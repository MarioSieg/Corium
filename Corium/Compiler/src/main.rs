mod ast;
mod parser;

fn main() {
    let expr = parser::generated::ExprParser::new()
        .parse("22 * 44 + 66")
        .unwrap();
    dbg!(expr);
}
