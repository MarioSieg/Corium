use crate::ast::{populators::*, *};
use crate::parser::*;

mod populators {
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
            assert!(matches!(ast, Literal::Float(2.5)));
        }

        #[test]
        fn int() {
            let result = CoriumParser::parse(Rule::Literal, "-10").unwrap();
            let ast = Literal::map(result);
            assert!(matches!(ast, Literal::Int(-10)));
        }

        #[test]
        fn boolean() {
            let result = CoriumParser::parse(Rule::Literal, "true").unwrap();
            let ast = Literal::map(result);
            assert!(matches!(ast, Literal::Bool(true)));
        }

        #[test]
        fn character() {
            let result = CoriumParser::parse(Rule::Literal, "'X'").unwrap();
            let ast = Literal::map(result);
            assert!(matches!(ast, Literal::Char('X')));
        }

        #[test]
        fn string() {
            let result = CoriumParser::parse(Rule::Literal, "\"Hallo zusammen ;)\"").unwrap();
            let ast = Literal::map(result);
            assert!(matches!(ast, Literal::String("Hallo zusammen ;)")));
        }

        #[test]
        fn string_empty() {
            let result = CoriumParser::parse(Rule::Literal, "\"\"").unwrap();
            let ast = Literal::map(result);
            assert!(matches!(ast, Literal::String("")));
        }
    }

    mod expression {
        use super::*;

        #[test]
        fn float_literal() {
            let result = CoriumParser::parse(Rule::Expression, "2.5").unwrap();
            let ast = Expression::map(result);
            assert!(matches!(ast, Expression::Literal(Literal::Float(2.5))));
        }

        #[test]
        fn int_literal() {
            let result = CoriumParser::parse(Rule::Expression, "10").unwrap();
            let ast = Expression::map(result);
            assert!(matches!(ast, Expression::Literal(Literal::Int(10))));
        }

        #[test]
        fn boolean_literal() {
            let result = CoriumParser::parse(Rule::Expression, "true").unwrap();
            let ast = Expression::map(result);
            assert!(matches!(ast, Expression::Literal(Literal::Bool(true))));
        }

        #[test]
        fn character_literal() {
            let result = CoriumParser::parse(Rule::Expression, "'X'").unwrap();
            let ast = Expression::map(result);
            assert!(matches!(ast, Expression::Literal(Literal::Char('X'))));
        }

        #[test]
        fn string_literal() {
            let result = CoriumParser::parse(Rule::Expression, "\"Hallo zusammen ;)\"").unwrap();
            let ast = Expression::map(result);
            assert!(matches!(
                ast,
                Expression::Literal(Literal::String("Hallo zusammen ;)"))
            ));
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
            assert!(matches!(
                ast.value.unwrap(),
                Expression::Literal(Literal::Int(10))
            ));
        }

        #[test]
        fn float_with_default_value() {
            let mut result = CoriumParser::parse(Rule::Parameter, "myParam float = 0.999").unwrap();
            let ast = Parameter::map(result);
            assert_eq!(ast.name.0, "myParam");
            assert_eq!(ast.type_hint.full, "float");
            assert!(ast.value.is_some());
            assert!(matches!(
                ast.value.unwrap(),
                Expression::Literal(Literal::Float(0.999))
            ));
        }

        #[test]
        fn bool_with_default_value() {
            let mut result = CoriumParser::parse(Rule::Parameter, "myParam bool = true").unwrap();
            let ast = Parameter::map(result);
            assert_eq!(ast.name.0, "myParam");
            assert_eq!(ast.type_hint.full, "bool");
            assert!(ast.value.is_some());
            assert!(matches!(
                ast.value.unwrap(),
                Expression::Literal(Literal::Bool(true))
            ));
        }

        #[test]
        fn char_with_default_value() {
            let mut result = CoriumParser::parse(Rule::Parameter, "myParam char = 'x'").unwrap();
            let ast = Parameter::map(result);
            assert_eq!(ast.name.0, "myParam");
            assert_eq!(ast.type_hint.full, "char");
            assert!(ast.value.is_some());
            assert!(matches!(
                ast.value.unwrap(),
                Expression::Literal(Literal::Char('x'))
            ));
        }

        #[test]
        fn string_with_default_value() {
            let mut result =
                CoriumParser::parse(Rule::Parameter, "myParam string = \"I luv u :3\"").unwrap();
            let ast = Parameter::map(result);
            assert_eq!(ast.name.0, "myParam");
            assert_eq!(ast.type_hint.full, "string");
            assert!(ast.value.is_some());
            assert!(matches!(
                ast.value.unwrap(),
                Expression::Literal(Literal::String("I luv u :3"))
            ));
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
            assert!(matches!(
                ast.0[0].value.as_ref().unwrap(),
                Expression::Literal(Literal::Int(10))
            ));
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
            assert!(matches!(
                ast.0[0].value.as_ref().unwrap(),
                Expression::Literal(Literal::Int(10))
            ));

            assert_eq!(ast.0[1].name.0, "y");
            assert_eq!(ast.0[1].type_hint.full, "float");
            assert!(ast.0[1].value.is_some());
            assert!(matches!(
                ast.0[1].value.as_ref().unwrap(),
                Expression::Literal(Literal::Float(2.4))
            ));
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
            assert!(matches!(
                ast.0[1].value.as_ref().unwrap(),
                Expression::Literal(Literal::Int(10))
            ));
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
            assert!(matches!(
                ast.0.unwrap(),
                Expression::Literal(Literal::Int(10))
            ));
        }

        #[test]
        fn return_float() {
            let mut result = CoriumParser::parse(Rule::ReturnStatement, "return -0.51\n").unwrap();
            let ast = ReturnStatement::map(result);
            assert!(ast.0.is_some());
            assert!(matches!(
                ast.0.unwrap(),
                Expression::Literal(Literal::Float(-0.51))
            ));
        }
    }

    mod local_variable {
        use super::*;

        #[test]
        fn int() {
            let result = CoriumParser::parse(Rule::LocalVariable, "let x = 10\n").unwrap();
            let ast = LocalVariable::map(result);
            assert_eq!(ast.name.0, "x");
            assert!(matches!(ast.value, Expression::Literal(Literal::Int(10))));
            assert!(ast.type_hint.is_none());
        }

        #[test]
        fn float() {
            let mut result = CoriumParser::parse(Rule::LocalVariable, "let x = 10.0\n").unwrap();
            let ast = LocalVariable::map(result);
            assert_eq!(ast.name.0, "x");
            assert!(matches!(
                ast.value,
                Expression::Literal(Literal::Float(10.0))
            ));
            assert!(ast.type_hint.is_none());
        }

        #[test]
        fn char() {
            let mut result = CoriumParser::parse(Rule::LocalVariable, "let x = 'x'\n").unwrap();
            let ast = LocalVariable::map(result);
            assert_eq!(ast.name.0, "x");
            assert!(matches!(ast.value, Expression::Literal(Literal::Char('x'))));
            assert!(ast.type_hint.is_none());
        }

        #[test]
        fn bool() {
            let mut result = CoriumParser::parse(Rule::LocalVariable, "let x = true\n").unwrap();
            let ast = LocalVariable::map(result);
            assert_eq!(ast.name.0, "x");
            assert!(matches!(
                ast.value,
                Expression::Literal(Literal::Bool(true))
            ));
            assert!(ast.type_hint.is_none());
        }

        #[test]
        fn string() {
            let mut result =
                CoriumParser::parse(Rule::LocalVariable, "let x = \"Name\"\n").unwrap();
            let ast = LocalVariable::map(result);
            assert_eq!(ast.name.0, "x");
            assert!(matches!(
                ast.value,
                Expression::Literal(Literal::String("Name"))
            ));
            assert!(ast.type_hint.is_none());
        }

        #[test]
        fn type_int() {
            let mut result = CoriumParser::parse(Rule::LocalVariable, "let x int = 10\n").unwrap();
            let ast = LocalVariable::map(result);
            assert_eq!(ast.name.0, "x");
            assert!(matches!(ast.value, Expression::Literal(Literal::Int(10))));
            assert!(ast.type_hint.is_some());
            assert_eq!(ast.type_hint.unwrap().full, "int");
        }

        #[test]
        fn type_float() {
            let mut result =
                CoriumParser::parse(Rule::LocalVariable, "let x float = 10.0\n").unwrap();
            let ast = LocalVariable::map(result);
            assert_eq!(ast.name.0, "x");
            assert!(matches!(
                ast.value,
                Expression::Literal(Literal::Float(10.0))
            ));
            assert!(ast.type_hint.is_some());
            assert_eq!(ast.type_hint.unwrap().full, "float");
        }

        #[test]
        fn type_char() {
            let mut result =
                CoriumParser::parse(Rule::LocalVariable, "let x char = 'x'\n").unwrap();
            let ast = LocalVariable::map(result);
            assert_eq!(ast.name.0, "x");
            assert!(matches!(ast.value, Expression::Literal(Literal::Char('x'))));
            assert!(ast.type_hint.is_some());
            assert_eq!(ast.type_hint.unwrap().full, "char");
        }

        #[test]
        fn type_bool() {
            let mut result =
                CoriumParser::parse(Rule::LocalVariable, "let x bool = true\n").unwrap();
            let ast = LocalVariable::map(result);
            assert_eq!(ast.name.0, "x");
            assert!(matches!(
                ast.value,
                Expression::Literal(Literal::Bool(true))
            ));
            assert!(ast.type_hint.is_some());
            assert_eq!(ast.type_hint.unwrap().full, "bool");
        }

        #[test]
        fn type_string() {
            let mut result =
                CoriumParser::parse(Rule::LocalVariable, "let x string = \"Name\"\n").unwrap();
            let ast = LocalVariable::map(result);
            assert_eq!(ast.name.0, "x");
            assert!(matches!(
                ast.value,
                Expression::Literal(Literal::String("Name"))
            ));
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

    mod function_statement {
        use super::*;

        #[test]
        fn local_var() {
            let result = CoriumParser::parse(Rule::FunctionStatement, "let x = 10\n").unwrap();
            let ast = FunctionStatement::map(result);
            assert!(matches!(
                ast,
                FunctionStatement::LocalVariable(LocalVariable {
                    name: Identifier("x"),
                    type_hint: None,
                    value: Expression::Literal(Literal::Int(10))
                })
            ));
        }

        #[test]
        fn return_statement() {
            let result = CoriumParser::parse(Rule::FunctionStatement, "return\n").unwrap();
            let ast = FunctionStatement::map(result);
            assert!(matches!(
                ast,
                FunctionStatement::ReturnStatement(ReturnStatement(None))
            ));
        }

        #[test]
        fn return_statement2() {
            let result = CoriumParser::parse(Rule::FunctionStatement, "return true\n").unwrap();
            let ast = FunctionStatement::map(result);
            assert!(matches!(
                ast,
                FunctionStatement::ReturnStatement(ReturnStatement(Some(Expression::Literal(
                    Literal::Bool(true)
                ))))
            ));
        }
    }

    mod block {
        use super::*;

        #[test]
        fn variables() {
            let source = concat!(
                "let x = 10\n",
                "let y bool = true\n",
                "let name = \"Hey\"\n",
                "let z char = 'y'\n",
                "let zw float = 2.33225\n"
            );
            let result = CoriumParser::parse(Rule::Block, source).unwrap();
            let ast = Block::map(result);
            assert_eq!(ast.0.len(), 5);

            assert!(matches!(
                &ast.0[0],
                FunctionStatement::LocalVariable(LocalVariable {
                    name: Identifier("x"),
                    value: Expression::Literal(Literal::Int(10)),
                    type_hint: None
                })
            ));

            let name = QualifiedName::from("bool");
            assert!(matches!(
                &ast.0[1],
                FunctionStatement::LocalVariable(LocalVariable {
                    name: Identifier("y"),
                    value: Expression::Literal(Literal::Bool(true)),
                    type_hint: Some(name)
                })
            ));

            assert!(matches!(
                &ast.0[2],
                FunctionStatement::LocalVariable(LocalVariable {
                    name: Identifier("name"),
                    value: Expression::Literal(Literal::String("Hey")),
                    type_hint: None
                })
            ));

            let name = QualifiedName::from("char");
            assert!(matches!(
                &ast.0[3],
                FunctionStatement::LocalVariable(LocalVariable {
                    name: Identifier("z"),
                    value: Expression::Literal(Literal::Char('y')),
                    type_hint: Some(name)
                })
            ));

            let name = QualifiedName::from("float");
            assert!(matches!(
                &ast.0[4],
                FunctionStatement::LocalVariable(LocalVariable {
                    name: Identifier("zw"),
                    value: Expression::Literal(Literal::Float(2.33225)),
                    type_hint: Some(name)
                })
            ));
        }

        #[test]
        fn returns() {
            let source = concat!(
                "return\n",
                "return true\n",
                "return \"Hey\"\n",
                "return 2.33225\n"
            );
            let result = CoriumParser::parse(Rule::Block, source).unwrap();
            let ast = Block::map(result);
            assert_eq!(ast.0.len(), 4);
            assert!(matches!(
                &ast.0[0],
                FunctionStatement::ReturnStatement(ReturnStatement(None))
            ));
            assert!(matches!(
                &ast.0[1],
                FunctionStatement::ReturnStatement(ReturnStatement(Some(Expression::Literal(
                    Literal::Bool(true)
                ))))
            ));
            assert!(matches!(
                &ast.0[2],
                FunctionStatement::ReturnStatement(ReturnStatement(Some(Expression::Literal(
                    Literal::String("Hey")
                ))))
            ));
            assert!(matches!(
                &ast.0[3],
                FunctionStatement::ReturnStatement(ReturnStatement(Some(Expression::Literal(
                    Literal::Float(2.33225)
                ))))
            ));
        }

        #[test]
        fn mixed() {
            let source = concat!(
                "let x = 10\n",
                "return true\n",
                "return \"Hey\"\n",
                "let z bool = true\n",
                "let z float = 2.33225\n"
            );
            let result = CoriumParser::parse(Rule::Block, source).unwrap();
            let ast = Block::map(result);
            assert_eq!(ast.0.len(), 5);
            assert!(matches!(
                &ast.0[0],
                FunctionStatement::LocalVariable(LocalVariable {
                    name: Identifier("x"),
                    value: Expression::Literal(Literal::Int(10)),
                    type_hint: None
                })
            ));
            assert!(matches!(
                &ast.0[1],
                FunctionStatement::ReturnStatement(ReturnStatement(Some(Expression::Literal(
                    Literal::Bool(true)
                ))))
            ));
            assert!(matches!(
                &ast.0[2],
                FunctionStatement::ReturnStatement(ReturnStatement(Some(Expression::Literal(
                    Literal::String("Hey")
                ))))
            ));
            let name = QualifiedName::from("bool");
            assert!(matches!(
                &ast.0[3],
                FunctionStatement::LocalVariable(LocalVariable {
                    name: Identifier("z"),
                    value: Expression::Literal(Literal::Bool(true)),
                    type_hint: Some(name)
                })
            ));
            let name = QualifiedName::from("float");
            assert!(matches!(
                &ast.0[4],
                FunctionStatement::LocalVariable(LocalVariable {
                    name: Identifier("z"),
                    value: Expression::Literal(Literal::Float(2.33225)),
                    type_hint: Some(name)
                })
            ));
        }
    }

    mod function_signature {
        use super::*;

        #[test]
        fn simple() {
            let result = CoriumParser::parse(Rule::FunctionSignature, "fun f()").unwrap();
            let ast = FunctionSignature::map(result);
            assert_eq!(ast.name.0, "f");
            assert!(ast.parameters.is_none());
            assert!(ast.return_type.is_none());
        }

        #[test]
        fn return_type() {
            let result = CoriumParser::parse(Rule::FunctionSignature, "fun f() int").unwrap();
            let ast = FunctionSignature::map(result);
            assert_eq!(ast.name.0, "f");
            assert!(ast.parameters.is_none());
            assert!(ast.return_type.is_some());
            let name = QualifiedName::from("int");
            assert!(matches!(ast.return_type.unwrap(), name));
        }

        #[test]
        fn param() {
            let result = CoriumParser::parse(Rule::FunctionSignature, "fun f(x float)").unwrap();
            let ast = FunctionSignature::map(result);
            assert_eq!(ast.name.0, "f");
            assert!(ast.parameters.is_some());
            assert_eq!(ast.parameters.as_ref().unwrap().0.len(), 1);
            assert!(ast.return_type.is_none());
            let name = QualifiedName::from("float");
            assert!(matches!(
                &ast.parameters.as_ref().unwrap().0[0],
                Parameter {
                    name: Identifier("x"),
                    type_hint: name,
                    value: None
                }
            ));
        }

        #[test]
        fn params() {
            let result = CoriumParser::parse(
                Rule::FunctionSignature,
                "fun proc(x float, name string, ok bool = true)",
            )
            .unwrap();
            let ast = FunctionSignature::map(result);
            assert_eq!(ast.name.0, "proc");
            assert!(ast.parameters.is_some());
            assert_eq!(ast.parameters.as_ref().unwrap().0.len(), 3);
            assert!(ast.return_type.is_none());
            let name = QualifiedName::from("float");
            assert!(matches!(
                &ast.parameters.as_ref().unwrap().0[0],
                Parameter {
                    name: Identifier("x"),
                    type_hint: name,
                    value: None
                }
            ));
            let name = QualifiedName::from("string");
            assert!(matches!(
                &ast.parameters.as_ref().unwrap().0[1],
                Parameter {
                    name: Identifier("name"),
                    type_hint: name,
                    value: None
                }
            ));
            let name = QualifiedName::from("bool");
            assert!(matches!(
                &ast.parameters.as_ref().unwrap().0[2],
                Parameter {
                    name: Identifier("ok"),
                    type_hint: name,
                    value: Some(Expression::Literal(Literal::Bool(true)))
                }
            ));
        }

        #[test]
        fn param_ret() {
            let result =
                CoriumParser::parse(Rule::FunctionSignature, "fun f(x float) float").unwrap();
            let ast = FunctionSignature::map(result);
            assert_eq!(ast.name.0, "f");
            assert!(ast.parameters.is_some());
            assert_eq!(ast.parameters.as_ref().unwrap().0.len(), 1);
            assert!(ast.return_type.is_some());
            let name = QualifiedName::from("float");
            assert!(matches!(ast.return_type.unwrap(), name));
            let name = QualifiedName::from("float");
            assert!(matches!(
                &ast.parameters.as_ref().unwrap().0[0],
                Parameter {
                    name: Identifier("x"),
                    type_hint: name,
                    value: None
                }
            ));
        }
    }

    mod native_function {
        use super::*;

        #[test]
        fn simple() {
            let result = CoriumParser::parse(Rule::NativeFunction, "native fun f()\n").unwrap();
            let ast = NativeFunction::map(result);
            assert_eq!(ast.signature.name.0, "f");
            assert!(ast.signature.parameters.is_none());
            assert!(ast.signature.return_type.is_none());
        }

        #[test]
        fn return_type() {
            let result = CoriumParser::parse(Rule::NativeFunction, "native fun f() int\n").unwrap();
            let ast = NativeFunction::map(result);
            assert_eq!(ast.signature.name.0, "f");
            assert!(ast.signature.parameters.is_none());
            assert!(ast.signature.return_type.is_some());
            let name = QualifiedName::from("int");
            assert!(matches!(ast.signature.return_type.unwrap(), name));
        }

        #[test]
        fn param() {
            let result =
                CoriumParser::parse(Rule::NativeFunction, "native fun f(x float)\n").unwrap();
            let ast = NativeFunction::map(result);
            assert_eq!(ast.signature.name.0, "f");
            assert!(ast.signature.parameters.is_some());
            assert_eq!(ast.signature.parameters.as_ref().unwrap().0.len(), 1);
            assert!(ast.signature.return_type.is_none());
            let name = QualifiedName::from("float");
            assert!(matches!(
                &ast.signature.parameters.as_ref().unwrap().0[0],
                Parameter {
                    name: Identifier("x"),
                    type_hint: name,
                    value: None
                }
            ));
        }

        #[test]
        fn params() {
            let result = CoriumParser::parse(
                Rule::NativeFunction,
                "native fun proc(x float, name string, ok bool = true)\n",
            )
            .unwrap();
            let ast = NativeFunction::map(result);
            assert_eq!(ast.signature.name.0, "proc");
            assert!(ast.signature.parameters.is_some());
            assert_eq!(ast.signature.parameters.as_ref().unwrap().0.len(), 3);
            assert!(ast.signature.return_type.is_none());
            let name = QualifiedName::from("float");
            assert!(matches!(
                &ast.signature.parameters.as_ref().unwrap().0[0],
                Parameter {
                    name: Identifier("x"),
                    type_hint: name,
                    value: None
                }
            ));
            let name = QualifiedName::from("string");
            assert!(matches!(
                &ast.signature.parameters.as_ref().unwrap().0[1],
                Parameter {
                    name: Identifier("name"),
                    type_hint: name,
                    value: None
                }
            ));
            let name = QualifiedName::from("bool");
            assert!(matches!(
                &ast.signature.parameters.as_ref().unwrap().0[2],
                Parameter {
                    name: Identifier("ok"),
                    type_hint: name,
                    value: Some(Expression::Literal(Literal::Bool(true)))
                }
            ));
        }

        #[test]
        fn param_ret() {
            let result =
                CoriumParser::parse(Rule::NativeFunction, "native fun f(x float) float\n").unwrap();
            let ast = NativeFunction::map(result);
            assert_eq!(ast.signature.name.0, "f");
            assert!(ast.signature.parameters.is_some());
            assert_eq!(ast.signature.parameters.as_ref().unwrap().0.len(), 1);
            assert!(ast.signature.return_type.is_some());
            let name = QualifiedName::from("float");
            assert!(matches!(ast.signature.return_type.unwrap(), name));
            let name = QualifiedName::from("float");
            assert!(matches!(
                &ast.signature.parameters.as_ref().unwrap().0[0],
                Parameter {
                    name: Identifier("x"),
                    type_hint: name,
                    value: None
                }
            ));
        }
    }

    mod function {
        use super::*;

        #[test]
        fn simple() {
            let result = CoriumParser::parse(Rule::Function, "fun f() {\n}\n").unwrap();
            let ast = Function::map(result);
            assert_eq!(ast.signature.name, Identifier("f"));
            assert!(ast.signature.return_type.is_none());
            assert!(ast.signature.parameters.is_none());
            assert!(ast.block.0.is_empty());
        }

        #[test]
        fn return_type() {
            let result = CoriumParser::parse(Rule::Function, "fun f() int {\n}\n").unwrap();
            let ast = Function::map(result);
            assert_eq!(ast.signature.name, Identifier("f"));
            assert!(ast.signature.return_type.is_some());
            let name = QualifiedName::from("int");
            assert!(matches!(ast.signature.return_type.as_ref().unwrap(), name));
            assert!(ast.signature.parameters.is_none());
            assert!(ast.block.0.is_empty());
        }

        #[test]
        fn param() {
            let result = CoriumParser::parse(Rule::Function, "fun f(x float) {\n}\n").unwrap();
            let ast = Function::map(result);
            assert!(ast.block.0.is_empty());
            assert_eq!(ast.signature.name.0, "f");
            assert!(ast.signature.parameters.is_some());
            assert_eq!(ast.signature.parameters.as_ref().unwrap().0.len(), 1);
            assert!(ast.signature.return_type.is_none());
            let name = QualifiedName::from("float");
            assert!(matches!(
                &ast.signature.parameters.as_ref().unwrap().0[0],
                Parameter {
                    name: Identifier("x"),
                    type_hint: name,
                    value: None
                }
            ));
        }

        #[test]
        fn params() {
            let result = CoriumParser::parse(
                Rule::Function,
                "fun proc(x float, name string, ok bool = true) {\n}\n",
            )
            .unwrap();
            let ast = Function::map(result);
            assert!(ast.block.0.is_empty());
            assert_eq!(ast.signature.name.0, "proc");
            assert!(ast.signature.parameters.is_some());
            assert_eq!(ast.signature.parameters.as_ref().unwrap().0.len(), 3);
            assert!(ast.signature.return_type.is_none());
            let name = QualifiedName::from("float");
            assert!(matches!(
                &ast.signature.parameters.as_ref().unwrap().0[0],
                Parameter {
                    name: Identifier("x"),
                    type_hint: name,
                    value: None
                }
            ));
            let name = QualifiedName::from("string");
            assert!(matches!(
                &ast.signature.parameters.as_ref().unwrap().0[1],
                Parameter {
                    name: Identifier("name"),
                    type_hint: name,
                    value: None
                }
            ));
            let name = QualifiedName::from("bool");
            assert!(matches!(
                &ast.signature.parameters.as_ref().unwrap().0[2],
                Parameter {
                    name: Identifier("ok"),
                    type_hint: name,
                    value: Some(Expression::Literal(Literal::Bool(true)))
                }
            ));
        }

        #[test]
        fn param_ret() {
            let result =
                CoriumParser::parse(Rule::Function, "fun f(x float) float {\n}\n").unwrap();
            let ast = Function::map(result);
            assert!(ast.block.0.is_empty());
            assert_eq!(ast.signature.name.0, "f");
            assert!(ast.signature.parameters.is_some());
            assert_eq!(ast.signature.parameters.as_ref().unwrap().0.len(), 1);
            assert!(ast.signature.return_type.is_some());
            let name = QualifiedName::from("float");
            assert!(matches!(ast.signature.return_type.unwrap(), name));
            let name = QualifiedName::from("float");
            assert!(matches!(
                &ast.signature.parameters.as_ref().unwrap().0[0],
                Parameter {
                    name: Identifier("x"),
                    type_hint: name,
                    value: None
                }
            ));
        }

        #[test]
        fn return_statement() {
            let result = CoriumParser::parse(Rule::Function, "fun f() {\nreturn 10\n}\n").unwrap();
            let ast = Function::map(result);
            assert_eq!(ast.signature.name.0, "f");
            assert!(ast.signature.parameters.is_none());
            assert!(ast.signature.return_type.is_none());
            assert_eq!(ast.block.0.len(), 1);
            assert!(matches!(
                &ast.block.0[0],
                FunctionStatement::ReturnStatement(ReturnStatement(Some(Expression::Literal(
                    Literal::Int(10)
                ))))
            ))
        }

        #[test]
        fn complex() {
            let src = concat!(
                "fun compute(x int = 0) int {\n",
                "    let result = \"LOL\"\n",
                "    return 23\n",
                "}\n"
            );
            let result = CoriumParser::parse(Rule::Function, src).unwrap();
            let ast = Function::map(result);
            assert_eq!(ast.signature.name.0, "compute");
            assert!(ast.signature.parameters.is_some());
            assert!(ast.signature.return_type.is_some());
            assert_eq!(ast.block.0.len(), 2);
            let name = QualifiedName::from("int");
            assert!(matches!(
                &ast.signature.parameters.as_ref().unwrap().0[0],
                Parameter {
                    name: Identifier("x"),
                    type_hint: name,
                    value: Some(Expression::Literal(Literal::Int(0)))
                }
            ));
            assert_eq!(ast.signature.return_type.unwrap().full, "int");
            assert!(matches!(
                &ast.block.0[0],
                FunctionStatement::LocalVariable(LocalVariable {
                    name: Identifier("result"),
                    type_hint: None,
                    value: Expression::Literal(Literal::String("LOL"))
                })
            ));
            assert!(matches!(
                &ast.block.0[1],
                FunctionStatement::ReturnStatement(ReturnStatement(Some(Expression::Literal(
                    Literal::Int(23)
                ))))
            ));
        }
    }
}
