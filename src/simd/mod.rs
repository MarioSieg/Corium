pub mod aligned;
pub mod f32;
pub mod fallback;
pub mod flags;
pub mod i32;

#[cfg(all(feature = "simd", target_arch = "x86_64", target_feature = "sse4.1"))]
mod sse;

#[cfg(all(feature = "simd", target_arch = "x86_64", target_feature = "avx"))]
mod avx;

#[cfg(all(feature = "simd", target_arch = "x86_64", target_feature = "avx512f"))]
mod avx512;

#[cfg(all(feature = "simd", target_arch = "x86_64", target_feature = "fma"))]
mod fma;
