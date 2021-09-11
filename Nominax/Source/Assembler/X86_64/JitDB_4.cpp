// File: JitDB_4.cpp
// Author: Mario
// Created: 20.08.2021 2:40 PM
// Project: Corium
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

#include "../../../Include/Nominax/Assembler/_Assembler.hpp"

namespace Nominax::Assembler::X86_64
{
	NOX_NEVER_INLINE NOX_COLD auto GetVariationTable_4(std::pmr::monotonic_buffer_resource& allocator, std::pmr::vector<InstructionVariationPool>& out) -> void
	{
		std::pmr::vector<InstructionVariation> instruction {&allocator};
		instruction =
		{
			InstructionVariation
			{
				.IntelMnemonic = "divss",
				.GasMnemonic = "divss",
				.Description = "divss xmm, xmm",
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
					IsaExtension::Sse,
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
							.Value = 0x5e,
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
				.IntelMnemonic = "divss",
				.GasMnemonic = "divss",
				.Description = "divss xmm, m32",
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
					IsaExtension::Sse,
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
							.Value = 0x5e,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M32},
							.Rm = {OperandType::M32},
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
				.IntelMnemonic = "dppd",
				.GasMnemonic = "dppd",
				.Description = "dppd xmm, xmm, imm8",
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
							.Value = 0x41,
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
				.IntelMnemonic = "dppd",
				.GasMnemonic = "dppd",
				.Description = "dppd xmm, m128, imm8",
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
							.Value = 0x41,
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
				.IntelMnemonic = "dpps",
				.GasMnemonic = "dpps",
				.Description = "dpps xmm, xmm, imm8",
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
							.Value = 0x40,
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
				.IntelMnemonic = "dpps",
				.GasMnemonic = "dpps",
				.Description = "dpps xmm, m128, imm8",
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
							.Value = 0x40,
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
				.IntelMnemonic = "emms",
				.GasMnemonic = "emms",
				.Description = "emms",
				.MmxMode = MmxModeType::Mmx,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
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
						OpCode
						{
							.Value = 0xf,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x77,
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
				.IntelMnemonic = "extractps",
				.GasMnemonic = "extractps",
				.Description = "extractps r32, xmm, imm8",
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
							.Value = 0x17,
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
				.IntelMnemonic = "extractps",
				.GasMnemonic = "extractps",
				.Description = "extractps m32, xmm, imm8",
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
							.Value = 0x17,
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
				.IntelMnemonic = "extrq",
				.GasMnemonic = "extrq",
				.Description = "extrq xmm, xmm",
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
					IsaExtension::Sse4A,
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
							.Value = 0x79,
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
				.IntelMnemonic = "extrq",
				.GasMnemonic = "extrq",
				.Description = "extrq xmm, imm8, imm8",
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
					IsaExtension::Sse4A,
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
							.Value = 0x78,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Xmm},
							.Reg = {UINT64_C(0x0)},
						},
						ImmediateScalar
						{
							.Size = 1,
							.Value = {OperandType::Imm8},
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
				.IntelMnemonic = "femms",
				.GasMnemonic = "femms",
				.Description = "femms",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Femms,
				},
				.EncodingScheme =
				{
					Encoding
					{
						OpCode
						{
							.Value = 0xf,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0xe,
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
				.IntelMnemonic = "haddpd",
				.GasMnemonic = "haddpd",
				.Description = "haddpd xmm, xmm",
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
					IsaExtension::Sse3,
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
							.Value = 0x7c,
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
				.IntelMnemonic = "haddpd",
				.GasMnemonic = "haddpd",
				.Description = "haddpd xmm, m128",
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
					IsaExtension::Sse3,
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
							.Value = 0x7c,
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
				.IntelMnemonic = "haddps",
				.GasMnemonic = "haddps",
				.Description = "haddps xmm, xmm",
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
					IsaExtension::Sse3,
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
							.Value = 0x7c,
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
				.IntelMnemonic = "haddps",
				.GasMnemonic = "haddps",
				.Description = "haddps xmm, m128",
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
					IsaExtension::Sse3,
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
							.Value = 0x7c,
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
				.IntelMnemonic = "hsubpd",
				.GasMnemonic = "hsubpd",
				.Description = "hsubpd xmm, xmm",
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
					IsaExtension::Sse3,
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
							.Value = 0x7d,
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
				.IntelMnemonic = "hsubpd",
				.GasMnemonic = "hsubpd",
				.Description = "hsubpd xmm, m128",
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
					IsaExtension::Sse3,
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
							.Value = 0x7d,
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
				.IntelMnemonic = "hsubps",
				.GasMnemonic = "hsubps",
				.Description = "hsubps xmm, xmm",
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
					IsaExtension::Sse3,
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
							.Value = 0x7d,
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
				.IntelMnemonic = "hsubps",
				.GasMnemonic = "hsubps",
				.Description = "hsubps xmm, m128",
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
					IsaExtension::Sse3,
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
							.Value = 0x7d,
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
				.IntelMnemonic = "idiv",
				.GasMnemonic = "idivb",
				.Description = "idivb r8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::R8,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
					ImplicitRegisterOperand::Ax,
				},
				.ImplicitOutputs =
				{
					ImplicitRegisterOperand::Ax,
				},
				.IsaFeatureExtensions =
				{
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
							.B = {OperandType::R8},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xf6,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R8},
							.Reg = {UINT64_C(0x7)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "idiv",
				.GasMnemonic = "idivw",
				.Description = "idivw r16",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::R16,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
					ImplicitRegisterOperand::Dx,
					ImplicitRegisterOperand::Ax,
				},
				.ImplicitOutputs =
				{
					ImplicitRegisterOperand::Dx,
					ImplicitRegisterOperand::Ax,
				},
				.IsaFeatureExtensions =
				{
				},
				.EncodingScheme =
				{
					Encoding
					{
						Prefix
						{
							.Value = 0x66,
							.IsMandatory = false,
						},
						Rex
						{
							.W = false,
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R16},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xf7,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R16},
							.Reg = {UINT64_C(0x7)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "idiv",
				.GasMnemonic = "idivl",
				.Description = "idivl r32",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
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
					ImplicitRegisterOperand::Eax,
					ImplicitRegisterOperand::Edx,
				},
				.ImplicitOutputs =
				{
					ImplicitRegisterOperand::Eax,
					ImplicitRegisterOperand::Edx,
				},
				.IsaFeatureExtensions =
				{
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
							.B = {OperandType::R32},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xf7,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R32},
							.Reg = {UINT64_C(0x7)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "idiv",
				.GasMnemonic = "idivq",
				.Description = "idivq r64",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
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
					ImplicitRegisterOperand::Rdx,
					ImplicitRegisterOperand::Rax,
				},
				.ImplicitOutputs =
				{
					ImplicitRegisterOperand::Rdx,
					ImplicitRegisterOperand::Rax,
				},
				.IsaFeatureExtensions =
				{
				},
				.EncodingScheme =
				{
					Encoding
					{
						Rex
						{
							.W = true,
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R64},
							.IsMandatory = true,
						},
						OpCode
						{
							.Value = 0xf7,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R64},
							.Reg = {UINT64_C(0x7)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "idiv",
				.GasMnemonic = "idivb",
				.Description = "idivb m8",
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
					ImplicitRegisterOperand::Ax,
				},
				.ImplicitOutputs =
				{
					ImplicitRegisterOperand::Ax,
				},
				.IsaFeatureExtensions =
				{
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
							.Value = 0xf6,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M8},
							.Rm = {OperandType::M8},
							.Reg = {UINT64_C(0x7)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "idiv",
				.GasMnemonic = "idivw",
				.Description = "idivw m16",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::M16,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
					ImplicitRegisterOperand::Dx,
					ImplicitRegisterOperand::Ax,
				},
				.ImplicitOutputs =
				{
					ImplicitRegisterOperand::Dx,
					ImplicitRegisterOperand::Ax,
				},
				.IsaFeatureExtensions =
				{
				},
				.EncodingScheme =
				{
					Encoding
					{
						Prefix
						{
							.Value = 0x66,
							.IsMandatory = false,
						},
						Rex
						{
							.W = false,
							.R = {UINT64_C(0x0)},
							.X = {OperandType::M16},
							.B = {OperandType::M16},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xf7,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M16},
							.Rm = {OperandType::M16},
							.Reg = {UINT64_C(0x7)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "idiv",
				.GasMnemonic = "idivl",
				.Description = "idivl m32",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
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
					ImplicitRegisterOperand::Eax,
					ImplicitRegisterOperand::Edx,
				},
				.ImplicitOutputs =
				{
					ImplicitRegisterOperand::Eax,
					ImplicitRegisterOperand::Edx,
				},
				.IsaFeatureExtensions =
				{
				},
				.EncodingScheme =
				{
					Encoding
					{
						Rex
						{
							.W = false,
							.R = {UINT64_C(0x0)},
							.X = {OperandType::M32},
							.B = {OperandType::M32},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xf7,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M32},
							.Rm = {OperandType::M32},
							.Reg = {UINT64_C(0x7)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "idiv",
				.GasMnemonic = "idivq",
				.Description = "idivq m64",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
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
					ImplicitRegisterOperand::Rdx,
					ImplicitRegisterOperand::Rax,
				},
				.ImplicitOutputs =
				{
					ImplicitRegisterOperand::Rdx,
					ImplicitRegisterOperand::Rax,
				},
				.IsaFeatureExtensions =
				{
				},
				.EncodingScheme =
				{
					Encoding
					{
						Rex
						{
							.W = true,
							.R = {UINT64_C(0x0)},
							.X = {OperandType::M64},
							.B = {OperandType::M64},
							.IsMandatory = true,
						},
						OpCode
						{
							.Value = 0xf7,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M64},
							.Rm = {OperandType::M64},
							.Reg = {UINT64_C(0x7)},
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
				.IntelMnemonic = "imul",
				.GasMnemonic = "imulb",
				.Description = "imulb r8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::R8,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
					ImplicitRegisterOperand::Al,
				},
				.ImplicitOutputs =
				{
					ImplicitRegisterOperand::Ax,
				},
				.IsaFeatureExtensions =
				{
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
							.B = {OperandType::R8},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xf6,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R8},
							.Reg = {UINT64_C(0x5)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "imul",
				.GasMnemonic = "imulw",
				.Description = "imulw r16",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::R16,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
					ImplicitRegisterOperand::Ax,
				},
				.ImplicitOutputs =
				{
					ImplicitRegisterOperand::Dx,
					ImplicitRegisterOperand::Ax,
				},
				.IsaFeatureExtensions =
				{
				},
				.EncodingScheme =
				{
					Encoding
					{
						Prefix
						{
							.Value = 0x66,
							.IsMandatory = false,
						},
						Rex
						{
							.W = false,
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R16},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xf7,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R16},
							.Reg = {UINT64_C(0x5)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "imul",
				.GasMnemonic = "imull",
				.Description = "imull r32",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
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
					ImplicitRegisterOperand::Eax,
				},
				.ImplicitOutputs =
				{
					ImplicitRegisterOperand::Eax,
					ImplicitRegisterOperand::Edx,
				},
				.IsaFeatureExtensions =
				{
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
							.B = {OperandType::R32},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xf7,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R32},
							.Reg = {UINT64_C(0x5)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "imul",
				.GasMnemonic = "imulq",
				.Description = "imulq r64",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
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
					ImplicitRegisterOperand::Rax,
				},
				.ImplicitOutputs =
				{
					ImplicitRegisterOperand::Rdx,
					ImplicitRegisterOperand::Rax,
				},
				.IsaFeatureExtensions =
				{
				},
				.EncodingScheme =
				{
					Encoding
					{
						Rex
						{
							.W = true,
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R64},
							.IsMandatory = true,
						},
						OpCode
						{
							.Value = 0xf7,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R64},
							.Reg = {UINT64_C(0x5)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "imul",
				.GasMnemonic = "imulb",
				.Description = "imulb m8",
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
					ImplicitRegisterOperand::Al,
				},
				.ImplicitOutputs =
				{
					ImplicitRegisterOperand::Ax,
				},
				.IsaFeatureExtensions =
				{
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
							.Value = 0xf6,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M8},
							.Rm = {OperandType::M8},
							.Reg = {UINT64_C(0x5)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "imul",
				.GasMnemonic = "imulw",
				.Description = "imulw m16",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::M16,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
					ImplicitRegisterOperand::Ax,
				},
				.ImplicitOutputs =
				{
					ImplicitRegisterOperand::Dx,
					ImplicitRegisterOperand::Ax,
				},
				.IsaFeatureExtensions =
				{
				},
				.EncodingScheme =
				{
					Encoding
					{
						Prefix
						{
							.Value = 0x66,
							.IsMandatory = false,
						},
						Rex
						{
							.W = false,
							.R = {UINT64_C(0x0)},
							.X = {OperandType::M16},
							.B = {OperandType::M16},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xf7,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M16},
							.Rm = {OperandType::M16},
							.Reg = {UINT64_C(0x5)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "imul",
				.GasMnemonic = "imull",
				.Description = "imull m32",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
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
					ImplicitRegisterOperand::Eax,
				},
				.ImplicitOutputs =
				{
					ImplicitRegisterOperand::Eax,
					ImplicitRegisterOperand::Edx,
				},
				.IsaFeatureExtensions =
				{
				},
				.EncodingScheme =
				{
					Encoding
					{
						Rex
						{
							.W = false,
							.R = {UINT64_C(0x0)},
							.X = {OperandType::M32},
							.B = {OperandType::M32},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xf7,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M32},
							.Rm = {OperandType::M32},
							.Reg = {UINT64_C(0x5)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "imul",
				.GasMnemonic = "imulq",
				.Description = "imulq m64",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
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
					ImplicitRegisterOperand::Rax,
				},
				.ImplicitOutputs =
				{
					ImplicitRegisterOperand::Rdx,
					ImplicitRegisterOperand::Rax,
				},
				.IsaFeatureExtensions =
				{
				},
				.EncodingScheme =
				{
					Encoding
					{
						Rex
						{
							.W = true,
							.R = {UINT64_C(0x0)},
							.X = {OperandType::M64},
							.B = {OperandType::M64},
							.IsMandatory = true,
						},
						OpCode
						{
							.Value = 0xf7,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M64},
							.Rm = {OperandType::M64},
							.Reg = {UINT64_C(0x5)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "imul",
				.GasMnemonic = "imulw",
				.Description = "imulw r16, r16",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::R16,
						.IsInput = true,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::R16,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						Prefix
						{
							.Value = 0x66,
							.IsMandatory = false,
						},
						Rex
						{
							.W = false,
							.R = {OperandType::R16},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R16},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xf,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0xaf,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R16},
							.Reg = {OperandType::R16},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "imul",
				.GasMnemonic = "imulw",
				.Description = "imulw r16, m16",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::R16,
						.IsInput = true,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M16,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						Prefix
						{
							.Value = 0x66,
							.IsMandatory = false,
						},
						Rex
						{
							.W = false,
							.R = {OperandType::R16},
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
							.Value = 0xaf,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M16},
							.Rm = {OperandType::M16},
							.Reg = {OperandType::R16},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "imul",
				.GasMnemonic = "imull",
				.Description = "imull r32, r32",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::R32,
						.IsInput = true,
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
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
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
							.Value = 0xaf,
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
				.IntelMnemonic = "imul",
				.GasMnemonic = "imull",
				.Description = "imull r32, m32",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::R32,
						.IsInput = true,
						.IsOutput = true,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						Rex
						{
							.W = false,
							.R = {OperandType::R32},
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
							.Value = 0xaf,
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
				.IntelMnemonic = "imul",
				.GasMnemonic = "imulq",
				.Description = "imulq r64, r64",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::R64,
						.IsInput = true,
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
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
				},
				.EncodingScheme =
				{
					Encoding
					{
						Rex
						{
							.W = true,
							.R = {OperandType::R64},
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
							.Value = 0xaf,
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
				.IntelMnemonic = "imul",
				.GasMnemonic = "imulq",
				.Description = "imulq r64, m64",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::R64,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						Rex
						{
							.W = true,
							.R = {OperandType::R64},
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
							.Value = 0xaf,
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
			InstructionVariation
			{
				.IntelMnemonic = "imul",
				.GasMnemonic = "imulw",
				.Description = "imulw r16, r16, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::R16,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::R16,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 2
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						Prefix
						{
							.Value = 0x66,
							.IsMandatory = false,
						},
						Rex
						{
							.W = false,
							.R = {OperandType::R16},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R16},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0x6b,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R16},
							.Reg = {OperandType::R16},
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
				.IntelMnemonic = "imul",
				.GasMnemonic = "imulw",
				.Description = "imulw r16, r16, imm16",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::R16,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::R16,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Imm16,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						Prefix
						{
							.Value = 0x66,
							.IsMandatory = false,
						},
						Rex
						{
							.W = false,
							.R = {OperandType::R16},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R16},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0x69,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R16},
							.Reg = {OperandType::R16},
						},
						ImmediateScalar
						{
							.Size = 2,
							.Value = {OperandType::Imm16},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "imul",
				.GasMnemonic = "imulw",
				.Description = "imulw r16, m16, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::R16,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M16,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 2
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						Prefix
						{
							.Value = 0x66,
							.IsMandatory = false,
						},
						Rex
						{
							.W = false,
							.R = {OperandType::R16},
							.X = {OperandType::M16},
							.B = {OperandType::M16},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0x6b,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M16},
							.Rm = {OperandType::M16},
							.Reg = {OperandType::R16},
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
				.IntelMnemonic = "imul",
				.GasMnemonic = "imulw",
				.Description = "imulw r16, m16, imm16",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::R16,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M16,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Imm16,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						Prefix
						{
							.Value = 0x66,
							.IsMandatory = false,
						},
						Rex
						{
							.W = false,
							.R = {OperandType::R16},
							.X = {OperandType::M16},
							.B = {OperandType::M16},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0x69,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M16},
							.Rm = {OperandType::M16},
							.Reg = {OperandType::R16},
						},
						ImmediateScalar
						{
							.Size = 2,
							.Value = {OperandType::Imm16},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "imul",
				.GasMnemonic = "imull",
				.Description = "imull r32, r32, imm8",
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
						.ExtendedSize = 4
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
							.B = {OperandType::R32},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0x6b,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R32},
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
				.IntelMnemonic = "imul",
				.GasMnemonic = "imull",
				.Description = "imull r32, r32, imm32",
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
						.Type = OperandType::Imm32,
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
							.B = {OperandType::R32},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0x69,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R32},
							.Reg = {OperandType::R32},
						},
						ImmediateScalar
						{
							.Size = 4,
							.Value = {OperandType::Imm32},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "imul",
				.GasMnemonic = "imull",
				.Description = "imull r32, m32, imm8",
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
						.Type = OperandType::M32,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 4
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						Rex
						{
							.W = false,
							.R = {OperandType::R32},
							.X = {OperandType::M32},
							.B = {OperandType::M32},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0x6b,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M32},
							.Rm = {OperandType::M32},
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
				.IntelMnemonic = "imul",
				.GasMnemonic = "imull",
				.Description = "imull r32, m32, imm32",
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
						.Type = OperandType::M32,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Imm32,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						Rex
						{
							.W = false,
							.R = {OperandType::R32},
							.X = {OperandType::M32},
							.B = {OperandType::M32},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0x69,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M32},
							.Rm = {OperandType::M32},
							.Reg = {OperandType::R32},
						},
						ImmediateScalar
						{
							.Size = 4,
							.Value = {OperandType::Imm32},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "imul",
				.GasMnemonic = "imulq",
				.Description = "imulq r64, r64, imm8",
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
						.ExtendedSize = 8
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						Rex
						{
							.W = true,
							.R = {OperandType::R64},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R64},
							.IsMandatory = true,
						},
						OpCode
						{
							.Value = 0x6b,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R64},
							.Reg = {OperandType::R64},
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
				.IntelMnemonic = "imul",
				.GasMnemonic = "imulq",
				.Description = "imulq r64, r64, imm32",
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
						.ExtendedSize = 8
					},
					Operand
					{
						.Type = OperandType::Imm32,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						Rex
						{
							.W = true,
							.R = {OperandType::R64},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R64},
							.IsMandatory = true,
						},
						OpCode
						{
							.Value = 0x69,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R64},
							.Reg = {OperandType::R64},
						},
						ImmediateScalar
						{
							.Size = 4,
							.Value = {OperandType::Imm32},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "imul",
				.GasMnemonic = "imulq",
				.Description = "imulq r64, m64, imm8",
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
						.Type = OperandType::M64,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 8
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						Rex
						{
							.W = true,
							.R = {OperandType::R64},
							.X = {OperandType::M64},
							.B = {OperandType::M64},
							.IsMandatory = true,
						},
						OpCode
						{
							.Value = 0x6b,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M64},
							.Rm = {OperandType::M64},
							.Reg = {OperandType::R64},
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
				.IntelMnemonic = "imul",
				.GasMnemonic = "imulq",
				.Description = "imulq r64, m64, imm32",
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
						.Type = OperandType::M64,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 8
					},
					Operand
					{
						.Type = OperandType::Imm32,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						Rex
						{
							.W = true,
							.R = {OperandType::R64},
							.X = {OperandType::M64},
							.B = {OperandType::M64},
							.IsMandatory = true,
						},
						OpCode
						{
							.Value = 0x69,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M64},
							.Rm = {OperandType::M64},
							.Reg = {OperandType::R64},
						},
						ImmediateScalar
						{
							.Size = 4,
							.Value = {OperandType::Imm32},
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
				.IntelMnemonic = "inc",
				.GasMnemonic = "incb",
				.Description = "incb r8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::R8,
						.IsInput = true,
						.IsOutput = true,
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
							.B = {OperandType::R8},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xfe,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R8},
							.Reg = {UINT64_C(0x0)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "inc",
				.GasMnemonic = "incw",
				.Description = "incw r16",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::R16,
						.IsInput = true,
						.IsOutput = true,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						Prefix
						{
							.Value = 0x66,
							.IsMandatory = false,
						},
						Rex
						{
							.W = false,
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R16},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xff,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R16},
							.Reg = {UINT64_C(0x0)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "inc",
				.GasMnemonic = "incl",
				.Description = "incl r32",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::R32,
						.IsInput = true,
						.IsOutput = true,
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
							.B = {OperandType::R32},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xff,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R32},
							.Reg = {UINT64_C(0x0)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "inc",
				.GasMnemonic = "incq",
				.Description = "incq r64",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::R64,
						.IsInput = true,
						.IsOutput = true,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						Rex
						{
							.W = true,
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R64},
							.IsMandatory = true,
						},
						OpCode
						{
							.Value = 0xff,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R64},
							.Reg = {UINT64_C(0x0)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "inc",
				.GasMnemonic = "incb",
				.Description = "incb m8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::M8,
						.IsInput = true,
						.IsOutput = true,
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
							.Value = 0xfe,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M8},
							.Rm = {OperandType::M8},
							.Reg = {UINT64_C(0x0)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "inc",
				.GasMnemonic = "incw",
				.Description = "incw m16",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::M16,
						.IsInput = true,
						.IsOutput = true,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						Prefix
						{
							.Value = 0x66,
							.IsMandatory = false,
						},
						Rex
						{
							.W = false,
							.R = {UINT64_C(0x0)},
							.X = {OperandType::M16},
							.B = {OperandType::M16},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xff,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M16},
							.Rm = {OperandType::M16},
							.Reg = {UINT64_C(0x0)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "inc",
				.GasMnemonic = "incl",
				.Description = "incl m32",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::M32,
						.IsInput = true,
						.IsOutput = true,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						Rex
						{
							.W = false,
							.R = {UINT64_C(0x0)},
							.X = {OperandType::M32},
							.B = {OperandType::M32},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xff,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M32},
							.Rm = {OperandType::M32},
							.Reg = {UINT64_C(0x0)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "inc",
				.GasMnemonic = "incq",
				.Description = "incq m64",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::M64,
						.IsInput = true,
						.IsOutput = true,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						Rex
						{
							.W = true,
							.R = {UINT64_C(0x0)},
							.X = {OperandType::M64},
							.B = {OperandType::M64},
							.IsMandatory = true,
						},
						OpCode
						{
							.Value = 0xff,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M64},
							.Rm = {OperandType::M64},
							.Reg = {UINT64_C(0x0)},
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
				.IntelMnemonic = "insertps",
				.GasMnemonic = "insertps",
				.Description = "insertps xmm, xmm, imm8",
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
							.Value = 0x21,
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
				.IntelMnemonic = "insertps",
				.GasMnemonic = "insertps",
				.Description = "insertps xmm, m32, imm8",
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
						.Type = OperandType::M32,
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
							.Value = 0x21,
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
				.IntelMnemonic = "insertq",
				.GasMnemonic = "insertq",
				.Description = "insertq xmm, xmm",
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
					IsaExtension::Sse4A,
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
							.Value = 0x79,
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
				.IntelMnemonic = "insertq",
				.GasMnemonic = "insertq",
				.Description = "insertq xmm, xmm, imm8, imm8",
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
					IsaExtension::Sse4A,
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
							.Value = 0x78,
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
				.IntelMnemonic = "int",
				.GasMnemonic = "int",
				.Description = "int 3",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ScalarThree,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						OpCode
						{
							.Value = 0xcc,
							.Addend = {UINT64_C(0x0)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "int",
				.GasMnemonic = "int",
				.Description = "int imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						OpCode
						{
							.Value = 0xcd,
							.Addend = {UINT64_C(0x0)},
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
				.IntelMnemonic = "ja",
				.GasMnemonic = "ja",
				.Description = "ja rel8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Rel8,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						OpCode
						{
							.Value = 0x77,
							.Addend = {UINT64_C(0x0)},
						},
						CodeOffset
						{
							.Size = 1,
							.Value = OperandType::Rel8,
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "ja",
				.GasMnemonic = "ja",
				.Description = "ja rel32",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Rel32,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						OpCode
						{
							.Value = 0xf,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x87,
							.Addend = {UINT64_C(0x0)},
						},
						CodeOffset
						{
							.Size = 4,
							.Value = OperandType::Rel32,
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
				.IntelMnemonic = "jae",
				.GasMnemonic = "jae",
				.Description = "jae rel8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Rel8,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						OpCode
						{
							.Value = 0x73,
							.Addend = {UINT64_C(0x0)},
						},
						CodeOffset
						{
							.Size = 1,
							.Value = OperandType::Rel8,
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "jae",
				.GasMnemonic = "jae",
				.Description = "jae rel32",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Rel32,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						OpCode
						{
							.Value = 0xf,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x83,
							.Addend = {UINT64_C(0x0)},
						},
						CodeOffset
						{
							.Size = 4,
							.Value = OperandType::Rel32,
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
				.IntelMnemonic = "jb",
				.GasMnemonic = "jb",
				.Description = "jb rel8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Rel8,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						OpCode
						{
							.Value = 0x72,
							.Addend = {UINT64_C(0x0)},
						},
						CodeOffset
						{
							.Size = 1,
							.Value = OperandType::Rel8,
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "jb",
				.GasMnemonic = "jb",
				.Description = "jb rel32",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Rel32,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						OpCode
						{
							.Value = 0xf,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x82,
							.Addend = {UINT64_C(0x0)},
						},
						CodeOffset
						{
							.Size = 4,
							.Value = OperandType::Rel32,
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
				.IntelMnemonic = "jbe",
				.GasMnemonic = "jbe",
				.Description = "jbe rel8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Rel8,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						OpCode
						{
							.Value = 0x76,
							.Addend = {UINT64_C(0x0)},
						},
						CodeOffset
						{
							.Size = 1,
							.Value = OperandType::Rel8,
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "jbe",
				.GasMnemonic = "jbe",
				.Description = "jbe rel32",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Rel32,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						OpCode
						{
							.Value = 0xf,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x86,
							.Addend = {UINT64_C(0x0)},
						},
						CodeOffset
						{
							.Size = 4,
							.Value = OperandType::Rel32,
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
				.IntelMnemonic = "jc",
				.GasMnemonic = "jc",
				.Description = "jc rel8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Rel8,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						OpCode
						{
							.Value = 0x72,
							.Addend = {UINT64_C(0x0)},
						},
						CodeOffset
						{
							.Size = 1,
							.Value = OperandType::Rel8,
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "jc",
				.GasMnemonic = "jc",
				.Description = "jc rel32",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Rel32,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						OpCode
						{
							.Value = 0xf,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x82,
							.Addend = {UINT64_C(0x0)},
						},
						CodeOffset
						{
							.Size = 4,
							.Value = OperandType::Rel32,
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
				.IntelMnemonic = "je",
				.GasMnemonic = "je",
				.Description = "je rel8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Rel8,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						OpCode
						{
							.Value = 0x74,
							.Addend = {UINT64_C(0x0)},
						},
						CodeOffset
						{
							.Size = 1,
							.Value = OperandType::Rel8,
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "je",
				.GasMnemonic = "je",
				.Description = "je rel32",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Rel32,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						OpCode
						{
							.Value = 0xf,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x84,
							.Addend = {UINT64_C(0x0)},
						},
						CodeOffset
						{
							.Size = 4,
							.Value = OperandType::Rel32,
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
				.IntelMnemonic = "jecxz",
				.GasMnemonic = "jecxz",
				.Description = "jecxz rel8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Rel8,
						.IsInput = false,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
					ImplicitRegisterOperand::Ecx,
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
				},
				.EncodingScheme =
				{
					Encoding
					{
						OpCode
						{
							.Value = 0xe3,
							.Addend = {UINT64_C(0x0)},
						},
						CodeOffset
						{
							.Size = 1,
							.Value = OperandType::Rel8,
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
				.IntelMnemonic = "jg",
				.GasMnemonic = "jg",
				.Description = "jg rel8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Rel8,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						OpCode
						{
							.Value = 0x7f,
							.Addend = {UINT64_C(0x0)},
						},
						CodeOffset
						{
							.Size = 1,
							.Value = OperandType::Rel8,
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "jg",
				.GasMnemonic = "jg",
				.Description = "jg rel32",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Rel32,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						OpCode
						{
							.Value = 0xf,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x8f,
							.Addend = {UINT64_C(0x0)},
						},
						CodeOffset
						{
							.Size = 4,
							.Value = OperandType::Rel32,
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
				.IntelMnemonic = "jge",
				.GasMnemonic = "jge",
				.Description = "jge rel8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Rel8,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						OpCode
						{
							.Value = 0x7d,
							.Addend = {UINT64_C(0x0)},
						},
						CodeOffset
						{
							.Size = 1,
							.Value = OperandType::Rel8,
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "jge",
				.GasMnemonic = "jge",
				.Description = "jge rel32",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Rel32,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						OpCode
						{
							.Value = 0xf,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x8d,
							.Addend = {UINT64_C(0x0)},
						},
						CodeOffset
						{
							.Size = 4,
							.Value = OperandType::Rel32,
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
				.IntelMnemonic = "jl",
				.GasMnemonic = "jl",
				.Description = "jl rel8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Rel8,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						OpCode
						{
							.Value = 0x7c,
							.Addend = {UINT64_C(0x0)},
						},
						CodeOffset
						{
							.Size = 1,
							.Value = OperandType::Rel8,
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "jl",
				.GasMnemonic = "jl",
				.Description = "jl rel32",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Rel32,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						OpCode
						{
							.Value = 0xf,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x8c,
							.Addend = {UINT64_C(0x0)},
						},
						CodeOffset
						{
							.Size = 4,
							.Value = OperandType::Rel32,
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
				.IntelMnemonic = "jle",
				.GasMnemonic = "jle",
				.Description = "jle rel8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Rel8,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						OpCode
						{
							.Value = 0x7e,
							.Addend = {UINT64_C(0x0)},
						},
						CodeOffset
						{
							.Size = 1,
							.Value = OperandType::Rel8,
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "jle",
				.GasMnemonic = "jle",
				.Description = "jle rel32",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Rel32,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						OpCode
						{
							.Value = 0xf,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x8e,
							.Addend = {UINT64_C(0x0)},
						},
						CodeOffset
						{
							.Size = 4,
							.Value = OperandType::Rel32,
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
				.IntelMnemonic = "jmp",
				.GasMnemonic = "jmp",
				.Description = "jmp rel8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Rel8,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						OpCode
						{
							.Value = 0xeb,
							.Addend = {UINT64_C(0x0)},
						},
						CodeOffset
						{
							.Size = 1,
							.Value = OperandType::Rel8,
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "jmp",
				.GasMnemonic = "jmp",
				.Description = "jmp rel32",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Rel32,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						OpCode
						{
							.Value = 0xe9,
							.Addend = {UINT64_C(0x0)},
						},
						CodeOffset
						{
							.Size = 4,
							.Value = OperandType::Rel32,
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "jmp",
				.GasMnemonic = "jmpq",
				.Description = "jmpq r64",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
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
							.B = {OperandType::R64},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xff,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R64},
							.Reg = {UINT64_C(0x4)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "jmp",
				.GasMnemonic = "jmpq",
				.Description = "jmpq m64",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						Rex
						{
							.W = false,
							.R = {UINT64_C(0x0)},
							.X = {OperandType::M64},
							.B = {OperandType::M64},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xff,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M64},
							.Rm = {OperandType::M64},
							.Reg = {UINT64_C(0x4)},
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
				.IntelMnemonic = "jna",
				.GasMnemonic = "jna",
				.Description = "jna rel8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Rel8,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						OpCode
						{
							.Value = 0x76,
							.Addend = {UINT64_C(0x0)},
						},
						CodeOffset
						{
							.Size = 1,
							.Value = OperandType::Rel8,
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "jna",
				.GasMnemonic = "jna",
				.Description = "jna rel32",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Rel32,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						OpCode
						{
							.Value = 0xf,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x86,
							.Addend = {UINT64_C(0x0)},
						},
						CodeOffset
						{
							.Size = 4,
							.Value = OperandType::Rel32,
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
				.IntelMnemonic = "jnae",
				.GasMnemonic = "jnae",
				.Description = "jnae rel8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Rel8,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						OpCode
						{
							.Value = 0x72,
							.Addend = {UINT64_C(0x0)},
						},
						CodeOffset
						{
							.Size = 1,
							.Value = OperandType::Rel8,
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "jnae",
				.GasMnemonic = "jnae",
				.Description = "jnae rel32",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Rel32,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						OpCode
						{
							.Value = 0xf,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x82,
							.Addend = {UINT64_C(0x0)},
						},
						CodeOffset
						{
							.Size = 4,
							.Value = OperandType::Rel32,
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
				.IntelMnemonic = "jnb",
				.GasMnemonic = "jnb",
				.Description = "jnb rel8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Rel8,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						OpCode
						{
							.Value = 0x73,
							.Addend = {UINT64_C(0x0)},
						},
						CodeOffset
						{
							.Size = 1,
							.Value = OperandType::Rel8,
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "jnb",
				.GasMnemonic = "jnb",
				.Description = "jnb rel32",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Rel32,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						OpCode
						{
							.Value = 0xf,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x83,
							.Addend = {UINT64_C(0x0)},
						},
						CodeOffset
						{
							.Size = 4,
							.Value = OperandType::Rel32,
						},
					},
				}
			},
		};
		out.emplace_back(std::move(instruction));
	};
}
