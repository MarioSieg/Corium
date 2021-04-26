// File: ByteCode.cpp
// Author: Mario
// Created: 13.04.2021 6:10 PM
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

#include "TestBase.hpp"

TEST(BytecodeInstructionDB, MaximalImmediateArgumentCount)
{
	const auto max = INSTRUCTION_MAX_IMMEDIATE_ARGUMENTS;
	for (const auto val : INSTRUCTION_IMMEDIATE_ARGUMENT_COUNTS)
	{
		ASSERT_LE(val, max);
	}
}

TEST(BytecodeInstructionDB, ImmediateArgumentCount)
{
	ASSERT_EQ(INSTRUCTION_IMMEDIATE_ARGUMENT_COUNTS.size(), INSTRUCTION_IMMEDIATE_ARGUMENT_TYPES.size());
	for (std::size_t i = 0; i < INSTRUCTION_IMMEDIATE_ARGUMENT_COUNTS.size(); ++i)
	{
		std::uint8_t count = 0;
		for (const auto x : INSTRUCTION_IMMEDIATE_ARGUMENT_TYPES[i])
		{
			count += x != InstructionImmediateArgumentType::None;
		}
		ASSERT_EQ(count, INSTRUCTION_IMMEDIATE_ARGUMENT_COUNTS[i]);
	}
}

TEST(BytecodeDynamicSignal, InstructionData)
{
	const auto x = DynamicSignal {Instruction::CIntrin};
	ASSERT_TRUE(x.Contains<Instruction>());
	ASSERT_TRUE(x.Contains(Instruction::CIntrin));
}

TEST(BytecodeDynamicSignal, IntrinsicData)
{
	const auto x = DynamicSignal {SystemIntrinsicCallId::ATan2};
	ASSERT_TRUE(x.Contains<SystemIntrinsicCallId>());
	ASSERT_TRUE(x.Contains(SystemIntrinsicCallId::ATan2));
}

TEST(BytecodeDynamicSignal, CustomIntrinsicData)
{
	const auto x = DynamicSignal {CustomIntrinsicCallId {233113}};
	ASSERT_TRUE(x.Contains<CustomIntrinsicCallId>());
	ASSERT_TRUE(x.Contains(CustomIntrinsicCallId{233113}));
}

TEST(BytecodeDynamicSignal, U64Data)
{
	const auto x = DynamicSignal {UINT64_C(12345)};
	ASSERT_TRUE(x.Contains<std::uint64_t>());
	ASSERT_TRUE(x.Contains(UINT64_C(12345)));
}

TEST(BytecodeDynamicSignal, I64Data)
{
	const auto x = DynamicSignal {INT64_C(-12345)};
	ASSERT_TRUE(x.Contains<std::int64_t>());
	ASSERT_TRUE(x.Contains(INT64_C(-12345)));
}

TEST(BytecodeDynamicSignal, F64Data)
{
	const auto x = DynamicSignal {12345.0};
	ASSERT_TRUE(x.Contains<double>());
	ASSERT_TRUE(x.Contains(12345.0));
}

TEST(BytecodeDynamicSignal, C32Data)
{
	const auto x = DynamicSignal {static_cast<char32_t>('A')};
	ASSERT_TRUE(x.Contains<char32_t>());
	ASSERT_TRUE(x.Contains(static_cast<char32_t>('A')));
}

TEST(BytecodeDynamicSignal, DynamicSignalWithInstructionToSignal)
{
	const auto x = static_cast<Signal>(DynamicSignal {Instruction::CIntrin});
	ASSERT_EQ(x.Instr, Instruction::CIntrin);
}

TEST(BytecodeDynamicSignal, DynamicSignalWithIntrinsicToSignal)
{
	const auto x = static_cast<Signal>(DynamicSignal {SystemIntrinsicCallId::ATan2});
	ASSERT_EQ(x.SystemIntrinId, SystemIntrinsicCallId::ATan2);
}

TEST(BytecodeDynamicSignal, DynamicSignalWithCustomIntrinsicToSignal)
{
	const auto x = static_cast<Signal>(DynamicSignal {CustomIntrinsicCallId {4}});
	ASSERT_EQ(x.CustomIntrinId, CustomIntrinsicCallId{4});
}

TEST(BytecodeDynamicSignal, DynamicSignalWithU64ToSignal)
{
	const auto x = static_cast<Signal>(DynamicSignal {UINT64_C(0xFF'FF'FF'FF'FF'FF'FF'FF)});
	ASSERT_EQ(x.R64.U64, 0xFF'FF'FF'FF'FF'FF'FF'FF);
}

TEST(BytecodeDynamicSignal, DynamicSignalWithI64ToSignal)
{
	const auto x = static_cast<Signal>(DynamicSignal {INT64_C(-0x80'FF'FF'FF'FF'FF'FF'FF)});
	ASSERT_EQ(x.R64.I64, -0x80'FF'FF'FF'FF'FF'FF'FF);
}

TEST(BytecodeDynamicSignal, DynamicSignalWithF64ToSignal)
{
	const auto x = static_cast<Signal>(DynamicSignal {std::numeric_limits<double>::max()});
	ASSERT_EQ(x.R64.F64, std::numeric_limits<double>::max());
}

TEST(BytecodeDynamicSignal, DynamicSignalWithC32ToSignal)
{
	const auto x = static_cast<Signal>(DynamicSignal {static_cast<char32_t>('X')});
	ASSERT_EQ(x.R64.C32, 'X');
}

TEST(BytecodeValidationSingleInstruction, NoArguments)
{
	std::vector<DynamicSignal> args { };
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Int, args), ByteCodeValidationResult::NotEnoughArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Intrin, args), ByteCodeValidationResult::NotEnoughArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::CIntrin, args), ByteCodeValidationResult::NotEnoughArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Call, args), ByteCodeValidationResult::NotEnoughArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Ret, args), ByteCodeValidationResult::Ok);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Mov, args), ByteCodeValidationResult::NotEnoughArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Sto, args), ByteCodeValidationResult::NotEnoughArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Push, args), ByteCodeValidationResult::NotEnoughArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Pop, args), ByteCodeValidationResult::Ok);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Pop2, args), ByteCodeValidationResult::Ok);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Dupl, args), ByteCodeValidationResult::Ok);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Dupl2, args), ByteCodeValidationResult::Ok);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Swap, args), ByteCodeValidationResult::Ok);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::NOp, args), ByteCodeValidationResult::Ok);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Jmp, args), ByteCodeValidationResult::NotEnoughArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JmpRel, args), ByteCodeValidationResult::NotEnoughArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Jz, args), ByteCodeValidationResult::NotEnoughArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Jnz, args), ByteCodeValidationResult::NotEnoughArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JoCmpi, args), ByteCodeValidationResult::NotEnoughArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JoCmpf, args), ByteCodeValidationResult::NotEnoughArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JnoCmpi, args), ByteCodeValidationResult::NotEnoughArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JnoCmpf, args), ByteCodeValidationResult::NotEnoughArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JeCmpi, args), ByteCodeValidationResult::NotEnoughArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JeCmpf, args), ByteCodeValidationResult::NotEnoughArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JneCmpi, args), ByteCodeValidationResult::NotEnoughArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JneCmpf, args), ByteCodeValidationResult::NotEnoughArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JaCmpi, args), ByteCodeValidationResult::NotEnoughArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JaCmpf, args), ByteCodeValidationResult::NotEnoughArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JlCmpi, args), ByteCodeValidationResult::NotEnoughArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JlCmpf, args), ByteCodeValidationResult::NotEnoughArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JaeCmpi, args), ByteCodeValidationResult::NotEnoughArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JaeCmpf, args), ByteCodeValidationResult::NotEnoughArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JleCmpi, args), ByteCodeValidationResult::NotEnoughArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JleCmpf, args), ByteCodeValidationResult::NotEnoughArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::PushZ, args), ByteCodeValidationResult::Ok);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::IPushO, args), ByteCodeValidationResult::Ok);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::FPushO, args), ByteCodeValidationResult::Ok);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::IInc, args), ByteCodeValidationResult::Ok);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::IDec, args), ByteCodeValidationResult::Ok);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::IAdd, args), ByteCodeValidationResult::Ok);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::ISub, args), ByteCodeValidationResult::Ok);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::IMul, args), ByteCodeValidationResult::Ok);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::IDiv, args), ByteCodeValidationResult::Ok);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::IMod, args), ByteCodeValidationResult::Ok);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::IAnd, args), ByteCodeValidationResult::Ok);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::IOr, args), ByteCodeValidationResult::Ok);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::IXor, args), ByteCodeValidationResult::Ok);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::ICom, args), ByteCodeValidationResult::Ok);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::IRol, args), ByteCodeValidationResult::Ok);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::IRor, args), ByteCodeValidationResult::Ok);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::ISal, args), ByteCodeValidationResult::Ok);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::ISar, args), ByteCodeValidationResult::Ok);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::INeg, args), ByteCodeValidationResult::Ok);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::FAdd, args), ByteCodeValidationResult::Ok);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::FSub, args), ByteCodeValidationResult::Ok);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::FMul, args), ByteCodeValidationResult::Ok);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::FDiv, args), ByteCodeValidationResult::Ok);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::FMod, args), ByteCodeValidationResult::Ok);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::FNeg, args), ByteCodeValidationResult::Ok);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::FInc, args), ByteCodeValidationResult::Ok);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::FDec, args), ByteCodeValidationResult::Ok);
}

TEST(BytecodeValidationSingleInstruction, OneArgumentsI64)
{
	std::vector args
	{
		DynamicSignal {INT64_C(0)}
	};

	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Int, args), ByteCodeValidationResult::Ok);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Intrin, args), ByteCodeValidationResult::InvalidOperandType);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::CIntrin, args), ByteCodeValidationResult::InvalidOperandType);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Call, args), ByteCodeValidationResult::InvalidOperandType);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Ret, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Mov, args), ByteCodeValidationResult::NotEnoughArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Sto, args), ByteCodeValidationResult::NotEnoughArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Push, args), ByteCodeValidationResult::Ok);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Pop, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Pop2, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Dupl, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Dupl2, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Swap, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::NOp, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Jmp, args), ByteCodeValidationResult::InvalidOperandType);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JmpRel, args), ByteCodeValidationResult::InvalidOperandType);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Jz, args), ByteCodeValidationResult::InvalidOperandType);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Jnz, args), ByteCodeValidationResult::InvalidOperandType);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JoCmpi, args), ByteCodeValidationResult::InvalidOperandType);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JoCmpf, args), ByteCodeValidationResult::InvalidOperandType);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JnoCmpi, args), ByteCodeValidationResult::InvalidOperandType);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JnoCmpf, args), ByteCodeValidationResult::InvalidOperandType);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JeCmpi, args), ByteCodeValidationResult::InvalidOperandType);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JeCmpf, args), ByteCodeValidationResult::InvalidOperandType);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JneCmpi, args), ByteCodeValidationResult::InvalidOperandType);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JneCmpf, args), ByteCodeValidationResult::InvalidOperandType);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JaCmpi, args), ByteCodeValidationResult::InvalidOperandType);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JaCmpf, args), ByteCodeValidationResult::InvalidOperandType);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JlCmpi, args), ByteCodeValidationResult::InvalidOperandType);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JlCmpf, args), ByteCodeValidationResult::InvalidOperandType);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JaeCmpi, args), ByteCodeValidationResult::InvalidOperandType);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JaeCmpf, args), ByteCodeValidationResult::InvalidOperandType);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JleCmpi, args), ByteCodeValidationResult::InvalidOperandType);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JleCmpf, args), ByteCodeValidationResult::InvalidOperandType);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::PushZ, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::IPushO, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::FPushO, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::IInc, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::IDec, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::IAdd, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::ISub, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::IMul, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::IDiv, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::IMod, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::IAnd, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::IOr, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::IXor, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::ICom, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::IRol, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::IRor, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::ISal, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::ISar, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::INeg, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::FAdd, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::FSub, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::FMul, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::FDiv, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::FMod, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::FNeg, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::FInc, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::FDec, args), ByteCodeValidationResult::TooManyArguments);
}

TEST(BytecodeValidationSingleInstruction, TwoArgumentsI64)
{
	std::vector args
	{
		DynamicSignal {UINT64_C(0)},
		DynamicSignal {INT64_C(0)}
	};

	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Int, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Intrin, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::CIntrin, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Call, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Ret, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Mov, args), ByteCodeValidationResult::InvalidOperandType);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Sto, args), ByteCodeValidationResult::Ok);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Push, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Pop, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Pop2, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Dupl, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Dupl2, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Swap, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::NOp, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Jmp, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JmpRel, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Jz, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::Jnz, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JoCmpi, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JoCmpf, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JnoCmpi, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JnoCmpf, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JeCmpi, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JeCmpf, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JneCmpi, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JneCmpf, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JaCmpi, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JaCmpf, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JlCmpi, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JlCmpf, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JaeCmpi, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JaeCmpf, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JleCmpi, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::JleCmpf, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::PushZ, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::IPushO, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::FPushO, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::IInc, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::IDec, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::IAdd, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::ISub, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::IMul, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::IDiv, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::IMod, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::IAnd, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::IOr, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::IXor, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::ICom, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::IRol, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::IRor, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::ISal, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::ISar, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::INeg, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::FAdd, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::FSub, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::FMul, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::FDiv, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::FMod, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::FNeg, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::FInc, args), ByteCodeValidationResult::TooManyArguments);
	ASSERT_EQ(ByteCodeValidateSingleInstruction(Instruction::FDec, args), ByteCodeValidationResult::TooManyArguments);
}

TEST(BytecodeStream, Constructor)
{
	Stream stream { };
	ASSERT_EQ(stream.Capacity(), 8);
	ASSERT_EQ(stream.Size(), 1);
	ASSERT_EQ(stream.SizeInBytes(), sizeof(DynamicSignal));
	ASSERT_TRUE(stream[0].Contains(DynamicSignal::CodePrologue().Unwrap<Instruction>().value()));
	ASSERT_TRUE(stream.Buffer()[0].Contains(DynamicSignal::CodePrologue().Unwrap<Instruction>().value()));
}

TEST(BytecodeStream, ConstructorCapacity)
{
	Stream stream {128};
	ASSERT_EQ(stream.Capacity(), 128 + 3);
	ASSERT_EQ(stream.Size(), 1);
	ASSERT_EQ(stream.SizeInBytes(), sizeof(DynamicSignal));
	ASSERT_TRUE(stream[0].Contains(DynamicSignal::CodePrologue().Unwrap<Instruction>().value()));
	ASSERT_TRUE(stream.Buffer()[0].Contains(DynamicSignal::CodePrologue().Unwrap<Instruction>().value()));
}

TEST(BytecodeStream, Push)
{
	Stream stream { };
	ASSERT_EQ(stream.Size(), 1);

	stream.Push(DynamicSignal { });
	stream.Push(DynamicSignal {Instruction::NOp});
	stream << Instruction::Call;
	stream << SystemIntrinsicCallId::ACos;
	stream << CustomIntrinsicCallId {3};
	stream << 3.5;
	stream << UINT64_C(32);
	stream << INT64_C(-10);

	ASSERT_EQ(stream.Size(), 9);
	ASSERT_TRUE(stream[0].Contains(Instruction::NOp));
	ASSERT_TRUE(stream[1].Contains(UINT64_C(0)));
	ASSERT_TRUE(stream[2].Contains(Instruction::NOp));
	ASSERT_TRUE(stream[3].Contains(Instruction::Call));
	ASSERT_TRUE(stream[4].Contains(SystemIntrinsicCallId::ACos));
	ASSERT_TRUE(stream[5].Contains(CustomIntrinsicCallId{ 3 }));
	ASSERT_TRUE(stream[6].Contains(3.5));
	ASSERT_TRUE(stream[7].Contains(UINT64_C(32)));
	ASSERT_TRUE(stream[8].Contains(INT64_C(-10)));

	stream.Clear();
	ASSERT_EQ(stream.Size(), 1);
	ASSERT_TRUE(stream[0].Contains(Instruction::NOp));
}

TEST(ScopedVariable, StackPushPop)
{
	ASSERT_NE(OptLevel, OptimizationLevel::Off);
	Stream stream { };
	stream.With(4.5, [](auto&& var)
		{

		});
	ASSERT_EQ(stream.Size(), 4);
	ASSERT_TRUE(stream[0].Contains(Instruction::NOp));
	ASSERT_TRUE(stream[1].Contains(Instruction::Push));
	ASSERT_TRUE(stream[2].Contains(4.5));
	ASSERT_TRUE(stream[3].Contains(Instruction::Pop));
}

TEST(ScopedVariable, F64StackPushPopOptScalarZero)
{
	ASSERT_NE(OptLevel, OptimizationLevel::Off);
	Stream stream { };
	stream.With(0.0, [](auto&& var)
		{

		});
	ASSERT_EQ(stream.Size(), 3);
	ASSERT_TRUE(stream[0].Contains(Instruction::NOp));
	ASSERT_TRUE(stream[1].Contains(Instruction::PushZ));
	ASSERT_TRUE(stream[2].Contains(Instruction::Pop));
}

TEST(ScopedVariable, I64StackPushPopOptScalarZero)
{
	ASSERT_NE(OptLevel, OptimizationLevel::Off);
	Stream stream { };
	stream.With(0, [](auto&& var)
		{

		});
	ASSERT_EQ(stream.Size(), 3);
	ASSERT_TRUE(stream[0].Contains(Instruction::NOp));
	ASSERT_TRUE(stream[1].Contains(Instruction::PushZ));
	ASSERT_TRUE(stream[2].Contains(Instruction::Pop));
}

TEST(ScopedVariable, U64StackPushPopOptScalarZero)
{
	Stream stream { };
	stream.With(0, [](auto&& var)
		{

		});
	ASSERT_EQ(stream.Size(), 3);
	ASSERT_TRUE(stream[0].Contains(Instruction::NOp));
	ASSERT_TRUE(stream[1].Contains(Instruction::PushZ));
	ASSERT_TRUE(stream[2].Contains(Instruction::Pop));
}

TEST(ScopedVariable, F64StackPushPopOptScalarOne)
{
	ASSERT_NE(OptLevel, OptimizationLevel::Off);
	Stream stream { };
	stream.With(1.0, [](auto&& var)
		{

		});
	ASSERT_EQ(stream.Size(), 3);
	ASSERT_TRUE(stream[0].Contains(Instruction::NOp));
	ASSERT_TRUE(stream[1].Contains(Instruction::FPushO));
	ASSERT_TRUE(stream[2].Contains(Instruction::Pop));
}

TEST(ScopedVariable, I64StackPushPopOptScalarOne)
{
	ASSERT_NE(OptLevel, OptimizationLevel::Off);
	Stream stream { };
	stream.With(1, [](auto&& var)
		{

		});
	ASSERT_EQ(stream.Size(), 3);
	ASSERT_TRUE(stream[0].Contains(Instruction::NOp));
	ASSERT_TRUE(stream[1].Contains(Instruction::IPushO));
	ASSERT_TRUE(stream[2].Contains(Instruction::Pop));
}

TEST(ScopedVariable, U64StackPushPopOptScalarOne)
{
	ASSERT_NE(OptLevel, OptimizationLevel::Off);
	Stream stream { };
	stream.With(1, [](auto&& var)
		{

		});
	ASSERT_EQ(stream.Size(), 3);
	ASSERT_TRUE(stream[0].Contains(Instruction::NOp));
	ASSERT_TRUE(stream[1].Contains(Instruction::IPushO));
	ASSERT_TRUE(stream[2].Contains(Instruction::Pop));
}

TEST(ScopedVariable, F64StackPushPopOptScalarDupl)
{
	ASSERT_NE(OptLevel, OptimizationLevel::Off);
	Stream stream { };
	stream << 3.5;
	stream.With(3.5, [](auto&& var)
		{

		});
	ASSERT_EQ(stream.Size(), 4);
	ASSERT_TRUE(stream[0].Contains(Instruction::NOp));
	ASSERT_TRUE(stream[1].Contains(3.5));
	ASSERT_TRUE(stream[2].Contains(Instruction::Dupl));
	ASSERT_TRUE(stream[3].Contains(Instruction::Pop));
}

TEST(ScopedVariable, I64StackPushPopOptScalarDupl)
{
	ASSERT_NE(OptLevel, OptimizationLevel::Off);
	Stream stream { };
	stream << INT64_C(3);
	stream.With(3, [](auto&& var)
		{

		});
	ASSERT_EQ(stream.Size(), 4);
	ASSERT_TRUE(stream[0].Contains(Instruction::NOp));
	ASSERT_TRUE(stream[1].Contains<std::int64_t>(3));
	ASSERT_TRUE(stream[2].Contains(Instruction::Dupl));
	ASSERT_TRUE(stream[3].Contains(Instruction::Pop));
}

TEST(ScopedVariable, U64StackPushPopOptScalarDupl)
{
	ASSERT_NE(OptLevel, OptimizationLevel::Off);
	Stream stream { };
	stream << UINT64_C(3);
	stream.With(UINT64_C(3), [](auto&& var)
		{

		});
	ASSERT_EQ(stream.Size(), 4);
	ASSERT_TRUE(stream[0].Contains(Instruction::NOp));
	ASSERT_TRUE(stream[1].Contains<std::uint64_t>(3));
	ASSERT_TRUE(stream[2].Contains(Instruction::Dupl));
	ASSERT_TRUE(stream[3].Contains(Instruction::Pop));
}
