#include "../../Include/Nominax/JIT/ExecutableBuffer.hpp"

namespace Nominax::JIT
{
    ExecutableBuffer::ExecutableBuffer(const std::span<const std::uint8_t> source) :
        Foundation::MappedMemory { std::size(source), ALLOCATION_FLAGS },
        Buffer_ { static_cast<const MachCode*>(this->Region_) },
        BufferEnd_ { Buffer_ + GetByteSize() }
    {
        this->MemSet(TRAP);
        std::memcpy(static_cast<MachCode*>(this->Region_), std::data(source), std::size(source));
        const bool ok { this->Protect(SECURITY_FLAGS, LOCK_PROTECTION) };
        NOX_PAS_TRUE(ok, "Protection of execbuf failed!");
    }
}
