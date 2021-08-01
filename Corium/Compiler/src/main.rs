mod ast;
mod literal;
mod parser;

fn main() {
    let expr = parser::generated::ExprParser::new()
        .parse("22 * (44 + 66) % 2")
        .unwrap();
    dbg!(expr);
}
