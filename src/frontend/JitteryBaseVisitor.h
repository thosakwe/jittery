
// Generated from /Users/thosakwe/Source/CPP/jittery/src/frontend/Jittery.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "JitteryVisitor.h"


namespace frontend {

/**
 * This class provides an empty implementation of JitteryVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  JitteryBaseVisitor : public JitteryVisitor {
public:

  virtual antlrcpp::Any visitCompilationUnit(JitteryParser::CompilationUnitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTopLevel(JitteryParser::TopLevelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFnDecl(JitteryParser::FnDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStmts(JitteryParser::StmtsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarDeclStmt(JitteryParser::VarDeclStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfStmt(JitteryParser::IfStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhileStmt(JitteryParser::WhileStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForStmt(JitteryParser::ForStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitThrowStmt(JitteryParser::ThrowStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReturnStmt(JitteryParser::ReturnStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdAssnStmt(JitteryParser::IdAssnStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprStmt(JitteryParser::ExprStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitElseIf(JitteryParser::ElseIfContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStringExpr(JitteryParser::StringExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTrueExpr(JitteryParser::TrueExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFloatExpr(JitteryParser::FloatExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdExpr(JitteryParser::IdExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMulDivModExpr(JitteryParser::MulDivModExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCallExpr(JitteryParser::CallExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIntExpr(JitteryParser::IntExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRangeExpr(JitteryParser::RangeExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAddSubExpr(JitteryParser::AddSubExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBoolEqExpr(JitteryParser::BoolEqExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCondExpr(JitteryParser::CondExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFalseExpr(JitteryParser::FalseExprContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace frontend
