
// Generated from Corium.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  CoriumLexer : public antlr4::Lexer {
public:
  enum {
    BOOL = 1, CHAR = 2, FLOAT = 3, FUN = 4, INT = 5, STRING = 6, LET = 7, 
    NATIVE = 8, CONST = 9, MODULE = 10, CLASS = 11, STRUCT = 12, STATIC = 13, 
    RETURN = 14, INT_LITERAL_DEC = 15, INT_LITERAL_HEX = 16, INT_LITERAL_OCT = 17, 
    INT_LITERAL_BIN = 18, FLOAT_LITERAL_DEC = 19, FLOAT_LITERAL_HEX = 20, 
    BOOL_LITERAL = 21, CHAR_LITERAL = 22, STRING_LITERAL = 23, LPAREN = 24, 
    RPAREN = 25, LBRACE = 26, RBRACE = 27, LBRACK = 28, RBRACK = 29, SEMI = 30, 
    COMMA = 31, DOT = 32, ASSIGN = 33, PLUS = 34, PLUS_ASSIGN = 35, MINUS = 36, 
    MINUS_ASSIGN = 37, MULTIPLY = 38, MULTIPLY_ASSIGN = 39, DIVIDE = 40, 
    DIVIDE_ASSIGN = 41, MODULO = 42, MODULO_ASSIGN = 43, BIT_AND = 44, BIT_AND_ASSIGN = 45, 
    BIT_OR = 46, BIT_OR_ASSIGN = 47, BIT_XOR = 48, BIT_XOR_ASSIGN = 49, 
    BIT_NOT = 50, BIT_SHL = 51, BIT_SHL_ASSIGN = 52, BIT_SHR = 53, BIT_SHR_ASSIGN = 54, 
    BIT_ROL = 55, BIT_ROL_ASSIGN = 56, BIT_ROR = 57, BIT_ROR_ASSIGN = 58, 
    INCREMENT = 59, DECREMENT = 60, LOGICAL_NOT = 61, LOGICAL_AND = 62, 
    LOGICAL_OR = 63, LOGICAL_XOR = 64, EQUALS = 65, NOT_EQUALS = 66, LESS = 67, 
    LESS_EQUALS = 68, GREATER = 69, GREATER_EQUALS = 70, IDENT = 71, SPACE = 72, 
    SINGLE_LINE_COMMENT = 73, MULTI_LINE_COMMENT = 74
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

