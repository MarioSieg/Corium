// File: ByteCode.hpp
// Author: Mario
// Created: 09.04.2021 5:11 PM
// Project: NominaxRuntime
// 
//                                  Apache License
//                            Version 2.0, January 2004
//                         http://www.apache.org/licenses/
// 
//    TERMS AND CONDITIONS FOR USE, REPRODUCTION, AND DISTRIBUTION
// 
//    1. Definitions.
// 
//       "License" shall mean the terms and conditions for use, reproduction,
//       and distribution as defined by Sections 1 through 9 of this document.
// 
//       "Licensor" shall mean the copyright owner or entity authorized by
//       the copyright owner that is granting the License.
// 
//       "Legal Entity" shall mean the union of the acting entity and all
//       other entities that control, are controlled by, or are under common
//       control with that entity. For the purposes of this definition,
//       "control" means (i) the power, direct or indirect, to cause the
//       direction or management of such entity, whether by contract or
//       otherwise, or (ii) ownership of fifty percent (50%) or more of the
//       outstanding shares, or (iii) beneficial ownership of such entity.
// 
//       "You" (or "Your") shall mean an individual or Legal Entity
//       exercising permissions granted by this License.
// 
//       "Source" form shall mean the preferred form for making modifications,
//       including but not limited to software source code, documentation
//       source, and configuration files.
// 
//       "Object" form shall mean any form resulting from mechanical
//       transformation or translation of a Source form, including but
//       not limited to compiled object code, generated documentation,
//       and conversions to other media types.
// 
//       "Work" shall mean the work of authorship, whether in Source or
//       Object form, made available under the License, as indicated by a
//       copyright notice that is included in or attached to the work
//       (an example is provided in the Appendix below).
// 
//       "Derivative Works" shall mean any work, whether in Source or Object
//       form, that is based on (or derived from) the Work and for which the
//       editorial revisions, annotations, elaborations, or other modifications
//       represent, as a whole, an original work of authorship. For the purposes
//       of this License, Derivative Works shall not include works that remain
//       separable from, or merely link (or bind by name) to the interfaces of,
//       the Work and Derivative Works thereof.
// 
//       "Contribution" shall mean any work of authorship, including
//       the original version of the Work and any modifications or additions
//       to that Work or Derivative Works thereof, that is intentionally
//       submitted to Licensor for inclusion in the Work by the copyright owner
//       or by an individual or Legal Entity authorized to submit on behalf of
//       the copyright owner. For the purposes of this definition, "submitted"
//       means any form of electronic, verbal, or written communication sent
//       to the Licensor or its representatives, including but not limited to
//       communication on electronic mailing lists, source code control systems,
//       and issue tracking systems that are managed by, or on behalf of, the
//       Licensor for the purpose of discussing and improving the Work, but
//       excluding communication that is conspicuously marked or otherwise
//       designated in writing by the copyright owner as "Not a Contribution."
// 
//       "Contributor" shall mean Licensor and any individual or Legal Entity
//       on behalf of whom a Contribution has been received by Licensor and
//       subsequently incorporated within the Work.
// 
//    2. Grant of Copyright License. Subject to the terms and conditions of
//       this License, each Contributor hereby grants to You a perpetual,
//       worldwide, non-exclusive, no-charge, royalty-free, irrevocable
//       copyright license to reproduce, prepare Derivative Works of,
//       publicly display, publicly perform, sublicense, and distribute the
//       Work and such Derivative Works in Source or Object form.
// 
//    3. Grant of Patent License. Subject to the terms and conditions of
//       this License, each Contributor hereby grants to You a perpetual,
//       worldwide, non-exclusive, no-charge, royalty-free, irrevocable
//       (except as stated in this section) patent license to make, have made,
//       use, offer to sell, sell, import, and otherwise transfer the Work,
//       where such license applies only to those patent claims licensable
//       by such Contributor that are necessarily infringed by their
//       Contribution(s) alone or by combination of their Contribution(s)
//       with the Work to which such Contribution(s) was submitted. If You
//       institute patent litigation against any entity (including a
//       cross-claim or counterclaim in a lawsuit) alleging that the Work
//       or a Contribution incorporated within the Work constitutes direct
//       or contributory patent infringement, then any patent licenses
//       granted to You under this License for that Work shall terminate
//       as of the date such litigation is filed.
// 
//    4. Redistribution. You may reproduce and distribute copies of the
//       Work or Derivative Works thereof in any medium, with or without
//       modifications, and in Source or Object form, provided that You
//       meet the following conditions:
// 
//       (a) You must give any other recipients of the Work or
//           Derivative Works a copy of this License; and
// 
//       (b) You must cause any modified files to carry prominent notices
//           stating that You changed the files; and
// 
//       (c) You must retain, in the Source form of any Derivative Works
//           that You distribute, all copyright, patent, trademark, and
//           attribution notices from the Source form of the Work,
//           excluding those notices that do not pertain to any part of
//           the Derivative Works; and
// 
//       (d) If the Work includes a "NOTICE" text file as part of its
//           distribution, then any Derivative Works that You distribute must
//           include a readable copy of the attribution notices contained
//           within such NOTICE file, excluding those notices that do not
//           pertain to any part of the Derivative Works, in at least one
//           of the following places: within a NOTICE text file distributed
//           as part of the Derivative Works; within the Source form or
//           documentation, if provided along with the Derivative Works; or,
//           within a display generated by the Derivative Works, if and
//           wherever such third-party notices normally appear. The contents
//           of the NOTICE file are for informational purposes only and
//           do not modify the License. You may add Your own attribution
//           notices within Derivative Works that You distribute, alongside
//           or as an addendum to the NOTICE text from the Work, provided
//           that such additional attribution notices cannot be construed
//           as modifying the License.
// 
//       You may add Your own copyright statement to Your modifications and
//       may provide additional or different license terms and conditions
//       for use, reproduction, or distribution of Your modifications, or
//       for any such Derivative Works as a whole, provided Your use,
//       reproduction, and distribution of the Work otherwise complies with
//       the conditions stated in this License.
// 
//    5. Submission of Contributions. Unless You explicitly state otherwise,
//       any Contribution intentionally submitted for inclusion in the Work
//       by You to the Licensor shall be under the terms and conditions of
//       this License, without any additional terms or conditions.
//       Notwithstanding the above, nothing herein shall supersede or modify
//       the terms of any separate license agreement you may have executed
//       with Licensor regarding such Contributions.
// 
//    6. Trademarks. This License does not grant permission to use the trade
//       names, trademarks, service marks, or product names of the Licensor,
//       except as required for reasonable and customary use in describing the
//       origin of the Work and reproducing the content of the NOTICE file.
// 
//    7. Disclaimer of Warranty. Unless required by applicable law or
//       agreed to in writing, Licensor provides the Work (and each
//       Contributor provides its Contributions) on an "AS IS" BASIS,
//       WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
//       implied, including, without limitation, any warranties or conditions
//       of TITLE, NON-INFRINGEMENT, MERCHANTABILITY, or FITNESS FOR A
//       PARTICULAR PURPOSE. You are solely responsible for determining the
//       appropriateness of using or redistributing the Work and assume any
//       risks associated with Your exercise of permissions under this License.
// 
//    8. Limitation of Liability. In no event and under no legal theory,
//       whether in tort (including negligence), contract, or otherwise,
//       unless required by applicable law (such as deliberate and grossly
//       negligent acts) or agreed to in writing, shall any Contributor be
//       liable to You for damages, including any direct, indirect, special,
//       incidental, or consequential damages of any character arising as a
//       result of this License or out of the use or inability to use the
//       Work (including but not limited to damages for loss of goodwill,
//       work stoppage, computer failure or malfunction, or any and all
//       other commercial damages or losses), even if such Contributor
//       has been advised of the possibility of such damages.
// 
//    9. Accepting Warranty or Additional Liability. While redistributing
//       the Work or Derivative Works thereof, You may choose to offer,
//       and charge a fee for, acceptance of support, warranty, indemnity,
//       or other liability obligations and/or rights consistent with this
//       License. However, in accepting such obligations, You may act only
//       on Your own behalf and on Your sole responsibility, not on behalf
//       of any other Contributor, and only if You agree to indemnify,
//       defend, and hold each Contributor harmless for any liability
//       incurred by, or claims asserted against, such Contributor by reason
//       of your accepting any such warranty or additional liability.
// 
//    END OF TERMS AND CONDITIONS
// 
//    APPENDIX: How to apply the Apache License to your work.
// 
//       To apply the Apache License to your work, attach the following
//       boilerplate notice, with the fields enclosed by brackets "[]"
//       replaced with your own identifying information. (Don't include
//       the brackets!)  The text should be enclosed in the appropriate
//       comment syntax for the file format. We also recommend that a
//       file or class name and description of purpose be included on the
//       same "printed page" as the copyright notice for easier
//       identification within third-party archives.
// 
//    Copyright 2021 Mario Sieg "pinsrq" <mt3000@gmx.de>
// 
//    Licensed under the Apache License, Version 2.0 (the "License");
//    you may not use this file except in compliance with the License.
//    You may obtain a copy of the License at
// 
//        http://www.apache.org/licenses/LICENSE-2.0
// 
//    Unless required by applicable law or agreed to in writing, software
//    distributed under the License is distributed on an "AS IS" BASIS,
//    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//    See the License for the specific language governing permissions and
//    limitations under the License.

#pragma once

#include <array>
#include <filesystem>
#include <optional>
#include <ostream>
#include <string_view>
#include <span>
#include <type_traits>
#include <unordered_map>
#include <variant>
#include <vector>

#include "Record.hpp"
#include "MacroCfg.hpp"

namespace Nominax 
{
	/// <summary>
	/// Custom intrinsic routine function prototype.
	/// Contains the stack pointer as parameter.
	/// </summary>
	using IntrinsicRoutine = auto (Record*) -> bool;
	static_assert(std::is_function_v<IntrinsicRoutine>);

	/// <summary>
	///  std::visit auto overload helper
	/// </summary>
	/// <typeparam name="...Ts">The call types.</typeparam>
	template <typename... Ts>
	struct Overloaded : Ts...
	{
		using Ts::operator()...;
	};

	template <typename... Ts>
	Overloaded(Ts&&...) -> Overloaded<Ts...>;

	/// <summary>
	/// Restricts to valid bytecode elements.
	/// </summary>
	/// <typeparam name="...Ts">The generic types to perform restriction checks on.</typeparam>
	template <typename Ts>
	concept BytecodeElement = requires
	{
		requires sizeof(Ts) % sizeof(std::int32_t) == 0 || sizeof(Ts) % sizeof(std::int64_t) == 0;
		requires alignof(Ts) % alignof(std::int32_t) == 0 || alignof(Ts) % alignof(std::int64_t) == 0;
		requires
		std::is_same_v<Ts, Instruction>
		|| std::is_same_v<Ts, SystemIntrinsicCallId>
		|| std::is_same_v<Ts, CustomIntrinsicCallId>
		|| std::is_same_v<Ts, std::uint64_t>
		|| std::is_same_v<Ts, std::int64_t>
		|| std::is_same_v<Ts, double>
		|| std::is_same_v<Ts, char32_t>;
	};

	/// <summary>
	/// Represents an entry in a byte code steam. This get's converted to a signal for execution.
	/// </summary>
	struct DynamicSignal final
	{
		/// <summary>
		/// Discriminated union.
		/// </summary>
		using Variant = std::variant<Instruction, SystemIntrinsicCallId, CustomIntrinsicCallId, std::uint64_t, std::int64_t, double, char32_t>;

		/// <summary>
		/// Default construct an I64(0)
		/// </summary>
		/// <returns></returns>
		constexpr DynamicSignal() noexcept;

		/// <summary>
		/// Construct from data union.
		/// </summary>
		/// <param name="data">The initial value.</param>
		/// <returns></returns>
		explicit constexpr DynamicSignal(Variant&& data) noexcept;

		/// <summary>
		/// Construct from instruction.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr DynamicSignal(Instruction value) noexcept;

		/// <summary>
		/// Construct from 64-bit unsigned quadword integer.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr DynamicSignal(std::uint64_t value) noexcept;

		/// <summary>
		/// Construct from 64-bit signed quadword integer.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr DynamicSignal(std::int64_t value) noexcept;

		/// <summary>
		/// Construct from 64-bit double precision float.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr DynamicSignal(double value) noexcept;

		/// <summary>
		/// Construct from 32-bit UTF32 character.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr DynamicSignal(char32_t value) noexcept;

		/// <summary>
		/// Construct from system intrinsic call id.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr DynamicSignal(SystemIntrinsicCallId value) noexcept;

		/// <summary>
		/// Construct from custom intrinsic call id.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr DynamicSignal(CustomIntrinsicCallId value) noexcept;

		/// <summary>
		/// Copy constructor.
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		constexpr DynamicSignal(const DynamicSignal&) noexcept = default;

		/// <summary>
		/// Move constructor.
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		constexpr DynamicSignal(DynamicSignal&&) noexcept = default;

		/// <summary>
		/// Copy assignment operator.
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		constexpr auto operator =(const DynamicSignal&) noexcept -> DynamicSignal& = default;

		/// <summary>
		/// Move assignment operator.
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		constexpr auto operator =(DynamicSignal&&) noexcept -> DynamicSignal& = default;

		/// <summary>
		/// Destructor.
		/// </summary>
		~DynamicSignal() = default;


		/// <summary>
		/// Convert to undiscriminated runtime signal.
		/// </summary>
		[[nodiscard]]
		explicit operator Signal() const;

		/// <summary>
		/// Try to extract raw data.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <returns></returns>
		template <typename T> requires BytecodeElement<T>
		[[nodiscard]]
		constexpr auto Unwrap() const -> std::optional<T>;

		/// <summary>
		/// Check if generic T is contained.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <returns></returns>
		template <typename T> requires BytecodeElement<T>
		[[nodiscard]]
		constexpr auto Contains() const noexcept -> bool;

		/// <summary>
		/// Chgeck if generic T and value is contained.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <param name="compareTo"></param>
		/// <returns></returns>
		template <typename T> requires BytecodeElement<T>
		[[nodiscard]]
		constexpr auto Contains(const T compareTo) const -> bool;

		/// <summary>
		/// Raw data variant (discriminated union)
		/// </summary>
		Variant DataCollection { };

		/// <summary>
		/// Common code prologue.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		static constexpr auto CodePrologue() noexcept -> DynamicSignal;

		/// <summary>
		/// Common code epilogue.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		static constexpr auto CodeEpilogue() noexcept -> std::array<DynamicSignal, 2>;
	};

	constexpr DynamicSignal::DynamicSignal() noexcept : DataCollection {UINT64_C(0)} {}
	constexpr DynamicSignal::DynamicSignal(Variant&& data) noexcept : DataCollection {data} {}
	constexpr DynamicSignal::DynamicSignal(const Instruction value) noexcept : DataCollection {value} {}
	constexpr DynamicSignal::DynamicSignal(const std::uint64_t value) noexcept : DataCollection {value} {}
	constexpr DynamicSignal::DynamicSignal(const std::int64_t value) noexcept : DataCollection {value} {}
	constexpr DynamicSignal::DynamicSignal(const double value) noexcept : DataCollection {value} {}
	constexpr DynamicSignal::DynamicSignal(const char32_t value) noexcept : DataCollection {value} {}
	constexpr DynamicSignal::DynamicSignal(const SystemIntrinsicCallId value) noexcept : DataCollection {value} {}
	constexpr DynamicSignal::DynamicSignal(const CustomIntrinsicCallId value) noexcept : DataCollection {value} {}

	constexpr auto DynamicSignal::CodePrologue() noexcept -> DynamicSignal
	{
		// First instruction is always skipped and should be NOP:
		return DynamicSignal {Instruction::NOp};
	}

	constexpr auto DynamicSignal::CodeEpilogue() noexcept -> std::array<DynamicSignal, 2>
	{
		// Because the end of a byte code stream is not checked,
		// we always HAVE to interrupt at the end or we will jump to random memory locations.
		// The minimum std::int64_t exit code is the reserved final interrupt code,
		// the program should return before this instruction with it's own exit code.
		// This is the last trap before going to hell!
		return
		{
			DynamicSignal {Instruction::Int},
			DynamicSignal {std::numeric_limits<std::int64_t>::min()}
		};
	}

	template <typename T> requires BytecodeElement<T>
	constexpr auto DynamicSignal::Unwrap() const -> std::optional<T>
	{
		return std::holds_alternative<T>(this->DataCollection)
			       ? std::optional<T> {std::get<T>(this->DataCollection)}
			       : std::nullopt;
	}

	template <typename T> requires BytecodeElement<T>
	constexpr auto DynamicSignal::Contains() const noexcept -> bool
	{
		return std::holds_alternative<T>(this->DataCollection);
	}

	template <typename T> requires BytecodeElement<T>
	constexpr auto DynamicSignal::Contains(const T compareTo) const -> bool
	{
		return std::holds_alternative<T>(this->DataCollection) && std::get<T>(this->DataCollection) == compareTo;
	}

	extern auto operator <<(std::ostream& out, const DynamicSignal& in) -> std::ostream&;

	/// <summary>
	/// Creates an instruction mapping.
	/// </summary>
	/// <param name="input"></param>
	/// <param name="output"></param>
	/// <returns></returns>
	[[nodiscard]]
	extern auto CreateInstructionMapping(std::span<const DynamicSignal> input, std::span<bool>& output) -> bool;

	/// <summary>
	/// Contains all byte code validation results.
	/// </summary>
	enum class ByteCodeValidationResult
	{
		/// <summary>
		/// Validation did not found any problems.
		/// </summary>
		Ok = 0,

		/// <summary>
		/// An instruction requires more arguments, than given.
		/// </summary>
		NotEnoughArguments,

		/// <summary>
		/// An instruction requires less arguments, than given.
		/// </summary>
		TooManyArguments,

		/// <summary>
		/// The immediate argument type is not correct for the corresponding instruction.
		/// </summary>
		InvalidOperandType
	};

	/// <summary>
	/// Perform byte code validation on a single instruction.
	/// This just checks all argument types and values.
	/// </summary>
	/// <param name="instruction"></param>
	/// <param name="args"></param>
	/// <returns></returns>
	[[nodiscard]]
	extern auto ByteCodeValidateSingleInstruction(Instruction instruction, std::span<const DynamicSignal> args) -> ByteCodeValidationResult;

	/// <summary>
	/// Construct a runtime integer (64-bit).
	/// </summary>
	/// <param name="value"></param>
	/// <returns></returns>
	constexpr auto operator""_int(const unsigned long long int value) noexcept -> std::int64_t
	{
		return static_cast<std::int64_t>(value);
	}

	/// <summary>
	/// Construct a runtime unsigned integer (64-bit).
	/// </summary>
	/// <param name="value"></param>
	/// <returns></returns>
	constexpr auto operator""_uint(const unsigned long long int value) noexcept -> std::uint64_t
	{
		return value;
	}

	/// <summary>
	/// Construct a runtime float (64-bit).
	/// </summary>
	/// <param name="value"></param>
	/// <returns></returns>
	constexpr auto operator""_float(const long double value) noexcept -> double
	{
		return static_cast<double>(value);
	}

	enum class OptimizationLevel
	{
		Off = 0,
		O1 = 1,
		O2 = 2,
		O3 = 3
	};

	consteval auto DefaultOptimizationLevel() noexcept -> OptimizationLevel
	{
#if NOMINAX_DEBUG
		return OptimizationLevel::O3;
#else
		return OptimizationLevel::O2;
#endif
	}

	inline constinit OptimizationLevel OptLevel {DefaultOptimizationLevel()};

	template <typename T>
	concept StreamScalar = requires
	{
		requires std::is_trivial_v<T>;
		requires std::is_floating_point_v<T> || std::is_integral_v<T>;
	};

	template <typename T> requires StreamScalar<T>
	struct StreamVariable;

	/// <summary>
	/// Dynamic byte code stream.
	/// </summary>
	class Stream final
	{
		std::vector<DynamicSignal>                   SignalStream { };
		std::unordered_map<std::string, std::size_t> LabelTable { };

	public:
		static auto ExampleStream(Stream& stream) -> void;

		/// <summary>
		/// Construct empty stream.
		/// </summary>
		/// <returns></returns>
		Stream();

		/// <summary>
		/// Construct with capacity.
		/// </summary>
		/// <param name="cap"></param>
		explicit Stream(std::size_t cap);

		/// <summary>
		/// Move constructor.
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		Stream(Stream&&) noexcept = default;

		/// <summary>
		/// Copy constructor.
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		Stream(const Stream&) noexcept = default;

		/// <summary>
		/// Copy assignment operator.
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		auto operator =(const Stream&) -> Stream& = default;

		/// <summary>
		/// Move assignment operator.
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		auto operator =(Stream&&) -> Stream& = default;

		/// <summary>
		/// Destructor.
		/// </summary>
		~Stream() = default;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The vector used as buffer.</returns>
		[[nodiscard]]
		auto Buffer() const noexcept -> const std::vector<DynamicSignal>&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		auto Front() -> DynamicSignal&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		auto Back() -> DynamicSignal&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		auto Front() const -> const DynamicSignal&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		auto Back() const -> const DynamicSignal&;

		/// <summary>
		/// Clears the content of the whole stream.
		/// </summary>
		/// <returns></returns>
		auto Clear() -> void;

		/// <summary>
		/// Preallocate buffer capacity.
		/// </summary>
		/// <param name="cap"></param>
		/// <returns></returns>
		auto Reserve(std::size_t cap) -> void;

		/// <summary>
		/// Resize buffer size.
		/// </summary>
		/// <param name="size"></param>
		/// <returns></returns>
		auto Resize(std::size_t size) -> void;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The size of the stream.</returns>
		[[nodiscard]]
		auto Size() const noexcept -> std::size_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The size of the stream in bytes.</returns>
		[[nodiscard]]
		auto SizeInBytes() const noexcept -> std::size_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The capacity of the stream buffer.</returns>
		[[nodiscard]]
		auto Capacity() const noexcept -> std::size_t;

		/// <summary>
		/// Pushes a new signal into the stream.
		/// </summary>
		/// <param name="sig"></param>
		/// <returns></returns>
		auto Push(DynamicSignal&& sig) -> void;

		/// <summary>
		/// STL iterator compat
		/// </summary>
		/// <returns></returns>
		// ReSharper disable once CppInconsistentNaming
		[[nodiscard]]
		auto begin() noexcept -> std::vector<DynamicSignal>::iterator;

		/// <summary>
		/// STL iterator compat
		/// </summary>
		/// <returns></returns>
		// ReSharper disable once CppInconsistentNaming
		[[nodiscard]]
		auto end() noexcept -> std::vector<DynamicSignal>::iterator;

		/// <summary>
		/// STL iterator compat
		/// </summary>
		/// <returns></returns>
		// ReSharper disable once CppInconsistentNaming
		[[nodiscard]]
		auto begin() const noexcept -> std::vector<DynamicSignal>::const_iterator;

		/// <summary>
		/// STL iterator compat
		/// </summary>
		/// <returns></returns>
		// ReSharper disable once CppInconsistentNaming
		[[nodiscard]]
		auto end() const noexcept -> std::vector<DynamicSignal>::const_iterator;

		/// <summary>
		/// Push stream entry.
		/// </summary>
		/// <param name="instr"></param>
		/// <returns></returns>
		auto operator <<(Instruction instr) -> Stream&;

		/// <summary>
		/// Push stream entry.
		/// </summary>
		/// <param name="intrin"></param>
		/// <returns></returns>
		auto operator <<(SystemIntrinsicCallId intrin) -> Stream&;

		/// <summary>
		/// Push stream entry.
		/// </summary>
		/// <param name="intrin"></param>
		/// <returns></returns>
		auto operator <<(CustomIntrinsicCallId intrin) -> Stream&;

		/// <summary>
		/// Push stream entry.
		/// </summary>
		/// <param name="value"></param>
		/// <returns></returns>
		auto operator <<(std::uint64_t value) -> Stream&;

		/// <summary>
		/// Push stream entry.
		/// </summary>
		/// <param name="value"></param>
		/// <returns></returns>
		auto operator <<(std::int64_t value) -> Stream&;

		/// <summary>
		/// Push stream entry (casted to std::int64_t)
		/// </summary>
		/// <param name="value"></param>
		/// <returns></returns>
		auto operator <<(int value) -> Stream&;

		/// <summary>
		/// Push stream entry.
		/// </summary>
		/// <param name="value"></param>
		/// <returns></returns>
		auto operator <<(double value) -> Stream&;

		/// <summary>
		/// Push stream entry.
		/// </summary>
		/// <param name="value"></param>
		/// <returns></returns>
		auto operator <<(char32_t value) -> Stream&;

		/// <summary>
		/// Write the text byte code to a file.
		/// </summary>
		/// <param name="stream"></param>
		/// <param name="writeAddress"></param>
		/// <returns></returns>
		auto DumpToStream(std::ostream& stream, bool writeAddress = true) const -> void;

		/// <summary>
		/// Index lookup.
		/// </summary>
		/// <param name="idx"></param>
		/// <returns></returns>
		auto operator [](std::size_t idx) -> DynamicSignal&;

		/// <summary>
		/// Index lookup.
		/// </summary>
		/// <param name="idx"></param>
		/// <returns></returns>
		auto operator [](std::size_t idx) const -> DynamicSignal;

		/// <summary>
		/// Insert instruction manually.
		/// </summary>
		/// <param name="args"></param>
		/// <returns></returns>
		template <Instruction I, typename... Ts>
		auto Do(Ts&&...args) -> Stream&;

		template <typename F, typename V> requires
			std::is_trivial_v<V>
			&& (std::is_floating_point_v<V>
				|| std::is_integral_v<V>)
		auto With(V value, F&& functor) -> void;
	};

	template <Instruction I, typename... Ts>
	inline auto Stream::Do(Ts&&...args) -> Stream&
	{
		static_assert(sizeof...(Ts) == INSTRUCTION_IMMEDIATE_ARGUMENT_COUNTS[static_cast<std::size_t>(I)], "Invalid amount of immediate arguments!");
		*this << I;
		return (*this << ... << args);
	}

	template <typename F, typename V> requires
		std::is_trivial_v<V>
		&& (std::is_floating_point_v<V>
			|| std::is_integral_v<V>)
	inline auto Stream::With(const V value, F&& functor) -> void
	{
		if constexpr (std::is_same_v<int, V>)
		{
			return functor(StreamVariable<std::int64_t> {*this, static_cast<std::int64_t>(value)});
		}
		else
		{
			return functor(StreamVariable<V> {*this, value});
		}
	}

	inline auto Stream::Front() -> DynamicSignal&
	{
		return this->SignalStream.front();
	}

	inline auto Stream::Back() -> DynamicSignal&
	{
		return this->SignalStream.back();
	}

	inline auto Stream::Front() const -> const DynamicSignal&
	{
		return this->SignalStream.front();
	}

	inline auto Stream::Back() const -> const DynamicSignal&
	{
		return this->SignalStream.back();
	}

	inline auto Stream::operator[](const std::size_t idx) -> DynamicSignal&
	{
		return this->SignalStream.at(idx);
	}

	inline auto Stream::operator[](const std::size_t idx) const -> DynamicSignal
	{
		return this->SignalStream.at(idx);
	}

	inline Stream::Stream()
	{
		// Reserve buffer:
		this->SignalStream.reserve(8);

		// Insert important code prologue.
		this->SignalStream.emplace_back(DynamicSignal::CodePrologue());
	}

	inline Stream::Stream(const std::size_t cap)
	{
		// Reserve required space + (prologue + epilogue)
		this->SignalStream.reserve(cap + 3);

		// Insert important code prologue.
		this->SignalStream.emplace_back(DynamicSignal::CodePrologue());
	}

	inline auto Stream::Buffer() const noexcept -> const std::vector<DynamicSignal>&
	{
		return this->SignalStream;
	}

	inline auto Stream::Clear() -> void
	{
		this->SignalStream.resize(1);
	}

	inline auto Stream::Reserve(const std::size_t cap) -> void
	{
		this->SignalStream.reserve(cap);
	}

	inline auto Stream::Resize(const std::size_t size) -> void
	{
		this->SignalStream.resize(size);
	}

	inline auto Stream::Size() const noexcept -> std::size_t
	{
		return this->SignalStream.size();
	}

	inline auto Stream::SizeInBytes() const noexcept -> std::size_t
	{
		return this->SignalStream.size() * sizeof(DynamicSignal);
	}

	inline auto Stream::Capacity() const noexcept -> std::size_t
	{
		return this->SignalStream.capacity();
	}

	inline auto Stream::Push(DynamicSignal&& sig) -> void
	{
		this->SignalStream.emplace_back(sig);
	}

	// ReSharper disable once CppInconsistentNaming
	inline auto Stream::begin() noexcept -> std::vector<DynamicSignal>::iterator
	{
		return this->SignalStream.begin();
	}

	// ReSharper disable once CppInconsistentNaming
	inline auto Stream::end() noexcept -> std::vector<DynamicSignal>::iterator
	{
		return this->SignalStream.end();
	}

	// ReSharper disable once CppInconsistentNaming
	inline auto Stream::begin() const noexcept -> std::vector<DynamicSignal>::const_iterator
	{
		return this->SignalStream.begin();
	}

	// ReSharper disable once CppInconsistentNaming
	inline auto Stream::end() const noexcept -> std::vector<DynamicSignal>::const_iterator
	{
		return this->SignalStream.end();
	}

	/// <summary>
	/// STL iterator compat.
	/// </summary>
	/// <param name="in"></param>
	/// <returns></returns>
	// ReSharper disable once CppInconsistentNaming
	inline auto begin(Stream& in) noexcept -> std::vector<DynamicSignal>::iterator
	{
		return in.begin();
	}

	/// <summary>
	/// STL iterator compat.
	/// </summary>
	/// <param name="in"></param>
	/// <returns></returns>
	// ReSharper disable once CppInconsistentNaming
	inline auto end(Stream& in) noexcept -> std::vector<DynamicSignal>::iterator
	{
		return in.end();
	}

	/// <summary>
	/// STL iterator compat.
	/// </summary>
	/// <param name="in"></param>
	/// <returns></returns>
	// ReSharper disable once CppInconsistentNaming
	inline auto begin(const Stream& in) noexcept -> std::vector<DynamicSignal>::const_iterator
	{
		return in.begin();
	}

	/// <summary>
	/// STL iterator compat.
	/// </summary>
	/// <param name="in"></param>
	/// <returns></returns>
	// ReSharper disable once CppInconsistentNaming
	inline auto end(const Stream& in) noexcept -> std::vector<DynamicSignal>::const_iterator
	{
		return in.end();
	}

	inline auto Stream::operator <<(const Instruction instr) -> Stream&
	{
		this->Push(DynamicSignal {instr});
		return *this;
	}

	inline auto Stream::operator <<(const SystemIntrinsicCallId intrin) -> Stream&
	{
		this->Push(DynamicSignal {intrin});
		return *this;
	}

	inline auto Stream::operator <<(const CustomIntrinsicCallId intrin) -> Stream&
	{
		this->Push(DynamicSignal {intrin});
		return *this;
	}

	inline auto Stream::operator <<(const std::uint64_t value) -> Stream&
	{
		this->Push(DynamicSignal {value});
		return *this;
	}

	inline auto Stream::operator <<(const std::int64_t value) -> Stream&
	{
		this->Push(DynamicSignal {value});
		return *this;
	}

	inline auto Stream::operator <<(const double value) -> Stream&
	{
		this->Push(DynamicSignal {value});
		return *this;
	}

	inline auto Stream::operator<<(int value) -> Stream&
	{
		this->Push(DynamicSignal {static_cast<std::int64_t>(value)});
		return *this;
	}

	inline auto Stream::operator <<(const char32_t value) -> Stream&
	{
		this->Push(DynamicSignal {value});
		return *this;
	}

	extern auto operator <<(std::ostream& out, const Stream& in) -> std::ostream&;

	/// <summary>
	/// Single stack-bounded variable.
	/// When created it created a push instruction in the stream,
	/// when destroyed (RAII) it created a pop instruction.
	/// </summary>
	template <typename T> requires StreamScalar<T>
	struct StreamVariable final
	{
		/// <summary>
		/// Create a variable with specified value.
		/// </summary>
		/// <param name="attached"></param>
		/// <param name="value"></param>
		StreamVariable(Stream& attached, T value);

		StreamVariable(const StreamVariable&) = delete;

		StreamVariable(StreamVariable&&) = default;

		auto operator =(const StreamVariable&) -> StreamVariable& = delete;

		auto operator =(StreamVariable&&) -> StreamVariable& = delete;

		template <typename F, typename V> requires
			std::is_trivial_v<V>
			&& (std::is_floating_point_v<V>
				|| std::is_integral_v<V>)
		auto Another(V value, F&& functor) -> void;

		/// <summary>
		/// Arithmetic addition.
		/// Implemented for all types.
		/// self += value
		/// </summary>
		/// <param name="value">The second operand.</param>
		/// <returns>self</returns>
		auto Add(T value) -> StreamVariable&;

		/// <summary>
		/// Arithmetic addition.
		/// Implemented for all types.
		/// self += value
		/// </summary>
		/// <param name="value">The second operand.</param>
		/// <returns>self</returns>
		auto operator +=(T value) -> StreamVariable&;

		/// <summary>
		/// Arithmetic subtraction.
		/// Implemented for all types.
		/// self -= value
		/// </summary>
		/// <param name="value">The second operand.</param>
		/// <returns>self</returns>
		auto Sub(T value) -> StreamVariable&;

		/// <summary>
		/// Arithmetic subtraction.
		/// Implemented for all types.
		/// self -= value
		/// </summary>
		/// <param name="value">The second operand.</param>
		/// <returns>self</returns>
		auto operator -=(T value) -> StreamVariable&;

		/// <summary>
		/// Arithmetic multiplication.
		/// Implemented for all types.
		/// self *= value
		/// </summary>
		/// <param name="value">The second operand.</param>
		/// <returns>self</returns>
		auto Mul(T value) -> StreamVariable&;

		/// <summary>
		/// Arithmetic multiplication.
		/// Implemented for all types.
		/// self *= value
		/// </summary>
		/// <param name="value">The second operand.</param>
		/// <returns>self</returns>
		auto operator *=(T value) -> StreamVariable&;

		/// <summary>
		/// Arithmetic division.
		/// Implemented for all types.
		/// self /= value
		/// </summary>
		/// <param name="value">The second operand.</param>
		/// <returns>self</returns>
		auto Div(T value) -> StreamVariable&;

		/// <summary>
		/// Arithmetic division.
		/// Implemented for all types.
		/// self /= value
		/// </summary>
		/// <param name="value">The second operand.</param>
		/// <returns>self</returns>
		auto operator /=(T value) -> StreamVariable&;

		/// <summary>
		/// Arithmetic modulo.
		/// Implemented for all types.
		/// self %= value
		/// </summary>
		/// <param name="value">The second operand.</param>
		/// <returns>self</returns>
		auto Mod(T value) -> StreamVariable&;

		/// <summary>
		/// Arithmetic modulo.
		/// Implemented for all types.
		/// self %= value
		/// </summary>
		/// <param name="value">The second operand.</param>
		/// <returns>self</returns>
		auto operator %=(T value) -> StreamVariable&;

		/// <summary>
		/// Bitwise &.
		/// Implemented for int and uint.
		/// self &= value
		/// </summary>
		/// <param name="value">The second operand.</param>
		/// <returns>self</returns>
		auto And(T value) -> StreamVariable&;

		/// <summary>
		/// Bitwise &.
		/// Implemented for int and uint.
		/// self &= value
		/// </summary>
		/// <param name="value">The second operand.</param>
		/// <returns>self</returns>
		auto operator &=(T value) -> StreamVariable&;

		/// <summary>
		/// Bitwise &.
		/// Implemented for int and uint.
		/// self |= value
		/// </summary>
		/// <param name="value">The second operand.</param>
		/// <returns>self</returns>
		auto Or(T value) -> StreamVariable&;

		/// <summary>
		/// Bitwise &.
		/// Implemented for int and uint.
		/// self |= value
		/// </summary>
		/// <param name="value">The second operand.</param>
		/// <returns>self</returns>
		auto operator |=(T value) -> StreamVariable&;

		/// <summary>
		/// Bitwise ^.
		/// Implemented for int and uint.
		/// self ^= value
		/// </summary>
		/// <param name="value">The second operand.</param>
		/// <returns>self</returns>
		auto Xor(T value) -> StreamVariable&;

		/// <summary>
		/// Bitwise ^.
		/// Implemented for int and uint.
		/// self ^= value
		/// </summary>
		/// <param name="value">The second operand.</param>
		/// <returns>self</returns>
		auto operator ^=(T value) -> StreamVariable&;

		/// <summary>
		/// Bitwise <<.
		/// Implemented for int and uint.
		/// self <<= value
		/// </summary>
		/// <param name="value">The second operand.</param>
		/// <returns>self</returns>
		auto ShiftLeft(T value) -> StreamVariable&;

		/// <summary>
		/// Bitwise <<.
		/// Implemented for int and uint.
		/// self <<= value
		/// </summary>
		/// <param name="value">The second operand.</param>
		/// <returns>self</returns>
		auto operator <<=(T value) -> StreamVariable&;

		/// <summary>
		/// Bitwise >>.
		/// Implemented for int and uint.
		/// self >>= value
		/// </summary>
		/// <param name="value">The second operand.</param>
		/// <returns>self</returns>
		auto ShiftRight(T value) -> StreamVariable&;

		/// <summary>
		/// Bitwise >>.
		/// Implemented for int and uint.
		/// self >>= value
		/// </summary>
		/// <param name="value">The second operand.</param>
		/// <returns>self</returns>
		auto operator >>=(T value) -> StreamVariable&;

		/// <summary>
		/// Bitwise <<<.
		/// Implemented for int and uint.
		/// self <<<= value
		/// </summary>
		/// <param name="value">The second operand.</param>
		/// <returns>self</returns>
		auto RotateLeft(T value) -> StreamVariable&;

		/// <summary>
		/// Bitwise >>.
		/// Implemented for int and uint.
		/// self >>>= value
		/// </summary>
		/// <param name="value">The second operand.</param>
		/// <returns>self</returns>
		auto RotateRight(T value) -> StreamVariable&;

		/// <summary>
		/// Pop variable from stack.
		/// </summary>
		~StreamVariable();

	private:
		auto Push(T value) -> StreamVariable&;
		auto DoNothing() -> StreamVariable&;

		Stream& Attached;
	};

	/// <summary>
	/// Faster version of (x % 2) == 0
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="x"></param>
	/// <returns></returns>
	template <typename T> requires std::is_integral_v<T>
	constexpr auto IsPowerOfTwo(const T x) noexcept -> bool
	{
		// See https://github.com/MarioSieg/Bit-Twiddling-Hacks-Collection/blob/master/bithax.h
		return !(x & x - 1);
	}

	inline const double CACHED_LOG2 {std::log(2.0)};

	template <typename T> requires StreamScalar<T>
	template <typename F, typename V> requires
		std::is_trivial_v<V>
		&& (std::is_floating_point_v<V>
			|| std::is_integral_v<V>)
	inline auto StreamVariable<T>::Another(const V value, F&& functor) -> void
	{
		if constexpr (std::is_same_v<int, V>)
		{
			return functor(StreamVariable<std::int64_t> {this->Attached, static_cast<std::int64_t>(value)});
		}
		else
		{
			return functor(StreamVariable<V> {this->Attached, value});
		}
	}

	template <>
	// ReSharper disable once CppMemberFunctionMayBeConst
	inline auto StreamVariable<double>::Push(const double value) -> StreamVariable&
	{
		if (OptLevel >= OptimizationLevel::O1)
		[[likely]]
		{
			// If zero, optimize with special push zero instruction.
			if (value == 0.0)
			{
				this->Attached.Do<Instruction::PushZ>();
				return *this;
			}

			// If one, optimize with special push float one instruction.
			if (value == 1.0)
			{
				this->Attached.Do<Instruction::FPushO>();
				return *this;
			}

			// If the value is the previous written element in the stream,
			// we can just duplicate it:
			if (this->Attached.Back().Contains(value))
			{
				this->Attached.Do<Instruction::Dupl>();
				return *this;
			}
		}

		// Else just do a push:
		this->Attached.Do<Instruction::Push>(value);
		return *this;
	}

	template <>
	// ReSharper disable once CppMemberFunctionMayBeConst
	inline auto StreamVariable<std::int64_t>::Push(const std::int64_t value) -> StreamVariable&
	{
		if (OptLevel >= OptimizationLevel::O1)
		[[likely]]
		{
			// If zero, optimize with special push zero instruction.
			if (value == 0)
			{
				this->Attached.Do<Instruction::PushZ>();
				return *this;
			}

			// If one, optimize with special push integer one instruction.
			if (value == 1)
			{
				this->Attached.Do<Instruction::IPushO>();
				return *this;
			}

			// If the value is the previous written element in the stream,
			// we can just duplicate it:
			if (this->Attached.Back().Contains(value))
			{
				this->Attached.Do<Instruction::Dupl>();
				return *this;
			}
		}

		// Else just do a push:
		this->Attached.Do<Instruction::Push>(value);
		return *this;
	}

	template <>
	// ReSharper disable once CppMemberFunctionMayBeConst
	inline auto StreamVariable<std::uint64_t>::Push(const std::uint64_t value) -> StreamVariable&
	{
		if (OptLevel >= OptimizationLevel::O1)
		[[likely]]
		{
			// If zero, optimize with special push zero instruction.
			if (value == 0)
			{
				this->Attached.Do<Instruction::PushZ>();
				return *this;
			}

			// If one, optimize with special push integer one instruction.
			if (value == 1)
			{
				this->Attached.Do<Instruction::IPushO>();
				return *this;
			}

			// If the value is the previous written element in the stream,
			// we can just duplicate it:
			if (this->Attached.Back().Contains(value))
			{
				this->Attached.Do<Instruction::Dupl>();
				return *this;
			}
		}
		// Else just do a push:
		this->Attached.Do<Instruction::Push>(value);
		return *this;
	}

	template <typename T> requires StreamScalar<T>
	inline auto StreamVariable<T>::DoNothing() -> StreamVariable&
	{
		if (OptLevel == OptimizationLevel::Off)
		[[unlikely]]
		{
			// ReSharper disable once CppRedundantTemplateKeyword
			this->Attached.template Do<Instruction::NOp>();
		}
		return *this;
	}

	template <>
	inline StreamVariable<double>::StreamVariable(Stream& attached, const double value) : Attached {attached}
	{
		this->Push(value);
	}

	template <>
	inline StreamVariable<std::int64_t>::StreamVariable(Stream& attached, const std::int64_t value) : Attached {attached}
	{
		this->Push(value);
	}

	template <>
	inline StreamVariable<std::uint64_t>::StreamVariable(Stream& attached, const std::uint64_t value) : Attached {attached}
	{
		this->Push(value);
	}

	template <>
	// ReSharper disable once CppMemberFunctionMayBeConst
	inline auto StreamVariable<double>::Add(const double value) -> StreamVariable&
	{
		if (OptLevel >= OptimizationLevel::O1)
		[[likely]]
		{
			// With 0 it's a no-op
			if (value == 0.0)
			[[unlikely]]
			{
				return this->DoNothing();
			}

			// Optimize to increment:
			if (value == 1.0)
			{
				this->Attached.Do<Instruction::FInc>();
				return *this;
			}
		}
		this->Push(value);
		this->Attached.Do<Instruction::FAdd>();
		return *this;
	}

	template <>
	// ReSharper disable once CppMemberFunctionMayBeConst
	inline auto StreamVariable<std::int64_t>::Add(const std::int64_t value) -> StreamVariable&
	{
		if (OptLevel >= OptimizationLevel::O1)
		[[likely]]
		{
			// With 0 it's a no-op
			if (value == 0)
			[[unlikely]]
			{
				return this->DoNothing();
			}

			// Optimize to increment:
			if (value == 1)
			{
				this->Attached.Do<Instruction::IInc>();
				return *this;
			}
		}
		this->Push(value);
		this->Attached.Do<Instruction::IAdd>();
		return *this;
	}

	template <typename T> requires StreamScalar<T>
	inline auto StreamVariable<T>::operator+=(const T value) -> StreamVariable&
	{
		return this->Add(value);
	}

	template <>
	// ReSharper disable once CppMemberFunctionMayBeConst
	inline auto StreamVariable<std::uint64_t>::Add(const std::uint64_t value) -> StreamVariable&
	{
		if (OptLevel >= OptimizationLevel::O1)
		[[likely]]
		{
			// With 0 it's a no-op
			if (value == 0)
			[[unlikely]]
			{
				return this->DoNothing();
			}

			// Optimize to increment:
			if (value == 1)
			{
				this->Attached.Do<Instruction::IInc>();
				return *this;
			}
		}
		this->Push(value);
		this->Attached.Do<Instruction::IAdd>();
		return *this;
	}

	template <>
	// ReSharper disable once CppMemberFunctionMayBeConst
	inline auto StreamVariable<double>::Sub(const double value) -> StreamVariable&
	{
		if (OptLevel >= OptimizationLevel::O1)
		[[likely]]
		{
			// With 0 it's a no-op
			if (value == 0.0)
			[[unlikely]]
			{
				return this->DoNothing();
			}

			// Optimize to decrement:
			if (value == 1.0)
			{
				this->Attached.Do<Instruction::FDec>();
				return *this;
			}
		}
		this->Push(value);
		this->Attached.Do<Instruction::FSub>();
		return *this;
	}

	template <>
	// ReSharper disable once CppMemberFunctionMayBeConst
	inline auto StreamVariable<std::int64_t>::Sub(const std::int64_t value) -> StreamVariable&
	{
		if (OptLevel >= OptimizationLevel::O1)
		[[likely]]
		{
			// With 0 it's a no-op
			if (value == 0)
			[[unlikely]]
			{
				return this->DoNothing();
			}

			// Optimize to decrement:
			if (value == 1)
			{
				this->Attached.Do<Instruction::IDec>();
				return *this;
			}
		}
		this->Push(value);
		this->Attached.Do<Instruction::ISub>();
		return *this;
	}

	template <>
	// ReSharper disable once CppMemberFunctionMayBeConst
	inline auto StreamVariable<std::uint64_t>::Sub(const std::uint64_t value) -> StreamVariable&
	{
		if (OptLevel >= OptimizationLevel::O1)
		[[likely]]
		{
			// With 0 it's a no-op
			if (value == 0)
			[[unlikely]]
			{
				return this->DoNothing();
			}

			// Optimize to decrement:
			if (value == 1)
			{
				this->Attached.Do<Instruction::IDec>();
				return *this;
			}
		}
		this->Push(value);
		this->Attached.Do<Instruction::ISub>();
		return *this;
	}

	template <typename T> requires StreamScalar<T>
	inline auto StreamVariable<T>::operator-=(const T value) -> StreamVariable&
	{
		return this->Add(value);
	}

	template <>
	// ReSharper disable once CppMemberFunctionMayBeConst
	inline auto StreamVariable<double>::Mul(const double value) -> StreamVariable&
	{
		if (OptLevel >= OptimizationLevel::O1)
		[[likely]]
		{
			// By 0 or 1 is a no-op:
			if (value == 0.0 || value == 1.0)
			[[unlikely]]
			{
				return this->DoNothing();
			}
		}
		this->Push(value);
		this->Attached.Do<Instruction::FMul>();
		return *this;
	}

	template <typename T> requires StreamScalar<T>
	inline auto StreamVariable<T>::operator*=(const T value) -> StreamVariable&
	{
		return this->Mul(value);
	}

	template <>
	// ReSharper disable once CppMemberFunctionMayBeConst
	inline auto StreamVariable<std::int64_t>::Mul(std::int64_t value) -> StreamVariable&
	{
		if (OptLevel >= OptimizationLevel::O1)
		[[likely]]
		{
			// By 0 or 1 is a no-op:
			if (value == 0 || value == 1)
			[[unlikely]]
			{
				return this->DoNothing();
			}

			// Optimize with shift:
			if (IsPowerOfTwo(value))
			{
				value = static_cast<decltype(value)>(std::log(value) / CACHED_LOG2);
				this->Push(value);
				this->Attached.Do<Instruction::ISal>();
				return *this;
			}
		}
		this->Push(value);
		this->Attached.Do<Instruction::IMul>();
		return *this;
	}

	template <>
	// ReSharper disable once CppMemberFunctionMayBeConst
	inline auto StreamVariable<std::uint64_t>::Mul(std::uint64_t value) -> StreamVariable&
	{
		if (OptLevel >= OptimizationLevel::O1)
		[[likely]]
		{
			// By 0 or 1 is a no-op:
			if (value == 0 || value == 1)
			[[unlikely]]
			{
				return this->DoNothing();
			}

			// Optimize with shift:
			if (IsPowerOfTwo(value))
			{
				value = static_cast<decltype(value)>(std::log(value) / CACHED_LOG2);
				this->Push(value);
				this->Attached.Do<Instruction::ISal>();
				return *this;
			}
		}
		this->Push(value);
		this->Attached.Do<Instruction::IMul>();
		return *this;
	}

	template <>
	// ReSharper disable once CppMemberFunctionMayBeConst
	inline auto StreamVariable<double>::Div(const double value) -> StreamVariable&
	{
		if (OptLevel >= OptimizationLevel::O1)
		[[likely]]
		{
			// By 1 is a no-op:
			if (value == 1.0)
			[[unlikely]]
			{
				return this->DoNothing();
			}
		}
		this->Push(value);
		this->Attached.Do<Instruction::FDiv>();
		return *this;
	}

	template <typename T> requires StreamScalar<T>
	inline auto StreamVariable<T>::operator/=(const T value) -> StreamVariable&
	{
		return this->Div(value);
	}

	template <>
	// ReSharper disable once CppMemberFunctionMayBeConst
	inline auto StreamVariable<std::int64_t>::Div(std::int64_t value) -> StreamVariable&
	{
		if (OptLevel >= OptimizationLevel::O1)
		[[likely]]
		{
			// By 1 is a no-op:
			if (value == 1)
			[[unlikely]]
			{
				return this->DoNothing();
			}

			// Optimize with shift:
			if (IsPowerOfTwo(value))
			{
				value = static_cast<decltype(value)>(std::log(value) / CACHED_LOG2);
				this->Push(value);
				this->Attached.Do<Instruction::ISar>();
				return *this;
			}
		}

		this->Push(value);
		this->Attached.Do<Instruction::IDiv>();
		return *this;
	}

	template <>
	// ReSharper disable once CppMemberFunctionMayBeConst
	inline auto StreamVariable<std::uint64_t>::Div(std::uint64_t value) -> StreamVariable&
	{
		if (OptLevel >= OptimizationLevel::O1)
		[[likely]]
		{
			// By 1 is a no-op:
			if (value == 1)
			[[unlikely]]
			{
				return this->DoNothing();
			}

			// Optimize with shift:
			if (IsPowerOfTwo(value))
			{
				value = static_cast<decltype(value)>(std::log(value) / CACHED_LOG2);
				this->Push(value);
				this->Attached.Do<Instruction::ISar>();
				return *this;
			}
		}
		this->Push(value);
		this->Attached.Do<Instruction::IDiv>();
		return *this;
	}

	template <>
	// ReSharper disable once CppMemberFunctionMayBeConst
	inline auto StreamVariable<double>::Mod(const double value) -> StreamVariable&
	{
		this->Push(value);
		this->Attached.Do<Instruction::FMod>();
		return *this;
	}

	template <>
	// ReSharper disable once CppMemberFunctionMayBeConst
	inline auto StreamVariable<std::int64_t>::Mod(const std::int64_t value) -> StreamVariable&
	{
		this->Push(value);
		this->Attached.Do<Instruction::IMod>();
		return *this;
	}

	template <>
	// ReSharper disable once CppMemberFunctionMayBeConst
	inline auto StreamVariable<std::uint64_t>::Mod(const std::uint64_t value) -> StreamVariable&
	{
		this->Push(value);
		this->Attached.Do<Instruction::IMod>();
		return *this;
	}

	template <typename T> requires StreamScalar<T>
	inline auto StreamVariable<T>::operator%=(const T value) -> StreamVariable&
	{
		return this->Mod(value);
	}

	template <>
	// ReSharper disable once CppMemberFunctionMayBeConst
	inline auto StreamVariable<std::int64_t>::And(const std::int64_t value) -> StreamVariable&
	{
		this->Push(value);
		this->Attached.Do<Instruction::IAnd>();
		return *this;
	}

	template <>
	// ReSharper disable once CppMemberFunctionMayBeConst
	inline auto StreamVariable<std::uint64_t>::And(const std::uint64_t value) -> StreamVariable&
	{
		this->Push(value);
		this->Attached.Do<Instruction::IAnd>();
		return *this;
	}

	template <typename T> requires StreamScalar<T>
	inline auto StreamVariable<T>::operator&=(const T value) -> StreamVariable&
	{
		return this->And(value);
	}

	template <>
	// ReSharper disable once CppMemberFunctionMayBeConst
	inline auto StreamVariable<std::int64_t>::Or(const std::int64_t value) -> StreamVariable&
	{
		this->Push(value);
		this->Attached.Do<Instruction::IOr>();
		return *this;
	}

	template <typename T> requires StreamScalar<T>
	inline auto StreamVariable<T>::operator|=(const T value) -> StreamVariable&
	{
		return this->Or(value);
	}

	template <>
	// ReSharper disable once CppMemberFunctionMayBeConst
	inline auto StreamVariable<std::uint64_t>::Or(const std::uint64_t value) -> StreamVariable&
	{
		this->Push(value);
		this->Attached.Do<Instruction::IOr>();
		return *this;
	}

	template <>
	// ReSharper disable once CppMemberFunctionMayBeConst
	inline auto StreamVariable<std::int64_t>::Xor(const std::int64_t value) -> StreamVariable&
	{
		this->Push(value);
		this->Attached.Do<Instruction::IXor>();
		return *this;
	}

	template <>
	// ReSharper disable once CppMemberFunctionMayBeConst
	inline auto StreamVariable<std::uint64_t>::Xor(const std::uint64_t value) -> StreamVariable&
	{
		this->Push(value);
		this->Attached.Do<Instruction::IXor>();
		return *this;
	}

	template <typename T> requires StreamScalar<T>
	inline auto StreamVariable<T>::operator^=(const T value) -> StreamVariable&
	{
		return this->Xor(value);
	}

	template <>
	// ReSharper disable once CppMemberFunctionMayBeConst
	inline auto StreamVariable<std::int64_t>::ShiftLeft(const std::int64_t value) -> StreamVariable&
	{
		if (value == 0)
		[[unlikely]]
		{
			return this->DoNothing();
		}
		this->Push(value);
		this->Attached.Do<Instruction::ISal>();
		return *this;
	}

	template <typename T> requires StreamScalar<T>
	inline auto StreamVariable<T>::operator<<=(const T value) -> StreamVariable&
	{
		return this->ShiftLeft(value);
	}

	template <>
	// ReSharper disable once CppMemberFunctionMayBeConst
	inline auto StreamVariable<std::uint64_t>::ShiftLeft(const std::uint64_t value) -> StreamVariable&
	{
		if (value == 0)
		[[unlikely]]
		{
			return this->DoNothing();
		}
		this->Push(value);
		this->Attached.Do<Instruction::ISal>();
		return *this;
	}

	template <>
	// ReSharper disable once CppMemberFunctionMayBeConst
	inline auto StreamVariable<std::int64_t>::ShiftRight(const std::int64_t value) -> StreamVariable&
	{
		if (value == 0)
		[[unlikely]]
		{
			return this->DoNothing();
		}
		this->Push(value);
		this->Attached.Do<Instruction::ISar>();
		return *this;
	}

	template <typename T> requires StreamScalar<T>
	inline auto StreamVariable<T>::operator>>=(const T value) -> StreamVariable&
	{
		return this->ShiftRight(value);
	}

	template <>
	// ReSharper disable once CppMemberFunctionMayBeConst
	inline auto StreamVariable<std::uint64_t>::ShiftRight(const std::uint64_t value) -> StreamVariable&
	{
		if (value == 0)
		[[unlikely]]
		{
			return this->DoNothing();
		}
		this->Push(value);
		this->Attached.Do<Instruction::ISar>();
		return *this;
	}

	template <>
	// ReSharper disable once CppMemberFunctionMayBeConst
	inline auto StreamVariable<std::int64_t>::RotateLeft(const std::int64_t value) -> StreamVariable&
	{
		if (value == 0)
		[[unlikely]]
		{
			return this->DoNothing();
		}
		this->Push(value);
		this->Attached.Do<Instruction::IRol>();
		return *this;
	}

	template <>
	// ReSharper disable once CppMemberFunctionMayBeConst
	inline auto StreamVariable<std::uint64_t>::RotateLeft(const std::uint64_t value) -> StreamVariable&
	{
		if (value == 0)
		[[unlikely]]
		{
			return this->DoNothing();
		}
		this->Push(value);
		this->Attached.Do<Instruction::IRol>();
		return *this;
	}

	template <>
	// ReSharper disable once CppMemberFunctionMayBeConst
	inline auto StreamVariable<std::int64_t>::RotateRight(const std::int64_t value) -> StreamVariable&
	{
		if (value == 0)
		[[unlikely]]
		{
			return this->DoNothing();
		}
		this->Push(value);
		this->Attached.Do<Instruction::IRor>();
		return *this;
	}

	template <>
	// ReSharper disable once CppMemberFunctionMayBeConst
	inline auto StreamVariable<std::uint64_t>::RotateRight(const std::uint64_t value) -> StreamVariable&
	{
		if (value == 0)
		[[unlikely]]
		{
			return this->DoNothing();
		}
		this->Push(value);
		this->Attached.Do<Instruction::IRor>();
		return *this;
	}

	template <typename T> requires StreamScalar<T>
	inline StreamVariable<T>::~StreamVariable()
	{
		Attached.Do<Instruction::Pop>();
	}

	/// <summary>
	/// Stream variable with runtime type: int
	/// </summary>
	using SvInt = StreamVariable<std::int64_t>;

	/// <summary>
	/// Stream variable with runtime type: uint
	/// </summary>
	using SvUInt = StreamVariable<std::uint64_t>;

	/// <summary>
	/// Stream variable with runtime type: float
	/// </summary>
	using SvFloat = StreamVariable<double>;

	/// <summary>
	/// Contains lexical tokens required to parse and write byte code.
	/// </summary>
	namespace Lexemes
	{
		/// <summary>
		/// Specify immediate constant operand.
		/// </summary>
		constexpr auto IMMEDIATE {'%'};

		/// <summary>
		/// Begin or end comment.
		/// </summary>
		constexpr auto COMMENT {'$'};

		/// <summary>
		/// Begin preprocessor directive.
		/// </summary>
		constexpr auto PREPROCESSOR {'#'};
	}
}
