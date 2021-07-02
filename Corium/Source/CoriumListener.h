
// Generated from Corium.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "CoriumParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by CoriumParser.
 */
class  CoriumListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterR(CoriumParser::RContext *ctx) = 0;
  virtual void exitR(CoriumParser::RContext *ctx) = 0;


};

