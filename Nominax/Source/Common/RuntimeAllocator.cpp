#include "../../Include/Nominax/Common/RuntimeAllocator.hpp"

#include <cstdlib>

namespace Nominax::Common
{
	auto RuntimeAllocator::Allocate(void*& out, const std::size_t size) const noexcept(true) -> void
	{
		out = &*static_cast<U8*>(std::malloc(size));
	}

	auto RuntimeAllocator::Reallocate(void*& out, const std::size_t size) const noexcept(true) -> void
	{
		out = &*static_cast<U8*>(std::realloc(out, size));
	}

	auto RuntimeAllocator::Deallocate(void*& out) const noexcept(true) -> void
	{
		std::free(out);
		out = nullptr;
	}

	auto RuntimeAllocator::AllocateAligned(void*& out, const std::size_t size, const std::size_t alignment) const noexcept(true) -> void
	{
		out = &*static_cast<U8*>(_aligned_malloc(size, alignment));
	}

	auto RuntimeAllocator::ReallocateAligned(void*& out, const std::size_t size, const std::size_t alignment) const noexcept(true) -> void
	{
		out = &*static_cast<U8*>(_aligned_realloc(out, size, alignment));
	}

	auto RuntimeAllocator::DeallocateAligned(void*& out) const noexcept(true) -> void
	{
		_aligned_free(out);
		out = nullptr;
	}
}
