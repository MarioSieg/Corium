use super::unit::CompilationUnit;
use std::path::{Path, PathBuf};

pub struct CompilerContext {
    queue: Vec<CompilationUnit>,
}

impl CompilerContext {
    pub fn new() -> Self {
        Self { queue: Vec::new() }
    }

    pub fn enqueue_file<P: AsRef<Path>>(&mut self, path: P) {
        let unit = CompilationUnit::load_from_file(PathBuf::from(path.as_ref()));
        self.queue.push(unit);
    }

    pub fn get_queue(&self) -> &Vec<CompilationUnit> {
        &self.queue
    }

    pub fn compile(&mut self) {
        for compilation_unit in &mut self.queue {
            match compilation_unit.compile() {
                Ok(()) => (),
                Err(errors) => {
                    eprintln!("{}", errors)
                }
            }
        }
    }
}