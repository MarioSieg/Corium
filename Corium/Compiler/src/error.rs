pub enum InputLocation {
    Position(usize),
    Span(usize, usize),
}

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

pub struct ParseError {
    pub input_location: InputLocation,
    pub source_location: SourceLocation,
}

pub enum Error {
    IoError(String),
    ParseError(ParseError),
}
