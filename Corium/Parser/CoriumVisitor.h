
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

    virtual antlrcpp::Any visitCompilationUnitStatement(CoriumParser::CompilationUnitStatementContext *context) = 0;

    virtual antlrcpp::Any visitClassDeclaration(CoriumParser::ClassDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitClassBlockStatement(CoriumParser::ClassBlockStatementContext *context) = 0;

    virtual antlrcpp::Any visitNativeFunctionDeclaration(CoriumParser::NativeFunctionDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitFunctionDeclaration(CoriumParser::FunctionDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitFunctionCall(CoriumParser::FunctionCallContext *context) = 0;

    virtual antlrcpp::Any visitFunctionHeader(CoriumParser::FunctionHeaderContext *context) = 0;

    virtual antlrcpp::Any visitFunctionBlockStatement(CoriumParser::FunctionBlockStatementContext *context) = 0;

    virtual antlrcpp::Any visitReturnStatement(CoriumParser::ReturnStatementContext *context) = 0;

    virtual antlrcpp::Any visitLocalVariableDeclaration(CoriumParser::LocalVariableDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitConstVariableDeclaration(CoriumParser::ConstVariableDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitParameterList(CoriumParser::ParameterListContext *context) = 0;

    virtual antlrcpp::Any visitParameter(CoriumParser::ParameterContext *context) = 0;

    virtual antlrcpp::Any visitTypeName(CoriumParser::TypeNameContext *context) = 0;

    virtual antlrcpp::Any visitBuiltinType(CoriumParser::BuiltinTypeContext *context) = 0;

    virtual antlrcpp::Any visitQualifiedName(CoriumParser::QualifiedNameContext *context) = 0;

    virtual antlrcpp::Any visitExpressionList(CoriumParser::ExpressionListContext *context) = 0;

    virtual antlrcpp::Any visitExpression(CoriumParser::ExpressionContext *context) = 0;

    virtual antlrcpp::Any visitLiteral(CoriumParser::LiteralContext *context) = 0;

    virtual antlrcpp::Any visitIntLiteral(CoriumParser::IntLiteralContext *context) = 0;

    virtual antlrcpp::Any visitFloatLiteral(CoriumParser::FloatLiteralContext *context) = 0;


};

