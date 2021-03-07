use bitflags::bitflags;

bitflags! {
    /// Contains flags for all supported extensions.
    #[rustfmt::skip]
    pub struct CpuExtensionFlags: u64 {
        const NONE              = 0;

        /// Advanced encryption standart.
        const AES               = 1 << 0;

        /// Carry less multiplication.
        const PCLMULQDQ         = 1 << 1;

        /// Cryptographically secure pseudorandom number generator. NIST Compliance: SP 800-90A
        const RDRAND            = 1 << 2;

        /// Non-deterministic random bit generator NIST Compliance: SP 800-90B & C (drafts)
        const RDSEED            = 1 << 3;

        /// Time stamp counter.
        const TSC               = 1 << 4;

        /// (64-Bit) Multimedia extensions.
        const MMX               = 1 << 5;

        /// (128-Bit) Streaming SIMD extensions.
        const SSE               = 1 << 6;

        /// (128-Bit) Streaming SIMD extensions 2.
        const SSE2              = 1 << 7;

        /// (128-Bit) Streaming SIMD extensions 3.
        const SSE3              = 1 << 8;

        /// (128-Bit) Supplemental streaming SIMD extensions 3.
        const SSSE3             = 1 << 9;

        /// (128-Bit) Streaming SIMD extensions 4.1.
        const SSE4_1            = 1 << 10;

        /// (128-Bit) Streaming SIMD extensions 4.2.
        const SSE4_2            = 1 << 11;

        /// (128-Bit) Streaming SIMD extensions 4.A.
        const SSE4A             = 1 << 12;

        /// Secure hash algorithm.
        const SHA               = 1 << 13;

        /// (256-Bit) Advanced vector extensions.
        const AVX               = 1 << 15;

        /// (256-Bit) Advanced vector extensions 2.
        const AVX2              = 1 << 16;

        /// (512-Bit) Advanced vector extensions foundation.
        const AVX512F           = 1 << 17;

        /// (512-Bit) Advanced vector extensions conflict detection.
        const AVX512CD          = 1 << 18;

        /// (512-Bit) Advanced vector extensions exponential, reciprocal.
        const AVX512ER          = 1 << 19;

        /// (512-Bit) Advanced vector extensions prefetch.
        const AVX512PF          = 1 << 20;

        /// (512-Bit) Advanced vector extensions byte and word.
        const AVX512BW          = 1 << 21;

        /// (512-Bit) Advanced vector extensions doubleword and quadword.
        const AVX512DQ          = 1 << 22;

        /// (512-Bit) Advanced vector extensions vector length.
        const AVX512VL          = 1 << 21;

        /// (512-Bit) Advanced vector extensions integer fused multiply add.
        const AVX512IFMA        = 1 << 22;

        /// (512-Bit) Advanced vector extensions vector byte manipulation.
        const AVX512VBMI        = 1 << 23;

        /// (512-Bit) Advanced vector extensions vector population count.
        const AVX512VPOPCNTDQ   = 1 << 24;

        /// (512-Bit) Advanced vector extensions vector byte manipulation 2.
        const AVX512VBMI2       = 1 << 25;

        /// (512-Bit) Advanced vector extensions EVEX encoded GFNI version.
        const AVX512GFNI        = 1 << 26;

        /// (512-Bit) Advanced vector extensions EVEX encoded AES version.
        const AVX512VAES        = 1 << 27;

        /// (512-Bit) Advanced vector extensions EVEX encoded PCMULQDQ version.
        const AVX512VPCLMULQDQ  = 1 << 28;

        /// (512-Bit) Advanced vector extensions vector neuronal network instructions.
        const AVX512VNNI        = 1 << 29;

        /// (512-Bit) Advanced vector extensions bit algorithms.
        const AVX512BITALG      = 1 << 30;

        /// (512-Bit) Advanced vector extensions foundation.
        const AVX512BF16        = 1 << 31;

        /// (512-Bit) Advanced vector extensions vector pair intersection to a pair of mask registers.
        const AVX512VP2INTER    = 1 << 32;

        /// Half precision conversions.
        const F16C              = 1 << 33;

        /// Fused multiply add.
        const FMA               = 1 << 34;

        /// Bit manipulation instructions 1.
        const BMI1              = 1 << 35;

        /// Bit manipulation instructions 2.
        const BMI2              = 1 << 36;

        /// Advanced bit manipulation.
        const ABM               = 1 << 37;

        /// Count number of leading zero bits.
        const LZCNT             = 1 << 38;

        /// Trailing bit manipulation.
        const TBM               = 1 << 39;

        /// Count number of one bits.
        const POPCNT            = 1 << 40;

        /// Save processor extended states.
        const FXSR              = 1 << 41;

        /// Save processor extended states.
        const XSAVE             = 1 << 42;

        /// Save processor extended states.
        const XSAVEOPT          = 1 << 43;

        /// Save processor extended states.
        const XSAVES            = 1 << 44;

        /// Save processor extended states.
        const XSAVEC            = 1 << 45;

        /// Compare and exchange bytes.
        const CMPXCHG16B         = 1 << 46;

        /// Add with carry.
        const ADX               = 1 << 47;

        /// Restricted transactional memory.
        const RTM               = 1 << 48;
    }
}

impl CpuExtensionFlags {
    pub fn query_all() -> Self {
        let mut flags = Self::NONE;

        #[cfg(any(target_arch = "x86", target_arch = "x86_64"))]
        {
            if is_x86_feature_detected!("aes") {
                flags |= Self::AES;
            }
            if is_x86_feature_detected!("pclmulqdq") {
                flags |= Self::PCLMULQDQ;
            }
            if is_x86_feature_detected!("rdrand") {
                flags |= Self::RDRAND;
            }
            if is_x86_feature_detected!("rdseed") {
                flags |= Self::RDSEED;
            }
            if is_x86_feature_detected!("tsc") {
                flags |= Self::TSC;
            }
            if is_x86_feature_detected!("mmx") {
                flags |= Self::MMX;
            }
            if is_x86_feature_detected!("sse4.1") {
                flags |= Self::SSE;
            }
            if is_x86_feature_detected!("sse4.1") {
                flags |= Self::SSE2;
            }
            if is_x86_feature_detected!("sse3") {
                flags |= Self::SSE3;
            }
            if is_x86_feature_detected!("ssse3") {
                flags |= Self::SSSE3;
            }
            if is_x86_feature_detected!("sse4.1") {
                flags |= Self::SSE4_1;
            }
            if is_x86_feature_detected!("sse4.2") {
                flags |= Self::SSE4_2;
            }
            if is_x86_feature_detected!("sse4a") {
                flags |= Self::SSE4A;
            }
            if is_x86_feature_detected!("sha") {
                flags |= Self::SHA;
            }
            if is_x86_feature_detected!("avx") {
                flags |= Self::AVX;
            }
            if is_x86_feature_detected!("avx2") {
                flags |= Self::AVX2;
            }
            if is_x86_feature_detected!("avx512f") {
                flags |= Self::AVX512F;
            }
            if is_x86_feature_detected!("avx512cd") {
                flags |= Self::AVX512CD;
            }
            if is_x86_feature_detected!("avx512er") {
                flags |= Self::AVX512ER;
            }
            if is_x86_feature_detected!("avx512pf") {
                flags |= Self::AVX512PF;
            }
            if is_x86_feature_detected!("avx512bw") {
                flags |= Self::AVX512BW;
            }
            if is_x86_feature_detected!("avx512dq") {
                flags |= Self::AVX512DQ;
            }
            if is_x86_feature_detected!("avx512vl") {
                flags |= Self::AVX512VL;
            }
            if is_x86_feature_detected!("avx512ifma") {
                flags |= Self::AVX512IFMA;
            }
            if is_x86_feature_detected!("avx512vbmi") {
                flags |= Self::AVX512VBMI;
            }
            if is_x86_feature_detected!("avx512vpopcntdq") {
                flags |= Self::AVX512VPOPCNTDQ;
            }
            if is_x86_feature_detected!("avx512vbmi2") {
                flags |= Self::AVX512VBMI2;
            }
            if is_x86_feature_detected!("avx512gfni") {
                flags |= Self::AVX512GFNI;
            }
            if is_x86_feature_detected!("avx512vaes") {
                flags |= Self::AVX512VAES;
            }
            if is_x86_feature_detected!("avx512vpclmulqdq") {
                flags |= Self::AVX512VPCLMULQDQ;
            }
            if is_x86_feature_detected!("avx512vnni") {
                flags |= Self::AVX512VNNI;
            }
            if is_x86_feature_detected!("avx512bitalg") {
                flags |= Self::AVX512BITALG;
            }
            if is_x86_feature_detected!("avx512bf16") {
                flags |= Self::AVX512BF16;
            }
            if is_x86_feature_detected!("avx512vp2intersect") {
                flags |= Self::AVX512VP2INTER;
            }
            if is_x86_feature_detected!("f16c") {
                flags |= Self::F16C;
            }
            if is_x86_feature_detected!("fma") {
                flags |= Self::FMA;
            }
            if is_x86_feature_detected!("bmi1") {
                flags |= Self::BMI1;
            }
            if is_x86_feature_detected!("bmi2") {
                flags |= Self::BMI2;
            }
            if is_x86_feature_detected!("abm") {
                flags |= Self::ABM;
            }
            if is_x86_feature_detected!("lzcnt") {
                flags |= Self::LZCNT;
            }
            if is_x86_feature_detected!("tbm") {
                flags |= Self::TBM;
            }
            if is_x86_feature_detected!("popcnt") {
                flags |= Self::POPCNT;
            }
            if is_x86_feature_detected!("fxsr") {
                flags |= Self::FXSR;
            }
            if is_x86_feature_detected!("xsave") {
                flags |= Self::XSAVE;
            }
            if is_x86_feature_detected!("xsaveopt") {
                flags |= Self::XSAVEOPT;
            }
            if is_x86_feature_detected!("xsaves") {
                flags |= Self::XSAVES;
            }
            if is_x86_feature_detected!("xsavec") {
                flags |= Self::XSAVEC;
            }
            if is_x86_feature_detected!("cmpxchg16b") {
                flags |= Self::CMPXCHG16B;
            }
            if is_x86_feature_detected!("adx") {
                flags |= Self::ADX;
            }
            if is_x86_feature_detected!("rtm") {
                flags |= Self::RTM;
            }
        }

        #[cfg(any(target_arch = "mips", target_arch = "mips64"))]
        {
            // is_mips_feature_detected
            // is_mips64_feature_detected
            todo!();
        }

        #[cfg(any(target_arch = "powerpc", target_arch = "powerpc64"))]
        {
            // is_powerpc_feature_detected
            // is_powerpc64_feature_detected
            todo!();
        }

        #[cfg(target_arch = "arm")]
        {
            // is_arm_feature_detected
            todo!();
        }

        #[cfg(target_arch = "aarch64")]
        {
            // is_aarch64_feature_detected!
            todo!();
        }

        flags
    }
}
