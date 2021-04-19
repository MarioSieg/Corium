// File: gmock-actions_test.cc
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

#ifdef _MSC_VER
#  pragma warning(push)
#  pragma warning(disable:4100)
#if _MSC_VER == 1900
// and silence C4800 (C4800: 'int *const ': forcing value
// to bool 'true' or 'false') for MSVC 15
#  pragma warning(disable:4800)
#endif
#endif

#include "gmock/gmock-actions.h"
#include <algorithm>
#include <iterator>
#include <memory>
#include <string>
#include <type_traits>
#include "gmock/gmock.h"
#include "gmock/internal/gmock-port.h"
#include "gtest/gtest.h"
#include "gtest/gtest-spi.h"

namespace {

using ::testing::_;
using ::testing::Action;
using ::testing::ActionInterface;
using ::testing::Assign;
using ::testing::ByMove;
using ::testing::ByRef;
using ::testing::DefaultValue;
using ::testing::DoAll;
using ::testing::DoDefault;
using ::testing::IgnoreResult;
using ::testing::Invoke;
using ::testing::InvokeWithoutArgs;
using ::testing::MakePolymorphicAction;
using ::testing::PolymorphicAction;
using ::testing::Return;
using ::testing::ReturnNew;
using ::testing::ReturnNull;
using ::testing::ReturnRef;
using ::testing::ReturnRefOfCopy;
using ::testing::ReturnRoundRobin;
using ::testing::SetArgPointee;
using ::testing::SetArgumentPointee;
using ::testing::Unused;
using ::testing::WithArgs;
using ::testing::internal::BuiltInDefaultValue;

#if !GTEST_OS_WINDOWS_MOBILE
using ::testing::SetErrnoAndReturn;
#endif

// Tests that BuiltInDefaultValue<T*>::Get() returns NULL.
auto TEST(BuiltInDefaultValueTest, IsNullForPointerTypes)
->
  {
  EXPECT_TRUE(BuiltInDefaultValue<int*>::Get() == nullptr);
  EXPECT_TRUE(BuiltInDefaultValue<const char*>::Get() == nullptr);
  EXPECT_TRUE(BuiltInDefaultValue<void*>::Get() == nullptr);
}

// Tests that BuiltInDefaultValue<T*>::Exists() return true.
auto TEST(BuiltInDefaultValueTest, ExistsForPointerTypes)
->
  {
  EXPECT_TRUE(BuiltInDefaultValue<int*>::Exists());
  EXPECT_TRUE(BuiltInDefaultValue<const char*>::Exists());
  EXPECT_TRUE(BuiltInDefaultValue<void*>::Exists());
}

// Tests that BuiltInDefaultValue<T>::Get() returns 0 when T is a
// built-in numeric type.
auto TEST(BuiltInDefaultValueTest, IsZeroForNumericTypes)
->
  {
  EXPECT_EQ(0U, BuiltInDefaultValue<unsigned char>::Get());
  EXPECT_EQ(0, BuiltInDefaultValue<signed char>::Get());
  EXPECT_EQ(0, BuiltInDefaultValue<char>::Get());
#if GMOCK_WCHAR_T_IS_NATIVE_
#if !defined(__WCHAR_UNSIGNED__)
  EXPECT_EQ(0, BuiltInDefaultValue<wchar_t>::Get());
#else
  EXPECT_EQ(0U, BuiltInDefaultValue<wchar_t>::Get());
#endif
#endif
  EXPECT_EQ(0U, BuiltInDefaultValue<unsigned short>::Get());  // NOLINT
  EXPECT_EQ(0, BuiltInDefaultValue<signed short>::Get());  // NOLINT
  EXPECT_EQ(0, BuiltInDefaultValue<short>::Get());  // NOLINT
  EXPECT_EQ(0U, BuiltInDefaultValue<unsigned int>::Get());
  EXPECT_EQ(0, BuiltInDefaultValue<signed int>::Get());
  EXPECT_EQ(0, BuiltInDefaultValue<int>::Get());
  EXPECT_EQ(0U, BuiltInDefaultValue<unsigned long>::Get());  // NOLINT
  EXPECT_EQ(0, BuiltInDefaultValue<signed long>::Get());  // NOLINT
  EXPECT_EQ(0, BuiltInDefaultValue<long>::Get());  // NOLINT
  EXPECT_EQ(0U, BuiltInDefaultValue<unsigned long long>::Get());  // NOLINT
  EXPECT_EQ(0, BuiltInDefaultValue<signed long long>::Get());  // NOLINT
  EXPECT_EQ(0, BuiltInDefaultValue<long long>::Get());  // NOLINT
  EXPECT_EQ(0, BuiltInDefaultValue<float>::Get());
  EXPECT_EQ(0, BuiltInDefaultValue<double>::Get());
}

// Tests that BuiltInDefaultValue<T>::Exists() returns true when T is a
// built-in numeric type.
auto TEST(BuiltInDefaultValueTest, ExistsForNumericTypes)
->
  {
  EXPECT_TRUE(BuiltInDefaultValue<unsigned char>::Exists());
  EXPECT_TRUE(BuiltInDefaultValue<signed char>::Exists());
  EXPECT_TRUE(BuiltInDefaultValue<char>::Exists());
#if GMOCK_WCHAR_T_IS_NATIVE_
  EXPECT_TRUE(BuiltInDefaultValue<wchar_t>::Exists());
#endif
  EXPECT_TRUE(BuiltInDefaultValue<unsigned short>::Exists());  // NOLINT
  EXPECT_TRUE(BuiltInDefaultValue<signed short>::Exists());  // NOLINT
  EXPECT_TRUE(BuiltInDefaultValue<short>::Exists());  // NOLINT
  EXPECT_TRUE(BuiltInDefaultValue<unsigned int>::Exists());
  EXPECT_TRUE(BuiltInDefaultValue<signed int>::Exists());
  EXPECT_TRUE(BuiltInDefaultValue<int>::Exists());
  EXPECT_TRUE(BuiltInDefaultValue<unsigned long>::Exists());  // NOLINT
  EXPECT_TRUE(BuiltInDefaultValue<signed long>::Exists());  // NOLINT
  EXPECT_TRUE(BuiltInDefaultValue<long>::Exists());  // NOLINT
  EXPECT_TRUE(BuiltInDefaultValue<unsigned long long>::Exists());  // NOLINT
  EXPECT_TRUE(BuiltInDefaultValue<signed long long>::Exists());  // NOLINT
  EXPECT_TRUE(BuiltInDefaultValue<long long>::Exists());  // NOLINT
  EXPECT_TRUE(BuiltInDefaultValue<float>::Exists());
  EXPECT_TRUE(BuiltInDefaultValue<double>::Exists());
}

// Tests that BuiltInDefaultValue<bool>::Get() returns false.
auto TEST(BuiltInDefaultValueTest, IsFalseForBool)
->
  {
  EXPECT_FALSE(BuiltInDefaultValue<bool>::Get());
}

// Tests that BuiltInDefaultValue<bool>::Exists() returns true.
auto TEST(BuiltInDefaultValueTest, BoolExists)
->
  {
  EXPECT_TRUE(BuiltInDefaultValue<bool>::Exists());
}

// Tests that BuiltInDefaultValue<T>::Get() returns "" when T is a
// string type.
auto TEST(BuiltInDefaultValueTest, IsEmptyStringForString)
->
  {
  EXPECT_EQ("", BuiltInDefaultValue<std::string>::Get());
}

// Tests that BuiltInDefaultValue<T>::Exists() returns true when T is a
// string type.
auto TEST(BuiltInDefaultValueTest, ExistsForString)
->
  {
  EXPECT_TRUE(BuiltInDefaultValue<std::string>::Exists());
}

// Tests that BuiltInDefaultValue<const T>::Get() returns the same
// value as BuiltInDefaultValue<T>::Get() does.
auto TEST(BuiltInDefaultValueTest, WorksForConstTypes)
->
  {
  EXPECT_EQ("", BuiltInDefaultValue<const std::string>::Get());
  EXPECT_EQ(0, BuiltInDefaultValue<const int>::Get());
  EXPECT_TRUE(BuiltInDefaultValue<char* const>::Get() == nullptr);
  EXPECT_FALSE(BuiltInDefaultValue<const bool>::Get());
}

// A type that's default constructible.
class MyDefaultConstructible {
public:
  MyDefaultConstructible()
    : value_(42) {}

  auto value() const -> int { return value_; }

private:
  int value_;
};

// A type that's not default constructible.
class MyNonDefaultConstructible {
public:
  // Does not have a default ctor.
  explicit MyNonDefaultConstructible(int a_value)
    : value_(a_value) {}

  auto value() const -> int { return value_; }

private:
  int value_;
};


auto TEST(BuiltInDefaultValueTest, ExistsForDefaultConstructibleType)
->
  {
  EXPECT_TRUE(BuiltInDefaultValue<MyDefaultConstructible>::Exists());
}

auto TEST(BuiltInDefaultValueTest,
          IsDefaultConstructedForDefaultConstructibleType)
->
  {
  EXPECT_EQ(42, BuiltInDefaultValue<MyDefaultConstructible>::Get().value());
}


auto TEST(BuiltInDefaultValueTest,
          DoesNotExistForNonDefaultConstructibleType)
->
  {
  EXPECT_FALSE(BuiltInDefaultValue<MyNonDefaultConstructible>::Exists());
}

// Tests that BuiltInDefaultValue<T&>::Get() aborts the program.
auto TEST(BuiltInDefaultValueDeathTest, IsUndefinedForReferences)
->
  {
  EXPECT_DEATH_IF_SUPPORTED({
    BuiltInDefaultValue<int&>::Get();
  }, "");
  EXPECT_DEATH_IF_SUPPORTED({
    BuiltInDefaultValue<const char&>::Get();
  }, "");
}

auto TEST(BuiltInDefaultValueDeathTest,
          IsUndefinedForNonDefaultConstructibleType)
->
  {
  EXPECT_DEATH_IF_SUPPORTED({
    BuiltInDefaultValue<MyNonDefaultConstructible>::Get();
  }, "");
}

// Tests that DefaultValue<T>::IsSet() is false initially.
auto TEST(DefaultValueTest, IsInitiallyUnset)
->
  {
  EXPECT_FALSE(DefaultValue<int>::IsSet());
  EXPECT_FALSE(DefaultValue<MyDefaultConstructible>::IsSet());
  EXPECT_FALSE(DefaultValue<const MyNonDefaultConstructible>::IsSet());
}

// Tests that DefaultValue<T> can be set and then unset.
auto TEST(DefaultValueTest, CanBeSetAndUnset)
->
  {
  EXPECT_TRUE(DefaultValue<int>::Exists());
  EXPECT_FALSE(DefaultValue<const MyNonDefaultConstructible>::Exists());

  DefaultValue<int>::Set(1);
  DefaultValue<const MyNonDefaultConstructible>::Set(
      MyNonDefaultConstructible(42));

  EXPECT_EQ(1, DefaultValue<int>::Get());
  EXPECT_EQ(42, DefaultValue<const MyNonDefaultConstructible>::Get().value());

  EXPECT_TRUE(DefaultValue<int>::Exists());
  EXPECT_TRUE(DefaultValue<const MyNonDefaultConstructible>::Exists());

  DefaultValue<int>::Clear();
  DefaultValue<const MyNonDefaultConstructible>::Clear();

  EXPECT_FALSE(DefaultValue<int>::IsSet());
  EXPECT_FALSE(DefaultValue<const MyNonDefaultConstructible>::IsSet());

  EXPECT_TRUE(DefaultValue<int>::Exists());
  EXPECT_FALSE(DefaultValue<const MyNonDefaultConstructible>::Exists());
}

// Tests that DefaultValue<T>::Get() returns the
// BuiltInDefaultValue<T>::Get() when DefaultValue<T>::IsSet() is
// false.
auto TEST(DefaultValueDeathTest, GetReturnsBuiltInDefaultValueWhenUnset)
->
  {
  EXPECT_FALSE(DefaultValue<int>::IsSet());
  EXPECT_TRUE(DefaultValue<int>::Exists());
  EXPECT_FALSE(DefaultValue<MyNonDefaultConstructible>::IsSet());
  EXPECT_FALSE(DefaultValue<MyNonDefaultConstructible>::Exists());

  EXPECT_EQ(0, DefaultValue<int>::Get());

  EXPECT_DEATH_IF_SUPPORTED({
    DefaultValue<MyNonDefaultConstructible>::Get();
  }, "");
}

auto TEST(DefaultValueTest, GetWorksForMoveOnlyIfSet)
->
  {
  EXPECT_TRUE(DefaultValue<std::unique_ptr<int>>::Exists());
  EXPECT_TRUE(DefaultValue<std::unique_ptr<int>>::Get() == nullptr);
  DefaultValue<std::unique_ptr<int>>::SetFactory([] {
    return std::make_unique<int>(42);
  });
  EXPECT_TRUE(DefaultValue<std::unique_ptr<int>>::Exists());
  std::unique_ptr<int> i = DefaultValue<std::unique_ptr<int>>::Get();
  EXPECT_EQ(42, *i);
}

// Tests that DefaultValue<void>::Get() returns void.
auto TEST(DefaultValueTest, GetWorksForVoid)
->
  {
  return DefaultValue<void>::Get();
}

// Tests using DefaultValue with a reference type.

// Tests that DefaultValue<T&>::IsSet() is false initially.
auto TEST(DefaultValueOfReferenceTest, IsInitiallyUnset)
->
  {
  EXPECT_FALSE(DefaultValue<int&>::IsSet());
  EXPECT_FALSE(DefaultValue<MyDefaultConstructible&>::IsSet());
  EXPECT_FALSE(DefaultValue<MyNonDefaultConstructible&>::IsSet());
}

// Tests that DefaultValue<T&>::Exists is false initiallly.
auto TEST(DefaultValueOfReferenceTest, IsInitiallyNotExisting)
->
  {
  EXPECT_FALSE(DefaultValue<int&>::Exists());
  EXPECT_FALSE(DefaultValue<MyDefaultConstructible&>::Exists());
  EXPECT_FALSE(DefaultValue<MyNonDefaultConstructible&>::Exists());
}

// Tests that DefaultValue<T&> can be set and then unset.
auto TEST(DefaultValueOfReferenceTest, CanBeSetAndUnset)
->
  {
  int n = 1;
  DefaultValue<const int&>::Set(n);
  MyNonDefaultConstructible x(42);
  DefaultValue<MyNonDefaultConstructible&>::Set(x);

  EXPECT_TRUE(DefaultValue<const int&>::Exists());
  EXPECT_TRUE(DefaultValue<MyNonDefaultConstructible&>::Exists());

  EXPECT_EQ(&n, &DefaultValue<const int&>::Get());
  EXPECT_EQ(&x, &DefaultValue<MyNonDefaultConstructible&>::Get());

  DefaultValue<const int&>::Clear();
  DefaultValue<MyNonDefaultConstructible&>::Clear();

  EXPECT_FALSE(DefaultValue<const int&>::Exists());
  EXPECT_FALSE(DefaultValue<MyNonDefaultConstructible&>::Exists());

  EXPECT_FALSE(DefaultValue<const int&>::IsSet());
  EXPECT_FALSE(DefaultValue<MyNonDefaultConstructible&>::IsSet());
}

// Tests that DefaultValue<T&>::Get() returns the
// BuiltInDefaultValue<T&>::Get() when DefaultValue<T&>::IsSet() is
// false.
auto TEST(DefaultValueOfReferenceDeathTest,
          GetReturnsBuiltInDefaultValueWhenUnset)
->
  {
  EXPECT_FALSE(DefaultValue<int&>::IsSet());
  EXPECT_FALSE(DefaultValue<MyNonDefaultConstructible&>::IsSet());

  EXPECT_DEATH_IF_SUPPORTED({
    DefaultValue<int&>::Get();
  }, "");
  EXPECT_DEATH_IF_SUPPORTED({
    DefaultValue<MyNonDefaultConstructible>::Get();
  }, "");
}

// Tests that ActionInterface can be implemented by defining the
// Perform method.

using MyGlobalFunction = auto(bool, int) -> int;

class MyActionImpl : public ActionInterface<MyGlobalFunction> {
public:
  auto Perform(const std::tuple<bool, int>& args) const -> int override {
    return std::get<0>(args) ? std::get<1>(args) : 0;
  }
};

auto TEST(ActionInterfaceTest, CanBeImplementedByDefiningPerform)
->
  {
  MyActionImpl my_action_impl;
  (void)my_action_impl;
}

auto TEST(ActionInterfaceTest, MakeAction)
->
  {
  Action<MyGlobalFunction> action = MakeAction(new MyActionImpl);

  // When exercising the Perform() method of Action<F>, we must pass
  // it a tuple whose size and type are compatible with F's argument
  // types.  For example, if F is int(), then Perform() takes a
  // 0-tuple; if F is void(bool, int), then Perform() takes a
  // std::tuple<bool, int>, and so on.
  EXPECT_EQ(5, action.Perform(std::make_tuple(true, 5)));
}

// Tests that Action<F> can be contructed from a pointer to
// ActionInterface<F>.
auto TEST(ActionTest, CanBeConstructedFromActionInterface)
->
  {
  Action<MyGlobalFunction> action(new MyActionImpl);
}

// Tests that Action<F> delegates actual work to ActionInterface<F>.
auto TEST(ActionTest, DelegatesWorkToActionInterface)
->
  {
  const Action<MyGlobalFunction> action(new MyActionImpl);

  EXPECT_EQ(5, action.Perform(std::make_tuple(true, 5)));
  EXPECT_EQ(0, action.Perform(std::make_tuple(false, 1)));
}

// Tests that Action<F> can be copied.
auto TEST(ActionTest, IsCopyable)
->
  {
  Action<MyGlobalFunction> a1(new MyActionImpl);
  Action<MyGlobalFunction> a2(a1);  // Tests the copy constructor.

  // a1 should continue to work after being copied from.
  EXPECT_EQ(5, a1.Perform(std::make_tuple(true, 5)));
  EXPECT_EQ(0, a1.Perform(std::make_tuple(false, 1)));

  // a2 should work like the action it was copied from.
  EXPECT_EQ(5, a2.Perform(std::make_tuple(true, 5)));
  EXPECT_EQ(0, a2.Perform(std::make_tuple(false, 1)));

  a2 = a1;  // Tests the assignment operator.

  // a1 should continue to work after being copied from.
  EXPECT_EQ(5, a1.Perform(std::make_tuple(true, 5)));
  EXPECT_EQ(0, a1.Perform(std::make_tuple(false, 1)));

  // a2 should work like the action it was copied from.
  EXPECT_EQ(5, a2.Perform(std::make_tuple(true, 5)));
  EXPECT_EQ(0, a2.Perform(std::make_tuple(false, 1)));
}

// Tests that an Action<From> object can be converted to a
// compatible Action<To> object.

class IsNotZero : public ActionInterface<bool(int)> {
  // NOLINT
public:
  auto Perform(const std::tuple<int>& arg) const -> bool override {
    return std::get<0>(arg) != 0;
  }
};

auto TEST(ActionTest, CanBeConvertedToOtherActionType)
->
  {
  const Action<bool(int)> a1(new IsNotZero);  // NOLINT
  const Action<int(char)> a2 = Action<int(char)>(a1);  // NOLINT
  EXPECT_EQ(1, a2.Perform(std::make_tuple('a')));
  EXPECT_EQ(0, a2.Perform(std::make_tuple('\0')));
}

// The following two classes are for testing MakePolymorphicAction().

// Implements a polymorphic action that returns the second of the
// arguments it receives.
class ReturnSecondArgumentAction {
public:
  // We want to verify that MakePolymorphicAction() can work with a
  // polymorphic action whose Perform() method template is either
  // const or not.  This lets us verify the non-const case.
  template <typename Result, typename ArgumentTuple>
  auto Perform(const ArgumentTuple& args) -> Result {
    return std::get<1>(args);
  }
};

// Implements a polymorphic action that can be used in a nullary
// function to return 0.
class ReturnZeroFromNullaryFunctionAction {
public:
  // For testing that MakePolymorphicAction() works when the
  // implementation class' Perform() method template takes only one
  // template parameter.
  //
  // We want to verify that MakePolymorphicAction() can work with a
  // polymorphic action whose Perform() method template is either
  // const or not.  This lets us verify the const case.
  template <typename Result>
  auto Perform(const std::tuple<>&) const -> Result {
    return 0;
  }
};

// These functions verify that MakePolymorphicAction() returns a
// PolymorphicAction<T> where T is the argument's type.

auto ReturnSecondArgument() -> PolymorphicAction<ReturnSecondArgumentAction> {
  return MakePolymorphicAction(ReturnSecondArgumentAction());
}

auto ReturnZeroFromNullaryFunction() -> PolymorphicAction<
  ReturnZeroFromNullaryFunctionAction> {
  return MakePolymorphicAction(ReturnZeroFromNullaryFunctionAction());
}

// Tests that MakePolymorphicAction() turns a polymorphic action
// implementation class into a polymorphic action.
auto TEST(MakePolymorphicActionTest, ConstructsActionFromImpl)
->
  {
  Action<int(bool, int, double)> a1 = ReturnSecondArgument();  // NOLINT
  EXPECT_EQ(5, a1.Perform(std::make_tuple(false, 5, 2.0)));
}

// Tests that MakePolymorphicAction() works when the implementation
// class' Perform() method template has only one template parameter.
auto TEST(MakePolymorphicActionTest,
          WorksWhenPerformHasOneTemplateParameter)
->
  {
  Action<int()> a1 = ReturnZeroFromNullaryFunction();
  EXPECT_EQ(0, a1.Perform(std::make_tuple()));

  Action<void*()> a2 = ReturnZeroFromNullaryFunction();
  EXPECT_TRUE(a2.Perform(std::make_tuple()) == nullptr);
}

// Tests that Return() works as an action for void-returning
// functions.
auto TEST(ReturnTest, WorksForVoid)
->
  {
  const Action<void(int)> ret = Return();  // NOLINT
  return ret.Perform(std::make_tuple(1));
}

// Tests that Return(v) returns v.
auto TEST(ReturnTest, ReturnsGivenValue)
->
  {
  Action<int()> ret = Return(1);  // NOLINT
  EXPECT_EQ(1, ret.Perform(std::make_tuple()));

  ret = Return(-5);
  EXPECT_EQ(-5, ret.Perform(std::make_tuple()));
}

// Tests that Return("string literal") works.
auto TEST(ReturnTest, AcceptsStringLiteral)
->
  {
  Action<const char*()> a1 = Return("Hello");
  EXPECT_STREQ("Hello", a1.Perform(std::make_tuple()));

  Action<std::string()> a2 = Return("world");
  EXPECT_EQ("world", a2.Perform(std::make_tuple()));
}

// Test struct which wraps a vector of integers. Used in
// 'SupportsWrapperReturnType' test.
struct IntegerVectorWrapper {
  std::vector<int>* v;

  IntegerVectorWrapper(std::vector<int>& _v)
    : v(&_v) {} // NOLINT
};

// Tests that Return() works when return type is a wrapper type.
auto TEST(ReturnTest, SupportsWrapperReturnType)
->
  {
  // Initialize vector of integers.
  std::vector<int> v;
  for (int i = 0; i < 5; ++i) {
    v.push_back(i);
  }

  // Return() called with 'v' as argument. The Action will return the same data
  // as 'v' (copy) but it will be wrapped in an IntegerVectorWrapper.
  Action<IntegerVectorWrapper()> a = Return(v);
  const std::vector<int>& result = *a.Perform(std::make_tuple()).v;
  EXPECT_THAT(result, ::testing::ElementsAre(0, 1, 2, 3, 4));
}

// Tests that Return(v) is covaraint.

struct Base {
  auto operator==(const Base&) const -> bool { return true; }
};

struct Derived : public Base {
  auto operator==(const Derived&) const -> bool { return true; }
};

auto TEST(ReturnTest, IsCovariant)
->
  {
  Base base;
  Derived derived;
  Action<Base*()> ret = Return(&base);
  EXPECT_EQ(&base, ret.Perform(std::make_tuple()));

  ret = Return(&derived);
  EXPECT_EQ(&derived, ret.Perform(std::make_tuple()));
}

// Tests that the type of the value passed into Return is converted into T
// when the action is cast to Action<T(...)> rather than when the action is
// performed. See comments on testing::internal::ReturnAction in
// gmock-actions.h for more information.
class FromType {
public:
  explicit FromType(bool* is_converted)
    : converted_(is_converted) {}

  auto converted() const -> bool* { return converted_; }

private:
  bool* const converted_;
};

class ToType {
public:
  // Must allow implicit conversion due to use in ImplicitCast_<T>.
  ToType(const FromType& x) { *x.converted() = true; } // NOLINT
};

auto TEST(ReturnTest, ConvertsArgumentWhenConverted)
->
  {
  bool converted = false;
  FromType x(&converted);
  Action<ToType()> action(Return(x));
  EXPECT_TRUE(converted) << "Return must convert its argument in its own "
                         << "conversion operator.";
  converted = false;
  action.Perform(std::tuple<>());
  EXPECT_FALSE(converted) << "Action must NOT convert its argument "
                          << "when performed.";
}

class DestinationType {};

class SourceType {
public:
  // Note: a non-const typecast operator.
  operator DestinationType() const { return DestinationType(); }
};

auto TEST(ReturnTest, CanConvertArgumentUsingNonConstTypeCastOperator)
->
  {
  SourceType s;
  Action<DestinationType()> action(Return(s));
}

// Tests that ReturnNull() returns NULL in a pointer-returning function.
auto TEST(ReturnNullTest, WorksInPointerReturningFunction)
->
  {
  const Action<int*()> a1 = ReturnNull();
  EXPECT_TRUE(a1.Perform(std::make_tuple()) == nullptr);

  const Action<const char*(bool)> a2 = ReturnNull();  // NOLINT
  EXPECT_TRUE(a2.Perform(std::make_tuple(true)) == nullptr);
}

// Tests that ReturnNull() returns NULL for shared_ptr and unique_ptr returning
// functions.
auto TEST(ReturnNullTest, WorksInSmartPointerReturningFunction)
->
  {
  const Action<std::unique_ptr<const int>()> a1 = ReturnNull();
  EXPECT_TRUE(a1.Perform(std::make_tuple()) == nullptr);

  const Action<std::shared_ptr<int>(std::string)> a2 = ReturnNull();
  EXPECT_TRUE(a2.Perform(std::make_tuple("foo")) == nullptr);
}

// Tests that ReturnRef(v) works for reference types.
auto TEST(ReturnRefTest, WorksForReference)
->
  {
  const int n = 0;
  const Action<const int&(bool)> ret = ReturnRef(n);  // NOLINT

  EXPECT_EQ(&n, &ret.Perform(std::make_tuple(true)));
}

// Tests that ReturnRef(v) is covariant.
auto TEST(ReturnRefTest, IsCovariant)
->
  {
  Base base;
  Derived derived;
  Action<Base&()> a = ReturnRef(base);
  EXPECT_EQ(&base, &a.Perform(std::make_tuple()));

  a = ReturnRef(derived);
  EXPECT_EQ(&derived, &a.Perform(std::make_tuple()));
}

template <typename T, typename = decltype(ReturnRef(std::declval<T&&>()))>
auto CanCallReturnRef(T&&) -> bool { return true; }

auto CanCallReturnRef(Unused)
->
bool
{ return false; }

// Tests that ReturnRef(v) is working with non-temporaries (T&)
auto TEST(ReturnRefTest, WorksForNonTemporary)
->
  {
  int scalar_value = 123;
  EXPECT_TRUE(CanCallReturnRef(scalar_value));

  std::string non_scalar_value("ABC");
  EXPECT_TRUE(CanCallReturnRef(non_scalar_value));

  const int const_scalar_value{321};
  EXPECT_TRUE(CanCallReturnRef(const_scalar_value));

  const std::string const_non_scalar_value("CBA");
  EXPECT_TRUE(CanCallReturnRef(const_non_scalar_value));
}

// Tests that ReturnRef(v) is not working with temporaries (T&&)
auto TEST(ReturnRefTest, DoesNotWorkForTemporary)
->
  {
  auto scalar_value = []()  -> int { return 123; };
  EXPECT_FALSE(CanCallReturnRef(scalar_value()));

  auto non_scalar_value = []() -> std::string { return "ABC"; };
  EXPECT_FALSE(CanCallReturnRef(non_scalar_value()));

  // cannot use here callable returning "const scalar type",
  // because such const for scalar return type is ignored
  EXPECT_FALSE(CanCallReturnRef(static_cast<const int>(321)));

  auto const_non_scalar_value = []() -> const std::string { return "CBA"; };
  EXPECT_FALSE(CanCallReturnRef(const_non_scalar_value()));
}

// Tests that ReturnRefOfCopy(v) works for reference types.
auto TEST(ReturnRefOfCopyTest, WorksForReference)
->
  {
  int n = 42;
  const Action<const int&()> ret = ReturnRefOfCopy(n);

  EXPECT_NE(&n, &ret.Perform(std::make_tuple()));
  EXPECT_EQ(42, ret.Perform(std::make_tuple()));

  n = 43;
  EXPECT_NE(&n, &ret.Perform(std::make_tuple()));
  EXPECT_EQ(42, ret.Perform(std::make_tuple()));
}

// Tests that ReturnRefOfCopy(v) is covariant.
auto TEST(ReturnRefOfCopyTest, IsCovariant)
->
  {
  Base base;
  Derived derived;
  Action<Base&()> a = ReturnRefOfCopy(base);
  EXPECT_NE(&base, &a.Perform(std::make_tuple()));

  a = ReturnRefOfCopy(derived);
  EXPECT_NE(&derived, &a.Perform(std::make_tuple()));
}

// Tests that ReturnRoundRobin(v) works with initializer lists
auto TEST(ReturnRoundRobinTest, WorksForInitList)
->
  {
  Action<int()> ret = ReturnRoundRobin({1, 2, 3});

  EXPECT_EQ(1, ret.Perform(std::make_tuple()));
  EXPECT_EQ(2, ret.Perform(std::make_tuple()));
  EXPECT_EQ(3, ret.Perform(std::make_tuple()));
  EXPECT_EQ(1, ret.Perform(std::make_tuple()));
  EXPECT_EQ(2, ret.Perform(std::make_tuple()));
  EXPECT_EQ(3, ret.Perform(std::make_tuple()));
}

// Tests that ReturnRoundRobin(v) works with vectors
auto TEST(ReturnRoundRobinTest, WorksForVector)
->
  {
  std::vector<double> v = {4.4, 5.5, 6.6};
  Action<double()> ret = ReturnRoundRobin(v);

  EXPECT_EQ(4.4, ret.Perform(std::make_tuple()));
  EXPECT_EQ(5.5, ret.Perform(std::make_tuple()));
  EXPECT_EQ(6.6, ret.Perform(std::make_tuple()));
  EXPECT_EQ(4.4, ret.Perform(std::make_tuple()));
  EXPECT_EQ(5.5, ret.Perform(std::make_tuple()));
  EXPECT_EQ(6.6, ret.Perform(std::make_tuple()));
}

// Tests that DoDefault() does the default action for the mock method.

class MockClass {
public:
  MockClass() {}

  auto MOCK_METHOD1(IntFunc, int (bool flag)) -> ; // NOLINT
  auto MOCK_METHOD0(Foo, MyNonDefaultConstructible ()) -> ;
  auto MOCK_METHOD0(MakeUnique, std::unique_ptr<int> ()) -> ;
  auto MOCK_METHOD0(MakeUniqueBase, std::unique_ptr<Base> ()) -> ;
  auto MOCK_METHOD0(MakeVectorUnique, std::vector<std::unique_ptr<int>> ()) -> ;
  auto MOCK_METHOD1(TakeUnique, int (std::unique_ptr<int>)) -> ;
  auto MOCK_METHOD2(TakeUnique,
                    int (const std::unique_ptr<int>&,
                         std::unique_ptr<int>)) -> ;

private:
  auto GTEST_DISALLOW_COPY_AND_ASSIGN_(MockClass) -> ;
};

// Tests that DoDefault() returns the built-in default value for the
// return type by default.
auto TEST(DoDefaultTest, ReturnsBuiltInDefaultValueByDefault)
->
  {
  MockClass mock;
  EXPECT_CALL(mock, IntFunc(_))
      .WillOnce(DoDefault());
  EXPECT_EQ(0, mock.IntFunc(true));
}

// Tests that DoDefault() throws (when exceptions are enabled) or aborts
// the process when there is no built-in default value for the return type.
auto TEST(DoDefaultDeathTest, DiesForUnknowType)
->
  {
  MockClass mock;
  EXPECT_CALL(mock, Foo())
      .WillRepeatedly(DoDefault());
#if GTEST_HAS_EXCEPTIONS
  EXPECT_ANY_THROW(mock.Foo());
#else
  EXPECT_DEATH_IF_SUPPORTED({
    mock.Foo();
  }, "");
#endif
}

// Tests that using DoDefault() inside a composite action leads to a
// run-time error.

auto VoidFunc(bool /* flag */) -> void {}

auto TEST(DoDefaultDeathTest, DiesIfUsedInCompositeAction)
->
  {
  MockClass mock;
  EXPECT_CALL(mock, IntFunc(_))
      .WillRepeatedly(DoAll(Invoke(VoidFunc),
                            DoDefault()));

  // Ideally we should verify the error message as well.  Sadly,
  // EXPECT_DEATH() can only capture stderr, while Google Mock's
  // errors are printed on stdout.  Therefore we have to settle for
  // not verifying the message.
  EXPECT_DEATH_IF_SUPPORTED({
    mock.IntFunc(true);
  }, "");
}

// Tests that DoDefault() returns the default value set by
// DefaultValue<T>::Set() when it's not overriden by an ON_CALL().
auto TEST(DoDefaultTest,
          ReturnsUserSpecifiedPerTypeDefaultValueWhenThereIsOne)
->
  {
  DefaultValue<int>::Set(1);
  MockClass mock;
  EXPECT_CALL(mock, IntFunc(_))
      .WillOnce(DoDefault());
  EXPECT_EQ(1, mock.IntFunc(false));
  DefaultValue<int>::Clear();
}

// Tests that DoDefault() does the action specified by ON_CALL().
auto TEST(DoDefaultTest, DoesWhatOnCallSpecifies)
->
  {
  MockClass mock;
  ON_CALL(mock, IntFunc(_))
      .WillByDefault(Return(2));
  EXPECT_CALL(mock, IntFunc(_))
      .WillOnce(DoDefault());
  EXPECT_EQ(2, mock.IntFunc(false));
}

// Tests that using DoDefault() in ON_CALL() leads to a run-time failure.
auto TEST(DoDefaultTest, CannotBeUsedInOnCall)
->
  {
  MockClass mock;
  EXPECT_NONFATAL_FAILURE({  // NOLINT
    ON_CALL(mock, IntFunc(_))
      .WillByDefault(DoDefault());
  }, "DoDefault() cannot be used in ON_CALL()");
}

// Tests that SetArgPointee<N>(v) sets the variable pointed to by
// the N-th (0-based) argument to v.
auto TEST(SetArgPointeeTest, SetsTheNthPointee)
->
  {
  using MyFunction = auto(bool, int*, char*) -> void;
  Action<MyFunction> a = SetArgPointee<1>(2);

  int n = 0;
  char ch = '\0';
  a.Perform(std::make_tuple(true, &n, &ch));
  EXPECT_EQ(2, n);
  EXPECT_EQ('\0', ch);

  a = SetArgPointee<2>('a');
  n = 0;
  ch = '\0';
  a.Perform(std::make_tuple(true, &n, &ch));
  EXPECT_EQ(0, n);
  EXPECT_EQ('a', ch);
}

// Tests that SetArgPointee<N>() accepts a string literal.
auto TEST(SetArgPointeeTest, AcceptsStringLiteral)
->
  {
  using MyFunction = auto(std::string*, const char**) -> void;
  Action<MyFunction> a = SetArgPointee<0>("hi");
  std::string str;
  const char* ptr = nullptr;
  a.Perform(std::make_tuple(&str, &ptr));
  EXPECT_EQ("hi", str);
  EXPECT_TRUE(ptr == nullptr);

  a = SetArgPointee<1>("world");
  str = "";
  a.Perform(std::make_tuple(&str, &ptr));
  EXPECT_EQ("", str);
  EXPECT_STREQ("world", ptr);
}

auto TEST(SetArgPointeeTest, AcceptsWideStringLiteral)
->
  {
  using MyFunction = auto(const wchar_t**) -> void;
  Action<MyFunction> a = SetArgPointee<0>(L"world");
  const wchar_t* ptr = nullptr;
  a.Perform(std::make_tuple(&ptr));
  EXPECT_STREQ(L"world", ptr);

# if GTEST_HAS_STD_WSTRING

  typedef void MyStringFunction(std::wstring*);
  Action<MyStringFunction> a2 = SetArgPointee<0>(L"world");
  std::wstring str = L"";
  a2.Perform(std::make_tuple(&str));
  EXPECT_EQ(L"world", str);

# endif
}

// Tests that SetArgPointee<N>() accepts a char pointer.
auto TEST(SetArgPointeeTest, AcceptsCharPointer)
->
  {
  using MyFunction = auto(bool, std::string*, const char**) -> void;
  const auto hi = "hi";
  Action<MyFunction> a = SetArgPointee<1>(hi);
  std::string str;
  const char* ptr = nullptr;
  a.Perform(std::make_tuple(true, &str, &ptr));
  EXPECT_EQ("hi", str);
  EXPECT_TRUE(ptr == nullptr);

  char world_array[] = "world";
  char* const world = world_array;
  a = SetArgPointee<2>(world);
  str = "";
  a.Perform(std::make_tuple(true, &str, &ptr));
  EXPECT_EQ("", str);
  EXPECT_EQ(world, ptr);
}

auto TEST(SetArgPointeeTest, AcceptsWideCharPointer)
->
  {
  using MyFunction = auto(bool, const wchar_t**) -> void;
  const auto hi = L"hi";
  Action<MyFunction> a = SetArgPointee<1>(hi);
  const wchar_t* ptr = nullptr;
  a.Perform(std::make_tuple(true, &ptr));
  EXPECT_EQ(hi, ptr);

# if GTEST_HAS_STD_WSTRING

  typedef void MyStringFunction(bool, std::wstring*);
  wchar_t world_array[] = L"world";
  wchar_t* const world = world_array;
  Action<MyStringFunction> a2 = SetArgPointee<1>(world);
  std::wstring str;
  a2.Perform(std::make_tuple(true, &str));
  EXPECT_EQ(world_array, str);
# endif
}

// Tests that SetArgumentPointee<N>(v) sets the variable pointed to by
// the N-th (0-based) argument to v.
auto TEST(SetArgumentPointeeTest, SetsTheNthPointee)
->
  {
  using MyFunction = auto(bool, int*, char*) -> void;
  Action<MyFunction> a = SetArgumentPointee<1>(2);

  int n = 0;
  char ch = '\0';
  a.Perform(std::make_tuple(true, &n, &ch));
  EXPECT_EQ(2, n);
  EXPECT_EQ('\0', ch);

  a = SetArgumentPointee<2>('a');
  n = 0;
  ch = '\0';
  a.Perform(std::make_tuple(true, &n, &ch));
  EXPECT_EQ(0, n);
  EXPECT_EQ('a', ch);
}

// Sample functions and functors for testing Invoke() and etc.
auto Nullary() -> int { return 1; }

class NullaryFunctor {
public:
  auto operator()() const -> int { return 2; }
};

bool g_done = false;
auto VoidNullary() -> void { g_done = true; }

class VoidNullaryFunctor {
public:
  auto operator()() const -> void { g_done = true; }
};

auto Short(short n) -> short { return n; } // NOLINT
auto Char(char ch) -> char { return ch; }

auto CharPtr(const char* s) -> const char* { return s; }

auto Unary(int x) -> bool { return x < 0; }

auto Binary(const char* input, short n) -> const char* { return input + n; }
// NOLINT

auto VoidBinary(int, char) -> void { g_done = true; }

auto Ternary(int x, char y, short z) -> int { return x + y + z; } // NOLINT

auto SumOf4(int a, int b, int c, int d) -> int { return a + b + c + d; }

class Foo {
public:
  Foo()
    : value_(123) {}

  auto Nullary() const -> int { return value_; }

private:
  int value_;
};

// Tests InvokeWithoutArgs(function).
auto TEST(InvokeWithoutArgsTest, Function)
->
  {
  // As an action that takes one argument.
  Action<int(int)> a = InvokeWithoutArgs(Nullary);  // NOLINT
  EXPECT_EQ(1, a.Perform(std::make_tuple(2)));

  // As an action that takes two arguments.
  Action<int(int, double)> a2 = InvokeWithoutArgs(Nullary);  // NOLINT
  EXPECT_EQ(1, a2.Perform(std::make_tuple(2, 3.5)));

  // As an action that returns void.
  Action<void(int)> a3 = InvokeWithoutArgs(VoidNullary);  // NOLINT
  g_done = false;
  a3.Perform(std::make_tuple(1));
  EXPECT_TRUE(g_done);
}

// Tests InvokeWithoutArgs(functor).
auto TEST(InvokeWithoutArgsTest, Functor)
->
  {
  // As an action that takes no argument.
  Action<int()> a = InvokeWithoutArgs(NullaryFunctor());  // NOLINT
  EXPECT_EQ(2, a.Perform(std::make_tuple()));

  // As an action that takes three arguments.
  Action<int(int, double, char)> a2 =  // NOLINT
      InvokeWithoutArgs(NullaryFunctor());
  EXPECT_EQ(2, a2.Perform(std::make_tuple(3, 3.5, 'a')));

  // As an action that returns void.
  Action<void()> a3 = InvokeWithoutArgs(VoidNullaryFunctor());
  g_done = false;
  a3.Perform(std::make_tuple());
  EXPECT_TRUE(g_done);
}

// Tests InvokeWithoutArgs(obj_ptr, method).
auto TEST(InvokeWithoutArgsTest, Method)
->
  {
  Foo foo;
  Action<int(bool, char)> a =  // NOLINT
      InvokeWithoutArgs(&foo, &Foo::Nullary);
  EXPECT_EQ(123, a.Perform(std::make_tuple(true, 'a')));
}

// Tests using IgnoreResult() on a polymorphic action.
auto TEST(IgnoreResultTest, PolymorphicAction)
->
  {
  Action<void(int)> a = IgnoreResult(Return(5));  // NOLINT
  a.Perform(std::make_tuple(1));
}

// Tests using IgnoreResult() on a monomorphic action.

auto ReturnOne() -> int {
  g_done = true;
  return 1;
}

auto TEST(IgnoreResultTest, MonomorphicAction)
->
  {
  g_done = false;
  Action<void()> a = IgnoreResult(Invoke(ReturnOne));
  a.Perform(std::make_tuple());
  EXPECT_TRUE(g_done);
}

// Tests using IgnoreResult() on an action that returns a class type.

auto ReturnMyNonDefaultConstructible(
    double /* x */) -> MyNonDefaultConstructible {
  g_done = true;
  return MyNonDefaultConstructible(42);
}

auto TEST(IgnoreResultTest, ActionReturningClass)
->
  {
  g_done = false;
  Action<void(int)> a =
      IgnoreResult(Invoke(ReturnMyNonDefaultConstructible));  // NOLINT
  a.Perform(std::make_tuple(2));
  EXPECT_TRUE(g_done);
}

auto TEST(AssignTest, Int)
->
  {
  int x = 0;
  Action<void(int)> a = Assign(&x, 5);
  a.Perform(std::make_tuple(0));
  EXPECT_EQ(5, x);
}

auto TEST(AssignTest, String)
->
  {
  std::string x;
  Action<void(void)> a = Assign(&x, "Hello, world");
  a.Perform(std::make_tuple());
  EXPECT_EQ("Hello, world", x);
}

auto TEST(AssignTest, CompatibleTypes)
->
  {
  double x = 0;
  Action<void(int)> a = Assign(&x, 5);
  a.Perform(std::make_tuple(0));
  EXPECT_DOUBLE_EQ(5, x);
}


// Tests using WithArgs and with an action that takes 1 argument.
auto TEST(WithArgsTest, OneArg)
->
  {
  Action<bool(double x, int n)> a = WithArgs<1>(Invoke(Unary));  // NOLINT
  EXPECT_TRUE(a.Perform(std::make_tuple(1.5, -1)));
  EXPECT_FALSE(a.Perform(std::make_tuple(1.5, 1)));
}

// Tests using WithArgs with an action that takes 2 arguments.
auto TEST(WithArgsTest, TwoArgs)
->
  {
  Action<const char*(const char* s, double x, short n)> a =  // NOLINT
      WithArgs<0, 2>(Invoke(Binary));
  const char s[] = "Hello";
  EXPECT_EQ(s + 2, a.Perform(std::make_tuple(CharPtr(s), 0.5, Short(2))));
}

struct ConcatAll {
  auto operator()() const -> std::string { return { }; }

  template <typename... I>
  auto operator()(const char* a, I ...i) const -> std::string {
    return a + ConcatAll()(i...);
  }
};

// Tests using WithArgs with an action that takes 10 arguments.
auto TEST(WithArgsTest, TenArgs)
->
  {
  Action<std::string(const char*, const char*, const char*, const char*)> a =
      WithArgs<0, 1, 2, 3, 2, 1, 0, 1, 2, 3>(Invoke(ConcatAll{}));
  EXPECT_EQ("0123210123",
            a.Perform(std::make_tuple(CharPtr("0"), CharPtr("1"), CharPtr("2"),
                                      CharPtr("3"))));
}

// Tests using WithArgs with an action that is not Invoke().
class SubtractAction : public ActionInterface<int(int, int)> {
public:
  auto Perform(const std::tuple<int, int>& args) const -> int override {
    return std::get<0>(args) - std::get<1>(args);
  }
};

auto TEST(WithArgsTest, NonInvokeAction)
->
  {
  Action<int(const std::string&, int, int)> a =
      WithArgs<2, 1>(MakeAction(new SubtractAction));
  std::tuple<std::string, int, int> dummy =
      std::make_tuple(std::string("hi"), 2, 10);
  EXPECT_EQ(8, a.Perform(dummy));
}

// Tests using WithArgs to pass all original arguments in the original order.
auto TEST(WithArgsTest, Identity)
->
  {
  Action<int(int x, char y, short z)> a =  // NOLINT
      WithArgs<0, 1, 2>(Invoke(Ternary));
  EXPECT_EQ(123, a.Perform(std::make_tuple(100, Char(20), Short(3))));
}

// Tests using WithArgs with repeated arguments.
auto TEST(WithArgsTest, RepeatedArguments)
->
  {
  Action<int(bool, int m, int n)> a =  // NOLINT
      WithArgs<1, 1, 1, 1>(Invoke(SumOf4));
  EXPECT_EQ(4, a.Perform(std::make_tuple(false, 1, 10)));
}

// Tests using WithArgs with reversed argument order.
auto TEST(WithArgsTest, ReversedArgumentOrder)
->
  {
  Action<const char*(short n, const char* input)> a =  // NOLINT
      WithArgs<1, 0>(Invoke(Binary));
  const char s[] = "Hello";
  EXPECT_EQ(s + 2, a.Perform(std::make_tuple(Short(2), CharPtr(s))));
}

// Tests using WithArgs with compatible, but not identical, argument types.
auto TEST(WithArgsTest, ArgsOfCompatibleTypes)
->
  {
  Action<long(short x, char y, double z, char c)> a =  // NOLINT
      WithArgs<0, 1, 3>(Invoke(Ternary));
  EXPECT_EQ(123,
            a.Perform(std::make_tuple(Short(100), Char(20), 5.6, Char(3))));
}

// Tests using WithArgs with an action that returns void.
auto TEST(WithArgsTest, VoidAction)
->
  {
  Action<void(double x, char c, int n)> a = WithArgs<2, 1>(Invoke(VoidBinary));
  g_done = false;
  a.Perform(std::make_tuple(1.5, 'a', 3));
  EXPECT_TRUE(g_done);
}

auto TEST(WithArgsTest, ReturnReference)
->
  {
  Action<int&(int&, void*)> aa = WithArgs<0>([](int& a) -> int& { return a; });
  int i = 0;
  const int& res = aa.Perform(std::forward_as_tuple(i, nullptr));
  EXPECT_EQ(&i, &res);
}

auto TEST(WithArgsTest, InnerActionWithConversion)
->
  {
  Action<Derived*()> inner = [] { return nullptr; };
  Action<Base*(double)> a = testing::WithoutArgs(inner);
  EXPECT_EQ(nullptr, a.Perform(std::make_tuple(1.1)));
}

#if !GTEST_OS_WINDOWS_MOBILE

class SetErrnoAndReturnTest : public testing::Test {
protected:
  auto SetUp() -> void override {
    errno = 0;
  }

  auto TearDown() -> void override {
    errno = 0;
  }
};

auto TEST_F(SetErrnoAndReturnTest, Int)
->
  {
  Action<int(void)> a = SetErrnoAndReturn(ENOTTY, -5);
  EXPECT_EQ(-5, a.Perform(std::make_tuple()));
  EXPECT_EQ(ENOTTY, errno);
}

auto TEST_F(SetErrnoAndReturnTest, Ptr)
->
  {
  int x;
  Action<int*(void)> a = SetErrnoAndReturn(ENOTTY, &x);
  EXPECT_EQ(&x, a.Perform(std::make_tuple()));
  EXPECT_EQ(ENOTTY, errno);
}

auto TEST_F(SetErrnoAndReturnTest, CompatibleTypes)
->
  {
  Action<double()> a = SetErrnoAndReturn(EINVAL, 5);
  EXPECT_DOUBLE_EQ(5.0, a.Perform(std::make_tuple()));
  EXPECT_EQ(EINVAL, errno);
}

#endif  // !GTEST_OS_WINDOWS_MOBILE

// Tests ByRef().

// Tests that the result of ByRef() is copyable.
auto TEST(ByRefTest, IsCopyable)
->
  {
  const std::string s1 = "Hi";
  const std::string s2 = "Hello";

  auto ref_wrapper = ByRef(s1);
  const std::string& r1 = ref_wrapper;
  EXPECT_EQ(&s1, &r1);

  // Assigns a new value to ref_wrapper.
  ref_wrapper = ByRef(s2);
  const std::string& r2 = ref_wrapper;
  EXPECT_EQ(&s2, &r2);

  auto ref_wrapper1 = ByRef(s1);
  // Copies ref_wrapper1 to ref_wrapper.
  ref_wrapper = ref_wrapper1;
  const std::string& r3 = ref_wrapper;
  EXPECT_EQ(&s1, &r3);
}

// Tests using ByRef() on a const value.
auto TEST(ByRefTest, ConstValue)
->
  {
  const int n = 0;
  // int& ref = ByRef(n);  // This shouldn't compile - we have a
                           // negative compilation test to catch it.
  const int& const_ref = ByRef(n);
  EXPECT_EQ(&n, &const_ref);
}

// Tests using ByRef() on a non-const value.
auto TEST(ByRefTest, NonConstValue)
->
  {
  int n = 0;

  // ByRef(n) can be used as either an int&,
  int& ref = ByRef(n);
  EXPECT_EQ(&n, &ref);

  // or a const int&.
  const int& const_ref = ByRef(n);
  EXPECT_EQ(&n, &const_ref);
}

// Tests explicitly specifying the type when using ByRef().
auto TEST(ByRefTest, ExplicitType)
->
  {
  int n = 0;
  const int& r1 = ByRef<const int>(n);
  EXPECT_EQ(&n, &r1);

  // ByRef<char>(n);  // This shouldn't compile - we have a negative
                      // compilation test to catch it.

  Derived d;
  Derived& r2 = ByRef<Derived>(d);
  EXPECT_EQ(&d, &r2);

  const Derived& r3 = ByRef<const Derived>(d);
  EXPECT_EQ(&d, &r3);

  Base& r4 = ByRef<Base>(d);
  EXPECT_EQ(&d, &r4);

  const Base& r5 = ByRef<const Base>(d);
  EXPECT_EQ(&d, &r5);

  // The following shouldn't compile - we have a negative compilation
  // test for it.
  //
  // Base b;
  // ByRef<Derived>(b);
}

// Tests that Google Mock prints expression ByRef(x) as a reference to x.
auto TEST(ByRefTest, PrintsCorrectly)
->
  {
  int n = 42;
  std::stringstream expected, actual;
  testing::internal::UniversalPrinter<const int&>::Print(n, &expected);
  testing::internal::UniversalPrint(ByRef(n), &actual);
  EXPECT_EQ(expected.str(), actual.str());
}

struct UnaryConstructorClass {
  explicit UnaryConstructorClass(int v)
    : value(v) {}

  int value;
};

// Tests using ReturnNew() with a unary constructor.
auto TEST(ReturnNewTest, Unary)
->
  {
  Action<UnaryConstructorClass*()> a = ReturnNew<UnaryConstructorClass>(4000);
  UnaryConstructorClass* c = a.Perform(std::make_tuple());
  EXPECT_EQ(4000, c->value);
  delete c;
}

auto TEST(ReturnNewTest, UnaryWorksWhenMockMethodHasArgs)
->
  {
  Action<UnaryConstructorClass*(bool, int)> a =
      ReturnNew<UnaryConstructorClass>(4000);
  UnaryConstructorClass* c = a.Perform(std::make_tuple(false, 5));
  EXPECT_EQ(4000, c->value);
  delete c;
}

auto TEST(ReturnNewTest, UnaryWorksWhenMockMethodReturnsPointerToConst)
->
  {
  Action<const UnaryConstructorClass*()> a =
      ReturnNew<UnaryConstructorClass>(4000);
  const UnaryConstructorClass* c = a.Perform(std::make_tuple());
  EXPECT_EQ(4000, c->value);
  delete c;
}

class TenArgConstructorClass {
public:
  TenArgConstructorClass(int a1, int a2, int a3, int a4, int a5, int a6, int a7,
                         int a8, int a9, int a10)
    : value_(a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10) {}

  int value_;
};

// Tests using ReturnNew() with a 10-argument constructor.
auto TEST(ReturnNewTest, ConstructorThatTakes10Arguments)
->
  {
  Action<TenArgConstructorClass*()> a = ReturnNew<TenArgConstructorClass>(
      1000000000, 200000000, 30000000, 4000000, 500000, 60000, 7000, 800, 90,
      0);
  TenArgConstructorClass* c = a.Perform(std::make_tuple());
  EXPECT_EQ(1234567890, c->value_);
  delete c;
}

auto UniquePtrSource() -> std::unique_ptr<int> {
  return std::make_unique<int>(19);
}

auto VectorUniquePtrSource() -> std::vector<std::unique_ptr<int>> {
  std::vector<std::unique_ptr<int>> out;
  out.emplace_back(new int(7));
  return out;
}

auto TEST(MockMethodTest, CanReturnMoveOnlyValue_Return)
->
  {
  MockClass mock;
  std::unique_ptr<int> i(new int(19));
  EXPECT_CALL(mock, MakeUnique()).WillOnce(Return(ByMove(std::move(i))));
  EXPECT_CALL(mock, MakeVectorUnique())
      .WillOnce(Return(ByMove(VectorUniquePtrSource())));
  auto d = new Derived;
  EXPECT_CALL(mock, MakeUniqueBase())
      .WillOnce(Return(ByMove(std::unique_ptr<Derived>(d))));

  const std::unique_ptr<int> result1 = mock.MakeUnique();
  EXPECT_EQ(19, *result1);

  std::vector<std::unique_ptr<int>> vresult = mock.MakeVectorUnique();
  EXPECT_EQ(1u, vresult.size());
  EXPECT_NE(nullptr, vresult[0]);
  EXPECT_EQ(7, *vresult[0]);

  const std::unique_ptr<Base> result2 = mock.MakeUniqueBase();
  EXPECT_EQ(d, result2.get());
}

auto TEST(MockMethodTest, CanReturnMoveOnlyValue_DoAllReturn)
->
  {
  testing::MockFunction<void()> mock_function;
  MockClass mock;
  std::unique_ptr<int> i(new int(19));
  EXPECT_CALL(mock_function, Call());
  EXPECT_CALL(mock, MakeUnique()).WillOnce(DoAll(
      InvokeWithoutArgs(&mock_function, &testing::MockFunction<void()>::Call),
      Return(ByMove(std::move(i)))));

  const std::unique_ptr<int> result1 = mock.MakeUnique();
  EXPECT_EQ(19, *result1);
}

auto TEST(MockMethodTest, CanReturnMoveOnlyValue_Invoke)
->
  {
  MockClass mock;

  // Check default value
  DefaultValue<std::unique_ptr<int>>::SetFactory([] {
    return std::make_unique<int>(42);
  });
  EXPECT_EQ(42, *mock.MakeUnique());

  EXPECT_CALL(mock, MakeUnique()).WillRepeatedly(Invoke(UniquePtrSource));
  EXPECT_CALL(mock, MakeVectorUnique())
      .WillRepeatedly(Invoke(VectorUniquePtrSource));
  std::unique_ptr<int> result1 = mock.MakeUnique();
  EXPECT_EQ(19, *result1);
  std::unique_ptr<int> result2 = mock.MakeUnique();
  EXPECT_EQ(19, *result2);
  EXPECT_NE(result1, result2);

  std::vector<std::unique_ptr<int>> vresult = mock.MakeVectorUnique();
  EXPECT_EQ(1u, vresult.size());
  EXPECT_NE(nullptr, vresult[0]);
  EXPECT_EQ(7, *vresult[0]);
}

auto TEST(MockMethodTest, CanTakeMoveOnlyValue)
->
  {
  MockClass mock;
  auto make = [](int i) { return std::make_unique<int>(i); };

  EXPECT_CALL(mock, TakeUnique(_)).WillRepeatedly([](std::unique_ptr<int> i) {
    return *i;
  });
  // DoAll() does not compile, since it would move from its arguments twice.
  // EXPECT_CALL(mock, TakeUnique(_, _))
  //     .WillRepeatedly(DoAll(Invoke([](std::unique_ptr<int> j) {}),
  //     Return(1)));
  EXPECT_CALL(mock, TakeUnique(testing::Pointee(7)))
      .WillOnce(Return(-7))
      .RetiresOnSaturation();
  EXPECT_CALL(mock, TakeUnique(testing::IsNull()))
      .WillOnce(Return(-1))
      .RetiresOnSaturation();

  EXPECT_EQ(5, mock.TakeUnique(make(5)));
  EXPECT_EQ(-7, mock.TakeUnique(make(7)));
  EXPECT_EQ(7, mock.TakeUnique(make(7)));
  EXPECT_EQ(7, mock.TakeUnique(make(7)));
  EXPECT_EQ(-1, mock.TakeUnique({}));

  // Some arguments are moved, some passed by reference.
  auto lvalue = make(6);
  EXPECT_CALL(mock, TakeUnique(_, _))
      .WillOnce([](const std::unique_ptr<int>& i, std::unique_ptr<int> j) {
        return *i * *j;
      });
  EXPECT_EQ(42, mock.TakeUnique(lvalue, make(7)));

  // The unique_ptr can be saved by the action.
  std::unique_ptr<int> saved;
  EXPECT_CALL(mock, TakeUnique(_)).WillOnce([&saved](std::unique_ptr<int> i) {
    saved = std::move(i);
    return 0;
  });
  EXPECT_EQ(0, mock.TakeUnique(make(42)));
  EXPECT_EQ(42, *saved);
}


// Tests for std::function based action.

auto Add(int val, int& ref, int* ptr) -> int {
  // NOLINT
  const int result = val + ref + *ptr;
  ref = 42;
  *ptr = 43;
  return result;
}

auto Deref(std::unique_ptr<int> ptr) -> int { return *ptr; }

struct Double {
  template <typename T>
  auto operator()(T t) -> T { return 2 * t; }
};

auto UniqueInt(int i) -> std::unique_ptr<int> {
  return std::make_unique<int>(i);
}

auto TEST(FunctorActionTest, ActionFromFunction)
->
  {
  Action<int(int, int&, int*)> a = &Add;
  int x = 1, y = 2, z = 3;
  EXPECT_EQ(6, a.Perform(std::forward_as_tuple(x, y, &z)));
  EXPECT_EQ(42, y);
  EXPECT_EQ(43, z);

  Action<int(std::unique_ptr<int>)> a1 = &Deref;
  EXPECT_EQ(7, a1.Perform(std::make_tuple(UniqueInt(7))));
}

auto TEST(FunctorActionTest, ActionFromLambda)
->
  {
  Action<int(bool, int)> a1 = [](bool b, int i) { return b ? i : 0; };
  EXPECT_EQ(5, a1.Perform(std::make_tuple(true, 5)));
  EXPECT_EQ(0, a1.Perform(std::make_tuple(false, 5)));

  std::unique_ptr<int> saved;
  Action<void(std::unique_ptr<int>)> a2 = [&saved](std::unique_ptr<int> p) {
    saved = std::move(p);
  };
  a2.Perform(std::make_tuple(UniqueInt(5)));
  EXPECT_EQ(5, *saved);
}

auto TEST(FunctorActionTest, PolymorphicFunctor)
->
  {
  Action<int(int)> ai = Double();
  EXPECT_EQ(2, ai.Perform(std::make_tuple(1)));
  Action<double(double)> ad = Double();  // Double? Double double!
  EXPECT_EQ(3.0, ad.Perform(std::make_tuple(1.5)));
}

auto TEST(FunctorActionTest, TypeConversion)
->
  {
  // Numeric promotions are allowed.
  const Action<bool(int)> a1 = [](int i) { return i > 1; };
  const Action<int(bool)> a2 = Action<int(bool)>(a1);
  EXPECT_EQ(1, a1.Perform(std::make_tuple(42)));
  EXPECT_EQ(0, a2.Perform(std::make_tuple(42)));

  // Implicit constructors are allowed.
  const Action<bool(std::string)> s1 = [](std::string s) { return !s.empty(); };
  const Action<int(const char*)> s2 = Action<int(const char*)>(s1);
  EXPECT_EQ(0, s2.Perform(std::make_tuple("")));
  EXPECT_EQ(1, s2.Perform(std::make_tuple("hello")));

  // Also between the lambda and the action itself.
  const Action<bool(std::string)> x1 = [](Unused) { return 42; };
  const Action<bool(std::string)> x2 = [] { return 42; };
  EXPECT_TRUE(x1.Perform(std::make_tuple("hello")));
  EXPECT_TRUE(x2.Perform(std::make_tuple("hello")));

  // Ensure decay occurs where required.
  std::function<int()> f = [] { return 7; };
  Action<int(int)> d = f;
  f = nullptr;
  EXPECT_EQ(7, d.Perform(std::make_tuple(1)));

  // Ensure creation of an empty action succeeds.
  Action<void(int)>(nullptr);
}

auto TEST(FunctorActionTest, UnusedArguments)
->
  {
  // Verify that users can ignore uninteresting arguments.
  Action<int(int, double y, double z)> a =
      [](int i, Unused, Unused) { return 2 * i; };
  std::tuple<int, double, double> dummy = std::make_tuple(3, 7.3, 9.44);
  EXPECT_EQ(6, a.Perform(dummy));
}

// Test that basic built-in actions work with move-only arguments.
auto TEST(MoveOnlyArgumentsTest, ReturningActions)
->
  {
  Action<int(std::unique_ptr<int>)> a = Return(1);
  EXPECT_EQ(1, a.Perform(std::make_tuple(nullptr)));

  a = testing::WithoutArgs([]() { return 7; });
  EXPECT_EQ(7, a.Perform(std::make_tuple(nullptr)));

  Action<void(std::unique_ptr<int>, int*)> a2 = testing::SetArgPointee<1>(3);
  int x = 0;
  a2.Perform(std::make_tuple(nullptr, &x));
  EXPECT_EQ(x, 3);
}

ACTION (ReturnArity) {
  return std::tuple_size<args_type>::value;
}

auto TEST(ActionMacro, LargeArity)
->
  {
  EXPECT_EQ(
      1, testing::Action<int(int)>(ReturnArity()).Perform(std::make_tuple(0)));
  EXPECT_EQ(
      10,
      testing::Action<int(int, int, int, int, int, int, int, int, int, int)>(
          ReturnArity())
          .Perform(std::make_tuple(0, 1, 2, 3, 4, 5, 6, 7, 8, 9)));
  EXPECT_EQ(
      20,
      testing::Action<int(int, int, int, int, int, int, int, int, int, int, int,
                          int, int, int, int, int, int, int, int, int)>(
          ReturnArity())
          .Perform(std::make_tuple(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
                                   14, 15, 16, 17, 18, 19)));
}

} // Unnamed namespace

#ifdef _MSC_VER
#if _MSC_VER == 1900
#  pragma warning(pop)
#endif
#endif
