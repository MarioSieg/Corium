// File: lib.rs
// Author: Mario
// Created: 07.31.2021 2:17 PM
// Project: NominaxRuntime (noxbci - Nominax Byte Code Interface)
//
//                                  Apache License
//                            Version 2.0, January 2004
//                         http://www.apache.org/licenses/
//
//    TERMS AND CONDITIONS FOR USE, REPRODUCTION, AND DISTRIBUTION
//
//    1. Definitions.
//
//       "License" shall mean the terms and conditions for use, reproduction,
//       and distribution as defined by Sections 1 through 9 of this document.
//
//       "Licensor" shall mean the copyright owner or entity authorized by
//       the copyright owner that is granting the License.
//
//       "Legal Entity" shall mean the union of the acting entity and all
//       other entities that control, are controlled by, or are under common
//       control with that entity. For the purposes of this definition,
//       "control" means (i) the power, direct or indirect, to cause the
//       direction or management of such entity, whether by contract or
//       otherwise, or (ii) ownership of fifty percent (50%) or more of the
//       outstanding shares, or (iii) beneficial ownership of such entity.
//
//       "You" (or "Your") shall mean an individual or Legal Entity
//       exercising permissions granted by this License.
//
//       "Source" form shall mean the preferred form for making modifications,
//       including but not limited to software source code, documentation
//       source, and configuration files.
//
//       "Object" form shall mean any form resulting from mechanical
//       transformation or translation of a Source form, including but
//       not limited to compiled object code, generated documentation,
//       and conversions to other media types.
//
//       "Work" shall mean the work of authorship, whether in Source or
//       Object form, made available under the License, as indicated by a
//       copyright notice that is included in or attached to the work
//       (an example is provided in the Appendix below).
//
//       "Derivative Works" shall mean any work, whether in Source or Object
//       form, that is based on (or derived from) the Work and for which the
//       editorial revisions, annotations, elaborations, or other modifications
//       represent, as a whole, an original work of authorship. For the purposes
//       of this License, Derivative Works shall not include works that remain
//       separable from, or merely link (or bind by name) to the interfaces of,
//       the Work and Derivative Works thereof.
//
//       "Contribution" shall mean any work of authorship, including
//       the original version of the Work and any modifications or additions
//       to that Work or Derivative Works thereof, that is intentionally
//       submitted to Licensor for inclusion in the Work by the copyright owner
//       or by an individual or Legal Entity authorized to submit on behalf of
//       the copyright owner. For the purposes of this definition, "submitted"
//       means any form of electronic, verbal, or written communication sent
//       to the Licensor or its representatives, including but not limited to
//       communication on electronic mailing lists, source code control systems,
//       and issue tracking systems that are managed by, or on behalf of, the
//       Licensor for the purpose of discussing and improving the Work, but
//       excluding communication that is conspicuously marked or otherwise
//       designated in writing by the copyright owner as "Not a Contribution."
//
//       "Contributor" shall mean Licensor and any individual or Legal Entity
//       on behalf of whom a Contribution has been received by Licensor and
//       subsequently incorporated within the Work.
//
//    2. Grant of Copyright License. Subject to the terms and conditions of
//       this License, each Contributor hereby grants to You a perpetual,
//       worldwide, non-exclusive, no-charge, royalty-free, irrevocable
//       copyright license to reproduce, prepare Derivative Works of,
//       publicly display, publicly perform, sublicense, and distribute the
//       Work and such Derivative Works in Source or Object form.
//
//    3. Grant of Patent License. Subject to the terms and conditions of
//       this License, each Contributor hereby grants to You a perpetual,
//       worldwide, non-exclusive, no-charge, royalty-free, irrevocable
//       (except as stated in this section) patent license to make, have made,
//       use, offer to sell, sell, import, and otherwise transfer the Work,
//       where such license applies only to those patent claims licensable
//       by such Contributor that are necessarily infringed by their
//       Contribution(s) alone or by combination of their Contribution(s)
//       with the Work to which such Contribution(s) was submitted. If You
//       institute patent litigation against any entity (including a
//       cross-claim or counterclaim in a lawsuit) alleging that the Work
//       or a Contribution incorporated within the Work constitutes direct
//       or contributory patent infringement, then any patent licenses
//       granted to You under this License for that Work shall terminate
//       as of the date such litigation is filed.
//
//    4. Redistribution. You may reproduce and distribute copies of the
//       Work or Derivative Works thereof in any medium, with or without
//       modifications, and in Source or Object form, provided that You
//       meet the following conditions:
//
//       (a) You must give any other recipients of the Work or
//           Derivative Works a copy of this License; and
//
//       (b) You must cause any modified files to carry prominent notices
//           stating that You changed the files; and
//
//       (c) You must retain, in the Source form of any Derivative Works
//           that You distribute, all copyright, patent, trademark, and
//           attribution notices from the Source form of the Work,
//           excluding those notices that do not pertain to any part of
//           the Derivative Works; and
//
//       (d) If the Work includes a "NOTICE" text file as part of its
//           distribution, then any Derivative Works that You distribute must
//           include a readable copy of the attribution notices contained
//           within such NOTICE file, excluding those notices that do not
//           pertain to any part of the Derivative Works, in at least one
//           of the following places: within a NOTICE text file distributed
//           as part of the Derivative Works; within the Source form or
//           documentation, if provided along with the Derivative Works; or,
//           within a display generated by the Derivative Works, if and
//           wherever such third-party notices normally appear. The contents
//           of the NOTICE file are for informational purposes only and
//           do not modify the License. You may add Your own attribution
//           notices within Derivative Works that You distribute, alongside
//           or as an addendum to the NOTICE text from the Work, provided
//           that such additional attribution notices cannot be construed
//           as modifying the License.
//
//       You may add Your own copyright statement to Your modifications and
//       may provide additional or different license terms and conditions
//       for use, reproduction, or distribution of Your modifications, or
//       for any such Derivative Works as a whole, provided Your use,
//       reproduction, and distribution of the Work otherwise complies with
//       the conditions stated in this License.
//
//    5. Submission of Contributions. Unless You explicitly state otherwise,
//       any Contribution intentionally submitted for inclusion in the Work
//       by You to the Licensor shall be under the terms and conditions of
//       this License, without any additional terms or conditions.
//       Notwithstanding the above, nothing herein shall supersede or modify
//       the terms of any separate license agreement you may have executed
//       with Licensor regarding such Contributions.
//
//    6. Trademarks. This License does not grant permission to use the trade
//       names, trademarks, service marks, or product names of the Licensor,
//       except as required for reasonable and customary use in describing the
//       origin of the Work and reproducing the content of the NOTICE file.
//
//    7. Disclaimer of Warranty. Unless required by applicable law or
//       agreed to in writing, Licensor provides the Work (and each
//       Contributor provides its Contributions) on an "AS IS" BASIS,
//       WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
//       implied, including, without limitation, any warranties or conditions
//       of TITLE, NON-INFRINGEMENT, MERCHANTABILITY, or FITNESS FOR A
//       PARTICULAR PURPOSE. You are solely responsible for determining the
//       appropriateness of using or redistributing the Work and assume any
//       risks associated with Your exercise of permissions under this License.
//
//    8. Limitation of Liability. In no event and under no legal theory,
//       whether in tort (including negligence), contract, or otherwise,
//       unless required by applicable law (such as deliberate and grossly
//       negligent acts) or agreed to in writing, shall any Contributor be
//       liable to You for damages, including any direct, indirect, special,
//       incidental, or consequential damages of any character arising as a
//       result of this License or out of the use or inability to use the
//       Work (including but not limited to damages for loss of goodwill,
//       work stoppage, computer failure or malfunction, or any and all
//       other commercial damages or losses), even if such Contributor
//       has been advised of the possibility of such damages.
//
//    9. Accepting Warranty or Additional Liability. While redistributing
//       the Work or Derivative Works thereof, You may choose to offer,
//       and charge a fee for, acceptance of support, warranty, indemnity,
//       or other liability obligations and/or rights consistent with this
//       License. However, in accepting such obligations, You may act only
//       on Your own behalf and on Your sole responsibility, not on behalf
//       of any other Contributor, and only if You agree to indemnify,
//       defend, and hold each Contributor harmless for any liability
//       incurred by, or claims asserted against, such Contributor by reason
//       of your accepting any such warranty or additional liability.
//
//    END OF TERMS AND CONDITIONS
//
//    APPENDIX: How to apply the Apache License to your work.
//
//       To apply the Apache License to your work, attach the following
//       boilerplate notice, with the fields enclosed by brackets "[]"
//       replaced with your own identifying information. (Don't include
//       the brackets!)  The text should be enclosed in the appropriate
//       comment syntax for the file format. We also recommend that a
//       file or class name and description of purpose be included on the
//       same "printed page" as the copyright notice for easier
//       identification within third-party archives.
//
//    Copyright 2021 Mario Sieg "pinsrq" <mt3000@gmx.de>
//
//    Licensed under the Apache License, Version 2.0 (the "License");
//    you may not use this file except in compliance with the License.
//    You may obtain a copy of the License at
//
//        http://www.apache.org/licenses/LICENSE-2.0
//
//    Unless required by applicable law or agreed to in writing, software
//    distributed under the License is distributed on an "AS IS" BASIS,
//    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//    See the License for the specific language governing permissions and
//    limitations under the License.

use std::fmt;

#[repr(u64)]
#[derive(Copy, Clone, Eq, PartialEq)]
pub enum Instruction {
    Int = 0x00,
    Intrin = 0x01,
    CIntrin = 0x02,
    Call = 0x03,
    Ret = 0x04,
    Mov = 0x05,
    Sto = 0x06,
    Push = 0x07,
    Pop = 0x08,
    Pop2 = 0x09,
    Dupl = 0x0A,
    Dupl2 = 0x0B,
    Swap = 0x0C,
    NOp = 0x0D,
    Jmp = 0x0E,
    JmpRel = 0x0F,
    Jz = 0x10,
    Jnz = 0x11,
    JoCmpi = 0x12,
    JoCmpf = 0x13,
    JnoCmpi = 0x14,
    JnoCmpf = 0x15,
    JeCmpi = 0x16,
    JeCmpf = 0x17,
    JneCmpi = 0x18,
    JneCmpf = 0x19,
    JaCmpi = 0x1A,
    JaCmpf = 0x1B,
    JlCmpi = 0x1C,
    JlCmpf = 0x1D,
    JaeCmpi = 0x1E,
    JaeCmpf = 0x1F,
    JleCmpi = 0x20,
    JleCmpf = 0x21,
    PushZ = 0x22,
    IPushO = 0x23,
    FPushO = 0x24,
    IInc = 0x25,
    IDec = 0x26,
    IAdd = 0x27,
    ISub = 0x28,
    IMul = 0x29,
    IDiv = 0x2A,
    IMod = 0x2B,
    IAnd = 0x2C,
    IOr = 0x2D,
    IXor = 0x2E,
    ICom = 0x2F,
    ISal = 0x30,
    ISar = 0x31,
    IRol = 0x32,
    IRor = 0x33,
    INeg = 0x34,
    FAdd = 0x35,
    FSub = 0x36,
    FMul = 0x37,
    FDiv = 0x38,
    FMod = 0x39,
    FNeg = 0x3A,
    FInc = 0x3B,
    FDec = 0x3C,
    VecPush = 0x3D,
    VecPop = 0x3E,
    VecAdd = 0x3F,
    VecSub = 0x40,
    VecMul = 0x41,
    VecDiv = 0x42,
    MatPush = 0x43,
    MatPop = 0x44,
    MatAdd = 0x45,
    MatSub = 0x46,
    MatMul = 0x47,
    MatDiv = 0x48,

    /* count of total instructions */
    Count_,
}

#[repr(u8)]
#[derive(Debug, Copy, Clone, Eq, PartialEq)]
pub enum InstructionCategory {
    Control = 0x00,
    Memory = 0x01,
    Branching = 0x02,
    Arithmetic = 0x03,
    BitWise = 0x04,
    VectorSimd = 0x05,
}

impl Instruction {
    pub const MNEMONIC_TABLE: [&'static str; Instruction::Count_ as usize] = [
        "int", "intrin", "cintrin", "call", "ret", "mov", "sto", "push", "pop", "pop2", "dupl",
        "dupl2", "swap", "nop", "jmp", "jmprel", "jz", "jnz", "jo_cmpi", "jo_cmpf", "jno_cmpi",
        "jno_cmpf", "je_cmpi", "je_cmpf", "jne_cmpi", "jne_cmpf", "ja_cmpi", "ja_cmpf", "jl_cmpi",
        "jl_cmpf", "jae_cmpi", "jae_cmpf", "jle_cmpi", "jle_cmpf", "pushz", "ipusho", "fpusho",
        "iinc", "idec", "iadd", "isub", "imul", "idiv", "imod", "iand", "ior", "ixor", "icom",
        "isal", "isar", "irol", "iror", "ineg", "fadd", "fsub", "fmul", "fdiv", "fmod", "fneg",
        "finc", "fdec", "vecpush", "vecpop", "vecadd", "vecsub", "vecmul", "vecdiv", "matpush",
        "matpop", "matadd", "matsub", "matmul", "matdiv",
    ];

    pub const CATEGORY_TABLE: [InstructionCategory; Instruction::Count_ as usize] = [
        InstructionCategory::Control,
        InstructionCategory::Control,
        InstructionCategory::Control,
        InstructionCategory::Control,
        InstructionCategory::Control,
        InstructionCategory::Memory,
        InstructionCategory::Memory,
        InstructionCategory::Memory,
        InstructionCategory::Memory,
        InstructionCategory::Memory,
        InstructionCategory::Memory,
        InstructionCategory::Memory,
        InstructionCategory::Memory,
        InstructionCategory::Memory,
        InstructionCategory::Branching,
        InstructionCategory::Branching,
        InstructionCategory::Branching,
        InstructionCategory::Branching,
        InstructionCategory::Branching,
        InstructionCategory::Branching,
        InstructionCategory::Branching,
        InstructionCategory::Branching,
        InstructionCategory::Branching,
        InstructionCategory::Branching,
        InstructionCategory::Branching,
        InstructionCategory::Branching,
        InstructionCategory::Branching,
        InstructionCategory::Branching,
        InstructionCategory::Branching,
        InstructionCategory::Branching,
        InstructionCategory::Branching,
        InstructionCategory::Branching,
        InstructionCategory::Branching,
        InstructionCategory::Branching,
        InstructionCategory::Arithmetic,
        InstructionCategory::Arithmetic,
        InstructionCategory::Arithmetic,
        InstructionCategory::Arithmetic,
        InstructionCategory::Arithmetic,
        InstructionCategory::Arithmetic,
        InstructionCategory::Arithmetic,
        InstructionCategory::Arithmetic,
        InstructionCategory::Arithmetic,
        InstructionCategory::Arithmetic,
        InstructionCategory::BitWise,
        InstructionCategory::BitWise,
        InstructionCategory::BitWise,
        InstructionCategory::BitWise,
        InstructionCategory::BitWise,
        InstructionCategory::BitWise,
        InstructionCategory::BitWise,
        InstructionCategory::BitWise,
        InstructionCategory::BitWise,
        InstructionCategory::Arithmetic,
        InstructionCategory::Arithmetic,
        InstructionCategory::Arithmetic,
        InstructionCategory::Arithmetic,
        InstructionCategory::Arithmetic,
        InstructionCategory::Arithmetic,
        InstructionCategory::Arithmetic,
        InstructionCategory::Arithmetic,
        InstructionCategory::Memory,
        InstructionCategory::Memory,
        InstructionCategory::VectorSimd,
        InstructionCategory::VectorSimd,
        InstructionCategory::VectorSimd,
        InstructionCategory::VectorSimd,
        InstructionCategory::Memory,
        InstructionCategory::Memory,
        InstructionCategory::VectorSimd,
        InstructionCategory::VectorSimd,
        InstructionCategory::VectorSimd,
        InstructionCategory::VectorSimd,
    ];

    pub const PUSH_RECORD_TABLE: [u8; Instruction::Count_ as usize] = [
        0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 4, 0, 4, 4, 4, 4, 16, 0, 16, 16, 16, 16,
    ];

    pub const POP_RECORD_TABLE: [u8; Instruction::Count_ as usize] = [
        0, 0, 0, 0, 1, 0, 0, 0, 1, 2, 0, 0, 2, 0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 0, 0, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1, 1,
        1, 0, 4, 8, 8, 8, 8, 0, 16, 32, 32, 32, 32,
    ];

    pub const IMMEDIATE_ARG_TABLE: [u8; Instruction::Count_ as usize] = [
        1, 1, 1, 1, 0, 2, 2, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 4, 0, 0, 0, 0, 0, 16, 0, 0, 0, 0, 0,
    ];

    pub const DESCRIPTOR_TABLE: [&'static str; Instruction::Count_ as usize] = [
        "interrupt reactor execution",
        "call intrinsic system routine",
        "call custom intrinsic routine",
        "call procedure",
        "return from procedure",
        "copy stack slot to stack record",
        "copy immediate to stack record",
        "push one stack record onto stack",
        "pop one stack record from stack",
        "pop two records from stack",
        "duplicate stack top",
        "duplicate stack top two times",
        "swap the stack top slot with the lower slot",
        "no operation",
        "absolute direct unconditional jump",
        "relative indirect jump unconditional jump",
        "jump if zero",
        "jump if not zero",
        "jump if one - compare as integer",
        "jump if one - compare as F32",
        "jump if not one - compare as integer",
        "jump if not one - compare as  integer",
        "jump if equal as integer",
        "jump if equal - compare as F32ing point",
        "jump if not equal - compare  as integer",
        "jump if not equal - compare  as F32ing point",
        "jump if above - compare  as integer",
        "jump if above - compare  as F32ing point",
        "jump if less - compare as F32ing point",
        "jump if less - compare as F32ing point",
        "jump if above or equal - compare as integer",
        "jump if above or equal - compare as F32ing point",
        "jump if less or equal - compare as integer",
        "jump if less or equal - compare as F32ing point",
        "push zero as integer",
        "push one as  integer",
        "push one as F32ing point",
        "integer increment",
        "integer decrement",
        "integer addition",
        "integer subtraction",
        "integer multiplication",
        "integer division",
        "integer remainder",
        "integer bitwise and",
        "integer bitwise or",
        "integer bitwise xor",
        "integer bitwise complement",
        "integer bitwise arithmetic left shift",
        "integer bitwise arithmetic right shift",
        "integer bitwise rotation left",
        "integer bitwise right rotation",
        "integer negation",
        "floating point addition",
        "floating point subtraction",
        "floating point multiplication",
        "floating point division",
        "floating point remainder",
        "floating point negation",
        "floating point increment",
        "floating point decrement",
        "push vec4 quad vector",
        "pop vec4 quad vector",
        "simd floating point vec4 quad vector addition",
        "simd floating point vec4 quad vector subtraction",
        "simd floating point vec4 quad vector multiplication",
        "simd floating point vec4 quad vector division",
        "push mat4x4 matrix",
        "pop mat4x4 matrix",
        "simd floating point mat4x4 matrix addition",
        "simd floating point mat4x4 matrix subtraction",
        "simd floating point mat4x4 matrix multiplication",
        "simd floating point mat4x4 matrix division",
    ];

    /// Returns the short string mnemonic.
    #[inline]
    pub fn mnemonic(self) -> &'static str {
        Self::MNEMONIC_TABLE[self as usize]
    }

    /// Returns the category.
    #[inline]
    pub fn category(self) -> InstructionCategory {
        Self::CATEGORY_TABLE[self as usize]
    }

    /// Returns the amount of stack pushes each instruction will perform.
    #[inline]
    pub fn record_push_amount(self) -> u8 {
        Self::PUSH_RECORD_TABLE[self as usize]
    }

    /// Returns the amount of stack pops each instruction will perform.
    #[inline]
    pub fn record_pop_amount(self) -> u8 {
        Self::POP_RECORD_TABLE[self as usize]
    }

    /// Return the amount of required immediate arguments for each instruction.
    #[inline]
    pub fn immediate_arg_count(self) -> u8 {
        Self::IMMEDIATE_ARG_TABLE[self as usize]
    }

    /// Returns a short descriptions.
    #[inline]
    pub fn description(self) -> &'static str {
        Self::DESCRIPTOR_TABLE[self as usize]
    }
}

impl fmt::Display for Instruction {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "{}", Self::MNEMONIC_TABLE[*self as usize])
    }
}

impl fmt::Debug for Instruction {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(
            f,
            "{} ({:#02X})",
            Self::MNEMONIC_TABLE[*self as usize],
            *self as u64
        )
    }
}

/// Subroutine invocation id for system intrinsic routines.
#[repr(u64)]
#[derive(Debug, Copy, Clone, Eq, PartialEq)]
pub enum SystemIntrinsicInvocationID {
    Cos = 0x00,
    Sin = 0x01,
    Tan = 0x02,
    ACos = 0x03,
    ASin = 0x04,
    ATan = 0x05,
    ATan2 = 0x06,
    CosH = 0x07,
    SinH = 0x08,
    TanH = 0x09,
    ACosH = 0x0A,
    ASinH = 0x0B,
    ATanH = 0x0C,
    Exp = 0x0D,
    Log = 0x0E,
    Log10 = 0x0F,
    Exp2 = 0x10,
    ILogB = 0x11,
    Log2 = 0x12,
    Pow = 0x13,
    Sqrt = 0x14,
    Cbrt = 0x15,
    Hypot = 0x16,
    Ceil = 0x17,
    Floor = 0x18,
    Round = 0x19,
    RInt = 0x1A,
    IMax = 0x1B,
    IMin = 0x1C,
    FMax = 0x1D,
    FMin = 0x1E,
    Dim = 0x1F,
    IAbs = 0x20,
    FAbs = 0x21,
    IoPortWriteCluster = 0x22,
    IoPortReadCluster = 0x23,
    IoPortFlush = 0x24,

    /* !no intrinsic routine - count of total intrinsic routines! */
    Count_,
}

/// Represents a jump address which
/// is essentially an index to a instruction.
/// For dynamic signals only.
pub type JumpAddress = u64;

/// Subroutine invocation id for custom intrinsic routine.
pub type UserIntrinsicInvocationID = u64;

/// 64-bit byte code signal data contains either an instruction or an immediate value.
#[derive(Debug, Copy, Clone, PartialEq)]
pub enum Signal {
    U64(u64),
    I64(i64),
    F64(f64),
    Instruction(Instruction),
    SystemIntrinsicInvocationID(SystemIntrinsicInvocationID),
    UserIntrinsicInvocationID(UserIntrinsicInvocationID),
    JumpAddress(JumpAddress),
}

pub struct Stream {
    pub peephole_opt: bool,
    pub storage: Vec<Signal>,
}

impl Stream {
    pub fn new() -> Self {
        Self {
            peephole_opt: true,
            storage: Vec::new(),
        }
    }

    pub fn with_capacity(cap: usize) -> Self {
        Self {
            peephole_opt: true,
            storage: Vec::with_capacity(cap),
        }
    }

    #[inline]
    pub fn push(&mut self, signal: Signal) -> &mut Self {
        self.storage.push(signal);
        self
    }
}

impl std::default::Default for Stream {
    fn default() -> Self {
        Self::new()
    }
}

impl fmt::Display for Stream {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        for sig in &self.storage {
            writeln!(f, "{:?}", *sig)?
        }
        fmt::Result::Ok(())
    }
}