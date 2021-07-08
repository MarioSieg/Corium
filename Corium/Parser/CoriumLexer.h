
// Generated from Corium.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"




class  CoriumLexer : public antlr4::Lexer {
public:
  enum {
    BOOL = 1, CHAR = 2, FLOAT = 3, FUN = 4, INT = 5, LET = 6, NATIVE = 7, 
    CONST = 8, INT_LITERAL_DEC = 9, INT_LITERAL_HEX = 10, INT_LITERAL_OCT = 11, 
    INT_LITERAL_BIN = 12, FLOAT_LITERAL_DEC = 13, FLOAT_LITERAL_HEX = 14, 
    BOOL_LITERAL = 15, CHAR_LITERAL = 16, STRING_LITERAL = 17, LPAREN = 18, 
    RPAREN = 19, LBRACE = 20, RBRACE = 21, LBRACK = 22, RBRACK = 23, SEMI = 24, 
    COMMA = 25, DOT = 26, ASSIGN = 27, IDENT = 28, SINGLE_LINE_COMMENT = 29, 
    MULTI_LINE_COMMENT = 30, NEW_LINE = 31, WHITESPACE = 32
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

