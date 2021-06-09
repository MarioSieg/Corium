#pragma once

#include "Allocator.hpp"

namespace Nominax::Common
{
	/// <summary>
	/// Default and fast allocator implementation.
	/// </summary>
	class RuntimeAllocator: public IAllocator
	{		
	public:
		/// <summary>
		/// Default constructor.
		/// </summary>
		/// <returns></returns>
		constexpr RuntimeAllocator() noexcept(true) = default;

		/// <summary>
		/// Copy constructor.
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		constexpr RuntimeAllocator(const RuntimeAllocator& other) noexcept(true) = default;

		/// <summary>
		/// Move constructor.
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		constexpr RuntimeAllocator(RuntimeAllocator&& other) noexcept(true) = default;

		/// <summary>
		/// Copy assignment operator.
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		constexpr auto operator =(const RuntimeAllocator& other) noexcept(true) -> RuntimeAllocator& = default;

		/// <summary>
		/// Move assignment operator.
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		constexpr auto operator =(RuntimeAllocator&& other) noexcept(true) -> RuntimeAllocator& = default;

		/// <summary>
		/// Destructor.
		/// </summary>
		~RuntimeAllocator() override = default;

		/// <summary>
		/// Allocate block using std::malloc.
		/// </summary>
		/// <param name="out"></param>
		/// <param name="size"></param>
		/// <returns></returns>
		auto Allocate(void*& out, std::size_t size) const noexcept(true) ->  void override;

		/// <summary>
		/// Reallocate using std::realloc.
		/// </summary>
		/// <param name="out"></param>
		/// <param name="size"></param>
		/// <returns></returns>
		auto Reallocate(void*& out, std::size_t size) const noexcept(true) -> void override;

		/// <summary>
		/// Deallocate using std::free.
		/// </summary>
		/// <param name="out"></param>
		/// <returns></returns>
		auto Deallocate(void*& out) const noexcept(true) -> void override;

		/// <summary>
		/// Allocate aligned using platform specific intrinsic allocator.
		/// </summary>
		/// <param name="out"></param>
		/// <param name="size"></param>
		/// <param name="alignment"></param>
		/// <returns></returns>
		auto AllocateAligned(void*& out, std::size_t size, std::size_t alignment) const noexcept(true) -> void override;

		/// <summary>
		/// Reallocate aligned using platform specific intrinsic allocator.
		/// </summary>
		/// <param name="out"></param>
		/// <param name="size"></param>
		/// <param name="alignment"></param>
		/// <returns></returns>
		auto ReallocateAligned(void*& out, std::size_t size, std::size_t alignment) const noexcept(true) -> void override;

		/// <summary>
		/// Deallocate aligned using platform specific intrinsic allocator.
		/// </summary>
		/// <param name="out"></param>
		/// <returns></returns>
		auto DeallocateAligned(void*& out) const noexcept(true) -> void override;
	};

	/// <summary>
	/// Runtime allocator instance.
	/// </summary>
	constexpr RuntimeAllocator RUNTIME_ALLOCATOR{};
}
