use crate::ast::processor::AstProcessorContext;
use crate::error::list::ErrorList;
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
    error_list: ErrorList,
    ast_processor: AstProcessorContext,
}

impl CompilationUnit {
    pub fn new(source_code: String, file_name: PathBuf) -> Self {
        let id = Uuid::new_v4();
        let error_list = ErrorList::new();
        let ast_processor = AstProcessorContext::new();
        Self {
            source_code,
            file_name,
            id,
            error_list,
            ast_processor,
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
        let error_list = ErrorList::new();
        let ast_processor = AstProcessorContext::new();
        Self {
            source_code,
            file_name,
            id,
            error_list,
            ast_processor,
        }
    }

    /// Compiles this compilation unit.
    pub fn compile(&mut self) -> Result<(), ErrorList> {
        let root: Result<_, _> = parse_source(&self.source_code);
        match root {
            Ok(root) => {
                self.ast_processor.process_ast(root);
                Ok(())
            }
            Err(e) => Err(e.into()),
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

    #[inline]
    pub fn get_id(&self) -> &Uuid {
        &self.id
    }

    #[inline]
    pub fn get_error_list(&self) -> &ErrorList {
        &self.error_list
    }

    #[inline]
    pub fn get_ast_processor_context(&self) -> &AstProcessorContext {
        &self.ast_processor
    }
}
