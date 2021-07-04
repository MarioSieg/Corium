
// Generated from CoriumParser.g4 by ANTLR 4.7.2


#include "CoriumParserListener.h"

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
  return "CoriumParser.g4";
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

tree::TerminalNode* CoriumParser::CompilationUnitContext::EOF() {
  return getToken(CoriumParser::EOF, 0);
}

CoriumParser::PackageDeclarationContext* CoriumParser::CompilationUnitContext::packageDeclaration() {
  return getRuleContext<CoriumParser::PackageDeclarationContext>(0);
}

std::vector<CoriumParser::ImportDeclarationContext *> CoriumParser::CompilationUnitContext::importDeclaration() {
  return getRuleContexts<CoriumParser::ImportDeclarationContext>();
}

CoriumParser::ImportDeclarationContext* CoriumParser::CompilationUnitContext::importDeclaration(size_t i) {
  return getRuleContext<CoriumParser::ImportDeclarationContext>(i);
}

std::vector<CoriumParser::TypeDeclarationContext *> CoriumParser::CompilationUnitContext::typeDeclaration() {
  return getRuleContexts<CoriumParser::TypeDeclarationContext>();
}

CoriumParser::TypeDeclarationContext* CoriumParser::CompilationUnitContext::typeDeclaration(size_t i) {
  return getRuleContext<CoriumParser::TypeDeclarationContext>(i);
}


size_t CoriumParser::CompilationUnitContext::getRuleIndex() const {
  return CoriumParser::RuleCompilationUnit;
}

void CoriumParser::CompilationUnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompilationUnit(this);
}

void CoriumParser::CompilationUnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompilationUnit(this);
}

CoriumParser::CompilationUnitContext* CoriumParser::compilationUnit() {
  CompilationUnitContext *_localctx = _tracker.createInstance<CompilationUnitContext>(_ctx, getState());
  enterRule(_localctx, 0, CoriumParser::RuleCompilationUnit);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(211);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      setState(210);
      packageDeclaration();
      break;
    }

    }
    setState(216);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CoriumParser::IMPORT) {
      setState(213);
      importDeclaration();
      setState(218);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(222);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CoriumParser::ABSTRACT)
      | (1ULL << CoriumParser::CLASS)
      | (1ULL << CoriumParser::ENUM)
      | (1ULL << CoriumParser::FINAL)
      | (1ULL << CoriumParser::INTERFACE)
      | (1ULL << CoriumParser::PRIVATE)
      | (1ULL << CoriumParser::PROTECTED)
      | (1ULL << CoriumParser::PUBLIC)
      | (1ULL << CoriumParser::STATIC)
      | (1ULL << CoriumParser::STRICTFP))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & ((1ULL << (CoriumParser::SEMI - 67))
      | (1ULL << (CoriumParser::AT - 67))
      | (1ULL << (CoriumParser::IDENTIFIER - 67)))) != 0)) {
      setState(219);
      typeDeclaration();
      setState(224);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(225);
    match(CoriumParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PackageDeclarationContext ------------------------------------------------------------------

CoriumParser::PackageDeclarationContext::PackageDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::PackageDeclarationContext::PACKAGE() {
  return getToken(CoriumParser::PACKAGE, 0);
}

CoriumParser::QualifiedNameContext* CoriumParser::PackageDeclarationContext::qualifiedName() {
  return getRuleContext<CoriumParser::QualifiedNameContext>(0);
}

tree::TerminalNode* CoriumParser::PackageDeclarationContext::SEMI() {
  return getToken(CoriumParser::SEMI, 0);
}

std::vector<CoriumParser::AnnotationContext *> CoriumParser::PackageDeclarationContext::annotation() {
  return getRuleContexts<CoriumParser::AnnotationContext>();
}

CoriumParser::AnnotationContext* CoriumParser::PackageDeclarationContext::annotation(size_t i) {
  return getRuleContext<CoriumParser::AnnotationContext>(i);
}


size_t CoriumParser::PackageDeclarationContext::getRuleIndex() const {
  return CoriumParser::RulePackageDeclaration;
}

void CoriumParser::PackageDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPackageDeclaration(this);
}

void CoriumParser::PackageDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPackageDeclaration(this);
}

CoriumParser::PackageDeclarationContext* CoriumParser::packageDeclaration() {
  PackageDeclarationContext *_localctx = _tracker.createInstance<PackageDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 2, CoriumParser::RulePackageDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(230);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CoriumParser::AT

    || _la == CoriumParser::IDENTIFIER) {
      setState(227);
      annotation();
      setState(232);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(233);
    match(CoriumParser::PACKAGE);
    setState(234);
    qualifiedName();
    setState(235);
    match(CoriumParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImportDeclarationContext ------------------------------------------------------------------

CoriumParser::ImportDeclarationContext::ImportDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::ImportDeclarationContext::IMPORT() {
  return getToken(CoriumParser::IMPORT, 0);
}

CoriumParser::QualifiedNameContext* CoriumParser::ImportDeclarationContext::qualifiedName() {
  return getRuleContext<CoriumParser::QualifiedNameContext>(0);
}

tree::TerminalNode* CoriumParser::ImportDeclarationContext::SEMI() {
  return getToken(CoriumParser::SEMI, 0);
}

tree::TerminalNode* CoriumParser::ImportDeclarationContext::STATIC() {
  return getToken(CoriumParser::STATIC, 0);
}

tree::TerminalNode* CoriumParser::ImportDeclarationContext::DOT() {
  return getToken(CoriumParser::DOT, 0);
}

tree::TerminalNode* CoriumParser::ImportDeclarationContext::MUL() {
  return getToken(CoriumParser::MUL, 0);
}


size_t CoriumParser::ImportDeclarationContext::getRuleIndex() const {
  return CoriumParser::RuleImportDeclaration;
}

void CoriumParser::ImportDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportDeclaration(this);
}

void CoriumParser::ImportDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportDeclaration(this);
}

CoriumParser::ImportDeclarationContext* CoriumParser::importDeclaration() {
  ImportDeclarationContext *_localctx = _tracker.createInstance<ImportDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 4, CoriumParser::RuleImportDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(237);
    match(CoriumParser::IMPORT);
    setState(239);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CoriumParser::STATIC) {
      setState(238);
      match(CoriumParser::STATIC);
    }
    setState(241);
    qualifiedName();
    setState(244);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CoriumParser::DOT) {
      setState(242);
      match(CoriumParser::DOT);
      setState(243);
      match(CoriumParser::MUL);
    }
    setState(246);
    match(CoriumParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeDeclarationContext ------------------------------------------------------------------

CoriumParser::TypeDeclarationContext::TypeDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::ClassDeclarationContext* CoriumParser::TypeDeclarationContext::classDeclaration() {
  return getRuleContext<CoriumParser::ClassDeclarationContext>(0);
}

CoriumParser::EnumDeclarationContext* CoriumParser::TypeDeclarationContext::enumDeclaration() {
  return getRuleContext<CoriumParser::EnumDeclarationContext>(0);
}

CoriumParser::InterfaceDeclarationContext* CoriumParser::TypeDeclarationContext::interfaceDeclaration() {
  return getRuleContext<CoriumParser::InterfaceDeclarationContext>(0);
}

CoriumParser::AnnotationTypeDeclarationContext* CoriumParser::TypeDeclarationContext::annotationTypeDeclaration() {
  return getRuleContext<CoriumParser::AnnotationTypeDeclarationContext>(0);
}

std::vector<CoriumParser::ClassOrInterfaceModifierContext *> CoriumParser::TypeDeclarationContext::classOrInterfaceModifier() {
  return getRuleContexts<CoriumParser::ClassOrInterfaceModifierContext>();
}

CoriumParser::ClassOrInterfaceModifierContext* CoriumParser::TypeDeclarationContext::classOrInterfaceModifier(size_t i) {
  return getRuleContext<CoriumParser::ClassOrInterfaceModifierContext>(i);
}

tree::TerminalNode* CoriumParser::TypeDeclarationContext::SEMI() {
  return getToken(CoriumParser::SEMI, 0);
}


size_t CoriumParser::TypeDeclarationContext::getRuleIndex() const {
  return CoriumParser::RuleTypeDeclaration;
}

void CoriumParser::TypeDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeDeclaration(this);
}

void CoriumParser::TypeDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeDeclaration(this);
}

CoriumParser::TypeDeclarationContext* CoriumParser::typeDeclaration() {
  TypeDeclarationContext *_localctx = _tracker.createInstance<TypeDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 6, CoriumParser::RuleTypeDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(261);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CoriumParser::ABSTRACT:
      case CoriumParser::CLASS:
      case CoriumParser::ENUM:
      case CoriumParser::FINAL:
      case CoriumParser::INTERFACE:
      case CoriumParser::PRIVATE:
      case CoriumParser::PROTECTED:
      case CoriumParser::PUBLIC:
      case CoriumParser::STATIC:
      case CoriumParser::STRICTFP:
      case CoriumParser::AT:
      case CoriumParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(251);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(248);
            classOrInterfaceModifier(); 
          }
          setState(253);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
        }
        setState(258);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case CoriumParser::CLASS: {
            setState(254);
            classDeclaration();
            break;
          }

          case CoriumParser::ENUM: {
            setState(255);
            enumDeclaration();
            break;
          }

          case CoriumParser::INTERFACE: {
            setState(256);
            interfaceDeclaration();
            break;
          }

          case CoriumParser::AT: {
            setState(257);
            annotationTypeDeclaration();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        break;
      }

      case CoriumParser::SEMI: {
        enterOuterAlt(_localctx, 2);
        setState(260);
        match(CoriumParser::SEMI);
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

//----------------- ModifierContext ------------------------------------------------------------------

CoriumParser::ModifierContext::ModifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::ClassOrInterfaceModifierContext* CoriumParser::ModifierContext::classOrInterfaceModifier() {
  return getRuleContext<CoriumParser::ClassOrInterfaceModifierContext>(0);
}

tree::TerminalNode* CoriumParser::ModifierContext::NATIVE() {
  return getToken(CoriumParser::NATIVE, 0);
}

tree::TerminalNode* CoriumParser::ModifierContext::SYNCHRONIZED() {
  return getToken(CoriumParser::SYNCHRONIZED, 0);
}

tree::TerminalNode* CoriumParser::ModifierContext::TRANSIENT() {
  return getToken(CoriumParser::TRANSIENT, 0);
}

tree::TerminalNode* CoriumParser::ModifierContext::VOLATILE() {
  return getToken(CoriumParser::VOLATILE, 0);
}


size_t CoriumParser::ModifierContext::getRuleIndex() const {
  return CoriumParser::RuleModifier;
}

void CoriumParser::ModifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterModifier(this);
}

void CoriumParser::ModifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitModifier(this);
}

CoriumParser::ModifierContext* CoriumParser::modifier() {
  ModifierContext *_localctx = _tracker.createInstance<ModifierContext>(_ctx, getState());
  enterRule(_localctx, 8, CoriumParser::RuleModifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(268);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CoriumParser::ABSTRACT:
      case CoriumParser::FINAL:
      case CoriumParser::PRIVATE:
      case CoriumParser::PROTECTED:
      case CoriumParser::PUBLIC:
      case CoriumParser::STATIC:
      case CoriumParser::STRICTFP:
      case CoriumParser::AT:
      case CoriumParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(263);
        classOrInterfaceModifier();
        break;
      }

      case CoriumParser::NATIVE: {
        enterOuterAlt(_localctx, 2);
        setState(264);
        match(CoriumParser::NATIVE);
        break;
      }

      case CoriumParser::SYNCHRONIZED: {
        enterOuterAlt(_localctx, 3);
        setState(265);
        match(CoriumParser::SYNCHRONIZED);
        break;
      }

      case CoriumParser::TRANSIENT: {
        enterOuterAlt(_localctx, 4);
        setState(266);
        match(CoriumParser::TRANSIENT);
        break;
      }

      case CoriumParser::VOLATILE: {
        enterOuterAlt(_localctx, 5);
        setState(267);
        match(CoriumParser::VOLATILE);
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

//----------------- ClassOrInterfaceModifierContext ------------------------------------------------------------------

CoriumParser::ClassOrInterfaceModifierContext::ClassOrInterfaceModifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::AnnotationContext* CoriumParser::ClassOrInterfaceModifierContext::annotation() {
  return getRuleContext<CoriumParser::AnnotationContext>(0);
}

tree::TerminalNode* CoriumParser::ClassOrInterfaceModifierContext::PUBLIC() {
  return getToken(CoriumParser::PUBLIC, 0);
}

tree::TerminalNode* CoriumParser::ClassOrInterfaceModifierContext::PROTECTED() {
  return getToken(CoriumParser::PROTECTED, 0);
}

tree::TerminalNode* CoriumParser::ClassOrInterfaceModifierContext::PRIVATE() {
  return getToken(CoriumParser::PRIVATE, 0);
}

tree::TerminalNode* CoriumParser::ClassOrInterfaceModifierContext::STATIC() {
  return getToken(CoriumParser::STATIC, 0);
}

tree::TerminalNode* CoriumParser::ClassOrInterfaceModifierContext::ABSTRACT() {
  return getToken(CoriumParser::ABSTRACT, 0);
}

tree::TerminalNode* CoriumParser::ClassOrInterfaceModifierContext::FINAL() {
  return getToken(CoriumParser::FINAL, 0);
}

tree::TerminalNode* CoriumParser::ClassOrInterfaceModifierContext::STRICTFP() {
  return getToken(CoriumParser::STRICTFP, 0);
}


size_t CoriumParser::ClassOrInterfaceModifierContext::getRuleIndex() const {
  return CoriumParser::RuleClassOrInterfaceModifier;
}

void CoriumParser::ClassOrInterfaceModifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassOrInterfaceModifier(this);
}

void CoriumParser::ClassOrInterfaceModifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassOrInterfaceModifier(this);
}

CoriumParser::ClassOrInterfaceModifierContext* CoriumParser::classOrInterfaceModifier() {
  ClassOrInterfaceModifierContext *_localctx = _tracker.createInstance<ClassOrInterfaceModifierContext>(_ctx, getState());
  enterRule(_localctx, 10, CoriumParser::RuleClassOrInterfaceModifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(278);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CoriumParser::AT:
      case CoriumParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(270);
        annotation();
        break;
      }

      case CoriumParser::PUBLIC: {
        enterOuterAlt(_localctx, 2);
        setState(271);
        match(CoriumParser::PUBLIC);
        break;
      }

      case CoriumParser::PROTECTED: {
        enterOuterAlt(_localctx, 3);
        setState(272);
        match(CoriumParser::PROTECTED);
        break;
      }

      case CoriumParser::PRIVATE: {
        enterOuterAlt(_localctx, 4);
        setState(273);
        match(CoriumParser::PRIVATE);
        break;
      }

      case CoriumParser::STATIC: {
        enterOuterAlt(_localctx, 5);
        setState(274);
        match(CoriumParser::STATIC);
        break;
      }

      case CoriumParser::ABSTRACT: {
        enterOuterAlt(_localctx, 6);
        setState(275);
        match(CoriumParser::ABSTRACT);
        break;
      }

      case CoriumParser::FINAL: {
        enterOuterAlt(_localctx, 7);
        setState(276);
        match(CoriumParser::FINAL);
        break;
      }

      case CoriumParser::STRICTFP: {
        enterOuterAlt(_localctx, 8);
        setState(277);
        match(CoriumParser::STRICTFP);
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

//----------------- VariableModifierContext ------------------------------------------------------------------

CoriumParser::VariableModifierContext::VariableModifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::VariableModifierContext::FINAL() {
  return getToken(CoriumParser::FINAL, 0);
}

CoriumParser::AnnotationContext* CoriumParser::VariableModifierContext::annotation() {
  return getRuleContext<CoriumParser::AnnotationContext>(0);
}


size_t CoriumParser::VariableModifierContext::getRuleIndex() const {
  return CoriumParser::RuleVariableModifier;
}

void CoriumParser::VariableModifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableModifier(this);
}

void CoriumParser::VariableModifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableModifier(this);
}

CoriumParser::VariableModifierContext* CoriumParser::variableModifier() {
  VariableModifierContext *_localctx = _tracker.createInstance<VariableModifierContext>(_ctx, getState());
  enterRule(_localctx, 12, CoriumParser::RuleVariableModifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(282);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CoriumParser::FINAL: {
        enterOuterAlt(_localctx, 1);
        setState(280);
        match(CoriumParser::FINAL);
        break;
      }

      case CoriumParser::AT:
      case CoriumParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(281);
        annotation();
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

//----------------- ClassDeclarationContext ------------------------------------------------------------------

CoriumParser::ClassDeclarationContext::ClassDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::ClassDeclarationContext::CLASS() {
  return getToken(CoriumParser::CLASS, 0);
}

tree::TerminalNode* CoriumParser::ClassDeclarationContext::IDENTIFIER() {
  return getToken(CoriumParser::IDENTIFIER, 0);
}

CoriumParser::ClassBodyContext* CoriumParser::ClassDeclarationContext::classBody() {
  return getRuleContext<CoriumParser::ClassBodyContext>(0);
}

CoriumParser::TypeParametersContext* CoriumParser::ClassDeclarationContext::typeParameters() {
  return getRuleContext<CoriumParser::TypeParametersContext>(0);
}

tree::TerminalNode* CoriumParser::ClassDeclarationContext::EXTENDS() {
  return getToken(CoriumParser::EXTENDS, 0);
}

CoriumParser::TypeTypeContext* CoriumParser::ClassDeclarationContext::typeType() {
  return getRuleContext<CoriumParser::TypeTypeContext>(0);
}

tree::TerminalNode* CoriumParser::ClassDeclarationContext::IMPLEMENTS() {
  return getToken(CoriumParser::IMPLEMENTS, 0);
}

CoriumParser::TypeListContext* CoriumParser::ClassDeclarationContext::typeList() {
  return getRuleContext<CoriumParser::TypeListContext>(0);
}


size_t CoriumParser::ClassDeclarationContext::getRuleIndex() const {
  return CoriumParser::RuleClassDeclaration;
}

void CoriumParser::ClassDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassDeclaration(this);
}

void CoriumParser::ClassDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassDeclaration(this);
}

CoriumParser::ClassDeclarationContext* CoriumParser::classDeclaration() {
  ClassDeclarationContext *_localctx = _tracker.createInstance<ClassDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 14, CoriumParser::RuleClassDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(284);
    match(CoriumParser::CLASS);
    setState(285);
    match(CoriumParser::IDENTIFIER);
    setState(287);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CoriumParser::LT) {
      setState(286);
      typeParameters();
    }
    setState(291);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CoriumParser::EXTENDS) {
      setState(289);
      match(CoriumParser::EXTENDS);
      setState(290);
      typeType();
    }
    setState(295);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CoriumParser::IMPLEMENTS) {
      setState(293);
      match(CoriumParser::IMPLEMENTS);
      setState(294);
      typeList();
    }
    setState(297);
    classBody();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeParametersContext ------------------------------------------------------------------

CoriumParser::TypeParametersContext::TypeParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::TypeParametersContext::LT() {
  return getToken(CoriumParser::LT, 0);
}

std::vector<CoriumParser::TypeParameterContext *> CoriumParser::TypeParametersContext::typeParameter() {
  return getRuleContexts<CoriumParser::TypeParameterContext>();
}

CoriumParser::TypeParameterContext* CoriumParser::TypeParametersContext::typeParameter(size_t i) {
  return getRuleContext<CoriumParser::TypeParameterContext>(i);
}

tree::TerminalNode* CoriumParser::TypeParametersContext::GT() {
  return getToken(CoriumParser::GT, 0);
}

std::vector<tree::TerminalNode *> CoriumParser::TypeParametersContext::COMMA() {
  return getTokens(CoriumParser::COMMA);
}

tree::TerminalNode* CoriumParser::TypeParametersContext::COMMA(size_t i) {
  return getToken(CoriumParser::COMMA, i);
}


size_t CoriumParser::TypeParametersContext::getRuleIndex() const {
  return CoriumParser::RuleTypeParameters;
}

void CoriumParser::TypeParametersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeParameters(this);
}

void CoriumParser::TypeParametersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeParameters(this);
}

CoriumParser::TypeParametersContext* CoriumParser::typeParameters() {
  TypeParametersContext *_localctx = _tracker.createInstance<TypeParametersContext>(_ctx, getState());
  enterRule(_localctx, 16, CoriumParser::RuleTypeParameters);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(299);
    match(CoriumParser::LT);
    setState(300);
    typeParameter();
    setState(305);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CoriumParser::COMMA) {
      setState(301);
      match(CoriumParser::COMMA);
      setState(302);
      typeParameter();
      setState(307);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(308);
    match(CoriumParser::GT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeParameterContext ------------------------------------------------------------------

CoriumParser::TypeParameterContext::TypeParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::TypeParameterContext::IDENTIFIER() {
  return getToken(CoriumParser::IDENTIFIER, 0);
}

std::vector<CoriumParser::AnnotationContext *> CoriumParser::TypeParameterContext::annotation() {
  return getRuleContexts<CoriumParser::AnnotationContext>();
}

CoriumParser::AnnotationContext* CoriumParser::TypeParameterContext::annotation(size_t i) {
  return getRuleContext<CoriumParser::AnnotationContext>(i);
}

tree::TerminalNode* CoriumParser::TypeParameterContext::EXTENDS() {
  return getToken(CoriumParser::EXTENDS, 0);
}

CoriumParser::TypeBoundContext* CoriumParser::TypeParameterContext::typeBound() {
  return getRuleContext<CoriumParser::TypeBoundContext>(0);
}


size_t CoriumParser::TypeParameterContext::getRuleIndex() const {
  return CoriumParser::RuleTypeParameter;
}

void CoriumParser::TypeParameterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeParameter(this);
}

void CoriumParser::TypeParameterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeParameter(this);
}

CoriumParser::TypeParameterContext* CoriumParser::typeParameter() {
  TypeParameterContext *_localctx = _tracker.createInstance<TypeParameterContext>(_ctx, getState());
  enterRule(_localctx, 18, CoriumParser::RuleTypeParameter);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(313);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(310);
        annotation(); 
      }
      setState(315);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    }
    setState(316);
    match(CoriumParser::IDENTIFIER);
    setState(325);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CoriumParser::EXTENDS) {
      setState(317);
      match(CoriumParser::EXTENDS);
      setState(321);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(318);
          annotation(); 
        }
        setState(323);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
      }
      setState(324);
      typeBound();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeBoundContext ------------------------------------------------------------------

CoriumParser::TypeBoundContext::TypeBoundContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CoriumParser::TypeTypeContext *> CoriumParser::TypeBoundContext::typeType() {
  return getRuleContexts<CoriumParser::TypeTypeContext>();
}

CoriumParser::TypeTypeContext* CoriumParser::TypeBoundContext::typeType(size_t i) {
  return getRuleContext<CoriumParser::TypeTypeContext>(i);
}

std::vector<tree::TerminalNode *> CoriumParser::TypeBoundContext::BITAND() {
  return getTokens(CoriumParser::BITAND);
}

tree::TerminalNode* CoriumParser::TypeBoundContext::BITAND(size_t i) {
  return getToken(CoriumParser::BITAND, i);
}


size_t CoriumParser::TypeBoundContext::getRuleIndex() const {
  return CoriumParser::RuleTypeBound;
}

void CoriumParser::TypeBoundContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeBound(this);
}

void CoriumParser::TypeBoundContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeBound(this);
}

CoriumParser::TypeBoundContext* CoriumParser::typeBound() {
  TypeBoundContext *_localctx = _tracker.createInstance<TypeBoundContext>(_ctx, getState());
  enterRule(_localctx, 20, CoriumParser::RuleTypeBound);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(327);
    typeType();
    setState(332);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CoriumParser::BITAND) {
      setState(328);
      match(CoriumParser::BITAND);
      setState(329);
      typeType();
      setState(334);
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

//----------------- EnumDeclarationContext ------------------------------------------------------------------

CoriumParser::EnumDeclarationContext::EnumDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::EnumDeclarationContext::ENUM() {
  return getToken(CoriumParser::ENUM, 0);
}

tree::TerminalNode* CoriumParser::EnumDeclarationContext::IDENTIFIER() {
  return getToken(CoriumParser::IDENTIFIER, 0);
}

tree::TerminalNode* CoriumParser::EnumDeclarationContext::LBRACE() {
  return getToken(CoriumParser::LBRACE, 0);
}

tree::TerminalNode* CoriumParser::EnumDeclarationContext::RBRACE() {
  return getToken(CoriumParser::RBRACE, 0);
}

tree::TerminalNode* CoriumParser::EnumDeclarationContext::IMPLEMENTS() {
  return getToken(CoriumParser::IMPLEMENTS, 0);
}

CoriumParser::TypeListContext* CoriumParser::EnumDeclarationContext::typeList() {
  return getRuleContext<CoriumParser::TypeListContext>(0);
}

CoriumParser::EnumConstantsContext* CoriumParser::EnumDeclarationContext::enumConstants() {
  return getRuleContext<CoriumParser::EnumConstantsContext>(0);
}

tree::TerminalNode* CoriumParser::EnumDeclarationContext::COMMA() {
  return getToken(CoriumParser::COMMA, 0);
}

CoriumParser::EnumBodyDeclarationsContext* CoriumParser::EnumDeclarationContext::enumBodyDeclarations() {
  return getRuleContext<CoriumParser::EnumBodyDeclarationsContext>(0);
}


size_t CoriumParser::EnumDeclarationContext::getRuleIndex() const {
  return CoriumParser::RuleEnumDeclaration;
}

void CoriumParser::EnumDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumDeclaration(this);
}

void CoriumParser::EnumDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumDeclaration(this);
}

CoriumParser::EnumDeclarationContext* CoriumParser::enumDeclaration() {
  EnumDeclarationContext *_localctx = _tracker.createInstance<EnumDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 22, CoriumParser::RuleEnumDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(335);
    match(CoriumParser::ENUM);
    setState(336);
    match(CoriumParser::IDENTIFIER);
    setState(339);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CoriumParser::IMPLEMENTS) {
      setState(337);
      match(CoriumParser::IMPLEMENTS);
      setState(338);
      typeList();
    }
    setState(341);
    match(CoriumParser::LBRACE);
    setState(343);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CoriumParser::AT

    || _la == CoriumParser::IDENTIFIER) {
      setState(342);
      enumConstants();
    }
    setState(346);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CoriumParser::COMMA) {
      setState(345);
      match(CoriumParser::COMMA);
    }
    setState(349);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CoriumParser::SEMI) {
      setState(348);
      enumBodyDeclarations();
    }
    setState(351);
    match(CoriumParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumConstantsContext ------------------------------------------------------------------

CoriumParser::EnumConstantsContext::EnumConstantsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CoriumParser::EnumConstantContext *> CoriumParser::EnumConstantsContext::enumConstant() {
  return getRuleContexts<CoriumParser::EnumConstantContext>();
}

CoriumParser::EnumConstantContext* CoriumParser::EnumConstantsContext::enumConstant(size_t i) {
  return getRuleContext<CoriumParser::EnumConstantContext>(i);
}

std::vector<tree::TerminalNode *> CoriumParser::EnumConstantsContext::COMMA() {
  return getTokens(CoriumParser::COMMA);
}

tree::TerminalNode* CoriumParser::EnumConstantsContext::COMMA(size_t i) {
  return getToken(CoriumParser::COMMA, i);
}


size_t CoriumParser::EnumConstantsContext::getRuleIndex() const {
  return CoriumParser::RuleEnumConstants;
}

void CoriumParser::EnumConstantsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumConstants(this);
}

void CoriumParser::EnumConstantsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumConstants(this);
}

CoriumParser::EnumConstantsContext* CoriumParser::enumConstants() {
  EnumConstantsContext *_localctx = _tracker.createInstance<EnumConstantsContext>(_ctx, getState());
  enterRule(_localctx, 24, CoriumParser::RuleEnumConstants);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(353);
    enumConstant();
    setState(358);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(354);
        match(CoriumParser::COMMA);
        setState(355);
        enumConstant(); 
      }
      setState(360);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumConstantContext ------------------------------------------------------------------

CoriumParser::EnumConstantContext::EnumConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::EnumConstantContext::IDENTIFIER() {
  return getToken(CoriumParser::IDENTIFIER, 0);
}

std::vector<CoriumParser::AnnotationContext *> CoriumParser::EnumConstantContext::annotation() {
  return getRuleContexts<CoriumParser::AnnotationContext>();
}

CoriumParser::AnnotationContext* CoriumParser::EnumConstantContext::annotation(size_t i) {
  return getRuleContext<CoriumParser::AnnotationContext>(i);
}

CoriumParser::ArgumentsContext* CoriumParser::EnumConstantContext::arguments() {
  return getRuleContext<CoriumParser::ArgumentsContext>(0);
}

CoriumParser::ClassBodyContext* CoriumParser::EnumConstantContext::classBody() {
  return getRuleContext<CoriumParser::ClassBodyContext>(0);
}


size_t CoriumParser::EnumConstantContext::getRuleIndex() const {
  return CoriumParser::RuleEnumConstant;
}

void CoriumParser::EnumConstantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumConstant(this);
}

void CoriumParser::EnumConstantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumConstant(this);
}

CoriumParser::EnumConstantContext* CoriumParser::enumConstant() {
  EnumConstantContext *_localctx = _tracker.createInstance<EnumConstantContext>(_ctx, getState());
  enterRule(_localctx, 26, CoriumParser::RuleEnumConstant);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(364);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(361);
        annotation(); 
      }
      setState(366);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    }
    setState(367);
    match(CoriumParser::IDENTIFIER);
    setState(369);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CoriumParser::LPAREN) {
      setState(368);
      arguments();
    }
    setState(372);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CoriumParser::LBRACE) {
      setState(371);
      classBody();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumBodyDeclarationsContext ------------------------------------------------------------------

CoriumParser::EnumBodyDeclarationsContext::EnumBodyDeclarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::EnumBodyDeclarationsContext::SEMI() {
  return getToken(CoriumParser::SEMI, 0);
}

std::vector<CoriumParser::ClassBodyDeclarationContext *> CoriumParser::EnumBodyDeclarationsContext::classBodyDeclaration() {
  return getRuleContexts<CoriumParser::ClassBodyDeclarationContext>();
}

CoriumParser::ClassBodyDeclarationContext* CoriumParser::EnumBodyDeclarationsContext::classBodyDeclaration(size_t i) {
  return getRuleContext<CoriumParser::ClassBodyDeclarationContext>(i);
}


size_t CoriumParser::EnumBodyDeclarationsContext::getRuleIndex() const {
  return CoriumParser::RuleEnumBodyDeclarations;
}

void CoriumParser::EnumBodyDeclarationsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumBodyDeclarations(this);
}

void CoriumParser::EnumBodyDeclarationsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumBodyDeclarations(this);
}

CoriumParser::EnumBodyDeclarationsContext* CoriumParser::enumBodyDeclarations() {
  EnumBodyDeclarationsContext *_localctx = _tracker.createInstance<EnumBodyDeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 28, CoriumParser::RuleEnumBodyDeclarations);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(374);
    match(CoriumParser::SEMI);
    setState(378);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CoriumParser::ABSTRACT)
      | (1ULL << CoriumParser::BOOLEAN)
      | (1ULL << CoriumParser::BYTE)
      | (1ULL << CoriumParser::CHAR)
      | (1ULL << CoriumParser::CLASS)
      | (1ULL << CoriumParser::DOUBLE)
      | (1ULL << CoriumParser::ENUM)
      | (1ULL << CoriumParser::FINAL)
      | (1ULL << CoriumParser::FLOAT)
      | (1ULL << CoriumParser::INT)
      | (1ULL << CoriumParser::INTERFACE)
      | (1ULL << CoriumParser::LONG)
      | (1ULL << CoriumParser::NATIVE)
      | (1ULL << CoriumParser::PRIVATE)
      | (1ULL << CoriumParser::PROTECTED)
      | (1ULL << CoriumParser::PUBLIC)
      | (1ULL << CoriumParser::SHORT)
      | (1ULL << CoriumParser::STATIC)
      | (1ULL << CoriumParser::STRICTFP)
      | (1ULL << CoriumParser::SYNCHRONIZED)
      | (1ULL << CoriumParser::TRANSIENT)
      | (1ULL << CoriumParser::VOID)
      | (1ULL << CoriumParser::VOLATILE)
      | (1ULL << CoriumParser::LBRACE))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & ((1ULL << (CoriumParser::SEMI - 67))
      | (1ULL << (CoriumParser::LT - 67))
      | (1ULL << (CoriumParser::AT - 67))
      | (1ULL << (CoriumParser::IDENTIFIER - 67)))) != 0)) {
      setState(375);
      classBodyDeclaration();
      setState(380);
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

//----------------- InterfaceDeclarationContext ------------------------------------------------------------------

CoriumParser::InterfaceDeclarationContext::InterfaceDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::InterfaceDeclarationContext::INTERFACE() {
  return getToken(CoriumParser::INTERFACE, 0);
}

tree::TerminalNode* CoriumParser::InterfaceDeclarationContext::IDENTIFIER() {
  return getToken(CoriumParser::IDENTIFIER, 0);
}

CoriumParser::InterfaceBodyContext* CoriumParser::InterfaceDeclarationContext::interfaceBody() {
  return getRuleContext<CoriumParser::InterfaceBodyContext>(0);
}

CoriumParser::TypeParametersContext* CoriumParser::InterfaceDeclarationContext::typeParameters() {
  return getRuleContext<CoriumParser::TypeParametersContext>(0);
}

tree::TerminalNode* CoriumParser::InterfaceDeclarationContext::EXTENDS() {
  return getToken(CoriumParser::EXTENDS, 0);
}

CoriumParser::TypeListContext* CoriumParser::InterfaceDeclarationContext::typeList() {
  return getRuleContext<CoriumParser::TypeListContext>(0);
}


size_t CoriumParser::InterfaceDeclarationContext::getRuleIndex() const {
  return CoriumParser::RuleInterfaceDeclaration;
}

void CoriumParser::InterfaceDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInterfaceDeclaration(this);
}

void CoriumParser::InterfaceDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInterfaceDeclaration(this);
}

CoriumParser::InterfaceDeclarationContext* CoriumParser::interfaceDeclaration() {
  InterfaceDeclarationContext *_localctx = _tracker.createInstance<InterfaceDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 30, CoriumParser::RuleInterfaceDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(381);
    match(CoriumParser::INTERFACE);
    setState(382);
    match(CoriumParser::IDENTIFIER);
    setState(384);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CoriumParser::LT) {
      setState(383);
      typeParameters();
    }
    setState(388);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CoriumParser::EXTENDS) {
      setState(386);
      match(CoriumParser::EXTENDS);
      setState(387);
      typeList();
    }
    setState(390);
    interfaceBody();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassBodyContext ------------------------------------------------------------------

CoriumParser::ClassBodyContext::ClassBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::ClassBodyContext::LBRACE() {
  return getToken(CoriumParser::LBRACE, 0);
}

tree::TerminalNode* CoriumParser::ClassBodyContext::RBRACE() {
  return getToken(CoriumParser::RBRACE, 0);
}

std::vector<CoriumParser::ClassBodyDeclarationContext *> CoriumParser::ClassBodyContext::classBodyDeclaration() {
  return getRuleContexts<CoriumParser::ClassBodyDeclarationContext>();
}

CoriumParser::ClassBodyDeclarationContext* CoriumParser::ClassBodyContext::classBodyDeclaration(size_t i) {
  return getRuleContext<CoriumParser::ClassBodyDeclarationContext>(i);
}


size_t CoriumParser::ClassBodyContext::getRuleIndex() const {
  return CoriumParser::RuleClassBody;
}

void CoriumParser::ClassBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassBody(this);
}

void CoriumParser::ClassBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassBody(this);
}

CoriumParser::ClassBodyContext* CoriumParser::classBody() {
  ClassBodyContext *_localctx = _tracker.createInstance<ClassBodyContext>(_ctx, getState());
  enterRule(_localctx, 32, CoriumParser::RuleClassBody);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(392);
    match(CoriumParser::LBRACE);
    setState(396);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CoriumParser::ABSTRACT)
      | (1ULL << CoriumParser::BOOLEAN)
      | (1ULL << CoriumParser::BYTE)
      | (1ULL << CoriumParser::CHAR)
      | (1ULL << CoriumParser::CLASS)
      | (1ULL << CoriumParser::DOUBLE)
      | (1ULL << CoriumParser::ENUM)
      | (1ULL << CoriumParser::FINAL)
      | (1ULL << CoriumParser::FLOAT)
      | (1ULL << CoriumParser::INT)
      | (1ULL << CoriumParser::INTERFACE)
      | (1ULL << CoriumParser::LONG)
      | (1ULL << CoriumParser::NATIVE)
      | (1ULL << CoriumParser::PRIVATE)
      | (1ULL << CoriumParser::PROTECTED)
      | (1ULL << CoriumParser::PUBLIC)
      | (1ULL << CoriumParser::SHORT)
      | (1ULL << CoriumParser::STATIC)
      | (1ULL << CoriumParser::STRICTFP)
      | (1ULL << CoriumParser::SYNCHRONIZED)
      | (1ULL << CoriumParser::TRANSIENT)
      | (1ULL << CoriumParser::VOID)
      | (1ULL << CoriumParser::VOLATILE)
      | (1ULL << CoriumParser::LBRACE))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & ((1ULL << (CoriumParser::SEMI - 67))
      | (1ULL << (CoriumParser::LT - 67))
      | (1ULL << (CoriumParser::AT - 67))
      | (1ULL << (CoriumParser::IDENTIFIER - 67)))) != 0)) {
      setState(393);
      classBodyDeclaration();
      setState(398);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(399);
    match(CoriumParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InterfaceBodyContext ------------------------------------------------------------------

CoriumParser::InterfaceBodyContext::InterfaceBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::InterfaceBodyContext::LBRACE() {
  return getToken(CoriumParser::LBRACE, 0);
}

tree::TerminalNode* CoriumParser::InterfaceBodyContext::RBRACE() {
  return getToken(CoriumParser::RBRACE, 0);
}

std::vector<CoriumParser::InterfaceBodyDeclarationContext *> CoriumParser::InterfaceBodyContext::interfaceBodyDeclaration() {
  return getRuleContexts<CoriumParser::InterfaceBodyDeclarationContext>();
}

CoriumParser::InterfaceBodyDeclarationContext* CoriumParser::InterfaceBodyContext::interfaceBodyDeclaration(size_t i) {
  return getRuleContext<CoriumParser::InterfaceBodyDeclarationContext>(i);
}


size_t CoriumParser::InterfaceBodyContext::getRuleIndex() const {
  return CoriumParser::RuleInterfaceBody;
}

void CoriumParser::InterfaceBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInterfaceBody(this);
}

void CoriumParser::InterfaceBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInterfaceBody(this);
}

CoriumParser::InterfaceBodyContext* CoriumParser::interfaceBody() {
  InterfaceBodyContext *_localctx = _tracker.createInstance<InterfaceBodyContext>(_ctx, getState());
  enterRule(_localctx, 34, CoriumParser::RuleInterfaceBody);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(401);
    match(CoriumParser::LBRACE);
    setState(405);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CoriumParser::ABSTRACT)
      | (1ULL << CoriumParser::BOOLEAN)
      | (1ULL << CoriumParser::BYTE)
      | (1ULL << CoriumParser::CHAR)
      | (1ULL << CoriumParser::CLASS)
      | (1ULL << CoriumParser::DEFAULT)
      | (1ULL << CoriumParser::DOUBLE)
      | (1ULL << CoriumParser::ENUM)
      | (1ULL << CoriumParser::FINAL)
      | (1ULL << CoriumParser::FLOAT)
      | (1ULL << CoriumParser::INT)
      | (1ULL << CoriumParser::INTERFACE)
      | (1ULL << CoriumParser::LONG)
      | (1ULL << CoriumParser::NATIVE)
      | (1ULL << CoriumParser::PRIVATE)
      | (1ULL << CoriumParser::PROTECTED)
      | (1ULL << CoriumParser::PUBLIC)
      | (1ULL << CoriumParser::SHORT)
      | (1ULL << CoriumParser::STATIC)
      | (1ULL << CoriumParser::STRICTFP)
      | (1ULL << CoriumParser::SYNCHRONIZED)
      | (1ULL << CoriumParser::TRANSIENT)
      | (1ULL << CoriumParser::VOID)
      | (1ULL << CoriumParser::VOLATILE))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & ((1ULL << (CoriumParser::SEMI - 67))
      | (1ULL << (CoriumParser::LT - 67))
      | (1ULL << (CoriumParser::AT - 67))
      | (1ULL << (CoriumParser::IDENTIFIER - 67)))) != 0)) {
      setState(402);
      interfaceBodyDeclaration();
      setState(407);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(408);
    match(CoriumParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassBodyDeclarationContext ------------------------------------------------------------------

CoriumParser::ClassBodyDeclarationContext::ClassBodyDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::ClassBodyDeclarationContext::SEMI() {
  return getToken(CoriumParser::SEMI, 0);
}

CoriumParser::BlockContext* CoriumParser::ClassBodyDeclarationContext::block() {
  return getRuleContext<CoriumParser::BlockContext>(0);
}

tree::TerminalNode* CoriumParser::ClassBodyDeclarationContext::STATIC() {
  return getToken(CoriumParser::STATIC, 0);
}

CoriumParser::MemberDeclarationContext* CoriumParser::ClassBodyDeclarationContext::memberDeclaration() {
  return getRuleContext<CoriumParser::MemberDeclarationContext>(0);
}

std::vector<CoriumParser::ModifierContext *> CoriumParser::ClassBodyDeclarationContext::modifier() {
  return getRuleContexts<CoriumParser::ModifierContext>();
}

CoriumParser::ModifierContext* CoriumParser::ClassBodyDeclarationContext::modifier(size_t i) {
  return getRuleContext<CoriumParser::ModifierContext>(i);
}


size_t CoriumParser::ClassBodyDeclarationContext::getRuleIndex() const {
  return CoriumParser::RuleClassBodyDeclaration;
}

void CoriumParser::ClassBodyDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassBodyDeclaration(this);
}

void CoriumParser::ClassBodyDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassBodyDeclaration(this);
}

CoriumParser::ClassBodyDeclarationContext* CoriumParser::classBodyDeclaration() {
  ClassBodyDeclarationContext *_localctx = _tracker.createInstance<ClassBodyDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 36, CoriumParser::RuleClassBodyDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(422);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(410);
      match(CoriumParser::SEMI);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(412);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CoriumParser::STATIC) {
        setState(411);
        match(CoriumParser::STATIC);
      }
      setState(414);
      block();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(418);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(415);
          modifier(); 
        }
        setState(420);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
      }
      setState(421);
      memberDeclaration();
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

//----------------- MemberDeclarationContext ------------------------------------------------------------------

CoriumParser::MemberDeclarationContext::MemberDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::MethodDeclarationContext* CoriumParser::MemberDeclarationContext::methodDeclaration() {
  return getRuleContext<CoriumParser::MethodDeclarationContext>(0);
}

CoriumParser::GenericMethodDeclarationContext* CoriumParser::MemberDeclarationContext::genericMethodDeclaration() {
  return getRuleContext<CoriumParser::GenericMethodDeclarationContext>(0);
}

CoriumParser::FieldDeclarationContext* CoriumParser::MemberDeclarationContext::fieldDeclaration() {
  return getRuleContext<CoriumParser::FieldDeclarationContext>(0);
}

CoriumParser::ConstructorDeclarationContext* CoriumParser::MemberDeclarationContext::constructorDeclaration() {
  return getRuleContext<CoriumParser::ConstructorDeclarationContext>(0);
}

CoriumParser::GenericConstructorDeclarationContext* CoriumParser::MemberDeclarationContext::genericConstructorDeclaration() {
  return getRuleContext<CoriumParser::GenericConstructorDeclarationContext>(0);
}

CoriumParser::InterfaceDeclarationContext* CoriumParser::MemberDeclarationContext::interfaceDeclaration() {
  return getRuleContext<CoriumParser::InterfaceDeclarationContext>(0);
}

CoriumParser::AnnotationTypeDeclarationContext* CoriumParser::MemberDeclarationContext::annotationTypeDeclaration() {
  return getRuleContext<CoriumParser::AnnotationTypeDeclarationContext>(0);
}

CoriumParser::ClassDeclarationContext* CoriumParser::MemberDeclarationContext::classDeclaration() {
  return getRuleContext<CoriumParser::ClassDeclarationContext>(0);
}

CoriumParser::EnumDeclarationContext* CoriumParser::MemberDeclarationContext::enumDeclaration() {
  return getRuleContext<CoriumParser::EnumDeclarationContext>(0);
}


size_t CoriumParser::MemberDeclarationContext::getRuleIndex() const {
  return CoriumParser::RuleMemberDeclaration;
}

void CoriumParser::MemberDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMemberDeclaration(this);
}

void CoriumParser::MemberDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMemberDeclaration(this);
}

CoriumParser::MemberDeclarationContext* CoriumParser::memberDeclaration() {
  MemberDeclarationContext *_localctx = _tracker.createInstance<MemberDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 38, CoriumParser::RuleMemberDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(433);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(424);
      methodDeclaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(425);
      genericMethodDeclaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(426);
      fieldDeclaration();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(427);
      constructorDeclaration();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(428);
      genericConstructorDeclaration();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(429);
      interfaceDeclaration();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(430);
      annotationTypeDeclaration();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(431);
      classDeclaration();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(432);
      enumDeclaration();
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

//----------------- MethodDeclarationContext ------------------------------------------------------------------

CoriumParser::MethodDeclarationContext::MethodDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::TypeTypeOrVoidContext* CoriumParser::MethodDeclarationContext::typeTypeOrVoid() {
  return getRuleContext<CoriumParser::TypeTypeOrVoidContext>(0);
}

tree::TerminalNode* CoriumParser::MethodDeclarationContext::IDENTIFIER() {
  return getToken(CoriumParser::IDENTIFIER, 0);
}

CoriumParser::FormalParametersContext* CoriumParser::MethodDeclarationContext::formalParameters() {
  return getRuleContext<CoriumParser::FormalParametersContext>(0);
}

CoriumParser::MethodBodyContext* CoriumParser::MethodDeclarationContext::methodBody() {
  return getRuleContext<CoriumParser::MethodBodyContext>(0);
}

std::vector<tree::TerminalNode *> CoriumParser::MethodDeclarationContext::LBRACK() {
  return getTokens(CoriumParser::LBRACK);
}

tree::TerminalNode* CoriumParser::MethodDeclarationContext::LBRACK(size_t i) {
  return getToken(CoriumParser::LBRACK, i);
}

std::vector<tree::TerminalNode *> CoriumParser::MethodDeclarationContext::RBRACK() {
  return getTokens(CoriumParser::RBRACK);
}

tree::TerminalNode* CoriumParser::MethodDeclarationContext::RBRACK(size_t i) {
  return getToken(CoriumParser::RBRACK, i);
}

tree::TerminalNode* CoriumParser::MethodDeclarationContext::THROWS() {
  return getToken(CoriumParser::THROWS, 0);
}

CoriumParser::QualifiedNameListContext* CoriumParser::MethodDeclarationContext::qualifiedNameList() {
  return getRuleContext<CoriumParser::QualifiedNameListContext>(0);
}


size_t CoriumParser::MethodDeclarationContext::getRuleIndex() const {
  return CoriumParser::RuleMethodDeclaration;
}

void CoriumParser::MethodDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMethodDeclaration(this);
}

void CoriumParser::MethodDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMethodDeclaration(this);
}

CoriumParser::MethodDeclarationContext* CoriumParser::methodDeclaration() {
  MethodDeclarationContext *_localctx = _tracker.createInstance<MethodDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 40, CoriumParser::RuleMethodDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(435);
    typeTypeOrVoid();
    setState(436);
    match(CoriumParser::IDENTIFIER);
    setState(437);
    formalParameters();
    setState(442);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CoriumParser::LBRACK) {
      setState(438);
      match(CoriumParser::LBRACK);
      setState(439);
      match(CoriumParser::RBRACK);
      setState(444);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(447);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CoriumParser::THROWS) {
      setState(445);
      match(CoriumParser::THROWS);
      setState(446);
      qualifiedNameList();
    }
    setState(449);
    methodBody();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MethodBodyContext ------------------------------------------------------------------

CoriumParser::MethodBodyContext::MethodBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::BlockContext* CoriumParser::MethodBodyContext::block() {
  return getRuleContext<CoriumParser::BlockContext>(0);
}

tree::TerminalNode* CoriumParser::MethodBodyContext::SEMI() {
  return getToken(CoriumParser::SEMI, 0);
}


size_t CoriumParser::MethodBodyContext::getRuleIndex() const {
  return CoriumParser::RuleMethodBody;
}

void CoriumParser::MethodBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMethodBody(this);
}

void CoriumParser::MethodBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMethodBody(this);
}

CoriumParser::MethodBodyContext* CoriumParser::methodBody() {
  MethodBodyContext *_localctx = _tracker.createInstance<MethodBodyContext>(_ctx, getState());
  enterRule(_localctx, 42, CoriumParser::RuleMethodBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(453);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CoriumParser::LBRACE: {
        enterOuterAlt(_localctx, 1);
        setState(451);
        block();
        break;
      }

      case CoriumParser::SEMI: {
        enterOuterAlt(_localctx, 2);
        setState(452);
        match(CoriumParser::SEMI);
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

//----------------- TypeTypeOrVoidContext ------------------------------------------------------------------

CoriumParser::TypeTypeOrVoidContext::TypeTypeOrVoidContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::TypeTypeContext* CoriumParser::TypeTypeOrVoidContext::typeType() {
  return getRuleContext<CoriumParser::TypeTypeContext>(0);
}

tree::TerminalNode* CoriumParser::TypeTypeOrVoidContext::VOID() {
  return getToken(CoriumParser::VOID, 0);
}


size_t CoriumParser::TypeTypeOrVoidContext::getRuleIndex() const {
  return CoriumParser::RuleTypeTypeOrVoid;
}

void CoriumParser::TypeTypeOrVoidContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeTypeOrVoid(this);
}

void CoriumParser::TypeTypeOrVoidContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeTypeOrVoid(this);
}

CoriumParser::TypeTypeOrVoidContext* CoriumParser::typeTypeOrVoid() {
  TypeTypeOrVoidContext *_localctx = _tracker.createInstance<TypeTypeOrVoidContext>(_ctx, getState());
  enterRule(_localctx, 44, CoriumParser::RuleTypeTypeOrVoid);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(457);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CoriumParser::BOOLEAN:
      case CoriumParser::BYTE:
      case CoriumParser::CHAR:
      case CoriumParser::DOUBLE:
      case CoriumParser::FLOAT:
      case CoriumParser::INT:
      case CoriumParser::LONG:
      case CoriumParser::SHORT:
      case CoriumParser::AT:
      case CoriumParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(455);
        typeType();
        break;
      }

      case CoriumParser::VOID: {
        enterOuterAlt(_localctx, 2);
        setState(456);
        match(CoriumParser::VOID);
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

//----------------- GenericMethodDeclarationContext ------------------------------------------------------------------

CoriumParser::GenericMethodDeclarationContext::GenericMethodDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::TypeParametersContext* CoriumParser::GenericMethodDeclarationContext::typeParameters() {
  return getRuleContext<CoriumParser::TypeParametersContext>(0);
}

CoriumParser::MethodDeclarationContext* CoriumParser::GenericMethodDeclarationContext::methodDeclaration() {
  return getRuleContext<CoriumParser::MethodDeclarationContext>(0);
}


size_t CoriumParser::GenericMethodDeclarationContext::getRuleIndex() const {
  return CoriumParser::RuleGenericMethodDeclaration;
}

void CoriumParser::GenericMethodDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGenericMethodDeclaration(this);
}

void CoriumParser::GenericMethodDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGenericMethodDeclaration(this);
}

CoriumParser::GenericMethodDeclarationContext* CoriumParser::genericMethodDeclaration() {
  GenericMethodDeclarationContext *_localctx = _tracker.createInstance<GenericMethodDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 46, CoriumParser::RuleGenericMethodDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(459);
    typeParameters();
    setState(460);
    methodDeclaration();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GenericConstructorDeclarationContext ------------------------------------------------------------------

CoriumParser::GenericConstructorDeclarationContext::GenericConstructorDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::TypeParametersContext* CoriumParser::GenericConstructorDeclarationContext::typeParameters() {
  return getRuleContext<CoriumParser::TypeParametersContext>(0);
}

CoriumParser::ConstructorDeclarationContext* CoriumParser::GenericConstructorDeclarationContext::constructorDeclaration() {
  return getRuleContext<CoriumParser::ConstructorDeclarationContext>(0);
}


size_t CoriumParser::GenericConstructorDeclarationContext::getRuleIndex() const {
  return CoriumParser::RuleGenericConstructorDeclaration;
}

void CoriumParser::GenericConstructorDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGenericConstructorDeclaration(this);
}

void CoriumParser::GenericConstructorDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGenericConstructorDeclaration(this);
}

CoriumParser::GenericConstructorDeclarationContext* CoriumParser::genericConstructorDeclaration() {
  GenericConstructorDeclarationContext *_localctx = _tracker.createInstance<GenericConstructorDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 48, CoriumParser::RuleGenericConstructorDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(462);
    typeParameters();
    setState(463);
    constructorDeclaration();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstructorDeclarationContext ------------------------------------------------------------------

CoriumParser::ConstructorDeclarationContext::ConstructorDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::ConstructorDeclarationContext::IDENTIFIER() {
  return getToken(CoriumParser::IDENTIFIER, 0);
}

CoriumParser::FormalParametersContext* CoriumParser::ConstructorDeclarationContext::formalParameters() {
  return getRuleContext<CoriumParser::FormalParametersContext>(0);
}

CoriumParser::BlockContext* CoriumParser::ConstructorDeclarationContext::block() {
  return getRuleContext<CoriumParser::BlockContext>(0);
}

tree::TerminalNode* CoriumParser::ConstructorDeclarationContext::THROWS() {
  return getToken(CoriumParser::THROWS, 0);
}

CoriumParser::QualifiedNameListContext* CoriumParser::ConstructorDeclarationContext::qualifiedNameList() {
  return getRuleContext<CoriumParser::QualifiedNameListContext>(0);
}


size_t CoriumParser::ConstructorDeclarationContext::getRuleIndex() const {
  return CoriumParser::RuleConstructorDeclaration;
}

void CoriumParser::ConstructorDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstructorDeclaration(this);
}

void CoriumParser::ConstructorDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstructorDeclaration(this);
}

CoriumParser::ConstructorDeclarationContext* CoriumParser::constructorDeclaration() {
  ConstructorDeclarationContext *_localctx = _tracker.createInstance<ConstructorDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 50, CoriumParser::RuleConstructorDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(465);
    match(CoriumParser::IDENTIFIER);
    setState(466);
    formalParameters();
    setState(469);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CoriumParser::THROWS) {
      setState(467);
      match(CoriumParser::THROWS);
      setState(468);
      qualifiedNameList();
    }
    setState(471);
    dynamic_cast<ConstructorDeclarationContext *>(_localctx)->constructorBody = block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FieldDeclarationContext ------------------------------------------------------------------

CoriumParser::FieldDeclarationContext::FieldDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::TypeTypeContext* CoriumParser::FieldDeclarationContext::typeType() {
  return getRuleContext<CoriumParser::TypeTypeContext>(0);
}

CoriumParser::VariableDeclaratorsContext* CoriumParser::FieldDeclarationContext::variableDeclarators() {
  return getRuleContext<CoriumParser::VariableDeclaratorsContext>(0);
}

tree::TerminalNode* CoriumParser::FieldDeclarationContext::SEMI() {
  return getToken(CoriumParser::SEMI, 0);
}


size_t CoriumParser::FieldDeclarationContext::getRuleIndex() const {
  return CoriumParser::RuleFieldDeclaration;
}

void CoriumParser::FieldDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFieldDeclaration(this);
}

void CoriumParser::FieldDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFieldDeclaration(this);
}

CoriumParser::FieldDeclarationContext* CoriumParser::fieldDeclaration() {
  FieldDeclarationContext *_localctx = _tracker.createInstance<FieldDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 52, CoriumParser::RuleFieldDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(473);
    typeType();
    setState(474);
    variableDeclarators();
    setState(475);
    match(CoriumParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InterfaceBodyDeclarationContext ------------------------------------------------------------------

CoriumParser::InterfaceBodyDeclarationContext::InterfaceBodyDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::InterfaceMemberDeclarationContext* CoriumParser::InterfaceBodyDeclarationContext::interfaceMemberDeclaration() {
  return getRuleContext<CoriumParser::InterfaceMemberDeclarationContext>(0);
}

std::vector<CoriumParser::ModifierContext *> CoriumParser::InterfaceBodyDeclarationContext::modifier() {
  return getRuleContexts<CoriumParser::ModifierContext>();
}

CoriumParser::ModifierContext* CoriumParser::InterfaceBodyDeclarationContext::modifier(size_t i) {
  return getRuleContext<CoriumParser::ModifierContext>(i);
}

tree::TerminalNode* CoriumParser::InterfaceBodyDeclarationContext::SEMI() {
  return getToken(CoriumParser::SEMI, 0);
}


size_t CoriumParser::InterfaceBodyDeclarationContext::getRuleIndex() const {
  return CoriumParser::RuleInterfaceBodyDeclaration;
}

void CoriumParser::InterfaceBodyDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInterfaceBodyDeclaration(this);
}

void CoriumParser::InterfaceBodyDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInterfaceBodyDeclaration(this);
}

CoriumParser::InterfaceBodyDeclarationContext* CoriumParser::interfaceBodyDeclaration() {
  InterfaceBodyDeclarationContext *_localctx = _tracker.createInstance<InterfaceBodyDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 54, CoriumParser::RuleInterfaceBodyDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(485);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CoriumParser::ABSTRACT:
      case CoriumParser::BOOLEAN:
      case CoriumParser::BYTE:
      case CoriumParser::CHAR:
      case CoriumParser::CLASS:
      case CoriumParser::DEFAULT:
      case CoriumParser::DOUBLE:
      case CoriumParser::ENUM:
      case CoriumParser::FINAL:
      case CoriumParser::FLOAT:
      case CoriumParser::INT:
      case CoriumParser::INTERFACE:
      case CoriumParser::LONG:
      case CoriumParser::NATIVE:
      case CoriumParser::PRIVATE:
      case CoriumParser::PROTECTED:
      case CoriumParser::PUBLIC:
      case CoriumParser::SHORT:
      case CoriumParser::STATIC:
      case CoriumParser::STRICTFP:
      case CoriumParser::SYNCHRONIZED:
      case CoriumParser::TRANSIENT:
      case CoriumParser::VOID:
      case CoriumParser::VOLATILE:
      case CoriumParser::LT:
      case CoriumParser::AT:
      case CoriumParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(480);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(477);
            modifier(); 
          }
          setState(482);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx);
        }
        setState(483);
        interfaceMemberDeclaration();
        break;
      }

      case CoriumParser::SEMI: {
        enterOuterAlt(_localctx, 2);
        setState(484);
        match(CoriumParser::SEMI);
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

//----------------- InterfaceMemberDeclarationContext ------------------------------------------------------------------

CoriumParser::InterfaceMemberDeclarationContext::InterfaceMemberDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::ConstDeclarationContext* CoriumParser::InterfaceMemberDeclarationContext::constDeclaration() {
  return getRuleContext<CoriumParser::ConstDeclarationContext>(0);
}

CoriumParser::InterfaceMethodDeclarationContext* CoriumParser::InterfaceMemberDeclarationContext::interfaceMethodDeclaration() {
  return getRuleContext<CoriumParser::InterfaceMethodDeclarationContext>(0);
}

CoriumParser::GenericInterfaceMethodDeclarationContext* CoriumParser::InterfaceMemberDeclarationContext::genericInterfaceMethodDeclaration() {
  return getRuleContext<CoriumParser::GenericInterfaceMethodDeclarationContext>(0);
}

CoriumParser::InterfaceDeclarationContext* CoriumParser::InterfaceMemberDeclarationContext::interfaceDeclaration() {
  return getRuleContext<CoriumParser::InterfaceDeclarationContext>(0);
}

CoriumParser::AnnotationTypeDeclarationContext* CoriumParser::InterfaceMemberDeclarationContext::annotationTypeDeclaration() {
  return getRuleContext<CoriumParser::AnnotationTypeDeclarationContext>(0);
}

CoriumParser::ClassDeclarationContext* CoriumParser::InterfaceMemberDeclarationContext::classDeclaration() {
  return getRuleContext<CoriumParser::ClassDeclarationContext>(0);
}

CoriumParser::EnumDeclarationContext* CoriumParser::InterfaceMemberDeclarationContext::enumDeclaration() {
  return getRuleContext<CoriumParser::EnumDeclarationContext>(0);
}


size_t CoriumParser::InterfaceMemberDeclarationContext::getRuleIndex() const {
  return CoriumParser::RuleInterfaceMemberDeclaration;
}

void CoriumParser::InterfaceMemberDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInterfaceMemberDeclaration(this);
}

void CoriumParser::InterfaceMemberDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInterfaceMemberDeclaration(this);
}

CoriumParser::InterfaceMemberDeclarationContext* CoriumParser::interfaceMemberDeclaration() {
  InterfaceMemberDeclarationContext *_localctx = _tracker.createInstance<InterfaceMemberDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 56, CoriumParser::RuleInterfaceMemberDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(494);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(487);
      constDeclaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(488);
      interfaceMethodDeclaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(489);
      genericInterfaceMethodDeclaration();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(490);
      interfaceDeclaration();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(491);
      annotationTypeDeclaration();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(492);
      classDeclaration();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(493);
      enumDeclaration();
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

//----------------- ConstDeclarationContext ------------------------------------------------------------------

CoriumParser::ConstDeclarationContext::ConstDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::TypeTypeContext* CoriumParser::ConstDeclarationContext::typeType() {
  return getRuleContext<CoriumParser::TypeTypeContext>(0);
}

std::vector<CoriumParser::ConstantDeclaratorContext *> CoriumParser::ConstDeclarationContext::constantDeclarator() {
  return getRuleContexts<CoriumParser::ConstantDeclaratorContext>();
}

CoriumParser::ConstantDeclaratorContext* CoriumParser::ConstDeclarationContext::constantDeclarator(size_t i) {
  return getRuleContext<CoriumParser::ConstantDeclaratorContext>(i);
}

tree::TerminalNode* CoriumParser::ConstDeclarationContext::SEMI() {
  return getToken(CoriumParser::SEMI, 0);
}

std::vector<tree::TerminalNode *> CoriumParser::ConstDeclarationContext::COMMA() {
  return getTokens(CoriumParser::COMMA);
}

tree::TerminalNode* CoriumParser::ConstDeclarationContext::COMMA(size_t i) {
  return getToken(CoriumParser::COMMA, i);
}


size_t CoriumParser::ConstDeclarationContext::getRuleIndex() const {
  return CoriumParser::RuleConstDeclaration;
}

void CoriumParser::ConstDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstDeclaration(this);
}

void CoriumParser::ConstDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstDeclaration(this);
}

CoriumParser::ConstDeclarationContext* CoriumParser::constDeclaration() {
  ConstDeclarationContext *_localctx = _tracker.createInstance<ConstDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 58, CoriumParser::RuleConstDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(496);
    typeType();
    setState(497);
    constantDeclarator();
    setState(502);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CoriumParser::COMMA) {
      setState(498);
      match(CoriumParser::COMMA);
      setState(499);
      constantDeclarator();
      setState(504);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(505);
    match(CoriumParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantDeclaratorContext ------------------------------------------------------------------

CoriumParser::ConstantDeclaratorContext::ConstantDeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::ConstantDeclaratorContext::IDENTIFIER() {
  return getToken(CoriumParser::IDENTIFIER, 0);
}

tree::TerminalNode* CoriumParser::ConstantDeclaratorContext::ASSIGN() {
  return getToken(CoriumParser::ASSIGN, 0);
}

CoriumParser::VariableInitializerContext* CoriumParser::ConstantDeclaratorContext::variableInitializer() {
  return getRuleContext<CoriumParser::VariableInitializerContext>(0);
}

std::vector<tree::TerminalNode *> CoriumParser::ConstantDeclaratorContext::LBRACK() {
  return getTokens(CoriumParser::LBRACK);
}

tree::TerminalNode* CoriumParser::ConstantDeclaratorContext::LBRACK(size_t i) {
  return getToken(CoriumParser::LBRACK, i);
}

std::vector<tree::TerminalNode *> CoriumParser::ConstantDeclaratorContext::RBRACK() {
  return getTokens(CoriumParser::RBRACK);
}

tree::TerminalNode* CoriumParser::ConstantDeclaratorContext::RBRACK(size_t i) {
  return getToken(CoriumParser::RBRACK, i);
}


size_t CoriumParser::ConstantDeclaratorContext::getRuleIndex() const {
  return CoriumParser::RuleConstantDeclarator;
}

void CoriumParser::ConstantDeclaratorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstantDeclarator(this);
}

void CoriumParser::ConstantDeclaratorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstantDeclarator(this);
}

CoriumParser::ConstantDeclaratorContext* CoriumParser::constantDeclarator() {
  ConstantDeclaratorContext *_localctx = _tracker.createInstance<ConstantDeclaratorContext>(_ctx, getState());
  enterRule(_localctx, 60, CoriumParser::RuleConstantDeclarator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(507);
    match(CoriumParser::IDENTIFIER);
    setState(512);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CoriumParser::LBRACK) {
      setState(508);
      match(CoriumParser::LBRACK);
      setState(509);
      match(CoriumParser::RBRACK);
      setState(514);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(515);
    match(CoriumParser::ASSIGN);
    setState(516);
    variableInitializer();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InterfaceMethodDeclarationContext ------------------------------------------------------------------

CoriumParser::InterfaceMethodDeclarationContext::InterfaceMethodDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::InterfaceMethodDeclarationContext::IDENTIFIER() {
  return getToken(CoriumParser::IDENTIFIER, 0);
}

CoriumParser::FormalParametersContext* CoriumParser::InterfaceMethodDeclarationContext::formalParameters() {
  return getRuleContext<CoriumParser::FormalParametersContext>(0);
}

CoriumParser::MethodBodyContext* CoriumParser::InterfaceMethodDeclarationContext::methodBody() {
  return getRuleContext<CoriumParser::MethodBodyContext>(0);
}

CoriumParser::TypeTypeOrVoidContext* CoriumParser::InterfaceMethodDeclarationContext::typeTypeOrVoid() {
  return getRuleContext<CoriumParser::TypeTypeOrVoidContext>(0);
}

CoriumParser::TypeParametersContext* CoriumParser::InterfaceMethodDeclarationContext::typeParameters() {
  return getRuleContext<CoriumParser::TypeParametersContext>(0);
}

std::vector<CoriumParser::InterfaceMethodModifierContext *> CoriumParser::InterfaceMethodDeclarationContext::interfaceMethodModifier() {
  return getRuleContexts<CoriumParser::InterfaceMethodModifierContext>();
}

CoriumParser::InterfaceMethodModifierContext* CoriumParser::InterfaceMethodDeclarationContext::interfaceMethodModifier(size_t i) {
  return getRuleContext<CoriumParser::InterfaceMethodModifierContext>(i);
}

std::vector<tree::TerminalNode *> CoriumParser::InterfaceMethodDeclarationContext::LBRACK() {
  return getTokens(CoriumParser::LBRACK);
}

tree::TerminalNode* CoriumParser::InterfaceMethodDeclarationContext::LBRACK(size_t i) {
  return getToken(CoriumParser::LBRACK, i);
}

std::vector<tree::TerminalNode *> CoriumParser::InterfaceMethodDeclarationContext::RBRACK() {
  return getTokens(CoriumParser::RBRACK);
}

tree::TerminalNode* CoriumParser::InterfaceMethodDeclarationContext::RBRACK(size_t i) {
  return getToken(CoriumParser::RBRACK, i);
}

tree::TerminalNode* CoriumParser::InterfaceMethodDeclarationContext::THROWS() {
  return getToken(CoriumParser::THROWS, 0);
}

CoriumParser::QualifiedNameListContext* CoriumParser::InterfaceMethodDeclarationContext::qualifiedNameList() {
  return getRuleContext<CoriumParser::QualifiedNameListContext>(0);
}

std::vector<CoriumParser::AnnotationContext *> CoriumParser::InterfaceMethodDeclarationContext::annotation() {
  return getRuleContexts<CoriumParser::AnnotationContext>();
}

CoriumParser::AnnotationContext* CoriumParser::InterfaceMethodDeclarationContext::annotation(size_t i) {
  return getRuleContext<CoriumParser::AnnotationContext>(i);
}


size_t CoriumParser::InterfaceMethodDeclarationContext::getRuleIndex() const {
  return CoriumParser::RuleInterfaceMethodDeclaration;
}

void CoriumParser::InterfaceMethodDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInterfaceMethodDeclaration(this);
}

void CoriumParser::InterfaceMethodDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInterfaceMethodDeclaration(this);
}

CoriumParser::InterfaceMethodDeclarationContext* CoriumParser::interfaceMethodDeclaration() {
  InterfaceMethodDeclarationContext *_localctx = _tracker.createInstance<InterfaceMethodDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 62, CoriumParser::RuleInterfaceMethodDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(521);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(518);
        interfaceMethodModifier(); 
      }
      setState(523);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx);
    }
    setState(534);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CoriumParser::BOOLEAN:
      case CoriumParser::BYTE:
      case CoriumParser::CHAR:
      case CoriumParser::DOUBLE:
      case CoriumParser::FLOAT:
      case CoriumParser::INT:
      case CoriumParser::LONG:
      case CoriumParser::SHORT:
      case CoriumParser::VOID:
      case CoriumParser::AT:
      case CoriumParser::IDENTIFIER: {
        setState(524);
        typeTypeOrVoid();
        break;
      }

      case CoriumParser::LT: {
        setState(525);
        typeParameters();
        setState(529);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(526);
            annotation(); 
          }
          setState(531);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx);
        }
        setState(532);
        typeTypeOrVoid();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(536);
    match(CoriumParser::IDENTIFIER);
    setState(537);
    formalParameters();
    setState(542);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CoriumParser::LBRACK) {
      setState(538);
      match(CoriumParser::LBRACK);
      setState(539);
      match(CoriumParser::RBRACK);
      setState(544);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(547);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CoriumParser::THROWS) {
      setState(545);
      match(CoriumParser::THROWS);
      setState(546);
      qualifiedNameList();
    }
    setState(549);
    methodBody();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InterfaceMethodModifierContext ------------------------------------------------------------------

CoriumParser::InterfaceMethodModifierContext::InterfaceMethodModifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::AnnotationContext* CoriumParser::InterfaceMethodModifierContext::annotation() {
  return getRuleContext<CoriumParser::AnnotationContext>(0);
}

tree::TerminalNode* CoriumParser::InterfaceMethodModifierContext::PUBLIC() {
  return getToken(CoriumParser::PUBLIC, 0);
}

tree::TerminalNode* CoriumParser::InterfaceMethodModifierContext::ABSTRACT() {
  return getToken(CoriumParser::ABSTRACT, 0);
}

tree::TerminalNode* CoriumParser::InterfaceMethodModifierContext::DEFAULT() {
  return getToken(CoriumParser::DEFAULT, 0);
}

tree::TerminalNode* CoriumParser::InterfaceMethodModifierContext::STATIC() {
  return getToken(CoriumParser::STATIC, 0);
}

tree::TerminalNode* CoriumParser::InterfaceMethodModifierContext::STRICTFP() {
  return getToken(CoriumParser::STRICTFP, 0);
}


size_t CoriumParser::InterfaceMethodModifierContext::getRuleIndex() const {
  return CoriumParser::RuleInterfaceMethodModifier;
}

void CoriumParser::InterfaceMethodModifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInterfaceMethodModifier(this);
}

void CoriumParser::InterfaceMethodModifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInterfaceMethodModifier(this);
}

CoriumParser::InterfaceMethodModifierContext* CoriumParser::interfaceMethodModifier() {
  InterfaceMethodModifierContext *_localctx = _tracker.createInstance<InterfaceMethodModifierContext>(_ctx, getState());
  enterRule(_localctx, 64, CoriumParser::RuleInterfaceMethodModifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(557);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CoriumParser::AT:
      case CoriumParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(551);
        annotation();
        break;
      }

      case CoriumParser::PUBLIC: {
        enterOuterAlt(_localctx, 2);
        setState(552);
        match(CoriumParser::PUBLIC);
        break;
      }

      case CoriumParser::ABSTRACT: {
        enterOuterAlt(_localctx, 3);
        setState(553);
        match(CoriumParser::ABSTRACT);
        break;
      }

      case CoriumParser::DEFAULT: {
        enterOuterAlt(_localctx, 4);
        setState(554);
        match(CoriumParser::DEFAULT);
        break;
      }

      case CoriumParser::STATIC: {
        enterOuterAlt(_localctx, 5);
        setState(555);
        match(CoriumParser::STATIC);
        break;
      }

      case CoriumParser::STRICTFP: {
        enterOuterAlt(_localctx, 6);
        setState(556);
        match(CoriumParser::STRICTFP);
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

//----------------- GenericInterfaceMethodDeclarationContext ------------------------------------------------------------------

CoriumParser::GenericInterfaceMethodDeclarationContext::GenericInterfaceMethodDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::TypeParametersContext* CoriumParser::GenericInterfaceMethodDeclarationContext::typeParameters() {
  return getRuleContext<CoriumParser::TypeParametersContext>(0);
}

CoriumParser::InterfaceMethodDeclarationContext* CoriumParser::GenericInterfaceMethodDeclarationContext::interfaceMethodDeclaration() {
  return getRuleContext<CoriumParser::InterfaceMethodDeclarationContext>(0);
}


size_t CoriumParser::GenericInterfaceMethodDeclarationContext::getRuleIndex() const {
  return CoriumParser::RuleGenericInterfaceMethodDeclaration;
}

void CoriumParser::GenericInterfaceMethodDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGenericInterfaceMethodDeclaration(this);
}

void CoriumParser::GenericInterfaceMethodDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGenericInterfaceMethodDeclaration(this);
}

CoriumParser::GenericInterfaceMethodDeclarationContext* CoriumParser::genericInterfaceMethodDeclaration() {
  GenericInterfaceMethodDeclarationContext *_localctx = _tracker.createInstance<GenericInterfaceMethodDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 66, CoriumParser::RuleGenericInterfaceMethodDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(559);
    typeParameters();
    setState(560);
    interfaceMethodDeclaration();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclaratorsContext ------------------------------------------------------------------

CoriumParser::VariableDeclaratorsContext::VariableDeclaratorsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CoriumParser::VariableDeclaratorContext *> CoriumParser::VariableDeclaratorsContext::variableDeclarator() {
  return getRuleContexts<CoriumParser::VariableDeclaratorContext>();
}

CoriumParser::VariableDeclaratorContext* CoriumParser::VariableDeclaratorsContext::variableDeclarator(size_t i) {
  return getRuleContext<CoriumParser::VariableDeclaratorContext>(i);
}

std::vector<tree::TerminalNode *> CoriumParser::VariableDeclaratorsContext::COMMA() {
  return getTokens(CoriumParser::COMMA);
}

tree::TerminalNode* CoriumParser::VariableDeclaratorsContext::COMMA(size_t i) {
  return getToken(CoriumParser::COMMA, i);
}


size_t CoriumParser::VariableDeclaratorsContext::getRuleIndex() const {
  return CoriumParser::RuleVariableDeclarators;
}

void CoriumParser::VariableDeclaratorsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableDeclarators(this);
}

void CoriumParser::VariableDeclaratorsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableDeclarators(this);
}

CoriumParser::VariableDeclaratorsContext* CoriumParser::variableDeclarators() {
  VariableDeclaratorsContext *_localctx = _tracker.createInstance<VariableDeclaratorsContext>(_ctx, getState());
  enterRule(_localctx, 68, CoriumParser::RuleVariableDeclarators);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(562);
    variableDeclarator();
    setState(567);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CoriumParser::COMMA) {
      setState(563);
      match(CoriumParser::COMMA);
      setState(564);
      variableDeclarator();
      setState(569);
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

//----------------- VariableDeclaratorContext ------------------------------------------------------------------

CoriumParser::VariableDeclaratorContext::VariableDeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::VariableDeclaratorIdContext* CoriumParser::VariableDeclaratorContext::variableDeclaratorId() {
  return getRuleContext<CoriumParser::VariableDeclaratorIdContext>(0);
}

tree::TerminalNode* CoriumParser::VariableDeclaratorContext::ASSIGN() {
  return getToken(CoriumParser::ASSIGN, 0);
}

CoriumParser::VariableInitializerContext* CoriumParser::VariableDeclaratorContext::variableInitializer() {
  return getRuleContext<CoriumParser::VariableInitializerContext>(0);
}


size_t CoriumParser::VariableDeclaratorContext::getRuleIndex() const {
  return CoriumParser::RuleVariableDeclarator;
}

void CoriumParser::VariableDeclaratorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableDeclarator(this);
}

void CoriumParser::VariableDeclaratorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableDeclarator(this);
}

CoriumParser::VariableDeclaratorContext* CoriumParser::variableDeclarator() {
  VariableDeclaratorContext *_localctx = _tracker.createInstance<VariableDeclaratorContext>(_ctx, getState());
  enterRule(_localctx, 70, CoriumParser::RuleVariableDeclarator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(570);
    variableDeclaratorId();
    setState(573);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CoriumParser::ASSIGN) {
      setState(571);
      match(CoriumParser::ASSIGN);
      setState(572);
      variableInitializer();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclaratorIdContext ------------------------------------------------------------------

CoriumParser::VariableDeclaratorIdContext::VariableDeclaratorIdContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::VariableDeclaratorIdContext::IDENTIFIER() {
  return getToken(CoriumParser::IDENTIFIER, 0);
}

std::vector<tree::TerminalNode *> CoriumParser::VariableDeclaratorIdContext::LBRACK() {
  return getTokens(CoriumParser::LBRACK);
}

tree::TerminalNode* CoriumParser::VariableDeclaratorIdContext::LBRACK(size_t i) {
  return getToken(CoriumParser::LBRACK, i);
}

std::vector<tree::TerminalNode *> CoriumParser::VariableDeclaratorIdContext::RBRACK() {
  return getTokens(CoriumParser::RBRACK);
}

tree::TerminalNode* CoriumParser::VariableDeclaratorIdContext::RBRACK(size_t i) {
  return getToken(CoriumParser::RBRACK, i);
}


size_t CoriumParser::VariableDeclaratorIdContext::getRuleIndex() const {
  return CoriumParser::RuleVariableDeclaratorId;
}

void CoriumParser::VariableDeclaratorIdContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableDeclaratorId(this);
}

void CoriumParser::VariableDeclaratorIdContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableDeclaratorId(this);
}

CoriumParser::VariableDeclaratorIdContext* CoriumParser::variableDeclaratorId() {
  VariableDeclaratorIdContext *_localctx = _tracker.createInstance<VariableDeclaratorIdContext>(_ctx, getState());
  enterRule(_localctx, 72, CoriumParser::RuleVariableDeclaratorId);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(575);
    match(CoriumParser::IDENTIFIER);
    setState(580);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CoriumParser::LBRACK) {
      setState(576);
      match(CoriumParser::LBRACK);
      setState(577);
      match(CoriumParser::RBRACK);
      setState(582);
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

//----------------- VariableInitializerContext ------------------------------------------------------------------

CoriumParser::VariableInitializerContext::VariableInitializerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::ArrayInitializerContext* CoriumParser::VariableInitializerContext::arrayInitializer() {
  return getRuleContext<CoriumParser::ArrayInitializerContext>(0);
}

CoriumParser::ExpressionContext* CoriumParser::VariableInitializerContext::expression() {
  return getRuleContext<CoriumParser::ExpressionContext>(0);
}


size_t CoriumParser::VariableInitializerContext::getRuleIndex() const {
  return CoriumParser::RuleVariableInitializer;
}

void CoriumParser::VariableInitializerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableInitializer(this);
}

void CoriumParser::VariableInitializerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableInitializer(this);
}

CoriumParser::VariableInitializerContext* CoriumParser::variableInitializer() {
  VariableInitializerContext *_localctx = _tracker.createInstance<VariableInitializerContext>(_ctx, getState());
  enterRule(_localctx, 74, CoriumParser::RuleVariableInitializer);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(585);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CoriumParser::LBRACE: {
        enterOuterAlt(_localctx, 1);
        setState(583);
        arrayInitializer();
        break;
      }

      case CoriumParser::BOOLEAN:
      case CoriumParser::BYTE:
      case CoriumParser::CHAR:
      case CoriumParser::DOUBLE:
      case CoriumParser::FLOAT:
      case CoriumParser::INT:
      case CoriumParser::LONG:
      case CoriumParser::NEW:
      case CoriumParser::SHORT:
      case CoriumParser::SUPER:
      case CoriumParser::THIS:
      case CoriumParser::VOID:
      case CoriumParser::DECIMAL_LITERAL:
      case CoriumParser::HEX_LITERAL:
      case CoriumParser::OCT_LITERAL:
      case CoriumParser::BINARY_LITERAL:
      case CoriumParser::FLOAT_LITERAL:
      case CoriumParser::HEX_FLOAT_LITERAL:
      case CoriumParser::BOOL_LITERAL:
      case CoriumParser::CHAR_LITERAL:
      case CoriumParser::STRING_LITERAL:
      case CoriumParser::NULL_LITERAL:
      case CoriumParser::LPAREN:
      case CoriumParser::LT:
      case CoriumParser::BANG:
      case CoriumParser::TILDE:
      case CoriumParser::INC:
      case CoriumParser::DEC:
      case CoriumParser::ADD:
      case CoriumParser::SUB:
      case CoriumParser::AT:
      case CoriumParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(584);
        expression(0);
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

//----------------- ArrayInitializerContext ------------------------------------------------------------------

CoriumParser::ArrayInitializerContext::ArrayInitializerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::ArrayInitializerContext::LBRACE() {
  return getToken(CoriumParser::LBRACE, 0);
}

tree::TerminalNode* CoriumParser::ArrayInitializerContext::RBRACE() {
  return getToken(CoriumParser::RBRACE, 0);
}

std::vector<CoriumParser::VariableInitializerContext *> CoriumParser::ArrayInitializerContext::variableInitializer() {
  return getRuleContexts<CoriumParser::VariableInitializerContext>();
}

CoriumParser::VariableInitializerContext* CoriumParser::ArrayInitializerContext::variableInitializer(size_t i) {
  return getRuleContext<CoriumParser::VariableInitializerContext>(i);
}

std::vector<tree::TerminalNode *> CoriumParser::ArrayInitializerContext::COMMA() {
  return getTokens(CoriumParser::COMMA);
}

tree::TerminalNode* CoriumParser::ArrayInitializerContext::COMMA(size_t i) {
  return getToken(CoriumParser::COMMA, i);
}


size_t CoriumParser::ArrayInitializerContext::getRuleIndex() const {
  return CoriumParser::RuleArrayInitializer;
}

void CoriumParser::ArrayInitializerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayInitializer(this);
}

void CoriumParser::ArrayInitializerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayInitializer(this);
}

CoriumParser::ArrayInitializerContext* CoriumParser::arrayInitializer() {
  ArrayInitializerContext *_localctx = _tracker.createInstance<ArrayInitializerContext>(_ctx, getState());
  enterRule(_localctx, 76, CoriumParser::RuleArrayInitializer);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(587);
    match(CoriumParser::LBRACE);
    setState(599);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CoriumParser::BOOLEAN)
      | (1ULL << CoriumParser::BYTE)
      | (1ULL << CoriumParser::CHAR)
      | (1ULL << CoriumParser::DOUBLE)
      | (1ULL << CoriumParser::FLOAT)
      | (1ULL << CoriumParser::INT)
      | (1ULL << CoriumParser::LONG)
      | (1ULL << CoriumParser::NEW)
      | (1ULL << CoriumParser::SHORT)
      | (1ULL << CoriumParser::SUPER)
      | (1ULL << CoriumParser::THIS)
      | (1ULL << CoriumParser::VOID)
      | (1ULL << CoriumParser::DECIMAL_LITERAL)
      | (1ULL << CoriumParser::HEX_LITERAL)
      | (1ULL << CoriumParser::OCT_LITERAL)
      | (1ULL << CoriumParser::BINARY_LITERAL)
      | (1ULL << CoriumParser::FLOAT_LITERAL)
      | (1ULL << CoriumParser::HEX_FLOAT_LITERAL)
      | (1ULL << CoriumParser::BOOL_LITERAL)
      | (1ULL << CoriumParser::CHAR_LITERAL)
      | (1ULL << CoriumParser::STRING_LITERAL)
      | (1ULL << CoriumParser::NULL_LITERAL)
      | (1ULL << CoriumParser::LPAREN)
      | (1ULL << CoriumParser::LBRACE))) != 0) || ((((_la - 72) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 72)) & ((1ULL << (CoriumParser::LT - 72))
      | (1ULL << (CoriumParser::BANG - 72))
      | (1ULL << (CoriumParser::TILDE - 72))
      | (1ULL << (CoriumParser::INC - 72))
      | (1ULL << (CoriumParser::DEC - 72))
      | (1ULL << (CoriumParser::ADD - 72))
      | (1ULL << (CoriumParser::SUB - 72))
      | (1ULL << (CoriumParser::AT - 72))
      | (1ULL << (CoriumParser::IDENTIFIER - 72)))) != 0)) {
      setState(588);
      variableInitializer();
      setState(593);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(589);
          match(CoriumParser::COMMA);
          setState(590);
          variableInitializer(); 
        }
        setState(595);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx);
      }
      setState(597);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CoriumParser::COMMA) {
        setState(596);
        match(CoriumParser::COMMA);
      }
    }
    setState(601);
    match(CoriumParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassOrInterfaceTypeContext ------------------------------------------------------------------

CoriumParser::ClassOrInterfaceTypeContext::ClassOrInterfaceTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> CoriumParser::ClassOrInterfaceTypeContext::IDENTIFIER() {
  return getTokens(CoriumParser::IDENTIFIER);
}

tree::TerminalNode* CoriumParser::ClassOrInterfaceTypeContext::IDENTIFIER(size_t i) {
  return getToken(CoriumParser::IDENTIFIER, i);
}

std::vector<CoriumParser::TypeArgumentsContext *> CoriumParser::ClassOrInterfaceTypeContext::typeArguments() {
  return getRuleContexts<CoriumParser::TypeArgumentsContext>();
}

CoriumParser::TypeArgumentsContext* CoriumParser::ClassOrInterfaceTypeContext::typeArguments(size_t i) {
  return getRuleContext<CoriumParser::TypeArgumentsContext>(i);
}

std::vector<tree::TerminalNode *> CoriumParser::ClassOrInterfaceTypeContext::DOT() {
  return getTokens(CoriumParser::DOT);
}

tree::TerminalNode* CoriumParser::ClassOrInterfaceTypeContext::DOT(size_t i) {
  return getToken(CoriumParser::DOT, i);
}


size_t CoriumParser::ClassOrInterfaceTypeContext::getRuleIndex() const {
  return CoriumParser::RuleClassOrInterfaceType;
}

void CoriumParser::ClassOrInterfaceTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassOrInterfaceType(this);
}

void CoriumParser::ClassOrInterfaceTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassOrInterfaceType(this);
}

CoriumParser::ClassOrInterfaceTypeContext* CoriumParser::classOrInterfaceType() {
  ClassOrInterfaceTypeContext *_localctx = _tracker.createInstance<ClassOrInterfaceTypeContext>(_ctx, getState());
  enterRule(_localctx, 78, CoriumParser::RuleClassOrInterfaceType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(603);
    match(CoriumParser::IDENTIFIER);
    setState(605);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx)) {
    case 1: {
      setState(604);
      typeArguments();
      break;
    }

    }
    setState(614);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 62, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(607);
        match(CoriumParser::DOT);
        setState(608);
        match(CoriumParser::IDENTIFIER);
        setState(610);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 61, _ctx)) {
        case 1: {
          setState(609);
          typeArguments();
          break;
        }

        } 
      }
      setState(616);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 62, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeArgumentContext ------------------------------------------------------------------

CoriumParser::TypeArgumentContext::TypeArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::TypeTypeContext* CoriumParser::TypeArgumentContext::typeType() {
  return getRuleContext<CoriumParser::TypeTypeContext>(0);
}

tree::TerminalNode* CoriumParser::TypeArgumentContext::QUESTION() {
  return getToken(CoriumParser::QUESTION, 0);
}

std::vector<CoriumParser::AnnotationContext *> CoriumParser::TypeArgumentContext::annotation() {
  return getRuleContexts<CoriumParser::AnnotationContext>();
}

CoriumParser::AnnotationContext* CoriumParser::TypeArgumentContext::annotation(size_t i) {
  return getRuleContext<CoriumParser::AnnotationContext>(i);
}

tree::TerminalNode* CoriumParser::TypeArgumentContext::EXTENDS() {
  return getToken(CoriumParser::EXTENDS, 0);
}

tree::TerminalNode* CoriumParser::TypeArgumentContext::SUPER() {
  return getToken(CoriumParser::SUPER, 0);
}


size_t CoriumParser::TypeArgumentContext::getRuleIndex() const {
  return CoriumParser::RuleTypeArgument;
}

void CoriumParser::TypeArgumentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeArgument(this);
}

void CoriumParser::TypeArgumentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeArgument(this);
}

CoriumParser::TypeArgumentContext* CoriumParser::typeArgument() {
  TypeArgumentContext *_localctx = _tracker.createInstance<TypeArgumentContext>(_ctx, getState());
  enterRule(_localctx, 80, CoriumParser::RuleTypeArgument);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(629);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(617);
      typeType();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(621);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CoriumParser::AT

      || _la == CoriumParser::IDENTIFIER) {
        setState(618);
        annotation();
        setState(623);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(624);
      match(CoriumParser::QUESTION);
      setState(627);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CoriumParser::EXTENDS

      || _la == CoriumParser::SUPER) {
        setState(625);
        _la = _input->LA(1);
        if (!(_la == CoriumParser::EXTENDS

        || _la == CoriumParser::SUPER)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(626);
        typeType();
      }
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

//----------------- QualifiedNameListContext ------------------------------------------------------------------

CoriumParser::QualifiedNameListContext::QualifiedNameListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CoriumParser::QualifiedNameContext *> CoriumParser::QualifiedNameListContext::qualifiedName() {
  return getRuleContexts<CoriumParser::QualifiedNameContext>();
}

CoriumParser::QualifiedNameContext* CoriumParser::QualifiedNameListContext::qualifiedName(size_t i) {
  return getRuleContext<CoriumParser::QualifiedNameContext>(i);
}

std::vector<tree::TerminalNode *> CoriumParser::QualifiedNameListContext::COMMA() {
  return getTokens(CoriumParser::COMMA);
}

tree::TerminalNode* CoriumParser::QualifiedNameListContext::COMMA(size_t i) {
  return getToken(CoriumParser::COMMA, i);
}


size_t CoriumParser::QualifiedNameListContext::getRuleIndex() const {
  return CoriumParser::RuleQualifiedNameList;
}

void CoriumParser::QualifiedNameListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQualifiedNameList(this);
}

void CoriumParser::QualifiedNameListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQualifiedNameList(this);
}

CoriumParser::QualifiedNameListContext* CoriumParser::qualifiedNameList() {
  QualifiedNameListContext *_localctx = _tracker.createInstance<QualifiedNameListContext>(_ctx, getState());
  enterRule(_localctx, 82, CoriumParser::RuleQualifiedNameList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(631);
    qualifiedName();
    setState(636);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CoriumParser::COMMA) {
      setState(632);
      match(CoriumParser::COMMA);
      setState(633);
      qualifiedName();
      setState(638);
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

//----------------- FormalParametersContext ------------------------------------------------------------------

CoriumParser::FormalParametersContext::FormalParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::FormalParametersContext::LPAREN() {
  return getToken(CoriumParser::LPAREN, 0);
}

tree::TerminalNode* CoriumParser::FormalParametersContext::RPAREN() {
  return getToken(CoriumParser::RPAREN, 0);
}

CoriumParser::FormalParameterListContext* CoriumParser::FormalParametersContext::formalParameterList() {
  return getRuleContext<CoriumParser::FormalParameterListContext>(0);
}


size_t CoriumParser::FormalParametersContext::getRuleIndex() const {
  return CoriumParser::RuleFormalParameters;
}

void CoriumParser::FormalParametersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFormalParameters(this);
}

void CoriumParser::FormalParametersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFormalParameters(this);
}

CoriumParser::FormalParametersContext* CoriumParser::formalParameters() {
  FormalParametersContext *_localctx = _tracker.createInstance<FormalParametersContext>(_ctx, getState());
  enterRule(_localctx, 84, CoriumParser::RuleFormalParameters);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(639);
    match(CoriumParser::LPAREN);
    setState(641);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CoriumParser::BOOLEAN)
      | (1ULL << CoriumParser::BYTE)
      | (1ULL << CoriumParser::CHAR)
      | (1ULL << CoriumParser::DOUBLE)
      | (1ULL << CoriumParser::FINAL)
      | (1ULL << CoriumParser::FLOAT)
      | (1ULL << CoriumParser::INT)
      | (1ULL << CoriumParser::LONG)
      | (1ULL << CoriumParser::SHORT))) != 0) || _la == CoriumParser::AT

    || _la == CoriumParser::IDENTIFIER) {
      setState(640);
      formalParameterList();
    }
    setState(643);
    match(CoriumParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FormalParameterListContext ------------------------------------------------------------------

CoriumParser::FormalParameterListContext::FormalParameterListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CoriumParser::FormalParameterContext *> CoriumParser::FormalParameterListContext::formalParameter() {
  return getRuleContexts<CoriumParser::FormalParameterContext>();
}

CoriumParser::FormalParameterContext* CoriumParser::FormalParameterListContext::formalParameter(size_t i) {
  return getRuleContext<CoriumParser::FormalParameterContext>(i);
}

std::vector<tree::TerminalNode *> CoriumParser::FormalParameterListContext::COMMA() {
  return getTokens(CoriumParser::COMMA);
}

tree::TerminalNode* CoriumParser::FormalParameterListContext::COMMA(size_t i) {
  return getToken(CoriumParser::COMMA, i);
}

CoriumParser::LastFormalParameterContext* CoriumParser::FormalParameterListContext::lastFormalParameter() {
  return getRuleContext<CoriumParser::LastFormalParameterContext>(0);
}


size_t CoriumParser::FormalParameterListContext::getRuleIndex() const {
  return CoriumParser::RuleFormalParameterList;
}

void CoriumParser::FormalParameterListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFormalParameterList(this);
}

void CoriumParser::FormalParameterListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFormalParameterList(this);
}

CoriumParser::FormalParameterListContext* CoriumParser::formalParameterList() {
  FormalParameterListContext *_localctx = _tracker.createInstance<FormalParameterListContext>(_ctx, getState());
  enterRule(_localctx, 86, CoriumParser::RuleFormalParameterList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(658);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(645);
      formalParameter();
      setState(650);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 68, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(646);
          match(CoriumParser::COMMA);
          setState(647);
          formalParameter(); 
        }
        setState(652);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 68, _ctx);
      }
      setState(655);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CoriumParser::COMMA) {
        setState(653);
        match(CoriumParser::COMMA);
        setState(654);
        lastFormalParameter();
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(657);
      lastFormalParameter();
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

//----------------- FormalParameterContext ------------------------------------------------------------------

CoriumParser::FormalParameterContext::FormalParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::TypeTypeContext* CoriumParser::FormalParameterContext::typeType() {
  return getRuleContext<CoriumParser::TypeTypeContext>(0);
}

CoriumParser::VariableDeclaratorIdContext* CoriumParser::FormalParameterContext::variableDeclaratorId() {
  return getRuleContext<CoriumParser::VariableDeclaratorIdContext>(0);
}

std::vector<CoriumParser::VariableModifierContext *> CoriumParser::FormalParameterContext::variableModifier() {
  return getRuleContexts<CoriumParser::VariableModifierContext>();
}

CoriumParser::VariableModifierContext* CoriumParser::FormalParameterContext::variableModifier(size_t i) {
  return getRuleContext<CoriumParser::VariableModifierContext>(i);
}


size_t CoriumParser::FormalParameterContext::getRuleIndex() const {
  return CoriumParser::RuleFormalParameter;
}

void CoriumParser::FormalParameterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFormalParameter(this);
}

void CoriumParser::FormalParameterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFormalParameter(this);
}

CoriumParser::FormalParameterContext* CoriumParser::formalParameter() {
  FormalParameterContext *_localctx = _tracker.createInstance<FormalParameterContext>(_ctx, getState());
  enterRule(_localctx, 88, CoriumParser::RuleFormalParameter);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(663);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(660);
        variableModifier(); 
      }
      setState(665);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx);
    }
    setState(666);
    typeType();
    setState(667);
    variableDeclaratorId();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LastFormalParameterContext ------------------------------------------------------------------

CoriumParser::LastFormalParameterContext::LastFormalParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::TypeTypeContext* CoriumParser::LastFormalParameterContext::typeType() {
  return getRuleContext<CoriumParser::TypeTypeContext>(0);
}

tree::TerminalNode* CoriumParser::LastFormalParameterContext::ELLIPSIS() {
  return getToken(CoriumParser::ELLIPSIS, 0);
}

CoriumParser::VariableDeclaratorIdContext* CoriumParser::LastFormalParameterContext::variableDeclaratorId() {
  return getRuleContext<CoriumParser::VariableDeclaratorIdContext>(0);
}

std::vector<CoriumParser::VariableModifierContext *> CoriumParser::LastFormalParameterContext::variableModifier() {
  return getRuleContexts<CoriumParser::VariableModifierContext>();
}

CoriumParser::VariableModifierContext* CoriumParser::LastFormalParameterContext::variableModifier(size_t i) {
  return getRuleContext<CoriumParser::VariableModifierContext>(i);
}

std::vector<CoriumParser::AnnotationContext *> CoriumParser::LastFormalParameterContext::annotation() {
  return getRuleContexts<CoriumParser::AnnotationContext>();
}

CoriumParser::AnnotationContext* CoriumParser::LastFormalParameterContext::annotation(size_t i) {
  return getRuleContext<CoriumParser::AnnotationContext>(i);
}


size_t CoriumParser::LastFormalParameterContext::getRuleIndex() const {
  return CoriumParser::RuleLastFormalParameter;
}

void CoriumParser::LastFormalParameterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLastFormalParameter(this);
}

void CoriumParser::LastFormalParameterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLastFormalParameter(this);
}

CoriumParser::LastFormalParameterContext* CoriumParser::lastFormalParameter() {
  LastFormalParameterContext *_localctx = _tracker.createInstance<LastFormalParameterContext>(_ctx, getState());
  enterRule(_localctx, 90, CoriumParser::RuleLastFormalParameter);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(672);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 72, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(669);
        variableModifier(); 
      }
      setState(674);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 72, _ctx);
    }
    setState(675);
    typeType();
    setState(679);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CoriumParser::AT

    || _la == CoriumParser::IDENTIFIER) {
      setState(676);
      annotation();
      setState(681);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(682);
    match(CoriumParser::ELLIPSIS);
    setState(683);
    variableDeclaratorId();
   
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

std::vector<tree::TerminalNode *> CoriumParser::QualifiedNameContext::IDENTIFIER() {
  return getTokens(CoriumParser::IDENTIFIER);
}

tree::TerminalNode* CoriumParser::QualifiedNameContext::IDENTIFIER(size_t i) {
  return getToken(CoriumParser::IDENTIFIER, i);
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
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQualifiedName(this);
}

void CoriumParser::QualifiedNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQualifiedName(this);
}

CoriumParser::QualifiedNameContext* CoriumParser::qualifiedName() {
  QualifiedNameContext *_localctx = _tracker.createInstance<QualifiedNameContext>(_ctx, getState());
  enterRule(_localctx, 92, CoriumParser::RuleQualifiedName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(685);
    match(CoriumParser::IDENTIFIER);
    setState(690);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 74, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(686);
        match(CoriumParser::DOT);
        setState(687);
        match(CoriumParser::IDENTIFIER); 
      }
      setState(692);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 74, _ctx);
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

CoriumParser::IntegerLiteralContext* CoriumParser::LiteralContext::integerLiteral() {
  return getRuleContext<CoriumParser::IntegerLiteralContext>(0);
}

CoriumParser::FloatLiteralContext* CoriumParser::LiteralContext::floatLiteral() {
  return getRuleContext<CoriumParser::FloatLiteralContext>(0);
}

tree::TerminalNode* CoriumParser::LiteralContext::CHAR_LITERAL() {
  return getToken(CoriumParser::CHAR_LITERAL, 0);
}

tree::TerminalNode* CoriumParser::LiteralContext::STRING_LITERAL() {
  return getToken(CoriumParser::STRING_LITERAL, 0);
}

tree::TerminalNode* CoriumParser::LiteralContext::BOOL_LITERAL() {
  return getToken(CoriumParser::BOOL_LITERAL, 0);
}

tree::TerminalNode* CoriumParser::LiteralContext::NULL_LITERAL() {
  return getToken(CoriumParser::NULL_LITERAL, 0);
}


size_t CoriumParser::LiteralContext::getRuleIndex() const {
  return CoriumParser::RuleLiteral;
}

void CoriumParser::LiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteral(this);
}

void CoriumParser::LiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteral(this);
}

CoriumParser::LiteralContext* CoriumParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 94, CoriumParser::RuleLiteral);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(699);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CoriumParser::DECIMAL_LITERAL:
      case CoriumParser::HEX_LITERAL:
      case CoriumParser::OCT_LITERAL:
      case CoriumParser::BINARY_LITERAL: {
        enterOuterAlt(_localctx, 1);
        setState(693);
        integerLiteral();
        break;
      }

      case CoriumParser::FLOAT_LITERAL:
      case CoriumParser::HEX_FLOAT_LITERAL: {
        enterOuterAlt(_localctx, 2);
        setState(694);
        floatLiteral();
        break;
      }

      case CoriumParser::CHAR_LITERAL: {
        enterOuterAlt(_localctx, 3);
        setState(695);
        match(CoriumParser::CHAR_LITERAL);
        break;
      }

      case CoriumParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 4);
        setState(696);
        match(CoriumParser::STRING_LITERAL);
        break;
      }

      case CoriumParser::BOOL_LITERAL: {
        enterOuterAlt(_localctx, 5);
        setState(697);
        match(CoriumParser::BOOL_LITERAL);
        break;
      }

      case CoriumParser::NULL_LITERAL: {
        enterOuterAlt(_localctx, 6);
        setState(698);
        match(CoriumParser::NULL_LITERAL);
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

//----------------- IntegerLiteralContext ------------------------------------------------------------------

CoriumParser::IntegerLiteralContext::IntegerLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::IntegerLiteralContext::DECIMAL_LITERAL() {
  return getToken(CoriumParser::DECIMAL_LITERAL, 0);
}

tree::TerminalNode* CoriumParser::IntegerLiteralContext::HEX_LITERAL() {
  return getToken(CoriumParser::HEX_LITERAL, 0);
}

tree::TerminalNode* CoriumParser::IntegerLiteralContext::OCT_LITERAL() {
  return getToken(CoriumParser::OCT_LITERAL, 0);
}

tree::TerminalNode* CoriumParser::IntegerLiteralContext::BINARY_LITERAL() {
  return getToken(CoriumParser::BINARY_LITERAL, 0);
}


size_t CoriumParser::IntegerLiteralContext::getRuleIndex() const {
  return CoriumParser::RuleIntegerLiteral;
}

void CoriumParser::IntegerLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntegerLiteral(this);
}

void CoriumParser::IntegerLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntegerLiteral(this);
}

CoriumParser::IntegerLiteralContext* CoriumParser::integerLiteral() {
  IntegerLiteralContext *_localctx = _tracker.createInstance<IntegerLiteralContext>(_ctx, getState());
  enterRule(_localctx, 96, CoriumParser::RuleIntegerLiteral);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(701);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CoriumParser::DECIMAL_LITERAL)
      | (1ULL << CoriumParser::HEX_LITERAL)
      | (1ULL << CoriumParser::OCT_LITERAL)
      | (1ULL << CoriumParser::BINARY_LITERAL))) != 0))) {
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

tree::TerminalNode* CoriumParser::FloatLiteralContext::FLOAT_LITERAL() {
  return getToken(CoriumParser::FLOAT_LITERAL, 0);
}

tree::TerminalNode* CoriumParser::FloatLiteralContext::HEX_FLOAT_LITERAL() {
  return getToken(CoriumParser::HEX_FLOAT_LITERAL, 0);
}


size_t CoriumParser::FloatLiteralContext::getRuleIndex() const {
  return CoriumParser::RuleFloatLiteral;
}

void CoriumParser::FloatLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFloatLiteral(this);
}

void CoriumParser::FloatLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFloatLiteral(this);
}

CoriumParser::FloatLiteralContext* CoriumParser::floatLiteral() {
  FloatLiteralContext *_localctx = _tracker.createInstance<FloatLiteralContext>(_ctx, getState());
  enterRule(_localctx, 98, CoriumParser::RuleFloatLiteral);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(703);
    _la = _input->LA(1);
    if (!(_la == CoriumParser::FLOAT_LITERAL

    || _la == CoriumParser::HEX_FLOAT_LITERAL)) {
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

//----------------- AltAnnotationQualifiedNameContext ------------------------------------------------------------------

CoriumParser::AltAnnotationQualifiedNameContext::AltAnnotationQualifiedNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::AltAnnotationQualifiedNameContext::AT() {
  return getToken(CoriumParser::AT, 0);
}

std::vector<tree::TerminalNode *> CoriumParser::AltAnnotationQualifiedNameContext::IDENTIFIER() {
  return getTokens(CoriumParser::IDENTIFIER);
}

tree::TerminalNode* CoriumParser::AltAnnotationQualifiedNameContext::IDENTIFIER(size_t i) {
  return getToken(CoriumParser::IDENTIFIER, i);
}

std::vector<tree::TerminalNode *> CoriumParser::AltAnnotationQualifiedNameContext::DOT() {
  return getTokens(CoriumParser::DOT);
}

tree::TerminalNode* CoriumParser::AltAnnotationQualifiedNameContext::DOT(size_t i) {
  return getToken(CoriumParser::DOT, i);
}


size_t CoriumParser::AltAnnotationQualifiedNameContext::getRuleIndex() const {
  return CoriumParser::RuleAltAnnotationQualifiedName;
}

void CoriumParser::AltAnnotationQualifiedNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAltAnnotationQualifiedName(this);
}

void CoriumParser::AltAnnotationQualifiedNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAltAnnotationQualifiedName(this);
}

CoriumParser::AltAnnotationQualifiedNameContext* CoriumParser::altAnnotationQualifiedName() {
  AltAnnotationQualifiedNameContext *_localctx = _tracker.createInstance<AltAnnotationQualifiedNameContext>(_ctx, getState());
  enterRule(_localctx, 100, CoriumParser::RuleAltAnnotationQualifiedName);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(709);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CoriumParser::IDENTIFIER) {
      setState(705);
      match(CoriumParser::IDENTIFIER);
      setState(706);
      match(CoriumParser::DOT);
      setState(711);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(712);
    match(CoriumParser::AT);
    setState(713);
    match(CoriumParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AnnotationContext ------------------------------------------------------------------

CoriumParser::AnnotationContext::AnnotationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::AnnotationContext::AT() {
  return getToken(CoriumParser::AT, 0);
}

CoriumParser::QualifiedNameContext* CoriumParser::AnnotationContext::qualifiedName() {
  return getRuleContext<CoriumParser::QualifiedNameContext>(0);
}

CoriumParser::AltAnnotationQualifiedNameContext* CoriumParser::AnnotationContext::altAnnotationQualifiedName() {
  return getRuleContext<CoriumParser::AltAnnotationQualifiedNameContext>(0);
}

tree::TerminalNode* CoriumParser::AnnotationContext::LPAREN() {
  return getToken(CoriumParser::LPAREN, 0);
}

tree::TerminalNode* CoriumParser::AnnotationContext::RPAREN() {
  return getToken(CoriumParser::RPAREN, 0);
}

CoriumParser::ElementValuePairsContext* CoriumParser::AnnotationContext::elementValuePairs() {
  return getRuleContext<CoriumParser::ElementValuePairsContext>(0);
}

CoriumParser::ElementValueContext* CoriumParser::AnnotationContext::elementValue() {
  return getRuleContext<CoriumParser::ElementValueContext>(0);
}


size_t CoriumParser::AnnotationContext::getRuleIndex() const {
  return CoriumParser::RuleAnnotation;
}

void CoriumParser::AnnotationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnnotation(this);
}

void CoriumParser::AnnotationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnnotation(this);
}

CoriumParser::AnnotationContext* CoriumParser::annotation() {
  AnnotationContext *_localctx = _tracker.createInstance<AnnotationContext>(_ctx, getState());
  enterRule(_localctx, 102, CoriumParser::RuleAnnotation);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(718);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 77, _ctx)) {
    case 1: {
      setState(715);
      match(CoriumParser::AT);
      setState(716);
      qualifiedName();
      break;
    }

    case 2: {
      setState(717);
      altAnnotationQualifiedName();
      break;
    }

    }
    setState(726);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CoriumParser::LPAREN) {
      setState(720);
      match(CoriumParser::LPAREN);
      setState(723);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 78, _ctx)) {
      case 1: {
        setState(721);
        elementValuePairs();
        break;
      }

      case 2: {
        setState(722);
        elementValue();
        break;
      }

      }
      setState(725);
      match(CoriumParser::RPAREN);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElementValuePairsContext ------------------------------------------------------------------

CoriumParser::ElementValuePairsContext::ElementValuePairsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CoriumParser::ElementValuePairContext *> CoriumParser::ElementValuePairsContext::elementValuePair() {
  return getRuleContexts<CoriumParser::ElementValuePairContext>();
}

CoriumParser::ElementValuePairContext* CoriumParser::ElementValuePairsContext::elementValuePair(size_t i) {
  return getRuleContext<CoriumParser::ElementValuePairContext>(i);
}

std::vector<tree::TerminalNode *> CoriumParser::ElementValuePairsContext::COMMA() {
  return getTokens(CoriumParser::COMMA);
}

tree::TerminalNode* CoriumParser::ElementValuePairsContext::COMMA(size_t i) {
  return getToken(CoriumParser::COMMA, i);
}


size_t CoriumParser::ElementValuePairsContext::getRuleIndex() const {
  return CoriumParser::RuleElementValuePairs;
}

void CoriumParser::ElementValuePairsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElementValuePairs(this);
}

void CoriumParser::ElementValuePairsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElementValuePairs(this);
}

CoriumParser::ElementValuePairsContext* CoriumParser::elementValuePairs() {
  ElementValuePairsContext *_localctx = _tracker.createInstance<ElementValuePairsContext>(_ctx, getState());
  enterRule(_localctx, 104, CoriumParser::RuleElementValuePairs);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(728);
    elementValuePair();
    setState(733);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CoriumParser::COMMA) {
      setState(729);
      match(CoriumParser::COMMA);
      setState(730);
      elementValuePair();
      setState(735);
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

//----------------- ElementValuePairContext ------------------------------------------------------------------

CoriumParser::ElementValuePairContext::ElementValuePairContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::ElementValuePairContext::IDENTIFIER() {
  return getToken(CoriumParser::IDENTIFIER, 0);
}

tree::TerminalNode* CoriumParser::ElementValuePairContext::ASSIGN() {
  return getToken(CoriumParser::ASSIGN, 0);
}

CoriumParser::ElementValueContext* CoriumParser::ElementValuePairContext::elementValue() {
  return getRuleContext<CoriumParser::ElementValueContext>(0);
}


size_t CoriumParser::ElementValuePairContext::getRuleIndex() const {
  return CoriumParser::RuleElementValuePair;
}

void CoriumParser::ElementValuePairContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElementValuePair(this);
}

void CoriumParser::ElementValuePairContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElementValuePair(this);
}

CoriumParser::ElementValuePairContext* CoriumParser::elementValuePair() {
  ElementValuePairContext *_localctx = _tracker.createInstance<ElementValuePairContext>(_ctx, getState());
  enterRule(_localctx, 106, CoriumParser::RuleElementValuePair);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(736);
    match(CoriumParser::IDENTIFIER);
    setState(737);
    match(CoriumParser::ASSIGN);
    setState(738);
    elementValue();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElementValueContext ------------------------------------------------------------------

CoriumParser::ElementValueContext::ElementValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::ExpressionContext* CoriumParser::ElementValueContext::expression() {
  return getRuleContext<CoriumParser::ExpressionContext>(0);
}

CoriumParser::AnnotationContext* CoriumParser::ElementValueContext::annotation() {
  return getRuleContext<CoriumParser::AnnotationContext>(0);
}

CoriumParser::ElementValueArrayInitializerContext* CoriumParser::ElementValueContext::elementValueArrayInitializer() {
  return getRuleContext<CoriumParser::ElementValueArrayInitializerContext>(0);
}


size_t CoriumParser::ElementValueContext::getRuleIndex() const {
  return CoriumParser::RuleElementValue;
}

void CoriumParser::ElementValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElementValue(this);
}

void CoriumParser::ElementValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElementValue(this);
}

CoriumParser::ElementValueContext* CoriumParser::elementValue() {
  ElementValueContext *_localctx = _tracker.createInstance<ElementValueContext>(_ctx, getState());
  enterRule(_localctx, 108, CoriumParser::RuleElementValue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(743);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 81, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(740);
      expression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(741);
      annotation();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(742);
      elementValueArrayInitializer();
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

//----------------- ElementValueArrayInitializerContext ------------------------------------------------------------------

CoriumParser::ElementValueArrayInitializerContext::ElementValueArrayInitializerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::ElementValueArrayInitializerContext::LBRACE() {
  return getToken(CoriumParser::LBRACE, 0);
}

tree::TerminalNode* CoriumParser::ElementValueArrayInitializerContext::RBRACE() {
  return getToken(CoriumParser::RBRACE, 0);
}

std::vector<CoriumParser::ElementValueContext *> CoriumParser::ElementValueArrayInitializerContext::elementValue() {
  return getRuleContexts<CoriumParser::ElementValueContext>();
}

CoriumParser::ElementValueContext* CoriumParser::ElementValueArrayInitializerContext::elementValue(size_t i) {
  return getRuleContext<CoriumParser::ElementValueContext>(i);
}

std::vector<tree::TerminalNode *> CoriumParser::ElementValueArrayInitializerContext::COMMA() {
  return getTokens(CoriumParser::COMMA);
}

tree::TerminalNode* CoriumParser::ElementValueArrayInitializerContext::COMMA(size_t i) {
  return getToken(CoriumParser::COMMA, i);
}


size_t CoriumParser::ElementValueArrayInitializerContext::getRuleIndex() const {
  return CoriumParser::RuleElementValueArrayInitializer;
}

void CoriumParser::ElementValueArrayInitializerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElementValueArrayInitializer(this);
}

void CoriumParser::ElementValueArrayInitializerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElementValueArrayInitializer(this);
}

CoriumParser::ElementValueArrayInitializerContext* CoriumParser::elementValueArrayInitializer() {
  ElementValueArrayInitializerContext *_localctx = _tracker.createInstance<ElementValueArrayInitializerContext>(_ctx, getState());
  enterRule(_localctx, 110, CoriumParser::RuleElementValueArrayInitializer);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(745);
    match(CoriumParser::LBRACE);
    setState(754);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CoriumParser::BOOLEAN)
      | (1ULL << CoriumParser::BYTE)
      | (1ULL << CoriumParser::CHAR)
      | (1ULL << CoriumParser::DOUBLE)
      | (1ULL << CoriumParser::FLOAT)
      | (1ULL << CoriumParser::INT)
      | (1ULL << CoriumParser::LONG)
      | (1ULL << CoriumParser::NEW)
      | (1ULL << CoriumParser::SHORT)
      | (1ULL << CoriumParser::SUPER)
      | (1ULL << CoriumParser::THIS)
      | (1ULL << CoriumParser::VOID)
      | (1ULL << CoriumParser::DECIMAL_LITERAL)
      | (1ULL << CoriumParser::HEX_LITERAL)
      | (1ULL << CoriumParser::OCT_LITERAL)
      | (1ULL << CoriumParser::BINARY_LITERAL)
      | (1ULL << CoriumParser::FLOAT_LITERAL)
      | (1ULL << CoriumParser::HEX_FLOAT_LITERAL)
      | (1ULL << CoriumParser::BOOL_LITERAL)
      | (1ULL << CoriumParser::CHAR_LITERAL)
      | (1ULL << CoriumParser::STRING_LITERAL)
      | (1ULL << CoriumParser::NULL_LITERAL)
      | (1ULL << CoriumParser::LPAREN)
      | (1ULL << CoriumParser::LBRACE))) != 0) || ((((_la - 72) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 72)) & ((1ULL << (CoriumParser::LT - 72))
      | (1ULL << (CoriumParser::BANG - 72))
      | (1ULL << (CoriumParser::TILDE - 72))
      | (1ULL << (CoriumParser::INC - 72))
      | (1ULL << (CoriumParser::DEC - 72))
      | (1ULL << (CoriumParser::ADD - 72))
      | (1ULL << (CoriumParser::SUB - 72))
      | (1ULL << (CoriumParser::AT - 72))
      | (1ULL << (CoriumParser::IDENTIFIER - 72)))) != 0)) {
      setState(746);
      elementValue();
      setState(751);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 82, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(747);
          match(CoriumParser::COMMA);
          setState(748);
          elementValue(); 
        }
        setState(753);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 82, _ctx);
      }
    }
    setState(757);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CoriumParser::COMMA) {
      setState(756);
      match(CoriumParser::COMMA);
    }
    setState(759);
    match(CoriumParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AnnotationTypeDeclarationContext ------------------------------------------------------------------

CoriumParser::AnnotationTypeDeclarationContext::AnnotationTypeDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::AnnotationTypeDeclarationContext::AT() {
  return getToken(CoriumParser::AT, 0);
}

tree::TerminalNode* CoriumParser::AnnotationTypeDeclarationContext::INTERFACE() {
  return getToken(CoriumParser::INTERFACE, 0);
}

tree::TerminalNode* CoriumParser::AnnotationTypeDeclarationContext::IDENTIFIER() {
  return getToken(CoriumParser::IDENTIFIER, 0);
}

CoriumParser::AnnotationTypeBodyContext* CoriumParser::AnnotationTypeDeclarationContext::annotationTypeBody() {
  return getRuleContext<CoriumParser::AnnotationTypeBodyContext>(0);
}


size_t CoriumParser::AnnotationTypeDeclarationContext::getRuleIndex() const {
  return CoriumParser::RuleAnnotationTypeDeclaration;
}

void CoriumParser::AnnotationTypeDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnnotationTypeDeclaration(this);
}

void CoriumParser::AnnotationTypeDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnnotationTypeDeclaration(this);
}

CoriumParser::AnnotationTypeDeclarationContext* CoriumParser::annotationTypeDeclaration() {
  AnnotationTypeDeclarationContext *_localctx = _tracker.createInstance<AnnotationTypeDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 112, CoriumParser::RuleAnnotationTypeDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(761);
    match(CoriumParser::AT);
    setState(762);
    match(CoriumParser::INTERFACE);
    setState(763);
    match(CoriumParser::IDENTIFIER);
    setState(764);
    annotationTypeBody();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AnnotationTypeBodyContext ------------------------------------------------------------------

CoriumParser::AnnotationTypeBodyContext::AnnotationTypeBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::AnnotationTypeBodyContext::LBRACE() {
  return getToken(CoriumParser::LBRACE, 0);
}

tree::TerminalNode* CoriumParser::AnnotationTypeBodyContext::RBRACE() {
  return getToken(CoriumParser::RBRACE, 0);
}

std::vector<CoriumParser::AnnotationTypeElementDeclarationContext *> CoriumParser::AnnotationTypeBodyContext::annotationTypeElementDeclaration() {
  return getRuleContexts<CoriumParser::AnnotationTypeElementDeclarationContext>();
}

CoriumParser::AnnotationTypeElementDeclarationContext* CoriumParser::AnnotationTypeBodyContext::annotationTypeElementDeclaration(size_t i) {
  return getRuleContext<CoriumParser::AnnotationTypeElementDeclarationContext>(i);
}


size_t CoriumParser::AnnotationTypeBodyContext::getRuleIndex() const {
  return CoriumParser::RuleAnnotationTypeBody;
}

void CoriumParser::AnnotationTypeBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnnotationTypeBody(this);
}

void CoriumParser::AnnotationTypeBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnnotationTypeBody(this);
}

CoriumParser::AnnotationTypeBodyContext* CoriumParser::annotationTypeBody() {
  AnnotationTypeBodyContext *_localctx = _tracker.createInstance<AnnotationTypeBodyContext>(_ctx, getState());
  enterRule(_localctx, 114, CoriumParser::RuleAnnotationTypeBody);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(766);
    match(CoriumParser::LBRACE);
    setState(770);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CoriumParser::ABSTRACT)
      | (1ULL << CoriumParser::BOOLEAN)
      | (1ULL << CoriumParser::BYTE)
      | (1ULL << CoriumParser::CHAR)
      | (1ULL << CoriumParser::CLASS)
      | (1ULL << CoriumParser::DOUBLE)
      | (1ULL << CoriumParser::ENUM)
      | (1ULL << CoriumParser::FINAL)
      | (1ULL << CoriumParser::FLOAT)
      | (1ULL << CoriumParser::INT)
      | (1ULL << CoriumParser::INTERFACE)
      | (1ULL << CoriumParser::LONG)
      | (1ULL << CoriumParser::NATIVE)
      | (1ULL << CoriumParser::PRIVATE)
      | (1ULL << CoriumParser::PROTECTED)
      | (1ULL << CoriumParser::PUBLIC)
      | (1ULL << CoriumParser::SHORT)
      | (1ULL << CoriumParser::STATIC)
      | (1ULL << CoriumParser::STRICTFP)
      | (1ULL << CoriumParser::SYNCHRONIZED)
      | (1ULL << CoriumParser::TRANSIENT)
      | (1ULL << CoriumParser::VOLATILE))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & ((1ULL << (CoriumParser::SEMI - 67))
      | (1ULL << (CoriumParser::AT - 67))
      | (1ULL << (CoriumParser::IDENTIFIER - 67)))) != 0)) {
      setState(767);
      annotationTypeElementDeclaration();
      setState(772);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(773);
    match(CoriumParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AnnotationTypeElementDeclarationContext ------------------------------------------------------------------

CoriumParser::AnnotationTypeElementDeclarationContext::AnnotationTypeElementDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::AnnotationTypeElementRestContext* CoriumParser::AnnotationTypeElementDeclarationContext::annotationTypeElementRest() {
  return getRuleContext<CoriumParser::AnnotationTypeElementRestContext>(0);
}

std::vector<CoriumParser::ModifierContext *> CoriumParser::AnnotationTypeElementDeclarationContext::modifier() {
  return getRuleContexts<CoriumParser::ModifierContext>();
}

CoriumParser::ModifierContext* CoriumParser::AnnotationTypeElementDeclarationContext::modifier(size_t i) {
  return getRuleContext<CoriumParser::ModifierContext>(i);
}

tree::TerminalNode* CoriumParser::AnnotationTypeElementDeclarationContext::SEMI() {
  return getToken(CoriumParser::SEMI, 0);
}


size_t CoriumParser::AnnotationTypeElementDeclarationContext::getRuleIndex() const {
  return CoriumParser::RuleAnnotationTypeElementDeclaration;
}

void CoriumParser::AnnotationTypeElementDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnnotationTypeElementDeclaration(this);
}

void CoriumParser::AnnotationTypeElementDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnnotationTypeElementDeclaration(this);
}

CoriumParser::AnnotationTypeElementDeclarationContext* CoriumParser::annotationTypeElementDeclaration() {
  AnnotationTypeElementDeclarationContext *_localctx = _tracker.createInstance<AnnotationTypeElementDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 116, CoriumParser::RuleAnnotationTypeElementDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(783);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CoriumParser::ABSTRACT:
      case CoriumParser::BOOLEAN:
      case CoriumParser::BYTE:
      case CoriumParser::CHAR:
      case CoriumParser::CLASS:
      case CoriumParser::DOUBLE:
      case CoriumParser::ENUM:
      case CoriumParser::FINAL:
      case CoriumParser::FLOAT:
      case CoriumParser::INT:
      case CoriumParser::INTERFACE:
      case CoriumParser::LONG:
      case CoriumParser::NATIVE:
      case CoriumParser::PRIVATE:
      case CoriumParser::PROTECTED:
      case CoriumParser::PUBLIC:
      case CoriumParser::SHORT:
      case CoriumParser::STATIC:
      case CoriumParser::STRICTFP:
      case CoriumParser::SYNCHRONIZED:
      case CoriumParser::TRANSIENT:
      case CoriumParser::VOLATILE:
      case CoriumParser::AT:
      case CoriumParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(778);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 86, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(775);
            modifier(); 
          }
          setState(780);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 86, _ctx);
        }
        setState(781);
        annotationTypeElementRest();
        break;
      }

      case CoriumParser::SEMI: {
        enterOuterAlt(_localctx, 2);
        setState(782);
        match(CoriumParser::SEMI);
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

//----------------- AnnotationTypeElementRestContext ------------------------------------------------------------------

CoriumParser::AnnotationTypeElementRestContext::AnnotationTypeElementRestContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::TypeTypeContext* CoriumParser::AnnotationTypeElementRestContext::typeType() {
  return getRuleContext<CoriumParser::TypeTypeContext>(0);
}

CoriumParser::AnnotationMethodOrConstantRestContext* CoriumParser::AnnotationTypeElementRestContext::annotationMethodOrConstantRest() {
  return getRuleContext<CoriumParser::AnnotationMethodOrConstantRestContext>(0);
}

tree::TerminalNode* CoriumParser::AnnotationTypeElementRestContext::SEMI() {
  return getToken(CoriumParser::SEMI, 0);
}

CoriumParser::ClassDeclarationContext* CoriumParser::AnnotationTypeElementRestContext::classDeclaration() {
  return getRuleContext<CoriumParser::ClassDeclarationContext>(0);
}

CoriumParser::InterfaceDeclarationContext* CoriumParser::AnnotationTypeElementRestContext::interfaceDeclaration() {
  return getRuleContext<CoriumParser::InterfaceDeclarationContext>(0);
}

CoriumParser::EnumDeclarationContext* CoriumParser::AnnotationTypeElementRestContext::enumDeclaration() {
  return getRuleContext<CoriumParser::EnumDeclarationContext>(0);
}

CoriumParser::AnnotationTypeDeclarationContext* CoriumParser::AnnotationTypeElementRestContext::annotationTypeDeclaration() {
  return getRuleContext<CoriumParser::AnnotationTypeDeclarationContext>(0);
}


size_t CoriumParser::AnnotationTypeElementRestContext::getRuleIndex() const {
  return CoriumParser::RuleAnnotationTypeElementRest;
}

void CoriumParser::AnnotationTypeElementRestContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnnotationTypeElementRest(this);
}

void CoriumParser::AnnotationTypeElementRestContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnnotationTypeElementRest(this);
}

CoriumParser::AnnotationTypeElementRestContext* CoriumParser::annotationTypeElementRest() {
  AnnotationTypeElementRestContext *_localctx = _tracker.createInstance<AnnotationTypeElementRestContext>(_ctx, getState());
  enterRule(_localctx, 118, CoriumParser::RuleAnnotationTypeElementRest);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(805);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 92, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(785);
      typeType();
      setState(786);
      annotationMethodOrConstantRest();
      setState(787);
      match(CoriumParser::SEMI);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(789);
      classDeclaration();
      setState(791);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 88, _ctx)) {
      case 1: {
        setState(790);
        match(CoriumParser::SEMI);
        break;
      }

      }
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(793);
      interfaceDeclaration();
      setState(795);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 89, _ctx)) {
      case 1: {
        setState(794);
        match(CoriumParser::SEMI);
        break;
      }

      }
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(797);
      enumDeclaration();
      setState(799);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 90, _ctx)) {
      case 1: {
        setState(798);
        match(CoriumParser::SEMI);
        break;
      }

      }
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(801);
      annotationTypeDeclaration();
      setState(803);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 91, _ctx)) {
      case 1: {
        setState(802);
        match(CoriumParser::SEMI);
        break;
      }

      }
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

//----------------- AnnotationMethodOrConstantRestContext ------------------------------------------------------------------

CoriumParser::AnnotationMethodOrConstantRestContext::AnnotationMethodOrConstantRestContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::AnnotationMethodRestContext* CoriumParser::AnnotationMethodOrConstantRestContext::annotationMethodRest() {
  return getRuleContext<CoriumParser::AnnotationMethodRestContext>(0);
}

CoriumParser::AnnotationConstantRestContext* CoriumParser::AnnotationMethodOrConstantRestContext::annotationConstantRest() {
  return getRuleContext<CoriumParser::AnnotationConstantRestContext>(0);
}


size_t CoriumParser::AnnotationMethodOrConstantRestContext::getRuleIndex() const {
  return CoriumParser::RuleAnnotationMethodOrConstantRest;
}

void CoriumParser::AnnotationMethodOrConstantRestContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnnotationMethodOrConstantRest(this);
}

void CoriumParser::AnnotationMethodOrConstantRestContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnnotationMethodOrConstantRest(this);
}

CoriumParser::AnnotationMethodOrConstantRestContext* CoriumParser::annotationMethodOrConstantRest() {
  AnnotationMethodOrConstantRestContext *_localctx = _tracker.createInstance<AnnotationMethodOrConstantRestContext>(_ctx, getState());
  enterRule(_localctx, 120, CoriumParser::RuleAnnotationMethodOrConstantRest);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(809);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 93, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(807);
      annotationMethodRest();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(808);
      annotationConstantRest();
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

//----------------- AnnotationMethodRestContext ------------------------------------------------------------------

CoriumParser::AnnotationMethodRestContext::AnnotationMethodRestContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::AnnotationMethodRestContext::IDENTIFIER() {
  return getToken(CoriumParser::IDENTIFIER, 0);
}

tree::TerminalNode* CoriumParser::AnnotationMethodRestContext::LPAREN() {
  return getToken(CoriumParser::LPAREN, 0);
}

tree::TerminalNode* CoriumParser::AnnotationMethodRestContext::RPAREN() {
  return getToken(CoriumParser::RPAREN, 0);
}

CoriumParser::DefaultValueContext* CoriumParser::AnnotationMethodRestContext::defaultValue() {
  return getRuleContext<CoriumParser::DefaultValueContext>(0);
}


size_t CoriumParser::AnnotationMethodRestContext::getRuleIndex() const {
  return CoriumParser::RuleAnnotationMethodRest;
}

void CoriumParser::AnnotationMethodRestContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnnotationMethodRest(this);
}

void CoriumParser::AnnotationMethodRestContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnnotationMethodRest(this);
}

CoriumParser::AnnotationMethodRestContext* CoriumParser::annotationMethodRest() {
  AnnotationMethodRestContext *_localctx = _tracker.createInstance<AnnotationMethodRestContext>(_ctx, getState());
  enterRule(_localctx, 122, CoriumParser::RuleAnnotationMethodRest);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(811);
    match(CoriumParser::IDENTIFIER);
    setState(812);
    match(CoriumParser::LPAREN);
    setState(813);
    match(CoriumParser::RPAREN);
    setState(815);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CoriumParser::DEFAULT) {
      setState(814);
      defaultValue();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AnnotationConstantRestContext ------------------------------------------------------------------

CoriumParser::AnnotationConstantRestContext::AnnotationConstantRestContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::VariableDeclaratorsContext* CoriumParser::AnnotationConstantRestContext::variableDeclarators() {
  return getRuleContext<CoriumParser::VariableDeclaratorsContext>(0);
}


size_t CoriumParser::AnnotationConstantRestContext::getRuleIndex() const {
  return CoriumParser::RuleAnnotationConstantRest;
}

void CoriumParser::AnnotationConstantRestContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnnotationConstantRest(this);
}

void CoriumParser::AnnotationConstantRestContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnnotationConstantRest(this);
}

CoriumParser::AnnotationConstantRestContext* CoriumParser::annotationConstantRest() {
  AnnotationConstantRestContext *_localctx = _tracker.createInstance<AnnotationConstantRestContext>(_ctx, getState());
  enterRule(_localctx, 124, CoriumParser::RuleAnnotationConstantRest);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(817);
    variableDeclarators();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefaultValueContext ------------------------------------------------------------------

CoriumParser::DefaultValueContext::DefaultValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::DefaultValueContext::DEFAULT() {
  return getToken(CoriumParser::DEFAULT, 0);
}

CoriumParser::ElementValueContext* CoriumParser::DefaultValueContext::elementValue() {
  return getRuleContext<CoriumParser::ElementValueContext>(0);
}


size_t CoriumParser::DefaultValueContext::getRuleIndex() const {
  return CoriumParser::RuleDefaultValue;
}

void CoriumParser::DefaultValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDefaultValue(this);
}

void CoriumParser::DefaultValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDefaultValue(this);
}

CoriumParser::DefaultValueContext* CoriumParser::defaultValue() {
  DefaultValueContext *_localctx = _tracker.createInstance<DefaultValueContext>(_ctx, getState());
  enterRule(_localctx, 126, CoriumParser::RuleDefaultValue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(819);
    match(CoriumParser::DEFAULT);
    setState(820);
    elementValue();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

CoriumParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::BlockContext::LBRACE() {
  return getToken(CoriumParser::LBRACE, 0);
}

tree::TerminalNode* CoriumParser::BlockContext::RBRACE() {
  return getToken(CoriumParser::RBRACE, 0);
}

std::vector<CoriumParser::BlockStatementContext *> CoriumParser::BlockContext::blockStatement() {
  return getRuleContexts<CoriumParser::BlockStatementContext>();
}

CoriumParser::BlockStatementContext* CoriumParser::BlockContext::blockStatement(size_t i) {
  return getRuleContext<CoriumParser::BlockStatementContext>(i);
}


size_t CoriumParser::BlockContext::getRuleIndex() const {
  return CoriumParser::RuleBlock;
}

void CoriumParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void CoriumParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}

CoriumParser::BlockContext* CoriumParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 128, CoriumParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(822);
    match(CoriumParser::LBRACE);
    setState(826);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CoriumParser::ABSTRACT)
      | (1ULL << CoriumParser::ASSERT)
      | (1ULL << CoriumParser::BOOLEAN)
      | (1ULL << CoriumParser::BREAK)
      | (1ULL << CoriumParser::BYTE)
      | (1ULL << CoriumParser::CHAR)
      | (1ULL << CoriumParser::CLASS)
      | (1ULL << CoriumParser::CONTINUE)
      | (1ULL << CoriumParser::DO)
      | (1ULL << CoriumParser::DOUBLE)
      | (1ULL << CoriumParser::FINAL)
      | (1ULL << CoriumParser::FLOAT)
      | (1ULL << CoriumParser::FOR)
      | (1ULL << CoriumParser::IF)
      | (1ULL << CoriumParser::INT)
      | (1ULL << CoriumParser::INTERFACE)
      | (1ULL << CoriumParser::LONG)
      | (1ULL << CoriumParser::NEW)
      | (1ULL << CoriumParser::PRIVATE)
      | (1ULL << CoriumParser::PROTECTED)
      | (1ULL << CoriumParser::PUBLIC)
      | (1ULL << CoriumParser::RETURN)
      | (1ULL << CoriumParser::SHORT)
      | (1ULL << CoriumParser::STATIC)
      | (1ULL << CoriumParser::STRICTFP)
      | (1ULL << CoriumParser::SUPER)
      | (1ULL << CoriumParser::SWITCH)
      | (1ULL << CoriumParser::SYNCHRONIZED)
      | (1ULL << CoriumParser::THIS)
      | (1ULL << CoriumParser::THROW)
      | (1ULL << CoriumParser::TRY)
      | (1ULL << CoriumParser::VOID)
      | (1ULL << CoriumParser::WHILE)
      | (1ULL << CoriumParser::DECIMAL_LITERAL)
      | (1ULL << CoriumParser::HEX_LITERAL)
      | (1ULL << CoriumParser::OCT_LITERAL)
      | (1ULL << CoriumParser::BINARY_LITERAL)
      | (1ULL << CoriumParser::FLOAT_LITERAL)
      | (1ULL << CoriumParser::HEX_FLOAT_LITERAL)
      | (1ULL << CoriumParser::BOOL_LITERAL)
      | (1ULL << CoriumParser::CHAR_LITERAL)
      | (1ULL << CoriumParser::STRING_LITERAL)
      | (1ULL << CoriumParser::NULL_LITERAL)
      | (1ULL << CoriumParser::LPAREN)
      | (1ULL << CoriumParser::LBRACE))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & ((1ULL << (CoriumParser::SEMI - 67))
      | (1ULL << (CoriumParser::LT - 67))
      | (1ULL << (CoriumParser::BANG - 67))
      | (1ULL << (CoriumParser::TILDE - 67))
      | (1ULL << (CoriumParser::INC - 67))
      | (1ULL << (CoriumParser::DEC - 67))
      | (1ULL << (CoriumParser::ADD - 67))
      | (1ULL << (CoriumParser::SUB - 67))
      | (1ULL << (CoriumParser::AT - 67))
      | (1ULL << (CoriumParser::IDENTIFIER - 67)))) != 0)) {
      setState(823);
      blockStatement();
      setState(828);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(829);
    match(CoriumParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockStatementContext ------------------------------------------------------------------

CoriumParser::BlockStatementContext::BlockStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::LocalVariableDeclarationContext* CoriumParser::BlockStatementContext::localVariableDeclaration() {
  return getRuleContext<CoriumParser::LocalVariableDeclarationContext>(0);
}

tree::TerminalNode* CoriumParser::BlockStatementContext::SEMI() {
  return getToken(CoriumParser::SEMI, 0);
}

CoriumParser::StatementContext* CoriumParser::BlockStatementContext::statement() {
  return getRuleContext<CoriumParser::StatementContext>(0);
}

CoriumParser::LocalTypeDeclarationContext* CoriumParser::BlockStatementContext::localTypeDeclaration() {
  return getRuleContext<CoriumParser::LocalTypeDeclarationContext>(0);
}


size_t CoriumParser::BlockStatementContext::getRuleIndex() const {
  return CoriumParser::RuleBlockStatement;
}

void CoriumParser::BlockStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockStatement(this);
}

void CoriumParser::BlockStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockStatement(this);
}

CoriumParser::BlockStatementContext* CoriumParser::blockStatement() {
  BlockStatementContext *_localctx = _tracker.createInstance<BlockStatementContext>(_ctx, getState());
  enterRule(_localctx, 130, CoriumParser::RuleBlockStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(836);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 96, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(831);
      localVariableDeclaration();
      setState(832);
      match(CoriumParser::SEMI);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(834);
      statement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(835);
      localTypeDeclaration();
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

//----------------- LocalVariableDeclarationContext ------------------------------------------------------------------

CoriumParser::LocalVariableDeclarationContext::LocalVariableDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::TypeTypeContext* CoriumParser::LocalVariableDeclarationContext::typeType() {
  return getRuleContext<CoriumParser::TypeTypeContext>(0);
}

CoriumParser::VariableDeclaratorsContext* CoriumParser::LocalVariableDeclarationContext::variableDeclarators() {
  return getRuleContext<CoriumParser::VariableDeclaratorsContext>(0);
}

std::vector<CoriumParser::VariableModifierContext *> CoriumParser::LocalVariableDeclarationContext::variableModifier() {
  return getRuleContexts<CoriumParser::VariableModifierContext>();
}

CoriumParser::VariableModifierContext* CoriumParser::LocalVariableDeclarationContext::variableModifier(size_t i) {
  return getRuleContext<CoriumParser::VariableModifierContext>(i);
}


size_t CoriumParser::LocalVariableDeclarationContext::getRuleIndex() const {
  return CoriumParser::RuleLocalVariableDeclaration;
}

void CoriumParser::LocalVariableDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLocalVariableDeclaration(this);
}

void CoriumParser::LocalVariableDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLocalVariableDeclaration(this);
}

CoriumParser::LocalVariableDeclarationContext* CoriumParser::localVariableDeclaration() {
  LocalVariableDeclarationContext *_localctx = _tracker.createInstance<LocalVariableDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 132, CoriumParser::RuleLocalVariableDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(841);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 97, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(838);
        variableModifier(); 
      }
      setState(843);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 97, _ctx);
    }
    setState(844);
    typeType();
    setState(845);
    variableDeclarators();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LocalTypeDeclarationContext ------------------------------------------------------------------

CoriumParser::LocalTypeDeclarationContext::LocalTypeDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::ClassDeclarationContext* CoriumParser::LocalTypeDeclarationContext::classDeclaration() {
  return getRuleContext<CoriumParser::ClassDeclarationContext>(0);
}

CoriumParser::InterfaceDeclarationContext* CoriumParser::LocalTypeDeclarationContext::interfaceDeclaration() {
  return getRuleContext<CoriumParser::InterfaceDeclarationContext>(0);
}

std::vector<CoriumParser::ClassOrInterfaceModifierContext *> CoriumParser::LocalTypeDeclarationContext::classOrInterfaceModifier() {
  return getRuleContexts<CoriumParser::ClassOrInterfaceModifierContext>();
}

CoriumParser::ClassOrInterfaceModifierContext* CoriumParser::LocalTypeDeclarationContext::classOrInterfaceModifier(size_t i) {
  return getRuleContext<CoriumParser::ClassOrInterfaceModifierContext>(i);
}

tree::TerminalNode* CoriumParser::LocalTypeDeclarationContext::SEMI() {
  return getToken(CoriumParser::SEMI, 0);
}


size_t CoriumParser::LocalTypeDeclarationContext::getRuleIndex() const {
  return CoriumParser::RuleLocalTypeDeclaration;
}

void CoriumParser::LocalTypeDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLocalTypeDeclaration(this);
}

void CoriumParser::LocalTypeDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLocalTypeDeclaration(this);
}

CoriumParser::LocalTypeDeclarationContext* CoriumParser::localTypeDeclaration() {
  LocalTypeDeclarationContext *_localctx = _tracker.createInstance<LocalTypeDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 134, CoriumParser::RuleLocalTypeDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(858);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CoriumParser::ABSTRACT:
      case CoriumParser::CLASS:
      case CoriumParser::FINAL:
      case CoriumParser::INTERFACE:
      case CoriumParser::PRIVATE:
      case CoriumParser::PROTECTED:
      case CoriumParser::PUBLIC:
      case CoriumParser::STATIC:
      case CoriumParser::STRICTFP:
      case CoriumParser::AT:
      case CoriumParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(850);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CoriumParser::ABSTRACT)
          | (1ULL << CoriumParser::FINAL)
          | (1ULL << CoriumParser::PRIVATE)
          | (1ULL << CoriumParser::PROTECTED)
          | (1ULL << CoriumParser::PUBLIC)
          | (1ULL << CoriumParser::STATIC)
          | (1ULL << CoriumParser::STRICTFP))) != 0) || _la == CoriumParser::AT

        || _la == CoriumParser::IDENTIFIER) {
          setState(847);
          classOrInterfaceModifier();
          setState(852);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(855);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case CoriumParser::CLASS: {
            setState(853);
            classDeclaration();
            break;
          }

          case CoriumParser::INTERFACE: {
            setState(854);
            interfaceDeclaration();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        break;
      }

      case CoriumParser::SEMI: {
        enterOuterAlt(_localctx, 2);
        setState(857);
        match(CoriumParser::SEMI);
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

//----------------- StatementContext ------------------------------------------------------------------

CoriumParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::BlockContext* CoriumParser::StatementContext::block() {
  return getRuleContext<CoriumParser::BlockContext>(0);
}

tree::TerminalNode* CoriumParser::StatementContext::ASSERT() {
  return getToken(CoriumParser::ASSERT, 0);
}

std::vector<CoriumParser::ExpressionContext *> CoriumParser::StatementContext::expression() {
  return getRuleContexts<CoriumParser::ExpressionContext>();
}

CoriumParser::ExpressionContext* CoriumParser::StatementContext::expression(size_t i) {
  return getRuleContext<CoriumParser::ExpressionContext>(i);
}

tree::TerminalNode* CoriumParser::StatementContext::SEMI() {
  return getToken(CoriumParser::SEMI, 0);
}

tree::TerminalNode* CoriumParser::StatementContext::COLON() {
  return getToken(CoriumParser::COLON, 0);
}

tree::TerminalNode* CoriumParser::StatementContext::IF() {
  return getToken(CoriumParser::IF, 0);
}

CoriumParser::ParExpressionContext* CoriumParser::StatementContext::parExpression() {
  return getRuleContext<CoriumParser::ParExpressionContext>(0);
}

std::vector<CoriumParser::StatementContext *> CoriumParser::StatementContext::statement() {
  return getRuleContexts<CoriumParser::StatementContext>();
}

CoriumParser::StatementContext* CoriumParser::StatementContext::statement(size_t i) {
  return getRuleContext<CoriumParser::StatementContext>(i);
}

tree::TerminalNode* CoriumParser::StatementContext::ELSE() {
  return getToken(CoriumParser::ELSE, 0);
}

tree::TerminalNode* CoriumParser::StatementContext::FOR() {
  return getToken(CoriumParser::FOR, 0);
}

tree::TerminalNode* CoriumParser::StatementContext::LPAREN() {
  return getToken(CoriumParser::LPAREN, 0);
}

CoriumParser::ForControlContext* CoriumParser::StatementContext::forControl() {
  return getRuleContext<CoriumParser::ForControlContext>(0);
}

tree::TerminalNode* CoriumParser::StatementContext::RPAREN() {
  return getToken(CoriumParser::RPAREN, 0);
}

tree::TerminalNode* CoriumParser::StatementContext::WHILE() {
  return getToken(CoriumParser::WHILE, 0);
}

tree::TerminalNode* CoriumParser::StatementContext::DO() {
  return getToken(CoriumParser::DO, 0);
}

tree::TerminalNode* CoriumParser::StatementContext::TRY() {
  return getToken(CoriumParser::TRY, 0);
}

CoriumParser::FinallyBlockContext* CoriumParser::StatementContext::finallyBlock() {
  return getRuleContext<CoriumParser::FinallyBlockContext>(0);
}

std::vector<CoriumParser::CatchClauseContext *> CoriumParser::StatementContext::catchClause() {
  return getRuleContexts<CoriumParser::CatchClauseContext>();
}

CoriumParser::CatchClauseContext* CoriumParser::StatementContext::catchClause(size_t i) {
  return getRuleContext<CoriumParser::CatchClauseContext>(i);
}

CoriumParser::ResourceSpecificationContext* CoriumParser::StatementContext::resourceSpecification() {
  return getRuleContext<CoriumParser::ResourceSpecificationContext>(0);
}

tree::TerminalNode* CoriumParser::StatementContext::SWITCH() {
  return getToken(CoriumParser::SWITCH, 0);
}

tree::TerminalNode* CoriumParser::StatementContext::LBRACE() {
  return getToken(CoriumParser::LBRACE, 0);
}

tree::TerminalNode* CoriumParser::StatementContext::RBRACE() {
  return getToken(CoriumParser::RBRACE, 0);
}

std::vector<CoriumParser::SwitchBlockStatementGroupContext *> CoriumParser::StatementContext::switchBlockStatementGroup() {
  return getRuleContexts<CoriumParser::SwitchBlockStatementGroupContext>();
}

CoriumParser::SwitchBlockStatementGroupContext* CoriumParser::StatementContext::switchBlockStatementGroup(size_t i) {
  return getRuleContext<CoriumParser::SwitchBlockStatementGroupContext>(i);
}

std::vector<CoriumParser::SwitchLabelContext *> CoriumParser::StatementContext::switchLabel() {
  return getRuleContexts<CoriumParser::SwitchLabelContext>();
}

CoriumParser::SwitchLabelContext* CoriumParser::StatementContext::switchLabel(size_t i) {
  return getRuleContext<CoriumParser::SwitchLabelContext>(i);
}

tree::TerminalNode* CoriumParser::StatementContext::SYNCHRONIZED() {
  return getToken(CoriumParser::SYNCHRONIZED, 0);
}

tree::TerminalNode* CoriumParser::StatementContext::RETURN() {
  return getToken(CoriumParser::RETURN, 0);
}

tree::TerminalNode* CoriumParser::StatementContext::THROW() {
  return getToken(CoriumParser::THROW, 0);
}

tree::TerminalNode* CoriumParser::StatementContext::BREAK() {
  return getToken(CoriumParser::BREAK, 0);
}

tree::TerminalNode* CoriumParser::StatementContext::IDENTIFIER() {
  return getToken(CoriumParser::IDENTIFIER, 0);
}

tree::TerminalNode* CoriumParser::StatementContext::CONTINUE() {
  return getToken(CoriumParser::CONTINUE, 0);
}


size_t CoriumParser::StatementContext::getRuleIndex() const {
  return CoriumParser::RuleStatement;
}

void CoriumParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void CoriumParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}

CoriumParser::StatementContext* CoriumParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 136, CoriumParser::RuleStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(964);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 113, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(860);
      dynamic_cast<StatementContext *>(_localctx)->blockLabel = block();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(861);
      match(CoriumParser::ASSERT);
      setState(862);
      expression(0);
      setState(865);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CoriumParser::COLON) {
        setState(863);
        match(CoriumParser::COLON);
        setState(864);
        expression(0);
      }
      setState(867);
      match(CoriumParser::SEMI);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(869);
      match(CoriumParser::IF);
      setState(870);
      parExpression();
      setState(871);
      statement();
      setState(874);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 102, _ctx)) {
      case 1: {
        setState(872);
        match(CoriumParser::ELSE);
        setState(873);
        statement();
        break;
      }

      }
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(876);
      match(CoriumParser::FOR);
      setState(877);
      match(CoriumParser::LPAREN);
      setState(878);
      forControl();
      setState(879);
      match(CoriumParser::RPAREN);
      setState(880);
      statement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(882);
      match(CoriumParser::WHILE);
      setState(883);
      parExpression();
      setState(884);
      statement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(886);
      match(CoriumParser::DO);
      setState(887);
      statement();
      setState(888);
      match(CoriumParser::WHILE);
      setState(889);
      parExpression();
      setState(890);
      match(CoriumParser::SEMI);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(892);
      match(CoriumParser::TRY);
      setState(893);
      block();
      setState(903);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case CoriumParser::CATCH: {
          setState(895); 
          _errHandler->sync(this);
          _la = _input->LA(1);
          do {
            setState(894);
            catchClause();
            setState(897); 
            _errHandler->sync(this);
            _la = _input->LA(1);
          } while (_la == CoriumParser::CATCH);
          setState(900);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CoriumParser::FINALLY) {
            setState(899);
            finallyBlock();
          }
          break;
        }

        case CoriumParser::FINALLY: {
          setState(902);
          finallyBlock();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(905);
      match(CoriumParser::TRY);
      setState(906);
      resourceSpecification();
      setState(907);
      block();
      setState(911);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CoriumParser::CATCH) {
        setState(908);
        catchClause();
        setState(913);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(915);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CoriumParser::FINALLY) {
        setState(914);
        finallyBlock();
      }
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(917);
      match(CoriumParser::SWITCH);
      setState(918);
      parExpression();
      setState(919);
      match(CoriumParser::LBRACE);
      setState(923);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 108, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(920);
          switchBlockStatementGroup(); 
        }
        setState(925);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 108, _ctx);
      }
      setState(929);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CoriumParser::CASE

      || _la == CoriumParser::DEFAULT) {
        setState(926);
        switchLabel();
        setState(931);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(932);
      match(CoriumParser::RBRACE);
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(934);
      match(CoriumParser::SYNCHRONIZED);
      setState(935);
      parExpression();
      setState(936);
      block();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(938);
      match(CoriumParser::RETURN);
      setState(940);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CoriumParser::BOOLEAN)
        | (1ULL << CoriumParser::BYTE)
        | (1ULL << CoriumParser::CHAR)
        | (1ULL << CoriumParser::DOUBLE)
        | (1ULL << CoriumParser::FLOAT)
        | (1ULL << CoriumParser::INT)
        | (1ULL << CoriumParser::LONG)
        | (1ULL << CoriumParser::NEW)
        | (1ULL << CoriumParser::SHORT)
        | (1ULL << CoriumParser::SUPER)
        | (1ULL << CoriumParser::THIS)
        | (1ULL << CoriumParser::VOID)
        | (1ULL << CoriumParser::DECIMAL_LITERAL)
        | (1ULL << CoriumParser::HEX_LITERAL)
        | (1ULL << CoriumParser::OCT_LITERAL)
        | (1ULL << CoriumParser::BINARY_LITERAL)
        | (1ULL << CoriumParser::FLOAT_LITERAL)
        | (1ULL << CoriumParser::HEX_FLOAT_LITERAL)
        | (1ULL << CoriumParser::BOOL_LITERAL)
        | (1ULL << CoriumParser::CHAR_LITERAL)
        | (1ULL << CoriumParser::STRING_LITERAL)
        | (1ULL << CoriumParser::NULL_LITERAL)
        | (1ULL << CoriumParser::LPAREN))) != 0) || ((((_la - 72) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 72)) & ((1ULL << (CoriumParser::LT - 72))
        | (1ULL << (CoriumParser::BANG - 72))
        | (1ULL << (CoriumParser::TILDE - 72))
        | (1ULL << (CoriumParser::INC - 72))
        | (1ULL << (CoriumParser::DEC - 72))
        | (1ULL << (CoriumParser::ADD - 72))
        | (1ULL << (CoriumParser::SUB - 72))
        | (1ULL << (CoriumParser::AT - 72))
        | (1ULL << (CoriumParser::IDENTIFIER - 72)))) != 0)) {
        setState(939);
        expression(0);
      }
      setState(942);
      match(CoriumParser::SEMI);
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(943);
      match(CoriumParser::THROW);
      setState(944);
      expression(0);
      setState(945);
      match(CoriumParser::SEMI);
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(947);
      match(CoriumParser::BREAK);
      setState(949);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CoriumParser::IDENTIFIER) {
        setState(948);
        match(CoriumParser::IDENTIFIER);
      }
      setState(951);
      match(CoriumParser::SEMI);
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(952);
      match(CoriumParser::CONTINUE);
      setState(954);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CoriumParser::IDENTIFIER) {
        setState(953);
        match(CoriumParser::IDENTIFIER);
      }
      setState(956);
      match(CoriumParser::SEMI);
      break;
    }

    case 15: {
      enterOuterAlt(_localctx, 15);
      setState(957);
      match(CoriumParser::SEMI);
      break;
    }

    case 16: {
      enterOuterAlt(_localctx, 16);
      setState(958);
      dynamic_cast<StatementContext *>(_localctx)->statementExpression = expression(0);
      setState(959);
      match(CoriumParser::SEMI);
      break;
    }

    case 17: {
      enterOuterAlt(_localctx, 17);
      setState(961);
      dynamic_cast<StatementContext *>(_localctx)->identifierLabel = match(CoriumParser::IDENTIFIER);
      setState(962);
      match(CoriumParser::COLON);
      setState(963);
      statement();
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

//----------------- CatchClauseContext ------------------------------------------------------------------

CoriumParser::CatchClauseContext::CatchClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::CatchClauseContext::CATCH() {
  return getToken(CoriumParser::CATCH, 0);
}

tree::TerminalNode* CoriumParser::CatchClauseContext::LPAREN() {
  return getToken(CoriumParser::LPAREN, 0);
}

CoriumParser::CatchTypeContext* CoriumParser::CatchClauseContext::catchType() {
  return getRuleContext<CoriumParser::CatchTypeContext>(0);
}

tree::TerminalNode* CoriumParser::CatchClauseContext::IDENTIFIER() {
  return getToken(CoriumParser::IDENTIFIER, 0);
}

tree::TerminalNode* CoriumParser::CatchClauseContext::RPAREN() {
  return getToken(CoriumParser::RPAREN, 0);
}

CoriumParser::BlockContext* CoriumParser::CatchClauseContext::block() {
  return getRuleContext<CoriumParser::BlockContext>(0);
}

std::vector<CoriumParser::VariableModifierContext *> CoriumParser::CatchClauseContext::variableModifier() {
  return getRuleContexts<CoriumParser::VariableModifierContext>();
}

CoriumParser::VariableModifierContext* CoriumParser::CatchClauseContext::variableModifier(size_t i) {
  return getRuleContext<CoriumParser::VariableModifierContext>(i);
}


size_t CoriumParser::CatchClauseContext::getRuleIndex() const {
  return CoriumParser::RuleCatchClause;
}

void CoriumParser::CatchClauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCatchClause(this);
}

void CoriumParser::CatchClauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCatchClause(this);
}

CoriumParser::CatchClauseContext* CoriumParser::catchClause() {
  CatchClauseContext *_localctx = _tracker.createInstance<CatchClauseContext>(_ctx, getState());
  enterRule(_localctx, 138, CoriumParser::RuleCatchClause);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(966);
    match(CoriumParser::CATCH);
    setState(967);
    match(CoriumParser::LPAREN);
    setState(971);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 114, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(968);
        variableModifier(); 
      }
      setState(973);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 114, _ctx);
    }
    setState(974);
    catchType();
    setState(975);
    match(CoriumParser::IDENTIFIER);
    setState(976);
    match(CoriumParser::RPAREN);
    setState(977);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CatchTypeContext ------------------------------------------------------------------

CoriumParser::CatchTypeContext::CatchTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CoriumParser::QualifiedNameContext *> CoriumParser::CatchTypeContext::qualifiedName() {
  return getRuleContexts<CoriumParser::QualifiedNameContext>();
}

CoriumParser::QualifiedNameContext* CoriumParser::CatchTypeContext::qualifiedName(size_t i) {
  return getRuleContext<CoriumParser::QualifiedNameContext>(i);
}

std::vector<tree::TerminalNode *> CoriumParser::CatchTypeContext::BITOR() {
  return getTokens(CoriumParser::BITOR);
}

tree::TerminalNode* CoriumParser::CatchTypeContext::BITOR(size_t i) {
  return getToken(CoriumParser::BITOR, i);
}


size_t CoriumParser::CatchTypeContext::getRuleIndex() const {
  return CoriumParser::RuleCatchType;
}

void CoriumParser::CatchTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCatchType(this);
}

void CoriumParser::CatchTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCatchType(this);
}

CoriumParser::CatchTypeContext* CoriumParser::catchType() {
  CatchTypeContext *_localctx = _tracker.createInstance<CatchTypeContext>(_ctx, getState());
  enterRule(_localctx, 140, CoriumParser::RuleCatchType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(979);
    qualifiedName();
    setState(984);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CoriumParser::BITOR) {
      setState(980);
      match(CoriumParser::BITOR);
      setState(981);
      qualifiedName();
      setState(986);
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

//----------------- FinallyBlockContext ------------------------------------------------------------------

CoriumParser::FinallyBlockContext::FinallyBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::FinallyBlockContext::FINALLY() {
  return getToken(CoriumParser::FINALLY, 0);
}

CoriumParser::BlockContext* CoriumParser::FinallyBlockContext::block() {
  return getRuleContext<CoriumParser::BlockContext>(0);
}


size_t CoriumParser::FinallyBlockContext::getRuleIndex() const {
  return CoriumParser::RuleFinallyBlock;
}

void CoriumParser::FinallyBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFinallyBlock(this);
}

void CoriumParser::FinallyBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFinallyBlock(this);
}

CoriumParser::FinallyBlockContext* CoriumParser::finallyBlock() {
  FinallyBlockContext *_localctx = _tracker.createInstance<FinallyBlockContext>(_ctx, getState());
  enterRule(_localctx, 142, CoriumParser::RuleFinallyBlock);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(987);
    match(CoriumParser::FINALLY);
    setState(988);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ResourceSpecificationContext ------------------------------------------------------------------

CoriumParser::ResourceSpecificationContext::ResourceSpecificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::ResourceSpecificationContext::LPAREN() {
  return getToken(CoriumParser::LPAREN, 0);
}

CoriumParser::ResourcesContext* CoriumParser::ResourceSpecificationContext::resources() {
  return getRuleContext<CoriumParser::ResourcesContext>(0);
}

tree::TerminalNode* CoriumParser::ResourceSpecificationContext::RPAREN() {
  return getToken(CoriumParser::RPAREN, 0);
}

tree::TerminalNode* CoriumParser::ResourceSpecificationContext::SEMI() {
  return getToken(CoriumParser::SEMI, 0);
}


size_t CoriumParser::ResourceSpecificationContext::getRuleIndex() const {
  return CoriumParser::RuleResourceSpecification;
}

void CoriumParser::ResourceSpecificationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterResourceSpecification(this);
}

void CoriumParser::ResourceSpecificationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitResourceSpecification(this);
}

CoriumParser::ResourceSpecificationContext* CoriumParser::resourceSpecification() {
  ResourceSpecificationContext *_localctx = _tracker.createInstance<ResourceSpecificationContext>(_ctx, getState());
  enterRule(_localctx, 144, CoriumParser::RuleResourceSpecification);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(990);
    match(CoriumParser::LPAREN);
    setState(991);
    resources();
    setState(993);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CoriumParser::SEMI) {
      setState(992);
      match(CoriumParser::SEMI);
    }
    setState(995);
    match(CoriumParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ResourcesContext ------------------------------------------------------------------

CoriumParser::ResourcesContext::ResourcesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CoriumParser::ResourceContext *> CoriumParser::ResourcesContext::resource() {
  return getRuleContexts<CoriumParser::ResourceContext>();
}

CoriumParser::ResourceContext* CoriumParser::ResourcesContext::resource(size_t i) {
  return getRuleContext<CoriumParser::ResourceContext>(i);
}

std::vector<tree::TerminalNode *> CoriumParser::ResourcesContext::SEMI() {
  return getTokens(CoriumParser::SEMI);
}

tree::TerminalNode* CoriumParser::ResourcesContext::SEMI(size_t i) {
  return getToken(CoriumParser::SEMI, i);
}


size_t CoriumParser::ResourcesContext::getRuleIndex() const {
  return CoriumParser::RuleResources;
}

void CoriumParser::ResourcesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterResources(this);
}

void CoriumParser::ResourcesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitResources(this);
}

CoriumParser::ResourcesContext* CoriumParser::resources() {
  ResourcesContext *_localctx = _tracker.createInstance<ResourcesContext>(_ctx, getState());
  enterRule(_localctx, 146, CoriumParser::RuleResources);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(997);
    resource();
    setState(1002);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 117, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(998);
        match(CoriumParser::SEMI);
        setState(999);
        resource(); 
      }
      setState(1004);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 117, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ResourceContext ------------------------------------------------------------------

CoriumParser::ResourceContext::ResourceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::ClassOrInterfaceTypeContext* CoriumParser::ResourceContext::classOrInterfaceType() {
  return getRuleContext<CoriumParser::ClassOrInterfaceTypeContext>(0);
}

CoriumParser::VariableDeclaratorIdContext* CoriumParser::ResourceContext::variableDeclaratorId() {
  return getRuleContext<CoriumParser::VariableDeclaratorIdContext>(0);
}

tree::TerminalNode* CoriumParser::ResourceContext::ASSIGN() {
  return getToken(CoriumParser::ASSIGN, 0);
}

CoriumParser::ExpressionContext* CoriumParser::ResourceContext::expression() {
  return getRuleContext<CoriumParser::ExpressionContext>(0);
}

std::vector<CoriumParser::VariableModifierContext *> CoriumParser::ResourceContext::variableModifier() {
  return getRuleContexts<CoriumParser::VariableModifierContext>();
}

CoriumParser::VariableModifierContext* CoriumParser::ResourceContext::variableModifier(size_t i) {
  return getRuleContext<CoriumParser::VariableModifierContext>(i);
}


size_t CoriumParser::ResourceContext::getRuleIndex() const {
  return CoriumParser::RuleResource;
}

void CoriumParser::ResourceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterResource(this);
}

void CoriumParser::ResourceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitResource(this);
}

CoriumParser::ResourceContext* CoriumParser::resource() {
  ResourceContext *_localctx = _tracker.createInstance<ResourceContext>(_ctx, getState());
  enterRule(_localctx, 148, CoriumParser::RuleResource);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1008);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 118, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(1005);
        variableModifier(); 
      }
      setState(1010);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 118, _ctx);
    }
    setState(1011);
    classOrInterfaceType();
    setState(1012);
    variableDeclaratorId();
    setState(1013);
    match(CoriumParser::ASSIGN);
    setState(1014);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SwitchBlockStatementGroupContext ------------------------------------------------------------------

CoriumParser::SwitchBlockStatementGroupContext::SwitchBlockStatementGroupContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CoriumParser::SwitchLabelContext *> CoriumParser::SwitchBlockStatementGroupContext::switchLabel() {
  return getRuleContexts<CoriumParser::SwitchLabelContext>();
}

CoriumParser::SwitchLabelContext* CoriumParser::SwitchBlockStatementGroupContext::switchLabel(size_t i) {
  return getRuleContext<CoriumParser::SwitchLabelContext>(i);
}

std::vector<CoriumParser::BlockStatementContext *> CoriumParser::SwitchBlockStatementGroupContext::blockStatement() {
  return getRuleContexts<CoriumParser::BlockStatementContext>();
}

CoriumParser::BlockStatementContext* CoriumParser::SwitchBlockStatementGroupContext::blockStatement(size_t i) {
  return getRuleContext<CoriumParser::BlockStatementContext>(i);
}


size_t CoriumParser::SwitchBlockStatementGroupContext::getRuleIndex() const {
  return CoriumParser::RuleSwitchBlockStatementGroup;
}

void CoriumParser::SwitchBlockStatementGroupContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitchBlockStatementGroup(this);
}

void CoriumParser::SwitchBlockStatementGroupContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitchBlockStatementGroup(this);
}

CoriumParser::SwitchBlockStatementGroupContext* CoriumParser::switchBlockStatementGroup() {
  SwitchBlockStatementGroupContext *_localctx = _tracker.createInstance<SwitchBlockStatementGroupContext>(_ctx, getState());
  enterRule(_localctx, 150, CoriumParser::RuleSwitchBlockStatementGroup);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1017); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(1016);
      switchLabel();
      setState(1019); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == CoriumParser::CASE

    || _la == CoriumParser::DEFAULT);
    setState(1022); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(1021);
      blockStatement();
      setState(1024); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CoriumParser::ABSTRACT)
      | (1ULL << CoriumParser::ASSERT)
      | (1ULL << CoriumParser::BOOLEAN)
      | (1ULL << CoriumParser::BREAK)
      | (1ULL << CoriumParser::BYTE)
      | (1ULL << CoriumParser::CHAR)
      | (1ULL << CoriumParser::CLASS)
      | (1ULL << CoriumParser::CONTINUE)
      | (1ULL << CoriumParser::DO)
      | (1ULL << CoriumParser::DOUBLE)
      | (1ULL << CoriumParser::FINAL)
      | (1ULL << CoriumParser::FLOAT)
      | (1ULL << CoriumParser::FOR)
      | (1ULL << CoriumParser::IF)
      | (1ULL << CoriumParser::INT)
      | (1ULL << CoriumParser::INTERFACE)
      | (1ULL << CoriumParser::LONG)
      | (1ULL << CoriumParser::NEW)
      | (1ULL << CoriumParser::PRIVATE)
      | (1ULL << CoriumParser::PROTECTED)
      | (1ULL << CoriumParser::PUBLIC)
      | (1ULL << CoriumParser::RETURN)
      | (1ULL << CoriumParser::SHORT)
      | (1ULL << CoriumParser::STATIC)
      | (1ULL << CoriumParser::STRICTFP)
      | (1ULL << CoriumParser::SUPER)
      | (1ULL << CoriumParser::SWITCH)
      | (1ULL << CoriumParser::SYNCHRONIZED)
      | (1ULL << CoriumParser::THIS)
      | (1ULL << CoriumParser::THROW)
      | (1ULL << CoriumParser::TRY)
      | (1ULL << CoriumParser::VOID)
      | (1ULL << CoriumParser::WHILE)
      | (1ULL << CoriumParser::DECIMAL_LITERAL)
      | (1ULL << CoriumParser::HEX_LITERAL)
      | (1ULL << CoriumParser::OCT_LITERAL)
      | (1ULL << CoriumParser::BINARY_LITERAL)
      | (1ULL << CoriumParser::FLOAT_LITERAL)
      | (1ULL << CoriumParser::HEX_FLOAT_LITERAL)
      | (1ULL << CoriumParser::BOOL_LITERAL)
      | (1ULL << CoriumParser::CHAR_LITERAL)
      | (1ULL << CoriumParser::STRING_LITERAL)
      | (1ULL << CoriumParser::NULL_LITERAL)
      | (1ULL << CoriumParser::LPAREN)
      | (1ULL << CoriumParser::LBRACE))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & ((1ULL << (CoriumParser::SEMI - 67))
      | (1ULL << (CoriumParser::LT - 67))
      | (1ULL << (CoriumParser::BANG - 67))
      | (1ULL << (CoriumParser::TILDE - 67))
      | (1ULL << (CoriumParser::INC - 67))
      | (1ULL << (CoriumParser::DEC - 67))
      | (1ULL << (CoriumParser::ADD - 67))
      | (1ULL << (CoriumParser::SUB - 67))
      | (1ULL << (CoriumParser::AT - 67))
      | (1ULL << (CoriumParser::IDENTIFIER - 67)))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SwitchLabelContext ------------------------------------------------------------------

CoriumParser::SwitchLabelContext::SwitchLabelContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::SwitchLabelContext::CASE() {
  return getToken(CoriumParser::CASE, 0);
}

tree::TerminalNode* CoriumParser::SwitchLabelContext::COLON() {
  return getToken(CoriumParser::COLON, 0);
}

CoriumParser::ExpressionContext* CoriumParser::SwitchLabelContext::expression() {
  return getRuleContext<CoriumParser::ExpressionContext>(0);
}

tree::TerminalNode* CoriumParser::SwitchLabelContext::IDENTIFIER() {
  return getToken(CoriumParser::IDENTIFIER, 0);
}

tree::TerminalNode* CoriumParser::SwitchLabelContext::DEFAULT() {
  return getToken(CoriumParser::DEFAULT, 0);
}


size_t CoriumParser::SwitchLabelContext::getRuleIndex() const {
  return CoriumParser::RuleSwitchLabel;
}

void CoriumParser::SwitchLabelContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitchLabel(this);
}

void CoriumParser::SwitchLabelContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitchLabel(this);
}

CoriumParser::SwitchLabelContext* CoriumParser::switchLabel() {
  SwitchLabelContext *_localctx = _tracker.createInstance<SwitchLabelContext>(_ctx, getState());
  enterRule(_localctx, 152, CoriumParser::RuleSwitchLabel);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1034);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CoriumParser::CASE: {
        enterOuterAlt(_localctx, 1);
        setState(1026);
        match(CoriumParser::CASE);
        setState(1029);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 121, _ctx)) {
        case 1: {
          setState(1027);
          dynamic_cast<SwitchLabelContext *>(_localctx)->constantExpression = expression(0);
          break;
        }

        case 2: {
          setState(1028);
          dynamic_cast<SwitchLabelContext *>(_localctx)->enumConstantName = match(CoriumParser::IDENTIFIER);
          break;
        }

        }
        setState(1031);
        match(CoriumParser::COLON);
        break;
      }

      case CoriumParser::DEFAULT: {
        enterOuterAlt(_localctx, 2);
        setState(1032);
        match(CoriumParser::DEFAULT);
        setState(1033);
        match(CoriumParser::COLON);
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

//----------------- ForControlContext ------------------------------------------------------------------

CoriumParser::ForControlContext::ForControlContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::EnhancedForControlContext* CoriumParser::ForControlContext::enhancedForControl() {
  return getRuleContext<CoriumParser::EnhancedForControlContext>(0);
}

std::vector<tree::TerminalNode *> CoriumParser::ForControlContext::SEMI() {
  return getTokens(CoriumParser::SEMI);
}

tree::TerminalNode* CoriumParser::ForControlContext::SEMI(size_t i) {
  return getToken(CoriumParser::SEMI, i);
}

CoriumParser::ForInitContext* CoriumParser::ForControlContext::forInit() {
  return getRuleContext<CoriumParser::ForInitContext>(0);
}

CoriumParser::ExpressionContext* CoriumParser::ForControlContext::expression() {
  return getRuleContext<CoriumParser::ExpressionContext>(0);
}

CoriumParser::ExpressionListContext* CoriumParser::ForControlContext::expressionList() {
  return getRuleContext<CoriumParser::ExpressionListContext>(0);
}


size_t CoriumParser::ForControlContext::getRuleIndex() const {
  return CoriumParser::RuleForControl;
}

void CoriumParser::ForControlContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForControl(this);
}

void CoriumParser::ForControlContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForControl(this);
}

CoriumParser::ForControlContext* CoriumParser::forControl() {
  ForControlContext *_localctx = _tracker.createInstance<ForControlContext>(_ctx, getState());
  enterRule(_localctx, 154, CoriumParser::RuleForControl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1048);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 126, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1036);
      enhancedForControl();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1038);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CoriumParser::BOOLEAN)
        | (1ULL << CoriumParser::BYTE)
        | (1ULL << CoriumParser::CHAR)
        | (1ULL << CoriumParser::DOUBLE)
        | (1ULL << CoriumParser::FINAL)
        | (1ULL << CoriumParser::FLOAT)
        | (1ULL << CoriumParser::INT)
        | (1ULL << CoriumParser::LONG)
        | (1ULL << CoriumParser::NEW)
        | (1ULL << CoriumParser::SHORT)
        | (1ULL << CoriumParser::SUPER)
        | (1ULL << CoriumParser::THIS)
        | (1ULL << CoriumParser::VOID)
        | (1ULL << CoriumParser::DECIMAL_LITERAL)
        | (1ULL << CoriumParser::HEX_LITERAL)
        | (1ULL << CoriumParser::OCT_LITERAL)
        | (1ULL << CoriumParser::BINARY_LITERAL)
        | (1ULL << CoriumParser::FLOAT_LITERAL)
        | (1ULL << CoriumParser::HEX_FLOAT_LITERAL)
        | (1ULL << CoriumParser::BOOL_LITERAL)
        | (1ULL << CoriumParser::CHAR_LITERAL)
        | (1ULL << CoriumParser::STRING_LITERAL)
        | (1ULL << CoriumParser::NULL_LITERAL)
        | (1ULL << CoriumParser::LPAREN))) != 0) || ((((_la - 72) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 72)) & ((1ULL << (CoriumParser::LT - 72))
        | (1ULL << (CoriumParser::BANG - 72))
        | (1ULL << (CoriumParser::TILDE - 72))
        | (1ULL << (CoriumParser::INC - 72))
        | (1ULL << (CoriumParser::DEC - 72))
        | (1ULL << (CoriumParser::ADD - 72))
        | (1ULL << (CoriumParser::SUB - 72))
        | (1ULL << (CoriumParser::AT - 72))
        | (1ULL << (CoriumParser::IDENTIFIER - 72)))) != 0)) {
        setState(1037);
        forInit();
      }
      setState(1040);
      match(CoriumParser::SEMI);
      setState(1042);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CoriumParser::BOOLEAN)
        | (1ULL << CoriumParser::BYTE)
        | (1ULL << CoriumParser::CHAR)
        | (1ULL << CoriumParser::DOUBLE)
        | (1ULL << CoriumParser::FLOAT)
        | (1ULL << CoriumParser::INT)
        | (1ULL << CoriumParser::LONG)
        | (1ULL << CoriumParser::NEW)
        | (1ULL << CoriumParser::SHORT)
        | (1ULL << CoriumParser::SUPER)
        | (1ULL << CoriumParser::THIS)
        | (1ULL << CoriumParser::VOID)
        | (1ULL << CoriumParser::DECIMAL_LITERAL)
        | (1ULL << CoriumParser::HEX_LITERAL)
        | (1ULL << CoriumParser::OCT_LITERAL)
        | (1ULL << CoriumParser::BINARY_LITERAL)
        | (1ULL << CoriumParser::FLOAT_LITERAL)
        | (1ULL << CoriumParser::HEX_FLOAT_LITERAL)
        | (1ULL << CoriumParser::BOOL_LITERAL)
        | (1ULL << CoriumParser::CHAR_LITERAL)
        | (1ULL << CoriumParser::STRING_LITERAL)
        | (1ULL << CoriumParser::NULL_LITERAL)
        | (1ULL << CoriumParser::LPAREN))) != 0) || ((((_la - 72) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 72)) & ((1ULL << (CoriumParser::LT - 72))
        | (1ULL << (CoriumParser::BANG - 72))
        | (1ULL << (CoriumParser::TILDE - 72))
        | (1ULL << (CoriumParser::INC - 72))
        | (1ULL << (CoriumParser::DEC - 72))
        | (1ULL << (CoriumParser::ADD - 72))
        | (1ULL << (CoriumParser::SUB - 72))
        | (1ULL << (CoriumParser::AT - 72))
        | (1ULL << (CoriumParser::IDENTIFIER - 72)))) != 0)) {
        setState(1041);
        expression(0);
      }
      setState(1044);
      match(CoriumParser::SEMI);
      setState(1046);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CoriumParser::BOOLEAN)
        | (1ULL << CoriumParser::BYTE)
        | (1ULL << CoriumParser::CHAR)
        | (1ULL << CoriumParser::DOUBLE)
        | (1ULL << CoriumParser::FLOAT)
        | (1ULL << CoriumParser::INT)
        | (1ULL << CoriumParser::LONG)
        | (1ULL << CoriumParser::NEW)
        | (1ULL << CoriumParser::SHORT)
        | (1ULL << CoriumParser::SUPER)
        | (1ULL << CoriumParser::THIS)
        | (1ULL << CoriumParser::VOID)
        | (1ULL << CoriumParser::DECIMAL_LITERAL)
        | (1ULL << CoriumParser::HEX_LITERAL)
        | (1ULL << CoriumParser::OCT_LITERAL)
        | (1ULL << CoriumParser::BINARY_LITERAL)
        | (1ULL << CoriumParser::FLOAT_LITERAL)
        | (1ULL << CoriumParser::HEX_FLOAT_LITERAL)
        | (1ULL << CoriumParser::BOOL_LITERAL)
        | (1ULL << CoriumParser::CHAR_LITERAL)
        | (1ULL << CoriumParser::STRING_LITERAL)
        | (1ULL << CoriumParser::NULL_LITERAL)
        | (1ULL << CoriumParser::LPAREN))) != 0) || ((((_la - 72) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 72)) & ((1ULL << (CoriumParser::LT - 72))
        | (1ULL << (CoriumParser::BANG - 72))
        | (1ULL << (CoriumParser::TILDE - 72))
        | (1ULL << (CoriumParser::INC - 72))
        | (1ULL << (CoriumParser::DEC - 72))
        | (1ULL << (CoriumParser::ADD - 72))
        | (1ULL << (CoriumParser::SUB - 72))
        | (1ULL << (CoriumParser::AT - 72))
        | (1ULL << (CoriumParser::IDENTIFIER - 72)))) != 0)) {
        setState(1045);
        dynamic_cast<ForControlContext *>(_localctx)->forUpdate = expressionList();
      }
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

//----------------- ForInitContext ------------------------------------------------------------------

CoriumParser::ForInitContext::ForInitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::LocalVariableDeclarationContext* CoriumParser::ForInitContext::localVariableDeclaration() {
  return getRuleContext<CoriumParser::LocalVariableDeclarationContext>(0);
}

CoriumParser::ExpressionListContext* CoriumParser::ForInitContext::expressionList() {
  return getRuleContext<CoriumParser::ExpressionListContext>(0);
}


size_t CoriumParser::ForInitContext::getRuleIndex() const {
  return CoriumParser::RuleForInit;
}

void CoriumParser::ForInitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForInit(this);
}

void CoriumParser::ForInitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForInit(this);
}

CoriumParser::ForInitContext* CoriumParser::forInit() {
  ForInitContext *_localctx = _tracker.createInstance<ForInitContext>(_ctx, getState());
  enterRule(_localctx, 156, CoriumParser::RuleForInit);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1052);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 127, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1050);
      localVariableDeclaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1051);
      expressionList();
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

//----------------- EnhancedForControlContext ------------------------------------------------------------------

CoriumParser::EnhancedForControlContext::EnhancedForControlContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::TypeTypeContext* CoriumParser::EnhancedForControlContext::typeType() {
  return getRuleContext<CoriumParser::TypeTypeContext>(0);
}

CoriumParser::VariableDeclaratorIdContext* CoriumParser::EnhancedForControlContext::variableDeclaratorId() {
  return getRuleContext<CoriumParser::VariableDeclaratorIdContext>(0);
}

tree::TerminalNode* CoriumParser::EnhancedForControlContext::COLON() {
  return getToken(CoriumParser::COLON, 0);
}

CoriumParser::ExpressionContext* CoriumParser::EnhancedForControlContext::expression() {
  return getRuleContext<CoriumParser::ExpressionContext>(0);
}

std::vector<CoriumParser::VariableModifierContext *> CoriumParser::EnhancedForControlContext::variableModifier() {
  return getRuleContexts<CoriumParser::VariableModifierContext>();
}

CoriumParser::VariableModifierContext* CoriumParser::EnhancedForControlContext::variableModifier(size_t i) {
  return getRuleContext<CoriumParser::VariableModifierContext>(i);
}


size_t CoriumParser::EnhancedForControlContext::getRuleIndex() const {
  return CoriumParser::RuleEnhancedForControl;
}

void CoriumParser::EnhancedForControlContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnhancedForControl(this);
}

void CoriumParser::EnhancedForControlContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnhancedForControl(this);
}

CoriumParser::EnhancedForControlContext* CoriumParser::enhancedForControl() {
  EnhancedForControlContext *_localctx = _tracker.createInstance<EnhancedForControlContext>(_ctx, getState());
  enterRule(_localctx, 158, CoriumParser::RuleEnhancedForControl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1057);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 128, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(1054);
        variableModifier(); 
      }
      setState(1059);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 128, _ctx);
    }
    setState(1060);
    typeType();
    setState(1061);
    variableDeclaratorId();
    setState(1062);
    match(CoriumParser::COLON);
    setState(1063);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParExpressionContext ------------------------------------------------------------------

CoriumParser::ParExpressionContext::ParExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::ParExpressionContext::LPAREN() {
  return getToken(CoriumParser::LPAREN, 0);
}

CoriumParser::ExpressionContext* CoriumParser::ParExpressionContext::expression() {
  return getRuleContext<CoriumParser::ExpressionContext>(0);
}

tree::TerminalNode* CoriumParser::ParExpressionContext::RPAREN() {
  return getToken(CoriumParser::RPAREN, 0);
}


size_t CoriumParser::ParExpressionContext::getRuleIndex() const {
  return CoriumParser::RuleParExpression;
}

void CoriumParser::ParExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParExpression(this);
}

void CoriumParser::ParExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParExpression(this);
}

CoriumParser::ParExpressionContext* CoriumParser::parExpression() {
  ParExpressionContext *_localctx = _tracker.createInstance<ParExpressionContext>(_ctx, getState());
  enterRule(_localctx, 160, CoriumParser::RuleParExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1065);
    match(CoriumParser::LPAREN);
    setState(1066);
    expression(0);
    setState(1067);
    match(CoriumParser::RPAREN);
   
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
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionList(this);
}

void CoriumParser::ExpressionListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionList(this);
}

CoriumParser::ExpressionListContext* CoriumParser::expressionList() {
  ExpressionListContext *_localctx = _tracker.createInstance<ExpressionListContext>(_ctx, getState());
  enterRule(_localctx, 162, CoriumParser::RuleExpressionList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1069);
    expression(0);
    setState(1074);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CoriumParser::COMMA) {
      setState(1070);
      match(CoriumParser::COMMA);
      setState(1071);
      expression(0);
      setState(1076);
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

//----------------- MethodCallContext ------------------------------------------------------------------

CoriumParser::MethodCallContext::MethodCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::MethodCallContext::IDENTIFIER() {
  return getToken(CoriumParser::IDENTIFIER, 0);
}

tree::TerminalNode* CoriumParser::MethodCallContext::LPAREN() {
  return getToken(CoriumParser::LPAREN, 0);
}

tree::TerminalNode* CoriumParser::MethodCallContext::RPAREN() {
  return getToken(CoriumParser::RPAREN, 0);
}

CoriumParser::ExpressionListContext* CoriumParser::MethodCallContext::expressionList() {
  return getRuleContext<CoriumParser::ExpressionListContext>(0);
}

tree::TerminalNode* CoriumParser::MethodCallContext::THIS() {
  return getToken(CoriumParser::THIS, 0);
}

tree::TerminalNode* CoriumParser::MethodCallContext::SUPER() {
  return getToken(CoriumParser::SUPER, 0);
}


size_t CoriumParser::MethodCallContext::getRuleIndex() const {
  return CoriumParser::RuleMethodCall;
}

void CoriumParser::MethodCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMethodCall(this);
}

void CoriumParser::MethodCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMethodCall(this);
}

CoriumParser::MethodCallContext* CoriumParser::methodCall() {
  MethodCallContext *_localctx = _tracker.createInstance<MethodCallContext>(_ctx, getState());
  enterRule(_localctx, 164, CoriumParser::RuleMethodCall);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1095);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CoriumParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(1077);
        match(CoriumParser::IDENTIFIER);
        setState(1078);
        match(CoriumParser::LPAREN);
        setState(1080);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CoriumParser::BOOLEAN)
          | (1ULL << CoriumParser::BYTE)
          | (1ULL << CoriumParser::CHAR)
          | (1ULL << CoriumParser::DOUBLE)
          | (1ULL << CoriumParser::FLOAT)
          | (1ULL << CoriumParser::INT)
          | (1ULL << CoriumParser::LONG)
          | (1ULL << CoriumParser::NEW)
          | (1ULL << CoriumParser::SHORT)
          | (1ULL << CoriumParser::SUPER)
          | (1ULL << CoriumParser::THIS)
          | (1ULL << CoriumParser::VOID)
          | (1ULL << CoriumParser::DECIMAL_LITERAL)
          | (1ULL << CoriumParser::HEX_LITERAL)
          | (1ULL << CoriumParser::OCT_LITERAL)
          | (1ULL << CoriumParser::BINARY_LITERAL)
          | (1ULL << CoriumParser::FLOAT_LITERAL)
          | (1ULL << CoriumParser::HEX_FLOAT_LITERAL)
          | (1ULL << CoriumParser::BOOL_LITERAL)
          | (1ULL << CoriumParser::CHAR_LITERAL)
          | (1ULL << CoriumParser::STRING_LITERAL)
          | (1ULL << CoriumParser::NULL_LITERAL)
          | (1ULL << CoriumParser::LPAREN))) != 0) || ((((_la - 72) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 72)) & ((1ULL << (CoriumParser::LT - 72))
          | (1ULL << (CoriumParser::BANG - 72))
          | (1ULL << (CoriumParser::TILDE - 72))
          | (1ULL << (CoriumParser::INC - 72))
          | (1ULL << (CoriumParser::DEC - 72))
          | (1ULL << (CoriumParser::ADD - 72))
          | (1ULL << (CoriumParser::SUB - 72))
          | (1ULL << (CoriumParser::AT - 72))
          | (1ULL << (CoriumParser::IDENTIFIER - 72)))) != 0)) {
          setState(1079);
          expressionList();
        }
        setState(1082);
        match(CoriumParser::RPAREN);
        break;
      }

      case CoriumParser::THIS: {
        enterOuterAlt(_localctx, 2);
        setState(1083);
        match(CoriumParser::THIS);
        setState(1084);
        match(CoriumParser::LPAREN);
        setState(1086);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CoriumParser::BOOLEAN)
          | (1ULL << CoriumParser::BYTE)
          | (1ULL << CoriumParser::CHAR)
          | (1ULL << CoriumParser::DOUBLE)
          | (1ULL << CoriumParser::FLOAT)
          | (1ULL << CoriumParser::INT)
          | (1ULL << CoriumParser::LONG)
          | (1ULL << CoriumParser::NEW)
          | (1ULL << CoriumParser::SHORT)
          | (1ULL << CoriumParser::SUPER)
          | (1ULL << CoriumParser::THIS)
          | (1ULL << CoriumParser::VOID)
          | (1ULL << CoriumParser::DECIMAL_LITERAL)
          | (1ULL << CoriumParser::HEX_LITERAL)
          | (1ULL << CoriumParser::OCT_LITERAL)
          | (1ULL << CoriumParser::BINARY_LITERAL)
          | (1ULL << CoriumParser::FLOAT_LITERAL)
          | (1ULL << CoriumParser::HEX_FLOAT_LITERAL)
          | (1ULL << CoriumParser::BOOL_LITERAL)
          | (1ULL << CoriumParser::CHAR_LITERAL)
          | (1ULL << CoriumParser::STRING_LITERAL)
          | (1ULL << CoriumParser::NULL_LITERAL)
          | (1ULL << CoriumParser::LPAREN))) != 0) || ((((_la - 72) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 72)) & ((1ULL << (CoriumParser::LT - 72))
          | (1ULL << (CoriumParser::BANG - 72))
          | (1ULL << (CoriumParser::TILDE - 72))
          | (1ULL << (CoriumParser::INC - 72))
          | (1ULL << (CoriumParser::DEC - 72))
          | (1ULL << (CoriumParser::ADD - 72))
          | (1ULL << (CoriumParser::SUB - 72))
          | (1ULL << (CoriumParser::AT - 72))
          | (1ULL << (CoriumParser::IDENTIFIER - 72)))) != 0)) {
          setState(1085);
          expressionList();
        }
        setState(1088);
        match(CoriumParser::RPAREN);
        break;
      }

      case CoriumParser::SUPER: {
        enterOuterAlt(_localctx, 3);
        setState(1089);
        match(CoriumParser::SUPER);
        setState(1090);
        match(CoriumParser::LPAREN);
        setState(1092);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CoriumParser::BOOLEAN)
          | (1ULL << CoriumParser::BYTE)
          | (1ULL << CoriumParser::CHAR)
          | (1ULL << CoriumParser::DOUBLE)
          | (1ULL << CoriumParser::FLOAT)
          | (1ULL << CoriumParser::INT)
          | (1ULL << CoriumParser::LONG)
          | (1ULL << CoriumParser::NEW)
          | (1ULL << CoriumParser::SHORT)
          | (1ULL << CoriumParser::SUPER)
          | (1ULL << CoriumParser::THIS)
          | (1ULL << CoriumParser::VOID)
          | (1ULL << CoriumParser::DECIMAL_LITERAL)
          | (1ULL << CoriumParser::HEX_LITERAL)
          | (1ULL << CoriumParser::OCT_LITERAL)
          | (1ULL << CoriumParser::BINARY_LITERAL)
          | (1ULL << CoriumParser::FLOAT_LITERAL)
          | (1ULL << CoriumParser::HEX_FLOAT_LITERAL)
          | (1ULL << CoriumParser::BOOL_LITERAL)
          | (1ULL << CoriumParser::CHAR_LITERAL)
          | (1ULL << CoriumParser::STRING_LITERAL)
          | (1ULL << CoriumParser::NULL_LITERAL)
          | (1ULL << CoriumParser::LPAREN))) != 0) || ((((_la - 72) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 72)) & ((1ULL << (CoriumParser::LT - 72))
          | (1ULL << (CoriumParser::BANG - 72))
          | (1ULL << (CoriumParser::TILDE - 72))
          | (1ULL << (CoriumParser::INC - 72))
          | (1ULL << (CoriumParser::DEC - 72))
          | (1ULL << (CoriumParser::ADD - 72))
          | (1ULL << (CoriumParser::SUB - 72))
          | (1ULL << (CoriumParser::AT - 72))
          | (1ULL << (CoriumParser::IDENTIFIER - 72)))) != 0)) {
          setState(1091);
          expressionList();
        }
        setState(1094);
        match(CoriumParser::RPAREN);
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

//----------------- ExpressionContext ------------------------------------------------------------------

CoriumParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::PrimaryContext* CoriumParser::ExpressionContext::primary() {
  return getRuleContext<CoriumParser::PrimaryContext>(0);
}

CoriumParser::MethodCallContext* CoriumParser::ExpressionContext::methodCall() {
  return getRuleContext<CoriumParser::MethodCallContext>(0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::NEW() {
  return getToken(CoriumParser::NEW, 0);
}

CoriumParser::CreatorContext* CoriumParser::ExpressionContext::creator() {
  return getRuleContext<CoriumParser::CreatorContext>(0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::LPAREN() {
  return getToken(CoriumParser::LPAREN, 0);
}

CoriumParser::TypeTypeContext* CoriumParser::ExpressionContext::typeType() {
  return getRuleContext<CoriumParser::TypeTypeContext>(0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::RPAREN() {
  return getToken(CoriumParser::RPAREN, 0);
}

std::vector<CoriumParser::ExpressionContext *> CoriumParser::ExpressionContext::expression() {
  return getRuleContexts<CoriumParser::ExpressionContext>();
}

CoriumParser::ExpressionContext* CoriumParser::ExpressionContext::expression(size_t i) {
  return getRuleContext<CoriumParser::ExpressionContext>(i);
}

std::vector<CoriumParser::AnnotationContext *> CoriumParser::ExpressionContext::annotation() {
  return getRuleContexts<CoriumParser::AnnotationContext>();
}

CoriumParser::AnnotationContext* CoriumParser::ExpressionContext::annotation(size_t i) {
  return getRuleContext<CoriumParser::AnnotationContext>(i);
}

tree::TerminalNode* CoriumParser::ExpressionContext::ADD() {
  return getToken(CoriumParser::ADD, 0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::SUB() {
  return getToken(CoriumParser::SUB, 0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::INC() {
  return getToken(CoriumParser::INC, 0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::DEC() {
  return getToken(CoriumParser::DEC, 0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::TILDE() {
  return getToken(CoriumParser::TILDE, 0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::BANG() {
  return getToken(CoriumParser::BANG, 0);
}

CoriumParser::LambdaExpressionContext* CoriumParser::ExpressionContext::lambdaExpression() {
  return getRuleContext<CoriumParser::LambdaExpressionContext>(0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::COLONCOLON() {
  return getToken(CoriumParser::COLONCOLON, 0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::IDENTIFIER() {
  return getToken(CoriumParser::IDENTIFIER, 0);
}

CoriumParser::TypeArgumentsContext* CoriumParser::ExpressionContext::typeArguments() {
  return getRuleContext<CoriumParser::TypeArgumentsContext>(0);
}

CoriumParser::ClassTypeContext* CoriumParser::ExpressionContext::classType() {
  return getRuleContext<CoriumParser::ClassTypeContext>(0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::MUL() {
  return getToken(CoriumParser::MUL, 0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::DIV() {
  return getToken(CoriumParser::DIV, 0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::MOD() {
  return getToken(CoriumParser::MOD, 0);
}

std::vector<tree::TerminalNode *> CoriumParser::ExpressionContext::LT() {
  return getTokens(CoriumParser::LT);
}

tree::TerminalNode* CoriumParser::ExpressionContext::LT(size_t i) {
  return getToken(CoriumParser::LT, i);
}

std::vector<tree::TerminalNode *> CoriumParser::ExpressionContext::GT() {
  return getTokens(CoriumParser::GT);
}

tree::TerminalNode* CoriumParser::ExpressionContext::GT(size_t i) {
  return getToken(CoriumParser::GT, i);
}

tree::TerminalNode* CoriumParser::ExpressionContext::LE() {
  return getToken(CoriumParser::LE, 0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::GE() {
  return getToken(CoriumParser::GE, 0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::EQUAL() {
  return getToken(CoriumParser::EQUAL, 0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::NOTEQUAL() {
  return getToken(CoriumParser::NOTEQUAL, 0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::BITAND() {
  return getToken(CoriumParser::BITAND, 0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::CARET() {
  return getToken(CoriumParser::CARET, 0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::BITOR() {
  return getToken(CoriumParser::BITOR, 0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::AND() {
  return getToken(CoriumParser::AND, 0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::OR() {
  return getToken(CoriumParser::OR, 0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::COLON() {
  return getToken(CoriumParser::COLON, 0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::QUESTION() {
  return getToken(CoriumParser::QUESTION, 0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::ASSIGN() {
  return getToken(CoriumParser::ASSIGN, 0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::ADD_ASSIGN() {
  return getToken(CoriumParser::ADD_ASSIGN, 0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::SUB_ASSIGN() {
  return getToken(CoriumParser::SUB_ASSIGN, 0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::MUL_ASSIGN() {
  return getToken(CoriumParser::MUL_ASSIGN, 0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::DIV_ASSIGN() {
  return getToken(CoriumParser::DIV_ASSIGN, 0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::AND_ASSIGN() {
  return getToken(CoriumParser::AND_ASSIGN, 0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::OR_ASSIGN() {
  return getToken(CoriumParser::OR_ASSIGN, 0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::XOR_ASSIGN() {
  return getToken(CoriumParser::XOR_ASSIGN, 0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::RSHIFT_ASSIGN() {
  return getToken(CoriumParser::RSHIFT_ASSIGN, 0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::URSHIFT_ASSIGN() {
  return getToken(CoriumParser::URSHIFT_ASSIGN, 0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::LSHIFT_ASSIGN() {
  return getToken(CoriumParser::LSHIFT_ASSIGN, 0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::MOD_ASSIGN() {
  return getToken(CoriumParser::MOD_ASSIGN, 0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::DOT() {
  return getToken(CoriumParser::DOT, 0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::THIS() {
  return getToken(CoriumParser::THIS, 0);
}

CoriumParser::InnerCreatorContext* CoriumParser::ExpressionContext::innerCreator() {
  return getRuleContext<CoriumParser::InnerCreatorContext>(0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::SUPER() {
  return getToken(CoriumParser::SUPER, 0);
}

CoriumParser::SuperSuffixContext* CoriumParser::ExpressionContext::superSuffix() {
  return getRuleContext<CoriumParser::SuperSuffixContext>(0);
}

CoriumParser::ExplicitGenericInvocationContext* CoriumParser::ExpressionContext::explicitGenericInvocation() {
  return getRuleContext<CoriumParser::ExplicitGenericInvocationContext>(0);
}

CoriumParser::NonWildcardTypeArgumentsContext* CoriumParser::ExpressionContext::nonWildcardTypeArguments() {
  return getRuleContext<CoriumParser::NonWildcardTypeArgumentsContext>(0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::LBRACK() {
  return getToken(CoriumParser::LBRACK, 0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::RBRACK() {
  return getToken(CoriumParser::RBRACK, 0);
}

tree::TerminalNode* CoriumParser::ExpressionContext::INSTANCEOF() {
  return getToken(CoriumParser::INSTANCEOF, 0);
}


size_t CoriumParser::ExpressionContext::getRuleIndex() const {
  return CoriumParser::RuleExpression;
}

void CoriumParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void CoriumParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
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
  size_t startState = 166;
  enterRecursionRule(_localctx, 166, CoriumParser::RuleExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1134);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 138, _ctx)) {
    case 1: {
      setState(1098);
      primary();
      break;
    }

    case 2: {
      setState(1099);
      methodCall();
      break;
    }

    case 3: {
      setState(1100);
      match(CoriumParser::NEW);
      setState(1101);
      creator();
      break;
    }

    case 4: {
      setState(1102);
      match(CoriumParser::LPAREN);
      setState(1106);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 134, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(1103);
          annotation(); 
        }
        setState(1108);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 134, _ctx);
      }
      setState(1109);
      typeType();
      setState(1110);
      match(CoriumParser::RPAREN);
      setState(1111);
      expression(21);
      break;
    }

    case 5: {
      setState(1113);
      dynamic_cast<ExpressionContext *>(_localctx)->prefix = _input->LT(1);
      _la = _input->LA(1);
      if (!(((((_la - 83) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 83)) & ((1ULL << (CoriumParser::INC - 83))
        | (1ULL << (CoriumParser::DEC - 83))
        | (1ULL << (CoriumParser::ADD - 83))
        | (1ULL << (CoriumParser::SUB - 83)))) != 0))) {
        dynamic_cast<ExpressionContext *>(_localctx)->prefix = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(1114);
      expression(19);
      break;
    }

    case 6: {
      setState(1115);
      dynamic_cast<ExpressionContext *>(_localctx)->prefix = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == CoriumParser::BANG

      || _la == CoriumParser::TILDE)) {
        dynamic_cast<ExpressionContext *>(_localctx)->prefix = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(1116);
      expression(18);
      break;
    }

    case 7: {
      setState(1117);
      lambdaExpression();
      break;
    }

    case 8: {
      setState(1118);
      typeType();
      setState(1119);
      match(CoriumParser::COLONCOLON);
      setState(1125);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case CoriumParser::LT:
        case CoriumParser::IDENTIFIER: {
          setState(1121);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CoriumParser::LT) {
            setState(1120);
            typeArguments();
          }
          setState(1123);
          match(CoriumParser::IDENTIFIER);
          break;
        }

        case CoriumParser::NEW: {
          setState(1124);
          match(CoriumParser::NEW);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      break;
    }

    case 9: {
      setState(1127);
      classType();
      setState(1128);
      match(CoriumParser::COLONCOLON);
      setState(1130);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CoriumParser::LT) {
        setState(1129);
        typeArguments();
      }
      setState(1132);
      match(CoriumParser::NEW);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(1216);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 144, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(1214);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 143, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(1136);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(1137);
          dynamic_cast<ExpressionContext *>(_localctx)->bop = _input->LT(1);
          _la = _input->LA(1);
          if (!(((((_la - 87) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 87)) & ((1ULL << (CoriumParser::MUL - 87))
            | (1ULL << (CoriumParser::DIV - 87))
            | (1ULL << (CoriumParser::MOD - 87)))) != 0))) {
            dynamic_cast<ExpressionContext *>(_localctx)->bop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(1138);
          expression(18);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(1139);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(1140);
          dynamic_cast<ExpressionContext *>(_localctx)->bop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == CoriumParser::ADD

          || _la == CoriumParser::SUB)) {
            dynamic_cast<ExpressionContext *>(_localctx)->bop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(1141);
          expression(17);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(1142);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(1150);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 139, _ctx)) {
          case 1: {
            setState(1143);
            match(CoriumParser::LT);
            setState(1144);
            match(CoriumParser::LT);
            break;
          }

          case 2: {
            setState(1145);
            match(CoriumParser::GT);
            setState(1146);
            match(CoriumParser::GT);
            setState(1147);
            match(CoriumParser::GT);
            break;
          }

          case 3: {
            setState(1148);
            match(CoriumParser::GT);
            setState(1149);
            match(CoriumParser::GT);
            break;
          }

          }
          setState(1152);
          expression(16);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(1153);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(1154);
          dynamic_cast<ExpressionContext *>(_localctx)->bop = _input->LT(1);
          _la = _input->LA(1);
          if (!(((((_la - 71) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 71)) & ((1ULL << (CoriumParser::GT - 71))
            | (1ULL << (CoriumParser::LT - 71))
            | (1ULL << (CoriumParser::LE - 71))
            | (1ULL << (CoriumParser::GE - 71)))) != 0))) {
            dynamic_cast<ExpressionContext *>(_localctx)->bop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(1155);
          expression(15);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(1156);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(1157);
          dynamic_cast<ExpressionContext *>(_localctx)->bop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == CoriumParser::EQUAL

          || _la == CoriumParser::NOTEQUAL)) {
            dynamic_cast<ExpressionContext *>(_localctx)->bop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(1158);
          expression(13);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(1159);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(1160);
          dynamic_cast<ExpressionContext *>(_localctx)->bop = match(CoriumParser::BITAND);
          setState(1161);
          expression(12);
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(1162);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(1163);
          dynamic_cast<ExpressionContext *>(_localctx)->bop = match(CoriumParser::CARET);
          setState(1164);
          expression(11);
          break;
        }

        case 8: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(1165);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(1166);
          dynamic_cast<ExpressionContext *>(_localctx)->bop = match(CoriumParser::BITOR);
          setState(1167);
          expression(10);
          break;
        }

        case 9: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(1168);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(1169);
          dynamic_cast<ExpressionContext *>(_localctx)->bop = match(CoriumParser::AND);
          setState(1170);
          expression(9);
          break;
        }

        case 10: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(1171);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(1172);
          dynamic_cast<ExpressionContext *>(_localctx)->bop = match(CoriumParser::OR);
          setState(1173);
          expression(8);
          break;
        }

        case 11: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(1174);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(1175);
          dynamic_cast<ExpressionContext *>(_localctx)->bop = match(CoriumParser::QUESTION);
          setState(1176);
          expression(0);
          setState(1177);
          match(CoriumParser::COLON);
          setState(1178);
          expression(6);
          break;
        }

        case 12: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(1180);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(1181);
          dynamic_cast<ExpressionContext *>(_localctx)->bop = _input->LT(1);
          _la = _input->LA(1);
          if (!(((((_la - 70) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 70)) & ((1ULL << (CoriumParser::ASSIGN - 70))
            | (1ULL << (CoriumParser::ADD_ASSIGN - 70))
            | (1ULL << (CoriumParser::SUB_ASSIGN - 70))
            | (1ULL << (CoriumParser::MUL_ASSIGN - 70))
            | (1ULL << (CoriumParser::DIV_ASSIGN - 70))
            | (1ULL << (CoriumParser::AND_ASSIGN - 70))
            | (1ULL << (CoriumParser::OR_ASSIGN - 70))
            | (1ULL << (CoriumParser::XOR_ASSIGN - 70))
            | (1ULL << (CoriumParser::MOD_ASSIGN - 70))
            | (1ULL << (CoriumParser::LSHIFT_ASSIGN - 70))
            | (1ULL << (CoriumParser::RSHIFT_ASSIGN - 70))
            | (1ULL << (CoriumParser::URSHIFT_ASSIGN - 70)))) != 0))) {
            dynamic_cast<ExpressionContext *>(_localctx)->bop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(1182);
          expression(5);
          break;
        }

        case 13: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(1183);

          if (!(precpred(_ctx, 25))) throw FailedPredicateException(this, "precpred(_ctx, 25)");
          setState(1184);
          dynamic_cast<ExpressionContext *>(_localctx)->bop = match(CoriumParser::DOT);
          setState(1196);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 141, _ctx)) {
          case 1: {
            setState(1185);
            match(CoriumParser::IDENTIFIER);
            break;
          }

          case 2: {
            setState(1186);
            methodCall();
            break;
          }

          case 3: {
            setState(1187);
            match(CoriumParser::THIS);
            break;
          }

          case 4: {
            setState(1188);
            match(CoriumParser::NEW);
            setState(1190);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == CoriumParser::LT) {
              setState(1189);
              nonWildcardTypeArguments();
            }
            setState(1192);
            innerCreator();
            break;
          }

          case 5: {
            setState(1193);
            match(CoriumParser::SUPER);
            setState(1194);
            superSuffix();
            break;
          }

          case 6: {
            setState(1195);
            explicitGenericInvocation();
            break;
          }

          }
          break;
        }

        case 14: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(1198);

          if (!(precpred(_ctx, 24))) throw FailedPredicateException(this, "precpred(_ctx, 24)");
          setState(1199);
          match(CoriumParser::LBRACK);
          setState(1200);
          expression(0);
          setState(1201);
          match(CoriumParser::RBRACK);
          break;
        }

        case 15: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(1203);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(1204);
          dynamic_cast<ExpressionContext *>(_localctx)->postfix = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == CoriumParser::INC

          || _la == CoriumParser::DEC)) {
            dynamic_cast<ExpressionContext *>(_localctx)->postfix = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          break;
        }

        case 16: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(1205);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(1206);
          dynamic_cast<ExpressionContext *>(_localctx)->bop = match(CoriumParser::INSTANCEOF);
          setState(1207);
          typeType();
          break;
        }

        case 17: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(1208);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(1209);
          match(CoriumParser::COLONCOLON);
          setState(1211);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CoriumParser::LT) {
            setState(1210);
            typeArguments();
          }
          setState(1213);
          match(CoriumParser::IDENTIFIER);
          break;
        }

        } 
      }
      setState(1218);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 144, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LambdaExpressionContext ------------------------------------------------------------------

CoriumParser::LambdaExpressionContext::LambdaExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::LambdaParametersContext* CoriumParser::LambdaExpressionContext::lambdaParameters() {
  return getRuleContext<CoriumParser::LambdaParametersContext>(0);
}

tree::TerminalNode* CoriumParser::LambdaExpressionContext::ARROW() {
  return getToken(CoriumParser::ARROW, 0);
}

CoriumParser::LambdaBodyContext* CoriumParser::LambdaExpressionContext::lambdaBody() {
  return getRuleContext<CoriumParser::LambdaBodyContext>(0);
}


size_t CoriumParser::LambdaExpressionContext::getRuleIndex() const {
  return CoriumParser::RuleLambdaExpression;
}

void CoriumParser::LambdaExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLambdaExpression(this);
}

void CoriumParser::LambdaExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLambdaExpression(this);
}

CoriumParser::LambdaExpressionContext* CoriumParser::lambdaExpression() {
  LambdaExpressionContext *_localctx = _tracker.createInstance<LambdaExpressionContext>(_ctx, getState());
  enterRule(_localctx, 168, CoriumParser::RuleLambdaExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1219);
    lambdaParameters();
    setState(1220);
    match(CoriumParser::ARROW);
    setState(1221);
    lambdaBody();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LambdaParametersContext ------------------------------------------------------------------

CoriumParser::LambdaParametersContext::LambdaParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> CoriumParser::LambdaParametersContext::IDENTIFIER() {
  return getTokens(CoriumParser::IDENTIFIER);
}

tree::TerminalNode* CoriumParser::LambdaParametersContext::IDENTIFIER(size_t i) {
  return getToken(CoriumParser::IDENTIFIER, i);
}

tree::TerminalNode* CoriumParser::LambdaParametersContext::LPAREN() {
  return getToken(CoriumParser::LPAREN, 0);
}

tree::TerminalNode* CoriumParser::LambdaParametersContext::RPAREN() {
  return getToken(CoriumParser::RPAREN, 0);
}

CoriumParser::FormalParameterListContext* CoriumParser::LambdaParametersContext::formalParameterList() {
  return getRuleContext<CoriumParser::FormalParameterListContext>(0);
}

std::vector<tree::TerminalNode *> CoriumParser::LambdaParametersContext::COMMA() {
  return getTokens(CoriumParser::COMMA);
}

tree::TerminalNode* CoriumParser::LambdaParametersContext::COMMA(size_t i) {
  return getToken(CoriumParser::COMMA, i);
}


size_t CoriumParser::LambdaParametersContext::getRuleIndex() const {
  return CoriumParser::RuleLambdaParameters;
}

void CoriumParser::LambdaParametersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLambdaParameters(this);
}

void CoriumParser::LambdaParametersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLambdaParameters(this);
}

CoriumParser::LambdaParametersContext* CoriumParser::lambdaParameters() {
  LambdaParametersContext *_localctx = _tracker.createInstance<LambdaParametersContext>(_ctx, getState());
  enterRule(_localctx, 170, CoriumParser::RuleLambdaParameters);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1239);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 147, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1223);
      match(CoriumParser::IDENTIFIER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1224);
      match(CoriumParser::LPAREN);
      setState(1226);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CoriumParser::BOOLEAN)
        | (1ULL << CoriumParser::BYTE)
        | (1ULL << CoriumParser::CHAR)
        | (1ULL << CoriumParser::DOUBLE)
        | (1ULL << CoriumParser::FINAL)
        | (1ULL << CoriumParser::FLOAT)
        | (1ULL << CoriumParser::INT)
        | (1ULL << CoriumParser::LONG)
        | (1ULL << CoriumParser::SHORT))) != 0) || _la == CoriumParser::AT

      || _la == CoriumParser::IDENTIFIER) {
        setState(1225);
        formalParameterList();
      }
      setState(1228);
      match(CoriumParser::RPAREN);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1229);
      match(CoriumParser::LPAREN);
      setState(1230);
      match(CoriumParser::IDENTIFIER);
      setState(1235);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CoriumParser::COMMA) {
        setState(1231);
        match(CoriumParser::COMMA);
        setState(1232);
        match(CoriumParser::IDENTIFIER);
        setState(1237);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(1238);
      match(CoriumParser::RPAREN);
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

//----------------- LambdaBodyContext ------------------------------------------------------------------

CoriumParser::LambdaBodyContext::LambdaBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::ExpressionContext* CoriumParser::LambdaBodyContext::expression() {
  return getRuleContext<CoriumParser::ExpressionContext>(0);
}

CoriumParser::BlockContext* CoriumParser::LambdaBodyContext::block() {
  return getRuleContext<CoriumParser::BlockContext>(0);
}


size_t CoriumParser::LambdaBodyContext::getRuleIndex() const {
  return CoriumParser::RuleLambdaBody;
}

void CoriumParser::LambdaBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLambdaBody(this);
}

void CoriumParser::LambdaBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLambdaBody(this);
}

CoriumParser::LambdaBodyContext* CoriumParser::lambdaBody() {
  LambdaBodyContext *_localctx = _tracker.createInstance<LambdaBodyContext>(_ctx, getState());
  enterRule(_localctx, 172, CoriumParser::RuleLambdaBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1243);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CoriumParser::BOOLEAN:
      case CoriumParser::BYTE:
      case CoriumParser::CHAR:
      case CoriumParser::DOUBLE:
      case CoriumParser::FLOAT:
      case CoriumParser::INT:
      case CoriumParser::LONG:
      case CoriumParser::NEW:
      case CoriumParser::SHORT:
      case CoriumParser::SUPER:
      case CoriumParser::THIS:
      case CoriumParser::VOID:
      case CoriumParser::DECIMAL_LITERAL:
      case CoriumParser::HEX_LITERAL:
      case CoriumParser::OCT_LITERAL:
      case CoriumParser::BINARY_LITERAL:
      case CoriumParser::FLOAT_LITERAL:
      case CoriumParser::HEX_FLOAT_LITERAL:
      case CoriumParser::BOOL_LITERAL:
      case CoriumParser::CHAR_LITERAL:
      case CoriumParser::STRING_LITERAL:
      case CoriumParser::NULL_LITERAL:
      case CoriumParser::LPAREN:
      case CoriumParser::LT:
      case CoriumParser::BANG:
      case CoriumParser::TILDE:
      case CoriumParser::INC:
      case CoriumParser::DEC:
      case CoriumParser::ADD:
      case CoriumParser::SUB:
      case CoriumParser::AT:
      case CoriumParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(1241);
        expression(0);
        break;
      }

      case CoriumParser::LBRACE: {
        enterOuterAlt(_localctx, 2);
        setState(1242);
        block();
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

//----------------- PrimaryContext ------------------------------------------------------------------

CoriumParser::PrimaryContext::PrimaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::PrimaryContext::LPAREN() {
  return getToken(CoriumParser::LPAREN, 0);
}

CoriumParser::ExpressionContext* CoriumParser::PrimaryContext::expression() {
  return getRuleContext<CoriumParser::ExpressionContext>(0);
}

tree::TerminalNode* CoriumParser::PrimaryContext::RPAREN() {
  return getToken(CoriumParser::RPAREN, 0);
}

tree::TerminalNode* CoriumParser::PrimaryContext::THIS() {
  return getToken(CoriumParser::THIS, 0);
}

tree::TerminalNode* CoriumParser::PrimaryContext::SUPER() {
  return getToken(CoriumParser::SUPER, 0);
}

CoriumParser::LiteralContext* CoriumParser::PrimaryContext::literal() {
  return getRuleContext<CoriumParser::LiteralContext>(0);
}

tree::TerminalNode* CoriumParser::PrimaryContext::IDENTIFIER() {
  return getToken(CoriumParser::IDENTIFIER, 0);
}

CoriumParser::TypeTypeOrVoidContext* CoriumParser::PrimaryContext::typeTypeOrVoid() {
  return getRuleContext<CoriumParser::TypeTypeOrVoidContext>(0);
}

tree::TerminalNode* CoriumParser::PrimaryContext::DOT() {
  return getToken(CoriumParser::DOT, 0);
}

tree::TerminalNode* CoriumParser::PrimaryContext::CLASS() {
  return getToken(CoriumParser::CLASS, 0);
}

CoriumParser::NonWildcardTypeArgumentsContext* CoriumParser::PrimaryContext::nonWildcardTypeArguments() {
  return getRuleContext<CoriumParser::NonWildcardTypeArgumentsContext>(0);
}

CoriumParser::ExplicitGenericInvocationSuffixContext* CoriumParser::PrimaryContext::explicitGenericInvocationSuffix() {
  return getRuleContext<CoriumParser::ExplicitGenericInvocationSuffixContext>(0);
}

CoriumParser::ArgumentsContext* CoriumParser::PrimaryContext::arguments() {
  return getRuleContext<CoriumParser::ArgumentsContext>(0);
}


size_t CoriumParser::PrimaryContext::getRuleIndex() const {
  return CoriumParser::RulePrimary;
}

void CoriumParser::PrimaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimary(this);
}

void CoriumParser::PrimaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimary(this);
}

CoriumParser::PrimaryContext* CoriumParser::primary() {
  PrimaryContext *_localctx = _tracker.createInstance<PrimaryContext>(_ctx, getState());
  enterRule(_localctx, 174, CoriumParser::RulePrimary);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1263);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 150, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1245);
      match(CoriumParser::LPAREN);
      setState(1246);
      expression(0);
      setState(1247);
      match(CoriumParser::RPAREN);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1249);
      match(CoriumParser::THIS);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1250);
      match(CoriumParser::SUPER);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1251);
      literal();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(1252);
      match(CoriumParser::IDENTIFIER);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(1253);
      typeTypeOrVoid();
      setState(1254);
      match(CoriumParser::DOT);
      setState(1255);
      match(CoriumParser::CLASS);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(1257);
      nonWildcardTypeArguments();
      setState(1261);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case CoriumParser::SUPER:
        case CoriumParser::IDENTIFIER: {
          setState(1258);
          explicitGenericInvocationSuffix();
          break;
        }

        case CoriumParser::THIS: {
          setState(1259);
          match(CoriumParser::THIS);
          setState(1260);
          arguments();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
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

//----------------- ClassTypeContext ------------------------------------------------------------------

CoriumParser::ClassTypeContext::ClassTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::ClassTypeContext::IDENTIFIER() {
  return getToken(CoriumParser::IDENTIFIER, 0);
}

CoriumParser::ClassOrInterfaceTypeContext* CoriumParser::ClassTypeContext::classOrInterfaceType() {
  return getRuleContext<CoriumParser::ClassOrInterfaceTypeContext>(0);
}

tree::TerminalNode* CoriumParser::ClassTypeContext::DOT() {
  return getToken(CoriumParser::DOT, 0);
}

std::vector<CoriumParser::AnnotationContext *> CoriumParser::ClassTypeContext::annotation() {
  return getRuleContexts<CoriumParser::AnnotationContext>();
}

CoriumParser::AnnotationContext* CoriumParser::ClassTypeContext::annotation(size_t i) {
  return getRuleContext<CoriumParser::AnnotationContext>(i);
}

CoriumParser::TypeArgumentsContext* CoriumParser::ClassTypeContext::typeArguments() {
  return getRuleContext<CoriumParser::TypeArgumentsContext>(0);
}


size_t CoriumParser::ClassTypeContext::getRuleIndex() const {
  return CoriumParser::RuleClassType;
}

void CoriumParser::ClassTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassType(this);
}

void CoriumParser::ClassTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassType(this);
}

CoriumParser::ClassTypeContext* CoriumParser::classType() {
  ClassTypeContext *_localctx = _tracker.createInstance<ClassTypeContext>(_ctx, getState());
  enterRule(_localctx, 176, CoriumParser::RuleClassType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1268);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 151, _ctx)) {
    case 1: {
      setState(1265);
      classOrInterfaceType();
      setState(1266);
      match(CoriumParser::DOT);
      break;
    }

    }
    setState(1273);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 152, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(1270);
        annotation(); 
      }
      setState(1275);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 152, _ctx);
    }
    setState(1276);
    match(CoriumParser::IDENTIFIER);
    setState(1278);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CoriumParser::LT) {
      setState(1277);
      typeArguments();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CreatorContext ------------------------------------------------------------------

CoriumParser::CreatorContext::CreatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::NonWildcardTypeArgumentsContext* CoriumParser::CreatorContext::nonWildcardTypeArguments() {
  return getRuleContext<CoriumParser::NonWildcardTypeArgumentsContext>(0);
}

CoriumParser::CreatedNameContext* CoriumParser::CreatorContext::createdName() {
  return getRuleContext<CoriumParser::CreatedNameContext>(0);
}

CoriumParser::ClassCreatorRestContext* CoriumParser::CreatorContext::classCreatorRest() {
  return getRuleContext<CoriumParser::ClassCreatorRestContext>(0);
}

CoriumParser::ArrayCreatorRestContext* CoriumParser::CreatorContext::arrayCreatorRest() {
  return getRuleContext<CoriumParser::ArrayCreatorRestContext>(0);
}


size_t CoriumParser::CreatorContext::getRuleIndex() const {
  return CoriumParser::RuleCreator;
}

void CoriumParser::CreatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCreator(this);
}

void CoriumParser::CreatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCreator(this);
}

CoriumParser::CreatorContext* CoriumParser::creator() {
  CreatorContext *_localctx = _tracker.createInstance<CreatorContext>(_ctx, getState());
  enterRule(_localctx, 178, CoriumParser::RuleCreator);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1289);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CoriumParser::LT: {
        enterOuterAlt(_localctx, 1);
        setState(1280);
        nonWildcardTypeArguments();
        setState(1281);
        createdName();
        setState(1282);
        classCreatorRest();
        break;
      }

      case CoriumParser::BOOLEAN:
      case CoriumParser::BYTE:
      case CoriumParser::CHAR:
      case CoriumParser::DOUBLE:
      case CoriumParser::FLOAT:
      case CoriumParser::INT:
      case CoriumParser::LONG:
      case CoriumParser::SHORT:
      case CoriumParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(1284);
        createdName();
        setState(1287);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case CoriumParser::LBRACK: {
            setState(1285);
            arrayCreatorRest();
            break;
          }

          case CoriumParser::LPAREN: {
            setState(1286);
            classCreatorRest();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
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

//----------------- CreatedNameContext ------------------------------------------------------------------

CoriumParser::CreatedNameContext::CreatedNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> CoriumParser::CreatedNameContext::IDENTIFIER() {
  return getTokens(CoriumParser::IDENTIFIER);
}

tree::TerminalNode* CoriumParser::CreatedNameContext::IDENTIFIER(size_t i) {
  return getToken(CoriumParser::IDENTIFIER, i);
}

std::vector<CoriumParser::TypeArgumentsOrDiamondContext *> CoriumParser::CreatedNameContext::typeArgumentsOrDiamond() {
  return getRuleContexts<CoriumParser::TypeArgumentsOrDiamondContext>();
}

CoriumParser::TypeArgumentsOrDiamondContext* CoriumParser::CreatedNameContext::typeArgumentsOrDiamond(size_t i) {
  return getRuleContext<CoriumParser::TypeArgumentsOrDiamondContext>(i);
}

std::vector<tree::TerminalNode *> CoriumParser::CreatedNameContext::DOT() {
  return getTokens(CoriumParser::DOT);
}

tree::TerminalNode* CoriumParser::CreatedNameContext::DOT(size_t i) {
  return getToken(CoriumParser::DOT, i);
}

CoriumParser::PrimitiveTypeContext* CoriumParser::CreatedNameContext::primitiveType() {
  return getRuleContext<CoriumParser::PrimitiveTypeContext>(0);
}


size_t CoriumParser::CreatedNameContext::getRuleIndex() const {
  return CoriumParser::RuleCreatedName;
}

void CoriumParser::CreatedNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCreatedName(this);
}

void CoriumParser::CreatedNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCreatedName(this);
}

CoriumParser::CreatedNameContext* CoriumParser::createdName() {
  CreatedNameContext *_localctx = _tracker.createInstance<CreatedNameContext>(_ctx, getState());
  enterRule(_localctx, 180, CoriumParser::RuleCreatedName);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1306);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CoriumParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(1291);
        match(CoriumParser::IDENTIFIER);
        setState(1293);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CoriumParser::LT) {
          setState(1292);
          typeArgumentsOrDiamond();
        }
        setState(1302);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CoriumParser::DOT) {
          setState(1295);
          match(CoriumParser::DOT);
          setState(1296);
          match(CoriumParser::IDENTIFIER);
          setState(1298);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CoriumParser::LT) {
            setState(1297);
            typeArgumentsOrDiamond();
          }
          setState(1304);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case CoriumParser::BOOLEAN:
      case CoriumParser::BYTE:
      case CoriumParser::CHAR:
      case CoriumParser::DOUBLE:
      case CoriumParser::FLOAT:
      case CoriumParser::INT:
      case CoriumParser::LONG:
      case CoriumParser::SHORT: {
        enterOuterAlt(_localctx, 2);
        setState(1305);
        primitiveType();
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

//----------------- InnerCreatorContext ------------------------------------------------------------------

CoriumParser::InnerCreatorContext::InnerCreatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::InnerCreatorContext::IDENTIFIER() {
  return getToken(CoriumParser::IDENTIFIER, 0);
}

CoriumParser::ClassCreatorRestContext* CoriumParser::InnerCreatorContext::classCreatorRest() {
  return getRuleContext<CoriumParser::ClassCreatorRestContext>(0);
}

CoriumParser::NonWildcardTypeArgumentsOrDiamondContext* CoriumParser::InnerCreatorContext::nonWildcardTypeArgumentsOrDiamond() {
  return getRuleContext<CoriumParser::NonWildcardTypeArgumentsOrDiamondContext>(0);
}


size_t CoriumParser::InnerCreatorContext::getRuleIndex() const {
  return CoriumParser::RuleInnerCreator;
}

void CoriumParser::InnerCreatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInnerCreator(this);
}

void CoriumParser::InnerCreatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInnerCreator(this);
}

CoriumParser::InnerCreatorContext* CoriumParser::innerCreator() {
  InnerCreatorContext *_localctx = _tracker.createInstance<InnerCreatorContext>(_ctx, getState());
  enterRule(_localctx, 182, CoriumParser::RuleInnerCreator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1308);
    match(CoriumParser::IDENTIFIER);
    setState(1310);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CoriumParser::LT) {
      setState(1309);
      nonWildcardTypeArgumentsOrDiamond();
    }
    setState(1312);
    classCreatorRest();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayCreatorRestContext ------------------------------------------------------------------

CoriumParser::ArrayCreatorRestContext::ArrayCreatorRestContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> CoriumParser::ArrayCreatorRestContext::LBRACK() {
  return getTokens(CoriumParser::LBRACK);
}

tree::TerminalNode* CoriumParser::ArrayCreatorRestContext::LBRACK(size_t i) {
  return getToken(CoriumParser::LBRACK, i);
}

std::vector<tree::TerminalNode *> CoriumParser::ArrayCreatorRestContext::RBRACK() {
  return getTokens(CoriumParser::RBRACK);
}

tree::TerminalNode* CoriumParser::ArrayCreatorRestContext::RBRACK(size_t i) {
  return getToken(CoriumParser::RBRACK, i);
}

CoriumParser::ArrayInitializerContext* CoriumParser::ArrayCreatorRestContext::arrayInitializer() {
  return getRuleContext<CoriumParser::ArrayInitializerContext>(0);
}

std::vector<CoriumParser::ExpressionContext *> CoriumParser::ArrayCreatorRestContext::expression() {
  return getRuleContexts<CoriumParser::ExpressionContext>();
}

CoriumParser::ExpressionContext* CoriumParser::ArrayCreatorRestContext::expression(size_t i) {
  return getRuleContext<CoriumParser::ExpressionContext>(i);
}


size_t CoriumParser::ArrayCreatorRestContext::getRuleIndex() const {
  return CoriumParser::RuleArrayCreatorRest;
}

void CoriumParser::ArrayCreatorRestContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayCreatorRest(this);
}

void CoriumParser::ArrayCreatorRestContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayCreatorRest(this);
}

CoriumParser::ArrayCreatorRestContext* CoriumParser::arrayCreatorRest() {
  ArrayCreatorRestContext *_localctx = _tracker.createInstance<ArrayCreatorRestContext>(_ctx, getState());
  enterRule(_localctx, 184, CoriumParser::RuleArrayCreatorRest);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1314);
    match(CoriumParser::LBRACK);
    setState(1342);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CoriumParser::RBRACK: {
        setState(1315);
        match(CoriumParser::RBRACK);
        setState(1320);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CoriumParser::LBRACK) {
          setState(1316);
          match(CoriumParser::LBRACK);
          setState(1317);
          match(CoriumParser::RBRACK);
          setState(1322);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(1323);
        arrayInitializer();
        break;
      }

      case CoriumParser::BOOLEAN:
      case CoriumParser::BYTE:
      case CoriumParser::CHAR:
      case CoriumParser::DOUBLE:
      case CoriumParser::FLOAT:
      case CoriumParser::INT:
      case CoriumParser::LONG:
      case CoriumParser::NEW:
      case CoriumParser::SHORT:
      case CoriumParser::SUPER:
      case CoriumParser::THIS:
      case CoriumParser::VOID:
      case CoriumParser::DECIMAL_LITERAL:
      case CoriumParser::HEX_LITERAL:
      case CoriumParser::OCT_LITERAL:
      case CoriumParser::BINARY_LITERAL:
      case CoriumParser::FLOAT_LITERAL:
      case CoriumParser::HEX_FLOAT_LITERAL:
      case CoriumParser::BOOL_LITERAL:
      case CoriumParser::CHAR_LITERAL:
      case CoriumParser::STRING_LITERAL:
      case CoriumParser::NULL_LITERAL:
      case CoriumParser::LPAREN:
      case CoriumParser::LT:
      case CoriumParser::BANG:
      case CoriumParser::TILDE:
      case CoriumParser::INC:
      case CoriumParser::DEC:
      case CoriumParser::ADD:
      case CoriumParser::SUB:
      case CoriumParser::AT:
      case CoriumParser::IDENTIFIER: {
        setState(1324);
        expression(0);
        setState(1325);
        match(CoriumParser::RBRACK);
        setState(1332);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 162, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1326);
            match(CoriumParser::LBRACK);
            setState(1327);
            expression(0);
            setState(1328);
            match(CoriumParser::RBRACK); 
          }
          setState(1334);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 162, _ctx);
        }
        setState(1339);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 163, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1335);
            match(CoriumParser::LBRACK);
            setState(1336);
            match(CoriumParser::RBRACK); 
          }
          setState(1341);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 163, _ctx);
        }
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

//----------------- ClassCreatorRestContext ------------------------------------------------------------------

CoriumParser::ClassCreatorRestContext::ClassCreatorRestContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::ArgumentsContext* CoriumParser::ClassCreatorRestContext::arguments() {
  return getRuleContext<CoriumParser::ArgumentsContext>(0);
}

CoriumParser::ClassBodyContext* CoriumParser::ClassCreatorRestContext::classBody() {
  return getRuleContext<CoriumParser::ClassBodyContext>(0);
}


size_t CoriumParser::ClassCreatorRestContext::getRuleIndex() const {
  return CoriumParser::RuleClassCreatorRest;
}

void CoriumParser::ClassCreatorRestContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassCreatorRest(this);
}

void CoriumParser::ClassCreatorRestContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassCreatorRest(this);
}

CoriumParser::ClassCreatorRestContext* CoriumParser::classCreatorRest() {
  ClassCreatorRestContext *_localctx = _tracker.createInstance<ClassCreatorRestContext>(_ctx, getState());
  enterRule(_localctx, 186, CoriumParser::RuleClassCreatorRest);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1344);
    arguments();
    setState(1346);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 165, _ctx)) {
    case 1: {
      setState(1345);
      classBody();
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

//----------------- ExplicitGenericInvocationContext ------------------------------------------------------------------

CoriumParser::ExplicitGenericInvocationContext::ExplicitGenericInvocationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::NonWildcardTypeArgumentsContext* CoriumParser::ExplicitGenericInvocationContext::nonWildcardTypeArguments() {
  return getRuleContext<CoriumParser::NonWildcardTypeArgumentsContext>(0);
}

CoriumParser::ExplicitGenericInvocationSuffixContext* CoriumParser::ExplicitGenericInvocationContext::explicitGenericInvocationSuffix() {
  return getRuleContext<CoriumParser::ExplicitGenericInvocationSuffixContext>(0);
}


size_t CoriumParser::ExplicitGenericInvocationContext::getRuleIndex() const {
  return CoriumParser::RuleExplicitGenericInvocation;
}

void CoriumParser::ExplicitGenericInvocationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExplicitGenericInvocation(this);
}

void CoriumParser::ExplicitGenericInvocationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExplicitGenericInvocation(this);
}

CoriumParser::ExplicitGenericInvocationContext* CoriumParser::explicitGenericInvocation() {
  ExplicitGenericInvocationContext *_localctx = _tracker.createInstance<ExplicitGenericInvocationContext>(_ctx, getState());
  enterRule(_localctx, 188, CoriumParser::RuleExplicitGenericInvocation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1348);
    nonWildcardTypeArguments();
    setState(1349);
    explicitGenericInvocationSuffix();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeArgumentsOrDiamondContext ------------------------------------------------------------------

CoriumParser::TypeArgumentsOrDiamondContext::TypeArgumentsOrDiamondContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::TypeArgumentsOrDiamondContext::LT() {
  return getToken(CoriumParser::LT, 0);
}

tree::TerminalNode* CoriumParser::TypeArgumentsOrDiamondContext::GT() {
  return getToken(CoriumParser::GT, 0);
}

CoriumParser::TypeArgumentsContext* CoriumParser::TypeArgumentsOrDiamondContext::typeArguments() {
  return getRuleContext<CoriumParser::TypeArgumentsContext>(0);
}


size_t CoriumParser::TypeArgumentsOrDiamondContext::getRuleIndex() const {
  return CoriumParser::RuleTypeArgumentsOrDiamond;
}

void CoriumParser::TypeArgumentsOrDiamondContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeArgumentsOrDiamond(this);
}

void CoriumParser::TypeArgumentsOrDiamondContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeArgumentsOrDiamond(this);
}

CoriumParser::TypeArgumentsOrDiamondContext* CoriumParser::typeArgumentsOrDiamond() {
  TypeArgumentsOrDiamondContext *_localctx = _tracker.createInstance<TypeArgumentsOrDiamondContext>(_ctx, getState());
  enterRule(_localctx, 190, CoriumParser::RuleTypeArgumentsOrDiamond);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1354);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 166, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1351);
      match(CoriumParser::LT);
      setState(1352);
      match(CoriumParser::GT);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1353);
      typeArguments();
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

//----------------- NonWildcardTypeArgumentsOrDiamondContext ------------------------------------------------------------------

CoriumParser::NonWildcardTypeArgumentsOrDiamondContext::NonWildcardTypeArgumentsOrDiamondContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::NonWildcardTypeArgumentsOrDiamondContext::LT() {
  return getToken(CoriumParser::LT, 0);
}

tree::TerminalNode* CoriumParser::NonWildcardTypeArgumentsOrDiamondContext::GT() {
  return getToken(CoriumParser::GT, 0);
}

CoriumParser::NonWildcardTypeArgumentsContext* CoriumParser::NonWildcardTypeArgumentsOrDiamondContext::nonWildcardTypeArguments() {
  return getRuleContext<CoriumParser::NonWildcardTypeArgumentsContext>(0);
}


size_t CoriumParser::NonWildcardTypeArgumentsOrDiamondContext::getRuleIndex() const {
  return CoriumParser::RuleNonWildcardTypeArgumentsOrDiamond;
}

void CoriumParser::NonWildcardTypeArgumentsOrDiamondContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNonWildcardTypeArgumentsOrDiamond(this);
}

void CoriumParser::NonWildcardTypeArgumentsOrDiamondContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNonWildcardTypeArgumentsOrDiamond(this);
}

CoriumParser::NonWildcardTypeArgumentsOrDiamondContext* CoriumParser::nonWildcardTypeArgumentsOrDiamond() {
  NonWildcardTypeArgumentsOrDiamondContext *_localctx = _tracker.createInstance<NonWildcardTypeArgumentsOrDiamondContext>(_ctx, getState());
  enterRule(_localctx, 192, CoriumParser::RuleNonWildcardTypeArgumentsOrDiamond);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1359);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 167, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1356);
      match(CoriumParser::LT);
      setState(1357);
      match(CoriumParser::GT);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1358);
      nonWildcardTypeArguments();
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

//----------------- NonWildcardTypeArgumentsContext ------------------------------------------------------------------

CoriumParser::NonWildcardTypeArgumentsContext::NonWildcardTypeArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::NonWildcardTypeArgumentsContext::LT() {
  return getToken(CoriumParser::LT, 0);
}

CoriumParser::TypeListContext* CoriumParser::NonWildcardTypeArgumentsContext::typeList() {
  return getRuleContext<CoriumParser::TypeListContext>(0);
}

tree::TerminalNode* CoriumParser::NonWildcardTypeArgumentsContext::GT() {
  return getToken(CoriumParser::GT, 0);
}


size_t CoriumParser::NonWildcardTypeArgumentsContext::getRuleIndex() const {
  return CoriumParser::RuleNonWildcardTypeArguments;
}

void CoriumParser::NonWildcardTypeArgumentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNonWildcardTypeArguments(this);
}

void CoriumParser::NonWildcardTypeArgumentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNonWildcardTypeArguments(this);
}

CoriumParser::NonWildcardTypeArgumentsContext* CoriumParser::nonWildcardTypeArguments() {
  NonWildcardTypeArgumentsContext *_localctx = _tracker.createInstance<NonWildcardTypeArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 194, CoriumParser::RuleNonWildcardTypeArguments);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1361);
    match(CoriumParser::LT);
    setState(1362);
    typeList();
    setState(1363);
    match(CoriumParser::GT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeListContext ------------------------------------------------------------------

CoriumParser::TypeListContext::TypeListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CoriumParser::TypeTypeContext *> CoriumParser::TypeListContext::typeType() {
  return getRuleContexts<CoriumParser::TypeTypeContext>();
}

CoriumParser::TypeTypeContext* CoriumParser::TypeListContext::typeType(size_t i) {
  return getRuleContext<CoriumParser::TypeTypeContext>(i);
}

std::vector<tree::TerminalNode *> CoriumParser::TypeListContext::COMMA() {
  return getTokens(CoriumParser::COMMA);
}

tree::TerminalNode* CoriumParser::TypeListContext::COMMA(size_t i) {
  return getToken(CoriumParser::COMMA, i);
}


size_t CoriumParser::TypeListContext::getRuleIndex() const {
  return CoriumParser::RuleTypeList;
}

void CoriumParser::TypeListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeList(this);
}

void CoriumParser::TypeListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeList(this);
}

CoriumParser::TypeListContext* CoriumParser::typeList() {
  TypeListContext *_localctx = _tracker.createInstance<TypeListContext>(_ctx, getState());
  enterRule(_localctx, 196, CoriumParser::RuleTypeList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1365);
    typeType();
    setState(1370);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CoriumParser::COMMA) {
      setState(1366);
      match(CoriumParser::COMMA);
      setState(1367);
      typeType();
      setState(1372);
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

//----------------- TypeTypeContext ------------------------------------------------------------------

CoriumParser::TypeTypeContext::TypeTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::ClassOrInterfaceTypeContext* CoriumParser::TypeTypeContext::classOrInterfaceType() {
  return getRuleContext<CoriumParser::ClassOrInterfaceTypeContext>(0);
}

CoriumParser::PrimitiveTypeContext* CoriumParser::TypeTypeContext::primitiveType() {
  return getRuleContext<CoriumParser::PrimitiveTypeContext>(0);
}

std::vector<CoriumParser::AnnotationContext *> CoriumParser::TypeTypeContext::annotation() {
  return getRuleContexts<CoriumParser::AnnotationContext>();
}

CoriumParser::AnnotationContext* CoriumParser::TypeTypeContext::annotation(size_t i) {
  return getRuleContext<CoriumParser::AnnotationContext>(i);
}

std::vector<tree::TerminalNode *> CoriumParser::TypeTypeContext::LBRACK() {
  return getTokens(CoriumParser::LBRACK);
}

tree::TerminalNode* CoriumParser::TypeTypeContext::LBRACK(size_t i) {
  return getToken(CoriumParser::LBRACK, i);
}

std::vector<tree::TerminalNode *> CoriumParser::TypeTypeContext::RBRACK() {
  return getTokens(CoriumParser::RBRACK);
}

tree::TerminalNode* CoriumParser::TypeTypeContext::RBRACK(size_t i) {
  return getToken(CoriumParser::RBRACK, i);
}


size_t CoriumParser::TypeTypeContext::getRuleIndex() const {
  return CoriumParser::RuleTypeType;
}

void CoriumParser::TypeTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeType(this);
}

void CoriumParser::TypeTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeType(this);
}

CoriumParser::TypeTypeContext* CoriumParser::typeType() {
  TypeTypeContext *_localctx = _tracker.createInstance<TypeTypeContext>(_ctx, getState());
  enterRule(_localctx, 198, CoriumParser::RuleTypeType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1376);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 169, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(1373);
        annotation(); 
      }
      setState(1378);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 169, _ctx);
    }
    setState(1381);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CoriumParser::IDENTIFIER: {
        setState(1379);
        classOrInterfaceType();
        break;
      }

      case CoriumParser::BOOLEAN:
      case CoriumParser::BYTE:
      case CoriumParser::CHAR:
      case CoriumParser::DOUBLE:
      case CoriumParser::FLOAT:
      case CoriumParser::INT:
      case CoriumParser::LONG:
      case CoriumParser::SHORT: {
        setState(1380);
        primitiveType();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(1393);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 172, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(1386);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CoriumParser::AT

        || _la == CoriumParser::IDENTIFIER) {
          setState(1383);
          annotation();
          setState(1388);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(1389);
        match(CoriumParser::LBRACK);
        setState(1390);
        match(CoriumParser::RBRACK); 
      }
      setState(1395);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 172, _ctx);
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

tree::TerminalNode* CoriumParser::PrimitiveTypeContext::BOOLEAN() {
  return getToken(CoriumParser::BOOLEAN, 0);
}

tree::TerminalNode* CoriumParser::PrimitiveTypeContext::CHAR() {
  return getToken(CoriumParser::CHAR, 0);
}

tree::TerminalNode* CoriumParser::PrimitiveTypeContext::BYTE() {
  return getToken(CoriumParser::BYTE, 0);
}

tree::TerminalNode* CoriumParser::PrimitiveTypeContext::SHORT() {
  return getToken(CoriumParser::SHORT, 0);
}

tree::TerminalNode* CoriumParser::PrimitiveTypeContext::INT() {
  return getToken(CoriumParser::INT, 0);
}

tree::TerminalNode* CoriumParser::PrimitiveTypeContext::LONG() {
  return getToken(CoriumParser::LONG, 0);
}

tree::TerminalNode* CoriumParser::PrimitiveTypeContext::FLOAT() {
  return getToken(CoriumParser::FLOAT, 0);
}

tree::TerminalNode* CoriumParser::PrimitiveTypeContext::DOUBLE() {
  return getToken(CoriumParser::DOUBLE, 0);
}


size_t CoriumParser::PrimitiveTypeContext::getRuleIndex() const {
  return CoriumParser::RulePrimitiveType;
}

void CoriumParser::PrimitiveTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimitiveType(this);
}

void CoriumParser::PrimitiveTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimitiveType(this);
}

CoriumParser::PrimitiveTypeContext* CoriumParser::primitiveType() {
  PrimitiveTypeContext *_localctx = _tracker.createInstance<PrimitiveTypeContext>(_ctx, getState());
  enterRule(_localctx, 200, CoriumParser::RulePrimitiveType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1396);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CoriumParser::BOOLEAN)
      | (1ULL << CoriumParser::BYTE)
      | (1ULL << CoriumParser::CHAR)
      | (1ULL << CoriumParser::DOUBLE)
      | (1ULL << CoriumParser::FLOAT)
      | (1ULL << CoriumParser::INT)
      | (1ULL << CoriumParser::LONG)
      | (1ULL << CoriumParser::SHORT))) != 0))) {
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

//----------------- TypeArgumentsContext ------------------------------------------------------------------

CoriumParser::TypeArgumentsContext::TypeArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::TypeArgumentsContext::LT() {
  return getToken(CoriumParser::LT, 0);
}

std::vector<CoriumParser::TypeArgumentContext *> CoriumParser::TypeArgumentsContext::typeArgument() {
  return getRuleContexts<CoriumParser::TypeArgumentContext>();
}

CoriumParser::TypeArgumentContext* CoriumParser::TypeArgumentsContext::typeArgument(size_t i) {
  return getRuleContext<CoriumParser::TypeArgumentContext>(i);
}

tree::TerminalNode* CoriumParser::TypeArgumentsContext::GT() {
  return getToken(CoriumParser::GT, 0);
}

std::vector<tree::TerminalNode *> CoriumParser::TypeArgumentsContext::COMMA() {
  return getTokens(CoriumParser::COMMA);
}

tree::TerminalNode* CoriumParser::TypeArgumentsContext::COMMA(size_t i) {
  return getToken(CoriumParser::COMMA, i);
}


size_t CoriumParser::TypeArgumentsContext::getRuleIndex() const {
  return CoriumParser::RuleTypeArguments;
}

void CoriumParser::TypeArgumentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeArguments(this);
}

void CoriumParser::TypeArgumentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeArguments(this);
}

CoriumParser::TypeArgumentsContext* CoriumParser::typeArguments() {
  TypeArgumentsContext *_localctx = _tracker.createInstance<TypeArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 202, CoriumParser::RuleTypeArguments);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1398);
    match(CoriumParser::LT);
    setState(1399);
    typeArgument();
    setState(1404);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CoriumParser::COMMA) {
      setState(1400);
      match(CoriumParser::COMMA);
      setState(1401);
      typeArgument();
      setState(1406);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1407);
    match(CoriumParser::GT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SuperSuffixContext ------------------------------------------------------------------

CoriumParser::SuperSuffixContext::SuperSuffixContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoriumParser::ArgumentsContext* CoriumParser::SuperSuffixContext::arguments() {
  return getRuleContext<CoriumParser::ArgumentsContext>(0);
}

tree::TerminalNode* CoriumParser::SuperSuffixContext::DOT() {
  return getToken(CoriumParser::DOT, 0);
}

tree::TerminalNode* CoriumParser::SuperSuffixContext::IDENTIFIER() {
  return getToken(CoriumParser::IDENTIFIER, 0);
}


size_t CoriumParser::SuperSuffixContext::getRuleIndex() const {
  return CoriumParser::RuleSuperSuffix;
}

void CoriumParser::SuperSuffixContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSuperSuffix(this);
}

void CoriumParser::SuperSuffixContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSuperSuffix(this);
}

CoriumParser::SuperSuffixContext* CoriumParser::superSuffix() {
  SuperSuffixContext *_localctx = _tracker.createInstance<SuperSuffixContext>(_ctx, getState());
  enterRule(_localctx, 204, CoriumParser::RuleSuperSuffix);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1415);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CoriumParser::LPAREN: {
        enterOuterAlt(_localctx, 1);
        setState(1409);
        arguments();
        break;
      }

      case CoriumParser::DOT: {
        enterOuterAlt(_localctx, 2);
        setState(1410);
        match(CoriumParser::DOT);
        setState(1411);
        match(CoriumParser::IDENTIFIER);
        setState(1413);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 174, _ctx)) {
        case 1: {
          setState(1412);
          arguments();
          break;
        }

        }
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

//----------------- ExplicitGenericInvocationSuffixContext ------------------------------------------------------------------

CoriumParser::ExplicitGenericInvocationSuffixContext::ExplicitGenericInvocationSuffixContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::ExplicitGenericInvocationSuffixContext::SUPER() {
  return getToken(CoriumParser::SUPER, 0);
}

CoriumParser::SuperSuffixContext* CoriumParser::ExplicitGenericInvocationSuffixContext::superSuffix() {
  return getRuleContext<CoriumParser::SuperSuffixContext>(0);
}

tree::TerminalNode* CoriumParser::ExplicitGenericInvocationSuffixContext::IDENTIFIER() {
  return getToken(CoriumParser::IDENTIFIER, 0);
}

CoriumParser::ArgumentsContext* CoriumParser::ExplicitGenericInvocationSuffixContext::arguments() {
  return getRuleContext<CoriumParser::ArgumentsContext>(0);
}


size_t CoriumParser::ExplicitGenericInvocationSuffixContext::getRuleIndex() const {
  return CoriumParser::RuleExplicitGenericInvocationSuffix;
}

void CoriumParser::ExplicitGenericInvocationSuffixContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExplicitGenericInvocationSuffix(this);
}

void CoriumParser::ExplicitGenericInvocationSuffixContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExplicitGenericInvocationSuffix(this);
}

CoriumParser::ExplicitGenericInvocationSuffixContext* CoriumParser::explicitGenericInvocationSuffix() {
  ExplicitGenericInvocationSuffixContext *_localctx = _tracker.createInstance<ExplicitGenericInvocationSuffixContext>(_ctx, getState());
  enterRule(_localctx, 206, CoriumParser::RuleExplicitGenericInvocationSuffix);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1421);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CoriumParser::SUPER: {
        enterOuterAlt(_localctx, 1);
        setState(1417);
        match(CoriumParser::SUPER);
        setState(1418);
        superSuffix();
        break;
      }

      case CoriumParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(1419);
        match(CoriumParser::IDENTIFIER);
        setState(1420);
        arguments();
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

//----------------- ArgumentsContext ------------------------------------------------------------------

CoriumParser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoriumParser::ArgumentsContext::LPAREN() {
  return getToken(CoriumParser::LPAREN, 0);
}

tree::TerminalNode* CoriumParser::ArgumentsContext::RPAREN() {
  return getToken(CoriumParser::RPAREN, 0);
}

CoriumParser::ExpressionListContext* CoriumParser::ArgumentsContext::expressionList() {
  return getRuleContext<CoriumParser::ExpressionListContext>(0);
}


size_t CoriumParser::ArgumentsContext::getRuleIndex() const {
  return CoriumParser::RuleArguments;
}

void CoriumParser::ArgumentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArguments(this);
}

void CoriumParser::ArgumentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CoriumParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArguments(this);
}

CoriumParser::ArgumentsContext* CoriumParser::arguments() {
  ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 208, CoriumParser::RuleArguments);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1423);
    match(CoriumParser::LPAREN);
    setState(1425);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CoriumParser::BOOLEAN)
      | (1ULL << CoriumParser::BYTE)
      | (1ULL << CoriumParser::CHAR)
      | (1ULL << CoriumParser::DOUBLE)
      | (1ULL << CoriumParser::FLOAT)
      | (1ULL << CoriumParser::INT)
      | (1ULL << CoriumParser::LONG)
      | (1ULL << CoriumParser::NEW)
      | (1ULL << CoriumParser::SHORT)
      | (1ULL << CoriumParser::SUPER)
      | (1ULL << CoriumParser::THIS)
      | (1ULL << CoriumParser::VOID)
      | (1ULL << CoriumParser::DECIMAL_LITERAL)
      | (1ULL << CoriumParser::HEX_LITERAL)
      | (1ULL << CoriumParser::OCT_LITERAL)
      | (1ULL << CoriumParser::BINARY_LITERAL)
      | (1ULL << CoriumParser::FLOAT_LITERAL)
      | (1ULL << CoriumParser::HEX_FLOAT_LITERAL)
      | (1ULL << CoriumParser::BOOL_LITERAL)
      | (1ULL << CoriumParser::CHAR_LITERAL)
      | (1ULL << CoriumParser::STRING_LITERAL)
      | (1ULL << CoriumParser::NULL_LITERAL)
      | (1ULL << CoriumParser::LPAREN))) != 0) || ((((_la - 72) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 72)) & ((1ULL << (CoriumParser::LT - 72))
      | (1ULL << (CoriumParser::BANG - 72))
      | (1ULL << (CoriumParser::TILDE - 72))
      | (1ULL << (CoriumParser::INC - 72))
      | (1ULL << (CoriumParser::DEC - 72))
      | (1ULL << (CoriumParser::ADD - 72))
      | (1ULL << (CoriumParser::SUB - 72))
      | (1ULL << (CoriumParser::AT - 72))
      | (1ULL << (CoriumParser::IDENTIFIER - 72)))) != 0)) {
      setState(1424);
      expressionList();
    }
    setState(1427);
    match(CoriumParser::RPAREN);
   
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
    case 83: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool CoriumParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 17);
    case 1: return precpred(_ctx, 16);
    case 2: return precpred(_ctx, 15);
    case 3: return precpred(_ctx, 14);
    case 4: return precpred(_ctx, 12);
    case 5: return precpred(_ctx, 11);
    case 6: return precpred(_ctx, 10);
    case 7: return precpred(_ctx, 9);
    case 8: return precpred(_ctx, 8);
    case 9: return precpred(_ctx, 7);
    case 10: return precpred(_ctx, 6);
    case 11: return precpred(_ctx, 5);
    case 12: return precpred(_ctx, 25);
    case 13: return precpred(_ctx, 24);
    case 14: return precpred(_ctx, 20);
    case 15: return precpred(_ctx, 13);
    case 16: return precpred(_ctx, 3);

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
  "compilationUnit", "packageDeclaration", "importDeclaration", "typeDeclaration", 
  "modifier", "classOrInterfaceModifier", "variableModifier", "classDeclaration", 
  "typeParameters", "typeParameter", "typeBound", "enumDeclaration", "enumConstants", 
  "enumConstant", "enumBodyDeclarations", "interfaceDeclaration", "classBody", 
  "interfaceBody", "classBodyDeclaration", "memberDeclaration", "methodDeclaration", 
  "methodBody", "typeTypeOrVoid", "genericMethodDeclaration", "genericConstructorDeclaration", 
  "constructorDeclaration", "fieldDeclaration", "interfaceBodyDeclaration", 
  "interfaceMemberDeclaration", "constDeclaration", "constantDeclarator", 
  "interfaceMethodDeclaration", "interfaceMethodModifier", "genericInterfaceMethodDeclaration", 
  "variableDeclarators", "variableDeclarator", "variableDeclaratorId", "variableInitializer", 
  "arrayInitializer", "classOrInterfaceType", "typeArgument", "qualifiedNameList", 
  "formalParameters", "formalParameterList", "formalParameter", "lastFormalParameter", 
  "qualifiedName", "literal", "integerLiteral", "floatLiteral", "altAnnotationQualifiedName", 
  "annotation", "elementValuePairs", "elementValuePair", "elementValue", 
  "elementValueArrayInitializer", "annotationTypeDeclaration", "annotationTypeBody", 
  "annotationTypeElementDeclaration", "annotationTypeElementRest", "annotationMethodOrConstantRest", 
  "annotationMethodRest", "annotationConstantRest", "defaultValue", "block", 
  "blockStatement", "localVariableDeclaration", "localTypeDeclaration", 
  "statement", "catchClause", "catchType", "finallyBlock", "resourceSpecification", 
  "resources", "resource", "switchBlockStatementGroup", "switchLabel", "forControl", 
  "forInit", "enhancedForControl", "parExpression", "expressionList", "methodCall", 
  "expression", "lambdaExpression", "lambdaParameters", "lambdaBody", "primary", 
  "classType", "creator", "createdName", "innerCreator", "arrayCreatorRest", 
  "classCreatorRest", "explicitGenericInvocation", "typeArgumentsOrDiamond", 
  "nonWildcardTypeArgumentsOrDiamond", "nonWildcardTypeArguments", "typeList", 
  "typeType", "primitiveType", "typeArguments", "superSuffix", "explicitGenericInvocationSuffix", 
  "arguments"
};

std::vector<std::string> CoriumParser::_literalNames = {
  "", "'abstract'", "'assert'", "'boolean'", "'break'", "'byte'", "'case'", 
  "'catch'", "'char'", "'class'", "'const'", "'continue'", "'default'", 
  "'do'", "'double'", "'else'", "'enum'", "'extends'", "'final'", "'finally'", 
  "'float'", "'for'", "'if'", "'goto'", "'implements'", "'import'", "'instanceof'", 
  "'int'", "'interface'", "'long'", "'native'", "'new'", "'package'", "'private'", 
  "'protected'", "'public'", "'return'", "'short'", "'static'", "'strictfp'", 
  "'super'", "'switch'", "'synchronized'", "'this'", "'throw'", "'throws'", 
  "'transient'", "'try'", "'void'", "'volatile'", "'while'", "", "", "", 
  "", "", "", "", "", "", "'null'", "'('", "')'", "'{'", "'}'", "'['", "']'", 
  "';'", "','", "'.'", "'='", "'>'", "'<'", "'!'", "'~'", "'?'", "':'", 
  "'=='", "'<='", "'>='", "'!='", "'&&'", "'||'", "'++'", "'--'", "'+'", 
  "'-'", "'*'", "'/'", "'&'", "'|'", "'^'", "'%'", "'+='", "'-='", "'*='", 
  "'/='", "'&='", "'|='", "'^='", "'%='", "'<<='", "'>>='", "'>>>='", "'->'", 
  "'::'", "'@'", "'...'"
};

std::vector<std::string> CoriumParser::_symbolicNames = {
  "", "ABSTRACT", "ASSERT", "BOOLEAN", "BREAK", "BYTE", "CASE", "CATCH", 
  "CHAR", "CLASS", "CONST", "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE", 
  "ENUM", "EXTENDS", "FINAL", "FINALLY", "FLOAT", "FOR", "IF", "GOTO", "IMPLEMENTS", 
  "IMPORT", "INSTANCEOF", "INT", "INTERFACE", "LONG", "NATIVE", "NEW", "PACKAGE", 
  "PRIVATE", "PROTECTED", "PUBLIC", "RETURN", "SHORT", "STATIC", "STRICTFP", 
  "SUPER", "SWITCH", "SYNCHRONIZED", "THIS", "THROW", "THROWS", "TRANSIENT", 
  "TRY", "VOID", "VOLATILE", "WHILE", "DECIMAL_LITERAL", "HEX_LITERAL", 
  "OCT_LITERAL", "BINARY_LITERAL", "FLOAT_LITERAL", "HEX_FLOAT_LITERAL", 
  "BOOL_LITERAL", "CHAR_LITERAL", "STRING_LITERAL", "NULL_LITERAL", "LPAREN", 
  "RPAREN", "LBRACE", "RBRACE", "LBRACK", "RBRACK", "SEMI", "COMMA", "DOT", 
  "ASSIGN", "GT", "LT", "BANG", "TILDE", "QUESTION", "COLON", "EQUAL", "LE", 
  "GE", "NOTEQUAL", "AND", "OR", "INC", "DEC", "ADD", "SUB", "MUL", "DIV", 
  "BITAND", "BITOR", "CARET", "MOD", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", 
  "DIV_ASSIGN", "AND_ASSIGN", "OR_ASSIGN", "XOR_ASSIGN", "MOD_ASSIGN", "LSHIFT_ASSIGN", 
  "RSHIFT_ASSIGN", "URSHIFT_ASSIGN", "ARROW", "COLONCOLON", "AT", "ELLIPSIS", 
  "WS", "COMMENT", "LINE_COMMENT", "IDENTIFIER"
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
    0x3, 0x71, 0x598, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 
    0x2c, 0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
    0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 0x9, 
    0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 0x9, 0x35, 
    0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 0x9, 0x38, 0x4, 
    0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 0x9, 0x3b, 0x4, 0x3c, 
    0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 0x9, 0x3e, 0x4, 0x3f, 0x9, 
    0x3f, 0x4, 0x40, 0x9, 0x40, 0x4, 0x41, 0x9, 0x41, 0x4, 0x42, 0x9, 0x42, 
    0x4, 0x43, 0x9, 0x43, 0x4, 0x44, 0x9, 0x44, 0x4, 0x45, 0x9, 0x45, 0x4, 
    0x46, 0x9, 0x46, 0x4, 0x47, 0x9, 0x47, 0x4, 0x48, 0x9, 0x48, 0x4, 0x49, 
    0x9, 0x49, 0x4, 0x4a, 0x9, 0x4a, 0x4, 0x4b, 0x9, 0x4b, 0x4, 0x4c, 0x9, 
    0x4c, 0x4, 0x4d, 0x9, 0x4d, 0x4, 0x4e, 0x9, 0x4e, 0x4, 0x4f, 0x9, 0x4f, 
    0x4, 0x50, 0x9, 0x50, 0x4, 0x51, 0x9, 0x51, 0x4, 0x52, 0x9, 0x52, 0x4, 
    0x53, 0x9, 0x53, 0x4, 0x54, 0x9, 0x54, 0x4, 0x55, 0x9, 0x55, 0x4, 0x56, 
    0x9, 0x56, 0x4, 0x57, 0x9, 0x57, 0x4, 0x58, 0x9, 0x58, 0x4, 0x59, 0x9, 
    0x59, 0x4, 0x5a, 0x9, 0x5a, 0x4, 0x5b, 0x9, 0x5b, 0x4, 0x5c, 0x9, 0x5c, 
    0x4, 0x5d, 0x9, 0x5d, 0x4, 0x5e, 0x9, 0x5e, 0x4, 0x5f, 0x9, 0x5f, 0x4, 
    0x60, 0x9, 0x60, 0x4, 0x61, 0x9, 0x61, 0x4, 0x62, 0x9, 0x62, 0x4, 0x63, 
    0x9, 0x63, 0x4, 0x64, 0x9, 0x64, 0x4, 0x65, 0x9, 0x65, 0x4, 0x66, 0x9, 
    0x66, 0x4, 0x67, 0x9, 0x67, 0x4, 0x68, 0x9, 0x68, 0x4, 0x69, 0x9, 0x69, 
    0x4, 0x6a, 0x9, 0x6a, 0x3, 0x2, 0x5, 0x2, 0xd6, 0xa, 0x2, 0x3, 0x2, 
    0x7, 0x2, 0xd9, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0xdc, 0xb, 0x2, 0x3, 0x2, 
    0x7, 0x2, 0xdf, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0xe2, 0xb, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x3, 0x7, 0x3, 0xe7, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0xea, 
    0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 
    0x5, 0x4, 0xf2, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0xf7, 
    0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x7, 0x5, 0xfc, 0xa, 0x5, 0xc, 
    0x5, 0xe, 0x5, 0xff, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x5, 0x5, 0x105, 0xa, 0x5, 0x3, 0x5, 0x5, 0x5, 0x108, 0xa, 0x5, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x10f, 0xa, 0x6, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x5, 0x7, 0x119, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x11d, 
    0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x122, 0xa, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x5, 0x9, 0x126, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 
    0x12a, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x7, 0xa, 0x132, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x135, 0xb, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x7, 0xb, 0x13a, 0xa, 0xb, 0xc, 0xb, 0xe, 
    0xb, 0x13d, 0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0x142, 
    0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x145, 0xb, 0xb, 0x3, 0xb, 0x5, 0xb, 0x148, 
    0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0x14d, 0xa, 0xc, 0xc, 
    0xc, 0xe, 0xc, 0x150, 0xb, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x5, 0xd, 0x156, 0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x15a, 0xa, 
    0xd, 0x3, 0xd, 0x5, 0xd, 0x15d, 0xa, 0xd, 0x3, 0xd, 0x5, 0xd, 0x160, 
    0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 
    0x167, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0x16a, 0xb, 0xe, 0x3, 0xf, 0x7, 
    0xf, 0x16d, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0x170, 0xb, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x5, 0xf, 0x174, 0xa, 0xf, 0x3, 0xf, 0x5, 0xf, 0x177, 0xa, 
    0xf, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0x17b, 0xa, 0x10, 0xc, 0x10, 0xe, 
    0x10, 0x17e, 0xb, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 
    0x183, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x187, 0xa, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x7, 0x12, 0x18d, 0xa, 0x12, 
    0xc, 0x12, 0xe, 0x12, 0x190, 0xb, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 
    0x3, 0x13, 0x7, 0x13, 0x196, 0xa, 0x13, 0xc, 0x13, 0xe, 0x13, 0x199, 
    0xb, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0x19f, 
    0xa, 0x14, 0x3, 0x14, 0x3, 0x14, 0x7, 0x14, 0x1a3, 0xa, 0x14, 0xc, 0x14, 
    0xe, 0x14, 0x1a6, 0xb, 0x14, 0x3, 0x14, 0x5, 0x14, 0x1a9, 0xa, 0x14, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0x1b4, 0xa, 0x15, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x7, 0x16, 0x1bb, 0xa, 0x16, 
    0xc, 0x16, 0xe, 0x16, 0x1be, 0xb, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 
    0x1c2, 0xa, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 
    0x1c8, 0xa, 0x17, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0x1cc, 0xa, 0x18, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 
    0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0x1d8, 0xa, 0x1b, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 
    0x1d, 0x7, 0x1d, 0x1e1, 0xa, 0x1d, 0xc, 0x1d, 0xe, 0x1d, 0x1e4, 0xb, 
    0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x1e8, 0xa, 0x1d, 0x3, 0x1e, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x5, 
    0x1e, 0x1f1, 0xa, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 
    0x7, 0x1f, 0x1f7, 0xa, 0x1f, 0xc, 0x1f, 0xe, 0x1f, 0x1fa, 0xb, 0x1f, 
    0x3, 0x1f, 0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x7, 0x20, 0x201, 
    0xa, 0x20, 0xc, 0x20, 0xe, 0x20, 0x204, 0xb, 0x20, 0x3, 0x20, 0x3, 0x20, 
    0x3, 0x20, 0x3, 0x21, 0x7, 0x21, 0x20a, 0xa, 0x21, 0xc, 0x21, 0xe, 0x21, 
    0x20d, 0xb, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x7, 0x21, 0x212, 
    0xa, 0x21, 0xc, 0x21, 0xe, 0x21, 0x215, 0xb, 0x21, 0x3, 0x21, 0x3, 0x21, 
    0x5, 0x21, 0x219, 0xa, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 
    0x7, 0x21, 0x21f, 0xa, 0x21, 0xc, 0x21, 0xe, 0x21, 0x222, 0xb, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x226, 0xa, 0x21, 0x3, 0x21, 0x3, 0x21, 
    0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x5, 
    0x22, 0x230, 0xa, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 
    0x3, 0x24, 0x3, 0x24, 0x7, 0x24, 0x238, 0xa, 0x24, 0xc, 0x24, 0xe, 0x24, 
    0x23b, 0xb, 0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x240, 
    0xa, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x7, 0x26, 0x245, 0xa, 0x26, 
    0xc, 0x26, 0xe, 0x26, 0x248, 0xb, 0x26, 0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 
    0x24c, 0xa, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x7, 0x28, 
    0x252, 0xa, 0x28, 0xc, 0x28, 0xe, 0x28, 0x255, 0xb, 0x28, 0x3, 0x28, 
    0x5, 0x28, 0x258, 0xa, 0x28, 0x5, 0x28, 0x25a, 0xa, 0x28, 0x3, 0x28, 
    0x3, 0x28, 0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x260, 0xa, 0x29, 0x3, 0x29, 
    0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x265, 0xa, 0x29, 0x7, 0x29, 0x267, 
    0xa, 0x29, 0xc, 0x29, 0xe, 0x29, 0x26a, 0xb, 0x29, 0x3, 0x2a, 0x3, 0x2a, 
    0x7, 0x2a, 0x26e, 0xa, 0x2a, 0xc, 0x2a, 0xe, 0x2a, 0x271, 0xb, 0x2a, 
    0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x276, 0xa, 0x2a, 0x5, 0x2a, 
    0x278, 0xa, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x7, 0x2b, 0x27d, 
    0xa, 0x2b, 0xc, 0x2b, 0xe, 0x2b, 0x280, 0xb, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 
    0x5, 0x2c, 0x284, 0xa, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 
    0x3, 0x2d, 0x7, 0x2d, 0x28b, 0xa, 0x2d, 0xc, 0x2d, 0xe, 0x2d, 0x28e, 
    0xb, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 0x292, 0xa, 0x2d, 0x3, 0x2d, 
    0x5, 0x2d, 0x295, 0xa, 0x2d, 0x3, 0x2e, 0x7, 0x2e, 0x298, 0xa, 0x2e, 
    0xc, 0x2e, 0xe, 0x2e, 0x29b, 0xb, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 
    0x3, 0x2f, 0x7, 0x2f, 0x2a1, 0xa, 0x2f, 0xc, 0x2f, 0xe, 0x2f, 0x2a4, 
    0xb, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x7, 0x2f, 0x2a8, 0xa, 0x2f, 0xc, 0x2f, 
    0xe, 0x2f, 0x2ab, 0xb, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x30, 
    0x3, 0x30, 0x3, 0x30, 0x7, 0x30, 0x2b3, 0xa, 0x30, 0xc, 0x30, 0xe, 0x30, 
    0x2b6, 0xb, 0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 
    0x3, 0x31, 0x5, 0x31, 0x2be, 0xa, 0x31, 0x3, 0x32, 0x3, 0x32, 0x3, 0x33, 
    0x3, 0x33, 0x3, 0x34, 0x3, 0x34, 0x7, 0x34, 0x2c6, 0xa, 0x34, 0xc, 0x34, 
    0xe, 0x34, 0x2c9, 0xb, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x35, 
    0x3, 0x35, 0x3, 0x35, 0x5, 0x35, 0x2d1, 0xa, 0x35, 0x3, 0x35, 0x3, 0x35, 
    0x3, 0x35, 0x5, 0x35, 0x2d6, 0xa, 0x35, 0x3, 0x35, 0x5, 0x35, 0x2d9, 
    0xa, 0x35, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x7, 0x36, 0x2de, 0xa, 0x36, 
    0xc, 0x36, 0xe, 0x36, 0x2e1, 0xb, 0x36, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 
    0x3, 0x37, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x5, 0x38, 0x2ea, 0xa, 0x38, 
    0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x7, 0x39, 0x2f0, 0xa, 0x39, 
    0xc, 0x39, 0xe, 0x39, 0x2f3, 0xb, 0x39, 0x5, 0x39, 0x2f5, 0xa, 0x39, 
    0x3, 0x39, 0x5, 0x39, 0x2f8, 0xa, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x3a, 
    0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3b, 0x3, 0x3b, 0x7, 
    0x3b, 0x303, 0xa, 0x3b, 0xc, 0x3b, 0xe, 0x3b, 0x306, 0xb, 0x3b, 0x3, 
    0x3b, 0x3, 0x3b, 0x3, 0x3c, 0x7, 0x3c, 0x30b, 0xa, 0x3c, 0xc, 0x3c, 
    0xe, 0x3c, 0x30e, 0xb, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x5, 0x3c, 0x312, 
    0xa, 0x3c, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 
    0x3d, 0x5, 0x3d, 0x31a, 0xa, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x5, 0x3d, 
    0x31e, 0xa, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x5, 0x3d, 0x322, 0xa, 0x3d, 
    0x3, 0x3d, 0x3, 0x3d, 0x5, 0x3d, 0x326, 0xa, 0x3d, 0x5, 0x3d, 0x328, 
    0xa, 0x3d, 0x3, 0x3e, 0x3, 0x3e, 0x5, 0x3e, 0x32c, 0xa, 0x3e, 0x3, 0x3f, 
    0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x5, 0x3f, 0x332, 0xa, 0x3f, 0x3, 0x40, 
    0x3, 0x40, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x42, 0x3, 0x42, 0x7, 
    0x42, 0x33b, 0xa, 0x42, 0xc, 0x42, 0xe, 0x42, 0x33e, 0xb, 0x42, 0x3, 
    0x42, 0x3, 0x42, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 
    0x5, 0x43, 0x347, 0xa, 0x43, 0x3, 0x44, 0x7, 0x44, 0x34a, 0xa, 0x44, 
    0xc, 0x44, 0xe, 0x44, 0x34d, 0xb, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 
    0x3, 0x45, 0x7, 0x45, 0x353, 0xa, 0x45, 0xc, 0x45, 0xe, 0x45, 0x356, 
    0xb, 0x45, 0x3, 0x45, 0x3, 0x45, 0x5, 0x45, 0x35a, 0xa, 0x45, 0x3, 0x45, 
    0x5, 0x45, 0x35d, 0xa, 0x45, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 
    0x3, 0x46, 0x5, 0x46, 0x364, 0xa, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 
    0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x5, 0x46, 0x36d, 0xa, 0x46, 
    0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 
    0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 
    0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x6, 
    0x46, 0x382, 0xa, 0x46, 0xd, 0x46, 0xe, 0x46, 0x383, 0x3, 0x46, 0x5, 
    0x46, 0x387, 0xa, 0x46, 0x3, 0x46, 0x5, 0x46, 0x38a, 0xa, 0x46, 0x3, 
    0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x7, 0x46, 0x390, 0xa, 0x46, 
    0xc, 0x46, 0xe, 0x46, 0x393, 0xb, 0x46, 0x3, 0x46, 0x5, 0x46, 0x396, 
    0xa, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x7, 0x46, 0x39c, 
    0xa, 0x46, 0xc, 0x46, 0xe, 0x46, 0x39f, 0xb, 0x46, 0x3, 0x46, 0x7, 0x46, 
    0x3a2, 0xa, 0x46, 0xc, 0x46, 0xe, 0x46, 0x3a5, 0xb, 0x46, 0x3, 0x46, 
    0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 
    0x46, 0x5, 0x46, 0x3af, 0xa, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 
    0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x5, 0x46, 0x3b8, 0xa, 0x46, 
    0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x5, 0x46, 0x3bd, 0xa, 0x46, 0x3, 0x46, 
    0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 
    0x46, 0x5, 0x46, 0x3c7, 0xa, 0x46, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 
    0x7, 0x47, 0x3cc, 0xa, 0x47, 0xc, 0x47, 0xe, 0x47, 0x3cf, 0xb, 0x47, 
    0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x48, 0x3, 
    0x48, 0x3, 0x48, 0x7, 0x48, 0x3d9, 0xa, 0x48, 0xc, 0x48, 0xe, 0x48, 
    0x3dc, 0xb, 0x48, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x4a, 0x3, 0x4a, 
    0x3, 0x4a, 0x5, 0x4a, 0x3e4, 0xa, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4b, 
    0x3, 0x4b, 0x3, 0x4b, 0x7, 0x4b, 0x3eb, 0xa, 0x4b, 0xc, 0x4b, 0xe, 0x4b, 
    0x3ee, 0xb, 0x4b, 0x3, 0x4c, 0x7, 0x4c, 0x3f1, 0xa, 0x4c, 0xc, 0x4c, 
    0xe, 0x4c, 0x3f4, 0xb, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 
    0x3, 0x4c, 0x3, 0x4d, 0x6, 0x4d, 0x3fc, 0xa, 0x4d, 0xd, 0x4d, 0xe, 0x4d, 
    0x3fd, 0x3, 0x4d, 0x6, 0x4d, 0x401, 0xa, 0x4d, 0xd, 0x4d, 0xe, 0x4d, 
    0x402, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x5, 0x4e, 0x408, 0xa, 0x4e, 
    0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x5, 0x4e, 0x40d, 0xa, 0x4e, 0x3, 0x4f, 
    0x3, 0x4f, 0x5, 0x4f, 0x411, 0xa, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x5, 0x4f, 
    0x415, 0xa, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x5, 0x4f, 0x419, 0xa, 0x4f, 
    0x5, 0x4f, 0x41b, 0xa, 0x4f, 0x3, 0x50, 0x3, 0x50, 0x5, 0x50, 0x41f, 
    0xa, 0x50, 0x3, 0x51, 0x7, 0x51, 0x422, 0xa, 0x51, 0xc, 0x51, 0xe, 0x51, 
    0x425, 0xb, 0x51, 0x3, 0x51, 0x3, 0x51, 0x3, 0x51, 0x3, 0x51, 0x3, 0x51, 
    0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x3, 0x53, 0x3, 0x53, 0x3, 
    0x53, 0x7, 0x53, 0x433, 0xa, 0x53, 0xc, 0x53, 0xe, 0x53, 0x436, 0xb, 
    0x53, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x5, 0x54, 0x43b, 0xa, 0x54, 
    0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x5, 0x54, 0x441, 0xa, 0x54, 
    0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x5, 0x54, 0x447, 0xa, 0x54, 
    0x3, 0x54, 0x5, 0x54, 0x44a, 0xa, 0x54, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 
    0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x7, 0x55, 0x453, 0xa, 0x55, 
    0xc, 0x55, 0xe, 0x55, 0x456, 0xb, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 
    0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 
    0x55, 0x3, 0x55, 0x3, 0x55, 0x5, 0x55, 0x464, 0xa, 0x55, 0x3, 0x55, 
    0x3, 0x55, 0x5, 0x55, 0x468, 0xa, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 
    0x5, 0x55, 0x46d, 0xa, 0x55, 0x3, 0x55, 0x3, 0x55, 0x5, 0x55, 0x471, 
    0xa, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 
    0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 
    0x3, 0x55, 0x3, 0x55, 0x5, 0x55, 0x481, 0xa, 0x55, 0x3, 0x55, 0x3, 0x55, 
    0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 
    0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 
    0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 
    0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 
    0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 
    0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x5, 0x55, 0x4a9, 0xa, 0x55, 
    0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x5, 0x55, 0x4af, 0xa, 0x55, 
    0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 
    0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 
    0x5, 0x55, 0x4be, 0xa, 0x55, 0x3, 0x55, 0x7, 0x55, 0x4c1, 0xa, 0x55, 
    0xc, 0x55, 0xe, 0x55, 0x4c4, 0xb, 0x55, 0x3, 0x56, 0x3, 0x56, 0x3, 0x56, 
    0x3, 0x56, 0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 0x5, 0x57, 0x4cd, 0xa, 0x57, 
    0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 0x7, 0x57, 0x4d4, 
    0xa, 0x57, 0xc, 0x57, 0xe, 0x57, 0x4d7, 0xb, 0x57, 0x3, 0x57, 0x5, 0x57, 
    0x4da, 0xa, 0x57, 0x3, 0x58, 0x3, 0x58, 0x5, 0x58, 0x4de, 0xa, 0x58, 
    0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 
    0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 
    0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x5, 0x59, 0x4f0, 0xa, 0x59, 0x5, 0x59, 
    0x4f2, 0xa, 0x59, 0x3, 0x5a, 0x3, 0x5a, 0x3, 0x5a, 0x5, 0x5a, 0x4f7, 
    0xa, 0x5a, 0x3, 0x5a, 0x7, 0x5a, 0x4fa, 0xa, 0x5a, 0xc, 0x5a, 0xe, 0x5a, 
    0x4fd, 0xb, 0x5a, 0x3, 0x5a, 0x3, 0x5a, 0x5, 0x5a, 0x501, 0xa, 0x5a, 
    0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5b, 0x3, 
    0x5b, 0x5, 0x5b, 0x50a, 0xa, 0x5b, 0x5, 0x5b, 0x50c, 0xa, 0x5b, 0x3, 
    0x5c, 0x3, 0x5c, 0x5, 0x5c, 0x510, 0xa, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 
    0x3, 0x5c, 0x5, 0x5c, 0x515, 0xa, 0x5c, 0x7, 0x5c, 0x517, 0xa, 0x5c, 
    0xc, 0x5c, 0xe, 0x5c, 0x51a, 0xb, 0x5c, 0x3, 0x5c, 0x5, 0x5c, 0x51d, 
    0xa, 0x5c, 0x3, 0x5d, 0x3, 0x5d, 0x5, 0x5d, 0x521, 0xa, 0x5d, 0x3, 0x5d, 
    0x3, 0x5d, 0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x7, 0x5e, 0x529, 
    0xa, 0x5e, 0xc, 0x5e, 0xe, 0x5e, 0x52c, 0xb, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 
    0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x7, 0x5e, 0x535, 
    0xa, 0x5e, 0xc, 0x5e, 0xe, 0x5e, 0x538, 0xb, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 
    0x7, 0x5e, 0x53c, 0xa, 0x5e, 0xc, 0x5e, 0xe, 0x5e, 0x53f, 0xb, 0x5e, 
    0x5, 0x5e, 0x541, 0xa, 0x5e, 0x3, 0x5f, 0x3, 0x5f, 0x5, 0x5f, 0x545, 
    0xa, 0x5f, 0x3, 0x60, 0x3, 0x60, 0x3, 0x60, 0x3, 0x61, 0x3, 0x61, 0x3, 
    0x61, 0x5, 0x61, 0x54d, 0xa, 0x61, 0x3, 0x62, 0x3, 0x62, 0x3, 0x62, 
    0x5, 0x62, 0x552, 0xa, 0x62, 0x3, 0x63, 0x3, 0x63, 0x3, 0x63, 0x3, 0x63, 
    0x3, 0x64, 0x3, 0x64, 0x3, 0x64, 0x7, 0x64, 0x55b, 0xa, 0x64, 0xc, 0x64, 
    0xe, 0x64, 0x55e, 0xb, 0x64, 0x3, 0x65, 0x7, 0x65, 0x561, 0xa, 0x65, 
    0xc, 0x65, 0xe, 0x65, 0x564, 0xb, 0x65, 0x3, 0x65, 0x3, 0x65, 0x5, 0x65, 
    0x568, 0xa, 0x65, 0x3, 0x65, 0x7, 0x65, 0x56b, 0xa, 0x65, 0xc, 0x65, 
    0xe, 0x65, 0x56e, 0xb, 0x65, 0x3, 0x65, 0x3, 0x65, 0x7, 0x65, 0x572, 
    0xa, 0x65, 0xc, 0x65, 0xe, 0x65, 0x575, 0xb, 0x65, 0x3, 0x66, 0x3, 0x66, 
    0x3, 0x67, 0x3, 0x67, 0x3, 0x67, 0x3, 0x67, 0x7, 0x67, 0x57d, 0xa, 0x67, 
    0xc, 0x67, 0xe, 0x67, 0x580, 0xb, 0x67, 0x3, 0x67, 0x3, 0x67, 0x3, 0x68, 
    0x3, 0x68, 0x3, 0x68, 0x3, 0x68, 0x5, 0x68, 0x588, 0xa, 0x68, 0x5, 0x68, 
    0x58a, 0xa, 0x68, 0x3, 0x69, 0x3, 0x69, 0x3, 0x69, 0x3, 0x69, 0x5, 0x69, 
    0x590, 0xa, 0x69, 0x3, 0x6a, 0x3, 0x6a, 0x5, 0x6a, 0x594, 0xa, 0x6a, 
    0x3, 0x6a, 0x3, 0x6a, 0x3, 0x6a, 0x2, 0x3, 0xa8, 0x6b, 0x2, 0x4, 0x6, 
    0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 
    0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 
    0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 
    0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 
    0x68, 0x6a, 0x6c, 0x6e, 0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e, 
    0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c, 0x8e, 0x90, 0x92, 0x94, 0x96, 
    0x98, 0x9a, 0x9c, 0x9e, 0xa0, 0xa2, 0xa4, 0xa6, 0xa8, 0xaa, 0xac, 0xae, 
    0xb0, 0xb2, 0xb4, 0xb6, 0xb8, 0xba, 0xbc, 0xbe, 0xc0, 0xc2, 0xc4, 0xc6, 
    0xc8, 0xca, 0xcc, 0xce, 0xd0, 0xd2, 0x2, 0xe, 0x4, 0x2, 0x13, 0x13, 
    0x2a, 0x2a, 0x3, 0x2, 0x35, 0x38, 0x3, 0x2, 0x39, 0x3a, 0x3, 0x2, 0x55, 
    0x58, 0x3, 0x2, 0x4b, 0x4c, 0x4, 0x2, 0x59, 0x5a, 0x5e, 0x5e, 0x3, 0x2, 
    0x57, 0x58, 0x4, 0x2, 0x49, 0x4a, 0x50, 0x51, 0x4, 0x2, 0x4f, 0x4f, 
    0x52, 0x52, 0x4, 0x2, 0x48, 0x48, 0x5f, 0x69, 0x3, 0x2, 0x55, 0x56, 
    0xa, 0x2, 0x5, 0x5, 0x7, 0x7, 0xa, 0xa, 0x10, 0x10, 0x16, 0x16, 0x1d, 
    0x1d, 0x1f, 0x1f, 0x27, 0x27, 0x2, 0x637, 0x2, 0xd5, 0x3, 0x2, 0x2, 
    0x2, 0x4, 0xe8, 0x3, 0x2, 0x2, 0x2, 0x6, 0xef, 0x3, 0x2, 0x2, 0x2, 0x8, 
    0x107, 0x3, 0x2, 0x2, 0x2, 0xa, 0x10e, 0x3, 0x2, 0x2, 0x2, 0xc, 0x118, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x10, 0x11e, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x14, 0x13b, 0x3, 0x2, 
    0x2, 0x2, 0x16, 0x149, 0x3, 0x2, 0x2, 0x2, 0x18, 0x151, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0x163, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x16e, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0x178, 0x3, 0x2, 0x2, 0x2, 0x20, 0x17f, 0x3, 0x2, 0x2, 0x2, 0x22, 
    0x18a, 0x3, 0x2, 0x2, 0x2, 0x24, 0x193, 0x3, 0x2, 0x2, 0x2, 0x26, 0x1a8, 
    0x3, 0x2, 0x2, 0x2, 0x28, 0x1b3, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x1b5, 0x3, 
    0x2, 0x2, 0x2, 0x2c, 0x1c7, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x1cb, 0x3, 0x2, 
    0x2, 0x2, 0x30, 0x1cd, 0x3, 0x2, 0x2, 0x2, 0x32, 0x1d0, 0x3, 0x2, 0x2, 
    0x2, 0x34, 0x1d3, 0x3, 0x2, 0x2, 0x2, 0x36, 0x1db, 0x3, 0x2, 0x2, 0x2, 
    0x38, 0x1e7, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x1f0, 0x3, 0x2, 0x2, 0x2, 0x3c, 
    0x1f2, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x1fd, 0x3, 0x2, 0x2, 0x2, 0x40, 0x20b, 
    0x3, 0x2, 0x2, 0x2, 0x42, 0x22f, 0x3, 0x2, 0x2, 0x2, 0x44, 0x231, 0x3, 
    0x2, 0x2, 0x2, 0x46, 0x234, 0x3, 0x2, 0x2, 0x2, 0x48, 0x23c, 0x3, 0x2, 
    0x2, 0x2, 0x4a, 0x241, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x24b, 0x3, 0x2, 0x2, 
    0x2, 0x4e, 0x24d, 0x3, 0x2, 0x2, 0x2, 0x50, 0x25d, 0x3, 0x2, 0x2, 0x2, 
    0x52, 0x277, 0x3, 0x2, 0x2, 0x2, 0x54, 0x279, 0x3, 0x2, 0x2, 0x2, 0x56, 
    0x281, 0x3, 0x2, 0x2, 0x2, 0x58, 0x294, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x299, 
    0x3, 0x2, 0x2, 0x2, 0x5c, 0x2a2, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x2af, 0x3, 
    0x2, 0x2, 0x2, 0x60, 0x2bd, 0x3, 0x2, 0x2, 0x2, 0x62, 0x2bf, 0x3, 0x2, 
    0x2, 0x2, 0x64, 0x2c1, 0x3, 0x2, 0x2, 0x2, 0x66, 0x2c7, 0x3, 0x2, 0x2, 
    0x2, 0x68, 0x2d0, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x2da, 0x3, 0x2, 0x2, 0x2, 
    0x6c, 0x2e2, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x2e9, 0x3, 0x2, 0x2, 0x2, 0x70, 
    0x2eb, 0x3, 0x2, 0x2, 0x2, 0x72, 0x2fb, 0x3, 0x2, 0x2, 0x2, 0x74, 0x300, 
    0x3, 0x2, 0x2, 0x2, 0x76, 0x311, 0x3, 0x2, 0x2, 0x2, 0x78, 0x327, 0x3, 
    0x2, 0x2, 0x2, 0x7a, 0x32b, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x32d, 0x3, 0x2, 
    0x2, 0x2, 0x7e, 0x333, 0x3, 0x2, 0x2, 0x2, 0x80, 0x335, 0x3, 0x2, 0x2, 
    0x2, 0x82, 0x338, 0x3, 0x2, 0x2, 0x2, 0x84, 0x346, 0x3, 0x2, 0x2, 0x2, 
    0x86, 0x34b, 0x3, 0x2, 0x2, 0x2, 0x88, 0x35c, 0x3, 0x2, 0x2, 0x2, 0x8a, 
    0x3c6, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x3c8, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x3d5, 
    0x3, 0x2, 0x2, 0x2, 0x90, 0x3dd, 0x3, 0x2, 0x2, 0x2, 0x92, 0x3e0, 0x3, 
    0x2, 0x2, 0x2, 0x94, 0x3e7, 0x3, 0x2, 0x2, 0x2, 0x96, 0x3f2, 0x3, 0x2, 
    0x2, 0x2, 0x98, 0x3fb, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x40c, 0x3, 0x2, 0x2, 
    0x2, 0x9c, 0x41a, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x41e, 0x3, 0x2, 0x2, 0x2, 
    0xa0, 0x423, 0x3, 0x2, 0x2, 0x2, 0xa2, 0x42b, 0x3, 0x2, 0x2, 0x2, 0xa4, 
    0x42f, 0x3, 0x2, 0x2, 0x2, 0xa6, 0x449, 0x3, 0x2, 0x2, 0x2, 0xa8, 0x470, 
    0x3, 0x2, 0x2, 0x2, 0xaa, 0x4c5, 0x3, 0x2, 0x2, 0x2, 0xac, 0x4d9, 0x3, 
    0x2, 0x2, 0x2, 0xae, 0x4dd, 0x3, 0x2, 0x2, 0x2, 0xb0, 0x4f1, 0x3, 0x2, 
    0x2, 0x2, 0xb2, 0x4f6, 0x3, 0x2, 0x2, 0x2, 0xb4, 0x50b, 0x3, 0x2, 0x2, 
    0x2, 0xb6, 0x51c, 0x3, 0x2, 0x2, 0x2, 0xb8, 0x51e, 0x3, 0x2, 0x2, 0x2, 
    0xba, 0x524, 0x3, 0x2, 0x2, 0x2, 0xbc, 0x542, 0x3, 0x2, 0x2, 0x2, 0xbe, 
    0x546, 0x3, 0x2, 0x2, 0x2, 0xc0, 0x54c, 0x3, 0x2, 0x2, 0x2, 0xc2, 0x551, 
    0x3, 0x2, 0x2, 0x2, 0xc4, 0x553, 0x3, 0x2, 0x2, 0x2, 0xc6, 0x557, 0x3, 
    0x2, 0x2, 0x2, 0xc8, 0x562, 0x3, 0x2, 0x2, 0x2, 0xca, 0x576, 0x3, 0x2, 
    0x2, 0x2, 0xcc, 0x578, 0x3, 0x2, 0x2, 0x2, 0xce, 0x589, 0x3, 0x2, 0x2, 
    0x2, 0xd0, 0x58f, 0x3, 0x2, 0x2, 0x2, 0xd2, 0x591, 0x3, 0x2, 0x2, 0x2, 
    0xd4, 0xd6, 0x5, 0x4, 0x3, 0x2, 0xd5, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd5, 
    0xd6, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xda, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd9, 
    0x5, 0x6, 0x4, 0x2, 0xd8, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xdc, 0x3, 
    0x2, 0x2, 0x2, 0xda, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xda, 0xdb, 0x3, 0x2, 
    0x2, 0x2, 0xdb, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xda, 0x3, 0x2, 0x2, 
    0x2, 0xdd, 0xdf, 0x5, 0x8, 0x5, 0x2, 0xde, 0xdd, 0x3, 0x2, 0x2, 0x2, 
    0xdf, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xde, 0x3, 0x2, 0x2, 0x2, 0xe0, 
    0xe1, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe0, 
    0x3, 0x2, 0x2, 0x2, 0xe3, 0xe4, 0x7, 0x2, 0x2, 0x3, 0xe4, 0x3, 0x3, 
    0x2, 0x2, 0x2, 0xe5, 0xe7, 0x5, 0x68, 0x35, 0x2, 0xe6, 0xe5, 0x3, 0x2, 
    0x2, 0x2, 0xe7, 0xea, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe6, 0x3, 0x2, 0x2, 
    0x2, 0xe8, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xeb, 0x3, 0x2, 0x2, 0x2, 
    0xea, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xec, 0x7, 0x22, 0x2, 0x2, 0xec, 
    0xed, 0x5, 0x5e, 0x30, 0x2, 0xed, 0xee, 0x7, 0x45, 0x2, 0x2, 0xee, 0x5, 
    0x3, 0x2, 0x2, 0x2, 0xef, 0xf1, 0x7, 0x1b, 0x2, 0x2, 0xf0, 0xf2, 0x7, 
    0x28, 0x2, 0x2, 0xf1, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf2, 0x3, 0x2, 
    0x2, 0x2, 0xf2, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf6, 0x5, 0x5e, 0x30, 
    0x2, 0xf4, 0xf5, 0x7, 0x47, 0x2, 0x2, 0xf5, 0xf7, 0x7, 0x59, 0x2, 0x2, 
    0xf6, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xf7, 
    0xf8, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf9, 0x7, 0x45, 0x2, 0x2, 0xf9, 0x7, 
    0x3, 0x2, 0x2, 0x2, 0xfa, 0xfc, 0x5, 0xc, 0x7, 0x2, 0xfb, 0xfa, 0x3, 
    0x2, 0x2, 0x2, 0xfc, 0xff, 0x3, 0x2, 0x2, 0x2, 0xfd, 0xfb, 0x3, 0x2, 
    0x2, 0x2, 0xfd, 0xfe, 0x3, 0x2, 0x2, 0x2, 0xfe, 0x104, 0x3, 0x2, 0x2, 
    0x2, 0xff, 0xfd, 0x3, 0x2, 0x2, 0x2, 0x100, 0x105, 0x5, 0x10, 0x9, 0x2, 
    0x101, 0x105, 0x5, 0x18, 0xd, 0x2, 0x102, 0x105, 0x5, 0x20, 0x11, 0x2, 
    0x103, 0x105, 0x5, 0x72, 0x3a, 0x2, 0x104, 0x100, 0x3, 0x2, 0x2, 0x2, 
    0x104, 0x101, 0x3, 0x2, 0x2, 0x2, 0x104, 0x102, 0x3, 0x2, 0x2, 0x2, 
    0x104, 0x103, 0x3, 0x2, 0x2, 0x2, 0x105, 0x108, 0x3, 0x2, 0x2, 0x2, 
    0x106, 0x108, 0x7, 0x45, 0x2, 0x2, 0x107, 0xfd, 0x3, 0x2, 0x2, 0x2, 
    0x107, 0x106, 0x3, 0x2, 0x2, 0x2, 0x108, 0x9, 0x3, 0x2, 0x2, 0x2, 0x109, 
    0x10f, 0x5, 0xc, 0x7, 0x2, 0x10a, 0x10f, 0x7, 0x20, 0x2, 0x2, 0x10b, 
    0x10f, 0x7, 0x2c, 0x2, 0x2, 0x10c, 0x10f, 0x7, 0x30, 0x2, 0x2, 0x10d, 
    0x10f, 0x7, 0x33, 0x2, 0x2, 0x10e, 0x109, 0x3, 0x2, 0x2, 0x2, 0x10e, 
    0x10a, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x10e, 
    0x10c, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x10f, 
    0xb, 0x3, 0x2, 0x2, 0x2, 0x110, 0x119, 0x5, 0x68, 0x35, 0x2, 0x111, 
    0x119, 0x7, 0x25, 0x2, 0x2, 0x112, 0x119, 0x7, 0x24, 0x2, 0x2, 0x113, 
    0x119, 0x7, 0x23, 0x2, 0x2, 0x114, 0x119, 0x7, 0x28, 0x2, 0x2, 0x115, 
    0x119, 0x7, 0x3, 0x2, 0x2, 0x116, 0x119, 0x7, 0x14, 0x2, 0x2, 0x117, 
    0x119, 0x7, 0x29, 0x2, 0x2, 0x118, 0x110, 0x3, 0x2, 0x2, 0x2, 0x118, 
    0x111, 0x3, 0x2, 0x2, 0x2, 0x118, 0x112, 0x3, 0x2, 0x2, 0x2, 0x118, 
    0x113, 0x3, 0x2, 0x2, 0x2, 0x118, 0x114, 0x3, 0x2, 0x2, 0x2, 0x118, 
    0x115, 0x3, 0x2, 0x2, 0x2, 0x118, 0x116, 0x3, 0x2, 0x2, 0x2, 0x118, 
    0x117, 0x3, 0x2, 0x2, 0x2, 0x119, 0xd, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x11d, 
    0x7, 0x14, 0x2, 0x2, 0x11b, 0x11d, 0x5, 0x68, 0x35, 0x2, 0x11c, 0x11a, 
    0x3, 0x2, 0x2, 0x2, 0x11c, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x11d, 0xf, 0x3, 
    0x2, 0x2, 0x2, 0x11e, 0x11f, 0x7, 0xb, 0x2, 0x2, 0x11f, 0x121, 0x7, 
    0x71, 0x2, 0x2, 0x120, 0x122, 0x5, 0x12, 0xa, 0x2, 0x121, 0x120, 0x3, 
    0x2, 0x2, 0x2, 0x121, 0x122, 0x3, 0x2, 0x2, 0x2, 0x122, 0x125, 0x3, 
    0x2, 0x2, 0x2, 0x123, 0x124, 0x7, 0x13, 0x2, 0x2, 0x124, 0x126, 0x5, 
    0xc8, 0x65, 0x2, 0x125, 0x123, 0x3, 0x2, 0x2, 0x2, 0x125, 0x126, 0x3, 
    0x2, 0x2, 0x2, 0x126, 0x129, 0x3, 0x2, 0x2, 0x2, 0x127, 0x128, 0x7, 
    0x1a, 0x2, 0x2, 0x128, 0x12a, 0x5, 0xc6, 0x64, 0x2, 0x129, 0x127, 0x3, 
    0x2, 0x2, 0x2, 0x129, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x12b, 0x3, 
    0x2, 0x2, 0x2, 0x12b, 0x12c, 0x5, 0x22, 0x12, 0x2, 0x12c, 0x11, 0x3, 
    0x2, 0x2, 0x2, 0x12d, 0x12e, 0x7, 0x4a, 0x2, 0x2, 0x12e, 0x133, 0x5, 
    0x14, 0xb, 0x2, 0x12f, 0x130, 0x7, 0x46, 0x2, 0x2, 0x130, 0x132, 0x5, 
    0x14, 0xb, 0x2, 0x131, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x132, 0x135, 0x3, 
    0x2, 0x2, 0x2, 0x133, 0x131, 0x3, 0x2, 0x2, 0x2, 0x133, 0x134, 0x3, 
    0x2, 0x2, 0x2, 0x134, 0x136, 0x3, 0x2, 0x2, 0x2, 0x135, 0x133, 0x3, 
    0x2, 0x2, 0x2, 0x136, 0x137, 0x7, 0x49, 0x2, 0x2, 0x137, 0x13, 0x3, 
    0x2, 0x2, 0x2, 0x138, 0x13a, 0x5, 0x68, 0x35, 0x2, 0x139, 0x138, 0x3, 
    0x2, 0x2, 0x2, 0x13a, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x139, 0x3, 
    0x2, 0x2, 0x2, 0x13b, 0x13c, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x13e, 0x3, 
    0x2, 0x2, 0x2, 0x13d, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x147, 0x7, 
    0x71, 0x2, 0x2, 0x13f, 0x143, 0x7, 0x13, 0x2, 0x2, 0x140, 0x142, 0x5, 
    0x68, 0x35, 0x2, 0x141, 0x140, 0x3, 0x2, 0x2, 0x2, 0x142, 0x145, 0x3, 
    0x2, 0x2, 0x2, 0x143, 0x141, 0x3, 0x2, 0x2, 0x2, 0x143, 0x144, 0x3, 
    0x2, 0x2, 0x2, 0x144, 0x146, 0x3, 0x2, 0x2, 0x2, 0x145, 0x143, 0x3, 
    0x2, 0x2, 0x2, 0x146, 0x148, 0x5, 0x16, 0xc, 0x2, 0x147, 0x13f, 0x3, 
    0x2, 0x2, 0x2, 0x147, 0x148, 0x3, 0x2, 0x2, 0x2, 0x148, 0x15, 0x3, 0x2, 
    0x2, 0x2, 0x149, 0x14e, 0x5, 0xc8, 0x65, 0x2, 0x14a, 0x14b, 0x7, 0x5b, 
    0x2, 0x2, 0x14b, 0x14d, 0x5, 0xc8, 0x65, 0x2, 0x14c, 0x14a, 0x3, 0x2, 
    0x2, 0x2, 0x14d, 0x150, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x14c, 0x3, 0x2, 
    0x2, 0x2, 0x14e, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x17, 0x3, 0x2, 0x2, 
    0x2, 0x150, 0x14e, 0x3, 0x2, 0x2, 0x2, 0x151, 0x152, 0x7, 0x12, 0x2, 
    0x2, 0x152, 0x155, 0x7, 0x71, 0x2, 0x2, 0x153, 0x154, 0x7, 0x1a, 0x2, 
    0x2, 0x154, 0x156, 0x5, 0xc6, 0x64, 0x2, 0x155, 0x153, 0x3, 0x2, 0x2, 
    0x2, 0x155, 0x156, 0x3, 0x2, 0x2, 0x2, 0x156, 0x157, 0x3, 0x2, 0x2, 
    0x2, 0x157, 0x159, 0x7, 0x41, 0x2, 0x2, 0x158, 0x15a, 0x5, 0x1a, 0xe, 
    0x2, 0x159, 0x158, 0x3, 0x2, 0x2, 0x2, 0x159, 0x15a, 0x3, 0x2, 0x2, 
    0x2, 0x15a, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x15d, 0x7, 0x46, 0x2, 
    0x2, 0x15c, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x15d, 0x3, 0x2, 0x2, 
    0x2, 0x15d, 0x15f, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x160, 0x5, 0x1e, 0x10, 
    0x2, 0x15f, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x15f, 0x160, 0x3, 0x2, 0x2, 
    0x2, 0x160, 0x161, 0x3, 0x2, 0x2, 0x2, 0x161, 0x162, 0x7, 0x42, 0x2, 
    0x2, 0x162, 0x19, 0x3, 0x2, 0x2, 0x2, 0x163, 0x168, 0x5, 0x1c, 0xf, 
    0x2, 0x164, 0x165, 0x7, 0x46, 0x2, 0x2, 0x165, 0x167, 0x5, 0x1c, 0xf, 
    0x2, 0x166, 0x164, 0x3, 0x2, 0x2, 0x2, 0x167, 0x16a, 0x3, 0x2, 0x2, 
    0x2, 0x168, 0x166, 0x3, 0x2, 0x2, 0x2, 0x168, 0x169, 0x3, 0x2, 0x2, 
    0x2, 0x169, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x16a, 0x168, 0x3, 0x2, 0x2, 0x2, 
    0x16b, 0x16d, 0x5, 0x68, 0x35, 0x2, 0x16c, 0x16b, 0x3, 0x2, 0x2, 0x2, 
    0x16d, 0x170, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x16c, 0x3, 0x2, 0x2, 0x2, 
    0x16e, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x171, 0x3, 0x2, 0x2, 0x2, 
    0x170, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x171, 0x173, 0x7, 0x71, 0x2, 0x2, 
    0x172, 0x174, 0x5, 0xd2, 0x6a, 0x2, 0x173, 0x172, 0x3, 0x2, 0x2, 0x2, 
    0x173, 0x174, 0x3, 0x2, 0x2, 0x2, 0x174, 0x176, 0x3, 0x2, 0x2, 0x2, 
    0x175, 0x177, 0x5, 0x22, 0x12, 0x2, 0x176, 0x175, 0x3, 0x2, 0x2, 0x2, 
    0x176, 0x177, 0x3, 0x2, 0x2, 0x2, 0x177, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x178, 
    0x17c, 0x7, 0x45, 0x2, 0x2, 0x179, 0x17b, 0x5, 0x26, 0x14, 0x2, 0x17a, 
    0x179, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x17c, 
    0x17a, 0x3, 0x2, 0x2, 0x2, 0x17c, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x17d, 
    0x1f, 0x3, 0x2, 0x2, 0x2, 0x17e, 0x17c, 0x3, 0x2, 0x2, 0x2, 0x17f, 0x180, 
    0x7, 0x1e, 0x2, 0x2, 0x180, 0x182, 0x7, 0x71, 0x2, 0x2, 0x181, 0x183, 
    0x5, 0x12, 0xa, 0x2, 0x182, 0x181, 0x3, 0x2, 0x2, 0x2, 0x182, 0x183, 
    0x3, 0x2, 0x2, 0x2, 0x183, 0x186, 0x3, 0x2, 0x2, 0x2, 0x184, 0x185, 
    0x7, 0x13, 0x2, 0x2, 0x185, 0x187, 0x5, 0xc6, 0x64, 0x2, 0x186, 0x184, 
    0x3, 0x2, 0x2, 0x2, 0x186, 0x187, 0x3, 0x2, 0x2, 0x2, 0x187, 0x188, 
    0x3, 0x2, 0x2, 0x2, 0x188, 0x189, 0x5, 0x24, 0x13, 0x2, 0x189, 0x21, 
    0x3, 0x2, 0x2, 0x2, 0x18a, 0x18e, 0x7, 0x41, 0x2, 0x2, 0x18b, 0x18d, 
    0x5, 0x26, 0x14, 0x2, 0x18c, 0x18b, 0x3, 0x2, 0x2, 0x2, 0x18d, 0x190, 
    0x3, 0x2, 0x2, 0x2, 0x18e, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x18e, 0x18f, 
    0x3, 0x2, 0x2, 0x2, 0x18f, 0x191, 0x3, 0x2, 0x2, 0x2, 0x190, 0x18e, 
    0x3, 0x2, 0x2, 0x2, 0x191, 0x192, 0x7, 0x42, 0x2, 0x2, 0x192, 0x23, 
    0x3, 0x2, 0x2, 0x2, 0x193, 0x197, 0x7, 0x41, 0x2, 0x2, 0x194, 0x196, 
    0x5, 0x38, 0x1d, 0x2, 0x195, 0x194, 0x3, 0x2, 0x2, 0x2, 0x196, 0x199, 
    0x3, 0x2, 0x2, 0x2, 0x197, 0x195, 0x3, 0x2, 0x2, 0x2, 0x197, 0x198, 
    0x3, 0x2, 0x2, 0x2, 0x198, 0x19a, 0x3, 0x2, 0x2, 0x2, 0x199, 0x197, 
    0x3, 0x2, 0x2, 0x2, 0x19a, 0x19b, 0x7, 0x42, 0x2, 0x2, 0x19b, 0x25, 
    0x3, 0x2, 0x2, 0x2, 0x19c, 0x1a9, 0x7, 0x45, 0x2, 0x2, 0x19d, 0x19f, 
    0x7, 0x28, 0x2, 0x2, 0x19e, 0x19d, 0x3, 0x2, 0x2, 0x2, 0x19e, 0x19f, 
    0x3, 0x2, 0x2, 0x2, 0x19f, 0x1a0, 0x3, 0x2, 0x2, 0x2, 0x1a0, 0x1a9, 
    0x5, 0x82, 0x42, 0x2, 0x1a1, 0x1a3, 0x5, 0xa, 0x6, 0x2, 0x1a2, 0x1a1, 
    0x3, 0x2, 0x2, 0x2, 0x1a3, 0x1a6, 0x3, 0x2, 0x2, 0x2, 0x1a4, 0x1a2, 
    0x3, 0x2, 0x2, 0x2, 0x1a4, 0x1a5, 0x3, 0x2, 0x2, 0x2, 0x1a5, 0x1a7, 
    0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a4, 0x3, 0x2, 0x2, 0x2, 0x1a7, 0x1a9, 
    0x5, 0x28, 0x15, 0x2, 0x1a8, 0x19c, 0x3, 0x2, 0x2, 0x2, 0x1a8, 0x19e, 
    0x3, 0x2, 0x2, 0x2, 0x1a8, 0x1a4, 0x3, 0x2, 0x2, 0x2, 0x1a9, 0x27, 0x3, 
    0x2, 0x2, 0x2, 0x1aa, 0x1b4, 0x5, 0x2a, 0x16, 0x2, 0x1ab, 0x1b4, 0x5, 
    0x30, 0x19, 0x2, 0x1ac, 0x1b4, 0x5, 0x36, 0x1c, 0x2, 0x1ad, 0x1b4, 0x5, 
    0x34, 0x1b, 0x2, 0x1ae, 0x1b4, 0x5, 0x32, 0x1a, 0x2, 0x1af, 0x1b4, 0x5, 
    0x20, 0x11, 0x2, 0x1b0, 0x1b4, 0x5, 0x72, 0x3a, 0x2, 0x1b1, 0x1b4, 0x5, 
    0x10, 0x9, 0x2, 0x1b2, 0x1b4, 0x5, 0x18, 0xd, 0x2, 0x1b3, 0x1aa, 0x3, 
    0x2, 0x2, 0x2, 0x1b3, 0x1ab, 0x3, 0x2, 0x2, 0x2, 0x1b3, 0x1ac, 0x3, 
    0x2, 0x2, 0x2, 0x1b3, 0x1ad, 0x3, 0x2, 0x2, 0x2, 0x1b3, 0x1ae, 0x3, 
    0x2, 0x2, 0x2, 0x1b3, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x1b3, 0x1b0, 0x3, 
    0x2, 0x2, 0x2, 0x1b3, 0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1b3, 0x1b2, 0x3, 
    0x2, 0x2, 0x2, 0x1b4, 0x29, 0x3, 0x2, 0x2, 0x2, 0x1b5, 0x1b6, 0x5, 0x2e, 
    0x18, 0x2, 0x1b6, 0x1b7, 0x7, 0x71, 0x2, 0x2, 0x1b7, 0x1bc, 0x5, 0x56, 
    0x2c, 0x2, 0x1b8, 0x1b9, 0x7, 0x43, 0x2, 0x2, 0x1b9, 0x1bb, 0x7, 0x44, 
    0x2, 0x2, 0x1ba, 0x1b8, 0x3, 0x2, 0x2, 0x2, 0x1bb, 0x1be, 0x3, 0x2, 
    0x2, 0x2, 0x1bc, 0x1ba, 0x3, 0x2, 0x2, 0x2, 0x1bc, 0x1bd, 0x3, 0x2, 
    0x2, 0x2, 0x1bd, 0x1c1, 0x3, 0x2, 0x2, 0x2, 0x1be, 0x1bc, 0x3, 0x2, 
    0x2, 0x2, 0x1bf, 0x1c0, 0x7, 0x2f, 0x2, 0x2, 0x1c0, 0x1c2, 0x5, 0x54, 
    0x2b, 0x2, 0x1c1, 0x1bf, 0x3, 0x2, 0x2, 0x2, 0x1c1, 0x1c2, 0x3, 0x2, 
    0x2, 0x2, 0x1c2, 0x1c3, 0x3, 0x2, 0x2, 0x2, 0x1c3, 0x1c4, 0x5, 0x2c, 
    0x17, 0x2, 0x1c4, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x1c5, 0x1c8, 0x5, 0x82, 
    0x42, 0x2, 0x1c6, 0x1c8, 0x7, 0x45, 0x2, 0x2, 0x1c7, 0x1c5, 0x3, 0x2, 
    0x2, 0x2, 0x1c7, 0x1c6, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x2d, 0x3, 0x2, 0x2, 
    0x2, 0x1c9, 0x1cc, 0x5, 0xc8, 0x65, 0x2, 0x1ca, 0x1cc, 0x7, 0x32, 0x2, 
    0x2, 0x1cb, 0x1c9, 0x3, 0x2, 0x2, 0x2, 0x1cb, 0x1ca, 0x3, 0x2, 0x2, 
    0x2, 0x1cc, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x1cd, 0x1ce, 0x5, 0x12, 0xa, 
    0x2, 0x1ce, 0x1cf, 0x5, 0x2a, 0x16, 0x2, 0x1cf, 0x31, 0x3, 0x2, 0x2, 
    0x2, 0x1d0, 0x1d1, 0x5, 0x12, 0xa, 0x2, 0x1d1, 0x1d2, 0x5, 0x34, 0x1b, 
    0x2, 0x1d2, 0x33, 0x3, 0x2, 0x2, 0x2, 0x1d3, 0x1d4, 0x7, 0x71, 0x2, 
    0x2, 0x1d4, 0x1d7, 0x5, 0x56, 0x2c, 0x2, 0x1d5, 0x1d6, 0x7, 0x2f, 0x2, 
    0x2, 0x1d6, 0x1d8, 0x5, 0x54, 0x2b, 0x2, 0x1d7, 0x1d5, 0x3, 0x2, 0x2, 
    0x2, 0x1d7, 0x1d8, 0x3, 0x2, 0x2, 0x2, 0x1d8, 0x1d9, 0x3, 0x2, 0x2, 
    0x2, 0x1d9, 0x1da, 0x5, 0x82, 0x42, 0x2, 0x1da, 0x35, 0x3, 0x2, 0x2, 
    0x2, 0x1db, 0x1dc, 0x5, 0xc8, 0x65, 0x2, 0x1dc, 0x1dd, 0x5, 0x46, 0x24, 
    0x2, 0x1dd, 0x1de, 0x7, 0x45, 0x2, 0x2, 0x1de, 0x37, 0x3, 0x2, 0x2, 
    0x2, 0x1df, 0x1e1, 0x5, 0xa, 0x6, 0x2, 0x1e0, 0x1df, 0x3, 0x2, 0x2, 
    0x2, 0x1e1, 0x1e4, 0x3, 0x2, 0x2, 0x2, 0x1e2, 0x1e0, 0x3, 0x2, 0x2, 
    0x2, 0x1e2, 0x1e3, 0x3, 0x2, 0x2, 0x2, 0x1e3, 0x1e5, 0x3, 0x2, 0x2, 
    0x2, 0x1e4, 0x1e2, 0x3, 0x2, 0x2, 0x2, 0x1e5, 0x1e8, 0x5, 0x3a, 0x1e, 
    0x2, 0x1e6, 0x1e8, 0x7, 0x45, 0x2, 0x2, 0x1e7, 0x1e2, 0x3, 0x2, 0x2, 
    0x2, 0x1e7, 0x1e6, 0x3, 0x2, 0x2, 0x2, 0x1e8, 0x39, 0x3, 0x2, 0x2, 0x2, 
    0x1e9, 0x1f1, 0x5, 0x3c, 0x1f, 0x2, 0x1ea, 0x1f1, 0x5, 0x40, 0x21, 0x2, 
    0x1eb, 0x1f1, 0x5, 0x44, 0x23, 0x2, 0x1ec, 0x1f1, 0x5, 0x20, 0x11, 0x2, 
    0x1ed, 0x1f1, 0x5, 0x72, 0x3a, 0x2, 0x1ee, 0x1f1, 0x5, 0x10, 0x9, 0x2, 
    0x1ef, 0x1f1, 0x5, 0x18, 0xd, 0x2, 0x1f0, 0x1e9, 0x3, 0x2, 0x2, 0x2, 
    0x1f0, 0x1ea, 0x3, 0x2, 0x2, 0x2, 0x1f0, 0x1eb, 0x3, 0x2, 0x2, 0x2, 
    0x1f0, 0x1ec, 0x3, 0x2, 0x2, 0x2, 0x1f0, 0x1ed, 0x3, 0x2, 0x2, 0x2, 
    0x1f0, 0x1ee, 0x3, 0x2, 0x2, 0x2, 0x1f0, 0x1ef, 0x3, 0x2, 0x2, 0x2, 
    0x1f1, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x1f2, 0x1f3, 0x5, 0xc8, 0x65, 0x2, 
    0x1f3, 0x1f8, 0x5, 0x3e, 0x20, 0x2, 0x1f4, 0x1f5, 0x7, 0x46, 0x2, 0x2, 
    0x1f5, 0x1f7, 0x5, 0x3e, 0x20, 0x2, 0x1f6, 0x1f4, 0x3, 0x2, 0x2, 0x2, 
    0x1f7, 0x1fa, 0x3, 0x2, 0x2, 0x2, 0x1f8, 0x1f6, 0x3, 0x2, 0x2, 0x2, 
    0x1f8, 0x1f9, 0x3, 0x2, 0x2, 0x2, 0x1f9, 0x1fb, 0x3, 0x2, 0x2, 0x2, 
    0x1fa, 0x1f8, 0x3, 0x2, 0x2, 0x2, 0x1fb, 0x1fc, 0x7, 0x45, 0x2, 0x2, 
    0x1fc, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x1fd, 0x202, 0x7, 0x71, 0x2, 0x2, 
    0x1fe, 0x1ff, 0x7, 0x43, 0x2, 0x2, 0x1ff, 0x201, 0x7, 0x44, 0x2, 0x2, 
    0x200, 0x1fe, 0x3, 0x2, 0x2, 0x2, 0x201, 0x204, 0x3, 0x2, 0x2, 0x2, 
    0x202, 0x200, 0x3, 0x2, 0x2, 0x2, 0x202, 0x203, 0x3, 0x2, 0x2, 0x2, 
    0x203, 0x205, 0x3, 0x2, 0x2, 0x2, 0x204, 0x202, 0x3, 0x2, 0x2, 0x2, 
    0x205, 0x206, 0x7, 0x48, 0x2, 0x2, 0x206, 0x207, 0x5, 0x4c, 0x27, 0x2, 
    0x207, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x208, 0x20a, 0x5, 0x42, 0x22, 0x2, 
    0x209, 0x208, 0x3, 0x2, 0x2, 0x2, 0x20a, 0x20d, 0x3, 0x2, 0x2, 0x2, 
    0x20b, 0x209, 0x3, 0x2, 0x2, 0x2, 0x20b, 0x20c, 0x3, 0x2, 0x2, 0x2, 
    0x20c, 0x218, 0x3, 0x2, 0x2, 0x2, 0x20d, 0x20b, 0x3, 0x2, 0x2, 0x2, 
    0x20e, 0x219, 0x5, 0x2e, 0x18, 0x2, 0x20f, 0x213, 0x5, 0x12, 0xa, 0x2, 
    0x210, 0x212, 0x5, 0x68, 0x35, 0x2, 0x211, 0x210, 0x3, 0x2, 0x2, 0x2, 
    0x212, 0x215, 0x3, 0x2, 0x2, 0x2, 0x213, 0x211, 0x3, 0x2, 0x2, 0x2, 
    0x213, 0x214, 0x3, 0x2, 0x2, 0x2, 0x214, 0x216, 0x3, 0x2, 0x2, 0x2, 
    0x215, 0x213, 0x3, 0x2, 0x2, 0x2, 0x216, 0x217, 0x5, 0x2e, 0x18, 0x2, 
    0x217, 0x219, 0x3, 0x2, 0x2, 0x2, 0x218, 0x20e, 0x3, 0x2, 0x2, 0x2, 
    0x218, 0x20f, 0x3, 0x2, 0x2, 0x2, 0x219, 0x21a, 0x3, 0x2, 0x2, 0x2, 
    0x21a, 0x21b, 0x7, 0x71, 0x2, 0x2, 0x21b, 0x220, 0x5, 0x56, 0x2c, 0x2, 
    0x21c, 0x21d, 0x7, 0x43, 0x2, 0x2, 0x21d, 0x21f, 0x7, 0x44, 0x2, 0x2, 
    0x21e, 0x21c, 0x3, 0x2, 0x2, 0x2, 0x21f, 0x222, 0x3, 0x2, 0x2, 0x2, 
    0x220, 0x21e, 0x3, 0x2, 0x2, 0x2, 0x220, 0x221, 0x3, 0x2, 0x2, 0x2, 
    0x221, 0x225, 0x3, 0x2, 0x2, 0x2, 0x222, 0x220, 0x3, 0x2, 0x2, 0x2, 
    0x223, 0x224, 0x7, 0x2f, 0x2, 0x2, 0x224, 0x226, 0x5, 0x54, 0x2b, 0x2, 
    0x225, 0x223, 0x3, 0x2, 0x2, 0x2, 0x225, 0x226, 0x3, 0x2, 0x2, 0x2, 
    0x226, 0x227, 0x3, 0x2, 0x2, 0x2, 0x227, 0x228, 0x5, 0x2c, 0x17, 0x2, 
    0x228, 0x41, 0x3, 0x2, 0x2, 0x2, 0x229, 0x230, 0x5, 0x68, 0x35, 0x2, 
    0x22a, 0x230, 0x7, 0x25, 0x2, 0x2, 0x22b, 0x230, 0x7, 0x3, 0x2, 0x2, 
    0x22c, 0x230, 0x7, 0xe, 0x2, 0x2, 0x22d, 0x230, 0x7, 0x28, 0x2, 0x2, 
    0x22e, 0x230, 0x7, 0x29, 0x2, 0x2, 0x22f, 0x229, 0x3, 0x2, 0x2, 0x2, 
    0x22f, 0x22a, 0x3, 0x2, 0x2, 0x2, 0x22f, 0x22b, 0x3, 0x2, 0x2, 0x2, 
    0x22f, 0x22c, 0x3, 0x2, 0x2, 0x2, 0x22f, 0x22d, 0x3, 0x2, 0x2, 0x2, 
    0x22f, 0x22e, 0x3, 0x2, 0x2, 0x2, 0x230, 0x43, 0x3, 0x2, 0x2, 0x2, 0x231, 
    0x232, 0x5, 0x12, 0xa, 0x2, 0x232, 0x233, 0x5, 0x40, 0x21, 0x2, 0x233, 
    0x45, 0x3, 0x2, 0x2, 0x2, 0x234, 0x239, 0x5, 0x48, 0x25, 0x2, 0x235, 
    0x236, 0x7, 0x46, 0x2, 0x2, 0x236, 0x238, 0x5, 0x48, 0x25, 0x2, 0x237, 
    0x235, 0x3, 0x2, 0x2, 0x2, 0x238, 0x23b, 0x3, 0x2, 0x2, 0x2, 0x239, 
    0x237, 0x3, 0x2, 0x2, 0x2, 0x239, 0x23a, 0x3, 0x2, 0x2, 0x2, 0x23a, 
    0x47, 0x3, 0x2, 0x2, 0x2, 0x23b, 0x239, 0x3, 0x2, 0x2, 0x2, 0x23c, 0x23f, 
    0x5, 0x4a, 0x26, 0x2, 0x23d, 0x23e, 0x7, 0x48, 0x2, 0x2, 0x23e, 0x240, 
    0x5, 0x4c, 0x27, 0x2, 0x23f, 0x23d, 0x3, 0x2, 0x2, 0x2, 0x23f, 0x240, 
    0x3, 0x2, 0x2, 0x2, 0x240, 0x49, 0x3, 0x2, 0x2, 0x2, 0x241, 0x246, 0x7, 
    0x71, 0x2, 0x2, 0x242, 0x243, 0x7, 0x43, 0x2, 0x2, 0x243, 0x245, 0x7, 
    0x44, 0x2, 0x2, 0x244, 0x242, 0x3, 0x2, 0x2, 0x2, 0x245, 0x248, 0x3, 
    0x2, 0x2, 0x2, 0x246, 0x244, 0x3, 0x2, 0x2, 0x2, 0x246, 0x247, 0x3, 
    0x2, 0x2, 0x2, 0x247, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x248, 0x246, 0x3, 0x2, 
    0x2, 0x2, 0x249, 0x24c, 0x5, 0x4e, 0x28, 0x2, 0x24a, 0x24c, 0x5, 0xa8, 
    0x55, 0x2, 0x24b, 0x249, 0x3, 0x2, 0x2, 0x2, 0x24b, 0x24a, 0x3, 0x2, 
    0x2, 0x2, 0x24c, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x24d, 0x259, 0x7, 0x41, 
    0x2, 0x2, 0x24e, 0x253, 0x5, 0x4c, 0x27, 0x2, 0x24f, 0x250, 0x7, 0x46, 
    0x2, 0x2, 0x250, 0x252, 0x5, 0x4c, 0x27, 0x2, 0x251, 0x24f, 0x3, 0x2, 
    0x2, 0x2, 0x252, 0x255, 0x3, 0x2, 0x2, 0x2, 0x253, 0x251, 0x3, 0x2, 
    0x2, 0x2, 0x253, 0x254, 0x3, 0x2, 0x2, 0x2, 0x254, 0x257, 0x3, 0x2, 
    0x2, 0x2, 0x255, 0x253, 0x3, 0x2, 0x2, 0x2, 0x256, 0x258, 0x7, 0x46, 
    0x2, 0x2, 0x257, 0x256, 0x3, 0x2, 0x2, 0x2, 0x257, 0x258, 0x3, 0x2, 
    0x2, 0x2, 0x258, 0x25a, 0x3, 0x2, 0x2, 0x2, 0x259, 0x24e, 0x3, 0x2, 
    0x2, 0x2, 0x259, 0x25a, 0x3, 0x2, 0x2, 0x2, 0x25a, 0x25b, 0x3, 0x2, 
    0x2, 0x2, 0x25b, 0x25c, 0x7, 0x42, 0x2, 0x2, 0x25c, 0x4f, 0x3, 0x2, 
    0x2, 0x2, 0x25d, 0x25f, 0x7, 0x71, 0x2, 0x2, 0x25e, 0x260, 0x5, 0xcc, 
    0x67, 0x2, 0x25f, 0x25e, 0x3, 0x2, 0x2, 0x2, 0x25f, 0x260, 0x3, 0x2, 
    0x2, 0x2, 0x260, 0x268, 0x3, 0x2, 0x2, 0x2, 0x261, 0x262, 0x7, 0x47, 
    0x2, 0x2, 0x262, 0x264, 0x7, 0x71, 0x2, 0x2, 0x263, 0x265, 0x5, 0xcc, 
    0x67, 0x2, 0x264, 0x263, 0x3, 0x2, 0x2, 0x2, 0x264, 0x265, 0x3, 0x2, 
    0x2, 0x2, 0x265, 0x267, 0x3, 0x2, 0x2, 0x2, 0x266, 0x261, 0x3, 0x2, 
    0x2, 0x2, 0x267, 0x26a, 0x3, 0x2, 0x2, 0x2, 0x268, 0x266, 0x3, 0x2, 
    0x2, 0x2, 0x268, 0x269, 0x3, 0x2, 0x2, 0x2, 0x269, 0x51, 0x3, 0x2, 0x2, 
    0x2, 0x26a, 0x268, 0x3, 0x2, 0x2, 0x2, 0x26b, 0x278, 0x5, 0xc8, 0x65, 
    0x2, 0x26c, 0x26e, 0x5, 0x68, 0x35, 0x2, 0x26d, 0x26c, 0x3, 0x2, 0x2, 
    0x2, 0x26e, 0x271, 0x3, 0x2, 0x2, 0x2, 0x26f, 0x26d, 0x3, 0x2, 0x2, 
    0x2, 0x26f, 0x270, 0x3, 0x2, 0x2, 0x2, 0x270, 0x272, 0x3, 0x2, 0x2, 
    0x2, 0x271, 0x26f, 0x3, 0x2, 0x2, 0x2, 0x272, 0x275, 0x7, 0x4d, 0x2, 
    0x2, 0x273, 0x274, 0x9, 0x2, 0x2, 0x2, 0x274, 0x276, 0x5, 0xc8, 0x65, 
    0x2, 0x275, 0x273, 0x3, 0x2, 0x2, 0x2, 0x275, 0x276, 0x3, 0x2, 0x2, 
    0x2, 0x276, 0x278, 0x3, 0x2, 0x2, 0x2, 0x277, 0x26b, 0x3, 0x2, 0x2, 
    0x2, 0x277, 0x26f, 0x3, 0x2, 0x2, 0x2, 0x278, 0x53, 0x3, 0x2, 0x2, 0x2, 
    0x279, 0x27e, 0x5, 0x5e, 0x30, 0x2, 0x27a, 0x27b, 0x7, 0x46, 0x2, 0x2, 
    0x27b, 0x27d, 0x5, 0x5e, 0x30, 0x2, 0x27c, 0x27a, 0x3, 0x2, 0x2, 0x2, 
    0x27d, 0x280, 0x3, 0x2, 0x2, 0x2, 0x27e, 0x27c, 0x3, 0x2, 0x2, 0x2, 
    0x27e, 0x27f, 0x3, 0x2, 0x2, 0x2, 0x27f, 0x55, 0x3, 0x2, 0x2, 0x2, 0x280, 
    0x27e, 0x3, 0x2, 0x2, 0x2, 0x281, 0x283, 0x7, 0x3f, 0x2, 0x2, 0x282, 
    0x284, 0x5, 0x58, 0x2d, 0x2, 0x283, 0x282, 0x3, 0x2, 0x2, 0x2, 0x283, 
    0x284, 0x3, 0x2, 0x2, 0x2, 0x284, 0x285, 0x3, 0x2, 0x2, 0x2, 0x285, 
    0x286, 0x7, 0x40, 0x2, 0x2, 0x286, 0x57, 0x3, 0x2, 0x2, 0x2, 0x287, 
    0x28c, 0x5, 0x5a, 0x2e, 0x2, 0x288, 0x289, 0x7, 0x46, 0x2, 0x2, 0x289, 
    0x28b, 0x5, 0x5a, 0x2e, 0x2, 0x28a, 0x288, 0x3, 0x2, 0x2, 0x2, 0x28b, 
    0x28e, 0x3, 0x2, 0x2, 0x2, 0x28c, 0x28a, 0x3, 0x2, 0x2, 0x2, 0x28c, 
    0x28d, 0x3, 0x2, 0x2, 0x2, 0x28d, 0x291, 0x3, 0x2, 0x2, 0x2, 0x28e, 
    0x28c, 0x3, 0x2, 0x2, 0x2, 0x28f, 0x290, 0x7, 0x46, 0x2, 0x2, 0x290, 
    0x292, 0x5, 0x5c, 0x2f, 0x2, 0x291, 0x28f, 0x3, 0x2, 0x2, 0x2, 0x291, 
    0x292, 0x3, 0x2, 0x2, 0x2, 0x292, 0x295, 0x3, 0x2, 0x2, 0x2, 0x293, 
    0x295, 0x5, 0x5c, 0x2f, 0x2, 0x294, 0x287, 0x3, 0x2, 0x2, 0x2, 0x294, 
    0x293, 0x3, 0x2, 0x2, 0x2, 0x295, 0x59, 0x3, 0x2, 0x2, 0x2, 0x296, 0x298, 
    0x5, 0xe, 0x8, 0x2, 0x297, 0x296, 0x3, 0x2, 0x2, 0x2, 0x298, 0x29b, 
    0x3, 0x2, 0x2, 0x2, 0x299, 0x297, 0x3, 0x2, 0x2, 0x2, 0x299, 0x29a, 
    0x3, 0x2, 0x2, 0x2, 0x29a, 0x29c, 0x3, 0x2, 0x2, 0x2, 0x29b, 0x299, 
    0x3, 0x2, 0x2, 0x2, 0x29c, 0x29d, 0x5, 0xc8, 0x65, 0x2, 0x29d, 0x29e, 
    0x5, 0x4a, 0x26, 0x2, 0x29e, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x29f, 0x2a1, 
    0x5, 0xe, 0x8, 0x2, 0x2a0, 0x29f, 0x3, 0x2, 0x2, 0x2, 0x2a1, 0x2a4, 
    0x3, 0x2, 0x2, 0x2, 0x2a2, 0x2a0, 0x3, 0x2, 0x2, 0x2, 0x2a2, 0x2a3, 
    0x3, 0x2, 0x2, 0x2, 0x2a3, 0x2a5, 0x3, 0x2, 0x2, 0x2, 0x2a4, 0x2a2, 
    0x3, 0x2, 0x2, 0x2, 0x2a5, 0x2a9, 0x5, 0xc8, 0x65, 0x2, 0x2a6, 0x2a8, 
    0x5, 0x68, 0x35, 0x2, 0x2a7, 0x2a6, 0x3, 0x2, 0x2, 0x2, 0x2a8, 0x2ab, 
    0x3, 0x2, 0x2, 0x2, 0x2a9, 0x2a7, 0x3, 0x2, 0x2, 0x2, 0x2a9, 0x2aa, 
    0x3, 0x2, 0x2, 0x2, 0x2aa, 0x2ac, 0x3, 0x2, 0x2, 0x2, 0x2ab, 0x2a9, 
    0x3, 0x2, 0x2, 0x2, 0x2ac, 0x2ad, 0x7, 0x6d, 0x2, 0x2, 0x2ad, 0x2ae, 
    0x5, 0x4a, 0x26, 0x2, 0x2ae, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x2af, 0x2b4, 
    0x7, 0x71, 0x2, 0x2, 0x2b0, 0x2b1, 0x7, 0x47, 0x2, 0x2, 0x2b1, 0x2b3, 
    0x7, 0x71, 0x2, 0x2, 0x2b2, 0x2b0, 0x3, 0x2, 0x2, 0x2, 0x2b3, 0x2b6, 
    0x3, 0x2, 0x2, 0x2, 0x2b4, 0x2b2, 0x3, 0x2, 0x2, 0x2, 0x2b4, 0x2b5, 
    0x3, 0x2, 0x2, 0x2, 0x2b5, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x2b6, 0x2b4, 0x3, 
    0x2, 0x2, 0x2, 0x2b7, 0x2be, 0x5, 0x62, 0x32, 0x2, 0x2b8, 0x2be, 0x5, 
    0x64, 0x33, 0x2, 0x2b9, 0x2be, 0x7, 0x3c, 0x2, 0x2, 0x2ba, 0x2be, 0x7, 
    0x3d, 0x2, 0x2, 0x2bb, 0x2be, 0x7, 0x3b, 0x2, 0x2, 0x2bc, 0x2be, 0x7, 
    0x3e, 0x2, 0x2, 0x2bd, 0x2b7, 0x3, 0x2, 0x2, 0x2, 0x2bd, 0x2b8, 0x3, 
    0x2, 0x2, 0x2, 0x2bd, 0x2b9, 0x3, 0x2, 0x2, 0x2, 0x2bd, 0x2ba, 0x3, 
    0x2, 0x2, 0x2, 0x2bd, 0x2bb, 0x3, 0x2, 0x2, 0x2, 0x2bd, 0x2bc, 0x3, 
    0x2, 0x2, 0x2, 0x2be, 0x61, 0x3, 0x2, 0x2, 0x2, 0x2bf, 0x2c0, 0x9, 0x3, 
    0x2, 0x2, 0x2c0, 0x63, 0x3, 0x2, 0x2, 0x2, 0x2c1, 0x2c2, 0x9, 0x4, 0x2, 
    0x2, 0x2c2, 0x65, 0x3, 0x2, 0x2, 0x2, 0x2c3, 0x2c4, 0x7, 0x71, 0x2, 
    0x2, 0x2c4, 0x2c6, 0x7, 0x47, 0x2, 0x2, 0x2c5, 0x2c3, 0x3, 0x2, 0x2, 
    0x2, 0x2c6, 0x2c9, 0x3, 0x2, 0x2, 0x2, 0x2c7, 0x2c5, 0x3, 0x2, 0x2, 
    0x2, 0x2c7, 0x2c8, 0x3, 0x2, 0x2, 0x2, 0x2c8, 0x2ca, 0x3, 0x2, 0x2, 
    0x2, 0x2c9, 0x2c7, 0x3, 0x2, 0x2, 0x2, 0x2ca, 0x2cb, 0x7, 0x6c, 0x2, 
    0x2, 0x2cb, 0x2cc, 0x7, 0x71, 0x2, 0x2, 0x2cc, 0x67, 0x3, 0x2, 0x2, 
    0x2, 0x2cd, 0x2ce, 0x7, 0x6c, 0x2, 0x2, 0x2ce, 0x2d1, 0x5, 0x5e, 0x30, 
    0x2, 0x2cf, 0x2d1, 0x5, 0x66, 0x34, 0x2, 0x2d0, 0x2cd, 0x3, 0x2, 0x2, 
    0x2, 0x2d0, 0x2cf, 0x3, 0x2, 0x2, 0x2, 0x2d1, 0x2d8, 0x3, 0x2, 0x2, 
    0x2, 0x2d2, 0x2d5, 0x7, 0x3f, 0x2, 0x2, 0x2d3, 0x2d6, 0x5, 0x6a, 0x36, 
    0x2, 0x2d4, 0x2d6, 0x5, 0x6e, 0x38, 0x2, 0x2d5, 0x2d3, 0x3, 0x2, 0x2, 
    0x2, 0x2d5, 0x2d4, 0x3, 0x2, 0x2, 0x2, 0x2d5, 0x2d6, 0x3, 0x2, 0x2, 
    0x2, 0x2d6, 0x2d7, 0x3, 0x2, 0x2, 0x2, 0x2d7, 0x2d9, 0x7, 0x40, 0x2, 
    0x2, 0x2d8, 0x2d2, 0x3, 0x2, 0x2, 0x2, 0x2d8, 0x2d9, 0x3, 0x2, 0x2, 
    0x2, 0x2d9, 0x69, 0x3, 0x2, 0x2, 0x2, 0x2da, 0x2df, 0x5, 0x6c, 0x37, 
    0x2, 0x2db, 0x2dc, 0x7, 0x46, 0x2, 0x2, 0x2dc, 0x2de, 0x5, 0x6c, 0x37, 
    0x2, 0x2dd, 0x2db, 0x3, 0x2, 0x2, 0x2, 0x2de, 0x2e1, 0x3, 0x2, 0x2, 
    0x2, 0x2df, 0x2dd, 0x3, 0x2, 0x2, 0x2, 0x2df, 0x2e0, 0x3, 0x2, 0x2, 
    0x2, 0x2e0, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x2e1, 0x2df, 0x3, 0x2, 0x2, 0x2, 
    0x2e2, 0x2e3, 0x7, 0x71, 0x2, 0x2, 0x2e3, 0x2e4, 0x7, 0x48, 0x2, 0x2, 
    0x2e4, 0x2e5, 0x5, 0x6e, 0x38, 0x2, 0x2e5, 0x6d, 0x3, 0x2, 0x2, 0x2, 
    0x2e6, 0x2ea, 0x5, 0xa8, 0x55, 0x2, 0x2e7, 0x2ea, 0x5, 0x68, 0x35, 0x2, 
    0x2e8, 0x2ea, 0x5, 0x70, 0x39, 0x2, 0x2e9, 0x2e6, 0x3, 0x2, 0x2, 0x2, 
    0x2e9, 0x2e7, 0x3, 0x2, 0x2, 0x2, 0x2e9, 0x2e8, 0x3, 0x2, 0x2, 0x2, 
    0x2ea, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x2eb, 0x2f4, 0x7, 0x41, 0x2, 0x2, 
    0x2ec, 0x2f1, 0x5, 0x6e, 0x38, 0x2, 0x2ed, 0x2ee, 0x7, 0x46, 0x2, 0x2, 
    0x2ee, 0x2f0, 0x5, 0x6e, 0x38, 0x2, 0x2ef, 0x2ed, 0x3, 0x2, 0x2, 0x2, 
    0x2f0, 0x2f3, 0x3, 0x2, 0x2, 0x2, 0x2f1, 0x2ef, 0x3, 0x2, 0x2, 0x2, 
    0x2f1, 0x2f2, 0x3, 0x2, 0x2, 0x2, 0x2f2, 0x2f5, 0x3, 0x2, 0x2, 0x2, 
    0x2f3, 0x2f1, 0x3, 0x2, 0x2, 0x2, 0x2f4, 0x2ec, 0x3, 0x2, 0x2, 0x2, 
    0x2f4, 0x2f5, 0x3, 0x2, 0x2, 0x2, 0x2f5, 0x2f7, 0x3, 0x2, 0x2, 0x2, 
    0x2f6, 0x2f8, 0x7, 0x46, 0x2, 0x2, 0x2f7, 0x2f6, 0x3, 0x2, 0x2, 0x2, 
    0x2f7, 0x2f8, 0x3, 0x2, 0x2, 0x2, 0x2f8, 0x2f9, 0x3, 0x2, 0x2, 0x2, 
    0x2f9, 0x2fa, 0x7, 0x42, 0x2, 0x2, 0x2fa, 0x71, 0x3, 0x2, 0x2, 0x2, 
    0x2fb, 0x2fc, 0x7, 0x6c, 0x2, 0x2, 0x2fc, 0x2fd, 0x7, 0x1e, 0x2, 0x2, 
    0x2fd, 0x2fe, 0x7, 0x71, 0x2, 0x2, 0x2fe, 0x2ff, 0x5, 0x74, 0x3b, 0x2, 
    0x2ff, 0x73, 0x3, 0x2, 0x2, 0x2, 0x300, 0x304, 0x7, 0x41, 0x2, 0x2, 
    0x301, 0x303, 0x5, 0x76, 0x3c, 0x2, 0x302, 0x301, 0x3, 0x2, 0x2, 0x2, 
    0x303, 0x306, 0x3, 0x2, 0x2, 0x2, 0x304, 0x302, 0x3, 0x2, 0x2, 0x2, 
    0x304, 0x305, 0x3, 0x2, 0x2, 0x2, 0x305, 0x307, 0x3, 0x2, 0x2, 0x2, 
    0x306, 0x304, 0x3, 0x2, 0x2, 0x2, 0x307, 0x308, 0x7, 0x42, 0x2, 0x2, 
    0x308, 0x75, 0x3, 0x2, 0x2, 0x2, 0x309, 0x30b, 0x5, 0xa, 0x6, 0x2, 0x30a, 
    0x309, 0x3, 0x2, 0x2, 0x2, 0x30b, 0x30e, 0x3, 0x2, 0x2, 0x2, 0x30c, 
    0x30a, 0x3, 0x2, 0x2, 0x2, 0x30c, 0x30d, 0x3, 0x2, 0x2, 0x2, 0x30d, 
    0x30f, 0x3, 0x2, 0x2, 0x2, 0x30e, 0x30c, 0x3, 0x2, 0x2, 0x2, 0x30f, 
    0x312, 0x5, 0x78, 0x3d, 0x2, 0x310, 0x312, 0x7, 0x45, 0x2, 0x2, 0x311, 
    0x30c, 0x3, 0x2, 0x2, 0x2, 0x311, 0x310, 0x3, 0x2, 0x2, 0x2, 0x312, 
    0x77, 0x3, 0x2, 0x2, 0x2, 0x313, 0x314, 0x5, 0xc8, 0x65, 0x2, 0x314, 
    0x315, 0x5, 0x7a, 0x3e, 0x2, 0x315, 0x316, 0x7, 0x45, 0x2, 0x2, 0x316, 
    0x328, 0x3, 0x2, 0x2, 0x2, 0x317, 0x319, 0x5, 0x10, 0x9, 0x2, 0x318, 
    0x31a, 0x7, 0x45, 0x2, 0x2, 0x319, 0x318, 0x3, 0x2, 0x2, 0x2, 0x319, 
    0x31a, 0x3, 0x2, 0x2, 0x2, 0x31a, 0x328, 0x3, 0x2, 0x2, 0x2, 0x31b, 
    0x31d, 0x5, 0x20, 0x11, 0x2, 0x31c, 0x31e, 0x7, 0x45, 0x2, 0x2, 0x31d, 
    0x31c, 0x3, 0x2, 0x2, 0x2, 0x31d, 0x31e, 0x3, 0x2, 0x2, 0x2, 0x31e, 
    0x328, 0x3, 0x2, 0x2, 0x2, 0x31f, 0x321, 0x5, 0x18, 0xd, 0x2, 0x320, 
    0x322, 0x7, 0x45, 0x2, 0x2, 0x321, 0x320, 0x3, 0x2, 0x2, 0x2, 0x321, 
    0x322, 0x3, 0x2, 0x2, 0x2, 0x322, 0x328, 0x3, 0x2, 0x2, 0x2, 0x323, 
    0x325, 0x5, 0x72, 0x3a, 0x2, 0x324, 0x326, 0x7, 0x45, 0x2, 0x2, 0x325, 
    0x324, 0x3, 0x2, 0x2, 0x2, 0x325, 0x326, 0x3, 0x2, 0x2, 0x2, 0x326, 
    0x328, 0x3, 0x2, 0x2, 0x2, 0x327, 0x313, 0x3, 0x2, 0x2, 0x2, 0x327, 
    0x317, 0x3, 0x2, 0x2, 0x2, 0x327, 0x31b, 0x3, 0x2, 0x2, 0x2, 0x327, 
    0x31f, 0x3, 0x2, 0x2, 0x2, 0x327, 0x323, 0x3, 0x2, 0x2, 0x2, 0x328, 
    0x79, 0x3, 0x2, 0x2, 0x2, 0x329, 0x32c, 0x5, 0x7c, 0x3f, 0x2, 0x32a, 
    0x32c, 0x5, 0x7e, 0x40, 0x2, 0x32b, 0x329, 0x3, 0x2, 0x2, 0x2, 0x32b, 
    0x32a, 0x3, 0x2, 0x2, 0x2, 0x32c, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x32d, 0x32e, 
    0x7, 0x71, 0x2, 0x2, 0x32e, 0x32f, 0x7, 0x3f, 0x2, 0x2, 0x32f, 0x331, 
    0x7, 0x40, 0x2, 0x2, 0x330, 0x332, 0x5, 0x80, 0x41, 0x2, 0x331, 0x330, 
    0x3, 0x2, 0x2, 0x2, 0x331, 0x332, 0x3, 0x2, 0x2, 0x2, 0x332, 0x7d, 0x3, 
    0x2, 0x2, 0x2, 0x333, 0x334, 0x5, 0x46, 0x24, 0x2, 0x334, 0x7f, 0x3, 
    0x2, 0x2, 0x2, 0x335, 0x336, 0x7, 0xe, 0x2, 0x2, 0x336, 0x337, 0x5, 
    0x6e, 0x38, 0x2, 0x337, 0x81, 0x3, 0x2, 0x2, 0x2, 0x338, 0x33c, 0x7, 
    0x41, 0x2, 0x2, 0x339, 0x33b, 0x5, 0x84, 0x43, 0x2, 0x33a, 0x339, 0x3, 
    0x2, 0x2, 0x2, 0x33b, 0x33e, 0x3, 0x2, 0x2, 0x2, 0x33c, 0x33a, 0x3, 
    0x2, 0x2, 0x2, 0x33c, 0x33d, 0x3, 0x2, 0x2, 0x2, 0x33d, 0x33f, 0x3, 
    0x2, 0x2, 0x2, 0x33e, 0x33c, 0x3, 0x2, 0x2, 0x2, 0x33f, 0x340, 0x7, 
    0x42, 0x2, 0x2, 0x340, 0x83, 0x3, 0x2, 0x2, 0x2, 0x341, 0x342, 0x5, 
    0x86, 0x44, 0x2, 0x342, 0x343, 0x7, 0x45, 0x2, 0x2, 0x343, 0x347, 0x3, 
    0x2, 0x2, 0x2, 0x344, 0x347, 0x5, 0x8a, 0x46, 0x2, 0x345, 0x347, 0x5, 
    0x88, 0x45, 0x2, 0x346, 0x341, 0x3, 0x2, 0x2, 0x2, 0x346, 0x344, 0x3, 
    0x2, 0x2, 0x2, 0x346, 0x345, 0x3, 0x2, 0x2, 0x2, 0x347, 0x85, 0x3, 0x2, 
    0x2, 0x2, 0x348, 0x34a, 0x5, 0xe, 0x8, 0x2, 0x349, 0x348, 0x3, 0x2, 
    0x2, 0x2, 0x34a, 0x34d, 0x3, 0x2, 0x2, 0x2, 0x34b, 0x349, 0x3, 0x2, 
    0x2, 0x2, 0x34b, 0x34c, 0x3, 0x2, 0x2, 0x2, 0x34c, 0x34e, 0x3, 0x2, 
    0x2, 0x2, 0x34d, 0x34b, 0x3, 0x2, 0x2, 0x2, 0x34e, 0x34f, 0x5, 0xc8, 
    0x65, 0x2, 0x34f, 0x350, 0x5, 0x46, 0x24, 0x2, 0x350, 0x87, 0x3, 0x2, 
    0x2, 0x2, 0x351, 0x353, 0x5, 0xc, 0x7, 0x2, 0x352, 0x351, 0x3, 0x2, 
    0x2, 0x2, 0x353, 0x356, 0x3, 0x2, 0x2, 0x2, 0x354, 0x352, 0x3, 0x2, 
    0x2, 0x2, 0x354, 0x355, 0x3, 0x2, 0x2, 0x2, 0x355, 0x359, 0x3, 0x2, 
    0x2, 0x2, 0x356, 0x354, 0x3, 0x2, 0x2, 0x2, 0x357, 0x35a, 0x5, 0x10, 
    0x9, 0x2, 0x358, 0x35a, 0x5, 0x20, 0x11, 0x2, 0x359, 0x357, 0x3, 0x2, 
    0x2, 0x2, 0x359, 0x358, 0x3, 0x2, 0x2, 0x2, 0x35a, 0x35d, 0x3, 0x2, 
    0x2, 0x2, 0x35b, 0x35d, 0x7, 0x45, 0x2, 0x2, 0x35c, 0x354, 0x3, 0x2, 
    0x2, 0x2, 0x35c, 0x35b, 0x3, 0x2, 0x2, 0x2, 0x35d, 0x89, 0x3, 0x2, 0x2, 
    0x2, 0x35e, 0x3c7, 0x5, 0x82, 0x42, 0x2, 0x35f, 0x360, 0x7, 0x4, 0x2, 
    0x2, 0x360, 0x363, 0x5, 0xa8, 0x55, 0x2, 0x361, 0x362, 0x7, 0x4e, 0x2, 
    0x2, 0x362, 0x364, 0x5, 0xa8, 0x55, 0x2, 0x363, 0x361, 0x3, 0x2, 0x2, 
    0x2, 0x363, 0x364, 0x3, 0x2, 0x2, 0x2, 0x364, 0x365, 0x3, 0x2, 0x2, 
    0x2, 0x365, 0x366, 0x7, 0x45, 0x2, 0x2, 0x366, 0x3c7, 0x3, 0x2, 0x2, 
    0x2, 0x367, 0x368, 0x7, 0x18, 0x2, 0x2, 0x368, 0x369, 0x5, 0xa2, 0x52, 
    0x2, 0x369, 0x36c, 0x5, 0x8a, 0x46, 0x2, 0x36a, 0x36b, 0x7, 0x11, 0x2, 
    0x2, 0x36b, 0x36d, 0x5, 0x8a, 0x46, 0x2, 0x36c, 0x36a, 0x3, 0x2, 0x2, 
    0x2, 0x36c, 0x36d, 0x3, 0x2, 0x2, 0x2, 0x36d, 0x3c7, 0x3, 0x2, 0x2, 
    0x2, 0x36e, 0x36f, 0x7, 0x17, 0x2, 0x2, 0x36f, 0x370, 0x7, 0x3f, 0x2, 
    0x2, 0x370, 0x371, 0x5, 0x9c, 0x4f, 0x2, 0x371, 0x372, 0x7, 0x40, 0x2, 
    0x2, 0x372, 0x373, 0x5, 0x8a, 0x46, 0x2, 0x373, 0x3c7, 0x3, 0x2, 0x2, 
    0x2, 0x374, 0x375, 0x7, 0x34, 0x2, 0x2, 0x375, 0x376, 0x5, 0xa2, 0x52, 
    0x2, 0x376, 0x377, 0x5, 0x8a, 0x46, 0x2, 0x377, 0x3c7, 0x3, 0x2, 0x2, 
    0x2, 0x378, 0x379, 0x7, 0xf, 0x2, 0x2, 0x379, 0x37a, 0x5, 0x8a, 0x46, 
    0x2, 0x37a, 0x37b, 0x7, 0x34, 0x2, 0x2, 0x37b, 0x37c, 0x5, 0xa2, 0x52, 
    0x2, 0x37c, 0x37d, 0x7, 0x45, 0x2, 0x2, 0x37d, 0x3c7, 0x3, 0x2, 0x2, 
    0x2, 0x37e, 0x37f, 0x7, 0x31, 0x2, 0x2, 0x37f, 0x389, 0x5, 0x82, 0x42, 
    0x2, 0x380, 0x382, 0x5, 0x8c, 0x47, 0x2, 0x381, 0x380, 0x3, 0x2, 0x2, 
    0x2, 0x382, 0x383, 0x3, 0x2, 0x2, 0x2, 0x383, 0x381, 0x3, 0x2, 0x2, 
    0x2, 0x383, 0x384, 0x3, 0x2, 0x2, 0x2, 0x384, 0x386, 0x3, 0x2, 0x2, 
    0x2, 0x385, 0x387, 0x5, 0x90, 0x49, 0x2, 0x386, 0x385, 0x3, 0x2, 0x2, 
    0x2, 0x386, 0x387, 0x3, 0x2, 0x2, 0x2, 0x387, 0x38a, 0x3, 0x2, 0x2, 
    0x2, 0x388, 0x38a, 0x5, 0x90, 0x49, 0x2, 0x389, 0x381, 0x3, 0x2, 0x2, 
    0x2, 0x389, 0x388, 0x3, 0x2, 0x2, 0x2, 0x38a, 0x3c7, 0x3, 0x2, 0x2, 
    0x2, 0x38b, 0x38c, 0x7, 0x31, 0x2, 0x2, 0x38c, 0x38d, 0x5, 0x92, 0x4a, 
    0x2, 0x38d, 0x391, 0x5, 0x82, 0x42, 0x2, 0x38e, 0x390, 0x5, 0x8c, 0x47, 
    0x2, 0x38f, 0x38e, 0x3, 0x2, 0x2, 0x2, 0x390, 0x393, 0x3, 0x2, 0x2, 
    0x2, 0x391, 0x38f, 0x3, 0x2, 0x2, 0x2, 0x391, 0x392, 0x3, 0x2, 0x2, 
    0x2, 0x392, 0x395, 0x3, 0x2, 0x2, 0x2, 0x393, 0x391, 0x3, 0x2, 0x2, 
    0x2, 0x394, 0x396, 0x5, 0x90, 0x49, 0x2, 0x395, 0x394, 0x3, 0x2, 0x2, 
    0x2, 0x395, 0x396, 0x3, 0x2, 0x2, 0x2, 0x396, 0x3c7, 0x3, 0x2, 0x2, 
    0x2, 0x397, 0x398, 0x7, 0x2b, 0x2, 0x2, 0x398, 0x399, 0x5, 0xa2, 0x52, 
    0x2, 0x399, 0x39d, 0x7, 0x41, 0x2, 0x2, 0x39a, 0x39c, 0x5, 0x98, 0x4d, 
    0x2, 0x39b, 0x39a, 0x3, 0x2, 0x2, 0x2, 0x39c, 0x39f, 0x3, 0x2, 0x2, 
    0x2, 0x39d, 0x39b, 0x3, 0x2, 0x2, 0x2, 0x39d, 0x39e, 0x3, 0x2, 0x2, 
    0x2, 0x39e, 0x3a3, 0x3, 0x2, 0x2, 0x2, 0x39f, 0x39d, 0x3, 0x2, 0x2, 
    0x2, 0x3a0, 0x3a2, 0x5, 0x9a, 0x4e, 0x2, 0x3a1, 0x3a0, 0x3, 0x2, 0x2, 
    0x2, 0x3a2, 0x3a5, 0x3, 0x2, 0x2, 0x2, 0x3a3, 0x3a1, 0x3, 0x2, 0x2, 
    0x2, 0x3a3, 0x3a4, 0x3, 0x2, 0x2, 0x2, 0x3a4, 0x3a6, 0x3, 0x2, 0x2, 
    0x2, 0x3a5, 0x3a3, 0x3, 0x2, 0x2, 0x2, 0x3a6, 0x3a7, 0x7, 0x42, 0x2, 
    0x2, 0x3a7, 0x3c7, 0x3, 0x2, 0x2, 0x2, 0x3a8, 0x3a9, 0x7, 0x2c, 0x2, 
    0x2, 0x3a9, 0x3aa, 0x5, 0xa2, 0x52, 0x2, 0x3aa, 0x3ab, 0x5, 0x82, 0x42, 
    0x2, 0x3ab, 0x3c7, 0x3, 0x2, 0x2, 0x2, 0x3ac, 0x3ae, 0x7, 0x26, 0x2, 
    0x2, 0x3ad, 0x3af, 0x5, 0xa8, 0x55, 0x2, 0x3ae, 0x3ad, 0x3, 0x2, 0x2, 
    0x2, 0x3ae, 0x3af, 0x3, 0x2, 0x2, 0x2, 0x3af, 0x3b0, 0x3, 0x2, 0x2, 
    0x2, 0x3b0, 0x3c7, 0x7, 0x45, 0x2, 0x2, 0x3b1, 0x3b2, 0x7, 0x2e, 0x2, 
    0x2, 0x3b2, 0x3b3, 0x5, 0xa8, 0x55, 0x2, 0x3b3, 0x3b4, 0x7, 0x45, 0x2, 
    0x2, 0x3b4, 0x3c7, 0x3, 0x2, 0x2, 0x2, 0x3b5, 0x3b7, 0x7, 0x6, 0x2, 
    0x2, 0x3b6, 0x3b8, 0x7, 0x71, 0x2, 0x2, 0x3b7, 0x3b6, 0x3, 0x2, 0x2, 
    0x2, 0x3b7, 0x3b8, 0x3, 0x2, 0x2, 0x2, 0x3b8, 0x3b9, 0x3, 0x2, 0x2, 
    0x2, 0x3b9, 0x3c7, 0x7, 0x45, 0x2, 0x2, 0x3ba, 0x3bc, 0x7, 0xd, 0x2, 
    0x2, 0x3bb, 0x3bd, 0x7, 0x71, 0x2, 0x2, 0x3bc, 0x3bb, 0x3, 0x2, 0x2, 
    0x2, 0x3bc, 0x3bd, 0x3, 0x2, 0x2, 0x2, 0x3bd, 0x3be, 0x3, 0x2, 0x2, 
    0x2, 0x3be, 0x3c7, 0x7, 0x45, 0x2, 0x2, 0x3bf, 0x3c7, 0x7, 0x45, 0x2, 
    0x2, 0x3c0, 0x3c1, 0x5, 0xa8, 0x55, 0x2, 0x3c1, 0x3c2, 0x7, 0x45, 0x2, 
    0x2, 0x3c2, 0x3c7, 0x3, 0x2, 0x2, 0x2, 0x3c3, 0x3c4, 0x7, 0x71, 0x2, 
    0x2, 0x3c4, 0x3c5, 0x7, 0x4e, 0x2, 0x2, 0x3c5, 0x3c7, 0x5, 0x8a, 0x46, 
    0x2, 0x3c6, 0x35e, 0x3, 0x2, 0x2, 0x2, 0x3c6, 0x35f, 0x3, 0x2, 0x2, 
    0x2, 0x3c6, 0x367, 0x3, 0x2, 0x2, 0x2, 0x3c6, 0x36e, 0x3, 0x2, 0x2, 
    0x2, 0x3c6, 0x374, 0x3, 0x2, 0x2, 0x2, 0x3c6, 0x378, 0x3, 0x2, 0x2, 
    0x2, 0x3c6, 0x37e, 0x3, 0x2, 0x2, 0x2, 0x3c6, 0x38b, 0x3, 0x2, 0x2, 
    0x2, 0x3c6, 0x397, 0x3, 0x2, 0x2, 0x2, 0x3c6, 0x3a8, 0x3, 0x2, 0x2, 
    0x2, 0x3c6, 0x3ac, 0x3, 0x2, 0x2, 0x2, 0x3c6, 0x3b1, 0x3, 0x2, 0x2, 
    0x2, 0x3c6, 0x3b5, 0x3, 0x2, 0x2, 0x2, 0x3c6, 0x3ba, 0x3, 0x2, 0x2, 
    0x2, 0x3c6, 0x3bf, 0x3, 0x2, 0x2, 0x2, 0x3c6, 0x3c0, 0x3, 0x2, 0x2, 
    0x2, 0x3c6, 0x3c3, 0x3, 0x2, 0x2, 0x2, 0x3c7, 0x8b, 0x3, 0x2, 0x2, 0x2, 
    0x3c8, 0x3c9, 0x7, 0x9, 0x2, 0x2, 0x3c9, 0x3cd, 0x7, 0x3f, 0x2, 0x2, 
    0x3ca, 0x3cc, 0x5, 0xe, 0x8, 0x2, 0x3cb, 0x3ca, 0x3, 0x2, 0x2, 0x2, 
    0x3cc, 0x3cf, 0x3, 0x2, 0x2, 0x2, 0x3cd, 0x3cb, 0x3, 0x2, 0x2, 0x2, 
    0x3cd, 0x3ce, 0x3, 0x2, 0x2, 0x2, 0x3ce, 0x3d0, 0x3, 0x2, 0x2, 0x2, 
    0x3cf, 0x3cd, 0x3, 0x2, 0x2, 0x2, 0x3d0, 0x3d1, 0x5, 0x8e, 0x48, 0x2, 
    0x3d1, 0x3d2, 0x7, 0x71, 0x2, 0x2, 0x3d2, 0x3d3, 0x7, 0x40, 0x2, 0x2, 
    0x3d3, 0x3d4, 0x5, 0x82, 0x42, 0x2, 0x3d4, 0x8d, 0x3, 0x2, 0x2, 0x2, 
    0x3d5, 0x3da, 0x5, 0x5e, 0x30, 0x2, 0x3d6, 0x3d7, 0x7, 0x5c, 0x2, 0x2, 
    0x3d7, 0x3d9, 0x5, 0x5e, 0x30, 0x2, 0x3d8, 0x3d6, 0x3, 0x2, 0x2, 0x2, 
    0x3d9, 0x3dc, 0x3, 0x2, 0x2, 0x2, 0x3da, 0x3d8, 0x3, 0x2, 0x2, 0x2, 
    0x3da, 0x3db, 0x3, 0x2, 0x2, 0x2, 0x3db, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x3dc, 
    0x3da, 0x3, 0x2, 0x2, 0x2, 0x3dd, 0x3de, 0x7, 0x15, 0x2, 0x2, 0x3de, 
    0x3df, 0x5, 0x82, 0x42, 0x2, 0x3df, 0x91, 0x3, 0x2, 0x2, 0x2, 0x3e0, 
    0x3e1, 0x7, 0x3f, 0x2, 0x2, 0x3e1, 0x3e3, 0x5, 0x94, 0x4b, 0x2, 0x3e2, 
    0x3e4, 0x7, 0x45, 0x2, 0x2, 0x3e3, 0x3e2, 0x3, 0x2, 0x2, 0x2, 0x3e3, 
    0x3e4, 0x3, 0x2, 0x2, 0x2, 0x3e4, 0x3e5, 0x3, 0x2, 0x2, 0x2, 0x3e5, 
    0x3e6, 0x7, 0x40, 0x2, 0x2, 0x3e6, 0x93, 0x3, 0x2, 0x2, 0x2, 0x3e7, 
    0x3ec, 0x5, 0x96, 0x4c, 0x2, 0x3e8, 0x3e9, 0x7, 0x45, 0x2, 0x2, 0x3e9, 
    0x3eb, 0x5, 0x96, 0x4c, 0x2, 0x3ea, 0x3e8, 0x3, 0x2, 0x2, 0x2, 0x3eb, 
    0x3ee, 0x3, 0x2, 0x2, 0x2, 0x3ec, 0x3ea, 0x3, 0x2, 0x2, 0x2, 0x3ec, 
    0x3ed, 0x3, 0x2, 0x2, 0x2, 0x3ed, 0x95, 0x3, 0x2, 0x2, 0x2, 0x3ee, 0x3ec, 
    0x3, 0x2, 0x2, 0x2, 0x3ef, 0x3f1, 0x5, 0xe, 0x8, 0x2, 0x3f0, 0x3ef, 
    0x3, 0x2, 0x2, 0x2, 0x3f1, 0x3f4, 0x3, 0x2, 0x2, 0x2, 0x3f2, 0x3f0, 
    0x3, 0x2, 0x2, 0x2, 0x3f2, 0x3f3, 0x3, 0x2, 0x2, 0x2, 0x3f3, 0x3f5, 
    0x3, 0x2, 0x2, 0x2, 0x3f4, 0x3f2, 0x3, 0x2, 0x2, 0x2, 0x3f5, 0x3f6, 
    0x5, 0x50, 0x29, 0x2, 0x3f6, 0x3f7, 0x5, 0x4a, 0x26, 0x2, 0x3f7, 0x3f8, 
    0x7, 0x48, 0x2, 0x2, 0x3f8, 0x3f9, 0x5, 0xa8, 0x55, 0x2, 0x3f9, 0x97, 
    0x3, 0x2, 0x2, 0x2, 0x3fa, 0x3fc, 0x5, 0x9a, 0x4e, 0x2, 0x3fb, 0x3fa, 
    0x3, 0x2, 0x2, 0x2, 0x3fc, 0x3fd, 0x3, 0x2, 0x2, 0x2, 0x3fd, 0x3fb, 
    0x3, 0x2, 0x2, 0x2, 0x3fd, 0x3fe, 0x3, 0x2, 0x2, 0x2, 0x3fe, 0x400, 
    0x3, 0x2, 0x2, 0x2, 0x3ff, 0x401, 0x5, 0x84, 0x43, 0x2, 0x400, 0x3ff, 
    0x3, 0x2, 0x2, 0x2, 0x401, 0x402, 0x3, 0x2, 0x2, 0x2, 0x402, 0x400, 
    0x3, 0x2, 0x2, 0x2, 0x402, 0x403, 0x3, 0x2, 0x2, 0x2, 0x403, 0x99, 0x3, 
    0x2, 0x2, 0x2, 0x404, 0x407, 0x7, 0x8, 0x2, 0x2, 0x405, 0x408, 0x5, 
    0xa8, 0x55, 0x2, 0x406, 0x408, 0x7, 0x71, 0x2, 0x2, 0x407, 0x405, 0x3, 
    0x2, 0x2, 0x2, 0x407, 0x406, 0x3, 0x2, 0x2, 0x2, 0x408, 0x409, 0x3, 
    0x2, 0x2, 0x2, 0x409, 0x40d, 0x7, 0x4e, 0x2, 0x2, 0x40a, 0x40b, 0x7, 
    0xe, 0x2, 0x2, 0x40b, 0x40d, 0x7, 0x4e, 0x2, 0x2, 0x40c, 0x404, 0x3, 
    0x2, 0x2, 0x2, 0x40c, 0x40a, 0x3, 0x2, 0x2, 0x2, 0x40d, 0x9b, 0x3, 0x2, 
    0x2, 0x2, 0x40e, 0x41b, 0x5, 0xa0, 0x51, 0x2, 0x40f, 0x411, 0x5, 0x9e, 
    0x50, 0x2, 0x410, 0x40f, 0x3, 0x2, 0x2, 0x2, 0x410, 0x411, 0x3, 0x2, 
    0x2, 0x2, 0x411, 0x412, 0x3, 0x2, 0x2, 0x2, 0x412, 0x414, 0x7, 0x45, 
    0x2, 0x2, 0x413, 0x415, 0x5, 0xa8, 0x55, 0x2, 0x414, 0x413, 0x3, 0x2, 
    0x2, 0x2, 0x414, 0x415, 0x3, 0x2, 0x2, 0x2, 0x415, 0x416, 0x3, 0x2, 
    0x2, 0x2, 0x416, 0x418, 0x7, 0x45, 0x2, 0x2, 0x417, 0x419, 0x5, 0xa4, 
    0x53, 0x2, 0x418, 0x417, 0x3, 0x2, 0x2, 0x2, 0x418, 0x419, 0x3, 0x2, 
    0x2, 0x2, 0x419, 0x41b, 0x3, 0x2, 0x2, 0x2, 0x41a, 0x40e, 0x3, 0x2, 
    0x2, 0x2, 0x41a, 0x410, 0x3, 0x2, 0x2, 0x2, 0x41b, 0x9d, 0x3, 0x2, 0x2, 
    0x2, 0x41c, 0x41f, 0x5, 0x86, 0x44, 0x2, 0x41d, 0x41f, 0x5, 0xa4, 0x53, 
    0x2, 0x41e, 0x41c, 0x3, 0x2, 0x2, 0x2, 0x41e, 0x41d, 0x3, 0x2, 0x2, 
    0x2, 0x41f, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x420, 0x422, 0x5, 0xe, 0x8, 0x2, 
    0x421, 0x420, 0x3, 0x2, 0x2, 0x2, 0x422, 0x425, 0x3, 0x2, 0x2, 0x2, 
    0x423, 0x421, 0x3, 0x2, 0x2, 0x2, 0x423, 0x424, 0x3, 0x2, 0x2, 0x2, 
    0x424, 0x426, 0x3, 0x2, 0x2, 0x2, 0x425, 0x423, 0x3, 0x2, 0x2, 0x2, 
    0x426, 0x427, 0x5, 0xc8, 0x65, 0x2, 0x427, 0x428, 0x5, 0x4a, 0x26, 0x2, 
    0x428, 0x429, 0x7, 0x4e, 0x2, 0x2, 0x429, 0x42a, 0x5, 0xa8, 0x55, 0x2, 
    0x42a, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x42b, 0x42c, 0x7, 0x3f, 0x2, 0x2, 
    0x42c, 0x42d, 0x5, 0xa8, 0x55, 0x2, 0x42d, 0x42e, 0x7, 0x40, 0x2, 0x2, 
    0x42e, 0xa3, 0x3, 0x2, 0x2, 0x2, 0x42f, 0x434, 0x5, 0xa8, 0x55, 0x2, 
    0x430, 0x431, 0x7, 0x46, 0x2, 0x2, 0x431, 0x433, 0x5, 0xa8, 0x55, 0x2, 
    0x432, 0x430, 0x3, 0x2, 0x2, 0x2, 0x433, 0x436, 0x3, 0x2, 0x2, 0x2, 
    0x434, 0x432, 0x3, 0x2, 0x2, 0x2, 0x434, 0x435, 0x3, 0x2, 0x2, 0x2, 
    0x435, 0xa5, 0x3, 0x2, 0x2, 0x2, 0x436, 0x434, 0x3, 0x2, 0x2, 0x2, 0x437, 
    0x438, 0x7, 0x71, 0x2, 0x2, 0x438, 0x43a, 0x7, 0x3f, 0x2, 0x2, 0x439, 
    0x43b, 0x5, 0xa4, 0x53, 0x2, 0x43a, 0x439, 0x3, 0x2, 0x2, 0x2, 0x43a, 
    0x43b, 0x3, 0x2, 0x2, 0x2, 0x43b, 0x43c, 0x3, 0x2, 0x2, 0x2, 0x43c, 
    0x44a, 0x7, 0x40, 0x2, 0x2, 0x43d, 0x43e, 0x7, 0x2d, 0x2, 0x2, 0x43e, 
    0x440, 0x7, 0x3f, 0x2, 0x2, 0x43f, 0x441, 0x5, 0xa4, 0x53, 0x2, 0x440, 
    0x43f, 0x3, 0x2, 0x2, 0x2, 0x440, 0x441, 0x3, 0x2, 0x2, 0x2, 0x441, 
    0x442, 0x3, 0x2, 0x2, 0x2, 0x442, 0x44a, 0x7, 0x40, 0x2, 0x2, 0x443, 
    0x444, 0x7, 0x2a, 0x2, 0x2, 0x444, 0x446, 0x7, 0x3f, 0x2, 0x2, 0x445, 
    0x447, 0x5, 0xa4, 0x53, 0x2, 0x446, 0x445, 0x3, 0x2, 0x2, 0x2, 0x446, 
    0x447, 0x3, 0x2, 0x2, 0x2, 0x447, 0x448, 0x3, 0x2, 0x2, 0x2, 0x448, 
    0x44a, 0x7, 0x40, 0x2, 0x2, 0x449, 0x437, 0x3, 0x2, 0x2, 0x2, 0x449, 
    0x43d, 0x3, 0x2, 0x2, 0x2, 0x449, 0x443, 0x3, 0x2, 0x2, 0x2, 0x44a, 
    0xa7, 0x3, 0x2, 0x2, 0x2, 0x44b, 0x44c, 0x8, 0x55, 0x1, 0x2, 0x44c, 
    0x471, 0x5, 0xb0, 0x59, 0x2, 0x44d, 0x471, 0x5, 0xa6, 0x54, 0x2, 0x44e, 
    0x44f, 0x7, 0x21, 0x2, 0x2, 0x44f, 0x471, 0x5, 0xb4, 0x5b, 0x2, 0x450, 
    0x454, 0x7, 0x3f, 0x2, 0x2, 0x451, 0x453, 0x5, 0x68, 0x35, 0x2, 0x452, 
    0x451, 0x3, 0x2, 0x2, 0x2, 0x453, 0x456, 0x3, 0x2, 0x2, 0x2, 0x454, 
    0x452, 0x3, 0x2, 0x2, 0x2, 0x454, 0x455, 0x3, 0x2, 0x2, 0x2, 0x455, 
    0x457, 0x3, 0x2, 0x2, 0x2, 0x456, 0x454, 0x3, 0x2, 0x2, 0x2, 0x457, 
    0x458, 0x5, 0xc8, 0x65, 0x2, 0x458, 0x459, 0x7, 0x40, 0x2, 0x2, 0x459, 
    0x45a, 0x5, 0xa8, 0x55, 0x17, 0x45a, 0x471, 0x3, 0x2, 0x2, 0x2, 0x45b, 
    0x45c, 0x9, 0x5, 0x2, 0x2, 0x45c, 0x471, 0x5, 0xa8, 0x55, 0x15, 0x45d, 
    0x45e, 0x9, 0x6, 0x2, 0x2, 0x45e, 0x471, 0x5, 0xa8, 0x55, 0x14, 0x45f, 
    0x471, 0x5, 0xaa, 0x56, 0x2, 0x460, 0x461, 0x5, 0xc8, 0x65, 0x2, 0x461, 
    0x467, 0x7, 0x6b, 0x2, 0x2, 0x462, 0x464, 0x5, 0xcc, 0x67, 0x2, 0x463, 
    0x462, 0x3, 0x2, 0x2, 0x2, 0x463, 0x464, 0x3, 0x2, 0x2, 0x2, 0x464, 
    0x465, 0x3, 0x2, 0x2, 0x2, 0x465, 0x468, 0x7, 0x71, 0x2, 0x2, 0x466, 
    0x468, 0x7, 0x21, 0x2, 0x2, 0x467, 0x463, 0x3, 0x2, 0x2, 0x2, 0x467, 
    0x466, 0x3, 0x2, 0x2, 0x2, 0x468, 0x471, 0x3, 0x2, 0x2, 0x2, 0x469, 
    0x46a, 0x5, 0xb2, 0x5a, 0x2, 0x46a, 0x46c, 0x7, 0x6b, 0x2, 0x2, 0x46b, 
    0x46d, 0x5, 0xcc, 0x67, 0x2, 0x46c, 0x46b, 0x3, 0x2, 0x2, 0x2, 0x46c, 
    0x46d, 0x3, 0x2, 0x2, 0x2, 0x46d, 0x46e, 0x3, 0x2, 0x2, 0x2, 0x46e, 
    0x46f, 0x7, 0x21, 0x2, 0x2, 0x46f, 0x471, 0x3, 0x2, 0x2, 0x2, 0x470, 
    0x44b, 0x3, 0x2, 0x2, 0x2, 0x470, 0x44d, 0x3, 0x2, 0x2, 0x2, 0x470, 
    0x44e, 0x3, 0x2, 0x2, 0x2, 0x470, 0x450, 0x3, 0x2, 0x2, 0x2, 0x470, 
    0x45b, 0x3, 0x2, 0x2, 0x2, 0x470, 0x45d, 0x3, 0x2, 0x2, 0x2, 0x470, 
    0x45f, 0x3, 0x2, 0x2, 0x2, 0x470, 0x460, 0x3, 0x2, 0x2, 0x2, 0x470, 
    0x469, 0x3, 0x2, 0x2, 0x2, 0x471, 0x4c2, 0x3, 0x2, 0x2, 0x2, 0x472, 
    0x473, 0xc, 0x13, 0x2, 0x2, 0x473, 0x474, 0x9, 0x7, 0x2, 0x2, 0x474, 
    0x4c1, 0x5, 0xa8, 0x55, 0x14, 0x475, 0x476, 0xc, 0x12, 0x2, 0x2, 0x476, 
    0x477, 0x9, 0x8, 0x2, 0x2, 0x477, 0x4c1, 0x5, 0xa8, 0x55, 0x13, 0x478, 
    0x480, 0xc, 0x11, 0x2, 0x2, 0x479, 0x47a, 0x7, 0x4a, 0x2, 0x2, 0x47a, 
    0x481, 0x7, 0x4a, 0x2, 0x2, 0x47b, 0x47c, 0x7, 0x49, 0x2, 0x2, 0x47c, 
    0x47d, 0x7, 0x49, 0x2, 0x2, 0x47d, 0x481, 0x7, 0x49, 0x2, 0x2, 0x47e, 
    0x47f, 0x7, 0x49, 0x2, 0x2, 0x47f, 0x481, 0x7, 0x49, 0x2, 0x2, 0x480, 
    0x479, 0x3, 0x2, 0x2, 0x2, 0x480, 0x47b, 0x3, 0x2, 0x2, 0x2, 0x480, 
    0x47e, 0x3, 0x2, 0x2, 0x2, 0x481, 0x482, 0x3, 0x2, 0x2, 0x2, 0x482, 
    0x4c1, 0x5, 0xa8, 0x55, 0x12, 0x483, 0x484, 0xc, 0x10, 0x2, 0x2, 0x484, 
    0x485, 0x9, 0x9, 0x2, 0x2, 0x485, 0x4c1, 0x5, 0xa8, 0x55, 0x11, 0x486, 
    0x487, 0xc, 0xe, 0x2, 0x2, 0x487, 0x488, 0x9, 0xa, 0x2, 0x2, 0x488, 
    0x4c1, 0x5, 0xa8, 0x55, 0xf, 0x489, 0x48a, 0xc, 0xd, 0x2, 0x2, 0x48a, 
    0x48b, 0x7, 0x5b, 0x2, 0x2, 0x48b, 0x4c1, 0x5, 0xa8, 0x55, 0xe, 0x48c, 
    0x48d, 0xc, 0xc, 0x2, 0x2, 0x48d, 0x48e, 0x7, 0x5d, 0x2, 0x2, 0x48e, 
    0x4c1, 0x5, 0xa8, 0x55, 0xd, 0x48f, 0x490, 0xc, 0xb, 0x2, 0x2, 0x490, 
    0x491, 0x7, 0x5c, 0x2, 0x2, 0x491, 0x4c1, 0x5, 0xa8, 0x55, 0xc, 0x492, 
    0x493, 0xc, 0xa, 0x2, 0x2, 0x493, 0x494, 0x7, 0x53, 0x2, 0x2, 0x494, 
    0x4c1, 0x5, 0xa8, 0x55, 0xb, 0x495, 0x496, 0xc, 0x9, 0x2, 0x2, 0x496, 
    0x497, 0x7, 0x54, 0x2, 0x2, 0x497, 0x4c1, 0x5, 0xa8, 0x55, 0xa, 0x498, 
    0x499, 0xc, 0x8, 0x2, 0x2, 0x499, 0x49a, 0x7, 0x4d, 0x2, 0x2, 0x49a, 
    0x49b, 0x5, 0xa8, 0x55, 0x2, 0x49b, 0x49c, 0x7, 0x4e, 0x2, 0x2, 0x49c, 
    0x49d, 0x5, 0xa8, 0x55, 0x8, 0x49d, 0x4c1, 0x3, 0x2, 0x2, 0x2, 0x49e, 
    0x49f, 0xc, 0x7, 0x2, 0x2, 0x49f, 0x4a0, 0x9, 0xb, 0x2, 0x2, 0x4a0, 
    0x4c1, 0x5, 0xa8, 0x55, 0x7, 0x4a1, 0x4a2, 0xc, 0x1b, 0x2, 0x2, 0x4a2, 
    0x4ae, 0x7, 0x47, 0x2, 0x2, 0x4a3, 0x4af, 0x7, 0x71, 0x2, 0x2, 0x4a4, 
    0x4af, 0x5, 0xa6, 0x54, 0x2, 0x4a5, 0x4af, 0x7, 0x2d, 0x2, 0x2, 0x4a6, 
    0x4a8, 0x7, 0x21, 0x2, 0x2, 0x4a7, 0x4a9, 0x5, 0xc4, 0x63, 0x2, 0x4a8, 
    0x4a7, 0x3, 0x2, 0x2, 0x2, 0x4a8, 0x4a9, 0x3, 0x2, 0x2, 0x2, 0x4a9, 
    0x4aa, 0x3, 0x2, 0x2, 0x2, 0x4aa, 0x4af, 0x5, 0xb8, 0x5d, 0x2, 0x4ab, 
    0x4ac, 0x7, 0x2a, 0x2, 0x2, 0x4ac, 0x4af, 0x5, 0xce, 0x68, 0x2, 0x4ad, 
    0x4af, 0x5, 0xbe, 0x60, 0x2, 0x4ae, 0x4a3, 0x3, 0x2, 0x2, 0x2, 0x4ae, 
    0x4a4, 0x3, 0x2, 0x2, 0x2, 0x4ae, 0x4a5, 0x3, 0x2, 0x2, 0x2, 0x4ae, 
    0x4a6, 0x3, 0x2, 0x2, 0x2, 0x4ae, 0x4ab, 0x3, 0x2, 0x2, 0x2, 0x4ae, 
    0x4ad, 0x3, 0x2, 0x2, 0x2, 0x4af, 0x4c1, 0x3, 0x2, 0x2, 0x2, 0x4b0, 
    0x4b1, 0xc, 0x1a, 0x2, 0x2, 0x4b1, 0x4b2, 0x7, 0x43, 0x2, 0x2, 0x4b2, 
    0x4b3, 0x5, 0xa8, 0x55, 0x2, 0x4b3, 0x4b4, 0x7, 0x44, 0x2, 0x2, 0x4b4, 
    0x4c1, 0x3, 0x2, 0x2, 0x2, 0x4b5, 0x4b6, 0xc, 0x16, 0x2, 0x2, 0x4b6, 
    0x4c1, 0x9, 0xc, 0x2, 0x2, 0x4b7, 0x4b8, 0xc, 0xf, 0x2, 0x2, 0x4b8, 
    0x4b9, 0x7, 0x1c, 0x2, 0x2, 0x4b9, 0x4c1, 0x5, 0xc8, 0x65, 0x2, 0x4ba, 
    0x4bb, 0xc, 0x5, 0x2, 0x2, 0x4bb, 0x4bd, 0x7, 0x6b, 0x2, 0x2, 0x4bc, 
    0x4be, 0x5, 0xcc, 0x67, 0x2, 0x4bd, 0x4bc, 0x3, 0x2, 0x2, 0x2, 0x4bd, 
    0x4be, 0x3, 0x2, 0x2, 0x2, 0x4be, 0x4bf, 0x3, 0x2, 0x2, 0x2, 0x4bf, 
    0x4c1, 0x7, 0x71, 0x2, 0x2, 0x4c0, 0x472, 0x3, 0x2, 0x2, 0x2, 0x4c0, 
    0x475, 0x3, 0x2, 0x2, 0x2, 0x4c0, 0x478, 0x3, 0x2, 0x2, 0x2, 0x4c0, 
    0x483, 0x3, 0x2, 0x2, 0x2, 0x4c0, 0x486, 0x3, 0x2, 0x2, 0x2, 0x4c0, 
    0x489, 0x3, 0x2, 0x2, 0x2, 0x4c0, 0x48c, 0x3, 0x2, 0x2, 0x2, 0x4c0, 
    0x48f, 0x3, 0x2, 0x2, 0x2, 0x4c0, 0x492, 0x3, 0x2, 0x2, 0x2, 0x4c0, 
    0x495, 0x3, 0x2, 0x2, 0x2, 0x4c0, 0x498, 0x3, 0x2, 0x2, 0x2, 0x4c0, 
    0x49e, 0x3, 0x2, 0x2, 0x2, 0x4c0, 0x4a1, 0x3, 0x2, 0x2, 0x2, 0x4c0, 
    0x4b0, 0x3, 0x2, 0x2, 0x2, 0x4c0, 0x4b5, 0x3, 0x2, 0x2, 0x2, 0x4c0, 
    0x4b7, 0x3, 0x2, 0x2, 0x2, 0x4c0, 0x4ba, 0x3, 0x2, 0x2, 0x2, 0x4c1, 
    0x4c4, 0x3, 0x2, 0x2, 0x2, 0x4c2, 0x4c0, 0x3, 0x2, 0x2, 0x2, 0x4c2, 
    0x4c3, 0x3, 0x2, 0x2, 0x2, 0x4c3, 0xa9, 0x3, 0x2, 0x2, 0x2, 0x4c4, 0x4c2, 
    0x3, 0x2, 0x2, 0x2, 0x4c5, 0x4c6, 0x5, 0xac, 0x57, 0x2, 0x4c6, 0x4c7, 
    0x7, 0x6a, 0x2, 0x2, 0x4c7, 0x4c8, 0x5, 0xae, 0x58, 0x2, 0x4c8, 0xab, 
    0x3, 0x2, 0x2, 0x2, 0x4c9, 0x4da, 0x7, 0x71, 0x2, 0x2, 0x4ca, 0x4cc, 
    0x7, 0x3f, 0x2, 0x2, 0x4cb, 0x4cd, 0x5, 0x58, 0x2d, 0x2, 0x4cc, 0x4cb, 
    0x3, 0x2, 0x2, 0x2, 0x4cc, 0x4cd, 0x3, 0x2, 0x2, 0x2, 0x4cd, 0x4ce, 
    0x3, 0x2, 0x2, 0x2, 0x4ce, 0x4da, 0x7, 0x40, 0x2, 0x2, 0x4cf, 0x4d0, 
    0x7, 0x3f, 0x2, 0x2, 0x4d0, 0x4d5, 0x7, 0x71, 0x2, 0x2, 0x4d1, 0x4d2, 
    0x7, 0x46, 0x2, 0x2, 0x4d2, 0x4d4, 0x7, 0x71, 0x2, 0x2, 0x4d3, 0x4d1, 
    0x3, 0x2, 0x2, 0x2, 0x4d4, 0x4d7, 0x3, 0x2, 0x2, 0x2, 0x4d5, 0x4d3, 
    0x3, 0x2, 0x2, 0x2, 0x4d5, 0x4d6, 0x3, 0x2, 0x2, 0x2, 0x4d6, 0x4d8, 
    0x3, 0x2, 0x2, 0x2, 0x4d7, 0x4d5, 0x3, 0x2, 0x2, 0x2, 0x4d8, 0x4da, 
    0x7, 0x40, 0x2, 0x2, 0x4d9, 0x4c9, 0x3, 0x2, 0x2, 0x2, 0x4d9, 0x4ca, 
    0x3, 0x2, 0x2, 0x2, 0x4d9, 0x4cf, 0x3, 0x2, 0x2, 0x2, 0x4da, 0xad, 0x3, 
    0x2, 0x2, 0x2, 0x4db, 0x4de, 0x5, 0xa8, 0x55, 0x2, 0x4dc, 0x4de, 0x5, 
    0x82, 0x42, 0x2, 0x4dd, 0x4db, 0x3, 0x2, 0x2, 0x2, 0x4dd, 0x4dc, 0x3, 
    0x2, 0x2, 0x2, 0x4de, 0xaf, 0x3, 0x2, 0x2, 0x2, 0x4df, 0x4e0, 0x7, 0x3f, 
    0x2, 0x2, 0x4e0, 0x4e1, 0x5, 0xa8, 0x55, 0x2, 0x4e1, 0x4e2, 0x7, 0x40, 
    0x2, 0x2, 0x4e2, 0x4f2, 0x3, 0x2, 0x2, 0x2, 0x4e3, 0x4f2, 0x7, 0x2d, 
    0x2, 0x2, 0x4e4, 0x4f2, 0x7, 0x2a, 0x2, 0x2, 0x4e5, 0x4f2, 0x5, 0x60, 
    0x31, 0x2, 0x4e6, 0x4f2, 0x7, 0x71, 0x2, 0x2, 0x4e7, 0x4e8, 0x5, 0x2e, 
    0x18, 0x2, 0x4e8, 0x4e9, 0x7, 0x47, 0x2, 0x2, 0x4e9, 0x4ea, 0x7, 0xb, 
    0x2, 0x2, 0x4ea, 0x4f2, 0x3, 0x2, 0x2, 0x2, 0x4eb, 0x4ef, 0x5, 0xc4, 
    0x63, 0x2, 0x4ec, 0x4f0, 0x5, 0xd0, 0x69, 0x2, 0x4ed, 0x4ee, 0x7, 0x2d, 
    0x2, 0x2, 0x4ee, 0x4f0, 0x5, 0xd2, 0x6a, 0x2, 0x4ef, 0x4ec, 0x3, 0x2, 
    0x2, 0x2, 0x4ef, 0x4ed, 0x3, 0x2, 0x2, 0x2, 0x4f0, 0x4f2, 0x3, 0x2, 
    0x2, 0x2, 0x4f1, 0x4df, 0x3, 0x2, 0x2, 0x2, 0x4f1, 0x4e3, 0x3, 0x2, 
    0x2, 0x2, 0x4f1, 0x4e4, 0x3, 0x2, 0x2, 0x2, 0x4f1, 0x4e5, 0x3, 0x2, 
    0x2, 0x2, 0x4f1, 0x4e6, 0x3, 0x2, 0x2, 0x2, 0x4f1, 0x4e7, 0x3, 0x2, 
    0x2, 0x2, 0x4f1, 0x4eb, 0x3, 0x2, 0x2, 0x2, 0x4f2, 0xb1, 0x3, 0x2, 0x2, 
    0x2, 0x4f3, 0x4f4, 0x5, 0x50, 0x29, 0x2, 0x4f4, 0x4f5, 0x7, 0x47, 0x2, 
    0x2, 0x4f5, 0x4f7, 0x3, 0x2, 0x2, 0x2, 0x4f6, 0x4f3, 0x3, 0x2, 0x2, 
    0x2, 0x4f6, 0x4f7, 0x3, 0x2, 0x2, 0x2, 0x4f7, 0x4fb, 0x3, 0x2, 0x2, 
    0x2, 0x4f8, 0x4fa, 0x5, 0x68, 0x35, 0x2, 0x4f9, 0x4f8, 0x3, 0x2, 0x2, 
    0x2, 0x4fa, 0x4fd, 0x3, 0x2, 0x2, 0x2, 0x4fb, 0x4f9, 0x3, 0x2, 0x2, 
    0x2, 0x4fb, 0x4fc, 0x3, 0x2, 0x2, 0x2, 0x4fc, 0x4fe, 0x3, 0x2, 0x2, 
    0x2, 0x4fd, 0x4fb, 0x3, 0x2, 0x2, 0x2, 0x4fe, 0x500, 0x7, 0x71, 0x2, 
    0x2, 0x4ff, 0x501, 0x5, 0xcc, 0x67, 0x2, 0x500, 0x4ff, 0x3, 0x2, 0x2, 
    0x2, 0x500, 0x501, 0x3, 0x2, 0x2, 0x2, 0x501, 0xb3, 0x3, 0x2, 0x2, 0x2, 
    0x502, 0x503, 0x5, 0xc4, 0x63, 0x2, 0x503, 0x504, 0x5, 0xb6, 0x5c, 0x2, 
    0x504, 0x505, 0x5, 0xbc, 0x5f, 0x2, 0x505, 0x50c, 0x3, 0x2, 0x2, 0x2, 
    0x506, 0x509, 0x5, 0xb6, 0x5c, 0x2, 0x507, 0x50a, 0x5, 0xba, 0x5e, 0x2, 
    0x508, 0x50a, 0x5, 0xbc, 0x5f, 0x2, 0x509, 0x507, 0x3, 0x2, 0x2, 0x2, 
    0x509, 0x508, 0x3, 0x2, 0x2, 0x2, 0x50a, 0x50c, 0x3, 0x2, 0x2, 0x2, 
    0x50b, 0x502, 0x3, 0x2, 0x2, 0x2, 0x50b, 0x506, 0x3, 0x2, 0x2, 0x2, 
    0x50c, 0xb5, 0x3, 0x2, 0x2, 0x2, 0x50d, 0x50f, 0x7, 0x71, 0x2, 0x2, 
    0x50e, 0x510, 0x5, 0xc0, 0x61, 0x2, 0x50f, 0x50e, 0x3, 0x2, 0x2, 0x2, 
    0x50f, 0x510, 0x3, 0x2, 0x2, 0x2, 0x510, 0x518, 0x3, 0x2, 0x2, 0x2, 
    0x511, 0x512, 0x7, 0x47, 0x2, 0x2, 0x512, 0x514, 0x7, 0x71, 0x2, 0x2, 
    0x513, 0x515, 0x5, 0xc0, 0x61, 0x2, 0x514, 0x513, 0x3, 0x2, 0x2, 0x2, 
    0x514, 0x515, 0x3, 0x2, 0x2, 0x2, 0x515, 0x517, 0x3, 0x2, 0x2, 0x2, 
    0x516, 0x511, 0x3, 0x2, 0x2, 0x2, 0x517, 0x51a, 0x3, 0x2, 0x2, 0x2, 
    0x518, 0x516, 0x3, 0x2, 0x2, 0x2, 0x518, 0x519, 0x3, 0x2, 0x2, 0x2, 
    0x519, 0x51d, 0x3, 0x2, 0x2, 0x2, 0x51a, 0x518, 0x3, 0x2, 0x2, 0x2, 
    0x51b, 0x51d, 0x5, 0xca, 0x66, 0x2, 0x51c, 0x50d, 0x3, 0x2, 0x2, 0x2, 
    0x51c, 0x51b, 0x3, 0x2, 0x2, 0x2, 0x51d, 0xb7, 0x3, 0x2, 0x2, 0x2, 0x51e, 
    0x520, 0x7, 0x71, 0x2, 0x2, 0x51f, 0x521, 0x5, 0xc2, 0x62, 0x2, 0x520, 
    0x51f, 0x3, 0x2, 0x2, 0x2, 0x520, 0x521, 0x3, 0x2, 0x2, 0x2, 0x521, 
    0x522, 0x3, 0x2, 0x2, 0x2, 0x522, 0x523, 0x5, 0xbc, 0x5f, 0x2, 0x523, 
    0xb9, 0x3, 0x2, 0x2, 0x2, 0x524, 0x540, 0x7, 0x43, 0x2, 0x2, 0x525, 
    0x52a, 0x7, 0x44, 0x2, 0x2, 0x526, 0x527, 0x7, 0x43, 0x2, 0x2, 0x527, 
    0x529, 0x7, 0x44, 0x2, 0x2, 0x528, 0x526, 0x3, 0x2, 0x2, 0x2, 0x529, 
    0x52c, 0x3, 0x2, 0x2, 0x2, 0x52a, 0x528, 0x3, 0x2, 0x2, 0x2, 0x52a, 
    0x52b, 0x3, 0x2, 0x2, 0x2, 0x52b, 0x52d, 0x3, 0x2, 0x2, 0x2, 0x52c, 
    0x52a, 0x3, 0x2, 0x2, 0x2, 0x52d, 0x541, 0x5, 0x4e, 0x28, 0x2, 0x52e, 
    0x52f, 0x5, 0xa8, 0x55, 0x2, 0x52f, 0x536, 0x7, 0x44, 0x2, 0x2, 0x530, 
    0x531, 0x7, 0x43, 0x2, 0x2, 0x531, 0x532, 0x5, 0xa8, 0x55, 0x2, 0x532, 
    0x533, 0x7, 0x44, 0x2, 0x2, 0x533, 0x535, 0x3, 0x2, 0x2, 0x2, 0x534, 
    0x530, 0x3, 0x2, 0x2, 0x2, 0x535, 0x538, 0x3, 0x2, 0x2, 0x2, 0x536, 
    0x534, 0x3, 0x2, 0x2, 0x2, 0x536, 0x537, 0x3, 0x2, 0x2, 0x2, 0x537, 
    0x53d, 0x3, 0x2, 0x2, 0x2, 0x538, 0x536, 0x3, 0x2, 0x2, 0x2, 0x539, 
    0x53a, 0x7, 0x43, 0x2, 0x2, 0x53a, 0x53c, 0x7, 0x44, 0x2, 0x2, 0x53b, 
    0x539, 0x3, 0x2, 0x2, 0x2, 0x53c, 0x53f, 0x3, 0x2, 0x2, 0x2, 0x53d, 
    0x53b, 0x3, 0x2, 0x2, 0x2, 0x53d, 0x53e, 0x3, 0x2, 0x2, 0x2, 0x53e, 
    0x541, 0x3, 0x2, 0x2, 0x2, 0x53f, 0x53d, 0x3, 0x2, 0x2, 0x2, 0x540, 
    0x525, 0x3, 0x2, 0x2, 0x2, 0x540, 0x52e, 0x3, 0x2, 0x2, 0x2, 0x541, 
    0xbb, 0x3, 0x2, 0x2, 0x2, 0x542, 0x544, 0x5, 0xd2, 0x6a, 0x2, 0x543, 
    0x545, 0x5, 0x22, 0x12, 0x2, 0x544, 0x543, 0x3, 0x2, 0x2, 0x2, 0x544, 
    0x545, 0x3, 0x2, 0x2, 0x2, 0x545, 0xbd, 0x3, 0x2, 0x2, 0x2, 0x546, 0x547, 
    0x5, 0xc4, 0x63, 0x2, 0x547, 0x548, 0x5, 0xd0, 0x69, 0x2, 0x548, 0xbf, 
    0x3, 0x2, 0x2, 0x2, 0x549, 0x54a, 0x7, 0x4a, 0x2, 0x2, 0x54a, 0x54d, 
    0x7, 0x49, 0x2, 0x2, 0x54b, 0x54d, 0x5, 0xcc, 0x67, 0x2, 0x54c, 0x549, 
    0x3, 0x2, 0x2, 0x2, 0x54c, 0x54b, 0x3, 0x2, 0x2, 0x2, 0x54d, 0xc1, 0x3, 
    0x2, 0x2, 0x2, 0x54e, 0x54f, 0x7, 0x4a, 0x2, 0x2, 0x54f, 0x552, 0x7, 
    0x49, 0x2, 0x2, 0x550, 0x552, 0x5, 0xc4, 0x63, 0x2, 0x551, 0x54e, 0x3, 
    0x2, 0x2, 0x2, 0x551, 0x550, 0x3, 0x2, 0x2, 0x2, 0x552, 0xc3, 0x3, 0x2, 
    0x2, 0x2, 0x553, 0x554, 0x7, 0x4a, 0x2, 0x2, 0x554, 0x555, 0x5, 0xc6, 
    0x64, 0x2, 0x555, 0x556, 0x7, 0x49, 0x2, 0x2, 0x556, 0xc5, 0x3, 0x2, 
    0x2, 0x2, 0x557, 0x55c, 0x5, 0xc8, 0x65, 0x2, 0x558, 0x559, 0x7, 0x46, 
    0x2, 0x2, 0x559, 0x55b, 0x5, 0xc8, 0x65, 0x2, 0x55a, 0x558, 0x3, 0x2, 
    0x2, 0x2, 0x55b, 0x55e, 0x3, 0x2, 0x2, 0x2, 0x55c, 0x55a, 0x3, 0x2, 
    0x2, 0x2, 0x55c, 0x55d, 0x3, 0x2, 0x2, 0x2, 0x55d, 0xc7, 0x3, 0x2, 0x2, 
    0x2, 0x55e, 0x55c, 0x3, 0x2, 0x2, 0x2, 0x55f, 0x561, 0x5, 0x68, 0x35, 
    0x2, 0x560, 0x55f, 0x3, 0x2, 0x2, 0x2, 0x561, 0x564, 0x3, 0x2, 0x2, 
    0x2, 0x562, 0x560, 0x3, 0x2, 0x2, 0x2, 0x562, 0x563, 0x3, 0x2, 0x2, 
    0x2, 0x563, 0x567, 0x3, 0x2, 0x2, 0x2, 0x564, 0x562, 0x3, 0x2, 0x2, 
    0x2, 0x565, 0x568, 0x5, 0x50, 0x29, 0x2, 0x566, 0x568, 0x5, 0xca, 0x66, 
    0x2, 0x567, 0x565, 0x3, 0x2, 0x2, 0x2, 0x567, 0x566, 0x3, 0x2, 0x2, 
    0x2, 0x568, 0x573, 0x3, 0x2, 0x2, 0x2, 0x569, 0x56b, 0x5, 0x68, 0x35, 
    0x2, 0x56a, 0x569, 0x3, 0x2, 0x2, 0x2, 0x56b, 0x56e, 0x3, 0x2, 0x2, 
    0x2, 0x56c, 0x56a, 0x3, 0x2, 0x2, 0x2, 0x56c, 0x56d, 0x3, 0x2, 0x2, 
    0x2, 0x56d, 0x56f, 0x3, 0x2, 0x2, 0x2, 0x56e, 0x56c, 0x3, 0x2, 0x2, 
    0x2, 0x56f, 0x570, 0x7, 0x43, 0x2, 0x2, 0x570, 0x572, 0x7, 0x44, 0x2, 
    0x2, 0x571, 0x56c, 0x3, 0x2, 0x2, 0x2, 0x572, 0x575, 0x3, 0x2, 0x2, 
    0x2, 0x573, 0x571, 0x3, 0x2, 0x2, 0x2, 0x573, 0x574, 0x3, 0x2, 0x2, 
    0x2, 0x574, 0xc9, 0x3, 0x2, 0x2, 0x2, 0x575, 0x573, 0x3, 0x2, 0x2, 0x2, 
    0x576, 0x577, 0x9, 0xd, 0x2, 0x2, 0x577, 0xcb, 0x3, 0x2, 0x2, 0x2, 0x578, 
    0x579, 0x7, 0x4a, 0x2, 0x2, 0x579, 0x57e, 0x5, 0x52, 0x2a, 0x2, 0x57a, 
    0x57b, 0x7, 0x46, 0x2, 0x2, 0x57b, 0x57d, 0x5, 0x52, 0x2a, 0x2, 0x57c, 
    0x57a, 0x3, 0x2, 0x2, 0x2, 0x57d, 0x580, 0x3, 0x2, 0x2, 0x2, 0x57e, 
    0x57c, 0x3, 0x2, 0x2, 0x2, 0x57e, 0x57f, 0x3, 0x2, 0x2, 0x2, 0x57f, 
    0x581, 0x3, 0x2, 0x2, 0x2, 0x580, 0x57e, 0x3, 0x2, 0x2, 0x2, 0x581, 
    0x582, 0x7, 0x49, 0x2, 0x2, 0x582, 0xcd, 0x3, 0x2, 0x2, 0x2, 0x583, 
    0x58a, 0x5, 0xd2, 0x6a, 0x2, 0x584, 0x585, 0x7, 0x47, 0x2, 0x2, 0x585, 
    0x587, 0x7, 0x71, 0x2, 0x2, 0x586, 0x588, 0x5, 0xd2, 0x6a, 0x2, 0x587, 
    0x586, 0x3, 0x2, 0x2, 0x2, 0x587, 0x588, 0x3, 0x2, 0x2, 0x2, 0x588, 
    0x58a, 0x3, 0x2, 0x2, 0x2, 0x589, 0x583, 0x3, 0x2, 0x2, 0x2, 0x589, 
    0x584, 0x3, 0x2, 0x2, 0x2, 0x58a, 0xcf, 0x3, 0x2, 0x2, 0x2, 0x58b, 0x58c, 
    0x7, 0x2a, 0x2, 0x2, 0x58c, 0x590, 0x5, 0xce, 0x68, 0x2, 0x58d, 0x58e, 
    0x7, 0x71, 0x2, 0x2, 0x58e, 0x590, 0x5, 0xd2, 0x6a, 0x2, 0x58f, 0x58b, 
    0x3, 0x2, 0x2, 0x2, 0x58f, 0x58d, 0x3, 0x2, 0x2, 0x2, 0x590, 0xd1, 0x3, 
    0x2, 0x2, 0x2, 0x591, 0x593, 0x7, 0x3f, 0x2, 0x2, 0x592, 0x594, 0x5, 
    0xa4, 0x53, 0x2, 0x593, 0x592, 0x3, 0x2, 0x2, 0x2, 0x593, 0x594, 0x3, 
    0x2, 0x2, 0x2, 0x594, 0x595, 0x3, 0x2, 0x2, 0x2, 0x595, 0x596, 0x7, 
    0x40, 0x2, 0x2, 0x596, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xd5, 0xda, 0xe0, 
    0xe8, 0xf1, 0xf6, 0xfd, 0x104, 0x107, 0x10e, 0x118, 0x11c, 0x121, 0x125, 
    0x129, 0x133, 0x13b, 0x143, 0x147, 0x14e, 0x155, 0x159, 0x15c, 0x15f, 
    0x168, 0x16e, 0x173, 0x176, 0x17c, 0x182, 0x186, 0x18e, 0x197, 0x19e, 
    0x1a4, 0x1a8, 0x1b3, 0x1bc, 0x1c1, 0x1c7, 0x1cb, 0x1d7, 0x1e2, 0x1e7, 
    0x1f0, 0x1f8, 0x202, 0x20b, 0x213, 0x218, 0x220, 0x225, 0x22f, 0x239, 
    0x23f, 0x246, 0x24b, 0x253, 0x257, 0x259, 0x25f, 0x264, 0x268, 0x26f, 
    0x275, 0x277, 0x27e, 0x283, 0x28c, 0x291, 0x294, 0x299, 0x2a2, 0x2a9, 
    0x2b4, 0x2bd, 0x2c7, 0x2d0, 0x2d5, 0x2d8, 0x2df, 0x2e9, 0x2f1, 0x2f4, 
    0x2f7, 0x304, 0x30c, 0x311, 0x319, 0x31d, 0x321, 0x325, 0x327, 0x32b, 
    0x331, 0x33c, 0x346, 0x34b, 0x354, 0x359, 0x35c, 0x363, 0x36c, 0x383, 
    0x386, 0x389, 0x391, 0x395, 0x39d, 0x3a3, 0x3ae, 0x3b7, 0x3bc, 0x3c6, 
    0x3cd, 0x3da, 0x3e3, 0x3ec, 0x3f2, 0x3fd, 0x402, 0x407, 0x40c, 0x410, 
    0x414, 0x418, 0x41a, 0x41e, 0x423, 0x434, 0x43a, 0x440, 0x446, 0x449, 
    0x454, 0x463, 0x467, 0x46c, 0x470, 0x480, 0x4a8, 0x4ae, 0x4bd, 0x4c0, 
    0x4c2, 0x4cc, 0x4d5, 0x4d9, 0x4dd, 0x4ef, 0x4f1, 0x4f6, 0x4fb, 0x500, 
    0x509, 0x50b, 0x50f, 0x514, 0x518, 0x51c, 0x520, 0x52a, 0x536, 0x53d, 
    0x540, 0x544, 0x54c, 0x551, 0x55c, 0x562, 0x567, 0x56c, 0x573, 0x57e, 
    0x587, 0x589, 0x58f, 0x593, 
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
