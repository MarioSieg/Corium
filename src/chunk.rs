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

use super::asm;
use super::record::*;

/// A fixed size chunk of bytecode, which can be executed by the VM.
pub struct BytecodeChunk(Box<[RecordUnion]>, usize);

impl BytecodeChunk {
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
}

impl BytecodeChunk {
    #[inline]
    pub fn buffer(&self) -> &[RecordUnion] {
        &self.0
    }

    #[inline]
    pub fn buffer_mut(self) -> Box<[RecordUnion]> {
        self.0
    }

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
    pub fn instruction_pointer(&self) -> usize {
        self.1
    }

    #[inline]
    pub fn jump(&mut self, ip: usize) {
        self.1 = ip
    }

    #[inline]
    pub fn fetch(&mut self) -> RecordUnion {
        let record = self.0[self.1];
        self.1 += 1;
        record
    }

    #[inline]
    pub fn is_done(&self) -> bool {
        self.1 >= self.0.len()
    }
}

impl ops::Index<usize> for BytecodeChunk {
    type Output = RecordUnion;

    fn index(&self, idx: usize) -> &Self::Output {
        &self.0[idx]
    }
}

impl ops::IndexMut<usize> for BytecodeChunk {
    fn index_mut(&mut self, idx: usize) -> &mut Self::Output {
        &mut self.0[idx]
    }
}

impl fmt::Debug for BytecodeChunk {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        writeln!(f, "-----------------------------------------------")?;
        writeln!(f, "      Address      |    Bytes    |  Opcode/Arg ")?;
        writeln!(f, "-----------------------------------------------")?;
        let mut i = 0;
        while i < self.0.len() {
            let meta = &asm::META_TABLE[self.0[i].u32() as usize];
            writeln!(f, "{:#018X} | {} | {}", i, self.0[i], meta.mnemonic)?;
            for j in (1..=meta.num_args).map(|j| i + j) {
                writeln!(f, "{:#018X} | {:?}", j, self.0[j])?;
            }
            i += 1 + meta.num_args;
        }
        writeln!(f, "-----------------------------------------------")
    }
}
