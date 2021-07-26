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
NOX_NEVER_INLINE NOX_COLD auto GetVariationTable_30(std::pmr::monotonic_buffer_resource& allocator, std::pmr::vector<InstructionVariationPool>& out) -> void
{
	std::pmr::vector<InstructionVariation> instruction{&allocator};
	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "vphsubd",
			.GasMnemonic = "vphsubd",
			.Description = "vphsubd xmm, xmm, xmm",
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
						.Value = 0x6,
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
			.IntelMnemonic = "vphsubd",
			.GasMnemonic = "vphsubd",
			.Description = "vphsubd xmm, xmm, m128",
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
						.Value = 0x6,
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
			.IntelMnemonic = "vphsubd",
			.GasMnemonic = "vphsubd",
			.Description = "vphsubd ymm, ymm, ymm",
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
						.Value = 0x6,
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
			.IntelMnemonic = "vphsubd",
			.GasMnemonic = "vphsubd",
			.Description = "vphsubd ymm, ymm, m256",
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
						.Value = 0x6,
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
			.IntelMnemonic = "vphsubdq",
			.GasMnemonic = "vphsubdq",
			.Description = "vphsubdq xmm, xmm",
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
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Xop,
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
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xe3,
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
			.IntelMnemonic = "vphsubdq",
			.GasMnemonic = "vphsubdq",
			.Description = "vphsubdq xmm, m128",
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
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Xop,
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
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xe3,
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
			.IntelMnemonic = "vphsubsw",
			.GasMnemonic = "vphsubsw",
			.Description = "vphsubsw xmm, xmm, xmm",
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
						.Value = 0x7,
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
			.IntelMnemonic = "vphsubsw",
			.GasMnemonic = "vphsubsw",
			.Description = "vphsubsw xmm, xmm, m128",
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
						.Value = 0x7,
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
			.IntelMnemonic = "vphsubsw",
			.GasMnemonic = "vphsubsw",
			.Description = "vphsubsw ymm, ymm, ymm",
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
						.Value = 0x7,
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
			.IntelMnemonic = "vphsubsw",
			.GasMnemonic = "vphsubsw",
			.Description = "vphsubsw ymm, ymm, m256",
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
						.Value = 0x7,
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
			.IntelMnemonic = "vphsubw",
			.GasMnemonic = "vphsubw",
			.Description = "vphsubw xmm, xmm, xmm",
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
						.Value = 0x5,
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
			.IntelMnemonic = "vphsubw",
			.GasMnemonic = "vphsubw",
			.Description = "vphsubw xmm, xmm, m128",
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
						.Value = 0x5,
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
			.IntelMnemonic = "vphsubw",
			.GasMnemonic = "vphsubw",
			.Description = "vphsubw ymm, ymm, ymm",
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
						.Value = 0x5,
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
			.IntelMnemonic = "vphsubw",
			.GasMnemonic = "vphsubw",
			.Description = "vphsubw ymm, ymm, m256",
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
						.Value = 0x5,
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
			.IntelMnemonic = "vphsubwd",
			.GasMnemonic = "vphsubwd",
			.Description = "vphsubwd xmm, xmm",
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
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Xop,
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
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
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
			.IntelMnemonic = "vphsubwd",
			.GasMnemonic = "vphsubwd",
			.Description = "vphsubwd xmm, m128",
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
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Xop,
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
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.Vvvv = {UINT64_C(0x0)},
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
			.IntelMnemonic = "vpinsrb",
			.GasMnemonic = "vpinsrb",
			.Description = "vpinsrb xmm, xmm, r32, imm8",
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
				IsaExtension::Avx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Vex
					{
						.Type = VexPrefixType::Vex,
						.Mmmmm = 0b11,
						.Pp = 0b1,
						.W = false,
						.L = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R32},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0x20,
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
			.IntelMnemonic = "vpinsrb",
			.GasMnemonic = "vpinsrb",
			.Description = "vpinsrb xmm, xmm, r32, imm8",
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
				IsaExtension::Avx512Bw,
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
						.Rr = {OperandType::Xmm},
						.Bb = {OperandType::R32},
						.X = {OperandType::R32},
						.Vvvv = {OperandType::Xmm},
						.V = {OperandType::Xmm},
						.B = {OperandType::R32},
						.Aaa = {UINT64_C(0x0)},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 0,
					},
					OpCode
					{
						.Value = 0x20,
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
			.IntelMnemonic = "vpinsrb",
			.GasMnemonic = "vpinsrb",
			.Description = "vpinsrb xmm, xmm, m8, imm8",
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
				IsaExtension::Avx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Vex
					{
						.Type = VexPrefixType::Vex,
						.Mmmmm = 0b11,
						.Pp = 0b1,
						.W = false,
						.L = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M8},
						.B = {OperandType::M8},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0x20,
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
		InstructionVariation
		{
			.IntelMnemonic = "vpinsrb",
			.GasMnemonic = "vpinsrb",
			.Description = "vpinsrb xmm, xmm, m8, imm8",
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
				IsaExtension::Avx512Bw,
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
						.Rr = {OperandType::Xmm},
						.Bb = {OperandType::M8},
						.X = {OperandType::M8},
						.Vvvv = {OperandType::Xmm},
						.V = {OperandType::Xmm},
						.B = {OperandType::M8},
						.Aaa = {UINT64_C(0x0)},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 1,
					},
					OpCode
					{
						.Value = 0x20,
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
			.IntelMnemonic = "vpinsrd",
			.GasMnemonic = "vpinsrd",
			.Description = "vpinsrd xmm, xmm, r32, imm8",
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
				IsaExtension::Avx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Vex
					{
						.Type = VexPrefixType::Vex,
						.Mmmmm = 0b11,
						.Pp = 0b1,
						.W = false,
						.L = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R32},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0x22,
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
			.IntelMnemonic = "vpinsrd",
			.GasMnemonic = "vpinsrd",
			.Description = "vpinsrd xmm, xmm, r32, imm8",
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
				IsaExtension::Avx512Dq,
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
						.Rr = {OperandType::Xmm},
						.Bb = {OperandType::R32},
						.X = {OperandType::R32},
						.Vvvv = {OperandType::Xmm},
						.V = {OperandType::Xmm},
						.B = {OperandType::R32},
						.Aaa = {UINT64_C(0x0)},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 0,
					},
					OpCode
					{
						.Value = 0x22,
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
			.IntelMnemonic = "vpinsrd",
			.GasMnemonic = "vpinsrd",
			.Description = "vpinsrd xmm, xmm, m32, imm8",
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
				IsaExtension::Avx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Vex
					{
						.Type = VexPrefixType::Vex,
						.Mmmmm = 0b11,
						.Pp = 0b1,
						.W = false,
						.L = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M32},
						.B = {OperandType::M32},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0x22,
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
		InstructionVariation
		{
			.IntelMnemonic = "vpinsrd",
			.GasMnemonic = "vpinsrd",
			.Description = "vpinsrd xmm, xmm, m32, imm8",
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
				IsaExtension::Avx512Dq,
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
						.Rr = {OperandType::Xmm},
						.Bb = {OperandType::M32},
						.X = {OperandType::M32},
						.Vvvv = {OperandType::Xmm},
						.V = {OperandType::Xmm},
						.B = {OperandType::M32},
						.Aaa = {UINT64_C(0x0)},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 4,
					},
					OpCode
					{
						.Value = 0x22,
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
			.IntelMnemonic = "vpinsrq",
			.GasMnemonic = "vpinsrq",
			.Description = "vpinsrq xmm, xmm, r64, imm8",
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
				IsaExtension::Avx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Vex
					{
						.Type = VexPrefixType::Vex,
						.Mmmmm = 0b11,
						.Pp = 0b1,
						.W = true,
						.L = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R64},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0x22,
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
			.IntelMnemonic = "vpinsrq",
			.GasMnemonic = "vpinsrq",
			.Description = "vpinsrq xmm, xmm, r64, imm8",
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
				IsaExtension::Avx512Dq,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Evex
					{
						.Mm = 0b11,
						.Pp = 0b1,
						.W = true,
						.Ll = UINT64_C(0x0),
						.Rr = {OperandType::Xmm},
						.Bb = {OperandType::R64},
						.X = {OperandType::R64},
						.Vvvv = {OperandType::Xmm},
						.V = {OperandType::Xmm},
						.B = {OperandType::R64},
						.Aaa = {UINT64_C(0x0)},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 0,
					},
					OpCode
					{
						.Value = 0x22,
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
			.IntelMnemonic = "vpinsrq",
			.GasMnemonic = "vpinsrq",
			.Description = "vpinsrq xmm, xmm, m64, imm8",
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
				IsaExtension::Avx,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Vex
					{
						.Type = VexPrefixType::Vex,
						.Mmmmm = 0b11,
						.Pp = 0b1,
						.W = true,
						.L = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0x22,
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
		InstructionVariation
		{
			.IntelMnemonic = "vpinsrq",
			.GasMnemonic = "vpinsrq",
			.Description = "vpinsrq xmm, xmm, m64, imm8",
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
				IsaExtension::Avx512Dq,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Evex
					{
						.Mm = 0b11,
						.Pp = 0b1,
						.W = true,
						.Ll = UINT64_C(0x0),
						.Rr = {OperandType::Xmm},
						.Bb = {OperandType::M64},
						.X = {OperandType::M64},
						.Vvvv = {OperandType::Xmm},
						.V = {OperandType::Xmm},
						.B = {OperandType::M64},
						.Aaa = {UINT64_C(0x0)},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 8,
					},
					OpCode
					{
						.Value = 0x22,
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
			.IntelMnemonic = "vpinsrw",
			.GasMnemonic = "vpinsrw",
			.Description = "vpinsrw xmm, xmm, r32, imm8",
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
						.B = {OperandType::R32},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0xc4,
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
			.IntelMnemonic = "vpinsrw",
			.GasMnemonic = "vpinsrw",
			.Description = "vpinsrw xmm, xmm, r32, imm8",
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
						.Rr = {OperandType::Xmm},
						.Bb = {OperandType::R32},
						.X = {OperandType::R32},
						.Vvvv = {OperandType::Xmm},
						.V = {OperandType::Xmm},
						.B = {OperandType::R32},
						.Aaa = {UINT64_C(0x0)},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 0,
					},
					OpCode
					{
						.Value = 0xc4,
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
			.IntelMnemonic = "vpinsrw",
			.GasMnemonic = "vpinsrw",
			.Description = "vpinsrw xmm, xmm, m16, imm8",
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
					.Type = OperandType::M16,
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
						.R = {OperandType::Xmm},
						.X = {OperandType::M16},
						.B = {OperandType::M16},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0xc4,
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
		InstructionVariation
		{
			.IntelMnemonic = "vpinsrw",
			.GasMnemonic = "vpinsrw",
			.Description = "vpinsrw xmm, xmm, m16, imm8",
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
					.Type = OperandType::M16,
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
						.Ll = UINT64_C(0x0),
						.Rr = {OperandType::Xmm},
						.Bb = {OperandType::M16},
						.X = {OperandType::M16},
						.Vvvv = {OperandType::Xmm},
						.V = {OperandType::Xmm},
						.B = {OperandType::M16},
						.Aaa = {UINT64_C(0x0)},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 2,
					},
					OpCode
					{
						.Value = 0xc4,
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
			.IntelMnemonic = "vplzcntd",
			.GasMnemonic = "vplzcntd",
			.Description = "vplzcntd xmm{k}{z}, m128/m32bcst",
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
				IsaExtension::Avx512Cd,
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
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M128M32Bcst},
						.Aaa = {OperandType::XmmKz},
						.Z = {OperandType::XmmKz},
						.Disp8xN = 16,
					},
					OpCode
					{
						.Value = 0x44,
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
			.IntelMnemonic = "vplzcntd",
			.GasMnemonic = "vplzcntd",
			.Description = "vplzcntd ymm{k}{z}, m256/m32bcst",
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
				IsaExtension::Avx512Cd,
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
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M256M32Bcst},
						.Aaa = {OperandType::YmmKz},
						.Z = {OperandType::YmmKz},
						.Disp8xN = 32,
					},
					OpCode
					{
						.Value = 0x44,
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
			.IntelMnemonic = "vplzcntd",
			.GasMnemonic = "vplzcntd",
			.Description = "vplzcntd zmm{k}{z}, m512/m32bcst",
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
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Avx512Cd,
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
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M512M32Bcst},
						.Aaa = {OperandType::ZmmKz},
						.Z = {OperandType::ZmmKz},
						.Disp8xN = 64,
					},
					OpCode
					{
						.Value = 0x44,
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
			.IntelMnemonic = "vplzcntd",
			.GasMnemonic = "vplzcntd",
			.Description = "vplzcntd xmm{k}{z}, xmm",
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
				IsaExtension::Avx512Cd,
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
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Aaa = {OperandType::XmmKz},
						.Z = {OperandType::XmmKz},
						.Disp8xN = 0,
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
						.Reg = {OperandType::XmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vplzcntd",
			.GasMnemonic = "vplzcntd",
			.Description = "vplzcntd ymm{k}{z}, ymm",
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
				IsaExtension::Avx512Cd,
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
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Ymm},
						.Aaa = {OperandType::YmmKz},
						.Z = {OperandType::YmmKz},
						.Disp8xN = 0,
					},
					OpCode
					{
						.Value = 0x44,
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
			.IntelMnemonic = "vplzcntd",
			.GasMnemonic = "vplzcntd",
			.Description = "vplzcntd zmm{k}{z}, zmm",
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
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Avx512Cd,
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
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Zmm},
						.Aaa = {OperandType::ZmmKz},
						.Z = {OperandType::ZmmKz},
						.Disp8xN = 0,
					},
					OpCode
					{
						.Value = 0x44,
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
			.IntelMnemonic = "vplzcntq",
			.GasMnemonic = "vplzcntq",
			.Description = "vplzcntq xmm{k}{z}, m128/m64bcst",
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
				IsaExtension::Avx512Cd,
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
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M128M64Bcst},
						.Aaa = {OperandType::XmmKz},
						.Z = {OperandType::XmmKz},
						.Disp8xN = 16,
					},
					OpCode
					{
						.Value = 0x44,
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
			.IntelMnemonic = "vplzcntq",
			.GasMnemonic = "vplzcntq",
			.Description = "vplzcntq ymm{k}{z}, m256/m64bcst",
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
				IsaExtension::Avx512Cd,
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
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M256M64Bcst},
						.Aaa = {OperandType::YmmKz},
						.Z = {OperandType::YmmKz},
						.Disp8xN = 32,
					},
					OpCode
					{
						.Value = 0x44,
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
			.IntelMnemonic = "vplzcntq",
			.GasMnemonic = "vplzcntq",
			.Description = "vplzcntq zmm{k}{z}, m512/m64bcst",
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
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Avx512Cd,
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
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M512M64Bcst},
						.Aaa = {OperandType::ZmmKz},
						.Z = {OperandType::ZmmKz},
						.Disp8xN = 64,
					},
					OpCode
					{
						.Value = 0x44,
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
			.IntelMnemonic = "vplzcntq",
			.GasMnemonic = "vplzcntq",
			.Description = "vplzcntq xmm{k}{z}, xmm",
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
				IsaExtension::Avx512Cd,
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
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Aaa = {OperandType::XmmKz},
						.Z = {OperandType::XmmKz},
						.Disp8xN = 0,
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
						.Reg = {OperandType::XmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vplzcntq",
			.GasMnemonic = "vplzcntq",
			.Description = "vplzcntq ymm{k}{z}, ymm",
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
				IsaExtension::Avx512Cd,
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
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Ymm},
						.Aaa = {OperandType::YmmKz},
						.Z = {OperandType::YmmKz},
						.Disp8xN = 0,
					},
					OpCode
					{
						.Value = 0x44,
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
			.IntelMnemonic = "vplzcntq",
			.GasMnemonic = "vplzcntq",
			.Description = "vplzcntq zmm{k}{z}, zmm",
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
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Avx512Cd,
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
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Zmm},
						.Aaa = {OperandType::ZmmKz},
						.Z = {OperandType::ZmmKz},
						.Disp8xN = 0,
					},
					OpCode
					{
						.Value = 0x44,
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
			.IntelMnemonic = "vpmacsdd",
			.GasMnemonic = "vpmacsdd",
			.Description = "vpmacsdd xmm, xmm, xmm, xmm",
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
				IsaExtension::Xop,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Vex
					{
						.Type = VexPrefixType::Xop,
						.Mmmmm = 0b1000,
						.Pp = 0b0,
						.W = false,
						.L = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0x9e,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
					RegisterByte
					{
						.Register = OperandType::Xmm,
						.Payload = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmacsdd",
			.GasMnemonic = "vpmacsdd",
			.Description = "vpmacsdd xmm, xmm, m128, xmm",
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
				IsaExtension::Xop,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Vex
					{
						.Type = VexPrefixType::Xop,
						.Mmmmm = 0b1000,
						.Pp = 0b0,
						.W = false,
						.L = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0x9e,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
					RegisterByte
					{
						.Register = OperandType::Xmm,
						.Payload = {UINT64_C(0x0)},
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
			.IntelMnemonic = "vpmacsdqh",
			.GasMnemonic = "vpmacsdqh",
			.Description = "vpmacsdqh xmm, xmm, xmm, xmm",
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
				IsaExtension::Xop,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Vex
					{
						.Type = VexPrefixType::Xop,
						.Mmmmm = 0b1000,
						.Pp = 0b0,
						.W = false,
						.L = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0x9f,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
					RegisterByte
					{
						.Register = OperandType::Xmm,
						.Payload = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmacsdqh",
			.GasMnemonic = "vpmacsdqh",
			.Description = "vpmacsdqh xmm, xmm, m128, xmm",
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
				IsaExtension::Xop,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Vex
					{
						.Type = VexPrefixType::Xop,
						.Mmmmm = 0b1000,
						.Pp = 0b0,
						.W = false,
						.L = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0x9f,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
					RegisterByte
					{
						.Register = OperandType::Xmm,
						.Payload = {UINT64_C(0x0)},
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
			.IntelMnemonic = "vpmacsdql",
			.GasMnemonic = "vpmacsdql",
			.Description = "vpmacsdql xmm, xmm, xmm, xmm",
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
				IsaExtension::Xop,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Vex
					{
						.Type = VexPrefixType::Xop,
						.Mmmmm = 0b1000,
						.Pp = 0b0,
						.W = false,
						.L = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0x97,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
					RegisterByte
					{
						.Register = OperandType::Xmm,
						.Payload = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmacsdql",
			.GasMnemonic = "vpmacsdql",
			.Description = "vpmacsdql xmm, xmm, m128, xmm",
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
				IsaExtension::Xop,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Vex
					{
						.Type = VexPrefixType::Xop,
						.Mmmmm = 0b1000,
						.Pp = 0b0,
						.W = false,
						.L = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0x97,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
					RegisterByte
					{
						.Register = OperandType::Xmm,
						.Payload = {UINT64_C(0x0)},
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
			.IntelMnemonic = "vpmacssdd",
			.GasMnemonic = "vpmacssdd",
			.Description = "vpmacssdd xmm, xmm, xmm, xmm",
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
				IsaExtension::Xop,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Vex
					{
						.Type = VexPrefixType::Xop,
						.Mmmmm = 0b1000,
						.Pp = 0b0,
						.W = false,
						.L = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0x8e,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
					RegisterByte
					{
						.Register = OperandType::Xmm,
						.Payload = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmacssdd",
			.GasMnemonic = "vpmacssdd",
			.Description = "vpmacssdd xmm, xmm, m128, xmm",
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
				IsaExtension::Xop,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Vex
					{
						.Type = VexPrefixType::Xop,
						.Mmmmm = 0b1000,
						.Pp = 0b0,
						.W = false,
						.L = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0x8e,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
					RegisterByte
					{
						.Register = OperandType::Xmm,
						.Payload = {UINT64_C(0x0)},
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
			.IntelMnemonic = "vpmacssdqh",
			.GasMnemonic = "vpmacssdqh",
			.Description = "vpmacssdqh xmm, xmm, xmm, xmm",
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
				IsaExtension::Xop,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Vex
					{
						.Type = VexPrefixType::Xop,
						.Mmmmm = 0b1000,
						.Pp = 0b0,
						.W = false,
						.L = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0x8f,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
					RegisterByte
					{
						.Register = OperandType::Xmm,
						.Payload = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmacssdqh",
			.GasMnemonic = "vpmacssdqh",
			.Description = "vpmacssdqh xmm, xmm, m128, xmm",
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
				IsaExtension::Xop,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Vex
					{
						.Type = VexPrefixType::Xop,
						.Mmmmm = 0b1000,
						.Pp = 0b0,
						.W = false,
						.L = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0x8f,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
					RegisterByte
					{
						.Register = OperandType::Xmm,
						.Payload = {UINT64_C(0x0)},
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
			.IntelMnemonic = "vpmacssdql",
			.GasMnemonic = "vpmacssdql",
			.Description = "vpmacssdql xmm, xmm, xmm, xmm",
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
				IsaExtension::Xop,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Vex
					{
						.Type = VexPrefixType::Xop,
						.Mmmmm = 0b1000,
						.Pp = 0b0,
						.W = false,
						.L = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0x87,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
					RegisterByte
					{
						.Register = OperandType::Xmm,
						.Payload = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmacssdql",
			.GasMnemonic = "vpmacssdql",
			.Description = "vpmacssdql xmm, xmm, m128, xmm",
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
				IsaExtension::Xop,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Vex
					{
						.Type = VexPrefixType::Xop,
						.Mmmmm = 0b1000,
						.Pp = 0b0,
						.W = false,
						.L = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0x87,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
					RegisterByte
					{
						.Register = OperandType::Xmm,
						.Payload = {UINT64_C(0x0)},
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
			.IntelMnemonic = "vpmacsswd",
			.GasMnemonic = "vpmacsswd",
			.Description = "vpmacsswd xmm, xmm, xmm, xmm",
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
				IsaExtension::Xop,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Vex
					{
						.Type = VexPrefixType::Xop,
						.Mmmmm = 0b1000,
						.Pp = 0b0,
						.W = false,
						.L = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0x86,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
					RegisterByte
					{
						.Register = OperandType::Xmm,
						.Payload = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmacsswd",
			.GasMnemonic = "vpmacsswd",
			.Description = "vpmacsswd xmm, xmm, m128, xmm",
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
				IsaExtension::Xop,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Vex
					{
						.Type = VexPrefixType::Xop,
						.Mmmmm = 0b1000,
						.Pp = 0b0,
						.W = false,
						.L = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0x86,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
					RegisterByte
					{
						.Register = OperandType::Xmm,
						.Payload = {UINT64_C(0x0)},
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
			.IntelMnemonic = "vpmacssww",
			.GasMnemonic = "vpmacssww",
			.Description = "vpmacssww xmm, xmm, xmm, xmm",
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
				IsaExtension::Xop,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Vex
					{
						.Type = VexPrefixType::Xop,
						.Mmmmm = 0b1000,
						.Pp = 0b0,
						.W = false,
						.L = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0x85,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
					RegisterByte
					{
						.Register = OperandType::Xmm,
						.Payload = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmacssww",
			.GasMnemonic = "vpmacssww",
			.Description = "vpmacssww xmm, xmm, m128, xmm",
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
				IsaExtension::Xop,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Vex
					{
						.Type = VexPrefixType::Xop,
						.Mmmmm = 0b1000,
						.Pp = 0b0,
						.W = false,
						.L = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0x85,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
					RegisterByte
					{
						.Register = OperandType::Xmm,
						.Payload = {UINT64_C(0x0)},
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
			.IntelMnemonic = "vpmacswd",
			.GasMnemonic = "vpmacswd",
			.Description = "vpmacswd xmm, xmm, xmm, xmm",
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
				IsaExtension::Xop,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Vex
					{
						.Type = VexPrefixType::Xop,
						.Mmmmm = 0b1000,
						.Pp = 0b0,
						.W = false,
						.L = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0x96,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
					RegisterByte
					{
						.Register = OperandType::Xmm,
						.Payload = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmacswd",
			.GasMnemonic = "vpmacswd",
			.Description = "vpmacswd xmm, xmm, m128, xmm",
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
				IsaExtension::Xop,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Vex
					{
						.Type = VexPrefixType::Xop,
						.Mmmmm = 0b1000,
						.Pp = 0b0,
						.W = false,
						.L = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0x96,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
					RegisterByte
					{
						.Register = OperandType::Xmm,
						.Payload = {UINT64_C(0x0)},
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
			.IntelMnemonic = "vpmacsww",
			.GasMnemonic = "vpmacsww",
			.Description = "vpmacsww xmm, xmm, xmm, xmm",
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
				IsaExtension::Xop,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Vex
					{
						.Type = VexPrefixType::Xop,
						.Mmmmm = 0b1000,
						.Pp = 0b0,
						.W = false,
						.L = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0x95,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
					RegisterByte
					{
						.Register = OperandType::Xmm,
						.Payload = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmacsww",
			.GasMnemonic = "vpmacsww",
			.Description = "vpmacsww xmm, xmm, m128, xmm",
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
				IsaExtension::Xop,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Vex
					{
						.Type = VexPrefixType::Xop,
						.Mmmmm = 0b1000,
						.Pp = 0b0,
						.W = false,
						.L = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0x95,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
					RegisterByte
					{
						.Register = OperandType::Xmm,
						.Payload = {UINT64_C(0x0)},
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
			.IntelMnemonic = "vpmadcsswd",
			.GasMnemonic = "vpmadcsswd",
			.Description = "vpmadcsswd xmm, xmm, xmm, xmm",
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
				IsaExtension::Xop,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Vex
					{
						.Type = VexPrefixType::Xop,
						.Mmmmm = 0b1000,
						.Pp = 0b0,
						.W = false,
						.L = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0xa6,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
					RegisterByte
					{
						.Register = OperandType::Xmm,
						.Payload = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmadcsswd",
			.GasMnemonic = "vpmadcsswd",
			.Description = "vpmadcsswd xmm, xmm, m128, xmm",
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
				IsaExtension::Xop,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Vex
					{
						.Type = VexPrefixType::Xop,
						.Mmmmm = 0b1000,
						.Pp = 0b0,
						.W = false,
						.L = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0xa6,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
					RegisterByte
					{
						.Register = OperandType::Xmm,
						.Payload = {UINT64_C(0x0)},
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
			.IntelMnemonic = "vpmadcswd",
			.GasMnemonic = "vpmadcswd",
			.Description = "vpmadcswd xmm, xmm, xmm, xmm",
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
				IsaExtension::Xop,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Vex
					{
						.Type = VexPrefixType::Xop,
						.Mmmmm = 0b1000,
						.Pp = 0b0,
						.W = false,
						.L = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0xb6,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
					RegisterByte
					{
						.Register = OperandType::Xmm,
						.Payload = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmadcswd",
			.GasMnemonic = "vpmadcswd",
			.Description = "vpmadcswd xmm, xmm, m128, xmm",
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
				IsaExtension::Xop,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Vex
					{
						.Type = VexPrefixType::Xop,
						.Mmmmm = 0b1000,
						.Pp = 0b0,
						.W = false,
						.L = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0xb6,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
					RegisterByte
					{
						.Register = OperandType::Xmm,
						.Payload = {UINT64_C(0x0)},
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
			.IntelMnemonic = "vpmadd52huq",
			.GasMnemonic = "vpmadd52huq",
			.Description = "vpmadd52huq xmm{k}{z}, xmm, m128/m64bcst",
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
				IsaExtension::Avx512Ifma,
				IsaExtension::Avx512Vl,
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
						.Value = 0xb5,
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
			.IntelMnemonic = "vpmadd52huq",
			.GasMnemonic = "vpmadd52huq",
			.Description = "vpmadd52huq xmm{k}{z}, xmm, xmm",
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
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Avx512Ifma,
				IsaExtension::Avx512Vl,
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
						.Value = 0xb5,
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
			.IntelMnemonic = "vpmadd52huq",
			.GasMnemonic = "vpmadd52huq",
			.Description = "vpmadd52huq ymm{k}{z}, ymm, m256/m64bcst",
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
				IsaExtension::Avx512Ifma,
				IsaExtension::Avx512Vl,
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
						.Value = 0xb5,
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
			.IntelMnemonic = "vpmadd52huq",
			.GasMnemonic = "vpmadd52huq",
			.Description = "vpmadd52huq ymm{k}{z}, ymm, ymm",
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
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Avx512Ifma,
				IsaExtension::Avx512Vl,
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
						.Value = 0xb5,
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
			.IntelMnemonic = "vpmadd52huq",
			.GasMnemonic = "vpmadd52huq",
			.Description = "vpmadd52huq zmm{k}{z}, zmm, m512/m64bcst",
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
				IsaExtension::Avx512Ifma,
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
						.Value = 0xb5,
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
			.IntelMnemonic = "vpmadd52huq",
			.GasMnemonic = "vpmadd52huq",
			.Description = "vpmadd52huq zmm{k}{z}, zmm, zmm",
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
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Avx512Ifma,
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
						.Value = 0xb5,
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
			.IntelMnemonic = "vpmadd52luq",
			.GasMnemonic = "vpmadd52luq",
			.Description = "vpmadd52luq xmm{k}{z}, xmm, m128/m64bcst",
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
				IsaExtension::Avx512Ifma,
				IsaExtension::Avx512Vl,
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
						.Value = 0xb4,
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
			.IntelMnemonic = "vpmadd52luq",
			.GasMnemonic = "vpmadd52luq",
			.Description = "vpmadd52luq xmm{k}{z}, xmm, xmm",
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
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Avx512Ifma,
				IsaExtension::Avx512Vl,
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
						.Value = 0xb4,
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
			.IntelMnemonic = "vpmadd52luq",
			.GasMnemonic = "vpmadd52luq",
			.Description = "vpmadd52luq ymm{k}{z}, ymm, m256/m64bcst",
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
				IsaExtension::Avx512Ifma,
				IsaExtension::Avx512Vl,
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
						.Value = 0xb4,
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
			.IntelMnemonic = "vpmadd52luq",
			.GasMnemonic = "vpmadd52luq",
			.Description = "vpmadd52luq ymm{k}{z}, ymm, ymm",
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
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Avx512Ifma,
				IsaExtension::Avx512Vl,
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
						.Value = 0xb4,
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
			.IntelMnemonic = "vpmadd52luq",
			.GasMnemonic = "vpmadd52luq",
			.Description = "vpmadd52luq zmm{k}{z}, zmm, m512/m64bcst",
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
				IsaExtension::Avx512Ifma,
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
						.Value = 0xb4,
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
			.IntelMnemonic = "vpmadd52luq",
			.GasMnemonic = "vpmadd52luq",
			.Description = "vpmadd52luq zmm{k}{z}, zmm, zmm",
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
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Avx512Ifma,
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
						.Value = 0xb4,
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
			.IntelMnemonic = "vpmaddubsw",
			.GasMnemonic = "vpmaddubsw",
			.Description = "vpmaddubsw xmm{k}{z}, xmm, xmm",
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
						.Value = 0x4,
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
			.IntelMnemonic = "vpmaddubsw",
			.GasMnemonic = "vpmaddubsw",
			.Description = "vpmaddubsw xmm{k}{z}, xmm, m128",
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
						.Value = 0x4,
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
			.IntelMnemonic = "vpmaddubsw",
			.GasMnemonic = "vpmaddubsw",
			.Description = "vpmaddubsw ymm{k}{z}, ymm, ymm",
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
						.Value = 0x4,
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
			.IntelMnemonic = "vpmaddubsw",
			.GasMnemonic = "vpmaddubsw",
			.Description = "vpmaddubsw ymm{k}{z}, ymm, m256",
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
						.Value = 0x4,
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
			.IntelMnemonic = "vpmaddubsw",
			.GasMnemonic = "vpmaddubsw",
			.Description = "vpmaddubsw zmm{k}{z}, zmm, zmm",
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
						.Value = 0x4,
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
			.IntelMnemonic = "vpmaddubsw",
			.GasMnemonic = "vpmaddubsw",
			.Description = "vpmaddubsw zmm{k}{z}, zmm, m512",
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
						.Value = 0x4,
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
			.IntelMnemonic = "vpmaddubsw",
			.GasMnemonic = "vpmaddubsw",
			.Description = "vpmaddubsw xmm, xmm, xmm",
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
						.Value = 0x4,
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
			.IntelMnemonic = "vpmaddubsw",
			.GasMnemonic = "vpmaddubsw",
			.Description = "vpmaddubsw xmm, xmm, m128",
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
						.Value = 0x4,
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
			.IntelMnemonic = "vpmaddubsw",
			.GasMnemonic = "vpmaddubsw",
			.Description = "vpmaddubsw ymm, ymm, ymm",
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
						.Value = 0x4,
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
			.IntelMnemonic = "vpmaddubsw",
			.GasMnemonic = "vpmaddubsw",
			.Description = "vpmaddubsw ymm, ymm, m256",
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
						.Value = 0x4,
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
			.IntelMnemonic = "vpmaddwd",
			.GasMnemonic = "vpmaddwd",
			.Description = "vpmaddwd xmm{k}{z}, xmm, xmm",
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
						.Value = 0xf5,
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
			.IntelMnemonic = "vpmaddwd",
			.GasMnemonic = "vpmaddwd",
			.Description = "vpmaddwd xmm{k}{z}, xmm, m128",
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
						.Value = 0xf5,
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
			.IntelMnemonic = "vpmaddwd",
			.GasMnemonic = "vpmaddwd",
			.Description = "vpmaddwd ymm{k}{z}, ymm, ymm",
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
						.Value = 0xf5,
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
			.IntelMnemonic = "vpmaddwd",
			.GasMnemonic = "vpmaddwd",
			.Description = "vpmaddwd ymm{k}{z}, ymm, m256",
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
						.Value = 0xf5,
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
			.IntelMnemonic = "vpmaddwd",
			.GasMnemonic = "vpmaddwd",
			.Description = "vpmaddwd zmm{k}{z}, zmm, zmm",
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
						.Value = 0xf5,
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
			.IntelMnemonic = "vpmaddwd",
			.GasMnemonic = "vpmaddwd",
			.Description = "vpmaddwd zmm{k}{z}, zmm, m512",
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
						.Value = 0xf5,
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
			.IntelMnemonic = "vpmaddwd",
			.GasMnemonic = "vpmaddwd",
			.Description = "vpmaddwd xmm, xmm, xmm",
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
						.Value = 0xf5,
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
			.IntelMnemonic = "vpmaddwd",
			.GasMnemonic = "vpmaddwd",
			.Description = "vpmaddwd xmm, xmm, m128",
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
						.Value = 0xf5,
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
			.IntelMnemonic = "vpmaddwd",
			.GasMnemonic = "vpmaddwd",
			.Description = "vpmaddwd ymm, ymm, ymm",
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
						.Value = 0xf5,
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
			.IntelMnemonic = "vpmaddwd",
			.GasMnemonic = "vpmaddwd",
			.Description = "vpmaddwd ymm, ymm, m256",
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
						.Value = 0xf5,
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
			.IntelMnemonic = "vpmaskmovd",
			.GasMnemonic = "vpmaskmovd",
			.Description = "vpmaskmovd xmm, xmm, m128",
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
						.Value = 0x8c,
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
			.IntelMnemonic = "vpmaskmovd",
			.GasMnemonic = "vpmaskmovd",
			.Description = "vpmaskmovd ymm, ymm, m256",
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
						.Value = 0x8c,
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
		InstructionVariation
		{
			.IntelMnemonic = "vpmaskmovd",
			.GasMnemonic = "vpmaskmovd",
			.Description = "vpmaskmovd m128, xmm, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M128,
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
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0x8e,
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
			.IntelMnemonic = "vpmaskmovd",
			.GasMnemonic = "vpmaskmovd",
			.Description = "vpmaskmovd m256, ymm, ymm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M256,
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
						.X = {OperandType::M256},
						.B = {OperandType::M256},
						.Vvvv = {OperandType::Ymm},
					},
					OpCode
					{
						.Value = 0x8e,
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
			.IntelMnemonic = "vpmaskmovq",
			.GasMnemonic = "vpmaskmovq",
			.Description = "vpmaskmovq xmm, xmm, m128",
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
						.Value = 0x8c,
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
			.IntelMnemonic = "vpmaskmovq",
			.GasMnemonic = "vpmaskmovq",
			.Description = "vpmaskmovq ymm, ymm, m256",
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
						.Value = 0x8c,
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
		InstructionVariation
		{
			.IntelMnemonic = "vpmaskmovq",
			.GasMnemonic = "vpmaskmovq",
			.Description = "vpmaskmovq m128, xmm, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M128,
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
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0x8e,
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
			.IntelMnemonic = "vpmaskmovq",
			.GasMnemonic = "vpmaskmovq",
			.Description = "vpmaskmovq m256, ymm, ymm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M256,
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
						.X = {OperandType::M256},
						.B = {OperandType::M256},
						.Vvvv = {OperandType::Ymm},
					},
					OpCode
					{
						.Value = 0x8e,
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
			.IntelMnemonic = "vpmaxsb",
			.GasMnemonic = "vpmaxsb",
			.Description = "vpmaxsb xmm{k}{z}, xmm, xmm",
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
						.Value = 0x3c,
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
			.IntelMnemonic = "vpmaxsb",
			.GasMnemonic = "vpmaxsb",
			.Description = "vpmaxsb xmm{k}{z}, xmm, m128",
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
						.Value = 0x3c,
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
			.IntelMnemonic = "vpmaxsb",
			.GasMnemonic = "vpmaxsb",
			.Description = "vpmaxsb ymm{k}{z}, ymm, ymm",
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
						.Value = 0x3c,
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
			.IntelMnemonic = "vpmaxsb",
			.GasMnemonic = "vpmaxsb",
			.Description = "vpmaxsb ymm{k}{z}, ymm, m256",
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
						.Value = 0x3c,
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
			.IntelMnemonic = "vpmaxsb",
			.GasMnemonic = "vpmaxsb",
			.Description = "vpmaxsb zmm{k}{z}, zmm, zmm",
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
						.Value = 0x3c,
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
			.IntelMnemonic = "vpmaxsb",
			.GasMnemonic = "vpmaxsb",
			.Description = "vpmaxsb zmm{k}{z}, zmm, m512",
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
						.Value = 0x3c,
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
			.IntelMnemonic = "vpmaxsb",
			.GasMnemonic = "vpmaxsb",
			.Description = "vpmaxsb xmm, xmm, xmm",
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
						.Value = 0x3c,
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
			.IntelMnemonic = "vpmaxsb",
			.GasMnemonic = "vpmaxsb",
			.Description = "vpmaxsb xmm, xmm, m128",
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
						.Value = 0x3c,
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
			.IntelMnemonic = "vpmaxsb",
			.GasMnemonic = "vpmaxsb",
			.Description = "vpmaxsb ymm, ymm, ymm",
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
						.Value = 0x3c,
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
			.IntelMnemonic = "vpmaxsb",
			.GasMnemonic = "vpmaxsb",
			.Description = "vpmaxsb ymm, ymm, m256",
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
						.Value = 0x3c,
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
			.IntelMnemonic = "vpmaxsd",
			.GasMnemonic = "vpmaxsd",
			.Description = "vpmaxsd xmm{k}{z}, xmm, m128/m32bcst",
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
						.Value = 0x3d,
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
			.IntelMnemonic = "vpmaxsd",
			.GasMnemonic = "vpmaxsd",
			.Description = "vpmaxsd xmm{k}{z}, xmm, xmm",
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
						.Value = 0x3d,
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
			.IntelMnemonic = "vpmaxsd",
			.GasMnemonic = "vpmaxsd",
			.Description = "vpmaxsd ymm{k}{z}, ymm, m256/m32bcst",
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
						.Value = 0x3d,
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
			.IntelMnemonic = "vpmaxsd",
			.GasMnemonic = "vpmaxsd",
			.Description = "vpmaxsd ymm{k}{z}, ymm, ymm",
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
						.Value = 0x3d,
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
			.IntelMnemonic = "vpmaxsd",
			.GasMnemonic = "vpmaxsd",
			.Description = "vpmaxsd zmm{k}{z}, zmm, m512/m32bcst",
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
						.Value = 0x3d,
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
			.IntelMnemonic = "vpmaxsd",
			.GasMnemonic = "vpmaxsd",
			.Description = "vpmaxsd zmm{k}{z}, zmm, zmm",
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
						.Value = 0x3d,
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
			.IntelMnemonic = "vpmaxsd",
			.GasMnemonic = "vpmaxsd",
			.Description = "vpmaxsd xmm, xmm, xmm",
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
						.Value = 0x3d,
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
			.IntelMnemonic = "vpmaxsd",
			.GasMnemonic = "vpmaxsd",
			.Description = "vpmaxsd xmm, xmm, m128",
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
						.Value = 0x3d,
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
			.IntelMnemonic = "vpmaxsd",
			.GasMnemonic = "vpmaxsd",
			.Description = "vpmaxsd ymm, ymm, ymm",
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
						.Value = 0x3d,
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
			.IntelMnemonic = "vpmaxsd",
			.GasMnemonic = "vpmaxsd",
			.Description = "vpmaxsd ymm, ymm, m256",
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
						.Value = 0x3d,
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
			.IntelMnemonic = "vpmaxsq",
			.GasMnemonic = "vpmaxsq",
			.Description = "vpmaxsq xmm{k}{z}, xmm, m128/m64bcst",
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
						.Value = 0x3d,
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
			.IntelMnemonic = "vpmaxsq",
			.GasMnemonic = "vpmaxsq",
			.Description = "vpmaxsq xmm{k}{z}, xmm, xmm",
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
						.Value = 0x3d,
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
			.IntelMnemonic = "vpmaxsq",
			.GasMnemonic = "vpmaxsq",
			.Description = "vpmaxsq ymm{k}{z}, ymm, m256/m64bcst",
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
						.Value = 0x3d,
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
			.IntelMnemonic = "vpmaxsq",
			.GasMnemonic = "vpmaxsq",
			.Description = "vpmaxsq ymm{k}{z}, ymm, ymm",
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
						.Value = 0x3d,
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
			.IntelMnemonic = "vpmaxsq",
			.GasMnemonic = "vpmaxsq",
			.Description = "vpmaxsq zmm{k}{z}, zmm, m512/m64bcst",
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
						.Value = 0x3d,
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
			.IntelMnemonic = "vpmaxsq",
			.GasMnemonic = "vpmaxsq",
			.Description = "vpmaxsq zmm{k}{z}, zmm, zmm",
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
						.Value = 0x3d,
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

};
}
