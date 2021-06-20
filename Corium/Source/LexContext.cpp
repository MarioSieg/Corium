#include "LexContext.hpp"
#include "Literal.hpp"

namespace Corium
{
	LexContext::LexContext(const std::size_t expectedOutputSize, const std::size_t expectedIdentSize)
	{
		this->Output_.reserve(expectedOutputSize);
		this->IdentifierBuffer_.reserve(expectedIdentSize);
	}

	auto LexContext::ParseAndSubmitIdentifier() -> void
	{
		std::u8string& ident{ this->IdentifierBuffer_ };

		if (ident.empty())
		{
			return;
		}

		// check if it's a keyword
		if (const std::optional<Keyword> keyword{ QueryKeyword(ident) }; keyword)
		{
			this->Output_.emplace_back(*keyword);
		}

		// check if it's a "float":
		else if (const std::optional<F64> f{ ConvertFloatLiteral(ident) }; DetermineLiteralType(ident) == EstimatedLiteralType::Float && f)
		{
			this->Output_.emplace_back(Literal{ *f });
		}

		// check if it's an "int":
		else if(const std::optional<I64> i{ ConvertIntLiteral(ident) }; i)
		{
			this->Output_.emplace_back(Literal{ *i });
		}

		// else it's an identifier:
		else
		{
			this->Output_.emplace_back(std::move(ident));
		}
		
		ident.clear();
	}

	namespace Sym
	{
		static constexpr char8_t PARENTHESIS_LEFT{ static_cast<char8_t>(MonoLexeme::ParenthesisLeft) };
		static constexpr char8_t PARENTHESIS_RIGHT{ static_cast<char8_t>(MonoLexeme::ParenthesisRight) };
		static constexpr char8_t CURLY_BRACES_LEFT{ static_cast<char8_t>(MonoLexeme::CurlyBracesLeft) };
		static constexpr char8_t CURLY_BRACES_RIGHT{ static_cast<char8_t>(MonoLexeme::CurlyBracesRight) };
		static constexpr char8_t OPERATOR_ASSIGNMENT{ static_cast<char8_t>(Operator::Assignment) };
	}
	
	auto LexContext::EvalChar(const char8_t x) -> void
	{
		LexTree& result{ this->Output_ };
		
		switch (x)
		{
			case Sym::PARENTHESIS_LEFT:
				this->ParseAndSubmitIdentifier();
				result.emplace_back(MonoLexeme::ParenthesisLeft);
			return;

			case Sym::PARENTHESIS_RIGHT:
				this->ParseAndSubmitIdentifier();
				result.emplace_back(MonoLexeme::ParenthesisRight);
			return;

			case Sym::CURLY_BRACES_LEFT:
				this->ParseAndSubmitIdentifier();
				result.emplace_back(MonoLexeme::CurlyBracesLeft);
			return;
				
			case Sym::CURLY_BRACES_RIGHT:
				this->ParseAndSubmitIdentifier();
				result.emplace_back(MonoLexeme::CurlyBracesRight);
			return;

			case Sym::OPERATOR_ASSIGNMENT:
				result.emplace_back(Operator::Assignment);
			return;

			case u8'\n':
			case u8'\t':
			case u8'\v':
			case u8'\f':
			case u8'\r':
			case u8' ':
				this->ParseAndSubmitIdentifier();
			return;

			default:
				this->IdentifierBuffer_.push_back(x);
		}
	}

	auto LexContext::EvaluateString(const std::u8string_view sourceText) -> void
	{
		for (const char8_t x : sourceText)
		{
			this->EvalChar(x);
		}
	}
}
