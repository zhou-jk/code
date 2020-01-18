
../code/C++/01背包问题/19_1_DP.cpp/../19_1_DP.o:     file format pe-x86-64


Disassembly of section .text:

0000000000000000 <main>:
main():
E:\OI-Files/../code/C++/01背包问题/19_1_DP.cpp:11

const int M = 200;
int f[M + 1];

int main()
{
   0:	55                   	push   %rbp
   1:	48 89 e5             	mov    %rsp,%rbp
   4:	48 83 ec 40          	sub    $0x40,%rsp
   8:	e8 00 00 00 00       	callq  d <main+0xd>
E:\OI-Files/../code/C++/01背包问题/19_1_DP.cpp:13
	int m, n;
	scanf("%d%d", &m, &n);
   d:	48 8d 55 ec          	lea    -0x14(%rbp),%rdx
  11:	48 8d 45 f0          	lea    -0x10(%rbp),%rax
  15:	49 89 d0             	mov    %rdx,%r8
  18:	48 89 c2             	mov    %rax,%rdx
  1b:	48 8d 0d 04 00 00 00 	lea    0x4(%rip),%rcx        # 26 <main+0x26>
  22:	e8 00 00 00 00       	callq  27 <main+0x27>
E:\OI-Files/../code/C++/01背包问题/19_1_DP.cpp:14
	for (int i = 0; i < n; ++i)
  27:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
  2e:	8b 45 ec             	mov    -0x14(%rbp),%eax
  31:	39 45 fc             	cmp    %eax,-0x4(%rbp)
  34:	0f 8d 9a 00 00 00    	jge    d4 <main+0xd4>
E:\OI-Files/../code/C++/01背包问题/19_1_DP.cpp:17
	{
		int w, c;
		scanf("%d%d", &w, &c);
  3a:	48 8d 55 e4          	lea    -0x1c(%rbp),%rdx
  3e:	48 8d 45 e8          	lea    -0x18(%rbp),%rax
  42:	49 89 d0             	mov    %rdx,%r8
  45:	48 89 c2             	mov    %rax,%rdx
  48:	48 8d 0d 04 00 00 00 	lea    0x4(%rip),%rcx        # 53 <main+0x53>
  4f:	e8 00 00 00 00       	callq  54 <main+0x54>
E:\OI-Files/../code/C++/01背包问题/19_1_DP.cpp:18
		for (int j = m; j >= w; --j) f[j] = max(f[j], f[j - w] + c);
  54:	8b 45 f0             	mov    -0x10(%rbp),%eax
  57:	89 45 f8             	mov    %eax,-0x8(%rbp)
  5a:	8b 45 e8             	mov    -0x18(%rbp),%eax
  5d:	39 45 f8             	cmp    %eax,-0x8(%rbp)
  60:	7c 69                	jl     cb <main+0xcb>
  62:	8b 45 e8             	mov    -0x18(%rbp),%eax
  65:	8b 55 f8             	mov    -0x8(%rbp),%edx
  68:	29 c2                	sub    %eax,%edx
  6a:	89 d0                	mov    %edx,%eax
  6c:	48 98                	cltq   
  6e:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
  75:	00 
  76:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # 7d <main+0x7d>
  7d:	8b 14 02             	mov    (%rdx,%rax,1),%edx
  80:	8b 45 e4             	mov    -0x1c(%rbp),%eax
  83:	01 d0                	add    %edx,%eax
  85:	89 45 f4             	mov    %eax,-0xc(%rbp)
  88:	8b 45 f8             	mov    -0x8(%rbp),%eax
  8b:	48 98                	cltq   
  8d:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
  94:	00 
  95:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # 9c <main+0x9c>
  9c:	48 8d 0c 02          	lea    (%rdx,%rax,1),%rcx
  a0:	48 8d 45 f4          	lea    -0xc(%rbp),%rax
  a4:	48 89 c2             	mov    %rax,%rdx
  a7:	e8 00 00 00 00       	callq  ac <main+0xac>
  ac:	8b 08                	mov    (%rax),%ecx
  ae:	8b 45 f8             	mov    -0x8(%rbp),%eax
  b1:	48 98                	cltq   
  b3:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
  ba:	00 
  bb:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # c2 <main+0xc2>
  c2:	89 0c 02             	mov    %ecx,(%rdx,%rax,1)
  c5:	83 6d f8 01          	subl   $0x1,-0x8(%rbp)
  c9:	eb 8f                	jmp    5a <main+0x5a>
E:\OI-Files/../code/C++/01背包问题/19_1_DP.cpp:14
	for (int i = 0; i < n; ++i)
  cb:	83 45 fc 01          	addl   $0x1,-0x4(%rbp)
  cf:	e9 5a ff ff ff       	jmpq   2e <main+0x2e>
E:\OI-Files/../code/C++/01背包问题/19_1_DP.cpp:20
	}
	printf("%d", f[m]);
  d4:	8b 45 f0             	mov    -0x10(%rbp),%eax
  d7:	48 98                	cltq   
  d9:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
  e0:	00 
  e1:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # e8 <main+0xe8>
  e8:	8b 04 02             	mov    (%rdx,%rax,1),%eax
  eb:	89 c2                	mov    %eax,%edx
  ed:	48 8d 0d 09 00 00 00 	lea    0x9(%rip),%rcx        # fd <main+0xfd>
  f4:	e8 00 00 00 00       	callq  f9 <main+0xf9>
E:\OI-Files/../code/C++/01背包问题/19_1_DP.cpp:21
	return 0;
  f9:	b8 00 00 00 00       	mov    $0x0,%eax
E:\OI-Files/../code/C++/01背包问题/19_1_DP.cpp:22
  fe:	48 83 c4 40          	add    $0x40,%rsp
 102:	5d                   	pop    %rbp
 103:	c3                   	retq   
 104:	90                   	nop
 105:	90                   	nop
 106:	90                   	nop
 107:	90                   	nop
 108:	90                   	nop
 109:	90                   	nop
 10a:	90                   	nop
 10b:	90                   	nop
 10c:	90                   	nop
 10d:	90                   	nop
 10e:	90                   	nop
 10f:	90                   	nop

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

Disassembly of section .text$_ZSt3maxIiERKT_S2_S2_:

0000000000000000 <_ZSt3maxIiERKT_S2_S2_>:
_ZSt3maxIiERKT_S2_S2_():
C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/stl_algobase.h:219
   *  preprocessor macro.
  */
  template<typename _Tp>
    _GLIBCXX14_CONSTEXPR
    inline const _Tp&
    max(const _Tp& __a, const _Tp& __b)
   0:	55                   	push   %rbp
   1:	48 89 e5             	mov    %rsp,%rbp
   4:	48 89 4d 10          	mov    %rcx,0x10(%rbp)
   8:	48 89 55 18          	mov    %rdx,0x18(%rbp)
C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/stl_algobase.h:224
    {
      // concept requirements
      __glibcxx_function_requires(_LessThanComparableConcept<_Tp>)
      //return  __a < __b ? __b : __a;
      if (__a < __b)
   c:	48 8b 45 10          	mov    0x10(%rbp),%rax
  10:	8b 10                	mov    (%rax),%edx
  12:	48 8b 45 18          	mov    0x18(%rbp),%rax
  16:	8b 00                	mov    (%rax),%eax
  18:	39 c2                	cmp    %eax,%edx
  1a:	7d 06                	jge    22 <_ZSt3maxIiERKT_S2_S2_+0x22>
C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/stl_algobase.h:225
	return __b;
  1c:	48 8b 45 18          	mov    0x18(%rbp),%rax
  20:	eb 04                	jmp    26 <_ZSt3maxIiERKT_S2_S2_+0x26>
C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/stl_algobase.h:226
      return __a;
  22:	48 8b 45 10          	mov    0x10(%rbp),%rax
C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/stl_algobase.h:227
    }
  26:	5d                   	pop    %rbp
  27:	c3                   	retq   
  28:	90                   	nop
  29:	90                   	nop
  2a:	90                   	nop
  2b:	90                   	nop
  2c:	90                   	nop
  2d:	90                   	nop
  2e:	90                   	nop
  2f:	90                   	nop
19_1_DP.cpp:
typedef void void;
void f /* 0x0 */;
void __imp___acrt_iob_func /* 0x0 */;
