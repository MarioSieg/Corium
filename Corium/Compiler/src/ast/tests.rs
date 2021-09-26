use crate::ast::{mapping::*, *};
use crate::parser::*;

mod mapping {
    use super::*;

    mod identifier {
        use super::*;

        #[test]
        fn alphanumeric() {
            let result = CoriumParser::parse(Rule::Identifier, "MyClass").unwrap();
            let ast = Identifier::map(result).unwrap();
            assert_eq!(ast.0, "MyClass");
        }

        #[test]
        fn mixed() {
            let result = CoriumParser::parse(Rule::Identifier, "My2Class32LOl").unwrap();
            let ast = Identifier::map(result).unwrap();
            assert_eq!(ast.0, "My2Class32LOl");
        }

        #[test]
        fn numeric() {
            let result = CoriumParser::parse(Rule::Identifier, "X278247842877284").unwrap();
            let ast = Identifier::map(result).unwrap();
            assert_eq!(ast.0, "X278247842877284");
        }
    }

    mod qualified_name {
        use super::*;

        #[test]
        fn simple() {
            let result = CoriumParser::parse(Rule::QualifiedName, "MyPackage").unwrap();
            let ast = QualifiedName::map(result).unwrap();
            assert_eq!(ast.full, "MyPackage");
            assert_eq!(ast.split.len(), 1);
            assert_eq!(ast.split[0], "MyPackage");
        }

        #[test]
        fn nested() {
            let result = CoriumParser::parse(Rule::QualifiedName, "MyPackage.Class").unwrap();
            let ast = QualifiedName::map(result).unwrap();
            assert_eq!(ast.full, "MyPackage.Class");
            assert_eq!(ast.split.len(), 2);
            assert_eq!(ast.split[0], "MyPackage");
            assert_eq!(ast.split[1], "Class");
        }

        #[test]
        fn nested2() {
            let result =
                CoriumParser::parse(Rule::QualifiedName, "MyPackage.Class.StaticMember").unwrap();
            let ast = QualifiedName::map(result).unwrap();
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
            let ast = QualifiedName::map(result).unwrap();
            assert_eq!(ast.full, "MyPackage.Class.StaticMember.Field");
            assert_eq!(ast.split.len(), 4);
            assert_eq!(ast.split[0], "MyPackage");
            assert_eq!(ast.split[1], "Class");
            assert_eq!(ast.split[2], "StaticMember");
            assert_eq!(ast.split[3], "Field");
        }
    }

    mod module {
        use super::*;

        #[test]
        fn simple() {
            let result = CoriumParser::parse(Rule::Module, "module MyPackage\n").unwrap();
            let ast = Module::map(result).unwrap();
            assert_eq!(ast.0.full, "MyPackage");
            assert_eq!(ast.0.split.len(), 1);
            assert_eq!(ast.0.split[0], "MyPackage");
        }

        #[test]
        fn nested() {
            let result = CoriumParser::parse(Rule::Module, "module MyPackage.Class\n").unwrap();
            let ast = Module::map(result).unwrap();
            assert_eq!(ast.0.full, "MyPackage.Class");
            assert_eq!(ast.0.split.len(), 2);
            assert_eq!(ast.0.split[0], "MyPackage");
            assert_eq!(ast.0.split[1], "Class");
        }

        #[test]
        fn nested2() {
            let result =
                CoriumParser::parse(Rule::Module, "module MyPackage.Class.StaticMember\n").unwrap();
            let ast = Module::map(result).unwrap();
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
            let ast = Module::map(result).unwrap();
            assert_eq!(ast.0.full, "MyPackage.Class.StaticMember.Field");
            assert_eq!(ast.0.split.len(), 4);
            assert_eq!(ast.0.split[0], "MyPackage");
            assert_eq!(ast.0.split[1], "Class");
            assert_eq!(ast.0.split[2], "StaticMember");
            assert_eq!(ast.0.split[3], "Field");
        }
    }

    mod literal {
        use super::*;

        #[test]
        fn float() {
            let result = CoriumParser::parse(Rule::Literal, "2.5").unwrap();
            let ast = Literal::map(result).unwrap();
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
            let ast = Literal::map(result).unwrap();
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
            let ast = Literal::map(result).unwrap();
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
            let ast = Literal::map(result).unwrap();
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
            let ast = Literal::map(result).unwrap();
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
            let ast = Literal::map(result).unwrap();
            match ast {
                Literal::String(x) => {
                    assert!(x.is_empty());
                }
                _ => panic!("Invalid literal type!"),
            }
        }
    }
}
