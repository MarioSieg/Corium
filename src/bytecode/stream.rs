use super::ast::{OpCode, Token};
use super::chunk::BytecodeChunk;
use super::descriptors;
use super::validator;
use std::{convert, default, fmt, ops};

/// A bytecode stream is used to dynamically build bytecode.
/// When building is done, the next step is validating.
/// The validator checks if there are any invalid operations,
/// values and parameters in the bytecode.
/// If validation is successful, it can get converted
/// into a bytecode chunk, which then can get executed by a VM executor kernel.
pub struct BytecodeStream {
    stream: Vec<Token>,
    last_op_idx: usize,
    ops_count: usize,
    args_count: usize,
}

impl BytecodeStream {
    /// Inserts common prologue code into the bytecode stream.
    /// This always should be called when a new instance is created
    /// and before any operations/arguments are there.
    fn prologue(mut self) -> Self {
        // The first record of the stack (0x00000000) is always unused because of the stack
        // pointer layout. So we fill it with some random value using the MOV operation.
        self.with(Token::Opc(OpCode::Move)) // Move to stack slot.
            .with(Token::U32(0)) // Into first stack slot (0x00000000)
            .with(Token::U32(u32::from_le_bytes(*b"LOVE"))); // (4 * u8) Because I love my cutie!
        self
    }

    /// Inserts common prologue code into the bytecode stream.
    /// This always should be called when building is done.
    fn epilogue(mut self) -> Self {
        // Add interrupt as last operation because
        // there are no operation pointer out of range checks
        // for performance.
        self.with(Token::Opc(OpCode::Interrupt)).with(Token::I32(0));
        self
    }

    /// Creates a new, empty bytecode stream.
    #[inline]
    pub fn new() -> Self {
        Self {
            stream: Vec::new(),
            last_op_idx: 0,
            ops_count: 0,
            args_count: 0,
        }
        .prologue()
    }

    /// Creates a new, empty instance with a specified
    /// capacity for the command and jump table buffer.
    #[inline]
    pub fn with_capacity(capacity: usize) -> Self {
        Self {
            stream: Vec::with_capacity(capacity),
            last_op_idx: 0,
            ops_count: 0,
            args_count: 0,
        }
        .prologue()
    }

    // Pushes a new token.
    pub fn with(&mut self, tok: Token) -> &mut Self {
        if tok.is_instr() {
            self.ops_count += 1;
        } else if tok.is_imm() {
            self.args_count += 1;
        }
        self.stream.push(tok);
        self
    }

    /// Returns the index to the last signal.
    #[inline]
    pub fn index(&self) -> usize {
        self.stream.len() - 1
    }

    /// Returns the index to the last signal, which was an operation.
    #[inline]
    pub fn last_opcode_index(&self) -> usize {
        self.last_op_idx
    }

    /// Returns the total count of signals, which are operations.
    #[inline]
    pub fn operation_count(&self) -> usize {
        self.ops_count
    }

    /// Returns the total count of signals, which are operation arguments.
    #[inline]
    pub fn argument_count(&self) -> usize {
        self.args_count
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

    /// Returns the last signal, which was an opcode (if any),
    /// else None.
    pub fn last_opcode(&self) -> Option<OpCode> {
        debug_assert!(!self.is_empty());
        if let Token::Opc(op) = self[self.last_op_idx] {
            Some(op)
        } else {
            None
        }
    }

    /// Returns a slice of the parameters of the stack operation.
    /// Returns none if there are none or the operation index is invalid.
    pub fn last_explicit_opcode_args(&self) -> Option<&[Token]> {
        debug_assert!(!self.is_empty());
        if let Some(op) = self.last_opcode() {
            if let Some(arg_count) = descriptors::EXPLICIT_ARGUMENTS[op as usize] {
                Some(&self.stream[self.last_op_idx..=self.last_op_idx + arg_count.len()])
            } else {
                None
            }
        } else {
            None
        }
    }

    /// Validates this bytecode and returns an list of error messages (if any).
    #[inline]
    pub fn validate(&self, sec: validator::ValidationPolicy) {
        validator::validate(&self.stream[..], sec)
    }

    /// Builds and validates this bytecode and returns an list of error messages (if any).
    /// On success this returns the bytecode chunk, which can be injected into a VM executor kernel.
    pub fn build(mut self, sec: validator::ValidationPolicy) -> BytecodeChunk {
        assert!(!self.is_empty());
        self = self.epilogue();
        validator::validate(&self.stream[..], sec);
        let buf = validator::build(&self.stream[..]);
        BytecodeChunk::from(buf)
    }
}

impl fmt::Display for BytecodeStream {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        for tok in &self.stream {
            if tok.is_instr() {
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
            if tok.is_instr() {
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
            last_op_idx: 0,
            ops_count: 0,
            args_count: 0,
        }
    }
}

impl convert::From<Vec<Token>> for BytecodeStream {
    /// Creates a new instance from a vec.
    fn from(vec: Vec<Token>) -> Self {
        Self {
            stream: vec,
            last_op_idx: 0,
            ops_count: 0,
            args_count: 0,
        }
    }
}

impl default::Default for BytecodeStream {
    /// Same as new()
    fn default() -> Self {
        Self::new()
    }
}
