use super::{intrinsic::Intrinsics, lexemes};
use std::{convert, fmt};

/// A token in bytecode.
/// Like a type safe version of 'Signal' using a discriminator and more features.
/// This is only used by the interpreter, optimizer and validator, not at runtime!
#[derive(Clone, PartialEq)]
pub enum Token {
    OpCode(OpCode),
    I32(i32),
    F32(f32),
    U32(u32),
    C32(char),
    Pin(u32),
    Ipc(Intrinsics),
}

impl Token {
    #[inline]
    pub fn is_operation(&self) -> bool {
        matches!(*self, Self::OpCode(_))
    }

    #[inline]
    pub fn is_argument(&self) -> bool {
        !matches!(*self, Self::OpCode(_))
    }

    #[inline]
    pub fn is_scalar(&self) -> bool {
        matches!(
            *self,
            Self::I32(_) | Self::F32(_) | Self::C32(_) | Self::U32(_)
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

    _Count,
}

impl convert::From<&Token> for Option<[u8; 4]> {
    fn from(x: &Token) -> Self {
        match *x {
            Token::OpCode(value) => Some((value as u32).to_le_bytes()),
            Token::Ipc(value) => Some((value as u32).to_le_bytes()),
            Token::I32(value) => Some(value.to_le_bytes()),
            Token::F32(value) => Some(value.to_le_bytes()),
            Token::U32(value) => Some(value.to_le_bytes()),
            Token::Pin(value) => Some(value.to_le_bytes()),
            Token::C32(value) => Some((value as u32).to_le_bytes()),
        }
    }
}

impl fmt::Display for Token {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match *self {
            Self::I32(_) => write!(f, "{}", lexemes::TYPES[0]),
            Self::F32(_) => write!(f, "{}", lexemes::TYPES[1]),
            Self::U32(_) => write!(f, "{}", lexemes::TYPES[2]),
            Self::C32(_) => write!(f, "{}", lexemes::TYPES[3]),
            Self::Pin(_) => write!(f, "{}", lexemes::TYPES[4]),
            Self::Ipc(_) => write!(f, "{}", lexemes::TYPES[5]),
            Self::OpCode(_) => write!(f, "op"),
        }
    }
}

impl fmt::Debug for Token {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        let get_type = || -> &'static str {
            match self {
                Self::I32(_) => lexemes::TYPES[0],
                Self::F32(_) => lexemes::TYPES[1],
                Self::U32(_) => lexemes::TYPES[2],
                Self::C32(_) => lexemes::TYPES[3],
                Self::Pin(_) => lexemes::TYPES[4],
                Self::Ipc(_) => lexemes::TYPES[5],
                _ => &"?",
            }
        };

        match self {
            Self::I32(value) => write!(
                f,
                " {}{} {}{}{:X}",
                lexemes::markers::TYPE,
                get_type(),
                lexemes::markers::IMMEDIATE_VALUE,
                lexemes::literals::BEGIN_HEXADECIMAL,
                value,
            ),
            Self::F32(value) => write!(
                f,
                " {}{} {}{}{:E}",
                lexemes::markers::TYPE,
                get_type(),
                lexemes::markers::IMMEDIATE_VALUE,
                lexemes::literals::BEGIN_SCIENTIFIC,
                value,
            ),
            Self::U32(value) => write!(
                f,
                " {}{} {}{}{:X}",
                lexemes::markers::TYPE,
                get_type(),
                lexemes::markers::IMMEDIATE_VALUE,
                lexemes::literals::BEGIN_HEXADECIMAL,
                value,
            ),
            Self::C32(value) => write!(
                f,
                " {}{} {}{:X}",
                lexemes::markers::TYPE,
                get_type(),
                lexemes::markers::IMMEDIATE_VALUE,
                *value as u32,
            ),
            Self::Pin(value) => write!(
                f,
                " {}{} {}{}{}{:X}{}",
                lexemes::markers::TYPE,
                get_type(),
                lexemes::markers::BEGIN_PTR,
                lexemes::markers::IMMEDIATE_VALUE,
                lexemes::literals::BEGIN_HEXADECIMAL,
                value,
                lexemes::markers::END_PTR,
            ),
            Self::Ipc(value) => write!(
                f,
                " {}{} {}{}{}{:X}{}",
                lexemes::markers::TYPE,
                get_type(),
                lexemes::markers::BEGIN_PTR,
                lexemes::markers::IMMEDIATE_VALUE,
                lexemes::literals::BEGIN_HEXADECIMAL,
                *value as u32,
                lexemes::markers::END_PTR,
            ),
            Self::OpCode(value) => write!(
                f,
                "{}{}",
                lexemes::markers::INSTRUCTION,
                lexemes::MNEMONICS[*value as usize],
            ),
        }
    }
}
