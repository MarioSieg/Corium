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

use super::asm;
use super::argument::*;

/// The category of an instruction type.
#[derive(Copy, Clone, Eq, PartialEq, Debug)]
pub enum InstructionType {

    /// The instruction is for VM controlling.
    System,

    /// The instruction is for memory controlling.
    Memory,

    /// The instruction is for flow and brach control.
    Control,

    /// The instruction is for arithmetic operations.
    Arithmetic,

    /// This instruction is for logical operations.
    Logical,

    /// This instruction is for bitwise operations.
    Bitwise
}

/// Represents an instruction.
/// Contains metadata for bytecode parsing verification.
pub struct InstructionMeta {

    /// The opcode of this instruction taken from the list above.
    pub opcode: u32,

    /// The bytecoee mnemonic of this instruction.
    pub mnemonic: &'static str,

    /// A short but precise description of what this
    /// instruction does and how it should be used.
    /// If there are any dangers of using this instruction,
    /// also write them down here!
    pub description: &'static str,

    /// Stack pointer offset after execution.
    /// Use isize::MAX to indicate unknown push count!
    /// Use isize::MIN to indicate unknown pop count!
    pub stack_modificator: isize,

    /// Set to true if this instruction jumps or executes any
    /// branches or flow control modifications.
    pub is_modifying_flow_control: bool,

    /// Set to true if this instruction modifies anything on the stack.
    pub is_modifying_stack: bool,

    /// Set to true if this instruction modifies anything on the heap.
    pub is_modifying_heap: bool,

    /// The instruction type category of this instruction.
    pub instruction_type: InstructionType,

    /// Contains meta data about all arguments.
    /// Will be heavily used by the bytecode verifier.
    pub arguments: &'static [ArgumentMeta],
}

impl InstructionMeta {

    /// Contains the metadata of all instructions.
    /// The opcodes can be used to lookup.
    pub const META_TABLE: &'static [InstructionMeta] = &[

        ///////////////////////////////
        InstructionMeta {
            opcode: asm::INTERRUPT,
            mnemonic: "int",
            description: 
            r#" 
                Interrupts execution. 
                If 0 is passed it ends the program, else it triggers 
                the exception with the corresponding id.
            "#,
            stack_modificator: 0,
            is_modifying_flow_control: false,
            is_modifying_stack: false,
            is_modifying_heap: false,
            instruction_type: InstructionType::System,
            arguments: &[
                ArgumentMeta {
                    visibility_type: ArgumentVisibilityType::Explicit,
                    value_type: ArgumentValueType::Int,
                    policy: ArgumentPolicy::Required,
                    description:
                    r#"
                        The interrupt code. If the code is <= 0
                        it will end the program and use it as exit code.
                        Else an exception with the interrupt code will be triggerd.
                        If there is not exception with that interrupt code,
                        and unkown exeption will be raised.
                    "#
                }
            ]
        },

        ///////////////////////////////
        InstructionMeta {
            opcode: asm::PUSH,
            mnemonic: "push",
            description: 
            r#"
                Pushes the argument onto the stack.
                The argument must be value type, no reference!
            "#,
            stack_modificator: 1,
            is_modifying_flow_control: false,
            is_modifying_stack: true,
            is_modifying_heap: false,
            instruction_type: InstructionType::Memory,
            arguments: &[

                ArgumentMeta {
                    visibility_type: ArgumentVisibilityType::Explicit,
                    value_type: ArgumentValueType::AnyValueType,
                    policy: ArgumentPolicy::Optional(ArgumentDefaultValue::Int(0)),
                    description:
                    r#"
                        The value to push onto the stack.
                        Can be any value type, which fits into a stack record.
                    "#
                }
            ]
        },

        ///////////////////////////////
        InstructionMeta {
            opcode: asm::POP,
            mnemonic: "pop",
            description:
            r#"
                Pops 'x' elements from the stack.
                The argument is the number of
                elements to pop.
                Passing zero is not an error but redundant.
            "#,
            stack_modificator: isize::MIN, // We don't know how many values will be popped, as it depends on the args.
            is_modifying_flow_control: false,
            is_modifying_stack: true,
            is_modifying_heap: false,
            instruction_type: InstructionType::Memory,
            arguments: &[

                ArgumentMeta {
                    visibility_type: ArgumentVisibilityType::Implicit(-1),
                    value_type: ArgumentValueType::AnyValueType,
                    policy: ArgumentPolicy::Required,
                    description:
                    r#"
                        The value/s to pop off the stack.
                        This policy applies to all implicit parameters if
                        there are more than one!
                    "#
                },

                ArgumentMeta {
                    visibility_type: ArgumentVisibilityType::Explicit,
                    value_type: ArgumentValueType::Int,
                    policy: ArgumentPolicy::Optional(ArgumentDefaultValue::Int(1)),
                    description:
                    r#"
                        Pops a specific count of values off the stack.
                        If pop is called without any explicit parameter,
                        the default value is 1 so it pops 1 value.
                    "#
                }
            ]
        }
    ];
}