// File: ByteCode.hpp
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

#pragma once

#include <array>
#include <algorithm>
#include <cassert>
#include <string_view>
#include <span>
#include <optional>
#include <vector>

#include "Common.hpp"
#include "Core/Record.hpp"

namespace Nominax::Core
{
	union Record;
}

namespace Nominax::ByteCode
{
	/// <summary>
	/// Contains all byte code instructions with opcodes.
	/// </summary>
	enum class alignas(alignof(U64)) Instruction : U64
	{
		Int = 0x00'00'00'00'00'00'00'00,
		Intrin = 0x00'00'00'00'00'00'00'01,
		CIntrin = 0x00'00'00'00'00'00'00'02,
		Call = 0x00'00'00'00'00'00'00'03,
		Ret = 0x00'00'00'00'00'00'00'04,
		Mov = 0x00'00'00'00'00'00'00'05,
		Sto = 0x00'00'00'00'00'00'00'06,
		Push = 0x00'00'00'00'00'00'00'07,
		Pop = 0x00'00'00'00'00'00'00'08,
		Pop2 = 0x00'00'00'00'00'00'00'09,
		Dupl = 0x00'00'00'00'00'00'00'0A,
		Dupl2 = 0x00'00'00'00'00'00'00'0B,
		Swap = 0x00'00'00'00'00'00'00'0C,
		NOp = 0x00'00'00'00'00'00'00'0D,
		Jmp = 0x00'00'00'00'00'00'00'0E,
		JmpRel = 0x00'00'00'00'00'00'00'0F,
		Jz = 0x00'00'00'00'00'00'00'10,
		Jnz = 0x00'00'00'00'00'00'00'11,
		JoCmpi = 0x00'00'00'00'00'00'00'12,
		JoCmpf = 0x00'00'00'00'00'00'00'13,
		JnoCmpi = 0x00'00'00'00'00'00'00'14,
		JnoCmpf = 0x00'00'00'00'00'00'00'15,
		JeCmpi = 0x00'00'00'00'00'00'00'16,
		JeCmpf = 0x00'00'00'00'00'00'00'17,
		JneCmpi = 0x00'00'00'00'00'00'00'18,
		JneCmpf = 0x00'00'00'00'00'00'00'19,
		JaCmpi = 0x00'00'00'00'00'00'00'1A,
		JaCmpf = 0x00'00'00'00'00'00'00'1B,
		JlCmpi = 0x00'00'00'00'00'00'00'1C,
		JlCmpf = 0x00'00'00'00'00'00'00'1D,
		JaeCmpi = 0x00'00'00'00'00'00'00'1E,
		JaeCmpf = 0x00'00'00'00'00'00'00'1F,
		JleCmpi = 0x00'00'00'00'00'00'00'20,
		JleCmpf = 0x00'00'00'00'00'00'00'21,
		PushZ = 0x00'00'00'00'00'00'00'22,
		IPushO = 0x00'00'00'00'00'00'00'23,
		FPushO = 0x00'00'00'00'00'00'00'24,
		IInc = 0x00'00'00'00'00'00'00'25,
		IDec = 0x00'00'00'00'00'00'00'26,
		IAdd = 0x00'00'00'00'00'00'00'27,
		ISub = 0x00'00'00'00'00'00'00'28,
		IMul = 0x00'00'00'00'00'00'00'29,
		IDiv = 0x00'00'00'00'00'00'00'2A,
		IMod = 0x00'00'00'00'00'00'00'2B,
		IAnd = 0x00'00'00'00'00'00'00'2C,
		IOr = 0x00'00'00'00'00'00'00'2D,
		IXor = 0x00'00'00'00'00'00'00'2E,
		ICom = 0x00'00'00'00'00'00'00'2F,
		ISal = 0x00'00'00'00'00'00'00'30,
		ISar = 0x00'00'00'00'00'00'00'31,
		IRol = 0x00'00'00'00'00'00'00'32,
		IRor = 0x00'00'00'00'00'00'00'33,
		INeg = 0x00'00'00'00'00'00'00'34,
		FAdd = 0x00'00'00'00'00'00'00'35,
		FSub = 0x00'00'00'00'00'00'00'36,
		FMul = 0x00'00'00'00'00'00'00'37,
		FDiv = 0x00'00'00'00'00'00'00'38,
		FMod = 0x00'00'00'00'00'00'00'39,
		FNeg = 0x00'00'00'00'00'00'00'3A,
		FInc = 0x00'00'00'00'00'00'00'3B,
		FDec = 0x00'00'00'00'00'00'00'3C,
		VecPush = 0x00'00'00'00'00'00'00'3D,
		VecPop = 0x00'00'00'00'00'00'00'3E,
		VecAdd = 0x00'00'00'00'00'00'00'3F,
		VecSub = 0x00'00'00'00'00'00'00'40,
		VecMul = 0x00'00'00'00'00'00'00'41,
		VecDiv = 0x00'00'00'00'00'00'00'42,
		MatPush = 0x00'00'00'00'00'00'00'43,
		MatPop = 0x00'00'00'00'00'00'00'44,
		MatAdd = 0x00'00'00'00'00'00'00'45,
		MatSub = 0x00'00'00'00'00'00'00'46,
		MatMul = 0x00'00'00'00'00'00'00'47,
		MatDiv = 0x00'00'00'00'00'00'00'48,

		/* count of total instructions */
		$Count
	};

	/// <summary>
	/// Contains all instruction mnemonics.
	/// </summary>
	constexpr std::array<const std::string_view, static_cast<std::size_t>(Instruction::$Count)> INSTRUCTION_MNEMONICS
	{
		"int",
		"intrin",
		"cintrin",
		"call",
		"ret",
		"mov",
		"sto",
		"push",
		"pop",
		"pop2",
		"dupl",
		"dupl2",
		"swap",
		"nop",
		"jmp",
		"jmprel",
		"jz",
		"jnz",
		"jo_cmpi",
		"jo_cmpf",
		"jno_cmpi",
		"jno_cmpf",
		"je_cmpi",
		"je_cmpf",
		"jne_cmpi",
		"jne_cmpf",
		"ja_cmpi",
		"ja_cmpf",
		"jl_cmpi",
		"jl_cmpf",
		"jae_cmpi",
		"jae_cmpf",
		"jle_cmpi",
		"jle_cmpf",
		"pushz",
		"ipusho",
		"fpusho",
		"iinc",
		"idec",
		"iadd",
		"isub",
		"imul",
		"idiv",
		"imod",
		"iand",
		"ior",
		"ixor",
		"icom",
		"isal",
		"isar",
		"irol",
		"iror",
		"ineg",
		"fadd",
		"fsub",
		"fmul",
		"fdiv",
		"fmod",
		"fneg",
		"finc",
		"fdec",
		"vecpush",
		"vecpop",
		"vecadd",
		"vecsub",
		"vecmul",
		"vecdiv",
		"matpush",
		"matpop",
		"matadd",
		"matsub",
		"matmul",
		"matdiv"
	};

	/// <summary>
	/// Instruction category.
	/// </summary>
	enum class InstructionCategory : U8
	{
		Control,
		Memory,
		Branching,
		Arithmetic,
		BitWise
	};

	/// <summary>
	/// Contains the categories of all instructions.
	/// </summary>
	[[maybe_unused]]
	constexpr std::array INSTRUCTION_CATEGORIES
	{
		InstructionCategory::Control,
		InstructionCategory::Control,
		InstructionCategory::Control,
		InstructionCategory::Control,
		InstructionCategory::Control,
		InstructionCategory::Memory,
		InstructionCategory::Memory,
		InstructionCategory::Memory,
		InstructionCategory::Memory,
		InstructionCategory::Memory,
		InstructionCategory::Memory,
		InstructionCategory::Memory,
		InstructionCategory::Memory,
		InstructionCategory::Memory,
		InstructionCategory::Branching,
		InstructionCategory::Branching,
		InstructionCategory::Branching,
		InstructionCategory::Branching,
		InstructionCategory::Branching,
		InstructionCategory::Branching,
		InstructionCategory::Branching,
		InstructionCategory::Branching,
		InstructionCategory::Branching,
		InstructionCategory::Branching,
		InstructionCategory::Branching,
		InstructionCategory::Branching,
		InstructionCategory::Branching,
		InstructionCategory::Branching,
		InstructionCategory::Branching,
		InstructionCategory::Branching,
		InstructionCategory::Branching,
		InstructionCategory::Branching,
		InstructionCategory::Branching,
		InstructionCategory::Branching,
		InstructionCategory::Arithmetic,
		InstructionCategory::Arithmetic,
		InstructionCategory::Arithmetic,
		InstructionCategory::Arithmetic,
		InstructionCategory::Arithmetic,
		InstructionCategory::Arithmetic,
		InstructionCategory::Arithmetic,
		InstructionCategory::Arithmetic,
		InstructionCategory::Arithmetic,
		InstructionCategory::Arithmetic,
		InstructionCategory::BitWise,
		InstructionCategory::BitWise,
		InstructionCategory::BitWise,
		InstructionCategory::BitWise,
		InstructionCategory::BitWise,
		InstructionCategory::BitWise,
		InstructionCategory::BitWise,
		InstructionCategory::BitWise,
		InstructionCategory::BitWise,
		InstructionCategory::Arithmetic,
		InstructionCategory::Arithmetic,
		InstructionCategory::Arithmetic,
		InstructionCategory::Arithmetic,
		InstructionCategory::Arithmetic,
		InstructionCategory::Arithmetic,
		InstructionCategory::Arithmetic,
		InstructionCategory::Arithmetic,
		InstructionCategory::Memory,
		InstructionCategory::Memory,
		InstructionCategory::Arithmetic,
		InstructionCategory::Arithmetic,
		InstructionCategory::Arithmetic,
		InstructionCategory::Arithmetic,
	};

	/// <summary>
	/// Contains the amount of stack pushes each instruction will perform.
	/// </summary>
	constexpr std::array<U8, static_cast<std::size_t>(Instruction::$Count)> INSTRUCTION_PUSH_COUNTS
	{
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		1,
		0,
		0,
		1,
		2,
		2,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		1,
		1,
		1,
		1,
		1,
		1,
		1,
		1,
		1,
		1,
		1,
		1,
		1,
		1,
		1,
		1,
		1,
		1,
		1,
		1,
		1,
		1,
		1,
		1,
		1,
		1,
		1,
		4,
		0,
		4,
		4,
		4,
		4
	};

	/// <summary>
	/// Contains the amount of stack pops each instruction will perform.
	/// </summary>
	constexpr std::array<U8, static_cast<std::size_t>(Instruction::$Count)> INSTRUCTION_POP_COUNTS
	{
		0,
		0,
		0,
		0,
		1,
		0,
		0,
		0,
		1,
		2,
		0,
		0,
		2,
		0,
		0,
		0,
		1,
		1,
		1,
		1,
		1,
		1,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		0,
		0,
		1,
		1,
		1,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		2,
		1,
		2,
		2,
		2,
		2,
		1,
		2,
		2,
		2,
		2,
		2,
		1,
		1,
		1,
		0,
		4,
		8,
		8,
		8,
		8
	};

	/// <summary>
	/// Contains a short descriptions for all instructions.
	/// </summary>
	constexpr std::array<const std::string_view, static_cast<std::size_t>(Instruction::$Count)> INSTRUCTION_DESCRIPTIONS
	{
		"interrupt reactor execution",
		"call intrinsic system routine",
		"call custom intrinsic routine",
		"call procedure",
		"return from procedure",
		"copy stack slot to stack record",
		"copy immediate to stack record",
		"push one stack record onto stack",
		"pop one stack record from stack",
		"pop two records from stack",
		"duplicate stack top",
		"duplicate stack top two times",
		"swap the stack top slot with the lower slot",
		"no operation",
		"absolute direct unconditional jump",
		"relative indirect jump unconditional jump",
		"jump if zero",
		"jump if not zero",
		"jump if one - compare as integer",
		"jump if one - compare as F32",
		"jump if not one - compare as integer",
		"jump if not one - compare as  integer",
		"jump if equal as integer",
		"jump if equal - compare as F32ing point",
		"jump if not equal - compare  as integer",
		"jump if not equal - compare  as F32ing point",
		"jump if above - compare  as integer",
		"jump if above - compare  as F32ing point",
		"jump if less - compare as F32ing point",
		"jump if less - compare as F32ing point",
		"jump if above or equal - compare as integer",
		"jump if above or equal - compare as F32ing point",
		"jump if less or equal - compare as integer",
		"jump if less or equal - compare as F32ing point",
		"push zero as integer",
		"push one as  integer",
		"push one as F32ing point",
		"integer increment",
		"integer decrement",
		"integer addition",
		"integer subtraction",
		"integer multiplication",
		"integer division",
		"integer remainder",
		"integer bitwise and",
		"integer bitwise or",
		"integer bitwise xor",
		"integer bitwise complement",
		"integer bitwise arithmetic left shift",
		"integer bitwise arithmetic right shift",
		"integer bitwise rotation left",
		"integer bitwise right rotation",
		"integer negation",
		"floating point addition",
		"floating point subtraction",
		"floating point multiplication",
		"floating point division",
		"floating point remainder",
		"floating point negation",
		"floating point increment",
		"floating point decrement",
		"push quad vector",
		"pop quad vector",
		"floating point quad vector addition",
		"floating point quad vector subtraction",
		"floating point quad vector multiplication",
		"floating point quad vector division",
	};

	/// <summary>
	/// Contains the count of required immediate arguments for each instruction.
	/// </summary>
	constexpr std::array<U8, static_cast<std::size_t>(Instruction::$Count)> INSTRUCTION_IMMEDIATE_ARGUMENT_COUNTS
	{
		1, // int
		1,
		1,
		1,
		0,
		2, // mov
		2, // sto
		1, // push
		0,
		0,
		0,
		0,
		0, // swap
		0, // nop
		1, // jmp
		1,
		1,
		1,
		1,
		1,
		1,
		1,
		1,
		1,
		1,
		1,
		1,
		1,
		1,
		1,
		1,
		1,
		1,
		1,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		4,
		0,
		0,
		0,
		0,
		0,
		16,
		0,
		0,
		0,
		0,
		0,
	};

	consteval auto FindMaxImmediateArgumentCount() -> U8
	{
		U8 max {0};
		for (const U8 x : INSTRUCTION_IMMEDIATE_ARGUMENT_COUNTS)
		{
			max = std::max(max, x);
		}
		return max;
	}

	constexpr U8 MAX_IMMEDIATE_ARGUMENTS {FindMaxImmediateArgumentCount()};
	static_assert(MAX_IMMEDIATE_ARGUMENTS);

	/// <summary>
	/// Call id for system intrinsic routine.
	/// </summary>
	enum class alignas(alignof(U64)) SystemIntrinsicCallID : U64
	{
		Cos = 0x00'00'00'00'00'00'00'00,
		Sin = 0x00'00'00'00'00'00'00'01,
		Tan = 0x00'00'00'00'00'00'00'02,
		ACos = 0x00'00'00'00'00'00'00'03,
		ASin = 0x00'00'00'00'00'00'00'04,
		ATan = 0x00'00'00'00'00'00'00'05,
		ATan2 = 0x00'00'00'00'00'00'00'06,
		CosH = 0x00'00'00'00'00'00'00'07,
		SinH = 0x00'00'00'00'00'00'00'08,
		TanH = 0x00'00'00'00'00'00'00'09,
		ACosH = 0x00'00'00'00'00'00'00'0A,
		ASinH = 0x00'00'00'00'00'00'00'0B,
		ATanH = 0x00'00'00'00'00'00'00'0C,
		Exp = 0x00'00'00'00'00'00'00'0D,
		Log = 0x00'00'00'00'00'00'00'0E,
		Log10 = 0x00'00'00'00'00'00'00'0F,
		Exp2 = 0x00'00'00'00'00'00'00'10,
		ILogB = 0x00'00'00'00'00'00'00'11,
		Log2 = 0x00'00'00'00'00'00'00'12,
		Pow = 0x00'00'00'00'00'00'00'13,
		Sqrt = 0x00'00'00'00'00'00'00'14,
		Cbrt = 0x00'00'00'00'00'00'00'15,
		Hypot = 0x00'00'00'00'00'00'00'16,
		Ceil = 0x00'00'00'00'00'00'00'17,
		Floor = 0x00'00'00'00'00'00'00'18,
		Round = 0x00'00'00'00'00'00'00'19,
		RInt = 0x00'00'00'00'00'00'00'1A,
		IMax = 0x00'00'00'00'00'00'00'1B,
		IMin = 0x00'00'00'00'00'00'00'1C,
		FMax = 0x00'00'00'00'00'00'00'1D,
		FMin = 0x00'00'00'00'00'00'00'1E,
		Dim = 0x00'00'00'00'00'00'00'1F,
		IAbs = 0x00'00'00'00'00'00'00'20,
		FAbs = 0x00'00'00'00'00'00'00'21,
		IoPortWriteCluster = 0x00'00'00'00'00'00'00'22,
		IoPortReadCluster = 0x00'00'00'00'00'00'00'23,
		IoPortFlush = 0x00'00'00'00'00'00'00'24,

		/* !no intrinsic routine - count of total intrinsic routines! */
		$Count
	};

	/// <summary>
	/// Represents a jump address which
	/// is essentially an index to a instruction.
	/// For dynamic signals only.
	/// </summary>
	enum class alignas(alignof(U64)) JumpAddress : U64;

	/// <summary>
	/// Call id for custom intrinsic routine.
	/// </summary>
	enum class alignas(alignof(U64)) UserIntrinsicCallID : U64;

	/// <summary>
	/// Custom intrinsic routine function prototype.
	/// Contains the stack pointer as parameter.
	/// </summary>
	using IntrinsicRoutine = auto (Core::Record*) -> void;
	static_assert(std::is_function_v<IntrinsicRoutine>);

	using UserIntrinsicRoutineRegistry = std::span<IntrinsicRoutine*>;


	/// <summary>
	/// Utf-8 character constant without null terminator.
	/// </summary>
	union CharClusterUtf8
	{
		std::array<char8_t, 8> Chars;
		U64                    Merged;
	};

	inline auto operator ==(const CharClusterUtf8 left, const CharClusterUtf8 right) -> bool
	{
		return left.Merged == right.Merged;
	}

	inline auto operator !=(const CharClusterUtf8 left, const CharClusterUtf8 right) -> bool
	{
		return left.Merged == right.Merged;
	}

	/// <summary>
	/// Writes the string literal into the char clusters.
	/// If the string literal is longer than 8 chars, only the first 8 chars are written.
	/// Null terminators are not written, so it's possible to use the full 8 chars, without using the 8th as null terminator.
	/// </summary>
	/// <param name="data"></param>
	/// <param name="count"></param>
	/// <returns></returns>
	constexpr auto operator "" _cluster(const char8_t* const data, const std::size_t count) -> CharClusterUtf8
	{
		CharClusterUtf8 result { };
		for (std::size_t i {0}; i < std::clamp(count, count, sizeof(CharClusterUtf8)); ++i)
		{
			result.Chars[i] = data[i];
		}
		return result;
	}

	static_assert(sizeof(CharClusterUtf8) == sizeof(U64));
	static_assert(sizeof(char) == sizeof(char8_t));

	/// <summary>
	/// Utf-16 character constant without null terminator.
	/// </summary>
	union CharClusterUtf16
	{
		std::array<char16_t, 4> Chars;
		U64                     Merged;
	};

	inline auto operator ==(const CharClusterUtf16 left, const CharClusterUtf16 right) -> bool
	{
		return left.Merged == right.Merged;
	}

	inline auto operator !=(const CharClusterUtf16 left, const CharClusterUtf16 right) -> bool
	{
		return left.Merged == right.Merged;
	}

	static_assert(sizeof(CharClusterUtf16) == sizeof(U64));

	/// <summary>
	/// Utf-32 character constant without null terminator.
	/// </summary>
	union CharClusterUtf32
	{
		std::array<char32_t, 2> Chars;
		U64                     Merged;
	};

	inline auto operator ==(const CharClusterUtf32 left, const CharClusterUtf32 right) -> bool
	{
		return left.Merged == right.Merged;
	}

	inline auto operator !=(const CharClusterUtf32 left, const CharClusterUtf32 right) -> bool
	{
		return left.Merged == right.Merged;
	}

	static_assert(sizeof(CharClusterUtf32) == sizeof(U64));

	/// <summary>
	/// Contains all byte code validation results.
	/// </summary>
	enum class ValidationResultCode
	{
		/// <summary>
		/// Validation did not found any problems.
		/// </summary>
		Ok = 0,

		/// <summary>
		/// More arguments specified than required.
		/// </summary>
		TooManyArgumentsForInstruction,

		/// <summary>
		/// Not enough arguments specified, more are required.
		/// </summary>
		NotEnoughArgumentsForInstruction,

		/// <summary>
		/// Expected argument of other type.
		/// </summary>
		ArgumentTypeMismatch,

		/// <summary>
		/// No entries.
		/// </summary>
		Empty,

		/// <summary>
		/// Code is missing prologue code.
		/// </summary>
		MissingPrologueCode,

		/// <summary>
		/// Code is missing epilogue code.
		/// </summary>
		MissingEpilogueCode,

		/// <summary>
		/// Jump address out of bounds.
		/// </summary>
		InvalidJumpAddress,

		/// <summary>
		/// The corresponding user intrinsic routine is invalid or the call id is too big.
		/// </summary>
		InvalidUserIntrinsicCall,

		/// <summary>
		/// Maximum dynamic signals for validation: 0xFF'FF'FF'FF,
		/// because pointers are compressed to 32-bit in the validator internally.
		/// </summary>
		SignalLimitReached
	};

	/// <summary>
	/// Size of the extracted fault code section.
	/// </summary>
	constexpr std::size_t CROPPED_FAULT_CODE_DUMP_SIZE {8};

	/// <summary>
	/// Contains all byte code validation error messages.
	/// </summary>
	constexpr std::array<std::string_view, 10> BYTE_CODE_VALIDATION_RESULT_CODE_MESSAGES
	{
		"Ok",
		"Too many arguments provided!",
		"Not enough arguments provided!",
		"Argument data type mismatch!",
		"Empty byte code submitted!",
		"Missing code prologue!",
		"Missing code epilogue!",
		"Jump address is out of range or does not point to an instruction!",
		"Unknown system intrinsic call!",
		"Signal limit reached! Because of pointer compression no more than (2 ^ 32) - 1 signals are allowed!"
	};

	/// <summary>
	/// Represents a stream optimization level.
	/// </summary>
	enum class OptimizationLevel : U8
	{
		Off = 0,
		O1 = 1,
		O2 = 2,
		O3 = 3
	};

	consteval auto DefaultOptimizationLevel() -> OptimizationLevel
	{
		#if NOX_DEBUG
		return OptimizationLevel::O2;
		#else
		return OptimizationLevel::O3;
		#endif
	}

	/// <summary>
	/// 64-bit byte code signal data contains either an instruction or an immediate value.
	/// </summary>
	union alignas(alignof(U64)) Signal
	{
		/// <summary>
		/// Discriminator for discriminated signals.
		/// </summary>
		enum class Discriminator : U8
		{
			/// <summary>
			/// U64 in record.
			/// </summary>
			U64,

			/// <summary>
			/// I64 in record.
			/// </summary>
			I64,

			/// <summary>
			/// F64 in record.
			/// </summary>
			F64,

			/// <summary>
			/// Char cluster UTF-8.
			/// </summary>
			CharClusterUtf8,

			/// <summary>
			/// Char cluster UTF-16.
			/// </summary>
			CharClusterUtf16,

			/// <summary>
			/// Char cluster UTF-32.
			/// </summary>
			CharClusterUtf32,

			/// <summary>
			/// Byte code instruction.
			/// </summary>
			Instruction,

			/// <summary>
			/// System call id.
			/// </summary>
			SystemIntrinsicCallID,

			/// <summary>
			/// User call id.
			/// </summary>
			UserIntrinsicCallID,

			/// <summary>
			/// Byte code instruction opcode.
			/// </summary>
			OpCode,

			/// <summary>
			/// Pointer.
			/// </summary>
			Ptr,

			/// <summary>
			/// Jump address.
			/// </summary>
			JumpAddress
		};

		/// <summary>
		/// Reinterpret as Record64.
		/// </summary>
		Core::Record R64;

		/// <summary>
		/// Reinterpret as instruction.
		/// </summary>
		Instruction Instr;

		/// <summary>
		/// Reinterpret as system intrinsic call id.
		/// </summary>
		SystemIntrinsicCallID SystemIntrinID;

		/// <summary>
		/// Reinterpret as custom intrinsic call id.
		/// </summary>
		UserIntrinsicCallID UserIntrinID;

		/// <summary>
		/// Reinterpret as 64-bit unsigned opcode. (For intrinsic calls and instructions).
		/// </summary>
		U64 OpCode;

		/// <summary>
		/// Reinterpret as void pointer.
		/// </summary>
		void* Ptr;

		/// <summary>
			/// Reinterpret as jump target.
			/// </summary>
		JumpAddress JmpAddress;

		/// <summary>
		/// Default constructor.
		/// </summary>
		/// <returns></returns>
		Signal() = default;

		/// <summary>
		/// Construct from record64.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr Signal(Core::Record value);

		/// <summary>
		/// Construct from instruction.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr Signal(Instruction value);

		/// <summary>
		/// Construct from system intrinsic call id.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr Signal(SystemIntrinsicCallID value);

		/// <summary>
			/// Construct from custom intrinsic call id.
			/// </summary>
			/// <param name="value">The initial value.</param>
			/// <returns></returns>
		explicit constexpr Signal(UserIntrinsicCallID value);

		/// <summary>
		/// Construct from void pointer.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr Signal(void* value);

		/// <summary>
		/// Construct from 64-bit signed quadword integer.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr Signal(I64 value);

		/// <summary>
		/// Construct from 64-bit unsigned quadword integer.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr Signal(U64 value);

		/// <summary>
		/// Construct from 64-bit F64 precision F32.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr Signal(F64 value);

		/// <summary>
		/// Construct from UTF-8 char cluster.
		/// </summary>
		/// <param name="cluster"></param>
		/// <returns></returns>
		explicit constexpr Signal(CharClusterUtf8 cluster);

		/// <summary>
		/// Construct from UTF-16 char cluster.
		/// </summary>
		/// <param name="cluster"></param>
		/// <returns></returns>
		explicit constexpr Signal(CharClusterUtf16 cluster);

		/// <summary>
		/// Construct from UTF-32 char cluster.
		/// </summary>
		/// <param name="cluster"></param>
		/// <returns></returns>
		explicit constexpr Signal(CharClusterUtf32 cluster);

		/// <summary>
		/// Construct from 32-bit UTF-32 character.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr Signal(char32_t value);

		/// <summary>
		/// Construct from 64 bit jump address.
		/// </summary>
		/// <param name="value"></param>
		/// <returns></returns>
		explicit constexpr Signal(JumpAddress value);
	};

	constexpr Signal::Signal(const Core::Record value) : R64 {value} {}
	constexpr Signal::Signal(const Instruction value) : Instr {value} {}
	constexpr Signal::Signal(const SystemIntrinsicCallID value) : SystemIntrinID {value} {}
	constexpr Signal::Signal(const UserIntrinsicCallID value) : UserIntrinID {value} {}
	constexpr Signal::Signal(void* const value) : Ptr {value} {}
	constexpr Signal::Signal(const I64 value) : R64 {value} {}
	constexpr Signal::Signal(const U64 value) : R64 {value} {}
	constexpr Signal::Signal(const F64 value) : R64 {value} {}
	constexpr Signal::Signal(const CharClusterUtf8 cluster) : R64 {cluster.Merged} {}
	constexpr Signal::Signal(const CharClusterUtf16 cluster) : R64 {cluster.Merged} {}
	constexpr Signal::Signal(const CharClusterUtf32 cluster) : R64 {cluster.Merged} {}
	constexpr Signal::Signal(const char32_t value) : R64 {value} {}
	constexpr Signal::Signal(const JumpAddress value) : JmpAddress {value} {}

	/// <summary>
	/// Raw representation of a signal as bytes.
	/// </summary>
	using SignalByteBuffer = std::array<U8, sizeof(Signal)>;

	static_assert(std::is_trivial_v<Signal>);
	static_assert(std::is_default_constructible_v<Signal>);
	static_assert(std::is_same_v<std::underlying_type_t<Instruction>, U64>);
	static_assert(sizeof(Instruction) == sizeof(U64));
	static_assert(sizeof(Signal) == sizeof(U64));
	static_assert(std::is_standard_layout_v<Signal>);

	/// <summary>
	/// Restricts to valid byte code elements.
	/// </summary>
	/// <typeparam name="...Ts">The generic types to perform restriction checks on.</typeparam>
	template <typename T>
	concept BytecodeElement = requires(T x)
	{
		// Type size must either be 32 or 64 bits
		sizeof(T) == 4 || sizeof(T) == 8;
		alignof(T) == 4 || alignof(T) == 8;
		x == x;
		x != x;
		std::is_trivial_v<T>;
	};

	/// <summary>
	/// Maps a generic type to a signal discriminator, if applicable.
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <returns></returns>
	template <typename T> requires BytecodeElement<T>
	constexpr auto MapStreamType() -> std::optional<Signal::Discriminator>
	{
		if constexpr (std::is_same_v<Instruction, T>)
		{
			return {Signal::Discriminator::Instruction};
		}
		else if constexpr (std::is_same_v<SystemIntrinsicCallID, T>)
		{
			return {Signal::Discriminator::SystemIntrinsicCallID};
		}
		else if constexpr (std::is_same_v<UserIntrinsicCallID, T>)
		{
			return {Signal::Discriminator::UserIntrinsicCallID};
		}
		else if constexpr (std::is_same_v<JumpAddress, T>)
		{
			return {Signal::Discriminator::JumpAddress};
		}
		else if constexpr (std::is_same_v<U64, T>)
		{
			return {Signal::Discriminator::U64};
		}
		else if constexpr (std::is_same_v<I64, T>)
		{
			return {Signal::Discriminator::I64};
		}
		else if constexpr (std::is_same_v<F64, T>)
		{
			return {Signal::Discriminator::F64};
		}
		else if constexpr (std::is_same_v<CharClusterUtf8, T>)
		{
			return {Signal::Discriminator::CharClusterUtf8};
		}
		else if constexpr (std::is_same_v<CharClusterUtf16, T>)
		{
			return {Signal::Discriminator::CharClusterUtf16};
		}
		else if constexpr (std::is_same_v<CharClusterUtf32, T>)
		{
			return {Signal::Discriminator::CharClusterUtf32};
		}
		else
		{
			return std::nullopt;
		}
	}

	template <typename T>
	concept StreamScalar = requires
	{
		requires sizeof(T) == 4 || sizeof(T) == 8;
		requires alignof(T) == 4 || alignof(T) == 8;
		requires std::is_trivial_v<T>;
		requires std::is_floating_point_v<T> || std::is_integral_v<T>;
	};

	/// <summary>
	/// Represents an entry in the byte code stream.
	/// Both values are just copied from the internal storage of the stream.
	/// </summary>
	/// <typeparam name="V"></typeparam>
	/// <typeparam name="D"></typeparam>
	struct DiscriminatedSignal
	{
		/// <summary>
		/// Discriminator for the signal "Value".
		/// </summary>
		Signal::Discriminator Discriminator;

		/// <summary>
		/// The value itself.
		/// </summary>
		Signal Value;

		/// <summary>
		/// Construct.
		/// </summary>
		/// <param name="discriminator"></param>
		/// <param name="value"></param>
		/// <returns></returns>
		constexpr DiscriminatedSignal(Signal::Discriminator discriminator, Signal value);

		/// <summary>
		/// Check if discriminator matches generic type.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <returns></returns>
		template <typename T> requires BytecodeElement<T>
		[[nodiscard]]
		constexpr auto Contains() const -> bool;

		/// <summary>
		///  Check if discriminator matches generic type and value.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <param name="value"></param>
		/// <returns></returns>
		template <typename T> requires BytecodeElement<T>
		[[nodiscard]]
		constexpr auto Contains(T value) const -> bool;

		/// <summary>
		///  Check if discriminator matches generic type,
		///  and convert to T if possible.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <returns></returns>
		template <typename T> requires BytecodeElement<T>
		[[nodiscard]]
		constexpr auto Unwrap() const -> std::optional<std::remove_reference_t<T>>;

		/// <summary>
		/// Converted to T without discriminator checks.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <returns></returns>
		template <typename T> requires BytecodeElement<T>
		[[nodiscard]]
		constexpr auto UnwrapUnchecked() const -> std::remove_reference_t<T>;

		/// <summary>
		/// Equals.
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		constexpr auto operator ==(const DiscriminatedSignal& other) const -> bool;

		/// <summary>
		/// Not equals.
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		constexpr auto operator !=(const DiscriminatedSignal& other) const -> bool;
	};

	constexpr DiscriminatedSignal::DiscriminatedSignal(const Signal::Discriminator discriminator, const Signal value) : Discriminator {discriminator},
	                                                                                                                    Value {value} { }

	template <typename T> requires BytecodeElement<T>
	constexpr auto DiscriminatedSignal::Contains() const -> bool
	{
		static_assert(MapStreamType<T>());
		return this->Discriminator == *MapStreamType<T>();
	}

	template <typename T> requires BytecodeElement<T>
	constexpr auto DiscriminatedSignal::Contains(T value) const -> bool
	{
		static_assert(MapStreamType<std::remove_reference_t<T>>());
		const bool result
		{
			this->Discriminator == *MapStreamType<std::remove_reference_t<T>>()
			&& this->Value.R64.AsU64 == std::bit_cast<decltype(this->Value.R64.AsU64)>(value)
		};
		return result;
	}

	template <typename T> requires BytecodeElement<T>
	constexpr auto DiscriminatedSignal::Unwrap() const -> std::optional<std::remove_reference_t<T>>
	{
		return this->Contains<T>()
			       ? std::optional<std::remove_reference_t<T>> {std::bit_cast<T>(this->Value.R64.AsU64)}
			       : std::optional<std::remove_reference_t<T>> {std::nullopt};
	}

	template <typename T> requires BytecodeElement<T>
	constexpr auto DiscriminatedSignal::UnwrapUnchecked() const -> std::remove_reference_t<T>
	{
		return std::bit_cast<T>(this->Value.R64.AsU64);
	}

	constexpr auto DiscriminatedSignal::operator==(const DiscriminatedSignal& other) const -> bool
	{
		return this->Value.R64.AsU64 == other.Value.R64.AsU64;
	}

	constexpr auto DiscriminatedSignal::operator!=(const DiscriminatedSignal& other) const -> bool
	{
		return !(*this == other);
	}

	/// <summary>
	/// Contains the variant type indices of the storage type of DynamicSignal.
	/// </summary>
	using TypeIndexTable = std::vector<Signal::Discriminator>;

	/// <summary>
	/// 
	/// </summary>
	using PerInstructionArgTypes = std::vector<TypeIndexTable>;

	/// <summary>
	/// 
	/// </summary>
	inline constexpr std::array ANY_TYPE
	{
		Signal::Discriminator::U64,
		Signal::Discriminator::I64,
		Signal::Discriminator::F64,
		Signal::Discriminator::CharClusterUtf8,
		Signal::Discriminator::CharClusterUtf16,
		Signal::Discriminator::CharClusterUtf32
	};

	/// <summary>
	/// Contains all immediate argument types for each instruction.
	/// </summary>
	inline const std::array<PerInstructionArgTypes, static_cast<std::size_t>(Instruction::$Count)> INSTRUCTION_IMMEDIATE_ARGUMENT_TYPES
	{
		PerInstructionArgTypes {{Signal::Discriminator::I64}},                      // int
		{{Signal::Discriminator::SystemIntrinsicCallID}},                           // intrin
		{{Signal::Discriminator::UserIntrinsicCallID}},                             // cintrin
		{{Signal::Discriminator::U64}},                                             // call
		{ },                                                                        // ret
		{{Signal::Discriminator::U64}, {Signal::Discriminator::U64}},               // mov
		{{Signal::Discriminator::U64}, {std::begin(ANY_TYPE), std::end(ANY_TYPE)}}, // sto
		{{std::begin(ANY_TYPE), std::end(ANY_TYPE)}},                               // push
		{ },                                                                        // pop
		{ },                                                                        // pop2
		{ },                                                                        // dupl
		{ },                                                                        // dupl2
		{ },                                                                        // swap
		{ },                                                                        // nop
		{{Signal::Discriminator::JumpAddress}},                                     // jmp
		{{Signal::Discriminator::JumpAddress}},                                     // jmprel
		{{Signal::Discriminator::JumpAddress}},                                     // jz
		{{Signal::Discriminator::JumpAddress}},                                     // jnz
		{{Signal::Discriminator::JumpAddress}},                                     // jo_cmpi
		{{Signal::Discriminator::JumpAddress}},                                     // jo_cmpf
		{{Signal::Discriminator::JumpAddress}},                                     // jno_cmpi
		{{Signal::Discriminator::JumpAddress}},                                     // jno_cmpf
		{{Signal::Discriminator::JumpAddress}},                                     // je_cmpi
		{{Signal::Discriminator::JumpAddress}},                                     // je_cmpf
		{{Signal::Discriminator::JumpAddress}},                                     // jne_cmpi
		{{Signal::Discriminator::JumpAddress}},                                     // jne_cmpf
		{{Signal::Discriminator::JumpAddress}},                                     // ja_cmpi
		{{Signal::Discriminator::JumpAddress}},                                     // ja_cmpf
		{{Signal::Discriminator::JumpAddress}},                                     // jl_cmpi
		{{Signal::Discriminator::JumpAddress}},                                     // jl_cmpf
		{{Signal::Discriminator::JumpAddress}},                                     // jae_cmpi
		{{Signal::Discriminator::JumpAddress}},                                     // jae_cmpf
		{{Signal::Discriminator::JumpAddress}},                                     // jle_cmpi
		{{Signal::Discriminator::JumpAddress}},                                     // jle_cmpf
		{ },                                                                        // pushz
		{ },                                                                        // ipusho
		{ },                                                                        // fpusho
		{ },                                                                        // iinc
		{ },                                                                        // idec
		{ },                                                                        // iadd
		{ },                                                                        // isub
		{ },                                                                        // imul
		{ },                                                                        // idiv
		{ },                                                                        // imod
		{ },                                                                        // iand
		{ },                                                                        // ior
		{ },                                                                        // ixor
		{ },                                                                        // icom
		{ },                                                                        // isal
		{ },                                                                        // isar
		{ },                                                                        // irol
		{ },                                                                        // iror
		{ },                                                                        // ineg
		{ },                                                                        // fadd
		{ },                                                                        // fsub
		{ },                                                                        // fmul
		{ },                                                                        // fdiv
		{ },                                                                        // fmod
		{ },                                                                        // fneg
		{ },                                                                        // finc
		{ },                                                                        // fdec
		{
			// vpush
			{std::begin(ANY_TYPE), std::end(ANY_TYPE)},
			{std::begin(ANY_TYPE), std::end(ANY_TYPE)},
			{std::begin(ANY_TYPE), std::end(ANY_TYPE)},
			{std::begin(ANY_TYPE), std::end(ANY_TYPE)}
		},
		{ }, // vpop
		{ }, // vadd
		{ }, // vsub
		{ }, // vmul
		{ }, // vdiv
		{
			// matpush
			{std::begin(ANY_TYPE), std::end(ANY_TYPE)},
			{std::begin(ANY_TYPE), std::end(ANY_TYPE)},
			{std::begin(ANY_TYPE), std::end(ANY_TYPE)},
			{std::begin(ANY_TYPE), std::end(ANY_TYPE)},
			{std::begin(ANY_TYPE), std::end(ANY_TYPE)},
			{std::begin(ANY_TYPE), std::end(ANY_TYPE)},
			{std::begin(ANY_TYPE), std::end(ANY_TYPE)},
			{std::begin(ANY_TYPE), std::end(ANY_TYPE)},
			{std::begin(ANY_TYPE), std::end(ANY_TYPE)},
			{std::begin(ANY_TYPE), std::end(ANY_TYPE)},
			{std::begin(ANY_TYPE), std::end(ANY_TYPE)},
			{std::begin(ANY_TYPE), std::end(ANY_TYPE)},
			{std::begin(ANY_TYPE), std::end(ANY_TYPE)},
			{std::begin(ANY_TYPE), std::end(ANY_TYPE)},
			{std::begin(ANY_TYPE), std::end(ANY_TYPE)},
			{std::begin(ANY_TYPE), std::end(ANY_TYPE)},
		},
		{ }, // matpop
		{ }, // matadd
		{ }, // matsub
		{ }, // matmul
		{ }  // matdiv
	};

	/// <summary>
	/// 
	/// </summary>
	/// <param name="instruction"></param>
	/// <returns></returns>
	[[nodiscard]]
	inline auto LookupInstructionArgumentTypes(const Instruction instruction) -> const PerInstructionArgTypes&
	{
		return INSTRUCTION_IMMEDIATE_ARGUMENT_TYPES[static_cast<std::size_t>(instruction)];
	}


	/// <summary>
	/// 
	/// </summary>
	[[nodiscard]]
	inline auto LookupInstructionArgumentCount(const Instruction instruction) -> std::size_t
	{
		return INSTRUCTION_IMMEDIATE_ARGUMENT_TYPES[static_cast<std::size_t>(instruction)].size();
	}

	/// <summary>
	/// 
	/// </summary>
	[[nodiscard]]
	inline auto LookupInstructionArgumentAllowedTypeCount(const Instruction instruction, const std::size_t argumentIndex) -> std::size_t
	{
		return INSTRUCTION_IMMEDIATE_ARGUMENT_TYPES[static_cast<std::size_t>(instruction)][argumentIndex].size();
	}

	/// <summary>
	/// An optimized and ready to execute code chunk.
	/// </summary>
	class Image final
	{
		Signal*     Blob_ {nullptr};
		std::size_t Size_ {0};

	public:
		/// <summary>
		/// 
		/// </summary>
		/// <returns>The size of the blob in bytes.</returns>
		[[nodiscard]]
		auto GetByteSize() const -> std::size_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The size of the blob (amount of signals).</returns>
		[[nodiscard]]
		auto GetSize() const -> std::size_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Data pointer of the blob.</returns>
		[[nodiscard]]
		auto GetBlobData() const -> const Signal*;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Data pointer of the blob as byte ptr.</returns>
		[[nodiscard]]
		auto GetByteData() const -> const U8*;

		/// <summary>
		/// Check of null pointer or zero size.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto IsEmpty() const -> bool;

		/// <summary>
		/// Returns the data as modifiable reactor view.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto GetReactorView() const -> std::span<Signal>;

		/// <summary>
		/// Construct empty image.
		/// </summary>
		Image() = default;

		/// <summary>
		/// Construct with by copying blob.
		/// Allocates an internal blob for the image
		/// and copies the data into it.
		/// </summary>
		/// <param name="blob">The blob to copy the data from.</param>
		explicit Image(std::span<const Signal> blob);

		/// <summary>
		/// Construct by coping blob.
		/// Allocates an internal blob for the image
		/// and copies the data into it.
		/// </summary>
		/// <param name="data">The blob to copy the data from.</param>
		/// <param name="byteSize">The size of the data in bytes.</param>
		Image(const void* data, std::size_t byteSize);

		/// <summary>
		/// Construct with owning blob.
		/// Assumes that the data is owned by this instance after construction.
		/// </summary>
		/// <param name="data">The data to be used as buffer.</param>
		/// <param name="size">The size of the data in records.</param>
		Image(Signal* data, std::size_t size);

		/// <summary>
		/// Construct with blob.
		/// Assumes that the data is owned by this instance after construction.
		/// </summary>
		/// <param name="data">The data to be used as buffer.</param>
		/// <param name="size">The size of the data in bytes.</param>
		Image(U8* data, std::size_t size);

		/// <summary>
		/// No copying.
		/// </summary>
		/// <param name="other"></param>
		Image(const Image& other) = delete;

		/// <summary>
		/// Move constructor.
		/// </summary>
		/// <param name="other"></param>
		Image(Image&& other);

		/// <summary>
		/// No copying.
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		auto operator =(const Image& other) -> Image& = delete;

		/// <summary>
		/// Copy assignment operator.
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		auto operator =(Image&& other) -> Image&;

		/// <summary>
		/// Destructor.
		/// </summary>
		~Image();

		/// <summary>
		/// STL iterator interface.
		/// </summary>
		/// <returns>Iterator.</returns>
		[[nodiscard]]
		auto begin() const -> const Signal*;

		/// <summary>
		/// STL iterator interface.
		/// </summary>
		/// <returns>Iterator.</returns>
		[[nodiscard]]
		auto end() const -> const Signal*;

		/// <summary>
		/// STL iterator interface.
		/// </summary>
		/// <returns>Iterator.</returns>
		[[nodiscard]]
		auto cbegin() const -> const Signal*;

		/// <summary>
		/// STL iterator interface.
		/// </summary>
		/// <returns>Iterator.</returns>
		[[nodiscard]]
		auto cend() const -> const Signal*;

		/// <summary>
		/// Subscript operator.
		/// </summary>
		/// <param name="idx"></param>
		/// <returns></returns>
		auto operator [](std::size_t idx) -> Signal&;

		/// <summary>
		/// Subscript operator.
		/// </summary>
		/// <param name="idx"></param>
		/// <returns></returns>
		auto operator [](std::size_t idx) const -> Signal;
	};

	inline auto Image::GetByteSize() const -> std::size_t
	{
		return this->Size_ * sizeof(Signal);
	}

	inline auto Image::GetSize() const -> std::size_t
	{
		return this->Size_;
	}

	inline auto Image::GetBlobData() const -> const Signal*
	{
		return this->Blob_;
	}

	inline auto Image::GetByteData() const -> const U8*
	{
		return reinterpret_cast<const U8*>(this->Blob_);
	}

	inline auto Image::IsEmpty() const -> bool
	{
		return !this->Size_ || !this->Blob_;
	}

	inline auto Image::begin() const -> const Signal*
	{
		return this->Blob_;
	}

	inline auto Image::end() const -> const Signal*
	{
		return this->Blob_ + this->Size_;
	}

	inline auto Image::cbegin() const -> const Signal*
	{
		return this->Blob_;
	}

	inline auto Image::cend() const -> const Signal*
	{
		return this->Blob_ + this->Size_;
	}

	/// <summary>
	/// STL iterator interface.
	/// </summary>
	/// <returns>Iterator.</returns>
	[[nodiscard]]
	inline auto begin(const Image& image) -> const Signal*
	{
		return image.begin();
	}

	/// <summary>
	/// STL iterator interface.
	/// </summary>
	/// <returns>Iterator.</returns>
	[[nodiscard]]
	inline auto end(const Image& image) -> const Signal*
	{
		return image.end();
	}

	/// <summary>
	/// STL iterator interface.
	/// </summary>
	/// <returns>Iterator.</returns>
	[[nodiscard]]
	inline auto cbegin(const Image& image) -> const Signal*
	{
		return image.cbegin();
	}

	/// <summary>
	/// STL iterator interface.
	/// </summary>
	/// <returns>Iterator.</returns>
	[[nodiscard]]
	inline auto cend(const Image& image) -> const Signal*
	{
		return image.cend();
	}

	inline auto Image::operator[](const std::size_t idx) const -> Signal
	{
		return *(this->Blob_ + idx);
	}

	inline auto Image::operator[](const std::size_t idx) -> Signal&
	{
		return *(this->Blob_ + idx);
	}

	inline auto Image::GetReactorView() const -> std::span<Signal>
	{
		auto* const begin {this->Blob_};
		auto* const end {this->Blob_ + this->Size_};
		return {begin, end};
	}

	template <typename T> requires StreamScalar<T>
	class ScopedVariable;

	/// <summary>
	/// Proxy type for scoped variable value type.
	/// </summary>
	/// <typeparam name="T"></typeparam>
	template <typename T>
	class ScopedVariableProxyType final
	{
		using Type = std::decay_t<T>;
	};

	/// <summary>
	/// Proxy type for scoped variable value type.
	/// </summary>
	template <>
	class ScopedVariableProxyType<signed>
	{
		using Type = I64;
	};

	/// <summary>
	/// Restrict stream expression type.
	/// </summary>
	template <typename F, typename V>
	concept StreamWithExpressionType = requires
	{
		requires std::is_trivial_v<V>;
		requires std::is_floating_point_v<V> || std::is_integral_v<V>;
		// TODO: Validate that F() is callable with F(V, ScopedVariable<ScopedVariableProxyType<V>>)
	};

	/// <summary>
	/// Validate template instruction.
	/// </summary>
	template <const Instruction I, typename... Ts>
	concept ValidInstruction = requires
	{
		requires sizeof...(Ts) == INSTRUCTION_IMMEDIATE_ARGUMENT_COUNTS[static_cast<std::underlying_type_t<decltype(I)>>(I)];
	};

	/// <summary>
	/// Validate template instruction argument.
	/// </summary>
	template <typename... Ts>
	concept ValidInstructionArgument = requires
	{
		requires std::is_trivial_v<std::decay_t<Ts>...>;
		requires std::is_integral_v<std::decay_t<Ts>...>
		|| std::is_floating_point_v<std::decay_t<Ts>...>
		|| std::is_enum_v<std::decay_t<Ts>...>;
		requires (sizeof(std::decay_t<Ts>) + ... + 0) % sizeof(I64) == 0
		|| (sizeof(std::decay_t<Ts>) + ... + 0) % sizeof(I32) == 0;
	};

	/// <summary>
	/// Contains the boolean values for the jump map.
	/// We cannot use vector<bool> because it's a specialization
	/// and does not allow pointer to it's elements, because they are stored as bits.
	/// </summary>
	using JumpMap = std::vector<U8>;

	/// <summary>
	/// Execution ready byte code and jump map.
	/// </summary>
	using AppCodeBundle = std::tuple<Image, JumpMap>;

	/// <summary>
	/// Dynamic byte code stream.
	/// </summary>
	class Stream final
	{
	public:
		/// <summary>
		/// Data structure to store the whole byte code.
		/// </summary>
		using CodeStorageType = std::vector<Signal>;

		/// <summary>
		/// Data structure to store the discriminator for each signal.
		/// </summary>
		using DiscriminatorStorageType = std::vector<Signal::Discriminator>;

	private:
		/// <summary>
		/// Required prologue code.
		/// </summary>
		static constexpr std::array PROLOGUE_CODE
		{
			DiscriminatedSignal {Signal::Discriminator::Instruction, Signal {Instruction::NOp}}
		};

		/// <summary>
		/// Required epilogue code.
		/// </summary>
		static constexpr std::array EPILOGUE_CODE
		{
			DiscriminatedSignal {Signal::Discriminator::Instruction, Signal {Instruction::Int}},
			DiscriminatedSignal {Signal::Discriminator::I64, Signal { }}
		};

		/// <summary>
		/// Contains the whole byte code.
		/// </summary>
		CodeStorageType Code_ { };

		/// <summary>
		/// Contains all discriminators for the byte code.
		/// Must always be same size as the "Code_" above.
		/// </summary>
		DiscriminatorStorageType CodeDisc_ { };

		/// <summary>
		/// Optimization level used for stream.
		/// </summary>
		OptimizationLevel OptimizationLevel_ {DefaultOptimizationLevel()};

	public:
		/// <summary>
		/// Query prologue code.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		static constexpr auto PrologueCode() -> const auto&;

		/// <summary>
		/// Query epilogue code.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		static constexpr auto EpilogueCode() -> const auto&;

		/// <summary>
		/// Returns PrologueCode.size() + EpilogueCode().size()
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		static constexpr auto MandatoryCodeSize() -> std::size_t;

		/// <summary>
		/// Construct empty stream.
		/// </summary>
		/// <returns></returns>
		Stream() = default;

		/// <summary>
		/// Construct with specific optimization level.
		/// </summary>
		/// <param name="optimizationLevel"></param>
		/// <returns></returns>
		explicit Stream(OptimizationLevel optimizationLevel);

		/// <summary>
		/// Move constructor.
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		Stream(Stream&& other) = default;

		/// <summary>
		/// No copy.
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		Stream(const Stream& other) = delete;

		/// <summary>
		/// Move assignment operator.
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		auto operator =(Stream&& other) -> Stream& = default;

		/// <summary>
		/// No copy.
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		auto operator =(const Stream& other) -> Stream& = delete;

		/// <summary>
		/// Destructor.
		/// </summary>
		~Stream() = default;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The underlying code buffer.</returns>
		[[nodiscard]]
		auto GetCodeBuffer() const -> const CodeStorageType&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The underlying discriminator buffer.</returns>
		[[nodiscard]]
		auto GetDiscriminatorBuffer() const -> const DiscriminatorStorageType&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto Front() const -> DiscriminatedSignal;

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto Back() const -> DiscriminatedSignal;

		/// <summary>
		/// Clears the content of the whole stream.
		/// </summary>
		/// <returns></returns>
		auto Clear() -> void;

		/// <summary>
		/// Resize buffer size.
		/// </summary>
		/// <param name="size"></param>
		/// <returns></returns>
		auto Resize(std::size_t size) -> void;

		/// <summary>
		/// Reserve buffer size.
		/// </summary>
		/// <param name="size"></param>
		/// <returns></returns>
		auto Reserve(std::size_t size) -> void;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The size of the stream.</returns>
		[[nodiscard]]
		auto Size() const -> std::size_t;

		/// <summary>
		/// Returns true if the stream contains
		/// no code or only prologue and or epilogue.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto IsEmpty() const -> bool;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The size of the stream in bytes.</returns>
		[[nodiscard]]
		auto SizeInBytes() const -> std::size_t;

		/// <summary>
		/// Push stream entry.
		/// </summary>
		/// <param name="instr"></param>
		/// <returns></returns>
		auto operator <<(Instruction instr) -> Stream&;

		/// <summary>
		/// Push stream entry.
		/// </summary>
		/// <param name="intrin"></param>
		/// <returns></returns>
		auto operator <<(SystemIntrinsicCallID intrin) -> Stream&;

		/// <summary>
		/// Push stream entry.
		/// </summary>
		/// <param name="intrin"></param>
		/// <returns></returns>
		auto operator <<(UserIntrinsicCallID intrin) -> Stream&;

		/// <summary>
		/// Push stream entry.
		/// </summary>
		/// <param name="address"></param>
		/// <returns></returns>
		auto operator <<(JumpAddress address) -> Stream&;

		/// <summary>
		/// Push stream entry.
		/// </summary>
		/// <param name="value"></param>
		/// <returns></returns>
		auto operator <<(U64 value) -> Stream&;

		/// <summary>
		/// Push stream entry.
		/// </summary>
		/// <param name="value"></param>
		/// <returns></returns>
		auto operator <<(I64 value) -> Stream&;

		/// <summary>
		/// Sign extend 32-bit signed integer to I64 and push.
		/// </summary>
		/// <param name="value"></param>
		/// <returns></returns>
		auto operator <<(signed value) -> Stream&;

		/// <summary>
		/// Push stream entry.
		/// </summary>
		/// <param name="value"></param>
		/// <returns></returns>
		auto operator <<(F64 value) -> Stream&;

		/// <summary>
		/// Push stream entry.
		/// </summary>
		/// <param name="value"></param>
		/// <returns></returns>
		auto operator <<(CharClusterUtf8 value) -> Stream&;

		/// <summary>
		/// Push stream entry.
		/// </summary>
		/// <param name="value"></param>
		/// <returns></returns>
		auto operator <<(CharClusterUtf16 value) -> Stream&;

		/// <summary>
		/// Push stream entry.
		/// </summary>
		/// <param name="value"></param>
		/// <returns></returns>
		auto operator <<(CharClusterUtf32 value) -> Stream&;

		/// <summary>
		/// Print out immediate byte code.
		/// </summary>
		/// <returns></returns>
		auto PrintByteCode() const -> void;

		/// <summary>
		/// Print the size of the stream with memory info.
		/// </summary>
		/// <returns></returns>
		auto PrintMemoryCompositionInfo() const -> void;

		/// <summary>
		/// Index lookup.
		///Slow! O(i)
		/// </summary>
		/// <param name="idx"></param>
		/// <returns></returns>
		auto operator [](std::size_t idx) const -> DiscriminatedSignal;

		/// <summary>
		/// Insert instruction manually with immediate arguments.
		/// </summary>
		/// <param name="args"></param>
		/// <returns></returns>
		template <Instruction I, typename... Ts> requires ValidInstruction<I, Ts...> && ValidInstructionArgument<Ts...>
		auto Do(Ts&&...args) -> Stream&;

		/// <summary>
		/// Insert instruction manually without immediate arguments.
		/// </summary>
		/// <returns></returns>
		template <Instruction I>
		auto Do() -> Stream&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>True if the current stream contains required epilogue code, else false.</returns>
		[[nodiscard]]
		auto ContainsEpilogue() const -> bool;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>True if the current stream contains required prologue code, else false.</returns>
		[[nodiscard]]
		auto ContainsPrologue() const -> bool;

		/// <summary>
		/// Begin stream building.
		/// Inserts code prologue, if missing.
		/// </summary>
		/// <returns></returns>
		auto Prologue() -> Stream&;

		/// <summary>
		/// End stream building.
		/// Inserts code epilogue, if missing.
		/// </summary>
		/// <returns></returns>
		auto Epilogue() -> Stream&;

		/// <summary>
		/// Map new local variable into the stream.
		/// It is a scoped variable, which means it is automatically popped,
		/// when it goes out of the lambda scope.
		/// </summary>
		/// <typeparam name="F"></typeparam>
		/// <typeparam name="V"></typeparam>
		/// <param name="value"></param>
		/// <param name="functor"></param>
		/// <returns>self</returns>
		template <typename F, typename V> requires StreamWithExpressionType<F, V>
		auto With(V value, F&& functor) -> Stream&;

		/// <summary>
		/// Validate and build code chunk plus jump map.
		/// </summary>
		/// <param name="out"></param>
		/// <param name="outJumpMap"></param>
		/// <returns></returns>
		auto Build(Image& out, JumpMap& outJumpMap) const -> ValidationResultCode;

		/// <summary>
		/// Validate and build code chunk plus jump map into app code bundle.
		/// </summary>
		/// <param name="out"></param>
		/// <returns></returns>
		auto Build(AppCodeBundle& out) const -> ValidationResultCode;

		/// <summary>
		/// Get current optimization level.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto GetOptimizationLevel() const -> OptimizationLevel;

		/// <summary>
		/// Set current optimization level.
		/// </summary>
		/// <param name="optimizationLevel"></param>
		/// <returns></returns>
		auto SetOptimizationLevel(OptimizationLevel optimizationLevel) -> void;
	};

	constexpr auto Stream::PrologueCode() -> const auto&
	{
		return PROLOGUE_CODE;
	}

	constexpr auto Stream::EpilogueCode() -> const auto&
	{
		return EPILOGUE_CODE;
	}

	constexpr auto Stream::MandatoryCodeSize() -> std::size_t
	{
		return PrologueCode().size() + EpilogueCode().size();
	}

	static_assert(Stream::MandatoryCodeSize() == Stream::PrologueCode().size() + Stream::EpilogueCode().size());

	inline Stream::Stream(const OptimizationLevel optimizationLevel) : OptimizationLevel_ {optimizationLevel} { }

	inline auto Stream::GetOptimizationLevel() const -> OptimizationLevel
	{
		return this->OptimizationLevel_;
	}

	inline auto Stream::SetOptimizationLevel(const OptimizationLevel optimizationLevel) -> void
	{
		this->OptimizationLevel_ = optimizationLevel;
	}

	inline auto Stream::Build(AppCodeBundle& out) const -> ValidationResultCode
	{
		return this->Build(std::get<0>(out), std::get<1>(out));
	}

	template <Instruction I, typename... Ts> requires ValidInstruction<I, Ts...> && ValidInstructionArgument<Ts...>
	inline auto Stream::Do(Ts&&...args) -> Stream&
	{
		*this << I;
		return (*this << ... << args);
	}

	template <Instruction I>
	inline auto Stream::Do() -> Stream&
	{
		return *this << I;
	}

	template <typename F, typename V> requires StreamWithExpressionType<F, V>
	inline auto Stream::With(const V value, F&& functor) -> Stream&
	{
		if constexpr (std::is_same_v<signed, V>)
		{
			functor(ScopedVariable<I64> {*this, static_cast<I64>(value)});
		}
		else
		{
			functor(ScopedVariable<V> {*this, value});
		}
		return *this;
	}

	inline auto Stream::Front() const -> DiscriminatedSignal
	{
		return {this->CodeDisc_.front(), this->Code_.front()};
	}

	inline auto Stream::Back() const -> DiscriminatedSignal
	{
		return {this->CodeDisc_.back(), this->Code_.back()};
	}

	inline auto Stream::operator[](const std::size_t idx) const -> DiscriminatedSignal
	{
		return {this->CodeDisc_[idx], this->Code_[idx]};
	}

	inline auto Stream::IsEmpty() const -> bool
	{
		return this->Code_.empty() && this->CodeDisc_.empty();
	}

	inline auto Stream::GetCodeBuffer() const -> const CodeStorageType&
	{
		return this->Code_;
	}

	inline auto Stream::GetDiscriminatorBuffer() const -> const DiscriminatorStorageType&
	{
		return this->CodeDisc_;
	}

	inline auto Stream::Clear() -> void
	{
		this->Code_.clear();
		this->CodeDisc_.clear();
	}

	inline auto Stream::Resize(const std::size_t size) -> void
	{
		assert(this->Code_.size() == this->CodeDisc_.size());
		this->Code_.resize(size);
		this->CodeDisc_.resize(size);
	}

	inline auto Stream::Reserve(const std::size_t size) -> void
	{
		assert(this->Code_.size() == this->CodeDisc_.size());
		this->Code_.reserve(size);
		this->CodeDisc_.reserve(size);
	}

	inline auto Stream::Size() const -> std::size_t
	{
		assert(this->Code_.size() == this->CodeDisc_.size());
		return this->Code_.size();
	}

	inline auto Stream::SizeInBytes() const -> std::size_t
	{
		assert(this->Code_.size() == this->CodeDisc_.size());
		return
			this->Code_.size()
			* sizeof(Signal)
			+ this->CodeDisc_.size()
			* sizeof(Signal::Discriminator);
	}

	inline auto Stream::operator <<(const Instruction instr) -> Stream&
	{
		assert(this->Code_.size() == this->CodeDisc_.size());
		this->Code_.emplace_back(Signal {instr});
		this->CodeDisc_.emplace_back(Signal::Discriminator::Instruction);
		return *this;
	}

	inline auto Stream::operator <<(const SystemIntrinsicCallID intrin) -> Stream&
	{
		assert(this->Code_.size() == this->CodeDisc_.size());
		this->Code_.emplace_back(Signal {intrin});
		this->CodeDisc_.emplace_back(Signal::Discriminator::SystemIntrinsicCallID);
		return *this;
	}

	inline auto Stream::operator <<(const UserIntrinsicCallID intrin) -> Stream&
	{
		assert(this->Code_.size() == this->CodeDisc_.size());
		this->Code_.emplace_back(Signal {intrin});
		this->CodeDisc_.emplace_back(Signal::Discriminator::UserIntrinsicCallID);
		return *this;
	}

	inline auto Stream::operator<<(const JumpAddress address) -> Stream&
	{
		assert(this->Code_.size() == this->CodeDisc_.size());
		this->Code_.emplace_back(Signal {address});
		this->CodeDisc_.emplace_back(Signal::Discriminator::JumpAddress);
		return *this;
	}

	inline auto Stream::operator <<(const U64 value) -> Stream&
	{
		assert(this->Code_.size() == this->CodeDisc_.size());
		this->Code_.emplace_back(Signal {value});
		this->CodeDisc_.emplace_back(Signal::Discriminator::U64);
		return *this;
	}

	inline auto Stream::operator <<(const I64 value) -> Stream&
	{
		assert(this->Code_.size() == this->CodeDisc_.size());
		this->Code_.emplace_back(Signal {value});
		this->CodeDisc_.emplace_back(Signal::Discriminator::I64);
		return *this;
	}

	inline auto Stream::operator <<(const F64 value) -> Stream&
	{
		assert(this->Code_.size() == this->CodeDisc_.size());
		this->Code_.emplace_back(Signal {value});
		this->CodeDisc_.emplace_back(Signal::Discriminator::F64);
		return *this;
	}

	inline auto Stream::operator<<(const signed value) -> Stream&
	{
		return *this << static_cast<I64>(value);
	}

	inline auto Stream::operator <<(const CharClusterUtf8 value) -> Stream&
	{
		assert(this->Code_.size() == this->CodeDisc_.size());
		this->Code_.emplace_back(Signal {value});
		this->CodeDisc_.emplace_back(Signal::Discriminator::CharClusterUtf8);
		return *this;
	}

	inline auto Stream::operator<<(const CharClusterUtf16 value) -> Stream&
	{
		assert(this->Code_.size() == this->CodeDisc_.size());
		this->Code_.emplace_back(Signal {value});
		this->CodeDisc_.emplace_back(Signal::Discriminator::CharClusterUtf16);
		return *this;
	}

	inline auto Stream::operator<<(const CharClusterUtf32 value) -> Stream&
	{
		assert(this->Code_.size() == this->CodeDisc_.size());
		this->Code_.emplace_back(Signal {value});
		this->CodeDisc_.emplace_back(Signal::Discriminator::CharClusterUtf32);
		return *this;
	}

	/// <summary>
		/// Contains the boolean values for the jump map.
		/// We cannot use vector<bool> because it's a specialization
		/// and does not allow pointer to it's elements, because they are stored as bits.
		/// </summary>
	using JumpMap = std::vector<U8>;

	static_assert(sizeof(U8) == sizeof(bool));
	static_assert(alignof(U8) == alignof(bool));

	/// <summary>
	/// Builds a byte code image chunk and a jump map out of the stream.
	/// The memory for the chunk image is newly allocated which might be slower.
	/// If you execute a stream once, use TransformStreamMove.
	/// </summary>
	/// <param name="input"></param>
	/// <param name="output"></param>
	/// <param name="jumpMap"></param>
	extern auto TransformStreamToImageByCopy(const Stream& input, Image& output, JumpMap& jumpMap) -> void;

	/*
	 * Stop crying, we use macros instead of "constexpr char"
	 * here to use compile time string concatenation!
	 * It's not pretty and the best modern C++ way but simple and effective!
	 */

	/// <summary>
	/// Specify immediate constant operand.
	/// </summary>
	#define NOX_LEX_IMM "%"

	/// <summary>
	/// Begin byte code comment.
	/// </summary>
	#define NOX_LEX_COMMENT "#"

	/// <summary>
	///
	/// </summary>
	#define NOX_LEX_TYPE "*"

	/// <summary>
	///
	/// </summary>
	#define NOX_LEX_TYPE_U64 NOX_LEX_TYPE "u64"

	/// <summary>
	///
	/// </summary>
	#define NOX_LEX_TYPE_I64 NOX_LEX_TYPE "i64"

	/// <summary>
	///
	/// </summary>
	#define NOX_LEX_TYPE_F64 NOX_LEX_TYPE "f64"

	/// <summary>
	/// CharClusterUtf8 (1 byte)
	/// </summary>
	#define NOX_LEX_TYPE_CC1 NOX_LEX_TYPE "cc1"

	/// <summary>
	/// CharClusterUtf16 (2 byte)
	/// </summary>
	#define NOX_LEX_TYPE_CC2 NOX_LEX_TYPE "cc2"

	/// <summary>
	///CharClusterUtf32 (4 byte)
	/// </summary>
	#define NOX_LEX_TYPE_CC4 NOX_LEX_TYPE "cc4"

	/// <summary>
	/// System intrinsic call id.
	/// </summary>
	#define NOX_LEX_TYPE_SIC NOX_LEX_TYPE "sys"

	/// <summary>
	/// User intrinsic call id.
	/// </summary>
	#define NOX_LEX_TYPE_UIC NOX_LEX_TYPE "usr"

	/// <summary>
	/// Jump address.
	/// </summary>
	#define NOX_LEX_TYPE_JMP NOX_LEX_TYPE "jma"

	/// <summary>
	/// Single stack-bounded variable.
	/// When created it created a push instruction in the stream,
	/// when destroyed (RAII), a pop instruction is generated.
	/// </summary>
	template <typename T> requires StreamScalar<T>
	class ScopedVariable final
	{
		friend class Stream;

		/// <summary>
		/// Create a variable with specified value.
		/// </summary>
		/// <param name="attached"></param>
		/// <param name="value"></param>
		ScopedVariable(Stream& attached, T value);

		/// <summary>
		/// 
		/// </summary>
		/// <param name="value"></param>
		/// <returns></returns>
		auto Push(T value) -> ScopedVariable&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		auto DoNothing() -> ScopedVariable&;

		/// <summary>
		/// The attached stream instance.
		/// </summary>
		Stream& Attached_;

	public:
		/// <summary>
		/// No copy.
		/// </summary>
		/// <param name="other"></param>
		ScopedVariable(const ScopedVariable& other) = delete;

		/// <summary>
		/// No move.
		/// </summary>
		/// <param name="other"></param>
		ScopedVariable(ScopedVariable&& other) = delete;

		/// <summary>
		/// No copy.
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		auto operator =(const ScopedVariable& other) -> ScopedVariable& = delete;

		/// <summary>
		/// No move.
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		auto operator =(ScopedVariable&& other) -> ScopedVariable& = delete;

		/// <summary>
		/// Arithmetic addition.
		/// Implemented for all types.
		/// self += value
		/// </summary>
		/// <param name="value">The second operand.</param>
		/// <returns>self</returns>
		auto Add(T value) -> ScopedVariable&;

		/// <summary>
		/// Arithmetic addition.
		/// Implemented for all types.
		/// self += value
		/// </summary>
		/// <param name="value">The second operand.</param>
		/// <returns>self</returns>
		auto operator +=(T value) -> ScopedVariable&;

		/// <summary>
		/// Arithmetic subtraction.
		/// Implemented for all types.
		/// self -= value
		/// </summary>
		/// <param name="value">The second operand.</param>
		/// <returns>self</returns>
		auto Sub(T value) -> ScopedVariable&;

		/// <summary>
		/// Arithmetic subtraction.
		/// Implemented for all types.
		/// self -= value
		/// </summary>
		/// <param name="value">The second operand.</param>
		/// <returns>self</returns>
		auto operator -=(T value) -> ScopedVariable&;

		/// <summary>
		/// Arithmetic multiplication.
		/// Implemented for all types.
		/// self *= value
		/// </summary>
		/// <param name="value">The second operand.</param>
		/// <returns>self</returns>
		auto Mul(T value) -> ScopedVariable&;

		/// <summary>
		/// Arithmetic multiplication.
		/// Implemented for all types.
		/// self *= value
		/// </summary>
		/// <param name="value">The second operand.</param>
		/// <returns>self</returns>
		auto operator *=(T value) -> ScopedVariable&;

		/// <summary>
		/// Arithmetic division.
		/// Implemented for all types.
		/// self /= value
		/// </summary>
		/// <param name="value">The second operand.</param>
		/// <returns>self</returns>
		auto Div(T value) -> ScopedVariable&;

		/// <summary>
		/// Arithmetic division.
		/// Implemented for all types.
		/// self /= value
		/// </summary>
		/// <param name="value">The second operand.</param>
		/// <returns>self</returns>
		auto operator /=(T value) -> ScopedVariable&;

		/// <summary>
		/// Arithmetic modulo.
		/// Implemented for all types.
		/// self %= value
		/// </summary>
		/// <param name="value">The second operand.</param>
		/// <returns>self</returns>
		auto Mod(T value) -> ScopedVariable&;

		/// <summary>
		/// Arithmetic modulo.
		/// Implemented for all types.
		/// self %= value
		/// </summary>
		/// <param name="value">The second operand.</param>
		/// <returns>self</returns>
		auto operator %=(T value) -> ScopedVariable&;

		/// <summary>
		/// Bitwise &.
		/// Implemented for int and uint.
		/// self &= value
		/// </summary>
		/// <param name="value">The second operand.</param>
		/// <returns>self</returns>
		auto And(T value) -> ScopedVariable&;

		/// <summary>
		/// Bitwise &.
		/// Implemented for int and uint.
		/// self &= value
		/// </summary>
		/// <param name="value">The second operand.</param>
		/// <returns>self</returns>
		auto operator &=(T value) -> ScopedVariable&;

		/// <summary>
		/// Bitwise &.
		/// Implemented for int and uint.
		/// self |= value
		/// </summary>
		/// <param name="value">The second operand.</param>
		/// <returns>self</returns>
		auto Or(T value) -> ScopedVariable&;

		/// <summary>
		/// Bitwise &.
		/// Implemented for int and uint.
		/// self |= value
		/// </summary>
		/// <param name="value">The second operand.</param>
		/// <returns>self</returns>
		auto operator |=(T value) -> ScopedVariable&;

		/// <summary>
		/// Bitwise ^.
		/// Implemented for int and uint.
		/// self ^= value
		/// </summary>
		/// <param name="value">The second operand.</param>
		/// <returns>self</returns>
		auto Xor(T value) -> ScopedVariable&;

		/// <summary>
		/// Bitwise ^.
		/// Implemented for int and uint.
		/// self ^= value
		/// </summary>
		/// <param name="value">The second operand.</param>
		/// <returns>self</returns>
		auto operator ^=(T value) -> ScopedVariable&;

		/// <summary>
		/// Bitwise <<.
		/// Implemented for int and uint.
		/// self <<= value
		/// </summary>
		/// <param name="value">The second operand.</param>
		/// <returns>self</returns>
		auto ShiftLeft(T value) -> ScopedVariable&;

		/// <summary>
		/// Bitwise <<.
		/// Implemented for int and uint.
		/// self <<= value
		/// </summary>
		/// <param name="value">The second operand.</param>
		/// <returns>self</returns>
		auto operator <<=(T value) -> ScopedVariable&;

		/// <summary>
		/// Bitwise >>.
		/// Implemented for int and uint.
		/// self >>= value
		/// </summary>
		/// <param name="value">The second operand.</param>
		/// <returns>self</returns>
		auto ShiftRight(T value) -> ScopedVariable&;

		/// <summary>
		/// Bitwise >>.
		/// Implemented for int and uint.
		/// self >>= value
		/// </summary>
		/// <param name="value">The second operand.</param>
		/// <returns>self</returns>
		auto operator >>=(T value) -> ScopedVariable&;

		/// <summary>
		/// Bitwise <<<.
		/// Implemented for int and uint.
		/// self <<<= value
		/// </summary>
		/// <param name="value">The second operand.</param>
		/// <returns>self</returns>
		auto RotateLeft(T value) -> ScopedVariable&;

		/// <summary>
		/// Bitwise >>.
		/// Implemented for int and uint.
		/// self >>>= value
		/// </summary>
		/// <param name="value">The second operand.</param>
		/// <returns>self</returns>
		auto RotateRight(T value) -> ScopedVariable&;

		/// <summary>
		/// Pop variable from stack.
		/// </summary>
		~ScopedVariable();

		/// <summary>
		/// Returns the attached stream.
		/// </summary>
		/// <returns></returns>
		auto AttachedStream() const -> const Stream&;

		auto Unwrap() const -> T;
	};

	template <typename T> requires StreamScalar<T>
	inline auto ScopedVariable<T>::Unwrap() const -> T
	{
		#if NOX_DEBUG
				return this->Attached_.Back().template Unwrap<T>().value();
		#else
		return *this->Attached_.Back().template Unwrap<T>();
		#endif
	}

	template <typename T> requires StreamScalar<T>
	inline auto ScopedVariable<T>::AttachedStream() const -> const Stream&
	{
		return this->Attached_;
	}

	template <typename T> requires StreamScalar<T>
	inline auto ScopedVariable<T>::DoNothing() -> ScopedVariable&
	{
		if (this->Attached_.GetOptimizationLevel() == OptimizationLevel::Off)
		{
			// ReSharper disable once CppRedundantTemplateKeyword
			this->Attached_.template Do<Instruction::NOp>();
		}
		return *this;
	}

	template <>
	auto ScopedVariable<F64>::Push(F64 value) -> ScopedVariable&;

	template <>
	auto ScopedVariable<I64>::Push(I64 value) -> ScopedVariable&;

	template <>
	auto ScopedVariable<U64>::Push(U64 value) -> ScopedVariable&;

	template <>
	inline ScopedVariable<F64>::ScopedVariable(Stream& attached, const F64 value) : Attached_ {attached}
	{
		this->Push(value);
	}

	template <>
	inline ScopedVariable<I64>::ScopedVariable(Stream& attached, const I64 value) : Attached_ {attached}
	{
		this->Push(value);
	}

	template <>
	inline ScopedVariable<U64>::ScopedVariable(Stream& attached, const U64 value) : Attached_ {attached}
	{
		this->Push(value);
	}

	template <>
	auto ScopedVariable<F64>::Add(F64 value) -> ScopedVariable&;

	template <>
	auto ScopedVariable<I64>::Add(I64 value) -> ScopedVariable&;

	template <>
	auto ScopedVariable<U64>::Add(U64 value) -> ScopedVariable&;

	template <typename T> requires StreamScalar<T>
	inline auto ScopedVariable<T>::operator+=(const T value) -> ScopedVariable&
	{
		return this->Add(value);
	}

	template <>
	auto ScopedVariable<F64>::Sub(F64 value) -> ScopedVariable&;

	template <>
	auto ScopedVariable<I64>::Sub(I64 value) -> ScopedVariable&;

	template <>
	auto ScopedVariable<U64>::Sub(U64 value) -> ScopedVariable&;

	template <typename T> requires StreamScalar<T>
	inline auto ScopedVariable<T>::operator-=(const T value) -> ScopedVariable&
	{
		return this->Add(value);
	}

	template <>
	auto ScopedVariable<F64>::Mul(F64 value) -> ScopedVariable&;

	template <>
	auto ScopedVariable<I64>::Mul(I64 value) -> ScopedVariable&;

	template <>
	auto ScopedVariable<U64>::Mul(U64 value) -> ScopedVariable&;


	template <typename T> requires StreamScalar<T>
	inline auto ScopedVariable<T>::operator*=(const T value) -> ScopedVariable&
	{
		return this->Mul(value);
	}

	template <>
	auto ScopedVariable<F64>::Div(F64 value) -> ScopedVariable&;

	template <>
	auto ScopedVariable<I64>::Div(I64 value) -> ScopedVariable&;

	template <>
	auto ScopedVariable<U64>::Div(U64 value) -> ScopedVariable&;


	template <typename T> requires StreamScalar<T>
	inline auto ScopedVariable<T>::operator/=(const T value) -> ScopedVariable&
	{
		return this->Div(value);
	}

	template <>
	auto ScopedVariable<F64>::Mod(F64 value) -> ScopedVariable&;

	template <>
	auto ScopedVariable<I64>::Mod(I64 value) -> ScopedVariable&;

	template <>
	auto ScopedVariable<U64>::Mod(U64 value) -> ScopedVariable&;

	template <typename T> requires StreamScalar<T>
	inline auto ScopedVariable<T>::operator%=(const T value) -> ScopedVariable&
	{
		return this->Mod(value);
	}

	template <>
	auto ScopedVariable<I64>::And(I64 value) -> ScopedVariable&;

	template <>
	auto ScopedVariable<U64>::And(U64 value) -> ScopedVariable&;

	template <typename T> requires StreamScalar<T>
	inline auto ScopedVariable<T>::operator&=(const T value) -> ScopedVariable&
	{
		return this->And(value);
	}

	template <>
	auto ScopedVariable<I64>::Or(const I64 value) -> ScopedVariable&;

	template <>
	auto ScopedVariable<U64>::Or(const U64 value) -> ScopedVariable&;

	template <typename T> requires StreamScalar<T>
	inline auto ScopedVariable<T>::operator|=(const T value) -> ScopedVariable&
	{
		return this->Or(value);
	}

	template <>
	auto ScopedVariable<I64>::Xor(const I64 value) -> ScopedVariable&;

	template <>
	auto ScopedVariable<U64>::Xor(const U64 value) -> ScopedVariable&;

	template <typename T> requires StreamScalar<T>
	inline auto ScopedVariable<T>::operator^=(const T value) -> ScopedVariable&
	{
		return this->Xor(value);
	}

	template <>
	auto ScopedVariable<I64>::ShiftLeft(const I64 value) -> ScopedVariable&;

	template <>
	auto ScopedVariable<U64>::ShiftLeft(const U64 value) -> ScopedVariable&;

	template <typename T> requires StreamScalar<T>
	inline auto ScopedVariable<T>::operator<<=(const T value) -> ScopedVariable&
	{
		return this->ShiftLeft(value);
	}

	template <>
	auto ScopedVariable<I64>::ShiftRight(const I64 value) -> ScopedVariable&;

	template <>
	auto ScopedVariable<U64>::ShiftRight(const U64 value) -> ScopedVariable&;

	template <typename T> requires StreamScalar<T>
	inline auto ScopedVariable<T>::operator>>=(const T value) -> ScopedVariable&
	{
		return this->ShiftRight(value);
	}

	template <>
	auto ScopedVariable<I64>::RotateLeft(I64 value) -> ScopedVariable&;
	template <>
	auto ScopedVariable<U64>::RotateLeft(U64 value) -> ScopedVariable&;

	template <>
	auto ScopedVariable<I64>::RotateRight(I64 value) -> ScopedVariable&;

	template <>
	auto ScopedVariable<U64>::RotateRight(U64 value) -> ScopedVariable&;

	template <typename T> requires StreamScalar<T>
	inline ScopedVariable<T>::~ScopedVariable()
	{
		Attached_.Do<Instruction::Pop>();
	}

	/// <summary>
	/// Stream variable with runtime type: int
	/// </summary>
	using ScopedInt = ScopedVariable<I64>;

	/// <summary>
	/// Stream variable with runtime type: uint
	/// </summary>
	using ScopedUInt = ScopedVariable<U64>;

	/// <summary>
	/// Stream variable with runtime type: F32
	/// </summary>
	using ScopedF32 = ScopedVariable<F64>;

	/// <summary>
/// Validates a jump address. To be valid the jump address must be:
/// 1. Inside the range of the bucket addresses
/// 2. The target must be a instruction
/// </summary>
/// <param name="bucket"></param>
/// <param name="address"></param>
/// <returns></returns>
	[[nodiscard]]
	extern auto ValidateJumpAddress(const Stream& bucket, JumpAddress address) -> bool;

	/// <summary>
	/// Validates a system intrinsic call id. To be valid the call id must be:
	/// 1. Inside the range of the system intrinsic call ids
	/// </summary>
	/// <param name="id"></param>
	/// <returns></returns>
	[[nodiscard]]
	extern auto ValidateSystemIntrinsicCall(SystemIntrinsicCallID id) -> bool;

	/// <summary>
	/// Validates a user intrinsic call id. To be valid the call id must be:
	/// 1. Inside the range of the shared intrinsic table view.
	/// 2. Non null, but this is not checked here, because it's overkill to check it in each occurrence.
	/// </summary>
	/// <param name="routines"></param>
	/// <param name="id"></param>
	/// <returns></returns>
	[[nodiscard]]
	extern auto ValidateUserIntrinsicCall(const UserIntrinsicRoutineRegistry& routines, UserIntrinsicCallID id) -> bool;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="instruction"></param>
	/// <param name="args"></param>
	/// <returns></returns>
	[[nodiscard]]
	extern auto ValidateInstructionArguments(Instruction instruction, const std::span<const Signal::Discriminator>& args) -> ValidationResultCode;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="instruction"></param>
	/// <param name="args"></param>
	/// <returns></returns>
	[[nodiscard]]
	inline auto ValidateInstructionArguments(const Instruction instruction, std::vector<Signal::Discriminator>&& args) -> ValidationResultCode
	{
		return ValidateInstructionArguments(instruction, args);
	}

	/// <summary>
	/// Returns true if the iterator range begins with
	/// prologue code, else false.
	/// </summary>
	/// <typeparam name="Iterator"></typeparam>
	/// <param name="input"></param>
	/// <returns></returns>
	extern auto ContainsPrologue(const Stream& input) -> bool;

	/// <summary>
	/// Returns true if the iterator range end with
	/// epilogue code, else false.
	/// </summary>
	/// <typeparam name="Iterator"></typeparam>
	/// <param name="input"></param>
	/// <returns></returns>
	extern auto ContainsEpilogue(const Stream& input) -> bool;

	/// <summary>
	/// Compute offset of the instruction argument.
	/// </summary>
	/// <param name="where"></param>
	/// <param name="next"></param>
	/// <returns></returns>
	[[nodiscard]]
	constexpr auto ComputeInstructionArgumentOffset(const Signal::Discriminator* NOX_RESTRICT const where, const Signal::Discriminator* NOX_RESTRICT const next) -> std::ptrdiff_t
	{
		return next - where - 1;
	}

	/// <summary>
	/// 
	/// </summary>
	/// <param name="current"></param>
	/// <param name="end"></param>
	/// <returns></returns>
	[[nodiscard]]
	constexpr auto SearchForNextInstruction(const Signal::Discriminator* NOX_RESTRICT current, const Signal::Discriminator* NOX_RESTRICT const end) -> const Signal::Discriminator*
	{
		do
		{
			++current;
		}
		while (*current != Signal::Discriminator::Instruction && current < end);
		return current;
	}

	/// <summary>
	/// Extracts the arguments from an instruction into a span.
	/// !! Warning this can not be used on the last instruction,
	/// because it will determine the count by computing the pointer difference of two instructions.
	/// </summary>
	/// <param name="where">Pointer to instruction</param>
	/// <param name="offset"></param>
	/// <returns></returns>
	[[nodiscard]]
	constexpr auto ExtractInstructionArguments(const Signal::Discriminator* const where, const std::size_t offset) -> std::span<const Signal::Discriminator>
	{
		return {where + 1, where + 1 + offset};
	}

	/// <summary>
	/// Validates the whole code and returns the result.
	/// </summary>
	/// <param name="input">The stream to validate.</param>
	/// <param name="intrinsicRegistry"></param>
	/// <param name="outIndex"></param>
	/// <returns>Returns the validation result.</returns>
	[[nodiscard]]
	extern auto ValidateFullPass(const Stream& input, UserIntrinsicRoutineRegistry intrinsicRegistry = { }, U32* outIndex = nullptr) -> ValidationResultCode;
}
