
// Generated from Corium.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"
#include "CoriumParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by CoriumParser.
 */
class  CoriumListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterCompilationUnit(CoriumParser::CompilationUnitContext *ctx) = 0;
  virtual void exitCompilationUnit(CoriumParser::CompilationUnitContext *ctx) = 0;

  virtual void enterLocalVariableDeclaration(CoriumParser::LocalVariableDeclarationContext *ctx) = 0;
  virtual void exitLocalVariableDeclaration(CoriumParser::LocalVariableDeclarationContext *ctx) = 0;

  virtual void enterLiteral(CoriumParser::LiteralContext *ctx) = 0;
  virtual void exitLiteral(CoriumParser::LiteralContext *ctx) = 0;

  virtual void enterPrimitiveType(CoriumParser::PrimitiveTypeContext *ctx) = 0;
  virtual void exitPrimitiveType(CoriumParser::PrimitiveTypeContext *ctx) = 0;


};

