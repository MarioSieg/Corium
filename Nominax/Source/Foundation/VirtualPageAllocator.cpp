#include "../../Include/Nominax/Foundation/VirtualPageAllocator.hpp"
#include "../../Include/Nominax/Foundation/OSInterface.hpp"
#include "../../Include/Nominax/Foundation/PanicAssertions.hpp"

namespace Nominax::Foundation
{
    using VAH = VirtualAllocationHeader;

    auto VMM::VirtualAlloc(const std::uint64_t size, const MemoryPageProtectionFlags flags, const bool locked) -> void*
    {
        if (!size)
        {
            [[unlikely]]
            return nullptr;
        }
        void* const block { OSI::MemoryMap(sizeof(VAH) + size, flags) };
        NOX_DBG_PAS_NOT_NULL(block, "Memory mapping failed!");
        auto& header { *static_cast<VAH*>(block) };
        header.Size = size;
        header.ProtectionFlags = flags;
        if (locked)
        {
            header.SetLock(); // The region is now locked, so no more protection flag changes in the future!
        }
        header.UserData.Ptr = nullptr;
        return static_cast<std::byte*>(block) + sizeof(VAH);
    }

    auto VMM::VirtualDealloc(void* const region) -> bool
    {
        if (!region)
        {
            [[unlikely]]
            return false;
        }
        auto* const blockOffset { VAH::ComputeRegionStart(region) };
        auto& header { VAH::MapHeader(blockOffset) };
        return OSI::MemoryUnmap(blockOffset, header.Size);
    }

    auto VMM::VirtualProtectPages(void* const region, const MemoryPageProtectionFlags newFlags, const bool locked) -> bool
    {
        if (!region)
        {
            [[unlikely]]
            return false;
        }
        auto* const blockOffset { VAH::ComputeRegionStart(region) };
        auto& header { VAH::MapHeader(blockOffset) };
        if (header.IsLocked()) // Already locked, we can't change any protection flags...
        {
            return false;
        }
        const bool result { OSI::MemoryProtect(blockOffset, header.Size, newFlags) };
        if (!result)
        {
            [[unlikely]]
            return false;
        }
        header.ProtectionFlags = newFlags;
        if (locked)
        {
            header.SetLock(); // The region is now locked, so no more protection flag changes in the future!
        }
        return true;
    }
}
