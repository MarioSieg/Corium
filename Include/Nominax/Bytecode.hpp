// File: ByteCode.hpp
// Author: Mario
// Created: 09.04.2021 17:11
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
#include <optional>
#include <string_view>
#include <span>
#include <variant>

#include "Record.hpp"

namespace Nominax
{
	/// <summary>
	/// Contains all byte code instructions with opcodes.
	/// </summary>
	enum class alignas(alignof(std::uint64_t)) Instruction : std::uint64_t
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

		/* !no instruction - count of total instructions! */
		Count
	};

	/// <summary>
	/// Call id for custom intrinsic routine.
	/// </summary>
	enum class alignas(alignof(std::uint64_t)) CustomIntrinsicCallId : std::uint64_t;

	/// <summary>
	/// Call id for system intrinsic routine.
	/// </summary>
	enum class alignas(alignof(std::uint64_t)) SystemIntrinsicCallId : std::uint64_t
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

		/* !no intrinsic routine - count of total intrinsic routines! */
		Count
	};

	/// <summary>
	/// Instruction category.
	/// </summary>
	enum class InstructionCategory : std::uint8_t
	{
		Control,
		Memory,
		Branching,
		Arithmetic,
		BitWise
	};

	/// <summary>
	/// All types of immediate arguments a instruction could have.
	/// </summary>
	enum class InstructionImmediateArgumentType : std::uint8_t
	{
		None,
		I64,
		F64,
		U64,
		I64OrU64,
		I64OrU64OrF64,
		RelativeJumpAddress64,
		AbsoluteJumpAddress64,
		SystemIntrinsicId,
		CustomIntrinsicId
	};

	/// <summary>
	/// Contains all instruction mnemonics.
	/// </summary>
	constexpr std::array<const std::string_view, static_cast<std::size_t>(Instruction::Count)> INSTRUCTION_MNEMONICS {
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
		"fdec"
	};

	/// <summary>
	/// Contains a short descripion for all instructions.
	/// </summary>
	constexpr std::array<const std::string_view, static_cast<std::size_t>(Instruction::Count)> INSTRUCTION_DESCRIPTIONS {
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
		"jump if one - compare as float",
		"jump if not one - compare as integer",
		"jump if not one - compare as  integer",
		"jump if equal as integer",
		"jump if equal - compare as floating point",
		"jump if not equal - compare  as integer",
		"jump if not equal - compare  as floating point",
		"jump if above - compare  as integer",
		"jump if above - compare  as floating point",
		"jump if less - compare as floating point",
		"jump if less - compare as floating point",
		"jump if above or equal - compare as integer",
		"jump if above or equal - compare as floating point",
		"jump if less or equal - compare as integer",
		"jump if less or equal - compare as floating point",
		"push zero as integer",
		"push one as  integer",
		"push one as floating point",
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
		"floating point decrement"
	};

	/// <summary>
	/// Contains the categories of all instructions.
	/// </summary>
	constexpr std::array INSTRUCTION_CATEGORIES {
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
		InstructionCategory::Arithmetic
	};

	/// <summary>
	/// Contains the amount of stack pushes each instruction will perform.
	/// </summary>
	constexpr std::array<std::uint8_t, static_cast<std::size_t>(Instruction::Count)> INSTRUCTION_PUSH_COUNTS {
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
		1
	};

	/// <summary>
	/// Contains the amount of stack pops each instruction will perform.
	/// </summary>
	constexpr std::array<std::uint8_t, static_cast<std::size_t>(Instruction::Count)> INSTRUCTION_POP_COUNTS {
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
		1
	};

	/// <summary>
	/// Contains the count of required immediate arguments for each instruction.
	/// </summary>
	constexpr std::array<std::uint8_t, static_cast<std::size_t>(Instruction::Count)> INSTRUCTION_IMMEDIATE_ARGUMENT_COUNTS {
		1,
		1,
		1,
		1,
		0,
		2,
		2,
		1,
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
		0
	};

	/// <summary>
	/// Defines the maximal amount of immediate arguments.
	/// </summary>
	constexpr std::size_t INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS {2};

	/// <summary>
	/// Contains all immediate argument types for each instruction.
	/// </summary>
	constexpr std::array INSTRUCTION_IMMEDIATE_ARGUMENT_TYPES {
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> {
			InstructionImmediateArgumentType::I64OrU64OrF64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> {
			InstructionImmediateArgumentType::SystemIntrinsicId
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> {
			InstructionImmediateArgumentType::CustomIntrinsicId
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> {
			InstructionImmediateArgumentType::I64OrU64OrF64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> {
			InstructionImmediateArgumentType::RelativeJumpAddress64, InstructionImmediateArgumentType::RelativeJumpAddress64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> {
			InstructionImmediateArgumentType::RelativeJumpAddress64, InstructionImmediateArgumentType::I64OrU64OrF64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> {
			InstructionImmediateArgumentType::I64OrU64OrF64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> {
			InstructionImmediateArgumentType::AbsoluteJumpAddress64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> {
			InstructionImmediateArgumentType::RelativeJumpAddress64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> {
			InstructionImmediateArgumentType::AbsoluteJumpAddress64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> {
			InstructionImmediateArgumentType::AbsoluteJumpAddress64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> {
			InstructionImmediateArgumentType::AbsoluteJumpAddress64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> {
			InstructionImmediateArgumentType::AbsoluteJumpAddress64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> {
			InstructionImmediateArgumentType::AbsoluteJumpAddress64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> {
			InstructionImmediateArgumentType::AbsoluteJumpAddress64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> {
			InstructionImmediateArgumentType::AbsoluteJumpAddress64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> {
			InstructionImmediateArgumentType::AbsoluteJumpAddress64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> {
			InstructionImmediateArgumentType::AbsoluteJumpAddress64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> {
			InstructionImmediateArgumentType::AbsoluteJumpAddress64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> {
			InstructionImmediateArgumentType::AbsoluteJumpAddress64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> {
			InstructionImmediateArgumentType::AbsoluteJumpAddress64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> {
			InstructionImmediateArgumentType::AbsoluteJumpAddress64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> {
			InstructionImmediateArgumentType::AbsoluteJumpAddress64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> {
			InstructionImmediateArgumentType::AbsoluteJumpAddress64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> {
			InstructionImmediateArgumentType::AbsoluteJumpAddress64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> {
			InstructionImmediateArgumentType::AbsoluteJumpAddress64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> {
			InstructionImmediateArgumentType::AbsoluteJumpAddress64
		},
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
		std::array<InstructionImmediateArgumentType, INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS> { },
	};

	/// <summary>
	/// 64-bit byte code signal data contains either an instruction or an immediate value.
	/// </summary>
	union alignas(alignof(std::uint64_t)) Signal
	{
		/// <summary>
		/// Reinterpret as Record64.
		/// </summary>
		Record64 R64;

		/// <summary>
		/// Reinterpret as instruction.
		/// </summary>
		Instruction Instr;

		/// <summary>
		/// Reinterpret as system intrinsic call id.
		/// </summary>
		SystemIntrinsicCallId SystemIntrinId;

		/// <summary>
		/// Reinterpret as custom intrinsic call id.
		/// </summary>
		CustomIntrinsicCallId CustomIntrinId;

		/// <summary>
		/// Reinterpret as 64-bit unsigned opcode. (For intrinsic calls and instructions).
		/// </summary>
		std::uint64_t OpCode;

		/// <summary>
		/// Reinterpret as void pointer.
		/// </summary>
		void* Ptr;

		/// <summary>
		/// Construct from record64.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr Signal(Record64 value) noexcept;

		/// <summary>
		/// Construct from instruction.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr Signal(Instruction value) noexcept;

		/// <summary>
		/// Construct from system intrinsic call id.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr Signal(SystemIntrinsicCallId value) noexcept;

		/// <summary>
		/// Construct from custom intrinsic call id.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr Signal(CustomIntrinsicCallId value) noexcept;

		/// <summary>
		/// Construct from void pointer.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr Signal(void* value) noexcept;

		/// <summary>
		/// Construct from 64-bit signed quadword integer.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr Signal(std::int64_t value) noexcept;

		/// <summary>
		/// Construct from 64-bit unsigned quadword integer.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr Signal(std::uint64_t value) noexcept;

		/// <summary>
		/// Construct from 64-bit double precision float.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr Signal(double value) noexcept;

		/// <summary>
		/// Construct from 32-bit UTF-32 character.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr Signal(char32_t value) noexcept;
	};

	constexpr Signal::Signal(const Record64 value) noexcept : R64 {value} {}
	constexpr Signal::Signal(const Instruction value) noexcept : Instr {value} {}
	constexpr Signal::Signal(const SystemIntrinsicCallId value) noexcept : SystemIntrinId {value} {}
	constexpr Signal::Signal(const CustomIntrinsicCallId value) noexcept : CustomIntrinId {value} {}
	constexpr Signal::Signal(void* const value) noexcept : Ptr {value} {}
	constexpr Signal::Signal(const std::int64_t value) noexcept : R64 {value} {}
	constexpr Signal::Signal(const std::uint64_t value) noexcept : R64 {value} {}
	constexpr Signal::Signal(const double value) noexcept : R64 {value} {}
	constexpr Signal::Signal(const char32_t value) noexcept : R64 {value} {}

	/// <summary>
	/// Create signal from unsigned 64-bit quadword.
	/// </summary>
	/// <param name="value">The value to convert from.</param>
	/// <returns>The signal containing the value.</returns>
	constexpr auto operator""_sig_u(const unsigned long long int value) noexcept -> Signal
	{
		return Signal {static_cast<std::uint64_t>(value)};
	}

	/// <summary>
	/// Create signal from signed 64-bit quadword.
	/// </summary>
	/// <param name="value">The value to convert from.</param>
	/// <returns>The signal containing the value.</returns>
	constexpr auto operator""_sig_i(const unsigned long long int value) noexcept -> Signal
	{
		return Signal {static_cast<std::int64_t>(value)};
	}

	/// <summary>
	/// Create signal from 64-bit double precision float.
	/// </summary>
	/// <param name="value">The value to convert from.</param>
	/// <returns>The signal containing the value.</returns>
	constexpr auto operator""_sig_f(const long double value) noexcept -> Signal
	{
		return Signal {static_cast<double>(value)};
	}

	/// <summary>
	/// Create signal from 32-bit UTF-32 character.
	/// </summary>
	/// <param name="value">The value to convert from.</param>
	/// <returns>The signal containing the value.</returns>
	constexpr auto operator""_sig_c(const unsigned long long int value) noexcept -> Signal
	{
		return Signal {static_cast<char32_t>(value)};
	}

	static_assert(std::is_same_v<std::underlying_type_t<Instruction>, std::uint64_t>);
	static_assert(sizeof(Instruction) == sizeof(std::uint64_t));
	static_assert(sizeof(Signal) == sizeof(std::uint64_t));
	static_assert(std::is_standard_layout_v<Signal>);

	/// <summary>
	/// Custom intrinsic routine function prototype.
	/// Contains the stack pointer as parameter.
	/// </summary>
	using IntrinsicRoutine = auto (Record64*) -> bool;
	static_assert(std::is_function_v<IntrinsicRoutine>);

	/// <summary>
	///  std::visit auto overload helper
	/// </summary>
	/// <typeparam name="...Ts">The call types.</typeparam>
	template <typename... Ts>
	struct Overloaded : Ts...
	{
		using Ts::operator()...;
	};

	template <typename... Ts>
	Overloaded(Ts&&...) -> Overloaded<Ts...>;

	/// <summary>
	/// Restricts to valid bytecode elements.
	/// </summary>
	/// <typeparam name="...Ts">The generic types to perform restriction checks on.</typeparam>
	template <typename... Ts>
	concept BytecodeElement = requires
	{
		requires (sizeof(Ts) + ... + 0) % sizeof(Record32) == 0 || (sizeof(Ts) + ... + 0) % sizeof(Record64) == 0;
		requires (alignof(Ts) + ... + 0) % alignof(Record32) == 0 || (alignof(Ts) + ... + 0) % alignof(Record64) == 0;
		requires
		std::is_same_v<Ts..., Instruction>
		|| std::is_same_v<Ts..., SystemIntrinsicCallId>
		|| std::is_same_v<Ts..., CustomIntrinsicCallId>
		|| std::is_same_v<Ts..., std::uint64_t>
		|| std::is_same_v<Ts..., std::int64_t>
		|| std::is_same_v<Ts..., double>
		|| std::is_same_v<Ts..., char32_t>;
	};

	/// <summary>
	/// Represents an entry in a byte code steam. This get's converted to a signal for execution.
	/// </summary>
	struct DynamicSignal final
	{
		/// <summary>
		/// Discriminated union.
		/// </summary>
		using Variant = std::variant<Instruction, SystemIntrinsicCallId, CustomIntrinsicCallId, std::uint64_t, std::int64_t, double, char32_t>;

		/// <summary>
		/// Construct from data union.
		/// </summary>
		/// <param name="data">The initial value.</param>
		/// <returns></returns>
		explicit constexpr DynamicSignal(Variant&& data) noexcept;

		/// <summary>
		/// Construct from instruction.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr DynamicSignal(Instruction value) noexcept;

		/// <summary>
		/// Construct from 64-bit unsigned quadword integer.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr DynamicSignal(std::uint64_t value) noexcept;

		/// <summary>
		/// Construct from 64-bit signed quadword integer.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr DynamicSignal(std::int64_t value) noexcept;

		/// <summary>
		/// Construct from 64-bit double precision float.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr DynamicSignal(double value) noexcept;

		/// <summary>
		/// Construct from 32-bit UTF32 character.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr DynamicSignal(char32_t value) noexcept;

		/// <summary>
		/// Construct from system intrinsic call id.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr DynamicSignal(SystemIntrinsicCallId value) noexcept;

		/// <summary>
		/// Construct from custom intrinsic call id.
		/// </summary>
		/// <param name="value">The initial value.</param>
		/// <returns></returns>
		explicit constexpr DynamicSignal(CustomIntrinsicCallId value) noexcept;

		/// <summary>
		/// Copy constructor.
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		constexpr DynamicSignal(const DynamicSignal&) noexcept = default;

		/// <summary>
		/// Move constructor.
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		constexpr DynamicSignal(DynamicSignal&&) noexcept = default;

		/// <summary>
		/// Copy assignment operator.
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		constexpr auto operator =(const DynamicSignal&) noexcept -> DynamicSignal& = default;

		/// <summary>
		/// Move assignment operator.
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		constexpr auto operator =(DynamicSignal&&) noexcept -> DynamicSignal& = default;

		/// <summary>
		/// Destructor.
		/// </summary>
		~DynamicSignal() = default;


		/// <summary>
		/// Convert to undiscriminated runtime signal.
		/// </summary>
		[[nodiscard]]
		explicit constexpr operator Signal() const;

		/// <summary>
		/// Try to extract raw data.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <returns></returns>
		template <typename T> requires BytecodeElement<T>
		[[nodiscard]]
		constexpr auto Unwrap() const -> std::optional<T>;

		/// <summary>
		/// Check if generic T is contained.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <returns></returns>
		template <typename T> requires BytecodeElement<T>
		[[nodiscard]]
		constexpr auto Contains() const noexcept -> bool;

		/// <summary>
		/// Chgeck if generic T and value is contained.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <param name="compareTo"></param>
		/// <returns></returns>
		template <typename T> requires BytecodeElement<T>
		[[nodiscard]]
		constexpr auto Contains(T&& compareTo) const -> bool;

		/// <summary>
		/// Raw data variant (discriminated union)
		/// </summary>
		Variant DataCollection { };
	};

	constexpr DynamicSignal::DynamicSignal(Variant&& data) noexcept : DataCollection {data} {}
	constexpr DynamicSignal::DynamicSignal(const Instruction value) noexcept : DataCollection {value} {}
	constexpr DynamicSignal::DynamicSignal(const std::uint64_t value) noexcept : DataCollection {value} {}
	constexpr DynamicSignal::DynamicSignal(const std::int64_t value) noexcept : DataCollection {value} {}
	constexpr DynamicSignal::DynamicSignal(const double value) noexcept : DataCollection {value} {}
	constexpr DynamicSignal::DynamicSignal(const char32_t value) noexcept : DataCollection {value} {}
	constexpr DynamicSignal::DynamicSignal(const SystemIntrinsicCallId value) noexcept : DataCollection {value} {}
	constexpr DynamicSignal::DynamicSignal(const CustomIntrinsicCallId value) noexcept : DataCollection {value} {}

	template <typename T> requires BytecodeElement<T>
	constexpr auto DynamicSignal::Unwrap() const -> std::optional<T>
	{
		return std::holds_alternative<T>(this->DataCollection)
			       ? std::optional<T> {std::get<T>(this->DataCollection)}
			       : std::nullopt;
	}

	template <typename T> requires BytecodeElement<T>
	constexpr auto DynamicSignal::Contains() const noexcept -> bool
	{
		return std::holds_alternative<T>(this->DataCollection);
	}

	template <typename T> requires BytecodeElement<T>
	constexpr auto DynamicSignal::Contains(T&& compareTo) const -> bool
	{
		return std::holds_alternative<T>(this->DataCollection) && std::get<T>(this->DataCollection) == compareTo;
	}

	constexpr DynamicSignal::operator Signal() const
	{
		return std::visit(Overloaded {
			                  [](const Instruction value) noexcept
			                  {
				                  return Signal {value};
			                  },
			                  [](const SystemIntrinsicCallId value) noexcept
			                  {
				                  return Signal {value};
			                  },
			                  [](const CustomIntrinsicCallId value) noexcept
			                  {
				                  return Signal {value};
			                  },
			                  [](const std::uint64_t value) noexcept
			                  {
				                  return Signal {value};
			                  },
			                  [](const std::int64_t value) noexcept
			                  {
				                  return Signal {value};
			                  },
			                  [](const double value) noexcept
			                  {
				                  return Signal {value};
			                  },
			                  [](const char32_t value) noexcept
			                  {
				                  return Signal {value};
			                  },
		                  }, this->DataCollection);
	}

	/// <summary>
	/// Creates an instruction mapping.
	/// </summary>
	/// <param name="input"></param>
	/// <param name="output"></param>
	/// <returns></returns>
	[[nodiscard]]
	extern auto CreateInstructionMapping(std::span<const DynamicSignal> input, std::span<bool>& output) -> bool;

	/// <summary>
	/// Contains all byte code validation results.
	/// </summary>
	enum class ByteCodeValidationResult
	{
		/// <summary>
		/// Validation did not found any problems.
		/// </summary>
		Ok = 0,

		/// <summary>
		/// An instruction requires more arguments, than given.
		/// </summary>
		NotEnoughArguments,

		/// <summary>
		/// An instruction requires less arguments, than given.
		/// </summary>
		TooManyArguments,

		/// <summary>
		/// The immediate argument type is not correct for the corresponding instruction.
		/// </summary>
		InvalidOperandType
	};

	/// <summary>
	/// Perform byte code validation on a single instruction.
	/// This just checks all argument types and values.
	/// </summary>
	/// <param name="instruction"></param>
	/// <param name="args"></param>
	/// <returns></returns>
	[[nodiscard]]
	extern auto ByteCodeValidateSingleInstruction(Instruction instruction, std::span<const DynamicSignal> args) -> ByteCodeValidationResult;
}
