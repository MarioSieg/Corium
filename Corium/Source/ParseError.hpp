#pragma once

#include <array>
#include <string_view>
#include <utility>

#include "Base.hpp"

namespace Corium
{
    /// <summary>
    /// Contains all possible error codes for the parser.
    /// </summary>
    enum class ParseErrorCode: U8
    {
        Ok = 0,
        ContextError,
        MissingParentheses,
        MissingBraces,
        MissingIdentifier,

        $Count
    };

    /// <summary>
    /// Contains all possible error code messages.
    /// </summary>
    constexpr std::array<std::string_view, static_cast<std::size_t>(ParseErrorCode::$Count)> PARSE_ERROR_MESSAGES
    {
        "OK",
        "Internal parse context error!",
        "Missing parenthesis!",
        "Missing brackets!",
        "Missing identifier!"
    };

    /// <summary>
    /// Represents an error state of the parser.
    /// </summary>
    using ParseError = std::pair<ParseErrorCode, std::string>;
}
