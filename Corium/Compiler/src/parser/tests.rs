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

    mod ident {
        use super::*;

        mod valid {
            use super::*;

            #[test]
            fn alphanumeric() {
                let result = CoriumParser::parse(Rule::Ident, "MyClass")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "MyClass");
            }

            #[test]
            fn mixed() {
                let result = CoriumParser::parse(Rule::Ident, "My2Class32LOl")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "My2Class32LOl");
            }

            #[test]
            fn numberic() {
                let result = CoriumParser::parse(Rule::Ident, "X278247842877284")
                    .unwrap()
                    .as_str();
                assert_eq!(result, "X278247842877284");
            }
        }

        mod invalid {
            use super::*;

            #[test]
            fn numeric() {
                let result = CoriumParser::parse(Rule::Ident, "1");
                assert!(result.is_err());
            }

            #[test]
            fn numeric2() {
                let result = CoriumParser::parse(Rule::Ident, "3MyClass");
                assert!(result.is_err());
            }

            #[test]
            fn numeric3() {
                let result = CoriumParser::parse(Rule::Ident, "0MyClass");
                assert!(result.is_err());
            }

            #[test]
            fn numeric4() {
                let result = CoriumParser::parse(Rule::Ident, "-10MyClass");
                assert!(result.is_err());
            }

            #[test]
            fn symbol() {
                let result = CoriumParser::parse(Rule::Ident, "&MyClass");
                assert!(result.is_err());
            }

            #[test]
            fn symbol2() {
                let result = CoriumParser::parse(Rule::Ident, "+MyClass");
                assert!(result.is_err());
            }

            #[test]
            fn symbol3() {
                let result = CoriumParser::parse(Rule::Ident, "*MyClass");
                assert!(result.is_err());
            }

            #[test]
            fn symbol4() {
                let result = CoriumParser::parse(Rule::Ident, "#MyClass");
                assert!(result.is_err());
            }

            #[test]
            fn symbol5() {
                let result = CoriumParser::parse(Rule::Ident, "\"MyClass");
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
                assert_eq!(ident.as_rule(), Rule::Ident);
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
                assert_eq!(ident.as_rule(), Rule::Ident);
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
                assert_eq!(ident.as_rule(), Rule::Ident);
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
                assert_eq!(ident.as_rule(), Rule::Ident);
                assert_eq!(ident.as_str(), "myParam");
                let typename = result.next().unwrap();
                assert_eq!(typename.as_rule(), Rule::QualifiedName);
                assert_eq!(typename.as_str(), "MyPackage.MyClass");
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
}
