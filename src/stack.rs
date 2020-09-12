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

use std::{fmt, ops};

use super::record::RecordUnion;

#[repr(usize)]
#[derive(Copy, Clone, Eq, PartialEq, Debug)]
pub enum CommonStackSize {
    Small8KB = 1024,
    Small32KB = 1024 * 32,
    Small64KB = 1024 * 64,
    Medium128KB = 1024 * 128,
    Medium256KB = 1024 * 256,
    Medium512KB = 1024 * 512,
    Large1MB = 1024 * 1024,
    Large4MB = 1024 * 1024 * 4,
    Large8MB = 1024 * 1024 * 8,
}

pub struct Stack(Box<[RecordUnion]>, usize);

impl Stack {
    #[inline]
    pub fn from_buffer(buf: Box<[RecordUnion]>) -> Self {
        assert_ne!(buf.len(), 0);
        Self(buf, 0)
    }

    #[inline]
    pub fn from_vector(vec: Vec<RecordUnion>) -> Self {
        assert_ne!(vec.len(), 0);
        Self(vec.into_boxed_slice(), 0)
    }

    #[inline]
    pub fn with_length(len: usize) -> Self {
        assert_ne!(len, 0);
        Self::from_vector(vec![RecordUnion::ZERO; len])
    }

    #[inline]
    pub fn with_byte_size(size: usize) -> Self {
        assert_ne!(size, 0);
        assert_eq!(size % std::mem::size_of::<RecordUnion>(), 0);
        Self::from_vector(vec![RecordUnion::ZERO; size / std::mem::size_of::<RecordUnion>()])
    }

    #[inline]
    pub fn with_common_size(size: CommonStackSize) -> Self {
        Self::with_byte_size(size as usize)
    }
}

impl Stack {
    #[inline]
    pub fn length(&self) -> usize {
        self.0.len()
    }

    #[inline]
    pub fn is_empty(&self) -> bool {
        self.0.is_empty()
    }

    #[inline]
    pub fn size(&self) -> usize {
        self.0.len() * std::mem::size_of::<RecordUnion>()
    }

    #[inline]
    pub fn buffer(&self) -> &[RecordUnion] {
        &self.0
    }

    #[inline]
    pub fn stack_pointer(&self) -> usize {
        self.1
    }

    #[inline]
    pub fn push(&mut self, rec: RecordUnion) {
        self.1 += 1;
        self.0[self.1] = rec;
    }

    #[inline]
    pub fn push_all(&mut self) {
        self.1 = self.0.len() - 1;
    }

    #[inline]
    pub fn pop(&mut self) {
        self.1 -= 1;
    }

    #[inline]
    pub fn pop_all(&mut self) {
        self.1 = 0
    }

    #[inline]
    pub fn pop_multi(&mut self, count: usize) {
        debug_assert_ne!(count, 0);
        self.1 -= count;
    }

    #[inline]
    pub fn pop_ret(&mut self) -> RecordUnion {
        let val = self.0[self.1];
        self.1 -= 1;
        val
    }

    #[inline]
    pub fn peek(&self) -> RecordUnion {
        self.0[self.1]
    }

    #[inline]
    pub fn peek_set(&mut self, rec: RecordUnion) {
        self.0[self.1] = rec
    }

    #[inline]
    pub fn peek_previous(&self) -> RecordUnion {
        self.0[self.1 - 1]
    }

    #[inline]
    pub fn peek_previous_set(&mut self, rec: RecordUnion) {
        self.0[self.1 - 1] = rec
    }

    #[inline]
    pub fn poke(&self, idx: usize) -> RecordUnion {
        debug_assert!(idx <= self.1);
        self.0[idx]
    }

    #[inline]
    pub fn poke_set(&mut self, idx: usize, rec: RecordUnion) {
        debug_assert!(idx <= self.1);
        self.0[idx] = rec
    }

    #[inline]
    pub fn is_overflowed(&self) -> bool {
        self.1 >= self.0.len()
    }
}

impl ops::Index<usize> for Stack {
    type Output = RecordUnion;

    fn index(&self, idx: usize) -> &Self::Output {
        &self.0[idx]
    }
}

impl ops::IndexMut<usize> for Stack {
    fn index_mut(&mut self, idx: usize) -> &mut Self::Output {
        &mut self.0[idx]
    }
}

impl fmt::Debug for Stack {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        for (i, rec) in self.0.iter().enumerate() {
            writeln!(f, "{:#010x} {:?}", i, rec)?
        }
        Ok(())
    }
}