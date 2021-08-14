use crate::ast::Int;
use std::str::FromStr;

pub fn parse_int_literal_dec(int: &str) -> Int {
    let txt = int.replace("_", "");
    Int::from_str(&txt).unwrap()
}

pub fn parse_int_literal_hex(int: &str) -> Int {
    let mut txt = int.replace("_", "");
    txt = txt.replacen("0x", "", 1);
    Int::from_str_radix(&txt, 16).unwrap()
}

pub fn parse_int_literal_bin(int: &str) -> Int {
    let mut txt = int.replace("_", "");
    txt = txt.replacen("0b", "", 1);
    Int::from_str_radix(&txt, 2).unwrap()
}

pub fn parse_int_literal_oct(int: &str) -> Int {
    let mut txt = int.replace("_", "");
    txt = txt.replacen("0o", "", 1);
    Int::from_str_radix(&txt, 8).unwrap()
}
