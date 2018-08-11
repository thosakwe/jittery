
// Generated from /Users/thosakwe/Source/CPP/jittery/src/frontend/Jittery.g4 by ANTLR 4.7


#include "JitteryVisitor.h"

#include "JitteryParser.h"


using namespace antlrcpp;
using namespace frontend;
using namespace antlr4;

JitteryParser::JitteryParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

JitteryParser::~JitteryParser() {
  delete _interpreter;
}

std::string JitteryParser::getGrammarFileName() const {
  return "Jittery.g4";
}

const std::vector<std::string>& JitteryParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& JitteryParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- CompilationUnitContext ------------------------------------------------------------------

JitteryParser::CompilationUnitContext::CompilationUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<JitteryParser::TopLevelContext *> JitteryParser::CompilationUnitContext::topLevel() {
  return getRuleContexts<JitteryParser::TopLevelContext>();
}

JitteryParser::TopLevelContext* JitteryParser::CompilationUnitContext::topLevel(size_t i) {
  return getRuleContext<JitteryParser::TopLevelContext>(i);
}


size_t JitteryParser::CompilationUnitContext::getRuleIndex() const {
  return JitteryParser::RuleCompilationUnit;
}

antlrcpp::Any JitteryParser::CompilationUnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JitteryVisitor*>(visitor))
    return parserVisitor->visitCompilationUnit(this);
  else
    return visitor->visitChildren(this);
}

JitteryParser::CompilationUnitContext* JitteryParser::compilationUnit() {
  CompilationUnitContext *_localctx = _tracker.createInstance<CompilationUnitContext>(_ctx, getState());
  enterRule(_localctx, 0, JitteryParser::RuleCompilationUnit);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(15);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << JitteryParser::T__0)
      | (1ULL << JitteryParser::T__6)
      | (1ULL << JitteryParser::T__8)
      | (1ULL << JitteryParser::T__10)
      | (1ULL << JitteryParser::T__11)
      | (1ULL << JitteryParser::T__13)
      | (1ULL << JitteryParser::T__14)
      | (1ULL << JitteryParser::T__15)
      | (1ULL << JitteryParser::FLOAT)
      | (1ULL << JitteryParser::INT)
      | (1ULL << JitteryParser::STRING)
      | (1ULL << JitteryParser::ID))) != 0)) {
      setState(12);
      topLevel();
      setState(17);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TopLevelContext ------------------------------------------------------------------

JitteryParser::TopLevelContext::TopLevelContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JitteryParser::FnDeclContext* JitteryParser::TopLevelContext::fnDecl() {
  return getRuleContext<JitteryParser::FnDeclContext>(0);
}

JitteryParser::StmtContext* JitteryParser::TopLevelContext::stmt() {
  return getRuleContext<JitteryParser::StmtContext>(0);
}


size_t JitteryParser::TopLevelContext::getRuleIndex() const {
  return JitteryParser::RuleTopLevel;
}

antlrcpp::Any JitteryParser::TopLevelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JitteryVisitor*>(visitor))
    return parserVisitor->visitTopLevel(this);
  else
    return visitor->visitChildren(this);
}

JitteryParser::TopLevelContext* JitteryParser::topLevel() {
  TopLevelContext *_localctx = _tracker.createInstance<TopLevelContext>(_ctx, getState());
  enterRule(_localctx, 2, JitteryParser::RuleTopLevel);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(20);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case JitteryParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(18);
        fnDecl();
        break;
      }

      case JitteryParser::T__6:
      case JitteryParser::T__8:
      case JitteryParser::T__10:
      case JitteryParser::T__11:
      case JitteryParser::T__13:
      case JitteryParser::T__14:
      case JitteryParser::T__15:
      case JitteryParser::FLOAT:
      case JitteryParser::INT:
      case JitteryParser::STRING:
      case JitteryParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(19);
        stmt();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FnDeclContext ------------------------------------------------------------------

JitteryParser::FnDeclContext::FnDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> JitteryParser::FnDeclContext::ID() {
  return getTokens(JitteryParser::ID);
}

tree::TerminalNode* JitteryParser::FnDeclContext::ID(size_t i) {
  return getToken(JitteryParser::ID, i);
}

std::vector<JitteryParser::StmtContext *> JitteryParser::FnDeclContext::stmt() {
  return getRuleContexts<JitteryParser::StmtContext>();
}

JitteryParser::StmtContext* JitteryParser::FnDeclContext::stmt(size_t i) {
  return getRuleContext<JitteryParser::StmtContext>(i);
}


size_t JitteryParser::FnDeclContext::getRuleIndex() const {
  return JitteryParser::RuleFnDecl;
}

antlrcpp::Any JitteryParser::FnDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JitteryVisitor*>(visitor))
    return parserVisitor->visitFnDecl(this);
  else
    return visitor->visitChildren(this);
}

JitteryParser::FnDeclContext* JitteryParser::fnDecl() {
  FnDeclContext *_localctx = _tracker.createInstance<FnDeclContext>(_ctx, getState());
  enterRule(_localctx, 4, JitteryParser::RuleFnDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(22);
    match(JitteryParser::T__0);
    setState(23);
    dynamic_cast<FnDeclContext *>(_localctx)->name = match(JitteryParser::ID);
    setState(24);
    match(JitteryParser::T__1);
    setState(33);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == JitteryParser::ID) {
      setState(29);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(25);
          dynamic_cast<FnDeclContext *>(_localctx)->idToken = match(JitteryParser::ID);
          dynamic_cast<FnDeclContext *>(_localctx)->params.push_back(dynamic_cast<FnDeclContext *>(_localctx)->idToken);
          setState(26);
          match(JitteryParser::T__2); 
        }
        setState(31);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
      }
      setState(32);
      dynamic_cast<FnDeclContext *>(_localctx)->idToken = match(JitteryParser::ID);
      dynamic_cast<FnDeclContext *>(_localctx)->params.push_back(dynamic_cast<FnDeclContext *>(_localctx)->idToken);
    }
    setState(35);
    match(JitteryParser::T__3);
    setState(36);
    match(JitteryParser::T__4);
    setState(40);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << JitteryParser::T__6)
      | (1ULL << JitteryParser::T__8)
      | (1ULL << JitteryParser::T__10)
      | (1ULL << JitteryParser::T__11)
      | (1ULL << JitteryParser::T__13)
      | (1ULL << JitteryParser::T__14)
      | (1ULL << JitteryParser::T__15)
      | (1ULL << JitteryParser::FLOAT)
      | (1ULL << JitteryParser::INT)
      | (1ULL << JitteryParser::STRING)
      | (1ULL << JitteryParser::ID))) != 0)) {
      setState(37);
      stmt();
      setState(42);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(43);
    match(JitteryParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

JitteryParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t JitteryParser::StmtContext::getRuleIndex() const {
  return JitteryParser::RuleStmt;
}

void JitteryParser::StmtContext::copyFrom(StmtContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- IfStmtContext ------------------------------------------------------------------

JitteryParser::ExprContext* JitteryParser::IfStmtContext::expr() {
  return getRuleContext<JitteryParser::ExprContext>(0);
}

std::vector<JitteryParser::ElseIfContext *> JitteryParser::IfStmtContext::elseIf() {
  return getRuleContexts<JitteryParser::ElseIfContext>();
}

JitteryParser::ElseIfContext* JitteryParser::IfStmtContext::elseIf(size_t i) {
  return getRuleContext<JitteryParser::ElseIfContext>(i);
}

std::vector<JitteryParser::StmtContext *> JitteryParser::IfStmtContext::stmt() {
  return getRuleContexts<JitteryParser::StmtContext>();
}

JitteryParser::StmtContext* JitteryParser::IfStmtContext::stmt(size_t i) {
  return getRuleContext<JitteryParser::StmtContext>(i);
}

JitteryParser::IfStmtContext::IfStmtContext(StmtContext *ctx) { copyFrom(ctx); }

antlrcpp::Any JitteryParser::IfStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JitteryVisitor*>(visitor))
    return parserVisitor->visitIfStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprStmtContext ------------------------------------------------------------------

JitteryParser::ExprContext* JitteryParser::ExprStmtContext::expr() {
  return getRuleContext<JitteryParser::ExprContext>(0);
}

JitteryParser::ExprStmtContext::ExprStmtContext(StmtContext *ctx) { copyFrom(ctx); }

antlrcpp::Any JitteryParser::ExprStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JitteryVisitor*>(visitor))
    return parserVisitor->visitExprStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WhileStmtContext ------------------------------------------------------------------

JitteryParser::ExprContext* JitteryParser::WhileStmtContext::expr() {
  return getRuleContext<JitteryParser::ExprContext>(0);
}

std::vector<JitteryParser::StmtContext *> JitteryParser::WhileStmtContext::stmt() {
  return getRuleContexts<JitteryParser::StmtContext>();
}

JitteryParser::StmtContext* JitteryParser::WhileStmtContext::stmt(size_t i) {
  return getRuleContext<JitteryParser::StmtContext>(i);
}

JitteryParser::WhileStmtContext::WhileStmtContext(StmtContext *ctx) { copyFrom(ctx); }

antlrcpp::Any JitteryParser::WhileStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JitteryVisitor*>(visitor))
    return parserVisitor->visitWhileStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VarDeclStmtContext ------------------------------------------------------------------

tree::TerminalNode* JitteryParser::VarDeclStmtContext::ID() {
  return getToken(JitteryParser::ID, 0);
}

JitteryParser::ExprContext* JitteryParser::VarDeclStmtContext::expr() {
  return getRuleContext<JitteryParser::ExprContext>(0);
}

JitteryParser::VarDeclStmtContext::VarDeclStmtContext(StmtContext *ctx) { copyFrom(ctx); }

antlrcpp::Any JitteryParser::VarDeclStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JitteryVisitor*>(visitor))
    return parserVisitor->visitVarDeclStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdAssnStmtContext ------------------------------------------------------------------

tree::TerminalNode* JitteryParser::IdAssnStmtContext::ID() {
  return getToken(JitteryParser::ID, 0);
}

JitteryParser::ExprContext* JitteryParser::IdAssnStmtContext::expr() {
  return getRuleContext<JitteryParser::ExprContext>(0);
}

JitteryParser::IdAssnStmtContext::IdAssnStmtContext(StmtContext *ctx) { copyFrom(ctx); }

antlrcpp::Any JitteryParser::IdAssnStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JitteryVisitor*>(visitor))
    return parserVisitor->visitIdAssnStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ForStmtContext ------------------------------------------------------------------

JitteryParser::ExprContext* JitteryParser::ForStmtContext::expr() {
  return getRuleContext<JitteryParser::ExprContext>(0);
}

std::vector<tree::TerminalNode *> JitteryParser::ForStmtContext::ID() {
  return getTokens(JitteryParser::ID);
}

tree::TerminalNode* JitteryParser::ForStmtContext::ID(size_t i) {
  return getToken(JitteryParser::ID, i);
}

std::vector<JitteryParser::StmtContext *> JitteryParser::ForStmtContext::stmt() {
  return getRuleContexts<JitteryParser::StmtContext>();
}

JitteryParser::StmtContext* JitteryParser::ForStmtContext::stmt(size_t i) {
  return getRuleContext<JitteryParser::StmtContext>(i);
}

JitteryParser::ForStmtContext::ForStmtContext(StmtContext *ctx) { copyFrom(ctx); }

antlrcpp::Any JitteryParser::ForStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JitteryVisitor*>(visitor))
    return parserVisitor->visitForStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ThrowStmtContext ------------------------------------------------------------------

JitteryParser::ExprContext* JitteryParser::ThrowStmtContext::expr() {
  return getRuleContext<JitteryParser::ExprContext>(0);
}

JitteryParser::ThrowStmtContext::ThrowStmtContext(StmtContext *ctx) { copyFrom(ctx); }

antlrcpp::Any JitteryParser::ThrowStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JitteryVisitor*>(visitor))
    return parserVisitor->visitThrowStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ReturnStmtContext ------------------------------------------------------------------

JitteryParser::ExprContext* JitteryParser::ReturnStmtContext::expr() {
  return getRuleContext<JitteryParser::ExprContext>(0);
}

JitteryParser::ReturnStmtContext::ReturnStmtContext(StmtContext *ctx) { copyFrom(ctx); }

antlrcpp::Any JitteryParser::ReturnStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JitteryVisitor*>(visitor))
    return parserVisitor->visitReturnStmt(this);
  else
    return visitor->visitChildren(this);
}
JitteryParser::StmtContext* JitteryParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 6, JitteryParser::RuleStmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(112);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<JitteryParser::VarDeclStmtContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(45);
      match(JitteryParser::T__6);
      setState(46);
      match(JitteryParser::ID);
      setState(47);
      match(JitteryParser::T__7);
      setState(48);
      expr(0);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<JitteryParser::IfStmtContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(49);
      match(JitteryParser::T__8);
      setState(50);
      dynamic_cast<IfStmtContext *>(_localctx)->condition = expr(0);
      setState(51);
      match(JitteryParser::T__4);
      setState(55);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << JitteryParser::T__6)
        | (1ULL << JitteryParser::T__8)
        | (1ULL << JitteryParser::T__10)
        | (1ULL << JitteryParser::T__11)
        | (1ULL << JitteryParser::T__13)
        | (1ULL << JitteryParser::T__14)
        | (1ULL << JitteryParser::T__15)
        | (1ULL << JitteryParser::FLOAT)
        | (1ULL << JitteryParser::INT)
        | (1ULL << JitteryParser::STRING)
        | (1ULL << JitteryParser::ID))) != 0)) {
        setState(52);
        dynamic_cast<IfStmtContext *>(_localctx)->ifPredicate = stmt();
        setState(57);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(63);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(58);
          match(JitteryParser::T__9);
          setState(59);
          match(JitteryParser::T__8);
          setState(60);
          elseIf(); 
        }
        setState(65);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
      }
      setState(73);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == JitteryParser::T__9) {
        setState(66);
        match(JitteryParser::T__9);
        setState(70);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << JitteryParser::T__6)
          | (1ULL << JitteryParser::T__8)
          | (1ULL << JitteryParser::T__10)
          | (1ULL << JitteryParser::T__11)
          | (1ULL << JitteryParser::T__13)
          | (1ULL << JitteryParser::T__14)
          | (1ULL << JitteryParser::T__15)
          | (1ULL << JitteryParser::FLOAT)
          | (1ULL << JitteryParser::INT)
          | (1ULL << JitteryParser::STRING)
          | (1ULL << JitteryParser::ID))) != 0)) {
          setState(67);
          dynamic_cast<IfStmtContext *>(_localctx)->elsePredicate = stmt();
          setState(72);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(75);
      match(JitteryParser::T__5);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<JitteryParser::WhileStmtContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(77);
      match(JitteryParser::T__10);
      setState(78);
      dynamic_cast<WhileStmtContext *>(_localctx)->condition = expr(0);
      setState(82);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << JitteryParser::T__6)
        | (1ULL << JitteryParser::T__8)
        | (1ULL << JitteryParser::T__10)
        | (1ULL << JitteryParser::T__11)
        | (1ULL << JitteryParser::T__13)
        | (1ULL << JitteryParser::T__14)
        | (1ULL << JitteryParser::T__15)
        | (1ULL << JitteryParser::FLOAT)
        | (1ULL << JitteryParser::INT)
        | (1ULL << JitteryParser::STRING)
        | (1ULL << JitteryParser::ID))) != 0)) {
        setState(79);
        stmt();
        setState(84);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(85);
      match(JitteryParser::T__5);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<JitteryParser::ForStmtContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(87);
      match(JitteryParser::T__11);
      setState(88);
      dynamic_cast<ForStmtContext *>(_localctx)->itemName = match(JitteryParser::ID);
      setState(91);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == JitteryParser::T__2) {
        setState(89);
        match(JitteryParser::T__2);
        setState(90);
        dynamic_cast<ForStmtContext *>(_localctx)->indexName = match(JitteryParser::ID);
      }
      setState(93);
      match(JitteryParser::T__12);
      setState(94);
      expr(0);
      setState(95);
      match(JitteryParser::T__4);
      setState(99);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << JitteryParser::T__6)
        | (1ULL << JitteryParser::T__8)
        | (1ULL << JitteryParser::T__10)
        | (1ULL << JitteryParser::T__11)
        | (1ULL << JitteryParser::T__13)
        | (1ULL << JitteryParser::T__14)
        | (1ULL << JitteryParser::T__15)
        | (1ULL << JitteryParser::FLOAT)
        | (1ULL << JitteryParser::INT)
        | (1ULL << JitteryParser::STRING)
        | (1ULL << JitteryParser::ID))) != 0)) {
        setState(96);
        stmt();
        setState(101);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(102);
      match(JitteryParser::T__5);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<JitteryParser::ThrowStmtContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(104);
      match(JitteryParser::T__13);
      setState(105);
      expr(0);
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<JitteryParser::ReturnStmtContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(106);
      match(JitteryParser::T__14);
      setState(107);
      expr(0);
      break;
    }

    case 7: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<JitteryParser::IdAssnStmtContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(108);
      match(JitteryParser::ID);
      setState(109);
      match(JitteryParser::T__7);
      setState(110);
      expr(0);
      break;
    }

    case 8: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<JitteryParser::ExprStmtContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(111);
      expr(0);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElseIfContext ------------------------------------------------------------------

JitteryParser::ElseIfContext::ElseIfContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JitteryParser::ExprContext* JitteryParser::ElseIfContext::expr() {
  return getRuleContext<JitteryParser::ExprContext>(0);
}

std::vector<JitteryParser::StmtContext *> JitteryParser::ElseIfContext::stmt() {
  return getRuleContexts<JitteryParser::StmtContext>();
}

JitteryParser::StmtContext* JitteryParser::ElseIfContext::stmt(size_t i) {
  return getRuleContext<JitteryParser::StmtContext>(i);
}


size_t JitteryParser::ElseIfContext::getRuleIndex() const {
  return JitteryParser::RuleElseIf;
}

antlrcpp::Any JitteryParser::ElseIfContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JitteryVisitor*>(visitor))
    return parserVisitor->visitElseIf(this);
  else
    return visitor->visitChildren(this);
}

JitteryParser::ElseIfContext* JitteryParser::elseIf() {
  ElseIfContext *_localctx = _tracker.createInstance<ElseIfContext>(_ctx, getState());
  enterRule(_localctx, 8, JitteryParser::RuleElseIf);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(114);
    dynamic_cast<ElseIfContext *>(_localctx)->condition = expr(0);
    setState(115);
    match(JitteryParser::T__4);
    setState(119);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << JitteryParser::T__6)
      | (1ULL << JitteryParser::T__8)
      | (1ULL << JitteryParser::T__10)
      | (1ULL << JitteryParser::T__11)
      | (1ULL << JitteryParser::T__13)
      | (1ULL << JitteryParser::T__14)
      | (1ULL << JitteryParser::T__15)
      | (1ULL << JitteryParser::FLOAT)
      | (1ULL << JitteryParser::INT)
      | (1ULL << JitteryParser::STRING)
      | (1ULL << JitteryParser::ID))) != 0)) {
      setState(116);
      dynamic_cast<ElseIfContext *>(_localctx)->predicate = stmt();
      setState(121);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

JitteryParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t JitteryParser::ExprContext::getRuleIndex() const {
  return JitteryParser::RuleExpr;
}

void JitteryParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- StringExprContext ------------------------------------------------------------------

tree::TerminalNode* JitteryParser::StringExprContext::STRING() {
  return getToken(JitteryParser::STRING, 0);
}

JitteryParser::StringExprContext::StringExprContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any JitteryParser::StringExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JitteryVisitor*>(visitor))
    return parserVisitor->visitStringExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FloatExprContext ------------------------------------------------------------------

tree::TerminalNode* JitteryParser::FloatExprContext::FLOAT() {
  return getToken(JitteryParser::FLOAT, 0);
}

JitteryParser::FloatExprContext::FloatExprContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any JitteryParser::FloatExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JitteryVisitor*>(visitor))
    return parserVisitor->visitFloatExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdExprContext ------------------------------------------------------------------

tree::TerminalNode* JitteryParser::IdExprContext::ID() {
  return getToken(JitteryParser::ID, 0);
}

JitteryParser::IdExprContext::IdExprContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any JitteryParser::IdExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JitteryVisitor*>(visitor))
    return parserVisitor->visitIdExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MulDivModExprContext ------------------------------------------------------------------

std::vector<JitteryParser::ExprContext *> JitteryParser::MulDivModExprContext::expr() {
  return getRuleContexts<JitteryParser::ExprContext>();
}

JitteryParser::ExprContext* JitteryParser::MulDivModExprContext::expr(size_t i) {
  return getRuleContext<JitteryParser::ExprContext>(i);
}

JitteryParser::MulDivModExprContext::MulDivModExprContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any JitteryParser::MulDivModExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JitteryVisitor*>(visitor))
    return parserVisitor->visitMulDivModExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CallExprContext ------------------------------------------------------------------

std::vector<JitteryParser::ExprContext *> JitteryParser::CallExprContext::expr() {
  return getRuleContexts<JitteryParser::ExprContext>();
}

JitteryParser::ExprContext* JitteryParser::CallExprContext::expr(size_t i) {
  return getRuleContext<JitteryParser::ExprContext>(i);
}

JitteryParser::CallExprContext::CallExprContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any JitteryParser::CallExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JitteryVisitor*>(visitor))
    return parserVisitor->visitCallExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntExprContext ------------------------------------------------------------------

tree::TerminalNode* JitteryParser::IntExprContext::INT() {
  return getToken(JitteryParser::INT, 0);
}

JitteryParser::IntExprContext::IntExprContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any JitteryParser::IntExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JitteryVisitor*>(visitor))
    return parserVisitor->visitIntExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RangeExprContext ------------------------------------------------------------------

std::vector<JitteryParser::ExprContext *> JitteryParser::RangeExprContext::expr() {
  return getRuleContexts<JitteryParser::ExprContext>();
}

JitteryParser::ExprContext* JitteryParser::RangeExprContext::expr(size_t i) {
  return getRuleContext<JitteryParser::ExprContext>(i);
}

JitteryParser::RangeExprContext::RangeExprContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any JitteryParser::RangeExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JitteryVisitor*>(visitor))
    return parserVisitor->visitRangeExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AddSubExprContext ------------------------------------------------------------------

std::vector<JitteryParser::ExprContext *> JitteryParser::AddSubExprContext::expr() {
  return getRuleContexts<JitteryParser::ExprContext>();
}

JitteryParser::ExprContext* JitteryParser::AddSubExprContext::expr(size_t i) {
  return getRuleContext<JitteryParser::ExprContext>(i);
}

JitteryParser::AddSubExprContext::AddSubExprContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any JitteryParser::AddSubExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JitteryVisitor*>(visitor))
    return parserVisitor->visitAddSubExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BoolEqExprContext ------------------------------------------------------------------

std::vector<JitteryParser::ExprContext *> JitteryParser::BoolEqExprContext::expr() {
  return getRuleContexts<JitteryParser::ExprContext>();
}

JitteryParser::ExprContext* JitteryParser::BoolEqExprContext::expr(size_t i) {
  return getRuleContext<JitteryParser::ExprContext>(i);
}

JitteryParser::BoolEqExprContext::BoolEqExprContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any JitteryParser::BoolEqExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JitteryVisitor*>(visitor))
    return parserVisitor->visitBoolEqExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CondExprContext ------------------------------------------------------------------

std::vector<JitteryParser::ExprContext *> JitteryParser::CondExprContext::expr() {
  return getRuleContexts<JitteryParser::ExprContext>();
}

JitteryParser::ExprContext* JitteryParser::CondExprContext::expr(size_t i) {
  return getRuleContext<JitteryParser::ExprContext>(i);
}

JitteryParser::CondExprContext::CondExprContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any JitteryParser::CondExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JitteryVisitor*>(visitor))
    return parserVisitor->visitCondExpr(this);
  else
    return visitor->visitChildren(this);
}

JitteryParser::ExprContext* JitteryParser::expr() {
   return expr(0);
}

JitteryParser::ExprContext* JitteryParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  JitteryParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  JitteryParser::ExprContext *previousContext = _localctx;
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, JitteryParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(139);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case JitteryParser::ID: {
        _localctx = _tracker.createInstance<IdExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(123);
        match(JitteryParser::ID);
        break;
      }

      case JitteryParser::FLOAT: {
        _localctx = _tracker.createInstance<FloatExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(124);
        match(JitteryParser::FLOAT);
        break;
      }

      case JitteryParser::INT: {
        _localctx = _tracker.createInstance<IntExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(125);
        match(JitteryParser::INT);
        break;
      }

      case JitteryParser::STRING: {
        _localctx = _tracker.createInstance<StringExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(126);
        match(JitteryParser::STRING);
        break;
      }

      case JitteryParser::T__15: {
        _localctx = _tracker.createInstance<RangeExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(127);
        match(JitteryParser::T__15);
        setState(128);
        dynamic_cast<RangeExprContext *>(_localctx)->from = expr(0);
        setState(129);
        match(JitteryParser::T__16);
        setState(130);
        dynamic_cast<RangeExprContext *>(_localctx)->to = expr(5);
        break;
      }

      case JitteryParser::T__8: {
        _localctx = _tracker.createInstance<CondExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(132);
        match(JitteryParser::T__8);
        setState(133);
        dynamic_cast<CondExprContext *>(_localctx)->condition = expr(0);
        setState(134);
        match(JitteryParser::T__17);
        setState(135);
        dynamic_cast<CondExprContext *>(_localctx)->then = expr(0);
        setState(136);
        match(JitteryParser::T__9);
        setState(137);
        dynamic_cast<CondExprContext *>(_localctx)->otherwise = expr(4);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(166);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(164);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MulDivModExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(141);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(142);
          dynamic_cast<MulDivModExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << JitteryParser::T__18)
            | (1ULL << JitteryParser::T__19)
            | (1ULL << JitteryParser::T__20))) != 0))) {
            dynamic_cast<MulDivModExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(143);
          dynamic_cast<MulDivModExprContext *>(_localctx)->right = expr(4);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AddSubExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(144);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(145);
          dynamic_cast<AddSubExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == JitteryParser::T__21

          || _la == JitteryParser::T__22)) {
            dynamic_cast<AddSubExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(146);
          dynamic_cast<AddSubExprContext *>(_localctx)->right = expr(3);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<BoolEqExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(147);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(148);
          dynamic_cast<BoolEqExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == JitteryParser::T__23

          || _la == JitteryParser::T__24)) {
            dynamic_cast<BoolEqExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(149);
          dynamic_cast<BoolEqExprContext *>(_localctx)->right = expr(2);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<CallExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->target = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(150);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(151);
          match(JitteryParser::T__1);
          setState(161);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << JitteryParser::T__8)
            | (1ULL << JitteryParser::T__15)
            | (1ULL << JitteryParser::FLOAT)
            | (1ULL << JitteryParser::INT)
            | (1ULL << JitteryParser::STRING)
            | (1ULL << JitteryParser::ID))) != 0)) {
            setState(157);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
            while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
              if (alt == 1) {
                setState(152);
                dynamic_cast<CallExprContext *>(_localctx)->exprContext = expr(0);
                dynamic_cast<CallExprContext *>(_localctx)->arguments.push_back(dynamic_cast<CallExprContext *>(_localctx)->exprContext);
                setState(153);
                match(JitteryParser::T__2); 
              }
              setState(159);
              _errHandler->sync(this);
              alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
            }
            setState(160);
            dynamic_cast<CallExprContext *>(_localctx)->exprContext = expr(0);
            dynamic_cast<CallExprContext *>(_localctx)->arguments.push_back(dynamic_cast<CallExprContext *>(_localctx)->exprContext);
          }
          setState(163);
          match(JitteryParser::T__3);
          break;
        }

        } 
      }
      setState(168);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool JitteryParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 5: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool JitteryParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 3);
    case 1: return precpred(_ctx, 2);
    case 2: return precpred(_ctx, 1);
    case 3: return precpred(_ctx, 6);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> JitteryParser::_decisionToDFA;
atn::PredictionContextCache JitteryParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN JitteryParser::_atn;
std::vector<uint16_t> JitteryParser::_serializedATN;

std::vector<std::string> JitteryParser::_ruleNames = {
  "compilationUnit", "topLevel", "fnDecl", "stmt", "elseIf", "expr"
};

std::vector<std::string> JitteryParser::_literalNames = {
  "", "'fn'", "'('", "','", "')'", "':'", "'end'", "'let'", "'='", "'if'", 
  "'else'", "'while'", "'for'", "'in'", "'throw'", "'return'", "'range'", 
  "'to'", "'then'", "'*'", "'/'", "'%'", "'+'", "'-'", "'=='", "'!='"
};

std::vector<std::string> JitteryParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "COMMENT", "WS", "FLOAT", "INT", "STRING", 
  "ID"
};

dfa::Vocabulary JitteryParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> JitteryParser::_tokenNames;

JitteryParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x21, 0xac, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x3, 
    0x2, 0x7, 0x2, 0x10, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x13, 0xb, 0x2, 0x3, 
    0x3, 0x3, 0x3, 0x5, 0x3, 0x17, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x1e, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x21, 
    0xb, 0x4, 0x3, 0x4, 0x5, 0x4, 0x24, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x7, 0x4, 0x29, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x2c, 0xb, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x38, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 
    0x3b, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x40, 0xa, 0x5, 
    0xc, 0x5, 0xe, 0x5, 0x43, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x47, 
    0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x4a, 0xb, 0x5, 0x5, 0x5, 0x4c, 0xa, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x53, 0xa, 
    0x5, 0xc, 0x5, 0xe, 0x5, 0x56, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x5e, 0xa, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x64, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 
    0x67, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x73, 0xa, 0x5, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x78, 0xa, 0x6, 0xc, 0x6, 0xe, 
    0x6, 0x7b, 0xb, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x8e, 0xa, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x7, 0x7, 0x9e, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0xa1, 0xb, 0x7, 0x3, 
    0x7, 0x5, 0x7, 0xa4, 0xa, 0x7, 0x3, 0x7, 0x7, 0x7, 0xa7, 0xa, 0x7, 0xc, 
    0x7, 0xe, 0x7, 0xaa, 0xb, 0x7, 0x3, 0x7, 0x2, 0x3, 0xc, 0x8, 0x2, 0x4, 
    0x6, 0x8, 0xa, 0xc, 0x2, 0x5, 0x3, 0x2, 0x15, 0x17, 0x3, 0x2, 0x18, 
    0x19, 0x3, 0x2, 0x1a, 0x1b, 0x2, 0xc4, 0x2, 0x11, 0x3, 0x2, 0x2, 0x2, 
    0x4, 0x16, 0x3, 0x2, 0x2, 0x2, 0x6, 0x18, 0x3, 0x2, 0x2, 0x2, 0x8, 0x72, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x74, 0x3, 0x2, 0x2, 0x2, 0xc, 0x8d, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0x10, 0x5, 0x4, 0x3, 0x2, 0xf, 0xe, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0x13, 0x3, 0x2, 0x2, 0x2, 0x11, 0xf, 0x3, 0x2, 0x2, 0x2, 0x11, 
    0x12, 0x3, 0x2, 0x2, 0x2, 0x12, 0x3, 0x3, 0x2, 0x2, 0x2, 0x13, 0x11, 
    0x3, 0x2, 0x2, 0x2, 0x14, 0x17, 0x5, 0x6, 0x4, 0x2, 0x15, 0x17, 0x5, 
    0x8, 0x5, 0x2, 0x16, 0x14, 0x3, 0x2, 0x2, 0x2, 0x16, 0x15, 0x3, 0x2, 
    0x2, 0x2, 0x17, 0x5, 0x3, 0x2, 0x2, 0x2, 0x18, 0x19, 0x7, 0x3, 0x2, 
    0x2, 0x19, 0x1a, 0x7, 0x21, 0x2, 0x2, 0x1a, 0x23, 0x7, 0x4, 0x2, 0x2, 
    0x1b, 0x1c, 0x7, 0x21, 0x2, 0x2, 0x1c, 0x1e, 0x7, 0x5, 0x2, 0x2, 0x1d, 
    0x1b, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x21, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x1d, 
    0x3, 0x2, 0x2, 0x2, 0x1f, 0x20, 0x3, 0x2, 0x2, 0x2, 0x20, 0x22, 0x3, 
    0x2, 0x2, 0x2, 0x21, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x22, 0x24, 0x7, 0x21, 
    0x2, 0x2, 0x23, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x23, 0x24, 0x3, 0x2, 0x2, 
    0x2, 0x24, 0x25, 0x3, 0x2, 0x2, 0x2, 0x25, 0x26, 0x7, 0x6, 0x2, 0x2, 
    0x26, 0x2a, 0x7, 0x7, 0x2, 0x2, 0x27, 0x29, 0x5, 0x8, 0x5, 0x2, 0x28, 
    0x27, 0x3, 0x2, 0x2, 0x2, 0x29, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x28, 
    0x3, 0x2, 0x2, 0x2, 0x2a, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x2d, 0x3, 
    0x2, 0x2, 0x2, 0x2c, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2e, 0x7, 0x8, 
    0x2, 0x2, 0x2e, 0x7, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x30, 0x7, 0x9, 0x2, 
    0x2, 0x30, 0x31, 0x7, 0x21, 0x2, 0x2, 0x31, 0x32, 0x7, 0xa, 0x2, 0x2, 
    0x32, 0x73, 0x5, 0xc, 0x7, 0x2, 0x33, 0x34, 0x7, 0xb, 0x2, 0x2, 0x34, 
    0x35, 0x5, 0xc, 0x7, 0x2, 0x35, 0x39, 0x7, 0x7, 0x2, 0x2, 0x36, 0x38, 
    0x5, 0x8, 0x5, 0x2, 0x37, 0x36, 0x3, 0x2, 0x2, 0x2, 0x38, 0x3b, 0x3, 
    0x2, 0x2, 0x2, 0x39, 0x37, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3a, 0x3, 0x2, 
    0x2, 0x2, 0x3a, 0x41, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x39, 0x3, 0x2, 0x2, 
    0x2, 0x3c, 0x3d, 0x7, 0xc, 0x2, 0x2, 0x3d, 0x3e, 0x7, 0xb, 0x2, 0x2, 
    0x3e, 0x40, 0x5, 0xa, 0x6, 0x2, 0x3f, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x40, 
    0x43, 0x3, 0x2, 0x2, 0x2, 0x41, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x41, 0x42, 
    0x3, 0x2, 0x2, 0x2, 0x42, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x43, 0x41, 0x3, 
    0x2, 0x2, 0x2, 0x44, 0x48, 0x7, 0xc, 0x2, 0x2, 0x45, 0x47, 0x5, 0x8, 
    0x5, 0x2, 0x46, 0x45, 0x3, 0x2, 0x2, 0x2, 0x47, 0x4a, 0x3, 0x2, 0x2, 
    0x2, 0x48, 0x46, 0x3, 0x2, 0x2, 0x2, 0x48, 0x49, 0x3, 0x2, 0x2, 0x2, 
    0x49, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x48, 0x3, 0x2, 0x2, 0x2, 0x4b, 
    0x44, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4d, 
    0x3, 0x2, 0x2, 0x2, 0x4d, 0x4e, 0x7, 0x8, 0x2, 0x2, 0x4e, 0x73, 0x3, 
    0x2, 0x2, 0x2, 0x4f, 0x50, 0x7, 0xd, 0x2, 0x2, 0x50, 0x54, 0x5, 0xc, 
    0x7, 0x2, 0x51, 0x53, 0x5, 0x8, 0x5, 0x2, 0x52, 0x51, 0x3, 0x2, 0x2, 
    0x2, 0x53, 0x56, 0x3, 0x2, 0x2, 0x2, 0x54, 0x52, 0x3, 0x2, 0x2, 0x2, 
    0x54, 0x55, 0x3, 0x2, 0x2, 0x2, 0x55, 0x57, 0x3, 0x2, 0x2, 0x2, 0x56, 
    0x54, 0x3, 0x2, 0x2, 0x2, 0x57, 0x58, 0x7, 0x8, 0x2, 0x2, 0x58, 0x73, 
    0x3, 0x2, 0x2, 0x2, 0x59, 0x5a, 0x7, 0xe, 0x2, 0x2, 0x5a, 0x5d, 0x7, 
    0x21, 0x2, 0x2, 0x5b, 0x5c, 0x7, 0x5, 0x2, 0x2, 0x5c, 0x5e, 0x7, 0x21, 
    0x2, 0x2, 0x5d, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5e, 0x3, 0x2, 0x2, 
    0x2, 0x5e, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x60, 0x7, 0xf, 0x2, 0x2, 
    0x60, 0x61, 0x5, 0xc, 0x7, 0x2, 0x61, 0x65, 0x7, 0x7, 0x2, 0x2, 0x62, 
    0x64, 0x5, 0x8, 0x5, 0x2, 0x63, 0x62, 0x3, 0x2, 0x2, 0x2, 0x64, 0x67, 
    0x3, 0x2, 0x2, 0x2, 0x65, 0x63, 0x3, 0x2, 0x2, 0x2, 0x65, 0x66, 0x3, 
    0x2, 0x2, 0x2, 0x66, 0x68, 0x3, 0x2, 0x2, 0x2, 0x67, 0x65, 0x3, 0x2, 
    0x2, 0x2, 0x68, 0x69, 0x7, 0x8, 0x2, 0x2, 0x69, 0x73, 0x3, 0x2, 0x2, 
    0x2, 0x6a, 0x6b, 0x7, 0x10, 0x2, 0x2, 0x6b, 0x73, 0x5, 0xc, 0x7, 0x2, 
    0x6c, 0x6d, 0x7, 0x11, 0x2, 0x2, 0x6d, 0x73, 0x5, 0xc, 0x7, 0x2, 0x6e, 
    0x6f, 0x7, 0x21, 0x2, 0x2, 0x6f, 0x70, 0x7, 0xa, 0x2, 0x2, 0x70, 0x73, 
    0x5, 0xc, 0x7, 0x2, 0x71, 0x73, 0x5, 0xc, 0x7, 0x2, 0x72, 0x2f, 0x3, 
    0x2, 0x2, 0x2, 0x72, 0x33, 0x3, 0x2, 0x2, 0x2, 0x72, 0x4f, 0x3, 0x2, 
    0x2, 0x2, 0x72, 0x59, 0x3, 0x2, 0x2, 0x2, 0x72, 0x6a, 0x3, 0x2, 0x2, 
    0x2, 0x72, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x72, 0x6e, 0x3, 0x2, 0x2, 0x2, 
    0x72, 0x71, 0x3, 0x2, 0x2, 0x2, 0x73, 0x9, 0x3, 0x2, 0x2, 0x2, 0x74, 
    0x75, 0x5, 0xc, 0x7, 0x2, 0x75, 0x79, 0x7, 0x7, 0x2, 0x2, 0x76, 0x78, 
    0x5, 0x8, 0x5, 0x2, 0x77, 0x76, 0x3, 0x2, 0x2, 0x2, 0x78, 0x7b, 0x3, 
    0x2, 0x2, 0x2, 0x79, 0x77, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7a, 0x3, 0x2, 
    0x2, 0x2, 0x7a, 0xb, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x79, 0x3, 0x2, 0x2, 
    0x2, 0x7c, 0x7d, 0x8, 0x7, 0x1, 0x2, 0x7d, 0x8e, 0x7, 0x21, 0x2, 0x2, 
    0x7e, 0x8e, 0x7, 0x1e, 0x2, 0x2, 0x7f, 0x8e, 0x7, 0x1f, 0x2, 0x2, 0x80, 
    0x8e, 0x7, 0x20, 0x2, 0x2, 0x81, 0x82, 0x7, 0x12, 0x2, 0x2, 0x82, 0x83, 
    0x5, 0xc, 0x7, 0x2, 0x83, 0x84, 0x7, 0x13, 0x2, 0x2, 0x84, 0x85, 0x5, 
    0xc, 0x7, 0x7, 0x85, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x86, 0x87, 0x7, 0xb, 
    0x2, 0x2, 0x87, 0x88, 0x5, 0xc, 0x7, 0x2, 0x88, 0x89, 0x7, 0x14, 0x2, 
    0x2, 0x89, 0x8a, 0x5, 0xc, 0x7, 0x2, 0x8a, 0x8b, 0x7, 0xc, 0x2, 0x2, 
    0x8b, 0x8c, 0x5, 0xc, 0x7, 0x6, 0x8c, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x8d, 
    0x7c, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x7f, 
    0x3, 0x2, 0x2, 0x2, 0x8d, 0x80, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x81, 0x3, 
    0x2, 0x2, 0x2, 0x8d, 0x86, 0x3, 0x2, 0x2, 0x2, 0x8e, 0xa8, 0x3, 0x2, 
    0x2, 0x2, 0x8f, 0x90, 0xc, 0x5, 0x2, 0x2, 0x90, 0x91, 0x9, 0x2, 0x2, 
    0x2, 0x91, 0xa7, 0x5, 0xc, 0x7, 0x6, 0x92, 0x93, 0xc, 0x4, 0x2, 0x2, 
    0x93, 0x94, 0x9, 0x3, 0x2, 0x2, 0x94, 0xa7, 0x5, 0xc, 0x7, 0x5, 0x95, 
    0x96, 0xc, 0x3, 0x2, 0x2, 0x96, 0x97, 0x9, 0x4, 0x2, 0x2, 0x97, 0xa7, 
    0x5, 0xc, 0x7, 0x4, 0x98, 0x99, 0xc, 0x8, 0x2, 0x2, 0x99, 0xa3, 0x7, 
    0x4, 0x2, 0x2, 0x9a, 0x9b, 0x5, 0xc, 0x7, 0x2, 0x9b, 0x9c, 0x7, 0x5, 
    0x2, 0x2, 0x9c, 0x9e, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x9a, 0x3, 0x2, 0x2, 
    0x2, 0x9e, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x9d, 0x3, 0x2, 0x2, 0x2, 
    0x9f, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa1, 
    0x9f, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa4, 0x5, 0xc, 0x7, 0x2, 0xa3, 0x9f, 
    0x3, 0x2, 0x2, 0x2, 0xa3, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa5, 0x3, 
    0x2, 0x2, 0x2, 0xa5, 0xa7, 0x7, 0x6, 0x2, 0x2, 0xa6, 0x8f, 0x3, 0x2, 
    0x2, 0x2, 0xa6, 0x92, 0x3, 0x2, 0x2, 0x2, 0xa6, 0x95, 0x3, 0x2, 0x2, 
    0x2, 0xa6, 0x98, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xaa, 0x3, 0x2, 0x2, 0x2, 
    0xa8, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xa9, 
    0xd, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xa8, 0x3, 0x2, 0x2, 0x2, 0x15, 0x11, 
    0x16, 0x1f, 0x23, 0x2a, 0x39, 0x41, 0x48, 0x4b, 0x54, 0x5d, 0x65, 0x72, 
    0x79, 0x8d, 0x9f, 0xa3, 0xa6, 0xa8, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

JitteryParser::Initializer JitteryParser::_init;
