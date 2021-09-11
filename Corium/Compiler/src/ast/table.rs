use crate::ast::*;
use std::collections::HashMap;

pub type FunctionTable<'t> = HashMap<QualifiedName<'t>, Function<'t>>;
