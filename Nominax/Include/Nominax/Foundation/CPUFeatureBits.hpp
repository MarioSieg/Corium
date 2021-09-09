// File: CPUFeatureBits.hpp
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

#include <array>
#include <bitset>
#include <string_view>

#include "Algorithm.hpp"

#include "Platform.hpp"

namespace Nominax::Foundation
{
	enum class CPUFeatureBits : std::uint8_t
	{
		/// <summary>
		/// Onboard x87 FPU
		/// </summary>
		Fpu = 0,

		/// <summary>
		/// Virtual 8086 mode extensions (such as VIF, VIP, PIV)
		/// </summary>
		Vme = 1,

		/// <summary>
		/// Debugging extensions (CR4 bit 3)
		/// </summary>
		De = 2,

		/// <summary>
		/// Page WordSize Extension
		/// </summary>
		Pse = 3,

		/// <summary>
		/// Time Stamp Counter
		/// </summary>
		Tsc = 4,

		/// <summary>
		/// Model-specific registers
		/// </summary>
		Msr = 5,

		/// <summary>
		/// Physical Address Extension
		/// </summary>
		Pae = 6,

		/// <summary>
		/// Machine Check Exception
		/// </summary>
		Mce = 7,

		/// <summary>
		/// CMPXCHG8 (compare-and-swap) instruction
		/// </summary>
		Cx8 = 8,

		/// <summary>
		/// On-board Advanced Programmable InterruptStatus Controller
		/// </summary>
		Apic = 9,

		/// <summary>
		/// SYSENTER and SYSEXIT instructions
		/// </summary>
		Sep = 11,

		/// <summary>
		/// Memory Type Range Registers
		/// </summary>
		Mtrr = 12,

		/// <summary>
		/// Page Global Enable bit in CR4
		/// </summary>
		Pge = 13,

		/// <summary>
		/// Machine check architecture
		/// </summary>
		Mca = 14,

		/// <summary>
		///	Conditional move and FCMOV instructions
		/// </summary>
		CMov = 15,

		/// <summary>
		/// Page Attribute Table
		/// </summary>
		Pat = 16,

		/// <summary>
		/// 36-bit page size extension
		/// </summary>
		Pse36 = 17,

		/// <summary>
		/// Processor Serial Number
		/// </summary>
		Psn = 18,

		/// <summary>
		/// CLFLUSH instruction (SSE2)
		/// </summary>
		Clfsh = 19,

		/// <summary>
		/// Debug store: save trace of executed jumps
		/// </summary>
		Ds = 21,

		/// <summary>
		/// Onboard thermal control MSRs for ACPI
		/// </summary>
		Acpi = 22,


		/// <summary>
		/// MMX instructions
		/// </summary>
		Mmx = 23,

		/// <summary>
		/// FXSAVE, FXRESTOR instructions, CR4 bit 9
		/// </summary>
		Fxsr = 24,

		/// <summary>
		/// SSE instructions (a.k.a. Katmai New Instructions)
		/// </summary>
		Sse = 25,

		/// <summary>
		/// SSE2 instructions
		/// </summary>
		Sse2 = 26,

		/// <summary>
		/// CPU cache implements self-snoop
		/// </summary>
		Ss = 27,

		/// <summary>
		/// Hyper-threading
		/// </summary>
		Htt = 28,

		/// <summary>
		/// Thermal monitor automatically limits temperature
		/// </summary>
		Tm = 29,

		/// <summary>
		/// IA64 processor emulating x86
		/// </summary>
		Ia64 = 30,

		/// <summary>
		/// Pending Break Enable (PBE# pin) wakeup capability
		/// </summary>
		Pbe = 31,

		/// <summary>
		/// Prescott New Instructions-SSE3 (PNI)
		/// </summary>		
		Sse3 = 32,

		/// <summary>
		/// Carry-less Multiplication (CLMUL)
		/// </summary>
		PclMulDqd = 33,

		/// <summary>
		/// 64-bit debug store (edx bit 21)
		/// </summary>
		DTes64 = 34,

		/// <summary>
		/// MONITOR and MWAIT instructions (SSE3)
		/// </summary>
		Monitor = 35,

		/// <summary>
		/// CPL qualified debug store
		/// </summary>
		DsCpl = 36,

		/// <summary>
		/// Virtual Machine eXtensions
		/// </summary>
		Vmx = 37,

		/// <summary>
		/// Safer Mode Extensions (LaGrande)
		/// </summary>
		Smx = 38,

		/// <summary>
		/// Enhanced SpeedStep
		/// </summary>
		Est = 39,

		/// <summary>
		/// Thermal Monitor 2
		/// </summary>
		Tm2 = 40,

		/// <summary>
		/// Supplemental SSE3 instructions
		/// </summary>
		Ssse3 = 41,

		/// <summary>
		/// L1 Context ID
		/// </summary>
		CnxtId = 42,

		/// <summary>
		/// Silicon Debug interface
		/// </summary>
		Sdbg = 43,

		/// <summary>
		/// Fused multiply-add (FMA3)
		/// </summary>
		Fma3 = 44,

		/// <summary>
		/// CMPXCHG16B instruction
		/// </summary>
		Cx16 = 45,

		/// <summary>
		/// Can disable sending task priority messages
		/// </summary>
		Xtpr = 46,

		/// <summary>
		/// Perfmon & debug capability
		/// </summary>
		Pdcm = 47,

		/// <summary>
		/// Process context identifiers (CR4 bit 17)
		/// </summary>
		Pcid = 49,

		/// <summary>
		/// Direct cache access for DMA writes
		/// </summary>
		Dca = 50,

		/// <summary>
		/// SSE4.1 instructions
		/// </summary>
		Sse41 = 51,

		/// <summary>
		/// SSE4.2 instructions
		/// </summary>
		Sse42 = 52,

		/// <summary>
		/// x2APIC
		/// </summary>
		X2Apic = 53,

		/// <summary>
		/// MOVBE instruction (big-endian)
		/// </summary>
		MovBe = 54,

		/// <summary>
		/// POPCNT instruction
		/// </summary>
		PopCnt = 55,

		/// <summary>
		/// APIC implements one-shot operation using a TSC deadline value
		/// </summary>
		TscDeadLine = 56,

		/// <summary>
		/// AES instruction set
		/// </summary>
		Aes = 57,

		/// <summary>
		/// XSAVE, XRESTOR, XSETBV, XGETBV
		/// </summary>
		XSave = 58,

		/// <summary>
		/// XSAVE enabled by OS
		/// </summary>
		OsXSave = 59,

		/// <summary>
		/// Advanced Vector Extensions
		/// </summary>
		Avx = 60,

		/// <summary>
		/// F16C (half-precision) FP feature
		/// </summary>
		F16C = 61,

		/// <summary>
		/// RDRAND (on-chip random number generator) feature
		/// </summary>
		RdRand = 62,

		/// <summary>
		/// HyperVisor present (always zero on physical CPUs)
		/// </summary>
		HyperVisor = 63,

		/// <summary>
		/// Access to base of %fs and %gs
		/// </summary>
		FsGsBase = 64,

		/// <summary>
		/// IA32_TSC_ADJUST
		/// </summary>
		TscAdjust = 65,

		/// <summary>
		/// Software Guard Extensions
		/// </summary>
		Sgx = 66,

		/// <summary>
		/// Bit Manipulation Instruction Set 1
		/// </summary>
		Bmi1 = 67,

		/// <summary>
		/// TSX Hardware Lock Elision
		/// </summary>
		Hle = 68,

		/// <summary>
		/// Advanced Vector Extensions 2
		/// </summary>
		Avx2 = 69,

		/// <summary>
		/// FDP_EXCPTN_ONLY
		/// </summary>
		FdpExcept = 70,

		/// <summary>
		/// Supervisor Mode Execution Prevention
		/// </summary>
		Smep = 71,

		/// <summary>
		/// Bit Manipulation Instruction Set 2
		/// </summary>
		Bmi2 = 72,

		/// <summary>
		/// Enhanced REP MOVSB/STOSB
		/// </summary>
		Erms = 73,

		/// <summary>
		/// INVPCID instruction
		/// </summary>
		InvPcid = 74,

		/// <summary>
		/// TSX Restricted Transactional Memory
		/// </summary>
		Rtm = 75,

		/// <summary>
		/// Platform Quality of Service Monitoring
		/// </summary>
		Pqm = 76,

		/// <summary>
		/// FPU CS and FPU DS deprecated
		/// </summary>
		FpuCsDsDepr = 77,

		/// <summary>
		/// Intel MPX (Memory Protection Extensions)
		/// </summary>
		Mpx = 78,

		/// <summary>
		/// Platform Quality of Service Enforcement
		/// </summary>
		Pwe = 79,

		/// <summary>
		/// AVX-512 Foundation
		/// </summary>
		Avx512F = 80,

		/// <summary>
		/// AVX-512 Doubleword and Quadword Instructions
		/// </summary>
		Avx512Dq = 81,

		/// <summary>
		/// RDSEED instruction
		/// </summary>
		RdSeed = 82,

		/// <summary>
		/// Intel ADX (Multi-Precision Add-Carry Instruction Extensions)
		/// </summary>
		Adx = 83,

		/// <summary>
		/// Supervisor Mode Access Prevention
		/// </summary>
		SMap = 84,

		/// <summary>
		/// Integer Fused Multiply-Add Instructions
		/// </summary>
		Avx512Ifma = 85,

		/// <summary>
		/// PCOMMIT instruction
		/// </summary>
		PCommit = 86,

		/// <summary>
		/// CLFLUSHOPT instruction
		/// </summary>
		ClFlushOpt = 87,

		/// <summary>
		/// CLWB instruction
		/// </summary>
		Clwb = 88,

		/// <summary>
		/// Intel Processor Trace
		/// </summary>
		IntelPt = 89,

		/// <summary>
		/// AVX 512 Prefetch Instructions
		/// </summary>
		Avx512Pf = 90,

		/// <summary>
		///  Exponential and Reciprocal Instructions
		/// </summary>
		Avx512Er = 91,

		/// <summary>
		/// Conflict Detection Instructions
		/// </summary>
		Avx512Cd = 92,

		/// <summary>
		/// Intel secure hashing algorithm extensions
		/// </summary>
		Sha = 93,

		/// <summary>
		/// Byte and word Instructions
		/// </summary>
		Avx512Bw = 94,

		/// <summary>
		/// Vector Length Extensions
		/// </summary>
		Avx512Vl = 95,

		/// <summary>
		/// PREFETCHWT1 instruction
		/// </summary>
		PreFetchWt1 = 96,

		/// <summary>
		/// Vector Bit Manipulation Instructions
		/// </summary>
		Avx512Vbmi = 97,

		/// <summary>
		/// User-mode Instruction Prevention
		/// </summary>
		Umip = 98,

		/// <summary>
		/// Memory Protection Keys for User-mode pages
		/// </summary>
		Pku = 99,

		/// <summary>
		/// PKU enabled by OS
		/// </summary>
		OsPku = 100,

		/// <summary>
		/// Timed pause and user-level monitor/wait
		/// </summary>
		WaitPkg = 101,

		/// <summary>
		/// AVX-512 Vector Bit Manipulation Instructions 2
		/// </summary>
		Avx512Vmbi2 = 102,

		/// <summary>
		/// Control flow enforcement (CET) shadow stack
		/// </summary>
		CetSs = 103,

		/// <summary>
		/// AVX-512	galois field instructions
		/// </summary>
		Avx512Gfni = 104,

		/// <summary>
		/// Vector AES instruction set (VEX-256/EVEX)
		/// </summary>
		VAes = 105,

		/// <summary>
		/// Vector CLMUL instruction set (VEX-256/EVEX)
		/// </summary>
		VPclMulDqd = 106,

		/// <summary>
		/// AVX-512 vector neural network instructions
		/// </summary>
		Avx512Vnni = 107,

		/// <summary>
		/// AVX-512 bit algorithm instructions
		/// </summary>
		Avx512Bitalg = 108,

		/// <summary>
		/// AVX-512 vector population count double and qword
		/// </summary>
		Avx512PopCntdq = 110,

		/// <summary>
		/// 5-level paging
		/// </summary>
		Level5Paging = 112,

		/// <summary>
		/// Read Processor ID and IA32_TSC_AUX
		/// </summary>
		RdPid = 118,

		/// <summary>
		/// Cache line demote
		/// </summary>
		ClDemote = 121,

		/// <summary>
		/// 
		/// </summary>
		MovDiri = 123,

		/// <summary>
		/// 
		/// </summary>
		MovDir64B = 124,

		/// <summary>
		/// Enqueue Stores
		/// </summary>
		EnqCmd = 125,

		/// <summary>
		/// SGX Launch Configuration
		/// </summary>
		SgxLc = 126,

		/// <summary>
		/// Protection keys for supervisor-mode pages
		/// </summary>
		Pks = 127,

		/// <summary>
		/// AVX-512 4 register neural network instructions
		/// </summary>
		Avx512Vnniw4 = 130,

		/// <summary>
		/// AVX-512 4 register multiply accumulation single precision
		/// </summary>
		Avx512FMaps4 = 131,

		/// <summary>
		/// Fast Short REP MOVSB
		/// </summary>
		Fsrm = 132,

		/// <summary>
		/// AVX-512 intersection
		/// </summary>
		Avx512Vp2Intersect = 136,

		/// <summary>
		/// Special register system bump pool data sampling mitigations
		/// </summary>
		SrbdsCtrl = 137,

		/// <summary>
		/// Clears CPU buffers
		/// </summary>
		MdClear = 138,

		/// <summary>
		/// 
		/// </summary>
		TsxForceAbort = 141,

		/// <summary>
		/// Serialize instruction execution
		/// </summary>
		Serialize = 142,

		/// <summary>
		/// 
		/// </summary>
		Hybrid = 143,

		/// <summary>
		/// TSX suspend load address tracking
		/// </summary>
		TsxLdTrk = 144,

		/// <summary>
		/// Platform configuration (Memory Encryption Technologies Instructions)
		/// </summary>
		PConfig = 146,

		/// <summary>
		/// Architectural Last Branch Records
		/// </summary>
		Pbr = 147,

		/// <summary>
		/// Control flow enforcement (CET) indirect branch tracking
		/// </summary>
		CetIbt = 148,

		/// <summary>
		/// Tile computation on bfloat16 numbers
		/// </summary>
		AmxBf16 = 150,

		/// <summary>
		/// Tile architecture
		/// </summary>
		AmxTile = 152,

		/// <summary>
		///  Tile computation on 8-bit integers
		/// </summary>
		AmxInt8 = 153,

		/// <summary>
		/// Speculation Control, part of Indirect Branch 
		/// Indirect Branch Restricted Speculation(IBRS)
		///	SpecIndirect Branch Prediction Barrier(IBPB)
		///	</summary>
		Ctrl = 154,

		/// <summary>
		/// Single thread indirect branch predictor, part of IBC
		/// </summary>
		Stibp = 155,

		/// <summary>
		/// IA32_FLUSH_CMD MSR
		/// </summary>
		L1DFlush = 156,

		/// <summary>
		/// Speculative side channel mitigations
		/// </summary>
		Ia32ArchCompat = 157,

		/// <summary>
		/// Support for a MSR listing model-specific core capabilities
		/// </summary>
		Ia32CoreCompat = 158,

		/// <summary>
		/// Speculative Store Bypass Disable,
		/// as mitigation for Speculative Store Bypass (IA32_SPEC_CTRL)
		/// </summary>
		Ssbd = 159,

		/// <summary>
		/// LAHF/SAHF in long mode
		/// </summary>
		LahfLm = 160,

		/// <summary>
		/// Hyperthreading not valid
		/// </summary>
		CmpLegacy = 161,

		/// <summary>
		/// Secure Virtual Machine
		/// </summary>
		Svm = 162,

		/// <summary>
		/// Extended APIC space
		/// </summary>
		ExtApic = 163,

		/// <summary>
		/// CR8 in 32-bit mode
		/// </summary>
		Cr8Legacy = 164,

		/// <summary>
		/// Advanced bit manipulation (lzcnt and popcnt)
		/// </summary>
		Avm = 165,

		/// <summary>
		/// SSE4a
		/// </summary>
		Sse4A = 166,

		/// <summary>
		/// Misaligned SSE mode
		/// </summary>
		MisAlignedSse = 167,

		/// <summary>
		/// PREFETCH and PREFETCHW instructions
		/// </summary>
		D3NowPrefetch = 168,

		/// <summary>
		/// OS Visible Workaround
		/// </summary>
		OsVw = 169,

		/// <summary>
		/// Instruction based sampling
		/// </summary>
		Ibs = 170,

		/// <summary>
		/// XOP instruction set
		/// </summary>
		Xop = 171,

		/// <summary>
		/// SKINIT/STGI instructions
		/// </summary>
		SkInit = 172,

		/// <summary>
		/// Watchdog timer
		/// </summary>
		Dgt = 173,

		/// <summary>
		/// Light Weight Profiling[25]
		/// </summary>
		Lwp = 175,

		/// <summary>
		/// 4 operands fused multiply-add
		/// </summary>
		Fma4 = 176,

		/// <summary>
		/// Translation cache extension
		/// </summary>
		Tce = 177,

		/// <summary>
		/// NodeID MSR
		/// </summary>
		NodeIdMdr = 179,

		/// <summary>
		/// Trailing bit manipulation
		/// </summary>
		Tbm = 181,

		/// <summary>
		/// Topology extensions
		/// </summary>
		TopoExt = 182,

		/// <summary>
		///  Core performance counter extensions
		/// </summary>
		PerfCtrCore = 183,

		/// <summary>
		/// NB performance counter extensions
		/// </summary>
		PerCtrNb = 184,

		/// <summary>
		/// Data breakpoint extensions
		/// </summary>
		Dbx = 186,

		/// <summary>
		/// Performance TSC
		/// </summary>
		PerfTsc = 187,

		/// <summary>
		/// L2I perf counter extensions
		/// </summary>
		PcxL2i = 188,

		/// <summary>
		///  SYSCALL and SYSRET instructions
		/// </summary>
		SysCall = 203,

		/// <summary>
		/// Multiprocessor capable
		/// </summary>
		MpCap = 211,

		/// <summary>
		/// NX bit
		/// </summary>
		Nx = 212,

		/// <summary>
		/// Extended MMX
		/// </summary>
		MmxEx = 214,

		/// <summary>
		/// FXSAVE/FXRSTOR optimizations
		/// </summary>
		FxsrOpt = 217,

		/// <summary>
		/// Gigabyte pages
		/// </summary>
		Pdpe1Gb = 218,

		/// <summary>
		/// RDTSCP instruction
		/// </summary>
		RdTscP = 219,

		/// <summary>
		/// Long mode
		/// </summary>
		LongMode = 221,

		/// <summary>
		/// Extended 3DNow
		/// </summary>
		D3NowExt = 222,

		/// <summary>
		/// 3DNow!
		/// </summary>
		D3Now = 223,


		/// <summary>
		/// Amount of bits.
		/// </summary>
		Count_
	};

	/// <summary>
	/// Contains all CPU feature names.
	/// </summary>
	constexpr std::array<std::string_view, ToUnderlying(CPUFeatureBits::Count_)> CPU_FEATURE_BIT_NAMES
	{
		#if NOX_ARCH_X86_64
		"FPU",
		"VME",
		"DE",
		"PSE",
		"TSC",
		"MSR",
		"PAE",
		"MCE",
		"CX8",
		"APIC",
		{ },
		"SEP",
		"MTRR",
		"PGE",
		"MCA",
		"CMOV",
		"PAT",
		"PSE36",
		"PSN",
		"CLFSH",
		{ },
		"DS",
		"ACPI",
		"MMX",
		"FXSR",
		"SSE",
		"SSE2",
		"SS",
		"HTT",
		"TM",
		"IA64",
		"PBE",
		"SSE3",
		"PCLMULDQD",
		"DTES64",
		"MONITOR",
		"DSCPL",
		"VMX",
		"SMX",
		"EST",
		"TM2",
		"SSSE3",
		"CNXTID",
		"SDBG",
		"FMA3",
		"CX16",
		"XTPR",
		"PDCM",
		{ },
		"PCID",
		"DCA",
		"SSE41",
		"SSE42",
		"X2APIC",
		"MOVBE",
		"POPCNT",
		"TSCDEADLINE",
		"AES",
		"XSAVE",
		"OSXSAVE",
		"AVX",
		"F16C",
		"RDRAND",
		"HYPERVISOR",
		"FSGSBASE",
		"TSCADJUST",
		"SGX",
		"BMI1",
		"HLE",
		"AVX2",
		"FDPEXCEPT",
		"SMEP",
		"BMI2",
		"ERMS",
		"INVPCID",
		"RTM",
		"PQM",
		"FPUCSDSDEPR",
		"MPX",
		"PWE",
		"AVX512F",
		"AVX512DQ",
		"RDSEED",
		"ADX",
		"SMAP",
		"AVX512IFMA",
		"PCOMMIT",
		"CLFLUSHOPT",
		"CLWB",
		"INTELPT",
		"AVX512PF",
		"AVX512ER",
		"AVX512CD",
		"SHA",
		"AVX512BW",
		"AVX512VL",
		"PREFETCHWT1",
		"AVX512VBMI",
		"UMIP",
		"PKU",
		"OSPKU",
		"WAITPKG",
		"AVX512VMBI2",
		"CETSS",
		"AVX512GFNI",
		"VAES",
		"VPCLMULDQD",
		"AVX512VNNI",
		"AVX512BITALG",
		{ },
		"AVX512POPCNTDQ",
		{ },
		"LEVEL5PAGING",
		{ },
		{ },
		{ },
		{ },
		{ },
		"RDPID",
		{ },
		{ },
		"CLDEMOTE",
		{ },
		"MOVDIRI",
		"MOVDIR64B",
		"ENQCMD",
		"SGXLC",
		"PKS",
		{ },
		{ },
		"AVX512VNNIW4",
		"AVX512FMAPS4",
		"FSRM",
		{ },
		{ },
		{ },
		"AVX512VP2INTERSECT",
		"SRBDSCTRL",
		"MDCLEAR",
		{ },
		{ },
		"TSXFORCEABORT",
		"SERIALIZE",
		"HYBRID",
		"TSXLDTRK",
		{ },
		"PCONFIG",
		"PBR",
		"CETIBT",
		{ },
		"AMXBF16",
		{ },
		"AMXTILE",
		"AMXINT8",
		"CTRL",
		"STIBP",
		"L1DFLUSH",
		"IA32ARCHCOMPAT",
		"IA32CORECOMPAT",
		"SSBD",
		"LAHFLM",
		"CMPLEGACY",
		"SVM",
		"EXTAPIC",
		"CR8LEGACY",
		"AVM",
		"SSE4A",
		"MISALIGNEDSSE",
		"D3NOWPREFETCH",
		"OSVW",
		"IBS",
		"XOP",
		"SKINIT",
		"DGT",
		{ },
		"LWP",
		"FMA4",
		"TCE",
		{ },
		"NODEIDMDR",
		{ },
		"TBM",
		"TOPOEXT",
		"PERFCTRCORE",
		"PERCTRNB",
		{ },
		"DBX",
		"PERFTSC",
		"PCXL2I",
		{ },
		{ },
		{ },
		{ },
		{ },
		{ },
		{ },
		{ },
		{ },
		{ },
		{ },
		{ },
		{ },
		{ },
		"SYSCALL",
		{ },
		{ },
		{ },
		{ },
		{ },
		{ },
		{ },
		"MPCAP",
		"NX",
		{ },
		"MMXEX",
		{ },
		{ },
		"FXSROPT",
		"PDPE1GB",
		"RDTSCP",
		{ },
		"LONGMODE",
		"D3NOWEXT",
		"D3NOW"
		#else
#error "Unimplemented architecture!"
		#endif
	};

	/// <summary>
	/// Feature mask.
	/// </summary>
	using CpuFeatureMask = std::array<bool, ToUnderlying(CPUFeatureBits::Count_)>;

	/// <summary>
	/// Bitmask storage type.
	/// </summary>
	using CpuFeatureMaskBitStorage = std::bitset<ToUnderlying(CPUFeatureBits::Count_)>;

	/// <summary>
	/// Feature mask.
	/// </summary>
	using CpuFeatureMaskBuffer = std::array<std::uint8_t, ToUnderlying(CPUFeatureBits::Count_) / CHAR_BIT>;
}
