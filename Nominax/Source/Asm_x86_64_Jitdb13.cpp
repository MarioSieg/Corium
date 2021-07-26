// File: Asm_x86_64_Jitdb.cpp
// Author: Mario
// Created: 07.27.2021 5:38 PM
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
// Auto generated, do not edit!

#include "../Include/Nominax/Asm_x86_64.hpp"

namespace Nominax::Assembler::X86_64
{
NOX_NEVER_INLINE NOX_COLD auto GetVariationTable_13(std::pmr::monotonic_buffer_resource& allocator, std::pmr::vector<InstructionVariationPool>& out) -> void
{
	std::pmr::vector<InstructionVariation> instruction{&allocator};
	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "prefetchw",
			.GasMnemonic = "prefetchw",
			.Description = "prefetchw m8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M8,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Prefetchw,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {OperandType::M8},
						.B = {OperandType::M8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xd,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M8},
						.Rm = {OperandType::M8},
						.Reg = {UINT64_C(0x1)},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "prefetchwt1",
			.GasMnemonic = "prefetchwt1",
			.Description = "prefetchwt1 m8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M8,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Prefetchwt1,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {OperandType::M8},
						.B = {OperandType::M8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xd,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M8},
						.Rm = {OperandType::M8},
						.Reg = {UINT64_C(0x2)},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "psadbw",
			.GasMnemonic = "psadbw",
			.Description = "psadbw mm, mm",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = true,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::MmxExt,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Mm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xf6,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Mm},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psadbw",
			.GasMnemonic = "psadbw",
			.Description = "psadbw mm, m64",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M64,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::MmxExt,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xf6,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psadbw",
			.GasMnemonic = "psadbw",
			.Description = "psadbw xmm, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = true,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xf6,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psadbw",
			.GasMnemonic = "psadbw",
			.Description = "psadbw xmm, m128",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M128,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xf6,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "pshufb",
			.GasMnemonic = "pshufb",
			.Description = "pshufb mm, mm",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Ssse3,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Mm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x38,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x0,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Mm},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "pshufb",
			.GasMnemonic = "pshufb",
			.Description = "pshufb mm, m64",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M64,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Ssse3,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x38,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x0,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "pshufb",
			.GasMnemonic = "pshufb",
			.Description = "pshufb xmm, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Ssse3,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x38,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x0,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "pshufb",
			.GasMnemonic = "pshufb",
			.Description = "pshufb xmm, m128",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M128,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Ssse3,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x38,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x0,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "pshufd",
			.GasMnemonic = "pshufd",
			.Description = "pshufd xmm, xmm, imm8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Imm8,
					.IsInput = false,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x70,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
					ImmediateScalar
					{
						.Size = 1,
						.Value = {OperandType::Imm8},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "pshufd",
			.GasMnemonic = "pshufd",
			.Description = "pshufd xmm, m128, imm8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M128,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Imm8,
					.IsInput = false,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x70,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
					ImmediateScalar
					{
						.Size = 1,
						.Value = {OperandType::Imm8},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "pshufhw",
			.GasMnemonic = "pshufhw",
			.Description = "pshufhw xmm, xmm, imm8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Imm8,
					.IsInput = false,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0xf3,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x70,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
					ImmediateScalar
					{
						.Size = 1,
						.Value = {OperandType::Imm8},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "pshufhw",
			.GasMnemonic = "pshufhw",
			.Description = "pshufhw xmm, m128, imm8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M128,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Imm8,
					.IsInput = false,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0xf3,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x70,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
					ImmediateScalar
					{
						.Size = 1,
						.Value = {OperandType::Imm8},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "pshuflw",
			.GasMnemonic = "pshuflw",
			.Description = "pshuflw xmm, xmm, imm8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Imm8,
					.IsInput = false,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0xf2,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x70,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
					ImmediateScalar
					{
						.Size = 1,
						.Value = {OperandType::Imm8},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "pshuflw",
			.GasMnemonic = "pshuflw",
			.Description = "pshuflw xmm, m128, imm8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M128,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Imm8,
					.IsInput = false,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0xf2,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x70,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
					ImmediateScalar
					{
						.Size = 1,
						.Value = {OperandType::Imm8},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "pshufw",
			.GasMnemonic = "pshufw",
			.Description = "pshufw mm, mm, imm8",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Imm8,
					.IsInput = false,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::MmxExt,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Mm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x70,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Mm},
						.Reg = {OperandType::Mm},
					},
					ImmediateScalar
					{
						.Size = 1,
						.Value = {OperandType::Imm8},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "pshufw",
			.GasMnemonic = "pshufw",
			.Description = "pshufw mm, m64, imm8",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M64,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Imm8,
					.IsInput = false,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::MmxExt,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x70,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Mm},
					},
					ImmediateScalar
					{
						.Size = 1,
						.Value = {OperandType::Imm8},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "psignb",
			.GasMnemonic = "psignb",
			.Description = "psignb mm, mm",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Ssse3,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Mm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x38,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x8,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Mm},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psignb",
			.GasMnemonic = "psignb",
			.Description = "psignb mm, m64",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M64,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Ssse3,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x38,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x8,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psignb",
			.GasMnemonic = "psignb",
			.Description = "psignb xmm, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Ssse3,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x38,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x8,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psignb",
			.GasMnemonic = "psignb",
			.Description = "psignb xmm, m128",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M128,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Ssse3,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x38,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x8,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "psignd",
			.GasMnemonic = "psignd",
			.Description = "psignd mm, mm",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Ssse3,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Mm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x38,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xa,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Mm},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psignd",
			.GasMnemonic = "psignd",
			.Description = "psignd mm, m64",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M64,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Ssse3,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x38,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xa,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psignd",
			.GasMnemonic = "psignd",
			.Description = "psignd xmm, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Ssse3,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x38,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xa,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psignd",
			.GasMnemonic = "psignd",
			.Description = "psignd xmm, m128",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M128,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Ssse3,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x38,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xa,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "psignw",
			.GasMnemonic = "psignw",
			.Description = "psignw mm, mm",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Ssse3,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Mm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x38,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x9,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Mm},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psignw",
			.GasMnemonic = "psignw",
			.Description = "psignw mm, m64",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M64,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Ssse3,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x38,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x9,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psignw",
			.GasMnemonic = "psignw",
			.Description = "psignw xmm, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Ssse3,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x38,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x9,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psignw",
			.GasMnemonic = "psignw",
			.Description = "psignw xmm, m128",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M128,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Ssse3,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x38,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x9,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "pslld",
			.GasMnemonic = "pslld",
			.Description = "pslld mm, imm8",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Imm8,
					.IsInput = false,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Mm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x72,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Mm},
						.Reg = {UINT64_C(0x6)},
					},
					ImmediateScalar
					{
						.Size = 1,
						.Value = {OperandType::Imm8},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "pslld",
			.GasMnemonic = "pslld",
			.Description = "pslld mm, mm",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Mm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xf2,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Mm},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "pslld",
			.GasMnemonic = "pslld",
			.Description = "pslld mm, m64",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M64,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xf2,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "pslld",
			.GasMnemonic = "pslld",
			.Description = "pslld xmm, imm8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Imm8,
					.IsInput = false,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x72,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {UINT64_C(0x6)},
					},
					ImmediateScalar
					{
						.Size = 1,
						.Value = {OperandType::Imm8},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "pslld",
			.GasMnemonic = "pslld",
			.Description = "pslld xmm, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xf2,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "pslld",
			.GasMnemonic = "pslld",
			.Description = "pslld xmm, m128",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M128,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xf2,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "pslldq",
			.GasMnemonic = "pslldq",
			.Description = "pslldq xmm, imm8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Imm8,
					.IsInput = false,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x73,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {UINT64_C(0x7)},
					},
					ImmediateScalar
					{
						.Size = 1,
						.Value = {OperandType::Imm8},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "psllq",
			.GasMnemonic = "psllq",
			.Description = "psllq mm, imm8",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Imm8,
					.IsInput = false,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Mm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x73,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Mm},
						.Reg = {UINT64_C(0x6)},
					},
					ImmediateScalar
					{
						.Size = 1,
						.Value = {OperandType::Imm8},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psllq",
			.GasMnemonic = "psllq",
			.Description = "psllq mm, mm",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Mm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xf3,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Mm},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psllq",
			.GasMnemonic = "psllq",
			.Description = "psllq mm, m64",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M64,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xf3,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psllq",
			.GasMnemonic = "psllq",
			.Description = "psllq xmm, imm8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Imm8,
					.IsInput = false,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x73,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {UINT64_C(0x6)},
					},
					ImmediateScalar
					{
						.Size = 1,
						.Value = {OperandType::Imm8},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psllq",
			.GasMnemonic = "psllq",
			.Description = "psllq xmm, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xf3,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psllq",
			.GasMnemonic = "psllq",
			.Description = "psllq xmm, m128",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M128,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xf3,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "psllw",
			.GasMnemonic = "psllw",
			.Description = "psllw mm, imm8",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Imm8,
					.IsInput = false,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Mm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x71,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Mm},
						.Reg = {UINT64_C(0x6)},
					},
					ImmediateScalar
					{
						.Size = 1,
						.Value = {OperandType::Imm8},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psllw",
			.GasMnemonic = "psllw",
			.Description = "psllw mm, mm",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Mm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xf1,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Mm},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psllw",
			.GasMnemonic = "psllw",
			.Description = "psllw mm, m64",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M64,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xf1,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psllw",
			.GasMnemonic = "psllw",
			.Description = "psllw xmm, imm8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Imm8,
					.IsInput = false,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x71,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {UINT64_C(0x6)},
					},
					ImmediateScalar
					{
						.Size = 1,
						.Value = {OperandType::Imm8},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psllw",
			.GasMnemonic = "psllw",
			.Description = "psllw xmm, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xf1,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psllw",
			.GasMnemonic = "psllw",
			.Description = "psllw xmm, m128",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M128,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xf1,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "psrad",
			.GasMnemonic = "psrad",
			.Description = "psrad mm, imm8",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Imm8,
					.IsInput = false,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Mm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x72,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Mm},
						.Reg = {UINT64_C(0x4)},
					},
					ImmediateScalar
					{
						.Size = 1,
						.Value = {OperandType::Imm8},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psrad",
			.GasMnemonic = "psrad",
			.Description = "psrad mm, mm",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Mm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xe2,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Mm},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psrad",
			.GasMnemonic = "psrad",
			.Description = "psrad mm, m64",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M64,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xe2,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psrad",
			.GasMnemonic = "psrad",
			.Description = "psrad xmm, imm8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Imm8,
					.IsInput = false,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x72,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {UINT64_C(0x4)},
					},
					ImmediateScalar
					{
						.Size = 1,
						.Value = {OperandType::Imm8},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psrad",
			.GasMnemonic = "psrad",
			.Description = "psrad xmm, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xe2,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psrad",
			.GasMnemonic = "psrad",
			.Description = "psrad xmm, m128",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M128,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xe2,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "psraw",
			.GasMnemonic = "psraw",
			.Description = "psraw mm, imm8",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Imm8,
					.IsInput = false,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Mm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x71,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Mm},
						.Reg = {UINT64_C(0x4)},
					},
					ImmediateScalar
					{
						.Size = 1,
						.Value = {OperandType::Imm8},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psraw",
			.GasMnemonic = "psraw",
			.Description = "psraw mm, mm",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Mm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xe1,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Mm},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psraw",
			.GasMnemonic = "psraw",
			.Description = "psraw mm, m64",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M64,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xe1,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psraw",
			.GasMnemonic = "psraw",
			.Description = "psraw xmm, imm8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Imm8,
					.IsInput = false,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x71,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {UINT64_C(0x4)},
					},
					ImmediateScalar
					{
						.Size = 1,
						.Value = {OperandType::Imm8},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psraw",
			.GasMnemonic = "psraw",
			.Description = "psraw xmm, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xe1,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psraw",
			.GasMnemonic = "psraw",
			.Description = "psraw xmm, m128",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M128,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xe1,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "psrld",
			.GasMnemonic = "psrld",
			.Description = "psrld mm, imm8",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Imm8,
					.IsInput = false,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Mm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x72,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Mm},
						.Reg = {UINT64_C(0x2)},
					},
					ImmediateScalar
					{
						.Size = 1,
						.Value = {OperandType::Imm8},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psrld",
			.GasMnemonic = "psrld",
			.Description = "psrld mm, mm",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Mm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xd2,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Mm},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psrld",
			.GasMnemonic = "psrld",
			.Description = "psrld mm, m64",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M64,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xd2,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psrld",
			.GasMnemonic = "psrld",
			.Description = "psrld xmm, imm8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Imm8,
					.IsInput = false,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x72,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {UINT64_C(0x2)},
					},
					ImmediateScalar
					{
						.Size = 1,
						.Value = {OperandType::Imm8},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psrld",
			.GasMnemonic = "psrld",
			.Description = "psrld xmm, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xd2,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psrld",
			.GasMnemonic = "psrld",
			.Description = "psrld xmm, m128",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M128,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xd2,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "psrldq",
			.GasMnemonic = "psrldq",
			.Description = "psrldq xmm, imm8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Imm8,
					.IsInput = false,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x73,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {UINT64_C(0x3)},
					},
					ImmediateScalar
					{
						.Size = 1,
						.Value = {OperandType::Imm8},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "psrlq",
			.GasMnemonic = "psrlq",
			.Description = "psrlq mm, imm8",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Imm8,
					.IsInput = false,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Mm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x73,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Mm},
						.Reg = {UINT64_C(0x2)},
					},
					ImmediateScalar
					{
						.Size = 1,
						.Value = {OperandType::Imm8},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psrlq",
			.GasMnemonic = "psrlq",
			.Description = "psrlq mm, mm",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Mm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xd3,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Mm},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psrlq",
			.GasMnemonic = "psrlq",
			.Description = "psrlq mm, m64",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M64,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xd3,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psrlq",
			.GasMnemonic = "psrlq",
			.Description = "psrlq xmm, imm8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Imm8,
					.IsInput = false,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x73,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {UINT64_C(0x2)},
					},
					ImmediateScalar
					{
						.Size = 1,
						.Value = {OperandType::Imm8},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psrlq",
			.GasMnemonic = "psrlq",
			.Description = "psrlq xmm, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xd3,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psrlq",
			.GasMnemonic = "psrlq",
			.Description = "psrlq xmm, m128",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M128,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xd3,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "psrlw",
			.GasMnemonic = "psrlw",
			.Description = "psrlw mm, imm8",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Imm8,
					.IsInput = false,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Mm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x71,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Mm},
						.Reg = {UINT64_C(0x2)},
					},
					ImmediateScalar
					{
						.Size = 1,
						.Value = {OperandType::Imm8},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psrlw",
			.GasMnemonic = "psrlw",
			.Description = "psrlw mm, mm",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Mm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xd1,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Mm},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psrlw",
			.GasMnemonic = "psrlw",
			.Description = "psrlw mm, m64",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M64,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xd1,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psrlw",
			.GasMnemonic = "psrlw",
			.Description = "psrlw xmm, imm8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Imm8,
					.IsInput = false,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x71,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {UINT64_C(0x2)},
					},
					ImmediateScalar
					{
						.Size = 1,
						.Value = {OperandType::Imm8},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psrlw",
			.GasMnemonic = "psrlw",
			.Description = "psrlw xmm, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xd1,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psrlw",
			.GasMnemonic = "psrlw",
			.Description = "psrlw xmm, m128",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M128,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xd1,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "psubb",
			.GasMnemonic = "psubb",
			.Description = "psubb mm, mm",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = true,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Mm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xf8,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Mm},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psubb",
			.GasMnemonic = "psubb",
			.Description = "psubb mm, m64",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M64,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xf8,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psubb",
			.GasMnemonic = "psubb",
			.Description = "psubb xmm, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = true,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xf8,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psubb",
			.GasMnemonic = "psubb",
			.Description = "psubb xmm, m128",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M128,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xf8,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "psubd",
			.GasMnemonic = "psubd",
			.Description = "psubd mm, mm",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = true,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Mm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xfa,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Mm},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psubd",
			.GasMnemonic = "psubd",
			.Description = "psubd mm, m64",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M64,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xfa,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psubd",
			.GasMnemonic = "psubd",
			.Description = "psubd xmm, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = true,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xfa,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psubd",
			.GasMnemonic = "psubd",
			.Description = "psubd xmm, m128",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M128,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xfa,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "psubq",
			.GasMnemonic = "psubq",
			.Description = "psubq mm, mm",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = true,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Mm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xfb,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Mm},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psubq",
			.GasMnemonic = "psubq",
			.Description = "psubq mm, m64",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M64,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xfb,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psubq",
			.GasMnemonic = "psubq",
			.Description = "psubq xmm, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = true,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xfb,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psubq",
			.GasMnemonic = "psubq",
			.Description = "psubq xmm, m128",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M128,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xfb,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "psubsb",
			.GasMnemonic = "psubsb",
			.Description = "psubsb mm, mm",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = true,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Mm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xe8,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Mm},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psubsb",
			.GasMnemonic = "psubsb",
			.Description = "psubsb mm, m64",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M64,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xe8,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psubsb",
			.GasMnemonic = "psubsb",
			.Description = "psubsb xmm, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = true,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xe8,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psubsb",
			.GasMnemonic = "psubsb",
			.Description = "psubsb xmm, m128",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M128,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xe8,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "psubsw",
			.GasMnemonic = "psubsw",
			.Description = "psubsw mm, mm",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = true,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Mm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xe9,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Mm},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psubsw",
			.GasMnemonic = "psubsw",
			.Description = "psubsw mm, m64",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M64,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xe9,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psubsw",
			.GasMnemonic = "psubsw",
			.Description = "psubsw xmm, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = true,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xe9,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psubsw",
			.GasMnemonic = "psubsw",
			.Description = "psubsw xmm, m128",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M128,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xe9,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "psubusb",
			.GasMnemonic = "psubusb",
			.Description = "psubusb mm, mm",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = true,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Mm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xd8,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Mm},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psubusb",
			.GasMnemonic = "psubusb",
			.Description = "psubusb mm, m64",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M64,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xd8,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psubusb",
			.GasMnemonic = "psubusb",
			.Description = "psubusb xmm, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = true,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xd8,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psubusb",
			.GasMnemonic = "psubusb",
			.Description = "psubusb xmm, m128",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M128,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xd8,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "psubusw",
			.GasMnemonic = "psubusw",
			.Description = "psubusw mm, mm",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = true,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Mm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xd9,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Mm},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psubusw",
			.GasMnemonic = "psubusw",
			.Description = "psubusw mm, m64",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M64,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xd9,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psubusw",
			.GasMnemonic = "psubusw",
			.Description = "psubusw xmm, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = true,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xd9,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psubusw",
			.GasMnemonic = "psubusw",
			.Description = "psubusw xmm, m128",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M128,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xd9,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "psubw",
			.GasMnemonic = "psubw",
			.Description = "psubw mm, mm",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = true,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Mm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xf9,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Mm},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psubw",
			.GasMnemonic = "psubw",
			.Description = "psubw mm, m64",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M64,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xf9,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psubw",
			.GasMnemonic = "psubw",
			.Description = "psubw xmm, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = true,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xf9,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "psubw",
			.GasMnemonic = "psubw",
			.Description = "psubw xmm, m128",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M128,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xf9,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "pswapd",
			.GasMnemonic = "pswapd",
			.Description = "pswapd mm, mm",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::D3NowExt,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Mm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Mm},
						.Reg = {OperandType::Mm},
					},
					OpCode
					{
						.Value = 0xbb,
						.Addend = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "pswapd",
			.GasMnemonic = "pswapd",
			.Description = "pswapd mm, m64",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M64,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::D3NowExt,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Mm},
					},
					OpCode
					{
						.Value = 0xbb,
						.Addend = {UINT64_C(0x0)},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "ptest",
			.GasMnemonic = "ptest",
			.Description = "ptest xmm, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse41,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x38,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x17,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "ptest",
			.GasMnemonic = "ptest",
			.Description = "ptest xmm, m128",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M128,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse41,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x38,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x17,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "punpckhbw",
			.GasMnemonic = "punpckhbw",
			.Description = "punpckhbw mm, mm",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Mm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x68,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Mm},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "punpckhbw",
			.GasMnemonic = "punpckhbw",
			.Description = "punpckhbw mm, m64",
			.MmxMode = MmxModeType::Mmx,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Mm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M64,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Mmx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Mm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x68,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::Mm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "punpckhbw",
			.GasMnemonic = "punpckhbw",
			.Description = "punpckhbw xmm, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x68,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "punpckhbw",
			.GasMnemonic = "punpckhbw",
			.Description = "punpckhbw xmm, m128",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M128,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sse2,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Prefix
					{
						.Value = 0x66,
						.IsMandatory = true,
					},
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x68,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

};
}
