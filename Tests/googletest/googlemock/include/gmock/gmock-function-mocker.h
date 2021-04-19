// File: gmock-function-mocker.h
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

#ifndef GOOGLEMOCK_INCLUDE_GMOCK_INTERNAL_GMOCK_FUNCTION_MOCKER_H_  // NOLINT
#define GOOGLEMOCK_INCLUDE_GMOCK_INTERNAL_GMOCK_FUNCTION_MOCKER_H_  // NOLINT

#include <type_traits>  // IWYU pragma: keep
#include <utility>      // IWYU pragma: keep

#include "gmock/gmock-spec-builders.h"
#include "gmock/internal/gmock-internal-utils.h"
#include "gmock/internal/gmock-pp.h"

namespace testing {
namespace internal {
template <typename T>
using identity_t = T;

template <typename Pattern>
struct ThisRefAdjuster {
  template <typename T>
  using AdjustT = typename std::conditional<
    std::is_const<typename std::remove_reference<Pattern>::type>::value,
    typename std::conditional<std::is_lvalue_reference<Pattern>::value,
                              const T&, const T&&>::type,
    typename std::conditional<std::is_lvalue_reference<Pattern>::value, T&,
                              T&&>::type>::type;

  template <typename MockType>
  static auto Adjust(const MockType& mock) -> AdjustT<MockType> {
    return static_cast<AdjustT<MockType>>(const_cast<MockType&>(mock));
  }
};

} // namespace internal

// The style guide prohibits "using" statements in a namespace scope
// inside a header file.  However, the FunctionMocker class template
// is meant to be defined in the ::testing namespace.  The following
// line is just a trick for working around a bug in MSVC 8.0, which
// cannot handle it if we define FunctionMocker in ::testing.
using internal::FunctionMocker;
} // namespace testing

#define MOCK_METHOD(...) \
  GMOCK_PP_VARIADIC_CALL(GMOCK_INTERNAL_MOCK_METHOD_ARG_, __VA_ARGS__)

#define GMOCK_INTERNAL_MOCK_METHOD_ARG_1(...) \
  GMOCK_INTERNAL_WRONG_ARITY(__VA_ARGS__)

#define GMOCK_INTERNAL_MOCK_METHOD_ARG_2(...) \
  GMOCK_INTERNAL_WRONG_ARITY(__VA_ARGS__)

#define GMOCK_INTERNAL_MOCK_METHOD_ARG_3(_Ret, _MethodName, _Args) \
  GMOCK_INTERNAL_MOCK_METHOD_ARG_4(_Ret, _MethodName, _Args, ())

#define GMOCK_INTERNAL_MOCK_METHOD_ARG_4(_Ret, _MethodName, _Args, _Spec)     \
  GMOCK_INTERNAL_ASSERT_PARENTHESIS(_Args);                                   \
  GMOCK_INTERNAL_ASSERT_PARENTHESIS(_Spec);                                   \
  GMOCK_INTERNAL_ASSERT_VALID_SIGNATURE(                                      \
      GMOCK_PP_NARG0 _Args, GMOCK_INTERNAL_SIGNATURE(_Ret, _Args));           \
  GMOCK_INTERNAL_ASSERT_VALID_SPEC(_Spec)                                     \
  GMOCK_INTERNAL_MOCK_METHOD_IMPL(                                            \
      GMOCK_PP_NARG0 _Args, _MethodName, GMOCK_INTERNAL_HAS_CONST(_Spec),     \
      GMOCK_INTERNAL_HAS_OVERRIDE(_Spec), GMOCK_INTERNAL_HAS_FINAL(_Spec),    \
      GMOCK_INTERNAL_GET_NOEXCEPT_SPEC(_Spec),                                \
      GMOCK_INTERNAL_GET_CALLTYPE(_Spec), GMOCK_INTERNAL_GET_REF_SPEC(_Spec), \
      (GMOCK_INTERNAL_SIGNATURE(_Ret, _Args)))

#define GMOCK_INTERNAL_MOCK_METHOD_ARG_5(...) \
  GMOCK_INTERNAL_WRONG_ARITY(__VA_ARGS__)

#define GMOCK_INTERNAL_MOCK_METHOD_ARG_6(...) \
  GMOCK_INTERNAL_WRONG_ARITY(__VA_ARGS__)

#define GMOCK_INTERNAL_MOCK_METHOD_ARG_7(...) \
  GMOCK_INTERNAL_WRONG_ARITY(__VA_ARGS__)

#define GMOCK_INTERNAL_WRONG_ARITY(...)                                      \
  static_assert(                                                             \
      false,                                                                 \
      "MOCK_METHOD must be called with 3 or 4 arguments. _Ret, "             \
      "_MethodName, _Args and optionally _Spec. _Args and _Spec must be "    \
      "enclosed in parentheses. If _Ret is a type with unprotected commas, " \
      "it must also be enclosed in parentheses.")

#define GMOCK_INTERNAL_ASSERT_PARENTHESIS(_Tuple) \
  static_assert(                                  \
      GMOCK_PP_IS_ENCLOSED_PARENS(_Tuple),        \
      GMOCK_PP_STRINGIZE(_Tuple) " should be enclosed in parentheses.")

#define GMOCK_INTERNAL_ASSERT_VALID_SIGNATURE(_N, ...)                 \
  static_assert(                                                       \
      std::is_function<__VA_ARGS__>::value,                            \
      "Signature must be a function type, maybe return type contains " \
      "unprotected comma.");                                           \
  static_assert(                                                       \
      ::testing::tuple_size<typename ::testing::internal::Function<    \
              __VA_ARGS__>::ArgumentTuple>::value == _N,               \
      "This method does not take " GMOCK_PP_STRINGIZE(                 \
          _N) " arguments. Parenthesize all types with unprotected commas.")

#define GMOCK_INTERNAL_ASSERT_VALID_SPEC(_Spec) \
  GMOCK_PP_FOR_EACH(GMOCK_INTERNAL_ASSERT_VALID_SPEC_ELEMENT, ~, _Spec)

#define GMOCK_INTERNAL_MOCK_METHOD_IMPL(_N, _MethodName, _Constness,           \
  _Override, _Final, _NoexceptSpec,      \
  _CallType, _RefSpec, _Signature)       \
  typename ::testing::internal::Function<GMOCK_PP_REMOVE_PARENS(               \
      _Signature)>::Result                                                     \
  GMOCK_INTERNAL_EXPAND(_CallType)                                             \
      _MethodName(GMOCK_PP_REPEAT(GMOCK_INTERNAL_PARAMETER, _Signature, _N))   \
          GMOCK_PP_IF(_Constness, const, ) _RefSpec _NoexceptSpec              \
          GMOCK_PP_IF(_Override, override, ) GMOCK_PP_IF(_Final, final, ) {    \
    GMOCK_MOCKER_(_N, _Constness, _MethodName)                                 \
        .SetOwnerAndName(this, #_MethodName);                                  \
    return GMOCK_MOCKER_(_N, _Constness, _MethodName)                          \
        .Invoke(GMOCK_PP_REPEAT(GMOCK_INTERNAL_FORWARD_ARG, _Signature, _N));  \
  }                                                                            \
  ::testing::MockSpec<GMOCK_PP_REMOVE_PARENS(_Signature)> gmock_##_MethodName( \
      GMOCK_PP_REPEAT(GMOCK_INTERNAL_MATCHER_PARAMETER, _Signature, _N))       \
      GMOCK_PP_IF(_Constness, const, ) _RefSpec {                              \
    GMOCK_MOCKER_(_N, _Constness, _MethodName).RegisterOwner(this);            \
    return GMOCK_MOCKER_(_N, _Constness, _MethodName)                          \
        .With(GMOCK_PP_REPEAT(GMOCK_INTERNAL_MATCHER_ARGUMENT, , _N));         \
  }                                                                            \
  ::testing::MockSpec<GMOCK_PP_REMOVE_PARENS(_Signature)> gmock_##_MethodName( \
      const ::testing::internal::WithoutMatchers&,                             \
      GMOCK_PP_IF(_Constness, const, )::testing::internal::Function<           \
          GMOCK_PP_REMOVE_PARENS(_Signature)>*) const _RefSpec _NoexceptSpec { \
    return ::testing::internal::ThisRefAdjuster<GMOCK_PP_IF(                   \
        _Constness, const, ) int _RefSpec>::Adjust(*this)                      \
        .gmock_##_MethodName(GMOCK_PP_REPEAT(                                  \
            GMOCK_INTERNAL_A_MATCHER_ARGUMENT, _Signature, _N));               \
  }                                                                            \
  mutable ::testing::FunctionMocker<GMOCK_PP_REMOVE_PARENS(_Signature)>        \
      GMOCK_MOCKER_(_N, _Constness, _MethodName)

#define GMOCK_INTERNAL_EXPAND(...) __VA_ARGS__

// Five Valid modifiers.
#define GMOCK_INTERNAL_HAS_CONST(_Tuple) \
  GMOCK_PP_HAS_COMMA(GMOCK_PP_FOR_EACH(GMOCK_INTERNAL_DETECT_CONST, ~, _Tuple))

#define GMOCK_INTERNAL_HAS_OVERRIDE(_Tuple) \
  GMOCK_PP_HAS_COMMA(                       \
      GMOCK_PP_FOR_EACH(GMOCK_INTERNAL_DETECT_OVERRIDE, ~, _Tuple))

#define GMOCK_INTERNAL_HAS_FINAL(_Tuple) \
  GMOCK_PP_HAS_COMMA(GMOCK_PP_FOR_EACH(GMOCK_INTERNAL_DETECT_FINAL, ~, _Tuple))

#define GMOCK_INTERNAL_GET_NOEXCEPT_SPEC(_Tuple) \
  GMOCK_PP_FOR_EACH(GMOCK_INTERNAL_NOEXCEPT_SPEC_IF_NOEXCEPT, ~, _Tuple)

#define GMOCK_INTERNAL_NOEXCEPT_SPEC_IF_NOEXCEPT(_i, _, _elem)          \
  GMOCK_PP_IF(                                                          \
      GMOCK_PP_HAS_COMMA(GMOCK_INTERNAL_DETECT_NOEXCEPT(_i, _, _elem)), \
      _elem, )

#define GMOCK_INTERNAL_GET_REF_SPEC(_Tuple) \
  GMOCK_PP_FOR_EACH(GMOCK_INTERNAL_REF_SPEC_IF_REF, ~, _Tuple)

#define GMOCK_INTERNAL_REF_SPEC_IF_REF(_i, _, _elem)                       \
  GMOCK_PP_IF(GMOCK_PP_HAS_COMMA(GMOCK_INTERNAL_DETECT_REF(_i, _, _elem)), \
              GMOCK_PP_CAT(GMOCK_INTERNAL_UNPACK_, _elem), )

#define GMOCK_INTERNAL_GET_CALLTYPE(_Tuple) \
  GMOCK_PP_FOR_EACH(GMOCK_INTERNAL_GET_CALLTYPE_IMPL, ~, _Tuple)

#define GMOCK_INTERNAL_ASSERT_VALID_SPEC_ELEMENT(_i, _, _elem)            \
  static_assert(                                                          \
      (GMOCK_PP_HAS_COMMA(GMOCK_INTERNAL_DETECT_CONST(_i, _, _elem)) +    \
       GMOCK_PP_HAS_COMMA(GMOCK_INTERNAL_DETECT_OVERRIDE(_i, _, _elem)) + \
       GMOCK_PP_HAS_COMMA(GMOCK_INTERNAL_DETECT_FINAL(_i, _, _elem)) +    \
       GMOCK_PP_HAS_COMMA(GMOCK_INTERNAL_DETECT_NOEXCEPT(_i, _, _elem)) + \
       GMOCK_PP_HAS_COMMA(GMOCK_INTERNAL_DETECT_REF(_i, _, _elem)) +      \
       GMOCK_INTERNAL_IS_CALLTYPE(_elem)) == 1,                           \
      GMOCK_PP_STRINGIZE(                                                 \
          _elem) " cannot be recognized as a valid specification modifier.");

// Modifiers implementation.
#define GMOCK_INTERNAL_DETECT_CONST(_i, _, _elem) \
  GMOCK_PP_CAT(GMOCK_INTERNAL_DETECT_CONST_I_, _elem)

#define GMOCK_INTERNAL_DETECT_CONST_I_const ,

#define GMOCK_INTERNAL_DETECT_OVERRIDE(_i, _, _elem) \
  GMOCK_PP_CAT(GMOCK_INTERNAL_DETECT_OVERRIDE_I_, _elem)

#define GMOCK_INTERNAL_DETECT_OVERRIDE_I_override ,

#define GMOCK_INTERNAL_DETECT_FINAL(_i, _, _elem) \
  GMOCK_PP_CAT(GMOCK_INTERNAL_DETECT_FINAL_I_, _elem)

#define GMOCK_INTERNAL_DETECT_FINAL_I_final ,

#define GMOCK_INTERNAL_DETECT_NOEXCEPT(_i, _, _elem) \
  GMOCK_PP_CAT(GMOCK_INTERNAL_DETECT_NOEXCEPT_I_, _elem)

#define GMOCK_INTERNAL_DETECT_NOEXCEPT_I_noexcept ,

#define GMOCK_INTERNAL_DETECT_REF(_i, _, _elem) \
  GMOCK_PP_CAT(GMOCK_INTERNAL_DETECT_REF_I_, _elem)

#define GMOCK_INTERNAL_DETECT_REF_I_ref ,

#define GMOCK_INTERNAL_UNPACK_ref(x) x

#define GMOCK_INTERNAL_GET_CALLTYPE_IMPL(_i, _, _elem)           \
  GMOCK_PP_IF(GMOCK_INTERNAL_IS_CALLTYPE(_elem),                 \
              GMOCK_INTERNAL_GET_VALUE_CALLTYPE, GMOCK_PP_EMPTY) \
  (_elem)

// TODO(iserna): GMOCK_INTERNAL_IS_CALLTYPE and
// GMOCK_INTERNAL_GET_VALUE_CALLTYPE needed more expansions to work on windows
// maybe they can be simplified somehow.
#define GMOCK_INTERNAL_IS_CALLTYPE(_arg) \
  GMOCK_INTERNAL_IS_CALLTYPE_I(          \
      GMOCK_PP_CAT(GMOCK_INTERNAL_IS_CALLTYPE_HELPER_, _arg))
#define GMOCK_INTERNAL_IS_CALLTYPE_I(_arg) GMOCK_PP_IS_ENCLOSED_PARENS(_arg)

#define GMOCK_INTERNAL_GET_VALUE_CALLTYPE(_arg) \
  GMOCK_INTERNAL_GET_VALUE_CALLTYPE_I(          \
      GMOCK_PP_CAT(GMOCK_INTERNAL_IS_CALLTYPE_HELPER_, _arg))
#define GMOCK_INTERNAL_GET_VALUE_CALLTYPE_I(_arg) \
  GMOCK_PP_IDENTITY _arg

#define GMOCK_INTERNAL_IS_CALLTYPE_HELPER_Calltype

// Note: The use of `identity_t` here allows _Ret to represent return types that
// would normally need to be specified in a different way. For example, a method
// returning a function pointer must be written as
//
// fn_ptr_return_t (*method(method_args_t...))(fn_ptr_args_t...)
//
// But we only support placing the return type at the beginning. To handle this,
// we wrap all calls in identity_t, so that a declaration will be expanded to
//
// identity_t<fn_ptr_return_t (*)(fn_ptr_args_t...)> method(method_args_t...)
//
// This allows us to work around the syntactic oddities of function/method
// types.
#define GMOCK_INTERNAL_SIGNATURE(_Ret, _Args)                                 \
  ::testing::internal::identity_t<GMOCK_PP_IF(GMOCK_PP_IS_BEGIN_PARENS(_Ret), \
                                              GMOCK_PP_REMOVE_PARENS,         \
                                              GMOCK_PP_IDENTITY)(_Ret)>(      \
      GMOCK_PP_FOR_EACH(GMOCK_INTERNAL_GET_TYPE, _, _Args))

#define GMOCK_INTERNAL_GET_TYPE(_i, _, _elem)                          \
  GMOCK_PP_COMMA_IF(_i)                                                \
  GMOCK_PP_IF(GMOCK_PP_IS_BEGIN_PARENS(_elem), GMOCK_PP_REMOVE_PARENS, \
              GMOCK_PP_IDENTITY)                                       \
  (_elem)

#define GMOCK_INTERNAL_PARAMETER(_i, _Signature, _)            \
  GMOCK_PP_COMMA_IF(_i)                                        \
  GMOCK_INTERNAL_ARG_O(_i, GMOCK_PP_REMOVE_PARENS(_Signature)) \
  gmock_a##_i

#define GMOCK_INTERNAL_FORWARD_ARG(_i, _Signature, _) \
  GMOCK_PP_COMMA_IF(_i)                               \
  ::std::forward<GMOCK_INTERNAL_ARG_O(                \
      _i, GMOCK_PP_REMOVE_PARENS(_Signature))>(gmock_a##_i)

#define GMOCK_INTERNAL_MATCHER_PARAMETER(_i, _Signature, _)        \
  GMOCK_PP_COMMA_IF(_i)                                            \
  GMOCK_INTERNAL_MATCHER_O(_i, GMOCK_PP_REMOVE_PARENS(_Signature)) \
  gmock_a##_i

#define GMOCK_INTERNAL_MATCHER_ARGUMENT(_i, _1, _2) \
  GMOCK_PP_COMMA_IF(_i)                             \
  gmock_a##_i

#define GMOCK_INTERNAL_A_MATCHER_ARGUMENT(_i, _Signature, _) \
  GMOCK_PP_COMMA_IF(_i)                                      \
  ::testing::A<GMOCK_INTERNAL_ARG_O(_i, GMOCK_PP_REMOVE_PARENS(_Signature))>()

#define GMOCK_INTERNAL_ARG_O(_i, ...) \
  typename ::testing::internal::Function<__VA_ARGS__>::template Arg<_i>::type

#define GMOCK_INTERNAL_MATCHER_O(_i, ...)                          \
  const ::testing::Matcher<typename ::testing::internal::Function< \
      __VA_ARGS__>::template Arg<_i>::type>&

#define MOCK_METHOD0(m, ...) GMOCK_INTERNAL_MOCK_METHODN(, , m, 0, __VA_ARGS__)
#define MOCK_METHOD1(m, ...) GMOCK_INTERNAL_MOCK_METHODN(, , m, 1, __VA_ARGS__)
#define MOCK_METHOD2(m, ...) GMOCK_INTERNAL_MOCK_METHODN(, , m, 2, __VA_ARGS__)
#define MOCK_METHOD3(m, ...) GMOCK_INTERNAL_MOCK_METHODN(, , m, 3, __VA_ARGS__)
#define MOCK_METHOD4(m, ...) GMOCK_INTERNAL_MOCK_METHODN(, , m, 4, __VA_ARGS__)
#define MOCK_METHOD5(m, ...) GMOCK_INTERNAL_MOCK_METHODN(, , m, 5, __VA_ARGS__)
#define MOCK_METHOD6(m, ...) GMOCK_INTERNAL_MOCK_METHODN(, , m, 6, __VA_ARGS__)
#define MOCK_METHOD7(m, ...) GMOCK_INTERNAL_MOCK_METHODN(, , m, 7, __VA_ARGS__)
#define MOCK_METHOD8(m, ...) GMOCK_INTERNAL_MOCK_METHODN(, , m, 8, __VA_ARGS__)
#define MOCK_METHOD9(m, ...) GMOCK_INTERNAL_MOCK_METHODN(, , m, 9, __VA_ARGS__)
#define MOCK_METHOD10(m, ...) \
  GMOCK_INTERNAL_MOCK_METHODN(, , m, 10, __VA_ARGS__)

#define MOCK_CONST_METHOD0(m, ...) \
  GMOCK_INTERNAL_MOCK_METHODN(const, , m, 0, __VA_ARGS__)
#define MOCK_CONST_METHOD1(m, ...) \
  GMOCK_INTERNAL_MOCK_METHODN(const, , m, 1, __VA_ARGS__)
#define MOCK_CONST_METHOD2(m, ...) \
  GMOCK_INTERNAL_MOCK_METHODN(const, , m, 2, __VA_ARGS__)
#define MOCK_CONST_METHOD3(m, ...) \
  GMOCK_INTERNAL_MOCK_METHODN(const, , m, 3, __VA_ARGS__)
#define MOCK_CONST_METHOD4(m, ...) \
  GMOCK_INTERNAL_MOCK_METHODN(const, , m, 4, __VA_ARGS__)
#define MOCK_CONST_METHOD5(m, ...) \
  GMOCK_INTERNAL_MOCK_METHODN(const, , m, 5, __VA_ARGS__)
#define MOCK_CONST_METHOD6(m, ...) \
  GMOCK_INTERNAL_MOCK_METHODN(const, , m, 6, __VA_ARGS__)
#define MOCK_CONST_METHOD7(m, ...) \
  GMOCK_INTERNAL_MOCK_METHODN(const, , m, 7, __VA_ARGS__)
#define MOCK_CONST_METHOD8(m, ...) \
  GMOCK_INTERNAL_MOCK_METHODN(const, , m, 8, __VA_ARGS__)
#define MOCK_CONST_METHOD9(m, ...) \
  GMOCK_INTERNAL_MOCK_METHODN(const, , m, 9, __VA_ARGS__)
#define MOCK_CONST_METHOD10(m, ...) \
  GMOCK_INTERNAL_MOCK_METHODN(const, , m, 10, __VA_ARGS__)

#define MOCK_METHOD0_T(m, ...) MOCK_METHOD0(m, __VA_ARGS__)
#define MOCK_METHOD1_T(m, ...) MOCK_METHOD1(m, __VA_ARGS__)
#define MOCK_METHOD2_T(m, ...) MOCK_METHOD2(m, __VA_ARGS__)
#define MOCK_METHOD3_T(m, ...) MOCK_METHOD3(m, __VA_ARGS__)
#define MOCK_METHOD4_T(m, ...) MOCK_METHOD4(m, __VA_ARGS__)
#define MOCK_METHOD5_T(m, ...) MOCK_METHOD5(m, __VA_ARGS__)
#define MOCK_METHOD6_T(m, ...) MOCK_METHOD6(m, __VA_ARGS__)
#define MOCK_METHOD7_T(m, ...) MOCK_METHOD7(m, __VA_ARGS__)
#define MOCK_METHOD8_T(m, ...) MOCK_METHOD8(m, __VA_ARGS__)
#define MOCK_METHOD9_T(m, ...) MOCK_METHOD9(m, __VA_ARGS__)
#define MOCK_METHOD10_T(m, ...) MOCK_METHOD10(m, __VA_ARGS__)

#define MOCK_CONST_METHOD0_T(m, ...) MOCK_CONST_METHOD0(m, __VA_ARGS__)
#define MOCK_CONST_METHOD1_T(m, ...) MOCK_CONST_METHOD1(m, __VA_ARGS__)
#define MOCK_CONST_METHOD2_T(m, ...) MOCK_CONST_METHOD2(m, __VA_ARGS__)
#define MOCK_CONST_METHOD3_T(m, ...) MOCK_CONST_METHOD3(m, __VA_ARGS__)
#define MOCK_CONST_METHOD4_T(m, ...) MOCK_CONST_METHOD4(m, __VA_ARGS__)
#define MOCK_CONST_METHOD5_T(m, ...) MOCK_CONST_METHOD5(m, __VA_ARGS__)
#define MOCK_CONST_METHOD6_T(m, ...) MOCK_CONST_METHOD6(m, __VA_ARGS__)
#define MOCK_CONST_METHOD7_T(m, ...) MOCK_CONST_METHOD7(m, __VA_ARGS__)
#define MOCK_CONST_METHOD8_T(m, ...) MOCK_CONST_METHOD8(m, __VA_ARGS__)
#define MOCK_CONST_METHOD9_T(m, ...) MOCK_CONST_METHOD9(m, __VA_ARGS__)
#define MOCK_CONST_METHOD10_T(m, ...) MOCK_CONST_METHOD10(m, __VA_ARGS__)

#define MOCK_METHOD0_WITH_CALLTYPE(ct, m, ...) \
  GMOCK_INTERNAL_MOCK_METHODN(, ct, m, 0, __VA_ARGS__)
#define MOCK_METHOD1_WITH_CALLTYPE(ct, m, ...) \
  GMOCK_INTERNAL_MOCK_METHODN(, ct, m, 1, __VA_ARGS__)
#define MOCK_METHOD2_WITH_CALLTYPE(ct, m, ...) \
  GMOCK_INTERNAL_MOCK_METHODN(, ct, m, 2, __VA_ARGS__)
#define MOCK_METHOD3_WITH_CALLTYPE(ct, m, ...) \
  GMOCK_INTERNAL_MOCK_METHODN(, ct, m, 3, __VA_ARGS__)
#define MOCK_METHOD4_WITH_CALLTYPE(ct, m, ...) \
  GMOCK_INTERNAL_MOCK_METHODN(, ct, m, 4, __VA_ARGS__)
#define MOCK_METHOD5_WITH_CALLTYPE(ct, m, ...) \
  GMOCK_INTERNAL_MOCK_METHODN(, ct, m, 5, __VA_ARGS__)
#define MOCK_METHOD6_WITH_CALLTYPE(ct, m, ...) \
  GMOCK_INTERNAL_MOCK_METHODN(, ct, m, 6, __VA_ARGS__)
#define MOCK_METHOD7_WITH_CALLTYPE(ct, m, ...) \
  GMOCK_INTERNAL_MOCK_METHODN(, ct, m, 7, __VA_ARGS__)
#define MOCK_METHOD8_WITH_CALLTYPE(ct, m, ...) \
  GMOCK_INTERNAL_MOCK_METHODN(, ct, m, 8, __VA_ARGS__)
#define MOCK_METHOD9_WITH_CALLTYPE(ct, m, ...) \
  GMOCK_INTERNAL_MOCK_METHODN(, ct, m, 9, __VA_ARGS__)
#define MOCK_METHOD10_WITH_CALLTYPE(ct, m, ...) \
  GMOCK_INTERNAL_MOCK_METHODN(, ct, m, 10, __VA_ARGS__)

#define MOCK_CONST_METHOD0_WITH_CALLTYPE(ct, m, ...) \
  GMOCK_INTERNAL_MOCK_METHODN(const, ct, m, 0, __VA_ARGS__)
#define MOCK_CONST_METHOD1_WITH_CALLTYPE(ct, m, ...) \
  GMOCK_INTERNAL_MOCK_METHODN(const, ct, m, 1, __VA_ARGS__)
#define MOCK_CONST_METHOD2_WITH_CALLTYPE(ct, m, ...) \
  GMOCK_INTERNAL_MOCK_METHODN(const, ct, m, 2, __VA_ARGS__)
#define MOCK_CONST_METHOD3_WITH_CALLTYPE(ct, m, ...) \
  GMOCK_INTERNAL_MOCK_METHODN(const, ct, m, 3, __VA_ARGS__)
#define MOCK_CONST_METHOD4_WITH_CALLTYPE(ct, m, ...) \
  GMOCK_INTERNAL_MOCK_METHODN(const, ct, m, 4, __VA_ARGS__)
#define MOCK_CONST_METHOD5_WITH_CALLTYPE(ct, m, ...) \
  GMOCK_INTERNAL_MOCK_METHODN(const, ct, m, 5, __VA_ARGS__)
#define MOCK_CONST_METHOD6_WITH_CALLTYPE(ct, m, ...) \
  GMOCK_INTERNAL_MOCK_METHODN(const, ct, m, 6, __VA_ARGS__)
#define MOCK_CONST_METHOD7_WITH_CALLTYPE(ct, m, ...) \
  GMOCK_INTERNAL_MOCK_METHODN(const, ct, m, 7, __VA_ARGS__)
#define MOCK_CONST_METHOD8_WITH_CALLTYPE(ct, m, ...) \
  GMOCK_INTERNAL_MOCK_METHODN(const, ct, m, 8, __VA_ARGS__)
#define MOCK_CONST_METHOD9_WITH_CALLTYPE(ct, m, ...) \
  GMOCK_INTERNAL_MOCK_METHODN(const, ct, m, 9, __VA_ARGS__)
#define MOCK_CONST_METHOD10_WITH_CALLTYPE(ct, m, ...) \
  GMOCK_INTERNAL_MOCK_METHODN(const, ct, m, 10, __VA_ARGS__)

#define MOCK_METHOD0_T_WITH_CALLTYPE(ct, m, ...) \
  MOCK_METHOD0_WITH_CALLTYPE(ct, m, __VA_ARGS__)
#define MOCK_METHOD1_T_WITH_CALLTYPE(ct, m, ...) \
  MOCK_METHOD1_WITH_CALLTYPE(ct, m, __VA_ARGS__)
#define MOCK_METHOD2_T_WITH_CALLTYPE(ct, m, ...) \
  MOCK_METHOD2_WITH_CALLTYPE(ct, m, __VA_ARGS__)
#define MOCK_METHOD3_T_WITH_CALLTYPE(ct, m, ...) \
  MOCK_METHOD3_WITH_CALLTYPE(ct, m, __VA_ARGS__)
#define MOCK_METHOD4_T_WITH_CALLTYPE(ct, m, ...) \
  MOCK_METHOD4_WITH_CALLTYPE(ct, m, __VA_ARGS__)
#define MOCK_METHOD5_T_WITH_CALLTYPE(ct, m, ...) \
  MOCK_METHOD5_WITH_CALLTYPE(ct, m, __VA_ARGS__)
#define MOCK_METHOD6_T_WITH_CALLTYPE(ct, m, ...) \
  MOCK_METHOD6_WITH_CALLTYPE(ct, m, __VA_ARGS__)
#define MOCK_METHOD7_T_WITH_CALLTYPE(ct, m, ...) \
  MOCK_METHOD7_WITH_CALLTYPE(ct, m, __VA_ARGS__)
#define MOCK_METHOD8_T_WITH_CALLTYPE(ct, m, ...) \
  MOCK_METHOD8_WITH_CALLTYPE(ct, m, __VA_ARGS__)
#define MOCK_METHOD9_T_WITH_CALLTYPE(ct, m, ...) \
  MOCK_METHOD9_WITH_CALLTYPE(ct, m, __VA_ARGS__)
#define MOCK_METHOD10_T_WITH_CALLTYPE(ct, m, ...) \
  MOCK_METHOD10_WITH_CALLTYPE(ct, m, __VA_ARGS__)

#define MOCK_CONST_METHOD0_T_WITH_CALLTYPE(ct, m, ...) \
  MOCK_CONST_METHOD0_WITH_CALLTYPE(ct, m, __VA_ARGS__)
#define MOCK_CONST_METHOD1_T_WITH_CALLTYPE(ct, m, ...) \
  MOCK_CONST_METHOD1_WITH_CALLTYPE(ct, m, __VA_ARGS__)
#define MOCK_CONST_METHOD2_T_WITH_CALLTYPE(ct, m, ...) \
  MOCK_CONST_METHOD2_WITH_CALLTYPE(ct, m, __VA_ARGS__)
#define MOCK_CONST_METHOD3_T_WITH_CALLTYPE(ct, m, ...) \
  MOCK_CONST_METHOD3_WITH_CALLTYPE(ct, m, __VA_ARGS__)
#define MOCK_CONST_METHOD4_T_WITH_CALLTYPE(ct, m, ...) \
  MOCK_CONST_METHOD4_WITH_CALLTYPE(ct, m, __VA_ARGS__)
#define MOCK_CONST_METHOD5_T_WITH_CALLTYPE(ct, m, ...) \
  MOCK_CONST_METHOD5_WITH_CALLTYPE(ct, m, __VA_ARGS__)
#define MOCK_CONST_METHOD6_T_WITH_CALLTYPE(ct, m, ...) \
  MOCK_CONST_METHOD6_WITH_CALLTYPE(ct, m, __VA_ARGS__)
#define MOCK_CONST_METHOD7_T_WITH_CALLTYPE(ct, m, ...) \
  MOCK_CONST_METHOD7_WITH_CALLTYPE(ct, m, __VA_ARGS__)
#define MOCK_CONST_METHOD8_T_WITH_CALLTYPE(ct, m, ...) \
  MOCK_CONST_METHOD8_WITH_CALLTYPE(ct, m, __VA_ARGS__)
#define MOCK_CONST_METHOD9_T_WITH_CALLTYPE(ct, m, ...) \
  MOCK_CONST_METHOD9_WITH_CALLTYPE(ct, m, __VA_ARGS__)
#define MOCK_CONST_METHOD10_T_WITH_CALLTYPE(ct, m, ...) \
  MOCK_CONST_METHOD10_WITH_CALLTYPE(ct, m, __VA_ARGS__)

#define GMOCK_INTERNAL_MOCK_METHODN(constness, ct, Method, args_num, ...) \
  GMOCK_INTERNAL_ASSERT_VALID_SIGNATURE(                                  \
      args_num, ::testing::internal::identity_t<__VA_ARGS__>);            \
  GMOCK_INTERNAL_MOCK_METHOD_IMPL(                                        \
      args_num, Method, GMOCK_PP_NARG0(constness), 0, 0, , ct, ,          \
      (::testing::internal::identity_t<__VA_ARGS__>))

#define GMOCK_MOCKER_(arity, constness, Method) \
  GTEST_CONCAT_TOKEN_(gmock##constness##arity##_##Method##_, __LINE__)

#endif  // GOOGLEMOCK_INCLUDE_GMOCK_INTERNAL_GMOCK_FUNCTION_MOCKER_H_
