#include <new>

#include "../../Include/Nominax/Common/Allocator.hpp"

auto operator new(const std::size_t size) noexcept(false) -> void*
{
	void* mem;
	Nominax::Common::GlobalSystemAllocator->Allocate(mem, size);
	return mem;
}

auto operator new[](const std::size_t size) noexcept(false) -> void*
{
	void* mem;
	Nominax::Common::GlobalSystemAllocator->Allocate(mem, size);
	return mem;
}

auto operator new(const std::size_t size, const std::align_val_t alignment) noexcept(false) -> void*
{
	void* mem;
	Nominax::Common::GlobalSystemAllocator->AllocateAligned(mem, size, static_cast<std::size_t>(alignment));
	return mem;
}

auto operator new[](const std::size_t size, const std::align_val_t alignment) noexcept(false) -> void*
{
	void* mem;
	Nominax::Common::GlobalSystemAllocator->AllocateAligned(mem, size, static_cast<std::size_t>(alignment));
	return mem;
}

auto operator new(const std::size_t size, [[maybe_unused]] const std::nothrow_t& tag) noexcept(true) -> void*
{
	void* mem;
	Nominax::Common::GlobalSystemAllocator->Allocate(mem, size);
	return mem;
}

auto operator new[](const std::size_t size, [[maybe_unused]] const std::nothrow_t& tag) noexcept(true) -> void*
{
	void* mem;
	Nominax::Common::GlobalSystemAllocator->Allocate(mem, size);
	return mem;
}

auto operator new(const std::size_t size, const std::align_val_t alignment, [[maybe_unused]] const std::nothrow_t& tag) noexcept(true) -> void*
{
	void* mem;
	Nominax::Common::GlobalSystemAllocator->AllocateAligned(mem, size, static_cast<std::size_t>(alignment));
	return mem;
}

auto operator new[](const std::size_t size, const std::align_val_t alignment, [[maybe_unused]] const std::nothrow_t& tag) noexcept(true) -> void*
{
	void* mem;
	Nominax::Common::GlobalSystemAllocator->AllocateAligned(mem, size, static_cast<std::size_t>(alignment));
	return mem;
}

auto operator delete(void* mem) noexcept(true) -> void
{
	Nominax::Common::GlobalSystemAllocator->Deallocate(mem);
}

auto operator delete[](void* mem) noexcept(true) -> void
{
	Nominax::Common::GlobalSystemAllocator->Deallocate(mem);
}