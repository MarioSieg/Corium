#include <algorithm>
#include <execution>

#include "Parser.hpp"

namespace Corium
{
	auto PerformSemanticErrorAnalysis(const std::span<const Token> tokenStream) -> std::optional<std::string>
	{
		std::for_each(std::begin(tokenStream), std::end(tokenStream), [](const Token& where)
		{
			
		});
	}
}
