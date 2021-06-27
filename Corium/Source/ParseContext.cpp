#include "ParseContext.hpp"

#define UNL NOMINAX_UNLIKELY

namespace Corium
{
    auto ParseContext::Reset(const std::span<const Token> tokenView, const std::span<const U16> lineMapView) -> void
    {
        NOMINAX_PANIC_ASSERT_LE(std::size(tokenView), std::size(lineMapView), "Token view size must be smaller of equal to line view size!");

        this->TokenStreamView_ = tokenView;
        this->LineMapView_ = lineMapView;
        this->ErrorState_ = std::nullopt;
    }

    auto ParseContext::Parse() -> const std::optional<std::string>&
    {
        this->Needle_ = std::begin(this->TokenStreamView_);
        this->End_ = std::end(this->TokenStreamView_);

        for (; this->Needle_ < this->End_ && !this->ErrorState_.has_value(); std::advance(this->Needle_, 1))
        {
            std::visit
            (
                Common::Overload
                {
                    [this](const MonoLexeme monoLexeme)
                    {
                        this->ParseProxy_MonoLexeme(monoLexeme);
                    },
                    [this](const Identifier& identifier)
                    {
                        this->ParseProxy_Identifier(identifier);
                    },
                    [this](const Keyword keyword)
                    {
                        this->ParseProxy_Keyword(keyword);
                    },
                    [this](const Operator operateur)
                    {
                        this->ParseProxy_Operator(operateur);
                    },
                    [this](const Literal& literal)
                    {
                        this->ParseProxy_Literal(literal);
                    }
            }, *this->Needle_);
        }

        return this->ErrorState_;
    }

    auto ParseContext::ParseProxy_MonoLexeme([[maybe_unused]] MonoLexeme monoLexeme) -> void
    {

    }

    auto ParseContext::ParseProxy_Identifier([[maybe_unused]] const Identifier &identifier) -> void
    {

    }

    auto ParseContext::ParseProxy_Keyword(const Keyword keyword) -> void
    {
        switch (keyword)
        {
            case Keyword::Fun:
                this->ParseFunction();
                return;

            default:
                return;
        }
    }

    auto ParseContext::ParseProxy_Operator([[maybe_unused]] const Operator operateur) -> void
    {

    }

    auto ParseContext::ParseProxy_Literal([[maybe_unused]] const Literal &literal) -> void
    {

    }

    auto ParseContext::ParseFunction() -> void
    {
        // validate function name:
        {
            const Token *const functionName{this->GetNextAtOrNull(1)};
            if (UNL(!functionName))
            {
                this->MakeParseError("Expected function name");
                return;
            }

            const Identifier *const identifier{std::get_if<Identifier>(functionName)};
            if (UNL(!identifier))
            {
                this->MakeParseError("Expected function name");
                return;
            }
        }

        // validate parenthesis left
        {
            const Token *const leftParen{this->GetNextAtOrNull(2)};
            if (UNL(!leftParen))
            {
                this->MakeParseError("Expected '{}'",static_cast<char>(MonoLexeme::ParenthesisLeft));
                return;
            }

            const MonoLexeme *const lexeme{std::get_if<MonoLexeme>(leftParen)};
            if (UNL(!lexeme || *lexeme != MonoLexeme::ParenthesisLeft))
            {
                this->MakeParseError("Expected '{}'", static_cast<char>(MonoLexeme::ParenthesisLeft));
                return;
            }
        }

        // validate parenthesis right:
        {
            const Token *const rightParen{this->GetNextAtOrNull(3)};
            if (UNL(!rightParen))
            {
                this->MakeParseError("Expected '{}'", static_cast<char>(MonoLexeme::ParenthesisRight));
                return;
            }

            const MonoLexeme *const lexeme{std::get_if<MonoLexeme>(rightParen)};
            if (UNL(!lexeme || *lexeme != MonoLexeme::ParenthesisRight))
            {
                this->MakeParseError("Expected '{}'", static_cast<char>(MonoLexeme::ParenthesisRight));
                return;
            }
        }
    }
}