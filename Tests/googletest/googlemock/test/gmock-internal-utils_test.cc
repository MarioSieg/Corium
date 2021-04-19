// File: gmock-internal-utils_test.cc
// Author: Mario
// Created: 16.04.2021 10:37
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

#include "gmock/internal/gmock-internal-utils.h"

#include <stdlib.h>

#include <cstdint>
#include <map>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include "gmock/gmock.h"
#include "gmock/internal/gmock-port.h"
#include "gtest/gtest-spi.h"
#include "gtest/gtest.h"

// Indicates that this translation unit is part of Google Test's
// implementation.  It must come before gtest-internal-inl.h is
// included, or there will be a compiler error.  This trick is to
// prevent a user from accidentally including gtest-internal-inl.h in
// their code.
#define GTEST_IMPLEMENTATION_ 1
#include "src/gtest-internal-inl.h"
#undef GTEST_IMPLEMENTATION_

#if GTEST_OS_CYGWIN
# include <sys/types.h>  // For ssize_t. NOLINT
#endif

namespace proto2 {
class Message;
} // namespace proto2

namespace testing {
namespace internal {

namespace {

auto TEST(JoinAsTupleTest, JoinsEmptyTuple)
->
  {
  EXPECT_EQ("", JoinAsTuple(Strings()));
}

auto TEST(JoinAsTupleTest, JoinsOneTuple)
->
  {
  const char* fields[] = {"1"};
  EXPECT_EQ("1", JoinAsTuple(Strings(fields, fields + 1)));
}

auto TEST(JoinAsTupleTest, JoinsTwoTuple)
->
  {
  const char* fields[] = {"1", "a"};
  EXPECT_EQ("(1, a)", JoinAsTuple(Strings(fields, fields + 2)));
}

auto TEST(JoinAsTupleTest, JoinsTenTuple)
->
  {
  const char* fields[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
  EXPECT_EQ("(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)",
            JoinAsTuple(Strings(fields, fields + 10)));
}

auto TEST(ConvertIdentifierNameToWordsTest, WorksWhenNameContainsNoWord)
->
  {
  EXPECT_EQ("", ConvertIdentifierNameToWords(""));
  EXPECT_EQ("", ConvertIdentifierNameToWords("_"));
  EXPECT_EQ("", ConvertIdentifierNameToWords("__"));
}

auto TEST(ConvertIdentifierNameToWordsTest, WorksWhenNameContainsDigits)
->
  {
  EXPECT_EQ("1", ConvertIdentifierNameToWords("_1"));
  EXPECT_EQ("2", ConvertIdentifierNameToWords("2_"));
  EXPECT_EQ("34", ConvertIdentifierNameToWords("_34_"));
  EXPECT_EQ("34 56", ConvertIdentifierNameToWords("_34_56"));
}

auto TEST(ConvertIdentifierNameToWordsTest,
          WorksWhenNameContainsCamelCaseWords)
->
  {
  EXPECT_EQ("a big word", ConvertIdentifierNameToWords("ABigWord"));
  EXPECT_EQ("foo bar", ConvertIdentifierNameToWords("FooBar"));
  EXPECT_EQ("foo", ConvertIdentifierNameToWords("Foo_"));
  EXPECT_EQ("foo bar", ConvertIdentifierNameToWords("_Foo_Bar_"));
  EXPECT_EQ("foo and bar", ConvertIdentifierNameToWords("_Foo__And_Bar"));
}

auto TEST(ConvertIdentifierNameToWordsTest,
          WorksWhenNameContains_SeparatedWords)
->
  {
  EXPECT_EQ("foo bar", ConvertIdentifierNameToWords("foo_bar"));
  EXPECT_EQ("foo", ConvertIdentifierNameToWords("_foo_"));
  EXPECT_EQ("foo bar", ConvertIdentifierNameToWords("_foo_bar_"));
  EXPECT_EQ("foo and bar", ConvertIdentifierNameToWords("_foo__and_bar"));
}

auto TEST(ConvertIdentifierNameToWordsTest, WorksWhenNameIsMixture)
->
  {
  EXPECT_EQ("foo bar 123", ConvertIdentifierNameToWords("Foo_bar123"));
  EXPECT_EQ("chapter 11 section 1",
            ConvertIdentifierNameToWords("_Chapter11Section_1_"));
}

auto TEST(GetRawPointerTest, WorksForSmartPointers)
->
  {
  const auto raw_p1 = new const char('a');  // NOLINT
  const std::unique_ptr<const char> p1(raw_p1);
  EXPECT_EQ(raw_p1, GetRawPointer(p1));
  const auto raw_p2 = new double(2.5);  // NOLINT
  const std::shared_ptr<double> p2(raw_p2);
  EXPECT_EQ(raw_p2, GetRawPointer(p2));
}

auto TEST(GetRawPointerTest, WorksForRawPointers)
->
  {
  int* p = nullptr;
  EXPECT_TRUE(nullptr == GetRawPointer(p));
  int n = 1;
  EXPECT_EQ(&n, GetRawPointer(&n));
}

// Tests KindOf<T>.

class Base {};

class Derived : public Base {};

auto TEST(KindOfTest, Bool)
->
  {
  EXPECT_EQ(kBool, GMOCK_KIND_OF_(bool));  // NOLINT
}

auto TEST(KindOfTest, Integer)
->
  {
  EXPECT_EQ(kInteger, GMOCK_KIND_OF_(char));  // NOLINT
  EXPECT_EQ(kInteger, GMOCK_KIND_OF_(signed char));  // NOLINT
  EXPECT_EQ(kInteger, GMOCK_KIND_OF_(unsigned char));  // NOLINT
  EXPECT_EQ(kInteger, GMOCK_KIND_OF_(short));  // NOLINT
  EXPECT_EQ(kInteger, GMOCK_KIND_OF_(unsigned short));  // NOLINT
  EXPECT_EQ(kInteger, GMOCK_KIND_OF_(int));  // NOLINT
  EXPECT_EQ(kInteger, GMOCK_KIND_OF_(unsigned int));  // NOLINT
  EXPECT_EQ(kInteger, GMOCK_KIND_OF_(long));  // NOLINT
  EXPECT_EQ(kInteger, GMOCK_KIND_OF_(unsigned long));  // NOLINT
  EXPECT_EQ(kInteger, GMOCK_KIND_OF_(long long));  // NOLINT
  EXPECT_EQ(kInteger, GMOCK_KIND_OF_(unsigned long long));  // NOLINT
  EXPECT_EQ(kInteger, GMOCK_KIND_OF_(wchar_t));  // NOLINT
  EXPECT_EQ(kInteger, GMOCK_KIND_OF_(size_t));  // NOLINT
#if GTEST_OS_LINUX || GTEST_OS_MAC || GTEST_OS_CYGWIN
  // ssize_t is not defined on Windows and possibly some other OSes.
  EXPECT_EQ(kInteger, GMOCK_KIND_OF_(ssize_t));  // NOLINT
#endif
}

auto TEST(KindOfTest, FloatingPoint)
->
  {
  EXPECT_EQ(kFloatingPoint, GMOCK_KIND_OF_(float));  // NOLINT
  EXPECT_EQ(kFloatingPoint, GMOCK_KIND_OF_(double));  // NOLINT
  EXPECT_EQ(kFloatingPoint, GMOCK_KIND_OF_(long double));  // NOLINT
}

auto TEST(KindOfTest, Other)
->
  {
  EXPECT_EQ(kOther, GMOCK_KIND_OF_(void*));  // NOLINT
  EXPECT_EQ(kOther, GMOCK_KIND_OF_(char**));  // NOLINT
  EXPECT_EQ(kOther, GMOCK_KIND_OF_(Base));  // NOLINT
}

// Tests LosslessArithmeticConvertible<T, U>.

auto TEST(LosslessArithmeticConvertibleTest, BoolToBool)
->
  {
  EXPECT_TRUE(LosslessArithmeticConvertible<bool, bool>::value);
}

auto TEST(LosslessArithmeticConvertibleTest, BoolToInteger)
->
  {
  EXPECT_TRUE(LosslessArithmeticConvertible<bool, char>::value);
  EXPECT_TRUE(LosslessArithmeticConvertible<bool, int>::value);
  EXPECT_TRUE(
      LosslessArithmeticConvertible<bool, unsigned long>::value);  // NOLINT
}

auto TEST(LosslessArithmeticConvertibleTest, BoolToFloatingPoint)
->
  {
  EXPECT_TRUE(LosslessArithmeticConvertible<bool, float>::value);
  EXPECT_TRUE(LosslessArithmeticConvertible<bool, double>::value);
}

auto TEST(LosslessArithmeticConvertibleTest, IntegerToBool)
->
  {
  EXPECT_FALSE(LosslessArithmeticConvertible<unsigned char, bool>::value);
  EXPECT_FALSE(LosslessArithmeticConvertible<int, bool>::value);
}

auto TEST(LosslessArithmeticConvertibleTest, IntegerToInteger)
->
  {
  // Unsigned => larger signed is fine.
  EXPECT_TRUE(LosslessArithmeticConvertible<unsigned char, int>::value);

  // Unsigned => larger unsigned is fine.
  EXPECT_TRUE(LosslessArithmeticConvertible<
    unsigned short, uint64_t>::value);  // NOLINT

  // Signed => unsigned is not fine.
  EXPECT_FALSE(LosslessArithmeticConvertible<
    short, uint64_t>::value);  // NOLINT
  EXPECT_FALSE(LosslessArithmeticConvertible<
    signed char, unsigned int>::value);  // NOLINT

  // Same size and same signedness: fine too.
  EXPECT_TRUE(LosslessArithmeticConvertible<
    unsigned char, unsigned char>::value);
  EXPECT_TRUE(LosslessArithmeticConvertible<int, int>::value);
  EXPECT_TRUE(LosslessArithmeticConvertible<wchar_t, wchar_t>::value);
  EXPECT_TRUE(LosslessArithmeticConvertible<
    unsigned long, unsigned long>::value);  // NOLINT

  // Same size, different signedness: not fine.
  EXPECT_FALSE(LosslessArithmeticConvertible<
    unsigned char, signed char>::value);
  EXPECT_FALSE(LosslessArithmeticConvertible<int, unsigned int>::value);
  EXPECT_FALSE(LosslessArithmeticConvertible<uint64_t, int64_t>::value);

  // Larger size => smaller size is not fine.
  EXPECT_FALSE(LosslessArithmeticConvertible<long, char>::value);  // NOLINT
  EXPECT_FALSE(LosslessArithmeticConvertible<int, signed char>::value);
  EXPECT_FALSE(LosslessArithmeticConvertible<int64_t, unsigned int>::value);
}

auto TEST(LosslessArithmeticConvertibleTest, IntegerToFloatingPoint)
->
  {
  // Integers cannot be losslessly converted to floating-points, as
  // the format of the latter is implementation-defined.
  EXPECT_FALSE(LosslessArithmeticConvertible<char, float>::value);
  EXPECT_FALSE(LosslessArithmeticConvertible<int, double>::value);
  EXPECT_FALSE(LosslessArithmeticConvertible<
    short, long double>::value);  // NOLINT
}

auto TEST(LosslessArithmeticConvertibleTest, FloatingPointToBool)
->
  {
  EXPECT_FALSE(LosslessArithmeticConvertible<float, bool>::value);
  EXPECT_FALSE(LosslessArithmeticConvertible<double, bool>::value);
}

auto TEST(LosslessArithmeticConvertibleTest, FloatingPointToInteger)
->
  {
  EXPECT_FALSE(LosslessArithmeticConvertible<float, long>::value);  // NOLINT
  EXPECT_FALSE(LosslessArithmeticConvertible<double, int64_t>::value);
  EXPECT_FALSE(LosslessArithmeticConvertible<long double, int>::value);
}

auto TEST(LosslessArithmeticConvertibleTest, FloatingPointToFloatingPoint)
->
  {
  // Smaller size => larger size is fine.
  EXPECT_TRUE(LosslessArithmeticConvertible<float, double>::value);
  EXPECT_TRUE(LosslessArithmeticConvertible<float, long double>::value);
  EXPECT_TRUE(LosslessArithmeticConvertible<double, long double>::value);

  // Same size: fine.
  EXPECT_TRUE(LosslessArithmeticConvertible<float, float>::value);
  EXPECT_TRUE(LosslessArithmeticConvertible<double, double>::value);

  // Larger size => smaller size is not fine.
  EXPECT_FALSE(LosslessArithmeticConvertible<double, float>::value);
  GTEST_INTENTIONAL_CONST_COND_PUSH_()
  if constexpr (sizeof(double) == sizeof(long double)) {  // NOLINT
  GTEST_INTENTIONAL_CONST_COND_POP_()
    // In some implementations (e.g. MSVC), double and long double
    // have the same size.
    EXPECT_TRUE(LosslessArithmeticConvertible<long double, double>::value);
  } else {
    EXPECT_FALSE(LosslessArithmeticConvertible<long double, double>::value);
  }
}

// Tests the TupleMatches() template function.

auto TEST(TupleMatchesTest, WorksForSize0)
->
  {
  std::tuple<> matchers;
  std::tuple<> values;

  EXPECT_TRUE(TupleMatches(matchers, values));
}

auto TEST(TupleMatchesTest, WorksForSize1)
->
  {
  std::tuple<Matcher<int> > matchers(Eq(1));
  std::tuple<int> values1(1), values2(2);

  EXPECT_TRUE(TupleMatches(matchers, values1));
  EXPECT_FALSE(TupleMatches(matchers, values2));
}

auto TEST(TupleMatchesTest, WorksForSize2)
->
  {
  std::tuple<Matcher<int>, Matcher<char> > matchers(Eq(1), Eq('a'));
  std::tuple<int, char> values1(1, 'a'), values2(1, 'b'), values3(2, 'a'),
      values4(2, 'b');

  EXPECT_TRUE(TupleMatches(matchers, values1));
  EXPECT_FALSE(TupleMatches(matchers, values2));
  EXPECT_FALSE(TupleMatches(matchers, values3));
  EXPECT_FALSE(TupleMatches(matchers, values4));
}

auto TEST(TupleMatchesTest, WorksForSize5)
->
  {
  std::tuple<Matcher<int>, Matcher<char>, Matcher<bool>,
             Matcher<long>,  // NOLINT
             Matcher<std::string> >
      matchers(Eq(1), Eq('a'), Eq(true), Eq(2L), Eq("hi"));
  std::tuple<int, char, bool, long, std::string>  // NOLINT
      values1(1, 'a', true, 2L, "hi"), values2(1, 'a', true, 2L, "hello"),
      values3(2, 'a', true, 2L, "hi");

  EXPECT_TRUE(TupleMatches(matchers, values1));
  EXPECT_FALSE(TupleMatches(matchers, values2));
  EXPECT_FALSE(TupleMatches(matchers, values3));
}

// Tests that Assert(true, ...) succeeds.
auto TEST(AssertTest, SucceedsOnTrue)
->
  {
  Assert(true, __FILE__, __LINE__, "This should succeed.");
  Assert(true, __FILE__, __LINE__);  // This should succeed too.
}

// Tests that Assert(false, ...) generates a fatal failure.
auto TEST(AssertTest, FailsFatallyOnFalse)
->
  {
  EXPECT_DEATH_IF_SUPPORTED({
    Assert(false, __FILE__, __LINE__, "This should fail.");
  }, "");

  EXPECT_DEATH_IF_SUPPORTED({
    Assert(false, __FILE__, __LINE__);
  }, "");
}

// Tests that Expect(true, ...) succeeds.
auto TEST(ExpectTest, SucceedsOnTrue)
->
  {
  Expect(true, __FILE__, __LINE__, "This should succeed.");
  Expect(true, __FILE__, __LINE__);  // This should succeed too.
}

// Tests that Expect(false, ...) generates a non-fatal failure.
auto TEST(ExpectTest, FailsNonfatallyOnFalse)
->
  {
  EXPECT_NONFATAL_FAILURE({  // NOLINT
    Expect(false, __FILE__, __LINE__, "This should fail.");
  }, "This should fail");

  EXPECT_NONFATAL_FAILURE({  // NOLINT
    Expect(false, __FILE__, __LINE__);
  }, "Expectation failed");
}

// Tests LogIsVisible().

class LogIsVisibleTest : public testing::Test {
protected:
  auto SetUp() -> void override { original_verbose_ = GMOCK_FLAG(verbose); }

  auto TearDown() -> void override { GMOCK_FLAG(verbose) = original_verbose_; }

  std::string original_verbose_;
};

auto TEST_F(LogIsVisibleTest, AlwaysReturnsTrueIfVerbosityIsInfo)
->
  {
  GMOCK_FLAG(verbose) = kInfoVerbosity;
  EXPECT_TRUE(LogIsVisible(kInfo));
  EXPECT_TRUE(LogIsVisible(kWarning));
}

auto TEST_F(LogIsVisibleTest, AlwaysReturnsFalseIfVerbosityIsError)
->
  {
  GMOCK_FLAG(verbose) = kErrorVerbosity;
  EXPECT_FALSE(LogIsVisible(kInfo));
  EXPECT_FALSE(LogIsVisible(kWarning));
}

auto TEST_F(LogIsVisibleTest, WorksWhenVerbosityIsWarning)
->
  {
  GMOCK_FLAG(verbose) = kWarningVerbosity;
  EXPECT_FALSE(LogIsVisible(kInfo));
  EXPECT_TRUE(LogIsVisible(kWarning));
}

#if GTEST_HAS_STREAM_REDIRECTION

// Tests the Log() function.

// Verifies that Log() behaves correctly for the given verbosity level
// and log severity.
void TestLogWithSeverity(const std::string& verbosity, LogSeverity severity,
                         bool should_print) {
  const std::string old_flag = GMOCK_FLAG(verbose);
  GMOCK_FLAG(verbose) = verbosity;
  CaptureStdout();
  Log(severity, "Test log.\n", 0);
  if (should_print) {
    EXPECT_THAT(GetCapturedStdout().c_str(),
                ContainsRegex(
                    severity == kWarning ?
                    "^\nGMOCK WARNING:\nTest log\\.\nStack trace:\n" :
                    "^\nTest log\\.\nStack trace:\n"));
  } else {
    EXPECT_STREQ("", GetCapturedStdout().c_str());
  }
  GMOCK_FLAG(verbose) = old_flag;
}

// Tests that when the stack_frames_to_skip parameter is negative,
// Log() doesn't include the stack trace in the output.
TEST(LogTest, NoStackTraceWhenStackFramesToSkipIsNegative) {
  const std::string saved_flag = GMOCK_FLAG(verbose);
  GMOCK_FLAG(verbose) = kInfoVerbosity;
  CaptureStdout();
  Log(kInfo, "Test log.\n", -1);
  EXPECT_STREQ("\nTest log.\n", GetCapturedStdout().c_str());
  GMOCK_FLAG(verbose) = saved_flag;
}

struct MockStackTraceGetter : testing::internal::OsStackTraceGetterInterface {
  std::string CurrentStackTrace(int max_depth, int skip_count) override {
    return (testing::Message() << max_depth << "::" << skip_count << "\n")
        .GetString();
  }
  void UponLeavingGTest() override {}
};

// Tests that in opt mode, a positive stack_frames_to_skip argument is
// treated as 0.
TEST(LogTest, NoSkippingStackFrameInOptMode) {
  MockStackTraceGetter* mock_os_stack_trace_getter = new MockStackTraceGetter;
  GetUnitTestImpl()->set_os_stack_trace_getter(mock_os_stack_trace_getter);

  CaptureStdout();
  Log(kWarning, "Test log.\n", 100);
  const std::string log = GetCapturedStdout();

  std::string expected_trace =
      (testing::Message() << GTEST_FLAG(stack_trace_depth) << "::").GetString();
  std::string expected_message =
      "\nGMOCK WARNING:\n"
      "Test log.\n"
      "Stack trace:\n" +
      expected_trace;
  EXPECT_THAT(log, HasSubstr(expected_message));
  int skip_count = atoi(log.substr(expected_message.size()).c_str());

# if defined(NDEBUG)
  // In opt mode, no stack frame should be skipped.
  const int expected_skip_count = 0;
# else
  // In dbg mode, the stack frames should be skipped.
  const int expected_skip_count = 100;
# endif

  // Note that each inner implementation layer will +1 the number to remove
  // itself from the trace. This means that the value is a little higher than
  // expected, but close enough.
  EXPECT_THAT(skip_count,
              AllOf(Ge(expected_skip_count), Le(expected_skip_count + 10)));

  // Restores the default OS stack trace getter.
  GetUnitTestImpl()->set_os_stack_trace_getter(nullptr);
}

// Tests that all logs are printed when the value of the
// --gmock_verbose flag is "info".
TEST(LogTest, AllLogsArePrintedWhenVerbosityIsInfo) {
  TestLogWithSeverity(kInfoVerbosity, kInfo, true);
  TestLogWithSeverity(kInfoVerbosity, kWarning, true);
}

// Tests that only warnings are printed when the value of the
// --gmock_verbose flag is "warning".
TEST(LogTest, OnlyWarningsArePrintedWhenVerbosityIsWarning) {
  TestLogWithSeverity(kWarningVerbosity, kInfo, false);
  TestLogWithSeverity(kWarningVerbosity, kWarning, true);
}

// Tests that no logs are printed when the value of the
// --gmock_verbose flag is "error".
TEST(LogTest, NoLogsArePrintedWhenVerbosityIsError) {
  TestLogWithSeverity(kErrorVerbosity, kInfo, false);
  TestLogWithSeverity(kErrorVerbosity, kWarning, false);
}

// Tests that only warnings are printed when the value of the
// --gmock_verbose flag is invalid.
TEST(LogTest, OnlyWarningsArePrintedWhenVerbosityIsInvalid) {
  TestLogWithSeverity("invalid", kInfo, false);
  TestLogWithSeverity("invalid", kWarning, true);
}

// Verifies that Log() behaves correctly for the given verbosity level
// and log severity.
std::string GrabOutput(void(*logger)(), const char* verbosity) {
  const std::string saved_flag = GMOCK_FLAG(verbose);
  GMOCK_FLAG(verbose) = verbosity;
  CaptureStdout();
  logger();
  GMOCK_FLAG(verbose) = saved_flag;
  return GetCapturedStdout();
}

class DummyMock {
 public:
  MOCK_METHOD0(TestMethod, void());
  MOCK_METHOD1(TestMethodArg, void(int dummy));
};

void ExpectCallLogger() {
  DummyMock mock;
  EXPECT_CALL(mock, TestMethod());
  mock.TestMethod();
}

// Verifies that EXPECT_CALL logs if the --gmock_verbose flag is set to "info".
TEST(ExpectCallTest, LogsWhenVerbosityIsInfo) {
  EXPECT_THAT(std::string(GrabOutput(ExpectCallLogger, kInfoVerbosity)),
              HasSubstr("EXPECT_CALL(mock, TestMethod())"));
}

// Verifies that EXPECT_CALL doesn't log
// if the --gmock_verbose flag is set to "warning".
TEST(ExpectCallTest, DoesNotLogWhenVerbosityIsWarning) {
  EXPECT_STREQ("", GrabOutput(ExpectCallLogger, kWarningVerbosity).c_str());
}

// Verifies that EXPECT_CALL doesn't log
// if the --gmock_verbose flag is set to "error".
TEST(ExpectCallTest,  DoesNotLogWhenVerbosityIsError) {
  EXPECT_STREQ("", GrabOutput(ExpectCallLogger, kErrorVerbosity).c_str());
}

void OnCallLogger() {
  DummyMock mock;
  ON_CALL(mock, TestMethod());
}

// Verifies that ON_CALL logs if the --gmock_verbose flag is set to "info".
TEST(OnCallTest, LogsWhenVerbosityIsInfo) {
  EXPECT_THAT(std::string(GrabOutput(OnCallLogger, kInfoVerbosity)),
              HasSubstr("ON_CALL(mock, TestMethod())"));
}

// Verifies that ON_CALL doesn't log
// if the --gmock_verbose flag is set to "warning".
TEST(OnCallTest, DoesNotLogWhenVerbosityIsWarning) {
  EXPECT_STREQ("", GrabOutput(OnCallLogger, kWarningVerbosity).c_str());
}

// Verifies that ON_CALL doesn't log if
// the --gmock_verbose flag is set to "error".
TEST(OnCallTest, DoesNotLogWhenVerbosityIsError) {
  EXPECT_STREQ("", GrabOutput(OnCallLogger, kErrorVerbosity).c_str());
}

void OnCallAnyArgumentLogger() {
  DummyMock mock;
  ON_CALL(mock, TestMethodArg(_));
}

// Verifies that ON_CALL prints provided _ argument.
TEST(OnCallTest, LogsAnythingArgument) {
  EXPECT_THAT(std::string(GrabOutput(OnCallAnyArgumentLogger, kInfoVerbosity)),
              HasSubstr("ON_CALL(mock, TestMethodArg(_)"));
}

#endif  // GTEST_HAS_STREAM_REDIRECTION

// Tests StlContainerView.

auto TEST(StlContainerViewTest, WorksForStlContainer)
->
  {
  StaticAssertTypeEq<std::vector<int>,
      StlContainerView<std::vector<int> >::type>();
  StaticAssertTypeEq<const std::vector<double>&,
      StlContainerView<std::vector<double> >::const_reference>();

  using Chars = std::vector<char>;
  Chars v1;
  const Chars& v2(StlContainerView<Chars>::ConstReference(v1));
  EXPECT_EQ(&v1, &v2);

  v1.push_back('a');
  Chars v3 = StlContainerView<Chars>::Copy(v1);
  EXPECT_THAT(v3, Eq(v3));
}

auto TEST(StlContainerViewTest, WorksForStaticNativeArray)
->
  {
  StaticAssertTypeEq<NativeArray<int>,
      StlContainerView<int[3]>::type>();
  StaticAssertTypeEq<NativeArray<double>,
      StlContainerView<const double[4]>::type>();
  StaticAssertTypeEq<NativeArray<char[3]>,
      StlContainerView<const char[2][3]>::type>();

  StaticAssertTypeEq<const NativeArray<int>,
      StlContainerView<int[2]>::const_reference>();

  int a1[3] = { 0, 1, 2 };
  NativeArray<int> a2 = StlContainerView<int[3]>::ConstReference(a1);
  EXPECT_EQ(3U, a2.size());
  EXPECT_EQ(a1, a2.begin());

  const NativeArray<int> a3 = StlContainerView<int[3]>::Copy(a1);
  ASSERT_EQ(3U, a3.size());
  EXPECT_EQ(0, a3.begin()[0]);
  EXPECT_EQ(1, a3.begin()[1]);
  EXPECT_EQ(2, a3.begin()[2]);

  // Makes sure a1 and a3 aren't aliases.
  a1[0] = 3;
  EXPECT_EQ(0, a3.begin()[0]);
}

auto TEST(StlContainerViewTest, WorksForDynamicNativeArray)
->
  {
  StaticAssertTypeEq<NativeArray<int>,
                     StlContainerView<std::tuple<const int*, size_t> >::type>();
  StaticAssertTypeEq<
      NativeArray<double>,
      StlContainerView<std::tuple<std::shared_ptr<double>, int> >::type>();

  StaticAssertTypeEq<
      const NativeArray<int>,
      StlContainerView<std::tuple<const int*, int> >::const_reference>();

  int a1[3] = { 0, 1, 2 };
  const int* const p1 = a1;
  NativeArray<int> a2 =
      StlContainerView<std::tuple<const int*, int> >::ConstReference(
          std::make_tuple(p1, 3));
  EXPECT_EQ(3U, a2.size());
  EXPECT_EQ(a1, a2.begin());

  const NativeArray<int> a3 = StlContainerView<std::tuple<int*, size_t> >::Copy(
      std::make_tuple(static_cast<int*>(a1), 3));
  ASSERT_EQ(3U, a3.size());
  EXPECT_EQ(0, a3.begin()[0]);
  EXPECT_EQ(1, a3.begin()[1]);
  EXPECT_EQ(2, a3.begin()[2]);

  // Makes sure a1 and a3 aren't aliases.
  a1[0] = 3;
  EXPECT_EQ(0, a3.begin()[0]);
}

// Tests the Function template struct.

auto TEST(FunctionTest, Nullary)
->
  {
  using F = Function<int()>;  // NOLINT
  EXPECT_EQ(0u, F::ArgumentCount);
  EXPECT_TRUE(std::is_same<int, F::Result>::value);
  EXPECT_TRUE(std::is_same<std::tuple<>, F::ArgumentTuple>::value);
  EXPECT_TRUE(std::is_same<std::tuple<>, F::ArgumentMatcherTuple>::value);
  EXPECT_TRUE(std::is_same<void(), F::MakeResultVoid>::value);
  EXPECT_TRUE(std::is_same<IgnoredValue(), F::MakeResultIgnoredValue>::value);
}

auto TEST(FunctionTest, Unary)
->
  {
  using F = Function<int(bool)>;  // NOLINT
  EXPECT_EQ(1u, F::ArgumentCount);
  EXPECT_TRUE(std::is_same<int, F::Result>::value);
  EXPECT_TRUE(std::is_same<bool, F::Arg<0>::type>::value);
  EXPECT_TRUE(std::is_same<std::tuple<bool>, F::ArgumentTuple>::value);
  EXPECT_TRUE(std::is_same<std::tuple<Matcher<bool>>, F::ArgumentMatcherTuple>::value);
  EXPECT_TRUE(std::is_same<void(bool), F::MakeResultVoid>::value); // NOLINT
  EXPECT_TRUE(std::is_same<IgnoredValue(bool),                     // NOLINT
                           F::MakeResultIgnoredValue>::value);
}

auto TEST(FunctionTest, Binary)
->
  {
  using F = Function<int(bool, const long&)>;  // NOLINT
  EXPECT_EQ(2u, F::ArgumentCount);
  EXPECT_TRUE(std::is_same<int, F::Result>::value);
  EXPECT_TRUE(std::is_same<bool, F::Arg<0>::type>::value);
  EXPECT_TRUE(std::is_same<const long&, F::Arg<1>::type>::value); // NOLINT
  EXPECT_TRUE(std::is_same<std::tuple<bool, const long&>,         // NOLINT
                           F::ArgumentTuple>::value);
  EXPECT_TRUE(
      std::is_same<std::tuple<Matcher<bool>, Matcher<const long&>>, // NOLINT
                   F::ArgumentMatcherTuple>::value);
  EXPECT_TRUE(std::is_same<void(bool, const long&), // NOLINT
                           F::MakeResultVoid>::value);
  EXPECT_TRUE(std::is_same<IgnoredValue(bool, const long&), // NOLINT
                           F::MakeResultIgnoredValue>::value);
}

auto TEST(FunctionTest, LongArgumentList)
->
  {
  using F = Function<char(bool, int, char*, int&, const long&)>;  // NOLINT
  EXPECT_EQ(5u, F::ArgumentCount);
  EXPECT_TRUE(std::is_same<char, F::Result>::value);
  EXPECT_TRUE(std::is_same<bool, F::Arg<0>::type>::value);
  EXPECT_TRUE(std::is_same<int, F::Arg<1>::type>::value);
  EXPECT_TRUE(std::is_same<char*, F::Arg<2>::type>::value);
  EXPECT_TRUE(std::is_same<int&, F::Arg<3>::type>::value);
  EXPECT_TRUE(std::is_same<const long&, F::Arg<4>::type>::value);  // NOLINT
  EXPECT_TRUE(
      std::is_same<std::tuple<bool, int, char*, int&, const long&>, // NOLINT
                   F::ArgumentTuple>::value);
  EXPECT_TRUE(
      std::is_same<
        std::tuple<Matcher<bool>, Matcher<int>, Matcher<char*>, Matcher<int&>,
                   Matcher<const long&>>, // NOLINT
        F::ArgumentMatcherTuple>::value);
  EXPECT_TRUE(
      std::is_same<void(bool, int, char*, int&, const long&), // NOLINT
                   F::MakeResultVoid>::value);
  EXPECT_TRUE(std::is_same<IgnoredValue(bool, int, char*, int&, const long&),  // NOLINT
                           F::MakeResultIgnoredValue>::value);
}

} // namespace
} // namespace internal
} // namespace testing
