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
NOX_NEVER_INLINE NOX_COLD auto GetVariationTable_23(std::pmr::monotonic_buffer_resource& allocator, std::pmr::vector<InstructionVariationPool>& out) -> void
{
	std::pmr::vector<InstructionVariation> instruction{&allocator};
	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "vfnmsub231ps",
			.GasMnemonic = "vfnmsub231ps",
			.Description = "vfnmsub231ps xmm{k}{z}, xmm, m128/m32bcst",
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
						.Value = 0xbe,
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
			.IntelMnemonic = "vfnmsub231ps",
			.GasMnemonic = "vfnmsub231ps",
			.Description = "vfnmsub231ps xmm{k}{z}, xmm, xmm",
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
						.Value = 0xbe,
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
			.IntelMnemonic = "vfnmsub231ps",
			.GasMnemonic = "vfnmsub231ps",
			.Description = "vfnmsub231ps ymm{k}{z}, ymm, m256/m32bcst",
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
						.Value = 0xbe,
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
			.IntelMnemonic = "vfnmsub231ps",
			.GasMnemonic = "vfnmsub231ps",
			.Description = "vfnmsub231ps ymm{k}{z}, ymm, ymm",
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
						.Value = 0xbe,
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
			.IntelMnemonic = "vfnmsub231ps",
			.GasMnemonic = "vfnmsub231ps",
			.Description = "vfnmsub231ps zmm{k}{z}, zmm, m512/m32bcst",
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
						.Value = 0xbe,
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
			.IntelMnemonic = "vfnmsub231ps",
			.GasMnemonic = "vfnmsub231ps",
			.Description = "vfnmsub231ps xmm, xmm, xmm",
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
						.Value = 0xbe,
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
			.IntelMnemonic = "vfnmsub231ps",
			.GasMnemonic = "vfnmsub231ps",
			.Description = "vfnmsub231ps xmm, xmm, m128",
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
						.Value = 0xbe,
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
			.IntelMnemonic = "vfnmsub231ps",
			.GasMnemonic = "vfnmsub231ps",
			.Description = "vfnmsub231ps ymm, ymm, ymm",
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
						.Value = 0xbe,
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
			.IntelMnemonic = "vfnmsub231ps",
			.GasMnemonic = "vfnmsub231ps",
			.Description = "vfnmsub231ps ymm, ymm, m256",
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
						.Value = 0xbe,
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
			.IntelMnemonic = "vfnmsub231ps",
			.GasMnemonic = "vfnmsub231ps",
			.Description = "vfnmsub231ps zmm{k}{z}, zmm, zmm, {er}",
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
						.Value = 0xbe,
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
			.IntelMnemonic = "vfnmsub231sd",
			.GasMnemonic = "vfnmsub231sd",
			.Description = "vfnmsub231sd xmm{k}{z}, xmm, m64",
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
						.Value = 0xbf,
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
			.IntelMnemonic = "vfnmsub231sd",
			.GasMnemonic = "vfnmsub231sd",
			.Description = "vfnmsub231sd xmm, xmm, xmm",
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
						.Value = 0xbf,
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
			.IntelMnemonic = "vfnmsub231sd",
			.GasMnemonic = "vfnmsub231sd",
			.Description = "vfnmsub231sd xmm, xmm, m64",
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
						.Value = 0xbf,
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
			.IntelMnemonic = "vfnmsub231sd",
			.GasMnemonic = "vfnmsub231sd",
			.Description = "vfnmsub231sd xmm{k}{z}, xmm, xmm, {er}",
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
						.Value = 0xbf,
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
			.IntelMnemonic = "vfnmsub231ss",
			.GasMnemonic = "vfnmsub231ss",
			.Description = "vfnmsub231ss xmm{k}{z}, xmm, m32",
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
						.Value = 0xbf,
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
			.IntelMnemonic = "vfnmsub231ss",
			.GasMnemonic = "vfnmsub231ss",
			.Description = "vfnmsub231ss xmm, xmm, xmm",
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
						.Value = 0xbf,
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
			.IntelMnemonic = "vfnmsub231ss",
			.GasMnemonic = "vfnmsub231ss",
			.Description = "vfnmsub231ss xmm, xmm, m32",
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
						.Value = 0xbf,
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
			.IntelMnemonic = "vfnmsub231ss",
			.GasMnemonic = "vfnmsub231ss",
			.Description = "vfnmsub231ss xmm{k}{z}, xmm, xmm, {er}",
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
						.Value = 0xbf,
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
			.IntelMnemonic = "vfnmsubpd",
			.GasMnemonic = "vfnmsubpd",
			.Description = "vfnmsubpd xmm, xmm, xmm, xmm",
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
				IsaExtension::Fma4,
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
						.B = {OperandType::Xmm},
						.Vvvv = {OperandType::Xmm},
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
					RegisterByte
					{
						.Register = OperandType::Xmm,
						.Payload = {UINT64_C(0x0)},
					},
				},
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
						.Value = 0x7d,
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
			.IntelMnemonic = "vfnmsubpd",
			.GasMnemonic = "vfnmsubpd",
			.Description = "vfnmsubpd xmm, xmm, xmm, m128",
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
				IsaExtension::Fma4,
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
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.Vvvv = {OperandType::Xmm},
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
			.IntelMnemonic = "vfnmsubpd",
			.GasMnemonic = "vfnmsubpd",
			.Description = "vfnmsubpd xmm, xmm, m128, xmm",
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
				IsaExtension::Fma4,
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
						.Value = 0x7d,
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
		InstructionVariation
		{
			.IntelMnemonic = "vfnmsubpd",
			.GasMnemonic = "vfnmsubpd",
			.Description = "vfnmsubpd ymm, ymm, ymm, ymm",
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
				IsaExtension::Fma4,
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
						.L = true,
						.R = {OperandType::Ymm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Ymm},
						.Vvvv = {OperandType::Ymm},
					},
					OpCode
					{
						.Value = 0x7d,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Ymm},
						.Reg = {OperandType::Ymm},
					},
					RegisterByte
					{
						.Register = OperandType::Ymm,
						.Payload = {UINT64_C(0x0)},
					},
				},
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
						.Value = 0x7d,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Ymm},
						.Reg = {OperandType::Ymm},
					},
					RegisterByte
					{
						.Register = OperandType::Ymm,
						.Payload = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vfnmsubpd",
			.GasMnemonic = "vfnmsubpd",
			.Description = "vfnmsubpd ymm, ymm, ymm, m256",
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
				IsaExtension::Fma4,
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
						.L = true,
						.R = {OperandType::Ymm},
						.X = {OperandType::M256},
						.B = {OperandType::M256},
						.Vvvv = {OperandType::Ymm},
					},
					OpCode
					{
						.Value = 0x7d,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M256},
						.Rm = {OperandType::M256},
						.Reg = {OperandType::Ymm},
					},
					RegisterByte
					{
						.Register = OperandType::Ymm,
						.Payload = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vfnmsubpd",
			.GasMnemonic = "vfnmsubpd",
			.Description = "vfnmsubpd ymm, ymm, m256, ymm",
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
				IsaExtension::Fma4,
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
						.Value = 0x7d,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M256},
						.Rm = {OperandType::M256},
						.Reg = {OperandType::Ymm},
					},
					RegisterByte
					{
						.Register = OperandType::Ymm,
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
			.IntelMnemonic = "vfnmsubps",
			.GasMnemonic = "vfnmsubps",
			.Description = "vfnmsubps xmm, xmm, xmm, xmm",
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
				IsaExtension::Fma4,
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
						.B = {OperandType::Xmm},
						.Vvvv = {OperandType::Xmm},
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
					RegisterByte
					{
						.Register = OperandType::Xmm,
						.Payload = {UINT64_C(0x0)},
					},
				},
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
						.Value = 0x7c,
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
			.IntelMnemonic = "vfnmsubps",
			.GasMnemonic = "vfnmsubps",
			.Description = "vfnmsubps xmm, xmm, xmm, m128",
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
				IsaExtension::Fma4,
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
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.Vvvv = {OperandType::Xmm},
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
			.IntelMnemonic = "vfnmsubps",
			.GasMnemonic = "vfnmsubps",
			.Description = "vfnmsubps xmm, xmm, m128, xmm",
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
				IsaExtension::Fma4,
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
						.Value = 0x7c,
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
		InstructionVariation
		{
			.IntelMnemonic = "vfnmsubps",
			.GasMnemonic = "vfnmsubps",
			.Description = "vfnmsubps ymm, ymm, ymm, ymm",
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
				IsaExtension::Fma4,
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
						.L = true,
						.R = {OperandType::Ymm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Ymm},
						.Vvvv = {OperandType::Ymm},
					},
					OpCode
					{
						.Value = 0x7c,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Ymm},
						.Reg = {OperandType::Ymm},
					},
					RegisterByte
					{
						.Register = OperandType::Ymm,
						.Payload = {UINT64_C(0x0)},
					},
				},
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
						.Value = 0x7c,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Ymm},
						.Reg = {OperandType::Ymm},
					},
					RegisterByte
					{
						.Register = OperandType::Ymm,
						.Payload = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vfnmsubps",
			.GasMnemonic = "vfnmsubps",
			.Description = "vfnmsubps ymm, ymm, ymm, m256",
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
				IsaExtension::Fma4,
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
						.L = true,
						.R = {OperandType::Ymm},
						.X = {OperandType::M256},
						.B = {OperandType::M256},
						.Vvvv = {OperandType::Ymm},
					},
					OpCode
					{
						.Value = 0x7c,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M256},
						.Rm = {OperandType::M256},
						.Reg = {OperandType::Ymm},
					},
					RegisterByte
					{
						.Register = OperandType::Ymm,
						.Payload = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vfnmsubps",
			.GasMnemonic = "vfnmsubps",
			.Description = "vfnmsubps ymm, ymm, m256, ymm",
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
				IsaExtension::Fma4,
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
						.Value = 0x7c,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M256},
						.Rm = {OperandType::M256},
						.Reg = {OperandType::Ymm},
					},
					RegisterByte
					{
						.Register = OperandType::Ymm,
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
			.IntelMnemonic = "vfnmsubsd",
			.GasMnemonic = "vfnmsubsd",
			.Description = "vfnmsubsd xmm, xmm, xmm, xmm",
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
				IsaExtension::Fma4,
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
						.B = {OperandType::Xmm},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0x7f,
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
						.Value = 0x7f,
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
			.IntelMnemonic = "vfnmsubsd",
			.GasMnemonic = "vfnmsubsd",
			.Description = "vfnmsubsd xmm, xmm, xmm, m64",
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
				IsaExtension::Fma4,
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
						.Value = 0x7f,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
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
			.IntelMnemonic = "vfnmsubsd",
			.GasMnemonic = "vfnmsubsd",
			.Description = "vfnmsubsd xmm, xmm, m64, xmm",
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
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Fma4,
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
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0x7f,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
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
			.IntelMnemonic = "vfnmsubss",
			.GasMnemonic = "vfnmsubss",
			.Description = "vfnmsubss xmm, xmm, xmm, xmm",
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
				IsaExtension::Fma4,
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
						.B = {OperandType::Xmm},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0x7e,
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
						.Value = 0x7e,
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
			.IntelMnemonic = "vfnmsubss",
			.GasMnemonic = "vfnmsubss",
			.Description = "vfnmsubss xmm, xmm, xmm, m32",
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
				IsaExtension::Fma4,
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
						.X = {OperandType::M32},
						.B = {OperandType::M32},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0x7e,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M32},
						.Rm = {OperandType::M32},
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
			.IntelMnemonic = "vfnmsubss",
			.GasMnemonic = "vfnmsubss",
			.Description = "vfnmsubss xmm, xmm, m32, xmm",
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
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Fma4,
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
						.Value = 0x7e,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M32},
						.Rm = {OperandType::M32},
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
			.IntelMnemonic = "vfpclasspd",
			.GasMnemonic = "vfpclasspd",
			.Description = "vfpclasspd k{k}, m128/m64bcst, imm8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Kk,
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
						.Rr = {OperandType::Kk},
						.Bb = {OperandType::M128M64Bcst},
						.X = {OperandType::M128M64Bcst},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M128M64Bcst},
						.Aaa = {OperandType::Kk},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 16,
					},
					OpCode
					{
						.Value = 0x66,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128M64Bcst},
						.Rm = {OperandType::M128M64Bcst},
						.Reg = {OperandType::Kk},
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
			.IntelMnemonic = "vfpclasspd",
			.GasMnemonic = "vfpclasspd",
			.Description = "vfpclasspd k{k}, m256/m64bcst, imm8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Kk,
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
						.Rr = {OperandType::Kk},
						.Bb = {OperandType::M256M64Bcst},
						.X = {OperandType::M256M64Bcst},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M256M64Bcst},
						.Aaa = {OperandType::Kk},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 32,
					},
					OpCode
					{
						.Value = 0x66,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M256M64Bcst},
						.Rm = {OperandType::M256M64Bcst},
						.Reg = {OperandType::Kk},
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
			.IntelMnemonic = "vfpclasspd",
			.GasMnemonic = "vfpclasspd",
			.Description = "vfpclasspd k{k}, m512/m64bcst, imm8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Kk,
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
						.Rr = {OperandType::Kk},
						.Bb = {OperandType::M512M64Bcst},
						.X = {OperandType::M512M64Bcst},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M512M64Bcst},
						.Aaa = {OperandType::Kk},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 64,
					},
					OpCode
					{
						.Value = 0x66,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M512M64Bcst},
						.Rm = {OperandType::M512M64Bcst},
						.Reg = {OperandType::Kk},
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
			.IntelMnemonic = "vfpclasspd",
			.GasMnemonic = "vfpclasspd",
			.Description = "vfpclasspd k{k}, xmm, imm8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Kk,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
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
						.Rr = {OperandType::Kk},
						.Bb = {OperandType::Xmm},
						.X = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Aaa = {OperandType::Kk},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 0,
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
						.Reg = {OperandType::Kk},
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
			.IntelMnemonic = "vfpclasspd",
			.GasMnemonic = "vfpclasspd",
			.Description = "vfpclasspd k{k}, ymm, imm8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Kk,
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
						.Rr = {OperandType::Kk},
						.Bb = {OperandType::Ymm},
						.X = {OperandType::Ymm},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Ymm},
						.Aaa = {OperandType::Kk},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 0,
					},
					OpCode
					{
						.Value = 0x66,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Ymm},
						.Reg = {OperandType::Kk},
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
			.IntelMnemonic = "vfpclasspd",
			.GasMnemonic = "vfpclasspd",
			.Description = "vfpclasspd k{k}, zmm, imm8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Kk,
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
						.Rr = {OperandType::Kk},
						.Bb = {OperandType::Zmm},
						.X = {OperandType::Zmm},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Zmm},
						.Aaa = {OperandType::Kk},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 0,
					},
					OpCode
					{
						.Value = 0x66,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Zmm},
						.Reg = {OperandType::Kk},
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
			.IntelMnemonic = "vfpclassps",
			.GasMnemonic = "vfpclassps",
			.Description = "vfpclassps k{k}, m128/m32bcst, imm8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Kk,
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
						.Rr = {OperandType::Kk},
						.Bb = {OperandType::M128M32Bcst},
						.X = {OperandType::M128M32Bcst},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M128M32Bcst},
						.Aaa = {OperandType::Kk},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 16,
					},
					OpCode
					{
						.Value = 0x66,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128M32Bcst},
						.Rm = {OperandType::M128M32Bcst},
						.Reg = {OperandType::Kk},
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
			.IntelMnemonic = "vfpclassps",
			.GasMnemonic = "vfpclassps",
			.Description = "vfpclassps k{k}, m256/m32bcst, imm8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Kk,
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
						.Ll = UINT64_C(0x1),
						.Rr = {OperandType::Kk},
						.Bb = {OperandType::M256M32Bcst},
						.X = {OperandType::M256M32Bcst},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M256M32Bcst},
						.Aaa = {OperandType::Kk},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 32,
					},
					OpCode
					{
						.Value = 0x66,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M256M32Bcst},
						.Rm = {OperandType::M256M32Bcst},
						.Reg = {OperandType::Kk},
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
			.IntelMnemonic = "vfpclassps",
			.GasMnemonic = "vfpclassps",
			.Description = "vfpclassps k{k}, m512/m32bcst, imm8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Kk,
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
						.Rr = {OperandType::Kk},
						.Bb = {OperandType::M512M32Bcst},
						.X = {OperandType::M512M32Bcst},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M512M32Bcst},
						.Aaa = {OperandType::Kk},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 64,
					},
					OpCode
					{
						.Value = 0x66,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M512M32Bcst},
						.Rm = {OperandType::M512M32Bcst},
						.Reg = {OperandType::Kk},
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
			.IntelMnemonic = "vfpclassps",
			.GasMnemonic = "vfpclassps",
			.Description = "vfpclassps k{k}, xmm, imm8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Kk,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
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
						.Rr = {OperandType::Kk},
						.Bb = {OperandType::Xmm},
						.X = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Aaa = {OperandType::Kk},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 0,
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
						.Reg = {OperandType::Kk},
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
			.IntelMnemonic = "vfpclassps",
			.GasMnemonic = "vfpclassps",
			.Description = "vfpclassps k{k}, ymm, imm8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Kk,
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
						.W = false,
						.Ll = UINT64_C(0x1),
						.Rr = {OperandType::Kk},
						.Bb = {OperandType::Ymm},
						.X = {OperandType::Ymm},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Ymm},
						.Aaa = {OperandType::Kk},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 0,
					},
					OpCode
					{
						.Value = 0x66,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Ymm},
						.Reg = {OperandType::Kk},
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
			.IntelMnemonic = "vfpclassps",
			.GasMnemonic = "vfpclassps",
			.Description = "vfpclassps k{k}, zmm, imm8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Kk,
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
						.Rr = {OperandType::Kk},
						.Bb = {OperandType::Zmm},
						.X = {OperandType::Zmm},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Zmm},
						.Aaa = {OperandType::Kk},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 0,
					},
					OpCode
					{
						.Value = 0x66,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Zmm},
						.Reg = {OperandType::Kk},
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
			.IntelMnemonic = "vfpclasssd",
			.GasMnemonic = "vfpclasssd",
			.Description = "vfpclasssd k{k}, xmm, imm8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Kk,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
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
						.Rr = {OperandType::Kk},
						.Bb = {OperandType::Xmm},
						.X = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Aaa = {OperandType::Kk},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 0,
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
						.Reg = {OperandType::Kk},
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
			.IntelMnemonic = "vfpclasssd",
			.GasMnemonic = "vfpclasssd",
			.Description = "vfpclasssd k{k}, m64, imm8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Kk,
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
						.Rr = {OperandType::Kk},
						.Bb = {OperandType::M64},
						.X = {OperandType::M64},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M64},
						.Aaa = {OperandType::Kk},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 8,
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
						.Reg = {OperandType::Kk},
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
			.IntelMnemonic = "vfpclassss",
			.GasMnemonic = "vfpclassss",
			.Description = "vfpclassss k{k}, xmm, imm8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Kk,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
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
						.Rr = {OperandType::Kk},
						.Bb = {OperandType::Xmm},
						.X = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Aaa = {OperandType::Kk},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 0,
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
						.Reg = {OperandType::Kk},
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
			.IntelMnemonic = "vfpclassss",
			.GasMnemonic = "vfpclassss",
			.Description = "vfpclassss k{k}, m32, imm8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Kk,
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
					.Type = OperandType::Imm8,
					.IsInput = false,
					.IsOutput = false,
					.ExtendedSize = 0
				},
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
						.Rr = {OperandType::Kk},
						.Bb = {OperandType::M32},
						.X = {OperandType::M32},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M32},
						.Aaa = {OperandType::Kk},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 4,
					},
					OpCode
					{
						.Value = 0x67,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M32},
						.Rm = {OperandType::M32},
						.Reg = {OperandType::Kk},
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
			.IntelMnemonic = "vfrczpd",
			.GasMnemonic = "vfrczpd",
			.Description = "vfrczpd xmm, xmm",
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
						.Value = 0x81,
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
			.IntelMnemonic = "vfrczpd",
			.GasMnemonic = "vfrczpd",
			.Description = "vfrczpd xmm, m128",
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
						.Value = 0x81,
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
			.IntelMnemonic = "vfrczpd",
			.GasMnemonic = "vfrczpd",
			.Description = "vfrczpd ymm, ymm",
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
						.L = true,
						.R = {OperandType::Ymm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Ymm},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x81,
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
			.IntelMnemonic = "vfrczpd",
			.GasMnemonic = "vfrczpd",
			.Description = "vfrczpd ymm, m256",
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
						.L = true,
						.R = {OperandType::Ymm},
						.X = {OperandType::M256},
						.B = {OperandType::M256},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x81,
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
			.IntelMnemonic = "vfrczps",
			.GasMnemonic = "vfrczps",
			.Description = "vfrczps xmm, xmm",
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
						.Value = 0x80,
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
			.IntelMnemonic = "vfrczps",
			.GasMnemonic = "vfrczps",
			.Description = "vfrczps xmm, m128",
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
						.Value = 0x80,
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
			.IntelMnemonic = "vfrczps",
			.GasMnemonic = "vfrczps",
			.Description = "vfrczps ymm, ymm",
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
						.L = true,
						.R = {OperandType::Ymm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Ymm},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x80,
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
			.IntelMnemonic = "vfrczps",
			.GasMnemonic = "vfrczps",
			.Description = "vfrczps ymm, m256",
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
						.L = true,
						.R = {OperandType::Ymm},
						.X = {OperandType::M256},
						.B = {OperandType::M256},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x80,
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
			.IntelMnemonic = "vfrczsd",
			.GasMnemonic = "vfrczsd",
			.Description = "vfrczsd xmm, xmm",
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
						.Value = 0x83,
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
			.IntelMnemonic = "vfrczsd",
			.GasMnemonic = "vfrczsd",
			.Description = "vfrczsd xmm, m64",
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
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.Vvvv = {UINT64_C(0x0)},
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
			.IntelMnemonic = "vfrczss",
			.GasMnemonic = "vfrczss",
			.Description = "vfrczss xmm, xmm",
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
						.Value = 0x82,
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
			.IntelMnemonic = "vfrczss",
			.GasMnemonic = "vfrczss",
			.Description = "vfrczss xmm, m32",
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
						.X = {OperandType::M32},
						.B = {OperandType::M32},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x82,
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
			.IntelMnemonic = "vgatherdpd",
			.GasMnemonic = "vgatherdpd",
			.Description = "vgatherdpd xmm{k}, vm32x",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::XmmK,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Vm32x,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
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
						.Rr = {OperandType::XmmK},
						.Bb = {OperandType::Vm32x},
						.X = {OperandType::Vm32x},
						.Vvvv = {UINT64_C(0x0)},
						.V = {OperandType::Vm32x},
						.B = {OperandType::Vm32x},
						.Aaa = {OperandType::XmmK},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 8,
					},
					OpCode
					{
						.Value = 0x92,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::Vm32x},
						.Rm = {OperandType::Vm32x},
						.Reg = {OperandType::XmmK},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vgatherdpd",
			.GasMnemonic = "vgatherdpd",
			.Description = "vgatherdpd ymm{k}, vm32x",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::YmmK,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Vm32x,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
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
						.Rr = {OperandType::YmmK},
						.Bb = {OperandType::Vm32x},
						.X = {OperandType::Vm32x},
						.Vvvv = {UINT64_C(0x0)},
						.V = {OperandType::Vm32x},
						.B = {OperandType::Vm32x},
						.Aaa = {OperandType::YmmK},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 8,
					},
					OpCode
					{
						.Value = 0x92,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::Vm32x},
						.Rm = {OperandType::Vm32x},
						.Reg = {OperandType::YmmK},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vgatherdpd",
			.GasMnemonic = "vgatherdpd",
			.Description = "vgatherdpd zmm{k}, vm32y",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::ZmmK,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Vm32y,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
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
						.Rr = {OperandType::ZmmK},
						.Bb = {OperandType::Vm32y},
						.X = {OperandType::Vm32y},
						.Vvvv = {UINT64_C(0x0)},
						.V = {OperandType::Vm32y},
						.B = {OperandType::Vm32y},
						.Aaa = {OperandType::ZmmK},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 8,
					},
					OpCode
					{
						.Value = 0x92,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::Vm32y},
						.Rm = {OperandType::Vm32y},
						.Reg = {OperandType::ZmmK},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vgatherdpd",
			.GasMnemonic = "vgatherdpd",
			.Description = "vgatherdpd xmm, vm32x, xmm",
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
					.Type = OperandType::Vm32x,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
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
						.X = {OperandType::Vm32x},
						.B = {OperandType::Vm32x},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0x92,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::Vm32x},
						.Rm = {OperandType::Vm32x},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vgatherdpd",
			.GasMnemonic = "vgatherdpd",
			.Description = "vgatherdpd ymm, vm32x, ymm",
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
					.Type = OperandType::Vm32x,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Ymm,
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
						.X = {OperandType::Vm32x},
						.B = {OperandType::Vm32x},
						.Vvvv = {OperandType::Ymm},
					},
					OpCode
					{
						.Value = 0x92,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::Vm32x},
						.Rm = {OperandType::Vm32x},
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
			.IntelMnemonic = "vgatherdps",
			.GasMnemonic = "vgatherdps",
			.Description = "vgatherdps xmm{k}, vm32x",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::XmmK,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Vm32x,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
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
						.Rr = {OperandType::XmmK},
						.Bb = {OperandType::Vm32x},
						.X = {OperandType::Vm32x},
						.Vvvv = {UINT64_C(0x0)},
						.V = {OperandType::Vm32x},
						.B = {OperandType::Vm32x},
						.Aaa = {OperandType::XmmK},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 4,
					},
					OpCode
					{
						.Value = 0x92,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::Vm32x},
						.Rm = {OperandType::Vm32x},
						.Reg = {OperandType::XmmK},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vgatherdps",
			.GasMnemonic = "vgatherdps",
			.Description = "vgatherdps ymm{k}, vm32y",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::YmmK,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Vm32y,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
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
						.Rr = {OperandType::YmmK},
						.Bb = {OperandType::Vm32y},
						.X = {OperandType::Vm32y},
						.Vvvv = {UINT64_C(0x0)},
						.V = {OperandType::Vm32y},
						.B = {OperandType::Vm32y},
						.Aaa = {OperandType::YmmK},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 4,
					},
					OpCode
					{
						.Value = 0x92,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::Vm32y},
						.Rm = {OperandType::Vm32y},
						.Reg = {OperandType::YmmK},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vgatherdps",
			.GasMnemonic = "vgatherdps",
			.Description = "vgatherdps zmm{k}, vm32z",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::ZmmK,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Vm32z,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
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
						.Rr = {OperandType::ZmmK},
						.Bb = {OperandType::Vm32z},
						.X = {OperandType::Vm32z},
						.Vvvv = {UINT64_C(0x0)},
						.V = {OperandType::Vm32z},
						.B = {OperandType::Vm32z},
						.Aaa = {OperandType::ZmmK},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 4,
					},
					OpCode
					{
						.Value = 0x92,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::Vm32z},
						.Rm = {OperandType::Vm32z},
						.Reg = {OperandType::ZmmK},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vgatherdps",
			.GasMnemonic = "vgatherdps",
			.Description = "vgatherdps xmm, vm32x, xmm",
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
					.Type = OperandType::Vm32x,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
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
						.X = {OperandType::Vm32x},
						.B = {OperandType::Vm32x},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0x92,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::Vm32x},
						.Rm = {OperandType::Vm32x},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vgatherdps",
			.GasMnemonic = "vgatherdps",
			.Description = "vgatherdps ymm, vm32y, ymm",
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
					.Type = OperandType::Vm32y,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Ymm,
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
						.X = {OperandType::Vm32y},
						.B = {OperandType::Vm32y},
						.Vvvv = {OperandType::Ymm},
					},
					OpCode
					{
						.Value = 0x92,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::Vm32y},
						.Rm = {OperandType::Vm32y},
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
			.IntelMnemonic = "vgatherpf0dpd",
			.GasMnemonic = "vgatherpf0dpd",
			.Description = "vgatherpf0dpd vm32y{k}",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Vm32yk,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Avx512Pf,
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
						.Rr = {UINT64_C(0x0)},
						.Bb = {OperandType::Vm32yk},
						.X = {OperandType::Vm32yk},
						.Vvvv = {UINT64_C(0x0)},
						.V = {OperandType::Vm32yk},
						.B = {OperandType::Vm32yk},
						.Aaa = {OperandType::Vm32yk},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 8,
					},
					OpCode
					{
						.Value = 0xc6,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::Vm32yk},
						.Rm = {OperandType::Vm32yk},
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
			.IntelMnemonic = "vgatherpf0dps",
			.GasMnemonic = "vgatherpf0dps",
			.Description = "vgatherpf0dps vm32z{k}",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Vm32zk,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Avx512Pf,
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
						.Rr = {UINT64_C(0x0)},
						.Bb = {OperandType::Vm32zk},
						.X = {OperandType::Vm32zk},
						.Vvvv = {UINT64_C(0x0)},
						.V = {OperandType::Vm32zk},
						.B = {OperandType::Vm32zk},
						.Aaa = {OperandType::Vm32zk},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 4,
					},
					OpCode
					{
						.Value = 0xc6,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::Vm32zk},
						.Rm = {OperandType::Vm32zk},
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
			.IntelMnemonic = "vgatherpf0qpd",
			.GasMnemonic = "vgatherpf0qpd",
			.Description = "vgatherpf0qpd vm64z{k}",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Vm64zk,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Avx512Pf,
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
						.Rr = {UINT64_C(0x0)},
						.Bb = {OperandType::Vm64zk},
						.X = {OperandType::Vm64zk},
						.Vvvv = {UINT64_C(0x0)},
						.V = {OperandType::Vm64zk},
						.B = {OperandType::Vm64zk},
						.Aaa = {OperandType::Vm64zk},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 8,
					},
					OpCode
					{
						.Value = 0xc7,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::Vm64zk},
						.Rm = {OperandType::Vm64zk},
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
			.IntelMnemonic = "vgatherpf0qps",
			.GasMnemonic = "vgatherpf0qps",
			.Description = "vgatherpf0qps vm64z{k}",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Vm64zk,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Avx512Pf,
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
						.Rr = {UINT64_C(0x0)},
						.Bb = {OperandType::Vm64zk},
						.X = {OperandType::Vm64zk},
						.Vvvv = {UINT64_C(0x0)},
						.V = {OperandType::Vm64zk},
						.B = {OperandType::Vm64zk},
						.Aaa = {OperandType::Vm64zk},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 4,
					},
					OpCode
					{
						.Value = 0xc7,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::Vm64zk},
						.Rm = {OperandType::Vm64zk},
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
			.IntelMnemonic = "vgatherpf1dpd",
			.GasMnemonic = "vgatherpf1dpd",
			.Description = "vgatherpf1dpd vm32y{k}",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Vm32yk,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Avx512Pf,
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
						.Rr = {UINT64_C(0x0)},
						.Bb = {OperandType::Vm32yk},
						.X = {OperandType::Vm32yk},
						.Vvvv = {UINT64_C(0x0)},
						.V = {OperandType::Vm32yk},
						.B = {OperandType::Vm32yk},
						.Aaa = {OperandType::Vm32yk},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 8,
					},
					OpCode
					{
						.Value = 0xc6,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::Vm32yk},
						.Rm = {OperandType::Vm32yk},
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
			.IntelMnemonic = "vgatherpf1dps",
			.GasMnemonic = "vgatherpf1dps",
			.Description = "vgatherpf1dps vm32z{k}",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Vm32zk,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Avx512Pf,
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
						.Rr = {UINT64_C(0x0)},
						.Bb = {OperandType::Vm32zk},
						.X = {OperandType::Vm32zk},
						.Vvvv = {UINT64_C(0x0)},
						.V = {OperandType::Vm32zk},
						.B = {OperandType::Vm32zk},
						.Aaa = {OperandType::Vm32zk},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 4,
					},
					OpCode
					{
						.Value = 0xc6,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::Vm32zk},
						.Rm = {OperandType::Vm32zk},
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
			.IntelMnemonic = "vgatherpf1qpd",
			.GasMnemonic = "vgatherpf1qpd",
			.Description = "vgatherpf1qpd vm64z{k}",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Vm64zk,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Avx512Pf,
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
						.Rr = {UINT64_C(0x0)},
						.Bb = {OperandType::Vm64zk},
						.X = {OperandType::Vm64zk},
						.Vvvv = {UINT64_C(0x0)},
						.V = {OperandType::Vm64zk},
						.B = {OperandType::Vm64zk},
						.Aaa = {OperandType::Vm64zk},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 8,
					},
					OpCode
					{
						.Value = 0xc7,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::Vm64zk},
						.Rm = {OperandType::Vm64zk},
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
			.IntelMnemonic = "vgatherpf1qps",
			.GasMnemonic = "vgatherpf1qps",
			.Description = "vgatherpf1qps vm64z{k}",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Vm64zk,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Avx512Pf,
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
						.Rr = {UINT64_C(0x0)},
						.Bb = {OperandType::Vm64zk},
						.X = {OperandType::Vm64zk},
						.Vvvv = {UINT64_C(0x0)},
						.V = {OperandType::Vm64zk},
						.B = {OperandType::Vm64zk},
						.Aaa = {OperandType::Vm64zk},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 4,
					},
					OpCode
					{
						.Value = 0xc7,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::Vm64zk},
						.Rm = {OperandType::Vm64zk},
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
			.IntelMnemonic = "vgatherqpd",
			.GasMnemonic = "vgatherqpd",
			.Description = "vgatherqpd xmm{k}, vm64x",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::XmmK,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Vm64x,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
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
						.Rr = {OperandType::XmmK},
						.Bb = {OperandType::Vm64x},
						.X = {OperandType::Vm64x},
						.Vvvv = {UINT64_C(0x0)},
						.V = {OperandType::Vm64x},
						.B = {OperandType::Vm64x},
						.Aaa = {OperandType::XmmK},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 8,
					},
					OpCode
					{
						.Value = 0x93,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::Vm64x},
						.Rm = {OperandType::Vm64x},
						.Reg = {OperandType::XmmK},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vgatherqpd",
			.GasMnemonic = "vgatherqpd",
			.Description = "vgatherqpd ymm{k}, vm64y",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::YmmK,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Vm64y,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
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
						.Rr = {OperandType::YmmK},
						.Bb = {OperandType::Vm64y},
						.X = {OperandType::Vm64y},
						.Vvvv = {UINT64_C(0x0)},
						.V = {OperandType::Vm64y},
						.B = {OperandType::Vm64y},
						.Aaa = {OperandType::YmmK},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 8,
					},
					OpCode
					{
						.Value = 0x93,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::Vm64y},
						.Rm = {OperandType::Vm64y},
						.Reg = {OperandType::YmmK},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vgatherqpd",
			.GasMnemonic = "vgatherqpd",
			.Description = "vgatherqpd zmm{k}, vm64z",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::ZmmK,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Vm64z,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
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
						.Rr = {OperandType::ZmmK},
						.Bb = {OperandType::Vm64z},
						.X = {OperandType::Vm64z},
						.Vvvv = {UINT64_C(0x0)},
						.V = {OperandType::Vm64z},
						.B = {OperandType::Vm64z},
						.Aaa = {OperandType::ZmmK},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 8,
					},
					OpCode
					{
						.Value = 0x93,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::Vm64z},
						.Rm = {OperandType::Vm64z},
						.Reg = {OperandType::ZmmK},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vgatherqpd",
			.GasMnemonic = "vgatherqpd",
			.Description = "vgatherqpd xmm, vm64x, xmm",
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
					.Type = OperandType::Vm64x,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
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
						.X = {OperandType::Vm64x},
						.B = {OperandType::Vm64x},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0x93,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::Vm64x},
						.Rm = {OperandType::Vm64x},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vgatherqpd",
			.GasMnemonic = "vgatherqpd",
			.Description = "vgatherqpd ymm, vm64y, ymm",
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
					.Type = OperandType::Vm64y,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Ymm,
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
						.X = {OperandType::Vm64y},
						.B = {OperandType::Vm64y},
						.Vvvv = {OperandType::Ymm},
					},
					OpCode
					{
						.Value = 0x93,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::Vm64y},
						.Rm = {OperandType::Vm64y},
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
			.IntelMnemonic = "vgatherqps",
			.GasMnemonic = "vgatherqps",
			.Description = "vgatherqps xmm{k}, vm64x",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::XmmK,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Vm64x,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
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
						.Rr = {OperandType::XmmK},
						.Bb = {OperandType::Vm64x},
						.X = {OperandType::Vm64x},
						.Vvvv = {UINT64_C(0x0)},
						.V = {OperandType::Vm64x},
						.B = {OperandType::Vm64x},
						.Aaa = {OperandType::XmmK},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 4,
					},
					OpCode
					{
						.Value = 0x93,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::Vm64x},
						.Rm = {OperandType::Vm64x},
						.Reg = {OperandType::XmmK},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vgatherqps",
			.GasMnemonic = "vgatherqps",
			.Description = "vgatherqps xmm{k}, vm64y",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::XmmK,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Vm64y,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
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
						.Rr = {OperandType::XmmK},
						.Bb = {OperandType::Vm64y},
						.X = {OperandType::Vm64y},
						.Vvvv = {UINT64_C(0x0)},
						.V = {OperandType::Vm64y},
						.B = {OperandType::Vm64y},
						.Aaa = {OperandType::XmmK},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 4,
					},
					OpCode
					{
						.Value = 0x93,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::Vm64y},
						.Rm = {OperandType::Vm64y},
						.Reg = {OperandType::XmmK},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vgatherqps",
			.GasMnemonic = "vgatherqps",
			.Description = "vgatherqps ymm{k}, vm64z",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::YmmK,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Vm64z,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
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
						.Rr = {OperandType::YmmK},
						.Bb = {OperandType::Vm64z},
						.X = {OperandType::Vm64z},
						.Vvvv = {UINT64_C(0x0)},
						.V = {OperandType::Vm64z},
						.B = {OperandType::Vm64z},
						.Aaa = {OperandType::YmmK},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 4,
					},
					OpCode
					{
						.Value = 0x93,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::Vm64z},
						.Rm = {OperandType::Vm64z},
						.Reg = {OperandType::YmmK},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vgatherqps",
			.GasMnemonic = "vgatherqps",
			.Description = "vgatherqps xmm, vm64x, xmm",
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
					.Type = OperandType::Vm64x,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
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
						.X = {OperandType::Vm64x},
						.B = {OperandType::Vm64x},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0x93,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::Vm64x},
						.Rm = {OperandType::Vm64x},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vgatherqps",
			.GasMnemonic = "vgatherqps",
			.Description = "vgatherqps xmm, vm64y, xmm",
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
					.Type = OperandType::Vm64y,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
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
						.R = {OperandType::Xmm},
						.X = {OperandType::Vm64y},
						.B = {OperandType::Vm64y},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0x93,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::Vm64y},
						.Rm = {OperandType::Vm64y},
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
			.IntelMnemonic = "vgetexppd",
			.GasMnemonic = "vgetexppd",
			.Description = "vgetexppd xmm{k}{z}, m128/m64bcst",
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
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M128M64Bcst},
						.Aaa = {OperandType::XmmKz},
						.Z = {OperandType::XmmKz},
						.Disp8xN = 16,
					},
					OpCode
					{
						.Value = 0x42,
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
			.IntelMnemonic = "vgetexppd",
			.GasMnemonic = "vgetexppd",
			.Description = "vgetexppd ymm{k}{z}, m256/m64bcst",
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
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M256M64Bcst},
						.Aaa = {OperandType::YmmKz},
						.Z = {OperandType::YmmKz},
						.Disp8xN = 32,
					},
					OpCode
					{
						.Value = 0x42,
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
			.IntelMnemonic = "vgetexppd",
			.GasMnemonic = "vgetexppd",
			.Description = "vgetexppd zmm{k}{z}, m512/m64bcst",
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
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M512M64Bcst},
						.Aaa = {OperandType::ZmmKz},
						.Z = {OperandType::ZmmKz},
						.Disp8xN = 64,
					},
					OpCode
					{
						.Value = 0x42,
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
			.IntelMnemonic = "vgetexppd",
			.GasMnemonic = "vgetexppd",
			.Description = "vgetexppd xmm{k}{z}, xmm",
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
						.Value = 0x42,
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
			.IntelMnemonic = "vgetexppd",
			.GasMnemonic = "vgetexppd",
			.Description = "vgetexppd ymm{k}{z}, ymm",
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
						.Value = 0x42,
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
			.IntelMnemonic = "vgetexppd",
			.GasMnemonic = "vgetexppd",
			.Description = "vgetexppd zmm{k}{z}, zmm, {sae}",
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
						.Value = 0x42,
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
			.IntelMnemonic = "vgetexpps",
			.GasMnemonic = "vgetexpps",
			.Description = "vgetexpps xmm{k}{z}, m128/m32bcst",
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
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M128M32Bcst},
						.Aaa = {OperandType::XmmKz},
						.Z = {OperandType::XmmKz},
						.Disp8xN = 16,
					},
					OpCode
					{
						.Value = 0x42,
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
			.IntelMnemonic = "vgetexpps",
			.GasMnemonic = "vgetexpps",
			.Description = "vgetexpps ymm{k}{z}, m256/m32bcst",
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
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M256M32Bcst},
						.Aaa = {OperandType::YmmKz},
						.Z = {OperandType::YmmKz},
						.Disp8xN = 32,
					},
					OpCode
					{
						.Value = 0x42,
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
			.IntelMnemonic = "vgetexpps",
			.GasMnemonic = "vgetexpps",
			.Description = "vgetexpps zmm{k}{z}, m512/m32bcst",
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
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M512M32Bcst},
						.Aaa = {OperandType::ZmmKz},
						.Z = {OperandType::ZmmKz},
						.Disp8xN = 64,
					},
					OpCode
					{
						.Value = 0x42,
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
			.IntelMnemonic = "vgetexpps",
			.GasMnemonic = "vgetexpps",
			.Description = "vgetexpps xmm{k}{z}, xmm",
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
						.Value = 0x42,
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
			.IntelMnemonic = "vgetexpps",
			.GasMnemonic = "vgetexpps",
			.Description = "vgetexpps ymm{k}{z}, ymm",
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
						.Value = 0x42,
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
			.IntelMnemonic = "vgetexpps",
			.GasMnemonic = "vgetexpps",
			.Description = "vgetexpps zmm{k}{z}, zmm, {sae}",
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
						.Value = 0x42,
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
			.IntelMnemonic = "vgetexpsd",
			.GasMnemonic = "vgetexpsd",
			.Description = "vgetexpsd xmm{k}{z}, xmm, m64",
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
						.Value = 0x43,
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
			.IntelMnemonic = "vgetexpsd",
			.GasMnemonic = "vgetexpsd",
			.Description = "vgetexpsd xmm{k}{z}, xmm, xmm, {sae}",
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
						.Value = 0x43,
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
			.IntelMnemonic = "vgetexpss",
			.GasMnemonic = "vgetexpss",
			.Description = "vgetexpss xmm{k}{z}, xmm, m32",
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
						.Value = 0x43,
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
			.IntelMnemonic = "vgetexpss",
			.GasMnemonic = "vgetexpss",
			.Description = "vgetexpss xmm{k}{z}, xmm, xmm, {sae}",
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
						.Value = 0x43,
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
			.IntelMnemonic = "vgetmantpd",
			.GasMnemonic = "vgetmantpd",
			.Description = "vgetmantpd xmm{k}{z}, m128/m64bcst, imm8",
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
						.Mm = 0b11,
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
						.Value = 0x26,
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
			.IntelMnemonic = "vgetmantpd",
			.GasMnemonic = "vgetmantpd",
			.Description = "vgetmantpd ymm{k}{z}, m256/m64bcst, imm8",
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
						.Mm = 0b11,
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
						.Value = 0x26,
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
			.IntelMnemonic = "vgetmantpd",
			.GasMnemonic = "vgetmantpd",
			.Description = "vgetmantpd zmm{k}{z}, m512/m64bcst, imm8",
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
						.Mm = 0b11,
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
						.Value = 0x26,
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
			.IntelMnemonic = "vgetmantpd",
			.GasMnemonic = "vgetmantpd",
			.Description = "vgetmantpd xmm{k}{z}, xmm, imm8",
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
						.Mm = 0b11,
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
						.Value = 0x26,
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
			.IntelMnemonic = "vgetmantpd",
			.GasMnemonic = "vgetmantpd",
			.Description = "vgetmantpd ymm{k}{z}, ymm, imm8",
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
						.Mm = 0b11,
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
						.Value = 0x26,
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
			.IntelMnemonic = "vgetmantpd",
			.GasMnemonic = "vgetmantpd",
			.Description = "vgetmantpd zmm{k}{z}, zmm, {sae}, imm8",
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
				Operand
				{
					.Type = OperandType::Imm8,
					.IsInput = false,
					.IsOutput = false,
					.ExtendedSize = 0
				},
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
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Zmm},
						.Aaa = {OperandType::ZmmKz},
						.Z = {OperandType::ZmmKz},
						.Disp8xN = 0,
					},
					OpCode
					{
						.Value = 0x26,
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
