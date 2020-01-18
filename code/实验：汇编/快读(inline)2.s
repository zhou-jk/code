
C++/实验：汇编/快读(inline).cpp/../快读(inline).o:     file format pe-x86-64


Disassembly of section .text:

0000000000000000 <main>:
		re = (re << 1) + (re << 3) + (c - '0'), c = Get_Char();
	return re;
}

int main()
{
   0:	55                   	push   %rbp
   1:	48 89 e5             	mov    %rsp,%rbp
   4:	48 83 ec 30          	sub    $0x30,%rsp
   8:	e8 00 00 00 00       	callq  d <main+0xd>
	int a = Get_Int();
   d:	e8 00 00 00 00       	callq  12 <main+0x12>
  12:	89 45 fc             	mov    %eax,-0x4(%rbp)
	printf("%d", a);
  15:	8b 45 fc             	mov    -0x4(%rbp),%eax
  18:	89 c2                	mov    %eax,%edx
  1a:	48 8d 0d 04 00 00 00 	lea    0x4(%rip),%rcx        # 25 <main+0x25>
  21:	e8 00 00 00 00       	callq  26 <main+0x26>
	return 0;
  26:	b8 00 00 00 00       	mov    $0x0,%eax
  2b:	48 83 c4 30          	add    $0x30,%rsp
  2f:	5d                   	pop    %rbp
  30:	c3                   	retq   
		T = (S = buffer) + fread(buffer, 1, maxn, stdin);
  31:	90                   	nop
  32:	90                   	nop
  33:	90                   	nop
  34:	90                   	nop
  35:	90                   	nop
  36:	90                   	nop
  37:	90                   	nop
  38:	90                   	nop
  39:	90                   	nop
  3a:	90                   	nop
  3b:	90                   	nop
  3c:	90                   	nop
  3d:	90                   	nop
  3e:	90                   	nop
  3f:	90                   	nop

Disassembly of section .text$_Z6printfPKcz:

0000000000000000 <_Z6printfPKcz>:
}

__mingw_ovr
__attribute__((__format__ (gnu_printf, 1, 2))) __MINGW_ATTRIB_NONNULL(1)
int printf (const char *__format, ...)
{
   0:	55                   	push   %rbp
   1:	53                   	push   %rbx
   2:	48 83 ec 38          	sub    $0x38,%rsp
   6:	48 8d ac 24 80 00 00 	lea    0x80(%rsp),%rbp
   d:	00 
   e:	48 89 4d d0          	mov    %rcx,-0x30(%rbp)
  12:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
  16:	4c 89 45 e0          	mov    %r8,-0x20(%rbp)
  1a:	4c 89 4d e8          	mov    %r9,-0x18(%rbp)
  int __retval;
  __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
  1e:	48 8d 45 d8          	lea    -0x28(%rbp),%rax
  22:	48 89 45 a0          	mov    %rax,-0x60(%rbp)
  __retval = __mingw_vfprintf( stdout, __format, __local_argv );
  26:	48 8b 5d a0          	mov    -0x60(%rbp),%rbx
  2a:	b9 01 00 00 00       	mov    $0x1,%ecx
  2f:	48 8b 05 00 00 00 00 	mov    0x0(%rip),%rax        # 36 <_Z6printfPKcz+0x36>
  36:	ff d0                	callq  *%rax
  38:	49 89 d8             	mov    %rbx,%r8
  3b:	48 8b 55 d0          	mov    -0x30(%rbp),%rdx
  3f:	48 89 c1             	mov    %rax,%rcx
  42:	e8 00 00 00 00       	callq  47 <_Z6printfPKcz+0x47>
  47:	89 45 ac             	mov    %eax,-0x54(%rbp)
  __builtin_va_end( __local_argv );
  return __retval;
  4a:	8b 45 ac             	mov    -0x54(%rbp),%eax
}
  4d:	48 83 c4 38          	add    $0x38,%rsp
  51:	5b                   	pop    %rbx
  52:	5d                   	pop    %rbp
  53:	c3                   	retq   
  54:	90                   	nop
  55:	90                   	nop
  56:	90                   	nop
  57:	90                   	nop
  58:	90                   	nop
  59:	90                   	nop
  5a:	90                   	nop
  5b:	90                   	nop
  5c:	90                   	nop
  5d:	90                   	nop
  5e:	90                   	nop
  5f:	90                   	nop

Disassembly of section .text$_Z8Get_Charv:

0000000000000000 <_Z8Get_Charv>:
{
   0:	55                   	push   %rbp
   1:	53                   	push   %rbx
   2:	48 83 ec 28          	sub    $0x28,%rsp
   6:	48 8d ac 24 80 00 00 	lea    0x80(%rsp),%rbp
   d:	00 
	if (S == T)
   e:	48 8b 15 00 00 02 00 	mov    0x20000(%rip),%rdx        # 20015 <T+0xd>
  15:	48 8b 05 08 00 02 00 	mov    0x20008(%rip),%rax        # 20024 <T+0x1c>
  1c:	48 39 c2             	cmp    %rax,%rdx
  1f:	75 61                	jne    82 <_Z8Get_Charv+0x82>
		T = (S = buffer) + fread(buffer, 1, maxn, stdin);
  21:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # 28 <_Z8Get_Charv+0x28>
  28:	48 89 05 00 00 02 00 	mov    %rax,0x20000(%rip)        # 2002f <T+0x27>
  2f:	48 8b 1d 00 00 02 00 	mov    0x20000(%rip),%rbx        # 20036 <T+0x2e>
  36:	b9 00 00 00 00       	mov    $0x0,%ecx
  3b:	48 8b 05 00 00 00 00 	mov    0x0(%rip),%rax        # 42 <_Z8Get_Charv+0x42>
  42:	ff d0                	callq  *%rax
  44:	49 89 c1             	mov    %rax,%r9
  47:	41 b8 00 00 02 00    	mov    $0x20000,%r8d
  4d:	ba 01 00 00 00       	mov    $0x1,%edx
  52:	48 8d 0d 00 00 00 00 	lea    0x0(%rip),%rcx        # 59 <_Z8Get_Charv+0x59>
  59:	e8 00 00 00 00       	callq  5e <_Z8Get_Charv+0x5e>
  5e:	48 01 d8             	add    %rbx,%rax
  61:	48 89 05 08 00 02 00 	mov    %rax,0x20008(%rip)        # 20070 <T+0x68>
		if (S == T) return EOF;
  68:	48 8b 15 00 00 02 00 	mov    0x20000(%rip),%rdx        # 2006f <T+0x67>
  6f:	48 8b 05 08 00 02 00 	mov    0x20008(%rip),%rax        # 2007e <T+0x76>
  76:	48 39 c2             	cmp    %rax,%rdx
  79:	75 07                	jne    82 <_Z8Get_Charv+0x82>
  7b:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  80:	eb 15                	jmp    97 <_Z8Get_Charv+0x97>
	return *S++;
  82:	48 8b 05 00 00 02 00 	mov    0x20000(%rip),%rax        # 20089 <T+0x81>
  89:	48 8d 50 01          	lea    0x1(%rax),%rdx
  8d:	48 89 15 00 00 02 00 	mov    %rdx,0x20000(%rip)        # 20094 <T+0x8c>
  94:	0f b6 00             	movzbl (%rax),%eax
}
  97:	48 83 c4 28          	add    $0x28,%rsp
  9b:	5b                   	pop    %rbx
  9c:	5d                   	pop    %rbp
  9d:	c3                   	retq   
  9e:	90                   	nop
  9f:	90                   	nop

Disassembly of section .text$_Z7Get_Intv:

0000000000000000 <_Z7Get_Intv>:
{
   0:	55                   	push   %rbp
   1:	48 89 e5             	mov    %rsp,%rbp
   4:	48 83 ec 30          	sub    $0x30,%rsp
	int re = 0;
   8:	c7 45 f8 00 00 00 00 	movl   $0x0,-0x8(%rbp)
	for (c = Get_Char(); c < '0' || c > '9'; c = Get_Char())
   f:	e8 00 00 00 00       	callq  14 <_Z7Get_Intv+0x14>
  14:	88 45 ff             	mov    %al,-0x1(%rbp)
  17:	80 7d ff 2f          	cmpb   $0x2f,-0x1(%rbp)
  1b:	7e 06                	jle    23 <_Z7Get_Intv+0x23>
  1d:	80 7d ff 39          	cmpb   $0x39,-0x1(%rbp)
  21:	7e 0a                	jle    2d <_Z7Get_Intv+0x2d>
  23:	e8 00 00 00 00       	callq  28 <_Z7Get_Intv+0x28>
  28:	88 45 ff             	mov    %al,-0x1(%rbp)
  2b:	eb ea                	jmp    17 <_Z7Get_Intv+0x17>
	while (c >= '0' && c <= '9')
  2d:	80 7d ff 2f          	cmpb   $0x2f,-0x1(%rbp)
  31:	7e 2a                	jle    5d <_Z7Get_Intv+0x5d>
  33:	80 7d ff 39          	cmpb   $0x39,-0x1(%rbp)
  37:	7f 24                	jg     5d <_Z7Get_Intv+0x5d>
		re = (re << 1) + (re << 3) + (c - '0'), c = Get_Char();
  39:	8b 45 f8             	mov    -0x8(%rbp),%eax
  3c:	8d 14 00             	lea    (%rax,%rax,1),%edx
  3f:	8b 45 f8             	mov    -0x8(%rbp),%eax
  42:	c1 e0 03             	shl    $0x3,%eax
  45:	01 c2                	add    %eax,%edx
  47:	0f be 45 ff          	movsbl -0x1(%rbp),%eax
  4b:	83 e8 30             	sub    $0x30,%eax
  4e:	01 d0                	add    %edx,%eax
  50:	89 45 f8             	mov    %eax,-0x8(%rbp)
  53:	e8 00 00 00 00       	callq  58 <_Z7Get_Intv+0x58>
  58:	88 45 ff             	mov    %al,-0x1(%rbp)
	while (c >= '0' && c <= '9')
  5b:	eb d0                	jmp    2d <_Z7Get_Intv+0x2d>
	return re;
  5d:	8b 45 f8             	mov    -0x8(%rbp),%eax
}
  60:	48 83 c4 30          	add    $0x30,%rsp
  64:	5d                   	pop    %rbp
  65:	c3                   	retq   
  66:	90                   	nop
  67:	90                   	nop
  68:	90                   	nop
  69:	90                   	nop
  6a:	90                   	nop
  6b:	90                   	nop
  6c:	90                   	nop
  6d:	90                   	nop
  6e:	90                   	nop
  6f:	90                   	nop
