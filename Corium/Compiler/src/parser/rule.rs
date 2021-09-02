use crate::parser::Rule;
use pest::iterators::{Pair, Pairs};

pub struct RuleStrider<'a> {
    rule: Rule,
    iter: Pairs<'a, Rule>,
}

impl<'a> RuleStrider<'a> {
    pub fn new(rule: Pair<'a, Rule>) -> RuleStrider<'a> {
        Self {
            rule: rule.as_rule(),
            iter: rule.into_inner(),
        }
    }

    #[inline]
    pub fn get_rule(&self) -> &Rule {
        &self.rule
    }

    #[inline]
    pub fn get_iter(&self) -> &Pairs<'a, Rule> {
        &self.iter
    }

    #[inline]
    pub fn next(&mut self) -> Option<Pair<'a, Rule>> {
        self.iter.next()
    }

    #[inline]
    pub fn peek(&self) -> Option<Pair<'a, Rule>> {
        self.iter.peek()
    }

    #[inline]
    pub fn decay_str(mut self) -> &'a str {
        self.next().unwrap().as_str()
    }
}
