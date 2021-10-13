use super::error;
use super::record::Record;
use super::table::SymbolTable;
use crate::ast::*;
use crate::error::list::ErrorList;

pub struct Context<'a> {
    pub file: &'a str,
    pub function: Identifier<'a>,
    pub errors: ErrorList,
    pub global: SymbolTable<'a>,
    pub local: SymbolTable<'a>,
}

impl<'a> Context<'a> {
    pub fn new(file: &'a str) -> Self {
        Self {
            file,
            function: Identifier("?"),
            errors: ErrorList::new(),
            global: SymbolTable::new(),
            local: SymbolTable::new(),
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
        if let Some(existing) = existing {
            self.errors.push(error::make_global_definition_error(
                &existing, statement, self.file,
            ));
        }
    }

    pub fn analyze_local(
        &mut self,
        statement: &'a LocalStatement,
        ret_type: &Option<QualifiedName>,
    ) {
        match statement {
            LocalStatement::MutableVariable(var) => {
                if let Some(existing) = self.local.insert(var.name, Record::MutableVariable(var)) {
                    self.errors.push(error::make_local_definition_error(
                        &existing,
                        statement,
                        self.file,
                        self.function,
                    ));
                }
            }
            LocalStatement::ImmutableVariable(var) => {
                if let Some(existing) = self.local.insert(var.name, Record::ImmutableVariable(var))
                {
                    self.errors.push(error::make_local_definition_error(
                        &existing,
                        statement,
                        self.file,
                        self.function,
                    ));
                }
            }
            LocalStatement::ReturnStatement(smt) => self.analyze_return(smt, ret_type),
        }
    }

    fn analyze_return(&mut self, smt: &ReturnStatement, return_type: &Option<QualifiedName>) {
        if return_type.is_none() && smt.0.is_some() {
            self.errors
                .push(error::make_return_statement_error_unexpected(
                    smt,
                    self.function,
                    self.file,
                ))
        } else if return_type.is_some() && smt.0.is_none() {
            self.errors.push(error::make_return_statement_error_invalid(
                return_type.as_ref().unwrap(),
                self.function,
                self.file,
            ))
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
        self.function = name;
    }

    #[inline]
    pub fn exit_local_scope(&mut self) {
        self.local.clear();
    }
}

#[cfg(test)]
mod tests {}
