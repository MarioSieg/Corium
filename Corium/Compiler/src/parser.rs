use pest_derive::*;

#[derive(Parser)]
#[grammar = "corium.pest"]
pub struct CoriumParser;
