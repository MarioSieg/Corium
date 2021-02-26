extern crate ronin_runtime;

use ronin_runtime::prelude::*;

fn main() {
    let mut bytecode = BytecodeStream::new();
    bytecode.with(Token::Opc(OpCode::Push));
    bytecode.with(Token::I32(0xFFFFF));
    println!("{:?}", bytecode);
}
