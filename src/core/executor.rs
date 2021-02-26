use crate::{
    bytecode::{ast::OpCode, chunk::BytecodeChunk, intrinsic::IntId},
    core::{record::Record, stack::Stack},
};
use std::time::Instant;

/// Input data required for the VM executor to run.
pub struct ExecutorInput {
    pub fixed: Option<u64>,
    pub stack: Stack,
    pub chunk: BytecodeChunk,
}

/// Output data coming from the VM executor after program execution finished.
pub struct ExecutorOutput {
    pub input: ExecutorInput,
    pub cycles: u64,
    pub exit_code: i32,
    pub interrupt_code: i32,
    pub time: f64,
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
    let fixed = input.fixed.unwrap_or(u64::MAX);
    let mut stdout = String::with_capacity(16);
    let mut command_buffer = input.chunk;
    let mut stack = input.stack;
    let mut cycles: u64 = 0;
    let mut interrupt: i32 = 0;

    'vm: while cycles < fixed {
        let opcode = command_buffer.fetch().into();
        cycles += 1;

        match opcode {
            OpCode::Interrupt => {
                interrupt = command_buffer.fetch().into();
                if interrupt <= 0 {
                    break 'vm;
                } else {
                }
                continue 'vm;
            }

            OpCode::CallIntrinsic => {
                let intrin = command_buffer.fetch().into();
                match intrin {
                    IntId::PutChar => {
                        stdout.push(char::from(stack.peek()));
                        stack.pop();
                        continue 'vm;
                    }
                    IntId::Flush => {
                        print!("{}", stdout);
                        stdout.clear();
                    }
                    IntId::Floor => {
                        impl_scalar_intrin!(stack, f32, floor);
                        continue 'vm;
                    }
                    IntId::Ceil => {
                        impl_scalar_intrin!(stack, f32, ceil);
                        continue 'vm;
                    }
                    IntId::Round => {
                        impl_scalar_intrin!(stack, f32, round);
                        continue 'vm;
                    }
                    IntId::Trunc => {
                        impl_scalar_intrin!(stack, f32, trunc);
                        continue 'vm;
                    }
                    IntId::Fract => {
                        impl_scalar_intrin!(stack, f32, fract);
                        continue 'vm;
                    }
                    IntId::Abs => {
                        impl_scalar_intrin!(stack, f32, abs);
                        continue 'vm;
                    }
                    IntId::Signum => {
                        impl_scalar_intrin!(stack, f32, signum);
                        continue 'vm;
                    }
                    IntId::Copysign => {
                        impl_duplet_intrin!(stack, f32, copysign);
                        continue 'vm;
                    }
                    IntId::DivEuclid => {
                        impl_duplet_intrin!(stack, f32, div_euclid);
                        continue 'vm;
                    }
                    IntId::RemEuclid => {
                        impl_duplet_intrin!(stack, f32, rem_euclid);
                        continue 'vm;
                    }
                    IntId::PowF => {
                        impl_duplet_intrin!(stack, f32, powf);
                        continue 'vm;
                    }
                    IntId::Sqrt => {
                        impl_scalar_intrin!(stack, f32, sqrt);
                        continue 'vm;
                    }
                    IntId::Exp => {
                        impl_scalar_intrin!(stack, f32, exp);
                        continue 'vm;
                    }
                    IntId::Exp2 => {
                        impl_scalar_intrin!(stack, f32, exp2);
                        continue 'vm;
                    }
                    IntId::Ln => {
                        impl_scalar_intrin!(stack, f32, ln);
                        continue 'vm;
                    }
                    IntId::Log => {
                        impl_duplet_intrin!(stack, f32, log);
                        continue 'vm;
                    }
                    IntId::Log2 => {
                        impl_scalar_intrin!(stack, f32, log2);
                        continue 'vm;
                    }
                    IntId::Log10 => {
                        impl_scalar_intrin!(stack, f32, log10);
                        continue 'vm;
                    }
                    IntId::Cbrt => {
                        impl_scalar_intrin!(stack, f32, cbrt);
                        continue 'vm;
                    }
                    IntId::Hypot => {
                        impl_duplet_intrin!(stack, f32, hypot);
                        continue 'vm;
                    }
                    IntId::Sin => {
                        impl_scalar_intrin!(stack, f32, sin);
                        continue 'vm;
                    }
                    IntId::Cos => {
                        impl_scalar_intrin!(stack, f32, cos);
                        continue 'vm;
                    }
                    IntId::Tan => {
                        impl_scalar_intrin!(stack, f32, tan);
                        continue 'vm;
                    }
                    IntId::Asin => {
                        impl_scalar_intrin!(stack, f32, asin);
                        continue 'vm;
                    }
                    IntId::Acos => {
                        impl_scalar_intrin!(stack, f32, acos);
                        continue 'vm;
                    }
                    IntId::Atan => {
                        impl_scalar_intrin!(stack, f32, atan);
                        continue 'vm;
                    }
                    IntId::Atan2 => {
                        impl_duplet_intrin!(stack, f32, atan2);
                        continue 'vm;
                    }
                    IntId::ExpM1 => {
                        impl_scalar_intrin!(stack, f32, exp_m1);
                        continue 'vm;
                    }
                    IntId::Ln1P => {
                        impl_scalar_intrin!(stack, f32, ln_1p);
                        continue 'vm;
                    }
                    IntId::SinH => {
                        impl_scalar_intrin!(stack, f32, sinh);
                        continue 'vm;
                    }
                    IntId::CosH => {
                        impl_scalar_intrin!(stack, f32, cosh);
                        continue 'vm;
                    }
                    IntId::TanH => {
                        impl_scalar_intrin!(stack, f32, tanh);
                        continue 'vm;
                    }
                    IntId::AsinH => {
                        impl_scalar_intrin!(stack, f32, asinh);
                        continue 'vm;
                    }
                    IntId::AcosH => {
                        impl_scalar_intrin!(stack, f32, acosh);
                        continue 'vm;
                    }
                    IntId::AtanH => {
                        impl_scalar_intrin!(stack, f32, atanh);
                        continue 'vm;
                    }
                    IntId::IsNan => {
                        continue 'vm;
                    }
                    IntId::IsInfinite => {
                        continue 'vm;
                    }
                    IntId::IsFinite => {
                        continue 'vm;
                    }
                    IntId::IsNormal => {
                        continue 'vm;
                    }
                    IntId::IsSignalPositive => {
                        continue 'vm;
                    }
                    IntId::IsSignalNegative => {
                        continue 'vm;
                    }
                    IntId::Recip => {
                        continue 'vm;
                    }
                    IntId::ToDegrees => {
                        continue 'vm;
                    }
                    IntId::ToRadians => {
                        continue 'vm;
                    }
                    IntId::Max => {
                        impl_duplet_intrin!(stack, f32, max);
                        continue 'vm;
                    }
                    IntId::Min => {
                        impl_duplet_intrin!(stack, f32, min);
                        continue 'vm;
                    }
                    _ => {
                        break 'vm;
                    }
                }
            }

            OpCode::Push => {
                stack.push(Record::from(command_buffer.fetch()));
                continue 'vm;
            }

            OpCode::Pop => {
                stack.pop_multi(command_buffer.fetch().into());
                continue 'vm;
            }

            OpCode::Move => {
                stack.poke_set(
                    command_buffer.fetch().into(),
                    Record::from(command_buffer.fetch()),
                );
                continue 'vm;
            }

            OpCode::Copy => {
                stack.poke_set(
                    command_buffer.fetch().into(),
                    stack.poke(command_buffer.fetch().into()),
                );
                continue 'vm;
            }

            OpCode::NoOp => {
                continue 'vm;
            }

            OpCode::Duplicate => {
                stack.push(stack.peek());
                continue 'vm;
            }

            OpCode::DuplicateTwice => {
                stack.push(stack.peek());
                stack.push(stack.peek());
                continue 'vm;
            }

            OpCode::CastI32toF32 => {
                stack.peek_set(Record::from(f32::from(stack.peek())));
                continue 'vm;
            }

            OpCode::CastF32toI32 => {
                stack.peek_set(Record::from(i32::from(stack.peek())));
                continue 'vm;
            }

            OpCode::Jump => {
                let target_address = command_buffer.fetch().into();
                command_buffer.jump(target_address);
                continue 'vm;
            }

            OpCode::JumpIfZero => {
                impl_scalar_con_jmp!(stack, command_buffer, ==, 0i32, i32);
                continue 'vm;
            }

            OpCode::JumpIfNotZero => {
                impl_scalar_con_jmp!(stack, command_buffer, !=, 0i32, i32);
                continue 'vm;
            }

            OpCode::JumpIfEquals => {
                impl_duplet_con_jmp!(stack, command_buffer, ==, i32);
                continue 'vm;
            }

            OpCode::JumpIfNotEquals => {
                impl_duplet_con_jmp!(stack, command_buffer, !=, i32);
                continue 'vm;
            }

            OpCode::JumpIfAbove => {
                impl_duplet_con_jmp!(stack, command_buffer, >, i32);
                continue 'vm;
            }

            OpCode::JumpIfAboveEquals => {
                impl_duplet_con_jmp!(stack, command_buffer, >=, i32);
                continue 'vm;
            }

            OpCode::JumpIfLess => {
                impl_duplet_con_jmp!(stack, command_buffer, <, i32);
                continue 'vm;
            }

            OpCode::JumpIfLessEquals => {
                impl_duplet_con_jmp!(stack, command_buffer, <=, i32);
                continue 'vm;
            }

            OpCode::I32Addition => {
                impl_duplet_op_static!(stack, i32, wrapping_add);
                continue 'vm;
            }

            OpCode::I32Subtraction => {
                impl_duplet_op_static!(stack, i32, wrapping_sub);
                continue 'vm;
            }

            OpCode::I32Multiplication => {
                impl_duplet_op_static!(stack, i32, wrapping_mul);
                continue 'vm;
            }

            OpCode::I32Division => {
                impl_duplet_op_static!(stack, i32, wrapping_div);
                continue 'vm;
            }

            OpCode::I32Modulo => {
                impl_duplet_op!(stack, i32, %);
                continue 'vm;
            }

            OpCode::I32BitwiseAnd => {
                impl_duplet_op!(stack, i32, &);
                continue 'vm;
            }

            OpCode::I32BitwiseOr => {
                impl_duplet_op!(stack, i32, |);
                continue 'vm;
            }

            OpCode::I32BitwiseXor => {
                impl_duplet_op!(stack, i32, ^);
                continue 'vm;
            }

            OpCode::I32BitwiseArithmeticLeftShift => {
                impl_duplet_op_static!(stack, i32, wrapping_shl);
                continue 'vm;
            }

            OpCode::I32BitwiseArithmeticRightShift => {
                impl_duplet_op_static!(stack, i32, wrapping_shr);
                continue 'vm;
            }

            OpCode::I32BitwiseCircularLeftShift => {
                impl_duplet_op_static!(stack, i32, rotate_left);
                continue 'vm;
            }

            OpCode::I32BitwiseCircularRightShift => {
                impl_duplet_op_static!(stack, i32, rotate_right);
                continue 'vm;
            }

            OpCode::I32BitwiseComplement => {
                stack.peek_set(Record::from(!i32::from(stack.peek())));
                continue 'vm;
            }

            OpCode::I32Increment => {
                impl_scalar_op!(stack, i32, +, 1);
                continue 'vm;
            }

            OpCode::I32Decrement => {
                impl_scalar_op!(stack, i32, -, 1);
                continue 'vm;
            }

            OpCode::F32Addition => {
                impl_duplet_op!(stack, f32, +);
                continue 'vm;
            }

            OpCode::F32Subtraction => {
                impl_duplet_op!(stack, f32, -);
                continue 'vm;
            }

            OpCode::F32Multiplication => {
                impl_duplet_op!(stack, f32, *);
                continue 'vm;
            }

            OpCode::F32Division => {
                impl_duplet_op!(stack, f32, /);
                continue 'vm;
            }

            OpCode::F32Modulo => {
                impl_duplet_op!(stack, f32, %);
                continue 'vm;
            }

            OpCode::F32FusedMultiplyAddition => {
                stack.poke_set(
                    2,
                    Record::from(
                        f32::from(stack.poke(2)).mul_add(stack.poke(1).into(), stack.peek().into()),
                    ),
                );
                stack.pop_multi(2);
                continue;
            }

            OpCode::I32Vector4Addition => {
                impl_vector_op!(stack, i32, __add4_slice, i32, 4);
                continue;
            }

            OpCode::I32Vector4Subtraction => {
                impl_vector_op!(stack, i32, __sub4_slice, i32, 4);
                continue;
            }

            OpCode::I32Vector4Multiplication => {
                impl_vector_op!(stack, i32, __mul4_slice, i32, 4);
                continue;
            }

            OpCode::I32Vector4Division => {
                impl_vector_op!(stack, i32, __div4_slice, i32, 4);
                continue;
            }

            OpCode::I32Vector4Modulo => {
                impl_vector_op!(stack, i32, __mod4_slice, i32, 4);
                continue;
            }

            OpCode::I32Vector4BitwiseAnd => {
                impl_vector_op!(stack, i32, __and4_slice, i32, 4);
                continue;
            }

            OpCode::I32Vector4BitwiseOr => {
                impl_vector_op!(stack, i32, __or4_slice, i32, 4);
                continue;
            }

            OpCode::I32Vector4BitwiseXor => {
                impl_vector_op!(stack, i32, __xor4_slice, i32, 4);
                continue;
            }

            OpCode::I32Vector4BitwiseArithmeticLeftShift => {
                impl_vector_op!(stack, i32, __sal4_slice, i32, 4);
                continue;
            }

            OpCode::I32Vector4BitwiseArithmeticRightShift => {
                impl_vector_op!(stack, i32, __sar4_slice, i32, 4);
                continue;
            }

            OpCode::I32Vector4BitwiseCircularLeftShift => {
                impl_vector_op!(stack, i32, __rol4_slice, i32, 4);
                continue;
            }

            OpCode::I32Vector4BitwiseCircularRightShift => {
                impl_vector_op!(stack, i32, __ror4_slice, i32, 4);
                continue;
            }

            OpCode::I32Vector4BitwiseComplement => {}

            OpCode::F32Vector4Addition => {
                impl_vector_op!(stack, f32, __add4_slice, f32, 4);
                continue;
            }

            OpCode::F32Vector4Subtraction => {
                impl_vector_op!(stack, f32, __sub4_slice, f32, 4);
                continue;
            }

            OpCode::F32Vector4Multiplication => {
                impl_vector_op!(stack, f32, __mul4_slice, f32, 4);
                continue;
            }

            OpCode::F32Vector4Division => {
                impl_vector_op!(stack, f32, __div4_slice, f32, 4);
                continue;
            }

            OpCode::F32Vector4Modulo => {
                impl_vector_op!(stack, f32, __mod4_slice, f32, 4);
                continue;
            }

            OpCode::F32Vector4FusedMultiplyAddition => {
                impl_fma_vector_op!(stack, f32, __fma4_slice, f32, 4);
            }

            OpCode::I32Vector8Addition => {
                impl_vector_op!(stack, i32, __add8_slice, i32, 8);
                continue;
            }

            OpCode::I32Vector8Subtraction => {
                impl_vector_op!(stack, i32, __sub8_slice, i32, 8);
                continue;
            }

            OpCode::I32Vector8Multiplication => {
                impl_vector_op!(stack, i32, __mul8_slice, i32, 8);
                continue;
            }

            OpCode::I32Vector8Division => {
                impl_vector_op!(stack, i32, __div8_slice, i32, 8);
                continue;
            }

            OpCode::I32Vector8Modulo => {
                impl_vector_op!(stack, i32, __mod8_slice, i32, 8);
                continue;
            }

            OpCode::I32Vector8BitwiseAnd => {
                impl_vector_op!(stack, i32, __and8_slice, i32, 8);
                continue;
            }

            OpCode::I32Vector8BitwiseOr => {
                impl_vector_op!(stack, i32, __or8_slice, i32, 8);
                continue;
            }

            OpCode::I32Vector8BitwiseXor => {
                impl_vector_op!(stack, i32, __xor8_slice, i32, 8);
                continue;
            }

            OpCode::I32Vector8BitwiseArithmeticLeftShift => {
                impl_vector_op!(stack, i32, __sal8_slice, i32, 8);
                continue;
            }

            OpCode::I32Vector8BitwiseArithmeticRightShift => {
                impl_vector_op!(stack, i32, __sar8_slice, i32, 8);
                continue;
            }

            OpCode::I32Vector8BitwiseCircularLeftShift => {
                impl_vector_op!(stack, i32, __rol8_slice, i32, 8);
                continue;
            }

            OpCode::I32Vector8BitwiseCircularRightShift => {
                impl_vector_op!(stack, i32, __ror8_slice, i32, 8);
                continue;
            }

            OpCode::I32Vector8BitwiseComplement => {}

            OpCode::F32Vector8Addition => {
                impl_vector_op!(stack, f32, __add8_slice, f32, 8);
                continue;
            }

            OpCode::F32Vector8Subtraction => {
                impl_vector_op!(stack, f32, __sub8_slice, f32, 8);
                continue;
            }

            OpCode::F32Vector8Multiplication => {
                impl_vector_op!(stack, f32, __mul8_slice, f32, 8);
                continue;
            }

            OpCode::F32Vector8Division => {
                impl_vector_op!(stack, f32, __div8_slice, f32, 8);
                continue;
            }

            OpCode::F32Vector8Modulo => {
                impl_vector_op!(stack, f32, __mod8_slice, f32, 8);
                continue;
            }

            OpCode::F32Vector8FusedMultiplyAddition => {
                impl_fma_vector_op!(stack, f32, __fma8_slice, f32, 8);
            }

            OpCode::I32Vector16Addition => {
                impl_vector_op!(stack, i32, __add16_slice, i32, 16);
                continue;
            }

            OpCode::I32Vector16Subtraction => {
                impl_vector_op!(stack, i32, __sub16_slice, i32, 16);
                continue;
            }

            OpCode::I32Vector16Multiplication => {
                impl_vector_op!(stack, i32, __mul16_slice, i32, 16);
                continue;
            }

            OpCode::I32Vector16Division => {
                impl_vector_op!(stack, i32, __div16_slice, i32, 16);
                continue;
            }

            OpCode::I32Vector16Modulo => {
                impl_vector_op!(stack, i32, __mod16_slice, i32, 16);
                continue;
            }

            OpCode::I32Vector16BitwiseAnd => {
                impl_vector_op!(stack, i32, __and16_slice, i32, 16);
                continue;
            }

            OpCode::I32Vector16BitwiseOr => {
                impl_vector_op!(stack, i32, __or16_slice, i32, 16);
                continue;
            }

            OpCode::I32Vector16BitwiseXor => {
                impl_vector_op!(stack, i32, __xor16_slice, i32, 16);
                continue;
            }

            OpCode::I32Vector16BitwiseArithmeticLeftShift => {
                impl_vector_op!(stack, i32, __sal16_slice, i32, 16);
                continue;
            }

            OpCode::I32Vector16BitwiseArithmeticRightShift => {
                impl_vector_op!(stack, i32, __sar16_slice, i32, 16);
                continue;
            }

            OpCode::I32Vector16BitwiseCircularLeftShift => {
                impl_vector_op!(stack, i32, __rol16_slice, i32, 16);
                continue;
            }

            OpCode::I32Vector16BitwiseCircularRightShift => {
                impl_vector_op!(stack, i32, __ror16_slice, i32, 16);
                continue;
            }

            OpCode::I32Vector16BitwiseComplement => {}

            OpCode::F32Vector16Addition => {
                impl_vector_op!(stack, f32, __add16_slice, f32, 16);
                continue;
            }

            OpCode::F32Vector16Subtraction => {
                impl_vector_op!(stack, f32, __sub16_slice, f32, 16);
                continue;
            }

            OpCode::F32Vector16Multiplication => {
                impl_vector_op!(stack, f32, __mul16_slice, f32, 16);
                continue;
            }

            OpCode::F32Vector16Division => {
                impl_vector_op!(stack, f32, __div16_slice, f32, 16);
                continue;
            }

            OpCode::F32Vector16Modulo => {
                impl_vector_op!(stack, f32, __mod16_slice, f32, 16);
                continue;
            }

            OpCode::F32Vector16FusedMultiplyAddition => {
                impl_fma_vector_op!(stack, f32, __fma16_slice, f32, 16);
            }

            _ => {
                break 'vm;
            }
        }
    }

    ExecutorOutput {
        input: ExecutorInput {
            stack,
            chunk: command_buffer,
            fixed: None,
        },
        cycles,
        exit_code: interrupt,
        interrupt_code: interrupt,
        time: clock.elapsed().as_secs_f64(),
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
        stream::{BytecodeStream, ValidationPolicy},
    };
    use crate::core::stack::Stack;

    #[test]
    fn memory_dupl_ddupl() {
        let mut stream = BytecodeStream::new();
        stream.with(Token::Opc(Push)).with(Token::I32(3));
        stream.with(Token::Opc(Duplicate));
        stream.with(Token::Opc(DuplicateTwice));
        stream.with(Token::Opc(Interrupt)).with(Token::I32(0));
        let input = ExecutorInput {
            stack: Stack::with_length(4),
            chunk: stream.build(ValidationPolicy::Full),
            fixed: None,
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
        stream.with(Token::Opc(Push)).with(Token::I32(3));
        stream.with(Token::Opc(Push)).with(Token::I32(7));
        stream.with(Token::Opc(Push)).with(Token::I32(5));
        stream
            .with(Token::Opc(Move))
            .with(Token::I32(1))
            .with(Token::I32(-4));
        stream
            .with(Token::Opc(Copy))
            .with(Token::I32(0))
            .with(Token::I32(1));
        stream.with(Token::Opc(Interrupt)).with(Token::I32(0));
        let input = ExecutorInput {
            stack: Stack::with_length(3),
            chunk: stream.build(ValidationPolicy::Full),
            fixed: None,
        };
        let stack = execute(input).input.stack;
        assert_eq!(i32::from(stack.poke(1)), -4);
        assert_eq!(i32::from(stack.peek()), -4);
    }

    #[test]
    fn memory_push_pop() {
        let mut stream = BytecodeStream::new();
        for i in 0..4096 {
            stream.with(Token::Opc(Push)).with(Token::I32(i));
        }
        stream.with(Token::Opc(Pop)).with(Token::I32(2048));
        stream.with(Token::Opc(Interrupt)).with(Token::I32(0));
        let input = ExecutorInput {
            stack: Stack::with_length(8192),
            chunk: stream.build(ValidationPolicy::Full),
            fixed: None,
        };
        let stack = execute(input).input.stack;
        assert_eq!(i32::from(stack.peek()), 2047);
    }

    #[test]
    fn control_intrinsic() {
        let mut stream = BytecodeStream::new();
        stream.with(Token::Opc(Push)).with(Token::F32(0.5236));
        stream
            .with(Token::Opc(CallIntrinsic))
            .with(Token::Int(IntId::Sin));
        stream.with(Token::Opc(Interrupt)).with(Token::I32(0));
        let input = ExecutorInput {
            stack: Stack::with_length(1),
            chunk: stream.build(ValidationPolicy::Full),
            fixed: None,
        };
        let stack = execute(input).input.stack;
        assert!(f32::from(stack.peek()) - 0.5 < 0.00001);
    }

    #[test]
    fn control_interrupt() {
        let mut stream = BytecodeStream::new();
        stream.with(Token::Opc(Push)).with(Token::I32(0));
        stream.with(Token::Opc(Interrupt)).with(Token::I32(0));
        stream.with(Token::Opc(Push)).with(Token::I32(0));
        let input = ExecutorInput {
            stack: Stack::with_length(2),
            chunk: stream.build(ValidationPolicy::Full),
            fixed: None,
        };
        let chunk = execute(input).input.chunk;
        assert_eq!(chunk.operation_ptr(), 4);
    }

    fn test_i32op_template(op: OpCode, a: i32, b: i32, x: i32) {
        let mut stream = BytecodeStream::new();
        stream.with(Token::Opc(Push)).with(Token::I32(a));
        stream.with(Token::Opc(Push)).with(Token::I32(b));
        stream.with(Token::Opc(op));
        stream.with(Token::Opc(Interrupt)).with(Token::I32(0));
        let input = ExecutorInput {
            stack: Stack::with_length(2),
            chunk: stream.build(ValidationPolicy::Full),
            fixed: None,
        };
        let stack = execute(input).input.stack;
        if a != b {
            assert_eq!(stack.stack_ptr(), 1);
        }
        assert_eq!(i32::from(stack.peek()), x);
    }

    fn test_f32op_template(op: OpCode, a: f32, b: f32, x: f32) {
        let mut stream = BytecodeStream::new();
        stream.with(Token::Opc(Push)).with(Token::F32(a));
        stream.with(Token::Opc(Push)).with(Token::F32(b));
        stream.with(Token::Opc(op));
        stream.with(Token::Opc(Interrupt)).with(Token::I32(0));
        let input = ExecutorInput {
            stack: Stack::with_length(4),
            chunk: stream.build(ValidationPolicy::Full),
            fixed: None,
        };
        let stack = execute(input).input.stack;
        assert_eq!(stack.stack_ptr(), 1);
        assert_eq!(f32::from(stack.peek()), x);
    }

    #[test]
    fn arithmetic_f32_add() {
        test_f32op_template(OpCode::F32Addition, 3.5, 2.5, 6.0);
    }

    #[test]
    fn arithmetic_f32_sub() {
        test_f32op_template(OpCode::F32Subtraction, 3.5, 2.5, 1.0);
    }

    #[test]
    fn arithmetic_f32_mul() {
        test_f32op_template(OpCode::F32Multiplication, 3.5, 2.5, 8.75);
    }

    #[test]
    fn arithmetic_f32_div() {
        test_f32op_template(OpCode::F32Division, 3.5, 2.5, 1.4);
    }

    #[test]
    fn arithmetic_f32_mod() {
        test_f32op_template(OpCode::F32Modulo, 3.5, 2.5, 1.0);
    }

    #[test]
    fn arithmetic_f32_fma() {
        let mut stream = BytecodeStream::new();
        stream.with(Token::Opc(Push)).with(Token::F32(2.0));
        stream.with(Token::Opc(Push)).with(Token::F32(3.0));
        stream.with(Token::Opc(Push)).with(Token::F32(4.0));
        stream.with(Token::Opc(F32FusedMultiplyAddition));
        stream.with(Token::Opc(Interrupt)).with(Token::I32(0));
        let input = ExecutorInput {
            stack: Stack::with_length(4),
            chunk: stream.build(ValidationPolicy::Full),
            fixed: None,
        };
        let stack = execute(input).input.stack;
        assert_eq!(stack.stack_ptr(), 1);
        assert_eq!(f32::from(stack.peek()), 10.0);
    }

    #[test]
    fn arithmetic_i32_add() {
        test_i32op_template(OpCode::I32Addition, 8, 4, 12);
    }

    #[test]
    fn arithmetic_i32_sub() {
        test_i32op_template(OpCode::I32Subtraction, 8, 4, 4);
    }

    #[test]
    fn arithmetic_i32_mul() {
        test_i32op_template(OpCode::I32Multiplication, 8, 4, 32);
    }

    #[test]
    fn arithmetic_i32_div() {
        test_i32op_template(OpCode::I32Division, 8, 4, 2);
    }

    #[test]
    fn arithmetic_i32_mod() {
        test_i32op_template(OpCode::I32Modulo, 8, 5, 3);
    }

    #[test]
    fn arithmetic_i32_and() {
        test_i32op_template(OpCode::I32BitwiseAnd, 2, 3, 2);
    }

    #[test]
    fn arithmetic_i32_or() {
        test_i32op_template(OpCode::I32BitwiseOr, 2, 8, 10);
    }

    #[test]
    fn arithmetic_i32_xor() {
        test_i32op_template(OpCode::I32BitwiseXor, 9, 9, 0);
    }

    #[test]
    fn arithmetic_i32_sal() {
        test_i32op_template(OpCode::I32BitwiseArithmeticLeftShift, 1, 8, 256);
    }

    #[test]
    fn arithmetic_i32_sar() {
        test_i32op_template(OpCode::I32BitwiseArithmeticRightShift, 8, 1, 4);
    }

    #[test]
    fn arithmetic_i32_rol() {
        test_i32op_template(OpCode::I32BitwiseCircularLeftShift, 4, 64, 4);
    }

    #[test]
    fn arithmetic_i32_ror() {
        test_i32op_template(OpCode::I32BitwiseCircularRightShift, 64, 4, 4);
    }

    #[test]
    fn arithmetic_i32_com() {
        test_i32op_template(OpCode::I32BitwiseComplement, 8, 8, -9);
    }

    #[test]
    fn arithmetic_i32_inc() {
        test_i32op_template(OpCode::I32Increment, 0, 0, 1);
    }

    #[test]
    fn arithmetic_i32_dec() {
        test_i32op_template(OpCode::I32Decrement, 1, 1, 0);
    }

    #[test]
    fn simd_vquadiadd() {
        let mut stream = BytecodeStream::new();
        stream.prologue();
        stream.with(Token::Opc(Push)).with(Token::I32(2));
        stream.with(Token::Opc(Push)).with(Token::I32(5));
        stream.with(Token::Opc(Push)).with(Token::I32(1));
        stream.with(Token::Opc(Push)).with(Token::I32(-3));

        stream.with(Token::Opc(Push)).with(Token::I32(4));
        stream.with(Token::Opc(Push)).with(Token::I32(2));
        stream.with(Token::Opc(Push)).with(Token::I32(9));
        stream.with(Token::Opc(Push)).with(Token::I32(2));
        stream.with(Token::Opc(I32Vector4Addition));
        stream.epilogue();

        let input = ExecutorInput {
            stack: Stack::with_length(32),
            chunk: stream.build(ValidationPolicy::Full),
            fixed: None,
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
        stream.prologue();
        stream.with(Token::Opc(Push)).with(Token::I32(2));
        stream.with(Token::Opc(Push)).with(Token::I32(5));
        stream.with(Token::Opc(Push)).with(Token::I32(1));
        stream.with(Token::Opc(Push)).with(Token::I32(-3));

        stream.with(Token::Opc(Push)).with(Token::I32(4));
        stream.with(Token::Opc(Push)).with(Token::I32(2));
        stream.with(Token::Opc(Push)).with(Token::I32(9));
        stream.with(Token::Opc(Push)).with(Token::I32(2));
        stream.with(Token::Opc(I32Vector4Subtraction));
        stream.epilogue();

        let input = ExecutorInput {
            stack: Stack::with_length(32),
            chunk: stream.build(ValidationPolicy::Full),
            fixed: None,
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
        stream.prologue();
        stream.with(Token::Opc(Push)).with(Token::I32(2));
        stream.with(Token::Opc(Push)).with(Token::I32(5));
        stream.with(Token::Opc(Push)).with(Token::I32(1));
        stream.with(Token::Opc(Push)).with(Token::I32(-3));

        stream.with(Token::Opc(Push)).with(Token::I32(4));
        stream.with(Token::Opc(Push)).with(Token::I32(2));
        stream.with(Token::Opc(Push)).with(Token::I32(9));
        stream.with(Token::Opc(Push)).with(Token::I32(2));
        stream.with(Token::Opc(I32Vector4Multiplication));
        stream.epilogue();

        let input = ExecutorInput {
            stack: Stack::with_length(32),
            chunk: stream.build(ValidationPolicy::Full),
            fixed: None,
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
        stream.prologue();
        stream.with(Token::Opc(Push)).with(Token::I32(40));
        stream.with(Token::Opc(Push)).with(Token::I32(5));
        stream.with(Token::Opc(Push)).with(Token::I32(1));
        stream.with(Token::Opc(Push)).with(Token::I32(-3));

        stream.with(Token::Opc(Push)).with(Token::I32(10));
        stream.with(Token::Opc(Push)).with(Token::I32(2));
        stream.with(Token::Opc(Push)).with(Token::I32(9));
        stream.with(Token::Opc(Push)).with(Token::I32(2));
        stream.with(Token::Opc(I32Vector4Division));
        stream.epilogue();

        let input = ExecutorInput {
            stack: Stack::with_length(32),
            chunk: stream.build(ValidationPolicy::Full),
            fixed: None,
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
        stream.prologue();
        stream.with(Token::Opc(Push)).with(Token::I32(40));
        stream.with(Token::Opc(Push)).with(Token::I32(5));
        stream.with(Token::Opc(Push)).with(Token::I32(1));
        stream.with(Token::Opc(Push)).with(Token::I32(-3));

        stream.with(Token::Opc(Push)).with(Token::I32(4));
        stream.with(Token::Opc(Push)).with(Token::I32(2));
        stream.with(Token::Opc(Push)).with(Token::I32(9));
        stream.with(Token::Opc(Push)).with(Token::I32(2));
        stream.with(Token::Opc(I32Vector4Modulo));
        stream.epilogue();

        let input = ExecutorInput {
            stack: Stack::with_length(32),
            chunk: stream.build(ValidationPolicy::Full),
            fixed: None,
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
        stream.prologue();
        stream.with(Token::Opc(Push)).with(Token::I32(2));
        stream.with(Token::Opc(Push)).with(Token::I32(5));
        stream.with(Token::Opc(Push)).with(Token::I32(1));
        stream.with(Token::Opc(Push)).with(Token::I32(-3));

        stream.with(Token::Opc(Push)).with(Token::I32(4));
        stream.with(Token::Opc(Push)).with(Token::I32(2));
        stream.with(Token::Opc(Push)).with(Token::I32(9));
        stream.with(Token::Opc(Push)).with(Token::I32(2));
        stream.with(Token::Opc(I32Vector4BitwiseAnd));
        stream.epilogue();

        let input = ExecutorInput {
            stack: Stack::with_length(32),
            chunk: stream.build(ValidationPolicy::Full),
            fixed: None,
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
        stream.prologue();
        stream.with(Token::Opc(Push)).with(Token::I32(2));
        stream.with(Token::Opc(Push)).with(Token::I32(5));
        stream.with(Token::Opc(Push)).with(Token::I32(1));
        stream.with(Token::Opc(Push)).with(Token::I32(-3));

        stream.with(Token::Opc(Push)).with(Token::I32(4));
        stream.with(Token::Opc(Push)).with(Token::I32(2));
        stream.with(Token::Opc(Push)).with(Token::I32(9));
        stream.with(Token::Opc(Push)).with(Token::I32(2));
        stream.with(Token::Opc(I32Vector4BitwiseOr));
        stream.epilogue();

        let input = ExecutorInput {
            stack: Stack::with_length(32),
            chunk: stream.build(ValidationPolicy::Full),
            fixed: None,
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
        stream.prologue();
        stream.with(Token::Opc(Push)).with(Token::I32(2));
        stream.with(Token::Opc(Push)).with(Token::I32(5));
        stream.with(Token::Opc(Push)).with(Token::I32(1));
        stream.with(Token::Opc(Push)).with(Token::I32(-3));

        stream.with(Token::Opc(Push)).with(Token::I32(4));
        stream.with(Token::Opc(Push)).with(Token::I32(2));
        stream.with(Token::Opc(Push)).with(Token::I32(9));
        stream.with(Token::Opc(Push)).with(Token::I32(2));
        stream.with(Token::Opc(I32Vector4BitwiseXor));
        stream.epilogue();

        let input = ExecutorInput {
            stack: Stack::with_length(32),
            chunk: stream.build(ValidationPolicy::Full),
            fixed: None,
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
        stream.prologue();
        stream.with(Token::Opc(Push)).with(Token::I32(2));
        stream.with(Token::Opc(Push)).with(Token::I32(5));
        stream.with(Token::Opc(Push)).with(Token::I32(1));
        stream.with(Token::Opc(Push)).with(Token::I32(-3));

        stream.with(Token::Opc(Push)).with(Token::I32(4));
        stream.with(Token::Opc(Push)).with(Token::I32(2));
        stream.with(Token::Opc(Push)).with(Token::I32(9));
        stream.with(Token::Opc(Push)).with(Token::I32(2));
        stream.with(Token::Opc(I32Vector4BitwiseArithmeticLeftShift));
        stream.epilogue();

        let input = ExecutorInput {
            stack: Stack::with_length(32),
            chunk: stream.build(ValidationPolicy::Full),
            fixed: None,
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
        stream.prologue();
        stream.with(Token::Opc(Push)).with(Token::I32(2));
        stream.with(Token::Opc(Push)).with(Token::I32(5));
        stream.with(Token::Opc(Push)).with(Token::I32(1));
        stream.with(Token::Opc(Push)).with(Token::I32(-3));

        stream.with(Token::Opc(Push)).with(Token::I32(4));
        stream.with(Token::Opc(Push)).with(Token::I32(2));
        stream.with(Token::Opc(Push)).with(Token::I32(9));
        stream.with(Token::Opc(Push)).with(Token::I32(2));
        stream.with(Token::Opc(I32Vector4BitwiseArithmeticRightShift));
        stream.epilogue();

        let input = ExecutorInput {
            stack: Stack::with_length(32),
            chunk: stream.build(ValidationPolicy::Full),
            fixed: None,
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
        stream.prologue();
        stream.with(Token::Opc(Push)).with(Token::I32(2));
        stream.with(Token::Opc(Push)).with(Token::I32(5));
        stream.with(Token::Opc(Push)).with(Token::I32(2000000000));
        stream.with(Token::Opc(Push)).with(Token::I32(-3));

        stream.with(Token::Opc(Push)).with(Token::I32(4));
        stream.with(Token::Opc(Push)).with(Token::I32(2));
        stream.with(Token::Opc(Push)).with(Token::I32(9));
        stream.with(Token::Opc(Push)).with(Token::I32(2));
        stream.with(Token::Opc(I32Vector4BitwiseCircularLeftShift));
        stream.epilogue();

        let input = ExecutorInput {
            stack: Stack::with_length(32),
            chunk: stream.build(ValidationPolicy::Full),
            fixed: None,
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
        stream.prologue();
        stream.with(Token::Opc(Push)).with(Token::I32(2));
        stream.with(Token::Opc(Push)).with(Token::I32(5));
        stream.with(Token::Opc(Push)).with(Token::I32(1));
        stream.with(Token::Opc(Push)).with(Token::I32(-3));

        stream.with(Token::Opc(Push)).with(Token::I32(4));
        stream.with(Token::Opc(Push)).with(Token::I32(2));
        stream.with(Token::Opc(Push)).with(Token::I32(9));
        stream.with(Token::Opc(Push)).with(Token::I32(2));
        stream.with(Token::Opc(I32Vector4BitwiseCircularRightShift));
        stream.epilogue();

        let input = ExecutorInput {
            stack: Stack::with_length(32),
            chunk: stream.build(ValidationPolicy::Full),
            fixed: None,
        };
        let stack = execute(input).input.stack;
        assert_eq!(i32::from(stack[1]), 536870912);
        assert_eq!(i32::from(stack[2]), 1073741825);
        assert_eq!(i32::from(stack[3]), 8388608);
        assert_eq!(i32::from(stack[4]), 2147483647);
        assert_eq!(stack.stack_ptr(), 4);
    }
}
