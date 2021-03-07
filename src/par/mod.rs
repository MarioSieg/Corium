pub mod prelude {
    #[cfg(feature = "multithreading")]
    pub use rayon::prelude::*;

    #[cfg(feature = "multithreading")]
    pub use rayon::iter::*;

    #[cfg(not(feature = "multithreading"))]
    pub use std::iter::*;
}

use prelude::*;

#[inline]
#[cfg(feature = "multithreading")]
pub fn iter<T>(t: T) -> <T as IntoParallelIterator>::Iter
where
    T: IntoParallelIterator + Sync,
{
    t.into_par_iter()
}

#[inline]
#[cfg(not(feature = "multithreading"))]
pub fn iter<T>(t: T) -> <T as IntoIterator>::IntoIter
where
    T: IntoIterator + Sync,
{
    t.into_iter()
}
