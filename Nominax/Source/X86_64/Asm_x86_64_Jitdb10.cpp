// File: Asm_x86_64_Jitdb10.cpp
// Author: Mario
// Created: 26.07.2021 4:26 PM
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

#include "../../Include/Nominax/Asm_x86_64.hpp"

namespace Nominax::Assembler::X86_64
{
	NOX_NEVER_INLINE NOX_COLD auto GetVariationTable_10(std::pmr::monotonic_buffer_resource& allocator, std::pmr::vector<InstructionVariationPool>& out) -> void
	{
		std::pmr::vector<InstructionVariation> instruction {&allocator};
		instruction =
		{
			InstructionVariation
			{
				.IntelMnemonic = "pblendvb",
				.GasMnemonic = "pblendvb",
				.Description = "pblendvb xmm, xmm, xmm0",
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
						.Type = OperandType::Xmm0,
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
							.Value = 0x10,
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
				.IntelMnemonic = "pblendvb",
				.GasMnemonic = "pblendvb",
				.Description = "pblendvb xmm, m128, xmm0",
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
						.Type = OperandType::Xmm0,
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
							.Value = 0x10,
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
				.IntelMnemonic = "pblendw",
				.GasMnemonic = "pblendw",
				.Description = "pblendw xmm, xmm, imm8",
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
							.Value = 0x3a,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0xe,
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
				.IntelMnemonic = "pblendw",
				.GasMnemonic = "pblendw",
				.Description = "pblendw xmm, m128, imm8",
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
							.Value = 0x3a,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0xe,
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
				.IntelMnemonic = "pclmulqdq",
				.GasMnemonic = "pclmulqdq",
				.Description = "pclmulqdq xmm, xmm, imm8",
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
					IsaExtension::Pclmulqdq,
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
							.Value = 0x3a,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x44,
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
				.IntelMnemonic = "pclmulqdq",
				.GasMnemonic = "pclmulqdq",
				.Description = "pclmulqdq xmm, m128, imm8",
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
					IsaExtension::Pclmulqdq,
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
							.Value = 0x3a,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x44,
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
				.IntelMnemonic = "pcmpeqb",
				.GasMnemonic = "pcmpeqb",
				.Description = "pcmpeqb mm, mm",
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
							.Value = 0x74,
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
				.IntelMnemonic = "pcmpeqb",
				.GasMnemonic = "pcmpeqb",
				.Description = "pcmpeqb mm, m64",
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
							.Value = 0x74,
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
				.IntelMnemonic = "pcmpeqb",
				.GasMnemonic = "pcmpeqb",
				.Description = "pcmpeqb xmm, xmm",
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
							.Value = 0x74,
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
				.IntelMnemonic = "pcmpeqb",
				.GasMnemonic = "pcmpeqb",
				.Description = "pcmpeqb xmm, m128",
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
							.Value = 0x74,
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
				.IntelMnemonic = "pcmpeqd",
				.GasMnemonic = "pcmpeqd",
				.Description = "pcmpeqd mm, mm",
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
							.Value = 0x76,
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
				.IntelMnemonic = "pcmpeqd",
				.GasMnemonic = "pcmpeqd",
				.Description = "pcmpeqd mm, m64",
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
							.Value = 0x76,
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
				.IntelMnemonic = "pcmpeqd",
				.GasMnemonic = "pcmpeqd",
				.Description = "pcmpeqd xmm, xmm",
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
							.Value = 0x76,
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
				.IntelMnemonic = "pcmpeqd",
				.GasMnemonic = "pcmpeqd",
				.Description = "pcmpeqd xmm, m128",
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
							.Value = 0x76,
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
				.IntelMnemonic = "pcmpeqq",
				.GasMnemonic = "pcmpeqq",
				.Description = "pcmpeqq xmm, xmm",
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
							.Value = 0x29,
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
				.IntelMnemonic = "pcmpeqq",
				.GasMnemonic = "pcmpeqq",
				.Description = "pcmpeqq xmm, m128",
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
							.Value = 0x29,
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
				.IntelMnemonic = "pcmpeqw",
				.GasMnemonic = "pcmpeqw",
				.Description = "pcmpeqw mm, mm",
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
							.Value = 0x75,
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
				.IntelMnemonic = "pcmpeqw",
				.GasMnemonic = "pcmpeqw",
				.Description = "pcmpeqw mm, m64",
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
							.Value = 0x75,
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
				.IntelMnemonic = "pcmpeqw",
				.GasMnemonic = "pcmpeqw",
				.Description = "pcmpeqw xmm, xmm",
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
							.Value = 0x75,
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
				.IntelMnemonic = "pcmpeqw",
				.GasMnemonic = "pcmpeqw",
				.Description = "pcmpeqw xmm, m128",
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
							.Value = 0x75,
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
				.IntelMnemonic = "pcmpestri",
				.GasMnemonic = "pcmpestri",
				.Description = "pcmpestri xmm, xmm, imm8",
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
					ImplicitRegisterOperand::Edx,
					ImplicitRegisterOperand::Eax,
				},
				.ImplicitOutputs =
				{
					ImplicitRegisterOperand::Ecx,
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Sse42,
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
							.Value = 0x3a,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x61,
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
				.IntelMnemonic = "pcmpestri",
				.GasMnemonic = "pcmpestri",
				.Description = "pcmpestri xmm, m128, imm8",
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
					ImplicitRegisterOperand::Edx,
					ImplicitRegisterOperand::Eax,
				},
				.ImplicitOutputs =
				{
					ImplicitRegisterOperand::Ecx,
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Sse42,
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
							.Value = 0x3a,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x61,
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
				.IntelMnemonic = "pcmpestrm",
				.GasMnemonic = "pcmpestrm",
				.Description = "pcmpestrm xmm, xmm, imm8",
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
					ImplicitRegisterOperand::Edx,
					ImplicitRegisterOperand::Eax,
				},
				.ImplicitOutputs =
				{
					ImplicitRegisterOperand::Xmm0,
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Sse42,
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
							.Value = 0x3a,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x60,
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
				.IntelMnemonic = "pcmpestrm",
				.GasMnemonic = "pcmpestrm",
				.Description = "pcmpestrm xmm, m128, imm8",
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
					ImplicitRegisterOperand::Edx,
					ImplicitRegisterOperand::Eax,
				},
				.ImplicitOutputs =
				{
					ImplicitRegisterOperand::Xmm0,
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Sse42,
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
							.Value = 0x3a,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x60,
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
				.IntelMnemonic = "pcmpgtb",
				.GasMnemonic = "pcmpgtb",
				.Description = "pcmpgtb mm, mm",
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
							.Value = 0x64,
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
				.IntelMnemonic = "pcmpgtb",
				.GasMnemonic = "pcmpgtb",
				.Description = "pcmpgtb mm, m64",
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
							.Value = 0x64,
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
				.IntelMnemonic = "pcmpgtb",
				.GasMnemonic = "pcmpgtb",
				.Description = "pcmpgtb xmm, xmm",
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
							.Value = 0x64,
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
				.IntelMnemonic = "pcmpgtb",
				.GasMnemonic = "pcmpgtb",
				.Description = "pcmpgtb xmm, m128",
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
							.Value = 0x64,
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
				.IntelMnemonic = "pcmpgtd",
				.GasMnemonic = "pcmpgtd",
				.Description = "pcmpgtd mm, mm",
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
							.Value = 0x66,
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
				.IntelMnemonic = "pcmpgtd",
				.GasMnemonic = "pcmpgtd",
				.Description = "pcmpgtd mm, m64",
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
							.Value = 0x66,
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
				.IntelMnemonic = "pcmpgtd",
				.GasMnemonic = "pcmpgtd",
				.Description = "pcmpgtd xmm, xmm",
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
							.Value = 0x66,
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
				.IntelMnemonic = "pcmpgtd",
				.GasMnemonic = "pcmpgtd",
				.Description = "pcmpgtd xmm, m128",
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
							.Value = 0x66,
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
				.IntelMnemonic = "pcmpgtq",
				.GasMnemonic = "pcmpgtq",
				.Description = "pcmpgtq xmm, xmm",
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
					IsaExtension::Sse42,
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
							.Value = 0x37,
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
				.IntelMnemonic = "pcmpgtq",
				.GasMnemonic = "pcmpgtq",
				.Description = "pcmpgtq xmm, m128",
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
					IsaExtension::Sse42,
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
							.Value = 0x37,
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
				.IntelMnemonic = "pcmpgtw",
				.GasMnemonic = "pcmpgtw",
				.Description = "pcmpgtw mm, mm",
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
							.Value = 0x65,
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
				.IntelMnemonic = "pcmpgtw",
				.GasMnemonic = "pcmpgtw",
				.Description = "pcmpgtw mm, m64",
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
							.Value = 0x65,
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
				.IntelMnemonic = "pcmpgtw",
				.GasMnemonic = "pcmpgtw",
				.Description = "pcmpgtw xmm, xmm",
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
							.Value = 0x65,
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
				.IntelMnemonic = "pcmpgtw",
				.GasMnemonic = "pcmpgtw",
				.Description = "pcmpgtw xmm, m128",
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
							.Value = 0x65,
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
				.IntelMnemonic = "pcmpistri",
				.GasMnemonic = "pcmpistri",
				.Description = "pcmpistri xmm, xmm, imm8",
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
					ImplicitRegisterOperand::Ecx,
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Sse42,
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
							.Value = 0x3a,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x63,
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
				.IntelMnemonic = "pcmpistri",
				.GasMnemonic = "pcmpistri",
				.Description = "pcmpistri xmm, m128, imm8",
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
					ImplicitRegisterOperand::Ecx,
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Sse42,
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
							.Value = 0x3a,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x63,
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
				.IntelMnemonic = "pcmpistrm",
				.GasMnemonic = "pcmpistrm",
				.Description = "pcmpistrm xmm, xmm, imm8",
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
					ImplicitRegisterOperand::Xmm0,
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Sse42,
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
							.Value = 0x3a,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x62,
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
				.IntelMnemonic = "pcmpistrm",
				.GasMnemonic = "pcmpistrm",
				.Description = "pcmpistrm xmm, m128, imm8",
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
					ImplicitRegisterOperand::Xmm0,
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Sse42,
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
							.Value = 0x3a,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x62,
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
				.IntelMnemonic = "pdep",
				.GasMnemonic = "pdep",
				.Description = "pdep r32, r32, r32",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::R32,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::R32,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::R32,
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
					IsaExtension::Bmi2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b10,
							.Pp = 0b11,
							.W = false,
							.L = false,
							.R = {OperandType::R32},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R32},
							.Vvvv = {OperandType::R32},
						},
						OpCode
						{
							.Value = 0xf5,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R32},
							.Reg = {OperandType::R32},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "pdep",
				.GasMnemonic = "pdep",
				.Description = "pdep r32, r32, m32",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::R32,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::R32,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M32,
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
					IsaExtension::Bmi2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b10,
							.Pp = 0b11,
							.W = false,
							.L = false,
							.R = {OperandType::R32},
							.X = {OperandType::M32},
							.B = {OperandType::M32},
							.Vvvv = {OperandType::R32},
						},
						OpCode
						{
							.Value = 0xf5,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M32},
							.Rm = {OperandType::M32},
							.Reg = {OperandType::R32},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "pdep",
				.GasMnemonic = "pdep",
				.Description = "pdep r64, r64, r64",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::R64,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::R64,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::R64,
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
					IsaExtension::Bmi2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b10,
							.Pp = 0b11,
							.W = true,
							.L = false,
							.R = {OperandType::R64},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R64},
							.Vvvv = {OperandType::R64},
						},
						OpCode
						{
							.Value = 0xf5,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R64},
							.Reg = {OperandType::R64},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "pdep",
				.GasMnemonic = "pdep",
				.Description = "pdep r64, r64, m64",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::R64,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::R64,
						.IsInput = true,
						.IsOutput = false,
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
					IsaExtension::Bmi2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b10,
							.Pp = 0b11,
							.W = true,
							.L = false,
							.R = {OperandType::R64},
							.X = {OperandType::M64},
							.B = {OperandType::M64},
							.Vvvv = {OperandType::R64},
						},
						OpCode
						{
							.Value = 0xf5,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M64},
							.Rm = {OperandType::M64},
							.Reg = {OperandType::R64},
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
				.IntelMnemonic = "pext",
				.GasMnemonic = "pext",
				.Description = "pext r32, r32, r32",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::R32,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::R32,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::R32,
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
					IsaExtension::Bmi2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b10,
							.Pp = 0b10,
							.W = false,
							.L = false,
							.R = {OperandType::R32},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R32},
							.Vvvv = {OperandType::R32},
						},
						OpCode
						{
							.Value = 0xf5,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R32},
							.Reg = {OperandType::R32},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "pext",
				.GasMnemonic = "pext",
				.Description = "pext r32, r32, m32",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::R32,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::R32,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M32,
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
					IsaExtension::Bmi2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b10,
							.Pp = 0b10,
							.W = false,
							.L = false,
							.R = {OperandType::R32},
							.X = {OperandType::M32},
							.B = {OperandType::M32},
							.Vvvv = {OperandType::R32},
						},
						OpCode
						{
							.Value = 0xf5,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M32},
							.Rm = {OperandType::M32},
							.Reg = {OperandType::R32},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "pext",
				.GasMnemonic = "pext",
				.Description = "pext r64, r64, r64",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::R64,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::R64,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::R64,
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
					IsaExtension::Bmi2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b10,
							.Pp = 0b10,
							.W = true,
							.L = false,
							.R = {OperandType::R64},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R64},
							.Vvvv = {OperandType::R64},
						},
						OpCode
						{
							.Value = 0xf5,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R64},
							.Reg = {OperandType::R64},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "pext",
				.GasMnemonic = "pext",
				.Description = "pext r64, r64, m64",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::R64,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::R64,
						.IsInput = true,
						.IsOutput = false,
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
					IsaExtension::Bmi2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b10,
							.Pp = 0b10,
							.W = true,
							.L = false,
							.R = {OperandType::R64},
							.X = {OperandType::M64},
							.B = {OperandType::M64},
							.Vvvv = {OperandType::R64},
						},
						OpCode
						{
							.Value = 0xf5,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M64},
							.Rm = {OperandType::M64},
							.Reg = {OperandType::R64},
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
				.IntelMnemonic = "pextrb",
				.GasMnemonic = "pextrb",
				.Description = "pextrb r32, xmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Sse,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::R32,
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
							.B = {OperandType::R32},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xf,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x3a,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x14,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R32},
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
				.IntelMnemonic = "pextrb",
				.GasMnemonic = "pextrb",
				.Description = "pextrb m8, xmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Sse,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::M8,
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
							.Value = 0x3a,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x14,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M8},
							.Rm = {OperandType::M8},
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
				.IntelMnemonic = "pextrd",
				.GasMnemonic = "pextrd",
				.Description = "pextrd r32, xmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Sse,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::R32,
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
							.B = {OperandType::R32},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xf,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x3a,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x16,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R32},
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
				.IntelMnemonic = "pextrd",
				.GasMnemonic = "pextrd",
				.Description = "pextrd m32, xmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Sse,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::M32,
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
							.X = {OperandType::M32},
							.B = {OperandType::M32},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xf,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x3a,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x16,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M32},
							.Rm = {OperandType::M32},
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
				.IntelMnemonic = "pextrq",
				.GasMnemonic = "pextrq",
				.Description = "pextrq r64, xmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Sse,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::R64,
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
							.W = true,
							.R = {OperandType::Xmm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R64},
							.IsMandatory = true,
						},
						OpCode
						{
							.Value = 0xf,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x3a,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x16,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R64},
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
				.IntelMnemonic = "pextrq",
				.GasMnemonic = "pextrq",
				.Description = "pextrq m64, xmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Sse,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::M64,
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
							.W = true,
							.R = {OperandType::Xmm},
							.X = {OperandType::M64},
							.B = {OperandType::M64},
							.IsMandatory = true,
						},
						OpCode
						{
							.Value = 0xf,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x3a,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x16,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M64},
							.Rm = {OperandType::M64},
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
				.IntelMnemonic = "pextrw",
				.GasMnemonic = "pextrw",
				.Description = "pextrw r32, mm, imm8",
				.MmxMode = MmxModeType::Mmx,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::R32,
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
							.R = {OperandType::R32},
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
							.Value = 0xc5,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Mm},
							.Reg = {OperandType::R32},
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
				.IntelMnemonic = "pextrw",
				.GasMnemonic = "pextrw",
				.Description = "pextrw r32, xmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Sse,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::R32,
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
							.B = {OperandType::R32},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xf,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x3a,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x15,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R32},
							.Reg = {OperandType::Xmm},
						},
						ImmediateScalar
						{
							.Size = 1,
							.Value = {OperandType::Imm8},
						},
					},
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
							.R = {OperandType::R32},
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
							.Value = 0xc5,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Xmm},
							.Reg = {OperandType::R32},
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
				.IntelMnemonic = "pextrw",
				.GasMnemonic = "pextrw",
				.Description = "pextrw m16, xmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Sse,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::M16,
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
							.X = {OperandType::M16},
							.B = {OperandType::M16},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xf,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x3a,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x15,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M16},
							.Rm = {OperandType::M16},
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
				.IntelMnemonic = "pf2id",
				.GasMnemonic = "pf2id",
				.Description = "pf2id mm, mm",
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
					IsaExtension::D3Now,
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
							.Value = 0x1d,
							.Addend = {UINT64_C(0x0)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "pf2id",
				.GasMnemonic = "pf2id",
				.Description = "pf2id mm, m64",
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
					IsaExtension::D3Now,
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
							.Value = 0x1d,
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
				.IntelMnemonic = "pf2iw",
				.GasMnemonic = "pf2iw",
				.Description = "pf2iw mm, mm",
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
							.Value = 0x1c,
							.Addend = {UINT64_C(0x0)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "pf2iw",
				.GasMnemonic = "pf2iw",
				.Description = "pf2iw mm, m64",
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
							.Value = 0x1c,
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
				.IntelMnemonic = "pfacc",
				.GasMnemonic = "pfacc",
				.Description = "pfacc mm, mm",
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
					IsaExtension::D3Now,
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
							.Value = 0xae,
							.Addend = {UINT64_C(0x0)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "pfacc",
				.GasMnemonic = "pfacc",
				.Description = "pfacc mm, m64",
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
					IsaExtension::D3Now,
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
							.Value = 0xae,
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
				.IntelMnemonic = "pfadd",
				.GasMnemonic = "pfadd",
				.Description = "pfadd mm, mm",
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
					IsaExtension::D3Now,
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
							.Value = 0x9e,
							.Addend = {UINT64_C(0x0)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "pfadd",
				.GasMnemonic = "pfadd",
				.Description = "pfadd mm, m64",
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
					IsaExtension::D3Now,
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
							.Value = 0x9e,
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
				.IntelMnemonic = "pfcmpeq",
				.GasMnemonic = "pfcmpeq",
				.Description = "pfcmpeq mm, mm",
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
					IsaExtension::D3Now,
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
							.Value = 0xb0,
							.Addend = {UINT64_C(0x0)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "pfcmpeq",
				.GasMnemonic = "pfcmpeq",
				.Description = "pfcmpeq mm, m64",
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
					IsaExtension::D3Now,
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
							.Value = 0xb0,
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
				.IntelMnemonic = "pfcmpge",
				.GasMnemonic = "pfcmpge",
				.Description = "pfcmpge mm, mm",
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
					IsaExtension::D3Now,
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
							.Value = 0x90,
							.Addend = {UINT64_C(0x0)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "pfcmpge",
				.GasMnemonic = "pfcmpge",
				.Description = "pfcmpge mm, m64",
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
					IsaExtension::D3Now,
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
							.Value = 0x90,
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
				.IntelMnemonic = "pfcmpgt",
				.GasMnemonic = "pfcmpgt",
				.Description = "pfcmpgt mm, mm",
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
					IsaExtension::D3Now,
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
							.Value = 0xa0,
							.Addend = {UINT64_C(0x0)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "pfcmpgt",
				.GasMnemonic = "pfcmpgt",
				.Description = "pfcmpgt mm, m64",
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
					IsaExtension::D3Now,
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
							.Value = 0xa0,
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
				.IntelMnemonic = "pfmax",
				.GasMnemonic = "pfmax",
				.Description = "pfmax mm, mm",
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
					IsaExtension::D3Now,
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
							.Value = 0xa4,
							.Addend = {UINT64_C(0x0)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "pfmax",
				.GasMnemonic = "pfmax",
				.Description = "pfmax mm, m64",
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
					IsaExtension::D3Now,
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
							.Value = 0xa4,
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
				.IntelMnemonic = "pfmin",
				.GasMnemonic = "pfmin",
				.Description = "pfmin mm, mm",
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
					IsaExtension::D3Now,
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
							.Value = 0x94,
							.Addend = {UINT64_C(0x0)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "pfmin",
				.GasMnemonic = "pfmin",
				.Description = "pfmin mm, m64",
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
					IsaExtension::D3Now,
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
							.Value = 0x94,
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
				.IntelMnemonic = "pfmul",
				.GasMnemonic = "pfmul",
				.Description = "pfmul mm, mm",
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
					IsaExtension::D3Now,
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
							.Value = 0xb4,
							.Addend = {UINT64_C(0x0)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "pfmul",
				.GasMnemonic = "pfmul",
				.Description = "pfmul mm, m64",
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
					IsaExtension::D3Now,
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
							.Value = 0xb4,
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
				.IntelMnemonic = "pfnacc",
				.GasMnemonic = "pfnacc",
				.Description = "pfnacc mm, mm",
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
							.Value = 0x8a,
							.Addend = {UINT64_C(0x0)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "pfnacc",
				.GasMnemonic = "pfnacc",
				.Description = "pfnacc mm, m64",
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
							.Value = 0x8a,
							.Addend = {UINT64_C(0x0)},
						},
					},
				}
			},
		};
		out.emplace_back(std::move(instruction));
	};
}
