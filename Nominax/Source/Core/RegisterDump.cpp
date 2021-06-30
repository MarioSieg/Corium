// File: RegisterDump.cpp
// Author: Mario
// Created: 06.06.2021 5:38 PM
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

#include <bitset>
#include <ostream>

#include "../../Include/Nominax/Core/RegisterDump.hpp"

namespace Nominax::Core
{
#if NOX_ARCH_X86_32
	
	auto RegisterDump_X86_32(std::ostream& out, const GprRegisterLane& gpr) -> void
	{
		out << "\n%eax = " << std::bitset<32>{gpr[0]};
		out << "\n%ebx = " << std::bitset<32>{gpr[1]};
		out << "\n%ecx = " << std::bitset<32>{gpr[2]};
		out << "\n%edx = " << std::bitset<32>{gpr[3]};
		out << "\n%esi = " << std::bitset<32>{gpr[4]};
		out << "\n%edi = " << std::bitset<32>{gpr[5]};
		out << "\n%ebp = " << std::bitset<32>{gpr[6]};
		out << "\n%esp = " << std::bitset<32>{gpr[7]};
	}

#elif NOX_ARCH_X86_64

	/// <summary>
	/// Read and dump all the register values into the stream.
	/// </summary>
	/// <param name="out"></param>
	/// <param name="gpr"></param>
	/// <param name="xmm"></param>
	/// <param name="ymm"></param>
	/// <param name="zmm"></param>
	/// <returns></returns>
	auto RegisterDump_X86_64
	(
		std::ostream&                out,
		const GprRegisterLane&       gpr,
		const VectorRegisterLane128& xmm,
		const VectorRegisterLane256& ymm
	) -> void
	{
		out << std::dec;
		out << "\n%RAX   = " << std::bitset<64> {gpr[0]};
		out << "\n%RBX   = " << std::bitset<64> {gpr[1]};
		out << "\n%RCX   = " << std::bitset<64> {gpr[2]};
		out << "\n%RDX   = " << std::bitset<64> {gpr[3]};
		out << "\n%RSI   = " << std::bitset<64> {gpr[4]};
		out << "\n%RDI   = " << std::bitset<64> {gpr[5]};
		out << "\n%RBP   = " << std::bitset<64> {gpr[6]};
		out << "\n%RSP   = " << std::bitset<64> {gpr[7]};
		out << "\n%R8    = " << std::bitset<64> {gpr[8]};
		out << "\n%R9    = " << std::bitset<64> {gpr[9]};
		out << "\n%R10   = " << std::bitset<64> {gpr[10]};
		out << "\n%R11   = " << std::bitset<64> {gpr[11]};
		out << "\n%R12   = " << std::bitset<64> {gpr[12]};
		out << "\n%R13   = " << std::bitset<64> {gpr[13]};
		out << "\n%R14   = " << std::bitset<64> {gpr[14]};
		out << "\n%R15   = " << std::bitset<64> {gpr[15]};

		out << '\n';

		out << "\n%XMM0  = " << std::bitset<64> {xmm[0][0]} << std::bitset<64> {xmm[0][1]};
		out << "\n%XMM1  = " << std::bitset<64> {xmm[1][0]} << std::bitset<64> {xmm[1][1]};
		out << "\n%XMM2  = " << std::bitset<64> {xmm[2][0]} << std::bitset<64> {xmm[2][1]};
		out << "\n%XMM3  = " << std::bitset<64> {xmm[3][0]} << std::bitset<64> {xmm[3][1]};
		out << "\n%XMM4  = " << std::bitset<64> {xmm[4][0]} << std::bitset<64> {xmm[4][1]};
		out << "\n%XMM5  = " << std::bitset<64> {xmm[5][0]} << std::bitset<64> {xmm[5][1]};
		out << "\n%XMM6  = " << std::bitset<64> {xmm[6][0]} << std::bitset<64> {xmm[6][1]};
		out << "\n%XMM7  = " << std::bitset<64> {xmm[7][0]} << std::bitset<64> {xmm[7][1]};
		out << "\n%XMM8  = " << std::bitset<64> {xmm[8][0]} << std::bitset<64> {xmm[8][1]};
		out << "\n%XMM9  = " << std::bitset<64> {xmm[9][0]} << std::bitset<64> {xmm[9][1]};
		out << "\n%XMM10 = " << std::bitset<64> {xmm[10][0]} << std::bitset<64> {xmm[10][1]};
		out << "\n%XMM11 = " << std::bitset<64> {xmm[11][0]} << std::bitset<64> {xmm[11][1]};
		out << "\n%XMM12 = " << std::bitset<64> {xmm[12][0]} << std::bitset<64> {xmm[12][1]};
		out << "\n%XMM13 = " << std::bitset<64> {xmm[13][0]} << std::bitset<64> {xmm[13][1]};
		out << "\n%XMM14 = " << std::bitset<64> {xmm[14][0]} << std::bitset<64> {xmm[14][1]};
		out << "\n%XMM15 = " << std::bitset<64> {xmm[15][0]} << std::bitset<64> {xmm[15][1]};

		out << '\n';

		out << "\n%YMM0  = " << std::bitset<64> {ymm[0][0]} << std::bitset<64> {ymm[0][1]} << std::bitset<64> {ymm[0][2]} << std::bitset<64> {ymm[0][3]};
		out << "\n%YMM1  = " << std::bitset<64> {ymm[1][0]} << std::bitset<64> {ymm[1][1]} << std::bitset<64> {ymm[1][2]} << std::bitset<64> {ymm[1][3]};
		out << "\n%YMM2  = " << std::bitset<64> {ymm[2][0]} << std::bitset<64> {ymm[2][1]} << std::bitset<64> {ymm[2][2]} << std::bitset<64> {ymm[2][3]};
		out << "\n%YMM3  = " << std::bitset<64> {ymm[3][0]} << std::bitset<64> {ymm[3][1]} << std::bitset<64> {ymm[3][2]} << std::bitset<64> {ymm[3][3]};
		out << "\n%YMM4  = " << std::bitset<64> {ymm[4][0]} << std::bitset<64> {ymm[4][1]} << std::bitset<64> {ymm[4][2]} << std::bitset<64> {ymm[4][3]};
		out << "\n%YMM5  = " << std::bitset<64> {ymm[5][0]} << std::bitset<64> {ymm[5][1]} << std::bitset<64> {ymm[5][2]} << std::bitset<64> {ymm[5][3]};
		out << "\n%YMM6  = " << std::bitset<64> {ymm[6][0]} << std::bitset<64> {ymm[6][1]} << std::bitset<64> {ymm[6][2]} << std::bitset<64> {ymm[6][3]};
		out << "\n%YMM7  = " << std::bitset<64> {ymm[7][0]} << std::bitset<64> {ymm[7][1]} << std::bitset<64> {ymm[7][2]} << std::bitset<64> {ymm[7][3]};
		out << "\n%YMM8  = " << std::bitset<64> {ymm[8][0]} << std::bitset<64> {ymm[8][1]} << std::bitset<64> {ymm[8][2]} << std::bitset<64> {ymm[8][3]};
		out << "\n%YMM9  = " << std::bitset<64> {ymm[9][0]} << std::bitset<64> {ymm[9][1]} << std::bitset<64> {ymm[9][2]} << std::bitset<64> {ymm[9][3]};
		out << "\n%YMM10 = " << std::bitset<64> {ymm[10][0]} << std::bitset<64> {ymm[10][1]} << std::bitset<64> {ymm[10][2]} << std::bitset<64> {ymm[10][3]};
		out << "\n%YMM11 = " << std::bitset<64> {ymm[11][0]} << std::bitset<64> {ymm[11][1]} << std::bitset<64> {ymm[11][2]} << std::bitset<64> {ymm[11][3]};
		out << "\n%YMM12 = " << std::bitset<64> {ymm[12][0]} << std::bitset<64> {ymm[12][1]} << std::bitset<64> {ymm[12][2]} << std::bitset<64> {ymm[12][3]};
		out << "\n%YMM13 = " << std::bitset<64> {ymm[13][0]} << std::bitset<64> {ymm[13][1]} << std::bitset<64> {ymm[13][2]} << std::bitset<64> {ymm[13][3]};
		out << "\n%YMM14 = " << std::bitset<64> {ymm[14][0]} << std::bitset<64> {ymm[14][1]} << std::bitset<64> {ymm[14][2]} << std::bitset<64> {ymm[14][3]};
		out << "\n%YMM15 = " << std::bitset<64> {ymm[15][0]} << std::bitset<64> {ymm[15][1]} << std::bitset<64> {ymm[15][2]} << std::bitset<64> {ymm[15][3]};

		out << "\n\nUncaptured:\n\n";
		out << "%RIP\n\n";
		out << "%ZMM0,  %ZMM1,  %ZMM2,  %ZMM3\n";
		out << "%ZMM4,  %ZMM5,  %ZMM6,  %ZMM7\n";
		out << "%ZMM8,  %ZMM9,  %ZMM10, %ZMM11\n";
		out << "%ZMM12, %ZMM13, %ZMM14, %ZMM15\n";
		out << "%ZMM16, %ZMM17, %ZMM18, %ZMM19\n";
		out << "%ZMM20, %ZMM21, %ZMM22, %ZMM23\n";
		out << "%ZMM24, %ZMM25, %ZMM26, %ZMM27\n";
		out << "%ZMM28, %ZMM29, %ZMM30, %ZMM31\n\n";

		out << "%K0, %K1, %K2, %K3\n";
		out << "%K4, %K5, %K6, %K7\n";
		out << '\n';
	}

#elif NOX_ARCH_ARM_64
#	error "Not yet implemented!"
#else
#	error "Unknown arch!"
#endif
}
