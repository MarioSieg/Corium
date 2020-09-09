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

use std::{default, fmt};

/// Represents a 32-bit multitype record union.
/// The union can basically used as a f32, i32 and u32.
/// The native f32 maps to the runtime 'float' type.
/// The native i32 maps to the runtime 'int' type.
/// The native u32 maps to a instruction.
/// Warning! This is not a tagged/discriminated union!
/// That means that you can write a f32 into it,
/// even it was used as i32.
/// If we would have used an enum 
/// (which is like tagged union in Rust)
/// we would have additional 8 bits (1 bytes) for the discriminator.
/// This might not be a big value but we will have many many of these
/// RecordUnion instances (basically every value is represented by them)
/// to it definetly will be a cost because:
/// 1. The data is larger, we will have more memory pressure.
/// 2. Due to packing the struct will probably not become 32-bits + 8-bits, but instead 64!
/// 3. Because of the double of the size, only the half will fit into the caches.
/// 4. We would need to check the types for each operation which can be very slow.
/// 5. If we only would use the types for static bytecode analysis, we would waste memory at runtime!
/// 6. When we validate bytecode, we add a type lookup table, which will be used by the interpreter to verify the bytecode.
#[derive(Copy, Clone, PartialEq)]
pub struct RecordUnion(u32);

/// The descriminator rperesents the current field set.
/// This is for the 'BytecodeStream# which contains this
/// descriminator as meta data to do a proper bytecode validation.
/// At runtime this is removed to save memory and execution time.
/// See the docs of 'RecordUnion'
#[repr(u8)]
#[derive(Debug, Copy, Clone, Eq, PartialEq)]
pub enum RecordUnionDiscriminator {

    // It is an operation.
    Opcode,
    
    /// It is an integer.
    Int,

    /// It is a float.
    Float,
}

impl RecordUnion {

    /// Create with zero for all types.
    #[inline]
    pub fn new() -> Self {
        Self(0)
    }

    /// Create from an integer.
    #[inline]
    pub fn from_int(val: i32) -> Self {
        Self(val as _)
    }

    /// Create from a float.
    #[inline]
    pub fn from_float(val: f32) -> Self {
        Self(val.to_bits())
    }

    /// Create from an opcode.
    #[inline]
    pub fn from_opcode(val: u32) -> Self {
        Self(val)
    }
}

impl RecordUnion {
    /// Returns the value interpreted as integer.
    /// Warning!
    /// This might return an arbitrary value,
    /// if the value was set with an other type.
    #[inline]
    pub fn int(&self) -> i32 {
        self.0 as _
    }

    /// Sets the value interpreted as integer.
    /// Warning!
    /// This might override a previous set value of some other type.
    #[inline]
    pub fn set_int(&mut self, val: i32) {
        self.0 = val as _
    }

    /// Returns the value interpreted as float.
    /// Warning!
    /// This might return an arbitrary value,
    /// if the value was set with an other type.
    #[inline]
    pub fn float(&self) -> f32 {
        f32::from_bits(self.0)
    }

    /// Sets the value interpreted as float.
    /// Warning!
    /// This might override a previous set value of some other type.
    #[inline]
    pub fn set_float(&mut self, val: f32) {
        self.0 = val.to_bits()
    }

    /// Returns the value interpreted as opcode.
    /// Warning!
    /// This might return an arbitrary value,
    /// if the value was set with an other type.
    #[inline]
    pub fn opcode(&self) -> u32 {
        self.0
    }

    /// Returns the 4 bytes representing the data.
    /// The data is represented as little endian byte order.
    #[inline]
    pub fn to_byte_array(&self) -> [u8; 4] {
        /*
        [
            ((self.0 >> 24) & 0xff) as _,
            ((self.0 >> 16) & 0xff) as _,
            ((self.0 >> 8) & 0xff) as _,
            (self.0 & 0xff) as _,
        ]
        */

        self.0.to_le_bytes()
    }
}

impl default::Default for RecordUnion {
    fn default() -> Self {
        Self::new()
    }
}

impl fmt::Display for RecordUnion {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "op: {} int: {} flt: {}", self.opcode(), self.int(), self.float())
    }
}

impl fmt::Debug for RecordUnion {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        let by = self.to_byte_array();
        write!(f, "{:02x} {:02x} {:02x} {:02x} | {} {} {}", 
            by[0], 
            by[1], 
            by[2],
            by[3],
            self.opcode(),
            self.int(),
            self.float()
        )
    }
}