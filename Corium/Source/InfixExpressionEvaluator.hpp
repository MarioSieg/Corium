#pragma once

#include <stack>
#include <queue>

#include "Token.hpp"

namespace Corium
{
	struct InfixExpressionEvaluator final
	{
		std::queue<Token> Operands {};
		std::stack<Operator> Operators {};
	};
}