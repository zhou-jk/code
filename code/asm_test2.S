
..\..\..\code\code\asm_test.cpp/../asm_test.o:     file format pe-x86-64


Disassembly of section .text:

0000000000000000 <main>:
main():
e:\OI-Files\yz\一中/../../../code/code/asm_test.cpp:4
#include <cstdio>
using namespace std;
const unsigned int P = 3;
int main() {
   0:	55                   	push   %rbp
   1:	48 89 e5             	mov    %rsp,%rbp
   4:	48 83 ec 30          	sub    $0x30,%rsp
   8:	e8 00 00 00 00       	callq  d <main+0xd>
e:\OI-Files\yz\一中/../../../code/code/asm_test.cpp:6
    unsigned a;
    scanf("%u", &a);
   d:	48 8d 45 f8          	lea    -0x8(%rbp),%rax
  11:	48 89 c2             	mov    %rax,%rdx
  14:	48 8d 0d 04 00 00 00 	lea    0x4(%rip),%rcx        # 1f <main+0x1f>
  1b:	e8 00 00 00 00       	callq  20 <main+0x20>
e:\OI-Files\yz\一中/../../../code/code/asm_test.cpp:7
    unsigned int b = a % P;
  20:	8b 4d f8             	mov    -0x8(%rbp),%ecx
  23:	ba ab aa aa aa       	mov    $0xaaaaaaab,%edx
  28:	89 c8                	mov    %ecx,%eax
  2a:	f7 e2                	mul    %edx
  2c:	89 d0                	mov    %edx,%eax
  2e:	d1 e8                	shr    %eax
  30:	89 45 fc             	mov    %eax,-0x4(%rbp)
  33:	8b 55 fc             	mov    -0x4(%rbp),%edx
  36:	89 d0                	mov    %edx,%eax
  38:	01 c0                	add    %eax,%eax
  3a:	01 d0                	add    %edx,%eax
  3c:	29 c1                	sub    %eax,%ecx
  3e:	89 c8                	mov    %ecx,%eax
  40:	89 45 fc             	mov    %eax,-0x4(%rbp)
e:\OI-Files\yz\一中/../../../code/code/asm_test.cpp:8
    printf("%u", b);
  43:	8b 45 fc             	mov    -0x4(%rbp),%eax
  46:	89 c2                	mov    %eax,%edx
  48:	48 8d 0d 04 00 00 00 	lea    0x4(%rip),%rcx        # 53 <main+0x53>
  4f:	e8 00 00 00 00       	callq  54 <main+0x54>
e:\OI-Files\yz\一中/../../../code/code/asm_test.cpp:9
  54:	b8 00 00 00 00       	mov    $0x0,%eax
  59:	48 83 c4 30          	add    $0x30,%rsp
  5d:	5d                   	pop    %rbp
  5e:	c3                   	retq   
  5f:	90                   	nop

Disassembly of section .text$_Z5scanfPKcz:

0000000000000000 <_Z5scanfPKcz>:
_Z5scanfPKcz():
C:/Compiler/MinGW64/x86_64-w64-mingw32/include/stdio.h:279
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
C:/Compiler/MinGW64/x86_64-w64-mingw32/include/stdio.h:281
  int __retval;
  __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
  1e:	48 8d 45 d8          	lea    -0x28(%rbp),%rax
  22:	48 89 45 a0          	mov    %rax,-0x60(%rbp)
C:/Compiler/MinGW64/x86_64-w64-mingw32/include/stdio.h:282
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
C:/Compiler/MinGW64/x86_64-w64-mingw32/include/stdio.h:284
  __builtin_va_end( __local_argv );
  return __retval;
  4a:	8b 45 ac             	mov    -0x54(%rbp),%eax
C:/Compiler/MinGW64/x86_64-w64-mingw32/include/stdio.h:285
}
  4d:	48 83 c4 38          	add    $0x38,%rsp
  51:	5b                   	pop    %rbx
  52:	5d                   	pop    %rbp
  53:	c3                   	retq   
_Z6printfPKcz():
C:/Compiler/MinGW64/x86_64-w64-mingw32/include/stdio.h:349
__attribute__((__format__ (gnu_printf, 1, 2))) __MINGW_ATTRIB_NONNULL(1)
int printf (const char *__format, ...)
{
  int __retval;
  __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
  __retval = __mingw_vfprintf( stdout, __format, __local_argv );
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
C:/Compiler/MinGW64/x86_64-w64-mingw32/include/stdio.h:346
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
C:/Compiler/MinGW64/x86_64-w64-mingw32/include/stdio.h:348
  __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
  1e:	48 8d 45 d8          	lea    -0x28(%rbp),%rax
  22:	48 89 45 a0          	mov    %rax,-0x60(%rbp)
C:/Compiler/MinGW64/x86_64-w64-mingw32/include/stdio.h:349
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
C:/Compiler/MinGW64/x86_64-w64-mingw32/include/stdio.h:351
  __builtin_va_end( __local_argv );
  return __retval;
  4a:	8b 45 ac             	mov    -0x54(%rbp),%eax
C:/Compiler/MinGW64/x86_64-w64-mingw32/include/stdio.h:352
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
asm_test.cpp:
typedef void void;
void __imp___acrt_iob_func /* 0x0 */;
