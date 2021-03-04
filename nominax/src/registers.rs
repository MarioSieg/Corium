use super::union::Union32;
use std::fmt;

/// There are 32 of each register type.
pub const REGISTER_COUNT: usize = 32;

/// 32-bit general purpose register
pub struct Reg32(pub Union32);

/// 128-bit simd vector accumulator
pub struct Reg128(pub [Union32; 4]);

/// 256-bit simd vector accumulator
pub struct Reg256(pub [Union32; 8]);

/// 512-bit simd vector accumulator
pub struct Reg512(pub [Union32; 16]);

/// Represents a register. Each id only ranges from 0 to 31!
#[derive(Copy, Clone, Eq, PartialEq, Debug)]
pub enum Register {
    R(u8),
    X(u8),
    Y(u8),
    Z(u8),
}

impl Register {
    #[inline]
    pub fn id(&self) -> u8 {
        match *self {
            Self::R(x) => x,
            Self::X(x) => x,
            Self::Y(x) => x,
            Self::Z(x) => x,
        }
        .clamp(0, (REGISTER_COUNT - 1) as u8)
    }

    #[inline]
    pub fn size(&self) -> usize {
        match self {
            Self::R(_) => std::mem::size_of::<Reg32>(),
            Self::X(_) => std::mem::size_of::<Reg128>(),
            Self::Y(_) => std::mem::size_of::<Reg256>(),
            Self::Z(_) => std::mem::size_of::<Reg512>(),
        }
    }
}

impl fmt::Display for Register {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match *self {
            Self::R(x) => write!(f, "R{}", x),
            Self::X(x) => write!(f, "X{}", x),
            Self::Y(x) => write!(f, "Y{}", x),
            Self::Z(x) => write!(f, "Z{}", x),
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn id_clamp() {
        let r0 = Register::R(0);
        assert_eq!(r0.id(), 0);
        let r31 = Register::R(31);
        assert_eq!(r31.id(), 31);
        let r32 = Register::R(32);
        assert_eq!(r32.id(), 31);
        let r128 = Register::R(128);
        assert_eq!(r128.id(), 31);
    }

    #[test]
    fn size() {
        let r0 = Register::R(0);
        assert_eq!(r0.size(), 4);
        let x0 = Register::X(0);
        assert_eq!(x0.size(), 16);
        let y0 = Register::Y(0);
        assert_eq!(y0.size(), 32);
        let z0 = Register::Z(0);
        assert_eq!(z0.size(), 64);
    }
}
