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

pub mod ops {
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
}

pub struct InstructionMeta {
    pub opcode: u32,
    pub num_args: usize,
    pub mnemonic: &'static str,
}

pub const META_TABLE: &'static [InstructionMeta] = &[
    InstructionMeta {
        opcode: ops::INTERRUPT,
        num_args: 1,
        mnemonic: "interrupt",
    },
    InstructionMeta {
        opcode: ops::PUSH,
        num_args: 1,
        mnemonic: "push",
    },
    InstructionMeta {
        opcode: ops::POP,
        num_args: 1,
        mnemonic: "pop",
    },
    InstructionMeta {
        opcode: ops::MOVE,
        num_args: 1,
        mnemonic: "mov",
    },
    InstructionMeta {
        opcode: ops::COPY,
        num_args: 2,
        mnemonic: "cpy",
    },
    InstructionMeta {
        opcode: ops::DUPLICATE,
        num_args: 0,
        mnemonic: "dupl",
    },
    InstructionMeta {
        opcode: ops::DUPLICATE_X2,
        num_args: 0,
        mnemonic: "ddupl",
    },
    InstructionMeta {
        opcode: ops::I32_ADD,
        num_args: 0,
        mnemonic: "iadd",
    },
    InstructionMeta {
        opcode: ops::I32_SUB,
        num_args: 0,
        mnemonic: "isub",
    },
    InstructionMeta {
        opcode: ops::I32_MUL,
        num_args: 0,
        mnemonic: "imul",
    },
    InstructionMeta {
        opcode: ops::I32_DIV,
        num_args: 0,
        mnemonic: "idiv",
    },
    InstructionMeta {
        opcode: ops::I32_MOD,
        num_args: 0,
        mnemonic: "imod",
    },
    InstructionMeta {
        opcode: ops::I32_AND,
        num_args: 0,
        mnemonic: "iand",
    },
    InstructionMeta {
        opcode: ops::I32_OR,
        num_args: 0,
        mnemonic: "ior",
    },
    InstructionMeta {
        opcode: ops::I32_XOR,
        num_args: 0,
        mnemonic: "ixor",
    },
    InstructionMeta {
        opcode: ops::I32_SAL,
        num_args: 0,
        mnemonic: "isal",
    },
    InstructionMeta {
        opcode: ops::I32_SAR,
        num_args: 0,
        mnemonic: "isar",
    },
    InstructionMeta {
        opcode: ops::I32_COM,
        num_args: 0,
        mnemonic: "icom",
    },
    InstructionMeta {
        opcode: ops::F32_ADD,
        num_args: 0,
        mnemonic: "fadd",
    },
    InstructionMeta {
        opcode: ops::F32_SUB,
        num_args: 0,
        mnemonic: "fsub",
    },
    InstructionMeta {
        opcode: ops::F32_MUL,
        num_args: 0,
        mnemonic: "fmul",
    },
    InstructionMeta {
        opcode: ops::F32_DIV,
        num_args: 0,
        mnemonic: "fdiv",
    },
    InstructionMeta {
        opcode: ops::F32_MOD,
        num_args: 0,
        mnemonic: "fmod",
    },
];