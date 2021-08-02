use crate::error::*;
use std::fs;
use std::path::PathBuf;
use uuid::Uuid;

/// Represents a compilation unit.
/// Each file contains a single compilation unit.
pub struct CompilationUnit {
    source_code: String,
    file_name: PathBuf,
    id: Uuid,
    error_list: Vec<Error>,
}

impl CompilationUnit {
    /// By default, all Corium source files are compiled in parallel but really huge files
    /// are split into chunks and these chunks are then also compiled in parallel.
    /// If the length of the source code string is above this value,
    /// the source code will be broken down into chunks and compiled in parallel.
    pub const PARALLEL_CHUNK_THRESHOLD: usize = 25000;

    /// The size of each chunk if a huge file is broken down into chunks
    /// to get compiled in parallel.
    pub const PARALLEL_CHUNK_SIZE: usize = 2048;

    pub fn new(source_code: String, file_name: PathBuf) -> Self {
        let id = Uuid::new_v4();
        let error_list = Vec::new();
        Self {
            source_code,
            file_name,
            id,
            error_list,
        }
    }

    pub fn load_from_file(path: PathBuf) -> Self {
        let source_code = fs::read_to_string(&path)
            .unwrap_or_else(|_| panic!("Failed to read source file: {:?}", path));
        let file_name = path
            .file_name()
            .unwrap_or_else(|| panic!("Missing file name: {:?}", path))
            .to_str()
            .unwrap_or_else(|| panic!("Failed to convert path: {:?}", path))
            .into();
        let id = Uuid::new_v4();
        let error_list = Vec::new();
        Self {
            source_code,
            file_name,
            id,
            error_list,
        }
    }

    #[inline]
    pub fn get_source_code(&self) -> &String {
        &self.source_code
    }

    #[inline]
    pub fn get_file_name(&self) -> &PathBuf {
        &self.file_name
    }

    /// Compiles this compilation unit.
    pub fn compile(mut self) -> Result<(), Vec<Error>> {
        use crate::parser::*;
        use pest::Parser;

        let file = CoriumParser::parse(Rule::file, &self.source_code);
        if let Err(error) = &file {
            let input_location = match error.location {
                pest::error::InputLocation::Pos(x) => InputLocation::Position(x),
                pest::error::InputLocation::Span(range) => InputLocation::Span(range.0, range.1),
            };
            let source_location = match error.line_col {
                pest::error::LineColLocation::Pos(pos) => SourceLocation::Position {
                    line: pos.0,
                    column: pos.1,
                },
                pest::error::LineColLocation::Span(range1, range2) => SourceLocation::Span {
                    from: range1,
                    to: range2,
                },
            };
            let parse_err = ParseError {
                input_location,
                source_location,
            };
            self.error_list.push(Error::ParseError(parse_err));
            return Err(self.error_list);
        }
        let file = file.unwrap().next().unwrap();
        for entry in file.into_inner() {
            println!("{}", entry);
        }
        Ok(())
    }
}
