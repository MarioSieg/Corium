// MIT License
//
// Copyright (c) 2020 Mario Sieg (KerboGames)
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

use crate::stack::Stack;

use super::asm::*;
use super::chunk::*;
use super::record::*;

/// Executes the bytecode.
/// Returns the interrupt id (exitcode) and the number of cycles.
pub fn execute(mut code: BytecodeChunk, mut stack: Stack) -> (i32, u64) {
    let mut cycles: u64 = 0; // Cycles counter.
    let mut interrupt: i32 = 0; // Interrupt id.

    loop {
        match code.fetch().u32() {
            ops::INTERRUPT => {
                interrupt = code.fetch().i32();
                if interrupt <= 0 {
                    break;
                } else {
                    // Trigger exception
                }
            }

            ops::PUSH => {
                stack.push(code.fetch());
            }

            ops::POP => {
                stack.pop_multi(code.fetch().u32() as _);
            }

            ops::MOVE => {
                stack.poke_set(code.fetch().u32() as _, code.fetch());
            }

            ops::COPY => {
                stack.poke_set(code.fetch().u32() as _, stack.poke(code.fetch().u32() as _));
            }

            ops::DUPLICATE => {
                stack.push(stack.peek());
            }

            ops::DUPLICATE_X2 => {
                stack.push(stack.peek());
                stack.push(stack.peek());
            }

            ops::I32_ADD => {
                stack.peek_previous_set(RecordUnion::from_i32(stack.peek_previous().i32() + stack.peek().i32()));
                stack.pop();
            }

            ops::I32_SUB => {
                stack.peek_previous_set(RecordUnion::from_i32(stack.peek_previous().i32() - stack.peek().i32()));
                stack.pop();
            }

            ops::I32_MUL => {
                stack.peek_previous_set(RecordUnion::from_i32(stack.peek_previous().i32() * stack.peek().i32()));
                stack.pop();
            }

            ops::I32_DIV => {
                stack.peek_previous_set(RecordUnion::from_i32(stack.peek_previous().i32() / stack.peek().i32()));
                stack.pop();
            }

            ops::I32_MOD => {
                stack.peek_previous_set(RecordUnion::from_i32(stack.peek_previous().i32() % stack.peek().i32()));
                stack.pop();
            }

            ops::I32_AND => {
                stack.peek_previous_set(RecordUnion::from_i32(stack.peek_previous().i32() & stack.peek().i32()));
                stack.pop();
            }

            ops::I32_OR => {
                stack.peek_previous_set(RecordUnion::from_i32(stack.peek_previous().i32() | stack.peek().i32()));
                stack.pop();
            }

            ops::I32_XOR => {
                stack.peek_previous_set(RecordUnion::from_i32(stack.peek_previous().i32() ^ stack.peek().i32()));
                stack.pop();
            }

            ops::I32_SAL => {
                stack.peek_previous_set(RecordUnion::from_i32(stack.peek_previous().i32() << stack.peek().i32()));
                stack.pop();
            }

            ops::I32_SAR => {
                stack.peek_previous_set(RecordUnion::from_i32(stack.peek_previous().i32() >> stack.peek().i32()));
                stack.pop();
            }

            ops::I32_COM => {
                stack.peek_previous_set(RecordUnion::from_i32(!stack.peek_previous().i32()));
                stack.pop();
            }

            ops::F32_ADD => {
                stack.peek_previous_set(RecordUnion::from_f32(stack.peek_previous().f32() + stack.peek().f32()));
                stack.pop();
            }

            ops::F32_SUB => {
                stack.peek_previous_set(RecordUnion::from_f32(stack.peek_previous().f32() - stack.peek().f32()));
                stack.pop();
            }

            ops::F32_MUL => {
                stack.peek_previous_set(RecordUnion::from_f32(stack.peek_previous().f32() * stack.peek().f32()));
                stack.pop();
            }

            ops::F32_DIV => {
                stack.peek_previous_set(RecordUnion::from_f32(stack.peek_previous().f32() / stack.peek().f32()));
                stack.pop();
            }

            ops::F32_MOD => {
                stack.peek_previous_set(RecordUnion::from_f32(stack.peek_previous().f32() % stack.peek().f32()));
                stack.pop();
            }

            _ => (),
        }

        if code.is_done() {
            break;
        }

        cycles += 1;
    }

    print!("{:?}", stack);
    print!("{:?}", code);

    (interrupt, cycles)
}