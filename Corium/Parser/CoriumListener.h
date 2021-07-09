
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

  virtual void enterModuleDeclaration(CoriumParser::ModuleDeclarationContext *ctx) = 0;
  virtual void exitModuleDeclaration(CoriumParser::ModuleDeclarationContext *ctx) = 0;

  virtual void enterCompilationUnitStatement(CoriumParser::CompilationUnitStatementContext *ctx) = 0;
  virtual void exitCompilationUnitStatement(CoriumParser::CompilationUnitStatementContext *ctx) = 0;

  virtual void enterNativeFunctionDeclaration(CoriumParser::NativeFunctionDeclarationContext *ctx) = 0;
  virtual void exitNativeFunctionDeclaration(CoriumParser::NativeFunctionDeclarationContext *ctx) = 0;

  virtual void enterFunctionDeclaration(CoriumParser::FunctionDeclarationContext *ctx) = 0;
  virtual void exitFunctionDeclaration(CoriumParser::FunctionDeclarationContext *ctx) = 0;

  virtual void enterFunctionBlockStatement(CoriumParser::FunctionBlockStatementContext *ctx) = 0;
  virtual void exitFunctionBlockStatement(CoriumParser::FunctionBlockStatementContext *ctx) = 0;

  virtual void enterLocalVariableDeclaration(CoriumParser::LocalVariableDeclarationContext *ctx) = 0;
  virtual void exitLocalVariableDeclaration(CoriumParser::LocalVariableDeclarationContext *ctx) = 0;

  virtual void enterConstVariableDeclaration(CoriumParser::ConstVariableDeclarationContext *ctx) = 0;
  virtual void exitConstVariableDeclaration(CoriumParser::ConstVariableDeclarationContext *ctx) = 0;

  virtual void enterParameterList(CoriumParser::ParameterListContext *ctx) = 0;
  virtual void exitParameterList(CoriumParser::ParameterListContext *ctx) = 0;

  virtual void enterParameter(CoriumParser::ParameterContext *ctx) = 0;
  virtual void exitParameter(CoriumParser::ParameterContext *ctx) = 0;

  virtual void enterTypeName(CoriumParser::TypeNameContext *ctx) = 0;
  virtual void exitTypeName(CoriumParser::TypeNameContext *ctx) = 0;

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

