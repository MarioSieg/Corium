// File: CpuId.cpp
// Author: Mario
// Created: 05.07.2021 4:43 PM
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

#include <array>
#include <bit>

#include "../../Include/Nominax/Foundation.hpp"

#define PRINT_CPU_FEATURE(name, has) Print(( has ) ? TextColor::Green : TextColor::Red, "{0: <18} ", name)

namespace Nominax::Arch::X86_64
{
	using namespace Common;

	CpuFeatureBits::CpuFeatureBits()
	{
		// check if cpuid is supported on system
		NOX_PANIC_ASSERT_TRUE(Asm_IsCpuIdSupported(), "CPUID instruction is not supported on system!");

		// Raw DATA.
		std::array<U8, sizeof(CpuFeatureBits)> data { };
		std::array<MergedInfoTable, 3>         chunk { };

		// Call cpuid assembly routine:
		U32 r {Asm_CpuId(&chunk[0], &chunk[1], &chunk[2])};

		// Copy parameter output quads
		std::memcpy(data.data(), chunk.data(), sizeof(MergedInfoTable) * 3);

		// Copy return value:
		std::memcpy(data.data() + sizeof(MergedInfoTable) * 3, &r, sizeof(U32));

		// Update this
		*this = std::bit_cast<CpuFeatureBits>(data);

		// Validate OS support and update flags for AVX:
		const bool avxOsSupport = this->OsXSave ? Asm_IsAvxSupportedByOs() : false;

		// Update flags requiring os support for AVX:
		this->Avx &= avxOsSupport;
		this->Avx2 &= avxOsSupport;
		this->F16C &= avxOsSupport;
		this->Avx2 &= avxOsSupport;

		// Validate OS support and update flags for AVX 512:
		const bool avx512OsSupport = this->OsXSave ? avxOsSupport && Asm_IsAvx512SupportedByOs() : false;

		// Update flags requiring OS support for AVX 512:
		this->Avx512F &= avx512OsSupport;
		this->Avx512Dq &= avx512OsSupport;
		this->Avx512Ifma &= avx512OsSupport;
		this->Avx512Pf &= avx512OsSupport;
		this->Avx512Er &= avx512OsSupport;
		this->Avx512Cd &= avx512OsSupport;
		this->Avx512Bw &= avx512OsSupport;
		this->Avx512Vl &= avx512OsSupport;
		this->Avx512Vbmi &= avx512OsSupport;
		this->Avx512Vbmi2 &= avx512OsSupport;
		this->Avx512Vnni &= avx512OsSupport;
		this->Avx512Bitalg &= avx512OsSupport;
		this->Avx512VPopCntdq &= avx512OsSupport;
		this->Avx5124FMaps &= avx512OsSupport;
		this->Avx5124Vnniw &= avx512OsSupport;
	}

	auto CpuFeatureBits::PrintFeatures() const -> void
	{
		PRINT_CPU_FEATURE("FPU", this->Fpu);
		PRINT_CPU_FEATURE("VME", this->Vme);
		PRINT_CPU_FEATURE("DE", this->De);
		PRINT_CPU_FEATURE("PSE", this->Pse);

		Print('\n');

		PRINT_CPU_FEATURE("TSC", this->Tsc);
		PRINT_CPU_FEATURE("MSR", this->Msr);
		PRINT_CPU_FEATURE("PAE", this->Pae);
		PRINT_CPU_FEATURE("MCE", this->Mce);

		Print('\n');

		PRINT_CPU_FEATURE("CMPXCHG8", this->Cx8);
		PRINT_CPU_FEATURE("APIC", this->Apic);
		PRINT_CPU_FEATURE("SEP", this->Sep);
		PRINT_CPU_FEATURE("MTRR", this->Mtrr);

		Print('\n');

		PRINT_CPU_FEATURE("PGE", this->Pge);
		PRINT_CPU_FEATURE("MCA", this->Mca);
		PRINT_CPU_FEATURE("CMOV", this->CMov);
		PRINT_CPU_FEATURE("PAT", this->Pat);

		Print('\n');

		PRINT_CPU_FEATURE("PSE36", this->Pse36);
		PRINT_CPU_FEATURE("PSN", this->Psn);
		PRINT_CPU_FEATURE("CLFSH", this->Clfsh);
		PRINT_CPU_FEATURE("DS", this->Ds);

		Print('\n');

		PRINT_CPU_FEATURE("ACPI", this->Acpi);
		PRINT_CPU_FEATURE("MMX", this->Mmx);
		PRINT_CPU_FEATURE("FXSR", this->Fxsr);
		PRINT_CPU_FEATURE("SSE", this->Sse);

		Print('\n');

		PRINT_CPU_FEATURE("SSE2", this->Sse2);
		PRINT_CPU_FEATURE("SS", this->Ss);
		PRINT_CPU_FEATURE("HTT", this->Htt);
		PRINT_CPU_FEATURE("TM", this->Tm);

		Print('\n');

		PRINT_CPU_FEATURE("IA64", this->Ia64);
		PRINT_CPU_FEATURE("PBE", this->Pbe);
		PRINT_CPU_FEATURE("SSE3", this->Sse3);
		PRINT_CPU_FEATURE("PCLMULDQD", this->PclMulDqd);

		Print('\n');

		PRINT_CPU_FEATURE("DTES64", this->DTes64);
		PRINT_CPU_FEATURE("Monitor", this->Monitor);
		PRINT_CPU_FEATURE("DSCPL", this->DsCpl);
		PRINT_CPU_FEATURE("SMX", this->Smx);

		Print('\n');

		PRINT_CPU_FEATURE("EST", this->Est);
		PRINT_CPU_FEATURE("TM2", this->Tm2);
		PRINT_CPU_FEATURE("SSSE3", this->Sse3);
		PRINT_CPU_FEATURE("CNXTID", this->CnxtId);

		Print('\n');

		PRINT_CPU_FEATURE("SDBG", this->Sdbg);
		PRINT_CPU_FEATURE("FMA3", this->Fma3);
		PRINT_CPU_FEATURE("CMPXCHG16", this->Cx16);
		PRINT_CPU_FEATURE("XPTR", this->Xtpr);

		Print('\n');

		PRINT_CPU_FEATURE("PDCM", this->Pdcm);
		PRINT_CPU_FEATURE("PCID", this->Pcid);
		PRINT_CPU_FEATURE("DCA", this->Dca);
		PRINT_CPU_FEATURE("SSE4.1", this->Sse41);

		Print('\n');

		PRINT_CPU_FEATURE("SSE4.2", this->Sse42);
		PRINT_CPU_FEATURE("X2APIC", this->X2Apic);
		PRINT_CPU_FEATURE("MOVBE", this->MovBe);
		PRINT_CPU_FEATURE("POPCNT", this->PopCnt);

		Print('\n');

		PRINT_CPU_FEATURE("TSCDeadline", this->TscDeadline);
		PRINT_CPU_FEATURE("AES", this->Aes);
		PRINT_CPU_FEATURE("XSave", this->XSave);
		PRINT_CPU_FEATURE("OsXSave", this->OsXSave);

		Print('\n');

		PRINT_CPU_FEATURE("AVX", this->Avx);
		PRINT_CPU_FEATURE("F16C", this->F16C);
		PRINT_CPU_FEATURE("RDRND", this->RdRnd);
		PRINT_CPU_FEATURE("HyperVisor", this->HyperVisor);

		Print('\n');

		PRINT_CPU_FEATURE("FSGSBase", this->FsGsBase);
		PRINT_CPU_FEATURE("TSCAdjust", this->TscAdjust);
		PRINT_CPU_FEATURE("SGX", this->Sgx);
		PRINT_CPU_FEATURE("BMI1", this->Bmi1);

		Print('\n');

		PRINT_CPU_FEATURE("HLE", this->Hle);
		PRINT_CPU_FEATURE("AVX2", this->Avx2);
		PRINT_CPU_FEATURE("FDPExcept", this->FdpExcept);
		PRINT_CPU_FEATURE("SMEP", this->Smep);

		Print('\n');

		PRINT_CPU_FEATURE("BMI2", this->Bmi2);
		PRINT_CPU_FEATURE("ERMS", this->Erms);
		PRINT_CPU_FEATURE("INVPCID", this->InvPcid);
		PRINT_CPU_FEATURE("RTM", this->Rtm);

		Print('\n');

		PRINT_CPU_FEATURE("PQM", this->Pqm);
		PRINT_CPU_FEATURE("FPUCSDSDEPR", this->FpuCsDsDepr);
		PRINT_CPU_FEATURE("MPX", this->Mpx);
		PRINT_CPU_FEATURE("PQE", this->Pqe);

		Print('\n');

		PRINT_CPU_FEATURE("AVX512F", this->Avx512F);
		PRINT_CPU_FEATURE("AVX512DQ", this->Avx512Dq);
		PRINT_CPU_FEATURE("RDSEED", this->RdSeed);
		PRINT_CPU_FEATURE("ADX", this->Adx);

		Print('\n');

		PRINT_CPU_FEATURE("SMAP", this->SMap);
		PRINT_CPU_FEATURE("AVX512IFMA", this->Avx512Ifma);
		PRINT_CPU_FEATURE("PCommit", this->PCommit);
		PRINT_CPU_FEATURE("CLFlushOpt", this->ClFlushOpt);

		Print('\n');

		PRINT_CPU_FEATURE("CLWB", this->Clwb);
		PRINT_CPU_FEATURE("IntelPt", this->IntelPt);
		PRINT_CPU_FEATURE("AVX512PF", this->Avx512Pf);
		PRINT_CPU_FEATURE("AVX512ER", this->Avx512Er);

		Print('\n');

		PRINT_CPU_FEATURE("AVX512CD", this->Avx512Cd);
		PRINT_CPU_FEATURE("SHA", this->Sha);
		PRINT_CPU_FEATURE("AVX512BW", this->Avx512Bw);
		PRINT_CPU_FEATURE("AVX512VL", this->Avx512Vl);

		Print('\n');

		PRINT_CPU_FEATURE("PreFetchWt1", this->PreFetchWt1);
		PRINT_CPU_FEATURE("AVX512VBMI1", this->Avx512Vbmi);
		PRINT_CPU_FEATURE("UMIP", this->Umip);
		PRINT_CPU_FEATURE("PKU", this->Pku);

		Print('\n');

		PRINT_CPU_FEATURE("OSPKE", this->OsPke);
		PRINT_CPU_FEATURE("WaitPKG", this->WaitPkg);
		PRINT_CPU_FEATURE("AVX512VBMI2", this->Avx512Vbmi2);
		PRINT_CPU_FEATURE("CETSS", this->CetSS);

		Print('\n');

		PRINT_CPU_FEATURE("GFNI", this->Gfni);
		PRINT_CPU_FEATURE("VAES", this->VAes);
		PRINT_CPU_FEATURE("VPCLMULDQD", this->VPclMulDqd);
		PRINT_CPU_FEATURE("AVX512VNNI", this->Avx512Vnni);

		Print('\n');

		PRINT_CPU_FEATURE("AVX512BITALG", this->Avx512Bitalg);
		PRINT_CPU_FEATURE("AVX512VPOPCNTDQ", this->Avx512VPopCntdq);
		PRINT_CPU_FEATURE("5LevelPaging", this->Level5Paging);
		PRINT_CPU_FEATURE("RDPID", this->RdPid);

		Print('\n');

		PRINT_CPU_FEATURE("CLDemote", this->ClDemote);
		PRINT_CPU_FEATURE("MOVDIRI", this->MovDiri);
		PRINT_CPU_FEATURE("MOVDIR64B", this->MovDir64B);
		PRINT_CPU_FEATURE("EQNCMD", this->EnqCmd);

		Print('\n');

		PRINT_CPU_FEATURE("SGXLC", this->SgxLc);
		PRINT_CPU_FEATURE("PKS", this->Pks);
		PRINT_CPU_FEATURE("AVX512VNNIW", this->Avx5124Vnniw);
		PRINT_CPU_FEATURE("AVX512FMAPS", this->Avx5124FMaps);

		Print('\n');

		PRINT_CPU_FEATURE("FSRM", this->Fsrm);
		PRINT_CPU_FEATURE("AVX512VP2INTERSECT", this->Avx512Vp2Intersect);
		PRINT_CPU_FEATURE("SRBDSCTRL", this->SrbdsCtrl);
		PRINT_CPU_FEATURE("MDCLEAR", this->MdClear);

		Print('\n');

		PRINT_CPU_FEATURE("TSXForceAbort", this->TsxForceAbort);
		PRINT_CPU_FEATURE("Serialize", this->Serialize);
		PRINT_CPU_FEATURE("Hybrid", this->Hybrid);
		PRINT_CPU_FEATURE("TSXLDTRK", this->Tsxldtrk);

		Print('\n');

		PRINT_CPU_FEATURE("PConfig", this->PConfig);
		PRINT_CPU_FEATURE("LBR", this->Lbr);
		PRINT_CPU_FEATURE("CETIBT", this->CetIbt);
		PRINT_CPU_FEATURE("AMXBF16", this->AmxBf16);

		Print('\n');

		PRINT_CPU_FEATURE("AMXTile", this->AmxTile);
		PRINT_CPU_FEATURE("AMXInt8", this->AmxInt8);
		PRINT_CPU_FEATURE("SpecCTRL", this->SpecCtrl);
		PRINT_CPU_FEATURE("STIBP", this->Stibp);

		Print('\n');

		PRINT_CPU_FEATURE("L1DFlush", this->L1DFlush);
		PRINT_CPU_FEATURE("IA32ArchCompat", this->Ia32CoreCompat);
		PRINT_CPU_FEATURE("IA32CoreCompat", this->Ia32CoreCompat);
		PRINT_CPU_FEATURE("SSBD", this->Ssbd);

		Print('\n');

		PRINT_CPU_FEATURE("LAHFLM", this->LahfLm);
		PRINT_CPU_FEATURE("CMPLegacy", this->CmpLegacy);
		PRINT_CPU_FEATURE("SVM", this->Svm);
		PRINT_CPU_FEATURE("ExtAPIC", this->ExtApic);

		Print('\n');

		PRINT_CPU_FEATURE("CR8Legacy", this->Cr8Legacy);
		PRINT_CPU_FEATURE("ABM", this->Abm);
		PRINT_CPU_FEATURE("SSE4A", this->Sse4a);
		PRINT_CPU_FEATURE("MisAlignSSE", this->MisAlignSse);

		Print('\n');

		PRINT_CPU_FEATURE("3DNowPrefetch", this->D3NowPrefetch);
		PRINT_CPU_FEATURE("OSVW", this->OsVw);
		PRINT_CPU_FEATURE("IBS", this->Ibs);
		PRINT_CPU_FEATURE("XOP", this->Xop);

		Print('\n');

		PRINT_CPU_FEATURE("SKInit", this->SkInit);
		PRINT_CPU_FEATURE("WDT", this->Wdt);
		PRINT_CPU_FEATURE("LWP", this->Lwp);
		PRINT_CPU_FEATURE("FMA4", this->Fma4);

		Print('\n');

		PRINT_CPU_FEATURE("TCE", this->Tce);
		PRINT_CPU_FEATURE("NodeIDMSR", this->NodeIdMsr);
		PRINT_CPU_FEATURE("TBM", this->Tbm);
		PRINT_CPU_FEATURE("TopoExt", this->TopoExt);

		Print('\n');

		PRINT_CPU_FEATURE("PerfCTRCore", this->PerfCtrCore);
		PRINT_CPU_FEATURE("PerfCTRNB", this->PerCtrNb);
		PRINT_CPU_FEATURE("DBX", this->Dbx);
		PRINT_CPU_FEATURE("PerfTSC", this->PerfTsc);

		Print('\n');

		PRINT_CPU_FEATURE("PCXL2I", this->PcxL2i);
		PRINT_CPU_FEATURE("SYSCALL", this->SysCall);
		PRINT_CPU_FEATURE("MP", this->Mp);
		PRINT_CPU_FEATURE("NX", this->Nx);

		Print('\n');

		PRINT_CPU_FEATURE("MMXExt", this->MmmxExt);
		PRINT_CPU_FEATURE("FXSROpt", this->FxsrOpt);
		PRINT_CPU_FEATURE("PDPE1GB", this->Pdpe1Gb);
		PRINT_CPU_FEATURE("RDTSCP", this->Rdtscp);

		Print('\n');

		PRINT_CPU_FEATURE("LM", this->LongMode);
		PRINT_CPU_FEATURE("3DNowExt", this->D3NowExt);
		PRINT_CPU_FEATURE("3DNow", this->D3Now);

		Print('\n');
	}
}

#undef PRINT_CPU_FEATURE
