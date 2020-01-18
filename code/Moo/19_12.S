
C++/Moo/19_1.cpp/../19_1.o:     file format pe-x86-64


Disassembly of section .text:

0000000000000000 <_Z5solveii>:
_Z5solveii():
E:\code/C++/Moo/19_1.cpp:7

const int N = 31;
int f[N];

char solve(int s, int k)
{
   0:	55                   	push   %rbp
   1:	48 89 e5             	mov    %rsp,%rbp
   4:	48 83 ec 30          	sub    $0x30,%rsp
   8:	89 4d 10             	mov    %ecx,0x10(%rbp)
   b:	89 55 18             	mov    %edx,0x18(%rbp)
E:\code/C++/Moo/19_1.cpp:8
	if (k <= f[s - 1]) return solve(s - 1, k);
   e:	8b 45 10             	mov    0x10(%rbp),%eax
  11:	83 e8 01             	sub    $0x1,%eax
  14:	48 98                	cltq   
  16:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
  1d:	00 
  1e:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # 25 <_Z5solveii+0x25>
  25:	8b 04 02             	mov    (%rdx,%rax,1),%eax
  28:	39 45 18             	cmp    %eax,0x18(%rbp)
  2b:	7f 12                	jg     3f <_Z5solveii+0x3f>
  2d:	8b 45 10             	mov    0x10(%rbp),%eax
  30:	83 e8 01             	sub    $0x1,%eax
  33:	8b 55 18             	mov    0x18(%rbp),%edx
  36:	89 c1                	mov    %eax,%ecx
  38:	e8 c3 ff ff ff       	callq  0 <_Z5solveii>
  3d:	eb 5c                	jmp    9b <_Z5solveii+0x9b>
E:\code/C++/Moo/19_1.cpp:9
	int tmp = k - f[s - 1];
  3f:	8b 45 10             	mov    0x10(%rbp),%eax
  42:	83 e8 01             	sub    $0x1,%eax
  45:	48 98                	cltq   
  47:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
  4e:	00 
  4f:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # 56 <_Z5solveii+0x56>
  56:	8b 04 02             	mov    (%rdx,%rax,1),%eax
  59:	8b 55 18             	mov    0x18(%rbp),%edx
  5c:	29 c2                	sub    %eax,%edx
  5e:	89 d0                	mov    %edx,%eax
  60:	89 45 fc             	mov    %eax,-0x4(%rbp)
E:\code/C++/Moo/19_1.cpp:10
	if (tmp <= s + 3) return tmp == 1 ? 'm' : 'o';
  63:	8b 45 10             	mov    0x10(%rbp),%eax
  66:	83 c0 03             	add    $0x3,%eax
  69:	39 45 fc             	cmp    %eax,-0x4(%rbp)
  6c:	7f 14                	jg     82 <_Z5solveii+0x82>
  6e:	83 7d fc 01          	cmpl   $0x1,-0x4(%rbp)
  72:	75 07                	jne    7b <_Z5solveii+0x7b>
  74:	b8 6d 00 00 00       	mov    $0x6d,%eax
  79:	eb 20                	jmp    9b <_Z5solveii+0x9b>
  7b:	b8 6f 00 00 00       	mov    $0x6f,%eax
  80:	eb 19                	jmp    9b <_Z5solveii+0x9b>
E:\code/C++/Moo/19_1.cpp:11
	return solve(s - 1, tmp - (s + 3));
  82:	8b 45 10             	mov    0x10(%rbp),%eax
  85:	83 c0 03             	add    $0x3,%eax
  88:	8b 55 fc             	mov    -0x4(%rbp),%edx
  8b:	29 c2                	sub    %eax,%edx
  8d:	8b 45 10             	mov    0x10(%rbp),%eax
  90:	83 e8 01             	sub    $0x1,%eax
  93:	89 c1                	mov    %eax,%ecx
  95:	e8 66 ff ff ff       	callq  0 <_Z5solveii>
  9a:	90                   	nop
E:\code/C++/Moo/19_1.cpp:12
}
  9b:	48 83 c4 30          	add    $0x30,%rsp
  9f:	5d                   	pop    %rbp
  a0:	c3                   	retq   

00000000000000a1 <main>:
main():
E:\code/C++/Moo/19_1.cpp:15

int main()
{
  a1:	55                   	push   %rbp
  a2:	48 89 e5             	mov    %rsp,%rbp
  a5:	48 83 ec 30          	sub    $0x30,%rsp
  a9:	e8 00 00 00 00       	callq  ae <main+0xd>
E:\code/C++/Moo/19_1.cpp:17
	int n;
	scanf("%d", &n);
  ae:	48 8d 45 f8          	lea    -0x8(%rbp),%rax
  b2:	48 89 c2             	mov    %rax,%rdx
  b5:	48 8d 0d 04 00 00 00 	lea    0x4(%rip),%rcx        # c0 <main+0x1f>
  bc:	e8 00 00 00 00       	callq  c1 <main+0x20>
E:\code/C++/Moo/19_1.cpp:18
	f[0] = 3;
  c1:	c7 05 fc ff ff ff 03 	movl   $0x3,-0x4(%rip)        # c7 <main+0x26>
  c8:	00 00 00 
E:\code/C++/Moo/19_1.cpp:20
	int i;
	for (i = 1; f[i - 1] < n; ++i) f[i] = i + 3 + (f[i - 1] << 1);
  cb:	c7 45 fc 01 00 00 00 	movl   $0x1,-0x4(%rbp)
  d2:	8b 45 fc             	mov    -0x4(%rbp),%eax
  d5:	83 e8 01             	sub    $0x1,%eax
  d8:	48 98                	cltq   
  da:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
  e1:	00 
  e2:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # e9 <main+0x48>
  e9:	8b 14 02             	mov    (%rdx,%rax,1),%edx
  ec:	8b 45 f8             	mov    -0x8(%rbp),%eax
  ef:	39 c2                	cmp    %eax,%edx
  f1:	7d 41                	jge    134 <main+0x93>
  f3:	8b 45 fc             	mov    -0x4(%rbp),%eax
  f6:	8d 48 03             	lea    0x3(%rax),%ecx
  f9:	8b 45 fc             	mov    -0x4(%rbp),%eax
  fc:	83 e8 01             	sub    $0x1,%eax
  ff:	48 98                	cltq   
 101:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
 108:	00 
 109:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # 110 <main+0x6f>
 110:	8b 04 02             	mov    (%rdx,%rax,1),%eax
 113:	01 c0                	add    %eax,%eax
 115:	01 c1                	add    %eax,%ecx
 117:	8b 45 fc             	mov    -0x4(%rbp),%eax
 11a:	48 98                	cltq   
 11c:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
 123:	00 
 124:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # 12b <main+0x8a>
 12b:	89 0c 02             	mov    %ecx,(%rdx,%rax,1)
 12e:	83 45 fc 01          	addl   $0x1,-0x4(%rbp)
 132:	eb 9e                	jmp    d2 <main+0x31>
E:\code/C++/Moo/19_1.cpp:21
	putchar(solve(i - 1, n));
 134:	8b 55 f8             	mov    -0x8(%rbp),%edx
 137:	8b 45 fc             	mov    -0x4(%rbp),%eax
 13a:	83 e8 01             	sub    $0x1,%eax
 13d:	89 c1                	mov    %eax,%ecx
 13f:	e8 bc fe ff ff       	callq  0 <_Z5solveii>
 144:	0f be c0             	movsbl %al,%eax
 147:	89 c1                	mov    %eax,%ecx
 149:	e8 00 00 00 00       	callq  14e <main+0xad>
E:\code/C++/Moo/19_1.cpp:22
	return 0;
 14e:	b8 00 00 00 00       	mov    $0x0,%eax
E:\code/C++/Moo/19_1.cpp:23
 153:	48 83 c4 30          	add    $0x30,%rsp
 157:	5d                   	pop    %rbp
 158:	c3                   	retq   
 159:	90                   	nop
 15a:	90                   	nop
 15b:	90                   	nop
 15c:	90                   	nop
 15d:	90                   	nop
 15e:	90                   	nop
 15f:	90                   	nop

Disassembly of section .text$_Z5scanfPKcz:

0000000000000000 <_Z5scanfPKcz>:
_Z5scanfPKcz():
C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include/stdio.h:279
}

__mingw_ovr
__attribute__((__format__ (gnu_scanf, 1, 2))) __MINGW_ATTRIB_NONNULL(1)
int scanf(const char *__format, ...)
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
C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include/stdio.h:281
  int __retval;
  __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
  1e:	48 8d 45 d8          	lea    -0x28(%rbp),%rax
  22:	48 89 45 a0          	mov    %rax,-0x60(%rbp)
C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include/stdio.h:282
  __retval = __mingw_vfscanf( stdin, __format, __local_argv );
  26:	48 8b 5d a0          	mov    -0x60(%rbp),%rbx
  2a:	b9 00 00 00 00       	mov    $0x0,%ecx
  2f:	48 8b 05 00 00 00 00 	mov    0x0(%rip),%rax        # 36 <_Z5scanfPKcz+0x36>
  36:	ff d0                	callq  *%rax
  38:	49 89 d8             	mov    %rbx,%r8
  3b:	48 8b 55 d0          	mov    -0x30(%rbp),%rdx
  3f:	48 89 c1             	mov    %rax,%rcx
  42:	e8 00 00 00 00       	callq  47 <_Z5scanfPKcz+0x47>
  47:	89 45 ac             	mov    %eax,-0x54(%rbp)
C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include/stdio.h:284
  __builtin_va_end( __local_argv );
  return __retval;
  4a:	8b 45 ac             	mov    -0x54(%rbp),%eax
C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include/stdio.h:285
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
19_1.cpp:
typedef void void;
void f /* 0x0 */;
void __imp___acrt_iob_func /* 0x0 */;
