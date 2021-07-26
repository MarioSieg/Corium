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
NOX_NEVER_INLINE NOX_COLD auto GetVariationTable_32(std::pmr::monotonic_buffer_resource& allocator, std::pmr::vector<InstructionVariationPool>& out) -> void
{
	std::pmr::vector<InstructionVariation> instruction{&allocator};
	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "vpmovsxbd",
			.GasMnemonic = "vpmovsxbd",
			.Description = "vpmovsxbd xmm{k}{z}, xmm",
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
						.Value = 0x21,
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
			.IntelMnemonic = "vpmovsxbd",
			.GasMnemonic = "vpmovsxbd",
			.Description = "vpmovsxbd ymm{k}{z}, xmm",
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
						.Ll = UINT64_C(0x1),
						.Rr = {OperandType::YmmKz},
						.Bb = {OperandType::Xmm},
						.X = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Aaa = {OperandType::YmmKz},
						.Z = {OperandType::YmmKz},
						.Disp8xN = 0,
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
						.Reg = {OperandType::YmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovsxbd",
			.GasMnemonic = "vpmovsxbd",
			.Description = "vpmovsxbd zmm{k}{z}, xmm",
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
						.Mm = 0b10,
						.Pp = 0b1,
						.W = false,
						.Ll = UINT64_C(0x2),
						.Rr = {OperandType::ZmmKz},
						.Bb = {OperandType::Xmm},
						.X = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Aaa = {OperandType::ZmmKz},
						.Z = {OperandType::ZmmKz},
						.Disp8xN = 0,
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
						.Reg = {OperandType::ZmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovsxbd",
			.GasMnemonic = "vpmovsxbd",
			.Description = "vpmovsxbd xmm{k}{z}, m32",
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
						.Bb = {OperandType::M32},
						.X = {OperandType::M32},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M32},
						.Aaa = {OperandType::XmmKz},
						.Z = {OperandType::XmmKz},
						.Disp8xN = 4,
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
						.Reg = {OperandType::XmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovsxbd",
			.GasMnemonic = "vpmovsxbd",
			.Description = "vpmovsxbd ymm{k}{z}, m64",
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
						.Bb = {OperandType::M64},
						.X = {OperandType::M64},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M64},
						.Aaa = {OperandType::YmmKz},
						.Z = {OperandType::YmmKz},
						.Disp8xN = 8,
					},
					OpCode
					{
						.Value = 0x21,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::YmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovsxbd",
			.GasMnemonic = "vpmovsxbd",
			.Description = "vpmovsxbd zmm{k}{z}, m128",
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
						.Mm = 0b10,
						.Pp = 0b1,
						.W = false,
						.Ll = UINT64_C(0x2),
						.Rr = {OperandType::ZmmKz},
						.Bb = {OperandType::M128},
						.X = {OperandType::M128},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M128},
						.Aaa = {OperandType::ZmmKz},
						.Z = {OperandType::ZmmKz},
						.Disp8xN = 16,
					},
					OpCode
					{
						.Value = 0x21,
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
			.IntelMnemonic = "vpmovsxbd",
			.GasMnemonic = "vpmovsxbd",
			.Description = "vpmovsxbd xmm, xmm",
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
						.Vvvv = {UINT64_C(0x0)},
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
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovsxbd",
			.GasMnemonic = "vpmovsxbd",
			.Description = "vpmovsxbd xmm, m32",
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
						.Mmmmm = 0b10,
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
						.Value = 0x21,
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
			.IntelMnemonic = "vpmovsxbd",
			.GasMnemonic = "vpmovsxbd",
			.Description = "vpmovsxbd ymm, xmm",
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
						.L = true,
						.R = {OperandType::Ymm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
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
						.Reg = {OperandType::Ymm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovsxbd",
			.GasMnemonic = "vpmovsxbd",
			.Description = "vpmovsxbd ymm, m64",
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
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x21,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
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
			.IntelMnemonic = "vpmovsxbq",
			.GasMnemonic = "vpmovsxbq",
			.Description = "vpmovsxbq xmm{k}{z}, xmm",
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
						.Value = 0x22,
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
			.IntelMnemonic = "vpmovsxbq",
			.GasMnemonic = "vpmovsxbq",
			.Description = "vpmovsxbq ymm{k}{z}, xmm",
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
						.Ll = UINT64_C(0x1),
						.Rr = {OperandType::YmmKz},
						.Bb = {OperandType::Xmm},
						.X = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Aaa = {OperandType::YmmKz},
						.Z = {OperandType::YmmKz},
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
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::YmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovsxbq",
			.GasMnemonic = "vpmovsxbq",
			.Description = "vpmovsxbq zmm{k}{z}, xmm",
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
						.Mm = 0b10,
						.Pp = 0b1,
						.W = false,
						.Ll = UINT64_C(0x2),
						.Rr = {OperandType::ZmmKz},
						.Bb = {OperandType::Xmm},
						.X = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Aaa = {OperandType::ZmmKz},
						.Z = {OperandType::ZmmKz},
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
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::ZmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovsxbq",
			.GasMnemonic = "vpmovsxbq",
			.Description = "vpmovsxbq xmm{k}{z}, m16",
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
						.Bb = {OperandType::M16},
						.X = {OperandType::M16},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M16},
						.Aaa = {OperandType::XmmKz},
						.Z = {OperandType::XmmKz},
						.Disp8xN = 2,
					},
					OpCode
					{
						.Value = 0x22,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M16},
						.Rm = {OperandType::M16},
						.Reg = {OperandType::XmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovsxbq",
			.GasMnemonic = "vpmovsxbq",
			.Description = "vpmovsxbq ymm{k}{z}, m32",
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
						.Bb = {OperandType::M32},
						.X = {OperandType::M32},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M32},
						.Aaa = {OperandType::YmmKz},
						.Z = {OperandType::YmmKz},
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
						.Reg = {OperandType::YmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovsxbq",
			.GasMnemonic = "vpmovsxbq",
			.Description = "vpmovsxbq zmm{k}{z}, m64",
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
						.W = false,
						.Ll = UINT64_C(0x2),
						.Rr = {OperandType::ZmmKz},
						.Bb = {OperandType::M64},
						.X = {OperandType::M64},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M64},
						.Aaa = {OperandType::ZmmKz},
						.Z = {OperandType::ZmmKz},
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
						.Reg = {OperandType::ZmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovsxbq",
			.GasMnemonic = "vpmovsxbq",
			.Description = "vpmovsxbq xmm, xmm",
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
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x22,
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
			.IntelMnemonic = "vpmovsxbq",
			.GasMnemonic = "vpmovsxbq",
			.Description = "vpmovsxbq xmm, m16",
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
						.X = {OperandType::M16},
						.B = {OperandType::M16},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x22,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M16},
						.Rm = {OperandType::M16},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovsxbq",
			.GasMnemonic = "vpmovsxbq",
			.Description = "vpmovsxbq ymm, xmm",
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
						.L = true,
						.R = {OperandType::Ymm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x22,
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
			.IntelMnemonic = "vpmovsxbq",
			.GasMnemonic = "vpmovsxbq",
			.Description = "vpmovsxbq ymm, m32",
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
						.X = {OperandType::M32},
						.B = {OperandType::M32},
						.Vvvv = {UINT64_C(0x0)},
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
			.IntelMnemonic = "vpmovsxbw",
			.GasMnemonic = "vpmovsxbw",
			.Description = "vpmovsxbw xmm{k}{z}, xmm",
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
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Aaa = {OperandType::XmmKz},
						.Z = {OperandType::XmmKz},
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
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::XmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovsxbw",
			.GasMnemonic = "vpmovsxbw",
			.Description = "vpmovsxbw ymm{k}{z}, xmm",
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
						.Ll = UINT64_C(0x1),
						.Rr = {OperandType::YmmKz},
						.Bb = {OperandType::Xmm},
						.X = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Aaa = {OperandType::YmmKz},
						.Z = {OperandType::YmmKz},
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
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::YmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovsxbw",
			.GasMnemonic = "vpmovsxbw",
			.Description = "vpmovsxbw zmm{k}{z}, ymm",
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
						.Bb = {OperandType::Ymm},
						.X = {OperandType::Ymm},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Ymm},
						.Aaa = {OperandType::ZmmKz},
						.Z = {OperandType::ZmmKz},
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
						.Rm = {OperandType::Ymm},
						.Reg = {OperandType::ZmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovsxbw",
			.GasMnemonic = "vpmovsxbw",
			.Description = "vpmovsxbw xmm{k}{z}, m64",
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
						.Bb = {OperandType::M64},
						.X = {OperandType::M64},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M64},
						.Aaa = {OperandType::XmmKz},
						.Z = {OperandType::XmmKz},
						.Disp8xN = 8,
					},
					OpCode
					{
						.Value = 0x20,
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
			.IntelMnemonic = "vpmovsxbw",
			.GasMnemonic = "vpmovsxbw",
			.Description = "vpmovsxbw ymm{k}{z}, m128",
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
						.Ll = UINT64_C(0x1),
						.Rr = {OperandType::YmmKz},
						.Bb = {OperandType::M128},
						.X = {OperandType::M128},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M128},
						.Aaa = {OperandType::YmmKz},
						.Z = {OperandType::YmmKz},
						.Disp8xN = 16,
					},
					OpCode
					{
						.Value = 0x20,
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
			.IntelMnemonic = "vpmovsxbw",
			.GasMnemonic = "vpmovsxbw",
			.Description = "vpmovsxbw zmm{k}{z}, m256",
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
						.Bb = {OperandType::M256},
						.X = {OperandType::M256},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M256},
						.Aaa = {OperandType::ZmmKz},
						.Z = {OperandType::ZmmKz},
						.Disp8xN = 32,
					},
					OpCode
					{
						.Value = 0x20,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M256},
						.Rm = {OperandType::M256},
						.Reg = {OperandType::ZmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovsxbw",
			.GasMnemonic = "vpmovsxbw",
			.Description = "vpmovsxbw xmm, xmm",
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
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x20,
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
			.IntelMnemonic = "vpmovsxbw",
			.GasMnemonic = "vpmovsxbw",
			.Description = "vpmovsxbw xmm, m64",
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
						.Mmmmm = 0b10,
						.Pp = 0b1,
						.W = false,
						.L = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x20,
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
			.IntelMnemonic = "vpmovsxbw",
			.GasMnemonic = "vpmovsxbw",
			.Description = "vpmovsxbw ymm, xmm",
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
						.L = true,
						.R = {OperandType::Ymm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x20,
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
			.IntelMnemonic = "vpmovsxbw",
			.GasMnemonic = "vpmovsxbw",
			.Description = "vpmovsxbw ymm, m128",
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
						.L = true,
						.R = {OperandType::Ymm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x20,
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
			.IntelMnemonic = "vpmovsxdq",
			.GasMnemonic = "vpmovsxdq",
			.Description = "vpmovsxdq xmm{k}{z}, xmm",
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
						.Value = 0x25,
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
			.IntelMnemonic = "vpmovsxdq",
			.GasMnemonic = "vpmovsxdq",
			.Description = "vpmovsxdq ymm{k}{z}, xmm",
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
						.Ll = UINT64_C(0x1),
						.Rr = {OperandType::YmmKz},
						.Bb = {OperandType::Xmm},
						.X = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
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
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::YmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovsxdq",
			.GasMnemonic = "vpmovsxdq",
			.Description = "vpmovsxdq zmm{k}{z}, ymm",
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
						.Bb = {OperandType::Ymm},
						.X = {OperandType::Ymm},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Ymm},
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
						.Rm = {OperandType::Ymm},
						.Reg = {OperandType::ZmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovsxdq",
			.GasMnemonic = "vpmovsxdq",
			.Description = "vpmovsxdq xmm{k}{z}, m64",
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
						.Bb = {OperandType::M64},
						.X = {OperandType::M64},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M64},
						.Aaa = {OperandType::XmmKz},
						.Z = {OperandType::XmmKz},
						.Disp8xN = 8,
					},
					OpCode
					{
						.Value = 0x25,
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
			.IntelMnemonic = "vpmovsxdq",
			.GasMnemonic = "vpmovsxdq",
			.Description = "vpmovsxdq ymm{k}{z}, m128",
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
						.Ll = UINT64_C(0x1),
						.Rr = {OperandType::YmmKz},
						.Bb = {OperandType::M128},
						.X = {OperandType::M128},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M128},
						.Aaa = {OperandType::YmmKz},
						.Z = {OperandType::YmmKz},
						.Disp8xN = 16,
					},
					OpCode
					{
						.Value = 0x25,
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
			.IntelMnemonic = "vpmovsxdq",
			.GasMnemonic = "vpmovsxdq",
			.Description = "vpmovsxdq zmm{k}{z}, m256",
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
						.Bb = {OperandType::M256},
						.X = {OperandType::M256},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M256},
						.Aaa = {OperandType::ZmmKz},
						.Z = {OperandType::ZmmKz},
						.Disp8xN = 32,
					},
					OpCode
					{
						.Value = 0x25,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M256},
						.Rm = {OperandType::M256},
						.Reg = {OperandType::ZmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovsxdq",
			.GasMnemonic = "vpmovsxdq",
			.Description = "vpmovsxdq xmm, xmm",
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
						.Vvvv = {UINT64_C(0x0)},
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
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovsxdq",
			.GasMnemonic = "vpmovsxdq",
			.Description = "vpmovsxdq xmm, m64",
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
						.Mmmmm = 0b10,
						.Pp = 0b1,
						.W = false,
						.L = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x25,
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
			.IntelMnemonic = "vpmovsxdq",
			.GasMnemonic = "vpmovsxdq",
			.Description = "vpmovsxdq ymm, xmm",
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
						.L = true,
						.R = {OperandType::Ymm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
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
						.Reg = {OperandType::Ymm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovsxdq",
			.GasMnemonic = "vpmovsxdq",
			.Description = "vpmovsxdq ymm, m128",
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
						.L = true,
						.R = {OperandType::Ymm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x25,
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
			.IntelMnemonic = "vpmovsxwd",
			.GasMnemonic = "vpmovsxwd",
			.Description = "vpmovsxwd xmm{k}{z}, xmm",
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
						.Value = 0x23,
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
			.IntelMnemonic = "vpmovsxwd",
			.GasMnemonic = "vpmovsxwd",
			.Description = "vpmovsxwd ymm{k}{z}, xmm",
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
						.Ll = UINT64_C(0x1),
						.Rr = {OperandType::YmmKz},
						.Bb = {OperandType::Xmm},
						.X = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Aaa = {OperandType::YmmKz},
						.Z = {OperandType::YmmKz},
						.Disp8xN = 0,
					},
					OpCode
					{
						.Value = 0x23,
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
			.IntelMnemonic = "vpmovsxwd",
			.GasMnemonic = "vpmovsxwd",
			.Description = "vpmovsxwd zmm{k}{z}, ymm",
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
						.Bb = {OperandType::Ymm},
						.X = {OperandType::Ymm},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Ymm},
						.Aaa = {OperandType::ZmmKz},
						.Z = {OperandType::ZmmKz},
						.Disp8xN = 0,
					},
					OpCode
					{
						.Value = 0x23,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Ymm},
						.Reg = {OperandType::ZmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovsxwd",
			.GasMnemonic = "vpmovsxwd",
			.Description = "vpmovsxwd xmm{k}{z}, m64",
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
						.Bb = {OperandType::M64},
						.X = {OperandType::M64},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M64},
						.Aaa = {OperandType::XmmKz},
						.Z = {OperandType::XmmKz},
						.Disp8xN = 8,
					},
					OpCode
					{
						.Value = 0x23,
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
			.IntelMnemonic = "vpmovsxwd",
			.GasMnemonic = "vpmovsxwd",
			.Description = "vpmovsxwd ymm{k}{z}, m128",
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
						.Ll = UINT64_C(0x1),
						.Rr = {OperandType::YmmKz},
						.Bb = {OperandType::M128},
						.X = {OperandType::M128},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M128},
						.Aaa = {OperandType::YmmKz},
						.Z = {OperandType::YmmKz},
						.Disp8xN = 16,
					},
					OpCode
					{
						.Value = 0x23,
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
			.IntelMnemonic = "vpmovsxwd",
			.GasMnemonic = "vpmovsxwd",
			.Description = "vpmovsxwd zmm{k}{z}, m256",
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
						.Bb = {OperandType::M256},
						.X = {OperandType::M256},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M256},
						.Aaa = {OperandType::ZmmKz},
						.Z = {OperandType::ZmmKz},
						.Disp8xN = 32,
					},
					OpCode
					{
						.Value = 0x23,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M256},
						.Rm = {OperandType::M256},
						.Reg = {OperandType::ZmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovsxwd",
			.GasMnemonic = "vpmovsxwd",
			.Description = "vpmovsxwd xmm, xmm",
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
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x23,
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
			.IntelMnemonic = "vpmovsxwd",
			.GasMnemonic = "vpmovsxwd",
			.Description = "vpmovsxwd xmm, m64",
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
						.Mmmmm = 0b10,
						.Pp = 0b1,
						.W = false,
						.L = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x23,
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
			.IntelMnemonic = "vpmovsxwd",
			.GasMnemonic = "vpmovsxwd",
			.Description = "vpmovsxwd ymm, xmm",
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
						.L = true,
						.R = {OperandType::Ymm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x23,
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
			.IntelMnemonic = "vpmovsxwd",
			.GasMnemonic = "vpmovsxwd",
			.Description = "vpmovsxwd ymm, m128",
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
						.L = true,
						.R = {OperandType::Ymm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x23,
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
			.IntelMnemonic = "vpmovsxwq",
			.GasMnemonic = "vpmovsxwq",
			.Description = "vpmovsxwq xmm{k}{z}, xmm",
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
						.Value = 0x24,
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
			.IntelMnemonic = "vpmovsxwq",
			.GasMnemonic = "vpmovsxwq",
			.Description = "vpmovsxwq ymm{k}{z}, xmm",
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
						.Ll = UINT64_C(0x1),
						.Rr = {OperandType::YmmKz},
						.Bb = {OperandType::Xmm},
						.X = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Aaa = {OperandType::YmmKz},
						.Z = {OperandType::YmmKz},
						.Disp8xN = 0,
					},
					OpCode
					{
						.Value = 0x24,
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
			.IntelMnemonic = "vpmovsxwq",
			.GasMnemonic = "vpmovsxwq",
			.Description = "vpmovsxwq zmm{k}{z}, xmm",
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
						.Mm = 0b10,
						.Pp = 0b1,
						.W = false,
						.Ll = UINT64_C(0x2),
						.Rr = {OperandType::ZmmKz},
						.Bb = {OperandType::Xmm},
						.X = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Aaa = {OperandType::ZmmKz},
						.Z = {OperandType::ZmmKz},
						.Disp8xN = 0,
					},
					OpCode
					{
						.Value = 0x24,
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
			.IntelMnemonic = "vpmovsxwq",
			.GasMnemonic = "vpmovsxwq",
			.Description = "vpmovsxwq xmm{k}{z}, m32",
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
						.Bb = {OperandType::M32},
						.X = {OperandType::M32},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M32},
						.Aaa = {OperandType::XmmKz},
						.Z = {OperandType::XmmKz},
						.Disp8xN = 4,
					},
					OpCode
					{
						.Value = 0x24,
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
			.IntelMnemonic = "vpmovsxwq",
			.GasMnemonic = "vpmovsxwq",
			.Description = "vpmovsxwq ymm{k}{z}, m64",
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
						.Bb = {OperandType::M64},
						.X = {OperandType::M64},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M64},
						.Aaa = {OperandType::YmmKz},
						.Z = {OperandType::YmmKz},
						.Disp8xN = 8,
					},
					OpCode
					{
						.Value = 0x24,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::YmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovsxwq",
			.GasMnemonic = "vpmovsxwq",
			.Description = "vpmovsxwq zmm{k}{z}, m128",
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
						.Mm = 0b10,
						.Pp = 0b1,
						.W = false,
						.Ll = UINT64_C(0x2),
						.Rr = {OperandType::ZmmKz},
						.Bb = {OperandType::M128},
						.X = {OperandType::M128},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M128},
						.Aaa = {OperandType::ZmmKz},
						.Z = {OperandType::ZmmKz},
						.Disp8xN = 16,
					},
					OpCode
					{
						.Value = 0x24,
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
			.IntelMnemonic = "vpmovsxwq",
			.GasMnemonic = "vpmovsxwq",
			.Description = "vpmovsxwq xmm, xmm",
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
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x24,
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
			.IntelMnemonic = "vpmovsxwq",
			.GasMnemonic = "vpmovsxwq",
			.Description = "vpmovsxwq xmm, m32",
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
						.Mmmmm = 0b10,
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
						.Value = 0x24,
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
			.IntelMnemonic = "vpmovsxwq",
			.GasMnemonic = "vpmovsxwq",
			.Description = "vpmovsxwq ymm, xmm",
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
						.L = true,
						.R = {OperandType::Ymm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x24,
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
			.IntelMnemonic = "vpmovsxwq",
			.GasMnemonic = "vpmovsxwq",
			.Description = "vpmovsxwq ymm, m64",
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
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x24,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
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
			.IntelMnemonic = "vpmovusdb",
			.GasMnemonic = "vpmovusdb",
			.Description = "vpmovusdb xmm{k}{z}, xmm",
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
						.Pp = 0b10,
						.W = false,
						.Ll = UINT64_C(0x0),
						.Rr = {OperandType::Xmm},
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
						.Value = 0x11,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::XmmKz},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovusdb",
			.GasMnemonic = "vpmovusdb",
			.Description = "vpmovusdb m32{k}{z}, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M32Kz,
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
						.Pp = 0b10,
						.W = false,
						.Ll = UINT64_C(0x0),
						.Rr = {OperandType::Xmm},
						.Bb = {OperandType::M32Kz},
						.X = {OperandType::M32Kz},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M32Kz},
						.Aaa = {OperandType::M32Kz},
						.Z = {OperandType::M32Kz},
						.Disp8xN = 4,
					},
					OpCode
					{
						.Value = 0x11,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M32Kz},
						.Rm = {OperandType::M32Kz},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovusdb",
			.GasMnemonic = "vpmovusdb",
			.Description = "vpmovusdb xmm{k}{z}, ymm",
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
						.Pp = 0b10,
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
						.Value = 0x11,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::XmmKz},
						.Reg = {OperandType::Ymm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovusdb",
			.GasMnemonic = "vpmovusdb",
			.Description = "vpmovusdb m64{k}{z}, ymm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M64Kz,
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
						.Pp = 0b10,
						.W = false,
						.Ll = UINT64_C(0x1),
						.Rr = {OperandType::Ymm},
						.Bb = {OperandType::M64Kz},
						.X = {OperandType::M64Kz},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M64Kz},
						.Aaa = {OperandType::M64Kz},
						.Z = {OperandType::M64Kz},
						.Disp8xN = 8,
					},
					OpCode
					{
						.Value = 0x11,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64Kz},
						.Rm = {OperandType::M64Kz},
						.Reg = {OperandType::Ymm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovusdb",
			.GasMnemonic = "vpmovusdb",
			.Description = "vpmovusdb xmm{k}{z}, zmm",
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
						.Pp = 0b10,
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
						.Value = 0x11,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::XmmKz},
						.Reg = {OperandType::Zmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovusdb",
			.GasMnemonic = "vpmovusdb",
			.Description = "vpmovusdb m128{k}{z}, zmm",
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
						.Pp = 0b10,
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
						.Value = 0x11,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128Kz},
						.Rm = {OperandType::M128Kz},
						.Reg = {OperandType::Zmm},
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
			.IntelMnemonic = "vpmovusdw",
			.GasMnemonic = "vpmovusdw",
			.Description = "vpmovusdw xmm{k}{z}, xmm",
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
						.Pp = 0b10,
						.W = false,
						.Ll = UINT64_C(0x0),
						.Rr = {OperandType::Xmm},
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
						.Value = 0x13,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::XmmKz},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovusdw",
			.GasMnemonic = "vpmovusdw",
			.Description = "vpmovusdw m64{k}{z}, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M64Kz,
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
						.Pp = 0b10,
						.W = false,
						.Ll = UINT64_C(0x0),
						.Rr = {OperandType::Xmm},
						.Bb = {OperandType::M64Kz},
						.X = {OperandType::M64Kz},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M64Kz},
						.Aaa = {OperandType::M64Kz},
						.Z = {OperandType::M64Kz},
						.Disp8xN = 8,
					},
					OpCode
					{
						.Value = 0x13,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64Kz},
						.Rm = {OperandType::M64Kz},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovusdw",
			.GasMnemonic = "vpmovusdw",
			.Description = "vpmovusdw xmm{k}{z}, ymm",
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
						.Pp = 0b10,
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
						.Value = 0x13,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::XmmKz},
						.Reg = {OperandType::Ymm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovusdw",
			.GasMnemonic = "vpmovusdw",
			.Description = "vpmovusdw m128{k}{z}, ymm",
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
						.Pp = 0b10,
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
						.Value = 0x13,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128Kz},
						.Rm = {OperandType::M128Kz},
						.Reg = {OperandType::Ymm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovusdw",
			.GasMnemonic = "vpmovusdw",
			.Description = "vpmovusdw ymm{k}{z}, zmm",
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
						.Pp = 0b10,
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
						.Value = 0x13,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::YmmKz},
						.Reg = {OperandType::Zmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovusdw",
			.GasMnemonic = "vpmovusdw",
			.Description = "vpmovusdw m256{k}{z}, zmm",
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
						.Pp = 0b10,
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
						.Value = 0x13,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M256Kz},
						.Rm = {OperandType::M256Kz},
						.Reg = {OperandType::Zmm},
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
			.IntelMnemonic = "vpmovusqb",
			.GasMnemonic = "vpmovusqb",
			.Description = "vpmovusqb xmm{k}{z}, xmm",
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
						.Pp = 0b10,
						.W = false,
						.Ll = UINT64_C(0x0),
						.Rr = {OperandType::Xmm},
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
						.Value = 0x12,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::XmmKz},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovusqb",
			.GasMnemonic = "vpmovusqb",
			.Description = "vpmovusqb m16{k}{z}, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M16Kz,
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
						.Pp = 0b10,
						.W = false,
						.Ll = UINT64_C(0x0),
						.Rr = {OperandType::Xmm},
						.Bb = {OperandType::M16Kz},
						.X = {OperandType::M16Kz},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M16Kz},
						.Aaa = {OperandType::M16Kz},
						.Z = {OperandType::M16Kz},
						.Disp8xN = 2,
					},
					OpCode
					{
						.Value = 0x12,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M16Kz},
						.Rm = {OperandType::M16Kz},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovusqb",
			.GasMnemonic = "vpmovusqb",
			.Description = "vpmovusqb xmm{k}{z}, ymm",
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
						.Pp = 0b10,
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
						.Value = 0x12,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::XmmKz},
						.Reg = {OperandType::Ymm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovusqb",
			.GasMnemonic = "vpmovusqb",
			.Description = "vpmovusqb m32{k}{z}, ymm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M32Kz,
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
						.Pp = 0b10,
						.W = false,
						.Ll = UINT64_C(0x1),
						.Rr = {OperandType::Ymm},
						.Bb = {OperandType::M32Kz},
						.X = {OperandType::M32Kz},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M32Kz},
						.Aaa = {OperandType::M32Kz},
						.Z = {OperandType::M32Kz},
						.Disp8xN = 4,
					},
					OpCode
					{
						.Value = 0x12,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M32Kz},
						.Rm = {OperandType::M32Kz},
						.Reg = {OperandType::Ymm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovusqb",
			.GasMnemonic = "vpmovusqb",
			.Description = "vpmovusqb xmm{k}{z}, zmm",
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
						.Pp = 0b10,
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
						.Value = 0x12,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::XmmKz},
						.Reg = {OperandType::Zmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovusqb",
			.GasMnemonic = "vpmovusqb",
			.Description = "vpmovusqb m64{k}{z}, zmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M64Kz,
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
						.Pp = 0b10,
						.W = false,
						.Ll = UINT64_C(0x2),
						.Rr = {OperandType::Zmm},
						.Bb = {OperandType::M64Kz},
						.X = {OperandType::M64Kz},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M64Kz},
						.Aaa = {OperandType::M64Kz},
						.Z = {OperandType::M64Kz},
						.Disp8xN = 8,
					},
					OpCode
					{
						.Value = 0x12,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64Kz},
						.Rm = {OperandType::M64Kz},
						.Reg = {OperandType::Zmm},
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
			.IntelMnemonic = "vpmovusqd",
			.GasMnemonic = "vpmovusqd",
			.Description = "vpmovusqd xmm{k}{z}, xmm",
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
						.Pp = 0b10,
						.W = false,
						.Ll = UINT64_C(0x0),
						.Rr = {OperandType::Xmm},
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
						.Value = 0x15,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::XmmKz},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovusqd",
			.GasMnemonic = "vpmovusqd",
			.Description = "vpmovusqd m64{k}{z}, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M64Kz,
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
						.Pp = 0b10,
						.W = false,
						.Ll = UINT64_C(0x0),
						.Rr = {OperandType::Xmm},
						.Bb = {OperandType::M64Kz},
						.X = {OperandType::M64Kz},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M64Kz},
						.Aaa = {OperandType::M64Kz},
						.Z = {OperandType::M64Kz},
						.Disp8xN = 8,
					},
					OpCode
					{
						.Value = 0x15,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64Kz},
						.Rm = {OperandType::M64Kz},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovusqd",
			.GasMnemonic = "vpmovusqd",
			.Description = "vpmovusqd xmm{k}{z}, ymm",
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
						.Pp = 0b10,
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
						.Value = 0x15,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::XmmKz},
						.Reg = {OperandType::Ymm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovusqd",
			.GasMnemonic = "vpmovusqd",
			.Description = "vpmovusqd m128{k}{z}, ymm",
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
						.Pp = 0b10,
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
						.Value = 0x15,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128Kz},
						.Rm = {OperandType::M128Kz},
						.Reg = {OperandType::Ymm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovusqd",
			.GasMnemonic = "vpmovusqd",
			.Description = "vpmovusqd ymm{k}{z}, zmm",
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
						.Pp = 0b10,
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
						.Value = 0x15,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::YmmKz},
						.Reg = {OperandType::Zmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovusqd",
			.GasMnemonic = "vpmovusqd",
			.Description = "vpmovusqd m256{k}{z}, zmm",
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
						.Pp = 0b10,
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
						.Value = 0x15,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M256Kz},
						.Rm = {OperandType::M256Kz},
						.Reg = {OperandType::Zmm},
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
			.IntelMnemonic = "vpmovusqw",
			.GasMnemonic = "vpmovusqw",
			.Description = "vpmovusqw xmm{k}{z}, xmm",
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
						.Pp = 0b10,
						.W = false,
						.Ll = UINT64_C(0x0),
						.Rr = {OperandType::Xmm},
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
						.Value = 0x14,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::XmmKz},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovusqw",
			.GasMnemonic = "vpmovusqw",
			.Description = "vpmovusqw m32{k}{z}, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M32Kz,
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
						.Pp = 0b10,
						.W = false,
						.Ll = UINT64_C(0x0),
						.Rr = {OperandType::Xmm},
						.Bb = {OperandType::M32Kz},
						.X = {OperandType::M32Kz},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M32Kz},
						.Aaa = {OperandType::M32Kz},
						.Z = {OperandType::M32Kz},
						.Disp8xN = 4,
					},
					OpCode
					{
						.Value = 0x14,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M32Kz},
						.Rm = {OperandType::M32Kz},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovusqw",
			.GasMnemonic = "vpmovusqw",
			.Description = "vpmovusqw xmm{k}{z}, ymm",
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
						.Pp = 0b10,
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
						.Value = 0x14,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::XmmKz},
						.Reg = {OperandType::Ymm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovusqw",
			.GasMnemonic = "vpmovusqw",
			.Description = "vpmovusqw m64{k}{z}, ymm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M64Kz,
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
						.Pp = 0b10,
						.W = false,
						.Ll = UINT64_C(0x1),
						.Rr = {OperandType::Ymm},
						.Bb = {OperandType::M64Kz},
						.X = {OperandType::M64Kz},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M64Kz},
						.Aaa = {OperandType::M64Kz},
						.Z = {OperandType::M64Kz},
						.Disp8xN = 8,
					},
					OpCode
					{
						.Value = 0x14,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64Kz},
						.Rm = {OperandType::M64Kz},
						.Reg = {OperandType::Ymm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovusqw",
			.GasMnemonic = "vpmovusqw",
			.Description = "vpmovusqw xmm{k}{z}, zmm",
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
						.Pp = 0b10,
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
						.Value = 0x14,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::XmmKz},
						.Reg = {OperandType::Zmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovusqw",
			.GasMnemonic = "vpmovusqw",
			.Description = "vpmovusqw m128{k}{z}, zmm",
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
						.Pp = 0b10,
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
						.Value = 0x14,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128Kz},
						.Rm = {OperandType::M128Kz},
						.Reg = {OperandType::Zmm},
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
			.IntelMnemonic = "vpmovuswb",
			.GasMnemonic = "vpmovuswb",
			.Description = "vpmovuswb xmm{k}{z}, xmm",
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
				IsaExtension::Avx512Bw,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Evex
					{
						.Mm = 0b10,
						.Pp = 0b10,
						.W = false,
						.Ll = UINT64_C(0x0),
						.Rr = {OperandType::Xmm},
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
						.Value = 0x10,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::XmmKz},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovuswb",
			.GasMnemonic = "vpmovuswb",
			.Description = "vpmovuswb m64{k}{z}, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M64Kz,
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
				IsaExtension::Avx512Bw,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Evex
					{
						.Mm = 0b10,
						.Pp = 0b10,
						.W = false,
						.Ll = UINT64_C(0x0),
						.Rr = {OperandType::Xmm},
						.Bb = {OperandType::M64Kz},
						.X = {OperandType::M64Kz},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M64Kz},
						.Aaa = {OperandType::M64Kz},
						.Z = {OperandType::M64Kz},
						.Disp8xN = 8,
					},
					OpCode
					{
						.Value = 0x10,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64Kz},
						.Rm = {OperandType::M64Kz},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovuswb",
			.GasMnemonic = "vpmovuswb",
			.Description = "vpmovuswb xmm{k}{z}, ymm",
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
						.Pp = 0b10,
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
						.Value = 0x10,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::XmmKz},
						.Reg = {OperandType::Ymm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovuswb",
			.GasMnemonic = "vpmovuswb",
			.Description = "vpmovuswb m128{k}{z}, ymm",
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
						.Pp = 0b10,
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
						.Value = 0x10,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128Kz},
						.Rm = {OperandType::M128Kz},
						.Reg = {OperandType::Ymm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovuswb",
			.GasMnemonic = "vpmovuswb",
			.Description = "vpmovuswb ymm{k}{z}, zmm",
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
						.Pp = 0b10,
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
						.Value = 0x10,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::YmmKz},
						.Reg = {OperandType::Zmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovuswb",
			.GasMnemonic = "vpmovuswb",
			.Description = "vpmovuswb m256{k}{z}, zmm",
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
						.Pp = 0b10,
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
						.Value = 0x10,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M256Kz},
						.Rm = {OperandType::M256Kz},
						.Reg = {OperandType::Zmm},
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
			.IntelMnemonic = "vpmovw2m",
			.GasMnemonic = "vpmovw2m",
			.Description = "vpmovw2m k, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::K,
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
				IsaExtension::Avx512Bw,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Evex
					{
						.Mm = 0b10,
						.Pp = 0b10,
						.W = true,
						.Ll = UINT64_C(0x0),
						.Rr = {OperandType::K},
						.Bb = {OperandType::Xmm},
						.X = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Aaa = {UINT64_C(0x0)},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 0,
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
						.Reg = {OperandType::K},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovw2m",
			.GasMnemonic = "vpmovw2m",
			.Description = "vpmovw2m k, ymm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::K,
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
				IsaExtension::Avx512Bw,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Evex
					{
						.Mm = 0b10,
						.Pp = 0b10,
						.W = true,
						.Ll = UINT64_C(0x1),
						.Rr = {OperandType::K},
						.Bb = {OperandType::Ymm},
						.X = {OperandType::Ymm},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Ymm},
						.Aaa = {UINT64_C(0x0)},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 0,
					},
					OpCode
					{
						.Value = 0x29,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Ymm},
						.Reg = {OperandType::K},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovw2m",
			.GasMnemonic = "vpmovw2m",
			.Description = "vpmovw2m k, zmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::K,
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
				IsaExtension::Avx512Bw,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Evex
					{
						.Mm = 0b10,
						.Pp = 0b10,
						.W = true,
						.Ll = UINT64_C(0x2),
						.Rr = {OperandType::K},
						.Bb = {OperandType::Zmm},
						.X = {OperandType::Zmm},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Zmm},
						.Aaa = {UINT64_C(0x0)},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 0,
					},
					OpCode
					{
						.Value = 0x29,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Zmm},
						.Reg = {OperandType::K},
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
			.IntelMnemonic = "vpmovwb",
			.GasMnemonic = "vpmovwb",
			.Description = "vpmovwb xmm{k}{z}, xmm",
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
				IsaExtension::Avx512Bw,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Evex
					{
						.Mm = 0b10,
						.Pp = 0b10,
						.W = false,
						.Ll = UINT64_C(0x0),
						.Rr = {OperandType::Xmm},
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
						.Value = 0x30,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::XmmKz},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovwb",
			.GasMnemonic = "vpmovwb",
			.Description = "vpmovwb m64{k}{z}, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M64Kz,
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
				IsaExtension::Avx512Bw,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Evex
					{
						.Mm = 0b10,
						.Pp = 0b10,
						.W = false,
						.Ll = UINT64_C(0x0),
						.Rr = {OperandType::Xmm},
						.Bb = {OperandType::M64Kz},
						.X = {OperandType::M64Kz},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M64Kz},
						.Aaa = {OperandType::M64Kz},
						.Z = {OperandType::M64Kz},
						.Disp8xN = 8,
					},
					OpCode
					{
						.Value = 0x30,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64Kz},
						.Rm = {OperandType::M64Kz},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovwb",
			.GasMnemonic = "vpmovwb",
			.Description = "vpmovwb xmm{k}{z}, ymm",
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
						.Pp = 0b10,
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
						.Value = 0x30,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::XmmKz},
						.Reg = {OperandType::Ymm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovwb",
			.GasMnemonic = "vpmovwb",
			.Description = "vpmovwb m128{k}{z}, ymm",
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
						.Pp = 0b10,
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
						.Value = 0x30,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128Kz},
						.Rm = {OperandType::M128Kz},
						.Reg = {OperandType::Ymm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovwb",
			.GasMnemonic = "vpmovwb",
			.Description = "vpmovwb ymm{k}{z}, zmm",
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
						.Pp = 0b10,
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
						.Value = 0x30,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::YmmKz},
						.Reg = {OperandType::Zmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovwb",
			.GasMnemonic = "vpmovwb",
			.Description = "vpmovwb m256{k}{z}, zmm",
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
						.Pp = 0b10,
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
						.Value = 0x30,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M256Kz},
						.Rm = {OperandType::M256Kz},
						.Reg = {OperandType::Zmm},
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
			.IntelMnemonic = "vpmovzxbd",
			.GasMnemonic = "vpmovzxbd",
			.Description = "vpmovzxbd xmm{k}{z}, xmm",
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
						.Value = 0x31,
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
			.IntelMnemonic = "vpmovzxbd",
			.GasMnemonic = "vpmovzxbd",
			.Description = "vpmovzxbd ymm{k}{z}, xmm",
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
						.Ll = UINT64_C(0x1),
						.Rr = {OperandType::YmmKz},
						.Bb = {OperandType::Xmm},
						.X = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Aaa = {OperandType::YmmKz},
						.Z = {OperandType::YmmKz},
						.Disp8xN = 0,
					},
					OpCode
					{
						.Value = 0x31,
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
			.IntelMnemonic = "vpmovzxbd",
			.GasMnemonic = "vpmovzxbd",
			.Description = "vpmovzxbd zmm{k}{z}, xmm",
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
						.Mm = 0b10,
						.Pp = 0b1,
						.W = false,
						.Ll = UINT64_C(0x2),
						.Rr = {OperandType::ZmmKz},
						.Bb = {OperandType::Xmm},
						.X = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Aaa = {OperandType::ZmmKz},
						.Z = {OperandType::ZmmKz},
						.Disp8xN = 0,
					},
					OpCode
					{
						.Value = 0x31,
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
			.IntelMnemonic = "vpmovzxbd",
			.GasMnemonic = "vpmovzxbd",
			.Description = "vpmovzxbd xmm{k}{z}, m32",
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
						.Bb = {OperandType::M32},
						.X = {OperandType::M32},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M32},
						.Aaa = {OperandType::XmmKz},
						.Z = {OperandType::XmmKz},
						.Disp8xN = 4,
					},
					OpCode
					{
						.Value = 0x31,
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
			.IntelMnemonic = "vpmovzxbd",
			.GasMnemonic = "vpmovzxbd",
			.Description = "vpmovzxbd ymm{k}{z}, m64",
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
						.Bb = {OperandType::M64},
						.X = {OperandType::M64},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M64},
						.Aaa = {OperandType::YmmKz},
						.Z = {OperandType::YmmKz},
						.Disp8xN = 8,
					},
					OpCode
					{
						.Value = 0x31,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::YmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovzxbd",
			.GasMnemonic = "vpmovzxbd",
			.Description = "vpmovzxbd zmm{k}{z}, m128",
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
						.Mm = 0b10,
						.Pp = 0b1,
						.W = false,
						.Ll = UINT64_C(0x2),
						.Rr = {OperandType::ZmmKz},
						.Bb = {OperandType::M128},
						.X = {OperandType::M128},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M128},
						.Aaa = {OperandType::ZmmKz},
						.Z = {OperandType::ZmmKz},
						.Disp8xN = 16,
					},
					OpCode
					{
						.Value = 0x31,
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
			.IntelMnemonic = "vpmovzxbd",
			.GasMnemonic = "vpmovzxbd",
			.Description = "vpmovzxbd xmm, xmm",
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
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x31,
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
			.IntelMnemonic = "vpmovzxbd",
			.GasMnemonic = "vpmovzxbd",
			.Description = "vpmovzxbd xmm, m32",
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
						.Mmmmm = 0b10,
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
						.Value = 0x31,
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
			.IntelMnemonic = "vpmovzxbd",
			.GasMnemonic = "vpmovzxbd",
			.Description = "vpmovzxbd ymm, xmm",
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
						.L = true,
						.R = {OperandType::Ymm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x31,
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
			.IntelMnemonic = "vpmovzxbd",
			.GasMnemonic = "vpmovzxbd",
			.Description = "vpmovzxbd ymm, m64",
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
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x31,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
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
			.IntelMnemonic = "vpmovzxbq",
			.GasMnemonic = "vpmovzxbq",
			.Description = "vpmovzxbq xmm{k}{z}, xmm",
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
						.Value = 0x32,
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
			.IntelMnemonic = "vpmovzxbq",
			.GasMnemonic = "vpmovzxbq",
			.Description = "vpmovzxbq ymm{k}{z}, xmm",
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
						.Ll = UINT64_C(0x1),
						.Rr = {OperandType::YmmKz},
						.Bb = {OperandType::Xmm},
						.X = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Aaa = {OperandType::YmmKz},
						.Z = {OperandType::YmmKz},
						.Disp8xN = 0,
					},
					OpCode
					{
						.Value = 0x32,
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
			.IntelMnemonic = "vpmovzxbq",
			.GasMnemonic = "vpmovzxbq",
			.Description = "vpmovzxbq zmm{k}{z}, xmm",
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
						.Mm = 0b10,
						.Pp = 0b1,
						.W = false,
						.Ll = UINT64_C(0x2),
						.Rr = {OperandType::ZmmKz},
						.Bb = {OperandType::Xmm},
						.X = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Aaa = {OperandType::ZmmKz},
						.Z = {OperandType::ZmmKz},
						.Disp8xN = 0,
					},
					OpCode
					{
						.Value = 0x32,
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
			.IntelMnemonic = "vpmovzxbq",
			.GasMnemonic = "vpmovzxbq",
			.Description = "vpmovzxbq xmm{k}{z}, m16",
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
						.Bb = {OperandType::M16},
						.X = {OperandType::M16},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M16},
						.Aaa = {OperandType::XmmKz},
						.Z = {OperandType::XmmKz},
						.Disp8xN = 2,
					},
					OpCode
					{
						.Value = 0x32,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M16},
						.Rm = {OperandType::M16},
						.Reg = {OperandType::XmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovzxbq",
			.GasMnemonic = "vpmovzxbq",
			.Description = "vpmovzxbq ymm{k}{z}, m32",
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
						.Bb = {OperandType::M32},
						.X = {OperandType::M32},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M32},
						.Aaa = {OperandType::YmmKz},
						.Z = {OperandType::YmmKz},
						.Disp8xN = 4,
					},
					OpCode
					{
						.Value = 0x32,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M32},
						.Rm = {OperandType::M32},
						.Reg = {OperandType::YmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovzxbq",
			.GasMnemonic = "vpmovzxbq",
			.Description = "vpmovzxbq zmm{k}{z}, m64",
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
						.W = false,
						.Ll = UINT64_C(0x2),
						.Rr = {OperandType::ZmmKz},
						.Bb = {OperandType::M64},
						.X = {OperandType::M64},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M64},
						.Aaa = {OperandType::ZmmKz},
						.Z = {OperandType::ZmmKz},
						.Disp8xN = 8,
					},
					OpCode
					{
						.Value = 0x32,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::ZmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovzxbq",
			.GasMnemonic = "vpmovzxbq",
			.Description = "vpmovzxbq xmm, xmm",
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
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x32,
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
			.IntelMnemonic = "vpmovzxbq",
			.GasMnemonic = "vpmovzxbq",
			.Description = "vpmovzxbq xmm, m16",
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
						.X = {OperandType::M16},
						.B = {OperandType::M16},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x32,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M16},
						.Rm = {OperandType::M16},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovzxbq",
			.GasMnemonic = "vpmovzxbq",
			.Description = "vpmovzxbq ymm, xmm",
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
						.L = true,
						.R = {OperandType::Ymm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x32,
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
			.IntelMnemonic = "vpmovzxbq",
			.GasMnemonic = "vpmovzxbq",
			.Description = "vpmovzxbq ymm, m32",
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
						.X = {OperandType::M32},
						.B = {OperandType::M32},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x32,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M32},
						.Rm = {OperandType::M32},
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
			.IntelMnemonic = "vpmovzxbw",
			.GasMnemonic = "vpmovzxbw",
			.Description = "vpmovzxbw xmm{k}{z}, xmm",
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
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Aaa = {OperandType::XmmKz},
						.Z = {OperandType::XmmKz},
						.Disp8xN = 0,
					},
					OpCode
					{
						.Value = 0x30,
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
			.IntelMnemonic = "vpmovzxbw",
			.GasMnemonic = "vpmovzxbw",
			.Description = "vpmovzxbw ymm{k}{z}, xmm",
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
						.Ll = UINT64_C(0x1),
						.Rr = {OperandType::YmmKz},
						.Bb = {OperandType::Xmm},
						.X = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Aaa = {OperandType::YmmKz},
						.Z = {OperandType::YmmKz},
						.Disp8xN = 0,
					},
					OpCode
					{
						.Value = 0x30,
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
			.IntelMnemonic = "vpmovzxbw",
			.GasMnemonic = "vpmovzxbw",
			.Description = "vpmovzxbw zmm{k}{z}, ymm",
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
						.Bb = {OperandType::Ymm},
						.X = {OperandType::Ymm},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Ymm},
						.Aaa = {OperandType::ZmmKz},
						.Z = {OperandType::ZmmKz},
						.Disp8xN = 0,
					},
					OpCode
					{
						.Value = 0x30,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Ymm},
						.Reg = {OperandType::ZmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovzxbw",
			.GasMnemonic = "vpmovzxbw",
			.Description = "vpmovzxbw xmm{k}{z}, m64",
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
						.Bb = {OperandType::M64},
						.X = {OperandType::M64},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M64},
						.Aaa = {OperandType::XmmKz},
						.Z = {OperandType::XmmKz},
						.Disp8xN = 8,
					},
					OpCode
					{
						.Value = 0x30,
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
			.IntelMnemonic = "vpmovzxbw",
			.GasMnemonic = "vpmovzxbw",
			.Description = "vpmovzxbw ymm{k}{z}, m128",
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
						.Ll = UINT64_C(0x1),
						.Rr = {OperandType::YmmKz},
						.Bb = {OperandType::M128},
						.X = {OperandType::M128},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M128},
						.Aaa = {OperandType::YmmKz},
						.Z = {OperandType::YmmKz},
						.Disp8xN = 16,
					},
					OpCode
					{
						.Value = 0x30,
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
			.IntelMnemonic = "vpmovzxbw",
			.GasMnemonic = "vpmovzxbw",
			.Description = "vpmovzxbw zmm{k}{z}, m256",
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
						.Bb = {OperandType::M256},
						.X = {OperandType::M256},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M256},
						.Aaa = {OperandType::ZmmKz},
						.Z = {OperandType::ZmmKz},
						.Disp8xN = 32,
					},
					OpCode
					{
						.Value = 0x30,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M256},
						.Rm = {OperandType::M256},
						.Reg = {OperandType::ZmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovzxbw",
			.GasMnemonic = "vpmovzxbw",
			.Description = "vpmovzxbw xmm, xmm",
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
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x30,
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
			.IntelMnemonic = "vpmovzxbw",
			.GasMnemonic = "vpmovzxbw",
			.Description = "vpmovzxbw xmm, m64",
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
						.Mmmmm = 0b10,
						.Pp = 0b1,
						.W = false,
						.L = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x30,
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
			.IntelMnemonic = "vpmovzxbw",
			.GasMnemonic = "vpmovzxbw",
			.Description = "vpmovzxbw ymm, xmm",
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
						.L = true,
						.R = {OperandType::Ymm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x30,
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
			.IntelMnemonic = "vpmovzxbw",
			.GasMnemonic = "vpmovzxbw",
			.Description = "vpmovzxbw ymm, m128",
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
						.L = true,
						.R = {OperandType::Ymm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x30,
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
			.IntelMnemonic = "vpmovzxdq",
			.GasMnemonic = "vpmovzxdq",
			.Description = "vpmovzxdq xmm{k}{z}, xmm",
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
						.Value = 0x35,
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
			.IntelMnemonic = "vpmovzxdq",
			.GasMnemonic = "vpmovzxdq",
			.Description = "vpmovzxdq ymm{k}{z}, xmm",
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
						.Ll = UINT64_C(0x1),
						.Rr = {OperandType::YmmKz},
						.Bb = {OperandType::Xmm},
						.X = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Aaa = {OperandType::YmmKz},
						.Z = {OperandType::YmmKz},
						.Disp8xN = 0,
					},
					OpCode
					{
						.Value = 0x35,
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
			.IntelMnemonic = "vpmovzxdq",
			.GasMnemonic = "vpmovzxdq",
			.Description = "vpmovzxdq zmm{k}{z}, ymm",
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
						.Bb = {OperandType::Ymm},
						.X = {OperandType::Ymm},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Ymm},
						.Aaa = {OperandType::ZmmKz},
						.Z = {OperandType::ZmmKz},
						.Disp8xN = 0,
					},
					OpCode
					{
						.Value = 0x35,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Ymm},
						.Reg = {OperandType::ZmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovzxdq",
			.GasMnemonic = "vpmovzxdq",
			.Description = "vpmovzxdq xmm{k}{z}, m64",
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
						.Bb = {OperandType::M64},
						.X = {OperandType::M64},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M64},
						.Aaa = {OperandType::XmmKz},
						.Z = {OperandType::XmmKz},
						.Disp8xN = 8,
					},
					OpCode
					{
						.Value = 0x35,
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
			.IntelMnemonic = "vpmovzxdq",
			.GasMnemonic = "vpmovzxdq",
			.Description = "vpmovzxdq ymm{k}{z}, m128",
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
						.Ll = UINT64_C(0x1),
						.Rr = {OperandType::YmmKz},
						.Bb = {OperandType::M128},
						.X = {OperandType::M128},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M128},
						.Aaa = {OperandType::YmmKz},
						.Z = {OperandType::YmmKz},
						.Disp8xN = 16,
					},
					OpCode
					{
						.Value = 0x35,
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
			.IntelMnemonic = "vpmovzxdq",
			.GasMnemonic = "vpmovzxdq",
			.Description = "vpmovzxdq zmm{k}{z}, m256",
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
						.Bb = {OperandType::M256},
						.X = {OperandType::M256},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M256},
						.Aaa = {OperandType::ZmmKz},
						.Z = {OperandType::ZmmKz},
						.Disp8xN = 32,
					},
					OpCode
					{
						.Value = 0x35,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M256},
						.Rm = {OperandType::M256},
						.Reg = {OperandType::ZmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovzxdq",
			.GasMnemonic = "vpmovzxdq",
			.Description = "vpmovzxdq xmm, xmm",
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
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x35,
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
			.IntelMnemonic = "vpmovzxdq",
			.GasMnemonic = "vpmovzxdq",
			.Description = "vpmovzxdq xmm, m64",
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
						.Mmmmm = 0b10,
						.Pp = 0b1,
						.W = false,
						.L = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x35,
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
			.IntelMnemonic = "vpmovzxdq",
			.GasMnemonic = "vpmovzxdq",
			.Description = "vpmovzxdq ymm, xmm",
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
						.L = true,
						.R = {OperandType::Ymm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x35,
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
			.IntelMnemonic = "vpmovzxdq",
			.GasMnemonic = "vpmovzxdq",
			.Description = "vpmovzxdq ymm, m128",
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
						.L = true,
						.R = {OperandType::Ymm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x35,
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
			.IntelMnemonic = "vpmovzxwd",
			.GasMnemonic = "vpmovzxwd",
			.Description = "vpmovzxwd xmm{k}{z}, xmm",
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
						.Value = 0x33,
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
			.IntelMnemonic = "vpmovzxwd",
			.GasMnemonic = "vpmovzxwd",
			.Description = "vpmovzxwd ymm{k}{z}, xmm",
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
						.Ll = UINT64_C(0x1),
						.Rr = {OperandType::YmmKz},
						.Bb = {OperandType::Xmm},
						.X = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Aaa = {OperandType::YmmKz},
						.Z = {OperandType::YmmKz},
						.Disp8xN = 0,
					},
					OpCode
					{
						.Value = 0x33,
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
			.IntelMnemonic = "vpmovzxwd",
			.GasMnemonic = "vpmovzxwd",
			.Description = "vpmovzxwd zmm{k}{z}, ymm",
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
						.Bb = {OperandType::Ymm},
						.X = {OperandType::Ymm},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Ymm},
						.Aaa = {OperandType::ZmmKz},
						.Z = {OperandType::ZmmKz},
						.Disp8xN = 0,
					},
					OpCode
					{
						.Value = 0x33,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Ymm},
						.Reg = {OperandType::ZmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovzxwd",
			.GasMnemonic = "vpmovzxwd",
			.Description = "vpmovzxwd xmm{k}{z}, m64",
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
						.Bb = {OperandType::M64},
						.X = {OperandType::M64},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M64},
						.Aaa = {OperandType::XmmKz},
						.Z = {OperandType::XmmKz},
						.Disp8xN = 8,
					},
					OpCode
					{
						.Value = 0x33,
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
			.IntelMnemonic = "vpmovzxwd",
			.GasMnemonic = "vpmovzxwd",
			.Description = "vpmovzxwd ymm{k}{z}, m128",
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
						.Ll = UINT64_C(0x1),
						.Rr = {OperandType::YmmKz},
						.Bb = {OperandType::M128},
						.X = {OperandType::M128},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M128},
						.Aaa = {OperandType::YmmKz},
						.Z = {OperandType::YmmKz},
						.Disp8xN = 16,
					},
					OpCode
					{
						.Value = 0x33,
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
			.IntelMnemonic = "vpmovzxwd",
			.GasMnemonic = "vpmovzxwd",
			.Description = "vpmovzxwd zmm{k}{z}, m256",
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
						.Bb = {OperandType::M256},
						.X = {OperandType::M256},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M256},
						.Aaa = {OperandType::ZmmKz},
						.Z = {OperandType::ZmmKz},
						.Disp8xN = 32,
					},
					OpCode
					{
						.Value = 0x33,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M256},
						.Rm = {OperandType::M256},
						.Reg = {OperandType::ZmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovzxwd",
			.GasMnemonic = "vpmovzxwd",
			.Description = "vpmovzxwd xmm, xmm",
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
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x33,
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
			.IntelMnemonic = "vpmovzxwd",
			.GasMnemonic = "vpmovzxwd",
			.Description = "vpmovzxwd xmm, m64",
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
						.Mmmmm = 0b10,
						.Pp = 0b1,
						.W = false,
						.L = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x33,
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
			.IntelMnemonic = "vpmovzxwd",
			.GasMnemonic = "vpmovzxwd",
			.Description = "vpmovzxwd ymm, xmm",
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
						.L = true,
						.R = {OperandType::Ymm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x33,
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
			.IntelMnemonic = "vpmovzxwd",
			.GasMnemonic = "vpmovzxwd",
			.Description = "vpmovzxwd ymm, m128",
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
						.L = true,
						.R = {OperandType::Ymm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x33,
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
			.IntelMnemonic = "vpmovzxwq",
			.GasMnemonic = "vpmovzxwq",
			.Description = "vpmovzxwq xmm{k}{z}, xmm",
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
						.Value = 0x34,
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
			.IntelMnemonic = "vpmovzxwq",
			.GasMnemonic = "vpmovzxwq",
			.Description = "vpmovzxwq ymm{k}{z}, xmm",
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
						.Ll = UINT64_C(0x1),
						.Rr = {OperandType::YmmKz},
						.Bb = {OperandType::Xmm},
						.X = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Aaa = {OperandType::YmmKz},
						.Z = {OperandType::YmmKz},
						.Disp8xN = 0,
					},
					OpCode
					{
						.Value = 0x34,
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
			.IntelMnemonic = "vpmovzxwq",
			.GasMnemonic = "vpmovzxwq",
			.Description = "vpmovzxwq zmm{k}{z}, xmm",
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
						.Mm = 0b10,
						.Pp = 0b1,
						.W = false,
						.Ll = UINT64_C(0x2),
						.Rr = {OperandType::ZmmKz},
						.Bb = {OperandType::Xmm},
						.X = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Aaa = {OperandType::ZmmKz},
						.Z = {OperandType::ZmmKz},
						.Disp8xN = 0,
					},
					OpCode
					{
						.Value = 0x34,
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
			.IntelMnemonic = "vpmovzxwq",
			.GasMnemonic = "vpmovzxwq",
			.Description = "vpmovzxwq xmm{k}{z}, m32",
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
						.Bb = {OperandType::M32},
						.X = {OperandType::M32},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M32},
						.Aaa = {OperandType::XmmKz},
						.Z = {OperandType::XmmKz},
						.Disp8xN = 4,
					},
					OpCode
					{
						.Value = 0x34,
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
			.IntelMnemonic = "vpmovzxwq",
			.GasMnemonic = "vpmovzxwq",
			.Description = "vpmovzxwq ymm{k}{z}, m64",
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
						.Bb = {OperandType::M64},
						.X = {OperandType::M64},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M64},
						.Aaa = {OperandType::YmmKz},
						.Z = {OperandType::YmmKz},
						.Disp8xN = 8,
					},
					OpCode
					{
						.Value = 0x34,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::YmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vpmovzxwq",
			.GasMnemonic = "vpmovzxwq",
			.Description = "vpmovzxwq zmm{k}{z}, m128",
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
						.Mm = 0b10,
						.Pp = 0b1,
						.W = false,
						.Ll = UINT64_C(0x2),
						.Rr = {OperandType::ZmmKz},
						.Bb = {OperandType::M128},
						.X = {OperandType::M128},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M128},
						.Aaa = {OperandType::ZmmKz},
						.Z = {OperandType::ZmmKz},
						.Disp8xN = 16,
					},
					OpCode
					{
						.Value = 0x34,
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
			.IntelMnemonic = "vpmovzxwq",
			.GasMnemonic = "vpmovzxwq",
			.Description = "vpmovzxwq xmm, xmm",
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
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x34,
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
			.IntelMnemonic = "vpmovzxwq",
			.GasMnemonic = "vpmovzxwq",
			.Description = "vpmovzxwq xmm, m32",
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
						.Mmmmm = 0b10,
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
						.Value = 0x34,
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
			.IntelMnemonic = "vpmovzxwq",
			.GasMnemonic = "vpmovzxwq",
			.Description = "vpmovzxwq ymm, xmm",
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
						.L = true,
						.R = {OperandType::Ymm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x34,
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
			.IntelMnemonic = "vpmovzxwq",
			.GasMnemonic = "vpmovzxwq",
			.Description = "vpmovzxwq ymm, m64",
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
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x34,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
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
			.IntelMnemonic = "vpmuldq",
			.GasMnemonic = "vpmuldq",
			.Description = "vpmuldq xmm{k}{z}, xmm, m128/m64bcst",
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
						.Value = 0x28,
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
			.IntelMnemonic = "vpmuldq",
			.GasMnemonic = "vpmuldq",
			.Description = "vpmuldq xmm{k}{z}, xmm, xmm",
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
						.Value = 0x28,
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
			.IntelMnemonic = "vpmuldq",
			.GasMnemonic = "vpmuldq",
			.Description = "vpmuldq ymm{k}{z}, ymm, m256/m64bcst",
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
						.Value = 0x28,
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
			.IntelMnemonic = "vpmuldq",
			.GasMnemonic = "vpmuldq",
			.Description = "vpmuldq ymm{k}{z}, ymm, ymm",
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
						.Value = 0x28,
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
			.IntelMnemonic = "vpmuldq",
			.GasMnemonic = "vpmuldq",
			.Description = "vpmuldq zmm{k}{z}, zmm, m512/m64bcst",
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
						.Value = 0x28,
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
			.IntelMnemonic = "vpmuldq",
			.GasMnemonic = "vpmuldq",
			.Description = "vpmuldq zmm{k}{z}, zmm, zmm",
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
						.Value = 0x28,
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
			.IntelMnemonic = "vpmuldq",
			.GasMnemonic = "vpmuldq",
			.Description = "vpmuldq xmm, xmm, xmm",
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
						.Value = 0x28,
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
			.IntelMnemonic = "vpmuldq",
			.GasMnemonic = "vpmuldq",
			.Description = "vpmuldq xmm, xmm, m128",
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
						.Value = 0x28,
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
			.IntelMnemonic = "vpmuldq",
			.GasMnemonic = "vpmuldq",
			.Description = "vpmuldq ymm, ymm, ymm",
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
						.Value = 0x28,
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
			.IntelMnemonic = "vpmuldq",
			.GasMnemonic = "vpmuldq",
			.Description = "vpmuldq ymm, ymm, m256",
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
						.Value = 0x28,
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
			.IntelMnemonic = "vpmulhrsw",
			.GasMnemonic = "vpmulhrsw",
			.Description = "vpmulhrsw xmm{k}{z}, xmm, xmm",
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
						.Value = 0xb,
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
			.IntelMnemonic = "vpmulhrsw",
			.GasMnemonic = "vpmulhrsw",
			.Description = "vpmulhrsw xmm{k}{z}, xmm, m128",
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
						.Value = 0xb,
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
			.IntelMnemonic = "vpmulhrsw",
			.GasMnemonic = "vpmulhrsw",
			.Description = "vpmulhrsw ymm{k}{z}, ymm, ymm",
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
						.Value = 0xb,
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
			.IntelMnemonic = "vpmulhrsw",
			.GasMnemonic = "vpmulhrsw",
			.Description = "vpmulhrsw ymm{k}{z}, ymm, m256",
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
						.Value = 0xb,
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
			.IntelMnemonic = "vpmulhrsw",
			.GasMnemonic = "vpmulhrsw",
			.Description = "vpmulhrsw zmm{k}{z}, zmm, zmm",
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
						.Value = 0xb,
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
			.IntelMnemonic = "vpmulhrsw",
			.GasMnemonic = "vpmulhrsw",
			.Description = "vpmulhrsw zmm{k}{z}, zmm, m512",
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
						.Value = 0xb,
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
			.IntelMnemonic = "vpmulhrsw",
			.GasMnemonic = "vpmulhrsw",
			.Description = "vpmulhrsw xmm, xmm, xmm",
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
						.Value = 0xb,
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
			.IntelMnemonic = "vpmulhrsw",
			.GasMnemonic = "vpmulhrsw",
			.Description = "vpmulhrsw xmm, xmm, m128",
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
						.Value = 0xb,
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
			.IntelMnemonic = "vpmulhrsw",
			.GasMnemonic = "vpmulhrsw",
			.Description = "vpmulhrsw ymm, ymm, ymm",
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
						.Value = 0xb,
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
			.IntelMnemonic = "vpmulhrsw",
			.GasMnemonic = "vpmulhrsw",
			.Description = "vpmulhrsw ymm, ymm, m256",
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
						.Value = 0xb,
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
			.IntelMnemonic = "vpmulhuw",
			.GasMnemonic = "vpmulhuw",
			.Description = "vpmulhuw xmm{k}{z}, xmm, xmm",
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
						.Value = 0xe4,
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
			.IntelMnemonic = "vpmulhuw",
			.GasMnemonic = "vpmulhuw",
			.Description = "vpmulhuw xmm{k}{z}, xmm, m128",
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
						.Value = 0xe4,
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
			.IntelMnemonic = "vpmulhuw",
			.GasMnemonic = "vpmulhuw",
			.Description = "vpmulhuw ymm{k}{z}, ymm, ymm",
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
						.Value = 0xe4,
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
			.IntelMnemonic = "vpmulhuw",
			.GasMnemonic = "vpmulhuw",
			.Description = "vpmulhuw ymm{k}{z}, ymm, m256",
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
						.Value = 0xe4,
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
			.IntelMnemonic = "vpmulhuw",
			.GasMnemonic = "vpmulhuw",
			.Description = "vpmulhuw zmm{k}{z}, zmm, zmm",
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
						.Value = 0xe4,
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
			.IntelMnemonic = "vpmulhuw",
			.GasMnemonic = "vpmulhuw",
			.Description = "vpmulhuw zmm{k}{z}, zmm, m512",
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
						.Value = 0xe4,
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
			.IntelMnemonic = "vpmulhuw",
			.GasMnemonic = "vpmulhuw",
			.Description = "vpmulhuw xmm, xmm, xmm",
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
						.Value = 0xe4,
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
			.IntelMnemonic = "vpmulhuw",
			.GasMnemonic = "vpmulhuw",
			.Description = "vpmulhuw xmm, xmm, m128",
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
						.Value = 0xe4,
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
			.IntelMnemonic = "vpmulhuw",
			.GasMnemonic = "vpmulhuw",
			.Description = "vpmulhuw ymm, ymm, ymm",
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
						.Value = 0xe4,
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
			.IntelMnemonic = "vpmulhuw",
			.GasMnemonic = "vpmulhuw",
			.Description = "vpmulhuw ymm, ymm, m256",
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
						.Value = 0xe4,
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
			.IntelMnemonic = "vpmulhw",
			.GasMnemonic = "vpmulhw",
			.Description = "vpmulhw xmm{k}{z}, xmm, xmm",
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
						.Value = 0xe5,
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
			.IntelMnemonic = "vpmulhw",
			.GasMnemonic = "vpmulhw",
			.Description = "vpmulhw xmm{k}{z}, xmm, m128",
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
						.Value = 0xe5,
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
			.IntelMnemonic = "vpmulhw",
			.GasMnemonic = "vpmulhw",
			.Description = "vpmulhw ymm{k}{z}, ymm, ymm",
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
						.Value = 0xe5,
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
			.IntelMnemonic = "vpmulhw",
			.GasMnemonic = "vpmulhw",
			.Description = "vpmulhw ymm{k}{z}, ymm, m256",
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
						.Value = 0xe5,
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
			.IntelMnemonic = "vpmulhw",
			.GasMnemonic = "vpmulhw",
			.Description = "vpmulhw zmm{k}{z}, zmm, zmm",
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
						.Value = 0xe5,
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
			.IntelMnemonic = "vpmulhw",
			.GasMnemonic = "vpmulhw",
			.Description = "vpmulhw zmm{k}{z}, zmm, m512",
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
						.Value = 0xe5,
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
			.IntelMnemonic = "vpmulhw",
			.GasMnemonic = "vpmulhw",
			.Description = "vpmulhw xmm, xmm, xmm",
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
						.Value = 0xe5,
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
			.IntelMnemonic = "vpmulhw",
			.GasMnemonic = "vpmulhw",
			.Description = "vpmulhw xmm, xmm, m128",
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
						.Value = 0xe5,
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
			.IntelMnemonic = "vpmulhw",
			.GasMnemonic = "vpmulhw",
			.Description = "vpmulhw ymm, ymm, ymm",
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
						.Value = 0xe5,
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
			.IntelMnemonic = "vpmulhw",
			.GasMnemonic = "vpmulhw",
			.Description = "vpmulhw ymm, ymm, m256",
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
						.Value = 0xe5,
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
			.IntelMnemonic = "vpmulld",
			.GasMnemonic = "vpmulld",
			.Description = "vpmulld xmm{k}{z}, xmm, m128/m32bcst",
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
						.Value = 0x40,
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
			.IntelMnemonic = "vpmulld",
			.GasMnemonic = "vpmulld",
			.Description = "vpmulld xmm{k}{z}, xmm, xmm",
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
						.Value = 0x40,
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
			.IntelMnemonic = "vpmulld",
			.GasMnemonic = "vpmulld",
			.Description = "vpmulld ymm{k}{z}, ymm, m256/m32bcst",
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
						.Value = 0x40,
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
			.IntelMnemonic = "vpmulld",
			.GasMnemonic = "vpmulld",
			.Description = "vpmulld ymm{k}{z}, ymm, ymm",
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
						.Value = 0x40,
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
			.IntelMnemonic = "vpmulld",
			.GasMnemonic = "vpmulld",
			.Description = "vpmulld zmm{k}{z}, zmm, m512/m32bcst",
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
						.Value = 0x40,
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
			.IntelMnemonic = "vpmulld",
			.GasMnemonic = "vpmulld",
			.Description = "vpmulld zmm{k}{z}, zmm, zmm",
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
						.Value = 0x40,
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
			.IntelMnemonic = "vpmulld",
			.GasMnemonic = "vpmulld",
			.Description = "vpmulld xmm, xmm, xmm",
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
						.Value = 0x40,
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
			.IntelMnemonic = "vpmulld",
			.GasMnemonic = "vpmulld",
			.Description = "vpmulld xmm, xmm, m128",
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
						.Value = 0x40,
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
			.IntelMnemonic = "vpmulld",
			.GasMnemonic = "vpmulld",
			.Description = "vpmulld ymm, ymm, ymm",
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
						.Value = 0x40,
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
			.IntelMnemonic = "vpmulld",
			.GasMnemonic = "vpmulld",
			.Description = "vpmulld ymm, ymm, m256",
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
						.Value = 0x40,
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
			.IntelMnemonic = "vpmullq",
			.GasMnemonic = "vpmullq",
			.Description = "vpmullq xmm{k}{z}, xmm, m128/m64bcst",
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
				IsaExtension::Avx512Dq,
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
						.Value = 0x40,
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
			.IntelMnemonic = "vpmullq",
			.GasMnemonic = "vpmullq",
			.Description = "vpmullq xmm{k}{z}, xmm, xmm",
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
				IsaExtension::Avx512Dq,
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
						.Value = 0x40,
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
			.IntelMnemonic = "vpmullq",
			.GasMnemonic = "vpmullq",
			.Description = "vpmullq ymm{k}{z}, ymm, m256/m64bcst",
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
				IsaExtension::Avx512Dq,
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
						.Value = 0x40,
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
			.IntelMnemonic = "vpmullq",
			.GasMnemonic = "vpmullq",
			.Description = "vpmullq ymm{k}{z}, ymm, ymm",
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
				IsaExtension::Avx512Dq,
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
						.Value = 0x40,
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
			.IntelMnemonic = "vpmullq",
			.GasMnemonic = "vpmullq",
			.Description = "vpmullq zmm{k}{z}, zmm, m512/m64bcst",
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
				IsaExtension::Avx512Dq,
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
						.Value = 0x40,
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
			.IntelMnemonic = "vpmullq",
			.GasMnemonic = "vpmullq",
			.Description = "vpmullq zmm{k}{z}, zmm, zmm",
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
				IsaExtension::Avx512Dq,
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
						.Value = 0x40,
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
			.IntelMnemonic = "vpmullw",
			.GasMnemonic = "vpmullw",
			.Description = "vpmullw xmm{k}{z}, xmm, xmm",
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
						.Value = 0xd5,
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
			.IntelMnemonic = "vpmullw",
			.GasMnemonic = "vpmullw",
			.Description = "vpmullw xmm{k}{z}, xmm, m128",
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
						.Value = 0xd5,
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
			.IntelMnemonic = "vpmullw",
			.GasMnemonic = "vpmullw",
			.Description = "vpmullw ymm{k}{z}, ymm, ymm",
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
						.Value = 0xd5,
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
			.IntelMnemonic = "vpmullw",
			.GasMnemonic = "vpmullw",
			.Description = "vpmullw ymm{k}{z}, ymm, m256",
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
						.Value = 0xd5,
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
			.IntelMnemonic = "vpmullw",
			.GasMnemonic = "vpmullw",
			.Description = "vpmullw zmm{k}{z}, zmm, zmm",
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
						.Value = 0xd5,
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
			.IntelMnemonic = "vpmullw",
			.GasMnemonic = "vpmullw",
			.Description = "vpmullw zmm{k}{z}, zmm, m512",
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
						.Value = 0xd5,
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
			.IntelMnemonic = "vpmullw",
			.GasMnemonic = "vpmullw",
			.Description = "vpmullw xmm, xmm, xmm",
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
						.Value = 0xd5,
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
			.IntelMnemonic = "vpmullw",
			.GasMnemonic = "vpmullw",
			.Description = "vpmullw xmm, xmm, m128",
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
						.Value = 0xd5,
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
			.IntelMnemonic = "vpmullw",
			.GasMnemonic = "vpmullw",
			.Description = "vpmullw ymm, ymm, ymm",
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
						.Value = 0xd5,
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
			.IntelMnemonic = "vpmullw",
			.GasMnemonic = "vpmullw",
			.Description = "vpmullw ymm, ymm, m256",
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
						.Value = 0xd5,
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
			.IntelMnemonic = "vpmultishiftqb",
			.GasMnemonic = "vpmultishiftqb",
			.Description = "vpmultishiftqb xmm{k}{z}, xmm, m128/m64bcst",
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
				IsaExtension::Avx512Vbmi,
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
						.Value = 0x83,
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
			.IntelMnemonic = "vpmultishiftqb",
			.GasMnemonic = "vpmultishiftqb",
			.Description = "vpmultishiftqb xmm{k}{z}, xmm, xmm",
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
				IsaExtension::Avx512Vbmi,
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
						.Value = 0x83,
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
			.IntelMnemonic = "vpmultishiftqb",
			.GasMnemonic = "vpmultishiftqb",
			.Description = "vpmultishiftqb ymm{k}{z}, ymm, m256/m64bcst",
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
				IsaExtension::Avx512Vbmi,
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
						.Value = 0x83,
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
			.IntelMnemonic = "vpmultishiftqb",
			.GasMnemonic = "vpmultishiftqb",
			.Description = "vpmultishiftqb ymm{k}{z}, ymm, ymm",
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
				IsaExtension::Avx512Vbmi,
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
						.Value = 0x83,
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
			.IntelMnemonic = "vpmultishiftqb",
			.GasMnemonic = "vpmultishiftqb",
			.Description = "vpmultishiftqb zmm{k}{z}, zmm, m512/m64bcst",
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
				IsaExtension::Avx512Vbmi,
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
						.Value = 0x83,
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
			.IntelMnemonic = "vpmultishiftqb",
			.GasMnemonic = "vpmultishiftqb",
			.Description = "vpmultishiftqb zmm{k}{z}, zmm, zmm",
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
				IsaExtension::Avx512Vbmi,
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
						.Value = 0x83,
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
			.IntelMnemonic = "vpmuludq",
			.GasMnemonic = "vpmuludq",
			.Description = "vpmuludq xmm{k}{z}, xmm, m128/m64bcst",
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
						.Value = 0xf4,
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
			.IntelMnemonic = "vpmuludq",
			.GasMnemonic = "vpmuludq",
			.Description = "vpmuludq xmm{k}{z}, xmm, xmm",
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
						.Value = 0xf4,
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
			.IntelMnemonic = "vpmuludq",
			.GasMnemonic = "vpmuludq",
			.Description = "vpmuludq ymm{k}{z}, ymm, m256/m64bcst",
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
						.Value = 0xf4,
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
			.IntelMnemonic = "vpmuludq",
			.GasMnemonic = "vpmuludq",
			.Description = "vpmuludq ymm{k}{z}, ymm, ymm",
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
						.Value = 0xf4,
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
			.IntelMnemonic = "vpmuludq",
			.GasMnemonic = "vpmuludq",
			.Description = "vpmuludq zmm{k}{z}, zmm, m512/m64bcst",
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
						.Value = 0xf4,
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
			.IntelMnemonic = "vpmuludq",
			.GasMnemonic = "vpmuludq",
			.Description = "vpmuludq zmm{k}{z}, zmm, zmm",
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
						.Value = 0xf4,
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
			.IntelMnemonic = "vpmuludq",
			.GasMnemonic = "vpmuludq",
			.Description = "vpmuludq xmm, xmm, xmm",
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
						.Value = 0xf4,
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
			.IntelMnemonic = "vpmuludq",
			.GasMnemonic = "vpmuludq",
			.Description = "vpmuludq xmm, xmm, m128",
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
						.Value = 0xf4,
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
			.IntelMnemonic = "vpmuludq",
			.GasMnemonic = "vpmuludq",
			.Description = "vpmuludq ymm, ymm, ymm",
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
						.Value = 0xf4,
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
			.IntelMnemonic = "vpmuludq",
			.GasMnemonic = "vpmuludq",
			.Description = "vpmuludq ymm, ymm, m256",
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
						.Value = 0xf4,
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
			.IntelMnemonic = "vpopcntd",
			.GasMnemonic = "vpopcntd",
			.Description = "vpopcntd zmm{k}{z}, m512/m32bcst",
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
				IsaExtension::Avx512Vpopcntd,
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
						.Value = 0x55,
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
			.IntelMnemonic = "vpopcntd",
			.GasMnemonic = "vpopcntd",
			.Description = "vpopcntd zmm{k}{z}, zmm",
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
				IsaExtension::Avx512Vpopcntd,
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
						.Value = 0x55,
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
			.IntelMnemonic = "vpopcntq",
			.GasMnemonic = "vpopcntq",
			.Description = "vpopcntq zmm{k}{z}, m512/m64bcst",
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
				IsaExtension::Avx512Vpopcntd,
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
						.Value = 0x55,
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
			.IntelMnemonic = "vpopcntq",
			.GasMnemonic = "vpopcntq",
			.Description = "vpopcntq zmm{k}{z}, zmm",
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
				IsaExtension::Avx512Vpopcntd,
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
						.Value = 0x55,
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
			.IntelMnemonic = "vpor",
			.GasMnemonic = "vpor",
			.Description = "vpor xmm, xmm, xmm",
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
						.Value = 0xeb,
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
			.IntelMnemonic = "vpor",
			.GasMnemonic = "vpor",
			.Description = "vpor xmm, xmm, m128",
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
						.Value = 0xeb,
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
			.IntelMnemonic = "vpor",
			.GasMnemonic = "vpor",
			.Description = "vpor ymm, ymm, ymm",
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
						.Value = 0xeb,
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
			.IntelMnemonic = "vpor",
			.GasMnemonic = "vpor",
			.Description = "vpor ymm, ymm, m256",
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
						.Value = 0xeb,
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

};
}
