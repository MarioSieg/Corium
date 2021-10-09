pub trait SymbolTable {
    fn new() -> Self;
    fn with_capacity(capacity: usize) -> Self;
    fn clear(&mut self);
}
