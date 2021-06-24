#pragma once

#include "Token.hpp"

namespace Corium
{
	/// <summary>
	/// Performs an error analysis and returns the error string if any.
	/// </summary>
	/// <param name="tokenStream"></param>
	/// <returns>The string explaining the error, if and error happend, else std::nullopt.</returns>
	extern auto PerformSemanticErrorAnalysis(std::span<const Token> tokenStream) -> std::optional<std::string>;
}
