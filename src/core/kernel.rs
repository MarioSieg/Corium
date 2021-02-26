use super::stack::Stack;
use crate::bytecode::chunk::BytecodeChunk;
use std::fmt;

#[derive(Clone)]
pub struct Kernel {
    pub id: u64,
    pub stack: Stack,
    pub descriptor: String,
    pub index: usize,
    pub chunk: BytecodeChunk,
}

impl fmt::Debug for Kernel {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        writeln!(
            f,
            "id: {}, stack: {}, descriptor: {}, index: {}",
            self.id,
            self.stack.size(),
            self.descriptor,
            self.index
        )?;
        for sig in self.chunk.buffer().iter() {
            writeln!(f, "{}", sig)?;
        }
        Ok(())
    }
}
