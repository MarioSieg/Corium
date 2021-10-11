use crate::ast::*;
use colored::Colorize;

pub mod any;
pub mod global;
pub mod local;
pub mod symtable;

use crate::error::list::ErrorList;
use crate::error::Error;
use any::*;
use global::GlobalSymbolTable;
use local::LocalSymbolTable;
use symtable::SymbolTable;

pub fn analyze(root: &CompilationUnit, file: &str) -> Result<(), ErrorList> {
    let mut errors = ErrorList::new();
    let mut global = GlobalSymbolTable::new();
    let mut local = LocalSymbolTable::new();

    for statement in &root.statements {
        let existed = match statement {
            GlobalStatement::MutableVariable(x) => global
                .variables
                .insert(x.name, AnyVariable::Mutable(x))
                .is_some(),
            GlobalStatement::ImmutableVariable(x) => global
                .variables
                .insert(x.name, AnyVariable::Immutable(x))
                .is_some(),
            GlobalStatement::Function(x) => {
                if global
                    .functions
                    .insert(x.signature.name, AnyFunction::Local(x))
                    .is_some()
                {
                    true
                } else {
                    local.clear();
                    for statement in &x.block.0 {
                        let existed = match statement {
                            LocalStatement::ImmutableVariable(x) => local
                                .variables
                                .insert(x.name, AnyVariable::Immutable(x))
                                .is_some(),
                            LocalStatement::MutableVariable(x) => local
                                .variables
                                .insert(x.name, AnyVariable::Mutable(x))
                                .is_some(),
                            _ => false,
                        };
                        if existed {
                            let smt_type = statement.descriptive_name();
                            let smt_ident = statement.code_identifier().0.red().bold();
                            let message =
                                format!("Local {} `{}` already defined!", smt_type, smt_ident);
                            errors.push(Error::Semantic(message, file.to_string()));
                        }
                    }
                    false
                }
            }
            GlobalStatement::NativeFunction(x) => global
                .functions
                .insert(x.signature.name, AnyFunction::Native(x))
                .is_some(),
        };
        if existed {
            let smt_type = statement.descriptive_name();
            let smt_ident = statement.code_identifier().0.red().bold();
            let message = format!("Global {} `{}` already defined!", smt_type, smt_ident);
            errors.push(Error::Semantic(message, file.to_string()));
        }
    }

    errors.into()
}
