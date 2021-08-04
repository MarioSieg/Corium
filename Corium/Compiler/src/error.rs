#[derive(Debug)]
pub enum InputLocation {
    Position(usize),
    Span(usize, usize),
}

#[derive(Debug)]
pub enum SourceLocation {
    Position {
        line: usize,
        column: usize,
    },
    Span {
        from: (usize, usize),
        to: (usize, usize),
    },
}

#[derive(Debug)]
pub struct ParseError {
    pub input_location: InputLocation,
    pub source_location: SourceLocation,
    pub message: Option<String>,
}

#[derive(Debug)]
pub enum Error {
    IoError(String),
    ParseError(ParseError),
}
