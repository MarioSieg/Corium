use super::signal::Signal;
use super::stream::Stream;
use crate::nominax::bci::Instruction;

#[derive(Clone, Debug)]
pub struct Emitter {
    pub stream: Stream,
    pub optimize: bool,
}

impl Emitter {
    pub fn emit_push(&mut self, val: Signal) {
        if !self.optimize {
            self.stream.push_instr(Instruction::PUSH);
            self.stream.push_back(val);
            return;
        }
        match val {
            Signal::Int(x) => {
                if x == 0 {
                    self.stream.push_instr(Instruction::PUSHZ);
                } else if x == 1 {
                    self.stream.push_instr(Instruction::IPUSHO);
                } else {
                    self.stream.push_instr(Instruction::PUSH);
                    self.stream.push_back(val);
                }
            }
            Signal::Float(x) => {
                if x == 0.0 {
                    self.stream.push_instr(Instruction::PUSHZ);
                } else if (x - 1.0).abs() < f64::EPSILON {
                    self.stream.push_instr(Instruction::FPUSHO);
                } else {
                    self.stream.push_instr(Instruction::PUSH);
                    self.stream.push_back(val);
                }
            }
            _ => {
                self.stream.push_instr(Instruction::PUSH);
                self.stream.push_back(val);
            }
        }
    }

    pub fn emit_pop(&mut self, mut count: u32) {
        if !self.optimize {
            for _ in 0..count {
                self.stream.push_instr(Instruction::POP);
            }
        }
        match count {
            0 => (),
            1 => {
                self.stream.push_instr(Instruction::POP);
            }
            2 => {
                self.stream.push_instr(Instruction::POP2);
            }
            4 => {
                self.stream.push_instr(Instruction::VPOP);
            }
            16 => {
                self.stream.push_instr(Instruction::MPOP);
            }
            _ => {
                // flatten
                while count > 0 {
                    if count >= 16 {
                        self.stream.push_instr(Instruction::MPOP);
                        count -= 16;
                    } else if count >= 4 {
                        self.stream.push_instr(Instruction::VPOP);
                        count -= 4;
                    } else if count >= 2 {
                        self.stream.push_instr(Instruction::POP2);
                        count -= 2;
                    } else {
                        self.stream.push_instr(Instruction::POP);
                        count -= 1;
                    }
                }
            }
        }
    }
}
