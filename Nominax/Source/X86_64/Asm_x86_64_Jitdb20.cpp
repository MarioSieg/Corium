// File: Asm_x86_64_Jitdb20.cpp
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
	NOX_NEVER_INLINE NOX_COLD auto GetVariationTable_20(std::pmr::monotonic_buffer_resource& allocator, std::pmr::vector<InstructionVariationPool>& out) -> void
	{
		std::pmr::vector<InstructionVariation> instruction {&allocator};
		instruction =
		{
			InstructionVariation
			{
				.IntelMnemonic = "vdivsd",
				.GasMnemonic = "vdivsd",
				.Description = "vdivsd xmm{k}{z}, xmm, m64",
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
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b11,
							.W = true,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::M64},
							.X = {OperandType::M64},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M64},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 8,
						},
						OpCode
						{
							.Value = 0x5e,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M64},
							.Rm = {OperandType::M64},
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vdivsd",
				.GasMnemonic = "vdivsd",
				.Description = "vdivsd xmm, xmm, xmm",
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
							.Pp = 0b11,
							.W = false,
							.L = false,
							.R = {OperandType::Xmm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
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
				.IntelMnemonic = "vdivsd",
				.GasMnemonic = "vdivsd",
				.Description = "vdivsd xmm, xmm, m64",
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
							.Pp = 0b11,
							.W = false,
							.L = false,
							.R = {OperandType::Xmm},
							.X = {OperandType::M64},
							.B = {OperandType::M64},
							.Vvvv = {OperandType::Xmm},
						},
						OpCode
						{
							.Value = 0x5e,
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
			InstructionVariation
			{
				.IntelMnemonic = "vdivsd",
				.GasMnemonic = "vdivsd",
				.Description = "vdivsd xmm{k}{z}, xmm, xmm, {er}",
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
					Operand
					{
						.Type = OperandType::Er,
						.IsInput = false,
						.IsOutput = false,
						.ExtendedSize = 0
					},
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
							.Pp = 0b11,
							.W = true,
							.Ll = OperandType::Er,
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
							.Value = 0x5e,
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
		};
		out.emplace_back(std::move(instruction));

		instruction =
		{
			InstructionVariation
			{
				.IntelMnemonic = "vdivss",
				.GasMnemonic = "vdivss",
				.Description = "vdivss xmm{k}{z}, xmm, m32",
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
					IsaExtension::Avx512F,
				},
				.EncodingScheme =
				{
					Encoding
					{
						Evex
						{
							.Mm = 0b1,
							.Pp = 0b10,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::M32},
							.X = {OperandType::M32},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M32},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 4,
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
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vdivss",
				.GasMnemonic = "vdivss",
				.Description = "vdivss xmm, xmm, xmm",
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
							.Pp = 0b10,
							.W = false,
							.L = false,
							.R = {OperandType::Xmm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
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
				.IntelMnemonic = "vdivss",
				.GasMnemonic = "vdivss",
				.Description = "vdivss xmm, xmm, m32",
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
							.Pp = 0b10,
							.W = false,
							.L = false,
							.R = {OperandType::Xmm},
							.X = {OperandType::M32},
							.B = {OperandType::M32},
							.Vvvv = {OperandType::Xmm},
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
			InstructionVariation
			{
				.IntelMnemonic = "vdivss",
				.GasMnemonic = "vdivss",
				.Description = "vdivss xmm{k}{z}, xmm, xmm, {er}",
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
					Operand
					{
						.Type = OperandType::Er,
						.IsInput = false,
						.IsOutput = false,
						.ExtendedSize = 0
					},
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
							.Pp = 0b10,
							.W = false,
							.Ll = OperandType::Er,
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
							.Value = 0x5e,
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
		};
		out.emplace_back(std::move(instruction));

		instruction =
		{
			InstructionVariation
			{
				.IntelMnemonic = "vdppd",
				.GasMnemonic = "vdppd",
				.Description = "vdppd xmm, xmm, xmm, imm8",
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
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
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
				.IntelMnemonic = "vdppd",
				.GasMnemonic = "vdppd",
				.Description = "vdppd xmm, xmm, m128, imm8",
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
							.X = {OperandType::M128},
							.B = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
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
				.IntelMnemonic = "vdpps",
				.GasMnemonic = "vdpps",
				.Description = "vdpps xmm, xmm, xmm, imm8",
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
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
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
				.IntelMnemonic = "vdpps",
				.GasMnemonic = "vdpps",
				.Description = "vdpps xmm, xmm, m128, imm8",
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
							.X = {OperandType::M128},
							.B = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
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
			InstructionVariation
			{
				.IntelMnemonic = "vdpps",
				.GasMnemonic = "vdpps",
				.Description = "vdpps ymm, ymm, ymm, imm8",
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
							.L = true,
							.R = {OperandType::Ymm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0x40,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
							.Reg = {OperandType::Ymm},
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
				.IntelMnemonic = "vdpps",
				.GasMnemonic = "vdpps",
				.Description = "vdpps ymm, ymm, m256, imm8",
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
							.L = true,
							.R = {OperandType::Ymm},
							.X = {OperandType::M256},
							.B = {OperandType::M256},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0x40,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256},
							.Rm = {OperandType::M256},
							.Reg = {OperandType::Ymm},
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
				.IntelMnemonic = "vexp2pd",
				.GasMnemonic = "vexp2pd",
				.Description = "vexp2pd zmm{k}{z}, m512/m64bcst",
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
					IsaExtension::Avx512Er,
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
							.Value = 0xc8,
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
				.IntelMnemonic = "vexp2pd",
				.GasMnemonic = "vexp2pd",
				.Description = "vexp2pd zmm{k}{z}, zmm, {sae}",
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
						.Type = OperandType::Sae,
						.IsInput = false,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Er,
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
							.Value = 0xc8,
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
				.IntelMnemonic = "vexp2ps",
				.GasMnemonic = "vexp2ps",
				.Description = "vexp2ps zmm{k}{z}, m512/m32bcst",
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
					IsaExtension::Avx512Er,
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
							.Value = 0xc8,
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
				.IntelMnemonic = "vexp2ps",
				.GasMnemonic = "vexp2ps",
				.Description = "vexp2ps zmm{k}{z}, zmm, {sae}",
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
						.Type = OperandType::Sae,
						.IsInput = false,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
					IsaExtension::Avx512Er,
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
							.Value = 0xc8,
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
				.IntelMnemonic = "vexpandpd",
				.GasMnemonic = "vexpandpd",
				.Description = "vexpandpd xmm{k}{z}, xmm",
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
							.Value = 0x88,
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
				.IntelMnemonic = "vexpandpd",
				.GasMnemonic = "vexpandpd",
				.Description = "vexpandpd ymm{k}{z}, ymm",
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
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::Ymm},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x88,
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
				.IntelMnemonic = "vexpandpd",
				.GasMnemonic = "vexpandpd",
				.Description = "vexpandpd zmm{k}{z}, zmm",
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
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::Zmm},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x88,
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
				.IntelMnemonic = "vexpandpd",
				.GasMnemonic = "vexpandpd",
				.Description = "vexpandpd xmm{k}{z}, m128",
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
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::M128},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 8,
						},
						OpCode
						{
							.Value = 0x88,
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
				.IntelMnemonic = "vexpandpd",
				.GasMnemonic = "vexpandpd",
				.Description = "vexpandpd ymm{k}{z}, m256",
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
							.Bb = {OperandType::M256},
							.X = {OperandType::M256},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::M256},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 8,
						},
						OpCode
						{
							.Value = 0x88,
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
				.IntelMnemonic = "vexpandpd",
				.GasMnemonic = "vexpandpd",
				.Description = "vexpandpd zmm{k}{z}, m512",
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
							.Bb = {OperandType::M512},
							.X = {OperandType::M512},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::M512},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 8,
						},
						OpCode
						{
							.Value = 0x88,
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
				.IntelMnemonic = "vexpandps",
				.GasMnemonic = "vexpandps",
				.Description = "vexpandps xmm{k}{z}, xmm",
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
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x88,
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
				.IntelMnemonic = "vexpandps",
				.GasMnemonic = "vexpandps",
				.Description = "vexpandps ymm{k}{z}, ymm",
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
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::Ymm},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x88,
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
				.IntelMnemonic = "vexpandps",
				.GasMnemonic = "vexpandps",
				.Description = "vexpandps zmm{k}{z}, zmm",
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
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::Zmm},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x88,
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
				.IntelMnemonic = "vexpandps",
				.GasMnemonic = "vexpandps",
				.Description = "vexpandps xmm{k}{z}, m128",
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
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::M128},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 4,
						},
						OpCode
						{
							.Value = 0x88,
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
				.IntelMnemonic = "vexpandps",
				.GasMnemonic = "vexpandps",
				.Description = "vexpandps ymm{k}{z}, m256",
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
							.Bb = {OperandType::M256},
							.X = {OperandType::M256},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::M256},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 4,
						},
						OpCode
						{
							.Value = 0x88,
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
				.IntelMnemonic = "vexpandps",
				.GasMnemonic = "vexpandps",
				.Description = "vexpandps zmm{k}{z}, m512",
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
							.Bb = {OperandType::M512},
							.X = {OperandType::M512},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::M512},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 4,
						},
						OpCode
						{
							.Value = 0x88,
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
				.IntelMnemonic = "vextractf128",
				.GasMnemonic = "vextractf128",
				.Description = "vextractf128 xmm, ymm, imm8",
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
							.L = true,
							.R = {OperandType::Ymm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x19,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Xmm},
							.Reg = {OperandType::Ymm},
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
				.IntelMnemonic = "vextractf128",
				.GasMnemonic = "vextractf128",
				.Description = "vextractf128 m128, ymm, imm8",
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
							.L = true,
							.R = {OperandType::Ymm},
							.X = {OperandType::M128},
							.B = {OperandType::M128},
							.Vvvv = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x19,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M128},
							.Rm = {OperandType::M128},
							.Reg = {OperandType::Ymm},
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
				.IntelMnemonic = "vextractf32x4",
				.GasMnemonic = "vextractf32x4",
				.Description = "vextractf32x4 xmm{k}{z}, ymm, imm8",
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
							.Rr = {OperandType::Ymm},
							.Bb = {OperandType::XmmKz},
							.X = {OperandType::XmmKz},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::XmmKz},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x19,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::XmmKz},
							.Reg = {OperandType::Ymm},
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
				.IntelMnemonic = "vextractf32x4",
				.GasMnemonic = "vextractf32x4",
				.Description = "vextractf32x4 m128{k}{z}, ymm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::M128Kz,
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
							.Mm = 0b11,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::Ymm},
							.Bb = {OperandType::M128Kz},
							.X = {OperandType::M128Kz},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::M128Kz},
							.Aaa = {OperandType::M128Kz},
							.Z = {OperandType::M128Kz},
							.Disp8xN = 16,
						},
						OpCode
						{
							.Value = 0x19,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M128Kz},
							.Rm = {OperandType::M128Kz},
							.Reg = {OperandType::Ymm},
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
				.IntelMnemonic = "vextractf32x4",
				.GasMnemonic = "vextractf32x4",
				.Description = "vextractf32x4 xmm{k}{z}, zmm, imm8",
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
							.Rr = {OperandType::Zmm},
							.Bb = {OperandType::XmmKz},
							.X = {OperandType::XmmKz},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::XmmKz},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x19,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::XmmKz},
							.Reg = {OperandType::Zmm},
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
				.IntelMnemonic = "vextractf32x4",
				.GasMnemonic = "vextractf32x4",
				.Description = "vextractf32x4 m128{k}{z}, zmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::M128Kz,
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
							.Mm = 0b11,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::Zmm},
							.Bb = {OperandType::M128Kz},
							.X = {OperandType::M128Kz},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::M128Kz},
							.Aaa = {OperandType::M128Kz},
							.Z = {OperandType::M128Kz},
							.Disp8xN = 16,
						},
						OpCode
						{
							.Value = 0x19,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M128Kz},
							.Rm = {OperandType::M128Kz},
							.Reg = {OperandType::Zmm},
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
				.IntelMnemonic = "vextractf32x8",
				.GasMnemonic = "vextractf32x8",
				.Description = "vextractf32x8 ymm{k}{z}, zmm, imm8",
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
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::Zmm},
							.Bb = {OperandType::YmmKz},
							.X = {OperandType::YmmKz},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::YmmKz},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x1b,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::YmmKz},
							.Reg = {OperandType::Zmm},
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
				.IntelMnemonic = "vextractf32x8",
				.GasMnemonic = "vextractf32x8",
				.Description = "vextractf32x8 m256{k}{z}, zmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::M256Kz,
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
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::Zmm},
							.Bb = {OperandType::M256Kz},
							.X = {OperandType::M256Kz},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::M256Kz},
							.Aaa = {OperandType::M256Kz},
							.Z = {OperandType::M256Kz},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0x1b,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256Kz},
							.Rm = {OperandType::M256Kz},
							.Reg = {OperandType::Zmm},
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
				.IntelMnemonic = "vextractf64x2",
				.GasMnemonic = "vextractf64x2",
				.Description = "vextractf64x2 xmm{k}{z}, ymm, imm8",
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
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::Ymm},
							.Bb = {OperandType::XmmKz},
							.X = {OperandType::XmmKz},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::XmmKz},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x19,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::XmmKz},
							.Reg = {OperandType::Ymm},
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
				.IntelMnemonic = "vextractf64x2",
				.GasMnemonic = "vextractf64x2",
				.Description = "vextractf64x2 m128{k}{z}, ymm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::M128Kz,
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
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::Ymm},
							.Bb = {OperandType::M128Kz},
							.X = {OperandType::M128Kz},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::M128Kz},
							.Aaa = {OperandType::M128Kz},
							.Z = {OperandType::M128Kz},
							.Disp8xN = 16,
						},
						OpCode
						{
							.Value = 0x19,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M128Kz},
							.Rm = {OperandType::M128Kz},
							.Reg = {OperandType::Ymm},
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
				.IntelMnemonic = "vextractf64x2",
				.GasMnemonic = "vextractf64x2",
				.Description = "vextractf64x2 xmm{k}{z}, zmm, imm8",
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
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::Zmm},
							.Bb = {OperandType::XmmKz},
							.X = {OperandType::XmmKz},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::XmmKz},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x19,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::XmmKz},
							.Reg = {OperandType::Zmm},
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
				.IntelMnemonic = "vextractf64x2",
				.GasMnemonic = "vextractf64x2",
				.Description = "vextractf64x2 m128{k}{z}, zmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::M128Kz,
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
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::Zmm},
							.Bb = {OperandType::M128Kz},
							.X = {OperandType::M128Kz},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::M128Kz},
							.Aaa = {OperandType::M128Kz},
							.Z = {OperandType::M128Kz},
							.Disp8xN = 16,
						},
						OpCode
						{
							.Value = 0x19,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M128Kz},
							.Rm = {OperandType::M128Kz},
							.Reg = {OperandType::Zmm},
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
				.IntelMnemonic = "vextractf64x4",
				.GasMnemonic = "vextractf64x4",
				.Description = "vextractf64x4 ymm{k}{z}, zmm, imm8",
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
							.W = true,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::Zmm},
							.Bb = {OperandType::YmmKz},
							.X = {OperandType::YmmKz},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::YmmKz},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x1b,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::YmmKz},
							.Reg = {OperandType::Zmm},
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
				.IntelMnemonic = "vextractf64x4",
				.GasMnemonic = "vextractf64x4",
				.Description = "vextractf64x4 m256{k}{z}, zmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::M256Kz,
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
							.Mm = 0b11,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::Zmm},
							.Bb = {OperandType::M256Kz},
							.X = {OperandType::M256Kz},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::M256Kz},
							.Aaa = {OperandType::M256Kz},
							.Z = {OperandType::M256Kz},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0x1b,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256Kz},
							.Rm = {OperandType::M256Kz},
							.Reg = {OperandType::Zmm},
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
				.IntelMnemonic = "vextracti128",
				.GasMnemonic = "vextracti128",
				.Description = "vextracti128 xmm, ymm, imm8",
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
							.Mmmmm = 0b11,
							.Pp = 0b1,
							.W = false,
							.L = true,
							.R = {OperandType::Ymm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x39,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Xmm},
							.Reg = {OperandType::Ymm},
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
				.IntelMnemonic = "vextracti128",
				.GasMnemonic = "vextracti128",
				.Description = "vextracti128 m128, ymm, imm8",
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
							.Mmmmm = 0b11,
							.Pp = 0b1,
							.W = false,
							.L = true,
							.R = {OperandType::Ymm},
							.X = {OperandType::M128},
							.B = {OperandType::M128},
							.Vvvv = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x39,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M128},
							.Rm = {OperandType::M128},
							.Reg = {OperandType::Ymm},
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
				.IntelMnemonic = "vextracti32x4",
				.GasMnemonic = "vextracti32x4",
				.Description = "vextracti32x4 xmm{k}{z}, ymm, imm8",
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
							.Rr = {OperandType::Ymm},
							.Bb = {OperandType::XmmKz},
							.X = {OperandType::XmmKz},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::XmmKz},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x39,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::XmmKz},
							.Reg = {OperandType::Ymm},
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
				.IntelMnemonic = "vextracti32x4",
				.GasMnemonic = "vextracti32x4",
				.Description = "vextracti32x4 m128{k}{z}, ymm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::M128Kz,
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
							.Mm = 0b11,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::Ymm},
							.Bb = {OperandType::M128Kz},
							.X = {OperandType::M128Kz},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::M128Kz},
							.Aaa = {OperandType::M128Kz},
							.Z = {OperandType::M128Kz},
							.Disp8xN = 16,
						},
						OpCode
						{
							.Value = 0x39,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M128Kz},
							.Rm = {OperandType::M128Kz},
							.Reg = {OperandType::Ymm},
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
				.IntelMnemonic = "vextracti32x4",
				.GasMnemonic = "vextracti32x4",
				.Description = "vextracti32x4 xmm{k}{z}, zmm, imm8",
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
							.Rr = {OperandType::Zmm},
							.Bb = {OperandType::XmmKz},
							.X = {OperandType::XmmKz},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::XmmKz},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x39,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::XmmKz},
							.Reg = {OperandType::Zmm},
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
				.IntelMnemonic = "vextracti32x4",
				.GasMnemonic = "vextracti32x4",
				.Description = "vextracti32x4 m128{k}{z}, zmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::M128Kz,
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
							.Mm = 0b11,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::Zmm},
							.Bb = {OperandType::M128Kz},
							.X = {OperandType::M128Kz},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::M128Kz},
							.Aaa = {OperandType::M128Kz},
							.Z = {OperandType::M128Kz},
							.Disp8xN = 16,
						},
						OpCode
						{
							.Value = 0x39,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M128Kz},
							.Rm = {OperandType::M128Kz},
							.Reg = {OperandType::Zmm},
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
				.IntelMnemonic = "vextracti32x8",
				.GasMnemonic = "vextracti32x8",
				.Description = "vextracti32x8 ymm{k}{z}, zmm, imm8",
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
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::Zmm},
							.Bb = {OperandType::YmmKz},
							.X = {OperandType::YmmKz},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::YmmKz},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x3b,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::YmmKz},
							.Reg = {OperandType::Zmm},
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
				.IntelMnemonic = "vextracti32x8",
				.GasMnemonic = "vextracti32x8",
				.Description = "vextracti32x8 m256{k}{z}, zmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::M256Kz,
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
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::Zmm},
							.Bb = {OperandType::M256Kz},
							.X = {OperandType::M256Kz},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::M256Kz},
							.Aaa = {OperandType::M256Kz},
							.Z = {OperandType::M256Kz},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0x3b,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256Kz},
							.Rm = {OperandType::M256Kz},
							.Reg = {OperandType::Zmm},
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
				.IntelMnemonic = "vextracti64x2",
				.GasMnemonic = "vextracti64x2",
				.Description = "vextracti64x2 xmm{k}{z}, ymm, imm8",
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
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::Ymm},
							.Bb = {OperandType::XmmKz},
							.X = {OperandType::XmmKz},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::XmmKz},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x39,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::XmmKz},
							.Reg = {OperandType::Ymm},
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
				.IntelMnemonic = "vextracti64x2",
				.GasMnemonic = "vextracti64x2",
				.Description = "vextracti64x2 m128{k}{z}, ymm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::M128Kz,
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
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::Ymm},
							.Bb = {OperandType::M128Kz},
							.X = {OperandType::M128Kz},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::M128Kz},
							.Aaa = {OperandType::M128Kz},
							.Z = {OperandType::M128Kz},
							.Disp8xN = 16,
						},
						OpCode
						{
							.Value = 0x39,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M128Kz},
							.Rm = {OperandType::M128Kz},
							.Reg = {OperandType::Ymm},
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
				.IntelMnemonic = "vextracti64x2",
				.GasMnemonic = "vextracti64x2",
				.Description = "vextracti64x2 xmm{k}{z}, zmm, imm8",
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
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::Zmm},
							.Bb = {OperandType::XmmKz},
							.X = {OperandType::XmmKz},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::XmmKz},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x39,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::XmmKz},
							.Reg = {OperandType::Zmm},
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
				.IntelMnemonic = "vextracti64x2",
				.GasMnemonic = "vextracti64x2",
				.Description = "vextracti64x2 m128{k}{z}, zmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::M128Kz,
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
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::Zmm},
							.Bb = {OperandType::M128Kz},
							.X = {OperandType::M128Kz},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::M128Kz},
							.Aaa = {OperandType::M128Kz},
							.Z = {OperandType::M128Kz},
							.Disp8xN = 16,
						},
						OpCode
						{
							.Value = 0x39,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M128Kz},
							.Rm = {OperandType::M128Kz},
							.Reg = {OperandType::Zmm},
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
				.IntelMnemonic = "vextracti64x4",
				.GasMnemonic = "vextracti64x4",
				.Description = "vextracti64x4 ymm{k}{z}, zmm, imm8",
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
							.W = true,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::Zmm},
							.Bb = {OperandType::YmmKz},
							.X = {OperandType::YmmKz},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::YmmKz},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x3b,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::YmmKz},
							.Reg = {OperandType::Zmm},
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
				.IntelMnemonic = "vextracti64x4",
				.GasMnemonic = "vextracti64x4",
				.Description = "vextracti64x4 m256{k}{z}, zmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::M256Kz,
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
							.Mm = 0b11,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::Zmm},
							.Bb = {OperandType::M256Kz},
							.X = {OperandType::M256Kz},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::M256Kz},
							.Aaa = {OperandType::M256Kz},
							.Z = {OperandType::M256Kz},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0x3b,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256Kz},
							.Rm = {OperandType::M256Kz},
							.Reg = {OperandType::Zmm},
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
				.IntelMnemonic = "vextractps",
				.GasMnemonic = "vextractps",
				.Description = "vextractps r32, xmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
							.Vvvv = {UINT64_C(0x0)},
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
				.IntelMnemonic = "vextractps",
				.GasMnemonic = "vextractps",
				.Description = "vextractps r32, xmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
							.Rr = {OperandType::Xmm},
							.Bb = {OperandType::R32},
							.X = {OperandType::R32},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::R32},
							.Aaa = {UINT64_C(0x0)},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
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
				.IntelMnemonic = "vextractps",
				.GasMnemonic = "vextractps",
				.Description = "vextractps m32, xmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
							.Vvvv = {UINT64_C(0x0)},
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
			InstructionVariation
			{
				.IntelMnemonic = "vextractps",
				.GasMnemonic = "vextractps",
				.Description = "vextractps m32, xmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
							.Rr = {OperandType::Xmm},
							.Bb = {OperandType::M32},
							.X = {OperandType::M32},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::M32},
							.Aaa = {UINT64_C(0x0)},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 4,
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
				.IntelMnemonic = "vfixupimmpd",
				.GasMnemonic = "vfixupimmpd",
				.Description = "vfixupimmpd xmm{k}{z}, xmm, m128/m64bcst, imm8",
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
							.Value = 0x54,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M128M64Bcst},
							.Rm = {OperandType::M128M64Bcst},
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
				.IntelMnemonic = "vfixupimmpd",
				.GasMnemonic = "vfixupimmpd",
				.Description = "vfixupimmpd xmm{k}{z}, xmm, xmm, imm8",
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
							.Value = 0x54,
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
				.IntelMnemonic = "vfixupimmpd",
				.GasMnemonic = "vfixupimmpd",
				.Description = "vfixupimmpd ymm{k}{z}, ymm, m256/m64bcst, imm8",
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
							.Value = 0x54,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256M64Bcst},
							.Rm = {OperandType::M256M64Bcst},
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
				.IntelMnemonic = "vfixupimmpd",
				.GasMnemonic = "vfixupimmpd",
				.Description = "vfixupimmpd ymm{k}{z}, ymm, ymm, imm8",
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
							.Value = 0x54,
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
				.IntelMnemonic = "vfixupimmpd",
				.GasMnemonic = "vfixupimmpd",
				.Description = "vfixupimmpd zmm{k}{z}, zmm, m512/m64bcst, imm8",
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
							.Value = 0x54,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M512M64Bcst},
							.Rm = {OperandType::M512M64Bcst},
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
				.IntelMnemonic = "vfixupimmpd",
				.GasMnemonic = "vfixupimmpd",
				.Description = "vfixupimmpd zmm{k}{z}, zmm, zmm, {sae}, imm8",
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
						.Type = OperandType::Sae,
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
							.Value = 0x54,
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

		instruction =
		{
			InstructionVariation
			{
				.IntelMnemonic = "vfixupimmps",
				.GasMnemonic = "vfixupimmps",
				.Description = "vfixupimmps xmm{k}{z}, xmm, m128/m32bcst, imm8",
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
							.Value = 0x54,
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
				.IntelMnemonic = "vfixupimmps",
				.GasMnemonic = "vfixupimmps",
				.Description = "vfixupimmps xmm{k}{z}, xmm, xmm, imm8",
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
							.Value = 0x54,
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
				.IntelMnemonic = "vfixupimmps",
				.GasMnemonic = "vfixupimmps",
				.Description = "vfixupimmps ymm{k}{z}, ymm, m256/m32bcst, imm8",
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
							.Value = 0x54,
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
				.IntelMnemonic = "vfixupimmps",
				.GasMnemonic = "vfixupimmps",
				.Description = "vfixupimmps ymm{k}{z}, ymm, ymm, imm8",
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
							.Value = 0x54,
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
				.IntelMnemonic = "vfixupimmps",
				.GasMnemonic = "vfixupimmps",
				.Description = "vfixupimmps zmm{k}{z}, zmm, m512/m32bcst, imm8",
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
							.Value = 0x54,
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
				.IntelMnemonic = "vfixupimmps",
				.GasMnemonic = "vfixupimmps",
				.Description = "vfixupimmps zmm{k}{z}, zmm, zmm, {sae}, imm8",
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
						.Type = OperandType::Sae,
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
							.Value = 0x54,
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

		instruction =
		{
			InstructionVariation
			{
				.IntelMnemonic = "vfixupimmsd",
				.GasMnemonic = "vfixupimmsd",
				.Description = "vfixupimmsd xmm{k}{z}, xmm, m64, imm8",
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
							.W = true,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::XmmKz},
							.Bb = {OperandType::M64},
							.X = {OperandType::M64},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M64},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 8,
						},
						OpCode
						{
							.Value = 0x55,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M64},
							.Rm = {OperandType::M64},
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
				.IntelMnemonic = "vfixupimmsd",
				.GasMnemonic = "vfixupimmsd",
				.Description = "vfixupimmsd xmm{k}{z}, xmm, xmm, {sae}, imm8",
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
						.Type = OperandType::Sae,
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
							.Value = 0x55,
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
		};
		out.emplace_back(std::move(instruction));

		instruction =
		{
			InstructionVariation
			{
				.IntelMnemonic = "vfixupimmss",
				.GasMnemonic = "vfixupimmss",
				.Description = "vfixupimmss xmm{k}{z}, xmm, m32, imm8",
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
							.Bb = {OperandType::M32},
							.X = {OperandType::M32},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M32},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 4,
						},
						OpCode
						{
							.Value = 0x55,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M32},
							.Rm = {OperandType::M32},
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
				.IntelMnemonic = "vfixupimmss",
				.GasMnemonic = "vfixupimmss",
				.Description = "vfixupimmss xmm{k}{z}, xmm, xmm, {sae}, imm8",
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
						.Type = OperandType::Sae,
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
							.Value = 0x55,
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
		};
		out.emplace_back(std::move(instruction));

		instruction =
		{
			InstructionVariation
			{
				.IntelMnemonic = "vfmadd132pd",
				.GasMnemonic = "vfmadd132pd",
				.Description = "vfmadd132pd xmm{k}{z}, xmm, m128/m64bcst",
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
							.Value = 0x98,
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
				.IntelMnemonic = "vfmadd132pd",
				.GasMnemonic = "vfmadd132pd",
				.Description = "vfmadd132pd xmm{k}{z}, xmm, xmm",
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
							.Value = 0x98,
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
				.IntelMnemonic = "vfmadd132pd",
				.GasMnemonic = "vfmadd132pd",
				.Description = "vfmadd132pd ymm{k}{z}, ymm, m256/m64bcst",
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
							.Value = 0x98,
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
				.IntelMnemonic = "vfmadd132pd",
				.GasMnemonic = "vfmadd132pd",
				.Description = "vfmadd132pd ymm{k}{z}, ymm, ymm",
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
							.Value = 0x98,
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
				.IntelMnemonic = "vfmadd132pd",
				.GasMnemonic = "vfmadd132pd",
				.Description = "vfmadd132pd zmm{k}{z}, zmm, m512/m64bcst",
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
							.Value = 0x98,
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
				.IntelMnemonic = "vfmadd132pd",
				.GasMnemonic = "vfmadd132pd",
				.Description = "vfmadd132pd xmm, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Fma3,
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
							.Value = 0x98,
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
				.IntelMnemonic = "vfmadd132pd",
				.GasMnemonic = "vfmadd132pd",
				.Description = "vfmadd132pd xmm, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Fma3,
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
							.Value = 0x98,
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
				.IntelMnemonic = "vfmadd132pd",
				.GasMnemonic = "vfmadd132pd",
				.Description = "vfmadd132pd ymm, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Fma3,
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
							.Value = 0x98,
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
				.IntelMnemonic = "vfmadd132pd",
				.GasMnemonic = "vfmadd132pd",
				.Description = "vfmadd132pd ymm, ymm, m256",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Fma3,
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
							.Value = 0x98,
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
				.IntelMnemonic = "vfmadd132pd",
				.GasMnemonic = "vfmadd132pd",
				.Description = "vfmadd132pd zmm{k}{z}, zmm, zmm, {er}",
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
						.Type = OperandType::Er,
						.IsInput = false,
						.IsOutput = false,
						.ExtendedSize = 0
					},
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
							.Ll = OperandType::Er,
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
							.Value = 0x98,
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
				.IntelMnemonic = "vfmadd132ps",
				.GasMnemonic = "vfmadd132ps",
				.Description = "vfmadd132ps xmm{k}{z}, xmm, m128/m32bcst",
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
							.Value = 0x98,
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
				.IntelMnemonic = "vfmadd132ps",
				.GasMnemonic = "vfmadd132ps",
				.Description = "vfmadd132ps xmm{k}{z}, xmm, xmm",
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
							.Value = 0x98,
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
				.IntelMnemonic = "vfmadd132ps",
				.GasMnemonic = "vfmadd132ps",
				.Description = "vfmadd132ps ymm{k}{z}, ymm, m256/m32bcst",
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
							.Value = 0x98,
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
				.IntelMnemonic = "vfmadd132ps",
				.GasMnemonic = "vfmadd132ps",
				.Description = "vfmadd132ps ymm{k}{z}, ymm, ymm",
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
							.Value = 0x98,
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
				.IntelMnemonic = "vfmadd132ps",
				.GasMnemonic = "vfmadd132ps",
				.Description = "vfmadd132ps zmm{k}{z}, zmm, m512/m32bcst",
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
							.Value = 0x98,
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
				.IntelMnemonic = "vfmadd132ps",
				.GasMnemonic = "vfmadd132ps",
				.Description = "vfmadd132ps xmm, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Fma3,
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
							.Value = 0x98,
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
				.IntelMnemonic = "vfmadd132ps",
				.GasMnemonic = "vfmadd132ps",
				.Description = "vfmadd132ps xmm, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Fma3,
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
							.Value = 0x98,
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
				.IntelMnemonic = "vfmadd132ps",
				.GasMnemonic = "vfmadd132ps",
				.Description = "vfmadd132ps ymm, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Fma3,
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
							.Value = 0x98,
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
				.IntelMnemonic = "vfmadd132ps",
				.GasMnemonic = "vfmadd132ps",
				.Description = "vfmadd132ps ymm, ymm, m256",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Fma3,
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
							.Value = 0x98,
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
				.IntelMnemonic = "vfmadd132ps",
				.GasMnemonic = "vfmadd132ps",
				.Description = "vfmadd132ps zmm{k}{z}, zmm, zmm, {er}",
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
						.Type = OperandType::Er,
						.IsInput = false,
						.IsOutput = false,
						.ExtendedSize = 0
					},
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
							.Ll = OperandType::Er,
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
							.Value = 0x98,
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
				.IntelMnemonic = "vfmadd132sd",
				.GasMnemonic = "vfmadd132sd",
				.Description = "vfmadd132sd xmm{k}{z}, xmm, m64",
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
							.Bb = {OperandType::M64},
							.X = {OperandType::M64},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M64},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 8,
						},
						OpCode
						{
							.Value = 0x99,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M64},
							.Rm = {OperandType::M64},
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vfmadd132sd",
				.GasMnemonic = "vfmadd132sd",
				.Description = "vfmadd132sd xmm, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Fma3,
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
							.Value = 0x99,
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
				.IntelMnemonic = "vfmadd132sd",
				.GasMnemonic = "vfmadd132sd",
				.Description = "vfmadd132sd xmm, xmm, m64",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Fma3,
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
							.X = {OperandType::M64},
							.B = {OperandType::M64},
							.Vvvv = {OperandType::Xmm},
						},
						OpCode
						{
							.Value = 0x99,
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
			InstructionVariation
			{
				.IntelMnemonic = "vfmadd132sd",
				.GasMnemonic = "vfmadd132sd",
				.Description = "vfmadd132sd xmm{k}{z}, xmm, xmm, {er}",
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
						.Type = OperandType::Er,
						.IsInput = false,
						.IsOutput = false,
						.ExtendedSize = 0
					},
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
							.Ll = OperandType::Er,
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
							.Value = 0x99,
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
		};
		out.emplace_back(std::move(instruction));

		instruction =
		{
			InstructionVariation
			{
				.IntelMnemonic = "vfmadd132ss",
				.GasMnemonic = "vfmadd132ss",
				.Description = "vfmadd132ss xmm{k}{z}, xmm, m32",
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
							.Bb = {OperandType::M32},
							.X = {OperandType::M32},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M32},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 4,
						},
						OpCode
						{
							.Value = 0x99,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M32},
							.Rm = {OperandType::M32},
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vfmadd132ss",
				.GasMnemonic = "vfmadd132ss",
				.Description = "vfmadd132ss xmm, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Fma3,
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
							.Value = 0x99,
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
				.IntelMnemonic = "vfmadd132ss",
				.GasMnemonic = "vfmadd132ss",
				.Description = "vfmadd132ss xmm, xmm, m32",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Fma3,
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
							.X = {OperandType::M32},
							.B = {OperandType::M32},
							.Vvvv = {OperandType::Xmm},
						},
						OpCode
						{
							.Value = 0x99,
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
			InstructionVariation
			{
				.IntelMnemonic = "vfmadd132ss",
				.GasMnemonic = "vfmadd132ss",
				.Description = "vfmadd132ss xmm{k}{z}, xmm, xmm, {er}",
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
						.Type = OperandType::Er,
						.IsInput = false,
						.IsOutput = false,
						.ExtendedSize = 0
					},
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
							.Ll = OperandType::Er,
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
							.Value = 0x99,
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
		};
		out.emplace_back(std::move(instruction));

		instruction =
		{
			InstructionVariation
			{
				.IntelMnemonic = "vfmadd213pd",
				.GasMnemonic = "vfmadd213pd",
				.Description = "vfmadd213pd xmm{k}{z}, xmm, m128/m64bcst",
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
							.Value = 0xa8,
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
				.IntelMnemonic = "vfmadd213pd",
				.GasMnemonic = "vfmadd213pd",
				.Description = "vfmadd213pd xmm{k}{z}, xmm, xmm",
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
							.Value = 0xa8,
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
				.IntelMnemonic = "vfmadd213pd",
				.GasMnemonic = "vfmadd213pd",
				.Description = "vfmadd213pd ymm{k}{z}, ymm, m256/m64bcst",
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
							.Value = 0xa8,
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
				.IntelMnemonic = "vfmadd213pd",
				.GasMnemonic = "vfmadd213pd",
				.Description = "vfmadd213pd ymm{k}{z}, ymm, ymm",
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
							.Value = 0xa8,
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
				.IntelMnemonic = "vfmadd213pd",
				.GasMnemonic = "vfmadd213pd",
				.Description = "vfmadd213pd zmm{k}{z}, zmm, m512/m64bcst",
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
							.Value = 0xa8,
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
				.IntelMnemonic = "vfmadd213pd",
				.GasMnemonic = "vfmadd213pd",
				.Description = "vfmadd213pd xmm, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Fma3,
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
							.Value = 0xa8,
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
				.IntelMnemonic = "vfmadd213pd",
				.GasMnemonic = "vfmadd213pd",
				.Description = "vfmadd213pd xmm, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Fma3,
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
							.Value = 0xa8,
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
				.IntelMnemonic = "vfmadd213pd",
				.GasMnemonic = "vfmadd213pd",
				.Description = "vfmadd213pd ymm, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Fma3,
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
							.Value = 0xa8,
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
				.IntelMnemonic = "vfmadd213pd",
				.GasMnemonic = "vfmadd213pd",
				.Description = "vfmadd213pd ymm, ymm, m256",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Fma3,
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
							.Value = 0xa8,
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
				.IntelMnemonic = "vfmadd213pd",
				.GasMnemonic = "vfmadd213pd",
				.Description = "vfmadd213pd zmm{k}{z}, zmm, zmm, {er}",
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
						.Type = OperandType::Er,
						.IsInput = false,
						.IsOutput = false,
						.ExtendedSize = 0
					},
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
							.Ll = OperandType::Er,
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
							.Value = 0xa8,
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
				.IntelMnemonic = "vfmadd213ps",
				.GasMnemonic = "vfmadd213ps",
				.Description = "vfmadd213ps xmm{k}{z}, xmm, m128/m32bcst",
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
							.Value = 0xa8,
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
				.IntelMnemonic = "vfmadd213ps",
				.GasMnemonic = "vfmadd213ps",
				.Description = "vfmadd213ps xmm{k}{z}, xmm, xmm",
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
							.Value = 0xa8,
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
				.IntelMnemonic = "vfmadd213ps",
				.GasMnemonic = "vfmadd213ps",
				.Description = "vfmadd213ps ymm{k}{z}, ymm, m256/m32bcst",
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
							.Value = 0xa8,
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
				.IntelMnemonic = "vfmadd213ps",
				.GasMnemonic = "vfmadd213ps",
				.Description = "vfmadd213ps ymm{k}{z}, ymm, ymm",
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
							.Value = 0xa8,
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
				.IntelMnemonic = "vfmadd213ps",
				.GasMnemonic = "vfmadd213ps",
				.Description = "vfmadd213ps zmm{k}{z}, zmm, m512/m32bcst",
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
							.Value = 0xa8,
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
				.IntelMnemonic = "vfmadd213ps",
				.GasMnemonic = "vfmadd213ps",
				.Description = "vfmadd213ps xmm, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Fma3,
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
							.Value = 0xa8,
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
				.IntelMnemonic = "vfmadd213ps",
				.GasMnemonic = "vfmadd213ps",
				.Description = "vfmadd213ps xmm, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Fma3,
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
							.Value = 0xa8,
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
				.IntelMnemonic = "vfmadd213ps",
				.GasMnemonic = "vfmadd213ps",
				.Description = "vfmadd213ps ymm, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Fma3,
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
							.Value = 0xa8,
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
				.IntelMnemonic = "vfmadd213ps",
				.GasMnemonic = "vfmadd213ps",
				.Description = "vfmadd213ps ymm, ymm, m256",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Fma3,
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
							.Value = 0xa8,
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
				.IntelMnemonic = "vfmadd213ps",
				.GasMnemonic = "vfmadd213ps",
				.Description = "vfmadd213ps zmm{k}{z}, zmm, zmm, {er}",
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
						.Type = OperandType::Er,
						.IsInput = false,
						.IsOutput = false,
						.ExtendedSize = 0
					},
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
							.Ll = OperandType::Er,
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
							.Value = 0xa8,
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
				.IntelMnemonic = "vfmadd213sd",
				.GasMnemonic = "vfmadd213sd",
				.Description = "vfmadd213sd xmm{k}{z}, xmm, m64",
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
							.Bb = {OperandType::M64},
							.X = {OperandType::M64},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M64},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 8,
						},
						OpCode
						{
							.Value = 0xa9,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M64},
							.Rm = {OperandType::M64},
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vfmadd213sd",
				.GasMnemonic = "vfmadd213sd",
				.Description = "vfmadd213sd xmm, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Fma3,
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
							.Value = 0xa9,
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
				.IntelMnemonic = "vfmadd213sd",
				.GasMnemonic = "vfmadd213sd",
				.Description = "vfmadd213sd xmm, xmm, m64",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Fma3,
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
							.X = {OperandType::M64},
							.B = {OperandType::M64},
							.Vvvv = {OperandType::Xmm},
						},
						OpCode
						{
							.Value = 0xa9,
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
			InstructionVariation
			{
				.IntelMnemonic = "vfmadd213sd",
				.GasMnemonic = "vfmadd213sd",
				.Description = "vfmadd213sd xmm{k}{z}, xmm, xmm, {er}",
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
						.Type = OperandType::Er,
						.IsInput = false,
						.IsOutput = false,
						.ExtendedSize = 0
					},
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
							.Ll = OperandType::Er,
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
							.Value = 0xa9,
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
		};
		out.emplace_back(std::move(instruction));

		instruction =
		{
			InstructionVariation
			{
				.IntelMnemonic = "vfmadd213ss",
				.GasMnemonic = "vfmadd213ss",
				.Description = "vfmadd213ss xmm{k}{z}, xmm, m32",
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
							.Bb = {OperandType::M32},
							.X = {OperandType::M32},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M32},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 4,
						},
						OpCode
						{
							.Value = 0xa9,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M32},
							.Rm = {OperandType::M32},
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vfmadd213ss",
				.GasMnemonic = "vfmadd213ss",
				.Description = "vfmadd213ss xmm, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Fma3,
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
							.Value = 0xa9,
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
				.IntelMnemonic = "vfmadd213ss",
				.GasMnemonic = "vfmadd213ss",
				.Description = "vfmadd213ss xmm, xmm, m32",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Fma3,
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
							.X = {OperandType::M32},
							.B = {OperandType::M32},
							.Vvvv = {OperandType::Xmm},
						},
						OpCode
						{
							.Value = 0xa9,
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
			InstructionVariation
			{
				.IntelMnemonic = "vfmadd213ss",
				.GasMnemonic = "vfmadd213ss",
				.Description = "vfmadd213ss xmm{k}{z}, xmm, xmm, {er}",
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
						.Type = OperandType::Er,
						.IsInput = false,
						.IsOutput = false,
						.ExtendedSize = 0
					},
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
							.Ll = OperandType::Er,
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
							.Value = 0xa9,
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
		};
		out.emplace_back(std::move(instruction));

		instruction =
		{
			InstructionVariation
			{
				.IntelMnemonic = "vfmadd231pd",
				.GasMnemonic = "vfmadd231pd",
				.Description = "vfmadd231pd xmm{k}{z}, xmm, m128/m64bcst",
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
							.Value = 0xb8,
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
				.IntelMnemonic = "vfmadd231pd",
				.GasMnemonic = "vfmadd231pd",
				.Description = "vfmadd231pd xmm{k}{z}, xmm, xmm",
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
							.Value = 0xb8,
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
				.IntelMnemonic = "vfmadd231pd",
				.GasMnemonic = "vfmadd231pd",
				.Description = "vfmadd231pd ymm{k}{z}, ymm, m256/m64bcst",
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
							.Value = 0xb8,
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
				.IntelMnemonic = "vfmadd231pd",
				.GasMnemonic = "vfmadd231pd",
				.Description = "vfmadd231pd ymm{k}{z}, ymm, ymm",
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
							.Value = 0xb8,
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
				.IntelMnemonic = "vfmadd231pd",
				.GasMnemonic = "vfmadd231pd",
				.Description = "vfmadd231pd zmm{k}{z}, zmm, m512/m64bcst",
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
							.Value = 0xb8,
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
				.IntelMnemonic = "vfmadd231pd",
				.GasMnemonic = "vfmadd231pd",
				.Description = "vfmadd231pd xmm, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Fma3,
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
							.Value = 0xb8,
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
				.IntelMnemonic = "vfmadd231pd",
				.GasMnemonic = "vfmadd231pd",
				.Description = "vfmadd231pd xmm, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
					IsaExtension::Fma3,
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
							.Value = 0xb8,
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
				.IntelMnemonic = "vfmadd231pd",
				.GasMnemonic = "vfmadd231pd",
				.Description = "vfmadd231pd ymm, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Fma3,
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
							.Value = 0xb8,
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
				.IntelMnemonic = "vfmadd231pd",
				.GasMnemonic = "vfmadd231pd",
				.Description = "vfmadd231pd ymm, ymm, m256",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Ymm,
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
					IsaExtension::Fma3,
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
							.Value = 0xb8,
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
				.IntelMnemonic = "vfmadd231pd",
				.GasMnemonic = "vfmadd231pd",
				.Description = "vfmadd231pd zmm{k}{z}, zmm, zmm, {er}",
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
						.Type = OperandType::Er,
						.IsInput = false,
						.IsOutput = false,
						.ExtendedSize = 0
					},
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
							.Ll = OperandType::Er,
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
							.Value = 0xb8,
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
