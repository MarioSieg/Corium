#pragma once

#include "Base.hpp"

namespace Corium
{
    /// <summary>
    /// Represents the scope of a declaration.
    /// </summary>
    enum class Scope : U8
    {
        Global,
        Local
    };
}