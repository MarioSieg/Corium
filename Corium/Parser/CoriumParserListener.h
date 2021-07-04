
// Generated from CoriumParser.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "CoriumParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by CoriumParser.
 */
class  CoriumParserListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterCompilationUnit(CoriumParser::CompilationUnitContext *ctx) = 0;
  virtual void exitCompilationUnit(CoriumParser::CompilationUnitContext *ctx) = 0;

  virtual void enterPackageDeclaration(CoriumParser::PackageDeclarationContext *ctx) = 0;
  virtual void exitPackageDeclaration(CoriumParser::PackageDeclarationContext *ctx) = 0;

  virtual void enterImportDeclaration(CoriumParser::ImportDeclarationContext *ctx) = 0;
  virtual void exitImportDeclaration(CoriumParser::ImportDeclarationContext *ctx) = 0;

  virtual void enterTypeDeclaration(CoriumParser::TypeDeclarationContext *ctx) = 0;
  virtual void exitTypeDeclaration(CoriumParser::TypeDeclarationContext *ctx) = 0;

  virtual void enterModifier(CoriumParser::ModifierContext *ctx) = 0;
  virtual void exitModifier(CoriumParser::ModifierContext *ctx) = 0;

  virtual void enterClassOrInterfaceModifier(CoriumParser::ClassOrInterfaceModifierContext *ctx) = 0;
  virtual void exitClassOrInterfaceModifier(CoriumParser::ClassOrInterfaceModifierContext *ctx) = 0;

  virtual void enterVariableModifier(CoriumParser::VariableModifierContext *ctx) = 0;
  virtual void exitVariableModifier(CoriumParser::VariableModifierContext *ctx) = 0;

  virtual void enterClassDeclaration(CoriumParser::ClassDeclarationContext *ctx) = 0;
  virtual void exitClassDeclaration(CoriumParser::ClassDeclarationContext *ctx) = 0;

  virtual void enterTypeParameters(CoriumParser::TypeParametersContext *ctx) = 0;
  virtual void exitTypeParameters(CoriumParser::TypeParametersContext *ctx) = 0;

  virtual void enterTypeParameter(CoriumParser::TypeParameterContext *ctx) = 0;
  virtual void exitTypeParameter(CoriumParser::TypeParameterContext *ctx) = 0;

  virtual void enterTypeBound(CoriumParser::TypeBoundContext *ctx) = 0;
  virtual void exitTypeBound(CoriumParser::TypeBoundContext *ctx) = 0;

  virtual void enterEnumDeclaration(CoriumParser::EnumDeclarationContext *ctx) = 0;
  virtual void exitEnumDeclaration(CoriumParser::EnumDeclarationContext *ctx) = 0;

  virtual void enterEnumConstants(CoriumParser::EnumConstantsContext *ctx) = 0;
  virtual void exitEnumConstants(CoriumParser::EnumConstantsContext *ctx) = 0;

  virtual void enterEnumConstant(CoriumParser::EnumConstantContext *ctx) = 0;
  virtual void exitEnumConstant(CoriumParser::EnumConstantContext *ctx) = 0;

  virtual void enterEnumBodyDeclarations(CoriumParser::EnumBodyDeclarationsContext *ctx) = 0;
  virtual void exitEnumBodyDeclarations(CoriumParser::EnumBodyDeclarationsContext *ctx) = 0;

  virtual void enterInterfaceDeclaration(CoriumParser::InterfaceDeclarationContext *ctx) = 0;
  virtual void exitInterfaceDeclaration(CoriumParser::InterfaceDeclarationContext *ctx) = 0;

  virtual void enterClassBody(CoriumParser::ClassBodyContext *ctx) = 0;
  virtual void exitClassBody(CoriumParser::ClassBodyContext *ctx) = 0;

  virtual void enterInterfaceBody(CoriumParser::InterfaceBodyContext *ctx) = 0;
  virtual void exitInterfaceBody(CoriumParser::InterfaceBodyContext *ctx) = 0;

  virtual void enterClassBodyDeclaration(CoriumParser::ClassBodyDeclarationContext *ctx) = 0;
  virtual void exitClassBodyDeclaration(CoriumParser::ClassBodyDeclarationContext *ctx) = 0;

  virtual void enterMemberDeclaration(CoriumParser::MemberDeclarationContext *ctx) = 0;
  virtual void exitMemberDeclaration(CoriumParser::MemberDeclarationContext *ctx) = 0;

  virtual void enterMethodDeclaration(CoriumParser::MethodDeclarationContext *ctx) = 0;
  virtual void exitMethodDeclaration(CoriumParser::MethodDeclarationContext *ctx) = 0;

  virtual void enterMethodBody(CoriumParser::MethodBodyContext *ctx) = 0;
  virtual void exitMethodBody(CoriumParser::MethodBodyContext *ctx) = 0;

  virtual void enterTypeTypeOrVoid(CoriumParser::TypeTypeOrVoidContext *ctx) = 0;
  virtual void exitTypeTypeOrVoid(CoriumParser::TypeTypeOrVoidContext *ctx) = 0;

  virtual void enterGenericMethodDeclaration(CoriumParser::GenericMethodDeclarationContext *ctx) = 0;
  virtual void exitGenericMethodDeclaration(CoriumParser::GenericMethodDeclarationContext *ctx) = 0;

  virtual void enterGenericConstructorDeclaration(CoriumParser::GenericConstructorDeclarationContext *ctx) = 0;
  virtual void exitGenericConstructorDeclaration(CoriumParser::GenericConstructorDeclarationContext *ctx) = 0;

  virtual void enterConstructorDeclaration(CoriumParser::ConstructorDeclarationContext *ctx) = 0;
  virtual void exitConstructorDeclaration(CoriumParser::ConstructorDeclarationContext *ctx) = 0;

  virtual void enterFieldDeclaration(CoriumParser::FieldDeclarationContext *ctx) = 0;
  virtual void exitFieldDeclaration(CoriumParser::FieldDeclarationContext *ctx) = 0;

  virtual void enterInterfaceBodyDeclaration(CoriumParser::InterfaceBodyDeclarationContext *ctx) = 0;
  virtual void exitInterfaceBodyDeclaration(CoriumParser::InterfaceBodyDeclarationContext *ctx) = 0;

  virtual void enterInterfaceMemberDeclaration(CoriumParser::InterfaceMemberDeclarationContext *ctx) = 0;
  virtual void exitInterfaceMemberDeclaration(CoriumParser::InterfaceMemberDeclarationContext *ctx) = 0;

  virtual void enterConstDeclaration(CoriumParser::ConstDeclarationContext *ctx) = 0;
  virtual void exitConstDeclaration(CoriumParser::ConstDeclarationContext *ctx) = 0;

  virtual void enterConstantDeclarator(CoriumParser::ConstantDeclaratorContext *ctx) = 0;
  virtual void exitConstantDeclarator(CoriumParser::ConstantDeclaratorContext *ctx) = 0;

  virtual void enterInterfaceMethodDeclaration(CoriumParser::InterfaceMethodDeclarationContext *ctx) = 0;
  virtual void exitInterfaceMethodDeclaration(CoriumParser::InterfaceMethodDeclarationContext *ctx) = 0;

  virtual void enterInterfaceMethodModifier(CoriumParser::InterfaceMethodModifierContext *ctx) = 0;
  virtual void exitInterfaceMethodModifier(CoriumParser::InterfaceMethodModifierContext *ctx) = 0;

  virtual void enterGenericInterfaceMethodDeclaration(CoriumParser::GenericInterfaceMethodDeclarationContext *ctx) = 0;
  virtual void exitGenericInterfaceMethodDeclaration(CoriumParser::GenericInterfaceMethodDeclarationContext *ctx) = 0;

  virtual void enterVariableDeclarators(CoriumParser::VariableDeclaratorsContext *ctx) = 0;
  virtual void exitVariableDeclarators(CoriumParser::VariableDeclaratorsContext *ctx) = 0;

  virtual void enterVariableDeclarator(CoriumParser::VariableDeclaratorContext *ctx) = 0;
  virtual void exitVariableDeclarator(CoriumParser::VariableDeclaratorContext *ctx) = 0;

  virtual void enterVariableDeclaratorId(CoriumParser::VariableDeclaratorIdContext *ctx) = 0;
  virtual void exitVariableDeclaratorId(CoriumParser::VariableDeclaratorIdContext *ctx) = 0;

  virtual void enterVariableInitializer(CoriumParser::VariableInitializerContext *ctx) = 0;
  virtual void exitVariableInitializer(CoriumParser::VariableInitializerContext *ctx) = 0;

  virtual void enterArrayInitializer(CoriumParser::ArrayInitializerContext *ctx) = 0;
  virtual void exitArrayInitializer(CoriumParser::ArrayInitializerContext *ctx) = 0;

  virtual void enterClassOrInterfaceType(CoriumParser::ClassOrInterfaceTypeContext *ctx) = 0;
  virtual void exitClassOrInterfaceType(CoriumParser::ClassOrInterfaceTypeContext *ctx) = 0;

  virtual void enterTypeArgument(CoriumParser::TypeArgumentContext *ctx) = 0;
  virtual void exitTypeArgument(CoriumParser::TypeArgumentContext *ctx) = 0;

  virtual void enterQualifiedNameList(CoriumParser::QualifiedNameListContext *ctx) = 0;
  virtual void exitQualifiedNameList(CoriumParser::QualifiedNameListContext *ctx) = 0;

  virtual void enterFormalParameters(CoriumParser::FormalParametersContext *ctx) = 0;
  virtual void exitFormalParameters(CoriumParser::FormalParametersContext *ctx) = 0;

  virtual void enterFormalParameterList(CoriumParser::FormalParameterListContext *ctx) = 0;
  virtual void exitFormalParameterList(CoriumParser::FormalParameterListContext *ctx) = 0;

  virtual void enterFormalParameter(CoriumParser::FormalParameterContext *ctx) = 0;
  virtual void exitFormalParameter(CoriumParser::FormalParameterContext *ctx) = 0;

  virtual void enterLastFormalParameter(CoriumParser::LastFormalParameterContext *ctx) = 0;
  virtual void exitLastFormalParameter(CoriumParser::LastFormalParameterContext *ctx) = 0;

  virtual void enterQualifiedName(CoriumParser::QualifiedNameContext *ctx) = 0;
  virtual void exitQualifiedName(CoriumParser::QualifiedNameContext *ctx) = 0;

  virtual void enterLiteral(CoriumParser::LiteralContext *ctx) = 0;
  virtual void exitLiteral(CoriumParser::LiteralContext *ctx) = 0;

  virtual void enterIntegerLiteral(CoriumParser::IntegerLiteralContext *ctx) = 0;
  virtual void exitIntegerLiteral(CoriumParser::IntegerLiteralContext *ctx) = 0;

  virtual void enterFloatLiteral(CoriumParser::FloatLiteralContext *ctx) = 0;
  virtual void exitFloatLiteral(CoriumParser::FloatLiteralContext *ctx) = 0;

  virtual void enterAltAnnotationQualifiedName(CoriumParser::AltAnnotationQualifiedNameContext *ctx) = 0;
  virtual void exitAltAnnotationQualifiedName(CoriumParser::AltAnnotationQualifiedNameContext *ctx) = 0;

  virtual void enterAnnotation(CoriumParser::AnnotationContext *ctx) = 0;
  virtual void exitAnnotation(CoriumParser::AnnotationContext *ctx) = 0;

  virtual void enterElementValuePairs(CoriumParser::ElementValuePairsContext *ctx) = 0;
  virtual void exitElementValuePairs(CoriumParser::ElementValuePairsContext *ctx) = 0;

  virtual void enterElementValuePair(CoriumParser::ElementValuePairContext *ctx) = 0;
  virtual void exitElementValuePair(CoriumParser::ElementValuePairContext *ctx) = 0;

  virtual void enterElementValue(CoriumParser::ElementValueContext *ctx) = 0;
  virtual void exitElementValue(CoriumParser::ElementValueContext *ctx) = 0;

  virtual void enterElementValueArrayInitializer(CoriumParser::ElementValueArrayInitializerContext *ctx) = 0;
  virtual void exitElementValueArrayInitializer(CoriumParser::ElementValueArrayInitializerContext *ctx) = 0;

  virtual void enterAnnotationTypeDeclaration(CoriumParser::AnnotationTypeDeclarationContext *ctx) = 0;
  virtual void exitAnnotationTypeDeclaration(CoriumParser::AnnotationTypeDeclarationContext *ctx) = 0;

  virtual void enterAnnotationTypeBody(CoriumParser::AnnotationTypeBodyContext *ctx) = 0;
  virtual void exitAnnotationTypeBody(CoriumParser::AnnotationTypeBodyContext *ctx) = 0;

  virtual void enterAnnotationTypeElementDeclaration(CoriumParser::AnnotationTypeElementDeclarationContext *ctx) = 0;
  virtual void exitAnnotationTypeElementDeclaration(CoriumParser::AnnotationTypeElementDeclarationContext *ctx) = 0;

  virtual void enterAnnotationTypeElementRest(CoriumParser::AnnotationTypeElementRestContext *ctx) = 0;
  virtual void exitAnnotationTypeElementRest(CoriumParser::AnnotationTypeElementRestContext *ctx) = 0;

  virtual void enterAnnotationMethodOrConstantRest(CoriumParser::AnnotationMethodOrConstantRestContext *ctx) = 0;
  virtual void exitAnnotationMethodOrConstantRest(CoriumParser::AnnotationMethodOrConstantRestContext *ctx) = 0;

  virtual void enterAnnotationMethodRest(CoriumParser::AnnotationMethodRestContext *ctx) = 0;
  virtual void exitAnnotationMethodRest(CoriumParser::AnnotationMethodRestContext *ctx) = 0;

  virtual void enterAnnotationConstantRest(CoriumParser::AnnotationConstantRestContext *ctx) = 0;
  virtual void exitAnnotationConstantRest(CoriumParser::AnnotationConstantRestContext *ctx) = 0;

  virtual void enterDefaultValue(CoriumParser::DefaultValueContext *ctx) = 0;
  virtual void exitDefaultValue(CoriumParser::DefaultValueContext *ctx) = 0;

  virtual void enterBlock(CoriumParser::BlockContext *ctx) = 0;
  virtual void exitBlock(CoriumParser::BlockContext *ctx) = 0;

  virtual void enterBlockStatement(CoriumParser::BlockStatementContext *ctx) = 0;
  virtual void exitBlockStatement(CoriumParser::BlockStatementContext *ctx) = 0;

  virtual void enterLocalVariableDeclaration(CoriumParser::LocalVariableDeclarationContext *ctx) = 0;
  virtual void exitLocalVariableDeclaration(CoriumParser::LocalVariableDeclarationContext *ctx) = 0;

  virtual void enterLocalTypeDeclaration(CoriumParser::LocalTypeDeclarationContext *ctx) = 0;
  virtual void exitLocalTypeDeclaration(CoriumParser::LocalTypeDeclarationContext *ctx) = 0;

  virtual void enterStatement(CoriumParser::StatementContext *ctx) = 0;
  virtual void exitStatement(CoriumParser::StatementContext *ctx) = 0;

  virtual void enterCatchClause(CoriumParser::CatchClauseContext *ctx) = 0;
  virtual void exitCatchClause(CoriumParser::CatchClauseContext *ctx) = 0;

  virtual void enterCatchType(CoriumParser::CatchTypeContext *ctx) = 0;
  virtual void exitCatchType(CoriumParser::CatchTypeContext *ctx) = 0;

  virtual void enterFinallyBlock(CoriumParser::FinallyBlockContext *ctx) = 0;
  virtual void exitFinallyBlock(CoriumParser::FinallyBlockContext *ctx) = 0;

  virtual void enterResourceSpecification(CoriumParser::ResourceSpecificationContext *ctx) = 0;
  virtual void exitResourceSpecification(CoriumParser::ResourceSpecificationContext *ctx) = 0;

  virtual void enterResources(CoriumParser::ResourcesContext *ctx) = 0;
  virtual void exitResources(CoriumParser::ResourcesContext *ctx) = 0;

  virtual void enterResource(CoriumParser::ResourceContext *ctx) = 0;
  virtual void exitResource(CoriumParser::ResourceContext *ctx) = 0;

  virtual void enterSwitchBlockStatementGroup(CoriumParser::SwitchBlockStatementGroupContext *ctx) = 0;
  virtual void exitSwitchBlockStatementGroup(CoriumParser::SwitchBlockStatementGroupContext *ctx) = 0;

  virtual void enterSwitchLabel(CoriumParser::SwitchLabelContext *ctx) = 0;
  virtual void exitSwitchLabel(CoriumParser::SwitchLabelContext *ctx) = 0;

  virtual void enterForControl(CoriumParser::ForControlContext *ctx) = 0;
  virtual void exitForControl(CoriumParser::ForControlContext *ctx) = 0;

  virtual void enterForInit(CoriumParser::ForInitContext *ctx) = 0;
  virtual void exitForInit(CoriumParser::ForInitContext *ctx) = 0;

  virtual void enterEnhancedForControl(CoriumParser::EnhancedForControlContext *ctx) = 0;
  virtual void exitEnhancedForControl(CoriumParser::EnhancedForControlContext *ctx) = 0;

  virtual void enterParExpression(CoriumParser::ParExpressionContext *ctx) = 0;
  virtual void exitParExpression(CoriumParser::ParExpressionContext *ctx) = 0;

  virtual void enterExpressionList(CoriumParser::ExpressionListContext *ctx) = 0;
  virtual void exitExpressionList(CoriumParser::ExpressionListContext *ctx) = 0;

  virtual void enterMethodCall(CoriumParser::MethodCallContext *ctx) = 0;
  virtual void exitMethodCall(CoriumParser::MethodCallContext *ctx) = 0;

  virtual void enterExpression(CoriumParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(CoriumParser::ExpressionContext *ctx) = 0;

  virtual void enterLambdaExpression(CoriumParser::LambdaExpressionContext *ctx) = 0;
  virtual void exitLambdaExpression(CoriumParser::LambdaExpressionContext *ctx) = 0;

  virtual void enterLambdaParameters(CoriumParser::LambdaParametersContext *ctx) = 0;
  virtual void exitLambdaParameters(CoriumParser::LambdaParametersContext *ctx) = 0;

  virtual void enterLambdaBody(CoriumParser::LambdaBodyContext *ctx) = 0;
  virtual void exitLambdaBody(CoriumParser::LambdaBodyContext *ctx) = 0;

  virtual void enterPrimary(CoriumParser::PrimaryContext *ctx) = 0;
  virtual void exitPrimary(CoriumParser::PrimaryContext *ctx) = 0;

  virtual void enterClassType(CoriumParser::ClassTypeContext *ctx) = 0;
  virtual void exitClassType(CoriumParser::ClassTypeContext *ctx) = 0;

  virtual void enterCreator(CoriumParser::CreatorContext *ctx) = 0;
  virtual void exitCreator(CoriumParser::CreatorContext *ctx) = 0;

  virtual void enterCreatedName(CoriumParser::CreatedNameContext *ctx) = 0;
  virtual void exitCreatedName(CoriumParser::CreatedNameContext *ctx) = 0;

  virtual void enterInnerCreator(CoriumParser::InnerCreatorContext *ctx) = 0;
  virtual void exitInnerCreator(CoriumParser::InnerCreatorContext *ctx) = 0;

  virtual void enterArrayCreatorRest(CoriumParser::ArrayCreatorRestContext *ctx) = 0;
  virtual void exitArrayCreatorRest(CoriumParser::ArrayCreatorRestContext *ctx) = 0;

  virtual void enterClassCreatorRest(CoriumParser::ClassCreatorRestContext *ctx) = 0;
  virtual void exitClassCreatorRest(CoriumParser::ClassCreatorRestContext *ctx) = 0;

  virtual void enterExplicitGenericInvocation(CoriumParser::ExplicitGenericInvocationContext *ctx) = 0;
  virtual void exitExplicitGenericInvocation(CoriumParser::ExplicitGenericInvocationContext *ctx) = 0;

  virtual void enterTypeArgumentsOrDiamond(CoriumParser::TypeArgumentsOrDiamondContext *ctx) = 0;
  virtual void exitTypeArgumentsOrDiamond(CoriumParser::TypeArgumentsOrDiamondContext *ctx) = 0;

  virtual void enterNonWildcardTypeArgumentsOrDiamond(CoriumParser::NonWildcardTypeArgumentsOrDiamondContext *ctx) = 0;
  virtual void exitNonWildcardTypeArgumentsOrDiamond(CoriumParser::NonWildcardTypeArgumentsOrDiamondContext *ctx) = 0;

  virtual void enterNonWildcardTypeArguments(CoriumParser::NonWildcardTypeArgumentsContext *ctx) = 0;
  virtual void exitNonWildcardTypeArguments(CoriumParser::NonWildcardTypeArgumentsContext *ctx) = 0;

  virtual void enterTypeList(CoriumParser::TypeListContext *ctx) = 0;
  virtual void exitTypeList(CoriumParser::TypeListContext *ctx) = 0;

  virtual void enterTypeType(CoriumParser::TypeTypeContext *ctx) = 0;
  virtual void exitTypeType(CoriumParser::TypeTypeContext *ctx) = 0;

  virtual void enterPrimitiveType(CoriumParser::PrimitiveTypeContext *ctx) = 0;
  virtual void exitPrimitiveType(CoriumParser::PrimitiveTypeContext *ctx) = 0;

  virtual void enterTypeArguments(CoriumParser::TypeArgumentsContext *ctx) = 0;
  virtual void exitTypeArguments(CoriumParser::TypeArgumentsContext *ctx) = 0;

  virtual void enterSuperSuffix(CoriumParser::SuperSuffixContext *ctx) = 0;
  virtual void exitSuperSuffix(CoriumParser::SuperSuffixContext *ctx) = 0;

  virtual void enterExplicitGenericInvocationSuffix(CoriumParser::ExplicitGenericInvocationSuffixContext *ctx) = 0;
  virtual void exitExplicitGenericInvocationSuffix(CoriumParser::ExplicitGenericInvocationSuffixContext *ctx) = 0;

  virtual void enterArguments(CoriumParser::ArgumentsContext *ctx) = 0;
  virtual void exitArguments(CoriumParser::ArgumentsContext *ctx) = 0;


};

