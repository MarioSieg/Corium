/// Bytecode AST (Abstract Syntax Tree) representation.
pub mod ast;

/// The bytecode chunk, which the VM can execute.
pub mod chunk;

/// Meta data about bytecode operations and syntax.
pub mod descriptors;

/// All intrinsic operation codes.
pub mod intrinsic;

/// Lexemes, mnemonic and syntax tokens as strings and chars.
pub mod lexemes;

/// The signal, which is the runtime version of an AST token.
pub mod signal;

/// The bytecode stream, which can be used to build bytecode in software.
pub mod stream;

/// Algorithms and tools to validate a bytecode stream before executing it as a bytecode chunk.
pub mod validator;
