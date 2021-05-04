// File: CpuId.hpp
// Author: Mario
// Created: 02.05.2021 9:22 PM
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

#pragma once

#include <type_traits>

#include "../MachInterface.hpp"

namespace Nominax::X86_64
{
	/// <summary>
	/// Contains all feature bits for a x86-64 cpu.
	/// </summary>
	struct CpuFeatureBits final
	{
		CpuFeatureBits() noexcept(false);

		// QWORD 1 LO

		bool Fpu : 1 { };
		bool Vme : 1 { };
		bool De : 1 { };
		bool Pse : 1 { };
		bool Tsc : 1 { };
		bool Msr : 1 { };
		bool Pae : 1 { };
		bool Mce : 1 { };
		bool Cx8 : 1 { };
		bool Apic : 1 { };
		bool Reserved0 : 1 { };
		bool Sep : 1 { };
		bool Mtrr : 1 { };
		bool Pge : 1 { };
		bool Mca : 1 { };
		bool CMov : 1 { };
		bool Pat : 1 { };
		bool Pse36 : 1 { };
		bool Psn : 1 { };
		bool Clfsh : 1 { };
		bool Reserved1 : 1 { };
		bool Ds : 1 { };
		bool Acpi : 1 { };
		bool Mmx : 1 { };
		bool Fxsr : 1 { };
		bool Sse : 1 { };
		bool Sse2 : 1 { };
		bool Ss : 1 { };
		bool Htt : 1 { };
		bool Tm : 1 { };
		bool Ia64 : 1 { };
		bool Pbe : 1 { };

		// QWORD 1 HI

		bool Sse3 : 1 { };
		bool PclMulDqd : 1 { };
		bool DTes64 : 1 { };
		bool Monitor : 1 { };
		bool DsCpl : 1 { };
		bool Vmx : 1 { };
		bool Smx : 1 { };
		bool Est : 1 { };
		bool Tm2 : 1 { };
		bool Ssse3 : 1 { };
		bool CnxtId : 1 { };
		bool Sdbg : 1 { };
		bool Fma3 : 1 { };
		bool Cx16 : 1 { };
		bool Xtpr : 1 { };
		bool Pdcm : 1 { };
		bool Reserved2 : 1 { };
		bool Pcid : 1 { };
		bool Dca : 1 { };
		bool Sse41 : 1 { };
		bool Sse42 : 1 { };
		bool X2Apic : 1 { };
		bool MovBe : 1 { };
		bool PopCnt : 1 { };
		bool TscDeadline : 1 { };
		bool Aes : 1 { };
		bool XSave : 1 { };
		bool OsXSave : 1 { };
		bool Avx : 1 { };
		bool F16C : 1 { };
		bool RdRnd : 1 { };
		bool HyperVisor : 1 { };

		// QWORD 2 LO

		bool FsGsBase : 1 { };
		bool TscAdjust : 1 { };
		bool Sgx : 1 { };
		bool Bmi1 : 1 { };
		bool Hle : 1 { };
		bool Avx2 : 1 { };
		bool FdpExcept : 1 { };
		bool Smep : 1 { };
		bool Bmi2 : 1 { };
		bool Erms : 1 { };
		bool InvPcid : 1 { };
		bool Rtm : 1 { };
		bool Pqm : 1 { };
		bool FpuCsDsDepr : 1 { };
		bool Mpx : 1 { };
		bool Pqe : 1 { };
		bool Avx512F : 1 { };
		bool Avx512Dq : 1 { };
		bool RdSeed : 1 { };
		bool Adx : 1 { };
		bool SMap : 1 { };
		bool Avx512Ifma : 1 { };
		bool PCommit : 1 { };
		bool ClFlushOpt : 1 { };
		bool Clwb : 1 { };
		bool IntelPt : 1 { };
		bool Avx512Pf : 1 { };
		bool Avx512Er : 1 { };
		bool Avx512Cd : 1 { };
		bool Sha : 1 { };
		bool Avx512Bw : 1 { };
		bool Avx512Vl : 1 { };

		// QWORD 2 HI

		bool PreFetchWt1 : 1 { };
		bool Avx512Vbmi : 1 { };
		bool Umip : 1 { };
		bool Pku : 1 { };
		bool OsPke : 1 { };
		bool WaitPkg : 1 { };
		bool Avx512Vbmi2 : 1 { };
		bool CetSS : 1 { };
		bool Gfni : 1 { };
		bool VAes : 1 { };
		bool VPclMulDqd : 1 { };
		bool Avx512Vnni : 1 { };
		bool Avx512Bitalg: 1 { };
		bool Reserved3 : 1 { };
		bool Avx512VPopCntdq : 1 { };
		bool Reserved4 : 1 { };
		bool Level5Paging : 1 { };
		bool MaWau0 : 1 { };
		bool MaWau1 : 1 { };
		bool MaWau2 : 1 { };
		bool MaWau3 : 1 { };
		bool MaWau4 : 1 { };
		bool RdPid : 1 { };
		bool Reserved5 : 1 { };
		bool Reserved6 : 1 { };
		bool ClDemote : 1 { };
		bool Reserved7 : 1 { };
		bool MovDiri : 1 { };
		bool MovDir64B : 1 { };
		bool EnqCmd : 1 { };
		bool SgxLc : 1 { };
		bool Pks : 1 { };

		// QUADWORD 3 LO

		bool Reserved8 : 1{ };
		bool Reserved9 : 1{ };
		bool Avx5124Vnniw: 1{ };
		bool Avx5124FMaps: 1{ };
		bool Fsrm : 1{ };
		bool Reserved10 : 1{ };
		bool Reserved11 : 1{ };
		bool Reserved12 : 1{ };
		bool Avx512Vp2Intersect: 1{ };
		bool SrbdsCtrl: 1{ };
		bool MdClear : 1{ };
		bool Reserved13: 1{ };
		bool Reserved14: 1{ };
		bool TsxForceAbort: 1{ };
		bool Serialize: 1{ };
		bool Hybrid: 1{ };
		bool Tsxldtrk: 1{ };
		bool Reserved15 : 1{ };
		bool PConfig : 1{ };
		bool Lbr : 1{ };
		bool CetIbt : 1{ };
		bool Reserved16 : 1{ };
		bool AmxBf16 : 1{ };
		bool Reserved17 : 1{ };
		bool AmxTile : 1{ };
		bool AmxInt8 : 1{ };
		bool SpecCtrl : 1{ };
		bool Stibp : 1{ };
		bool L1DFlush : 1{ };
		bool Ia32ArchCompat : 1{ };
		bool Ia32CoreCompat : 1{ };
		bool Ssbd : 1{ };

		// QUADWORD 3 HI

		bool LahfLm : 1{ };
		bool CmpLegacy : 1 { };
		bool Svm : 1 { };
		bool ExtApic: 1 { };
		bool Cr8Legacy: 1 { };
		bool Abm: 1 { };
		bool Sse4a : 1 { };
		bool MisAlignSse: 1 { };
		bool D3NowPrefetch : 1 { };
		bool OsVw : 1 { };
		bool Ibs : 1 { };
		bool Xop : 1 { };
		bool SkInit : 1 { };
		bool Wdt : 1 { };
		bool Reserved18 : 1 { };
		bool Lwp : 1 { };
		bool Fma4 : 1 { };
		bool Tce : 1 { };
		bool Reserved19 : 1 { };
		bool NodeIdMsr : 1 { };
		bool Reserved20 : 1 { };
		bool Tbm : 1 { };
		bool TopoExt : 1 { };
		bool PerfCtrCore : 1 { };
		bool PerCtrNb: 1 { };
		bool Reserved21 : 1 { };
		bool Dbx: 1 { };
		bool PerfTsc: 1 { };
		bool PcxL2i : 1 { };
		bool Reserved22 : 1 { };
		bool Reserved23 : 1 { };
		bool Reserved24 : 1 { };

		// DWORD RET

		U16 Ignored0 : 11 { };
		bool SysCall : 1 { };
		U8 Ignored1 : 7 { };
		bool Mp : 1 { };
		bool Nx : 1 { };
		bool Reserved25 : 1 { };
		bool MmmxExt : 1 { };
		U8 Ignored2 : 2{ };
		bool FxsrOpt : 1 { };
		bool Pdpe1Gb : 1 { };
		bool Rdtscp : 1 { };
		bool Reserved26 : 1 { };
		bool LongMode : 1 { };
		bool D3NowExt : 1 { };
		bool D3Now : 1 { };

		auto PrintFeatures() const -> void;
	};

	static_assert(sizeof(CpuFeatureBits) == 30);
	static_assert(std::is_trivially_copyable_v<CpuFeatureBits>);

	/// <summary>
	/// Contains merged info table.
	/// One 64-bit instance contains two 32-bit info tables.
	/// </summary>
	union MergedInfoTable
	{
		U64 Merged { };
		struct
		{
			U32 Table1;
			U32 Table2;
		};
	};

	static_assert(sizeof(MergedInfoTable) == 8);
	static_assert(std::is_trivially_copyable_v<MergedInfoTable>);

	/// <summary>
	/// Returns 1 if the current CPU supports the CPUID instruction, else 0.
	/// Implementation: Source/Arch/X86_64.CpuId.S
	/// </summary>
	extern "C" auto Asm_IsCpuIdSupported() noexcept -> BYTE;

	/// <summary>
	/// Assembly routine which calls cpuid
	/// multiple time to determine all cpu features.
	/// The first 6 feature tables are returned via
	/// out1, out2 and out3. Each contains two info tables.
	/// (See MergedInfoTable). The last info table is returned
	/// as return value. Do not use this function, better use
	/// CpuFeatureBits instead, which calls this function in the
	/// constructor.
	/// Implementation: Source/Arch/X86_64.CpuId.S
	/// </summary>
	extern "C" auto Asm_CpuId
	(
		MergedInfoTable& out1,
		MergedInfoTable& out2,
		MergedInfoTable& out3
	) noexcept -> DOUBLEWORD;
}
