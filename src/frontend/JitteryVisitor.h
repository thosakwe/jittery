
// Generated from /Users/thosakwe/Source/CPP/jittery/src/frontend/Jittery.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "JitteryParser.h"


namespace frontend {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by JitteryParser.
 */
class  JitteryVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by JitteryParser.
   */
    virtual antlrcpp::Any visitCompilationUnit(JitteryParser::CompilationUnitContext *context) = 0;

    virtual antlrcpp::Any visitTopLevel(JitteryParser::TopLevelContext *context) = 0;

    virtual antlrcpp::Any visitFnDecl(JitteryParser::FnDeclContext *context) = 0;

    virtual antlrcpp::Any visitVarDeclStmt(JitteryParser::VarDeclStmtContext *context) = 0;

    virtual antlrcpp::Any visitIfStmt(JitteryParser::IfStmtContext *context) = 0;

    virtual antlrcpp::Any visitWhileStmt(JitteryParser::WhileStmtContext *context) = 0;

    virtual antlrcpp::Any visitForStmt(JitteryParser::ForStmtContext *context) = 0;

    virtual antlrcpp::Any visitThrowStmt(JitteryParser::ThrowStmtContext *context) = 0;

    virtual antlrcpp::Any visitReturnStmt(JitteryParser::ReturnStmtContext *context) = 0;

    virtual antlrcpp::Any visitIdAssnStmt(JitteryParser::IdAssnStmtContext *context) = 0;

    virtual antlrcpp::Any visitExprStmt(JitteryParser::ExprStmtContext *context) = 0;

    virtual antlrcpp::Any visitElseIf(JitteryParser::ElseIfContext *context) = 0;

    virtual antlrcpp::Any visitStringExpr(JitteryParser::StringExprContext *context) = 0;

    virtual antlrcpp::Any visitTrueExpr(JitteryParser::TrueExprContext *context) = 0;

    virtual antlrcpp::Any visitFloatExpr(JitteryParser::FloatExprContext *context) = 0;

    virtual antlrcpp::Any visitIdExpr(JitteryParser::IdExprContext *context) = 0;

    virtual antlrcpp::Any visitMulDivModExpr(JitteryParser::MulDivModExprContext *context) = 0;

    virtual antlrcpp::Any visitCallExpr(JitteryParser::CallExprContext *context) = 0;

    virtual antlrcpp::Any visitIntExpr(JitteryParser::IntExprContext *context) = 0;

    virtual antlrcpp::Any visitRangeExpr(JitteryParser::RangeExprContext *context) = 0;

    virtual antlrcpp::Any visitAddSubExpr(JitteryParser::AddSubExprContext *context) = 0;

    virtual antlrcpp::Any visitBoolEqExpr(JitteryParser::BoolEqExprContext *context) = 0;

    virtual antlrcpp::Any visitCondExpr(JitteryParser::CondExprContext *context) = 0;

    virtual antlrcpp::Any visitFalseExpr(JitteryParser::FalseExprContext *context) = 0;


};

}  // namespace frontend
