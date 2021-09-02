use crate::error::{Error, InputLocation, ParseError, SourceLocation};
use crate::parser::Rule;
use pest::error as pe;
use pest::iterators::Pairs;

pub(super) fn handle_parser_error(
    result: Result<Pairs<Rule>, pe::Error<Rule>>,
) -> Result<Pairs<Rule>, Error> {
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
