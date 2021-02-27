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
            Token::Pin(x) => write!(f, "%pin &{:#X}", x),
            Token::Int(x) => write!(f, "%ipc *{:#X}", x as u32),
            Token::C32(x) => write!(f, "%c32 ${}", x as u32),
            Token::I32(x) => write!(f, "%i32 ${}", x),
            Token::F32(x) => write!(f, "%f32 ${}", x as u32),
            Token::U32(x) => write!(f, "%u32 ${}", x),
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
    Interrupt = 0x00,
    Intrin = 0x01,
    Nop = 0x02,

    // Memory:
    Push = 0x03,
    Pop = 0x04,
    Mov = 0x05,
    Cpy = 0x06,
    Dupl = 0x07,
    Ddupl = 0x08,
    CastI2F = 0x09,
    CastF2I = 0x0A,

    // Branching:
    Jmp = 0x0B,
    Jz = 0x0C,
    Jnz = 0x0D,
    Je = 0x0E,
    Jne = 0x0F,
    Ja = 0x10,
    Jae = 0x11,
    Jl = 0x12,
    Jle = 0x13,

    // Arithmetics:
    Iadd = 0x14,
    Isub = 0x15,
    Imul = 0x16,
    Idiv = 0x17,
    Imod = 0x18,
    Iand = 0x19,
    Ior = 0x1A,
    Ixor = 0x1B,
    Isal = 0x1C,
    Isar = 0x1D,
    Irol = 0x1E,
    Iror = 0x1F,
    Icom = 0x20,
    Iinc = 0x21,
    Idec = 0x22,
    Fadd = 0x23,
    Fsub = 0x24,
    Fmul = 0x25,
    Fdiv = 0x26,
    Fmod = 0x27,
    Ffma = 0x28,

    // Vector:
    Viquadadd = 0x29,
    Viquadsub = 0x2A,
    Viquadmul = 0x2B,
    Viquaddiv = 0x2C,
    Viquadmod = 0x2D,
    Viquadand = 0x2E,
    Viquador = 0x2F,
    Viquadxor = 0x30,
    Viquadsal = 0x31,
    Viquadsar = 0x32,
    Viquadrol = 0x33,
    Viquadror = 0x34,
    Viquadcom = 0x35,
    Vfquadadd = 0x36,
    Vfquadsub = 0x37,
    Vfquadmul = 0x38,
    Vfquaddiv = 0x39,
    Vfquadmod = 0x3A,
    Vfquadfma = 0x3B,

    Vioctaadd = 0x3C,
    Vioctasub = 0x3D,
    Vioctamul = 0x3E,
    Vioctadiv = 0x3F,
    Vioctamod = 0x40,
    Vioctaand = 0x41,
    Vioctaor = 0x42,
    Vioctaxor = 0x43,
    Vioctasal = 0x44,
    Vioctasar = 0x45,
    Vioctarol = 0x46,
    Vioctaror = 0x47,
    Vioctacom = 0x48,
    Vfoctaadd = 0x49,
    Vfoctasub = 0x4A,
    Vfoctamul = 0x4B,
    Vfoctadiv = 0x4C,
    Vfoctamod = 0x4D,
    Vfoctafma = 0x4E,

    Vihexaadd = 0x4F,
    Vihexasub = 0x50,
    Vihexamul = 0x51,
    Vihexadiv = 0x52,
    Vihexamod = 0x53,
    Vihexaand = 0x54,
    Vihexaor = 0x55,
    Vihexaxor = 0x56,
    Vihexasal = 0x57,
    Vihexasar = 0x58,
    Vihexarol = 0x59,
    Vihexaror = 0x5A,
    Vihexacom = 0x5B,
    Vfhexaadd = 0x5C,
    Vfhexasub = 0x5D,
    Vfhexamul = 0x5E,
    Vfhexadiv = 0x5F,
    Vfhexamod = 0x60,
    Vfhexafma = 0x61,

    Count,
}
