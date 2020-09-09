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

use super::record::RecordUnionDiscriminator;
use super::stream::BytecodeStream;

/// Validates the input bytecode stream.
/// Basically it iterates over the bytecode and checks
/// if the paramters and calls are correct.
/// For parameters it checks the type and values against the
/// metadata in 'Instruction::META_TABLE'!
/// It does some superficial memory and call checks.
pub fn validate_bytecode(stream: &BytecodeStream) -> Result<(), Vec<&'static str>> {

    // List of error messages.
    let errors: Vec<&'static str> = Vec::new();

    for rec in stream.buffer() {
        match rec.1 {
            RecordUnionDiscriminator::Opcode => {
                
            }
            RecordUnionDiscriminator::Int => {

            },
            RecordUnionDiscriminator::Float => {

            },
        }
    }

    // If we have no errors, exit!
    // Instead of quitting on the first error
    // we check all. Then we do not have to recompile every
    // time after fixing one.
    if errors.is_empty() {
        Result::Ok(())
    }
    else {
        Result::Err(errors)
    }
}