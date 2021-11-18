use crate::semantic::SymbolTable;
use std::fmt;
use std::fmt::Debug;
use std::hash::Hash;

pub mod binary_operator;
pub mod block;
pub mod builtin_types;
pub mod compilation_unit;
pub mod expression;
pub mod function;
pub mod function_signature;
pub mod global_statement;
pub mod identifier;
pub mod immutable_variable;
pub mod literal;
pub mod local_statement;
pub mod module;
pub mod mutable_variable;
pub mod native_function;
pub mod parameter;
pub mod parameter_list;
pub mod return_statement;
pub mod unary_operator;

pub type Rule = crate::parser::Rule;

pub trait AstComponent: Clone + fmt::Display + fmt::Debug {
    const CORRESPONDING_RULE: Rule;
}

pub trait Statement<'ast>: AstComponent {
    fn populate_symbols(&'ast self, table: &mut SymbolTable<'ast, Self>) -> Option<&Self> {
        table.insert(self.code_identifier(), self)
    }
    fn descriptive_name(&self) -> &'static str;
    fn code_identifier(&self) -> &identifier::Identifier;
}

#[repr(u8)]
#[derive(Copy, Clone, Eq, PartialEq, Debug)]
pub enum OperatorAssociativity {
    LeftToRight,
    RightToLeft,
}

pub trait Operator:
    Sized + AstComponent + Copy + Clone + Eq + PartialEq + Debug + Hash + Ord + PartialOrd
{
    const COUNT: usize;
    const TOKENS: &'static [&'static str];
    const PRECEDENCE_TABLE: &'static [u8];
    const ASSOCIATIVITY_TABLE: &'static [OperatorAssociativity];
    const RULE_TABLE: &'static [Rule];

    fn from_primitive(x: u64) -> Self;
    fn token(&self) -> &'static str;
    fn precedence(&self) -> u8;
    fn associativity(&self) -> OperatorAssociativity;
    fn rule(&self) -> Rule;

    fn is_valid(r: Rule) -> bool {
        Self::RULE_TABLE.contains(&r)
    }
}
