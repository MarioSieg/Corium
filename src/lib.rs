/// Bytecode data, ast, parser, optimizer, validator.
pub mod bytecode;

/// Executor, stack, record, hooks and core implementation.
pub mod core;

/// Most used modules for a quick import.
pub mod prelude;

/// SIMD (Single Instruction Multiple Data) tools for i32 and f32.
pub mod simd;

/// Tools and adapters for multithreaded parallelism.
pub mod par;
