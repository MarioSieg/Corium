// MIT License
//
// Copyright (c) 2020 Mario Sieg
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

/// Represents the type of a argument.
#[derive(Copy, Clone, Eq, PartialEq, Debug)]
pub enum ArgumentValueType {

    /// This argument is an integer.
    Int,

    /// This argument is a float.
    Float,

    /// This argument can be an int, float or any other value type.
    AnyValueType
}

/// Represents the type of a argument.
#[derive(Copy, Clone, PartialEq, Debug)]
pub enum ArgumentDefaultValue {

    /// This contains the default value for an integer.
    Int(i32),

    /// This contains the default value for a float.
    Float(f32),
}

/// Sets if an argument is required or not.
#[derive(Copy, Clone, PartialEq, Debug)]
pub enum ArgumentPolicy {

    /// This argument is required!
    Required,

    /// This argument is optional, so we provide a default value if the user does not.
    Optional(ArgumentDefaultValue)
}

/// The type of an argument.
#[derive(Copy, Clone, Eq, PartialEq, Debug)]
pub enum ArgumentVisibilityType {

    /// This argument is explicitly passed as immediate value.
    /// For example:
    /// "push 0" <<- explicit constant immediate value pass
    Explicit,

    /// This argument is implicitely passed as value somewhere in the stack memory.
    /// For example:
    /// "sub %i" <<- Both values are implit values on the stack
    /// and they have to be both floats.
    /// It also contains the stack offset index.
    Implicit(isize),
}

/// Contains meta data about an instruction argument.
#[derive(Copy, Clone, PartialEq, Debug)]
pub struct ArgumentMeta {

    /// The visibility of this argument.
    pub visibility_type: ArgumentVisibilityType,

    /// The value of type of this argument.
    pub value_type: ArgumentValueType,

    /// Sets if an argument is required or optional.
    pub policy: ArgumentPolicy,

    /// A short but precise info and warning if there are any.
    pub description: &'static str,
}