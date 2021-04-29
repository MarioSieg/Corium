#pragma once

#include <bit>
#include <cstddef>
#include <cstdint>

#include "ILog.hpp"

namespace Nominax
{
	/// <summary>
	/// Returns true if the alignment is valid,
	/// which means it is a power of two and not zero.
	/// </summary>
	/// <param name="alignment"></param>
	/// <returns></returns>
	[[nodiscard]]
	constexpr auto IsAlignmentValid(const std::size_t alignment) noexcept(true) -> bool
	{
		return alignment && !(alignment & alignment - 1);
	}
	
	static_assert(IsAlignmentValid(alignof(std::max_align_t)), "WTF");

	/// <summary>
	/// Checks is the address of the pointer is aligned to specified alignment,
	/// </summary>
	/// <param name="ptr">The address to check.</param>
	/// <param name="alignment">The alignment the address should have.</param>
	/// <returns>True if valid and corresponding alignment, else false.</returns>
	[[nodiscard]]
	constexpr auto IsAlignedTo(void* const ptr, const std::size_t alignment) noexcept(true) -> bool
	{
		return std::bit_cast<std::uintptr_t>(ptr) % alignment == 0 && IsAlignmentValid(alignment);
	}

	/// <summary>
	/// Compute the required offset to align the pointer to the given alignment.
	/// The specified alignment must be valid, check with IsAlignmentValid() if needed. 
	/// </summary>
	/// <param name="ptr">The pointer address. Can be nullptr!</param>
	/// <param name="alignment">The alignment, which must be valid.</param>
	/// <returns>The required offset.</returns>
	constexpr auto ComputeMissingAlignmentOffset(void* const ptr, const std::size_t alignment) noexcept(true) -> std::size_t
	{
		const auto misalignment = std::bit_cast<std::uintptr_t>(ptr) & alignment - 1;
		return misalignment ? alignment - misalignment : 0;
	}

	/// <summary>
	/// Compute the required offset to align the pointer to the given alignment.
	/// The specified alignment must be valid, check with IsAlignmentValid() if needed. 
	/// </summary>
	/// <param name="ptr">The pointer address. Can be nullptr!</param>
	/// <param name="alignment">The alignment, which must be valid.</param>
	/// <returns>The required offset.</returns>
	constexpr auto ComputeMissingAlignmentOffset(const std::uintptr_t  ptr, const std::size_t alignment) noexcept(true) -> std::size_t
	{
		const auto misalignment = ptr & alignment - 1;
		return misalignment ? alignment - misalignment : 0;
	}

	/// <summary>
	/// Computes the minimum required alignment for an
	/// object of the specified size.
	/// </summary>
	/// <param name="size"></param>
	/// <returns></returns>
	inline auto ComputeMinAlignmentRequiredForSize(const std::size_t size) noexcept(true) -> std::size_t
	{
		return size >= alignof(std::max_align_t) ? alignof(std::max_align_t) : static_cast<std::size_t>(1) << ILog2(size);
	}
}
