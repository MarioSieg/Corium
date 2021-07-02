
// Generated from Corium.g4 by ANTLR 4.7.2

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

  virtual void enterR(CoriumParser::RContext * /*ctx*/) override { }
  virtual void exitR(CoriumParser::RContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

