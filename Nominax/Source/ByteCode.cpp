// File: ByteCode.cpp
// Author: Mario
// Created: 06.07.2021 4:08 PM
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

#include <execution>

#include "../../Nominax/Include/Nominax/ByteCode/_ByteCode.hpp"
#include "../../Nominax/Include/Nominax/Foundation/_Foundation.hpp"
#include "../../Nominax/Include/Nominax/Utils.hpp"
#include "../../Nominax/Include/Nominax/Core.hpp"

namespace Nominax::ByteCode
{
	auto TransformStreamToImageByCopy
	(
		const Stream&            input,
		const OptimizationHints& optHints,
		Image&                   output
	) -> void
	{
		Stream copy {input};
		return TransformStreamToImageByMove(std::move(copy), optHints, output);
	}

	auto TransformStreamToImageByMove
	(
		Stream&&                                  input,
		[[maybe_unused]] const OptimizationHints& optHints,
		Image&                                    output
	) -> void
	{
		if (input.IsEmpty())
		{
			[[unlikely]]
				return;
		}

		output = Image {std::move(input.GetCodeBuffer())};

		#if NOX_OPT_EXECUTION_ADDRESS_MAPPING
		const auto* const NOX_RESTRICT                     discriminators {&*std::begin(input.GetDiscriminatorBuffer())};
		const auto* const NOX_RESTRICT* const NOX_RESTRICT jumpTable {&optHints.JumpTable};
		const auto* const NOX_RESTRICT                     base {output.GetBlobData()};
		const auto* const NOX_RESTRICT                     begin {&*std::begin(output)};

		const auto addressMapper
		{
			[=](Signal& x)
			{
				const Signal::Discriminator discriminator {discriminators[&x - begin]};
				if (discriminator == Signal::Discriminator::Instruction)
				{
					x.Ptr = const_cast<void*>(*(jumpTable + x.OpCode));
				}
				else if (discriminator == Signal::Discriminator::JumpAddress)
				{
					x.Ptr = const_cast<void*>(ComputeRelativeJumpAddress(base, x.JmpAddress));
				}
			}
		};
		std::for_each(std::execution::par_unseq, std::begin(output), std::end(output), addressMapper);
		#endif
	}

	Image::Image(std::vector<Signal>&& buffer) : Blob_ {std::move(buffer)} { }

	Image::Image(const std::span<const Signal> blob)
	{
		NOX_PAS_FALSE(std::empty(blob), "Byte code image with zero size is invalid!");
		this->Blob_.resize(std::size(blob));
		std::copy(std::execution::par_unseq, std::cbegin(blob), std::cend(blob), std::begin(this->Blob_));
	}

	Image::Image(const void* const data, const U64 byteSize)
	{
		NOX_PAS_NOT_ZERO(byteSize, "Byte code image with zero size is invalid!");
		NOX_PAS_NOT_NULL(data, "Byte code image with null data is invalid!");
		NOX_PAS_TRUE(byteSize % sizeof(Signal) == 0, "Byte code image size must be a multiple of eight!");
		this->Blob_.resize(byteSize / sizeof(Signal));
		std::memcpy(std::data(this->Blob_), data, byteSize);
	}

	auto Stream::GetSerializationImageHeader(SerializationImageHeader& out) const -> void
	{
		NOX_DBG_PAS_TRUE(std::size(this->CodeBuffer_) == std::size(this->CodeDiscriminatorBuffer_), "Stream size mismatch");
		std::memcpy(std::data(out.Magic), std::data(SerializationImageHeader::MAGIC_ID), sizeof out.Magic);
		out.CodeImageSize          = std::size(this->CodeBuffer_);
		out.DiscriminatorImageSize = std::size(this->CodeDiscriminatorBuffer_);
		out.EncryptDecrypt();
	}

	auto Stream::Serialize(std::ofstream& out) const -> bool
	{
		SerializationImageHeader header { };
		constexpr U64            codeSectionMarker {STREAM_IMAGE_CODE_SECTION_MARKER};
		constexpr U64            discriminatorSectionMarker {STREAM_IMAGE_DISCRIMINATOR_SECTION_MARKER};

		// header
		this->GetSerializationImageHeader(header);
		out.write(reinterpret_cast<const char*>(&header), sizeof(SerializationImageHeader));

		// code section
		out.write(reinterpret_cast<const char*>(&codeSectionMarker), sizeof(U64));
		out.write(reinterpret_cast<const char*>(std::data(this->CodeBuffer_)), std::size(this->CodeBuffer_) * sizeof(CodeStorageType::value_type));

		// discriminator section
		out.write(reinterpret_cast<const char*>(&discriminatorSectionMarker), sizeof(U64));
		out.write(reinterpret_cast<const char*>(std::data(this->CodeDiscriminatorBuffer_)), std::size(this->CodeDiscriminatorBuffer_) * sizeof(DiscriminatorStorageType::value_type));
		return true;
	}

	auto Stream::Deserialize(std::ifstream& in) -> bool
	{
		SerializationImageHeader header { };
		in.read(reinterpret_cast<char*>(&header), sizeof(SerializationImageHeader));
		for (U64 i {0}; i < std::size(SerializationImageHeader::MAGIC_ID); ++i)
		{
			if (header.Magic[i] != SerializationImageHeader::MAGIC_ID[i])
			{
				[[unlikely]]
					return false;
			}
		}

		header.EncryptDecrypt();
		if (!header.CodeImageSize || !header.DiscriminatorImageSize)
		{
			[[unlikely]]
				return false;
		}

		// validate code section marker
		U64 codeSectionMarker { };
		in.read(reinterpret_cast<char*>(&codeSectionMarker), sizeof(U64));
		if (codeSectionMarker != STREAM_IMAGE_CODE_SECTION_MARKER)
		{
			[[unlikely]]
				return false;
		}

		// load code section:
		this->CodeBuffer_.clear();
		this->CodeBuffer_.resize(header.CodeImageSize);
		in.read(reinterpret_cast<char*>(std::data(this->CodeBuffer_)), header.CodeImageSize * sizeof(CodeStorageType::value_type));

		// validate discriminator section marker
		U64 discriminatorSectionMarker { };
		in.read(reinterpret_cast<char*>(&discriminatorSectionMarker), sizeof(U64));
		if (discriminatorSectionMarker != STREAM_IMAGE_DISCRIMINATOR_SECTION_MARKER)
		{
			[[unlikely]]
				return false;
		}

		// load discriminator section:
		this->CodeDiscriminatorBuffer_.clear();
		this->CodeDiscriminatorBuffer_.resize(header.CodeImageSize);
		in.read(reinterpret_cast<char*>(std::data(this->CodeDiscriminatorBuffer_)), header.DiscriminatorImageSize * sizeof(CodeStorageType::value_type));

		return true;
	}

	using Foundation::ILog2;
	using Foundation::Proxy_F64IsZero;
	using Foundation::Proxy_F64IsOne;
	using Foundation::IsPowerOfTwo;

	template <>
	// ReSharper disable once CppMemberFunctionMayBeConst
	auto ScopedVariable<F64>::Push(const F64 value) -> ScopedVariable<F64>&
	{
		if (this->Attached_.GetOptimizationLevel() >= OptimizationLevel::O1)
		{
			// If zero, optimize with special push zero instruction.
			if (Proxy_F64IsZero(value))
			{
				this->Attached_.Do<Instruction::PushZ>();
				return *this;
			}

			// If one, optimize with special push F32 one instruction.
			if (Proxy_F64IsOne(value))
			{
				this->Attached_.Do<Instruction::FPushO>();
				return *this;
			}

			// If the value is the previous written element in the stream,
			// we can just duplicate it:
			if (!this->Attached_.IsEmpty() && this->Attached_.Back().Contains(value))
			{
				this->Attached_.Do<Instruction::Dupl>();
				return *this;
			}
		}

		// Else just do a push:
		this->Attached_.Do<Instruction::Push>(value);
		return *this;
	}

	template <>
	auto ScopedVariable<I64>::Push(const I64 value) -> ScopedVariable<I64>&
	{
		if (this->Attached_.GetOptimizationLevel() >= OptimizationLevel::O1)
		{
			// If zero, optimize with special push zero instruction.
			if (value == 0)
			{
				this->Attached_.Do<Instruction::PushZ>();
				return *this;
			}

			// If one, optimize with special push integer one instruction.
			if (value == 1)
			{
				this->Attached_.Do<Instruction::IPushO>();
				return *this;
			}

			// If the value is the previous written element in the stream,
			// we can just duplicate it:
			if (!this->Attached_.IsEmpty() && this->Attached_.Back().Contains(value))
			{
				this->Attached_.Do<Instruction::Dupl>();
				return *this;
			}
		}

		// Else just do a push:
		this->Attached_.Do<Instruction::Push>(value);
		return *this;
	}

	template <>
	auto ScopedVariable<U64>::Push(const U64 value) -> ScopedVariable<U64>&
	{
		if (this->Attached_.GetOptimizationLevel() >= OptimizationLevel::O1)
		{
			// If zero, optimize with special push zero instruction.
			if (value == 0)
			{
				this->Attached_.Do<Instruction::PushZ>();
				return *this;
			}

			// If one, optimize with special push integer one instruction.
			if (value == 1)
			{
				this->Attached_.Do<Instruction::IPushO>();
				return *this;
			}

			// If the value is the previous written element in the stream,
			// we can just duplicate it:
			if (!this->Attached_.IsEmpty() && this->Attached_.Back().Contains(value))
			{
				this->Attached_.Do<Instruction::Dupl>();
				return *this;
			}
		}
		// Else just do a push:
		this->Attached_.Do<Instruction::Push>(value);
		return *this;
	}

	template <>
	auto ScopedVariable<F64>::Add(const F64 value) -> ScopedVariable<F64>&
	{
		if (this->Attached_.GetOptimizationLevel() >= OptimizationLevel::O1)
		{
			// With 0 it's a no-op
			if (Proxy_F64IsZero(value))
			{
				return this->DoNothing();
			}

			// Optimize to increment:
			if (Proxy_F64IsOne(value))
			{
				this->Attached_.Do<Instruction::FInc>();
				return *this;
			}
		}
		this->Push(value);
		this->Attached_.Do<Instruction::FAdd>();
		return *this;
	}

	template <>
	auto ScopedVariable<I64>::Add(const I64 value) -> ScopedVariable<I64>&
	{
		if (this->Attached_.GetOptimizationLevel() >= OptimizationLevel::O1)
		{
			// With 0 it's a no-op
			if (value == 0)
			{
				return this->DoNothing();
			}

			// Optimize to increment:
			if (value == 1)
			{
				this->Attached_.Do<Instruction::IInc>();
				return *this;
			}
		}
		this->Push(value);
		this->Attached_.Do<Instruction::IAdd>();
		return *this;
	}

	template <>
	auto ScopedVariable<U64>::Add(const U64 value) -> ScopedVariable<U64>&
	{
		if (this->Attached_.GetOptimizationLevel() >= OptimizationLevel::O1)
		{
			// With 0 it's a no-op
			if (value == 0)
			{
				return this->DoNothing();
			}

			// Optimize to increment:
			if (value == 1)
			{
				this->Attached_.Do<Instruction::IInc>();
				return *this;
			}
		}
		this->Push(value);
		this->Attached_.Do<Instruction::IAdd>();
		return *this;
	}


	template <>
	auto ScopedVariable<F64>::Sub(const F64 value) -> ScopedVariable<F64>&
	{
		if (this->Attached_.GetOptimizationLevel() >= OptimizationLevel::O1)
		{
			// With 0 it's a no-op
			if (Proxy_F64IsZero(value))
			{
				return this->DoNothing();
			}

			// Optimize to decrement:
			if (Proxy_F64IsOne(value))
			{
				this->Attached_.Do<Instruction::FDec>();
				return *this;
			}
		}
		this->Push(value);
		this->Attached_.Do<Instruction::FSub>();
		return *this;
	}

	template <>
	auto ScopedVariable<I64>::Sub(const I64 value) -> ScopedVariable<I64>&
	{
		if (this->Attached_.GetOptimizationLevel() >= OptimizationLevel::O1)
		{
			// With 0 it's a no-op
			if (value == 0)
			{
				return this->DoNothing();
			}

			// Optimize to decrement:
			if (value == 1)
			{
				this->Attached_.Do<Instruction::IDec>();
				return *this;
			}
		}
		this->Push(value);
		this->Attached_.Do<Instruction::ISub>();
		return *this;
	}

	template <>
	auto ScopedVariable<U64>::Sub(const U64 value) -> ScopedVariable<U64>&
	{
		if (this->Attached_.GetOptimizationLevel() >= OptimizationLevel::O1)
		{
			// With 0 it's a no-op
			if (value == 0)
			{
				return this->DoNothing();
			}

			// Optimize to decrement:
			if (value == 1)
			{
				this->Attached_.Do<Instruction::IDec>();
				return *this;
			}
		}
		this->Push(value);
		this->Attached_.Do<Instruction::ISub>();
		return *this;
	}

	template <>
	auto ScopedVariable<F64>::Mul(const F64 value) -> ScopedVariable<F64>&
	{
		if (this->Attached_.GetOptimizationLevel() >= OptimizationLevel::O1)
		{
			// By 0 or 1 is a no-op:
			if (Proxy_F64IsZero(value) || Proxy_F64IsOne(value))
			{
				return this->DoNothing();
			}
		}
		this->Push(value);
		this->Attached_.Do<Instruction::FMul>();
		return *this;
	}

	template <>
	auto ScopedVariable<I64>::Mul(I64 value) -> ScopedVariable<I64>&
	{
		if (this->Attached_.GetOptimizationLevel() >= OptimizationLevel::O1)
		{
			// By 0 or 1 is a no-op:
			if (value == 0 || value == 1)
			{
				return this->DoNothing();
			}

			// Optimize with shift:
			if (IsPowerOfTwo(value))
			{
				value = ILog2(value);
				this->Push(value);
				this->Attached_.Do<Instruction::ISal>();
				return *this;
			}
		}
		this->Push(value);
		this->Attached_.Do<Instruction::IMul>();
		return *this;
	}

	template <>
	auto ScopedVariable<U64>::Mul(U64 value) -> ScopedVariable<U64>&
	{
		if (this->Attached_.GetOptimizationLevel() >= OptimizationLevel::O1)
		{
			// By 0 or 1 is a no-op:
			if (value == 0 || value == 1)
			{
				return this->DoNothing();
			}

			// Optimize with shift:
			if (IsPowerOfTwo(value))
			{
				value = ILog2(value);
				this->Push(value);
				this->Attached_.Do<Instruction::ISal>();
				return *this;
			}
		}
		this->Push(value);
		this->Attached_.Do<Instruction::IMul>();
		return *this;
	}

	template <>
	auto ScopedVariable<F64>::Div(const F64 value) -> ScopedVariable<F64>&
	{
		if (this->Attached_.GetOptimizationLevel() >= OptimizationLevel::O1)
		{
			// x / x is always 1
			if (this->Attached_.Back().Contains(value))
			{
				this->Attached_.Do<Instruction::Pop>();
				this->Push(1.0);
				return *this;
			}

			// By 1 it's just the same value.
			if (Proxy_F64IsOne(value))
			{
				return this->DoNothing();
			}
		}
		this->Push(value);
		this->Attached_.Do<Instruction::FDiv>();
		return *this;
	}

	template <>
	auto ScopedVariable<I64>::Div(I64 value) -> ScopedVariable<I64>&
	{
		if (this->Attached_.GetOptimizationLevel() >= OptimizationLevel::O1)
		{
			// x / x is always 1
			if (this->Attached_.Back().Contains(value))
			{
				this->Attached_.Do<Instruction::Pop>();
				this->Push(static_cast<decltype(value)>(1));
				return *this;
			}

			// By 1 it's just the same value.
			if (value == 1)
			{
				return this->DoNothing();
			}

			// Optimize with shift:
			if (IsPowerOfTwo(value))
			{
				value = ILog2(value);
				this->Push(value);
				this->Attached_.Do<Instruction::ISar>();
				return *this;
			}
		}

		this->Push(value);
		this->Attached_.Do<Instruction::IDiv>();
		return *this;
	}

	template <>
	auto ScopedVariable<U64>::Div(U64 value) -> ScopedVariable<U64>&
	{
		if (this->Attached_.GetOptimizationLevel() >= OptimizationLevel::O1)
		{
			// x / x is always 1
			if (this->Attached_.Back().Contains(value))
			{
				this->Attached_.Do<Instruction::Pop>();
				this->Push(static_cast<decltype(value)>(1));
				return *this;
			}

			// By 1 it's just the same value.
			if (value == 1)
			{
				return this->DoNothing();
			}

			// Optimize with shift:
			if (IsPowerOfTwo(value))
			{
				value = ILog2(value);
				this->Push(value);
				this->Attached_.Do<Instruction::ISar>();
				return *this;
			}
		}
		this->Push(value);
		this->Attached_.Do<Instruction::IDiv>();
		return *this;
	}

	template <>
	auto ScopedVariable<F64>::Mod(const F64 value) -> ScopedVariable<F64>&
	{
		this->Push(value);
		this->Attached_.Do<Instruction::FMod>();
		return *this;
	}

	template <>
	auto ScopedVariable<I64>::Mod(const I64 value) -> ScopedVariable<I64>&
	{
		this->Push(value);
		this->Attached_.Do<Instruction::IMod>();
		return *this;
	}

	template <>
	auto ScopedVariable<U64>::Mod(const U64 value) -> ScopedVariable<U64>&
	{
		this->Push(value);
		this->Attached_.Do<Instruction::IMod>();
		return *this;
	}

	template <>
	auto ScopedVariable<I64>::And(const I64 value) -> ScopedVariable<I64>&
	{
		this->Push(value);
		this->Attached_.Do<Instruction::IAnd>();
		return *this;
	}

	template <>
	auto ScopedVariable<U64>::And(const U64 value) -> ScopedVariable<U64>&
	{
		this->Push(value);
		this->Attached_.Do<Instruction::IAnd>();
		return *this;
	}

	template <>
	auto ScopedVariable<I64>::Or(const I64 value) -> ScopedVariable<I64>&
	{
		this->Push(value);
		this->Attached_.Do<Instruction::IOr>();
		return *this;
	}


	template <>
	auto ScopedVariable<U64>::Or(const U64 value) -> ScopedVariable<U64>&
	{
		this->Push(value);
		this->Attached_.Do<Instruction::IOr>();
		return *this;
	}

	template <>
	auto ScopedVariable<I64>::Xor(const I64 value) -> ScopedVariable<I64>&
	{
		this->Push(value);
		this->Attached_.Do<Instruction::IXor>();
		return *this;
	}

	template <>
	auto ScopedVariable<U64>::Xor(const U64 value) -> ScopedVariable<U64>&
	{
		this->Push(value);
		this->Attached_.Do<Instruction::IXor>();
		return *this;
	}

	template <>
	auto ScopedVariable<I64>::ShiftLeft(const I64 value) -> ScopedVariable<I64>&
	{
		if (value == 0)
		{
			return this->DoNothing();
		}
		this->Push(value);
		this->Attached_.Do<Instruction::ISal>();
		return *this;
	}

	template <>
	auto ScopedVariable<U64>::ShiftLeft(const U64 value) -> ScopedVariable<U64>&
	{
		if (value == 0)
		{
			return this->DoNothing();
		}
		this->Push(value);
		this->Attached_.Do<Instruction::ISal>();
		return *this;
	}

	template <>
	auto ScopedVariable<I64>::ShiftRight(const I64 value) -> ScopedVariable<I64>&
	{
		if (value == 0)
		{
			return this->DoNothing();
		}
		this->Push(value);
		this->Attached_.Do<Instruction::ISar>();
		return *this;
	}

	template <>
	auto ScopedVariable<U64>::ShiftRight(const U64 value) -> ScopedVariable<U64>&
	{
		if (value == 0)
		{
			return this->DoNothing();
		}
		this->Push(value);
		this->Attached_.Do<Instruction::ISar>();
		return *this;
	}

	template <>
	auto ScopedVariable<I64>::RotateLeft(const I64 value) -> ScopedVariable<I64>&
	{
		if (value == 0)
		{
			return this->DoNothing();
		}
		this->Push(value);
		this->Attached_.Do<Instruction::IRol>();
		return *this;
	}

	template <>
	auto ScopedVariable<U64>::RotateLeft(const U64 value) -> ScopedVariable<U64>&
	{
		if (value == 0)
		{
			return this->DoNothing();
		}
		this->Push(value);
		this->Attached_.Do<Instruction::IRol>();
		return *this;
	}

	template <>
	auto ScopedVariable<I64>::RotateRight(const I64 value) -> ScopedVariable<I64>&
	{
		if (value == 0)
		{
			return this->DoNothing();
		}
		this->Push(value);
		this->Attached_.Do<Instruction::IRor>();
		return *this;
	}

	template <>
	auto ScopedVariable<U64>::RotateRight(const U64 value) -> ScopedVariable<U64>&
	{
		if (value == 0)
		{
			return this->DoNothing();
		}
		this->Push(value);
		this->Attached_.Do<Instruction::IRor>();
		return *this;
	}

	using namespace Foundation;

	auto Stream::DumpByteCode() const -> void
	{
		Print("Signal: {}, Size: {:.3} kB, Granularity: {} B\n", this->Size(), Bytes2Kilobytes(static_cast<F32>(this->SizeInBytes())), sizeof(Signal));

		for (U64 i {0}; i < this->Size(); ++i)
		{
			const auto bytes {std::bit_cast<std::array<U8, sizeof(Signal)>>(this->CodeBuffer_[i])};
			const auto isInstr {this->CodeDiscriminatorBuffer_[i] == Signal::Discriminator::Instruction};
			Print(TextColor::Green, "&{:016X} ", reinterpret_cast<Uip64>(&this->CodeBuffer_[i]));
			Print
			(
				"| {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} {:02X} | ",
				bytes[0],
				bytes[1],
				bytes[2],
				bytes[3],
				bytes[4],
				bytes[5],
				bytes[6],
				bytes[7]
			);
			Print(isInstr ? TextColor::Blue : TextColor::Magenta, "{}\n", (*this)[i]);
		}

		Print("\n\n");
	}

	auto Stream::PrintMemoryCompositionInfo() const -> void
	{
		Print("Stream size: {}\n", this->Size());
		Print("Code buffer: {:.03F} MB\n",
		      Bytes2Megabytes<F32>(
			      static_cast<F32>(this->CodeBuffer_.size()) * static_cast<F32>(sizeof(CodeStorageType::value_type))));
		Print("Discriminator buffer: {:.03F} MB\n", Bytes2Megabytes<F32>(
			      static_cast<F32>(this->CodeDiscriminatorBuffer_.size()) * static_cast<F32>(sizeof(
				      DiscriminatorStorageType::value_type))));
		Print("Total: {:.03F} MB\n", Bytes2Megabytes<F32>(static_cast<F32>(this->SizeInBytes())));
	}

	auto Stream::Prologue() -> Stream&
	{
		for (const auto& [discriminator, signal] : PrologueCode())
		{
			this->CodeDiscriminatorBuffer_.emplace_back(discriminator);
			this->CodeBuffer_.emplace_back(signal);
		}
		return *this;
	}

	auto Stream::Epilogue() -> Stream&
	{
		for (const auto& [discriminator, signal] : EpilogueCode())
		{
			this->CodeDiscriminatorBuffer_.emplace_back(discriminator);
			this->CodeBuffer_.emplace_back(signal);
		}
		return *this;
	}

	auto Stream::Build(Stream&& stream, const OptimizationHints& optInfo, Image& out) -> ValidationResultCode
	{
		const ValidationResultCode validationResult {ValidateFullPass(stream)};
		if (validationResult != ValidationResultCode::Ok)
		{
			[[unlikely]]
				return validationResult;
		}
		TransformStreamToImageByMove(std::move(stream), optInfo, out);
		return ValidationResultCode::Ok;
	}

	auto Stream::Build(const Stream& stream, const OptimizationHints& optInfo, Image& out) -> ValidationResultCode
	{
		const ValidationResultCode validationResult {ValidateFullPass(stream)};
		if (validationResult != ValidationResultCode::Ok)
		{
			[[unlikely]]
				return validationResult;
		}
		TransformStreamToImageByCopy(stream, optInfo, out);
		return ValidationResultCode::Ok;
	}

	auto Stream::ContainsPrologue() const -> bool
	{
		return ByteCode::ContainsPrologue(*this);
	}

	auto Stream::ContainsEpilogue() const -> bool
	{
		return ByteCode::ContainsEpilogue(*this);
	}

	auto ContainsPrologue(const Stream& input) -> bool
	{
		constexpr const auto& code {Stream::PrologueCode()};
		if (input.Size() < code.size())
		{
			[[unlikely]]
				return false;
		}
		for (U64 i {0}; i < code.size(); ++i)
		{
			if (code[i] != input[i])
			{
				[[unlikely]]
					return false;
			}
		}
		return true;
	}

	auto ContainsEpilogue(const Stream& input) -> bool
	{
		constexpr const auto& code {Stream::EpilogueCode()};
		if (input.Size() < code.size())
		{
			[[unlikely]]
				return false;
		}
		for (U64 i {0}, j {input.Size() - code.size()}; i < code.size(); ++i)
		{
			if (code[i] != input[j + i])
			{
				[[unlikely]]
					return false;
			}
		}
		return true;
	}

	auto ValidateFullPass
	(
		const Stream& input, UserIntrinsicRoutineRegistry intrinsicRegistry,
		U32* const    outIndex
	) -> ValidationResultCode
	{
		// Check if empty:
		if (input.IsEmpty())
		{
			[[unlikely]]
				return ValidationResultCode::Empty;
		}

		// Check if prologue code is contained:
		if (!ContainsPrologue(input))
		{
			[[unlikely]]
				return ValidationResultCode::MissingPrologueCode;
		}

		// Check if epilogue code is contained:
		if (!ContainsEpilogue(input))
		{
			[[unlikely]]
				return ValidationResultCode::MissingEpilogueCode;
		}

		// Validate that user intrinsic calls are non null:
		for (IntrinsicRoutine* const routine : intrinsicRegistry)
		{
			if (!routine)
			{
				[[unlikely]]
					return ValidationResultCode::InvalidUserIntrinsicCall;
			}
		}

		// Error state:
		AtomicState<ValidationResultCode> error { };
		std::atomic<U32>                  errorIndex {0};

		const auto& codeBuf {input.GetCodeBuffer()};
		const auto& discBuf {input.GetDiscriminatorBuffer()};
		const auto  bufBegin {&*std::begin(discBuf)};
		const auto  bufEnd {&*std::end(discBuf)};

		auto validationRoutine
		{
			[&](const Signal::Discriminator& iterator)
			{
				const std::ptrdiff_t index {DistanceRef(iterator, bufBegin)};
				const Signal         signal {codeBuf[index]};
				auto                 result {ValidationResultCode::Ok};

				switch (iterator)
				{
						// validate instruction:
					case Signal::Discriminator::Instruction:
					{
						const auto* const next {SearchForNextInstruction(&iterator, bufEnd)};
						const auto        args {
							ExtractInstructionArguments(&iterator, ComputeInstructionArgumentOffset(&iterator, next))
						};
						result = ValidateInstructionArguments(signal.Instr, args); // validate args
					}
					break;

					case Signal::Discriminator::JumpAddress:
					{
						result = ValidateJumpAddress(input, signal.JmpAddress)
							         ? ValidationResultCode::Ok
							         : ValidationResultCode::InvalidJumpAddress;
					}
					break;

					case Signal::Discriminator::UserIntrinsicInvocationID:
					{
						result = ValidateUserIntrinsicCall(intrinsicRegistry, signal.UserIntrinID)
							         ? ValidationResultCode::Ok
							         : ValidationResultCode::InvalidUserIntrinsicCall;
					}
					break;

					default: ;
				}

				if (result != ValidationResultCode::Ok)
				[[unlikely]]
				{
					errorIndex.store(static_cast<U32>(index));
					error(result);
				}
			}
		};

		// Validate in parallel:
		std::for_each(std::execution::par_unseq, std::begin(discBuf), std::end(discBuf), validationRoutine);

		// Return error if the error value is not okay
		if (!error)
		[[unlikely]]
		{
			if (outIndex)
			{
				[[unlikely]]
					*outIndex = errorIndex.load();
			}
			return error();
		}

		if (outIndex)
		{
			[[unlikely]]
				*outIndex = 0;
		}

		return ValidationResultCode::Ok;
	}

	auto ValidateJumpAddress(const Stream& bucket, const JumpAddress address) -> bool
	{
		const auto idx {static_cast<U64>(address)};

		// validate that jump address is inside the range of the bucket:
		if (bucket.Size() <= idx)
		{
			[[unlikely]]
				return false;
		}

		return NOX_EXPECT_VALUE(bucket[idx].Contains<Instruction>(), true);
	}

	auto ValidateSystemIntrinsicCall(const SystemIntrinsicInvocationID id) -> bool
	{
		constexpr auto max {ToUnderlying(SystemIntrinsicInvocationID::Count_) - 1};
		const auto     value {ToUnderlying(id)};
		static_assert(std::is_unsigned_v<decltype(value)>);
		return NOX_EXPECT_VALUE(value <= max, true);
	}

	auto ValidateUserIntrinsicCall(const UserIntrinsicRoutineRegistry& routines, UserIntrinsicInvocationID id) -> bool
	{
		static_assert(std::is_unsigned_v<std::underlying_type_t<decltype(id)>>);
		return NOX_EXPECT_VALUE(ToUnderlying(id) < routines.size(), true);
	}

	auto ValidateInstructionArguments
	(
		const Instruction                             instruction,
		const std::span<const Signal::Discriminator>& args
	) -> ValidationResultCode
	{
		// First check if the argument count is incorrect:
		if (LookupInstructionArgumentCount(instruction) > args.size())
		{
			[[unlikely]]
				return ValidationResultCode::NotEnoughArgumentsForInstruction;
		}

		// First check if the argument count is incorrect:
		if (LookupInstructionArgumentCount(instruction) < args.size())
		{
			[[unlikely]]
				return ValidationResultCode::TooManyArgumentsForInstruction;
		}

		for (U64 i {0}; i < args.size(); ++i)
		{
			const Signal::Discriminator discriminator {args[i]};

			// Check if our given type index is within the required indices:

			const TypeIndexTable& required {LookupInstructionArgumentTypes(instruction)[i]};
			const bool            isWithinAllowedIndices {
				std::find(std::begin(required), std::end(required), discriminator) != std::end(required)
			};

			if (!isWithinAllowedIndices)
			{
				// if not, validation failed:
				[[unlikely]]
					return ValidationResultCode::ArgumentTypeMismatch;
			}
		}

		return ValidationResultCode::Ok;
	}

	auto LocalCodeGenerationLayer::EmitPush(const I64 value) -> LocalCodeGenerationLayer&
	{
		if (this->EnablePeepholeOptimizations && value == 0)
		{
			this->Emitter << Instruction::PushZ;
		}
		else if (this->EnablePeepholeOptimizations && value == 1)
		{
			this->Emitter << Instruction::IPushO;
		}
		else
		{
			this->Emitter << Instruction::Push << value;
		}
		return *this;
	}

	auto LocalCodeGenerationLayer::EmitPush(const F64 value) -> LocalCodeGenerationLayer&
	{
		if (this->EnablePeepholeOptimizations && value == 0.0)
		{
			this->Emitter << Instruction::PushZ;
		}
		else if (this->EnablePeepholeOptimizations && value == 1.0)
		{
			this->Emitter << Instruction::FPushO;
		}
		else
		{
			this->Emitter << Instruction::Push << value;
		}
		return *this;
	}

	auto LocalCodeGenerationLayer::EmitPop(const U16 popCount) -> LocalCodeGenerationLayer&
	{
		if (this->EnablePeepholeOptimizations)
		{
			switch (popCount)
			{
				case 0:
					return *this;

				case 1:
					this->Emitter << Instruction::Pop;
					return *this;

				case 2:
					this->Emitter << Instruction::Pop2;
					return *this;

				case 4:
					this->Emitter << Instruction::VecPop;
					return *this;

				case 16:
					this->Emitter << Instruction::MatPop;
					return *this;

				default:
					if (popCount % 2 == 0)
					{
						for (U8 i {0}; i < popCount / 2; ++i)
						{
							this->Emitter << Instruction::Pop2;
						}
					}
					else if (popCount % 4 == 0)
					{
						for (U8 i {0}; i < popCount / 4; ++i)
						{
							this->Emitter << Instruction::VecPop;
						}
					}
					else if (popCount % 16 == 0)
					{
						for (U8 i {0}; i < popCount / 16; ++i)
						{
							this->Emitter << Instruction::MatPop;
						}
					}
					else
					{
						for (U8 i {0}; i < popCount; ++i)
						{
							this->Emitter << Instruction::Pop;
						}
					}
					return *this;
			}
		}
		for (U8 i {0}; i < popCount; ++i)
		{
			this->Emitter << Instruction::Pop;
		}
		return *this;
	}
}
