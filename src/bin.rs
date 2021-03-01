extern crate ronin_runtime;

use ronin_runtime::prelude::*;

fn main() {
    let mut bytecode = BytecodeStream::new();
    bytecode.for_loop(
        0,
        100,
        &[Token::Opc(OpCode::Intrin), Token::Int(IntId::PutChar)],
    );
    bytecode.evaluate_pins();
    println!("{}", bytecode);

    let chunk = bytecode.build();
    println!("{}", chunk);
}
