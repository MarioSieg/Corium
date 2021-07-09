
// Generated from Corium.g4 by ANTLR 4.9


#include "CoriumListener.h"

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

tree::TerminalNode* CoriumParser::CompilationUnitContext::EOF() {
  return getToken(CoriumParser::EOF, 0);
}

std::vector<CoriumParser::CompilationUnitStatementContext *> CoriumParser::CompilationUnitContext::compilationUnitStatement() {
  return getRuleContexts<CoriumParser::CompilationUnitStatementContext>();
}

CoriumParser::CompilationUnitStatementContext* CoriumParser::CompilationUnitContext::compilationUnitStatement(size_t i) {
  return getRuleContext<CoriumParser::CompilationUnitStatementContext>(i);
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
    setState(22);
    moduleDeclaration();
    setState(26);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CoriumParser::FUN)
      | (1ULL << CoriumParser::CONST)
      | (1ULL << CoriumParser::SPACE))) != 0)) {
      setState(23);
      compilationUnitStatement();
      setState(28);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(29);
    match(CoriumParser::EOF);
   
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

tree::TerminalNode* CoriumParser::ModuleDeclarationContext::IDENT() {
  return getToken(CoriumParser::IDENT, 0);
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
    setState(31);
    match(CoriumParser::MODULE);
    setState(32);
    match(CoriumParser::IDENT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompilationUnitStatementContext ------------------------------------------------------------------

CoriumParser::CompilationUnitStatementContext::CompilationUnitStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::FunctionDeclarationContext* CoriumParser::CompilationUnitStatementContext::functionDeclaration() {
  return getRuleContext<CoriumParser::FunctionDeclarationContext>(0);
}

CoriumParser::ConstVariableDeclarationContext* CoriumParser::CompilationUnitStatementContext::constVariableDeclaration() {
  return getRuleContext<CoriumParser::ConstVariableDeclarationContext>(0);
}

tree::TerminalNode* CoriumParser::CompilationUnitStatementContext::SPACE() {
  return getToken(CoriumParser::SPACE, 0);
}


size_t CoriumParser::CompilationUnitStatementContext::getRuleIndex() const {
  return CoriumParser::RuleCompilationUnitStatement;
}

void CoriumParser::CompilationUnitStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompilationUnitStatement(this);
}

void CoriumParser::CompilationUnitStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompilationUnitStatement(this);
}

CoriumParser::CompilationUnitStatementContext* CoriumParser::compilationUnitStatement() {
  CompilationUnitStatementContext *_localctx = _tracker.createInstance<CompilationUnitStatementContext>(_ctx, getState());
  enterRule(_localctx, 4, CoriumParser::RuleCompilationUnitStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(37);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CoriumParser::FUN: {
        enterOuterAlt(_localctx, 1);
        setState(34);
        functionDeclaration();
        break;
      }

      case CoriumParser::CONST: {
        enterOuterAlt(_localctx, 2);
        setState(35);
        constVariableDeclaration();
        break;
      }

      case CoriumParser::SPACE: {
        enterOuterAlt(_localctx, 3);
        setState(36);
        match(CoriumParser::SPACE);
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

//----------------- FunctionDeclarationContext ------------------------------------------------------------------

CoriumParser::FunctionDeclarationContext::FunctionDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::FunctionDeclarationContext::FUN() {
  return getToken(CoriumParser::FUN, 0);
}

tree::TerminalNode* CoriumParser::FunctionDeclarationContext::IDENT() {
  return getToken(CoriumParser::IDENT, 0);
}

tree::TerminalNode* CoriumParser::FunctionDeclarationContext::LPAREN() {
  return getToken(CoriumParser::LPAREN, 0);
}

tree::TerminalNode* CoriumParser::FunctionDeclarationContext::RPAREN() {
  return getToken(CoriumParser::RPAREN, 0);
}

tree::TerminalNode* CoriumParser::FunctionDeclarationContext::LBRACE() {
  return getToken(CoriumParser::LBRACE, 0);
}

tree::TerminalNode* CoriumParser::FunctionDeclarationContext::RBRACE() {
  return getToken(CoriumParser::RBRACE, 0);
}

std::vector<CoriumParser::FunctionBlockStatementContext *> CoriumParser::FunctionDeclarationContext::functionBlockStatement() {
  return getRuleContexts<CoriumParser::FunctionBlockStatementContext>();
}

CoriumParser::FunctionBlockStatementContext* CoriumParser::FunctionDeclarationContext::functionBlockStatement(size_t i) {
  return getRuleContext<CoriumParser::FunctionBlockStatementContext>(i);
}


size_t CoriumParser::FunctionDeclarationContext::getRuleIndex() const {
  return CoriumParser::RuleFunctionDeclaration;
}

void CoriumParser::FunctionDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDeclaration(this);
}

void CoriumParser::FunctionDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDeclaration(this);
}

CoriumParser::FunctionDeclarationContext* CoriumParser::functionDeclaration() {
  FunctionDeclarationContext *_localctx = _tracker.createInstance<FunctionDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 6, CoriumParser::RuleFunctionDeclaration);
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
    setState(39);
    match(CoriumParser::FUN);
    setState(40);
    match(CoriumParser::IDENT);
    setState(41);
    match(CoriumParser::LPAREN);
    setState(42);
    match(CoriumParser::RPAREN);
    setState(43);
    match(CoriumParser::LBRACE);
    setState(47);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CoriumParser::LET

    || _la == CoriumParser::CONST) {
      setState(44);
      functionBlockStatement();
      setState(49);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(50);
    match(CoriumParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionBlockStatementContext ------------------------------------------------------------------

CoriumParser::FunctionBlockStatementContext::FunctionBlockStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::LocalVariableDeclarationContext* CoriumParser::FunctionBlockStatementContext::localVariableDeclaration() {
  return getRuleContext<CoriumParser::LocalVariableDeclarationContext>(0);
}

CoriumParser::ConstVariableDeclarationContext* CoriumParser::FunctionBlockStatementContext::constVariableDeclaration() {
  return getRuleContext<CoriumParser::ConstVariableDeclarationContext>(0);
}


size_t CoriumParser::FunctionBlockStatementContext::getRuleIndex() const {
  return CoriumParser::RuleFunctionBlockStatement;
}

void CoriumParser::FunctionBlockStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionBlockStatement(this);
}

void CoriumParser::FunctionBlockStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionBlockStatement(this);
}

CoriumParser::FunctionBlockStatementContext* CoriumParser::functionBlockStatement() {
  FunctionBlockStatementContext *_localctx = _tracker.createInstance<FunctionBlockStatementContext>(_ctx, getState());
  enterRule(_localctx, 8, CoriumParser::RuleFunctionBlockStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(54);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CoriumParser::LET: {
        enterOuterAlt(_localctx, 1);
        setState(52);
        localVariableDeclaration();
        break;
      }

      case CoriumParser::CONST: {
        enterOuterAlt(_localctx, 2);
        setState(53);
        constVariableDeclaration();
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

//----------------- LocalVariableDeclarationContext ------------------------------------------------------------------

CoriumParser::LocalVariableDeclarationContext::LocalVariableDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::LocalVariableDeclarationContext::LET() {
  return getToken(CoriumParser::LET, 0);
}

tree::TerminalNode* CoriumParser::LocalVariableDeclarationContext::ASSIGN() {
  return getToken(CoriumParser::ASSIGN, 0);
}

CoriumParser::LiteralContext* CoriumParser::LocalVariableDeclarationContext::literal() {
  return getRuleContext<CoriumParser::LiteralContext>(0);
}

CoriumParser::BuiltinTypeContext* CoriumParser::LocalVariableDeclarationContext::builtinType() {
  return getRuleContext<CoriumParser::BuiltinTypeContext>(0);
}

tree::TerminalNode* CoriumParser::LocalVariableDeclarationContext::IDENT() {
  return getToken(CoriumParser::IDENT, 0);
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

CoriumParser::LocalVariableDeclarationContext* CoriumParser::localVariableDeclaration() {
  LocalVariableDeclarationContext *_localctx = _tracker.createInstance<LocalVariableDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 10, CoriumParser::RuleLocalVariableDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(56);
    match(CoriumParser::LET);
    setState(59);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CoriumParser::BOOL:
      case CoriumParser::CHAR:
      case CoriumParser::FLOAT:
      case CoriumParser::INT:
      case CoriumParser::STRING: {
        setState(57);
        builtinType();
        break;
      }

      case CoriumParser::IDENT: {
        setState(58);
        match(CoriumParser::IDENT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(61);
    match(CoriumParser::ASSIGN);
    setState(62);
    literal();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstVariableDeclarationContext ------------------------------------------------------------------

CoriumParser::ConstVariableDeclarationContext::ConstVariableDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::ConstVariableDeclarationContext::CONST() {
  return getToken(CoriumParser::CONST, 0);
}

tree::TerminalNode* CoriumParser::ConstVariableDeclarationContext::ASSIGN() {
  return getToken(CoriumParser::ASSIGN, 0);
}

CoriumParser::LiteralContext* CoriumParser::ConstVariableDeclarationContext::literal() {
  return getRuleContext<CoriumParser::LiteralContext>(0);
}

CoriumParser::BuiltinTypeContext* CoriumParser::ConstVariableDeclarationContext::builtinType() {
  return getRuleContext<CoriumParser::BuiltinTypeContext>(0);
}

tree::TerminalNode* CoriumParser::ConstVariableDeclarationContext::IDENT() {
  return getToken(CoriumParser::IDENT, 0);
}


size_t CoriumParser::ConstVariableDeclarationContext::getRuleIndex() const {
  return CoriumParser::RuleConstVariableDeclaration;
}

void CoriumParser::ConstVariableDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstVariableDeclaration(this);
}

void CoriumParser::ConstVariableDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstVariableDeclaration(this);
}

CoriumParser::ConstVariableDeclarationContext* CoriumParser::constVariableDeclaration() {
  ConstVariableDeclarationContext *_localctx = _tracker.createInstance<ConstVariableDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 12, CoriumParser::RuleConstVariableDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(64);
    match(CoriumParser::CONST);
    setState(67);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CoriumParser::BOOL:
      case CoriumParser::CHAR:
      case CoriumParser::FLOAT:
      case CoriumParser::INT:
      case CoriumParser::STRING: {
        setState(65);
        builtinType();
        break;
      }

      case CoriumParser::IDENT: {
        setState(66);
        match(CoriumParser::IDENT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(69);
    match(CoriumParser::ASSIGN);
    setState(70);
    literal();
   
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
    setState(77);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CoriumParser::INT_LITERAL_DEC:
      case CoriumParser::INT_LITERAL_HEX:
      case CoriumParser::INT_LITERAL_OCT:
      case CoriumParser::INT_LITERAL_BIN: {
        enterOuterAlt(_localctx, 1);
        setState(72);
        intLiteral();
        break;
      }

      case CoriumParser::FLOAT_LITERAL_DEC:
      case CoriumParser::FLOAT_LITERAL_HEX: {
        enterOuterAlt(_localctx, 2);
        setState(73);
        floatLiteral();
        break;
      }

      case CoriumParser::BOOL_LITERAL: {
        enterOuterAlt(_localctx, 3);
        setState(74);
        match(CoriumParser::BOOL_LITERAL);
        break;
      }

      case CoriumParser::CHAR_LITERAL: {
        enterOuterAlt(_localctx, 4);
        setState(75);
        match(CoriumParser::CHAR_LITERAL);
        break;
      }

      case CoriumParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 5);
        setState(76);
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
    setState(79);
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
    setState(81);
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

tree::TerminalNode* CoriumParser::BuiltinTypeContext::STRING() {
  return getToken(CoriumParser::STRING, 0);
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

CoriumParser::BuiltinTypeContext* CoriumParser::builtinType() {
  BuiltinTypeContext *_localctx = _tracker.createInstance<BuiltinTypeContext>(_ctx, getState());
  enterRule(_localctx, 20, CoriumParser::RuleBuiltinType);
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
    setState(83);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CoriumParser::BOOL)
      | (1ULL << CoriumParser::CHAR)
      | (1ULL << CoriumParser::FLOAT)
      | (1ULL << CoriumParser::INT)
      | (1ULL << CoriumParser::STRING))) != 0))) {
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

// Static vars and initialization.
std::vector<dfa::DFA> CoriumParser::_decisionToDFA;
atn::PredictionContextCache CoriumParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN CoriumParser::_atn;
std::vector<uint16_t> CoriumParser::_serializedATN;

std::vector<std::string> CoriumParser::_ruleNames = {
  "compilationUnit", "moduleDeclaration", "compilationUnitStatement", "functionDeclaration", 
  "functionBlockStatement", "localVariableDeclaration", "constVariableDeclaration", 
  "literal", "intLiteral", "floatLiteral", "builtinType"
};

std::vector<std::string> CoriumParser::_literalNames = {
  "", "'bool'", "'char'", "'float'", "'fun'", "'int'", "'string'", "'let'", 
  "'native'", "'const'", "'module'", "'class'", "'struct'", "'static'", 
  "", "", "", "", "", "", "", "", "", "'('", "')'", "'{'", "'}'", "'['", 
  "']'", "';'", "','", "'.'", "'='"
};

std::vector<std::string> CoriumParser::_symbolicNames = {
  "", "BOOL", "CHAR", "FLOAT", "FUN", "INT", "STRING", "LET", "NATIVE", 
  "CONST", "MODULE", "CLASS", "STRUCT", "STATIC", "INT_LITERAL_DEC", "INT_LITERAL_HEX", 
  "INT_LITERAL_OCT", "INT_LITERAL_BIN", "FLOAT_LITERAL_DEC", "FLOAT_LITERAL_HEX", 
  "BOOL_LITERAL", "CHAR_LITERAL", "STRING_LITERAL", "LPAREN", "RPAREN", 
  "LBRACE", "RBRACE", "LBRACK", "RBRACK", "SEMI", "COMMA", "DOT", "ASSIGN", 
  "IDENT", "SPACE", "SINGLE_LINE_COMMENT", "MULTI_LINE_COMMENT"
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

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x26, 0x58, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x1b, 0xa, 0x2, 
    0xc, 0x2, 0xe, 0x2, 0x1e, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x28, 0xa, 0x4, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 
    0x30, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x33, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x39, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x5, 0x7, 0x3e, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x46, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x50, 
    0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x2, 0x2, 0xd, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 
    0x14, 0x16, 0x2, 0x5, 0x3, 0x2, 0x10, 0x13, 0x3, 0x2, 0x14, 0x15, 0x4, 
    0x2, 0x3, 0x5, 0x7, 0x8, 0x2, 0x57, 0x2, 0x18, 0x3, 0x2, 0x2, 0x2, 0x4, 
    0x21, 0x3, 0x2, 0x2, 0x2, 0x6, 0x27, 0x3, 0x2, 0x2, 0x2, 0x8, 0x29, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x38, 0x3, 0x2, 0x2, 0x2, 0xc, 0x3a, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0x42, 0x3, 0x2, 0x2, 0x2, 0x10, 0x4f, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0x51, 0x3, 0x2, 0x2, 0x2, 0x14, 0x53, 0x3, 0x2, 0x2, 0x2, 
    0x16, 0x55, 0x3, 0x2, 0x2, 0x2, 0x18, 0x1c, 0x5, 0x4, 0x3, 0x2, 0x19, 
    0x1b, 0x5, 0x6, 0x4, 0x2, 0x1a, 0x19, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x1e, 
    0x3, 0x2, 0x2, 0x2, 0x1c, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1d, 0x3, 
    0x2, 0x2, 0x2, 0x1d, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x1c, 0x3, 0x2, 
    0x2, 0x2, 0x1f, 0x20, 0x7, 0x2, 0x2, 0x3, 0x20, 0x3, 0x3, 0x2, 0x2, 
    0x2, 0x21, 0x22, 0x7, 0xc, 0x2, 0x2, 0x22, 0x23, 0x7, 0x23, 0x2, 0x2, 
    0x23, 0x5, 0x3, 0x2, 0x2, 0x2, 0x24, 0x28, 0x5, 0x8, 0x5, 0x2, 0x25, 
    0x28, 0x5, 0xe, 0x8, 0x2, 0x26, 0x28, 0x7, 0x24, 0x2, 0x2, 0x27, 0x24, 
    0x3, 0x2, 0x2, 0x2, 0x27, 0x25, 0x3, 0x2, 0x2, 0x2, 0x27, 0x26, 0x3, 
    0x2, 0x2, 0x2, 0x28, 0x7, 0x3, 0x2, 0x2, 0x2, 0x29, 0x2a, 0x7, 0x6, 
    0x2, 0x2, 0x2a, 0x2b, 0x7, 0x23, 0x2, 0x2, 0x2b, 0x2c, 0x7, 0x19, 0x2, 
    0x2, 0x2c, 0x2d, 0x7, 0x1a, 0x2, 0x2, 0x2d, 0x31, 0x7, 0x1b, 0x2, 0x2, 
    0x2e, 0x30, 0x5, 0xa, 0x6, 0x2, 0x2f, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x30, 
    0x33, 0x3, 0x2, 0x2, 0x2, 0x31, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x31, 0x32, 
    0x3, 0x2, 0x2, 0x2, 0x32, 0x34, 0x3, 0x2, 0x2, 0x2, 0x33, 0x31, 0x3, 
    0x2, 0x2, 0x2, 0x34, 0x35, 0x7, 0x1c, 0x2, 0x2, 0x35, 0x9, 0x3, 0x2, 
    0x2, 0x2, 0x36, 0x39, 0x5, 0xc, 0x7, 0x2, 0x37, 0x39, 0x5, 0xe, 0x8, 
    0x2, 0x38, 0x36, 0x3, 0x2, 0x2, 0x2, 0x38, 0x37, 0x3, 0x2, 0x2, 0x2, 
    0x39, 0xb, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3d, 0x7, 0x9, 0x2, 0x2, 0x3b, 
    0x3e, 0x5, 0x16, 0xc, 0x2, 0x3c, 0x3e, 0x7, 0x23, 0x2, 0x2, 0x3d, 0x3b, 
    0x3, 0x2, 0x2, 0x2, 0x3d, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x3f, 0x3, 
    0x2, 0x2, 0x2, 0x3f, 0x40, 0x7, 0x22, 0x2, 0x2, 0x40, 0x41, 0x5, 0x10, 
    0x9, 0x2, 0x41, 0xd, 0x3, 0x2, 0x2, 0x2, 0x42, 0x45, 0x7, 0xb, 0x2, 
    0x2, 0x43, 0x46, 0x5, 0x16, 0xc, 0x2, 0x44, 0x46, 0x7, 0x23, 0x2, 0x2, 
    0x45, 0x43, 0x3, 0x2, 0x2, 0x2, 0x45, 0x44, 0x3, 0x2, 0x2, 0x2, 0x46, 
    0x47, 0x3, 0x2, 0x2, 0x2, 0x47, 0x48, 0x7, 0x22, 0x2, 0x2, 0x48, 0x49, 
    0x5, 0x10, 0x9, 0x2, 0x49, 0xf, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x50, 0x5, 
    0x12, 0xa, 0x2, 0x4b, 0x50, 0x5, 0x14, 0xb, 0x2, 0x4c, 0x50, 0x7, 0x16, 
    0x2, 0x2, 0x4d, 0x50, 0x7, 0x17, 0x2, 0x2, 0x4e, 0x50, 0x7, 0x18, 0x2, 
    0x2, 0x4f, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x4b, 0x3, 0x2, 0x2, 0x2, 
    0x4f, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4f, 
    0x4e, 0x3, 0x2, 0x2, 0x2, 0x50, 0x11, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 
    0x9, 0x2, 0x2, 0x2, 0x52, 0x13, 0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 0x9, 
    0x3, 0x2, 0x2, 0x54, 0x15, 0x3, 0x2, 0x2, 0x2, 0x55, 0x56, 0x9, 0x4, 
    0x2, 0x2, 0x56, 0x17, 0x3, 0x2, 0x2, 0x2, 0x9, 0x1c, 0x27, 0x31, 0x38, 
    0x3d, 0x45, 0x4f, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

CoriumParser::Initializer CoriumParser::_init;
