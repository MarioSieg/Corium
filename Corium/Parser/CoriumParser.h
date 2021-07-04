
// Generated from CoriumParser.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  CoriumParser : public antlr4::Parser {
public:
  enum {
    BOOL = 1, CHAR = 2, FLOAT = 3, FUN = 4, INT = 5, LET = 6, INT_LITERAL_DEC = 7, 
    INT_LITERAL_HEX = 8, INT_LITERAL_OCT = 9, INT_LITERAL_BIN = 10, FLOAT_LITERAL_DEC = 11, 
    FLOAT_LITERAL_HEX = 12, BOOL_LITERAL = 13, CHAR_LITERAL = 14, STRING_LITERAL = 15, 
    LPAREN = 16, RPAREN = 17, LBRACE = 18, RBRACE = 19, LBRACK = 20, RBRACK = 21, 
    SEMI = 22, COMMA = 23, DOT = 24, ASSIGN = 25, IDENT = 26, WHITESPACE = 27, 
    SINGLE_LINE_COMMENT = 28, MULTI_LINE_COMMENT = 29
  };

  enum {
    RuleLocalVariableDeclaration = 0, RuleLiteral = 1, RuleIntLiteral = 2, 
    RuleFloatLiteral = 3, RulePrimitiveType = 4
  };

  CoriumParser(antlr4::TokenStream *input);
  ~CoriumParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class LocalVariableDeclarationContext;
  class LiteralContext;
  class IntLiteralContext;
  class FloatLiteralContext;
  class PrimitiveTypeContext; 

  class  LocalVariableDeclarationContext : public antlr4::ParserRuleContext {
  public:
    LocalVariableDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LET();
    antlr4::tree::TerminalNode *WHITESPACE();
    antlr4::tree::TerminalNode *IDENT();
    antlr4::tree::TerminalNode *ASSIGN();
    LiteralContext *literal();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LocalVariableDeclarationContext* localVariableDeclaration();

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

