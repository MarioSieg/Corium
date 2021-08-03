use crate::error::*;
use crate::parser::parse_source;
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
    pub fn compile(self) -> Result<(), Vec<Error>> {
        let file = parse_source(&self.source_code);
        if let Err(e) = file {
            return Result::Err(vec![e]);
        }
        let inner = file.unwrap().into_inner();
        for r in inner {
            println!("{}", r);
        }
        Ok(())
    }
}
