// File: gmock-pp.h
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

#ifndef GOOGLEMOCK_INCLUDE_GMOCK_INTERNAL_GMOCK_PP_H_
#define GOOGLEMOCK_INCLUDE_GMOCK_INTERNAL_GMOCK_PP_H_

// Expands and concatenates the arguments. Constructed macros reevaluate.
#define GMOCK_PP_CAT(_1, _2) GMOCK_PP_INTERNAL_CAT(_1, _2)

// Expands and stringifies the only argument.
#define GMOCK_PP_STRINGIZE(...) GMOCK_PP_INTERNAL_STRINGIZE(__VA_ARGS__)

// Returns empty. Given a variadic number of arguments.
#define GMOCK_PP_EMPTY(...)

// Returns a comma. Given a variadic number of arguments.
#define GMOCK_PP_COMMA(...) ,

// Returns the only argument.
#define GMOCK_PP_IDENTITY(_1) _1

// Evaluates to the number of arguments after expansion.
//
//   #define PAIR x, y
//
//   GMOCK_PP_NARG() => 1
//   GMOCK_PP_NARG(x) => 1
//   GMOCK_PP_NARG(x, y) => 2
//   GMOCK_PP_NARG(PAIR) => 2
//
// Requires: the number of arguments after expansion is at most 15.
#define GMOCK_PP_NARG(...) \
  GMOCK_PP_INTERNAL_16TH(  \
      (__VA_ARGS__, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0))

// Returns 1 if the expansion of arguments has an unprotected comma. Otherwise
// returns 0. Requires no more than 15 unprotected commas.
#define GMOCK_PP_HAS_COMMA(...) \
  GMOCK_PP_INTERNAL_16TH(       \
      (__VA_ARGS__, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0))

// Returns the first argument.
#define GMOCK_PP_HEAD(...) GMOCK_PP_INTERNAL_HEAD((__VA_ARGS__, unusedArg))

// Returns the tail. A variadic list of all arguments minus the first. Requires
// at least one argument.
#define GMOCK_PP_TAIL(...) GMOCK_PP_INTERNAL_TAIL((__VA_ARGS__))

// Calls CAT(_Macro, NARG(__VA_ARGS__))(__VA_ARGS__)
#define GMOCK_PP_VARIADIC_CALL(_Macro, ...) \
  GMOCK_PP_IDENTITY(                        \
      GMOCK_PP_CAT(_Macro, GMOCK_PP_NARG(__VA_ARGS__))(__VA_ARGS__))

// If the arguments after expansion have no tokens, evaluates to `1`. Otherwise
// evaluates to `0`.
//
// Requires: * the number of arguments after expansion is at most 15.
//           * If the argument is a macro, it must be able to be called with one
//             argument.
//
// Implementation details:
//
// There is one case when it generates a compile error: if the argument is macro
// that cannot be called with one argument.
//
//   #define M(a, b)  // it doesn't matter what it expands to
//
//   // Expected: expands to `0`.
//   // Actual: compile error.
//   GMOCK_PP_IS_EMPTY(M)
//
// There are 4 cases tested:
//
// * __VA_ARGS__ possible expansion has no unparen'd commas. Expected 0.
// * __VA_ARGS__ possible expansion is not enclosed in parenthesis. Expected 0.
// * __VA_ARGS__ possible expansion is not a macro that ()-evaluates to a comma.
//   Expected 0
// * __VA_ARGS__ is empty, or has unparen'd commas, or is enclosed in
//   parenthesis, or is a macro that ()-evaluates to comma. Expected 1.
//
// We trigger detection on '0001', i.e. on empty.
#define GMOCK_PP_IS_EMPTY(...)                                               \
  GMOCK_PP_INTERNAL_IS_EMPTY(GMOCK_PP_HAS_COMMA(__VA_ARGS__),                \
                             GMOCK_PP_HAS_COMMA(GMOCK_PP_COMMA __VA_ARGS__), \
                             GMOCK_PP_HAS_COMMA(__VA_ARGS__()),              \
                             GMOCK_PP_HAS_COMMA(GMOCK_PP_COMMA __VA_ARGS__()))

// Evaluates to _Then if _Cond is 1 and _Else if _Cond is 0.
#define GMOCK_PP_IF(_Cond, _Then, _Else) \
  GMOCK_PP_CAT(GMOCK_PP_INTERNAL_IF_, _Cond)(_Then, _Else)

// Similar to GMOCK_PP_IF but takes _Then and _Else in parentheses.
//
// GMOCK_PP_GENERIC_IF(1, (a, b, c), (d, e, f)) => a, b, c
// GMOCK_PP_GENERIC_IF(0, (a, b, c), (d, e, f)) => d, e, f
//
#define GMOCK_PP_GENERIC_IF(_Cond, _Then, _Else) \
  GMOCK_PP_REMOVE_PARENS(GMOCK_PP_IF(_Cond, _Then, _Else))

// Evaluates to the number of arguments after expansion. Identifies 'empty' as
// 0.
//
//   #define PAIR x, y
//
//   GMOCK_PP_NARG0() => 0
//   GMOCK_PP_NARG0(x) => 1
//   GMOCK_PP_NARG0(x, y) => 2
//   GMOCK_PP_NARG0(PAIR) => 2
//
// Requires: * the number of arguments after expansion is at most 15.
//           * If the argument is a macro, it must be able to be called with one
//             argument.
#define GMOCK_PP_NARG0(...) \
  GMOCK_PP_IF(GMOCK_PP_IS_EMPTY(__VA_ARGS__), 0, GMOCK_PP_NARG(__VA_ARGS__))

// Expands to 1 if the first argument starts with something in parentheses,
// otherwise to 0.
#define GMOCK_PP_IS_BEGIN_PARENS(...)                              \
  GMOCK_PP_HEAD(GMOCK_PP_CAT(GMOCK_PP_INTERNAL_IBP_IS_VARIADIC_R_, \
                             GMOCK_PP_INTERNAL_IBP_IS_VARIADIC_C __VA_ARGS__))

// Expands to 1 is there is only one argument and it is enclosed in parentheses.
#define GMOCK_PP_IS_ENCLOSED_PARENS(...)             \
  GMOCK_PP_IF(GMOCK_PP_IS_BEGIN_PARENS(__VA_ARGS__), \
              GMOCK_PP_IS_EMPTY(GMOCK_PP_EMPTY __VA_ARGS__), 0)

// Remove the parens, requires GMOCK_PP_IS_ENCLOSED_PARENS(args) => 1.
#define GMOCK_PP_REMOVE_PARENS(...) GMOCK_PP_INTERNAL_REMOVE_PARENS __VA_ARGS__

// Expands to _Macro(0, _Data, e1) _Macro(1, _Data, e2) ... _Macro(K -1, _Data,
// eK) as many of GMOCK_INTERNAL_NARG0 _Tuple.
// Requires: * |_Macro| can be called with 3 arguments.
//           * |_Tuple| expansion has no more than 15 elements.
#define GMOCK_PP_FOR_EACH(_Macro, _Data, _Tuple)                        \
  GMOCK_PP_CAT(GMOCK_PP_INTERNAL_FOR_EACH_IMPL_, GMOCK_PP_NARG0 _Tuple) \
  (0, _Macro, _Data, _Tuple)

// Expands to _Macro(0, _Data, ) _Macro(1, _Data, ) ... _Macro(K - 1, _Data, )
// Empty if _K = 0.
// Requires: * |_Macro| can be called with 3 arguments.
//           * |_K| literal between 0 and 15
#define GMOCK_PP_REPEAT(_Macro, _Data, _N)           \
  GMOCK_PP_CAT(GMOCK_PP_INTERNAL_FOR_EACH_IMPL_, _N) \
  (0, _Macro, _Data, GMOCK_PP_INTENRAL_EMPTY_TUPLE)

// Increments the argument, requires the argument to be between 0 and 15.
#define GMOCK_PP_INC(_i) GMOCK_PP_CAT(GMOCK_PP_INTERNAL_INC_, _i)

// Returns comma if _i != 0. Requires _i to be between 0 and 15.
#define GMOCK_PP_COMMA_IF(_i) GMOCK_PP_CAT(GMOCK_PP_INTERNAL_COMMA_IF_, _i)

// Internal details follow. Do not use any of these symbols outside of this
// file or we will break your code.
#define GMOCK_PP_INTENRAL_EMPTY_TUPLE (, , , , , , , , , , , , , , , )
#define GMOCK_PP_INTERNAL_CAT(_1, _2) _1##_2
#define GMOCK_PP_INTERNAL_STRINGIZE(...) #__VA_ARGS__
#define GMOCK_PP_INTERNAL_CAT_5(_1, _2, _3, _4, _5) _1##_2##_3##_4##_5
#define GMOCK_PP_INTERNAL_IS_EMPTY(_1, _2, _3, _4)                             \
  GMOCK_PP_HAS_COMMA(GMOCK_PP_INTERNAL_CAT_5(GMOCK_PP_INTERNAL_IS_EMPTY_CASE_, \
                                             _1, _2, _3, _4))
#define GMOCK_PP_INTERNAL_IS_EMPTY_CASE_0001 ,
#define GMOCK_PP_INTERNAL_IF_1(_Then, _Else) _Then
#define GMOCK_PP_INTERNAL_IF_0(_Then, _Else) _Else

// Because of MSVC treating a token with a comma in it as a single token when
// passed to another macro, we need to force it to evaluate it as multiple
// tokens. We do that by using a "IDENTITY(MACRO PARENTHESIZED_ARGS)" macro. We
// define one per possible macro that relies on this behavior. Note "_Args" must
// be parenthesized.
#define GMOCK_PP_INTERNAL_INTERNAL_16TH(_1, _2, _3, _4, _5, _6, _7, _8, _9, \
  _10, _11, _12, _13, _14, _15, _16,  \
  ...)                                \
  _16
#define GMOCK_PP_INTERNAL_16TH(_Args) \
  GMOCK_PP_IDENTITY(GMOCK_PP_INTERNAL_INTERNAL_16TH _Args)
#define GMOCK_PP_INTERNAL_INTERNAL_HEAD(_1, ...) _1
#define GMOCK_PP_INTERNAL_HEAD(_Args) \
  GMOCK_PP_IDENTITY(GMOCK_PP_INTERNAL_INTERNAL_HEAD _Args)
#define GMOCK_PP_INTERNAL_INTERNAL_TAIL(_1, ...) __VA_ARGS__
#define GMOCK_PP_INTERNAL_TAIL(_Args) \
  GMOCK_PP_IDENTITY(GMOCK_PP_INTERNAL_INTERNAL_TAIL _Args)

#define GMOCK_PP_INTERNAL_IBP_IS_VARIADIC_C(...) 1 _
#define GMOCK_PP_INTERNAL_IBP_IS_VARIADIC_R_1 1,
#define GMOCK_PP_INTERNAL_IBP_IS_VARIADIC_R_GMOCK_PP_INTERNAL_IBP_IS_VARIADIC_C \
  0,
#define GMOCK_PP_INTERNAL_REMOVE_PARENS(...) __VA_ARGS__
#define GMOCK_PP_INTERNAL_INC_0 1
#define GMOCK_PP_INTERNAL_INC_1 2
#define GMOCK_PP_INTERNAL_INC_2 3
#define GMOCK_PP_INTERNAL_INC_3 4
#define GMOCK_PP_INTERNAL_INC_4 5
#define GMOCK_PP_INTERNAL_INC_5 6
#define GMOCK_PP_INTERNAL_INC_6 7
#define GMOCK_PP_INTERNAL_INC_7 8
#define GMOCK_PP_INTERNAL_INC_8 9
#define GMOCK_PP_INTERNAL_INC_9 10
#define GMOCK_PP_INTERNAL_INC_10 11
#define GMOCK_PP_INTERNAL_INC_11 12
#define GMOCK_PP_INTERNAL_INC_12 13
#define GMOCK_PP_INTERNAL_INC_13 14
#define GMOCK_PP_INTERNAL_INC_14 15
#define GMOCK_PP_INTERNAL_INC_15 16
#define GMOCK_PP_INTERNAL_COMMA_IF_0
#define GMOCK_PP_INTERNAL_COMMA_IF_1 ,
#define GMOCK_PP_INTERNAL_COMMA_IF_2 ,
#define GMOCK_PP_INTERNAL_COMMA_IF_3 ,
#define GMOCK_PP_INTERNAL_COMMA_IF_4 ,
#define GMOCK_PP_INTERNAL_COMMA_IF_5 ,
#define GMOCK_PP_INTERNAL_COMMA_IF_6 ,
#define GMOCK_PP_INTERNAL_COMMA_IF_7 ,
#define GMOCK_PP_INTERNAL_COMMA_IF_8 ,
#define GMOCK_PP_INTERNAL_COMMA_IF_9 ,
#define GMOCK_PP_INTERNAL_COMMA_IF_10 ,
#define GMOCK_PP_INTERNAL_COMMA_IF_11 ,
#define GMOCK_PP_INTERNAL_COMMA_IF_12 ,
#define GMOCK_PP_INTERNAL_COMMA_IF_13 ,
#define GMOCK_PP_INTERNAL_COMMA_IF_14 ,
#define GMOCK_PP_INTERNAL_COMMA_IF_15 ,
#define GMOCK_PP_INTERNAL_CALL_MACRO(_Macro, _i, _Data, _element) \
  _Macro(_i, _Data, _element)
#define GMOCK_PP_INTERNAL_FOR_EACH_IMPL_0(_i, _Macro, _Data, _Tuple)
#define GMOCK_PP_INTERNAL_FOR_EACH_IMPL_1(_i, _Macro, _Data, _Tuple) \
  GMOCK_PP_INTERNAL_CALL_MACRO(_Macro, _i, _Data, GMOCK_PP_HEAD _Tuple)
#define GMOCK_PP_INTERNAL_FOR_EACH_IMPL_2(_i, _Macro, _Data, _Tuple)    \
  GMOCK_PP_INTERNAL_CALL_MACRO(_Macro, _i, _Data, GMOCK_PP_HEAD _Tuple) \
  GMOCK_PP_INTERNAL_FOR_EACH_IMPL_1(GMOCK_PP_INC(_i), _Macro, _Data,    \
                                    (GMOCK_PP_TAIL _Tuple))
#define GMOCK_PP_INTERNAL_FOR_EACH_IMPL_3(_i, _Macro, _Data, _Tuple)    \
  GMOCK_PP_INTERNAL_CALL_MACRO(_Macro, _i, _Data, GMOCK_PP_HEAD _Tuple) \
  GMOCK_PP_INTERNAL_FOR_EACH_IMPL_2(GMOCK_PP_INC(_i), _Macro, _Data,    \
                                    (GMOCK_PP_TAIL _Tuple))
#define GMOCK_PP_INTERNAL_FOR_EACH_IMPL_4(_i, _Macro, _Data, _Tuple)    \
  GMOCK_PP_INTERNAL_CALL_MACRO(_Macro, _i, _Data, GMOCK_PP_HEAD _Tuple) \
  GMOCK_PP_INTERNAL_FOR_EACH_IMPL_3(GMOCK_PP_INC(_i), _Macro, _Data,    \
                                    (GMOCK_PP_TAIL _Tuple))
#define GMOCK_PP_INTERNAL_FOR_EACH_IMPL_5(_i, _Macro, _Data, _Tuple)    \
  GMOCK_PP_INTERNAL_CALL_MACRO(_Macro, _i, _Data, GMOCK_PP_HEAD _Tuple) \
  GMOCK_PP_INTERNAL_FOR_EACH_IMPL_4(GMOCK_PP_INC(_i), _Macro, _Data,    \
                                    (GMOCK_PP_TAIL _Tuple))
#define GMOCK_PP_INTERNAL_FOR_EACH_IMPL_6(_i, _Macro, _Data, _Tuple)    \
  GMOCK_PP_INTERNAL_CALL_MACRO(_Macro, _i, _Data, GMOCK_PP_HEAD _Tuple) \
  GMOCK_PP_INTERNAL_FOR_EACH_IMPL_5(GMOCK_PP_INC(_i), _Macro, _Data,    \
                                    (GMOCK_PP_TAIL _Tuple))
#define GMOCK_PP_INTERNAL_FOR_EACH_IMPL_7(_i, _Macro, _Data, _Tuple)    \
  GMOCK_PP_INTERNAL_CALL_MACRO(_Macro, _i, _Data, GMOCK_PP_HEAD _Tuple) \
  GMOCK_PP_INTERNAL_FOR_EACH_IMPL_6(GMOCK_PP_INC(_i), _Macro, _Data,    \
                                    (GMOCK_PP_TAIL _Tuple))
#define GMOCK_PP_INTERNAL_FOR_EACH_IMPL_8(_i, _Macro, _Data, _Tuple)    \
  GMOCK_PP_INTERNAL_CALL_MACRO(_Macro, _i, _Data, GMOCK_PP_HEAD _Tuple) \
  GMOCK_PP_INTERNAL_FOR_EACH_IMPL_7(GMOCK_PP_INC(_i), _Macro, _Data,    \
                                    (GMOCK_PP_TAIL _Tuple))
#define GMOCK_PP_INTERNAL_FOR_EACH_IMPL_9(_i, _Macro, _Data, _Tuple)    \
  GMOCK_PP_INTERNAL_CALL_MACRO(_Macro, _i, _Data, GMOCK_PP_HEAD _Tuple) \
  GMOCK_PP_INTERNAL_FOR_EACH_IMPL_8(GMOCK_PP_INC(_i), _Macro, _Data,    \
                                    (GMOCK_PP_TAIL _Tuple))
#define GMOCK_PP_INTERNAL_FOR_EACH_IMPL_10(_i, _Macro, _Data, _Tuple)   \
  GMOCK_PP_INTERNAL_CALL_MACRO(_Macro, _i, _Data, GMOCK_PP_HEAD _Tuple) \
  GMOCK_PP_INTERNAL_FOR_EACH_IMPL_9(GMOCK_PP_INC(_i), _Macro, _Data,    \
                                    (GMOCK_PP_TAIL _Tuple))
#define GMOCK_PP_INTERNAL_FOR_EACH_IMPL_11(_i, _Macro, _Data, _Tuple)   \
  GMOCK_PP_INTERNAL_CALL_MACRO(_Macro, _i, _Data, GMOCK_PP_HEAD _Tuple) \
  GMOCK_PP_INTERNAL_FOR_EACH_IMPL_10(GMOCK_PP_INC(_i), _Macro, _Data,   \
                                     (GMOCK_PP_TAIL _Tuple))
#define GMOCK_PP_INTERNAL_FOR_EACH_IMPL_12(_i, _Macro, _Data, _Tuple)   \
  GMOCK_PP_INTERNAL_CALL_MACRO(_Macro, _i, _Data, GMOCK_PP_HEAD _Tuple) \
  GMOCK_PP_INTERNAL_FOR_EACH_IMPL_11(GMOCK_PP_INC(_i), _Macro, _Data,   \
                                     (GMOCK_PP_TAIL _Tuple))
#define GMOCK_PP_INTERNAL_FOR_EACH_IMPL_13(_i, _Macro, _Data, _Tuple)   \
  GMOCK_PP_INTERNAL_CALL_MACRO(_Macro, _i, _Data, GMOCK_PP_HEAD _Tuple) \
  GMOCK_PP_INTERNAL_FOR_EACH_IMPL_12(GMOCK_PP_INC(_i), _Macro, _Data,   \
                                     (GMOCK_PP_TAIL _Tuple))
#define GMOCK_PP_INTERNAL_FOR_EACH_IMPL_14(_i, _Macro, _Data, _Tuple)   \
  GMOCK_PP_INTERNAL_CALL_MACRO(_Macro, _i, _Data, GMOCK_PP_HEAD _Tuple) \
  GMOCK_PP_INTERNAL_FOR_EACH_IMPL_13(GMOCK_PP_INC(_i), _Macro, _Data,   \
                                     (GMOCK_PP_TAIL _Tuple))
#define GMOCK_PP_INTERNAL_FOR_EACH_IMPL_15(_i, _Macro, _Data, _Tuple)   \
  GMOCK_PP_INTERNAL_CALL_MACRO(_Macro, _i, _Data, GMOCK_PP_HEAD _Tuple) \
  GMOCK_PP_INTERNAL_FOR_EACH_IMPL_14(GMOCK_PP_INC(_i), _Macro, _Data,   \
                                     (GMOCK_PP_TAIL _Tuple))

#endif  // GOOGLEMOCK_INCLUDE_GMOCK_INTERNAL_GMOCK_PP_H_
