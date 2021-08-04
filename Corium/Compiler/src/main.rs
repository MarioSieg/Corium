#![allow(dead_code)]

mod ast;
mod error;
mod literal;
mod parser;
mod unit;

use unit::CompilationUnit;

fn main() {
    let cu = CompilationUnit::load_from_file(std::path::PathBuf::from("../Docs/ParseTest.cor"));
    let clock = std::time::Instant::now();
    cu.compile().unwrap();
    println!("Compiled in {}s", clock.elapsed().as_secs_f32());
}
