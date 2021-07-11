
// Generated from Corium.g4 by ANTLR 4.9.2


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
    setState(42);
    moduleDeclaration();
    setState(46);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CoriumParser::FUN)
      | (1ULL << CoriumParser::NATIVE)
      | (1ULL << CoriumParser::CONST))) != 0) || _la == CoriumParser::SPACE) {
      setState(43);
      compilationUnitStatement();
      setState(48);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(49);
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
    setState(51);
    match(CoriumParser::MODULE);
    setState(52);
    qualifiedName();
   
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

CoriumParser::NativeFunctionDeclarationContext* CoriumParser::CompilationUnitStatementContext::nativeFunctionDeclaration() {
  return getRuleContext<CoriumParser::NativeFunctionDeclarationContext>(0);
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
    setState(58);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CoriumParser::FUN: {
        enterOuterAlt(_localctx, 1);
        setState(54);
        functionDeclaration();
        break;
      }

      case CoriumParser::NATIVE: {
        enterOuterAlt(_localctx, 2);
        setState(55);
        nativeFunctionDeclaration();
        break;
      }

      case CoriumParser::CONST: {
        enterOuterAlt(_localctx, 3);
        setState(56);
        constVariableDeclaration();
        break;
      }

      case CoriumParser::SPACE: {
        enterOuterAlt(_localctx, 4);
        setState(57);
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

//----------------- NativeFunctionDeclarationContext ------------------------------------------------------------------

CoriumParser::NativeFunctionDeclarationContext::NativeFunctionDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::NativeFunctionDeclarationContext::NATIVE() {
  return getToken(CoriumParser::NATIVE, 0);
}

CoriumParser::FunctionHeaderContext* CoriumParser::NativeFunctionDeclarationContext::functionHeader() {
  return getRuleContext<CoriumParser::FunctionHeaderContext>(0);
}


size_t CoriumParser::NativeFunctionDeclarationContext::getRuleIndex() const {
  return CoriumParser::RuleNativeFunctionDeclaration;
}

void CoriumParser::NativeFunctionDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNativeFunctionDeclaration(this);
}

void CoriumParser::NativeFunctionDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNativeFunctionDeclaration(this);
}

CoriumParser::NativeFunctionDeclarationContext* CoriumParser::nativeFunctionDeclaration() {
  NativeFunctionDeclarationContext *_localctx = _tracker.createInstance<NativeFunctionDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 6, CoriumParser::RuleNativeFunctionDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(60);
    match(CoriumParser::NATIVE);
    setState(61);
    functionHeader();
   
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

CoriumParser::FunctionHeaderContext* CoriumParser::FunctionDeclarationContext::functionHeader() {
  return getRuleContext<CoriumParser::FunctionHeaderContext>(0);
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
  enterRule(_localctx, 8, CoriumParser::RuleFunctionDeclaration);
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
    functionHeader();
    setState(64);
    match(CoriumParser::LBRACE);
    setState(68);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CoriumParser::LET)
      | (1ULL << CoriumParser::CONST)
      | (1ULL << CoriumParser::RETURN))) != 0)) {
      setState(65);
      functionBlockStatement();
      setState(70);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(71);
    match(CoriumParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionCallContext ------------------------------------------------------------------

CoriumParser::FunctionCallContext::FunctionCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::QualifiedNameContext* CoriumParser::FunctionCallContext::qualifiedName() {
  return getRuleContext<CoriumParser::QualifiedNameContext>(0);
}

tree::TerminalNode* CoriumParser::FunctionCallContext::LPAREN() {
  return getToken(CoriumParser::LPAREN, 0);
}

tree::TerminalNode* CoriumParser::FunctionCallContext::RPAREN() {
  return getToken(CoriumParser::RPAREN, 0);
}

CoriumParser::ExpressionListContext* CoriumParser::FunctionCallContext::expressionList() {
  return getRuleContext<CoriumParser::ExpressionListContext>(0);
}


size_t CoriumParser::FunctionCallContext::getRuleIndex() const {
  return CoriumParser::RuleFunctionCall;
}

void CoriumParser::FunctionCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCall(this);
}

void CoriumParser::FunctionCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCall(this);
}

CoriumParser::FunctionCallContext* CoriumParser::functionCall() {
  FunctionCallContext *_localctx = _tracker.createInstance<FunctionCallContext>(_ctx, getState());
  enterRule(_localctx, 10, CoriumParser::RuleFunctionCall);
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
    setState(73);
    qualifiedName();
    setState(74);
    match(CoriumParser::LPAREN);
    setState(76);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 15) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 15)) & ((1ULL << (CoriumParser::INT_LITERAL_DEC - 15))
      | (1ULL << (CoriumParser::INT_LITERAL_HEX - 15))
      | (1ULL << (CoriumParser::INT_LITERAL_OCT - 15))
      | (1ULL << (CoriumParser::INT_LITERAL_BIN - 15))
      | (1ULL << (CoriumParser::FLOAT_LITERAL_DEC - 15))
      | (1ULL << (CoriumParser::FLOAT_LITERAL_HEX - 15))
      | (1ULL << (CoriumParser::BOOL_LITERAL - 15))
      | (1ULL << (CoriumParser::CHAR_LITERAL - 15))
      | (1ULL << (CoriumParser::STRING_LITERAL - 15))
      | (1ULL << (CoriumParser::IDENT - 15)))) != 0)) {
      setState(75);
      expressionList();
    }
    setState(78);
    match(CoriumParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionHeaderContext ------------------------------------------------------------------

CoriumParser::FunctionHeaderContext::FunctionHeaderContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::FunctionHeaderContext::FUN() {
  return getToken(CoriumParser::FUN, 0);
}

CoriumParser::QualifiedNameContext* CoriumParser::FunctionHeaderContext::qualifiedName() {
  return getRuleContext<CoriumParser::QualifiedNameContext>(0);
}

tree::TerminalNode* CoriumParser::FunctionHeaderContext::LPAREN() {
  return getToken(CoriumParser::LPAREN, 0);
}

tree::TerminalNode* CoriumParser::FunctionHeaderContext::RPAREN() {
  return getToken(CoriumParser::RPAREN, 0);
}

CoriumParser::ParameterListContext* CoriumParser::FunctionHeaderContext::parameterList() {
  return getRuleContext<CoriumParser::ParameterListContext>(0);
}

CoriumParser::TypeNameContext* CoriumParser::FunctionHeaderContext::typeName() {
  return getRuleContext<CoriumParser::TypeNameContext>(0);
}


size_t CoriumParser::FunctionHeaderContext::getRuleIndex() const {
  return CoriumParser::RuleFunctionHeader;
}

void CoriumParser::FunctionHeaderContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionHeader(this);
}

void CoriumParser::FunctionHeaderContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionHeader(this);
}

CoriumParser::FunctionHeaderContext* CoriumParser::functionHeader() {
  FunctionHeaderContext *_localctx = _tracker.createInstance<FunctionHeaderContext>(_ctx, getState());
  enterRule(_localctx, 12, CoriumParser::RuleFunctionHeader);
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
    match(CoriumParser::FUN);
    setState(81);
    qualifiedName();
    setState(82);
    match(CoriumParser::LPAREN);
    setState(84);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CoriumParser::IDENT) {
      setState(83);
      parameterList();
    }
    setState(86);
    match(CoriumParser::RPAREN);
    setState(88);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CoriumParser::BOOL)
      | (1ULL << CoriumParser::CHAR)
      | (1ULL << CoriumParser::FLOAT)
      | (1ULL << CoriumParser::INT)
      | (1ULL << CoriumParser::STRING))) != 0) || _la == CoriumParser::IDENT) {
      setState(87);
      typeName();
    }
   
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

CoriumParser::ReturnStatementContext* CoriumParser::FunctionBlockStatementContext::returnStatement() {
  return getRuleContext<CoriumParser::ReturnStatementContext>(0);
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
  enterRule(_localctx, 14, CoriumParser::RuleFunctionBlockStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(93);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CoriumParser::LET: {
        enterOuterAlt(_localctx, 1);
        setState(90);
        localVariableDeclaration();
        break;
      }

      case CoriumParser::CONST: {
        enterOuterAlt(_localctx, 2);
        setState(91);
        constVariableDeclaration();
        break;
      }

      case CoriumParser::RETURN: {
        enterOuterAlt(_localctx, 3);
        setState(92);
        returnStatement();
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

//----------------- ReturnStatementContext ------------------------------------------------------------------

CoriumParser::ReturnStatementContext::ReturnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::ReturnStatementContext::RETURN() {
  return getToken(CoriumParser::RETURN, 0);
}

CoriumParser::ExpressionContext* CoriumParser::ReturnStatementContext::expression() {
  return getRuleContext<CoriumParser::ExpressionContext>(0);
}


size_t CoriumParser::ReturnStatementContext::getRuleIndex() const {
  return CoriumParser::RuleReturnStatement;
}

void CoriumParser::ReturnStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStatement(this);
}

void CoriumParser::ReturnStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStatement(this);
}

CoriumParser::ReturnStatementContext* CoriumParser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 16, CoriumParser::RuleReturnStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(95);
    match(CoriumParser::RETURN);
    setState(96);
    expression(0);
   
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

CoriumParser::TypeNameContext* CoriumParser::LocalVariableDeclarationContext::typeName() {
  return getRuleContext<CoriumParser::TypeNameContext>(0);
}

tree::TerminalNode* CoriumParser::LocalVariableDeclarationContext::ASSIGN() {
  return getToken(CoriumParser::ASSIGN, 0);
}

CoriumParser::ExpressionContext* CoriumParser::LocalVariableDeclarationContext::expression() {
  return getRuleContext<CoriumParser::ExpressionContext>(0);
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
  enterRule(_localctx, 18, CoriumParser::RuleLocalVariableDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(98);
    match(CoriumParser::LET);
    setState(99);
    typeName();
    setState(100);
    match(CoriumParser::ASSIGN);
    setState(101);
    expression(0);
   
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

CoriumParser::TypeNameContext* CoriumParser::ConstVariableDeclarationContext::typeName() {
  return getRuleContext<CoriumParser::TypeNameContext>(0);
}

tree::TerminalNode* CoriumParser::ConstVariableDeclarationContext::ASSIGN() {
  return getToken(CoriumParser::ASSIGN, 0);
}

CoriumParser::ExpressionContext* CoriumParser::ConstVariableDeclarationContext::expression() {
  return getRuleContext<CoriumParser::ExpressionContext>(0);
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
  enterRule(_localctx, 20, CoriumParser::RuleConstVariableDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(103);
    match(CoriumParser::CONST);
    setState(104);
    typeName();
    setState(105);
    match(CoriumParser::ASSIGN);
    setState(106);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterListContext ------------------------------------------------------------------

CoriumParser::ParameterListContext::ParameterListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CoriumParser::ParameterContext *> CoriumParser::ParameterListContext::parameter() {
  return getRuleContexts<CoriumParser::ParameterContext>();
}

CoriumParser::ParameterContext* CoriumParser::ParameterListContext::parameter(size_t i) {
  return getRuleContext<CoriumParser::ParameterContext>(i);
}

std::vector<tree::TerminalNode *> CoriumParser::ParameterListContext::COMMA() {
  return getTokens(CoriumParser::COMMA);
}

tree::TerminalNode* CoriumParser::ParameterListContext::COMMA(size_t i) {
  return getToken(CoriumParser::COMMA, i);
}


size_t CoriumParser::ParameterListContext::getRuleIndex() const {
  return CoriumParser::RuleParameterList;
}

void CoriumParser::ParameterListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterList(this);
}

void CoriumParser::ParameterListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterList(this);
}

CoriumParser::ParameterListContext* CoriumParser::parameterList() {
  ParameterListContext *_localctx = _tracker.createInstance<ParameterListContext>(_ctx, getState());
  enterRule(_localctx, 22, CoriumParser::RuleParameterList);
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
    setState(108);
    parameter();
    setState(113);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CoriumParser::COMMA) {
      setState(109);
      match(CoriumParser::COMMA);
      setState(110);
      parameter();
      setState(115);
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

//----------------- ParameterContext ------------------------------------------------------------------

CoriumParser::ParameterContext::ParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::ParameterContext::IDENT() {
  return getToken(CoriumParser::IDENT, 0);
}

CoriumParser::TypeNameContext* CoriumParser::ParameterContext::typeName() {
  return getRuleContext<CoriumParser::TypeNameContext>(0);
}


size_t CoriumParser::ParameterContext::getRuleIndex() const {
  return CoriumParser::RuleParameter;
}

void CoriumParser::ParameterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter(this);
}

void CoriumParser::ParameterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter(this);
}

CoriumParser::ParameterContext* CoriumParser::parameter() {
  ParameterContext *_localctx = _tracker.createInstance<ParameterContext>(_ctx, getState());
  enterRule(_localctx, 24, CoriumParser::RuleParameter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(116);
    match(CoriumParser::IDENT);
    setState(117);
    typeName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeNameContext ------------------------------------------------------------------

CoriumParser::TypeNameContext::TypeNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::BuiltinTypeContext* CoriumParser::TypeNameContext::builtinType() {
  return getRuleContext<CoriumParser::BuiltinTypeContext>(0);
}

CoriumParser::QualifiedNameContext* CoriumParser::TypeNameContext::qualifiedName() {
  return getRuleContext<CoriumParser::QualifiedNameContext>(0);
}


size_t CoriumParser::TypeNameContext::getRuleIndex() const {
  return CoriumParser::RuleTypeName;
}

void CoriumParser::TypeNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeName(this);
}

void CoriumParser::TypeNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeName(this);
}

CoriumParser::TypeNameContext* CoriumParser::typeName() {
  TypeNameContext *_localctx = _tracker.createInstance<TypeNameContext>(_ctx, getState());
  enterRule(_localctx, 26, CoriumParser::RuleTypeName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(121);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CoriumParser::BOOL:
      case CoriumParser::CHAR:
      case CoriumParser::FLOAT:
      case CoriumParser::INT:
      case CoriumParser::STRING: {
        enterOuterAlt(_localctx, 1);
        setState(119);
        builtinType();
        break;
      }

      case CoriumParser::IDENT: {
        enterOuterAlt(_localctx, 2);
        setState(120);
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
  enterRule(_localctx, 28, CoriumParser::RuleBuiltinType);
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
    setState(123);
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

CoriumParser::QualifiedNameContext* CoriumParser::qualifiedName() {
  QualifiedNameContext *_localctx = _tracker.createInstance<QualifiedNameContext>(_ctx, getState());
  enterRule(_localctx, 30, CoriumParser::RuleQualifiedName);
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
    setState(125);
    match(CoriumParser::IDENT);
    setState(130);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CoriumParser::IDENT) {
      setState(126);
      match(CoriumParser::IDENT);
      setState(127);
      match(CoriumParser::DOT);
      setState(132);
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

//----------------- ExpressionListContext ------------------------------------------------------------------

CoriumParser::ExpressionListContext::ExpressionListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CoriumParser::ExpressionContext *> CoriumParser::ExpressionListContext::expression() {
  return getRuleContexts<CoriumParser::ExpressionContext>();
}

CoriumParser::ExpressionContext* CoriumParser::ExpressionListContext::expression(size_t i) {
  return getRuleContext<CoriumParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> CoriumParser::ExpressionListContext::COMMA() {
  return getTokens(CoriumParser::COMMA);
}

tree::TerminalNode* CoriumParser::ExpressionListContext::COMMA(size_t i) {
  return getToken(CoriumParser::COMMA, i);
}


size_t CoriumParser::ExpressionListContext::getRuleIndex() const {
  return CoriumParser::RuleExpressionList;
}

void CoriumParser::ExpressionListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionList(this);
}

void CoriumParser::ExpressionListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionList(this);
}

CoriumParser::ExpressionListContext* CoriumParser::expressionList() {
  ExpressionListContext *_localctx = _tracker.createInstance<ExpressionListContext>(_ctx, getState());
  enterRule(_localctx, 32, CoriumParser::RuleExpressionList);
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
    setState(133);
    expression(0);
    setState(138);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CoriumParser::COMMA) {
      setState(134);
      match(CoriumParser::COMMA);
      setState(135);
      expression(0);
      setState(140);
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

//----------------- ExpressionContext ------------------------------------------------------------------

CoriumParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::ExpressionContext::IDENT() {
  return getToken(CoriumParser::IDENT, 0);
}

CoriumParser::LiteralContext* CoriumParser::ExpressionContext::literal() {
  return getRuleContext<CoriumParser::LiteralContext>(0);
}

CoriumParser::FunctionCallContext* CoriumParser::ExpressionContext::functionCall() {
  return getRuleContext<CoriumParser::FunctionCallContext>(0);
}

std::vector<CoriumParser::ExpressionContext *> CoriumParser::ExpressionContext::expression() {
  return getRuleContexts<CoriumParser::ExpressionContext>();
}

CoriumParser::ExpressionContext* CoriumParser::ExpressionContext::expression(size_t i) {
  return getRuleContext<CoriumParser::ExpressionContext>(i);
}

tree::TerminalNode* CoriumParser::ExpressionContext::PLUS() {
  return getToken(CoriumParser::PLUS, 0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::MINUS() {
  return getToken(CoriumParser::MINUS, 0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::MULTIPLY() {
  return getToken(CoriumParser::MULTIPLY, 0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::DIVIDE() {
  return getToken(CoriumParser::DIVIDE, 0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::MODULO() {
  return getToken(CoriumParser::MODULO, 0);
}


size_t CoriumParser::ExpressionContext::getRuleIndex() const {
  return CoriumParser::RuleExpression;
}

void CoriumParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void CoriumParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


CoriumParser::ExpressionContext* CoriumParser::expression() {
   return expression(0);
}

CoriumParser::ExpressionContext* CoriumParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CoriumParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  CoriumParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 34;
  enterRecursionRule(_localctx, 34, CoriumParser::RuleExpression, precedence);

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
    setState(145);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      setState(142);
      match(CoriumParser::IDENT);
      break;
    }

    case 2: {
      setState(143);
      literal();
      break;
    }

    case 3: {
      setState(144);
      functionCall();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(152);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpression);
        setState(147);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(148);
        dynamic_cast<ExpressionContext *>(_localctx)->bop = _input->LT(1);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CoriumParser::PLUS)
          | (1ULL << CoriumParser::MINUS)
          | (1ULL << CoriumParser::MULTIPLY)
          | (1ULL << CoriumParser::DIVIDE)
          | (1ULL << CoriumParser::MODULO))) != 0))) {
          dynamic_cast<ExpressionContext *>(_localctx)->bop = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(149);
        expression(2); 
      }
      setState(154);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
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

CoriumParser::LiteralContext* CoriumParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 36, CoriumParser::RuleLiteral);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(160);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CoriumParser::INT_LITERAL_DEC:
      case CoriumParser::INT_LITERAL_HEX:
      case CoriumParser::INT_LITERAL_OCT:
      case CoriumParser::INT_LITERAL_BIN: {
        enterOuterAlt(_localctx, 1);
        setState(155);
        intLiteral();
        break;
      }

      case CoriumParser::FLOAT_LITERAL_DEC:
      case CoriumParser::FLOAT_LITERAL_HEX: {
        enterOuterAlt(_localctx, 2);
        setState(156);
        floatLiteral();
        break;
      }

      case CoriumParser::BOOL_LITERAL: {
        enterOuterAlt(_localctx, 3);
        setState(157);
        match(CoriumParser::BOOL_LITERAL);
        break;
      }

      case CoriumParser::CHAR_LITERAL: {
        enterOuterAlt(_localctx, 4);
        setState(158);
        match(CoriumParser::CHAR_LITERAL);
        break;
      }

      case CoriumParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 5);
        setState(159);
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
  enterRule(_localctx, 38, CoriumParser::RuleIntLiteral);
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
    setState(162);
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
  enterRule(_localctx, 40, CoriumParser::RuleFloatLiteral);
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
    setState(164);
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
    case 17: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool CoriumParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

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
  "compilationUnit", "moduleDeclaration", "compilationUnitStatement", "nativeFunctionDeclaration", 
  "functionDeclaration", "functionCall", "functionHeader", "functionBlockStatement", 
  "returnStatement", "localVariableDeclaration", "constVariableDeclaration", 
  "parameterList", "parameter", "typeName", "builtinType", "qualifiedName", 
  "expressionList", "expression", "literal", "intLiteral", "floatLiteral"
};

std::vector<std::string> CoriumParser::_literalNames = {
  "", "'bool'", "'char'", "'float'", "'fun'", "'int'", "'string'", "'let'", 
  "'native'", "'const'", "'module'", "'class'", "'struct'", "'static'", 
  "'return'", "", "", "", "", "", "", "", "", "", "'('", "')'", "'{'", "'}'", 
  "'['", "']'", "';'", "','", "'.'", "'='", "'+'", "", "'-'", "", "'*'", 
  "", "'/'", "", "'%'", "", "'&'", "", "'|'", "", "'^'", "", "'~'", "'<<'", 
  "", "'>>'", "", "'<<<'", "", "'>>>'", "", "'++'", "'--'", "'!'", "'&&'", 
  "'||'", "'^^'", "'=='", "'!='", "'<'", "'<='", "'>'", "'>='"
};

std::vector<std::string> CoriumParser::_symbolicNames = {
  "", "BOOL", "CHAR", "FLOAT", "FUN", "INT", "STRING", "LET", "NATIVE", 
  "CONST", "MODULE", "CLASS", "STRUCT", "STATIC", "RETURN", "INT_LITERAL_DEC", 
  "INT_LITERAL_HEX", "INT_LITERAL_OCT", "INT_LITERAL_BIN", "FLOAT_LITERAL_DEC", 
  "FLOAT_LITERAL_HEX", "BOOL_LITERAL", "CHAR_LITERAL", "STRING_LITERAL", 
  "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACK", "RBRACK", "SEMI", "COMMA", 
  "DOT", "ASSIGN", "PLUS", "PLUS_ASSIGN", "MINUS", "MINUS_ASSIGN", "MULTIPLY", 
  "MULTIPLY_ASSIGN", "DIVIDE", "DIVIDE_ASSIGN", "MODULO", "MODULO_ASSIGN", 
  "BIT_AND", "BIT_AND_ASSIGN", "BIT_OR", "BIT_OR_ASSIGN", "BIT_XOR", "BIT_XOR_ASSIGN", 
  "BIT_NOT", "BIT_SHL", "BIT_SHL_ASSIGN", "BIT_SHR", "BIT_SHR_ASSIGN", "BIT_ROL", 
  "BIT_ROL_ASSIGN", "BIT_ROR", "BIT_ROR_ASSIGN", "INCREMENT", "DECREMENT", 
  "LOGICAL_NOT", "LOGICAL_AND", "LOGICAL_OR", "LOGICAL_XOR", "EQUALS", "NOT_EQUALS", 
  "LESS", "LESS_EQUALS", "GREATER", "GREATER_EQUALS", "IDENT", "SPACE", 
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
       0x3, 0x4c, 0xa9, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 
       0xe, 0x9, 0xe, 0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 
       0x9, 0x11, 0x4, 0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 
       0x9, 0x14, 0x4, 0x15, 0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x3, 0x2, 
       0x3, 0x2, 0x7, 0x2, 0x2f, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x32, 0xb, 
       0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 
       0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x3d, 0xa, 0x4, 0x3, 0x5, 
       0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x45, 
       0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x48, 0xb, 0x6, 0x3, 0x6, 0x3, 0x6, 
       0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x4f, 0xa, 0x7, 0x3, 0x7, 
       0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x57, 
       0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x5b, 0xa, 0x8, 0x3, 0x9, 
       0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x60, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 
       0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
       0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 
       0x3, 0xd, 0x7, 0xd, 0x72, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x75, 0xb, 
       0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 
       0x7c, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 
       0x11, 0x7, 0x11, 0x83, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0x86, 0xb, 
       0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x7, 0x12, 0x8b, 0xa, 0x12, 
       0xc, 0x12, 0xe, 0x12, 0x8e, 0xb, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 
       0x13, 0x3, 0x13, 0x5, 0x13, 0x94, 0xa, 0x13, 0x3, 0x13, 0x3, 0x13, 
       0x3, 0x13, 0x7, 0x13, 0x99, 0xa, 0x13, 0xc, 0x13, 0xe, 0x13, 0x9c, 
       0xb, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
       0x5, 0x14, 0xa3, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 
       0x16, 0x3, 0x16, 0x2, 0x3, 0x24, 0x17, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 
       0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 
       0x24, 0x26, 0x28, 0x2a, 0x2, 0x6, 0x4, 0x2, 0x3, 0x5, 0x7, 0x8, 0x7, 
       0x2, 0x24, 0x24, 0x26, 0x26, 0x28, 0x28, 0x2a, 0x2a, 0x2c, 0x2c, 
       0x3, 0x2, 0x11, 0x14, 0x3, 0x2, 0x15, 0x16, 0x2, 0xa8, 0x2, 0x2c, 
       0x3, 0x2, 0x2, 0x2, 0x4, 0x35, 0x3, 0x2, 0x2, 0x2, 0x6, 0x3c, 0x3, 
       0x2, 0x2, 0x2, 0x8, 0x3e, 0x3, 0x2, 0x2, 0x2, 0xa, 0x41, 0x3, 0x2, 
       0x2, 0x2, 0xc, 0x4b, 0x3, 0x2, 0x2, 0x2, 0xe, 0x52, 0x3, 0x2, 0x2, 
       0x2, 0x10, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x12, 0x61, 0x3, 0x2, 0x2, 0x2, 
       0x14, 0x64, 0x3, 0x2, 0x2, 0x2, 0x16, 0x69, 0x3, 0x2, 0x2, 0x2, 0x18, 
       0x6e, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x76, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x7b, 
       0x3, 0x2, 0x2, 0x2, 0x1e, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x20, 0x7f, 0x3, 
       0x2, 0x2, 0x2, 0x22, 0x87, 0x3, 0x2, 0x2, 0x2, 0x24, 0x93, 0x3, 0x2, 
       0x2, 0x2, 0x26, 0xa2, 0x3, 0x2, 0x2, 0x2, 0x28, 0xa4, 0x3, 0x2, 0x2, 
       0x2, 0x2a, 0xa6, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x30, 0x5, 0x4, 0x3, 0x2, 
       0x2d, 0x2f, 0x5, 0x6, 0x4, 0x2, 0x2e, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x2f, 
       0x32, 0x3, 0x2, 0x2, 0x2, 0x30, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x30, 0x31, 
       0x3, 0x2, 0x2, 0x2, 0x31, 0x33, 0x3, 0x2, 0x2, 0x2, 0x32, 0x30, 0x3, 
       0x2, 0x2, 0x2, 0x33, 0x34, 0x7, 0x2, 0x2, 0x3, 0x34, 0x3, 0x3, 0x2, 
       0x2, 0x2, 0x35, 0x36, 0x7, 0xc, 0x2, 0x2, 0x36, 0x37, 0x5, 0x20, 
       0x11, 0x2, 0x37, 0x5, 0x3, 0x2, 0x2, 0x2, 0x38, 0x3d, 0x5, 0xa, 0x6, 
       0x2, 0x39, 0x3d, 0x5, 0x8, 0x5, 0x2, 0x3a, 0x3d, 0x5, 0x16, 0xc, 
       0x2, 0x3b, 0x3d, 0x7, 0x4a, 0x2, 0x2, 0x3c, 0x38, 0x3, 0x2, 0x2, 
       0x2, 0x3c, 0x39, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3a, 0x3, 0x2, 0x2, 0x2, 
       0x3c, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x7, 0x3, 0x2, 0x2, 0x2, 0x3e, 
       0x3f, 0x7, 0xa, 0x2, 0x2, 0x3f, 0x40, 0x5, 0xe, 0x8, 0x2, 0x40, 0x9, 
       0x3, 0x2, 0x2, 0x2, 0x41, 0x42, 0x5, 0xe, 0x8, 0x2, 0x42, 0x46, 0x7, 
       0x1c, 0x2, 0x2, 0x43, 0x45, 0x5, 0x10, 0x9, 0x2, 0x44, 0x43, 0x3, 
       0x2, 0x2, 0x2, 0x45, 0x48, 0x3, 0x2, 0x2, 0x2, 0x46, 0x44, 0x3, 0x2, 
       0x2, 0x2, 0x46, 0x47, 0x3, 0x2, 0x2, 0x2, 0x47, 0x49, 0x3, 0x2, 0x2, 
       0x2, 0x48, 0x46, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4a, 0x7, 0x1d, 0x2, 
       0x2, 0x4a, 0xb, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4c, 0x5, 0x20, 0x11, 
       0x2, 0x4c, 0x4e, 0x7, 0x1a, 0x2, 0x2, 0x4d, 0x4f, 0x5, 0x22, 0x12, 
       0x2, 0x4e, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4f, 0x3, 0x2, 0x2, 0x2, 
       0x4f, 0x50, 0x3, 0x2, 0x2, 0x2, 0x50, 0x51, 0x7, 0x1b, 0x2, 0x2, 
       0x51, 0xd, 0x3, 0x2, 0x2, 0x2, 0x52, 0x53, 0x7, 0x6, 0x2, 0x2, 0x53, 
       0x54, 0x5, 0x20, 0x11, 0x2, 0x54, 0x56, 0x7, 0x1a, 0x2, 0x2, 0x55, 
       0x57, 0x5, 0x18, 0xd, 0x2, 0x56, 0x55, 0x3, 0x2, 0x2, 0x2, 0x56, 
       0x57, 0x3, 0x2, 0x2, 0x2, 0x57, 0x58, 0x3, 0x2, 0x2, 0x2, 0x58, 0x5a, 
       0x7, 0x1b, 0x2, 0x2, 0x59, 0x5b, 0x5, 0x1c, 0xf, 0x2, 0x5a, 0x59, 
       0x3, 0x2, 0x2, 0x2, 0x5a, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5b, 0xf, 0x3, 
       0x2, 0x2, 0x2, 0x5c, 0x60, 0x5, 0x14, 0xb, 0x2, 0x5d, 0x60, 0x5, 
       0x16, 0xc, 0x2, 0x5e, 0x60, 0x5, 0x12, 0xa, 0x2, 0x5f, 0x5c, 0x3, 
       0x2, 0x2, 0x2, 0x5f, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x5e, 0x3, 0x2, 
       0x2, 0x2, 0x60, 0x11, 0x3, 0x2, 0x2, 0x2, 0x61, 0x62, 0x7, 0x10, 
       0x2, 0x2, 0x62, 0x63, 0x5, 0x24, 0x13, 0x2, 0x63, 0x13, 0x3, 0x2, 
       0x2, 0x2, 0x64, 0x65, 0x7, 0x9, 0x2, 0x2, 0x65, 0x66, 0x5, 0x1c, 
       0xf, 0x2, 0x66, 0x67, 0x7, 0x23, 0x2, 0x2, 0x67, 0x68, 0x5, 0x24, 
       0x13, 0x2, 0x68, 0x15, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x7, 0xb, 
       0x2, 0x2, 0x6a, 0x6b, 0x5, 0x1c, 0xf, 0x2, 0x6b, 0x6c, 0x7, 0x23, 
       0x2, 0x2, 0x6c, 0x6d, 0x5, 0x24, 0x13, 0x2, 0x6d, 0x17, 0x3, 0x2, 
       0x2, 0x2, 0x6e, 0x73, 0x5, 0x1a, 0xe, 0x2, 0x6f, 0x70, 0x7, 0x21, 
       0x2, 0x2, 0x70, 0x72, 0x5, 0x1a, 0xe, 0x2, 0x71, 0x6f, 0x3, 0x2, 
       0x2, 0x2, 0x72, 0x75, 0x3, 0x2, 0x2, 0x2, 0x73, 0x71, 0x3, 0x2, 0x2, 
       0x2, 0x73, 0x74, 0x3, 0x2, 0x2, 0x2, 0x74, 0x19, 0x3, 0x2, 0x2, 0x2, 
       0x75, 0x73, 0x3, 0x2, 0x2, 0x2, 0x76, 0x77, 0x7, 0x49, 0x2, 0x2, 
       0x77, 0x78, 0x5, 0x1c, 0xf, 0x2, 0x78, 0x1b, 0x3, 0x2, 0x2, 0x2, 
       0x79, 0x7c, 0x5, 0x1e, 0x10, 0x2, 0x7a, 0x7c, 0x5, 0x20, 0x11, 0x2, 
       0x7b, 0x79, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x7c, 
       0x1d, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7e, 0x9, 0x2, 0x2, 0x2, 0x7e, 0x1f, 
       0x3, 0x2, 0x2, 0x2, 0x7f, 0x84, 0x7, 0x49, 0x2, 0x2, 0x80, 0x81, 
       0x7, 0x49, 0x2, 0x2, 0x81, 0x83, 0x7, 0x22, 0x2, 0x2, 0x82, 0x80, 
       0x3, 0x2, 0x2, 0x2, 0x83, 0x86, 0x3, 0x2, 0x2, 0x2, 0x84, 0x82, 0x3, 
       0x2, 0x2, 0x2, 0x84, 0x85, 0x3, 0x2, 0x2, 0x2, 0x85, 0x21, 0x3, 0x2, 
       0x2, 0x2, 0x86, 0x84, 0x3, 0x2, 0x2, 0x2, 0x87, 0x8c, 0x5, 0x24, 
       0x13, 0x2, 0x88, 0x89, 0x7, 0x21, 0x2, 0x2, 0x89, 0x8b, 0x5, 0x24, 
       0x13, 0x2, 0x8a, 0x88, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8e, 0x3, 0x2, 
       0x2, 0x2, 0x8c, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8d, 0x3, 0x2, 0x2, 
       0x2, 0x8d, 0x23, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8c, 0x3, 0x2, 0x2, 0x2, 
       0x8f, 0x90, 0x8, 0x13, 0x1, 0x2, 0x90, 0x94, 0x7, 0x49, 0x2, 0x2, 
       0x91, 0x94, 0x5, 0x26, 0x14, 0x2, 0x92, 0x94, 0x5, 0xc, 0x7, 0x2, 
       0x93, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x93, 0x91, 0x3, 0x2, 0x2, 0x2, 0x93, 
       0x92, 0x3, 0x2, 0x2, 0x2, 0x94, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x95, 0x96, 
       0xc, 0x3, 0x2, 0x2, 0x96, 0x97, 0x9, 0x3, 0x2, 0x2, 0x97, 0x99, 0x5, 
       0x24, 0x13, 0x4, 0x98, 0x95, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9c, 0x3, 
       0x2, 0x2, 0x2, 0x9a, 0x98, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x9b, 0x3, 0x2, 
       0x2, 0x2, 0x9b, 0x25, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9a, 0x3, 0x2, 0x2, 
       0x2, 0x9d, 0xa3, 0x5, 0x28, 0x15, 0x2, 0x9e, 0xa3, 0x5, 0x2a, 0x16, 
       0x2, 0x9f, 0xa3, 0x7, 0x17, 0x2, 0x2, 0xa0, 0xa3, 0x7, 0x18, 0x2, 
       0x2, 0xa1, 0xa3, 0x7, 0x19, 0x2, 0x2, 0xa2, 0x9d, 0x3, 0x2, 0x2, 
       0x2, 0xa2, 0x9e, 0x3, 0x2, 0x2, 0x2, 0xa2, 0x9f, 0x3, 0x2, 0x2, 0x2, 
       0xa2, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa3, 
       0x27, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa5, 0x9, 0x4, 0x2, 0x2, 0xa5, 0x29, 
       0x3, 0x2, 0x2, 0x2, 0xa6, 0xa7, 0x9, 0x5, 0x2, 0x2, 0xa7, 0x2b, 0x3, 
       0x2, 0x2, 0x2, 0x10, 0x30, 0x3c, 0x46, 0x4e, 0x56, 0x5a, 0x5f, 0x73, 
       0x7b, 0x84, 0x8c, 0x93, 0x9a, 0xa2, 
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
