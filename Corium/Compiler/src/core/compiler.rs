use crate::ast::populator::NestedAstPopulator;
use crate::ast::CompilationUnit;
use crate::error::list::ErrorList;
use crate::parser::parse_source;
use crate::semantic;

pub fn compile(src: &str, file: &str) -> Result<(), ErrorList> {
    let parse_tree = parse_source(src, file)?;
    let ast_tree = &CompilationUnit::populate(parse_tree);
    semantic::analyze(ast_tree, file)?;
    Ok(())
}
