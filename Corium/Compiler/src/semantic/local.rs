use super::any::*;
use super::symtable::SymbolTable;
use crate::ast::*;
use std::collections::HashMap;

pub struct LocalSymbolTable<'ast> {
    pub variables: HashMap<Identifier<'ast>, AnyVariable<'ast>>,
}

impl<'a> SymbolTable for LocalSymbolTable<'a> {
    fn new() -> Self {
        Self {
            variables: HashMap::new(),
        }
    }

    fn with_capacity(capacity: usize) -> Self {
        Self {
            variables: HashMap::with_capacity(capacity),
        }
    }

    fn clear(&mut self) {
        self.variables.clear();
    }
}
