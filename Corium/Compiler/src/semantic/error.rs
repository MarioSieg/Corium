use super::record::Record;
use crate::ast::*;
use crate::error::Error;
use colored::Colorize;

#[cold]
pub fn make_local_definition_error(
    rec: &Record,
    statement: &LocalStatement,
    file: &str,
    fun: Identifier,
) -> Error {
    let smt_type = statement.descriptive_name();
    let smt_ident = statement.code_identifier().0.red().bold();
    let fun_name = fun.0.red().bold();
    let rec_name = rec.descriptive_name();
    let message = format!(
        "Local {} `{}` in function `{}` already defined as {} before",
        smt_type, smt_ident, fun_name, rec_name
    );
    Error::Semantic(message, file.to_string())
}

#[cold]
pub fn make_global_definition_error(
    rec: &Record,
    statement: &GlobalStatement,
    file: &str,
) -> Error {
    let smt_type = statement.descriptive_name();
    let smt_ident = statement.code_identifier().0.red().bold();
    let rec_name = rec.descriptive_name();
    let message = format!(
        "Global {} `{}` already defined as {} before",
        smt_type, smt_ident, rec_name
    );
    Error::Semantic(message, file.to_string())
}

#[cold]
pub fn make_return_statement_error_unexpected(
    statement: &ReturnStatement,
    function: Identifier,
    file: &str,
) -> Error {
    let fun_name = function.0.red().bold();
    let smt = format!("{}", statement).red().bold();
    let message = format!(
        "Unexpected return statement `{}` in function `{}` - function does not return any value",
        smt, fun_name
    );
    Error::Semantic(message, file.to_string())
}

#[cold]
pub fn make_return_statement_error_invalid(
    type_name: &QualifiedName,
    function: Identifier,
    file: &str,
) -> Error {
    let fun_name = function.0.red().bold();
    let required_type = type_name.full.red().bold();
    let message = format!(
        "Return statement is missing an expression of type `{}` in function `{}`",
        required_type, fun_name
    );
    Error::Semantic(message, file.to_string())
}
