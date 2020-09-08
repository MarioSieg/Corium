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

// Does this struct include the stack pointer??

pub struct Stack<T>(Box<[T]>, usize) where T: Default + Copy + Clone + PartialEq;

impl<T> Stack<T> where T: Default + Copy + Clone + PartialEq {
    pub fn with_capacity(capacity: usize) -> Self {
        Self(Vec::with_capacity(capacity).into_boxed_slice(), 0)
    }

    pub fn with_size(size: usize) -> Self {
        Self(vec![T::default(); size].into_boxed_slice(), 0)
    }

    pub fn with_size_and_offset(size: usize, offset: usize) -> Self {
        Self(vec![T::default(); size].into_boxed_slice(), offset)
    }

    pub fn with_byte_size(byte_size: usize) -> Result<Self, ()> {
        if byte_size % std::mem::size_of::<T>() != 0 {
            Err(())
        }
        else {
            Ok(Self(vec![T::default(); byte_size / std::mem::size_of::<T>()].into_boxed_slice(), 0))
        }
    }
}

impl<T> Stack<T> where T: Default + Copy + Clone + PartialEq {
    pub fn len(&self) -> usize {
        self.0.len()
    }

    pub fn size(&self) -> usize {
        self.0.len() * std::mem::size_of::<T>()
    }

    pub fn buffer(&self) -> &Box<[T]> {
        &self.0
    }

    pub fn offset(&self) -> usize {
        self.1
    }

    pub fn set_offset(&mut self, offset: usize) {
        self.1 = offset
    }

    pub fn push(&mut self, val: T) {
        self.0[self.1] = val;
        self.1 += 1;
    }

    pub fn pop(&mut self) {
        self.1 -= 1;
    }

    pub fn pop_ret(&mut self) -> T {
        let ret = self.0[self.1];
        self.1 -= 1;
        ret
    }
}