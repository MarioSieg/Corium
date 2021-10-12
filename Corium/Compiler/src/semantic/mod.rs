use crate::ast::*;
use crate::error::list::ErrorList;

pub mod context;
pub mod record;
pub mod symtable;

use context::Context;

pub fn analyze(root: &CompilationUnit, file: &str) -> Result<(), ErrorList> {
    let mut context = Context::new(file);

    for global in &root.statements {
        context.analyze_global(global);
        if let GlobalStatement::Function(f) = global {
            context.analyze_function(f);
        }
    }

    context.errors.into()
}
