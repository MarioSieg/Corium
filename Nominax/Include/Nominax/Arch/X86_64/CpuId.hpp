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

		/// <summary>
		/// Onboard x87 FPU
		/// </summary>
		bool Fpu : 1 { };

		/// <summary>
		/// Virtual 8086 mode extensions (such as VIF, VIP, PIV)
		/// </summary>
		bool Vme : 1 { };

		/// <summary>
		/// Debugging extensions (CR4 bit 3)
		/// </summary>
		bool De : 1 { };

		/// <summary>
		/// Page Size Extension
		/// </summary>
		bool Pse : 1 { };

		/// <summary>
		/// Time Stamp Counter
		/// </summary>
		bool Tsc : 1 { };

		/// <summary>
		/// Model-specific registers
		/// </summary>
		bool Msr : 1 { };

		/// <summary>
		/// Physical Address Extension
		/// </summary>
		bool Pae : 1 { };

		/// <summary>
		/// Machine Check Exception
		/// </summary>
		bool Mce : 1 { };

		/// <summary>
		/// CMPXCHG8 (compare-and-swap) instruction
		/// </summary>
		bool Cx8 : 1 { };

		/// <summary>
		/// Onboard Advanced Programmable Interrupt Controller
		/// </summary>
		bool Apic : 1 { };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved0 : 1 { };

		/// <summary>
		/// SYSENTER and SYSEXIT instructions
		/// </summary>
		bool Sep : 1 { };

		/// <summary>
		/// Memory Type Range Registers
		/// </summary>
		bool Mtrr : 1 { };

		/// <summary>
		/// Page Global Enable bit in CR4
		/// </summary>
		bool Pge : 1 { };

		/// <summary>
		/// Machine check architecture
		/// </summary>
		bool Mca : 1 { };

		/// <summary>
		///	Conditional move and FCMOV instructions
		/// </summary>
		bool CMov : 1 { };

		/// <summary>
		/// Page Attribute Table
		/// </summary>
		bool Pat : 1 { };

		/// <summary>
		/// 36-bit page size extension
		/// </summary>
		bool Pse36 : 1 { };

		/// <summary>
		/// Processor Serial Number
		/// </summary>
		bool Psn : 1 { };

		/// <summary>
		/// CLFLUSH instruction (SSE2)
		/// </summary>
		bool Clfsh : 1 { };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved1 : 1 { };

		/// <summary>
		/// Debug store: save trace of executed jumps
		/// </summary>
		bool Ds : 1 { };

		/// <summary>
		/// Onboard thermal control MSRs for ACPI
		/// </summary>
		bool Acpi : 1 { };

		/// <summary>
		/// MMX instructions
		/// </summary>
		bool Mmx : 1 { };

		/// <summary>
		/// FXSAVE, FXRESTOR instructions, CR4 bit 9
		/// </summary>
		bool Fxsr : 1 { };

		/// <summary>
		/// SSE instructions (a.k.a. Katmai New Instructions)
		/// </summary>
		bool Sse : 1 { };

		/// <summary>
		/// SSE2 instructions
		/// </summary>
		bool Sse2 : 1 { };

		/// <summary>
		/// CPU cache implements self-snoop
		/// </summary>
		bool Ss : 1 { };

		/// <summary>
		/// Hyper-threading
		/// </summary>
		bool Htt : 1 { };

		/// <summary>
		/// Thermal monitor automatically limits temperature
		/// </summary>
		bool Tm : 1 { };

		/// <summary>
		/// IA64 processor emulating x86
		/// </summary>
		bool Ia64 : 1 { };

		/// <summary>
		/// Pending Break Enable (PBE# pin) wakeup capability
		/// </summary>
		bool Pbe : 1 { };

		// QWORD 1 HI

		/// <summary>
		/// Prescott New Instructions-SSE3 (PNI)
		/// </summary>
		bool Sse3 : 1 { };

		/// <summary>
		/// Carry-less Multiplication (CLMUL)
		/// </summary>
		bool PclMulDqd : 1 { };

		/// <summary>
		/// 64-bit debug store (edx bit 21)
		/// </summary>
		bool DTes64 : 1 { };

		/// <summary>
		/// MONITOR and MWAIT instructions (SSE3)
		/// </summary>
		bool Monitor : 1 { };

		/// <summary>
		/// CPL qualified debug store
		/// </summary>
		bool DsCpl : 1 { };

		/// <summary>
		/// Virtual Machine eXtensions
		/// </summary>
		bool Vmx : 1 { };

		/// <summary>
		/// Safer Mode Extensions (LaGrande)
		/// </summary>
		bool Smx : 1 { };

		/// <summary>
		/// Enhanced SpeedStep
		/// </summary>
		bool Est : 1 { };

		/// <summary>
		/// Thermal Monitor 2
		/// </summary>
		bool Tm2 : 1 { };

		/// <summary>
		/// Supplemental SSE3 instructions
		/// </summary>
		bool Ssse3 : 1 { };

		/// <summary>
		/// L1 Context ID
		/// </summary>
		bool CnxtId : 1 { };

		/// <summary>
		/// Silicon Debug interface
		/// </summary>
		bool Sdbg : 1 { };

		/// <summary>
		/// Fused multiply-add (FMA3)
		/// </summary>
		bool Fma3 : 1 { };

		/// <summary>
		/// CMPXCHG16B instruction
		/// </summary>
		bool Cx16 : 1 { };

		/// <summary>
		/// Can disable sending task priority messages
		/// </summary>
		bool Xtpr : 1 { };

		/// <summary>
		/// Perfmon & debug capability
		/// </summary>
		bool Pdcm : 1 { };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved2 : 1 { };

		/// <summary>
		/// Process context identifiers (CR4 bit 17)
		/// </summary>
		bool Pcid : 1 { };

		/// <summary>
		/// Direct cache access for DMA writes
		/// </summary>
		bool Dca : 1 { };

		/// <summary>
		/// SSE4.1 instructions
		/// </summary>
		bool Sse41 : 1 { };

		/// <summary>
		/// SSE4.2 instructions
		/// </summary>
		bool Sse42 : 1 { };

		/// <summary>
		/// x2APIC
		/// </summary>
		bool X2Apic : 1 { };

		/// <summary>
		/// MOVBE instruction (big-endian)
		/// </summary>
		bool MovBe : 1 { };

		/// <summary>
		/// POPCNT instruction
		/// </summary>
		bool PopCnt : 1 { };

		/// <summary>
		/// APIC implements one-shot operation using a TSC deadline value
		/// </summary>
		bool TscDeadline : 1 { };

		/// <summary>
		/// AES instruction set
		/// </summary>
		bool Aes : 1 { };

		/// <summary>
		/// XSAVE, XRESTOR, XSETBV, XGETBV
		/// </summary>
		bool XSave : 1 { };

		/// <summary>
		/// XSAVE enabled by OS
		/// </summary>
		bool OsXSave : 1 { };

		/// <summary>
		/// Advanced Vector Extensions
		/// </summary>
		bool Avx : 1 { };

		/// <summary>
		/// F16C (half-precision) FP feature
		/// </summary>
		bool F16C : 1 { };

		/// <summary>
		/// RDRAND (on-chip random number generator) feature
		/// </summary>
		bool RdRnd : 1 { };

		/// <summary>
		/// Hypervisor present (always zero on physical CPUs)
		/// </summary>
		bool HyperVisor : 1 { };

		// QWORD 2 LO

		/// <summary>
		/// Access to base of %fs and %gs
		/// </summary>
		bool FsGsBase : 1 { };

		/// <summary>
		/// IA32_TSC_ADJUST
		/// </summary>
		bool TscAdjust : 1 { };

		/// <summary>
		/// Software Guard Extensions
		/// </summary>
		bool Sgx : 1 { };

		/// <summary>
		/// Bit Manipulation Instruction Set 1
		/// </summary>
		bool Bmi1 : 1 { };

		/// <summary>
		/// TSX Hardware Lock Elision
		/// </summary>
		bool Hle : 1 { };

		/// <summary>
		/// Advanced Vector Extensions 2
		/// </summary>
		bool Avx2 : 1 { };

		/// <summary>
		/// FDP_EXCPTN_ONLY
		/// </summary>
		bool FdpExcept : 1 { };

		/// <summary>
		/// Supervisor Mode Execution Prevention
		/// </summary>
		bool Smep : 1 { };

		/// <summary>
		/// Bit Manipulation Instruction Set 2
		/// </summary>
		bool Bmi2 : 1 { };

		/// <summary>
		/// Enhanced REP MOVSB/STOSB
		/// </summary>
		bool Erms : 1 { };

		/// <summary>
		/// INVPCID instruction
		/// </summary>
		bool InvPcid : 1 { };

		/// <summary>
		/// TSX Restricted Transactional Memory
		/// </summary>
		bool Rtm : 1 { };

		/// <summary>
		/// Platform Quality of Service Monitoring
		/// </summary>
		bool Pqm : 1 { };

		/// <summary>
		/// 	FPU CS and FPU DS deprecated
		/// </summary>
		bool FpuCsDsDepr : 1 { };

		/// <summary>
		/// 	Intel MPX (Memory Protection Extensions)
		/// </summary>
		bool Mpx : 1 { };

		/// <summary>
		/// 	Platform Quality of Service Enforcement
		/// </summary>
		bool Pqe : 1 { };

		/// <summary>
		/// 	AVX-512 Foundation
		/// </summary>
		bool Avx512F : 1 { };

		/// <summary>
		/// AVX-512 Doubleword and Quadword Instructions
		/// </summary>
		bool Avx512Dq : 1 { };

		/// <summary>
		/// RDSEED instruction
		/// </summary>
		bool RdSeed : 1 { };

		/// <summary>
		/// Intel ADX (Multi-Precision Add-Carry Instruction Extensions)
		/// </summary>
		bool Adx : 1 { };

		/// <summary>
		/// 	Supervisor Mode Access Prevention
		/// </summary>
		bool SMap : 1 { };

		/// <summary>
		/// Integer Fused Multiply-Add Instructions
		/// </summary>
		bool Avx512Ifma : 1 { };

		/// <summary>
		/// PCOMMIT instruction
		/// </summary>
		bool PCommit : 1 { };

		/// <summary>
		/// CLFLUSHOPT instruction
		/// </summary>
		bool ClFlushOpt : 1 { };

		/// <summary>
		/// 	CLWB instruction
		/// </summary>
		bool Clwb : 1 { };

		/// <summary>
		/// 	Intel Processor Trace
		/// </summary>
		bool IntelPt : 1 { };

		/// <summary>
		/// Prefetch Instructions
		/// </summary>
		bool Avx512Pf : 1 { };

		/// <summary>
		///  Exponential and Reciprocal Instructions
		/// </summary>
		bool Avx512Er : 1 { };

		/// <summary>
		/// Conflict Detection Instructions
		/// </summary>
		bool Avx512Cd : 1 { };

		/// <summary>
		/// 	Intel SHA extensions
		/// </summary>
		bool Sha : 1 { };

		/// <summary>
		/// Byte and Word Instructions
		/// </summary>
		bool Avx512Bw : 1 { };

		/// <summary>
		/// Vector Length Extensions
		/// </summary>
		bool Avx512Vl : 1 { };

		// QWORD 2 HI

		/// <summary>
		/// PREFETCHWT1 instruction
		/// </summary>
		bool PreFetchWt1 : 1 { };

		/// <summary>
		/// Vector Bit Manipulation Instructions
		/// </summary>
		bool Avx512Vbmi : 1 { };

		/// <summary>
		/// User-mode Instruction Prevention
		/// </summary>
		bool Umip : 1 { };

		/// <summary>
		/// Memory Protection Keys for User-mode pages
		/// </summary>
		bool Pku : 1 { };

		/// <summary>
		/// PKU enabled by OS
		/// </summary>
		bool OsPke : 1 { };

		/// <summary>
		/// Timed pause and user-level monitor/wait
		/// </summary>
		bool WaitPkg : 1 { };

		/// <summary>
		/// AVX-512 Vector Bit Manipulation Instructions 2
		/// </summary>
		bool Avx512Vbmi2 : 1 { };

		/// <summary>
		/// 	Control flow enforcement (CET) shadow stack
		/// </summary>
		bool CetSS : 1 { };

		/// <summary>
		/// 	Galois Field instructions
		/// </summary>
		bool Gfni : 1 { };

		/// <summary>
		/// Vector AES instruction set (VEX-256/EVEX)
		/// </summary>
		bool VAes : 1 { };

		/// <summary>
		/// 	CLMUL instruction set (VEX-256/EVEX)
		/// </summary>
		bool VPclMulDqd : 1 { };

		/// <summary>
		/// Vector Neural Network Instructions
		/// </summary>
		bool Avx512Vnni : 1 { };

		/// <summary>
		/// BITALG instructions
		/// </summary>
		bool Avx512Bitalg: 1 { };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved3 : 1 { };

		/// <summary>
		/// 	AVX-512 Vector Population Count Double and Quad-word
		/// </summary>
		bool Avx512VPopCntdq : 1 { };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved4 : 1 { };

		/// <summary>
		/// 	5-level paging
		/// </summary>
		bool Level5Paging : 1 { };

		/// <summary>
		/// Unused.
		/// The value of userspace MPX Address-Width Adjust used by the BNDLDX and BNDSTX Intel MPX instructions in 64-bit mode
		/// </summary>
		U8 IngoredM0 : 5 { };

		/// <summary>
		/// Read Processor ID and IA32_TSC_AUX
		/// </summary>
		bool RdPid : 1 { };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved5 : 1 { };

		/// <summary>
		/// Unused.
		/// </summary>
		bool Reserved6 : 1 { };

		/// <summary>
		/// 	Cache line demote
		/// </summary>
		bool ClDemote : 1 { };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved7 : 1 { };

		/// <summary>
		/// 
		/// </summary>
		bool MovDiri : 1 { };

		/// <summary>
		/// 
		/// </summary>
		bool MovDir64B : 1 { };

		/// <summary>
		/// Enqueue Stores
		/// </summary>
		bool EnqCmd : 1 { };

		/// <summary>
		/// SGX Launch Configuration
		/// </summary>
		bool SgxLc : 1 { };

		/// <summary>
		/// Protection keys for supervisor-mode pages
		/// </summary>
		bool Pks : 1 { };

		// QUADWORD 3 LO

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved8 : 1{ };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved9 : 1{ };

		/// <summary>
		/// 4-register Neural Network Instructions
		/// </summary>
		bool Avx5124Vnniw: 1{ };

		/// <summary>
		/// 4-register Multiply Accumulation Single precision
		/// </summary>
		bool Avx5124FMaps: 1{ };

		/// <summary>
		/// Fast Short REP MOVSB
		/// </summary>
		bool Fsrm : 1{ };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved10 : 1{ };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved11 : 1{ };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved12 : 1{ };

		/// <summary>
		/// Doubleword and Quadword Instructions
		/// </summary>
		bool Avx512Vp2Intersect: 1{ };

		/// <summary>
		/// Special Register Buffer Data Sampling Mitigations
		/// </summary>
		bool SrbdsCtrl: 1{ };

		/// <summary>
		/// 	VERW instruction clears CPU buffers
		/// </summary>
		bool MdClear : 1{ };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved13: 1{ };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved14: 1{ };

		/// <summary>
		/// 
		/// </summary>
		bool TsxForceAbort: 1{ };

		/// <summary>
		/// 	Serialize instruction execution
		/// </summary>
		bool Serialize: 1{ };

		/// <summary>
		/// 
		/// </summary>
		bool Hybrid: 1{ };

		/// <summary>
		/// 	TSX suspend load address tracking
		/// </summary>
		bool Tsxldtrk: 1{ };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved15 : 1{ };

		/// <summary>
		/// Platform configuration (Memory Encryption Technologies Instructions)
		/// </summary>
		bool PConfig : 1{ };

		/// <summary>
		/// 	Architectural Last Branch Records
		/// </summary>
		bool Lbr : 1{ };

		/// <summary>
		/// Control flow enforcement (CET) indirect branch tracking
		/// </summary>
		bool CetIbt : 1{ };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved16 : 1{ };

		/// <summary>
		/// Tile computation on bfloat16 numbers
		/// </summary>
		bool AmxBf16 : 1{ };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved17 : 1{ };

		/// <summary>
		/// Tile architecture
		/// </summary>
		bool AmxTile : 1{ };

		/// <summary>
		/// Tile computation on 8-bit integers
		/// </summary>
		bool AmxInt8 : 1{ };

		/// <summary>
		/// Speculation Control, part of Indirect Branch Control (IBC):
		/// Indirect Branch Restricted Speculation(IBRS) and
		/// Indirect Branch Prediction Barrier(IBPB)
		/// </summary>
		bool SpecCtrl : 1{ };

		/// <summary>
		/// 	Single Thread Indirect Branch Predictor, part of IBC
		/// </summary>
		bool Stibp : 1{ };

		/// <summary>
		/// 	IA32_FLUSH_CMD MSR
		/// </summary>
		bool L1DFlush : 1{ };

		/// <summary>
		/// Speculative Side Channel Mitigations
		/// </summary>
		bool Ia32ArchCompat : 1{ };

		/// <summary>
		/// Support for a MSR listing model-specific core capabilities
		/// </summary>
		bool Ia32CoreCompat : 1{ };

		/// <summary>
		/// 	Speculative Store Bypass Disable,
		/// 	as mitigation for Speculative Store Bypass (IA32_SPEC_CTRL)
		/// </summary>
		bool Ssbd : 1{ };

		// QUADWORD 3 HI

		/// <summary>
		/// LAHF/SAHF in long mode
		/// </summary>
		bool LahfLm : 1{ };

		/// <summary>
		/// 	Hyperthreading not valid
		/// </summary>
		bool CmpLegacy : 1 { };

		/// <summary>
		/// 	Secure Virtual Machine
		/// </summary>
		bool Svm : 1 { };

		/// <summary>
		/// 	Extended APIC space
		/// </summary>
		bool ExtApic: 1 { };

		/// <summary>
		/// CR8 in 32-bit mode
		/// </summary>
		bool Cr8Legacy: 1 { };

		/// <summary>
		/// 	Advanced bit manipulation (lzcnt and popcnt)
		/// </summary>
		bool Abm: 1 { };

		/// <summary>
		/// 	SSE4a
		/// </summary>
		bool Sse4a : 1 { };

		/// <summary>
		/// Misaligned SSE mode
		/// </summary>
		bool MisAlignSse: 1 { };

		/// <summary>
		/// PREFETCH and PREFETCHW instructions
		/// </summary>
		bool D3NowPrefetch : 1 { };

		/// <summary>
		/// 	OS Visible Workaround
		/// </summary>
		bool OsVw : 1 { };

		/// <summary>
		/// 	Instruction Based Sampling
		/// </summary>
		bool Ibs : 1 { };

		/// <summary>
		/// 	XOP instruction set
		/// </summary>
		bool Xop : 1 { };

		/// <summary>
		/// SKINIT/STGI instructions
		/// </summary>
		bool SkInit : 1 { };

		/// <summary>
		/// 	Watchdog timer
		/// </summary>
		bool Wdt : 1 { };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved18 : 1 { };

		/// <summary>
		/// 	Light Weight Profiling[25]
		/// </summary>
		bool Lwp : 1 { };

		/// <summary>
		/// 	4 operands fused multiply-add
		/// </summary>
		bool Fma4 : 1 { };

		/// <summary>
		/// 	Translation Cache Extension
		/// </summary>
		bool Tce : 1 { };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved19 : 1 { };

		/// <summary>
		/// 	NodeID MSR
		/// </summary>
		bool NodeIdMsr : 1 { };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved20 : 1 { };

		/// <summary>
		/// Trailing Bit Manipulation
		/// </summary>
		bool Tbm : 1 { };

		/// <summary>
		/// 	Topology Extensions
		/// </summary>
		bool TopoExt : 1 { };

		/// <summary>
		/// Core performance counter extensions
		/// </summary>
		bool PerfCtrCore : 1 { };

		/// <summary>
		/// 	NB performance counter extensions
		/// </summary>
		bool PerCtrNb: 1 { };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved21 : 1 { };

		/// <summary>
		/// 	Data breakpoint extensions
		/// </summary>
		bool Dbx: 1 { };

		/// <summary>
		/// 	Performance TSC
		/// </summary>
		bool PerfTsc: 1 { };

		/// <summary>
		/// 	L2I perf counter extensions
		/// </summary>
		bool PcxL2i : 1 { };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved22 : 1 { };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved23 : 1 { };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved24 : 1 { };

		// DWORD RET

		/// <summary>
		/// Unused
		/// </summary>
		U16 Ignored0 : 11 { };

		/// <summary>
		/// SYSCALL and SYSRET instructions
		/// </summary>
		bool SysCall : 1 { };

		/// <summary>
		/// Unused
		/// </summary>
		U8 Ignored1 : 7 { };

		/// <summary>
		/// Multiprocessor Capable
		/// </summary>
		bool Mp : 1 { };

		/// <summary>
		/// 	NX bit
		/// </summary>
		bool Nx : 1 { };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved25 : 1 { };

		/// <summary>
		/// 	Extended MMX
		/// </summary>
		bool MmmxExt : 1 { };

		/// <summary>
		/// Is AVX supported by OS?
		/// Can only be true if OSXSAVE is supported.
		/// </summary>
		bool AvxSupportByOs : 1{ };

		/// <summary>
		/// Os AVX 512 supported by OS?
		/// Can only be true if OSXSAVE is supported.
		/// </summary>
		bool Avx512SupportByOs : 1{ };

		/// <summary>
		/// 	FXSAVE/FXRSTOR optimizations
		/// </summary>
		bool FxsrOpt : 1 { };

		/// <summary>
		/// Gigabyte pages
		/// </summary>
		bool Pdpe1Gb : 1 { };

		/// <summary>
		/// RDTSCP instruction
		/// </summary>
		bool Rdtscp : 1 { };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved26 : 1 { };

		/// <summary>
		/// Long mode
		/// </summary>
		bool LongMode : 1 { };

		/// <summary>
		/// 	Extended 3DNow!
		/// </summary>
		bool D3NowExt : 1 { };

		/// <summary>
		/// 	3DNow!
		/// </summary>
		bool D3Now : 1 { };

		/// <summary>
		/// Prints all the features into a table
		/// coloring the available features green
		/// and the unavailable red.
		/// </summary>
		/// <returns></returns>
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

	/// <summary>
	/// Returns 1 if the current CPU supports the CPUID instruction, else 0.
	/// Implementation: Source/Arch/X86_64.CpuId.S
	/// </summary>
	extern "C" auto Asm_IsCpuIdSupported() noexcept -> BYTE;

	/// <summary>
	/// Returns true if the OS supports AVX YMM registers, else false.
	/// Warning! Check if os supports OSXSAVE first!
	/// </summary>
	extern "C" auto Asm_IsAvxSupportedByOs() noexcept -> BYTE;

	/// <summary>
	/// Returns true if the OS supports AVX512 ZMM registers, else false.
	/// Warning! Check if os supports OSXSAVE first!
	/// </summary>
	extern "C" auto Asm_IsAvx512SupportedByOs() noexcept -> BYTE;
}
