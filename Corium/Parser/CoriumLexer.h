
// Generated from Corium.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  CoriumLexer : public antlr4::Lexer {
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

