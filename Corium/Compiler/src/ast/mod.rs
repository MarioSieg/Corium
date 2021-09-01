use smallvec::{smallvec, SmallVec};
use std::convert;
use std::fmt;
use std::iter;

pub mod processor;

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

impl<'s> fmt::Display for Function<'s> {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "{} (", self.name)?;
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

#[derive(Clone, Debug)]
pub enum TypeName<'s> {
    Int,
    Float,
    Char,
    Bool,
    String,
    Custom(Identifier<'s>),
}

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

impl_token_base!(
    BinaryOperator,
    [
        ".", "+", "-", "*", "/", "%", "and", "or", "&", "|", "^", "<<", ">>", "<<+", ">>+", "<<<",
        ">>>"
    ]
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
#[derive(Debug, Clone)]
pub struct QualifiedName<'s>(pub SmallVec<[Identifier<'s>; 16]>);

impl<'s> QualifiedName<'s> {
    pub fn flat(ident: Identifier<'s>) -> Self {
        Self(smallvec![ident])
    }

    pub fn nested(idents: &[Identifier<'s>]) -> Self {
        Self(idents.into())
    }
}

impl<'s> fmt::Display for QualifiedName<'s> {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        if self.0.len() > 1 {
            write!(f, "{}", self.0[0])
        } else {
            let last = self.0.len() - 1;
            for (i, submod) in self.0.iter().enumerate() {
                write!(f, "{}", submod)?;
                if i != last {
                    write!(f, "{}", BinaryOperator::Dot.get_token())?;
                }
            }
            Ok(())
        }
    }
}

impl<'s> iter::FromIterator<Identifier<'s>> for QualifiedName<'s> {
    fn from_iter<T: IntoIterator<Item = Identifier<'s>>>(iter: T) -> Self {
        Self(SmallVec::from_iter::<T>(iter))
    }
}

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
