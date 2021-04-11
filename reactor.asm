	.text
	.def	 @feat.00;
	.scl	3;
	.type	0;
	.endef
	.globl	@feat.00
.set @feat.00, 0
	.intel_syntax noprefix
	.file	"reactor.cpp"
	.def	 "?validate@reactor_input@nominax@@QEBA?AW4reactor_validation_result@2@XZ";
	.scl	2;
	.type	32;
	.endef
	.globl	"?validate@reactor_input@nominax@@QEBA?AW4reactor_validation_result@2@XZ" # -- Begin function ?validate@reactor_input@nominax@@QEBA?AW4reactor_validation_result@2@XZ
	.p2align	4, 0x90
"?validate@reactor_input@nominax@@QEBA?AW4reactor_validation_result@2@XZ": # @"?validate@reactor_input@nominax@@QEBA?AW4reactor_validation_result@2@XZ"
# %bb.0:
	mov	eax, 1
	cmp	qword ptr [rcx], 0
	je	.LBB0_14
# %bb.1:
	mov	rdx, qword ptr [rcx + 8]
	test	rdx, rdx
	je	.LBB0_14
# %bb.2:
	mov	r8, qword ptr [rcx + 24]
	test	r8, r8
	je	.LBB0_14
# %bb.3:
	cmp	qword ptr [rcx + 40], 0
	je	.LBB0_14
# %bb.4:
	mov	r9, qword ptr [rcx + 48]
	test	r9, r9
	je	.LBB0_14
# %bb.5:
	mov	eax, 2
	cmp	qword ptr [rcx + 16], 0
	je	.LBB0_14
# %bb.6:
	mov	r10, qword ptr [rcx + 32]
	test	r10, r10
	je	.LBB0_14
# %bb.7:
	cmp	qword ptr [rcx + 56], 0
	je	.LBB0_14
# %bb.8:
	mov	eax, 3
	cmp	dword ptr [rdx], 11
	jne	.LBB0_14
# %bb.9:
	mov	eax, 4
	cmp	dword ptr [r9], -1
	jne	.LBB0_14
# %bb.10:
	lea	rcx, [r8 + 8*r10]
	mov	eax, 5
.LBB0_11:                               # =>This Inner Loop Header: Depth=1
	cmp	r8, rcx
	jae	.LBB0_12
# %bb.13:                               #   in Loop: Header=BB0_11 Depth=1
	cmp	qword ptr [r8], 0
	lea	r8, [r8 + 8]
	jne	.LBB0_11
.LBB0_14:
	ret
.LBB0_12:
	xor	eax, eax
	ret
                                        # -- End function
	.def	 "?execute_reactor@nominax@@YA?AUreactor_output@1@AEBUreactor_input@1@@Z";
	.scl	2;
	.type	32;
	.endef
	.globl	__real@3f800000                 # -- Begin function ?execute_reactor@nominax@@YA?AUreactor_output@1@AEBUreactor_input@1@@Z
	.section	.rdata,"dr",discard,__real@3f800000
	.p2align	2
__real@3f800000:
	.long	0x3f800000                      # float 1
	.globl	__real@bf800000
	.section	.rdata,"dr",discard,__real@bf800000
	.p2align	2
__real@bf800000:
	.long	0xbf800000                      # float -1
	.globl	__xmm@80000000800000008000000080000000
	.section	.rdata,"dr",discard,__xmm@80000000800000008000000080000000
	.p2align	4
__xmm@80000000800000008000000080000000:
	.long	0x80000000                      # float -0
	.long	0x80000000                      # float -0
	.long	0x80000000                      # float -0
	.long	0x80000000                      # float -0
	.text
	.globl	"?execute_reactor@nominax@@YA?AUreactor_output@1@AEBUreactor_input@1@@Z"
	.p2align	4, 0x90
"?execute_reactor@nominax@@YA?AUreactor_output@1@AEBUreactor_input@1@@Z": # @"?execute_reactor@nominax@@YA?AUreactor_output@1@AEBUreactor_input@1@@Z"
.Lfunc_begin0:
.seh_proc "?execute_reactor@nominax@@YA?AUreactor_output@1@AEBUreactor_input@1@@Z"
	.seh_handler __CxxFrameHandler3, @unwind, @except
# %bb.0:
	push	rbp
	.seh_pushreg rbp
	push	r15
	.seh_pushreg r15
	push	r14
	.seh_pushreg r14
	push	r13
	.seh_pushreg r13
	push	r12
	.seh_pushreg r12
	push	rsi
	.seh_pushreg rsi
	push	rdi
	.seh_pushreg rdi
	push	rbx
	.seh_pushreg rbx
	sub	rsp, 88
	.seh_stackalloc 88
	lea	rbp, [rsp + 80]
	.seh_setframe rbp, 80
	.seh_endprologue
	mov	qword ptr [rbp], -2
	mov	r13, rdx
	mov	rsi, rcx
	mov	eax, 1
	cmp	qword ptr [rdx], 0
	je	.LBB1_13
# %bb.1:
	mov	rdx, qword ptr [r13 + 8]
	test	rdx, rdx
	je	.LBB1_13
# %bb.2:
	mov	rcx, qword ptr [r13 + 24]
	test	rcx, rcx
	je	.LBB1_13
# %bb.3:
	cmp	qword ptr [r13 + 40], 0
	je	.LBB1_13
# %bb.4:
	mov	rbx, qword ptr [r13 + 48]
	test	rbx, rbx
	je	.LBB1_13
# %bb.5:
	mov	eax, 2
	cmp	qword ptr [r13 + 16], 0
	je	.LBB1_13
# %bb.6:
	mov	rdi, qword ptr [r13 + 32]
	test	rdi, rdi
	je	.LBB1_13
# %bb.7:
	cmp	qword ptr [r13 + 56], 0
	je	.LBB1_13
# %bb.8:
	mov	eax, 3
	cmp	dword ptr [rdx], 11
	jne	.LBB1_13
# %bb.9:
	mov	eax, 4
	cmp	dword ptr [rbx], -1
	jne	.LBB1_13
# %bb.10:
	lea	rdx, [rcx + 8*rdi]
	mov	eax, 5
.LBB1_11:                               # =>This Inner Loop Header: Depth=1
	cmp	rcx, rdx
	jae	.LBB1_14
# %bb.12:                               #   in Loop: Header=BB1_11 Depth=1
	cmp	qword ptr [rcx], 0
	lea	rcx, [rcx + 8]
	jne	.LBB1_11
.LBB1_13:
	mov	dword ptr [rsi], eax
	movups	xmm0, xmmword ptr [r13]
	movups	xmm1, xmmword ptr [r13 + 16]
	movups	xmm2, xmmword ptr [r13 + 32]
	movups	xmm3, xmmword ptr [r13 + 48]
	movups	xmmword ptr [rsi + 8], xmm0
	movups	xmmword ptr [rsi + 24], xmm1
	movups	xmmword ptr [rsi + 40], xmm2
	movups	xmmword ptr [rsi + 56], xmm3
	mov	rax, qword ptr [r13 + 64]
	mov	qword ptr [rsi + 72], rax
	mov	byte ptr [rsi + 80], 0
	xorps	xmm0, xmm0
	movups	xmmword ptr [rsi + 88], xmm0
	movups	xmmword ptr [rsi + 100], xmm0
	movups	xmmword ptr [rsi + 120], xmm0
.LBB1_94:
	mov	rax, rsi
	add	rsp, 88
	pop	rbx
	pop	rdi
	pop	rsi
	pop	r12
	pop	r13
	pop	r14
	pop	r15
	pop	rbp
	ret
.LBB1_14:
.Ltmp0:
	call	_Query_perf_frequency
.Ltmp1:
# %bb.15:
	mov	rbx, rax
.Ltmp2:
	call	_Query_perf_counter
.Ltmp3:
# %bb.16:
	mov	rcx, rax
	or	rcx, rbx
	shr	rcx, 32
	je	.LBB1_17
# %bb.18:
	cqo
	idiv	rbx
	jmp	.LBB1_19
.LBB1_17:
                                        # kill: def $eax killed $eax killed $rax
	xor	edx, edx
	div	ebx
                                        # kill: def $edx killed $edx def $rdx
                                        # kill: def $eax killed $eax def $rax
.LBB1_19:
	imul	rcx, rax, 1000000000
	imul	rax, rdx, 1000000000
	mov	rdx, rbx
	or	rdx, rax
	shr	rdx, 32
	je	.LBB1_20
# %bb.21:
	cqo
	idiv	rbx
	add	rax, rcx
	mov	qword ptr [rbp - 16], rax       # 8-byte Spill
	#APP
	#reactor begin
	#NO_APP
	mov	rax, qword ptr [r13 + 64]
	mov	qword ptr [rbp - 40], rax       # 8-byte Spill
	mov	rax, qword ptr [r13]
	mov	qword ptr [rbp - 32], rax       # 8-byte Spill
	mov	rax, qword ptr [r13 + 8]
	mov	rcx, qword ptr [r13 + 24]
	mov	qword ptr [rbp - 8], rcx        # 8-byte Spill
	mov	rcx, qword ptr [r13 + 40]
	mov	qword ptr [rbp - 24], rcx       # 8-byte Spill
	mov	r15, qword ptr [r13 + 48]
	#APP
	#reactor exec
	#NO_APP
	lea	rdi, [rax + 4]
	mov	r12, rax
	lea	r14, [rax - 4]
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
.LBB1_20:
                                        # kill: def $eax killed $eax killed $rax
	xor	edx, edx
	div	ebx
                                        # kill: def $eax killed $eax def $rax
	add	rax, rcx
	mov	qword ptr [rbp - 16], rax       # 8-byte Spill
	#APP
	#reactor begin
	#NO_APP
	mov	rax, qword ptr [r13 + 64]
	mov	qword ptr [rbp - 40], rax       # 8-byte Spill
	mov	rax, qword ptr [r13]
	mov	qword ptr [rbp - 32], rax       # 8-byte Spill
	mov	rax, qword ptr [r13 + 8]
	mov	rcx, qword ptr [r13 + 24]
	mov	qword ptr [rbp - 8], rcx        # 8-byte Spill
	mov	rcx, qword ptr [r13 + 40]
	mov	qword ptr [rbp - 24], rcx       # 8-byte Spill
	mov	r15, qword ptr [r13 + 48]
	#APP
	#reactor exec
	#NO_APP
	lea	rdi, [rax + 4]
	mov	r12, rax
	lea	r14, [rax - 4]
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp8:                                 # Block address taken
.LBB1_22:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__int__
	#NO_APP
	mov	ebx, dword ptr [rdi + 4]
	test	ebx, ebx
	js	.LBB1_85
# %bb.23:                               #   in Loop: Header=BB1_22 Depth=1
	mov	ecx, ebx
	mov	rdx, qword ptr [rbp - 32]       # 8-byte Reload
	mov	r8, qword ptr [rbp - 40]        # 8-byte Reload
	call	qword ptr [rbp - 24]            # 8-byte Folded Reload
	test	al, al
	je	.LBB1_85
# %bb.24:                               #   in Loop: Header=BB1_22 Depth=1
	add	rdi, 8
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
.LBB1_85:
	#APP
	#reactor end
	#NO_APP
.Ltmp4:
	call	_Query_perf_frequency
.Ltmp5:
# %bb.86:
	mov	r14, rax
.Ltmp6:
	call	_Query_perf_counter
.Ltmp7:
# %bb.87:
	mov	rcx, rax
	or	rcx, r14
	shr	rcx, 32
	je	.LBB1_88
# %bb.89:
	cqo
	idiv	r14
	jmp	.LBB1_90
.LBB1_88:
                                        # kill: def $eax killed $eax killed $rax
	xor	edx, edx
	div	r14d
                                        # kill: def $edx killed $edx def $rdx
                                        # kill: def $eax killed $eax def $rax
.LBB1_90:
	add	rdi, 4
	imul	rcx, rax, 1000000000
	imul	rax, rdx, 1000000000
	mov	rdx, r14
	or	rdx, rax
	shr	rdx, 32
	je	.LBB1_91
# %bb.92:
	cqo
	idiv	r14
	jmp	.LBB1_93
.LBB1_91:
                                        # kill: def $eax killed $eax killed $rax
	xor	edx, edx
	div	r14d
                                        # kill: def $eax killed $eax def $rax
.LBB1_93:
	add	rax, rcx
	mov	rcx, rax
	mov	r8, qword ptr [rbp - 16]        # 8-byte Reload
	sub	rcx, r8
	sub	rdi, qword ptr [r13 + 8]
	sar	rdi, 2
	sub	r15, qword ptr [r13 + 48]
	sar	r15, 2
	#APP
	#reactor ret
	#NO_APP
	mov	dword ptr [rsi], 0
	movups	xmm0, xmmword ptr [r13]
	movups	xmm1, xmmword ptr [r13 + 16]
	movups	xmm2, xmmword ptr [r13 + 32]
	movups	xmm3, xmmword ptr [r13 + 48]
	movups	xmmword ptr [rsi + 8], xmm0
	movups	xmmword ptr [rsi + 24], xmm1
	movups	xmmword ptr [rsi + 40], xmm2
	movups	xmmword ptr [rsi + 56], xmm3
	mov	rdx, qword ptr [r13 + 64]
	mov	qword ptr [rsi + 72], rdx
	test	ebx, ebx
	sete	byte ptr [rsi + 80]
	mov	qword ptr [rsi + 88], r8
	mov	qword ptr [rsi + 96], rax
	mov	qword ptr [rsi + 104], rcx
	mov	dword ptr [rsi + 112], ebx
	mov	qword ptr [rsi + 120], rdi
	mov	qword ptr [rsi + 128], r15
	jmp	.LBB1_94
	.p2align	4, 0x90
.Ltmp9:                                 # Block address taken
.LBB1_25:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__intrin__
	#NO_APP
	mov	eax, dword ptr [rdi + 4]
	test	eax, eax
	jns	.LBB1_26
# %bb.27:                               #   in Loop: Header=BB1_25 Depth=1
	add	rdi, 8
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
.LBB1_26:                               #   in Loop: Header=BB1_25 Depth=1
	mov	rcx, qword ptr [rbp - 8]        # 8-byte Reload
	call	qword ptr [rcx + 8*rax]
	add	rdi, 8
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp10:                                # Block address taken
.LBB1_28:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__call__
	#NO_APP
	add	rdi, 4
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp11:                                # Block address taken
.LBB1_29:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__ret__
	#NO_APP
	add	rdi, 4
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp12:                                # Block address taken
.LBB1_30:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__mov__
	#NO_APP
	mov	eax, dword ptr [rdi + 4]
	mov	ecx, dword ptr [rdi + 8]
	mov	ecx, dword ptr [r15 + 4*rcx]
	mov	dword ptr [r15 + 4*rax], ecx
	add	rdi, 12
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp13:                                # Block address taken
.LBB1_31:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__sto__
	#NO_APP
	mov	eax, dword ptr [rdi + 4]
	mov	ecx, dword ptr [rdi + 8]
	mov	dword ptr [r15 + 4*rax], ecx
	add	rdi, 12
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp14:                                # Block address taken
.LBB1_32:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__push__
	#NO_APP
	mov	eax, dword ptr [rdi + 4]
	mov	dword ptr [r15 + 4], eax
	add	r15, 4
	add	rdi, 8
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp15:                                # Block address taken
.LBB1_33:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__pop__
	#NO_APP
	add	r15, -4
	add	rdi, 4
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp16:                                # Block address taken
.LBB1_34:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__pop2__
	#NO_APP
	add	r15, -8
	add	rdi, 4
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp17:                                # Block address taken
.LBB1_35:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__dupl__
	#NO_APP
	mov	eax, dword ptr [r15]
	mov	dword ptr [r15 + 4], eax
	add	r15, 4
	add	rdi, 4
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp18:                                # Block address taken
.LBB1_36:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__dupl2__
	#NO_APP
	mov	eax, dword ptr [r15]
	mov	dword ptr [r15 + 4], eax
	mov	dword ptr [r15 + 8], eax
	add	r15, 8
	add	rdi, 4
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp19:                                # Block address taken
.LBB1_37:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__nop__
	#NO_APP
	add	rdi, 4
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp20:                                # Block address taken
.LBB1_38:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__ipushz__
	#NO_APP
	mov	dword ptr [r15 + 4], 0
	add	r15, 4
	add	rdi, 4
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp21:                                # Block address taken
.LBB1_39:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__ipusho__
	#NO_APP
	mov	dword ptr [r15 + 4], 1
	add	r15, 4
	add	rdi, 4
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp22:                                # Block address taken
.LBB1_40:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__fpusho__
	#NO_APP
	mov	dword ptr [r15 + 4], 1065353216
	add	r15, 4
	add	rdi, 4
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp23:                                # Block address taken
.LBB1_41:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__iinc__
	#NO_APP
	add	dword ptr [r15], 1
	add	rdi, 4
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp24:                                # Block address taken
.LBB1_42:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__idec__
	#NO_APP
	add	dword ptr [r15], -1
	add	rdi, 4
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp25:                                # Block address taken
.LBB1_43:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__iadd__
	#NO_APP
	mov	eax, dword ptr [r15]
	add	dword ptr [r15 - 4], eax
	add	r15, -4
	add	rdi, 4
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp26:                                # Block address taken
.LBB1_44:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__isub__
	#NO_APP
	mov	eax, dword ptr [r15]
	sub	dword ptr [r15 - 4], eax
	add	r15, -4
	add	rdi, 4
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp27:                                # Block address taken
.LBB1_45:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__imul__
	#NO_APP
	mov	eax, dword ptr [r15 - 4]
	imul	eax, dword ptr [r15]
	mov	dword ptr [r15 - 4], eax
	add	r15, -4
	add	rdi, 4
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp28:                                # Block address taken
.LBB1_46:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__idiv__
	#NO_APP
	mov	eax, dword ptr [r15 - 4]
	cdq
	idiv	dword ptr [r15]
	mov	dword ptr [r15 - 4], eax
	add	r15, -4
	add	rdi, 4
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp29:                                # Block address taken
.LBB1_47:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__imod__
	#NO_APP
	mov	eax, dword ptr [r15 - 4]
	cdq
	idiv	dword ptr [r15]
	mov	dword ptr [r15 - 4], edx
	add	r15, -4
	add	rdi, 4
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp30:                                # Block address taken
.LBB1_48:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__iand__
	#NO_APP
	mov	eax, dword ptr [r15]
	and	dword ptr [r15 - 4], eax
	add	r15, -4
	add	rdi, 4
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp31:                                # Block address taken
.LBB1_49:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__ior__
	#NO_APP
	mov	eax, dword ptr [r15]
	or	dword ptr [r15 - 4], eax
	add	r15, -4
	add	rdi, 4
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp32:                                # Block address taken
.LBB1_50:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__ixor__
	#NO_APP
	mov	eax, dword ptr [r15]
	xor	dword ptr [r15 - 4], eax
	add	r15, -4
	add	rdi, 4
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp33:                                # Block address taken
.LBB1_51:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__icom__
	#NO_APP
	not	dword ptr [r15]
	add	rdi, 4
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp34:                                # Block address taken
.LBB1_52:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__isal__
	#NO_APP
	movzx	ecx, byte ptr [r15]
	shl	dword ptr [r15 - 4], cl
	add	r15, -4
	add	rdi, 4
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp35:                                # Block address taken
.LBB1_53:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__isar__
	#NO_APP
	movzx	ecx, byte ptr [r15]
	sar	dword ptr [r15 - 4], cl
	add	r15, -4
	add	rdi, 4
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp36:                                # Block address taken
.LBB1_54:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__irol__
	#NO_APP
	movzx	ecx, byte ptr [r15]
	rol	dword ptr [r15 - 4], cl
	add	r15, -4
	add	rdi, 4
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp37:                                # Block address taken
.LBB1_55:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__iror__
	#NO_APP
	movzx	ecx, byte ptr [r15]
	ror	dword ptr [r15 - 4], cl
	add	r15, -4
	add	rdi, 4
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp38:                                # Block address taken
.LBB1_56:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__ineg__
	#NO_APP
	neg	dword ptr [r15]
	add	rdi, 4
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp39:                                # Block address taken
.LBB1_57:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__fadd__
	#NO_APP
	movss	xmm0, dword ptr [r15 - 4]       # xmm0 = mem[0],zero,zero,zero
	addss	xmm0, dword ptr [r15]
	movss	dword ptr [r15 - 4], xmm0
	add	r15, -4
	add	rdi, 4
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp40:                                # Block address taken
.LBB1_58:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__fsub__
	#NO_APP
	movss	xmm0, dword ptr [r15 - 4]       # xmm0 = mem[0],zero,zero,zero
	subss	xmm0, dword ptr [r15]
	movss	dword ptr [r15 - 4], xmm0
	add	r15, -4
	add	rdi, 4
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp41:                                # Block address taken
.LBB1_59:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__fmul__
	#NO_APP
	movss	xmm0, dword ptr [r15 - 4]       # xmm0 = mem[0],zero,zero,zero
	mulss	xmm0, dword ptr [r15]
	movss	dword ptr [r15 - 4], xmm0
	add	r15, -4
	add	rdi, 4
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp42:                                # Block address taken
.LBB1_60:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__fdiv__
	#NO_APP
	movss	xmm0, dword ptr [r15 - 4]       # xmm0 = mem[0],zero,zero,zero
	divss	xmm0, dword ptr [r15]
	movss	dword ptr [r15 - 4], xmm0
	add	r15, -4
	add	rdi, 4
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp43:                                # Block address taken
.LBB1_61:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__fmod__
	#NO_APP
	lea	rbx, [r15 - 4]
	movss	xmm0, dword ptr [r15 - 4]       # xmm0 = mem[0],zero,zero,zero
	movss	xmm1, dword ptr [r15]           # xmm1 = mem[0],zero,zero,zero
	call	fmodf
	movss	dword ptr [r15 - 4], xmm0
	add	rdi, 4
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	mov	r15, rbx
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp44:                                # Block address taken
.LBB1_62:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__fneg__
	#NO_APP
	movss	xmm0, dword ptr [r15]           # xmm0 = mem[0],zero,zero,zero
	xorps	xmm0, xmmword ptr [rip + __xmm@80000000800000008000000080000000]
	movss	dword ptr [r15], xmm0
	add	rdi, 4
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp45:                                # Block address taken
.LBB1_63:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__finc__
	#NO_APP
	movss	xmm0, dword ptr [r15]           # xmm0 = mem[0],zero,zero,zero
	addss	xmm0, dword ptr [rip + __real@3f800000]
	movss	dword ptr [r15], xmm0
	add	rdi, 4
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp46:                                # Block address taken
.LBB1_64:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__fdec__
	#NO_APP
	movss	xmm0, dword ptr [r15]           # xmm0 = mem[0],zero,zero,zero
	addss	xmm0, dword ptr [rip + __real@bf800000]
	movss	dword ptr [r15], xmm0
	add	rdi, 4
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp47:                                # Block address taken
.LBB1_65:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__jmp__
	#NO_APP
	mov	eax, dword ptr [rdi + 4]
	lea	rdi, [r12 + 4*rax]
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp48:                                # Block address taken
.LBB1_66:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__jmprel__
	#NO_APP
	mov	eax, dword ptr [rdi + 4]
	lea	rdi, [rdi + 4*rax]
	add	rdi, 4
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp49:                                # Block address taken
.LBB1_67:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__jz__
	#NO_APP
	add	rdi, 4
	cmp	dword ptr [r15], 0
	jne	.LBB1_69
# %bb.68:                               #   in Loop: Header=BB1_67 Depth=1
	mov	eax, dword ptr [rdi]
	lea	rdi, [r14 + 4*rax]
.LBB1_69:                               #   in Loop: Header=BB1_67 Depth=1
	add	r15, -4
	add	rdi, 4
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp50:                                # Block address taken
.LBB1_70:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__jnz__
	#NO_APP
	add	rdi, 4
	cmp	dword ptr [r15], 0
	je	.LBB1_72
# %bb.71:                               #   in Loop: Header=BB1_70 Depth=1
	mov	eax, dword ptr [rdi]
	lea	rdi, [r14 + 4*rax]
.LBB1_72:                               #   in Loop: Header=BB1_70 Depth=1
	add	r15, -4
	add	rdi, 4
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp51:                                # Block address taken
.LBB1_73:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__jo_cmpi__
	#NO_APP
	add	rdi, 4
	cmp	dword ptr [r15], 1
	jne	.LBB1_75
# %bb.74:                               #   in Loop: Header=BB1_73 Depth=1
	mov	eax, dword ptr [rdi]
	lea	rdi, [r14 + 4*rax]
.LBB1_75:                               #   in Loop: Header=BB1_73 Depth=1
	add	r15, -4
	add	rdi, 4
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp52:                                # Block address taken
.LBB1_76:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__jo_cmpf__
	#NO_APP
	add	rdi, 4
	movss	xmm0, dword ptr [rip + __real@3f800000] # xmm0 = mem[0],zero,zero,zero
	ucomiss	xmm0, dword ptr [r15]
	jne	.LBB1_78
# %bb.77:                               #   in Loop: Header=BB1_76 Depth=1
	mov	eax, dword ptr [rdi]
	lea	rdi, [r14 + 4*rax]
.LBB1_78:                               #   in Loop: Header=BB1_76 Depth=1
	add	r15, -4
	add	rdi, 4
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp53:                                # Block address taken
.LBB1_79:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__jno_cmpi__
	#NO_APP
	add	rdi, 4
	cmp	dword ptr [r15], 1
	je	.LBB1_81
# %bb.80:                               #   in Loop: Header=BB1_79 Depth=1
	mov	eax, dword ptr [rdi]
	lea	rdi, [r14 + 4*rax]
.LBB1_81:                               #   in Loop: Header=BB1_79 Depth=1
	add	r15, -4
	add	rdi, 4
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.p2align	4, 0x90
.Ltmp54:                                # Block address taken
.LBB1_82:                               # =>This Inner Loop Header: Depth=1
	#APP
	#__jno_cmpf__
	#NO_APP
	add	rdi, 4
	movss	xmm0, dword ptr [rip + __real@3f800000] # xmm0 = mem[0],zero,zero,zero
	ucomiss	xmm0, dword ptr [r15]
	je	.LBB1_84
# %bb.83:                               #   in Loop: Header=BB1_82 Depth=1
	mov	eax, dword ptr [rdi]
	lea	rdi, [r14 + 4*rax]
.LBB1_84:                               #   in Loop: Header=BB1_82 Depth=1
	add	r15, -4
	add	rdi, 4
	mov	eax, dword ptr [rdi]
	lea	rcx, [rip + "?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"]
	jmp	qword ptr [rcx + 8*rax]
	.seh_handlerdata
	.long	("$cppxdata$?execute_reactor@nominax@@YA?AUreactor_output@1@AEBUreactor_input@1@@Z")@IMGREL
	.text
	.seh_endproc
	.def	 "?dtor$95@?0??execute_reactor@nominax@@YA?AUreactor_output@1@AEBUreactor_input@1@@Z@4HA";
	.scl	3;
	.type	32;
	.endef
	.p2align	4, 0x90
"?dtor$95@?0??execute_reactor@nominax@@YA?AUreactor_output@1@AEBUreactor_input@1@@Z@4HA":
.seh_proc "?dtor$95@?0??execute_reactor@nominax@@YA?AUreactor_output@1@AEBUreactor_input@1@@Z@4HA"
.LBB1_95:
	mov	qword ptr [rsp + 16], rdx
	push	rbp
	.seh_pushreg rbp
	push	r15
	.seh_pushreg r15
	push	r14
	.seh_pushreg r14
	push	r13
	.seh_pushreg r13
	push	r12
	.seh_pushreg r12
	push	rsi
	.seh_pushreg rsi
	push	rdi
	.seh_pushreg rdi
	push	rbx
	.seh_pushreg rbx
	sub	rsp, 40
	.seh_stackalloc 40
	lea	rbp, [rdx + 80]
	.seh_endprologue
	call	__std_terminate
	int3
	.seh_handlerdata
	.text
	.seh_endproc
	.def	 "?dtor$96@?0??execute_reactor@nominax@@YA?AUreactor_output@1@AEBUreactor_input@1@@Z@4HA";
	.scl	3;
	.type	32;
	.endef
	.p2align	4, 0x90
"?dtor$96@?0??execute_reactor@nominax@@YA?AUreactor_output@1@AEBUreactor_input@1@@Z@4HA":
.seh_proc "?dtor$96@?0??execute_reactor@nominax@@YA?AUreactor_output@1@AEBUreactor_input@1@@Z@4HA"
.LBB1_96:
	mov	qword ptr [rsp + 16], rdx
	push	rbp
	.seh_pushreg rbp
	push	r15
	.seh_pushreg r15
	push	r14
	.seh_pushreg r14
	push	r13
	.seh_pushreg r13
	push	r12
	.seh_pushreg r12
	push	rsi
	.seh_pushreg rsi
	push	rdi
	.seh_pushreg rdi
	push	rbx
	.seh_pushreg rbx
	sub	rsp, 40
	.seh_stackalloc 40
	lea	rbp, [rdx + 80]
	.seh_endprologue
	call	__std_terminate
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
	.long	"?dtor$95@?0??execute_reactor@nominax@@YA?AUreactor_output@1@AEBUreactor_input@1@@Z@4HA"@IMGREL # Action
	.long	-1                              # ToState
	.long	"?dtor$96@?0??execute_reactor@nominax@@YA?AUreactor_output@1@AEBUreactor_input@1@@Z@4HA"@IMGREL # Action
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
	.p2align	4                               # @"?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB"
"?branch_table@?1??execute_reactor@nominax@@YA?AUreactor_output@2@AEBUreactor_input@2@@Z@4QBQEIBXB":
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
