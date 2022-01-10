#include "corium.h"

static void parse_ident(parser_t *p) {
    p->iB = p->s - 1;
    p->iE = p->s;
    while ((p->p = *++p->s) && (p->p >= 'a' && p->p <= 'z') || (p->p >= 'A' && p->p <= 'Z') || p->p == '_') ++p->iE;
    p->tok = TK_IDENT;
}

static void parse_int_literal(parser_t *p) {
    p->tok = TK_INT_LIT;
    if ((p->val.imm = p->p - '0')) { // dec
        while (*p->s >= '0' && *p->s <= '9') p->val.imm = p->val.imm * 10 + *p->s++ - '0';
    } else if (*p->s == 'x' || *p->s == 'X') { // hex
        while ((p->p = *++p->s)
            && ((p->p >= '0'
            && p->p <= '9')
            || (p->p >= 'a'
            && p->p <= 'f')
            || (p->p >= 'A'
            && p->p <= 'F')))
            p->val.imm = p->val.imm * 16 + (p->p & 15) + (p->p >= 'A' ? 9 : 0);
    } else { // oct
        while (*p->s >= '0' && *p->s <= '7') p->val.imm = p->val.imm * 8 + *p->s++ - '0';
    }
}

static void parse_common(parser_t *p) {
    switch (p->p) {
        case SY_ASSIGN: if (*p->s == SY_ASSIGN) { ++p->s; p->tok = TK_EQ; } else p->tok = TK_ASSIGN; return;
        case SY_ADD: if (*p->s == SY_ADD) { ++p->s; p->tok = TK_INC; } else p->tok = TK_ADD; return;
        case SY_SUB: if (*p->s == SY_SUB) { ++p->s; p->tok = TK_DEC; } else p->tok = TK_SUB; return;
        case SY_NOT: if (*p->s == SY_ASSIGN) { ++p->s; p->tok = TK_NE; } return;
        case SY_LT:
            if (*p->s == SY_ASSIGN) { ++p->s; p->tok = TK_LE; }
            else if (*p->s == SY_LT && *(p->s + 1) != SY_LT) { ++p->s; p->tok = TK_SHL; }
            else if (*p->s == SY_LT) { ++p->s; p->tok = TK_ROL; }
            else p->tok = TK_LT;
        return;
        case SY_GT:
            if (*p->s == SY_ASSIGN) { ++p->s; p->tok = TK_GE; }
            else if (*p->s == SY_GT && *(p->s + 1) != SY_GT) { ++p->s; p->tok = TK_SHR; }
            else if (*p->s == SY_GT) { ++p->s; p->tok = TK_ROR; }
            else p->tok = TK_GT;
        return;
        case SY_AND: if (*p->s == SY_AND) { ++p->s; p->tok = TK_LAND; } else p->tok = TK_AND; return;
        case SY_OR: if (*p->s == SY_OR) { ++p->s; p->tok = TK_LOR; } else p->tok = TK_OR; return;
        case SY_MUL: p->tok = TK_MUL; return;
        case SY_DIV: p->tok = TK_DIV; return;
        case SY_MOD: p->tok = TK_MOD; return;
        case SY_XOR: p->tok = TK_XOR; return;
        case SY_COMMENT:
            for(; *p->s && *p->s != '\n'; ++p->s);
            ++p->s;
            parser_run(p);
        return;
        case ' ': case '\t': case '\r':
            ++p->s;
            for(; *p->s && (*p->s == ' ' || *p->s == '\t' || *p->s == '\r'); ++p->s);
            parser_run(p);
        return;
        default: return;
    }
}

void parser_run(parser_t *p) {
    if (!p->s || !*p->s) return;
    p->p = *p->s++;
    if ((p->p >= 'a' && p->p <= 'z') || (p->p >= 'A' && p->p <= 'Z') || p->p == '_')
        parse_ident(p);
    else if (p->p >= '0' && p->p <= '9')
        parse_int_literal(p);
    else
        parse_common(p);
}
