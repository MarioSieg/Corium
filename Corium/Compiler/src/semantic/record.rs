use crate::ast::*;

pub enum Record<'a> {
    MutableVariable(&'a MutableVariable<'a>),
    ImmutableVariable(&'a ImmutableVariable<'a>),
    Function(&'a Function<'a>),
    NativeFunction(&'a NativeFunction<'a>),
}

impl<'a> Record<'a> {
    pub fn descriptive_name(&self) -> &'static str {
        match self {
            Self::MutableVariable(_) => "mutable variable",
            Self::ImmutableVariable(_) => "immutable variable",
            Self::Function(_) => "function",
            Self::NativeFunction(_) => "native function",
        }
    }
}
