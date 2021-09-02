use crate::ast::*;
use crate::error::*;
use pest::iterators::Pair;
use pest::Parser;
use pest_derive::*;

pub mod error;

use error::handle_parser_error;

#[derive(Parser)]
#[grammar = "parser/corium.pest"]
pub struct CoriumParser;

pub fn parse_source(src: &str) -> Result<RootList, Error> {
    let content = CoriumParser::parse(Rule::compilation_unit, src);
    match handle_parser_error(content) {
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
    match rule.as_rule() {
        Rule::module_def => Some(visitors::module_def(rule)),
        Rule::function_def => Some(visitors::function_def(rule)),
        Rule::qualified_name => Some(visitors::qualified_name(rule)),
        Rule::ident => Some(visitors::ident(rule)),
        Rule::compilation_unit | Rule::sep | Rule::EOI => None,
    }
}

mod visitors {
    use super::*;

    pub fn module_def(rule: Pair<Rule>) -> Node {
        Node::Module(get_rule_text(rule))
    }

    pub fn function_def(rule: Pair<Rule>) -> Node {
        let mut rule = rule.into_inner();
        let name = rule.next().unwrap().as_str();
        let return_type = rule.next().map(|name| name.as_str().into());
        Node::Function(Function {
            name,
            parameters: vec![],
            return_type,
        })
    }

    pub fn qualified_name(rule: Pair<Rule>) -> Node {
        Node::QualifiedName(get_rule_text(rule))
    }

    pub fn ident(rule: Pair<Rule>) -> Node {
        Node::Identifier(get_rule_text(rule))
    }
}

#[inline]
fn get_rule_text(rule: Pair<Rule>) -> &str {
    rule.into_inner().next().unwrap().as_str()
}
