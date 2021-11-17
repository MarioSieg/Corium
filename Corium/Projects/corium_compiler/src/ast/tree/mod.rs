use std::fmt;
use std::fmt::Debug;
use std::hash::Hash;

pub mod binary_operator;
pub mod block;
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

pub trait Statement: AstComponent {
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

pub mod prelude {
    pub use super::binary_operator::*;
    pub use super::block::*;
    pub use super::compilation_unit::*;
    pub use super::expression::*;
    pub use super::function::*;
    pub use super::function_signature::*;
    pub use super::global_statement::*;
    pub use super::identifier::*;
    pub use super::immutable_variable::*;
    pub use super::literal::*;
    pub use super::local_statement::*;
    pub use super::module::*;
    pub use super::mutable_variable::*;
    pub use super::native_function::*;
    pub use super::parameter::*;
    pub use super::parameter_list::*;
    pub use super::return_statement::*;
    pub use super::unary_operator::*;
    pub use super::{AstComponent, Operator, OperatorAssociativity, Statement};
    pub use crate::semantic::types::builtin_types::*;
}

mod tree_prelude {
    pub use super::AstComponent;
    pub use super::Rule;
    pub use super::Statement;
    pub use super::{Operator, OperatorAssociativity};
    pub use crate::semantic::types::builtin_types::*;
    pub use std::fmt;
}
