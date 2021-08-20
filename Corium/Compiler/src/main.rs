#![allow(dead_code)]

mod ast;
mod cli;
mod error;
mod literal;
mod parser;
mod unit;

fn main() {
    cli::process_args();
}
