parser grammar CoriumParser;

options { tokenVocab=CoriumLexer; }

localVariableDeclaration: LET WHITESPACE IDENT ASSIGN literal;
literal: intLiteral | floatLiteral | BOOL_LITERAL | CHAR_LITERAL | STRING_LITERAL;
intLiteral: INT_LITERAL_DEC | INT_LITERAL_HEX | INT_LITERAL_OCT | INT_LITERAL_BIN;
floatLiteral: FLOAT_LITERAL_DEC | FLOAT_LITERAL_HEX;
primitiveType: INT | FLOAT | CHAR | BOOL;
