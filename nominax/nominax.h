/**
 * @file nominax.h
 * @author Mario "pinsrq" Sieg (mario.sieg@gmx.net)
 * @brief 
 * @version 0.1
 * @date 2022-01-10
 * 
 * @copyright Copyright (c) Mario "pinsrq" Sieg 2022
 * 
 */

#ifndef _NOMINAX_H_
#define _NOMINAX_H_

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
#   error "nominax.h: Unknown compiler!"
#endif

#if defined(__amd64__) || defined(__amd64) || defined(__x86_64__) || defined(__x86_64) || defined(_M_X64) || defined(_M_AMD64)
#   undef ARCH_X86_64
#   define ARCH_X86_64 true
#elif defined(__aarch64__)
#   undef ARCH_AARCH64
#   define ARCH_AARCH64 true
#else
#   error "nominax.h: Unknown architecture!"
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
#   define FOPEN(out, name, mode) ((out) = fopen(name, mode))
#elif COM_MSVC
#   define NORET	__declspec(noreturn)
#   define ALIGN(n)	__declspec(align(n))
#   define AINLINE __forceinline
#   define NOINLINE __declspec(noinline)
#   define HOT
#   define COLD
#   define PACK(decl) __pragma(pack(push, 1)) decl __pragma(pack(pop))
#   define LIKELY(x) (x)
#   define UNLIKELY(x) (x)
#   define MALLOC_LIKE
#   define FOPEN(out, name, mode) fopen_s(&(out), name, mode)
#   define __PRETTY_FUNCTION__ __FUNCSIG__
#else
#   error "Missing macro detection for your compiler"
#endif

#define ASSERT(expr) if (UNLIKELY(!(expr))) {                                                       \
    printf("Assertion failed: %s:%d in %s", __FILE__, __LINE__, __PRETTY_FUNCTION__);               \
    exit(-1);                                                                                       \
}

typedef void *(*allocproc_t)(size_t size);
typedef void *(*reallocproc_t)(void* block, size_t size);
typedef void (*deallocproc_t)(void* block);

extern allocproc_t allocator;
extern reallocproc_t reallocator;
extern deallocproc_t deallocator;

extern MALLOC_LIKE void *co_def_malloc(size_t size);
extern void *co_def_realloc(void *block, size_t size);
extern void co_def_free(void *size);

AINLINE MALLOC_LIKE static void *co_malloc(size_t size) {
    return (*allocator)(size);
}

AINLINE static void *co_realloc(void *block, size_t size) {
    return (*reallocator)(block, size);
}

AINLINE static void co_free(void *block) {
    (*deallocator)(block);
}

extern char *load_bin_file(const char *name);
extern char *load_txt_file(const char *name);

AINLINE static void free_file(char *file) {
    co_free(file);
}

enum {
    OP_INT = 0, OP_SYSCALL, OP_INTRIN, OP_CALL,
    OP_RET, OP_PMOV, OP_STO, OP_PUSH, OP_POP,
    OP_DPOP, OP_MOP, OP_DUP, OP_DDUP, OP_SWAP, OP_NOP,
    OP_JMP, OP_JMPR, OP_JZCMPI, OP_JNZCMPI,
    OP_JZCMPF, OP_JNZCMPF, OP_JOCMPI,
    OP_JOCMPF, OP_JNOCMPI, OP_JNOCMPF, OP_JECMPI,
    OP_JECMPF, OP_JNECMPI, OP_JNECMPF, OP_JACMPI,
    OP_JACMPF, OP_JLCMPI, OP_JLCMPF, OP_JAECMPI,
    OP_JAECMPF, OP_JLECMPI, OP_JLECMPF, OP_PUSHZ,
    OP_IPUSHO, OP_FPUSHO, OP_IINC, OP_IDEC, OP_IADD,
    OP_ISUB, OP_IMUL, OP_IDIV, OP_IMOD, OP_IAND,
    OP_IOR, OP_IXOR, OP_ISAL, OP_ISAR,
    OP_IROL, OP_IROR, OP_INEG, OP_FADD, OP_FSUB,
    OP_FMUL, OP_FDIV, OP_FMOD, OP_FNEG, OP_FINC,
    OP_FDEC, OP_CVTI2F, OP_CVTF2I, OP_CVTI2C,
    OP_CVTI2B, OP_GCNEW, OP_DEREFW, OP_DEREFR, OP_THROW,
    OP_COUNT
};

extern const char *OP_MNEMONICS[OP_COUNT];
extern const int8_t OP_STACK_OFFSETS[OP_COUNT];
extern const uint8_t OP_IMM_ARGS[OP_COUNT];

#ifdef __cplusplus
}
#endif

#endif

