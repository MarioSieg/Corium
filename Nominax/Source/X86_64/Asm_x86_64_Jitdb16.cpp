// File: Asm_x86_64_Jitdb16.cpp
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

#include "../../Include/Nominax/Assembler/_Assembler.hpp"

namespace Nominax::Assembler::X86_64
{
	NOX_NEVER_INLINE NOX_COLD auto GetVariationTable_16(std::pmr::monotonic_buffer_resource& allocator, std::pmr::vector<InstructionVariationPool>& out) -> void
	{
		std::pmr::vector<InstructionVariation> instruction {&allocator};
		instruction =
		{
			InstructionVariation
			{
				.IntelMnemonic = "sha1nexte",
				.GasMnemonic = "sha1nexte",
				.Description = "sha1nexte xmm, xmm",
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
					IsaExtension::Sha,
				},
				.EncodingScheme =
				{
					Encoding
					{
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
							.Value = 0xc8,
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
				.IntelMnemonic = "sha1nexte",
				.GasMnemonic = "sha1nexte",
				.Description = "sha1nexte xmm, m128",
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
					IsaExtension::Sha,
				},
				.EncodingScheme =
				{
					Encoding
					{
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
							.Value = 0xc8,
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
				.IntelMnemonic = "sha1rnds4",
				.GasMnemonic = "sha1rnds4",
				.Description = "sha1rnds4 xmm, xmm, imm8",
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
					IsaExtension::Sha,
				},
				.EncodingScheme =
				{
					Encoding
					{
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
							.Value = 0xcc,
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
				.IntelMnemonic = "sha1rnds4",
				.GasMnemonic = "sha1rnds4",
				.Description = "sha1rnds4 xmm, m128, imm8",
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
					IsaExtension::Sha,
				},
				.EncodingScheme =
				{
					Encoding
					{
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
							.Value = 0xcc,
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
				.IntelMnemonic = "sha256msg1",
				.GasMnemonic = "sha256msg1",
				.Description = "sha256msg1 xmm, xmm",
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
					IsaExtension::Sha,
				},
				.EncodingScheme =
				{
					Encoding
					{
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
							.Value = 0xcc,
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
				.IntelMnemonic = "sha256msg1",
				.GasMnemonic = "sha256msg1",
				.Description = "sha256msg1 xmm, m128",
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
					IsaExtension::Sha,
				},
				.EncodingScheme =
				{
					Encoding
					{
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
							.Value = 0xcc,
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
				.IntelMnemonic = "sha256msg2",
				.GasMnemonic = "sha256msg2",
				.Description = "sha256msg2 xmm, xmm",
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
					IsaExtension::Sha,
				},
				.EncodingScheme =
				{
					Encoding
					{
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
							.Value = 0xcd,
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
				.IntelMnemonic = "sha256msg2",
				.GasMnemonic = "sha256msg2",
				.Description = "sha256msg2 xmm, m128",
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
					IsaExtension::Sha,
				},
				.EncodingScheme =
				{
					Encoding
					{
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
							.Value = 0xcd,
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
				.IntelMnemonic = "sha256rnds2",
				.GasMnemonic = "sha256rnds2",
				.Description = "sha256rnds2 xmm, xmm, xmm0",
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
					IsaExtension::Sha,
				},
				.EncodingScheme =
				{
					Encoding
					{
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
							.Value = 0xcb,
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
				.IntelMnemonic = "sha256rnds2",
				.GasMnemonic = "sha256rnds2",
				.Description = "sha256rnds2 xmm, m128, xmm0",
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
					IsaExtension::Sha,
				},
				.EncodingScheme =
				{
					Encoding
					{
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
							.Value = 0xcb,
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
				.IntelMnemonic = "shl",
				.GasMnemonic = "shlb",
				.Description = "shlb r8, 1",
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
					Operand
					{
						.Type = OperandType::ScalarOne,
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
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R8},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xd0,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R8},
							.Reg = {UINT64_C(0x4)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "shl",
				.GasMnemonic = "shlb",
				.Description = "shlb r8, imm8",
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
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R8},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xc0,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R8},
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
				.IntelMnemonic = "shl",
				.GasMnemonic = "shlb",
				.Description = "shlb r8, cl",
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
					Operand
					{
						.Type = OperandType::Cl,
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
							.B = {OperandType::R8},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xd2,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R8},
							.Reg = {UINT64_C(0x4)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "shl",
				.GasMnemonic = "shlw",
				.Description = "shlw r16, 1",
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
						.Type = OperandType::ScalarOne,
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
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R16},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xd1,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R16},
							.Reg = {UINT64_C(0x4)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "shl",
				.GasMnemonic = "shlw",
				.Description = "shlw r16, imm8",
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
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R16},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xc1,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R16},
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
				.IntelMnemonic = "shl",
				.GasMnemonic = "shlw",
				.Description = "shlw r16, cl",
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
						.Type = OperandType::Cl,
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
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R16},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xd3,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R16},
							.Reg = {UINT64_C(0x4)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "shl",
				.GasMnemonic = "shll",
				.Description = "shll r32, 1",
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
						.Type = OperandType::ScalarOne,
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
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R32},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xd1,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R32},
							.Reg = {UINT64_C(0x4)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "shl",
				.GasMnemonic = "shll",
				.Description = "shll r32, imm8",
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
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R32},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xc1,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R32},
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
				.IntelMnemonic = "shl",
				.GasMnemonic = "shll",
				.Description = "shll r32, cl",
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
						.Type = OperandType::Cl,
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
							.B = {OperandType::R32},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xd3,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R32},
							.Reg = {UINT64_C(0x4)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "shl",
				.GasMnemonic = "shlq",
				.Description = "shlq r64, 1",
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
						.Type = OperandType::ScalarOne,
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
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R64},
							.IsMandatory = true,
						},
						OpCode
						{
							.Value = 0xd1,
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
				.IntelMnemonic = "shl",
				.GasMnemonic = "shlq",
				.Description = "shlq r64, imm8",
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
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R64},
							.IsMandatory = true,
						},
						OpCode
						{
							.Value = 0xc1,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R64},
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
				.IntelMnemonic = "shl",
				.GasMnemonic = "shlq",
				.Description = "shlq r64, cl",
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
						.Type = OperandType::Cl,
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
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R64},
							.IsMandatory = true,
						},
						OpCode
						{
							.Value = 0xd3,
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
				.IntelMnemonic = "shl",
				.GasMnemonic = "shlb",
				.Description = "shlb m8, 1",
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
					Operand
					{
						.Type = OperandType::ScalarOne,
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
							.R = {UINT64_C(0x0)},
							.X = {OperandType::M8},
							.B = {OperandType::M8},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xd0,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M8},
							.Rm = {OperandType::M8},
							.Reg = {UINT64_C(0x4)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "shl",
				.GasMnemonic = "shlb",
				.Description = "shlb m8, imm8",
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
							.R = {UINT64_C(0x0)},
							.X = {OperandType::M8},
							.B = {OperandType::M8},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xc0,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M8},
							.Rm = {OperandType::M8},
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
				.IntelMnemonic = "shl",
				.GasMnemonic = "shlb",
				.Description = "shlb m8, cl",
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
					Operand
					{
						.Type = OperandType::Cl,
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
							.X = {OperandType::M8},
							.B = {OperandType::M8},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xd2,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M8},
							.Rm = {OperandType::M8},
							.Reg = {UINT64_C(0x4)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "shl",
				.GasMnemonic = "shlw",
				.Description = "shlw m16, 1",
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
					Operand
					{
						.Type = OperandType::ScalarOne,
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
							.R = {UINT64_C(0x0)},
							.X = {OperandType::M16},
							.B = {OperandType::M16},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xd1,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M16},
							.Rm = {OperandType::M16},
							.Reg = {UINT64_C(0x4)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "shl",
				.GasMnemonic = "shlw",
				.Description = "shlw m16, imm8",
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
							.R = {UINT64_C(0x0)},
							.X = {OperandType::M16},
							.B = {OperandType::M16},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xc1,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M16},
							.Rm = {OperandType::M16},
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
				.IntelMnemonic = "shl",
				.GasMnemonic = "shlw",
				.Description = "shlw m16, cl",
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
					Operand
					{
						.Type = OperandType::Cl,
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
							.R = {UINT64_C(0x0)},
							.X = {OperandType::M16},
							.B = {OperandType::M16},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xd3,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M16},
							.Rm = {OperandType::M16},
							.Reg = {UINT64_C(0x4)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "shl",
				.GasMnemonic = "shll",
				.Description = "shll m32, 1",
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
					Operand
					{
						.Type = OperandType::ScalarOne,
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
							.R = {UINT64_C(0x0)},
							.X = {OperandType::M32},
							.B = {OperandType::M32},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xd1,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M32},
							.Rm = {OperandType::M32},
							.Reg = {UINT64_C(0x4)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "shl",
				.GasMnemonic = "shll",
				.Description = "shll m32, imm8",
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
							.R = {UINT64_C(0x0)},
							.X = {OperandType::M32},
							.B = {OperandType::M32},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xc1,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M32},
							.Rm = {OperandType::M32},
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
				.IntelMnemonic = "shl",
				.GasMnemonic = "shll",
				.Description = "shll m32, cl",
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
					Operand
					{
						.Type = OperandType::Cl,
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
							.X = {OperandType::M32},
							.B = {OperandType::M32},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xd3,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M32},
							.Rm = {OperandType::M32},
							.Reg = {UINT64_C(0x4)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "shl",
				.GasMnemonic = "shlq",
				.Description = "shlq m64, 1",
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
					Operand
					{
						.Type = OperandType::ScalarOne,
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
							.R = {UINT64_C(0x0)},
							.X = {OperandType::M64},
							.B = {OperandType::M64},
							.IsMandatory = true,
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
							.Reg = {UINT64_C(0x4)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "shl",
				.GasMnemonic = "shlq",
				.Description = "shlq m64, imm8",
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
							.R = {UINT64_C(0x0)},
							.X = {OperandType::M64},
							.B = {OperandType::M64},
							.IsMandatory = true,
						},
						OpCode
						{
							.Value = 0xc1,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M64},
							.Rm = {OperandType::M64},
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
				.IntelMnemonic = "shl",
				.GasMnemonic = "shlq",
				.Description = "shlq m64, cl",
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
					Operand
					{
						.Type = OperandType::Cl,
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
							.R = {UINT64_C(0x0)},
							.X = {OperandType::M64},
							.B = {OperandType::M64},
							.IsMandatory = true,
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
				.IntelMnemonic = "shld",
				.GasMnemonic = "shldw",
				.Description = "shldw r16, r16, imm8",
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
							.Value = 0xf,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0xa4,
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
				.IntelMnemonic = "shld",
				.GasMnemonic = "shldw",
				.Description = "shldw r16, r16, cl",
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
					Operand
					{
						.Type = OperandType::Cl,
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
							.Value = 0xa5,
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
				.IntelMnemonic = "shld",
				.GasMnemonic = "shldl",
				.Description = "shldl r32, r32, imm8",
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
							.Value = 0xf,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0xa4,
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
				.IntelMnemonic = "shld",
				.GasMnemonic = "shldl",
				.Description = "shldl r32, r32, cl",
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
					Operand
					{
						.Type = OperandType::Cl,
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
							.Value = 0xa5,
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
				.IntelMnemonic = "shld",
				.GasMnemonic = "shldq",
				.Description = "shldq r64, r64, imm8",
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
							.Value = 0xf,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0xa4,
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
				.IntelMnemonic = "shld",
				.GasMnemonic = "shldq",
				.Description = "shldq r64, r64, cl",
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
					Operand
					{
						.Type = OperandType::Cl,
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
							.Value = 0xa5,
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
				.IntelMnemonic = "shld",
				.GasMnemonic = "shldw",
				.Description = "shldw m16, r16, imm8",
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
					Operand
					{
						.Type = OperandType::R16,
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
							.Value = 0xa4,
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
				.IntelMnemonic = "shld",
				.GasMnemonic = "shldw",
				.Description = "shldw m16, r16, cl",
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
					Operand
					{
						.Type = OperandType::R16,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Cl,
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
							.Value = 0xa5,
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
				.IntelMnemonic = "shld",
				.GasMnemonic = "shldl",
				.Description = "shldl m32, r32, imm8",
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
					Operand
					{
						.Type = OperandType::R32,
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
							.Value = 0xa4,
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
				.IntelMnemonic = "shld",
				.GasMnemonic = "shldl",
				.Description = "shldl m32, r32, cl",
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
					Operand
					{
						.Type = OperandType::R32,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Cl,
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
							.Value = 0xa5,
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
				.IntelMnemonic = "shld",
				.GasMnemonic = "shldq",
				.Description = "shldq m64, r64, imm8",
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
					Operand
					{
						.Type = OperandType::R64,
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
							.Value = 0xa4,
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
				.IntelMnemonic = "shld",
				.GasMnemonic = "shldq",
				.Description = "shldq m64, r64, cl",
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
					Operand
					{
						.Type = OperandType::R64,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Cl,
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
							.Value = 0xa5,
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
				.IntelMnemonic = "shlx",
				.GasMnemonic = "shlxl",
				.Description = "shlxl r32, r32, r32",
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
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {OperandType::R32},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R32},
							.Vvvv = {OperandType::R32},
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
							.Reg = {OperandType::R32},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "shlx",
				.GasMnemonic = "shlxl",
				.Description = "shlxl r32, m32, r32",
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
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {OperandType::R32},
							.X = {OperandType::M32},
							.B = {OperandType::M32},
							.Vvvv = {OperandType::R32},
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
							.Reg = {OperandType::R32},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "shlx",
				.GasMnemonic = "shlxq",
				.Description = "shlxq r64, r64, r64",
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
							.Pp = 0b1,
							.W = true,
							.L = false,
							.R = {OperandType::R64},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R64},
							.Vvvv = {OperandType::R64},
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
							.Reg = {OperandType::R64},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "shlx",
				.GasMnemonic = "shlxq",
				.Description = "shlxq r64, m64, r64",
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
							.Pp = 0b1,
							.W = true,
							.L = false,
							.R = {OperandType::R64},
							.X = {OperandType::M64},
							.B = {OperandType::M64},
							.Vvvv = {OperandType::R64},
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
				.IntelMnemonic = "shr",
				.GasMnemonic = "shrb",
				.Description = "shrb r8, 1",
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
					Operand
					{
						.Type = OperandType::ScalarOne,
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
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R8},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xd0,
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
				.IntelMnemonic = "shr",
				.GasMnemonic = "shrb",
				.Description = "shrb r8, imm8",
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
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R8},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xc0,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R8},
							.Reg = {UINT64_C(0x5)},
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
				.IntelMnemonic = "shr",
				.GasMnemonic = "shrb",
				.Description = "shrb r8, cl",
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
					Operand
					{
						.Type = OperandType::Cl,
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
							.B = {OperandType::R8},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xd2,
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
				.IntelMnemonic = "shr",
				.GasMnemonic = "shrw",
				.Description = "shrw r16, 1",
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
						.Type = OperandType::ScalarOne,
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
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R16},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xd1,
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
				.IntelMnemonic = "shr",
				.GasMnemonic = "shrw",
				.Description = "shrw r16, imm8",
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
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R16},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xc1,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R16},
							.Reg = {UINT64_C(0x5)},
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
				.IntelMnemonic = "shr",
				.GasMnemonic = "shrw",
				.Description = "shrw r16, cl",
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
						.Type = OperandType::Cl,
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
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R16},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xd3,
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
				.IntelMnemonic = "shr",
				.GasMnemonic = "shrl",
				.Description = "shrl r32, 1",
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
						.Type = OperandType::ScalarOne,
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
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R32},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xd1,
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
				.IntelMnemonic = "shr",
				.GasMnemonic = "shrl",
				.Description = "shrl r32, imm8",
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
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R32},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xc1,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R32},
							.Reg = {UINT64_C(0x5)},
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
				.IntelMnemonic = "shr",
				.GasMnemonic = "shrl",
				.Description = "shrl r32, cl",
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
						.Type = OperandType::Cl,
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
							.B = {OperandType::R32},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xd3,
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
				.IntelMnemonic = "shr",
				.GasMnemonic = "shrq",
				.Description = "shrq r64, 1",
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
						.Type = OperandType::ScalarOne,
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
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R64},
							.IsMandatory = true,
						},
						OpCode
						{
							.Value = 0xd1,
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
				.IntelMnemonic = "shr",
				.GasMnemonic = "shrq",
				.Description = "shrq r64, imm8",
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
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R64},
							.IsMandatory = true,
						},
						OpCode
						{
							.Value = 0xc1,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R64},
							.Reg = {UINT64_C(0x5)},
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
				.IntelMnemonic = "shr",
				.GasMnemonic = "shrq",
				.Description = "shrq r64, cl",
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
						.Type = OperandType::Cl,
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
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R64},
							.IsMandatory = true,
						},
						OpCode
						{
							.Value = 0xd3,
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
				.IntelMnemonic = "shr",
				.GasMnemonic = "shrb",
				.Description = "shrb m8, 1",
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
					Operand
					{
						.Type = OperandType::ScalarOne,
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
							.R = {UINT64_C(0x0)},
							.X = {OperandType::M8},
							.B = {OperandType::M8},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xd0,
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
				.IntelMnemonic = "shr",
				.GasMnemonic = "shrb",
				.Description = "shrb m8, imm8",
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
							.R = {UINT64_C(0x0)},
							.X = {OperandType::M8},
							.B = {OperandType::M8},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xc0,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M8},
							.Rm = {OperandType::M8},
							.Reg = {UINT64_C(0x5)},
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
				.IntelMnemonic = "shr",
				.GasMnemonic = "shrb",
				.Description = "shrb m8, cl",
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
					Operand
					{
						.Type = OperandType::Cl,
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
							.X = {OperandType::M8},
							.B = {OperandType::M8},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xd2,
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
				.IntelMnemonic = "shr",
				.GasMnemonic = "shrw",
				.Description = "shrw m16, 1",
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
					Operand
					{
						.Type = OperandType::ScalarOne,
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
							.R = {UINT64_C(0x0)},
							.X = {OperandType::M16},
							.B = {OperandType::M16},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xd1,
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
				.IntelMnemonic = "shr",
				.GasMnemonic = "shrw",
				.Description = "shrw m16, imm8",
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
							.R = {UINT64_C(0x0)},
							.X = {OperandType::M16},
							.B = {OperandType::M16},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xc1,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M16},
							.Rm = {OperandType::M16},
							.Reg = {UINT64_C(0x5)},
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
				.IntelMnemonic = "shr",
				.GasMnemonic = "shrw",
				.Description = "shrw m16, cl",
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
					Operand
					{
						.Type = OperandType::Cl,
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
							.R = {UINT64_C(0x0)},
							.X = {OperandType::M16},
							.B = {OperandType::M16},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xd3,
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
				.IntelMnemonic = "shr",
				.GasMnemonic = "shrl",
				.Description = "shrl m32, 1",
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
					Operand
					{
						.Type = OperandType::ScalarOne,
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
							.R = {UINT64_C(0x0)},
							.X = {OperandType::M32},
							.B = {OperandType::M32},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xd1,
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
				.IntelMnemonic = "shr",
				.GasMnemonic = "shrl",
				.Description = "shrl m32, imm8",
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
							.R = {UINT64_C(0x0)},
							.X = {OperandType::M32},
							.B = {OperandType::M32},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xc1,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M32},
							.Rm = {OperandType::M32},
							.Reg = {UINT64_C(0x5)},
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
				.IntelMnemonic = "shr",
				.GasMnemonic = "shrl",
				.Description = "shrl m32, cl",
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
					Operand
					{
						.Type = OperandType::Cl,
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
							.X = {OperandType::M32},
							.B = {OperandType::M32},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0xd3,
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
				.IntelMnemonic = "shr",
				.GasMnemonic = "shrq",
				.Description = "shrq m64, 1",
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
					Operand
					{
						.Type = OperandType::ScalarOne,
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
							.R = {UINT64_C(0x0)},
							.X = {OperandType::M64},
							.B = {OperandType::M64},
							.IsMandatory = true,
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
							.Reg = {UINT64_C(0x5)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "shr",
				.GasMnemonic = "shrq",
				.Description = "shrq m64, imm8",
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
							.R = {UINT64_C(0x0)},
							.X = {OperandType::M64},
							.B = {OperandType::M64},
							.IsMandatory = true,
						},
						OpCode
						{
							.Value = 0xc1,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M64},
							.Rm = {OperandType::M64},
							.Reg = {UINT64_C(0x5)},
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
				.IntelMnemonic = "shr",
				.GasMnemonic = "shrq",
				.Description = "shrq m64, cl",
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
					Operand
					{
						.Type = OperandType::Cl,
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
							.R = {UINT64_C(0x0)},
							.X = {OperandType::M64},
							.B = {OperandType::M64},
							.IsMandatory = true,
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
							.Reg = {UINT64_C(0x5)},
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
				.IntelMnemonic = "shrd",
				.GasMnemonic = "shrdw",
				.Description = "shrdw r16, r16, imm8",
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
							.Value = 0xf,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0xac,
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
				.IntelMnemonic = "shrd",
				.GasMnemonic = "shrdw",
				.Description = "shrdw r16, r16, cl",
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
					Operand
					{
						.Type = OperandType::Cl,
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
							.Value = 0xad,
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
				.IntelMnemonic = "shrd",
				.GasMnemonic = "shrdl",
				.Description = "shrdl r32, r32, imm8",
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
							.Value = 0xf,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0xac,
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
				.IntelMnemonic = "shrd",
				.GasMnemonic = "shrdl",
				.Description = "shrdl r32, r32, cl",
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
					Operand
					{
						.Type = OperandType::Cl,
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
							.Value = 0xad,
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
				.IntelMnemonic = "shrd",
				.GasMnemonic = "shrdq",
				.Description = "shrdq r64, r64, imm8",
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
							.Value = 0xf,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0xac,
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
				.IntelMnemonic = "shrd",
				.GasMnemonic = "shrdq",
				.Description = "shrdq r64, r64, cl",
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
					Operand
					{
						.Type = OperandType::Cl,
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
							.Value = 0xad,
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
				.IntelMnemonic = "shrd",
				.GasMnemonic = "shrdw",
				.Description = "shrdw m16, r16, imm8",
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
					Operand
					{
						.Type = OperandType::R16,
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
							.Value = 0xac,
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
				.IntelMnemonic = "shrd",
				.GasMnemonic = "shrdw",
				.Description = "shrdw m16, r16, cl",
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
					Operand
					{
						.Type = OperandType::R16,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Cl,
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
							.Value = 0xad,
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
				.IntelMnemonic = "shrd",
				.GasMnemonic = "shrdl",
				.Description = "shrdl m32, r32, imm8",
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
					Operand
					{
						.Type = OperandType::R32,
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
							.Value = 0xac,
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
				.IntelMnemonic = "shrd",
				.GasMnemonic = "shrdl",
				.Description = "shrdl m32, r32, cl",
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
					Operand
					{
						.Type = OperandType::R32,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Cl,
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
							.Value = 0xad,
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
				.IntelMnemonic = "shrd",
				.GasMnemonic = "shrdq",
				.Description = "shrdq m64, r64, imm8",
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
					Operand
					{
						.Type = OperandType::R64,
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
							.Value = 0xac,
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
				.IntelMnemonic = "shrd",
				.GasMnemonic = "shrdq",
				.Description = "shrdq m64, r64, cl",
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
					Operand
					{
						.Type = OperandType::R64,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Cl,
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
							.Value = 0xad,
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
				.IntelMnemonic = "shrx",
				.GasMnemonic = "shrxl",
				.Description = "shrxl r32, r32, r32",
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
							.Value = 0xf7,
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
				.IntelMnemonic = "shrx",
				.GasMnemonic = "shrxl",
				.Description = "shrxl r32, m32, r32",
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
							.X = {OperandType::M32},
							.B = {OperandType::M32},
							.Vvvv = {OperandType::R32},
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
							.Reg = {OperandType::R32},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "shrx",
				.GasMnemonic = "shrxq",
				.Description = "shrxq r64, r64, r64",
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
							.Value = 0xf7,
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
				.IntelMnemonic = "shrx",
				.GasMnemonic = "shrxq",
				.Description = "shrxq r64, m64, r64",
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
							.X = {OperandType::M64},
							.B = {OperandType::M64},
							.Vvvv = {OperandType::R64},
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
				.IntelMnemonic = "shufpd",
				.GasMnemonic = "shufpd",
				.Description = "shufpd xmm, xmm, imm8",
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
							.Value = 0xc6,
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
				.IntelMnemonic = "shufpd",
				.GasMnemonic = "shufpd",
				.Description = "shufpd xmm, m128, imm8",
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
							.Value = 0xc6,
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
				.IntelMnemonic = "shufps",
				.GasMnemonic = "shufps",
				.Description = "shufps xmm, xmm, imm8",
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
					IsaExtension::Sse,
				},
				.EncodingScheme =
				{
					Encoding
					{
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
							.Value = 0xc6,
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
				.IntelMnemonic = "shufps",
				.GasMnemonic = "shufps",
				.Description = "shufps xmm, m128, imm8",
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
					IsaExtension::Sse,
				},
				.EncodingScheme =
				{
					Encoding
					{
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
							.Value = 0xc6,
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
				.IntelMnemonic = "sqrtpd",
				.GasMnemonic = "sqrtpd",
				.Description = "sqrtpd xmm, xmm",
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
							.Value = 0x51,
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
				.IntelMnemonic = "sqrtpd",
				.GasMnemonic = "sqrtpd",
				.Description = "sqrtpd xmm, m128",
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
							.Value = 0x51,
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
				.IntelMnemonic = "sqrtps",
				.GasMnemonic = "sqrtps",
				.Description = "sqrtps xmm, xmm",
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
					IsaExtension::Sse,
				},
				.EncodingScheme =
				{
					Encoding
					{
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
							.Value = 0x51,
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
				.IntelMnemonic = "sqrtps",
				.GasMnemonic = "sqrtps",
				.Description = "sqrtps xmm, m128",
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
					IsaExtension::Sse,
				},
				.EncodingScheme =
				{
					Encoding
					{
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
							.Value = 0x51,
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
				.IntelMnemonic = "sqrtsd",
				.GasMnemonic = "sqrtsd",
				.Description = "sqrtsd xmm, xmm",
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
							.Value = 0x51,
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
				.IntelMnemonic = "sqrtsd",
				.GasMnemonic = "sqrtsd",
				.Description = "sqrtsd xmm, m64",
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
						Prefix
						{
							.Value = 0xf2,
							.IsMandatory = true,
						},
						Rex
						{
							.W = false,
							.R = {OperandType::Xmm},
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
							.Value = 0x51,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M64},
							.Rm = {OperandType::M64},
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
				.IntelMnemonic = "sqrtss",
				.GasMnemonic = "sqrtss",
				.Description = "sqrtss xmm, xmm",
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
							.Value = 0x51,
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
				.IntelMnemonic = "sqrtss",
				.GasMnemonic = "sqrtss",
				.Description = "sqrtss xmm, m32",
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
							.Value = 0x51,
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
				.IntelMnemonic = "stc",
				.GasMnemonic = "stc",
				.Description = "stc",
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						OpCode
						{
							.Value = 0xf9,
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
				.IntelMnemonic = "std",
				.GasMnemonic = "std",
				.Description = "std",
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						OpCode
						{
							.Value = 0xfd,
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
				.IntelMnemonic = "stmxcsr",
				.GasMnemonic = "stmxcsr",
				.Description = "stmxcsr m32",
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
							.Value = 0xf,
							.Addend = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0xae,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M32},
							.Rm = {OperandType::M32},
							.Reg = {UINT64_C(0x3)},
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
				.IntelMnemonic = "sub",
				.GasMnemonic = "subb",
				.Description = "subb al, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Al,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						OpCode
						{
							.Value = 0x2c,
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
			InstructionVariation
			{
				.IntelMnemonic = "sub",
				.GasMnemonic = "subb",
				.Description = "subb r8, imm8",
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
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R8},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0x80,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R8},
							.Reg = {UINT64_C(0x5)},
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
				.IntelMnemonic = "sub",
				.GasMnemonic = "subb",
				.Description = "subb r8, r8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = true,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::R8,
						.IsInput = true,
						.IsOutput = true,
						.ExtendedSize = 0
					},
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
							.R = {OperandType::R8},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R8},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0x28,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R8},
							.Reg = {OperandType::R8},
						},
					},
					Encoding
					{
						Rex
						{
							.W = false,
							.R = {OperandType::R8},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R8},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0x2a,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R8},
							.Reg = {OperandType::R8},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "sub",
				.GasMnemonic = "subb",
				.Description = "subb r8, m8",
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						Rex
						{
							.W = false,
							.R = {OperandType::R8},
							.X = {OperandType::M8},
							.B = {OperandType::M8},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0x2a,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M8},
							.Rm = {OperandType::M8},
							.Reg = {OperandType::R8},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "sub",
				.GasMnemonic = "subw",
				.Description = "subw ax, imm16",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ax,
						.IsInput = true,
						.IsOutput = true,
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
						OpCode
						{
							.Value = 0x2d,
							.Addend = {UINT64_C(0x0)},
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
				.IntelMnemonic = "sub",
				.GasMnemonic = "subw",
				.Description = "subw r16, imm8",
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
						.Type = OperandType::Imm8,
						.IsInput = false,
						.IsOutput = false,
						.ExtendedSize = 2
					},
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
							.Value = 0x83,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R16},
							.Reg = {UINT64_C(0x5)},
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
				.IntelMnemonic = "sub",
				.GasMnemonic = "subw",
				.Description = "subw r16, imm16",
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
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R16},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0x81,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R16},
							.Reg = {UINT64_C(0x5)},
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
				.IntelMnemonic = "sub",
				.GasMnemonic = "subw",
				.Description = "subw r16, r16",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = true,
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
							.Value = 0x29,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R16},
							.Reg = {OperandType::R16},
						},
					},
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
							.Value = 0x2b,
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
				.IntelMnemonic = "sub",
				.GasMnemonic = "subw",
				.Description = "subw r16, m16",
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
							.Value = 0x2b,
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
				.IntelMnemonic = "sub",
				.GasMnemonic = "subl",
				.Description = "subl eax, imm32",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Eax,
						.IsInput = true,
						.IsOutput = true,
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
						OpCode
						{
							.Value = 0x2d,
							.Addend = {UINT64_C(0x0)},
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
				.IntelMnemonic = "sub",
				.GasMnemonic = "subl",
				.Description = "subl r32, imm8",
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
						.Type = OperandType::Imm8,
						.IsInput = false,
						.IsOutput = false,
						.ExtendedSize = 4
					},
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
							.Value = 0x83,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R32},
							.Reg = {UINT64_C(0x5)},
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
				.IntelMnemonic = "sub",
				.GasMnemonic = "subl",
				.Description = "subl r32, imm32",
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
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R32},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0x81,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R32},
							.Reg = {UINT64_C(0x5)},
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
				.IntelMnemonic = "sub",
				.GasMnemonic = "subl",
				.Description = "subl r32, r32",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = true,
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
							.Value = 0x29,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R32},
							.Reg = {OperandType::R32},
						},
					},
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
							.Value = 0x2b,
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
				.IntelMnemonic = "sub",
				.GasMnemonic = "subl",
				.Description = "subl r32, m32",
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
							.Value = 0x2b,
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
				.IntelMnemonic = "sub",
				.GasMnemonic = "subq",
				.Description = "subq rax, imm32",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Rax,
						.IsInput = true,
						.IsOutput = true,
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
							.W = true,
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {UINT64_C(0x0)},
							.IsMandatory = true,
						},
						OpCode
						{
							.Value = 0x2d,
							.Addend = {UINT64_C(0x0)},
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
				.IntelMnemonic = "sub",
				.GasMnemonic = "subq",
				.Description = "subq r64, imm8",
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
						.Type = OperandType::Imm8,
						.IsInput = false,
						.IsOutput = false,
						.ExtendedSize = 8
					},
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
							.Value = 0x83,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R64},
							.Reg = {UINT64_C(0x5)},
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
				.IntelMnemonic = "sub",
				.GasMnemonic = "subq",
				.Description = "subq r64, imm32",
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
						.Type = OperandType::Imm32,
						.IsInput = false,
						.IsOutput = false,
						.ExtendedSize = 8
					},
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
							.Value = 0x81,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R64},
							.Reg = {UINT64_C(0x5)},
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
				.IntelMnemonic = "sub",
				.GasMnemonic = "subq",
				.Description = "subq r64, r64",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = true,
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
							.Value = 0x29,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R64},
							.Reg = {OperandType::R64},
						},
					},
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
							.Value = 0x2b,
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
				.IntelMnemonic = "sub",
				.GasMnemonic = "subq",
				.Description = "subq r64, m64",
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
							.Value = 0x2b,
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
				.IntelMnemonic = "sub",
				.GasMnemonic = "subb",
				.Description = "subb m8, imm8",
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
							.R = {UINT64_C(0x0)},
							.X = {OperandType::M8},
							.B = {OperandType::M8},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0x80,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M8},
							.Rm = {OperandType::M8},
							.Reg = {UINT64_C(0x5)},
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
				.IntelMnemonic = "sub",
				.GasMnemonic = "subb",
				.Description = "subb m8, r8",
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
							.R = {OperandType::R8},
							.X = {OperandType::M8},
							.B = {OperandType::M8},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0x28,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M8},
							.Rm = {OperandType::M8},
							.Reg = {OperandType::R8},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "sub",
				.GasMnemonic = "subw",
				.Description = "subw m16, imm8",
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
					Operand
					{
						.Type = OperandType::Imm8,
						.IsInput = false,
						.IsOutput = false,
						.ExtendedSize = 2
					},
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
							.Value = 0x83,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M16},
							.Rm = {OperandType::M16},
							.Reg = {UINT64_C(0x5)},
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
				.IntelMnemonic = "sub",
				.GasMnemonic = "subw",
				.Description = "subw m16, imm16",
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
							.R = {UINT64_C(0x0)},
							.X = {OperandType::M16},
							.B = {OperandType::M16},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0x81,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M16},
							.Rm = {OperandType::M16},
							.Reg = {UINT64_C(0x5)},
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
				.IntelMnemonic = "sub",
				.GasMnemonic = "subw",
				.Description = "subw m16, r16",
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
							.X = {OperandType::M16},
							.B = {OperandType::M16},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0x29,
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
				.IntelMnemonic = "sub",
				.GasMnemonic = "subl",
				.Description = "subl m32, imm8",
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
					Operand
					{
						.Type = OperandType::Imm8,
						.IsInput = false,
						.IsOutput = false,
						.ExtendedSize = 4
					},
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
							.Value = 0x83,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M32},
							.Rm = {OperandType::M32},
							.Reg = {UINT64_C(0x5)},
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
				.IntelMnemonic = "sub",
				.GasMnemonic = "subl",
				.Description = "subl m32, imm32",
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
							.R = {UINT64_C(0x0)},
							.X = {OperandType::M32},
							.B = {OperandType::M32},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0x81,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M32},
							.Rm = {OperandType::M32},
							.Reg = {UINT64_C(0x5)},
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
				.IntelMnemonic = "sub",
				.GasMnemonic = "subl",
				.Description = "subl m32, r32",
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
							.X = {OperandType::M32},
							.B = {OperandType::M32},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0x29,
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
				.IntelMnemonic = "sub",
				.GasMnemonic = "subq",
				.Description = "subq m64, imm8",
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
					Operand
					{
						.Type = OperandType::Imm8,
						.IsInput = false,
						.IsOutput = false,
						.ExtendedSize = 8
					},
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
							.Value = 0x83,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M64},
							.Rm = {OperandType::M64},
							.Reg = {UINT64_C(0x5)},
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
				.IntelMnemonic = "sub",
				.GasMnemonic = "subq",
				.Description = "subq m64, imm32",
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
					Operand
					{
						.Type = OperandType::Imm32,
						.IsInput = false,
						.IsOutput = false,
						.ExtendedSize = 8
					},
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
							.Value = 0x81,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M64},
							.Rm = {OperandType::M64},
							.Reg = {UINT64_C(0x5)},
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
				.IntelMnemonic = "sub",
				.GasMnemonic = "subq",
				.Description = "subq m64, r64",
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
							.X = {OperandType::M64},
							.B = {OperandType::M64},
							.IsMandatory = true,
						},
						OpCode
						{
							.Value = 0x29,
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
				.IntelMnemonic = "subpd",
				.GasMnemonic = "subpd",
				.Description = "subpd xmm, xmm",
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
							.Value = 0x5c,
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
				.IntelMnemonic = "subpd",
				.GasMnemonic = "subpd",
				.Description = "subpd xmm, m128",
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
							.Value = 0x5c,
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
				.IntelMnemonic = "subps",
				.GasMnemonic = "subps",
				.Description = "subps xmm, xmm",
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
							.Value = 0x5c,
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
				.IntelMnemonic = "subps",
				.GasMnemonic = "subps",
				.Description = "subps xmm, m128",
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
					IsaExtension::Sse,
				},
				.EncodingScheme =
				{
					Encoding
					{
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
							.Value = 0x5c,
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
				.IntelMnemonic = "subsd",
				.GasMnemonic = "subsd",
				.Description = "subsd xmm, xmm",
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
							.Value = 0x5c,
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
				.IntelMnemonic = "subsd",
				.GasMnemonic = "subsd",
				.Description = "subsd xmm, m64",
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
						Prefix
						{
							.Value = 0xf2,
							.IsMandatory = true,
						},
						Rex
						{
							.W = false,
							.R = {OperandType::Xmm},
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
							.Value = 0x5c,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M64},
							.Rm = {OperandType::M64},
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
				.IntelMnemonic = "subss",
				.GasMnemonic = "subss",
				.Description = "subss xmm, xmm",
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
							.Value = 0x5c,
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
				.IntelMnemonic = "subss",
				.GasMnemonic = "subss",
				.Description = "subss xmm, m32",
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
							.Value = 0x5c,
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
				.IntelMnemonic = "syscall",
				.GasMnemonic = "syscall",
				.Description = "syscall",
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
					ImplicitRegisterOperand::Rcx,
					ImplicitRegisterOperand::R11,
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
							.Value = 0x5,
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
				.IntelMnemonic = "t1mskc",
				.GasMnemonic = "t1mskc",
				.Description = "t1mskc r32, r32",
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
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Tbm,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Xop,
							.Mmmmm = 0b1001,
							.Pp = 0b0,
							.W = false,
							.L = false,
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R32},
							.Vvvv = {OperandType::R32},
						},
						OpCode
						{
							.Value = 0x1,
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
				.IntelMnemonic = "t1mskc",
				.GasMnemonic = "t1mskc",
				.Description = "t1mskc r32, m32",
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
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Tbm,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Xop,
							.Mmmmm = 0b1001,
							.Pp = 0b0,
							.W = false,
							.L = false,
							.R = {UINT64_C(0x0)},
							.X = {OperandType::M32},
							.B = {OperandType::M32},
							.Vvvv = {OperandType::R32},
						},
						OpCode
						{
							.Value = 0x1,
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
				.IntelMnemonic = "t1mskc",
				.GasMnemonic = "t1mskc",
				.Description = "t1mskc r64, r64",
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
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Tbm,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Xop,
							.Mmmmm = 0b1001,
							.Pp = 0b0,
							.W = true,
							.L = false,
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R64},
							.Vvvv = {OperandType::R64},
						},
						OpCode
						{
							.Value = 0x1,
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
				.IntelMnemonic = "t1mskc",
				.GasMnemonic = "t1mskc",
				.Description = "t1mskc r64, m64",
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
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Tbm,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Xop,
							.Mmmmm = 0b1001,
							.Pp = 0b0,
							.W = true,
							.L = false,
							.R = {UINT64_C(0x0)},
							.X = {OperandType::M64},
							.B = {OperandType::M64},
							.Vvvv = {OperandType::R64},
						},
						OpCode
						{
							.Value = 0x1,
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
				.IntelMnemonic = "test",
				.GasMnemonic = "testb",
				.Description = "testb al, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Al,
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
				},
				.EncodingScheme =
				{
					Encoding
					{
						OpCode
						{
							.Value = 0xa8,
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
			InstructionVariation
			{
				.IntelMnemonic = "test",
				.GasMnemonic = "testb",
				.Description = "testb r8, imm8",
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
							.Reg = {UINT64_C(0x0)},
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
				.IntelMnemonic = "test",
				.GasMnemonic = "testb",
				.Description = "testb r8, r8",
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
							.R = {OperandType::R8},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R8},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0x84,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R8},
							.Reg = {OperandType::R8},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "test",
				.GasMnemonic = "testw",
				.Description = "testw ax, imm16",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ax,
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
						OpCode
						{
							.Value = 0xa9,
							.Addend = {UINT64_C(0x0)},
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
				.IntelMnemonic = "test",
				.GasMnemonic = "testw",
				.Description = "testw r16, imm16",
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
							.Reg = {UINT64_C(0x0)},
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
				.IntelMnemonic = "test",
				.GasMnemonic = "testw",
				.Description = "testw r16, r16",
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
							.Value = 0x85,
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
				.IntelMnemonic = "test",
				.GasMnemonic = "testl",
				.Description = "testl eax, imm32",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Eax,
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
						OpCode
						{
							.Value = 0xa9,
							.Addend = {UINT64_C(0x0)},
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
				.IntelMnemonic = "test",
				.GasMnemonic = "testl",
				.Description = "testl r32, imm32",
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
							.Reg = {UINT64_C(0x0)},
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
				.IntelMnemonic = "test",
				.GasMnemonic = "testl",
				.Description = "testl r32, r32",
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
							.Value = 0x85,
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
				.IntelMnemonic = "test",
				.GasMnemonic = "testq",
				.Description = "testq rax, imm32",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::None,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Rax,
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
							.W = true,
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {UINT64_C(0x0)},
							.IsMandatory = true,
						},
						OpCode
						{
							.Value = 0xa9,
							.Addend = {UINT64_C(0x0)},
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
				.IntelMnemonic = "test",
				.GasMnemonic = "testq",
				.Description = "testq r64, imm32",
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
					Operand
					{
						.Type = OperandType::Imm32,
						.IsInput = false,
						.IsOutput = false,
						.ExtendedSize = 8
					},
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
							.Value = 0xf7,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R64},
							.Reg = {UINT64_C(0x0)},
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
				.IntelMnemonic = "test",
				.GasMnemonic = "testq",
				.Description = "testq r64, r64",
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
							.Value = 0x85,
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
				.IntelMnemonic = "test",
				.GasMnemonic = "testb",
				.Description = "testb m8, imm8",
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
							.Reg = {UINT64_C(0x0)},
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
				.IntelMnemonic = "test",
				.GasMnemonic = "testb",
				.Description = "testb m8, r8",
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
							.R = {OperandType::R8},
							.X = {OperandType::M8},
							.B = {OperandType::M8},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0x84,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M8},
							.Rm = {OperandType::M8},
							.Reg = {OperandType::R8},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "test",
				.GasMnemonic = "testw",
				.Description = "testw m16, imm16",
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
							.Reg = {UINT64_C(0x0)},
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
				.IntelMnemonic = "test",
				.GasMnemonic = "testw",
				.Description = "testw m16, r16",
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
							.X = {OperandType::M16},
							.B = {OperandType::M16},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0x85,
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
				.IntelMnemonic = "test",
				.GasMnemonic = "testl",
				.Description = "testl m32, imm32",
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
							.Reg = {UINT64_C(0x0)},
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
				.IntelMnemonic = "test",
				.GasMnemonic = "testl",
				.Description = "testl m32, r32",
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
							.X = {OperandType::M32},
							.B = {OperandType::M32},
							.IsMandatory = false,
						},
						OpCode
						{
							.Value = 0x85,
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
				.IntelMnemonic = "test",
				.GasMnemonic = "testq",
				.Description = "testq m64, imm32",
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
					Operand
					{
						.Type = OperandType::Imm32,
						.IsInput = false,
						.IsOutput = false,
						.ExtendedSize = 8
					},
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
							.Value = 0xf7,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M64},
							.Rm = {OperandType::M64},
							.Reg = {UINT64_C(0x0)},
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
				.IntelMnemonic = "test",
				.GasMnemonic = "testq",
				.Description = "testq m64, r64",
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
							.X = {OperandType::M64},
							.B = {OperandType::M64},
							.IsMandatory = true,
						},
						OpCode
						{
							.Value = 0x85,
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
				.IntelMnemonic = "tzcnt",
				.GasMnemonic = "tzcntw",
				.Description = "tzcntw r16, r16",
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
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Bmi,
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
						Prefix
						{
							.Value = 0xf3,
							.IsMandatory = true,
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
							.Value = 0xbc,
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
				.IntelMnemonic = "tzcnt",
				.GasMnemonic = "tzcntw",
				.Description = "tzcntw r16, m16",
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
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Bmi,
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
						Prefix
						{
							.Value = 0xf3,
							.IsMandatory = true,
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
							.Value = 0xbc,
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
				.IntelMnemonic = "tzcnt",
				.GasMnemonic = "tzcntl",
				.Description = "tzcntl r32, r32",
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
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Bmi,
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
							.Value = 0xbc,
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
				.IntelMnemonic = "tzcnt",
				.GasMnemonic = "tzcntl",
				.Description = "tzcntl r32, m32",
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
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Bmi,
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
							.Value = 0xbc,
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
				.IntelMnemonic = "tzcnt",
				.GasMnemonic = "tzcntq",
				.Description = "tzcntq r64, r64",
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
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Bmi,
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
							.Value = 0xbc,
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
				.IntelMnemonic = "tzcnt",
				.GasMnemonic = "tzcntq",
				.Description = "tzcntq r64, m64",
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
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Bmi,
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
							.Value = 0xbc,
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
				.IntelMnemonic = "tzmsk",
				.GasMnemonic = "tzmsk",
				.Description = "tzmsk r32, r32",
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
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Tbm,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Xop,
							.Mmmmm = 0b1001,
							.Pp = 0b0,
							.W = false,
							.L = false,
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R32},
							.Vvvv = {OperandType::R32},
						},
						OpCode
						{
							.Value = 0x1,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R32},
							.Reg = {UINT64_C(0x4)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "tzmsk",
				.GasMnemonic = "tzmsk",
				.Description = "tzmsk r32, m32",
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
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Tbm,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Xop,
							.Mmmmm = 0b1001,
							.Pp = 0b0,
							.W = false,
							.L = false,
							.R = {UINT64_C(0x0)},
							.X = {OperandType::M32},
							.B = {OperandType::M32},
							.Vvvv = {OperandType::R32},
						},
						OpCode
						{
							.Value = 0x1,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M32},
							.Rm = {OperandType::M32},
							.Reg = {UINT64_C(0x4)},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "tzmsk",
				.GasMnemonic = "tzmsk",
				.Description = "tzmsk r64, r64",
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
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Tbm,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Xop,
							.Mmmmm = 0b1001,
							.Pp = 0b0,
							.W = true,
							.L = false,
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::R64},
							.Vvvv = {OperandType::R64},
						},
						OpCode
						{
							.Value = 0x1,
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
				.IntelMnemonic = "tzmsk",
				.GasMnemonic = "tzmsk",
				.Description = "tzmsk r64, m64",
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
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Tbm,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Xop,
							.Mmmmm = 0b1001,
							.Pp = 0b0,
							.W = true,
							.L = false,
							.R = {UINT64_C(0x0)},
							.X = {OperandType::M64},
							.B = {OperandType::M64},
							.Vvvv = {OperandType::R64},
						},
						OpCode
						{
							.Value = 0x1,
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
				.IntelMnemonic = "ucomisd",
				.GasMnemonic = "ucomisd",
				.Description = "ucomisd xmm, xmm",
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
							.Value = 0x2e,
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
				.IntelMnemonic = "ucomisd",
				.GasMnemonic = "ucomisd",
				.Description = "ucomisd xmm, m64",
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
						Prefix
						{
							.Value = 0x66,
							.IsMandatory = true,
						},
						Rex
						{
							.W = false,
							.R = {OperandType::Xmm},
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
							.Value = 0x2e,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M64},
							.Rm = {OperandType::M64},
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
				.IntelMnemonic = "ucomiss",
				.GasMnemonic = "ucomiss",
				.Description = "ucomiss xmm, xmm",
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
					IsaExtension::Sse,
				},
				.EncodingScheme =
				{
					Encoding
					{
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
							.Value = 0x2e,
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
				.IntelMnemonic = "ucomiss",
				.GasMnemonic = "ucomiss",
				.Description = "ucomiss xmm, m32",
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
							.Value = 0x2e,
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
	};
}
