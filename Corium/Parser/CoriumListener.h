
// Generated from Corium.g4 by ANTLR 4.9.2

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

  virtual void enterModuleDeclaration(CoriumParser::ModuleDeclarationContext *ctx) = 0;
  virtual void exitModuleDeclaration(CoriumParser::ModuleDeclarationContext *ctx) = 0;

  virtual void enterLocalVariableDeclaration(CoriumParser::LocalVariableDeclarationContext *ctx) = 0;
  virtual void exitLocalVariableDeclaration(CoriumParser::LocalVariableDeclarationContext *ctx) = 0;

  virtual void enterExpr(CoriumParser::ExprContext *ctx) = 0;
  virtual void exitExpr(CoriumParser::ExprContext *ctx) = 0;

  virtual void enterTypeClassName(CoriumParser::TypeClassNameContext *ctx) = 0;
  virtual void exitTypeClassName(CoriumParser::TypeClassNameContext *ctx) = 0;

  virtual void enterBuiltinType(CoriumParser::BuiltinTypeContext *ctx) = 0;
  virtual void exitBuiltinType(CoriumParser::BuiltinTypeContext *ctx) = 0;

  virtual void enterQualifiedName(CoriumParser::QualifiedNameContext *ctx) = 0;
  virtual void exitQualifiedName(CoriumParser::QualifiedNameContext *ctx) = 0;

  virtual void enterLiteral(CoriumParser::LiteralContext *ctx) = 0;
  virtual void exitLiteral(CoriumParser::LiteralContext *ctx) = 0;

  virtual void enterIntLiteral(CoriumParser::IntLiteralContext *ctx) = 0;
  virtual void exitIntLiteral(CoriumParser::IntLiteralContext *ctx) = 0;

  virtual void enterFloatLiteral(CoriumParser::FloatLiteralContext *ctx) = 0;
  virtual void exitFloatLiteral(CoriumParser::FloatLiteralContext *ctx) = 0;


};

