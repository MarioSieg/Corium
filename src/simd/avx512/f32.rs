use crate::simd::fallback;

// Foreign function interface for f32.c
// AVX-512 intrinsics are not yet available in Rust.
mod ffi {
    extern "C" {
        #[no_mangle]
        pub fn __add16(x: *mut f32, y: *const f32);

        #[no_mangle]
        pub fn __sub16(x: *mut f32, y: *const f32);

        #[no_mangle]
        pub fn __mul16(x: *mut f32, y: *const f32);

        #[no_mangle]
        pub fn __div16(x: *mut f32, y: *const f32);
    }
}

#[inline(always)]
pub fn __add16(x: &mut [f32; 16], y: &[f32; 16]) {
    unsafe {
        ffi::__add16(x.as_mut_ptr(), y.as_ptr());
    }
}

#[inline(always)]
pub fn __sub16(x: &mut [f32; 16], y: &[f32; 16]) {
    unsafe {
        ffi::__sub16(x.as_mut_ptr(), y.as_ptr());
    }
}

#[inline(always)]
pub fn __mul16(x: &mut [f32; 16], y: &[f32; 16]) {
    unsafe {
        ffi::__mul16(x.as_mut_ptr(), y.as_ptr());
    }
}

#[inline(always)]
pub fn __div16(x: &mut [f32; 16], y: &[f32; 16]) {
    unsafe {
        ffi::__div16(x.as_mut_ptr(), y.as_ptr());
    }
}
