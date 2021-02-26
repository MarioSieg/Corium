use crate::bytecode::signal::Signal;
use std::{convert, fmt};

/// Represents a single stack record at runtime.
/// A record is used as an union which can be an i32, f32 or u32.
/// It is not discriminated and typesafe so be carefully!
#[repr(C)]
#[derive(Copy, Clone, Eq, PartialEq, Hash)]
pub struct Record(u32);

/// Creates a record from an usize.
/// It might get truncated into an u32, if sizeof(usize) > 32.
impl convert::From<usize> for Record {
    #[inline(always)]
    fn from(x: usize) -> Self {
        Self(x as _)
    }
}

/// Creates an usize from a record.
/// This might lead to arbitrary values,
/// if the record representation wasn't an usize.
impl convert::From<Record> for usize {
    #[inline(always)]
    fn from(x: Record) -> Self {
        x.0 as _
    }
}

/// Creates a record from an i32.
/// The record then represents an i32 with the value of x.
impl convert::From<i32> for Record {
    #[inline(always)]
    fn from(x: i32) -> Self {
        Self(x as _)
    }
}

/// Creates an i32 from a record.
/// This might lead to arbitrary values,
/// if the record representation wasn't an i32.
impl convert::From<Record> for i32 {
    #[inline(always)]
    fn from(x: Record) -> Self {
        x.0 as _
    }
}

/// Creates a record from an u32.
/// The record then represents an u32 with the value of x.
impl convert::From<u32> for Record {
    #[inline(always)]
    fn from(x: u32) -> Self {
        Self(x)
    }
}

/// Creates an u32 from a record.
/// This might lead to arbitrary values,
/// if the record representation wasn't an u32.
impl convert::From<Record> for u32 {
    #[inline(always)]
    fn from(x: Record) -> Self {
        x.0
    }
}

/// Creates a record from a char.
/// The record then represents a char with the value of x.
impl convert::From<char> for Record {
    #[inline(always)]
    fn from(x: char) -> Self {
        Self(x as u32)
    }
}

/// Creates a char from a record.
/// This might lead to arbitrary values,
/// if the record representation wasn't a char.
impl convert::From<Record> for char {
    #[inline(always)]
    fn from(x: Record) -> Self {
        debug_assert!(
            std::char::from_u32(x.into()).is_some(),
            "VM_RecordCharMiscast!"
        );
        unsafe { std::char::from_u32_unchecked(x.into()) }
    }
}

/// Creates a srecord from a f32.
/// The record then represents an f32 with the value of x.
impl convert::From<f32> for Record {
    #[inline(always)]
    fn from(x: f32) -> Self {
        Self(x.to_bits())
    }
}

/// Creates an f32 from a record.
/// This might lead to arbitrary values,
/// if the record representation wasn't an f32.
impl convert::From<Record> for f32 {
    #[inline(always)]
    fn from(x: Record) -> Self {
        f32::from_bits(x.0)
    }
}

impl convert::From<[u8; 4]> for Record {
    #[inline(always)]
    fn from(x: [u8; 4]) -> Self {
        Self(u32::from_le_bytes(x))
    }
}

/// Creates a new signal from a little endian byte array with four elements (32-bits).
impl convert::From<Record> for [u8; 4] {
    #[inline(always)]
    fn from(x: Record) -> Self {
        x.0.to_le_bytes()
    }
}

/// Creates a signal from a byte array with four elements (32-bits).
impl convert::From<Signal> for Record {
    #[inline(always)]
    fn from(x: Signal) -> Self {
        Self(u32::from(x))
    }
}

/// Only prints the byte array.
impl fmt::Display for Record {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        let b: [u8; 4] = (*self).into();
        write!(f, "{:02X} {:02X} {:02X} {:02X}", b[0], b[1], b[2], b[3])
    }
}

/// Prints the byte array with values and correct syntax.
impl fmt::Debug for Record {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        let b: [u8; 4] = (*self).into();
        write!(
            f,
            "{:02X} {:02X} {:02X} {:02X} | {} {}",
            b[0],
            b[1],
            b[2],
            b[3],
            i32::from(*self),
            f32::from(*self),
        )
    }
}

#[cfg(tests)]
mod tests {
    #[cfg(test)]
    mod tests {
        use super::Record;
        use crate::bytecode::signal::Signal;
        use std::mem;

        #[test]
        fn size() {
            assert_eq!(mem::size_of::<Record>(), mem::size_of::<i32>());
            assert_eq!(mem::size_of::<Signal>(), mem::size_of::<Record>());
        }

        #[test]
        fn union_i32() {
            assert_eq!(i32::from(Record::from(-5_i32)), -5);
        }

        #[test]
        fn union_u32() {
            assert_eq!(u32::from(Record::from(5_u32)), 5);
        }

        #[test]
        fn union_bytes() {
            assert_eq!(u32::from(Record::from([0xFF, 0xFF, 0xFF, 0xFF])), u32::MAX);
        }

        #[test]
        fn union_f32() {
            assert_eq!(f32::from(Record::from(5.12345_f32)), 5.12345);
        }
    }
}
