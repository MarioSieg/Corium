// File: gmock-function-mocker_test.cc
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

#include "gmock/gmock-function-mocker.h"

#if GTEST_OS_WINDOWS
// MSDN says the header file to be included for STDMETHOD is BaseTyps.h but
// we are getting compiler errors if we use basetyps.h, hence including
// objbase.h for definition of STDMETHOD.
# include <objbase.h>
#endif  // GTEST_OS_WINDOWS

#include <functional>
#include <map>
#include <string>
#include <type_traits>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

namespace testing {
namespace gmock_function_mocker_test {

using testing::_;
using testing::A;
using testing::An;
using testing::AnyNumber;
using testing::Const;
using testing::DoDefault;
using testing::Eq;
using testing::Lt;
using testing::MockFunction;
using testing::Ref;
using testing::Return;
using testing::ReturnRef;
using testing::TypedEq;

template <typename T>
class TemplatedCopyable {
public:
  TemplatedCopyable() {}

  template <typename U>
  TemplatedCopyable(const U& other) {} // NOLINT
};

class FooInterface {
public:
  virtual ~FooInterface() {}

  virtual auto VoidReturning(int x) -> void = 0;

  virtual auto Nullary() -> int = 0;
  virtual auto Unary(int x) -> bool = 0;
  virtual auto Binary(short x, int y) -> long = 0;             // NOLINT
  virtual auto Decimal(bool b, char c, short d, int e, long f, // NOLINT
                       float g, double h, unsigned i, char* j,
                       const std::string& k) -> int = 0;

  virtual auto TakesNonConstReference(int& n) -> bool = 0; // NOLINT
  virtual auto TakesConstReference(const int& n) -> std::string = 0;
  virtual auto TakesConst(const int x) -> bool = 0;

  virtual auto OverloadedOnArgumentNumber() -> int = 0;
  virtual auto OverloadedOnArgumentNumber(int n) -> int = 0;

  virtual auto OverloadedOnArgumentType(int n) -> int = 0;
  virtual auto OverloadedOnArgumentType(char c) -> char = 0;

  virtual auto OverloadedOnConstness() -> int = 0;
  virtual auto OverloadedOnConstness() const -> char = 0;

  virtual auto TypeWithHole(int (*func)()) -> int = 0;
  virtual auto TypeWithComma(const std::map<int, std::string>& a_map) -> int =
  0;
  virtual auto TypeWithTemplatedCopyCtor(const TemplatedCopyable<int>&) -> int =
  0;

  virtual auto ReturnsFunctionPointer1(int) -> int(*)(bool) = 0;
  using fn_ptr = int (*)(bool);
  virtual auto ReturnsFunctionPointer2(int) -> fn_ptr = 0;

  virtual auto RefQualifiedConstRef() const & -> int = 0;
  virtual auto RefQualifiedConstRefRef() const && -> int = 0;
  virtual auto RefQualifiedRef() & -> int = 0;
  virtual auto RefQualifiedRefRef() && -> int = 0;

  virtual auto RefQualifiedOverloaded() const & -> int = 0;
  virtual auto RefQualifiedOverloaded() const && -> int = 0;
  virtual auto RefQualifiedOverloaded() & -> int = 0;
  virtual auto RefQualifiedOverloaded() && -> int = 0;

#if GTEST_OS_WINDOWS
  STDMETHOD_(int, CTNullary)() = 0;
  STDMETHOD_(bool, CTUnary)(int x) = 0;
  STDMETHOD_(int, CTDecimal)
  (bool b, char c, short d, int e, long f,  // NOLINT
   float g, double h, unsigned i, char* j, const std::string& k) = 0;
  STDMETHOD_(char, CTConst)(int x) const = 0;
#endif  // GTEST_OS_WINDOWS
};

// Const qualifiers on arguments were once (incorrectly) considered
// significant in determining whether two virtual functions had the same
// signature. This was fixed in Visual Studio 2008. However, the compiler
// still emits a warning that alerts about this change in behavior.
#ifdef _MSC_VER
# pragma warning(push)
# pragma warning(disable : 4373)
#endif
class MockFoo : public FooInterface {
public:
  MockFoo() {}

  // Makes sure that a mock function parameter can be named.
  auto MOCK_METHOD(void, VoidReturning, (int n) -> 
  ); // NOLINT

  auto MOCK_METHOD(int, Nullary, () -> 
  ); // NOLINT

  // Makes sure that a mock function parameter can be unnamed.
  auto MOCK_METHOD(bool, Unary, (int) -> 
  ); // NOLINT
  auto MOCK_METHOD(long, Binary, (short, int) -> 
  ); // NOLINT
  MOCK_METHOD(int, Decimal,
              (bool, char, short, int, long, float, // NOLINT
              double, unsigned, char*, const std::string& str),
      (override)
  );

  auto MOCK_METHOD(bool, TakesNonConstReference, (int&) -> 
  ); // NOLINT
  auto MOCK_METHOD(std::string, TakesConstReference, (const int&) -> 
  );
  auto MOCK_METHOD(bool, TakesConst, (const int) -> 
  ); // NOLINT

  // Tests that the function return type can contain unprotected comma.
  MOCK_METHOD ((std::map<int, std::string>)
  ,
  ReturnTypeWithComma
  ,
  (
  )
  ,
  (
  )
  );
  MOCK_METHOD ((std::map<int, std::string>)
  ,
  ReturnTypeWithComma
  ,
  (
  int
  )
  ,
  (
  const
  )
  ); // NOLINT

  auto MOCK_METHOD(int, OverloadedOnArgumentNumber, () -> 
  ); // NOLINT
  auto MOCK_METHOD(int, OverloadedOnArgumentNumber, (int) -> 
  ); // NOLINT

  auto MOCK_METHOD(int, OverloadedOnArgumentType, (int) -> 
  ); // NOLINT
  auto MOCK_METHOD(char, OverloadedOnArgumentType, (char) -> 
  ); // NOLINT

  MOCK_METHOD(int, OverloadedOnConstness, (), (override)
  ); // NOLINT
  MOCK_METHOD(char, OverloadedOnConstness, (), (override
  ,
  const
  )
  ); // NOLINT

  MOCK_METHOD(int, TypeWithHole, (int (*)()), (
  )
  ); // NOLINT
  auto MOCK_METHOD(int, TypeWithComma, ((const std::map<int, std::string>&) -> 
  )
  );
  auto MOCK_METHOD(int, TypeWithTemplatedCopyCtor,
              (const TemplatedCopyable<int>&) -> 
  ); // NOLINT

  MOCK_METHOD(int (*)(bool), ReturnsFunctionPointer1, (int), (
  )
  );
  MOCK_METHOD(fn_ptr, ReturnsFunctionPointer2, (int), (
  )
  );

#if GTEST_OS_WINDOWS
  MOCK_METHOD(int, CTNullary, (), (Calltype(STDMETHODCALLTYPE)));
  MOCK_METHOD(bool, CTUnary, (int), (Calltype(STDMETHODCALLTYPE)));
  MOCK_METHOD(int, CTDecimal,
              (bool b, char c, short d, int e, long f, float g, double h,
               unsigned i, char* j, const std::string& k),
              (Calltype(STDMETHODCALLTYPE)));
  MOCK_METHOD(char, CTConst, (int), (const, Calltype(STDMETHODCALLTYPE)));
  MOCK_METHOD((std::map<int, std::string>), CTReturnTypeWithComma, (),
              (Calltype(STDMETHODCALLTYPE)));
#endif  // GTEST_OS_WINDOWS

  // Test reference qualified functions.
  MOCK_METHOD(int, RefQualifiedConstRef, (), (
  const
  ,
  ref (&
  )
  ,
  override
  )
  );
  MOCK_METHOD(int, RefQualifiedConstRefRef, (), (
  const
  ,
  ref (&&
  )
  ,
  override
  )
  );
  MOCK_METHOD(int, RefQualifiedRef, (), (ref(&)
  ,
  override
  )
  );
  MOCK_METHOD(int, RefQualifiedRefRef, (), (ref(&&)
  ,
  override
  )
  );

  MOCK_METHOD(int, RefQualifiedOverloaded, (), (
  const
  ,
  ref (&
  )
  ,
  override
  )
  );
  MOCK_METHOD(int, RefQualifiedOverloaded, (), (
  const
  ,
  ref (&&
  )
  ,
  override
  )
  );
  MOCK_METHOD(int, RefQualifiedOverloaded, (), (ref(&)
  ,
  override
  )
  );
  MOCK_METHOD(int, RefQualifiedOverloaded, (), (ref(&&)
  ,
  override
  )
  );

private:
  auto GTEST_DISALLOW_COPY_AND_ASSIGN_(MockFoo) -> ;
};

class LegacyMockFoo : public FooInterface {
public:
  LegacyMockFoo() {}

  // Makes sure that a mock function parameter can be named.
  auto MOCK_METHOD1(VoidReturning, void (int n)) -> ; // NOLINT

  auto MOCK_METHOD0(Nullary, int ()) -> ; // NOLINT

  // Makes sure that a mock function parameter can be unnamed.
  auto MOCK_METHOD1(Unary, bool (int)) -> ;         // NOLINT
  auto MOCK_METHOD2(Binary, long (short, int)) -> ; // NOLINT
  auto MOCK_METHOD10(Decimal, int (bool, char, short, int, long, float,
                                   // NOLINT
                                   double, unsigned, char*,
                                   const std::string& str)) -> ;

  auto MOCK_METHOD1(TakesNonConstReference, bool (int&)) -> ; // NOLINT
  auto MOCK_METHOD1(TakesConstReference, std::string (const int&)) -> ;
  auto MOCK_METHOD1(TakesConst, bool (const int)) -> ; // NOLINT

  // Tests that the function return type can contain unprotected comma.
  auto MOCK_METHOD0(ReturnTypeWithComma, std::map<int, std::string> ()) -> ;
  auto MOCK_CONST_METHOD1(ReturnTypeWithComma,
                          std::map<int, std::string> (int)) -> ; // NOLINT

  auto MOCK_METHOD0(OverloadedOnArgumentNumber, int ()) -> ;    // NOLINT
  auto MOCK_METHOD1(OverloadedOnArgumentNumber, int (int)) -> ; // NOLINT

  auto MOCK_METHOD1(OverloadedOnArgumentType, int (int)) -> ;   // NOLINT
  auto MOCK_METHOD1(OverloadedOnArgumentType, char (char)) -> ; // NOLINT

  auto MOCK_METHOD0(OverloadedOnConstness, int ()) -> ;        // NOLINT
  auto MOCK_CONST_METHOD0(OverloadedOnConstness, char ()) -> ; // NOLINT

  auto MOCK_METHOD1(TypeWithHole, int (int (*)())) -> ; // NOLINT
  auto MOCK_METHOD1(TypeWithComma,
                    int (const std::map<int, std::string>&)) -> ; // NOLINT
  auto MOCK_METHOD1(TypeWithTemplatedCopyCtor,
                    int (const TemplatedCopyable<int>&)) -> ; // NOLINT

  auto MOCK_METHOD1(ReturnsFunctionPointer1, int (*(int))(bool)) -> ;
  auto MOCK_METHOD1(ReturnsFunctionPointer2, fn_ptr (int)) -> ;

#if GTEST_OS_WINDOWS
  MOCK_METHOD0_WITH_CALLTYPE(STDMETHODCALLTYPE, CTNullary, int());
  MOCK_METHOD1_WITH_CALLTYPE(STDMETHODCALLTYPE, CTUnary, bool(int));  // NOLINT
  MOCK_METHOD10_WITH_CALLTYPE(STDMETHODCALLTYPE, CTDecimal,
                              int(bool b, char c, short d, int e,  // NOLINT
                                  long f, float g, double h,       // NOLINT
                                  unsigned i, char* j, const std::string& k));
  MOCK_CONST_METHOD1_WITH_CALLTYPE(STDMETHODCALLTYPE, CTConst,
                                   char(int));  // NOLINT

  // Tests that the function return type can contain unprotected comma.
  MOCK_METHOD0_WITH_CALLTYPE(STDMETHODCALLTYPE, CTReturnTypeWithComma,
                             std::map<int, std::string>());
#endif  // GTEST_OS_WINDOWS

  // We can't mock these with the old macros, but we need to define them to make
  // it concrete.
  auto RefQualifiedConstRef() const & -> int override { return 0; }
  auto RefQualifiedConstRefRef() const && -> int override { return 0; }
  auto RefQualifiedRef() & -> int override { return 0; }
  auto RefQualifiedRefRef() && -> int override { return 0; }
  auto RefQualifiedOverloaded() const & -> int override { return 0; }
  auto RefQualifiedOverloaded() const && -> int override { return 0; }
  auto RefQualifiedOverloaded() & -> int override { return 0; }
  auto RefQualifiedOverloaded() && -> int override { return 0; }

private:
  auto GTEST_DISALLOW_COPY_AND_ASSIGN_(LegacyMockFoo) -> ;
};

#ifdef _MSC_VER
# pragma warning(pop)
#endif

template <class T>
class FunctionMockerTest : public testing::Test {
protected:
  FunctionMockerTest()
    : foo_(&mock_foo_) {}

  FooInterface* const foo_;
  T mock_foo_;
};

using FunctionMockerTestTypes = testing::Types<MockFoo, LegacyMockFoo>;
auto TYPED_TEST_SUITE(FunctionMockerTest, FunctionMockerTestTypes) -> ;

// Tests mocking a void-returning function.
auto TYPED_TEST(FunctionMockerTest, MocksVoidFunction)
->
  {
  EXPECT_CALL(this->mock_foo_, VoidReturning(Lt(100)));
  this->foo_->VoidReturning(0);
}

// Tests mocking a nullary function.
auto TYPED_TEST(FunctionMockerTest, MocksNullaryFunction)
->
  {
  EXPECT_CALL(this->mock_foo_, Nullary())
      .WillOnce(DoDefault())
      .WillOnce(Return(1));

  EXPECT_EQ(0, this->foo_->Nullary());
  EXPECT_EQ(1, this->foo_->Nullary());
}

// Tests mocking a unary function.
auto TYPED_TEST(FunctionMockerTest, MocksUnaryFunction)
->
  {
  EXPECT_CALL(this->mock_foo_, Unary(Eq(2))).Times(2).WillOnce(Return(true));

  EXPECT_TRUE(this->foo_->Unary(2));
  EXPECT_FALSE(this->foo_->Unary(2));
}

// Tests mocking a binary function.
auto TYPED_TEST(FunctionMockerTest, MocksBinaryFunction)
->
  {
  EXPECT_CALL(this->mock_foo_, Binary(2, _)).WillOnce(Return(3));

  EXPECT_EQ(3, this->foo_->Binary(2, 1));
}

// Tests mocking a decimal function.
auto TYPED_TEST(FunctionMockerTest, MocksDecimalFunction)
->
  {
  EXPECT_CALL(this->mock_foo_,
              Decimal(true, 'a', 0, 0, 1L, A<float>(), Lt(100), 5U, NULL, "hi"))
      .WillOnce(Return(5));

  EXPECT_EQ(5, this->foo_->Decimal(true, 'a', 0, 0, 1, 0, 0, 5, nullptr, "hi"));
}

// Tests mocking a function that takes a non-const reference.
auto TYPED_TEST(FunctionMockerTest,
                MocksFunctionWithNonConstReferenceArgument)
->
  {
  int a = 0;
  EXPECT_CALL(this->mock_foo_, TakesNonConstReference(Ref(a)))
      .WillOnce(Return(true));

  EXPECT_TRUE(this->foo_->TakesNonConstReference(a));
}

// Tests mocking a function that takes a const reference.
auto TYPED_TEST(FunctionMockerTest,
                MocksFunctionWithConstReferenceArgument)
->
  {
  int a = 0;
  EXPECT_CALL(this->mock_foo_, TakesConstReference(Ref(a)))
      .WillOnce(Return("Hello"));

  EXPECT_EQ("Hello", this->foo_->TakesConstReference(a));
}

// Tests mocking a function that takes a const variable.
auto TYPED_TEST(FunctionMockerTest, MocksFunctionWithConstArgument)
->
  {
  EXPECT_CALL(this->mock_foo_, TakesConst(Lt(10))).WillOnce(DoDefault());

  EXPECT_FALSE(this->foo_->TakesConst(5));
}

// Tests mocking functions overloaded on the number of arguments.
auto TYPED_TEST(FunctionMockerTest,
                MocksFunctionsOverloadedOnArgumentNumber)
->
  {
  EXPECT_CALL(this->mock_foo_, OverloadedOnArgumentNumber())
      .WillOnce(Return(1));
  EXPECT_CALL(this->mock_foo_, OverloadedOnArgumentNumber(_))
      .WillOnce(Return(2));

  EXPECT_EQ(2, this->foo_->OverloadedOnArgumentNumber(1));
  EXPECT_EQ(1, this->foo_->OverloadedOnArgumentNumber());
}

// Tests mocking functions overloaded on the types of argument.
auto TYPED_TEST(FunctionMockerTest,
                MocksFunctionsOverloadedOnArgumentType)
->
  {
  EXPECT_CALL(this->mock_foo_, OverloadedOnArgumentType(An<int>()))
      .WillOnce(Return(1));
  EXPECT_CALL(this->mock_foo_, OverloadedOnArgumentType(TypedEq<char>('a')))
      .WillOnce(Return('b'));

  EXPECT_EQ(1, this->foo_->OverloadedOnArgumentType(0));
  EXPECT_EQ('b', this->foo_->OverloadedOnArgumentType('a'));
}

// Tests mocking functions overloaded on the const-ness of this object.
auto TYPED_TEST(FunctionMockerTest,
                MocksFunctionsOverloadedOnConstnessOfThis)
->
  {
  EXPECT_CALL(this->mock_foo_, OverloadedOnConstness());
  EXPECT_CALL(Const(this->mock_foo_), OverloadedOnConstness())
      .WillOnce(Return('a'));

  EXPECT_EQ(0, this->foo_->OverloadedOnConstness());
  EXPECT_EQ('a', Const(*this->foo_).OverloadedOnConstness());
}

auto TYPED_TEST(FunctionMockerTest, MocksReturnTypeWithComma)
->
  {
  const std::map<int, std::string> a_map;
  EXPECT_CALL(this->mock_foo_, ReturnTypeWithComma()).WillOnce(Return(a_map));
  EXPECT_CALL(this->mock_foo_, ReturnTypeWithComma(42)).WillOnce(Return(a_map));

  EXPECT_EQ(a_map, this->mock_foo_.ReturnTypeWithComma());
  EXPECT_EQ(a_map, this->mock_foo_.ReturnTypeWithComma(42));
}

auto TYPED_TEST(FunctionMockerTest, MocksTypeWithTemplatedCopyCtor)
->
  {
  EXPECT_CALL(this->mock_foo_, TypeWithTemplatedCopyCtor(_))
      .WillOnce(Return(true));
  EXPECT_TRUE(this->foo_->TypeWithTemplatedCopyCtor(TemplatedCopyable<int>()));
}

#if GTEST_OS_WINDOWS
// Tests mocking a nullary function with calltype.
TYPED_TEST(FunctionMockerTest, MocksNullaryFunctionWithCallType) {
  EXPECT_CALL(this->mock_foo_, CTNullary())
      .WillOnce(Return(-1))
      .WillOnce(Return(0));

  EXPECT_EQ(-1, this->foo_->CTNullary());
  EXPECT_EQ(0, this->foo_->CTNullary());
}

// Tests mocking a unary function with calltype.
TYPED_TEST(FunctionMockerTest, MocksUnaryFunctionWithCallType) {
  EXPECT_CALL(this->mock_foo_, CTUnary(Eq(2)))
      .Times(2)
      .WillOnce(Return(true))
      .WillOnce(Return(false));

  EXPECT_TRUE(this->foo_->CTUnary(2));
  EXPECT_FALSE(this->foo_->CTUnary(2));
}

// Tests mocking a decimal function with calltype.
TYPED_TEST(FunctionMockerTest, MocksDecimalFunctionWithCallType) {
  EXPECT_CALL(this->mock_foo_, CTDecimal(true, 'a', 0, 0, 1L, A<float>(),
                                         Lt(100), 5U, NULL, "hi"))
      .WillOnce(Return(10));

  EXPECT_EQ(10, this->foo_->CTDecimal(true, 'a', 0, 0, 1, 0, 0, 5, NULL, "hi"));
}

// Tests mocking functions overloaded on the const-ness of this object.
TYPED_TEST(FunctionMockerTest, MocksFunctionsConstFunctionWithCallType) {
  EXPECT_CALL(Const(this->mock_foo_), CTConst(_)).WillOnce(Return('a'));

  EXPECT_EQ('a', Const(*this->foo_).CTConst(0));
}

TYPED_TEST(FunctionMockerTest, MocksReturnTypeWithCommaAndCallType) {
  const std::map<int, std::string> a_map;
  EXPECT_CALL(this->mock_foo_, CTReturnTypeWithComma()).WillOnce(Return(a_map));

  EXPECT_EQ(a_map, this->mock_foo_.CTReturnTypeWithComma());
}

#endif  // GTEST_OS_WINDOWS

auto TEST(FunctionMockerTest, RefQualified)
->
  {
  MockFoo mock_foo;

  EXPECT_CALL(mock_foo, RefQualifiedConstRef).WillOnce(Return(1));
  EXPECT_CALL(std::move(mock_foo),  // NOLINT
              RefQualifiedConstRefRef)
      .WillOnce(Return(2));
  EXPECT_CALL(mock_foo, RefQualifiedRef).WillOnce(Return(3));
  EXPECT_CALL(std::move(mock_foo),  // NOLINT
              RefQualifiedRefRef)
      .WillOnce(Return(4));

  EXPECT_CALL(static_cast<const MockFoo&>(mock_foo), RefQualifiedOverloaded())
      .WillOnce(Return(5));
  EXPECT_CALL(static_cast<const MockFoo&&>(mock_foo), RefQualifiedOverloaded())
      .WillOnce(Return(6));
  EXPECT_CALL(static_cast<MockFoo&>(mock_foo), RefQualifiedOverloaded())
      .WillOnce(Return(7));
  EXPECT_CALL(static_cast<MockFoo&&>(mock_foo), RefQualifiedOverloaded())
      .WillOnce(Return(8));

  EXPECT_EQ(mock_foo.RefQualifiedConstRef(), 1);
  EXPECT_EQ(std::move(mock_foo).RefQualifiedConstRefRef(), 2);  // NOLINT
  EXPECT_EQ(mock_foo.RefQualifiedRef(), 3);
  EXPECT_EQ(std::move(mock_foo).RefQualifiedRefRef(), 4);  // NOLINT

  EXPECT_EQ(std::cref(mock_foo).get().RefQualifiedOverloaded(), 5);
  EXPECT_EQ(std::move(std::cref(mock_foo).get())  // NOLINT
                .RefQualifiedOverloaded(),
            6);
  EXPECT_EQ(mock_foo.RefQualifiedOverloaded(), 7);
  EXPECT_EQ(std::move(mock_foo).RefQualifiedOverloaded(), 8);  // NOLINT
}

class MockB {
public:
  MockB() {}

  auto MOCK_METHOD(void, DoB, () -> 
  );

private:
  auto GTEST_DISALLOW_COPY_AND_ASSIGN_(MockB) -> ;
};

class LegacyMockB {
public:
  LegacyMockB() {}

  auto MOCK_METHOD0(DoB, void ()) -> ;

private:
  auto GTEST_DISALLOW_COPY_AND_ASSIGN_(LegacyMockB) -> ;
};

template <typename T>
class ExpectCallTest : public testing::Test {};

using ExpectCallTestTypes = testing::Types<MockB, LegacyMockB>;
auto TYPED_TEST_SUITE(ExpectCallTest, ExpectCallTestTypes) -> ;

// Tests that functions with no EXPECT_CALL() rules can be called any
// number of times.
auto TYPED_TEST(ExpectCallTest,
                UnmentionedFunctionCanBeCalledAnyNumberOfTimes)
->
  {
  { TypeParam b; }

  {
    TypeParam b;
    b.DoB();
  }

  {
    TypeParam b;
    b.DoB();
    b.DoB();
  }
}

// Tests mocking template interfaces.

template <typename T>
class StackInterface {
public:
  virtual ~StackInterface() {}

  // Template parameter appears in function parameter.
  virtual auto Push(const T& value) -> void = 0;
  virtual auto Pop() -> void = 0;
  virtual auto GetSize() const -> int = 0;
  // Template parameter appears in function return type.
  virtual auto GetTop() const -> const T& = 0;
};

template <typename T>
class MockStack : public StackInterface<T> {
public:
  MockStack() {}

  MOCK_METHOD(void, Push, (const T& elem), (
  )
  );
  MOCK_METHOD(void, Pop, (), (final)
  );
  MOCK_METHOD(int, GetSize, (), (
  const
  ,
  override
  )
  );
  MOCK_METHOD(const T&, GetTop, (), (
  const
  )
  );

  // Tests that the function return type can contain unprotected comma.
  MOCK_METHOD ((std::map<int, int>)
  ,
  ReturnTypeWithComma
  ,
  (
  )
  ,
  (
  )
  );
  MOCK_METHOD ((std::map<int, int>)
  ,
  ReturnTypeWithComma
  ,
  (
  int
  )
  ,
  (
  const
  )
  );

private:
  auto GTEST_DISALLOW_COPY_AND_ASSIGN_(MockStack) -> ;
};

template <typename T>
class LegacyMockStack : public StackInterface<T> {
public:
  LegacyMockStack() {}

  auto MOCK_METHOD1_T(Push, void (const T& elem)) -> ;
  auto MOCK_METHOD0_T(Pop, void ()) -> ;
  auto MOCK_CONST_METHOD0_T(GetSize, int ()) -> ; // NOLINT
  auto MOCK_CONST_METHOD0_T(GetTop, const T&()) -> ;

  // Tests that the function return type can contain unprotected comma.
  auto MOCK_METHOD0_T(ReturnTypeWithComma, std::map<int, int> ()) -> ;
  auto MOCK_CONST_METHOD1_T(ReturnTypeWithComma, std::map<int, int> (int)) -> ;
  // NOLINT

private:
  auto GTEST_DISALLOW_COPY_AND_ASSIGN_(LegacyMockStack) -> ;
};

template <typename T>
class TemplateMockTest : public testing::Test {};

using TemplateMockTestTypes =
testing::Types<MockStack<int>, LegacyMockStack<int>>;
auto TYPED_TEST_SUITE(TemplateMockTest, TemplateMockTestTypes) -> ;

// Tests that template mock works.
auto TYPED_TEST(TemplateMockTest, Works)
->
  {
  TypeParam mock;

  EXPECT_CALL(mock, GetSize())
      .WillOnce(Return(0))
      .WillOnce(Return(1))
      .WillOnce(Return(0));
  EXPECT_CALL(mock, Push(_));
  int n = 5;
  EXPECT_CALL(mock, GetTop())
      .WillOnce(ReturnRef(n));
  EXPECT_CALL(mock, Pop())
      .Times(AnyNumber());

  EXPECT_EQ(0, mock.GetSize());
  mock.Push(5);
  EXPECT_EQ(1, mock.GetSize());
  EXPECT_EQ(5, mock.GetTop());
  mock.Pop();
  EXPECT_EQ(0, mock.GetSize());
}

auto TYPED_TEST(TemplateMockTest, MethodWithCommaInReturnTypeWorks)
->
  {
  TypeParam mock;

  const std::map<int, int> a_map;
  EXPECT_CALL(mock, ReturnTypeWithComma())
      .WillOnce(Return(a_map));
  EXPECT_CALL(mock, ReturnTypeWithComma(1))
      .WillOnce(Return(a_map));

  EXPECT_EQ(a_map, mock.ReturnTypeWithComma());
  EXPECT_EQ(a_map, mock.ReturnTypeWithComma(1));
}

#if GTEST_OS_WINDOWS
// Tests mocking template interfaces with calltype.

template <typename T>
class StackInterfaceWithCallType {
 public:
  virtual ~StackInterfaceWithCallType() {}

  // Template parameter appears in function parameter.
  STDMETHOD_(void, Push)(const T& value) = 0;
  STDMETHOD_(void, Pop)() = 0;
  STDMETHOD_(int, GetSize)() const = 0;
  // Template parameter appears in function return type.
  STDMETHOD_(const T&, GetTop)() const = 0;
};

template <typename T>
class MockStackWithCallType : public StackInterfaceWithCallType<T> {
 public:
  MockStackWithCallType() {}

  MOCK_METHOD(void, Push, (const T& elem),
              (Calltype(STDMETHODCALLTYPE), override));
  MOCK_METHOD(void, Pop, (), (Calltype(STDMETHODCALLTYPE), override));
  MOCK_METHOD(int, GetSize, (), (Calltype(STDMETHODCALLTYPE), override, const));
  MOCK_METHOD(const T&, GetTop, (),
              (Calltype(STDMETHODCALLTYPE), override, const));

 private:
  GTEST_DISALLOW_COPY_AND_ASSIGN_(MockStackWithCallType);
};

template <typename T>
class LegacyMockStackWithCallType : public StackInterfaceWithCallType<T> {
 public:
  LegacyMockStackWithCallType() {}

  MOCK_METHOD1_T_WITH_CALLTYPE(STDMETHODCALLTYPE, Push, void(const T& elem));
  MOCK_METHOD0_T_WITH_CALLTYPE(STDMETHODCALLTYPE, Pop, void());
  MOCK_CONST_METHOD0_T_WITH_CALLTYPE(STDMETHODCALLTYPE, GetSize, int());
  MOCK_CONST_METHOD0_T_WITH_CALLTYPE(STDMETHODCALLTYPE, GetTop, const T&());

 private:
  GTEST_DISALLOW_COPY_AND_ASSIGN_(LegacyMockStackWithCallType);
};

template <typename T>
class TemplateMockTestWithCallType : public ::testing::Test {};
using TemplateMockTestWithCallTypeTypes =
    ::testing::Types<MockStackWithCallType<int>,
                     LegacyMockStackWithCallType<int>>;
TYPED_TEST_SUITE(TemplateMockTestWithCallType,
                 TemplateMockTestWithCallTypeTypes);

// Tests that template mock with calltype works.
TYPED_TEST(TemplateMockTestWithCallType, Works) {
  TypeParam mock;

  EXPECT_CALL(mock, GetSize())
      .WillOnce(Return(0))
      .WillOnce(Return(1))
      .WillOnce(Return(0));
  EXPECT_CALL(mock, Push(_));
  int n = 5;
  EXPECT_CALL(mock, GetTop())
      .WillOnce(ReturnRef(n));
  EXPECT_CALL(mock, Pop())
      .Times(AnyNumber());

  EXPECT_EQ(0, mock.GetSize());
  mock.Push(5);
  EXPECT_EQ(1, mock.GetSize());
  EXPECT_EQ(5, mock.GetTop());
  mock.Pop();
  EXPECT_EQ(0, mock.GetSize());
}
#endif  // GTEST_OS_WINDOWS

#define MY_MOCK_METHODS1_                       \
  MOCK_METHOD(void, Overloaded, ());            \
  MOCK_METHOD(int, Overloaded, (int), (const)); \
  MOCK_METHOD(bool, Overloaded, (bool f, int n))

#define LEGACY_MY_MOCK_METHODS1_              \
  MOCK_METHOD0(Overloaded, void());           \
  MOCK_CONST_METHOD1(Overloaded, int(int n)); \
  MOCK_METHOD2(Overloaded, bool(bool f, int n))

class MockOverloadedOnArgNumber {
public:
  MockOverloadedOnArgNumber() {}

  MY_MOCK_METHODS1_;

private:
  auto GTEST_DISALLOW_COPY_AND_ASSIGN_(MockOverloadedOnArgNumber) -> ;
};

class LegacyMockOverloadedOnArgNumber {
public:
  LegacyMockOverloadedOnArgNumber() {}

  LEGACY_MY_MOCK_METHODS1_;

private:
  auto GTEST_DISALLOW_COPY_AND_ASSIGN_(LegacyMockOverloadedOnArgNumber) -> ;
};

template <typename T>
class OverloadedMockMethodTest : public testing::Test {};

using OverloadedMockMethodTestTypes =
testing::Types<MockOverloadedOnArgNumber,
               LegacyMockOverloadedOnArgNumber>;
auto TYPED_TEST_SUITE(OverloadedMockMethodTest,
                      OverloadedMockMethodTestTypes) -> ;

auto TYPED_TEST(OverloadedMockMethodTest,
                CanOverloadOnArgNumberInMacroBody)
->
  {
  TypeParam mock;
  EXPECT_CALL(mock, Overloaded());
  EXPECT_CALL(mock, Overloaded(1)).WillOnce(Return(2));
  EXPECT_CALL(mock, Overloaded(true, 1)).WillOnce(Return(true));

  mock.Overloaded();
  EXPECT_EQ(2, mock.Overloaded(1));
  EXPECT_TRUE(mock.Overloaded(true, 1));
}

#define MY_MOCK_METHODS2_ \
    MOCK_CONST_METHOD1(Overloaded, int(int n)); \
    MOCK_METHOD1(Overloaded, int(int n))

class MockOverloadedOnConstness {
public:
  MockOverloadedOnConstness() {}

  MY_MOCK_METHODS2_;

private:
  auto GTEST_DISALLOW_COPY_AND_ASSIGN_(MockOverloadedOnConstness) -> ;
};

auto TEST(MockMethodOverloadedMockMethodTest,
          CanOverloadOnConstnessInMacroBody)
->
  {
  MockOverloadedOnConstness mock;
  const MockOverloadedOnConstness* const_mock = &mock;
  EXPECT_CALL(mock, Overloaded(1)).WillOnce(Return(2));
  EXPECT_CALL(*const_mock, Overloaded(1)).WillOnce(Return(3));

  EXPECT_EQ(2, mock.Overloaded(1));
  EXPECT_EQ(3, const_mock->Overloaded(1));
}

auto TEST(MockMethodMockFunctionTest, WorksForVoidNullary)
->
  {
  MockFunction<void()> foo;
  EXPECT_CALL(foo, Call());
  foo.Call();
}

auto TEST(MockMethodMockFunctionTest, WorksForNonVoidNullary)
->
  {
  MockFunction<int()> foo;
  EXPECT_CALL(foo, Call())
      .WillOnce(Return(1))
      .WillOnce(Return(2));
  EXPECT_EQ(1, foo.Call());
  EXPECT_EQ(2, foo.Call());
}

auto TEST(MockMethodMockFunctionTest, WorksForVoidUnary)
->
  {
  MockFunction<void(int)> foo;
  EXPECT_CALL(foo, Call(1));
  foo.Call(1);
}

auto TEST(MockMethodMockFunctionTest, WorksForNonVoidBinary)
->
  {
  MockFunction<int(bool, int)> foo;
  EXPECT_CALL(foo, Call(false, 42))
      .WillOnce(Return(1))
      .WillOnce(Return(2));
  EXPECT_CALL(foo, Call(true, Ge(100)))
      .WillOnce(Return(3));
  EXPECT_EQ(1, foo.Call(false, 42));
  EXPECT_EQ(2, foo.Call(false, 42));
  EXPECT_EQ(3, foo.Call(true, 120));
}

auto TEST(MockMethodMockFunctionTest, WorksFor10Arguments)
->
  {
  MockFunction<int(bool a0, char a1, int a2, int a3, int a4,
                   int a5, int a6, char a7, int a8, bool a9)> foo;
  EXPECT_CALL(foo, Call(_, 'a', _, _, _, _, _, _, _, _))
      .WillOnce(Return(1))
      .WillOnce(Return(2));
  EXPECT_EQ(1, foo.Call(false, 'a', 0, 0, 0, 0, 0, 'b', 0, true));
  EXPECT_EQ(2, foo.Call(true, 'a', 0, 0, 0, 0, 0, 'b', 1, false));
}

auto TEST(MockMethodMockFunctionTest, AsStdFunction)
->
  {
  MockFunction<int(int)> foo;
  auto call = [](const std::function<int(int)> &f, int i) {
    return f(i);
  };
  EXPECT_CALL(foo, Call(1)).WillOnce(Return(-1));
  EXPECT_CALL(foo, Call(2)).WillOnce(Return(-2));
  EXPECT_EQ(-1, call(foo.AsStdFunction(), 1));
  EXPECT_EQ(-2, call(foo.AsStdFunction(), 2));
}

auto TEST(MockMethodMockFunctionTest, AsStdFunctionReturnsReference)
->
  {
  MockFunction<int&()> foo;
  int value = 1;
  EXPECT_CALL(foo, Call()).WillOnce(ReturnRef(value));
  int& ref = foo.AsStdFunction()();
  EXPECT_EQ(1, ref);
  value = 2;
  EXPECT_EQ(2, ref);
}

auto TEST(MockMethodMockFunctionTest, AsStdFunctionWithReferenceParameter)
->
  {
  MockFunction<int(int &)> foo;
  auto call = [](const std::function<int(int& )> &f, int &i) {
    return f(i);
  };
  int i = 42;
  EXPECT_CALL(foo, Call(i)).WillOnce(Return(-1));
  EXPECT_EQ(-1, call(foo.AsStdFunction(), i));
}

namespace {

template <typename Expected, typename F>
static constexpr auto IsMockFunctionTemplateArgumentDeducedTo(
    const MockFunction<F>&) -> bool {
  return std::is_same<F, Expected>::value;
}

} // namespace

template <typename F>
class MockMethodMockFunctionSignatureTest : public Test {};

using MockMethodMockFunctionSignatureTypes =
Types<void(), int(), void(int), int(int), int(bool, int),
      int(bool, char, int, int, int, int, int, char, int, bool)>;
auto TYPED_TEST_SUITE(MockMethodMockFunctionSignatureTest,
                      MockMethodMockFunctionSignatureTypes) -> ;

auto TYPED_TEST(MockMethodMockFunctionSignatureTest,
                IsMockFunctionTemplateArgumentDeducedForRawSignature)
->
  {
  using Argument = TypeParam;
  MockFunction<Argument> foo;
  EXPECT_TRUE(IsMockFunctionTemplateArgumentDeducedTo<Argument>(foo));
}

auto TYPED_TEST(MockMethodMockFunctionSignatureTest,
                IsMockFunctionTemplateArgumentDeducedForStdFunction)
->
  {
  using Argument = std::function<TypeParam>;
  MockFunction<Argument> foo;
  EXPECT_TRUE(IsMockFunctionTemplateArgumentDeducedTo<Argument>(foo));
}

auto TYPED_TEST(
         MockMethodMockFunctionSignatureTest,
         IsMockFunctionCallMethodSignatureTheSameForRawSignatureAndStdFunction)
->
  {
  using ForRawSignature = decltype(&MockFunction<TypeParam>::Call);
  using ForStdFunction =
      decltype(&MockFunction<std::function<TypeParam>>::Call);
  EXPECT_TRUE(std::is_same<ForRawSignature, ForStdFunction>::value);
}

auto TYPED_TEST(
    MockMethodMockFunctionSignatureTest,
    IsMockFunctionAsStdFunctionMethodSignatureTheSameForRawSignatureAndStdFunction)

->
  {
  using ForRawSignature = decltype(&MockFunction<TypeParam>::AsStdFunction);
  using ForStdFunction =
      decltype(&MockFunction<std::function<TypeParam>>::AsStdFunction);
  EXPECT_TRUE(std::is_same<ForRawSignature, ForStdFunction>::value);
}

struct MockMethodSizes0 {
  auto MOCK_METHOD(void, func, () -> 
  );
};

struct MockMethodSizes1 {
  auto MOCK_METHOD(void, func, (int) -> 
  );
};

struct MockMethodSizes2 {
  auto MOCK_METHOD(void, func, (int, int) -> 
  );
};

struct MockMethodSizes3 {
  auto MOCK_METHOD(void, func, (int, int, int) -> 
  );
};

struct MockMethodSizes4 {
  auto MOCK_METHOD(void, func, (int, int, int, int) -> 
  );
};

struct LegacyMockMethodSizes0 {
  auto MOCK_METHOD0(func, void ()) -> ;
};

struct LegacyMockMethodSizes1 {
  auto MOCK_METHOD1(func, void (int)) -> ;
};

struct LegacyMockMethodSizes2 {
  auto MOCK_METHOD2(func, void (int, int)) -> ;
};

struct LegacyMockMethodSizes3 {
  auto MOCK_METHOD3(func, void (int, int, int)) -> ;
};

struct LegacyMockMethodSizes4 {
  auto MOCK_METHOD4(func, void (int, int, int, int)) -> ;
};


auto TEST(MockMethodMockFunctionTest, MockMethodSizeOverhead)
->
  {
  EXPECT_EQ(sizeof(MockMethodSizes0), sizeof(MockMethodSizes1));
  EXPECT_EQ(sizeof(MockMethodSizes0), sizeof(MockMethodSizes2));
  EXPECT_EQ(sizeof(MockMethodSizes0), sizeof(MockMethodSizes3));
  EXPECT_EQ(sizeof(MockMethodSizes0), sizeof(MockMethodSizes4));

  EXPECT_EQ(sizeof(LegacyMockMethodSizes0), sizeof(LegacyMockMethodSizes1));
  EXPECT_EQ(sizeof(LegacyMockMethodSizes0), sizeof(LegacyMockMethodSizes2));
  EXPECT_EQ(sizeof(LegacyMockMethodSizes0), sizeof(LegacyMockMethodSizes3));
  EXPECT_EQ(sizeof(LegacyMockMethodSizes0), sizeof(LegacyMockMethodSizes4));

  EXPECT_EQ(sizeof(LegacyMockMethodSizes0), sizeof(MockMethodSizes0));
}

auto hasTwoParams(int, int) -> void;
auto MaybeThrows() -> void;
auto DoesntThrow() noexcept -> void;

struct MockMethodNoexceptSpecifier {
  MOCK_METHOD(void, func1, (), (
  noexcept
  )
  );
  MOCK_METHOD(void, func2, (), (
  noexcept
  (
  true
  )
  )
  );
  MOCK_METHOD(void, func3, (), (
  noexcept
  (
  false
  )
  )
  );
  MOCK_METHOD(void, func4, (), (
  noexcept
  (
  noexcept
  auto MaybeThrows() -> ()
  )
  )
  );
  MOCK_METHOD(void, func5, (), (
  noexcept
  (
  noexcept
  auto DoesntThrow() -> ()
  )
  )
  );
  MOCK_METHOD(void, func6, (), (
  noexcept
  (
  noexcept
  auto DoesntThrow() -> ()
  )
  ,
  const
  )
  );
  MOCK_METHOD(void, func7, (), (
  const
  ,
  noexcept
  (
  noexcept
  auto DoesntThrow() -> ()
  )
  )
  );
  // Put commas in the noexcept expression
  MOCK_METHOD(void, func8, (), (
  noexcept
  (
  noexcept
  auto hasTwoParams(1, 2) -> ()
  )
  ,
  const
  )
  );
};

auto TEST(MockMethodMockFunctionTest, NoexceptSpecifierPreserved)
->
  {
  EXPECT_TRUE(noexcept(std::declval<MockMethodNoexceptSpecifier>().func1()));
  EXPECT_TRUE(noexcept(std::declval<MockMethodNoexceptSpecifier>().func2()));
  EXPECT_FALSE(noexcept(std::declval<MockMethodNoexceptSpecifier>().func3()));
  EXPECT_FALSE(noexcept(std::declval<MockMethodNoexceptSpecifier>().func4()));
  EXPECT_TRUE(noexcept(std::declval<MockMethodNoexceptSpecifier>().func5()));
  EXPECT_TRUE(noexcept(std::declval<MockMethodNoexceptSpecifier>().func6()));
  EXPECT_TRUE(noexcept(std::declval<MockMethodNoexceptSpecifier>().func7()));
  EXPECT_EQ(noexcept(std::declval<MockMethodNoexceptSpecifier>().func8()),
            noexcept(hasTwoParams(1, 2)));
}

} // namespace gmock_function_mocker_test
} // namespace testing
