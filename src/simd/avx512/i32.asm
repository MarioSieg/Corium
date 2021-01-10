	.text
	.def	 @feat.00;
	.scl	3;
	.type	0;
	.endef
	.globl	@feat.00
.set @feat.00, 0
	.file	"i32.c"
	.def	 main;
	.scl	2;
	.type	32;
	.endef
	.globl	main                            # -- Begin function main
	.p2align	4, 0x90
main:                                   # @main
.seh_proc main
# %bb.0:
	pushq	%rbp
	.seh_pushreg %rbp
	subq	$240, %rsp
	.seh_stackalloc 240
	leaq	128(%rsp), %rbp
	.seh_setframe %rbp, 128
	.seh_endprologue
	andq	$-32, %rsp
	vxorps	%xmm0, %xmm0, %xmm0
	vmovaps	%ymm0, 128(%rsp)
	vmovaps	%ymm0, 96(%rsp)
	vmovaps	%ymm0, 160(%rsp)
	vmovaps	%ymm0, 192(%rsp)
	movl	%ecx, 160(%rsp)
	movl	%ecx, 96(%rsp)
	vmovdqu64	160(%rsp), %zmm0
	vpaddd	96(%rsp), %zmm0, %zmm0
	vmovdqu64	%zmm0, 96(%rsp)
	leaq	96(%rsp), %rax
	movq	%rax, 88(%rsp)
	#APP
	#NO_APP
	leaq	160(%rsp), %rcx
	movq	%rcx, 80(%rsp)
	#APP
	#NO_APP
	vmovdqu64	96(%rsp), %zmm0
	vmovdqu64	160(%rsp), %zmm1
	vpsubd	%zmm1, %zmm0, %zmm0
	vpmulld	%zmm1, %zmm0, %zmm0
	vmovdqu64	%zmm0, 96(%rsp)
	movq	%rax, 72(%rsp)
	#APP
	#NO_APP
	movq	%rcx, 64(%rsp)
	#APP
	#NO_APP
	vmovups	160(%rsp), %zmm0
	vandps	96(%rsp), %zmm0, %zmm0
	vmovups	%zmm0, 96(%rsp)
	movq	%rax, 56(%rsp)
	#APP
	#NO_APP
	movq	%rcx, 48(%rsp)
	#APP
	#NO_APP
	vmovups	160(%rsp), %zmm0
	vorps	96(%rsp), %zmm0, %zmm0
	vmovups	%zmm0, 96(%rsp)
	movq	%rax, 40(%rsp)
	#APP
	#NO_APP
	movq	%rcx, 32(%rsp)
	#APP
	#NO_APP
	vmovups	160(%rsp), %zmm0
	vxorps	96(%rsp), %zmm0, %zmm0
	vmovups	%zmm0, 96(%rsp)
	movq	%rax, 24(%rsp)
	#APP
	#NO_APP
	movq	%rcx, 16(%rsp)
	#APP
	#NO_APP
	movl	96(%rsp), %eax
	leaq	112(%rbp), %rsp
	popq	%rbp
	vzeroupper
	retq
	.seh_handlerdata
	.text
	.seh_endproc
                                        # -- End function
	.addrsig
