	.file	"\277\354\266\301.cpp"
	.text
.Ltext0:
	.cfi_sections	.debug_frame
	.section	.text$_Z6printfPKcz,"x"
	.linkonce discard
	.globl	_Z6printfPKcz
	.def	_Z6printfPKcz;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z6printfPKcz
_Z6printfPKcz:
.LFB8:
	.file 1 "C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include/stdio.h"
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
.LVL0:
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
	.text
	.globl	_Z8Get_Charv
	.def	_Z8Get_Charv;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z8Get_Charv
_Z8Get_Charv:
.LFB44:
	.file 2 "../../code/code/\312\265\321\351\243\272\273\343\261\340/\277\354\266\301.cpp"
	.loc 2 9 1
	.cfi_startproc
	pushq	%rbp
	.seh_pushreg	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.seh_pushreg	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$40, %rsp
	.seh_stackalloc	40
	.cfi_def_cfa_offset 64
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.cfi_def_cfa 6, -64
	.seh_endprologue
	.loc 2 10 8
	movq	S(%rip), %rdx
	movq	T(%rip), %rax
	.loc 2 10 2
	cmpq	%rax, %rdx
	jne	.L4
	.loc 2 12 10
	leaq	buffer(%rip), %rax
	movq	%rax, S(%rip)
	movq	S(%rip), %rbx
	.loc 2 12 27
	movl	$0, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
.LVL1:
	movq	%rax, %r9
	movl	$131072, %r8d
	movl	$1, %edx
	leaq	buffer(%rip), %rcx
	call	fread
	.loc 2 12 20
	addq	%rbx, %rax
	.loc 2 12 5
	movq	%rax, T(%rip)
	.loc 2 13 9
	movq	S(%rip), %rdx
	movq	T(%rip), %rax
	.loc 2 13 3
	cmpq	%rax, %rdx
	jne	.L4
	.loc 2 13 22 discriminator 1
	movl	$-1, %eax
	jmp	.L5
.L4:
	.loc 2 15 11
	movq	S(%rip), %rax
	leaq	1(%rax), %rdx
	movq	%rdx, S(%rip)
	movzbl	(%rax), %eax
.L5:
	.loc 2 16 1
	addq	$40, %rsp
	popq	%rbx
	.cfi_restore 3
	popq	%rbp
	.cfi_restore 6
	.cfi_def_cfa 7, -24
	ret
	.cfi_endproc
.LFE44:
	.seh_endproc
	.globl	_Z7Get_Intv
	.def	_Z7Get_Intv;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z7Get_Intv
_Z7Get_Intv:
.LFB45:
	.loc 2 19 1
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
	.loc 2 21 6
	movl	$0, -8(%rbp)
	.loc 2 22 19
	call	_Z8Get_Charv
	movb	%al, -1(%rbp)
.L9:
	.loc 2 22 31 discriminator 5
	cmpb	$47, -1(%rbp)
	jle	.L7
	.loc 2 22 31 is_stmt 0 discriminator 2
	cmpb	$57, -1(%rbp)
	jle	.L8
.L7:
	.loc 2 22 55 is_stmt 1 discriminator 4
	call	_Z8Get_Charv
	movb	%al, -1(%rbp)
	.loc 2 22 2 discriminator 4
	jmp	.L9
.L8:
	.loc 2 24 18
	cmpb	$47, -1(%rbp)
	jle	.L10
	.loc 2 24 18 is_stmt 0 discriminator 1
	cmpb	$57, -1(%rbp)
	jg	.L10
	.loc 2 25 12 is_stmt 1
	movl	-8(%rbp), %eax
	leal	(%rax,%rax), %edx
	.loc 2 25 24
	movl	-8(%rbp), %eax
	sall	$3, %eax
	.loc 2 25 18
	addl	%eax, %edx
	.loc 2 25 35
	movsbl	-1(%rbp), %eax
	subl	$48, %eax
	.loc 2 25 6
	addl	%edx, %eax
	movl	%eax, -8(%rbp)
	.loc 2 25 55
	call	_Z8Get_Charv
	movb	%al, -1(%rbp)
	.loc 2 24 2
	jmp	.L8
.L10:
	.loc 2 26 9
	movl	-8(%rbp), %eax
	.loc 2 27 1
	addq	$48, %rsp
	popq	%rbp
	.cfi_restore 6
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE45:
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
	.loc 2 30 1
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
	.loc 2 30 1
	call	__main
.LVL2:
	.loc 2 31 17
	call	_Z7Get_Intv
	movl	%eax, -4(%rbp)
	.loc 2 32 8
	movl	-4(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC0(%rip), %rcx
	call	_Z6printfPKcz
	.loc 2 33 9
	movl	$0, %eax
	.loc 2 34 1
	addq	$48, %rsp
	popq	%rbp
	.cfi_restore 6
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE46:
	.seh_endproc
.Letext0:
	.file 3 "C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/cstdio"
	.file 4 "C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/x86_64-w64-mingw32/bits/c++config.h"
	.file 5 "C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include/crtdefs.h"
	.file 6 "<built-in>"
	.section	.debug_info,"dr"
.Ldebug_info0:
	.long	0xb40
	.word	0x4
	.secrel32	.Ldebug_abbrev0
	.byte	0x8
	.uleb128 0x1
	.ascii "GNU C++98 8.1.0 -mtune=core2 -march=nocona -g -std=c++98\0"
	.byte	0x4
	.ascii "..\\..\\code\\code\\\312\265\321\351\243\272\273\343\261\340\\\277\354\266\301.cpp\0"
	.ascii "e:\\yz\\\322\273\326\320\0"
	.secrel32	.Ldebug_ranges0+0
	.quad	0
	.secrel32	.Ldebug_line0
	.uleb128 0x2
	.ascii "std\0"
	.byte	0x6
	.byte	0
	.long	0x1f7
	.uleb128 0x3
	.ascii "__cxx11\0"
	.byte	0x4
	.word	0x104
	.byte	0x41
	.uleb128 0x4
	.byte	0x4
	.word	0x104
	.byte	0x41
	.long	0x90
	.uleb128 0x5
	.byte	0x3
	.byte	0x62
	.byte	0xb
	.long	0x3ad
	.uleb128 0x5
	.byte	0x3
	.byte	0x63
	.byte	0xb
	.long	0x3ba
	.uleb128 0x5
	.byte	0x3
	.byte	0x65
	.byte	0xb
	.long	0x3ce
	.uleb128 0x5
	.byte	0x3
	.byte	0x66
	.byte	0xb
	.long	0x3ec
	.uleb128 0x5
	.byte	0x3
	.byte	0x67
	.byte	0xb
	.long	0x406
	.uleb128 0x5
	.byte	0x3
	.byte	0x68
	.byte	0xb
	.long	0x41e
	.uleb128 0x5
	.byte	0x3
	.byte	0x69
	.byte	0xb
	.long	0x438
	.uleb128 0x5
	.byte	0x3
	.byte	0x6a
	.byte	0xb
	.long	0x452
	.uleb128 0x5
	.byte	0x3
	.byte	0x6b
	.byte	0xb
	.long	0x46b
	.uleb128 0x5
	.byte	0x3
	.byte	0x6c
	.byte	0xb
	.long	0x491
	.uleb128 0x5
	.byte	0x3
	.byte	0x6d
	.byte	0xb
	.long	0x4b4
	.uleb128 0x5
	.byte	0x3
	.byte	0x6e
	.byte	0xb
	.long	0x4d8
	.uleb128 0x5
	.byte	0x3
	.byte	0x71
	.byte	0xb
	.long	0x510
	.uleb128 0x5
	.byte	0x3
	.byte	0x72
	.byte	0xb
	.long	0x53a
	.uleb128 0x5
	.byte	0x3
	.byte	0x73
	.byte	0xb
	.long	0x55f
	.uleb128 0x5
	.byte	0x3
	.byte	0x74
	.byte	0xb
	.long	0x595
	.uleb128 0x5
	.byte	0x3
	.byte	0x75
	.byte	0xb
	.long	0x5b8
	.uleb128 0x5
	.byte	0x3
	.byte	0x76
	.byte	0xb
	.long	0x5de
	.uleb128 0x5
	.byte	0x3
	.byte	0x78
	.byte	0xb
	.long	0x5f7
	.uleb128 0x5
	.byte	0x3
	.byte	0x79
	.byte	0xb
	.long	0x60f
	.uleb128 0x5
	.byte	0x3
	.byte	0x7c
	.byte	0xb
	.long	0x620
	.uleb128 0x5
	.byte	0x3
	.byte	0x7e
	.byte	0xb
	.long	0x638
	.uleb128 0x5
	.byte	0x3
	.byte	0x7f
	.byte	0xb
	.long	0x64e
	.uleb128 0x5
	.byte	0x3
	.byte	0x83
	.byte	0xb
	.long	0x6d5
	.uleb128 0x5
	.byte	0x3
	.byte	0x84
	.byte	0xb
	.long	0x6ef
	.uleb128 0x5
	.byte	0x3
	.byte	0x85
	.byte	0xb
	.long	0x70e
	.uleb128 0x5
	.byte	0x3
	.byte	0x86
	.byte	0xb
	.long	0x724
	.uleb128 0x5
	.byte	0x3
	.byte	0x87
	.byte	0xb
	.long	0x74b
	.uleb128 0x5
	.byte	0x3
	.byte	0x88
	.byte	0xb
	.long	0x766
	.uleb128 0x5
	.byte	0x3
	.byte	0x89
	.byte	0xb
	.long	0x790
	.uleb128 0x5
	.byte	0x3
	.byte	0x8a
	.byte	0xb
	.long	0x7c2
	.uleb128 0x5
	.byte	0x3
	.byte	0x8b
	.byte	0xb
	.long	0x7f3
	.uleb128 0x5
	.byte	0x3
	.byte	0x8d
	.byte	0xb
	.long	0x804
	.uleb128 0x5
	.byte	0x3
	.byte	0x8f
	.byte	0xb
	.long	0x81e
	.uleb128 0x5
	.byte	0x3
	.byte	0x90
	.byte	0xb
	.long	0x83d
	.uleb128 0x5
	.byte	0x3
	.byte	0x91
	.byte	0xb
	.long	0x87c
	.uleb128 0x5
	.byte	0x3
	.byte	0x92
	.byte	0xb
	.long	0x8ac
	.uleb128 0x5
	.byte	0x3
	.byte	0xb9
	.byte	0x16
	.long	0x8e5
	.uleb128 0x5
	.byte	0x3
	.byte	0xba
	.byte	0x16
	.long	0x91f
	.uleb128 0x5
	.byte	0x3
	.byte	0xbb
	.byte	0x16
	.long	0x95c
	.uleb128 0x5
	.byte	0x3
	.byte	0xbc
	.byte	0x16
	.long	0x98a
	.uleb128 0x5
	.byte	0x3
	.byte	0xbd
	.byte	0x16
	.long	0x9cb
	.byte	0
	.uleb128 0x6
	.ascii "__gnu_cxx\0"
	.byte	0x4
	.word	0x106
	.byte	0xb
	.long	0x249
	.uleb128 0x3
	.ascii "__cxx11\0"
	.byte	0x4
	.word	0x108
	.byte	0x41
	.uleb128 0x4
	.byte	0x4
	.word	0x108
	.byte	0x41
	.long	0x20a
	.uleb128 0x5
	.byte	0x3
	.byte	0xaf
	.byte	0xb
	.long	0x8e5
	.uleb128 0x5
	.byte	0x3
	.byte	0xb0
	.byte	0xb
	.long	0x91f
	.uleb128 0x5
	.byte	0x3
	.byte	0xb1
	.byte	0xb
	.long	0x95c
	.uleb128 0x5
	.byte	0x3
	.byte	0xb2
	.byte	0xb
	.long	0x98a
	.uleb128 0x5
	.byte	0x3
	.byte	0xb3
	.byte	0xb
	.long	0x9cb
	.byte	0
	.uleb128 0x7
	.byte	0x8
	.ascii "__builtin_va_list\0"
	.long	0x261
	.uleb128 0x8
	.byte	0x1
	.byte	0x6
	.ascii "char\0"
	.uleb128 0x9
	.long	0x261
	.uleb128 0xa
	.ascii "size_t\0"
	.byte	0x5
	.byte	0x23
	.byte	0x2c
	.long	0x27d
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
	.long	0x2be
	.uleb128 0x8
	.byte	0x4
	.byte	0x5
	.ascii "long int\0"
	.uleb128 0xb
	.byte	0x8
	.long	0x261
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
	.long	0x3ad
	.uleb128 0xd
	.ascii "_ptr\0"
	.byte	0x1
	.byte	0x1b
	.byte	0xb
	.long	0x2d6
	.byte	0
	.uleb128 0xd
	.ascii "_cnt\0"
	.byte	0x1
	.byte	0x1c
	.byte	0x9
	.long	0x2be
	.byte	0x8
	.uleb128 0xd
	.ascii "_base\0"
	.byte	0x1
	.byte	0x1d
	.byte	0xb
	.long	0x2d6
	.byte	0x10
	.uleb128 0xd
	.ascii "_flag\0"
	.byte	0x1
	.byte	0x1e
	.byte	0x9
	.long	0x2be
	.byte	0x18
	.uleb128 0xd
	.ascii "_file\0"
	.byte	0x1
	.byte	0x1f
	.byte	0x9
	.long	0x2be
	.byte	0x1c
	.uleb128 0xd
	.ascii "_charbuf\0"
	.byte	0x1
	.byte	0x20
	.byte	0x9
	.long	0x2be
	.byte	0x20
	.uleb128 0xd
	.ascii "_bufsiz\0"
	.byte	0x1
	.byte	0x21
	.byte	0x9
	.long	0x2be
	.byte	0x24
	.uleb128 0xd
	.ascii "_tmpfname\0"
	.byte	0x1
	.byte	0x22
	.byte	0xb
	.long	0x2d6
	.byte	0x28
	.byte	0
	.uleb128 0xa
	.ascii "FILE\0"
	.byte	0x1
	.byte	0x24
	.byte	0x19
	.long	0x31d
	.uleb128 0xa
	.ascii "fpos_t\0"
	.byte	0x1
	.byte	0x68
	.byte	0x25
	.long	0x297
	.uleb128 0x9
	.long	0x3ba
	.uleb128 0xe
	.ascii "clearerr\0"
	.byte	0x1
	.word	0x242
	.byte	0x10
	.long	0x3e6
	.uleb128 0xf
	.long	0x3e6
	.byte	0
	.uleb128 0xb
	.byte	0x8
	.long	0x3ad
	.uleb128 0x10
	.ascii "fclose\0"
	.byte	0x1
	.word	0x243
	.byte	0xf
	.long	0x2be
	.long	0x406
	.uleb128 0xf
	.long	0x3e6
	.byte	0
	.uleb128 0x10
	.ascii "feof\0"
	.byte	0x1
	.word	0x24a
	.byte	0xf
	.long	0x2be
	.long	0x41e
	.uleb128 0xf
	.long	0x3e6
	.byte	0
	.uleb128 0x10
	.ascii "ferror\0"
	.byte	0x1
	.word	0x24b
	.byte	0xf
	.long	0x2be
	.long	0x438
	.uleb128 0xf
	.long	0x3e6
	.byte	0
	.uleb128 0x10
	.ascii "fflush\0"
	.byte	0x1
	.word	0x24c
	.byte	0xf
	.long	0x2be
	.long	0x452
	.uleb128 0xf
	.long	0x3e6
	.byte	0
	.uleb128 0x10
	.ascii "fgetc\0"
	.byte	0x1
	.word	0x24d
	.byte	0xf
	.long	0x2be
	.long	0x46b
	.uleb128 0xf
	.long	0x3e6
	.byte	0
	.uleb128 0x10
	.ascii "fgetpos\0"
	.byte	0x1
	.word	0x24f
	.byte	0xf
	.long	0x2be
	.long	0x48b
	.uleb128 0xf
	.long	0x3e6
	.uleb128 0xf
	.long	0x48b
	.byte	0
	.uleb128 0xb
	.byte	0x8
	.long	0x3ba
	.uleb128 0x10
	.ascii "fgets\0"
	.byte	0x1
	.word	0x251
	.byte	0x11
	.long	0x2d6
	.long	0x4b4
	.uleb128 0xf
	.long	0x2d6
	.uleb128 0xf
	.long	0x2be
	.uleb128 0xf
	.long	0x3e6
	.byte	0
	.uleb128 0x10
	.ascii "fopen\0"
	.byte	0x1
	.word	0x258
	.byte	0x11
	.long	0x3e6
	.long	0x4d2
	.uleb128 0xf
	.long	0x4d2
	.uleb128 0xf
	.long	0x4d2
	.byte	0
	.uleb128 0xb
	.byte	0x8
	.long	0x269
	.uleb128 0x11
	.ascii "fprintf\0"
	.byte	0x1
	.word	0x14e
	.byte	0x5
	.ascii "_Z7fprintfP6_iobufPKcz\0"
	.long	0x2be
	.long	0x510
	.uleb128 0xf
	.long	0x3e6
	.uleb128 0xf
	.long	0x4d2
	.uleb128 0x12
	.byte	0
	.uleb128 0x10
	.ascii "fread\0"
	.byte	0x1
	.word	0x25d
	.byte	0x12
	.long	0x26e
	.long	0x538
	.uleb128 0xf
	.long	0x538
	.uleb128 0xf
	.long	0x26e
	.uleb128 0xf
	.long	0x26e
	.uleb128 0xf
	.long	0x3e6
	.byte	0
	.uleb128 0x13
	.byte	0x8
	.uleb128 0x10
	.ascii "freopen\0"
	.byte	0x1
	.word	0x25e
	.byte	0x11
	.long	0x3e6
	.long	0x55f
	.uleb128 0xf
	.long	0x4d2
	.uleb128 0xf
	.long	0x4d2
	.uleb128 0xf
	.long	0x3e6
	.byte	0
	.uleb128 0x11
	.ascii "fscanf\0"
	.byte	0x1
	.word	0x121
	.byte	0x5
	.ascii "_Z6fscanfP6_iobufPKcz\0"
	.long	0x2be
	.long	0x595
	.uleb128 0xf
	.long	0x3e6
	.uleb128 0xf
	.long	0x4d2
	.uleb128 0x12
	.byte	0
	.uleb128 0x10
	.ascii "fseek\0"
	.byte	0x1
	.word	0x261
	.byte	0xf
	.long	0x2be
	.long	0x5b8
	.uleb128 0xf
	.long	0x3e6
	.uleb128 0xf
	.long	0x2ca
	.uleb128 0xf
	.long	0x2be
	.byte	0
	.uleb128 0x10
	.ascii "fsetpos\0"
	.byte	0x1
	.word	0x25f
	.byte	0xf
	.long	0x2be
	.long	0x5d8
	.uleb128 0xf
	.long	0x3e6
	.uleb128 0xf
	.long	0x5d8
	.byte	0
	.uleb128 0xb
	.byte	0x8
	.long	0x3c9
	.uleb128 0x10
	.ascii "ftell\0"
	.byte	0x1
	.word	0x262
	.byte	0x10
	.long	0x2ca
	.long	0x5f7
	.uleb128 0xf
	.long	0x3e6
	.byte	0
	.uleb128 0x10
	.ascii "getc\0"
	.byte	0x1
	.word	0x28f
	.byte	0xf
	.long	0x2be
	.long	0x60f
	.uleb128 0xf
	.long	0x3e6
	.byte	0
	.uleb128 0x14
	.ascii "getchar\0"
	.byte	0x1
	.word	0x290
	.byte	0xf
	.long	0x2be
	.uleb128 0x10
	.ascii "gets\0"
	.byte	0x1
	.word	0x292
	.byte	0x11
	.long	0x2d6
	.long	0x638
	.uleb128 0xf
	.long	0x2d6
	.byte	0
	.uleb128 0xe
	.ascii "perror\0"
	.byte	0x1
	.word	0x296
	.byte	0x10
	.long	0x64e
	.uleb128 0xf
	.long	0x4d2
	.byte	0
	.uleb128 0x15
	.ascii "printf\0"
	.byte	0x1
	.word	0x159
	.byte	0x5
	.ascii "_Z6printfPKcz\0"
	.long	0x2be
	.quad	.LFB8
	.quad	.LFE8-.LFB8
	.uleb128 0x1
	.byte	0x9c
	.long	0x6d5
	.uleb128 0x12
	.uleb128 0x16
	.ascii "__format\0"
	.byte	0x1
	.word	0x159
	.byte	0x19
	.long	0x4d2
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x12
	.uleb128 0x17
	.ascii "__retval\0"
	.byte	0x1
	.word	0x15b
	.byte	0x7
	.long	0x2be
	.uleb128 0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0x17
	.ascii "__local_argv\0"
	.byte	0x1
	.word	0x15c
	.byte	0x15
	.long	0x249
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x18
	.quad	.LVL0
	.long	0xb37
	.byte	0
	.uleb128 0x10
	.ascii "remove\0"
	.byte	0x1
	.word	0x2a4
	.byte	0xf
	.long	0x2be
	.long	0x6ef
	.uleb128 0xf
	.long	0x4d2
	.byte	0
	.uleb128 0x10
	.ascii "rename\0"
	.byte	0x1
	.word	0x2a5
	.byte	0xf
	.long	0x2be
	.long	0x70e
	.uleb128 0xf
	.long	0x4d2
	.uleb128 0xf
	.long	0x4d2
	.byte	0
	.uleb128 0xe
	.ascii "rewind\0"
	.byte	0x1
	.word	0x2ab
	.byte	0x10
	.long	0x724
	.uleb128 0xf
	.long	0x3e6
	.byte	0
	.uleb128 0x11
	.ascii "scanf\0"
	.byte	0x1
	.word	0x116
	.byte	0x5
	.ascii "_Z5scanfPKcz\0"
	.long	0x2be
	.long	0x74b
	.uleb128 0xf
	.long	0x4d2
	.uleb128 0x12
	.byte	0
	.uleb128 0xe
	.ascii "setbuf\0"
	.byte	0x1
	.word	0x2ad
	.byte	0x10
	.long	0x766
	.uleb128 0xf
	.long	0x3e6
	.uleb128 0xf
	.long	0x2d6
	.byte	0
	.uleb128 0x10
	.ascii "setvbuf\0"
	.byte	0x1
	.word	0x2b1
	.byte	0xf
	.long	0x2be
	.long	0x790
	.uleb128 0xf
	.long	0x3e6
	.uleb128 0xf
	.long	0x2d6
	.uleb128 0xf
	.long	0x2be
	.uleb128 0xf
	.long	0x26e
	.byte	0
	.uleb128 0x11
	.ascii "sprintf\0"
	.byte	0x1
	.word	0x164
	.byte	0x5
	.ascii "_Z7sprintfPcPKcz\0"
	.long	0x2be
	.long	0x7c2
	.uleb128 0xf
	.long	0x2d6
	.uleb128 0xf
	.long	0x4d2
	.uleb128 0x12
	.byte	0
	.uleb128 0x11
	.ascii "sscanf\0"
	.byte	0x1
	.word	0x10b
	.byte	0x5
	.ascii "_Z6sscanfPKcS0_z\0"
	.long	0x2be
	.long	0x7f3
	.uleb128 0xf
	.long	0x4d2
	.uleb128 0xf
	.long	0x4d2
	.uleb128 0x12
	.byte	0
	.uleb128 0x14
	.ascii "tmpfile\0"
	.byte	0x1
	.word	0x2cb
	.byte	0x11
	.long	0x3e6
	.uleb128 0x10
	.ascii "tmpnam\0"
	.byte	0x1
	.word	0x2cc
	.byte	0x11
	.long	0x2d6
	.long	0x81e
	.uleb128 0xf
	.long	0x2d6
	.byte	0
	.uleb128 0x10
	.ascii "ungetc\0"
	.byte	0x1
	.word	0x2cd
	.byte	0xf
	.long	0x2be
	.long	0x83d
	.uleb128 0xf
	.long	0x2be
	.uleb128 0xf
	.long	0x3e6
	.byte	0
	.uleb128 0x11
	.ascii "vfprintf\0"
	.byte	0x1
	.word	0x16f
	.byte	0x5
	.ascii "_Z8vfprintfP6_iobufPKcPc\0"
	.long	0x2be
	.long	0x87c
	.uleb128 0xf
	.long	0x3e6
	.uleb128 0xf
	.long	0x4d2
	.uleb128 0xf
	.long	0x249
	.byte	0
	.uleb128 0x11
	.ascii "vprintf\0"
	.byte	0x1
	.word	0x176
	.byte	0x5
	.ascii "_Z7vprintfPKcPc\0"
	.long	0x2be
	.long	0x8ac
	.uleb128 0xf
	.long	0x4d2
	.uleb128 0xf
	.long	0x249
	.byte	0
	.uleb128 0x11
	.ascii "vsprintf\0"
	.byte	0x1
	.word	0x17d
	.byte	0x5
	.ascii "_Z8vsprintfPcPKcS_\0"
	.long	0x2be
	.long	0x8e5
	.uleb128 0xf
	.long	0x2d6
	.uleb128 0xf
	.long	0x4d2
	.uleb128 0xf
	.long	0x249
	.byte	0
	.uleb128 0x11
	.ascii "snprintf\0"
	.byte	0x1
	.word	0x184
	.byte	0x5
	.ascii "_Z8snprintfPcyPKcz\0"
	.long	0x2be
	.long	0x91f
	.uleb128 0xf
	.long	0x2d6
	.uleb128 0xf
	.long	0x26e
	.uleb128 0xf
	.long	0x4d2
	.uleb128 0x12
	.byte	0
	.uleb128 0x11
	.ascii "vfscanf\0"
	.byte	0x1
	.word	0x140
	.byte	0x5
	.ascii "_Z7vfscanfP6_iobufPKcPc\0"
	.long	0x2be
	.long	0x95c
	.uleb128 0xf
	.long	0x3e6
	.uleb128 0xf
	.long	0x4d2
	.uleb128 0xf
	.long	0x249
	.byte	0
	.uleb128 0x11
	.ascii "vscanf\0"
	.byte	0x1
	.word	0x139
	.byte	0x5
	.ascii "_Z6vscanfPKcPc\0"
	.long	0x2be
	.long	0x98a
	.uleb128 0xf
	.long	0x4d2
	.uleb128 0xf
	.long	0x249
	.byte	0
	.uleb128 0x11
	.ascii "vsnprintf\0"
	.byte	0x1
	.word	0x18f
	.byte	0x5
	.ascii "_Z9vsnprintfPcyPKcS_\0"
	.long	0x2be
	.long	0x9cb
	.uleb128 0xf
	.long	0x2d6
	.uleb128 0xf
	.long	0x26e
	.uleb128 0xf
	.long	0x4d2
	.uleb128 0xf
	.long	0x249
	.byte	0
	.uleb128 0x11
	.ascii "vsscanf\0"
	.byte	0x1
	.word	0x132
	.byte	0x5
	.ascii "_Z7vsscanfPKcS0_Pc\0"
	.long	0x2be
	.long	0xa03
	.uleb128 0xf
	.long	0x4d2
	.uleb128 0xf
	.long	0x4d2
	.uleb128 0xf
	.long	0x249
	.byte	0
	.uleb128 0x19
	.byte	0x2
	.byte	0x3
	.byte	0x11
	.long	0x85
	.uleb128 0x1a
	.ascii "maxn\0"
	.byte	0x2
	.byte	0x5
	.byte	0xb
	.long	0x2c5
	.uleb128 0x9
	.byte	0x3
	.quad	_ZL4maxn
	.uleb128 0x1b
	.long	0x261
	.long	0xa35
	.uleb128 0x1c
	.long	0x27d
	.long	0x1ffff
	.byte	0
	.uleb128 0x1d
	.ascii "buffer\0"
	.byte	0x2
	.byte	0x7
	.byte	0x6
	.long	0xa22
	.uleb128 0x9
	.byte	0x3
	.quad	buffer
	.uleb128 0x1d
	.ascii "S\0"
	.byte	0x2
	.byte	0x7
	.byte	0x15
	.long	0x2d6
	.uleb128 0x9
	.byte	0x3
	.quad	S
	.uleb128 0x1d
	.ascii "T\0"
	.byte	0x2
	.byte	0x7
	.byte	0x19
	.long	0x2d6
	.uleb128 0x9
	.byte	0x3
	.quad	T
	.uleb128 0x1e
	.ascii "main\0"
	.byte	0x2
	.byte	0x1d
	.byte	0x5
	.long	0x2be
	.quad	.LFB46
	.quad	.LFE46-.LFB46
	.uleb128 0x1
	.byte	0x9c
	.long	0xaa7
	.uleb128 0x1a
	.ascii "a\0"
	.byte	0x2
	.byte	0x1f
	.byte	0x6
	.long	0x2be
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.byte	0
	.uleb128 0x1f
	.ascii "Get_Int\0"
	.byte	0x2
	.byte	0x12
	.byte	0x5
	.ascii "_Z7Get_Intv\0"
	.long	0x2be
	.quad	.LFB45
	.quad	.LFE45-.LFB45
	.uleb128 0x1
	.byte	0x9c
	.long	0xaf5
	.uleb128 0x1a
	.ascii "c\0"
	.byte	0x2
	.byte	0x14
	.byte	0x7
	.long	0x261
	.uleb128 0x2
	.byte	0x91
	.sleb128 -17
	.uleb128 0x1a
	.ascii "re\0"
	.byte	0x2
	.byte	0x15
	.byte	0x6
	.long	0x2be
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
	.uleb128 0x1f
	.ascii "Get_Char\0"
	.byte	0x2
	.byte	0x8
	.byte	0x6
	.ascii "_Z8Get_Charv\0"
	.long	0x261
	.quad	.LFB44
	.quad	.LFE44-.LFB44
	.uleb128 0x1
	.byte	0x9c
	.long	0xb37
	.uleb128 0x18
	.quad	.LVL1
	.long	0xb37
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
	.uleb128 0x3a
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
	.uleb128 0x1a
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
	.uleb128 0x1b
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1c
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0x6
	.byte	0
	.byte	0
	.uleb128 0x1d
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
	.quad	.LFB8
	.quad	.LFE8-.LFB8
	.quad	0
	.quad	0
	.section	.debug_ranges,"dr"
.Ldebug_ranges0:
	.quad	.Ltext0
	.quad	.Letext0
	.quad	.LFB8
	.quad	.LFE8
	.quad	0
	.quad	0
	.section	.debug_line,"dr"
.Ldebug_line0:
	.section	.debug_str,"dr"
.LASF0:
	.ascii "__acrt_iob_func\0"
	.ident	"GCC: (x86_64-win32-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	__mingw_vfprintf;	.scl	2;	.type	32;	.endef
	.def	fread;	.scl	2;	.type	32;	.endef
