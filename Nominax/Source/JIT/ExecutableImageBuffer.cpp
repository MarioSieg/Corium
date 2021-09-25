#include "../../Include/Nominax/JIT/ExecutableImageBuffer.hpp"

namespace Nominax::JIT
{
    ExecutableImageBuffer::ExecutableImageBuffer(const std::span<const MachCode> source) :
        Foundation::MappedMemory { std::size(source) * sizeof(MachCode), ALLOCATION_FLAGS },
        Buffer_ { static_cast<const MachCode*>(this->Region_) },
        BufferEnd_ { Buffer_ + GetByteSize() }
    {
        this->MemSet(TRAP);
        std::memcpy(static_cast<MachCode*>(this->Region_), std::data(source), std::size(source) * sizeof(MachCode));
        const bool ok { this->Protect(SECURITY_FLAGS, LOCK_PROTECTION) };
        NOX_PAS_TRUE(ok, "Protection of execbuf failed!");
    }
}
