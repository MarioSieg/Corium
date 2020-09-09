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

use super::record::{RecordUnion, RecordUnionDiscriminator};
use super::validator;
use std::default;

/// A helper to build bytecode. Contains a stream with the 
/// data (RecordUnion) and their corresponding discriminators
/// for validation (RecordUnionDiscriminator).
/// It allows appending opcodes and parameters.
/// You can call validate() to validate the bytecode
/// and then to_bytecode_chunk() to convert it to a bytecode chunk,
/// which can be injected into the VM.
pub struct BytecodeStream(Vec<(RecordUnion, RecordUnionDiscriminator)>);

// TODO write bytecode class
// and to_bytecode_chunk()
impl BytecodeStream {

    /// Creates a new, empty bytecode stream.
    #[inline]
    pub fn new() -> Self {
        Self(Vec::new())
    }
    
    /// Creates a new, empty bytecode stream with given capacity.
    /// Use this if you roughly know how big your bytecode will be.
    /// This only changes the memory capacity and not the number of entries!
    #[inline]
    pub fn with_capacity(capacity: usize) -> Self {
        Self(Vec::with_capacity(capacity))
    }
}

impl BytecodeStream {
    /// Pushes an int parameter.
    #[inline]
    pub fn with_int(&mut self, x: i32) -> &mut Self {
        self.0.push((RecordUnion::from_int(x), RecordUnionDiscriminator::Int));
        self
    }

    /// Pushes a float parameter.
    #[inline]
    pub fn with_float(&mut self, x: f32) -> &mut Self  {
        self.0.push((RecordUnion::from_float(x), RecordUnionDiscriminator::Float));
        self
    }

    /// Pushes an opcode parameter.
    #[inline]
    pub fn new_op(&mut self, x: u32) -> &mut Self  {
        self.0.push((RecordUnion::from_opcode(x), RecordUnionDiscriminator::Opcode));
        self
    }

    /// Returns the internal buffer.
    #[inline]
    pub fn buffer(&self) -> &Vec<(RecordUnion, RecordUnionDiscriminator)> {
        &self.0
    }

    /// Validates the input bytecode stream.
    /// Basically it iterates over the bytecode and checks
    /// if the paramters and calls are correct.
    /// See 'validator::validate_bytecode' for more info.
    #[inline]
    pub fn validate(&self) -> Result<(), Vec<&'static str>> {
        validator::validate_bytecode(self)
    }
}

impl default::Default for BytecodeStream {
    fn default() -> Self {
        Self::new()
    }
}