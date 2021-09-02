use std::convert;
use std::fmt;

pub mod processor;
pub mod table;

pub trait AstComponent: Clone + fmt::Display + fmt::Debug {}

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

impl<'s> AstComponent for Function<'s> {}

impl<'s> fmt::Display for Function<'s> {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "{}(", self.name)?;
        for param in &self.parameters {
            write!(f, "{}", param)?;
        }
        write!(f, ")")?;
        if let Some(ret) = &self.return_type {
            write!(f, " {}", ret)
        } else {
            Ok(())
        }
    }
}

/// Represents a local variable
#[derive(Clone, Debug)]
pub struct Variable<'s> {
    pub name: Identifier<'s>,
    pub type_hint: Option<TypeName<'s>>,
    pub value: Option<Box<Expression<'s>>>,
    pub is_parameter: bool,
}

impl<'s> AstComponent for Variable<'s> {}

impl<'s> fmt::Display for Variable<'s> {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        if self.is_parameter {
            write!(f, "let ")?;
        }
        write!(f, "{}", self.name)?;
        if let Some(typename) = &self.type_hint {
            write!(f, " {}", typename)?;
        } else {
            write!(f, " ")?;
        }
        if let Some(_value) = &self.value {
            write!(f, "= !")
        } else {
            write!(f, "= ?")
        }
    }
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

impl<'s> AstComponent for Expression<'s> {}

impl<'s> fmt::Display for Expression<'s> {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        match self {
            Self::Literal(lit) => write!(f, "{}", lit),
            Self::Unary { op, val } => {
                write!(f, "{} {}", op, val)
            }
            Self::Binary { lhs, op, rhs } => {
                write!(f, "{} {} {}", lhs, op, rhs)
            }
        }
    }
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

impl<'s> AstComponent for TypeName<'s> {}

impl<'s> convert::From<&'s str> for TypeName<'s> {
    fn from(st: &'s str) -> Self {
        match st {
            "int" => TypeName::Int,
            "float" => TypeName::Float,
            "char" => TypeName::Char,
            "bool" => TypeName::Bool,
            "string" => TypeName::String,
            _ => TypeName::Custom(st),
        }
    }
}

impl<'s> fmt::Display for TypeName<'s> {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        match self {
            Self::Int => write!(f, "int"),
            Self::Float => write!(f, "float"),
            Self::Char => write!(f, "char"),
            Self::Bool => write!(f, "bool"),
            Self::String => write!(f, "string"),
            Self::Custom(name) => write!(f, "{}", name),
        }
    }
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

impl<'s> AstComponent for Literal<'s> {}

impl<'s> fmt::Display for Literal<'s> {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        match self {
            Self::Int(x) => write!(f, "{}", x),
            Self::Float(x) => write!(f, "{}", x),
            Self::Char(x) => write!(f, "'{}'", x),
            Self::Bool(x) => write!(f, "{}", x),
            Self::String(x) => write!(f, "\"{}\"", x),
        }
    }
}

/// Represents a binary operator.
#[repr(usize)]
#[derive(Copy, Clone, Eq, PartialEq, Debug)]
pub enum BinaryOperator {
    /// .
    Dot,

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

impl AstComponent for BinaryOperator {}

impl fmt::Display for BinaryOperator {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        match self {
            Self::Dot => write!(f, "."),
            Self::Add => write!(f, "+"),
            Self::Sub => write!(f, "-"),
            Self::Mul => write!(f, "*"),
            Self::Div => write!(f, "/"),
            Self::Mod => write!(f, "%"),
            Self::And => write!(f, "and"),
            Self::Or => write!(f, "or"),
            Self::BitAnd => write!(f, "&"),
            Self::BitOr => write!(f, "|"),
            Self::BitXor => write!(f, "^"),
            Self::BitShiftLeft => write!(f, "<<"),
            Self::BitShiftRight => write!(f, ">>"),
            Self::BitShiftLeftUnsigned => write!(f, "<<<"),
            Self::BitShiftRightUnsigned => write!(f, ">>>"),
            Self::BitRotationLeft => write!(f, "<<<<"),
            Self::BitRotationRight => write!(f, ">>>>"),
        }
    }
}

#[repr(usize)]
#[derive(Copy, Clone, Eq, PartialEq, Debug)]
pub enum UnaryOperator {
    Plus,
    Minus,
    Not,
    BitNot,
}

impl AstComponent for UnaryOperator {}

impl fmt::Display for UnaryOperator {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        match self {
            Self::Plus => write!(f, "+"),
            Self::Minus => write!(f, "-"),
            Self::Not => write!(f, "not"),
            Self::BitNot => write!(f, "~"),
        }
    }
}

/// Represents a qualified name - such as a module name or a class type name.
/// Qualified names can be seperated into sub paths by dots.
/// E. g. TestClass
/// E. g. Module.TestClass
/// E. g. Module.TestClass.Function
pub type QualifiedName<'s> = &'s str;

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

/// Represents the root nodes for a compilation unit.
pub type RootList<'s> = Vec<Node<'s>>;

impl<'s> AstComponent for &'s str {}
