
..\..\code\code\实验：汇编\快读.cpp/../快读.o:     file format pe-x86-64


Disassembly of section .text:

0000000000000000 <_Z8Get_Charv>:
_Z8Get_Charv():
e:\yz\一中/../../code/code/实验：汇编/快读.cpp:9

const int maxn = 2 << 16;

char buffer[maxn], *S, *T;
char Get_Char()
{
   0:	55                   	push   %rbp
   1:	53                   	push   %rbx
   2:	48 83 ec 28          	sub    $0x28,%rsp
   6:	48 8d ac 24 80 00 00 	lea    0x80(%rsp),%rbp
   d:	00 
e:\yz\一中/../../code/code/实验：汇编/快读.cpp:10
	if (S == T)
   e:	48 8b 15 00 00 02 00 	mov    0x20000(%rip),%rdx        # 20015 <T+0xd>
  15:	48 8b 05 08 00 02 00 	mov    0x20008(%rip),%rax        # 20024 <T+0x1c>
  1c:	48 39 c2             	cmp    %rax,%rdx
  1f:	75 61                	jne    82 <_Z8Get_Charv+0x82>
e:\yz\一中/../../code/code/实验：汇编/快读.cpp:12
	{
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
e:\yz\一中/../../code/code/实验：汇编/快读.cpp:13
		if (S == T) return EOF;
  68:	48 8b 15 00 00 02 00 	mov    0x20000(%rip),%rdx        # 2006f <T+0x67>
  6f:	48 8b 05 08 00 02 00 	mov    0x20008(%rip),%rax        # 2007e <T+0x76>
  76:	48 39 c2             	cmp    %rax,%rdx
  79:	75 07                	jne    82 <_Z8Get_Charv+0x82>
  7b:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  80:	eb 15                	jmp    97 <_Z8Get_Charv+0x97>
e:\yz\一中/../../code/code/实验：汇编/快读.cpp:15
	}
	return *S++;
  82:	48 8b 05 00 00 02 00 	mov    0x20000(%rip),%rax        # 20089 <T+0x81>
  89:	48 8d 50 01          	lea    0x1(%rax),%rdx
  8d:	48 89 15 00 00 02 00 	mov    %rdx,0x20000(%rip)        # 20094 <T+0x8c>
  94:	0f b6 00             	movzbl (%rax),%eax
e:\yz\一中/../../code/code/实验：汇编/快读.cpp:16
}
  97:	48 83 c4 28          	add    $0x28,%rsp
  9b:	5b                   	pop    %rbx
  9c:	5d                   	pop    %rbp
  9d:	c3                   	retq   

000000000000009e <_Z7Get_Intv>:
_Z7Get_Intv():
e:\yz\一中/../../code/code/实验：汇编/快读.cpp:19

int Get_Int()
{
  9e:	55                   	push   %rbp
  9f:	48 89 e5             	mov    %rsp,%rbp
  a2:	48 83 ec 30          	sub    $0x30,%rsp
e:\yz\一中/../../code/code/实验：汇编/快读.cpp:21
	char c;
	int re = 0;
  a6:	c7 45 f8 00 00 00 00 	movl   $0x0,-0x8(%rbp)
e:\yz\一中/../../code/code/实验：汇编/快读.cpp:22
	for (c = Get_Char(); c < '0' || c > '9'; c = Get_Char())
  ad:	e8 4e ff ff ff       	callq  0 <_Z8Get_Charv>
  b2:	88 45 ff             	mov    %al,-0x1(%rbp)
  b5:	80 7d ff 2f          	cmpb   $0x2f,-0x1(%rbp)
  b9:	7e 06                	jle    c1 <_Z7Get_Intv+0x23>
  bb:	80 7d ff 39          	cmpb   $0x39,-0x1(%rbp)
  bf:	7e 0a                	jle    cb <_Z7Get_Intv+0x2d>
  c1:	e8 3a ff ff ff       	callq  0 <_Z8Get_Charv>
  c6:	88 45 ff             	mov    %al,-0x1(%rbp)
  c9:	eb ea                	jmp    b5 <_Z7Get_Intv+0x17>
e:\yz\一中/../../code/code/实验：汇编/快读.cpp:24
		;
	while (c >= '0' && c <= '9')
  cb:	80 7d ff 2f          	cmpb   $0x2f,-0x1(%rbp)
  cf:	7e 2a                	jle    fb <_Z7Get_Intv+0x5d>
  d1:	80 7d ff 39          	cmpb   $0x39,-0x1(%rbp)
  d5:	7f 24                	jg     fb <_Z7Get_Intv+0x5d>
e:\yz\一中/../../code/code/实验：汇编/快读.cpp:25
		re = (re << 1) + (re << 3) + (c - '0'), c = Get_Char();
  d7:	8b 45 f8             	mov    -0x8(%rbp),%eax
  da:	8d 14 00             	lea    (%rax,%rax,1),%edx
  dd:	8b 45 f8             	mov    -0x8(%rbp),%eax
  e0:	c1 e0 03             	shl    $0x3,%eax
  e3:	01 c2                	add    %eax,%edx
  e5:	0f be 45 ff          	movsbl -0x1(%rbp),%eax
  e9:	83 e8 30             	sub    $0x30,%eax
  ec:	01 d0                	add    %edx,%eax
  ee:	89 45 f8             	mov    %eax,-0x8(%rbp)
  f1:	e8 0a ff ff ff       	callq  0 <_Z8Get_Charv>
  f6:	88 45 ff             	mov    %al,-0x1(%rbp)
e:\yz\一中/../../code/code/实验：汇编/快读.cpp:24
	while (c >= '0' && c <= '9')
  f9:	eb d0                	jmp    cb <_Z7Get_Intv+0x2d>
e:\yz\一中/../../code/code/实验：汇编/快读.cpp:26
	return re;
  fb:	8b 45 f8             	mov    -0x8(%rbp),%eax
e:\yz\一中/../../code/code/实验：汇编/快读.cpp:27
}
  fe:	48 83 c4 30          	add    $0x30,%rsp
 102:	5d                   	pop    %rbp
 103:	c3                   	retq   

0000000000000104 <main>:
main():
e:\yz\一中/../../code/code/实验：汇编/快读.cpp:30

int main()
{
 104:	55                   	push   %rbp
 105:	48 89 e5             	mov    %rsp,%rbp
 108:	48 83 ec 30          	sub    $0x30,%rsp
 10c:	e8 00 00 00 00       	callq  111 <main+0xd>
e:\yz\一中/../../code/code/实验：汇编/快读.cpp:31
	int a = Get_Int();
 111:	e8 88 ff ff ff       	callq  9e <_Z7Get_Intv>
 116:	89 45 fc             	mov    %eax,-0x4(%rbp)
e:\yz\一中/../../code/code/实验：汇编/快读.cpp:32
	printf("%d", a);
 119:	8b 45 fc             	mov    -0x4(%rbp),%eax
 11c:	89 c2                	mov    %eax,%edx
 11e:	48 8d 0d 04 00 00 00 	lea    0x4(%rip),%rcx        # 129 <main+0x25>
 125:	e8 00 00 00 00       	callq  12a <main+0x26>
e:\yz\一中/../../code/code/实验：汇编/快读.cpp:33
	return 0;
 12a:	b8 00 00 00 00       	mov    $0x0,%eax
e:\yz\一中/../../code/code/实验：汇编/快读.cpp:34
 12f:	48 83 c4 30          	add    $0x30,%rsp
 133:	5d                   	pop    %rbp
 134:	c3                   	retq   
 135:	90                   	nop
 136:	90                   	nop
 137:	90                   	nop
 138:	90                   	nop
 139:	90                   	nop
 13a:	90                   	nop
 13b:	90                   	nop
 13c:	90                   	nop
 13d:	90                   	nop
 13e:	90                   	nop
 13f:	90                   	nop

Disassembly of section .text$_Z6printfPKcz:

0000000000000000 <_Z6printfPKcz>:
_Z6printfPKcz():
C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include/stdio.h:346
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
C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include/stdio.h:348
  int __retval;
  __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
  1e:	48 8d 45 d8          	lea    -0x28(%rbp),%rax
  22:	48 89 45 a0          	mov    %rax,-0x60(%rbp)
C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include/stdio.h:349
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
C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include/stdio.h:351
  __builtin_va_end( __local_argv );
  return __retval;
  4a:	8b 45 ac             	mov    -0x54(%rbp),%eax
C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include/stdio.h:352
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
快读.cpp:
typedef void void;
void buffer /* 0x0 */;
void S /* 0x20000 */;
void T /* 0x20008 */;
void __imp___acrt_iob_func /* 0x0 */;
