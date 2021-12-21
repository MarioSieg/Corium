use crate::ast::tree::immutable_variable::ImmutableVariable;
use crate::error::list::ErrorList;
use crate::semantic::InferTypes;

impl<'ast> InferTypes<'ast> for ImmutableVariable<'ast> {
    fn infer_types(&mut self, _errors: &mut ErrorList) {}
}
