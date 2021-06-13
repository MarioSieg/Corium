#include "../../Include/Nominax/Common/RuntimeAllocator.hpp"
#include "../../Include/Nominax/System/Platform.hpp"

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
#if NOMINAX_OS_WINDOWS
        out = &*static_cast<U8*>(_aligned_malloc(size, alignment));
#else
        out = &*static_cast<U8*>(aligned_alloc(size, alignment));
#endif
	}

    auto RuntimeAllocator::ReallocateAligned([[maybe_unused]] void*& out, [[maybe_unused]] const std::size_t size, [[maybe_unused]] const std::size_t alignment) const noexcept(true) -> void
    {
#if NOMINAX_OS_WINDOWS
		out = &*static_cast<U8*>(_aligned_realloc(out, size, alignment));
#else
        // todo using posix_memalign
        __asm__("int3");
#endif
	}

	auto RuntimeAllocator::DeallocateAligned(void*& out) const noexcept(true) -> void
	{
#if NOMINAX_OS_WINDOWS
		_aligned_free(out);
#else
        std::free(out);
#endif
		out = nullptr;
	}
}
