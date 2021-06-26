#pragma once

#include "Token.hpp"

namespace Corium
{
    using ParseError = std::optional<std::string>;

    extern auto Parse(std::span<const Token> tokenStream, std::span<const U16> lines) -> ParseError;
}