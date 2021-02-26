extern crate ronin_runtime;

use ronin_runtime::prelude::*;
use std::time::Instant;

fn main() {
    let clock = Instant::now();
    let mut stream = BytecodeStream::new();
    stream.prologue();
    /*
        push #0
        inc
        dupl
        push #5
        push #*
        intrin #0
        jl #&5
        pop #1
    */
    for _ in 0..30_000 {
        stream.with(OpCode(Op::Push)).with(I32(0));
        stream.with(OpCode(Op::I32Increment));
        stream.with(OpCode(Op::Duplicate));
        stream.with(OpCode(Op::Push)).with(I32(5));
        for c1 in "Hello, World!\n".chars() {
            stream.with(OpCode(Op::Push)).with(C32(c1));
            stream
                .with(OpCode(Op::CallIntrinsic))
                .with(Ipc(Intrinsics::PutChar));
        }
        stream.with(OpCode(Op::JumpIfLess)).with(Pin(5));
        stream.with(OpCode(Op::Pop)).with(I32(1));
    }
    stream.epilogue();
    let chunk = stream.build(ValidationPolicy::Basic);
    let input = ExecutorInput {
        chunk,
        stack: Stack::with_byte_size(1024 * 1024),
        fixed: Some(0xFF),
    };
    let _output = execute(input);
    println!("Executed VM in {}s!", clock.elapsed().as_secs_f64());
}
