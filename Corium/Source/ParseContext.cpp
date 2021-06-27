#include "ParseContext.hpp"

#define UNL NOMINAX_UNLIKELY

namespace Corium
{
    auto ParseContext::Reset(const std::span<const Token> tokenView, const std::string_view sourceText) -> void
    {
        this->TokenStreamView_ = tokenView;
        this->CurrentLine_ = 1;
        this->ErrorState_ = std::nullopt;
        this->Needle_ = std::begin(this->TokenStreamView_);
        this->End_ = std::end(this->TokenStreamView_);
        this->SourceText_ = sourceText;
    }

    auto ParseContext::Parse() -> const std::optional<std::string>&
    {
        if (UNL(this->Needle_ != std::begin(this->TokenStreamView_) || this->End_ != std::end(this->TokenStreamView_)))
        {
            return this->ErrorState_ = "Invalid needle iterator!";
        }

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

    auto ParseContext::ParseProxy_MonoLexeme(const MonoLexeme monoLexeme) -> void
    {
        switch (monoLexeme)
        {
            case MonoLexeme::NewLine:
                ++this->CurrentLine_;
                return;

            default:
                return;
        }
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

    auto ParseContext::GetNthLineOfSource(const std::size_t lineNumber) const -> std::optional<std::string>
    {
        if (UNL(std::empty(this->SourceText_)))
        {
            return std::nullopt;
        }

        std::stringstream  ss;
        ss.str(std::string{this->SourceText_});

        std::size_t i {1};
        for(std::string temp{}; std::getline(ss, temp); ++i)
        {
            if (i == lineNumber)
            {
                return temp;
            }
        }

        return std::nullopt;
    }

    auto ParseContext::FormatAndSetParseError(std::string&& userMessage) -> const ParseError&
    {
        const U32 line {this->CurrentLine_};
        const std::string errorLine{this->GetNthLineOfSource(this->CurrentLine_).template value_or("?")};
        const std::string lineInfo{Common::Format("Line {}: ", line)};
        std::string message{ Common::Format("Syntax error: {}\n{}\"{}\"\n", userMessage, lineInfo, errorLine)};
        for (std::size_t i{0}; i <= std::size(lineInfo); ++i)
        {
            message.push_back(' ');
        }
        for (std::size_t i{0}; i < std::size(errorLine); ++i)
        {
            message.push_back('^');
        }
        message.push_back('\n');
        return this->ErrorState_ = message;
    }
}