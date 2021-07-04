lexer grammar CoriumLexer;

// Keywords:

LET:            'let';
FUN:            'fun';

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
STRING_LITERAL: '"' (~["\\\r\n] | EscapeSequence) '"';

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

// identifier:
IDENT: Letter LetterOrDigit*;

// whitespace and comments:
WHITESPACE:             [\t\r\n]+ -> channel(HIDDEN);
SINGLE_LINE_COMMENT:    '#' ~[\r\n]* -> channel(HIDDEN);
MULTI_LINE_COMMENT:     '##' .*? '##' -> channel(HIDDEN);

// Fragments:
fragment EscapeSequence: '\\' [btnfr"'\\] | '\\' ([0-3]? [0-7])? [0-7] | '\\' 'u' + HexDigit HexDigit HexDigit HexDigit;
fragment ExponentPart: [eE] [+-]? Digits;
fragment HexDigits: HexDigit((HexDigit | '_')* HexDigit)?;
fragment HexDigit: [0-9a-fA-F];
fragment Digits: [0-9] ([0-9_]* [0-9])?;
fragment LetterOrDigit: Letter | [0-9];
fragment Letter: [a-zA-Z];