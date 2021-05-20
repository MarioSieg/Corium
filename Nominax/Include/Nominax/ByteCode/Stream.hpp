// File: Stream.hpp
// Author: Mario
// Created: 25.04.2021 12:41 PM
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

#include <vector>
#include <functional>

#include "DynamicSignal.hpp"
#include "ImmediateArgumentCount.hpp"
#include "ByteCodeValidationResult.hpp"
#include "OptBase.hpp"
#include "StreamScalar.hpp"
#include "Chunk.hpp"

namespace Nominax
{
	template <typename T> requires StreamScalar<T>
	class ScopedVariable;

	template <typename T>
	class ScopedVariableProxyType final
	{
		using Type = std::decay_t<T>;
	};

	template <>
	class ScopedVariableProxyType<signed>
	{
		using Type = I64;
	};

	class Stream;

	/// <summary>
	/// Restrict stream expression type.
	/// </summary>
	template <typename F, typename V>
	concept StreamWithExpressionType = requires
	{
		requires std::is_trivial_v<V>;
		requires std::is_floating_point_v<V> || std::is_integral_v<V>;
		// TODO: Validate that F() is callable with F(V, ScopedVariable<ScopedVariableProxyType<V>>)
	};

	/// <summary>
	/// Execution ready byte code and jump map.
	/// </summary>
	using AppCodeBundle = std::tuple<CodeChunk, JumpMap>;

	/// <summary>
	/// Dynamic byte code stream.
	/// </summary>
	class Stream final
	{
	public:
		/// <summary>
		/// Data structure used for storing the dynamic signals.
		/// </summary>
		using StorageType = std::vector<DynamicSignal>;

	private:
		StorageType Storage_ { };

		/// <summary>
		/// Optimization level used for stream.
		/// </summary>
		OptimizationLevel OptimizationLevel_ {DefaultOptimizationLevel()};

		/// <summary>
		/// Contains the count of instruction in the stream.
		/// Used for optimizations (pre allocating validator instruction cache).
		/// </summary>
		std::size_t InstructionCounter_ {0};

	public:
		/// <summary>
		/// Construct empty stream.
		/// </summary>
		/// <returns></returns>
		Stream() noexcept(true) = default;

		/// <summary>
		/// Construct with data.
		/// </summary>
		/// <param name="data"></param>
		/// <returns></returns>
		explicit Stream(StorageType&& data) noexcept(true);

		/// <summary>
		/// Construct with specific optimization level.
		/// </summary>
		/// <param name="optimizationLevel"></param>
		/// <returns></returns>
		explicit Stream(OptimizationLevel optimizationLevel) noexcept(true);

		/// <summary>
		/// Construct with data and specific optimization level.
		/// </summary>
		/// <param name="data"></param>
		/// <param name="optimizationLevel"></param>
		/// <returns></returns>
		explicit Stream(StorageType&& data, OptimizationLevel optimizationLevel) noexcept(true);

		/// <summary>
		/// Move constructor.
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		Stream(Stream&& other) noexcept(true) = default;

		/// <summary>
		/// Copy constructor.
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		Stream(const Stream& other) noexcept(true) = default;

		/// <summary>
		/// Copy assignment operator.
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		auto operator =(const Stream& other) -> Stream& = default;

		/// <summary>
		/// Move assignment operator.
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		auto operator =(Stream&& other) -> Stream& = default;

		/// <summary>
		/// Destructor.
		/// </summary>
		~Stream() = default;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The vector used as buffer.</returns>
		[[nodiscard]]
		auto Buffer() const noexcept(true) -> const StorageType&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto Front() noexcept(true) -> DynamicSignal&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto Back() noexcept(true) -> DynamicSignal&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto Front() const noexcept(true) -> const DynamicSignal&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto Back() const noexcept(true) -> const DynamicSignal&;

		/// <summary>
		/// Clears the content of the whole stream.
		/// </summary>
		/// <returns></returns>
		auto Clear() noexcept(false) -> void;

		/// <summary>
		/// Resize buffer size.
		/// </summary>
		/// <param name="size"></param>
		/// <returns></returns>
		auto Resize(std::size_t size) noexcept(false) -> void;

		/// <summary>
		/// Reserve buffer size.
		/// </summary>
		/// <param name="size"></param>
		/// <returns></returns>
		auto Reserve(std::size_t size) noexcept(false) -> void;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The size of the stream.</returns>
		[[nodiscard]]
		auto Size() const noexcept(true) -> std::size_t;

		/// <summary>
		/// Returns true if the stream contains
		/// no code or only prologue and or epilogue.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto IsEmpty() const noexcept(true) -> bool;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The size of the stream in bytes.</returns>
		[[nodiscard]]
		auto SizeInBytes() const noexcept(true) -> std::size_t;

		/// <summary>
		/// Insert range.
		/// </summary>
		/// <param name="begin"></param>
		/// <param name="end"></param>
		/// <returns></returns>
		template <typename Iterator>
		auto Insert(Iterator begin, Iterator end) noexcept(false) -> void;

		/// <summary>
		/// STL iterator compat
		/// </summary>
		/// <returns></returns>
		// ReSharper disable once CppInconsistentNaming
		[[nodiscard]]
		auto begin() noexcept(true) -> StorageType::iterator;

		/// <summary>
		/// STL iterator compat
		/// </summary>
		/// <returns></returns>
		// ReSharper disable once CppInconsistentNaming
		[[nodiscard]]
		auto end() noexcept(true) -> StorageType::iterator;

		/// <summary>
		/// STL iterator compat
		/// </summary>
		/// <returns></returns>
		// ReSharper disable once CppInconsistentNaming
		[[nodiscard]]
		auto begin() const noexcept(true) -> StorageType::const_iterator;

		/// <summary>
		/// STL iterator compat
		/// </summary>
		/// <returns></returns>
		// ReSharper disable once CppInconsistentNaming
		[[nodiscard]]
		auto end() const noexcept(true) -> StorageType::const_iterator;

		/// <summary>
		/// Push stream entry.
		/// </summary>
		/// <param name="sig"></param>
		/// <returns></returns>
		auto operator <<(const DynamicSignal& sig) noexcept(false) -> Stream&;

		/// <summary>
		/// Push stream entry.
		/// </summary>
		/// <param name="instr"></param>
		/// <returns></returns>
		auto operator <<(Instruction instr) noexcept(false) -> Stream&;

		/// <summary>
		/// Push stream entry.
		/// </summary>
		/// <param name="intrin"></param>
		/// <returns></returns>
		auto operator <<(SystemIntrinsicCallId intrin) noexcept(false) -> Stream&;

		/// <summary>
		/// Push stream entry.
		/// </summary>
		/// <param name="intrin"></param>
		/// <returns></returns>
		auto operator <<(CustomIntrinsicCallId intrin) noexcept(false) -> Stream&;

		/// <summary>
		/// Push stream entry.
		/// </summary>
		/// <param name="address"></param>
		/// <returns></returns>
		auto operator <<(JumpAddress address) noexcept(false) -> Stream&;

		/// <summary>
		/// Push stream entry.
		/// </summary>
		/// <param name="value"></param>
		/// <returns></returns>
		auto operator <<(U64 value) noexcept(false) -> Stream&;

		/// <summary>
		/// Push stream entry.
		/// </summary>
		/// <param name="value"></param>
		/// <returns></returns>
		auto operator <<(I64 value) noexcept(false) -> Stream&;

		/// <summary>
		/// Sign extend 32-bit signed integer to I64 and push.
		/// </summary>
		/// <param name="value"></param>
		/// <returns></returns>
		auto operator <<(signed value) noexcept(false) -> Stream&;

		/// <summary>
		/// Push stream entry.
		/// </summary>
		/// <param name="value"></param>
		/// <returns></returns>
		auto operator <<(F64 value) noexcept(false) -> Stream&;

		/// <summary>
		/// Push stream entry.
		/// </summary>
		/// <param name="value"></param>
		/// <returns></returns>
		auto operator <<(CharClusterUtf8 value) noexcept(false) -> Stream&;

		/// <summary>
		/// Print out the ir.
		/// </summary>
		/// <returns></returns>
		auto PrintIntermediateRepresentation() const noexcept(false) -> void;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The instruction count of the stream.</returns>
		auto GetInstructionCount() const noexcept(true) -> std::size_t;

		/// <summary>
		/// Index lookup.
		/// Slow! O(i)
		/// </summary>
		/// <param name="idx"></param>
		/// <returns></returns>
		auto operator [](std::size_t idx) noexcept(false) -> DynamicSignal&;

		/// <summary>
		/// Index lookup.
		///Slow! O(i)
		/// </summary>
		/// <param name="idx"></param>
		/// <returns></returns>
		auto operator [](std::size_t idx) const noexcept(false) -> const DynamicSignal&;

		/// <summary>
		/// Insert instruction manually with immediate arguments.
		/// </summary>
		/// <param name="args"></param>
		/// <returns></returns>
		template <Instruction I, typename... Ts>
		auto Do(Ts&&...args) noexcept(false) -> Stream&;

		/// <summary>
		/// Insert instruction manually without immediate arguments.
		/// </summary>
		/// <returns></returns>
		template <Instruction I>
		auto Do() noexcept(false) -> Stream&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>True if the current stream contains required epilogue code, else false.</returns>
		[[nodiscard]]
		auto ContainsEpilogue() const noexcept(false) -> bool;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>True if the current stream contains required prologue code, else false.</returns>
		[[nodiscard]]
		auto ContainsPrologue() const noexcept(false) -> bool;

		/// <summary>
		/// Begin stream building.
		/// Inserts code prologue, if missing.
		/// </summary>
		/// <returns></returns>
		auto Prologue() noexcept(false) -> Stream&;

		/// <summary>
		/// End stream building.
		/// Inserts code epilogue, if missing.
		/// </summary>
		/// <returns></returns>
		auto Epilogue() noexcept(false) -> Stream&;

		/// <summary>
		/// Map new local variable into the stream.
		/// It is a scoped variable, which means it is automatically popped,
		/// when it goes out of the lambda scope.
		/// </summary>
		/// <typeparam name="F"></typeparam>
		/// <typeparam name="V"></typeparam>
		/// <param name="value"></param>
		/// <param name="functor"></param>
		/// <returns>self</returns>
		template <typename F, typename V> requires StreamWithExpressionType<F, V>
		auto With(V value, F&& functor) noexcept(false) -> Stream&;

		/// <summary>
		/// Validate and build code chunk plus jump map.
		/// </summary>
		/// <param name="out"></param>
		/// <param name="outJumpMap"></param>
		/// <returns></returns>
		auto Build(CodeChunk& out, JumpMap& outJumpMap) const noexcept(false) -> ByteCodeValidationResult;

		/// <summary>
		/// Validate and build code chunk plus jump map into app code bundle.
		/// </summary>
		/// <param name="out"></param>
		/// <returns></returns>
		auto Build(AppCodeBundle& out) const noexcept(false) -> ByteCodeValidationResult;

		/// <summary>
		/// Get current optimization level.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto GetOptimizationLevel() const noexcept(true) -> OptimizationLevel;

		/// <summary>
		/// Set current optimization level.
		/// </summary>
		/// <param name="optimizationLevel"></param>
		/// <returns></returns>
		auto SetOptimizationLevel(OptimizationLevel optimizationLevel) noexcept(true) -> void;
	};

	inline Stream::Stream(StorageType&& data) noexcept(true) : Storage_ {std::move(data)} { }

	inline Stream::Stream(const OptimizationLevel optimizationLevel) noexcept(true) : OptimizationLevel_ {optimizationLevel} { }

	inline Stream::Stream(StorageType&& data, const OptimizationLevel optimizationLevel) noexcept(true) : Storage_ {std::move(data)}, OptimizationLevel_ {optimizationLevel} {}

	inline auto Stream::GetOptimizationLevel() const noexcept(true) -> OptimizationLevel
	{
		return this->OptimizationLevel_;
	}

	inline auto Stream::SetOptimizationLevel(const OptimizationLevel optimizationLevel) noexcept(true) -> void
	{
		this->OptimizationLevel_ = optimizationLevel;
	}

	inline auto Stream::Build(AppCodeBundle& out) const noexcept(false) -> ByteCodeValidationResult
	{
		return this->Build(std::get<0>(out), std::get<1>(out));
	}

	template <Instruction I, typename... Ts>
	inline auto Stream::Do(Ts&&...args) noexcept(false) -> Stream&
	{
		static_assert(sizeof...(Ts) == INSTRUCTION_IMMEDIATE_ARGUMENT_COUNTS[static_cast<std::size_t>(I)], "Invalid amount of immediate arguments!");
		static_assert(std::is_trivial_v<std::remove_reference_t<Ts>...>, "Invalid argument types!");
		static_assert(std::is_integral_v<std::remove_reference_t<Ts>...>
			|| std::is_floating_point_v<std::remove_reference_t<Ts>...>
			|| std::is_enum_v<std::remove_reference_t<Ts>...>, "Invalid argument types!");
		static_assert((sizeof(std::remove_reference_t<Ts>) + ... + 0) % sizeof(I64) == 0
			|| (sizeof(std::remove_reference_t<Ts>) + ... + 0) % sizeof(I32) == 0,
			"Invalid argument types!");
		*this << I;
		return (*this << ... << args);
	}

	template <Instruction I>
	inline auto Stream::Do() noexcept(false) -> Stream&
	{
		return *this << I;
	}

	template <typename F, typename V> requires StreamWithExpressionType<F, V>
	inline auto Stream::With(const V value, F&& functor) noexcept(false) -> Stream&
	{
		if constexpr (std::is_same_v<signed, V>)
		{
			functor(ScopedVariable<I64> {*this, static_cast<I64>(value)});
		}
		else
		{
			functor(ScopedVariable<V> {*this, value});
		}
		return *this;
	}

	inline auto Stream::Front() noexcept(true) -> DynamicSignal&
	{
		return this->Storage_.front();
	}

	inline auto Stream::Back() noexcept(true) -> DynamicSignal&
	{
		return this->Storage_.back();
	}

	inline auto Stream::Front() const noexcept(true) -> const DynamicSignal&
	{
		return this->Storage_.front();
	}

	inline auto Stream::Back() const noexcept(true) -> const DynamicSignal&
	{
		return this->Storage_.back();
	}

	inline auto Stream::GetInstructionCount() const noexcept(true) -> std::size_t
	{
		return this->InstructionCounter_;
	}

	inline auto Stream::operator[](const std::size_t idx) noexcept(false) -> DynamicSignal&
	{
		return this->Storage_[idx];
	}

	inline auto Stream::operator[](const std::size_t idx) const noexcept(false) -> const DynamicSignal&
	{
		return this->Storage_[idx];
	}

	inline auto Stream::IsEmpty() const noexcept(true) -> bool
	{
		return this->Storage_.empty();
	}

	inline auto Stream::Buffer() const noexcept(true) -> const StorageType&
	{
		return this->Storage_;
	}

	inline auto Stream::Clear() noexcept(false) -> void
	{
		this->Storage_.clear();
	}

	inline auto Stream::Resize(const std::size_t size) noexcept(false) -> void
	{
		this->Storage_.resize(size);
	}

	inline auto Stream::Reserve(const std::size_t size) noexcept(false) -> void
	{
		this->Storage_.reserve(size);
	}

	inline auto Stream::Size() const noexcept(true) -> std::size_t
	{
		return this->Storage_.size();
	}

	inline auto Stream::SizeInBytes() const noexcept(true) -> std::size_t
	{
		return this->Storage_.size() * sizeof(DynamicSignal);
	}

	template <typename Iterator>
	inline auto Stream::Insert(Iterator begin, Iterator end) noexcept(false) -> void
	{
		std::for_each(begin, end, [this](const DynamicSignal& sig)
		{
			this->Storage_.emplace_back(sig);
			if (sig.Contains<Instruction>())
			{
				++this->InstructionCounter_;
			}
		});
	}

	// ReSharper disable once CppInconsistentNaming
	inline auto Stream::begin() noexcept(true) -> StorageType::iterator
	{
		return std::begin(this->Storage_);
	}

	// ReSharper disable once CppInconsistentNaming
	inline auto Stream::end() noexcept(true) -> StorageType::iterator
	{
		return std::end(this->Storage_);
	}

	// ReSharper disable once CppInconsistentNaming
	inline auto Stream::begin() const noexcept(true) -> StorageType::const_iterator
	{
		return std::begin(this->Storage_);
	}

	// ReSharper disable once CppInconsistentNaming
	inline auto Stream::end() const noexcept(true) -> StorageType::const_iterator
	{
		return std::end(this->Storage_);
	}

	/// <summary>
	/// STL iterator compat.
	/// </summary>
	/// <param name="in"></param>
	/// <returns></returns>
	// ReSharper disable once CppInconsistentNaming
	inline auto begin(Stream& in) noexcept(true) -> Stream::StorageType::iterator
	{
		return in.begin();
	}

	/// <summary>
	/// STL iterator compat.
	/// </summary>
	/// <param name="in"></param>
	/// <returns></returns>
	// ReSharper disable once CppInconsistentNaming
	inline auto end(Stream& in) noexcept(true) -> Stream::StorageType::iterator
	{
		return in.end();
	}

	/// <summary>
	/// STL iterator compat.
	/// </summary>
	/// <param name="in"></param>
	/// <returns></returns>
	// ReSharper disable once CppInconsistentNaming
	inline auto begin(const Stream& in) noexcept(true) -> Stream::StorageType::const_iterator
	{
		return in.begin();
	}

	/// <summary>
	/// STL iterator compat.
	/// </summary>
	/// <param name="in"></param>
	/// <returns></returns>
	// ReSharper disable once CppInconsistentNaming
	inline auto end(const Stream& in) noexcept(true) -> Stream::StorageType::const_iterator
	{
		return in.end();
	}

	inline auto Stream::operator<<(const DynamicSignal& sig) noexcept(false) -> Stream&
	{
		this->Storage_.emplace_back(sig);
		return *this;
	}

	inline auto Stream::operator <<(const Instruction instr) noexcept(false) -> Stream&
	{
		this->Storage_.emplace_back(DynamicSignal {instr});
		++this->InstructionCounter_;
		return *this;
	}

	inline auto Stream::operator <<(const SystemIntrinsicCallId intrin) noexcept(false) -> Stream&
	{
		this->Storage_.emplace_back(DynamicSignal {intrin});
		return *this;
	}

	inline auto Stream::operator <<(const CustomIntrinsicCallId intrin) noexcept(false) -> Stream&
	{
		this->Storage_.emplace_back(DynamicSignal {intrin});
		return *this;
	}

	inline auto Stream::operator<<(const JumpAddress address) noexcept(false) -> Stream&
	{
		this->Storage_.emplace_back(DynamicSignal {address});
		return *this;
	}

	inline auto Stream::operator <<(const U64 value) noexcept(false) -> Stream&
	{
		this->Storage_.emplace_back(DynamicSignal {value});
		return *this;
	}

	inline auto Stream::operator <<(const I64 value) noexcept(false) -> Stream&
	{
		this->Storage_.emplace_back(DynamicSignal {value});
		return *this;
	}

	inline auto Stream::operator <<(const F64 value) noexcept(false) -> Stream&
	{
		this->Storage_.emplace_back(DynamicSignal {value});
		return *this;
	}

	inline auto Stream::operator<<(const signed value) noexcept(false) -> Stream&
	{
		this->Storage_.emplace_back(DynamicSignal {static_cast<I64>(value)});
		return *this;
	}

	inline auto Stream::operator <<(const CharClusterUtf8 value) noexcept(false) -> Stream&
	{
		this->Storage_.emplace_back(DynamicSignal {value});
		return *this;
	}
}
