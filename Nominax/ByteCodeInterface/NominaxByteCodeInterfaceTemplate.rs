// Author: Mario Sieg
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

// Autogenerated, to NOT edit!

use std::{fmt, io, fs};
use std::path::{Path, PathBuf};

#[repr(u64)]
#[derive(Debug, Copy, Clone, Eq, PartialEq)]
#[allow(non_camel_case_types)]
pub enum Instruction {
    $INSTRUCTION$
}

#[repr(u8)]
#[derive(Debug, Copy, Clone, Eq, PartialEq)]
pub enum InstructionCategory {
    $INSTRUCTION_CATEGORY$
}

#[repr(u64)]
#[derive(Debug, Copy, Clone, Eq, PartialEq)]
#[allow(non_camel_case_types)]
pub enum SysCall {
    $SYSCALL$
}

pub type MemoryOffset = u64;

pub type Int = i64;

pub type Float = f64;

pub type JumpAddress = u64;

pub type Intrinsic = u64;

pub type TypeID = u64;

pub type FieldOffset = u64;

/// Represents a single byte code signal.
#[derive(Copy, Clone, PartialEq, Debug)]
pub enum Signal {
    Int(Int),
    Float(Float),
    Instruction(Instruction),
    SysCall(SysCall),
    Intrinsic(Intrinsic),
    MemoryOffset(MemoryOffset),
    JumpAddress(JumpAddress),
    TypeID(TypeID),
    FieldOffset(FieldOffset),
}

impl Signal {
    pub fn name(&self) -> &'static str {
        match self {
            Self::Int(_) => "imm",
            Self::Float(_) => "fmm",
            Self::Instruction(_) => "instr",
            Self::SysCall(_) => "sys",
            Self::Intrinsic(_) => "int",
            Self::MemoryOffset(_) => "mof",
            Self::JumpAddress(_) => "rel",
            Self::TypeID(_) => "tyd",
            Self::FieldOffset(_) => "fof"
        }
    }
}

impl fmt::Display for Signal {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            Self::Int(x) => write!(f, "{}{} {}{:#X}", syntax::PRIMITIVE_TYPE, self.name(), syntax::IMMEDIATE, *x),
            Self::Float(x) => write!(f, "{}{} {}{:#X}", syntax::PRIMITIVE_TYPE, self.name(), syntax::IMMEDIATE, x.to_bits()),
            Self::Instruction(x) => write!(f, "{}", meta_data::MNEMONIC_TABLE[*x as usize]),
            Self::SysCall(x) => write!(f, "{}{} {}{:#X}", syntax::PRIMITIVE_TYPE, self.name(), syntax::IMMEDIATE, *x as u64),
            Self::Intrinsic(x) => write!(f, "{}{} {}{:#X}", syntax::PRIMITIVE_TYPE, self.name(), syntax::IMMEDIATE, *x),
            Self::MemoryOffset(x) => write!(f, "{}{} {}{:#X}", syntax::PRIMITIVE_TYPE, self.name(), syntax::IMMEDIATE, *x),
            Self::JumpAddress(x) => write!(f, "{}{} {}{:#X}", syntax::PRIMITIVE_TYPE, self.name(), syntax::IMMEDIATE, *x),
            Self::TypeID(x) => write!(f, "{}{} {}{:#X}", syntax::PRIMITIVE_TYPE, self.name(), syntax::IMMEDIATE, *x),
            Self::FieldOffset(x) => write!(f, "{}{} {}{:#X}", syntax::PRIMITIVE_TYPE, self.name(), syntax::IMMEDIATE, *x),
        }
    }
}

/// Represents a stream of byte code signals.
#[derive(Clone, Debug, PartialEq)]
pub struct Stream {
    data: Vec<Signal>,
    routine_counter: u64,
    label_counter: u64
}

impl Stream {
    pub const TXT_EXTENSION: &'static str = "nxs";
    pub const BIN_EXTENSION: &'static str = "nxb";

    #[inline]
    pub fn new() -> Self {
        Self::default()
    }

    #[inline]
    pub fn with_capacity(capacity: usize) -> Self {
        Self {
            data: Vec::with_capacity(capacity),
            routine_counter: 0,
            label_counter: 0
        }
    }

    #[inline]
    pub fn len(&self) -> usize {
        self.data.len()
    }

    #[inline]
    pub fn capacity(&self) -> usize {
        self.data.capacity()
    }

    #[inline]
    pub fn is_empty(&self) -> bool {
        self.data.is_empty()
    }

    #[inline]
    pub fn push(&mut self, sig: Signal) {
        self.data.push(sig)
    }

    #[inline]
    pub fn push_instr(&mut self, instr: Instruction) {
        self.push(Signal::Instruction(instr))
    }

    #[inline]
    pub fn reserve(&mut self, additional: usize) {
        self.data.reserve(additional);
    }

    pub fn write_to_source_file(&self, file: &Path) -> Result<(), io::Error> {
        let mut file = PathBuf::from(file);
        file.set_extension(Self::TXT_EXTENSION);
        let output = self.to_string();
        fs::write(file, output)
    }
}

impl Default for Stream {
    fn default() -> Self {
        Self {
            data: Vec::new(),
            routine_counter: 0,
            label_counter: 0
        }
    }
}

impl fmt::Display for Stream {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        for signal in &self.data {
            if let Signal::Instruction(_) = signal {
                writeln!(f)?;
            }
            write!(f, "{} ", signal)?
        }
        Ok(())
    }
}

#[repr(u8)]
#[derive(Debug, Copy, Clone, Eq, PartialEq)]
#[allow(non_camel_case_types)]
pub enum SubroutineAttributes {
    None = 0,

    /// <summary>
    /// Should inline.
    /// </summary>
    ForceInline,

    /// <summary>
    /// Do not inline.
    /// </summary>
    NoInline,

    /// <summary>
    /// Pure subroutine.
    /// </summary>
    Pure,

    /// <summary>
    /// Recursive subroutine.
    /// </summary>
    Recursive,

    /// <summary>
    /// Hot subroutine.
    /// </summary>
    Hot,

    /// <summary>
    /// Cold subroutine.
    /// </summary>
    Cold,

    /// <summary>
    /// Should JIT.
    /// </summary>
    ForceJIT,

    /// <summary>
    /// Should not JIT.
    /// </summary>
    NoJIT,

    /// <summary>
    /// Subroutine does not return.
    /// </summary>
    NoReturn,

    /// <summary>
    /// Subroutine can be offloaded to the GPU.
    /// </summary>
    Compute,

    /// <summary>
    /// Subroutine has parameters.
    /// </summary>
    Sentinel,

    /// <summary>
    /// Subroutine is probably not used.
    /// </summary>
    Unused,

    /// <summary>
    /// Subroutine is obfuscated.
    /// </summary>
    Obfuscate,

    /// <summary>
    /// No attribute, but the total count of total attributes.
    /// </summary>
    /// <param name=""></param>
    Count_
}

impl SubroutineAttributes {
    pub const NAMES: [&'static str; Self::Count_ as usize] = [
        "NONE",
        "FORCE_INLINE",
        "NO_INLINE",
        "PURE",
        "RECURSIVE",
        "HOT",
        "COLD",
        "FORCE_JIT",
        "NO_JIT",
        "NO_RET",
        "COMPUTE",
        "SENTINEL",
        "UNUSED",
        "OBFUSCATE"
    ];

    #[inline]
    pub fn name(&self) -> &str {
        Self::NAMES[*self as usize]
    }
}

pub mod syntax {
    pub const COM_DIRECTIVE: char = '.';
    pub const IMMEDIATE: char = '$';
    pub const PRIMITIVE_TYPE: char = '%';
}

pub mod meta_data {
    use super::*;

    pub const MNEMONIC_TABLE: [&str; Instruction::Count_ as usize] = [
        $MNEMONIC_TABLE$
    ];

    pub const CATEGORY_TABLE: [InstructionCategory; Instruction::Count_ as usize] = [
        $CATEGORY_TABLE$
    ];

    pub const PUSH_RECORD_TABLE: [u8; Instruction::Count_ as usize] = [
        $PUSH_RECORD_TABLE$
    ];

    pub const POP_RECORD_TABLE: [u8; Instruction::Count_ as usize] = [
        $POP_RECORD_TABLE$
    ];

    pub const IMMEDIATE_TABLE: [u8; Instruction::Count_ as usize] = [
        $IMMEDIATE_TABLE$
    ];

    pub const DESCRIPTOR_TABLE: [&str; Instruction::Count_ as usize] = [
        $DESCRIPTOR_TABLE$
    ];
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn empty() {
        let stream = Stream::new();
        assert_eq!(stream.0, Vec::new());
        assert!(stream.is_empty());
        assert_eq!(stream.len(), 0);
        assert_eq!(stream.capacity(), 0);
    }

    #[test]
    fn capacity() {
        let stream = Stream::with_capacity(10);
        assert_eq!(stream.0.capacity(), 10);
        assert_eq!(stream.capacity(), 10);
    }

    #[test]
    fn push_back() {
        let mut stream = Stream::new();
        stream.push(Signal::Int(3));
        assert_eq!(stream.len(), 1);
        assert!(matches!(&stream.0[0], Signal::Int(3)));
    }

    #[test]
    fn push_instr() {
        let mut stream = Stream::new();
        stream.push_instr(Instruction::CVTF2I);
        assert_eq!(stream.len(), 1);
        assert!(matches!(
            &stream.0[0],
            Signal::Instruction(Instruction::CVTF2I)
        ));
    }
}
