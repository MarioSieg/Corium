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

#[derive(Copy, Clone, PartialEq, Debug, Hash)]
pub struct RecordUnion(u32);

impl RecordUnion {
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
    pub fn to_le_bytes(&self) -> [u8; 4] {
        self.0.to_le_bytes()
    }

    #[inline]
    pub fn to_be_bytes(&self) -> [u8; 4] {
        self.0.to_be_bytes()
    }
}

#[derive(Copy, Clone, Eq, PartialEq, Debug, Hash)]
pub enum Discriminator {
    U32,
    I32,
    F32,
}

#[derive(Copy, Clone, PartialEq, Debug, Hash)]
pub struct DiscriminatedRecordUnion(RecordUnion, Discriminator);

impl DiscriminatedRecordUnion {
    #[inline]
    pub fn new(rec: RecordUnion, dis: Discriminator) -> Self {
        Self(rec, dis)
    }

    #[inline]
    pub fn from_u32(val: u32) -> Self {
        Self(RecordUnion::from_u32(val), Discriminator::U32)
    }

    #[inline]
    pub fn from_i32(val: i32) -> Self {
        Self(RecordUnion::from_i32(val), Discriminator::I32)
    }

    #[inline]
    pub fn from_f32(val: f32) -> Self {
        Self(RecordUnion::from_f32(val), Discriminator::F32)
    }
}

impl DiscriminatedRecordUnion {
    #[inline]
    pub fn record(&self) -> RecordUnion {
        self.0
    }

    #[inline]
    pub fn discriminator(&self) -> Discriminator {
        self.1
    }

    #[inline]
    pub fn u32(&self) -> Option<u32> {
        if self.1 == Discriminator::U32 {
            Some(self.0.u32())
        } else {
          None
        }
    }

    #[inline]
    pub fn set_u32(&mut self, val: u32) {
        self.0.set_u32(val);
        self.1 = Discriminator::U32
    }

    #[inline]
    pub fn i32(&self) -> Option<i32> {
        if self.1 == Discriminator::I32 {
            Some(self.0.i32())
        } else {
            None
        }
    }

    #[inline]
    pub fn set_i32(&mut self, val: i32) {
        self.0.set_i32(val);
        self.1 = Discriminator::I32
    }

    #[inline]
    pub fn f32(&self) -> Option<f32> {
        if self.1 == Discriminator::F32 {
            Some(self.0.f32())
        } else {
            None
        }
    }

    #[inline]
    pub fn set_f32(&mut self, val: f32) {
        self.0.set_f32(val);
        self.1 = Discriminator::F32
    }
}