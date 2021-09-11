use colored::Colorize;
use std::fmt;
use std::path::PathBuf;

pub mod list;

#[derive(Clone, Debug)]
pub enum InputLocation {
    Position(usize),
    Span(usize, usize),
}

#[derive(Clone, Debug)]
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

#[derive(Clone, Debug)]
pub struct ParseError {
    pub source: String,
    pub input_location: InputLocation,
    pub source_location: SourceLocation,
    pub message: Option<String>,
}

impl fmt::Display for ParseError {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        match self.input_location {
            InputLocation::Position(pos) => {
                write!(f, "{}", &self.source[pos..])?;
            }
            InputLocation::Span(from, to) => {
                write!(f, "{}", &self.source[from..=to])?;
            }
        }
        if let Some(msg) = &self.message {
            writeln!(f, "{}", msg)
        } else {
            Ok(())
        }
    }
}

#[derive(Clone, Debug)]
pub enum Error {
    Io(PathBuf),
    Parse(ParseError),
    Definition(String),
}

impl fmt::Display for Error {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        match self {
            Self::Io(path) => {
                write!(
                    f,
                    "Failed to access path: {}",
                    format!("\"{:?}\"", path).red()
                )
            }
            Self::Parse(error) => {
                write!(f, "Syntax error: {}", format!("\"{}\"", error).red())
            }
            Self::Definition(name) => {
                write!(f, "Symbol error: {}", format!("\"{}\"", name).red())
            }
        }
    }
}
