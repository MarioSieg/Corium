// (C) Copyright Mario Sieg <alias Kerbo, Pinsrq> <mt3000@gmx.de> 2021! All rights reserved!
// See LICENSE file for license information!

use super::registers::Register;

#[derive(Copy, Clone, Eq, PartialEq, Debug)]
#[repr(u32)]
pub enum Instruction {
    INT = 0x00,
    PANIC = 0x01,
    INTRIN = 0x02,
    CALL = 0x03,
    RET = 0x04,

    Count,
}

pub enum Token {
    Instruction(Instruction),
    ImmediateU32(u32),
    ImmediateI32(i32),
    ImmediateF32(f32),
    Register(Register),
    Label(String),
    LabelDefinition(String),
}

pub mod syntax {
    pub const COMMENT: char = '/';
    pub const SEPARATOR: char = ',';
    pub const IMMEDIATE: char = '$';
    pub const REGISTER_READ_ACCESS: char = '%';
    pub const REGISTER_WRITE_ACCESS: char = '&';
    pub const JUMP: char = '*';
    pub const ABSOLUTE: char = ':';
    pub const LABEL: char = '@';
    pub const REGISTER_RANGE: &str = "...";
    pub const PREPROCESSOR: char = '#';
}

#[cfg(test)]
mod tests {
    const IR_SNIPPER: &str = r#"
        sto &r0, $0
        sto &r1, $10
    @begin:
        cmp %r0, %r1
        je *@end
        inc &r0
    @end:
        xor &r0...&r4
        panic
    "#;
}
