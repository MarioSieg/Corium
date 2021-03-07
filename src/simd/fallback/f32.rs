#[inline(always)]
pub fn __add4(x: &mut [f32; 4], y: &[f32; 4]) {
    x[0] += y[0];
    x[1] += y[1];
    x[2] += y[2];
    x[3] += y[3];
}

#[inline(always)]
pub fn __add4_slice(x: &mut [f32], y: &[f32]) {
    debug_assert_eq!(x.len(), 4);
    debug_assert_eq!(y.len(), 4);
    let x: &mut [f32; 4] = unsafe { &mut *(x.as_mut_ptr() as *mut [f32; 4]) };
    let y: &[f32; 4] = unsafe { &*(x.as_ptr() as *const [f32; 4]) };
    __add4(x, y);
}

#[inline(always)]
pub fn __add8(x: &mut [f32; 8], y: &[f32; 8]) {
    x[0] += y[0];
    x[1] += y[1];
    x[2] += y[2];
    x[3] += y[3];
    x[4] += y[4];
    x[5] += y[5];
    x[6] += y[6];
    x[7] += y[7];
}

#[inline(always)]
pub fn __add8_slice(x: &mut [f32], y: &[f32]) {
    debug_assert_eq!(x.len(), 8);
    debug_assert_eq!(y.len(), 8);
    let x: &mut [f32; 8] = unsafe { &mut *(x.as_mut_ptr() as *mut [f32; 8]) };
    let y: &[f32; 8] = unsafe { &*(x.as_ptr() as *const [f32; 8]) };
    __add8(x, y);
}

#[inline(always)]
pub fn __add16(x: &mut [f32; 16], y: &[f32; 16]) {
    x[0] += y[0];
    x[1] += y[1];
    x[2] += y[2];
    x[3] += y[3];
    x[4] += y[4];
    x[5] += y[5];
    x[6] += y[6];
    x[7] += y[7];
    x[8] += y[8];
    x[9] += y[9];
    x[10] += y[10];
    x[11] += y[11];
    x[12] += y[12];
    x[13] += y[13];
    x[14] += y[14];
    x[15] += y[15];
}

#[inline(always)]
pub fn __add16_slice(x: &mut [f32], y: &[f32]) {
    debug_assert_eq!(x.len(), 16);
    debug_assert_eq!(y.len(), 16);
    let x: &mut [f32; 16] = unsafe { &mut *(x.as_mut_ptr() as *mut [f32; 16]) };
    let y: &[f32; 16] = unsafe { &*(x.as_ptr() as *const [f32; 16]) };
    __add16(x, y);
}

#[inline(always)]
pub fn __sub4(x: &mut [f32; 4], y: &[f32; 4]) {
    x[0] -= y[0];
    x[1] -= y[1];
    x[2] -= y[2];
    x[3] -= y[3];
}

#[inline(always)]
pub fn __sub4_slice(x: &mut [f32], y: &[f32]) {
    debug_assert_eq!(x.len(), 4);
    debug_assert_eq!(y.len(), 4);
    let x: &mut [f32; 4] = unsafe { &mut *(x.as_mut_ptr() as *mut [f32; 4]) };
    let y: &[f32; 4] = unsafe { &*(x.as_ptr() as *const [f32; 4]) };
    __sub4(x, y);
}

#[inline(always)]
pub fn __sub8(x: &mut [f32; 8], y: &[f32; 8]) {
    x[0] -= y[0];
    x[1] -= y[1];
    x[2] -= y[2];
    x[3] -= y[3];
    x[4] -= y[4];
    x[5] -= y[5];
    x[6] -= y[6];
    x[7] -= y[7];
}

#[inline(always)]
pub fn __sub8_slice(x: &mut [f32], y: &[f32]) {
    debug_assert_eq!(x.len(), 8);
    debug_assert_eq!(y.len(), 8);
    let x: &mut [f32; 8] = unsafe { &mut *(x.as_mut_ptr() as *mut [f32; 8]) };
    let y: &[f32; 8] = unsafe { &*(x.as_ptr() as *const [f32; 8]) };
    __sub8(x, y);
}

#[inline(always)]
pub fn __sub16(x: &mut [f32; 16], y: &[f32; 16]) {
    x[0] -= y[0];
    x[1] -= y[1];
    x[2] -= y[2];
    x[3] -= y[3];
    x[4] -= y[4];
    x[5] -= y[5];
    x[6] -= y[6];
    x[7] -= y[7];
    x[8] -= y[8];
    x[9] -= y[9];
    x[10] -= y[10];
    x[11] -= y[11];
    x[12] -= y[12];
    x[13] -= y[13];
    x[14] -= y[14];
    x[15] -= y[15];
}

#[inline(always)]
pub fn __sub16_slice(x: &mut [f32], y: &[f32]) {
    debug_assert_eq!(x.len(), 16);
    debug_assert_eq!(y.len(), 16);
    let x: &mut [f32; 16] = unsafe { &mut *(x.as_mut_ptr() as *mut [f32; 16]) };
    let y: &[f32; 16] = unsafe { &*(x.as_ptr() as *const [f32; 16]) };
    __sub16(x, y);
}

#[inline(always)]
pub fn __mul4(x: &mut [f32; 4], y: &[f32; 4]) {
    x[0] *= y[0];
    x[1] *= y[1];
    x[2] *= y[2];
    x[3] *= y[3];
}

#[inline(always)]
pub fn __mul4_slice(x: &mut [f32], y: &[f32]) {
    debug_assert_eq!(x.len(), 4);
    debug_assert_eq!(y.len(), 4);
    let x: &mut [f32; 4] = unsafe { &mut *(x.as_mut_ptr() as *mut [f32; 4]) };
    let y: &[f32; 4] = unsafe { &*(x.as_ptr() as *const [f32; 4]) };
    __mul4(x, y);
}

#[inline(always)]
pub fn __mul8(x: &mut [f32; 8], y: &[f32; 8]) {
    x[0] *= y[0];
    x[1] *= y[1];
    x[2] *= y[2];
    x[3] *= y[3];
    x[4] *= y[4];
    x[5] *= y[5];
    x[6] *= y[6];
    x[7] *= y[7];
}

#[inline(always)]
pub fn __mul8_slice(x: &mut [f32], y: &[f32]) {
    debug_assert_eq!(x.len(), 8);
    debug_assert_eq!(y.len(), 8);
    let x: &mut [f32; 8] = unsafe { &mut *(x.as_mut_ptr() as *mut [f32; 8]) };
    let y: &[f32; 8] = unsafe { &*(x.as_ptr() as *const [f32; 8]) };
    __mul8(x, y);
}

#[inline(always)]
pub fn __mul16(x: &mut [f32; 16], y: &[f32; 16]) {
    x[0] *= y[0];
    x[1] *= y[1];
    x[2] *= y[2];
    x[3] *= y[3];
    x[4] *= y[4];
    x[5] *= y[5];
    x[6] *= y[6];
    x[7] *= y[7];
    x[8] *= y[8];
    x[9] *= y[9];
    x[10] *= y[10];
    x[11] *= y[11];
    x[12] *= y[12];
    x[13] *= y[13];
    x[14] *= y[14];
    x[15] *= y[15];
}

#[inline(always)]
pub fn __mul16_slice(x: &mut [f32], y: &[f32]) {
    debug_assert_eq!(x.len(), 16);
    debug_assert_eq!(y.len(), 16);
    let x: &mut [f32; 16] = unsafe { &mut *(x.as_mut_ptr() as *mut [f32; 16]) };
    let y: &[f32; 16] = unsafe { &*(x.as_ptr() as *const [f32; 16]) };
    __mul16(x, y);
}

#[inline(always)]
pub fn __div4(x: &mut [f32; 4], y: &[f32; 4]) {
    x[0] /= y[0];
    x[1] /= y[1];
    x[2] /= y[2];
    x[3] /= y[3];
}

#[inline(always)]
pub fn __div4_slice(x: &mut [f32], y: &[f32]) {
    debug_assert_eq!(x.len(), 4);
    debug_assert_eq!(y.len(), 4);
    let x: &mut [f32; 4] = unsafe { &mut *(x.as_mut_ptr() as *mut [f32; 4]) };
    let y: &[f32; 4] = unsafe { &*(x.as_ptr() as *const [f32; 4]) };
    __div4(x, y);
}

#[inline(always)]
pub fn __div8(x: &mut [f32; 8], y: &[f32; 8]) {
    x[0] /= y[0];
    x[1] /= y[1];
    x[2] /= y[2];
    x[3] /= y[3];
    x[4] /= y[4];
    x[5] /= y[5];
    x[6] /= y[6];
    x[7] /= y[7];
}

#[inline(always)]
pub fn __div8_slice(x: &mut [f32], y: &[f32]) {
    debug_assert_eq!(x.len(), 8);
    debug_assert_eq!(y.len(), 8);
    let x: &mut [f32; 8] = unsafe { &mut *(x.as_mut_ptr() as *mut [f32; 8]) };
    let y: &[f32; 8] = unsafe { &*(x.as_ptr() as *const [f32; 8]) };
    __div8(x, y);
}

#[inline(always)]
pub fn __div16(x: &mut [f32; 16], y: &[f32; 16]) {
    x[0] /= y[0];
    x[1] /= y[1];
    x[2] /= y[2];
    x[3] /= y[3];
    x[4] /= y[4];
    x[5] /= y[5];
    x[6] /= y[6];
    x[7] /= y[7];
    x[8] /= y[8];
    x[9] /= y[9];
    x[10] /= y[10];
    x[11] /= y[11];
    x[12] /= y[12];
    x[13] /= y[13];
    x[14] /= y[14];
    x[15] /= y[15];
}

#[inline(always)]
pub fn __div16_slice(x: &mut [f32], y: &[f32]) {
    debug_assert_eq!(x.len(), 16);
    debug_assert_eq!(y.len(), 16);
    let x: &mut [f32; 16] = unsafe { &mut *(x.as_mut_ptr() as *mut [f32; 16]) };
    let y: &[f32; 16] = unsafe { &*(x.as_ptr() as *const [f32; 16]) };
    __div16(x, y);
}

#[inline(always)]
pub fn __mod4(x: &mut [f32; 4], y: &[f32; 4]) {
    x[0] %= y[0];
    x[1] %= y[1];
    x[2] %= y[2];
    x[3] %= y[3];
}

#[inline(always)]
pub fn __mod4_slice(x: &mut [f32], y: &[f32]) {
    debug_assert_eq!(x.len(), 4);
    debug_assert_eq!(y.len(), 4);
    let x: &mut [f32; 4] = unsafe { &mut *(x.as_mut_ptr() as *mut [f32; 4]) };
    let y: &[f32; 4] = unsafe { &*(x.as_ptr() as *const [f32; 4]) };
    __mod4(x, y);
}

#[inline(always)]
pub fn __mod8(x: &mut [f32; 8], y: &[f32; 8]) {
    x[0] %= y[0];
    x[1] %= y[1];
    x[2] %= y[2];
    x[3] %= y[3];
    x[4] %= y[4];
    x[5] %= y[5];
    x[6] %= y[6];
    x[7] %= y[7];
}

#[inline(always)]
pub fn __mod8_slice(x: &mut [f32], y: &[f32]) {
    debug_assert_eq!(x.len(), 8);
    debug_assert_eq!(y.len(), 8);
    let x: &mut [f32; 8] = unsafe { &mut *(x.as_mut_ptr() as *mut [f32; 8]) };
    let y: &[f32; 8] = unsafe { &*(x.as_ptr() as *const [f32; 8]) };
    __mod8(x, y);
}

#[inline(always)]
pub fn __mod16(x: &mut [f32; 16], y: &[f32; 16]) {
    x[0] %= y[0];
    x[1] %= y[1];
    x[2] %= y[2];
    x[3] %= y[3];
    x[4] %= y[4];
    x[5] %= y[5];
    x[6] %= y[6];
    x[7] %= y[7];
    x[8] %= y[8];
    x[9] %= y[9];
    x[10] %= y[10];
    x[11] %= y[11];
    x[12] %= y[12];
    x[13] %= y[13];
    x[14] %= y[14];
    x[15] %= y[15];
}

#[inline(always)]
pub fn __mod16_slice(x: &mut [f32], y: &[f32]) {
    debug_assert_eq!(x.len(), 16);
    debug_assert_eq!(y.len(), 16);
    let x: &mut [f32; 16] = unsafe { &mut *(x.as_mut_ptr() as *mut [f32; 16]) };
    let y: &[f32; 16] = unsafe { &*(x.as_ptr() as *const [f32; 16]) };
    __mod16(x, y);
}

#[inline(always)]
pub fn __fma4(x: &mut [f32; 4], y: &[f32; 4], z: &[f32; 4]) {
    x[0] = x[0].mul_add(y[0], z[0]);
    x[1] = x[1].mul_add(y[1], z[1]);
    x[2] = x[2].mul_add(y[2], z[2]);
    x[3] = x[3].mul_add(y[3], z[3]);
}

#[inline(always)]
pub fn __fma4_slice(x: &mut [f32], y: &[f32], z: &[f32]) {
    debug_assert_eq!(x.len(), 4);
    debug_assert_eq!(y.len(), 4);
    debug_assert_eq!(z.len(), 4);
    let x: &mut [f32; 4] = unsafe { &mut *(x.as_mut_ptr() as *mut [f32; 4]) };
    let y: &[f32; 4] = unsafe { &*(x.as_ptr() as *const [f32; 4]) };
    let z: &[f32; 4] = unsafe { &*(z.as_ptr() as *const [f32; 4]) };
    __fma4(x, y, z);
}

#[inline(always)]
pub fn __fma8(x: &mut [f32; 8], y: &[f32; 8], z: &[f32; 8]) {
    x[0] = x[0].mul_add(y[0], z[0]);
    x[1] = x[1].mul_add(y[1], z[1]);
    x[2] = x[2].mul_add(y[2], z[2]);
    x[3] = x[3].mul_add(y[3], z[3]);
    x[4] = x[4].mul_add(y[4], z[4]);
    x[5] = x[5].mul_add(y[5], z[5]);
    x[6] = x[6].mul_add(y[6], z[6]);
    x[7] = x[7].mul_add(y[7], z[7]);
}

#[inline(always)]
pub fn __fma8_slice(x: &mut [f32], y: &[f32], z: &[f32]) {
    debug_assert_eq!(x.len(), 8);
    debug_assert_eq!(y.len(), 8);
    debug_assert_eq!(z.len(), 8);
    let x: &mut [f32; 8] = unsafe { &mut *(x.as_mut_ptr() as *mut [f32; 8]) };
    let y: &[f32; 8] = unsafe { &*(x.as_ptr() as *const [f32; 8]) };
    let z: &[f32; 8] = unsafe { &*(z.as_ptr() as *const [f32; 8]) };
    __fma8(x, y, z);
}

#[inline(always)]
pub fn __fma16(x: &mut [f32; 16], y: &[f32; 16], z: &[f32; 16]) {
    x[0] = x[0].mul_add(y[0], z[0]);
    x[1] = x[1].mul_add(y[1], z[1]);
    x[2] = x[2].mul_add(y[2], z[2]);
    x[3] = x[3].mul_add(y[3], z[3]);
    x[4] = x[4].mul_add(y[4], z[4]);
    x[5] = x[5].mul_add(y[5], z[5]);
    x[6] = x[6].mul_add(y[6], z[6]);
    x[7] = x[7].mul_add(y[7], z[7]);
    x[8] = x[8].mul_add(y[8], z[8]);
    x[9] = x[9].mul_add(y[9], z[9]);
    x[10] = x[10].mul_add(y[10], z[10]);
    x[11] = x[11].mul_add(y[11], z[11]);
    x[12] = x[12].mul_add(y[12], z[12]);
    x[13] = x[13].mul_add(y[13], z[13]);
    x[14] = x[14].mul_add(y[14], z[14]);
    x[15] = x[15].mul_add(y[15], z[15]);
}

#[inline(always)]
pub fn __fma16_slice(x: &mut [f32], y: &[f32], z: &[f32]) {
    debug_assert_eq!(x.len(), 16);
    debug_assert_eq!(y.len(), 16);
    debug_assert_eq!(z.len(), 16);
    let x: &mut [f32; 16] = unsafe { &mut *(x.as_mut_ptr() as *mut [f32; 16]) };
    let y: &[f32; 16] = unsafe { &*(x.as_ptr() as *const [f32; 16]) };
    let z: &[f32; 16] = unsafe { &*(z.as_ptr() as *const [f32; 16]) };
    __fma16(x, y, z);
}
