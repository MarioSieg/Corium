use crate::ast::*;
use crate::parser::{rule::RuleStrider, Rule};

// Base trait for parseable ast items.
pub trait AstParseable<'a>: AstComponent {
    fn parse(rule: RuleStrider<'a>) -> Node<'a>;
}

impl<'a> AstParseable<'a> for Function<'a> {
    fn parse(mut rule: RuleStrider<'a>) -> Node<'a> {
        let name = rule.next().unwrap().as_str();
        let mut parameters = Vec::new();
        let mut return_type = None;
        while let Some(param) = rule.next() {
            match param.as_rule() {
                Rule::parameter => {
                    let var = Variable {
                        name: param.as_str(),
                        type_hint: None,
                        value: None,
                        is_parameter: true,
                    };
                    parameters.push(var);
                }
                Rule::qualified_name => {
                    return_type = Some(param.as_str().into());
                }
                _ => (),
            }
        }
        Node::Function(Function {
            name,
            parameters,
            return_type,
        })
    }
}

impl<'a> AstParseable<'a> for ModuleName<'a> {
    fn parse(rule: RuleStrider<'a>) -> Node<'a> {
        Node::Module(ModuleName(rule.decay_str()))
    }
}
