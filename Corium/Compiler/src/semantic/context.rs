use super::record::Record;
use super::symtable::SymbolTable;
use crate::ast::*;
use crate::error::{list::ErrorList, Error};
use colored::Colorize;

pub struct Context<'a> {
    pub file: &'a str,
    pub fun: Identifier<'a>,
    pub errors: ErrorList,
    pub global: SymbolTable<'a>,
    pub local: SymbolTable<'a>,
}

impl<'a> Context<'a> {
    pub fn new(file: &'a str) -> Self {
        Self {
            file,
            fun: Identifier("?"),
            errors: ErrorList::new(),
            global: SymbolTable::new(),
            local: SymbolTable::new(),
        }
    }

    #[cold]
    fn make_local_definition_error(
        &mut self,
        record: Option<Record<'a>>,
        statement: &LocalStatement,
    ) {
        if let Some(rec) = record {
            let smt_type = statement.descriptive_name();
            let smt_ident = statement.code_identifier().0.red().bold();
            let fun_name = self.fun.0.red().bold();
            let rec_name = rec.descriptive_name();
            let message = format!(
                "Local {} `{}` in function `{}` already defined as {} before",
                smt_type, smt_ident, fun_name, rec_name
            );
            self.errors
                .push(Error::Semantic(message, self.file.to_string()));
        }
    }

    #[cold]
    fn make_global_definition_error(
        &mut self,
        record: Option<Record<'a>>,
        statement: &GlobalStatement,
    ) {
        if let Some(rec) = record {
            let smt_type = statement.descriptive_name();
            let smt_ident = statement.code_identifier().0.red().bold();
            let rec_name = rec.descriptive_name();
            let message = format!(
                "Global {} `{}` already defined as {} before",
                smt_type, smt_ident, rec_name
            );
            self.errors
                .push(Error::Semantic(message, self.file.to_string()));
        }
    }

    pub fn analyze_global(&mut self, statement: &'a GlobalStatement) {
        let existing = match statement {
            GlobalStatement::MutableVariable(x) => {
                self.global.insert(x.name, Record::MutableVariable(x))
            }
            GlobalStatement::ImmutableVariable(x) => {
                self.global.insert(x.name, Record::ImmutableVariable(x))
            }
            GlobalStatement::Function(x) => {
                self.global.insert(x.signature.name, Record::Function(x))
            }
            GlobalStatement::NativeFunction(x) => self
                .global
                .insert(x.signature.name, Record::NativeFunction(x)),
        };
        self.make_global_definition_error(existing, statement);
    }

    pub fn analyze_local(
        &mut self,
        statement: &'a LocalStatement,
        return_type: &Option<QualifiedName>,
    ) {
        match statement {
            LocalStatement::MutableVariable(var) => {
                let exists = self.local.insert(var.name, Record::MutableVariable(var));
                self.make_local_definition_error(exists, statement);
            }
            LocalStatement::ImmutableVariable(var) => {
                let exists = self.local.insert(var.name, Record::ImmutableVariable(var));
                self.make_local_definition_error(exists, statement);
            }
            LocalStatement::ReturnStatement(smt) => {
                if return_type.is_none() && smt.0.is_some() {
                    let fun_name = self.fun.0.red().bold();
                    let smt = format!("{}", smt).red().bold();
                    let message = format!("Unexpected return statement `{}` in function `{}` - function does not return any value", smt, fun_name);
                    self.errors
                        .push(Error::Semantic(message, self.file.to_string()));
                } else if return_type.is_some() && smt.0.is_none() {
                    let fun_name = self.fun.0.red().bold();
                    let required_type = return_type.as_ref().unwrap().full.red().bold();
                    let message = format!(
                        "Return statement is missing an expression of type `{}` in function `{}`",
                        required_type, fun_name
                    );
                    self.errors
                        .push(Error::Semantic(message, self.file.to_string()));
                }
            }
        }
    }

    pub fn analyze_function(&mut self, f: &'a Function) {
        self.enter_local_scope(f.signature.name);
        let return_type = &f.signature.return_type;
        for local in &f.block.0 {
            self.analyze_local(local, return_type);
        }
        self.exit_local_scope();
    }

    #[inline]
    pub fn enter_local_scope(&mut self, name: Identifier<'a>) {
        self.fun = name;
    }

    #[inline]
    pub fn exit_local_scope(&mut self) {
        self.local.clear();
    }
}
