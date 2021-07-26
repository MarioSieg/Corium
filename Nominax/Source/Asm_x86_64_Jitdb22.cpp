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
NOX_NEVER_INLINE NOX_COLD auto GetVariationTable_22(std::pmr::monotonic_buffer_resource& allocator, std::pmr::vector<InstructionVariationPool>& out) -> void
{
	std::pmr::vector<InstructionVariation> instruction{&allocator};
	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "vfmsubadd231ps",
			.GasMnemonic = "vfmsubadd231ps",
			.Description = "vfmsubadd231ps xmm{k}{z}, xmm, m128/m32bcst",
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
						.Value = 0xb7,
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
			.IntelMnemonic = "vfmsubadd231ps",
			.GasMnemonic = "vfmsubadd231ps",
			.Description = "vfmsubadd231ps xmm{k}{z}, xmm, xmm",
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
						.Value = 0xb7,
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
			.IntelMnemonic = "vfmsubadd231ps",
			.GasMnemonic = "vfmsubadd231ps",
			.Description = "vfmsubadd231ps ymm{k}{z}, ymm, m256/m32bcst",
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
						.Value = 0xb7,
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
			.IntelMnemonic = "vfmsubadd231ps",
			.GasMnemonic = "vfmsubadd231ps",
			.Description = "vfmsubadd231ps ymm{k}{z}, ymm, ymm",
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
						.Value = 0xb7,
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
			.IntelMnemonic = "vfmsubadd231ps",
			.GasMnemonic = "vfmsubadd231ps",
			.Description = "vfmsubadd231ps zmm{k}{z}, zmm, m512/m32bcst",
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
						.Value = 0xb7,
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
			.IntelMnemonic = "vfmsubadd231ps",
			.GasMnemonic = "vfmsubadd231ps",
			.Description = "vfmsubadd231ps xmm, xmm, xmm",
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
						.Value = 0xb7,
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
			.IntelMnemonic = "vfmsubadd231ps",
			.GasMnemonic = "vfmsubadd231ps",
			.Description = "vfmsubadd231ps xmm, xmm, m128",
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
						.Value = 0xb7,
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
			.IntelMnemonic = "vfmsubadd231ps",
			.GasMnemonic = "vfmsubadd231ps",
			.Description = "vfmsubadd231ps ymm, ymm, ymm",
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
						.Value = 0xb7,
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
			.IntelMnemonic = "vfmsubadd231ps",
			.GasMnemonic = "vfmsubadd231ps",
			.Description = "vfmsubadd231ps ymm, ymm, m256",
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
						.Value = 0xb7,
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
			.IntelMnemonic = "vfmsubadd231ps",
			.GasMnemonic = "vfmsubadd231ps",
			.Description = "vfmsubadd231ps zmm{k}{z}, zmm, zmm, {er}",
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
						.Value = 0xb7,
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
			.IntelMnemonic = "vfmsubaddpd",
			.GasMnemonic = "vfmsubaddpd",
			.Description = "vfmsubaddpd xmm, xmm, xmm, xmm",
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
						.Value = 0x5f,
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
						.Value = 0x5f,
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
			.IntelMnemonic = "vfmsubaddpd",
			.GasMnemonic = "vfmsubaddpd",
			.Description = "vfmsubaddpd xmm, xmm, xmm, m128",
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
						.Value = 0x5f,
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
			.IntelMnemonic = "vfmsubaddpd",
			.GasMnemonic = "vfmsubaddpd",
			.Description = "vfmsubaddpd xmm, xmm, m128, xmm",
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
						.Value = 0x5f,
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
			.IntelMnemonic = "vfmsubaddpd",
			.GasMnemonic = "vfmsubaddpd",
			.Description = "vfmsubaddpd ymm, ymm, ymm, ymm",
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
						.Value = 0x5f,
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
						.Value = 0x5f,
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
			.IntelMnemonic = "vfmsubaddpd",
			.GasMnemonic = "vfmsubaddpd",
			.Description = "vfmsubaddpd ymm, ymm, ymm, m256",
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
						.Value = 0x5f,
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
			.IntelMnemonic = "vfmsubaddpd",
			.GasMnemonic = "vfmsubaddpd",
			.Description = "vfmsubaddpd ymm, ymm, m256, ymm",
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
						.Value = 0x5f,
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
			.IntelMnemonic = "vfmsubaddps",
			.GasMnemonic = "vfmsubaddps",
			.Description = "vfmsubaddps xmm, xmm, xmm, xmm",
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
						.Value = 0x5e,
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
						.Value = 0x5e,
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
			.IntelMnemonic = "vfmsubaddps",
			.GasMnemonic = "vfmsubaddps",
			.Description = "vfmsubaddps xmm, xmm, xmm, m128",
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
						.Value = 0x5e,
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
			.IntelMnemonic = "vfmsubaddps",
			.GasMnemonic = "vfmsubaddps",
			.Description = "vfmsubaddps xmm, xmm, m128, xmm",
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
						.Value = 0x5e,
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
			.IntelMnemonic = "vfmsubaddps",
			.GasMnemonic = "vfmsubaddps",
			.Description = "vfmsubaddps ymm, ymm, ymm, ymm",
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
						.Value = 0x5e,
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
						.Value = 0x5e,
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
			.IntelMnemonic = "vfmsubaddps",
			.GasMnemonic = "vfmsubaddps",
			.Description = "vfmsubaddps ymm, ymm, ymm, m256",
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
						.Value = 0x5e,
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
			.IntelMnemonic = "vfmsubaddps",
			.GasMnemonic = "vfmsubaddps",
			.Description = "vfmsubaddps ymm, ymm, m256, ymm",
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
						.Value = 0x5e,
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
			.IntelMnemonic = "vfmsubpd",
			.GasMnemonic = "vfmsubpd",
			.Description = "vfmsubpd xmm, xmm, xmm, xmm",
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
						.Value = 0x6d,
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
						.Value = 0x6d,
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
			.IntelMnemonic = "vfmsubpd",
			.GasMnemonic = "vfmsubpd",
			.Description = "vfmsubpd xmm, xmm, xmm, m128",
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
						.Value = 0x6d,
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
			.IntelMnemonic = "vfmsubpd",
			.GasMnemonic = "vfmsubpd",
			.Description = "vfmsubpd xmm, xmm, m128, xmm",
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
						.Value = 0x6d,
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
			.IntelMnemonic = "vfmsubpd",
			.GasMnemonic = "vfmsubpd",
			.Description = "vfmsubpd ymm, ymm, ymm, ymm",
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
						.Value = 0x6d,
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
						.Value = 0x6d,
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
			.IntelMnemonic = "vfmsubpd",
			.GasMnemonic = "vfmsubpd",
			.Description = "vfmsubpd ymm, ymm, ymm, m256",
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
						.Value = 0x6d,
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
			.IntelMnemonic = "vfmsubpd",
			.GasMnemonic = "vfmsubpd",
			.Description = "vfmsubpd ymm, ymm, m256, ymm",
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
						.Value = 0x6d,
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
			.IntelMnemonic = "vfmsubps",
			.GasMnemonic = "vfmsubps",
			.Description = "vfmsubps xmm, xmm, xmm, xmm",
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
						.Value = 0x6c,
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
						.Value = 0x6c,
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
			.IntelMnemonic = "vfmsubps",
			.GasMnemonic = "vfmsubps",
			.Description = "vfmsubps xmm, xmm, xmm, m128",
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
						.Value = 0x6c,
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
			.IntelMnemonic = "vfmsubps",
			.GasMnemonic = "vfmsubps",
			.Description = "vfmsubps xmm, xmm, m128, xmm",
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
						.Value = 0x6c,
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
			.IntelMnemonic = "vfmsubps",
			.GasMnemonic = "vfmsubps",
			.Description = "vfmsubps ymm, ymm, ymm, ymm",
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
						.Value = 0x6c,
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
						.Value = 0x6c,
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
			.IntelMnemonic = "vfmsubps",
			.GasMnemonic = "vfmsubps",
			.Description = "vfmsubps ymm, ymm, ymm, m256",
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
						.Value = 0x6c,
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
			.IntelMnemonic = "vfmsubps",
			.GasMnemonic = "vfmsubps",
			.Description = "vfmsubps ymm, ymm, m256, ymm",
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
						.Value = 0x6c,
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
			.IntelMnemonic = "vfmsubsd",
			.GasMnemonic = "vfmsubsd",
			.Description = "vfmsubsd xmm, xmm, xmm, xmm",
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
						.Value = 0x6f,
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
						.Value = 0x6f,
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
			.IntelMnemonic = "vfmsubsd",
			.GasMnemonic = "vfmsubsd",
			.Description = "vfmsubsd xmm, xmm, xmm, m64",
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
						.Value = 0x6f,
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
			.IntelMnemonic = "vfmsubsd",
			.GasMnemonic = "vfmsubsd",
			.Description = "vfmsubsd xmm, xmm, m64, xmm",
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
						.Value = 0x6f,
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
			.IntelMnemonic = "vfmsubss",
			.GasMnemonic = "vfmsubss",
			.Description = "vfmsubss xmm, xmm, xmm, xmm",
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
						.Value = 0x6e,
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
						.Value = 0x6e,
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
			.IntelMnemonic = "vfmsubss",
			.GasMnemonic = "vfmsubss",
			.Description = "vfmsubss xmm, xmm, xmm, m32",
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
						.Value = 0x6e,
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
			.IntelMnemonic = "vfmsubss",
			.GasMnemonic = "vfmsubss",
			.Description = "vfmsubss xmm, xmm, m32, xmm",
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
						.Value = 0x6e,
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
			.IntelMnemonic = "vfnmadd132pd",
			.GasMnemonic = "vfnmadd132pd",
			.Description = "vfnmadd132pd xmm{k}{z}, xmm, m128/m64bcst",
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
						.Value = 0x9c,
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
			.IntelMnemonic = "vfnmadd132pd",
			.GasMnemonic = "vfnmadd132pd",
			.Description = "vfnmadd132pd xmm{k}{z}, xmm, xmm",
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
						.Value = 0x9c,
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
			.IntelMnemonic = "vfnmadd132pd",
			.GasMnemonic = "vfnmadd132pd",
			.Description = "vfnmadd132pd ymm{k}{z}, ymm, m256/m64bcst",
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
						.Value = 0x9c,
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
			.IntelMnemonic = "vfnmadd132pd",
			.GasMnemonic = "vfnmadd132pd",
			.Description = "vfnmadd132pd ymm{k}{z}, ymm, ymm",
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
						.Value = 0x9c,
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
			.IntelMnemonic = "vfnmadd132pd",
			.GasMnemonic = "vfnmadd132pd",
			.Description = "vfnmadd132pd zmm{k}{z}, zmm, m512/m64bcst",
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
						.Value = 0x9c,
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
			.IntelMnemonic = "vfnmadd132pd",
			.GasMnemonic = "vfnmadd132pd",
			.Description = "vfnmadd132pd xmm, xmm, xmm",
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
						.Value = 0x9c,
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
			.IntelMnemonic = "vfnmadd132pd",
			.GasMnemonic = "vfnmadd132pd",
			.Description = "vfnmadd132pd xmm, xmm, m128",
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
						.Value = 0x9c,
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
			.IntelMnemonic = "vfnmadd132pd",
			.GasMnemonic = "vfnmadd132pd",
			.Description = "vfnmadd132pd ymm, ymm, ymm",
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
						.Value = 0x9c,
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
			.IntelMnemonic = "vfnmadd132pd",
			.GasMnemonic = "vfnmadd132pd",
			.Description = "vfnmadd132pd ymm, ymm, m256",
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
						.Value = 0x9c,
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
			.IntelMnemonic = "vfnmadd132pd",
			.GasMnemonic = "vfnmadd132pd",
			.Description = "vfnmadd132pd zmm{k}{z}, zmm, zmm, {er}",
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
						.Value = 0x9c,
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
			.IntelMnemonic = "vfnmadd132ps",
			.GasMnemonic = "vfnmadd132ps",
			.Description = "vfnmadd132ps xmm{k}{z}, xmm, m128/m32bcst",
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
						.Value = 0x9c,
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
			.IntelMnemonic = "vfnmadd132ps",
			.GasMnemonic = "vfnmadd132ps",
			.Description = "vfnmadd132ps xmm{k}{z}, xmm, xmm",
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
						.Value = 0x9c,
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
			.IntelMnemonic = "vfnmadd132ps",
			.GasMnemonic = "vfnmadd132ps",
			.Description = "vfnmadd132ps ymm{k}{z}, ymm, m256/m32bcst",
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
						.Value = 0x9c,
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
			.IntelMnemonic = "vfnmadd132ps",
			.GasMnemonic = "vfnmadd132ps",
			.Description = "vfnmadd132ps ymm{k}{z}, ymm, ymm",
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
						.Value = 0x9c,
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
			.IntelMnemonic = "vfnmadd132ps",
			.GasMnemonic = "vfnmadd132ps",
			.Description = "vfnmadd132ps zmm{k}{z}, zmm, m512/m32bcst",
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
						.Value = 0x9c,
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
			.IntelMnemonic = "vfnmadd132ps",
			.GasMnemonic = "vfnmadd132ps",
			.Description = "vfnmadd132ps xmm, xmm, xmm",
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
						.Value = 0x9c,
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
			.IntelMnemonic = "vfnmadd132ps",
			.GasMnemonic = "vfnmadd132ps",
			.Description = "vfnmadd132ps xmm, xmm, m128",
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
						.Value = 0x9c,
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
			.IntelMnemonic = "vfnmadd132ps",
			.GasMnemonic = "vfnmadd132ps",
			.Description = "vfnmadd132ps ymm, ymm, ymm",
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
						.Value = 0x9c,
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
			.IntelMnemonic = "vfnmadd132ps",
			.GasMnemonic = "vfnmadd132ps",
			.Description = "vfnmadd132ps ymm, ymm, m256",
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
						.Value = 0x9c,
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
			.IntelMnemonic = "vfnmadd132ps",
			.GasMnemonic = "vfnmadd132ps",
			.Description = "vfnmadd132ps zmm{k}{z}, zmm, zmm, {er}",
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
						.Value = 0x9c,
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
			.IntelMnemonic = "vfnmadd132sd",
			.GasMnemonic = "vfnmadd132sd",
			.Description = "vfnmadd132sd xmm{k}{z}, xmm, m64",
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
						.Value = 0x9d,
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
			.IntelMnemonic = "vfnmadd132sd",
			.GasMnemonic = "vfnmadd132sd",
			.Description = "vfnmadd132sd xmm, xmm, xmm",
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
						.Value = 0x9d,
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
			.IntelMnemonic = "vfnmadd132sd",
			.GasMnemonic = "vfnmadd132sd",
			.Description = "vfnmadd132sd xmm, xmm, m64",
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
						.Value = 0x9d,
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
			.IntelMnemonic = "vfnmadd132sd",
			.GasMnemonic = "vfnmadd132sd",
			.Description = "vfnmadd132sd xmm{k}{z}, xmm, xmm, {er}",
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
						.Value = 0x9d,
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
			.IntelMnemonic = "vfnmadd132ss",
			.GasMnemonic = "vfnmadd132ss",
			.Description = "vfnmadd132ss xmm{k}{z}, xmm, m32",
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
						.Value = 0x9d,
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
			.IntelMnemonic = "vfnmadd132ss",
			.GasMnemonic = "vfnmadd132ss",
			.Description = "vfnmadd132ss xmm, xmm, xmm",
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
						.Value = 0x9d,
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
			.IntelMnemonic = "vfnmadd132ss",
			.GasMnemonic = "vfnmadd132ss",
			.Description = "vfnmadd132ss xmm, xmm, m32",
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
						.Value = 0x9d,
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
			.IntelMnemonic = "vfnmadd132ss",
			.GasMnemonic = "vfnmadd132ss",
			.Description = "vfnmadd132ss xmm{k}{z}, xmm, xmm, {er}",
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
						.Value = 0x9d,
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
			.IntelMnemonic = "vfnmadd213pd",
			.GasMnemonic = "vfnmadd213pd",
			.Description = "vfnmadd213pd xmm{k}{z}, xmm, m128/m64bcst",
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
						.Value = 0xac,
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
			.IntelMnemonic = "vfnmadd213pd",
			.GasMnemonic = "vfnmadd213pd",
			.Description = "vfnmadd213pd xmm{k}{z}, xmm, xmm",
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
						.Value = 0xac,
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
			.IntelMnemonic = "vfnmadd213pd",
			.GasMnemonic = "vfnmadd213pd",
			.Description = "vfnmadd213pd ymm{k}{z}, ymm, m256/m64bcst",
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
						.Value = 0xac,
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
			.IntelMnemonic = "vfnmadd213pd",
			.GasMnemonic = "vfnmadd213pd",
			.Description = "vfnmadd213pd ymm{k}{z}, ymm, ymm",
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
						.Value = 0xac,
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
			.IntelMnemonic = "vfnmadd213pd",
			.GasMnemonic = "vfnmadd213pd",
			.Description = "vfnmadd213pd zmm{k}{z}, zmm, m512/m64bcst",
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
						.Value = 0xac,
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
			.IntelMnemonic = "vfnmadd213pd",
			.GasMnemonic = "vfnmadd213pd",
			.Description = "vfnmadd213pd xmm, xmm, xmm",
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
						.Value = 0xac,
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
			.IntelMnemonic = "vfnmadd213pd",
			.GasMnemonic = "vfnmadd213pd",
			.Description = "vfnmadd213pd xmm, xmm, m128",
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
						.Value = 0xac,
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
			.IntelMnemonic = "vfnmadd213pd",
			.GasMnemonic = "vfnmadd213pd",
			.Description = "vfnmadd213pd ymm, ymm, ymm",
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
						.Value = 0xac,
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
			.IntelMnemonic = "vfnmadd213pd",
			.GasMnemonic = "vfnmadd213pd",
			.Description = "vfnmadd213pd ymm, ymm, m256",
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
						.Value = 0xac,
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
			.IntelMnemonic = "vfnmadd213pd",
			.GasMnemonic = "vfnmadd213pd",
			.Description = "vfnmadd213pd zmm{k}{z}, zmm, zmm, {er}",
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
						.Value = 0xac,
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
			.IntelMnemonic = "vfnmadd213ps",
			.GasMnemonic = "vfnmadd213ps",
			.Description = "vfnmadd213ps xmm{k}{z}, xmm, m128/m32bcst",
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
						.Value = 0xac,
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
			.IntelMnemonic = "vfnmadd213ps",
			.GasMnemonic = "vfnmadd213ps",
			.Description = "vfnmadd213ps xmm{k}{z}, xmm, xmm",
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
						.Value = 0xac,
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
			.IntelMnemonic = "vfnmadd213ps",
			.GasMnemonic = "vfnmadd213ps",
			.Description = "vfnmadd213ps ymm{k}{z}, ymm, m256/m32bcst",
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
						.Value = 0xac,
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
			.IntelMnemonic = "vfnmadd213ps",
			.GasMnemonic = "vfnmadd213ps",
			.Description = "vfnmadd213ps ymm{k}{z}, ymm, ymm",
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
						.Value = 0xac,
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
			.IntelMnemonic = "vfnmadd213ps",
			.GasMnemonic = "vfnmadd213ps",
			.Description = "vfnmadd213ps zmm{k}{z}, zmm, m512/m32bcst",
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
						.Value = 0xac,
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
			.IntelMnemonic = "vfnmadd213ps",
			.GasMnemonic = "vfnmadd213ps",
			.Description = "vfnmadd213ps xmm, xmm, xmm",
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
						.Value = 0xac,
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
			.IntelMnemonic = "vfnmadd213ps",
			.GasMnemonic = "vfnmadd213ps",
			.Description = "vfnmadd213ps xmm, xmm, m128",
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
						.Value = 0xac,
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
			.IntelMnemonic = "vfnmadd213ps",
			.GasMnemonic = "vfnmadd213ps",
			.Description = "vfnmadd213ps ymm, ymm, ymm",
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
						.Value = 0xac,
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
			.IntelMnemonic = "vfnmadd213ps",
			.GasMnemonic = "vfnmadd213ps",
			.Description = "vfnmadd213ps ymm, ymm, m256",
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
						.Value = 0xac,
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
			.IntelMnemonic = "vfnmadd213ps",
			.GasMnemonic = "vfnmadd213ps",
			.Description = "vfnmadd213ps zmm{k}{z}, zmm, zmm, {er}",
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
						.Value = 0xac,
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
			.IntelMnemonic = "vfnmadd213sd",
			.GasMnemonic = "vfnmadd213sd",
			.Description = "vfnmadd213sd xmm{k}{z}, xmm, m64",
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
						.Value = 0xad,
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
			.IntelMnemonic = "vfnmadd213sd",
			.GasMnemonic = "vfnmadd213sd",
			.Description = "vfnmadd213sd xmm, xmm, xmm",
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
						.Value = 0xad,
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
			.IntelMnemonic = "vfnmadd213sd",
			.GasMnemonic = "vfnmadd213sd",
			.Description = "vfnmadd213sd xmm, xmm, m64",
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
						.Value = 0xad,
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
			.IntelMnemonic = "vfnmadd213sd",
			.GasMnemonic = "vfnmadd213sd",
			.Description = "vfnmadd213sd xmm{k}{z}, xmm, xmm, {er}",
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
						.Value = 0xad,
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
			.IntelMnemonic = "vfnmadd213ss",
			.GasMnemonic = "vfnmadd213ss",
			.Description = "vfnmadd213ss xmm{k}{z}, xmm, m32",
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
						.Value = 0xad,
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
			.IntelMnemonic = "vfnmadd213ss",
			.GasMnemonic = "vfnmadd213ss",
			.Description = "vfnmadd213ss xmm, xmm, xmm",
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
						.Value = 0xad,
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
			.IntelMnemonic = "vfnmadd213ss",
			.GasMnemonic = "vfnmadd213ss",
			.Description = "vfnmadd213ss xmm, xmm, m32",
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
						.Value = 0xad,
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
			.IntelMnemonic = "vfnmadd213ss",
			.GasMnemonic = "vfnmadd213ss",
			.Description = "vfnmadd213ss xmm{k}{z}, xmm, xmm, {er}",
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
						.Value = 0xad,
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
			.IntelMnemonic = "vfnmadd231pd",
			.GasMnemonic = "vfnmadd231pd",
			.Description = "vfnmadd231pd xmm{k}{z}, xmm, m128/m64bcst",
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
						.Value = 0xbc,
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
			.IntelMnemonic = "vfnmadd231pd",
			.GasMnemonic = "vfnmadd231pd",
			.Description = "vfnmadd231pd xmm{k}{z}, xmm, xmm",
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
						.Value = 0xbc,
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
			.IntelMnemonic = "vfnmadd231pd",
			.GasMnemonic = "vfnmadd231pd",
			.Description = "vfnmadd231pd ymm{k}{z}, ymm, m256/m64bcst",
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
						.Value = 0xbc,
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
			.IntelMnemonic = "vfnmadd231pd",
			.GasMnemonic = "vfnmadd231pd",
			.Description = "vfnmadd231pd ymm{k}{z}, ymm, ymm",
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
						.Value = 0xbc,
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
			.IntelMnemonic = "vfnmadd231pd",
			.GasMnemonic = "vfnmadd231pd",
			.Description = "vfnmadd231pd zmm{k}{z}, zmm, m512/m64bcst",
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
						.Value = 0xbc,
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
			.IntelMnemonic = "vfnmadd231pd",
			.GasMnemonic = "vfnmadd231pd",
			.Description = "vfnmadd231pd xmm, xmm, xmm",
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
						.Value = 0xbc,
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
			.IntelMnemonic = "vfnmadd231pd",
			.GasMnemonic = "vfnmadd231pd",
			.Description = "vfnmadd231pd xmm, xmm, m128",
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
						.Value = 0xbc,
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
			.IntelMnemonic = "vfnmadd231pd",
			.GasMnemonic = "vfnmadd231pd",
			.Description = "vfnmadd231pd ymm, ymm, ymm",
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
						.Value = 0xbc,
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
			.IntelMnemonic = "vfnmadd231pd",
			.GasMnemonic = "vfnmadd231pd",
			.Description = "vfnmadd231pd ymm, ymm, m256",
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
						.Value = 0xbc,
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
			.IntelMnemonic = "vfnmadd231pd",
			.GasMnemonic = "vfnmadd231pd",
			.Description = "vfnmadd231pd zmm{k}{z}, zmm, zmm, {er}",
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
						.Value = 0xbc,
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
			.IntelMnemonic = "vfnmadd231ps",
			.GasMnemonic = "vfnmadd231ps",
			.Description = "vfnmadd231ps xmm{k}{z}, xmm, m128/m32bcst",
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
						.Value = 0xbc,
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
			.IntelMnemonic = "vfnmadd231ps",
			.GasMnemonic = "vfnmadd231ps",
			.Description = "vfnmadd231ps xmm{k}{z}, xmm, xmm",
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
						.Value = 0xbc,
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
			.IntelMnemonic = "vfnmadd231ps",
			.GasMnemonic = "vfnmadd231ps",
			.Description = "vfnmadd231ps ymm{k}{z}, ymm, m256/m32bcst",
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
						.Value = 0xbc,
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
			.IntelMnemonic = "vfnmadd231ps",
			.GasMnemonic = "vfnmadd231ps",
			.Description = "vfnmadd231ps ymm{k}{z}, ymm, ymm",
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
						.Value = 0xbc,
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
			.IntelMnemonic = "vfnmadd231ps",
			.GasMnemonic = "vfnmadd231ps",
			.Description = "vfnmadd231ps zmm{k}{z}, zmm, m512/m32bcst",
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
						.Value = 0xbc,
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
			.IntelMnemonic = "vfnmadd231ps",
			.GasMnemonic = "vfnmadd231ps",
			.Description = "vfnmadd231ps xmm, xmm, xmm",
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
						.Value = 0xbc,
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
			.IntelMnemonic = "vfnmadd231ps",
			.GasMnemonic = "vfnmadd231ps",
			.Description = "vfnmadd231ps xmm, xmm, m128",
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
						.Value = 0xbc,
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
			.IntelMnemonic = "vfnmadd231ps",
			.GasMnemonic = "vfnmadd231ps",
			.Description = "vfnmadd231ps ymm, ymm, ymm",
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
						.Value = 0xbc,
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
			.IntelMnemonic = "vfnmadd231ps",
			.GasMnemonic = "vfnmadd231ps",
			.Description = "vfnmadd231ps ymm, ymm, m256",
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
						.Value = 0xbc,
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
			.IntelMnemonic = "vfnmadd231ps",
			.GasMnemonic = "vfnmadd231ps",
			.Description = "vfnmadd231ps zmm{k}{z}, zmm, zmm, {er}",
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
						.Value = 0xbc,
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
			.IntelMnemonic = "vfnmadd231sd",
			.GasMnemonic = "vfnmadd231sd",
			.Description = "vfnmadd231sd xmm{k}{z}, xmm, m64",
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
						.Value = 0xbd,
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
			.IntelMnemonic = "vfnmadd231sd",
			.GasMnemonic = "vfnmadd231sd",
			.Description = "vfnmadd231sd xmm, xmm, xmm",
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
						.Value = 0xbd,
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
			.IntelMnemonic = "vfnmadd231sd",
			.GasMnemonic = "vfnmadd231sd",
			.Description = "vfnmadd231sd xmm, xmm, m64",
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
						.Value = 0xbd,
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
			.IntelMnemonic = "vfnmadd231sd",
			.GasMnemonic = "vfnmadd231sd",
			.Description = "vfnmadd231sd xmm{k}{z}, xmm, xmm, {er}",
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
						.Value = 0xbd,
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
			.IntelMnemonic = "vfnmadd231ss",
			.GasMnemonic = "vfnmadd231ss",
			.Description = "vfnmadd231ss xmm{k}{z}, xmm, m32",
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
						.Value = 0xbd,
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
			.IntelMnemonic = "vfnmadd231ss",
			.GasMnemonic = "vfnmadd231ss",
			.Description = "vfnmadd231ss xmm, xmm, xmm",
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
						.Value = 0xbd,
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
			.IntelMnemonic = "vfnmadd231ss",
			.GasMnemonic = "vfnmadd231ss",
			.Description = "vfnmadd231ss xmm, xmm, m32",
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
						.Value = 0xbd,
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
			.IntelMnemonic = "vfnmadd231ss",
			.GasMnemonic = "vfnmadd231ss",
			.Description = "vfnmadd231ss xmm{k}{z}, xmm, xmm, {er}",
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
						.Value = 0xbd,
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
			.IntelMnemonic = "vfnmaddpd",
			.GasMnemonic = "vfnmaddpd",
			.Description = "vfnmaddpd xmm, xmm, xmm, xmm",
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
						.Value = 0x79,
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
						.Value = 0x79,
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
			.IntelMnemonic = "vfnmaddpd",
			.GasMnemonic = "vfnmaddpd",
			.Description = "vfnmaddpd xmm, xmm, xmm, m128",
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
						.Value = 0x79,
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
			.IntelMnemonic = "vfnmaddpd",
			.GasMnemonic = "vfnmaddpd",
			.Description = "vfnmaddpd xmm, xmm, m128, xmm",
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
						.Value = 0x79,
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
			.IntelMnemonic = "vfnmaddpd",
			.GasMnemonic = "vfnmaddpd",
			.Description = "vfnmaddpd ymm, ymm, ymm, ymm",
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
						.Value = 0x79,
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
						.Value = 0x79,
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
			.IntelMnemonic = "vfnmaddpd",
			.GasMnemonic = "vfnmaddpd",
			.Description = "vfnmaddpd ymm, ymm, ymm, m256",
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
						.Value = 0x79,
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
			.IntelMnemonic = "vfnmaddpd",
			.GasMnemonic = "vfnmaddpd",
			.Description = "vfnmaddpd ymm, ymm, m256, ymm",
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
						.Value = 0x79,
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
			.IntelMnemonic = "vfnmaddps",
			.GasMnemonic = "vfnmaddps",
			.Description = "vfnmaddps xmm, xmm, xmm, xmm",
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
						.Value = 0x78,
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
						.Value = 0x78,
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
			.IntelMnemonic = "vfnmaddps",
			.GasMnemonic = "vfnmaddps",
			.Description = "vfnmaddps xmm, xmm, xmm, m128",
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
						.Value = 0x78,
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
			.IntelMnemonic = "vfnmaddps",
			.GasMnemonic = "vfnmaddps",
			.Description = "vfnmaddps xmm, xmm, m128, xmm",
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
						.Value = 0x78,
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
			.IntelMnemonic = "vfnmaddps",
			.GasMnemonic = "vfnmaddps",
			.Description = "vfnmaddps ymm, ymm, ymm, ymm",
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
						.Value = 0x78,
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
						.Value = 0x78,
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
			.IntelMnemonic = "vfnmaddps",
			.GasMnemonic = "vfnmaddps",
			.Description = "vfnmaddps ymm, ymm, ymm, m256",
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
						.Value = 0x78,
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
			.IntelMnemonic = "vfnmaddps",
			.GasMnemonic = "vfnmaddps",
			.Description = "vfnmaddps ymm, ymm, m256, ymm",
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
						.Value = 0x78,
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
			.IntelMnemonic = "vfnmaddsd",
			.GasMnemonic = "vfnmaddsd",
			.Description = "vfnmaddsd xmm, xmm, xmm, xmm",
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
						.Value = 0x7b,
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
						.Value = 0x7b,
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
			.IntelMnemonic = "vfnmaddsd",
			.GasMnemonic = "vfnmaddsd",
			.Description = "vfnmaddsd xmm, xmm, xmm, m64",
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
						.Value = 0x7b,
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
			.IntelMnemonic = "vfnmaddsd",
			.GasMnemonic = "vfnmaddsd",
			.Description = "vfnmaddsd xmm, xmm, m64, xmm",
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
						.Value = 0x7b,
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
			.IntelMnemonic = "vfnmaddss",
			.GasMnemonic = "vfnmaddss",
			.Description = "vfnmaddss xmm, xmm, xmm, xmm",
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
						.Value = 0x7a,
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
						.Value = 0x7a,
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
			.IntelMnemonic = "vfnmaddss",
			.GasMnemonic = "vfnmaddss",
			.Description = "vfnmaddss xmm, xmm, xmm, m32",
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
						.Value = 0x7a,
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
			.IntelMnemonic = "vfnmaddss",
			.GasMnemonic = "vfnmaddss",
			.Description = "vfnmaddss xmm, xmm, m32, xmm",
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
						.Value = 0x7a,
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
			.IntelMnemonic = "vfnmsub132pd",
			.GasMnemonic = "vfnmsub132pd",
			.Description = "vfnmsub132pd xmm{k}{z}, xmm, m128/m64bcst",
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
						.Value = 0x9e,
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
			.IntelMnemonic = "vfnmsub132pd",
			.GasMnemonic = "vfnmsub132pd",
			.Description = "vfnmsub132pd xmm{k}{z}, xmm, xmm",
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
						.Value = 0x9e,
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
			.IntelMnemonic = "vfnmsub132pd",
			.GasMnemonic = "vfnmsub132pd",
			.Description = "vfnmsub132pd ymm{k}{z}, ymm, m256/m64bcst",
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
						.Value = 0x9e,
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
			.IntelMnemonic = "vfnmsub132pd",
			.GasMnemonic = "vfnmsub132pd",
			.Description = "vfnmsub132pd ymm{k}{z}, ymm, ymm",
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
						.Value = 0x9e,
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
			.IntelMnemonic = "vfnmsub132pd",
			.GasMnemonic = "vfnmsub132pd",
			.Description = "vfnmsub132pd zmm{k}{z}, zmm, m512/m64bcst",
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
						.Value = 0x9e,
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
			.IntelMnemonic = "vfnmsub132pd",
			.GasMnemonic = "vfnmsub132pd",
			.Description = "vfnmsub132pd xmm, xmm, xmm",
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
						.Value = 0x9e,
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
			.IntelMnemonic = "vfnmsub132pd",
			.GasMnemonic = "vfnmsub132pd",
			.Description = "vfnmsub132pd xmm, xmm, m128",
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
						.Value = 0x9e,
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
			.IntelMnemonic = "vfnmsub132pd",
			.GasMnemonic = "vfnmsub132pd",
			.Description = "vfnmsub132pd ymm, ymm, ymm",
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
						.Value = 0x9e,
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
			.IntelMnemonic = "vfnmsub132pd",
			.GasMnemonic = "vfnmsub132pd",
			.Description = "vfnmsub132pd ymm, ymm, m256",
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
						.Value = 0x9e,
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
			.IntelMnemonic = "vfnmsub132pd",
			.GasMnemonic = "vfnmsub132pd",
			.Description = "vfnmsub132pd zmm{k}{z}, zmm, zmm, {er}",
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
						.Value = 0x9e,
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
			.IntelMnemonic = "vfnmsub132ps",
			.GasMnemonic = "vfnmsub132ps",
			.Description = "vfnmsub132ps xmm{k}{z}, xmm, m128/m32bcst",
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
						.Value = 0x9e,
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
			.IntelMnemonic = "vfnmsub132ps",
			.GasMnemonic = "vfnmsub132ps",
			.Description = "vfnmsub132ps xmm{k}{z}, xmm, xmm",
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
						.Value = 0x9e,
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
			.IntelMnemonic = "vfnmsub132ps",
			.GasMnemonic = "vfnmsub132ps",
			.Description = "vfnmsub132ps ymm{k}{z}, ymm, m256/m32bcst",
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
						.Value = 0x9e,
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
			.IntelMnemonic = "vfnmsub132ps",
			.GasMnemonic = "vfnmsub132ps",
			.Description = "vfnmsub132ps ymm{k}{z}, ymm, ymm",
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
						.Value = 0x9e,
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
			.IntelMnemonic = "vfnmsub132ps",
			.GasMnemonic = "vfnmsub132ps",
			.Description = "vfnmsub132ps zmm{k}{z}, zmm, m512/m32bcst",
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
						.Value = 0x9e,
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
			.IntelMnemonic = "vfnmsub132ps",
			.GasMnemonic = "vfnmsub132ps",
			.Description = "vfnmsub132ps xmm, xmm, xmm",
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
						.Value = 0x9e,
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
			.IntelMnemonic = "vfnmsub132ps",
			.GasMnemonic = "vfnmsub132ps",
			.Description = "vfnmsub132ps xmm, xmm, m128",
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
						.Value = 0x9e,
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
			.IntelMnemonic = "vfnmsub132ps",
			.GasMnemonic = "vfnmsub132ps",
			.Description = "vfnmsub132ps ymm, ymm, ymm",
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
						.Value = 0x9e,
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
			.IntelMnemonic = "vfnmsub132ps",
			.GasMnemonic = "vfnmsub132ps",
			.Description = "vfnmsub132ps ymm, ymm, m256",
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
						.Value = 0x9e,
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
			.IntelMnemonic = "vfnmsub132ps",
			.GasMnemonic = "vfnmsub132ps",
			.Description = "vfnmsub132ps zmm{k}{z}, zmm, zmm, {er}",
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
						.Value = 0x9e,
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
			.IntelMnemonic = "vfnmsub132sd",
			.GasMnemonic = "vfnmsub132sd",
			.Description = "vfnmsub132sd xmm{k}{z}, xmm, m64",
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
						.Value = 0x9f,
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
			.IntelMnemonic = "vfnmsub132sd",
			.GasMnemonic = "vfnmsub132sd",
			.Description = "vfnmsub132sd xmm, xmm, xmm",
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
						.Value = 0x9f,
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
			.IntelMnemonic = "vfnmsub132sd",
			.GasMnemonic = "vfnmsub132sd",
			.Description = "vfnmsub132sd xmm, xmm, m64",
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
						.Value = 0x9f,
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
			.IntelMnemonic = "vfnmsub132sd",
			.GasMnemonic = "vfnmsub132sd",
			.Description = "vfnmsub132sd xmm{k}{z}, xmm, xmm, {er}",
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
						.Value = 0x9f,
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
			.IntelMnemonic = "vfnmsub132ss",
			.GasMnemonic = "vfnmsub132ss",
			.Description = "vfnmsub132ss xmm{k}{z}, xmm, m32",
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
						.Value = 0x9f,
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
			.IntelMnemonic = "vfnmsub132ss",
			.GasMnemonic = "vfnmsub132ss",
			.Description = "vfnmsub132ss xmm, xmm, xmm",
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
						.Value = 0x9f,
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
			.IntelMnemonic = "vfnmsub132ss",
			.GasMnemonic = "vfnmsub132ss",
			.Description = "vfnmsub132ss xmm, xmm, m32",
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
						.Value = 0x9f,
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
			.IntelMnemonic = "vfnmsub132ss",
			.GasMnemonic = "vfnmsub132ss",
			.Description = "vfnmsub132ss xmm{k}{z}, xmm, xmm, {er}",
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
						.Value = 0x9f,
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
			.IntelMnemonic = "vfnmsub213pd",
			.GasMnemonic = "vfnmsub213pd",
			.Description = "vfnmsub213pd xmm{k}{z}, xmm, m128/m64bcst",
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
						.Value = 0xae,
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
			.IntelMnemonic = "vfnmsub213pd",
			.GasMnemonic = "vfnmsub213pd",
			.Description = "vfnmsub213pd xmm{k}{z}, xmm, xmm",
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
						.Value = 0xae,
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
			.IntelMnemonic = "vfnmsub213pd",
			.GasMnemonic = "vfnmsub213pd",
			.Description = "vfnmsub213pd ymm{k}{z}, ymm, m256/m64bcst",
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
						.Value = 0xae,
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
			.IntelMnemonic = "vfnmsub213pd",
			.GasMnemonic = "vfnmsub213pd",
			.Description = "vfnmsub213pd ymm{k}{z}, ymm, ymm",
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
						.Value = 0xae,
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
			.IntelMnemonic = "vfnmsub213pd",
			.GasMnemonic = "vfnmsub213pd",
			.Description = "vfnmsub213pd zmm{k}{z}, zmm, m512/m64bcst",
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
						.Value = 0xae,
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
			.IntelMnemonic = "vfnmsub213pd",
			.GasMnemonic = "vfnmsub213pd",
			.Description = "vfnmsub213pd xmm, xmm, xmm",
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
						.Value = 0xae,
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
			.IntelMnemonic = "vfnmsub213pd",
			.GasMnemonic = "vfnmsub213pd",
			.Description = "vfnmsub213pd xmm, xmm, m128",
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
						.Value = 0xae,
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
			.IntelMnemonic = "vfnmsub213pd",
			.GasMnemonic = "vfnmsub213pd",
			.Description = "vfnmsub213pd ymm, ymm, ymm",
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
						.Value = 0xae,
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
			.IntelMnemonic = "vfnmsub213pd",
			.GasMnemonic = "vfnmsub213pd",
			.Description = "vfnmsub213pd ymm, ymm, m256",
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
						.Value = 0xae,
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
			.IntelMnemonic = "vfnmsub213pd",
			.GasMnemonic = "vfnmsub213pd",
			.Description = "vfnmsub213pd zmm{k}{z}, zmm, zmm, {er}",
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
						.Value = 0xae,
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
			.IntelMnemonic = "vfnmsub213ps",
			.GasMnemonic = "vfnmsub213ps",
			.Description = "vfnmsub213ps xmm{k}{z}, xmm, m128/m32bcst",
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
						.Value = 0xae,
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
			.IntelMnemonic = "vfnmsub213ps",
			.GasMnemonic = "vfnmsub213ps",
			.Description = "vfnmsub213ps xmm{k}{z}, xmm, xmm",
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
						.Value = 0xae,
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
			.IntelMnemonic = "vfnmsub213ps",
			.GasMnemonic = "vfnmsub213ps",
			.Description = "vfnmsub213ps ymm{k}{z}, ymm, m256/m32bcst",
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
						.Value = 0xae,
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
			.IntelMnemonic = "vfnmsub213ps",
			.GasMnemonic = "vfnmsub213ps",
			.Description = "vfnmsub213ps ymm{k}{z}, ymm, ymm",
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
						.Value = 0xae,
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
			.IntelMnemonic = "vfnmsub213ps",
			.GasMnemonic = "vfnmsub213ps",
			.Description = "vfnmsub213ps zmm{k}{z}, zmm, m512/m32bcst",
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
						.Value = 0xae,
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
			.IntelMnemonic = "vfnmsub213ps",
			.GasMnemonic = "vfnmsub213ps",
			.Description = "vfnmsub213ps xmm, xmm, xmm",
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
						.Value = 0xae,
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
			.IntelMnemonic = "vfnmsub213ps",
			.GasMnemonic = "vfnmsub213ps",
			.Description = "vfnmsub213ps xmm, xmm, m128",
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
						.Value = 0xae,
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
			.IntelMnemonic = "vfnmsub213ps",
			.GasMnemonic = "vfnmsub213ps",
			.Description = "vfnmsub213ps ymm, ymm, ymm",
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
						.Value = 0xae,
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
			.IntelMnemonic = "vfnmsub213ps",
			.GasMnemonic = "vfnmsub213ps",
			.Description = "vfnmsub213ps ymm, ymm, m256",
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
						.Value = 0xae,
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
			.IntelMnemonic = "vfnmsub213ps",
			.GasMnemonic = "vfnmsub213ps",
			.Description = "vfnmsub213ps zmm{k}{z}, zmm, zmm, {er}",
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
						.Value = 0xae,
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
			.IntelMnemonic = "vfnmsub213sd",
			.GasMnemonic = "vfnmsub213sd",
			.Description = "vfnmsub213sd xmm{k}{z}, xmm, m64",
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
						.Value = 0xaf,
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
			.IntelMnemonic = "vfnmsub213sd",
			.GasMnemonic = "vfnmsub213sd",
			.Description = "vfnmsub213sd xmm, xmm, xmm",
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
						.Value = 0xaf,
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
			.IntelMnemonic = "vfnmsub213sd",
			.GasMnemonic = "vfnmsub213sd",
			.Description = "vfnmsub213sd xmm, xmm, m64",
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
						.Value = 0xaf,
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
			.IntelMnemonic = "vfnmsub213sd",
			.GasMnemonic = "vfnmsub213sd",
			.Description = "vfnmsub213sd xmm{k}{z}, xmm, xmm, {er}",
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
						.Value = 0xaf,
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
			.IntelMnemonic = "vfnmsub213ss",
			.GasMnemonic = "vfnmsub213ss",
			.Description = "vfnmsub213ss xmm{k}{z}, xmm, m32",
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
						.Value = 0xaf,
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
			.IntelMnemonic = "vfnmsub213ss",
			.GasMnemonic = "vfnmsub213ss",
			.Description = "vfnmsub213ss xmm, xmm, xmm",
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
						.Value = 0xaf,
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
			.IntelMnemonic = "vfnmsub213ss",
			.GasMnemonic = "vfnmsub213ss",
			.Description = "vfnmsub213ss xmm, xmm, m32",
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
						.Value = 0xaf,
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
			.IntelMnemonic = "vfnmsub213ss",
			.GasMnemonic = "vfnmsub213ss",
			.Description = "vfnmsub213ss xmm{k}{z}, xmm, xmm, {er}",
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
						.Value = 0xaf,
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
			.IntelMnemonic = "vfnmsub231pd",
			.GasMnemonic = "vfnmsub231pd",
			.Description = "vfnmsub231pd xmm{k}{z}, xmm, m128/m64bcst",
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
						.Value = 0xbe,
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
			.IntelMnemonic = "vfnmsub231pd",
			.GasMnemonic = "vfnmsub231pd",
			.Description = "vfnmsub231pd xmm{k}{z}, xmm, xmm",
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
			.IntelMnemonic = "vfnmsub231pd",
			.GasMnemonic = "vfnmsub231pd",
			.Description = "vfnmsub231pd ymm{k}{z}, ymm, m256/m64bcst",
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
						.Value = 0xbe,
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
			.IntelMnemonic = "vfnmsub231pd",
			.GasMnemonic = "vfnmsub231pd",
			.Description = "vfnmsub231pd ymm{k}{z}, ymm, ymm",
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
			.IntelMnemonic = "vfnmsub231pd",
			.GasMnemonic = "vfnmsub231pd",
			.Description = "vfnmsub231pd zmm{k}{z}, zmm, m512/m64bcst",
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
						.Value = 0xbe,
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
			.IntelMnemonic = "vfnmsub231pd",
			.GasMnemonic = "vfnmsub231pd",
			.Description = "vfnmsub231pd xmm, xmm, xmm",
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
			.IntelMnemonic = "vfnmsub231pd",
			.GasMnemonic = "vfnmsub231pd",
			.Description = "vfnmsub231pd xmm, xmm, m128",
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
			.IntelMnemonic = "vfnmsub231pd",
			.GasMnemonic = "vfnmsub231pd",
			.Description = "vfnmsub231pd ymm, ymm, ymm",
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
			.IntelMnemonic = "vfnmsub231pd",
			.GasMnemonic = "vfnmsub231pd",
			.Description = "vfnmsub231pd ymm, ymm, m256",
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
			.IntelMnemonic = "vfnmsub231pd",
			.GasMnemonic = "vfnmsub231pd",
			.Description = "vfnmsub231pd zmm{k}{z}, zmm, zmm, {er}",
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

};
}
