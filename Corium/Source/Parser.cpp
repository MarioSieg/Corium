#include "Parser.hpp"

using namespace Nominax;

namespace Corium
{
	auto ParseFile(Common::TextFile&& file) noexcept(false) -> ParseResult
	{
		file.ParallelEraseSpacesAndControlChars();
		if (NOMINAX_UNLIKELY(file.IsEmpty()))
		{
			return { {}, ParseResultCode::EmptyFile };
		}

		Print(Common::TextColor::BrightMagenta, "{}\n\n", reinterpret_cast<const char*>(file.GetContentText().c_str()));

		const auto& text{ file.GetContentText() };

		// String to store identifiers in:
		Identifier identBuffer{};
		identBuffer.reserve(128);

		// Result:
		ParseTree result{};

		// Raw iterators:
		const char8_t* __restrict__ i{ &*std::begin(text) };
		const char8_t* __restrict const end{ &*std::end(text) };

		auto endIdentifier = [&]
		{
			if (!identBuffer.empty())
			{
				result.emplace_back(std::move(identBuffer));
				identBuffer = {};
			}
		};

		for (; i < end; ++i)
		{
			switch (*i)
			{
				case static_cast<char8_t>(MonoLexeme::ParenthesisLeft) :
					endIdentifier();
					result.emplace_back(MonoLexeme::ParenthesisLeft);
				break;

				case static_cast<char8_t>(MonoLexeme::ParenthesisRight):
					endIdentifier();
					result.emplace_back(MonoLexeme::ParenthesisRight);
				break;

				case static_cast<char8_t>(MonoLexeme::CurlyBracesLeft):
					endIdentifier();
					result.emplace_back(MonoLexeme::CurlyBracesLeft);
				break;

				case static_cast<char8_t>(MonoLexeme::CurlyBracesRight):
					endIdentifier();
					result.emplace_back(MonoLexeme::CurlyBracesRight);
				break;

				default:
					identBuffer.push_back(*i);
			}
		}

		// Print parse tree:
		for (const Lexeme& x : result)
		{
			PrintLexeme(x);
		}

		return { result, ParseResultCode::Ok };
	}
}
