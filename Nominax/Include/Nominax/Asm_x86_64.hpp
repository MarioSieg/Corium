// File: Asm_x86_64.hpp
// Author: Mario
// Created: 06.07.2021 2:12 PM
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

#include "Foundation.hpp"

namespace Nominax::Assembler::X86_64
{
	namespace Routines
	{
		/// <summary>
		/// Returns a special constant value depending on the OS for testing.
		/// </summary>
		extern "C" NOX_ASM_ROUTINE auto MockCall() -> U64;

		/// <summary>
		/// Tries to detect a VM using time stamp counter.
		/// Warning! Do not use this! On most systems it will crash
		/// because the in instruction cannot get executed from user space.
		/// </summary>
		extern "C" NOX_ASM_ROUTINE auto VmDetector() -> bool;

		/// <summary>
		/// Detects vm ware using a port read action.
		/// Warning! Do not use this! On most systems it will crash
		/// because the in instruction cannot get executed from user space.
		/// </summary>
		extern "C" NOX_ASM_ROUTINE auto VmWareDetector() -> bool;

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
		extern "C" NOX_ASM_ROUTINE auto CpuId
		(
			U64* out1,
			U64* out2,
			U64* out3
		) -> U32;

		/// <summary>
		/// Queries the 16 GPR 64-bit registers and the 16 XMM 128-bit registers.
		/// </summary>
		extern "C" NOX_ASM_ROUTINE auto QueryRegSet(U64 gpr[16], U64 sse[32]) -> void;

		/// <summary>
		/// Returns 1 if the current CPU supports the CPUID instruction, else 0.
		/// Implementation: Source/Arch/X86_64.CpuId.S
		/// </summary>
		extern "C" NOX_ASM_ROUTINE auto IsCpuIdSupported() -> bool;

		/// <summary>
		/// Returns true if the OS supports AVX YMM registers, else false.
		/// Warning! Check if os supports OSXSAVE first!
		/// </summary>
		extern "C" NOX_ASM_ROUTINE auto IsAvxSupportedByOs() -> bool;

		/// <summary>
		/// Returns true if the OS supports AVX512 ZMM registers, else false.
		/// Warning! Check if os supports OSXSAVE first!
		/// </summary>
		extern "C" NOX_ASM_ROUTINE auto IsAvx512SupportedByOs() -> bool;

		/// <summary>
		/// Queries the value of the %rip instruction pointer.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		inline auto QueryRip() -> const void*
		{
			Uip64 rip;
			asm volatile
			(
				"call 1f \n\t"
				"1: popq %0"
				: "=r"(rip)
			);
			return reinterpret_cast<const void*>(rip);
		}
	}

	/// <summary>
	/// Pack a REX prefix:
	/// +---+---+---+---+---+---+---+---+
	/// | 0 | 1 | 0 | 0 | W | R | X | B |
	/// +---+---+---+---+---+---+---+---+
	/// </summary>
	/// <param name="w"></param>
	/// <param name="r"></param>
	/// <param name="x"></param>
	/// <param name="b"></param>
	/// <returns>The composed rex prefix.</returns>
	constexpr auto PackRex(const bool w, const bool r, const bool x, const bool b) -> U8
	{
		U8 rex {0x40};
		rex |= b;
		rex |= x << 1;
		rex |= r << 2;
		rex |= w << 3;
		return rex;
	}

	/// <summary>
	/// Pack a REX prefix if optional, else return zero.
	/// </summary>
	/// <param name="w"></param>
	/// <param name="r"></param>
	/// <param name="x"></param>
	/// <param name="b"></param>
	/// <returns>The composed rex prefix or zero.</returns>
	constexpr auto PackRexOpt(const bool w, const bool r, const bool x, const bool b) -> U8
	{
		return w || r || x || b ? PackRex(w, r, x, b) : 0;
	}

	/// <summary>
	/// Packs the bits into the specified order:
	/// +-----------+-----------+-------+
	/// | bits01 |  bits234 |  bits567  |
	/// +---+---+---+---+---+---+---+---+
	/// | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
	/// +---+---+---+---+---+---+---+---+
	/// </summary>
	/// <param name="bits01"></param>
	/// <param name="bits234"></param>
	/// <param name="bits567"></param>
	/// <returns>The composed mod rm sib byte.</returns>
	constexpr auto PackModRm(const U8 bits01, const U8 bits234, const U8 bits567) -> U8
	{
		NOX_DBG_PAS_TRUE((bits01 & ~0b11) == 0, "Mask mismatch -> 2 bits requested");
		NOX_DBG_PAS_TRUE((bits234 & ~0b111) == 0, "Mask mismatch -> 3 bits requested");
		NOX_DBG_PAS_TRUE((bits567 & ~0b111) == 0, "Mask mismatch -> 3 bits requested");
		U8 trio {bits567};
		trio &= ~0xF8;
		trio |= (bits234 & ~0xF8) << 3;
		trio |= (bits01 & ~0xFC) << 6;
		return trio;
	}

	/// <summary>
	/// Writes a NOP chain of the specified size into the needle.
	/// </summary>
	/// <param name="needle">The machine code needle. Must have at least size elements.</param>
	/// <param name="size">The NOP chain size between 1 and 15 inclusive.</param>
	extern auto InjectNopChain(U8* needle, U8 size) -> void;

	/// <summary>
	/// Represents a register or data size as 16-bit machine words in bytes.
	/// </summary>
	enum class Size : U8
	{
		Byte = 1,
		Word = 2,
		DWord = 2 * Word,
		QWord = 4 * Word,
		XmmWord = 16,
		YmmWord = 32,
		ZmmWord = 64
	};

	enum class RegisterType : U8
	{
		Gpr,
		Simd
	};

	/// <summary>
	/// Represents an encodable CPU register.
	/// </summary>
	struct Register
	{
		/// <summary>
		/// The virtual register id.
		/// </summary>
		const U8 VirtualId;

		/// <summary>
		/// The physical register id (in the CPU).
		/// </summary>
		const U8 PhysicalId;

		/// <summary>
		/// The name of the register.
		/// </summary>
		const std::string_view Name;

		/// <summary>
		/// The size in bytes.
		/// </summary>
		const Size Size;

		/// <summary>
		/// The type of the register.
		/// </summary>
		const RegisterType Type;

		/// <summary>
		/// Equals.
		/// </summary>
		constexpr auto operator ==(const Register& other) const -> bool;

		/// <summary>
		/// Not equals.
		/// </summary>
		constexpr auto operator !=(const Register& other) const -> bool;
	};

	constexpr auto Register::operator==(const Register& other) const -> bool
	{
		return this->VirtualId == other.VirtualId;
	}

	constexpr auto Register::operator!=(const Register& other) const -> bool
	{
		return !(*this == other);
	}

	/// <summary>
	/// Represents the register: %rax
	/// </summary>
	constexpr Register RAX
	{
		.VirtualId = 0x00,
		.PhysicalId = 0x00,
		.Name = "rax",
		.Size = Size::QWord,
		.Type = RegisterType::Gpr
	};

	/// <summary>
	/// Represents the register: %rbx
	/// </summary>
	constexpr Register RBX
	{
		.VirtualId = 0x01,
		.PhysicalId = 0x03,
		.Name = "rbx",
		.Size = Size::QWord,
		.Type = RegisterType::Gpr
	};

	/// <summary>
	/// Represents the register: %rcx
	/// </summary>
	constexpr Register RCX
	{
		.VirtualId = 0x02,
		.PhysicalId = 0x01,
		.Name = "rcx",
		.Size = Size::QWord,
		.Type = RegisterType::Gpr
	};

	/// <summary>
	/// Represents the register: %rdx
	/// </summary>
	constexpr Register RDX
	{
		.VirtualId = 0x03,
		.PhysicalId = 0x02,
		.Name = "rdx",
		.Size = Size::QWord,
		.Type = RegisterType::Gpr
	};

	/// <summary>
	/// Represents the register: %rsi
	/// </summary>
	constexpr Register RSI
	{
		.VirtualId = 0x04,
		.PhysicalId = 0x06,
		.Name = "rsi",
		.Size = Size::QWord,
		.Type = RegisterType::Gpr
	};

	/// <summary>
	/// Represents the register: %rdi
	/// </summary>
	constexpr Register RDI
	{
		.VirtualId = 0x05,
		.PhysicalId = 0x07,
		.Name = "rdi",
		.Size = Size::QWord,
		.Type = RegisterType::Gpr
	};

	/// <summary>
	/// Represents the register: %rbp
	/// </summary>
	constexpr Register RBP
	{
		.VirtualId = 0x06,
		.PhysicalId = 0x05,
		.Name = "rbp",
		.Size = Size::QWord,
		.Type = RegisterType::Gpr
	};

	/// <summary>
	/// Represents the register: %rsp
	/// </summary>
	constexpr Register RSP
	{
		.VirtualId = 0x07,
		.PhysicalId = 0x04,
		.Name = "rsp",
		.Size = Size::QWord,
		.Type = RegisterType::Gpr
	};

	/// <summary>
	/// Represents the register: %r8
	/// </summary>
	constexpr Register R8
	{
		.VirtualId = 0x08,
		.PhysicalId = 0x00,
		.Name = "r8",
		.Size = Size::QWord,
		.Type = RegisterType::Gpr
	};

	/// <summary>
	/// Represents the register: %r9
	/// </summary>
	constexpr Register R9
	{
		.VirtualId = 0x09,
		.PhysicalId = 0x01,
		.Name = "r9",
		.Size = Size::QWord,
		.Type = RegisterType::Gpr
	};

	/// <summary>
	/// Represents the register: %r10
	/// </summary>
	constexpr Register R10
	{
		.VirtualId = 0x0A,
		.PhysicalId = 0x02,
		.Name = "r10",
		.Size = Size::QWord,
		.Type = RegisterType::Gpr
	};

	/// <summary>
	/// Represents the register: %r11
	/// </summary>
	constexpr Register R11
	{
		.VirtualId = 0x0B,
		.PhysicalId = 0x03,
		.Name = "r11",
		.Size = Size::QWord,
		.Type = RegisterType::Gpr
	};

	/// <summary>
	/// Represents the register: %r12
	/// </summary>
	constexpr Register R12
	{
		.VirtualId = 0x0C,
		.PhysicalId = 0x04,
		.Name = "r12",
		.Size = Size::QWord,
		.Type = RegisterType::Gpr
	};

	/// <summary>
	/// Represents the register: %r13
	/// </summary>
	constexpr Register R13
	{
		.VirtualId = 0x0D,
		.PhysicalId = 0x05,
		.Name = "r13",
		.Size = Size::QWord,
		.Type = RegisterType::Gpr
	};

	/// <summary>
	/// Represents the register: %r14
	/// </summary>
	constexpr Register R14
	{
		.VirtualId = 0x0E,
		.PhysicalId = 0x06,
		.Name = "r14",
		.Size = Size::QWord,
		.Type = RegisterType::Gpr
	};

	/// <summary>
	/// Represents the register: %r15
	/// </summary>
	constexpr Register R15
	{
		.VirtualId = 0x0F,
		.PhysicalId = 0x07,
		.Name = "r15",
		.Size = Size::QWord,
		.Type = RegisterType::Gpr
	};

	constexpr std::array<std::reference_wrapper<const Register>, 16> ALL_GPR_REGISTERS
	{
		std::ref(RAX),
		std::ref(RBX),
		std::ref(RCX),
		std::ref(RDX),
		std::ref(RSI),
		std::ref(RDI),
		std::ref(RBP),
		std::ref(RSP),
		std::ref(R8),
		std::ref(R9),
		std::ref(R10),
		std::ref(R11),
		std::ref(R12),
		std::ref(R13),
		std::ref(R14),
		std::ref(R15)
	};

	/// <summary>
	/// Contains all instruction types.
	/// </summary>
	enum class Instruction : U16
	{
		Adc,
		Adcx,
		Add,
		Addpd,
		Addps,
		Addsd,
		Addss,
		Addsubpd,
		Addsubps,
		Adox,
		Aesdec,
		Aesdeclast,
		Aesenc,
		Aesenclast,
		Aesimc,
		Aeskeygenassist,
		And,
		Andn,
		Andnpd,
		Andnps,
		Andpd,
		Andps,
		Bextr,
		Blcfill,
		Blci,
		Blcic,
		Blcmsk,
		Blcs,
		Blendpd,
		Blendps,
		Blendvpd,
		Blendvps,
		Blsfill,
		Blsi,
		Blsic,
		Blsmsk,
		Blsr,
		Bsf,
		Bsr,
		Bswap,
		Bt,
		Btc,
		Btr,
		Bts,
		Bzhi,
		Call,
		Cbw,
		Cdq,
		Cdqe,
		Clc,
		Cld,
		Clflush,
		Clflushopt,
		Clwb,
		Clzero,
		Cmc,
		Cmova,
		Cmovae,
		Cmovb,
		Cmovbe,
		Cmovc,
		Cmove,
		Cmovg,
		Cmovge,
		Cmovl,
		Cmovle,
		Cmovna,
		Cmovnae,
		Cmovnb,
		Cmovnbe,
		Cmovnc,
		Cmovne,
		Cmovng,
		Cmovnge,
		Cmovnl,
		Cmovnle,
		Cmovno,
		Cmovnp,
		Cmovns,
		Cmovnz,
		Cmovo,
		Cmovp,
		Cmovpe,
		Cmovpo,
		Cmovs,
		Cmovz,
		Cmp,
		Cmppd,
		Cmpps,
		Cmpsd,
		Cmpss,
		Cmpxchg,
		Cmpxchg16b,
		Cmpxchg8b,
		Comisd,
		Comiss,
		Cpuid,
		Cqo,
		Crc32,
		Cvtdq2pd,
		Cvtdq2ps,
		Cvtpd2dq,
		Cvtpd2pi,
		Cvtpd2ps,
		Cvtpi2pd,
		Cvtpi2ps,
		Cvtps2dq,
		Cvtps2pd,
		Cvtps2pi,
		Cvtsd2si,
		Cvtsd2ss,
		Cvtsi2sd,
		Cvtsi2ss,
		Cvtss2sd,
		Cvtss2si,
		Cvttpd2dq,
		Cvttpd2pi,
		Cvttps2dq,
		Cvttps2pi,
		Cvttsd2si,
		Cvttss2si,
		Cwd,
		Cwde,
		Dec,
		Div,
		Divpd,
		Divps,
		Divsd,
		Divss,
		Dppd,
		Dpps,
		Emms,
		Extractps,
		Extrq,
		Femms,
		Haddpd,
		Haddps,
		Hsubpd,
		Hsubps,
		Idiv,
		Imul,
		Inc,
		Insertps,
		Insertq,
		Int,
		Ja,
		Jae,
		Jb,
		Jbe,
		Jc,
		Je,
		Jecxz,
		Jg,
		Jge,
		Jl,
		Jle,
		Jmp,
		Jna,
		Jnae,
		Jnb,
		Jnbe,
		Jnc,
		Jne,
		Jng,
		Jnge,
		Jnl,
		Jnle,
		Jno,
		Jnp,
		Jns,
		Jnz,
		Jo,
		Jp,
		Jpe,
		Jpo,
		Jrcxz,
		Js,
		Jz,
		Kaddb,
		Kaddd,
		Kaddq,
		Kaddw,
		Kandb,
		Kandd,
		Kandnb,
		Kandnd,
		Kandnq,
		Kandnw,
		Kandq,
		Kandw,
		Kmovb,
		Kmovd,
		Kmovq,
		Kmovw,
		Knotb,
		Knotd,
		Knotq,
		Knotw,
		Korb,
		Kord,
		Korq,
		Kortestb,
		Kortestd,
		Kortestq,
		Kortestw,
		Korw,
		Kshiftlb,
		Kshiftld,
		Kshiftlq,
		Kshiftlw,
		Kshiftrb,
		Kshiftrd,
		Kshiftrq,
		Kshiftrw,
		Ktestb,
		Ktestd,
		Ktestq,
		Ktestw,
		Kunpckbw,
		Kunpckdq,
		Kunpckwd,
		Kxnorb,
		Kxnord,
		Kxnorq,
		Kxnorw,
		Kxorb,
		Kxord,
		Kxorq,
		Kxorw,
		Lddqu,
		Ldmxcsr,
		Lea,
		Lfence,
		Lzcnt,
		Maskmovdqu,
		Maskmovq,
		Maxpd,
		Maxps,
		Maxsd,
		Maxss,
		Mfence,
		Minpd,
		Minps,
		Minsd,
		Minss,
		Monitor,
		Monitorx,
		Mov,
		Movapd,
		Movaps,
		Movbe,
		Movd,
		Movddup,
		Movdq2q,
		Movdqa,
		Movdqu,
		Movhlps,
		Movhpd,
		Movhps,
		Movlhps,
		Movlpd,
		Movlps,
		Movmskpd,
		Movmskps,
		Movntdq,
		Movntdqa,
		Movnti,
		Movntpd,
		Movntps,
		Movntq,
		Movntsd,
		Movntss,
		Movq,
		Movq2dq,
		Movsd,
		Movshdup,
		Movsldup,
		Movss,
		Movsx,
		Movsxd,
		Movupd,
		Movups,
		Movzx,
		Mpsadbw,
		Mul,
		Mulpd,
		Mulps,
		Mulsd,
		Mulss,
		Mulx,
		Mwait,
		Mwaitx,
		Neg,
		Nop,
		Not,
		Or,
		Orpd,
		Orps,
		Pabsb,
		Pabsd,
		Pabsw,
		Packssdw,
		Packsswb,
		Packusdw,
		Packuswb,
		Paddb,
		Paddd,
		Paddq,
		Paddsb,
		Paddsw,
		Paddusb,
		Paddusw,
		Paddw,
		Palignr,
		Pand,
		Pandn,
		Pause,
		Pavgb,
		Pavgusb,
		Pavgw,
		Pblendvb,
		Pblendw,
		Pclmulqdq,
		Pcmpeqb,
		Pcmpeqd,
		Pcmpeqq,
		Pcmpeqw,
		Pcmpestri,
		Pcmpestrm,
		Pcmpgtb,
		Pcmpgtd,
		Pcmpgtq,
		Pcmpgtw,
		Pcmpistri,
		Pcmpistrm,
		Pdep,
		Pext,
		Pextrb,
		Pextrd,
		Pextrq,
		Pextrw,
		Pf2id,
		Pf2iw,
		Pfacc,
		Pfadd,
		Pfcmpeq,
		Pfcmpge,
		Pfcmpgt,
		Pfmax,
		Pfmin,
		Pfmul,
		Pfnacc,
		Pfpnacc,
		Pfrcp,
		Pfrcpit1,
		Pfrcpit2,
		Pfrsqit1,
		Pfrsqrt,
		Pfsub,
		Pfsubr,
		Phaddd,
		Phaddsw,
		Phaddw,
		Phminposuw,
		Phsubd,
		Phsubsw,
		Phsubw,
		Pi2fd,
		Pi2fw,
		Pinsrb,
		Pinsrd,
		Pinsrq,
		Pinsrw,
		Pmaddubsw,
		Pmaddwd,
		Pmaxsb,
		Pmaxsd,
		Pmaxsw,
		Pmaxub,
		Pmaxud,
		Pmaxuw,
		Pminsb,
		Pminsd,
		Pminsw,
		Pminub,
		Pminud,
		Pminuw,
		Pmovmskb,
		Pmovsxbd,
		Pmovsxbq,
		Pmovsxbw,
		Pmovsxdq,
		Pmovsxwd,
		Pmovsxwq,
		Pmovzxbd,
		Pmovzxbq,
		Pmovzxbw,
		Pmovzxdq,
		Pmovzxwd,
		Pmovzxwq,
		Pmuldq,
		Pmulhrsw,
		Pmulhrw,
		Pmulhuw,
		Pmulhw,
		Pmulld,
		Pmullw,
		Pmuludq,
		Pop,
		Popcnt,
		Por,
		Prefetch,
		Prefetchnta,
		Prefetcht0,
		Prefetcht1,
		Prefetcht2,
		Prefetchw,
		Prefetchwt1,
		Psadbw,
		Pshufb,
		Pshufd,
		Pshufhw,
		Pshuflw,
		Pshufw,
		Psignb,
		Psignd,
		Psignw,
		Pslld,
		Pslldq,
		Psllq,
		Psllw,
		Psrad,
		Psraw,
		Psrld,
		Psrldq,
		Psrlq,
		Psrlw,
		Psubb,
		Psubd,
		Psubq,
		Psubsb,
		Psubsw,
		Psubusb,
		Psubusw,
		Psubw,
		Pswapd,
		Ptest,
		Punpckhbw,
		Punpckhdq,
		Punpckhqdq,
		Punpckhwd,
		Punpcklbw,
		Punpckldq,
		Punpcklqdq,
		Punpcklwd,
		Push,
		Pxor,
		Rcl,
		Rcpps,
		Rcpss,
		Rcr,
		Rdrand,
		Rdseed,
		Rdtsc,
		Rdtscp,
		Ret,
		Rol,
		Ror,
		Rorx,
		Roundpd,
		Roundps,
		Roundsd,
		Roundss,
		Rsqrtps,
		Rsqrtss,
		Sal,
		Sar,
		Sarx,
		Sbb,
		Seta,
		Setae,
		Setb,
		Setbe,
		Setc,
		Sete,
		Setg,
		Setge,
		Setl,
		Setle,
		Setna,
		Setnae,
		Setnb,
		Setnbe,
		Setnc,
		Setne,
		Setng,
		Setnge,
		Setnl,
		Setnle,
		Setno,
		Setnp,
		Setns,
		Setnz,
		Seto,
		Setp,
		Setpe,
		Setpo,
		Sets,
		Setz,
		Sfence,
		Sha1msg1,
		Sha1msg2,
		Sha1nexte,
		Sha1rnds4,
		Sha256msg1,
		Sha256msg2,
		Sha256rnds2,
		Shl,
		Shld,
		Shlx,
		Shr,
		Shrd,
		Shrx,
		Shufpd,
		Shufps,
		Sqrtpd,
		Sqrtps,
		Sqrtsd,
		Sqrtss,
		Stc,
		Std,
		Stmxcsr,
		Sub,
		Subpd,
		Subps,
		Subsd,
		Subss,
		Syscall,
		T1mskc,
		Test,
		Tzcnt,
		Tzmsk,
		Ucomisd,
		Ucomiss,
		Ud2,
		Unpckhpd,
		Unpckhps,
		Unpcklpd,
		Unpcklps,
		Vaddpd,
		Vaddps,
		Vaddsd,
		Vaddss,
		Vaddsubpd,
		Vaddsubps,
		Vaesdec,
		Vaesdeclast,
		Vaesenc,
		Vaesenclast,
		Vaesimc,
		Vaeskeygenassist,
		Valignd,
		Valignq,
		Vandnpd,
		Vandnps,
		Vandpd,
		Vandps,
		Vblendmpd,
		Vblendmps,
		Vblendpd,
		Vblendps,
		Vblendvpd,
		Vblendvps,
		Vbroadcastf128,
		Vbroadcastf32x2,
		Vbroadcastf32x4,
		Vbroadcastf32x8,
		Vbroadcastf64x2,
		Vbroadcastf64x4,
		Vbroadcasti128,
		Vbroadcasti32x2,
		Vbroadcasti32x4,
		Vbroadcasti32x8,
		Vbroadcasti64x2,
		Vbroadcasti64x4,
		Vbroadcastsd,
		Vbroadcastss,
		Vcmppd,
		Vcmpps,
		Vcmpsd,
		Vcmpss,
		Vcomisd,
		Vcomiss,
		Vcompresspd,
		Vcompressps,
		Vcvtdq2pd,
		Vcvtdq2ps,
		Vcvtpd2dq,
		Vcvtpd2ps,
		Vcvtpd2qq,
		Vcvtpd2udq,
		Vcvtpd2uqq,
		Vcvtph2ps,
		Vcvtps2dq,
		Vcvtps2pd,
		Vcvtps2ph,
		Vcvtps2qq,
		Vcvtps2udq,
		Vcvtps2uqq,
		Vcvtqq2pd,
		Vcvtqq2ps,
		Vcvtsd2si,
		Vcvtsd2ss,
		Vcvtsd2usi,
		Vcvtsi2sd,
		Vcvtsi2ss,
		Vcvtss2sd,
		Vcvtss2si,
		Vcvtss2usi,
		Vcvttpd2dq,
		Vcvttpd2qq,
		Vcvttpd2udq,
		Vcvttpd2uqq,
		Vcvttps2dq,
		Vcvttps2qq,
		Vcvttps2udq,
		Vcvttps2uqq,
		Vcvttsd2si,
		Vcvttsd2usi,
		Vcvttss2si,
		Vcvttss2usi,
		Vcvtudq2pd,
		Vcvtudq2ps,
		Vcvtuqq2pd,
		Vcvtuqq2ps,
		Vcvtusi2sd,
		Vcvtusi2ss,
		Vdbpsadbw,
		Vdivpd,
		Vdivps,
		Vdivsd,
		Vdivss,
		Vdppd,
		Vdpps,
		Vexp2pd,
		Vexp2ps,
		Vexpandpd,
		Vexpandps,
		Vextractf128,
		Vextractf32x4,
		Vextractf32x8,
		Vextractf64x2,
		Vextractf64x4,
		Vextracti128,
		Vextracti32x4,
		Vextracti32x8,
		Vextracti64x2,
		Vextracti64x4,
		Vextractps,
		Vfixupimmpd,
		Vfixupimmps,
		Vfixupimmsd,
		Vfixupimmss,
		Vfmadd132pd,
		Vfmadd132ps,
		Vfmadd132sd,
		Vfmadd132ss,
		Vfmadd213pd,
		Vfmadd213ps,
		Vfmadd213sd,
		Vfmadd213ss,
		Vfmadd231pd,
		Vfmadd231ps,
		Vfmadd231sd,
		Vfmadd231ss,
		Vfmaddpd,
		Vfmaddps,
		Vfmaddsd,
		Vfmaddss,
		Vfmaddsub132pd,
		Vfmaddsub132ps,
		Vfmaddsub213pd,
		Vfmaddsub213ps,
		Vfmaddsub231pd,
		Vfmaddsub231ps,
		Vfmaddsubpd,
		Vfmaddsubps,
		Vfmsub132pd,
		Vfmsub132ps,
		Vfmsub132sd,
		Vfmsub132ss,
		Vfmsub213pd,
		Vfmsub213ps,
		Vfmsub213sd,
		Vfmsub213ss,
		Vfmsub231pd,
		Vfmsub231ps,
		Vfmsub231sd,
		Vfmsub231ss,
		Vfmsubadd132pd,
		Vfmsubadd132ps,
		Vfmsubadd213pd,
		Vfmsubadd213ps,
		Vfmsubadd231pd,
		Vfmsubadd231ps,
		Vfmsubaddpd,
		Vfmsubaddps,
		Vfmsubpd,
		Vfmsubps,
		Vfmsubsd,
		Vfmsubss,
		Vfnmadd132pd,
		Vfnmadd132ps,
		Vfnmadd132sd,
		Vfnmadd132ss,
		Vfnmadd213pd,
		Vfnmadd213ps,
		Vfnmadd213sd,
		Vfnmadd213ss,
		Vfnmadd231pd,
		Vfnmadd231ps,
		Vfnmadd231sd,
		Vfnmadd231ss,
		Vfnmaddpd,
		Vfnmaddps,
		Vfnmaddsd,
		Vfnmaddss,
		Vfnmsub132pd,
		Vfnmsub132ps,
		Vfnmsub132sd,
		Vfnmsub132ss,
		Vfnmsub213pd,
		Vfnmsub213ps,
		Vfnmsub213sd,
		Vfnmsub213ss,
		Vfnmsub231pd,
		Vfnmsub231ps,
		Vfnmsub231sd,
		Vfnmsub231ss,
		Vfnmsubpd,
		Vfnmsubps,
		Vfnmsubsd,
		Vfnmsubss,
		Vfpclasspd,
		Vfpclassps,
		Vfpclasssd,
		Vfpclassss,
		Vfrczpd,
		Vfrczps,
		Vfrczsd,
		Vfrczss,
		Vgatherdpd,
		Vgatherdps,
		Vgatherpf0dpd,
		Vgatherpf0dps,
		Vgatherpf0qpd,
		Vgatherpf0qps,
		Vgatherpf1dpd,
		Vgatherpf1dps,
		Vgatherpf1qpd,
		Vgatherpf1qps,
		Vgatherqpd,
		Vgatherqps,
		Vgetexppd,
		Vgetexpps,
		Vgetexpsd,
		Vgetexpss,
		Vgetmantpd,
		Vgetmantps,
		Vgetmantsd,
		Vgetmantss,
		Vhaddpd,
		Vhaddps,
		Vhsubpd,
		Vhsubps,
		Vinsertf128,
		Vinsertf32x4,
		Vinsertf32x8,
		Vinsertf64x2,
		Vinsertf64x4,
		Vinserti128,
		Vinserti32x4,
		Vinserti32x8,
		Vinserti64x2,
		Vinserti64x4,
		Vinsertps,
		Vlddqu,
		Vldmxcsr,
		Vmaskmovdqu,
		Vmaskmovpd,
		Vmaskmovps,
		Vmaxpd,
		Vmaxps,
		Vmaxsd,
		Vmaxss,
		Vminpd,
		Vminps,
		Vminsd,
		Vminss,
		Vmovapd,
		Vmovaps,
		Vmovd,
		Vmovddup,
		Vmovdqa,
		Vmovdqa32,
		Vmovdqa64,
		Vmovdqu,
		Vmovdqu16,
		Vmovdqu32,
		Vmovdqu64,
		Vmovdqu8,
		Vmovhlps,
		Vmovhpd,
		Vmovhps,
		Vmovlhps,
		Vmovlpd,
		Vmovlps,
		Vmovmskpd,
		Vmovmskps,
		Vmovntdq,
		Vmovntdqa,
		Vmovntpd,
		Vmovntps,
		Vmovq,
		Vmovsd,
		Vmovshdup,
		Vmovsldup,
		Vmovss,
		Vmovupd,
		Vmovups,
		Vmpsadbw,
		Vmulpd,
		Vmulps,
		Vmulsd,
		Vmulss,
		Vorpd,
		Vorps,
		Vpabsb,
		Vpabsd,
		Vpabsq,
		Vpabsw,
		Vpackssdw,
		Vpacksswb,
		Vpackusdw,
		Vpackuswb,
		Vpaddb,
		Vpaddd,
		Vpaddq,
		Vpaddsb,
		Vpaddsw,
		Vpaddusb,
		Vpaddusw,
		Vpaddw,
		Vpalignr,
		Vpand,
		Vpandd,
		Vpandn,
		Vpandnd,
		Vpandnq,
		Vpandq,
		Vpavgb,
		Vpavgw,
		Vpblendd,
		Vpblendmb,
		Vpblendmd,
		Vpblendmq,
		Vpblendmw,
		Vpblendvb,
		Vpblendw,
		Vpbroadcastb,
		Vpbroadcastd,
		Vpbroadcastmb2q,
		Vpbroadcastmw2d,
		Vpbroadcastq,
		Vpbroadcastw,
		Vpclmulqdq,
		Vpcmov,
		Vpcmpb,
		Vpcmpd,
		Vpcmpeqb,
		Vpcmpeqd,
		Vpcmpeqq,
		Vpcmpeqw,
		Vpcmpestri,
		Vpcmpestrm,
		Vpcmpgtb,
		Vpcmpgtd,
		Vpcmpgtq,
		Vpcmpgtw,
		Vpcmpistri,
		Vpcmpistrm,
		Vpcmpq,
		Vpcmpub,
		Vpcmpud,
		Vpcmpuq,
		Vpcmpuw,
		Vpcmpw,
		Vpcomb,
		Vpcomd,
		Vpcompressd,
		Vpcompressq,
		Vpcomq,
		Vpcomub,
		Vpcomud,
		Vpcomuq,
		Vpcomuw,
		Vpcomw,
		Vpconflictd,
		Vpconflictq,
		Vperm2f128,
		Vperm2i128,
		Vpermb,
		Vpermd,
		Vpermi2b,
		Vpermi2d,
		Vpermi2pd,
		Vpermi2ps,
		Vpermi2q,
		Vpermi2w,
		Vpermil2pd,
		Vpermil2ps,
		Vpermilpd,
		Vpermilps,
		Vpermpd,
		Vpermps,
		Vpermq,
		Vpermt2b,
		Vpermt2d,
		Vpermt2pd,
		Vpermt2ps,
		Vpermt2q,
		Vpermt2w,
		Vpermw,
		Vpexpandd,
		Vpexpandq,
		Vpextrb,
		Vpextrd,
		Vpextrq,
		Vpextrw,
		Vpgatherdd,
		Vpgatherdq,
		Vpgatherqd,
		Vpgatherqq,
		Vphaddbd,
		Vphaddbq,
		Vphaddbw,
		Vphaddd,
		Vphadddq,
		Vphaddsw,
		Vphaddubd,
		Vphaddubq,
		Vphaddubw,
		Vphaddudq,
		Vphadduwd,
		Vphadduwq,
		Vphaddw,
		Vphaddwd,
		Vphaddwq,
		Vphminposuw,
		Vphsubbw,
		Vphsubd,
		Vphsubdq,
		Vphsubsw,
		Vphsubw,
		Vphsubwd,
		Vpinsrb,
		Vpinsrd,
		Vpinsrq,
		Vpinsrw,
		Vplzcntd,
		Vplzcntq,
		Vpmacsdd,
		Vpmacsdqh,
		Vpmacsdql,
		Vpmacssdd,
		Vpmacssdqh,
		Vpmacssdql,
		Vpmacsswd,
		Vpmacssww,
		Vpmacswd,
		Vpmacsww,
		Vpmadcsswd,
		Vpmadcswd,
		Vpmadd52huq,
		Vpmadd52luq,
		Vpmaddubsw,
		Vpmaddwd,
		Vpmaskmovd,
		Vpmaskmovq,
		Vpmaxsb,
		Vpmaxsd,
		Vpmaxsq,
		Vpmaxsw,
		Vpmaxub,
		Vpmaxud,
		Vpmaxuq,
		Vpmaxuw,
		Vpminsb,
		Vpminsd,
		Vpminsq,
		Vpminsw,
		Vpminub,
		Vpminud,
		Vpminuq,
		Vpminuw,
		Vpmovb2m,
		Vpmovd2m,
		Vpmovdb,
		Vpmovdw,
		Vpmovm2b,
		Vpmovm2d,
		Vpmovm2q,
		Vpmovm2w,
		Vpmovmskb,
		Vpmovq2m,
		Vpmovqb,
		Vpmovqd,
		Vpmovqw,
		Vpmovsdb,
		Vpmovsdw,
		Vpmovsqb,
		Vpmovsqd,
		Vpmovsqw,
		Vpmovswb,
		Vpmovsxbd,
		Vpmovsxbq,
		Vpmovsxbw,
		Vpmovsxdq,
		Vpmovsxwd,
		Vpmovsxwq,
		Vpmovusdb,
		Vpmovusdw,
		Vpmovusqb,
		Vpmovusqd,
		Vpmovusqw,
		Vpmovuswb,
		Vpmovw2m,
		Vpmovwb,
		Vpmovzxbd,
		Vpmovzxbq,
		Vpmovzxbw,
		Vpmovzxdq,
		Vpmovzxwd,
		Vpmovzxwq,
		Vpmuldq,
		Vpmulhrsw,
		Vpmulhuw,
		Vpmulhw,
		Vpmulld,
		Vpmullq,
		Vpmullw,
		Vpmultishiftqb,
		Vpmuludq,
		Vpopcntd,
		Vpopcntq,
		Vpor,
		Vpord,
		Vporq,
		Vpperm,
		Vprold,
		Vprolq,
		Vprolvd,
		Vprolvq,
		Vprord,
		Vprorq,
		Vprorvd,
		Vprorvq,
		Vprotb,
		Vprotd,
		Vprotq,
		Vprotw,
		Vpsadbw,
		Vpscatterdd,
		Vpscatterdq,
		Vpscatterqd,
		Vpscatterqq,
		Vpshab,
		Vpshad,
		Vpshaq,
		Vpshaw,
		Vpshlb,
		Vpshld,
		Vpshlq,
		Vpshlw,
		Vpshufb,
		Vpshufd,
		Vpshufhw,
		Vpshuflw,
		Vpsignb,
		Vpsignd,
		Vpsignw,
		Vpslld,
		Vpslldq,
		Vpsllq,
		Vpsllvd,
		Vpsllvq,
		Vpsllvw,
		Vpsllw,
		Vpsrad,
		Vpsraq,
		Vpsravd,
		Vpsravq,
		Vpsravw,
		Vpsraw,
		Vpsrld,
		Vpsrldq,
		Vpsrlq,
		Vpsrlvd,
		Vpsrlvq,
		Vpsrlvw,
		Vpsrlw,
		Vpsubb,
		Vpsubd,
		Vpsubq,
		Vpsubsb,
		Vpsubsw,
		Vpsubusb,
		Vpsubusw,
		Vpsubw,
		Vpternlogd,
		Vpternlogq,
		Vptest,
		Vptestmb,
		Vptestmd,
		Vptestmq,
		Vptestmw,
		Vptestnmb,
		Vptestnmd,
		Vptestnmq,
		Vptestnmw,
		Vpunpckhbw,
		Vpunpckhdq,
		Vpunpckhqdq,
		Vpunpckhwd,
		Vpunpcklbw,
		Vpunpckldq,
		Vpunpcklqdq,
		Vpunpcklwd,
		Vpxor,
		Vpxord,
		Vpxorq,
		Vrangepd,
		Vrangeps,
		Vrangesd,
		Vrangess,
		Vrcp14pd,
		Vrcp14ps,
		Vrcp14sd,
		Vrcp14ss,
		Vrcp28pd,
		Vrcp28ps,
		Vrcp28sd,
		Vrcp28ss,
		Vrcpps,
		Vrcpss,
		Vreducepd,
		Vreduceps,
		Vreducesd,
		Vreducess,
		Vrndscalepd,
		Vrndscaleps,
		Vrndscalesd,
		Vrndscaless,
		Vroundpd,
		Vroundps,
		Vroundsd,
		Vroundss,
		Vrsqrt14pd,
		Vrsqrt14ps,
		Vrsqrt14sd,
		Vrsqrt14ss,
		Vrsqrt28pd,
		Vrsqrt28ps,
		Vrsqrt28sd,
		Vrsqrt28ss,
		Vrsqrtps,
		Vrsqrtss,
		Vscalefpd,
		Vscalefps,
		Vscalefsd,
		Vscalefss,
		Vscatterdpd,
		Vscatterdps,
		Vscatterpf0dpd,
		Vscatterpf0dps,
		Vscatterpf0qpd,
		Vscatterpf0qps,
		Vscatterpf1dpd,
		Vscatterpf1dps,
		Vscatterpf1qpd,
		Vscatterpf1qps,
		Vscatterqpd,
		Vscatterqps,
		Vshuff32x4,
		Vshuff64x2,
		Vshufi32x4,
		Vshufi64x2,
		Vshufpd,
		Vshufps,
		Vsqrtpd,
		Vsqrtps,
		Vsqrtsd,
		Vsqrtss,
		Vstmxcsr,
		Vsubpd,
		Vsubps,
		Vsubsd,
		Vsubss,
		Vtestpd,
		Vtestps,
		Vucomisd,
		Vucomiss,
		Vunpckhpd,
		Vunpckhps,
		Vunpcklpd,
		Vunpcklps,
		Vxorpd,
		Vxorps,
		Vzeroall,
		Vzeroupper,
		Xadd,
		Xchg,
		Xgetbv,
		Xlatb,
		Xor,
		Xorpd,
		Xorps,

		Count_
	};

	/// <summary>
	/// Contains all instruction set extensions.
	/// </summary>
	enum class IsaExtension : U8
	{
		Rdtsc,
		Rdtscp,
		Cpuid,
		Femms,
		Movbe,
		Popcnt,
		Lzcnt,
		Pclmulqdq,
		Rdrand,
		Rdseed,
		Clflush,
		Clflushopt,
		Clwb,
		Clzero,
		Prefetch,
		Prefetchw,
		Prefetchwt1,
		Monitor,
		Monitorx,
		Cmov,
		Mmx,
		MmxExt,
		D3Now,
		D3NowExt,
		Sse,
		Sse2,
		Sse3,
		Ssse3,
		Sse41,
		Sse42,
		Sse4A,
		Avx,
		Avx2,
		Avx512F,
		Avx512Bw,
		Avx512Dq,
		Avx512Vl,
		Avx512Pf,
		Avx512Er,
		Avx512Cd,
		Avx512Vbmi,
		Avx512Ifma,
		Avx512Vpopcntd,
		Xop,
		F16C,
		Fma3,
		Fma4,
		Bmi,
		Bmi2,
		Tbm,
		Adx,
		Aes,
		Sha
	};

	/// <summary>
	/// Contains all implicit register operands.
	/// </summary>
	enum class ImplicitRegisterOperand : U8
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

	/// <summary>
	/// MMX register access mode.
	/// </summary>
	enum class MmxModeType : U8
	{
		Fpu,
		Mmx,
		None
	};

	/// <summary>
	/// Sse XMM register access mode.
	/// </summary>
	enum class XmmModeType : U8
	{
		Sse,
		Avx,
		None
	};

	enum class OperandType : U8
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
		const OperandType Type;
		const bool        IsInput;
		const bool        IsOutput;
		const U8          ExtendedSize;

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

	using Soo = std::variant<U64, OperandType>;

	struct Prefix final
	{
		const U8   Value;
		const bool IsMandatory;
	};

	struct Rex final
	{
		const bool W;
		const Soo  R;
		const Soo  X;
		const Soo  B;
		const bool IsMandatory;
	};

	enum class VexPrefixType : U8
	{
		Xop,
		Vex
	};

	struct Vex final
	{
		const VexPrefixType Type;
		const U8            Mmmmm;
		const U8            Pp;
		const U8            W;
		const U8            L;
		const Soo           R;
		const Soo           X;
		const Soo           B;
		const Soo           Vvvv;
	};

	struct Evex final
	{
		const U8  Mm;
		const U8  Pp;
		const U8  W;
		const Soo Ll;
		const Soo Rr;
		const Soo Bb;
		const Soo X;
		const Soo Vvvv;
		const Soo V;
		const Soo B;
		const Soo Aaa;
		const Soo Z;
		const U8  Disp8xN;
	};

	struct OpCode final
	{
		const U8  Value;
		const Soo Addend;
	};

	struct ModRm final
	{
		const Soo Mode;
		const Soo Rm;
		const Soo Reg;
	};

	struct ImmediateScalar final
	{
		const U8  Size;
		const Soo Value;
	};

	struct RegisterByte final
	{
		const OperandType Register;
		const Soo         Payload;
	};

	struct CodeOffset final
	{
		const U8  Size;
		const Soo Value;
	};

	struct DataOffset final
	{
		const U8  Size;
		const Soo Value;
	};

	using EncodingRecord = std::variant<const Prefix, const Rex, const Vex, const Evex, const OpCode, const ModRm, const ImmediateScalar, const RegisterByte, const CodeOffset, const DataOffset>;
	using Encoding = std::initializer_list<const EncodingRecord>;

	/// <summary>
	/// Represents an instruction variation.
	/// </summary>
	struct InstructionVariation final
	{
		const std::string_view                                     IntelMnemonic;
		const std::string_view                                     GasMnemonic;
		const std::string_view                                     Description;
		const MmxModeType                                          MmxMode;
		const XmmModeType                                          XmmMode;
		const bool                                                 IsCancellingInputs;
		const std::initializer_list<const Operand>                 OperandList;
		const std::initializer_list<const ImplicitRegisterOperand> ImplicitInputs;
		const std::initializer_list<const ImplicitRegisterOperand> ImplicitOutputs;
		const std::initializer_list<const IsaExtension>            IsaFeatureExtensions;
		const std::initializer_list<const Encoding>                EncodingScheme;
	};

	extern auto GetInstructionNameTable() -> const std::array<const std::string_view, static_cast<U64>(Instruction::Count_)>&;
	extern auto GetInstructionInfoTable() -> const std::array<const std::string_view, static_cast<U64>(Instruction::Count_)>&;
	extern auto GetVariationSizeTable() -> const std::array<U8, static_cast<U64>(Instruction::Count_)>&;
	extern auto GetVariationTable() -> const std::array<const std::initializer_list<const InstructionVariation>, static_cast<U64>(Instruction::Count_)>&;
}
