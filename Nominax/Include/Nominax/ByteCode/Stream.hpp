// File: Stream.hpp
// Author: Mario
// Created: 10.08.2021 12:57 PM
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

#include <cstdint>
#include "../Foundation/ISerializable.hpp"
#include "../Foundation/PanicAssertions.hpp"

#include "Image.hpp"
#include "Signal.hpp"
#include "DiscriminatedSignal.hpp"
#include "Optimization.hpp"
#include "ValidationResult.hpp"

namespace Nominax::ByteCode
{
	/// <summary>
	/// Dynamic byte code stream.
	/// </summary>
	class Stream final : public Foundation::ISerializable
	{
		/// <summary>
		/// Code section marker.
		/// </summary>
		static constexpr std::uint64_t STREAM_IMAGE_CODE_SECTION_MARKER {0x9FCF'2A4B'F10F'BEBA};

		/// <summary>
		/// Discriminator section marker.
		/// </summary>
		static constexpr std::uint64_t STREAM_IMAGE_DISCRIMINATOR_SECTION_MARKER {0x922C'232B'D183'ADDE};

		/// <summary>
		/// Encryption for the sizes.
		/// </summary>
		static constexpr std::uint64_t ENCRYPTION_KEY_ALPHA {0x160B490091BE68};

		/// <summary>
		/// Encryption for the sizes.
		/// </summary>
		static constexpr std::uint64_t ENCRYPTION_KEY_BETA {0x54746EC3DF441};

		/// <summary>
		/// Encryption for the sizes.
		/// </summary>
		static constexpr std::uint64_t ENCRYPTION_KEY_GAMMA {0x1672E3969FF6FC8};

	public:
		/// <summary>
		/// Contains the file header of a serialized stream image.
		/// </summary>
		struct SerializationImageHeader final
		{
			/// <summary>
			/// Image identifier.
			/// </summary>
			static constexpr std::string_view MAGIC_ID {"&NOMINAX*IMAGE#"};

			/// <summary>
			/// Magic number string.
			/// </summary>
			std::array<char, std::size(MAGIC_ID)> Magic;

			/// <summary>
			/// The amount of code buffer entries.
			/// </summary>
			std::uint64_t CodeImageSize;

			/// <summary>
			/// The amount of discriminator buffer entries.
			/// </summary>
			std::uint64_t DiscriminatorImageSize;

			/// <summary>
			/// Encrypt descriptor values.
			/// </summary>
			/// <returns></returns>
			constexpr auto EncryptDecrypt()
			{
				constexpr std::uint64_t alpha {ENCRYPTION_KEY_ALPHA}, beta {ENCRYPTION_KEY_BETA}, gamma {ENCRYPTION_KEY_GAMMA};
				this->CodeImageSize ^= alpha ^ gamma ^ beta;
				this->DiscriminatorImageSize ^= beta ^ alpha ^ gamma;
			}
		};

		static_assert(std::is_standard_layout_v<SerializationImageHeader>);

		/// <summary>
		/// Serialize to file stream.
		/// </summary>
		/// <returns>True on success, else false.</returns>
		[[nodiscard]]
		virtual auto Serialize(std::ofstream& out) const -> bool override;

		/// <summary>
		/// Deserialize from file stream.
		/// </summary>
		/// <returns>True on success, else false.</returns>
		[[nodiscard]]
		virtual auto Deserialize(std::ifstream& in) -> bool override;

		/// <summary>
		/// Query image header from this stream.
		/// </summary>
		/// <param name="out"></param>
		/// <returns></returns>
		auto GetSerializationImageHeader(SerializationImageHeader& out) const -> void;

		/// <summary>
		/// Data structure to store the whole byte code.
		/// </summary>
		using CodeStorageType = std::vector<Signal>;

		/// <summary>
		/// Data structure to store the discriminator for each signal.
		/// </summary>
		using DiscriminatorStorageType = std::vector<Signal::Discriminator>;

	private:
		/// <summary>
		/// Required prologue code.
		/// </summary>
		static constexpr std::array PROLOGUE_CODE
		{
			DiscriminatedSignal {Signal::Discriminator::Instruction, Signal {Instruction::NOp}}
		};

		/// <summary>
		/// Required epilogue code.
		/// </summary>
		static constexpr std::array EPILOGUE_CODE
		{
			DiscriminatedSignal {Signal::Discriminator::Instruction, Signal {Instruction::Int}},
			DiscriminatedSignal {Signal::Discriminator::I64, Signal { }}
		};

		/// <summary>
		/// Contains the whole byte code.
		/// </summary>
		CodeStorageType CodeBuffer_ { };

		/// <summary>
		/// Contains all discriminators for the byte code.
		/// Must always be same size as the "Code_" above.
		/// </summary>
		DiscriminatorStorageType CodeDiscriminatorBuffer_ { };

		/// <summary>
		/// Optimization level used for stream.
		/// </summary>
		OptimizationLevel OptimizationLevel_ {DefaultOptimizationLevel()};

	public:
		/// <summary>
		/// Query prologue code.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		static constexpr auto PrologueCode() -> const auto&;

		/// <summary>
		/// Query epilogue code.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		static constexpr auto EpilogueCode() -> const auto&;

		/// <summary>
		/// Returns PrologueCode.size() + EpilogueCode().size()
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		static constexpr auto GuardCodeSize() -> std::uint64_t;

		/// <summary>
		/// Construct empty stream.
		/// </summary>
		/// <returns></returns>
		Stream() = default;

		/// <summary>
		/// Construct with specific optimization level.
		/// </summary>
		/// <param name="optimizationLevel"></param>
		/// <returns></returns>
		explicit Stream(OptimizationLevel optimizationLevel);

		/// <summary>
		/// Move constructor.
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		Stream(Stream&& other) = default;

		/// <summary>
		/// Copy constructor.
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		Stream(const Stream& other) = default;

		/// <summary>
		/// Move assignment operator.
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		auto operator =(Stream&& other) -> Stream& = default;

		/// <summary>
		/// Copy assignment operator.
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		auto operator =(const Stream& other) -> Stream& = default;

		/// <summary>
		/// Destructor.
		/// </summary>
		virtual ~Stream() override = default;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The underlying code buffer.</returns>
		[[nodiscard]]
		auto GetCodeBuffer() & -> CodeStorageType&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The underlying code buffer.</returns>
		[[nodiscard]]
		auto GetCodeBuffer() const & -> const CodeStorageType&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The underlying code buffer.</returns>
		[[nodiscard]]
		auto GetCodeBuffer() && -> CodeStorageType&&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The underlying code buffer.</returns>
		[[nodiscard]]
		auto GetCodeBuffer() const && -> const CodeStorageType&&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The underlying discriminator buffer.</returns>
		[[nodiscard]]
		auto GetDiscriminatorBuffer() & -> DiscriminatorStorageType&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The underlying discriminator buffer.</returns>
		[[nodiscard]]
		auto GetDiscriminatorBuffer() const & -> const DiscriminatorStorageType&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The underlying discriminator buffer.</returns>
		[[nodiscard]]
		auto GetDiscriminatorBuffer() && -> DiscriminatorStorageType&&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The underlying discriminator buffer.</returns>
		[[nodiscard]]
		auto GetDiscriminatorBuffer() const && -> const DiscriminatorStorageType&&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto Front() const -> DiscriminatedSignal;

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto Back() const -> DiscriminatedSignal;

		/// <summary>
		/// Clears the content of the whole stream.
		/// </summary>
		/// <returns></returns>
		auto Clear() -> void;

		/// <summary>
		/// Resize buffer size.
		/// </summary>
		/// <param name="size"></param>
		/// <returns></returns>
		auto Resize(std::uint64_t size) -> void;

		/// <summary>
		/// Reserve buffer size.
		/// </summary>
		/// <param name="size"></param>
		/// <returns></returns>
		auto Reserve(std::uint64_t size) -> void;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The size of the stream.</returns>
		[[nodiscard]]
		auto Size() const -> std::uint64_t;

		/// <summary>
		/// Returns true if the stream contains
		/// no code or only prologue and or epilogue.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto IsEmpty() const -> bool;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The size of the stream in bytes.</returns>
		[[nodiscard]]
		auto SizeInBytes() const -> std::uint64_t;

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
		auto operator <<(SystemIntrinsicInvocationID intrin) -> Stream&;

		/// <summary>
		/// Push stream entry.
		/// </summary>
		/// <param name="intrin"></param>
		/// <returns></returns>
		auto operator <<(UserIntrinsicInvocationID intrin) -> Stream&;

		/// <summary>
		/// Push stream entry.
		/// </summary>
		/// <param name="address"></param>
		/// <returns></returns>
		auto operator <<(JumpAddress address) -> Stream&;

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
		/// Sign extend 32-bit signed integer to std::int64_t and push.
		/// </summary>
		/// <param name="value"></param>
		/// <returns></returns>
		auto operator <<(signed value) -> Stream&;

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
		auto operator <<(CharClusterUtf8 value) -> Stream&;

		/// <summary>
		/// Push stream entry.
		/// </summary>
		/// <param name="value"></param>
		/// <returns></returns>
		auto operator <<(CharClusterUtf16 value) -> Stream&;

		/// <summary>
		/// Push stream entry.
		/// </summary>
		/// <param name="value"></param>
		/// <returns></returns>
		auto operator <<(CharClusterUtf32 value) -> Stream&;

		/// <summary>
		/// Print out immediate byte code.
		/// </summary>
		/// <returns></returns>
		auto DumpByteCode() const -> void;

		/// <summary>
		/// Print the size of the stream with memory info.
		/// </summary>
		/// <returns></returns>
		auto PrintMemoryCompositionInfo() const -> void;

		/// <summary>
		/// Index lookup.
		///Slow! O(i)
		/// </summary>
		/// <param name="idx"></param>
		/// <returns></returns>
		auto operator [](std::uint64_t idx) const -> DiscriminatedSignal;

		/// <summary>
		/// Insert instruction manually with immediate arguments.
		/// </summary>
		/// <param name="args"></param>
		/// <returns></returns>
		template <Instruction I, typename... Ts> requires ValidInstruction<I, Ts...> && ValidInstructionArgument<Ts...>
		auto Do(Ts&&...args) -> Stream&;

		/// <summary>
		/// Insert instruction manually without immediate arguments.
		/// </summary>
		/// <returns></returns>
		template <Instruction I>
		auto Do() -> Stream&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>True if the current stream contains required epilogue code, else false.</returns>
		[[nodiscard]]
		auto ContainsEpilogue() const -> bool;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>True if the current stream contains required prologue code, else false.</returns>
		[[nodiscard]]
		auto ContainsPrologue() const -> bool;

		/// <summary>
		/// Begin stream building.
		/// Inserts code prologue, if missing.
		/// </summary>
		/// <returns></returns>
		auto Prologue() -> Stream&;

		/// <summary>
		/// End stream building.
		/// Inserts code epilogue, if missing.
		/// </summary>
		/// <returns></returns>
		auto Epilogue() -> Stream&;

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
		auto With(V value, F&& functor) -> Stream&;

		/// <summary>
		/// Validate and build code chunk plus jump map into app code bundle.
		/// </summary>
		/// <param name="optInfo"></param>
		/// <param name="stream"></param>
		/// <param name="out"></param>
		/// <returns></returns>
		static auto Build(Stream&& stream, const OptimizationHints& optInfo, Image& out) -> ValidationResultCode;

		/// <summary>
		/// Validate and build code chunk plus jump map into app code bundle.
		/// </summary>
		/// <param name="optInfo"></param>
		/// <param name="stream"></param>
		/// <param name="out"></param>
		/// <returns></returns>
		static auto Build(const Stream& stream, const OptimizationHints& optInfo, Image& out) -> ValidationResultCode;

		/// <summary>
		/// Get current optimization level.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto GetOptimizationLevel() const -> OptimizationLevel;

		/// <summary>
		/// Set current optimization level.
		/// </summary>
		/// <param name="optimizationLevel"></param>
		/// <returns></returns>
		auto SetOptimizationLevel(OptimizationLevel optimizationLevel) -> void;
	};

	constexpr auto Stream::PrologueCode() -> const auto&
	{
		return PROLOGUE_CODE;
	}

	constexpr auto Stream::EpilogueCode() -> const auto&
	{
		return EPILOGUE_CODE;
	}

	constexpr auto Stream::GuardCodeSize() -> std::uint64_t
	{
		return std::size(PrologueCode()) + std::size(EpilogueCode());
	}

	static_assert(Stream::GuardCodeSize() == Stream::PrologueCode().size() + Stream::EpilogueCode().size());

	inline Stream::Stream(const OptimizationLevel optimizationLevel) : OptimizationLevel_ {optimizationLevel} { }

	inline auto Stream::GetOptimizationLevel() const -> OptimizationLevel
	{
		return this->OptimizationLevel_;
	}

	inline auto Stream::SetOptimizationLevel(const OptimizationLevel optimizationLevel) -> void
	{
		this->OptimizationLevel_ = optimizationLevel;
	}

	template <Instruction I, typename... Ts> requires ValidInstruction<I, Ts...> && ValidInstructionArgument<Ts...>
	inline auto Stream::Do(Ts&&...args) -> Stream&
	{
		*this << I;
		return (*this << ... << args);
	}

	template <Instruction I>
	inline auto Stream::Do() -> Stream&
	{
		return *this << I;
	}

	template <typename F, typename V> requires StreamWithExpressionType<F, V>
	inline auto Stream::With(const V value, F&& functor) -> Stream&
	{
		if constexpr (std::is_same_v<std::int32_t, V>)
		{
			functor(ScopedVariable<std::int64_t> {*this, static_cast<std::int64_t>(value)});
		}
		else
		{
			functor(ScopedVariable<V> {*this, value});
		}
		return *this;
	}

	inline auto Stream::Front() const -> DiscriminatedSignal
	{
		return {this->CodeDiscriminatorBuffer_.front(), this->CodeBuffer_.front()};
	}

	inline auto Stream::Back() const -> DiscriminatedSignal
	{
		return {this->CodeDiscriminatorBuffer_.back(), this->CodeBuffer_.back()};
	}

	inline auto Stream::operator[](const std::uint64_t idx) const -> DiscriminatedSignal
	{
		return {this->CodeDiscriminatorBuffer_[idx], this->CodeBuffer_[idx]};
	}

	inline auto Stream::IsEmpty() const -> bool
	{
		return std::empty(this->CodeBuffer_) && std::empty(this->CodeDiscriminatorBuffer_);
	}

	inline auto Stream::GetCodeBuffer() & -> CodeStorageType&
	{
		return this->CodeBuffer_;
	}

	inline auto Stream::GetCodeBuffer() const & -> const CodeStorageType&
	{
		return this->CodeBuffer_;
	}

	inline auto Stream::GetCodeBuffer() && -> CodeStorageType&&
	{
		return std::move(this->CodeBuffer_);
	}

	inline auto Stream::GetCodeBuffer() const && -> const CodeStorageType&&
	{
		return std::move(this->CodeBuffer_);
	}

	inline auto Stream::GetDiscriminatorBuffer() & -> DiscriminatorStorageType&
	{
		return this->CodeDiscriminatorBuffer_;
	}

	inline auto Stream::GetDiscriminatorBuffer() const & -> const DiscriminatorStorageType&
	{
		return this->CodeDiscriminatorBuffer_;
	}

	inline auto Stream::GetDiscriminatorBuffer() && -> DiscriminatorStorageType&&
	{
		return std::move(this->CodeDiscriminatorBuffer_);
	}

	inline auto Stream::GetDiscriminatorBuffer() const && -> const DiscriminatorStorageType&&
	{
		return std::move(this->CodeDiscriminatorBuffer_);
	}

	inline auto Stream::Clear() -> void
	{
		this->CodeBuffer_.clear();
		this->CodeDiscriminatorBuffer_.clear();
	}

	inline auto Stream::Resize(const std::uint64_t size) -> void
	{
		NOX_DBG_PAS_TRUE(std::size(this->CodeBuffer_) == std::size(this->CodeDiscriminatorBuffer_), "Stream size mismatch");
		this->CodeBuffer_.resize(size);
		this->CodeDiscriminatorBuffer_.resize(size);
	}

	inline auto Stream::Reserve(const std::uint64_t size) -> void
	{
		NOX_DBG_PAS_TRUE(std::size(this->CodeBuffer_) == std::size(this->CodeDiscriminatorBuffer_), "Stream size mismatch");
		this->CodeBuffer_.reserve(size);
		this->CodeDiscriminatorBuffer_.reserve(size);
	}

	inline auto Stream::Size() const -> std::uint64_t
	{
		NOX_DBG_PAS_TRUE(std::size(this->CodeBuffer_) == std::size(this->CodeDiscriminatorBuffer_), "Stream size mismatch");
		return std::size(this->CodeBuffer_);
	}

	inline auto Stream::SizeInBytes() const -> std::uint64_t
	{
		NOX_DBG_PAS_TRUE(std::size(this->CodeBuffer_) == std::size(this->CodeDiscriminatorBuffer_), "Stream size mismatch");
		return
			std::size(this->CodeBuffer_)
			* sizeof(Signal)
			+ std::size(this->CodeDiscriminatorBuffer_)
			* sizeof(Signal::Discriminator);
	}

	inline auto Stream::operator <<(const Instruction instr) -> Stream&
	{
		NOX_DBG_PAS_TRUE(std::size(this->CodeBuffer_) == std::size(this->CodeDiscriminatorBuffer_), "Stream size mismatch");
		this->CodeBuffer_.emplace_back(Signal {instr});
		this->CodeDiscriminatorBuffer_.emplace_back(Signal::Discriminator::Instruction);
		return *this;
	}

	inline auto Stream::operator <<(const SystemIntrinsicInvocationID intrin) -> Stream&
	{
		NOX_DBG_PAS_TRUE(std::size(this->CodeBuffer_) == std::size(this->CodeDiscriminatorBuffer_), "Stream size mismatch");
		this->CodeBuffer_.emplace_back(Signal {intrin});
		this->CodeDiscriminatorBuffer_.emplace_back(Signal::Discriminator::SystemIntrinsicInvocationID);
		return *this;
	}

	inline auto Stream::operator <<(const UserIntrinsicInvocationID intrin) -> Stream&
	{
		NOX_DBG_PAS_TRUE(std::size(this->CodeBuffer_) == std::size(this->CodeDiscriminatorBuffer_), "Stream size mismatch");
		this->CodeBuffer_.emplace_back(Signal {intrin});
		this->CodeDiscriminatorBuffer_.emplace_back(Signal::Discriminator::UserIntrinsicInvocationID);
		return *this;
	}

	inline auto Stream::operator<<(const JumpAddress address) -> Stream&
	{
		NOX_DBG_PAS_TRUE(std::size(this->CodeBuffer_) == std::size(this->CodeDiscriminatorBuffer_), "Stream size mismatch");
		this->CodeBuffer_.emplace_back(Signal {address});
		this->CodeDiscriminatorBuffer_.emplace_back(Signal::Discriminator::JumpAddress);
		return *this;
	}

	inline auto Stream::operator <<(const std::uint64_t value) -> Stream&
	{
		NOX_DBG_PAS_TRUE(std::size(this->CodeBuffer_) == std::size(this->CodeDiscriminatorBuffer_), "Stream size mismatch");
		this->CodeBuffer_.emplace_back(Signal {value});
		this->CodeDiscriminatorBuffer_.emplace_back(Signal::Discriminator::U64);
		return *this;
	}

	inline auto Stream::operator <<(const std::int64_t value) -> Stream&
	{
		NOX_DBG_PAS_TRUE(std::size(this->CodeBuffer_) == std::size(this->CodeDiscriminatorBuffer_), "Stream size mismatch");
		this->CodeBuffer_.emplace_back(Signal {value});
		this->CodeDiscriminatorBuffer_.emplace_back(Signal::Discriminator::I64);
		return *this;
	}

	inline auto Stream::operator <<(const double value) -> Stream&
	{
		NOX_DBG_PAS_TRUE(std::size(this->CodeBuffer_) == std::size(this->CodeDiscriminatorBuffer_), "Stream size mismatch");
		this->CodeBuffer_.emplace_back(Signal {value});
		this->CodeDiscriminatorBuffer_.emplace_back(Signal::Discriminator::F64);
		return *this;
	}

	inline auto Stream::operator<<(const signed value) -> Stream&
	{
		return *this << static_cast<std::int64_t>(value);
	}

	inline auto Stream::operator <<(const CharClusterUtf8 value) -> Stream&
	{
		NOX_DBG_PAS_TRUE(std::size(this->CodeBuffer_) == std::size(this->CodeDiscriminatorBuffer_), "Stream size mismatch");
		this->CodeBuffer_.emplace_back(Signal {value});
		this->CodeDiscriminatorBuffer_.emplace_back(Signal::Discriminator::CharClusterUtf8);
		return *this;
	}

	inline auto Stream::operator<<(const CharClusterUtf16 value) -> Stream&
	{
		NOX_DBG_PAS_TRUE(std::size(this->CodeBuffer_) == std::size(this->CodeDiscriminatorBuffer_), "Stream size mismatch");
		this->CodeBuffer_.emplace_back(Signal {value});
		this->CodeDiscriminatorBuffer_.emplace_back(Signal::Discriminator::CharClusterUtf16);
		return *this;
	}

	inline auto Stream::operator<<(const CharClusterUtf32 value) -> Stream&
	{
		NOX_DBG_PAS_TRUE(std::size(this->CodeBuffer_) == std::size(this->CodeDiscriminatorBuffer_), "Stream size mismatch");
		this->CodeBuffer_.emplace_back(Signal {value});
		this->CodeDiscriminatorBuffer_.emplace_back(Signal::Discriminator::CharClusterUtf32);
		return *this;
	}
}
