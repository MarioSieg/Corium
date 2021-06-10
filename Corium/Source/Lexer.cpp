#include "Lexer.hpp"

using namespace Nominax;

namespace Corium
{
	auto LexFile(Common::TextFile&& file) noexcept(false) -> LexResult
	{
		if (NOMINAX_UNLIKELY(file.IsEmpty()))
		{
			return { {}, LexResultCode::EmptyFile };
		}

		Print(Common::TextColor::BrightMagenta, "{}\n\n", reinterpret_cast<const char*>(file.GetContentText().c_str()));

		const auto& text{ file.GetContentText() };

		// String to store identifiers in:
		Identifier identBuffer{};
		identBuffer.reserve(128);

		// Result:
		LexTree result{};

		// Raw iterators:
		const char8_t* __restrict__ iterator{ &*std::begin(text) };
		const char8_t* __restrict__ const end{ &*std::end(text) };

		// Outputs the identifier buffer, if it's not empty.
		const auto endIdentifier = [&]
		{
			if (!identBuffer.empty())
			{
				result.emplace_back(std::move(identBuffer));
				identBuffer = {};
			}
		};

		// Invoked for each char in the code.
		const auto charPredicate = [&](const char8_t x)
		{	
			switch (x)
			{				
				case static_cast<char8_t>(MonoLexeme::ParenthesisLeft):
					std::invoke(endIdentifier);
					result.emplace_back(MonoLexeme::ParenthesisLeft);
					return;
				
				case static_cast<char8_t>(MonoLexeme::ParenthesisRight):
					std::invoke(endIdentifier);
					result.emplace_back(MonoLexeme::ParenthesisRight);
					return;
				
				case static_cast<char8_t>(MonoLexeme::CurlyBracesLeft):
					std::invoke(endIdentifier);
					result.emplace_back(MonoLexeme::CurlyBracesLeft);
					return;
				
				case static_cast<char8_t>(MonoLexeme::CurlyBracesRight):
					std::invoke(endIdentifier);
					result.emplace_back(MonoLexeme::CurlyBracesRight);
					return;
				
				case ' ':
				case '\n':
				case '\t':
				case '\v':
				case '\f':
				case '\r':
					return;
			}

			identBuffer.push_back(*iterator);
		};

		for (bool isComment{ false }; iterator < end; ++iterator)
		{
			const auto current{ *iterator };
			if (current == '#' || current == '\n')
			{
				isComment ^= true;
				continue;
			}

			if (!isComment)
			{
				std::invoke(charPredicate, current);
			}
		}

		// Print parse tree:
		for (const Lexeme& x : result)
		{
			PrintLexeme(x);
		}

		Common::Print('\n');

		return { result, LexResultCode::Ok };
	}
}
