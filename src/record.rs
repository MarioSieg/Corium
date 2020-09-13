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

use std::{default, fmt};

#[derive(Copy, Clone, PartialEq, Hash)]
pub struct RecordUnion(u32);

impl RecordUnion {
    pub const ZERO: Self = Self(0x00000000);
    pub const MIN: Self = Self(0x00000000);
    pub const MAX: Self = Self(0xffffffff);

    #[inline]
    pub fn new() -> Self {
        Self(0)
    }

    #[inline]
    pub fn from_u32(val: u32) -> Self {
        Self(val)
    }

    #[inline]
    pub fn from_i32(val: i32) -> Self {
        Self(val as _)
    }

    #[inline]
    pub fn from_f32(val: f32) -> Self {
        Self(val as _)
    }

    #[inline]
    pub fn from_bytes(bytes: [u8; 4]) -> Self {
        Self(u32::from_le_bytes(bytes))
    }
}

impl RecordUnion {
    #[inline]
    pub fn u32(&self) -> u32 {
        self.0
    }

    #[inline]
    pub fn set_u32(&mut self, val: u32) {
        self.0 = val
    }

    #[inline]
    pub fn i32(&self) -> i32 {
        self.0 as _
    }

    #[inline]
    pub fn set_i32(&mut self, val: i32) {
        self.0 = val as _
    }

    #[inline]
    pub fn f32(&self) -> f32 {
        f32::from_bits(self.0)
    }

    #[inline]
    pub fn set_f32(&mut self, val: f32) {
        self.0 = val.to_bits()
    }

    #[inline]
    pub fn to_bytes(&self) -> [u8; 4] {
        self.0.to_le_bytes()
    }
}

#[derive(Copy, Clone, Eq, PartialEq, Debug, Hash)]
pub enum Discriminator {
    U32,
    I32,
    F32,
}

impl fmt::Display for RecordUnion {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        let b = self.to_bytes();
        write!(f, "{:02X} {:02X} {:02X} {:02X}", b[0], b[1], b[2], b[3])
    }
}

impl fmt::Debug for RecordUnion {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        let b = self.to_bytes();
        write!(
            f,
            "{:02X} {:02X} {:02X} {:02X} -> {} | {} | {}",
            b[0],
            b[1],
            b[2],
            b[3],
            self.u32(),
            self.i32(),
            self.f32()
        )
    }
}

impl default::Default for RecordUnion {
    fn default() -> Self {
        Self::ZERO
    }
}
