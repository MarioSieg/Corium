#![allow(dead_code)]

mod ast;
mod error;
mod literal;
mod parser;
mod unit;
mod context;

fn main() {
    let mut context = context::CompilerContext::new();
    context.enqueue_file("../Docs/ParseTest.cor");
    context.compile();
}
