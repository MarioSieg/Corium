use super::{record::Record, stack::Stack};
use crate::bytecode::{ast::OpCode, chunk::BytecodeChunk, intrinsic::IntId};
use std::time::Instant;

/// Input data required for the VM executor to run.
pub struct ExecutorInput {
    pub stack: Stack,
    pub chunk: BytecodeChunk,
}

/// Output data coming from the VM executor after program execution finished.
pub struct ExecutorOutput {
    pub input: ExecutorInput,
    pub cycles: u64,
    pub exit_code: i32,
    pub interrupt_code: i32,
    pub time: f32,
}

/// Executes the bytecode.
/// Returns the interrupt id (exitcode) and the number of cycles.
pub fn execute(input: ExecutorInput) -> ExecutorOutput {
    assert!(input.stack.is_empty());
    assert!(!input.chunk.is_empty());
    assert!(input.chunk.length() < u32::MAX as _);
    assert_eq!(input.chunk.operation_ptr(), 0);
    assert_eq!(input.stack.stack_ptr(), 0);

    let clock = Instant::now();
    let mut command_buffer = input.chunk;
    let mut stack = input.stack;
    let mut cycles: u64 = 0;
    let mut interrupt: i32 = 0;

    loop {
        let opcode = command_buffer.fetch().into();
        cycles += 1;

        match opcode {
            OpCode::Int => {
                interrupt = command_buffer.fetch().into();
                if interrupt <= 0 {
                    break;
                } else {
                }
                continue;
            }

            OpCode::Intrin => {
                let intrin = command_buffer.fetch().into();
                match intrin {
                    IntId::PutChar => {
                        continue;
                    }
                    IntId::Flush => {}
                    IntId::Floor => {
                        impl_scalar_intrin!(stack, f32, floor);
                        continue;
                    }
                    IntId::Ceil => {
                        impl_scalar_intrin!(stack, f32, ceil);
                        continue;
                    }
                    IntId::Round => {
                        impl_scalar_intrin!(stack, f32, round);
                        continue;
                    }
                    IntId::Trunc => {
                        impl_scalar_intrin!(stack, f32, trunc);
                        continue;
                    }
                    IntId::Fract => {
                        impl_scalar_intrin!(stack, f32, fract);
                        continue;
                    }
                    IntId::Abs => {
                        impl_scalar_intrin!(stack, f32, abs);
                        continue;
                    }
                    IntId::Signum => {
                        impl_scalar_intrin!(stack, f32, signum);
                        continue;
                    }
                    IntId::Copysign => {
                        impl_duplet_intrin!(stack, f32, copysign);
                        continue;
                    }
                    IntId::DivEuclid => {
                        impl_duplet_intrin!(stack, f32, div_euclid);
                        continue;
                    }
                    IntId::RemEuclid => {
                        impl_duplet_intrin!(stack, f32, rem_euclid);
                        continue;
                    }
                    IntId::PowF => {
                        impl_duplet_intrin!(stack, f32, powf);
                        continue;
                    }
                    IntId::Sqrt => {
                        impl_scalar_intrin!(stack, f32, sqrt);
                        continue;
                    }
                    IntId::Exp => {
                        impl_scalar_intrin!(stack, f32, exp);
                        continue;
                    }
                    IntId::Exp2 => {
                        impl_scalar_intrin!(stack, f32, exp2);
                        continue;
                    }
                    IntId::Ln => {
                        impl_scalar_intrin!(stack, f32, ln);
                        continue;
                    }
                    IntId::Log => {
                        impl_duplet_intrin!(stack, f32, log);
                        continue;
                    }
                    IntId::Log2 => {
                        impl_scalar_intrin!(stack, f32, log2);
                        continue;
                    }
                    IntId::Log10 => {
                        impl_scalar_intrin!(stack, f32, log10);
                        continue;
                    }
                    IntId::Cbrt => {
                        impl_scalar_intrin!(stack, f32, cbrt);
                        continue;
                    }
                    IntId::Hypot => {
                        impl_duplet_intrin!(stack, f32, hypot);
                        continue;
                    }
                    IntId::Sin => {
                        impl_scalar_intrin!(stack, f32, sin);
                        continue;
                    }
                    IntId::Cos => {
                        impl_scalar_intrin!(stack, f32, cos);
                        continue;
                    }
                    IntId::Tan => {
                        impl_scalar_intrin!(stack, f32, tan);
                        continue;
                    }
                    IntId::Asin => {
                        impl_scalar_intrin!(stack, f32, asin);
                        continue;
                    }
                    IntId::Acos => {
                        impl_scalar_intrin!(stack, f32, acos);
                        continue;
                    }
                    IntId::Atan => {
                        impl_scalar_intrin!(stack, f32, atan);
                        continue;
                    }
                    IntId::Atan2 => {
                        impl_duplet_intrin!(stack, f32, atan2);
                        continue;
                    }
                    IntId::ExpM1 => {
                        impl_scalar_intrin!(stack, f32, exp_m1);
                        continue;
                    }
                    IntId::Ln1P => {
                        impl_scalar_intrin!(stack, f32, ln_1p);
                        continue;
                    }
                    IntId::SinH => {
                        impl_scalar_intrin!(stack, f32, sinh);
                        continue;
                    }
                    IntId::CosH => {
                        impl_scalar_intrin!(stack, f32, cosh);
                        continue;
                    }
                    IntId::TanH => {
                        impl_scalar_intrin!(stack, f32, tanh);
                        continue;
                    }
                    IntId::AsinH => {
                        impl_scalar_intrin!(stack, f32, asinh);
                        continue;
                    }
                    IntId::AcosH => {
                        impl_scalar_intrin!(stack, f32, acosh);
                        continue;
                    }
                    IntId::AtanH => {
                        impl_scalar_intrin!(stack, f32, atanh);
                        continue;
                    }
                    IntId::IsNan => {
                        continue;
                    }
                    IntId::IsInfinite => {
                        continue;
                    }
                    IntId::IsFinite => {
                        continue;
                    }
                    IntId::IsNormal => {
                        continue;
                    }
                    IntId::IsSignalPositive => {
                        continue;
                    }
                    IntId::IsSignalNegative => {
                        continue;
                    }
                    IntId::Recip => {
                        continue;
                    }
                    IntId::ToDegrees => {
                        continue;
                    }
                    IntId::ToRadians => {
                        continue;
                    }
                    IntId::Max => {
                        impl_duplet_intrin!(stack, f32, max);
                        continue;
                    }
                    IntId::Min => {
                        impl_duplet_intrin!(stack, f32, min);
                        continue;
                    }
                    _ => {
                        break;
                    }
                }
            }

            OpCode::Push => {
                stack.push(Record::from(command_buffer.fetch()));
                continue;
            }

            OpCode::Pop => {
                stack.pop_multi(command_buffer.fetch().into());
                continue;
            }

            OpCode::Mov => {
                stack.poke_set(
                    command_buffer.fetch().into(),
                    Record::from(command_buffer.fetch()),
                );
                continue;
            }

            OpCode::Cpy => {
                stack.poke_set(
                    command_buffer.fetch().into(),
                    stack.poke(command_buffer.fetch().into()),
                );
                continue;
            }

            OpCode::Nop => {
                continue;
            }

            OpCode::Dupl => {
                stack.push(stack.peek());
                continue;
            }

            OpCode::Ddupl => {
                stack.push(stack.peek());
                stack.push(stack.peek());
                continue;
            }

            OpCode::CastI2F => {
                stack.peek_set(Record::from(f32::from(stack.peek())));
                continue;
            }

            OpCode::CastF2I => {
                stack.peek_set(Record::from(i32::from(stack.peek())));
                continue;
            }

            OpCode::Jmp => {
                let target_address = command_buffer.fetch().into();
                command_buffer.jump(target_address);
                continue;
            }

            OpCode::Jz => {
                impl_scalar_con_jmp!(stack, command_buffer, ==, 0i32, i32);
                continue;
            }

            OpCode::Jnz => {
                impl_scalar_con_jmp!(stack, command_buffer, !=, 0i32, i32);
                continue;
            }

            OpCode::Je => {
                impl_duplet_con_jmp!(stack, command_buffer, ==, i32);
                continue;
            }

            OpCode::Jne => {
                impl_duplet_con_jmp!(stack, command_buffer, !=, i32);
                continue;
            }

            OpCode::Ja => {
                impl_duplet_con_jmp!(stack, command_buffer, >, i32);
                continue;
            }

            OpCode::Jae => {
                impl_duplet_con_jmp!(stack, command_buffer, >=, i32);
                continue;
            }

            OpCode::Jl => {
                impl_duplet_con_jmp!(stack, command_buffer, <, i32);
                continue;
            }

            OpCode::Jle => {
                impl_duplet_con_jmp!(stack, command_buffer, <=, i32);
                continue;
            }

            OpCode::Iadd => {
                impl_duplet_op_static!(stack, i32, wrapping_add);
                continue;
            }

            OpCode::Isub => {
                impl_duplet_op_static!(stack, i32, wrapping_sub);
                continue;
            }

            OpCode::Imul => {
                impl_duplet_op_static!(stack, i32, wrapping_mul);
                continue;
            }

            OpCode::Idiv => {
                impl_duplet_op_static!(stack, i32, wrapping_div);
                continue;
            }

            OpCode::Imod => {
                impl_duplet_op!(stack, i32, %);
                continue;
            }

            OpCode::Iand => {
                impl_duplet_op!(stack, i32, &);
                continue;
            }

            OpCode::Ior => {
                impl_duplet_op!(stack, i32, |);
                continue;
            }

            OpCode::Ixor => {
                impl_duplet_op!(stack, i32, ^);
                continue;
            }

            OpCode::Isal => {
                impl_duplet_op_static!(stack, i32, wrapping_shl);
                continue;
            }

            OpCode::Isar => {
                impl_duplet_op_static!(stack, i32, wrapping_shr);
                continue;
            }

            OpCode::Irol => {
                impl_duplet_op_static!(stack, i32, rotate_left);
                continue;
            }

            OpCode::Iror => {
                impl_duplet_op_static!(stack, i32, rotate_right);
                continue;
            }

            OpCode::Icom => {
                stack.peek_set(Record::from(!i32::from(stack.peek())));
                continue;
            }

            OpCode::Iinc => {
                impl_scalar_op!(stack, i32, +, 1);
                continue;
            }

            OpCode::Idec => {
                impl_scalar_op!(stack, i32, -, 1);
                continue;
            }

            OpCode::Fadd => {
                impl_duplet_op!(stack, f32, +);
                continue;
            }

            OpCode::Fsub => {
                impl_duplet_op!(stack, f32, -);
                continue;
            }

            OpCode::Fmul => {
                impl_duplet_op!(stack, f32, *);
                continue;
            }

            OpCode::Fdiv => {
                impl_duplet_op!(stack, f32, /);
                continue;
            }

            OpCode::Fmod => {
                impl_duplet_op!(stack, f32, %);
                continue;
            }

            OpCode::Ffma => {
                stack.poke_set(
                    2,
                    Record::from(
                        f32::from(stack.poke(2)).mul_add(stack.poke(1).into(), stack.peek().into()),
                    ),
                );
                stack.pop_multi(2);
                continue;
            }

            OpCode::Viquadadd => {
                impl_vector_op!(stack, i32, __add4_slice, i32, 4);
                continue;
            }

            OpCode::Viquadsub => {
                impl_vector_op!(stack, i32, __sub4_slice, i32, 4);
                continue;
            }

            OpCode::Viquadmul => {
                impl_vector_op!(stack, i32, __mul4_slice, i32, 4);
                continue;
            }

            OpCode::Viquaddiv => {
                impl_vector_op!(stack, i32, __div4_slice, i32, 4);
                continue;
            }

            OpCode::Viquadmod => {
                impl_vector_op!(stack, i32, __mod4_slice, i32, 4);
                continue;
            }

            OpCode::Viquadand => {
                impl_vector_op!(stack, i32, __and4_slice, i32, 4);
                continue;
            }

            OpCode::Viquador => {
                impl_vector_op!(stack, i32, __or4_slice, i32, 4);
                continue;
            }

            OpCode::Viquadxor => {
                impl_vector_op!(stack, i32, __xor4_slice, i32, 4);
                continue;
            }

            OpCode::Viquadsal => {
                impl_vector_op!(stack, i32, __sal4_slice, i32, 4);
                continue;
            }

            OpCode::Viquadsar => {
                impl_vector_op!(stack, i32, __sar4_slice, i32, 4);
                continue;
            }

            OpCode::Viquadrol => {
                impl_vector_op!(stack, i32, __rol4_slice, i32, 4);
                continue;
            }

            OpCode::Viquadror => {
                impl_vector_op!(stack, i32, __ror4_slice, i32, 4);
                continue;
            }

            OpCode::Viquadcom => {}

            OpCode::Vfquadadd => {
                impl_vector_op!(stack, f32, __add4_slice, f32, 4);
                continue;
            }

            OpCode::Vfquadsub => {
                impl_vector_op!(stack, f32, __sub4_slice, f32, 4);
                continue;
            }

            OpCode::Vfquadmul => {
                impl_vector_op!(stack, f32, __mul4_slice, f32, 4);
                continue;
            }

            OpCode::Vfquaddiv => {
                impl_vector_op!(stack, f32, __div4_slice, f32, 4);
                continue;
            }

            OpCode::Vfquadmod => {
                impl_vector_op!(stack, f32, __mod4_slice, f32, 4);
                continue;
            }

            OpCode::Vfquadfma => {
                impl_fma_vector_op!(stack, f32, __fma4_slice, f32, 4);
            }

            OpCode::Vioctaadd => {
                impl_vector_op!(stack, i32, __add8_slice, i32, 8);
                continue;
            }

            OpCode::Vioctasub => {
                impl_vector_op!(stack, i32, __sub8_slice, i32, 8);
                continue;
            }

            OpCode::Vioctamul => {
                impl_vector_op!(stack, i32, __mul8_slice, i32, 8);
                continue;
            }

            OpCode::Vioctadiv => {
                impl_vector_op!(stack, i32, __div8_slice, i32, 8);
                continue;
            }

            OpCode::Vioctamod => {
                impl_vector_op!(stack, i32, __mod8_slice, i32, 8);
                continue;
            }

            OpCode::Vioctaand => {
                impl_vector_op!(stack, i32, __and8_slice, i32, 8);
                continue;
            }

            OpCode::Vioctaor => {
                impl_vector_op!(stack, i32, __or8_slice, i32, 8);
                continue;
            }

            OpCode::Vioctaxor => {
                impl_vector_op!(stack, i32, __xor8_slice, i32, 8);
                continue;
            }

            OpCode::Vioctasal => {
                impl_vector_op!(stack, i32, __sal8_slice, i32, 8);
                continue;
            }

            OpCode::Vioctasar => {
                impl_vector_op!(stack, i32, __sar8_slice, i32, 8);
                continue;
            }

            OpCode::Vioctarol => {
                impl_vector_op!(stack, i32, __rol8_slice, i32, 8);
                continue;
            }

            OpCode::Vioctaror => {
                impl_vector_op!(stack, i32, __ror8_slice, i32, 8);
                continue;
            }

            OpCode::Vioctacom => {}

            OpCode::Vfoctaadd => {
                impl_vector_op!(stack, f32, __add8_slice, f32, 8);
                continue;
            }

            OpCode::Vfoctasub => {
                impl_vector_op!(stack, f32, __sub8_slice, f32, 8);
                continue;
            }

            OpCode::Vfoctamul => {
                impl_vector_op!(stack, f32, __mul8_slice, f32, 8);
                continue;
            }

            OpCode::Vfoctadiv => {
                impl_vector_op!(stack, f32, __div8_slice, f32, 8);
                continue;
            }

            OpCode::Vfoctamod => {
                impl_vector_op!(stack, f32, __mod8_slice, f32, 8);
                continue;
            }

            OpCode::Vfoctafma => {
                impl_fma_vector_op!(stack, f32, __fma8_slice, f32, 8);
            }

            OpCode::Vihexaadd => {
                impl_vector_op!(stack, i32, __add16_slice, i32, 16);
                continue;
            }

            OpCode::Vihexasub => {
                impl_vector_op!(stack, i32, __sub16_slice, i32, 16);
                continue;
            }

            OpCode::Vihexamul => {
                impl_vector_op!(stack, i32, __mul16_slice, i32, 16);
                continue;
            }

            OpCode::Vihexadiv => {
                impl_vector_op!(stack, i32, __div16_slice, i32, 16);
                continue;
            }

            OpCode::Vihexamod => {
                impl_vector_op!(stack, i32, __mod16_slice, i32, 16);
                continue;
            }

            OpCode::Vihexaand => {
                impl_vector_op!(stack, i32, __and16_slice, i32, 16);
                continue;
            }

            OpCode::Vihexaor => {
                impl_vector_op!(stack, i32, __or16_slice, i32, 16);
                continue;
            }

            OpCode::Vihexaxor => {
                impl_vector_op!(stack, i32, __xor16_slice, i32, 16);
                continue;
            }

            OpCode::Vihexasal => {
                impl_vector_op!(stack, i32, __sal16_slice, i32, 16);
                continue;
            }

            OpCode::Vihexasar => {
                impl_vector_op!(stack, i32, __sar16_slice, i32, 16);
                continue;
            }

            OpCode::Vihexarol => {
                impl_vector_op!(stack, i32, __rol16_slice, i32, 16);
                continue;
            }

            OpCode::Vihexaror => {
                impl_vector_op!(stack, i32, __ror16_slice, i32, 16);
                continue;
            }

            OpCode::Vihexacom => {}

            OpCode::Vfhexaadd => {
                impl_vector_op!(stack, f32, __add16_slice, f32, 16);
                continue;
            }

            OpCode::Vfhexasub => {
                impl_vector_op!(stack, f32, __sub16_slice, f32, 16);
                continue;
            }

            OpCode::Vfhexamul => {
                impl_vector_op!(stack, f32, __mul16_slice, f32, 16);
                continue;
            }

            OpCode::Vfhexadiv => {
                impl_vector_op!(stack, f32, __div16_slice, f32, 16);
                continue;
            }

            OpCode::Vfhexamod => {
                impl_vector_op!(stack, f32, __mod16_slice, f32, 16);
                continue;
            }

            OpCode::Vfhexafma => {
                impl_fma_vector_op!(stack, f32, __fma16_slice, f32, 16);
            }

            _ => {
                break;
            }
        }
    }

    ExecutorOutput {
        input: ExecutorInput {
            stack,
            chunk: command_buffer,
        },
        cycles,
        exit_code: interrupt,
        interrupt_code: interrupt,
        time: clock.elapsed().as_secs_f32(),
    }
}

#[cfg(test)]
mod tests {
    use super::{execute, ExecutorInput};
    use crate::bytecode::{
        ast::{
            OpCode::{self, *},
            Token,
        },
        intrinsic::IntId,
        stream::BytecodeStream,
    };
    use crate::core::stack::Stack;

    #[test]
    fn memory_dupl_ddupl() {
        let mut stream = BytecodeStream::new();
        stream.push(Token::Opc(Push)).push(Token::I32(3));
        stream.push(Token::Opc(Dupl));
        stream.push(Token::Opc(Ddupl));
        stream.push(Token::Opc(Int)).push(Token::I32(0));
        let input = ExecutorInput {
            stack: Stack::with_length(4),
            chunk: stream.build(),
        };
        let stack = execute(input).input.stack;
        assert_eq!(i32::from(stack.poke(3)), 3);
        assert_eq!(i32::from(stack.poke(2)), 3);
        assert_eq!(i32::from(stack.poke(1)), 3);
        assert_eq!(i32::from(stack.poke(0)), 3);
    }

    #[test]
    fn memory_mov_cpy() {
        let mut stream = BytecodeStream::new();
        stream.push(Token::Opc(Push)).push(Token::I32(3));
        stream.push(Token::Opc(Push)).push(Token::I32(7));
        stream.push(Token::Opc(Push)).push(Token::I32(5));
        stream
            .push(Token::Opc(Mov))
            .push(Token::I32(1))
            .push(Token::I32(-4));
        stream
            .push(Token::Opc(Cpy))
            .push(Token::I32(0))
            .push(Token::I32(1));
        stream.push(Token::Opc(Int)).push(Token::I32(0));
        let input = ExecutorInput {
            stack: Stack::with_length(3),
            chunk: stream.build(),
        };
        let stack = execute(input).input.stack;
        assert_eq!(i32::from(stack.poke(1)), -4);
        assert_eq!(i32::from(stack.peek()), -4);
    }

    #[test]
    fn memory_push_pop() {
        let mut stream = BytecodeStream::new();
        for i in 0..4096 {
            stream.push(Token::Opc(Push)).push(Token::I32(i));
        }
        stream.push(Token::Opc(Pop)).push(Token::I32(2048));
        stream.push(Token::Opc(Int)).push(Token::I32(0));
        let input = ExecutorInput {
            stack: Stack::with_length(8192),
            chunk: stream.build(),
        };
        let stack = execute(input).input.stack;
        assert_eq!(i32::from(stack.peek()), 2047);
    }

    #[test]
    fn control_intrinsic() {
        let mut stream = BytecodeStream::new();
        stream.push(Token::Opc(Push)).push(Token::F32(0.5236));
        stream.push(Token::Opc(Intrin)).push(Token::Int(IntId::Sin));
        stream.push(Token::Opc(Int)).push(Token::I32(0));
        let input = ExecutorInput {
            stack: Stack::with_length(1),
            chunk: stream.build(),
        };
        let stack = execute(input).input.stack;
        assert!(f32::from(stack.peek()) - 0.5 < 0.00001);
    }

    #[test]
    fn control_interrupt() {
        let mut stream = BytecodeStream::new();
        stream.push(Token::Opc(Push)).push(Token::I32(0));
        stream.push(Token::Opc(Int)).push(Token::I32(0));
        stream.push(Token::Opc(Push)).push(Token::I32(0));
        let input = ExecutorInput {
            stack: Stack::with_length(2),
            chunk: stream.build(),
        };
        let chunk = execute(input).input.chunk;
        assert_eq!(chunk.operation_ptr(), 7);
    }

    fn test_i32op_template(op: OpCode, a: i32, b: i32, x: i32) {
        let mut stream = BytecodeStream::new();
        stream.push(Token::Opc(Push)).push(Token::I32(a));
        stream.push(Token::Opc(Push)).push(Token::I32(b));
        stream.push(Token::Opc(op));
        stream.push(Token::Opc(Int)).push(Token::I32(0));
        let input = ExecutorInput {
            stack: Stack::with_length(2),
            chunk: stream.build(),
        };
        let stack = execute(input).input.stack;
        if a != b {
            assert_eq!(stack.stack_ptr(), 1);
        }
        assert_eq!(i32::from(stack.peek()), x);
    }

    fn test_f32op_template(op: OpCode, a: f32, b: f32, x: f32) {
        let mut stream = BytecodeStream::new();
        stream.push(Token::Opc(Push)).push(Token::F32(a));
        stream.push(Token::Opc(Push)).push(Token::F32(b));
        stream.push(Token::Opc(op));
        stream.push(Token::Opc(Int)).push(Token::I32(0));
        let input = ExecutorInput {
            stack: Stack::with_length(4),
            chunk: stream.build(),
        };
        let stack = execute(input).input.stack;
        assert_eq!(stack.stack_ptr(), 1);
        assert_eq!(f32::from(stack.peek()), x);
    }

    #[test]
    fn arithmetic_f32_add() {
        test_f32op_template(OpCode::Fadd, 3.5, 2.5, 6.0);
    }

    #[test]
    fn arithmetic_f32_sub() {
        test_f32op_template(OpCode::Fsub, 3.5, 2.5, 1.0);
    }

    #[test]
    fn arithmetic_f32_mul() {
        test_f32op_template(OpCode::Fmul, 3.5, 2.5, 8.75);
    }

    #[test]
    fn arithmetic_f32_div() {
        test_f32op_template(OpCode::Fdiv, 3.5, 2.5, 1.4);
    }

    #[test]
    fn arithmetic_f32_mod() {
        test_f32op_template(OpCode::Fmod, 3.5, 2.5, 1.0);
    }

    #[test]
    fn arithmetic_f32_fma() {
        let mut stream = BytecodeStream::new();
        stream.push(Token::Opc(Push)).push(Token::F32(2.0));
        stream.push(Token::Opc(Push)).push(Token::F32(3.0));
        stream.push(Token::Opc(Push)).push(Token::F32(4.0));
        stream.push(Token::Opc(Ffma));
        stream.push(Token::Opc(Int)).push(Token::I32(0));
        let input = ExecutorInput {
            stack: Stack::with_length(4),
            chunk: stream.build(),
        };
        let stack = execute(input).input.stack;
        assert_eq!(stack.stack_ptr(), 1);
        assert_eq!(f32::from(stack.peek()), 10.0);
    }

    #[test]
    fn arithmetic_i32_add() {
        test_i32op_template(OpCode::Iadd, 8, 4, 12);
    }

    #[test]
    fn arithmetic_i32_sub() {
        test_i32op_template(OpCode::Isub, 8, 4, 4);
    }

    #[test]
    fn arithmetic_i32_mul() {
        test_i32op_template(OpCode::Imul, 8, 4, 32);
    }

    #[test]
    fn arithmetic_i32_div() {
        test_i32op_template(OpCode::Idiv, 8, 4, 2);
    }

    #[test]
    fn arithmetic_i32_mod() {
        test_i32op_template(OpCode::Imod, 8, 5, 3);
    }

    #[test]
    fn arithmetic_i32_and() {
        test_i32op_template(OpCode::Iand, 2, 3, 2);
    }

    #[test]
    fn arithmetic_i32_or() {
        test_i32op_template(OpCode::Ior, 2, 8, 10);
    }

    #[test]
    fn arithmetic_i32_xor() {
        test_i32op_template(OpCode::Ixor, 9, 9, 0);
    }

    #[test]
    fn arithmetic_i32_sal() {
        test_i32op_template(OpCode::Isal, 1, 8, 256);
    }

    #[test]
    fn arithmetic_i32_sar() {
        test_i32op_template(OpCode::Isar, 8, 1, 4);
    }

    #[test]
    fn arithmetic_i32_rol() {
        test_i32op_template(OpCode::Irol, 4, 64, 4);
    }

    #[test]
    fn arithmetic_i32_ror() {
        test_i32op_template(OpCode::Iror, 64, 4, 4);
    }

    #[test]
    fn arithmetic_i32_com() {
        test_i32op_template(OpCode::Icom, 8, 8, -9);
    }

    #[test]
    fn arithmetic_i32_inc() {
        test_i32op_template(OpCode::Iinc, 0, 0, 1);
    }

    #[test]
    fn arithmetic_i32_dec() {
        test_i32op_template(OpCode::Idec, 1, 1, 0);
    }

    #[test]
    fn simd_vquadiadd() {
        let mut stream = BytecodeStream::new();
        stream.push(Token::Opc(Push)).push(Token::I32(2));
        stream.push(Token::Opc(Push)).push(Token::I32(5));
        stream.push(Token::Opc(Push)).push(Token::I32(1));
        stream.push(Token::Opc(Push)).push(Token::I32(-3));

        stream.push(Token::Opc(Push)).push(Token::I32(4));
        stream.push(Token::Opc(Push)).push(Token::I32(2));
        stream.push(Token::Opc(Push)).push(Token::I32(9));
        stream.push(Token::Opc(Push)).push(Token::I32(2));
        stream.push(Token::Opc(Viquadadd));

        let input = ExecutorInput {
            stack: Stack::with_length(32),
            chunk: stream.build(),
        };
        let stack = execute(input).input.stack;
        assert_eq!(i32::from(stack[1]), 6);
        assert_eq!(i32::from(stack[2]), 7);
        assert_eq!(i32::from(stack[3]), 10);
        assert_eq!(i32::from(stack[4]), -1);
        assert_eq!(stack.stack_ptr(), 4);
    }

    #[test]
    fn simd_vquadisub() {
        let mut stream = BytecodeStream::new();
        stream.push(Token::Opc(Push)).push(Token::I32(2));
        stream.push(Token::Opc(Push)).push(Token::I32(5));
        stream.push(Token::Opc(Push)).push(Token::I32(1));
        stream.push(Token::Opc(Push)).push(Token::I32(-3));

        stream.push(Token::Opc(Push)).push(Token::I32(4));
        stream.push(Token::Opc(Push)).push(Token::I32(2));
        stream.push(Token::Opc(Push)).push(Token::I32(9));
        stream.push(Token::Opc(Push)).push(Token::I32(2));
        stream.push(Token::Opc(Viquadsub));

        let input = ExecutorInput {
            stack: Stack::with_length(32),
            chunk: stream.build(),
        };
        let stack = execute(input).input.stack;
        assert_eq!(i32::from(stack[1]), -2);
        assert_eq!(i32::from(stack[2]), 3);
        assert_eq!(i32::from(stack[3]), -8);
        assert_eq!(i32::from(stack[4]), -5);
        assert_eq!(stack.stack_ptr(), 4);
    }

    #[test]
    fn simd_vquadimul() {
        let mut stream = BytecodeStream::new();
        stream.push(Token::Opc(Push)).push(Token::I32(2));
        stream.push(Token::Opc(Push)).push(Token::I32(5));
        stream.push(Token::Opc(Push)).push(Token::I32(1));
        stream.push(Token::Opc(Push)).push(Token::I32(-3));

        stream.push(Token::Opc(Push)).push(Token::I32(4));
        stream.push(Token::Opc(Push)).push(Token::I32(2));
        stream.push(Token::Opc(Push)).push(Token::I32(9));
        stream.push(Token::Opc(Push)).push(Token::I32(2));
        stream.push(Token::Opc(Viquadmul));

        let input = ExecutorInput {
            stack: Stack::with_length(32),
            chunk: stream.build(),
        };
        let stack = execute(input).input.stack;
        assert_eq!(i32::from(stack[1]), 8);
        assert_eq!(i32::from(stack[2]), 10);
        assert_eq!(i32::from(stack[3]), 9);
        assert_eq!(i32::from(stack[4]), -6);
        assert_eq!(stack.stack_ptr(), 4);
    }

    #[test]
    fn simd_vquadidiv() {
        let mut stream = BytecodeStream::new();
        stream.push(Token::Opc(Push)).push(Token::I32(40));
        stream.push(Token::Opc(Push)).push(Token::I32(5));
        stream.push(Token::Opc(Push)).push(Token::I32(1));
        stream.push(Token::Opc(Push)).push(Token::I32(-3));

        stream.push(Token::Opc(Push)).push(Token::I32(10));
        stream.push(Token::Opc(Push)).push(Token::I32(2));
        stream.push(Token::Opc(Push)).push(Token::I32(9));
        stream.push(Token::Opc(Push)).push(Token::I32(2));
        stream.push(Token::Opc(Viquaddiv));

        let input = ExecutorInput {
            stack: Stack::with_length(32),
            chunk: stream.build(),
        };
        let stack = execute(input).input.stack;
        assert_eq!(i32::from(stack[1]), 4);
        assert_eq!(i32::from(stack[2]), 2);
        assert_eq!(i32::from(stack[3]), 0);
        assert_eq!(i32::from(stack[4]), -1);
        assert_eq!(stack.stack_ptr(), 4);
    }

    #[test]
    fn simd_vquadimod() {
        let mut stream = BytecodeStream::new();
        stream.push(Token::Opc(Push)).push(Token::I32(40));
        stream.push(Token::Opc(Push)).push(Token::I32(5));
        stream.push(Token::Opc(Push)).push(Token::I32(1));
        stream.push(Token::Opc(Push)).push(Token::I32(-3));

        stream.push(Token::Opc(Push)).push(Token::I32(4));
        stream.push(Token::Opc(Push)).push(Token::I32(2));
        stream.push(Token::Opc(Push)).push(Token::I32(9));
        stream.push(Token::Opc(Push)).push(Token::I32(2));
        stream.push(Token::Opc(Viquadmod));

        let input = ExecutorInput {
            stack: Stack::with_length(32),
            chunk: stream.build(),
        };
        let stack = execute(input).input.stack;
        assert_eq!(i32::from(stack[1]), 0);
        assert_eq!(i32::from(stack[2]), 1);
        assert_eq!(i32::from(stack[3]), 1);
        assert_eq!(i32::from(stack[4]), -1);
        assert_eq!(stack.stack_ptr(), 4);
    }

    #[test]
    fn simd_vquadiand() {
        let mut stream = BytecodeStream::new();
        stream.push(Token::Opc(Push)).push(Token::I32(2));
        stream.push(Token::Opc(Push)).push(Token::I32(5));
        stream.push(Token::Opc(Push)).push(Token::I32(1));
        stream.push(Token::Opc(Push)).push(Token::I32(-3));

        stream.push(Token::Opc(Push)).push(Token::I32(4));
        stream.push(Token::Opc(Push)).push(Token::I32(2));
        stream.push(Token::Opc(Push)).push(Token::I32(9));
        stream.push(Token::Opc(Push)).push(Token::I32(2));
        stream.push(Token::Opc(Viquadand));

        let input = ExecutorInput {
            stack: Stack::with_length(32),
            chunk: stream.build(),
        };
        let stack = execute(input).input.stack;
        assert_eq!(i32::from(stack[1]), 0);
        assert_eq!(i32::from(stack[2]), 0);
        assert_eq!(i32::from(stack[3]), 1);
        assert_eq!(i32::from(stack[4]), 0);
        assert_eq!(stack.stack_ptr(), 4);
    }

    #[test]
    fn simd_vquadior() {
        let mut stream = BytecodeStream::new();
        stream.push(Token::Opc(Push)).push(Token::I32(2));
        stream.push(Token::Opc(Push)).push(Token::I32(5));
        stream.push(Token::Opc(Push)).push(Token::I32(1));
        stream.push(Token::Opc(Push)).push(Token::I32(-3));

        stream.push(Token::Opc(Push)).push(Token::I32(4));
        stream.push(Token::Opc(Push)).push(Token::I32(2));
        stream.push(Token::Opc(Push)).push(Token::I32(9));
        stream.push(Token::Opc(Push)).push(Token::I32(2));
        stream.push(Token::Opc(Viquador));

        let input = ExecutorInput {
            stack: Stack::with_length(32),
            chunk: stream.build(),
        };
        let stack = execute(input).input.stack;
        assert_eq!(i32::from(stack[1]), 6);
        assert_eq!(i32::from(stack[2]), 7);
        assert_eq!(i32::from(stack[3]), 9);
        assert_eq!(i32::from(stack[4]), -1);
        assert_eq!(stack.stack_ptr(), 4);
    }

    #[test]
    fn simd_vquadixor() {
        let mut stream = BytecodeStream::new();
        stream.push(Token::Opc(Push)).push(Token::I32(2));
        stream.push(Token::Opc(Push)).push(Token::I32(5));
        stream.push(Token::Opc(Push)).push(Token::I32(1));
        stream.push(Token::Opc(Push)).push(Token::I32(-3));

        stream.push(Token::Opc(Push)).push(Token::I32(4));
        stream.push(Token::Opc(Push)).push(Token::I32(2));
        stream.push(Token::Opc(Push)).push(Token::I32(9));
        stream.push(Token::Opc(Push)).push(Token::I32(2));
        stream.push(Token::Opc(Viquadxor));

        let input = ExecutorInput {
            stack: Stack::with_length(32),
            chunk: stream.build(),
        };
        let stack = execute(input).input.stack;
        assert_eq!(i32::from(stack[1]), 6);
        assert_eq!(i32::from(stack[2]), 7);
        assert_eq!(i32::from(stack[3]), 8);
        assert_eq!(i32::from(stack[4]), -1);
        assert_eq!(stack.stack_ptr(), 4);
    }

    #[test]
    fn simd_vquadisal() {
        let mut stream = BytecodeStream::new();
        stream.push(Token::Opc(Push)).push(Token::I32(2));
        stream.push(Token::Opc(Push)).push(Token::I32(5));
        stream.push(Token::Opc(Push)).push(Token::I32(1));
        stream.push(Token::Opc(Push)).push(Token::I32(-3));

        stream.push(Token::Opc(Push)).push(Token::I32(4));
        stream.push(Token::Opc(Push)).push(Token::I32(2));
        stream.push(Token::Opc(Push)).push(Token::I32(9));
        stream.push(Token::Opc(Push)).push(Token::I32(2));
        stream.push(Token::Opc(Viquadsal));

        let input = ExecutorInput {
            stack: Stack::with_length(32),
            chunk: stream.build(),
        };
        let stack = execute(input).input.stack;
        assert_eq!(i32::from(stack[1]), 32);
        assert_eq!(i32::from(stack[2]), 20);
        assert_eq!(i32::from(stack[3]), 512);
        assert_eq!(i32::from(stack[4]), -12);
        assert_eq!(stack.stack_ptr(), 4);
    }

    #[test]
    fn simd_vquadisar() {
        let mut stream = BytecodeStream::new();
        stream.push(Token::Opc(Push)).push(Token::I32(2));
        stream.push(Token::Opc(Push)).push(Token::I32(5));
        stream.push(Token::Opc(Push)).push(Token::I32(1));
        stream.push(Token::Opc(Push)).push(Token::I32(-3));

        stream.push(Token::Opc(Push)).push(Token::I32(4));
        stream.push(Token::Opc(Push)).push(Token::I32(2));
        stream.push(Token::Opc(Push)).push(Token::I32(9));
        stream.push(Token::Opc(Push)).push(Token::I32(2));
        stream.push(Token::Opc(Viquadsar));

        let input = ExecutorInput {
            stack: Stack::with_length(32),
            chunk: stream.build(),
        };
        let stack = execute(input).input.stack;
        assert_eq!(i32::from(stack[1]), 0);
        assert_eq!(i32::from(stack[2]), 1);
        assert_eq!(i32::from(stack[3]), 0);
        assert_eq!(i32::from(stack[4]), -1);
        assert_eq!(stack.stack_ptr(), 4);
    }

    #[test]
    fn simd_vquadirol() {
        let mut stream = BytecodeStream::new();
        stream.push(Token::Opc(Push)).push(Token::I32(2));
        stream.push(Token::Opc(Push)).push(Token::I32(5));
        stream.push(Token::Opc(Push)).push(Token::I32(2000000000));
        stream.push(Token::Opc(Push)).push(Token::I32(-3));

        stream.push(Token::Opc(Push)).push(Token::I32(4));
        stream.push(Token::Opc(Push)).push(Token::I32(2));
        stream.push(Token::Opc(Push)).push(Token::I32(9));
        stream.push(Token::Opc(Push)).push(Token::I32(2));
        stream.push(Token::Opc(Viquadrol));

        let input = ExecutorInput {
            stack: Stack::with_length(32),
            chunk: stream.build(),
        };
        let stack = execute(input).input.stack;
        assert_eq!(i32::from(stack[1]), 32);
        assert_eq!(i32::from(stack[2]), 20);
        assert_eq!(i32::from(stack[3]), 1797783790);
        assert_eq!(i32::from(stack[4]), -9);
        assert_eq!(stack.stack_ptr(), 4);
    }

    #[test]
    fn simd_vquadiror() {
        let mut stream = BytecodeStream::new();
        stream.push(Token::Opc(Push)).push(Token::I32(2));
        stream.push(Token::Opc(Push)).push(Token::I32(5));
        stream.push(Token::Opc(Push)).push(Token::I32(1));
        stream.push(Token::Opc(Push)).push(Token::I32(-3));

        stream.push(Token::Opc(Push)).push(Token::I32(4));
        stream.push(Token::Opc(Push)).push(Token::I32(2));
        stream.push(Token::Opc(Push)).push(Token::I32(9));
        stream.push(Token::Opc(Push)).push(Token::I32(2));
        stream.push(Token::Opc(Viquadror));

        let input = ExecutorInput {
            stack: Stack::with_length(32),
            chunk: stream.build(),
        };
        let stack = execute(input).input.stack;
        assert_eq!(i32::from(stack[1]), 536870912);
        assert_eq!(i32::from(stack[2]), 1073741825);
        assert_eq!(i32::from(stack[3]), 8388608);
        assert_eq!(i32::from(stack[4]), 2147483647);
        assert_eq!(stack.stack_ptr(), 4);
    }
}
