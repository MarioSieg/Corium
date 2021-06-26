#include "Parser.hpp"

namespace Corium
{
    template<class... Ts> struct Overload : Ts...
    {
        using Ts::operator()...;
    };

    template<class... Ts> Overload(Ts...) -> Overload<Ts...>;

    auto Parse(const std::span<const Token> tokenStream, const std::span<const U16> lines) -> ParseError
    {
        std::string errorMessage { };

        for (std::size_t i = 0; i < std::size(tokenStream); ++i)
        {
            const auto& c{tokenStream[i]};

            const auto nextAt
            {
                [&tokenStream, i](const std::size_t offset) -> const Token&
                {
                    return tokenStream[i + offset];
                }
            };

            const auto hasNext
            {
                [i, size = std::size(tokenStream)](const std::size_t count) -> bool
                {
                    return i + count < size;
                }
            };

            const auto nextAtChecked
            {
                [&nextAt, hasNext](const std::size_t offset) -> const Token*
                {
                    return hasNext(offset) ? &nextAt(offset) : nullptr;
                }
            };

            const auto makeParseError
            {
                [&errorMessage, lines, i](const auto message, auto&&... format)
                {
                    const auto formattedMessage {Common::Format(message, format...)};
                    errorMessage = Common::Format("Syntax error in line {}:\n{}", lines[i], formattedMessage);
                }
            };

            if (NOMINAX_UNLIKELY(!std::empty(errorMessage)))
            {
                break;
            }

            std::visit
            (
                Overload
                {
                    []([[maybe_unused]] const MonoLexeme monoLexeme)
                    {

                    },
                    []([[maybe_unused]] const Identifier& identifier)
                    {

                    },
                    [&]([[maybe_unused]] const Keyword keyword)
                    {
                        switch (keyword)
                        {
                            /*
                             * A simple function is made out of 3 parts:
                             * fun <name> ()
                             * optionally with parameters:
                             * fun <name> (<params, ...>)
                             * and with return type:
                             * fun <name> (<params, ...>) <returns>
                             */
                            case Keyword::Fun:
                            {
                                const Token* const functionName {nextAtChecked(1)};
                                if (NOMINAX_UNLIKELY(!functionName))
                                {
                                    makeParseError("Expected function name");
                                    return;
                                }
                                if (const Identifier* const identifier {std::get_if<Identifier>(functionName)}; NOMINAX_UNLIKELY(!identifier))
                                {
                                    makeParseError("Expected function name");
                                    return;
                                }

                                const Token* const leftParen {nextAtChecked(2)};
                                if (NOMINAX_UNLIKELY(!leftParen))
                                {
                                    makeParseError("Expected '{}'", static_cast<char>(MonoLexeme::ParenthesisLeft));
                                    return;
                                }
                                if (const MonoLexeme* const lexeme {std::get_if<MonoLexeme>(leftParen)}; NOMINAX_UNLIKELY(!lexeme || *lexeme != MonoLexeme::ParenthesisLeft))
                                {
                                    makeParseError("Expected '{}'", static_cast<char>(MonoLexeme::ParenthesisLeft));
                                    return;
                                }

                                const Token* const rightParen {nextAtChecked(3)};
                                if (NOMINAX_UNLIKELY(!rightParen))
                                {
                                    makeParseError("Expected '{}'", static_cast<char>(MonoLexeme::ParenthesisRight));
                                    return;
                                }
                                if (const MonoLexeme* const lexeme {std::get_if<MonoLexeme>(rightParen)}; NOMINAX_UNLIKELY(!lexeme || *lexeme != MonoLexeme::ParenthesisRight))
                                {
                                    makeParseError("Expected '{}'", static_cast<char>(MonoLexeme::ParenthesisRight));
                                    return;
                                }
                            }
                            break;

                            case Keyword::Let:

                            break;

                            default: ;
                        }
                    },
                    []([[maybe_unused]] const Operator operateur)
                    {

                    },
                    []([[maybe_unused]] const Literal& literal)
                    {

                    }
                }, c);
        }

        return std::empty(errorMessage) ? std::nullopt : ParseError{ errorMessage };
    }

}