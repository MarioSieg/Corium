
// Generated from Corium.g4 by ANTLR 4.9.2


#include "CoriumListener.h"
#include "CoriumVisitor.h"

#include "CoriumParser.h"


using namespace antlrcpp;
using namespace antlr4;

CoriumParser::CoriumParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

CoriumParser::~CoriumParser() {
  delete _interpreter;
}

std::string CoriumParser::getGrammarFileName() const {
  return "Corium.g4";
}

const std::vector<std::string>& CoriumParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& CoriumParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- CompilationUnitContext ------------------------------------------------------------------

CoriumParser::CompilationUnitContext::CompilationUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::ModuleDeclarationContext* CoriumParser::CompilationUnitContext::moduleDeclaration() {
  return getRuleContext<CoriumParser::ModuleDeclarationContext>(0);
}

std::vector<CoriumParser::LocalVariableDeclarationContext *> CoriumParser::CompilationUnitContext::localVariableDeclaration() {
  return getRuleContexts<CoriumParser::LocalVariableDeclarationContext>();
}

CoriumParser::LocalVariableDeclarationContext* CoriumParser::CompilationUnitContext::localVariableDeclaration(size_t i) {
  return getRuleContext<CoriumParser::LocalVariableDeclarationContext>(i);
}


size_t CoriumParser::CompilationUnitContext::getRuleIndex() const {
  return CoriumParser::RuleCompilationUnit;
}

void CoriumParser::CompilationUnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompilationUnit(this);
}

void CoriumParser::CompilationUnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompilationUnit(this);
}


antlrcpp::Any CoriumParser::CompilationUnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CoriumVisitor*>(visitor))
    return parserVisitor->visitCompilationUnit(this);
  else
    return visitor->visitChildren(this);
}

CoriumParser::CompilationUnitContext* CoriumParser::compilationUnit() {
  CompilationUnitContext *_localctx = _tracker.createInstance<CompilationUnitContext>(_ctx, getState());
  enterRule(_localctx, 0, CoriumParser::RuleCompilationUnit);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(20);
    moduleDeclaration();
    setState(24);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CoriumParser::VAR) {
      setState(21);
      localVariableDeclaration();
      setState(26);
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

//----------------- ModuleDeclarationContext ------------------------------------------------------------------

CoriumParser::ModuleDeclarationContext::ModuleDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::ModuleDeclarationContext::MODULE() {
  return getToken(CoriumParser::MODULE, 0);
}

CoriumParser::QualifiedNameContext* CoriumParser::ModuleDeclarationContext::qualifiedName() {
  return getRuleContext<CoriumParser::QualifiedNameContext>(0);
}


size_t CoriumParser::ModuleDeclarationContext::getRuleIndex() const {
  return CoriumParser::RuleModuleDeclaration;
}

void CoriumParser::ModuleDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterModuleDeclaration(this);
}

void CoriumParser::ModuleDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitModuleDeclaration(this);
}


antlrcpp::Any CoriumParser::ModuleDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CoriumVisitor*>(visitor))
    return parserVisitor->visitModuleDeclaration(this);
  else
    return visitor->visitChildren(this);
}

CoriumParser::ModuleDeclarationContext* CoriumParser::moduleDeclaration() {
  ModuleDeclarationContext *_localctx = _tracker.createInstance<ModuleDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 2, CoriumParser::RuleModuleDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(27);
    match(CoriumParser::MODULE);
    setState(28);
    qualifiedName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LocalVariableDeclarationContext ------------------------------------------------------------------

CoriumParser::LocalVariableDeclarationContext::LocalVariableDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::LocalVariableDeclarationContext::VAR() {
  return getToken(CoriumParser::VAR, 0);
}

tree::TerminalNode* CoriumParser::LocalVariableDeclarationContext::IDENT() {
  return getToken(CoriumParser::IDENT, 0);
}

tree::TerminalNode* CoriumParser::LocalVariableDeclarationContext::ASSIGN() {
  return getToken(CoriumParser::ASSIGN, 0);
}

CoriumParser::ExprContext* CoriumParser::LocalVariableDeclarationContext::expr() {
  return getRuleContext<CoriumParser::ExprContext>(0);
}


size_t CoriumParser::LocalVariableDeclarationContext::getRuleIndex() const {
  return CoriumParser::RuleLocalVariableDeclaration;
}

void CoriumParser::LocalVariableDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLocalVariableDeclaration(this);
}

void CoriumParser::LocalVariableDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLocalVariableDeclaration(this);
}


antlrcpp::Any CoriumParser::LocalVariableDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CoriumVisitor*>(visitor))
    return parserVisitor->visitLocalVariableDeclaration(this);
  else
    return visitor->visitChildren(this);
}

CoriumParser::LocalVariableDeclarationContext* CoriumParser::localVariableDeclaration() {
  LocalVariableDeclarationContext *_localctx = _tracker.createInstance<LocalVariableDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 4, CoriumParser::RuleLocalVariableDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(30);
    match(CoriumParser::VAR);
    setState(31);
    match(CoriumParser::IDENT);
    setState(32);
    match(CoriumParser::ASSIGN);
    setState(33);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

CoriumParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::ExprContext::LPAREN() {
  return getToken(CoriumParser::LPAREN, 0);
}

std::vector<CoriumParser::ExprContext *> CoriumParser::ExprContext::expr() {
  return getRuleContexts<CoriumParser::ExprContext>();
}

CoriumParser::ExprContext* CoriumParser::ExprContext::expr(size_t i) {
  return getRuleContext<CoriumParser::ExprContext>(i);
}

tree::TerminalNode* CoriumParser::ExprContext::RPAREN() {
  return getToken(CoriumParser::RPAREN, 0);
}

tree::TerminalNode* CoriumParser::ExprContext::ADD() {
  return getToken(CoriumParser::ADD, 0);
}

tree::TerminalNode* CoriumParser::ExprContext::SUB() {
  return getToken(CoriumParser::SUB, 0);
}

tree::TerminalNode* CoriumParser::ExprContext::IDENT() {
  return getToken(CoriumParser::IDENT, 0);
}

CoriumParser::LiteralContext* CoriumParser::ExprContext::literal() {
  return getRuleContext<CoriumParser::LiteralContext>(0);
}

tree::TerminalNode* CoriumParser::ExprContext::MUL() {
  return getToken(CoriumParser::MUL, 0);
}

tree::TerminalNode* CoriumParser::ExprContext::DIV() {
  return getToken(CoriumParser::DIV, 0);
}

tree::TerminalNode* CoriumParser::ExprContext::MOD() {
  return getToken(CoriumParser::MOD, 0);
}


size_t CoriumParser::ExprContext::getRuleIndex() const {
  return CoriumParser::RuleExpr;
}

void CoriumParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void CoriumParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


antlrcpp::Any CoriumParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CoriumVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}


CoriumParser::ExprContext* CoriumParser::expr() {
   return expr(0);
}

CoriumParser::ExprContext* CoriumParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CoriumParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  CoriumParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 6;
  enterRecursionRule(_localctx, 6, CoriumParser::RuleExpr, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(49);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      setState(36);
      match(CoriumParser::LPAREN);
      setState(37);
      expr(0);
      setState(38);
      match(CoriumParser::RPAREN);
      break;
    }

    case 2: {
      setState(40);
      dynamic_cast<ExprContext *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == CoriumParser::ADD

      || _la == CoriumParser::SUB)) {
        dynamic_cast<ExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(41);
      expr(5);
      break;
    }

    case 3: {
      setState(42);
      dynamic_cast<ExprContext *>(_localctx)->func = match(CoriumParser::IDENT);
      setState(43);
      match(CoriumParser::LPAREN);
      setState(44);
      expr(0);
      setState(45);
      match(CoriumParser::RPAREN);
      break;
    }

    case 4: {
      setState(47);
      dynamic_cast<ExprContext *>(_localctx)->value = literal();
      break;
    }

    case 5: {
      setState(48);
      match(CoriumParser::IDENT);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(56);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpr);
        setState(51);

        if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
        setState(52);
        dynamic_cast<ExprContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CoriumParser::ADD)
          | (1ULL << CoriumParser::SUB)
          | (1ULL << CoriumParser::MUL)
          | (1ULL << CoriumParser::DIV)
          | (1ULL << CoriumParser::MOD))) != 0))) {
          dynamic_cast<ExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(53);
        expr(5); 
      }
      setState(58);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TypeClassNameContext ------------------------------------------------------------------

CoriumParser::TypeClassNameContext::TypeClassNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::BuiltinTypeContext* CoriumParser::TypeClassNameContext::builtinType() {
  return getRuleContext<CoriumParser::BuiltinTypeContext>(0);
}

CoriumParser::QualifiedNameContext* CoriumParser::TypeClassNameContext::qualifiedName() {
  return getRuleContext<CoriumParser::QualifiedNameContext>(0);
}


size_t CoriumParser::TypeClassNameContext::getRuleIndex() const {
  return CoriumParser::RuleTypeClassName;
}

void CoriumParser::TypeClassNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeClassName(this);
}

void CoriumParser::TypeClassNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeClassName(this);
}


antlrcpp::Any CoriumParser::TypeClassNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CoriumVisitor*>(visitor))
    return parserVisitor->visitTypeClassName(this);
  else
    return visitor->visitChildren(this);
}

CoriumParser::TypeClassNameContext* CoriumParser::typeClassName() {
  TypeClassNameContext *_localctx = _tracker.createInstance<TypeClassNameContext>(_ctx, getState());
  enterRule(_localctx, 8, CoriumParser::RuleTypeClassName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(61);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CoriumParser::BOOL:
      case CoriumParser::CHAR:
      case CoriumParser::FLOAT:
      case CoriumParser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(59);
        builtinType();
        break;
      }

      case CoriumParser::IDENT: {
        enterOuterAlt(_localctx, 2);
        setState(60);
        qualifiedName();
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

//----------------- BuiltinTypeContext ------------------------------------------------------------------

CoriumParser::BuiltinTypeContext::BuiltinTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::BuiltinTypeContext::INT() {
  return getToken(CoriumParser::INT, 0);
}

tree::TerminalNode* CoriumParser::BuiltinTypeContext::FLOAT() {
  return getToken(CoriumParser::FLOAT, 0);
}

tree::TerminalNode* CoriumParser::BuiltinTypeContext::CHAR() {
  return getToken(CoriumParser::CHAR, 0);
}

tree::TerminalNode* CoriumParser::BuiltinTypeContext::BOOL() {
  return getToken(CoriumParser::BOOL, 0);
}


size_t CoriumParser::BuiltinTypeContext::getRuleIndex() const {
  return CoriumParser::RuleBuiltinType;
}

void CoriumParser::BuiltinTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBuiltinType(this);
}

void CoriumParser::BuiltinTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBuiltinType(this);
}


antlrcpp::Any CoriumParser::BuiltinTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CoriumVisitor*>(visitor))
    return parserVisitor->visitBuiltinType(this);
  else
    return visitor->visitChildren(this);
}

CoriumParser::BuiltinTypeContext* CoriumParser::builtinType() {
  BuiltinTypeContext *_localctx = _tracker.createInstance<BuiltinTypeContext>(_ctx, getState());
  enterRule(_localctx, 10, CoriumParser::RuleBuiltinType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(63);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CoriumParser::BOOL)
      | (1ULL << CoriumParser::CHAR)
      | (1ULL << CoriumParser::FLOAT)
      | (1ULL << CoriumParser::INT))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QualifiedNameContext ------------------------------------------------------------------

CoriumParser::QualifiedNameContext::QualifiedNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> CoriumParser::QualifiedNameContext::IDENT() {
  return getTokens(CoriumParser::IDENT);
}

tree::TerminalNode* CoriumParser::QualifiedNameContext::IDENT(size_t i) {
  return getToken(CoriumParser::IDENT, i);
}

std::vector<tree::TerminalNode *> CoriumParser::QualifiedNameContext::DOT() {
  return getTokens(CoriumParser::DOT);
}

tree::TerminalNode* CoriumParser::QualifiedNameContext::DOT(size_t i) {
  return getToken(CoriumParser::DOT, i);
}


size_t CoriumParser::QualifiedNameContext::getRuleIndex() const {
  return CoriumParser::RuleQualifiedName;
}

void CoriumParser::QualifiedNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQualifiedName(this);
}

void CoriumParser::QualifiedNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQualifiedName(this);
}


antlrcpp::Any CoriumParser::QualifiedNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CoriumVisitor*>(visitor))
    return parserVisitor->visitQualifiedName(this);
  else
    return visitor->visitChildren(this);
}

CoriumParser::QualifiedNameContext* CoriumParser::qualifiedName() {
  QualifiedNameContext *_localctx = _tracker.createInstance<QualifiedNameContext>(_ctx, getState());
  enterRule(_localctx, 12, CoriumParser::RuleQualifiedName);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(65);
    match(CoriumParser::IDENT);
    setState(70);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CoriumParser::DOT) {
      setState(66);
      match(CoriumParser::DOT);
      setState(67);
      match(CoriumParser::IDENT);
      setState(72);
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

//----------------- LiteralContext ------------------------------------------------------------------

CoriumParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::IntLiteralContext* CoriumParser::LiteralContext::intLiteral() {
  return getRuleContext<CoriumParser::IntLiteralContext>(0);
}

CoriumParser::FloatLiteralContext* CoriumParser::LiteralContext::floatLiteral() {
  return getRuleContext<CoriumParser::FloatLiteralContext>(0);
}

tree::TerminalNode* CoriumParser::LiteralContext::BOOL_LITERAL() {
  return getToken(CoriumParser::BOOL_LITERAL, 0);
}

tree::TerminalNode* CoriumParser::LiteralContext::CHAR_LITERAL() {
  return getToken(CoriumParser::CHAR_LITERAL, 0);
}

tree::TerminalNode* CoriumParser::LiteralContext::STRING_LITERAL() {
  return getToken(CoriumParser::STRING_LITERAL, 0);
}


size_t CoriumParser::LiteralContext::getRuleIndex() const {
  return CoriumParser::RuleLiteral;
}

void CoriumParser::LiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteral(this);
}

void CoriumParser::LiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteral(this);
}


antlrcpp::Any CoriumParser::LiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CoriumVisitor*>(visitor))
    return parserVisitor->visitLiteral(this);
  else
    return visitor->visitChildren(this);
}

CoriumParser::LiteralContext* CoriumParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 14, CoriumParser::RuleLiteral);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(78);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CoriumParser::INT_LITERAL_DEC:
      case CoriumParser::INT_LITERAL_HEX:
      case CoriumParser::INT_LITERAL_OCT:
      case CoriumParser::INT_LITERAL_BIN: {
        enterOuterAlt(_localctx, 1);
        setState(73);
        intLiteral();
        break;
      }

      case CoriumParser::FLOAT_LITERAL_DEC:
      case CoriumParser::FLOAT_LITERAL_HEX: {
        enterOuterAlt(_localctx, 2);
        setState(74);
        floatLiteral();
        break;
      }

      case CoriumParser::BOOL_LITERAL: {
        enterOuterAlt(_localctx, 3);
        setState(75);
        match(CoriumParser::BOOL_LITERAL);
        break;
      }

      case CoriumParser::CHAR_LITERAL: {
        enterOuterAlt(_localctx, 4);
        setState(76);
        match(CoriumParser::CHAR_LITERAL);
        break;
      }

      case CoriumParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 5);
        setState(77);
        match(CoriumParser::STRING_LITERAL);
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

//----------------- IntLiteralContext ------------------------------------------------------------------

CoriumParser::IntLiteralContext::IntLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::IntLiteralContext::INT_LITERAL_DEC() {
  return getToken(CoriumParser::INT_LITERAL_DEC, 0);
}

tree::TerminalNode* CoriumParser::IntLiteralContext::INT_LITERAL_HEX() {
  return getToken(CoriumParser::INT_LITERAL_HEX, 0);
}

tree::TerminalNode* CoriumParser::IntLiteralContext::INT_LITERAL_OCT() {
  return getToken(CoriumParser::INT_LITERAL_OCT, 0);
}

tree::TerminalNode* CoriumParser::IntLiteralContext::INT_LITERAL_BIN() {
  return getToken(CoriumParser::INT_LITERAL_BIN, 0);
}


size_t CoriumParser::IntLiteralContext::getRuleIndex() const {
  return CoriumParser::RuleIntLiteral;
}

void CoriumParser::IntLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntLiteral(this);
}

void CoriumParser::IntLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntLiteral(this);
}


antlrcpp::Any CoriumParser::IntLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CoriumVisitor*>(visitor))
    return parserVisitor->visitIntLiteral(this);
  else
    return visitor->visitChildren(this);
}

CoriumParser::IntLiteralContext* CoriumParser::intLiteral() {
  IntLiteralContext *_localctx = _tracker.createInstance<IntLiteralContext>(_ctx, getState());
  enterRule(_localctx, 16, CoriumParser::RuleIntLiteral);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(80);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CoriumParser::INT_LITERAL_DEC)
      | (1ULL << CoriumParser::INT_LITERAL_HEX)
      | (1ULL << CoriumParser::INT_LITERAL_OCT)
      | (1ULL << CoriumParser::INT_LITERAL_BIN))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FloatLiteralContext ------------------------------------------------------------------

CoriumParser::FloatLiteralContext::FloatLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::FloatLiteralContext::FLOAT_LITERAL_DEC() {
  return getToken(CoriumParser::FLOAT_LITERAL_DEC, 0);
}

tree::TerminalNode* CoriumParser::FloatLiteralContext::FLOAT_LITERAL_HEX() {
  return getToken(CoriumParser::FLOAT_LITERAL_HEX, 0);
}


size_t CoriumParser::FloatLiteralContext::getRuleIndex() const {
  return CoriumParser::RuleFloatLiteral;
}

void CoriumParser::FloatLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFloatLiteral(this);
}

void CoriumParser::FloatLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFloatLiteral(this);
}


antlrcpp::Any CoriumParser::FloatLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CoriumVisitor*>(visitor))
    return parserVisitor->visitFloatLiteral(this);
  else
    return visitor->visitChildren(this);
}

CoriumParser::FloatLiteralContext* CoriumParser::floatLiteral() {
  FloatLiteralContext *_localctx = _tracker.createInstance<FloatLiteralContext>(_ctx, getState());
  enterRule(_localctx, 18, CoriumParser::RuleFloatLiteral);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(82);
    _la = _input->LA(1);
    if (!(_la == CoriumParser::FLOAT_LITERAL_DEC

    || _la == CoriumParser::FLOAT_LITERAL_HEX)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool CoriumParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 3: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool CoriumParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 4);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> CoriumParser::_decisionToDFA;
atn::PredictionContextCache CoriumParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN CoriumParser::_atn;
std::vector<uint16_t> CoriumParser::_serializedATN;

std::vector<std::string> CoriumParser::_ruleNames = {
  "compilationUnit", "moduleDeclaration", "localVariableDeclaration", "expr", 
  "typeClassName", "builtinType", "qualifiedName", "literal", "intLiteral", 
  "floatLiteral"
};

std::vector<std::string> CoriumParser::_literalNames = {
  "", "'bool'", "'char'", "'float'", "'int'", "'var'", "'module'", "", "", 
  "", "", "", "", "", "", "", "'('", "')'", "'{'", "'}'", "'['", "']'", 
  "';'", "','", "'.'", "'='", "'+'", "'-'", "'*'", "'/'", "'%'"
};

std::vector<std::string> CoriumParser::_symbolicNames = {
  "", "BOOL", "CHAR", "FLOAT", "INT", "VAR", "MODULE", "INT_LITERAL_DEC", 
  "INT_LITERAL_HEX", "INT_LITERAL_OCT", "INT_LITERAL_BIN", "FLOAT_LITERAL_DEC", 
  "FLOAT_LITERAL_HEX", "BOOL_LITERAL", "CHAR_LITERAL", "STRING_LITERAL", 
  "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACK", "RBRACK", "SEMI", "COMMA", 
  "DOT", "ASSIGN", "ADD", "SUB", "MUL", "DIV", "MOD", "IDENT", "SPACE", 
  "SINGLE_LINE_COMMENT", "MULTI_LINE_COMMENT"
};

dfa::Vocabulary CoriumParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> CoriumParser::_tokenNames;

CoriumParser::Initializer::Initializer() {
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

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0x24, 0x57, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x19, 0xa, 0x2, 
       0xc, 0x2, 0xe, 0x2, 0x1c, 0xb, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 
       0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
       0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 
       0x5, 0x34, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x39, 
       0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x3c, 0xb, 0x5, 0x3, 0x6, 0x3, 0x6, 
       0x5, 0x6, 0x40, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 
       0x3, 0x8, 0x7, 0x8, 0x47, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0x4a, 0xb, 
       0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 
       0x51, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
       0x2, 0x3, 0x8, 0xc, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 
       0x14, 0x2, 0x7, 0x3, 0x2, 0x1c, 0x1d, 0x3, 0x2, 0x1c, 0x20, 0x3, 
       0x2, 0x3, 0x6, 0x3, 0x2, 0x9, 0xc, 0x3, 0x2, 0xd, 0xe, 0x2, 0x58, 
       0x2, 0x16, 0x3, 0x2, 0x2, 0x2, 0x4, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x6, 
       0x20, 0x3, 0x2, 0x2, 0x2, 0x8, 0x33, 0x3, 0x2, 0x2, 0x2, 0xa, 0x3f, 
       0x3, 0x2, 0x2, 0x2, 0xc, 0x41, 0x3, 0x2, 0x2, 0x2, 0xe, 0x43, 0x3, 
       0x2, 0x2, 0x2, 0x10, 0x50, 0x3, 0x2, 0x2, 0x2, 0x12, 0x52, 0x3, 0x2, 
       0x2, 0x2, 0x14, 0x54, 0x3, 0x2, 0x2, 0x2, 0x16, 0x1a, 0x5, 0x4, 0x3, 
       0x2, 0x17, 0x19, 0x5, 0x6, 0x4, 0x2, 0x18, 0x17, 0x3, 0x2, 0x2, 0x2, 
       0x19, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x18, 0x3, 0x2, 0x2, 0x2, 0x1a, 
       0x1b, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x3, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1a, 
       0x3, 0x2, 0x2, 0x2, 0x1d, 0x1e, 0x7, 0x8, 0x2, 0x2, 0x1e, 0x1f, 0x5, 
       0xe, 0x8, 0x2, 0x1f, 0x5, 0x3, 0x2, 0x2, 0x2, 0x20, 0x21, 0x7, 0x7, 
       0x2, 0x2, 0x21, 0x22, 0x7, 0x21, 0x2, 0x2, 0x22, 0x23, 0x7, 0x1b, 
       0x2, 0x2, 0x23, 0x24, 0x5, 0x8, 0x5, 0x2, 0x24, 0x7, 0x3, 0x2, 0x2, 
       0x2, 0x25, 0x26, 0x8, 0x5, 0x1, 0x2, 0x26, 0x27, 0x7, 0x12, 0x2, 
       0x2, 0x27, 0x28, 0x5, 0x8, 0x5, 0x2, 0x28, 0x29, 0x7, 0x13, 0x2, 
       0x2, 0x29, 0x34, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2b, 0x9, 0x2, 0x2, 0x2, 
       0x2b, 0x34, 0x5, 0x8, 0x5, 0x7, 0x2c, 0x2d, 0x7, 0x21, 0x2, 0x2, 
       0x2d, 0x2e, 0x7, 0x12, 0x2, 0x2, 0x2e, 0x2f, 0x5, 0x8, 0x5, 0x2, 
       0x2f, 0x30, 0x7, 0x13, 0x2, 0x2, 0x30, 0x34, 0x3, 0x2, 0x2, 0x2, 
       0x31, 0x34, 0x5, 0x10, 0x9, 0x2, 0x32, 0x34, 0x7, 0x21, 0x2, 0x2, 
       0x33, 0x25, 0x3, 0x2, 0x2, 0x2, 0x33, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x33, 
       0x2c, 0x3, 0x2, 0x2, 0x2, 0x33, 0x31, 0x3, 0x2, 0x2, 0x2, 0x33, 0x32, 
       0x3, 0x2, 0x2, 0x2, 0x34, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x35, 0x36, 0xc, 
       0x6, 0x2, 0x2, 0x36, 0x37, 0x9, 0x3, 0x2, 0x2, 0x37, 0x39, 0x5, 0x8, 
       0x5, 0x7, 0x38, 0x35, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3c, 0x3, 0x2, 0x2, 
       0x2, 0x3a, 0x38, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3b, 0x3, 0x2, 0x2, 0x2, 
       0x3b, 0x9, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x3d, 
       0x40, 0x5, 0xc, 0x7, 0x2, 0x3e, 0x40, 0x5, 0xe, 0x8, 0x2, 0x3f, 0x3d, 
       0x3, 0x2, 0x2, 0x2, 0x3f, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x40, 0xb, 0x3, 
       0x2, 0x2, 0x2, 0x41, 0x42, 0x9, 0x4, 0x2, 0x2, 0x42, 0xd, 0x3, 0x2, 
       0x2, 0x2, 0x43, 0x48, 0x7, 0x21, 0x2, 0x2, 0x44, 0x45, 0x7, 0x1a, 
       0x2, 0x2, 0x45, 0x47, 0x7, 0x21, 0x2, 0x2, 0x46, 0x44, 0x3, 0x2, 
       0x2, 0x2, 0x47, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x48, 0x46, 0x3, 0x2, 0x2, 
       0x2, 0x48, 0x49, 0x3, 0x2, 0x2, 0x2, 0x49, 0xf, 0x3, 0x2, 0x2, 0x2, 
       0x4a, 0x48, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x51, 0x5, 0x12, 0xa, 0x2, 
       0x4c, 0x51, 0x5, 0x14, 0xb, 0x2, 0x4d, 0x51, 0x7, 0xf, 0x2, 0x2, 
       0x4e, 0x51, 0x7, 0x10, 0x2, 0x2, 0x4f, 0x51, 0x7, 0x11, 0x2, 0x2, 
       0x50, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x50, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x50, 
       0x4d, 0x3, 0x2, 0x2, 0x2, 0x50, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x50, 0x4f, 
       0x3, 0x2, 0x2, 0x2, 0x51, 0x11, 0x3, 0x2, 0x2, 0x2, 0x52, 0x53, 0x9, 
       0x5, 0x2, 0x2, 0x53, 0x13, 0x3, 0x2, 0x2, 0x2, 0x54, 0x55, 0x9, 0x6, 
       0x2, 0x2, 0x55, 0x15, 0x3, 0x2, 0x2, 0x2, 0x8, 0x1a, 0x33, 0x3a, 
       0x3f, 0x48, 0x50, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

CoriumParser::Initializer CoriumParser::_init;
