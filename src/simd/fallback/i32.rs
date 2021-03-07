#[inline(always)]
pub fn __add4(x: &mut [i32; 4], y: &[i32; 4]) {
    x[0] = x[0].wrapping_add(y[0]);
    x[1] = x[1].wrapping_add(y[1]);
    x[2] = x[2].wrapping_add(y[2]);
    x[3] = x[3].wrapping_add(y[3]);
}

#[inline(always)]
pub fn __add4_slice(x: &mut [i32], y: &[i32]) {
    debug_assert_eq!(x.len(), 4);
    debug_assert_eq!(y.len(), 4);
    let x: &mut [i32; 4] = unsafe { &mut *(x.as_mut_ptr() as *mut [i32; 4]) };
    let y: &[i32; 4] = unsafe { &*(x.as_ptr() as *const [i32; 4]) };
    __add4(x, y);
}

#[inline(always)]
pub fn __add8(x: &mut [i32; 8], y: &[i32; 8]) {
    x[0] = x[0].wrapping_add(y[0]);
    x[1] = x[1].wrapping_add(y[1]);
    x[2] = x[2].wrapping_add(y[2]);
    x[3] = x[3].wrapping_add(y[3]);
    x[4] = x[4].wrapping_add(y[4]);
    x[5] = x[5].wrapping_add(y[5]);
    x[6] = x[6].wrapping_add(y[6]);
    x[7] = x[7].wrapping_add(y[7]);
}

#[inline(always)]
pub fn __add8_slice(x: &mut [i32], y: &[i32]) {
    debug_assert_eq!(x.len(), 8);
    debug_assert_eq!(y.len(), 8);
    let x: &mut [i32; 8] = unsafe { &mut *(x.as_mut_ptr() as *mut [i32; 8]) };
    let y: &[i32; 8] = unsafe { &*(x.as_ptr() as *const [i32; 8]) };
    __add8(x, y);
}

#[inline(always)]
pub fn __add16(x: &mut [i32; 16], y: &[i32; 16]) {
    x[0] = x[0].wrapping_add(y[0]);
    x[1] = x[1].wrapping_add(y[1]);
    x[2] = x[2].wrapping_add(y[2]);
    x[3] = x[3].wrapping_add(y[3]);
    x[4] = x[4].wrapping_add(y[4]);
    x[5] = x[5].wrapping_add(y[5]);
    x[6] = x[6].wrapping_add(y[6]);
    x[7] = x[7].wrapping_add(y[7]);
    x[8] = x[8].wrapping_add(y[8]);
    x[9] = x[9].wrapping_add(y[9]);
    x[10] = x[10].wrapping_add(y[10]);
    x[11] = x[11].wrapping_add(y[11]);
    x[12] = x[12].wrapping_add(y[12]);
    x[13] = x[13].wrapping_add(y[13]);
    x[14] = x[14].wrapping_add(y[14]);
    x[15] = x[15].wrapping_add(y[15]);
}

#[inline(always)]
pub fn __add16_slice(x: &mut [i32], y: &[i32]) {
    debug_assert_eq!(x.len(), 16);
    debug_assert_eq!(y.len(), 16);
    let x: &mut [i32; 16] = unsafe { &mut *(x.as_mut_ptr() as *mut [i32; 16]) };
    let y: &[i32; 16] = unsafe { &*(x.as_ptr() as *const [i32; 16]) };
    __add16(x, y);
}

#[inline(always)]
pub fn __sub4(x: &mut [i32; 4], y: &[i32; 4]) {
    x[0] = x[0].wrapping_sub(y[0]);
    x[1] = x[1].wrapping_sub(y[1]);
    x[2] = x[2].wrapping_sub(y[2]);
    x[3] = x[3].wrapping_sub(y[3]);
}

#[inline(always)]
pub fn __sub4_slice(x: &mut [i32], y: &[i32]) {
    debug_assert_eq!(x.len(), 4);
    debug_assert_eq!(y.len(), 4);
    let x: &mut [i32; 4] = unsafe { &mut *(x.as_mut_ptr() as *mut [i32; 4]) };
    let y: &[i32; 4] = unsafe { &*(x.as_ptr() as *const [i32; 4]) };
    __sub4(x, y);
}

#[inline(always)]
pub fn __sub8(x: &mut [i32; 8], y: &[i32; 8]) {
    x[0] = x[0].wrapping_sub(y[0]);
    x[1] = x[1].wrapping_sub(y[1]);
    x[2] = x[2].wrapping_sub(y[2]);
    x[3] = x[3].wrapping_sub(y[3]);
    x[4] = x[4].wrapping_sub(y[4]);
    x[5] = x[5].wrapping_sub(y[5]);
    x[6] = x[6].wrapping_sub(y[6]);
    x[7] = x[7].wrapping_sub(y[7]);
}

#[inline(always)]
pub fn __sub8_slice(x: &mut [i32], y: &[i32]) {
    debug_assert_eq!(x.len(), 8);
    debug_assert_eq!(y.len(), 8);
    let x: &mut [i32; 8] = unsafe { &mut *(x.as_mut_ptr() as *mut [i32; 8]) };
    let y: &[i32; 8] = unsafe { &*(x.as_ptr() as *const [i32; 8]) };
    __sub8(x, y);
}

#[inline(always)]
pub fn __sub16(x: &mut [i32; 16], y: &[i32; 16]) {
    x[0] = x[0].wrapping_sub(y[0]);
    x[1] = x[1].wrapping_sub(y[1]);
    x[2] = x[2].wrapping_sub(y[2]);
    x[3] = x[3].wrapping_sub(y[3]);
    x[4] = x[4].wrapping_sub(y[4]);
    x[5] = x[5].wrapping_sub(y[5]);
    x[6] = x[6].wrapping_sub(y[6]);
    x[7] = x[7].wrapping_sub(y[7]);
    x[8] = x[8].wrapping_sub(y[8]);
    x[9] = x[9].wrapping_sub(y[9]);
    x[10] = x[10].wrapping_sub(y[10]);
    x[11] = x[11].wrapping_sub(y[11]);
    x[12] = x[12].wrapping_sub(y[12]);
    x[13] = x[13].wrapping_sub(y[13]);
    x[14] = x[14].wrapping_sub(y[14]);
    x[15] = x[15].wrapping_sub(y[15]);
}

#[inline(always)]
pub fn __sub16_slice(x: &mut [i32], y: &[i32]) {
    debug_assert_eq!(x.len(), 16);
    debug_assert_eq!(y.len(), 16);
    let x: &mut [i32; 16] = unsafe { &mut *(x.as_mut_ptr() as *mut [i32; 16]) };
    let y: &[i32; 16] = unsafe { &*(x.as_ptr() as *const [i32; 16]) };
    __sub16(x, y);
}

#[inline(always)]
pub fn __mul4(x: &mut [i32; 4], y: &[i32; 4]) {
    x[0] = x[0].wrapping_mul(y[0]);
    x[1] = x[1].wrapping_mul(y[1]);
    x[2] = x[2].wrapping_mul(y[2]);
    x[3] = x[3].wrapping_mul(y[3]);
}

#[inline(always)]
pub fn __mul4_slice(x: &mut [i32], y: &[i32]) {
    debug_assert_eq!(x.len(), 4);
    debug_assert_eq!(y.len(), 4);
    let x: &mut [i32; 4] = unsafe { &mut *(x.as_mut_ptr() as *mut [i32; 4]) };
    let y: &[i32; 4] = unsafe { &*(x.as_ptr() as *const [i32; 4]) };
    __mul4(x, y);
}

#[inline(always)]
pub fn __mul8(x: &mut [i32; 8], y: &[i32; 8]) {
    x[0] = x[0].wrapping_mul(y[0]);
    x[1] = x[1].wrapping_mul(y[1]);
    x[2] = x[2].wrapping_mul(y[2]);
    x[3] = x[3].wrapping_mul(y[3]);
    x[4] = x[4].wrapping_mul(y[4]);
    x[5] = x[5].wrapping_mul(y[5]);
    x[6] = x[6].wrapping_mul(y[6]);
    x[7] = x[7].wrapping_mul(y[7]);
}

#[inline(always)]
pub fn __mul8_slice(x: &mut [i32], y: &[i32]) {
    debug_assert_eq!(x.len(), 8);
    debug_assert_eq!(y.len(), 8);
    let x: &mut [i32; 8] = unsafe { &mut *(x.as_mut_ptr() as *mut [i32; 8]) };
    let y: &[i32; 8] = unsafe { &*(x.as_ptr() as *const [i32; 8]) };
    __mul8(x, y);
}

#[inline(always)]
pub fn __mul16(x: &mut [i32; 16], y: &[i32; 16]) {
    x[0] = x[0].wrapping_mul(y[0]);
    x[1] = x[1].wrapping_mul(y[1]);
    x[2] = x[2].wrapping_mul(y[2]);
    x[3] = x[3].wrapping_mul(y[3]);
    x[4] = x[4].wrapping_mul(y[4]);
    x[5] = x[5].wrapping_mul(y[5]);
    x[6] = x[6].wrapping_mul(y[6]);
    x[7] = x[7].wrapping_mul(y[7]);
    x[8] = x[8].wrapping_mul(y[8]);
    x[9] = x[9].wrapping_mul(y[9]);
    x[10] = x[10].wrapping_mul(y[10]);
    x[11] = x[11].wrapping_mul(y[11]);
    x[12] = x[12].wrapping_mul(y[12]);
    x[13] = x[13].wrapping_mul(y[13]);
    x[14] = x[14].wrapping_mul(y[14]);
    x[15] = x[15].wrapping_mul(y[15]);
}

#[inline(always)]
pub fn __mul16_slice(x: &mut [i32], y: &[i32]) {
    debug_assert_eq!(x.len(), 16);
    debug_assert_eq!(y.len(), 16);
    let x: &mut [i32; 16] = unsafe { &mut *(x.as_mut_ptr() as *mut [i32; 16]) };
    let y: &[i32; 16] = unsafe { &*(x.as_ptr() as *const [i32; 16]) };
    __mul16(x, y);
}

#[inline(always)]
pub fn __div4(x: &mut [i32; 4], y: &[i32; 4]) {
    x[0] = x[0].wrapping_div(y[0]);
    x[1] = x[1].wrapping_div(y[1]);
    x[2] = x[2].wrapping_div(y[2]);
    x[3] = x[3].wrapping_div(y[3]);
}

#[inline(always)]
pub fn __div4_slice(x: &mut [i32], y: &[i32]) {
    debug_assert_eq!(x.len(), 4);
    debug_assert_eq!(y.len(), 4);
    let x: &mut [i32; 4] = unsafe { &mut *(x.as_mut_ptr() as *mut [i32; 4]) };
    let y: &[i32; 4] = unsafe { &*(x.as_ptr() as *const [i32; 4]) };
    __div4(x, y);
}

#[inline(always)]
pub fn __div8(x: &mut [i32; 8], y: &[i32; 8]) {
    x[0] = x[0].wrapping_div(y[0]);
    x[1] = x[1].wrapping_div(y[1]);
    x[2] = x[2].wrapping_div(y[2]);
    x[3] = x[3].wrapping_div(y[3]);
    x[4] = x[4].wrapping_div(y[4]);
    x[5] = x[5].wrapping_div(y[5]);
    x[6] = x[6].wrapping_div(y[6]);
    x[7] = x[7].wrapping_div(y[7]);
}

#[inline(always)]
pub fn __div8_slice(x: &mut [i32], y: &[i32]) {
    debug_assert_eq!(x.len(), 8);
    debug_assert_eq!(y.len(), 8);
    let x: &mut [i32; 8] = unsafe { &mut *(x.as_mut_ptr() as *mut [i32; 8]) };
    let y: &[i32; 8] = unsafe { &*(x.as_ptr() as *const [i32; 8]) };
    __div8(x, y);
}

#[inline(always)]
pub fn __div16(x: &mut [i32; 16], y: &[i32; 16]) {
    x[0] = x[0].wrapping_div(y[0]);
    x[1] = x[1].wrapping_div(y[1]);
    x[2] = x[2].wrapping_div(y[2]);
    x[3] = x[3].wrapping_div(y[3]);
    x[4] = x[4].wrapping_div(y[4]);
    x[5] = x[5].wrapping_div(y[5]);
    x[6] = x[6].wrapping_div(y[6]);
    x[7] = x[7].wrapping_div(y[7]);
    x[8] = x[8].wrapping_div(y[8]);
    x[9] = x[9].wrapping_div(y[9]);
    x[10] = x[10].wrapping_div(y[10]);
    x[11] = x[11].wrapping_div(y[11]);
    x[12] = x[12].wrapping_div(y[12]);
    x[13] = x[13].wrapping_div(y[13]);
    x[14] = x[14].wrapping_div(y[14]);
    x[15] = x[15].wrapping_div(y[15]);
}

#[inline(always)]
pub fn __div16_slice(x: &mut [i32], y: &[i32]) {
    debug_assert_eq!(x.len(), 16);
    debug_assert_eq!(y.len(), 16);
    let x: &mut [i32; 16] = unsafe { &mut *(x.as_mut_ptr() as *mut [i32; 16]) };
    let y: &[i32; 16] = unsafe { &*(x.as_ptr() as *const [i32; 16]) };
    __div16(x, y);
}

#[inline(always)]
pub fn __mod4(x: &mut [i32; 4], y: &[i32; 4]) {
    x[0] %= y[0];
    x[1] %= y[1];
    x[2] %= y[2];
    x[3] %= y[3];
}

#[inline(always)]
pub fn __mod4_slice(x: &mut [i32], y: &[i32]) {
    debug_assert_eq!(x.len(), 4);
    debug_assert_eq!(y.len(), 4);
    let x: &mut [i32; 4] = unsafe { &mut *(x.as_mut_ptr() as *mut [i32; 4]) };
    let y: &[i32; 4] = unsafe { &*(x.as_ptr() as *const [i32; 4]) };
    __mod4(x, y);
}

#[inline(always)]
pub fn __mod8(x: &mut [i32; 8], y: &[i32; 8]) {
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
pub fn __mod8_slice(x: &mut [i32], y: &[i32]) {
    debug_assert_eq!(x.len(), 8);
    debug_assert_eq!(y.len(), 8);
    let x: &mut [i32; 8] = unsafe { &mut *(x.as_mut_ptr() as *mut [i32; 8]) };
    let y: &[i32; 8] = unsafe { &*(x.as_ptr() as *const [i32; 8]) };
    __mod8(x, y);
}

#[inline(always)]
pub fn __mod16(x: &mut [i32; 16], y: &[i32; 16]) {
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
pub fn __mod16_slice(x: &mut [i32], y: &[i32]) {
    debug_assert_eq!(x.len(), 16);
    debug_assert_eq!(y.len(), 16);
    let x: &mut [i32; 16] = unsafe { &mut *(x.as_mut_ptr() as *mut [i32; 16]) };
    let y: &[i32; 16] = unsafe { &*(x.as_ptr() as *const [i32; 16]) };
    __mod16(x, y);
}

#[inline(always)]
pub fn __and4(x: &mut [i32; 4], y: &[i32; 4]) {
    x[0] &= y[0];
    x[1] &= y[1];
    x[2] &= y[2];
    x[3] &= y[3];
}

#[inline(always)]
pub fn __and4_slice(x: &mut [i32], y: &[i32]) {
    debug_assert_eq!(x.len(), 4);
    debug_assert_eq!(y.len(), 4);
    let x: &mut [i32; 4] = unsafe { &mut *(x.as_mut_ptr() as *mut [i32; 4]) };
    let y: &[i32; 4] = unsafe { &*(x.as_ptr() as *const [i32; 4]) };
    __and4(x, y);
}

#[inline(always)]
pub fn __and8(x: &mut [i32; 8], y: &[i32; 8]) {
    x[0] &= y[0];
    x[1] &= y[1];
    x[2] &= y[2];
    x[3] &= y[3];
    x[4] &= y[4];
    x[5] &= y[5];
    x[6] &= y[6];
    x[7] &= y[7];
}

#[inline(always)]
pub fn __and8_slice(x: &mut [i32], y: &[i32]) {
    debug_assert_eq!(x.len(), 8);
    debug_assert_eq!(y.len(), 8);
    let x: &mut [i32; 8] = unsafe { &mut *(x.as_mut_ptr() as *mut [i32; 8]) };
    let y: &[i32; 8] = unsafe { &*(x.as_ptr() as *const [i32; 8]) };
    __and8(x, y);
}

#[inline(always)]
pub fn __and16(x: &mut [i32; 16], y: &[i32; 16]) {
    x[0] &= y[0];
    x[1] &= y[1];
    x[2] &= y[2];
    x[3] &= y[3];
    x[4] &= y[4];
    x[5] &= y[5];
    x[6] &= y[6];
    x[7] &= y[7];
    x[8] &= y[8];
    x[9] &= y[9];
    x[10] &= y[10];
    x[11] &= y[11];
    x[12] &= y[12];
    x[13] &= y[13];
    x[14] &= y[14];
    x[15] &= y[15];
}

#[inline(always)]
pub fn __and16_slice(x: &mut [i32], y: &[i32]) {
    debug_assert_eq!(x.len(), 16);
    debug_assert_eq!(y.len(), 16);
    let x: &mut [i32; 16] = unsafe { &mut *(x.as_mut_ptr() as *mut [i32; 16]) };
    let y: &[i32; 16] = unsafe { &*(x.as_ptr() as *const [i32; 16]) };
    __and16(x, y);
}

#[inline(always)]
pub fn __or4(x: &mut [i32; 4], y: &[i32; 4]) {
    x[0] |= y[0];
    x[1] |= y[1];
    x[2] |= y[2];
    x[3] |= y[3];
}

#[inline(always)]
pub fn __or4_slice(x: &mut [i32], y: &[i32]) {
    debug_assert_eq!(x.len(), 4);
    debug_assert_eq!(y.len(), 4);
    let x: &mut [i32; 4] = unsafe { &mut *(x.as_mut_ptr() as *mut [i32; 4]) };
    let y: &[i32; 4] = unsafe { &*(x.as_ptr() as *const [i32; 4]) };
    __or4(x, y);
}

#[inline(always)]
pub fn __or8(x: &mut [i32; 8], y: &[i32; 8]) {
    x[0] |= y[0];
    x[1] |= y[1];
    x[2] |= y[2];
    x[3] |= y[3];
    x[4] |= y[4];
    x[5] |= y[5];
    x[6] |= y[6];
    x[7] |= y[7];
}

#[inline(always)]
pub fn __or8_slice(x: &mut [i32], y: &[i32]) {
    debug_assert_eq!(x.len(), 8);
    debug_assert_eq!(y.len(), 8);
    let x: &mut [i32; 8] = unsafe { &mut *(x.as_mut_ptr() as *mut [i32; 8]) };
    let y: &[i32; 8] = unsafe { &*(x.as_ptr() as *const [i32; 8]) };
    __or8(x, y);
}

#[inline(always)]
pub fn __or16(x: &mut [i32; 16], y: &[i32; 16]) {
    x[0] |= y[0];
    x[1] |= y[1];
    x[2] |= y[2];
    x[3] |= y[3];
    x[4] |= y[4];
    x[5] |= y[5];
    x[6] |= y[6];
    x[7] |= y[7];
    x[8] |= y[8];
    x[9] |= y[9];
    x[10] |= y[10];
    x[11] |= y[11];
    x[12] |= y[12];
    x[13] |= y[13];
    x[14] |= y[14];
    x[15] |= y[15];
}

#[inline(always)]
pub fn __or16_slice(x: &mut [i32], y: &[i32]) {
    debug_assert_eq!(x.len(), 16);
    debug_assert_eq!(y.len(), 16);
    let x: &mut [i32; 16] = unsafe { &mut *(x.as_mut_ptr() as *mut [i32; 16]) };
    let y: &[i32; 16] = unsafe { &*(x.as_ptr() as *const [i32; 16]) };
    __or16(x, y);
}

#[inline(always)]
pub fn __xor4(x: &mut [i32; 4], y: &[i32; 4]) {
    x[0] ^= y[0];
    x[1] ^= y[1];
    x[2] ^= y[2];
    x[3] ^= y[3];
}

#[inline(always)]
pub fn __xor4_slice(x: &mut [i32], y: &[i32]) {
    debug_assert_eq!(x.len(), 4);
    debug_assert_eq!(y.len(), 4);
    let x: &mut [i32; 4] = unsafe { &mut *(x.as_mut_ptr() as *mut [i32; 4]) };
    let y: &[i32; 4] = unsafe { &*(x.as_ptr() as *const [i32; 4]) };
    __xor4(x, y);
}

#[inline(always)]
pub fn __xor8(x: &mut [i32; 8], y: &[i32; 8]) {
    x[0] ^= y[0];
    x[1] ^= y[1];
    x[2] ^= y[2];
    x[3] ^= y[3];
    x[4] ^= y[4];
    x[5] ^= y[5];
    x[6] ^= y[6];
    x[7] ^= y[7];
}

#[inline(always)]
pub fn __xor8_slice(x: &mut [i32], y: &[i32]) {
    debug_assert_eq!(x.len(), 8);
    debug_assert_eq!(y.len(), 8);
    let x: &mut [i32; 8] = unsafe { &mut *(x.as_mut_ptr() as *mut [i32; 8]) };
    let y: &[i32; 8] = unsafe { &*(x.as_ptr() as *const [i32; 8]) };
    __xor8(x, y);
}

#[inline(always)]
pub fn __xor16(x: &mut [i32; 16], y: &[i32; 16]) {
    x[0] ^= y[0];
    x[1] ^= y[1];
    x[2] ^= y[2];
    x[3] ^= y[3];
    x[4] ^= y[4];
    x[5] ^= y[5];
    x[6] ^= y[6];
    x[7] ^= y[7];
    x[8] ^= y[8];
    x[9] ^= y[9];
    x[10] ^= y[10];
    x[11] ^= y[11];
    x[12] ^= y[12];
    x[13] ^= y[13];
    x[14] ^= y[14];
    x[15] ^= y[15];
}

#[inline(always)]
pub fn __xor16_slice(x: &mut [i32], y: &[i32]) {
    debug_assert_eq!(x.len(), 16);
    debug_assert_eq!(y.len(), 16);
    let x: &mut [i32; 16] = unsafe { &mut *(x.as_mut_ptr() as *mut [i32; 16]) };
    let y: &[i32; 16] = unsafe { &*(x.as_ptr() as *const [i32; 16]) };
    __xor16(x, y);
}

#[inline(always)]
pub fn __sal4(x: &mut [i32; 4], y: &[i32; 4]) {
    x[0] = x[0].wrapping_shl(y[0] as _);
    x[1] = x[1].wrapping_shl(y[1] as _);
    x[2] = x[2].wrapping_shl(y[2] as _);
    x[3] = x[3].wrapping_shl(y[3] as _);
}

#[inline(always)]
pub fn __sal4_slice(x: &mut [i32], y: &[i32]) {
    debug_assert_eq!(x.len(), 4);
    debug_assert_eq!(y.len(), 4);
    let x: &mut [i32; 4] = unsafe { &mut *(x.as_mut_ptr() as *mut [i32; 4]) };
    let y: &[i32; 4] = unsafe { &*(x.as_ptr() as *const [i32; 4]) };
    __sal4(x, y);
}

#[inline(always)]
pub fn __sal8(x: &mut [i32; 8], y: &[i32; 8]) {
    x[0] = x[0].wrapping_shl(y[0] as _);
    x[1] = x[1].wrapping_shl(y[1] as _);
    x[2] = x[2].wrapping_shl(y[2] as _);
    x[3] = x[3].wrapping_shl(y[3] as _);
    x[4] = x[4].wrapping_shl(y[4] as _);
    x[5] = x[5].wrapping_shl(y[5] as _);
    x[6] = x[6].wrapping_shl(y[6] as _);
    x[7] = x[7].wrapping_shl(y[7] as _);
}

#[inline(always)]
pub fn __sal8_slice(x: &mut [i32], y: &[i32]) {
    debug_assert_eq!(x.len(), 8);
    debug_assert_eq!(y.len(), 8);
    let x: &mut [i32; 8] = unsafe { &mut *(x.as_mut_ptr() as *mut [i32; 8]) };
    let y: &[i32; 8] = unsafe { &*(x.as_ptr() as *const [i32; 8]) };
    __sal8(x, y);
}

#[inline(always)]
pub fn __sal16(x: &mut [i32; 16], y: &[i32; 16]) {
    x[0] = x[0].wrapping_shl(y[0] as _);
    x[1] = x[1].wrapping_shl(y[1] as _);
    x[2] = x[2].wrapping_shl(y[2] as _);
    x[3] = x[3].wrapping_shl(y[3] as _);
    x[4] = x[4].wrapping_shl(y[4] as _);
    x[5] = x[5].wrapping_shl(y[5] as _);
    x[6] = x[6].wrapping_shl(y[6] as _);
    x[7] = x[7].wrapping_shl(y[7] as _);
    x[8] = x[8].wrapping_shl(y[8] as _);
    x[9] = x[9].wrapping_shl(y[9] as _);
    x[10] = x[10].wrapping_shl(y[10] as _);
    x[11] = x[11].wrapping_shl(y[11] as _);
    x[12] = x[12].wrapping_shl(y[12] as _);
    x[13] = x[13].wrapping_shl(y[13] as _);
    x[14] = x[14].wrapping_shl(y[14] as _);
    x[15] = x[15].wrapping_shl(y[15] as _);
}

#[inline(always)]
pub fn __sal16_slice(x: &mut [i32], y: &[i32]) {
    debug_assert_eq!(x.len(), 16);
    debug_assert_eq!(y.len(), 16);
    let x: &mut [i32; 16] = unsafe { &mut *(x.as_mut_ptr() as *mut [i32; 16]) };
    let y: &[i32; 16] = unsafe { &*(x.as_ptr() as *const [i32; 16]) };
    __sal16(x, y);
}

#[inline(always)]
pub fn __sar4(x: &mut [i32; 4], y: &[i32; 4]) {
    x[0] = x[0].wrapping_shr(y[0] as _);
    x[1] = x[1].wrapping_shr(y[1] as _);
    x[2] = x[2].wrapping_shr(y[2] as _);
    x[3] = x[3].wrapping_shr(y[3] as _);
}

#[inline(always)]
pub fn __sar4_slice(x: &mut [i32], y: &[i32]) {
    debug_assert_eq!(x.len(), 4);
    debug_assert_eq!(y.len(), 4);
    let x: &mut [i32; 4] = unsafe { &mut *(x.as_mut_ptr() as *mut [i32; 4]) };
    let y: &[i32; 4] = unsafe { &*(x.as_ptr() as *const [i32; 4]) };
    __sar4(x, y);
}

#[inline(always)]
pub fn __sar8(x: &mut [i32; 8], y: &[i32; 8]) {
    x[0] = x[0].wrapping_shr(y[0] as _);
    x[1] = x[1].wrapping_shr(y[1] as _);
    x[2] = x[2].wrapping_shr(y[2] as _);
    x[3] = x[3].wrapping_shr(y[3] as _);
    x[4] = x[4].wrapping_shr(y[4] as _);
    x[5] = x[5].wrapping_shr(y[5] as _);
    x[6] = x[6].wrapping_shr(y[6] as _);
    x[7] = x[7].wrapping_shr(y[7] as _);
}

#[inline(always)]
pub fn __sar8_slice(x: &mut [i32], y: &[i32]) {
    debug_assert_eq!(x.len(), 8);
    debug_assert_eq!(y.len(), 8);
    let x: &mut [i32; 8] = unsafe { &mut *(x.as_mut_ptr() as *mut [i32; 8]) };
    let y: &[i32; 8] = unsafe { &*(x.as_ptr() as *const [i32; 8]) };
    __sar8(x, y);
}

#[inline(always)]
pub fn __sar16(x: &mut [i32; 16], y: &[i32; 16]) {
    x[0] = x[0].wrapping_shr(y[0] as _);
    x[1] = x[1].wrapping_shr(y[1] as _);
    x[2] = x[2].wrapping_shr(y[2] as _);
    x[3] = x[3].wrapping_shr(y[3] as _);
    x[4] = x[4].wrapping_shr(y[4] as _);
    x[5] = x[5].wrapping_shr(y[5] as _);
    x[6] = x[6].wrapping_shr(y[6] as _);
    x[7] = x[7].wrapping_shr(y[7] as _);
    x[8] = x[8].wrapping_shr(y[8] as _);
    x[9] = x[9].wrapping_shr(y[9] as _);
    x[10] = x[10].wrapping_shr(y[10] as _);
    x[11] = x[11].wrapping_shr(y[11] as _);
    x[12] = x[12].wrapping_shr(y[12] as _);
    x[13] = x[13].wrapping_shr(y[13] as _);
    x[14] = x[14].wrapping_shr(y[14] as _);
    x[15] = x[15].wrapping_shr(y[15] as _);
}

#[inline(always)]
pub fn __sar16_slice(x: &mut [i32], y: &[i32]) {
    debug_assert_eq!(x.len(), 16);
    debug_assert_eq!(y.len(), 16);
    let x: &mut [i32; 16] = unsafe { &mut *(x.as_mut_ptr() as *mut [i32; 16]) };
    let y: &[i32; 16] = unsafe { &*(x.as_ptr() as *const [i32; 16]) };
    __sar16(x, y);
}

#[inline(always)]
pub fn __rol4(x: &mut [i32; 4], y: &[i32; 4]) {
    x[0] = x[0].rotate_left(y[0] as _);
    x[1] = x[1].rotate_left(y[1] as _);
    x[2] = x[2].rotate_left(y[2] as _);
    x[3] = x[3].rotate_left(y[3] as _);
}

#[inline(always)]
pub fn __rol4_slice(x: &mut [i32], y: &[i32]) {
    debug_assert_eq!(x.len(), 4);
    debug_assert_eq!(y.len(), 4);
    let x: &mut [i32; 4] = unsafe { &mut *(x.as_mut_ptr() as *mut [i32; 4]) };
    let y: &[i32; 4] = unsafe { &*(x.as_ptr() as *const [i32; 4]) };
    __rol4(x, y);
}

#[inline(always)]
pub fn __rol8(x: &mut [i32; 8], y: &[i32; 8]) {
    x[0] = x[0].rotate_left(y[0] as _);
    x[1] = x[1].rotate_left(y[1] as _);
    x[2] = x[2].rotate_left(y[2] as _);
    x[3] = x[3].rotate_left(y[3] as _);
    x[4] = x[4].rotate_left(y[4] as _);
    x[5] = x[5].rotate_left(y[5] as _);
    x[6] = x[6].rotate_left(y[6] as _);
    x[7] = x[7].rotate_left(y[7] as _);
}

#[inline(always)]
pub fn __rol8_slice(x: &mut [i32], y: &[i32]) {
    debug_assert_eq!(x.len(), 8);
    debug_assert_eq!(y.len(), 8);
    let x: &mut [i32; 8] = unsafe { &mut *(x.as_mut_ptr() as *mut [i32; 8]) };
    let y: &[i32; 8] = unsafe { &*(x.as_ptr() as *const [i32; 8]) };
    __rol8(x, y);
}

#[inline(always)]
pub fn __rol16(x: &mut [i32; 16], y: &[i32; 16]) {
    x[0] = x[0].rotate_left(y[0] as _);
    x[1] = x[1].rotate_left(y[1] as _);
    x[2] = x[2].rotate_left(y[2] as _);
    x[3] = x[3].rotate_left(y[3] as _);
    x[4] = x[4].rotate_left(y[4] as _);
    x[5] = x[5].rotate_left(y[5] as _);
    x[6] = x[6].rotate_left(y[6] as _);
    x[7] = x[7].rotate_left(y[7] as _);
    x[8] = x[8].rotate_left(y[8] as _);
    x[9] = x[9].rotate_left(y[9] as _);
    x[10] = x[10].rotate_left(y[10] as _);
    x[11] = x[11].rotate_left(y[11] as _);
    x[12] = x[12].rotate_left(y[12] as _);
    x[13] = x[13].rotate_left(y[13] as _);
    x[14] = x[14].rotate_left(y[14] as _);
    x[15] = x[15].rotate_left(y[15] as _);
}

#[inline(always)]
pub fn __rol16_slice(x: &mut [i32], y: &[i32]) {
    debug_assert_eq!(x.len(), 16);
    debug_assert_eq!(y.len(), 16);
    let x: &mut [i32; 16] = unsafe { &mut *(x.as_mut_ptr() as *mut [i32; 16]) };
    let y: &[i32; 16] = unsafe { &*(x.as_ptr() as *const [i32; 16]) };
    __rol16(x, y);
}

#[inline(always)]
pub fn __ror4(x: &mut [i32; 4], y: &[i32; 4]) {
    x[0] = x[0].rotate_right(y[0] as _);
    x[1] = x[1].rotate_right(y[1] as _);
    x[2] = x[2].rotate_right(y[2] as _);
    x[3] = x[3].rotate_right(y[3] as _);
}

#[inline(always)]
pub fn __ror4_slice(x: &mut [i32], y: &[i32]) {
    debug_assert_eq!(x.len(), 4);
    debug_assert_eq!(y.len(), 4);
    let x: &mut [i32; 4] = unsafe { &mut *(x.as_mut_ptr() as *mut [i32; 4]) };
    let y: &[i32; 4] = unsafe { &*(x.as_ptr() as *const [i32; 4]) };
    __ror4(x, y);
}

#[inline(always)]
pub fn __ror8(x: &mut [i32; 8], y: &[i32; 8]) {
    x[0] = x[0].rotate_right(y[0] as _);
    x[1] = x[1].rotate_right(y[1] as _);
    x[2] = x[2].rotate_right(y[2] as _);
    x[3] = x[3].rotate_right(y[3] as _);
    x[4] = x[4].rotate_right(y[4] as _);
    x[5] = x[5].rotate_right(y[5] as _);
    x[6] = x[6].rotate_right(y[6] as _);
    x[7] = x[7].rotate_right(y[7] as _);
}

#[inline(always)]
pub fn __ror8_slice(x: &mut [i32], y: &[i32]) {
    debug_assert_eq!(x.len(), 8);
    debug_assert_eq!(y.len(), 8);
    let x: &mut [i32; 8] = unsafe { &mut *(x.as_mut_ptr() as *mut [i32; 8]) };
    let y: &[i32; 8] = unsafe { &*(x.as_ptr() as *const [i32; 8]) };
    __ror8(x, y);
}

#[inline(always)]
pub fn __ror16(x: &mut [i32; 16], y: &[i32; 16]) {
    x[0] = x[0].rotate_right(y[0] as _);
    x[1] = x[1].rotate_right(y[1] as _);
    x[2] = x[2].rotate_right(y[2] as _);
    x[3] = x[3].rotate_right(y[3] as _);
    x[4] = x[4].rotate_right(y[4] as _);
    x[5] = x[5].rotate_right(y[5] as _);
    x[6] = x[6].rotate_right(y[6] as _);
    x[7] = x[7].rotate_right(y[7] as _);
    x[8] = x[8].rotate_right(y[8] as _);
    x[9] = x[9].rotate_right(y[9] as _);
    x[10] = x[10].rotate_right(y[10] as _);
    x[11] = x[11].rotate_right(y[11] as _);
    x[12] = x[12].rotate_right(y[12] as _);
    x[13] = x[13].rotate_right(y[13] as _);
    x[14] = x[14].rotate_right(y[14] as _);
    x[15] = x[15].rotate_right(y[15] as _);
}

#[inline(always)]
pub fn __ror16_slice(x: &mut [i32], y: &[i32]) {
    debug_assert_eq!(x.len(), 16);
    debug_assert_eq!(y.len(), 16);
    let x: &mut [i32; 16] = unsafe { &mut *(x.as_mut_ptr() as *mut [i32; 16]) };
    let y: &[i32; 16] = unsafe { &*(x.as_ptr() as *const [i32; 16]) };
    __ror16(x, y);
}
