// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <jit/jit-dump.h>
#include <bitset>
#include <cstdint>
#include <deque>
#include <iostream>
#include <unordered_map>
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

    // Sweep the GC
    while (!references.empty()) {
        free(references.top()->data);
        references.pop();
    }
}

bool
jit::Interpreter::LoadCompilationUnit(frontend::JitteryParser::CompilationUnitContext *ctx, const char **errorMessage) {
    jit_context_build_start(jitContext);

    // TODO: Custom functions
    ctx->accept(this);
    jit_insn_return(entryPoint, nullptr);
    //jit_dump_function(stdout, entryPoint, "entryPoint");
    jit_function_compile(entryPoint);
    jit_context_build_end(jitContext);
    return true;
}

void jit::Interpreter::Run(const char **errorMessage) {
    jit_function_apply(entryPoint, nullptr, nullptr);
}

antlrcpp::Any jit::Interpreter::visitStmt(frontend::JitteryParser::StmtContext *ctx) {
    return ctx->accept(this);
}

antlrcpp::Any jit::Interpreter::visitExprStmt(frontend::JitteryParser::ExprStmtContext *ctx) {
    return visitExpr(ctx->expr());
}

antlrcpp::Any jit::Interpreter::visitIfStmt(frontend::JitteryParser::IfStmtContext *ctx) {
    // Examine initial if condition
    auto conditionAny = visitExpr(ctx->condition);

    if (conditionAny.isNotNull()) {
        //std::unordered_map<Pars
        auto condition = conditionAny.as<jit_value_t>();
        auto endLabel = jit_function_reserve_label(currentFunction);
        auto elseLabel = jit_function_reserve_label(currentFunction);

        // The if predicate runs if the condition is TRUE. Otherwise, jump to else.
        auto isTrue = jit_insn_eq(currentFunction, condition, JIT_ULONG_CONSTANT(JITTERY_TAG_TRUE));
        jit_insn_branch_if_not(currentFunction, isTrue, &elseLabel);

        // Otherwise, just do everything defined in the if statement.
        for (auto *stmt : ctx->ifPredicate->stmt()) {
            visitStmt(stmt);
        }

        // If the condition was met, jump to the end.
        jit_insn_branch(currentFunction, &endLabel);

        // Else block
        jit_insn_label(currentFunction, &elseLabel);

        // Compile else-if
        for (auto *elseIf : ctx->elseIf()) {

            auto localConditionAny = visitExpr(elseIf->condition);

            if (localConditionAny.isNotNull()) {
                // Reserve a label that will be visited if the predicate was not matched.
                auto localEndLabel = jit_function_reserve_label(currentFunction);

                // Evaluate the condition.
                auto localCondition = localConditionAny.as<jit_value_t>();
                auto localIsTrue = jit_insn_eq(currentFunction, localCondition, JIT_ULONG_CONSTANT(JITTERY_TAG_TRUE));
                jit_insn_branch_if_not(currentFunction, localIsTrue, &localEndLabel);

                // Visit every statement.
                for (auto *stmt : elseIf->stmt()) {
                    visitStmt(stmt);
                }

                // Skip to the end, because we only want to run the logic from this
                // condition.
                jit_insn_branch(currentFunction, &endLabel);

                // If the condition was not true, continue checking other statements.
                jit_insn_label(currentFunction, &localEndLabel);
            } else {
                // TODO: Handle this
                std::cerr << "Failed else if: " << elseIf->getText() << std::endl;
            }
        }

        // Visit any behavior defined in else
        if (ctx->elsePredicate != nullptr) {
            for (auto *stmt : ctx->elsePredicate->stmt()) {
                visitStmt(stmt);
            }
        }

        // All paths end up at the next label.
        jit_insn_label(currentFunction, &endLabel);
    } else {
        // TODO: Handle this
        std::cerr << "Failed if: " << ctx->getText() << std::endl;
    }

    return Any();
}

antlrcpp::Any jit::Interpreter::visitVarDeclStmt(frontend::JitteryParser::VarDeclStmtContext *ctx) {
    auto initializerAny = visitExpr(ctx->expr());

    if (initializerAny.isNotNull()) {
        auto initializer = initializerAny.as<jit_value_t>();

        if (!scope->Add(ctx->ID()->getText(), nullptr)) {
            // TODO: Handle this
            std::cerr << "Cannot redefine " << ctx->ID()->getText() << std::endl;
        } else {
            // Mark the object, if necessary.
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

antlrcpp::Any jit::Interpreter::visitThrowStmt(frontend::JitteryParser::ThrowStmtContext *ctx) {
    auto result = visitExpr(ctx->expr());

    if (result.isNotNull()) {
        auto retVal = result.as<jit_value_t>();
        jit_insn_throw(currentFunction, retVal);
    }

    return result;
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
        // The tag itself is a char*
        auto *str = (char *) &obj;
        std::cout << str << std::endl;
    } else if (JITTERY_HAS_TAG(obj, JITTERY_TAG_STRING)) {
        // The value is a char*
        auto *location = (char *) JITTERY_GET_VALUE(obj);
        std::cout << location << std::endl;
    } else if (JITTERY_HAS_TAG(obj, JITTERY_TAG_INLINE_NUM)) {
        // Clear the number info bits
        auto isSigned = ((uint8_t) obj) == JITTERY_NUM_SIGNED;
        obj >>= 8;

        if (isSigned) {
            std::cout << jit_ulong_to_long(obj) << std::endl;
        } else {
            std::cout << obj << std::endl;
        }
    } else if (JITTERY_HAS_TAG(obj, JITTERY_TAG_NUM)) {
        // This is a double; pull it out
        auto rawValue = JITTERY_GET_VALUE(obj);
        auto asDouble = *((double *) &rawValue);
        std::cout << asDouble << std::endl;
    } else if (JITTERY_HAS_TAG(obj, JITTERY_TAG_TRUE)) {
        std::cout << "true" << std::endl;
    } else if (JITTERY_HAS_TAG(obj, JITTERY_TAG_FALSE)) {
        std::cout << "false" << std::endl;
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

antlrcpp::Any jit::Interpreter::visitIntExpr(frontend::JitteryParser::IntExprContext *ctx) {
    // Parse the value.
    auto value = jit_long_to_ulong(atol(ctx->getText().c_str()));

    // If this number can be inlined, then inline it.
    if (value < JITTERY_MAX_INLINE_NUM) {
        value <<= 8;
        value |= JITTERY_TAG_INLINE_NUM;
    } else {
        // Otherwise, this is a quite large number.
        // TODO: Handle this
    }

    return Any(JIT_ULONG_CONSTANT(value));
}

antlrcpp::Any jit::Interpreter::visitStringExpr(frontend::JitteryParser::StringExprContext *ctx) {
    auto stringText = ctx->getText(); // TODO: Escapes
    stringText = stringText.substr(1, stringText.length() - 2);

    // Strings less than 7 chars can be stored directly in the tagged pointer.
    auto len = stringText.length();
    if (len < 7) {
        jit_ulong value = JITTERY_TAG_SMALL_STRING;
        auto *asCharPtr = (char *) &value;

        for (int i = 0; i < stringText.length(); i++) {
            asCharPtr[i + 1] = stringText.at((unsigned long) i);
        }

        return Any(JIT_ULONG_CONSTANT(value));
    } else {
        // Allocate some space.
        auto *ptr = (char *) GCNew(this, (uint32_t) len + 1);
        ptr[len] = 0;
        strcpy(ptr, stringText.c_str());

        // Encode a pointer
        auto value = (jit_ulong) ptr;
        value <<= 3;
        value |= JITTERY_TAG_STRING;
        return Any(JIT_ULONG_CONSTANT(value));
    }
}

antlrcpp::Any jit::Interpreter::visitTrueExpr(frontend::JitteryParser::TrueExprContext *ctx) {
    return Any(JIT_ULONG_CONSTANT(JITTERY_TAG_TRUE));
}

antlrcpp::Any jit::Interpreter::visitFalseExpr(frontend::JitteryParser::FalseExprContext *ctx) {
    return Any(JIT_ULONG_CONSTANT(JITTERY_TAG_FALSE));
}

void *jit::Interpreter::GCNew(jit::Interpreter *interpreter, uint32_t size) {
    // If enough objects have been created, we need to sweep the GC.
    if (interpreter->references.size() >= interpreter->maxGcObjects) {
        // Only preserve references that are alive.
        std::stack<GCReference *> stillAlive;

        while (!interpreter->references.empty()) {
            auto *ref = interpreter->references.top();

            if (!(ref->marked)) {
                free(ref->data);
                delete ref;
            } else {
                // Unmark the object, so that it will be destroyed in the next sweep.
                ref->marked = false;
                stillAlive.push(ref);
            }

            interpreter->references.pop();
        }

        // Put back anything that's still alive.
        while (!stillAlive.empty()) {
            interpreter->references.push(stillAlive.top());
            stillAlive.pop();
        }

        // If there are still too many objects, increase the count so that
        // the GC isn't constantly looping.
        if (interpreter->references.size() >= interpreter->maxGcObjects) {
            interpreter->maxGcObjects++;
        }
    }

    // Allocate data.
    //
    // Initially mark it as in-use; all data will survive at least one cycle.
    auto *data = new uint8_t[size];
    auto *ref = new GCReference;
    ref->marked = false;
    ref->data = data;
    interpreter->references.push(ref);
    return ref;
}
