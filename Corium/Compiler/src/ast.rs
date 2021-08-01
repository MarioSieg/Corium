use std::fmt;

#[derive(Debug)]
pub enum Expr {
    Imm(i64),
    Operation(Box<Expr>, Operator, Box<Expr>),
}

#[derive(Debug)]
pub enum Operator {
    Add,
    Sub,
    Mul,
    Div,
    Mod,
}
