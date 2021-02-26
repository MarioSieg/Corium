use std::arch::x86_64::*;

#[inline(always)]
pub fn __fma4(x: &mut [f32; 4], y: &[f32; 4], z: &[f32; 4]) {
    unsafe {
        let x: *mut f32 = x.as_mut_ptr();
        let y: *const f32 = y.as_ptr();
        let z: *const f32 = z.as_ptr();
        _mm_storeu_ps(
            x,
            _mm_fmadd_ps(_mm_loadu_ps(x), _mm_loadu_ps(y), _mm_loadu_ps(z)),
        );
    }
}

#[inline(always)]
pub fn __fma8(x: &mut [f32; 8], y: &[f32; 8], z: &[f32; 8]) {
    unsafe {
        let x: *mut f32 = x.as_mut_ptr();
        let y: *const f32 = y.as_ptr();
        let z: *const f32 = z.as_ptr();
        _mm256_storeu_ps(
            x,
            _mm256_fmadd_ps(_mm256_loadu_ps(x), _mm256_loadu_ps(y), _mm256_loadu_ps(z)),
        );
    }
}

#[inline(always)]
pub fn __fma16(x: &mut [f32; 16], y: &[f32; 16], z: &[f32; 16]) {
    unsafe {
        let x: *mut f32 = x.as_mut_ptr();
        let y: *const f32 = y.as_ptr();
        let z: *const f32 = z.as_ptr();
        _mm256_storeu_ps(
            x,
            _mm256_fmadd_ps(_mm256_loadu_ps(x), _mm256_loadu_ps(y), _mm256_loadu_ps(z)),
        );
        _mm256_storeu_ps(
            x.offset(8),
            _mm256_fmadd_ps(
                _mm256_loadu_ps(x.offset(8)),
                _mm256_loadu_ps(y.offset(8)),
                _mm256_loadu_ps(z.offset(8)),
            ),
        );
    }
}

#[cfg(test)]
mod tests {
    use crate::simd::fallback;

    #[test]
    fn __fma4() {
        let y = [3.0, -5.0, 8.0, 200.0];
        let z = y;
        let mut x_simd = [32.0, 2883.0, f32::MAX, f32::MIN];
        let mut x_fallback = x_simd;
        super::__fma4(&mut x_simd, &y, &z);
        fallback::f32::__fma4(&mut x_fallback, &y, &z);
        for (x, y) in x_simd.iter().zip(x_fallback.iter()) {
            assert_eq!(x, y);
        }
    }

    #[test]
    fn __fma8() {
        let y = [3.0, -5.0, 8.0, 200.0, -32.0, f32::MAX, f32::MIN, 2.0];
        let z = y;
        let mut x_simd = [4.0, 2.0, 8.0, 109.0, 9.0, 134.0, 21.0, 3.0];
        let mut x_fallback = x_simd;
        super::__fma8(&mut x_simd, &y, &z);
        fallback::f32::__fma8(&mut x_fallback, &y, &z);
        for (x, y) in x_simd.iter().zip(x_fallback.iter()) {
            assert_eq!(x, y);
        }
    }

    #[test]
    fn __fma16() {
        let y = [
            4.0,
            2.0,
            8.0,
            109.0,
            9.0,
            134.0,
            21.0,
            3.0,
            f32::MAX,
            f32::MIN,
            8.0,
            109.0,
            9.0,
            134.0,
            21.0,
            3.0,
        ];
        let z = y;
        let mut x_simd = [
            3.0, -5.0, 8.0, 200.0, -32.0, 92.0, 12.0, 2.0, 3.0, -5.0, 8.0, 200.0, -32.0, 92.0,
            12.0, 2.0,
        ];
        let mut x_fallback = x_simd;
        super::__fma16(&mut x_simd, &y, &z);
        fallback::f32::__fma16(&mut x_fallback, &y, &z);
        for (x, y) in x_simd.iter().zip(x_fallback.iter()) {
            assert_eq!(x, y);
        }
    }
}
