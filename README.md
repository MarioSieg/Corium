# Ronin Virtual Machine
![alt](https://img.shields.io/github/license/MarioSieg/NominaxRonVM)
![alt](https://img.shields.io/appveyor/build/MarioSieg/NominaxRonVM)
![alt](https://img.shields.io/tokei/lines/github/MarioSieg/NominaxRonVM)
![alt](https://img.shields.io/github/repo-size/MarioSieg/NominaxRonVM)

# What is it?
The Ronin Virtual Machine is a modular, flexible and modern runtime for scripting languages.
Parallelism and speed is one of the main features. The idea was to create a runtime which automatically
runs code in parallel, if it could increase performance.
For the implementation, multithreading, GPU offloading (GP-GPU) and SIMD is used.
It also features a bytecode optimizer, validator, JIT compiler, debugger and analyzer.

# Planned Features
 * Target systems: PC, Mac, Linux, IOS, Android.
 * Parallel subsystems (JIT, optimizer, validator etc).
 * Parallel runtime and instructions (Iterators, VM Kernels, Ports).
 * SIMD instructions and special optimizations using SSE4.1, AVX, AVX-512 and FMA for x86_64.
 * GPU offloading (GPGPU) using cuda and vulkan compute shaders.
 * Flexible bytecode design and builder to build a backend for your custom language.
 * C backend for GCC, Clang with computed goto branch table optimization (not yet online).
 
 # To run it
 To see some multithreading in action first run:
 "cargo run --release --no-default-features"
 this will do all the work on only one thread.
 The console will output the time needed.
 Now run:
  "cargo run --release"
  And you will see how all CPU cores are used (Task Manager)
and the work will be done much more quicker!
 
 # Languages
* Rust     (primary)
* Assembly (some JIT and SIMD optimized code)
* RonAsm   (custom bytecode-language snippets)
* C++      (the assembler for the JIT compiler is written in C++ 20 but not included here)
* C        AVX 512 SIMD extensions are written using C intrinsics (immintrin.h) because Rust does not yet support them

# Instruction Set
| Name                                                                  | Mnemonic  | Opcode | Category                | Arguments (Explicit)    | Stack Arguments (Implicit)         | C Operator | Mathematical    |
|-----------------------------------------------------------------------|-----------|--------|-------------------------|-------------------------|------------------------------------|------------|-----------------|
| Interrupt                                                             | INTERRUPT | 0h     | Control                 | interrupt_id: i32       |                                    |            |                 |
| Call intrinsic                                                        | INTRIN    | 1h     | Control                 | intrin_id: u32          | …                                  |            |                 |
| No operation                                                          | NOP       | 2h     | Control                 |                         |                                    |            |                 |
| Call subroutine                                                       | CALL      | 3h     | Control                 | routine_id: u32         | …                                  | ()         | ()              |
| Return from subroutine                                                | RET       | 4h     | Control                 |                         |                                    | return     |                 |
| Push                                                                  | PUSH      | 5h     | Memory                  | const: *                |                                    |            |                 |
| Pop                                                                   | POP       | 6h     | Memory                  | count: i32              | …                                  |            |                 |
| Move                                                                  | MOV       | 7h     | Memory                  |  dst: u32; src: *       | @dst                               |            |                 |
| Copy                                                                  | CPY       | 8h     | Memory                  | dst: u32; src: u32      | @dst, @src                         |            |                 |
| Duplicate                                                             | DUPL      | 9h     | Memory                  |                         | src: *                             |            |                 |
| Double Duplicate                                                      | DDUPL     | Ah     | Memory                  |                         | src: *                             |            |                 |
| Cast i32 to f32                                                       | CASTI2F   | Bh     | Memory                  |                         | src: *                             |            |                 |
| Cast f32 to i32                                                       | CASTF2I   | Ch     | Memory                  |                         | src: *                             |            |                 |
| Jump unconditionally                                                  | JMP       | Dh     | Branching               | to: u32                 |                                    | goto       |                 |
| Jump if zero                                                          | JZ        | Eh     | Branching               | x: i32;  y: u32         | x: i32                             | x == 0     | x ≡ 0           |
| Jump if not zero                                                      | JNZ       | Fh     | Branching               | x: i32;  y: u32         | x: i32                             | x != 0     | x ≠ 0           |
| Jump if equals                                                        | JE        | 10h    | Branching               | x: i32; y: i32; to: u32 | x: i32; y: i32                     | x == y     | x ≡ y           |
| Jump if not equals                                                    | JNE       | 11h    | Branching               | x: i32; y: i32; to: u32 | x: i32; y: i32                     |  x != y    | x ≠ y           |
| Jump if above                                                         | JA        | 12h    | Branching               | x: i32; y: i32; to: u32 | x: i32; y: i32                     | x > y      | x > y           |
| Jump if above equals                                                  | JAE       | 13h    | Branching               | x: i32; y: i32; to: u32 | x: i32; y: i32                     | x >= y     | x ≥ y           |
| Jump if less                                                          | JL        | 14h    | Branching               | x: i32; y: i32; to: u32 | x: i32; y: i32                     | x < y      | x < y           |
| Jump if less equals                                                   | JLE       | 15h    | Branching               | x: i32; y: i32; to: u32 | x: i32; y: i32                     | x <= y     | x ≤ y           |
| Addition with two i32                                                 | IADD      | 16h    | Arithmetics             |                         | x: i32; y: i32                     | +          | x = x + y       |
| Subtraction with two i32                                              | ISUB      | 17h    | Arithmetics             |                         | x: i32; y: i32                     | -          | x = x - y       |
| Multiplication with two i32                                           | IMUL      | 18h    | Arithmetics             |                         | x: i32; y: i32                     | *          | x = x ∙ y       |
| Division with two i32                                                 | IDIV      | 19h    | Arithmetics             |                         | x: i32; y: i32                     | /          | x = x ÷ y       |
| Remainder (Modulo) with two i32                                       | IMOD      | 1Ah    | Arithmetics             |                         | x: i32; y: i32                     | %          | x = x mod y     |
| Bitwise AND with two i32                                              | IAND      | 1Bh    | Arithmetics             |                         | x: i32; y: i32                     | &          | x = x ∧ y       |
| Bitwise OR with two i32                                               | IOR       | 1Ch    | Arithmetics             |                         | x: i32; y: i32                     | |          | x = x ∨ y       |
| Bitwise XOR with two i32                                              | IXOR      | 1Dh    | Arithmetics             |                         | x: i32; y: i32                     | ^          | x = x ⊻ y       |
| Bitwise airthmetic left shift with two i32                            | ISAL      | 1Eh    | Arithmetics             |                         | x: i32; y: i32                     | <<         | x = x << y      |
| Bitwise airthmetic right shift with two i32                           | ISAR      | 1Fh    | Arithmetics             |                         | x: i32; y: i32                     | >>         | x = x >> y      |
| Bitwise circular left shift (bitwise rolling) with two i32            | IROL      | 20h    | Arithmetics             |                         | x: i32; y: i32                     |            | x = x <<< y     |
| Bitwise circular right shift (bitwise rolling) with two i32           | IROR      | 21h    | Arithmetics             |                         | x: i32; y: i32                     |            | x = x >>> y     |
| Bitwise complement (negation) with one i32                            | ICOM      | 22h    | Arithmetics             |                         | x: i32                             | ~          | x = ¬x          |
| Increment by one with one i32                                         | IINC      | 23h    | Arithmetics             |                         | x: i32                             | ++         | x = x + 1       |
| Decrement by one with one i32                                         | IDEC      | 24h    | Arithmetics             |                         | x: i32                             | --         | x = x - 1       |
| Addition with two f32                                                 | FADD      | 25h    | Arithmetics             |                         | x: f32; y: f32                     | +          | x = x + y       |
| Subtraction with two f32                                              | FSUB      | 26h    | Arithmetics             |                         | x: f32; y: f32                     | -          | x = x - y       |
| Multiplication with two f32                                           | FMUL      | 27h    | Arithmetics             |                         | x: f32; y: f32                     | *          | x = x ∙ y       |
| Division with two f32                                                 | FDIV      | 28h    | Arithmetics             |                         | x: f32; y: f32                     | /          | x = x ÷ y       |
| Remainder (Modulo) with two f32                                       | FMOD      | 29h    | Arithmetics             |                         | x: f32; y: f32                     | (%)        | x = x mod y     |
| Fused multiply add with two f32                                       | FFMA      | 2Ah    | Arithmetics             |                         | x: f32; y: f32; z: f32             |            | x = (x ∙ y) + z |
| Addition with four i32 (SSE)                                          | VQUADIADD | 2Bh    | SIMD Vector Arithmetics |                         | x: i32[4]; y: i32[4]               | +          | x = x + y       |
| Subtraction with four i32 (SSE)                                       | VQUADISUB | 2Ch    | SIMD Vector Arithmetics |                         | x: i32[4]; y: i32[4]               | -          | x = x - y       |
| Multiplication with four i32 (SSE)                                    | VQUADIMUL | 2Dh    | SIMD Vector Arithmetics |                         | x: i32[4]; y: i32[4]               | *          | x = x ∙ y       |
| Division with four i32 (SSE)                                          | VQUADIDIV | 2Eh    | SIMD Vector Arithmetics |                         | x: i32[4]; y: i32[4]               | /          | x = x ÷ y       |
| Remainer (modulo) with four i32 (SSE)                                 | VQUADIMOD | 2Fh    | SIMD Vector Arithmetics |                         | x: i32[4]; y: i32[4]               | %          | x = x mod y     |
| Bitwise AND with four i32 (SSE)                                       | VQUADIAND | 30h    | SIMD Vector Arithmetics |                         | x: i32[4]; y: i32[4]               | &          | x = x ∧ y       |
| Bitwise OR with four i32 (SSE)                                        | VQUADIOR  | 31h    | SIMD Vector Arithmetics |                         | x: i32[4]; y: i32[4]               | |          | x = x ∨ y       |
| Bitwise XOR with four i32 (SSE)                                       | VQUADIXOR | 32h    | SIMD Vector Arithmetics |                         | x: i32[4]; y: i32[4]               | ^          | x = x ⊻ y       |
| Bitwise airthmetic left shift with four i32 (SSE)                     | VQUADISAL | 33h    | SIMD Vector Arithmetics |                         | x: i32[4]; y: i32[4]               | <<         | x = x << y      |
| Bitwise airthmetic right shift with four i32 (SSE)                    | VQUADISAR | 34h    | SIMD Vector Arithmetics |                         | x: i32[4]; y: i32[4]               | >>         | x = x >> y      |
| Bitwise circular left shift (bitwise rolling) with four i32 (SSE)     | VQUADIROL | 35h    | SIMD Vector Arithmetics |                         | x: i32[4]; y: i32[4]               |            | x = x <<< y     |
| Bitwise circular right shift (bitwise rolling) with four i32 (SSE)    | VQUADIROR | 36h    | SIMD Vector Arithmetics |                         | x: i32[4]; y: i32[4]               |            | x = x >>> y     |
| Bitwise complement (negation) with four i32 (SSE)                     | VQUADICOM | 37h    | SIMD Vector Arithmetics |                         | x: i32[4]; y: i32[4]               | ~          | x = ¬x          |
| Addition with four f32 (SSE)                                          | VQUADFADD | 38h    | SIMD Vector Arithmetics |                         | x: f32[4]; y: f32[4]               | +          | x = x + y       |
| Subtraction with four f32 (SSE)                                       | VQUADFSUB | 39h    | SIMD Vector Arithmetics |                         | x: f32[4]; y: f32[4]               | -          | x = x - y       |
| Multiplication with four f32 (SSE)                                    | VQUADFMUL | 3Ah    | SIMD Vector Arithmetics |                         | x: f32[4]; y: f32[4]               | *          | x = x ∙ y       |
| Division with four f32 (SSE)                                          | VQUADFDIV | 3Bh    | SIMD Vector Arithmetics |                         | x: f32[4]; y: f32[4]               | /          | x = x ÷ y       |
| Remainer (modulo) with four f32 (SSE)                                 | VQUADFMOD | 3Ch    | SIMD Vector Arithmetics |                         | x: f32[4]; y: f32[4]               | %          | x = x mod y     |
| Fused multiply add with four f32 (SSE)                                | VQUADFFMA | 3Dh    | SIMD Vector Arithmetics |                         | x: f32[4]; y: f32[4]; z: f32[4]    |            | x = (x ∙ y) + z |
| Addition with eight i32 (SSE)                                         | VOCTAIADD | 3Eh    | SIMD Vector Arithmetics |                         | x: i32[8]; y: i32[8]               | +          | x = x + y       |
| Subtraction with eight i32 (SSE)                                      | VOCTAISUB | 3Fh    | SIMD Vector Arithmetics |                         | x: i32[8]; y: i32[8]               | -          | x = x - y       |
| Multiplication with eight i32 (SSE)                                   | VOCTAIMUL | 40h    | SIMD Vector Arithmetics |                         | x: i32[8]; y: i32[8]               | *          | x = x ∙ y       |
| Division with eight i32 (SSE)                                         | VOCTAIDIV | 41h    | SIMD Vector Arithmetics |                         | x: i32[8]; y: i32[8]               | /          | x = x ÷ y       |
| Remainer (modulo) with eight i32 (SSE)                                | VOCTAIMOD | 42h    | SIMD Vector Arithmetics |                         | x: i32[8]; y: i32[8]               | %          | x = x mod y     |
| Bitwise AND with eight i32 (SSE)                                      | VOCTAIAND | 43h    | SIMD Vector Arithmetics |                         | x: i32[8]; y: i32[8]               | &          | x = x ∧ y       |
| Bitwise OR with eight i32 (SSE)                                       | VOCTAIOR  | 44h    | SIMD Vector Arithmetics |                         | x: i32[8]; y: i32[8]               | |          | x = x ∨ y       |
| Bitwise XOR witheight i32 (SSE)                                       | VOCTAIXOR | 45h    | SIMD Vector Arithmetics |                         | x: i32[8]; y: i32[8]               | ^          | x = x ⊻ y       |
| Bitwise airthmetic left shift with eight i32 (SSE)                    | VOCTAISAL | 46h    | SIMD Vector Arithmetics |                         | x: i32[8]; y: i32[8]               | <<         | x = x << y      |
| Bitwise airthmetic right shift with eight i32 (SSE)                   | VOCTAISAR | 47h    | SIMD Vector Arithmetics |                         | x: i32[8]; y: i32[8]               | >>         | x = x >> y      |
| Bitwise circular left shift (bitwise rolling) with eight i32 (SSE)    | VOCTAIROL | 48h    | SIMD Vector Arithmetics |                         | x: i32[8]; y: i32[8]               |            | x = x <<< y     |
| Bitwise circular right shift (bitwise rolling) with eight i32 (SSE)   | VOCTAIROR | 49h    | SIMD Vector Arithmetics |                         | x: i32[8]; y: i32[8]               |            | x = x >>> y     |
| Bitwise complement (negation) with eight i32 (SSE)                    | VOCTAICOM | 4Ah    | SIMD Vector Arithmetics |                         | x: i32[8]; y: i32[8]               | ~          | x = ¬x          |
| Addition with eight f32 (SSE)                                         | VOCTAFADD | 4Bh    | SIMD Vector Arithmetics |                         | x: f32[8]; y: f32[8]               | +          | x = x + y       |
| Subtraction with eight f32 (SSE)                                      | VOCTAFSUB | 4Ch    | SIMD Vector Arithmetics |                         | x: f32[8]; y: f32[8]               | -          | x = x - y       |
| Multiplication with eight f32 (SSE)                                   | VOCTAFMUL | 4Dh    | SIMD Vector Arithmetics |                         | x: f32[8]; y: f32[8]               | *          | x = x ∙ y       |
| Division with eight f32 (SSE)                                         | VOCTAFDIV | 4Eh    | SIMD Vector Arithmetics |                         | x: f32[8]; y: f32[8]               | /          | x = x ÷ y       |
| Remainer (modulo) with eight f32 (SSE)                                | VOCTAFMOD | 4Fh    | SIMD Vector Arithmetics |                         | x: f32[8]; y: f32[8]               | %          | x = x mod y     |
| Fused multiply add with eight f32 (SSE)                               | VOCTAFFMA | 50h    | SIMD Vector Arithmetics |                         | x: f32[8]; y: f32[8]; z: f32[8]    |            | x = (x ∙ y) + z |
| Addition with sixteen i32 (SSE)                                       | VHEXAIADD | 51h    | SIMD Vector Arithmetics |                         | x: i32[16]; y: i32[16]             | +          | x = x + y       |
| Subtraction with sixteen i32 (SSE)                                    | VHEXAISUB | 52h    | SIMD Vector Arithmetics |                         | x: i32[16]; y: i32[16]             | -          | x = x - y       |
| Multiplication with sixteen i32 (SSE)                                 | VHEXAIMUL | 53h    | SIMD Vector Arithmetics |                         | x: i32[16]; y: i32[16]             | *          | x = x ∙ y       |
| Division with sixteen i32 (SSE)                                       | VHEXAIDIV | 54h    | SIMD Vector Arithmetics |                         | x: i32[16]; y: i32[16]             | /          | x = x ÷ y       |
| Remainer (modulo) with sixteen i32 (SSE)                              | VHEXAIMOD | 55h    | SIMD Vector Arithmetics |                         | x: i32[16]; y: i32[16]             | %          | x = x mod y     |
| Bitwise AND with sixteen i32 (SSE)                                    | VHEXAIAND | 56h    | SIMD Vector Arithmetics |                         | x: i32[16]; y: i32[16]             | &          | x = x ∧ y       |
| Bitwise OR with sixteen i32 (SSE)                                     | VHEXAIOR  | 57h    | SIMD Vector Arithmetics |                         | x: i32[16]; y: i32[16]             | |          | x = x ∨ y       |
| Bitwise XOR with sixteen i32 (SSE)                                    | VHEXAIXOR | 58h    | SIMD Vector Arithmetics |                         | x: i32[16]; y: i32[16]             | ^          | x = x ⊻ y       |
| Bitwise airthmetic left shift with sixteen i32 (SSE)                  | VHEXAISAL | 59h    | SIMD Vector Arithmetics |                         | x: i32[16]; y: i32[16]             | <<         | x = x << y      |
| Bitwise airthmetic right shift with sixteen i32 (SSE)                 | VHEXAISAR | 5Ah    | SIMD Vector Arithmetics |                         | x: i32[16]; y: i32[16]             | >>         | x = x >> y      |
| Bitwise circular left shift (bitwise rolling) with sixteen i32 (SSE)  | VHEXAIROL | 5Bh    | SIMD Vector Arithmetics |                         | x: i32[16]; y: i32[16]             |            | x = x <<< y     |
| Bitwise circular right shift (bitwise rolling) with sixteen i32 (SSE) | VHEXAIROR | 5Ch    | SIMD Vector Arithmetics |                         | x: i32[16]; y: i32[16]             |            | x = x >>> y     |
| Bitwise complement (negation) with sixteen i32 (SSE)                  | VHEXAICOM | 5Dh    | SIMD Vector Arithmetics |                         | x: i32[16]; y: i32[16]             | ~          | x = ¬x          |
| Addition with sixteen f32 (SSE)                                       | VHEXAFADD | 5Eh    | SIMD Vector Arithmetics |                         | x: f32[16]; y: f32[16]             | +          | x = x + y       |
| Subtraction with sixteen f32 (SSE)                                    | VHEXAFSUB | 5Fh    | SIMD Vector Arithmetics |                         | x: f32[16]; y: f32[16]             | -          | x = x - y       |
| Multiplication with sixteen f32 (SSE)                                 | VHEXAFMUL | 60h    | SIMD Vector Arithmetics |                         | x: f32[16]; y: f32[16]             | *          | x = x ∙ y       |
| Division with sixteen f32 (SSE)                                       | VHEXAFDIV | 61h    | SIMD Vector Arithmetics |                         | x: f32[16]; y: f32[16]             | /          | x = x ÷ y       |
| Remainer (modulo) with sixteen f32 (SSE)                              | VHEXAFMOD | 62h    | SIMD Vector Arithmetics |                         | x: f32[16]; y: f32[16]             | %          | x = x mod y     |
| Fused multiply add with sixteen f32 (SSE)                             | VHEXAFFMA | 63h    | SIMD Vector Arithmetics |                         | x: f32[16]; y: f32[16]; z: f32[16] |            | x = (x ∙ y) + z |
