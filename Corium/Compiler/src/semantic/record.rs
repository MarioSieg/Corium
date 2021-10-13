use crate::ast::*;

pub enum Record<'a> {
    MutableVariable(&'a MutableVariable<'a>),
    ImmutableVariable(&'a ImmutableVariable<'a>),
    Function(&'a Function<'a>),
    NativeFunction(&'a NativeFunction<'a>),
}

impl<'a> Record<'a> {
    pub fn descriptive_name(&self) -> &'static str {
        match self {
            Self::MutableVariable(_) => "mutable variable",
            Self::ImmutableVariable(_) => "immutable variable",
            Self::Function(_) => "function",
            Self::NativeFunction(_) => "native function",
        }
    }

    #[inline]
    pub fn is_function(&self) -> bool {
        matches!(self, Self::Function(_) | Self::NativeFunction(_))
    }

    #[inline]
    pub fn is_variable(&self) -> bool {
        matches!(self, Self::MutableVariable(_) | Self::ImmutableVariable(_))
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn descriptive_name_mutable_variable() {
        assert_eq!(
            Record::MutableVariable(&MutableVariable {
                name: Identifier("x"),
                type_hint: None,
                value: Expression::Literal(Literal::Bool(true))
            })
            .descriptive_name(),
            "mutable variable"
        );
    }

    #[test]
    fn descriptive_name_immutable_variable() {
        assert_eq!(
            Record::ImmutableVariable(&ImmutableVariable {
                name: Identifier("x"),
                type_hint: None,
                value: Expression::Literal(Literal::Bool(true))
            })
            .descriptive_name(),
            "immutable variable"
        );
    }

    #[test]
    fn descriptive_name_function() {
        assert_eq!(
            Record::Function(&Function {
                signature: FunctionSignature {
                    name: Identifier("x"),
                    parameters: None,
                    return_type: None
                },
                block: Block::empty()
            })
            .descriptive_name(),
            "function"
        );
    }

    #[test]
    fn descriptive_name_native_function() {
        assert_eq!(
            Record::NativeFunction(&NativeFunction {
                signature: FunctionSignature {
                    name: Identifier("x"),
                    parameters: None,
                    return_type: None
                }
            })
            .descriptive_name(),
            "native function"
        );
    }

    #[test]
    fn is_function_mutable_variable() {
        assert!(!Record::MutableVariable(&MutableVariable {
            name: Identifier("x"),
            type_hint: None,
            value: Expression::Literal(Literal::Bool(true))
        })
        .is_function());
    }

    #[test]
    fn is_function_immutable_variable() {
        assert!(!Record::ImmutableVariable(&ImmutableVariable {
            name: Identifier("x"),
            type_hint: None,
            value: Expression::Literal(Literal::Bool(true))
        })
        .is_function());
    }

    #[test]
    fn is_function_function() {
        assert!(Record::Function(&Function {
            signature: FunctionSignature {
                name: Identifier("x"),
                parameters: None,
                return_type: None
            },
            block: Block::empty()
        })
        .is_function());
    }

    #[test]
    fn is_function_native_function() {
        assert!(Record::NativeFunction(&NativeFunction {
            signature: FunctionSignature {
                name: Identifier("x"),
                parameters: None,
                return_type: None
            }
        })
        .is_function());
    }

    #[test]
    fn is_variable_mutable_variable() {
        assert!(Record::MutableVariable(&MutableVariable {
            name: Identifier("x"),
            type_hint: None,
            value: Expression::Literal(Literal::Bool(true))
        })
        .is_variable());
    }

    #[test]
    fn is_variable_immutable_variable() {
        assert!(Record::ImmutableVariable(&ImmutableVariable {
            name: Identifier("x"),
            type_hint: None,
            value: Expression::Literal(Literal::Bool(true))
        })
        .is_variable());
    }

    #[test]
    fn is_variable_function() {
        assert!(!Record::Function(&Function {
            signature: FunctionSignature {
                name: Identifier("x"),
                parameters: None,
                return_type: None
            },
            block: Block::empty()
        })
        .is_variable());
    }

    #[test]
    fn is_variable_native_function() {
        assert!(!Record::NativeFunction(&NativeFunction {
            signature: FunctionSignature {
                name: Identifier("x"),
                parameters: None,
                return_type: None
            }
        })
        .is_variable());
    }
}
