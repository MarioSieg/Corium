use crate::ast::*;
use crate::parser::{Rule, RuleIterator};

// Base trait for parseable ast items.
pub trait AstParseable<'a>: AstComponent {
    fn parse(rule: RuleIterator<'a>) -> Self;
}

impl<'a> AstParseable<'a> for Function<'a> {
    fn parse(mut rule: RuleIterator<'a>) -> Self {
        let ident = rule.next().expect("expected identifier!").as_str();
        let mut parameters = Vec::new();
        let mut return_type = None;
        let mut block = Block(Vec::new());

        if let Some(nested) = rule.next() {
            match nested.as_rule() {
                Rule::parameter_list => {
                    let inner = nested.into_inner();
                    for param in inner {
                        parameters.push(Variable::parse(param.into_inner()));
                    }

                    if let Some(ret_ty) = rule.next() {
                        if ret_ty.as_rule() == Rule::qualified_name {
                            return_type = Some(TypeName::from(ret_ty.as_str()));
                        }
                    }
                }
                Rule::qualified_name => {
                    return_type = Some(TypeName::from(nested.as_str()));
                }
                Rule::block => {
                    block = Block::parse(nested.into_inner());
                }
                _ => unreachable!(),
            }
        }

        Self {
            name: ident,
            parameters,
            return_type,
            block,
        }
    }
}

impl<'a> AstParseable<'a> for Variable<'a> {
    fn parse(rule: RuleIterator<'a>) -> Self {
        Self {
            name: rule.as_str(),
            type_hint: None,
            value: None,
            is_parameter: true,
        }
    }
}

impl<'a> AstParseable<'a> for Block<'a> {
    fn parse(_rule: RuleIterator<'a>) -> Self {
        Self(Vec::new())
    }
}

impl<'a> AstParseable<'a> for ModuleName<'a> {
    fn parse(rule: RuleIterator<'a>) -> Self {
        Self(rule.as_str())
    }
}
