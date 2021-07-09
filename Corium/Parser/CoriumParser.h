
// Generated from Corium.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"




class  CoriumParser : public antlr4::Parser {
public:
  enum {
    BOOL = 1, CHAR = 2, FLOAT = 3, FUN = 4, INT = 5, STRING = 6, LET = 7, 
    NATIVE = 8, CONST = 9, MODULE = 10, CLASS = 11, STRUCT = 12, STATIC = 13, 
    INT_LITERAL_DEC = 14, INT_LITERAL_HEX = 15, INT_LITERAL_OCT = 16, INT_LITERAL_BIN = 17, 
    FLOAT_LITERAL_DEC = 18, FLOAT_LITERAL_HEX = 19, BOOL_LITERAL = 20, CHAR_LITERAL = 21, 
    STRING_LITERAL = 22, LPAREN = 23, RPAREN = 24, LBRACE = 25, RBRACE = 26, 
    LBRACK = 27, RBRACK = 28, SEMI = 29, COMMA = 30, DOT = 31, ASSIGN = 32, 
    IDENT = 33, SPACE = 34, SINGLE_LINE_COMMENT = 35, MULTI_LINE_COMMENT = 36
  };

  enum {
    RuleCompilationUnit = 0, RuleModuleDeclaration = 1, RuleCompilationUnitStatement = 2, 
    RuleNativeFunctionDeclaration = 3, RuleFunctionDeclaration = 4, RuleFunctionBlockStatement = 5, 
    RuleLocalVariableDeclaration = 6, RuleConstVariableDeclaration = 7, 
    RuleParameterList = 8, RuleParameter = 9, RuleTypeName = 10, RuleBuiltinType = 11, 
    RuleQualifiedName = 12, RuleLiteral = 13, RuleIntLiteral = 14, RuleFloatLiteral = 15
  };

  explicit CoriumParser(antlr4::TokenStream *input);
  ~CoriumParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class CompilationUnitContext;
  class ModuleDeclarationContext;
  class CompilationUnitStatementContext;
  class NativeFunctionDeclarationContext;
  class FunctionDeclarationContext;
  class FunctionBlockStatementContext;
  class LocalVariableDeclarationContext;
  class ConstVariableDeclarationContext;
  class ParameterListContext;
  class ParameterContext;
  class TypeNameContext;
  class BuiltinTypeContext;
  class QualifiedNameContext;
  class LiteralContext;
  class IntLiteralContext;
  class FloatLiteralContext; 

  class  CompilationUnitContext : public antlr4::ParserRuleContext {
  public:
    CompilationUnitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ModuleDeclarationContext *moduleDeclaration();
    antlr4::tree::TerminalNode *EOF();
    std::vector<CompilationUnitStatementContext *> compilationUnitStatement();
    CompilationUnitStatementContext* compilationUnitStatement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  CompilationUnitContext* compilationUnit();

  class  ModuleDeclarationContext : public antlr4::ParserRuleContext {
  public:
    ModuleDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MODULE();
    QualifiedNameContext *qualifiedName();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ModuleDeclarationContext* moduleDeclaration();

  class  CompilationUnitStatementContext : public antlr4::ParserRuleContext {
  public:
    CompilationUnitStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FunctionDeclarationContext *functionDeclaration();
    NativeFunctionDeclarationContext *nativeFunctionDeclaration();
    ConstVariableDeclarationContext *constVariableDeclaration();
    antlr4::tree::TerminalNode *SPACE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  CompilationUnitStatementContext* compilationUnitStatement();

  class  NativeFunctionDeclarationContext : public antlr4::ParserRuleContext {
  public:
    NativeFunctionDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NATIVE();
    antlr4::tree::TerminalNode *FUN();
    antlr4::tree::TerminalNode *IDENT();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    ParameterListContext *parameterList();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  NativeFunctionDeclarationContext* nativeFunctionDeclaration();

  class  FunctionDeclarationContext : public antlr4::ParserRuleContext {
  public:
    FunctionDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FUN();
    antlr4::tree::TerminalNode *IDENT();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    ParameterListContext *parameterList();
    std::vector<FunctionBlockStatementContext *> functionBlockStatement();
    FunctionBlockStatementContext* functionBlockStatement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FunctionDeclarationContext* functionDeclaration();

  class  FunctionBlockStatementContext : public antlr4::ParserRuleContext {
  public:
    FunctionBlockStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LocalVariableDeclarationContext *localVariableDeclaration();
    ConstVariableDeclarationContext *constVariableDeclaration();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FunctionBlockStatementContext* functionBlockStatement();

  class  LocalVariableDeclarationContext : public antlr4::ParserRuleContext {
  public:
    LocalVariableDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LET();
    TypeNameContext *typeName();
    antlr4::tree::TerminalNode *ASSIGN();
    LiteralContext *literal();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LocalVariableDeclarationContext* localVariableDeclaration();

  class  ConstVariableDeclarationContext : public antlr4::ParserRuleContext {
  public:
    ConstVariableDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONST();
    TypeNameContext *typeName();
    antlr4::tree::TerminalNode *ASSIGN();
    LiteralContext *literal();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ConstVariableDeclarationContext* constVariableDeclaration();

  class  ParameterListContext : public antlr4::ParserRuleContext {
  public:
    ParameterListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ParameterContext *> parameter();
    ParameterContext* parameter(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ParameterListContext* parameterList();

  class  ParameterContext : public antlr4::ParserRuleContext {
  public:
    ParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENT();
    TypeNameContext *typeName();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ParameterContext* parameter();

  class  TypeNameContext : public antlr4::ParserRuleContext {
  public:
    TypeNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BuiltinTypeContext *builtinType();
    QualifiedNameContext *qualifiedName();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TypeNameContext* typeName();

  class  BuiltinTypeContext : public antlr4::ParserRuleContext {
  public:
    BuiltinTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *CHAR();
    antlr4::tree::TerminalNode *BOOL();
    antlr4::tree::TerminalNode *STRING();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BuiltinTypeContext* builtinType();

  class  QualifiedNameContext : public antlr4::ParserRuleContext {
  public:
    QualifiedNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IDENT();
    antlr4::tree::TerminalNode* IDENT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DOT();
    antlr4::tree::TerminalNode* DOT(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  QualifiedNameContext* qualifiedName();

  class  LiteralContext : public antlr4::ParserRuleContext {
  public:
    LiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IntLiteralContext *intLiteral();
    FloatLiteralContext *floatLiteral();
    antlr4::tree::TerminalNode *BOOL_LITERAL();
    antlr4::tree::TerminalNode *CHAR_LITERAL();
    antlr4::tree::TerminalNode *STRING_LITERAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LiteralContext* literal();

  class  IntLiteralContext : public antlr4::ParserRuleContext {
  public:
    IntLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT_LITERAL_DEC();
    antlr4::tree::TerminalNode *INT_LITERAL_HEX();
    antlr4::tree::TerminalNode *INT_LITERAL_OCT();
    antlr4::tree::TerminalNode *INT_LITERAL_BIN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  IntLiteralContext* intLiteral();

  class  FloatLiteralContext : public antlr4::ParserRuleContext {
  public:
    FloatLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FLOAT_LITERAL_DEC();
    antlr4::tree::TerminalNode *FLOAT_LITERAL_HEX();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FloatLiteralContext* floatLiteral();


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

