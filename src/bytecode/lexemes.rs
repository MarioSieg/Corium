use super::ast::OpCode;

pub mod markers {
    pub const COMMENT: char = ';';
    pub const MACRO: char = '#';
    pub const INSTRUCTION: char = '%';
    pub const TYPE: char = '*';
    pub const IMMEDIATE_VALUE: char = '$';
    pub const BEGIN_PTR: char = '[';
    pub const END_PTR: char = ']';
    pub const ARGUMENT_SEPARATOR: char = ',';
    pub const SECTION: char = '@';
}

pub mod literals {
    pub const BEGIN_DECIMAL: &str = "0d";
    pub const BEGIN_BINARY: &str = "0b";
    pub const BEGIN_HEXADECIMAL: &str = "0x";
    pub const BEGIN_OCTAL: &str = "0c";
    pub const BEGIN_QUATERNARY: &str = "0q";
    pub const BEGIN_SCIENTIFIC: &str = "0s";
    pub const STRING_LITERAL: char = '\"';
    pub const BYTES_LITERAL: char = '´';
}

pub const TYPES: &[&str] = &["i32", "f32", "u32", "c32", "pin", "ipc"];

pub const MNEMONICS: &[&str; OpCode::_Count as usize] = &[
    "interrupt",
    "intrin",
    "nop",
    "push",
    "pop",
    "mov",
    "cpy",
    "dupl",
    "ddupl",
    "casti2f",
    "castf2i",
    "jmp",
    "jz",
    "jnz",
    "je",
    "jne",
    "ja",
    "jae",
    "jl",
    "jle",
    "iadd",
    "isub",
    "imul",
    "idiv",
    "imod",
    "iand",
    "ior",
    "ixor",
    "isal",
    "isar",
    "irol",
    "iror",
    "icom",
    "iinc",
    "idec",
    "fadd",
    "fsub",
    "fmul",
    "fdiv",
    "fmod",
    "ffma",
    "viquadadd",
    "viquadsub",
    "viquadmul",
    "viquaddiv",
    "viquadmod",
    "viquadand",
    "viquador",
    "viquadxor",
    "viquadsal",
    "viquadsar",
    "viquadrol",
    "viquadror",
    "viquadcom",
    "vfquadadd",
    "vfquadsub",
    "vfquadmul",
    "vfquaddiv",
    "vfquadmod",
    "vfquadfma",
    "vioctaadd",
    "vioctasub",
    "vioctamul",
    "vioctadiv",
    "vioctamod",
    "vioctaand",
    "vioctaor",
    "vioctaxor",
    "vioctasal",
    "vioctasar",
    "vioctarol",
    "vioctaror",
    "vioctacom",
    "vfoctaadd",
    "vfoctasub",
    "vfoctamul",
    "vfoctadiv",
    "vfoctamod",
    "vfoctafma",
    "vihexaadd",
    "vihexasub",
    "vihexamul",
    "vihexadiv",
    "vihexamod",
    "vihexaand",
    "vihexaor",
    "vihexaxor",
    "vihexasal",
    "vihexasar",
    "vihexarol",
    "vihexaror",
    "vihexacom",
    "vfhexaadd",
    "vfhexasub",
    "vfhexamul",
    "vfhexadiv",
    "vfhexamod",
    "vfhexafma",
];
