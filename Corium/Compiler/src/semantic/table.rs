use super::record::Record;
use crate::ast::*;
use std::collections::HashMap;

pub struct SymbolTable<'a>(HashMap<Identifier<'a>, Record<'a>>);

impl<'a> SymbolTable<'a> {
    #[inline]
    pub fn new() -> Self {
        Self(HashMap::new())
    }

    #[inline]
    pub fn with_capacity(capacity: usize) -> Self {
        Self(HashMap::with_capacity(capacity))
    }

    #[inline]
    pub fn clear(&mut self) {
        self.0.clear();
    }

    #[inline]
    pub fn insert(&mut self, ident: Identifier<'a>, elem: Record<'a>) -> Option<Record<'a>> {
        self.0.insert(ident, elem)
    }

    #[inline]
    pub fn is_empty(&self) -> bool {
        self.0.is_empty()
    }

    #[inline]
    pub fn len(&self) -> usize {
        self.0.len()
    }

    #[inline]
    pub fn capacity(&self) -> usize {
        self.0.capacity()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn new() {
        let x = SymbolTable::new();
        assert!(x.is_empty());
        assert!(x.0.is_empty());
        assert_eq!(x.len(), 0);
        assert_eq!(x.capacity(), 0);
    }

    #[test]
    fn with_capacity() {
        let x = SymbolTable::with_capacity(32);
        assert!(x.is_empty());
        assert_eq!(x.len(), 0);
        assert!(x.capacity() >= 32);
    }

    #[test]
    fn insert() {
        let mut x = SymbolTable::new();
        let r = x.insert(
            Identifier("x"),
            Record::ImmutableVariable(&ImmutableVariable {
                name: Identifier("x"),
                type_hint: None,
                value: Expression::Literal(Literal::Bool(true)),
            }),
        );
        assert!(r.is_none());
        assert!(!x.is_empty());
        assert_eq!(x.len(), 1);
    }

    #[test]
    fn insert_same() {
        let mut x = SymbolTable::new();
        let r = x.insert(
            Identifier("x"),
            Record::ImmutableVariable(&ImmutableVariable {
                name: Identifier("x"),
                type_hint: None,
                value: Expression::Literal(Literal::Bool(true)),
            }),
        );
        assert!(r.is_none());
        assert!(!x.is_empty());
        assert_eq!(x.len(), 1);
        let r2 = x.insert(
            Identifier("x"),
            Record::ImmutableVariable(&ImmutableVariable {
                name: Identifier("x"),
                type_hint: None,
                value: Expression::Literal(Literal::Bool(true)),
            }),
        );
        assert!(r2.is_some());
        assert!(!x.is_empty());
        assert_eq!(x.len(), 1);
    }

    #[test]
    fn insert_unique2() {
        let mut x = SymbolTable::new();
        let r = x.insert(
            Identifier("x"),
            Record::ImmutableVariable(&ImmutableVariable {
                name: Identifier("x"),
                type_hint: None,
                value: Expression::Literal(Literal::Bool(true)),
            }),
        );
        assert!(r.is_none());
        assert!(!x.is_empty());
        assert_eq!(x.len(), 1);
        let r2 = x.insert(
            Identifier("y"),
            Record::ImmutableVariable(&ImmutableVariable {
                name: Identifier("y"),
                type_hint: None,
                value: Expression::Literal(Literal::Bool(true)),
            }),
        );
        assert!(r2.is_none());
        assert!(!x.is_empty());
        assert_eq!(x.len(), 2);
    }
}
