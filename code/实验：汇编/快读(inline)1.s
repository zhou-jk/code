	.file	"\277\354\266\301(inline).cpp"
	.text
	.section	.text$_Z6printfPKcz,"x"
	.linkonce discard
	.globl	_Z6printfPKcz
	.def	_Z6printfPKcz;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z6printfPKcz
_Z6printfPKcz:
.LFB8:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movq	%rcx, -48(%rbp)
	movq	%rdx, -40(%rbp)
	movq	%r8, -32(%rbp)
	movq	%r9, -24(%rbp)
	leaq	-40(%rbp), %rax
	movq	%rax, -96(%rbp)
	movq	-96(%rbp), %rbx
	movl	$1, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
	movq	%rbx, %r8
	movq	-48(%rbp), %rdx
	movq	%rax, %rcx
	call	__mingw_vfprintf
	movl	%eax, -84(%rbp)
	movl	-84(%rbp), %eax
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 4
_ZL4maxn:
	.long	131072
	.globl	buffer
	.bss
	.align 32
buffer:
	.space 131072
	.globl	S
	.align 8
S:
	.space 8
	.globl	T
	.align 8
T:
	.space 8
	.section	.text$_Z8Get_Charv,"x"
	.linkonce discard
	.globl	_Z8Get_Charv
	.def	_Z8Get_Charv;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z8Get_Charv
_Z8Get_Charv:
.LFB44:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movq	S(%rip), %rdx
	movq	T(%rip), %rax
	cmpq	%rax, %rdx
	jne	.L4
	leaq	buffer(%rip), %rax
	movq	%rax, S(%rip)
	movq	S(%rip), %rbx
	movl	$0, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
	movq	%rax, %r9
	movl	$131072, %r8d
	movl	$1, %edx
	leaq	buffer(%rip), %rcx
	call	fread
	addq	%rbx, %rax
	movq	%rax, T(%rip)
	movq	S(%rip), %rdx
	movq	T(%rip), %rax
	cmpq	%rax, %rdx
	jne	.L4
	movl	$-1, %eax
	jmp	.L5
.L4:
	movq	S(%rip), %rax
	leaq	1(%rax), %rdx
	movq	%rdx, S(%rip)
	movzbl	(%rax), %eax
.L5:
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_Z7Get_Intv,"x"
	.linkonce discard
	.globl	_Z7Get_Intv
	.def	_Z7Get_Intv;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z7Get_Intv
_Z7Get_Intv:
.LFB45:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movl	$0, -8(%rbp)
	call	_Z8Get_Charv
	movb	%al, -1(%rbp)
.L9:
	cmpb	$47, -1(%rbp)
	jle	.L7
	cmpb	$57, -1(%rbp)
	jle	.L8
.L7:
	call	_Z8Get_Charv
	movb	%al, -1(%rbp)
	jmp	.L9
.L8:
	cmpb	$47, -1(%rbp)
	jle	.L10
	cmpb	$57, -1(%rbp)
	jg	.L10
	movl	-8(%rbp), %eax
	leal	(%rax,%rax), %edx
	movl	-8(%rbp), %eax
	sall	$3, %eax
	addl	%eax, %edx
	movsbl	-1(%rbp), %eax
	subl	$48, %eax
	addl	%edx, %eax
	movl	%eax, -8(%rbp)
	call	_Z8Get_Charv
	movb	%al, -1(%rbp)
	jmp	.L8
.L10:
	movl	-8(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "%d\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB46:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	call	__main
	call	_Z7Get_Intv
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC0(%rip), %rcx
	call	_Z6printfPKcz
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-win32-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	__mingw_vfprintf;	.scl	2;	.type	32;	.endef
	.def	fread;	.scl	2;	.type	32;	.endef
