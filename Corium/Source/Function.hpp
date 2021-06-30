#pragma once

#include "Token.hpp"

namespace Corium
{
    struct FunctionInfo final
    {
        Identifier Name{};
        TokenStreamView Body{};
    };

    using FunctionTable = std::vector<FunctionInfo>;
}
