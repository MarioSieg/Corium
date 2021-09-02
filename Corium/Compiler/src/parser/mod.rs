use crate::ast::*;
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
        Rule::module_def => Some(visitors::module_def(rule)),
        Rule::function_def => Some(visitors::function_def(rule)),
        Rule::qualified_name
        | Rule::ident
        | Rule::parameter
        | Rule::compilation_unit
        | Rule::sep
        | Rule::EOI => None,
    }
}

mod visitors {
    use super::*;

    pub fn module_def(rule: RuleStrider) -> Node {
        Node::Module(rule.decay_str())
    }

    pub fn function_def(mut rule: RuleStrider) -> Node {
        let name = rule.next().unwrap().as_str();
        let mut parameters = Vec::new();
        let mut return_type = None;
        while let Some(param) = rule.next() {
            match param.as_rule() {
                Rule::parameter => {
                    let var = Variable {
                        name: param.as_str(),
                        type_hint: None,
                        value: None,
                        is_parameter: true,
                    };
                    parameters.push(var);
                }
                Rule::qualified_name => {
                    return_type = Some(param.as_str().into());
                }
                _ => (),
            }
        }
        Node::Function(Function {
            name,
            parameters,
            return_type,
        })
    }
}
