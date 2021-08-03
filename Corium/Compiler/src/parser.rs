use crate::error::*;
use pest::error as pe;
use pest::iterators::{Pair, Pairs};
use pest::Parser;
use pest_derive::*;

#[derive(Parser)]
#[grammar = "corium.pest"]
pub struct CoriumParser;

pub fn parse_source(src: &str) -> Result<Pair<'_, Rule>, Error> {
    let content = CoriumParser::parse(Rule::file, src);
    if let Err(error) = handle_parser_error(&content) {
        Err(error)
    } else {
        Ok(content.unwrap().next().unwrap())
    }
}

fn handle_parser_error(result: &Result<Pairs<'_, Rule>, pe::Error<Rule>>) -> Result<(), Error> {
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
        Err(Error::ParseError(ParseError {
            input_location,
            source_location,
        }))
    } else {
        Ok(())
    }
}
