use crate::ast::{mapping::*, *};
use crate::parser::*;

mod mapping {
    use super::*;

    mod identifier {
        use super::*;

        #[test]
        fn alphanumeric() {
            let result = CoriumParser::parse(Rule::Identifier, "MyClass").unwrap();
            let ast = Identifier::map(result);
            assert_eq!(ast.0, "MyClass");
        }

        #[test]
        fn mixed() {
            let result = CoriumParser::parse(Rule::Identifier, "My2Class32LOl").unwrap();
            let ast = Identifier::map(result);
            assert_eq!(ast.0, "My2Class32LOl");
        }

        #[test]
        fn numeric() {
            let result = CoriumParser::parse(Rule::Identifier, "X278247842877284").unwrap();
            let ast = Identifier::map(result);
            assert_eq!(ast.0, "X278247842877284");
        }
    }

    mod qualified_name {
        use super::*;

        #[test]
        fn simple() {
            let result = CoriumParser::parse(Rule::QualifiedName, "MyPackage").unwrap();
            let ast = QualifiedName::map(result);
            assert_eq!(ast.full, "MyPackage");
            assert_eq!(ast.split.len(), 1);
            assert_eq!(ast.split[0], "MyPackage");
        }

        #[test]
        fn nested() {
            let result = CoriumParser::parse(Rule::QualifiedName, "MyPackage.Class").unwrap();
            let ast = QualifiedName::map(result);
            assert_eq!(ast.full, "MyPackage.Class");
            assert_eq!(ast.split.len(), 2);
            assert_eq!(ast.split[0], "MyPackage");
            assert_eq!(ast.split[1], "Class");
        }

        #[test]
        fn nested2() {
            let result =
                CoriumParser::parse(Rule::QualifiedName, "MyPackage.Class.StaticMember").unwrap();
            let ast = QualifiedName::map(result);
            assert_eq!(ast.full, "MyPackage.Class.StaticMember");
            assert_eq!(ast.split.len(), 3);
            assert_eq!(ast.split[0], "MyPackage");
            assert_eq!(ast.split[1], "Class");
            assert_eq!(ast.split[2], "StaticMember");
        }

        #[test]
        fn nested3() {
            let result =
                CoriumParser::parse(Rule::QualifiedName, "MyPackage.Class.StaticMember.Field")
                    .unwrap();
            let ast = QualifiedName::map(result);
            assert_eq!(ast.full, "MyPackage.Class.StaticMember.Field");
            assert_eq!(ast.split.len(), 4);
            assert_eq!(ast.split[0], "MyPackage");
            assert_eq!(ast.split[1], "Class");
            assert_eq!(ast.split[2], "StaticMember");
            assert_eq!(ast.split[3], "Field");
        }
    }

    mod literal {
        use super::*;

        #[test]
        fn float() {
            let result = CoriumParser::parse(Rule::Literal, "2.5").unwrap();
            let ast = Literal::map(result);
            match ast {
                Literal::Float(x) => {
                    assert_eq!(x, 2.5);
                }
                _ => panic!("Invalid literal type!"),
            }
        }

        #[test]
        fn int() {
            let result = CoriumParser::parse(Rule::Literal, "-10").unwrap();
            let ast = Literal::map(result);
            match ast {
                Literal::Int(x) => {
                    assert_eq!(x, -10);
                }
                _ => panic!("Invalid literal type!"),
            }
        }

        #[test]
        fn boolean() {
            let result = CoriumParser::parse(Rule::Literal, "true").unwrap();
            let ast = Literal::map(result);
            match ast {
                Literal::Bool(x) => {
                    assert_eq!(x, true);
                }
                _ => panic!("Invalid literal type!"),
            }
        }

        #[test]
        fn character() {
            let result = CoriumParser::parse(Rule::Literal, "'X'").unwrap();
            let ast = Literal::map(result);
            match ast {
                Literal::Char(x) => {
                    assert_eq!(x, 'X');
                }
                _ => panic!("Invalid literal type!"),
            }
        }

        #[test]
        fn string() {
            let result = CoriumParser::parse(Rule::Literal, "\"Hallo zusammen ;)\"").unwrap();
            let ast = Literal::map(result);
            match ast {
                Literal::String(x) => {
                    assert_eq!(x, "Hallo zusammen ;)");
                }
                _ => panic!("Invalid literal type!"),
            }
        }

        #[test]
        fn string_empty() {
            let result = CoriumParser::parse(Rule::Literal, "\"\"").unwrap();
            let ast = Literal::map(result);
            match ast {
                Literal::String(x) => {
                    assert!(x.is_empty());
                }
                _ => panic!("Invalid literal type!"),
            }
        }
    }

    mod expression {
        use super::*;

        #[test]
        fn float_literal() {
            let result = CoriumParser::parse(Rule::Expression, "2.5").unwrap();
            let ast = Expression::map(result);
        }

        #[test]
        fn int_literal() {
            let result = CoriumParser::parse(Rule::Expression, "10").unwrap();
            let ast = Expression::map(result);
        }

        #[test]
        fn boolean_literal() {
            let result = CoriumParser::parse(Rule::Expression, "true").unwrap();
            let ast = Expression::map(result);
        }

        #[test]
        fn character_literal() {
            let result = CoriumParser::parse(Rule::Expression, "'X'").unwrap();
            let ast = Expression::map(result);
        }

        #[test]
        fn string_literal() {
            let result = CoriumParser::parse(Rule::Expression, "\"Hallo zusammen ;)\"").unwrap();
            let ast = Expression::map(result);
        }
    }

    mod parameter {
        use super::*;

        #[test]
        fn int() {
            let result = CoriumParser::parse(Rule::Parameter, "myParam int").unwrap();
            let ast = Parameter::map(result);
            assert_eq!(ast.name.0, "myParam");
            assert_eq!(ast.type_hint.full, "int");
            assert!(ast.value.is_none());
        }

        #[test]
        fn float() {
            let mut result = CoriumParser::parse(Rule::Parameter, "myParam float").unwrap();
            let ast = Parameter::map(result);
            assert_eq!(ast.name.0, "myParam");
            assert_eq!(ast.type_hint.full, "float");
            assert!(ast.value.is_none());
        }

        #[test]
        fn class() {
            let mut result = CoriumParser::parse(Rule::Parameter, "myParam MyClass").unwrap();
            let ast = Parameter::map(result);
            assert_eq!(ast.name.0, "myParam");
            assert_eq!(ast.type_hint.full, "MyClass");
            assert!(ast.value.is_none());
        }

        #[test]
        fn package_class() {
            let mut result =
                CoriumParser::parse(Rule::Parameter, "myParam MyPackage.MyClass").unwrap();
            let ast = Parameter::map(result);
            assert_eq!(ast.name.0, "myParam");
            assert_eq!(ast.type_hint.full, "MyPackage.MyClass");
            assert!(ast.value.is_none());
        }

        #[test]
        fn int_with_default_value() {
            let mut result = CoriumParser::parse(Rule::Parameter, "myParam int = 10").unwrap();
            let ast = Parameter::map(result);
            assert_eq!(ast.name.0, "myParam");
            assert_eq!(ast.type_hint.full, "int");
            assert!(ast.value.is_some());
            match ast.value.unwrap() {
                Expression::Literal(x) => match x {
                    Literal::Int(y) => {
                        assert_eq!(y, 10);
                    }
                    _ => panic!("Invalid literal!"),
                },
                _ => panic!("Invalid expression!"),
            }
        }

        #[test]
        fn float_with_default_value() {
            let mut result = CoriumParser::parse(Rule::Parameter, "myParam float = 0.999").unwrap();
            let ast = Parameter::map(result);
            assert_eq!(ast.name.0, "myParam");
            assert_eq!(ast.type_hint.full, "float");
            assert!(ast.value.is_some());
            match ast.value.unwrap() {
                Expression::Literal(x) => match x {
                    Literal::Float(y) => {
                        assert_eq!(y, 0.999);
                    }
                    _ => panic!("Invalid literal!"),
                },
                _ => panic!("Invalid expression!"),
            }
        }

        #[test]
        fn bool_with_default_value() {
            let mut result = CoriumParser::parse(Rule::Parameter, "myParam bool = true").unwrap();
            let ast = Parameter::map(result);
            assert_eq!(ast.name.0, "myParam");
            assert_eq!(ast.type_hint.full, "bool");
            assert!(ast.value.is_some());
            match ast.value.unwrap() {
                Expression::Literal(x) => match x {
                    Literal::Bool(y) => {
                        assert_eq!(y, true);
                    }
                    _ => panic!("Invalid literal!"),
                },
                _ => panic!("Invalid expression!"),
            }
        }

        #[test]
        fn char_with_default_value() {
            let mut result = CoriumParser::parse(Rule::Parameter, "myParam char = 'x'").unwrap();
            let ast = Parameter::map(result);
            assert_eq!(ast.name.0, "myParam");
            assert_eq!(ast.type_hint.full, "char");
            assert!(ast.value.is_some());
            match ast.value.unwrap() {
                Expression::Literal(x) => match x {
                    Literal::Char(y) => {
                        assert_eq!(y, 'x');
                    }
                    _ => panic!("Invalid literal!"),
                },
                _ => panic!("Invalid expression!"),
            }
        }

        #[test]
        fn string_with_default_value() {
            let mut result =
                CoriumParser::parse(Rule::Parameter, "myParam string = \"I luv u :3\"").unwrap();
            let ast = Parameter::map(result);
            assert_eq!(ast.name.0, "myParam");
            assert_eq!(ast.type_hint.full, "string");
            assert!(ast.value.is_some());
            match ast.value.unwrap() {
                Expression::Literal(x) => match x {
                    Literal::String(y) => {
                        assert_eq!(y, "I luv u :3");
                    }
                    _ => panic!("Invalid literal!"),
                },
                _ => panic!("Invalid expression!"),
            }
        }
    }

    mod parameter_list {
        use super::*;

        #[test]
        fn one() {
            let result = CoriumParser::parse(Rule::ParameterList, "x int").unwrap();
            let ast = ParameterList::map(result);
            assert_eq!(ast.0.len(), 1);

            assert_eq!(ast.0[0].name.0, "x");
            assert_eq!(ast.0[0].type_hint.full, "int");
            assert!(ast.0[0].value.is_none());
        }

        #[test]
        fn two() {
            let result = CoriumParser::parse(Rule::ParameterList, "x int, y float").unwrap();
            let ast = ParameterList::map(result);
            assert_eq!(ast.0.len(), 2);

            assert_eq!(ast.0[0].name.0, "x");
            assert_eq!(ast.0[0].type_hint.full, "int");
            assert!(ast.0[0].value.is_none());

            assert_eq!(ast.0[1].name.0, "y");
            assert_eq!(ast.0[1].type_hint.full, "float");
            assert!(ast.0[1].value.is_none());
        }

        #[test]
        fn three() {
            let result =
                CoriumParser::parse(Rule::ParameterList, "x int, y float, z string").unwrap();
            let ast = ParameterList::map(result);
            assert_eq!(ast.0.len(), 3);

            assert_eq!(ast.0[0].name.0, "x");
            assert_eq!(ast.0[0].type_hint.full, "int");
            assert!(ast.0[0].value.is_none());

            assert_eq!(ast.0[1].name.0, "y");
            assert_eq!(ast.0[1].type_hint.full, "float");
            assert!(ast.0[1].value.is_none());

            assert_eq!(ast.0[2].name.0, "z");
            assert_eq!(ast.0[2].type_hint.full, "string");
            assert!(ast.0[2].value.is_none());
        }

        #[test]
        fn one_with_default_value() {
            let result = CoriumParser::parse(Rule::ParameterList, "x int = 10").unwrap();
            let ast = ParameterList::map(result);
            assert_eq!(ast.0.len(), 1);

            assert_eq!(ast.0[0].name.0, "x");
            assert_eq!(ast.0[0].type_hint.full, "int");
            assert!(ast.0[0].value.is_some());
            match ast.0[0].value.as_ref().unwrap() {
                Expression::Literal(x) => match x {
                    Literal::Int(y) => {
                        assert_eq!(*y, 10);
                    }
                    _ => panic!("Invalid literal!"),
                },
                _ => panic!("Invalid expression!"),
            }
        }

        #[test]
        fn two_with_default_value() {
            let result =
                CoriumParser::parse(Rule::ParameterList, "x int = 10, y float = 2.4").unwrap();
            let ast = ParameterList::map(result);
            assert_eq!(ast.0.len(), 2);

            assert_eq!(ast.0[0].name.0, "x");
            assert_eq!(ast.0[0].type_hint.full, "int");
            assert!(ast.0[0].value.is_some());
            match ast.0[0].value.as_ref().unwrap() {
                Expression::Literal(x) => match x {
                    Literal::Int(y) => {
                        assert_eq!(*y, 10);
                    }
                    _ => panic!("Invalid literal!"),
                },
                _ => panic!("Invalid expression!"),
            }

            assert_eq!(ast.0[1].name.0, "y");
            assert_eq!(ast.0[1].type_hint.full, "float");
            assert!(ast.0[1].value.is_some());
            match ast.0[1].value.as_ref().unwrap() {
                Expression::Literal(x) => match x {
                    Literal::Float(y) => {
                        assert_eq!(*y, 2.4);
                    }
                    _ => panic!("Invalid literal!"),
                },
                _ => panic!("Invalid expression!"),
            }
        }

        #[test]
        fn two_one_with_default_value() {
            let result = CoriumParser::parse(Rule::ParameterList, "a char, x int = 10").unwrap();
            let ast = ParameterList::map(result);
            assert_eq!(ast.0.len(), 2);

            assert_eq!(ast.0[0].name.0, "a");
            assert_eq!(ast.0[0].type_hint.full, "char");
            assert!(ast.0[0].value.is_none());

            assert_eq!(ast.0[1].name.0, "x");
            assert_eq!(ast.0[1].type_hint.full, "int");
            assert!(ast.0[1].value.is_some());
            match ast.0[1].value.as_ref().unwrap() {
                Expression::Literal(x) => match x {
                    Literal::Int(y) => {
                        assert_eq!(*y, 10);
                    }
                    _ => panic!("Invalid literal!"),
                },
                _ => panic!("Invalid expression!"),
            }
        }
    }

    mod return_statement {
        use super::*;

        #[test]
        fn return_none() {
            let result = CoriumParser::parse(Rule::ReturnStatement, "return\n").unwrap();
            let ast = ReturnStatement::map(result);
            assert!(ast.0.is_none());
        }

        #[test]
        fn return_int() {
            let mut result = CoriumParser::parse(Rule::ReturnStatement, "return 10\n").unwrap();
            let ast = ReturnStatement::map(result);
            assert!(ast.0.is_some());
            match ast.0.unwrap() {
                Expression::Literal(x) => match x {
                    Literal::Int(y) => {
                        assert_eq!(y, 10)
                    }
                    _ => panic!("Invalid literal"),
                },
                _ => panic!("Invalid expression!"),
            }
        }

        #[test]
        fn return_float() {
            let mut result = CoriumParser::parse(Rule::ReturnStatement, "return -0.51\n").unwrap();
            let ast = ReturnStatement::map(result);
            assert!(ast.0.is_some());
            match ast.0.unwrap() {
                Expression::Literal(x) => match x {
                    Literal::Float(y) => {
                        assert_eq!(y, -0.51)
                    }
                    _ => panic!("Invalid literal"),
                },
                _ => panic!("Invalid expression!"),
            }
        }
    }

    mod local_variable {
        use super::*;

        #[test]
        fn int() {
            let result = CoriumParser::parse(Rule::LocalVariable, "let x = 10\n").unwrap();
            let ast = LocalVariable::map(result);
            assert_eq!(ast.name.0, "x");
            match ast.value {
                Expression::Literal(x) => match x {
                    Literal::Int(y) => {
                        assert_eq!(y, 10);
                    }
                    _ => unreachable!(),
                },
                _ => unreachable!(),
            }
            assert!(ast.type_hint.is_none());
        }

        #[test]
        fn float() {
            let mut result = CoriumParser::parse(Rule::LocalVariable, "let x = 10.0\n").unwrap();
            let ast = LocalVariable::map(result);
            assert_eq!(ast.name.0, "x");
            match ast.value {
                Expression::Literal(x) => match x {
                    Literal::Float(y) => {
                        assert_eq!(y, 10.0);
                    }
                    _ => unreachable!(),
                },
                _ => unreachable!(),
            }
            assert!(ast.type_hint.is_none());
        }

        #[test]
        fn char() {
            let mut result = CoriumParser::parse(Rule::LocalVariable, "let x = 'x'\n").unwrap();
            let ast = LocalVariable::map(result);
            assert_eq!(ast.name.0, "x");
            match ast.value {
                Expression::Literal(x) => match x {
                    Literal::Char(y) => {
                        assert_eq!(y, 'x');
                    }
                    _ => unreachable!(),
                },
                _ => unreachable!(),
            }
            assert!(ast.type_hint.is_none());
        }

        #[test]
        fn bool() {
            let mut result = CoriumParser::parse(Rule::LocalVariable, "let x = true\n").unwrap();
            let ast = LocalVariable::map(result);
            assert_eq!(ast.name.0, "x");
            match ast.value {
                Expression::Literal(x) => match x {
                    Literal::Bool(y) => {
                        assert!(y);
                    }
                    _ => unreachable!(),
                },
                _ => unreachable!(),
            }
            assert!(ast.type_hint.is_none());
        }

        #[test]
        fn string() {
            let mut result =
                CoriumParser::parse(Rule::LocalVariable, "let x = \"Name\"\n").unwrap();
            let ast = LocalVariable::map(result);
            assert_eq!(ast.name.0, "x");
            match ast.value {
                Expression::Literal(x) => match x {
                    Literal::String(y) => {
                        assert_eq!(y, "Name");
                    }
                    _ => unreachable!(),
                },
                _ => unreachable!(),
            }
            assert!(ast.type_hint.is_none());
        }

        #[test]
        fn type_int() {
            let mut result = CoriumParser::parse(Rule::LocalVariable, "let x int = 10\n").unwrap();
            let ast = LocalVariable::map(result);
            assert_eq!(ast.name.0, "x");
            match ast.value {
                Expression::Literal(x) => match x {
                    Literal::Int(y) => {
                        assert_eq!(y, 10);
                    }
                    _ => unreachable!(),
                },
                _ => unreachable!(),
            }
            assert!(ast.type_hint.is_some());
            assert_eq!(ast.type_hint.unwrap().full, "int");
        }

        #[test]
        fn type_float() {
            let mut result =
                CoriumParser::parse(Rule::LocalVariable, "let x float = 10.0\n").unwrap();
            let ast = LocalVariable::map(result);
            assert_eq!(ast.name.0, "x");
            match ast.value {
                Expression::Literal(x) => match x {
                    Literal::Float(y) => {
                        assert_eq!(y, 10.0);
                    }
                    _ => unreachable!(),
                },
                _ => unreachable!(),
            }
            assert!(ast.type_hint.is_some());
            assert_eq!(ast.type_hint.unwrap().full, "float");
        }

        #[test]
        fn type_char() {
            let mut result =
                CoriumParser::parse(Rule::LocalVariable, "let x char = 'x'\n").unwrap();
            let ast = LocalVariable::map(result);
            assert_eq!(ast.name.0, "x");
            match ast.value {
                Expression::Literal(x) => match x {
                    Literal::Char(y) => {
                        assert_eq!(y, 'x');
                    }
                    _ => unreachable!(),
                },
                _ => unreachable!(),
            }
            assert!(ast.type_hint.is_some());
            assert_eq!(ast.type_hint.unwrap().full, "char");
        }

        #[test]
        fn type_bool() {
            let mut result =
                CoriumParser::parse(Rule::LocalVariable, "let x bool = true\n").unwrap();
            let ast = LocalVariable::map(result);
            assert_eq!(ast.name.0, "x");
            match ast.value {
                Expression::Literal(x) => match x {
                    Literal::Bool(y) => {
                        assert!(y);
                    }
                    _ => unreachable!(),
                },
                _ => unreachable!(),
            }
            assert!(ast.type_hint.is_some());
            assert_eq!(ast.type_hint.unwrap().full, "bool");
        }

        #[test]
        fn type_string() {
            let mut result =
                CoriumParser::parse(Rule::LocalVariable, "let x string = \"Name\"\n").unwrap();
            let ast = LocalVariable::map(result);
            assert_eq!(ast.name.0, "x");
            match ast.value {
                Expression::Literal(x) => match x {
                    Literal::String(y) => {
                        assert_eq!(y, "Name");
                    }
                    _ => unreachable!(),
                },
                _ => unreachable!(),
            }
            assert!(ast.type_hint.is_some());
            assert_eq!(ast.type_hint.unwrap().full, "string");
        }
    }

    mod module {
        use super::*;

        #[test]
        fn simple() {
            let result = CoriumParser::parse(Rule::Module, "module MyPackage\n").unwrap();
            let ast = Module::map(result);
            assert_eq!(ast.0.full, "MyPackage");
            assert_eq!(ast.0.split.len(), 1);
            assert_eq!(ast.0.split[0], "MyPackage");
        }

        #[test]
        fn nested() {
            let result = CoriumParser::parse(Rule::Module, "module MyPackage.Class\n").unwrap();
            let ast = Module::map(result);
            assert_eq!(ast.0.full, "MyPackage.Class");
            assert_eq!(ast.0.split.len(), 2);
            assert_eq!(ast.0.split[0], "MyPackage");
            assert_eq!(ast.0.split[1], "Class");
        }

        #[test]
        fn nested2() {
            let result =
                CoriumParser::parse(Rule::Module, "module MyPackage.Class.StaticMember\n").unwrap();
            let ast = Module::map(result);
            assert_eq!(ast.0.full, "MyPackage.Class.StaticMember");
            assert_eq!(ast.0.split.len(), 3);
            assert_eq!(ast.0.split[0], "MyPackage");
            assert_eq!(ast.0.split[1], "Class");
            assert_eq!(ast.0.split[2], "StaticMember");
        }

        #[test]
        fn nested3() {
            let result =
                CoriumParser::parse(Rule::Module, "module MyPackage.Class.StaticMember.Field\n")
                    .unwrap();
            let ast = Module::map(result);
            assert_eq!(ast.0.full, "MyPackage.Class.StaticMember.Field");
            assert_eq!(ast.0.split.len(), 4);
            assert_eq!(ast.0.split[0], "MyPackage");
            assert_eq!(ast.0.split[1], "Class");
            assert_eq!(ast.0.split[2], "StaticMember");
            assert_eq!(ast.0.split[3], "Field");
        }
    }
}
