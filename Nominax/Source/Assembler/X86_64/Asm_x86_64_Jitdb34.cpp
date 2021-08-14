// File: Asm_x86_64_Jitdb34.cpp
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

#include "../../../Include/Nominax/Assembler/_Assembler.hpp"

namespace Nominax::Assembler::X86_64
{
	NOX_NEVER_INLINE NOX_COLD auto GetVariationTable_34(std::pmr::monotonic_buffer_resource& allocator, std::pmr::vector<InstructionVariationPool>& out) -> void
	{
		std::pmr::vector<InstructionVariation> instruction {&allocator};
		instruction =
		{
			InstructionVariation
			{
				.IntelMnemonic = "vpsignb",
				.GasMnemonic = "vpsignb",
				.Description = "vpsignb xmm, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx,
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
							.R = {OperandType::Xmm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
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
				.IntelMnemonic = "vpsignb",
				.GasMnemonic = "vpsignb",
				.Description = "vpsignb xmm, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx,
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
							.R = {OperandType::Xmm},
							.X = {OperandType::M128},
							.B = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
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
			InstructionVariation
			{
				.IntelMnemonic = "vpsignb",
				.GasMnemonic = "vpsignb",
				.Description = "vpsignb ymm, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx2,
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
							.L = true,
							.R = {OperandType::Ymm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0x8,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
							.Reg = {OperandType::Ymm},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsignb",
				.GasMnemonic = "vpsignb",
				.Description = "vpsignb ymm, ymm, m256",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx2,
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
							.L = true,
							.R = {OperandType::Ymm},
							.X = {OperandType::M256},
							.B = {OperandType::M256},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0x8,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256},
							.Rm = {OperandType::M256},
							.Reg = {OperandType::Ymm},
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
				.IntelMnemonic = "vpsignd",
				.GasMnemonic = "vpsignd",
				.Description = "vpsignd xmm, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx,
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
							.R = {OperandType::Xmm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
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
				.IntelMnemonic = "vpsignd",
				.GasMnemonic = "vpsignd",
				.Description = "vpsignd xmm, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx,
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
							.R = {OperandType::Xmm},
							.X = {OperandType::M128},
							.B = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
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
			InstructionVariation
			{
				.IntelMnemonic = "vpsignd",
				.GasMnemonic = "vpsignd",
				.Description = "vpsignd ymm, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx2,
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
							.L = true,
							.R = {OperandType::Ymm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0xa,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
							.Reg = {OperandType::Ymm},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsignd",
				.GasMnemonic = "vpsignd",
				.Description = "vpsignd ymm, ymm, m256",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx2,
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
							.L = true,
							.R = {OperandType::Ymm},
							.X = {OperandType::M256},
							.B = {OperandType::M256},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0xa,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256},
							.Rm = {OperandType::M256},
							.Reg = {OperandType::Ymm},
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
				.IntelMnemonic = "vpsignw",
				.GasMnemonic = "vpsignw",
				.Description = "vpsignw xmm, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx,
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
							.R = {OperandType::Xmm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
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
				.IntelMnemonic = "vpsignw",
				.GasMnemonic = "vpsignw",
				.Description = "vpsignw xmm, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx,
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
							.R = {OperandType::Xmm},
							.X = {OperandType::M128},
							.B = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
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
			InstructionVariation
			{
				.IntelMnemonic = "vpsignw",
				.GasMnemonic = "vpsignw",
				.Description = "vpsignw ymm, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx2,
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
							.L = true,
							.R = {OperandType::Ymm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0x9,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
							.Reg = {OperandType::Ymm},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsignw",
				.GasMnemonic = "vpsignw",
				.Description = "vpsignw ymm, ymm, m256",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx2,
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
							.L = true,
							.R = {OperandType::Ymm},
							.X = {OperandType::M256},
							.B = {OperandType::M256},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0x9,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256},
							.Rm = {OperandType::M256},
							.Reg = {OperandType::Ymm},
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
				.IntelMnemonic = "vpslld",
				.GasMnemonic = "vpslld",
				.Description = "vpslld xmm{k}{z}, m128/m32bcst, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M128M32Bcst,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::M128M32Bcst},
							.X = {OperandType::M128M32Bcst},
							.Vvvv = {OperandType::XmmKz},
							.V = {OperandType::XmmKz},
							.B = {OperandType::M128M32Bcst},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 16,
						},
						OpCode
						{
							.Value = 0x72,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M128M32Bcst},
							.Rm = {OperandType::M128M32Bcst},
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
				.IntelMnemonic = "vpslld",
				.GasMnemonic = "vpslld",
				.Description = "vpslld ymm{k}{z}, m256/m32bcst, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256M32Bcst,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::M256M32Bcst},
							.X = {OperandType::M256M32Bcst},
							.Vvvv = {OperandType::YmmKz},
							.V = {OperandType::YmmKz},
							.B = {OperandType::M256M32Bcst},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0x72,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256M32Bcst},
							.Rm = {OperandType::M256M32Bcst},
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
				.IntelMnemonic = "vpslld",
				.GasMnemonic = "vpslld",
				.Description = "vpslld zmm{k}{z}, m512/m32bcst, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M512M32Bcst,
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
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::M512M32Bcst},
							.X = {OperandType::M512M32Bcst},
							.Vvvv = {OperandType::ZmmKz},
							.V = {OperandType::ZmmKz},
							.B = {OperandType::M512M32Bcst},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 64,
						},
						OpCode
						{
							.Value = 0x72,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M512M32Bcst},
							.Rm = {OperandType::M512M32Bcst},
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
				.IntelMnemonic = "vpslld",
				.GasMnemonic = "vpslld",
				.Description = "vpslld xmm{k}{z}, xmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::XmmKz},
							.V = {OperandType::XmmKz},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
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
				.IntelMnemonic = "vpslld",
				.GasMnemonic = "vpslld",
				.Description = "vpslld xmm{k}{z}, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
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
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpslld",
				.GasMnemonic = "vpslld",
				.Description = "vpslld xmm{k}{z}, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M128},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 16,
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
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpslld",
				.GasMnemonic = "vpslld",
				.Description = "vpslld ymm{k}{z}, ymm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::Ymm},
							.X = {OperandType::Ymm},
							.Vvvv = {OperandType::YmmKz},
							.V = {OperandType::YmmKz},
							.B = {OperandType::Ymm},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x72,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
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
				.IntelMnemonic = "vpslld",
				.GasMnemonic = "vpslld",
				.Description = "vpslld ymm{k}{z}, ymm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
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
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpslld",
				.GasMnemonic = "vpslld",
				.Description = "vpslld ymm{k}{z}, ymm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::M128},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 16,
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
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpslld",
				.GasMnemonic = "vpslld",
				.Description = "vpslld zmm{k}{z}, zmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
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
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::Zmm},
							.X = {OperandType::Zmm},
							.Vvvv = {OperandType::ZmmKz},
							.V = {OperandType::ZmmKz},
							.B = {OperandType::Zmm},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x72,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Zmm},
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
				.IntelMnemonic = "vpslld",
				.GasMnemonic = "vpslld",
				.Description = "vpslld zmm{k}{z}, zmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
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
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 0,
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
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpslld",
				.GasMnemonic = "vpslld",
				.Description = "vpslld zmm{k}{z}, zmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
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
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::M128},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 16,
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
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpslld",
				.GasMnemonic = "vpslld",
				.Description = "vpslld xmm, xmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
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
				.IntelMnemonic = "vpslld",
				.GasMnemonic = "vpslld",
				.Description = "vpslld xmm, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {OperandType::Xmm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
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
				.IntelMnemonic = "vpslld",
				.GasMnemonic = "vpslld",
				.Description = "vpslld xmm, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {OperandType::Xmm},
							.X = {OperandType::M128},
							.B = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
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
			InstructionVariation
			{
				.IntelMnemonic = "vpslld",
				.GasMnemonic = "vpslld",
				.Description = "vpslld ymm, ymm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = true,
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0x72,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
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
				.IntelMnemonic = "vpslld",
				.GasMnemonic = "vpslld",
				.Description = "vpslld ymm, ymm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = true,
							.R = {OperandType::Ymm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Ymm},
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
							.Reg = {OperandType::Ymm},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpslld",
				.GasMnemonic = "vpslld",
				.Description = "vpslld ymm, ymm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = true,
							.R = {OperandType::Ymm},
							.X = {OperandType::M128},
							.B = {OperandType::M128},
							.Vvvv = {OperandType::Ymm},
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
							.Reg = {OperandType::Ymm},
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
				.IntelMnemonic = "vpslldq",
				.GasMnemonic = "vpslldq",
				.Description = "vpslldq xmm, xmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
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
			InstructionVariation
			{
				.IntelMnemonic = "vpslldq",
				.GasMnemonic = "vpslldq",
				.Description = "vpslldq xmm, xmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::Xmm},
							.Aaa = {UINT64_C(0x0)},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
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
			InstructionVariation
			{
				.IntelMnemonic = "vpslldq",
				.GasMnemonic = "vpslldq",
				.Description = "vpslldq xmm, m128, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M128},
							.Aaa = {UINT64_C(0x0)},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 16,
						},
						OpCode
						{
							.Value = 0x73,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M128},
							.Rm = {OperandType::M128},
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
			InstructionVariation
			{
				.IntelMnemonic = "vpslldq",
				.GasMnemonic = "vpslldq",
				.Description = "vpslldq ymm, ymm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = true,
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0x73,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
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
			InstructionVariation
			{
				.IntelMnemonic = "vpslldq",
				.GasMnemonic = "vpslldq",
				.Description = "vpslldq ymm, ymm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::Ymm},
							.X = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::Ymm},
							.Aaa = {UINT64_C(0x0)},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x73,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
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
			InstructionVariation
			{
				.IntelMnemonic = "vpslldq",
				.GasMnemonic = "vpslldq",
				.Description = "vpslldq ymm, m256, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::M256},
							.X = {OperandType::M256},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::M256},
							.Aaa = {UINT64_C(0x0)},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0x73,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256},
							.Rm = {OperandType::M256},
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
			InstructionVariation
			{
				.IntelMnemonic = "vpslldq",
				.GasMnemonic = "vpslldq",
				.Description = "vpslldq zmm, zmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
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
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::Zmm},
							.X = {OperandType::Zmm},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::Zmm},
							.Aaa = {UINT64_C(0x0)},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x73,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Zmm},
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
			InstructionVariation
			{
				.IntelMnemonic = "vpslldq",
				.GasMnemonic = "vpslldq",
				.Description = "vpslldq zmm, m512, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M512,
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
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::M512},
							.X = {OperandType::M512},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::M512},
							.Aaa = {UINT64_C(0x0)},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 64,
						},
						OpCode
						{
							.Value = 0x73,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M512},
							.Rm = {OperandType::M512},
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
				.IntelMnemonic = "vpsllq",
				.GasMnemonic = "vpsllq",
				.Description = "vpsllq xmm{k}{z}, m128/m64bcst, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M128M64Bcst,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x0),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::M128M64Bcst},
							.X = {OperandType::M128M64Bcst},
							.Vvvv = {OperandType::XmmKz},
							.V = {OperandType::XmmKz},
							.B = {OperandType::M128M64Bcst},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 16,
						},
						OpCode
						{
							.Value = 0x73,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M128M64Bcst},
							.Rm = {OperandType::M128M64Bcst},
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
				.IntelMnemonic = "vpsllq",
				.GasMnemonic = "vpsllq",
				.Description = "vpsllq ymm{k}{z}, m256/m64bcst, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256M64Bcst,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x1),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::M256M64Bcst},
							.X = {OperandType::M256M64Bcst},
							.Vvvv = {OperandType::YmmKz},
							.V = {OperandType::YmmKz},
							.B = {OperandType::M256M64Bcst},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0x73,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256M64Bcst},
							.Rm = {OperandType::M256M64Bcst},
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
				.IntelMnemonic = "vpsllq",
				.GasMnemonic = "vpsllq",
				.Description = "vpsllq zmm{k}{z}, m512/m64bcst, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M512M64Bcst,
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
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x2),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::M512M64Bcst},
							.X = {OperandType::M512M64Bcst},
							.Vvvv = {OperandType::ZmmKz},
							.V = {OperandType::ZmmKz},
							.B = {OperandType::M512M64Bcst},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 64,
						},
						OpCode
						{
							.Value = 0x73,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M512M64Bcst},
							.Rm = {OperandType::M512M64Bcst},
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
				.IntelMnemonic = "vpsllq",
				.GasMnemonic = "vpsllq",
				.Description = "vpsllq xmm{k}{z}, xmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x0),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::XmmKz},
							.V = {OperandType::XmmKz},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
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
				.IntelMnemonic = "vpsllq",
				.GasMnemonic = "vpsllq",
				.Description = "vpsllq xmm{k}{z}, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
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
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsllq",
				.GasMnemonic = "vpsllq",
				.Description = "vpsllq xmm{k}{z}, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M128},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 16,
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
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsllq",
				.GasMnemonic = "vpsllq",
				.Description = "vpsllq ymm{k}{z}, ymm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x1),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::Ymm},
							.X = {OperandType::Ymm},
							.Vvvv = {OperandType::YmmKz},
							.V = {OperandType::YmmKz},
							.B = {OperandType::Ymm},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x73,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
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
				.IntelMnemonic = "vpsllq",
				.GasMnemonic = "vpsllq",
				.Description = "vpsllq ymm{k}{z}, ymm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
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
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsllq",
				.GasMnemonic = "vpsllq",
				.Description = "vpsllq ymm{k}{z}, ymm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::M128},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 16,
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
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsllq",
				.GasMnemonic = "vpsllq",
				.Description = "vpsllq zmm{k}{z}, zmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
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
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x2),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::Zmm},
							.X = {OperandType::Zmm},
							.Vvvv = {OperandType::ZmmKz},
							.V = {OperandType::ZmmKz},
							.B = {OperandType::Zmm},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x73,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Zmm},
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
				.IntelMnemonic = "vpsllq",
				.GasMnemonic = "vpsllq",
				.Description = "vpsllq zmm{k}{z}, zmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
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
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 0,
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
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsllq",
				.GasMnemonic = "vpsllq",
				.Description = "vpsllq zmm{k}{z}, zmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
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
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::M128},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 16,
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
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsllq",
				.GasMnemonic = "vpsllq",
				.Description = "vpsllq xmm, xmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
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
				.IntelMnemonic = "vpsllq",
				.GasMnemonic = "vpsllq",
				.Description = "vpsllq xmm, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {OperandType::Xmm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
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
				.IntelMnemonic = "vpsllq",
				.GasMnemonic = "vpsllq",
				.Description = "vpsllq xmm, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {OperandType::Xmm},
							.X = {OperandType::M128},
							.B = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
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
			InstructionVariation
			{
				.IntelMnemonic = "vpsllq",
				.GasMnemonic = "vpsllq",
				.Description = "vpsllq ymm, ymm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = true,
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0x73,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
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
				.IntelMnemonic = "vpsllq",
				.GasMnemonic = "vpsllq",
				.Description = "vpsllq ymm, ymm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = true,
							.R = {OperandType::Ymm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Ymm},
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
							.Reg = {OperandType::Ymm},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsllq",
				.GasMnemonic = "vpsllq",
				.Description = "vpsllq ymm, ymm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = true,
							.R = {OperandType::Ymm},
							.X = {OperandType::M128},
							.B = {OperandType::M128},
							.Vvvv = {OperandType::Ymm},
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
							.Reg = {OperandType::Ymm},
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
				.IntelMnemonic = "vpsllvd",
				.GasMnemonic = "vpsllvd",
				.Description = "vpsllvd xmm{k}{z}, xmm, m128/m32bcst",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
						.Type = OperandType::M128M32Bcst,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::M128M32Bcst},
							.X = {OperandType::M128M32Bcst},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M128M32Bcst},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 16,
						},
						OpCode
						{
							.Value = 0x47,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M128M32Bcst},
							.Rm = {OperandType::M128M32Bcst},
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsllvd",
				.GasMnemonic = "vpsllvd",
				.Description = "vpsllvd xmm{k}{z}, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x47,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Xmm},
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsllvd",
				.GasMnemonic = "vpsllvd",
				.Description = "vpsllvd ymm{k}{z}, ymm, m256/m32bcst",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256M32Bcst,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::M256M32Bcst},
							.X = {OperandType::M256M32Bcst},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::M256M32Bcst},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0x47,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256M32Bcst},
							.Rm = {OperandType::M256M32Bcst},
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsllvd",
				.GasMnemonic = "vpsllvd",
				.Description = "vpsllvd ymm{k}{z}, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::Ymm},
							.X = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::Ymm},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x47,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsllvd",
				.GasMnemonic = "vpsllvd",
				.Description = "vpsllvd zmm{k}{z}, zmm, m512/m32bcst",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M512M32Bcst,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::M512M32Bcst},
							.X = {OperandType::M512M32Bcst},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::M512M32Bcst},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 64,
						},
						OpCode
						{
							.Value = 0x47,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M512M32Bcst},
							.Rm = {OperandType::M512M32Bcst},
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsllvd",
				.GasMnemonic = "vpsllvd",
				.Description = "vpsllvd zmm{k}{z}, zmm, zmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::Zmm},
							.X = {OperandType::Zmm},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::Zmm},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x47,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Zmm},
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsllvd",
				.GasMnemonic = "vpsllvd",
				.Description = "vpsllvd xmm, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx2,
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
							.R = {OperandType::Xmm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
						},
						OpCode
						{
							.Value = 0x47,
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
				.IntelMnemonic = "vpsllvd",
				.GasMnemonic = "vpsllvd",
				.Description = "vpsllvd xmm, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx2,
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
							.R = {OperandType::Xmm},
							.X = {OperandType::M128},
							.B = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
						},
						OpCode
						{
							.Value = 0x47,
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
			InstructionVariation
			{
				.IntelMnemonic = "vpsllvd",
				.GasMnemonic = "vpsllvd",
				.Description = "vpsllvd ymm, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx2,
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
							.L = true,
							.R = {OperandType::Ymm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0x47,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
							.Reg = {OperandType::Ymm},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsllvd",
				.GasMnemonic = "vpsllvd",
				.Description = "vpsllvd ymm, ymm, m256",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx2,
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
							.L = true,
							.R = {OperandType::Ymm},
							.X = {OperandType::M256},
							.B = {OperandType::M256},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0x47,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256},
							.Rm = {OperandType::M256},
							.Reg = {OperandType::Ymm},
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
				.IntelMnemonic = "vpsllvq",
				.GasMnemonic = "vpsllvq",
				.Description = "vpsllvq xmm{k}{z}, xmm, m128/m64bcst",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
						.Type = OperandType::M128M64Bcst,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::M128M64Bcst},
							.X = {OperandType::M128M64Bcst},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M128M64Bcst},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 16,
						},
						OpCode
						{
							.Value = 0x47,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M128M64Bcst},
							.Rm = {OperandType::M128M64Bcst},
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsllvq",
				.GasMnemonic = "vpsllvq",
				.Description = "vpsllvq xmm{k}{z}, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x47,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Xmm},
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsllvq",
				.GasMnemonic = "vpsllvq",
				.Description = "vpsllvq ymm{k}{z}, ymm, m256/m64bcst",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256M64Bcst,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::M256M64Bcst},
							.X = {OperandType::M256M64Bcst},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::M256M64Bcst},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0x47,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256M64Bcst},
							.Rm = {OperandType::M256M64Bcst},
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsllvq",
				.GasMnemonic = "vpsllvq",
				.Description = "vpsllvq ymm{k}{z}, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::Ymm},
							.X = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::Ymm},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x47,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsllvq",
				.GasMnemonic = "vpsllvq",
				.Description = "vpsllvq zmm{k}{z}, zmm, m512/m64bcst",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M512M64Bcst,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::M512M64Bcst},
							.X = {OperandType::M512M64Bcst},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::M512M64Bcst},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 64,
						},
						OpCode
						{
							.Value = 0x47,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M512M64Bcst},
							.Rm = {OperandType::M512M64Bcst},
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsllvq",
				.GasMnemonic = "vpsllvq",
				.Description = "vpsllvq zmm{k}{z}, zmm, zmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::Zmm},
							.X = {OperandType::Zmm},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::Zmm},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x47,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Zmm},
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsllvq",
				.GasMnemonic = "vpsllvq",
				.Description = "vpsllvq xmm, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx2,
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
							.R = {OperandType::Xmm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
						},
						OpCode
						{
							.Value = 0x47,
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
				.IntelMnemonic = "vpsllvq",
				.GasMnemonic = "vpsllvq",
				.Description = "vpsllvq xmm, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx2,
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
							.R = {OperandType::Xmm},
							.X = {OperandType::M128},
							.B = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
						},
						OpCode
						{
							.Value = 0x47,
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
			InstructionVariation
			{
				.IntelMnemonic = "vpsllvq",
				.GasMnemonic = "vpsllvq",
				.Description = "vpsllvq ymm, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx2,
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
							.L = true,
							.R = {OperandType::Ymm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0x47,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
							.Reg = {OperandType::Ymm},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsllvq",
				.GasMnemonic = "vpsllvq",
				.Description = "vpsllvq ymm, ymm, m256",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx2,
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
							.L = true,
							.R = {OperandType::Ymm},
							.X = {OperandType::M256},
							.B = {OperandType::M256},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0x47,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256},
							.Rm = {OperandType::M256},
							.Reg = {OperandType::Ymm},
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
				.IntelMnemonic = "vpsllvw",
				.GasMnemonic = "vpsllvw",
				.Description = "vpsllvw xmm{k}{z}, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x12,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Xmm},
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsllvw",
				.GasMnemonic = "vpsllvw",
				.Description = "vpsllvw xmm{k}{z}, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M128},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 16,
						},
						OpCode
						{
							.Value = 0x12,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M128},
							.Rm = {OperandType::M128},
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsllvw",
				.GasMnemonic = "vpsllvw",
				.Description = "vpsllvw ymm{k}{z}, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::Ymm},
							.X = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::Ymm},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x12,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsllvw",
				.GasMnemonic = "vpsllvw",
				.Description = "vpsllvw ymm{k}{z}, ymm, m256",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::M256},
							.X = {OperandType::M256},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::M256},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0x12,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256},
							.Rm = {OperandType::M256},
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsllvw",
				.GasMnemonic = "vpsllvw",
				.Description = "vpsllvw zmm{k}{z}, zmm, zmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::Zmm},
							.X = {OperandType::Zmm},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::Zmm},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x12,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Zmm},
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsllvw",
				.GasMnemonic = "vpsllvw",
				.Description = "vpsllvw zmm{k}{z}, zmm, m512",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M512,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::M512},
							.X = {OperandType::M512},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::M512},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 64,
						},
						OpCode
						{
							.Value = 0x12,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M512},
							.Rm = {OperandType::M512},
							.Reg = {OperandType::ZmmKz},
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
				.IntelMnemonic = "vpsllw",
				.GasMnemonic = "vpsllw",
				.Description = "vpsllw xmm{k}{z}, xmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::XmmKz},
							.V = {OperandType::XmmKz},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
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
				.IntelMnemonic = "vpsllw",
				.GasMnemonic = "vpsllw",
				.Description = "vpsllw xmm{k}{z}, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
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
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsllw",
				.GasMnemonic = "vpsllw",
				.Description = "vpsllw xmm{k}{z}, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M128},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 16,
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
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsllw",
				.GasMnemonic = "vpsllw",
				.Description = "vpsllw ymm{k}{z}, ymm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::Ymm},
							.X = {OperandType::Ymm},
							.Vvvv = {OperandType::YmmKz},
							.V = {OperandType::YmmKz},
							.B = {OperandType::Ymm},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x71,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
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
				.IntelMnemonic = "vpsllw",
				.GasMnemonic = "vpsllw",
				.Description = "vpsllw ymm{k}{z}, ymm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
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
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsllw",
				.GasMnemonic = "vpsllw",
				.Description = "vpsllw ymm{k}{z}, ymm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::M128},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 16,
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
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsllw",
				.GasMnemonic = "vpsllw",
				.Description = "vpsllw zmm{k}{z}, zmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
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
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::Zmm},
							.X = {OperandType::Zmm},
							.Vvvv = {OperandType::ZmmKz},
							.V = {OperandType::ZmmKz},
							.B = {OperandType::Zmm},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x71,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Zmm},
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
				.IntelMnemonic = "vpsllw",
				.GasMnemonic = "vpsllw",
				.Description = "vpsllw zmm{k}{z}, zmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
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
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 0,
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
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsllw",
				.GasMnemonic = "vpsllw",
				.Description = "vpsllw zmm{k}{z}, zmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
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
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::M128},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 16,
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
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsllw",
				.GasMnemonic = "vpsllw",
				.Description = "vpsllw xmm{k}{z}, m128, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::XmmKz},
							.V = {OperandType::XmmKz},
							.B = {OperandType::M128},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 16,
						},
						OpCode
						{
							.Value = 0x71,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M128},
							.Rm = {OperandType::M128},
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
				.IntelMnemonic = "vpsllw",
				.GasMnemonic = "vpsllw",
				.Description = "vpsllw ymm{k}{z}, m256, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::M256},
							.X = {OperandType::M256},
							.Vvvv = {OperandType::YmmKz},
							.V = {OperandType::YmmKz},
							.B = {OperandType::M256},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0x71,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256},
							.Rm = {OperandType::M256},
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
				.IntelMnemonic = "vpsllw",
				.GasMnemonic = "vpsllw",
				.Description = "vpsllw zmm{k}{z}, m512, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M512,
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
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::M512},
							.X = {OperandType::M512},
							.Vvvv = {OperandType::ZmmKz},
							.V = {OperandType::ZmmKz},
							.B = {OperandType::M512},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 64,
						},
						OpCode
						{
							.Value = 0x71,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M512},
							.Rm = {OperandType::M512},
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
				.IntelMnemonic = "vpsllw",
				.GasMnemonic = "vpsllw",
				.Description = "vpsllw xmm, xmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
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
				.IntelMnemonic = "vpsllw",
				.GasMnemonic = "vpsllw",
				.Description = "vpsllw xmm, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {OperandType::Xmm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
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
				.IntelMnemonic = "vpsllw",
				.GasMnemonic = "vpsllw",
				.Description = "vpsllw xmm, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {OperandType::Xmm},
							.X = {OperandType::M128},
							.B = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
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
			InstructionVariation
			{
				.IntelMnemonic = "vpsllw",
				.GasMnemonic = "vpsllw",
				.Description = "vpsllw ymm, ymm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = true,
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0x71,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
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
				.IntelMnemonic = "vpsllw",
				.GasMnemonic = "vpsllw",
				.Description = "vpsllw ymm, ymm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = true,
							.R = {OperandType::Ymm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Ymm},
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
							.Reg = {OperandType::Ymm},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsllw",
				.GasMnemonic = "vpsllw",
				.Description = "vpsllw ymm, ymm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = true,
							.R = {OperandType::Ymm},
							.X = {OperandType::M128},
							.B = {OperandType::M128},
							.Vvvv = {OperandType::Ymm},
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
							.Reg = {OperandType::Ymm},
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
				.IntelMnemonic = "vpsrad",
				.GasMnemonic = "vpsrad",
				.Description = "vpsrad xmm{k}{z}, m128/m32bcst, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M128M32Bcst,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::M128M32Bcst},
							.X = {OperandType::M128M32Bcst},
							.Vvvv = {OperandType::XmmKz},
							.V = {OperandType::XmmKz},
							.B = {OperandType::M128M32Bcst},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 16,
						},
						OpCode
						{
							.Value = 0x72,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M128M32Bcst},
							.Rm = {OperandType::M128M32Bcst},
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
				.IntelMnemonic = "vpsrad",
				.GasMnemonic = "vpsrad",
				.Description = "vpsrad ymm{k}{z}, m256/m32bcst, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256M32Bcst,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::M256M32Bcst},
							.X = {OperandType::M256M32Bcst},
							.Vvvv = {OperandType::YmmKz},
							.V = {OperandType::YmmKz},
							.B = {OperandType::M256M32Bcst},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0x72,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256M32Bcst},
							.Rm = {OperandType::M256M32Bcst},
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
				.IntelMnemonic = "vpsrad",
				.GasMnemonic = "vpsrad",
				.Description = "vpsrad zmm{k}{z}, m512/m32bcst, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M512M32Bcst,
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
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::M512M32Bcst},
							.X = {OperandType::M512M32Bcst},
							.Vvvv = {OperandType::ZmmKz},
							.V = {OperandType::ZmmKz},
							.B = {OperandType::M512M32Bcst},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 64,
						},
						OpCode
						{
							.Value = 0x72,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M512M32Bcst},
							.Rm = {OperandType::M512M32Bcst},
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
				.IntelMnemonic = "vpsrad",
				.GasMnemonic = "vpsrad",
				.Description = "vpsrad xmm{k}{z}, xmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::XmmKz},
							.V = {OperandType::XmmKz},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
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
				.IntelMnemonic = "vpsrad",
				.GasMnemonic = "vpsrad",
				.Description = "vpsrad xmm{k}{z}, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
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
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrad",
				.GasMnemonic = "vpsrad",
				.Description = "vpsrad xmm{k}{z}, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M128},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 16,
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
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrad",
				.GasMnemonic = "vpsrad",
				.Description = "vpsrad ymm{k}{z}, ymm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::Ymm},
							.X = {OperandType::Ymm},
							.Vvvv = {OperandType::YmmKz},
							.V = {OperandType::YmmKz},
							.B = {OperandType::Ymm},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x72,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
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
				.IntelMnemonic = "vpsrad",
				.GasMnemonic = "vpsrad",
				.Description = "vpsrad ymm{k}{z}, ymm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
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
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrad",
				.GasMnemonic = "vpsrad",
				.Description = "vpsrad ymm{k}{z}, ymm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::M128},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 16,
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
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrad",
				.GasMnemonic = "vpsrad",
				.Description = "vpsrad zmm{k}{z}, zmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
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
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::Zmm},
							.X = {OperandType::Zmm},
							.Vvvv = {OperandType::ZmmKz},
							.V = {OperandType::ZmmKz},
							.B = {OperandType::Zmm},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x72,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Zmm},
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
				.IntelMnemonic = "vpsrad",
				.GasMnemonic = "vpsrad",
				.Description = "vpsrad zmm{k}{z}, zmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
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
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 0,
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
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrad",
				.GasMnemonic = "vpsrad",
				.Description = "vpsrad zmm{k}{z}, zmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
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
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::M128},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 16,
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
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrad",
				.GasMnemonic = "vpsrad",
				.Description = "vpsrad xmm, xmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
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
				.IntelMnemonic = "vpsrad",
				.GasMnemonic = "vpsrad",
				.Description = "vpsrad xmm, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {OperandType::Xmm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
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
				.IntelMnemonic = "vpsrad",
				.GasMnemonic = "vpsrad",
				.Description = "vpsrad xmm, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {OperandType::Xmm},
							.X = {OperandType::M128},
							.B = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
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
			InstructionVariation
			{
				.IntelMnemonic = "vpsrad",
				.GasMnemonic = "vpsrad",
				.Description = "vpsrad ymm, ymm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = true,
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0x72,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
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
				.IntelMnemonic = "vpsrad",
				.GasMnemonic = "vpsrad",
				.Description = "vpsrad ymm, ymm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = true,
							.R = {OperandType::Ymm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Ymm},
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
							.Reg = {OperandType::Ymm},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrad",
				.GasMnemonic = "vpsrad",
				.Description = "vpsrad ymm, ymm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = true,
							.R = {OperandType::Ymm},
							.X = {OperandType::M128},
							.B = {OperandType::M128},
							.Vvvv = {OperandType::Ymm},
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
							.Reg = {OperandType::Ymm},
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
				.IntelMnemonic = "vpsraq",
				.GasMnemonic = "vpsraq",
				.Description = "vpsraq xmm{k}{z}, m128/m64bcst, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M128M64Bcst,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x0),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::M128M64Bcst},
							.X = {OperandType::M128M64Bcst},
							.Vvvv = {OperandType::XmmKz},
							.V = {OperandType::XmmKz},
							.B = {OperandType::M128M64Bcst},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 16,
						},
						OpCode
						{
							.Value = 0x72,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M128M64Bcst},
							.Rm = {OperandType::M128M64Bcst},
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
				.IntelMnemonic = "vpsraq",
				.GasMnemonic = "vpsraq",
				.Description = "vpsraq ymm{k}{z}, m256/m64bcst, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256M64Bcst,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x1),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::M256M64Bcst},
							.X = {OperandType::M256M64Bcst},
							.Vvvv = {OperandType::YmmKz},
							.V = {OperandType::YmmKz},
							.B = {OperandType::M256M64Bcst},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0x72,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256M64Bcst},
							.Rm = {OperandType::M256M64Bcst},
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
				.IntelMnemonic = "vpsraq",
				.GasMnemonic = "vpsraq",
				.Description = "vpsraq zmm{k}{z}, m512/m64bcst, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M512M64Bcst,
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
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x2),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::M512M64Bcst},
							.X = {OperandType::M512M64Bcst},
							.Vvvv = {OperandType::ZmmKz},
							.V = {OperandType::ZmmKz},
							.B = {OperandType::M512M64Bcst},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 64,
						},
						OpCode
						{
							.Value = 0x72,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M512M64Bcst},
							.Rm = {OperandType::M512M64Bcst},
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
				.IntelMnemonic = "vpsraq",
				.GasMnemonic = "vpsraq",
				.Description = "vpsraq xmm{k}{z}, xmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x0),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::XmmKz},
							.V = {OperandType::XmmKz},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
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
				.IntelMnemonic = "vpsraq",
				.GasMnemonic = "vpsraq",
				.Description = "vpsraq xmm{k}{z}, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
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
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsraq",
				.GasMnemonic = "vpsraq",
				.Description = "vpsraq xmm{k}{z}, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M128},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 16,
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
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsraq",
				.GasMnemonic = "vpsraq",
				.Description = "vpsraq ymm{k}{z}, ymm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x1),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::Ymm},
							.X = {OperandType::Ymm},
							.Vvvv = {OperandType::YmmKz},
							.V = {OperandType::YmmKz},
							.B = {OperandType::Ymm},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x72,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
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
				.IntelMnemonic = "vpsraq",
				.GasMnemonic = "vpsraq",
				.Description = "vpsraq ymm{k}{z}, ymm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
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
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsraq",
				.GasMnemonic = "vpsraq",
				.Description = "vpsraq ymm{k}{z}, ymm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::M128},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 16,
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
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsraq",
				.GasMnemonic = "vpsraq",
				.Description = "vpsraq zmm{k}{z}, zmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
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
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x2),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::Zmm},
							.X = {OperandType::Zmm},
							.Vvvv = {OperandType::ZmmKz},
							.V = {OperandType::ZmmKz},
							.B = {OperandType::Zmm},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x72,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Zmm},
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
				.IntelMnemonic = "vpsraq",
				.GasMnemonic = "vpsraq",
				.Description = "vpsraq zmm{k}{z}, zmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
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
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 0,
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
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsraq",
				.GasMnemonic = "vpsraq",
				.Description = "vpsraq zmm{k}{z}, zmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
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
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::M128},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 16,
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
							.Reg = {OperandType::ZmmKz},
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
				.IntelMnemonic = "vpsravd",
				.GasMnemonic = "vpsravd",
				.Description = "vpsravd xmm{k}{z}, xmm, m128/m32bcst",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
						.Type = OperandType::M128M32Bcst,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::M128M32Bcst},
							.X = {OperandType::M128M32Bcst},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M128M32Bcst},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 16,
						},
						OpCode
						{
							.Value = 0x46,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M128M32Bcst},
							.Rm = {OperandType::M128M32Bcst},
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsravd",
				.GasMnemonic = "vpsravd",
				.Description = "vpsravd xmm{k}{z}, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x46,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Xmm},
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsravd",
				.GasMnemonic = "vpsravd",
				.Description = "vpsravd ymm{k}{z}, ymm, m256/m32bcst",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256M32Bcst,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::M256M32Bcst},
							.X = {OperandType::M256M32Bcst},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::M256M32Bcst},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0x46,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256M32Bcst},
							.Rm = {OperandType::M256M32Bcst},
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsravd",
				.GasMnemonic = "vpsravd",
				.Description = "vpsravd ymm{k}{z}, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::Ymm},
							.X = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::Ymm},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x46,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsravd",
				.GasMnemonic = "vpsravd",
				.Description = "vpsravd zmm{k}{z}, zmm, m512/m32bcst",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M512M32Bcst,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::M512M32Bcst},
							.X = {OperandType::M512M32Bcst},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::M512M32Bcst},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 64,
						},
						OpCode
						{
							.Value = 0x46,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M512M32Bcst},
							.Rm = {OperandType::M512M32Bcst},
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsravd",
				.GasMnemonic = "vpsravd",
				.Description = "vpsravd zmm{k}{z}, zmm, zmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::Zmm},
							.X = {OperandType::Zmm},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::Zmm},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x46,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Zmm},
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsravd",
				.GasMnemonic = "vpsravd",
				.Description = "vpsravd xmm, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx2,
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
							.R = {OperandType::Xmm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
						},
						OpCode
						{
							.Value = 0x46,
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
				.IntelMnemonic = "vpsravd",
				.GasMnemonic = "vpsravd",
				.Description = "vpsravd xmm, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx2,
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
							.R = {OperandType::Xmm},
							.X = {OperandType::M128},
							.B = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
						},
						OpCode
						{
							.Value = 0x46,
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
			InstructionVariation
			{
				.IntelMnemonic = "vpsravd",
				.GasMnemonic = "vpsravd",
				.Description = "vpsravd ymm, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx2,
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
							.L = true,
							.R = {OperandType::Ymm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0x46,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
							.Reg = {OperandType::Ymm},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsravd",
				.GasMnemonic = "vpsravd",
				.Description = "vpsravd ymm, ymm, m256",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx2,
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
							.L = true,
							.R = {OperandType::Ymm},
							.X = {OperandType::M256},
							.B = {OperandType::M256},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0x46,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256},
							.Rm = {OperandType::M256},
							.Reg = {OperandType::Ymm},
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
				.IntelMnemonic = "vpsravq",
				.GasMnemonic = "vpsravq",
				.Description = "vpsravq xmm{k}{z}, xmm, m128/m64bcst",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
						.Type = OperandType::M128M64Bcst,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::M128M64Bcst},
							.X = {OperandType::M128M64Bcst},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M128M64Bcst},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 16,
						},
						OpCode
						{
							.Value = 0x46,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M128M64Bcst},
							.Rm = {OperandType::M128M64Bcst},
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsravq",
				.GasMnemonic = "vpsravq",
				.Description = "vpsravq xmm{k}{z}, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x46,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Xmm},
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsravq",
				.GasMnemonic = "vpsravq",
				.Description = "vpsravq ymm{k}{z}, ymm, m256/m64bcst",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256M64Bcst,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::M256M64Bcst},
							.X = {OperandType::M256M64Bcst},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::M256M64Bcst},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0x46,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256M64Bcst},
							.Rm = {OperandType::M256M64Bcst},
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsravq",
				.GasMnemonic = "vpsravq",
				.Description = "vpsravq ymm{k}{z}, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::Ymm},
							.X = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::Ymm},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x46,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsravq",
				.GasMnemonic = "vpsravq",
				.Description = "vpsravq zmm{k}{z}, zmm, m512/m64bcst",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M512M64Bcst,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::M512M64Bcst},
							.X = {OperandType::M512M64Bcst},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::M512M64Bcst},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 64,
						},
						OpCode
						{
							.Value = 0x46,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M512M64Bcst},
							.Rm = {OperandType::M512M64Bcst},
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsravq",
				.GasMnemonic = "vpsravq",
				.Description = "vpsravq zmm{k}{z}, zmm, zmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::Zmm},
							.X = {OperandType::Zmm},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::Zmm},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x46,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Zmm},
							.Reg = {OperandType::ZmmKz},
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
				.IntelMnemonic = "vpsravw",
				.GasMnemonic = "vpsravw",
				.Description = "vpsravw xmm{k}{z}, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x11,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Xmm},
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsravw",
				.GasMnemonic = "vpsravw",
				.Description = "vpsravw xmm{k}{z}, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M128},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 16,
						},
						OpCode
						{
							.Value = 0x11,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M128},
							.Rm = {OperandType::M128},
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsravw",
				.GasMnemonic = "vpsravw",
				.Description = "vpsravw ymm{k}{z}, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::Ymm},
							.X = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::Ymm},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x11,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsravw",
				.GasMnemonic = "vpsravw",
				.Description = "vpsravw ymm{k}{z}, ymm, m256",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::M256},
							.X = {OperandType::M256},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::M256},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0x11,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256},
							.Rm = {OperandType::M256},
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsravw",
				.GasMnemonic = "vpsravw",
				.Description = "vpsravw zmm{k}{z}, zmm, zmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::Zmm},
							.X = {OperandType::Zmm},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::Zmm},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x11,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Zmm},
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsravw",
				.GasMnemonic = "vpsravw",
				.Description = "vpsravw zmm{k}{z}, zmm, m512",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M512,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::M512},
							.X = {OperandType::M512},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::M512},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 64,
						},
						OpCode
						{
							.Value = 0x11,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M512},
							.Rm = {OperandType::M512},
							.Reg = {OperandType::ZmmKz},
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
				.IntelMnemonic = "vpsraw",
				.GasMnemonic = "vpsraw",
				.Description = "vpsraw xmm{k}{z}, xmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::XmmKz},
							.V = {OperandType::XmmKz},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
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
				.IntelMnemonic = "vpsraw",
				.GasMnemonic = "vpsraw",
				.Description = "vpsraw xmm{k}{z}, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
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
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsraw",
				.GasMnemonic = "vpsraw",
				.Description = "vpsraw xmm{k}{z}, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M128},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 16,
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
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsraw",
				.GasMnemonic = "vpsraw",
				.Description = "vpsraw ymm{k}{z}, ymm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::Ymm},
							.X = {OperandType::Ymm},
							.Vvvv = {OperandType::YmmKz},
							.V = {OperandType::YmmKz},
							.B = {OperandType::Ymm},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x71,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
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
				.IntelMnemonic = "vpsraw",
				.GasMnemonic = "vpsraw",
				.Description = "vpsraw ymm{k}{z}, ymm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
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
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsraw",
				.GasMnemonic = "vpsraw",
				.Description = "vpsraw ymm{k}{z}, ymm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::M128},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 16,
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
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsraw",
				.GasMnemonic = "vpsraw",
				.Description = "vpsraw zmm{k}{z}, zmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
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
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::Zmm},
							.X = {OperandType::Zmm},
							.Vvvv = {OperandType::ZmmKz},
							.V = {OperandType::ZmmKz},
							.B = {OperandType::Zmm},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x71,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Zmm},
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
				.IntelMnemonic = "vpsraw",
				.GasMnemonic = "vpsraw",
				.Description = "vpsraw zmm{k}{z}, zmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
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
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 0,
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
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsraw",
				.GasMnemonic = "vpsraw",
				.Description = "vpsraw zmm{k}{z}, zmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
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
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::M128},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 16,
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
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsraw",
				.GasMnemonic = "vpsraw",
				.Description = "vpsraw xmm{k}{z}, m128, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::XmmKz},
							.V = {OperandType::XmmKz},
							.B = {OperandType::M128},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 16,
						},
						OpCode
						{
							.Value = 0x71,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M128},
							.Rm = {OperandType::M128},
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
				.IntelMnemonic = "vpsraw",
				.GasMnemonic = "vpsraw",
				.Description = "vpsraw ymm{k}{z}, m256, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::M256},
							.X = {OperandType::M256},
							.Vvvv = {OperandType::YmmKz},
							.V = {OperandType::YmmKz},
							.B = {OperandType::M256},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0x71,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256},
							.Rm = {OperandType::M256},
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
				.IntelMnemonic = "vpsraw",
				.GasMnemonic = "vpsraw",
				.Description = "vpsraw zmm{k}{z}, m512, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M512,
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
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::M512},
							.X = {OperandType::M512},
							.Vvvv = {OperandType::ZmmKz},
							.V = {OperandType::ZmmKz},
							.B = {OperandType::M512},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 64,
						},
						OpCode
						{
							.Value = 0x71,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M512},
							.Rm = {OperandType::M512},
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
				.IntelMnemonic = "vpsraw",
				.GasMnemonic = "vpsraw",
				.Description = "vpsraw xmm, xmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
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
				.IntelMnemonic = "vpsraw",
				.GasMnemonic = "vpsraw",
				.Description = "vpsraw xmm, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {OperandType::Xmm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
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
				.IntelMnemonic = "vpsraw",
				.GasMnemonic = "vpsraw",
				.Description = "vpsraw xmm, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {OperandType::Xmm},
							.X = {OperandType::M128},
							.B = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
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
			InstructionVariation
			{
				.IntelMnemonic = "vpsraw",
				.GasMnemonic = "vpsraw",
				.Description = "vpsraw ymm, ymm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = true,
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0x71,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
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
				.IntelMnemonic = "vpsraw",
				.GasMnemonic = "vpsraw",
				.Description = "vpsraw ymm, ymm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = true,
							.R = {OperandType::Ymm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Ymm},
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
							.Reg = {OperandType::Ymm},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsraw",
				.GasMnemonic = "vpsraw",
				.Description = "vpsraw ymm, ymm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = true,
							.R = {OperandType::Ymm},
							.X = {OperandType::M128},
							.B = {OperandType::M128},
							.Vvvv = {OperandType::Ymm},
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
							.Reg = {OperandType::Ymm},
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
				.IntelMnemonic = "vpsrld",
				.GasMnemonic = "vpsrld",
				.Description = "vpsrld xmm{k}{z}, m128/m32bcst, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M128M32Bcst,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::M128M32Bcst},
							.X = {OperandType::M128M32Bcst},
							.Vvvv = {OperandType::XmmKz},
							.V = {OperandType::XmmKz},
							.B = {OperandType::M128M32Bcst},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 16,
						},
						OpCode
						{
							.Value = 0x72,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M128M32Bcst},
							.Rm = {OperandType::M128M32Bcst},
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
				.IntelMnemonic = "vpsrld",
				.GasMnemonic = "vpsrld",
				.Description = "vpsrld ymm{k}{z}, m256/m32bcst, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256M32Bcst,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::M256M32Bcst},
							.X = {OperandType::M256M32Bcst},
							.Vvvv = {OperandType::YmmKz},
							.V = {OperandType::YmmKz},
							.B = {OperandType::M256M32Bcst},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0x72,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256M32Bcst},
							.Rm = {OperandType::M256M32Bcst},
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
				.IntelMnemonic = "vpsrld",
				.GasMnemonic = "vpsrld",
				.Description = "vpsrld zmm{k}{z}, m512/m32bcst, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M512M32Bcst,
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
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::M512M32Bcst},
							.X = {OperandType::M512M32Bcst},
							.Vvvv = {OperandType::ZmmKz},
							.V = {OperandType::ZmmKz},
							.B = {OperandType::M512M32Bcst},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 64,
						},
						OpCode
						{
							.Value = 0x72,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M512M32Bcst},
							.Rm = {OperandType::M512M32Bcst},
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
				.IntelMnemonic = "vpsrld",
				.GasMnemonic = "vpsrld",
				.Description = "vpsrld xmm{k}{z}, xmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::XmmKz},
							.V = {OperandType::XmmKz},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
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
				.IntelMnemonic = "vpsrld",
				.GasMnemonic = "vpsrld",
				.Description = "vpsrld xmm{k}{z}, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
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
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrld",
				.GasMnemonic = "vpsrld",
				.Description = "vpsrld xmm{k}{z}, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M128},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 16,
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
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrld",
				.GasMnemonic = "vpsrld",
				.Description = "vpsrld ymm{k}{z}, ymm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::Ymm},
							.X = {OperandType::Ymm},
							.Vvvv = {OperandType::YmmKz},
							.V = {OperandType::YmmKz},
							.B = {OperandType::Ymm},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x72,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
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
				.IntelMnemonic = "vpsrld",
				.GasMnemonic = "vpsrld",
				.Description = "vpsrld ymm{k}{z}, ymm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
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
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrld",
				.GasMnemonic = "vpsrld",
				.Description = "vpsrld ymm{k}{z}, ymm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::M128},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 16,
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
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrld",
				.GasMnemonic = "vpsrld",
				.Description = "vpsrld zmm{k}{z}, zmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
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
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::Zmm},
							.X = {OperandType::Zmm},
							.Vvvv = {OperandType::ZmmKz},
							.V = {OperandType::ZmmKz},
							.B = {OperandType::Zmm},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x72,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Zmm},
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
				.IntelMnemonic = "vpsrld",
				.GasMnemonic = "vpsrld",
				.Description = "vpsrld zmm{k}{z}, zmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
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
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 0,
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
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrld",
				.GasMnemonic = "vpsrld",
				.Description = "vpsrld zmm{k}{z}, zmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
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
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::M128},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 16,
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
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrld",
				.GasMnemonic = "vpsrld",
				.Description = "vpsrld xmm, xmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
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
				.IntelMnemonic = "vpsrld",
				.GasMnemonic = "vpsrld",
				.Description = "vpsrld xmm, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {OperandType::Xmm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
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
				.IntelMnemonic = "vpsrld",
				.GasMnemonic = "vpsrld",
				.Description = "vpsrld xmm, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {OperandType::Xmm},
							.X = {OperandType::M128},
							.B = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
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
			InstructionVariation
			{
				.IntelMnemonic = "vpsrld",
				.GasMnemonic = "vpsrld",
				.Description = "vpsrld ymm, ymm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = true,
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0x72,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
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
				.IntelMnemonic = "vpsrld",
				.GasMnemonic = "vpsrld",
				.Description = "vpsrld ymm, ymm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = true,
							.R = {OperandType::Ymm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Ymm},
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
							.Reg = {OperandType::Ymm},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrld",
				.GasMnemonic = "vpsrld",
				.Description = "vpsrld ymm, ymm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = true,
							.R = {OperandType::Ymm},
							.X = {OperandType::M128},
							.B = {OperandType::M128},
							.Vvvv = {OperandType::Ymm},
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
							.Reg = {OperandType::Ymm},
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
				.IntelMnemonic = "vpsrldq",
				.GasMnemonic = "vpsrldq",
				.Description = "vpsrldq xmm, xmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
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
			InstructionVariation
			{
				.IntelMnemonic = "vpsrldq",
				.GasMnemonic = "vpsrldq",
				.Description = "vpsrldq xmm, xmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::Xmm},
							.Aaa = {UINT64_C(0x0)},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
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
			InstructionVariation
			{
				.IntelMnemonic = "vpsrldq",
				.GasMnemonic = "vpsrldq",
				.Description = "vpsrldq xmm, m128, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M128},
							.Aaa = {UINT64_C(0x0)},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 16,
						},
						OpCode
						{
							.Value = 0x73,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M128},
							.Rm = {OperandType::M128},
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
			InstructionVariation
			{
				.IntelMnemonic = "vpsrldq",
				.GasMnemonic = "vpsrldq",
				.Description = "vpsrldq ymm, ymm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = true,
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0x73,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
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
			InstructionVariation
			{
				.IntelMnemonic = "vpsrldq",
				.GasMnemonic = "vpsrldq",
				.Description = "vpsrldq ymm, ymm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::Ymm},
							.X = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::Ymm},
							.Aaa = {UINT64_C(0x0)},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x73,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
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
			InstructionVariation
			{
				.IntelMnemonic = "vpsrldq",
				.GasMnemonic = "vpsrldq",
				.Description = "vpsrldq ymm, m256, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::M256},
							.X = {OperandType::M256},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::M256},
							.Aaa = {UINT64_C(0x0)},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0x73,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256},
							.Rm = {OperandType::M256},
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
			InstructionVariation
			{
				.IntelMnemonic = "vpsrldq",
				.GasMnemonic = "vpsrldq",
				.Description = "vpsrldq zmm, zmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
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
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::Zmm},
							.X = {OperandType::Zmm},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::Zmm},
							.Aaa = {UINT64_C(0x0)},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x73,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Zmm},
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
			InstructionVariation
			{
				.IntelMnemonic = "vpsrldq",
				.GasMnemonic = "vpsrldq",
				.Description = "vpsrldq zmm, m512, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M512,
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
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::M512},
							.X = {OperandType::M512},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::M512},
							.Aaa = {UINT64_C(0x0)},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 64,
						},
						OpCode
						{
							.Value = 0x73,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M512},
							.Rm = {OperandType::M512},
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
				.IntelMnemonic = "vpsrlq",
				.GasMnemonic = "vpsrlq",
				.Description = "vpsrlq xmm{k}{z}, m128/m64bcst, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M128M64Bcst,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x0),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::M128M64Bcst},
							.X = {OperandType::M128M64Bcst},
							.Vvvv = {OperandType::XmmKz},
							.V = {OperandType::XmmKz},
							.B = {OperandType::M128M64Bcst},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 16,
						},
						OpCode
						{
							.Value = 0x73,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M128M64Bcst},
							.Rm = {OperandType::M128M64Bcst},
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
				.IntelMnemonic = "vpsrlq",
				.GasMnemonic = "vpsrlq",
				.Description = "vpsrlq ymm{k}{z}, m256/m64bcst, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256M64Bcst,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x1),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::M256M64Bcst},
							.X = {OperandType::M256M64Bcst},
							.Vvvv = {OperandType::YmmKz},
							.V = {OperandType::YmmKz},
							.B = {OperandType::M256M64Bcst},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0x73,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256M64Bcst},
							.Rm = {OperandType::M256M64Bcst},
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
				.IntelMnemonic = "vpsrlq",
				.GasMnemonic = "vpsrlq",
				.Description = "vpsrlq zmm{k}{z}, m512/m64bcst, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M512M64Bcst,
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
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x2),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::M512M64Bcst},
							.X = {OperandType::M512M64Bcst},
							.Vvvv = {OperandType::ZmmKz},
							.V = {OperandType::ZmmKz},
							.B = {OperandType::M512M64Bcst},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 64,
						},
						OpCode
						{
							.Value = 0x73,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M512M64Bcst},
							.Rm = {OperandType::M512M64Bcst},
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
				.IntelMnemonic = "vpsrlq",
				.GasMnemonic = "vpsrlq",
				.Description = "vpsrlq xmm{k}{z}, xmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x0),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::XmmKz},
							.V = {OperandType::XmmKz},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
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
				.IntelMnemonic = "vpsrlq",
				.GasMnemonic = "vpsrlq",
				.Description = "vpsrlq xmm{k}{z}, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
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
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrlq",
				.GasMnemonic = "vpsrlq",
				.Description = "vpsrlq xmm{k}{z}, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M128},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 16,
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
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrlq",
				.GasMnemonic = "vpsrlq",
				.Description = "vpsrlq ymm{k}{z}, ymm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x1),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::Ymm},
							.X = {OperandType::Ymm},
							.Vvvv = {OperandType::YmmKz},
							.V = {OperandType::YmmKz},
							.B = {OperandType::Ymm},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x73,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
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
				.IntelMnemonic = "vpsrlq",
				.GasMnemonic = "vpsrlq",
				.Description = "vpsrlq ymm{k}{z}, ymm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
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
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrlq",
				.GasMnemonic = "vpsrlq",
				.Description = "vpsrlq ymm{k}{z}, ymm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::M128},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 16,
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
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrlq",
				.GasMnemonic = "vpsrlq",
				.Description = "vpsrlq zmm{k}{z}, zmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
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
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x2),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::Zmm},
							.X = {OperandType::Zmm},
							.Vvvv = {OperandType::ZmmKz},
							.V = {OperandType::ZmmKz},
							.B = {OperandType::Zmm},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x73,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Zmm},
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
				.IntelMnemonic = "vpsrlq",
				.GasMnemonic = "vpsrlq",
				.Description = "vpsrlq zmm{k}{z}, zmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
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
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 0,
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
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrlq",
				.GasMnemonic = "vpsrlq",
				.Description = "vpsrlq zmm{k}{z}, zmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
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
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::M128},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 16,
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
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrlq",
				.GasMnemonic = "vpsrlq",
				.Description = "vpsrlq xmm, xmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
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
				.IntelMnemonic = "vpsrlq",
				.GasMnemonic = "vpsrlq",
				.Description = "vpsrlq xmm, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {OperandType::Xmm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
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
				.IntelMnemonic = "vpsrlq",
				.GasMnemonic = "vpsrlq",
				.Description = "vpsrlq xmm, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {OperandType::Xmm},
							.X = {OperandType::M128},
							.B = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
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
			InstructionVariation
			{
				.IntelMnemonic = "vpsrlq",
				.GasMnemonic = "vpsrlq",
				.Description = "vpsrlq ymm, ymm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = true,
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0x73,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
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
				.IntelMnemonic = "vpsrlq",
				.GasMnemonic = "vpsrlq",
				.Description = "vpsrlq ymm, ymm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = true,
							.R = {OperandType::Ymm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Ymm},
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
							.Reg = {OperandType::Ymm},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrlq",
				.GasMnemonic = "vpsrlq",
				.Description = "vpsrlq ymm, ymm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = true,
							.R = {OperandType::Ymm},
							.X = {OperandType::M128},
							.B = {OperandType::M128},
							.Vvvv = {OperandType::Ymm},
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
							.Reg = {OperandType::Ymm},
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
				.IntelMnemonic = "vpsrlvd",
				.GasMnemonic = "vpsrlvd",
				.Description = "vpsrlvd xmm{k}{z}, xmm, m128/m32bcst",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
						.Type = OperandType::M128M32Bcst,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::M128M32Bcst},
							.X = {OperandType::M128M32Bcst},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M128M32Bcst},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 16,
						},
						OpCode
						{
							.Value = 0x45,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M128M32Bcst},
							.Rm = {OperandType::M128M32Bcst},
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrlvd",
				.GasMnemonic = "vpsrlvd",
				.Description = "vpsrlvd xmm{k}{z}, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x45,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Xmm},
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrlvd",
				.GasMnemonic = "vpsrlvd",
				.Description = "vpsrlvd ymm{k}{z}, ymm, m256/m32bcst",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256M32Bcst,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::M256M32Bcst},
							.X = {OperandType::M256M32Bcst},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::M256M32Bcst},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0x45,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256M32Bcst},
							.Rm = {OperandType::M256M32Bcst},
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrlvd",
				.GasMnemonic = "vpsrlvd",
				.Description = "vpsrlvd ymm{k}{z}, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::Ymm},
							.X = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::Ymm},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x45,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrlvd",
				.GasMnemonic = "vpsrlvd",
				.Description = "vpsrlvd zmm{k}{z}, zmm, m512/m32bcst",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M512M32Bcst,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::M512M32Bcst},
							.X = {OperandType::M512M32Bcst},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::M512M32Bcst},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 64,
						},
						OpCode
						{
							.Value = 0x45,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M512M32Bcst},
							.Rm = {OperandType::M512M32Bcst},
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrlvd",
				.GasMnemonic = "vpsrlvd",
				.Description = "vpsrlvd zmm{k}{z}, zmm, zmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::Zmm},
							.X = {OperandType::Zmm},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::Zmm},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x45,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Zmm},
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrlvd",
				.GasMnemonic = "vpsrlvd",
				.Description = "vpsrlvd xmm, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx2,
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
							.R = {OperandType::Xmm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
						},
						OpCode
						{
							.Value = 0x45,
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
				.IntelMnemonic = "vpsrlvd",
				.GasMnemonic = "vpsrlvd",
				.Description = "vpsrlvd xmm, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx2,
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
							.R = {OperandType::Xmm},
							.X = {OperandType::M128},
							.B = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
						},
						OpCode
						{
							.Value = 0x45,
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
			InstructionVariation
			{
				.IntelMnemonic = "vpsrlvd",
				.GasMnemonic = "vpsrlvd",
				.Description = "vpsrlvd ymm, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx2,
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
							.L = true,
							.R = {OperandType::Ymm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0x45,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
							.Reg = {OperandType::Ymm},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrlvd",
				.GasMnemonic = "vpsrlvd",
				.Description = "vpsrlvd ymm, ymm, m256",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx2,
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
							.L = true,
							.R = {OperandType::Ymm},
							.X = {OperandType::M256},
							.B = {OperandType::M256},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0x45,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256},
							.Rm = {OperandType::M256},
							.Reg = {OperandType::Ymm},
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
				.IntelMnemonic = "vpsrlvq",
				.GasMnemonic = "vpsrlvq",
				.Description = "vpsrlvq xmm{k}{z}, xmm, m128/m64bcst",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
						.Type = OperandType::M128M64Bcst,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::M128M64Bcst},
							.X = {OperandType::M128M64Bcst},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M128M64Bcst},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 16,
						},
						OpCode
						{
							.Value = 0x45,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M128M64Bcst},
							.Rm = {OperandType::M128M64Bcst},
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrlvq",
				.GasMnemonic = "vpsrlvq",
				.Description = "vpsrlvq xmm{k}{z}, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x45,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Xmm},
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrlvq",
				.GasMnemonic = "vpsrlvq",
				.Description = "vpsrlvq ymm{k}{z}, ymm, m256/m64bcst",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256M64Bcst,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::M256M64Bcst},
							.X = {OperandType::M256M64Bcst},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::M256M64Bcst},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0x45,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256M64Bcst},
							.Rm = {OperandType::M256M64Bcst},
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrlvq",
				.GasMnemonic = "vpsrlvq",
				.Description = "vpsrlvq ymm{k}{z}, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::Ymm},
							.X = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::Ymm},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x45,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrlvq",
				.GasMnemonic = "vpsrlvq",
				.Description = "vpsrlvq zmm{k}{z}, zmm, m512/m64bcst",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M512M64Bcst,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::M512M64Bcst},
							.X = {OperandType::M512M64Bcst},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::M512M64Bcst},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 64,
						},
						OpCode
						{
							.Value = 0x45,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M512M64Bcst},
							.Rm = {OperandType::M512M64Bcst},
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrlvq",
				.GasMnemonic = "vpsrlvq",
				.Description = "vpsrlvq zmm{k}{z}, zmm, zmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::Zmm},
							.X = {OperandType::Zmm},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::Zmm},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x45,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Zmm},
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrlvq",
				.GasMnemonic = "vpsrlvq",
				.Description = "vpsrlvq xmm, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx2,
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
							.R = {OperandType::Xmm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
						},
						OpCode
						{
							.Value = 0x45,
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
				.IntelMnemonic = "vpsrlvq",
				.GasMnemonic = "vpsrlvq",
				.Description = "vpsrlvq xmm, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx2,
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
							.R = {OperandType::Xmm},
							.X = {OperandType::M128},
							.B = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
						},
						OpCode
						{
							.Value = 0x45,
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
			InstructionVariation
			{
				.IntelMnemonic = "vpsrlvq",
				.GasMnemonic = "vpsrlvq",
				.Description = "vpsrlvq ymm, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx2,
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
							.L = true,
							.R = {OperandType::Ymm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0x45,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
							.Reg = {OperandType::Ymm},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrlvq",
				.GasMnemonic = "vpsrlvq",
				.Description = "vpsrlvq ymm, ymm, m256",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx2,
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
							.L = true,
							.R = {OperandType::Ymm},
							.X = {OperandType::M256},
							.B = {OperandType::M256},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0x45,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256},
							.Rm = {OperandType::M256},
							.Reg = {OperandType::Ymm},
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
				.IntelMnemonic = "vpsrlvw",
				.GasMnemonic = "vpsrlvw",
				.Description = "vpsrlvw xmm{k}{z}, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
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
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrlvw",
				.GasMnemonic = "vpsrlvw",
				.Description = "vpsrlvw xmm{k}{z}, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M128},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 16,
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
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrlvw",
				.GasMnemonic = "vpsrlvw",
				.Description = "vpsrlvw ymm{k}{z}, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::Ymm},
							.X = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::Ymm},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x10,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrlvw",
				.GasMnemonic = "vpsrlvw",
				.Description = "vpsrlvw ymm{k}{z}, ymm, m256",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::M256},
							.X = {OperandType::M256},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::M256},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0x10,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256},
							.Rm = {OperandType::M256},
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrlvw",
				.GasMnemonic = "vpsrlvw",
				.Description = "vpsrlvw zmm{k}{z}, zmm, zmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::Zmm},
							.X = {OperandType::Zmm},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::Zmm},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x10,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Zmm},
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrlvw",
				.GasMnemonic = "vpsrlvw",
				.Description = "vpsrlvw zmm{k}{z}, zmm, m512",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M512,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b10,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::M512},
							.X = {OperandType::M512},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::M512},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 64,
						},
						OpCode
						{
							.Value = 0x10,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M512},
							.Rm = {OperandType::M512},
							.Reg = {OperandType::ZmmKz},
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
				.IntelMnemonic = "vpsrlw",
				.GasMnemonic = "vpsrlw",
				.Description = "vpsrlw xmm{k}{z}, xmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::XmmKz},
							.V = {OperandType::XmmKz},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
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
				.IntelMnemonic = "vpsrlw",
				.GasMnemonic = "vpsrlw",
				.Description = "vpsrlw xmm{k}{z}, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
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
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrlw",
				.GasMnemonic = "vpsrlw",
				.Description = "vpsrlw xmm{k}{z}, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M128},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 16,
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
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrlw",
				.GasMnemonic = "vpsrlw",
				.Description = "vpsrlw ymm{k}{z}, ymm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::Ymm},
							.X = {OperandType::Ymm},
							.Vvvv = {OperandType::YmmKz},
							.V = {OperandType::YmmKz},
							.B = {OperandType::Ymm},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x71,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
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
				.IntelMnemonic = "vpsrlw",
				.GasMnemonic = "vpsrlw",
				.Description = "vpsrlw ymm{k}{z}, ymm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
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
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrlw",
				.GasMnemonic = "vpsrlw",
				.Description = "vpsrlw ymm{k}{z}, ymm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::M128},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 16,
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
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrlw",
				.GasMnemonic = "vpsrlw",
				.Description = "vpsrlw zmm{k}{z}, zmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
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
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::Zmm},
							.X = {OperandType::Zmm},
							.Vvvv = {OperandType::ZmmKz},
							.V = {OperandType::ZmmKz},
							.B = {OperandType::Zmm},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x71,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Zmm},
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
				.IntelMnemonic = "vpsrlw",
				.GasMnemonic = "vpsrlw",
				.Description = "vpsrlw zmm{k}{z}, zmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
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
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 0,
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
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrlw",
				.GasMnemonic = "vpsrlw",
				.Description = "vpsrlw zmm{k}{z}, zmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
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
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::M128},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 16,
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
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrlw",
				.GasMnemonic = "vpsrlw",
				.Description = "vpsrlw xmm{k}{z}, m128, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::XmmKz},
							.V = {OperandType::XmmKz},
							.B = {OperandType::M128},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 16,
						},
						OpCode
						{
							.Value = 0x71,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M128},
							.Rm = {OperandType::M128},
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
				.IntelMnemonic = "vpsrlw",
				.GasMnemonic = "vpsrlw",
				.Description = "vpsrlw ymm{k}{z}, m256, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::M256},
							.X = {OperandType::M256},
							.Vvvv = {OperandType::YmmKz},
							.V = {OperandType::YmmKz},
							.B = {OperandType::M256},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0x71,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256},
							.Rm = {OperandType::M256},
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
				.IntelMnemonic = "vpsrlw",
				.GasMnemonic = "vpsrlw",
				.Description = "vpsrlw zmm{k}{z}, m512, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M512,
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
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {UINT64_C(0x0)},
							.Bb = {OperandType::M512},
							.X = {OperandType::M512},
							.Vvvv = {OperandType::ZmmKz},
							.V = {OperandType::ZmmKz},
							.B = {OperandType::M512},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 64,
						},
						OpCode
						{
							.Value = 0x71,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M512},
							.Rm = {OperandType::M512},
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
				.IntelMnemonic = "vpsrlw",
				.GasMnemonic = "vpsrlw",
				.Description = "vpsrlw xmm, xmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
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
				.IntelMnemonic = "vpsrlw",
				.GasMnemonic = "vpsrlw",
				.Description = "vpsrlw xmm, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {OperandType::Xmm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
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
				.IntelMnemonic = "vpsrlw",
				.GasMnemonic = "vpsrlw",
				.Description = "vpsrlw xmm, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {OperandType::Xmm},
							.X = {OperandType::M128},
							.B = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
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
			InstructionVariation
			{
				.IntelMnemonic = "vpsrlw",
				.GasMnemonic = "vpsrlw",
				.Description = "vpsrlw ymm, ymm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = true,
							.R = {UINT64_C(0x0)},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0x71,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
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
				.IntelMnemonic = "vpsrlw",
				.GasMnemonic = "vpsrlw",
				.Description = "vpsrlw ymm, ymm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = true,
							.R = {OperandType::Ymm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Ymm},
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
							.Reg = {OperandType::Ymm},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsrlw",
				.GasMnemonic = "vpsrlw",
				.Description = "vpsrlw ymm, ymm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = true,
							.R = {OperandType::Ymm},
							.X = {OperandType::M128},
							.B = {OperandType::M128},
							.Vvvv = {OperandType::Ymm},
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
							.Reg = {OperandType::Ymm},
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
				.IntelMnemonic = "vpsubb",
				.GasMnemonic = "vpsubb",
				.Description = "vpsubb xmm{k}{z}, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
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
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubb",
				.GasMnemonic = "vpsubb",
				.Description = "vpsubb xmm{k}{z}, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M128},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 16,
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
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubb",
				.GasMnemonic = "vpsubb",
				.Description = "vpsubb ymm{k}{z}, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::Ymm},
							.X = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::Ymm},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0xf8,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubb",
				.GasMnemonic = "vpsubb",
				.Description = "vpsubb ymm{k}{z}, ymm, m256",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::M256},
							.X = {OperandType::M256},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::M256},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0xf8,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256},
							.Rm = {OperandType::M256},
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubb",
				.GasMnemonic = "vpsubb",
				.Description = "vpsubb zmm{k}{z}, zmm, zmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::Zmm},
							.X = {OperandType::Zmm},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::Zmm},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0xf8,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Zmm},
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubb",
				.GasMnemonic = "vpsubb",
				.Description = "vpsubb zmm{k}{z}, zmm, m512",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M512,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::M512},
							.X = {OperandType::M512},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::M512},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 64,
						},
						OpCode
						{
							.Value = 0xf8,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M512},
							.Rm = {OperandType::M512},
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubb",
				.GasMnemonic = "vpsubb",
				.Description = "vpsubb xmm, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
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
					IsaExtension::Avx,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {OperandType::Xmm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
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
				.IntelMnemonic = "vpsubb",
				.GasMnemonic = "vpsubb",
				.Description = "vpsubb xmm, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {OperandType::Xmm},
							.X = {OperandType::M128},
							.B = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
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
			InstructionVariation
			{
				.IntelMnemonic = "vpsubb",
				.GasMnemonic = "vpsubb",
				.Description = "vpsubb ymm, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = true,
							.R = {OperandType::Ymm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0xf8,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
							.Reg = {OperandType::Ymm},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubb",
				.GasMnemonic = "vpsubb",
				.Description = "vpsubb ymm, ymm, m256",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = true,
							.R = {OperandType::Ymm},
							.X = {OperandType::M256},
							.B = {OperandType::M256},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0xf8,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256},
							.Rm = {OperandType::M256},
							.Reg = {OperandType::Ymm},
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
				.IntelMnemonic = "vpsubd",
				.GasMnemonic = "vpsubd",
				.Description = "vpsubd xmm{k}{z}, xmm, m128/m32bcst",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
						.Type = OperandType::M128M32Bcst,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::M128M32Bcst},
							.X = {OperandType::M128M32Bcst},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M128M32Bcst},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 16,
						},
						OpCode
						{
							.Value = 0xfa,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M128M32Bcst},
							.Rm = {OperandType::M128M32Bcst},
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubd",
				.GasMnemonic = "vpsubd",
				.Description = "vpsubd xmm{k}{z}, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
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
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubd",
				.GasMnemonic = "vpsubd",
				.Description = "vpsubd ymm{k}{z}, ymm, m256/m32bcst",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256M32Bcst,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::M256M32Bcst},
							.X = {OperandType::M256M32Bcst},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::M256M32Bcst},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0xfa,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256M32Bcst},
							.Rm = {OperandType::M256M32Bcst},
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubd",
				.GasMnemonic = "vpsubd",
				.Description = "vpsubd ymm{k}{z}, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::Ymm},
							.X = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::Ymm},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0xfa,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubd",
				.GasMnemonic = "vpsubd",
				.Description = "vpsubd zmm{k}{z}, zmm, m512/m32bcst",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M512M32Bcst,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::M512M32Bcst},
							.X = {OperandType::M512M32Bcst},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::M512M32Bcst},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 64,
						},
						OpCode
						{
							.Value = 0xfa,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M512M32Bcst},
							.Rm = {OperandType::M512M32Bcst},
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubd",
				.GasMnemonic = "vpsubd",
				.Description = "vpsubd zmm{k}{z}, zmm, zmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::Zmm},
							.X = {OperandType::Zmm},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::Zmm},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0xfa,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Zmm},
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubd",
				.GasMnemonic = "vpsubd",
				.Description = "vpsubd xmm, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
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
					IsaExtension::Avx,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {OperandType::Xmm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
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
				.IntelMnemonic = "vpsubd",
				.GasMnemonic = "vpsubd",
				.Description = "vpsubd xmm, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {OperandType::Xmm},
							.X = {OperandType::M128},
							.B = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
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
			InstructionVariation
			{
				.IntelMnemonic = "vpsubd",
				.GasMnemonic = "vpsubd",
				.Description = "vpsubd ymm, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = true,
							.R = {OperandType::Ymm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0xfa,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
							.Reg = {OperandType::Ymm},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubd",
				.GasMnemonic = "vpsubd",
				.Description = "vpsubd ymm, ymm, m256",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = true,
							.R = {OperandType::Ymm},
							.X = {OperandType::M256},
							.B = {OperandType::M256},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0xfa,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256},
							.Rm = {OperandType::M256},
							.Reg = {OperandType::Ymm},
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
				.IntelMnemonic = "vpsubq",
				.GasMnemonic = "vpsubq",
				.Description = "vpsubq xmm{k}{z}, xmm, m128/m64bcst",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
						.Type = OperandType::M128M64Bcst,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::M128M64Bcst},
							.X = {OperandType::M128M64Bcst},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M128M64Bcst},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 16,
						},
						OpCode
						{
							.Value = 0xfb,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M128M64Bcst},
							.Rm = {OperandType::M128M64Bcst},
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubq",
				.GasMnemonic = "vpsubq",
				.Description = "vpsubq xmm{k}{z}, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
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
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubq",
				.GasMnemonic = "vpsubq",
				.Description = "vpsubq ymm{k}{z}, ymm, m256/m64bcst",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256M64Bcst,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::M256M64Bcst},
							.X = {OperandType::M256M64Bcst},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::M256M64Bcst},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0xfb,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256M64Bcst},
							.Rm = {OperandType::M256M64Bcst},
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubq",
				.GasMnemonic = "vpsubq",
				.Description = "vpsubq ymm{k}{z}, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::Ymm},
							.X = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::Ymm},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0xfb,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubq",
				.GasMnemonic = "vpsubq",
				.Description = "vpsubq zmm{k}{z}, zmm, m512/m64bcst",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M512M64Bcst,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::M512M64Bcst},
							.X = {OperandType::M512M64Bcst},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::M512M64Bcst},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 64,
						},
						OpCode
						{
							.Value = 0xfb,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M512M64Bcst},
							.Rm = {OperandType::M512M64Bcst},
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubq",
				.GasMnemonic = "vpsubq",
				.Description = "vpsubq zmm{k}{z}, zmm, zmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::Zmm},
							.X = {OperandType::Zmm},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::Zmm},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0xfb,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Zmm},
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubq",
				.GasMnemonic = "vpsubq",
				.Description = "vpsubq xmm, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
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
					IsaExtension::Avx,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {OperandType::Xmm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
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
				.IntelMnemonic = "vpsubq",
				.GasMnemonic = "vpsubq",
				.Description = "vpsubq xmm, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {OperandType::Xmm},
							.X = {OperandType::M128},
							.B = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
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
			InstructionVariation
			{
				.IntelMnemonic = "vpsubq",
				.GasMnemonic = "vpsubq",
				.Description = "vpsubq ymm, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = true,
							.R = {OperandType::Ymm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0xfb,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
							.Reg = {OperandType::Ymm},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubq",
				.GasMnemonic = "vpsubq",
				.Description = "vpsubq ymm, ymm, m256",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = true,
							.R = {OperandType::Ymm},
							.X = {OperandType::M256},
							.B = {OperandType::M256},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0xfb,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256},
							.Rm = {OperandType::M256},
							.Reg = {OperandType::Ymm},
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
				.IntelMnemonic = "vpsubsb",
				.GasMnemonic = "vpsubsb",
				.Description = "vpsubsb xmm{k}{z}, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
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
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubsb",
				.GasMnemonic = "vpsubsb",
				.Description = "vpsubsb xmm{k}{z}, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M128},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 16,
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
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubsb",
				.GasMnemonic = "vpsubsb",
				.Description = "vpsubsb ymm{k}{z}, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::Ymm},
							.X = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::Ymm},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0xe8,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubsb",
				.GasMnemonic = "vpsubsb",
				.Description = "vpsubsb ymm{k}{z}, ymm, m256",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::M256},
							.X = {OperandType::M256},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::M256},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0xe8,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256},
							.Rm = {OperandType::M256},
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubsb",
				.GasMnemonic = "vpsubsb",
				.Description = "vpsubsb zmm{k}{z}, zmm, zmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::Zmm},
							.X = {OperandType::Zmm},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::Zmm},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0xe8,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Zmm},
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubsb",
				.GasMnemonic = "vpsubsb",
				.Description = "vpsubsb zmm{k}{z}, zmm, m512",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M512,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::M512},
							.X = {OperandType::M512},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::M512},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 64,
						},
						OpCode
						{
							.Value = 0xe8,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M512},
							.Rm = {OperandType::M512},
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubsb",
				.GasMnemonic = "vpsubsb",
				.Description = "vpsubsb xmm, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
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
					IsaExtension::Avx,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {OperandType::Xmm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
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
				.IntelMnemonic = "vpsubsb",
				.GasMnemonic = "vpsubsb",
				.Description = "vpsubsb xmm, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {OperandType::Xmm},
							.X = {OperandType::M128},
							.B = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
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
			InstructionVariation
			{
				.IntelMnemonic = "vpsubsb",
				.GasMnemonic = "vpsubsb",
				.Description = "vpsubsb ymm, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = true,
							.R = {OperandType::Ymm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0xe8,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
							.Reg = {OperandType::Ymm},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubsb",
				.GasMnemonic = "vpsubsb",
				.Description = "vpsubsb ymm, ymm, m256",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = true,
							.R = {OperandType::Ymm},
							.X = {OperandType::M256},
							.B = {OperandType::M256},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0xe8,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256},
							.Rm = {OperandType::M256},
							.Reg = {OperandType::Ymm},
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
				.IntelMnemonic = "vpsubsw",
				.GasMnemonic = "vpsubsw",
				.Description = "vpsubsw xmm{k}{z}, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
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
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubsw",
				.GasMnemonic = "vpsubsw",
				.Description = "vpsubsw xmm{k}{z}, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M128},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 16,
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
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubsw",
				.GasMnemonic = "vpsubsw",
				.Description = "vpsubsw ymm{k}{z}, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::Ymm},
							.X = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::Ymm},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0xe9,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubsw",
				.GasMnemonic = "vpsubsw",
				.Description = "vpsubsw ymm{k}{z}, ymm, m256",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::M256},
							.X = {OperandType::M256},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::M256},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0xe9,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256},
							.Rm = {OperandType::M256},
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubsw",
				.GasMnemonic = "vpsubsw",
				.Description = "vpsubsw zmm{k}{z}, zmm, zmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::Zmm},
							.X = {OperandType::Zmm},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::Zmm},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0xe9,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Zmm},
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubsw",
				.GasMnemonic = "vpsubsw",
				.Description = "vpsubsw zmm{k}{z}, zmm, m512",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M512,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::M512},
							.X = {OperandType::M512},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::M512},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 64,
						},
						OpCode
						{
							.Value = 0xe9,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M512},
							.Rm = {OperandType::M512},
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubsw",
				.GasMnemonic = "vpsubsw",
				.Description = "vpsubsw xmm, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
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
					IsaExtension::Avx,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {OperandType::Xmm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
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
				.IntelMnemonic = "vpsubsw",
				.GasMnemonic = "vpsubsw",
				.Description = "vpsubsw xmm, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {OperandType::Xmm},
							.X = {OperandType::M128},
							.B = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
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
			InstructionVariation
			{
				.IntelMnemonic = "vpsubsw",
				.GasMnemonic = "vpsubsw",
				.Description = "vpsubsw ymm, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = true,
							.R = {OperandType::Ymm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0xe9,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
							.Reg = {OperandType::Ymm},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubsw",
				.GasMnemonic = "vpsubsw",
				.Description = "vpsubsw ymm, ymm, m256",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = true,
							.R = {OperandType::Ymm},
							.X = {OperandType::M256},
							.B = {OperandType::M256},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0xe9,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256},
							.Rm = {OperandType::M256},
							.Reg = {OperandType::Ymm},
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
				.IntelMnemonic = "vpsubusb",
				.GasMnemonic = "vpsubusb",
				.Description = "vpsubusb xmm{k}{z}, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
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
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubusb",
				.GasMnemonic = "vpsubusb",
				.Description = "vpsubusb xmm{k}{z}, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M128},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 16,
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
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubusb",
				.GasMnemonic = "vpsubusb",
				.Description = "vpsubusb ymm{k}{z}, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::Ymm},
							.X = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::Ymm},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0xd8,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubusb",
				.GasMnemonic = "vpsubusb",
				.Description = "vpsubusb ymm{k}{z}, ymm, m256",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::M256},
							.X = {OperandType::M256},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::M256},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0xd8,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256},
							.Rm = {OperandType::M256},
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubusb",
				.GasMnemonic = "vpsubusb",
				.Description = "vpsubusb zmm{k}{z}, zmm, zmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::Zmm},
							.X = {OperandType::Zmm},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::Zmm},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0xd8,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Zmm},
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubusb",
				.GasMnemonic = "vpsubusb",
				.Description = "vpsubusb zmm{k}{z}, zmm, m512",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M512,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::M512},
							.X = {OperandType::M512},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::M512},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 64,
						},
						OpCode
						{
							.Value = 0xd8,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M512},
							.Rm = {OperandType::M512},
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubusb",
				.GasMnemonic = "vpsubusb",
				.Description = "vpsubusb xmm, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
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
					IsaExtension::Avx,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {OperandType::Xmm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
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
				.IntelMnemonic = "vpsubusb",
				.GasMnemonic = "vpsubusb",
				.Description = "vpsubusb xmm, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {OperandType::Xmm},
							.X = {OperandType::M128},
							.B = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
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
			InstructionVariation
			{
				.IntelMnemonic = "vpsubusb",
				.GasMnemonic = "vpsubusb",
				.Description = "vpsubusb ymm, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = true,
							.R = {OperandType::Ymm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0xd8,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
							.Reg = {OperandType::Ymm},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubusb",
				.GasMnemonic = "vpsubusb",
				.Description = "vpsubusb ymm, ymm, m256",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = true,
							.R = {OperandType::Ymm},
							.X = {OperandType::M256},
							.B = {OperandType::M256},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0xd8,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256},
							.Rm = {OperandType::M256},
							.Reg = {OperandType::Ymm},
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
				.IntelMnemonic = "vpsubusw",
				.GasMnemonic = "vpsubusw",
				.Description = "vpsubusw xmm{k}{z}, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
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
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubusw",
				.GasMnemonic = "vpsubusw",
				.Description = "vpsubusw xmm{k}{z}, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M128},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 16,
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
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubusw",
				.GasMnemonic = "vpsubusw",
				.Description = "vpsubusw ymm{k}{z}, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::Ymm},
							.X = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::Ymm},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0xd9,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubusw",
				.GasMnemonic = "vpsubusw",
				.Description = "vpsubusw ymm{k}{z}, ymm, m256",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::M256},
							.X = {OperandType::M256},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::M256},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0xd9,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256},
							.Rm = {OperandType::M256},
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubusw",
				.GasMnemonic = "vpsubusw",
				.Description = "vpsubusw zmm{k}{z}, zmm, zmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::Zmm},
							.X = {OperandType::Zmm},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::Zmm},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0xd9,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Zmm},
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubusw",
				.GasMnemonic = "vpsubusw",
				.Description = "vpsubusw zmm{k}{z}, zmm, m512",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M512,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::M512},
							.X = {OperandType::M512},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::M512},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 64,
						},
						OpCode
						{
							.Value = 0xd9,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M512},
							.Rm = {OperandType::M512},
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubusw",
				.GasMnemonic = "vpsubusw",
				.Description = "vpsubusw xmm, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
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
					IsaExtension::Avx,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {OperandType::Xmm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
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
				.IntelMnemonic = "vpsubusw",
				.GasMnemonic = "vpsubusw",
				.Description = "vpsubusw xmm, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {OperandType::Xmm},
							.X = {OperandType::M128},
							.B = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
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
			InstructionVariation
			{
				.IntelMnemonic = "vpsubusw",
				.GasMnemonic = "vpsubusw",
				.Description = "vpsubusw ymm, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = true,
							.R = {OperandType::Ymm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0xd9,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
							.Reg = {OperandType::Ymm},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubusw",
				.GasMnemonic = "vpsubusw",
				.Description = "vpsubusw ymm, ymm, m256",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = true,
							.R = {OperandType::Ymm},
							.X = {OperandType::M256},
							.B = {OperandType::M256},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0xd9,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256},
							.Rm = {OperandType::M256},
							.Reg = {OperandType::Ymm},
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
				.IntelMnemonic = "vpsubw",
				.GasMnemonic = "vpsubw",
				.Description = "vpsubw xmm{k}{z}, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
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
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubw",
				.GasMnemonic = "vpsubw",
				.Description = "vpsubw xmm{k}{z}, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M128},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 16,
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
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubw",
				.GasMnemonic = "vpsubw",
				.Description = "vpsubw ymm{k}{z}, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::Ymm},
							.X = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::Ymm},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0xf9,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubw",
				.GasMnemonic = "vpsubw",
				.Description = "vpsubw ymm{k}{z}, ymm, m256",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::M256},
							.X = {OperandType::M256},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::M256},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0xf9,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256},
							.Rm = {OperandType::M256},
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubw",
				.GasMnemonic = "vpsubw",
				.Description = "vpsubw zmm{k}{z}, zmm, zmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::Zmm},
							.X = {OperandType::Zmm},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::Zmm},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0xf9,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Zmm},
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubw",
				.GasMnemonic = "vpsubw",
				.Description = "vpsubw zmm{k}{z}, zmm, m512",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M512,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Bw,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::M512},
							.X = {OperandType::M512},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::M512},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 64,
						},
						OpCode
						{
							.Value = 0xf9,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M512},
							.Rm = {OperandType::M512},
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubw",
				.GasMnemonic = "vpsubw",
				.Description = "vpsubw xmm, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
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
					IsaExtension::Avx,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {OperandType::Xmm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
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
				.IntelMnemonic = "vpsubw",
				.GasMnemonic = "vpsubw",
				.Description = "vpsubw xmm, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Avx,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {OperandType::Xmm},
							.X = {OperandType::M128},
							.B = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
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
			InstructionVariation
			{
				.IntelMnemonic = "vpsubw",
				.GasMnemonic = "vpsubw",
				.Description = "vpsubw ymm, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = true,
							.R = {OperandType::Ymm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0xf9,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
							.Reg = {OperandType::Ymm},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpsubw",
				.GasMnemonic = "vpsubw",
				.Description = "vpsubw ymm, ymm, m256",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx2,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Vex
						{
							.Type = VexPrefixType::Vex,
							.Mmmmm = 0b1,
							.Pp = 0b1,
							.W = false,
							.L = true,
							.R = {OperandType::Ymm},
							.X = {OperandType::M256},
							.B = {OperandType::M256},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0xf9,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256},
							.Rm = {OperandType::M256},
							.Reg = {OperandType::Ymm},
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
				.IntelMnemonic = "vpternlogd",
				.GasMnemonic = "vpternlogd",
				.Description = "vpternlogd xmm{k}{z}, xmm, m128/m32bcst, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
						.Type = OperandType::M128M32Bcst,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b11,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::M128M32Bcst},
							.X = {OperandType::M128M32Bcst},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M128M32Bcst},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 16,
						},
						OpCode
						{
							.Value = 0x25,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M128M32Bcst},
							.Rm = {OperandType::M128M32Bcst},
							.Reg = {OperandType::XmmKz},
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
				.IntelMnemonic = "vpternlogd",
				.GasMnemonic = "vpternlogd",
				.Description = "vpternlogd xmm{k}{z}, xmm, xmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::XmmKz,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b11,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x25,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Xmm},
							.Reg = {OperandType::XmmKz},
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
				.IntelMnemonic = "vpternlogd",
				.GasMnemonic = "vpternlogd",
				.Description = "vpternlogd ymm{k}{z}, ymm, m256/m32bcst, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = true,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M256M32Bcst,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b11,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::M256M32Bcst},
							.X = {OperandType::M256M32Bcst},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::M256M32Bcst},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0x25,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256M32Bcst},
							.Rm = {OperandType::M256M32Bcst},
							.Reg = {OperandType::YmmKz},
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
				.IntelMnemonic = "vpternlogd",
				.GasMnemonic = "vpternlogd",
				.Description = "vpternlogd ymm{k}{z}, ymm, ymm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::YmmKz,
						.IsInput = true,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Avx512Vl,
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b11,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::YmmKz},
							.Bb = {OperandType::Ymm},
							.X = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::Ymm},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x25,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
							.Reg = {OperandType::YmmKz},
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
				.IntelMnemonic = "vpternlogd",
				.GasMnemonic = "vpternlogd",
				.Description = "vpternlogd zmm{k}{z}, zmm, m512/m32bcst, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = true,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::M512M32Bcst,
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
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b11,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::M512M32Bcst},
							.X = {OperandType::M512M32Bcst},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::M512M32Bcst},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 64,
						},
						OpCode
						{
							.Value = 0x25,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M512M32Bcst},
							.Rm = {OperandType::M512M32Bcst},
							.Reg = {OperandType::ZmmKz},
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
				.IntelMnemonic = "vpternlogd",
				.GasMnemonic = "vpternlogd",
				.Description = "vpternlogd zmm{k}{z}, zmm, zmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::ZmmKz,
						.IsInput = true,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Zmm,
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
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b11,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::Zmm},
							.X = {OperandType::Zmm},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::Zmm},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x25,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Zmm},
							.Reg = {OperandType::ZmmKz},
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
	};
}
