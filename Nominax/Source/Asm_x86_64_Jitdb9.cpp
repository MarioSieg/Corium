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
NOX_NEVER_INLINE NOX_COLD auto GetVariationTable_9(std::pmr::monotonic_buffer_resource& allocator, std::pmr::vector<InstructionVariationPool>& out) -> void
{
	std::pmr::vector<InstructionVariation> instruction{&allocator};
	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "mulss",
			.GasMnemonic = "mulss",
			.Description = "mulss xmm, xmm",
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
						.Value = 0x59,
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
			.IntelMnemonic = "mulss",
			.GasMnemonic = "mulss",
			.Description = "mulss xmm, m32",
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
						.Value = 0x59,
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
			.IntelMnemonic = "mulx",
			.GasMnemonic = "mulxl",
			.Description = "mulxl r32, r32, r32",
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
				ImplicitRegisterOperand::Edx,
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
						.Value = 0xf6,
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
			.IntelMnemonic = "mulx",
			.GasMnemonic = "mulxl",
			.Description = "mulxl r32, r32, m32",
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
				ImplicitRegisterOperand::Edx,
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
						.Value = 0xf6,
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
			.IntelMnemonic = "mulx",
			.GasMnemonic = "mulxq",
			.Description = "mulxq r64, r64, r64",
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
				ImplicitRegisterOperand::Rdx,
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
						.Value = 0xf6,
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
			.IntelMnemonic = "mulx",
			.GasMnemonic = "mulxq",
			.Description = "mulxq r64, r64, m64",
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
				ImplicitRegisterOperand::Rdx,
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
						.Value = 0xf6,
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
			.IntelMnemonic = "mwait",
			.GasMnemonic = "mwait",
			.Description = "mwait",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
			},
			.ImplicitInputs =
			{
				ImplicitRegisterOperand::Ecx,
				ImplicitRegisterOperand::Eax,
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Monitor,
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
						.Value = 0x1,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xc9,
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
			.IntelMnemonic = "mwaitx",
			.GasMnemonic = "mwaitx",
			.Description = "mwaitx",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
			},
			.ImplicitInputs =
			{
				ImplicitRegisterOperand::Ecx,
				ImplicitRegisterOperand::Ebx,
				ImplicitRegisterOperand::Eax,
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Monitorx,
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
						.Value = 0x1,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xfb,
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
			.IntelMnemonic = "neg",
			.GasMnemonic = "negb",
			.Description = "negb r8",
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
						.Value = 0xf6,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R8},
						.Reg = {UINT64_C(0x3)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "neg",
			.GasMnemonic = "negw",
			.Description = "negw r16",
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
						.Value = 0xf7,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R16},
						.Reg = {UINT64_C(0x3)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "neg",
			.GasMnemonic = "negl",
			.Description = "negl r32",
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
						.Value = 0xf7,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R32},
						.Reg = {UINT64_C(0x3)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "neg",
			.GasMnemonic = "negq",
			.Description = "negq r64",
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
						.Value = 0xf7,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R64},
						.Reg = {UINT64_C(0x3)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "neg",
			.GasMnemonic = "negb",
			.Description = "negb m8",
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
						.Value = 0xf6,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M8},
						.Rm = {OperandType::M8},
						.Reg = {UINT64_C(0x3)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "neg",
			.GasMnemonic = "negw",
			.Description = "negw m16",
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
						.Value = 0xf7,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M16},
						.Rm = {OperandType::M16},
						.Reg = {UINT64_C(0x3)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "neg",
			.GasMnemonic = "negl",
			.Description = "negl m32",
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
						.Value = 0xf7,
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
		InstructionVariation
		{
			.IntelMnemonic = "neg",
			.GasMnemonic = "negq",
			.Description = "negq m64",
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
						.Value = 0xf7,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
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
			.IntelMnemonic = "nop",
			.GasMnemonic = "nop",
			.Description = "nop",
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
			.IntelMnemonic = "not",
			.GasMnemonic = "notb",
			.Description = "notb r8",
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
						.Value = 0xf6,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R8},
						.Reg = {UINT64_C(0x2)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "not",
			.GasMnemonic = "notw",
			.Description = "notw r16",
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
						.Value = 0xf7,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R16},
						.Reg = {UINT64_C(0x2)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "not",
			.GasMnemonic = "notl",
			.Description = "notl r32",
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
						.Value = 0xf7,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R32},
						.Reg = {UINT64_C(0x2)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "not",
			.GasMnemonic = "notq",
			.Description = "notq r64",
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
						.Value = 0xf7,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R64},
						.Reg = {UINT64_C(0x2)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "not",
			.GasMnemonic = "notb",
			.Description = "notb m8",
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
						.Value = 0xf6,
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
		InstructionVariation
		{
			.IntelMnemonic = "not",
			.GasMnemonic = "notw",
			.Description = "notw m16",
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
						.Value = 0xf7,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M16},
						.Rm = {OperandType::M16},
						.Reg = {UINT64_C(0x2)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "not",
			.GasMnemonic = "notl",
			.Description = "notl m32",
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
						.Value = 0xf7,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M32},
						.Rm = {OperandType::M32},
						.Reg = {UINT64_C(0x2)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "not",
			.GasMnemonic = "notq",
			.Description = "notq m64",
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
						.Value = 0xf7,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
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
			.IntelMnemonic = "or",
			.GasMnemonic = "orb",
			.Description = "orb al, imm8",
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
						.Value = 0xc,
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
			.IntelMnemonic = "or",
			.GasMnemonic = "orb",
			.Description = "orb r8, imm8",
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
						.Reg = {UINT64_C(0x1)},
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
			.IntelMnemonic = "or",
			.GasMnemonic = "orb",
			.Description = "orb r8, r8",
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
						.Value = 0x8,
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
						.Value = 0xa,
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
			.IntelMnemonic = "or",
			.GasMnemonic = "orb",
			.Description = "orb r8, m8",
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
						.Value = 0xa,
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
			.IntelMnemonic = "or",
			.GasMnemonic = "orw",
			.Description = "orw ax, imm16",
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
						.Value = 0xd,
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
			.IntelMnemonic = "or",
			.GasMnemonic = "orw",
			.Description = "orw r16, imm8",
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
						.Reg = {UINT64_C(0x1)},
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
			.IntelMnemonic = "or",
			.GasMnemonic = "orw",
			.Description = "orw r16, imm16",
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
						.Reg = {UINT64_C(0x1)},
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
			.IntelMnemonic = "or",
			.GasMnemonic = "orw",
			.Description = "orw r16, r16",
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
						.Value = 0x9,
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
						.Value = 0xb,
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
			.IntelMnemonic = "or",
			.GasMnemonic = "orw",
			.Description = "orw r16, m16",
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
						.Value = 0xb,
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
			.IntelMnemonic = "or",
			.GasMnemonic = "orl",
			.Description = "orl eax, imm32",
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
						.Value = 0xd,
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
			.IntelMnemonic = "or",
			.GasMnemonic = "orl",
			.Description = "orl r32, imm8",
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
						.Reg = {UINT64_C(0x1)},
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
			.IntelMnemonic = "or",
			.GasMnemonic = "orl",
			.Description = "orl r32, imm32",
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
						.Reg = {UINT64_C(0x1)},
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
			.IntelMnemonic = "or",
			.GasMnemonic = "orl",
			.Description = "orl r32, r32",
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
						.Value = 0x9,
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
						.Value = 0xb,
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
			.IntelMnemonic = "or",
			.GasMnemonic = "orl",
			.Description = "orl r32, m32",
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
						.Value = 0xb,
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
			.IntelMnemonic = "or",
			.GasMnemonic = "orq",
			.Description = "orq rax, imm32",
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
						.Value = 0xd,
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
			.IntelMnemonic = "or",
			.GasMnemonic = "orq",
			.Description = "orq r64, imm8",
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
						.Reg = {UINT64_C(0x1)},
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
			.IntelMnemonic = "or",
			.GasMnemonic = "orq",
			.Description = "orq r64, imm32",
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
						.Reg = {UINT64_C(0x1)},
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
			.IntelMnemonic = "or",
			.GasMnemonic = "orq",
			.Description = "orq r64, r64",
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
						.Value = 0x9,
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
						.Value = 0xb,
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
			.IntelMnemonic = "or",
			.GasMnemonic = "orq",
			.Description = "orq r64, m64",
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
						.Value = 0xb,
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
			.IntelMnemonic = "or",
			.GasMnemonic = "orb",
			.Description = "orb m8, imm8",
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
						.Reg = {UINT64_C(0x1)},
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
			.IntelMnemonic = "or",
			.GasMnemonic = "orb",
			.Description = "orb m8, r8",
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
						.Value = 0x8,
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
			.IntelMnemonic = "or",
			.GasMnemonic = "orw",
			.Description = "orw m16, imm8",
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
						.Reg = {UINT64_C(0x1)},
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
			.IntelMnemonic = "or",
			.GasMnemonic = "orw",
			.Description = "orw m16, imm16",
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
						.Reg = {UINT64_C(0x1)},
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
			.IntelMnemonic = "or",
			.GasMnemonic = "orw",
			.Description = "orw m16, r16",
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
						.Value = 0x9,
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
			.IntelMnemonic = "or",
			.GasMnemonic = "orl",
			.Description = "orl m32, imm8",
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
						.Reg = {UINT64_C(0x1)},
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
			.IntelMnemonic = "or",
			.GasMnemonic = "orl",
			.Description = "orl m32, imm32",
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
						.Reg = {UINT64_C(0x1)},
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
			.IntelMnemonic = "or",
			.GasMnemonic = "orl",
			.Description = "orl m32, r32",
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
						.Value = 0x9,
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
			.IntelMnemonic = "or",
			.GasMnemonic = "orq",
			.Description = "orq m64, imm8",
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
						.Reg = {UINT64_C(0x1)},
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
			.IntelMnemonic = "or",
			.GasMnemonic = "orq",
			.Description = "orq m64, imm32",
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
						.Reg = {UINT64_C(0x1)},
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
			.IntelMnemonic = "or",
			.GasMnemonic = "orq",
			.Description = "orq m64, r64",
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
						.Value = 0x9,
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
			.IntelMnemonic = "orpd",
			.GasMnemonic = "orpd",
			.Description = "orpd xmm, xmm",
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
						.Value = 0x56,
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
			.IntelMnemonic = "orpd",
			.GasMnemonic = "orpd",
			.Description = "orpd xmm, m128",
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
						.Value = 0x56,
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
			.IntelMnemonic = "orps",
			.GasMnemonic = "orps",
			.Description = "orps xmm, xmm",
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
						.Value = 0x56,
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
			.IntelMnemonic = "orps",
			.GasMnemonic = "orps",
			.Description = "orps xmm, m128",
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
						.Value = 0x56,
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
			.IntelMnemonic = "pabsb",
			.GasMnemonic = "pabsb",
			.Description = "pabsb mm, mm",
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
						.Value = 0x1c,
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
			.IntelMnemonic = "pabsb",
			.GasMnemonic = "pabsb",
			.Description = "pabsb mm, m64",
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
						.Value = 0x1c,
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
			.IntelMnemonic = "pabsb",
			.GasMnemonic = "pabsb",
			.Description = "pabsb xmm, xmm",
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
						.Value = 0x1c,
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
			.IntelMnemonic = "pabsb",
			.GasMnemonic = "pabsb",
			.Description = "pabsb xmm, m128",
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
						.Value = 0x1c,
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
			.IntelMnemonic = "pabsd",
			.GasMnemonic = "pabsd",
			.Description = "pabsd mm, mm",
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
						.Value = 0x1e,
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
			.IntelMnemonic = "pabsd",
			.GasMnemonic = "pabsd",
			.Description = "pabsd mm, m64",
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
						.Value = 0x1e,
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
			.IntelMnemonic = "pabsd",
			.GasMnemonic = "pabsd",
			.Description = "pabsd xmm, xmm",
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
						.Value = 0x1e,
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
			.IntelMnemonic = "pabsd",
			.GasMnemonic = "pabsd",
			.Description = "pabsd xmm, m128",
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
						.Value = 0x1e,
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
			.IntelMnemonic = "pabsw",
			.GasMnemonic = "pabsw",
			.Description = "pabsw mm, mm",
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
						.Value = 0x1d,
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
			.IntelMnemonic = "pabsw",
			.GasMnemonic = "pabsw",
			.Description = "pabsw mm, m64",
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
						.Value = 0x1d,
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
			.IntelMnemonic = "pabsw",
			.GasMnemonic = "pabsw",
			.Description = "pabsw xmm, xmm",
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
						.Value = 0x1d,
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
			.IntelMnemonic = "pabsw",
			.GasMnemonic = "pabsw",
			.Description = "pabsw xmm, m128",
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
						.Value = 0x1d,
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
			.IntelMnemonic = "packssdw",
			.GasMnemonic = "packssdw",
			.Description = "packssdw mm, mm",
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
						.Value = 0x6b,
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
			.IntelMnemonic = "packssdw",
			.GasMnemonic = "packssdw",
			.Description = "packssdw mm, m64",
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
						.Value = 0x6b,
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
			.IntelMnemonic = "packssdw",
			.GasMnemonic = "packssdw",
			.Description = "packssdw xmm, xmm",
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
						.Value = 0x6b,
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
			.IntelMnemonic = "packssdw",
			.GasMnemonic = "packssdw",
			.Description = "packssdw xmm, m128",
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
						.Value = 0x6b,
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
			.IntelMnemonic = "packsswb",
			.GasMnemonic = "packsswb",
			.Description = "packsswb mm, mm",
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
						.Value = 0x63,
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
			.IntelMnemonic = "packsswb",
			.GasMnemonic = "packsswb",
			.Description = "packsswb mm, m64",
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
						.Value = 0x63,
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
			.IntelMnemonic = "packsswb",
			.GasMnemonic = "packsswb",
			.Description = "packsswb xmm, xmm",
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
						.Value = 0x63,
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
			.IntelMnemonic = "packsswb",
			.GasMnemonic = "packsswb",
			.Description = "packsswb xmm, m128",
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
						.Value = 0x63,
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
			.IntelMnemonic = "packusdw",
			.GasMnemonic = "packusdw",
			.Description = "packusdw xmm, xmm",
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
						.Value = 0x2b,
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
			.IntelMnemonic = "packusdw",
			.GasMnemonic = "packusdw",
			.Description = "packusdw xmm, m128",
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
						.Value = 0x2b,
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
			.IntelMnemonic = "packuswb",
			.GasMnemonic = "packuswb",
			.Description = "packuswb mm, mm",
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
						.Value = 0x67,
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
			.IntelMnemonic = "packuswb",
			.GasMnemonic = "packuswb",
			.Description = "packuswb mm, m64",
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
						.Value = 0x67,
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
			.IntelMnemonic = "packuswb",
			.GasMnemonic = "packuswb",
			.Description = "packuswb xmm, xmm",
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
						.Value = 0x67,
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
			.IntelMnemonic = "packuswb",
			.GasMnemonic = "packuswb",
			.Description = "packuswb xmm, m128",
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
						.Value = 0x67,
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
			.IntelMnemonic = "paddb",
			.GasMnemonic = "paddb",
			.Description = "paddb mm, mm",
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
						.Value = 0xfc,
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
			.IntelMnemonic = "paddb",
			.GasMnemonic = "paddb",
			.Description = "paddb mm, m64",
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
						.Value = 0xfc,
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
			.IntelMnemonic = "paddb",
			.GasMnemonic = "paddb",
			.Description = "paddb xmm, xmm",
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
						.Value = 0xfc,
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
			.IntelMnemonic = "paddb",
			.GasMnemonic = "paddb",
			.Description = "paddb xmm, m128",
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
						.Value = 0xfc,
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
			.IntelMnemonic = "paddd",
			.GasMnemonic = "paddd",
			.Description = "paddd mm, mm",
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
						.Value = 0xfe,
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
			.IntelMnemonic = "paddd",
			.GasMnemonic = "paddd",
			.Description = "paddd mm, m64",
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
						.Value = 0xfe,
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
			.IntelMnemonic = "paddd",
			.GasMnemonic = "paddd",
			.Description = "paddd xmm, xmm",
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
						.Value = 0xfe,
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
			.IntelMnemonic = "paddd",
			.GasMnemonic = "paddd",
			.Description = "paddd xmm, m128",
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
						.Value = 0xfe,
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
			.IntelMnemonic = "paddq",
			.GasMnemonic = "paddq",
			.Description = "paddq mm, mm",
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
						.Value = 0xd4,
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
			.IntelMnemonic = "paddq",
			.GasMnemonic = "paddq",
			.Description = "paddq mm, m64",
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
						.Value = 0xd4,
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
			.IntelMnemonic = "paddq",
			.GasMnemonic = "paddq",
			.Description = "paddq xmm, xmm",
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
						.Value = 0xd4,
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
			.IntelMnemonic = "paddq",
			.GasMnemonic = "paddq",
			.Description = "paddq xmm, m128",
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
						.Value = 0xd4,
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
			.IntelMnemonic = "paddsb",
			.GasMnemonic = "paddsb",
			.Description = "paddsb mm, mm",
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
						.Value = 0xec,
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
			.IntelMnemonic = "paddsb",
			.GasMnemonic = "paddsb",
			.Description = "paddsb mm, m64",
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
						.Value = 0xec,
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
			.IntelMnemonic = "paddsb",
			.GasMnemonic = "paddsb",
			.Description = "paddsb xmm, xmm",
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
						.Value = 0xec,
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
			.IntelMnemonic = "paddsb",
			.GasMnemonic = "paddsb",
			.Description = "paddsb xmm, m128",
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
						.Value = 0xec,
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
			.IntelMnemonic = "paddsw",
			.GasMnemonic = "paddsw",
			.Description = "paddsw mm, mm",
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
						.Value = 0xed,
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
			.IntelMnemonic = "paddsw",
			.GasMnemonic = "paddsw",
			.Description = "paddsw mm, m64",
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
						.Value = 0xed,
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
			.IntelMnemonic = "paddsw",
			.GasMnemonic = "paddsw",
			.Description = "paddsw xmm, xmm",
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
						.Value = 0xed,
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
			.IntelMnemonic = "paddsw",
			.GasMnemonic = "paddsw",
			.Description = "paddsw xmm, m128",
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
						.Value = 0xed,
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
			.IntelMnemonic = "paddusb",
			.GasMnemonic = "paddusb",
			.Description = "paddusb mm, mm",
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
						.Value = 0xdc,
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
			.IntelMnemonic = "paddusb",
			.GasMnemonic = "paddusb",
			.Description = "paddusb mm, m64",
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
						.Value = 0xdc,
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
			.IntelMnemonic = "paddusb",
			.GasMnemonic = "paddusb",
			.Description = "paddusb xmm, xmm",
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
						.Value = 0xdc,
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
			.IntelMnemonic = "paddusb",
			.GasMnemonic = "paddusb",
			.Description = "paddusb xmm, m128",
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
						.Value = 0xdc,
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
			.IntelMnemonic = "paddusw",
			.GasMnemonic = "paddusw",
			.Description = "paddusw mm, mm",
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
						.Value = 0xdd,
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
			.IntelMnemonic = "paddusw",
			.GasMnemonic = "paddusw",
			.Description = "paddusw mm, m64",
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
						.Value = 0xdd,
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
			.IntelMnemonic = "paddusw",
			.GasMnemonic = "paddusw",
			.Description = "paddusw xmm, xmm",
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
						.Value = 0xdd,
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
			.IntelMnemonic = "paddusw",
			.GasMnemonic = "paddusw",
			.Description = "paddusw xmm, m128",
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
						.Value = 0xdd,
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
			.IntelMnemonic = "paddw",
			.GasMnemonic = "paddw",
			.Description = "paddw mm, mm",
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
						.Value = 0xfd,
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
			.IntelMnemonic = "paddw",
			.GasMnemonic = "paddw",
			.Description = "paddw mm, m64",
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
						.Value = 0xfd,
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
			.IntelMnemonic = "paddw",
			.GasMnemonic = "paddw",
			.Description = "paddw xmm, xmm",
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
						.Value = 0xfd,
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
			.IntelMnemonic = "paddw",
			.GasMnemonic = "paddw",
			.Description = "paddw xmm, m128",
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
						.Value = 0xfd,
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
			.IntelMnemonic = "palignr",
			.GasMnemonic = "palignr",
			.Description = "palignr mm, mm, imm8",
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
						.Value = 0x3a,
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
			.IntelMnemonic = "palignr",
			.GasMnemonic = "palignr",
			.Description = "palignr mm, m64, imm8",
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
						.Value = 0x3a,
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
			.IntelMnemonic = "palignr",
			.GasMnemonic = "palignr",
			.Description = "palignr xmm, xmm, imm8",
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
						.Value = 0x3a,
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
			.IntelMnemonic = "palignr",
			.GasMnemonic = "palignr",
			.Description = "palignr xmm, m128, imm8",
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
						.Value = 0x3a,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xf,
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
			.IntelMnemonic = "pand",
			.GasMnemonic = "pand",
			.Description = "pand mm, mm",
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
						.Value = 0xdb,
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
			.IntelMnemonic = "pand",
			.GasMnemonic = "pand",
			.Description = "pand mm, m64",
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
						.Value = 0xdb,
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
			.IntelMnemonic = "pand",
			.GasMnemonic = "pand",
			.Description = "pand xmm, xmm",
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
						.Value = 0xdb,
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
			.IntelMnemonic = "pand",
			.GasMnemonic = "pand",
			.Description = "pand xmm, m128",
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
						.Value = 0xdb,
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
			.IntelMnemonic = "pandn",
			.GasMnemonic = "pandn",
			.Description = "pandn mm, mm",
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
						.Value = 0xdf,
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
			.IntelMnemonic = "pandn",
			.GasMnemonic = "pandn",
			.Description = "pandn mm, m64",
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
						.Value = 0xdf,
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
			.IntelMnemonic = "pandn",
			.GasMnemonic = "pandn",
			.Description = "pandn xmm, xmm",
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
						.Value = 0xdf,
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
			.IntelMnemonic = "pandn",
			.GasMnemonic = "pandn",
			.Description = "pandn xmm, m128",
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
						.Value = 0xdf,
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
			.IntelMnemonic = "pause",
			.GasMnemonic = "pause",
			.Description = "pause",
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
					Prefix
					{
						.Value = 0xf3,
						.IsMandatory = true,
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
			.IntelMnemonic = "pavgb",
			.GasMnemonic = "pavgb",
			.Description = "pavgb mm, mm",
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
						.Value = 0xe0,
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
			.IntelMnemonic = "pavgb",
			.GasMnemonic = "pavgb",
			.Description = "pavgb mm, m64",
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
						.Value = 0xe0,
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
			.IntelMnemonic = "pavgb",
			.GasMnemonic = "pavgb",
			.Description = "pavgb xmm, xmm",
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
						.Value = 0xe0,
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
			.IntelMnemonic = "pavgb",
			.GasMnemonic = "pavgb",
			.Description = "pavgb xmm, m128",
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
						.Value = 0xe0,
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
			.IntelMnemonic = "pavgusb",
			.GasMnemonic = "pavgusb",
			.Description = "pavgusb mm, mm",
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
						.Value = 0xbf,
						.Addend = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "pavgusb",
			.GasMnemonic = "pavgusb",
			.Description = "pavgusb mm, m64",
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
						.Value = 0xbf,
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
			.IntelMnemonic = "pavgw",
			.GasMnemonic = "pavgw",
			.Description = "pavgw mm, mm",
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
						.Value = 0xe3,
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
			.IntelMnemonic = "pavgw",
			.GasMnemonic = "pavgw",
			.Description = "pavgw mm, m64",
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
						.Value = 0xe3,
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
			.IntelMnemonic = "pavgw",
			.GasMnemonic = "pavgw",
			.Description = "pavgw xmm, xmm",
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
			.IntelMnemonic = "pavgw",
			.GasMnemonic = "pavgw",
			.Description = "pavgw xmm, m128",
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

};
}
