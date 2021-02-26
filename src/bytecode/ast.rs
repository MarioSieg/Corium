use super::intrinsic::IntId;
use super::lexemes;
use std::fmt;

/// A token in bytecode.
/// Like a type safe version of 'Signal' using a discriminator and more features.
/// This is only used by the interpreter, optimizer and validator, not at runtime!
#[derive(Clone, PartialEq)]
pub enum Token {
    Opc(OpCode),
    Int(IntId),

    I32(i32),
    F32(f32),
    U32(u32),
    C32(char),
    Pin(u32),
}

impl Token {
    #[inline]
    pub fn is_instr(&self) -> bool {
        matches!(*self, Self::Opc(_))
    }

    #[inline]
    pub fn is_imm(&self) -> bool {
        !matches!(*self, Self::Opc(_))
    }

    pub fn bytes(&self) -> [u8; 4] {
        match *self {
            Token::Opc(x) => (x as u32).to_le_bytes(),
            Token::Int(x) => (x as u32).to_le_bytes(),
            Token::C32(x) => (x as u32).to_le_bytes(),
            Token::I32(x) => x.to_le_bytes(),
            Token::F32(x) => x.to_le_bytes(),
            Token::U32(x) => x.to_le_bytes(),
            Token::Pin(x) => x.to_le_bytes(),
        }
    }
}

impl fmt::Display for Token {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match *self {
            Token::Opc(x) => write!(f, "{}", lexemes::MNEMONICS[x as usize]),
            Token::Int(x) => write!(f, "intrin({:?})", x),
            Token::C32(x) => write!(f, "c32({})", x),
            Token::I32(x) => write!(f, "i32({})", x),
            Token::F32(x) => write!(f, "f32({})", x),
            Token::U32(x) => write!(f, "u32({})", x),
            Token::Pin(x) => write!(f, "pin({})", x),
        }
    }
}

impl fmt::Debug for Token {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        let bytes = self.bytes();
        write!(
            f,
            "{:02X} {:02X} {:02X} {:02X}",
            bytes[0], bytes[1], bytes[2], bytes[3]
        )
    }
}

/// Represents an opcode.
/// Contains all bytecode operations available.
#[repr(u32)]
#[derive(Copy, Clone, Eq, PartialEq, Debug)]
pub enum OpCode {
    // Control:
    Interrupt,
    CallIntrinsic,
    NoOp,

    // Memory:
    Push,
    Pop,
    Move,
    Copy,
    Duplicate,
    DuplicateTwice,
    CastI32toF32,
    CastF32toI32,

    // Branching:
    Jump,
    JumpIfZero,
    JumpIfNotZero,
    JumpIfEquals,
    JumpIfNotEquals,
    JumpIfAbove,
    JumpIfAboveEquals,
    JumpIfLess,
    JumpIfLessEquals,

    // Arithmetics:
    I32Addition,
    I32Subtraction,
    I32Multiplication,
    I32Division,
    I32Modulo,
    I32BitwiseAnd,
    I32BitwiseOr,
    I32BitwiseXor,
    I32BitwiseArithmeticLeftShift,
    I32BitwiseArithmeticRightShift,
    I32BitwiseCircularLeftShift,
    I32BitwiseCircularRightShift,
    I32BitwiseComplement,
    I32Increment,
    I32Decrement,
    F32Addition,
    F32Subtraction,
    F32Multiplication,
    F32Division,
    F32Modulo,
    F32FusedMultiplyAddition,

    // Vector:
    I32Vector4Addition,
    I32Vector4Subtraction,
    I32Vector4Multiplication,
    I32Vector4Division,
    I32Vector4Modulo,
    I32Vector4BitwiseAnd,
    I32Vector4BitwiseOr,
    I32Vector4BitwiseXor,
    I32Vector4BitwiseArithmeticLeftShift,
    I32Vector4BitwiseArithmeticRightShift,
    I32Vector4BitwiseCircularLeftShift,
    I32Vector4BitwiseCircularRightShift,
    I32Vector4BitwiseComplement,
    F32Vector4Addition,
    F32Vector4Subtraction,
    F32Vector4Multiplication,
    F32Vector4Division,
    F32Vector4Modulo,
    F32Vector4FusedMultiplyAddition,
    I32Vector8Addition,
    I32Vector8Subtraction,
    I32Vector8Multiplication,
    I32Vector8Division,
    I32Vector8Modulo,
    I32Vector8BitwiseAnd,
    I32Vector8BitwiseOr,
    I32Vector8BitwiseXor,
    I32Vector8BitwiseArithmeticLeftShift,
    I32Vector8BitwiseArithmeticRightShift,
    I32Vector8BitwiseCircularLeftShift,
    I32Vector8BitwiseCircularRightShift,
    I32Vector8BitwiseComplement,
    F32Vector8Addition,
    F32Vector8Subtraction,
    F32Vector8Multiplication,
    F32Vector8Division,
    F32Vector8Modulo,
    F32Vector8FusedMultiplyAddition,
    I32Vector16Addition,
    I32Vector16Subtraction,
    I32Vector16Multiplication,
    I32Vector16Division,
    I32Vector16Modulo,
    I32Vector16BitwiseAnd,
    I32Vector16BitwiseOr,
    I32Vector16BitwiseXor,
    I32Vector16BitwiseArithmeticLeftShift,
    I32Vector16BitwiseArithmeticRightShift,
    I32Vector16BitwiseCircularLeftShift,
    I32Vector16BitwiseCircularRightShift,
    I32Vector16BitwiseComplement,
    F32Vector16Addition,
    F32Vector16Subtraction,
    F32Vector16Multiplication,
    F32Vector16Division,
    F32Vector16Modulo,
    F32Vector16FusedMultiplyAddition,

    Count,
}
