// File: Asm_x86_64_Jitdb31.cpp
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

#include "../../Include/Nominax/Asm_x86_64.hpp"

namespace Nominax::Assembler::X86_64
{
	NOX_NEVER_INLINE NOX_COLD auto GetVariationTable_31(std::pmr::monotonic_buffer_resource& allocator, std::pmr::vector<InstructionVariationPool>& out) -> void
	{
		std::pmr::vector<InstructionVariation> instruction {&allocator};
		instruction =
		{
			InstructionVariation
			{
				.IntelMnemonic = "vpmaxsw",
				.GasMnemonic = "vpmaxsw",
				.Description = "vpmaxsw xmm{k}{z}, xmm, xmm",
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
							.Value = 0xee,
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
				.IntelMnemonic = "vpmaxsw",
				.GasMnemonic = "vpmaxsw",
				.Description = "vpmaxsw xmm{k}{z}, xmm, m128",
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
							.Value = 0xee,
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
				.IntelMnemonic = "vpmaxsw",
				.GasMnemonic = "vpmaxsw",
				.Description = "vpmaxsw ymm{k}{z}, ymm, ymm",
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
							.Value = 0xee,
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
				.IntelMnemonic = "vpmaxsw",
				.GasMnemonic = "vpmaxsw",
				.Description = "vpmaxsw ymm{k}{z}, ymm, m256",
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
							.Value = 0xee,
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
				.IntelMnemonic = "vpmaxsw",
				.GasMnemonic = "vpmaxsw",
				.Description = "vpmaxsw zmm{k}{z}, zmm, zmm",
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
							.Value = 0xee,
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
				.IntelMnemonic = "vpmaxsw",
				.GasMnemonic = "vpmaxsw",
				.Description = "vpmaxsw zmm{k}{z}, zmm, m512",
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
							.Value = 0xee,
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
				.IntelMnemonic = "vpmaxsw",
				.GasMnemonic = "vpmaxsw",
				.Description = "vpmaxsw xmm, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Xmm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Xmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Xmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
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
							.Value = 0xee,
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
				.IntelMnemonic = "vpmaxsw",
				.GasMnemonic = "vpmaxsw",
				.Description = "vpmaxsw xmm, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Xmm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
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
							.Value = 0xee,
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
				.IntelMnemonic = "vpmaxsw",
				.GasMnemonic = "vpmaxsw",
				.Description = "vpmaxsw ymm, ymm, ymm",
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
							.Value = 0xee,
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
				.IntelMnemonic = "vpmaxsw",
				.GasMnemonic = "vpmaxsw",
				.Description = "vpmaxsw ymm, ymm, m256",
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
							.Value = 0xee,
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
				.IntelMnemonic = "vpmaxub",
				.GasMnemonic = "vpmaxub",
				.Description = "vpmaxub xmm{k}{z}, xmm, xmm",
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
							.Value = 0xde,
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
				.IntelMnemonic = "vpmaxub",
				.GasMnemonic = "vpmaxub",
				.Description = "vpmaxub xmm{k}{z}, xmm, m128",
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
							.Value = 0xde,
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
				.IntelMnemonic = "vpmaxub",
				.GasMnemonic = "vpmaxub",
				.Description = "vpmaxub ymm{k}{z}, ymm, ymm",
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
							.Value = 0xde,
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
				.IntelMnemonic = "vpmaxub",
				.GasMnemonic = "vpmaxub",
				.Description = "vpmaxub ymm{k}{z}, ymm, m256",
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
							.Value = 0xde,
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
				.IntelMnemonic = "vpmaxub",
				.GasMnemonic = "vpmaxub",
				.Description = "vpmaxub zmm{k}{z}, zmm, zmm",
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
							.Value = 0xde,
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
				.IntelMnemonic = "vpmaxub",
				.GasMnemonic = "vpmaxub",
				.Description = "vpmaxub zmm{k}{z}, zmm, m512",
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
							.Value = 0xde,
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
				.IntelMnemonic = "vpmaxub",
				.GasMnemonic = "vpmaxub",
				.Description = "vpmaxub xmm, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Xmm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Xmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Xmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
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
							.Value = 0xde,
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
				.IntelMnemonic = "vpmaxub",
				.GasMnemonic = "vpmaxub",
				.Description = "vpmaxub xmm, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Xmm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
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
							.Value = 0xde,
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
				.IntelMnemonic = "vpmaxub",
				.GasMnemonic = "vpmaxub",
				.Description = "vpmaxub ymm, ymm, ymm",
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
							.Value = 0xde,
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
				.IntelMnemonic = "vpmaxub",
				.GasMnemonic = "vpmaxub",
				.Description = "vpmaxub ymm, ymm, m256",
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
							.Value = 0xde,
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
				.IntelMnemonic = "vpmaxud",
				.GasMnemonic = "vpmaxud",
				.Description = "vpmaxud xmm{k}{z}, xmm, m128/m32bcst",
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
							.Value = 0x3f,
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
				.IntelMnemonic = "vpmaxud",
				.GasMnemonic = "vpmaxud",
				.Description = "vpmaxud xmm{k}{z}, xmm, xmm",
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
							.Value = 0x3f,
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
				.IntelMnemonic = "vpmaxud",
				.GasMnemonic = "vpmaxud",
				.Description = "vpmaxud ymm{k}{z}, ymm, m256/m32bcst",
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
							.Value = 0x3f,
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
				.IntelMnemonic = "vpmaxud",
				.GasMnemonic = "vpmaxud",
				.Description = "vpmaxud ymm{k}{z}, ymm, ymm",
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
							.Value = 0x3f,
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
				.IntelMnemonic = "vpmaxud",
				.GasMnemonic = "vpmaxud",
				.Description = "vpmaxud zmm{k}{z}, zmm, m512/m32bcst",
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
							.Value = 0x3f,
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
				.IntelMnemonic = "vpmaxud",
				.GasMnemonic = "vpmaxud",
				.Description = "vpmaxud zmm{k}{z}, zmm, zmm",
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
							.Value = 0x3f,
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
				.IntelMnemonic = "vpmaxud",
				.GasMnemonic = "vpmaxud",
				.Description = "vpmaxud xmm, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Xmm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Xmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Xmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
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
							.Value = 0x3f,
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
				.IntelMnemonic = "vpmaxud",
				.GasMnemonic = "vpmaxud",
				.Description = "vpmaxud xmm, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Xmm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
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
							.Value = 0x3f,
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
				.IntelMnemonic = "vpmaxud",
				.GasMnemonic = "vpmaxud",
				.Description = "vpmaxud ymm, ymm, ymm",
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
							.Value = 0x3f,
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
				.IntelMnemonic = "vpmaxud",
				.GasMnemonic = "vpmaxud",
				.Description = "vpmaxud ymm, ymm, m256",
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
							.Value = 0x3f,
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
				.IntelMnemonic = "vpmaxuq",
				.GasMnemonic = "vpmaxuq",
				.Description = "vpmaxuq xmm{k}{z}, xmm, m128/m64bcst",
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
							.Value = 0x3f,
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
				.IntelMnemonic = "vpmaxuq",
				.GasMnemonic = "vpmaxuq",
				.Description = "vpmaxuq xmm{k}{z}, xmm, xmm",
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
							.Value = 0x3f,
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
				.IntelMnemonic = "vpmaxuq",
				.GasMnemonic = "vpmaxuq",
				.Description = "vpmaxuq ymm{k}{z}, ymm, m256/m64bcst",
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
							.Value = 0x3f,
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
				.IntelMnemonic = "vpmaxuq",
				.GasMnemonic = "vpmaxuq",
				.Description = "vpmaxuq ymm{k}{z}, ymm, ymm",
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
							.Value = 0x3f,
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
				.IntelMnemonic = "vpmaxuq",
				.GasMnemonic = "vpmaxuq",
				.Description = "vpmaxuq zmm{k}{z}, zmm, m512/m64bcst",
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
							.Value = 0x3f,
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
				.IntelMnemonic = "vpmaxuq",
				.GasMnemonic = "vpmaxuq",
				.Description = "vpmaxuq zmm{k}{z}, zmm, zmm",
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
							.Value = 0x3f,
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
				.IntelMnemonic = "vpmaxuw",
				.GasMnemonic = "vpmaxuw",
				.Description = "vpmaxuw xmm{k}{z}, xmm, xmm",
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
							.Value = 0x3e,
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
				.IntelMnemonic = "vpmaxuw",
				.GasMnemonic = "vpmaxuw",
				.Description = "vpmaxuw xmm{k}{z}, xmm, m128",
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
							.Value = 0x3e,
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
				.IntelMnemonic = "vpmaxuw",
				.GasMnemonic = "vpmaxuw",
				.Description = "vpmaxuw ymm{k}{z}, ymm, ymm",
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
							.Value = 0x3e,
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
				.IntelMnemonic = "vpmaxuw",
				.GasMnemonic = "vpmaxuw",
				.Description = "vpmaxuw ymm{k}{z}, ymm, m256",
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
							.Value = 0x3e,
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
				.IntelMnemonic = "vpmaxuw",
				.GasMnemonic = "vpmaxuw",
				.Description = "vpmaxuw zmm{k}{z}, zmm, zmm",
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
							.Value = 0x3e,
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
				.IntelMnemonic = "vpmaxuw",
				.GasMnemonic = "vpmaxuw",
				.Description = "vpmaxuw zmm{k}{z}, zmm, m512",
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
							.Value = 0x3e,
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
				.IntelMnemonic = "vpmaxuw",
				.GasMnemonic = "vpmaxuw",
				.Description = "vpmaxuw xmm, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Xmm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Xmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Xmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
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
							.Value = 0x3e,
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
				.IntelMnemonic = "vpmaxuw",
				.GasMnemonic = "vpmaxuw",
				.Description = "vpmaxuw xmm, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Xmm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
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
							.Value = 0x3e,
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
				.IntelMnemonic = "vpmaxuw",
				.GasMnemonic = "vpmaxuw",
				.Description = "vpmaxuw ymm, ymm, ymm",
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
							.Value = 0x3e,
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
				.IntelMnemonic = "vpmaxuw",
				.GasMnemonic = "vpmaxuw",
				.Description = "vpmaxuw ymm, ymm, m256",
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
							.Value = 0x3e,
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
				.IntelMnemonic = "vpminsb",
				.GasMnemonic = "vpminsb",
				.Description = "vpminsb xmm{k}{z}, xmm, xmm",
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
							.Value = 0x38,
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
				.IntelMnemonic = "vpminsb",
				.GasMnemonic = "vpminsb",
				.Description = "vpminsb xmm{k}{z}, xmm, m128",
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
							.Value = 0x38,
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
				.IntelMnemonic = "vpminsb",
				.GasMnemonic = "vpminsb",
				.Description = "vpminsb ymm{k}{z}, ymm, ymm",
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
							.Value = 0x38,
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
				.IntelMnemonic = "vpminsb",
				.GasMnemonic = "vpminsb",
				.Description = "vpminsb ymm{k}{z}, ymm, m256",
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
							.Value = 0x38,
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
				.IntelMnemonic = "vpminsb",
				.GasMnemonic = "vpminsb",
				.Description = "vpminsb zmm{k}{z}, zmm, zmm",
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
							.Value = 0x38,
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
				.IntelMnemonic = "vpminsb",
				.GasMnemonic = "vpminsb",
				.Description = "vpminsb zmm{k}{z}, zmm, m512",
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
							.Value = 0x38,
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
				.IntelMnemonic = "vpminsb",
				.GasMnemonic = "vpminsb",
				.Description = "vpminsb xmm, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Xmm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Xmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Xmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
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
							.Value = 0x38,
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
				.IntelMnemonic = "vpminsb",
				.GasMnemonic = "vpminsb",
				.Description = "vpminsb xmm, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Xmm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
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
							.Value = 0x38,
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
				.IntelMnemonic = "vpminsb",
				.GasMnemonic = "vpminsb",
				.Description = "vpminsb ymm, ymm, ymm",
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
							.Value = 0x38,
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
				.IntelMnemonic = "vpminsb",
				.GasMnemonic = "vpminsb",
				.Description = "vpminsb ymm, ymm, m256",
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
							.Value = 0x38,
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
				.IntelMnemonic = "vpminsd",
				.GasMnemonic = "vpminsd",
				.Description = "vpminsd xmm{k}{z}, xmm, m128/m32bcst",
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
							.Value = 0x39,
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
				.IntelMnemonic = "vpminsd",
				.GasMnemonic = "vpminsd",
				.Description = "vpminsd xmm{k}{z}, xmm, xmm",
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
							.Value = 0x39,
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
				.IntelMnemonic = "vpminsd",
				.GasMnemonic = "vpminsd",
				.Description = "vpminsd ymm{k}{z}, ymm, m256/m32bcst",
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
							.Value = 0x39,
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
				.IntelMnemonic = "vpminsd",
				.GasMnemonic = "vpminsd",
				.Description = "vpminsd ymm{k}{z}, ymm, ymm",
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
							.Value = 0x39,
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
				.IntelMnemonic = "vpminsd",
				.GasMnemonic = "vpminsd",
				.Description = "vpminsd zmm{k}{z}, zmm, m512/m32bcst",
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
							.Value = 0x39,
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
				.IntelMnemonic = "vpminsd",
				.GasMnemonic = "vpminsd",
				.Description = "vpminsd zmm{k}{z}, zmm, zmm",
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
							.Value = 0x39,
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
				.IntelMnemonic = "vpminsd",
				.GasMnemonic = "vpminsd",
				.Description = "vpminsd xmm, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Xmm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Xmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Xmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
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
							.Value = 0x39,
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
				.IntelMnemonic = "vpminsd",
				.GasMnemonic = "vpminsd",
				.Description = "vpminsd xmm, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Xmm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
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
							.Value = 0x39,
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
				.IntelMnemonic = "vpminsd",
				.GasMnemonic = "vpminsd",
				.Description = "vpminsd ymm, ymm, ymm",
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
							.Value = 0x39,
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
				.IntelMnemonic = "vpminsd",
				.GasMnemonic = "vpminsd",
				.Description = "vpminsd ymm, ymm, m256",
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
							.Value = 0x39,
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
				.IntelMnemonic = "vpminsq",
				.GasMnemonic = "vpminsq",
				.Description = "vpminsq xmm{k}{z}, xmm, m128/m64bcst",
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
							.Value = 0x39,
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
				.IntelMnemonic = "vpminsq",
				.GasMnemonic = "vpminsq",
				.Description = "vpminsq xmm{k}{z}, xmm, xmm",
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
							.Value = 0x39,
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
				.IntelMnemonic = "vpminsq",
				.GasMnemonic = "vpminsq",
				.Description = "vpminsq ymm{k}{z}, ymm, m256/m64bcst",
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
							.Value = 0x39,
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
				.IntelMnemonic = "vpminsq",
				.GasMnemonic = "vpminsq",
				.Description = "vpminsq ymm{k}{z}, ymm, ymm",
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
							.Value = 0x39,
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
				.IntelMnemonic = "vpminsq",
				.GasMnemonic = "vpminsq",
				.Description = "vpminsq zmm{k}{z}, zmm, m512/m64bcst",
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
							.Value = 0x39,
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
				.IntelMnemonic = "vpminsq",
				.GasMnemonic = "vpminsq",
				.Description = "vpminsq zmm{k}{z}, zmm, zmm",
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
							.Value = 0x39,
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
				.IntelMnemonic = "vpminsw",
				.GasMnemonic = "vpminsw",
				.Description = "vpminsw xmm{k}{z}, xmm, xmm",
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
							.Value = 0xea,
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
				.IntelMnemonic = "vpminsw",
				.GasMnemonic = "vpminsw",
				.Description = "vpminsw xmm{k}{z}, xmm, m128",
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
							.Value = 0xea,
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
				.IntelMnemonic = "vpminsw",
				.GasMnemonic = "vpminsw",
				.Description = "vpminsw ymm{k}{z}, ymm, ymm",
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
							.Value = 0xea,
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
				.IntelMnemonic = "vpminsw",
				.GasMnemonic = "vpminsw",
				.Description = "vpminsw ymm{k}{z}, ymm, m256",
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
							.Value = 0xea,
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
				.IntelMnemonic = "vpminsw",
				.GasMnemonic = "vpminsw",
				.Description = "vpminsw zmm{k}{z}, zmm, zmm",
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
							.Value = 0xea,
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
				.IntelMnemonic = "vpminsw",
				.GasMnemonic = "vpminsw",
				.Description = "vpminsw zmm{k}{z}, zmm, m512",
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
							.Value = 0xea,
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
				.IntelMnemonic = "vpminsw",
				.GasMnemonic = "vpminsw",
				.Description = "vpminsw xmm, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Xmm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Xmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Xmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
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
							.Value = 0xea,
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
				.IntelMnemonic = "vpminsw",
				.GasMnemonic = "vpminsw",
				.Description = "vpminsw xmm, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Xmm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
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
							.Value = 0xea,
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
				.IntelMnemonic = "vpminsw",
				.GasMnemonic = "vpminsw",
				.Description = "vpminsw ymm, ymm, ymm",
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
							.Value = 0xea,
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
				.IntelMnemonic = "vpminsw",
				.GasMnemonic = "vpminsw",
				.Description = "vpminsw ymm, ymm, m256",
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
							.Value = 0xea,
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
				.IntelMnemonic = "vpminub",
				.GasMnemonic = "vpminub",
				.Description = "vpminub xmm{k}{z}, xmm, xmm",
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
							.Value = 0xda,
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
				.IntelMnemonic = "vpminub",
				.GasMnemonic = "vpminub",
				.Description = "vpminub xmm{k}{z}, xmm, m128",
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
							.Value = 0xda,
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
				.IntelMnemonic = "vpminub",
				.GasMnemonic = "vpminub",
				.Description = "vpminub ymm{k}{z}, ymm, ymm",
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
							.Value = 0xda,
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
				.IntelMnemonic = "vpminub",
				.GasMnemonic = "vpminub",
				.Description = "vpminub ymm{k}{z}, ymm, m256",
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
							.Value = 0xda,
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
				.IntelMnemonic = "vpminub",
				.GasMnemonic = "vpminub",
				.Description = "vpminub zmm{k}{z}, zmm, zmm",
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
							.Value = 0xda,
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
				.IntelMnemonic = "vpminub",
				.GasMnemonic = "vpminub",
				.Description = "vpminub zmm{k}{z}, zmm, m512",
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
							.Value = 0xda,
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
				.IntelMnemonic = "vpminub",
				.GasMnemonic = "vpminub",
				.Description = "vpminub xmm, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Xmm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Xmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Xmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
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
							.Value = 0xda,
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
				.IntelMnemonic = "vpminub",
				.GasMnemonic = "vpminub",
				.Description = "vpminub xmm, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Xmm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
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
							.Value = 0xda,
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
				.IntelMnemonic = "vpminub",
				.GasMnemonic = "vpminub",
				.Description = "vpminub ymm, ymm, ymm",
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
							.Value = 0xda,
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
				.IntelMnemonic = "vpminub",
				.GasMnemonic = "vpminub",
				.Description = "vpminub ymm, ymm, m256",
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
							.Value = 0xda,
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
				.IntelMnemonic = "vpminud",
				.GasMnemonic = "vpminud",
				.Description = "vpminud xmm{k}{z}, xmm, m128/m32bcst",
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
							.Value = 0x3b,
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
				.IntelMnemonic = "vpminud",
				.GasMnemonic = "vpminud",
				.Description = "vpminud xmm{k}{z}, xmm, xmm",
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
							.Value = 0x3b,
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
				.IntelMnemonic = "vpminud",
				.GasMnemonic = "vpminud",
				.Description = "vpminud ymm{k}{z}, ymm, m256/m32bcst",
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
							.Value = 0x3b,
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
				.IntelMnemonic = "vpminud",
				.GasMnemonic = "vpminud",
				.Description = "vpminud ymm{k}{z}, ymm, ymm",
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
							.Value = 0x3b,
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
				.IntelMnemonic = "vpminud",
				.GasMnemonic = "vpminud",
				.Description = "vpminud zmm{k}{z}, zmm, m512/m32bcst",
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
							.Value = 0x3b,
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
				.IntelMnemonic = "vpminud",
				.GasMnemonic = "vpminud",
				.Description = "vpminud zmm{k}{z}, zmm, zmm",
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
							.Value = 0x3b,
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
				.IntelMnemonic = "vpminud",
				.GasMnemonic = "vpminud",
				.Description = "vpminud xmm, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Xmm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Xmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Xmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
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
							.Value = 0x3b,
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
				.IntelMnemonic = "vpminud",
				.GasMnemonic = "vpminud",
				.Description = "vpminud xmm, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Xmm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
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
							.Value = 0x3b,
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
				.IntelMnemonic = "vpminud",
				.GasMnemonic = "vpminud",
				.Description = "vpminud ymm, ymm, ymm",
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
							.Value = 0x3b,
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
				.IntelMnemonic = "vpminud",
				.GasMnemonic = "vpminud",
				.Description = "vpminud ymm, ymm, m256",
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
							.Value = 0x3b,
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
				.IntelMnemonic = "vpminuq",
				.GasMnemonic = "vpminuq",
				.Description = "vpminuq xmm{k}{z}, xmm, m128/m64bcst",
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
							.Value = 0x3b,
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
				.IntelMnemonic = "vpminuq",
				.GasMnemonic = "vpminuq",
				.Description = "vpminuq xmm{k}{z}, xmm, xmm",
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
							.Value = 0x3b,
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
				.IntelMnemonic = "vpminuq",
				.GasMnemonic = "vpminuq",
				.Description = "vpminuq ymm{k}{z}, ymm, m256/m64bcst",
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
							.Value = 0x3b,
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
				.IntelMnemonic = "vpminuq",
				.GasMnemonic = "vpminuq",
				.Description = "vpminuq ymm{k}{z}, ymm, ymm",
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
							.Value = 0x3b,
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
				.IntelMnemonic = "vpminuq",
				.GasMnemonic = "vpminuq",
				.Description = "vpminuq zmm{k}{z}, zmm, m512/m64bcst",
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
							.Value = 0x3b,
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
				.IntelMnemonic = "vpminuq",
				.GasMnemonic = "vpminuq",
				.Description = "vpminuq zmm{k}{z}, zmm, zmm",
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
							.Value = 0x3b,
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
				.IntelMnemonic = "vpminuw",
				.GasMnemonic = "vpminuw",
				.Description = "vpminuw xmm{k}{z}, xmm, xmm",
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
							.Value = 0x3a,
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
				.IntelMnemonic = "vpminuw",
				.GasMnemonic = "vpminuw",
				.Description = "vpminuw xmm{k}{z}, xmm, m128",
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
							.Value = 0x3a,
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
				.IntelMnemonic = "vpminuw",
				.GasMnemonic = "vpminuw",
				.Description = "vpminuw ymm{k}{z}, ymm, ymm",
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
							.Value = 0x3a,
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
				.IntelMnemonic = "vpminuw",
				.GasMnemonic = "vpminuw",
				.Description = "vpminuw ymm{k}{z}, ymm, m256",
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
							.Value = 0x3a,
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
				.IntelMnemonic = "vpminuw",
				.GasMnemonic = "vpminuw",
				.Description = "vpminuw zmm{k}{z}, zmm, zmm",
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
							.Value = 0x3a,
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
				.IntelMnemonic = "vpminuw",
				.GasMnemonic = "vpminuw",
				.Description = "vpminuw zmm{k}{z}, zmm, m512",
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
							.Value = 0x3a,
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
				.IntelMnemonic = "vpminuw",
				.GasMnemonic = "vpminuw",
				.Description = "vpminuw xmm, xmm, xmm",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Xmm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Xmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
					Operand
					{
						.Type = OperandType::Xmm,
						.IsInput = true,
						.IsOutput = false,
						.ExtendedSize = 0
					},
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
							.Value = 0x3a,
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
				.IntelMnemonic = "vpminuw",
				.GasMnemonic = "vpminuw",
				.Description = "vpminuw xmm, xmm, m128",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
					Operand
					{
						.Type = OperandType::Xmm,
						.IsInput = false,
						.IsOutput = true,
						.ExtendedSize = 0
					},
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
							.Value = 0x3a,
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
				.IntelMnemonic = "vpminuw",
				.GasMnemonic = "vpminuw",
				.Description = "vpminuw ymm, ymm, ymm",
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
							.Value = 0x3a,
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
				.IntelMnemonic = "vpminuw",
				.GasMnemonic = "vpminuw",
				.Description = "vpminuw ymm, ymm, m256",
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
							.Value = 0x3a,
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
				.IntelMnemonic = "vpmovb2m",
				.GasMnemonic = "vpmovb2m",
				.Description = "vpmovb2m k, xmm",
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
							.W = false,
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
				.IntelMnemonic = "vpmovb2m",
				.GasMnemonic = "vpmovb2m",
				.Description = "vpmovb2m k, ymm",
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
							.W = false,
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
				.IntelMnemonic = "vpmovb2m",
				.GasMnemonic = "vpmovb2m",
				.Description = "vpmovb2m k, zmm",
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
							.W = false,
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
				.IntelMnemonic = "vpmovd2m",
				.GasMnemonic = "vpmovd2m",
				.Description = "vpmovd2m k, xmm",
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
					IsaExtension::Avx512Dq,
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
							.Value = 0x39,
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
				.IntelMnemonic = "vpmovd2m",
				.GasMnemonic = "vpmovd2m",
				.Description = "vpmovd2m k, ymm",
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
					IsaExtension::Avx512Dq,
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
							.Value = 0x39,
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
				.IntelMnemonic = "vpmovd2m",
				.GasMnemonic = "vpmovd2m",
				.Description = "vpmovd2m k, zmm",
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
					IsaExtension::Avx512Dq,
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
							.Value = 0x39,
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
				.IntelMnemonic = "vpmovdb",
				.GasMnemonic = "vpmovdb",
				.Description = "vpmovdb xmm{k}{z}, xmm",
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
							.Value = 0x31,
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
				.IntelMnemonic = "vpmovdb",
				.GasMnemonic = "vpmovdb",
				.Description = "vpmovdb m32{k}{z}, xmm",
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
							.Value = 0x31,
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
				.IntelMnemonic = "vpmovdb",
				.GasMnemonic = "vpmovdb",
				.Description = "vpmovdb xmm{k}{z}, ymm",
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
							.Value = 0x31,
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
				.IntelMnemonic = "vpmovdb",
				.GasMnemonic = "vpmovdb",
				.Description = "vpmovdb m64{k}{z}, ymm",
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
							.Value = 0x31,
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
				.IntelMnemonic = "vpmovdb",
				.GasMnemonic = "vpmovdb",
				.Description = "vpmovdb xmm{k}{z}, zmm",
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
							.Value = 0x31,
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
				.IntelMnemonic = "vpmovdb",
				.GasMnemonic = "vpmovdb",
				.Description = "vpmovdb m128{k}{z}, zmm",
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
							.Value = 0x31,
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
				.IntelMnemonic = "vpmovdw",
				.GasMnemonic = "vpmovdw",
				.Description = "vpmovdw xmm{k}{z}, xmm",
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
							.Value = 0x33,
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
				.IntelMnemonic = "vpmovdw",
				.GasMnemonic = "vpmovdw",
				.Description = "vpmovdw m64{k}{z}, xmm",
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
							.Value = 0x33,
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
				.IntelMnemonic = "vpmovdw",
				.GasMnemonic = "vpmovdw",
				.Description = "vpmovdw xmm{k}{z}, ymm",
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
							.Value = 0x33,
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
				.IntelMnemonic = "vpmovdw",
				.GasMnemonic = "vpmovdw",
				.Description = "vpmovdw m128{k}{z}, ymm",
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
							.Value = 0x33,
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
				.IntelMnemonic = "vpmovdw",
				.GasMnemonic = "vpmovdw",
				.Description = "vpmovdw ymm{k}{z}, zmm",
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
							.Value = 0x33,
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
				.IntelMnemonic = "vpmovdw",
				.GasMnemonic = "vpmovdw",
				.Description = "vpmovdw m256{k}{z}, zmm",
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
							.Value = 0x33,
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
				.IntelMnemonic = "vpmovm2b",
				.GasMnemonic = "vpmovm2b",
				.Description = "vpmovm2b xmm, k",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
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
							.Value = 0x28,
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
				.IntelMnemonic = "vpmovm2b",
				.GasMnemonic = "vpmovm2b",
				.Description = "vpmovm2b ymm, k",
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
							.Value = 0x28,
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
				.IntelMnemonic = "vpmovm2b",
				.GasMnemonic = "vpmovm2b",
				.Description = "vpmovm2b zmm, k",
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
							.Value = 0x28,
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
				.IntelMnemonic = "vpmovm2d",
				.GasMnemonic = "vpmovm2d",
				.Description = "vpmovm2d xmm, k",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
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
					IsaExtension::Avx512Dq,
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
							.Value = 0x38,
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
				.IntelMnemonic = "vpmovm2d",
				.GasMnemonic = "vpmovm2d",
				.Description = "vpmovm2d ymm, k",
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
					IsaExtension::Avx512Dq,
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
							.Value = 0x38,
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
				.IntelMnemonic = "vpmovm2d",
				.GasMnemonic = "vpmovm2d",
				.Description = "vpmovm2d zmm, k",
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
					IsaExtension::Avx512Dq,
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
							.Value = 0x38,
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
				.IntelMnemonic = "vpmovm2q",
				.GasMnemonic = "vpmovm2q",
				.Description = "vpmovm2q xmm, k",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
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
					IsaExtension::Avx512Dq,
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
							.Value = 0x38,
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
				.IntelMnemonic = "vpmovm2q",
				.GasMnemonic = "vpmovm2q",
				.Description = "vpmovm2q ymm, k",
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
					IsaExtension::Avx512Dq,
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
							.Value = 0x38,
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
				.IntelMnemonic = "vpmovm2q",
				.GasMnemonic = "vpmovm2q",
				.Description = "vpmovm2q zmm, k",
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
					IsaExtension::Avx512Dq,
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
							.Value = 0x38,
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
				.IntelMnemonic = "vpmovm2w",
				.GasMnemonic = "vpmovm2w",
				.Description = "vpmovm2w xmm, k",
				.MmxMode = MmxModeType::None,
				.XmmMode = XmmModeType::Avx,
				.IsCancellingInputs = false,
				.OperandList =
				{
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
							.Value = 0x28,
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
				.IntelMnemonic = "vpmovm2w",
				.GasMnemonic = "vpmovm2w",
				.Description = "vpmovm2w ymm, k",
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
							.Value = 0x28,
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
				.IntelMnemonic = "vpmovm2w",
				.GasMnemonic = "vpmovm2w",
				.Description = "vpmovm2w zmm, k",
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
							.Value = 0x28,
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
				.IntelMnemonic = "vpmovmskb",
				.GasMnemonic = "vpmovmskb",
				.Description = "vpmovmskb r32, xmm",
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
							.Pp = 0b1,
							.W = false,
							.L = false,
							.R = {OperandType::R32},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Xmm},
							.Vvvv = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0xd7,
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
				.IntelMnemonic = "vpmovmskb",
				.GasMnemonic = "vpmovmskb",
				.Description = "vpmovmskb r32, ymm",
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
							.R = {OperandType::R32},
							.X = {UINT64_C(0x0)},
							.B = {OperandType::Ymm},
							.Vvvv = {UINT64_C(0x0)},
						},
						OpCode
						{
							.Value = 0xd7,
							.Addend = {UINT64_C(0x0)},
						},
						ModRm
						{
							.Mode = {UINT64_C(0x3)},
							.Rm = {OperandType::Ymm},
							.Reg = {OperandType::R32},
						},
					},
				}
			},
		};
		out.emplace_back(std::move(instruction));

		instruction =
		{
			InstructionVariation
			{
				.IntelMnemonic = "vpmovq2m",
				.GasMnemonic = "vpmovq2m",
				.Description = "vpmovq2m k, xmm",
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
					IsaExtension::Avx512Dq,
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
							.Value = 0x39,
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
				.IntelMnemonic = "vpmovq2m",
				.GasMnemonic = "vpmovq2m",
				.Description = "vpmovq2m k, ymm",
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
					IsaExtension::Avx512Dq,
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
							.Value = 0x39,
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
				.IntelMnemonic = "vpmovq2m",
				.GasMnemonic = "vpmovq2m",
				.Description = "vpmovq2m k, zmm",
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
					IsaExtension::Avx512Dq,
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
							.Value = 0x39,
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
				.IntelMnemonic = "vpmovqb",
				.GasMnemonic = "vpmovqb",
				.Description = "vpmovqb xmm{k}{z}, xmm",
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
							.Value = 0x32,
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
				.IntelMnemonic = "vpmovqb",
				.GasMnemonic = "vpmovqb",
				.Description = "vpmovqb m16{k}{z}, xmm",
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
							.Value = 0x32,
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
				.IntelMnemonic = "vpmovqb",
				.GasMnemonic = "vpmovqb",
				.Description = "vpmovqb xmm{k}{z}, ymm",
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
							.Value = 0x32,
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
				.IntelMnemonic = "vpmovqb",
				.GasMnemonic = "vpmovqb",
				.Description = "vpmovqb m32{k}{z}, ymm",
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
							.Value = 0x32,
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
				.IntelMnemonic = "vpmovqb",
				.GasMnemonic = "vpmovqb",
				.Description = "vpmovqb xmm{k}{z}, zmm",
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
							.Value = 0x32,
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
				.IntelMnemonic = "vpmovqb",
				.GasMnemonic = "vpmovqb",
				.Description = "vpmovqb m64{k}{z}, zmm",
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
							.Value = 0x32,
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
				.IntelMnemonic = "vpmovqd",
				.GasMnemonic = "vpmovqd",
				.Description = "vpmovqd xmm{k}{z}, xmm",
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
							.Value = 0x35,
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
				.IntelMnemonic = "vpmovqd",
				.GasMnemonic = "vpmovqd",
				.Description = "vpmovqd m64{k}{z}, xmm",
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
							.Value = 0x35,
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
				.IntelMnemonic = "vpmovqd",
				.GasMnemonic = "vpmovqd",
				.Description = "vpmovqd xmm{k}{z}, ymm",
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
							.Value = 0x35,
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
				.IntelMnemonic = "vpmovqd",
				.GasMnemonic = "vpmovqd",
				.Description = "vpmovqd m128{k}{z}, ymm",
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
							.Value = 0x35,
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
				.IntelMnemonic = "vpmovqd",
				.GasMnemonic = "vpmovqd",
				.Description = "vpmovqd ymm{k}{z}, zmm",
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
							.Value = 0x35,
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
				.IntelMnemonic = "vpmovqd",
				.GasMnemonic = "vpmovqd",
				.Description = "vpmovqd m256{k}{z}, zmm",
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
							.Value = 0x35,
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
				.IntelMnemonic = "vpmovqw",
				.GasMnemonic = "vpmovqw",
				.Description = "vpmovqw xmm{k}{z}, xmm",
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
							.Value = 0x34,
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
				.IntelMnemonic = "vpmovqw",
				.GasMnemonic = "vpmovqw",
				.Description = "vpmovqw m32{k}{z}, xmm",
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
							.Value = 0x34,
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
				.IntelMnemonic = "vpmovqw",
				.GasMnemonic = "vpmovqw",
				.Description = "vpmovqw xmm{k}{z}, ymm",
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
							.Value = 0x34,
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
				.IntelMnemonic = "vpmovqw",
				.GasMnemonic = "vpmovqw",
				.Description = "vpmovqw m64{k}{z}, ymm",
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
							.Value = 0x34,
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
				.IntelMnemonic = "vpmovqw",
				.GasMnemonic = "vpmovqw",
				.Description = "vpmovqw xmm{k}{z}, zmm",
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
							.Value = 0x34,
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
				.IntelMnemonic = "vpmovqw",
				.GasMnemonic = "vpmovqw",
				.Description = "vpmovqw m128{k}{z}, zmm",
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
							.Value = 0x34,
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
				.IntelMnemonic = "vpmovsdb",
				.GasMnemonic = "vpmovsdb",
				.Description = "vpmovsdb xmm{k}{z}, xmm",
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
							.Value = 0x21,
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
				.IntelMnemonic = "vpmovsdb",
				.GasMnemonic = "vpmovsdb",
				.Description = "vpmovsdb m32{k}{z}, xmm",
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
							.Value = 0x21,
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
				.IntelMnemonic = "vpmovsdb",
				.GasMnemonic = "vpmovsdb",
				.Description = "vpmovsdb xmm{k}{z}, ymm",
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
							.Value = 0x21,
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
				.IntelMnemonic = "vpmovsdb",
				.GasMnemonic = "vpmovsdb",
				.Description = "vpmovsdb m64{k}{z}, ymm",
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
							.Value = 0x21,
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
				.IntelMnemonic = "vpmovsdb",
				.GasMnemonic = "vpmovsdb",
				.Description = "vpmovsdb xmm{k}{z}, zmm",
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
							.Value = 0x21,
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
				.IntelMnemonic = "vpmovsdb",
				.GasMnemonic = "vpmovsdb",
				.Description = "vpmovsdb m128{k}{z}, zmm",
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
							.Value = 0x21,
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
				.IntelMnemonic = "vpmovsdw",
				.GasMnemonic = "vpmovsdw",
				.Description = "vpmovsdw xmm{k}{z}, xmm",
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
							.Value = 0x23,
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
				.IntelMnemonic = "vpmovsdw",
				.GasMnemonic = "vpmovsdw",
				.Description = "vpmovsdw m64{k}{z}, xmm",
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
							.Value = 0x23,
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
				.IntelMnemonic = "vpmovsdw",
				.GasMnemonic = "vpmovsdw",
				.Description = "vpmovsdw xmm{k}{z}, ymm",
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
							.Value = 0x23,
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
				.IntelMnemonic = "vpmovsdw",
				.GasMnemonic = "vpmovsdw",
				.Description = "vpmovsdw m128{k}{z}, ymm",
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
							.Value = 0x23,
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
				.IntelMnemonic = "vpmovsdw",
				.GasMnemonic = "vpmovsdw",
				.Description = "vpmovsdw ymm{k}{z}, zmm",
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
							.Value = 0x23,
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
				.IntelMnemonic = "vpmovsdw",
				.GasMnemonic = "vpmovsdw",
				.Description = "vpmovsdw m256{k}{z}, zmm",
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
							.Value = 0x23,
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
				.IntelMnemonic = "vpmovsqb",
				.GasMnemonic = "vpmovsqb",
				.Description = "vpmovsqb xmm{k}{z}, xmm",
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
							.Value = 0x22,
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
				.IntelMnemonic = "vpmovsqb",
				.GasMnemonic = "vpmovsqb",
				.Description = "vpmovsqb m16{k}{z}, xmm",
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
							.Value = 0x22,
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
				.IntelMnemonic = "vpmovsqb",
				.GasMnemonic = "vpmovsqb",
				.Description = "vpmovsqb xmm{k}{z}, ymm",
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
							.Value = 0x22,
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
				.IntelMnemonic = "vpmovsqb",
				.GasMnemonic = "vpmovsqb",
				.Description = "vpmovsqb m32{k}{z}, ymm",
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
							.Value = 0x22,
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
				.IntelMnemonic = "vpmovsqb",
				.GasMnemonic = "vpmovsqb",
				.Description = "vpmovsqb xmm{k}{z}, zmm",
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
							.Value = 0x22,
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
				.IntelMnemonic = "vpmovsqb",
				.GasMnemonic = "vpmovsqb",
				.Description = "vpmovsqb m64{k}{z}, zmm",
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
							.Value = 0x22,
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
				.IntelMnemonic = "vpmovsqd",
				.GasMnemonic = "vpmovsqd",
				.Description = "vpmovsqd xmm{k}{z}, xmm",
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
							.Value = 0x25,
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
				.IntelMnemonic = "vpmovsqd",
				.GasMnemonic = "vpmovsqd",
				.Description = "vpmovsqd m64{k}{z}, xmm",
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
							.Value = 0x25,
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
				.IntelMnemonic = "vpmovsqd",
				.GasMnemonic = "vpmovsqd",
				.Description = "vpmovsqd xmm{k}{z}, ymm",
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
							.Value = 0x25,
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
				.IntelMnemonic = "vpmovsqd",
				.GasMnemonic = "vpmovsqd",
				.Description = "vpmovsqd m128{k}{z}, ymm",
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
							.Value = 0x25,
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
				.IntelMnemonic = "vpmovsqd",
				.GasMnemonic = "vpmovsqd",
				.Description = "vpmovsqd ymm{k}{z}, zmm",
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
							.Value = 0x25,
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
				.IntelMnemonic = "vpmovsqd",
				.GasMnemonic = "vpmovsqd",
				.Description = "vpmovsqd m256{k}{z}, zmm",
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
							.Value = 0x25,
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
				.IntelMnemonic = "vpmovsqw",
				.GasMnemonic = "vpmovsqw",
				.Description = "vpmovsqw xmm{k}{z}, xmm",
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
							.Value = 0x24,
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
				.IntelMnemonic = "vpmovsqw",
				.GasMnemonic = "vpmovsqw",
				.Description = "vpmovsqw m32{k}{z}, xmm",
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
							.Value = 0x24,
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
				.IntelMnemonic = "vpmovsqw",
				.GasMnemonic = "vpmovsqw",
				.Description = "vpmovsqw xmm{k}{z}, ymm",
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
							.Value = 0x24,
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
				.IntelMnemonic = "vpmovsqw",
				.GasMnemonic = "vpmovsqw",
				.Description = "vpmovsqw m64{k}{z}, ymm",
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
							.Value = 0x24,
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
				.IntelMnemonic = "vpmovsqw",
				.GasMnemonic = "vpmovsqw",
				.Description = "vpmovsqw xmm{k}{z}, zmm",
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
							.Value = 0x24,
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
				.IntelMnemonic = "vpmovsqw",
				.GasMnemonic = "vpmovsqw",
				.Description = "vpmovsqw m128{k}{z}, zmm",
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
							.Value = 0x24,
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
				.IntelMnemonic = "vpmovswb",
				.GasMnemonic = "vpmovswb",
				.Description = "vpmovswb xmm{k}{z}, xmm",
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
							.Value = 0x20,
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
				.IntelMnemonic = "vpmovswb",
				.GasMnemonic = "vpmovswb",
				.Description = "vpmovswb m64{k}{z}, xmm",
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
							.Value = 0x20,
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
				.IntelMnemonic = "vpmovswb",
				.GasMnemonic = "vpmovswb",
				.Description = "vpmovswb xmm{k}{z}, ymm",
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
							.Value = 0x20,
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
				.IntelMnemonic = "vpmovswb",
				.GasMnemonic = "vpmovswb",
				.Description = "vpmovswb m128{k}{z}, ymm",
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
							.Value = 0x20,
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
				.IntelMnemonic = "vpmovswb",
				.GasMnemonic = "vpmovswb",
				.Description = "vpmovswb ymm{k}{z}, zmm",
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
							.Value = 0x20,
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
				.IntelMnemonic = "vpmovswb",
				.GasMnemonic = "vpmovswb",
				.Description = "vpmovswb m256{k}{z}, zmm",
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
							.Value = 0x20,
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
	};
}
