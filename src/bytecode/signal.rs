use crate::bytecode::{
    ast::{OpCode, Token},
    intrinsic::Intrinsics,
};
use crate::core::record::Record;
use std::{convert, fmt, mem};

/// Represents a single bytecode signal at runtime.
/// A signal is used as an union which can be an operation (opcode) or a parameter.
/// For a typesafe, discriminated version use 'Token'.
#[repr(C)]
#[derive(Copy, Clone, Eq, PartialEq, Hash)]
pub struct Signal(u32);

/// Creates a signal from an usize.
/// Panics if the usize is > u32::MAX!
impl convert::From<usize> for Signal {
    #[inline(always)]
    fn from(x: usize) -> Self {
        debug_assert!(x < u32::MAX as _, "VM_Signal_USizeTooLarge");
        Self(x as _)
    }
}

/// Creates an usize from a signal.
/// This might lead to arbitrary values,
/// if the signal representation wasn't an usize.
/// Look at 'Token' for a typesafe non runtime version.
impl convert::From<Signal> for usize {
    #[inline(always)]
    fn from(x: Signal) -> Self {
        x.0 as _
    }
}

/// Creates a signal from an i32.
/// The signal then represents an i32 with the value of x.
impl convert::From<i32> for Signal {
    #[inline(always)]
    fn from(x: i32) -> Self {
        Self(x as _)
    }
}

/// Creates an i32 from a signal.
/// This might lead to arbitrary values,
/// if the signal representation wasn't an i32.
/// Look at 'Token' for a typesafe non runtime version.
impl convert::From<Signal> for i32 {
    #[inline(always)]
    fn from(x: Signal) -> Self {
        x.0 as _
    }
}

/// Creates a signal from an u32.
/// The signal then represents an u32 with the value of x.
impl convert::From<u32> for Signal {
    #[inline(always)]
    fn from(x: u32) -> Self {
        Self(x)
    }
}

/// Creates an u32 from a signal.
/// This might lead to arbitrary values,
/// if the signal representation wasn't an u32.
/// Look at 'Token' for a typesafe non runtime version.
impl convert::From<Signal> for u32 {
    #[inline(always)]
    fn from(x: Signal) -> Self {
        x.0
    }
}

/// Creates a signal from a char.
/// The record then represents a char with the value of x.
impl convert::From<char> for Signal {
    #[inline(always)]
    fn from(x: char) -> Self {
        Self(x as u32)
    }
}

/// Creates a char from a signal.
/// This might lead to arbitrary values,
/// if the signal representation wasn't a char.
impl convert::From<Signal> for char {
    #[inline(always)]
    fn from(x: Signal) -> Self {
        debug_assert!(
            std::char::from_u32(x.into()).is_some(),
            "VM_RecordCharMiscast!"
        );
        unsafe { std::char::from_u32_unchecked(x.into()) }
    }
}

/// Creates a signal from a f32.
/// The signal then represents an f32 with the value of x.
impl convert::From<f32> for Signal {
    #[inline(always)]
    fn from(x: f32) -> Self {
        Self(x.to_bits())
    }
}

/// Creates an f32 from a signal.
/// This might lead to arbitrary values,
/// if the signal representation wasn't an f32.
/// Look at 'Token' for a typesafe non runtime version.
impl convert::From<Signal> for f32 {
    #[inline(always)]
    fn from(x: Signal) -> Self {
        f32::from_bits(x.0)
    }
}

/// Creates a signal from an opcode.
/// The signal then represents an opcode with the value of x.
impl convert::From<OpCode> for Signal {
    #[inline(always)]
    fn from(x: OpCode) -> Self {
        Self(x as _)
    }
}

/// Creates an opcode from a signal.
/// This might lead to arbitrary values,
/// if the signal representation wasn't an opcode.
/// Look at 'Token' for a typesafe non runtime version.
impl convert::From<Signal> for OpCode {
    #[inline(always)]
    fn from(x: Signal) -> Self {
        debug_assert!(x.0 < OpCode::_Count as _);
        unsafe { mem::transmute::<u32, OpCode>(x.0) }
    }
}

/// Creates a signal from an intrinsic proc id.
/// The signal then represents an opcode with the value of x.
impl convert::From<Intrinsics> for Signal {
    #[inline(always)]
    fn from(x: Intrinsics) -> Self {
        Self(x as _)
    }
}

/// Creates an intrinsic proc id from a signal.
/// This might lead to arbitrary values,
/// if the signal representation wasn't an intrinsic proc id.
/// Look at 'Token' for a typesafe non runtime version.
impl convert::From<Signal> for Intrinsics {
    #[inline(always)]
    fn from(x: Signal) -> Self {
        debug_assert!(x.0 < Intrinsics::_Count as _);
        unsafe { mem::transmute::<u32, Intrinsics>(x.0) }
    }
}

/// Creates a new signal from a little endian byte array with four elements (32-bits).
impl convert::From<[u8; 4]> for Signal {
    #[inline(always)]
    fn from(x: [u8; 4]) -> Self {
        Self(u32::from_le_bytes(x))
    }
}

/// Creates a signal from a byte array with four elements (32-bits).
impl convert::From<Signal> for [u8; 4] {
    #[inline(always)]
    fn from(x: Signal) -> Self {
        x.0.to_le_bytes()
    }
}

/// Converts this signal from a stack record.
impl convert::From<Record> for Signal {
    #[inline(always)]
    fn from(x: Record) -> Self {
        Self(u32::from(x))
    }
}

/// Creates a signal from an discriminated signal.
impl<'a> convert::From<&Token> for Option<Signal> {
    fn from(x: &Token) -> Self {
        match x {
            Token::I32(i) => Some(Signal::from(*i)),
            Token::F32(f) => Some(Signal::from(*f)),
            Token::C32(c) => Some(Signal::from(*c)),
            Token::U32(u) => Some(Signal::from(*u)),
            Token::OpCode(op) => Some(Signal::from(*op)),
            Token::Ipc(ipc) => Some(Signal::from(*ipc)),
            Token::Pin(l) => Some(Signal::from(*l)),
        }
    }
}

/// Only prints the byte array.
impl fmt::Display for Signal {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        let b: [u8; 4] = (*self).into();
        write!(f, "{:02X} {:02X} {:02X} {:02X}", b[0], b[1], b[2], b[3])
    }
}

/// Prints the byte array with values and correct syntax.
impl fmt::Debug for Signal {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        let b: [u8; 4] = (*self).into();
        write!(
            f,
            "{:02X} {:02X} {:02X} {:02X} | {}, {:#e}",
            b[0],
            b[1],
            b[2],
            b[3],
            i32::from(*self),
            i32::from(*self),
        )
    }
}

#[cfg(test)]
mod tests {
    use crate::bytecode::{ast::OpCode, intrinsic::Intrinsics, signal::Signal};
    use std::mem;

    #[test]
    fn size() {
        assert_eq!(mem::size_of::<Signal>(), mem::size_of::<i32>());
    }

    #[test]
    fn union_i32() {
        assert_eq!(i32::from(Signal::from(-5_i32)), -5);
    }

    #[test]
    fn union_u32() {
        assert_eq!(u32::from(Signal::from(5_u32)), 5);
    }

    #[test]
    fn union_bytes() {
        assert_eq!(u32::from(Signal::from([0xFF, 0xFF, 0xFF, 0xFF])), u32::MAX);
    }

    #[test]
    fn union_f32() {
        assert_eq!(f32::from(Signal::from(5.12345_f32)), 5.12345);
    }

    #[test]
    fn union_opcode() {
        assert_eq!(OpCode::from(Signal::from(OpCode::Move)), OpCode::Move);
    }

    #[test]
    fn union_intrinsic_proc_id() {
        assert_eq!(
            Intrinsics::from(Signal::from(Intrinsics::Sin)),
            Intrinsics::Sin
        );
    }
}
