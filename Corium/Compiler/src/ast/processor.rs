use crate::ast::table::FunctionTable;
use crate::ast::*;
use crate::error::list::ErrorList;
use std::fmt;

pub struct AstProcessorContext<'a> {
    pub error_list: ErrorList,
    pub function_table: FunctionTable<'a>,
    pub current_module: Option<ModuleName<'a>>,
}

impl<'a> AstProcessorContext<'a> {
    pub fn new() -> Self {
        Self {
            error_list: ErrorList::new(),
            function_table: FunctionTable::new(),
            current_module: None,
        }
    }

    pub fn process_ast(&mut self, root: RootList<'a>) -> &ErrorList {
        for node in root {
            self.process_node(node);
        }
        &self.error_list
    }

    pub fn process_node(&mut self, node: Node<'a>) {
        match node {
            Node::Module(name) => self.process_module(name),
            Node::Function(func) => self.process_function(func),
            Node::QualifiedName(name) => self.process_qualified_name(name),
            Node::Identifier(ident) => self.process_identifier(ident),
        }
    }

    pub fn process_module(&mut self, name: ModuleName<'a>) {
        self.current_module = Some(name);
    }

    pub fn process_function(&mut self, func: Function<'a>) {
        self.function_table.insert(func.name, func);
    }

    pub fn process_qualified_name(&mut self, name: QualifiedName) {
        println!("NAME: {}", name);
    }

    pub fn process_identifier(&mut self, ident: Identifier) {
        println!("IDENT: {}", ident);
    }
}

impl<'a> fmt::Display for AstProcessorContext<'a> {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        writeln!(f, "Current module: {:?}", self.current_module)?;
        for fun in self.function_table.values() {
            writeln!(f, "{}", fun)?;
        }
        Ok(())
    }
}
