
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

  virtual void enterLocalVariableDeclaration(CoriumParser::LocalVariableDeclarationContext * /*ctx*/) override { }
  virtual void exitLocalVariableDeclaration(CoriumParser::LocalVariableDeclarationContext * /*ctx*/) override { }

  virtual void enterLiteral(CoriumParser::LiteralContext * /*ctx*/) override { }
  virtual void exitLiteral(CoriumParser::LiteralContext * /*ctx*/) override { }

  virtual void enterIntLiteral(CoriumParser::IntLiteralContext * /*ctx*/) override { }
  virtual void exitIntLiteral(CoriumParser::IntLiteralContext * /*ctx*/) override { }

  virtual void enterFloatLiteral(CoriumParser::FloatLiteralContext * /*ctx*/) override { }
  virtual void exitFloatLiteral(CoriumParser::FloatLiteralContext * /*ctx*/) override { }

  virtual void enterPrimitiveType(CoriumParser::PrimitiveTypeContext * /*ctx*/) override { }
  virtual void exitPrimitiveType(CoriumParser::PrimitiveTypeContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

