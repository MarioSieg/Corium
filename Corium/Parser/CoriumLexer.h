
// Generated from Corium.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  CoriumLexer : public antlr4::Lexer {
public:
  enum {
    BOOL = 1, CHAR = 2, FLOAT = 3, FUN = 4, INT = 5, STRING = 6, LET = 7, 
    NATIVE = 8, CONST = 9, MODULE = 10, CLASS = 11, STRUCT = 12, RETURN = 13, 
    SELF = 14, SELF_TYPE = 15, INT_LITERAL_DEC = 16, INT_LITERAL_HEX = 17, 
    INT_LITERAL_OCT = 18, INT_LITERAL_BIN = 19, FLOAT_LITERAL_DEC = 20, 
    FLOAT_LITERAL_HEX = 21, BOOL_LITERAL = 22, CHAR_LITERAL = 23, STRING_LITERAL = 24, 
    LPAREN = 25, RPAREN = 26, LBRACE = 27, RBRACE = 28, LBRACK = 29, RBRACK = 30, 
    SEMI = 31, COMMA = 32, DOT = 33, ASSIGN = 34, PLUS = 35, PLUS_ASSIGN = 36, 
    MINUS = 37, MINUS_ASSIGN = 38, MULTIPLY = 39, MULTIPLY_ASSIGN = 40, 
    DIVIDE = 41, DIVIDE_ASSIGN = 42, MODULO = 43, MODULO_ASSIGN = 44, BIT_AND = 45, 
    BIT_AND_ASSIGN = 46, BIT_OR = 47, BIT_OR_ASSIGN = 48, BIT_XOR = 49, 
    BIT_XOR_ASSIGN = 50, BIT_NOT = 51, BIT_SHL = 52, BIT_SHL_ASSIGN = 53, 
    BIT_SHR = 54, BIT_SHR_ASSIGN = 55, BIT_USHL = 56, BIT_USHL_ASSIGN = 57, 
    BIT_USHR = 58, BIT_USHR_ASSIGN = 59, BIT_ROL = 60, BIT_ROL_ASSIGN = 61, 
    BIT_ROR = 62, BIT_ROR_ASSIGN = 63, INCREMENT = 64, DECREMENT = 65, LOGICAL_NOT = 66, 
    LOGICAL_AND = 67, LOGICAL_OR = 68, LOGICAL_XOR = 69, EQUALS = 70, NOT_EQUALS = 71, 
    LESS = 72, LESS_EQUALS = 73, GREATER = 74, GREATER_EQUALS = 75, IDENT = 76, 
    SPACE = 77, SINGLE_LINE_COMMENT = 78, MULTI_LINE_COMMENT = 79
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

