use crate::ast::processor::AstProcessorContext;
use crate::ast::RootList;
use crate::error::list::ErrorList;
use crate::error::Error;
use crate::parser::parse_source;
use std::fs;
use std::mem::replace;
use std::path::PathBuf;
use uuid::Uuid;

/// Represents a compilation unit.
/// Each file contains a single compilation unit.
pub struct CompilationUnit<'a> {
    source_code: String,
    file_name: PathBuf,
    id: Uuid,
    error_list: ErrorList,
    root: Option<Result<RootList<'a>, Error>>,
    ast_processor: AstProcessorContext<'a>,
}

impl<'a> CompilationUnit<'a> {
    pub fn new(source_code: String, file_name: PathBuf) -> Self {
        let id = Uuid::new_v4();
        let error_list = ErrorList::new();
        let root = None;
        let ast_processor = AstProcessorContext::new();
        Self {
            source_code,
            file_name,
            id,
            error_list,
            root,
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
        let root = None;
        let ast_processor = AstProcessorContext::new();
        Self {
            source_code,
            file_name,
            id,
            error_list,
            root,
            ast_processor,
        }
    }

    /// Compiles this compilation unit.
    pub fn compile(&'a mut self) -> Result<(), ErrorList> {
        let src: &'a str = &self.source_code;
        self.root = Some(parse_source(src));
        match replace(&mut self.root, None) {
            Some(root) => match root {
                Ok(root) => {
                    self.ast_processor.process_ast(root);
                    print!("{}", self.ast_processor);
                    print!("{}", self.error_list);
                    Ok(())
                }
                Err(e) => Err(e.into()),
            },
            None => panic!("Missing AST root!"),
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
    pub fn get_ast_processor_context(&'a self) -> &'a AstProcessorContext {
        &self.ast_processor
    }
}
