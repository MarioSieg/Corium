# NominaxRonVM
 Ronin Virtual Machine

| Name                                           | Mnemonic  | Opcode | Category    | Arguments (Explicit)    | Stack Arguments (Implicit) | C Operator | Mathematical    |
|------------------------------------------------|-----------|--------|-------------|-------------------------|----------------------------|------------|-----------------|
| Interrupt                                      | INTERRUPT | 0h     | Control     | interrupt_id: i32       |                            |            |                 |
| Call to intrinsic                              | INTRIN    | 1h     | Control     | intrin_id: u32          | …                          |            |                 |
| No operation                                   | NOP       | 2h     | Control     |                         |                            |            |                 |
| Push                                           | PUSH      | 3h     | Memory      | const: *                |                            |            |                 |
| Pop                                            | POP       | 4h     | Memory      | count: i32              | …                          |            |                 |
| Move                                           | MOV       | 5h     | Memory      |  dst: u32; src: *       | @dst                       |            |                 |
| Copy                                           | CPY       | 6h     | Memory      | dst: u32; src: u32      | @dst, @src                 |            |                 |
| Duplicate                                      | DUPL      | 7h     | Memory      |                         | src: *                     |            |                 |
| Double Duplicate                               | DDUPL     | 8h     | Memory      |                         | src: *                     |            |                 |
| Cast i32 to f32                                | CASTI2F   | 9h     | Memory      |                         | src: *                     |            |                 |
| Cast f32 to i32                                | CASTF2I   | Ah     | Memory      |                         | src: *                     |            |                 |
| Jump unconditionally                           | JMP       | Bh     | Branching   | to: u32                 |                            | goto       |                 |
| Jump if zero                                   | JZ        | Ch     | Branching   | x: i32;  y: u32         | x: i32                     | x == 0     | x ≡ 0           |
| Jump if not zero                               | JNZ       | Dh     | Branching   | x: i32;  y: u32         | x: i32                     | x != 0     | x ≠ 0           |
| Jump if equals                                 | JE        | Eh     | Branching   | x: i32; y: i32; to: u32 | x: i32; y: i32             | x == y     | x ≡ y           |
| Jump if not equals                             | JNE       | Fh     | Branching   | x: i32; y: i32; to: u32 | x: i32; y: i32             |  x != y    | x ≠ y           |
| Jump if above                                  | JA        | 10h    | Branching   | x: i32; y: i32; to: u32 | x: i32; y: i32             | x > y      | x > y           |
| Jump if above equals                           | JAE       | 11h    | Branching   | x: i32; y: i32; to: u32 | x: i32; y: i32             | x >= y     | x ≥ y           |
| Jump if less                                   | JL        | 12h    | Branching   | x: i32; y: i32; to: u32 | x: i32; y: i32             | x < y      | x < y           |
| Jump if less equals                            | JLE       | 13h    | Branching   | x: i32; y: i32; to: u32 | x: i32; y: i32             | x <= y     | x ≤ y           |
| Addition with two i32                          | IADD      | 14h    | Arithmetics |                         | x: i32; y: i32             | +          | x = x + y       |
| Subtraction with two i32                       | ISUB      | 15h    | Arithmetics |                         | x: i32; y: i32             | -          | x = x - y       |
| Multiplication with two i32                    | IMUL      | 16h    | Arithmetics |                         | x: i32; y: i32             | *          | x = x ∙ y       |
| Division with two i32                          | IDIV      | 17h    | Arithmetics |                         | x: i32; y: i32             | /          | x = x ÷ y       |
| Remainder (Modulo) with two i32                | IMOD      | 18h    | Arithmetics |                         | x: i32; y: i32             | %          | x = x mod y     |
| Bitwise and with two i32                       | IAND      | 19h    | Arithmetics |                         | x: i32; y: i32             | &          | x = x ∧ y       |
| Bitwise or with two i32                        | IOR       | 1Ah    | Arithmetics |                         | x: i32; y: i32             | |          | x = x ∨ y       |
| Bitwise xor with two i32                       | IXOR      | 1Bh    | Arithmetics |                         | x: i32; y: i32             | ^          | x = x ⊻ y       |
| Bitwise airthmetic left shift with two i32     | ISAL      | 1Ch    | Arithmetics |                         | x: i32; y: i32             | <<         | x = x << y      |
| Bitwise airthmetic right shift with two i32    | ISAR      | 1Dh    | Arithmetics |                         | x: i32; y: i32             | >>         | x = x >> y      |
| Bitwise circular left shift (bitwise rolling)  | IROL      | 1Eh    | Arithmetics |                         | x: i32; y: i32             |            | x = x <<< y     |
| Bitwise circular right shift (bitwise rolling) | IROR      | 1Fh    | Arithmetics |                         | x: i32; y: i32             |            | x = x >>> y     |
| Bitwise complement (negation) with one i32     | ICOM      | 20h    | Arithmetics |                         | x: i32                     | ~          | x = ¬x          |
| Increment by one with one i32                  | IINC      | 21h    | Arithmetics |                         | x: i32                     | ++         | x = x + 1       |
| Decrement by one with one i32                  | IDEC      | 22h    | Arithmetics |                         | x: i32                     | --         | x = x - 1       |
| Addition with two f32                          | FADD      | 23h    | Arithmetics |                         | x: f32; y: f32             | +          | x = x + y       |
| Subtraction with two f32                       | FSUB      | 24h    | Arithmetics |                         | x: f32; y: f32             | -          | x = x - y       |
| Multiplication with two f32                    | FMUL      | 25h    | Arithmetics |                         | x: f32; y: f32             | *          | x = x ∙ y       |
| Division with two f32                          | FDIV      | 26h    | Arithmetics |                         | x: f32; y: f32             | /          | x = x ÷ y       |
| Remainder (Modulo) with two f32                | FMOD      | 27h    | Arithmetics |                         | x: f32; y: f32             | (%)        | x = x mod y     |
| Fused multiply add with two f32                | FFMA      | 28h    | Arithmetics |                         | x: f32; y: f32; z: f32     |            | x = (x ∙ y) + z |
