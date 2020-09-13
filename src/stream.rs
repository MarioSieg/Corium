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

use std::ops;

use super::asm;
use super::chunk::*;
use super::record::*;

/// A bytecode stream is used to dynamically build bytecode.
pub struct BytecodeStream(Vec<(RecordUnion, Discriminator)>);

impl BytecodeStream {
    #[inline]
    pub fn new() -> Self {
        Self(Vec::new())
    }

    #[inline]
    pub fn with_vec(vec: Vec<(RecordUnion, Discriminator)>) -> Self {
        Self(vec)
    }

    #[inline]
    pub fn with_capacity(capacity: usize) -> Self {
        Self(Vec::with_capacity(capacity))
    }
}

impl BytecodeStream {
    #[inline]
    pub fn u32(&mut self, val: u32) -> &mut Self {
        self.0.push((RecordUnion::from_u32(val), Discriminator::U32));
        self
    }

    #[inline]
    pub fn i32(&mut self, val: i32) -> &mut Self {
        self.0.push((RecordUnion::from_i32(val), Discriminator::I32));
        self
    }

    #[inline]
    pub fn f32(&mut self, val: f32) -> &mut Self {
        self.0.push((RecordUnion::from_f32(val), Discriminator::F32));
        self
    }

    #[inline]
    pub fn finish(&mut self) -> &mut Self {
        self.u32(asm::ops::INTERRUPT).i32(0);
        self
    }

    #[inline]
    pub fn buffer(&self) -> &Vec<(RecordUnion, Discriminator)> {
        &self.0
    }

    #[inline]
    pub fn buffer_mut(self) -> Vec<(RecordUnion, Discriminator)> { self.0 }

    #[inline]
    pub fn length(&self) -> usize {
        self.0.len()
    }

    #[inline]
    pub fn is_empty(&self) -> bool {
        self.0.is_empty()
    }

    #[inline]
    pub fn capacity(&self) -> usize {
        self.0.capacity()
    }

    #[inline]
    pub fn size(&self) -> usize {
        self.0.capacity() * std::mem::size_of::<(RecordUnion, Discriminator)>()
    }

    #[inline]
    pub fn clear(&mut self) {
        self.0.clear()
    }

    #[inline]
    pub fn validate(&self) -> Result<(), Vec<&'static str>> {
        Ok(())
    }

    pub fn build(self) -> Result<BytecodeChunk, Vec<&'static str>> {
        if let Err(errors) = self.validate() {
            Err(errors)
        } else {
            let mut buf = Vec::with_capacity(self.0.len());
            for rec in self.0 {
                buf.push(rec.0);
            }
            Ok(BytecodeChunk::from_vector(buf))
        }
    }
}

impl ops::Index<usize> for BytecodeStream {
    type Output = (RecordUnion, Discriminator);

    fn index(&self, idx: usize) -> &Self::Output {
        &self.0[idx]
    }
}

impl ops::IndexMut<usize> for BytecodeStream {
    fn index_mut(&mut self, idx: usize) -> &mut Self::Output {
        &mut self.0[idx]
    }
}