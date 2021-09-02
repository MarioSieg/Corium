#pragma once

#include <type_traits>
#include <cstring>

#include "VirtualPageAllocator.hpp"

namespace Nominax::Foundation
{
    class MappedMemory final
    {
        void* Region_;
        VirtualAllocationHeader* Header_;

    public:
        explicit MappedMemory
        (
            std::uint64_t size,
            MemoryPageProtectionFlags flags = MemoryPageProtectionFlags::ReadWrite,
            bool lockedProtection = false
        );
        MappedMemory(const MappedMemory& other) = delete;
        MappedMemory(MappedMemory&& other) = delete;
        auto operator =(const MappedMemory& other) -> MappedMemory& = delete;
        auto operator =(MappedMemory&& other) -> MappedMemory& = delete;
        ~MappedMemory();

        [[nodiscard]] auto GetRegion() const -> void*;
        [[nodiscard]] auto GetHeader() const -> const VirtualAllocationHeader&;
        [[nodiscard]] auto GetSize() const -> std::uint64_t;
        [[nodiscard]] auto GetProtectionFlags() const -> MemoryPageProtectionFlags;
        [[nodiscard]] auto IsLocked() const -> bool;

        auto SetLock() const -> void;
        auto DirtyPages() const -> void;
        auto MemSet(std::uint8_t value, std::uint64_t offset = 0) const -> void;

        template <typename T> requires std::is_standard_layout_v<T>
        [[nodiscard]]
        auto QueryRegion() -> T&;
    };

    inline auto MappedMemory::GetRegion() const -> void*
    {
        return this->Region_;
    }

    inline auto MappedMemory::GetHeader() const -> const VirtualAllocationHeader&
    {
        return *this->Header_;
    }

    inline auto MappedMemory::GetSize() const -> std::uint64_t
    {
        return this->Header_->Size;
    }

    inline auto MappedMemory::GetProtectionFlags() const -> MemoryPageProtectionFlags
    {
        return this->Header_->ProtectionFlags;
    }

    inline auto MappedMemory::IsLocked() const -> bool
    {
        return this->Header_->IsLocked();
    }

    template<typename T> requires std::is_standard_layout_v<T>
    inline auto MappedMemory::QueryRegion() -> T&
    {
        return *static_cast<T*>(this->Region_);
    }

    inline auto MappedMemory::SetLock() const -> void
    {
        this->Header_->SetLock();
    }

    inline auto MappedMemory::DirtyPages() const -> void
    {
        std::memset(this->Region_, 0, this->GetSize());
    }

    inline auto MappedMemory::MemSet(const std::uint8_t value, const std::uint64_t offset) const -> void
    {
        std::memset(static_cast<std::uint8_t*>(this->Region_) + offset, value, this->GetSize());
    }
}
