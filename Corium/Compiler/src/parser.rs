#[allow(dead_code)]
#[allow(clippy::all)]
pub mod generated {
    include!(concat!(env!("OUT_DIR"), "/grammar/grammar.rs"));
}

#[cfg(test)]
mod tests {
    use super::generated::IntParser;

    #[test]
    fn parse_num_dec() {
        assert_eq!(IntParser::new().parse("0").unwrap(), 0_i64);
        assert_eq!(IntParser::new().parse("12456").unwrap(), 12456_i64);
        assert_eq!(IntParser::new().parse("124_56").unwrap(), 12456_i64);
        assert_eq!(IntParser::new().parse("1_2_4_5_6").unwrap(), 12456_i64);
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

    #[test]
    fn parse_num_hex() {
        assert_eq!(IntParser::new().parse("0xFF").unwrap(), 0xFF_i64);
        assert_eq!(IntParser::new().parse("-0x5").unwrap(), -5_i64);
        assert_eq!(IntParser::new().parse("0xFFFF").unwrap(), 0xFFFF_i64);
        assert_eq!(IntParser::new().parse("0x_F_F").unwrap(), 0xFF_i64);
        assert_eq!(IntParser::new().parse("-0x5_0").unwrap(), -0x50_i64);
        assert_eq!(IntParser::new().parse("0xF_F_F_F").unwrap(), 0xFFFF_i64);
        assert_eq!(
            IntParser::new().parse("0x7FFFFFFFFFFFFFFF").unwrap(),
            i64::MAX
        );
        assert_eq!(
            IntParser::new().parse("-0x8000000000000000").unwrap(),
            i64::MIN
        );
    }

    #[test]
    fn parse_num_bin() {
        assert_eq!(IntParser::new().parse("0b1010101").unwrap(), 0b1010101_i64);
        assert_eq!(
            IntParser::new().parse("-0b10_1_0_101").unwrap(),
            -0b10_1_0_101_i64
        );
        assert_eq!(IntParser::new().parse("0b1111").unwrap(), 0b1111_i64);
        assert_eq!(IntParser::new().parse("-0b11").unwrap(), -3_i64);
        assert_eq!(
            IntParser::new().parse("0b10101010101010111").unwrap(),
            0b10101010101010111_i64
        );
        assert_eq!(IntParser::new().parse("0b000_1").unwrap(), 1_i64);
        assert_eq!(
            IntParser::new()
                .parse("0b111111111111111111111111111111111111111111111111111111111111111")
                .unwrap(),
            i64::MAX
        );
        assert_eq!(
            IntParser::new()
                .parse("-0b1000000000000000000000000000000000000000000000000000000000000000")
                .unwrap(),
            i64::MIN
        );
    }

    #[test]
    fn parse_num_oct() {
        assert_eq!(IntParser::new().parse("0o0").unwrap(), 0o0_i64);
        assert_eq!(IntParser::new().parse("0o12456").unwrap(), 0o12456_i64);
        assert_eq!(IntParser::new().parse("0o124_56").unwrap(), 0o12456_i64);
        assert_eq!(IntParser::new().parse("0o1_2_4_5_6").unwrap(), 0o12456_i64);
        assert_eq!(IntParser::new().parse("-0o355").unwrap(), -0o355_i64);
        assert_eq!(
            IntParser::new().parse("0o777777777777777777777").unwrap(),
            i64::MAX
        );
        assert_eq!(
            IntParser::new().parse("-0o1000000000000000000000").unwrap(),
            i64::MIN
        );
    }
}
