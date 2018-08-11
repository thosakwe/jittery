// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <jit/jit-dump.h>
#include <bitset>
#include <cstdint>
#include <iostream>
#include <vector>
#include "Interpreter.h"
#include "tagging.h"

#define JIT_ULONG_CONSTANT(x) jit_value_create_long_constant(currentFunction, jit_type_ulong, jit_ulong_to_long((x)))

jit::Interpreter::Interpreter() {
    jitContext = jit_context_create();
    scope = new SymbolTable<jit_value_t>;

    auto entrySignature = jit_type_create_signature(jit_abi_cdecl, jit_type_void, nullptr, 0, 0);
    currentFunction = entryPoint = jit_function_create(jitContext, entrySignature);

    InitStdLib();
}

jit::Interpreter::~Interpreter() {
    jit_context_destroy(jitContext);
}

bool
jit::Interpreter::LoadCompilationUnit(frontend::JitteryParser::CompilationUnitContext *ctx, const char **errorMessage) {
    jit_context_build_start(jitContext);

    // TODO: Custom functions
    ctx->accept(this);

    return true;
}

void jit::Interpreter::Run(const char **errorMessage) {
    typedef void (*Exec)();
    jit_insn_return(entryPoint, nullptr);
    jit_dump_function(stdout, entryPoint, "entryPoint");
    jit_function_compile(entryPoint);
    jit_context_build_end(jitContext);
    jit_function_apply(entryPoint, nullptr, nullptr);
}

antlrcpp::Any jit::Interpreter::visitExprStmt(frontend::JitteryParser::ExprStmtContext *ctx) {
    return visitExpr(ctx->expr());
}

antlrcpp::Any jit::Interpreter::visitVarDeclStmt(frontend::JitteryParser::VarDeclStmtContext *ctx) {
    auto initializerAny = visitExpr(ctx->expr());

    if (initializerAny.isNotNull()) {
        auto initializer = initializerAny.as<jit_value_t>();

        if (!scope->Add(ctx->ID()->getText(), nullptr)) {
            // TODO: Handle this
            std::cerr << "Cannot redefine " << ctx->ID()->getText() << std::endl;
        } else {
            auto *symbol = scope->Resolve(ctx->ID()->getText());
            auto value = jit_value_create(currentFunction, jit_value_get_type(initializer));
            jit_insn_store(currentFunction, value, initializer);
            symbol->SetValue(value);
        }
    } else {
        // TODO: Handle this
        std::cerr << "Bad initializer: " << ctx->expr()->getText() << std::endl;
    }

    return Any();
}

antlrcpp::Any jit::Interpreter::visitReturnStmt(frontend::JitteryParser::ReturnStmtContext *ctx) {
    auto result = visitExpr(ctx->expr());

    if (result.isNotNull()) {
        auto retVal = result.as<jit_value_t>();
        jit_insn_return(currentFunction, retVal);
    }

    return result;
}

antlrcpp::Any jit::Interpreter::visitExpr(frontend::JitteryParser::ExprContext *ctx) {
    return ctx->accept(this);
}

antlrcpp::Any jit::Interpreter::visitCallExpr(frontend::JitteryParser::CallExprContext *ctx) {
    auto target = visitExpr(ctx->target);

    bool argsPassed = true;
    std::vector<jit_value_t> args;

    for (auto *arg : ctx->arguments) {
        auto value = visitExpr(arg);

        if (value.isNull()) {
            std::cout << "Failed: " << arg->getText() << std::endl;
            argsPassed = false;
            break;
        } else {
            args.push_back(value.as<jit_value_t>());
        }
    }

    if (argsPassed) {
        // TODO: What should the signature look like???
        jit_type_t params = jit_type_ulong;
        auto signature = jit_type_create_signature(jit_abi_cdecl, jit_type_void, &params, 1, 0);
        return jit_insn_call_indirect(currentFunction, target, signature, args.data(), (unsigned int) args.size(), 0);
    } else {
        // TODO: Handle errors???
        std::cout << "Args did not pass" << std::endl;
    }

    return Any();
}

void jitPrint(uint64_t obj) {
    if (JITTERY_HAS_TAG(obj, JITTERY_TAG_SMALL_STRING)) {
        // The value is a char*
        auto *str = (char *) &obj;
        std::cout << str << std::endl;
    } else if (JITTERY_HAS_TAG(obj, JITTERY_TAG_STRING)) {
        // The value is a char**, not char*
        auto *location = (char **) JITTERY_GET_VALUE(obj);
        std::cout << *location << std::endl;
    } else {
        std::bitset<64> bits(obj);
        std::cout << "0b" << bits << std::endl;
    }
}

void jit::Interpreter::InitStdLib() {
    // Create Print
    scope->Add("Print", JIT_ULONG_CONSTANT((jit_ulong) &jitPrint));
}

antlrcpp::Any jit::Interpreter::visitIdExpr(frontend::JitteryParser::IdExprContext *ctx) {
    // TODO: SSA
    // TODO: Handle non-existent
    auto *symbol = scope->Resolve(ctx->ID()->getText());

    if (symbol == nullptr) {
        std::cout << "NOT FOUND: " << ctx->ID()->getText() << std::endl;
        return Any();
    } else {
        return Any(symbol->GetValue());
    }
}

antlrcpp::Any jit::Interpreter::visitStringExpr(frontend::JitteryParser::StringExprContext *ctx) {
    auto stringText = ctx->getText(); // TODO: Escapes
    stringText = stringText.substr(1, stringText.length() - 2);

    // Strings less than 7 chars can be stored directly in the tagged pointer.
    if (stringText.length() < 7) {
        jit_ulong value = JITTERY_TAG_SMALL_STRING;
        auto *asCharPtr = (char *) &value;

        for (int i = 0; i < stringText.length(); i++) {
            asCharPtr[i + 1] = stringText.at((unsigned long) i);
        }

        return Any(JIT_ULONG_CONSTANT(value));
    } else {
        // TODO: Handle bigger strings
        return Any();
    }
}
