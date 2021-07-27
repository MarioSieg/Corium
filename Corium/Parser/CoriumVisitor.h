
// Generated from Corium.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "CoriumParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by CoriumParser.
 */
class  CoriumVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by CoriumParser.
   */
    virtual antlrcpp::Any visitCompilationUnit(CoriumParser::CompilationUnitContext *context) = 0;

    virtual antlrcpp::Any visitModuleDeclaration(CoriumParser::ModuleDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitLocalVariableDeclaration(CoriumParser::LocalVariableDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitExpr(CoriumParser::ExprContext *context) = 0;

    virtual antlrcpp::Any visitTypeClassName(CoriumParser::TypeClassNameContext *context) = 0;

    virtual antlrcpp::Any visitBuiltinType(CoriumParser::BuiltinTypeContext *context) = 0;

    virtual antlrcpp::Any visitQualifiedName(CoriumParser::QualifiedNameContext *context) = 0;

    virtual antlrcpp::Any visitLiteral(CoriumParser::LiteralContext *context) = 0;

    virtual antlrcpp::Any visitIntLiteral(CoriumParser::IntLiteralContext *context) = 0;

    virtual antlrcpp::Any visitFloatLiteral(CoriumParser::FloatLiteralContext *context) = 0;


};

