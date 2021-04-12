#pragma once

#define NOMINAX_USE_ARCH_OPT true			// Use architecture specific optimizations such as assembly or intrinsics?
#define NOMINAX_NO_ARCH_INTRIN false
#define NOMINAX_NO_SSE false

/*
 * If true, explicit checks are inserted - if false stack overflow results in a segmentation fault handled through signals
 * BTW jump instruction which push cannot trigger a stack overflow because they recycle stack space.
 */
#define NOMINAX_STACK_OVERFLOW_CHECKS true
#define NOMINAX_REACTOR_ASM_MARKERS true