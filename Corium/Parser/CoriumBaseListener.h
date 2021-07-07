
// Generated from Corium.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"
#include "CoriumListener.h"


/**
 * This class provides an empty implementation of CoriumListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  CoriumBaseListener : public CoriumListener {
public:

  virtual void enterVariableDeclaration(CoriumParser::VariableDeclarationContext * /*ctx*/) override { }
  virtual void exitVariableDeclaration(CoriumParser::VariableDeclarationContext * /*ctx*/) override { }

  virtual void enterLocalVariableDeclaration(CoriumParser::LocalVariableDeclarationContext * /*ctx*/) override { }
  virtual void exitLocalVariableDeclaration(CoriumParser::LocalVariableDeclarationContext * /*ctx*/) override { }

  virtual void enterConstVariableDeclaration(CoriumParser::ConstVariableDeclarationContext * /*ctx*/) override { }
  virtual void exitConstVariableDeclaration(CoriumParser::ConstVariableDeclarationContext * /*ctx*/) override { }

  virtual void enterLiteral(CoriumParser::LiteralContext * /*ctx*/) override { }
  virtual void exitLiteral(CoriumParser::LiteralContext * /*ctx*/) override { }

  virtual void enterPrimitiveType(CoriumParser::PrimitiveTypeContext * /*ctx*/) override { }
  virtual void exitPrimitiveType(CoriumParser::PrimitiveTypeContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

