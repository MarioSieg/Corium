	.text
	.def	 @feat.00;
	.scl	3;
	.type	0;
	.endef
	.globl	@feat.00
.set @feat.00, 0
	.file	"reactor.cpp"
	.def	 "?validate@reactor_input@nominax@@QEBA?AW4reactor_validation_result@2@XZ";
	.scl	2;
	.type	32;
	.endef
	.globl	"?validate@reactor_input@nominax@@QEBA?AW4reactor_validation_result@2@XZ" # -- Begin function ?validate@reactor_input@nominax@@QEBA?AW4reactor_validation_result@2@XZ
	.p2align	4, 0x90
"?validate@reactor_input@nominax@@QEBA?AW4reactor_validation_result@2@XZ": # @"?validate@reactor_input@nominax@@QEBA?AW4reactor_validation_result@2@XZ"
# %bb.0:
	movl	$1, %eax
	cmpq	$0, (%rcx)
	je	.LBB0_14
# %bb.1:
	movq	8(%rcx), %rdx
	testq	%rdx, %rdx
	je	.LBB0_14
# %bb.2:
	movq	24(%rcx), %r8
	testq	%r8, %r8
	je	.LBB0_14
# %bb.3:
	cmpq	$0, 40(%rcx)
	je	.LBB0_14
# %bb.4:
	movq	48(%rcx), %r9
	testq	%r9, %r9
	je	.LBB0_14
# %bb.5:
	movl	$2, %eax
	cmpq	$0, 16(%rcx)
	je	.LBB0_14
# %bb.6:
	movq	32(%rcx), %r10
	testq	%r10, %r10
	je	.LBB0_14
# %bb.7:
	cmpq	$0, 56(%rcx)
	je	.LBB0_14
# %bb.8:
	movl	$3, %eax
	cmpq	$11, (%rdx)
	jne	.LBB0_14
# %bb.9:
	movl	$4, %eax
	cmpq	$-1, (%r9)
	jne	.LBB0_14
# %bb.10:
	leaq	(%r8,%r10,8), %rcx
	movl	$5, %eax
.LBB0_11:                               # =>This Inner Loop Header: Depth=1
	cmpq	%rcx, %r8
	jae	.LBB0_12
# %bb.13:                               #   in Loop: Header=BB0_11 Depth=1
	cmpq	$0, (%r8)
	leaq	8(%r8), %r8
	jne	.LBB0_11
.LBB0_14:
	retq
.LBB0_12:
	xorl	%eax, %eax
	retq
                                        # -- End function
	.def	 "?execute_reactor@nominax@@YA?AUreactor_output@1@AEBUreactor_input@1@@Z";
	.scl	2;
	.type	32;
	.endef
	.globl	__real@3ff0000000000000         # -- Begin function ?execute_reactor@nominax@@YA?AUreactor_output@1@AEBUreactor_input@1@@Z
	.section	.rdata,"dr",discard,__real@3ff0000000000000
	.p2align	3
__real@3ff0000000000000:
	.quad	0x3ff0000000000000              # double 1
	.globl	__real@bff0000000000000
	.section	.rdata,"dr",discard,__real@bff0000000000000
	.p2align	3
__real@bff0000000000000:
	.quad	0xbff0000000000000              # double -1
	.globl	__xmm@80000000000000008000000000000000
	.section	.rdata,"dr",discard,__xmm@80000000000000008000000000000000
	.p2align	4
__xmm@80000000000000008000000000000000:
	.quad	0x8000000000000000              # double -0
	.quad	0x8000000000000000              # double -0
	.text
	.globl	"?execute_reactor@nominax@@YA?AUreactor_output@1@AEBUreactor_input@1@@Z"
	.p2align	4, 0x90
"?execute_reactor@nominax@@YA?AUreactor_output@1@AEBUreactor_input@1@@Z": # @"?execute_reactor@nominax@@YA?AUreactor_output@1@AEBUreactor_input@1@@Z"
.Lfunc_begin0:
.seh_proc "?execute_reactor@nominax@@YA?AUreactor_output@1@AEBUreactor_input@1@@Z"
	.seh_handler __CxxFrameHandler3, @unwind, @except
# %bb.0:
	pushq	%rbp
	.seh_pushreg %rbp
	pushq	%r15
	.seh_pushreg %r15
	pushq	%r14
	.seh_pushreg %r14
	pushq	%r13
	.seh_pushreg %r13
	pushq	%r12
	.seh_pushreg %r12
	pushq	%rsi
	.seh_pushreg %rsi
	pushq	%rdi
	.seh_pushreg %rdi
	pushq	%rbx
	.seh_pushreg %rbx
	subq	$88, %rsp
	.seh_stackalloc 88
	leaq	80(%rsp), %rbp
	.seh_setframe %rbp, 80
	.seh_endprologue
	movq	$-2, (%rbp)
	movq	%rdx, %rdi
	movq	%rcx, %rsi
	movl	$1, %eax
	cmpq	$0, (%rdx)
	je	.LBB1_13
# %bb.1:
	movq	8(%rdi), %rdx
	testq	%rdx, %rdx
	je	.LBB1_13
# %bb.2:
	movq	24(%rdi), %rcx
	testq	%rcx, %rcx
	je	.LBB1_13
# %bb.3:
	cmpq	$0, 40(%rdi)
	je	.LBB1_13
# %bb.4:
	movq	48(%rdi), %rbx
	testq	%rbx, %rbx
	je	.LBB1_13
# %bb.5:
	movl	$2, %eax
	cmpq	$0, 16(%rdi)
	je	.LBB1_13
# %bb.6:
	movq	32(%rdi), %r8
	testq	%r8, %r8
	je	.LBB1_13
# %bb.7:
	cmpq	$0, 56(%rdi)
	je	.LBB1_13
# %bb.8:
	movl	$3, %eax
	cmpq	$11, (%rdx)
	jne	.LBB1_13
# %bb.9:
	movl	$4, %eax
	cmpq	$-1, (%rbx)
	jne	.LBB1_13
# %bb.10:
	leaq	(%rcx,%r8,8), %rdx
	movl	$5, %eax
.LBB1_11:                               # =>This Inner Loop Header: Depth=1
	cmpq	%rdx, %rcx
	jae	.LBB1_14
# %bb.12:                               #   in Loop: Header=BB1_11 Depth=1
	cmpq	$0, (%rcx)
	leaq	8(%rcx), %rcx
	jne	.LBB1_11
.LBB1_13:
	movl	%eax, (%rsi)
	movupd	(%rdi), %xmm0
	movups	16(%rdi), %xmm1
	movups	32(%rdi), %xmm2
	movups	48(%rdi), %xmm3
	movupd	%xmm0, 8(%rsi)
	movups	%xmm1, 24(%rsi)
	movups	%xmm2, 40(%rsi)
	movups	%xmm3, 56(%rsi)
	movq	64(%rdi), %rax
	movq	%rax, 72(%rsi)
	movb	$0, 80(%rsi)
	xorpd	%xmm0, %xmm0
	movupd	%xmm0, 88(%rsi)
	movupd	%xmm0, 100(%rsi)
	movupd	%xmm0, 120(%rsi)
.LBB1_110:
	movq	%rsi, %rax
	addq	$88, %rsp
	popq	%rbx
	popq	%rdi
	popq	%rsi
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.LBB1_14:
.Ltmp0:
	callq	_Query_perf_frequency
.Ltmp1:
# %bb.15:
	movq	%rax, %rbx
.Ltmp2:
	callq	_Query_perf_counter
.Ltmp3:
# %bb.16:
	movq	%rax, %rcx
	orq	%rbx, %rcx
	shrq	$32, %rcx
	je	.LBB1_17
# %bb.18:
	cqto
	idivq	%rbx
	jmp	.LBB1_19
.LBB1_17:
                                        # kill: def $eax killed $eax killed $rax
	xorl	%edx, %edx
	divl	%ebx
                                        # kill: def $edx killed $edx def $rdx
                                        # kill: def $eax killed $eax def $rax
.LBB1_19:
	imulq	$1000000000, %rax, %rcx         # imm = 0x3B9ACA00
	imulq	$1000000000, %rdx, %rax         # imm = 0x3B9ACA00
	movq	%rbx, %rdx
	orq	%rax, %rdx
	shrq	$32, %rdx
	je	.LBB1_20
# %bb.21:
	cqto
	idivq	%rbx
	addq	%rcx, %rax
	movq	%rax, -16(%rbp)                 # 8-byte Spill
	#APP
	##reactor begin
	#NO_APP
	movq	64(%rdi), %rax
	movq	%rax, -40(%rbp)                 # 8-byte Spill
	movq	(%rdi), %rax
	movq	%rax, -32(%rbp)                 # 8-byte Spill
	movq	8(%rdi), %rax
	movq	24(%rdi), %rcx
	movq	%rcx, -8(%rbp)                  # 8-byte Spill
	movq	40(%rdi), %rcx
	movq	%rcx, -24(%rbp)                 # 8-byte Spill
	movq	48(%rdi), %r13
	#APP
	#reactor exec
	#NO_APP
	leaq	8(%rax), %r15
	movq	%rax, %r12
	leaq	-8(%rax), %r14
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
.LBB1_20:
                                        # kill: def $eax killed $eax killed $rax
	xorl	%edx, %edx
	divl	%ebx
                                        # kill: def $eax killed $eax def $rax
	addq	%rcx, %rax
	movq	%rax, -16(%rbp)                 # 8-byte Spill
	#APP
	##reactor begin
	#NO_APP
	movq	64(%rdi), %rax
	movq	%rax, -40(%rbp)                 # 8-byte Spill
	movq	(%rdi), %rax
	movq	%rax, -32(%rbp)                 # 8-byte Spill
	movq	8(%rdi), %rax
	movq	24(%rdi), %rcx
	movq	%rcx, -8(%rbp)                  # 8-byte Spill
	movq	40(%rdi), %rcx
	movq	%rcx, -24(%rbp)                 # 8-byte Spill
	movq	48(%rdi), %r13
	#APP
	#reactor exec
	#NO_APP
	leaq	8(%rax), %r15
	movq	%rax, %r12
	leaq	-8(%rax), %r14
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp8:                                 # Block address taken
.LBB1_22:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__int__
	#NO_APP
	movq	8(%r15), %rbx
	testl	%ebx, %ebx
	js	.LBB1_101
# %bb.23:                               #   in Loop: Header=BB1_22 Depth=1
	movl	%ebx, %ecx
	movq	-32(%rbp), %rdx                 # 8-byte Reload
	movq	-40(%rbp), %r8                  # 8-byte Reload
	callq	*-24(%rbp)                      # 8-byte Folded Reload
	testb	%al, %al
	je	.LBB1_101
# %bb.24:                               #   in Loop: Header=BB1_22 Depth=1
	addq	$16, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
.LBB1_101:
	#APP
	#reactor end
	#NO_APP
.Ltmp4:
	callq	_Query_perf_frequency
.Ltmp5:
# %bb.102:
	movq	%rax, %r14
.Ltmp6:
	callq	_Query_perf_counter
.Ltmp7:
# %bb.103:
	movq	%rax, %rcx
	orq	%r14, %rcx
	shrq	$32, %rcx
	je	.LBB1_104
# %bb.105:
	cqto
	idivq	%r14
	jmp	.LBB1_106
.LBB1_104:
                                        # kill: def $eax killed $eax killed $rax
	xorl	%edx, %edx
	divl	%r14d
                                        # kill: def $edx killed $edx def $rdx
                                        # kill: def $eax killed $eax def $rax
.LBB1_106:
	addq	$8, %r15
	imulq	$1000000000, %rax, %rcx         # imm = 0x3B9ACA00
	imulq	$1000000000, %rdx, %rax         # imm = 0x3B9ACA00
	movq	%r14, %rdx
	orq	%rax, %rdx
	shrq	$32, %rdx
	je	.LBB1_107
# %bb.108:
	cqto
	idivq	%r14
	jmp	.LBB1_109
.LBB1_107:
                                        # kill: def $eax killed $eax killed $rax
	xorl	%edx, %edx
	divl	%r14d
                                        # kill: def $eax killed $eax def $rax
.LBB1_109:
	addq	%rcx, %rax
	movq	%rax, %rcx
	movq	-16(%rbp), %r8                  # 8-byte Reload
	subq	%r8, %rcx
	subq	8(%rdi), %r15
	sarq	$3, %r15
	subq	48(%rdi), %r13
	sarq	$3, %r13
	#APP
	#reactor ret
	#NO_APP
	movl	$0, (%rsi)
	movups	(%rdi), %xmm0
	movups	16(%rdi), %xmm1
	movups	32(%rdi), %xmm2
	movups	48(%rdi), %xmm3
	movups	%xmm0, 8(%rsi)
	movups	%xmm1, 24(%rsi)
	movups	%xmm2, 40(%rsi)
	movups	%xmm3, 56(%rsi)
	movq	64(%rdi), %rdx
	movq	%rdx, 72(%rsi)
	testl	%ebx, %ebx
	sete	80(%rsi)
	movq	%r8, 88(%rsi)
	movq	%rax, 96(%rsi)
	movq	%rcx, 104(%rsi)
	movl	%ebx, 112(%rsi)
	movq	%r15, 120(%rsi)
	movq	%r13, 128(%rsi)
	jmp	.LBB1_110
	.p2align	4, 0x90
.Ltmp9:                                 # Block address taken
.LBB1_25:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__intrin__
	#NO_APP
	movq	8(%r15), %rax
	testq	%rax, %rax
	jns	.LBB1_26
# %bb.27:                               #   in Loop: Header=BB1_25 Depth=1
	addq	$16, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
.LBB1_26:                               #   in Loop: Header=BB1_25 Depth=1
	movq	-8(%rbp), %rcx                  # 8-byte Reload
	callq	*(%rcx,%rax,8)
	addq	$16, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp10:                                # Block address taken
.LBB1_28:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__call__
	#NO_APP
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp11:                                # Block address taken
.LBB1_29:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__ret__
	#NO_APP
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp12:                                # Block address taken
.LBB1_30:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__mov__
	#NO_APP
	movq	8(%r15), %rax
	movq	16(%r15), %rcx
	movq	(%r13,%rcx,8), %rcx
	movq	%rcx, (%r13,%rax,8)
	addq	$24, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp13:                                # Block address taken
.LBB1_31:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__sto__
	#NO_APP
	movq	8(%r15), %rax
	movq	16(%r15), %rcx
	movq	%rcx, (%r13,%rax,8)
	addq	$24, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp14:                                # Block address taken
.LBB1_32:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__push__
	#NO_APP
	movq	8(%r15), %rax
	movq	%rax, 8(%r13)
	addq	$8, %r13
	addq	$16, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp15:                                # Block address taken
.LBB1_33:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__pop__
	#NO_APP
	addq	$-8, %r13
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp16:                                # Block address taken
.LBB1_34:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__pop2__
	#NO_APP
	addq	$-16, %r13
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp17:                                # Block address taken
.LBB1_35:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__dupl__
	#NO_APP
	movq	(%r13), %rax
	movq	%rax, 8(%r13)
	addq	$8, %r13
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp18:                                # Block address taken
.LBB1_36:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__dupl2__
	#NO_APP
	movq	(%r13), %rax
	movq	%rax, 8(%r13)
	movq	%rax, 16(%r13)
	addq	$16, %r13
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp19:                                # Block address taken
.LBB1_37:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__nop__
	#NO_APP
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp20:                                # Block address taken
.LBB1_38:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__ipushz__
	#NO_APP
	movq	$0, 8(%r13)
	addq	$8, %r13
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp21:                                # Block address taken
.LBB1_39:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__ipusho__
	#NO_APP
	movq	$1, 8(%r13)
	addq	$8, %r13
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp22:                                # Block address taken
.LBB1_40:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__fpusho__
	#NO_APP
	movabsq	$4607182418800017408, %rax      # imm = 0x3FF0000000000000
	movq	%rax, 8(%r13)
	addq	$8, %r13
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp23:                                # Block address taken
.LBB1_41:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__iinc__
	#NO_APP
	addq	$1, (%r13)
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp24:                                # Block address taken
.LBB1_42:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__idec__
	#NO_APP
	addq	$-1, (%r13)
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp25:                                # Block address taken
.LBB1_43:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__iadd__
	#NO_APP
	movq	(%r13), %rax
	addq	%rax, -8(%r13)
	addq	$-8, %r13
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp26:                                # Block address taken
.LBB1_44:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__isub__
	#NO_APP
	movq	(%r13), %rax
	subq	%rax, -8(%r13)
	addq	$-8, %r13
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp27:                                # Block address taken
.LBB1_45:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__imul__
	#NO_APP
	movq	-8(%r13), %rax
	imulq	(%r13), %rax
	movq	%rax, -8(%r13)
	addq	$-8, %r13
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp28:                                # Block address taken
.LBB1_46:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__idiv__
	#NO_APP
	leaq	-8(%r13), %rcx
	movq	-8(%r13), %rax
	movq	(%r13), %rbx
	movq	%rax, %rdx
	orq	%rbx, %rdx
	shrq	$32, %rdx
	je	.LBB1_47
# %bb.48:                               #   in Loop: Header=BB1_46 Depth=1
	cqto
	idivq	%rbx
	movq	%rax, (%rcx)
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rdx
	movq	%rcx, %r13
	jmpq	*(%rdx,%rax,8)
	.p2align	4, 0x90
.LBB1_47:                               #   in Loop: Header=BB1_46 Depth=1
                                        # kill: def $eax killed $eax killed $rax
	xorl	%edx, %edx
	divl	%ebx
                                        # kill: def $eax killed $eax def $rax
	movq	%rax, (%rcx)
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rdx
	movq	%rcx, %r13
	jmpq	*(%rdx,%rax,8)
	.p2align	4, 0x90
.Ltmp29:                                # Block address taken
.LBB1_49:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__imod__
	#NO_APP
	leaq	-8(%r13), %rcx
	movq	-8(%r13), %rax
	movq	(%r13), %rbx
	movq	%rax, %rdx
	orq	%rbx, %rdx
	shrq	$32, %rdx
	je	.LBB1_50
# %bb.51:                               #   in Loop: Header=BB1_49 Depth=1
	cqto
	idivq	%rbx
	movq	%rdx, (%rcx)
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rdx
	movq	%rcx, %r13
	jmpq	*(%rdx,%rax,8)
	.p2align	4, 0x90
.LBB1_50:                               #   in Loop: Header=BB1_49 Depth=1
                                        # kill: def $eax killed $eax killed $rax
	xorl	%edx, %edx
	divl	%ebx
                                        # kill: def $edx killed $edx def $rdx
	movq	%rdx, (%rcx)
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rdx
	movq	%rcx, %r13
	jmpq	*(%rdx,%rax,8)
	.p2align	4, 0x90
.Ltmp30:                                # Block address taken
.LBB1_52:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__iand__
	#NO_APP
	movq	(%r13), %rax
	andq	%rax, -8(%r13)
	addq	$-8, %r13
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp31:                                # Block address taken
.LBB1_53:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__ior__
	#NO_APP
	movq	(%r13), %rax
	orq	%rax, -8(%r13)
	addq	$-8, %r13
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp32:                                # Block address taken
.LBB1_54:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__ixor__
	#NO_APP
	movq	(%r13), %rax
	xorq	%rax, -8(%r13)
	addq	$-8, %r13
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp33:                                # Block address taken
.LBB1_55:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__icom__
	#NO_APP
	notq	(%r13)
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp34:                                # Block address taken
.LBB1_56:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__isal__
	#NO_APP
	movzbl	(%r13), %ecx
	shlq	%cl, -8(%r13)
	addq	$-8, %r13
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp35:                                # Block address taken
.LBB1_57:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__isar__
	#NO_APP
	movzbl	(%r13), %ecx
	sarq	%cl, -8(%r13)
	addq	$-8, %r13
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp36:                                # Block address taken
.LBB1_58:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__irol__
	#NO_APP
	movzbl	(%r13), %ecx
	rolq	%cl, -8(%r13)
	addq	$-8, %r13
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp37:                                # Block address taken
.LBB1_59:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__iror__
	#NO_APP
	movzbl	(%r13), %ecx
	rorq	%cl, -8(%r13)
	addq	$-8, %r13
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp38:                                # Block address taken
.LBB1_60:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__ineg__
	#NO_APP
	negq	(%r13)
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp39:                                # Block address taken
.LBB1_61:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__fadd__
	#NO_APP
	movsd	-8(%r13), %xmm0                 # xmm0 = mem[0],zero
	addsd	(%r13), %xmm0
	movsd	%xmm0, -8(%r13)
	addq	$-8, %r13
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp40:                                # Block address taken
.LBB1_62:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__fsub__
	#NO_APP
	movsd	-8(%r13), %xmm0                 # xmm0 = mem[0],zero
	subsd	(%r13), %xmm0
	movsd	%xmm0, -8(%r13)
	addq	$-8, %r13
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp41:                                # Block address taken
.LBB1_63:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__fmul__
	#NO_APP
	movsd	-8(%r13), %xmm0                 # xmm0 = mem[0],zero
	mulsd	(%r13), %xmm0
	movsd	%xmm0, -8(%r13)
	addq	$-8, %r13
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp42:                                # Block address taken
.LBB1_64:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__fdiv__
	#NO_APP
	movsd	-8(%r13), %xmm0                 # xmm0 = mem[0],zero
	divsd	(%r13), %xmm0
	movsd	%xmm0, -8(%r13)
	addq	$-8, %r13
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp43:                                # Block address taken
.LBB1_65:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__fmod__
	#NO_APP
	leaq	-8(%r13), %rbx
	movsd	-8(%r13), %xmm0                 # xmm0 = mem[0],zero
	movsd	(%r13), %xmm1                   # xmm1 = mem[0],zero
	callq	fmod
	movsd	%xmm0, -8(%r13)
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	movq	%rbx, %r13
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp44:                                # Block address taken
.LBB1_66:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__fneg__
	#NO_APP
	movsd	(%r13), %xmm0                   # xmm0 = mem[0],zero
	xorpd	__xmm@80000000000000008000000000000000(%rip), %xmm0
	movlpd	%xmm0, (%r13)
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp45:                                # Block address taken
.LBB1_67:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__finc__
	#NO_APP
	movsd	(%r13), %xmm0                   # xmm0 = mem[0],zero
	addsd	__real@3ff0000000000000(%rip), %xmm0
	movsd	%xmm0, (%r13)
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp46:                                # Block address taken
.LBB1_68:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__fdec__
	#NO_APP
	movsd	(%r13), %xmm0                   # xmm0 = mem[0],zero
	addsd	__real@bff0000000000000(%rip), %xmm0
	movsd	%xmm0, (%r13)
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp47:                                # Block address taken
.LBB1_69:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__jmp__
	#NO_APP
	movq	8(%r15), %rax
	leaq	(%r12,%rax,8), %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp48:                                # Block address taken
.LBB1_70:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__jmprel__
	#NO_APP
	movq	8(%r15), %rax
	leaq	(%r15,%rax,8), %r15
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp49:                                # Block address taken
.LBB1_71:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__jz__
	#NO_APP
	addq	$8, %r15
	cmpq	$0, (%r13)
	jne	.LBB1_73
# %bb.72:                               #   in Loop: Header=BB1_71 Depth=1
	movq	(%r15), %rax
	leaq	(%r14,%rax,8), %r15
.LBB1_73:                               #   in Loop: Header=BB1_71 Depth=1
	addq	$-8, %r13
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp50:                                # Block address taken
.LBB1_74:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__jnz__
	#NO_APP
	addq	$8, %r15
	cmpq	$0, (%r13)
	je	.LBB1_76
# %bb.75:                               #   in Loop: Header=BB1_74 Depth=1
	movq	(%r15), %rax
	leaq	(%r14,%rax,8), %r15
.LBB1_76:                               #   in Loop: Header=BB1_74 Depth=1
	addq	$-8, %r13
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp51:                                # Block address taken
.LBB1_77:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__jo_cmpi__
	#NO_APP
	addq	$8, %r15
	cmpq	$1, (%r13)
	jne	.LBB1_79
# %bb.78:                               #   in Loop: Header=BB1_77 Depth=1
	movq	(%r15), %rax
	leaq	(%r14,%rax,8), %r15
.LBB1_79:                               #   in Loop: Header=BB1_77 Depth=1
	addq	$-8, %r13
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp52:                                # Block address taken
.LBB1_80:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__jo_cmpf__
	#NO_APP
	addq	$8, %r15
	movsd	__real@3ff0000000000000(%rip), %xmm0 # xmm0 = mem[0],zero
	ucomisd	(%r13), %xmm0
	jne	.LBB1_82
# %bb.81:                               #   in Loop: Header=BB1_80 Depth=1
	movq	(%r15), %rax
	leaq	(%r14,%rax,8), %r15
.LBB1_82:                               #   in Loop: Header=BB1_80 Depth=1
	addq	$-8, %r13
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp53:                                # Block address taken
.LBB1_83:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__jno_cmpi__
	#NO_APP
	addq	$8, %r15
	cmpq	$1, (%r13)
	je	.LBB1_85
# %bb.84:                               #   in Loop: Header=BB1_83 Depth=1
	movq	(%r15), %rax
	leaq	(%r14,%rax,8), %r15
.LBB1_85:                               #   in Loop: Header=BB1_83 Depth=1
	addq	$-8, %r13
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp54:                                # Block address taken
.LBB1_86:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__jno_cmpf__
	#NO_APP
	addq	$8, %r15
	movsd	__real@3ff0000000000000(%rip), %xmm0 # xmm0 = mem[0],zero
	ucomisd	(%r13), %xmm0
	je	.LBB1_88
# %bb.87:                               #   in Loop: Header=BB1_86 Depth=1
	movq	(%r15), %rax
	leaq	(%r14,%rax,8), %r15
.LBB1_88:                               #   in Loop: Header=BB1_86 Depth=1
	addq	$-8, %r13
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp55:                                # Block address taken
.LBB1_89:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__je_cmpi__
	#NO_APP
	addq	$8, %r15
	movq	-8(%r13), %rax
	cmpq	(%r13), %rax
	jne	.LBB1_91
# %bb.90:                               #   in Loop: Header=BB1_89 Depth=1
	movq	(%r15), %rax
	leaq	(%r14,%rax,8), %r15
.LBB1_91:                               #   in Loop: Header=BB1_89 Depth=1
	addq	$-16, %r13
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp56:                                # Block address taken
.LBB1_92:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__je_cmpf__
	#NO_APP
	addq	$8, %r15
	movsd	-8(%r13), %xmm0                 # xmm0 = mem[0],zero
	ucomisd	(%r13), %xmm0
	jne	.LBB1_94
# %bb.93:                               #   in Loop: Header=BB1_92 Depth=1
	movq	(%r15), %rax
	leaq	(%r14,%rax,8), %r15
.LBB1_94:                               #   in Loop: Header=BB1_92 Depth=1
	addq	$-16, %r13
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp57:                                # Block address taken
.LBB1_95:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__jne_cmpi__
	#NO_APP
	addq	$8, %r15
	movq	-8(%r13), %rax
	cmpq	(%r13), %rax
	je	.LBB1_97
# %bb.96:                               #   in Loop: Header=BB1_95 Depth=1
	movq	(%r15), %rax
	leaq	(%r14,%rax,8), %r15
.LBB1_97:                               #   in Loop: Header=BB1_95 Depth=1
	addq	$-16, %r13
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.p2align	4, 0x90
.Ltmp58:                                # Block address taken
.LBB1_98:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__jne_cmpf__
	#NO_APP
	addq	$8, %r15
	movsd	-8(%r13), %xmm0                 # xmm0 = mem[0],zero
	ucomisd	(%r13), %xmm0
	je	.LBB1_100
# %bb.99:                               #   in Loop: Header=BB1_98 Depth=1
	movq	(%r15), %rax
	leaq	(%r14,%rax,8), %r15
.LBB1_100:                              #   in Loop: Header=BB1_98 Depth=1
	addq	$-16, %r13
	addq	$8, %r15
	movq	(%r15), %rax
	leaq	"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"(%rip), %rcx
	jmpq	*(%rcx,%rax,8)
	.seh_handlerdata
	.long	("$cppxdata$?execute_reactor@nominax@@YA?AUreactor_output@1@AEBUreactor_input@1@@Z")@IMGREL
	.text
	.seh_endproc
	.def	 "?dtor$111@?0??execute_reactor@nominax@@YA?AUreactor_output@1@AEBUreactor_input@1@@Z@4HA";
	.scl	3;
	.type	32;
	.endef
	.p2align	4, 0x90
"?dtor$111@?0??execute_reactor@nominax@@YA?AUreactor_output@1@AEBUreactor_input@1@@Z@4HA":
.seh_proc "?dtor$111@?0??execute_reactor@nominax@@YA?AUreactor_output@1@AEBUreactor_input@1@@Z@4HA"
.LBB1_111:
	movq	%rdx, 16(%rsp)
	pushq	%rbp
	.seh_pushreg %rbp
	pushq	%r15
	.seh_pushreg %r15
	pushq	%r14
	.seh_pushreg %r14
	pushq	%r13
	.seh_pushreg %r13
	pushq	%r12
	.seh_pushreg %r12
	pushq	%rsi
	.seh_pushreg %rsi
	pushq	%rdi
	.seh_pushreg %rdi
	pushq	%rbx
	.seh_pushreg %rbx
	subq	$40, %rsp
	.seh_stackalloc 40
	leaq	80(%rdx), %rbp
	.seh_endprologue
	callq	__std_terminate
	int3
	.seh_handlerdata
	.text
	.seh_endproc
	.def	 "?dtor$112@?0??execute_reactor@nominax@@YA?AUreactor_output@1@AEBUreactor_input@1@@Z@4HA";
	.scl	3;
	.type	32;
	.endef
	.p2align	4, 0x90
"?dtor$112@?0??execute_reactor@nominax@@YA?AUreactor_output@1@AEBUreactor_input@1@@Z@4HA":
.seh_proc "?dtor$112@?0??execute_reactor@nominax@@YA?AUreactor_output@1@AEBUreactor_input@1@@Z@4HA"
.LBB1_112:
	movq	%rdx, 16(%rsp)
	pushq	%rbp
	.seh_pushreg %rbp
	pushq	%r15
	.seh_pushreg %r15
	pushq	%r14
	.seh_pushreg %r14
	pushq	%r13
	.seh_pushreg %r13
	pushq	%r12
	.seh_pushreg %r12
	pushq	%rsi
	.seh_pushreg %rsi
	pushq	%rdi
	.seh_pushreg %rdi
	pushq	%rbx
	.seh_pushreg %rbx
	subq	$40, %rsp
	.seh_stackalloc 40
	leaq	80(%rdx), %rbp
	.seh_endprologue
	callq	__std_terminate
	int3
.Lfunc_end0:
	.seh_handlerdata
	.text
	.seh_endproc
	.section	.xdata,"dr"
	.p2align	2
"$cppxdata$?execute_reactor@nominax@@YA?AUreactor_output@1@AEBUreactor_input@1@@Z":
	.long	429065506                       # MagicNumber
	.long	2                               # MaxState
	.long	("$stateUnwindMap$?execute_reactor@nominax@@YA?AUreactor_output@1@AEBUreactor_input@1@@Z")@IMGREL # UnwindMap
	.long	0                               # NumTryBlocks
	.long	0                               # TryBlockMap
	.long	5                               # IPMapEntries
	.long	("$ip2state$?execute_reactor@nominax@@YA?AUreactor_output@1@AEBUreactor_input@1@@Z")@IMGREL # IPToStateXData
	.long	80                              # UnwindHelp
	.long	0                               # ESTypeList
	.long	1                               # EHFlags
"$stateUnwindMap$?execute_reactor@nominax@@YA?AUreactor_output@1@AEBUreactor_input@1@@Z":
	.long	-1                              # ToState
	.long	"?dtor$111@?0??execute_reactor@nominax@@YA?AUreactor_output@1@AEBUreactor_input@1@@Z@4HA"@IMGREL # Action
	.long	-1                              # ToState
	.long	"?dtor$112@?0??execute_reactor@nominax@@YA?AUreactor_output@1@AEBUreactor_input@1@@Z@4HA"@IMGREL # Action
"$ip2state$?execute_reactor@nominax@@YA?AUreactor_output@1@AEBUreactor_input@1@@Z":
	.long	.Lfunc_begin0@IMGREL            # IP
	.long	-1                              # ToState
	.long	.Ltmp0@IMGREL+1                 # IP
	.long	0                               # ToState
	.long	.Ltmp3@IMGREL+1                 # IP
	.long	-1                              # ToState
	.long	.Ltmp4@IMGREL+1                 # IP
	.long	1                               # ToState
	.long	.Ltmp7@IMGREL+1                 # IP
	.long	-1                              # ToState
	.text
                                        # -- End function
	.section	.rdata,"dr"
	.p2align	4                               # @"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"
"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB":
	.quad	.Ltmp8
	.quad	.Ltmp9
	.quad	.Ltmp10
	.quad	.Ltmp11
	.quad	.Ltmp12
	.quad	.Ltmp13
	.quad	.Ltmp14
	.quad	.Ltmp15
	.quad	.Ltmp16
	.quad	.Ltmp17
	.quad	.Ltmp18
	.quad	.Ltmp19
	.quad	.Ltmp20
	.quad	.Ltmp21
	.quad	.Ltmp22
	.quad	.Ltmp23
	.quad	.Ltmp24
	.quad	.Ltmp25
	.quad	.Ltmp26
	.quad	.Ltmp27
	.quad	.Ltmp28
	.quad	.Ltmp29
	.quad	.Ltmp30
	.quad	.Ltmp31
	.quad	.Ltmp32
	.quad	.Ltmp33
	.quad	.Ltmp34
	.quad	.Ltmp35
	.quad	.Ltmp36
	.quad	.Ltmp37
	.quad	.Ltmp38
	.quad	.Ltmp39
	.quad	.Ltmp40
	.quad	.Ltmp41
	.quad	.Ltmp42
	.quad	.Ltmp43
	.quad	.Ltmp44
	.quad	.Ltmp45
	.quad	.Ltmp46
	.quad	.Ltmp47
	.quad	.Ltmp48
	.quad	.Ltmp49
	.quad	.Ltmp50
	.quad	.Ltmp51
	.quad	.Ltmp52
	.quad	.Ltmp53
	.quad	.Ltmp54
	.quad	.Ltmp55
	.quad	.Ltmp56
	.quad	.Ltmp57
	.quad	.Ltmp58

	.section	.drectve,"yn"
	.ascii	" /FAILIFMISMATCH:\"_CRT_STDIO_ISO_WIDE_SPECIFIERS=0\""
	.ascii	" /FAILIFMISMATCH:\"_MSC_VER=1900\""
	.ascii	" /FAILIFMISMATCH:\"_ITERATOR_DEBUG_LEVEL=0\""
	.ascii	" /FAILIFMISMATCH:\"RuntimeLibrary=MT_StaticRelease\""
	.ascii	" /DEFAULTLIB:libcpmt.lib"
	.addrsig
	.addrsig_sym "?execute_reactor@nominax@@YA?AUreactor_output@1@AEBUreactor_input@1@@Z"
	.addrsig_sym __CxxFrameHandler3
	.globl	_fltused
