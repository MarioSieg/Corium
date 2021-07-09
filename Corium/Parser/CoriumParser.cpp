
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
    setState(32);
    moduleDeclaration();
    setState(36);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CoriumParser::FUN)
      | (1ULL << CoriumParser::NATIVE)
      | (1ULL << CoriumParser::CONST)
      | (1ULL << CoriumParser::SPACE))) != 0)) {
      setState(33);
      compilationUnitStatement();
      setState(38);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(39);
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
    setState(41);
    match(CoriumParser::MODULE);
    setState(42);
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
    setState(48);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CoriumParser::FUN: {
        enterOuterAlt(_localctx, 1);
        setState(44);
        functionDeclaration();
        break;
      }

      case CoriumParser::NATIVE: {
        enterOuterAlt(_localctx, 2);
        setState(45);
        nativeFunctionDeclaration();
        break;
      }

      case CoriumParser::CONST: {
        enterOuterAlt(_localctx, 3);
        setState(46);
        constVariableDeclaration();
        break;
      }

      case CoriumParser::SPACE: {
        enterOuterAlt(_localctx, 4);
        setState(47);
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

tree::TerminalNode* CoriumParser::NativeFunctionDeclarationContext::FUN() {
  return getToken(CoriumParser::FUN, 0);
}

tree::TerminalNode* CoriumParser::NativeFunctionDeclarationContext::IDENT() {
  return getToken(CoriumParser::IDENT, 0);
}

tree::TerminalNode* CoriumParser::NativeFunctionDeclarationContext::LPAREN() {
  return getToken(CoriumParser::LPAREN, 0);
}

tree::TerminalNode* CoriumParser::NativeFunctionDeclarationContext::RPAREN() {
  return getToken(CoriumParser::RPAREN, 0);
}

CoriumParser::ParameterListContext* CoriumParser::NativeFunctionDeclarationContext::parameterList() {
  return getRuleContext<CoriumParser::ParameterListContext>(0);
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
    setState(50);
    match(CoriumParser::NATIVE);
    setState(51);
    match(CoriumParser::FUN);
    setState(52);
    match(CoriumParser::IDENT);
    setState(53);
    match(CoriumParser::LPAREN);
    setState(55);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CoriumParser::IDENT) {
      setState(54);
      parameterList();
    }
    setState(57);
    match(CoriumParser::RPAREN);
   
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

CoriumParser::ParameterListContext* CoriumParser::FunctionDeclarationContext::parameterList() {
  return getRuleContext<CoriumParser::ParameterListContext>(0);
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
    setState(59);
    match(CoriumParser::FUN);
    setState(60);
    match(CoriumParser::IDENT);
    setState(61);
    match(CoriumParser::LPAREN);
    setState(63);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CoriumParser::IDENT) {
      setState(62);
      parameterList();
    }
    setState(65);
    match(CoriumParser::RPAREN);
    setState(66);
    match(CoriumParser::LBRACE);
    setState(70);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CoriumParser::LET

    || _la == CoriumParser::CONST) {
      setState(67);
      functionBlockStatement();
      setState(72);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(73);
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
  enterRule(_localctx, 10, CoriumParser::RuleFunctionBlockStatement);

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
      case CoriumParser::LET: {
        enterOuterAlt(_localctx, 1);
        setState(75);
        localVariableDeclaration();
        break;
      }

      case CoriumParser::CONST: {
        enterOuterAlt(_localctx, 2);
        setState(76);
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

CoriumParser::TypeNameContext* CoriumParser::LocalVariableDeclarationContext::typeName() {
  return getRuleContext<CoriumParser::TypeNameContext>(0);
}

tree::TerminalNode* CoriumParser::LocalVariableDeclarationContext::ASSIGN() {
  return getToken(CoriumParser::ASSIGN, 0);
}

CoriumParser::LiteralContext* CoriumParser::LocalVariableDeclarationContext::literal() {
  return getRuleContext<CoriumParser::LiteralContext>(0);
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
  enterRule(_localctx, 12, CoriumParser::RuleLocalVariableDeclaration);

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
    match(CoriumParser::LET);
    setState(80);
    typeName();
    setState(81);
    match(CoriumParser::ASSIGN);
    setState(82);
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

CoriumParser::TypeNameContext* CoriumParser::ConstVariableDeclarationContext::typeName() {
  return getRuleContext<CoriumParser::TypeNameContext>(0);
}

tree::TerminalNode* CoriumParser::ConstVariableDeclarationContext::ASSIGN() {
  return getToken(CoriumParser::ASSIGN, 0);
}

CoriumParser::LiteralContext* CoriumParser::ConstVariableDeclarationContext::literal() {
  return getRuleContext<CoriumParser::LiteralContext>(0);
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
  enterRule(_localctx, 14, CoriumParser::RuleConstVariableDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(84);
    match(CoriumParser::CONST);
    setState(85);
    typeName();
    setState(86);
    match(CoriumParser::ASSIGN);
    setState(87);
    literal();
   
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
  enterRule(_localctx, 16, CoriumParser::RuleParameterList);
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
    setState(89);
    parameter();
    setState(94);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CoriumParser::COMMA) {
      setState(90);
      match(CoriumParser::COMMA);
      setState(91);
      parameter();
      setState(96);
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
  enterRule(_localctx, 18, CoriumParser::RuleParameter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(97);
    match(CoriumParser::IDENT);
    setState(98);
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
  enterRule(_localctx, 20, CoriumParser::RuleTypeName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(102);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CoriumParser::BOOL:
      case CoriumParser::CHAR:
      case CoriumParser::FLOAT:
      case CoriumParser::INT:
      case CoriumParser::STRING: {
        enterOuterAlt(_localctx, 1);
        setState(100);
        builtinType();
        break;
      }

      case CoriumParser::IDENT: {
        enterOuterAlt(_localctx, 2);
        setState(101);
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
  enterRule(_localctx, 22, CoriumParser::RuleBuiltinType);
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
    setState(104);
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
  enterRule(_localctx, 24, CoriumParser::RuleQualifiedName);
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
    setState(106);
    match(CoriumParser::IDENT);
    setState(111);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CoriumParser::IDENT) {
      setState(107);
      match(CoriumParser::IDENT);
      setState(108);
      match(CoriumParser::DOT);
      setState(113);
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

CoriumParser::LiteralContext* CoriumParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 26, CoriumParser::RuleLiteral);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(119);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CoriumParser::INT_LITERAL_DEC:
      case CoriumParser::INT_LITERAL_HEX:
      case CoriumParser::INT_LITERAL_OCT:
      case CoriumParser::INT_LITERAL_BIN: {
        enterOuterAlt(_localctx, 1);
        setState(114);
        intLiteral();
        break;
      }

      case CoriumParser::FLOAT_LITERAL_DEC:
      case CoriumParser::FLOAT_LITERAL_HEX: {
        enterOuterAlt(_localctx, 2);
        setState(115);
        floatLiteral();
        break;
      }

      case CoriumParser::BOOL_LITERAL: {
        enterOuterAlt(_localctx, 3);
        setState(116);
        match(CoriumParser::BOOL_LITERAL);
        break;
      }

      case CoriumParser::CHAR_LITERAL: {
        enterOuterAlt(_localctx, 4);
        setState(117);
        match(CoriumParser::CHAR_LITERAL);
        break;
      }

      case CoriumParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 5);
        setState(118);
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
  enterRule(_localctx, 28, CoriumParser::RuleIntLiteral);
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
    setState(121);
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
  enterRule(_localctx, 30, CoriumParser::RuleFloatLiteral);
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

// Static vars and initialization.
std::vector<dfa::DFA> CoriumParser::_decisionToDFA;
atn::PredictionContextCache CoriumParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN CoriumParser::_atn;
std::vector<uint16_t> CoriumParser::_serializedATN;

std::vector<std::string> CoriumParser::_ruleNames = {
  "compilationUnit", "moduleDeclaration", "compilationUnitStatement", "nativeFunctionDeclaration", 
  "functionDeclaration", "functionBlockStatement", "localVariableDeclaration", 
  "constVariableDeclaration", "parameterList", "parameter", "typeName", 
  "builtinType", "qualifiedName", "literal", "intLiteral", "floatLiteral"
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
    0x3, 0x26, 0x80, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x3, 0x2, 
    0x3, 0x2, 0x7, 0x2, 0x25, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x28, 0xb, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x33, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x3a, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x42, 0xa, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x47, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 
    0x4a, 0xb, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x50, 
    0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x7, 0xa, 0x5f, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x62, 0xb, 0xa, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x69, 0xa, 0xc, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0x70, 0xa, 0xe, 
    0xc, 0xe, 0xe, 0xe, 0x73, 0xb, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x5, 0xf, 0x7a, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x2, 0x2, 0x12, 0x2, 0x4, 0x6, 0x8, 0xa, 
    0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x2, 
    0x5, 0x4, 0x2, 0x3, 0x5, 0x7, 0x8, 0x3, 0x2, 0x10, 0x13, 0x3, 0x2, 0x14, 
    0x15, 0x2, 0x7e, 0x2, 0x22, 0x3, 0x2, 0x2, 0x2, 0x4, 0x2b, 0x3, 0x2, 
    0x2, 0x2, 0x6, 0x32, 0x3, 0x2, 0x2, 0x2, 0x8, 0x34, 0x3, 0x2, 0x2, 0x2, 
    0xa, 0x3d, 0x3, 0x2, 0x2, 0x2, 0xc, 0x4f, 0x3, 0x2, 0x2, 0x2, 0xe, 0x51, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0x56, 0x3, 0x2, 0x2, 0x2, 0x12, 0x5b, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0x63, 0x3, 0x2, 0x2, 0x2, 0x16, 0x68, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x6c, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0x79, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x7b, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x22, 0x26, 0x5, 0x4, 0x3, 0x2, 0x23, 
    0x25, 0x5, 0x6, 0x4, 0x2, 0x24, 0x23, 0x3, 0x2, 0x2, 0x2, 0x25, 0x28, 
    0x3, 0x2, 0x2, 0x2, 0x26, 0x24, 0x3, 0x2, 0x2, 0x2, 0x26, 0x27, 0x3, 
    0x2, 0x2, 0x2, 0x27, 0x29, 0x3, 0x2, 0x2, 0x2, 0x28, 0x26, 0x3, 0x2, 
    0x2, 0x2, 0x29, 0x2a, 0x7, 0x2, 0x2, 0x3, 0x2a, 0x3, 0x3, 0x2, 0x2, 
    0x2, 0x2b, 0x2c, 0x7, 0xc, 0x2, 0x2, 0x2c, 0x2d, 0x5, 0x1a, 0xe, 0x2, 
    0x2d, 0x5, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x33, 0x5, 0xa, 0x6, 0x2, 0x2f, 
    0x33, 0x5, 0x8, 0x5, 0x2, 0x30, 0x33, 0x5, 0x10, 0x9, 0x2, 0x31, 0x33, 
    0x7, 0x24, 0x2, 0x2, 0x32, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x32, 0x2f, 0x3, 
    0x2, 0x2, 0x2, 0x32, 0x30, 0x3, 0x2, 0x2, 0x2, 0x32, 0x31, 0x3, 0x2, 
    0x2, 0x2, 0x33, 0x7, 0x3, 0x2, 0x2, 0x2, 0x34, 0x35, 0x7, 0xa, 0x2, 
    0x2, 0x35, 0x36, 0x7, 0x6, 0x2, 0x2, 0x36, 0x37, 0x7, 0x23, 0x2, 0x2, 
    0x37, 0x39, 0x7, 0x19, 0x2, 0x2, 0x38, 0x3a, 0x5, 0x12, 0xa, 0x2, 0x39, 
    0x38, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3b, 
    0x3, 0x2, 0x2, 0x2, 0x3b, 0x3c, 0x7, 0x1a, 0x2, 0x2, 0x3c, 0x9, 0x3, 
    0x2, 0x2, 0x2, 0x3d, 0x3e, 0x7, 0x6, 0x2, 0x2, 0x3e, 0x3f, 0x7, 0x23, 
    0x2, 0x2, 0x3f, 0x41, 0x7, 0x19, 0x2, 0x2, 0x40, 0x42, 0x5, 0x12, 0xa, 
    0x2, 0x41, 0x40, 0x3, 0x2, 0x2, 0x2, 0x41, 0x42, 0x3, 0x2, 0x2, 0x2, 
    0x42, 0x43, 0x3, 0x2, 0x2, 0x2, 0x43, 0x44, 0x7, 0x1a, 0x2, 0x2, 0x44, 
    0x48, 0x7, 0x1b, 0x2, 0x2, 0x45, 0x47, 0x5, 0xc, 0x7, 0x2, 0x46, 0x45, 
    0x3, 0x2, 0x2, 0x2, 0x47, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x48, 0x46, 0x3, 
    0x2, 0x2, 0x2, 0x48, 0x49, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4b, 0x3, 0x2, 
    0x2, 0x2, 0x4a, 0x48, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4c, 0x7, 0x1c, 0x2, 
    0x2, 0x4c, 0xb, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x50, 0x5, 0xe, 0x8, 0x2, 
    0x4e, 0x50, 0x5, 0x10, 0x9, 0x2, 0x4f, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4f, 
    0x4e, 0x3, 0x2, 0x2, 0x2, 0x50, 0xd, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 
    0x7, 0x9, 0x2, 0x2, 0x52, 0x53, 0x5, 0x16, 0xc, 0x2, 0x53, 0x54, 0x7, 
    0x22, 0x2, 0x2, 0x54, 0x55, 0x5, 0x1c, 0xf, 0x2, 0x55, 0xf, 0x3, 0x2, 
    0x2, 0x2, 0x56, 0x57, 0x7, 0xb, 0x2, 0x2, 0x57, 0x58, 0x5, 0x16, 0xc, 
    0x2, 0x58, 0x59, 0x7, 0x22, 0x2, 0x2, 0x59, 0x5a, 0x5, 0x1c, 0xf, 0x2, 
    0x5a, 0x11, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x60, 0x5, 0x14, 0xb, 0x2, 0x5c, 
    0x5d, 0x7, 0x20, 0x2, 0x2, 0x5d, 0x5f, 0x5, 0x14, 0xb, 0x2, 0x5e, 0x5c, 
    0x3, 0x2, 0x2, 0x2, 0x5f, 0x62, 0x3, 0x2, 0x2, 0x2, 0x60, 0x5e, 0x3, 
    0x2, 0x2, 0x2, 0x60, 0x61, 0x3, 0x2, 0x2, 0x2, 0x61, 0x13, 0x3, 0x2, 
    0x2, 0x2, 0x62, 0x60, 0x3, 0x2, 0x2, 0x2, 0x63, 0x64, 0x7, 0x23, 0x2, 
    0x2, 0x64, 0x65, 0x5, 0x16, 0xc, 0x2, 0x65, 0x15, 0x3, 0x2, 0x2, 0x2, 
    0x66, 0x69, 0x5, 0x18, 0xd, 0x2, 0x67, 0x69, 0x5, 0x1a, 0xe, 0x2, 0x68, 
    0x66, 0x3, 0x2, 0x2, 0x2, 0x68, 0x67, 0x3, 0x2, 0x2, 0x2, 0x69, 0x17, 
    0x3, 0x2, 0x2, 0x2, 0x6a, 0x6b, 0x9, 0x2, 0x2, 0x2, 0x6b, 0x19, 0x3, 
    0x2, 0x2, 0x2, 0x6c, 0x71, 0x7, 0x23, 0x2, 0x2, 0x6d, 0x6e, 0x7, 0x23, 
    0x2, 0x2, 0x6e, 0x70, 0x7, 0x21, 0x2, 0x2, 0x6f, 0x6d, 0x3, 0x2, 0x2, 
    0x2, 0x70, 0x73, 0x3, 0x2, 0x2, 0x2, 0x71, 0x6f, 0x3, 0x2, 0x2, 0x2, 
    0x71, 0x72, 0x3, 0x2, 0x2, 0x2, 0x72, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x73, 
    0x71, 0x3, 0x2, 0x2, 0x2, 0x74, 0x7a, 0x5, 0x1e, 0x10, 0x2, 0x75, 0x7a, 
    0x5, 0x20, 0x11, 0x2, 0x76, 0x7a, 0x7, 0x16, 0x2, 0x2, 0x77, 0x7a, 0x7, 
    0x17, 0x2, 0x2, 0x78, 0x7a, 0x7, 0x18, 0x2, 0x2, 0x79, 0x74, 0x3, 0x2, 
    0x2, 0x2, 0x79, 0x75, 0x3, 0x2, 0x2, 0x2, 0x79, 0x76, 0x3, 0x2, 0x2, 
    0x2, 0x79, 0x77, 0x3, 0x2, 0x2, 0x2, 0x79, 0x78, 0x3, 0x2, 0x2, 0x2, 
    0x7a, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7c, 0x9, 0x3, 0x2, 0x2, 0x7c, 
    0x1f, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7e, 0x9, 0x4, 0x2, 0x2, 0x7e, 0x21, 
    0x3, 0x2, 0x2, 0x2, 0xc, 0x26, 0x32, 0x39, 0x41, 0x48, 0x4f, 0x60, 0x68, 
    0x71, 0x79, 
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
