#pragma once

#include <cstdint>
#include <type_traits>

#include "../Record.hpp"

#include "SystemIntrinsicCallId.hpp"
#include "CustomIntrinsicCallId.hpp"
#include "Instruction.hpp"

namespace Nominax 
{
	/// <summary>
	/// 64-bit byte code signal data contains either an instruction or an immediate value.
	/// </summary>
	union alignas(alignof(std::uint64_t)) Signal
	{
		/// <summary>
		/// Reinterpret as Record64.
		/// </summary>
		Record R64;

		/// <summary>
		/// Reinterpret as instruction.
		/// </summary>
		Instruction Instr;

		/// <summary>
		/// Reinterpret as system intrinsic call id.
		/// </summary>
		SystemIntrinsicCallId SystemIntrinId;

		/// <summary>
		/// Reinterpret as custom intrinsic call id.
		/// </summary>
		CustomIntrinsicCallId CustomIntrinId;

		/// <summary>
		/// Reinterpret as 64-bit unsigned opcode. (For intrinsic calls and instructions).
		/// </summary>
		std::uint64_t OpCode;

		/// <summary>
		/// Reinterpret as void pointer.
		/// </summary>
		void* Ptr;

		/// <summary>
		/// Construct from record64.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr Signal(Record value) noexcept;

		/// <summary>
		/// Construct from instruction.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr Signal(Instruction value) noexcept;

		/// <summary>
		/// Construct from system intrinsic call id.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr Signal(SystemIntrinsicCallId value) noexcept;

		/// <summary>
		/// Construct from custom intrinsic call id.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr Signal(CustomIntrinsicCallId value) noexcept;

		/// <summary>
		/// Construct from void pointer.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr Signal(void* value) noexcept;

		/// <summary>
		/// Construct from 64-bit signed quadword integer.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr Signal(std::int64_t value) noexcept;

		/// <summary>
		/// Construct from 64-bit unsigned quadword integer.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr Signal(std::uint64_t value) noexcept;

		/// <summary>
		/// Construct from 64-bit double precision float.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr Signal(double value) noexcept;

		/// <summary>
		/// Construct from 32-bit UTF-32 character.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr Signal(char32_t value) noexcept;
	};

	constexpr Signal::Signal(const Record value) noexcept : R64{ value } {}
	constexpr Signal::Signal(const Instruction value) noexcept : Instr{ value } {}
	constexpr Signal::Signal(const SystemIntrinsicCallId value) noexcept : SystemIntrinId{ value } {}
	constexpr Signal::Signal(const CustomIntrinsicCallId value) noexcept : CustomIntrinId{ value } {}
	constexpr Signal::Signal(void* const value) noexcept : Ptr{ value } {}
	constexpr Signal::Signal(const std::int64_t value) noexcept : R64{ value } {}
	constexpr Signal::Signal(const std::uint64_t value) noexcept : R64{ value } {}
	constexpr Signal::Signal(const double value) noexcept : R64{ value } {}
	constexpr Signal::Signal(const char32_t value) noexcept : R64{ value } {}

	static_assert(std::is_same_v<std::underlying_type_t<Instruction>, std::uint64_t>);
	static_assert(sizeof(Instruction) == sizeof(std::uint64_t));
	static_assert(sizeof(Signal) == sizeof(std::uint64_t));
	static_assert(std::is_standard_layout_v<Signal>);
}