use super::{
    ast::Token,
    descriptors::{self, ExplicitArgumentType},
    lexemes,
};
use crate::{
    bytecode::{ast::OpCode, signal::Signal},
    par::{self, prelude::*},
};

#[derive(Copy, Clone, Eq, PartialEq)]
pub enum ValidationPolicy {
    Basic,
    Advanced,
    Full,
}

#[inline]
fn fatal(msg: String) {
    panic!("\x1b[1;31m\t{}\t\x1b[0;0m\n", msg);
}

/// Checks if operation argument count is valid.
pub fn check_op_args_count(op: OpCode, arg_count: usize) -> bool {
    // If operation has explicit arguments:
    if let Some(args) = descriptors::EXPLICIT_ARGUMENTS[op as usize] {
        // Required argument count:
        let desired_arg_count = args.len();

        // If actual argument count does not equals the required argument count,
        // we have an argument mismatch, which is a fatal error!
        if arg_count != desired_arg_count {
            fatal(format!(
                "Invalid argument count for instruction \"{}\"! Expected {} found {}!",
                lexemes::MNEMONICS[op as usize],
                desired_arg_count,
                arg_count
            ));
        }
        return true;
    }
    false
}

/// Checks if argument type is valid.
pub fn is_arg_equ(token: &Token, arg_type: ExplicitArgumentType) -> bool {
    match token {
        Token::I32(_) if arg_type & ExplicitArgumentType::I32 != ExplicitArgumentType::NONE => true,
        Token::F32(_) if arg_type & ExplicitArgumentType::F32 != ExplicitArgumentType::NONE => true,
        Token::U32(_) if arg_type & ExplicitArgumentType::U32 != ExplicitArgumentType::NONE => true,
        Token::C32(_) if arg_type & ExplicitArgumentType::C32 != ExplicitArgumentType::NONE => true,
        Token::Int(_) if arg_type & ExplicitArgumentType::IPC != ExplicitArgumentType::NONE => true,
        Token::Pin(_) if arg_type & ExplicitArgumentType::PIN != ExplicitArgumentType::NONE => true,
        _ => false,
    }
}

/// Checks if the argument type is valid, if not it panics.
pub fn check_if_arg_valid(x: usize, op: OpCode, tok: &Token) {
    if let Some(args) = descriptors::EXPLICIT_ARGUMENTS[op as usize] {
        assert!(x < args.len());
        if !is_arg_equ(tok, args[x]) {
            fatal(format!(
                "Invalid argument type for instruction \"{}\"! Expected {:?} found {}!",
                lexemes::MNEMONICS[op as usize],
                args[x],
                tok
            ));
        }
    }
}

/// Checks one single token.
pub fn check_single_token(tok: &Token, arg_count: &mut usize, prev: &mut OpCode) -> bool {
    // If token is an argument,
    // increment argument count and continue.
    if tok.is_imm() {
        *arg_count += 1;
        return true;
    }

    // If token is operation:
    if let Token::Opc(op) = tok {
        // If it is the first operation, prev is none, so assign:
        if *prev == OpCode::Count {
            *prev = *op;
            return true;
        }

        //check_if_arg_valid(x, *op, tok);

        // Check if op is valid.
        // Returns false if the op does not have any arguments,
        // so we can skip the iteration.
        if check_op_args_count(*prev, *arg_count) {
            return false;
        }
    }
    true
}

/// Validates the input bytecode.
pub fn validate(in_: &[Token], _sec: ValidationPolicy) {
    assert!(!in_.is_empty());

    // Closure for each_loop.
    let check = |i: (usize, &Token)| {
        if (i.0 as isize) < 0 {
            return;
        }
        if !i.1.is_instr() {
            return;
        }

        let mut arg_count: usize = 0;
        let mut prev = OpCode::Count;

        // Search next tokens:
        'search: for tok in &in_[i.0..] {
            if !check_single_token(tok, &mut arg_count, &mut prev) {
                break 'search;
            }
        }
    };

    // Execute in parallel:
    par::iter(in_).enumerate().for_each(check);
    let last = in_.last().unwrap();

    // Check if the last token is an operation and arguments are missing:
    if let Token::Opc(op) = last {
        if let Some(args) = descriptors::EXPLICIT_ARGUMENTS[*op as usize] {
            fatal(format!(
                "Invalid argument count for instruction \"{}\"! Expected {} found 0!",
                lexemes::MNEMONICS[*op as usize],
                args.len(),
            ));
            panic!();
        }
    }
    // Check if the last token is an arguments and there are some missing for the operation:
    else if last.is_imm() {
        let op = in_.iter().rev().position(|x| matches!(x, Token::Opc(_)));
        if let Some(op_pos) = op {
            if op_pos < in_.len() {
                if let Some(op_idx) = in_.len().saturating_sub(1).checked_sub(op_pos) {
                    if let Token::Opc(mut prev) = in_[op_idx] {
                        let mut arg_count: usize = op_pos;
                        // Search next tokens:
                        'search: for tok in &in_[op_idx..] {
                            if !check_single_token(tok, &mut arg_count, &mut prev) {
                                break 'search;
                            }
                        }
                    }
                }
            }
        }
    }
}

/// Converts a token stream into a signal stream for execution.
/// The tokens should be validated before calling this!
pub fn build(in_: &[Token]) -> Box<[Signal]> {
    let mut buffer = Vec::with_capacity(in_.len());
    in_.iter().for_each(|tok| {
        if let Some(sig) = Option::<Signal>::from(&*tok) {
            buffer.push(sig);
        }
    });
    buffer.into_boxed_slice()
}

#[cfg(test)]
mod tests {
    use crate::bytecode::{
        ast::{OpCode, Token},
        stream::{BytecodeStream, ValidationPolicy},
    };

    #[test]
    #[should_panic]
    fn too_many_args() {
        let mut stream = BytecodeStream::new();
        stream
            .with(Token::Opc(OpCode::Push))
            .with(Token::I32(3))
            .with(Token::I32(2)); // Push only wants one argument but we deliver two!
        stream.validate(ValidationPolicy::Full);
    }

    #[test]
    #[should_panic]
    fn too_less_args() {
        let mut stream = BytecodeStream::new();
        stream.with(Token::Opc(OpCode::Push)); // Push only wants one argument but we deliver zero!
        stream.validate(ValidationPolicy::Full);
    }
}
