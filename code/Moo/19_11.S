	.file	"19_1.cpp"
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
	.section .rdata,"dr"
	.align 4
_ZL1N:
	.long	31
	.globl	f
	.bss
	.align 32
f:
	.space 124
	.text
	.globl	_Z5solveii
	.def	_Z5solveii;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5solveii
_Z5solveii:
.LFB44:
	.file 2 "C++/Moo/19_1.cpp"
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
	movl	%edx, 24(%rbp)
	.loc 2 8 15
	movl	16(%rbp), %eax
	subl	$1, %eax
	.loc 2 8 18
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	f(%rip), %rax
	movl	(%rdx,%rax), %eax
	.loc 2 8 2
	cmpl	%eax, 24(%rbp)
	jg	.L4
	.loc 2 8 33 discriminator 1
	movl	16(%rbp), %eax
	subl	$1, %eax
	movl	24(%rbp), %edx
	movl	%eax, %ecx
	call	_Z5solveii
	.loc 2 8 42 discriminator 1
	jmp	.L5
.L4:
	.loc 2 9 20
	movl	16(%rbp), %eax
	subl	$1, %eax
	.loc 2 9 23
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	f(%rip), %rax
	movl	(%rdx,%rax), %eax
	.loc 2 9 6
	movl	24(%rbp), %edx
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -4(%rbp)
	.loc 2 10 15
	movl	16(%rbp), %eax
	addl	$3, %eax
	.loc 2 10 2
	cmpl	%eax, -4(%rbp)
	jg	.L6
	.loc 2 10 36 discriminator 1
	cmpl	$1, -4(%rbp)
	jne	.L7
	.loc 2 10 36 is_stmt 0 discriminator 2
	movl	$109, %eax
	.loc 2 10 44 is_stmt 1 discriminator 2
	jmp	.L5
.L7:
	.loc 2 10 36 discriminator 3
	movl	$111, %eax
	.loc 2 10 44 discriminator 3
	jmp	.L5
.L6:
	.loc 2 11 31
	movl	16(%rbp), %eax
	addl	$3, %eax
	.loc 2 11 14
	movl	-4(%rbp), %edx
	subl	%eax, %edx
	movl	16(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %ecx
	call	_Z5solveii
	.loc 2 11 35
	nop
.L5:
	.loc 2 12 1
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
	.ascii "%d\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB45:
	.loc 2 15 1
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
	.loc 2 15 1
	call	__main
.LVL1:
	.loc 2 17 7
	leaq	-8(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC0(%rip), %rcx
	call	_Z5scanfPKcz
	.loc 2 18 7
	movl	$3, f(%rip)
	.loc 2 20 9
	movl	$1, -4(%rbp)
.L11:
	.loc 2 20 18 discriminator 3
	movl	-4(%rbp), %eax
	subl	$1, %eax
	.loc 2 20 21 discriminator 3
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	f(%rip), %rax
	movl	(%rdx,%rax), %edx
	.loc 2 20 23 discriminator 3
	movl	-8(%rbp), %eax
	cmpl	%eax, %edx
	jge	.L10
	.loc 2 20 42 discriminator 2
	movl	-4(%rbp), %eax
	leal	3(%rax), %ecx
	.loc 2 20 53 discriminator 2
	movl	-4(%rbp), %eax
	subl	$1, %eax
	.loc 2 20 56 discriminator 2
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	f(%rip), %rax
	movl	(%rdx,%rax), %eax
	.loc 2 20 58 discriminator 2
	addl	%eax, %eax
	.loc 2 20 46 discriminator 2
	addl	%eax, %ecx
	.loc 2 20 38 discriminator 2
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	f(%rip), %rax
	movl	%ecx, (%rdx,%rax)
	.loc 2 20 2 discriminator 2
	addl	$1, -4(%rbp)
	jmp	.L11
.L10:
	.loc 2 21 15
	movl	-8(%rbp), %edx
	movl	-4(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %ecx
	call	_Z5solveii
	.loc 2 21 9
	movsbl	%al, %eax
	movl	%eax, %ecx
	call	putchar
	.loc 2 22 9
	movl	$0, %eax
	.loc 2 23 1
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
	.long	0xac7
	.word	0x4
	.secrel32	.Ldebug_abbrev0
	.byte	0x8
	.uleb128 0x1
	.ascii "GNU C++98 8.1.0 -mtune=core2 -march=nocona -g -std=gnu++98\0"
	.byte	0x4
	.ascii "C++/Moo/19_1.cpp\0"
	.ascii "E:\\code\0"
	.secrel32	.Ldebug_ranges0+0
	.quad	0
	.secrel32	.Ldebug_line0
	.uleb128 0x2
	.ascii "std\0"
	.byte	0x6
	.byte	0
	.long	0x1e3
	.uleb128 0x3
	.ascii "__cxx11\0"
	.byte	0x4
	.word	0x104
	.byte	0x41
	.uleb128 0x4
	.byte	0x4
	.word	0x104
	.byte	0x41
	.long	0x7c
	.uleb128 0x5
	.byte	0x3
	.byte	0x62
	.byte	0xb
	.long	0x399
	.uleb128 0x5
	.byte	0x3
	.byte	0x63
	.byte	0xb
	.long	0x3a6
	.uleb128 0x5
	.byte	0x3
	.byte	0x65
	.byte	0xb
	.long	0x3ba
	.uleb128 0x5
	.byte	0x3
	.byte	0x66
	.byte	0xb
	.long	0x3d8
	.uleb128 0x5
	.byte	0x3
	.byte	0x67
	.byte	0xb
	.long	0x3f2
	.uleb128 0x5
	.byte	0x3
	.byte	0x68
	.byte	0xb
	.long	0x40a
	.uleb128 0x5
	.byte	0x3
	.byte	0x69
	.byte	0xb
	.long	0x424
	.uleb128 0x5
	.byte	0x3
	.byte	0x6a
	.byte	0xb
	.long	0x43e
	.uleb128 0x5
	.byte	0x3
	.byte	0x6b
	.byte	0xb
	.long	0x457
	.uleb128 0x5
	.byte	0x3
	.byte	0x6c
	.byte	0xb
	.long	0x47d
	.uleb128 0x5
	.byte	0x3
	.byte	0x6d
	.byte	0xb
	.long	0x4a0
	.uleb128 0x5
	.byte	0x3
	.byte	0x6e
	.byte	0xb
	.long	0x4c4
	.uleb128 0x5
	.byte	0x3
	.byte	0x71
	.byte	0xb
	.long	0x4fc
	.uleb128 0x5
	.byte	0x3
	.byte	0x72
	.byte	0xb
	.long	0x526
	.uleb128 0x5
	.byte	0x3
	.byte	0x73
	.byte	0xb
	.long	0x54b
	.uleb128 0x5
	.byte	0x3
	.byte	0x74
	.byte	0xb
	.long	0x581
	.uleb128 0x5
	.byte	0x3
	.byte	0x75
	.byte	0xb
	.long	0x5a4
	.uleb128 0x5
	.byte	0x3
	.byte	0x76
	.byte	0xb
	.long	0x5ca
	.uleb128 0x5
	.byte	0x3
	.byte	0x78
	.byte	0xb
	.long	0x5e3
	.uleb128 0x5
	.byte	0x3
	.byte	0x79
	.byte	0xb
	.long	0x5fb
	.uleb128 0x5
	.byte	0x3
	.byte	0x7c
	.byte	0xb
	.long	0x60c
	.uleb128 0x5
	.byte	0x3
	.byte	0x7e
	.byte	0xb
	.long	0x624
	.uleb128 0x5
	.byte	0x3
	.byte	0x7f
	.byte	0xb
	.long	0x63a
	.uleb128 0x5
	.byte	0x3
	.byte	0x83
	.byte	0xb
	.long	0x663
	.uleb128 0x5
	.byte	0x3
	.byte	0x84
	.byte	0xb
	.long	0x67d
	.uleb128 0x5
	.byte	0x3
	.byte	0x85
	.byte	0xb
	.long	0x69c
	.uleb128 0x5
	.byte	0x3
	.byte	0x86
	.byte	0xb
	.long	0x6b2
	.uleb128 0x5
	.byte	0x3
	.byte	0x87
	.byte	0xb
	.long	0x737
	.uleb128 0x5
	.byte	0x3
	.byte	0x88
	.byte	0xb
	.long	0x752
	.uleb128 0x5
	.byte	0x3
	.byte	0x89
	.byte	0xb
	.long	0x77c
	.uleb128 0x5
	.byte	0x3
	.byte	0x8a
	.byte	0xb
	.long	0x7ae
	.uleb128 0x5
	.byte	0x3
	.byte	0x8b
	.byte	0xb
	.long	0x7df
	.uleb128 0x5
	.byte	0x3
	.byte	0x8d
	.byte	0xb
	.long	0x7f0
	.uleb128 0x5
	.byte	0x3
	.byte	0x8f
	.byte	0xb
	.long	0x80a
	.uleb128 0x5
	.byte	0x3
	.byte	0x90
	.byte	0xb
	.long	0x829
	.uleb128 0x5
	.byte	0x3
	.byte	0x91
	.byte	0xb
	.long	0x868
	.uleb128 0x5
	.byte	0x3
	.byte	0x92
	.byte	0xb
	.long	0x898
	.uleb128 0x5
	.byte	0x3
	.byte	0xb9
	.byte	0x16
	.long	0x8d1
	.uleb128 0x5
	.byte	0x3
	.byte	0xba
	.byte	0x16
	.long	0x90b
	.uleb128 0x5
	.byte	0x3
	.byte	0xbb
	.byte	0x16
	.long	0x948
	.uleb128 0x5
	.byte	0x3
	.byte	0xbc
	.byte	0x16
	.long	0x976
	.uleb128 0x5
	.byte	0x3
	.byte	0xbd
	.byte	0x16
	.long	0x9b7
	.byte	0
	.uleb128 0x6
	.ascii "__gnu_cxx\0"
	.byte	0x4
	.word	0x106
	.byte	0xb
	.long	0x235
	.uleb128 0x3
	.ascii "__cxx11\0"
	.byte	0x4
	.word	0x108
	.byte	0x41
	.uleb128 0x4
	.byte	0x4
	.word	0x108
	.byte	0x41
	.long	0x1f6
	.uleb128 0x5
	.byte	0x3
	.byte	0xaf
	.byte	0xb
	.long	0x8d1
	.uleb128 0x5
	.byte	0x3
	.byte	0xb0
	.byte	0xb
	.long	0x90b
	.uleb128 0x5
	.byte	0x3
	.byte	0xb1
	.byte	0xb
	.long	0x948
	.uleb128 0x5
	.byte	0x3
	.byte	0xb2
	.byte	0xb
	.long	0x976
	.uleb128 0x5
	.byte	0x3
	.byte	0xb3
	.byte	0xb
	.long	0x9b7
	.byte	0
	.uleb128 0x7
	.byte	0x8
	.ascii "__builtin_va_list\0"
	.long	0x24d
	.uleb128 0x8
	.byte	0x1
	.byte	0x6
	.ascii "char\0"
	.uleb128 0x9
	.long	0x24d
	.uleb128 0xa
	.ascii "size_t\0"
	.byte	0x5
	.byte	0x23
	.byte	0x2c
	.long	0x269
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
	.long	0x2aa
	.uleb128 0x8
	.byte	0x4
	.byte	0x5
	.ascii "long int\0"
	.uleb128 0xb
	.byte	0x8
	.long	0x24d
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
	.long	0x399
	.uleb128 0xd
	.ascii "_ptr\0"
	.byte	0x1
	.byte	0x1b
	.byte	0xb
	.long	0x2c2
	.byte	0
	.uleb128 0xd
	.ascii "_cnt\0"
	.byte	0x1
	.byte	0x1c
	.byte	0x9
	.long	0x2aa
	.byte	0x8
	.uleb128 0xd
	.ascii "_base\0"
	.byte	0x1
	.byte	0x1d
	.byte	0xb
	.long	0x2c2
	.byte	0x10
	.uleb128 0xd
	.ascii "_flag\0"
	.byte	0x1
	.byte	0x1e
	.byte	0x9
	.long	0x2aa
	.byte	0x18
	.uleb128 0xd
	.ascii "_file\0"
	.byte	0x1
	.byte	0x1f
	.byte	0x9
	.long	0x2aa
	.byte	0x1c
	.uleb128 0xd
	.ascii "_charbuf\0"
	.byte	0x1
	.byte	0x20
	.byte	0x9
	.long	0x2aa
	.byte	0x20
	.uleb128 0xd
	.ascii "_bufsiz\0"
	.byte	0x1
	.byte	0x21
	.byte	0x9
	.long	0x2aa
	.byte	0x24
	.uleb128 0xd
	.ascii "_tmpfname\0"
	.byte	0x1
	.byte	0x22
	.byte	0xb
	.long	0x2c2
	.byte	0x28
	.byte	0
	.uleb128 0xa
	.ascii "FILE\0"
	.byte	0x1
	.byte	0x24
	.byte	0x19
	.long	0x309
	.uleb128 0xa
	.ascii "fpos_t\0"
	.byte	0x1
	.byte	0x68
	.byte	0x25
	.long	0x283
	.uleb128 0x9
	.long	0x3a6
	.uleb128 0xe
	.ascii "clearerr\0"
	.byte	0x1
	.word	0x242
	.byte	0x10
	.long	0x3d2
	.uleb128 0xf
	.long	0x3d2
	.byte	0
	.uleb128 0xb
	.byte	0x8
	.long	0x399
	.uleb128 0x10
	.ascii "fclose\0"
	.byte	0x1
	.word	0x243
	.byte	0xf
	.long	0x2aa
	.long	0x3f2
	.uleb128 0xf
	.long	0x3d2
	.byte	0
	.uleb128 0x10
	.ascii "feof\0"
	.byte	0x1
	.word	0x24a
	.byte	0xf
	.long	0x2aa
	.long	0x40a
	.uleb128 0xf
	.long	0x3d2
	.byte	0
	.uleb128 0x10
	.ascii "ferror\0"
	.byte	0x1
	.word	0x24b
	.byte	0xf
	.long	0x2aa
	.long	0x424
	.uleb128 0xf
	.long	0x3d2
	.byte	0
	.uleb128 0x10
	.ascii "fflush\0"
	.byte	0x1
	.word	0x24c
	.byte	0xf
	.long	0x2aa
	.long	0x43e
	.uleb128 0xf
	.long	0x3d2
	.byte	0
	.uleb128 0x10
	.ascii "fgetc\0"
	.byte	0x1
	.word	0x24d
	.byte	0xf
	.long	0x2aa
	.long	0x457
	.uleb128 0xf
	.long	0x3d2
	.byte	0
	.uleb128 0x10
	.ascii "fgetpos\0"
	.byte	0x1
	.word	0x24f
	.byte	0xf
	.long	0x2aa
	.long	0x477
	.uleb128 0xf
	.long	0x3d2
	.uleb128 0xf
	.long	0x477
	.byte	0
	.uleb128 0xb
	.byte	0x8
	.long	0x3a6
	.uleb128 0x10
	.ascii "fgets\0"
	.byte	0x1
	.word	0x251
	.byte	0x11
	.long	0x2c2
	.long	0x4a0
	.uleb128 0xf
	.long	0x2c2
	.uleb128 0xf
	.long	0x2aa
	.uleb128 0xf
	.long	0x3d2
	.byte	0
	.uleb128 0x10
	.ascii "fopen\0"
	.byte	0x1
	.word	0x258
	.byte	0x11
	.long	0x3d2
	.long	0x4be
	.uleb128 0xf
	.long	0x4be
	.uleb128 0xf
	.long	0x4be
	.byte	0
	.uleb128 0xb
	.byte	0x8
	.long	0x255
	.uleb128 0x11
	.ascii "fprintf\0"
	.byte	0x1
	.word	0x14e
	.byte	0x5
	.ascii "_Z7fprintfP6_iobufPKcz\0"
	.long	0x2aa
	.long	0x4fc
	.uleb128 0xf
	.long	0x3d2
	.uleb128 0xf
	.long	0x4be
	.uleb128 0x12
	.byte	0
	.uleb128 0x10
	.ascii "fread\0"
	.byte	0x1
	.word	0x25d
	.byte	0x12
	.long	0x25a
	.long	0x524
	.uleb128 0xf
	.long	0x524
	.uleb128 0xf
	.long	0x25a
	.uleb128 0xf
	.long	0x25a
	.uleb128 0xf
	.long	0x3d2
	.byte	0
	.uleb128 0x13
	.byte	0x8
	.uleb128 0x10
	.ascii "freopen\0"
	.byte	0x1
	.word	0x25e
	.byte	0x11
	.long	0x3d2
	.long	0x54b
	.uleb128 0xf
	.long	0x4be
	.uleb128 0xf
	.long	0x4be
	.uleb128 0xf
	.long	0x3d2
	.byte	0
	.uleb128 0x11
	.ascii "fscanf\0"
	.byte	0x1
	.word	0x121
	.byte	0x5
	.ascii "_Z6fscanfP6_iobufPKcz\0"
	.long	0x2aa
	.long	0x581
	.uleb128 0xf
	.long	0x3d2
	.uleb128 0xf
	.long	0x4be
	.uleb128 0x12
	.byte	0
	.uleb128 0x10
	.ascii "fseek\0"
	.byte	0x1
	.word	0x261
	.byte	0xf
	.long	0x2aa
	.long	0x5a4
	.uleb128 0xf
	.long	0x3d2
	.uleb128 0xf
	.long	0x2b6
	.uleb128 0xf
	.long	0x2aa
	.byte	0
	.uleb128 0x10
	.ascii "fsetpos\0"
	.byte	0x1
	.word	0x25f
	.byte	0xf
	.long	0x2aa
	.long	0x5c4
	.uleb128 0xf
	.long	0x3d2
	.uleb128 0xf
	.long	0x5c4
	.byte	0
	.uleb128 0xb
	.byte	0x8
	.long	0x3b5
	.uleb128 0x10
	.ascii "ftell\0"
	.byte	0x1
	.word	0x262
	.byte	0x10
	.long	0x2b6
	.long	0x5e3
	.uleb128 0xf
	.long	0x3d2
	.byte	0
	.uleb128 0x10
	.ascii "getc\0"
	.byte	0x1
	.word	0x28f
	.byte	0xf
	.long	0x2aa
	.long	0x5fb
	.uleb128 0xf
	.long	0x3d2
	.byte	0
	.uleb128 0x14
	.ascii "getchar\0"
	.byte	0x1
	.word	0x290
	.byte	0xf
	.long	0x2aa
	.uleb128 0x10
	.ascii "gets\0"
	.byte	0x1
	.word	0x292
	.byte	0x11
	.long	0x2c2
	.long	0x624
	.uleb128 0xf
	.long	0x2c2
	.byte	0
	.uleb128 0xe
	.ascii "perror\0"
	.byte	0x1
	.word	0x296
	.byte	0x10
	.long	0x63a
	.uleb128 0xf
	.long	0x4be
	.byte	0
	.uleb128 0x11
	.ascii "printf\0"
	.byte	0x1
	.word	0x159
	.byte	0x5
	.ascii "_Z6printfPKcz\0"
	.long	0x2aa
	.long	0x663
	.uleb128 0xf
	.long	0x4be
	.uleb128 0x12
	.byte	0
	.uleb128 0x10
	.ascii "remove\0"
	.byte	0x1
	.word	0x2a4
	.byte	0xf
	.long	0x2aa
	.long	0x67d
	.uleb128 0xf
	.long	0x4be
	.byte	0
	.uleb128 0x10
	.ascii "rename\0"
	.byte	0x1
	.word	0x2a5
	.byte	0xf
	.long	0x2aa
	.long	0x69c
	.uleb128 0xf
	.long	0x4be
	.uleb128 0xf
	.long	0x4be
	.byte	0
	.uleb128 0xe
	.ascii "rewind\0"
	.byte	0x1
	.word	0x2ab
	.byte	0x10
	.long	0x6b2
	.uleb128 0xf
	.long	0x3d2
	.byte	0
	.uleb128 0x15
	.ascii "scanf\0"
	.byte	0x1
	.word	0x116
	.byte	0x5
	.ascii "_Z5scanfPKcz\0"
	.long	0x2aa
	.quad	.LFB2
	.quad	.LFE2-.LFB2
	.uleb128 0x1
	.byte	0x9c
	.long	0x737
	.uleb128 0x12
	.uleb128 0x16
	.ascii "__format\0"
	.byte	0x1
	.word	0x116
	.byte	0x17
	.long	0x4be
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x12
	.uleb128 0x17
	.ascii "__retval\0"
	.byte	0x1
	.word	0x118
	.byte	0x7
	.long	0x2aa
	.uleb128 0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0x17
	.ascii "__local_argv\0"
	.byte	0x1
	.word	0x119
	.byte	0x15
	.long	0x235
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x18
	.quad	.LVL0
	.long	0xabe
	.byte	0
	.uleb128 0xe
	.ascii "setbuf\0"
	.byte	0x1
	.word	0x2ad
	.byte	0x10
	.long	0x752
	.uleb128 0xf
	.long	0x3d2
	.uleb128 0xf
	.long	0x2c2
	.byte	0
	.uleb128 0x10
	.ascii "setvbuf\0"
	.byte	0x1
	.word	0x2b1
	.byte	0xf
	.long	0x2aa
	.long	0x77c
	.uleb128 0xf
	.long	0x3d2
	.uleb128 0xf
	.long	0x2c2
	.uleb128 0xf
	.long	0x2aa
	.uleb128 0xf
	.long	0x25a
	.byte	0
	.uleb128 0x11
	.ascii "sprintf\0"
	.byte	0x1
	.word	0x164
	.byte	0x5
	.ascii "_Z7sprintfPcPKcz\0"
	.long	0x2aa
	.long	0x7ae
	.uleb128 0xf
	.long	0x2c2
	.uleb128 0xf
	.long	0x4be
	.uleb128 0x12
	.byte	0
	.uleb128 0x11
	.ascii "sscanf\0"
	.byte	0x1
	.word	0x10b
	.byte	0x5
	.ascii "_Z6sscanfPKcS0_z\0"
	.long	0x2aa
	.long	0x7df
	.uleb128 0xf
	.long	0x4be
	.uleb128 0xf
	.long	0x4be
	.uleb128 0x12
	.byte	0
	.uleb128 0x14
	.ascii "tmpfile\0"
	.byte	0x1
	.word	0x2cb
	.byte	0x11
	.long	0x3d2
	.uleb128 0x10
	.ascii "tmpnam\0"
	.byte	0x1
	.word	0x2cc
	.byte	0x11
	.long	0x2c2
	.long	0x80a
	.uleb128 0xf
	.long	0x2c2
	.byte	0
	.uleb128 0x10
	.ascii "ungetc\0"
	.byte	0x1
	.word	0x2cd
	.byte	0xf
	.long	0x2aa
	.long	0x829
	.uleb128 0xf
	.long	0x2aa
	.uleb128 0xf
	.long	0x3d2
	.byte	0
	.uleb128 0x11
	.ascii "vfprintf\0"
	.byte	0x1
	.word	0x16f
	.byte	0x5
	.ascii "_Z8vfprintfP6_iobufPKcPc\0"
	.long	0x2aa
	.long	0x868
	.uleb128 0xf
	.long	0x3d2
	.uleb128 0xf
	.long	0x4be
	.uleb128 0xf
	.long	0x235
	.byte	0
	.uleb128 0x11
	.ascii "vprintf\0"
	.byte	0x1
	.word	0x176
	.byte	0x5
	.ascii "_Z7vprintfPKcPc\0"
	.long	0x2aa
	.long	0x898
	.uleb128 0xf
	.long	0x4be
	.uleb128 0xf
	.long	0x235
	.byte	0
	.uleb128 0x11
	.ascii "vsprintf\0"
	.byte	0x1
	.word	0x17d
	.byte	0x5
	.ascii "_Z8vsprintfPcPKcS_\0"
	.long	0x2aa
	.long	0x8d1
	.uleb128 0xf
	.long	0x2c2
	.uleb128 0xf
	.long	0x4be
	.uleb128 0xf
	.long	0x235
	.byte	0
	.uleb128 0x11
	.ascii "snprintf\0"
	.byte	0x1
	.word	0x184
	.byte	0x5
	.ascii "_Z8snprintfPcyPKcz\0"
	.long	0x2aa
	.long	0x90b
	.uleb128 0xf
	.long	0x2c2
	.uleb128 0xf
	.long	0x25a
	.uleb128 0xf
	.long	0x4be
	.uleb128 0x12
	.byte	0
	.uleb128 0x11
	.ascii "vfscanf\0"
	.byte	0x1
	.word	0x140
	.byte	0x5
	.ascii "_Z7vfscanfP6_iobufPKcPc\0"
	.long	0x2aa
	.long	0x948
	.uleb128 0xf
	.long	0x3d2
	.uleb128 0xf
	.long	0x4be
	.uleb128 0xf
	.long	0x235
	.byte	0
	.uleb128 0x11
	.ascii "vscanf\0"
	.byte	0x1
	.word	0x139
	.byte	0x5
	.ascii "_Z6vscanfPKcPc\0"
	.long	0x2aa
	.long	0x976
	.uleb128 0xf
	.long	0x4be
	.uleb128 0xf
	.long	0x235
	.byte	0
	.uleb128 0x11
	.ascii "vsnprintf\0"
	.byte	0x1
	.word	0x18f
	.byte	0x5
	.ascii "_Z9vsnprintfPcyPKcS_\0"
	.long	0x2aa
	.long	0x9b7
	.uleb128 0xf
	.long	0x2c2
	.uleb128 0xf
	.long	0x25a
	.uleb128 0xf
	.long	0x4be
	.uleb128 0xf
	.long	0x235
	.byte	0
	.uleb128 0x11
	.ascii "vsscanf\0"
	.byte	0x1
	.word	0x132
	.byte	0x5
	.ascii "_Z7vsscanfPKcS0_Pc\0"
	.long	0x2aa
	.long	0x9ef
	.uleb128 0xf
	.long	0x4be
	.uleb128 0xf
	.long	0x4be
	.uleb128 0xf
	.long	0x235
	.byte	0
	.uleb128 0x19
	.ascii "N\0"
	.byte	0x2
	.byte	0x3
	.byte	0xb
	.long	0x2b1
	.uleb128 0x9
	.byte	0x3
	.quad	_ZL1N
	.uleb128 0x1a
	.long	0x2aa
	.long	0xa13
	.uleb128 0x1b
	.long	0x269
	.byte	0x1e
	.byte	0
	.uleb128 0x1c
	.ascii "f\0"
	.byte	0x2
	.byte	0x4
	.byte	0x5
	.long	0xa03
	.uleb128 0x9
	.byte	0x3
	.quad	f
	.uleb128 0x1d
	.ascii "main\0"
	.byte	0x2
	.byte	0xe
	.byte	0x5
	.long	0x2aa
	.quad	.LFB45
	.quad	.LFE45-.LFB45
	.uleb128 0x1
	.byte	0x9c
	.long	0xa65
	.uleb128 0x19
	.ascii "n\0"
	.byte	0x2
	.byte	0x10
	.byte	0x6
	.long	0x2aa
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x19
	.ascii "i\0"
	.byte	0x2
	.byte	0x13
	.byte	0x6
	.long	0x2aa
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.byte	0
	.uleb128 0x1e
	.ascii "solve\0"
	.byte	0x2
	.byte	0x6
	.byte	0x6
	.ascii "_Z5solveii\0"
	.long	0x24d
	.quad	.LFB44
	.quad	.LFE44-.LFB44
	.uleb128 0x1
	.byte	0x9c
	.long	0xabe
	.uleb128 0x1f
	.ascii "s\0"
	.byte	0x2
	.byte	0x6
	.byte	0x10
	.long	0x2aa
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x1f
	.ascii "k\0"
	.byte	0x2
	.byte	0x6
	.byte	0x17
	.long	0x2aa
	.uleb128 0x2
	.byte	0x91
	.sleb128 8
	.uleb128 0x19
	.ascii "tmp\0"
	.byte	0x2
	.byte	0x9
	.byte	0x6
	.long	0x2aa
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.byte	0
	.uleb128 0x20
	.secrel32	.LASF0
	.secrel32	.LASF0
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
	.uleb128 0x8
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
	.uleb128 0x8
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
	.uleb128 0x1f
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
	.uleb128 0x20
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
	.long	0x3c
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
	.quad	0
	.quad	0
	.section	.debug_ranges,"dr"
.Ldebug_ranges0:
	.quad	.Ltext0
	.quad	.Letext0
	.quad	.LFB2
	.quad	.LFE2
	.quad	0
	.quad	0
	.section	.debug_line,"dr"
.Ldebug_line0:
	.section	.debug_str,"dr"
.LASF0:
	.ascii "__acrt_iob_func\0"
	.ident	"GCC: (x86_64-win32-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	__mingw_vfscanf;	.scl	2;	.type	32;	.endef
	.def	putchar;	.scl	2;	.type	32;	.endef
