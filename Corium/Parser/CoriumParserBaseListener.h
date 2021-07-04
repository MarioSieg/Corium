
// Generated from CoriumParser.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "CoriumParserListener.h"


/**
 * This class provides an empty implementation of CoriumParserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  CoriumParserBaseListener : public CoriumParserListener {
public:

  virtual void enterCompilationUnit(CoriumParser::CompilationUnitContext * /*ctx*/) override { }
  virtual void exitCompilationUnit(CoriumParser::CompilationUnitContext * /*ctx*/) override { }

  virtual void enterPackageDeclaration(CoriumParser::PackageDeclarationContext * /*ctx*/) override { }
  virtual void exitPackageDeclaration(CoriumParser::PackageDeclarationContext * /*ctx*/) override { }

  virtual void enterImportDeclaration(CoriumParser::ImportDeclarationContext * /*ctx*/) override { }
  virtual void exitImportDeclaration(CoriumParser::ImportDeclarationContext * /*ctx*/) override { }

  virtual void enterTypeDeclaration(CoriumParser::TypeDeclarationContext * /*ctx*/) override { }
  virtual void exitTypeDeclaration(CoriumParser::TypeDeclarationContext * /*ctx*/) override { }

  virtual void enterModifier(CoriumParser::ModifierContext * /*ctx*/) override { }
  virtual void exitModifier(CoriumParser::ModifierContext * /*ctx*/) override { }

  virtual void enterClassOrInterfaceModifier(CoriumParser::ClassOrInterfaceModifierContext * /*ctx*/) override { }
  virtual void exitClassOrInterfaceModifier(CoriumParser::ClassOrInterfaceModifierContext * /*ctx*/) override { }

  virtual void enterVariableModifier(CoriumParser::VariableModifierContext * /*ctx*/) override { }
  virtual void exitVariableModifier(CoriumParser::VariableModifierContext * /*ctx*/) override { }

  virtual void enterClassDeclaration(CoriumParser::ClassDeclarationContext * /*ctx*/) override { }
  virtual void exitClassDeclaration(CoriumParser::ClassDeclarationContext * /*ctx*/) override { }

  virtual void enterTypeParameters(CoriumParser::TypeParametersContext * /*ctx*/) override { }
  virtual void exitTypeParameters(CoriumParser::TypeParametersContext * /*ctx*/) override { }

  virtual void enterTypeParameter(CoriumParser::TypeParameterContext * /*ctx*/) override { }
  virtual void exitTypeParameter(CoriumParser::TypeParameterContext * /*ctx*/) override { }

  virtual void enterTypeBound(CoriumParser::TypeBoundContext * /*ctx*/) override { }
  virtual void exitTypeBound(CoriumParser::TypeBoundContext * /*ctx*/) override { }

  virtual void enterEnumDeclaration(CoriumParser::EnumDeclarationContext * /*ctx*/) override { }
  virtual void exitEnumDeclaration(CoriumParser::EnumDeclarationContext * /*ctx*/) override { }

  virtual void enterEnumConstants(CoriumParser::EnumConstantsContext * /*ctx*/) override { }
  virtual void exitEnumConstants(CoriumParser::EnumConstantsContext * /*ctx*/) override { }

  virtual void enterEnumConstant(CoriumParser::EnumConstantContext * /*ctx*/) override { }
  virtual void exitEnumConstant(CoriumParser::EnumConstantContext * /*ctx*/) override { }

  virtual void enterEnumBodyDeclarations(CoriumParser::EnumBodyDeclarationsContext * /*ctx*/) override { }
  virtual void exitEnumBodyDeclarations(CoriumParser::EnumBodyDeclarationsContext * /*ctx*/) override { }

  virtual void enterInterfaceDeclaration(CoriumParser::InterfaceDeclarationContext * /*ctx*/) override { }
  virtual void exitInterfaceDeclaration(CoriumParser::InterfaceDeclarationContext * /*ctx*/) override { }

  virtual void enterClassBody(CoriumParser::ClassBodyContext * /*ctx*/) override { }
  virtual void exitClassBody(CoriumParser::ClassBodyContext * /*ctx*/) override { }

  virtual void enterInterfaceBody(CoriumParser::InterfaceBodyContext * /*ctx*/) override { }
  virtual void exitInterfaceBody(CoriumParser::InterfaceBodyContext * /*ctx*/) override { }

  virtual void enterClassBodyDeclaration(CoriumParser::ClassBodyDeclarationContext * /*ctx*/) override { }
  virtual void exitClassBodyDeclaration(CoriumParser::ClassBodyDeclarationContext * /*ctx*/) override { }

  virtual void enterMemberDeclaration(CoriumParser::MemberDeclarationContext * /*ctx*/) override { }
  virtual void exitMemberDeclaration(CoriumParser::MemberDeclarationContext * /*ctx*/) override { }

  virtual void enterMethodDeclaration(CoriumParser::MethodDeclarationContext * /*ctx*/) override { }
  virtual void exitMethodDeclaration(CoriumParser::MethodDeclarationContext * /*ctx*/) override { }

  virtual void enterMethodBody(CoriumParser::MethodBodyContext * /*ctx*/) override { }
  virtual void exitMethodBody(CoriumParser::MethodBodyContext * /*ctx*/) override { }

  virtual void enterTypeTypeOrVoid(CoriumParser::TypeTypeOrVoidContext * /*ctx*/) override { }
  virtual void exitTypeTypeOrVoid(CoriumParser::TypeTypeOrVoidContext * /*ctx*/) override { }

  virtual void enterGenericMethodDeclaration(CoriumParser::GenericMethodDeclarationContext * /*ctx*/) override { }
  virtual void exitGenericMethodDeclaration(CoriumParser::GenericMethodDeclarationContext * /*ctx*/) override { }

  virtual void enterGenericConstructorDeclaration(CoriumParser::GenericConstructorDeclarationContext * /*ctx*/) override { }
  virtual void exitGenericConstructorDeclaration(CoriumParser::GenericConstructorDeclarationContext * /*ctx*/) override { }

  virtual void enterConstructorDeclaration(CoriumParser::ConstructorDeclarationContext * /*ctx*/) override { }
  virtual void exitConstructorDeclaration(CoriumParser::ConstructorDeclarationContext * /*ctx*/) override { }

  virtual void enterFieldDeclaration(CoriumParser::FieldDeclarationContext * /*ctx*/) override { }
  virtual void exitFieldDeclaration(CoriumParser::FieldDeclarationContext * /*ctx*/) override { }

  virtual void enterInterfaceBodyDeclaration(CoriumParser::InterfaceBodyDeclarationContext * /*ctx*/) override { }
  virtual void exitInterfaceBodyDeclaration(CoriumParser::InterfaceBodyDeclarationContext * /*ctx*/) override { }

  virtual void enterInterfaceMemberDeclaration(CoriumParser::InterfaceMemberDeclarationContext * /*ctx*/) override { }
  virtual void exitInterfaceMemberDeclaration(CoriumParser::InterfaceMemberDeclarationContext * /*ctx*/) override { }

  virtual void enterConstDeclaration(CoriumParser::ConstDeclarationContext * /*ctx*/) override { }
  virtual void exitConstDeclaration(CoriumParser::ConstDeclarationContext * /*ctx*/) override { }

  virtual void enterConstantDeclarator(CoriumParser::ConstantDeclaratorContext * /*ctx*/) override { }
  virtual void exitConstantDeclarator(CoriumParser::ConstantDeclaratorContext * /*ctx*/) override { }

  virtual void enterInterfaceMethodDeclaration(CoriumParser::InterfaceMethodDeclarationContext * /*ctx*/) override { }
  virtual void exitInterfaceMethodDeclaration(CoriumParser::InterfaceMethodDeclarationContext * /*ctx*/) override { }

  virtual void enterInterfaceMethodModifier(CoriumParser::InterfaceMethodModifierContext * /*ctx*/) override { }
  virtual void exitInterfaceMethodModifier(CoriumParser::InterfaceMethodModifierContext * /*ctx*/) override { }

  virtual void enterGenericInterfaceMethodDeclaration(CoriumParser::GenericInterfaceMethodDeclarationContext * /*ctx*/) override { }
  virtual void exitGenericInterfaceMethodDeclaration(CoriumParser::GenericInterfaceMethodDeclarationContext * /*ctx*/) override { }

  virtual void enterVariableDeclarators(CoriumParser::VariableDeclaratorsContext * /*ctx*/) override { }
  virtual void exitVariableDeclarators(CoriumParser::VariableDeclaratorsContext * /*ctx*/) override { }

  virtual void enterVariableDeclarator(CoriumParser::VariableDeclaratorContext * /*ctx*/) override { }
  virtual void exitVariableDeclarator(CoriumParser::VariableDeclaratorContext * /*ctx*/) override { }

  virtual void enterVariableDeclaratorId(CoriumParser::VariableDeclaratorIdContext * /*ctx*/) override { }
  virtual void exitVariableDeclaratorId(CoriumParser::VariableDeclaratorIdContext * /*ctx*/) override { }

  virtual void enterVariableInitializer(CoriumParser::VariableInitializerContext * /*ctx*/) override { }
  virtual void exitVariableInitializer(CoriumParser::VariableInitializerContext * /*ctx*/) override { }

  virtual void enterArrayInitializer(CoriumParser::ArrayInitializerContext * /*ctx*/) override { }
  virtual void exitArrayInitializer(CoriumParser::ArrayInitializerContext * /*ctx*/) override { }

  virtual void enterClassOrInterfaceType(CoriumParser::ClassOrInterfaceTypeContext * /*ctx*/) override { }
  virtual void exitClassOrInterfaceType(CoriumParser::ClassOrInterfaceTypeContext * /*ctx*/) override { }

  virtual void enterTypeArgument(CoriumParser::TypeArgumentContext * /*ctx*/) override { }
  virtual void exitTypeArgument(CoriumParser::TypeArgumentContext * /*ctx*/) override { }

  virtual void enterQualifiedNameList(CoriumParser::QualifiedNameListContext * /*ctx*/) override { }
  virtual void exitQualifiedNameList(CoriumParser::QualifiedNameListContext * /*ctx*/) override { }

  virtual void enterFormalParameters(CoriumParser::FormalParametersContext * /*ctx*/) override { }
  virtual void exitFormalParameters(CoriumParser::FormalParametersContext * /*ctx*/) override { }

  virtual void enterFormalParameterList(CoriumParser::FormalParameterListContext * /*ctx*/) override { }
  virtual void exitFormalParameterList(CoriumParser::FormalParameterListContext * /*ctx*/) override { }

  virtual void enterFormalParameter(CoriumParser::FormalParameterContext * /*ctx*/) override { }
  virtual void exitFormalParameter(CoriumParser::FormalParameterContext * /*ctx*/) override { }

  virtual void enterLastFormalParameter(CoriumParser::LastFormalParameterContext * /*ctx*/) override { }
  virtual void exitLastFormalParameter(CoriumParser::LastFormalParameterContext * /*ctx*/) override { }

  virtual void enterQualifiedName(CoriumParser::QualifiedNameContext * /*ctx*/) override { }
  virtual void exitQualifiedName(CoriumParser::QualifiedNameContext * /*ctx*/) override { }

  virtual void enterLiteral(CoriumParser::LiteralContext * /*ctx*/) override { }
  virtual void exitLiteral(CoriumParser::LiteralContext * /*ctx*/) override { }

  virtual void enterIntegerLiteral(CoriumParser::IntegerLiteralContext * /*ctx*/) override { }
  virtual void exitIntegerLiteral(CoriumParser::IntegerLiteralContext * /*ctx*/) override { }

  virtual void enterFloatLiteral(CoriumParser::FloatLiteralContext * /*ctx*/) override { }
  virtual void exitFloatLiteral(CoriumParser::FloatLiteralContext * /*ctx*/) override { }

  virtual void enterAltAnnotationQualifiedName(CoriumParser::AltAnnotationQualifiedNameContext * /*ctx*/) override { }
  virtual void exitAltAnnotationQualifiedName(CoriumParser::AltAnnotationQualifiedNameContext * /*ctx*/) override { }

  virtual void enterAnnotation(CoriumParser::AnnotationContext * /*ctx*/) override { }
  virtual void exitAnnotation(CoriumParser::AnnotationContext * /*ctx*/) override { }

  virtual void enterElementValuePairs(CoriumParser::ElementValuePairsContext * /*ctx*/) override { }
  virtual void exitElementValuePairs(CoriumParser::ElementValuePairsContext * /*ctx*/) override { }

  virtual void enterElementValuePair(CoriumParser::ElementValuePairContext * /*ctx*/) override { }
  virtual void exitElementValuePair(CoriumParser::ElementValuePairContext * /*ctx*/) override { }

  virtual void enterElementValue(CoriumParser::ElementValueContext * /*ctx*/) override { }
  virtual void exitElementValue(CoriumParser::ElementValueContext * /*ctx*/) override { }

  virtual void enterElementValueArrayInitializer(CoriumParser::ElementValueArrayInitializerContext * /*ctx*/) override { }
  virtual void exitElementValueArrayInitializer(CoriumParser::ElementValueArrayInitializerContext * /*ctx*/) override { }

  virtual void enterAnnotationTypeDeclaration(CoriumParser::AnnotationTypeDeclarationContext * /*ctx*/) override { }
  virtual void exitAnnotationTypeDeclaration(CoriumParser::AnnotationTypeDeclarationContext * /*ctx*/) override { }

  virtual void enterAnnotationTypeBody(CoriumParser::AnnotationTypeBodyContext * /*ctx*/) override { }
  virtual void exitAnnotationTypeBody(CoriumParser::AnnotationTypeBodyContext * /*ctx*/) override { }

  virtual void enterAnnotationTypeElementDeclaration(CoriumParser::AnnotationTypeElementDeclarationContext * /*ctx*/) override { }
  virtual void exitAnnotationTypeElementDeclaration(CoriumParser::AnnotationTypeElementDeclarationContext * /*ctx*/) override { }

  virtual void enterAnnotationTypeElementRest(CoriumParser::AnnotationTypeElementRestContext * /*ctx*/) override { }
  virtual void exitAnnotationTypeElementRest(CoriumParser::AnnotationTypeElementRestContext * /*ctx*/) override { }

  virtual void enterAnnotationMethodOrConstantRest(CoriumParser::AnnotationMethodOrConstantRestContext * /*ctx*/) override { }
  virtual void exitAnnotationMethodOrConstantRest(CoriumParser::AnnotationMethodOrConstantRestContext * /*ctx*/) override { }

  virtual void enterAnnotationMethodRest(CoriumParser::AnnotationMethodRestContext * /*ctx*/) override { }
  virtual void exitAnnotationMethodRest(CoriumParser::AnnotationMethodRestContext * /*ctx*/) override { }

  virtual void enterAnnotationConstantRest(CoriumParser::AnnotationConstantRestContext * /*ctx*/) override { }
  virtual void exitAnnotationConstantRest(CoriumParser::AnnotationConstantRestContext * /*ctx*/) override { }

  virtual void enterDefaultValue(CoriumParser::DefaultValueContext * /*ctx*/) override { }
  virtual void exitDefaultValue(CoriumParser::DefaultValueContext * /*ctx*/) override { }

  virtual void enterBlock(CoriumParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(CoriumParser::BlockContext * /*ctx*/) override { }

  virtual void enterBlockStatement(CoriumParser::BlockStatementContext * /*ctx*/) override { }
  virtual void exitBlockStatement(CoriumParser::BlockStatementContext * /*ctx*/) override { }

  virtual void enterLocalVariableDeclaration(CoriumParser::LocalVariableDeclarationContext * /*ctx*/) override { }
  virtual void exitLocalVariableDeclaration(CoriumParser::LocalVariableDeclarationContext * /*ctx*/) override { }

  virtual void enterLocalTypeDeclaration(CoriumParser::LocalTypeDeclarationContext * /*ctx*/) override { }
  virtual void exitLocalTypeDeclaration(CoriumParser::LocalTypeDeclarationContext * /*ctx*/) override { }

  virtual void enterStatement(CoriumParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(CoriumParser::StatementContext * /*ctx*/) override { }

  virtual void enterCatchClause(CoriumParser::CatchClauseContext * /*ctx*/) override { }
  virtual void exitCatchClause(CoriumParser::CatchClauseContext * /*ctx*/) override { }

  virtual void enterCatchType(CoriumParser::CatchTypeContext * /*ctx*/) override { }
  virtual void exitCatchType(CoriumParser::CatchTypeContext * /*ctx*/) override { }

  virtual void enterFinallyBlock(CoriumParser::FinallyBlockContext * /*ctx*/) override { }
  virtual void exitFinallyBlock(CoriumParser::FinallyBlockContext * /*ctx*/) override { }

  virtual void enterResourceSpecification(CoriumParser::ResourceSpecificationContext * /*ctx*/) override { }
  virtual void exitResourceSpecification(CoriumParser::ResourceSpecificationContext * /*ctx*/) override { }

  virtual void enterResources(CoriumParser::ResourcesContext * /*ctx*/) override { }
  virtual void exitResources(CoriumParser::ResourcesContext * /*ctx*/) override { }

  virtual void enterResource(CoriumParser::ResourceContext * /*ctx*/) override { }
  virtual void exitResource(CoriumParser::ResourceContext * /*ctx*/) override { }

  virtual void enterSwitchBlockStatementGroup(CoriumParser::SwitchBlockStatementGroupContext * /*ctx*/) override { }
  virtual void exitSwitchBlockStatementGroup(CoriumParser::SwitchBlockStatementGroupContext * /*ctx*/) override { }

  virtual void enterSwitchLabel(CoriumParser::SwitchLabelContext * /*ctx*/) override { }
  virtual void exitSwitchLabel(CoriumParser::SwitchLabelContext * /*ctx*/) override { }

  virtual void enterForControl(CoriumParser::ForControlContext * /*ctx*/) override { }
  virtual void exitForControl(CoriumParser::ForControlContext * /*ctx*/) override { }

  virtual void enterForInit(CoriumParser::ForInitContext * /*ctx*/) override { }
  virtual void exitForInit(CoriumParser::ForInitContext * /*ctx*/) override { }

  virtual void enterEnhancedForControl(CoriumParser::EnhancedForControlContext * /*ctx*/) override { }
  virtual void exitEnhancedForControl(CoriumParser::EnhancedForControlContext * /*ctx*/) override { }

  virtual void enterParExpression(CoriumParser::ParExpressionContext * /*ctx*/) override { }
  virtual void exitParExpression(CoriumParser::ParExpressionContext * /*ctx*/) override { }

  virtual void enterExpressionList(CoriumParser::ExpressionListContext * /*ctx*/) override { }
  virtual void exitExpressionList(CoriumParser::ExpressionListContext * /*ctx*/) override { }

  virtual void enterMethodCall(CoriumParser::MethodCallContext * /*ctx*/) override { }
  virtual void exitMethodCall(CoriumParser::MethodCallContext * /*ctx*/) override { }

  virtual void enterExpression(CoriumParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(CoriumParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterLambdaExpression(CoriumParser::LambdaExpressionContext * /*ctx*/) override { }
  virtual void exitLambdaExpression(CoriumParser::LambdaExpressionContext * /*ctx*/) override { }

  virtual void enterLambdaParameters(CoriumParser::LambdaParametersContext * /*ctx*/) override { }
  virtual void exitLambdaParameters(CoriumParser::LambdaParametersContext * /*ctx*/) override { }

  virtual void enterLambdaBody(CoriumParser::LambdaBodyContext * /*ctx*/) override { }
  virtual void exitLambdaBody(CoriumParser::LambdaBodyContext * /*ctx*/) override { }

  virtual void enterPrimary(CoriumParser::PrimaryContext * /*ctx*/) override { }
  virtual void exitPrimary(CoriumParser::PrimaryContext * /*ctx*/) override { }

  virtual void enterClassType(CoriumParser::ClassTypeContext * /*ctx*/) override { }
  virtual void exitClassType(CoriumParser::ClassTypeContext * /*ctx*/) override { }

  virtual void enterCreator(CoriumParser::CreatorContext * /*ctx*/) override { }
  virtual void exitCreator(CoriumParser::CreatorContext * /*ctx*/) override { }

  virtual void enterCreatedName(CoriumParser::CreatedNameContext * /*ctx*/) override { }
  virtual void exitCreatedName(CoriumParser::CreatedNameContext * /*ctx*/) override { }

  virtual void enterInnerCreator(CoriumParser::InnerCreatorContext * /*ctx*/) override { }
  virtual void exitInnerCreator(CoriumParser::InnerCreatorContext * /*ctx*/) override { }

  virtual void enterArrayCreatorRest(CoriumParser::ArrayCreatorRestContext * /*ctx*/) override { }
  virtual void exitArrayCreatorRest(CoriumParser::ArrayCreatorRestContext * /*ctx*/) override { }

  virtual void enterClassCreatorRest(CoriumParser::ClassCreatorRestContext * /*ctx*/) override { }
  virtual void exitClassCreatorRest(CoriumParser::ClassCreatorRestContext * /*ctx*/) override { }

  virtual void enterExplicitGenericInvocation(CoriumParser::ExplicitGenericInvocationContext * /*ctx*/) override { }
  virtual void exitExplicitGenericInvocation(CoriumParser::ExplicitGenericInvocationContext * /*ctx*/) override { }

  virtual void enterTypeArgumentsOrDiamond(CoriumParser::TypeArgumentsOrDiamondContext * /*ctx*/) override { }
  virtual void exitTypeArgumentsOrDiamond(CoriumParser::TypeArgumentsOrDiamondContext * /*ctx*/) override { }

  virtual void enterNonWildcardTypeArgumentsOrDiamond(CoriumParser::NonWildcardTypeArgumentsOrDiamondContext * /*ctx*/) override { }
  virtual void exitNonWildcardTypeArgumentsOrDiamond(CoriumParser::NonWildcardTypeArgumentsOrDiamondContext * /*ctx*/) override { }

  virtual void enterNonWildcardTypeArguments(CoriumParser::NonWildcardTypeArgumentsContext * /*ctx*/) override { }
  virtual void exitNonWildcardTypeArguments(CoriumParser::NonWildcardTypeArgumentsContext * /*ctx*/) override { }

  virtual void enterTypeList(CoriumParser::TypeListContext * /*ctx*/) override { }
  virtual void exitTypeList(CoriumParser::TypeListContext * /*ctx*/) override { }

  virtual void enterTypeType(CoriumParser::TypeTypeContext * /*ctx*/) override { }
  virtual void exitTypeType(CoriumParser::TypeTypeContext * /*ctx*/) override { }

  virtual void enterPrimitiveType(CoriumParser::PrimitiveTypeContext * /*ctx*/) override { }
  virtual void exitPrimitiveType(CoriumParser::PrimitiveTypeContext * /*ctx*/) override { }

  virtual void enterTypeArguments(CoriumParser::TypeArgumentsContext * /*ctx*/) override { }
  virtual void exitTypeArguments(CoriumParser::TypeArgumentsContext * /*ctx*/) override { }

  virtual void enterSuperSuffix(CoriumParser::SuperSuffixContext * /*ctx*/) override { }
  virtual void exitSuperSuffix(CoriumParser::SuperSuffixContext * /*ctx*/) override { }

  virtual void enterExplicitGenericInvocationSuffix(CoriumParser::ExplicitGenericInvocationSuffixContext * /*ctx*/) override { }
  virtual void exitExplicitGenericInvocationSuffix(CoriumParser::ExplicitGenericInvocationSuffixContext * /*ctx*/) override { }

  virtual void enterArguments(CoriumParser::ArgumentsContext * /*ctx*/) override { }
  virtual void exitArguments(CoriumParser::ArgumentsContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

