/**
 * @file corium.h
 * @author Mario "pinsrq" Sieg (mario.sieg@gmx.net)
 * @brief 
 * @version 0.1
 * @date 2022-01-01
 * 
 * @copyright Copyright (c) Mario "pinsrq" Sieg 2022
 * 
 */

#ifndef _CORIUM_H_
#define _CORIUM_H_

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include <nominax.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef int32_t co_int;
typedef float co_float;
typedef uint8_t co_char, co_bool;

enum {
    TK_IDENT, TK_ASSIGN,
    TK_INT_LIT, TK_FLOAT_LIT, TK_CHAR_LIT, TK_STR_LIT,
    TK_ADD, TK_SUB, TK_MUL, TK_DIV, TK_MOD, TK_INC, TK_DEC,
    TK_LOR, TK_LAND, TK_EQ, TK_NE, TK_LT, TK_GT, TK_LE, TK_GE, TK_NOT,
    TK_AND, TK_OR, TK_XOR, TK_SHL, TK_SHR, TK_ROL, TK_ROR
};

enum {
    SY_COMMENT = '#',
    SY_ASSIGN = '=',
    SY_LT = '<',
    SY_GT = '>',
    SY_ADD = '+',
    SY_SUB = '-',
    SY_MUL = '*',
    SY_DIV = '/',
    SY_MOD = '%',
    SY_AND = '&',
    SY_OR = '|',
    SY_XOR = '^',
    SY_NOT = '!'
};

typedef struct {
    const char *s;
    const char *iB, *iE;
    char p;
    uint8_t tok;
    uint16_t flags;
    union imm_t {
        co_int imm;
        co_float fmm;
    } val;
} parser_t ;

extern parser_t *parser_new();
extern void parser_run(parser_t *p);
extern void parser_delete(parser_t *p);

static inline parser_t *parser_new() {
    parser_t *restrict r = co_malloc(sizeof(parser_t));
    memset(r, 0, sizeof(*r));
    return r;
}

static inline void parser_delete(parser_t *p) {
    co_free(p);
}

#ifdef __cplusplus
}
#endif

#endif
