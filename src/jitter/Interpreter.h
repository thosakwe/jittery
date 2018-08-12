// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef JITTERY_INTERPRETER_H
#define JITTERY_INTERPRETER_H

#include <jit/jit.h>
#include <stack>
#include "../frontend/frontend.h"
#include "SymbolTable.h"

namespace jit
{
    using antlrcpp::Any;
    using frontend::JitteryParser;

    class Interpreter : public frontend::JitteryBaseVisitor
    {
    public:
        explicit Interpreter();

        ~Interpreter();

        bool LoadCompilationUnit(JitteryParser::CompilationUnitContext *ctx, const char **errorMessage);

        void Run(const char **errorMessage);

        Any visitStmt(JitteryParser::StmtContext *ctx);

        Any visitExprStmt(JitteryParser::ExprStmtContext *ctx) override;

        Any visitIfStmt(JitteryParser::IfStmtContext *ctx) override;

        Any visitVarDeclStmt(JitteryParser::VarDeclStmtContext *ctx) override;

        Any visitReturnStmt(JitteryParser::ReturnStmtContext *ctx) override;

        antlrcpp::Any visitExpr(JitteryParser::ExprContext *ctx);

        antlrcpp::Any visitCallExpr(JitteryParser::CallExprContext *ctx) override;

        antlrcpp::Any visitIdExpr(JitteryParser::IdExprContext *ctx) override;

        Any visitStringExpr(JitteryParser::StringExprContext *ctx) override;

        Any visitIntExpr(JitteryParser::IntExprContext *ctx) override;

        Any visitTrueExpr(JitteryParser::TrueExprContext *ctx) override;

        Any visitFalseExpr(JitteryParser::FalseExprContext *ctx) override;

        Any visitThrowStmt(JitteryParser::ThrowStmtContext *ctx) override;

    private:

        struct GCReference
        {
            bool marked = false;
            void *data = nullptr;
        };

        union Bits64 {
            double asDouble = 0.0;
            jit_ulong asUlong;
        };

        jit_context_t jitContext;
        jit_function_t entryPoint;
        jit_function_t currentFunction;
        SymbolTable<jit_value_t> *scope;
        std::stack<GCReference *> references;
        unsigned long maxGcObjects = 255;

        static void *GCNew(Interpreter *interpreter, uint32_t size);

        void InitStdLib();
    };
}


#endif //JITTERY_INTERPRETER_H
