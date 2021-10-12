use super::record::Record;
use crate::ast::*;
use std::collections::HashMap;

pub struct SymbolTable<'a>(HashMap<Identifier<'a>, Record<'a>>);

impl<'a> SymbolTable<'a> {
    pub fn new() -> Self {
        Self(HashMap::new())
    }

    pub fn with_capacity(capacity: usize) -> Self {
        Self(HashMap::with_capacity(capacity))
    }

    pub fn clear(&mut self) {
        self.0.clear();
    }

    #[inline]
    pub fn insert(&mut self, ident: Identifier<'a>, elem: Record<'a>) -> Option<Record<'a>> {
        self.0.insert(ident, elem)
    }
}
