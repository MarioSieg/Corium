#![allow(dead_code)]

mod ast;
mod compilation_unit;
mod error;
mod literal;
mod parser;

use compilation_unit::CompilationUnit;

fn main() {
    let cu = CompilationUnit::load_from_file(std::path::PathBuf::from("Test.csv"));
    assert!(cu.compile().is_ok());
}
