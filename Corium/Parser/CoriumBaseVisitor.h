
// Generated from Corium.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "CoriumVisitor.h"


/**
 * This class provides an empty implementation of CoriumVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  CoriumBaseVisitor : public CoriumVisitor {
public:

  virtual antlrcpp::Any visitCompilationUnit(CoriumParser::CompilationUnitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModuleDeclaration(CoriumParser::ModuleDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLocalVariableDeclaration(CoriumParser::LocalVariableDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr(CoriumParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeClassName(CoriumParser::TypeClassNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBuiltinType(CoriumParser::BuiltinTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQualifiedName(CoriumParser::QualifiedNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteral(CoriumParser::LiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIntLiteral(CoriumParser::IntLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFloatLiteral(CoriumParser::FloatLiteralContext *ctx) override {
    return visitChildren(ctx);
  }


};

