#pragma once

#include "Token.hpp"

namespace Corium
{
    using ParseError = std::optional<std::string>;

    class ParseContext final
    {
        ParseError ErrorState_ {std::nullopt };
        std::span<const Token> TokenStreamView_ { };
        std::span<const U16> LineMapView_ { };
        std::span<const Token>::iterator Needle_ { };
        std::span<const Token>::iterator End_ { };

    public:
        auto GetNextAt(std::size_t offset) const -> const Token&;
        auto HasNext(std::size_t amount) const -> bool;
        auto GetNextAtOrNull(std::size_t offset) -> const Token*;
        auto Reset(std::span<const Token> tokenView, std::span<const U16> lineMapView) -> void;
        auto Parse() -> const ParseError&;
        auto GetErrorState() const -> const ParseError&;
        auto GetTokenStreamView() const -> const std::span<const Token>&;
        auto GetNeedle() const -> std::span<const Token>::iterator;

        auto ParseProxy_MonoLexeme(MonoLexeme monoLexeme) -> void;
        auto ParseProxy_Identifier(const Identifier& identifier) -> void;
        auto ParseProxy_Keyword(Keyword keyword) -> void;
        auto ParseProxy_Operator(Operator operateur) -> void;
        auto ParseProxy_Literal(const Literal& literal) -> void;

        auto ParseFunction() -> void;

        template <typename T, typename... Ts>
        auto MakeParseError(T&& format, Ts&&... args) -> const ParseError&;
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
        const auto formattedMessage{Common::Format(std::forward<T>(format), std::forward<Ts>(args)...)};
        const U16 line { this->LineMapView_[std::distance(std::begin(this->TokenStreamView_), this->Needle_)] };
        return this->ErrorState_ = Common::Format("Syntax error in line {}:\n{}", line, formattedMessage);
    }

    extern auto Parse(std::span<const Token> tokenStream, std::span<const U16> lines) -> ParseError;
}