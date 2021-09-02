use crate::ast::*;
use crate::error::*;
use pest::Parser;
use pest_derive::*;

pub mod error;
pub mod rule;

use error::handle_parser_error;
use rule::RuleStrider;

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
        Rule::module_def => Some(visitors::module_def(rule)),
        Rule::function_def => Some(visitors::function_def(rule)),
        Rule::qualified_name => Some(visitors::qualified_name(rule)),
        Rule::ident => Some(visitors::ident(rule)),
        Rule::compilation_unit | Rule::sep | Rule::EOI => None,
    }
}

mod visitors {
    use super::*;

    pub fn module_def(rule: RuleStrider) -> Node {
        Node::Module(rule.decay_str())
    }

    pub fn function_def(mut rule: RuleStrider) -> Node {
        let name = rule.next().unwrap().as_str();
        let return_type = rule.next().map(|name| name.as_str().into());
        Node::Function(Function {
            name,
            parameters: vec![],
            return_type,
        })
    }

    pub fn qualified_name(rule: RuleStrider) -> Node {
        Node::QualifiedName(rule.decay_str())
    }

    pub fn ident(rule: RuleStrider) -> Node {
        Node::Identifier(rule.decay_str())
    }
}
