use crate::simd::fallback;

// Foreign function interface for i32.c
// AVX-512 intrinsics are not yet available in Rust.
mod ffi {
    extern "C" {
        #[no_mangle]
        pub fn __add16(x: *mut i32, y: *const i32);

        #[no_mangle]
        pub fn __sub16(x: *mut i32, y: *const i32);

        #[no_mangle]
        pub fn __mul16(x: *mut i32, y: *const i32);

        #[no_mangle]
        pub fn __and16(x: *mut i32, y: *const i32);

        #[no_mangle]
        pub fn __or16(x: *mut i32, y: *const i32);

        #[no_mangle]
        pub fn __xor16(x: *mut i32, y: *const i32);
    }
}

#[inline(always)]
pub fn __add16(x: &mut [i32; 16], y: &[i32; 16]) {
    unsafe {
        ffi::__add16(x.as_mut_ptr(), y.as_ptr());
    }
}
#[inline(always)]
pub fn __sub16(x: &mut [i32; 16], y: &[i32; 16]) {
    unsafe {
        ffi::__sub16(x.as_mut_ptr(), y.as_ptr());
    }
}

#[inline(always)]
pub fn __mul16(x: &mut [i32; 16], y: &[i32; 16]) {
    unsafe {
        ffi::__mul16(x.as_mut_ptr(), y.as_ptr());
    }
}
#[inline(always)]
pub fn __and16(x: &mut [i32; 16], y: &[i32; 16]) {
    unsafe {
        ffi::__and16(x.as_mut_ptr(), y.as_ptr());
    }
}

#[inline(always)]
pub fn __or16(x: &mut [i32; 16], y: &[i32; 16]) {
    unsafe {
        ffi::__or16(x.as_mut_ptr(), y.as_ptr());
    }
}

#[inline(always)]
pub fn __xor16(x: &mut [i32; 16], y: &[i32; 16]) {
    unsafe {
        ffi::__xor16(x.as_mut_ptr(), y.as_ptr());
    }
}
