// File: ReactorExecution.cpp
// Author: Mario
// Created: 09.04.2021 5:11 PM
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

#include "ReactorTestHelper.hpp"

TEST(ReactorExecution, Instruction_Int)
{
	std::array code = {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Int},
		Signal {INT64_C(5)},
		Signal {Instruction::Int},
		Signal {INT64_C(-12345)},
	};

	auto input {MOCK_REACTOR_INPUT};

	static constinit InterruptAccumulator accumulator;
	static constinit int                  calls;

	input.InterruptHandler = +[](const InterruptAccumulator x) noexcept(true) -> void
	{
		accumulator = x;
		++calls;
	};

	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(calls, 2);
	ASSERT_EQ(accumulator, -12345);
	ASSERT_EQ(o.InterruptCode, -12345);
	ASSERT_EQ(o.IpDiff, code.size() - 1);
}

TEST(ReactorExecution, Instruction_Mov)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Sto},
		Signal {UINT64_C(3)},
		Signal {3.1415},
		Signal {Instruction::Mov},
		Signal {UINT64_C(8)},
		Signal {UINT64_C(3)},
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[3].AsF64, 3.1415);
	ASSERT_EQ(o.Input->Stack[8].AsF64, 3.1415);
}

TEST(ReactorExecution, Instruction_Sto)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Sto},
		Signal {UINT64_C(1)},
		Signal {INT64_C(5657334)},
		Signal {Instruction::Sto},
		Signal {UINT64_C(31)},
		Signal {3.1415},
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsI64, 5657334);
	ASSERT_EQ(o.Input->Stack[31].AsF64, 3.1415);
}

TEST(ReactorExecution, Instruction_Push)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Push},
		Signal {INT64_C(1224)},
		Signal {Instruction::Push},
		Signal {-0.6666},
		Signal {Instruction::Int},
		Signal {INT64_C(-3)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsI64, 1224);
	ASSERT_EQ(o.Input->Stack[2].AsF64, -0.6666);
}

TEST(ReactorExecution, Instruction_Pop)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Push},
		Signal {INT64_C(1224)},
		Signal {Instruction::Push},
		Signal {-0.6666},
		Signal {Instruction::Pop},
		Signal {Instruction::Pop},
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsI64, 1224);
	ASSERT_EQ(o.Input->Stack[2].AsF64, -0.6666);
	ASSERT_EQ(o.SpDiff, 0);

	code[6].Instr = Instruction::NOp;
	o             = ExecuteOnce(input);
	ASSERT_EQ(o.Input->Stack[1].AsI64, 1224);
	ASSERT_EQ(o.Input->Stack[2].AsF64, -0.6666);
	ASSERT_EQ(o.SpDiff, 1);
}

TEST(ReactorExecution, Instruction_Pop2)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Push},
		Signal {UINT64_C(1224)},
		Signal {Instruction::Push},
		Signal {-0.6666},
		Signal {Instruction::Pop2},
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsI64, 1224);
	ASSERT_EQ(o.Input->Stack[2].AsF64, -0.6666);
	ASSERT_EQ(o.SpDiff, 0);
}

TEST(ReactorExecution, Instruction_Dupl)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Push},
		Signal {INT64_C(5)},
		Signal {Instruction::Dupl},
		Signal {Instruction::Push},
		Signal {INT64_C(-2)},
		Signal {Instruction::Dupl},
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsI64, 5);
	ASSERT_EQ(o.Input->Stack[2].AsI64, 5);
	ASSERT_EQ(o.Input->Stack[3].AsI64, -2);
	ASSERT_EQ(o.Input->Stack[4].AsI64, -2);
}

TEST(ReactorExecution, Instruction_Swap)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Push},
		Signal {INT64_C(3)},
		Signal {Instruction::Push},
		Signal {INT64_C(-666)},
		Signal {Instruction::Swap},
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsI64, -666);
	ASSERT_EQ(o.Input->Stack[2].AsI64, 3);
	ASSERT_EQ(o.SpDiff, 2);
}

TEST(ReactorExecution, Instruction_Dupl2)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Push},
		Signal {INT64_C(5)},
		Signal {Instruction::Dupl2},
		Signal {Instruction::Push},
		Signal {INT64_C(0xFF)},
		Signal {Instruction::Dupl2},
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsI64, 5);
	ASSERT_EQ(o.Input->Stack[2].AsI64, 5);
	ASSERT_EQ(o.Input->Stack[3].AsI64, 5);
	ASSERT_EQ(o.Input->Stack[4].AsI64, 0xFF);
	ASSERT_EQ(o.Input->Stack[5].AsI64, 0xFF);
	ASSERT_EQ(o.Input->Stack[6].AsI64, 0xFF);
}

TEST(ReactorExecution, Instruction_IInc)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Push},
		Signal {INT64_C(0)},
		Signal {Instruction::IInc},
		Signal {Instruction::IInc},
		Signal {Instruction::IInc},
		Signal {Instruction::IInc},
		Signal {Instruction::IInc},
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[0], Record::Padding());
	ASSERT_EQ(o.Input->Stack[1].AsI64, 5);
	ASSERT_EQ(o.SpDiff, 1);
}

TEST(ReactorExecution, Instruction_IDec)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Push},
		Signal {INT64_C(2)},
		Signal {Instruction::IDec},
		Signal {Instruction::IDec},
		Signal {Instruction::IDec},
		Signal {Instruction::IDec},
		Signal {Instruction::IDec},
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);
	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[0], Record::Padding());
	ASSERT_EQ(o.Input->Stack[1].AsI64, -3);
	ASSERT_EQ(o.SpDiff, 1);
}

TEST(ReactorExecution, Instruction_PushZ)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::PushZ},
		Signal {Instruction::PushZ},
		Signal {Instruction::PushZ},
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsI64, 0);
	ASSERT_EQ(o.Input->Stack[2].AsU64, 0);
	ASSERT_EQ(o.Input->Stack[3].AsF64, 0.0F);
}

TEST(ReactorExecution, Instruction_IPushO)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::IPushO},
		Signal {Instruction::PushZ},
		Signal {Instruction::IPushO},
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsI64, 1);
	ASSERT_EQ(o.Input->Stack[2].AsU64, 0);
	ASSERT_EQ(o.Input->Stack[3].AsU64, 1);
}

TEST(ReactorExecution, Instruction_IAdd)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Push},
		Signal {INT64_C(2)},
		Signal {Instruction::Push},
		Signal {INT64_C(5)},
		Signal {Instruction::IAdd},
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsI64, 2 + 5);
	ASSERT_EQ(o.Input->Stack[2].AsU64, 5);
	ASSERT_EQ(o.SpDiff, 1);
}

TEST(ReactorExecution, Instruction_ISub)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Push},
		Signal {INT64_C(2)},
		Signal {Instruction::Push},
		Signal {INT64_C(5)},
		Signal {Instruction::ISub},
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsI64, 2 - 5);
	ASSERT_EQ(o.Input->Stack[2].AsU64, 5);
	ASSERT_EQ(o.SpDiff, 1);
}

TEST(ReactorExecution, Instruction_IMul)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Push},
		Signal {INT64_C(2)},
		Signal {Instruction::Push},
		Signal {INT64_C(5)},
		Signal {Instruction::IMul},
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsI64, 2 * 5);
	ASSERT_EQ(o.Input->Stack[2].AsU64, 5);
	ASSERT_EQ(o.SpDiff, 1);
}

TEST(ReactorExecution, Instruction_IDiv)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Push},
		Signal {INT64_C(10)},
		Signal {Instruction::Push},
		Signal {INT64_C(5)},
		Signal {Instruction::IDiv},
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsI64, 10 / 5);
	ASSERT_EQ(o.Input->Stack[2].AsU64, 5);
	ASSERT_EQ(o.SpDiff, 1);
}

TEST(ReactorExecution, Instruction_IMod)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Push},
		Signal {INT64_C(10)},
		Signal {Instruction::Push},
		Signal {INT64_C(5)},
		Signal {Instruction::IMod},
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsI64, 10 % 5);
	ASSERT_EQ(o.Input->Stack[2].AsU64, 5);
	ASSERT_EQ(o.SpDiff, 1);
}

TEST(ReactorExecution, Instruction_IAnd)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Push},
		Signal {INT64_C(0b1101'1101)},
		Signal {Instruction::Push},
		Signal {INT64_C(0b0111'0111)},
		Signal {Instruction::IAnd},
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsI64, 0b1101'1101 & 0b0111'0111);
	ASSERT_EQ(o.Input->Stack[2].AsU64, 0b0111'0111);
	ASSERT_EQ(o.SpDiff, 1);
}

TEST(ReactorExecution, Instruction_IOr)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Push},
		Signal {INT64_C(0b1101'1101)},
		Signal {Instruction::Push},
		Signal {INT64_C(0b0111'0111)},
		Signal {Instruction::IOr},
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsI64, 0b1101'1101 | 0b0111'0111);
	ASSERT_EQ(o.Input->Stack[2].AsU64, 0b0111'0111);
	ASSERT_EQ(o.SpDiff, 1);
}

TEST(ReactorExecution, Instruction_IXor)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Push},
		Signal {INT64_C(0b1101'1101)},
		Signal {Instruction::Push},
		Signal {INT64_C(0b0111'0111)},
		Signal {Instruction::IXor},
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsI64, 0b1101'1101 ^ 0b0111'0111);
	ASSERT_EQ(o.Input->Stack[2].AsU64, 0b0111'0111);
	ASSERT_EQ(o.SpDiff, 1);
}

TEST(ReactorExecution, Instruction_ICom)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Push},
		Signal {INT64_C(0b1101'1101)},
		Signal {Instruction::ICom},
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsI64, ~0b1101'1101);
	ASSERT_EQ(o.SpDiff, 1);
}

TEST(ReactorExecution, Instruction_ISal)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Push},
		Signal {INT64_C(1)},
		Signal {Instruction::Push},
		Signal {INT64_C(2)},
		Signal {Instruction::ISal},
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsI64, 1 << 2);
	ASSERT_EQ(o.Input->Stack[2].AsU64, 2);
	ASSERT_EQ(o.SpDiff, 1);
}

TEST(ReactorExecution, Instruction_ISar)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Push},
		Signal {INT64_C(1)},
		Signal {Instruction::Push},
		Signal {INT64_C(2)},
		Signal {Instruction::ISar},
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsI64, 1 >> 2);
	ASSERT_EQ(o.Input->Stack[2].AsU64, 2);
	ASSERT_EQ(o.SpDiff, 1);
}

TEST(ReactorExecution, Instruction_IRol)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Push},
		Signal {INT64_C(1)},
		Signal {Instruction::Push},
		Signal {INT64_C(2)},
		Signal {Instruction::IRol},
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsU64, std::rotl<U64>(1, 2));
	ASSERT_EQ(o.Input->Stack[2].AsU64, 2);
	ASSERT_EQ(o.SpDiff, 1);
}

TEST(ReactorExecution, Instruction_IRor)
{
	std::array code = {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Push},
		Signal {INT64_C(1)},
		Signal {Instruction::Push},
		Signal {INT64_C(2)},
		Signal {Instruction::IRor},
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsU64, std::rotr<U64>(1, 2));
	ASSERT_EQ(o.Input->Stack[2].AsU64, 2);
	ASSERT_EQ(o.SpDiff, 1);
}

TEST(ReactorExecution, Instruction_INeg)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Push},
		Signal {INT64_C(10)},
		Signal {Instruction::INeg},
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsI64, -10);
	ASSERT_EQ(o.SpDiff, 1);
}

TEST(ReactorExecution, Instruction_FAdd)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Push},
		Signal {4.25},
		Signal {Instruction::Push},
		Signal {2.50},
		Signal {Instruction::FAdd},
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_DOUBLE_EQ(o.Input->Stack[1].AsF64, 6.75);
	ASSERT_DOUBLE_EQ(o.Input->Stack[2].AsF64, 2.50);
	ASSERT_EQ(o.SpDiff, 1);
}

TEST(ReactorExecution, Instruction_FMod)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Push},
		Signal {4.25},
		Signal {Instruction::Push},
		Signal {2.50},
		Signal {Instruction::FMod},
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_DOUBLE_EQ(o.Input->Stack[1].AsF64, std::fmod(4.25, 2.50));
	ASSERT_DOUBLE_EQ(o.Input->Stack[2].AsF64, 2.50);
	ASSERT_EQ(o.SpDiff, 1);
}

TEST(ReactorExecution, Instruction_FSub)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Push},
		Signal {4.25},
		Signal {Instruction::Push},
		Signal {2.50},
		Signal {Instruction::FSub},
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_DOUBLE_EQ(o.Input->Stack[1].AsF64, 1.75);
	ASSERT_DOUBLE_EQ(o.Input->Stack[2].AsF64, 2.50);
	ASSERT_EQ(o.SpDiff, 1);
}

TEST(ReactorExecution, Instruction_FMul)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Push},
		Signal {4.25},
		Signal {Instruction::Push},
		Signal {2.50},
		Signal {Instruction::FMul},
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_DOUBLE_EQ(o.Input->Stack[1].AsF64, 10.625);
	ASSERT_DOUBLE_EQ(o.Input->Stack[2].AsF64, 2.50);
	ASSERT_EQ(o.SpDiff, 1);
}

TEST(ReactorExecution, Instruction_FDiv)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Push},
		Signal {4.25},
		Signal {Instruction::Push},
		Signal {2.50},
		Signal {Instruction::FDiv},
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_DOUBLE_EQ(o.Input->Stack[1].AsF64, 1.7);
	ASSERT_DOUBLE_EQ(o.Input->Stack[2].AsF64, 2.50);
	ASSERT_EQ(o.SpDiff, 1);
}

TEST(ReactorExecution, Instruction_FNeg)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Push},
		Signal {2.25},
		Signal {Instruction::FNeg},
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_DOUBLE_EQ(o.Input->Stack[1].AsF64, -2.25);
	ASSERT_EQ(o.SpDiff, 1);
}

TEST(ReactorExecution, Instruction_FInc)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Push},
		Signal {.0},
		Signal {Instruction::FInc},
		Signal {Instruction::FInc},
		Signal {Instruction::FInc},
		Signal {Instruction::FInc},
		Signal {Instruction::FInc},
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[0], Record::Padding());
	ASSERT_DOUBLE_EQ(o.Input->Stack[1].AsF64, 5.);
	ASSERT_EQ(o.SpDiff, 1);
}

TEST(ReactorExecution, Instruction_FDec)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Push},
		Signal {2.},
		Signal {Instruction::FDec},
		Signal {Instruction::FDec},
		Signal {Instruction::FDec},
		Signal {Instruction::FDec},
		Signal {Instruction::FDec},
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[0], Record::Padding());
	ASSERT_DOUBLE_EQ(o.Input->Stack[1].AsF64, -3.);
	ASSERT_EQ(o.SpDiff, 1);
}

TEST(ReactorExecution, Instruction_FPushO)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::FPushO},
		Signal {Instruction::PushZ},
		Signal {Instruction::FPushO},
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsF64, 1.);
	ASSERT_EQ(o.Input->Stack[2].AsU64, 0);
	ASSERT_EQ(o.Input->Stack[3].AsF64, 1.);
}

TEST(ReactorExecution, Instruction_Call)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Call},
		Signal {UINT64_C(5)},
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
		Signal {Instruction::Push},
		Signal {INT64_C(10)},
		Signal {Instruction::Int},
		Signal {INT64_C(-0xFF)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsI64, 10);
	ASSERT_EQ(o.IpDiff, 8);
	ASSERT_EQ(o.InterruptCode, -0xFF);
}

TEST(ReactorExecution, Instruction_Ret)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Call},
		Signal {UINT64_C(5)},
		Signal {Instruction::Call},
		Signal {UINT64_C(5)},
		Signal {Instruction::Int},
		Signal {INT64_C(-0xABCDEF)},
		Signal {Instruction::Push},
		Signal {INT64_C(10)},
		Signal {Instruction::Ret},
		Signal {Instruction::Int},
		Signal {INT64_C(-0xFF)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsI64, 10);
	ASSERT_EQ(o.Input->Stack[1].AsI64, 10);
	ASSERT_EQ(o.IpDiff, 6);
	ASSERT_EQ(o.BpDiff, 3);
	ASSERT_EQ(o.InterruptCode, -0xABCDEF);
}

TEST(ReactorExecution, Instruction_Jmp)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Jmp},
		Signal {UINT64_C(5)},
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
		Signal {Instruction::Push},
		Signal {INT64_C(10)},
		Signal {Instruction::Int},
		Signal {INT64_C(-0xFF)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsI64, 10);
	ASSERT_EQ(o.IpDiff, 8);
	ASSERT_EQ(o.InterruptCode, -0xFF);
}

TEST(ReactorExecution, Instruction_JmpRel)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::JmpRel},
		Signal {UINT64_C(3)},
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
		Signal {Instruction::Push},
		Signal {INT64_C(10)},
		Signal {Instruction::Int},
		Signal {INT64_C(-0xFF)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsI64, 10);
	ASSERT_EQ(o.IpDiff, 8);
	ASSERT_EQ(o.InterruptCode, -0xFF);
}

TEST(ReactorExecution, Instruction_JZ)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::PushZ},
		Signal {Instruction::Jz},
		Signal {UINT64_C(6)}, // first padding does not count
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
		Signal {Instruction::IPushO},
		Signal {Instruction::Jz},
		Signal {UINT64_C(0)},
		Signal {Instruction::Int},
		Signal {INT64_C(-0xFF)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsU64, 1);
	ASSERT_EQ(o.SpDiff, 0);
	ASSERT_EQ(o.IpDiff, 10);
	ASSERT_EQ(o.InterruptCode, -0xFF);
}

TEST(ReactorExecution, Instruction_JnZ)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::IPushO},
		Signal {Instruction::Jnz},
		Signal {UINT64_C(6)}, // first padding does not count
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
		Signal {Instruction::PushZ},
		Signal {Instruction::Jnz},
		Signal {UINT64_C(1)},
		Signal {Instruction::Int},
		Signal {INT64_C(-0xFF)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsU64, 0);
	ASSERT_EQ(o.SpDiff, 0);
	ASSERT_EQ(o.IpDiff, 10);
	ASSERT_EQ(o.InterruptCode, -0xFF);
}

TEST(ReactorExecution, Instruction_JoCmpI)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::IPushO},
		Signal {Instruction::JoCmpi},
		Signal {UINT64_C(6)}, // first padding does not count
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
		Signal {Instruction::PushZ},
		Signal {Instruction::JoCmpi},
		Signal {UINT64_C(0)},
		Signal {Instruction::Int},
		Signal {INT64_C(-0xFF)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsU64, 0);
	ASSERT_EQ(o.SpDiff, 0);
	ASSERT_EQ(o.IpDiff, 10);
	ASSERT_EQ(o.InterruptCode, -0xFF);
}

TEST(ReactorExecution, Instruction_JnoCmpI)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::PushZ},
		Signal {Instruction::JnoCmpi},
		Signal {UINT64_C(6)}, // first padding does not count
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
		Signal {Instruction::IPushO},
		Signal {Instruction::JnoCmpi},
		Signal {UINT64_C(0)},
		Signal {Instruction::Int},
		Signal {INT64_C(-0xFF)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsU64, 1);
	ASSERT_EQ(o.SpDiff, 0);
	ASSERT_EQ(o.IpDiff, 10);
	ASSERT_EQ(o.InterruptCode, -0xFF);
}

TEST(ReactorExecution, Instruction_JoCmpF)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::FPushO},
		Signal {Instruction::JoCmpf},
		Signal {UINT64_C(6)}, // first padding does not count
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
		Signal {Instruction::PushZ},
		Signal {Instruction::JoCmpf},
		Signal {UINT64_C(0)},
		Signal {Instruction::Int},
		Signal {INT64_C(-0xFF)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsF64, 0.F);
	ASSERT_EQ(o.SpDiff, 0);
	ASSERT_EQ(o.IpDiff, 10);
	ASSERT_EQ(o.InterruptCode, -0xFF);
}

TEST(ReactorExecution, Instruction_JnoCmpF)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::PushZ},
		Signal {Instruction::JnoCmpf},
		Signal {UINT64_C(6)}, // first padding does not count
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
		Signal {Instruction::FPushO},
		Signal {Instruction::JnoCmpf},
		Signal {UINT64_C(0)},
		Signal {Instruction::Int},
		Signal {INT64_C(-0xFF)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsF64, 1.0);
	ASSERT_EQ(o.SpDiff, 0);
	ASSERT_EQ(o.IpDiff, 10);
	ASSERT_EQ(o.InterruptCode, -0xFF);
}

TEST(ReactorExecution, Instruction_JeCmpI)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Push},
		Signal {INT64_C(12345679)},
		Signal {Instruction::Dupl},
		Signal {Instruction::JeCmpi},
		Signal {UINT64_C(8)},
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
		Signal {Instruction::Push},
		Signal {INT64_C(123424224)},
		Signal {Instruction::Push},
		Signal {INT64_C(0xFF'FF)},
		Signal {Instruction::JeCmpi},
		Signal {UINT64_C(0)},
		Signal {Instruction::Int},
		Signal {INT64_C(-0xFF)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsI64, 123424224);
	ASSERT_EQ(o.Input->Stack[2].AsI64, 0xFF'FF);
	ASSERT_EQ(o.SpDiff, 0);
	ASSERT_EQ(o.IpDiff, 15);
	ASSERT_EQ(o.InterruptCode, -0xFF);
}

TEST(ReactorExecution, Instruction_JeCmpF)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Push},
		Signal {1234567.0},
		Signal {Instruction::Dupl},
		Signal {Instruction::JeCmpf},
		Signal {UINT64_C(8)},
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
		Signal {Instruction::Push},
		Signal {123424224.0},
		Signal {Instruction::Push},
		Signal {0.22233},
		Signal {Instruction::JeCmpf},
		Signal {UINT64_C(0)},
		Signal {Instruction::Int},
		Signal {INT64_C(-0xFF)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsF64, 123424224.0);
	ASSERT_EQ(o.Input->Stack[2].AsF64, 0.22233);
	ASSERT_EQ(o.SpDiff, 0);
	ASSERT_EQ(o.IpDiff, 15);
	ASSERT_EQ(o.InterruptCode, -0xFF);
}

TEST(ReactorExecution, Instruction_JneCmpI)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Push},
		Signal {INT64_C(1234567)},
		Signal {Instruction::Push},
		Signal {INT64_C(213131232)},
		Signal {Instruction::JneCmpi},
		Signal {UINT64_C(9)},
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
		Signal {Instruction::Push},
		Signal {INT64_C(0xFF'FF)},
		Signal {Instruction::Push},
		Signal {INT64_C(0xFF'FF)},
		Signal {Instruction::JneCmpi},
		Signal {UINT64_C(0)},
		Signal {Instruction::Int},
		Signal {INT64_C(-0xFF)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsI64, 0xFF'FF);
	ASSERT_EQ(o.Input->Stack[2].AsI64, 0xFF'FF);
	ASSERT_EQ(o.SpDiff, 0);
	ASSERT_EQ(o.IpDiff, 16);
	ASSERT_EQ(o.InterruptCode, -0xFF);
}

TEST(ReactorExecution, Instruction_JneCmpF)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Push},
		Signal {1234567.},
		Signal {Instruction::Push},
		Signal {213131232.},
		Signal {Instruction::JneCmpf},
		Signal {UINT64_C(9)},
		Signal {Instruction::Int},
		Signal {INT64_C(-1)},
		Signal {Instruction::Push},
		Signal {3.1415},
		Signal {Instruction::Push},
		Signal {3.1415},
		Signal {Instruction::JneCmpf},
		Signal {UINT64_C(0)},
		Signal {Instruction::Int},
		Signal {INT64_C(-0xFF)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsF64, 3.1415);
	ASSERT_EQ(o.Input->Stack[2].AsF64, 3.1415);
	ASSERT_EQ(o.SpDiff, 0);
	ASSERT_EQ(o.IpDiff, 16);
	ASSERT_EQ(o.InterruptCode, -0xFF);
}

TEST(ReactorExecution, Instruction_JaCmpI)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Push},
		Signal {INT64_C(5)},
		Signal {Instruction::Push},
		Signal {INT64_C(2)},
		Signal {Instruction::JaCmpi},
		Signal {UINT64_C(9)},
		Signal {Instruction::Int},
		Signal {INT64_C(0)},
		Signal {Instruction::Push},
		Signal {INT64_C(3)},
		Signal {Instruction::Push},
		Signal {INT64_C(53)},
		Signal {Instruction::JaCmpi},
		Signal {UINT64_C(0)},
		Signal {Instruction::Int},
		Signal {INT64_C(-0xFF)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsI64, 3);
	ASSERT_EQ(o.Input->Stack[2].AsI64, 53);
	ASSERT_EQ(o.SpDiff, 0);
	ASSERT_EQ(o.IpDiff, 16);
	ASSERT_EQ(o.InterruptCode, -0xFF);
}

TEST(ReactorExecution, Instruction_JaCmpF)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Push},
		Signal {5.0},
		Signal {Instruction::Push},
		Signal {2.0},
		Signal {Instruction::JaCmpf},
		Signal {UINT64_C(9)},
		Signal {Instruction::Int},
		Signal {INT64_C(0)},
		Signal {Instruction::Push},
		Signal {3.0},
		Signal {Instruction::Push},
		Signal {53.0},
		Signal {Instruction::JaCmpf},
		Signal {UINT64_C(0)},
		Signal {Instruction::Int},
		Signal {INT64_C(-0xFF)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsF64, 3.0);
	ASSERT_EQ(o.Input->Stack[2].AsF64, 53.0);
	ASSERT_EQ(o.SpDiff, 0);
	ASSERT_EQ(o.IpDiff, 16);
	ASSERT_EQ(o.InterruptCode, -0xFF);
}

TEST(ReactorExecution, Instruction_JlCmpI)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Push},
		Signal {INT64_C(2)},
		Signal {Instruction::Push},
		Signal {INT64_C(5)},
		Signal {Instruction::JlCmpi},
		Signal {UINT64_C(9)},
		Signal {Instruction::Int},
		Signal {INT64_C(0)},
		Signal {Instruction::Push},
		Signal {INT64_C(53)},
		Signal {Instruction::Push},
		Signal {INT64_C(3)},
		Signal {Instruction::JlCmpi},
		Signal {UINT64_C(0)},
		Signal {Instruction::Int},
		Signal {INT64_C(-0xFF)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsI64, 53);
	ASSERT_EQ(o.Input->Stack[2].AsI64, 3);
	ASSERT_EQ(o.SpDiff, 0);
	ASSERT_EQ(o.IpDiff, 16);
	ASSERT_EQ(o.InterruptCode, -0xFF);
}

TEST(ReactorExecution, Instruction_JlCmpF)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Push},
		Signal {2.0},
		Signal {Instruction::Push},
		Signal {5.0},
		Signal {Instruction::JlCmpf},
		Signal {UINT64_C(9)},
		Signal {Instruction::Int},
		Signal {INT64_C(0)},
		Signal {Instruction::Push},
		Signal {53.0},
		Signal {Instruction::Push},
		Signal {3.0},
		Signal {Instruction::JlCmpf},
		Signal {UINT64_C(0)},
		Signal {Instruction::Int},
		Signal {INT64_C(-0xFF)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsF64, 53.0);
	ASSERT_EQ(o.Input->Stack[2].AsF64, 3.0);
	ASSERT_EQ(o.SpDiff, 0);
	ASSERT_EQ(o.IpDiff, 16);
	ASSERT_EQ(o.InterruptCode, -0xFF);
}

TEST(ReactorExecution, Instruction_JaeCmpI)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Push},
		Signal {INT64_C(5)},
		Signal {Instruction::Push},
		Signal {INT64_C(2)},
		Signal {Instruction::JaeCmpi},
		Signal {UINT64_C(9)},
		Signal {Instruction::Int},
		Signal {INT64_C(-3)},
		Signal {Instruction::IPushO},
		Signal {Instruction::IPushO},
		Signal {Instruction::JaeCmpi},
		Signal {UINT64_C(15)},
		Signal {Instruction::Int},
		Signal {INT64_C(-5)},
		Signal {Instruction::Push},
		Signal {INT64_C(3)},
		Signal {Instruction::Push},
		Signal {INT64_C(53)},
		Signal {Instruction::JaeCmpi},
		Signal {UINT64_C(0)},
		Signal {Instruction::Int},
		Signal {INT64_C(-0xFF)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsI64, 3);
	ASSERT_EQ(o.Input->Stack[2].AsI64, 53);
	ASSERT_EQ(o.SpDiff, 0);
	ASSERT_EQ(o.IpDiff, 22);
	ASSERT_EQ(o.InterruptCode, -0xFF);
}

TEST(ReactorExecution, Instruction_JaeCmpF)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Push},
		Signal {5.0},
		Signal {Instruction::Push},
		Signal {2.0},
		Signal {Instruction::JaeCmpf},
		Signal {UINT64_C(9)},
		Signal {Instruction::Int},
		Signal {INT64_C(-3)},
		Signal {Instruction::IPushO},
		Signal {Instruction::IPushO},
		Signal {Instruction::JaeCmpf},
		Signal {UINT64_C(15)},
		Signal {Instruction::Int},
		Signal {INT64_C(-5)},
		Signal {Instruction::Push},
		Signal {3.0},
		Signal {Instruction::Push},
		Signal {53.0},
		Signal {Instruction::JaeCmpf},
		Signal {UINT64_C(0)},
		Signal {Instruction::Int},
		Signal {INT64_C(-0xFF)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsF64, 3.0);
	ASSERT_EQ(o.Input->Stack[2].AsF64, 53.0);
	ASSERT_EQ(o.SpDiff, 0);
	ASSERT_EQ(o.IpDiff, 22);
	ASSERT_EQ(o.InterruptCode, -0xFF);
}

TEST(ReactorExecution, Instruction_JleCmpI)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Push},
		Signal {INT64_C(2)},
		Signal {Instruction::Push},
		Signal {INT64_C(5)},
		Signal {Instruction::JleCmpi},
		Signal {UINT64_C(9)},
		Signal {Instruction::Int},
		Signal {INT64_C(-3)},
		Signal {Instruction::IPushO},
		Signal {Instruction::IPushO},
		Signal {Instruction::JleCmpi},
		Signal {UINT64_C(15)},
		Signal {Instruction::Int},
		Signal {INT64_C(-5)},
		Signal {Instruction::Push},
		Signal {INT64_C(53)},
		Signal {Instruction::Push},
		Signal {INT64_C(3)},
		Signal {Instruction::JleCmpi},
		Signal {UINT64_C(0)},
		Signal {Instruction::Int},
		Signal {INT64_C(-0xFF)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsI64, 53);
	ASSERT_EQ(o.Input->Stack[2].AsI64, 3);
	ASSERT_EQ(o.SpDiff, 0);
	ASSERT_EQ(o.IpDiff, 22);
	ASSERT_EQ(o.InterruptCode, -0xFF);
}

TEST(ReactorExecution, Instruction_JleCmpF)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::Push},
		Signal {2.0},
		Signal {Instruction::Push},
		Signal {5.0},
		Signal {Instruction::JleCmpf},
		Signal {UINT64_C(9)},
		Signal {Instruction::Int},
		Signal {INT64_C(-3)},
		Signal {Instruction::IPushO},
		Signal {Instruction::IPushO},
		Signal {Instruction::JleCmpf},
		Signal {UINT64_C(15)},
		Signal {Instruction::Int},
		Signal {INT64_C(-5)},
		Signal {Instruction::Push},
		Signal {53.0},
		Signal {Instruction::Push},
		Signal {3.0},
		Signal {Instruction::JleCmpf},
		Signal {UINT64_C(0)},
		Signal {Instruction::Int},
		Signal {INT64_C(-0xFF)},
	};
	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_EQ(o.Input->Stack[1].AsF64, 53.0);
	ASSERT_EQ(o.Input->Stack[2].AsF64, 3.0);
	ASSERT_EQ(o.SpDiff, 0);
	ASSERT_EQ(o.IpDiff, 22);
	ASSERT_EQ(o.InterruptCode, -0xFF);
}

TEST(ReactorExecution, Instruction_VPush)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::VPush},
		Signal {1.0},
		Signal {2.0},
		Signal {3.0},
		Signal {4.0},
		Signal {Instruction::Int},
		Signal {INT64_C(-0xFF)},
	};

	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_DOUBLE_EQ(o.Input->Stack[1].AsF64, 1.0);
	ASSERT_DOUBLE_EQ(o.Input->Stack[2].AsF64, 2.0);
	ASSERT_DOUBLE_EQ(o.Input->Stack[3].AsF64, 3.0);
	ASSERT_DOUBLE_EQ(o.Input->Stack[4].AsF64, 4.0);
	ASSERT_EQ(o.SpDiff, 4);
	ASSERT_EQ(o.IpDiff, 7);
	ASSERT_EQ(o.InterruptCode, -0xFF);
}

TEST(ReactorExecution, Instruction_VPop)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::VPush},
		Signal {1.0},
		Signal {2.0},
		Signal {3.0},
		Signal {4.0},
		Signal {Instruction::VPop},
		Signal {Instruction::Int},
		Signal {INT64_C(-0xFF)},
	};

	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_DOUBLE_EQ(o.Input->Stack[1].AsF64, 1.0);
	ASSERT_DOUBLE_EQ(o.Input->Stack[2].AsF64, 2.0);
	ASSERT_DOUBLE_EQ(o.Input->Stack[3].AsF64, 3.0);
	ASSERT_DOUBLE_EQ(o.Input->Stack[4].AsF64, 4.0);
	ASSERT_EQ(o.SpDiff, 0);
	ASSERT_EQ(o.IpDiff, 8);
	ASSERT_EQ(o.InterruptCode, -0xFF);
}

TEST(ReactorExecution, Instruction_VAdd)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::VPush},
		Signal {1.0},
		Signal {2.0},
		Signal {3.0},
		Signal {4.0},
		Signal {Instruction::VPush},
		Signal {6.0},
		Signal {8.0},
		Signal {10.0},
		Signal {12.0},
		Signal {Instruction::VAdd},
		Signal {Instruction::VPop},
		Signal {Instruction::Int},
		Signal {INT64_C(-0xFF)},
	};

	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_DOUBLE_EQ(o.Input->Stack[1].AsF64, 7.0);
	ASSERT_DOUBLE_EQ(o.Input->Stack[2].AsF64, 10.0);
	ASSERT_DOUBLE_EQ(o.Input->Stack[3].AsF64, 13.0);
	ASSERT_DOUBLE_EQ(o.Input->Stack[4].AsF64, 16.0);
	ASSERT_EQ(o.SpDiff, 0);
	ASSERT_EQ(o.IpDiff, 14);
	ASSERT_EQ(o.InterruptCode, -0xFF);
}

TEST(ReactorExecution, Instruction_VSub)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::VPush},
		Signal {1.0},
		Signal {2.0},
		Signal {3.0},
		Signal {4.0},
		Signal {Instruction::VPush},
		Signal {2.0},
		Signal {3.0},
		Signal {1.0},
		Signal {4.0},
		Signal {Instruction::VSub},
		Signal {Instruction::VPop},
		Signal {Instruction::Int},
		Signal {INT64_C(-0xFF)},
	};

	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_DOUBLE_EQ(o.Input->Stack[1].AsF64, -1.0);
	ASSERT_DOUBLE_EQ(o.Input->Stack[2].AsF64, -1.0);
	ASSERT_DOUBLE_EQ(o.Input->Stack[3].AsF64, 2.0);
	ASSERT_DOUBLE_EQ(o.Input->Stack[4].AsF64, 0.0);
	ASSERT_EQ(o.SpDiff, 0);
	ASSERT_EQ(o.IpDiff, 14);
	ASSERT_EQ(o.InterruptCode, -0xFF);
}

TEST(ReactorExecution, Instruction_VMul)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::VPush},
		Signal {1.0},
		Signal {2.0},
		Signal {3.0},
		Signal {4.0},
		Signal {Instruction::VPush},
		Signal {1.0},
		Signal {2.0},
		Signal {3.0},
		Signal {4.0},
		Signal {Instruction::VMul},
		Signal {Instruction::VPop},
		Signal {Instruction::Int},
		Signal {INT64_C(-0xFF)},
	};

	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_DOUBLE_EQ(o.Input->Stack[1].AsF64, 1.0);
	ASSERT_DOUBLE_EQ(o.Input->Stack[2].AsF64, 4.0);
	ASSERT_DOUBLE_EQ(o.Input->Stack[3].AsF64, 9.0);
	ASSERT_DOUBLE_EQ(o.Input->Stack[4].AsF64, 16.0);
	ASSERT_EQ(o.SpDiff, 0);
	ASSERT_EQ(o.IpDiff, 14);
	ASSERT_EQ(o.InterruptCode, -0xFF);
}

TEST(ReactorExecution, Instruction_VDiv)
{
	std::array code {
		Signal {Instruction::NOp}, // first padding
		Signal {Instruction::VPush},
		Signal {1.0},
		Signal {2.0},
		Signal {3.0},
		Signal {8.0},
		Signal {Instruction::VPush},
		Signal {4.0},
		Signal {2.0},
		Signal {0.5},
		Signal {4.0},
		Signal {Instruction::VDiv},
		Signal {Instruction::VPop},
		Signal {Instruction::Int},
		Signal {INT64_C(-0xFF)},
	};

	auto input {MOCK_REACTOR_INPUT};
	input.CodeChunk     = code.data();
	input.CodeChunkSize = code.size();
	ASSERT_EQ(input.Validate(), ReactorValidationResult::Ok);

	const auto o {ExecuteOnce(input)};
	ASSERT_DOUBLE_EQ(o.Input->Stack[1].AsF64, 0.25);
	ASSERT_DOUBLE_EQ(o.Input->Stack[2].AsF64, 1.0);
	ASSERT_DOUBLE_EQ(o.Input->Stack[3].AsF64, 6.0);
	ASSERT_DOUBLE_EQ(o.Input->Stack[4].AsF64, 2.0);
	ASSERT_EQ(o.SpDiff, 0);
	ASSERT_EQ(o.IpDiff, 14);
	ASSERT_EQ(o.InterruptCode, -0xFF);
}
