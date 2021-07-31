
// Generated from Corium.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  CoriumLexer : public antlr4::Lexer {
public:
  enum {
    BOOL = 1, CHAR = 2, FLOAT = 3, INT = 4, VAR = 5, MODULE = 6, INT_LITERAL_DEC = 7, 
    INT_LITERAL_HEX = 8, INT_LITERAL_OCT = 9, INT_LITERAL_BIN = 10, FLOAT_LITERAL_DEC = 11, 
    FLOAT_LITERAL_HEX = 12, BOOL_LITERAL = 13, CHAR_LITERAL = 14, STRING_LITERAL = 15, 
    LPAREN = 16, RPAREN = 17, LBRACE = 18, RBRACE = 19, LBRACK = 20, RBRACK = 21, 
    SEMI = 22, COMMA = 23, DOT = 24, ASSIGN = 25, ADD = 26, SUB = 27, MUL = 28, 
    DIV = 29, MOD = 30, IDENT = 31, SPACE = 32, SINGLE_LINE_COMMENT = 33, 
    MULTI_LINE_COMMENT = 34
  };

  explicit CoriumLexer(antlr4::CharStream *input);
  ~CoriumLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

