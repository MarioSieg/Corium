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

use std::{ops, fmt};
use super::record::RecordUnion;

/// Contains common stack sizes.
#[derive(Debug, Copy, Clone, Eq, PartialEq)]
pub enum CommonStackSize {
    Debug = 16,
    Tiny1KB = 1024,
    Tiny4KB = 1024 * 4,
    Tiny8KB = 1024 * 8,
    Medium64KB = 1024 * 64,
    Medium256KB = 1024 * 256,
    Medium512KB = 1024 * 512,
    Large2MB = 1024 * 1024 * 2,
    Large4MB = 1024 * 1024 * 4,
    Large8MB = 1024 * 1024 * 8,
}

/// A fixed size stack.
/// It includes a stack pointer 'sp', which points to the topmost entry.
/// it also include a base pointer 'bp', which points to to the stackframe base.
pub struct Stack {
    /// Buffer array.
    buf: Box<[RecordUnion]>,

    /// Points to the topmost element.
    sp: usize,

    /// Backup sp to create stack frames.
    bp: usize,
}

impl Stack {

    /// Creates a new stack with a give size in bytes.
    /// The size can be select by the common stack size enum 'CommonStackSize'!
    /// Here the 'byte_size' is the total size of bytes
    /// the stack should contain. The final length of the size is calculated as:
    /// 'byte_size' / sizeof(T)
    /// Which means if you pass 32 as 'byte_size' and sizeof(T) would be 4
    /// the stack will have 8 entries of T -> each with a size of 4 bytes -> 32 bytes in total.
    pub fn with_common_size(size: CommonStackSize) -> Self {
        Self::with_byte_size(size as usize)
    }

    /// Create a new stack with a give size.
    /// The size is the number of entries the stack will have.
    /// A size of 1024 will result in a stack with 1024 entries of T.
    pub fn with_size(size: usize) -> Self {
        Self {
            buf: vec![RecordUnion::default(); size].into_boxed_slice(),
            sp: 0,
            bp: 0
        }
    }

    /// Create a new stack with a give size.
    /// The size is the number of entries the stack will have.
    /// A size of 1024 will result in a stack with 1024 entries of T.
    /// The additional parameter 'sp' allows it to set the stack pointer
    /// to a specific value. That could be used to skip data at the beginning of
    /// the stack. Use with caution!
    pub fn with_size_sp(size: usize, sp: usize) -> Self {
        Self {
            buf: vec![RecordUnion::default(); size].into_boxed_slice(),
            sp,
            bp: 0
        }
    }

    /// Create a new stack with a give size.
    /// The size is the number of entries the stack will have.
    /// A size of 1024 will result in a stack with 1024 entries of T.
    /// The first additional parameter 'sp' allows it to set the stack pointer
    /// to a specific value. This could be used to skip data at the beginning of
    /// the stack. The second additional paramter 'bp' allows it to
    /// set the base pointer. This allows it to create initial stack frames.
    /// Use with caution!
    pub fn with_size_sp_bp(size: usize, sp: usize, bp: usize) -> Self {
        Self {
            buf: vec![RecordUnion::default(); size].into_boxed_slice(),
            sp,
            bp
        }
    }

    /// Create a new stack with a give size in bytes.
    /// Here the 'byte_size' is the total size of bytes
    /// the stack should contain. The final length of the size is calculated as:
    /// 'byte_size' / sizeof(T)
    /// Which means if you pass 32 as 'byte_size' and sizeof(T) would be 4
    /// the stack will have 8 entries of T -> each with a size of 4 bytes -> 32 bytes in total.
    pub fn with_byte_size(byte_size: usize) -> Self{
        if byte_size % std::mem::size_of::<RecordUnion>() != 0 {
            panic!("Invalid byte size!");
        }
        Self {
            buf: vec![RecordUnion::default(); byte_size / std::mem::size_of::<RecordUnion>()].into_boxed_slice(),
            sp: 0,
            bp: 0
        }
    }
}

impl Stack {

    /// Returns the amount of enties in the stack.
    #[inline]
    pub fn len(&self) -> usize {
        self.sp + 1
    }

    /// Returns true if the stack is empty, else false.
    #[inline]
    pub fn is_empty(&self) -> bool {
        self.sp == 0
    }

    /// Returns the byte size of the stack.
    /// It is calculated as follows:
    /// sp * sizeof(T)
    #[inline]
    pub fn size(&self) -> usize {
        self.sp * std::mem::size_of::<RecordUnion>()
    }

    /// Returns the size of a record union in bytes.
    /// Just a helper - same as:
    /// std::mem::size_of::<RecordUnion>()
    #[inline]
    pub fn rec_size(&self) -> usize {
        std::mem::size_of::<RecordUnion>()
    }

    /// Returns a immutable reference to the buffer array. 
    #[inline]
    pub fn buf(&self) -> &[RecordUnion] {
        &self.buf
    }

    /// Returns the amount of enties in the stack buffer.
    #[inline]
    pub fn buf_len(&self) -> usize {
        self.buf.len()
    }

    /// Returns true if the stack buffer is empty, else false.
    #[inline]
    pub fn buf_is_empty(&self) -> bool {
        self.buf.is_empty()
    }

    /// Returns the byte size of the stack  buffer.
    /// It is calculated as follows:
    /// stack_buffer.capacity() * sizeof(T)
    #[inline]
    pub fn buf_size(&self) -> usize {
        self.buf.len() * std::mem::size_of::<RecordUnion>()
    }

    /// Returns the current stack pointer.
    /// The stack pointer always points topmost
    /// element. To set the next free slot just call push or increment
    /// the stack pointer by one and the subscript the buffer with sp.
    #[inline]
    pub fn sp(&self) -> usize {
        self.sp
    }

    /// Returns the current base pointer.
    #[inline]
    pub fn bp(&self) -> usize {
        self.bp
    }

    /// Returns the value at the top of the stack.
    #[inline]
    pub fn top(&self) -> RecordUnion {
        self.buf[self.sp]
    }

    /// Sets the value at the top of the stack.
    #[inline]
    pub fn set_top(&mut self, val: RecordUnion) {
        self.buf[self.sp] = val;
    }

    /// Returns the value at the bottom of the stack.
    #[inline]
    pub fn bottom(&self) -> RecordUnion {
        self.buf[0]
    }

    /// Sets the value at the bottom of the stack.
    #[inline]
    pub fn set_bottom(&mut self, val: RecordUnion) {
        self.buf[self.sp] = val;
    }

    /// Pushes a new element on top of the stack.
    #[inline]
    pub fn push(&mut self, val: RecordUnion) {
        self.sp += 1;
        self.buf[self.sp] = val;
    }

    /// Shorthand for writing self.push(RecordUnion::from_int(x))
    #[inline]
    pub fn push_int(&mut self, x: i32) {
        self.push(RecordUnion::from_int(x))
    }

    /// Shorthand for writing self.push(RecordUnion::from_float(x))
    #[inline]
    pub fn push_float(&mut self, x: f32) {
        self.push(RecordUnion::from_float(x))
    }

    /// Shorthand for writing self.push(RecordUnion::from_opcode(x))
    #[inline]
    pub fn push_opcode(&mut self, x: u32) {
        self.push(RecordUnion::from_opcode(x))
    }

    /// Pops the top element from the stack.
    #[inline]
    pub fn pop(&mut self) {
        self.sp -= 1;
    }

    /// Pops the top element from the stack 
    /// and returns it.
    #[inline]
    pub fn pop_ret(&mut self) -> RecordUnion {
        let ret = self.buf[self.sp];
        self.sp -= 1;
        ret
    }
}

impl ops::Index<usize> for Stack  {
    type Output = RecordUnion;

    fn index(&self, idx: usize) -> &Self::Output {
        &self.buf[idx]
    }
}

impl ops::IndexMut<usize> for Stack {
    fn index_mut(&mut self, idx: usize) -> &mut Self::Output {
        &mut self.buf[idx]
    }
}

impl fmt::Display for Stack {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        writeln!(f, "len: {} size: {} B recsize: {} B, sp: {} bp: {}", self.len(), self.size(),
        self.rec_size(),
        self.sp(), self.bp())
    }
}

impl fmt::Debug for Stack {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        writeln!(f, "len: {} size: {} B recsize: {} B, sp: {} bp: {}", self.len(), self.size(),
        self.rec_size(),
        self.sp(), self.bp())?;
        for (i, rec) in self.buf.iter().enumerate() {
            writeln!(f, "{:#010x} | {:?}", i, rec)?;
        }
        fmt::Result::Ok(())
    }
}