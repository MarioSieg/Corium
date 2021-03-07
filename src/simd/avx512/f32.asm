	.text
	.def	 @feat.00;
	.scl	3;
	.type	0;
	.endef
	.globl	@feat.00
.set @feat.00, 0
	.intel_syntax noprefix
	.file	"f32.c"
	.def	 main;
	.scl	2;
	.type	32;
	.endef
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
main:                                   # @main
.seh_proc main
# %bb.0:
	sub	rsp, 184
	.seh_stackalloc 184
	.seh_endprologue
	lea	rax, [rsp + 96]
	lea	r8, [rsp + 32]
	mov	dword ptr [rsp + 180], 0
	mov	qword ptr [rsp + 168], rdx
	mov	dword ptr [rsp + 164], ecx
	mov	rcx, rax
	mov	rdx, r8
	call	__add16
	lea	rcx, [rsp + 96]
	lea	rdx, [rsp + 32]
	call	__sub16
	lea	rcx, [rsp + 96]
	lea	rdx, [rsp + 32]
	call	__mul16
	lea	rcx, [rsp + 96]
	lea	rdx, [rsp + 32]
	call	__div16
	xor	eax, eax
	add	rsp, 184
	ret
	.seh_handlerdata
	.text
	.seh_endproc
                                        # -- End function
	.def	 __add16;
	.scl	3;
	.type	32;
	.endef
	.p2align	4, 0x90         # -- Begin function __add16
__add16:                                # @__add16
.seh_proc __add16
# %bb.0:
	push	rbp
	.seh_pushreg rbp
	sub	rsp, 496
	.seh_stackalloc 496
	lea	rbp, [rsp + 128]
	.seh_setframe rbp, 128
	.seh_endprologue
	and	rsp, -64
	mov	qword ptr [rsp + 232], rdx
	mov	qword ptr [rsp + 224], rcx
	mov	rax, qword ptr [rsp + 224]
	mov	qword ptr [rsp + 240], rax
	mov	rax, qword ptr [rsp + 240]
	vmovups	zmm0, zmmword ptr [rax]
	vmovaps	zmmword ptr [rsp + 128], zmm0
	mov	rax, qword ptr [rsp + 232]
	mov	qword ptr [rsp + 488], rax
	mov	rax, qword ptr [rsp + 488]
	vmovups	zmm0, zmmword ptr [rax]
	vmovaps	zmmword ptr [rsp + 64], zmm0
	vmovaps	zmm0, zmmword ptr [rsp + 64]
	vmovaps	zmm1, zmmword ptr [rsp + 128]
	vmovaps	zmmword ptr [rsp + 384], zmm0
	vmovaps	zmmword ptr [rsp + 320], zmm1
	vmovaps	zmm0, zmmword ptr [rsp + 320]
	vaddps	zmm0, zmm0, zmmword ptr [rsp + 384]
	vmovaps	zmmword ptr [rsp], zmm0
	vmovaps	zmm0, zmmword ptr [rsp]
	mov	rax, qword ptr [rsp + 224]
	vmovdqa64	zmmword ptr [rsp + 256], zmm0
	mov	qword ptr [rsp + 248], rax
	vmovdqa64	zmm0, zmmword ptr [rsp + 256]
	mov	rax, qword ptr [rsp + 248]
	vmovdqu64	zmmword ptr [rax], zmm0
	lea	rsp, [rbp + 368]
	pop	rbp
	vzeroupper
	ret
	.seh_handlerdata
	.text
	.seh_endproc
                                        # -- End function
	.def	 __sub16;
	.scl	3;
	.type	32;
	.endef
	.p2align	4, 0x90         # -- Begin function __sub16
__sub16:                                # @__sub16
.seh_proc __sub16
# %bb.0:
	push	rbp
	.seh_pushreg rbp
	sub	rsp, 496
	.seh_stackalloc 496
	lea	rbp, [rsp + 128]
	.seh_setframe rbp, 128
	.seh_endprologue
	and	rsp, -64
	mov	qword ptr [rsp + 232], rdx
	mov	qword ptr [rsp + 224], rcx
	mov	rax, qword ptr [rsp + 224]
	mov	qword ptr [rsp + 240], rax
	mov	rax, qword ptr [rsp + 240]
	vmovups	zmm0, zmmword ptr [rax]
	vmovaps	zmmword ptr [rsp + 128], zmm0
	mov	rax, qword ptr [rsp + 232]
	mov	qword ptr [rsp + 488], rax
	mov	rax, qword ptr [rsp + 488]
	vmovups	zmm0, zmmword ptr [rax]
	vmovaps	zmmword ptr [rsp + 64], zmm0
	vmovaps	zmm0, zmmword ptr [rsp + 64]
	vmovaps	zmm1, zmmword ptr [rsp + 128]
	vmovaps	zmmword ptr [rsp + 384], zmm0
	vmovaps	zmmword ptr [rsp + 320], zmm1
	vmovaps	zmm0, zmmword ptr [rsp + 320]
	vsubps	zmm0, zmm0, zmmword ptr [rsp + 384]
	vmovaps	zmmword ptr [rsp], zmm0
	vmovaps	zmm0, zmmword ptr [rsp]
	mov	rax, qword ptr [rsp + 224]
	vmovdqa64	zmmword ptr [rsp + 256], zmm0
	mov	qword ptr [rsp + 248], rax
	vmovdqa64	zmm0, zmmword ptr [rsp + 256]
	mov	rax, qword ptr [rsp + 248]
	vmovdqu64	zmmword ptr [rax], zmm0
	lea	rsp, [rbp + 368]
	pop	rbp
	vzeroupper
	ret
	.seh_handlerdata
	.text
	.seh_endproc
                                        # -- End function
	.def	 __mul16;
	.scl	3;
	.type	32;
	.endef
	.p2align	4, 0x90         # -- Begin function __mul16
__mul16:                                # @__mul16
.seh_proc __mul16
# %bb.0:
	push	rbp
	.seh_pushreg rbp
	sub	rsp, 496
	.seh_stackalloc 496
	lea	rbp, [rsp + 128]
	.seh_setframe rbp, 128
	.seh_endprologue
	and	rsp, -64
	mov	qword ptr [rsp + 232], rdx
	mov	qword ptr [rsp + 224], rcx
	mov	rax, qword ptr [rsp + 224]
	mov	qword ptr [rsp + 240], rax
	mov	rax, qword ptr [rsp + 240]
	vmovups	zmm0, zmmword ptr [rax]
	vmovaps	zmmword ptr [rsp + 128], zmm0
	mov	rax, qword ptr [rsp + 232]
	mov	qword ptr [rsp + 488], rax
	mov	rax, qword ptr [rsp + 488]
	vmovups	zmm0, zmmword ptr [rax]
	vmovaps	zmmword ptr [rsp + 64], zmm0
	vmovaps	zmm0, zmmword ptr [rsp + 64]
	vmovaps	zmm1, zmmword ptr [rsp + 128]
	vmovaps	zmmword ptr [rsp + 384], zmm0
	vmovaps	zmmword ptr [rsp + 320], zmm1
	vmovaps	zmm0, zmmword ptr [rsp + 320]
	vmulps	zmm0, zmm0, zmmword ptr [rsp + 384]
	vmovaps	zmmword ptr [rsp], zmm0
	vmovaps	zmm0, zmmword ptr [rsp]
	mov	rax, qword ptr [rsp + 224]
	vmovdqa64	zmmword ptr [rsp + 256], zmm0
	mov	qword ptr [rsp + 248], rax
	vmovdqa64	zmm0, zmmword ptr [rsp + 256]
	mov	rax, qword ptr [rsp + 248]
	vmovdqu64	zmmword ptr [rax], zmm0
	lea	rsp, [rbp + 368]
	pop	rbp
	vzeroupper
	ret
	.seh_handlerdata
	.text
	.seh_endproc
                                        # -- End function
	.def	 __div16;
	.scl	3;
	.type	32;
	.endef
	.p2align	4, 0x90         # -- Begin function __div16
__div16:                                # @__div16
.seh_proc __div16
# %bb.0:
	push	rbp
	.seh_pushreg rbp
	sub	rsp, 496
	.seh_stackalloc 496
	lea	rbp, [rsp + 128]
	.seh_setframe rbp, 128
	.seh_endprologue
	and	rsp, -64
	mov	qword ptr [rsp + 232], rdx
	mov	qword ptr [rsp + 224], rcx
	mov	rax, qword ptr [rsp + 224]
	mov	qword ptr [rsp + 240], rax
	mov	rax, qword ptr [rsp + 240]
	vmovups	zmm0, zmmword ptr [rax]
	vmovaps	zmmword ptr [rsp + 128], zmm0
	mov	rax, qword ptr [rsp + 232]
	mov	qword ptr [rsp + 488], rax
	mov	rax, qword ptr [rsp + 488]
	vmovups	zmm0, zmmword ptr [rax]
	vmovaps	zmmword ptr [rsp + 64], zmm0
	vmovaps	zmm0, zmmword ptr [rsp + 64]
	vmovaps	zmm1, zmmword ptr [rsp + 128]
	vmovaps	zmmword ptr [rsp + 384], zmm0
	vmovaps	zmmword ptr [rsp + 320], zmm1
	vmovaps	zmm0, zmmword ptr [rsp + 320]
	vdivps	zmm0, zmm0, zmmword ptr [rsp + 384]
	vmovaps	zmmword ptr [rsp], zmm0
	vmovaps	zmm0, zmmword ptr [rsp]
	mov	rax, qword ptr [rsp + 224]
	vmovdqa64	zmmword ptr [rsp + 256], zmm0
	mov	qword ptr [rsp + 248], rax
	vmovdqa64	zmm0, zmmword ptr [rsp + 256]
	mov	rax, qword ptr [rsp + 248]
	vmovdqu64	zmmword ptr [rax], zmm0
	lea	rsp, [rbp + 368]
	pop	rbp
	vzeroupper
	ret
	.seh_handlerdata
	.text
	.seh_endproc
                                        # -- End function
	.addrsig
	.addrsig_sym __add16
	.addrsig_sym __sub16
	.addrsig_sym __mul16
	.addrsig_sym __div16
	.globl	_fltused
