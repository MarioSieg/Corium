// File: gmock-spec-builders.cc
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

#include "gmock/gmock-spec-builders.h"

#include <stdlib.h>

#include <iostream>  // NOLINT
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "gtest/internal/gtest-port.h"

#if GTEST_OS_CYGWIN || GTEST_OS_LINUX || GTEST_OS_MAC
# include <unistd.h>  // NOLINT
#endif

// Silence C4800 (C4800: 'int *const ': forcing value
// to bool 'true' or 'false') for MSVC 15
#ifdef _MSC_VER
#if _MSC_VER == 1900
#  pragma warning(push)
#  pragma warning(disable:4800)
#endif
#endif

namespace testing {
namespace internal {

// Protects the mock object registry (in class Mock), all function
// mockers, and all expectations.
GTEST_API_ GTEST_DEFINE_STATIC_MUTEX_(g_gmock_mutex);

// Logs a message including file and line number information.
GTEST_API_ auto LogWithLocation(LogSeverity severity,
                                const char* file, int line,
                                const std::string& message) -> void {
  std::ostringstream s;
  s << FormatFileLocation(file, line) << " " << message
      << std::endl;
  Log(severity, s.str(), 0);
}

// Constructs an ExpectationBase object.
ExpectationBase::ExpectationBase(const char* a_file, int a_line,
                                 const std::string& a_source_text)
  : file_(a_file),
    line_(a_line),
    source_text_(a_source_text),
    cardinality_specified_(false),
    cardinality_(Exactly(1)),
    call_count_(0),
    retired_(false),
    extra_matcher_specified_(false),
    repeated_action_specified_(false),
    retires_on_saturation_(false),
    last_clause_(kNone),
    action_count_checked_(false) {}

// Destructs an ExpectationBase object.
ExpectationBase::~ExpectationBase() {}

// Explicitly specifies the cardinality of this expectation.  Used by
// the subclasses to implement the .Times() clause.
auto ExpectationBase::SpecifyCardinality(
    const Cardinality& a_cardinality) -> void {
  cardinality_specified_ = true;
  cardinality_ = a_cardinality;
}

// Retires all pre-requisites of this expectation.
auto ExpectationBase::RetireAllPreRequisites() -> void
GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex) {
  if (is_retired()) {
    // We can take this short-cut as we never retire an expectation
    // until we have retired all its pre-requisites.
    return;
  }

  std::vector<ExpectationBase*> expectations(1, this);
  while (!expectations.empty()) {
    ExpectationBase* exp = expectations.back();
    expectations.pop_back();

    for (auto it =
             exp->immediate_prerequisites_.begin();
         it != exp->immediate_prerequisites_.end(); ++it) {
      ExpectationBase* next = it->expectation_base().get();
      if (!next->is_retired()) {
        next->Retire();
        expectations.push_back(next);
      }
    }
  }
}

// Returns true if and only if all pre-requisites of this expectation
// have been satisfied.
auto ExpectationBase::AllPrerequisitesAreSatisfied() const -> bool
GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex) {
  g_gmock_mutex.AssertHeld();
  std::vector<const ExpectationBase*> expectations(1, this);
  while (!expectations.empty()) {
    const ExpectationBase* exp = expectations.back();
    expectations.pop_back();

    for (auto it =
             exp->immediate_prerequisites_.begin();
         it != exp->immediate_prerequisites_.end(); ++it) {
      const ExpectationBase* next = it->expectation_base().get();
      if (!next->IsSatisfied()) {
        return false;
      }
      expectations.push_back(next);
    }
  }
  return true;
}

// Adds unsatisfied pre-requisites of this expectation to 'result'.
auto ExpectationBase::FindUnsatisfiedPrerequisites(
    ExpectationSet* result) const -> void
GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex) {
  g_gmock_mutex.AssertHeld();
  std::vector<const ExpectationBase*> expectations(1, this);
  while (!expectations.empty()) {
    const ExpectationBase* exp = expectations.back();
    expectations.pop_back();

    for (auto it =
             exp->immediate_prerequisites_.begin();
         it != exp->immediate_prerequisites_.end(); ++it) {
      const ExpectationBase* next = it->expectation_base().get();

      if (next->IsSatisfied()) {
        // If *it is satisfied and has a call count of 0, some of its
        // pre-requisites may not be satisfied yet.
        if (next->call_count_ == 0) {
          expectations.push_back(next);
        }
      } else {
        // Now that we know next is unsatisfied, we are not so interested
        // in whether its pre-requisites are satisfied.  Therefore we
        // don't iterate into it here.
        *result += *it;
      }
    }
  }
}

// Describes how many times a function call matching this
// expectation has occurred.
auto ExpectationBase::DescribeCallCountTo(std::ostream* os) const -> void
GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex) {
  g_gmock_mutex.AssertHeld();

  // Describes how many times the function is expected to be called.
  *os << "         Expected: to be ";
  cardinality().DescribeTo(os);
  *os << "\n           Actual: ";
  Cardinality::DescribeActualCallCountTo(call_count(), os);

  // Describes the state of the expectation (e.g. is it satisfied?
  // is it active?).
  *os << " - " << (IsOverSaturated()
                     ? "over-saturated"
                     : IsSaturated()
                     ? "saturated"
                     : IsSatisfied()
                     ? "satisfied"
                     : "unsatisfied")
      << " and "
      << (is_retired() ? "retired" : "active");
}

// Checks the action count (i.e. the number of WillOnce() and
// WillRepeatedly() clauses) against the cardinality if this hasn't
// been done before.  Prints a warning if there are too many or too
// few actions.
auto ExpectationBase::CheckActionCountIfNotDone() const -> void
GTEST_LOCK_EXCLUDED_(mutex_) {
  bool should_check = false;
  {
    MutexLock l(&mutex_);
    if (!action_count_checked_) {
      action_count_checked_ = true;
      should_check = true;
    }
  }

  if (should_check) {
    if (!cardinality_specified_) {
      // The cardinality was inferred - no need to check the action
      // count against it.
      return;
    }

    // The cardinality was explicitly specified.
    const int action_count = static_cast<int>(untyped_actions_.size());
    const int upper_bound = cardinality().ConservativeUpperBound();
    const int lower_bound = cardinality().ConservativeLowerBound();
    bool too_many; // True if there are too many actions, or false
    // if there are too few.
    if (action_count > upper_bound ||
        action_count == upper_bound && repeated_action_specified_) {
      too_many = true;
    } else if (0 < action_count && action_count < lower_bound &&
               !repeated_action_specified_) {
      too_many = false;
    } else {
      return;
    }

    std::stringstream ss;
    DescribeLocationTo(&ss);
    ss << "Too " << (too_many ? "many" : "few")
        << " actions specified in " << source_text() << "...\n"
        << "Expected to be ";
    cardinality().DescribeTo(&ss);
    ss << ", but has " << (too_many ? "" : "only ")
        << action_count << " WillOnce()"
        << (action_count == 1 ? "" : "s");
    if (repeated_action_specified_) {
      ss << " and a WillRepeatedly()";
    }
    ss << ".";
    Log(kWarning, ss.str(), -1); // -1 means "don't print stack trace".
  }
}

// Implements the .Times() clause.
auto ExpectationBase::UntypedTimes(const Cardinality& a_cardinality) -> void {
  if (last_clause_ == kTimes) {
    ExpectSpecProperty(false,
                       ".Times() cannot appear "
                       "more than once in an EXPECT_CALL().");
  } else {
    ExpectSpecProperty(last_clause_ < kTimes,
                       ".Times() cannot appear after "
                       ".InSequence(), .WillOnce(), .WillRepeatedly(), "
                       "or .RetiresOnSaturation().");
  }
  last_clause_ = kTimes;

  SpecifyCardinality(a_cardinality);
}

// Points to the implicit sequence introduced by a living InSequence
// object (if any) in the current thread or NULL.
GTEST_API_ ThreadLocal<Sequence*> g_gmock_implicit_sequence;

// Reports an uninteresting call (whose description is in msg) in the
// manner specified by 'reaction'.
auto ReportUninterestingCall(CallReaction reaction,
                             const std::string& msg) -> void {
  // Include a stack trace only if --gmock_verbose=info is specified.
  const int stack_frames_to_skip =
      GMOCK_FLAG(verbose) == kInfoVerbosity ? 3 : -1;
  switch (reaction) {
    case kAllow:
      Log(kInfo, msg, stack_frames_to_skip);
      break;
    case kWarn:
      Log(kWarning,
          msg +
          "\nNOTE: You can safely ignore the above warning unless this "
          "call should not happen.  Do not suppress it by blindly adding "
          "an EXPECT_CALL() if you don't mean to enforce the call.  "
          "See "
          "https://github.com/google/googletest/blob/master/docs/"
          "gmock_cook_book.md#"
          "knowing-when-to-expect for details.\n",
          stack_frames_to_skip);
      break;
    default: // FAIL
      Expect(false, nullptr, -1, msg);
  }
}

UntypedFunctionMockerBase::UntypedFunctionMockerBase()
  : mock_obj_(nullptr),
    name_("") {}

UntypedFunctionMockerBase::~UntypedFunctionMockerBase() {}

// Sets the mock object this mock method belongs to, and registers
// this information in the global mock registry.  Will be called
// whenever an EXPECT_CALL() or ON_CALL() is executed on this mock
// method.
auto UntypedFunctionMockerBase::RegisterOwner(const void* mock_obj) -> void
GTEST_LOCK_EXCLUDED_(g_gmock_mutex) {
  {
    MutexLock l(&g_gmock_mutex);
    mock_obj_ = mock_obj;
  }
  Mock::Register(mock_obj, this);
}

// Sets the mock object this mock method belongs to, and sets the name
// of the mock function.  Will be called upon each invocation of this
// mock function.
auto UntypedFunctionMockerBase::SetOwnerAndName(const void* mock_obj,
                                                const char* name) -> void
GTEST_LOCK_EXCLUDED_(g_gmock_mutex) {
  // We protect name_ under g_gmock_mutex in case this mock function
  // is called from two threads concurrently.
  MutexLock l(&g_gmock_mutex);
  mock_obj_ = mock_obj;
  name_ = name;
}

// Returns the name of the function being mocked.  Must be called
// after RegisterOwner() or SetOwnerAndName() has been called.
auto UntypedFunctionMockerBase::MockObject() const -> const void*
GTEST_LOCK_EXCLUDED_(g_gmock_mutex) {
  const void* mock_obj;
  {
    // We protect mock_obj_ under g_gmock_mutex in case this mock
    // function is called from two threads concurrently.
    MutexLock l(&g_gmock_mutex);
    Assert(mock_obj_ != nullptr, __FILE__, __LINE__,
           "MockObject() must not be called before RegisterOwner() or "
           "SetOwnerAndName() has been called.");
    mock_obj = mock_obj_;
  }
  return mock_obj;
}

// Returns the name of this mock method.  Must be called after
// SetOwnerAndName() has been called.
auto UntypedFunctionMockerBase::Name() const -> const char*
GTEST_LOCK_EXCLUDED_(g_gmock_mutex) {
  const char* name;
  {
    // We protect name_ under g_gmock_mutex in case this mock
    // function is called from two threads concurrently.
    MutexLock l(&g_gmock_mutex);
    Assert(name_ != nullptr, __FILE__, __LINE__,
           "Name() must not be called before SetOwnerAndName() has "
           "been called.");
    name = name_;
  }
  return name;
}

// Calculates the result of invoking this mock function with the given
// arguments, prints it, and returns it.  The caller is responsible
// for deleting the result.
auto UntypedFunctionMockerBase::UntypedInvokeWith(
    void* const untyped_args) -> UntypedActionResultHolderBase*
GTEST_LOCK_EXCLUDED_(g_gmock_mutex) {
  // See the definition of untyped_expectations_ for why access to it
  // is unprotected here.
  if (untyped_expectations_.size() == 0) {
    // No expectation is set on this mock method - we have an
    // uninteresting call.

    // We must get Google Mock's reaction on uninteresting calls
    // made on this mock object BEFORE performing the action,
    // because the action may DELETE the mock object and make the
    // following expression meaningless.
    const CallReaction reaction =
        Mock::GetReactionOnUninterestingCalls(MockObject());

    // True if and only if we need to print this call's arguments and return
    // value.  This definition must be kept in sync with
    // the behavior of ReportUninterestingCall().
    const bool need_to_report_uninteresting_call =
        // If the user allows this uninteresting call, we print it
        // only when they want informational messages.
        reaction == kAllow
          ? LogIsVisible(kInfo)
          :
          // If the user wants this to be a warning, we print
          // it only when they want to see warnings.
          reaction == kWarn
          ? LogIsVisible(kWarning)
          :
          // Otherwise, the user wants this to be an error, and we
          // should always print detailed information in the error.
          true;

    if (!need_to_report_uninteresting_call) {
      // Perform the action without printing the call information.
      return this->UntypedPerformDefaultAction(
          untyped_args, "Function call: " + std::string(Name()));
    }

    // Warns about the uninteresting call.
    std::stringstream ss;
    this->UntypedDescribeUninterestingCall(untyped_args, &ss);

    // Calculates the function result.
    UntypedActionResultHolderBase* const result =
        this->UntypedPerformDefaultAction(untyped_args, ss.str());

    // Prints the function result.
    if (result != nullptr) {
      result->PrintAsActionResult(&ss);
    }

    ReportUninterestingCall(reaction, ss.str());
    return result;
  }

  bool is_excessive = false;
  std::stringstream ss;
  std::stringstream why;
  std::stringstream loc;
  const void* untyped_action = nullptr;

  // The UntypedFindMatchingExpectation() function acquires and
  // releases g_gmock_mutex.

  const ExpectationBase* const untyped_expectation =
      this->UntypedFindMatchingExpectation(untyped_args, &untyped_action,
                                           &is_excessive, &ss, &why);
  const bool found = untyped_expectation != nullptr;

  // True if and only if we need to print the call's arguments
  // and return value.
  // This definition must be kept in sync with the uses of Expect()
  // and Log() in this function.
  const bool need_to_report_call =
      !found || is_excessive || LogIsVisible(kInfo);
  if (!need_to_report_call) {
    // Perform the action without printing the call information.
    return untyped_action == nullptr
             ? this->UntypedPerformDefaultAction(untyped_args, "")
             : this->UntypedPerformAction(untyped_action, untyped_args);
  }

  ss << "    Function call: " << Name();
  this->UntypedPrintArgs(untyped_args, &ss);

  // In case the action deletes a piece of the expectation, we
  // generate the message beforehand.
  if (found && !is_excessive) {
    untyped_expectation->DescribeLocationTo(&loc);
  }

  UntypedActionResultHolderBase* result = nullptr;

  auto perform_action = [&]
  {
    return untyped_action == nullptr
             ? this->UntypedPerformDefaultAction(untyped_args, ss.str())
             : this->UntypedPerformAction(untyped_action, untyped_args);
  };
  auto handle_failures = [&]
  {
    ss << "\n" << why.str();

    if (!found) {
      // No expectation matches this call - reports a failure.
      Expect(false, nullptr, -1, ss.str());
    } else if (is_excessive) {
      // We had an upper-bound violation and the failure message is in ss.
      Expect(false, untyped_expectation->file(), untyped_expectation->line(),
             ss.str());
    } else {
      // We had an expected call and the matching expectation is
      // described in ss.
      Log(kInfo, loc.str() + ss.str(), 2);
    }
  };
#if GTEST_HAS_EXCEPTIONS
  try {
    result = perform_action();
  } catch (...) {
    handle_failures();
    throw;
  }
#else
  result = perform_action();
#endif

  if (result != nullptr) {
    result->PrintAsActionResult(&ss);
  }
  handle_failures();
  return result;
}

// Returns an Expectation object that references and co-owns exp,
// which must be an expectation on this mock function.
auto UntypedFunctionMockerBase::GetHandleOf(
    ExpectationBase* exp) -> Expectation {
  // See the definition of untyped_expectations_ for why access to it
  // is unprotected here.
  for (UntypedExpectations::const_iterator it =
           untyped_expectations_.begin();
       it != untyped_expectations_.end(); ++it) {
    if (it->get() == exp) {
      return Expectation(*it);
    }
  }

  Assert(false, __FILE__, __LINE__, "Cannot find expectation.");
  return Expectation();
  // The above statement is just to make the code compile, and will
  // never be executed.
}

// Verifies that all expectations on this mock function have been
// satisfied.  Reports one or more Google Test non-fatal failures
// and returns false if not.
auto UntypedFunctionMockerBase::VerifyAndClearExpectationsLocked() -> bool
GTEST_EXCLUSIVE_LOCK_REQUIRED_(g_gmock_mutex) {
  g_gmock_mutex.AssertHeld();
  bool expectations_met = true;
  for (UntypedExpectations::const_iterator it =
           untyped_expectations_.begin();
       it != untyped_expectations_.end(); ++it) {
    ExpectationBase* const untyped_expectation = it->get();
    if (untyped_expectation->IsOverSaturated()) {
      // There was an upper-bound violation.  Since the error was
      // already reported when it occurred, there is no need to do
      // anything here.
      expectations_met = false;
    } else if (!untyped_expectation->IsSatisfied()) {
      expectations_met = false;
      std::stringstream ss;
      ss << "Actual function call count doesn't match "
          << untyped_expectation->source_text() << "...\n";
      // No need to show the source file location of the expectation
      // in the description, as the Expect() call that follows already
      // takes care of it.
      untyped_expectation->MaybeDescribeExtraMatcherTo(&ss);
      untyped_expectation->DescribeCallCountTo(&ss);
      Expect(false, untyped_expectation->file(),
             untyped_expectation->line(), ss.str());
    }
  }

  // Deleting our expectations may trigger other mock objects to be deleted, for
  // example if an action contains a reference counted smart pointer to that
  // mock object, and that is the last reference. So if we delete our
  // expectations within the context of the global mutex we may deadlock when
  // this method is called again. Instead, make a copy of the set of
  // expectations to delete, clear our set within the mutex, and then clear the
  // copied set outside of it.
  UntypedExpectations expectations_to_delete;
  untyped_expectations_.swap(expectations_to_delete);

  g_gmock_mutex.Unlock();
  expectations_to_delete.clear();
  g_gmock_mutex.Lock();

  return expectations_met;
}

auto intToCallReaction(int mock_behavior) -> CallReaction {
  if (mock_behavior >= kAllow && mock_behavior <= kFail) {
    return static_cast<CallReaction>(mock_behavior);
  }
  return kWarn;
}

} // namespace internal

// Class Mock.

namespace {

using FunctionMockers = std::set<internal::UntypedFunctionMockerBase*>;

// The current state of a mock object.  Such information is needed for
// detecting leaked mock objects and explicitly verifying a mock's
// expectations.
struct MockObjectState {
  MockObjectState()
    : first_used_file(nullptr),
      first_used_line(-1),
      leakable(false) {}

  // Where in the source file an ON_CALL or EXPECT_CALL is first
  // invoked on this mock object.
  const char* first_used_file;
  int first_used_line;
  std::string first_used_test_suite;
  std::string first_used_test;
  bool leakable; // true if and only if it's OK to leak the object.
  FunctionMockers function_mockers; // All registered methods of the object.
};

// A global registry holding the state of all mock objects that are
// alive.  A mock object is added to this registry the first time
// Mock::AllowLeak(), ON_CALL(), or EXPECT_CALL() is called on it.  It
// is removed from the registry in the mock object's destructor.
class MockObjectRegistry {
public:
  // Maps a mock object (identified by its address) to its state.
  using StateMap = std::map<const void*, MockObjectState>;

  // This destructor will be called when a program exits, after all
  // tests in it have been run.  By then, there should be no mock
  // object alive.  Therefore we report any living object as test
  // failure, unless the user explicitly asked us to ignore it.
  ~MockObjectRegistry() {
    if (!GMOCK_FLAG(catch_leaked_mocks)) {
      return;
    }

    int leaked_count = 0;
    for (StateMap::const_iterator it = states_.begin(); it != states_.end();
         ++it) {
      if (it->second.leakable) // The user said it's fine to leak this object.
      {
        continue;
      }

      // FIXME: Print the type of the leaked object.
      // This can help the user identify the leaked object.
      std::cout << "\n";
      const MockObjectState& state = it->second;
      std::cout << internal::FormatFileLocation(state.first_used_file,
                                                state.first_used_line);
      std::cout << " ERROR: this mock object";
      if (state.first_used_test != "") {
        std::cout << " (used in test " << state.first_used_test_suite << "."
            << state.first_used_test << ")";
      }
      std::cout << " should be deleted but never is. Its address is @"
          << it->first << ".";
      leaked_count++;
    }
    if (leaked_count > 0) {
      std::cout << "\nERROR: " << leaked_count << " leaked mock "
          << (leaked_count == 1 ? "object" : "objects")
          << " found at program exit. Expectations on a mock object are "
          "verified when the object is destructed. Leaking a mock "
          "means that its expectations aren't verified, which is "
          "usually a test bug. If you really intend to leak a mock, "
          "you can suppress this error using "
          "testing::Mock::AllowLeak(mock_object), or you may use a "
          "fake or stub instead of a mock.\n";
      std::cout.flush();
      std::cerr.flush();
      // RUN_ALL_TESTS() has already returned when this destructor is
      // called.  Therefore we cannot use the normal Google Test
      // failure reporting mechanism.
      _exit(1); // We cannot call exit() as it is not reentrant and
      // may already have been called.
    }
  }

  auto states() -> StateMap& { return states_; }

private:
  StateMap states_;
};

// Protected by g_gmock_mutex.
MockObjectRegistry g_mock_object_registry;

// Maps a mock object to the reaction Google Mock should have when an
// uninteresting method is called.  Protected by g_gmock_mutex.
std::map<const void*, internal::CallReaction> g_uninteresting_call_reaction;

// Sets the reaction Google Mock should have when an uninteresting
// method of the given mock object is called.
auto SetReactionOnUninterestingCalls(const void* mock_obj,
                                     internal::CallReaction reaction) -> void
GTEST_LOCK_EXCLUDED_(internal::g_gmock_mutex) {
  internal::MutexLock l(&internal::g_gmock_mutex);
  g_uninteresting_call_reaction[mock_obj] = reaction;
}

} // namespace

// Tells Google Mock to allow uninteresting calls on the given mock
// object.
auto Mock::AllowUninterestingCalls(const void* mock_obj) -> void
GTEST_LOCK_EXCLUDED_(internal::g_gmock_mutex) {
  SetReactionOnUninterestingCalls(mock_obj, internal::kAllow);
}

// Tells Google Mock to warn the user about uninteresting calls on the
// given mock object.
auto Mock::WarnUninterestingCalls(const void* mock_obj) -> void
GTEST_LOCK_EXCLUDED_(internal::g_gmock_mutex) {
  SetReactionOnUninterestingCalls(mock_obj, internal::kWarn);
}

// Tells Google Mock to fail uninteresting calls on the given mock
// object.
auto Mock::FailUninterestingCalls(const void* mock_obj) -> void
GTEST_LOCK_EXCLUDED_(internal::g_gmock_mutex) {
  SetReactionOnUninterestingCalls(mock_obj, internal::kFail);
}

// Tells Google Mock the given mock object is being destroyed and its
// entry in the call-reaction table should be removed.
auto Mock::UnregisterCallReaction(const void* mock_obj) -> void
GTEST_LOCK_EXCLUDED_(internal::g_gmock_mutex) {
  internal::MutexLock l(&internal::g_gmock_mutex);
  g_uninteresting_call_reaction.erase(mock_obj);
}

// Returns the reaction Google Mock will have on uninteresting calls
// made on the given mock object.
auto Mock::GetReactionOnUninterestingCalls(
    const void* mock_obj) -> internal::CallReaction
GTEST_LOCK_EXCLUDED_(internal::g_gmock_mutex) {
  internal::MutexLock l(&internal::g_gmock_mutex);
  return g_uninteresting_call_reaction.count(mock_obj) == 0
           ? internal::intToCallReaction(GMOCK_FLAG(default_mock_behavior))
           : g_uninteresting_call_reaction[mock_obj];
}

// Tells Google Mock to ignore mock_obj when checking for leaked mock
// objects.
auto Mock::AllowLeak(const void* mock_obj) -> void
GTEST_LOCK_EXCLUDED_(internal::g_gmock_mutex) {
  internal::MutexLock l(&internal::g_gmock_mutex);
  g_mock_object_registry.states()[mock_obj].leakable = true;
}

// Verifies and clears all expectations on the given mock object.  If
// the expectations aren't satisfied, generates one or more Google
// Test non-fatal failures and returns false.
auto Mock::VerifyAndClearExpectations(void* mock_obj) -> bool
GTEST_LOCK_EXCLUDED_(internal::g_gmock_mutex) {
  internal::MutexLock l(&internal::g_gmock_mutex);
  return VerifyAndClearExpectationsLocked(mock_obj);
}

// Verifies all expectations on the given mock object and clears its
// default actions and expectations.  Returns true if and only if the
// verification was successful.
auto Mock::VerifyAndClear(void* mock_obj) -> bool
GTEST_LOCK_EXCLUDED_(internal::g_gmock_mutex) {
  internal::MutexLock l(&internal::g_gmock_mutex);
  ClearDefaultActionsLocked(mock_obj);
  return VerifyAndClearExpectationsLocked(mock_obj);
}

// Verifies and clears all expectations on the given mock object.  If
// the expectations aren't satisfied, generates one or more Google
// Test non-fatal failures and returns false.
auto Mock::VerifyAndClearExpectationsLocked(void* mock_obj) -> bool
GTEST_EXCLUSIVE_LOCK_REQUIRED_(internal::g_gmock_mutex) {
  internal::g_gmock_mutex.AssertHeld();
  if (g_mock_object_registry.states().count(mock_obj) == 0) {
    // No EXPECT_CALL() was set on the given mock object.
    return true;
  }

  // Verifies and clears the expectations on each mock method in the
  // given mock object.
  bool expectations_met = true;
  FunctionMockers& mockers =
      g_mock_object_registry.states()[mock_obj].function_mockers;
  for (auto it = mockers.begin();
       it != mockers.end(); ++it) {
    if (!(*it)->VerifyAndClearExpectationsLocked()) {
      expectations_met = false;
    }
  }

  // We don't clear the content of mockers, as they may still be
  // needed by ClearDefaultActionsLocked().
  return expectations_met;
}

auto Mock::IsNaggy(void* mock_obj) -> bool
GTEST_LOCK_EXCLUDED_(internal::g_gmock_mutex) {
  return GetReactionOnUninterestingCalls(mock_obj) == internal::kWarn;
}

auto Mock::IsNice(void* mock_obj) -> bool
GTEST_LOCK_EXCLUDED_(internal::g_gmock_mutex) {
  return GetReactionOnUninterestingCalls(mock_obj) == internal::kAllow;
}

auto Mock::IsStrict(void* mock_obj) -> bool
GTEST_LOCK_EXCLUDED_(internal::g_gmock_mutex) {
  return GetReactionOnUninterestingCalls(mock_obj) == internal::kFail;
}

// Registers a mock object and a mock method it owns.
auto Mock::Register(const void* mock_obj,
                    internal::UntypedFunctionMockerBase* mocker) -> void
GTEST_LOCK_EXCLUDED_(internal::g_gmock_mutex) {
  internal::MutexLock l(&internal::g_gmock_mutex);
  g_mock_object_registry.states()[mock_obj].function_mockers.insert(mocker);
}

// Tells Google Mock where in the source code mock_obj is used in an
// ON_CALL or EXPECT_CALL.  In case mock_obj is leaked, this
// information helps the user identify which object it is.
auto Mock::RegisterUseByOnCallOrExpectCall(const void* mock_obj,
                                           const char* file, int line) -> void
GTEST_LOCK_EXCLUDED_(internal::g_gmock_mutex) {
  internal::MutexLock l(&internal::g_gmock_mutex);
  MockObjectState& state = g_mock_object_registry.states()[mock_obj];
  if (state.first_used_file == nullptr) {
    state.first_used_file = file;
    state.first_used_line = line;
    const TestInfo* const test_info =
        UnitTest::GetInstance()->current_test_info();
    if (test_info != nullptr) {
      state.first_used_test_suite = test_info->test_suite_name();
      state.first_used_test = test_info->name();
    }
  }
}

// Unregisters a mock method; removes the owning mock object from the
// registry when the last mock method associated with it has been
// unregistered.  This is called only in the destructor of
// FunctionMockerBase.
auto Mock::UnregisterLocked(internal::UntypedFunctionMockerBase* mocker) -> void
GTEST_EXCLUSIVE_LOCK_REQUIRED_(internal::g_gmock_mutex) {
  internal::g_gmock_mutex.AssertHeld();
  for (auto it =
           g_mock_object_registry.states().begin();
       it != g_mock_object_registry.states().end(); ++it) {
    FunctionMockers& mockers = it->second.function_mockers;
    if (mockers.erase(mocker) > 0) {
      // mocker was in mockers and has been just removed.
      if (mockers.empty()) {
        g_mock_object_registry.states().erase(it);
      }
      return;
    }
  }
}

// Clears all ON_CALL()s set on the given mock object.
auto Mock::ClearDefaultActionsLocked(void* mock_obj) -> void
GTEST_EXCLUSIVE_LOCK_REQUIRED_(internal::g_gmock_mutex) {
  internal::g_gmock_mutex.AssertHeld();

  if (g_mock_object_registry.states().count(mock_obj) == 0) {
    // No ON_CALL() was set on the given mock object.
    return;
  }

  // Clears the default actions for each mock method in the given mock
  // object.
  FunctionMockers& mockers =
      g_mock_object_registry.states()[mock_obj].function_mockers;
  for (auto it = mockers.begin();
       it != mockers.end(); ++it) {
    (*it)->ClearDefaultActionsLocked();
  }

  // We don't clear the content of mockers, as they may still be
  // needed by VerifyAndClearExpectationsLocked().
}

Expectation::Expectation() {}

Expectation::Expectation(
    const std::shared_ptr<internal::ExpectationBase>& an_expectation_base)
  : expectation_base_(an_expectation_base) {}

Expectation::~Expectation() {}

// Adds an expectation to a sequence.
auto Sequence::AddExpectation(const Expectation& expectation) const -> void {
  if (*last_expectation_ != expectation) {
    if (last_expectation_->expectation_base() != nullptr) {
      expectation.expectation_base()->immediate_prerequisites_
          += *last_expectation_;
    }
    *last_expectation_ = expectation;
  }
}

// Creates the implicit sequence if there isn't one.
InSequence::InSequence() {
  if (internal::g_gmock_implicit_sequence.get() == nullptr) {
    internal::g_gmock_implicit_sequence.set(new Sequence);
    sequence_created_ = true;
  } else {
    sequence_created_ = false;
  }
}

// Deletes the implicit sequence if it was created by the constructor
// of this object.
InSequence::~InSequence() {
  if (sequence_created_) {
    delete internal::g_gmock_implicit_sequence.get();
    internal::g_gmock_implicit_sequence.set(nullptr);
  }
}

} // namespace testing

#ifdef _MSC_VER
#if _MSC_VER == 1900
#  pragma warning(pop)
#endif
#endif
