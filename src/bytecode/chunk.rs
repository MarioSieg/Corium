use crate::bytecode::signal::Signal;
use std::{convert, ops};

/// A fixed size chunk of bytecode, which can be executed by the VM.
/// The bytecode inside is validated and optimized and ready for execution.
#[derive(Clone, Debug)]
pub struct BytecodeChunk {
    buf: Box<[Signal]>,
    ip: usize,
}

impl BytecodeChunk {
    /// Returns an immutable reference to the underlying command buffer.
    #[inline(always)]
    pub fn buffer(&self) -> &[Signal] {
        &self.buf
    }

    /// Returns the underlying command buffer.
    #[inline(always)]
    pub fn mov_buffer(self) -> Box<[Signal]> {
        self.buf
    }

    /// Returns an immutable pointer to the underlying command buffer array data.
    #[inline(always)]
    pub fn as_ptr(&self) -> *const Signal {
        self.buf.as_ptr()
    }

    /// Returns an mutable pointer to the underlying command buffer array data.
    #[inline(always)]
    pub fn as_mut_ptr(&mut self) -> *mut Signal {
        self.buf.as_mut_ptr()
    }

    /// Returns the amount of signals inside the command buffer.
    #[inline(always)]
    pub fn length(&self) -> usize {
        self.buf.len()
    }

    /// Returns true if the command buffer is empty, else false.
    #[inline(always)]
    pub fn is_empty(&self) -> bool {
        self.buf.is_empty()
    }

    /// Returns the estimated amount of bytes this instance takes up in memory.
    #[inline(always)]
    pub fn size(&self) -> usize {
        self.buf.len() * std::mem::size_of::<Signal>()
    }

    /// Returns the operation pointer.
    #[inline(always)]
    pub fn operation_ptr(&self) -> usize {
        self.ip
    }

    /// Jumps to a specific address in the command buffer.
    /// If this address does not exist it will panic in debug bulids.
    #[inline(always)]
    pub fn jump(&mut self, ip: usize) {
        debug_assert!(ip < self.buf.len(), "VM_BytecodeChunk_InvalidJumpAddress");
        self.ip = ip
    }

    /// Fetches the next signal from the command buffer
    /// and increments the operation pointer by one.
    #[inline(always)]
    pub fn fetch(&mut self) -> Signal {
        debug_assert!(
            self.ip < self.buf.len(),
            "VM_BytecodeChunk_BytecodeBufferEnd"
        );
        let record = self.buf[self.ip];
        self.ip += 1;
        record
    }

    /// Returns true if the operation pointer reached the end of the command buffer,
    /// else false.
    #[inline(always)]
    pub fn is_done(&self) -> bool {
        self.ip >= self.buf.len()
    }
}

impl ops::Index<usize> for BytecodeChunk {
    type Output = Signal;

    /// Returns the element at 'idx'.
    #[inline(always)]
    fn index(&self, idx: usize) -> &Self::Output {
        &self.buf[idx]
    }
}

impl ops::IndexMut<usize> for BytecodeChunk {
    /// Returns the element at 'idx'.
    #[inline(always)]
    fn index_mut(&mut self, idx: usize) -> &mut Self::Output {
        &mut self.buf[idx]
    }
}

impl convert::From<Box<[Signal]>> for BytecodeChunk {
    fn from(buf: Box<[Signal]>) -> Self {
        assert_ne!(buf.len(), 0);
        Self { buf, ip: 0 }
    }
}

impl convert::From<(Box<[Signal]>, usize)> for BytecodeChunk {
    fn from(buf: (Box<[Signal]>, usize)) -> Self {
        assert_ne!(buf.0.len(), 0);
        Self {
            ip: buf.1,
            buf: buf.0,
        }
    }
}

impl convert::From<Vec<Signal>> for BytecodeChunk {
    fn from(buf: Vec<Signal>) -> Self {
        assert_ne!(buf.len(), 0);
        Self {
            buf: buf.into_boxed_slice(),
            ip: 0,
        }
    }
}

#[cfg(test)]
mod tests {
    use crate::bytecode::{
        ast::{
            OpCode::{self, *},
            Token,
        },
        stream::{BytecodeStream, ValidationPolicy},
    };

    #[test]
    fn fetch() {
        let mut code = BytecodeStream::new();
        code.with(Token::Opc(Push)).with(Token::I32(3));
        code.with(Token::Opc(Push)).with(Token::I32(8));
        code.with(Token::Opc(I32Multiplication));
        let mut code = code.build(ValidationPolicy::Full);
        assert_eq!(OpCode::from(code.fetch()), Push);
        assert_eq!(i32::from(code.fetch()), 3);
        assert_eq!(OpCode::from(code.fetch()), Push);
        assert_eq!(i32::from(code.fetch()), 8);
        assert_eq!(OpCode::from(code.fetch()), I32Multiplication);
        assert!(code.is_done());
    }

    #[test]
    fn jump() {
        let mut code = BytecodeStream::new();
        code.with(Token::Opc(Push)).with(Token::I32(3));
        code.with(Token::Opc(Push)).with(Token::I32(8));
        code.with(Token::Opc(I32Multiplication));
        let mut code = code.build(ValidationPolicy::Full);
        assert_eq!(OpCode::from(code.fetch()), Push);
        assert_eq!(i32::from(code.fetch()), 3);
        assert_eq!(OpCode::from(code.fetch()), Push);
        assert_eq!(i32::from(code.fetch()), 8);
        assert_eq!(OpCode::from(code.fetch()), I32Multiplication);
        assert!(code.is_done());
        code.jump(0);
        assert_eq!(OpCode::from(code.fetch()), Push);
    }
}
