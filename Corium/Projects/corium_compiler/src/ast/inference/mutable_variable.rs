use crate::ast::tree::mutable_variable::MutableVariable;
use crate::error::list::ErrorList;
use crate::semantic::InferTypes;

impl<'ast> InferTypes<'ast> for MutableVariable<'ast> {
    fn infer_types(&mut self, _errors: &mut ErrorList) {}
}
