#pragma once

#include "Lexeme.hpp"
#include "Base.hpp"

namespace Corium
{
	enum class LexResultCode
	{
		Ok,
		EmptyFile
	};

	using LexTree = std::vector<Lexeme>;

	using LexResult = std::pair<LexTree, LexResultCode>;
	
	extern auto LexFile(Nominax::Common::TextFile&& file) noexcept(false) -> LexResult;
}
