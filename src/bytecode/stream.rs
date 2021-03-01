use super::ast::{OpCode, Token};
use super::chunk::BytecodeChunk;
use crate::bytecode::signal::Signal;
use crate::prelude::IntId;
use colored::Colorize;
use std::collections::HashMap;
use std::{convert, default, fmt, ops};

/// A bytecode stream is used to dynamically build bytecode.
/// When building is done, the next step is validating.
/// The validator checks if there are any invalid operations,
/// values and parameters in the bytecode.
/// If validation is successful, it can get converted
/// into a bytecode chunk, which then can get executed by a VM executor kernel.
pub struct BytecodeStream {
    stream: Vec<Token>,
    pin_table: HashMap<String, usize>,
}

impl BytecodeStream {
    /// Inserts common prologue code into the bytecode stream.
    /// This always should be called when a new instance is created
    /// and before any operations/arguments are there.
    fn prologue(&mut self) {
        // The first record of the stack (0x00000000) is always unused because of the stack
        // pointer layout. So we fill it with some random value using the MOV operation.
        self.push(Token::Opc(OpCode::Mov)) // Move to stack slot.
            .push(Token::U32(0)) // Into first stack slot (0x00000000)
            .push(Token::U32(u32::from_le_bytes(*b"LOVE"))); // (4 * u8) Because I love my cutie!
    }

    /// Inserts common prologue code into the bytecode stream.
    /// This always should be called when building is done.
    fn epilogue(&mut self) {
        // Add interrupt as last operation because
        // there are no operation pointer out of range checks
        // for performance.
        self.push(Token::Opc(OpCode::Int)).push(Token::I32(0));
    }

    /// Creates a new, empty bytecode stream.
    #[inline]
    pub fn new() -> Self {
        let mut this = Self {
            stream: Vec::new(),
            pin_table: HashMap::with_capacity(32),
        };
        this.prologue();
        this
    }

    /// Creates a new, empty instance with a specified
    /// capacity for the command and jump table buffer.
    #[inline]
    pub fn with_capacity(capacity: usize) -> Self {
        let mut this = Self {
            stream: Vec::with_capacity(capacity),
            pin_table: HashMap::with_capacity(32),
        };
        this.prologue();
        this
    }

    // Pushes a new token.
    pub fn push(&mut self, tok: Token) -> &mut Self {
        self.stream.push(tok);
        self
    }

    pub fn args(&mut self, args: &[Token]) -> &mut Self {
        for arg in args {
            self.push(arg.clone());
        }
        self
    }

    #[inline]
    pub fn op(&mut self, op: OpCode) -> &mut Self {
        self.push(Token::Opc(op))
    }

    #[inline]
    pub fn i32(&mut self, x: i32) -> &mut Self {
        self.push(Token::I32(x))
    }

    #[inline]
    pub fn u32(&mut self, x: u32) -> &mut Self {
        self.push(Token::U32(x))
    }

    #[inline]
    pub fn f32(&mut self, x: f32) -> &mut Self {
        self.push(Token::F32(x))
    }

    #[inline]
    pub fn c32(&mut self, x: char) -> &mut Self {
        self.push(Token::C32(x))
    }

    #[inline]
    pub fn intid(&mut self, x: IntId) -> &mut Self {
        self.push(Token::Int(x))
    }

    /// Returns the index to the last signal.
    #[inline]
    pub fn index(&self) -> usize {
        self.stream.len() - 1
    }

    /// Returns an immutable reference to the command buffer stream
    #[inline]
    pub fn command_buffer(&self) -> &Vec<Token> {
        &self.stream
    }

    /// Returns the amount of entries in the command buffer stream.
    #[inline]
    pub fn length(&self) -> usize {
        self.stream.len()
    }

    /// Returns true if the command buffer stream is empty, else false.
    #[inline]
    pub fn is_empty(&self) -> bool {
        self.stream.is_empty()
    }

    /// Returns the allocated memory capacity of the command buffer stream.
    #[inline]
    pub fn capacity(&self) -> usize {
        self.stream.capacity()
    }

    /// Returns the estimated amount of bytes the stream currently takes up in memory.
    #[inline]
    pub fn size(&self) -> usize {
        self.stream.capacity() * std::mem::size_of::<Token>()
    }

    /// Clears all entries in the command buffer stream
    /// and in the jump table.
    #[inline]
    pub fn clear(&mut self) {
        self.stream.clear();
    }

    #[inline]
    pub fn pin_here(&mut self, id: String) {
        self.pin_table.insert(id.clone(), self.stream.len());
        self.push(Token::PinMarker(id, self.stream.len()));
    }

    #[inline]
    pub fn pin(&mut self, name: String) {
        self.push(Token::Pin(name, None));
    }

    pub fn evaluate_pins(&mut self) {
        for mut tok in &mut self.stream {
            if let Token::Pin(name, id) = &mut tok {
                *id = Some(*self.pin_table.get(name).unwrap() as i32 - 1);
            }
        }
    }

    /// Builds and validates this bytecode and returns an list of error messages (if any).
    /// On success this returns the bytecode chunk, which can be injected into a VM executor kernel.
    pub fn build(mut self) -> BytecodeChunk {
        assert!(!self.is_empty());
        self.evaluate_pins();
        self.epilogue();
        let mut chunk = Vec::with_capacity(self.stream.len());
        for tok in self.stream {
            if matches!(tok, Token::PinMarker(_, _)) {
                continue;
            }
            chunk.push(Signal::from(tok.bytes()));
        }
        chunk.shrink_to_fit();
        BytecodeChunk::from(chunk)
    }

    pub fn for_loop(&mut self, i_start: i32, i_end: i32, body: &[Token]) {
        use OpCode::*;

        self.op(Push).i32(i_start);
        self.pin_here("begin".to_string());
        self.op(Dupl);
        self.op(Push).i32(i_end);
        self.op(Je).pin("end".to_string());
        self.args(body);
        self.op(Jmp).pin("begin".to_string());
        self.pin_here("end".to_string());
        self.op(Pop).u32(1);
    }
}

impl fmt::Display for BytecodeStream {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        for pin in &self.pin_table {
            writeln!(
                f,
                "{} {:#X} {}",
                ".equ".bold().bright_purple(),
                pin.1 - 1,
                pin.0
            )?;
        }
        for tok in &self.stream {
            if matches!(tok, Token::Opc(_) | Token::PinMarker(_, _)) {
                writeln!(f)?;
            }
            write!(f, "{} ", tok)?;
        }
        Ok(())
    }
}

impl fmt::Debug for BytecodeStream {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        for tok in &self.stream {
            if matches!(tok, Token::Opc(_)) {
                writeln!(f)?;
            }
            write!(f, "{:?} ", tok)?;
        }
        Ok(())
    }
}

impl ops::Index<usize> for BytecodeStream {
    type Output = Token;

    /// Returns the entry at index 'idx'.
    #[inline]
    fn index(&self, idx: usize) -> &Self::Output {
        &self.stream[idx]
    }
}

impl ops::IndexMut<usize> for BytecodeStream {
    /// Returns the entry at index 'idx'.
    #[inline]
    fn index_mut(&mut self, idx: usize) -> &mut Self::Output {
        &mut self.stream[idx]
    }
}

impl convert::From<Box<[Token]>> for BytecodeStream {
    /// Creates a new instance from a boxed array.
    fn from(buf: Box<[Token]>) -> Self {
        Self {
            stream: Vec::from(buf),
            ..default::Default::default()
        }
    }
}

impl convert::From<Vec<Token>> for BytecodeStream {
    /// Creates a new instance from a vec.
    fn from(vec: Vec<Token>) -> Self {
        Self {
            stream: vec,
            ..default::Default::default()
        }
    }
}

impl default::Default for BytecodeStream {
    /// Same as new()
    fn default() -> Self {
        Self::new()
    }
}
