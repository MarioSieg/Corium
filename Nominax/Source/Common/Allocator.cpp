#include "../../Include/Nominax/Common/Allocator.hpp"
#include "../../Include/Nominax/System/Platform.hpp"

#if NOMINAX_RELEASE
#include "../../Include/Nominax/Common/RuntimeAllocator.hpp"
#else
#include "../../Include/Nominax/Common/DebugAllocator.hpp"
#endif

namespace Nominax::Common
{
	constinit const IAllocator* GlobalSystemAllocator
	{
#if NOMINAX_RELEASE
		&RUNTIME_ALLOCATOR
#else
		&DEBUG_ALLOCATOR
#endif
	};
	
	auto IAllocator::Valloc(void*& out, const std::size_t size) const  noexcept(true) -> void
	{
		this->Allocate(out, size);
	}

	auto IAllocator::Vdealloc(void*& out) const noexcept(true) -> void
	{
		this->Deallocate(out);
	}
}
