use crate::simd::fallback;

use std::arch::x86_64::*;

#[inline(always)]
pub fn __add8(x: &mut [i32; 8], y: &[i32; 8]) {
    unsafe {
        let x: *mut i32 = x.as_mut_ptr();
        let y: *const i32 = y.as_ptr();
        _mm256_storeu_si256(
            x as *mut __m256i,
            _mm256_add_epi32(
                _mm256_loadu_si256(x as *const __m256i),
                _mm256_loadu_si256(y as *const __m256i),
            ),
        );
    }
}

#[inline(always)]
pub fn __add16(x: &mut [i32; 16], y: &[i32; 16]) {
    unsafe {
        let x: *mut i32 = x.as_mut_ptr();
        let y: *const i32 = y.as_ptr();
        _mm256_storeu_si256(
            x as *mut __m256i,
            _mm256_add_epi32(
                _mm256_loadu_si256(x as *const __m256i),
                _mm256_loadu_si256(y as *const __m256i),
            ),
        );
        _mm256_storeu_si256(
            x.offset(8) as *mut __m256i,
            _mm256_add_epi32(
                _mm256_loadu_si256(x.offset(8) as *const __m256i),
                _mm256_loadu_si256(y.offset(8) as *const __m256i),
            ),
        );
    }
}

#[inline(always)]
pub fn __sub8(x: &mut [i32; 8], y: &[i32; 8]) {
    unsafe {
        let x: *mut i32 = x.as_mut_ptr();
        let y: *const i32 = y.as_ptr();
        _mm256_storeu_si256(
            x as *mut __m256i,
            _mm256_sub_epi32(
                _mm256_loadu_si256(x as *const __m256i),
                _mm256_loadu_si256(y as *const __m256i),
            ),
        );
    }
}

#[inline(always)]
pub fn __sub16(x: &mut [i32; 16], y: &[i32; 16]) {
    unsafe {
        let x: *mut i32 = x.as_mut_ptr();
        let y: *const i32 = y.as_ptr();
        _mm256_storeu_si256(
            x as *mut __m256i,
            _mm256_sub_epi32(
                _mm256_loadu_si256(x as *const __m256i),
                _mm256_loadu_si256(y as *const __m256i),
            ),
        );
        _mm256_storeu_si256(
            x.offset(8) as *mut __m256i,
            _mm256_sub_epi32(
                _mm256_loadu_si256(x.offset(8) as *const __m256i),
                _mm256_loadu_si256(y.offset(8) as *const __m256i),
            ),
        );
    }
}

#[inline(always)]
pub fn __mul8(x: &mut [i32; 8], y: &[i32; 8]) {
    unsafe {
        let x: *mut i32 = x.as_mut_ptr();
        let y: *const i32 = y.as_ptr();
        _mm256_storeu_si256(
            x as *mut __m256i,
            _mm256_mullo_epi32(
                _mm256_loadu_si256(x as *const __m256i),
                _mm256_loadu_si256(y as *const __m256i),
            ),
        );
    }
}

#[inline(always)]
pub fn __mul16(x: &mut [i32; 16], y: &[i32; 16]) {
    unsafe {
        let x: *mut i32 = x.as_mut_ptr();
        let y: *const i32 = y.as_ptr();
        _mm256_storeu_si256(
            x as *mut __m256i,
            _mm256_mullo_epi32(
                _mm256_loadu_si256(x as *const __m256i),
                _mm256_loadu_si256(y as *const __m256i),
            ),
        );
        _mm256_storeu_si256(
            x.offset(8) as *mut __m256i,
            _mm256_mullo_epi32(
                _mm256_loadu_si256(x.offset(8) as *const __m256i),
                _mm256_loadu_si256(y.offset(8) as *const __m256i),
            ),
        );
    }
}

#[inline(always)]
pub fn __div8(x: &mut [i32; 8], y: &[i32; 8]) {
    fallback::i32::__div8(x, y);
}

#[inline(always)]
pub fn __div16(x: &mut [i32; 16], y: &[i32; 16]) {
    fallback::i32::__div16(x, y);
}

#[inline(always)]
pub fn __mod8(x: &mut [i32; 8], y: &[i32; 8]) {
    fallback::i32::__mod8(x, y);
}

#[inline(always)]
pub fn __mod16(x: &mut [i32; 16], y: &[i32; 16]) {
    fallback::i32::__mod16(x, y);
}

#[inline(always)]
pub fn __and8(x: &mut [i32; 8], y: &[i32; 8]) {
    unsafe {
        let x: *mut i32 = x.as_mut_ptr();
        let y: *const i32 = y.as_ptr();
        _mm256_storeu_si256(
            x as *mut __m256i,
            _mm256_and_si256(
                _mm256_loadu_si256(x as *const __m256i),
                _mm256_loadu_si256(y as *const __m256i),
            ),
        );
    }
}

#[inline(always)]
pub fn __and16(x: &mut [i32; 16], y: &[i32; 16]) {
    unsafe {
        let x: *mut i32 = x.as_mut_ptr();
        let y: *const i32 = y.as_ptr();
        _mm256_storeu_si256(
            x as *mut __m256i,
            _mm256_and_si256(
                _mm256_loadu_si256(x as *const __m256i),
                _mm256_loadu_si256(y as *const __m256i),
            ),
        );
        _mm256_storeu_si256(
            x.offset(8) as *mut __m256i,
            _mm256_and_si256(
                _mm256_loadu_si256(x.offset(8) as *const __m256i),
                _mm256_loadu_si256(y.offset(8) as *const __m256i),
            ),
        );
    }
}

#[inline(always)]
pub fn __or8(x: &mut [i32; 8], y: &[i32; 8]) {
    unsafe {
        let x: *mut i32 = x.as_mut_ptr();
        let y: *const i32 = y.as_ptr();
        _mm256_storeu_si256(
            x as *mut __m256i,
            _mm256_or_si256(
                _mm256_loadu_si256(x as *const __m256i),
                _mm256_loadu_si256(y as *const __m256i),
            ),
        );
    }
}

#[inline(always)]
pub fn __or16(x: &mut [i32; 16], y: &[i32; 16]) {
    unsafe {
        let x: *mut i32 = x.as_mut_ptr();
        let y: *const i32 = y.as_ptr();
        _mm256_storeu_si256(
            x as *mut __m256i,
            _mm256_or_si256(
                _mm256_loadu_si256(x as *const __m256i),
                _mm256_loadu_si256(y as *const __m256i),
            ),
        );
        _mm256_storeu_si256(
            x.offset(8) as *mut __m256i,
            _mm256_or_si256(
                _mm256_loadu_si256(x.offset(8) as *const __m256i),
                _mm256_loadu_si256(y.offset(8) as *const __m256i),
            ),
        );
    }
}

#[inline(always)]
pub fn __xor8(x: &mut [i32; 8], y: &[i32; 8]) {
    unsafe {
        let x: *mut i32 = x.as_mut_ptr();
        let y: *const i32 = y.as_ptr();
        _mm256_storeu_si256(
            x as *mut __m256i,
            _mm256_xor_si256(
                _mm256_loadu_si256(x as *const __m256i),
                _mm256_loadu_si256(y as *const __m256i),
            ),
        );
    }
}

#[inline(always)]
pub fn __xor16(x: &mut [i32; 16], y: &[i32; 16]) {
    unsafe {
        let x: *mut i32 = x.as_mut_ptr();
        let y: *const i32 = y.as_ptr();
        _mm256_storeu_si256(
            x as *mut __m256i,
            _mm256_xor_si256(
                _mm256_loadu_si256(x as *const __m256i),
                _mm256_loadu_si256(y as *const __m256i),
            ),
        );
        _mm256_storeu_si256(
            x.offset(8) as *mut __m256i,
            _mm256_xor_si256(
                _mm256_loadu_si256(x.offset(8) as *const __m256i),
                _mm256_loadu_si256(y.offset(8) as *const __m256i),
            ),
        );
    }
}

#[inline(always)]
pub fn __sal8(x: &mut [i32; 8], y: &[i32; 8]) {
    fallback::i32::__sal8(x, y);
}

#[inline(always)]
pub fn __sal16(x: &mut [i32; 16], y: &[i32; 16]) {
    fallback::i32::__sal16(x, y);
}

#[inline(always)]
pub fn __sar8(x: &mut [i32; 8], y: &[i32; 8]) {
    fallback::i32::__sar8(x, y);
}

#[inline(always)]
pub fn __sar16(x: &mut [i32; 16], y: &[i32; 16]) {
    fallback::i32::__sar16(x, y);
}

#[inline(always)]
pub fn __rol4(x: &mut [i32; 4], y: &[i32; 4]) {
    fallback::i32::__rol4(x, y);
}

#[inline(always)]
pub fn __rol8(x: &mut [i32; 8], y: &[i32; 8]) {
    fallback::i32::__rol8(x, y);
}

#[inline(always)]
pub fn __rol16(x: &mut [i32; 16], y: &[i32; 16]) {
    fallback::i32::__rol16(x, y);
}

#[inline(always)]
pub fn __ror4(x: &mut [i32; 4], y: &[i32; 4]) {
    fallback::i32::__ror4(x, y);
}

#[inline(always)]
pub fn __ror8(x: &mut [i32; 8], y: &[i32; 8]) {
    fallback::i32::__ror8(x, y);
}

#[inline(always)]
pub fn __ror16(x: &mut [i32; 16], y: &[i32; 16]) {
    fallback::i32::__ror16(x, y);
}

#[cfg(test)]
mod test {
    use crate::simd::fallback;

    #[test]
    fn __add8() {
        let y = [3, -5, 8, 200, -32, -0x80000000, 0x7FFFFFFF, 2];
        let mut x_simd = [4, 2, 8, 109, 9, 134, 21, 3];
        let mut x_fallback = x_simd;
        super::__add8(&mut x_simd, &y);
        fallback::i32::__add8(&mut x_fallback, &y);
        for (x, y) in x_simd.iter().zip(x_fallback.iter()) {
            assert_eq!(x, y);
        }
    }

    #[test]
    fn __add16() {
        let y = [
            4,
            2,
            8,
            109,
            9,
            -0x80000000,
            0x7FFFFFFF,
            3,
            4,
            2,
            8,
            109,
            9,
            134,
            21,
            3,
        ];
        let mut x_simd = [3, -5, 8, 200, -32, 92, 12, 2, 3, -5, 8, 200, -32, 92, 12, 2];
        let mut x_fallback = x_simd;
        super::__add16(&mut x_simd, &y);
        fallback::i32::__add16(&mut x_fallback, &y);
        for (x, y) in x_simd.iter().zip(x_fallback.iter()) {
            assert_eq!(x, y);
        }
    }

    #[test]
    fn __sub8() {
        let y = [3, -5, 8, 200, -32, -0x80000000, 0x7FFFFFFF, 2];
        let mut x_simd = [4, 2, 8, 109, 9, 134, 21, 3];
        let mut x_fallback = x_simd;
        super::__sub8(&mut x_simd, &y);
        fallback::i32::__sub8(&mut x_fallback, &y);
        for (x, y) in x_simd.iter().zip(x_fallback.iter()) {
            assert_eq!(x, y);
        }
    }

    #[test]
    fn __sub16() {
        let y = [
            4,
            2,
            8,
            109,
            9,
            134,
            21,
            3,
            4,
            -0x80000000,
            0x7FFFFFFF,
            109,
            9,
            134,
            21,
            3,
        ];
        let mut x_simd = [3, -5, 8, 200, -32, 92, 12, 2, 3, -5, 8, 200, -32, 92, 12, 2];
        let mut x_fallback = x_simd;
        super::__sub16(&mut x_simd, &y);
        fallback::i32::__sub16(&mut x_fallback, &y);
        for (x, y) in x_simd.iter().zip(x_fallback.iter()) {
            assert_eq!(x, y);
        }
    }

    #[test]
    fn __mul8() {
        let y = [3, -5, 8, 200, -32, -0x80000000, 0x7FFFFFFF, 2];
        let mut x_simd = [4, 2, 8, 109, 9, 134, 21, 3];
        let mut x_fallback = x_simd;
        super::__mul8(&mut x_simd, &y);
        fallback::i32::__mul8(&mut x_fallback, &y);
        for (x, y) in x_simd.iter().zip(x_fallback.iter()) {
            assert_eq!(x, y);
        }
    }

    #[test]
    fn __mul16() {
        let y = [
            4,
            2,
            8,
            109,
            9,
            134,
            21,
            -0x80000000,
            0x7FFFFFFF,
            2,
            8,
            109,
            9,
            134,
            21,
            3,
        ];
        let mut x_simd = [3, -5, 8, 200, -32, 92, 12, 2, 3, -5, 8, 200, -32, 92, 12, 2];
        let mut x_fallback = x_simd;
        super::__mul16(&mut x_simd, &y);
        fallback::i32::__mul16(&mut x_fallback, &y);
        for (x, y) in x_simd.iter().zip(x_fallback.iter()) {
            assert_eq!(x, y);
        }
    }

    #[test]
    fn __div8() {
        let y = [3, -5, 8, 200, -32, -0x80000000, 0x7FFFFFFF, 2];
        let mut x_simd = [4, 2, 8, 109, 9, 134, 21, 3];
        let mut x_fallback = x_simd;
        super::__div8(&mut x_simd, &y);
        fallback::i32::__div8(&mut x_fallback, &y);
        for (x, y) in x_simd.iter().zip(x_fallback.iter()) {
            assert_eq!(x, y);
        }
    }

    #[test]
    fn __div16() {
        let y = [
            4,
            2,
            8,
            109,
            9,
            134,
            -0x80000000,
            0x7FFFFFFF,
            4,
            2,
            8,
            109,
            9,
            134,
            21,
            3,
        ];
        let mut x_simd = [3, -5, 8, 200, -32, 92, 12, 2, 3, -5, 8, 200, -32, 92, 12, 2];
        let mut x_fallback = x_simd;
        super::__div16(&mut x_simd, &y);
        fallback::i32::__div16(&mut x_fallback, &y);
        for (x, y) in x_simd.iter().zip(x_fallback.iter()) {
            assert_eq!(x, y);
        }
    }

    #[test]
    fn __mod8() {
        let y = [3, -5, 8, 200, -32, -0x80000000, 0x7FFFFFFF, 2];
        let mut x_simd = [4, 2, 8, 109, 9, 134, 21, 3];
        let mut x_fallback = x_simd;
        super::__mod8(&mut x_simd, &y);
        fallback::i32::__mod8(&mut x_fallback, &y);
        for (x, y) in x_simd.iter().zip(x_fallback.iter()) {
            assert_eq!(x, y);
        }
    }

    #[test]
    fn __mod16() {
        let y = [
            4,
            2,
            8,
            109,
            9,
            134,
            21,
            3,
            -0x80000000,
            0x7FFFFFFF,
            8,
            109,
            9,
            134,
            21,
            3,
        ];
        let mut x_simd = [3, -5, 8, 200, -32, 92, 12, 2, 3, -5, 8, 200, -32, 92, 12, 2];
        let mut x_fallback = x_simd;
        super::__mod16(&mut x_simd, &y);
        fallback::i32::__mod16(&mut x_fallback, &y);
        for (x, y) in x_simd.iter().zip(x_fallback.iter()) {
            assert_eq!(x, y);
        }
    }

    #[test]
    fn __and8() {
        let y = [3, -5, 8, 200, -32, 92, -0x80000000, 0x7FFFFFFF];
        let mut x_simd = [4, 2, 8, 109, 9, 134, 21, 3];
        let mut x_fallback = x_simd;
        super::__and8(&mut x_simd, &y);
        fallback::i32::__and8(&mut x_fallback, &y);
        for (x, y) in x_simd.iter().zip(x_fallback.iter()) {
            assert_eq!(x, y);
        }
    }

    #[test]
    fn __and16() {
        let y = [
            4,
            2,
            8,
            109,
            9,
            134,
            21,
            3,
            -0x80000000,
            0x7FFFFFFF,
            8,
            109,
            9,
            134,
            21,
            3,
        ];
        let mut x_simd = [3, -5, 8, 200, -32, 92, 12, 2, 3, -5, 8, 200, -32, 92, 12, 2];
        let mut x_fallback = x_simd;
        super::__and16(&mut x_simd, &y);
        fallback::i32::__and16(&mut x_fallback, &y);
        for (x, y) in x_simd.iter().zip(x_fallback.iter()) {
            assert_eq!(x, y);
        }
    }

    #[test]
    fn __or8() {
        let y = [3, -5, 8, 200, -32, 92, -0x80000000, 0x7FFFFFFF];
        let mut x_simd = [4, 2, 8, 109, 9, 134, 21, 3];
        let mut x_fallback = x_simd;
        super::__or8(&mut x_simd, &y);
        fallback::i32::__or8(&mut x_fallback, &y);
        for (x, y) in x_simd.iter().zip(x_fallback.iter()) {
            assert_eq!(x, y);
        }
    }

    #[test]
    fn __or16() {
        let y = [
            4,
            2,
            8,
            109,
            9,
            134,
            21,
            3,
            -0x80000000,
            0x7FFFFFFF,
            8,
            109,
            9,
            134,
            21,
            3,
        ];
        let mut x_simd = [3, -5, 8, 200, -32, 92, 12, 2, 3, -5, 8, 200, -32, 92, 12, 2];
        let mut x_fallback = x_simd;
        super::__or16(&mut x_simd, &y);
        fallback::i32::__or16(&mut x_fallback, &y);
        for (x, y) in x_simd.iter().zip(x_fallback.iter()) {
            assert_eq!(x, y);
        }
    }

    #[test]
    fn __xor8() {
        let y = [3, -5, 8, 200, -32, -0x80000000, 0x7FFFFFFF, 2];
        let mut x_simd = [4, 2, 8, 109, 9, 134, 21, 3];
        let mut x_fallback = x_simd;
        super::__xor8(&mut x_simd, &y);
        fallback::i32::__xor8(&mut x_fallback, &y);
        for (x, y) in x_simd.iter().zip(x_fallback.iter()) {
            assert_eq!(x, y);
        }
    }

    #[test]
    fn __xor16() {
        let y = [
            4,
            2,
            8,
            109,
            9,
            134,
            -0x80000000,
            0x7FFFFFFF,
            2,
            43,
            8,
            109,
            9,
            134,
            21,
            3,
        ];
        let mut x_simd = [3, -5, 8, 200, -32, 92, 12, 2, 3, -5, 8, 200, -32, 92, 12, 2];
        let mut x_fallback = x_simd;
        super::__xor16(&mut x_simd, &y);
        fallback::i32::__xor16(&mut x_fallback, &y);
        for (x, y) in x_simd.iter().zip(x_fallback.iter()) {
            assert_eq!(x, y);
        }
    }

    #[test]
    fn __sal8() {
        let y = [3, -5, 8, 200, -32, -0x80000000, 0x7FFFFFFF, 2];
        let mut x_simd = [4, 2, 8, 109, 9, 134, 21, 3];
        let mut x_fallback = x_simd;
        super::__sal8(&mut x_simd, &y);
        fallback::i32::__sal8(&mut x_fallback, &y);
        for (x, y) in x_simd.iter().zip(x_fallback.iter()) {
            assert_eq!(x, y);
        }
    }

    #[test]
    fn __sal16() {
        let y = [
            4,
            2,
            8,
            109,
            9,
            134,
            21,
            -0x80000000,
            0x7FFFFFFF,
            2,
            8,
            109,
            9,
            134,
            21,
            3,
        ];
        let mut x_simd = [3, -5, 8, 200, -32, 92, 12, 2, 3, -5, 8, 200, -32, 92, 12, 2];
        let mut x_fallback = x_simd;
        super::__sal16(&mut x_simd, &y);
        fallback::i32::__sal16(&mut x_fallback, &y);
        for (x, y) in x_simd.iter().zip(x_fallback.iter()) {
            assert_eq!(x, y);
        }
    }

    #[test]
    fn __sar8() {
        let y = [3, -5, 8, 200, -32, -0x80000000, 0x7FFFFFFF, 2];
        let mut x_simd = [4, 2, 8, 109, 9, 134, 21, 3];
        let mut x_fallback = x_simd;
        super::__sar8(&mut x_simd, &y);
        fallback::i32::__sar8(&mut x_fallback, &y);
        for (x, y) in x_simd.iter().zip(x_fallback.iter()) {
            assert_eq!(x, y);
        }
    }

    #[test]
    fn __sar16() {
        let y = [
            4,
            2,
            8,
            109,
            9,
            134,
            21,
            -0x80000000,
            0x7FFFFFFF,
            2,
            8,
            109,
            9,
            134,
            21,
            3,
        ];
        let mut x_simd = [3, -5, 8, 200, -32, 92, 12, 2, 3, -5, 8, 200, -32, 92, 12, 2];
        let mut x_fallback = x_simd;
        super::__sar16(&mut x_simd, &y);
        fallback::i32::__sar16(&mut x_fallback, &y);
        for (x, y) in x_simd.iter().zip(x_fallback.iter()) {
            assert_eq!(x, y);
        }
    }

    #[test]
    fn __rol8() {
        let y = [3, -5, 8, 200, -32, 92, -0x80000000, 0x7FFFFFFF];
        let mut x_simd = [4, 2, 8, 109, 9, 134, 21, 3];
        let mut x_fallback = x_simd;
        super::__rol8(&mut x_simd, &y);
        fallback::i32::__rol8(&mut x_fallback, &y);
        for (x, y) in x_simd.iter().zip(x_fallback.iter()) {
            assert_eq!(x, y);
        }
    }

    #[test]
    fn __rol16() {
        let y = [
            4,
            2,
            8,
            109,
            9,
            134,
            21,
            -0x80000000,
            0x7FFFFFFF,
            2,
            8,
            109,
            9,
            134,
            21,
            3,
        ];
        let mut x_simd = [3, -5, 8, 200, -32, 92, 12, 2, 3, -5, 8, 200, -32, 92, 12, 2];
        let mut x_fallback = x_simd;
        super::__rol16(&mut x_simd, &y);
        fallback::i32::__rol16(&mut x_fallback, &y);
        for (x, y) in x_simd.iter().zip(x_fallback.iter()) {
            assert_eq!(x, y);
        }
    }

    #[test]
    fn __ror8() {
        let y = [3, -5, 8, 200, -32, -0x80000000, 0x7FFFFFFF, 2];
        let mut x_simd = [4, 2, 8, 109, 9, 134, 21, 3];
        let mut x_fallback = x_simd;
        super::__ror8(&mut x_simd, &y);
        fallback::i32::__ror8(&mut x_fallback, &y);
        for (x, y) in x_simd.iter().zip(x_fallback.iter()) {
            assert_eq!(x, y);
        }
    }

    #[test]
    fn __ror16() {
        let y = [
            4,
            2,
            8,
            109,
            9,
            134,
            21,
            -0x80000000,
            0x7FFFFFFF,
            2,
            8,
            109,
            9,
            134,
            21,
            3,
        ];
        let mut x_simd = [3, -5, 8, 200, -32, 92, 12, 2, 3, -5, 8, 200, -32, 92, 12, 2];
        let mut x_fallback = x_simd;
        super::__ror16(&mut x_simd, &y);
        fallback::i32::__ror16(&mut x_fallback, &y);
        for (x, y) in x_simd.iter().zip(x_fallback.iter()) {
            assert_eq!(x, y);
        }
    }
}
