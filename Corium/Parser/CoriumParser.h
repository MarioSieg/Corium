
// Generated from Corium.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"




class  CoriumParser : public antlr4::Parser {
public:
  enum {
    BOOL = 1, CHAR = 2, FLOAT = 3, FUN = 4, INT = 5, LET = 6, NATIVE = 7, 
    CONST = 8, INT_LITERAL_DEC = 9, INT_LITERAL_HEX = 10, INT_LITERAL_OCT = 11, 
    INT_LITERAL_BIN = 12, FLOAT_LITERAL_DEC = 13, FLOAT_LITERAL_HEX = 14, 
    BOOL_LITERAL = 15, CHAR_LITERAL = 16, STRING_LITERAL = 17, LPAREN = 18, 
    RPAREN = 19, LBRACE = 20, RBRACE = 21, LBRACK = 22, RBRACK = 23, SEMI = 24, 
    COMMA = 25, DOT = 26, ASSIGN = 27, IDENT = 28, SINGLE_SPACE = 29, WHITESPACE = 30, 
    SINGLE_LINE_COMMENT = 31, MULTI_LINE_COMMENT = 32
  };

  enum {
    RuleVariableDeclaration = 0, RuleLocalVariableDeclaration = 1, RuleConstVariableDeclaration = 2, 
    RuleLiteral = 3, RulePrimitiveType = 4
  };

  explicit CoriumParser(antlr4::TokenStream *input);
  ~CoriumParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class VariableDeclarationContext;
  class LocalVariableDeclarationContext;
  class ConstVariableDeclarationContext;
  class LiteralContext;
  class PrimitiveTypeContext; 

  class  VariableDeclarationContext : public antlr4::ParserRuleContext {
  public:
    VariableDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> SINGLE_SPACE();
    antlr4::tree::TerminalNode* SINGLE_SPACE(size_t i);
    antlr4::tree::TerminalNode *IDENT();
    antlr4::tree::TerminalNode *ASSIGN();
    LiteralContext *literal();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VariableDeclarationContext* variableDeclaration();

  class  LocalVariableDeclarationContext : public antlr4::ParserRuleContext {
  public:
    LocalVariableDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LET();
    VariableDeclarationContext *variableDeclaration();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LocalVariableDeclarationContext* localVariableDeclaration();

  class  ConstVariableDeclarationContext : public antlr4::ParserRuleContext {
  public:
    ConstVariableDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONST();
    VariableDeclarationContext *variableDeclaration();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ConstVariableDeclarationContext* constVariableDeclaration();

  class  LiteralContext : public antlr4::ParserRuleContext {
  public:
    LiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT_LITERAL_DEC();
    antlr4::tree::TerminalNode *INT_LITERAL_HEX();
    antlr4::tree::TerminalNode *INT_LITERAL_OCT();
    antlr4::tree::TerminalNode *INT_LITERAL_BIN();
    antlr4::tree::TerminalNode *FLOAT_LITERAL_DEC();
    antlr4::tree::TerminalNode *FLOAT_LITERAL_HEX();
    antlr4::tree::TerminalNode *BOOL_LITERAL();
    antlr4::tree::TerminalNode *CHAR_LITERAL();
    antlr4::tree::TerminalNode *STRING_LITERAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LiteralContext* literal();

  class  PrimitiveTypeContext : public antlr4::ParserRuleContext {
  public:
    PrimitiveTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *CHAR();
    antlr4::tree::TerminalNode *BOOL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PrimitiveTypeContext* primitiveType();


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

