#pragma once

#include "platform.hpp"

/*
 * Use architecture specific optimizations such as assembly or intrinsics?
 */
#define NOMINAX_USE_ARCH_OPT true

/*
 * If true, explicit checks are inserted - if false stack overflow results in a segmentation fault handled through signals
 * BTW jump instruction which push cannot trigger a stack overflow because they recycle stack space.
 */
#define NOMINAX_STACK_OVERFLOW_CHECKS true

/*
 * Insert assembly comments with the instruction name into the assembler code, to find the section in the compiled output.
 * Should be disabled when building for release.
 */
#define NOMINAX_REACTOR_ASM_MARKERS true