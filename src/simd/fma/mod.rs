// Currently we do use the unaligned loads/stores (loadu, storeu) which is okay.
// There might be a small 10% performance impact. If this turns out to be more in benchmarks,
// we should align everything properly.
#![allow(clippy::cast_ptr_alignment)]
#![allow(dead_code)]

pub mod f32;
