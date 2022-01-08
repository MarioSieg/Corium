#include "corium.h"
#include "corium.c"

extern void test_parser();

int main() {
    printf("Testing...\n");
    test_parser();
    printf("All tests OK!\n");
    return 0;
}

void test_parser() {
    struct parser_t *p;
    parser_new(&p);
    ASSERT(p != NULL);

    p->s = "2022";
    parser_run(p);
    ASSERT(p->imm == 2022);
    ASSERT(p->tok == TK_INT_LIT);

    p->s = "0xC0FFEE";
    parser_run(p);
    ASSERT(p->imm == 0xC0FFEE);
    ASSERT(p->tok == TK_INT_LIT);

    p->s = "#comment\n01234567";
    parser_run(p);
    ASSERT(p->imm == 01234567);
    ASSERT(p->tok == TK_INT_LIT);

    const char buf[] = "hello";
    p->s = buf;
    parser_run(p);
    ASSERT(p->tok == TK_IDENT);
    ASSERT(*p->iB == 'h');
    ASSERT(*p->iE == 'o');
    ASSERT(memcmp(buf, p->iB, sizeof(buf)) == 0);

    p->s = " \n \r  43\r\r\n ";
    parser_run(p);
    ASSERT(p->imm == 43);
    ASSERT(p->tok == TK_INT_LIT);

    p->s = "hello1234567#comment\n";
    parser_run(p);
    ASSERT(p->tok == TK_IDENT);
    ASSERT(*p->iB == 'h');
    ASSERT(*p->iE == 'o');

    parser_run(p);
    ASSERT(p->imm == 1234567);
    ASSERT(p->tok == TK_INT_LIT);

    p->s = "=";
    parser_run(p);
    ASSERT(p->tok == TK_ASSIGN);

    p->s = "==";
    parser_run(p);
    ASSERT(p->tok == TK_EQ);

    p->s = "+";
    parser_run(p);
    ASSERT(p->tok == TK_ADD);

    p->s = "++";
    parser_run(p);
    ASSERT(p->tok == TK_INC);

    p->s = "-";
    parser_run(p);
    ASSERT(p->tok == TK_SUB);

    p->s = "--";
    parser_run(p);
    ASSERT(p->tok == TK_DEC);

    p->s = "<";
    parser_run(p);
    ASSERT(p->tok == TK_LT);

    p->s = "<=";
    parser_run(p);
    ASSERT(p->tok == TK_LE);

    p->s = "<<";
    parser_run(p);
    ASSERT(p->tok == TK_SHL);

    p->s = "<<<";
    parser_run(p);
    ASSERT(p->tok == TK_ROL);

    p->s = ">";
    parser_run(p);
    ASSERT(p->tok == TK_GT);

    p->s = ">=";
    parser_run(p);
    ASSERT(p->tok == TK_GE);

    p->s = ">>";
    parser_run(p);
    ASSERT(p->tok == TK_SHR);

    p->s = ">>>";
    parser_run(p);
    ASSERT(p->tok == TK_ROR);

    p->s = "&";
    parser_run(p);
    ASSERT(p->tok == TK_AND);

    p->s = "&&";
    parser_run(p);
    ASSERT(p->tok == TK_LAND);

    p->s = "|";
    parser_run(p);
    ASSERT(p->tok == TK_OR);

    p->s = "||";
    parser_run(p);
    ASSERT(p->tok == TK_LOR);

    p->s = "*";
    parser_run(p);
    ASSERT(p->tok == TK_MUL);

    p->s = "/";
    parser_run(p);
    ASSERT(p->tok == TK_DIV);

    p->s = "%";
    parser_run(p);
    ASSERT(p->tok == TK_MOD);

    parser_delete(&p);
    ASSERT(p == NULL);
}
