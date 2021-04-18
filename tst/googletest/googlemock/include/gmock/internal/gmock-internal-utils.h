// File: gmock-internal-utils.h
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

#ifndef GOOGLEMOCK_INCLUDE_GMOCK_INTERNAL_GMOCK_INTERNAL_UTILS_H_
#define GOOGLEMOCK_INCLUDE_GMOCK_INTERNAL_GMOCK_INTERNAL_UTILS_H_

#include <stdio.h>
#include <ostream>  // NOLINT
#include <string>
#include <type_traits>
#include "gmock/internal/gmock-port.h"
#include "gtest/gtest.h"

namespace testing {

template <typename>
class Matcher;

namespace internal {

// Silence MSVC C4100 (unreferenced formal parameter) and
// C4805('==': unsafe mix of type 'const int' and type 'const bool')
#ifdef _MSC_VER
# pragma warning(push)
# pragma warning(disable:4100)
# pragma warning(disable:4805)
#endif

// Joins a vector of strings as if they are fields of a tuple; returns
// the joined string.
GTEST_API_ auto JoinAsTuple(const Strings& fields) -> std::string;

// Converts an identifier name to a space-separated list of lower-case
// words.  Each maximum substring of the form [A-Za-z][a-z]*|\d+ is
// treated as one word.  For example, both "FooBar123" and
// "foo_bar_123" are converted to "foo bar 123".
GTEST_API_ auto
ConvertIdentifierNameToWords(const char* id_name) -> std::string;

// GetRawPointer(p) returns the raw pointer underlying p when p is a
// smart pointer, or returns p itself when p is already a raw pointer.
// The following default implementation is for the smart pointer case.
template <typename Pointer>
inline auto GetRawPointer(
    const Pointer& p) -> const typename Pointer::element_type* {
  return p.get();
}

// This overloaded version is for the raw pointer case.
template <typename Element>
inline auto GetRawPointer(Element* p) -> Element* { return p; }

// MSVC treats wchar_t as a native type usually, but treats it as the
// same as unsigned short when the compiler option /Zc:wchar_t- is
// specified.  It defines _NATIVE_WCHAR_T_DEFINED symbol when wchar_t
// is a native type.
#if defined(_MSC_VER) && !defined(_NATIVE_WCHAR_T_DEFINED)
// wchar_t is a typedef.
#else
# define GMOCK_WCHAR_T_IS_NATIVE_ 1
#endif

// In what follows, we use the term "kind" to indicate whether a type
// is bool, an integer type (excluding bool), a floating-point type,
// or none of them.  This categorization is useful for determining
// when a matcher argument type can be safely converted to another
// type in the implementation of SafeMatcherCast.
enum TypeKind {
  kBool,
  kInteger,
  kFloatingPoint,
  kOther
};

// KindOf<T>::value is the kind of type T.
template <typename T>
struct KindOf {
  enum { value = kOther }; // The default kind.
};

// This macro declares that the kind of 'type' is 'kind'.
#define GMOCK_DECLARE_KIND_(type, kind) \
  template <> struct KindOf<type> { enum { value = kind }; }

GMOCK_DECLARE_KIND_(bool, kBool);

// All standard integer types.
GMOCK_DECLARE_KIND_(char, kInteger);

GMOCK_DECLARE_KIND_(signed char, kInteger);

GMOCK_DECLARE_KIND_(unsigned char, kInteger);

GMOCK_DECLARE_KIND_(short, kInteger);          // NOLINT
GMOCK_DECLARE_KIND_(unsigned short, kInteger); // NOLINT
GMOCK_DECLARE_KIND_(int, kInteger);

GMOCK_DECLARE_KIND_(unsigned int, kInteger);

GMOCK_DECLARE_KIND_(long, kInteger);               // NOLINT
GMOCK_DECLARE_KIND_(unsigned long, kInteger);      // NOLINT
GMOCK_DECLARE_KIND_(long long, kInteger);          // NOLINT
GMOCK_DECLARE_KIND_(unsigned long long, kInteger); // NOLINT

#if GMOCK_WCHAR_T_IS_NATIVE_
GMOCK_DECLARE_KIND_(wchar_t, kInteger);
#endif

// All standard floating-point types.
GMOCK_DECLARE_KIND_(float, kFloatingPoint);

GMOCK_DECLARE_KIND_(double, kFloatingPoint);

GMOCK_DECLARE_KIND_(long double, kFloatingPoint);

#undef GMOCK_DECLARE_KIND_

// Evaluates to the kind of 'type'.
#define GMOCK_KIND_OF_(type) \
  static_cast< ::testing::internal::TypeKind>( \
      ::testing::internal::KindOf<type>::value)

// LosslessArithmeticConvertibleImpl<kFromKind, From, kToKind, To>::value
// is true if and only if arithmetic type From can be losslessly converted to
// arithmetic type To.
//
// It's the user's responsibility to ensure that both From and To are
// raw (i.e. has no CV modifier, is not a pointer, and is not a
// reference) built-in arithmetic types, kFromKind is the kind of
// From, and kToKind is the kind of To; the value is
// implementation-defined when the above pre-condition is violated.
template <TypeKind kFromKind, typename From, TypeKind kToKind, typename To>
using LosslessArithmeticConvertibleImpl = std::integral_constant<
  bool,
  // clang-format off
  // Converting from bool is always lossless
  kFromKind == kBool
    ? true
    // Converting between any other type kinds will be lossy if the type
    // kinds are not the same.
    : kFromKind != kToKind
    ? false
    : kFromKind == kInteger &&
      // Converting between integers of different widths is allowed so long
      // as the conversion does not go from signed to unsigned.
      (sizeof(From) < sizeof(To) &&
       !(std::is_signed<From>::value && !std::is_signed<To>::value) ||
       // Converting between integers of the same width only requires the
       // two types to have the same signedness.
       sizeof(From) == sizeof(To) &&
       std::is_signed<From>::value == std::is_signed<To>::value)
    ? true
    // Floating point conversions are lossless if and only if `To` is at least
    // as wide as `From`.
    : kFromKind == kFloatingPoint && sizeof(From) <= sizeof(To)
    ? true
    : false
  // clang-format on
>;

// LosslessArithmeticConvertible<From, To>::value is true if and only if
// arithmetic type From can be losslessly converted to arithmetic type To.
//
// It's the user's responsibility to ensure that both From and To are
// raw (i.e. has no CV modifier, is not a pointer, and is not a
// reference) built-in arithmetic types; the value is
// implementation-defined when the above pre-condition is violated.
template <typename From, typename To>
using LosslessArithmeticConvertible =
LosslessArithmeticConvertibleImpl<GMOCK_KIND_OF_(From), From,
                                  GMOCK_KIND_OF_(To), To>;

// This interface knows how to report a Google Mock failure (either
// non-fatal or fatal).
class FailureReporterInterface {
public:
  // The type of a failure (either non-fatal or fatal).
  enum FailureType {
    kNonfatal,
    kFatal
  };

  virtual ~FailureReporterInterface() {}

  // Reports a failure that occurred at the given source file location.
  virtual auto ReportFailure(FailureType type, const char* file, int line,
                             const std::string& message) -> void = 0;
};

// Returns the failure reporter used by Google Mock.
GTEST_API_ auto GetFailureReporter() -> FailureReporterInterface*;

// Asserts that condition is true; aborts the process with the given
// message if condition is false.  We cannot use LOG(FATAL) or CHECK()
// as Google Mock might be used to mock the log sink itself.  We
// inline this function to prevent it from showing up in the stack
// trace.
inline auto Assert(bool condition, const char* file, int line,
                   const std::string& msg) -> void {
  if (!condition) {
    GetFailureReporter()->ReportFailure(FailureReporterInterface::kFatal,
                                        file, line, msg);
  }
}

inline auto Assert(bool condition, const char* file, int line) -> void {
  Assert(condition, file, line, "Assertion failed.");
}

// Verifies that condition is true; generates a non-fatal failure if
// condition is false.
inline auto Expect(bool condition, const char* file, int line,
                   const std::string& msg) -> void {
  if (!condition) {
    GetFailureReporter()->ReportFailure(FailureReporterInterface::kNonfatal,
                                        file, line, msg);
  }
}

inline auto Expect(bool condition, const char* file, int line) -> void {
  Expect(condition, file, line, "Expectation failed.");
}

// Severity level of a log.
enum LogSeverity {
  kInfo = 0,
  kWarning = 1
};

// Valid values for the --gmock_verbose flag.

// All logs (informational and warnings) are printed.
const char kInfoVerbosity[] = "info";
// Only warnings are printed.
const char kWarningVerbosity[] = "warning";
// No logs are printed.
const char kErrorVerbosity[] = "error";

// Returns true if and only if a log with the given severity is visible
// according to the --gmock_verbose flag.
GTEST_API_ auto LogIsVisible(LogSeverity severity) -> bool;

// Prints the given message to stdout if and only if 'severity' >= the level
// specified by the --gmock_verbose flag.  If stack_frames_to_skip >=
// 0, also prints the stack trace excluding the top
// stack_frames_to_skip frames.  In opt mode, any positive
// stack_frames_to_skip is treated as 0, since we don't know which
// function calls will be inlined by the compiler and need to be
// conservative.
GTEST_API_ auto Log(LogSeverity severity, const std::string& message,
                    int stack_frames_to_skip) -> void;

// A marker class that is used to resolve parameterless expectations to the
// correct overload. This must not be instantiable, to prevent client code from
// accidentally resolving to the overload; for example:
//
//    ON_CALL(mock, Method({}, nullptr))...
//
class WithoutMatchers {
private:
  WithoutMatchers() {}
  friend auto GetWithoutMatchers() -> WithoutMatchers;
};

// Internal use only: access the singleton instance of WithoutMatchers.
GTEST_API_ auto GetWithoutMatchers() -> WithoutMatchers;

// Disable MSVC warnings for infinite recursion, since in this case the
// the recursion is unreachable.
#ifdef _MSC_VER
# pragma warning(push)
# pragma warning(disable:4717)
#endif

// Invalid<T>() is usable as an expression of type T, but will terminate
// the program with an assertion failure if actually run.  This is useful
// when a value of type T is needed for compilation, but the statement
// will not really be executed (or we don't care if the statement
// crashes).
template <typename T>
inline auto Invalid() -> T {
  Assert(false, "", -1, "Internal error: attempt to return invalid value");
  // This statement is unreachable, and would never terminate even if it
  // could be reached. It is provided only to placate compiler warnings
  // about missing return statements.
  return Invalid<T>();
}

#ifdef _MSC_VER
# pragma warning(pop)
#endif

// Given a raw type (i.e. having no top-level reference or const
// modifier) RawContainer that's either an STL-style container or a
// native array, class StlContainerView<RawContainer> has the
// following members:
//
//   - type is a type that provides an STL-style container view to
//     (i.e. implements the STL container concept for) RawContainer;
//   - const_reference is a type that provides a reference to a const
//     RawContainer;
//   - ConstReference(raw_container) returns a const reference to an STL-style
//     container view to raw_container, which is a RawContainer.
//   - Copy(raw_container) returns an STL-style container view of a
//     copy of raw_container, which is a RawContainer.
//
// This generic version is used when RawContainer itself is already an
// STL-style container.
template <class RawContainer>
class StlContainerView {
public:
  using type = RawContainer;
  using const_reference = const type&;

  static auto ConstReference(const RawContainer& container) -> const_reference {
    static_assert(!std::is_const<RawContainer>::value,
      "RawContainer type must not be const");
    return container;
  }

  static auto Copy(const RawContainer& container) -> type { return container; }
};

// This specialization is used when RawContainer is a native array type.
template <typename Element, size_t N>
class StlContainerView<Element[N]> {
public:
  using RawElement = typename std::remove_const<Element>::type;
  using type = NativeArray<RawElement>;
  // NativeArray<T> can represent a native array either by value or by
  // reference (selected by a constructor argument), so 'const type'
  // can be used to reference a const native array.  We cannot
  // 'typedef const type& const_reference' here, as that would mean
  // ConstReference() has to return a reference to a local variable.
  using const_reference = const type;

  static auto ConstReference(const Element (&array)[N]) -> const_reference {
    static_assert(std::is_same<Element, RawElement>::value,
      "Element type must not be const");
    return type(array, N, RelationToSourceReference());
  }

  static auto Copy(const Element (&array)[N]) -> type {
    return type(array, N, RelationToSourceCopy());
  }
};

// This specialization is used when RawContainer is a native array
// represented as a (pointer, size) tuple.
template <typename ElementPointer, typename Size>
class StlContainerView<tuple<ElementPointer, Size>> {
public:
  using RawElement = typename std::remove_const<
    typename std::pointer_traits<ElementPointer>::element_type>::type;
  using type = NativeArray<RawElement>;
  using const_reference = const type;

  static auto ConstReference(
      const tuple<ElementPointer, Size>& array) -> const_reference {
    return type(std::get<0>(array), std::get<1>(array),
                RelationToSourceReference());
  }

  static auto Copy(const tuple<ElementPointer, Size>& array) -> type {
    return type(std::get<0>(array), std::get<1>(array), RelationToSourceCopy());
  }
};

// The following specialization prevents the user from instantiating
// StlContainer with a reference type.
template <typename T>
class StlContainerView<T&>;

// A type transform to remove constness from the first part of a pair.
// Pairs like that are used as the value_type of associative containers,
// and this transform produces a similar but assignable pair.
template <typename T>
struct RemoveConstFromKey {
  using type = T;
};

// Partially specialized to remove constness from std::pair<const K, V>.
template <typename K, typename V>
struct RemoveConstFromKey<std::pair<const K, V>> {
  using type = std::pair<K, V>;
};

// Emit an assertion failure due to incorrect DoDefault() usage. Out-of-lined to
// reduce code size.
GTEST_API_ auto IllegalDoDefault(const char* file, int line) -> void;

template <typename F, typename Tuple, size_t... Idx>
auto ApplyImpl(F&& f, Tuple&& args, IndexSequence<Idx...>) -> decltype(
  std::forward<F>(f)(std::get<Idx>(std::forward<Tuple>(args))...)) {
  return std::forward<F>(f)(std::get<Idx>(std::forward<Tuple>(args))...);
}

// Apply the function to a tuple of arguments.
template <typename F, typename Tuple>
auto Apply(F&& f, Tuple&& args) -> decltype(
  ApplyImpl(std::forward<F>(f), std::forward<Tuple>(args),
            MakeIndexSequence<std::tuple_size<
              typename std::remove_reference<Tuple>::type>::value>())) {
  return ApplyImpl(std::forward<F>(f), std::forward<Tuple>(args),
                   MakeIndexSequence<std::tuple_size<
                     typename std::remove_reference<Tuple>::type>::value>());
}

// Template struct Function<F>, where F must be a function type, contains
// the following typedefs:
//
//   Result:               the function's return type.
//   Arg<N>:               the type of the N-th argument, where N starts with 0.
//   ArgumentTuple:        the tuple type consisting of all parameters of F.
//   ArgumentMatcherTuple: the tuple type consisting of Matchers for all
//                         parameters of F.
//   MakeResultVoid:       the function type obtained by substituting void
//                         for the return type of F.
//   MakeResultIgnoredValue:
//                         the function type obtained by substituting Something
//                         for the return type of F.
template <typename T>
struct Function;

template <typename R, typename... Args>
struct Function<R(Args ...)> {
  using Result = R;
  static constexpr size_t ArgumentCount = sizeof...(Args);
  template <size_t I>
  using Arg = ElemFromList<I, Args...>;
  using ArgumentTuple = std::tuple<Args...>;
  using ArgumentMatcherTuple = std::tuple<Matcher<Args>...>;
  using MakeResultVoid = void(Args ...);
  using MakeResultIgnoredValue = IgnoredValue(Args ...);
};

template <typename R, typename... Args>
constexpr size_t Function<R(Args ...)>::ArgumentCount;

#ifdef _MSC_VER
# pragma warning(pop)
#endif

} // namespace internal
} // namespace testing

#endif  // GOOGLEMOCK_INCLUDE_GMOCK_INTERNAL_GMOCK_INTERNAL_UTILS_H_
