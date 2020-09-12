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

pub const INTERRUPT: u32 = 0x00000000;
pub const PUSH: u32 = 0x00000001;
pub const POP: u32 = 0x00000002;
pub const MOVE: u32 = 0x00000003;
pub const COPY: u32 = 0x00000004;
pub const DUPLICATE: u32 = 0x00000005;
pub const DUPLICATE_X2: u32 = 0x00000006;
pub const I32_ADD: u32 = 0x00000007;
pub const I32_SUB: u32 = 0x00000008;
pub const I32_MUL: u32 = 0x00000009;
pub const I32_DIV: u32 = 0x0000000A;
pub const I32_MOD: u32 = 0x0000000B;
pub const I32_AND: u32 = 0x0000000C;
pub const I32_OR: u32 = 0x0000000D;
pub const I32_XOR: u32 = 0x0000000E;
pub const I32_SAL: u32 = 0x0000000F;
pub const I32_SAR: u32 = 0x00000010;
pub const I32_COM: u32 = 0x00000011;
pub const F32_ADD: u32 = 0x00000012;
pub const F32_SUB: u32 = 0x00000013;
pub const F32_MUL: u32 = 0x00000014;
pub const F32_DIV: u32 = 0x00000015;
pub const F32_MOD: u32 = 0x00000016;