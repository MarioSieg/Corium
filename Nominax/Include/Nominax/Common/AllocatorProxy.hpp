#pragma once

#include "Allocator.hpp"
#include "DebugAllocator.hpp"

namespace Nominax::Common
{
    /// <summary>
    /// Currently used allocator.
    /// </summary>
    inline constinit const IAllocator* GlobalAllocatorProxy
    {
#if NOMINAX_DEBUG
        &GlobalDebugAllocator
#else
        &GlobalRuntimeAllocator
#endif
    };
}
