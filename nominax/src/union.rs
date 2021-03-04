#[derive(Copy, Clone, Eq, PartialEq)]
pub struct Union32(u32);

impl Union32 {
    #[inline(always)]
    pub fn u32(&self) -> u32 {
        self.0
    }

    #[inline(always)]
    pub fn set_u32(&mut self, x: u32) {
        self.0 = x
    }

    #[inline(always)]
    pub fn i32(&self) -> i32 {
        self.0 as _
    }

    #[inline(always)]
    pub fn set_i32(&mut self, x: i32) {
        self.0 = x as _
    }

    #[inline(always)]
    pub fn f32(&self) -> f32 {
        f32::from_bits(self.0)
    }

    #[inline(always)]
    pub fn set_f32(&mut self, x: f32) {
        self.0 = x.to_bits()
    }
}
