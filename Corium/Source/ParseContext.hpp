#pragma once

#include "Token.hpp"

namespace Corium
{
    using ParseError = std::optional<std::string>;

    class LexContext;

    class ParseContext final
    {
        ParseError ErrorState_ {std::nullopt };
        std::span<const Token> TokenStreamView_ { };
        std::span<const Token>::iterator Needle_ { nullptr };
        std::span<const Token>::iterator End_ { nullptr };
        std::string_view SourceText_ { };
        U32 CurrentLine_ { };

    public:
        ParseContext() = default;
        explicit ParseContext(const LexContext& lexContext);
        ParseContext(std::span<const Token> tokenView, std::string_view sourceText);
        ParseContext(ParseContext&& other) = default;
        ParseContext(const ParseContext& other) = delete;
        auto operator =(ParseContext&& other) -> ParseContext& = default;
        auto operator =(const ParseContext& other) -> ParseContext& = delete;
        ~ParseContext() = default;

        auto GetNextAt(std::size_t offset) const -> const Token&;
        auto HasNext(std::size_t amount) const -> bool;
        auto GetNextAtOrNull(std::size_t offset) -> const Token*;
        auto Reset(std::span<const Token> tokenView, std::string_view sourceText) -> void;
        auto GetNthLineOfSource(std::size_t lineNumber) const -> std::optional<std::string>;
        auto Parse() -> const ParseError&;
        auto GetErrorState() const -> const ParseError&;
        auto GetTokenStreamView() const -> const std::span<const Token>&;
        auto GetNeedle() const -> std::span<const Token>::iterator;
        auto GetNeedleEnd() const -> std::span<const Token>::iterator;
        auto GetSourceText() const -> std::string_view;
        auto GetCurrentLine() const -> U32;
        template <typename T, typename... Ts>
        auto MakeParseError(T&& format, Ts&&... args) -> const ParseError&;
        auto FormatAndSetParseError(std::string&& userMessage) -> const ParseError&;

        auto ParseProxy_MonoLexeme(MonoLexeme monoLexeme) -> void;
        auto ParseProxy_Identifier(const Identifier& identifier) -> void;
        auto ParseProxy_Keyword(Keyword keyword) -> void;
        auto ParseProxy_Operator(Operator operateur) -> void;
        auto ParseProxy_Literal(const Literal& literal) -> void;

        auto ParseFunction() -> void;
    };

    inline auto ParseContext::GetErrorState() const -> const ParseError&
    {
        return this->ErrorState_;
    }

    inline auto ParseContext::GetTokenStreamView() const -> const std::span<const Token>&
    {
        return this->TokenStreamView_;
    }

    inline auto ParseContext::GetNeedle() const -> std::span<const Token>::iterator
    {
        return this->Needle_;
    }

    inline auto ParseContext::GetNeedleEnd() const -> std::span<const Token>::iterator
    {
        return this->End_;
    }

    inline auto ParseContext::GetNextAt(const std::size_t offset) const -> const Token&
    {
        return this->Needle_[offset];
    }

    inline auto ParseContext::HasNext(const std::size_t amount) const -> bool
    {
        return this->Needle_ + amount < this->End_;
    }

    inline auto ParseContext::GetNextAtOrNull(const std::size_t offset) -> const Token*
    {
        return this->HasNext(offset) ? &this->GetNextAt(offset) : nullptr;
    }

    template<typename T, typename... Ts>
    inline auto ParseContext::MakeParseError(T&& format, Ts&&... args) -> const ParseError&
    {
        std::string formattedMessage{Common::Format(std::forward<T>(format), std::forward<Ts>(args)...)};
        return this->FormatAndSetParseError(std::move(formattedMessage));
    }

    inline auto ParseContext::GetSourceText() const -> std::string_view
    {
        return this->SourceText_;
    }

    inline auto ParseContext::GetCurrentLine() const -> U32
    {
        return this->CurrentLine_;
    }

    extern auto Parse(std::span<const Token> tokenStream, std::span<const U16> lines) -> ParseError;
}