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
NOX_NEVER_INLINE NOX_COLD auto GetVariationTable_19(std::pmr::monotonic_buffer_resource& allocator, std::pmr::vector<InstructionVariationPool>& out) -> void
{
	std::pmr::vector<InstructionVariation> instruction{&allocator};
	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "vcvtps2uqq",
			.GasMnemonic = "vcvtps2uqq",
			.Description = "vcvtps2uqq xmm{k}{z}, m64/m32bcst",
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
					.Type = OperandType::M64M32Bcst,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
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
						.Mm = 0b1,
						.Pp = 0b1,
						.W = false,
						.Ll = UINT64_C(0x0),
						.Rr = {OperandType::XmmKz},
						.Bb = {OperandType::M64M32Bcst},
						.X = {OperandType::M64M32Bcst},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M64M32Bcst},
						.Aaa = {OperandType::XmmKz},
						.Z = {OperandType::XmmKz},
						.Disp8xN = 8,
					},
					OpCode
					{
						.Value = 0x79,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64M32Bcst},
						.Rm = {OperandType::M64M32Bcst},
						.Reg = {OperandType::XmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvtps2uqq",
			.GasMnemonic = "vcvtps2uqq",
			.Description = "vcvtps2uqq ymm{k}{z}, m128/m32bcst",
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
				IsaExtension::Avx512Dq,
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
						.Bb = {OperandType::M128M32Bcst},
						.X = {OperandType::M128M32Bcst},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M128M32Bcst},
						.Aaa = {OperandType::YmmKz},
						.Z = {OperandType::YmmKz},
						.Disp8xN = 16,
					},
					OpCode
					{
						.Value = 0x79,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128M32Bcst},
						.Rm = {OperandType::M128M32Bcst},
						.Reg = {OperandType::YmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvtps2uqq",
			.GasMnemonic = "vcvtps2uqq",
			.Description = "vcvtps2uqq zmm{k}{z}, m256/m32bcst",
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
				IsaExtension::Avx512Dq,
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
						.Bb = {OperandType::M256M32Bcst},
						.X = {OperandType::M256M32Bcst},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M256M32Bcst},
						.Aaa = {OperandType::ZmmKz},
						.Z = {OperandType::ZmmKz},
						.Disp8xN = 32,
					},
					OpCode
					{
						.Value = 0x79,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M256M32Bcst},
						.Rm = {OperandType::M256M32Bcst},
						.Reg = {OperandType::ZmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvtps2uqq",
			.GasMnemonic = "vcvtps2uqq",
			.Description = "vcvtps2uqq xmm{k}{z}, xmm",
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
				IsaExtension::Avx512Dq,
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
			.IntelMnemonic = "vcvtps2uqq",
			.GasMnemonic = "vcvtps2uqq",
			.Description = "vcvtps2uqq ymm{k}{z}, xmm",
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
				IsaExtension::Avx512Dq,
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
			.IntelMnemonic = "vcvtps2uqq",
			.GasMnemonic = "vcvtps2uqq",
			.Description = "vcvtps2uqq zmm{k}{z}, ymm, {er}",
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
				IsaExtension::Avx512Dq,
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
						.Ll = OperandType::Er,
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
						.Value = 0x79,
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
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "vcvtqq2pd",
			.GasMnemonic = "vcvtqq2pd",
			.Description = "vcvtqq2pd xmm{k}{z}, m128/m64bcst",
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
				IsaExtension::Avx512Dq,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Evex
					{
						.Mm = 0b1,
						.Pp = 0b10,
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
						.Value = 0xe6,
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
			.IntelMnemonic = "vcvtqq2pd",
			.GasMnemonic = "vcvtqq2pd",
			.Description = "vcvtqq2pd ymm{k}{z}, m256/m64bcst",
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
				IsaExtension::Avx512Dq,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Evex
					{
						.Mm = 0b1,
						.Pp = 0b10,
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
						.Value = 0xe6,
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
			.IntelMnemonic = "vcvtqq2pd",
			.GasMnemonic = "vcvtqq2pd",
			.Description = "vcvtqq2pd zmm{k}{z}, m512/m64bcst",
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
				IsaExtension::Avx512Dq,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Evex
					{
						.Mm = 0b1,
						.Pp = 0b10,
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
						.Value = 0xe6,
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
			.IntelMnemonic = "vcvtqq2pd",
			.GasMnemonic = "vcvtqq2pd",
			.Description = "vcvtqq2pd xmm{k}{z}, xmm",
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
				IsaExtension::Avx512Dq,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Evex
					{
						.Mm = 0b1,
						.Pp = 0b10,
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
						.Value = 0xe6,
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
			.IntelMnemonic = "vcvtqq2pd",
			.GasMnemonic = "vcvtqq2pd",
			.Description = "vcvtqq2pd ymm{k}{z}, ymm",
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
				IsaExtension::Avx512Dq,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Evex
					{
						.Mm = 0b1,
						.Pp = 0b10,
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
						.Value = 0xe6,
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
			.IntelMnemonic = "vcvtqq2pd",
			.GasMnemonic = "vcvtqq2pd",
			.Description = "vcvtqq2pd zmm{k}{z}, zmm, {er}",
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
				IsaExtension::Avx512Dq,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Evex
					{
						.Mm = 0b1,
						.Pp = 0b10,
						.W = true,
						.Ll = OperandType::Er,
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
						.Value = 0xe6,
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
			.IntelMnemonic = "vcvtqq2ps",
			.GasMnemonic = "vcvtqq2ps",
			.Description = "vcvtqq2ps xmm{k}{z}, m128/m64bcst",
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
				IsaExtension::Avx512Dq,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Evex
					{
						.Mm = 0b1,
						.Pp = 0b0,
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
						.Value = 0x5b,
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
			.IntelMnemonic = "vcvtqq2ps",
			.GasMnemonic = "vcvtqq2ps",
			.Description = "vcvtqq2ps xmm{k}{z}, m256/m64bcst",
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
						.Mm = 0b1,
						.Pp = 0b0,
						.W = true,
						.Ll = UINT64_C(0x1),
						.Rr = {OperandType::XmmKz},
						.Bb = {OperandType::M256M64Bcst},
						.X = {OperandType::M256M64Bcst},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M256M64Bcst},
						.Aaa = {OperandType::XmmKz},
						.Z = {OperandType::XmmKz},
						.Disp8xN = 32,
					},
					OpCode
					{
						.Value = 0x5b,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M256M64Bcst},
						.Rm = {OperandType::M256M64Bcst},
						.Reg = {OperandType::XmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvtqq2ps",
			.GasMnemonic = "vcvtqq2ps",
			.Description = "vcvtqq2ps ymm{k}{z}, m512/m64bcst",
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
						.Mm = 0b1,
						.Pp = 0b0,
						.W = true,
						.Ll = UINT64_C(0x2),
						.Rr = {OperandType::YmmKz},
						.Bb = {OperandType::M512M64Bcst},
						.X = {OperandType::M512M64Bcst},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M512M64Bcst},
						.Aaa = {OperandType::YmmKz},
						.Z = {OperandType::YmmKz},
						.Disp8xN = 64,
					},
					OpCode
					{
						.Value = 0x5b,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M512M64Bcst},
						.Rm = {OperandType::M512M64Bcst},
						.Reg = {OperandType::YmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvtqq2ps",
			.GasMnemonic = "vcvtqq2ps",
			.Description = "vcvtqq2ps xmm{k}{z}, xmm",
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
				IsaExtension::Avx512Dq,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Evex
					{
						.Mm = 0b1,
						.Pp = 0b0,
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
						.Value = 0x5b,
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
			.IntelMnemonic = "vcvtqq2ps",
			.GasMnemonic = "vcvtqq2ps",
			.Description = "vcvtqq2ps xmm{k}{z}, ymm",
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
				IsaExtension::Avx512Dq,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Evex
					{
						.Mm = 0b1,
						.Pp = 0b0,
						.W = true,
						.Ll = UINT64_C(0x1),
						.Rr = {OperandType::XmmKz},
						.Bb = {OperandType::Ymm},
						.X = {OperandType::Ymm},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Ymm},
						.Aaa = {OperandType::XmmKz},
						.Z = {OperandType::XmmKz},
						.Disp8xN = 0,
					},
					OpCode
					{
						.Value = 0x5b,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Ymm},
						.Reg = {OperandType::XmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvtqq2ps",
			.GasMnemonic = "vcvtqq2ps",
			.Description = "vcvtqq2ps ymm{k}{z}, zmm, {er}",
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
				IsaExtension::Avx512Dq,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Evex
					{
						.Mm = 0b1,
						.Pp = 0b0,
						.W = true,
						.Ll = OperandType::Er,
						.Rr = {OperandType::YmmKz},
						.Bb = {OperandType::Zmm},
						.X = {OperandType::Zmm},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Zmm},
						.Aaa = {OperandType::YmmKz},
						.Z = {OperandType::YmmKz},
						.Disp8xN = 0,
					},
					OpCode
					{
						.Value = 0x5b,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Zmm},
						.Reg = {OperandType::YmmKz},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "vcvtsd2si",
			.GasMnemonic = "vcvtsd2si",
			.Description = "vcvtsd2si r32, xmm",
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
						.R = {OperandType::R32},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x2d,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::R32},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvtsd2si",
			.GasMnemonic = "vcvtsd2si",
			.Description = "vcvtsd2si r32, m64",
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
						.R = {OperandType::R32},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x2d,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::R32},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvtsd2si",
			.GasMnemonic = "vcvtsd2si",
			.Description = "vcvtsd2si r32, m64",
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
						.W = false,
						.Ll = UINT64_C(0x0),
						.Rr = {OperandType::R32},
						.Bb = {OperandType::M64},
						.X = {OperandType::M64},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M64},
						.Aaa = {UINT64_C(0x0)},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 8,
					},
					OpCode
					{
						.Value = 0x2d,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::R32},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvtsd2si",
			.GasMnemonic = "vcvtsd2si",
			.Description = "vcvtsd2si r64, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
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
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
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
						.W = true,
						.L = false,
						.R = {OperandType::R64},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x2d,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::R64},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvtsd2si",
			.GasMnemonic = "vcvtsd2si",
			.Description = "vcvtsd2si r64, m64",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
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
						.W = true,
						.L = false,
						.R = {OperandType::R64},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x2d,
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
			.IntelMnemonic = "vcvtsd2si",
			.GasMnemonic = "vcvtsd2si",
			.Description = "vcvtsd2si r64, m64",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
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
						.Rr = {OperandType::R64},
						.Bb = {OperandType::M64},
						.X = {OperandType::M64},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M64},
						.Aaa = {UINT64_C(0x0)},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 8,
					},
					OpCode
					{
						.Value = 0x2d,
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
			.IntelMnemonic = "vcvtsd2si",
			.GasMnemonic = "vcvtsd2si",
			.Description = "vcvtsd2si r32, xmm, {er}",
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
						.W = false,
						.Ll = OperandType::Er,
						.Rr = {OperandType::R32},
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
						.Value = 0x2d,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::R32},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvtsd2si",
			.GasMnemonic = "vcvtsd2si",
			.Description = "vcvtsd2si r64, xmm, {er}",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
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
						.Rr = {OperandType::R64},
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
						.Value = 0x2d,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
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
			.IntelMnemonic = "vcvtsd2ss",
			.GasMnemonic = "vcvtsd2ss",
			.Description = "vcvtsd2ss xmm{k}{z}, xmm, m64",
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
						.Value = 0x5a,
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
			.IntelMnemonic = "vcvtsd2ss",
			.GasMnemonic = "vcvtsd2ss",
			.Description = "vcvtsd2ss xmm, xmm, xmm",
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
						.Value = 0x5a,
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
			.IntelMnemonic = "vcvtsd2ss",
			.GasMnemonic = "vcvtsd2ss",
			.Description = "vcvtsd2ss xmm, xmm, m64",
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
						.Value = 0x5a,
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
			.IntelMnemonic = "vcvtsd2ss",
			.GasMnemonic = "vcvtsd2ss",
			.Description = "vcvtsd2ss xmm{k}{z}, xmm, xmm, {er}",
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
						.Value = 0x5a,
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
			.IntelMnemonic = "vcvtsd2usi",
			.GasMnemonic = "vcvtsd2usi",
			.Description = "vcvtsd2usi r32, m64",
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
						.W = false,
						.Ll = UINT64_C(0x0),
						.Rr = {OperandType::R32},
						.Bb = {OperandType::M64},
						.X = {OperandType::M64},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M64},
						.Aaa = {UINT64_C(0x0)},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 8,
					},
					OpCode
					{
						.Value = 0x79,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::R32},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvtsd2usi",
			.GasMnemonic = "vcvtsd2usi",
			.Description = "vcvtsd2usi r64, m64",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
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
						.Rr = {OperandType::R64},
						.Bb = {OperandType::M64},
						.X = {OperandType::M64},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M64},
						.Aaa = {UINT64_C(0x0)},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 8,
					},
					OpCode
					{
						.Value = 0x79,
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
			.IntelMnemonic = "vcvtsd2usi",
			.GasMnemonic = "vcvtsd2usi",
			.Description = "vcvtsd2usi r32, xmm, {er}",
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
						.W = false,
						.Ll = OperandType::Er,
						.Rr = {OperandType::R32},
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
						.Value = 0x79,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::R32},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvtsd2usi",
			.GasMnemonic = "vcvtsd2usi",
			.Description = "vcvtsd2usi r64, xmm, {er}",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
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
						.Rr = {OperandType::R64},
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
						.Value = 0x79,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
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
			.IntelMnemonic = "vcvtsi2sd",
			.GasMnemonic = "vcvtsi2sd",
			.Description = "vcvtsi2sd xmm, xmm, r32",
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
						.B = {OperandType::R32},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0x2a,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R32},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvtsi2sd",
			.GasMnemonic = "vcvtsi2sd",
			.Description = "vcvtsi2sd xmm, xmm, r32",
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
						.Value = 0x2a,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R32},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvtsi2sd",
			.GasMnemonic = "vcvtsi2sd",
			.Description = "vcvtsi2sd xmm, xmm, r64",
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
						.W = true,
						.L = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R64},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0x2a,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R64},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvtsi2sd",
			.GasMnemonic = "vcvtsi2sd",
			.Description = "vcvtsi2sd xmm, xmm, m32",
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
						.Pp = 0b11,
						.W = false,
						.L = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M32},
						.B = {OperandType::M32},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0x2a,
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
			.IntelMnemonic = "vcvtsi2sd",
			.GasMnemonic = "vcvtsi2sd",
			.Description = "vcvtsi2sd xmm, xmm, m32",
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
						.Value = 0x2a,
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
			.IntelMnemonic = "vcvtsi2sd",
			.GasMnemonic = "vcvtsi2sd",
			.Description = "vcvtsi2sd xmm, xmm, m64",
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
						.W = true,
						.L = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0x2a,
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
			.IntelMnemonic = "vcvtsi2sd",
			.GasMnemonic = "vcvtsi2sd",
			.Description = "vcvtsi2sd xmm, xmm, m64",
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
						.Value = 0x2a,
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
			.IntelMnemonic = "vcvtsi2sd",
			.GasMnemonic = "vcvtsi2sd",
			.Description = "vcvtsi2sd xmm, xmm, r64, {er}",
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
						.Value = 0x2a,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R64},
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
			.IntelMnemonic = "vcvtsi2ss",
			.GasMnemonic = "vcvtsi2ss",
			.Description = "vcvtsi2ss xmm, xmm, r32",
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
						.B = {OperandType::R32},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0x2a,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R32},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvtsi2ss",
			.GasMnemonic = "vcvtsi2ss",
			.Description = "vcvtsi2ss xmm, xmm, r64",
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
						.W = true,
						.L = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R64},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0x2a,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R64},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvtsi2ss",
			.GasMnemonic = "vcvtsi2ss",
			.Description = "vcvtsi2ss xmm, xmm, m32",
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
						.Value = 0x2a,
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
			.IntelMnemonic = "vcvtsi2ss",
			.GasMnemonic = "vcvtsi2ss",
			.Description = "vcvtsi2ss xmm, xmm, m32",
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
						.Value = 0x2a,
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
			.IntelMnemonic = "vcvtsi2ss",
			.GasMnemonic = "vcvtsi2ss",
			.Description = "vcvtsi2ss xmm, xmm, m64",
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
						.Pp = 0b10,
						.W = true,
						.L = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.Vvvv = {OperandType::Xmm},
					},
					OpCode
					{
						.Value = 0x2a,
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
			.IntelMnemonic = "vcvtsi2ss",
			.GasMnemonic = "vcvtsi2ss",
			.Description = "vcvtsi2ss xmm, xmm, m64",
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
						.Value = 0x2a,
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
			.IntelMnemonic = "vcvtsi2ss",
			.GasMnemonic = "vcvtsi2ss",
			.Description = "vcvtsi2ss xmm, xmm, r32, {er}",
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
						.Value = 0x2a,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R32},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvtsi2ss",
			.GasMnemonic = "vcvtsi2ss",
			.Description = "vcvtsi2ss xmm, xmm, r64, {er}",
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
						.W = true,
						.Ll = OperandType::Er,
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
						.Value = 0x2a,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R64},
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
			.IntelMnemonic = "vcvtss2sd",
			.GasMnemonic = "vcvtss2sd",
			.Description = "vcvtss2sd xmm{k}{z}, xmm, m32",
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
						.Value = 0x5a,
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
			.IntelMnemonic = "vcvtss2sd",
			.GasMnemonic = "vcvtss2sd",
			.Description = "vcvtss2sd xmm, xmm, xmm",
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
						.Value = 0x5a,
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
			.IntelMnemonic = "vcvtss2sd",
			.GasMnemonic = "vcvtss2sd",
			.Description = "vcvtss2sd xmm, xmm, m32",
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
						.Value = 0x5a,
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
			.IntelMnemonic = "vcvtss2sd",
			.GasMnemonic = "vcvtss2sd",
			.Description = "vcvtss2sd xmm{k}{z}, xmm, xmm, {sae}",
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
						.Mm = 0b1,
						.Pp = 0b10,
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
						.Value = 0x5a,
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
			.IntelMnemonic = "vcvtss2si",
			.GasMnemonic = "vcvtss2si",
			.Description = "vcvtss2si r32, xmm",
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
						.R = {OperandType::R32},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x2d,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::R32},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvtss2si",
			.GasMnemonic = "vcvtss2si",
			.Description = "vcvtss2si r32, m32",
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
						.R = {OperandType::R32},
						.X = {OperandType::M32},
						.B = {OperandType::M32},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x2d,
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
			.IntelMnemonic = "vcvtss2si",
			.GasMnemonic = "vcvtss2si",
			.Description = "vcvtss2si r32, m32",
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
						.Rr = {OperandType::R32},
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
						.Value = 0x2d,
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
			.IntelMnemonic = "vcvtss2si",
			.GasMnemonic = "vcvtss2si",
			.Description = "vcvtss2si r64, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
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
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
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
						.W = true,
						.L = false,
						.R = {OperandType::R64},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x2d,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::R64},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvtss2si",
			.GasMnemonic = "vcvtss2si",
			.Description = "vcvtss2si r64, m32",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
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
						.W = true,
						.L = false,
						.R = {OperandType::R64},
						.X = {OperandType::M32},
						.B = {OperandType::M32},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x2d,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M32},
						.Rm = {OperandType::M32},
						.Reg = {OperandType::R64},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvtss2si",
			.GasMnemonic = "vcvtss2si",
			.Description = "vcvtss2si r64, m32",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
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
						.W = true,
						.Ll = UINT64_C(0x0),
						.Rr = {OperandType::R64},
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
						.Value = 0x2d,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M32},
						.Rm = {OperandType::M32},
						.Reg = {OperandType::R64},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvtss2si",
			.GasMnemonic = "vcvtss2si",
			.Description = "vcvtss2si r32, xmm, {er}",
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
						.Rr = {OperandType::R32},
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
						.Value = 0x2d,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::R32},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvtss2si",
			.GasMnemonic = "vcvtss2si",
			.Description = "vcvtss2si r64, xmm, {er}",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
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
						.W = true,
						.Ll = OperandType::Er,
						.Rr = {OperandType::R64},
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
						.Value = 0x2d,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
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
			.IntelMnemonic = "vcvtss2usi",
			.GasMnemonic = "vcvtss2usi",
			.Description = "vcvtss2usi r32, m32",
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
						.Rr = {OperandType::R32},
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
						.Value = 0x79,
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
			.IntelMnemonic = "vcvtss2usi",
			.GasMnemonic = "vcvtss2usi",
			.Description = "vcvtss2usi r64, m32",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
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
						.W = true,
						.Ll = UINT64_C(0x0),
						.Rr = {OperandType::R64},
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
						.Value = 0x79,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M32},
						.Rm = {OperandType::M32},
						.Reg = {OperandType::R64},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvtss2usi",
			.GasMnemonic = "vcvtss2usi",
			.Description = "vcvtss2usi r32, xmm, {er}",
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
						.Rr = {OperandType::R32},
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
						.Value = 0x79,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::R32},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvtss2usi",
			.GasMnemonic = "vcvtss2usi",
			.Description = "vcvtss2usi r64, xmm, {er}",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
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
						.W = true,
						.Ll = OperandType::Er,
						.Rr = {OperandType::R64},
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
						.Value = 0x79,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
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
			.IntelMnemonic = "vcvttpd2dq",
			.GasMnemonic = "vcvttpd2dq",
			.Description = "vcvttpd2dq xmm{k}{z}, m128/m64bcst",
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
						.Mm = 0b1,
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
						.Value = 0xe6,
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
			.IntelMnemonic = "vcvttpd2dq",
			.GasMnemonic = "vcvttpd2dq",
			.Description = "vcvttpd2dq xmm{k}{z}, m256/m64bcst",
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
						.Rr = {OperandType::XmmKz},
						.Bb = {OperandType::M256M64Bcst},
						.X = {OperandType::M256M64Bcst},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M256M64Bcst},
						.Aaa = {OperandType::XmmKz},
						.Z = {OperandType::XmmKz},
						.Disp8xN = 32,
					},
					OpCode
					{
						.Value = 0xe6,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M256M64Bcst},
						.Rm = {OperandType::M256M64Bcst},
						.Reg = {OperandType::XmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvttpd2dq",
			.GasMnemonic = "vcvttpd2dq",
			.Description = "vcvttpd2dq ymm{k}{z}, m512/m64bcst",
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
						.Rr = {OperandType::YmmKz},
						.Bb = {OperandType::M512M64Bcst},
						.X = {OperandType::M512M64Bcst},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M512M64Bcst},
						.Aaa = {OperandType::YmmKz},
						.Z = {OperandType::YmmKz},
						.Disp8xN = 64,
					},
					OpCode
					{
						.Value = 0xe6,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M512M64Bcst},
						.Rm = {OperandType::M512M64Bcst},
						.Reg = {OperandType::YmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvttpd2dq",
			.GasMnemonic = "vcvttpd2dq",
			.Description = "vcvttpd2dq xmm{k}{z}, xmm",
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
						.Mm = 0b1,
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
						.Value = 0xe6,
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
			.IntelMnemonic = "vcvttpd2dq",
			.GasMnemonic = "vcvttpd2dq",
			.Description = "vcvttpd2dq xmm{k}{z}, ymm",
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
						.Mm = 0b1,
						.Pp = 0b1,
						.W = true,
						.Ll = UINT64_C(0x1),
						.Rr = {OperandType::XmmKz},
						.Bb = {OperandType::Ymm},
						.X = {OperandType::Ymm},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Ymm},
						.Aaa = {OperandType::XmmKz},
						.Z = {OperandType::XmmKz},
						.Disp8xN = 0,
					},
					OpCode
					{
						.Value = 0xe6,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Ymm},
						.Reg = {OperandType::XmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvttpd2dq",
			.GasMnemonic = "vcvttpd2dq",
			.Description = "vcvttpd2dq xmm, xmm",
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
						.Mmmmm = 0b1,
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
						.Value = 0xe6,
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
			.IntelMnemonic = "vcvttpd2dq",
			.GasMnemonic = "vcvttpd2dq",
			.Description = "vcvttpd2dq xmm, ymm",
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
						.L = true,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Ymm},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xe6,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Ymm},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvttpd2dq",
			.GasMnemonic = "vcvttpd2dq",
			.Description = "vcvttpd2dq xmm, m128",
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
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xe6,
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
			.IntelMnemonic = "vcvttpd2dq",
			.GasMnemonic = "vcvttpd2dq",
			.Description = "vcvttpd2dq xmm, m256",
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
						.L = true,
						.R = {OperandType::Xmm},
						.X = {OperandType::M256},
						.B = {OperandType::M256},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xe6,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M256},
						.Rm = {OperandType::M256},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvttpd2dq",
			.GasMnemonic = "vcvttpd2dq",
			.Description = "vcvttpd2dq ymm{k}{z}, zmm, {sae}",
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
						.Mm = 0b1,
						.Pp = 0b1,
						.W = true,
						.Ll = UINT64_C(0x2),
						.Rr = {OperandType::YmmKz},
						.Bb = {OperandType::Zmm},
						.X = {OperandType::Zmm},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Zmm},
						.Aaa = {OperandType::YmmKz},
						.Z = {OperandType::YmmKz},
						.Disp8xN = 0,
					},
					OpCode
					{
						.Value = 0xe6,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Zmm},
						.Reg = {OperandType::YmmKz},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "vcvttpd2qq",
			.GasMnemonic = "vcvttpd2qq",
			.Description = "vcvttpd2qq xmm{k}{z}, m128/m64bcst",
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
				IsaExtension::Avx512Dq,
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
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M128M64Bcst},
						.Aaa = {OperandType::XmmKz},
						.Z = {OperandType::XmmKz},
						.Disp8xN = 16,
					},
					OpCode
					{
						.Value = 0x7a,
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
			.IntelMnemonic = "vcvttpd2qq",
			.GasMnemonic = "vcvttpd2qq",
			.Description = "vcvttpd2qq ymm{k}{z}, m256/m64bcst",
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
				IsaExtension::Avx512Dq,
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
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M256M64Bcst},
						.Aaa = {OperandType::YmmKz},
						.Z = {OperandType::YmmKz},
						.Disp8xN = 32,
					},
					OpCode
					{
						.Value = 0x7a,
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
			.IntelMnemonic = "vcvttpd2qq",
			.GasMnemonic = "vcvttpd2qq",
			.Description = "vcvttpd2qq zmm{k}{z}, m512/m64bcst",
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
				IsaExtension::Avx512Dq,
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
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M512M64Bcst},
						.Aaa = {OperandType::ZmmKz},
						.Z = {OperandType::ZmmKz},
						.Disp8xN = 64,
					},
					OpCode
					{
						.Value = 0x7a,
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
			.IntelMnemonic = "vcvttpd2qq",
			.GasMnemonic = "vcvttpd2qq",
			.Description = "vcvttpd2qq xmm{k}{z}, xmm",
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
				IsaExtension::Avx512Dq,
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
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
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
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::XmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvttpd2qq",
			.GasMnemonic = "vcvttpd2qq",
			.Description = "vcvttpd2qq ymm{k}{z}, ymm",
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
				IsaExtension::Avx512Dq,
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
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Ymm},
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
						.Rm = {OperandType::Ymm},
						.Reg = {OperandType::YmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvttpd2qq",
			.GasMnemonic = "vcvttpd2qq",
			.Description = "vcvttpd2qq zmm{k}{z}, zmm, {sae}",
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
				IsaExtension::Avx512Dq,
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
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Zmm},
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
			.IntelMnemonic = "vcvttpd2udq",
			.GasMnemonic = "vcvttpd2udq",
			.Description = "vcvttpd2udq xmm{k}{z}, m128/m64bcst",
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
						.Mm = 0b1,
						.Pp = 0b0,
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
						.Value = 0x78,
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
			.IntelMnemonic = "vcvttpd2udq",
			.GasMnemonic = "vcvttpd2udq",
			.Description = "vcvttpd2udq xmm{k}{z}, m256/m64bcst",
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
						.Pp = 0b0,
						.W = true,
						.Ll = UINT64_C(0x1),
						.Rr = {OperandType::XmmKz},
						.Bb = {OperandType::M256M64Bcst},
						.X = {OperandType::M256M64Bcst},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M256M64Bcst},
						.Aaa = {OperandType::XmmKz},
						.Z = {OperandType::XmmKz},
						.Disp8xN = 32,
					},
					OpCode
					{
						.Value = 0x78,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M256M64Bcst},
						.Rm = {OperandType::M256M64Bcst},
						.Reg = {OperandType::XmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvttpd2udq",
			.GasMnemonic = "vcvttpd2udq",
			.Description = "vcvttpd2udq ymm{k}{z}, m512/m64bcst",
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
						.Pp = 0b0,
						.W = true,
						.Ll = UINT64_C(0x2),
						.Rr = {OperandType::YmmKz},
						.Bb = {OperandType::M512M64Bcst},
						.X = {OperandType::M512M64Bcst},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M512M64Bcst},
						.Aaa = {OperandType::YmmKz},
						.Z = {OperandType::YmmKz},
						.Disp8xN = 64,
					},
					OpCode
					{
						.Value = 0x78,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M512M64Bcst},
						.Rm = {OperandType::M512M64Bcst},
						.Reg = {OperandType::YmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvttpd2udq",
			.GasMnemonic = "vcvttpd2udq",
			.Description = "vcvttpd2udq xmm{k}{z}, xmm",
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
						.Mm = 0b1,
						.Pp = 0b0,
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
			.IntelMnemonic = "vcvttpd2udq",
			.GasMnemonic = "vcvttpd2udq",
			.Description = "vcvttpd2udq xmm{k}{z}, ymm",
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
						.Mm = 0b1,
						.Pp = 0b0,
						.W = true,
						.Ll = UINT64_C(0x1),
						.Rr = {OperandType::XmmKz},
						.Bb = {OperandType::Ymm},
						.X = {OperandType::Ymm},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Ymm},
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
						.Rm = {OperandType::Ymm},
						.Reg = {OperandType::XmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvttpd2udq",
			.GasMnemonic = "vcvttpd2udq",
			.Description = "vcvttpd2udq ymm{k}{z}, zmm, {sae}",
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
						.Mm = 0b1,
						.Pp = 0b0,
						.W = true,
						.Ll = UINT64_C(0x2),
						.Rr = {OperandType::YmmKz},
						.Bb = {OperandType::Zmm},
						.X = {OperandType::Zmm},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Zmm},
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
						.Rm = {OperandType::Zmm},
						.Reg = {OperandType::YmmKz},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "vcvttpd2uqq",
			.GasMnemonic = "vcvttpd2uqq",
			.Description = "vcvttpd2uqq xmm{k}{z}, m128/m64bcst",
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
				IsaExtension::Avx512Dq,
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
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M128M64Bcst},
						.Aaa = {OperandType::XmmKz},
						.Z = {OperandType::XmmKz},
						.Disp8xN = 16,
					},
					OpCode
					{
						.Value = 0x78,
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
			.IntelMnemonic = "vcvttpd2uqq",
			.GasMnemonic = "vcvttpd2uqq",
			.Description = "vcvttpd2uqq ymm{k}{z}, m256/m64bcst",
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
				IsaExtension::Avx512Dq,
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
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M256M64Bcst},
						.Aaa = {OperandType::YmmKz},
						.Z = {OperandType::YmmKz},
						.Disp8xN = 32,
					},
					OpCode
					{
						.Value = 0x78,
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
			.IntelMnemonic = "vcvttpd2uqq",
			.GasMnemonic = "vcvttpd2uqq",
			.Description = "vcvttpd2uqq zmm{k}{z}, m512/m64bcst",
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
				IsaExtension::Avx512Dq,
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
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M512M64Bcst},
						.Aaa = {OperandType::ZmmKz},
						.Z = {OperandType::ZmmKz},
						.Disp8xN = 64,
					},
					OpCode
					{
						.Value = 0x78,
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
			.IntelMnemonic = "vcvttpd2uqq",
			.GasMnemonic = "vcvttpd2uqq",
			.Description = "vcvttpd2uqq xmm{k}{z}, xmm",
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
				IsaExtension::Avx512Dq,
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
			.IntelMnemonic = "vcvttpd2uqq",
			.GasMnemonic = "vcvttpd2uqq",
			.Description = "vcvttpd2uqq ymm{k}{z}, ymm",
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
				IsaExtension::Avx512Dq,
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
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Ymm},
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
						.Rm = {OperandType::Ymm},
						.Reg = {OperandType::YmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvttpd2uqq",
			.GasMnemonic = "vcvttpd2uqq",
			.Description = "vcvttpd2uqq zmm{k}{z}, zmm, {sae}",
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
				IsaExtension::Avx512Dq,
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
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Zmm},
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
			.IntelMnemonic = "vcvttps2dq",
			.GasMnemonic = "vcvttps2dq",
			.Description = "vcvttps2dq xmm{k}{z}, m128/m32bcst",
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
						.Mm = 0b1,
						.Pp = 0b10,
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
						.Value = 0x5b,
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
			.IntelMnemonic = "vcvttps2dq",
			.GasMnemonic = "vcvttps2dq",
			.Description = "vcvttps2dq ymm{k}{z}, m256/m32bcst",
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
						.Mm = 0b1,
						.Pp = 0b10,
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
						.Value = 0x5b,
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
			.IntelMnemonic = "vcvttps2dq",
			.GasMnemonic = "vcvttps2dq",
			.Description = "vcvttps2dq zmm{k}{z}, m512/m32bcst",
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
						.Mm = 0b1,
						.Pp = 0b10,
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
						.Value = 0x5b,
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
			.IntelMnemonic = "vcvttps2dq",
			.GasMnemonic = "vcvttps2dq",
			.Description = "vcvttps2dq xmm{k}{z}, xmm",
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
						.Mm = 0b1,
						.Pp = 0b10,
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
						.Value = 0x5b,
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
			.IntelMnemonic = "vcvttps2dq",
			.GasMnemonic = "vcvttps2dq",
			.Description = "vcvttps2dq ymm{k}{z}, ymm",
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
						.Mm = 0b1,
						.Pp = 0b10,
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
						.Value = 0x5b,
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
			.IntelMnemonic = "vcvttps2dq",
			.GasMnemonic = "vcvttps2dq",
			.Description = "vcvttps2dq xmm, xmm",
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
						.Mmmmm = 0b1,
						.Pp = 0b10,
						.W = false,
						.L = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x5b,
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
			.IntelMnemonic = "vcvttps2dq",
			.GasMnemonic = "vcvttps2dq",
			.Description = "vcvttps2dq xmm, m128",
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
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x5b,
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
			.IntelMnemonic = "vcvttps2dq",
			.GasMnemonic = "vcvttps2dq",
			.Description = "vcvttps2dq ymm, ymm",
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
						.L = true,
						.R = {OperandType::Ymm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Ymm},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x5b,
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
			.IntelMnemonic = "vcvttps2dq",
			.GasMnemonic = "vcvttps2dq",
			.Description = "vcvttps2dq ymm, m256",
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
						.L = true,
						.R = {OperandType::Ymm},
						.X = {OperandType::M256},
						.B = {OperandType::M256},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x5b,
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
			.IntelMnemonic = "vcvttps2dq",
			.GasMnemonic = "vcvttps2dq",
			.Description = "vcvttps2dq zmm{k}{z}, zmm, {sae}",
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
						.Mm = 0b1,
						.Pp = 0b10,
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
						.Value = 0x5b,
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
			.IntelMnemonic = "vcvttps2qq",
			.GasMnemonic = "vcvttps2qq",
			.Description = "vcvttps2qq xmm{k}{z}, m64/m32bcst",
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
					.Type = OperandType::M64M32Bcst,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
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
						.Mm = 0b1,
						.Pp = 0b1,
						.W = false,
						.Ll = UINT64_C(0x0),
						.Rr = {OperandType::XmmKz},
						.Bb = {OperandType::M64M32Bcst},
						.X = {OperandType::M64M32Bcst},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M64M32Bcst},
						.Aaa = {OperandType::XmmKz},
						.Z = {OperandType::XmmKz},
						.Disp8xN = 8,
					},
					OpCode
					{
						.Value = 0x7a,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64M32Bcst},
						.Rm = {OperandType::M64M32Bcst},
						.Reg = {OperandType::XmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvttps2qq",
			.GasMnemonic = "vcvttps2qq",
			.Description = "vcvttps2qq ymm{k}{z}, m128/m32bcst",
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
				IsaExtension::Avx512Dq,
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
						.Bb = {OperandType::M128M32Bcst},
						.X = {OperandType::M128M32Bcst},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M128M32Bcst},
						.Aaa = {OperandType::YmmKz},
						.Z = {OperandType::YmmKz},
						.Disp8xN = 16,
					},
					OpCode
					{
						.Value = 0x7a,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128M32Bcst},
						.Rm = {OperandType::M128M32Bcst},
						.Reg = {OperandType::YmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvttps2qq",
			.GasMnemonic = "vcvttps2qq",
			.Description = "vcvttps2qq zmm{k}{z}, m256/m32bcst",
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
				IsaExtension::Avx512Dq,
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
						.Bb = {OperandType::M256M32Bcst},
						.X = {OperandType::M256M32Bcst},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M256M32Bcst},
						.Aaa = {OperandType::ZmmKz},
						.Z = {OperandType::ZmmKz},
						.Disp8xN = 32,
					},
					OpCode
					{
						.Value = 0x7a,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M256M32Bcst},
						.Rm = {OperandType::M256M32Bcst},
						.Reg = {OperandType::ZmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvttps2qq",
			.GasMnemonic = "vcvttps2qq",
			.Description = "vcvttps2qq xmm{k}{z}, xmm",
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
				IsaExtension::Avx512Dq,
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
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
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
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::XmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvttps2qq",
			.GasMnemonic = "vcvttps2qq",
			.Description = "vcvttps2qq ymm{k}{z}, xmm",
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
				IsaExtension::Avx512Dq,
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
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
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
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::YmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvttps2qq",
			.GasMnemonic = "vcvttps2qq",
			.Description = "vcvttps2qq zmm{k}{z}, ymm, {sae}",
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
				IsaExtension::Avx512Dq,
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
						.Value = 0x7a,
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
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "vcvttps2udq",
			.GasMnemonic = "vcvttps2udq",
			.Description = "vcvttps2udq xmm{k}{z}, m128/m32bcst",
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
						.Mm = 0b1,
						.Pp = 0b0,
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
						.Value = 0x78,
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
			.IntelMnemonic = "vcvttps2udq",
			.GasMnemonic = "vcvttps2udq",
			.Description = "vcvttps2udq ymm{k}{z}, m256/m32bcst",
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
						.Mm = 0b1,
						.Pp = 0b0,
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
						.Value = 0x78,
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
			.IntelMnemonic = "vcvttps2udq",
			.GasMnemonic = "vcvttps2udq",
			.Description = "vcvttps2udq zmm{k}{z}, m512/m32bcst",
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
						.Mm = 0b1,
						.Pp = 0b0,
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
						.Value = 0x78,
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
			.IntelMnemonic = "vcvttps2udq",
			.GasMnemonic = "vcvttps2udq",
			.Description = "vcvttps2udq xmm{k}{z}, xmm",
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
						.Mm = 0b1,
						.Pp = 0b0,
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
			.IntelMnemonic = "vcvttps2udq",
			.GasMnemonic = "vcvttps2udq",
			.Description = "vcvttps2udq ymm{k}{z}, ymm",
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
						.Mm = 0b1,
						.Pp = 0b0,
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
						.Value = 0x78,
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
			.IntelMnemonic = "vcvttps2udq",
			.GasMnemonic = "vcvttps2udq",
			.Description = "vcvttps2udq zmm{k}{z}, zmm, {sae}",
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
						.Mm = 0b1,
						.Pp = 0b0,
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
						.Value = 0x78,
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
			.IntelMnemonic = "vcvttps2uqq",
			.GasMnemonic = "vcvttps2uqq",
			.Description = "vcvttps2uqq xmm{k}{z}, m64/m32bcst",
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
					.Type = OperandType::M64M32Bcst,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
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
						.Mm = 0b1,
						.Pp = 0b1,
						.W = false,
						.Ll = UINT64_C(0x0),
						.Rr = {OperandType::XmmKz},
						.Bb = {OperandType::M64M32Bcst},
						.X = {OperandType::M64M32Bcst},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M64M32Bcst},
						.Aaa = {OperandType::XmmKz},
						.Z = {OperandType::XmmKz},
						.Disp8xN = 8,
					},
					OpCode
					{
						.Value = 0x78,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64M32Bcst},
						.Rm = {OperandType::M64M32Bcst},
						.Reg = {OperandType::XmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvttps2uqq",
			.GasMnemonic = "vcvttps2uqq",
			.Description = "vcvttps2uqq ymm{k}{z}, m128/m32bcst",
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
				IsaExtension::Avx512Dq,
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
						.Bb = {OperandType::M128M32Bcst},
						.X = {OperandType::M128M32Bcst},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M128M32Bcst},
						.Aaa = {OperandType::YmmKz},
						.Z = {OperandType::YmmKz},
						.Disp8xN = 16,
					},
					OpCode
					{
						.Value = 0x78,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128M32Bcst},
						.Rm = {OperandType::M128M32Bcst},
						.Reg = {OperandType::YmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvttps2uqq",
			.GasMnemonic = "vcvttps2uqq",
			.Description = "vcvttps2uqq zmm{k}{z}, m256/m32bcst",
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
				IsaExtension::Avx512Dq,
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
						.Bb = {OperandType::M256M32Bcst},
						.X = {OperandType::M256M32Bcst},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M256M32Bcst},
						.Aaa = {OperandType::ZmmKz},
						.Z = {OperandType::ZmmKz},
						.Disp8xN = 32,
					},
					OpCode
					{
						.Value = 0x78,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M256M32Bcst},
						.Rm = {OperandType::M256M32Bcst},
						.Reg = {OperandType::ZmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvttps2uqq",
			.GasMnemonic = "vcvttps2uqq",
			.Description = "vcvttps2uqq xmm{k}{z}, xmm",
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
				IsaExtension::Avx512Dq,
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
			.IntelMnemonic = "vcvttps2uqq",
			.GasMnemonic = "vcvttps2uqq",
			.Description = "vcvttps2uqq ymm{k}{z}, xmm",
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
				IsaExtension::Avx512Dq,
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
			.IntelMnemonic = "vcvttps2uqq",
			.GasMnemonic = "vcvttps2uqq",
			.Description = "vcvttps2uqq zmm{k}{z}, ymm, {sae}",
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
				IsaExtension::Avx512Dq,
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
						.Value = 0x78,
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
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "vcvttsd2si",
			.GasMnemonic = "vcvttsd2si",
			.Description = "vcvttsd2si r32, xmm",
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
						.R = {OperandType::R32},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x2c,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::R32},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvttsd2si",
			.GasMnemonic = "vcvttsd2si",
			.Description = "vcvttsd2si r32, m64",
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
						.R = {OperandType::R32},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x2c,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::R32},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvttsd2si",
			.GasMnemonic = "vcvttsd2si",
			.Description = "vcvttsd2si r32, m64",
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
						.W = false,
						.Ll = UINT64_C(0x0),
						.Rr = {OperandType::R32},
						.Bb = {OperandType::M64},
						.X = {OperandType::M64},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M64},
						.Aaa = {UINT64_C(0x0)},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 8,
					},
					OpCode
					{
						.Value = 0x2c,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::R32},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvttsd2si",
			.GasMnemonic = "vcvttsd2si",
			.Description = "vcvttsd2si r64, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
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
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
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
						.W = true,
						.L = false,
						.R = {OperandType::R64},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x2c,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::R64},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvttsd2si",
			.GasMnemonic = "vcvttsd2si",
			.Description = "vcvttsd2si r64, m64",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
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
						.W = true,
						.L = false,
						.R = {OperandType::R64},
						.X = {OperandType::M64},
						.B = {OperandType::M64},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x2c,
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
			.IntelMnemonic = "vcvttsd2si",
			.GasMnemonic = "vcvttsd2si",
			.Description = "vcvttsd2si r64, m64",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
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
						.Rr = {OperandType::R64},
						.Bb = {OperandType::M64},
						.X = {OperandType::M64},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M64},
						.Aaa = {UINT64_C(0x0)},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 8,
					},
					OpCode
					{
						.Value = 0x2c,
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
			.IntelMnemonic = "vcvttsd2si",
			.GasMnemonic = "vcvttsd2si",
			.Description = "vcvttsd2si r32, xmm, {sae}",
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
						.Mm = 0b1,
						.Pp = 0b11,
						.W = false,
						.Ll = UINT64_C(0x0),
						.Rr = {OperandType::R32},
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
						.Value = 0x2c,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::R32},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvttsd2si",
			.GasMnemonic = "vcvttsd2si",
			.Description = "vcvttsd2si r64, xmm, {sae}",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
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
						.Mm = 0b1,
						.Pp = 0b11,
						.W = true,
						.Ll = UINT64_C(0x0),
						.Rr = {OperandType::R64},
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
						.Value = 0x2c,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
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
			.IntelMnemonic = "vcvttsd2usi",
			.GasMnemonic = "vcvttsd2usi",
			.Description = "vcvttsd2usi r32, m64",
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
						.W = false,
						.Ll = UINT64_C(0x0),
						.Rr = {OperandType::R32},
						.Bb = {OperandType::M64},
						.X = {OperandType::M64},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M64},
						.Aaa = {UINT64_C(0x0)},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 8,
					},
					OpCode
					{
						.Value = 0x78,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64},
						.Rm = {OperandType::M64},
						.Reg = {OperandType::R32},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvttsd2usi",
			.GasMnemonic = "vcvttsd2usi",
			.Description = "vcvttsd2usi r64, m64",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
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
						.Rr = {OperandType::R64},
						.Bb = {OperandType::M64},
						.X = {OperandType::M64},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M64},
						.Aaa = {UINT64_C(0x0)},
						.Z = {UINT64_C(0x0)},
						.Disp8xN = 8,
					},
					OpCode
					{
						.Value = 0x78,
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
			.IntelMnemonic = "vcvttsd2usi",
			.GasMnemonic = "vcvttsd2usi",
			.Description = "vcvttsd2usi r32, xmm, {sae}",
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
						.Mm = 0b1,
						.Pp = 0b11,
						.W = false,
						.Ll = UINT64_C(0x0),
						.Rr = {OperandType::R32},
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
						.Value = 0x78,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::R32},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvttsd2usi",
			.GasMnemonic = "vcvttsd2usi",
			.Description = "vcvttsd2usi r64, xmm, {sae}",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
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
						.Mm = 0b1,
						.Pp = 0b11,
						.W = true,
						.Ll = UINT64_C(0x0),
						.Rr = {OperandType::R64},
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
						.Value = 0x78,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
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
			.IntelMnemonic = "vcvttss2si",
			.GasMnemonic = "vcvttss2si",
			.Description = "vcvttss2si r32, xmm",
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
						.R = {OperandType::R32},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x2c,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::R32},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvttss2si",
			.GasMnemonic = "vcvttss2si",
			.Description = "vcvttss2si r32, m32",
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
						.R = {OperandType::R32},
						.X = {OperandType::M32},
						.B = {OperandType::M32},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x2c,
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
			.IntelMnemonic = "vcvttss2si",
			.GasMnemonic = "vcvttss2si",
			.Description = "vcvttss2si r32, m32",
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
						.Rr = {OperandType::R32},
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
						.Value = 0x2c,
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
			.IntelMnemonic = "vcvttss2si",
			.GasMnemonic = "vcvttss2si",
			.Description = "vcvttss2si r64, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
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
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
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
						.W = true,
						.L = false,
						.R = {OperandType::R64},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x2c,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::R64},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvttss2si",
			.GasMnemonic = "vcvttss2si",
			.Description = "vcvttss2si r64, m32",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
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
						.W = true,
						.L = false,
						.R = {OperandType::R64},
						.X = {OperandType::M32},
						.B = {OperandType::M32},
						.Vvvv = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x2c,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M32},
						.Rm = {OperandType::M32},
						.Reg = {OperandType::R64},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvttss2si",
			.GasMnemonic = "vcvttss2si",
			.Description = "vcvttss2si r64, m32",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
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
						.W = true,
						.Ll = UINT64_C(0x0),
						.Rr = {OperandType::R64},
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
						.Value = 0x2c,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M32},
						.Rm = {OperandType::M32},
						.Reg = {OperandType::R64},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvttss2si",
			.GasMnemonic = "vcvttss2si",
			.Description = "vcvttss2si r32, xmm, {sae}",
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
						.Mm = 0b1,
						.Pp = 0b10,
						.W = false,
						.Ll = UINT64_C(0x0),
						.Rr = {OperandType::R32},
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
						.Value = 0x2c,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::R32},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvttss2si",
			.GasMnemonic = "vcvttss2si",
			.Description = "vcvttss2si r64, xmm, {sae}",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
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
						.Mm = 0b1,
						.Pp = 0b10,
						.W = true,
						.Ll = UINT64_C(0x0),
						.Rr = {OperandType::R64},
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
						.Value = 0x2c,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
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
			.IntelMnemonic = "vcvttss2usi",
			.GasMnemonic = "vcvttss2usi",
			.Description = "vcvttss2usi r32, m32",
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
						.Rr = {OperandType::R32},
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
						.Value = 0x78,
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
			.IntelMnemonic = "vcvttss2usi",
			.GasMnemonic = "vcvttss2usi",
			.Description = "vcvttss2usi r64, m32",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
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
						.W = true,
						.Ll = UINT64_C(0x0),
						.Rr = {OperandType::R64},
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
						.Value = 0x78,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M32},
						.Rm = {OperandType::M32},
						.Reg = {OperandType::R64},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvttss2usi",
			.GasMnemonic = "vcvttss2usi",
			.Description = "vcvttss2usi r32, xmm, {sae}",
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
						.Mm = 0b1,
						.Pp = 0b10,
						.W = false,
						.Ll = UINT64_C(0x0),
						.Rr = {OperandType::R32},
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
						.Value = 0x78,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::R32},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvttss2usi",
			.GasMnemonic = "vcvttss2usi",
			.Description = "vcvttss2usi r64, xmm, {sae}",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Avx,
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
						.Mm = 0b1,
						.Pp = 0b10,
						.W = true,
						.Ll = UINT64_C(0x0),
						.Rr = {OperandType::R64},
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
						.Value = 0x78,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
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
			.IntelMnemonic = "vcvtudq2pd",
			.GasMnemonic = "vcvtudq2pd",
			.Description = "vcvtudq2pd xmm{k}{z}, m64/m32bcst",
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
					.Type = OperandType::M64M32Bcst,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
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
						.Pp = 0b10,
						.W = false,
						.Ll = UINT64_C(0x0),
						.Rr = {OperandType::XmmKz},
						.Bb = {OperandType::M64M32Bcst},
						.X = {OperandType::M64M32Bcst},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M64M32Bcst},
						.Aaa = {OperandType::XmmKz},
						.Z = {OperandType::XmmKz},
						.Disp8xN = 8,
					},
					OpCode
					{
						.Value = 0x7a,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M64M32Bcst},
						.Rm = {OperandType::M64M32Bcst},
						.Reg = {OperandType::XmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvtudq2pd",
			.GasMnemonic = "vcvtudq2pd",
			.Description = "vcvtudq2pd ymm{k}{z}, m128/m32bcst",
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
						.Pp = 0b10,
						.W = false,
						.Ll = UINT64_C(0x1),
						.Rr = {OperandType::YmmKz},
						.Bb = {OperandType::M128M32Bcst},
						.X = {OperandType::M128M32Bcst},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M128M32Bcst},
						.Aaa = {OperandType::YmmKz},
						.Z = {OperandType::YmmKz},
						.Disp8xN = 16,
					},
					OpCode
					{
						.Value = 0x7a,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128M32Bcst},
						.Rm = {OperandType::M128M32Bcst},
						.Reg = {OperandType::YmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvtudq2pd",
			.GasMnemonic = "vcvtudq2pd",
			.Description = "vcvtudq2pd zmm{k}{z}, m256/m32bcst",
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
						.Ll = UINT64_C(0x2),
						.Rr = {OperandType::ZmmKz},
						.Bb = {OperandType::M256M32Bcst},
						.X = {OperandType::M256M32Bcst},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M256M32Bcst},
						.Aaa = {OperandType::ZmmKz},
						.Z = {OperandType::ZmmKz},
						.Disp8xN = 32,
					},
					OpCode
					{
						.Value = 0x7a,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M256M32Bcst},
						.Rm = {OperandType::M256M32Bcst},
						.Reg = {OperandType::ZmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvtudq2pd",
			.GasMnemonic = "vcvtudq2pd",
			.Description = "vcvtudq2pd xmm{k}{z}, xmm",
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
						.Mm = 0b1,
						.Pp = 0b10,
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
						.Value = 0x7a,
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
			.IntelMnemonic = "vcvtudq2pd",
			.GasMnemonic = "vcvtudq2pd",
			.Description = "vcvtudq2pd ymm{k}{z}, xmm",
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
						.Mm = 0b1,
						.Pp = 0b10,
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
						.Value = 0x7a,
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
			.IntelMnemonic = "vcvtudq2pd",
			.GasMnemonic = "vcvtudq2pd",
			.Description = "vcvtudq2pd zmm{k}{z}, ymm",
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
						.Mm = 0b1,
						.Pp = 0b10,
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
						.Value = 0x7a,
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
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "vcvtudq2ps",
			.GasMnemonic = "vcvtudq2ps",
			.Description = "vcvtudq2ps xmm{k}{z}, m128/m32bcst",
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
						.Mm = 0b1,
						.Pp = 0b11,
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
						.Value = 0x7a,
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
			.IntelMnemonic = "vcvtudq2ps",
			.GasMnemonic = "vcvtudq2ps",
			.Description = "vcvtudq2ps ymm{k}{z}, m256/m32bcst",
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
						.Mm = 0b1,
						.Pp = 0b11,
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
						.Value = 0x7a,
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
			.IntelMnemonic = "vcvtudq2ps",
			.GasMnemonic = "vcvtudq2ps",
			.Description = "vcvtudq2ps zmm{k}{z}, m512/m32bcst",
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
						.Mm = 0b1,
						.Pp = 0b11,
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
						.Value = 0x7a,
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
			.IntelMnemonic = "vcvtudq2ps",
			.GasMnemonic = "vcvtudq2ps",
			.Description = "vcvtudq2ps xmm{k}{z}, xmm",
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
						.Mm = 0b1,
						.Pp = 0b11,
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
						.Value = 0x7a,
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
			.IntelMnemonic = "vcvtudq2ps",
			.GasMnemonic = "vcvtudq2ps",
			.Description = "vcvtudq2ps ymm{k}{z}, ymm",
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
						.Mm = 0b1,
						.Pp = 0b11,
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
						.Value = 0x7a,
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
			.IntelMnemonic = "vcvtudq2ps",
			.GasMnemonic = "vcvtudq2ps",
			.Description = "vcvtudq2ps zmm{k}{z}, zmm, {er}",
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
						.W = false,
						.Ll = OperandType::Er,
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
						.Value = 0x7a,
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
			.IntelMnemonic = "vcvtuqq2pd",
			.GasMnemonic = "vcvtuqq2pd",
			.Description = "vcvtuqq2pd xmm{k}{z}, m128/m64bcst",
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
				IsaExtension::Avx512Dq,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Evex
					{
						.Mm = 0b1,
						.Pp = 0b10,
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
						.Value = 0x7a,
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
			.IntelMnemonic = "vcvtuqq2pd",
			.GasMnemonic = "vcvtuqq2pd",
			.Description = "vcvtuqq2pd ymm{k}{z}, m256/m64bcst",
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
				IsaExtension::Avx512Dq,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Evex
					{
						.Mm = 0b1,
						.Pp = 0b10,
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
						.Value = 0x7a,
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
			.IntelMnemonic = "vcvtuqq2pd",
			.GasMnemonic = "vcvtuqq2pd",
			.Description = "vcvtuqq2pd zmm{k}{z}, m512/m64bcst",
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
				IsaExtension::Avx512Dq,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Evex
					{
						.Mm = 0b1,
						.Pp = 0b10,
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
						.Value = 0x7a,
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
			.IntelMnemonic = "vcvtuqq2pd",
			.GasMnemonic = "vcvtuqq2pd",
			.Description = "vcvtuqq2pd xmm{k}{z}, xmm",
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
				IsaExtension::Avx512Dq,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Evex
					{
						.Mm = 0b1,
						.Pp = 0b10,
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
						.Value = 0x7a,
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
			.IntelMnemonic = "vcvtuqq2pd",
			.GasMnemonic = "vcvtuqq2pd",
			.Description = "vcvtuqq2pd ymm{k}{z}, ymm",
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
				IsaExtension::Avx512Dq,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Evex
					{
						.Mm = 0b1,
						.Pp = 0b10,
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
						.Value = 0x7a,
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
			.IntelMnemonic = "vcvtuqq2pd",
			.GasMnemonic = "vcvtuqq2pd",
			.Description = "vcvtuqq2pd zmm{k}{z}, zmm, {er}",
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
				IsaExtension::Avx512Dq,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Evex
					{
						.Mm = 0b1,
						.Pp = 0b10,
						.W = true,
						.Ll = OperandType::Er,
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
						.Value = 0x7a,
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
			.IntelMnemonic = "vcvtuqq2ps",
			.GasMnemonic = "vcvtuqq2ps",
			.Description = "vcvtuqq2ps xmm{k}{z}, m128/m64bcst",
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
				IsaExtension::Avx512Dq,
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
						.Value = 0x7a,
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
			.IntelMnemonic = "vcvtuqq2ps",
			.GasMnemonic = "vcvtuqq2ps",
			.Description = "vcvtuqq2ps xmm{k}{z}, m256/m64bcst",
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
						.Mm = 0b1,
						.Pp = 0b11,
						.W = true,
						.Ll = UINT64_C(0x1),
						.Rr = {OperandType::XmmKz},
						.Bb = {OperandType::M256M64Bcst},
						.X = {OperandType::M256M64Bcst},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M256M64Bcst},
						.Aaa = {OperandType::XmmKz},
						.Z = {OperandType::XmmKz},
						.Disp8xN = 32,
					},
					OpCode
					{
						.Value = 0x7a,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M256M64Bcst},
						.Rm = {OperandType::M256M64Bcst},
						.Reg = {OperandType::XmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvtuqq2ps",
			.GasMnemonic = "vcvtuqq2ps",
			.Description = "vcvtuqq2ps ymm{k}{z}, m512/m64bcst",
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
						.Mm = 0b1,
						.Pp = 0b11,
						.W = true,
						.Ll = UINT64_C(0x2),
						.Rr = {OperandType::YmmKz},
						.Bb = {OperandType::M512M64Bcst},
						.X = {OperandType::M512M64Bcst},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::M512M64Bcst},
						.Aaa = {OperandType::YmmKz},
						.Z = {OperandType::YmmKz},
						.Disp8xN = 64,
					},
					OpCode
					{
						.Value = 0x7a,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M512M64Bcst},
						.Rm = {OperandType::M512M64Bcst},
						.Reg = {OperandType::YmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvtuqq2ps",
			.GasMnemonic = "vcvtuqq2ps",
			.Description = "vcvtuqq2ps xmm{k}{z}, xmm",
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
				IsaExtension::Avx512Dq,
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
						.Value = 0x7a,
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
			.IntelMnemonic = "vcvtuqq2ps",
			.GasMnemonic = "vcvtuqq2ps",
			.Description = "vcvtuqq2ps xmm{k}{z}, ymm",
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
				IsaExtension::Avx512Dq,
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
						.Ll = UINT64_C(0x1),
						.Rr = {OperandType::XmmKz},
						.Bb = {OperandType::Ymm},
						.X = {OperandType::Ymm},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Ymm},
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
						.Rm = {OperandType::Ymm},
						.Reg = {OperandType::XmmKz},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvtuqq2ps",
			.GasMnemonic = "vcvtuqq2ps",
			.Description = "vcvtuqq2ps ymm{k}{z}, zmm, {er}",
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
				IsaExtension::Avx512Dq,
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
						.Rr = {OperandType::YmmKz},
						.Bb = {OperandType::Zmm},
						.X = {OperandType::Zmm},
						.Vvvv = {UINT64_C(0x0)},
						.V = {UINT64_C(0x0)},
						.B = {OperandType::Zmm},
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
						.Rm = {OperandType::Zmm},
						.Reg = {OperandType::YmmKz},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "vcvtusi2sd",
			.GasMnemonic = "vcvtusi2sd",
			.Description = "vcvtusi2sd xmm, xmm, r32",
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
						.Value = 0x7b,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R32},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvtusi2sd",
			.GasMnemonic = "vcvtusi2sd",
			.Description = "vcvtusi2sd xmm, xmm, m32",
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
						.Value = 0x7b,
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
			.IntelMnemonic = "vcvtusi2sd",
			.GasMnemonic = "vcvtusi2sd",
			.Description = "vcvtusi2sd xmm, xmm, m64",
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
						.Value = 0x7b,
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
			.IntelMnemonic = "vcvtusi2sd",
			.GasMnemonic = "vcvtusi2sd",
			.Description = "vcvtusi2sd xmm, xmm, r64, {er}",
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
						.Value = 0x7b,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R64},
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
			.IntelMnemonic = "vcvtusi2ss",
			.GasMnemonic = "vcvtusi2ss",
			.Description = "vcvtusi2ss xmm, xmm, m32",
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
						.Value = 0x7b,
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
			.IntelMnemonic = "vcvtusi2ss",
			.GasMnemonic = "vcvtusi2ss",
			.Description = "vcvtusi2ss xmm, xmm, m64",
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
						.Value = 0x7b,
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
			.IntelMnemonic = "vcvtusi2ss",
			.GasMnemonic = "vcvtusi2ss",
			.Description = "vcvtusi2ss xmm, xmm, r32, {er}",
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
						.Value = 0x7b,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R32},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vcvtusi2ss",
			.GasMnemonic = "vcvtusi2ss",
			.Description = "vcvtusi2ss xmm, xmm, r64, {er}",
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
						.W = true,
						.Ll = OperandType::Er,
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
						.Value = 0x7b,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R64},
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
			.IntelMnemonic = "vdbpsadbw",
			.GasMnemonic = "vdbpsadbw",
			.Description = "vdbpsadbw xmm{k}{z}, xmm, xmm, imm8",
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
					.Type = OperandType::Imm8,
					.IsInput = false,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
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
						.Value = 0x42,
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
			.IntelMnemonic = "vdbpsadbw",
			.GasMnemonic = "vdbpsadbw",
			.Description = "vdbpsadbw xmm{k}{z}, xmm, m128, imm8",
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
				Operand
				{
					.Type = OperandType::Imm8,
					.IsInput = false,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
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
						.Value = 0x42,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
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
			.IntelMnemonic = "vdbpsadbw",
			.GasMnemonic = "vdbpsadbw",
			.Description = "vdbpsadbw ymm{k}{z}, ymm, ymm, imm8",
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
				Operand
				{
					.Type = OperandType::Imm8,
					.IsInput = false,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
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
						.Value = 0x42,
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
			.IntelMnemonic = "vdbpsadbw",
			.GasMnemonic = "vdbpsadbw",
			.Description = "vdbpsadbw ymm{k}{z}, ymm, m256, imm8",
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
				Operand
				{
					.Type = OperandType::Imm8,
					.IsInput = false,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
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
						.Value = 0x42,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M256},
						.Rm = {OperandType::M256},
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
			.IntelMnemonic = "vdbpsadbw",
			.GasMnemonic = "vdbpsadbw",
			.Description = "vdbpsadbw zmm{k}{z}, zmm, zmm, imm8",
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
				Operand
				{
					.Type = OperandType::Imm8,
					.IsInput = false,
					.IsOutput = false,
					.ExtendedSize = 0
				},
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
						.Value = 0x42,
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
		InstructionVariation
		{
			.IntelMnemonic = "vdbpsadbw",
			.GasMnemonic = "vdbpsadbw",
			.Description = "vdbpsadbw zmm{k}{z}, zmm, m512, imm8",
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
				Operand
				{
					.Type = OperandType::Imm8,
					.IsInput = false,
					.IsOutput = false,
					.ExtendedSize = 0
				},
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
						.Value = 0x42,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M512},
						.Rm = {OperandType::M512},
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
			.IntelMnemonic = "vdivpd",
			.GasMnemonic = "vdivpd",
			.Description = "vdivpd xmm{k}{z}, xmm, m128/m64bcst",
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
						.Value = 0x5e,
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
			.IntelMnemonic = "vdivpd",
			.GasMnemonic = "vdivpd",
			.Description = "vdivpd xmm{k}{z}, xmm, xmm",
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
		InstructionVariation
		{
			.IntelMnemonic = "vdivpd",
			.GasMnemonic = "vdivpd",
			.Description = "vdivpd ymm{k}{z}, ymm, m256/m64bcst",
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
						.Value = 0x5e,
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
			.IntelMnemonic = "vdivpd",
			.GasMnemonic = "vdivpd",
			.Description = "vdivpd ymm{k}{z}, ymm, ymm",
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
						.Value = 0x5e,
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
			.IntelMnemonic = "vdivpd",
			.GasMnemonic = "vdivpd",
			.Description = "vdivpd zmm{k}{z}, zmm, m512/m64bcst",
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
						.Value = 0x5e,
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
			.IntelMnemonic = "vdivpd",
			.GasMnemonic = "vdivpd",
			.Description = "vdivpd xmm, xmm, xmm",
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
			.IntelMnemonic = "vdivpd",
			.GasMnemonic = "vdivpd",
			.Description = "vdivpd xmm, xmm, m128",
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
						.Value = 0x5e,
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
			.IntelMnemonic = "vdivpd",
			.GasMnemonic = "vdivpd",
			.Description = "vdivpd ymm, ymm, ymm",
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
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vdivpd",
			.GasMnemonic = "vdivpd",
			.Description = "vdivpd ymm, ymm, m256",
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
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "vdivpd",
			.GasMnemonic = "vdivpd",
			.Description = "vdivpd zmm{k}{z}, zmm, zmm, {er}",
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
						.Value = 0x5e,
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
			.IntelMnemonic = "vdivps",
			.GasMnemonic = "vdivps",
			.Description = "vdivps xmm{k}{z}, xmm, m128/m32bcst",
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
						.Pp = 0b0,
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
						.Value = 0x5e,
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
			.IntelMnemonic = "vdivps",
			.GasMnemonic = "vdivps",
			.Description = "vdivps xmm{k}{z}, xmm, xmm",
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
						.Pp = 0b0,
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
		InstructionVariation
		{
			.IntelMnemonic = "vdivps",
			.GasMnemonic = "vdivps",
			.Description = "vdivps ymm{k}{z}, ymm, m256/m32bcst",
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
						.Pp = 0b0,
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
						.Value = 0x5e,
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
			.IntelMnemonic = "vdivps",
			.GasMnemonic = "vdivps",
			.Description = "vdivps ymm{k}{z}, ymm, ymm",
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
						.Pp = 0b0,
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
						.Value = 0x5e,
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
			.IntelMnemonic = "vdivps",
			.GasMnemonic = "vdivps",
			.Description = "vdivps zmm{k}{z}, zmm, m512/m32bcst",
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
						.Pp = 0b0,
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
						.Value = 0x5e,
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
			.IntelMnemonic = "vdivps",
			.GasMnemonic = "vdivps",
			.Description = "vdivps xmm, xmm, xmm",
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
			.IntelMnemonic = "vdivps",
			.GasMnemonic = "vdivps",
			.Description = "vdivps xmm, xmm, m128",
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
						.Value = 0x5e,
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
			.IntelMnemonic = "vdivps",
			.GasMnemonic = "vdivps",
			.Description = "vdivps ymm, ymm, ymm",
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
						.Value = 0x5e,
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
			.IntelMnemonic = "vdivps",
			.GasMnemonic = "vdivps",
			.Description = "vdivps ymm, ymm, m256",
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
						.Value = 0x5e,
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
			.IntelMnemonic = "vdivps",
			.GasMnemonic = "vdivps",
			.Description = "vdivps zmm{k}{z}, zmm, zmm, {er}",
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
						.Pp = 0b0,
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
						.Value = 0x5e,
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
