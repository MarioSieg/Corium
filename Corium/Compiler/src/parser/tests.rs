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
            fn backspace() {
                let result = CoriumParser::parse(Rule::Char, r#"\b"#).unwrap().as_str();
                assert_eq!(result, r#"\b"#);
            }

            #[test]
            fn formfeed_page_break() {
                let result = CoriumParser::parse(Rule::Char, r#"\f"#).unwrap().as_str();
                assert_eq!(result, r#"\f"#);
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
            fn vertical_tab() {
                let result = CoriumParser::parse(Rule::Char, r#"\v"#).unwrap().as_str();
                assert_eq!(result, r#"\v"#);
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
            fn escapes() {
                let result = CoriumParser::parse(
                    Rule::StringLiteral,
                    r#""Hallo :) \" \\ \" / \b \f \n \r \t \v""#,
                )
                .unwrap()
                .as_str();
                assert_eq!(result, r#""Hallo :) \" \\ \" / \b \f \n \r \t \v""#);
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
            fn backspace() {
                let result = CoriumParser::parse(Rule::CharLiteral, r#"'\b'"#)
                    .unwrap()
                    .as_str();
                assert_eq!(result, r#"'\b'"#);
            }

            #[test]
            fn formfeed_page_break() {
                let result = CoriumParser::parse(Rule::CharLiteral, r#"'\f'"#)
                    .unwrap()
                    .as_str();
                assert_eq!(result, r#"'\f'"#);
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
            fn vertical_tab() {
                let result = CoriumParser::parse(Rule::CharLiteral, r#"'\v'"#)
                    .unwrap()
                    .as_str();
                assert_eq!(result, r#"'\v'"#);
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
            fn zero_negative() {
                let result = CoriumParser::parse(Rule::IntLiteral, "-0")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "-0");
            }

            #[test]
            fn zero_positive() {
                let result = CoriumParser::parse(Rule::IntLiteral, "+0")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "+0");
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
                let result = CoriumParser::parse(Rule::IntLiteral, "+10")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "+10");
            }

            #[test]
            fn simple_negative() {
                let result = CoriumParser::parse(Rule::IntLiteral, "-10")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "-10");
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
                let result = CoriumParser::parse(Rule::IntLiteral, "-0_2_4_20203_2200_22")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "-0_2_4_20203_2200_22");
            }

            #[test]
            fn simple_separated4() {
                let result = CoriumParser::parse(Rule::IntLiteral, "+0_2_4_20203_2200_22")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "+0_2_4_20203_2200_22");
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

            #[test]
            fn double_minus() {
                let result = CoriumParser::parse(Rule::IntLiteral, "--2233-2");
                assert!(result.is_err());
            }

            #[test]
            fn double_plus() {
                let result = CoriumParser::parse(Rule::IntLiteral, "++2233+2");
                assert!(result.is_err());
            }

            #[test]
            fn minus_within() {
                let result = CoriumParser::parse(Rule::IntLiteral, "+-3-3-2");
                assert!(result.is_err());
            }

            #[test]
            fn plus_within() {
                let result = CoriumParser::parse(Rule::IntLiteral, "-+2+3+3+2");
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
            fn zero_negative() {
                let result = CoriumParser::parse(Rule::FloatLiteral, "-0.0")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "-0.0");
            }

            #[test]
            fn zero_positive() {
                let result = CoriumParser::parse(Rule::FloatLiteral, "+0.0")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "+0.0");
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
                let result = CoriumParser::parse(Rule::FloatLiteral, "+1.6")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "+1.6");
            }

            #[test]
            fn simple_negative() {
                let result = CoriumParser::parse(Rule::FloatLiteral, "-1.5")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "-1.5");
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
                let result = CoriumParser::parse(Rule::FloatLiteral, "-0_2_4_20.203_2200_22")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "-0_2_4_20.203_2200_22");
            }

            #[test]
            fn simple_separated4() {
                let result = CoriumParser::parse(Rule::FloatLiteral, "+0.0_2_4_20203_2200_22")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "+0.0_2_4_20203_2200_22");
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
        }

        mod invalid {
            use super::*;

            #[test]
            fn empty() {
                let result = CoriumParser::parse(Rule::Expression, "");
                assert!(result.is_err());
            }

            #[test]
            fn text() {
                let result = CoriumParser::parse(Rule::Expression, "Trololo");
                assert!(result.is_err());
            }

            #[test]
            fn symbols() {
                let result = CoriumParser::parse(Rule::Expression, "?!?");
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

    mod local_variable {
        use super::*;

        mod valid {
            use super::*;

            #[test]
            fn int() {
                let mut result = CoriumParser::parse(Rule::LocalVariable, "let x = 10\n").unwrap();
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
                    CoriumParser::parse(Rule::LocalVariable, "let x = 10.0\n").unwrap();
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
                let mut result = CoriumParser::parse(Rule::LocalVariable, "let x = 'x'\n").unwrap();
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
                    CoriumParser::parse(Rule::LocalVariable, "let x = true\n").unwrap();
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
                    CoriumParser::parse(Rule::LocalVariable, "let x = \"Name\"\n").unwrap();
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
                    CoriumParser::parse(Rule::LocalVariable, "let x int = 10\n").unwrap();
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
                    CoriumParser::parse(Rule::LocalVariable, "let x float = 10.0\n").unwrap();
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
                    CoriumParser::parse(Rule::LocalVariable, "let x char = 'x'\n").unwrap();
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
                    CoriumParser::parse(Rule::LocalVariable, "let x bool = true\n").unwrap();
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
                    CoriumParser::parse(Rule::LocalVariable, "let x string = \"Name\"\n").unwrap();
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
                let result = CoriumParser::parse(Rule::LocalVariable, "let\n");
                assert!(result.is_err());
            }

            #[test]
            fn missing2() {
                let result = CoriumParser::parse(Rule::LocalVariable, "let=\n");
                assert!(result.is_err());
            }

            #[test]
            fn missing3() {
                let result = CoriumParser::parse(Rule::LocalVariable, "let = \n");
                assert!(result.is_err());
            }

            #[test]
            fn missing4() {
                let result = CoriumParser::parse(Rule::LocalVariable, "let x\n");
                assert!(result.is_err());
            }

            #[test]
            fn missing5() {
                let result = CoriumParser::parse(Rule::LocalVariable, "let x int\n");
                assert!(result.is_err());
            }

            #[test]
            fn missing6() {
                let result = CoriumParser::parse(Rule::LocalVariable, "let x int = \n");
                assert!(result.is_err());
            }

            #[test]
            fn no_space() {
                let result = CoriumParser::parse(Rule::LocalVariable, "let x=10\n");
                assert!(result.is_err());
            }

            #[test]
            fn no_space2() {
                let result = CoriumParser::parse(Rule::LocalVariable, "letx=3\n");
                assert!(result.is_err());
            }

            #[test]
            fn no_newline() {
                let result = CoriumParser::parse(Rule::LocalVariable, "let x = 10");
                assert!(result.is_err());
            }
        }
    }

    mod function_statement {
        use super::*;

        mod valid {
            use super::*;

            #[test]
            fn local_var() {
                let mut result =
                    CoriumParser::parse(Rule::FunctionStatement, "let x = 10\n").unwrap();
                let mut result = result.next().unwrap().into_inner();
                let var = result.next().unwrap();
                assert_eq!(var.as_rule(), Rule::LocalVariable);
                assert_eq!(var.as_str(), "let x = 10\n");
            }

            #[test]
            fn return_statement() {
                let mut result = CoriumParser::parse(Rule::FunctionStatement, "return\n").unwrap();
                let mut result = result.next().unwrap().into_inner();
                let var = result.next().unwrap();
                assert_eq!(var.as_rule(), Rule::ReturnStatement);
                assert_eq!(var.as_str(), "return\n");
            }

            #[test]
            fn return_statement2() {
                let mut result =
                    CoriumParser::parse(Rule::FunctionStatement, "return true\n").unwrap();
                let mut result = result.next().unwrap().into_inner();
                let var = result.next().unwrap();
                assert_eq!(var.as_rule(), Rule::ReturnStatement);
                assert_eq!(var.as_str(), "return true\n");
            }
        }

        mod invalid {
            use super::*;

            #[test]
            fn invalid() {
                let result = CoriumParser::parse(Rule::FunctionStatement, "HELLO THERE");
                assert!(result.is_err());
            }

            #[test]
            fn invalid2() {
                let result = CoriumParser::parse(Rule::FunctionStatement, "42742");
                assert!(result.is_err());
            }

            #[test]
            fn invalid3() {
                let result = CoriumParser::parse(Rule::FunctionStatement, "fun f()");
                assert!(result.is_err());
            }

            #[test]
            fn separators() {
                let result = CoriumParser::parse(Rule::FunctionStatement, " \n  \t \t \n\n  \n");
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
                let mut result = CoriumParser::parse(Rule::FunctionSignature, "fun f()").unwrap();
                assert_eq!(result.as_str(), "fun f()");
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "f");
            }

            #[test]
            fn return_type() {
                let mut result =
                    CoriumParser::parse(Rule::FunctionSignature, "fun f() int").unwrap();
                assert_eq!(result.as_str(), "fun f() int");
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
                    CoriumParser::parse(Rule::FunctionSignature, "fun f(x float)").unwrap();
                assert_eq!(result.as_str(), "fun f(x float)");
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
                    "fun f(x float, name string, ok bool = true)",
                )
                .unwrap();
                assert_eq!(
                    result.as_str(),
                    "fun f(x float, name string, ok bool = true)"
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
                    CoriumParser::parse(Rule::FunctionSignature, "fun f(x float) float").unwrap();
                assert_eq!(result.as_str(), "fun f(x float) float");
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
                let mut result = CoriumParser::parse(Rule::FunctionSignature, "fun f(x float, name string, ok bool = true, a int, b int, c float, d char, z string) char").unwrap();
                assert_eq!(result.as_str(), "fun f(x float, name string, ok bool = true, a int, b int, c float, d char, z string) char");
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
                let result = CoriumParser::parse(Rule::FunctionSignature, "fun");
                assert!(result.is_err());
            }

            #[test]
            fn no_ident() {
                let result = CoriumParser::parse(Rule::FunctionSignature, "fun ()");
                assert!(result.is_err());
            }

            #[test]
            fn no_fun() {
                let result = CoriumParser::parse(Rule::FunctionSignature, "() int");
                assert!(result.is_err());
            }

            #[test]
            fn no_parenthesis() {
                let result = CoriumParser::parse(Rule::FunctionSignature, "fun x");
                assert!(result.is_err());
            }

            #[test]
            fn no_space() {
                let result = CoriumParser::parse(Rule::FunctionSignature, "funx()");
                assert!(result.is_err());
            }

            #[test]
            fn ret_no_parenthesis() {
                let result = CoriumParser::parse(Rule::FunctionSignature, "fun x float");
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
                    CoriumParser::parse(Rule::NativeFunction, "native fun f()\n").unwrap();
                assert_eq!(result.as_str(), "native fun f()\n");
                let mut result = result.next().unwrap().into_inner();
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "f");
            }

            #[test]
            fn return_type() {
                let mut result =
                    CoriumParser::parse(Rule::NativeFunction, "native fun f() int\n").unwrap();
                assert_eq!(result.as_str(), "native fun f() int\n");
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
                    CoriumParser::parse(Rule::NativeFunction, "native fun f(x float)\n").unwrap();
                assert_eq!(result.as_str(), "native fun f(x float)\n");
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
                    "native fun f(x float, name string, ok bool = true)\n",
                )
                .unwrap();
                assert_eq!(
                    result.as_str(),
                    "native fun f(x float, name string, ok bool = true)\n"
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
                    CoriumParser::parse(Rule::NativeFunction, "native fun f(x float) float\n")
                        .unwrap();
                assert_eq!(result.as_str(), "native fun f(x float) float\n");
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
                let mut result = CoriumParser::parse(Rule::NativeFunction, "native fun f(x float, name string, ok bool = true, a int, b int, c float, d char, z string) char\n").unwrap();
                assert_eq!(result.as_str(), "native fun f(x float, name string, ok bool = true, a int, b int, c float, d char, z string) char\n");
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
                let result = CoriumParser::parse(Rule::NativeFunction, "native fun\n");
                assert!(result.is_err());
            }

            #[test]
            fn no_ident() {
                let result = CoriumParser::parse(Rule::NativeFunction, "native fun ()\n");
                assert!(result.is_err());
            }

            #[test]
            fn no_fun() {
                let result = CoriumParser::parse(Rule::NativeFunction, "native () int\n");
                assert!(result.is_err());
            }

            #[test]
            fn no_parenthesis() {
                let result = CoriumParser::parse(Rule::NativeFunction, "native fun x\n");
                assert!(result.is_err());
            }

            #[test]
            fn no_space() {
                let result = CoriumParser::parse(Rule::NativeFunction, "native funx()\n");
                assert!(result.is_err());
            }

            #[test]
            fn ret_no_parenthesis() {
                let result = CoriumParser::parse(Rule::NativeFunction, "native fun x float\n");
                assert!(result.is_err());
            }

            #[test]
            fn ret_newline() {
                let result = CoriumParser::parse(Rule::NativeFunction, "native fun f()");
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
                let mut result = CoriumParser::parse(Rule::Function, "fun f() {\n}\n").unwrap();
                assert_eq!(result.as_str(), "fun f() {\n}\n");
                let mut result = result.next().unwrap().into_inner();
                let mut result = result.next().unwrap().into_inner();
                let ident = result.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "f");
            }

            #[test]
            fn return_type() {
                let mut result = CoriumParser::parse(Rule::Function, "fun f() int {\n}\n").unwrap();
                assert_eq!(result.as_str(), "fun f() int {\n}\n");
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
                    CoriumParser::parse(Rule::Function, "fun f(x float) {\n}\n").unwrap();
                assert_eq!(result.as_str(), "fun f(x float) {\n}\n");
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
                    "fun f(x float, name string, ok bool = true) {\n}\n",
                )
                .unwrap();
                assert_eq!(
                    result.as_str(),
                    "fun f(x float, name string, ok bool = true) {\n}\n"
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
                    CoriumParser::parse(Rule::Function, "fun f(x float) float {\n}\n").unwrap();
                assert_eq!(result.as_str(), "fun f(x float) float {\n}\n");
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
                let mut result = CoriumParser::parse(Rule::Function, "fun f(x float, name string, ok bool = true, a int, b int, c float, d char, z string) char {\n}\n").unwrap();
                assert_eq!(result.as_str(), "fun f(x float, name string, ok bool = true, a int, b int, c float, d char, z string) char {\n}\n");
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
                let mut result = CoriumParser::parse(Rule::Function, "fun f() {\n}\n").unwrap();
                assert_eq!(result.as_str(), "fun f() {\n}\n");
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
                    CoriumParser::parse(Rule::Function, "fun f() {\nreturn 10\n}\n").unwrap();
                assert_eq!(result.as_str(), "fun f() {\nreturn 10\n}\n");
                let mut result = result.next().unwrap().into_inner();
                let mut inner = result.next().unwrap().into_inner();
                let ident = inner.next().unwrap();
                assert_eq!(ident.as_rule(), Rule::Identifier);
                assert_eq!(ident.as_str(), "f");
                let block = result.next().unwrap();
                assert_eq!(block.as_rule(), Rule::Block);
                assert_eq!(block.as_str(), "return 10\n");
                let smt = block.into_inner().next().unwrap();
                assert_eq!(smt.as_rule(), Rule::FunctionStatement);
                assert_eq!(smt.as_str(), "return 10\n");
                let ret = smt.into_inner().next().unwrap();
                assert_eq!(ret.as_rule(), Rule::ReturnStatement);
                assert_eq!(ret.as_str(), "return 10\n");
            }

            #[test]
            fn complex() {
                let src = concat!(
                    "fun compute(x int) int {\n",
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
                assert_eq!(var.as_rule(), Rule::FunctionStatement);
                assert_eq!(var.as_str(), "let result = \"LOL\"\n");
                let var = var.into_inner().next().unwrap();
                assert_eq!(var.as_rule(), Rule::LocalVariable);
                assert_eq!(var.as_str(), "let result = \"LOL\"\n");

                let ret = block.next().unwrap();
                assert_eq!(ret.as_rule(), Rule::FunctionStatement);
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
                let result = CoriumParser::parse(Rule::Function, "fun");
                assert!(result.is_err());
            }

            #[test]
            fn no_ident() {
                let result = CoriumParser::parse(Rule::Function, "fun ()");
                assert!(result.is_err());
            }

            #[test]
            fn no_fun() {
                let result = CoriumParser::parse(Rule::Function, "() int");
                assert!(result.is_err());
            }

            #[test]
            fn no_parenthesis() {
                let result = CoriumParser::parse(Rule::Function, "fun x");
                assert!(result.is_err());
            }

            #[test]
            fn no_space() {
                let result = CoriumParser::parse(Rule::Function, "funx()");
                assert!(result.is_err());
            }

            #[test]
            fn ret_no_parenthesis() {
                let result = CoriumParser::parse(Rule::Function, "fun x float");
                assert!(result.is_err());
            }

            #[test]
            fn no_body() {
                let result = CoriumParser::parse(Rule::Function, "fun f() int");
                assert!(result.is_err());
            }

            #[test]
            fn no_newline() {
                let result = CoriumParser::parse(Rule::Function, "fun f() int {}");
                assert!(result.is_err());
            }

            #[test]
            fn no_newline2() {
                let result = CoriumParser::parse(Rule::Function, "fun f() int {}\n");
                assert!(result.is_err());
            }

            #[test]
            fn no_newline3() {
                let result = CoriumParser::parse(Rule::Function, "fun f() int {\n}");
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
}
