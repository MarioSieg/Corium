use super::unit::CompilationUnit;
use std::path::{PathBuf, Path};

pub struct CompilerContext {
    queue: Vec<CompilationUnit>
}

impl CompilerContext {
    pub fn new() -> Self {
        Self {
            queue: Vec::new(),
        }
    }

    pub fn enqueue_file<P: AsRef<Path>>(&mut self, path: P) {
        self.queue.push(CompilationUnit::load_from_file(PathBuf::from(path.as_ref())))
    }

    pub fn get_queue(&self) -> &Vec<CompilationUnit> {
        &self.queue
    }

    pub fn compile(&mut self) {
        for compilation_unit in &self.queue {
            match compilation_unit.compile() {
                Ok(()) => (),
                Err(errors) => {
                    for err in errors {
                        println!("{:?}", err);
                    }
                }
            }
        }
    }
}
