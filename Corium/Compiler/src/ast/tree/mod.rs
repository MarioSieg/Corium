use std::fmt;

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
pub mod operator;
pub mod parameter;
pub mod parameter_list;
pub mod qualified_name;
pub mod return_statement;

pub type Rule = crate::parser::Rule;

pub trait AstComponent: Clone + fmt::Display + fmt::Debug {
    const CORRESPONDING_RULE: Rule;
}

pub trait Statement: AstComponent {
    fn descriptive_name(&self) -> &'static str;
    fn code_identifier(&self) -> identifier::Identifier;
}

pub mod prelude {
    pub use super::super::builtin_types::*;
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
    pub use super::operator::*;
    pub use super::parameter::*;
    pub use super::parameter_list::*;
    pub use super::qualified_name::*;
    pub use super::return_statement::*;
    pub use super::{AstComponent, Statement};
}

mod tree_prelude {
    pub use super::super::builtin_types::*;
    pub use super::AstComponent;
    pub use super::Rule;
    pub use super::Statement;
    pub use std::fmt;
}
