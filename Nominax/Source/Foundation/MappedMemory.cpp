#include "../../../Nominax/Include/Nominax/Foundation/MappedMemory.hpp"
#include "../../../Nominax/Include/Nominax/Foundation/PanicAssertions.hpp"

namespace Nominax::Foundation
{
    MappedMemory::MappedMemory(const std::uint64_t size, const MemoryPageProtectionFlags flags, const bool lockedProtection)
    {
        NOX_PAS_NOT_ZERO(size, "Memory mapping with zero size requested!");
        void* const region { VMM::VirtualAlloc(size, flags, lockedProtection) };
        NOX_PAS_NOT_NULL(region, "Virtual memory allocation failed!");
        this->Region_ = region;
        const bool result { VMM::MapHeaderFromRegion(region, this->Header_) };
        NOX_PAS_TRUE(result, "Header mapping for memory mapping failed!");
    }

    MappedMemory::~MappedMemory()
    {
        const bool result { VMM::VirtualDealloc(this->Region_) };
        NOX_PAS_TRUE(result, "Virtual memory deallocation failed!");
    }
}
