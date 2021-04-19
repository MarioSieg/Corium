// File: gmock-spec-builders.h
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

#ifndef GOOGLEMOCK_INCLUDE_GMOCK_GMOCK_SPEC_BUILDERS_H_
#define GOOGLEMOCK_INCLUDE_GMOCK_GMOCK_SPEC_BUILDERS_H_

#include <functional>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>
#include "gmock/gmock-actions.h"
#include "gmock/gmock-cardinalities.h"
#include "gmock/gmock-matchers.h"
#include "gmock/internal/gmock-internal-utils.h"
#include "gmock/internal/gmock-port.h"
#include "gtest/gtest.h"

#if GTEST_HAS_EXCEPTIONS
# include <stdexcept>  // NOLINT
#endif

GTEST_DISABLE_MSC_WARNINGS_PUSH_(4251
    /* class A needs to have dll-interface to be used by clients of class B */)

namespace testing {

// An abstract handle of an expectation.
class Expectation;

// A set of expectation handles.
class ExpectationSet;

// Anything inside the 'internal' namespace IS INTERNAL IMPLEMENTATION
// and MUST NOT BE USED IN USER CODE!!!
namespace internal {

// Implements a mock function.
template <typename F>
class FunctionMocker;

// Base class for expectations.
class ExpectationBase;

// Implements an expectation.
template <typename F>
class TypedExpectation;

// Helper class for testing the Expectation class template.
class ExpectationTester;

// Helper classes for implementing NiceMock, StrictMock, and NaggyMock.
template <typename MockClass>
class NiceMockImpl;
template <typename MockClass>
class StrictMockImpl;
template <typename MockClass>
class NaggyMockImpl;

// Protects the mock object registry (in class Mock), all function
// mockers, and all expectations.
//
// The reason we don't use more fine-grained protection is: when a
// mock function Foo() is called, it needs to consult its expectations
// to see which one should be picked.  If another thread is allowed to
// call a mock function (either Foo() or a different one) at the same
// time, it could affect the "retired" attributes of Foo()'s
// expectations when InSequence() is used, and thus affect which
// expectation gets picked.  Therefore, we sequence all mock function
// calls to ensure the integrity of the mock objects' states.
GTEST_API_ GTEST_DECLARE_STATIC_MUTEX_(g_gmock_mutex);

// Untyped base class for ActionResultHolder<R>.
class UntypedActionResultHolderBase;

// Abstract base class of FunctionMocker.  This is the
// type-agnostic part of the function mocker interface.  Its pure
// virtual methods are implemented by FunctionMocker.
class GTEST_API_ UntypedFunctionMockerBase {
public:
  UntypedFunctionMockerBase();
  virtual ~UntypedFunctionMockerBase();

  // Verifies that all expectations on this mock function have been
  // satisfied.  Reports one or more Google Test non-fatal failures
  // and returns false if not.
  auto VerifyAndClearExpectationsLocked() -> bool
  GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex);

  // Clears the ON_CALL()s set on this mock function.
  virtual auto ClearDefaultActionsLocked() -> void
  GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex) = 0;

  // In all of the following Untyped* functions, it's the caller's
  // responsibility to guarantee the correctness of the arguments'
  // types.

  // Performs the default action with the given arguments and returns
  // the action's result.  The call description string will be used in
  // the error message to describe the call in the case the default
  // action fails.
  // L = *
  virtual auto UntypedPerformDefaultAction(
      void* untyped_args,
      const std::string& call_description) const ->
  UntypedActionResultHolderBase* = 0;

  // Performs the given action with the given arguments and returns
  // the action's result.
  // L = *
  virtual auto UntypedPerformAction(
      const void* untyped_action,
      void* untyped_args) const -> UntypedActionResultHolderBase* = 0;

  // Writes a message that the call is uninteresting (i.e. neither
  // explicitly expected nor explicitly unexpected) to the given
  // ostream.
  virtual auto UntypedDescribeUninterestingCall(
      const void* untyped_args,
      std::ostream* os) const -> void
  GTEST_LOCK_EXCLUDED_(g_gmock_mutex) = 0;

  // Returns the expectation that matches the given function arguments
  // (or NULL is there's no match); when a match is found,
  // untyped_action is set to point to the action that should be
  // performed (or NULL if the action is "do default"), and
  // is_excessive is modified to indicate whether the call exceeds the
  // expected number.
  virtual auto UntypedFindMatchingExpectation(
      const void* untyped_args,
      const void** untyped_action, bool* is_excessive,
      std::ostream* what, std::ostream* why) -> const ExpectationBase*
  GTEST_LOCK_EXCLUDED_(g_gmock_mutex) = 0;

  // Prints the given function arguments to the ostream.
  virtual auto UntypedPrintArgs(const void* untyped_args,
                                std::ostream* os) const -> void = 0;

  // Sets the mock object this mock method belongs to, and registers
  // this information in the global mock registry.  Will be called
  // whenever an EXPECT_CALL() or ON_CALL() is executed on this mock
  // method.
  auto RegisterOwner(const void* mock_obj) -> void
  GTEST_LOCK_EXCLUDED_(g_gmock_mutex);

  // Sets the mock object this mock method belongs to, and sets the
  // name of the mock function.  Will be called upon each invocation
  // of this mock function.
  auto SetOwnerAndName(const void* mock_obj, const char* name) -> void
  GTEST_LOCK_EXCLUDED_(g_gmock_mutex);

  // Returns the mock object this mock method belongs to.  Must be
  // called after RegisterOwner() or SetOwnerAndName() has been
  // called.
  auto MockObject() const -> const void*
  GTEST_LOCK_EXCLUDED_(g_gmock_mutex);

  // Returns the name of this mock method.  Must be called after
  // SetOwnerAndName() has been called.
  auto Name() const -> const char*
  GTEST_LOCK_EXCLUDED_(g_gmock_mutex);

  // Returns the result of invoking this mock function with the given
  // arguments.  This function can be safely called from multiple
  // threads concurrently.  The caller is responsible for deleting the
  // result.
  auto UntypedInvokeWith(void* untyped_args) -> UntypedActionResultHolderBase*
  GTEST_LOCK_EXCLUDED_(g_gmock_mutex);

protected:
  using UntypedOnCallSpecs = std::vector<const void*>;

  using UntypedExpectations = std::vector<std::shared_ptr<ExpectationBase>>;

  // Returns an Expectation object that references and co-owns exp,
  // which must be an expectation on this mock function.
  auto GetHandleOf(ExpectationBase* exp) -> Expectation;

  // Address of the mock object this mock method belongs to.  Only
  // valid after this mock method has been called or
  // ON_CALL/EXPECT_CALL has been invoked on it.
  const void* mock_obj_; // Protected by g_gmock_mutex.

  // Name of the function being mocked.  Only valid after this mock
  // method has been called.
  const char* name_; // Protected by g_gmock_mutex.

  // All default action specs for this function mocker.
  UntypedOnCallSpecs untyped_on_call_specs_;

  // All expectations for this function mocker.
  //
  // It's undefined behavior to interleave expectations (EXPECT_CALLs
  // or ON_CALLs) and mock function calls.  Also, the order of
  // expectations is important.  Therefore it's a logic race condition
  // to read/write untyped_expectations_ concurrently.  In order for
  // tools like tsan to catch concurrent read/write accesses to
  // untyped_expectations, we deliberately leave accesses to it
  // unprotected.
  UntypedExpectations untyped_expectations_;
}; // class UntypedFunctionMockerBase

// Untyped base class for OnCallSpec<F>.
class UntypedOnCallSpecBase {
public:
  // The arguments are the location of the ON_CALL() statement.
  UntypedOnCallSpecBase(const char* a_file, int a_line)
    : file_(a_file),
      line_(a_line),
      last_clause_(kNone) {}

  // Where in the source file was the default action spec defined?
  auto file() const -> const char* { return file_; }
  auto line() const -> int { return line_; }

protected:
  // Gives each clause in the ON_CALL() statement a name.
  enum Clause {
    // Do not change the order of the enum members!  The run-time
    // syntax checking relies on it.
    kNone,
    kWith,
    kWillByDefault
  };

  // Asserts that the ON_CALL() statement has a certain property.
  auto AssertSpecProperty(bool property,
                          const std::string& failure_message) const -> void {
    Assert(property, file_, line_, failure_message);
  }

  // Expects that the ON_CALL() statement has a certain property.
  auto ExpectSpecProperty(bool property,
                          const std::string& failure_message) const -> void {
    Expect(property, file_, line_, failure_message);
  }

  const char* file_;
  int line_;

  // The last clause in the ON_CALL() statement as seen so far.
  // Initially kNone and changes as the statement is parsed.
  Clause last_clause_;
}; // class UntypedOnCallSpecBase

// This template class implements an ON_CALL spec.
template <typename F>
class OnCallSpec : public UntypedOnCallSpecBase {
public:
  using ArgumentTuple = typename Function<F>::ArgumentTuple;
  using ArgumentMatcherTuple = typename Function<F>::ArgumentMatcherTuple;

  // Constructs an OnCallSpec object from the information inside
  // the parenthesis of an ON_CALL() statement.
  OnCallSpec(const char* a_file, int a_line,
             const ArgumentMatcherTuple& matchers)
    : UntypedOnCallSpecBase(a_file, a_line),
      matchers_(matchers),
      // By default, extra_matcher_ should match anything.  However,
      // we cannot initialize it with _ as that causes ambiguity between
      // Matcher's copy and move constructor for some argument types.
      extra_matcher_(A<const ArgumentTuple&>()) {}

  // Implements the .With() clause.
  auto With(const Matcher<const ArgumentTuple&>& m) -> OnCallSpec& {
    // Makes sure this is called at most once.
    ExpectSpecProperty(last_clause_ < kWith,
                       ".With() cannot appear "
                       "more than once in an ON_CALL().");
    last_clause_ = kWith;

    extra_matcher_ = m;
    return *this;
  }

  // Implements the .WillByDefault() clause.
  auto WillByDefault(const Action<F>& action) -> OnCallSpec& {
    ExpectSpecProperty(last_clause_ < kWillByDefault,
                       ".WillByDefault() must appear "
                       "exactly once in an ON_CALL().");
    last_clause_ = kWillByDefault;

    ExpectSpecProperty(!action.IsDoDefault(),
                       "DoDefault() cannot be used in ON_CALL().");
    action_ = action;
    return *this;
  }

  // Returns true if and only if the given arguments match the matchers.
  auto Matches(const ArgumentTuple& args) const -> bool {
    return TupleMatches(matchers_, args) && extra_matcher_.Matches(args);
  }

  // Returns the action specified by the user.
  auto GetAction() const -> const Action<F>& {
    AssertSpecProperty(last_clause_ == kWillByDefault,
                       ".WillByDefault() must appear exactly "
                       "once in an ON_CALL().");
    return action_;
  }

private:
  // The information in statement
  //
  //   ON_CALL(mock_object, Method(matchers))
  //       .With(multi-argument-matcher)
  //       .WillByDefault(action);
  //
  // is recorded in the data members like this:
  //
  //   source file that contains the statement => file_
  //   line number of the statement            => line_
  //   matchers                                => matchers_
  //   multi-argument-matcher                  => extra_matcher_
  //   action                                  => action_
  ArgumentMatcherTuple matchers_;
  Matcher<const ArgumentTuple&> extra_matcher_;
  Action<F> action_;
}; // class OnCallSpec

// Possible reactions on uninteresting calls.
enum CallReaction {
  kAllow,
  kWarn,
  kFail,
};

} // namespace internal

// Utilities for manipulating mock objects.
class GTEST_API_ Mock {
public:
  // The following public methods can be called concurrently.

  // Tells Google Mock to ignore mock_obj when checking for leaked
  // mock objects.
  static auto AllowLeak(const void* mock_obj) -> void
  GTEST_LOCK_EXCLUDED_(internal::g_gmock_mutex);

  // Verifies and clears all expectations on the given mock object.
  // If the expectations aren't satisfied, generates one or more
  // Google Test non-fatal failures and returns false.
  static auto VerifyAndClearExpectations(void* mock_obj) -> bool
  GTEST_LOCK_EXCLUDED_(internal::g_gmock_mutex);

  // Verifies all expectations on the given mock object and clears its
  // default actions and expectations.  Returns true if and only if the
  // verification was successful.
  static auto VerifyAndClear(void* mock_obj) -> bool
  GTEST_LOCK_EXCLUDED_(internal::g_gmock_mutex);

  // Returns whether the mock was created as a naggy mock (default)
  static auto IsNaggy(void* mock_obj) -> bool
  GTEST_LOCK_EXCLUDED_(internal::g_gmock_mutex);
  // Returns whether the mock was created as a nice mock
  static auto IsNice(void* mock_obj) -> bool
  GTEST_LOCK_EXCLUDED_(internal::g_gmock_mutex);
  // Returns whether the mock was created as a strict mock
  static auto IsStrict(void* mock_obj) -> bool
  GTEST_LOCK_EXCLUDED_(internal::g_gmock_mutex);

private:
  friend class internal::UntypedFunctionMockerBase;

  // Needed for a function mocker to register itself (so that we know
  // how to clear a mock object).
  template <typename F>
  friend class internal::FunctionMocker;

  template <typename MockClass>
  friend class internal::NiceMockImpl;
  template <typename MockClass>
  friend class internal::NaggyMockImpl;
  template <typename MockClass>
  friend class internal::StrictMockImpl;

  // Tells Google Mock to allow uninteresting calls on the given mock
  // object.
  static auto AllowUninterestingCalls(const void* mock_obj) -> void
  GTEST_LOCK_EXCLUDED_(internal::g_gmock_mutex);

  // Tells Google Mock to warn the user about uninteresting calls on
  // the given mock object.
  static auto WarnUninterestingCalls(const void* mock_obj) -> void
  GTEST_LOCK_EXCLUDED_(internal::g_gmock_mutex);

  // Tells Google Mock to fail uninteresting calls on the given mock
  // object.
  static auto FailUninterestingCalls(const void* mock_obj) -> void
  GTEST_LOCK_EXCLUDED_(internal::g_gmock_mutex);

  // Tells Google Mock the given mock object is being destroyed and
  // its entry in the call-reaction table should be removed.
  static auto UnregisterCallReaction(const void* mock_obj) -> void
  GTEST_LOCK_EXCLUDED_(internal::g_gmock_mutex);

  // Returns the reaction Google Mock will have on uninteresting calls
  // made on the given mock object.
  static auto GetReactionOnUninterestingCalls(
      const void* mock_obj) -> internal::CallReaction
  GTEST_LOCK_EXCLUDED_(internal::g_gmock_mutex);

  // Verifies that all expectations on the given mock object have been
  // satisfied.  Reports one or more Google Test non-fatal failures
  // and returns false if not.
  static auto VerifyAndClearExpectationsLocked(void* mock_obj) -> bool
  GTEST_EXCLUSIVE_LOCK_REQUIRED_(internal::g_gmock_mutex);

  // Clears all ON_CALL()s set on the given mock object.
  static auto ClearDefaultActionsLocked(void* mock_obj) -> void
  GTEST_EXCLUSIVE_LOCK_REQUIRED_(internal::g_gmock_mutex);

  // Registers a mock object and a mock method it owns.
  static auto Register(
      const void* mock_obj,
      internal::UntypedFunctionMockerBase* mocker) -> void
  GTEST_LOCK_EXCLUDED_(internal::g_gmock_mutex);

  // Tells Google Mock where in the source code mock_obj is used in an
  // ON_CALL or EXPECT_CALL.  In case mock_obj is leaked, this
  // information helps the user identify which object it is.
  static auto RegisterUseByOnCallOrExpectCall(
      const void* mock_obj, const char* file, int line) -> void
  GTEST_LOCK_EXCLUDED_(internal::g_gmock_mutex);

  // Unregisters a mock method; removes the owning mock object from
  // the registry when the last mock method associated with it has
  // been unregistered.  This is called only in the destructor of
  // FunctionMocker.
  static auto UnregisterLocked(
      internal::UntypedFunctionMockerBase* mocker) -> void
  GTEST_EXCLUSIVE_LOCK_REQUIRED_(internal::g_gmock_mutex);
}; // class Mock

// An abstract handle of an expectation.  Useful in the .After()
// clause of EXPECT_CALL() for setting the (partial) order of
// expectations.  The syntax:
//
//   Expectation e1 = EXPECT_CALL(...)...;
//   EXPECT_CALL(...).After(e1)...;
//
// sets two expectations where the latter can only be matched after
// the former has been satisfied.
//
// Notes:
//   - This class is copyable and has value semantics.
//   - Constness is shallow: a const Expectation object itself cannot
//     be modified, but the mutable methods of the ExpectationBase
//     object it references can be called via expectation_base().

class GTEST_API_ Expectation {
public:
  // Constructs a null object that doesn't reference any expectation.
  Expectation();
  Expectation(Expectation&&) = default;
  Expectation(const Expectation&) = default;
  auto operator=(Expectation&&) -> Expectation& = default;
  auto operator=(const Expectation&) -> Expectation& = default;
  ~Expectation();

  // This single-argument ctor must not be explicit, in order to support the
  //   Expectation e = EXPECT_CALL(...);
  // syntax.
  //
  // A TypedExpectation object stores its pre-requisites as
  // Expectation objects, and needs to call the non-const Retire()
  // method on the ExpectationBase objects they reference.  Therefore
  // Expectation must receive a *non-const* reference to the
  // ExpectationBase object.
  Expectation(internal::ExpectationBase& exp); // NOLINT

  // The compiler-generated copy ctor and operator= work exactly as
  // intended, so we don't need to define our own.

  // Returns true if and only if rhs references the same expectation as this
  // object does.
  auto operator==(const Expectation& rhs) const -> bool {
    return expectation_base_ == rhs.expectation_base_;
  }

  auto operator!=(const Expectation& rhs) const -> bool {
    return !(*this == rhs);
  }

private:
  friend class ExpectationSet;
  friend class Sequence;
  friend class internal::ExpectationBase;
  friend class internal::UntypedFunctionMockerBase;

  template <typename F>
  friend class internal::FunctionMocker;

  template <typename F>
  friend class internal::TypedExpectation;

  // This comparator is needed for putting Expectation objects into a set.
  class Less {
  public:
    auto operator()(const Expectation& lhs,
                    const Expectation& rhs) const -> bool {
      return lhs.expectation_base_.get() < rhs.expectation_base_.get();
    }
  };

  using Set = std::set<Expectation, Less>;

  Expectation(
      const std::shared_ptr<internal::ExpectationBase>& expectation_base);

  // Returns the expectation this object references.
  auto expectation_base() const -> const std::shared_ptr<
    internal::ExpectationBase>& {
    return expectation_base_;
  }

  // A shared_ptr that co-owns the expectation this handle references.
  std::shared_ptr<internal::ExpectationBase> expectation_base_;
};

// A set of expectation handles.  Useful in the .After() clause of
// EXPECT_CALL() for setting the (partial) order of expectations.  The
// syntax:
//
//   ExpectationSet es;
//   es += EXPECT_CALL(...)...;
//   es += EXPECT_CALL(...)...;
//   EXPECT_CALL(...).After(es)...;
//
// sets three expectations where the last one can only be matched
// after the first two have both been satisfied.
//
// This class is copyable and has value semantics.
class ExpectationSet {
public:
  // A bidirectional iterator that can read a const element in the set.
  using const_iterator = Expectation::Set::const_iterator;

  // An object stored in the set.  This is an alias of Expectation.
  using value_type = Expectation::Set::value_type;

  // Constructs an empty set.
  ExpectationSet() {}

  // This single-argument ctor must not be explicit, in order to support the
  //   ExpectationSet es = EXPECT_CALL(...);
  // syntax.
  ExpectationSet(internal::ExpectationBase& exp) {
    // NOLINT
    *this += Expectation(exp);
  }

  // This single-argument ctor implements implicit conversion from
  // Expectation and thus must not be explicit.  This allows either an
  // Expectation or an ExpectationSet to be used in .After().
  ExpectationSet(const Expectation& e) {
    // NOLINT
    *this += e;
  }

  // The compiler-generator ctor and operator= works exactly as
  // intended, so we don't need to define our own.

  // Returns true if and only if rhs contains the same set of Expectation
  // objects as this does.
  auto operator==(const ExpectationSet& rhs) const -> bool {
    return expectations_ == rhs.expectations_;
  }

  auto operator!=(const ExpectationSet& rhs) const -> bool {
    return !(*this == rhs);
  }

  // Implements the syntax
  //   expectation_set += EXPECT_CALL(...);
  auto operator+=(const Expectation& e) -> ExpectationSet& {
    expectations_.insert(e);
    return *this;
  }

  auto size() const -> int { return static_cast<int>(expectations_.size()); }

  auto begin() const -> const_iterator { return expectations_.begin(); }
  auto end() const -> const_iterator { return expectations_.end(); }

private:
  Expectation::Set expectations_;
};


// Sequence objects are used by a user to specify the relative order
// in which the expectations should match.  They are copyable (we rely
// on the compiler-defined copy constructor and assignment operator).
class GTEST_API_ Sequence {
public:
  // Constructs an empty sequence.
  Sequence()
    : last_expectation_(new Expectation) {}

  // Adds an expectation to this sequence.  The caller must ensure
  // that no other thread is accessing this Sequence object.
  auto AddExpectation(const Expectation& expectation) const -> void;

private:
  // The last expectation in this sequence.
  std::shared_ptr<Expectation> last_expectation_;
}; // class Sequence

// An object of this type causes all EXPECT_CALL() statements
// encountered in its scope to be put in an anonymous sequence.  The
// work is done in the constructor and destructor.  You should only
// create an InSequence object on the stack.
//
// The sole purpose for this class is to support easy definition of
// sequential expectations, e.g.
//
//   {
//     InSequence dummy;  // The name of the object doesn't matter.
//
//     // The following expectations must match in the order they appear.
//     EXPECT_CALL(a, Bar())...;
//     EXPECT_CALL(a, Baz())...;
//     ...
//     EXPECT_CALL(b, Xyz())...;
//   }
//
// You can create InSequence objects in multiple threads, as long as
// they are used to affect different mock objects.  The idea is that
// each thread can create and set up its own mocks as if it's the only
// thread.  However, for clarity of your tests we recommend you to set
// up mocks in the main thread unless you have a good reason not to do
// so.
class GTEST_API_ InSequence {
public:
  InSequence();
  ~InSequence();
private:
  bool sequence_created_;

  GTEST_DISALLOW_COPY_AND_ASSIGN_(InSequence); // NOLINT
}

GTEST_ATTRIBUTE_UNUSED_;

namespace internal {

// Points to the implicit sequence introduced by a living InSequence
// object (if any) in the current thread or NULL.
GTEST_API_ extern ThreadLocal<Sequence*> g_gmock_implicit_sequence;

// Base class for implementing expectations.
//
// There are two reasons for having a type-agnostic base class for
// Expectation:
//
//   1. We need to store collections of expectations of different
//   types (e.g. all pre-requisites of a particular expectation, all
//   expectations in a sequence).  Therefore these expectation objects
//   must share a common base class.
//
//   2. We can avoid binary code bloat by moving methods not depending
//   on the template argument of Expectation to the base class.
//
// This class is internal and mustn't be used by user code directly.
class GTEST_API_ ExpectationBase {
public:
  // source_text is the EXPECT_CALL(...) source that created this Expectation.
  ExpectationBase(const char* file, int line, const std::string& source_text);

  virtual ~ExpectationBase();

  // Where in the source file was the expectation spec defined?
  auto file() const -> const char* { return file_; }
  auto line() const -> int { return line_; }
  auto source_text() const -> const char* { return source_text_.c_str(); }
  // Returns the cardinality specified in the expectation spec.
  auto cardinality() const -> const Cardinality& { return cardinality_; }

  // Describes the source file location of this expectation.
  auto DescribeLocationTo(std::ostream* os) const -> void {
    *os << FormatFileLocation(file(), line()) << " ";
  }

  // Describes how many times a function call matching this
  // expectation has occurred.
  auto DescribeCallCountTo(std::ostream* os) const -> void
  GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex);

  // If this mock method has an extra matcher (i.e. .With(matcher)),
  // describes it to the ostream.
  virtual auto MaybeDescribeExtraMatcherTo(std::ostream* os) -> void = 0;

protected:
  friend class Expectation;
  friend class UntypedFunctionMockerBase;

  enum Clause {
    // Don't change the order of the enum members!
    kNone,
    kWith,
    kTimes,
    kInSequence,
    kAfter,
    kWillOnce,
    kWillRepeatedly,
    kRetiresOnSaturation
  };

  using UntypedActions = std::vector<const void*>;

  // Returns an Expectation object that references and co-owns this
  // expectation.
  virtual auto GetHandle() -> Expectation = 0;

  // Asserts that the EXPECT_CALL() statement has the given property.
  auto AssertSpecProperty(bool property,
                          const std::string& failure_message) const -> void {
    Assert(property, file_, line_, failure_message);
  }

  // Expects that the EXPECT_CALL() statement has the given property.
  auto ExpectSpecProperty(bool property,
                          const std::string& failure_message) const -> void {
    Expect(property, file_, line_, failure_message);
  }

  // Explicitly specifies the cardinality of this expectation.  Used
  // by the subclasses to implement the .Times() clause.
  auto SpecifyCardinality(const Cardinality& cardinality) -> void;

  // Returns true if and only if the user specified the cardinality
  // explicitly using a .Times().
  auto cardinality_specified() const -> bool { return cardinality_specified_; }

  // Sets the cardinality of this expectation spec.
  auto set_cardinality(const Cardinality& a_cardinality) -> void {
    cardinality_ = a_cardinality;
  }

  // The following group of methods should only be called after the
  // EXPECT_CALL() statement, and only when g_gmock_mutex is held by
  // the current thread.

  // Retires all pre-requisites of this expectation.
  auto RetireAllPreRequisites() -> void
  GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex);

  // Returns true if and only if this expectation is retired.
  auto is_retired() const -> bool
  GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex) {
    g_gmock_mutex.AssertHeld();
    return retired_;
  }

  // Retires this expectation.
  auto Retire() -> void
  GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex) {
    g_gmock_mutex.AssertHeld();
    retired_ = true;
  }

  // Returns true if and only if this expectation is satisfied.
  auto IsSatisfied() const -> bool
  GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex) {
    g_gmock_mutex.AssertHeld();
    return cardinality().IsSatisfiedByCallCount(call_count_);
  }

  // Returns true if and only if this expectation is saturated.
  auto IsSaturated() const -> bool
  GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex) {
    g_gmock_mutex.AssertHeld();
    return cardinality().IsSaturatedByCallCount(call_count_);
  }

  // Returns true if and only if this expectation is over-saturated.
  auto IsOverSaturated() const -> bool
  GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex) {
    g_gmock_mutex.AssertHeld();
    return cardinality().IsOverSaturatedByCallCount(call_count_);
  }

  // Returns true if and only if all pre-requisites of this expectation are
  // satisfied.
  auto AllPrerequisitesAreSatisfied() const -> bool
  GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex);

  // Adds unsatisfied pre-requisites of this expectation to 'result'.
  auto FindUnsatisfiedPrerequisites(ExpectationSet* result) const -> void
  GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex);

  // Returns the number this expectation has been invoked.
  auto call_count() const -> int
  GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex) {
    g_gmock_mutex.AssertHeld();
    return call_count_;
  }

  // Increments the number this expectation has been invoked.
  auto IncrementCallCount() -> void
  GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex) {
    g_gmock_mutex.AssertHeld();
    call_count_++;
  }

  // Checks the action count (i.e. the number of WillOnce() and
  // WillRepeatedly() clauses) against the cardinality if this hasn't
  // been done before.  Prints a warning if there are too many or too
  // few actions.
  auto CheckActionCountIfNotDone() const -> void
  GTEST_LOCK_EXCLUDED_(mutex_);

  friend class Sequence;
  friend class ExpectationTester;

  template <typename Function>
  friend class TypedExpectation;

  // Implements the .Times() clause.
  auto UntypedTimes(const Cardinality& a_cardinality) -> void;

  // This group of fields are part of the spec and won't change after
  // an EXPECT_CALL() statement finishes.
  const char* file_;              // The file that contains the expectation.
  int line_;                      // The line number of the expectation.
  const std::string source_text_; // The EXPECT_CALL(...) source text.
  // True if and only if the cardinality is specified explicitly.
  bool cardinality_specified_;
  Cardinality cardinality_; // The cardinality of the expectation.
  // The immediate pre-requisites (i.e. expectations that must be
  // satisfied before this expectation can be matched) of this
  // expectation.  We use std::shared_ptr in the set because we want an
  // Expectation object to be co-owned by its FunctionMocker and its
  // successors.  This allows multiple mock objects to be deleted at
  // different times.
  ExpectationSet immediate_prerequisites_;

  // This group of fields are the current state of the expectation,
  // and can change as the mock function is called.
  int call_count_; // How many times this expectation has been invoked.
  bool retired_;   // True if and only if this expectation has retired.
  UntypedActions untyped_actions_;
  bool extra_matcher_specified_;
  bool repeated_action_specified_; // True if a WillRepeatedly() was specified.
  bool retires_on_saturation_;
  Clause last_clause_;
  mutable bool action_count_checked_; // Under mutex_.
  mutable Mutex mutex_;               // Protects action_count_checked_.
};                                    // class ExpectationBase

// Impements an expectation for the given function type.
template <typename F>
class TypedExpectation : public ExpectationBase {
public:
  using ArgumentTuple = typename Function<F>::ArgumentTuple;
  using ArgumentMatcherTuple = typename Function<F>::ArgumentMatcherTuple;
  using Result = typename Function<F>::Result;

  TypedExpectation(FunctionMocker<F>* owner, const char* a_file, int a_line,
                   const std::string& a_source_text,
                   const ArgumentMatcherTuple& m)
    : ExpectationBase(a_file, a_line, a_source_text),
      owner_(owner),
      matchers_(m),
      // By default, extra_matcher_ should match anything.  However,
      // we cannot initialize it with _ as that causes ambiguity between
      // Matcher's copy and move constructor for some argument types.
      extra_matcher_(A<const ArgumentTuple&>()),
      repeated_action_(DoDefault()) {}

  ~TypedExpectation() override {
    // Check the validity of the action count if it hasn't been done
    // yet (for example, if the expectation was never used).
    CheckActionCountIfNotDone();
    for (UntypedActions::const_iterator it = untyped_actions_.begin();
         it != untyped_actions_.end(); ++it) {
      delete static_cast<const Action<F>*>(*it);
    }
  }

  // Implements the .With() clause.
  auto With(const Matcher<const ArgumentTuple&>& m) -> TypedExpectation& {
    if (last_clause_ == kWith) {
      ExpectSpecProperty(false,
                         ".With() cannot appear "
                         "more than once in an EXPECT_CALL().");
    } else {
      ExpectSpecProperty(last_clause_ < kWith,
                         ".With() must be the first "
                         "clause in an EXPECT_CALL().");
    }
    last_clause_ = kWith;

    extra_matcher_ = m;
    extra_matcher_specified_ = true;
    return *this;
  }

  // Implements the .Times() clause.
  auto Times(const Cardinality& a_cardinality) -> TypedExpectation& {
    UntypedTimes(a_cardinality);
    return *this;
  }

  // Implements the .Times() clause.
  auto Times(int n) -> TypedExpectation& {
    return Times(Exactly(n));
  }

  // Implements the .InSequence() clause.
  auto InSequence(const Sequence& s) -> TypedExpectation& {
    ExpectSpecProperty(last_clause_ <= kInSequence,
                       ".InSequence() cannot appear after .After(),"
                       " .WillOnce(), .WillRepeatedly(), or "
                       ".RetiresOnSaturation().");
    last_clause_ = kInSequence;

    s.AddExpectation(GetHandle());
    return *this;
  }

  auto InSequence(const Sequence& s1, const Sequence& s2) -> TypedExpectation& {
    return InSequence(s1).InSequence(s2);
  }

  auto InSequence(const Sequence& s1, const Sequence& s2,
                  const Sequence& s3) -> TypedExpectation& {
    return InSequence(s1, s2).InSequence(s3);
  }

  auto InSequence(const Sequence& s1, const Sequence& s2,
                  const Sequence& s3, const Sequence& s4) -> TypedExpectation& {
    return InSequence(s1, s2, s3).InSequence(s4);
  }

  auto InSequence(const Sequence& s1, const Sequence& s2,
                  const Sequence& s3, const Sequence& s4,
                  const Sequence& s5) -> TypedExpectation& {
    return InSequence(s1, s2, s3, s4).InSequence(s5);
  }

  // Implements that .After() clause.
  auto After(const ExpectationSet& s) -> TypedExpectation& {
    ExpectSpecProperty(last_clause_ <= kAfter,
                       ".After() cannot appear after .WillOnce(),"
                       " .WillRepeatedly(), or "
                       ".RetiresOnSaturation().");
    last_clause_ = kAfter;

    for (auto it = s.begin(); it != s.end(); ++it) {
      immediate_prerequisites_ += *it;
    }
    return *this;
  }

  auto After(const ExpectationSet& s1,
             const ExpectationSet& s2) -> TypedExpectation& {
    return After(s1).After(s2);
  }

  auto After(const ExpectationSet& s1, const ExpectationSet& s2,
             const ExpectationSet& s3) -> TypedExpectation& {
    return After(s1, s2).After(s3);
  }

  auto After(const ExpectationSet& s1, const ExpectationSet& s2,
             const ExpectationSet& s3,
             const ExpectationSet& s4) -> TypedExpectation& {
    return After(s1, s2, s3).After(s4);
  }

  auto After(const ExpectationSet& s1, const ExpectationSet& s2,
             const ExpectationSet& s3, const ExpectationSet& s4,
             const ExpectationSet& s5) -> TypedExpectation& {
    return After(s1, s2, s3, s4).After(s5);
  }

  // Implements the .WillOnce() clause.
  auto WillOnce(const Action<F>& action) -> TypedExpectation& {
    ExpectSpecProperty(last_clause_ <= kWillOnce,
                       ".WillOnce() cannot appear after "
                       ".WillRepeatedly() or .RetiresOnSaturation().");
    last_clause_ = kWillOnce;

    untyped_actions_.push_back(new Action<F>(action));
    if (!cardinality_specified()) {
      set_cardinality(Exactly(static_cast<int>(untyped_actions_.size())));
    }
    return *this;
  }

  // Implements the .WillRepeatedly() clause.
  auto WillRepeatedly(const Action<F>& action) -> TypedExpectation& {
    if (last_clause_ == kWillRepeatedly) {
      ExpectSpecProperty(false,
                         ".WillRepeatedly() cannot appear "
                         "more than once in an EXPECT_CALL().");
    } else {
      ExpectSpecProperty(last_clause_ < kWillRepeatedly,
                         ".WillRepeatedly() cannot appear "
                         "after .RetiresOnSaturation().");
    }
    last_clause_ = kWillRepeatedly;
    repeated_action_specified_ = true;

    repeated_action_ = action;
    if (!cardinality_specified()) {
      set_cardinality(AtLeast(static_cast<int>(untyped_actions_.size())));
    }

    // Now that no more action clauses can be specified, we check
    // whether their count makes sense.
    CheckActionCountIfNotDone();
    return *this;
  }

  // Implements the .RetiresOnSaturation() clause.
  auto RetiresOnSaturation() -> TypedExpectation& {
    ExpectSpecProperty(last_clause_ < kRetiresOnSaturation,
                       ".RetiresOnSaturation() cannot appear "
                       "more than once.");
    last_clause_ = kRetiresOnSaturation;
    retires_on_saturation_ = true;

    // Now that no more action clauses can be specified, we check
    // whether their count makes sense.
    CheckActionCountIfNotDone();
    return *this;
  }

  // Returns the matchers for the arguments as specified inside the
  // EXPECT_CALL() macro.
  auto matchers() const -> const ArgumentMatcherTuple& {
    return matchers_;
  }

  // Returns the matcher specified by the .With() clause.
  auto extra_matcher() const -> const Matcher<const ArgumentTuple&>& {
    return extra_matcher_;
  }

  // Returns the action specified by the .WillRepeatedly() clause.
  auto repeated_action() const -> const Action<F>& { return repeated_action_; }

  // If this mock method has an extra matcher (i.e. .With(matcher)),
  // describes it to the ostream.
  auto MaybeDescribeExtraMatcherTo(std::ostream* os) -> void override {
    if (extra_matcher_specified_) {
      *os << "    Expected args: ";
      extra_matcher_.DescribeTo(os);
      *os << "\n";
    }
  }

private:
  template <typename Function>
  friend class FunctionMocker;

  // Returns an Expectation object that references and co-owns this
  // expectation.
  auto GetHandle() -> Expectation override { return owner_->GetHandleOf(this); }

  // The following methods will be called only after the EXPECT_CALL()
  // statement finishes and when the current thread holds
  // g_gmock_mutex.

  // Returns true if and only if this expectation matches the given arguments.
  auto Matches(const ArgumentTuple& args) const -> bool
  GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex) {
    g_gmock_mutex.AssertHeld();
    return TupleMatches(matchers_, args) && extra_matcher_.Matches(args);
  }

  // Returns true if and only if this expectation should handle the given
  // arguments.
  auto ShouldHandleArguments(const ArgumentTuple& args) const -> bool
  GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex) {
    g_gmock_mutex.AssertHeld();

    // In case the action count wasn't checked when the expectation
    // was defined (e.g. if this expectation has no WillRepeatedly()
    // or RetiresOnSaturation() clause), we check it when the
    // expectation is used for the first time.
    CheckActionCountIfNotDone();
    return !is_retired() && AllPrerequisitesAreSatisfied() && Matches(args);
  }

  // Describes the result of matching the arguments against this
  // expectation to the given ostream.
  auto ExplainMatchResultTo(
      const ArgumentTuple& args,
      std::ostream* os) const -> void
  GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex) {
    g_gmock_mutex.AssertHeld();

    if (is_retired()) {
      *os << "         Expected: the expectation is active\n"
          << "           Actual: it is retired\n";
    } else if (!Matches(args)) {
      if (!TupleMatches(matchers_, args)) {
        ExplainMatchFailureTupleTo(matchers_, args, os);
      }
      StringMatchResultListener listener;
      if (!extra_matcher_.MatchAndExplain(args, &listener)) {
        *os << "    Expected args: ";
        extra_matcher_.DescribeTo(os);
        *os << "\n           Actual: don't match";

        PrintIfNotEmpty(listener.str(), os);
        *os << "\n";
      }
    } else if (!AllPrerequisitesAreSatisfied()) {
      *os << "         Expected: all pre-requisites are satisfied\n"
          << "           Actual: the following immediate pre-requisites "
          << "are not satisfied:\n";
      ExpectationSet unsatisfied_prereqs;
      FindUnsatisfiedPrerequisites(&unsatisfied_prereqs);
      int i = 0;
      for (auto it = unsatisfied_prereqs.begin();
           it != unsatisfied_prereqs.end(); ++it) {
        it->expectation_base()->DescribeLocationTo(os);
        *os << "pre-requisite #" << i++ << "\n";
      }
      *os << "                   (end of pre-requisites)\n";
    } else {
      // This line is here just for completeness' sake.  It will never
      // be executed as currently the ExplainMatchResultTo() function
      // is called only when the mock function call does NOT match the
      // expectation.
      *os << "The call matches the expectation.\n";
    }
  }

  // Returns the action that should be taken for the current invocation.
  auto GetCurrentAction(const FunctionMocker<F>* mocker,
                        const ArgumentTuple& args) const -> const Action<F>&
  GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex) {
    g_gmock_mutex.AssertHeld();
    const int count = call_count();
    Assert(count >= 1, __FILE__, __LINE__,
           "call_count() is <= 0 when GetCurrentAction() is "
           "called - this should never happen.");

    const int action_count = static_cast<int>(untyped_actions_.size());
    if (action_count > 0 && !repeated_action_specified_ &&
        count > action_count) {
      // If there is at least one WillOnce() and no WillRepeatedly(),
      // we warn the user when the WillOnce() clauses ran out.
      std::stringstream ss;
      DescribeLocationTo(&ss);
      ss << "Actions ran out in " << source_text() << "...\n"
          << "Called " << count << " times, but only "
          << action_count << " WillOnce()"
          << (action_count == 1 ? " is" : "s are") << " specified - ";
      mocker->DescribeDefaultActionTo(args, &ss);
      Log(kWarning, ss.str(), 1);
    }

    return count <= action_count
             ? *static_cast<const Action<F>*>(
               untyped_actions_[static_cast<size_t>(count - 1)])
             : repeated_action();
  }

  // Given the arguments of a mock function call, if the call will
  // over-saturate this expectation, returns the default action;
  // otherwise, returns the next action in this expectation.  Also
  // describes *what* happened to 'what', and explains *why* Google
  // Mock does it to 'why'.  This method is not const as it calls
  // IncrementCallCount().  A return value of NULL means the default
  // action.
  auto GetActionForArguments(const FunctionMocker<F>* mocker,
                             const ArgumentTuple& args,
                             std::ostream* what,
                             std::ostream* why) -> const Action<F>*
  GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex) {
    g_gmock_mutex.AssertHeld();
    if (IsSaturated()) {
      // We have an excessive call.
      IncrementCallCount();
      *what << "Mock function called more times than expected - ";
      mocker->DescribeDefaultActionTo(args, what);
      DescribeCallCountTo(why);

      return nullptr;
    }

    IncrementCallCount();
    RetireAllPreRequisites();

    if (retires_on_saturation_ && IsSaturated()) {
      Retire();
    }

    // Must be done after IncrementCount()!
    *what << "Mock function call matches " << source_text() << "...\n";
    return &GetCurrentAction(mocker, args);
  }

  // All the fields below won't change once the EXPECT_CALL()
  // statement finishes.
  FunctionMocker<F>* const owner_;
  ArgumentMatcherTuple matchers_;
  Matcher<const ArgumentTuple&> extra_matcher_;
  Action<F> repeated_action_;

  GTEST_DISALLOW_COPY_AND_ASSIGN_(TypedExpectation);
}; // class TypedExpectation

// A MockSpec object is used by ON_CALL() or EXPECT_CALL() for
// specifying the default behavior of, or expectation on, a mock
// function.

// Note: class MockSpec really belongs to the ::testing namespace.
// However if we define it in ::testing, MSVC will complain when
// classes in ::testing::internal declare it as a friend class
// template.  To workaround this compiler bug, we define MockSpec in
// ::testing::internal and import it into ::testing.

// Logs a message including file and line number information.
GTEST_API_ auto LogWithLocation(LogSeverity severity,
                                const char* file, int line,
                                const std::string& message) -> void;

template <typename F>
class MockSpec {
public:
  using ArgumentTuple = typename Function<F>::ArgumentTuple;
  using ArgumentMatcherTuple = typename Function<F>::ArgumentMatcherTuple;

  // Constructs a MockSpec object, given the function mocker object
  // that the spec is associated with.
  MockSpec(FunctionMocker<F>* function_mocker,
           const ArgumentMatcherTuple& matchers)
    : function_mocker_(function_mocker),
      matchers_(matchers) {}

  // Adds a new default action spec to the function mocker and returns
  // the newly created spec.
  auto InternalDefaultActionSetAt(
      const char* file, int line, const char* obj,
      const char* call) -> OnCallSpec<F>& {
    LogWithLocation(kInfo, file, line,
                    std::string("ON_CALL(") + obj + ", " + call + ") invoked");
    return function_mocker_->AddNewOnCallSpec(file, line, matchers_);
  }

  // Adds a new expectation spec to the function mocker and returns
  // the newly created spec.
  auto InternalExpectedAt(
      const char* file, int line, const char* obj,
      const char* call) -> TypedExpectation<F>& {
    const std::string source_text(std::string("EXPECT_CALL(") + obj + ", " +
                                  call + ")");
    LogWithLocation(kInfo, file, line, source_text + " invoked");
    return function_mocker_->AddNewExpectation(
        file, line, source_text, matchers_);
  }

  // This operator overload is used to swallow the superfluous parameter list
  // introduced by the ON/EXPECT_CALL macros. See the macro comments for more
  // explanation.
  auto operator()(const WithoutMatchers&, void* const) -> MockSpec<F>& {
    return *this;
  }

private:
  template <typename Function>
  friend class FunctionMocker;

  // The function mocker that owns this spec.
  FunctionMocker<F>* const function_mocker_;
  // The argument matchers specified in the spec.
  ArgumentMatcherTuple matchers_;
}; // class MockSpec

// Wrapper type for generically holding an ordinary value or lvalue reference.
// If T is not a reference type, it must be copyable or movable.
// ReferenceOrValueWrapper<T> is movable, and will also be copyable unless
// T is a move-only value type (which means that it will always be copyable
// if the current platform does not support move semantics).
//
// The primary template defines handling for values, but function header
// comments describe the contract for the whole template (including
// specializations).
template <typename T>
class ReferenceOrValueWrapper {
public:
  // Constructs a wrapper from the given value/reference.
  explicit ReferenceOrValueWrapper(T value)
    : value_(std::move(value)) { }

  // Unwraps and returns the underlying value/reference, exactly as
  // originally passed. The behavior of calling this more than once on
  // the same object is unspecified.
  auto Unwrap() -> T { return std::move(value_); }

  // Provides nondestructive access to the underlying value/reference.
  // Always returns a const reference (more precisely,
  // const std::add_lvalue_reference<T>::type). The behavior of calling this
  // after calling Unwrap on the same object is unspecified.
  auto Peek() const -> const T& {
    return value_;
  }

private:
  T value_;
};

// Specialization for lvalue reference types. See primary template
// for documentation.
template <typename T>
class ReferenceOrValueWrapper<T&> {
public:
  // Workaround for debatable pass-by-reference lint warning (c-library-team
  // policy precludes NOLINT in this context)
  using reference = T&;

  explicit ReferenceOrValueWrapper(reference ref)
    : value_ptr_(&ref) {}

  auto Unwrap() -> T& { return *value_ptr_; }
  auto Peek() const -> const T& { return *value_ptr_; }

private:
  T* value_ptr_;
};

// C++ treats the void type specially.  For example, you cannot define
// a void-typed variable or pass a void value to a function.
// ActionResultHolder<T> holds a value of type T, where T must be a
// copyable type or void (T doesn't need to be default-constructable).
// It hides the syntactic difference between void and other types, and
// is used to unify the code for invoking both void-returning and
// non-void-returning mock functions.

// Untyped base class for ActionResultHolder<T>.
class UntypedActionResultHolderBase {
public:
  virtual ~UntypedActionResultHolderBase() {}

  // Prints the held value as an action's result to os.
  virtual auto PrintAsActionResult(std::ostream* os) const -> void = 0;
};

// This generic definition is used when T is not void.
template <typename T>
class ActionResultHolder : public UntypedActionResultHolderBase {
public:
  // Returns the held value. Must not be called more than once.
  auto Unwrap() -> T {
    return result_.Unwrap();
  }

  // Prints the held value as an action's result to os.
  auto PrintAsActionResult(std::ostream* os) const -> void override {
    *os << "\n          Returns: ";
    // T may be a reference type, so we don't use UniversalPrint().
    UniversalPrinter<T>::Print(result_.Peek(), os);
  }

  // Performs the given mock function's default action and returns the
  // result in a new-ed ActionResultHolder.
  template <typename F>
  static auto PerformDefaultAction(
      const FunctionMocker<F>* func_mocker,
      typename Function<F>::ArgumentTuple&& args,
      const std::string& call_description) -> ActionResultHolder* {
    return new ActionResultHolder(Wrapper(func_mocker->PerformDefaultAction(
        std::move(args), call_description)));
  }

  // Performs the given action and returns the result in a new-ed
  // ActionResultHolder.
  template <typename F>
  static auto PerformAction(
      const Action<F>& action,
      typename Function<F>::ArgumentTuple&& args) -> ActionResultHolder* {
    return new ActionResultHolder(
        Wrapper(action.Perform(std::move(args))));
  }

private:
  using Wrapper = ReferenceOrValueWrapper<T>;

  explicit ActionResultHolder(Wrapper result)
    : result_(std::move(result)) { }

  Wrapper result_;

  GTEST_DISALLOW_COPY_AND_ASSIGN_(ActionResultHolder);
};

// Specialization for T = void.
template <>
class ActionResultHolder<void> : public UntypedActionResultHolderBase {
public:
  auto Unwrap() -> void { }

  auto PrintAsActionResult(std::ostream* /* os */) const -> void override {}

  // Performs the given mock function's default action and returns ownership
  // of an empty ActionResultHolder*.
  template <typename F>
  static auto PerformDefaultAction(
      const FunctionMocker<F>* func_mocker,
      typename Function<F>::ArgumentTuple&& args,
      const std::string& call_description) -> ActionResultHolder* {
    func_mocker->PerformDefaultAction(std::move(args), call_description);
    return new ActionResultHolder;
  }

  // Performs the given action and returns ownership of an empty
  // ActionResultHolder*.
  template <typename F>
  static auto PerformAction(
      const Action<F>& action,
      typename Function<F>::ArgumentTuple&& args) -> ActionResultHolder* {
    action.Perform(std::move(args));
    return new ActionResultHolder;
  }

private:
  ActionResultHolder() {}
  GTEST_DISALLOW_COPY_AND_ASSIGN_(ActionResultHolder);
};

template <typename F>
class FunctionMocker;

template <typename R, typename... Args>
class FunctionMocker<R(Args ...)> final : public UntypedFunctionMockerBase {
  using F = R(Args ...);

public:
  using Result = R;
  using ArgumentTuple = std::tuple<Args...>;
  using ArgumentMatcherTuple = std::tuple<Matcher<Args>...>;

  FunctionMocker() {}

  // There is no generally useful and implementable semantics of
  // copying a mock object, so copying a mock is usually a user error.
  // Thus we disallow copying function mockers.  If the user really
  // wants to copy a mock object, they should implement their own copy
  // operation, for example:
  //
  //   class MockFoo : public Foo {
  //    public:
  //     // Defines a copy constructor explicitly.
  //     MockFoo(const MockFoo& src) {}
  //     ...
  //   };
  FunctionMocker(const FunctionMocker&) = delete;
  auto operator=(const FunctionMocker&) -> FunctionMocker& = delete;

  // The destructor verifies that all expectations on this mock
  // function have been satisfied.  If not, it will report Google Test
  // non-fatal failures for the violations.
  ~FunctionMocker() override GTEST_LOCK_EXCLUDED_(g_gmock_mutex) {
    MutexLock l(&g_gmock_mutex);
    VerifyAndClearExpectationsLocked();
    Mock::UnregisterLocked(this);
    ClearDefaultActionsLocked();
  }

  // Returns the ON_CALL spec that matches this mock function with the
  // given arguments; returns NULL if no matching ON_CALL is found.
  // L = *
  auto FindOnCallSpec(
      const ArgumentTuple& args) const -> const OnCallSpec<F>* {
    for (auto it
             = untyped_on_call_specs_.rbegin();
         it != untyped_on_call_specs_.rend(); ++it) {
      const OnCallSpec<F>* spec = static_cast<const OnCallSpec<F>*>(*it);
      if (spec->Matches(args)) {
        return spec;
      }
    }

    return nullptr;
  }

  // Performs the default action of this mock function on the given
  // arguments and returns the result. Asserts (or throws if
  // exceptions are enabled) with a helpful call descrption if there
  // is no valid return value. This method doesn't depend on the
  // mutable state of this object, and thus can be called concurrently
  // without locking.
  // L = *
  auto PerformDefaultAction(ArgumentTuple&& args,
                            const std::string& call_description) const ->
  Result {
    const OnCallSpec<F>* const spec =
        this->FindOnCallSpec(args);
    if (spec != nullptr) {
      return spec->GetAction().Perform(std::move(args));
    }
    const std::string message =
        call_description +
        "\n    The mock function has no default action "
        "set, and its return type has no default value set.";
#if GTEST_HAS_EXCEPTIONS
    if (!DefaultValue<Result>::Exists()) {
      throw std::runtime_error(message);
    }
#else
    Assert(DefaultValue<Result>::Exists(), "", -1, message);
#endif
    return DefaultValue<Result>::Get();
  }

  // Performs the default action with the given arguments and returns
  // the action's result.  The call description string will be used in
  // the error message to describe the call in the case the default
  // action fails.  The caller is responsible for deleting the result.
  // L = *
  auto UntypedPerformDefaultAction(
      void* untyped_args, // must point to an ArgumentTuple
      const std::string& call_description) const ->
  UntypedActionResultHolderBase* override {
    ArgumentTuple* args = static_cast<ArgumentTuple*>(untyped_args);
    return ResultHolder::PerformDefaultAction(this, std::move(*args),
                                              call_description);
  }

  // Performs the given action with the given arguments and returns
  // the action's result.  The caller is responsible for deleting the
  // result.
  // L = *
  auto UntypedPerformAction(
      const void* untyped_action,
      void* untyped_args) const -> UntypedActionResultHolderBase* override {
    // Make a copy of the action before performing it, in case the
    // action deletes the mock object (and thus deletes itself).
    const Action<F> action = *static_cast<const Action<F>*>(untyped_action);
    ArgumentTuple* args = static_cast<ArgumentTuple*>(untyped_args);
    return ResultHolder::PerformAction(action, std::move(*args));
  }

  // Implements UntypedFunctionMockerBase::ClearDefaultActionsLocked():
  // clears the ON_CALL()s set on this mock function.
  auto ClearDefaultActionsLocked() -> void override
  GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex) {
    g_gmock_mutex.AssertHeld();

    // Deleting our default actions may trigger other mock objects to be
    // deleted, for example if an action contains a reference counted smart
    // pointer to that mock object, and that is the last reference. So if we
    // delete our actions within the context of the global mutex we may deadlock
    // when this method is called again. Instead, make a copy of the set of
    // actions to delete, clear our set within the mutex, and then delete the
    // actions outside of the mutex.
    UntypedOnCallSpecs specs_to_delete;
    untyped_on_call_specs_.swap(specs_to_delete);

    g_gmock_mutex.Unlock();
    for (UntypedOnCallSpecs::const_iterator it =
             specs_to_delete.begin();
         it != specs_to_delete.end(); ++it) {
      delete static_cast<const OnCallSpec<F>*>(*it);
    }

    // Lock the mutex again, since the caller expects it to be locked when we
    // return.
    g_gmock_mutex.Lock();
  }

  // Returns the result of invoking this mock function with the given
  // arguments.  This function can be safely called from multiple
  // threads concurrently.
  auto Invoke(Args ...args) -> Result GTEST_LOCK_EXCLUDED_(g_gmock_mutex) {
    ArgumentTuple tuple(std::forward<Args>(args)...);
    std::unique_ptr<ResultHolder> holder(DownCast_<ResultHolder*>(
        this->UntypedInvokeWith(static_cast<void*>(&tuple))));
    return holder->Unwrap();
  }

  auto With(Matcher<Args> ...m) -> MockSpec<F> {
    return MockSpec<F>(this, std::make_tuple(std::move(m)...));
  }

protected:
  template <typename Function>
  friend class MockSpec;

  using ResultHolder = ActionResultHolder<Result>;

  // Adds and returns a default action spec for this mock function.
  auto AddNewOnCallSpec(
      const char* file, int line,
      const ArgumentMatcherTuple& m) -> OnCallSpec<F>&
  GTEST_LOCK_EXCLUDED_(g_gmock_mutex) {
    Mock::RegisterUseByOnCallOrExpectCall(MockObject(), file, line);
    OnCallSpec<F>* const on_call_spec = new OnCallSpec<F>(file, line, m);
    untyped_on_call_specs_.push_back(on_call_spec);
    return *on_call_spec;
  }

  // Adds and returns an expectation spec for this mock function.
  auto AddNewExpectation(const char* file, int line,
                         const std::string& source_text,
                         const ArgumentMatcherTuple& m) -> TypedExpectation<F>&
  GTEST_LOCK_EXCLUDED_(g_gmock_mutex) {
    Mock::RegisterUseByOnCallOrExpectCall(MockObject(), file, line);
    TypedExpectation<F>* const expectation =
        new TypedExpectation<F>(this, file, line, source_text, m);
    const std::shared_ptr<ExpectationBase> untyped_expectation(expectation);
    // See the definition of untyped_expectations_ for why access to
    // it is unprotected here.
    untyped_expectations_.push_back(untyped_expectation);

    // Adds this expectation into the implicit sequence if there is one.
    Sequence* const implicit_sequence = g_gmock_implicit_sequence.get();
    if (implicit_sequence != nullptr) {
      implicit_sequence->AddExpectation(Expectation(untyped_expectation));
    }

    return *expectation;
  }

private:
  template <typename Func>
  friend class TypedExpectation;

  // Some utilities needed for implementing UntypedInvokeWith().

  // Describes what default action will be performed for the given
  // arguments.
  // L = *
  auto DescribeDefaultActionTo(const ArgumentTuple& args,
                               std::ostream* os) const -> void {
    const OnCallSpec<F>* const spec = FindOnCallSpec(args);

    if (spec == nullptr) {
      *os << (std::is_void<Result>::value
                ? "returning directly.\n"
                : "returning default value.\n");
    } else {
      *os << "taking default action specified at:\n"
          << FormatFileLocation(spec->file(), spec->line()) << "\n";
    }
  }

  // Writes a message that the call is uninteresting (i.e. neither
  // explicitly expected nor explicitly unexpected) to the given
  // ostream.
  auto UntypedDescribeUninterestingCall(const void* untyped_args,
                                        std::ostream* os) const -> void override
  GTEST_LOCK_EXCLUDED_(g_gmock_mutex) {
    const ArgumentTuple& args =
        *static_cast<const ArgumentTuple*>(untyped_args);
    *os << "Uninteresting mock function call - ";
    DescribeDefaultActionTo(args, os);
    *os << "    Function call: " << Name();
    UniversalPrint(args, os);
  }

  // Returns the expectation that matches the given function arguments
  // (or NULL is there's no match); when a match is found,
  // untyped_action is set to point to the action that should be
  // performed (or NULL if the action is "do default"), and
  // is_excessive is modified to indicate whether the call exceeds the
  // expected number.
  //
  // Critical section: We must find the matching expectation and the
  // corresponding action that needs to be taken in an ATOMIC
  // transaction.  Otherwise another thread may call this mock
  // method in the middle and mess up the state.
  //
  // However, performing the action has to be left out of the critical
  // section.  The reason is that we have no control on what the
  // action does (it can invoke an arbitrary user function or even a
  // mock function) and excessive locking could cause a dead lock.
  auto UntypedFindMatchingExpectation(
      const void* untyped_args, const void** untyped_action, bool* is_excessive,
      std::ostream* what, std::ostream* why) -> const ExpectationBase* override
  GTEST_LOCK_EXCLUDED_(g_gmock_mutex) {
    const ArgumentTuple& args =
        *static_cast<const ArgumentTuple*>(untyped_args);
    MutexLock l(&g_gmock_mutex);
    TypedExpectation<F>* exp = this->FindMatchingExpectationLocked(args);
    if (exp == nullptr) {
      // A match wasn't found.
      this->FormatUnexpectedCallMessageLocked(args, what, why);
      return nullptr;
    }

    // This line must be done before calling GetActionForArguments(),
    // which will increment the call count for *exp and thus affect
    // its saturation status.
    *is_excessive = exp->IsSaturated();
    const Action<F>* action = exp->GetActionForArguments(this, args, what, why);
    if (action != nullptr && action->IsDoDefault()) {
      action = nullptr; // Normalize "do default" to NULL.
    }
    *untyped_action = action;
    return exp;
  }

  // Prints the given function arguments to the ostream.
  auto UntypedPrintArgs(const void* untyped_args,
                        std::ostream* os) const -> void override {
    const ArgumentTuple& args =
        *static_cast<const ArgumentTuple*>(untyped_args);
    UniversalPrint(args, os);
  }

  // Returns the expectation that matches the arguments, or NULL if no
  // expectation matches them.
  auto FindMatchingExpectationLocked(
      const ArgumentTuple& args) const -> TypedExpectation<F>*
  GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex) {
    g_gmock_mutex.AssertHeld();
    // See the definition of untyped_expectations_ for why access to
    // it is unprotected here.
    for (auto it =
             untyped_expectations_.rbegin();
         it != untyped_expectations_.rend(); ++it) {
      TypedExpectation<F>* const exp =
          static_cast<TypedExpectation<F>*>(it->get());
      if (exp->ShouldHandleArguments(args)) {
        return exp;
      }
    }
    return nullptr;
  }

  // Returns a message that the arguments don't match any expectation.
  auto FormatUnexpectedCallMessageLocked(
      const ArgumentTuple& args,
      std::ostream* os,
      std::ostream* why) const -> void
  GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex) {
    g_gmock_mutex.AssertHeld();
    *os << "\nUnexpected mock function call - ";
    DescribeDefaultActionTo(args, os);
    PrintTriedExpectationsLocked(args, why);
  }

  // Prints a list of expectations that have been tried against the
  // current mock function call.
  auto PrintTriedExpectationsLocked(
      const ArgumentTuple& args,
      std::ostream* why) const -> void
  GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex) {
    g_gmock_mutex.AssertHeld();
    const size_t count = untyped_expectations_.size();
    *why << "Google Mock tried the following " << count << " "
        << (count == 1
              ? "expectation, but it didn't match"
              : "expectations, but none matched")
        << ":\n";
    for (size_t i = 0; i < count; i++) {
      TypedExpectation<F>* const expectation =
          static_cast<TypedExpectation<F>*>(untyped_expectations_[i].get());
      *why << "\n";
      expectation->DescribeLocationTo(why);
      if (count > 1) {
        *why << "tried expectation #" << i << ": ";
      }
      *why << expectation->source_text() << "...\n";
      expectation->ExplainMatchResultTo(args, why);
      expectation->DescribeCallCountTo(why);
    }
  }
}; // class FunctionMocker

// Reports an uninteresting call (whose description is in msg) in the
// manner specified by 'reaction'.
auto ReportUninterestingCall(CallReaction reaction,
                             const std::string& msg) -> void;

} // namespace internal

namespace internal {

template <typename F>
class MockFunction;

template <typename R, typename... Args>
class MockFunction<R(Args ...)> {
public:
  MockFunction(const MockFunction&) = delete;
  auto operator=(const MockFunction&) -> MockFunction& = delete;

  auto AsStdFunction() -> std::function<R(Args ...)> {
    return [this](Args ... args) -> R
    {
      return this->Call(std::forward<Args>(args)...);
    };
  }

  // Implementation detail: the expansion of the MOCK_METHOD macro.
  auto Call(Args ...args) -> R {
    mock_.SetOwnerAndName(this, "Call");
    return mock_.Invoke(std::forward<Args>(args)...);
  }

  auto gmock_Call(Matcher<Args> ...m) -> MockSpec<R(Args ...)> {
    mock_.RegisterOwner(this);
    return mock_.With(std::move(m)...);
  }

  auto gmock_Call(const WithoutMatchers&,
                  R (*)(Args ...)) -> MockSpec<R(Args ...)> {
    return this->gmock_Call(testing::A<Args>()...);
  }

protected:
  MockFunction() = default;
  ~MockFunction() = default;

private:
  FunctionMocker<R(Args ...)> mock_;
};

/*
The SignatureOf<F> struct is a meta-function returning function signature
corresponding to the provided F argument.

It makes use of MockFunction easier by allowing it to accept more F arguments
than just function signatures.

Specializations provided here cover only a signature type itself and
std::function. However, if need be it can be easily extended to cover also other
types (like for example boost::function).
*/

template <typename F>
struct SignatureOf;

template <typename R, typename... Args>
struct SignatureOf<R(Args ...)> {
  using type = R(Args ...);
};

template <typename F>
struct SignatureOf<std::function<F>> : SignatureOf<F> {};

template <typename F>
using SignatureOfT = typename SignatureOf<F>::type;

} // namespace internal

// A MockFunction<F> type has one mock method whose type is
// internal::SignatureOfT<F>.  It is useful when you just want your
// test code to emit some messages and have Google Mock verify the
// right messages are sent (and perhaps at the right times).  For
// example, if you are exercising code:
//
//   Foo(1);
//   Foo(2);
//   Foo(3);
//
// and want to verify that Foo(1) and Foo(3) both invoke
// mock.Bar("a"), but Foo(2) doesn't invoke anything, you can write:
//
// TEST(FooTest, InvokesBarCorrectly) {
//   MyMock mock;
//   MockFunction<void(string check_point_name)> check;
//   {
//     InSequence s;
//
//     EXPECT_CALL(mock, Bar("a"));
//     EXPECT_CALL(check, Call("1"));
//     EXPECT_CALL(check, Call("2"));
//     EXPECT_CALL(mock, Bar("a"));
//   }
//   Foo(1);
//   check.Call("1");
//   Foo(2);
//   check.Call("2");
//   Foo(3);
// }
//
// The expectation spec says that the first Bar("a") must happen
// before check point "1", the second Bar("a") must happen after check
// point "2", and nothing should happen between the two check
// points. The explicit check points make it easy to tell which
// Bar("a") is called by which call to Foo().
//
// MockFunction<F> can also be used to exercise code that accepts
// std::function<internal::SignatureOfT<F>> callbacks. To do so, use
// AsStdFunction() method to create std::function proxy forwarding to
// original object's Call. Example:
//
// TEST(FooTest, RunsCallbackWithBarArgument) {
//   MockFunction<int(string)> callback;
//   EXPECT_CALL(callback, Call("bar")).WillOnce(Return(1));
//   Foo(callback.AsStdFunction());
// }
//
// The internal::SignatureOfT<F> indirection allows to use other types
// than just function signature type. This is typically useful when
// providing a mock for a predefined std::function type. Example:
//
// using FilterPredicate = std::function<bool(string)>;
// void MyFilterAlgorithm(FilterPredicate predicate);
//
// TEST(FooTest, FilterPredicateAlwaysAccepts) {
//   MockFunction<FilterPredicate> predicateMock;
//   EXPECT_CALL(predicateMock, Call(_)).WillRepeatedly(Return(true));
//   MyFilterAlgorithm(predicateMock.AsStdFunction());
// }
template <typename F>
class MockFunction : public internal::MockFunction<internal::SignatureOfT<F>> {
  using Base = internal::MockFunction<internal::SignatureOfT<F>>;

public:
  using Base::Base;
};

// The style guide prohibits "using" statements in a namespace scope
// inside a header file.  However, the MockSpec class template is
// meant to be defined in the ::testing namespace.  The following line
// is just a trick for working around a bug in MSVC 8.0, which cannot
// handle it if we define MockSpec in ::testing.
using internal::MockSpec;

// Const(x) is a convenient function for obtaining a const reference
// to x.  This is useful for setting expectations on an overloaded
// const mock method, e.g.
//
//   class MockFoo : public FooInterface {
//    public:
//     MOCK_METHOD0(Bar, int());
//     MOCK_CONST_METHOD0(Bar, int&());
//   };
//
//   MockFoo foo;
//   // Expects a call to non-const MockFoo::Bar().
//   EXPECT_CALL(foo, Bar());
//   // Expects a call to const MockFoo::Bar().
//   EXPECT_CALL(Const(foo), Bar());
template <typename T>
inline auto Const(const T& x) -> const T& { return x; }

// Constructs an Expectation object that references and co-owns exp.
inline Expectation::Expectation(internal::ExpectationBase& exp) // NOLINT
  : expectation_base_(exp.GetHandle().expectation_base()) {}

} // namespace testing

GTEST_DISABLE_MSC_WARNINGS_POP_() //  4251

// Implementation for ON_CALL and EXPECT_CALL macros. A separate macro is
// required to avoid compile errors when the name of the method used in call is
// a result of macro expansion. See CompilesWithMethodNameExpandedFromMacro
// tests in internal/gmock-spec-builders_test.cc for more details.
//
// This macro supports statements both with and without parameter matchers. If
// the parameter list is omitted, gMock will accept any parameters, which allows
// tests to be written that don't need to encode the number of method
// parameter. This technique may only be used for non-overloaded methods.
//
//   // These are the same:
//   ON_CALL(mock, NoArgsMethod()).WillByDefault(...);
//   ON_CALL(mock, NoArgsMethod).WillByDefault(...);
//
//   // As are these:
//   ON_CALL(mock, TwoArgsMethod(_, _)).WillByDefault(...);
//   ON_CALL(mock, TwoArgsMethod).WillByDefault(...);
//
//   // Can also specify args if you want, of course:
//   ON_CALL(mock, TwoArgsMethod(_, 45)).WillByDefault(...);
//
//   // Overloads work as long as you specify parameters:
//   ON_CALL(mock, OverloadedMethod(_)).WillByDefault(...);
//   ON_CALL(mock, OverloadedMethod(_, _)).WillByDefault(...);
//
//   // Oops! Which overload did you want?
//   ON_CALL(mock, OverloadedMethod).WillByDefault(...);
//     => ERROR: call to member function 'gmock_OverloadedMethod' is ambiguous
//
// How this works: The mock class uses two overloads of the gmock_Method
// expectation setter method plus an operator() overload on the MockSpec object.
// In the matcher list form, the macro expands to:
//
//   // This statement:
//   ON_CALL(mock, TwoArgsMethod(_, 45))...
//
//   // ...expands to:
//   mock.gmock_TwoArgsMethod(_, 45)(WithoutMatchers(), nullptr)...
//   |-------------v---------------||------------v-------------|
//       invokes first overload        swallowed by operator()
//
//   // ...which is essentially:
//   mock.gmock_TwoArgsMethod(_, 45)...
//
// Whereas the form without a matcher list:
//
//   // This statement:
//   ON_CALL(mock, TwoArgsMethod)...
//
//   // ...expands to:
//   mock.gmock_TwoArgsMethod(WithoutMatchers(), nullptr)...
//   |-----------------------v--------------------------|
//                 invokes second overload
//
//   // ...which is essentially:
//   mock.gmock_TwoArgsMethod(_, _)...
//
// The WithoutMatchers() argument is used to disambiguate overloads and to
// block the caller from accidentally invoking the second overload directly. The
// second argument is an internal type derived from the method signature. The
// failure to disambiguate two overloads of this method in the ON_CALL statement
// is how we block callers from setting expectations on overloaded methods.
#define GMOCK_ON_CALL_IMPL_(mock_expr, Setter, call)                    \
  ((mock_expr).gmock_##call)(::testing::internal::GetWithoutMatchers(), \
                             nullptr)                                   \
      .Setter(__FILE__, __LINE__, #mock_expr, #call)

#define ON_CALL(obj, call) \
  GMOCK_ON_CALL_IMPL_(obj, InternalDefaultActionSetAt, call)

#define EXPECT_CALL(obj, call) \
  GMOCK_ON_CALL_IMPL_(obj, InternalExpectedAt, call)

#endif  // GOOGLEMOCK_INCLUDE_GMOCK_GMOCK_SPEC_BUILDERS_H_
