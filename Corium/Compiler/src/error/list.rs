use crate::error::Error;
use std::default;
use std::fmt;

pub struct ErrorList(pub Vec<Error>);

impl ErrorList {
    pub fn new() -> Self {
        Self(Vec::new())
    }

    pub fn with_capacity(cap: usize) -> Self {
        Self(Vec::with_capacity(cap))
    }
}

impl From<Vec<Error>> for ErrorList {
    fn from(x: Vec<Error>) -> Self {
        Self(x)
    }
}

impl From<Error> for ErrorList {
    fn from(x: Error) -> Self {
        Self(vec![x])
    }
}

impl fmt::Display for ErrorList {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        for error in &self.0 {
            writeln!(f, "{}", error)?
        }
        Ok(())
    }
}

impl default::Default for ErrorList {
    fn default() -> Self {
        Self::new()
    }
}
