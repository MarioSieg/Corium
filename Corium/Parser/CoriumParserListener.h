
// Generated from CoriumParser.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "CoriumParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by CoriumParser.
 */
class  CoriumParserListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterLocalVariableDeclaration(CoriumParser::LocalVariableDeclarationContext *ctx) = 0;
  virtual void exitLocalVariableDeclaration(CoriumParser::LocalVariableDeclarationContext *ctx) = 0;

  virtual void enterLiteral(CoriumParser::LiteralContext *ctx) = 0;
  virtual void exitLiteral(CoriumParser::LiteralContext *ctx) = 0;

  virtual void enterIntLiteral(CoriumParser::IntLiteralContext *ctx) = 0;
  virtual void exitIntLiteral(CoriumParser::IntLiteralContext *ctx) = 0;

  virtual void enterFloatLiteral(CoriumParser::FloatLiteralContext *ctx) = 0;
  virtual void exitFloatLiteral(CoriumParser::FloatLiteralContext *ctx) = 0;

  virtual void enterPrimitiveType(CoriumParser::PrimitiveTypeContext *ctx) = 0;
  virtual void exitPrimitiveType(CoriumParser::PrimitiveTypeContext *ctx) = 0;


};

