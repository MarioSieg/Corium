use crate::ast::*;
use crate::error::*;
use pest::error as pe;
use pest::iterators::{Pair, Pairs};
use pest::Parser;
use pest_derive::*;

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

fn handle_parser_error(result: Result<Pairs<Rule>, pe::Error<Rule>>) -> Result<Pairs<Rule>, Error> {
    if let Err(error) = result {
        let input_location = match error.location {
            pe::InputLocation::Pos(x) => InputLocation::Position(x),
            pe::InputLocation::Span(range) => InputLocation::Span(range.0, range.1),
        };
        let source_location = match error.line_col {
            pe::LineColLocation::Pos(pos) => SourceLocation::Position {
                line: pos.0,
                column: pos.1,
            },
            pe::LineColLocation::Span(range1, range2) => SourceLocation::Span {
                from: range1,
                to: range2,
            },
        };
        let message = if let pe::ErrorVariant::CustomError { message } = &error.variant {
            Some(message.clone())
        } else {
            None
        };
        Err(Error::ParseError(ParseError {
            input_location,
            source_location,
            message,
        }))
    } else {
        Ok(result.unwrap())
    }
}
