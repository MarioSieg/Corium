use std::ops::{Index, IndexMut};

pub trait VectorScalar32: Sized + Copy + Clone + Default {}
impl VectorScalar32 for i32 {}
impl VectorScalar32 for f32 {}

/// Base for all aligned arrays.
pub trait AlignedArray<T>: Sized + Default + Clone + Index<usize> + IndexMut<usize>
where
    T: VectorScalar32,
{
    /// The length of the array.
    const LENGTH: usize;

    /// The alignment of the array in bytes.
    const ALIGNMENT: usize;

    /// The size of the array in bytes.
    const SIZE: usize;

    /// Returns an immutable pointer to the array data.
    fn as_ptr(&self) -> *const T;

    /// Returns a mutable pointer to the array data.
    fn as_mut_ptr(&mut self) -> *mut T;
}

/// 16-Bytes 128-Bit aligned array with 4 scalars.
#[repr(align(16))]
#[derive(Default, Clone)]
pub struct AlignedTo16Array4<T>(pub [T; 4])
where
    T: VectorScalar32;

impl<T> AlignedArray<T> for AlignedTo16Array4<T>
where
    T: VectorScalar32,
{
    /// The length of the array.
    const LENGTH: usize = 4;

    /// The alignment of the array in bytes.
    const ALIGNMENT: usize = 16;

    /// The size of the array in bytes.
    const SIZE: usize = std::mem::size_of::<[T; 4]>();

    /// Returns an immutable pointer to the array data.
    #[inline]
    fn as_ptr(&self) -> *const T {
        self.0.as_ptr()
    }

    /// Returns a mutable pointer to the array data.
    #[inline]
    fn as_mut_ptr(&mut self) -> *mut T {
        self.0.as_mut_ptr()
    }
}

impl<T> Index<usize> for AlignedTo16Array4<T>
where
    T: VectorScalar32,
{
    type Output = T;
    fn index(&self, idx: usize) -> &Self::Output {
        &self.0[idx]
    }
}

impl<T> IndexMut<usize> for AlignedTo16Array4<T>
where
    T: VectorScalar32,
{
    fn index_mut(&mut self, idx: usize) -> &mut Self::Output {
        &mut self.0[idx]
    }
}

/// 32-Bytes 256-Bit aligned array with 8 scalars.
#[repr(align(32))]
#[derive(Default, Clone)]
pub struct AlignedTo32Array8<T>(pub [T; 8])
where
    T: VectorScalar32;

impl<T> AlignedArray<T> for AlignedTo32Array8<T>
where
    T: VectorScalar32,
{
    /// The length of the array.
    const LENGTH: usize = 8;

    /// The alignment of the array in bytes.
    const ALIGNMENT: usize = 32;

    /// The size of the array in bytes.
    const SIZE: usize = std::mem::size_of::<[T; 8]>();

    /// Returns an immutable pointer to the array data.
    #[inline]
    fn as_ptr(&self) -> *const T {
        self.0.as_ptr()
    }

    /// Returns a mutable pointer to the array data.
    #[inline]
    fn as_mut_ptr(&mut self) -> *mut T {
        self.0.as_mut_ptr()
    }
}

impl<T> Index<usize> for AlignedTo32Array8<T>
where
    T: VectorScalar32,
{
    type Output = T;
    fn index(&self, idx: usize) -> &Self::Output {
        &self.0[idx]
    }
}

impl<T> IndexMut<usize> for AlignedTo32Array8<T>
where
    T: VectorScalar32,
{
    fn index_mut(&mut self, idx: usize) -> &mut Self::Output {
        &mut self.0[idx]
    }
}

/// 64-Bytes 512-Bit aligned array with 16 scalars.
#[repr(align(64))]
#[derive(Default, Clone)]
pub struct AlignedTo64Array16<T>(pub [T; 16])
where
    T: VectorScalar32;

impl<T> AlignedArray<T> for AlignedTo64Array16<T>
where
    T: VectorScalar32,
{
    /// The length of the array.
    const LENGTH: usize = 4;

    /// The alignment of the array in bytes.
    const ALIGNMENT: usize = 16;

    /// The size of the array in bytes.
    const SIZE: usize = std::mem::size_of::<[T; 4]>();

    /// Returns an immutable pointer to the array data.
    #[inline]
    fn as_ptr(&self) -> *const T {
        self.0.as_ptr()
    }

    /// Returns a mutable pointer to the array data.
    #[inline]
    fn as_mut_ptr(&mut self) -> *mut T {
        self.0.as_mut_ptr()
    }
}

impl<T> Index<usize> for AlignedTo64Array16<T>
where
    T: VectorScalar32,
{
    type Output = T;
    fn index(&self, idx: usize) -> &Self::Output {
        &self.0[idx]
    }
}

impl<T> IndexMut<usize> for AlignedTo64Array16<T>
where
    T: VectorScalar32,
{
    fn index_mut(&mut self, idx: usize) -> &mut Self::Output {
        &mut self.0[idx]
    }
}
