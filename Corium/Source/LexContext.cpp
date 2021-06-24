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
	
	auto LexContext::EvalChar(const char8_t x) -> void
	{
		TokenStream& result{ this->Output_ };
		
		switch (x)
		{
			case static_cast<char8_t>(Operator::Equals):
				result.emplace_back(Operator::Equals);
				return;

			case static_cast<char8_t>(Operator::Comma):
				result.emplace_back(Operator::Comma);
				return;

			case static_cast<char8_t>(Operator::Addition):
				result.emplace_back(Operator::Addition);
				return;

			case static_cast<char8_t>(Operator::Subtraction):
				result.emplace_back(Operator::Subtraction);
				return;

			case static_cast<char8_t>(Operator::Multiplication):
				result.emplace_back(Operator::Multiplication);
				return;

			case static_cast<char8_t>(Operator::Division):
				result.emplace_back(Operator::Division);
				return;

			case static_cast<char8_t>(Operator::Modulo):
				result.emplace_back(Operator::Modulo);
				return;

			case static_cast<char8_t>(Operator::And):
				result.emplace_back(Operator::And);
				return;

			case static_cast<char8_t>(Operator::Or):
				result.emplace_back(Operator::Or);
				return;
			
			case static_cast<char8_t>(Operator::Xor):
				result.emplace_back(Operator::Xor);
				return;

			case static_cast<char8_t>(Operator::Complement):
				result.emplace_back(Operator::Complement);
				return;

			case static_cast<char8_t>(Operator::Not):
				result.emplace_back(Operator::Not);
				return;

			case static_cast<char8_t>(Operator::Less):
				result.emplace_back(Operator::Less);
				return;

			case static_cast<char8_t>(Operator::Greater):
				result.emplace_back(Operator::Greater);
				return;
			
			case static_cast<char8_t>(MonoLexeme::ParenthesisLeft):
				this->ParseAndSubmitIdentifier();
				result.emplace_back(MonoLexeme::ParenthesisLeft);
			return;

			case static_cast<char8_t>(MonoLexeme::ParenthesisRight):
				this->ParseAndSubmitIdentifier();
				result.emplace_back(MonoLexeme::ParenthesisRight);
			return;

			case static_cast<char8_t>(MonoLexeme::CurlyBracesLeft):
				this->ParseAndSubmitIdentifier();
				result.emplace_back(MonoLexeme::CurlyBracesLeft);
			return;
				
			case static_cast<char8_t>(MonoLexeme::CurlyBracesRight):
				this->ParseAndSubmitIdentifier();
				result.emplace_back(MonoLexeme::CurlyBracesRight);
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
		std::for_each(std::begin(sourceText), std::end(sourceText), [this](const char8_t x)
		{
			this->EvalChar(x);
		});
	}
}
