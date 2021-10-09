use super::any::*;
use super::symtable::SymbolTable;
use crate::ast::*;
use std::collections::HashMap;

pub struct GlobalSymbolTable<'ast> {
    pub functions: HashMap<Identifier<'ast>, AnyFunction<'ast>>,
    pub variables: HashMap<Identifier<'ast>, AnyVariable<'ast>>,
}

impl<'a> SymbolTable for GlobalSymbolTable<'a> {
    fn new() -> Self {
        Self {
            functions: HashMap::new(),
            variables: HashMap::new(),
        }
    }

    fn with_capacity(capacity: usize) -> Self {
        Self {
            functions: HashMap::with_capacity(capacity),
            variables: HashMap::with_capacity(capacity),
        }
    }

    fn clear(&mut self) {
        self.functions.clear();
        self.variables.clear();
    }
}
