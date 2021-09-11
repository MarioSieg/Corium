// File: Operand.hpp
// Author: Mario
// Created: 20.08.2021 2:40 PM
// Project: Corium
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

#pragma once

#include "../../Foundation/_Foundation.hpp"

namespace Nominax::Assembler::X86_64
{
	/// <summary>
/// Contains all implicit register operands.
/// </summary>
	enum class ImplicitRegisterOperand : std::uint8_t
	{
		Al,
		Ax,
		Dx,
		Eax,
		Ebx,
		Ecx,
		Edx,
		Rax,
		Rbx,
		Rcx,
		Rdx,
		Rdi,
		R11,
		Xmm0
	};

	enum class OperandType : std::uint8_t
	{
		ScalarOne,
		ScalarThree,
		Al,
		Ax,
		Eax,
		Rax,
		Cl,
		Xmm0,
		Rel8,
		Rel32,
		Imm4,
		Imm8,
		Imm16,
		Imm32,
		Imm64,
		R8,
		R16,
		R32,
		R64,
		Mm,
		Xmm,
		XmmK,
		XmmKz,
		Ymm,
		YmmK,
		YmmKz,
		Zmm,
		ZmmK,
		ZmmKz,
		K,
		Kk,
		M,
		M8,
		M16,
		M16Kz,
		M32,
		M32k,
		M32Kz,
		M64,
		M64k,
		M64Kz,
		M80,
		M128,
		M128Kz,
		M256,
		M256Kz,
		M512,
		M512Kz,
		Moffs32,
		Moffs64,
		M64M32Bcst,
		M128M32Bcst,
		M256M32Bcst,
		M512M32Bcst,
		M128M64Bcst,
		M256M64Bcst,
		M512M64Bcst,
		Vm32x,
		Vm32xk,
		Vm32y,
		Vm32yk,
		Vm32z,
		Vm32zk,
		Vm64x,
		Vm64xk,
		Vm64y,
		Vm64yk,
		Vm64z,
		Vm64zk,
		Sae,
		Er
	};

	struct Operand final
	{
		OperandType  Type;
		bool         IsInput;
		bool         IsOutput;
		std::uint8_t ExtendedSize;

		constexpr auto IsVariable() const -> bool;
		constexpr auto IsRegister() const -> bool;
		constexpr auto IsMemory() const -> bool;
		constexpr auto IsImmediate() const -> bool;
	};

	constexpr auto Operand::IsVariable() const -> bool
	{
		return this->IsInput || this->IsOutput;
	}

	constexpr auto Operand::IsRegister() const -> bool
	{
		return
			this->Type == OperandType::Al
			|| this->Type == OperandType::Cl
			|| this->Type == OperandType::Ax
			|| this->Type == OperandType::Eax
			|| this->Type == OperandType::Rax
			|| this->Type == OperandType::Xmm0
			|| this->Type == OperandType::R8
			|| this->Type == OperandType::R16
			|| this->Type == OperandType::R32
			|| this->Type == OperandType::R64
			|| this->Type == OperandType::R8
			|| this->Type == OperandType::Mm
			|| this->Type == OperandType::Xmm
			|| this->Type == OperandType::XmmK
			|| this->Type == OperandType::XmmKz
			|| this->Type == OperandType::Ymm
			|| this->Type == OperandType::YmmK
			|| this->Type == OperandType::YmmKz
			|| this->Type == OperandType::Zmm
			|| this->Type == OperandType::ZmmK
			|| this->Type == OperandType::ZmmKz
			|| this->Type == OperandType::K
			|| this->Type == OperandType::Kk;
	}

	constexpr auto Operand::IsMemory() const -> bool
	{
		return
			this->Type == OperandType::M
			|| this->Type == OperandType::M8
			|| this->Type == OperandType::M16
			|| this->Type == OperandType::M16Kz
			|| this->Type == OperandType::M32
			|| this->Type == OperandType::M32k
			|| this->Type == OperandType::M32Kz
			|| this->Type == OperandType::M64
			|| this->Type == OperandType::M64k
			|| this->Type == OperandType::M64Kz
			|| this->Type == OperandType::M80
			|| this->Type == OperandType::M128
			|| this->Type == OperandType::M128Kz
			|| this->Type == OperandType::M256
			|| this->Type == OperandType::M256Kz
			|| this->Type == OperandType::M512
			|| this->Type == OperandType::M512Kz
			|| this->Type == OperandType::Moffs32
			|| this->Type == OperandType::Moffs64
			|| this->Type == OperandType::M64M32Bcst
			|| this->Type == OperandType::M128M32Bcst
			|| this->Type == OperandType::M256M32Bcst
			|| this->Type == OperandType::M512M32Bcst
			|| this->Type == OperandType::M128M64Bcst
			|| this->Type == OperandType::M256M64Bcst
			|| this->Type == OperandType::M512M64Bcst
			|| this->Type == OperandType::Vm32x
			|| this->Type == OperandType::Vm32xk
			|| this->Type == OperandType::Vm32y
			|| this->Type == OperandType::Vm32yk
			|| this->Type == OperandType::Vm32z
			|| this->Type == OperandType::Vm32zk;
	}

	constexpr auto Operand::IsImmediate() const -> bool
	{
		return
			this->Type == OperandType::Imm4
			|| this->Type == OperandType::Imm8
			|| this->Type == OperandType::Imm16
			|| this->Type == OperandType::Imm32
			|| this->Type == OperandType::Imm64;
	}

	using Soo = std::variant<std::uint64_t, OperandType>;
}
