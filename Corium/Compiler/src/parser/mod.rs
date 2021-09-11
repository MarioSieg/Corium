use crate::ast::{parse::AstParseable, *};
use crate::error::*;
use pest::Parser;
use pest_derive::*;

pub mod error;

use error::handle_parser_error;
use pest::iterators::{Pair, Pairs};

pub type RuleIterator<'a> = Pairs<'a, Rule>;

// Will be replaced by own parser implementation
#[derive(Parser)]
#[grammar = "parser/corium.pest"]
pub struct CoriumParser;

pub fn parse_source(src: &str) -> Result<RootList, Error> {
    let content = CoriumParser::parse(Rule::compilation_unit, src);
    match handle_parser_error(src, content) {
        Ok(rules) => {
            let mut result = RootList::new();
            for rule in rules {
                if let Some(node) = parse_rule_tree(rule) {
                    result.push(node);
                }
            }
            Ok(result)
        }
        Err(err) => Err(err),
    }
}

fn parse_rule_tree(rule: Pair<Rule>) -> Option<Node> {
    let ty = rule.as_rule();
    let rule = rule.into_inner();
    match ty {
        Rule::module_def => Some(Node::Module(ModuleName::parse(rule))),
        Rule::function_def => Some(Node::Function(Function::parse(rule))),
        _ => None,
    }
}
