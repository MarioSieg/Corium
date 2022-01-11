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

#include "nominax.h"

allocproc_t allocator = &co_def_malloc;
reallocproc_t reallocator = &co_def_realloc;
deallocproc_t deallocator = &co_def_free;

MALLOC_LIKE void *co_def_malloc(size_t size) {
    void* restrict mem = malloc(size);
    ASSERT(mem != NULL);
    return mem;
}

void *co_def_realloc(void *block, size_t size) {
    void* mem = realloc(block, size);
    ASSERT(mem != NULL);
    return mem;
}

void co_def_free(void *size) {
    if (size) free(size);
}

char *load_bin_file(const char *name) {
    FILE *f;
    FOPEN(f, name, "r");
    if (UNLIKELY(!f)) return NULL;
    fseek(f, 0, SEEK_END);
    long l = ftell(f);
    fseek(f, 0, SEEK_SET);
    char *restrict b = co_malloc(l * sizeof(char));
    fread(b, 1, l, f);
    fclose(f);
    return b;
}

char *load_txt_file(const char *name) {
    FILE *f;
    FOPEN(f, name, "r");
    if (UNLIKELY(!f)) return NULL;
    fseek(f, 0, SEEK_END);
    long l = ftell(f);
    fseek(f, 0, SEEK_SET);
    char *restrict b = co_malloc((l + 2) * sizeof(char));
    fread(b, 1, l, f);
    b[l] = '\n';
    b[l + 1] = '\0';
    for (char *i = b; *i; ++i)
        if (*i > 127) *i = '_';
    fclose(f);
    return b;
}

const char *OP_MNEMONICS[OP_COUNT] = {
    "int", "syscall", "intrin", "call",
    "ret", "pmov", "sto", "push", "pop",
    "dpop", "mop", "dup","ddup", "swap", "nop",
    "jmp", "jmpr", "jzcmpi", "jnzcmpi",
    "jzcmpf", "jnzcmpf" "jocmpi",
    "jocmpf", "jnocmpi", "jnocmpf", "jecmpi",
    "jecmpf", "jnecmpi", "jnecmpf", "jacmpi",
    "jacmpf", "jlcmpi", "jlcmpf", "jaecmpi",
    "jaecmpf", "jlecmpi", "jlecmpf", "pushz",
    "ipusho", "fpusho", "iinc", "idec", "iadd",
    "isub", "imul", "idiv", "imod", "iand",
    "ior", "ixor", "isal", "isar",
    "irol", "iror", "ineg", "fadd", "fsub",
    "fmul", "fdiv", "fmod", "fneg", "finc",
    "fdec", "cvti2f", "cvtf2i", "cvti2c",
    "cvti2b", "gcnew", "derefw", "derefr", "throw"
};

const int8_t OP_STACK_OFFSETS[OP_COUNT] = {
    0, 0x7F, 0x7F, 1,       /* int, syscall, intrin, call */
    -1, 1, 0, 1, -1,        /* ret, pmov, sto, push, pop */
    -2, 0x7F, 1, 2, 0, 0,   /* dpop, mop, dup, ddup, swap, nop */
    0, 0, -1, -1,           /* jmp, jmpr, jzcmpi, jnzcmpi */
    -1, -1, -1,             /* jzcmpf, jnzcmpf, jocmpi */
    -1, -1, -1, -2,         /* jocmpf, jnocmpi, jnocmpf, jacmpi */
    -2, -2, -2, -2,         /* jecmpf, jnecmpi, jnecmp, jacmpi */
    -2, -2, -2, -2          /* jacmpf, jlcmpi, jlcmpf, jaecmpi */
    -2, -2, -2, 1,          /* jaecmpf, jlecmpi, jlecmpf, pushz */
    1, 1, 0, 0, -1,         /* ipusho, fpsuho, iinc, idec, iadd */
    -1, -1, -1, -1, -1,     /* isub, imul, idiv, imod, iand */
    -1, -1,  -1, -1,        /* ior, ixor, isal, isar */
    -1, -1, 0, -1, -1,      /* irol, iror, ineg, fadd, fsub */
    -1, -1, -1, 0, 0,       /* fmul, fdiv, fmod, fneg, finc */
    0, 0, 0, 0,             /* fdec, cvti2f, cvtf2i, cvti2c */
    0, 1, -1, 1, 1          /* cvti2b, gcnew, derefw, derefr, throw */
};

const uint8_t OP_IMM_ARGS[OP_COUNT] = {
    1, 1, 1, 1,         /* int, syscall, intrin, call */
    0, 1, 2, 1, 0,      /* ret, pmov, sto, push, pop */
    0, 1, 0, 0, 0, 0,   /* dpop, mop, dup, ddup, swap, nop */
    1, 1, 0, 0,         /* jmp, jmpr, jzcmpi, jnzcmpi */
    0, 0, 0,            /* jzcmpf, jnzcmpf, jocmpi */
    0, 0, 0, 0,         /* jocmpf, jnocmpi, jnocmpf, jacmpi */
    0, 0, 0, 0,         /* jecmpf, jnecmpi, jnecmp, jacmpi */
    0, 0, 0, 0,         /* jacmpf, jlcmpi, jlcmpf, jaecmpi */
    0, 0, 0, 0,         /* jaecmpf, jlecmpi, jlecmpf, pushz */
    0, 0, 0, 0, 0,      /* ipusho, fpsuho, iinc, idec, iadd */
    0, 0, 0, 0,         /* isub, imul, idiv, imod, iand */
    0, 0, 0, 0, 0,      /* ior, ixor, isal, isar */
    0, 0, 0, 0, 0,      /* irol, iror, ineg, fadd, fsub */
    0, 0, 0, 0,         /* fmul, fdiv, fmod, fneg, finc */
    0, 1, 1, 1, 1       /* fdec, cvti2f, cvtf2i, cvti2c */
};
