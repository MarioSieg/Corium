	.text
	.def	 @feat.00;
	.scl	3;
	.type	0;
	.endef
	.globl	@feat.00
.set @feat.00, 1
	.intel_syntax noprefix
	.file	"reactor.cpp"
	.def	 "?validate@reactor_input@nominax@@QBE?AW4reactor_validation_result@2@XZ";
	.scl	2;
	.type	32;
	.endef
	.globl	"?validate@reactor_input@nominax@@QBE?AW4reactor_validation_result@2@XZ" # -- Begin function ?validate@reactor_input@nominax@@QBE?AW4reactor_validation_result@2@XZ
	.p2align	4, 0x90
"?validate@reactor_input@nominax@@QBE?AW4reactor_validation_result@2@XZ": # @"?validate@reactor_input@nominax@@QBE?AW4reactor_validation_result@2@XZ"
# %bb.0:
	push	ebx
	push	edi
	push	esi
	cmp	dword ptr [ecx], 0
	mov	eax, 1
	je	LBB0_14
# %bb.1:
	mov	esi, dword ptr [ecx + 4]
	test	esi, esi
	je	LBB0_14
# %bb.2:
	mov	edx, dword ptr [ecx + 12]
	test	edx, edx
	je	LBB0_14
# %bb.3:
	cmp	dword ptr [ecx + 20], 0
	je	LBB0_14
# %bb.4:
	mov	edi, dword ptr [ecx + 24]
	test	edi, edi
	je	LBB0_14
# %bb.5:
	cmp	dword ptr [ecx + 8], 0
	mov	eax, 2
	je	LBB0_14
# %bb.6:
	mov	ebx, dword ptr [ecx + 16]
	test	ebx, ebx
	je	LBB0_14
# %bb.7:
	cmp	dword ptr [ecx + 28], 0
	je	LBB0_14
# %bb.8:
	cmp	dword ptr [esi], 11
	mov	eax, 3
	jne	LBB0_14
# %bb.9:
	cmp	dword ptr [edi], -1
	mov	eax, 4
	jne	LBB0_14
# %bb.10:
	lea	ecx, [edx + 4*ebx]
	mov	eax, 5
LBB0_11:                                # =>This Inner Loop Header: Depth=1
	cmp	edx, ecx
	jae	LBB0_12
# %bb.13:                               #   in Loop: Header=BB0_11 Depth=1
	cmp	dword ptr [edx], 0
	lea	edx, [edx + 4]
	jne	LBB0_11
	jmp	LBB0_14
LBB0_12:
	xor	eax, eax
LBB0_14:
	pop	esi
	pop	edi
	pop	ebx
	ret
                                        # -- End function
	.def	 "?execute_reactor@nominax@@YA?AUreactor_output@1@ABUreactor_input@1@@Z";
	.scl	2;
	.type	32;
	.endef
	.globl	__real@3f800000                 # -- Begin function ?execute_reactor@nominax@@YA?AUreactor_output@1@ABUreactor_input@1@@Z
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
	.globl	"?execute_reactor@nominax@@YA?AUreactor_output@1@ABUreactor_input@1@@Z"
	.p2align	4, 0x90
"?execute_reactor@nominax@@YA?AUreactor_output@1@ABUreactor_input@1@@Z": # @"?execute_reactor@nominax@@YA?AUreactor_output@1@ABUreactor_input@1@@Z"
Lfunc_begin0:
# %bb.0:
	push	ebp
	mov	ebp, esp
	push	ebx
	push	edi
	push	esi
	sub	esp, 60
	mov	dword ptr [ebp - 28], esp
	mov	dword ptr [ebp - 16], -1
	mov	dword ptr [ebp - 20], offset "___ehhandler$?execute_reactor@nominax@@YA?AUreactor_output@1@ABUreactor_input@1@@Z"
	mov	esi, dword ptr [ebp + 12]
	lea	eax, [ebp - 24]
	mov	ebx, dword ptr [ebp + 8]
	mov	ecx, dword ptr fs:[0]
	mov	dword ptr [ebp - 24], ecx
	mov	dword ptr fs:[0], eax
	mov	eax, 1
	cmp	dword ptr [esi], 0
	je	LBB1_13
# %bb.1:
	mov	edx, dword ptr [esi + 4]
	test	edx, edx
	je	LBB1_13
# %bb.2:
	mov	ecx, dword ptr [esi + 12]
	test	ecx, ecx
	je	LBB1_13
# %bb.3:
	cmp	dword ptr [esi + 20], 0
	je	LBB1_13
# %bb.4:
	mov	esi, dword ptr [esi + 24]
	test	esi, esi
	je	LBB1_13
# %bb.5:
	mov	edi, dword ptr [ebp + 12]
	mov	eax, 2
	cmp	dword ptr [edi + 8], 0
	je	LBB1_13
# %bb.6:
	mov	edi, dword ptr [edi + 16]
	test	edi, edi
	je	LBB1_13
# %bb.7:
	mov	dword ptr [ebp - 32], edi       # 4-byte Spill
	mov	edi, dword ptr [ebp + 12]
	cmp	dword ptr [edi + 28], 0
	je	LBB1_13
# %bb.8:
	cmp	dword ptr [edx], 11
	mov	eax, 3
	jne	LBB1_13
# %bb.9:
	cmp	dword ptr [esi], -1
	mov	eax, 4
	jne	LBB1_13
# %bb.10:
	mov	eax, dword ptr [ebp - 32]       # 4-byte Reload
	lea	edx, [ecx + 4*eax]
	mov	eax, 5
LBB1_11:                                # =>This Inner Loop Header: Depth=1
	cmp	ecx, edx
	jae	LBB1_14
# %bb.12:                               #   in Loop: Header=BB1_11 Depth=1
	cmp	dword ptr [ecx], 0
	lea	ecx, [ecx + 4]
	jne	LBB1_11
LBB1_13:
	mov	dword ptr [ebx], eax
	mov	eax, dword ptr [ebp + 12]
	movsd	xmm0, qword ptr [eax]           # xmm0 = mem[0],zero
	movsd	xmm1, qword ptr [eax + 8]       # xmm1 = mem[0],zero
	movsd	qword ptr [ebx + 4], xmm0
	movsd	qword ptr [ebx + 12], xmm1
	movsd	xmm0, qword ptr [eax + 16]      # xmm0 = mem[0],zero
	movsd	qword ptr [ebx + 20], xmm0
	movsd	xmm0, qword ptr [eax + 24]      # xmm0 = mem[0],zero
	movsd	qword ptr [ebx + 28], xmm0
	mov	eax, dword ptr [eax + 32]
	mov	dword ptr [ebx + 36], eax
	mov	byte ptr [ebx + 40], 0
	mov	dword ptr [ebx + 52], 0
	mov	dword ptr [ebx + 48], 0
	mov	dword ptr [ebx + 60], 0
	mov	dword ptr [ebx + 56], 0
	mov	dword ptr [ebx + 68], 0
	mov	dword ptr [ebx + 64], 0
	mov	dword ptr [ebx + 76], 0
	mov	dword ptr [ebx + 72], 0
	mov	dword ptr [ebx + 80], 0
LBB1_103:
	mov	eax, dword ptr [ebp - 24]
	mov	dword ptr fs:[0], eax
	mov	eax, ebx
	add	esp, 60
	pop	esi
	pop	edi
	pop	ebx
	pop	ebp
	ret
LBB1_14:
	mov	dword ptr [ebp - 16], 0
	call	__Query_perf_frequency
	mov	dword ptr [ebp - 48], eax       # 4-byte Spill
	mov	dword ptr [ebp - 32], edx       # 4-byte Spill
# %bb.15:
	call	__Query_perf_counter
# %bb.16:
	push	dword ptr [ebp - 32]            # 4-byte Folded Reload
	mov	edi, dword ptr [ebp - 48]       # 4-byte Reload
	push	edi
	push	edx
	push	eax
	mov	dword ptr [ebp - 52], eax       # 4-byte Spill
	mov	dword ptr [ebp - 36], edx       # 4-byte Spill
	call	__alldiv
	mov	esi, eax
	mov	ecx, 1000000000
	mov	ebx, edx
	mul	ecx
	mov	ecx, esi
	mov	dword ptr [ebp - 44], eax       # 4-byte Spill
	imul	eax, ebx, 1000000000
	imul	ecx, dword ptr [ebp - 32]       # 4-byte Folded Reload
	imul	ebx, edi
	add	eax, edx
	mov	dword ptr [ebp - 40], eax       # 4-byte Spill
	mov	eax, esi
	mul	edi
	add	edx, ecx
	add	ebx, edx
	mov	edx, dword ptr [ebp - 52]       # 4-byte Reload
	sub	edx, eax
	mov	eax, dword ptr [ebp - 36]       # 4-byte Reload
	sbb	eax, ebx
	imul	ecx, eax, 1000000000
	mov	eax, edx
	mov	edx, 1000000000
	mul	edx
	add	edx, ecx
	push	dword ptr [ebp - 32]            # 4-byte Folded Reload
	push	edi
	push	edx
	push	eax
	call	__alldiv
	add	eax, dword ptr [ebp - 44]       # 4-byte Folded Reload
	mov	dword ptr [ebp - 52], eax       # 4-byte Spill
	adc	edx, dword ptr [ebp - 40]       # 4-byte Folded Reload
	mov	eax, dword ptr [ebp + 12]
	mov	dword ptr [ebp - 72], edx       # 4-byte Spill
	#APP
	##reactor begin
	#NO_APP
	mov	ecx, dword ptr [eax + 32]
	mov	edx, dword ptr [eax + 4]
	mov	esi, dword ptr [eax + 24]
	mov	dword ptr [ebp - 44], ecx       # 4-byte Spill
	mov	ecx, dword ptr [eax]
	lea	ebx, [edx + 4]
	mov	dword ptr [ebp - 40], ecx       # 4-byte Spill
	mov	ecx, dword ptr [eax + 12]
	mov	dword ptr [ebp - 56], ecx       # 4-byte Spill
	mov	ecx, dword ptr [eax + 20]
	lea	eax, [edx - 4]
	mov	dword ptr [ebp - 36], ecx       # 4-byte Spill
	#APP
	#reactor exec
	#NO_APP
	mov	ecx, dword ptr [ebx]
	mov	dword ptr [ebp - 48], edx       # 4-byte Spill
	mov	dword ptr [ebp - 32], eax       # 4-byte Spill
	jmp	dword ptr [4*ecx + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp8:                                  # Block address taken
LBB1_17:                                # =>This Inner Loop Header: Depth=1
	#APP
	#__int__
	#NO_APP
	mov	edi, dword ptr [ebx + 4]
	test	edi, edi
	js	LBB1_100
# %bb.18:                               #   in Loop: Header=BB1_17 Depth=1
	push	dword ptr [ebp - 44]            # 4-byte Folded Reload
	push	dword ptr [ebp - 40]            # 4-byte Folded Reload
	push	edi
	call	dword ptr [ebp - 36]            # 4-byte Folded Reload
	add	esp, 12
	test	al, al
	je	LBB1_100
# %bb.19:                               #   in Loop: Header=BB1_17 Depth=1
	add	ebx, 8
	mov	ecx, dword ptr [ebx]
	jmp	dword ptr [4*ecx + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
LBB1_100:
	mov	dword ptr [ebp - 68], edi       # 4-byte Spill
	mov	dword ptr [ebp - 44], ebx       # 4-byte Spill
	mov	dword ptr [ebp - 48], esi       # 4-byte Spill
	#APP
	#reactor end
	#NO_APP
	mov	dword ptr [ebp - 16], 1
	call	__Query_perf_frequency
	mov	dword ptr [ebp - 40], eax       # 4-byte Spill
	mov	dword ptr [ebp - 32], edx       # 4-byte Spill
# %bb.101:
	call	__Query_perf_counter
# %bb.102:
	mov	ecx, dword ptr [ebp - 44]       # 4-byte Reload
	add	ecx, 4
	mov	dword ptr [ebp - 44], ecx       # 4-byte Spill
	push	dword ptr [ebp - 32]            # 4-byte Folded Reload
	mov	edi, dword ptr [ebp - 40]       # 4-byte Reload
	push	edi
	push	edx
	push	eax
	mov	dword ptr [ebp - 60], eax       # 4-byte Spill
	mov	dword ptr [ebp - 64], edx       # 4-byte Spill
	call	__alldiv
	mov	ebx, eax
	mov	ecx, 1000000000
	mov	esi, edx
	mul	ecx
	mov	ecx, ebx
	mov	dword ptr [ebp - 36], eax       # 4-byte Spill
	imul	eax, esi, 1000000000
	imul	ecx, dword ptr [ebp - 32]       # 4-byte Folded Reload
	imul	esi, edi
	add	eax, edx
	mov	dword ptr [ebp - 56], eax       # 4-byte Spill
	mov	eax, ebx
	mul	edi
	add	edx, ecx
	add	esi, edx
	mov	edx, dword ptr [ebp - 60]       # 4-byte Reload
	sub	edx, eax
	mov	eax, dword ptr [ebp - 64]       # 4-byte Reload
	sbb	eax, esi
	imul	ecx, eax, 1000000000
	mov	eax, edx
	mov	edx, 1000000000
	mul	edx
	add	edx, ecx
	push	dword ptr [ebp - 32]            # 4-byte Folded Reload
	push	edi
	push	edx
	push	eax
	call	__alldiv
	add	eax, dword ptr [ebp - 36]       # 4-byte Folded Reload
	mov	esi, dword ptr [ebp - 72]       # 4-byte Reload
	mov	ebx, dword ptr [ebp + 8]
	mov	edi, dword ptr [ebp + 12]
	adc	edx, dword ptr [ebp - 56]       # 4-byte Folded Reload
	mov	ecx, eax
	mov	dword ptr [ebp - 36], eax       # 4-byte Spill
	sub	ecx, dword ptr [ebp - 52]       # 4-byte Folded Reload
	mov	eax, edx
	sbb	eax, esi
	mov	dword ptr [ebp - 32], ecx       # 4-byte Spill
	mov	ecx, dword ptr [ebp - 48]       # 4-byte Reload
	mov	dword ptr [ebp - 40], eax       # 4-byte Spill
	mov	eax, dword ptr [ebp - 44]       # 4-byte Reload
	sub	ecx, dword ptr [edi + 24]
	sub	eax, dword ptr [edi + 4]
	#APP
	#reactor ret
	#NO_APP
	mov	dword ptr [ebx], 0
	movsd	xmm0, qword ptr [edi]           # xmm0 = mem[0],zero
	movsd	xmm1, qword ptr [edi + 8]       # xmm1 = mem[0],zero
	sar	ecx, 2
	sar	eax, 2
	movsd	qword ptr [ebx + 4], xmm0
	movsd	qword ptr [ebx + 12], xmm1
	movsd	xmm0, qword ptr [edi + 16]      # xmm0 = mem[0],zero
	movsd	qword ptr [ebx + 20], xmm0
	movsd	xmm0, qword ptr [edi + 24]      # xmm0 = mem[0],zero
	movsd	qword ptr [ebx + 28], xmm0
	mov	edi, dword ptr [edi + 32]
	mov	dword ptr [ebx + 36], edi
	mov	edi, dword ptr [ebp - 68]       # 4-byte Reload
	test	edi, edi
	sete	byte ptr [ebx + 40]
	mov	dword ptr [ebx + 52], esi
	mov	esi, dword ptr [ebp - 52]       # 4-byte Reload
	mov	dword ptr [ebx + 48], esi
	mov	esi, dword ptr [ebp - 36]       # 4-byte Reload
	mov	dword ptr [ebx + 60], edx
	mov	edx, dword ptr [ebp - 32]       # 4-byte Reload
	mov	dword ptr [ebx + 56], esi
	mov	esi, dword ptr [ebp - 40]       # 4-byte Reload
	mov	dword ptr [ebx + 64], edx
	mov	dword ptr [ebx + 68], esi
	mov	dword ptr [ebx + 72], edi
	mov	dword ptr [ebx + 76], eax
	mov	dword ptr [ebx + 80], ecx
	jmp	LBB1_103
	.p2align	4, 0x90
Ltmp9:                                  # Block address taken
LBB1_20:                                # =>This Inner Loop Header: Depth=1
	#APP
	#__intrin__
	#NO_APP
	mov	eax, dword ptr [ebx + 4]
	test	eax, eax
	jns	LBB1_21
# %bb.22:                               #   in Loop: Header=BB1_20 Depth=1
	add	ebx, 8
	mov	ecx, dword ptr [ebx]
	jmp	dword ptr [4*ecx + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
LBB1_21:                                #   in Loop: Header=BB1_20 Depth=1
	mov	ecx, dword ptr [ebp - 56]       # 4-byte Reload
	mov	eax, dword ptr [ecx + 4*eax]
	mov	dword ptr [ebp - 16], -1
	call	eax
	add	ebx, 8
	mov	ecx, dword ptr [ebx]
	jmp	dword ptr [4*ecx + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp10:                                 # Block address taken
LBB1_23:                                # =>This Inner Loop Header: Depth=1
	add	ebx, 4
	#APP
	#__call__
	#NO_APP
	mov	eax, dword ptr [ebx]
	jmp	dword ptr [4*eax + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp11:                                 # Block address taken
LBB1_24:                                # =>This Inner Loop Header: Depth=1
	add	ebx, 4
	#APP
	#__ret__
	#NO_APP
	mov	eax, dword ptr [ebx]
	jmp	dword ptr [4*eax + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp12:                                 # Block address taken
LBB1_25:                                # =>This Inner Loop Header: Depth=1
	#APP
	#__mov__
	#NO_APP
	mov	ecx, dword ptr [ebx + 8]
	mov	eax, dword ptr [ebx + 4]
	add	ebx, 12
	mov	ecx, dword ptr [esi + 4*ecx]
	mov	dword ptr [esi + 4*eax], ecx
	mov	eax, dword ptr [ebx]
	jmp	dword ptr [4*eax + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp13:                                 # Block address taken
LBB1_26:                                # =>This Inner Loop Header: Depth=1
	#APP
	#__sto__
	#NO_APP
	mov	eax, dword ptr [ebx + 4]
	mov	ecx, dword ptr [ebx + 8]
	add	ebx, 12
	mov	dword ptr [esi + 4*eax], ecx
	mov	eax, dword ptr [ebx]
	jmp	dword ptr [4*eax + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp14:                                 # Block address taken
LBB1_27:                                # =>This Inner Loop Header: Depth=1
	#APP
	#__push__
	#NO_APP
	mov	eax, dword ptr [ebx + 4]
	add	ebx, 8
	mov	dword ptr [esi + 4], eax
	add	esi, 4
	mov	eax, dword ptr [ebx]
	jmp	dword ptr [4*eax + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp15:                                 # Block address taken
LBB1_28:                                # =>This Inner Loop Header: Depth=1
	add	ebx, 4
	#APP
	#__pop__
	#NO_APP
	add	esi, -4
	mov	eax, dword ptr [ebx]
	jmp	dword ptr [4*eax + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp16:                                 # Block address taken
LBB1_29:                                # =>This Inner Loop Header: Depth=1
	add	ebx, 4
	#APP
	#__pop2__
	#NO_APP
	add	esi, -8
	mov	eax, dword ptr [ebx]
	jmp	dword ptr [4*eax + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp17:                                 # Block address taken
LBB1_30:                                # =>This Inner Loop Header: Depth=1
	#APP
	#__dupl__
	#NO_APP
	mov	eax, dword ptr [esi]
	add	ebx, 4
	mov	dword ptr [esi + 4], eax
	add	esi, 4
	mov	eax, dword ptr [ebx]
	jmp	dword ptr [4*eax + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp18:                                 # Block address taken
LBB1_31:                                # =>This Inner Loop Header: Depth=1
	#APP
	#__dupl2__
	#NO_APP
	mov	eax, dword ptr [esi]
	add	ebx, 4
	mov	dword ptr [esi + 4], eax
	mov	dword ptr [esi + 8], eax
	add	esi, 8
	mov	eax, dword ptr [ebx]
	jmp	dword ptr [4*eax + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp19:                                 # Block address taken
LBB1_32:                                # =>This Inner Loop Header: Depth=1
	add	ebx, 4
	#APP
	#__nop__
	#NO_APP
	mov	eax, dword ptr [ebx]
	jmp	dword ptr [4*eax + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp20:                                 # Block address taken
LBB1_33:                                # =>This Inner Loop Header: Depth=1
	#APP
	#__ipushz__
	#NO_APP
	mov	dword ptr [esi + 4], 0
	add	ebx, 4
	add	esi, 4
	mov	eax, dword ptr [ebx]
	jmp	dword ptr [4*eax + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp21:                                 # Block address taken
LBB1_34:                                # =>This Inner Loop Header: Depth=1
	#APP
	#__ipusho__
	#NO_APP
	mov	dword ptr [esi + 4], 1
	add	ebx, 4
	add	esi, 4
	mov	eax, dword ptr [ebx]
	jmp	dword ptr [4*eax + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp22:                                 # Block address taken
LBB1_35:                                # =>This Inner Loop Header: Depth=1
	#APP
	#__fpusho__
	#NO_APP
	mov	dword ptr [esi + 4], 1065353216
	add	ebx, 4
	add	esi, 4
	mov	eax, dword ptr [ebx]
	jmp	dword ptr [4*eax + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp23:                                 # Block address taken
LBB1_36:                                # =>This Inner Loop Header: Depth=1
	#APP
	#__iinc__
	#NO_APP
	inc	dword ptr [esi]
	add	ebx, 4
	mov	eax, dword ptr [ebx]
	jmp	dword ptr [4*eax + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp24:                                 # Block address taken
LBB1_37:                                # =>This Inner Loop Header: Depth=1
	#APP
	#__idec__
	#NO_APP
	dec	dword ptr [esi]
	add	ebx, 4
	mov	eax, dword ptr [ebx]
	jmp	dword ptr [4*eax + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp25:                                 # Block address taken
LBB1_38:                                # =>This Inner Loop Header: Depth=1
	#APP
	#__iadd__
	#NO_APP
	mov	eax, dword ptr [esi]
	add	ebx, 4
	add	dword ptr [esi - 4], eax
	add	esi, -4
	mov	ecx, dword ptr [ebx]
	jmp	dword ptr [4*ecx + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp26:                                 # Block address taken
LBB1_39:                                # =>This Inner Loop Header: Depth=1
	#APP
	#__isub__
	#NO_APP
	mov	eax, dword ptr [esi]
	add	ebx, 4
	sub	dword ptr [esi - 4], eax
	add	esi, -4
	mov	ecx, dword ptr [ebx]
	jmp	dword ptr [4*ecx + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp27:                                 # Block address taken
LBB1_40:                                # =>This Inner Loop Header: Depth=1
	#APP
	#__imul__
	#NO_APP
	mov	eax, dword ptr [esi - 4]
	add	ebx, 4
	imul	eax, dword ptr [esi]
	mov	dword ptr [esi - 4], eax
	add	esi, -4
	mov	ecx, dword ptr [ebx]
	jmp	dword ptr [4*ecx + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp28:                                 # Block address taken
LBB1_41:                                # =>This Inner Loop Header: Depth=1
	#APP
	#__idiv__
	#NO_APP
	mov	eax, dword ptr [esi - 4]
	add	ebx, 4
	cdq
	idiv	dword ptr [esi]
	mov	dword ptr [esi - 4], eax
	add	esi, -4
	mov	ecx, dword ptr [ebx]
	jmp	dword ptr [4*ecx + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp29:                                 # Block address taken
LBB1_42:                                # =>This Inner Loop Header: Depth=1
	#APP
	#__imod__
	#NO_APP
	mov	eax, dword ptr [esi - 4]
	add	ebx, 4
	cdq
	idiv	dword ptr [esi]
	mov	dword ptr [esi - 4], edx
	add	esi, -4
	mov	ecx, dword ptr [ebx]
	jmp	dword ptr [4*ecx + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp30:                                 # Block address taken
LBB1_43:                                # =>This Inner Loop Header: Depth=1
	#APP
	#__iand__
	#NO_APP
	mov	eax, dword ptr [esi]
	add	ebx, 4
	and	dword ptr [esi - 4], eax
	add	esi, -4
	mov	ecx, dword ptr [ebx]
	jmp	dword ptr [4*ecx + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp31:                                 # Block address taken
LBB1_44:                                # =>This Inner Loop Header: Depth=1
	#APP
	#__ior__
	#NO_APP
	mov	eax, dword ptr [esi]
	add	ebx, 4
	or	dword ptr [esi - 4], eax
	add	esi, -4
	mov	ecx, dword ptr [ebx]
	jmp	dword ptr [4*ecx + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp32:                                 # Block address taken
LBB1_45:                                # =>This Inner Loop Header: Depth=1
	#APP
	#__ixor__
	#NO_APP
	mov	eax, dword ptr [esi]
	add	ebx, 4
	xor	dword ptr [esi - 4], eax
	add	esi, -4
	mov	ecx, dword ptr [ebx]
	jmp	dword ptr [4*ecx + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp33:                                 # Block address taken
LBB1_46:                                # =>This Inner Loop Header: Depth=1
	#APP
	#__icom__
	#NO_APP
	not	dword ptr [esi]
	add	ebx, 4
	mov	eax, dword ptr [ebx]
	jmp	dword ptr [4*eax + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp34:                                 # Block address taken
LBB1_47:                                # =>This Inner Loop Header: Depth=1
	#APP
	#__isal__
	#NO_APP
	movzx	ecx, byte ptr [esi]
	add	ebx, 4
	shl	dword ptr [esi - 4], cl
	add	esi, -4
	mov	ecx, dword ptr [ebx]
	jmp	dword ptr [4*ecx + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp35:                                 # Block address taken
LBB1_48:                                # =>This Inner Loop Header: Depth=1
	#APP
	#__isar__
	#NO_APP
	movzx	ecx, byte ptr [esi]
	add	ebx, 4
	sar	dword ptr [esi - 4], cl
	add	esi, -4
	mov	ecx, dword ptr [ebx]
	jmp	dword ptr [4*ecx + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp36:                                 # Block address taken
LBB1_49:                                # =>This Inner Loop Header: Depth=1
	#APP
	#__irol__
	#NO_APP
	mov	ecx, dword ptr [esi]
	lea	eax, [esi - 4]
	mov	edx, dword ptr [esi - 4]
	lea	esi, [ecx + 31]
	test	ecx, ecx
	cmovns	esi, ecx
	and	esi, -32
	sub	ecx, esi
	test	ecx, ecx
	jle	LBB1_51
# %bb.50:                               #   in Loop: Header=BB1_49 Depth=1
                                        # kill: def $cl killed $cl killed $ecx
	rol	edx, cl
	add	ebx, 4
	mov	esi, eax
	mov	dword ptr [eax], edx
	mov	edx, dword ptr [ebx]
	jmp	dword ptr [4*edx + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
LBB1_51:                                #   in Loop: Header=BB1_49 Depth=1
	je	LBB1_53
# %bb.52:                               #   in Loop: Header=BB1_49 Depth=1
	add	cl, 32
                                        # kill: def $cl killed $cl killed $ecx
	rol	edx, cl
LBB1_53:                                #   in Loop: Header=BB1_49 Depth=1
	mov	dword ptr [eax], edx
	add	ebx, 4
	mov	esi, eax
	mov	edx, dword ptr [ebx]
	jmp	dword ptr [4*edx + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp37:                                 # Block address taken
LBB1_54:                                # =>This Inner Loop Header: Depth=1
	#APP
	#__iror__
	#NO_APP
	mov	ecx, dword ptr [esi]
	lea	eax, [esi - 4]
	mov	edx, dword ptr [esi - 4]
	lea	esi, [ecx + 31]
	test	ecx, ecx
	cmovns	esi, ecx
	and	esi, -32
	sub	ecx, esi
	test	ecx, ecx
	jle	LBB1_56
# %bb.55:                               #   in Loop: Header=BB1_54 Depth=1
                                        # kill: def $cl killed $cl killed $ecx
	ror	edx, cl
	add	ebx, 4
	mov	esi, eax
	mov	dword ptr [eax], edx
	mov	edx, dword ptr [ebx]
	jmp	dword ptr [4*edx + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
LBB1_56:                                #   in Loop: Header=BB1_54 Depth=1
	je	LBB1_58
# %bb.57:                               #   in Loop: Header=BB1_54 Depth=1
	add	cl, 32
                                        # kill: def $cl killed $cl killed $ecx
	ror	edx, cl
LBB1_58:                                #   in Loop: Header=BB1_54 Depth=1
	mov	dword ptr [eax], edx
	add	ebx, 4
	mov	esi, eax
	mov	edx, dword ptr [ebx]
	jmp	dword ptr [4*edx + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp38:                                 # Block address taken
LBB1_59:                                # =>This Inner Loop Header: Depth=1
	#APP
	#__ineg__
	#NO_APP
	neg	dword ptr [esi]
	add	ebx, 4
	mov	eax, dword ptr [ebx]
	jmp	dword ptr [4*eax + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp39:                                 # Block address taken
LBB1_60:                                # =>This Inner Loop Header: Depth=1
	#APP
	#__fadd__
	#NO_APP
	movss	xmm0, dword ptr [esi - 4]       # xmm0 = mem[0],zero,zero,zero
	add	ebx, 4
	addss	xmm0, dword ptr [esi]
	movss	dword ptr [esi - 4], xmm0
	add	esi, -4
	mov	ecx, dword ptr [ebx]
	jmp	dword ptr [4*ecx + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp40:                                 # Block address taken
LBB1_61:                                # =>This Inner Loop Header: Depth=1
	#APP
	#__fsub__
	#NO_APP
	movss	xmm0, dword ptr [esi - 4]       # xmm0 = mem[0],zero,zero,zero
	add	ebx, 4
	subss	xmm0, dword ptr [esi]
	movss	dword ptr [esi - 4], xmm0
	add	esi, -4
	mov	ecx, dword ptr [ebx]
	jmp	dword ptr [4*ecx + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp41:                                 # Block address taken
LBB1_62:                                # =>This Inner Loop Header: Depth=1
	#APP
	#__fmul__
	#NO_APP
	movss	xmm0, dword ptr [esi - 4]       # xmm0 = mem[0],zero,zero,zero
	add	ebx, 4
	mulss	xmm0, dword ptr [esi]
	movss	dword ptr [esi - 4], xmm0
	add	esi, -4
	mov	ecx, dword ptr [ebx]
	jmp	dword ptr [4*ecx + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp42:                                 # Block address taken
LBB1_63:                                # =>This Inner Loop Header: Depth=1
	#APP
	#__fdiv__
	#NO_APP
	movss	xmm0, dword ptr [esi - 4]       # xmm0 = mem[0],zero,zero,zero
	add	ebx, 4
	divss	xmm0, dword ptr [esi]
	movss	dword ptr [esi - 4], xmm0
	add	esi, -4
	mov	ecx, dword ptr [ebx]
	jmp	dword ptr [4*ecx + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp43:                                 # Block address taken
LBB1_64:                                # =>This Inner Loop Header: Depth=1
	#APP
	#__fmod__
	#NO_APP
	movss	xmm0, dword ptr [esi - 4]       # xmm0 = mem[0],zero,zero,zero
	movss	xmm1, dword ptr [esi]           # xmm1 = mem[0],zero,zero,zero
	lea	edi, [esi - 4]
	sub	esp, 16
	cvtss2sd	xmm1, xmm1
	cvtss2sd	xmm0, xmm0
	movsd	qword ptr [esp + 8], xmm1
	movsd	qword ptr [esp], xmm0
	call	_fmod
	add	esp, 16
	fstp	dword ptr [esi - 4]
	add	ebx, 4
	mov	esi, edi
	mov	eax, dword ptr [ebx]
	jmp	dword ptr [4*eax + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp44:                                 # Block address taken
LBB1_65:                                # =>This Inner Loop Header: Depth=1
	#APP
	#__fneg__
	#NO_APP
	movss	xmm0, dword ptr [esi]           # xmm0 = mem[0],zero,zero,zero
	add	ebx, 4
	xorps	xmm0, xmmword ptr [__xmm@80000000800000008000000080000000]
	movss	dword ptr [esi], xmm0
	mov	ecx, dword ptr [ebx]
	jmp	dword ptr [4*ecx + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp45:                                 # Block address taken
LBB1_66:                                # =>This Inner Loop Header: Depth=1
	#APP
	#__finc__
	#NO_APP
	movss	xmm0, dword ptr [esi]           # xmm0 = mem[0],zero,zero,zero
	add	ebx, 4
	addss	xmm0, dword ptr [__real@3f800000]
	movss	dword ptr [esi], xmm0
	mov	ecx, dword ptr [ebx]
	jmp	dword ptr [4*ecx + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp46:                                 # Block address taken
LBB1_67:                                # =>This Inner Loop Header: Depth=1
	#APP
	#__fdec__
	#NO_APP
	movss	xmm0, dword ptr [esi]           # xmm0 = mem[0],zero,zero,zero
	add	ebx, 4
	addss	xmm0, dword ptr [__real@bf800000]
	movss	dword ptr [esi], xmm0
	mov	ecx, dword ptr [ebx]
	jmp	dword ptr [4*ecx + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp47:                                 # Block address taken
LBB1_68:                                # =>This Inner Loop Header: Depth=1
	#APP
	#__jmp__
	#NO_APP
	mov	eax, dword ptr [ebx + 4]
	mov	ecx, dword ptr [ebp - 48]       # 4-byte Reload
	lea	ebx, [ecx + 4*eax]
	mov	ecx, dword ptr [ebx]
	jmp	dword ptr [4*ecx + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp48:                                 # Block address taken
LBB1_69:                                # =>This Inner Loop Header: Depth=1
	#APP
	#__jmprel__
	#NO_APP
	mov	ecx, dword ptr [ebx + 4]
	lea	ebx, [ebx + 4*ecx + 4]
	mov	ecx, dword ptr [ebx]
	jmp	dword ptr [4*ecx + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp49:                                 # Block address taken
LBB1_70:                                # =>This Inner Loop Header: Depth=1
	#APP
	#__jz__
	#NO_APP
	add	ebx, 4
	cmp	dword ptr [esi], 0
	je	LBB1_71
# %bb.72:                               #   in Loop: Header=BB1_70 Depth=1
	add	ebx, 4
	add	esi, -4
	mov	ecx, dword ptr [ebx]
	jmp	dword ptr [4*ecx + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
LBB1_71:                                #   in Loop: Header=BB1_70 Depth=1
	mov	eax, dword ptr [ebx]
	mov	ecx, dword ptr [ebp - 32]       # 4-byte Reload
	lea	ebx, [ecx + 4*eax]
	add	ebx, 4
	add	esi, -4
	mov	ecx, dword ptr [ebx]
	jmp	dword ptr [4*ecx + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp50:                                 # Block address taken
LBB1_73:                                # =>This Inner Loop Header: Depth=1
	#APP
	#__jnz__
	#NO_APP
	add	ebx, 4
	cmp	dword ptr [esi], 0
	je	LBB1_75
# %bb.74:                               #   in Loop: Header=BB1_73 Depth=1
	mov	eax, dword ptr [ebx]
	mov	ecx, dword ptr [ebp - 32]       # 4-byte Reload
	lea	ebx, [ecx + 4*eax]
LBB1_75:                                #   in Loop: Header=BB1_73 Depth=1
	add	ebx, 4
	add	esi, -4
	mov	ecx, dword ptr [ebx]
	jmp	dword ptr [4*ecx + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp51:                                 # Block address taken
LBB1_76:                                # =>This Inner Loop Header: Depth=1
	#APP
	#__jo_cmpi__
	#NO_APP
	add	ebx, 4
	cmp	dword ptr [esi], 1
	jne	LBB1_78
# %bb.77:                               #   in Loop: Header=BB1_76 Depth=1
	mov	eax, dword ptr [ebx]
	mov	ecx, dword ptr [ebp - 32]       # 4-byte Reload
	lea	ebx, [ecx + 4*eax]
LBB1_78:                                #   in Loop: Header=BB1_76 Depth=1
	add	ebx, 4
	add	esi, -4
	mov	ecx, dword ptr [ebx]
	jmp	dword ptr [4*ecx + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp52:                                 # Block address taken
LBB1_79:                                # =>This Inner Loop Header: Depth=1
	movss	xmm0, dword ptr [__real@3f800000] # xmm0 = mem[0],zero,zero,zero
	#APP
	#__jo_cmpf__
	#NO_APP
	add	ebx, 4
	ucomiss	xmm0, dword ptr [esi]
	jne	LBB1_81
# %bb.80:                               #   in Loop: Header=BB1_79 Depth=1
	mov	eax, dword ptr [ebx]
	mov	ecx, dword ptr [ebp - 32]       # 4-byte Reload
	lea	ebx, [ecx + 4*eax]
LBB1_81:                                #   in Loop: Header=BB1_79 Depth=1
	add	ebx, 4
	add	esi, -4
	mov	ecx, dword ptr [ebx]
	jmp	dword ptr [4*ecx + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp53:                                 # Block address taken
LBB1_82:                                # =>This Inner Loop Header: Depth=1
	#APP
	#__jno_cmpi__
	#NO_APP
	add	ebx, 4
	cmp	dword ptr [esi], 1
	je	LBB1_84
# %bb.83:                               #   in Loop: Header=BB1_82 Depth=1
	mov	eax, dword ptr [ebx]
	mov	ecx, dword ptr [ebp - 32]       # 4-byte Reload
	lea	ebx, [ecx + 4*eax]
LBB1_84:                                #   in Loop: Header=BB1_82 Depth=1
	add	ebx, 4
	add	esi, -4
	mov	ecx, dword ptr [ebx]
	jmp	dword ptr [4*ecx + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp54:                                 # Block address taken
LBB1_85:                                # =>This Inner Loop Header: Depth=1
	movss	xmm0, dword ptr [__real@3f800000] # xmm0 = mem[0],zero,zero,zero
	#APP
	#__jno_cmpf__
	#NO_APP
	add	ebx, 4
	ucomiss	xmm0, dword ptr [esi]
	je	LBB1_87
# %bb.86:                               #   in Loop: Header=BB1_85 Depth=1
	mov	eax, dword ptr [ebx]
	mov	ecx, dword ptr [ebp - 32]       # 4-byte Reload
	lea	ebx, [ecx + 4*eax]
LBB1_87:                                #   in Loop: Header=BB1_85 Depth=1
	add	ebx, 4
	add	esi, -4
	mov	ecx, dword ptr [ebx]
	jmp	dword ptr [4*ecx + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp55:                                 # Block address taken
LBB1_88:                                # =>This Inner Loop Header: Depth=1
	#APP
	#__je_cmpi__
	#NO_APP
	mov	ecx, dword ptr [esi - 4]
	add	ebx, 4
	cmp	ecx, dword ptr [esi]
	jne	LBB1_90
# %bb.89:                               #   in Loop: Header=BB1_88 Depth=1
	mov	eax, dword ptr [ebx]
	mov	ecx, dword ptr [ebp - 32]       # 4-byte Reload
	lea	ebx, [ecx + 4*eax]
LBB1_90:                                #   in Loop: Header=BB1_88 Depth=1
	add	ebx, 4
	add	esi, -8
	mov	ecx, dword ptr [ebx]
	jmp	dword ptr [4*ecx + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp56:                                 # Block address taken
LBB1_91:                                # =>This Inner Loop Header: Depth=1
	#APP
	#__je_cmpf__
	#NO_APP
	movss	xmm0, dword ptr [esi - 4]       # xmm0 = mem[0],zero,zero,zero
	add	ebx, 4
	ucomiss	xmm0, dword ptr [esi]
	jne	LBB1_93
# %bb.92:                               #   in Loop: Header=BB1_91 Depth=1
	mov	eax, dword ptr [ebx]
	mov	ecx, dword ptr [ebp - 32]       # 4-byte Reload
	lea	ebx, [ecx + 4*eax]
LBB1_93:                                #   in Loop: Header=BB1_91 Depth=1
	add	ebx, 4
	add	esi, -8
	mov	ecx, dword ptr [ebx]
	jmp	dword ptr [4*ecx + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp57:                                 # Block address taken
LBB1_94:                                # =>This Inner Loop Header: Depth=1
	#APP
	#__jne_cmpi__
	#NO_APP
	mov	ecx, dword ptr [esi - 4]
	add	ebx, 4
	cmp	ecx, dword ptr [esi]
	je	LBB1_96
# %bb.95:                               #   in Loop: Header=BB1_94 Depth=1
	mov	eax, dword ptr [ebx]
	mov	ecx, dword ptr [ebp - 32]       # 4-byte Reload
	lea	ebx, [ecx + 4*eax]
LBB1_96:                                #   in Loop: Header=BB1_94 Depth=1
	add	ebx, 4
	add	esi, -8
	mov	ecx, dword ptr [ebx]
	jmp	dword ptr [4*ecx + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.p2align	4, 0x90
Ltmp58:                                 # Block address taken
LBB1_97:                                # =>This Inner Loop Header: Depth=1
	#APP
	#__jne_cmpf__
	#NO_APP
	movss	xmm0, dword ptr [esi - 4]       # xmm0 = mem[0],zero,zero,zero
	add	ebx, 4
	ucomiss	xmm0, dword ptr [esi]
	je	LBB1_99
# %bb.98:                               #   in Loop: Header=BB1_97 Depth=1
	mov	eax, dword ptr [ebx]
	mov	ecx, dword ptr [ebp - 32]       # 4-byte Reload
	lea	ebx, [ecx + 4*eax]
LBB1_99:                                #   in Loop: Header=BB1_97 Depth=1
	add	ebx, 4
	add	esi, -8
	mov	ecx, dword ptr [ebx]
	jmp	dword ptr [4*ecx + "?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"]
	.def	 "?dtor$104@?0??execute_reactor@nominax@@YA?AUreactor_output@1@ABUreactor_input@1@@Z@4HA";
	.scl	3;
	.type	32;
	.endef
	.p2align	4, 0x90
"?dtor$104@?0??execute_reactor@nominax@@YA?AUreactor_output@1@ABUreactor_input@1@@Z@4HA":
LBB1_104:
	push	ebp
	sub	esp, 16
	add	ebp, 12
	call	___std_terminate
	.def	 "?dtor$105@?0??execute_reactor@nominax@@YA?AUreactor_output@1@ABUreactor_input@1@@Z@4HA";
	.scl	3;
	.type	32;
	.endef
	.p2align	4, 0x90
"?dtor$105@?0??execute_reactor@nominax@@YA?AUreactor_output@1@ABUreactor_input@1@@Z@4HA":
LBB1_105:
	push	ebp
	sub	esp, 16
	add	ebp, 12
	call	___std_terminate
Lfunc_end0:
	.section	.xdata,"dr"
	.p2align	2
"L__ehtable$?execute_reactor@nominax@@YA?AUreactor_output@1@ABUreactor_input@1@@Z":
	.long	429065506                       # MagicNumber
	.long	2                               # MaxState
	.long	("$stateUnwindMap$?execute_reactor@nominax@@YA?AUreactor_output@1@ABUreactor_input@1@@Z") # UnwindMap
	.long	0                               # NumTryBlocks
	.long	0                               # TryBlockMap
	.long	0                               # IPMapEntries
	.long	0                               # IPToStateXData
	.long	0                               # ESTypeList
	.long	1                               # EHFlags
"$stateUnwindMap$?execute_reactor@nominax@@YA?AUreactor_output@1@ABUreactor_input@1@@Z":
	.long	-1                              # ToState
	.long	"?dtor$104@?0??execute_reactor@nominax@@YA?AUreactor_output@1@ABUreactor_input@1@@Z@4HA" # Action
	.long	-1                              # ToState
	.long	"?dtor$105@?0??execute_reactor@nominax@@YA?AUreactor_output@1@ABUreactor_input@1@@Z@4HA" # Action
	.text
                                        # -- End function
	.def	 "___ehhandler$?execute_reactor@nominax@@YA?AUreactor_output@1@ABUreactor_input@1@@Z";
	.scl	3;
	.type	32;
	.endef
	.p2align	4, 0x90                         # -- Begin function __ehhandler$?execute_reactor@nominax@@YA?AUreactor_output@1@ABUreactor_input@1@@Z
"___ehhandler$?execute_reactor@nominax@@YA?AUreactor_output@1@ABUreactor_input@1@@Z": # @"__ehhandler$?execute_reactor@nominax@@YA?AUreactor_output@1@ABUreactor_input@1@@Z"
# %bb.0:
	mov	eax, offset "L__ehtable$?execute_reactor@nominax@@YA?AUreactor_output@1@ABUreactor_input@1@@Z"
	jmp	___CxxFrameHandler3             # TAILCALL
                                        # -- End function
	.section	.rdata,"dr"
	.p2align	2                               # @"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB"
"?bt@?1??execute_reactor@nominax@@YA?AUreactor_output@2@ABUreactor_input@2@@Z@4QBQIBXB":
	.long	Ltmp8
	.long	Ltmp9
	.long	Ltmp10
	.long	Ltmp11
	.long	Ltmp12
	.long	Ltmp13
	.long	Ltmp14
	.long	Ltmp15
	.long	Ltmp16
	.long	Ltmp17
	.long	Ltmp18
	.long	Ltmp19
	.long	Ltmp20
	.long	Ltmp21
	.long	Ltmp22
	.long	Ltmp23
	.long	Ltmp24
	.long	Ltmp25
	.long	Ltmp26
	.long	Ltmp27
	.long	Ltmp28
	.long	Ltmp29
	.long	Ltmp30
	.long	Ltmp31
	.long	Ltmp32
	.long	Ltmp33
	.long	Ltmp34
	.long	Ltmp35
	.long	Ltmp36
	.long	Ltmp37
	.long	Ltmp38
	.long	Ltmp39
	.long	Ltmp40
	.long	Ltmp41
	.long	Ltmp42
	.long	Ltmp43
	.long	Ltmp44
	.long	Ltmp45
	.long	Ltmp46
	.long	Ltmp47
	.long	Ltmp48
	.long	Ltmp49
	.long	Ltmp50
	.long	Ltmp51
	.long	Ltmp52
	.long	Ltmp53
	.long	Ltmp54
	.long	Ltmp55
	.long	Ltmp56
	.long	Ltmp57
	.long	Ltmp58

	.section	.drectve,"yn"
	.ascii	" /FAILIFMISMATCH:\"_CRT_STDIO_ISO_WIDE_SPECIFIERS=0\""
	.ascii	" /FAILIFMISMATCH:\"_MSC_VER=1900\""
	.ascii	" /FAILIFMISMATCH:\"_ITERATOR_DEBUG_LEVEL=0\""
	.ascii	" /FAILIFMISMATCH:\"RuntimeLibrary=MT_StaticRelease\""
	.ascii	" /DEFAULTLIB:libcpmt.lib"
	.safeseh	"___ehhandler$?execute_reactor@nominax@@YA?AUreactor_output@1@ABUreactor_input@1@@Z"
	.addrsig
	.addrsig_sym "?execute_reactor@nominax@@YA?AUreactor_output@1@ABUreactor_input@1@@Z"
	.addrsig_sym ___CxxFrameHandler3
	.addrsig_sym "___ehhandler$?execute_reactor@nominax@@YA?AUreactor_output@1@ABUreactor_input@1@@Z"
	.globl	__fltused
