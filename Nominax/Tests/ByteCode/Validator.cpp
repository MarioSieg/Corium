// File: Validator.cpp
// Author: Mario
// Created: 18.05.2021 1:49 PM
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

#include "../TestBase.hpp"

TEST(ValidatorAlgorithms, ValidateJumpAddressValid)
{
	const std::array bucket
	{
		DynamicSignal {Instruction::Dupl},
		DynamicSignal {2.2_float},
		DynamicSignal {-2_int},
		DynamicSignal {0xFF_uint},
		DynamicSignal {Instruction::FAdd},
		DynamicSignal {3_int}
	};

	ASSERT_TRUE(ValidateJumpAddress(bucket, JumpAddress{ 0 }));
	ASSERT_FALSE(ValidateJumpAddress(bucket, JumpAddress{ 1 }));
	ASSERT_FALSE(ValidateJumpAddress(bucket, JumpAddress{ 2 }));
	ASSERT_FALSE(ValidateJumpAddress(bucket, JumpAddress{ 3 }));
	ASSERT_TRUE(ValidateJumpAddress(bucket, JumpAddress{ 4 }));
	ASSERT_FALSE(ValidateJumpAddress(bucket, JumpAddress{ 5 }));
	ASSERT_FALSE(ValidateJumpAddress(bucket, JumpAddress{ 6 }));
	ASSERT_FALSE(ValidateJumpAddress(bucket, JumpAddress{ 7 }));
	ASSERT_FALSE(ValidateJumpAddress(bucket, JumpAddress{ 8 }));
}

TEST(ValidatorAlgorithms, ValidateSystemIntrinsicCall)
{
	ASSERT_TRUE(ValidateSystemIntrinsicCall(SystemIntrinsicCallID::ACos));
	ASSERT_TRUE(ValidateSystemIntrinsicCall(SystemIntrinsicCallID::IoPortWriteCluster));
	ASSERT_FALSE(ValidateSystemIntrinsicCall(SystemIntrinsicCallID::Count));
	ASSERT_FALSE(ValidateSystemIntrinsicCall(static_cast<SystemIntrinsicCallID>(-1)));
}

TEST(ValidatorAlgorithms, ValidateCustomIntrinsicCall)
{
	std::vector<IntrinsicRoutine*> proc
	{
		nullptr,
		nullptr
	};

	ASSERT_TRUE(ValidateUserIntrinsicCall(proc, CustomIntrinsicCallID{ 0 }));
	ASSERT_TRUE(ValidateUserIntrinsicCall(proc, CustomIntrinsicCallID{ 1 }));
	ASSERT_FALSE(ValidateUserIntrinsicCall(proc, CustomIntrinsicCallID{ 2 }));
	ASSERT_FALSE(ValidateUserIntrinsicCall(proc, CustomIntrinsicCallID{ 3 }));
}

TEST(ValidatorAlgorithms, ValidateInstructionArguments_Int)
{
	ASSERT_EQ(ValidateInstructionArguments(Instruction::Int, { DynamicSignal{3_int} }), ValidationResultCode::Ok);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::Int, { DynamicSignal{3.0_float} }), ValidationResultCode::ArgumentTypeMismatch);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::Int, { DynamicSignal{3_uint} }), ValidationResultCode::ArgumentTypeMismatch);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::Int, { DynamicSignal{3_int}, {} }), ValidationResultCode::TooManyArgumentsForInstruction);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::Int, { {} }), ValidationResultCode::ArgumentTypeMismatch);
}

TEST(ValidatorAlgorithms, ValidateInstructionArguments_Jmp)
{
	ASSERT_EQ(ValidateInstructionArguments(Instruction::Jmp, { DynamicSignal{JumpAddress{0}} }), ValidationResultCode::Ok);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::Jmp, { DynamicSignal{3.0_float} }), ValidationResultCode::ArgumentTypeMismatch);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::Jmp, { DynamicSignal{3_uint} }), ValidationResultCode::ArgumentTypeMismatch);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::Jmp, { DynamicSignal{3_int}, {} }), ValidationResultCode::TooManyArgumentsForInstruction);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::Jmp, { {} }), ValidationResultCode::ArgumentTypeMismatch);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::Jmp, std::vector<DynamicSignal>{}), ValidationResultCode::NotEnoughArgumentsForInstruction);
}

TEST(ValidatorAlgorithms, ValidateInstructionArguments_Intrin)
{
	ASSERT_EQ(ValidateInstructionArguments(Instruction::Intrin, { DynamicSignal{3_int} }), ValidationResultCode::ArgumentTypeMismatch);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::Intrin, { DynamicSignal{3.0_float} }), ValidationResultCode::ArgumentTypeMismatch);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::Intrin, { DynamicSignal{3_uint} }), ValidationResultCode::ArgumentTypeMismatch);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::Intrin, { DynamicSignal{3_int}, {} }), ValidationResultCode::TooManyArgumentsForInstruction);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::Intrin, { {} }), ValidationResultCode::ArgumentTypeMismatch);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::Intrin, { DynamicSignal{SystemIntrinsicCallID::ASin}, DynamicSignal{SystemIntrinsicCallID::ASin} }),
	          ValidationResultCode::TooManyArgumentsForInstruction);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::Intrin, { DynamicSignal{SystemIntrinsicCallID::ASin} }), ValidationResultCode::Ok);
}


TEST(ValidatorAlgorithms, ValidateInstructionArguments_CIntrin)
{
	ASSERT_EQ(ValidateInstructionArguments(Instruction::CIntrin, { DynamicSignal{3_int} }), ValidationResultCode::ArgumentTypeMismatch);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::CIntrin, { DynamicSignal{3.0_float} }), ValidationResultCode::ArgumentTypeMismatch);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::CIntrin, { DynamicSignal{3_uint} }), ValidationResultCode::ArgumentTypeMismatch);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::CIntrin, { DynamicSignal{3_int}, {} }), ValidationResultCode::TooManyArgumentsForInstruction);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::CIntrin, { {} }), ValidationResultCode::ArgumentTypeMismatch);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::CIntrin, { DynamicSignal{CustomIntrinsicCallID{3}}, DynamicSignal{CustomIntrinsicCallID{3}} }),
	          ValidationResultCode::TooManyArgumentsForInstruction);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::CIntrin, { DynamicSignal{CustomIntrinsicCallID{3}} }), ValidationResultCode::Ok);
}

TEST(ValidatorAlgorithms, ValidateInstructionArguments_None)
{
	ASSERT_EQ(ValidateInstructionArguments(Instruction::NOp, { {} }), ValidationResultCode::TooManyArgumentsForInstruction);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::NOp, { {}, {} }), ValidationResultCode::TooManyArgumentsForInstruction);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::NOp, { DynamicSignal{3_int} }), ValidationResultCode::TooManyArgumentsForInstruction);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::NOp, { DynamicSignal{3_uint} }), ValidationResultCode::TooManyArgumentsForInstruction);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::NOp, { DynamicSignal{ 3.0_float } }), ValidationResultCode::TooManyArgumentsForInstruction);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::NOp, std::vector<DynamicSignal>{}), ValidationResultCode::Ok);
}

TEST(ValidatorAlgorithms, ValidateInstructionArguments_Push_Combined)
{
	ASSERT_EQ(ValidateInstructionArguments(Instruction::Push, { {}, {} }), ValidationResultCode::TooManyArgumentsForInstruction);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::Push, std::vector<DynamicSignal>{}), ValidationResultCode::NotEnoughArgumentsForInstruction);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::Push, { DynamicSignal{3_int} }), ValidationResultCode::Ok);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::Push, { DynamicSignal{3_uint} }), ValidationResultCode::Ok);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::Push, { DynamicSignal{3.0_float} }), ValidationResultCode::Ok);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::Push, { DynamicSignal{SystemIntrinsicCallID::ASin} }), ValidationResultCode::ArgumentTypeMismatch);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::Push, { DynamicSignal{CustomIntrinsicCallID{3}} }), ValidationResultCode::ArgumentTypeMismatch);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::Push, { DynamicSignal{JumpAddress{2}} }), ValidationResultCode::ArgumentTypeMismatch);
}

TEST(ValidatorAlgorithms, ValidateInstructionArguments_Sto_Combined)
{
	ASSERT_EQ(ValidateInstructionArguments(Instruction::Sto, { {}, {} }), ValidationResultCode::Ok);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::Sto, std::vector<DynamicSignal>{}), ValidationResultCode::NotEnoughArgumentsForInstruction);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::Sto, { DynamicSignal{3_uint}, DynamicSignal{3_int} }), ValidationResultCode::Ok);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::Sto, { DynamicSignal{3_uint},DynamicSignal{3_uint} }), ValidationResultCode::Ok);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::Sto, { DynamicSignal{3_uint},DynamicSignal{3.0_float} }), ValidationResultCode::Ok);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::Sto, { DynamicSignal{3_int}, DynamicSignal{3_int} }), ValidationResultCode::ArgumentTypeMismatch);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::Sto, { DynamicSignal{3.0_float},DynamicSignal{3_uint} }), ValidationResultCode::ArgumentTypeMismatch);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::Sto, { DynamicSignal{3.0_float},DynamicSignal{3.0_float} }), ValidationResultCode::ArgumentTypeMismatch);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::Sto, { DynamicSignal{3_uint},DynamicSignal{SystemIntrinsicCallID::ASin} }), ValidationResultCode::ArgumentTypeMismatch);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::Sto, { DynamicSignal{3_uint},DynamicSignal{CustomIntrinsicCallID{3}} }), ValidationResultCode::ArgumentTypeMismatch);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::Sto, { DynamicSignal{3_uint},DynamicSignal{JumpAddress{2}} }), ValidationResultCode::ArgumentTypeMismatch);
}

TEST(ValidatorAlgorithms, ValidateInstructionArguments_Push)
{
	ASSERT_EQ(ValidateInstructionArguments(Instruction::VPush, std::vector<DynamicSignal>{}), ValidationResultCode::NotEnoughArgumentsForInstruction);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::VPush, { {} }), ValidationResultCode::NotEnoughArgumentsForInstruction);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::VPush, { {}, {} }), ValidationResultCode::NotEnoughArgumentsForInstruction);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::VPush, { {}, {}, {} }), ValidationResultCode::NotEnoughArgumentsForInstruction);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::VPush, { {}, {}, {}, {} }), ValidationResultCode::Ok);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::VPush, { {}, {}, {}, {}, {} }), ValidationResultCode::TooManyArgumentsForInstruction);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::VPush, { DynamicSignal{0_int}, DynamicSignal{1_int}, DynamicSignal{2_int}, DynamicSignal{3_int} }), ValidationResultCode::Ok);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::VPush, { DynamicSignal{0_uint}, DynamicSignal{1_uint}, DynamicSignal{2_uint}, DynamicSignal{3_uint} }), ValidationResultCode::Ok);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::VPush, { DynamicSignal{0.0_float}, DynamicSignal{1.0_float}, DynamicSignal{2.0_float}, DynamicSignal{3.0_float} }),
	          ValidationResultCode::Ok);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::VPush, { DynamicSignal{0.0_float}, DynamicSignal{1_uint}, DynamicSignal{2_int}, DynamicSignal{3.0_float} }), ValidationResultCode::Ok);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::VPush, { DynamicSignal{0.0_float}, DynamicSignal{1_uint}, DynamicSignal{2_int}, DynamicSignal{3.0_float}, DynamicSignal{1_uint} }),
	          ValidationResultCode::TooManyArgumentsForInstruction);
	ASSERT_EQ(ValidateInstructionArguments(Instruction::VPush, { DynamicSignal{0.0_float}, DynamicSignal{1_uint}, DynamicSignal{2_int}, DynamicSignal{3.0_float}, DynamicSignal{3.0_float} }),
	          ValidationResultCode::TooManyArgumentsForInstruction);
}

TEST(ValidatorAlgorithms, Pass0InstructionCacheGenerator)
{
	constexpr std::array code
	{
		DynamicSignal {Instruction::Push},
		DynamicSignal {4_int},
		DynamicSignal {Instruction::Push},
		DynamicSignal {2_int},
		DynamicSignal {Instruction::Sto},
		DynamicSignal {1_uint},
		DynamicSignal {-0.5_float},
		DynamicSignal {Instruction::IAdd},
		DynamicSignal {Instruction::Int},
		DynamicSignal {0_int}
	};

	InstructionCache cache { };
	ASSERT_EQ(ValidatePrePass(code, cache).first, ValidationResultCode::Ok);

	// Only 4 because the last instruction is removed and checked separately.
	ASSERT_EQ(cache.size(), 5);
	ASSERT_TRUE(code[cache[0]].Contains(Instruction::Push));
	ASSERT_TRUE(code[cache[1]].Contains(Instruction::Push));
	ASSERT_TRUE(code[cache[2]].Contains(Instruction::Sto));
	ASSERT_TRUE(code[cache[3]].Contains(Instruction::IAdd));
	ASSERT_TRUE(code[cache[4]].Contains(Instruction::Int));
}

TEST(ValidatorAlgorithms, ComputeInstructionArgumentOffset)
{
	constexpr std::array code
	{
		DynamicSignal {Instruction::Push},
		DynamicSignal {4_int},
		DynamicSignal {Instruction::Push},
		DynamicSignal {2_int},
		DynamicSignal {Instruction::Sto},
		DynamicSignal {1_uint},
		DynamicSignal {-0.5_float},
		DynamicSignal {Instruction::IAdd},
		DynamicSignal {Instruction::Int},
		DynamicSignal {0_int}
	};

	InstructionCache cache { };
	ASSERT_EQ(ValidatePrePass(code, cache).first, ValidationResultCode::Ok);
	ASSERT_EQ(cache.size(), 5);

	ASSERT_EQ(ComputeInstructionArgumentOffset(&code[cache[0]], &code[cache[1]]), 1);
	ASSERT_EQ(ComputeInstructionArgumentOffset(&code[cache[1]], &code[cache[2]]), 1);
	ASSERT_EQ(ComputeInstructionArgumentOffset(&code[cache[2]], &code[cache[3]]), 2);
	// Only 4 because the last instruction is removed and checked separately.
	//ASSERT_EQ(ComputeInstructionArgumentOffset(&cache[3]), 0);
}

TEST(ValidatorAlgorithms, ExtractInstructionArguments)
{
	constexpr std::array code
	{
		DynamicSignal {Instruction::Push},
		DynamicSignal {4_int},
		DynamicSignal {Instruction::Push},
		DynamicSignal {2_int},
		DynamicSignal {Instruction::Sto},
		DynamicSignal {1_uint},
		DynamicSignal {-0.5_float},
		DynamicSignal {Instruction::IAdd},
		DynamicSignal {Instruction::Int},
		DynamicSignal {0_int}
	};

	InstructionCache cache { };
	ASSERT_EQ(ValidatePrePass(code, cache).first, ValidationResultCode::Ok);
	ASSERT_EQ(cache.size(), 5);

	// push
	const auto r1 {ExtractInstructionArguments(&code[cache[0]], ComputeInstructionArgumentOffset(&code[cache[0]], &code[cache[1]]))};
	ASSERT_EQ(r1.size(), 1);
	ASSERT_TRUE(r1[0].Contains(4_int));

	// push
	const auto r2 {ExtractInstructionArguments(&code[cache[1]], ComputeInstructionArgumentOffset(&code[cache[1]], &code[cache[2]]))};
	ASSERT_EQ(r2.size(), 1);
	ASSERT_TRUE(r2[0].Contains(2_int));

	// sto
	const auto r3 {ExtractInstructionArguments(&code[cache[2]], ComputeInstructionArgumentOffset(&code[cache[2]], &code[cache[3]]))};
	ASSERT_EQ(r3.size(), 2);
	ASSERT_TRUE(r3[0].Contains(1_uint));
	ASSERT_TRUE(r3[1].Contains(-0.5_float));

	// iadd
	const auto r4 {ExtractInstructionArguments(&code[cache[3]], ComputeInstructionArgumentOffset(&code[cache[3]], &code[cache[4]]))};
	ASSERT_TRUE(r4.empty());

	// Only 4 because the last instruction is removed and checked separately. 
	// int
	/*
	const auto r5{ ExtractInstructionArguments(&cache[4]) };
	ASSERT_EQ(r5.size(), 1);
	ASSERT_TRUE(r5[0].Contains(0_int));
	*/
}

TEST(ValidatorAlgorithms, ValidateValid)
{
	constexpr std::array code
	{
		DynamicSignal {Instruction::Push},
		DynamicSignal {4_int},
		DynamicSignal {Instruction::Push},
		DynamicSignal {2_int},
		DynamicSignal {Instruction::Sto},
		DynamicSignal {1_uint},
		DynamicSignal {-0.5_float},
		DynamicSignal {Instruction::Jmp},
		DynamicSignal {JumpAddress {0}},
		DynamicSignal {Instruction::IAdd},
		DynamicSignal {Instruction::Int},
		DynamicSignal {0_int}
	};

	std::vector<DynamicSignal> stream { };
	stream.insert(std::begin(stream), std::begin(DynamicSignal::CodePrologue()), std::end(DynamicSignal::CodePrologue()));
	stream.insert(std::end(stream), std::begin(code), std::end(code));
	stream.insert(std::end(stream), std::begin(DynamicSignal::CodeEpilogue()), std::end(DynamicSignal::CodeEpilogue()));

	ASSERT_EQ(ValidateFullPass(stream).first, ValidationResultCode::Ok);
	ASSERT_EQ(ValidateFullPass(stream).second, 0);
}

TEST(ValidatorAlgorithms, ValidateInvalidTooManyArgs)
{
	constexpr std::array code
	{
		DynamicSignal {Instruction::Push},
		DynamicSignal {2_int},
		DynamicSignal {Instruction::Push},
		DynamicSignal {4_int},
		DynamicSignal {4_int}, // error
		DynamicSignal {Instruction::Push},
		DynamicSignal {2_int},
		DynamicSignal {Instruction::Sto},
		DynamicSignal {1_uint},
		DynamicSignal {-0.5_float},
		DynamicSignal {Instruction::IAdd},
		DynamicSignal {Instruction::Int},
		DynamicSignal {0_int}
	};

	std::vector<DynamicSignal> stream { };
	stream.insert(std::begin(stream), std::begin(DynamicSignal::CodePrologue()), std::end(DynamicSignal::CodePrologue()));
	stream.insert(std::end(stream), std::begin(code), std::end(code));
	stream.insert(std::end(stream), std::begin(DynamicSignal::CodeEpilogue()), std::end(DynamicSignal::CodeEpilogue()));

	ASSERT_EQ(ValidateFullPass(stream).first, ValidationResultCode::TooManyArgumentsForInstruction);
	ASSERT_EQ(ValidateFullPass(stream).second, 2);
}

TEST(ValidatorAlgorithms, ValidateInvalidNotEnoughArgs)
{
	constexpr std::array code
	{
		DynamicSignal {Instruction::Push},
		DynamicSignal {2_int},
		DynamicSignal {Instruction::Push},
		DynamicSignal {Instruction::Sto},
		DynamicSignal {1_uint},
		DynamicSignal {-0.5_float},
		DynamicSignal {Instruction::IAdd},
		DynamicSignal {Instruction::Int},
		DynamicSignal {0_int}
	};

	std::vector<DynamicSignal> stream { };
	stream.insert(std::begin(stream), std::begin(DynamicSignal::CodePrologue()), std::end(DynamicSignal::CodePrologue()));
	stream.insert(std::end(stream), std::begin(code), std::end(code));
	stream.insert(std::end(stream), std::begin(DynamicSignal::CodeEpilogue()), std::end(DynamicSignal::CodeEpilogue()));

	ASSERT_EQ(ValidateFullPass(stream).first, ValidationResultCode::NotEnoughArgumentsForInstruction);
	ASSERT_EQ(ValidateFullPass(stream).second, 2);
}

TEST(ValidatorAlgorithms, ValidateInvalidTypeMismatch)
{
	constexpr std::array code
	{
		DynamicSignal {Instruction::Push},
		DynamicSignal {2.0_float},
		DynamicSignal {Instruction::Sto},
		DynamicSignal {2.0_float},
		DynamicSignal {-0.5_float},
		DynamicSignal {Instruction::IAdd},
		DynamicSignal {Instruction::Int},
		DynamicSignal {0_int}
	};

	std::vector<DynamicSignal> stream { };
	stream.insert(std::begin(stream), std::begin(DynamicSignal::CodePrologue()), std::end(DynamicSignal::CodePrologue()));
	stream.insert(std::end(stream), std::begin(code), std::end(code));
	stream.insert(std::end(stream), std::begin(DynamicSignal::CodeEpilogue()), std::end(DynamicSignal::CodeEpilogue()));

	ASSERT_EQ(ValidateFullPass(stream).first, ValidationResultCode::ArgumentTypeMismatch);
	ASSERT_EQ(ValidateFullPass(stream).second, 2);
}

TEST(ValidatorAlgorithms, ValidateLastValid)
{
	constexpr std::array code
	{
		DynamicSignal {Instruction::NOp},
		DynamicSignal {Instruction::Jmp},
		DynamicSignal {JumpAddress {0}}
	};

	std::vector<DynamicSignal> stream { };
	stream.insert(std::begin(stream), std::begin(DynamicSignal::CodePrologue()), std::end(DynamicSignal::CodePrologue()));
	stream.insert(std::end(stream), std::begin(code), std::end(code));
	stream.insert(std::end(stream), std::begin(DynamicSignal::CodeEpilogue()), std::end(DynamicSignal::CodeEpilogue()));

	ASSERT_EQ(ValidateFullPass(stream).first, ValidationResultCode::Ok);
	ASSERT_EQ(ValidateFullPass(stream).second, 0);
}

TEST(ValidatorAlgorithms, ValidateLastInvalidMissingArgs)
{
	constexpr std::array code
	{
		DynamicSignal {Instruction::NOp},
		DynamicSignal {Instruction::Int},
	};

	std::vector<DynamicSignal> stream { };
	stream.insert(std::begin(stream), std::begin(DynamicSignal::CodePrologue()), std::end(DynamicSignal::CodePrologue()));
	stream.insert(std::end(stream), std::begin(code), std::end(code));
	stream.insert(std::end(stream), std::begin(DynamicSignal::CodeEpilogue()), std::end(DynamicSignal::CodeEpilogue()));

	ASSERT_EQ(ValidateFullPass(stream).first, ValidationResultCode::NotEnoughArgumentsForInstruction);
	ASSERT_EQ(ValidateFullPass(stream).second, 1);
}

TEST(ValidatorAlgorithms, ValidateLastInvalidTooManyArgs)
{
	constexpr std::array code
	{
		DynamicSignal {Instruction::NOp},
		DynamicSignal {Instruction::Int},
		DynamicSignal {0_int},
		DynamicSignal {0_int}
	};

	std::vector<DynamicSignal> stream { };
	stream.insert(std::begin(stream), std::begin(DynamicSignal::CodePrologue()), std::end(DynamicSignal::CodePrologue()));
	stream.insert(std::end(stream), std::begin(code), std::end(code));
	stream.insert(std::end(stream), std::begin(DynamicSignal::CodeEpilogue()), std::end(DynamicSignal::CodeEpilogue()));

	ASSERT_EQ(ValidateFullPass(stream).first, ValidationResultCode::TooManyArgumentsForInstruction);
	ASSERT_EQ(ValidateFullPass(stream).second, 1);
}

TEST(ValidatorAlgorithms, ValidateLastInvalidTypeMismatch)
{
	constexpr std::array code
	{
		DynamicSignal {Instruction::NOp},
		DynamicSignal {Instruction::Int},
		DynamicSignal {0.0_float}
	};

	std::vector<DynamicSignal> stream { };
	stream.insert(std::begin(stream), std::begin(DynamicSignal::CodePrologue()), std::end(DynamicSignal::CodePrologue()));
	stream.insert(std::end(stream), std::begin(code), std::end(code));
	stream.insert(std::end(stream), std::begin(DynamicSignal::CodeEpilogue()), std::end(DynamicSignal::CodeEpilogue()));

	ASSERT_EQ(ValidateFullPass(stream).first, ValidationResultCode::ArgumentTypeMismatch);
	ASSERT_EQ(ValidateFullPass(stream).second, 1);
}

TEST(ValidatorAlgorithms, ValidateLastPushInvalidMissingArgs)
{
	constexpr std::array code
	{
		DynamicSignal {Instruction::NOp},
		DynamicSignal {Instruction::Push},
	};

	std::vector<DynamicSignal> stream { };
	stream.insert(std::begin(stream), std::begin(DynamicSignal::CodePrologue()), std::end(DynamicSignal::CodePrologue()));
	stream.insert(std::end(stream), std::begin(code), std::end(code));
	stream.insert(std::end(stream), std::begin(DynamicSignal::CodeEpilogue()), std::end(DynamicSignal::CodeEpilogue()));

	ASSERT_EQ(ValidateFullPass(stream).first, ValidationResultCode::NotEnoughArgumentsForInstruction);
	ASSERT_EQ(ValidateFullPass(stream).second, 1);
}

TEST(ValidatorAlgorithms, ValidateLastPushInvalidTooManyArgs)
{
	constexpr std::array code
	{
		DynamicSignal {Instruction::NOp},
		DynamicSignal {Instruction::Push},
		DynamicSignal {0_int},
		DynamicSignal {0_int}
	};

	std::vector<DynamicSignal> stream { };
	stream.insert(std::begin(stream), std::begin(DynamicSignal::CodePrologue()), std::end(DynamicSignal::CodePrologue()));
	stream.insert(std::end(stream), std::begin(code), std::end(code));
	stream.insert(std::end(stream), std::begin(DynamicSignal::CodeEpilogue()), std::end(DynamicSignal::CodeEpilogue()));

	ASSERT_EQ(ValidateFullPass(stream).first, ValidationResultCode::TooManyArgumentsForInstruction);
	ASSERT_EQ(ValidateFullPass(stream).second, 1);
}

TEST(ValidatorAlgorithms, ValidateValidLastPushInt)
{
	constexpr std::array code
	{
		DynamicSignal {Instruction::NOp},
		DynamicSignal {Instruction::Push},
		DynamicSignal {0_int},
	};

	std::vector<DynamicSignal> stream { };
	stream.insert(std::begin(stream), std::begin(DynamicSignal::CodePrologue()), std::end(DynamicSignal::CodePrologue()));
	stream.insert(std::end(stream), std::begin(code), std::end(code));
	stream.insert(std::end(stream), std::begin(DynamicSignal::CodeEpilogue()), std::end(DynamicSignal::CodeEpilogue()));

	ASSERT_EQ(ValidateFullPass(stream).first, ValidationResultCode::Ok);
	ASSERT_EQ(ValidateFullPass(stream).second, 0);
}

TEST(ValidatorAlgorithms, ValidateValidLastPushUInt)
{
	constexpr std::array code
	{
		DynamicSignal {Instruction::NOp},
		DynamicSignal {Instruction::Dupl},
		DynamicSignal {Instruction::Push},
		DynamicSignal {0_uint},
	};

	std::vector<DynamicSignal> stream { };
	stream.insert(std::begin(stream), std::begin(DynamicSignal::CodePrologue()), std::end(DynamicSignal::CodePrologue()));
	stream.insert(std::end(stream), std::begin(code), std::end(code));
	stream.insert(std::end(stream), std::begin(DynamicSignal::CodeEpilogue()), std::end(DynamicSignal::CodeEpilogue()));

	ASSERT_EQ(ValidateFullPass(stream).first, ValidationResultCode::Ok);
	ASSERT_EQ(ValidateFullPass(stream).second, 0);
}

TEST(ValidatorAlgorithms, ValidateValidLastPushFloat)
{
	constexpr std::array code
	{
		DynamicSignal {Instruction::NOp},
		DynamicSignal {Instruction::Push},
		DynamicSignal {0.0_float},
	};

	std::vector<DynamicSignal> stream { };
	stream.insert(std::begin(stream), std::begin(DynamicSignal::CodePrologue()), std::end(DynamicSignal::CodePrologue()));
	stream.insert(std::end(stream), std::begin(code), std::end(code));
	stream.insert(std::end(stream), std::begin(DynamicSignal::CodeEpilogue()), std::end(DynamicSignal::CodeEpilogue()));

	ASSERT_EQ(ValidateFullPass(stream).first, ValidationResultCode::Ok);
	ASSERT_EQ(ValidateFullPass(stream).second, 0);
}

TEST(ValidatorAlgorithms, ValidateValidLastSto)
{
	constexpr std::array code
	{
		DynamicSignal {Instruction::NOp},
		DynamicSignal {Instruction::Sto},
		DynamicSignal {0_uint},
		DynamicSignal {0.0_float},
	};

	std::vector<DynamicSignal> stream { };
	stream.insert(std::begin(stream), std::begin(DynamicSignal::CodePrologue()), std::end(DynamicSignal::CodePrologue()));
	stream.insert(std::end(stream), std::begin(code), std::end(code));
	stream.insert(std::end(stream), std::begin(DynamicSignal::CodeEpilogue()), std::end(DynamicSignal::CodeEpilogue()));

	ASSERT_EQ(ValidateFullPass(stream).first, ValidationResultCode::Ok);
	ASSERT_EQ(ValidateFullPass(stream).second, 0);
}

TEST(ValidatorAlgorithms, ValidateInvalidLastStoNotEnoughArgs)
{
	constexpr std::array code
	{
		DynamicSignal {Instruction::NOp},
		DynamicSignal {Instruction::Sto},
		DynamicSignal {0_uint},
	};

	std::vector<DynamicSignal> stream { };
	stream.insert(std::begin(stream), std::begin(DynamicSignal::CodePrologue()), std::end(DynamicSignal::CodePrologue()));
	stream.insert(std::end(stream), std::begin(code), std::end(code));
	stream.insert(std::end(stream), std::begin(DynamicSignal::CodeEpilogue()), std::end(DynamicSignal::CodeEpilogue()));

	ASSERT_EQ(ValidateFullPass(stream).first, ValidationResultCode::NotEnoughArgumentsForInstruction);
	ASSERT_EQ(ValidateFullPass(stream).second, 1);
}

TEST(ValidatorAlgorithms, ValidateInvalidLastStoTooManyArgs)
{
	constexpr std::array code
	{
		DynamicSignal {Instruction::NOp},
		DynamicSignal {Instruction::Sto},
		DynamicSignal {0_uint},
		DynamicSignal {0_uint},
		DynamicSignal {0_uint},
	};

	std::vector<DynamicSignal> stream { };
	stream.insert(std::begin(stream), std::begin(DynamicSignal::CodePrologue()), std::end(DynamicSignal::CodePrologue()));
	stream.insert(std::end(stream), std::begin(code), std::end(code));
	stream.insert(std::end(stream), std::begin(DynamicSignal::CodeEpilogue()), std::end(DynamicSignal::CodeEpilogue()));

	ASSERT_EQ(ValidateFullPass(stream).first, ValidationResultCode::TooManyArgumentsForInstruction);
	ASSERT_EQ(ValidateFullPass(stream).second, 1);
}

TEST(ValidatorAlgorithms, ValidateInvalidLastMovTypeMismatch)
{
	constexpr std::array code
	{
		DynamicSignal {Instruction::NOp},
		DynamicSignal {Instruction::Mov},
		DynamicSignal {0_uint},
		DynamicSignal {0.0_float},
	};

	std::vector<DynamicSignal> stream { };
	stream.insert(std::begin(stream), std::begin(DynamicSignal::CodePrologue()), std::end(DynamicSignal::CodePrologue()));
	stream.insert(std::end(stream), std::begin(code), std::end(code));
	stream.insert(std::end(stream), std::begin(DynamicSignal::CodeEpilogue()), std::end(DynamicSignal::CodeEpilogue()));

	ASSERT_EQ(ValidateFullPass(stream).first, ValidationResultCode::ArgumentTypeMismatch);
	ASSERT_EQ(ValidateFullPass(stream).second, 1);
}

TEST(ValidatorAlgorithms, ValidateInvalidEmpty)
{
	constexpr std::array<const DynamicSignal, 0> code { };

	ASSERT_EQ(ValidateFullPass(code).first, ValidationResultCode::Empty);
}

TEST(ValidatorAlgorithms, ValidateInvalidMissingPrologue)
{
	constexpr std::array code
	{
		DynamicSignal {Instruction::Mov},
		DynamicSignal {0_uint},
		DynamicSignal {0_uint},
	};

	std::vector<DynamicSignal> stream { };
	stream.insert(std::begin(stream), std::begin(code), std::end(code));
	stream.insert(std::end(stream), std::begin(DynamicSignal::CodeEpilogue()), std::end(DynamicSignal::CodeEpilogue()));

	ASSERT_EQ(ValidateFullPass(stream).first, ValidationResultCode::MissingPrologueCode);
	ASSERT_EQ(ValidateFullPass(stream).second, 0);
}

TEST(ValidatorAlgorithms, ValidateInvalidMissingEpilogue)
{
	constexpr std::array code
	{
		DynamicSignal {Instruction::NOp},
	};

	std::vector<DynamicSignal> stream { };
	stream.insert(std::begin(stream), std::begin(DynamicSignal::CodePrologue()), std::end(DynamicSignal::CodePrologue()));
	stream.insert(std::end(stream), std::begin(code), std::end(code));

	ASSERT_EQ(ValidateFullPass(stream).first, ValidationResultCode::MissingEpilogueCode);
	ASSERT_EQ(ValidateFullPass(stream).second, 0);
}

TEST(ValidatorAlgorithms, ValidateInvalidMissingEpilogue2)
{
	constexpr std::array code
	{
		DynamicSignal {Instruction::NOp},
		DynamicSignal {Instruction::Int},
	};

	std::vector<DynamicSignal> stream { };
	stream.insert(std::begin(stream), std::begin(DynamicSignal::CodePrologue()), std::end(DynamicSignal::CodePrologue()));
	stream.insert(std::end(stream), std::begin(code), std::end(code));

	ASSERT_EQ(ValidateFullPass(stream).first, ValidationResultCode::MissingEpilogueCode);
	ASSERT_EQ(ValidateFullPass(stream).second, 0);
}


TEST(ValidatorAlgorithms, ValidateValidPass0JumpAddress)
{
	constexpr std::array code
	{
		DynamicSignal {Instruction::Push},
		DynamicSignal {4_int},
		DynamicSignal {Instruction::Jmp},
		DynamicSignal {JumpAddress {0}},
		DynamicSignal {Instruction::Jmp},
		DynamicSignal {JumpAddress {7}},
		DynamicSignal {Instruction::Jmp},
		DynamicSignal {JumpAddress {10}},
		DynamicSignal {Instruction::IAdd},
		DynamicSignal {Instruction::Int},
		DynamicSignal {0_int}
	};

	std::vector<DynamicSignal> stream { };
	stream.insert(std::begin(stream), std::begin(DynamicSignal::CodePrologue()), std::end(DynamicSignal::CodePrologue()));
	stream.insert(std::end(stream), std::begin(code), std::end(code));
	stream.insert(std::end(stream), std::begin(DynamicSignal::CodeEpilogue()), std::end(DynamicSignal::CodeEpilogue()));

	ASSERT_EQ(ValidateFullPass(stream).first, ValidationResultCode::Ok);
	ASSERT_EQ(ValidateFullPass(stream).second, 0);
}

TEST(ValidatorAlgorithms, ValidateInvalidPass0JumpAddressOutOfRange)
{
	constexpr std::array code
	{
		DynamicSignal {Instruction::Push},
		DynamicSignal {4_int},
		DynamicSignal {Instruction::Jmp},
		DynamicSignal {JumpAddress {0}},
		DynamicSignal {Instruction::Jmp},
		DynamicSignal {JumpAddress {7}},
		DynamicSignal {Instruction::Jmp},
		DynamicSignal {JumpAddress {100}},
		DynamicSignal {Instruction::IAdd},
		DynamicSignal {Instruction::Int},
		DynamicSignal {0_int}
	};

	std::vector<DynamicSignal> stream { };
	stream.insert(std::begin(stream), std::begin(DynamicSignal::CodePrologue()), std::end(DynamicSignal::CodePrologue()));
	stream.insert(std::end(stream), std::begin(code), std::end(code));
	stream.insert(std::end(stream), std::begin(DynamicSignal::CodeEpilogue()), std::end(DynamicSignal::CodeEpilogue()));

	ASSERT_EQ(ValidateFullPass(stream).first, ValidationResultCode::InvalidJumpAddress);
	ASSERT_EQ(ValidateFullPass(stream).second, 6);
}

TEST(ValidatorAlgorithms, ValidateInvalidPass0JumpAddressNoInstruction)
{
	constexpr std::array code
	{
		DynamicSignal {Instruction::Push},
		DynamicSignal {4_int},
		DynamicSignal {Instruction::Jmp},
		DynamicSignal {JumpAddress {DynamicSignal::CodePrologue().size() + 1}},
		DynamicSignal {Instruction::Sto},
		DynamicSignal {1_uint},
		DynamicSignal {-0.5_float},
		DynamicSignal {Instruction::IAdd},
		DynamicSignal {Instruction::Int},
		DynamicSignal {0_int}
	};

	std::vector<DynamicSignal> stream { };
	stream.insert(std::begin(stream), std::begin(DynamicSignal::CodePrologue()), std::end(DynamicSignal::CodePrologue()));
	stream.insert(std::end(stream), std::begin(code), std::end(code));
	stream.insert(std::end(stream), std::begin(DynamicSignal::CodeEpilogue()), std::end(DynamicSignal::CodeEpilogue()));

	ASSERT_EQ(ValidateFullPass(stream).first, ValidationResultCode::InvalidJumpAddress);
	ASSERT_EQ(ValidateFullPass(stream).second, 9);
}

TEST(ValidatorAlgorithms, ValidateInvalidPass0LastJumpAddressOutOfRange)
{
	constexpr std::array code
	{
		DynamicSignal {Instruction::Jmp},
		DynamicSignal {JumpAddress {100}},
	};

	std::vector<DynamicSignal> stream { };
	stream.insert(std::begin(stream), std::begin(DynamicSignal::CodePrologue()), std::end(DynamicSignal::CodePrologue()));
	stream.insert(std::end(stream), std::begin(code), std::end(code));
	stream.insert(std::end(stream), std::begin(DynamicSignal::CodeEpilogue()), std::end(DynamicSignal::CodeEpilogue()));

	ASSERT_EQ(ValidateFullPass(stream).first, ValidationResultCode::InvalidJumpAddress);
	ASSERT_EQ(ValidateFullPass(stream).second, 3);
}

TEST(ValidatorAlgorithms, ValidateInvalidPass0LastJumpAddressNoInstruction)
{
	constexpr std::array code
	{
		DynamicSignal {Instruction::Jmp},
		DynamicSignal {JumpAddress {DynamicSignal::CodePrologue().size() + 1}},
	};

	std::vector<DynamicSignal> stream { };
	stream.insert(std::begin(stream), std::begin(DynamicSignal::CodePrologue()), std::end(DynamicSignal::CodePrologue()));
	stream.insert(std::end(stream), std::begin(code), std::end(code));
	stream.insert(std::end(stream), std::begin(DynamicSignal::CodeEpilogue()), std::end(DynamicSignal::CodeEpilogue()));

	ASSERT_EQ(ValidateFullPass(stream).first, ValidationResultCode::InvalidJumpAddress);
	ASSERT_EQ(ValidateFullPass(stream).second, 3);
}
