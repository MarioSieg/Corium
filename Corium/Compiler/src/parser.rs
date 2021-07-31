#[allow(dead_code)]
#[allow(clippy::all)]
pub mod generated {
    include!(concat!(env!("OUT_DIR"), "/grammar/grammar.rs"));
}

#[cfg(test)]
mod tests {
    use super::generated::IntParser;

    #[test]
    fn parse_num_decimal() {
        assert_eq!(IntParser::new().parse("0").unwrap(), 0_i64);
        assert_eq!(IntParser::new().parse("12456").unwrap(), 12456_i64);
        assert_eq!(IntParser::new().parse("-355").unwrap(), -355_i64);
        assert_eq!(
            IntParser::new().parse("9223372036854775807").unwrap(),
            i64::MAX
        );
        assert_eq!(
            IntParser::new().parse("-9223372036854775808").unwrap(),
            i64::MIN
        );
    }
}
