#include "../../Include/Nominax/Foundation/VirtualPageAllocator.hpp"
#include "../../Include/Nominax/Foundation/OSInterface.hpp"
#include "../../Include/Nominax/Foundation/PanicAssertions.hpp"

namespace Nominax::Foundation
{
    auto VMM::VirtualAlloc(const std::uint64_t size, const MemoryPageProtectionFlags flags) -> void*
    {
        if (!size)
        {
            [[unlikely]]
            return nullptr;
        }
        void* NOX_RESTRICT const block { OSI::MemoryMap(sizeof(VirtualAllocationHeader) + size, flags) };
        NOX_DBG_PAS_NOT_NULL(block, "Memory mapping failed!");
        auto& header { *static_cast<VirtualAllocationHeader*>(block) };
        header.Size = size;
        header.ProtectionFlags = flags;
        header.UserData.Ptr = nullptr;
        return static_cast<std::byte*>(block) + sizeof(VirtualAllocationHeader);
    }

    auto VMM::VirtualDealloc(void* const allocation) -> bool
    {
        if (!allocation)
        {
            [[unlikely]]
            return false;
        }
        auto* const blockOffset { static_cast<std::byte*>(allocation) - sizeof(VirtualAllocationHeader) };
        auto& header { *reinterpret_cast<VirtualAllocationHeader*>(blockOffset) };
        return OSI::MemoryUnmap(blockOffset, header.Size);
    }

    auto VMM::VirtualProtectPages(void* const allocation, const MemoryPageProtectionFlags newFlags) -> bool
    {
        if (!allocation)
        {
            [[unlikely]]
            return false;
        }
        auto* const blockOffset { static_cast<std::byte*>(allocation) - sizeof(VirtualAllocationHeader) };
        auto& header { *reinterpret_cast<VirtualAllocationHeader*>(blockOffset) };
        const bool result { OSI::MemoryProtect(blockOffset, header.Size, newFlags) };
        if (!result)
        {
            [[unlikely]]
            return false;
        }
        header.ProtectionFlags = newFlags;
        return true;
    }
}
