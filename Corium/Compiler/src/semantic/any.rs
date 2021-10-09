use crate::ast::*;

pub enum AnyVariable<'ast> {
    Mutable(&'ast MutableVariable<'ast>),
    Immutable(&'ast ImmutableVariable<'ast>),
}

pub enum AnyFunction<'ast> {
    Local(&'ast Function<'ast>),
    Native(&'ast NativeFunction<'ast>),
}
