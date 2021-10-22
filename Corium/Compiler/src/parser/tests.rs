use super::*;

mod rules {
    use super::*;

    mod char {
        use super::*;

        mod valid {
            use super::*;

            #[test]
            fn letter() {
                let result = CoriumParser::parse(Rule::Char, "A").unwrap().as_str();
                assert_eq!(result, "A");
            }

            #[test]
            fn number() {
                let result = CoriumParser::parse(Rule::Char, "3").unwrap().as_str();
                assert_eq!(result, "3");
            }

            #[test]
            fn special() {
                let result = CoriumParser::parse(Rule::Char, "$").unwrap().as_str();
                assert_eq!(result, "$");
            }

            #[test]
            fn unicode() {
                let result = CoriumParser::parse(Rule::Char, "ö").unwrap().as_str();
                assert_eq!(result, "ö");
            }

            #[test]
            fn unicode_2() {
                let result = CoriumParser::parse(Rule::Char, "글").unwrap().as_str();
                assert_eq!(result, "글");
            }

            #[test]
            fn unicode_3() {
                let result = CoriumParser::parse(Rule::Char, "中").unwrap().as_str();
                assert_eq!(result, "中");
            }

            #[test]
            fn quotation_mark() {
                let result = CoriumParser::parse(Rule::Char, r#"\""#).unwrap().as_str();
                assert_eq!(result, r#"\""#);
            }

            #[test]
            fn escaped_backslash() {
                let result = CoriumParser::parse(Rule::Char, r#"\\"#).unwrap().as_str();
                assert_eq!(result, r#"\\"#);
            }

            #[test]
            fn slash() {
                let result = CoriumParser::parse(Rule::Char, "/").unwrap().as_str();
                assert_eq!(result, "/");
            }

            #[test]
            fn newline() {
                let result = CoriumParser::parse(Rule::Char, r#"\n"#).unwrap().as_str();
                assert_eq!(result, r#"\n"#);
            }

            #[test]
            fn carriage_return() {
                let result = CoriumParser::parse(Rule::Char, r#"\r"#).unwrap().as_str();
                assert_eq!(result, r#"\r"#);
            }

            #[test]
            fn horizontal_tab() {
                let result = CoriumParser::parse(Rule::Char, r#"\t"#).unwrap().as_str();
                assert_eq!(result, r#"\t"#);
            }

            #[test]
            fn unicode_scalar() {
                let result = CoriumParser::parse(Rule::Char, r#"\u00000000"#)
                    .unwrap()
                    .as_str();
                assert_eq!(result, r#"\u00000000"#);
            }

            #[test]
            fn unicode_scalar2() {
                let result = CoriumParser::parse(Rule::Char, r#"\uFFFFFFFF"#)
                    .unwrap()
                    .as_str();
                assert_eq!(result, r#"\uFFFFFFFF"#);
            }

            #[test]
            fn unicode_scalar3() {
                let result = CoriumParser::parse(Rule::Char, r#"\uABABABAB"#)
                    .unwrap()
                    .as_str();
                assert_eq!(result, r#"\uABABABAB"#);
            }

            #[test]
            fn unicode_scalar4() {
                let result = CoriumParser::parse(Rule::Char, r#"\u123456AB"#)
                    .unwrap()
                    .as_str();
                assert_eq!(result, r#"\u123456AB"#);
            }
        }

        mod invalid {
            use super::*;

            #[test]
            fn escape() {
                let result = CoriumParser::parse(Rule::Char, r#"\A"#);
                assert!(result.is_err());
            }

            #[test]
            fn escape2() {
                let result = CoriumParser::parse(Rule::Char, r#""A"#);
                assert!(result.is_err());
            }
        }
    }

    mod identifier {
        use super::*;

        mod valid {
            use super::*;

            #[test]
            fn alphanumeric() {
                let result = CoriumParser::parse(Rule::Identifier, "MyClass")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "MyClass");
            }

            #[test]
            fn mixed() {
                let result = CoriumParser::parse(Rule::Identifier, "My2Class32LOl")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "My2Class32LOl");
            }

            #[test]
            fn numeric() {
                let result = CoriumParser::parse(Rule::Identifier, "X278247842877284")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "X278247842877284");
            }
        }

        mod invalid {
            use super::*;

            #[test]
            fn numeric() {
                let result = CoriumParser::parse(Rule::Identifier, "1");
                assert!(result.is_err());
            }

            #[test]
            fn numeric2() {
                let result = CoriumParser::parse(Rule::Identifier, "3MyClass");
                assert!(result.is_err());
            }

            #[test]
            fn numeric3() {
                let result = CoriumParser::parse(Rule::Identifier, "0MyClass");
                assert!(result.is_err());
            }

            #[test]
            fn numeric4() {
                let result = CoriumParser::parse(Rule::Identifier, "-10MyClass");
                assert!(result.is_err());
            }

            #[test]
            fn symbol() {
                let result = CoriumParser::parse(Rule::Identifier, "&MyClass");
                assert!(result.is_err());
            }

            #[test]
            fn symbol2() {
                let result = CoriumParser::parse(Rule::Identifier, "+MyClass");
                assert!(result.is_err());
            }

            #[test]
            fn symbol3() {
                let result = CoriumParser::parse(Rule::Identifier, "*MyClass");
                assert!(result.is_err());
            }

            #[test]
            fn symbol4() {
                let result = CoriumParser::parse(Rule::Identifier, "#MyClass");
                assert!(result.is_err());
            }

            #[test]
            fn symbol5() {
                let result = CoriumParser::parse(Rule::Identifier, "\"MyClass");
                assert!(result.is_err());
            }
        }
    }

    mod qualified_name {
        use super::*;

        mod valid {
            use super::*;

            #[test]
            fn simple() {
                let result = CoriumParser::parse(Rule::QualifiedName, "MyPackage")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "MyPackage");
            }

            #[test]
            fn nested() {
                let result = CoriumParser::parse(Rule::QualifiedName, "MyPackage.Class")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "MyPackage.Class");
            }

            #[test]
            fn nested2() {
                let result =
                    CoriumParser::parse(Rule::QualifiedName, "MyPackage.Class.StaticMember")
                        .unwrap()
                        .as_str();
                assert_eq!(result, "MyPackage.Class.StaticMember");
            }

            #[test]
            fn nested3() {
                let result =
                    CoriumParser::parse(Rule::QualifiedName, "MyPackage.Class.StaticMember.Field")
                        .unwrap()
                        .as_str();
                assert_eq!(result, "MyPackage.Class.StaticMember.Field");
            }
        }

        mod invalid {
            use super::*;

            #[test]
            fn numeric() {
                let result = CoriumParser::parse(Rule::QualifiedName, "+MyPackage");
                assert!(result.is_err());
            }

            #[test]
            fn missing_subpackage() {
                let result = CoriumParser::parse(Rule::QualifiedName, "MyPackage.")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "MyPackage");
            }

            #[test]
            fn nested_numeric() {
                let result = CoriumParser::parse(Rule::QualifiedName, "MyPackage.10Class")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "MyPackage");
            }

            #[test]
            fn no_names() {
                let result = CoriumParser::parse(Rule::QualifiedName, ".");
                assert!(result.is_err());
            }

            #[test]
            fn missing_super_package() {
                let result = CoriumParser::parse(Rule::QualifiedName, ".MyPackage");
                assert!(result.is_err());
            }

            #[test]
            fn numeric_subpackage() {
                let result = CoriumParser::parse(Rule::QualifiedName, "MyPackage.0")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "MyPackage");
            }

            #[test]
            fn dots() {
                let result = CoriumParser::parse(Rule::QualifiedName, "MyPackage.X..y")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "MyPackage.X");
            }

            #[test]
            fn missing_subpackage_nested() {
                let result = CoriumParser::parse(Rule::QualifiedName, "MyPackage.Class.")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "MyPackage.Class");
            }
        }
    }

    mod string_literal {
        use super::*;

        mod valid {
            use super::*;

            #[test]
            fn text() {
                let result =
                    CoriumParser::parse(Rule::StringLiteral, r#""Hallo :) das ist ein String!""#)
                        .unwrap()
                        .as_str();
                assert_eq!(result, r#""Hallo :) das ist ein String!""#);
            }

            #[test]
            fn char_scalars() {
                let result = CoriumParser::parse(
                    Rule::StringLiteral,
                    r#""Hallo :) \u00000000 \uFAFAFAFA \uFFFFFFFF \uABCDEFAF""#,
                )
                .unwrap()
                .as_str();
                assert_eq!(
                    result,
                    r#""Hallo :) \u00000000 \uFAFAFAFA \uFFFFFFFF \uABCDEFAF""#
                );
            }

            #[test]
            fn empty() {
                let result = CoriumParser::parse(Rule::StringLiteral, r#""""#)
                    .unwrap()
                    .as_str();
                assert_eq!(result, r#""""#);
            }
        }

        mod invalid {
            use super::*;

            #[test]
            fn quotation_mark_mismatch() {
                let result = CoriumParser::parse(Rule::StringLiteral, r#"""#);
                assert!(result.is_err());
            }

            #[test]
            fn quotation_mark_invalid() {
                let result = CoriumParser::parse(Rule::StringLiteral, r#""!"#);
                assert!(result.is_err());
            }

            #[test]
            fn quotation_mark_invalid2() {
                let result = CoriumParser::parse(Rule::StringLiteral, r#"A""#);
                assert!(result.is_err());
            }

            #[test]
            fn empty() {
                let result = CoriumParser::parse(Rule::StringLiteral, r#""#);
                assert!(result.is_err());
            }
        }
    }

    mod char_literal {
        use super::*;

        mod valid {
            use super::*;

            #[test]
            fn letter() {
                let result = CoriumParser::parse(Rule::CharLiteral, "'A'")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "'A'");
            }

            #[test]
            fn number() {
                let result = CoriumParser::parse(Rule::CharLiteral, "'3'")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "'3'");
            }

            #[test]
            fn special() {
                let result = CoriumParser::parse(Rule::CharLiteral, "'$'")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "'$'");
            }

            #[test]
            fn unicode() {
                let result = CoriumParser::parse(Rule::CharLiteral, "'ö'")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "'ö'");
            }

            #[test]
            fn unicode_2() {
                let result = CoriumParser::parse(Rule::CharLiteral, "'글'")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "'글'");
            }

            #[test]
            fn unicode_3() {
                let result = CoriumParser::parse(Rule::CharLiteral, "'中'")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "'中'");
            }

            #[test]
            fn quotation_mark() {
                let result = CoriumParser::parse(Rule::CharLiteral, r#"'\"'"#)
                    .unwrap()
                    .as_str();
                assert_eq!(result, r#"'\"'"#);
            }

            #[test]
            fn escaped_backslash() {
                let result = CoriumParser::parse(Rule::CharLiteral, r#"'\\'"#)
                    .unwrap()
                    .as_str();
                assert_eq!(result, r#"'\\'"#);
            }

            #[test]
            fn slash() {
                let result = CoriumParser::parse(Rule::CharLiteral, "'/'")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "'/'");
            }

            #[test]
            fn newline() {
                let result = CoriumParser::parse(Rule::CharLiteral, r#"'\n'"#)
                    .unwrap()
                    .as_str();
                assert_eq!(result, r#"'\n'"#);
            }

            #[test]
            fn carriage_return() {
                let result = CoriumParser::parse(Rule::CharLiteral, r#"'\r'"#)
                    .unwrap()
                    .as_str();
                assert_eq!(result, r#"'\r'"#);
            }

            #[test]
            fn horizontal_tab() {
                let result = CoriumParser::parse(Rule::CharLiteral, r#"'\t'"#)
                    .unwrap()
                    .as_str();
                assert_eq!(result, r#"'\t'"#);
            }

            #[test]
            fn unicode_scalar() {
                let result = CoriumParser::parse(Rule::CharLiteral, r#"'\u00000000'"#)
                    .unwrap()
                    .as_str();
                assert_eq!(result, r#"'\u00000000'"#);
            }

            #[test]
            fn unicode_scalar2() {
                let result = CoriumParser::parse(Rule::CharLiteral, r#"'\uFFFFFFFF'"#)
                    .unwrap()
                    .as_str();
                assert_eq!(result, r#"'\uFFFFFFFF'"#);
            }

            #[test]
            fn unicode_scalar3() {
                let result = CoriumParser::parse(Rule::CharLiteral, r#"'\uABABABAB'"#)
                    .unwrap()
                    .as_str();
                assert_eq!(result, r#"'\uABABABAB'"#);
            }

            #[test]
            fn unicode_scalar4() {
                let result = CoriumParser::parse(Rule::CharLiteral, r#"'\u123456AB'"#)
                    .unwrap()
                    .as_str();
                assert_eq!(result, r#"'\u123456AB'"#);
            }
        }

        mod invalid {
            use super::*;

            #[test]
            fn escape() {
                let result = CoriumParser::parse(Rule::CharLiteral, r#"'\A'"#);
                assert!(result.is_err());
            }

            #[test]
            fn escape2() {
                let result = CoriumParser::parse(Rule::CharLiteral, r#"'"A'"#);
                assert!(result.is_err());
            }
        }
    }

    mod bool_literal {
        use super::*;

        mod valid {
            use super::*;

            #[test]
            fn true_text() {
                let result = CoriumParser::parse(Rule::BoolLiteral, "true")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "true");
            }

            #[test]
            fn false_text() {
                let result = CoriumParser::parse(Rule::BoolLiteral, "false")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "false");
            }
        }

        mod invalid {
            use super::*;

            #[test]
            fn true_text() {
                let result = CoriumParser::parse(Rule::BoolLiteral, "t2rue");
                assert!(result.is_err());
            }

            #[test]
            fn false_text() {
                let result = CoriumParser::parse(Rule::BoolLiteral, "afalse");
                assert!(result.is_err());
            }

            #[test]
            fn one() {
                let result = CoriumParser::parse(Rule::BoolLiteral, "1");
                assert!(result.is_err());
            }

            #[test]
            fn zero() {
                let result = CoriumParser::parse(Rule::BoolLiteral, "0");
                assert!(result.is_err());
            }
        }
    }

    mod int_literal {
        use super::*;

        mod valid {
            use super::*;

            #[test]
            fn zero() {
                let result = CoriumParser::parse(Rule::IntLiteral, "0").unwrap().as_str();
                assert_eq!(result, "0");
            }

            #[test]
            fn simple() {
                let result = CoriumParser::parse(Rule::IntLiteral, "10")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "10");
            }

            #[test]
            fn simple_big() {
                let result = CoriumParser::parse(Rule::IntLiteral, "429472727848112283833")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "429472727848112283833");
            }

            #[test]
            fn simple_positive() {
                let result = CoriumParser::parse(Rule::IntLiteral, "10")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "10");
            }

            #[test]
            fn simple_separated() {
                let result = CoriumParser::parse(Rule::IntLiteral, "10_55")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "10_55");
            }

            #[test]
            fn simple_separated2() {
                let result = CoriumParser::parse(Rule::IntLiteral, "0_2_4_20203_2200_22")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "0_2_4_20203_2200_22");
            }

            #[test]
            fn simple_separated3() {
                let result = CoriumParser::parse(Rule::IntLiteral, "0_2_4_20203_2200_22")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "0_2_4_20203_2200_22");
            }

            #[test]
            fn simple_separated4() {
                let result = CoriumParser::parse(Rule::IntLiteral, "0_2_4_20203_2200_22")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "0_2_4_20203_2200_22");
            }
        }

        mod invalid {
            use super::*;

            #[test]
            fn float() {
                let result = CoriumParser::parse(Rule::IntLiteral, "0.0")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "0");
            }

            #[test]
            fn char() {
                let result = CoriumParser::parse(Rule::IntLiteral, "'0'");
                assert!(result.is_err());
            }
        }
    }

    mod float_literal {
        use super::*;

        mod valid {
            use super::*;

            #[test]
            fn zero() {
                let result = CoriumParser::parse(Rule::FloatLiteral, "0.0")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "0.0");
            }

            #[test]
            fn simple() {
                let result = CoriumParser::parse(Rule::FloatLiteral, "10.0")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "10.0");
            }

            #[test]
            fn simple_big() {
                let result = CoriumParser::parse(Rule::FloatLiteral, "4294727278481.12283833")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "4294727278481.12283833");
            }

            #[test]
            fn simple_positive() {
                let result = CoriumParser::parse(Rule::FloatLiteral, "1.6")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "1.6");
            }

            #[test]
            fn simple_separated() {
                let result = CoriumParser::parse(Rule::FloatLiteral, "1.0_55")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "1.0_55");
            }

            #[test]
            fn simple_separated2() {
                let result = CoriumParser::parse(Rule::FloatLiteral, "0_2_4_20.203_2200_22")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "0_2_4_20.203_2200_22");
            }

            #[test]
            fn simple_separated3() {
                let result = CoriumParser::parse(Rule::FloatLiteral, "0_2_4_20.203_2200_22")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "0_2_4_20.203_2200_22");
            }

            #[test]
            fn simple_separated4() {
                let result = CoriumParser::parse(Rule::FloatLiteral, "0.0_2_4_20203_2200_22")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "0.0_2_4_20203_2200_22");
            }
        }

        mod invalid {
            use super::*;

            #[test]
            fn multiple_points() {
                let result = CoriumParser::parse(Rule::FloatLiteral, "0..1");
                assert!(result.is_err());
            }

            #[test]
            fn missing_base() {
                let result = CoriumParser::parse(Rule::FloatLiteral, ".1");
                assert!(result.is_err());
            }

            #[test]
            fn missing_mantissa() {
                let result = CoriumParser::parse(Rule::FloatLiteral, "1.");
                assert!(result.is_err());
            }

            #[test]
            fn missing() {
                let result = CoriumParser::parse(Rule::FloatLiteral, ".");
                assert!(result.is_err());
            }
        }
    }

    mod literal {
        use super::*;

        mod valid {
            use super::*;

            #[test]
            fn float() {
                let mut result = CoriumParser::parse(Rule::Literal, "2.5").unwrap();
                let result = result.next().unwrap().into_inner().next().unwrap();
                assert_eq!(result.as_rule(), Rule::FloatLiteral);
            }

            #[test]
            fn int() {
                let mut result = CoriumParser::parse(Rule::Literal, "10").unwrap();
                let result = result.next().unwrap().into_inner().next().unwrap();
                assert_eq!(result.as_rule(), Rule::IntLiteral);
            }

            #[test]
            fn boolean() {
                let mut result = CoriumParser::parse(Rule::Literal, "true").unwrap();
                let result = result.next().unwrap().into_inner().next().unwrap();
                assert_eq!(result.as_rule(), Rule::BoolLiteral);
            }

            #[test]
            fn character() {
                let mut result = CoriumParser::parse(Rule::Literal, "'X'").unwrap();
                let result = result.next().unwrap().into_inner().next().unwrap();
                assert_eq!(result.as_rule(), Rule::CharLiteral);
            }

            #[test]
            fn string() {
                let mut result =
                    CoriumParser::parse(Rule::Literal, "\"Hallo zusammen ;)\"").unwrap();
                let result = result.next().unwrap().into_inner().next().unwrap();
                assert_eq!(result.as_rule(), Rule::StringLiteral);
            }
        }

        mod invalid {
            use super::*;

            #[test]
            fn empty() {
                let result = CoriumParser::parse(Rule::Literal, "");
                assert!(result.is_err());
            }

            #[test]
            fn text() {
                let result = CoriumParser::parse(Rule::Literal, "Trololo");
                assert!(result.is_err());
            }

            #[test]
            fn symbols() {
                let result = CoriumParser::parse(Rule::Literal, "?!?");
                assert!(result.is_err());
            }
        }
    }

    mod expression {
        use super::*;

        mod valid {
            use super::*;

            #[test]
            fn float() {
                let mut result = CoriumParser::parse(Rule::Expression, "2.5").unwrap();
                let result = result.next().unwrap().into_inner().next().unwrap();
                assert_eq!(result.as_rule(), Rule::Literal);
            }

            #[test]
            fn int() {
                let mut result = CoriumParser::parse(Rule::Expression, "10").unwrap();
                let result = result.next().unwrap().into_inner().next().unwrap();
                assert_eq!(result.as_rule(), Rule::Literal);
            }

            #[test]
            fn boolean() {
                let mut result = CoriumParser::parse(Rule::Expression, "true").unwrap();
                let result = result.next().unwrap().into_inner().next().unwrap();
                assert_eq!(result.as_rule(), Rule::Literal);
            }

            #[test]
            fn character() {
                let mut result = CoriumParser::parse(Rule::Expression, "'X'").unwrap();
                let result = result.next().unwrap().into_inner().next().unwrap();
                assert_eq!(result.as_rule(), Rule::Literal);
            }

            #[test]
            fn string() {
                let mut result =
                    CoriumParser::parse(Rule::Expression, "\"Hallo zusammen ;)\"").unwrap();
                let result = result.next().unwrap().into_inner().next().unwrap();
                assert_eq!(result.as_rule(), Rule::Literal);
            }

            #[test]
            fn float_literal() {
                let mut result = CoriumParser::parse(Rule::Expression, "2.5").unwrap();
                let result = result.next().unwrap().into_inner().next().unwrap();
                let result = result.into_inner().next().unwrap();
                assert_eq!(result.as_rule(), Rule::FloatLiteral);
            }

            #[test]
            fn int_literal() {
                let mut result = CoriumParser::parse(Rule::Expression, "10").unwrap();
                let result = result.next().unwrap().into_inner().next().unwrap();
                let result = result.into_inner().next().unwrap();
                assert_eq!(result.as_rule(), Rule::IntLiteral);
            }

            #[test]
            fn boolean_literal() {
                let mut result = CoriumParser::parse(Rule::Expression, "true").unwrap();
                let result = result.next().unwrap().into_inner().next().unwrap();
                let result = result.into_inner().next().unwrap();
                assert_eq!(result.as_rule(), Rule::BoolLiteral);
            }

            #[test]
            fn character_literal() {
                let mut result = CoriumParser::parse(Rule::Expression, "'X'").unwrap();
                let result = result.next().unwrap().into_inner().next().unwrap();
                let result = result.into_inner().next().unwrap();
                assert_eq!(result.as_rule(), Rule::CharLiteral);
            }

            #[test]
            fn string_literal() {
                let mut result =
                    CoriumParser::parse(Rule::Expression, "\"Hallo zusammen ;)\"").unwrap();
                let result = result.next().unwrap().into_inner().next().unwrap();
                let result = result.into_inner().next().unwrap();
                assert_eq!(result.as_rule(), Rule::StringLiteral);
            }

            #[test]
            fn identifier() {
                let mut result = CoriumParser::parse(Rule::Expression, "variable").unwrap();
                let result = result.next().unwrap().into_inner().next().unwrap();
                assert_eq!(result.as_rule(), Rule::Identifier);
            }

            #[test]
            fn parentheses() {
                let mut result = CoriumParser::parse(Rule::Expression, "(10)").unwrap();
                let result = result.next().unwrap().into_inner().next().unwrap();
                assert_eq!(result.as_rule(), Rule::Expression);
                let result = result.into_inner().next().unwrap();
                assert_eq!(result.as_rule(), Rule::Literal);
            }

            #[test]
            fn nested_parentheses() {
                let mut result = CoriumParser::parse(Rule::Expression, "(((10)))").unwrap();
                let result = result.next().unwrap().into_inner().next().unwrap();
                assert_eq!(result.as_rule(), Rule::Expression);
                let result = result.into_inner().next().unwrap();
                assert_eq!(result.as_rule(), Rule::Expression);
                let result = result.into_inner().next().unwrap();
                assert_eq!(result.as_rule(), Rule::Expression);
                let result = result.into_inner().next().unwrap();
                assert_eq!(result.as_rule(), Rule::Literal);
                assert_eq!(result.as_str(), "10");
            }

            #[test]
            fn unary_plus_literal() {
                let mut result = CoriumParser::parse(Rule::Expression, "+2.5").unwrap();
                let mut result = result.next().unwrap().into_inner();

                let operator = result.next().unwrap();
                assert_eq!(operator.as_rule(), Rule::UnaryOperator);
                assert_eq!(operator.as_str(), "+");

                let inner = result.next().unwrap();
                assert_eq!(inner.as_rule(), Rule::Expression);
                assert_eq!(inner.as_str(), "2.5");

                let literal = inner.into_inner().next().unwrap();
                assert_eq!(literal.as_rule(), Rule::Literal);
                assert_eq!(literal.as_str(), "2.5");

                let float = literal.into_inner().next().unwrap();
                assert_eq!(float.as_rule(), Rule::FloatLiteral);
                assert_eq!(float.as_str(), "2.5");
            }

            #[test]
            fn unary_minus_literal() {
                let mut result = CoriumParser::parse(Rule::Expression, "-30").unwrap();
                let mut result = result.next().unwrap().into_inner();

                let operator = result.next().unwrap();
                assert_eq!(operator.as_rule(), Rule::UnaryOperator);
                assert_eq!(operator.as_str(), "-");

                let inner = result.next().unwrap();
                assert_eq!(inner.as_rule(), Rule::Expression);
                assert_eq!(inner.as_str(), "30");

                let literal = inner.into_inner().next().unwrap();
                assert_eq!(literal.as_rule(), Rule::Literal);
                assert_eq!(literal.as_str(), "30");

                let float = literal.into_inner().next().unwrap();
                assert_eq!(float.as_rule(), Rule::IntLiteral);
                assert_eq!(float.as_str(), "30");
            }

            #[test]
            fn unary_not_literal() {
                let mut result = CoriumParser::parse(Rule::Expression, "!true").unwrap();
                let mut result = result.next().unwrap().into_inner();

                let operator = result.next().unwrap();
                assert_eq!(operator.as_rule(), Rule::UnaryOperator);
                assert_eq!(operator.as_str(), "!");

                let inner = result.next().unwrap();
                assert_eq!(inner.as_rule(), Rule::Expression);
                assert_eq!(inner.as_str(), "true");

                let literal = inner.into_inner().next().unwrap();
                assert_eq!(literal.as_rule(), Rule::Literal);
                assert_eq!(literal.as_str(), "true");

                let float = literal.into_inner().next().unwrap();
                assert_eq!(float.as_rule(), Rule::BoolLiteral);
                assert_eq!(float.as_str(), "true");
            }

            #[test]
            fn unary_complement_literal() {
                let mut result = CoriumParser::parse(Rule::Expression, "~7").unwrap();
                let mut result = result.next().unwrap().into_inner();

                let operator = result.next().unwrap();
                assert_eq!(operator.as_rule(), Rule::UnaryOperator);
                assert_eq!(operator.as_str(), "~");

                let inner = result.next().unwrap();
                assert_eq!(inner.as_rule(), Rule::Expression);
                assert_eq!(inner.as_str(), "7");

                let literal = inner.into_inner().next().unwrap();
                assert_eq!(literal.as_rule(), Rule::Literal);
                assert_eq!(literal.as_str(), "7");

                let float = literal.into_inner().next().unwrap();
                assert_eq!(float.as_rule(), Rule::IntLiteral);
                assert_eq!(float.as_str(), "7");
            }
        }

        mod invalid {
            use super::*;

            #[test]
            fn empty() {
                let result = CoriumParser::parse(Rule::Expression, "");
                assert!(result.is_err());
            }

            #[test]
            fn symbols() {
                let result = CoriumParser::parse(Rule::Expression, "?!?");
                assert!(result.is_err());
            }
        }
    }

    mod unary_operator {
        use super::*;

        mod valid {
            use super::*;

            #[test]
            fn plus() {
                let mut result = CoriumParser::parse(Rule::UnaryOperator, "+").unwrap();
                let result = result.next().unwrap();
                assert_eq!(result.as_rule(), Rule::UnaryOperator);
                assert_eq!(result.as_str(), "+");
            }

            #[test]
            fn minus() {
                let mut result = CoriumParser::parse(Rule::UnaryOperator, "-").unwrap();
                let result = result.next().unwrap();
                assert_eq!(result.as_rule(), Rule::UnaryOperator);
                assert_eq!(result.as_str(), "-");
            }

            #[test]
            fn not() {
                let mut result = CoriumParser::parse(Rule::UnaryOperator, "!").unwrap();
                let result = result.next().unwrap();
                assert_eq!(result.as_rule(), Rule::UnaryOperator);
                assert_eq!(result.as_str(), "!");
            }

            #[test]
            fn complement() {
                let mut result = CoriumParser::parse(Rule::UnaryOperator, "~").unwrap();
                let result = result.next().unwrap();
                assert_eq!(result.as_rule(), Rule::UnaryOperator);
                assert_eq!(result.as_str(), "~");
            }
        }

        mod invalid {
            use super::*;

            #[test]
            fn ampersand() {
                let result = CoriumParser::parse(Rule::UnaryOperator, "&");
                assert!(result.is_err());
            }

            #[test]
            fn dollar() {
                let result = CoriumParser::parse(Rule::UnaryOperator, "$");
                assert!(result.is_err());
            }
        }
    }

    mod parameter {
        use super::*;

        mod valid {
            use super::*;

            #[test]
            fn int() {
                let mut result = CoriumParser::parse(Rule::Parameter, "myParam int").unwrap();
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "myParam");
                let typename = result.next().unwrap();
                assert_eq!(typename.as_rule(), Rule::QualifiedName);
                assert_eq!(typename.as_str(), "int");
            }

            #[test]
            fn float() {
                let mut result = CoriumParser::parse(Rule::Parameter, "myParam float").unwrap();
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "myParam");
                let typename = result.next().unwrap();
                assert_eq!(typename.as_rule(), Rule::QualifiedName);
                assert_eq!(typename.as_str(), "float");
            }

            #[test]
            fn class() {
                let mut result = CoriumParser::parse(Rule::Parameter, "myParam MyClass").unwrap();
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "myParam");
                let typename = result.next().unwrap();
                assert_eq!(typename.as_rule(), Rule::QualifiedName);
                assert_eq!(typename.as_str(), "MyClass");
            }

            #[test]
            fn package_class() {
                let mut result =
                    CoriumParser::parse(Rule::Parameter, "myParam MyPackage.MyClass").unwrap();
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "myParam");
                let typename = result.next().unwrap();
                assert_eq!(typename.as_rule(), Rule::QualifiedName);
                assert_eq!(typename.as_str(), "MyPackage.MyClass");
            }

            #[test]
            fn int_with_default_value() {
                let mut result = CoriumParser::parse(Rule::Parameter, "myParam int = 10").unwrap();
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "myParam");
                let typename = result.next().unwrap();
                assert_eq!(typename.as_rule(), Rule::QualifiedName);
                assert_eq!(typename.as_str(), "int");
                let expr = result.next().unwrap();
                assert_eq!(expr.as_rule(), Rule::Expression);
                assert_eq!(expr.as_str(), "10");
                let expr = expr.into_inner().next().unwrap();
                assert_eq!(expr.as_rule(), Rule::Literal);
                assert_eq!(expr.as_str(), "10");
                let expr = expr.into_inner().next().unwrap();
                assert_eq!(expr.as_rule(), Rule::IntLiteral);
                assert_eq!(expr.as_str(), "10");
            }

            #[test]
            fn float_with_default_value() {
                let mut result =
                    CoriumParser::parse(Rule::Parameter, "myParam float = 0.999").unwrap();
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "myParam");
                let typename = result.next().unwrap();
                assert_eq!(typename.as_rule(), Rule::QualifiedName);
                assert_eq!(typename.as_str(), "float");
                let expr = result.next().unwrap();
                assert_eq!(expr.as_rule(), Rule::Expression);
                assert_eq!(expr.as_str(), "0.999");
                let expr = expr.into_inner().next().unwrap();
                assert_eq!(expr.as_rule(), Rule::Literal);
                assert_eq!(expr.as_str(), "0.999");
                let expr = expr.into_inner().next().unwrap();
                assert_eq!(expr.as_rule(), Rule::FloatLiteral);
                assert_eq!(expr.as_str(), "0.999");
            }

            #[test]
            fn bool_with_default_value() {
                let mut result =
                    CoriumParser::parse(Rule::Parameter, "myParam bool = true").unwrap();
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "myParam");
                let typename = result.next().unwrap();
                assert_eq!(typename.as_rule(), Rule::QualifiedName);
                assert_eq!(typename.as_str(), "bool");
                let expr = result.next().unwrap();
                assert_eq!(expr.as_rule(), Rule::Expression);
                assert_eq!(expr.as_str(), "true");
                let expr = expr.into_inner().next().unwrap();
                assert_eq!(expr.as_rule(), Rule::Literal);
                assert_eq!(expr.as_str(), "true");
                let expr = expr.into_inner().next().unwrap();
                assert_eq!(expr.as_rule(), Rule::BoolLiteral);
                assert_eq!(expr.as_str(), "true");
            }

            #[test]
            fn char_with_default_value() {
                let mut result =
                    CoriumParser::parse(Rule::Parameter, "myParam char = 'x'").unwrap();
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "myParam");
                let typename = result.next().unwrap();
                assert_eq!(typename.as_rule(), Rule::QualifiedName);
                assert_eq!(typename.as_str(), "char");
                let expr = result.next().unwrap();
                assert_eq!(expr.as_rule(), Rule::Expression);
                assert_eq!(expr.as_str(), "'x'");
                let expr = expr.into_inner().next().unwrap();
                assert_eq!(expr.as_rule(), Rule::Literal);
                assert_eq!(expr.as_str(), "'x'");
                let expr = expr.into_inner().next().unwrap();
                assert_eq!(expr.as_rule(), Rule::CharLiteral);
                assert_eq!(expr.as_str(), "'x'");
            }

            #[test]
            fn string_with_default_value() {
                let mut result =
                    CoriumParser::parse(Rule::Parameter, "myParam string = \"I luv u :3\"")
                        .unwrap();
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "myParam");
                let typename = result.next().unwrap();
                assert_eq!(typename.as_rule(), Rule::QualifiedName);
                assert_eq!(typename.as_str(), "string");
                let expr = result.next().unwrap();
                assert_eq!(expr.as_rule(), Rule::Expression);
                assert_eq!(expr.as_str(), "\"I luv u :3\"");
                let expr = expr.into_inner().next().unwrap();
                assert_eq!(expr.as_rule(), Rule::Literal);
                assert_eq!(expr.as_str(), "\"I luv u :3\"");
                let expr = expr.into_inner().next().unwrap();
                assert_eq!(expr.as_rule(), Rule::StringLiteral);
                assert_eq!(expr.as_str(), "\"I luv u :3\"");
            }
        }

        mod invalid {
            use super::*;

            #[test]
            fn no_ident() {
                let result = CoriumParser::parse(Rule::Parameter, "MyClass");
                assert!(result.is_err());
            }

            #[test]
            fn no_space() {
                let result = CoriumParser::parse(Rule::Parameter, "Test_MyClass");
                assert!(result.is_err());
            }
        }
    }

    mod parameter_list {
        use super::*;

        mod valid {
            use super::*;

            #[test]
            fn one() {
                let mut result = CoriumParser::parse(Rule::ParameterList, "x int").unwrap();
                let mut result = result.next().unwrap().into_inner();
                let p1 = result.next().unwrap();
                assert_eq!(p1.as_rule(), Rule::Parameter);
                assert_eq!(p1.as_str(), "x int");
            }

            #[test]
            fn two() {
                let mut result =
                    CoriumParser::parse(Rule::ParameterList, "x int, y float").unwrap();
                let mut result = result.next().unwrap().into_inner();
                let p1 = result.next().unwrap();
                assert_eq!(p1.as_rule(), Rule::Parameter);
                assert_eq!(p1.as_str(), "x int");
                let p2 = result.next().unwrap();
                assert_eq!(p2.as_rule(), Rule::Parameter);
                assert_eq!(p2.as_str(), "y float");
            }

            #[test]
            fn three() {
                let mut result =
                    CoriumParser::parse(Rule::ParameterList, "x int, y float, z string").unwrap();
                let mut result = result.next().unwrap().into_inner();
                let p1 = result.next().unwrap();
                assert_eq!(p1.as_rule(), Rule::Parameter);
                assert_eq!(p1.as_str(), "x int");
                let p2 = result.next().unwrap();
                assert_eq!(p2.as_rule(), Rule::Parameter);
                assert_eq!(p2.as_str(), "y float");
                let p3 = result.next().unwrap();
                assert_eq!(p3.as_rule(), Rule::Parameter);
                assert_eq!(p3.as_str(), "z string");
            }

            #[test]
            fn one_with_default_value() {
                let mut result = CoriumParser::parse(Rule::ParameterList, "x int = 10").unwrap();
                let mut result = result.next().unwrap().into_inner();
                let p1 = result.next().unwrap();
                assert_eq!(p1.as_rule(), Rule::Parameter);
                assert_eq!(p1.as_str(), "x int = 10");
            }

            #[test]
            fn two_with_default_value() {
                let mut result =
                    CoriumParser::parse(Rule::ParameterList, "x int = 10, y float = 2.4").unwrap();
                let mut result = result.next().unwrap().into_inner();
                let p1 = result.next().unwrap();
                assert_eq!(p1.as_rule(), Rule::Parameter);
                assert_eq!(p1.as_str(), "x int = 10");
                let p2 = result.next().unwrap();
                assert_eq!(p2.as_rule(), Rule::Parameter);
                assert_eq!(p2.as_str(), "y float = 2.4");
            }

            #[test]
            fn two_one_with_default_value() {
                let mut result =
                    CoriumParser::parse(Rule::ParameterList, "a char, x int = 10").unwrap();
                let mut result = result.next().unwrap().into_inner();
                let p1 = result.next().unwrap();
                assert_eq!(p1.as_rule(), Rule::Parameter);
                assert_eq!(p1.as_str(), "a char");
                let p2 = result.next().unwrap();
                assert_eq!(p2.as_rule(), Rule::Parameter);
                assert_eq!(p2.as_str(), "x int = 10");
            }
        }

        mod invalid {
            use super::*;

            #[test]
            fn comma_mismatch() {
                let result = CoriumParser::parse(Rule::ParameterList, ",a char b int");
                assert!(result.is_err());
            }

            #[test]
            fn wrong_comma() {
                let result = CoriumParser::parse(Rule::ParameterList, "a, char b int");
                assert!(result.is_err());
            }
        }
    }

    mod return_statement {
        use super::*;

        mod valid {
            use super::*;

            #[test]
            fn return_none() {
                let result = CoriumParser::parse(Rule::ReturnStatement, "return\n").unwrap();
                assert_eq!(result.as_str(), "return\n");
            }

            #[test]
            fn return_int() {
                let mut result = CoriumParser::parse(Rule::ReturnStatement, "return 10\n").unwrap();
                assert_eq!(result.as_str(), "return 10\n");
                let mut result = result.next().unwrap().into_inner();
                let p1 = result.next().unwrap();
                assert_eq!(p1.as_rule(), Rule::Expression);
                assert_eq!(p1.as_str(), "10");
            }
        }

        mod invalid {
            use super::*;

            #[test]
            fn no_newline() {
                let result = CoriumParser::parse(Rule::ReturnStatement, "return");
                assert!(result.is_err());
            }

            #[test]
            fn no_expr() {
                let result = CoriumParser::parse(Rule::ReturnStatement, "return ?\n");
                assert!(result.is_err());
            }
        }
    }

    mod mutable_variable {
        use super::*;

        mod valid {
            use super::*;

            #[test]
            fn int() {
                let mut result =
                    CoriumParser::parse(Rule::MutableVariable, "let x = 10\n").unwrap();
                assert_eq!(result.as_str(), "let x = 10\n");
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "x");
                let literal = result.next().unwrap();
                assert_eq!(literal.as_rule(), Rule::Expression);
                assert_eq!(literal.as_str(), "10");
            }

            #[test]
            fn float() {
                let mut result =
                    CoriumParser::parse(Rule::MutableVariable, "let x = 10.0\n").unwrap();
                assert_eq!(result.as_str(), "let x = 10.0\n");
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "x");
                let literal = result.next().unwrap();
                assert_eq!(literal.as_rule(), Rule::Expression);
                assert_eq!(literal.as_str(), "10.0");
            }

            #[test]
            fn char() {
                let mut result =
                    CoriumParser::parse(Rule::MutableVariable, "let x = 'x'\n").unwrap();
                assert_eq!(result.as_str(), "let x = 'x'\n");
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "x");
                let literal = result.next().unwrap();
                assert_eq!(literal.as_rule(), Rule::Expression);
                assert_eq!(literal.as_str(), "'x'");
            }

            #[test]
            fn bool() {
                let mut result =
                    CoriumParser::parse(Rule::MutableVariable, "let x = true\n").unwrap();
                assert_eq!(result.as_str(), "let x = true\n");
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "x");
                let literal = result.next().unwrap();
                assert_eq!(literal.as_rule(), Rule::Expression);
                assert_eq!(literal.as_str(), "true");
            }

            #[test]
            fn string() {
                let mut result =
                    CoriumParser::parse(Rule::MutableVariable, "let x = \"Name\"\n").unwrap();
                assert_eq!(result.as_str(), "let x = \"Name\"\n");
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "x");
                let literal = result.next().unwrap();
                assert_eq!(literal.as_rule(), Rule::Expression);
                assert_eq!(literal.as_str(), "\"Name\"");
            }

            #[test]
            fn type_int() {
                let mut result =
                    CoriumParser::parse(Rule::MutableVariable, "let x int = 10\n").unwrap();
                assert_eq!(result.as_str(), "let x int = 10\n");
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "x");
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::QualifiedName);
                assert_eq!(ident.as_str(), "int");
                let literal = result.next().unwrap();
                assert_eq!(literal.as_rule(), Rule::Expression);
                assert_eq!(literal.as_str(), "10");
            }

            #[test]
            fn type_float() {
                let mut result =
                    CoriumParser::parse(Rule::MutableVariable, "let x float = 10.0\n").unwrap();
                assert_eq!(result.as_str(), "let x float = 10.0\n");
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "x");
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::QualifiedName);
                assert_eq!(ident.as_str(), "float");
                let literal = result.next().unwrap();
                assert_eq!(literal.as_rule(), Rule::Expression);
                assert_eq!(literal.as_str(), "10.0");
            }

            #[test]
            fn type_char() {
                let mut result =
                    CoriumParser::parse(Rule::MutableVariable, "let x char = 'x'\n").unwrap();
                assert_eq!(result.as_str(), "let x char = 'x'\n");
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "x");
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::QualifiedName);
                assert_eq!(ident.as_str(), "char");
                let literal = result.next().unwrap();
                assert_eq!(literal.as_rule(), Rule::Expression);
                assert_eq!(literal.as_str(), "'x'");
            }

            #[test]
            fn type_bool() {
                let mut result =
                    CoriumParser::parse(Rule::MutableVariable, "let x bool = true\n").unwrap();
                assert_eq!(result.as_str(), "let x bool = true\n");
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "x");
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::QualifiedName);
                assert_eq!(ident.as_str(), "bool");
                let literal = result.next().unwrap();
                assert_eq!(literal.as_rule(), Rule::Expression);
                assert_eq!(literal.as_str(), "true");
            }

            #[test]
            fn type_string() {
                let mut result =
                    CoriumParser::parse(Rule::MutableVariable, "let x string = \"Name\"\n")
                        .unwrap();
                assert_eq!(result.as_str(), "let x string = \"Name\"\n");
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "x");
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::QualifiedName);
                assert_eq!(ident.as_str(), "string");
                let literal = result.next().unwrap();
                assert_eq!(literal.as_rule(), Rule::Expression);
                assert_eq!(literal.as_str(), "\"Name\"");
            }
        }

        mod invalid {
            use super::*;

            #[test]
            fn missing() {
                let result = CoriumParser::parse(Rule::MutableVariable, "let\n");
                assert!(result.is_err());
            }

            #[test]
            fn missing2() {
                let result = CoriumParser::parse(Rule::MutableVariable, "let=\n");
                assert!(result.is_err());
            }

            #[test]
            fn missing3() {
                let result = CoriumParser::parse(Rule::MutableVariable, "let = \n");
                assert!(result.is_err());
            }

            #[test]
            fn missing4() {
                let result = CoriumParser::parse(Rule::MutableVariable, "let x\n");
                assert!(result.is_err());
            }

            #[test]
            fn missing5() {
                let result = CoriumParser::parse(Rule::MutableVariable, "let x int\n");
                assert!(result.is_err());
            }

            #[test]
            fn missing6() {
                let result = CoriumParser::parse(Rule::MutableVariable, "let x int = \n");
                assert!(result.is_err());
            }

            #[test]
            fn no_space() {
                let result = CoriumParser::parse(Rule::MutableVariable, "let x=10\n");
                assert!(result.is_err());
            }

            #[test]
            fn no_space2() {
                let result = CoriumParser::parse(Rule::MutableVariable, "letx=3\n");
                assert!(result.is_err());
            }

            #[test]
            fn no_newline() {
                let result = CoriumParser::parse(Rule::MutableVariable, "let x = 10");
                assert!(result.is_err());
            }
        }
    }

    mod immutable_variable {
        use super::*;

        mod valid {
            use super::*;

            #[test]
            fn int() {
                let mut result =
                    CoriumParser::parse(Rule::ImmutableVariable, "const x = 10\n").unwrap();
                assert_eq!(result.as_str(), "const x = 10\n");
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "x");
                let literal = result.next().unwrap();
                assert_eq!(literal.as_rule(), Rule::Expression);
                assert_eq!(literal.as_str(), "10");
            }

            #[test]
            fn float() {
                let mut result =
                    CoriumParser::parse(Rule::ImmutableVariable, "const x = 10.0\n").unwrap();
                assert_eq!(result.as_str(), "const x = 10.0\n");
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "x");
                let literal = result.next().unwrap();
                assert_eq!(literal.as_rule(), Rule::Expression);
                assert_eq!(literal.as_str(), "10.0");
            }

            #[test]
            fn char() {
                let mut result =
                    CoriumParser::parse(Rule::ImmutableVariable, "const x = 'x'\n").unwrap();
                assert_eq!(result.as_str(), "const x = 'x'\n");
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "x");
                let literal = result.next().unwrap();
                assert_eq!(literal.as_rule(), Rule::Expression);
                assert_eq!(literal.as_str(), "'x'");
            }

            #[test]
            fn bool() {
                let mut result =
                    CoriumParser::parse(Rule::ImmutableVariable, "const x = true\n").unwrap();
                assert_eq!(result.as_str(), "const x = true\n");
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "x");
                let literal = result.next().unwrap();
                assert_eq!(literal.as_rule(), Rule::Expression);
                assert_eq!(literal.as_str(), "true");
            }

            #[test]
            fn string() {
                let mut result =
                    CoriumParser::parse(Rule::ImmutableVariable, "const x = \"Name\"\n").unwrap();
                assert_eq!(result.as_str(), "const x = \"Name\"\n");
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "x");
                let literal = result.next().unwrap();
                assert_eq!(literal.as_rule(), Rule::Expression);
                assert_eq!(literal.as_str(), "\"Name\"");
            }

            #[test]
            fn type_int() {
                let mut result =
                    CoriumParser::parse(Rule::ImmutableVariable, "const x int = 10\n").unwrap();
                assert_eq!(result.as_str(), "const x int = 10\n");
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "x");
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::QualifiedName);
                assert_eq!(ident.as_str(), "int");
                let literal = result.next().unwrap();
                assert_eq!(literal.as_rule(), Rule::Expression);
                assert_eq!(literal.as_str(), "10");
            }

            #[test]
            fn type_float() {
                let mut result =
                    CoriumParser::parse(Rule::ImmutableVariable, "const x float = 10.0\n").unwrap();
                assert_eq!(result.as_str(), "const x float = 10.0\n");
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "x");
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::QualifiedName);
                assert_eq!(ident.as_str(), "float");
                let literal = result.next().unwrap();
                assert_eq!(literal.as_rule(), Rule::Expression);
                assert_eq!(literal.as_str(), "10.0");
            }

            #[test]
            fn type_char() {
                let mut result =
                    CoriumParser::parse(Rule::ImmutableVariable, "const x char = 'x'\n").unwrap();
                assert_eq!(result.as_str(), "const x char = 'x'\n");
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "x");
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::QualifiedName);
                assert_eq!(ident.as_str(), "char");
                let literal = result.next().unwrap();
                assert_eq!(literal.as_rule(), Rule::Expression);
                assert_eq!(literal.as_str(), "'x'");
            }

            #[test]
            fn type_bool() {
                let mut result =
                    CoriumParser::parse(Rule::ImmutableVariable, "const x bool = true\n").unwrap();
                assert_eq!(result.as_str(), "const x bool = true\n");
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "x");
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::QualifiedName);
                assert_eq!(ident.as_str(), "bool");
                let literal = result.next().unwrap();
                assert_eq!(literal.as_rule(), Rule::Expression);
                assert_eq!(literal.as_str(), "true");
            }

            #[test]
            fn type_string() {
                let mut result =
                    CoriumParser::parse(Rule::ImmutableVariable, "const x string = \"Name\"\n")
                        .unwrap();
                assert_eq!(result.as_str(), "const x string = \"Name\"\n");
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "x");
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::QualifiedName);
                assert_eq!(ident.as_str(), "string");
                let literal = result.next().unwrap();
                assert_eq!(literal.as_rule(), Rule::Expression);
                assert_eq!(literal.as_str(), "\"Name\"");
            }
        }

        mod invalid {
            use super::*;

            #[test]
            fn missing() {
                let result = CoriumParser::parse(Rule::ImmutableVariable, "const\n");
                assert!(result.is_err());
            }

            #[test]
            fn missing2() {
                let result = CoriumParser::parse(Rule::ImmutableVariable, "const=\n");
                assert!(result.is_err());
            }

            #[test]
            fn missing3() {
                let result = CoriumParser::parse(Rule::ImmutableVariable, "const = \n");
                assert!(result.is_err());
            }

            #[test]
            fn missing4() {
                let result = CoriumParser::parse(Rule::ImmutableVariable, "const x\n");
                assert!(result.is_err());
            }

            #[test]
            fn missing5() {
                let result = CoriumParser::parse(Rule::ImmutableVariable, "const x int\n");
                assert!(result.is_err());
            }

            #[test]
            fn missing6() {
                let result = CoriumParser::parse(Rule::ImmutableVariable, "const x int = \n");
                assert!(result.is_err());
            }

            #[test]
            fn no_space() {
                let result = CoriumParser::parse(Rule::ImmutableVariable, "const x=10\n");
                assert!(result.is_err());
            }

            #[test]
            fn no_space2() {
                let result = CoriumParser::parse(Rule::ImmutableVariable, "constx=3\n");
                assert!(result.is_err());
            }

            #[test]
            fn no_newline() {
                let result = CoriumParser::parse(Rule::ImmutableVariable, "const x = 10");
                assert!(result.is_err());
            }
        }
    }

    mod function_statement {
        use super::*;

        mod valid {
            use super::*;

            #[test]
            fn return_statement() {
                let mut result = CoriumParser::parse(Rule::LocalStatement, "return\n").unwrap();
                let mut result = result.next().unwrap().into_inner();
                let var = result.next().unwrap();
                assert_eq!(var.as_rule(), Rule::ReturnStatement);
                assert_eq!(var.as_str(), "return\n");
            }

            #[test]
            fn return_statement2() {
                let mut result =
                    CoriumParser::parse(Rule::LocalStatement, "return true\n").unwrap();
                let mut result = result.next().unwrap().into_inner();
                let var = result.next().unwrap();
                assert_eq!(var.as_rule(), Rule::ReturnStatement);
                assert_eq!(var.as_str(), "return true\n");
            }

            #[test]
            fn mutable_variable() {
                let src = "let x = 10\n";
                let mut result = CoriumParser::parse(Rule::LocalStatement, src).unwrap();
                assert_eq!(result.as_str(), src);
                let inner = result.next().unwrap().into_inner().next().unwrap();
                assert_eq!(inner.as_rule(), Rule::MutableVariable);
            }

            #[test]
            fn immutable_variable() {
                let src = "const x = 10\n";
                let mut result = CoriumParser::parse(Rule::LocalStatement, src).unwrap();
                assert_eq!(result.as_str(), src);
                let inner = result.next().unwrap().into_inner().next().unwrap();
                assert_eq!(inner.as_rule(), Rule::ImmutableVariable);
            }
        }

        mod invalid {
            use super::*;

            #[test]
            fn invalid() {
                let result = CoriumParser::parse(Rule::LocalStatement, "HELLO THERE");
                assert!(result.is_err());
            }

            #[test]
            fn invalid2() {
                let result = CoriumParser::parse(Rule::LocalStatement, "42742");
                assert!(result.is_err());
            }

            #[test]
            fn invalid3() {
                let result = CoriumParser::parse(Rule::LocalStatement, "function f ()");
                assert!(result.is_err());
            }

            #[test]
            fn separators() {
                let result = CoriumParser::parse(Rule::LocalStatement, " \n  \t \t \n\n  \n");
                assert!(result.is_err());
            }
        }
    }

    mod block {
        use super::*;

        mod valid {
            use super::*;

            #[test]
            fn variables() {
                let source = concat!(
                    "let x = 10\n",
                    "let y int = true\n",
                    "let name = \"Hey\"\n",
                    "let z bool = true\n",
                    "let z float = 2.33225\n"
                );
                let mut y = CoriumParser::parse(Rule::Block, source)
                    .unwrap()
                    .next()
                    .unwrap()
                    .into_inner();

                let var = y.next().unwrap();
                assert_eq!(var.as_str(), "let x = 10\n");

                let var = y.next().unwrap();
                assert_eq!(var.as_str(), "let y int = true\n");

                let var = y.next().unwrap();
                assert_eq!(var.as_str(), "let name = \"Hey\"\n");

                let var = y.next().unwrap();
                assert_eq!(var.as_str(), "let z bool = true\n");

                let var = y.next().unwrap();
                assert_eq!(var.as_str(), "let z float = 2.33225\n");
            }

            #[test]
            fn returns() {
                let source = concat!(
                    "return\n",
                    "return true\n",
                    "return \"Hey\"\n",
                    "return true\n",
                    "return 2.33225\n"
                );
                let mut y = CoriumParser::parse(Rule::Block, source)
                    .unwrap()
                    .next()
                    .unwrap()
                    .into_inner();

                let var = y.next().unwrap();
                assert_eq!(var.as_str(), "return\n");

                let var = y.next().unwrap();
                assert_eq!(var.as_str(), "return true\n");

                let var = y.next().unwrap();
                assert_eq!(var.as_str(), "return \"Hey\"\n");

                let var = y.next().unwrap();
                assert_eq!(var.as_str(), "return true\n");

                let var = y.next().unwrap();
                assert_eq!(var.as_str(), "return 2.33225\n");
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
                let mut y = CoriumParser::parse(Rule::Block, source)
                    .unwrap()
                    .next()
                    .unwrap()
                    .into_inner();

                let var = y.next().unwrap();
                assert_eq!(var.as_str(), "let x = 10\n");

                let var = y.next().unwrap();
                assert_eq!(var.as_str(), "return true\n");

                let var = y.next().unwrap();
                assert_eq!(var.as_str(), "return \"Hey\"\n");

                let var = y.next().unwrap();
                assert_eq!(var.as_str(), "let z bool = true\n");

                let var = y.next().unwrap();
                assert_eq!(var.as_str(), "let z float = 2.33225\n");
            }
        }

        mod invalid {
            use super::*;

            #[test]
            fn mixed() {
                let result = CoriumParser::parse(Rule::Block, "48dad22adad8482").unwrap();
                assert!(result.as_str().is_empty());
            }

            #[test]
            fn mixed2() {
                let result = CoriumParser::parse(Rule::Block, "let = 4828482").unwrap();
                assert!(result.as_str().is_empty());
            }

            #[test]
            fn mixed3() {
                let result = CoriumParser::parse(Rule::Block, "return").unwrap();
                assert!(result.as_str().is_empty());
            }

            #[test]
            fn mixed4() {
                let result = CoriumParser::parse(Rule::Block, " \n\n \t \t\t   \n\t ");
                assert!(result.is_ok());
            }
        }
    }

    mod function_signature {
        use super::*;

        mod valid {
            use super::*;

            #[test]
            fn simple() {
                let mut result =
                    CoriumParser::parse(Rule::FunctionSignature, "function f ()").unwrap();
                assert_eq!(result.as_str(), "function f ()");
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "f");
            }

            #[test]
            fn return_type() {
                let mut result =
                    CoriumParser::parse(Rule::FunctionSignature, "function f () int").unwrap();
                assert_eq!(result.as_str(), "function f () int");
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "f");
                let ret = result.next().unwrap();
                assert_eq!(ret.as_rule(), Rule::QualifiedName);
                assert_eq!(ret.as_str(), "int");
            }

            #[test]
            fn param() {
                let mut result =
                    CoriumParser::parse(Rule::FunctionSignature, "function f (x float)").unwrap();
                assert_eq!(result.as_str(), "function f (x float)");
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "f");
                let params = result.next().unwrap();
                assert_eq!(params.as_rule(), Rule::ParameterList);
                assert_eq!(params.as_str(), "x float");
            }

            #[test]
            fn params() {
                let mut result = CoriumParser::parse(
                    Rule::FunctionSignature,
                    "function f (x float, name string, ok bool = true)",
                )
                .unwrap();
                assert_eq!(
                    result.as_str(),
                    "function f (x float, name string, ok bool = true)"
                );
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "f");
                let params = result.next().unwrap();
                assert_eq!(params.as_rule(), Rule::ParameterList);
                assert_eq!(params.as_str(), "x float, name string, ok bool = true");
            }

            #[test]
            fn param_ret() {
                let mut result =
                    CoriumParser::parse(Rule::FunctionSignature, "function f (x float) float")
                        .unwrap();
                assert_eq!(result.as_str(), "function f (x float) float");
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "f");
                let params = result.next().unwrap();
                assert_eq!(params.as_rule(), Rule::ParameterList);
                assert_eq!(params.as_str(), "x float");
                let ret = result.next().unwrap();
                assert_eq!(ret.as_rule(), Rule::QualifiedName);
                assert_eq!(ret.as_str(), "float");
            }

            #[test]
            fn many_params() {
                let mut result = CoriumParser::parse(Rule::FunctionSignature, "function f (x float, name string, ok bool = true, a int, b int, c float, d char, z string) char").unwrap();
                assert_eq!(result.as_str(), "function f (x float, name string, ok bool = true, a int, b int, c float, d char, z string) char");
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "f");
                let params = result.next().unwrap();
                assert_eq!(params.as_rule(), Rule::ParameterList);
                assert_eq!(
                    params.as_str(),
                    "x float, name string, ok bool = true, a int, b int, c float, d char, z string"
                );
            }
        }

        mod invalid {
            use super::*;

            #[test]
            fn no() {
                let result = CoriumParser::parse(Rule::FunctionSignature, "function");
                assert!(result.is_err());
            }

            #[test]
            fn no_ident() {
                let result = CoriumParser::parse(Rule::FunctionSignature, "function ()");
                assert!(result.is_err());
            }

            #[test]
            fn no_fun() {
                let result = CoriumParser::parse(Rule::FunctionSignature, "() int");
                assert!(result.is_err());
            }

            #[test]
            fn no_parenthesis() {
                let result = CoriumParser::parse(Rule::FunctionSignature, "function x");
                assert!(result.is_err());
            }

            #[test]
            fn no_space() {
                let result = CoriumParser::parse(Rule::FunctionSignature, "funx()");
                assert!(result.is_err());
            }

            #[test]
            fn ret_no_parenthesis() {
                let result = CoriumParser::parse(Rule::FunctionSignature, "function x float");
                assert!(result.is_err());
            }
        }
    }

    mod native_function {
        use super::*;

        mod valid {
            use super::*;

            #[test]
            fn simple() {
                let mut result =
                    CoriumParser::parse(Rule::NativeFunction, "native function f ()\n").unwrap();
                assert_eq!(result.as_str(), "native function f ()\n");
                let mut result = result.next().unwrap().into_inner();
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "f");
            }

            #[test]
            fn return_type() {
                let mut result =
                    CoriumParser::parse(Rule::NativeFunction, "native function f () int\n")
                        .unwrap();
                assert_eq!(result.as_str(), "native function f () int\n");
                let mut result = result.next().unwrap().into_inner();
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "f");
                let ret = result.next().unwrap();
                assert_eq!(ret.as_rule(), Rule::QualifiedName);
                assert_eq!(ret.as_str(), "int");
            }

            #[test]
            fn param() {
                let mut result =
                    CoriumParser::parse(Rule::NativeFunction, "native function f (x float)\n")
                        .unwrap();
                assert_eq!(result.as_str(), "native function f (x float)\n");
                let mut result = result.next().unwrap().into_inner();
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "f");
                let params = result.next().unwrap();
                assert_eq!(params.as_rule(), Rule::ParameterList);
                assert_eq!(params.as_str(), "x float");
            }

            #[test]
            fn params() {
                let mut result = CoriumParser::parse(
                    Rule::NativeFunction,
                    "native function f (x float, name string, ok bool = true)\n",
                )
                .unwrap();
                assert_eq!(
                    result.as_str(),
                    "native function f (x float, name string, ok bool = true)\n"
                );
                let mut result = result.next().unwrap().into_inner();
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "f");
                let params = result.next().unwrap();
                assert_eq!(params.as_rule(), Rule::ParameterList);
                assert_eq!(params.as_str(), "x float, name string, ok bool = true");
            }

            #[test]
            fn param_ret() {
                let mut result = CoriumParser::parse(
                    Rule::NativeFunction,
                    "native function f (x float) float\n",
                )
                .unwrap();
                assert_eq!(result.as_str(), "native function f (x float) float\n");
                let mut result = result.next().unwrap().into_inner();
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "f");
                let params = result.next().unwrap();
                assert_eq!(params.as_rule(), Rule::ParameterList);
                assert_eq!(params.as_str(), "x float");
                let ret = result.next().unwrap();
                assert_eq!(ret.as_rule(), Rule::QualifiedName);
                assert_eq!(ret.as_str(), "float");
            }

            #[test]
            fn many_params() {
                let mut result = CoriumParser::parse(Rule::NativeFunction, "native function f (x float, name string, ok bool = true, a int, b int, c float, d char, z string) char\n").unwrap();
                assert_eq!(result.as_str(), "native function f (x float, name string, ok bool = true, a int, b int, c float, d char, z string) char\n");
                let mut result = result.next().unwrap().into_inner();
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "f");
                let params = result.next().unwrap();
                assert_eq!(params.as_rule(), Rule::ParameterList);
                assert_eq!(
                    params.as_str(),
                    "x float, name string, ok bool = true, a int, b int, c float, d char, z string"
                );
            }
        }

        mod invalid {
            use super::*;

            #[test]
            fn no() {
                let result = CoriumParser::parse(Rule::NativeFunction, "native function\n");
                assert!(result.is_err());
            }

            #[test]
            fn no_ident() {
                let result = CoriumParser::parse(Rule::NativeFunction, "native function ()\n");
                assert!(result.is_err());
            }

            #[test]
            fn no_fun() {
                let result = CoriumParser::parse(Rule::NativeFunction, "native () int\n");
                assert!(result.is_err());
            }

            #[test]
            fn no_parenthesis() {
                let result = CoriumParser::parse(Rule::NativeFunction, "native function x\n");
                assert!(result.is_err());
            }

            #[test]
            fn no_space() {
                let result = CoriumParser::parse(Rule::NativeFunction, "native funx()\n");
                assert!(result.is_err());
            }

            #[test]
            fn ret_no_parenthesis() {
                let result = CoriumParser::parse(Rule::NativeFunction, "native function x float\n");
                assert!(result.is_err());
            }

            #[test]
            fn ret_newline() {
                let result = CoriumParser::parse(Rule::NativeFunction, "native function f ()");
                assert!(result.is_err());
            }
        }
    }

    mod function {
        use super::*;

        mod valid {
            use super::*;

            #[test]
            fn simple() {
                let mut result =
                    CoriumParser::parse(Rule::Function, "function f () {\n}\n").unwrap();
                assert_eq!(result.as_str(), "function f () {\n}\n");
                let mut result = result.next().unwrap().into_inner();
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "f");
            }

            #[test]
            fn return_type() {
                let mut result =
                    CoriumParser::parse(Rule::Function, "function f () int {\n}\n").unwrap();
                assert_eq!(result.as_str(), "function f () int {\n}\n");
                let mut result = result.next().unwrap().into_inner();
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "f");
                let ret = result.next().unwrap();
                assert_eq!(ret.as_rule(), Rule::QualifiedName);
                assert_eq!(ret.as_str(), "int");
            }

            #[test]
            fn param() {
                let mut result =
                    CoriumParser::parse(Rule::Function, "function f (x float) {\n}\n").unwrap();
                assert_eq!(result.as_str(), "function f (x float) {\n}\n");
                let mut result = result.next().unwrap().into_inner();
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "f");
                let params = result.next().unwrap();
                assert_eq!(params.as_rule(), Rule::ParameterList);
                assert_eq!(params.as_str(), "x float");
            }

            #[test]
            fn params() {
                let mut result = CoriumParser::parse(
                    Rule::Function,
                    "function f (x float, name string, ok bool = true) {\n}\n",
                )
                .unwrap();
                assert_eq!(
                    result.as_str(),
                    "function f (x float, name string, ok bool = true) {\n}\n"
                );
                let mut result = result.next().unwrap().into_inner();
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "f");
                let params = result.next().unwrap();
                assert_eq!(params.as_rule(), Rule::ParameterList);
                assert_eq!(params.as_str(), "x float, name string, ok bool = true");
            }

            #[test]
            fn param_ret() {
                let mut result =
                    CoriumParser::parse(Rule::Function, "function f (x float) float {\n}\n")
                        .unwrap();
                assert_eq!(result.as_str(), "function f (x float) float {\n}\n");
                let mut result = result.next().unwrap().into_inner();
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "f");
                let params = result.next().unwrap();
                assert_eq!(params.as_rule(), Rule::ParameterList);
                assert_eq!(params.as_str(), "x float");
                let ret = result.next().unwrap();
                assert_eq!(ret.as_rule(), Rule::QualifiedName);
                assert_eq!(ret.as_str(), "float");
            }

            #[test]
            fn many_params() {
                let mut result = CoriumParser::parse(Rule::Function, "function f (x float, name string, ok bool = true, a int, b int, c float, d char, z string) char {\n}\n").unwrap();
                assert_eq!(result.as_str(), "function f (x float, name string, ok bool = true, a int, b int, c float, d char, z string) char {\n}\n");
                let mut result = result.next().unwrap().into_inner();
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "f");
                let params = result.next().unwrap();
                assert_eq!(params.as_rule(), Rule::ParameterList);
                assert_eq!(
                    params.as_str(),
                    "x float, name string, ok bool = true, a int, b int, c float, d char, z string"
                );
            }

            #[test]
            fn simple_block() {
                let mut result =
                    CoriumParser::parse(Rule::Function, "function f () {\n}\n").unwrap();
                assert_eq!(result.as_str(), "function f () {\n}\n");
                let mut result = result.next().unwrap().into_inner();
                let mut inner = result.next().unwrap().into_inner();
                let ident = inner.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "f");
                let block = result.next().unwrap();
                assert_eq!(block.as_rule(), Rule::Block);
            }

            #[test]
            fn ret() {
                let mut result =
                    CoriumParser::parse(Rule::Function, "function f () {\nreturn 10\n}\n").unwrap();
                assert_eq!(result.as_str(), "function f () {\nreturn 10\n}\n");
                let mut result = result.next().unwrap().into_inner();
                let mut inner = result.next().unwrap().into_inner();
                let ident = inner.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "f");
                let block = result.next().unwrap();
                assert_eq!(block.as_rule(), Rule::Block);
                assert_eq!(block.as_str(), "return 10\n");
                let smt = block.into_inner().next().unwrap();
                assert_eq!(smt.as_rule(), Rule::LocalStatement);
                assert_eq!(smt.as_str(), "return 10\n");
                let ret = smt.into_inner().next().unwrap();
                assert_eq!(ret.as_rule(), Rule::ReturnStatement);
                assert_eq!(ret.as_str(), "return 10\n");
            }

            #[test]
            fn complex() {
                let src = concat!(
                    "function compute (x int) int {\n",
                    "    let result = \"LOL\"\n",
                    "    return 23\n",
                    "}\n"
                );
                let mut result = CoriumParser::parse(Rule::Function, src).unwrap();
                assert_eq!(result.as_str(), src);
                let mut result = result.next().unwrap().into_inner();
                let mut inner = result.next().unwrap().into_inner();
                let ident = inner.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "compute");
                let block = result.next().unwrap();
                assert_eq!(block.as_rule(), Rule::Block);
                assert_eq!(block.as_str(), "    let result = \"LOL\"\n    return 23\n");
                let mut block = block.into_inner();

                let var = block.next().unwrap();
                assert_eq!(var.as_rule(), Rule::LocalStatement);
                assert_eq!(var.as_str(), "let result = \"LOL\"\n");
                let var = var.into_inner().next().unwrap();
                assert_eq!(var.as_rule(), Rule::MutableVariable);
                assert_eq!(var.as_str(), "let result = \"LOL\"\n");

                let ret = block.next().unwrap();
                assert_eq!(ret.as_rule(), Rule::LocalStatement);
                assert_eq!(ret.as_str(), "return 23\n");
                let ret = ret.into_inner().next().unwrap();
                assert_eq!(ret.as_rule(), Rule::ReturnStatement);
                assert_eq!(ret.as_str(), "return 23\n");
            }
        }

        mod invalid {
            use super::*;

            #[test]
            fn no() {
                let result = CoriumParser::parse(Rule::Function, "function");
                assert!(result.is_err());
            }

            #[test]
            fn no_ident() {
                let result = CoriumParser::parse(Rule::Function, "function ()");
                assert!(result.is_err());
            }

            #[test]
            fn no_fun() {
                let result = CoriumParser::parse(Rule::Function, "() int");
                assert!(result.is_err());
            }

            #[test]
            fn no_parenthesis() {
                let result = CoriumParser::parse(Rule::Function, "function x");
                assert!(result.is_err());
            }

            #[test]
            fn no_space() {
                let result = CoriumParser::parse(Rule::Function, "funx()");
                assert!(result.is_err());
            }

            #[test]
            fn ret_no_parenthesis() {
                let result = CoriumParser::parse(Rule::Function, "function x float");
                assert!(result.is_err());
            }

            #[test]
            fn no_body() {
                let result = CoriumParser::parse(Rule::Function, "function f () int");
                assert!(result.is_err());
            }

            #[test]
            fn no_newline() {
                let result = CoriumParser::parse(Rule::Function, "function f () int {}");
                assert!(result.is_err());
            }

            #[test]
            fn no_newline2() {
                let result = CoriumParser::parse(Rule::Function, "function f () int {}\n");
                assert!(result.is_err());
            }

            #[test]
            fn no_newline3() {
                let result = CoriumParser::parse(Rule::Function, "function f () int {\n}");
                assert!(result.is_err());
            }
        }
    }

    mod module {
        use super::*;

        mod valid {
            use super::*;

            #[test]
            fn simple() {
                let result = CoriumParser::parse(Rule::Module, "module MyPackage\n")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "module MyPackage\n");
            }

            #[test]
            fn nested() {
                let result = CoriumParser::parse(Rule::Module, "module MyPackage.Class\n")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "module MyPackage.Class\n");
            }

            #[test]
            fn nested2() {
                let result =
                    CoriumParser::parse(Rule::Module, "module MyPackage.Class.StaticMember\n")
                        .unwrap()
                        .as_str();
                assert_eq!(result, "module MyPackage.Class.StaticMember\n");
            }

            #[test]
            fn nested3() {
                let result = CoriumParser::parse(
                    Rule::Module,
                    "module MyPackage.Class.StaticMember.Field\n",
                )
                .unwrap()
                .as_str();
                assert_eq!(result, "module MyPackage.Class.StaticMember.Field\n");
            }
        }

        mod invalid {
            use super::*;

            #[test]
            fn numeric() {
                let result = CoriumParser::parse(Rule::Module, "module +MyPackage\n");
                assert!(result.is_err());
            }

            #[test]
            fn missing_subpackage() {
                let result = CoriumParser::parse(Rule::Module, "module MyPackage.\n");
                assert!(result.is_err());
            }

            #[test]
            fn nested_numeric() {
                let result = CoriumParser::parse(Rule::Module, "module MyPackage.10Class\n");
                assert!(result.is_err());
            }

            #[test]
            fn no_names() {
                let result = CoriumParser::parse(Rule::Module, "module .\n");
                assert!(result.is_err());
            }

            #[test]
            fn missing_super_package() {
                let result = CoriumParser::parse(Rule::Module, "module .MyPackage\n");
                assert!(result.is_err());
            }

            #[test]
            fn numeric_subpackage() {
                let result = CoriumParser::parse(Rule::Module, "module MyPackage.0\n");
                assert!(result.is_err());
            }

            #[test]
            fn dots() {
                let result = CoriumParser::parse(Rule::Module, "module MyPackage.X..y\n");
                assert!(result.is_err());
            }

            #[test]
            fn missing_subpackage_nested() {
                let result = CoriumParser::parse(Rule::Module, "module MyPackage.Class.\n");
                assert!(result.is_err());
            }

            #[test]
            fn no_newline() {
                let result = CoriumParser::parse(Rule::Module, "module MyPackage.Class");
                assert!(result.is_err());
            }

            #[test]
            fn no_space() {
                let result = CoriumParser::parse(Rule::Module, "moduleMyPackage.Class.\n");
                assert!(result.is_err());
            }
        }
    }

    mod global_statement {
        use super::*;

        mod valid {
            use super::*;

            #[test]
            fn function() {
                let src = "function f () {\n}\n";
                let mut result = CoriumParser::parse(Rule::GlobalStatement, src).unwrap();
                assert_eq!(result.as_str(), src);
                let inner = result.next().unwrap().into_inner().next().unwrap();
                assert_eq!(inner.as_rule(), Rule::Function);
            }

            #[test]
            fn native_function() {
                let src = "native function f ()\n";
                let mut result = CoriumParser::parse(Rule::GlobalStatement, src).unwrap();
                assert_eq!(result.as_str(), src);
                let inner = result.next().unwrap().into_inner().next().unwrap();
                assert_eq!(inner.as_rule(), Rule::NativeFunction);
            }

            #[test]
            fn mutable_variable() {
                let src = "let x = 10\n";
                let mut result = CoriumParser::parse(Rule::GlobalStatement, src).unwrap();
                assert_eq!(result.as_str(), src);
                let inner = result.next().unwrap().into_inner().next().unwrap();
                assert_eq!(inner.as_rule(), Rule::MutableVariable);
            }

            #[test]
            fn immutable_variable() {
                let src = "const x = 10\n";
                let mut result = CoriumParser::parse(Rule::GlobalStatement, src).unwrap();
                assert_eq!(result.as_str(), src);
                let inner = result.next().unwrap().into_inner().next().unwrap();
                assert_eq!(inner.as_rule(), Rule::ImmutableVariable);
            }
        }

        mod invalid {
            use super::*;

            #[test]
            fn literal() {
                let src = "\"Hello\"\n";
                let result = CoriumParser::parse(Rule::GlobalStatement, src);
                assert!(result.is_err());
            }
        }
    }

    mod compilation_unit {
        use super::*;

        mod valid {
            use super::*;

            #[test]
            fn module() {
                let mut result =
                    CoriumParser::parse(Rule::CompilationUnit, "module test\n").unwrap();
                assert_eq!(result.as_str(), "module test\n");
                let module = result.next().unwrap().into_inner().next().unwrap();
                assert_eq!(module.as_rule(), Rule::Module);
                assert!(result.peek().is_none());
            }

            #[test]
            fn module_functions() {
                let src = concat!(
                    "module test\n",
                    "native function f ()\n",
                    "function test () {\n",
                    "let x = 10\n",
                    "}\n",
                    "native function z ()\n"
                );
                let mut result = CoriumParser::parse(Rule::CompilationUnit, src).unwrap();
                assert_eq!(result.as_str(), src);
                let mut result = result.next().unwrap().into_inner();
                let module = result.next().unwrap();
                assert_eq!(module.as_rule(), Rule::Module);
                assert_eq!(module.into_inner().next().unwrap().as_str(), "test");

                let native_fun = result.next().unwrap();
                assert_eq!(native_fun.as_rule(), Rule::GlobalStatement);
                assert_eq!(
                    native_fun.into_inner().next().unwrap().as_rule(),
                    Rule::NativeFunction
                );

                let function = result.next().unwrap();
                assert_eq!(function.as_rule(), Rule::GlobalStatement);
                assert_eq!(
                    function.into_inner().next().unwrap().as_rule(),
                    Rule::Function
                );

                let native_fun2 = result.next().unwrap();
                assert_eq!(native_fun2.as_rule(), Rule::GlobalStatement);
                assert_eq!(
                    native_fun2.into_inner().next().unwrap().as_rule(),
                    Rule::NativeFunction
                );
            }
        }

        mod invalid {
            use super::*;

            #[test]
            fn multiple_modules() {
                let result = CoriumParser::parse(Rule::CompilationUnit, "module a\nmodule b\n");
                assert!(result.is_err());
            }
        }
    }
}
