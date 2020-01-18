	.file	"tria.cpp"
	.text
.Ltext0:
	.cfi_sections	.debug_frame
	.section	.text$_Z5scanfPKcz,"x"
	.linkonce discard
	.globl	_Z5scanfPKcz
	.def	_Z5scanfPKcz;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5scanfPKcz
_Z5scanfPKcz:
.LFB2:
	.file 1 "C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include/stdio.h"
	.loc 1 279 1
	.cfi_startproc
	pushq	%rbp
	.seh_pushreg	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.seh_pushreg	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$56, %rsp
	.seh_stackalloc	56
	.cfi_def_cfa_offset 80
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.cfi_def_cfa 6, -48
	.seh_endprologue
	movq	%rcx, -48(%rbp)
	movq	%rdx, -40(%rbp)
	movq	%r8, -32(%rbp)
	movq	%r9, -24(%rbp)
	.loc 1 281 53
	leaq	-40(%rbp), %rax
	movq	%rax, -96(%rbp)
	.loc 1 282 29
	movq	-96(%rbp), %rbx
	movl	$0, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
.LVL0:
	movq	%rbx, %r8
	movq	-48(%rbp), %rdx
	movq	%rax, %rcx
	call	__mingw_vfscanf
	movl	%eax, -84(%rbp)
	.loc 1 284 10
	movl	-84(%rbp), %eax
	.loc 1 285 1
	addq	$56, %rsp
	popq	%rbx
	.cfi_restore 3
	popq	%rbp
	.cfi_restore 6
	.cfi_def_cfa 7, -40
	ret
	.cfi_endproc
.LFE2:
	.seh_endproc
	.section	.text$_Z6printfPKcz,"x"
	.linkonce discard
	.globl	_Z6printfPKcz
	.def	_Z6printfPKcz;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z6printfPKcz
_Z6printfPKcz:
.LFB8:
	.loc 1 346 1
	.cfi_startproc
	pushq	%rbp
	.seh_pushreg	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.seh_pushreg	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$56, %rsp
	.seh_stackalloc	56
	.cfi_def_cfa_offset 80
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.cfi_def_cfa 6, -48
	.seh_endprologue
	movq	%rcx, -48(%rbp)
	movq	%rdx, -40(%rbp)
	movq	%r8, -32(%rbp)
	movq	%r9, -24(%rbp)
	.loc 1 348 53
	leaq	-40(%rbp), %rax
	movq	%rax, -96(%rbp)
	.loc 1 349 30
	movq	-96(%rbp), %rbx
	movl	$1, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
.LVL1:
	movq	%rbx, %r8
	movq	-48(%rbp), %rdx
	movq	%rax, %rcx
	call	__mingw_vfprintf
	movl	%eax, -84(%rbp)
	.loc 1 351 10
	movl	-84(%rbp), %eax
	.loc 1 352 1
	addq	$56, %rsp
	popq	%rbx
	.cfi_restore 3
	popq	%rbp
	.cfi_restore 6
	.cfi_def_cfa 7, -40
	ret
	.cfi_endproc
.LFE8:
	.seh_endproc
	.section .rdata,"dr"
	.align 4
_ZL1N:
	.long	22
	.globl	f
	.bss
	.align 32
f:
	.space 1936
	.globl	s
	.align 32
s:
	.space 92
	.globl	n
	.align 4
n:
	.space 4
	.globl	ans
	.align 4
ans:
	.space 4
	.text
	.globl	_Z3dfsi
	.def	_Z3dfsi;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z3dfsi
_Z3dfsi:
.LFB44:
	.file 2 "../code/C++/\310\375\275\307\320\316/tria.cpp"
	.loc 2 7 1
	.cfi_startproc
	pushq	%rbp
	.seh_pushreg	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movl	%ecx, 16(%rbp)
.LBB2:
	.loc 2 8 8
	movl	n(%rip), %eax
	.loc 2 8 2
	cmpl	%eax, 16(%rbp)
	jne	.L6
.LBB3:
	.loc 2 10 7
	movl	$0, -4(%rbp)
.LBB4:
	.loc 2 11 12
	movl	$0, -8(%rbp)
.L10:
	.loc 2 11 21 discriminator 7
	movl	n(%rip), %eax
	cmpl	%eax, -8(%rbp)
	jge	.L7
	.loc 2 11 44 discriminator 2
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	f(%rip), %rax
	movl	(%rdx,%rax), %eax
	.loc 2 11 46 discriminator 2
	testl	%eax, %eax
	je	.L8
	.loc 2 11 46 is_stmt 0 discriminator 3
	movl	$1, %eax
	jmp	.L9
.L8:
	.loc 2 11 46 discriminator 4
	movl	$-1, %eax
.L9:
	.loc 2 11 35 is_stmt 1 discriminator 6
	addl	%eax, -4(%rbp)
	.loc 2 11 3 discriminator 6
	addl	$1, -8(%rbp)
	jmp	.L10
.L7:
.LBE4:
	.loc 2 12 17
	movl	n(%rip), %eax
	subl	$1, %eax
	.loc 2 12 20
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	s(%rip), %rax
	movl	(%rdx,%rax), %eax
	.loc 2 12 3
	cmpl	%eax, -4(%rbp)
	jg	.L22
	.loc 2 12 36 discriminator 2
	movl	n(%rip), %eax
	subl	$1, %eax
	.loc 2 12 39 discriminator 2
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	s(%rip), %rax
	movl	(%rdx,%rax), %eax
	.loc 2 12 31 discriminator 2
	negl	%eax
	.loc 2 12 22 discriminator 2
	cmpl	%eax, -4(%rbp)
	jl	.L22
.LBB5:
	.loc 2 13 12
	movl	$1, -12(%rbp)
.L21:
	.loc 2 13 21 discriminator 1
	movl	n(%rip), %eax
	cmpl	%eax, -12(%rbp)
	jge	.L14
.LBB6:
.LBB7:
	.loc 2 15 13
	movl	$0, -16(%rbp)
.L18:
	.loc 2 15 26 discriminator 2
	movl	n(%rip), %eax
	subl	-12(%rbp), %eax
	.loc 2 15 22 discriminator 2
	cmpl	%eax, -16(%rbp)
	jge	.L15
	.loc 2 17 19
	movl	-12(%rbp), %eax
	leal	-1(%rax), %edx
	.loc 2 17 25
	movl	-16(%rbp), %eax
	cltq
	movslq	%edx, %rdx
	imulq	$22, %rdx, %rdx
	addq	%rdx, %rax
	leaq	0(,%rax,4), %rdx
	leaq	f(%rip), %rax
	movl	(%rdx,%rax), %ecx
	.loc 2 17 33
	movl	-12(%rbp), %eax
	leal	-1(%rax), %edx
	.loc 2 17 40
	movl	-16(%rbp), %eax
	addl	$1, %eax
	.loc 2 17 43
	cltq
	movslq	%edx, %rdx
	imulq	$22, %rdx, %rdx
	addq	%rdx, %rax
	leaq	0(,%rax,4), %rdx
	leaq	f(%rip), %rax
	movl	(%rdx,%rax), %eax
	.loc 2 17 27
	xorl	%eax, %ecx
	.loc 2 17 13
	movl	-16(%rbp), %eax
	cltq
	movl	-12(%rbp), %edx
	movslq	%edx, %rdx
	imulq	$22, %rdx, %rdx
	addq	%rdx, %rax
	leaq	0(,%rax,4), %rdx
	leaq	f(%rip), %rax
	movl	%ecx, (%rdx,%rax)
	.loc 2 18 18
	movl	-16(%rbp), %eax
	cltq
	movl	-12(%rbp), %edx
	movslq	%edx, %rdx
	imulq	$22, %rdx, %rdx
	addq	%rdx, %rax
	leaq	0(,%rax,4), %rdx
	leaq	f(%rip), %rax
	movl	(%rdx,%rax), %eax
	.loc 2 18 20
	testl	%eax, %eax
	je	.L16
	.loc 2 18 20 is_stmt 0 discriminator 1
	movl	$1, %eax
	jmp	.L17
.L16:
	.loc 2 18 20 discriminator 2
	movl	$-1, %eax
.L17:
	.loc 2 18 9 is_stmt 1 discriminator 4
	addl	%eax, -4(%rbp)
	.loc 2 15 4 discriminator 4
	addl	$1, -16(%rbp)
	jmp	.L18
.L15:
.LBE7:
	.loc 2 20 18
	movl	n(%rip), %eax
	subl	$1, %eax
	.loc 2 20 22
	subl	-12(%rbp), %eax
	.loc 2 20 25
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	s(%rip), %rax
	movl	(%rdx,%rax), %eax
	.loc 2 20 4
	cmpl	%eax, -4(%rbp)
	jg	.L23
	.loc 2 20 41 discriminator 2
	movl	n(%rip), %eax
	subl	$1, %eax
	.loc 2 20 45 discriminator 2
	subl	-12(%rbp), %eax
	.loc 2 20 48 discriminator 2
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	s(%rip), %rax
	movl	(%rdx,%rax), %eax
	.loc 2 20 36 discriminator 2
	negl	%eax
	.loc 2 20 27 discriminator 2
	cmpl	%eax, -4(%rbp)
	jl	.L23
.LBE6:
	.loc 2 13 3 discriminator 2
	addl	$1, -12(%rbp)
	jmp	.L21
.L14:
.LBE5:
	.loc 2 22 3
	movl	ans(%rip), %eax
	addl	$1, %eax
	movl	%eax, ans(%rip)
	.loc 2 23 3
	jmp	.L5
.L6:
.LBE3:
.LBE2:
	.loc 2 25 10
	movl	16(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	f(%rip), %rax
	movl	$0, (%rdx,%rax)
	.loc 2 26 5
	movl	16(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %ecx
	call	_Z3dfsi
	.loc 2 27 10
	movl	16(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	f(%rip), %rax
	movl	$1, (%rdx,%rax)
	.loc 2 28 5
	movl	16(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %ecx
	call	_Z3dfsi
	jmp	.L5
.L22:
.LBB11:
.LBB10:
	.loc 2 12 42
	nop
	jmp	.L5
.L23:
.LBB9:
.LBB8:
	.loc 2 20 51
	nop
.L5:
.LBE8:
.LBE9:
.LBE10:
.LBE11:
	.loc 2 29 1
	addq	$48, %rsp
	popq	%rbp
	.cfi_restore 6
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE44:
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "r\0"
.LC1:
	.ascii "tria.in\0"
.LC2:
	.ascii "w\0"
.LC3:
	.ascii "tria.out\0"
.LC4:
	.ascii "%d\0"
.LC5:
	.ascii "0\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB45:
	.loc 2 32 1
	.cfi_startproc
	pushq	%rbp
	.seh_pushreg	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	.loc 2 32 1
	call	__main
.LVL2:
	.loc 2 33 9
	movl	$0, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
.LVL3:
	movq	%rax, %r8
	leaq	.LC0(%rip), %rdx
	leaq	.LC1(%rip), %rcx
	call	freopen
	.loc 2 34 9
	movl	$1, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
.LVL4:
	movq	%rax, %r8
	leaq	.LC2(%rip), %rdx
	leaq	.LC3(%rip), %rcx
	call	freopen
	.loc 2 35 7
	leaq	n(%rip), %rdx
	leaq	.LC4(%rip), %rcx
	call	_Z5scanfPKcz
	.loc 2 36 10
	movl	n(%rip), %eax
	leal	1(%rax), %edx
	.loc 2 36 15
	movl	n(%rip), %eax
	imull	%edx, %eax
	.loc 2 36 28
	andl	$2, %eax
	.loc 2 36 2
	testl	%eax, %eax
	je	.L25
	.loc 2 38 7
	leaq	.LC5(%rip), %rcx
	call	puts
	.loc 2 39 10
	movl	$0, %eax
	jmp	.L26
.L25:
.LBB12:
	.loc 2 41 11
	movl	$0, -4(%rbp)
.L28:
	.loc 2 41 20 discriminator 3
	movl	n(%rip), %eax
	cmpl	%eax, -4(%rbp)
	jge	.L27
	.loc 2 41 45 discriminator 2
	movl	-4(%rbp), %eax
	addl	$1, %eax
	.loc 2 41 40 discriminator 2
	imull	-4(%rbp), %eax
	.loc 2 41 51 discriminator 2
	sarl	%eax
	movl	%eax, %ecx
	.loc 2 41 35 discriminator 2
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	s(%rip), %rax
	movl	%ecx, (%rdx,%rax)
	.loc 2 41 2 discriminator 2
	addl	$1, -4(%rbp)
	jmp	.L28
.L27:
.LBE12:
	.loc 2 42 5
	movl	$0, %ecx
	call	_Z3dfsi
	.loc 2 43 8
	movl	ans(%rip), %eax
	movl	%eax, %edx
	leaq	.LC4(%rip), %rcx
	call	_Z6printfPKcz
	.loc 2 44 9
	movl	$0, %eax
.L26:
	.loc 2 45 1
	addq	$48, %rsp
	popq	%rbp
	.cfi_restore 6
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE45:
	.seh_endproc
.Letext0:
	.file 3 "C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/cstdio"
	.file 4 "C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/x86_64-w64-mingw32/bits/c++config.h"
	.file 5 "C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include/crtdefs.h"
	.file 6 "<built-in>"
	.section	.debug_info,"dr"
.Ldebug_info0:
	.long	0xbca
	.word	0x4
	.secrel32	.Ldebug_abbrev0
	.byte	0x8
	.uleb128 0x1
	.ascii "GNU C++98 8.1.0 -mtune=core2 -march=nocona -g -std=gnu++98\0"
	.byte	0x4
	.ascii "../code/C++/\310\375\275\307\320\316/tria.cpp\0"
	.ascii "E:\\OI-Files\0"
	.secrel32	.Ldebug_ranges0+0x60
	.quad	0
	.secrel32	.Ldebug_line0
	.uleb128 0x2
	.ascii "std\0"
	.byte	0x6
	.byte	0
	.long	0x1f2
	.uleb128 0x3
	.ascii "__cxx11\0"
	.byte	0x4
	.word	0x104
	.byte	0x41
	.uleb128 0x4
	.byte	0x4
	.word	0x104
	.byte	0x41
	.long	0x8b
	.uleb128 0x5
	.byte	0x3
	.byte	0x62
	.byte	0xb
	.long	0x3a8
	.uleb128 0x5
	.byte	0x3
	.byte	0x63
	.byte	0xb
	.long	0x3b5
	.uleb128 0x5
	.byte	0x3
	.byte	0x65
	.byte	0xb
	.long	0x3c9
	.uleb128 0x5
	.byte	0x3
	.byte	0x66
	.byte	0xb
	.long	0x3e7
	.uleb128 0x5
	.byte	0x3
	.byte	0x67
	.byte	0xb
	.long	0x401
	.uleb128 0x5
	.byte	0x3
	.byte	0x68
	.byte	0xb
	.long	0x419
	.uleb128 0x5
	.byte	0x3
	.byte	0x69
	.byte	0xb
	.long	0x433
	.uleb128 0x5
	.byte	0x3
	.byte	0x6a
	.byte	0xb
	.long	0x44d
	.uleb128 0x5
	.byte	0x3
	.byte	0x6b
	.byte	0xb
	.long	0x466
	.uleb128 0x5
	.byte	0x3
	.byte	0x6c
	.byte	0xb
	.long	0x48c
	.uleb128 0x5
	.byte	0x3
	.byte	0x6d
	.byte	0xb
	.long	0x4af
	.uleb128 0x5
	.byte	0x3
	.byte	0x6e
	.byte	0xb
	.long	0x4d3
	.uleb128 0x5
	.byte	0x3
	.byte	0x71
	.byte	0xb
	.long	0x50b
	.uleb128 0x5
	.byte	0x3
	.byte	0x72
	.byte	0xb
	.long	0x535
	.uleb128 0x5
	.byte	0x3
	.byte	0x73
	.byte	0xb
	.long	0x55a
	.uleb128 0x5
	.byte	0x3
	.byte	0x74
	.byte	0xb
	.long	0x590
	.uleb128 0x5
	.byte	0x3
	.byte	0x75
	.byte	0xb
	.long	0x5b3
	.uleb128 0x5
	.byte	0x3
	.byte	0x76
	.byte	0xb
	.long	0x5d9
	.uleb128 0x5
	.byte	0x3
	.byte	0x78
	.byte	0xb
	.long	0x5f2
	.uleb128 0x5
	.byte	0x3
	.byte	0x79
	.byte	0xb
	.long	0x60a
	.uleb128 0x5
	.byte	0x3
	.byte	0x7c
	.byte	0xb
	.long	0x61b
	.uleb128 0x5
	.byte	0x3
	.byte	0x7e
	.byte	0xb
	.long	0x633
	.uleb128 0x5
	.byte	0x3
	.byte	0x7f
	.byte	0xb
	.long	0x649
	.uleb128 0x5
	.byte	0x3
	.byte	0x83
	.byte	0xb
	.long	0x6bd
	.uleb128 0x5
	.byte	0x3
	.byte	0x84
	.byte	0xb
	.long	0x6d7
	.uleb128 0x5
	.byte	0x3
	.byte	0x85
	.byte	0xb
	.long	0x6f6
	.uleb128 0x5
	.byte	0x3
	.byte	0x86
	.byte	0xb
	.long	0x70c
	.uleb128 0x5
	.byte	0x3
	.byte	0x87
	.byte	0xb
	.long	0x77e
	.uleb128 0x5
	.byte	0x3
	.byte	0x88
	.byte	0xb
	.long	0x799
	.uleb128 0x5
	.byte	0x3
	.byte	0x89
	.byte	0xb
	.long	0x7c3
	.uleb128 0x5
	.byte	0x3
	.byte	0x8a
	.byte	0xb
	.long	0x7f5
	.uleb128 0x5
	.byte	0x3
	.byte	0x8b
	.byte	0xb
	.long	0x826
	.uleb128 0x5
	.byte	0x3
	.byte	0x8d
	.byte	0xb
	.long	0x837
	.uleb128 0x5
	.byte	0x3
	.byte	0x8f
	.byte	0xb
	.long	0x851
	.uleb128 0x5
	.byte	0x3
	.byte	0x90
	.byte	0xb
	.long	0x870
	.uleb128 0x5
	.byte	0x3
	.byte	0x91
	.byte	0xb
	.long	0x8af
	.uleb128 0x5
	.byte	0x3
	.byte	0x92
	.byte	0xb
	.long	0x8df
	.uleb128 0x5
	.byte	0x3
	.byte	0xb9
	.byte	0x16
	.long	0x918
	.uleb128 0x5
	.byte	0x3
	.byte	0xba
	.byte	0x16
	.long	0x952
	.uleb128 0x5
	.byte	0x3
	.byte	0xbb
	.byte	0x16
	.long	0x98f
	.uleb128 0x5
	.byte	0x3
	.byte	0xbc
	.byte	0x16
	.long	0x9bd
	.uleb128 0x5
	.byte	0x3
	.byte	0xbd
	.byte	0x16
	.long	0x9fe
	.byte	0
	.uleb128 0x6
	.ascii "__gnu_cxx\0"
	.byte	0x4
	.word	0x106
	.byte	0xb
	.long	0x244
	.uleb128 0x3
	.ascii "__cxx11\0"
	.byte	0x4
	.word	0x108
	.byte	0x41
	.uleb128 0x4
	.byte	0x4
	.word	0x108
	.byte	0x41
	.long	0x205
	.uleb128 0x5
	.byte	0x3
	.byte	0xaf
	.byte	0xb
	.long	0x918
	.uleb128 0x5
	.byte	0x3
	.byte	0xb0
	.byte	0xb
	.long	0x952
	.uleb128 0x5
	.byte	0x3
	.byte	0xb1
	.byte	0xb
	.long	0x98f
	.uleb128 0x5
	.byte	0x3
	.byte	0xb2
	.byte	0xb
	.long	0x9bd
	.uleb128 0x5
	.byte	0x3
	.byte	0xb3
	.byte	0xb
	.long	0x9fe
	.byte	0
	.uleb128 0x7
	.byte	0x8
	.ascii "__builtin_va_list\0"
	.long	0x25c
	.uleb128 0x8
	.byte	0x1
	.byte	0x6
	.ascii "char\0"
	.uleb128 0x9
	.long	0x25c
	.uleb128 0xa
	.ascii "size_t\0"
	.byte	0x5
	.byte	0x23
	.byte	0x2c
	.long	0x278
	.uleb128 0x8
	.byte	0x8
	.byte	0x7
	.ascii "long long unsigned int\0"
	.uleb128 0x8
	.byte	0x8
	.byte	0x5
	.ascii "long long int\0"
	.uleb128 0x8
	.byte	0x2
	.byte	0x7
	.ascii "short unsigned int\0"
	.uleb128 0x8
	.byte	0x4
	.byte	0x5
	.ascii "int\0"
	.uleb128 0x9
	.long	0x2b9
	.uleb128 0x8
	.byte	0x4
	.byte	0x5
	.ascii "long int\0"
	.uleb128 0xb
	.byte	0x8
	.long	0x25c
	.uleb128 0x8
	.byte	0x2
	.byte	0x7
	.ascii "wchar_t\0"
	.uleb128 0x8
	.byte	0x4
	.byte	0x7
	.ascii "unsigned int\0"
	.uleb128 0x8
	.byte	0x4
	.byte	0x7
	.ascii "long unsigned int\0"
	.uleb128 0x8
	.byte	0x1
	.byte	0x8
	.ascii "unsigned char\0"
	.uleb128 0xc
	.ascii "_iobuf\0"
	.byte	0x30
	.byte	0x1
	.byte	0x1a
	.byte	0xa
	.long	0x3a8
	.uleb128 0xd
	.ascii "_ptr\0"
	.byte	0x1
	.byte	0x1b
	.byte	0xb
	.long	0x2d1
	.byte	0
	.uleb128 0xd
	.ascii "_cnt\0"
	.byte	0x1
	.byte	0x1c
	.byte	0x9
	.long	0x2b9
	.byte	0x8
	.uleb128 0xd
	.ascii "_base\0"
	.byte	0x1
	.byte	0x1d
	.byte	0xb
	.long	0x2d1
	.byte	0x10
	.uleb128 0xd
	.ascii "_flag\0"
	.byte	0x1
	.byte	0x1e
	.byte	0x9
	.long	0x2b9
	.byte	0x18
	.uleb128 0xd
	.ascii "_file\0"
	.byte	0x1
	.byte	0x1f
	.byte	0x9
	.long	0x2b9
	.byte	0x1c
	.uleb128 0xd
	.ascii "_charbuf\0"
	.byte	0x1
	.byte	0x20
	.byte	0x9
	.long	0x2b9
	.byte	0x20
	.uleb128 0xd
	.ascii "_bufsiz\0"
	.byte	0x1
	.byte	0x21
	.byte	0x9
	.long	0x2b9
	.byte	0x24
	.uleb128 0xd
	.ascii "_tmpfname\0"
	.byte	0x1
	.byte	0x22
	.byte	0xb
	.long	0x2d1
	.byte	0x28
	.byte	0
	.uleb128 0xa
	.ascii "FILE\0"
	.byte	0x1
	.byte	0x24
	.byte	0x19
	.long	0x318
	.uleb128 0xa
	.ascii "fpos_t\0"
	.byte	0x1
	.byte	0x68
	.byte	0x25
	.long	0x292
	.uleb128 0x9
	.long	0x3b5
	.uleb128 0xe
	.ascii "clearerr\0"
	.byte	0x1
	.word	0x242
	.byte	0x10
	.long	0x3e1
	.uleb128 0xf
	.long	0x3e1
	.byte	0
	.uleb128 0xb
	.byte	0x8
	.long	0x3a8
	.uleb128 0x10
	.ascii "fclose\0"
	.byte	0x1
	.word	0x243
	.byte	0xf
	.long	0x2b9
	.long	0x401
	.uleb128 0xf
	.long	0x3e1
	.byte	0
	.uleb128 0x10
	.ascii "feof\0"
	.byte	0x1
	.word	0x24a
	.byte	0xf
	.long	0x2b9
	.long	0x419
	.uleb128 0xf
	.long	0x3e1
	.byte	0
	.uleb128 0x10
	.ascii "ferror\0"
	.byte	0x1
	.word	0x24b
	.byte	0xf
	.long	0x2b9
	.long	0x433
	.uleb128 0xf
	.long	0x3e1
	.byte	0
	.uleb128 0x10
	.ascii "fflush\0"
	.byte	0x1
	.word	0x24c
	.byte	0xf
	.long	0x2b9
	.long	0x44d
	.uleb128 0xf
	.long	0x3e1
	.byte	0
	.uleb128 0x10
	.ascii "fgetc\0"
	.byte	0x1
	.word	0x24d
	.byte	0xf
	.long	0x2b9
	.long	0x466
	.uleb128 0xf
	.long	0x3e1
	.byte	0
	.uleb128 0x10
	.ascii "fgetpos\0"
	.byte	0x1
	.word	0x24f
	.byte	0xf
	.long	0x2b9
	.long	0x486
	.uleb128 0xf
	.long	0x3e1
	.uleb128 0xf
	.long	0x486
	.byte	0
	.uleb128 0xb
	.byte	0x8
	.long	0x3b5
	.uleb128 0x10
	.ascii "fgets\0"
	.byte	0x1
	.word	0x251
	.byte	0x11
	.long	0x2d1
	.long	0x4af
	.uleb128 0xf
	.long	0x2d1
	.uleb128 0xf
	.long	0x2b9
	.uleb128 0xf
	.long	0x3e1
	.byte	0
	.uleb128 0x10
	.ascii "fopen\0"
	.byte	0x1
	.word	0x258
	.byte	0x11
	.long	0x3e1
	.long	0x4cd
	.uleb128 0xf
	.long	0x4cd
	.uleb128 0xf
	.long	0x4cd
	.byte	0
	.uleb128 0xb
	.byte	0x8
	.long	0x264
	.uleb128 0x11
	.ascii "fprintf\0"
	.byte	0x1
	.word	0x14e
	.byte	0x5
	.ascii "_Z7fprintfP6_iobufPKcz\0"
	.long	0x2b9
	.long	0x50b
	.uleb128 0xf
	.long	0x3e1
	.uleb128 0xf
	.long	0x4cd
	.uleb128 0x12
	.byte	0
	.uleb128 0x10
	.ascii "fread\0"
	.byte	0x1
	.word	0x25d
	.byte	0x12
	.long	0x269
	.long	0x533
	.uleb128 0xf
	.long	0x533
	.uleb128 0xf
	.long	0x269
	.uleb128 0xf
	.long	0x269
	.uleb128 0xf
	.long	0x3e1
	.byte	0
	.uleb128 0x13
	.byte	0x8
	.uleb128 0x10
	.ascii "freopen\0"
	.byte	0x1
	.word	0x25e
	.byte	0x11
	.long	0x3e1
	.long	0x55a
	.uleb128 0xf
	.long	0x4cd
	.uleb128 0xf
	.long	0x4cd
	.uleb128 0xf
	.long	0x3e1
	.byte	0
	.uleb128 0x11
	.ascii "fscanf\0"
	.byte	0x1
	.word	0x121
	.byte	0x5
	.ascii "_Z6fscanfP6_iobufPKcz\0"
	.long	0x2b9
	.long	0x590
	.uleb128 0xf
	.long	0x3e1
	.uleb128 0xf
	.long	0x4cd
	.uleb128 0x12
	.byte	0
	.uleb128 0x10
	.ascii "fseek\0"
	.byte	0x1
	.word	0x261
	.byte	0xf
	.long	0x2b9
	.long	0x5b3
	.uleb128 0xf
	.long	0x3e1
	.uleb128 0xf
	.long	0x2c5
	.uleb128 0xf
	.long	0x2b9
	.byte	0
	.uleb128 0x10
	.ascii "fsetpos\0"
	.byte	0x1
	.word	0x25f
	.byte	0xf
	.long	0x2b9
	.long	0x5d3
	.uleb128 0xf
	.long	0x3e1
	.uleb128 0xf
	.long	0x5d3
	.byte	0
	.uleb128 0xb
	.byte	0x8
	.long	0x3c4
	.uleb128 0x10
	.ascii "ftell\0"
	.byte	0x1
	.word	0x262
	.byte	0x10
	.long	0x2c5
	.long	0x5f2
	.uleb128 0xf
	.long	0x3e1
	.byte	0
	.uleb128 0x10
	.ascii "getc\0"
	.byte	0x1
	.word	0x28f
	.byte	0xf
	.long	0x2b9
	.long	0x60a
	.uleb128 0xf
	.long	0x3e1
	.byte	0
	.uleb128 0x14
	.ascii "getchar\0"
	.byte	0x1
	.word	0x290
	.byte	0xf
	.long	0x2b9
	.uleb128 0x10
	.ascii "gets\0"
	.byte	0x1
	.word	0x292
	.byte	0x11
	.long	0x2d1
	.long	0x633
	.uleb128 0xf
	.long	0x2d1
	.byte	0
	.uleb128 0xe
	.ascii "perror\0"
	.byte	0x1
	.word	0x296
	.byte	0x10
	.long	0x649
	.uleb128 0xf
	.long	0x4cd
	.byte	0
	.uleb128 0x15
	.ascii "printf\0"
	.byte	0x1
	.word	0x159
	.byte	0x5
	.ascii "_Z6printfPKcz\0"
	.long	0x2b9
	.quad	.LFB8
	.quad	.LFE8-.LFB8
	.uleb128 0x1
	.byte	0x9c
	.long	0x6bd
	.uleb128 0x12
	.uleb128 0x16
	.secrel32	.LASF2
	.byte	0x1
	.word	0x159
	.byte	0x19
	.long	0x4cd
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x12
	.uleb128 0x17
	.secrel32	.LASF0
	.byte	0x1
	.word	0x15b
	.byte	0x7
	.long	0x2b9
	.uleb128 0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0x17
	.secrel32	.LASF1
	.byte	0x1
	.word	0x15c
	.byte	0x15
	.long	0x244
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x18
	.quad	.LVL1
	.long	0xbc1
	.byte	0
	.uleb128 0x10
	.ascii "remove\0"
	.byte	0x1
	.word	0x2a4
	.byte	0xf
	.long	0x2b9
	.long	0x6d7
	.uleb128 0xf
	.long	0x4cd
	.byte	0
	.uleb128 0x10
	.ascii "rename\0"
	.byte	0x1
	.word	0x2a5
	.byte	0xf
	.long	0x2b9
	.long	0x6f6
	.uleb128 0xf
	.long	0x4cd
	.uleb128 0xf
	.long	0x4cd
	.byte	0
	.uleb128 0xe
	.ascii "rewind\0"
	.byte	0x1
	.word	0x2ab
	.byte	0x10
	.long	0x70c
	.uleb128 0xf
	.long	0x3e1
	.byte	0
	.uleb128 0x15
	.ascii "scanf\0"
	.byte	0x1
	.word	0x116
	.byte	0x5
	.ascii "_Z5scanfPKcz\0"
	.long	0x2b9
	.quad	.LFB2
	.quad	.LFE2-.LFB2
	.uleb128 0x1
	.byte	0x9c
	.long	0x77e
	.uleb128 0x12
	.uleb128 0x16
	.secrel32	.LASF2
	.byte	0x1
	.word	0x116
	.byte	0x17
	.long	0x4cd
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x12
	.uleb128 0x17
	.secrel32	.LASF0
	.byte	0x1
	.word	0x118
	.byte	0x7
	.long	0x2b9
	.uleb128 0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0x17
	.secrel32	.LASF1
	.byte	0x1
	.word	0x119
	.byte	0x15
	.long	0x244
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x18
	.quad	.LVL0
	.long	0xbc1
	.byte	0
	.uleb128 0xe
	.ascii "setbuf\0"
	.byte	0x1
	.word	0x2ad
	.byte	0x10
	.long	0x799
	.uleb128 0xf
	.long	0x3e1
	.uleb128 0xf
	.long	0x2d1
	.byte	0
	.uleb128 0x10
	.ascii "setvbuf\0"
	.byte	0x1
	.word	0x2b1
	.byte	0xf
	.long	0x2b9
	.long	0x7c3
	.uleb128 0xf
	.long	0x3e1
	.uleb128 0xf
	.long	0x2d1
	.uleb128 0xf
	.long	0x2b9
	.uleb128 0xf
	.long	0x269
	.byte	0
	.uleb128 0x11
	.ascii "sprintf\0"
	.byte	0x1
	.word	0x164
	.byte	0x5
	.ascii "_Z7sprintfPcPKcz\0"
	.long	0x2b9
	.long	0x7f5
	.uleb128 0xf
	.long	0x2d1
	.uleb128 0xf
	.long	0x4cd
	.uleb128 0x12
	.byte	0
	.uleb128 0x11
	.ascii "sscanf\0"
	.byte	0x1
	.word	0x10b
	.byte	0x5
	.ascii "_Z6sscanfPKcS0_z\0"
	.long	0x2b9
	.long	0x826
	.uleb128 0xf
	.long	0x4cd
	.uleb128 0xf
	.long	0x4cd
	.uleb128 0x12
	.byte	0
	.uleb128 0x14
	.ascii "tmpfile\0"
	.byte	0x1
	.word	0x2cb
	.byte	0x11
	.long	0x3e1
	.uleb128 0x10
	.ascii "tmpnam\0"
	.byte	0x1
	.word	0x2cc
	.byte	0x11
	.long	0x2d1
	.long	0x851
	.uleb128 0xf
	.long	0x2d1
	.byte	0
	.uleb128 0x10
	.ascii "ungetc\0"
	.byte	0x1
	.word	0x2cd
	.byte	0xf
	.long	0x2b9
	.long	0x870
	.uleb128 0xf
	.long	0x2b9
	.uleb128 0xf
	.long	0x3e1
	.byte	0
	.uleb128 0x11
	.ascii "vfprintf\0"
	.byte	0x1
	.word	0x16f
	.byte	0x5
	.ascii "_Z8vfprintfP6_iobufPKcPc\0"
	.long	0x2b9
	.long	0x8af
	.uleb128 0xf
	.long	0x3e1
	.uleb128 0xf
	.long	0x4cd
	.uleb128 0xf
	.long	0x244
	.byte	0
	.uleb128 0x11
	.ascii "vprintf\0"
	.byte	0x1
	.word	0x176
	.byte	0x5
	.ascii "_Z7vprintfPKcPc\0"
	.long	0x2b9
	.long	0x8df
	.uleb128 0xf
	.long	0x4cd
	.uleb128 0xf
	.long	0x244
	.byte	0
	.uleb128 0x11
	.ascii "vsprintf\0"
	.byte	0x1
	.word	0x17d
	.byte	0x5
	.ascii "_Z8vsprintfPcPKcS_\0"
	.long	0x2b9
	.long	0x918
	.uleb128 0xf
	.long	0x2d1
	.uleb128 0xf
	.long	0x4cd
	.uleb128 0xf
	.long	0x244
	.byte	0
	.uleb128 0x11
	.ascii "snprintf\0"
	.byte	0x1
	.word	0x184
	.byte	0x5
	.ascii "_Z8snprintfPcyPKcz\0"
	.long	0x2b9
	.long	0x952
	.uleb128 0xf
	.long	0x2d1
	.uleb128 0xf
	.long	0x269
	.uleb128 0xf
	.long	0x4cd
	.uleb128 0x12
	.byte	0
	.uleb128 0x11
	.ascii "vfscanf\0"
	.byte	0x1
	.word	0x140
	.byte	0x5
	.ascii "_Z7vfscanfP6_iobufPKcPc\0"
	.long	0x2b9
	.long	0x98f
	.uleb128 0xf
	.long	0x3e1
	.uleb128 0xf
	.long	0x4cd
	.uleb128 0xf
	.long	0x244
	.byte	0
	.uleb128 0x11
	.ascii "vscanf\0"
	.byte	0x1
	.word	0x139
	.byte	0x5
	.ascii "_Z6vscanfPKcPc\0"
	.long	0x2b9
	.long	0x9bd
	.uleb128 0xf
	.long	0x4cd
	.uleb128 0xf
	.long	0x244
	.byte	0
	.uleb128 0x11
	.ascii "vsnprintf\0"
	.byte	0x1
	.word	0x18f
	.byte	0x5
	.ascii "_Z9vsnprintfPcyPKcS_\0"
	.long	0x2b9
	.long	0x9fe
	.uleb128 0xf
	.long	0x2d1
	.uleb128 0xf
	.long	0x269
	.uleb128 0xf
	.long	0x4cd
	.uleb128 0xf
	.long	0x244
	.byte	0
	.uleb128 0x11
	.ascii "vsscanf\0"
	.byte	0x1
	.word	0x132
	.byte	0x5
	.ascii "_Z7vsscanfPKcS0_Pc\0"
	.long	0x2b9
	.long	0xa36
	.uleb128 0xf
	.long	0x4cd
	.uleb128 0xf
	.long	0x4cd
	.uleb128 0xf
	.long	0x244
	.byte	0
	.uleb128 0x19
	.ascii "N\0"
	.byte	0x2
	.byte	0x3
	.byte	0xb
	.long	0x2c0
	.uleb128 0x9
	.byte	0x3
	.quad	_ZL1N
	.uleb128 0x1a
	.long	0x2b9
	.long	0xa60
	.uleb128 0x1b
	.long	0x278
	.byte	0x15
	.uleb128 0x1b
	.long	0x278
	.byte	0x15
	.byte	0
	.uleb128 0x1c
	.ascii "f\0"
	.byte	0x2
	.byte	0x4
	.byte	0x5
	.long	0xa4a
	.uleb128 0x9
	.byte	0x3
	.quad	f
	.uleb128 0x1a
	.long	0x2b9
	.long	0xa84
	.uleb128 0x1b
	.long	0x278
	.byte	0x16
	.byte	0
	.uleb128 0x1c
	.ascii "s\0"
	.byte	0x2
	.byte	0x4
	.byte	0xe
	.long	0xa74
	.uleb128 0x9
	.byte	0x3
	.quad	s
	.uleb128 0x1c
	.ascii "n\0"
	.byte	0x2
	.byte	0x4
	.byte	0x18
	.long	0x2b9
	.uleb128 0x9
	.byte	0x3
	.quad	n
	.uleb128 0x1c
	.ascii "ans\0"
	.byte	0x2
	.byte	0x4
	.byte	0x1b
	.long	0x2b9
	.uleb128 0x9
	.byte	0x3
	.quad	ans
	.uleb128 0x1d
	.ascii "main\0"
	.byte	0x2
	.byte	0x1f
	.byte	0x5
	.long	0x2b9
	.quad	.LFB45
	.quad	.LFE45-.LFB45
	.uleb128 0x1
	.byte	0x9c
	.long	0xb23
	.uleb128 0x1e
	.quad	.LBB12
	.quad	.LBE12-.LBB12
	.long	0xb08
	.uleb128 0x19
	.ascii "i\0"
	.byte	0x2
	.byte	0x29
	.byte	0xb
	.long	0x2b9
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.byte	0
	.uleb128 0x18
	.quad	.LVL3
	.long	0xbc1
	.uleb128 0x18
	.quad	.LVL4
	.long	0xbc1
	.byte	0
	.uleb128 0x1f
	.ascii "dfs\0"
	.byte	0x2
	.byte	0x6
	.byte	0x6
	.ascii "_Z3dfsi\0"
	.quad	.LFB44
	.quad	.LFE44-.LFB44
	.uleb128 0x1
	.byte	0x9c
	.long	0xbc1
	.uleb128 0x20
	.ascii "k\0"
	.byte	0x2
	.byte	0x6
	.byte	0xe
	.long	0x2b9
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x21
	.secrel32	.Ldebug_ranges0+0
	.uleb128 0x19
	.ascii "tmp\0"
	.byte	0x2
	.byte	0xa
	.byte	0x7
	.long	0x2b9
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x1e
	.quad	.LBB4
	.quad	.LBE4-.LBB4
	.long	0xb8d
	.uleb128 0x19
	.ascii "j\0"
	.byte	0x2
	.byte	0xb
	.byte	0xc
	.long	0x2b9
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
	.uleb128 0x21
	.secrel32	.Ldebug_ranges0+0x30
	.uleb128 0x19
	.ascii "i\0"
	.byte	0x2
	.byte	0xd
	.byte	0xc
	.long	0x2b9
	.uleb128 0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0x22
	.quad	.LBB7
	.quad	.LBE7-.LBB7
	.uleb128 0x19
	.ascii "j\0"
	.byte	0x2
	.byte	0xf
	.byte	0xd
	.long	0x2b9
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x23
	.secrel32	.LASF3
	.secrel32	.LASF3
	.byte	0x1
	.byte	0x52
	.byte	0x17
	.byte	0
	.section	.debug_abbrev,"dr"
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0x8
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x1b
	.uleb128 0x8
	.uleb128 0x55
	.uleb128 0x17
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x39
	.byte	0x1
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x39
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x89
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x3a
	.byte	0
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x18
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x8
	.byte	0
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x18
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x39
	.byte	0x1
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x26
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x5
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x11
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x6e
	.uleb128 0x8
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x12
	.uleb128 0x18
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x13
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x14
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x15
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x6e
	.uleb128 0x8
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x16
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x17
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x18
	.uleb128 0x4109
	.byte	0
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x31
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x19
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x1a
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1b
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x1c
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x1d
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1e
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1f
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x6e
	.uleb128 0x8
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x20
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x21
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x55
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x22
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.byte	0
	.byte	0
	.uleb128 0x23
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x6e
	.uleb128 0xe
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"dr"
	.long	0x4c
	.word	0x2
	.secrel32	.Ldebug_info0
	.byte	0x8
	.byte	0
	.word	0
	.word	0
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.quad	.LFB2
	.quad	.LFE2-.LFB2
	.quad	.LFB8
	.quad	.LFE8-.LFB8
	.quad	0
	.quad	0
	.section	.debug_ranges,"dr"
.Ldebug_ranges0:
	.quad	.LBB3
	.quad	.LBE3
	.quad	.LBB10
	.quad	.LBE10
	.quad	0
	.quad	0
	.quad	.LBB5
	.quad	.LBE5
	.quad	.LBB9
	.quad	.LBE9
	.quad	0
	.quad	0
	.quad	.Ltext0
	.quad	.Letext0
	.quad	.LFB2
	.quad	.LFE2
	.quad	.LFB8
	.quad	.LFE8
	.quad	0
	.quad	0
	.section	.debug_line,"dr"
.Ldebug_line0:
	.section	.debug_str,"dr"
.LASF3:
	.ascii "__acrt_iob_func\0"
.LASF0:
	.ascii "__retval\0"
.LASF2:
	.ascii "__format\0"
.LASF1:
	.ascii "__local_argv\0"
	.ident	"GCC: (x86_64-win32-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	__mingw_vfscanf;	.scl	2;	.type	32;	.endef
	.def	__mingw_vfprintf;	.scl	2;	.type	32;	.endef
	.def	freopen;	.scl	2;	.type	32;	.endef
	.def	puts;	.scl	2;	.type	32;	.endef
