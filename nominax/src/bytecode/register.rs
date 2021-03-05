pub trait RegisterType: Copy + Clone + Eq + PartialEq {
    const GPR: bool;
    const SIZE: usize;
    const SIMD: bool;
    const LANE_SIZE: usize;
    const LANE_COUNT: usize;
    const I32: bool;
    const F32: bool;
}
