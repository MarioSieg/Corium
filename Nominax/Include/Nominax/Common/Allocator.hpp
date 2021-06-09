#pragma once

#include "BaseTypes.hpp"

namespace Nominax::Common
{
	/// <summary>
	/// Generic runtime allocator interface.
	/// </summary>
	class IAllocator
	{
	protected:
		/// <summary>
		/// Impl constructor.
		/// </summary>
		/// <returns></returns>
		constexpr IAllocator() noexcept(true) = default;
		
	public:
		/// <summary>
		/// Copy constructor.
		/// </summary>
		/// <param name="other"></param>
		constexpr IAllocator(const IAllocator& other) noexcept(true) = default;

		/// <summary>
		/// Move constructor.
		/// </summary>
		/// <param name="other"></param>
		constexpr IAllocator(IAllocator&& other) noexcept(true) = default;

		/// <summary>
		/// Copy assignment operator.
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		constexpr auto operator =(const IAllocator& other) noexcept(true)-> IAllocator& = default;

		/// <summary>
		/// Move assignment operator.
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		constexpr auto operator =(IAllocator&& other) noexcept(true) -> IAllocator& = default;

		/// <summary>
		/// Destructor.
		/// </summary>
		virtual ~IAllocator() = default;

		/// <summary>
		/// Raw allocate like malloc().
		/// </summary>
		/// <param name="out">Output pointer.</param>
		/// <param name="size">The size of the block in bytes.</param>
		/// <returns></returns>
		virtual auto Allocate (void*& out, std::size_t size) const noexcept(true) -> void = 0;

		/// <summary>
		/// Raw reallocate like realloc().
		/// </summary>
		/// <param name="out">Output pointer.</param>
		/// <param name="size">The size of the block in bytes.</param>
		/// <returns></returns>
		virtual auto Reallocate	(void*& out, std::size_t size) const noexcept(true) -> void = 0;

		/// <summary>
		/// Raw deallocate like free().
		/// </summary>
		/// <param name="out">Input pointer.</param>
		/// <returns></returns>
		virtual auto Deallocate (void*& out) const noexcept(true) -> void = 0;


		/// <summary>
		/// Raw allocate with alignment like aligned_malloc().
		/// </summary>
		/// <param name="out"></param>
		/// <param name="alignment"></param>
		/// <param name="size"></param>
		/// <returns></returns>
		virtual auto AllocateAligned(void*& out, std::size_t size, std::size_t alignment) const noexcept(true) -> void = 0;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="out"></param>
		/// <param name="alignment"></param>
		/// <param name="size"></param>
		/// <returns></returns>
		virtual auto ReallocateAligned(void*& out, std::size_t size, std::size_t alignment) const noexcept(true) -> void = 0;

		/// <summary>
		/// Raw deallocate aligned like free().
		/// </summary>
		/// <param name="out">Input pointer.</param>
		/// <returns></returns>
		virtual auto DeallocateAligned(void*& out) const noexcept(true) -> void = 0;

		/// <summary>
		/// Virtual alloc.
		/// </summary>
		/// <param name="out"></param>
		/// <param name="size"></param>
		/// <returns></returns>
		virtual auto Valloc	(void*& out, std::size_t size) const noexcept(true) -> void;

		/// <summary>
		/// Virtual free.
		/// </summary>
		/// <param name="out"></param>
		/// <returns></returns>
		virtual auto Vdealloc (void*& out) const noexcept(true) -> void;
	};

	/// <summary>
	/// Global used allocator.
	/// </summary>
	extern constinit const IAllocator* GlobalSystemAllocator;
}
