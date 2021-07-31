#[derive(Debug)]
pub enum Expr {
    Immediate(i64),
    Operation(Box<Expr>, Opcode, Box<Expr>),
}

#[derive(Debug)]
pub enum Opcode {
    Mul,
    Div,
    Add,
    Sub,
}
