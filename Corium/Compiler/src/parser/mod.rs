use crate::ast::{parse::AstParseable, *};
use crate::error::*;
use pest::Parser;
use pest_derive::*;

pub mod error;
pub mod rule;

use error::handle_parser_error;
use rule::RuleStrider;

// Will be replaced by own parser implementation
#[derive(Parser)]
#[grammar = "parser/corium.pest"]
pub struct CoriumParser;

pub fn parse_source(src: &str) -> Result<RootList, Error> {
    let content = CoriumParser::parse(Rule::compilation_unit, src);
    match handle_parser_error(content) {
        Ok(rules) => {
            let mut result = RootList::new();
            for rule in rules {
                if let Some(node) = parse_rule_tree(RuleStrider::new(rule)) {
                    result.push(node);
                }
            }
            Ok(result)
        }
        Err(err) => Err(err),
    }
}

fn parse_rule_tree(rule: RuleStrider) -> Option<Node> {
    match rule.get_rule() {
        Rule::module_def => Some(ModuleName::parse(rule)),
        Rule::function_def => Some(Function::parse(rule)),
        _ => None,
    }
}
