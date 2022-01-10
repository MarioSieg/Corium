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
