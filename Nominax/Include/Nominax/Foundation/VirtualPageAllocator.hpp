#pragma once

#include "VirtualPageProtectionFlags.hpp"

namespace Nominax::Foundation
{
    /// <summary>
    /// Header for all virtual allocations.
    /// </summary>
    struct VirtualAllocationHeader final
    {
        std::uint64_t Size {};
        MemoryPageProtectionFlags ProtectionFlags {};
        union
        {
            void* Ptr;
            std::uintptr_t Int;
        } UserData {nullptr};
    };

    /// <summary>
    /// Virtual memory manager.
    /// </summary>
    struct VMM final
    {
        /// <summary>
        /// Static class.
        /// </summary>
        VMM() = delete;

        /// <summary>
        /// Static class.
        /// </summary>
        VMM(const VMM& other) = delete;

        /// <summary>
        /// Static class.
        /// </summary>
        VMM(VMM&& other) = delete;

        /// <summary>
        /// Static class.
        /// </summary>
        auto operator =(const VMM& other) -> VMM& = delete;

        /// <summary>
        /// Static class.
        /// </summary>
        auto operator =(VMM&& other) -> VMM& = delete;

        /// <summary>
        /// Static class.
        /// </summary>
        ~VMM() = delete;

        static auto VirtualAlloc(std::uint64_t size, MemoryPageProtectionFlags flags) -> void*;
        static auto VirtualDealloc(void* allocation) -> bool;
        static auto VirtualProtectPages(void* allocation, MemoryPageProtectionFlags newFlags) -> bool;
    };
}
