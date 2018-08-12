
// Generated from /Users/thosakwe/Source/CPP/jittery/src/frontend/Jittery.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"


namespace frontend {


class  JitteryParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, T__25 = 26, 
    T__26 = 27, COMMENT = 28, WS = 29, FLOAT = 30, INT = 31, STRING = 32, 
    ID = 33
  };

  enum {
    RuleCompilationUnit = 0, RuleTopLevel = 1, RuleFnDecl = 2, RuleStmts = 3, 
    RuleStmt = 4, RuleElseIf = 5, RuleExpr = 6
  };

  JitteryParser(antlr4::TokenStream *input);
  ~JitteryParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class CompilationUnitContext;
  class TopLevelContext;
  class FnDeclContext;
  class StmtsContext;
  class StmtContext;
  class ElseIfContext;
  class ExprContext; 

  class  CompilationUnitContext : public antlr4::ParserRuleContext {
  public:
    CompilationUnitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TopLevelContext *> topLevel();
    TopLevelContext* topLevel(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CompilationUnitContext* compilationUnit();

  class  TopLevelContext : public antlr4::ParserRuleContext {
  public:
    TopLevelContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FnDeclContext *fnDecl();
    StmtContext *stmt();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TopLevelContext* topLevel();

  class  FnDeclContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *name = nullptr;;
    antlr4::Token *idToken = nullptr;;
    std::vector<antlr4::Token *> params;;
    FnDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FnDeclContext* fnDecl();

  class  StmtsContext : public antlr4::ParserRuleContext {
  public:
    StmtsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StmtsContext* stmts();

  class  StmtContext : public antlr4::ParserRuleContext {
  public:
    StmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    StmtContext() : antlr4::ParserRuleContext() { }
    void copyFrom(StmtContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  IfStmtContext : public StmtContext {
  public:
    IfStmtContext(StmtContext *ctx);

    JitteryParser::ExprContext *condition = nullptr;
    JitteryParser::StmtsContext *ifPredicate = nullptr;
    JitteryParser::StmtsContext *elsePredicate = nullptr;
    ExprContext *expr();
    std::vector<StmtsContext *> stmts();
    StmtsContext* stmts(size_t i);
    std::vector<ElseIfContext *> elseIf();
    ElseIfContext* elseIf(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprStmtContext : public StmtContext {
  public:
    ExprStmtContext(StmtContext *ctx);

    ExprContext *expr();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  WhileStmtContext : public StmtContext {
  public:
    WhileStmtContext(StmtContext *ctx);

    JitteryParser::ExprContext *condition = nullptr;
    StmtsContext *stmts();
    ExprContext *expr();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  VarDeclStmtContext : public StmtContext {
  public:
    VarDeclStmtContext(StmtContext *ctx);

    antlr4::tree::TerminalNode *ID();
    ExprContext *expr();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IdAssnStmtContext : public StmtContext {
  public:
    IdAssnStmtContext(StmtContext *ctx);

    antlr4::tree::TerminalNode *ID();
    ExprContext *expr();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ForStmtContext : public StmtContext {
  public:
    ForStmtContext(StmtContext *ctx);

    antlr4::Token *itemName = nullptr;
    antlr4::Token *indexName = nullptr;
    ExprContext *expr();
    StmtsContext *stmts();
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ThrowStmtContext : public StmtContext {
  public:
    ThrowStmtContext(StmtContext *ctx);

    ExprContext *expr();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ReturnStmtContext : public StmtContext {
  public:
    ReturnStmtContext(StmtContext *ctx);

    ExprContext *expr();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  StmtContext* stmt();

  class  ElseIfContext : public antlr4::ParserRuleContext {
  public:
    JitteryParser::ExprContext *condition = nullptr;;
    JitteryParser::StmtContext *predicate = nullptr;;
    ElseIfContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ElseIfContext* elseIf();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExprContext() : antlr4::ParserRuleContext() { }
    void copyFrom(ExprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  StringExprContext : public ExprContext {
  public:
    StringExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *STRING();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TrueExprContext : public ExprContext {
  public:
    TrueExprContext(ExprContext *ctx);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FloatExprContext : public ExprContext {
  public:
    FloatExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *FLOAT();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IdExprContext : public ExprContext {
  public:
    IdExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *ID();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MulDivModExprContext : public ExprContext {
  public:
    MulDivModExprContext(ExprContext *ctx);

    JitteryParser::ExprContext *left = nullptr;
    antlr4::Token *op = nullptr;
    JitteryParser::ExprContext *right = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CallExprContext : public ExprContext {
  public:
    CallExprContext(ExprContext *ctx);

    JitteryParser::ExprContext *target = nullptr;
    JitteryParser::ExprContext *exprContext = nullptr;
    std::vector<ExprContext *> arguments;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IntExprContext : public ExprContext {
  public:
    IntExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *INT();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  RangeExprContext : public ExprContext {
  public:
    RangeExprContext(ExprContext *ctx);

    JitteryParser::ExprContext *from = nullptr;
    JitteryParser::ExprContext *to = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AddSubExprContext : public ExprContext {
  public:
    AddSubExprContext(ExprContext *ctx);

    JitteryParser::ExprContext *left = nullptr;
    antlr4::Token *op = nullptr;
    JitteryParser::ExprContext *right = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BoolEqExprContext : public ExprContext {
  public:
    BoolEqExprContext(ExprContext *ctx);

    JitteryParser::ExprContext *left = nullptr;
    antlr4::Token *op = nullptr;
    JitteryParser::ExprContext *right = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CondExprContext : public ExprContext {
  public:
    CondExprContext(ExprContext *ctx);

    JitteryParser::ExprContext *condition = nullptr;
    JitteryParser::ExprContext *then = nullptr;
    JitteryParser::ExprContext *otherwise = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FalseExprContext : public ExprContext {
  public:
    FalseExprContext(ExprContext *ctx);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExprContext* expr();
  ExprContext* expr(int precedence);

  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool exprSempred(ExprContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace frontend
