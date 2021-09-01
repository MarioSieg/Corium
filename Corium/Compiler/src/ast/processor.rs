use crate::ast::*;
use crate::error::list::ErrorList;

pub struct AstProcessorContext {
    pub error_list: ErrorList,
}

impl AstProcessorContext {
    pub fn new() -> Self {
        Self {
            error_list: ErrorList::new(),
        }
    }

    pub fn process_ast(&mut self, root: RootList) -> &ErrorList {
        for node in root {
            self.process_node(node);
        }
        &self.error_list
    }

    pub fn process_node(&mut self, node: Node) {
        match node {
            Node::Module(name) => self.process_module(name),
            Node::Function(func) => self.process_function(func),
            Node::QualifiedName(name) => self.process_qualified_name(name),
            Node::Identifier(ident) => self.process_identifier(ident),
        }
    }

    pub fn process_module(&mut self, name: QualifiedName) {
        println!("MODULE: {}", name);
    }

    pub fn process_function(&mut self, func: Function) {
        println!("FUN: {}", func);
    }

    pub fn process_qualified_name(&mut self, name: QualifiedName) {
        println!("NAME: {}", name);
    }

    pub fn process_identifier(&mut self, ident: Identifier) {
        println!("IDENT: {}", ident);
    }
}
