#pragma once

#include "Lexeme.hpp"
#include "Base.hpp"

namespace Corium
{
	enum class ParseResultCode
	{
		Ok,
		EmptyFile
	};

	using ParseTree = std::vector<Lexeme>;

	using ParseResult = std::pair<ParseTree, ParseResultCode>;
	
	extern auto ParseFile(Nominax::Common::TextFile&& file) noexcept(false) -> ParseResult;
}
