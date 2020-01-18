	.file	"main.cpp"
	.text
	.section	.text$_Z6printfPKcz,"x"
	.linkonce discard
	.globl	_Z6printfPKcz
	.def	_Z6printfPKcz;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z6printfPKcz
_Z6printfPKcz:
.LFB8:
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	.seh_endprologue
	movq	%rcx, %rsi
	movq	%rdx, 88(%rsp)
	movq	%r8, 96(%rsp)
	movq	%r9, 104(%rsp)
	leaq	88(%rsp), %rbx
	movq	%rbx, 40(%rsp)
	movl	$1, %ecx
	call	*__imp___acrt_iob_func(%rip)
	movq	%rbx, %r8
	movq	%rsi, %rdx
	movq	%rax, %rcx
	call	__mingw_vfprintf
	addq	$56, %rsp
	popq	%rbx
	popq	%rsi
	ret
	.seh_endproc
	.text
	.globl	_Z1xii
	.def	_Z1xii;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z1xii
_Z1xii:
.LFB73:
	.seh_endprologue
	leal	(%rcx,%rdx), %eax
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "%d %d %d\0"
.LC1:
	.ascii "pause\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB74:
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	call	__main
	movl	f(%rip), %edx
	addl	e(%rip), %edx
	movl	$0, %r9d
	movl	%edx, %r8d
	leaq	.LC0(%rip), %rcx
	call	_Z6printfPKcz
	leaq	.LC1(%rip), %rcx
	call	system
	movl	$0, %eax
	addq	$40, %rsp
	ret
	.seh_endproc
	.globl	f
	.data
	.align 4
f:
	.long	2
	.globl	e
	.align 4
e:
	.long	1
	.ident	"GCC: (x86_64-win32-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	__mingw_vfprintf;	.scl	2;	.type	32;	.endef
	.def	system;	.scl	2;	.type	32;	.endef
