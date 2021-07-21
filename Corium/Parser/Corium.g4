grammar Corium;

// Keywords:
BOOL:           'bool';
CHAR:           'char';
FLOAT:          'float';
FUN:            'fun';
INT:            'int';
STRING:         'string';
LET:            'let';
NATIVE:         'native';
CONST:          'const';
MODULE:         'module';
CLASS:          'class';
STRUCT:         'struct';
RETURN:         'return';
SELF:           'self';
SELF_TYPE:      'Self';

// int literals:
INT_LITERAL_DEC: ('0' | [1-9] (Digits? | '_' + Digits));
INT_LITERAL_HEX: '0' [xX] [0-9a-fA-F] ([0-9a-fA-F_]* [0-9a-fA-F])?;
INT_LITERAL_OCT: '0' [cC] '_'* [0-7] ([0-7_]* [0-7])?;
INT_LITERAL_BIN: '0' [bB] [01] ([01_]* [01])? [lL]?;

// float literals:
FLOAT_LITERAL_DEC: (Digits '.' Digits? | '.' Digits) ExponentPart? | Digits ExponentPart;
FLOAT_LITERAL_HEX: '0' [xX] (HexDigits '.'? | HexDigits? '.' HexDigits) [pP] [+-]? Digits;

// bool literal:
BOOL_LITERAL: 'true' | 'false';

// char literal:
CHAR_LITERAL: '\'' (~['\\\r\n] | EscapeSequence) '\'';

// string literal:
STRING_LITERAL: '"' (~["\\\r\n] | EscapeSequence)* '"';

// separators:

LPAREN:             '(';
RPAREN:             ')';
LBRACE:             '{';
RBRACE:             '}';
LBRACK:             '[';
RBRACK:             ']';
SEMI:               ';';
COMMA:              ',';
DOT:                '.';

// operators:
ASSIGN:             '=';
PLUS:               '+';
PLUS_ASSIGN:        PLUS ASSIGN;
MINUS:              '-';
MINUS_ASSIGN:       MINUS ASSIGN;
MULTIPLY:           '*';
MULTIPLY_ASSIGN:    MULTIPLY ASSIGN;
DIVIDE:             '/';
DIVIDE_ASSIGN:      DIVIDE ASSIGN;
MODULO:             '%';
MODULO_ASSIGN:      MODULO ASSIGN;
BIT_AND:            '&';
BIT_AND_ASSIGN:     BIT_AND ASSIGN;
BIT_OR:             '|';
BIT_OR_ASSIGN:      BIT_OR ASSIGN;
BIT_XOR:            '^';
BIT_XOR_ASSIGN:     BIT_XOR ASSIGN;
BIT_NOT:            '~';
BIT_SHL:            '<<';
BIT_SHL_ASSIGN:     BIT_SHL ASSIGN;
BIT_SHR:            '>>';
BIT_SHR_ASSIGN:     BIT_SHL ASSIGN;
BIT_USHL:            '<<<';
BIT_USHL_ASSIGN:     BIT_SHL ASSIGN;
BIT_USHR:            '>>>';
BIT_USHR_ASSIGN:     BIT_SHL ASSIGN;
BIT_ROL:            '<<*';
BIT_ROL_ASSIGN:     BIT_ROL ASSIGN;
BIT_ROR:            '>>*';
BIT_ROR_ASSIGN:     BIT_ROR ASSIGN;
INCREMENT:          '++';
DECREMENT:          '--';
LOGICAL_NOT:        '!';
LOGICAL_AND:        '&&';
LOGICAL_OR:         '||';
LOGICAL_XOR:        '^^';
EQUALS:             '==';
NOT_EQUALS:         '!=';
LESS:               '<';
LESS_EQUALS:        '<=';
GREATER:            '>';
GREATER_EQUALS:     '>=';

// identifier:
IDENT: Letter LetterOrDigit*;

// whitespace and comments:
SPACE:                  [ \t\r\n\u000C]+ -> channel(HIDDEN);
SINGLE_LINE_COMMENT:    '#' ~[\r\n]* -> channel(HIDDEN);
MULTI_LINE_COMMENT:     '##' .*? '##' -> channel(HIDDEN);

// Fragments:
fragment EscapeSequence:    '\\' [btnfr"'\\] | '\\' ([0-3]? [0-7])? [0-7] | '\\' 'u' + HexDigit HexDigit HexDigit HexDigit;
fragment ExponentPart:      [eE] [+-]? Digits;
fragment HexDigits:         HexDigit((HexDigit | '_')* HexDigit)?;
fragment HexDigit:          [0-9a-fA-F];
fragment Digits:            [0-9] ([0-9_]* [0-9])?;
fragment LetterOrDigit:     Letter | [0-9] | '_';
fragment Letter:            [a-zA-Z];

compilationUnit
    :
    moduleDeclaration
    compilationUnitStatement*
    EOF
    ;

moduleDeclaration
    :
    MODULE
    qualifiedName
    ;

compilationUnitStatement
    : functionDeclaration
    | classDeclaration
    | nativeFunctionDeclaration
    | constVariableDeclaration
    | SPACE
    ;

classDeclaration
    :
    (CLASS | STRUCT)
    (IDENT | builtinType)
    LBRACE
    classBlockStatement*
    RBRACE
    ;

classBlockStatement
    : constVariableDeclaration
    | functionDeclaration
    ;

nativeFunctionDeclaration
    :
    NATIVE
    functionHeader
    ;

functionDeclaration
    :
    functionHeader
    LBRACE
    functionBlockStatement*
    RBRACE
    ;

functionCall
    :
    qualifiedName
    LPAREN
    expressionList?
    RPAREN
    ;

functionHeader
    :
    FUN
    IDENT
    LPAREN
    SELF?
    parameterList?
    RPAREN
    typeName?
    ;

functionBlockStatement
    : localVariableDeclaration
    | constVariableDeclaration
    | returnStatement
    | expression
    ;

returnStatement
    :
    RETURN
    expression
    ;

localVariableDeclaration
    :
    LET
    typeName
    ASSIGN
    expression
    ;

constVariableDeclaration
    :
    CONST
    typeName
    ASSIGN
    expression
    ;

parameterList
    :
    parameter
    (COMMA parameter)*
    ;

parameter
    :
    IDENT
    typeName;

typeName
    : builtinType
    | qualifiedName
    ;

builtinType
    : INT
    | FLOAT
    | CHAR
    | BOOL
    | STRING
    | SELF_TYPE
    ;

qualifiedName
    :
    IDENT
    (DOT IDENT)*
    ;

expressionList
    :
    expression
    (COMMA expression)*
    ;

expression
    : IDENT
    | SELF
    | literal
    | functionCall
    | expression postfix=(INCREMENT | DECREMENT)
    | prefix=(PLUS | MINUS | INCREMENT | DECREMENT) expression
    | prefix=(LOGICAL_NOT | BIT_NOT) expression
    | expression bop=(PLUS | MINUS | MULTIPLY | DIVIDE | MODULO) expression
    | expression bop=(LOGICAL_AND | LOGICAL_OR | LOGICAL_XOR) expression
    | expression bop=(EQUALS | NOT_EQUALS | LESS | LESS_EQUALS | GREATER | GREATER_EQUALS) expression
    | expression bop=(BIT_AND | BIT_OR | BIT_XOR | BIT_SHL | BIT_SHR | BIT_USHL | BIT_USHR | BIT_ROL | BIT_ROR) expression
    | <assoc=right> expression
        bop=
        (
            ASSIGN
            | PLUS_ASSIGN
            | MINUS_ASSIGN
            | MULTIPLY_ASSIGN
            | DIVIDE_ASSIGN
            | MODULO_ASSIGN
            | BIT_AND_ASSIGN
            | BIT_OR_ASSIGN
            | BIT_AND_ASSIGN
            | BIT_SHL_ASSIGN
            | BIT_SHR_ASSIGN
            | BIT_USHL_ASSIGN
            | BIT_USHR_ASSIGN
            | BIT_ROL_ASSIGN
            | BIT_ROR_ASSIGN
        ) expression
    ;

literal
    : intLiteral
    | floatLiteral
    | BOOL_LITERAL
    | CHAR_LITERAL
    | STRING_LITERAL
    ;

intLiteral
    : INT_LITERAL_DEC
    | INT_LITERAL_HEX
    | INT_LITERAL_OCT
    | INT_LITERAL_BIN
    ;

floatLiteral
    : FLOAT_LITERAL_DEC
    | FLOAT_LITERAL_HEX
    ;
