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

#ifdef __cplusplus
extern "C" {
#endif

#define COM_GCC false
#define COM_CLANG false
#define COM_MSVC false
#define ARCH_X86_64 false
#define ARCH_AARCH64 false

#ifdef __GNUC__
#   undef COM_GCC
#   define COM_GCC true
#elif defined(__clang__)
#   undef COM_CLANG
#   define COM_CLANG true
#elif defined(_MSC_VER)
#   undef COM_MSVC
#   define COM_MSVC true
#else
#   error "def.h: Unknown compiler!"
#endif

#if defined(__amd64__) || defined(__amd64) || defined(__x86_64__) || defined(__x86_64) || defined(_M_X64) || defined(_M_AMD64)
#   undef ARCH_X86_64
#   define ARCH_X86_64 true
#elif defined(__aarch64__)
#   undef ARCH_AARCH64
#   define ARCH_AARCH64 true
#else
#   error "def.h: Unknown architecture!"
#endif

#ifdef NDEBUG
#   define DEBUG false
#else
#   define DEBUG true
#endif

#if COM_GCC || COM_CLANG
#   define NORET __attribute__((noreturn))
#   define ALIGN(n)	__attribute__((aligned(n)))
#   define AINLINE inline __attribute__((always_inline))
#   define NOINLINE	__attribute__((noinline))
#   define HOT __attribute__((hot))
#   define COLD __attribute__((cold))
#   define PACK(decl) decl __attribute__((__packed__))
#   define LIKELY(x) __builtin_expect(!!(x), 1)
#   define UNLIKELY(x) __builtin_expect(!!(x), 0)
#   define MALLOC_LIKE __attribute__((malloc))
#elif COM_MSVC
#   define NORET	__declspec(noreturn)
#   define ALIGN(n)	__declspec(align(n))
#   define AINLINE __forceinline
#   define NOINLINE __declspec(noinline)
#   define HOT
#   define COLD
#   define PACK(decl) __pragma(pack(push, 1)) decl __pragma(pack(pop))
#   define LIKELY(x)
#   define UNLIKELY(x)
#   define MALLOC_LIKE
#   define __PRETTY_FUNCTION__ __FUNCSIG__
#else
#   error "Missing macro detection for your compiler"
#endif

#define ASSERT(expr) if (UNLIKELY(!(expr))) {                                                       \
    printf("Assertion failed: %s:%d in %s", __FILE__, __LINE__, __PRETTY_FUNCTION__); exit(-1);     \
}

typedef void *(*allocator_t)(size_t s);
typedef void *(*reallocator_t)(void* b, size_t s);
typedef void (*deallocator_t)(void* b);

extern allocator_t allocator;
extern reallocator_t reallocator;
extern deallocator_t deallocator;

extern MALLOC_LIKE void *co_def_malloc(size_t s);
extern void *co_def_realloc(void *b, size_t s);
extern void co_def_free(void *b);

AINLINE MALLOC_LIKE static void *co_malloc(const size_t s) {
    return (*allocator)(s);
}

AINLINE static void *co_realloc(void *const b, const size_t s) {
    return (*reallocator)(b, s);
}

AINLINE static void co_free(void *const b) {
    (*deallocator)(b);
}

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

struct parser_t {
    const char *s;
    const char *iB, *iE;
    char p;
    uint8_t tok;
    union {
        co_int imm;
        co_float fmm;
    };
};

extern void parser_new(struct parser_t **p);
extern void parser_run(register struct parser_t *p);
extern void parser_delete(struct parser_t **p);

#ifdef __cplusplus
}
#endif

#endif
