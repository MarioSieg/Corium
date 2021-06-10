#include "../../Include/Nominax/Common/DebugAllocator.hpp"
#include "../../Include/Nominax/Common/Protocol.hpp"

namespace Nominax::Common
{
	auto DebugAllocator::Allocate(void*& out, const std::size_t size) const noexcept(true) -> void
	{
		Print(TextColor::BrightGreen, "Allocate({}, {} B)\n", out, size);
		RuntimeAllocator::Allocate(out, size);
		++this->Allocations_;
		this->BytesAllocated_ += size;
	}

	auto DebugAllocator::Reallocate(void*& out, const std::size_t size) const noexcept(true) -> void
	{
		Print(TextColor::BrightYellow, "Reallocate({}, {} B)\n", out, size);
		RuntimeAllocator::Reallocate(out, size);
		++this->Reallocations_;
	}

	auto DebugAllocator::Deallocate(void*& out) const noexcept(true) -> void
	{
		Print(TextColor::BrightRed, "Deallocate({})\n", out);
		RuntimeAllocator::Deallocate(out);
		++this->Deallocations_;
	}

	auto DebugAllocator::AllocateAligned(void*& out, const std::size_t size, const std::size_t alignment) const noexcept(true) -> void
	{
		Print(TextColor::BrightGreen, "AllocateAligned({}, {} B, {} A)\n", out, size, alignment);
		RuntimeAllocator::AllocateAligned(out, size, alignment);
		++this->Allocations_;
		this->BytesAllocated_ += size;
	}

	auto DebugAllocator::ReallocateAligned(void*& out, const std::size_t size, const std::size_t alignment) const noexcept(true) -> void
	{
		Print(TextColor::BrightYellow, "ReallocateAligned({}, {} B, {} A)\n", out, size, alignment);
		RuntimeAllocator::ReallocateAligned(out, size, alignment);
		++this->Reallocations_;
	}

	auto DebugAllocator::DeallocateAligned(void*& out) const noexcept(true) -> void
	{
		Print(TextColor::BrightRed, "DeallocateAligned({})\n", out);
		RuntimeAllocator::DeallocateAligned(out);
		++this->Deallocations_;
	}

	auto DebugAllocator::DumpAllocationInfo() const noexcept(false) -> void
	{
		Print(TextColor::BrightGreen, "Allocations: {}\n", this->Allocations_);
		Print(TextColor::BrightGreen, "Reallocations: {}\n", this->Reallocations_);
		Print(TextColor::BrightGreen, "Deallocations: {}\n", this->Deallocations_);
		Print(TextColor::BrightGreen, "Total: {:.03F} MB\n", Bytes2Megabytes<F64>(this->BytesAllocated_));
		Print(TextColor::BrightYellow, "Warning! Some memory actions are incoming and that's fine!\n");
	}
}
