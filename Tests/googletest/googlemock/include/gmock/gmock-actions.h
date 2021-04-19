// File: gmock-actions.h
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

#ifndef GOOGLEMOCK_INCLUDE_GMOCK_GMOCK_ACTIONS_H_
#define GOOGLEMOCK_INCLUDE_GMOCK_GMOCK_ACTIONS_H_

#ifndef _WIN32_WCE
# include <errno.h>
#endif

#include <algorithm>
#include <functional>
#include <memory>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>

#include "gmock/internal/gmock-internal-utils.h"
#include "gmock/internal/gmock-port.h"
#include "gmock/internal/gmock-pp.h"

#ifdef _MSC_VER
# pragma warning(push)
# pragma warning(disable:4100)
#endif

namespace testing {

// To implement an action Foo, define:
//   1. a class FooAction that implements the ActionInterface interface, and
//   2. a factory function that creates an Action object from a
//      const FooAction*.
//
// The two-level delegation design follows that of Matcher, providing
// consistency for extension developers.  It also eases ownership
// management as Action objects can now be copied like plain values.

namespace internal {

// BuiltInDefaultValueGetter<T, true>::Get() returns a
// default-constructed T value.  BuiltInDefaultValueGetter<T,
// false>::Get() crashes with an error.
//
// This primary template is used when kDefaultConstructible is true.
template <typename T, bool kDefaultConstructible>
struct BuiltInDefaultValueGetter {
  static auto Get() -> T { return T(); }
};

template <typename T>
struct BuiltInDefaultValueGetter<T, false> {
  static auto Get() -> T {
    Assert(false, __FILE__, __LINE__,
           "Default action undefined for the function return type.");
    return internal::Invalid<T>();
    // The above statement will never be reached, but is required in
    // order for this function to compile.
  }
};

// BuiltInDefaultValue<T>::Get() returns the "built-in" default value
// for type T, which is NULL when T is a raw pointer type, 0 when T is
// a numeric type, false when T is bool, or "" when T is string or
// std::string.  In addition, in C++11 and above, it turns a
// default-constructed T value if T is default constructible.  For any
// other type T, the built-in default T value is undefined, and the
// function will abort the process.
template <typename T>
class BuiltInDefaultValue {
public:
  // This function returns true if and only if type T has a built-in default
  // value.
  static auto Exists() -> bool {
    return std::is_default_constructible<T>::value;
  }

  static auto Get() -> T {
    return BuiltInDefaultValueGetter<
      T, std::is_default_constructible<T>::value>::Get();
  }
};

// This partial specialization says that we use the same built-in
// default value for T and const T.
template <typename T>
class BuiltInDefaultValue<const T> {
public:
  static auto Exists() -> bool { return BuiltInDefaultValue<T>::Exists(); }
  static auto Get() -> T { return BuiltInDefaultValue<T>::Get(); }
};

// This partial specialization defines the default values for pointer
// types.
template <typename T>
class BuiltInDefaultValue<T*> {
public:
  static auto Exists() -> bool { return true; }
  static auto Get() -> T* { return nullptr; }
};

// The following specializations define the default values for
// specific types we care about.
#define GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_(type, value) \
  template <> \
  class BuiltInDefaultValue<type> { \
   public: \
    static bool Exists() { return true; } \
    static type Get() { return value; } \
  }

GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_(void,); // NOLINT
GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_(::std::string, "");

GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_(bool, false);

GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_(unsigned char, '\0');

GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_(signed char, '\0');

GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_(char, '\0');

// There's no need for a default action for signed wchar_t, as that
// type is the same as wchar_t for gcc, and invalid for MSVC.
//
// There's also no need for a default action for unsigned wchar_t, as
// that type is the same as unsigned int for gcc, and invalid for
// MSVC.
#if GMOCK_WCHAR_T_IS_NATIVE_
GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_(wchar_t, 0U); // NOLINT
#endif

GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_(unsigned short, 0U); // NOLINT
GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_(signed short, 0);    // NOLINT
GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_(unsigned int, 0U);

GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_(signed int, 0);

GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_(unsigned long, 0UL);    // NOLINT
GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_(signed long, 0L);       // NOLINT
GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_(unsigned long long, 0); // NOLINT
GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_(signed long long, 0);   // NOLINT
GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_(float, 0);

GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_(double, 0);

#undef GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_

// Simple two-arg form of std::disjunction.
template <typename P, typename Q>
using disjunction = typename std::conditional<P::value, P, Q>::type;

} // namespace internal

// When an unexpected function call is encountered, Google Mock will
// let it return a default value if the user has specified one for its
// return type, or if the return type has a built-in default value;
// otherwise Google Mock won't know what value to return and will have
// to abort the process.
//
// The DefaultValue<T> class allows a user to specify the
// default value for a type T that is both copyable and publicly
// destructible (i.e. anything that can be used as a function return
// type).  The usage is:
//
//   // Sets the default value for type T to be foo.
//   DefaultValue<T>::Set(foo);
template <typename T>
class DefaultValue {
public:
  // Sets the default value for type T; requires T to be
  // copy-constructable and have a public destructor.
  static auto Set(T x) -> void {
    delete producer_;
    producer_ = new FixedValueProducer(x);
  }

  // Provides a factory function to be called to generate the default value.
  // This method can be used even if T is only move-constructible, but it is not
  // limited to that case.
  using FactoryFunction = T(*)();

  static auto SetFactory(FactoryFunction factory) -> void {
    delete producer_;
    producer_ = new FactoryValueProducer(factory);
  }

  // Unsets the default value for type T.
  static auto Clear() -> void {
    delete producer_;
    producer_ = nullptr;
  }

  // Returns true if and only if the user has set the default value for type T.
  static auto IsSet() -> bool { return producer_ != nullptr; }

  // Returns true if T has a default return value set by the user or there
  // exists a built-in default value.
  static auto Exists() -> bool {
    return IsSet() || internal::BuiltInDefaultValue<T>::Exists();
  }

  // Returns the default value for type T if the user has set one;
  // otherwise returns the built-in default value. Requires that Exists()
  // is true, which ensures that the return value is well-defined.
  static auto Get() -> T {
    return producer_ == nullptr
             ? internal::BuiltInDefaultValue<T>::Get()
             : producer_->Produce();
  }

private:
  class ValueProducer {
  public:
    virtual ~ValueProducer() {}
    virtual auto Produce() -> T = 0;
  };

  class FixedValueProducer : public ValueProducer {
  public:
    explicit FixedValueProducer(T value)
      : value_(value) {}

    auto Produce() -> T override { return value_; }

  private:
    const T value_;
    GTEST_DISALLOW_COPY_AND_ASSIGN_(FixedValueProducer);
  };

  class FactoryValueProducer : public ValueProducer {
  public:
    explicit FactoryValueProducer(FactoryFunction factory)
      : factory_(factory) {}

    auto Produce() -> T override { return factory_(); }

  private:
    const FactoryFunction factory_;
    GTEST_DISALLOW_COPY_AND_ASSIGN_(FactoryValueProducer);
  };

  static ValueProducer* producer_;
};

// This partial specialization allows a user to set default values for
// reference types.
template <typename T>
class DefaultValue<T&> {
public:
  // Sets the default value for type T&.
  static auto Set(T& x) -> void {
    // NOLINT
    address_ = &x;
  }

  // Unsets the default value for type T&.
  static auto Clear() -> void { address_ = nullptr; }

  // Returns true if and only if the user has set the default value for type T&.
  static auto IsSet() -> bool { return address_ != nullptr; }

  // Returns true if T has a default return value set by the user or there
  // exists a built-in default value.
  static auto Exists() -> bool {
    return IsSet() || internal::BuiltInDefaultValue<T&>::Exists();
  }

  // Returns the default value for type T& if the user has set one;
  // otherwise returns the built-in default value if there is one;
  // otherwise aborts the process.
  static auto Get() -> T& {
    return address_ == nullptr
             ? internal::BuiltInDefaultValue<T&>::Get()
             : *address_;
  }

private:
  static T* address_;
};

// This specialization allows DefaultValue<void>::Get() to
// compile.
template <>
class DefaultValue<void> {
public:
  static auto Exists() -> bool { return true; }
  static auto Get() -> void {}
};

// Points to the user-set default value for type T.
template <typename T>
typename DefaultValue<T>::ValueProducer* DefaultValue<T>::producer_ = nullptr;

// Points to the user-set default value for type T&.
template <typename T>
T* DefaultValue<T&>::address_ = nullptr;

// Implement this interface to define an action for function type F.
template <typename F>
class ActionInterface {
public:
  using Result = typename internal::Function<F>::Result;
  using ArgumentTuple = typename internal::Function<F>::ArgumentTuple;

  ActionInterface() {}
  virtual ~ActionInterface() {}

  // Performs the action.  This method is not const, as in general an
  // action can have side effects and be stateful.  For example, a
  // get-the-next-element-from-the-collection action will need to
  // remember the current element.
  virtual auto Perform(const ArgumentTuple& args) -> Result = 0;

private:
  GTEST_DISALLOW_COPY_AND_ASSIGN_(ActionInterface);
};

// An Action<F> is a copyable and IMMUTABLE (except by assignment)
// object that represents an action to be taken when a mock function
// of type F is called.  The implementation of Action<T> is just a
// std::shared_ptr to const ActionInterface<T>. Don't inherit from Action!
// You can view an object implementing ActionInterface<F> as a
// concrete action (including its current state), and an Action<F>
// object as a handle to it.
template <typename F>
class Action {
  // Adapter class to allow constructing Action from a legacy ActionInterface.
  // New code should create Actions from functors instead.
  struct ActionAdapter {
    // Adapter must be copyable to satisfy std::function requirements.
    std::shared_ptr<ActionInterface<F>> impl_;

    template <typename... Args>
    auto operator()(Args&&...args) -> typename internal::Function<F>::Result {
      return impl_->Perform(
          std::forward_as_tuple(std::forward<Args>(args)...));
    }
  };

  template <typename G>
  using IsCompatibleFunctor = std::is_constructible<std::function<F>, G>;

public:
  using Result = typename internal::Function<F>::Result;
  using ArgumentTuple = typename internal::Function<F>::ArgumentTuple;

  // Constructs a null Action.  Needed for storing Action objects in
  // STL containers.
  Action() {}

  // Construct an Action from a specified callable.
  // This cannot take std::function directly, because then Action would not be
  // directly constructible from lambda (it would require two conversions).
  template <
    typename G,
    typename = typename std::enable_if<internal::disjunction<
      IsCompatibleFunctor<G>, std::is_constructible<std::function<Result()>,
                                                    G>>::value>::type>
  Action(G&& fun) {
    // NOLINT
    Init(std::forward<G>(fun), IsCompatibleFunctor<G>());
  }

  // Constructs an Action from its implementation.
  explicit Action(ActionInterface<F>* impl)
    : fun_(ActionAdapter {std::shared_ptr<ActionInterface<F>>(impl)}) {}

  // This constructor allows us to turn an Action<Func> object into an
  // Action<F>, as long as F's arguments can be implicitly converted
  // to Func's and Func's return type can be implicitly converted to F's.
  template <typename Func>
  explicit Action(const Action<Func>& action)
    : fun_(action.fun_) {}

  // Returns true if and only if this is the DoDefault() action.
  auto IsDoDefault() const -> bool { return fun_ == nullptr; }

  // Performs the action.  Note that this method is const even though
  // the corresponding method in ActionInterface is not.  The reason
  // is that a const Action<F> means that it cannot be re-bound to
  // another concrete action, not that the concrete action it binds to
  // cannot change state.  (Think of the difference between a const
  // pointer and a pointer to const.)
  auto Perform(ArgumentTuple args) const -> Result {
    if (IsDoDefault()) {
      internal::IllegalDoDefault(__FILE__, __LINE__);
    }
    return internal::Apply(fun_, std::move(args));
  }

private:
  template <typename G>
  friend class Action;

  template <typename G>
  auto Init(G&& g, std::true_type) -> void {
    fun_ = std::forward<G>(g);
  }

  template <typename G>
  auto Init(G&& g, std::false_type) -> void {
    fun_ = IgnoreArgs<typename std::decay<G>::type> {std::forward<G>(g)};
  }

  template <typename FunctionImpl>
  struct IgnoreArgs {
    template <typename... Args>
    auto operator()(const Args&...) const -> Result {
      return function_impl();
    }

    FunctionImpl function_impl;
  };

  // fun_ is an empty function if and only if this is the DoDefault() action.
  std::function<F> fun_;
};

// The PolymorphicAction class template makes it easy to implement a
// polymorphic action (i.e. an action that can be used in mock
// functions of than one type, e.g. Return()).
//
// To define a polymorphic action, a user first provides a COPYABLE
// implementation class that has a Perform() method template:
//
//   class FooAction {
//    public:
//     template <typename Result, typename ArgumentTuple>
//     Result Perform(const ArgumentTuple& args) const {
//       // Processes the arguments and returns a result, using
//       // std::get<N>(args) to get the N-th (0-based) argument in the tuple.
//     }
//     ...
//   };
//
// Then the user creates the polymorphic action using
// MakePolymorphicAction(object) where object has type FooAction.  See
// the definition of Return(void) and SetArgumentPointee<N>(value) for
// complete examples.
template <typename Impl>
class PolymorphicAction {
public:
  explicit PolymorphicAction(const Impl& impl)
    : impl_(impl) {}

  template <typename F>
  operator Action<F>() const {
    return Action<F>(new MonomorphicImpl<F>(impl_));
  }

private:
  template <typename F>
  class MonomorphicImpl : public ActionInterface<F> {
  public:
    using Result = typename internal::Function<F>::Result;
    using ArgumentTuple = typename internal::Function<F>::ArgumentTuple;

    explicit MonomorphicImpl(const Impl& impl)
      : impl_(impl) {}

    auto Perform(const ArgumentTuple& args) -> Result override {
      return impl_.template Perform<Result>(args);
    }

  private:
    Impl impl_;
  };

  Impl impl_;
};

// Creates an Action from its implementation and returns it.  The
// created Action object owns the implementation.
template <typename F>
auto MakeAction(ActionInterface<F>* impl) -> Action<F> {
  return Action<F>(impl);
}

// Creates a polymorphic action from its implementation.  This is
// easier to use than the PolymorphicAction<Impl> constructor as it
// doesn't require you to explicitly write the template argument, e.g.
//
//   MakePolymorphicAction(foo);
// vs
//   PolymorphicAction<TypeOfFoo>(foo);
template <typename Impl>
inline auto MakePolymorphicAction(const Impl& impl) -> PolymorphicAction<Impl> {
  return PolymorphicAction<Impl>(impl);
}

namespace internal {

// Helper struct to specialize ReturnAction to execute a move instead of a copy
// on return. Useful for move-only types, but could be used on any type.
template <typename T>
struct ByMoveWrapper {
  explicit ByMoveWrapper(T value)
    : payload(std::move(value)) {}

  T payload;
};

// Implements the polymorphic Return(x) action, which can be used in
// any function that returns the type of x, regardless of the argument
// types.
//
// Note: The value passed into Return must be converted into
// Function<F>::Result when this action is cast to Action<F> rather than
// when that action is performed. This is important in scenarios like
//
// MOCK_METHOD1(Method, T(U));
// ...
// {
//   Foo foo;
//   X x(&foo);
//   EXPECT_CALL(mock, Method(_)).WillOnce(Return(x));
// }
//
// In the example above the variable x holds reference to foo which leaves
// scope and gets destroyed.  If copying X just copies a reference to foo,
// that copy will be left with a hanging reference.  If conversion to T
// makes a copy of foo, the above code is safe. To support that scenario, we
// need to make sure that the type conversion happens inside the EXPECT_CALL
// statement, and conversion of the result of Return to Action<T(U)> is a
// good place for that.
//
// The real life example of the above scenario happens when an invocation
// of gtl::Container() is passed into Return.
//
template <typename R>
class ReturnAction {
public:
  // Constructs a ReturnAction object from the value to be returned.
  // 'value' is passed by value instead of by const reference in order
  // to allow Return("string literal") to compile.
  explicit ReturnAction(R value)
    : value_(new R(std::move(value))) {}

  // This template type conversion operator allows Return(x) to be
  // used in ANY function that returns x's type.
  template <typename F>
  operator Action<F>() const {
    // NOLINT
    // Assert statement belongs here because this is the best place to verify
    // conditions on F. It produces the clearest error messages
    // in most compilers.
    // Impl really belongs in this scope as a local class but can't
    // because MSVC produces duplicate symbols in different translation units
    // in this case. Until MS fixes that bug we put Impl into the class scope
    // and put the typedef both here (for use in assert statement) and
    // in the Impl class. But both definitions must be the same.
    using Result = typename Function<F>::Result;
    GTEST_COMPILE_ASSERT_(
        !std::is_reference<Result>::value,
        use_ReturnRef_instead_of_Return_to_return_a_reference);
    static_assert(!std::is_void<Result>::value,
      "Can't use Return() on an action expected to return `void`.");
    return Action<F>(new Impl<R, F>(value_));
  }

private:
  // Implements the Return(x) action for a particular function type F.
  template <typename R_, typename F>
  class Impl : public ActionInterface<F> {
  public:
    using Result = typename Function<F>::Result;
    using ArgumentTuple = typename Function<F>::ArgumentTuple;

    // The implicit cast is necessary when Result has more than one
    // single-argument constructor (e.g. Result is std::vector<int>) and R
    // has a type conversion operator template.  In that case, value_(value)
    // won't compile as the compiler doesn't known which constructor of
    // Result to call.  ImplicitCast_ forces the compiler to convert R to
    // Result without considering explicit constructors, thus resolving the
    // ambiguity. value_ is then initialized using its copy constructor.
    explicit Impl(const std::shared_ptr<R>& value)
      : value_before_cast_(*value),
        value_(ImplicitCast_<Result>(value_before_cast_)) {}

    auto Perform(const ArgumentTuple&) -> Result override { return value_; }

  private:
    GTEST_COMPILE_ASSERT_(!std::is_reference<Result>::value,
                          Result_cannot_be_a_reference_type);
    // We save the value before casting just in case it is being cast to a
    // wrapper type.
    R value_before_cast_;
    Result value_;

    GTEST_DISALLOW_COPY_AND_ASSIGN_(Impl);
  };

  // Partially specialize for ByMoveWrapper. This version of ReturnAction will
  // move its contents instead.
  template <typename R_, typename F>
  class Impl<ByMoveWrapper<R_>, F> : public ActionInterface<F> {
  public:
    using Result = typename Function<F>::Result;
    using ArgumentTuple = typename Function<F>::ArgumentTuple;

    explicit Impl(const std::shared_ptr<R>& wrapper)
      : performed_(false),
        wrapper_(wrapper) {}

    auto Perform(const ArgumentTuple&) -> Result override {
      GTEST_CHECK_(!performed_)
          << "A ByMove() action should only be performed once.";
      performed_ = true;
      return std::move(wrapper_->payload);
    }

  private:
    bool performed_;
    const std::shared_ptr<R> wrapper_;
  };

  const std::shared_ptr<R> value_;
};

// Implements the ReturnNull() action.
class ReturnNullAction {
public:
  // Allows ReturnNull() to be used in any pointer-returning function. In C++11
  // this is enforced by returning nullptr, and in non-C++11 by asserting a
  // pointer type on compile time.
  template <typename Result, typename ArgumentTuple>
  static auto Perform(const ArgumentTuple&) -> Result {
    return nullptr;
  }
};

// Implements the Return() action.
class ReturnVoidAction {
public:
  // Allows Return() to be used in any void-returning function.
  template <typename Result, typename ArgumentTuple>
  static auto Perform(const ArgumentTuple&) -> void {
    static_assert(std::is_void<Result>::value, "Result should be void.");
  }
};

// Implements the polymorphic ReturnRef(x) action, which can be used
// in any function that returns a reference to the type of x,
// regardless of the argument types.
template <typename T>
class ReturnRefAction {
public:
  // Constructs a ReturnRefAction object from the reference to be returned.
  explicit ReturnRefAction(T& ref)
    : ref_(ref) {} // NOLINT

  // This template type conversion operator allows ReturnRef(x) to be
  // used in ANY function that returns a reference to x's type.
  template <typename F>
  operator Action<F>() const {
    using Result = typename Function<F>::Result;
    // Asserts that the function return type is a reference.  This
    // catches the user error of using ReturnRef(x) when Return(x)
    // should be used, and generates some helpful error message.
    GTEST_COMPILE_ASSERT_(std::is_reference<Result>::value,
                          use_Return_instead_of_ReturnRef_to_return_a_value);
    return Action<F>(new Impl<F>(ref_));
  }

private:
  // Implements the ReturnRef(x) action for a particular function type F.
  template <typename F>
  class Impl : public ActionInterface<F> {
  public:
    using Result = typename Function<F>::Result;
    using ArgumentTuple = typename Function<F>::ArgumentTuple;

    explicit Impl(T& ref)
      : ref_(ref) {} // NOLINT

    auto Perform(const ArgumentTuple&) -> Result override { return ref_; }

  private:
    T& ref_;
  };

  T& ref_;
};

// Implements the polymorphic ReturnRefOfCopy(x) action, which can be
// used in any function that returns a reference to the type of x,
// regardless of the argument types.
template <typename T>
class ReturnRefOfCopyAction {
public:
  // Constructs a ReturnRefOfCopyAction object from the reference to
  // be returned.
  explicit ReturnRefOfCopyAction(const T& value)
    : value_(value) {} // NOLINT

  // This template type conversion operator allows ReturnRefOfCopy(x) to be
  // used in ANY function that returns a reference to x's type.
  template <typename F>
  operator Action<F>() const {
    using Result = typename Function<F>::Result;
    // Asserts that the function return type is a reference.  This
    // catches the user error of using ReturnRefOfCopy(x) when Return(x)
    // should be used, and generates some helpful error message.
    GTEST_COMPILE_ASSERT_(
        std::is_reference<Result>::value,
        use_Return_instead_of_ReturnRefOfCopy_to_return_a_value);
    return Action<F>(new Impl<F>(value_));
  }

private:
  // Implements the ReturnRefOfCopy(x) action for a particular function type F.
  template <typename F>
  class Impl : public ActionInterface<F> {
  public:
    using Result = typename Function<F>::Result;
    using ArgumentTuple = typename Function<F>::ArgumentTuple;

    explicit Impl(const T& value)
      : value_(value) {} // NOLINT

    auto Perform(const ArgumentTuple&) -> Result override { return value_; }

  private:
    T value_;
  };

  const T value_;
};

// Implements the polymorphic ReturnRoundRobin(v) action, which can be
// used in any function that returns the element_type of v.
template <typename T>
class ReturnRoundRobinAction {
public:
  explicit ReturnRoundRobinAction(std::vector<T> values) {
    GTEST_CHECK_(!values.empty())
        << "ReturnRoundRobin requires at least one element.";
    state_->values = std::move(values);
  }

  template <typename... Args>
  auto operator()(Args&&...) const -> T {
    return state_->Next();
  }

private:
  struct State {
    auto Next() -> T {
      T ret_val = values[i++];
      if (i == values.size()) {
        i = 0;
      }
      return ret_val;
    }

    std::vector<T> values;
    size_t i = 0;
  };

  std::shared_ptr<State> state_ = std::make_shared<State>();
};

// Implements the polymorphic DoDefault() action.
class DoDefaultAction {
public:
  // This template type conversion operator allows DoDefault() to be
  // used in any function.
  template <typename F>
  operator Action<F>() const { return Action<F>(); } // NOLINT
};

// Implements the Assign action to set a given pointer referent to a
// particular value.
template <typename T1, typename T2>
class AssignAction {
public:
  AssignAction(T1* ptr, T2 value)
    : ptr_(ptr),
      value_(value) {}

  template <typename Result, typename ArgumentTuple>
  auto Perform(const ArgumentTuple& /* args */) const -> void {
    *ptr_ = value_;
  }

private:
  T1* const ptr_;
  const T2 value_;
};

#if !GTEST_OS_WINDOWS_MOBILE

// Implements the SetErrnoAndReturn action to simulate return from
// various system calls and libc functions.
template <typename T>
class SetErrnoAndReturnAction {
public:
  SetErrnoAndReturnAction(int errno_value, T result)
    : errno_(errno_value),
      result_(result) {}

  template <typename Result, typename ArgumentTuple>
  auto Perform(const ArgumentTuple& /* args */) const -> Result {
    errno = errno_;
    return result_;
  }

private:
  const int errno_;
  const T result_;
};

#endif  // !GTEST_OS_WINDOWS_MOBILE

// Implements the SetArgumentPointee<N>(x) action for any function
// whose N-th argument (0-based) is a pointer to x's type.
template <size_t N, typename A, typename = void>
struct SetArgumentPointeeAction {
  A value;

  template <typename... Args>
  auto operator()(const Args&...args) const -> void {
    *std::get<N>(std::tie(args...)) = value;
  }
};

// Implements the Invoke(object_ptr, &Class::Method) action.
template <class Class, typename MethodPtr>
struct InvokeMethodAction {
  Class* const obj_ptr;
  const MethodPtr method_ptr;

  template <typename... Args>
  auto operator()(Args&&... args) const
  -> decltype((obj_ptr->*method_ptr)(std::forward<Args>(args)...)) {
    return (obj_ptr->*method_ptr)(std::forward<Args>(args)...);
  }
};

// Implements the InvokeWithoutArgs(f) action.  The template argument
// FunctionImpl is the implementation type of f, which can be either a
// function pointer or a functor.  InvokeWithoutArgs(f) can be used as an
// Action<F> as long as f's type is compatible with F.
template <typename FunctionImpl>
struct InvokeWithoutArgsAction {
  FunctionImpl function_impl;

  // Allows InvokeWithoutArgs(f) to be used as any action whose type is
  // compatible with f.
  template <typename... Args>
  auto operator()(const Args&...) -> decltype(function_impl()) {
    return function_impl();
  }
};

// Implements the InvokeWithoutArgs(object_ptr, &Class::Method) action.
template <class Class, typename MethodPtr>
struct InvokeMethodWithoutArgsAction {
  Class* const obj_ptr;
  const MethodPtr method_ptr;

  using ReturnType =
  decltype((std::declval<Class*>()->*std::declval<MethodPtr>())());

  template <typename... Args>
  auto operator()(const Args&...) const -> ReturnType {
    return (obj_ptr->*method_ptr)();
  }
};

// Implements the IgnoreResult(action) action.
template <typename A>
class IgnoreResultAction {
public:
  explicit IgnoreResultAction(const A& action)
    : action_(action) {}

  template <typename F>
  operator Action<F>() const {
    // Assert statement belongs here because this is the best place to verify
    // conditions on F. It produces the clearest error messages
    // in most compilers.
    // Impl really belongs in this scope as a local class but can't
    // because MSVC produces duplicate symbols in different translation units
    // in this case. Until MS fixes that bug we put Impl into the class scope
    // and put the typedef both here (for use in assert statement) and
    // in the Impl class. But both definitions must be the same.
    using Result = typename Function<F>::Result;

    // Asserts at compile time that F returns void.
    static_assert(std::is_void<Result>::value, "Result type should be void.");

    return Action<F>(new Impl<F>(action_));
  }

private:
  template <typename F>
  class Impl : public ActionInterface<F> {
  public:
    using Result = typename Function<F>::Result;
    using ArgumentTuple = typename Function<F>::ArgumentTuple;

    explicit Impl(const A& action)
      : action_(action) {}

    auto Perform(const ArgumentTuple& args) -> void override {
      // Performs the action and ignores its result.
      action_.Perform(args);
    }

  private:
    // Type OriginalFunction is the same as F except that its return
    // type is IgnoredValue.
    using OriginalFunction = typename Function<F>::MakeResultIgnoredValue;

    const Action<OriginalFunction> action_;
  };

  const A action_;
};

template <typename InnerAction, size_t... I>
struct WithArgsAction {
  InnerAction action;

  // The inner action could be anything convertible to Action<X>.
  // We use the conversion operator to detect the signature of the inner Action.
  template <typename R, typename... Args>
  operator Action<R(Args ...)>() const {
    // NOLINT
    using TupleType = std::tuple<Args...>;
    Action<R(typename std::tuple_element<I, TupleType>::type ...)>
        converted(action);

    return [converted](Args ... args) -> R
    {
      return converted.Perform(std::forward_as_tuple(
          std::get<I>(std::forward_as_tuple(std::forward<Args>(args)...))...));
    };
  }
};

template <typename... Actions>
struct DoAllAction {
private:
  template <typename T>
  using NonFinalType =
  typename std::conditional<std::is_scalar<T>::value, T, const T&>::type;

  template <typename ActionT, size_t... I>
  auto Convert(IndexSequence<I...>) const -> std::vector<ActionT> {
    return {ActionT(std::get<I>(actions))...};
  }

public:
  std::tuple<Actions...> actions;

  template <typename R, typename... Args>
  operator Action<R(Args ...)>() const {
    // NOLINT
    struct Op {
      std::vector<Action<void(NonFinalType<Args> ...)>> converted;
      Action<R(Args ...)> last;

      auto operator()(Args ...args) const -> R {
        auto tuple_args = std::forward_as_tuple(std::forward<Args>(args)...);
        for (auto& a : converted) {
          a.Perform(tuple_args);
        }
        return last.Perform(std::move(tuple_args));
      }
    };
    return Op {Convert<Action<void(NonFinalType<Args> ...)>>(
                   MakeIndexSequence<sizeof...(Actions) - 1>()),
               std::get<sizeof...(Actions) - 1>(actions)};
  }
};

template <typename T, typename... Params>
struct ReturnNewAction {
  auto operator()() const -> T* {
    return internal::Apply(
        [](const Params&... unpacked_params)
        {
          return new T(unpacked_params...);
        },
        params);
  }

  std::tuple<Params...> params;
};

template <size_t k>
struct ReturnArgAction {
  template <typename... Args>
  auto operator()(const Args&... args) const ->
  typename std::tuple_element<k, std::tuple<Args...>>::type {
    return std::get<k>(std::tie(args...));
  }
};

template <size_t k, typename Ptr>
struct SaveArgAction {
  Ptr pointer;

  template <typename... Args>
  auto operator()(const Args&...args) const -> void {
    *pointer = std::get<k>(std::tie(args...));
  }
};

template <size_t k, typename Ptr>
struct SaveArgPointeeAction {
  Ptr pointer;

  template <typename... Args>
  auto operator()(const Args&...args) const -> void {
    *pointer = *std::get<k>(std::tie(args...));
  }
};

template <size_t k, typename T>
struct SetArgRefereeAction {
  T value;

  template <typename... Args>
  auto operator()(Args&&...args) const -> void {
    using argk_type =
        typename tuple_element<k, std::tuple<Args...>>::type;
    static_assert(std::is_lvalue_reference<argk_type>::value,
      "Argument must be a reference type.");
    std::get<k>(std::tie(args...)) = value;
  }
};

template <size_t k, typename I1, typename I2>
struct SetArrayArgumentAction {
  I1 first;
  I2 last;

  template <typename... Args>
  auto operator()(const Args&...args) const -> void {
    auto value = std::get<k>(std::tie(args...));
    for (auto it = first; it != last; ++it, (void)++value) {
      *value = *it;
    }
  }
};

template <size_t k>
struct DeleteArgAction {
  template <typename... Args>
  auto operator()(const Args&...args) const -> void {
    delete std::get<k>(std::tie(args...));
  }
};

template <typename Ptr>
struct ReturnPointeeAction {
  Ptr pointer;

  template <typename... Args>
  auto operator()(const Args&...) const -> decltype(*pointer) {
    return *pointer;
  }
};

#if GTEST_HAS_EXCEPTIONS
template <typename T>
struct ThrowAction {
  T exception;
  // We use a conversion operator to adapt to any return type.
  template <typename R, typename... Args>
  operator Action<R(Args ...)>() const {
    // NOLINT
    T copy = exception;
    return [copy](Args ...) -> R { throw copy; };
  }
};
#endif  // GTEST_HAS_EXCEPTIONS

} // namespace internal

// An Unused object can be implicitly constructed from ANY value.
// This is handy when defining actions that ignore some or all of the
// mock function arguments.  For example, given
//
//   MOCK_METHOD3(Foo, double(const string& label, double x, double y));
//   MOCK_METHOD3(Bar, double(int index, double x, double y));
//
// instead of
//
//   double DistanceToOriginWithLabel(const string& label, double x, double y) {
//     return sqrt(x*x + y*y);
//   }
//   double DistanceToOriginWithIndex(int index, double x, double y) {
//     return sqrt(x*x + y*y);
//   }
//   ...
//   EXPECT_CALL(mock, Foo("abc", _, _))
//       .WillOnce(Invoke(DistanceToOriginWithLabel));
//   EXPECT_CALL(mock, Bar(5, _, _))
//       .WillOnce(Invoke(DistanceToOriginWithIndex));
//
// you could write
//
//   // We can declare any uninteresting argument as Unused.
//   double DistanceToOrigin(Unused, double x, double y) {
//     return sqrt(x*x + y*y);
//   }
//   ...
//   EXPECT_CALL(mock, Foo("abc", _, _)).WillOnce(Invoke(DistanceToOrigin));
//   EXPECT_CALL(mock, Bar(5, _, _)).WillOnce(Invoke(DistanceToOrigin));
using Unused = internal::IgnoredValue;

// Creates an action that does actions a1, a2, ..., sequentially in
// each invocation. All but the last action will have a readonly view of the
// arguments.
template <typename... Action>
auto DoAll(
    Action&&...action) -> internal::DoAllAction<typename std::decay<
  Action>::type...> {
  return {std::forward_as_tuple(std::forward<Action>(action)...)};
}

// WithArg<k>(an_action) creates an action that passes the k-th
// (0-based) argument of the mock function to an_action and performs
// it.  It adapts an action accepting one argument to one that accepts
// multiple arguments.  For convenience, we also provide
// WithArgs<k>(an_action) (defined below) as a synonym.
template <size_t k, typename InnerAction>
auto WithArg(
    InnerAction&& action) -> internal::WithArgsAction<
  typename std::decay<InnerAction>::type, k> {
  return {std::forward<InnerAction>(action)};
}

// WithArgs<N1, N2, ..., Nk>(an_action) creates an action that passes
// the selected arguments of the mock function to an_action and
// performs it.  It serves as an adaptor between actions with
// different argument lists.
template <size_t k, size_t... ks, typename InnerAction>
auto WithArgs(
    InnerAction&& action) -> internal::WithArgsAction<
  typename std::decay<InnerAction>::type, k, ks...> {
  return {std::forward<InnerAction>(action)};
}

// WithoutArgs(inner_action) can be used in a mock function with a
// non-empty argument list to perform inner_action, which takes no
// argument.  In other words, it adapts an action accepting no
// argument to one that accepts (and ignores) arguments.
template <typename InnerAction>
auto WithoutArgs(
    InnerAction&& action) -> internal::WithArgsAction<typename std::decay<
  InnerAction>::type> {
  return {std::forward<InnerAction>(action)};
}

// Creates an action that returns 'value'.  'value' is passed by value
// instead of const reference - otherwise Return("string literal")
// will trigger a compiler error about using array as initializer.
template <typename R>
auto Return(R value) -> internal::ReturnAction<R> {
  return internal::ReturnAction<R>(std::move(value));
}

// Creates an action that returns NULL.
inline auto ReturnNull() -> PolymorphicAction<internal::ReturnNullAction> {
  return MakePolymorphicAction(internal::ReturnNullAction());
}

// Creates an action that returns from a void function.
inline auto Return() -> PolymorphicAction<internal::ReturnVoidAction> {
  return MakePolymorphicAction(internal::ReturnVoidAction());
}

// Creates an action that returns the reference to a variable.
template <typename R>
inline auto ReturnRef(R& x) -> internal::ReturnRefAction<R> {
  // NOLINT
  return internal::ReturnRefAction<R>(x);
}

// Prevent using ReturnRef on reference to temporary.
template <typename R, R* = nullptr>
auto ReturnRef(R&&) -> internal::ReturnRefAction<R> = delete;

// Creates an action that returns the reference to a copy of the
// argument.  The copy is created when the action is constructed and
// lives as long as the action.
template <typename R>
inline auto ReturnRefOfCopy(const R& x) -> internal::ReturnRefOfCopyAction<R> {
  return internal::ReturnRefOfCopyAction<R>(x);
}

// Modifies the parent action (a Return() action) to perform a move of the
// argument instead of a copy.
// Return(ByMove()) actions can only be executed once and will assert this
// invariant.
template <typename R>
auto ByMove(R x) -> internal::ByMoveWrapper<R> {
  return internal::ByMoveWrapper<R>(std::move(x));
}

// Creates an action that returns an element of `vals`. Calling this action will
// repeatedly return the next value from `vals` until it reaches the end and
// will restart from the beginning.
template <typename T>
auto ReturnRoundRobin(
    std::vector<T> vals) -> internal::ReturnRoundRobinAction<T> {
  return internal::ReturnRoundRobinAction<T>(std::move(vals));
}

// Creates an action that returns an element of `vals`. Calling this action will
// repeatedly return the next value from `vals` until it reaches the end and
// will restart from the beginning.
template <typename T>
auto ReturnRoundRobin(
    std::initializer_list<T> vals) -> internal::ReturnRoundRobinAction<T> {
  return internal::ReturnRoundRobinAction<T>(std::vector<T>(vals));
}

// Creates an action that does the default action for the give mock function.
inline auto DoDefault() -> internal::DoDefaultAction {
  return internal::DoDefaultAction();
}

// Creates an action that sets the variable pointed by the N-th
// (0-based) function argument to 'value'.
template <size_t N, typename T>
auto SetArgPointee(T value) -> internal::SetArgumentPointeeAction<N, T> {
  return {std::move(value)};
}

// The following version is DEPRECATED.
template <size_t N, typename T>
auto SetArgumentPointee(T value) -> internal::SetArgumentPointeeAction<N, T> {
  return {std::move(value)};
}

// Creates an action that sets a pointer referent to a given value.
template <typename T1, typename T2>
auto Assign(T1* ptr,
            T2 val) -> PolymorphicAction<internal::AssignAction<T1, T2>> {
  return MakePolymorphicAction(internal::AssignAction<T1, T2>(ptr, val));
}

#if !GTEST_OS_WINDOWS_MOBILE

// Creates an action that sets errno and returns the appropriate error.
template <typename T>
auto SetErrnoAndReturn(int errval,
                       T result) -> PolymorphicAction<
  internal::SetErrnoAndReturnAction<T>> {
  return MakePolymorphicAction(
      internal::SetErrnoAndReturnAction<T>(errval, result));
}

#endif  // !GTEST_OS_WINDOWS_MOBILE

// Various overloads for Invoke().

// Legacy function.
// Actions can now be implicitly constructed from callables. No need to create
// wrapper objects.
// This function exists for backwards compatibility.
template <typename FunctionImpl>
auto Invoke(
    FunctionImpl&& function_impl) -> typename std::decay<FunctionImpl>::type {
  return std::forward<FunctionImpl>(function_impl);
}

// Creates an action that invokes the given method on the given object
// with the mock function's arguments.
template <class Class, typename MethodPtr>
auto Invoke(Class* obj_ptr,
            MethodPtr method_ptr) -> internal::InvokeMethodAction<
  Class, MethodPtr> {
  return {obj_ptr, method_ptr};
}

// Creates an action that invokes 'function_impl' with no argument.
template <typename FunctionImpl>
auto InvokeWithoutArgs(
    FunctionImpl function_impl) -> internal::InvokeWithoutArgsAction<typename
  std::decay<FunctionImpl>::type> {
  return {std::move(function_impl)};
}

// Creates an action that invokes the given method on the given object
// with no argument.
template <class Class, typename MethodPtr>
auto InvokeWithoutArgs(
    Class* obj_ptr,
    MethodPtr method_ptr) -> internal::InvokeMethodWithoutArgsAction<
  Class, MethodPtr> {
  return {obj_ptr, method_ptr};
}

// Creates an action that performs an_action and throws away its
// result.  In other words, it changes the return type of an_action to
// void.  an_action MUST NOT return void, or the code won't compile.
template <typename A>
inline auto
IgnoreResult(const A& an_action) -> internal::IgnoreResultAction<A> {
  return internal::IgnoreResultAction<A>(an_action);
}

// Creates a reference wrapper for the given L-value.  If necessary,
// you can explicitly specify the type of the reference.  For example,
// suppose 'derived' is an object of type Derived, ByRef(derived)
// would wrap a Derived&.  If you want to wrap a const Base& instead,
// where Base is a base class of Derived, just write:
//
//   ByRef<const Base>(derived)
//
// N.B. ByRef is redundant with std::ref, std::cref and std::reference_wrapper.
// However, it may still be used for consistency with ByMove().
template <typename T>
inline auto ByRef(T& l_value) -> std::reference_wrapper<T> {
  // NOLINT
  return std::reference_wrapper<T>(l_value);
}

// The ReturnNew<T>(a1, a2, ..., a_k) action returns a pointer to a new
// instance of type T, constructed on the heap with constructor arguments
// a1, a2, ..., and a_k. The caller assumes ownership of the returned value.
template <typename T, typename... Params>
auto ReturnNew(
    Params&&...params) -> internal::ReturnNewAction<
  T, typename std::decay<Params>::type...> {
  return {std::forward_as_tuple(std::forward<Params>(params)...)};
}

// Action ReturnArg<k>() returns the k-th argument of the mock function.
template <size_t k>
auto ReturnArg() -> internal::ReturnArgAction<k> {
  return { };
}

// Action SaveArg<k>(pointer) saves the k-th (0-based) argument of the
// mock function to *pointer.
template <size_t k, typename Ptr>
auto SaveArg(Ptr pointer) -> internal::SaveArgAction<k, Ptr> {
  return {pointer};
}

// Action SaveArgPointee<k>(pointer) saves the value pointed to
// by the k-th (0-based) argument of the mock function to *pointer.
template <size_t k, typename Ptr>
auto SaveArgPointee(Ptr pointer) -> internal::SaveArgPointeeAction<k, Ptr> {
  return {pointer};
}

// Action SetArgReferee<k>(value) assigns 'value' to the variable
// referenced by the k-th (0-based) argument of the mock function.
template <size_t k, typename T>
auto SetArgReferee(
    T&& value) -> internal::SetArgRefereeAction<
  k, typename std::decay<T>::type> {
  return {std::forward<T>(value)};
}

// Action SetArrayArgument<k>(first, last) copies the elements in
// source range [first, last) to the array pointed to by the k-th
// (0-based) argument, which can be either a pointer or an
// iterator. The action does not take ownership of the elements in the
// source range.
template <size_t k, typename I1, typename I2>
auto SetArrayArgument(I1 first,
                      I2 last) -> internal::SetArrayArgumentAction<k, I1, I2> {
  return {first, last};
}

// Action DeleteArg<k>() deletes the k-th (0-based) argument of the mock
// function.
template <size_t k>
auto DeleteArg() -> internal::DeleteArgAction<k> {
  return { };
}

// This action returns the value pointed to by 'pointer'.
template <typename Ptr>
auto ReturnPointee(Ptr pointer) -> internal::ReturnPointeeAction<Ptr> {
  return {pointer};
}

// Action Throw(exception) can be used in a mock function of any type
// to throw the given exception.  Any copyable value can be thrown.
#if GTEST_HAS_EXCEPTIONS
template <typename T>
auto Throw(
    T&& exception) -> internal::ThrowAction<typename std::decay<T>::type> {
  return {std::forward<T>(exception)};
}
#endif  // GTEST_HAS_EXCEPTIONS

namespace internal {

// A macro from the ACTION* family (defined later in gmock-generated-actions.h)
// defines an action that can be used in a mock function.  Typically,
// these actions only care about a subset of the arguments of the mock
// function.  For example, if such an action only uses the second
// argument, it can be used in any mock function that takes >= 2
// arguments where the type of the second argument is compatible.
//
// Therefore, the action implementation must be prepared to take more
// arguments than it needs.  The ExcessiveArg type is used to
// represent those excessive arguments.  In order to keep the compiler
// error messages tractable, we define it in the testing namespace
// instead of testing::internal.  However, this is an INTERNAL TYPE
// and subject to change without notice, so a user MUST NOT USE THIS
// TYPE DIRECTLY.
struct ExcessiveArg {};

// Builds an implementation of an Action<> for some particular signature, using
// a class defined by an ACTION* macro.
template <typename F, typename Impl>
struct ActionImpl;

template <typename Impl>
struct ImplBase {
  struct Holder {
    // Allows each copy of the Action<> to get to the Impl.
    explicit operator const Impl&() const { return *ptr; }
    std::shared_ptr<Impl> ptr;
  };

  using type = typename std::conditional<std::is_constructible<Impl>::value,
                                         Impl, Holder>::type;
};

template <typename R, typename... Args, typename Impl>
struct ActionImpl<R(Args ...), Impl> : ImplBase<Impl>::type {
  using Base = typename ImplBase<Impl>::type;
  using function_type = R(Args ...);
  using args_type = std::tuple<Args...>;

  ActionImpl() = default; // Only defined if appropriate for Base.
  explicit ActionImpl(std::shared_ptr<Impl> impl)
    : Base {std::move(impl)} { }

  auto operator()(Args&&...arg) const -> R {
    static constexpr size_t kMaxArgs =
        sizeof...(Args) <= 10 ? sizeof...(Args) : 10;
    return Apply(MakeIndexSequence<kMaxArgs> { },
                 MakeIndexSequence<10 - kMaxArgs> { },
                 args_type {std::forward<Args>(arg)...});
  }

  template <std::size_t... arg_id, std::size_t... excess_id>
  auto Apply(IndexSequence<arg_id...>, IndexSequence<excess_id...>,
             const args_type& args) const -> R {
    // Impl need not be specific to the signature of action being implemented;
    // only the implementing function body needs to have all of the specific
    // types instantiated.  Up to 10 of the args that are provided by the
    // args_type get passed, followed by a dummy of unspecified type for the
    // remainder up to 10 explicit args.
    static constexpr ExcessiveArg kExcessArg { };
    return static_cast<const Impl&>(*this).template gmock_PerformImpl<
      /*function_type=*/function_type, /*return_type=*/R,
                        /*args_type=*/args_type,
                        /*argN_type=*/typename std::tuple_element<
                          arg_id, args_type>::type...>(
        /*args=*/args, std::get<arg_id>(args)...,
                 (void)excess_id, kExcessArg...);
  }
};

// Stores a default-constructed Impl as part of the Action<>'s
// std::function<>. The Impl should be trivial to copy.
template <typename F, typename Impl>
auto MakeAction() -> Action<F> {
  return testing::Action<F>(ActionImpl<F, Impl>());
}

// Stores just the one given instance of Impl.
template <typename F, typename Impl>
auto MakeAction(std::shared_ptr<Impl> impl) -> Action<F> {
  return testing::Action<F>(ActionImpl<F, Impl>(std::move(impl)));
}

#define GMOCK_INTERNAL_ARG_UNUSED(i, data, el) \
  , const arg##i##_type& arg##i GTEST_ATTRIBUTE_UNUSED_
#define GMOCK_ACTION_ARG_TYPES_AND_NAMES_UNUSED_           \
  const args_type& args GTEST_ATTRIBUTE_UNUSED_ GMOCK_PP_REPEAT( \
      GMOCK_INTERNAL_ARG_UNUSED, , 10)

#define GMOCK_INTERNAL_ARG(i, data, el) , const arg##i##_type& arg##i
#define GMOCK_ACTION_ARG_TYPES_AND_NAMES_ \
  const args_type& args GMOCK_PP_REPEAT(GMOCK_INTERNAL_ARG, , 10)

#define GMOCK_INTERNAL_TEMPLATE_ARG(i, data, el) , typename arg##i##_type
#define GMOCK_ACTION_TEMPLATE_ARGS_NAMES_ \
  GMOCK_PP_TAIL(GMOCK_PP_REPEAT(GMOCK_INTERNAL_TEMPLATE_ARG, , 10))

#define GMOCK_INTERNAL_TYPENAME_PARAM(i, data, param) , typename param##_type
#define GMOCK_ACTION_TYPENAME_PARAMS_(params) \
  GMOCK_PP_TAIL(GMOCK_PP_FOR_EACH(GMOCK_INTERNAL_TYPENAME_PARAM, , params))

#define GMOCK_INTERNAL_TYPE_PARAM(i, data, param) , param##_type
#define GMOCK_ACTION_TYPE_PARAMS_(params) \
  GMOCK_PP_TAIL(GMOCK_PP_FOR_EACH(GMOCK_INTERNAL_TYPE_PARAM, , params))

#define GMOCK_INTERNAL_TYPE_GVALUE_PARAM(i, data, param) \
  , param##_type gmock_p##i
#define GMOCK_ACTION_TYPE_GVALUE_PARAMS_(params) \
  GMOCK_PP_TAIL(GMOCK_PP_FOR_EACH(GMOCK_INTERNAL_TYPE_GVALUE_PARAM, , params))

#define GMOCK_INTERNAL_GVALUE_PARAM(i, data, param) \
  , std::forward<param##_type>(gmock_p##i)
#define GMOCK_ACTION_GVALUE_PARAMS_(params) \
  GMOCK_PP_TAIL(GMOCK_PP_FOR_EACH(GMOCK_INTERNAL_GVALUE_PARAM, , params))

#define GMOCK_INTERNAL_INIT_PARAM(i, data, param) \
  , param(::std::forward<param##_type>(gmock_p##i))
#define GMOCK_ACTION_INIT_PARAMS_(params) \
  GMOCK_PP_TAIL(GMOCK_PP_FOR_EACH(GMOCK_INTERNAL_INIT_PARAM, , params))

#define GMOCK_INTERNAL_FIELD_PARAM(i, data, param) param##_type param;
#define GMOCK_ACTION_FIELD_PARAMS_(params) \
  GMOCK_PP_FOR_EACH(GMOCK_INTERNAL_FIELD_PARAM, , params)

#define GMOCK_INTERNAL_ACTION(name, full_name, params)                        \
  template <GMOCK_ACTION_TYPENAME_PARAMS_(params)>                            \
  class full_name {                                                           \
   public:                                                                    \
    explicit full_name(GMOCK_ACTION_TYPE_GVALUE_PARAMS_(params))              \
        : impl_(std::make_shared<gmock_Impl>(                                 \
                GMOCK_ACTION_GVALUE_PARAMS_(params))) { }                     \
    full_name(const full_name&) = default;                                    \
    full_name(full_name&&) noexcept = default;                                \
    template <typename F>                                                     \
    operator ::testing::Action<F>() const {                                   \
      return ::testing::internal::MakeAction<F>(impl_);                       \
    }                                                                         \
   private:                                                                   \
    class gmock_Impl {                                                        \
     public:                                                                  \
      explicit gmock_Impl(GMOCK_ACTION_TYPE_GVALUE_PARAMS_(params))           \
          : GMOCK_ACTION_INIT_PARAMS_(params) {}                              \
      template <typename function_type, typename return_type,                 \
                typename args_type, GMOCK_ACTION_TEMPLATE_ARGS_NAMES_>        \
      return_type gmock_PerformImpl(GMOCK_ACTION_ARG_TYPES_AND_NAMES_) const; \
      GMOCK_ACTION_FIELD_PARAMS_(params)                                      \
    };                                                                        \
    std::shared_ptr<const gmock_Impl> impl_;                                  \
  };                                                                          \
  template <GMOCK_ACTION_TYPENAME_PARAMS_(params)>                            \
  inline full_name<GMOCK_ACTION_TYPE_PARAMS_(params)> name(                   \
      GMOCK_ACTION_TYPE_GVALUE_PARAMS_(params)) {                             \
    return full_name<GMOCK_ACTION_TYPE_PARAMS_(params)>(                      \
        GMOCK_ACTION_GVALUE_PARAMS_(params));                                 \
  }                                                                           \
  template <GMOCK_ACTION_TYPENAME_PARAMS_(params)>                            \
  template <typename function_type, typename return_type, typename args_type, \
            GMOCK_ACTION_TEMPLATE_ARGS_NAMES_>                                \
  return_type full_name<GMOCK_ACTION_TYPE_PARAMS_(params)>::gmock_Impl::      \
  gmock_PerformImpl(GMOCK_ACTION_ARG_TYPES_AND_NAMES_UNUSED_) const

} // namespace internal

// Similar to GMOCK_INTERNAL_ACTION, but no bound parameters are stored.
#define ACTION(name)                                                          \
  class name##Action {                                                        \
   public:                                                                    \
   explicit name##Action() noexcept {}                                        \
   name##Action(const name##Action&) noexcept {}                              \
    template <typename F>                                                     \
    operator ::testing::Action<F>() const {                                   \
      return ::testing::internal::MakeAction<F, gmock_Impl>();                \
    }                                                                         \
   private:                                                                   \
    class gmock_Impl {                                                        \
     public:                                                                  \
      template <typename function_type, typename return_type,                 \
                typename args_type, GMOCK_ACTION_TEMPLATE_ARGS_NAMES_>        \
      return_type gmock_PerformImpl(GMOCK_ACTION_ARG_TYPES_AND_NAMES_) const; \
    };                                                                        \
  };                                                                          \
  inline name##Action name() GTEST_MUST_USE_RESULT_;                          \
  inline name##Action name() { return name##Action(); }                       \
  template <typename function_type, typename return_type, typename args_type, \
            GMOCK_ACTION_TEMPLATE_ARGS_NAMES_>                                \
  return_type name##Action::gmock_Impl::gmock_PerformImpl(                    \
      GMOCK_ACTION_ARG_TYPES_AND_NAMES_UNUSED_) const

#define ACTION_P(name, ...) \
  GMOCK_INTERNAL_ACTION(name, name##ActionP, (__VA_ARGS__))

#define ACTION_P2(name, ...) \
  GMOCK_INTERNAL_ACTION(name, name##ActionP2, (__VA_ARGS__))

#define ACTION_P3(name, ...) \
  GMOCK_INTERNAL_ACTION(name, name##ActionP3, (__VA_ARGS__))

#define ACTION_P4(name, ...) \
  GMOCK_INTERNAL_ACTION(name, name##ActionP4, (__VA_ARGS__))

#define ACTION_P5(name, ...) \
  GMOCK_INTERNAL_ACTION(name, name##ActionP5, (__VA_ARGS__))

#define ACTION_P6(name, ...) \
  GMOCK_INTERNAL_ACTION(name, name##ActionP6, (__VA_ARGS__))

#define ACTION_P7(name, ...) \
  GMOCK_INTERNAL_ACTION(name, name##ActionP7, (__VA_ARGS__))

#define ACTION_P8(name, ...) \
  GMOCK_INTERNAL_ACTION(name, name##ActionP8, (__VA_ARGS__))

#define ACTION_P9(name, ...) \
  GMOCK_INTERNAL_ACTION(name, name##ActionP9, (__VA_ARGS__))

#define ACTION_P10(name, ...) \
  GMOCK_INTERNAL_ACTION(name, name##ActionP10, (__VA_ARGS__))

} // namespace testing

#ifdef _MSC_VER
# pragma warning(pop)
#endif

#endif  // GOOGLEMOCK_INCLUDE_GMOCK_GMOCK_ACTIONS_H_
