// File: DynamicSignal.hpp
// Author: Mario
// Created: 24.04.2021 9:48 PM
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
#include <cstdint>
#include <optional>
#include <variant>

#include "../Common/RtTypes.hpp"
#include "../Common/LiteralOp.hpp"

#include "Signal.hpp"
#include "Instruction.hpp"
#include "SystemIntrinsic.hpp"
#include "CustomIntrinsic.hpp"

namespace Nominax
{
	/// <summary>
	/// Restricts to valid byte code elements.
	/// </summary>
	/// <typeparam name="...Ts">The generic types to perform restriction checks on.</typeparam>
	template <typename Ts>
	concept BytecodeElement = requires
	{
		requires sizeof(Ts) % sizeof(I32) == 0 || sizeof(Ts) % sizeof(I64) == 0;
		requires alignof(Ts) % alignof(I32) == 0 || alignof(Ts) % alignof(I64) == 0;
		requires
		std::is_same_v<Ts, Instruction>
		|| std::is_same_v<Ts, SystemIntrinsicCallId>
		|| std::is_same_v<Ts, CustomIntrinsicCallId>
		|| std::is_same_v<Ts, U64>
		|| std::is_same_v<Ts, I64>
		|| std::is_same_v<Ts, F64>
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
		using Variant = std::variant<Instruction, SystemIntrinsicCallId, CustomIntrinsicCallId, U64, I64, F64, char32_t>;

		/// <summary>
		/// Default construct an I64(0)
		/// </summary>
		/// <returns></returns>
		constexpr DynamicSignal() noexcept(true);

		/// <summary>
		/// Construct from data union.
		/// </summary>
		/// <param name="data">The initial value.</param>
		/// <returns></returns>
		explicit constexpr DynamicSignal(Variant&& data) noexcept(true);

		/// <summary>
		/// Construct from instruction.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr DynamicSignal(Instruction value) noexcept(true);

		/// <summary>
		/// Construct from 64-bit unsigned quadword integer.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr DynamicSignal(U64 value) noexcept(true);

		/// <summary>
		/// Construct from 64-bit signed quadword integer.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr DynamicSignal(I64 value) noexcept(true);

		/// <summary>
		/// Construct from 64-bit F64 precision F32.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr DynamicSignal(F64 value) noexcept(true);

		/// <summary>
		/// Construct from 32-bit UTF32 character.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr DynamicSignal(char32_t value) noexcept(true);

		/// <summary>
		/// Construct from system intrinsic call id.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr DynamicSignal(SystemIntrinsicCallId value) noexcept(true);

		/// <summary>
		/// Construct from custom intrinsic call id.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr DynamicSignal(CustomIntrinsicCallId value) noexcept(true);

		/// <summary>
		/// Copy constructor.
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		constexpr DynamicSignal(const DynamicSignal&) noexcept(true) = default;

		/// <summary>
		/// Move constructor.
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		constexpr DynamicSignal(DynamicSignal&&) noexcept(true) = default;

		/// <summary>
		/// Copy assignment operator.
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		constexpr auto operator =(const DynamicSignal&) noexcept(true) -> DynamicSignal& = default;

		/// <summary>
		/// Move assignment operator.
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		constexpr auto operator =(DynamicSignal&&) noexcept(true) -> DynamicSignal& = default;

		/// <summary>
		/// Destructor.
		/// </summary>
		~DynamicSignal() = default;


		/// <summary>
		/// Convert to undiscriminated runtime signal.
		/// </summary>
		[[nodiscard]]
		explicit operator Signal() const noexcept(false);

		/// <summary>
		/// Try to extract raw data.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <returns></returns>
		template <typename T> requires BytecodeElement<T>
		[[nodiscard]]
		constexpr auto Unwrap() const noexcept(false) -> std::optional<T>;

		/// <summary>
		/// Check if generic T is contained.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <returns></returns>
		template <typename T> requires BytecodeElement<T>
		[[nodiscard]]
		constexpr auto Contains() const noexcept(true) -> bool;

		/// <summary>
		/// Check if generic T and value is contained.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <param name="compareTo"></param>
		/// <returns></returns>
		template <typename T> requires BytecodeElement<T>
		[[nodiscard]]
		constexpr auto Contains(T compareTo) const noexcept(false) -> bool;

		/// <summary>
		/// Equals.
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		constexpr auto operator ==(const DynamicSignal& other) const noexcept(false) -> bool;

		/// <summary>
		/// Not equals.
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		constexpr auto operator !=(const DynamicSignal& other) const noexcept(false) -> bool;

		/// <summary>
		/// Raw data variant (discriminated union)
		/// </summary>
		Variant DataCollection { };

		/// <summary>
		/// Common code prologue.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		static constexpr auto CodePrologue() noexcept(true) -> std::array<DynamicSignal, 1>;

		/// <summary>
		/// Common code epilogue.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		static constexpr auto CodeEpilogue() noexcept(true) -> std::array<DynamicSignal, 2>;
	};

	/// <summary>
	/// This contains the total number of signals in the prologue + epilogue code.
	/// Each code chunk must have at least the size of this because prologue and epilogue are required.
	/// </summary>
	inline static const std::size_t MANDATORY_CODE_SIZE {DynamicSignal::CodePrologue().size() + DynamicSignal::CodeEpilogue().size()};


	/// <summary>
	/// Constructor.
	/// </summary>
	/// <returns></returns>
	constexpr DynamicSignal::DynamicSignal() noexcept(true) : DataCollection {UINT64_C(0)} {}

	/// <summary>
	/// Constructor.
	/// </summary>
	/// <returns></returns>
	constexpr DynamicSignal::DynamicSignal(Variant&& data) noexcept(true) : DataCollection {data} {}

	/// <summary>
	/// Constructor.
	/// </summary>
	/// <returns></returns>
	constexpr DynamicSignal::DynamicSignal(const Instruction value) noexcept(true) : DataCollection {value} {}

	/// <summary>
	/// Constructor.
	/// </summary>
	/// <returns></returns>
	constexpr DynamicSignal::DynamicSignal(const U64 value) noexcept(true) : DataCollection {value} {}

	/// <summary>
	/// Constructor.
	/// </summary>
	/// <returns></returns>
	constexpr DynamicSignal::DynamicSignal(const I64 value) noexcept(true) : DataCollection {value} {}

	/// <summary>
	/// Constructor.
	/// </summary>
	/// <returns></returns>
	constexpr DynamicSignal::DynamicSignal(const F64 value) noexcept(true) : DataCollection {value} {}

	/// <summary>
	/// Constructor.
	/// </summary>
	/// <returns></returns>
	constexpr DynamicSignal::DynamicSignal(const char32_t value) noexcept(true) : DataCollection {value} {}

	/// <summary>
	/// Constructor.
	/// </summary>
	/// <returns></returns>
	constexpr DynamicSignal::DynamicSignal(const SystemIntrinsicCallId value) noexcept(true) : DataCollection {value} {}

	/// <summary>
	/// Constructor.
	/// </summary>
	/// <returns></returns>
	constexpr DynamicSignal::DynamicSignal(const CustomIntrinsicCallId value) noexcept(true) : DataCollection {value} {}

	/// <summary>
	/// Equals
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	constexpr auto DynamicSignal::operator==(const DynamicSignal& other) const noexcept(false) -> bool
	{
		return this->DataCollection == other.DataCollection;
	}

	/// <summary>
	/// Not equals
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	constexpr auto DynamicSignal::operator!=(const DynamicSignal& other) const noexcept(false) -> bool
	{
		return !(*this == other);
	}

	constexpr auto DynamicSignal::CodePrologue() noexcept(true) -> std::array<DynamicSignal, 1>
	{
		// First instruction is always skipped and should be NOP:
		return
		{
			DynamicSignal {Instruction::NOp}
		};
	}

	constexpr auto DynamicSignal::CodeEpilogue() noexcept(true) -> std::array<DynamicSignal, 2>
	{
		return
		{
			DynamicSignal {Instruction::Int},
			DynamicSignal {0_int}
		};
	}

	template <typename T> requires BytecodeElement<T>
	constexpr auto DynamicSignal::Unwrap() const noexcept(false) -> std::optional<T>
	{
		return std::holds_alternative<T>(this->DataCollection)
			       ? std::optional<T> {std::get<T>(this->DataCollection)}
			       : std::nullopt;
	}

	template <typename T> requires BytecodeElement<T>
	constexpr auto DynamicSignal::Contains() const noexcept(true) -> bool
	{
		return std::holds_alternative<T>(this->DataCollection);
	}

	template <typename T> requires BytecodeElement<T>
	constexpr auto DynamicSignal::Contains(const T compareTo) const noexcept(false) -> bool
	{
		return std::holds_alternative<T>(this->DataCollection) && std::get<T>(this->DataCollection) == compareTo;
	}
}
