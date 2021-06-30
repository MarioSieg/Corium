// File: HardFaultReport.cpp
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

#include <algorithm>
#include <filesystem>
#include <ostream>
#include <iostream>
#include <fstream>
#include <thread>

#include "../../Include/Nominax/Core/HardFaultReport.hpp"
#include "../../Include/Nominax/Core/Info.hpp"
#include "../../Include/Nominax/Core/RegisterDump.hpp"
#include "../../Include/Nominax/System/Platform.hpp"
#include "../../Include/Nominax/System/Os.hpp"
#include "../../Include/Nominax/Common/Common.hpp"

namespace
{
	constexpr std::string_view CRASH_DIRECTORY {"Crashes/"};
}

namespace Nominax::Core
{
	/// <summary>
	/// Writes a full error dump into the stream.
	/// </summary>
	/// <param name="out"></param>
	/// <param name="sp"></param>
	/// <param name="ip"></param>
	/// <param name="bp"></param>
	/// <param name="stackSize"></param>
	/// <param name="codeSize"></param>
	/// <param name="stackDumpSize"></param>
	/// <param name="codeDumpSize"></param>
	/// <returns></returns>
	auto WriteHardFaultReport
	(
		std::ostream&                 out,
		const Record* const           sp,
		const ByteCode::Signal* const ip,
		const ByteCode::Signal* const bp,
		const std::size_t             stackSize,
		const std::size_t             codeSize,
		const std::string_view        message,
		std::size_t                   stackDumpSize,
		std::size_t                   codeDumpSize
	) -> void
	{
		[[maybe_unused]] GprRegisterLane gpr { };

		[[maybe_unused]] VectorRegisterLane128 v128 { };

		[[maybe_unused]] VectorRegisterLane256 v256 { };

		{
#if NOX_ARCH_X86_32
			/// <summary>
			/// Read 32-bit GPR registers.
			/// Output is:
			/// %eax = gpr[0];
			/// %ebx = gpr[1];
			/// %ecx = gpr[2];
			/// %edx = gpr[3];
			/// %esi = gpr[4];
			/// %edi = gpr[5];
			///	%ebp = gpr[6];
			/// %esp = gpr[7];
			/// </summary>
			asm volatile
				(
					"movl %%eax, %0"
					: "=r" (gpr[0])
					:
					:
					);

			asm volatile
				(
					"movl %%ebx, %0"
					: "=r" (gpr[1])
					:
					:
					);

			asm volatile
				(
					"movl %%ecx, %0"
					: "=r" (gpr[2])
					:
					:
					);

			asm volatile
				(
					"movl %%edx, %0"
					: "=r" (gpr[3])
					:
					:
					);

			asm volatile
				(
					"movl %%esi, %0"
					: "=r" (gpr[4])
					:
					:
					);

			asm volatile
				(
					"movl %%edi, %0"
					: "=r" (gpr[5])
					:
					:
					);


			asm volatile
				(
					"movl %%ebp, %0"
					: "=r" (gpr[6])
					:
					:
					);

			asm volatile
				(
					"movl %%esp, %0"
					: "=r" (gpr[7])
					:
					:
					);

			// dump registers
			RegisterDump_X86_32(out, gpr);

#elif NOX_ARCH_X86_64
			/// <summary>
			/// Read 64-bit GPR registers.
			/// Output is:
			/// %rax = gpr[0];
			/// %rbx = gpr[1];
			/// %rcx = gpr[2];
			/// %rdx = gpr[3];
			/// %rsi = gpr[4];
			/// %rdi = gpr[5];
			/// %rbp = gpr[6];
			/// %rsp = gpr[7];
			/// %rax = gpr[8];
			/// %rbx = gpr[9];
			/// %rcx = gpr[10];
			/// %rdx = gpr[11];
			/// %rsi = gpr[12];
			/// %rdi = gpr[13];
			/// %rbp = gpr[14];
			/// %rsp = gpr[15];
			/// %xmm0 = v128[0];
			/// %xmm1 = v128[1];
			/// %xmm2 = v128[2];
			/// %xmm3 = v128[3];
			/// %xmm4 = v128[4];
			/// %xmm5 = v128[5];
			/// %xmm6 = v128[6];
			/// %xmm7 = v128[7];
			/// %xmm8 = v128[8];
			/// %xmm9 = v128[9];
			/// %xmm10 = v128[10];
			/// %xmm11 = v128[11];
			/// %xmm12 = v128[12];
			/// %xmm13 = v128[13];
			/// %xmm14 = v128[14];
			/// %xmm15 = v128[15];
			/// %ymm0 = v128[0];
			/// %ymm1 = v128[1];
			/// %ymm2 = v128[2];
			/// %ymm3 = v128[3];
			/// %ymm4 = sse[4];
			/// %ymm5 = sse[5];
			/// %ymm6 = sse[6];
			/// %ymm7 = sse[7];
			/// %ymm8 = sse[8];
			/// %ymm9 = sse[9];
			/// %ymm10 = sse[10];
			/// %ymm11 = sse[11];
			/// %ymm12 = sse[12];
			/// %ymm13 = sse[13];
			/// %ymm14 = sse[14];
			/// %ymm15 = sse[15];
			/// </summary>
			asm volatile
			(
				"movq %%rax, %0"
				: "=m" (gpr[0])
				:
				:
			);

			asm volatile
			(
				"movq %%rbx, %0"
				: "=m" (gpr[1])
				:
				:
			);

			asm volatile
			(
				"movq %%rcx, %0"
				: "=m" (gpr[2])
				:
				:
			);

			asm volatile
			(
				"movq %%rdx, %0"
				: "=m" (gpr[3])
				:
				:
			);

			asm volatile
			(
				"movq %%rsi, %0"
				: "=m" (gpr[4])
				:
				:
			);

			asm volatile
			(
				"movq %%rdi, %0"
				: "=m" (gpr[5])
				:
				:
			);

			asm volatile
			(
				"movq %%rbp, %0"
				: "=m" (gpr[6])
				:
				:
			);

			asm volatile
			(
				"movq %%rsp, %0"
				: "=m" (gpr[7])
				:
				:
			);

			asm volatile
			(
				"movq %%r8, %0"
				: "=m" (gpr[8])
				:
				:
			);

			asm volatile
			(
				"movq %%r9, %0"
				: "=m" (gpr[9])
				:
				:
			);

			asm volatile
			(
				"movq %%r10, %0"
				: "=m" (gpr[10])
				:
				:
			);

			asm volatile
			(
				"movq %%r11, %0"
				: "=m" (gpr[11])
				:
				:
			);

			asm volatile
			(
				"movq %%r12, %0"
				: "=m" (gpr[12])
				:
				:
			);

			asm volatile
			(
				"movq %%r13, %0"
				: "=m" (gpr[13])
				:
				:
			);

			asm volatile
			(
				"movq %%r14, %0"
				: "=m" (gpr[14])
				:
				:
			);

			asm volatile
			(
				"movq %%r15, %0"
				: "=m" (gpr[15])
				:
				:
			);

			asm volatile
			(
				"movdqu %%xmm0, %0"
				: "=m" (v128[0])
				:
				:
			);

			asm volatile
			(
				"movdqu %%xmm1, %0"
				: "=m" (v128[1])
				:
				:
			);

			asm volatile
			(
				"movdqu %%xmm2, %0"
				: "=m" (v128[2])
				:
				:
			);


			asm volatile
			(
				"movdqu %%xmm3, %0"
				: "=m" (v128[3])
				:
				:
			);

			asm volatile
			(
				"movdqu %%xmm4, %0"
				: "=m" (v128[4])
				:
				:
			);

			asm volatile
			(
				"movdqu %%xmm5, %0"
				: "=m" (v128[5])
				:
				:
			);

			asm volatile
			(
				"movdqu %%xmm6, %0"
				: "=m" (v128[6])
				:
				:
			);

			asm volatile
			(
				"movdqu %%xmm7, %0"
				: "=m" (v128[7])
				:
				:
			);

			asm volatile
			(
				"movdqu %%xmm8, %0"
				: "=m" (v128[8])
				:
				:
			);

			asm volatile
			(
				"movdqu %%xmm9, %0"
				: "=m" (v128[9])
				:
				:
			);

			asm volatile
			(
				"movdqu %%xmm10, %0"
				: "=m" (v128[10])
				:
				:
			);

			asm volatile
			(
				"movdqu %%xmm11, %0"
				: "=m" (v128[11])
				:
				:
			);

			asm volatile
			(
				"movdqu %%xmm12, %0"
				: "=m" (v128[12])
				:
				:
			);

			asm volatile
			(
				"movdqu %%xmm13, %0"
				: "=m" (v128[13])
				:
				:
			);

			asm volatile
			(
				"movdqu %%xmm14, %0"
				: "=m" (v128[14])
				:
				:
			);

			asm volatile
			(
				"movdqu %%xmm15, %0"
				: "=m" (v128[15])
				:
				:
			);

#ifdef __AVX__

			asm volatile
				(
					"vmovdqu %%ymm0, %0"
					: "=m" (v256[0])
					:
					:
					);

			asm volatile
				(
					"vmovdqu %%ymm1, %0"
					: "=m" (v256[1])
					:
					:
					);

			asm volatile
				(
					"vmovdqu %%ymm2, %0"
					: "=m" (v256[2])
					:
					:
					);


			asm volatile
				(
					"vmovdqu %%ymm3, %0"
					: "=m" (v256[3])
					:
					:
					);

			asm volatile
				(
					"vmovdqu %%xmm4, %0"
					: "=m" (v256[4])
					:
					:
					);

			asm volatile
				(
					"vmovdqu %%ymm5, %0"
					: "=m" (v256[5])
					:
					:
					);

			asm volatile
				(
					"vmovdqu %%ymm6, %0"
					: "=m" (v256[6])
					:
					:
					);

			asm volatile
				(
					"vmovdqu %%ymm7, %0"
					: "=m" (v256[7])
					:
					:
					);

			asm volatile
				(
					"vmovdqu %%ymm8, %0"
					: "=m" (v256[8])
					:
					:
					);

			asm volatile
				(
					"vmovdqu %%ymm9, %0"
					: "=m" (v256[9])
					:
					:
					);

			asm volatile
				(
					"vmovdqu %%ymm10, %0"
					: "=m" (v256[10])
					:
					:
					);

			asm volatile
				(
					"vmovdqu %%ymm11, %0"
					: "=m" (v256[11])
					:
					:
					);

			asm volatile
				(
					"vmovdqu %%ymm12, %0"
					: "=m" (v256[12])
					:
					:
					);

			asm volatile
				(
					"vmovdqu %%ymm13, %0"
					: "=m" (v256[13])
					:
					:
					);

			asm volatile
				(
					"vmovdqu %%ymm14, %0"
					: "=m" (v256[14])
					:
					:
					);

			asm volatile
				(
					"vmovdqu %%ymm15, %0"
					: "=m" (v256[15])
					:
					:
					);

#endif
#endif
		}

		out << "=========================\n";
		out << " !HARD FAULT TRAP ERROR!\n";
		out << "=========================\n";
		out << "Nominax runtime reactor " << std::hex << "0x" << std::this_thread::get_id() << std::dec << " has encountered a major problem and has been terminated.\n";
		out << "We are sorry for the inconvenience!\n";
		out << "Please send this file to: mt3000@gmx.de" << '\n';
		out << "Or create an issue: https://github.com/MarioSieg/NominaX" << "\n\n";
		out << "=========================\n";
		out << "         System\n";
		out << "=========================\n";
		out << "Nominax Version: " << SYSTEM_VERSION << '\n';
		out << "Platform: " NOX_OS_NAME " " NOX_ARCH_SIZE_NAME << '\n';
		out << "Arch: " << NOX_ARCH_NAME << '\n';
		out << "Posix: " << std::boolalpha << NOX_IS_POSIX << '\n';
		out << "Compiler: " << NOX_COM_NAME " - C++ 20" << '\n';
		out << "CPU: " << System::Os::QueryCpuName() << '\n';
		out << "CPU Threads: " << std::thread::hardware_concurrency() << '\n';
		out << "System RAM: " << Bytes2Megabytes(System::Os::QuerySystemMemoryTotal()) << " MB\n";
		out << "Process RAM: " << Bytes2Megabytes(System::Os::QueryProcessMemoryUsed()) << " MB\n";
		out << '\n';
		out << "MS = " << (!message.empty() && message.data() ? message : "none") << '\n';
		out << "SP = &0x" << std::hex << sp << '\n';
		out << "IP = &0x" << std::hex << ip << '\n';
		out << "BP = &0x" << std::hex << bp << "\n";
		out << std::endl;

		/*
		 * The problem with the register dump is that the values are very undefined.
		 * The idea originally was to dump the register values to help debugging,
		 * but the values are not really that useful. Also because this function is called,
		 * the registers are modified too. So this register dump feature is not that useful,
		 * but it's integrated into the debug pipeline, so it will stay.
		 */

		// dump registers:
		out << "=========================\n";
		out << "     Register Dump\n";
		out << "=========================\n";
		RegisterDump_X86_64(out, gpr, v128, v256);

		stackDumpSize = std::clamp(stackDumpSize, stackDumpSize, stackSize);
		codeDumpSize  = std::clamp(codeDumpSize, codeDumpSize, codeSize);

		// TODO Check if the stack dump could be a security vulnerability
		out << "=========================\n";
		out << "       Stack Dump        \n";
		out << "=========================\n";
		for (std::size_t i {0}; i < stackDumpSize && sp; ++i)
		{
			out << "0x" << std::hex << i << " = 0x" << std::hex << sp[-i].AsU64 << '\n';
		}

		out << std::endl;

		// TODO Check if the code dump could be a security vulnerability
		out << "=========================\n";
		out << "        Code Dump        \n";
		out << "=========================\n";
		for (std::size_t i {0}; i < codeDumpSize && ip; ++i)
		{
			out << "0x" << std::hex << i << " = 0x" << std::hex << ip[-i].R64.AsU64 << '\n';
		}
		out << std::endl;
	}

	/// <summary>
	/// Writes a full error dump into std::cerr and into a file.
	/// </summary>
	/// <param name="sp"></param>
	/// <param name="ip"></param>
	/// <param name="bp"></param>
	/// <param name="stackSize"></param>
	/// <param name="codeSize"></param>
	/// <param name="stackDumpSize"></param>
	/// <param name="codeDumpSize"></param>
	/// <returns></returns>
	auto WriteHardFaultReport
	(
		const Record* const           sp,
		const ByteCode::Signal* const ip,
		const ByteCode::Signal* const bp,
		const std::size_t             stackSize,
		const std::size_t             codeSize,
		const std::string_view        message,
		const std::size_t             stackDumpSize,
		const std::size_t             codeDumpSize
	) -> void
	{
		std::stringstream dump;
		WriteHardFaultReport(dump, sp, ip, bp, stackSize, codeSize, message, stackDumpSize, codeDumpSize);
		const std::string str = dump.str();
		std::cerr << str << std::endl;
		std::filesystem::create_directory(CRASH_DIRECTORY);
		const std::time_t t  = std::time(nullptr);
		const std::tm     tm = Common::SafeLocalTime(t);
		std::stringstream crashFilePath;
		crashFilePath << CRASH_DIRECTORY;
		crashFilePath << std::put_time(&tm, "NominaxCrash_%d_%m_%Y_%H_%M_%S.dmp");
		const std::string crashFilePathStr = crashFilePath.str();
		if (std::ofstream crashFile {crashFilePathStr}; crashFile.is_open())  [[likely]]
		{
			crashFile << str;
			crashFile.flush();

			std::cerr << "Crash file generated in: " << std::filesystem::absolute(crashFilePathStr) << "\n\n";
		}
	}

	auto WriteHardFaultReport(const std::string_view message) -> void
	{
		WriteHardFaultReport(nullptr, nullptr, nullptr, 0, 0, message, 0, 0);
	}
}
