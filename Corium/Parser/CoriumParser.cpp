
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
    setState(11);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CoriumParser::LET) {
      setState(8);
      localVariableDeclaration();
      setState(13);
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

//----------------- LocalVariableDeclarationContext ------------------------------------------------------------------

CoriumParser::LocalVariableDeclarationContext::LocalVariableDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::LocalVariableDeclarationContext::LET() {
  return getToken(CoriumParser::LET, 0);
}

std::vector<tree::TerminalNode *> CoriumParser::LocalVariableDeclarationContext::WHITESPACE() {
  return getTokens(CoriumParser::WHITESPACE);
}

tree::TerminalNode* CoriumParser::LocalVariableDeclarationContext::WHITESPACE(size_t i) {
  return getToken(CoriumParser::WHITESPACE, i);
}

tree::TerminalNode* CoriumParser::LocalVariableDeclarationContext::IDENT() {
  return getToken(CoriumParser::IDENT, 0);
}

tree::TerminalNode* CoriumParser::LocalVariableDeclarationContext::ASSIGN() {
  return getToken(CoriumParser::ASSIGN, 0);
}

CoriumParser::LiteralContext* CoriumParser::LocalVariableDeclarationContext::literal() {
  return getRuleContext<CoriumParser::LiteralContext>(0);
}

tree::TerminalNode* CoriumParser::LocalVariableDeclarationContext::NEW_LINE() {
  return getToken(CoriumParser::NEW_LINE, 0);
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
  enterRule(_localctx, 2, CoriumParser::RuleLocalVariableDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(14);
    match(CoriumParser::LET);
    setState(15);
    match(CoriumParser::WHITESPACE);
    setState(16);
    match(CoriumParser::IDENT);
    setState(17);
    match(CoriumParser::WHITESPACE);
    setState(18);
    match(CoriumParser::ASSIGN);
    setState(19);
    match(CoriumParser::WHITESPACE);
    setState(20);
    literal();
    setState(21);
    match(CoriumParser::NEW_LINE);
   
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

tree::TerminalNode* CoriumParser::LiteralContext::INT_LITERAL_DEC() {
  return getToken(CoriumParser::INT_LITERAL_DEC, 0);
}

tree::TerminalNode* CoriumParser::LiteralContext::INT_LITERAL_HEX() {
  return getToken(CoriumParser::INT_LITERAL_HEX, 0);
}

tree::TerminalNode* CoriumParser::LiteralContext::INT_LITERAL_OCT() {
  return getToken(CoriumParser::INT_LITERAL_OCT, 0);
}

tree::TerminalNode* CoriumParser::LiteralContext::INT_LITERAL_BIN() {
  return getToken(CoriumParser::INT_LITERAL_BIN, 0);
}

tree::TerminalNode* CoriumParser::LiteralContext::FLOAT_LITERAL_DEC() {
  return getToken(CoriumParser::FLOAT_LITERAL_DEC, 0);
}

tree::TerminalNode* CoriumParser::LiteralContext::FLOAT_LITERAL_HEX() {
  return getToken(CoriumParser::FLOAT_LITERAL_HEX, 0);
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
  enterRule(_localctx, 4, CoriumParser::RuleLiteral);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(28);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CoriumParser::INT_LITERAL_DEC:
      case CoriumParser::INT_LITERAL_HEX:
      case CoriumParser::INT_LITERAL_OCT:
      case CoriumParser::INT_LITERAL_BIN: {
        enterOuterAlt(_localctx, 1);
        setState(23);
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
        break;
      }

      case CoriumParser::FLOAT_LITERAL_DEC:
      case CoriumParser::FLOAT_LITERAL_HEX: {
        enterOuterAlt(_localctx, 2);
        setState(24);
        _la = _input->LA(1);
        if (!(_la == CoriumParser::FLOAT_LITERAL_DEC

        || _la == CoriumParser::FLOAT_LITERAL_HEX)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        break;
      }

      case CoriumParser::BOOL_LITERAL: {
        enterOuterAlt(_localctx, 3);
        setState(25);
        match(CoriumParser::BOOL_LITERAL);
        break;
      }

      case CoriumParser::CHAR_LITERAL: {
        enterOuterAlt(_localctx, 4);
        setState(26);
        match(CoriumParser::CHAR_LITERAL);
        break;
      }

      case CoriumParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 5);
        setState(27);
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

//----------------- PrimitiveTypeContext ------------------------------------------------------------------

CoriumParser::PrimitiveTypeContext::PrimitiveTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::PrimitiveTypeContext::INT() {
  return getToken(CoriumParser::INT, 0);
}

tree::TerminalNode* CoriumParser::PrimitiveTypeContext::FLOAT() {
  return getToken(CoriumParser::FLOAT, 0);
}

tree::TerminalNode* CoriumParser::PrimitiveTypeContext::CHAR() {
  return getToken(CoriumParser::CHAR, 0);
}

tree::TerminalNode* CoriumParser::PrimitiveTypeContext::BOOL() {
  return getToken(CoriumParser::BOOL, 0);
}


size_t CoriumParser::PrimitiveTypeContext::getRuleIndex() const {
  return CoriumParser::RulePrimitiveType;
}

void CoriumParser::PrimitiveTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimitiveType(this);
}

void CoriumParser::PrimitiveTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimitiveType(this);
}

CoriumParser::PrimitiveTypeContext* CoriumParser::primitiveType() {
  PrimitiveTypeContext *_localctx = _tracker.createInstance<PrimitiveTypeContext>(_ctx, getState());
  enterRule(_localctx, 6, CoriumParser::RulePrimitiveType);
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
    setState(30);
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

// Static vars and initialization.
std::vector<dfa::DFA> CoriumParser::_decisionToDFA;
atn::PredictionContextCache CoriumParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN CoriumParser::_atn;
std::vector<uint16_t> CoriumParser::_serializedATN;

std::vector<std::string> CoriumParser::_ruleNames = {
  "compilationUnit", "localVariableDeclaration", "literal", "primitiveType"
};

std::vector<std::string> CoriumParser::_literalNames = {
  "", "'bool'", "'char'", "'float'", "'fun'", "'int'", "'let'", "'native'", 
  "'const'", "", "", "", "", "", "", "", "", "", "'('", "')'", "'{'", "'}'", 
  "'['", "']'", "';'", "','", "'.'", "'='", "", "", "", "'\n'"
};

std::vector<std::string> CoriumParser::_symbolicNames = {
  "", "BOOL", "CHAR", "FLOAT", "FUN", "INT", "LET", "NATIVE", "CONST", "INT_LITERAL_DEC", 
  "INT_LITERAL_HEX", "INT_LITERAL_OCT", "INT_LITERAL_BIN", "FLOAT_LITERAL_DEC", 
  "FLOAT_LITERAL_HEX", "BOOL_LITERAL", "CHAR_LITERAL", "STRING_LITERAL", 
  "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACK", "RBRACK", "SEMI", "COMMA", 
  "DOT", "ASSIGN", "IDENT", "SINGLE_LINE_COMMENT", "MULTI_LINE_COMMENT", 
  "NEW_LINE", "WHITESPACE"
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
    0x3, 0x22, 0x23, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x3, 0x2, 0x7, 0x2, 0xc, 0xa, 0x2, 0xc, 0x2, 
    0xe, 0x2, 0xf, 0xb, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x1f, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x2, 0x2, 0x6, 0x2, 0x4, 0x6, 0x8, 0x2, 0x5, 0x3, 0x2, 0xb, 
    0xe, 0x3, 0x2, 0xf, 0x10, 0x4, 0x2, 0x3, 0x5, 0x7, 0x7, 0x2, 0x23, 0x2, 
    0xd, 0x3, 0x2, 0x2, 0x2, 0x4, 0x10, 0x3, 0x2, 0x2, 0x2, 0x6, 0x1e, 0x3, 
    0x2, 0x2, 0x2, 0x8, 0x20, 0x3, 0x2, 0x2, 0x2, 0xa, 0xc, 0x5, 0x4, 0x3, 
    0x2, 0xb, 0xa, 0x3, 0x2, 0x2, 0x2, 0xc, 0xf, 0x3, 0x2, 0x2, 0x2, 0xd, 
    0xb, 0x3, 0x2, 0x2, 0x2, 0xd, 0xe, 0x3, 0x2, 0x2, 0x2, 0xe, 0x3, 0x3, 
    0x2, 0x2, 0x2, 0xf, 0xd, 0x3, 0x2, 0x2, 0x2, 0x10, 0x11, 0x7, 0x8, 0x2, 
    0x2, 0x11, 0x12, 0x7, 0x22, 0x2, 0x2, 0x12, 0x13, 0x7, 0x1e, 0x2, 0x2, 
    0x13, 0x14, 0x7, 0x22, 0x2, 0x2, 0x14, 0x15, 0x7, 0x1d, 0x2, 0x2, 0x15, 
    0x16, 0x7, 0x22, 0x2, 0x2, 0x16, 0x17, 0x5, 0x6, 0x4, 0x2, 0x17, 0x18, 
    0x7, 0x21, 0x2, 0x2, 0x18, 0x5, 0x3, 0x2, 0x2, 0x2, 0x19, 0x1f, 0x9, 
    0x2, 0x2, 0x2, 0x1a, 0x1f, 0x9, 0x3, 0x2, 0x2, 0x1b, 0x1f, 0x7, 0x11, 
    0x2, 0x2, 0x1c, 0x1f, 0x7, 0x12, 0x2, 0x2, 0x1d, 0x1f, 0x7, 0x13, 0x2, 
    0x2, 0x1e, 0x19, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x1a, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x1e, 
    0x1d, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x7, 0x3, 0x2, 0x2, 0x2, 0x20, 0x21, 
    0x9, 0x4, 0x2, 0x2, 0x21, 0x9, 0x3, 0x2, 0x2, 0x2, 0x4, 0xd, 0x1e, 
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
