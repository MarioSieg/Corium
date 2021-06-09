#pragma once

#include "RuntimeAllocator.hpp"

namespace Nominax::Common
{
	/// <summary>
	/// Allocator for debugging based on the runtime allocator.
	/// It prints the size and address of each allocation
	/// and counts the bytes.
	/// </summary>
	class DebugAllocator final : public RuntimeAllocator
	{
		mutable U64 Allocations_{ 0 };
		mutable U64 Reallocations_{ 0 };
		mutable U64 Deallocations_{ 0 };
		mutable U64 BytesAllocated_{ 0 };
		
	public:
		/// <summary>
		/// Default constructor.
		/// </summary>
		/// <returns></returns>
		constexpr DebugAllocator() noexcept(true) = default;

		/// <summary>
		/// Copy constructor.
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		constexpr DebugAllocator(const DebugAllocator& other) noexcept(true) = default;

		/// <summary>
		/// Move constructor.
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		constexpr DebugAllocator(DebugAllocator&& other) noexcept(true) = default;

		/// <summary>
		/// Copy assignment operator.
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		constexpr auto operator =(const DebugAllocator& other) noexcept(true) -> DebugAllocator& = default;

		/// <summary>
		/// Move assignment operator.
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		constexpr auto operator =(DebugAllocator&& other) noexcept(true) -> DebugAllocator& = default;

		/// <summary>
		/// Destructor.
		/// </summary>
		~DebugAllocator() override = default;

		/// <summary>
		/// Call the equivalent RuntimeAllocator (superclass) method and print debug info.
		/// </summary>
		/// <param name="out"></param>
		/// <param name="size"></param>
		/// <returns></returns>
		auto Allocate(void*& out, std::size_t size) const noexcept(true) -> void override;

		/// <summary>
		/// Call the equivalent RuntimeAllocator (superclass) method and print debug info.
		/// </summary>
		/// <param name="out"></param>
		/// <param name="size"></param>
		/// <returns></returns>
		auto Reallocate(void*& out, std::size_t size) const noexcept(true) -> void override;

		/// <summary>
		/// Call the equivalent RuntimeAllocator (superclass) method and print debug info.
		/// </summary>
		/// <param name="out"></param>
		/// <returns></returns>
		auto Deallocate(void*& out) const noexcept(true) -> void override;

		/// <summary>
		/// Call the equivalent RuntimeAllocator (superclass) method and print debug info.
		/// </summary>
		/// <param name="out"></param>
		/// <param name="size"></param>
		/// <param name="alignment"></param>
		/// <returns></returns>
		auto AllocateAligned(void*& out, std::size_t size, std::size_t alignment) const noexcept(true) -> void override;

		/// <summary>
		/// Call the equivalent RuntimeAllocator (superclass) method and print debug info.
		/// </summary>
		/// <param name="out"></param>
		/// <param name="size"></param>
		/// <param name="alignment"></param>
		/// <returns></returns>
		auto ReallocateAligned(void*& out, std::size_t size, std::size_t alignment) const noexcept(true) -> void override;

		/// <summary>
		/// Call the equivalent RuntimeAllocator (superclass) method and print debug info.
		/// </summary>
		/// <param name="out"></param>
		/// <returns></returns>
		auto DeallocateAligned(void*& out) const noexcept(true) -> void override;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The amount of allocations so far.</returns>
		constexpr auto GetAllocationCount() const noexcept(true) -> U64;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The amount of reallocations so far.</returns>
		constexpr auto GetReallocationCount() const noexcept(true) -> U64;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The amount of deallocations so far.</returns>
		constexpr auto GetDeallocationCount() const noexcept(true) -> U64;

		/// <summary>
		/// The amount of allocated bytes so far.
		/// </summary>
		/// <returns></returns>
		constexpr auto GetTotalBytesAllocated() const noexcept(true) -> U64;

		/// <summary>
		/// Print the amount of allocations and bytes.
		/// </summary>
		/// <returns></returns>
		auto DumpAllocationInfo() const noexcept(false) -> void;
	};

	constexpr auto DebugAllocator::GetAllocationCount() const noexcept(true) -> U64
	{
		return this->Allocations_;
	}

	constexpr auto DebugAllocator::GetReallocationCount() const noexcept(true) -> U64
	{
		return this->Reallocations_;
	}

	constexpr auto DebugAllocator::GetDeallocationCount() const noexcept(true) -> U64
	{
		return this->Deallocations_;
	}

	constexpr auto DebugAllocator::GetTotalBytesAllocated() const noexcept(true) -> U64
	{
		return this->BytesAllocated_;
	}

	/// <summary>
	/// Debug allocator instance.
	/// </summary>
	constexpr DebugAllocator DEBUG_ALLOCATOR{};
}
