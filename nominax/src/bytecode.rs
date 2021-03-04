use super::registers::Register;

// (C) Copyright Mario Sieg <alias Kerbo, Pinsrq> <mt3000@gmx.de> 2021! All rights reserved!
// See LICENSE file for license information!

#[derive(Copy, Clone, Eq, PartialEq, Debug)]
#[repr(u32)]
pub enum Instruction {
    INT = 0x00_00_00_00,
    PANIC = 0x00_00_00_01,
    INTRIN = 0x00_00_00_02,
    CALL = 0x00_00_00_03,
    RET = 0x00_00_00_04,

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
