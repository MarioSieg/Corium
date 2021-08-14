// File: Asm_x86_64_Jitdb27.cpp
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
	NOX_NEVER_INLINE NOX_COLD auto GetVariationTable_27(std::pmr::monotonic_buffer_resource& allocator, std::pmr::vector<InstructionVariationPool>& out) -> void
	{
		std::pmr::vector<InstructionVariation> instruction {&allocator};
		instruction =
		{
			InstructionVariation
			{
				.IntelMnemonic = "vpblendmd",
				.GasMnemonic = "vpblendmd",
				.Description = "vpblendmd xmm{k}{z}, xmm, m128/m32bcst",
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
							.Value = 0x64,
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
				.IntelMnemonic = "vpblendmd",
				.GasMnemonic = "vpblendmd",
				.Description = "vpblendmd xmm{k}{z}, xmm, xmm",
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
							.Value = 0x64,
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
				.IntelMnemonic = "vpblendmd",
				.GasMnemonic = "vpblendmd",
				.Description = "vpblendmd ymm{k}{z}, ymm, m256/m32bcst",
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
							.Value = 0x64,
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
				.IntelMnemonic = "vpblendmd",
				.GasMnemonic = "vpblendmd",
				.Description = "vpblendmd ymm{k}{z}, ymm, ymm",
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
							.Value = 0x64,
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
				.IntelMnemonic = "vpblendmd",
				.GasMnemonic = "vpblendmd",
				.Description = "vpblendmd zmm{k}{z}, zmm, m512/m32bcst",
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
							.Value = 0x64,
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
				.IntelMnemonic = "vpblendmd",
				.GasMnemonic = "vpblendmd",
				.Description = "vpblendmd zmm{k}{z}, zmm, zmm",
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
							.Value = 0x64,
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
				.IntelMnemonic = "vpblendmq",
				.GasMnemonic = "vpblendmq",
				.Description = "vpblendmq xmm{k}{z}, xmm, m128/m64bcst",
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
							.Value = 0x64,
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
				.IntelMnemonic = "vpblendmq",
				.GasMnemonic = "vpblendmq",
				.Description = "vpblendmq xmm{k}{z}, xmm, xmm",
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
							.Value = 0x64,
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
				.IntelMnemonic = "vpblendmq",
				.GasMnemonic = "vpblendmq",
				.Description = "vpblendmq ymm{k}{z}, ymm, m256/m64bcst",
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
							.Value = 0x64,
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
				.IntelMnemonic = "vpblendmq",
				.GasMnemonic = "vpblendmq",
				.Description = "vpblendmq ymm{k}{z}, ymm, ymm",
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
							.Value = 0x64,
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
				.IntelMnemonic = "vpblendmq",
				.GasMnemonic = "vpblendmq",
				.Description = "vpblendmq zmm{k}{z}, zmm, m512/m64bcst",
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
							.Value = 0x64,
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
				.IntelMnemonic = "vpblendmq",
				.GasMnemonic = "vpblendmq",
				.Description = "vpblendmq zmm{k}{z}, zmm, zmm",
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
							.Value = 0x64,
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
				.IntelMnemonic = "vpblendmw",
				.GasMnemonic = "vpblendmw",
				.Description = "vpblendmw xmm{k}{z}, xmm, xmm",
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
							.Value = 0x66,
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
				.IntelMnemonic = "vpblendmw",
				.GasMnemonic = "vpblendmw",
				.Description = "vpblendmw xmm{k}{z}, xmm, m128",
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
							.Value = 0x66,
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
				.IntelMnemonic = "vpblendmw",
				.GasMnemonic = "vpblendmw",
				.Description = "vpblendmw ymm{k}{z}, ymm, ymm",
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
							.Value = 0x66,
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
				.IntelMnemonic = "vpblendmw",
				.GasMnemonic = "vpblendmw",
				.Description = "vpblendmw ymm{k}{z}, ymm, m256",
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
							.Value = 0x66,
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
				.IntelMnemonic = "vpblendmw",
				.GasMnemonic = "vpblendmw",
				.Description = "vpblendmw zmm{k}{z}, zmm, zmm",
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
							.Value = 0x66,
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
				.IntelMnemonic = "vpblendmw",
				.GasMnemonic = "vpblendmw",
				.Description = "vpblendmw zmm{k}{z}, zmm, m512",
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
							.Value = 0x66,
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
				.IntelMnemonic = "vpblendvb",
				.GasMnemonic = "vpblendvb",
				.Description = "vpblendvb xmm, xmm, xmm, xmm",
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
							.Value = 0x4c,
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
				.IntelMnemonic = "vpblendvb",
				.GasMnemonic = "vpblendvb",
				.Description = "vpblendvb xmm, xmm, m128, xmm",
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
							.Value = 0x4c,
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
				.IntelMnemonic = "vpblendvb",
				.GasMnemonic = "vpblendvb",
				.Description = "vpblendvb ymm, ymm, ymm, ymm",
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
							.B = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0x4c,
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
				.IntelMnemonic = "vpblendvb",
				.GasMnemonic = "vpblendvb",
				.Description = "vpblendvb ymm, ymm, m256, ymm",
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
							.X = {OperandType::M256},
							.B = {OperandType::M256},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0x4c,
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
				.IntelMnemonic = "vpblendw",
				.GasMnemonic = "vpblendw",
				.Description = "vpblendw xmm, xmm, xmm, imm8",
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
				.IntelMnemonic = "vpblendw",
				.GasMnemonic = "vpblendw",
				.Description = "vpblendw xmm, xmm, m128, imm8",
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
			InstructionVariation
			{
				.IntelMnemonic = "vpblendw",
				.GasMnemonic = "vpblendw",
				.Description = "vpblendw ymm, ymm, ymm, imm8",
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
							.B = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0xe,
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
				.IntelMnemonic = "vpblendw",
				.GasMnemonic = "vpblendw",
				.Description = "vpblendw ymm, ymm, m256, imm8",
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
							.X = {OperandType::M256},
							.B = {OperandType::M256},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0xe,
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
				.IntelMnemonic = "vpbroadcastb",
				.GasMnemonic = "vpbroadcastb",
				.Description = "vpbroadcastb xmm{k}{z}, r32",
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
							.Bb = {OperandType::R32},
							.X = {OperandType::R32},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::R32},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x7a,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R32},
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpbroadcastb",
				.GasMnemonic = "vpbroadcastb",
				.Description = "vpbroadcastb ymm{k}{z}, r32",
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
							.Bb = {OperandType::R32},
							.X = {OperandType::R32},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::R32},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x7a,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R32},
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpbroadcastb",
				.GasMnemonic = "vpbroadcastb",
				.Description = "vpbroadcastb zmm{k}{z}, r32",
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
							.Bb = {OperandType::R32},
							.X = {OperandType::R32},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::R32},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x7a,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R32},
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpbroadcastb",
				.GasMnemonic = "vpbroadcastb",
				.Description = "vpbroadcastb xmm{k}{z}, xmm",
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
							.Value = 0x78,
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
				.IntelMnemonic = "vpbroadcastb",
				.GasMnemonic = "vpbroadcastb",
				.Description = "vpbroadcastb ymm{k}{z}, xmm",
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
							.Value = 0x78,
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
				.IntelMnemonic = "vpbroadcastb",
				.GasMnemonic = "vpbroadcastb",
				.Description = "vpbroadcastb zmm{k}{z}, xmm",
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
							.Value = 0x78,
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
				.IntelMnemonic = "vpbroadcastb",
				.GasMnemonic = "vpbroadcastb",
				.Description = "vpbroadcastb xmm{k}{z}, m8",
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
							.Bb = {OperandType::M8},
							.X = {OperandType::M8},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::M8},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 1,
						},
						OpCode
						{
							.Value = 0x78,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M8},
							.Rm = {OperandType::M8},
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpbroadcastb",
				.GasMnemonic = "vpbroadcastb",
				.Description = "vpbroadcastb ymm{k}{z}, m8",
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
							.Bb = {OperandType::M8},
							.X = {OperandType::M8},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::M8},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 1,
						},
						OpCode
						{
							.Value = 0x78,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M8},
							.Rm = {OperandType::M8},
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpbroadcastb",
				.GasMnemonic = "vpbroadcastb",
				.Description = "vpbroadcastb zmm{k}{z}, m8",
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
							.Bb = {OperandType::M8},
							.X = {OperandType::M8},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::M8},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 1,
						},
						OpCode
						{
							.Value = 0x78,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M8},
							.Rm = {OperandType::M8},
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpbroadcastb",
				.GasMnemonic = "vpbroadcastb",
				.Description = "vpbroadcastb xmm, xmm",
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
							.Vvvv = {UINT64_C(0x0)},
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
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpbroadcastb",
				.GasMnemonic = "vpbroadcastb",
				.Description = "vpbroadcastb xmm, m8",
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
							.X = {OperandType::M8},
							.B = {OperandType::M8},
							.Vvvv = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x78,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M8},
							.Rm = {OperandType::M8},
							.Reg = {OperandType::Xmm},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpbroadcastb",
				.GasMnemonic = "vpbroadcastb",
				.Description = "vpbroadcastb ymm, xmm",
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
							.Value = 0x78,
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
				.IntelMnemonic = "vpbroadcastb",
				.GasMnemonic = "vpbroadcastb",
				.Description = "vpbroadcastb ymm, m8",
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
							.X = {OperandType::M8},
							.B = {OperandType::M8},
							.Vvvv = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x78,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M8},
							.Rm = {OperandType::M8},
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
				.IntelMnemonic = "vpbroadcastd",
				.GasMnemonic = "vpbroadcastd",
				.Description = "vpbroadcastd xmm{k}{z}, r32",
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
							.Bb = {OperandType::R32},
							.X = {OperandType::R32},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::R32},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x7c,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R32},
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpbroadcastd",
				.GasMnemonic = "vpbroadcastd",
				.Description = "vpbroadcastd ymm{k}{z}, r32",
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
							.Bb = {OperandType::R32},
							.X = {OperandType::R32},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::R32},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x7c,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R32},
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpbroadcastd",
				.GasMnemonic = "vpbroadcastd",
				.Description = "vpbroadcastd zmm{k}{z}, r32",
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
					IsaExtension::Avx512F,
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
							.Bb = {OperandType::R32},
							.X = {OperandType::R32},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::R32},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x7c,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R32},
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpbroadcastd",
				.GasMnemonic = "vpbroadcastd",
				.Description = "vpbroadcastd xmm{k}{z}, xmm",
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
							.Value = 0x58,
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
				.IntelMnemonic = "vpbroadcastd",
				.GasMnemonic = "vpbroadcastd",
				.Description = "vpbroadcastd ymm{k}{z}, xmm",
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
							.Value = 0x58,
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
				.IntelMnemonic = "vpbroadcastd",
				.GasMnemonic = "vpbroadcastd",
				.Description = "vpbroadcastd zmm{k}{z}, xmm",
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
							.Value = 0x58,
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
				.IntelMnemonic = "vpbroadcastd",
				.GasMnemonic = "vpbroadcastd",
				.Description = "vpbroadcastd xmm{k}{z}, m32",
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
							.Value = 0x58,
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
				.IntelMnemonic = "vpbroadcastd",
				.GasMnemonic = "vpbroadcastd",
				.Description = "vpbroadcastd ymm{k}{z}, m32",
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
							.Value = 0x58,
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
				.IntelMnemonic = "vpbroadcastd",
				.GasMnemonic = "vpbroadcastd",
				.Description = "vpbroadcastd zmm{k}{z}, m32",
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
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::ZmmKz},
							.Bb = {OperandType::M32},
							.X = {OperandType::M32},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::M32},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 4,
						},
						OpCode
						{
							.Value = 0x58,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M32},
							.Rm = {OperandType::M32},
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpbroadcastd",
				.GasMnemonic = "vpbroadcastd",
				.Description = "vpbroadcastd xmm, xmm",
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
							.Vvvv = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x58,
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
				.IntelMnemonic = "vpbroadcastd",
				.GasMnemonic = "vpbroadcastd",
				.Description = "vpbroadcastd xmm, m32",
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
							.X = {OperandType::M32},
							.B = {OperandType::M32},
							.Vvvv = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x58,
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
				.IntelMnemonic = "vpbroadcastd",
				.GasMnemonic = "vpbroadcastd",
				.Description = "vpbroadcastd ymm, xmm",
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
							.Value = 0x58,
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
				.IntelMnemonic = "vpbroadcastd",
				.GasMnemonic = "vpbroadcastd",
				.Description = "vpbroadcastd ymm, m32",
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
							.Value = 0x58,
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
				.IntelMnemonic = "vpbroadcastmb2q",
				.GasMnemonic = "vpbroadcastmb2q",
				.Description = "vpbroadcastmb2q xmm, k",
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
						.Type = OperandType::K,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
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
							.Pp = 0b10,
							.W = true,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::Xmm},
							.Bb = {OperandType::K},
							.X = {OperandType::K},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::K},
							.Aaa = {UINT64_C(0x0)},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x2a,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::K},
							.Reg = {OperandType::Xmm},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpbroadcastmb2q",
				.GasMnemonic = "vpbroadcastmb2q",
				.Description = "vpbroadcastmb2q ymm, k",
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
						.Type = OperandType::K,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
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
							.Pp = 0b10,
							.W = true,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::Ymm},
							.Bb = {OperandType::K},
							.X = {OperandType::K},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::K},
							.Aaa = {UINT64_C(0x0)},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x2a,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::K},
							.Reg = {OperandType::Ymm},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpbroadcastmb2q",
				.GasMnemonic = "vpbroadcastmb2q",
				.Description = "vpbroadcastmb2q zmm, k",
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
						.Type = OperandType::K,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
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
							.Pp = 0b10,
							.W = true,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::Zmm},
							.Bb = {OperandType::K},
							.X = {OperandType::K},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::K},
							.Aaa = {UINT64_C(0x0)},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x2a,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::K},
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
				.IntelMnemonic = "vpbroadcastmw2d",
				.GasMnemonic = "vpbroadcastmw2d",
				.Description = "vpbroadcastmw2d xmm, k",
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
						.Type = OperandType::K,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
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
							.Pp = 0b10,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::Xmm},
							.Bb = {OperandType::K},
							.X = {OperandType::K},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::K},
							.Aaa = {UINT64_C(0x0)},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x3a,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::K},
							.Reg = {OperandType::Xmm},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpbroadcastmw2d",
				.GasMnemonic = "vpbroadcastmw2d",
				.Description = "vpbroadcastmw2d ymm, k",
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
						.Type = OperandType::K,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
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
							.Pp = 0b10,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::Ymm},
							.Bb = {OperandType::K},
							.X = {OperandType::K},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::K},
							.Aaa = {UINT64_C(0x0)},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x3a,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::K},
							.Reg = {OperandType::Ymm},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpbroadcastmw2d",
				.GasMnemonic = "vpbroadcastmw2d",
				.Description = "vpbroadcastmw2d zmm, k",
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
						.Type = OperandType::K,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
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
							.Pp = 0b10,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::Zmm},
							.Bb = {OperandType::K},
							.X = {OperandType::K},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::K},
							.Aaa = {UINT64_C(0x0)},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x3a,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::K},
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
				.IntelMnemonic = "vpbroadcastq",
				.GasMnemonic = "vpbroadcastq",
				.Description = "vpbroadcastq xmm{k}{z}, r64",
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
							.Bb = {OperandType::R64},
							.X = {OperandType::R64},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::R64},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x7c,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R64},
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpbroadcastq",
				.GasMnemonic = "vpbroadcastq",
				.Description = "vpbroadcastq ymm{k}{z}, r64",
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
							.Bb = {OperandType::R64},
							.X = {OperandType::R64},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::R64},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x7c,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R64},
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpbroadcastq",
				.GasMnemonic = "vpbroadcastq",
				.Description = "vpbroadcastq zmm{k}{z}, r64",
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
					IsaExtension::Avx512F,
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
							.Bb = {OperandType::R64},
							.X = {OperandType::R64},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::R64},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x7c,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R64},
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpbroadcastq",
				.GasMnemonic = "vpbroadcastq",
				.Description = "vpbroadcastq xmm{k}{z}, xmm",
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
							.Value = 0x59,
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
				.IntelMnemonic = "vpbroadcastq",
				.GasMnemonic = "vpbroadcastq",
				.Description = "vpbroadcastq ymm{k}{z}, xmm",
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
							.W = true,
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
							.Value = 0x59,
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
				.IntelMnemonic = "vpbroadcastq",
				.GasMnemonic = "vpbroadcastq",
				.Description = "vpbroadcastq zmm{k}{z}, xmm",
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
							.W = true,
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
							.Value = 0x59,
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
				.IntelMnemonic = "vpbroadcastq",
				.GasMnemonic = "vpbroadcastq",
				.Description = "vpbroadcastq xmm{k}{z}, m64",
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
							.W = true,
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
							.Value = 0x59,
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
				.IntelMnemonic = "vpbroadcastq",
				.GasMnemonic = "vpbroadcastq",
				.Description = "vpbroadcastq ymm{k}{z}, m64",
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
							.W = true,
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
							.Value = 0x59,
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
				.IntelMnemonic = "vpbroadcastq",
				.GasMnemonic = "vpbroadcastq",
				.Description = "vpbroadcastq zmm{k}{z}, m64",
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
							.W = true,
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
							.Value = 0x59,
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
				.IntelMnemonic = "vpbroadcastq",
				.GasMnemonic = "vpbroadcastq",
				.Description = "vpbroadcastq xmm, xmm",
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
							.Vvvv = {UINT64_C(0x0)},
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
				.IntelMnemonic = "vpbroadcastq",
				.GasMnemonic = "vpbroadcastq",
				.Description = "vpbroadcastq xmm, m64",
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
							.X = {OperandType::M64},
							.B = {OperandType::M64},
							.Vvvv = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x59,
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
				.IntelMnemonic = "vpbroadcastq",
				.GasMnemonic = "vpbroadcastq",
				.Description = "vpbroadcastq ymm, xmm",
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
							.Value = 0x59,
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
				.IntelMnemonic = "vpbroadcastq",
				.GasMnemonic = "vpbroadcastq",
				.Description = "vpbroadcastq ymm, m64",
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
							.Value = 0x59,
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
				.IntelMnemonic = "vpbroadcastw",
				.GasMnemonic = "vpbroadcastw",
				.Description = "vpbroadcastw xmm{k}{z}, r32",
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
							.Bb = {OperandType::R32},
							.X = {OperandType::R32},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::R32},
							.Aaa = {OperandType::XmmKz},
							.Z = {OperandType::XmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x7b,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R32},
							.Reg = {OperandType::XmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpbroadcastw",
				.GasMnemonic = "vpbroadcastw",
				.Description = "vpbroadcastw ymm{k}{z}, r32",
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
							.Bb = {OperandType::R32},
							.X = {OperandType::R32},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::R32},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x7b,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R32},
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpbroadcastw",
				.GasMnemonic = "vpbroadcastw",
				.Description = "vpbroadcastw zmm{k}{z}, r32",
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
							.Bb = {OperandType::R32},
							.X = {OperandType::R32},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::R32},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x7b,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::R32},
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpbroadcastw",
				.GasMnemonic = "vpbroadcastw",
				.Description = "vpbroadcastw xmm{k}{z}, xmm",
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
							.Value = 0x79,
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
				.IntelMnemonic = "vpbroadcastw",
				.GasMnemonic = "vpbroadcastw",
				.Description = "vpbroadcastw ymm{k}{z}, xmm",
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
							.Value = 0x79,
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
				.IntelMnemonic = "vpbroadcastw",
				.GasMnemonic = "vpbroadcastw",
				.Description = "vpbroadcastw zmm{k}{z}, xmm",
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
							.Value = 0x79,
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
				.IntelMnemonic = "vpbroadcastw",
				.GasMnemonic = "vpbroadcastw",
				.Description = "vpbroadcastw xmm{k}{z}, m16",
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
							.Value = 0x79,
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
				.IntelMnemonic = "vpbroadcastw",
				.GasMnemonic = "vpbroadcastw",
				.Description = "vpbroadcastw ymm{k}{z}, m16",
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
							.Bb = {OperandType::M16},
							.X = {OperandType::M16},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::M16},
							.Aaa = {OperandType::YmmKz},
							.Z = {OperandType::YmmKz},
							.Disp8xN = 2,
						},
						OpCode
						{
							.Value = 0x79,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M16},
							.Rm = {OperandType::M16},
							.Reg = {OperandType::YmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpbroadcastw",
				.GasMnemonic = "vpbroadcastw",
				.Description = "vpbroadcastw zmm{k}{z}, m16",
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
							.Bb = {OperandType::M16},
							.X = {OperandType::M16},
							.Vvvv = {UINT64_C(0x0)},
							.V = {UINT64_C(0x0)},
							.B = {OperandType::M16},
							.Aaa = {OperandType::ZmmKz},
							.Z = {OperandType::ZmmKz},
							.Disp8xN = 2,
						},
						OpCode
						{
							.Value = 0x79,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M16},
							.Rm = {OperandType::M16},
							.Reg = {OperandType::ZmmKz},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpbroadcastw",
				.GasMnemonic = "vpbroadcastw",
				.Description = "vpbroadcastw xmm, xmm",
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
							.Vvvv = {UINT64_C(0x0)},
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
				.IntelMnemonic = "vpbroadcastw",
				.GasMnemonic = "vpbroadcastw",
				.Description = "vpbroadcastw xmm, m16",
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
							.X = {OperandType::M16},
							.B = {OperandType::M16},
							.Vvvv = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x79,
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
				.IntelMnemonic = "vpbroadcastw",
				.GasMnemonic = "vpbroadcastw",
				.Description = "vpbroadcastw ymm, xmm",
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
							.Value = 0x79,
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
				.IntelMnemonic = "vpbroadcastw",
				.GasMnemonic = "vpbroadcastw",
				.Description = "vpbroadcastw ymm, m16",
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
							.X = {OperandType::M16},
							.B = {OperandType::M16},
							.Vvvv = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0x79,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M16},
							.Rm = {OperandType::M16},
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
				.IntelMnemonic = "vpclmulqdq",
				.GasMnemonic = "vpclmulqdq",
				.Description = "vpclmulqdq xmm, xmm, xmm, imm8",
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
					IsaExtension::Pclmulqdq,
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
				.IntelMnemonic = "vpclmulqdq",
				.GasMnemonic = "vpclmulqdq",
				.Description = "vpclmulqdq xmm, xmm, m128, imm8",
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
					IsaExtension::Pclmulqdq,
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
				.IntelMnemonic = "vpcmov",
				.GasMnemonic = "vpcmov",
				.Description = "vpcmov xmm, xmm, xmm, xmm",
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
							.Value = 0xa2,
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
							.Type = VexPrefixType::Xop,
							.Mmmmm = 0b1000,
							.Pp = 0b0,
							.W = true,
							.L = false,
							.R = {OperandType::Xmm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
						},
						OpCode
						{
							.Value = 0xa2,
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
				.IntelMnemonic = "vpcmov",
				.GasMnemonic = "vpcmov",
				.Description = "vpcmov xmm, xmm, xmm, m128",
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
							.W = true,
							.L = false,
							.R = {OperandType::Xmm},
							.X = {OperandType::M128},
							.B = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
						},
						OpCode
						{
							.Value = 0xa2,
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
				.IntelMnemonic = "vpcmov",
				.GasMnemonic = "vpcmov",
				.Description = "vpcmov xmm, xmm, m128, xmm",
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
							.Value = 0xa2,
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
				.IntelMnemonic = "vpcmov",
				.GasMnemonic = "vpcmov",
				.Description = "vpcmov ymm, ymm, ymm, ymm",
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
							.L = true,
							.R = {OperandType::Ymm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0xa2,
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
							.Type = VexPrefixType::Xop,
							.Mmmmm = 0b1000,
							.Pp = 0b0,
							.W = true,
							.L = true,
							.R = {OperandType::Ymm},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0xa2,
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
				.IntelMnemonic = "vpcmov",
				.GasMnemonic = "vpcmov",
				.Description = "vpcmov ymm, ymm, ymm, m256",
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
							.W = true,
							.L = true,
							.R = {OperandType::Ymm},
							.X = {OperandType::M256},
							.B = {OperandType::M256},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0xa2,
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
				.IntelMnemonic = "vpcmov",
				.GasMnemonic = "vpcmov",
				.Description = "vpcmov ymm, ymm, m256, ymm",
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
							.L = true,
							.R = {OperandType::Ymm},
							.X = {OperandType::M256},
							.B = {OperandType::M256},
							.Vvvv = {OperandType::Ymm},
						},
						OpCode
						{
							.Value = 0xa2,
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
				.IntelMnemonic = "vpcmpb",
				.GasMnemonic = "vpcmpb",
				.Description = "vpcmpb k{k}, xmm, xmm, imm8",
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
							.Mm = 0b11,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x3f,
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
				.IntelMnemonic = "vpcmpb",
				.GasMnemonic = "vpcmpb",
				.Description = "vpcmpb k{k}, xmm, m128, imm8",
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
							.Mm = 0b11,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M128},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 16,
						},
						OpCode
						{
							.Value = 0x3f,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M128},
							.Rm = {OperandType::M128},
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
				.IntelMnemonic = "vpcmpb",
				.GasMnemonic = "vpcmpb",
				.Description = "vpcmpb k{k}, ymm, ymm, imm8",
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
							.Mm = 0b11,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Ymm},
							.X = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::Ymm},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x3f,
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
				.IntelMnemonic = "vpcmpb",
				.GasMnemonic = "vpcmpb",
				.Description = "vpcmpb k{k}, ymm, m256, imm8",
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
							.Mm = 0b11,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M256},
							.X = {OperandType::M256},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::M256},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0x3f,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256},
							.Rm = {OperandType::M256},
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
				.IntelMnemonic = "vpcmpb",
				.GasMnemonic = "vpcmpb",
				.Description = "vpcmpb k{k}, zmm, zmm, imm8",
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
							.Mm = 0b11,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Zmm},
							.X = {OperandType::Zmm},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::Zmm},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x3f,
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
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpb",
				.GasMnemonic = "vpcmpb",
				.Description = "vpcmpb k{k}, zmm, m512, imm8",
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
							.Mm = 0b11,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M512},
							.X = {OperandType::M512},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::M512},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 64,
						},
						OpCode
						{
							.Value = 0x3f,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M512},
							.Rm = {OperandType::M512},
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
				.IntelMnemonic = "vpcmpd",
				.GasMnemonic = "vpcmpd",
				.Description = "vpcmpd k{k}, xmm, m128/m32bcst, imm8",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M128M32Bcst},
							.X = {OperandType::M128M32Bcst},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M128M32Bcst},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 16,
						},
						OpCode
						{
							.Value = 0x1f,
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
				.IntelMnemonic = "vpcmpd",
				.GasMnemonic = "vpcmpd",
				.Description = "vpcmpd k{k}, xmm, xmm, imm8",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x1f,
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
				.IntelMnemonic = "vpcmpd",
				.GasMnemonic = "vpcmpd",
				.Description = "vpcmpd k{k}, ymm, m256/m32bcst, imm8",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M256M32Bcst},
							.X = {OperandType::M256M32Bcst},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::M256M32Bcst},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0x1f,
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
				.IntelMnemonic = "vpcmpd",
				.GasMnemonic = "vpcmpd",
				.Description = "vpcmpd k{k}, ymm, ymm, imm8",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Ymm},
							.X = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::Ymm},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x1f,
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
				.IntelMnemonic = "vpcmpd",
				.GasMnemonic = "vpcmpd",
				.Description = "vpcmpd k{k}, zmm, m512/m32bcst, imm8",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M512M32Bcst},
							.X = {OperandType::M512M32Bcst},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::M512M32Bcst},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 64,
						},
						OpCode
						{
							.Value = 0x1f,
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
				.IntelMnemonic = "vpcmpd",
				.GasMnemonic = "vpcmpd",
				.Description = "vpcmpd k{k}, zmm, zmm, imm8",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Zmm},
							.X = {OperandType::Zmm},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::Zmm},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x1f,
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
				.IntelMnemonic = "vpcmpeqb",
				.GasMnemonic = "vpcmpeqb",
				.Description = "vpcmpeqb k{k}, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
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
						.Type = OperandType::Xmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
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
							.Reg = {OperandType::Kk},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpeqb",
				.GasMnemonic = "vpcmpeqb",
				.Description = "vpcmpeqb k{k}, xmm, m128",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M128},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 16,
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
							.Reg = {OperandType::Kk},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpeqb",
				.GasMnemonic = "vpcmpeqb",
				.Description = "vpcmpeqb k{k}, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Ymm},
							.X = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::Ymm},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x74,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
							.Reg = {OperandType::Kk},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpeqb",
				.GasMnemonic = "vpcmpeqb",
				.Description = "vpcmpeqb k{k}, ymm, m256",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M256},
							.X = {OperandType::M256},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::M256},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0x74,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256},
							.Rm = {OperandType::M256},
							.Reg = {OperandType::Kk},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpeqb",
				.GasMnemonic = "vpcmpeqb",
				.Description = "vpcmpeqb k{k}, zmm, zmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Zmm},
							.X = {OperandType::Zmm},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::Zmm},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x74,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Zmm},
							.Reg = {OperandType::Kk},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpeqb",
				.GasMnemonic = "vpcmpeqb",
				.Description = "vpcmpeqb k{k}, zmm, m512",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M512},
							.X = {OperandType::M512},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::M512},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 64,
						},
						OpCode
						{
							.Value = 0x74,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M512},
							.Rm = {OperandType::M512},
							.Reg = {OperandType::Kk},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpeqb",
				.GasMnemonic = "vpcmpeqb",
				.Description = "vpcmpeqb xmm, xmm, xmm",
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
				.IntelMnemonic = "vpcmpeqb",
				.GasMnemonic = "vpcmpeqb",
				.Description = "vpcmpeqb xmm, xmm, m128",
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
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpeqb",
				.GasMnemonic = "vpcmpeqb",
				.Description = "vpcmpeqb ymm, ymm, ymm",
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
							.Value = 0x74,
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
				.IntelMnemonic = "vpcmpeqb",
				.GasMnemonic = "vpcmpeqb",
				.Description = "vpcmpeqb ymm, ymm, m256",
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
							.Value = 0x74,
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
				.IntelMnemonic = "vpcmpeqd",
				.GasMnemonic = "vpcmpeqd",
				.Description = "vpcmpeqd k{k}, xmm, m128/m32bcst",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M128M32Bcst},
							.X = {OperandType::M128M32Bcst},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M128M32Bcst},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 16,
						},
						OpCode
						{
							.Value = 0x76,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M128M32Bcst},
							.Rm = {OperandType::M128M32Bcst},
							.Reg = {OperandType::Kk},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpeqd",
				.GasMnemonic = "vpcmpeqd",
				.Description = "vpcmpeqd k{k}, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
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
						.Type = OperandType::Xmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
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
							.Reg = {OperandType::Kk},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpeqd",
				.GasMnemonic = "vpcmpeqd",
				.Description = "vpcmpeqd k{k}, ymm, m256/m32bcst",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M256M32Bcst},
							.X = {OperandType::M256M32Bcst},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::M256M32Bcst},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0x76,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256M32Bcst},
							.Rm = {OperandType::M256M32Bcst},
							.Reg = {OperandType::Kk},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpeqd",
				.GasMnemonic = "vpcmpeqd",
				.Description = "vpcmpeqd k{k}, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Ymm},
							.X = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::Ymm},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x76,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
							.Reg = {OperandType::Kk},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpeqd",
				.GasMnemonic = "vpcmpeqd",
				.Description = "vpcmpeqd k{k}, zmm, m512/m32bcst",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M512M32Bcst},
							.X = {OperandType::M512M32Bcst},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::M512M32Bcst},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 64,
						},
						OpCode
						{
							.Value = 0x76,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M512M32Bcst},
							.Rm = {OperandType::M512M32Bcst},
							.Reg = {OperandType::Kk},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpeqd",
				.GasMnemonic = "vpcmpeqd",
				.Description = "vpcmpeqd k{k}, zmm, zmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Zmm},
							.X = {OperandType::Zmm},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::Zmm},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x76,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Zmm},
							.Reg = {OperandType::Kk},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpeqd",
				.GasMnemonic = "vpcmpeqd",
				.Description = "vpcmpeqd xmm, xmm, xmm",
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
				.IntelMnemonic = "vpcmpeqd",
				.GasMnemonic = "vpcmpeqd",
				.Description = "vpcmpeqd xmm, xmm, m128",
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
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpeqd",
				.GasMnemonic = "vpcmpeqd",
				.Description = "vpcmpeqd ymm, ymm, ymm",
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
							.Value = 0x76,
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
				.IntelMnemonic = "vpcmpeqd",
				.GasMnemonic = "vpcmpeqd",
				.Description = "vpcmpeqd ymm, ymm, m256",
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
							.Value = 0x76,
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
				.IntelMnemonic = "vpcmpeqq",
				.GasMnemonic = "vpcmpeqq",
				.Description = "vpcmpeqq k{k}, xmm, m128/m64bcst",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M128M64Bcst},
							.X = {OperandType::M128M64Bcst},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M128M64Bcst},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 16,
						},
						OpCode
						{
							.Value = 0x29,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M128M64Bcst},
							.Rm = {OperandType::M128M64Bcst},
							.Reg = {OperandType::Kk},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpeqq",
				.GasMnemonic = "vpcmpeqq",
				.Description = "vpcmpeqq k{k}, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
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
						.Type = OperandType::Xmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::Kk},
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
							.Reg = {OperandType::Kk},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpeqq",
				.GasMnemonic = "vpcmpeqq",
				.Description = "vpcmpeqq k{k}, ymm, m256/m64bcst",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M256M64Bcst},
							.X = {OperandType::M256M64Bcst},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::M256M64Bcst},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0x29,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256M64Bcst},
							.Rm = {OperandType::M256M64Bcst},
							.Reg = {OperandType::Kk},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpeqq",
				.GasMnemonic = "vpcmpeqq",
				.Description = "vpcmpeqq k{k}, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Ymm},
							.X = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::Ymm},
							.Aaa = {OperandType::Kk},
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
							.Reg = {OperandType::Kk},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpeqq",
				.GasMnemonic = "vpcmpeqq",
				.Description = "vpcmpeqq k{k}, zmm, m512/m64bcst",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M512M64Bcst},
							.X = {OperandType::M512M64Bcst},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::M512M64Bcst},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 64,
						},
						OpCode
						{
							.Value = 0x29,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M512M64Bcst},
							.Rm = {OperandType::M512M64Bcst},
							.Reg = {OperandType::Kk},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpeqq",
				.GasMnemonic = "vpcmpeqq",
				.Description = "vpcmpeqq k{k}, zmm, zmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Zmm},
							.X = {OperandType::Zmm},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::Zmm},
							.Aaa = {OperandType::Kk},
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
							.Reg = {OperandType::Kk},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpeqq",
				.GasMnemonic = "vpcmpeqq",
				.Description = "vpcmpeqq xmm, xmm, xmm",
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
				.IntelMnemonic = "vpcmpeqq",
				.GasMnemonic = "vpcmpeqq",
				.Description = "vpcmpeqq xmm, xmm, m128",
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
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpeqq",
				.GasMnemonic = "vpcmpeqq",
				.Description = "vpcmpeqq ymm, ymm, ymm",
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
							.Value = 0x29,
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
				.IntelMnemonic = "vpcmpeqq",
				.GasMnemonic = "vpcmpeqq",
				.Description = "vpcmpeqq ymm, ymm, m256",
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
							.Value = 0x29,
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
				.IntelMnemonic = "vpcmpeqw",
				.GasMnemonic = "vpcmpeqw",
				.Description = "vpcmpeqw k{k}, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
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
						.Type = OperandType::Xmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
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
							.Reg = {OperandType::Kk},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpeqw",
				.GasMnemonic = "vpcmpeqw",
				.Description = "vpcmpeqw k{k}, xmm, m128",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M128},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 16,
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
							.Reg = {OperandType::Kk},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpeqw",
				.GasMnemonic = "vpcmpeqw",
				.Description = "vpcmpeqw k{k}, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Ymm},
							.X = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::Ymm},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x75,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
							.Reg = {OperandType::Kk},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpeqw",
				.GasMnemonic = "vpcmpeqw",
				.Description = "vpcmpeqw k{k}, ymm, m256",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M256},
							.X = {OperandType::M256},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::M256},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0x75,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256},
							.Rm = {OperandType::M256},
							.Reg = {OperandType::Kk},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpeqw",
				.GasMnemonic = "vpcmpeqw",
				.Description = "vpcmpeqw k{k}, zmm, zmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Zmm},
							.X = {OperandType::Zmm},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::Zmm},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x75,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Zmm},
							.Reg = {OperandType::Kk},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpeqw",
				.GasMnemonic = "vpcmpeqw",
				.Description = "vpcmpeqw k{k}, zmm, m512",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M512},
							.X = {OperandType::M512},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::M512},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 64,
						},
						OpCode
						{
							.Value = 0x75,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M512},
							.Rm = {OperandType::M512},
							.Reg = {OperandType::Kk},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpeqw",
				.GasMnemonic = "vpcmpeqw",
				.Description = "vpcmpeqw xmm, xmm, xmm",
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
				.IntelMnemonic = "vpcmpeqw",
				.GasMnemonic = "vpcmpeqw",
				.Description = "vpcmpeqw xmm, xmm, m128",
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
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpeqw",
				.GasMnemonic = "vpcmpeqw",
				.Description = "vpcmpeqw ymm, ymm, ymm",
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
							.Value = 0x75,
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
				.IntelMnemonic = "vpcmpeqw",
				.GasMnemonic = "vpcmpeqw",
				.Description = "vpcmpeqw ymm, ymm, m256",
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
							.Value = 0x75,
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
				.IntelMnemonic = "vpcmpestri",
				.GasMnemonic = "vpcmpestri",
				.Description = "vpcmpestri xmm, xmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
							.Vvvv = {UINT64_C(0x0)},
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
				.IntelMnemonic = "vpcmpestri",
				.GasMnemonic = "vpcmpestri",
				.Description = "vpcmpestri xmm, m128, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
							.Vvvv = {UINT64_C(0x0)},
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
				.IntelMnemonic = "vpcmpestrm",
				.GasMnemonic = "vpcmpestrm",
				.Description = "vpcmpestrm xmm, xmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
							.Vvvv = {UINT64_C(0x0)},
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
				.IntelMnemonic = "vpcmpestrm",
				.GasMnemonic = "vpcmpestrm",
				.Description = "vpcmpestrm xmm, m128, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
							.Vvvv = {UINT64_C(0x0)},
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
				.IntelMnemonic = "vpcmpgtb",
				.GasMnemonic = "vpcmpgtb",
				.Description = "vpcmpgtb k{k}, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
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
						.Type = OperandType::Xmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
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
							.Reg = {OperandType::Kk},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpgtb",
				.GasMnemonic = "vpcmpgtb",
				.Description = "vpcmpgtb k{k}, xmm, m128",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M128},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 16,
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
							.Reg = {OperandType::Kk},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpgtb",
				.GasMnemonic = "vpcmpgtb",
				.Description = "vpcmpgtb k{k}, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Ymm},
							.X = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::Ymm},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x64,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
							.Reg = {OperandType::Kk},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpgtb",
				.GasMnemonic = "vpcmpgtb",
				.Description = "vpcmpgtb k{k}, ymm, m256",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M256},
							.X = {OperandType::M256},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::M256},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0x64,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256},
							.Rm = {OperandType::M256},
							.Reg = {OperandType::Kk},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpgtb",
				.GasMnemonic = "vpcmpgtb",
				.Description = "vpcmpgtb k{k}, zmm, zmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Zmm},
							.X = {OperandType::Zmm},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::Zmm},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x64,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Zmm},
							.Reg = {OperandType::Kk},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpgtb",
				.GasMnemonic = "vpcmpgtb",
				.Description = "vpcmpgtb k{k}, zmm, m512",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M512},
							.X = {OperandType::M512},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::M512},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 64,
						},
						OpCode
						{
							.Value = 0x64,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M512},
							.Rm = {OperandType::M512},
							.Reg = {OperandType::Kk},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpgtb",
				.GasMnemonic = "vpcmpgtb",
				.Description = "vpcmpgtb xmm, xmm, xmm",
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
				.IntelMnemonic = "vpcmpgtb",
				.GasMnemonic = "vpcmpgtb",
				.Description = "vpcmpgtb xmm, xmm, m128",
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
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpgtb",
				.GasMnemonic = "vpcmpgtb",
				.Description = "vpcmpgtb ymm, ymm, ymm",
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
							.Value = 0x64,
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
				.IntelMnemonic = "vpcmpgtb",
				.GasMnemonic = "vpcmpgtb",
				.Description = "vpcmpgtb ymm, ymm, m256",
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
							.Value = 0x64,
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
				.IntelMnemonic = "vpcmpgtd",
				.GasMnemonic = "vpcmpgtd",
				.Description = "vpcmpgtd k{k}, xmm, m128/m32bcst",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M128M32Bcst},
							.X = {OperandType::M128M32Bcst},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
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
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpgtd",
				.GasMnemonic = "vpcmpgtd",
				.Description = "vpcmpgtd k{k}, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
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
						.Type = OperandType::Xmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
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
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpgtd",
				.GasMnemonic = "vpcmpgtd",
				.Description = "vpcmpgtd k{k}, ymm, m256/m32bcst",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M256M32Bcst},
							.X = {OperandType::M256M32Bcst},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
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
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpgtd",
				.GasMnemonic = "vpcmpgtd",
				.Description = "vpcmpgtd k{k}, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Ymm},
							.X = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
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
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpgtd",
				.GasMnemonic = "vpcmpgtd",
				.Description = "vpcmpgtd k{k}, zmm, m512/m32bcst",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M512M32Bcst},
							.X = {OperandType::M512M32Bcst},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
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
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpgtd",
				.GasMnemonic = "vpcmpgtd",
				.Description = "vpcmpgtd k{k}, zmm, zmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Zmm},
							.X = {OperandType::Zmm},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
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
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpgtd",
				.GasMnemonic = "vpcmpgtd",
				.Description = "vpcmpgtd xmm, xmm, xmm",
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
				.IntelMnemonic = "vpcmpgtd",
				.GasMnemonic = "vpcmpgtd",
				.Description = "vpcmpgtd xmm, xmm, m128",
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
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpgtd",
				.GasMnemonic = "vpcmpgtd",
				.Description = "vpcmpgtd ymm, ymm, ymm",
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
							.Value = 0x66,
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
				.IntelMnemonic = "vpcmpgtd",
				.GasMnemonic = "vpcmpgtd",
				.Description = "vpcmpgtd ymm, ymm, m256",
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
							.Value = 0x66,
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
				.IntelMnemonic = "vpcmpgtq",
				.GasMnemonic = "vpcmpgtq",
				.Description = "vpcmpgtq k{k}, xmm, m128/m64bcst",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M128M64Bcst},
							.X = {OperandType::M128M64Bcst},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M128M64Bcst},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 16,
						},
						OpCode
						{
							.Value = 0x37,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M128M64Bcst},
							.Rm = {OperandType::M128M64Bcst},
							.Reg = {OperandType::Kk},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpgtq",
				.GasMnemonic = "vpcmpgtq",
				.Description = "vpcmpgtq k{k}, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
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
						.Type = OperandType::Xmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
				.ImplicitInputs =
				{
				},
				.ImplicitOutputs =
				{
				},
				.IsaFeatureExtensions =
				{
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
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
							.Reg = {OperandType::Kk},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpgtq",
				.GasMnemonic = "vpcmpgtq",
				.Description = "vpcmpgtq k{k}, ymm, m256/m64bcst",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M256M64Bcst},
							.X = {OperandType::M256M64Bcst},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::M256M64Bcst},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0x37,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256M64Bcst},
							.Rm = {OperandType::M256M64Bcst},
							.Reg = {OperandType::Kk},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpgtq",
				.GasMnemonic = "vpcmpgtq",
				.Description = "vpcmpgtq k{k}, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Ymm},
							.X = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::Ymm},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x37,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
							.Reg = {OperandType::Kk},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpgtq",
				.GasMnemonic = "vpcmpgtq",
				.Description = "vpcmpgtq k{k}, zmm, m512/m64bcst",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M512M64Bcst},
							.X = {OperandType::M512M64Bcst},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::M512M64Bcst},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 64,
						},
						OpCode
						{
							.Value = 0x37,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M512M64Bcst},
							.Rm = {OperandType::M512M64Bcst},
							.Reg = {OperandType::Kk},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpgtq",
				.GasMnemonic = "vpcmpgtq",
				.Description = "vpcmpgtq k{k}, zmm, zmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Zmm},
							.X = {OperandType::Zmm},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::Zmm},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x37,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Zmm},
							.Reg = {OperandType::Kk},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpgtq",
				.GasMnemonic = "vpcmpgtq",
				.Description = "vpcmpgtq xmm, xmm, xmm",
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
				.IntelMnemonic = "vpcmpgtq",
				.GasMnemonic = "vpcmpgtq",
				.Description = "vpcmpgtq xmm, xmm, m128",
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
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpgtq",
				.GasMnemonic = "vpcmpgtq",
				.Description = "vpcmpgtq ymm, ymm, ymm",
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
							.Value = 0x37,
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
				.IntelMnemonic = "vpcmpgtq",
				.GasMnemonic = "vpcmpgtq",
				.Description = "vpcmpgtq ymm, ymm, m256",
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
							.Value = 0x37,
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
				.IntelMnemonic = "vpcmpgtw",
				.GasMnemonic = "vpcmpgtw",
				.Description = "vpcmpgtw k{k}, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
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
						.Type = OperandType::Xmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
				},
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
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
							.Reg = {OperandType::Kk},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpgtw",
				.GasMnemonic = "vpcmpgtw",
				.Description = "vpcmpgtw k{k}, xmm, m128",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M128},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 16,
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
							.Reg = {OperandType::Kk},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpgtw",
				.GasMnemonic = "vpcmpgtw",
				.Description = "vpcmpgtw k{k}, ymm, ymm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Ymm},
							.X = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::Ymm},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x65,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
							.Reg = {OperandType::Kk},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpgtw",
				.GasMnemonic = "vpcmpgtw",
				.Description = "vpcmpgtw k{k}, ymm, m256",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M256},
							.X = {OperandType::M256},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::M256},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0x65,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256},
							.Rm = {OperandType::M256},
							.Reg = {OperandType::Kk},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpgtw",
				.GasMnemonic = "vpcmpgtw",
				.Description = "vpcmpgtw k{k}, zmm, zmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = true,
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Zmm},
							.X = {OperandType::Zmm},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::Zmm},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x65,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Zmm},
							.Reg = {OperandType::Kk},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpgtw",
				.GasMnemonic = "vpcmpgtw",
				.Description = "vpcmpgtw k{k}, zmm, m512",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M512},
							.X = {OperandType::M512},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::M512},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 64,
						},
						OpCode
						{
							.Value = 0x65,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M512},
							.Rm = {OperandType::M512},
							.Reg = {OperandType::Kk},
						},
					},
				}
			},
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpgtw",
				.GasMnemonic = "vpcmpgtw",
				.Description = "vpcmpgtw xmm, xmm, xmm",
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
				.IntelMnemonic = "vpcmpgtw",
				.GasMnemonic = "vpcmpgtw",
				.Description = "vpcmpgtw xmm, xmm, m128",
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
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpgtw",
				.GasMnemonic = "vpcmpgtw",
				.Description = "vpcmpgtw ymm, ymm, ymm",
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
							.Value = 0x65,
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
				.IntelMnemonic = "vpcmpgtw",
				.GasMnemonic = "vpcmpgtw",
				.Description = "vpcmpgtw ymm, ymm, m256",
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
							.Value = 0x65,
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
				.IntelMnemonic = "vpcmpistri",
				.GasMnemonic = "vpcmpistri",
				.Description = "vpcmpistri xmm, xmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
							.Vvvv = {UINT64_C(0x0)},
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
				.IntelMnemonic = "vpcmpistri",
				.GasMnemonic = "vpcmpistri",
				.Description = "vpcmpistri xmm, m128, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
							.Vvvv = {UINT64_C(0x0)},
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
				.IntelMnemonic = "vpcmpistrm",
				.GasMnemonic = "vpcmpistrm",
				.Description = "vpcmpistrm xmm, xmm, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
							.Vvvv = {UINT64_C(0x0)},
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
				.IntelMnemonic = "vpcmpistrm",
				.GasMnemonic = "vpcmpistrm",
				.Description = "vpcmpistrm xmm, m128, imm8",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
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
							.Vvvv = {UINT64_C(0x0)},
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
				.IntelMnemonic = "vpcmpq",
				.GasMnemonic = "vpcmpq",
				.Description = "vpcmpq k{k}, xmm, m128/m64bcst, imm8",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M128M64Bcst},
							.X = {OperandType::M128M64Bcst},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M128M64Bcst},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 16,
						},
						OpCode
						{
							.Value = 0x1f,
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
				.IntelMnemonic = "vpcmpq",
				.GasMnemonic = "vpcmpq",
				.Description = "vpcmpq k{k}, xmm, xmm, imm8",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x1f,
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
				.IntelMnemonic = "vpcmpq",
				.GasMnemonic = "vpcmpq",
				.Description = "vpcmpq k{k}, ymm, m256/m64bcst, imm8",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M256M64Bcst},
							.X = {OperandType::M256M64Bcst},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::M256M64Bcst},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0x1f,
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
				.IntelMnemonic = "vpcmpq",
				.GasMnemonic = "vpcmpq",
				.Description = "vpcmpq k{k}, ymm, ymm, imm8",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Ymm},
							.X = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::Ymm},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x1f,
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
				.IntelMnemonic = "vpcmpq",
				.GasMnemonic = "vpcmpq",
				.Description = "vpcmpq k{k}, zmm, m512/m64bcst, imm8",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M512M64Bcst},
							.X = {OperandType::M512M64Bcst},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::M512M64Bcst},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 64,
						},
						OpCode
						{
							.Value = 0x1f,
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
				.IntelMnemonic = "vpcmpq",
				.GasMnemonic = "vpcmpq",
				.Description = "vpcmpq k{k}, zmm, zmm, imm8",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Zmm},
							.X = {OperandType::Zmm},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::Zmm},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x1f,
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
				.IntelMnemonic = "vpcmpub",
				.GasMnemonic = "vpcmpub",
				.Description = "vpcmpub k{k}, xmm, xmm, imm8",
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
							.Mm = 0b11,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x3e,
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
				.IntelMnemonic = "vpcmpub",
				.GasMnemonic = "vpcmpub",
				.Description = "vpcmpub k{k}, xmm, m128, imm8",
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
							.Mm = 0b11,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M128},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 16,
						},
						OpCode
						{
							.Value = 0x3e,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M128},
							.Rm = {OperandType::M128},
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
				.IntelMnemonic = "vpcmpub",
				.GasMnemonic = "vpcmpub",
				.Description = "vpcmpub k{k}, ymm, ymm, imm8",
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
							.Mm = 0b11,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Ymm},
							.X = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::Ymm},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x3e,
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
				.IntelMnemonic = "vpcmpub",
				.GasMnemonic = "vpcmpub",
				.Description = "vpcmpub k{k}, ymm, m256, imm8",
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
							.Mm = 0b11,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M256},
							.X = {OperandType::M256},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::M256},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0x3e,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256},
							.Rm = {OperandType::M256},
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
				.IntelMnemonic = "vpcmpub",
				.GasMnemonic = "vpcmpub",
				.Description = "vpcmpub k{k}, zmm, zmm, imm8",
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
							.Mm = 0b11,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Zmm},
							.X = {OperandType::Zmm},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::Zmm},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x3e,
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
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpub",
				.GasMnemonic = "vpcmpub",
				.Description = "vpcmpub k{k}, zmm, m512, imm8",
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
							.Mm = 0b11,
							.Pp = 0b1,
							.W = false,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M512},
							.X = {OperandType::M512},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::M512},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 64,
						},
						OpCode
						{
							.Value = 0x3e,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M512},
							.Rm = {OperandType::M512},
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
				.IntelMnemonic = "vpcmpud",
				.GasMnemonic = "vpcmpud",
				.Description = "vpcmpud k{k}, xmm, m128/m32bcst, imm8",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M128M32Bcst},
							.X = {OperandType::M128M32Bcst},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M128M32Bcst},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 16,
						},
						OpCode
						{
							.Value = 0x1e,
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
				.IntelMnemonic = "vpcmpud",
				.GasMnemonic = "vpcmpud",
				.Description = "vpcmpud k{k}, xmm, xmm, imm8",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
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
				.IntelMnemonic = "vpcmpud",
				.GasMnemonic = "vpcmpud",
				.Description = "vpcmpud k{k}, ymm, m256/m32bcst, imm8",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M256M32Bcst},
							.X = {OperandType::M256M32Bcst},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::M256M32Bcst},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0x1e,
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
				.IntelMnemonic = "vpcmpud",
				.GasMnemonic = "vpcmpud",
				.Description = "vpcmpud k{k}, ymm, ymm, imm8",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Ymm},
							.X = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::Ymm},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x1e,
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
				.IntelMnemonic = "vpcmpud",
				.GasMnemonic = "vpcmpud",
				.Description = "vpcmpud k{k}, zmm, m512/m32bcst, imm8",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M512M32Bcst},
							.X = {OperandType::M512M32Bcst},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::M512M32Bcst},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 64,
						},
						OpCode
						{
							.Value = 0x1e,
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
				.IntelMnemonic = "vpcmpud",
				.GasMnemonic = "vpcmpud",
				.Description = "vpcmpud k{k}, zmm, zmm, imm8",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Zmm},
							.X = {OperandType::Zmm},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::Zmm},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x1e,
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
				.IntelMnemonic = "vpcmpuq",
				.GasMnemonic = "vpcmpuq",
				.Description = "vpcmpuq k{k}, xmm, m128/m64bcst, imm8",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M128M64Bcst},
							.X = {OperandType::M128M64Bcst},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M128M64Bcst},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 16,
						},
						OpCode
						{
							.Value = 0x1e,
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
				.IntelMnemonic = "vpcmpuq",
				.GasMnemonic = "vpcmpuq",
				.Description = "vpcmpuq k{k}, xmm, xmm, imm8",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
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
				.IntelMnemonic = "vpcmpuq",
				.GasMnemonic = "vpcmpuq",
				.Description = "vpcmpuq k{k}, ymm, m256/m64bcst, imm8",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M256M64Bcst},
							.X = {OperandType::M256M64Bcst},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::M256M64Bcst},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0x1e,
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
				.IntelMnemonic = "vpcmpuq",
				.GasMnemonic = "vpcmpuq",
				.Description = "vpcmpuq k{k}, ymm, ymm, imm8",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Ymm},
							.X = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::Ymm},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x1e,
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
				.IntelMnemonic = "vpcmpuq",
				.GasMnemonic = "vpcmpuq",
				.Description = "vpcmpuq k{k}, zmm, m512/m64bcst, imm8",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M512M64Bcst},
							.X = {OperandType::M512M64Bcst},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::M512M64Bcst},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 64,
						},
						OpCode
						{
							.Value = 0x1e,
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
				.IntelMnemonic = "vpcmpuq",
				.GasMnemonic = "vpcmpuq",
				.Description = "vpcmpuq k{k}, zmm, zmm, imm8",
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
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Zmm},
							.X = {OperandType::Zmm},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::Zmm},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x1e,
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
				.IntelMnemonic = "vpcmpuw",
				.GasMnemonic = "vpcmpuw",
				.Description = "vpcmpuw k{k}, xmm, xmm, imm8",
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
							.Mm = 0b11,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Xmm},
							.X = {OperandType::Xmm},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::Xmm},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x3e,
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
				.IntelMnemonic = "vpcmpuw",
				.GasMnemonic = "vpcmpuw",
				.Description = "vpcmpuw k{k}, xmm, m128, imm8",
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
							.Mm = 0b11,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x0),
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M128},
							.X = {OperandType::M128},
							.Vvvv = {OperandType::Xmm},
							.V = {OperandType::Xmm},
							.B = {OperandType::M128},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 16,
						},
						OpCode
						{
							.Value = 0x3e,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M128},
							.Rm = {OperandType::M128},
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
				.IntelMnemonic = "vpcmpuw",
				.GasMnemonic = "vpcmpuw",
				.Description = "vpcmpuw k{k}, ymm, ymm, imm8",
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
							.Mm = 0b11,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Ymm},
							.X = {OperandType::Ymm},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::Ymm},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x3e,
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
				.IntelMnemonic = "vpcmpuw",
				.GasMnemonic = "vpcmpuw",
				.Description = "vpcmpuw k{k}, ymm, m256, imm8",
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
							.Mm = 0b11,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x1),
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M256},
							.X = {OperandType::M256},
							.Vvvv = {OperandType::Ymm},
							.V = {OperandType::Ymm},
							.B = {OperandType::M256},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 32,
						},
						OpCode
						{
							.Value = 0x3e,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M256},
							.Rm = {OperandType::M256},
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
				.IntelMnemonic = "vpcmpuw",
				.GasMnemonic = "vpcmpuw",
				.Description = "vpcmpuw k{k}, zmm, zmm, imm8",
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
							.Mm = 0b11,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::Zmm},
							.X = {OperandType::Zmm},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::Zmm},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 0,
						},
						OpCode
						{
							.Value = 0x3e,
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
			InstructionVariation
			{
				.IntelMnemonic = "vpcmpuw",
				.GasMnemonic = "vpcmpuw",
				.Description = "vpcmpuw k{k}, zmm, m512, imm8",
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
							.Mm = 0b11,
							.Pp = 0b1,
							.W = true,
							.Ll = UINT64_C(0x2),
							.Rr = {OperandType::Kk},
							.Bb = {OperandType::M512},
							.X = {OperandType::M512},
							.Vvvv = {OperandType::Zmm},
							.V = {OperandType::Zmm},
							.B = {OperandType::M512},
							.Aaa = {OperandType::Kk},
							.Z = {UINT64_C(0x0)},
							.Disp8xN = 64,
						},
						OpCode
						{
							.Value = 0x3e,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {OperandType::M512},
							.Rm = {OperandType::M512},
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
	};
}
