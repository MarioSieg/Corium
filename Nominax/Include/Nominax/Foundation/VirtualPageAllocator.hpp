#pragma once

#include <bit>

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
        std::uintptr_t ProtectionLock {};
        union
        {
            void* Ptr;
            std::uintptr_t Int;
        } UserData {nullptr};

        constexpr auto SetLock() -> void;
        constexpr auto IsLocked() const -> bool;

    private:
        friend struct VMM;

        constexpr auto ComputeLockHash(const void* hashPtr) const -> std::uintptr_t;
        static constexpr auto ComputeRegionStart(void* usrRegion) -> void*;
        static constexpr auto MapHeader(void* region) -> VirtualAllocationHeader&;
        static constexpr std::uintptr_t LOCK_KEY { 0x0DE11EB268bED472 };
    };

    static_assert(std::is_standard_layout_v<VirtualAllocationHeader>);

    constexpr auto VirtualAllocationHeader::IsLocked() const -> bool
    {
        return this->ProtectionLock == this->ComputeLockHash(this);
    }

    constexpr auto VirtualAllocationHeader::SetLock() -> void
    {
        this->ProtectionLock = this->ComputeLockHash(this);
    }

    constexpr auto VirtualAllocationHeader::ComputeLockHash(const void* const hashPtr) const -> std::uintptr_t
    {
        return (std::bit_cast<std::uintptr_t>(hashPtr) << 2) ^ LOCK_KEY ^ this->Size;
    }

    constexpr auto VirtualAllocationHeader::ComputeRegionStart(void* const usrRegion) -> void*
    {
        return static_cast<std::byte*>(usrRegion) - sizeof(VirtualAllocationHeader);
    }

    constexpr auto VirtualAllocationHeader::MapHeader(void* const region) -> VirtualAllocationHeader&
    {
        return *static_cast<VirtualAllocationHeader*>(region);
    }

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

        static auto VirtualAlloc(std::uint64_t size, MemoryPageProtectionFlags flags, bool locked = false) -> void*;
        static auto VirtualDealloc(void* region) -> bool;
        static auto VirtualProtectPages(void* region, MemoryPageProtectionFlags newFlags, bool locked = false) -> bool;
    };
}
