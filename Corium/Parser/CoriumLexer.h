
// Generated from CoriumLexer.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  CoriumLexer : public antlr4::Lexer {
public:
  enum {
    LET = 1, FUN = 2, INT_LITERAL_DEC = 3, INT_LITERAL_HEX = 4, INT_LITERAL_OCT = 5, 
    INT_LITERAL_BIN = 6, FLOAT_LITERAL_DEC = 7, FLOAT_LITERAL_HEX = 8, BOOL_LITERAL = 9, 
    CHAR_LITERAL = 10, STRING_LITERAL = 11, LPAREN = 12, RPAREN = 13, LBRACE = 14, 
    RBRACE = 15, LBRACK = 16, RBRACK = 17, SEMI = 18, COMMA = 19, DOT = 20, 
    IDENT = 21, WHITESPACE = 22, SINGLE_LINE_COMMENT = 23, MULTI_LINE_COMMENT = 24
  };

  CoriumLexer(antlr4::CharStream *input);
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

