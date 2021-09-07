// File: VM.inl
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
//       transformion or translation of a Source form, including but
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
//           of the NOTICE file are for informional purposes only and
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
//       replaced with your own identifying informion. (Don't include
//       the brackets!)  The text should be enclosed in the appropriate
//       comment syntax for the file form. We also recommend that a
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

#include <chrono>
#include <cstring>

#include "ReactorCores.hpp"

#include "../../Include/Nominax/ByteCode/_ByteCode.hpp"
#include "../../Include/Nominax/Foundation/_Foundation.hpp"
#include "../../Include/Nominax/Core/_Core.hpp"

namespace Nominax::Core
{
	using Foundation::Record;
	using Foundation::BreakpointInterrupt;
	using Foundation::NoOperation;
	using Foundation::Rol64;
	using Foundation::Ror64;
	using Foundation::Proxy_F64Equals;
	using Foundation::Proxy_F64IsOne;
	using Foundation::Proxy_F64IsZero;

	using Foundation::VectorLib::F64_X4_Add_Unaligned;
	using Foundation::VectorLib::F64_X4_Sub_Unaligned;
	using Foundation::VectorLib::F64_X4_Mul_Unaligned;
	using Foundation::VectorLib::F64_X4_Div_Unaligned;
	using Foundation::VectorLib::F64_X16_Add_Unaligned;
	using Foundation::VectorLib::F64_X16_Sub_Unaligned;
	using Foundation::VectorLib::F64_X16_Mul_Unaligned;
	using Foundation::VectorLib::F64_X16_Div_Unaligned;

	using ByteCode::SystemIntrinsicInvocationID;
	using ByteCode::Instruction;
	using ByteCode::IntrinsicRoutine;
	using ByteCode::Signal;
	using ByteCode::CharClusterUtf8;

	/// <summary>
	/// Operator for double precision F32ing point modulo.
	/// </summary>
    NOX_REACTOR_ROUTINE static inline auto operator %=(Record& self, const double value) -> void
	{
		self.AsF64 = std::fmod(self.AsF64, value);
	}

	/*
	 * This inserts a comment with the msg into the assembler code.
	 * Useful for finding the asm code of the instructions.
	 * These should be disabled when building for release.
	 * Asm volatile is like a black box and never touched by the compiler so it might affect code generation/ordering!
	 */
	#if NOX_REACTOR_ASM_MARKERS
	#	define ASM_MARKER(msg) asm volatile("#" msg)
	#else
	#	define ASM_MARKER(msg)
	#endif

	/// <summary>
	/// Implementation for the "intrin" instruction.
	/// This contains a jump table with the implementation of all system intrinsic routines.
	/// The stack pointer is copied, so all local pushes will be popped automically when
	/// returning. Since all local pushes and pops are not updates to the original stack pointer,
	/// this function can only modify the stack values, but not the original sp.
	/// For that reason the intrinsic routines requires the caller to push/pop the arguments and the return values.
	/// This is very important!
	/// So for single argument intrinsic routines, the intrinsic routine just modifies the stack top:
	/// For example (pseudo code):
	/// stack[0] = sin(stack[0])
	/// If a preserved value is needed, a call to "dupl" is needed before calling "intrin".
	/// A two argument intrinsic routine will write the result into the previous stack element and use the top as second argument:
	/// stack[-1] = atan2(stack[-1], stack[0])
	/// So the stack will be:
	/// +---+-------+
	/// |sp | value |
	/// +---+-------+
	/// | 0 | 12233 | << top -> stack[0] -> (arg1 and result)
	/// +---+-------+
	/// | 1 | 27223 | << top - 1 -> stack[-1] -> (arg2)
	/// +---+-------+
	/// So stack[-1] will be overwritten and contains the result.
	/// stack[0] will still contain arg2.
	/// </summary>
	NOX_HOT
    static auto SyscallIntrin(Record* NOX_RESTRICT const sp, const std::uint64_t id) -> void
	{
		static constexpr std::array<const void* NOX_RESTRICT const, ToUnderlying(SystemIntrinsicInvocationID::Count_)> JUMP_TABLE
		{
			&&__cos__,
			&&__sin__,
			&&__tan__,
			&&__acos__,
			&&__asin__,
			&&__atan__,
			&&__atan2__,
			&&__cosh__,
			&&__sinh__,
			&&__tanh__,
			&&__acosh__,
			&&__asinh__,
			&&__atanh__,
			&&__exp__,
			&&__log__,
			&&__log10__,
			&&__exp2__,
			&&__ilogb__,
			&&__log2__,
			&&__pow__,
			&&__sqrt__,
			&&__cbrt__,
			&&__hypot__,
			&&__ceil__,
			&&__floor__,
			&&__round__,
			&&__rint__,
			&&__max__,
			&&__min__,
			&&__fmax__,
			&&__fmin__,
			&&__fdim__,
			&&__abs__,
			&&__fabs__,
			&&__io_port_write_cluster__,
			&&__io_port_read_cluster__,
			&&__io_port_flush__
		};

		static_assert(ValidateJumpTable(std::data(JUMP_TABLE), std::size(JUMP_TABLE)));

		const void* NOX_RESTRICT const* const jumpTable { std::data(JUMP_TABLE) };

		goto
		**(jumpTable + id);

	__cos__:
		NOX_HOT_LABEL;

		(*sp).AsF64 = std::cos((*sp).AsF64);

		return;

	__sin__:
		NOX_HOT_LABEL;

		(*sp).AsF64 = std::sin((*sp).AsF64);

		return;

	__tan__:
		NOX_HOT_LABEL;

		(*sp).AsF64 = std::tan((*sp).AsF64);

		return;

	__acos__:
		NOX_HOT_LABEL;

		(*sp).AsF64 = std::acos((*sp).AsF64);

		return;

	__asin__:
		NOX_HOT_LABEL;

		(*sp).AsF64 = std::asin((*sp).AsF64);

		return;

	__atan__:
		NOX_HOT_LABEL;

		(*sp).AsF64 = std::atan((*sp).AsF64);

		return;

	__atan2__:
		NOX_HOT_LABEL;

		(*(sp - 1)).AsF64 = std::atan2((*(sp - 1)).AsF64, (*sp).AsF64);

		return;

	__cosh__:
		NOX_HOT_LABEL;

		(*sp).AsF64 = std::cosh((*sp).AsF64);

		return;

	__sinh__:
		NOX_HOT_LABEL;

		(*sp).AsF64 = std::sinh((*sp).AsF64);

		return;

	__tanh__:
		NOX_HOT_LABEL;

		(*sp).AsF64 = std::tanh((*sp).AsF64);

		return;

	__acosh__:
		NOX_HOT_LABEL;

		(*sp).AsF64 = std::acosh((*sp).AsF64);

		return;

	__asinh__:
		NOX_HOT_LABEL;

		(*sp).AsF64 = std::asinh((*sp).AsF64);

		return;

	__atanh__:
		NOX_HOT_LABEL;

		(*sp).AsF64 = std::atanh((*sp).AsF64);

		return;

	__exp__:
		NOX_HOT_LABEL;

		(*sp).AsF64 = std::exp((*sp).AsF64);

		return;

	__log__:
		NOX_HOT_LABEL;

		(*sp).AsF64 = std::log((*sp).AsF64);

		return;

	__log10__:
		NOX_HOT_LABEL;

		(*sp).AsF64 = std::log10((*sp).AsF64);

		return;

	__exp2__:
		NOX_HOT_LABEL;

		(*sp).AsF64 = std::exp2((*sp).AsF64);

		return;

	__ilogb__:
		NOX_HOT_LABEL;

		(*sp).AsI64 = std::ilogb((*sp).AsF64);

		return;

	__log2__:
		NOX_HOT_LABEL;

		(*sp).AsF64 = std::log2((*sp).AsF64);

		return;

	__pow__:
		NOX_HOT_LABEL;

		(*(sp - 1)).AsF64 = std::pow((*(sp - 1)).AsF64, (*sp).AsF64);

		return;

	__sqrt__:
		NOX_HOT_LABEL;

		(*sp).AsF64 = std::sqrt((*sp).AsF64);

		return;

	__cbrt__:
		NOX_HOT_LABEL;

		(*sp).AsF64 = std::cbrt((*sp).AsF64);

		return;

	__hypot__:
		NOX_HOT_LABEL;

		(*(sp - 1)).AsF64 = std::hypot((*(sp - 1)).AsF64, (*sp).AsF64);

		return;

	__ceil__:
		NOX_HOT_LABEL;

		(*sp).AsF64 = std::ceil((*sp).AsF64);

		return;

	__floor__:
		NOX_HOT_LABEL;

		(*sp).AsF64 = std::floor((*sp).AsF64);

		return;

	__round__:
		NOX_HOT_LABEL;

		(*sp).AsF64 = std::round((*sp).AsF64);

		return;

	__rint__:
		NOX_HOT_LABEL;

		(*sp).AsF64 = std::rint((*sp).AsF64);

		return;

	__max__:
		NOX_HOT_LABEL;

		(*(sp - 1)).AsI64 = std::max((*(sp - 1)).AsI64, (*sp).AsI64);

		return;

	__min__:
		NOX_HOT_LABEL;

		(*(sp - 1)).AsI64 = std::min((*(sp - 1)).AsI64, (*sp).AsI64);

		return;

	__fmax__:
		NOX_HOT_LABEL;

		(*(sp - 1)).AsF64 = std::max((*(sp - 1)).AsF64, (*sp).AsF64);

		return;

	__fmin__:
		NOX_HOT_LABEL;

		(*(sp - 1)).AsF64 = std::min((*(sp - 1)).AsF64, (*sp).AsF64);

		return;

	__fdim__:
		NOX_HOT_LABEL;

		(*(sp - 1)).AsF64 = std::fdim((*(sp - 1)).AsF64, (*sp).AsF64);

		return;

	__abs__:
		NOX_HOT_LABEL;

		(*sp).AsI64 = std::abs((*sp).AsI64);

		return;

	__fabs__:
		NOX_HOT_LABEL;

		(*sp).AsF64 = std::abs((*sp).AsF64);

		return;

	__io_port_write_cluster__:
		NOX_COLD_LABEL;

		std::fwrite(sp, sizeof(char8_t), sizeof(CharClusterUtf8) / sizeof(char8_t), stdout);

		return;

	__io_port_read_cluster__:
		NOX_COLD_LABEL;
		{
			// this reads until space, but we want to read until newline (at the moment):
			// fread(&sp->AsUtf8, sizeof(char8_t), sizeof(CharClusterUtf8) / sizeof(char8_t), stdin);
			[[maybe_unused]] // throw runtime exception
				auto _ { std::fgets(reinterpret_cast<char*>(sp), sizeof(CharClusterUtf8) / sizeof(char8_t), stdin) };
		}
		return;

	__io_port_flush__:
		NOX_COLD_LABEL;

		std::fflush(stdout);

		return;
	}

	NOX_HOT auto NOX_REACTOR_IMPL_NAME
	(
		const VerboseReactorDescriptor* input,
		ReactorState*                   output,
		const void****                  outJumpTable
	) -> ReactorShutdownReason
	{
		static constexpr std::array<const void* NOX_RESTRICT const, ToUnderlying(Instruction::Count_)> JUMP_TABLE
		{
			&&__int__,
			&&__intrin__,
			&&__cintrin__,
			&&__call__,
			&&__ret__,
			&&__mov__,
			&&__sto__,
			&&__push__,
			&&__pop__,
			&&__pop2__,
			&&__dupl__,
			&&__dupl2__,
			&&__swap__,
			&&__nop__,
			&&__jmp__,
			&&__jmprel__,
			&&__jz__,
			&&__jnz__,
			&&__jo_cmpi__,
			&&__jo_cmpf__,
			&&__jno_cmpi__,
			&&__jno_cmpf__,
			&&__je_cmpi__,
			&&__je_cmpf__,
			&&__jne_cmpi__,
			&&__jne_cmpf__,
			&&__ja_cmpi__,
			&&__ja_cmpf__,
			&&__jl_cmpi__,
			&&__jl_cmpf__,
			&&__jae_cmpi__,
			&&__jae_cmpf__,
			&&__jle_cmpi__,
			&&__jle_cmpf__,
			&&__ipushz__,
			&&__ipusho__,
			&&__fpusho__,
			&&__iinc__,
			&&__idec__,
			&&__iadd__,
			&&__isub__,
			&&__imul__,
			&&__idiv__,
			&&__imod__,
			&&__iand__,
			&&__ior__,
			&&__ixor__,
			&&__icom__,
			&&__isal__,
			&&__isar__,
			&&__irol__,
			&&__iror__,
			&&__ineg__,
			&&__fadd__,
			&&__fsub__,
			&&__fmul__,
			&&__fdiv__,
			&&__fmod__,
			&&__fneg__,
			&&__finc__,
			&&__fdec__,
			&&__vpush__,
			&&__vpop__,
			&&__vadd__,
			&&__vsub__,
			&&__vmul__,
			&&__vdiv__,
			&&__mpush__,
			&&__mpop__,
			&&__madd__,
			&&__msub__,
			&&__mmul__,
			&&__mdiv__
		};

		static_assert(ValidateJumpTable(std::data(JUMP_TABLE), std::size(JUMP_TABLE)));

		if (outJumpTable)
		{
			**outJumpTable = const_cast<const void**>(std::data(JUMP_TABLE));
			return ReactorShutdownReason::Success;
		}

		if (!input || !output)
		{
			[[unlikely]]
            return ReactorShutdownReason::Error;
		}

		ASM_MARKER("reactor begin");

		const auto pre { std::chrono::high_resolution_clock::now() };

		[[maybe_unused]]
        const void* NOX_RESTRICT const* const     jumpTable { std::data(JUMP_TABLE) };          /* jump table						*/
		InterruptAccumulator                      interruptCode { };                            /* interrupt id flag				*/
		IntrinsicRoutine* const* const            intrinsicTable { input->IntrinsicTable };     /* intrinsic table hi				*/
		InterruptRoutineProxy* const              interruptHandler { input->InterruptHandler }; /* global interrupt routine			*/
		const Signal* const NOX_RESTRICT          ipLo { input->CodeChunk };                    /* instruction low ptr				*/
		const Signal*                             ip { ipLo };                                  /* instruction ptr					*/
		const Signal*                             bp { ipLo };                                  /* base pointer						*/
		Record* NOX_RESTRICT                      sp { input->Stack };                          /* stack pointer lo					*/

		ASM_MARKER("reactor exec");

		#if NOX_OPT_EXECUTION_ADDRESS_MAPPING

		#define JMP_PTR()		*((*++ip).Ptr)
		#define JMP_PTR_REL()	*((*ip).Ptr)
		#define UPDATE_IP()		ip = reinterpret_cast<const Signal*>(abs)

		#else

		#define JMP_PTR()		**(jumpTable + (*++ip).OpCode)
		#define JMP_PTR_REL()	**(jumpTable + (*ip).OpCode)
		#define UPDATE_IP()		ip = ipLo + abs - 1
		
		#endif

		/*
		 * Compute vtor memory offset relative to %sp
		 */
		#define VEC_MOFFS(x) (sp - (( x ) + 1))

		// exec first:
		goto
		JMP_PTR();

	__int__:
		NOX_COLD_LABEL;
		{
			ASM_MARKER("__int__");

			interruptCode = (*++ip).R64.AsI32;
			(*interruptHandler)(interruptCode);
			if (__builtin_expect(interruptCode <= 0, false))
			{
                goto _terminate_;
			}
		}
		goto
		JMP_PTR();


	__intrin__:
		NOX_HOT_LABEL;
		ASM_MARKER("__intrin__");

		SyscallIntrin(sp, (*++ip).R64.AsU64); // syscall(sp, imm())

		goto
		JMP_PTR();


	__cintrin__:
		NOX_HOT_LABEL;
		ASM_MARKER("__cintrin__");

		(**(intrinsicTable + (*++ip).R64.AsU64))(sp);

		goto
		JMP_PTR();


	__call__:
		NOX_HOT_LABEL;
		{
			ASM_MARKER("__call__");

			// ip + 1 is the procedure to jump to, so
			// ip + 2 is the next instruction
			const std::uint64_t abs { (*++ip).R64.AsU64 }; // absolute address
			bp = ip + 1;                                   // store the address to return to in the base pointer
			ip = ipLo + abs;                               // ip = begin + offset
		}
		goto
		JMP_PTR_REL();


	__ret__:
		NOX_HOT_LABEL;
		{
			ASM_MARKER("__ret__");

			// restore address from last call:
			ip = bp;
		}
		goto
		JMP_PTR_REL();


	__mov__:
		NOX_HOT_LABEL;
		{
			ASM_MARKER("__mov__");

			const std::uint64_t dst { (*++ip).R64.AsU64 }; // imm() -> arg 1 (reg) - dst
			*(sp + dst) = *(sp + (*++ip).R64.AsU64);       // poke(dst) = poke(imm())
		}
		goto
		JMP_PTR();


	__sto__:
		NOX_HOT_LABEL;
		{
			ASM_MARKER("__sto__");

			const std::uint64_t dst { (*++ip).R64.AsU64 }; // imm() -> arg 1 (reg) - dst
			(*(sp + dst)).AsU64 = (*++ip).R64.AsU64;       // poke(dst) = imm()
		}
		goto
		JMP_PTR();


	__push__:
		NOX_HOT_LABEL;
		ASM_MARKER("__push__");

		*++sp = (*++ip).R64; // push(imm())

		goto
		JMP_PTR();


	__pop__:
		NOX_HOT_LABEL;
		ASM_MARKER("__pop__");

		--sp;

		goto
		JMP_PTR();


	__pop2__:
		NOX_HOT_LABEL;
		ASM_MARKER("__pop2__");

		sp -= 2;

		goto
		JMP_PTR();


	__dupl__:
		NOX_HOT_LABEL;
		{
			ASM_MARKER("__dupl__");
			const auto top { *sp }; // peek()
			*++sp = top;            // push(peek())
		}
		goto
		JMP_PTR();


	__dupl2__:
		NOX_HOT_LABEL;
		{
			ASM_MARKER("__dupl2__");

			const auto top { *sp }; // peek
			*++sp = top;            // push(peek())
			*++sp = top;            // push(peek())
		}
		goto
		JMP_PTR();


	__swap__:
		NOX_HOT_LABEL;
		{
			ASM_MARKER("__swap__");

			const auto top { *sp }; // backup = top()
			*sp       = *(sp - 1);  // top() = poke(1)
			*(sp - 1) = top;        // poke(1) = backup
		}
		goto
		JMP_PTR();


	__nop__:
		NOX_COLD_LABEL;
		ASM_MARKER("__nop__");

		NoOperation();

		goto
		JMP_PTR();


	__jmp__:
		NOX_HOT_LABEL;
		{
			ASM_MARKER("__jmp__");

			const std::uint64_t abs { (*++ip).R64.AsU64 }; // absolute address
			#if NOX_OPT_EXECUTION_ADDRESS_MAPPING
			ip = reinterpret_cast<const Signal*>(abs);
			#else
			ip = ipLo + abs; // ip = begin + offset
			#endif
		}
		goto
		JMP_PTR_REL();


	__jmprel__:
		NOX_HOT_LABEL;
		{
			ASM_MARKER("__jmprel__");

			const std::uint64_t rel { (*++ip).R64.AsU64 }; // relative address
			#if NOX_OPT_EXECUTION_ADDRESS_MAPPING
			ip = reinterpret_cast<const Signal*>(rel);
			#else
			ip += rel; // ip +-= rel
			#endif
		}
		goto
		JMP_PTR_REL();


	__jz__:
		NOX_HOT_LABEL;
		{
			ASM_MARKER("__jz__");

			const std::uint64_t abs { (*++ip).R64.AsU64 }; // absolute address
			if ((*sp--).AsI64 == 0)
			{
				UPDATE_IP(); // ip = begin + offset - 1 (inc stride)
			}
		}
		goto
		JMP_PTR();


	__jnz__:
		NOX_HOT_LABEL;
		{
			ASM_MARKER("__jnz__");

			const std::uint64_t abs { (*++ip).R64.AsU64 }; // absolute address
			if ((*sp--).AsI64 != 0)
			{
				UPDATE_IP(); // ip = begin + offset - 1 (inc stride)
			}
		}
		goto
		JMP_PTR();


	__jo_cmpi__:
		NOX_HOT_LABEL;
		{
			ASM_MARKER("__jo_cmpi__");

			const std::uint64_t abs { (*++ip).R64.AsU64 }; // absolute address
			if ((*sp--).AsI64 == 1)
			{
				// pop()
				UPDATE_IP(); // ip = begin + offset - 1 (inc stride)
			}
		}
		goto
		JMP_PTR();


	__jo_cmpf__:
		NOX_HOT_LABEL;
		{
			ASM_MARKER("__jo_cmpf__");

			const std::uint64_t abs { (*++ip).R64.AsU64 }; // absolute address
			if (Proxy_F64IsOne((*sp--).AsF64))
			{
				// pop()
				UPDATE_IP(); // ip = begin + offset - 1 (inc stride)
			}
		}
		goto
		JMP_PTR();


	__jno_cmpi__:
		NOX_HOT_LABEL;
		{
			ASM_MARKER("__jno_cmpi__");

			const std::uint64_t abs { (*++ip).R64.AsU64 }; // absolute address
			if ((*sp--).AsI64 != 1)
			{
				// pop()
				UPDATE_IP(); // ip = begin + offset - 1 (inc stride)
			}
		}
		goto
		JMP_PTR();


	__jno_cmpf__:
		NOX_HOT_LABEL;
		{
			ASM_MARKER("__jno_cmpf__");

			const std::uint64_t abs { (*++ip).R64.AsU64 }; // absolute address
			if (!Proxy_F64IsOne((*sp--).AsF64))
			{
				// pop()
				UPDATE_IP(); // ip = begin + offset - 1 (inc stride)
			}
		}
		goto
		JMP_PTR();


	__je_cmpi__:
		NOX_HOT_LABEL;
		{
			ASM_MARKER("__je_cmpi__");

			--sp;                                          // pop()
			const std::uint64_t abs { (*++ip).R64.AsU64 }; // absolute address
			if ((*sp).AsI64 == (*(sp + 1)).AsI64)
			{
				UPDATE_IP(); // ip = begin + offset - 1 (inc stride)
			}
			--sp; // pop()
		}
		goto
		JMP_PTR();


	__je_cmpf__:
		NOX_HOT_LABEL;
		{
			ASM_MARKER("__je_cmpf__");

			--sp;                                          // pop()
			const std::uint64_t abs { (*++ip).R64.AsU64 }; // absolute address
			if (Proxy_F64Equals((*sp).AsF64, (*(sp + 1)).AsF64))
			{
				UPDATE_IP(); // ip = begin + offset - 1 (inc stride)
			}
			--sp; // pop()
		}
		goto
		JMP_PTR();


	__jne_cmpi__:
		NOX_HOT_LABEL;
		{
			ASM_MARKER("__jne_cmpi__");

			--sp;                                          // pop()
			const std::uint64_t abs { (*++ip).R64.AsU64 }; // absolute address
			if ((*sp).AsI64 != (*(sp + 1)).AsI64)
			{
				UPDATE_IP(); // ip = begin + offset - 1 (inc stride)
			}
			--sp; // pop()
		}
		goto
		JMP_PTR();


	__jne_cmpf__:
		NOX_HOT_LABEL;
		{
			ASM_MARKER("__jne_cmpf__");

			--sp;                                          // pop()
			const std::uint64_t abs { (*++ip).R64.AsU64 }; // absolute address
			if (!Proxy_F64Equals((*sp).AsF64, (*(sp + 1)).AsF64))
			{
				UPDATE_IP(); // ip = begin + offset - 1 (inc stride)
			}
			--sp; // pop()
		}
		goto
		JMP_PTR();


	__ja_cmpi__:
		NOX_HOT_LABEL;
		{
			ASM_MARKER("__ja_cmpi__");

			--sp;                                          // pop()
			const std::uint64_t abs { (*++ip).R64.AsU64 }; // absolute address
			if ((*sp).AsI64 > (*(sp + 1)).AsI64)
			{
				UPDATE_IP(); // ip = begin + offset - 1 (inc stride)
			}
			--sp; // pop()
		}
		goto
		JMP_PTR();


	__ja_cmpf__:
		NOX_HOT_LABEL;
		{
			ASM_MARKER("__ja_cmpf__");

			--sp;                                          // pop()
			const std::uint64_t abs { (*++ip).R64.AsU64 }; // absolute address
			if ((*sp).AsF64 > (*(sp + 1)).AsF64)
			{
				UPDATE_IP(); // ip = begin + offset - 1 (inc stride)
			}
			--sp; // pop()
		}
		goto
		JMP_PTR();


	__jl_cmpi__:
		NOX_HOT_LABEL;
		{
			ASM_MARKER("__jl_cmpi__");

			--sp;                                          // pop()
			const std::uint64_t abs { (*++ip).R64.AsU64 }; // absolute address
			if ((*sp).AsI64 < (*(sp + 1)).AsI64)
			{
				UPDATE_IP(); // ip = begin + offset - 1 (inc stride)
			}
			--sp; // pop()
		}
		goto
		JMP_PTR();


	__jl_cmpf__:
		NOX_HOT_LABEL;
		{
			ASM_MARKER("__jl_cmpf__");

			--sp;                                          // pop()
			const std::uint64_t abs { (*++ip).R64.AsU64 }; // absolute address
			if ((*sp).AsF64 < (*(sp + 1)).AsF64)
			{
				UPDATE_IP(); // ip = begin + offset - 1 (inc stride)
			}
			--sp; // pop()
		}
		goto
		JMP_PTR();


	__jae_cmpi__:
		NOX_HOT_LABEL;
		{
			ASM_MARKER("__jae_cmpi__");

			--sp;                                          // pop()
			const std::uint64_t abs { (*++ip).R64.AsU64 }; // absolute address
			if ((*sp).AsI64 >= (*(sp + 1)).AsI64)
			{
				UPDATE_IP(); // ip = begin + offset - 1 (inc stride)
			}
			--sp; // pop()
		}
		goto
		JMP_PTR();


	__jae_cmpf__:
		NOX_HOT_LABEL;
		{
			ASM_MARKER("__jae_cmpf__");

			--sp;                                          // pop()
			const std::uint64_t abs { (*++ip).R64.AsU64 }; // absolute address
			if ((*sp).AsF64 >= (*(sp + 1)).AsF64)
			{
				UPDATE_IP(); // ip = begin + offset - 1 (inc stride)
			}
			--sp; // pop()
		}
		goto
		JMP_PTR();


	__jle_cmpi__:
		NOX_HOT_LABEL;
		{
			ASM_MARKER("__jle_cmpi__");

			--sp;                                          // pop()
			const std::uint64_t abs { (*++ip).R64.AsU64 }; // absolute address
			if ((*sp).AsI64 <= (*(sp + 1)).AsI64)
			{
				UPDATE_IP(); // ip = begin + offset - 1 (inc stride)
			}
			--sp; // pop()
		}
		goto
		JMP_PTR();


	__jle_cmpf__:
		NOX_HOT_LABEL;
		{
			ASM_MARKER("__jle_cmpf__");

			--sp;                                          // pop()
			const std::uint64_t abs { (*++ip).R64.AsU64 }; // absolute address
			if ((*sp).AsF64 <= (*(sp + 1)).AsF64)
			{
				UPDATE_IP(); // ip = begin + offset - 1 (inc stride)
			}
			--sp; // pop()
		}
		goto
		JMP_PTR();


	__ipushz__:
		NOX_HOT_LABEL;
		ASM_MARKER("__ipushz__");

		(*++sp).AsI64 = 0; // push(0)

		goto
		JMP_PTR();


	__ipusho__:
		NOX_HOT_LABEL;
		ASM_MARKER("__ipusho__");

		(*++sp).AsI64 = 1; // push(1)

		goto
		JMP_PTR();


	__fpusho__:
		NOX_HOT_LABEL;
		ASM_MARKER("__fpusho__");

		(*++sp).AsF64 = 1.0; // push(1)

		goto
		JMP_PTR();


	__iinc__:
		NOX_HOT_LABEL;
		ASM_MARKER("__iinc__");

		++(*sp).AsI64;

		goto
		JMP_PTR();


	__idec__:
		NOX_HOT_LABEL;
		ASM_MARKER("__idec__");

		--(*sp).AsI64;

		goto
		JMP_PTR();


	__iadd__:
		NOX_HOT_LABEL;
		ASM_MARKER("__iadd__");

		--sp;                             // pop
		(*sp).AsI64 += (*(sp + 1)).AsI64; // peek() += poke(1)

		goto
		JMP_PTR();


	__isub__:
		NOX_HOT_LABEL;
		ASM_MARKER("__isub__");

		--sp;                             // pop
		(*sp).AsI64 -= (*(sp + 1)).AsI64; // peek() -= poke(1)

		goto
		JMP_PTR();


	__imul__:
		NOX_HOT_LABEL;
		ASM_MARKER("__imul__");

		--sp;                             // pop
		(*sp).AsI64 *= (*(sp + 1)).AsI64; // peek() *= poke(1)

		goto
		JMP_PTR();


	__idiv__:
		NOX_HOT_LABEL;
		ASM_MARKER("__idiv__");

		--sp;                             // pop
		(*sp).AsI64 /= (*(sp + 1)).AsI64; // peek() /= poke(1)

		goto
		JMP_PTR();


	__imod__:
		NOX_HOT_LABEL;
		ASM_MARKER("__imod__");

		--sp;                             // pop
		(*sp).AsI64 %= (*(sp + 1)).AsI64; // peek() %= poke(1)

		goto
		JMP_PTR();


	__iand__:
		NOX_HOT_LABEL;
		ASM_MARKER("__iand__");
		--sp;                             // pop
		(*sp).AsI64 &= (*(sp + 1)).AsI64; // peek() &= poke(1)
		goto
		JMP_PTR();


	__ior__:
		NOX_HOT_LABEL;
		ASM_MARKER("__ior__");

		--sp;                             // pop
		(*sp).AsI64 |= (*(sp + 1)).AsI64; // peek() |= poke(1)

		goto
		JMP_PTR();


	__ixor__:
		NOX_HOT_LABEL;
		ASM_MARKER("__ixor__");

		--sp;                             // pop
		(*sp).AsI64 ^= (*(sp + 1)).AsI64; // peek() ^= poke(1)

		goto
		JMP_PTR();


	__icom__:
		NOX_HOT_LABEL;
		ASM_MARKER("__icom__");

		(*sp).AsI64 = ~(*sp).AsI64;

		goto
		JMP_PTR();


	__isal__:
		NOX_HOT_LABEL;
		ASM_MARKER("__isal__");

		--sp;                              // pop
		(*sp).AsI64 <<= (*(sp + 1)).AsI64; // peek() <<= poke(1)

		goto
		JMP_PTR();


	__isar__:
		NOX_HOT_LABEL;
		ASM_MARKER("__isar__");

		--sp;                              // pop
		(*sp).AsI64 >>= (*(sp + 1)).AsI64; // peek() >>= poke(1)

		goto
		JMP_PTR();


	__irol__:
		NOX_HOT_LABEL;
		ASM_MARKER("__irol__");

		--sp; // pop
		(*sp).AsU64 = Rol64((*sp).AsU64, static_cast<std::uint8_t>((*(sp + 1)).AsU64));

		goto
		JMP_PTR();


	__iror__:
		NOX_HOT_LABEL;
		ASM_MARKER("__iror__");

		--sp; // pop
		(*sp).AsU64 = Ror64((*sp).AsU64, static_cast<std::uint8_t>((*(sp + 1)).AsU64));

		goto
		JMP_PTR();


	__ineg__:
		NOX_HOT_LABEL;
		ASM_MARKER("__ineg__");

		(*sp).AsI64 = -(*sp).AsI64;

		goto
		JMP_PTR();


	__fadd__:
		NOX_HOT_LABEL;
		ASM_MARKER("__fadd__");

		--sp;                             // pop
		(*sp).AsF64 += (*(sp + 1)).AsF64; // peek() += poke(1)

		goto
		JMP_PTR();


	__fsub__:
		NOX_HOT_LABEL;
		ASM_MARKER("__fsub__");

		--sp;                             // pop
		(*sp).AsF64 -= (*(sp + 1)).AsF64; // peek() -= poke(1)

		goto
		JMP_PTR();


	__fmul__:
		NOX_HOT_LABEL;
		ASM_MARKER("__fmul__");

		--sp;                             // pop
		(*sp).AsF64 *= (*(sp + 1)).AsF64; // peek() *= poke(1)

		goto
		JMP_PTR();


	__fdiv__:
		NOX_HOT_LABEL;
		ASM_MARKER("__fdiv__");

		--sp;                             // pop
		(*sp).AsF64 /= (*(sp + 1)).AsF64; // peek() /= poke(1)

		goto
		JMP_PTR();


	__fmod__:
		NOX_HOT_LABEL;
		ASM_MARKER("__fmod__");

		--sp;                     // pop
		*sp %= (*(sp + 1)).AsF64; // peek() %= poke(1)

		goto
		JMP_PTR();


	__fneg__:
		NOX_HOT_LABEL;
		ASM_MARKER("__fneg__");

		(*sp).AsF64 = -(*sp).AsF64;

		goto
		JMP_PTR();


	__finc__:
		NOX_HOT_LABEL;
		ASM_MARKER("__finc__");

		++(*sp).AsF64;

		goto
		JMP_PTR();


	__fdec__:
		NOX_HOT_LABEL;
		ASM_MARKER("__fdec__");

		--(*sp).AsF64;

		goto
		JMP_PTR();


	__vpush__:
		NOX_HOT_LABEL;
		ASM_MARKER("__vpush__");

		/*
			SSE:
				movupd	(%r15), %xmm0
				movupd	16(%r15), %xmm1
				movupd	%xmm1, 16(%rdi)
				movupd	%xmm0, (%rdi)
				
			AVX:
				vmovupd 8(%rdi), %ymm0
				vmovupd %ymm0, 8(%rbx)
		*/
		std::memcpy(sp + 1, ip + 1, sizeof(Record) * 4);

		sp += 4;
		ip += 4;

		goto
		JMP_PTR();


	__vpop__:
		NOX_HOT_LABEL;
		ASM_MARKER("__vpop__");

		sp -= 4;

		goto
		JMP_PTR();

	__vadd__:
		NOX_HOT_LABEL;
		ASM_MARKER("__vadd__");

		/*
			SSE:
				movupd -0x38(%rbx), %xmm0
				movupd -0x28(%rbx), %xmm1
				movupd -0x18(%rbx), %xmm2
				addpd  %xmm0, %xmm2
				movupd -0x8(%rbx), %xmm0
				addpd  %xmm1, %xmm0
				movupd %xmm2, -0x38(%rbx)
				movupd %xmm0, -0x28(%rbx)

			AVX:
				vmovupd -0x38(%rbx), %ymm0
				vaddpd -0x18(%rbx), %ymm0, %ymm0
				vmovupd %ymm0, -0x38(%rbx)
		 */

		F64_X4_Add_Unaligned(reinterpret_cast<double*>(VEC_MOFFS(6)), reinterpret_cast<double*>(VEC_MOFFS(2)));
		sp -= 4;

		goto
		JMP_PTR();


	__vsub__:
		NOX_HOT_LABEL;
		ASM_MARKER("__vsub__");

		/*
			SSE:
				movupd -0x38(%rbx), %xmm0
				movupd -0x28(%rbx), %xmm1
				movupd -0x18(%rbx), %xmm2
				subpd  %xmm2, %xmm0
				movupd -0x8(%rbx), %xmm2
				subpd  %xmm2, %xmm1
				movupd %xmm0, -0x38(%rbx)
				movupd %xmm1, -0x28(%rbx)

			AVX:
				vmovupd -0x38(%rbx), %ymm0
				vsubpd -0x18(%rbx), %ymm0, %ymm0
				vmovupd %ymm0, -0x38(%rbx)
		 */

		F64_X4_Sub_Unaligned(reinterpret_cast<double*>(VEC_MOFFS(6)), reinterpret_cast<double*>(VEC_MOFFS(2)));

		sp -= 4;

		goto
		JMP_PTR();


	__vmul__:
		NOX_HOT_LABEL;
		ASM_MARKER("__vmul__");

		/*
			SSE:
				movupd -0x38(%rbx), %xmm0
				movupd -0x28(%rbx), %xmm1
				movupd -0x18(%rbx), %xmm2
				mulpd  %xmm0, %xmm2
				movupd -0x8(%rbx), %xmm0
				mulpd  %xmm1, %xmm0
				movupd %xmm2, -0x38(%rbx)
				movupd %xmm0, -0x28(%rbx)

			AVX:
				vmovupd -0x38(%rbx), %ymm0
				vmulpd -0x18(%rbx), %ymm0, %ymm0
				vmovupd %ymm0, -0x38(%rbx)
		 */

		F64_X4_Mul_Unaligned(reinterpret_cast<double*>(VEC_MOFFS(6)), reinterpret_cast<double*>(VEC_MOFFS(2)));

		sp -= 4;

		goto
		JMP_PTR();


	__vdiv__:
		NOX_HOT_LABEL;
		ASM_MARKER("__vdiv__");

		/*
			SSE:
				movupd -0x38(%rbx), %xmm0
				movupd -0x28(%rbx), %xmm1
				movupd -0x18(%rbx), %xmm2
				divpd  %xmm2, %xmm0
				movupd -0x8(%rbx), %xmm2
				divpd  %xmm2, %xmm1
				movupd %xmm0, -0x38(%rbx)
				movupd %xmm1, -0x28(%rbx)

			AVX:
				vmovupd -0x38(%rbx), %ymm0
				vdivpd -0x18(%rbx), %ymm0, %ymm0
				vmovupd %ymm0, -0x38(%rbx)
		 */

		F64_X4_Div_Unaligned(reinterpret_cast<double*>(VEC_MOFFS(6)), reinterpret_cast<double*>(VEC_MOFFS(2)));

		sp -= 4;

		goto
		JMP_PTR();

	__mpush__:
		NOX_HOT_LABEL;
		ASM_MARKER("__mpush__");

		/*
			SSE:
				movups 0x78(%rdi), %xmm0
				movups %xmm0, 0x78(%rbx)
				movups 0x68(%rdi), %xmm0
				movups %xmm0, 0x68(%rbx)
				movups 0x58(%rdi), %xmm0
				movups %xmm0, 0x58(%rbx)
				movups 0x48(%rdi), %xmm0
				movups %xmm0, 0x48(%rbx)
				movupd 0x8(%rdi), %xmm0
				movupd 0x18(%rdi), %xmm1
				movupd 0x28(%rdi), %xmm2
				movups 0x38(%rdi), %xmm3
				movups %xmm3, 0x38(%rbx)
				movupd %xmm2, 0x28(%rbx)
				movupd %xmm1, 0x18(%rbx)
				movupd %xmm0, 0x8(%rbx)

			AVX:
				vmovupd 0x8(%rdi), %ymm0
				vmovups 0x28(%rdi), %ymm1
				vmovups 0x48(%rdi), %ymm2
				vmovups 0x68(%rdi), %ymm3
				vmovups %ymm3, 0x68(%rbx)
				vmovups %ymm2, 0x48(%rbx)
				vmovups %ymm1, 0x28(%rbx)
				vmovupd %ymm0, 0x8(%rbx)

			AVX512F:
				vmovupd 0x8(%rdi), %zmm0
				vmovups 0x48(%rdi), %zmm1
				vmovups %zmm1, 0x48(%rbx)
				vmovupd %zmm0, 0x8(%rbx)
		 */
		std::memcpy(sp + 1, ip + 1, sizeof(Record) * 16);

		sp += 16;
		ip += 16;

		goto
		JMP_PTR();


	__mpop__:
		NOX_HOT_LABEL;
		ASM_MARKER("__mpop__");

		sp -= 16;

		goto
		JMP_PTR();

	__madd__:
		NOX_HOT_LABEL;
		ASM_MARKER("__madd__");

		/*
			SSE:
				movupd -0xf8(%rbx), %xmm0
				movupd -0xe8(%rbx), %xmm1
				movupd -0xd8(%rbx), %xmm2
				movupd -0xc8(%rbx), %xmm3
				movupd -0xb8(%rbx), %xmm4
				movupd -0xa8(%rbx), %xmm5
				movupd -0x98(%rbx), %xmm6
				movupd -0x88(%rbx), %xmm8
				movupd -0x78(%rbx), %xmm7
				addpd  %xmm0, %xmm7
				movupd -0x68(%rbx), %xmm0
				addpd  %xmm1, %xmm0
				movupd -0x58(%rbx), %xmm1
				addpd  %xmm2, %xmm1
				movupd -0x48(%rbx), %xmm2
				addpd  %xmm3, %xmm2
				movupd -0x38(%rbx), %xmm3
				addpd  %xmm4, %xmm3
				movupd -0x28(%rbx), %xmm4
				addpd  %xmm5, %xmm4
				movupd -0x18(%rbx), %xmm5
				addpd  %xmm6, %xmm5
				movupd -0x8(%rbx), %xmm6
				addpd  %xmm8, %xmm6
				movupd %xmm7, -0xf8(%rbx)
				movupd %xmm0, -0xe8(%rbx)
				movupd %xmm1, -0xd8(%rbx)
				movupd %xmm2, -0xc8(%rbx)
				movupd %xmm3, -0xb8(%rbx)
				movupd %xmm4, -0xa8(%rbx)
				movupd %xmm5, -0x98(%rbx)
				movupd %xmm6, -0x88(%rbx)

			AVX:
				vmovupd -0xf8(%rbx), %ymm0
				vmovupd -0xd8(%rbx), %ymm1
				vmovupd -0xb8(%rbx), %ymm2
				vmovupd -0x98(%rbx), %ymm3
				vaddpd -0x78(%rbx), %ymm0, %ymm0
				vaddpd -0x58(%rbx), %ymm1, %ymm1
				vaddpd -0x38(%rbx), %ymm2, %ymm2
				vaddpd -0x18(%rbx), %ymm3, %ymm3
				vmovupd %ymm0, -0xf8(%rbx)
				vmovupd %ymm1, -0xd8(%rbx)
				vmovupd %ymm2, -0xb8(%rbx)
				vmovupd %ymm3, -0x98(%rbx)

			AVX512F:
				vmovupd -0xf8(%rbx), %zmm0
				vaddpd -0x78(%rbx), %zmm0, %zmm0
				vmovupd %zmm0, -0xf8(%rbx)
				vmovupd %zmm0, -0xb8(%rbx)
		 */

		F64_X16_Add_Unaligned(reinterpret_cast<double*>(VEC_MOFFS(30)), reinterpret_cast<double*>(VEC_MOFFS(14)));
		sp -= 16;

		goto
		JMP_PTR();

	__msub__:
		NOX_HOT_LABEL;
		ASM_MARKER("__msub__");

		/*
			SSE:
				movupd -0xf8(%rbx), %xmm8
				movupd -0xe8(%rbx), %xmm1
				movupd -0xd8(%rbx), %xmm2
				movupd -0xc8(%rbx), %xmm3
				movupd -0xb8(%rbx), %xmm4
				movupd -0xa8(%rbx), %xmm5
				movupd -0x98(%rbx), %xmm6
				movupd -0x88(%rbx), %xmm7
				movupd -0x78(%rbx), %xmm0
				subpd  %xmm0, %xmm8
				movupd -0x68(%rbx), %xmm0
				subpd  %xmm0, %xmm1
				movupd -0x58(%rbx), %xmm0
				subpd  %xmm0, %xmm2
				movupd -0x48(%rbx), %xmm0
				subpd  %xmm0, %xmm3
				movupd -0x38(%rbx), %xmm0
				subpd  %xmm0, %xmm4
				movupd -0x28(%rbx), %xmm0
				subpd  %xmm0, %xmm5
				movupd -0x18(%rbx), %xmm0
				subpd  %xmm0, %xmm6
				movupd -0x8(%rbx), %xmm0
				subpd  %xmm0, %xmm7
				movupd %xmm8, -0xf8(%rbx)
				movupd %xmm1, -0xe8(%rbx)
				movupd %xmm2, -0xd8(%rbx)
				movupd %xmm3, -0xc8(%rbx)
				movupd %xmm4, -0xb8(%rbx)
				movupd %xmm5, -0xa8(%rbx)
				movupd %xmm6, -0x98(%rbx)
				movupd %xmm7, -0x88(%rbx)

			AVX:
				vmovupd -0xf8(%rbx), %ymm0
				vmovupd -0xd8(%rbx), %ymm1
				vmovupd -0xb8(%rbx), %ymm2
				vmovupd -0x98(%rbx), %ymm3
				vsubpd -0x78(%rbx), %ymm0, %ymm0
				vsubpd -0x58(%rbx), %ymm1, %ymm1
				vsubpd -0x38(%rbx), %ymm2, %ymm2
				vsubpd -0x18(%rbx), %ymm3, %ymm3
				vmovupd %ymm0, -0xf8(%rbx)
				vmovupd %ymm1, -0xd8(%rbx)
				vmovupd %ymm2, -0xb8(%rbx)
				vmovupd %ymm3, -0x98(%rbx)

			AVX512F:
				vmovupd -0xf8(%rbx), %zmm0
				vsubpd -0x78(%rbx), %zmm0, %zmm0
				vmovupd %zmm0, -0xf8(%rbx)
				vmovupd %zmm0, -0xb8(%rbx)
		 */

		F64_X16_Sub_Unaligned(reinterpret_cast<double*>(VEC_MOFFS(30)), reinterpret_cast<double*>(VEC_MOFFS(14)));
		sp -= 16;

		goto
		JMP_PTR();

	__mmul__:
		NOX_HOT_LABEL;
		ASM_MARKER("__mmul__");

		/*
			SSE:
				movupd -0xf8(%rbx), %xmm0
				movupd -0xe8(%rbx), %xmm1
				movupd -0xd8(%rbx), %xmm2
				movupd -0xc8(%rbx), %xmm3
				movupd -0xb8(%rbx), %xmm4
				movupd -0xa8(%rbx), %xmm5
				movupd -0x98(%rbx), %xmm6
				movupd -0x88(%rbx), %xmm8
				movupd -0x78(%rbx), %xmm7
				mulpd  %xmm0, %xmm7
				movupd -0x68(%rbx), %xmm0
				mulpd  %xmm1, %xmm0
				movupd -0x58(%rbx), %xmm1
				mulpd  %xmm2, %xmm1
				movupd -0x48(%rbx), %xmm2
				mulpd  %xmm3, %xmm2
				movupd -0x38(%rbx), %xmm3
				mulpd  %xmm4, %xmm3
				movupd -0x28(%rbx), %xmm4
				mulpd  %xmm5, %xmm4
				movupd -0x18(%rbx), %xmm5
				mulpd  %xmm6, %xmm5
				movupd -0x8(%rbx), %xmm6
				mulpd  %xmm8, %xmm6
				movupd %xmm7, -0xf8(%rbx)
				movupd %xmm0, -0xe8(%rbx)
				movupd %xmm1, -0xd8(%rbx)
				movupd %xmm2, -0xc8(%rbx)
				movupd %xmm3, -0xb8(%rbx)
				movupd %xmm4, -0xa8(%rbx)
				movupd %xmm5, -0x98(%rbx)
				movupd %xmm6, -0x88(%rbx)

			AVX:
				vmovupd -0xf8(%rbx), %ymm0
				vmovupd -0xd8(%rbx), %ymm1
				vmovupd -0xb8(%rbx), %ymm2
				vmovupd -0x98(%rbx), %ymm3
				vmulpd -0x78(%rbx), %ymm0, %ymm0
				vmulpd -0x58(%rbx), %ymm1, %ymm1
				vmulpd -0x38(%rbx), %ymm2, %ymm2
				vmulpd -0x18(%rbx), %ymm3, %ymm3
				vmovupd %ymm0, -0xf8(%rbx)
				vmovupd %ymm1, -0xd8(%rbx)
				vmovupd %ymm2, -0xb8(%rbx)
				vmovupd %ymm3, -0x98(%rbx)

			AVX512F:
				vmovupd -0xf8(%rbx), %zmm0
				vmulpd -0x78(%rbx), %zmm0, %zmm0
				vmovupd %zmm0, -0xf8(%rbx)
				vmovupd %zmm0, -0xb8(%rbx)
		 */

		F64_X16_Mul_Unaligned(reinterpret_cast<double*>(VEC_MOFFS(30)), reinterpret_cast<double*>(VEC_MOFFS(14)));
		sp -= 16;

		goto
		JMP_PTR();

	__mdiv__:
		NOX_HOT_LABEL;
		ASM_MARKER("__mdiv__");

		/*
			SSE:
				movupd -0xf8(%rbx), %xmm8
				movupd -0xe8(%rbx), %xmm1
				movupd -0xd8(%rbx), %xmm2
				movupd -0xc8(%rbx), %xmm3
				movupd -0xb8(%rbx), %xmm4
				movupd -0xa8(%rbx), %xmm5
				movupd -0x98(%rbx), %xmm6
				movupd -0x88(%rbx), %xmm7
				movupd -0x78(%rbx), %xmm0
				divpd  %xmm0, %xmm8
				movupd -0x68(%rbx), %xmm0
				divpd  %xmm0, %xmm1
				movupd -0x58(%rbx), %xmm0
				divpd  %xmm0, %xmm2
				movupd -0x48(%rbx), %xmm0
				divpd  %xmm0, %xmm3
				movupd -0x38(%rbx), %xmm0
				divpd  %xmm0, %xmm4
				movupd -0x28(%rbx), %xmm0
				divpd  %xmm0, %xmm5
				movupd -0x18(%rbx), %xmm0
				divpd  %xmm0, %xmm6
				movupd -0x8(%rbx), %xmm0
				divpd  %xmm0, %xmm7
				movupd %xmm8, -0xf8(%rbx)
				movupd %xmm1, -0xe8(%rbx)
				movupd %xmm2, -0xd8(%rbx)
				movupd %xmm3, -0xc8(%rbx)
				movupd %xmm4, -0xb8(%rbx)
				movupd %xmm5, -0xa8(%rbx)
				movupd %xmm6, -0x98(%rbx)
				movupd %xmm7, -0x88(%rbx)
				
			AVX:
				vmovupd -0xf8(%rbx), %ymm0
				vmovupd -0xd8(%rbx), %ymm1
				vmovupd -0xb8(%rbx), %ymm2
				vmovupd -0x98(%rbx), %ymm3
				vdivpd -0x78(%rbx), %ymm0, %ymm0
				vdivpd -0x58(%rbx), %ymm1, %ymm1
				vdivpd -0x38(%rbx), %ymm2, %ymm2
				vdivpd -0x18(%rbx), %ymm3, %ymm3
				movq %rdi, %rax
				vmovupd %ymm0, -0xf8(%rbx)
				vmovupd %ymm1, -0xd8(%rbx)
				vmovupd %ymm2, -0xb8(%rbx)
				vmovupd %ymm3, -0x98(%rbx)

			AVX512F:
				vmovupd -0xf8(%rbx), %zmm0
				vdivpd -0x78(%rbx), %zmm0, %zmm0
				vmovupd %zmm0, -0xf8(%rbx)
				vmovupd %zmm0, -0xb8(%rbx)
		 */

		F64_X16_Div_Unaligned(reinterpret_cast<double*>(VEC_MOFFS(30)), reinterpret_cast<double*>(VEC_MOFFS(14)));
		sp -= 16;

		goto
		JMP_PTR();

		[[maybe_unused]]
	_hard_fault_err_:
		NOX_COLD_LABEL;
		interruptCode = INT_CODE_FATAL_ERROR;

	_terminate_:
		NOX_COLD_LABEL;

		ASM_MARKER("_terminate_");

		output->ShutdownReason = MapIntAccum2ShutdownReason(interruptCode);
		output->Pre            = pre;
		output->Post           = std::chrono::high_resolution_clock::now();
		output->Duration       = std::chrono::high_resolution_clock::now() - pre;
		output->InterruptCode  = interruptCode;
		output->IpDiff         = ip - input->CodeChunk;
		output->SpDiff         = sp - input->Stack;
		output->BpDiff         = ip - bp;
		return output->ShutdownReason;
	}
}
