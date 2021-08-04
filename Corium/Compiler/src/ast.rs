use smallvec::SmallVec;
use std::fmt;

pub trait TokenTable: fmt::Display {
    const TOKEN_TABLE: &'static [&'static str];

    fn get_token(&self) -> &'static str;
}

macro_rules! impl_token_base {
    ($name:ident, $tokens:expr) => {
        impl TokenTable for $name {
            const TOKEN_TABLE: &'static [&'static str] = &$tokens;

            #[inline]
            fn get_token(&self) -> &'static str {
                Self::TOKEN_TABLE[*self as usize]
            }
        }

        impl fmt::Display for $name {
            fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
                write!(f, "{}", self.get_token())
            }
        }
    };
}

/// Represents an AST node.
#[derive(Clone, Debug)]
pub enum Node<'s> {
    Module(QualifiedName<'s>),
    Function(Function<'s>),
    QualifiedName(QualifiedName<'s>),
    Identifier(Identifier<'s>),
}

/// Represents a function.
#[derive(Clone, Debug)]
pub struct Function<'s> {
    pub name: Identifier<'s>,
    pub parameters: Vec<Variable<'s>>,
    pub return_type: Option<TypeName<'s>>,
}

/// Represents a local variable
#[derive(Clone, Debug)]
pub struct Variable<'s> {
    pub name: Identifier<'s>,
    pub type_hint: Option<TypeName<'s>>,
    pub value: Option<Box<Expression<'s>>>,
}

/// Represents an expression.
#[derive(Clone, Debug)]
pub enum Expression<'s> {
    Literal(Literal<'s>),
    Unary {
        op: UnaryOperator,
        val: Box<Self>,
    },
    Binary {
        lhs: Box<Self>,
        op: BinaryOperator,
        rhs: Box<Self>,
    },
}

#[derive(Clone, Debug)]
pub enum TypeName<'s> {
    Int,
    Float,
    Char,
    Bool,
    String,
    Custom(Identifier<'s>),
}

/// Represents a literal.
#[derive(Clone, PartialEq, Debug)]
pub enum Literal<'s> {
    /// An integer literal. E.g. 5
    Int(Int),

    /// A float literal. E.g. 5.0
    Float(Float),

    /// A char literal. E.g. 'A'
    Char(Char),

    /// A bool literal. E.g. true
    Bool(Bool),

    /// A string literal. E.g. "Hello"
    String(&'s str),
}

/// Represents the type of a comment.
#[repr(usize)]
#[derive(Copy, Clone, Eq, PartialEq, Debug)]
pub enum CommentType {
    /// # comment
    Line,

    /// ##
    /// bla bla bla
    /// bla bla
    /// ##
    Block,
}

impl_token_base!(CommentType, ["#", "##"]);

/// Represents a binary operator.
#[repr(usize)]
#[derive(Copy, Clone, Eq, PartialEq, Debug)]
pub enum BinaryOperator {
    ///+
    Add,

    /// -
    Sub,

    /// *
    Mul,

    /// /
    Div,

    /// %
    Mod,

    /// and
    And,

    /// or
    Or,

    /// &
    BitAnd,

    /// |
    BitOr,

    /// ^
    BitXor,

    /// <<
    BitShiftLeft,

    /// >>
    BitShiftRight,

    /// <<+
    BitShiftLeftUnsigned,

    /// >>+
    BitShiftRightUnsigned,

    /// <<<
    BitRotationLeft,

    /// >>>
    BitRotationRight,
}

impl_token_base!(
    BinaryOperator,
    ["+", "-", "*", "/", "%", "and", "or", "&", "|", "^", "<<", ">>", "<<+", ">>+", "<<<", ">>>"]
);

#[repr(usize)]
#[derive(Copy, Clone, Eq, PartialEq, Debug)]
pub enum UnaryOperator {
    Plus,
    Minus,
    Not,
    BitNot,
}

impl_token_base!(UnaryOperator, ["+", "-", "not", "~"]);

/// Represents a qualified name - such as a module name or a class type name.
/// Qualified names can be seperated into sub paths by dots.
/// E. g. TestClass
/// E. g. Module.TestClass
/// E. g. Module.TestClass.Function
pub type QualifiedName<'s> = SmallVec<[Identifier<'s>; 16]>;

/// Represents an identifier such as a class or variable name.
pub type Identifier<'s> = &'s str;

/// Represents a Corium "int".
pub type Int = i64;

/// Represents a Corium "float".
pub type Float = f64;

/// Represents a Corium "bool".
pub type Bool = bool;

/// Represents a Corium "char".
pub type Char = u32;
