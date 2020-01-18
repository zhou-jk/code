
../code/C++/三角形/tria.cpp/../tria.o:     file format pe-x86-64


Disassembly of section .text:

0000000000000000 <_Z3dfsi>:
_Z3dfsi():
E:\OI-Files/../code/C++/三角形/tria.cpp:7

const int N = 22;
int f[N][N], s[N + 1], n, ans;

void dfs(int k)
{
   0:	55                   	push   %rbp
   1:	48 89 e5             	mov    %rsp,%rbp
   4:	48 83 ec 30          	sub    $0x30,%rsp
   8:	89 4d 10             	mov    %ecx,0x10(%rbp)
E:\OI-Files/../code/C++/三角形/tria.cpp:8
	if (k == n)
   b:	8b 05 fc 07 00 00    	mov    0x7fc(%rip),%eax        # 80d <ans+0xd>
  11:	39 45 10             	cmp    %eax,0x10(%rbp)
  14:	0f 85 e7 01 00 00    	jne    201 <_Z3dfsi+0x201>
E:\OI-Files/../code/C++/三角形/tria.cpp:10
	{
		int tmp = 0;
  1a:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
E:\OI-Files/../code/C++/三角形/tria.cpp:11
		for (int j = 0; j < n; ++j) tmp += f[0][j] ? 1 : -1;
  21:	c7 45 f8 00 00 00 00 	movl   $0x0,-0x8(%rbp)
  28:	8b 05 fc 07 00 00    	mov    0x7fc(%rip),%eax        # 82a <ans+0x2a>
  2e:	39 45 f8             	cmp    %eax,-0x8(%rbp)
  31:	7d 30                	jge    63 <_Z3dfsi+0x63>
  33:	8b 45 f8             	mov    -0x8(%rbp),%eax
  36:	48 98                	cltq   
  38:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
  3f:	00 
  40:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # 47 <_Z3dfsi+0x47>
  47:	8b 04 02             	mov    (%rdx,%rax,1),%eax
  4a:	85 c0                	test   %eax,%eax
  4c:	74 07                	je     55 <_Z3dfsi+0x55>
  4e:	b8 01 00 00 00       	mov    $0x1,%eax
  53:	eb 05                	jmp    5a <_Z3dfsi+0x5a>
  55:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  5a:	01 45 fc             	add    %eax,-0x4(%rbp)
  5d:	83 45 f8 01          	addl   $0x1,-0x8(%rbp)
  61:	eb c5                	jmp    28 <_Z3dfsi+0x28>
E:\OI-Files/../code/C++/三角形/tria.cpp:12
		if (tmp > s[n - 1] || tmp < -s[n - 1]) return;
  63:	8b 05 fc 07 00 00    	mov    0x7fc(%rip),%eax        # 865 <ans+0x65>
  69:	83 e8 01             	sub    $0x1,%eax
  6c:	48 98                	cltq   
  6e:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
  75:	00 
  76:	48 8d 05 a0 07 00 00 	lea    0x7a0(%rip),%rax        # 81d <ans+0x1d>
  7d:	8b 04 02             	mov    (%rdx,%rax,1),%eax
  80:	39 45 fc             	cmp    %eax,-0x4(%rbp)
  83:	0f 8f ca 01 00 00    	jg     253 <_Z3dfsi+0x253>
  89:	8b 05 fc 07 00 00    	mov    0x7fc(%rip),%eax        # 88b <ans+0x8b>
  8f:	83 e8 01             	sub    $0x1,%eax
  92:	48 98                	cltq   
  94:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
  9b:	00 
  9c:	48 8d 05 a0 07 00 00 	lea    0x7a0(%rip),%rax        # 843 <ans+0x43>
  a3:	8b 04 02             	mov    (%rdx,%rax,1),%eax
  a6:	f7 d8                	neg    %eax
  a8:	39 45 fc             	cmp    %eax,-0x4(%rbp)
  ab:	0f 8c a2 01 00 00    	jl     253 <_Z3dfsi+0x253>
E:\OI-Files/../code/C++/三角形/tria.cpp:13
		for (int i = 1; i < n; ++i)
  b1:	c7 45 f4 01 00 00 00 	movl   $0x1,-0xc(%rbp)
  b8:	8b 05 fc 07 00 00    	mov    0x7fc(%rip),%eax        # 8ba <ans+0xba>
  be:	39 45 f4             	cmp    %eax,-0xc(%rbp)
  c1:	0f 8d 29 01 00 00    	jge    1f0 <_Z3dfsi+0x1f0>
E:\OI-Files/../code/C++/三角形/tria.cpp:15
		{
			for (int j = 0; j < n - i; ++j)
  c7:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%rbp)
  ce:	8b 05 fc 07 00 00    	mov    0x7fc(%rip),%eax        # 8d0 <ans+0xd0>
  d4:	2b 45 f4             	sub    -0xc(%rbp),%eax
  d7:	39 45 f0             	cmp    %eax,-0x10(%rbp)
  da:	0f 8d b7 00 00 00    	jge    197 <_Z3dfsi+0x197>
E:\OI-Files/../code/C++/三角形/tria.cpp:17
			{
				f[i][j] = f[i - 1][j] ^ f[i - 1][j + 1];
  e0:	8b 45 f4             	mov    -0xc(%rbp),%eax
  e3:	8d 50 ff             	lea    -0x1(%rax),%edx
  e6:	8b 45 f0             	mov    -0x10(%rbp),%eax
  e9:	48 98                	cltq   
  eb:	48 63 d2             	movslq %edx,%rdx
  ee:	48 6b d2 16          	imul   $0x16,%rdx,%rdx
  f2:	48 01 d0             	add    %rdx,%rax
  f5:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
  fc:	00 
  fd:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # 104 <_Z3dfsi+0x104>
 104:	8b 0c 02             	mov    (%rdx,%rax,1),%ecx
 107:	8b 45 f4             	mov    -0xc(%rbp),%eax
 10a:	8d 50 ff             	lea    -0x1(%rax),%edx
 10d:	8b 45 f0             	mov    -0x10(%rbp),%eax
 110:	83 c0 01             	add    $0x1,%eax
 113:	48 98                	cltq   
 115:	48 63 d2             	movslq %edx,%rdx
 118:	48 6b d2 16          	imul   $0x16,%rdx,%rdx
 11c:	48 01 d0             	add    %rdx,%rax
 11f:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
 126:	00 
 127:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # 12e <_Z3dfsi+0x12e>
 12e:	8b 04 02             	mov    (%rdx,%rax,1),%eax
 131:	31 c1                	xor    %eax,%ecx
 133:	8b 45 f0             	mov    -0x10(%rbp),%eax
 136:	48 98                	cltq   
 138:	8b 55 f4             	mov    -0xc(%rbp),%edx
 13b:	48 63 d2             	movslq %edx,%rdx
 13e:	48 6b d2 16          	imul   $0x16,%rdx,%rdx
 142:	48 01 d0             	add    %rdx,%rax
 145:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
 14c:	00 
 14d:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # 154 <_Z3dfsi+0x154>
 154:	89 0c 02             	mov    %ecx,(%rdx,%rax,1)
E:\OI-Files/../code/C++/三角形/tria.cpp:18
				tmp += f[i][j] ? 1 : -1;
 157:	8b 45 f0             	mov    -0x10(%rbp),%eax
 15a:	48 98                	cltq   
 15c:	8b 55 f4             	mov    -0xc(%rbp),%edx
 15f:	48 63 d2             	movslq %edx,%rdx
 162:	48 6b d2 16          	imul   $0x16,%rdx,%rdx
 166:	48 01 d0             	add    %rdx,%rax
 169:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
 170:	00 
 171:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # 178 <_Z3dfsi+0x178>
 178:	8b 04 02             	mov    (%rdx,%rax,1),%eax
 17b:	85 c0                	test   %eax,%eax
 17d:	74 07                	je     186 <_Z3dfsi+0x186>
 17f:	b8 01 00 00 00       	mov    $0x1,%eax
 184:	eb 05                	jmp    18b <_Z3dfsi+0x18b>
 186:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 18b:	01 45 fc             	add    %eax,-0x4(%rbp)
E:\OI-Files/../code/C++/三角形/tria.cpp:15
			for (int j = 0; j < n - i; ++j)
 18e:	83 45 f0 01          	addl   $0x1,-0x10(%rbp)
 192:	e9 37 ff ff ff       	jmpq   ce <_Z3dfsi+0xce>
E:\OI-Files/../code/C++/三角形/tria.cpp:20
			}
			if (tmp > s[n - 1 - i] || tmp < -s[n - 1 - i]) return;
 197:	8b 05 fc 07 00 00    	mov    0x7fc(%rip),%eax        # 999 <ans+0x199>
 19d:	83 e8 01             	sub    $0x1,%eax
 1a0:	2b 45 f4             	sub    -0xc(%rbp),%eax
 1a3:	48 98                	cltq   
 1a5:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
 1ac:	00 
 1ad:	48 8d 05 a0 07 00 00 	lea    0x7a0(%rip),%rax        # 954 <ans+0x154>
 1b4:	8b 04 02             	mov    (%rdx,%rax,1),%eax
 1b7:	39 45 fc             	cmp    %eax,-0x4(%rbp)
 1ba:	0f 8f 96 00 00 00    	jg     256 <_Z3dfsi+0x256>
 1c0:	8b 05 fc 07 00 00    	mov    0x7fc(%rip),%eax        # 9c2 <ans+0x1c2>
 1c6:	83 e8 01             	sub    $0x1,%eax
 1c9:	2b 45 f4             	sub    -0xc(%rbp),%eax
 1cc:	48 98                	cltq   
 1ce:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
 1d5:	00 
 1d6:	48 8d 05 a0 07 00 00 	lea    0x7a0(%rip),%rax        # 97d <ans+0x17d>
 1dd:	8b 04 02             	mov    (%rdx,%rax,1),%eax
 1e0:	f7 d8                	neg    %eax
 1e2:	39 45 fc             	cmp    %eax,-0x4(%rbp)
 1e5:	7c 6f                	jl     256 <_Z3dfsi+0x256>
E:\OI-Files/../code/C++/三角形/tria.cpp:13
		for (int i = 1; i < n; ++i)
 1e7:	83 45 f4 01          	addl   $0x1,-0xc(%rbp)
 1eb:	e9 c8 fe ff ff       	jmpq   b8 <_Z3dfsi+0xb8>
E:\OI-Files/../code/C++/三角形/tria.cpp:22
		}
		++ans;
 1f0:	8b 05 00 08 00 00    	mov    0x800(%rip),%eax        # 9f6 <ans+0x1f6>
 1f6:	83 c0 01             	add    $0x1,%eax
 1f9:	89 05 00 08 00 00    	mov    %eax,0x800(%rip)        # 9ff <ans+0x1ff>
E:\OI-Files/../code/C++/三角形/tria.cpp:23
		return;
 1ff:	eb 56                	jmp    257 <_Z3dfsi+0x257>
E:\OI-Files/../code/C++/三角形/tria.cpp:25
	}
	f[0][k] = 0;
 201:	8b 45 10             	mov    0x10(%rbp),%eax
 204:	48 98                	cltq   
 206:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
 20d:	00 
 20e:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # 215 <_Z3dfsi+0x215>
 215:	c7 04 02 00 00 00 00 	movl   $0x0,(%rdx,%rax,1)
E:\OI-Files/../code/C++/三角形/tria.cpp:26
	dfs(k + 1);
 21c:	8b 45 10             	mov    0x10(%rbp),%eax
 21f:	83 c0 01             	add    $0x1,%eax
 222:	89 c1                	mov    %eax,%ecx
 224:	e8 d7 fd ff ff       	callq  0 <_Z3dfsi>
E:\OI-Files/../code/C++/三角形/tria.cpp:27
	f[0][k] = 1;
 229:	8b 45 10             	mov    0x10(%rbp),%eax
 22c:	48 98                	cltq   
 22e:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
 235:	00 
 236:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # 23d <_Z3dfsi+0x23d>
 23d:	c7 04 02 01 00 00 00 	movl   $0x1,(%rdx,%rax,1)
E:\OI-Files/../code/C++/三角形/tria.cpp:28
	dfs(k + 1);
 244:	8b 45 10             	mov    0x10(%rbp),%eax
 247:	83 c0 01             	add    $0x1,%eax
 24a:	89 c1                	mov    %eax,%ecx
 24c:	e8 af fd ff ff       	callq  0 <_Z3dfsi>
 251:	eb 04                	jmp    257 <_Z3dfsi+0x257>
E:\OI-Files/../code/C++/三角形/tria.cpp:12
		if (tmp > s[n - 1] || tmp < -s[n - 1]) return;
 253:	90                   	nop
 254:	eb 01                	jmp    257 <_Z3dfsi+0x257>
E:\OI-Files/../code/C++/三角形/tria.cpp:20
			if (tmp > s[n - 1 - i] || tmp < -s[n - 1 - i]) return;
 256:	90                   	nop
E:\OI-Files/../code/C++/三角形/tria.cpp:29
}
 257:	48 83 c4 30          	add    $0x30,%rsp
 25b:	5d                   	pop    %rbp
 25c:	c3                   	retq   

000000000000025d <main>:
main():
E:\OI-Files/../code/C++/三角形/tria.cpp:32

int main()
{
 25d:	55                   	push   %rbp
 25e:	48 89 e5             	mov    %rsp,%rbp
 261:	48 83 ec 30          	sub    $0x30,%rsp
 265:	e8 00 00 00 00       	callq  26a <main+0xd>
E:\OI-Files/../code/C++/三角形/tria.cpp:33
	freopen("tria.in", "r", stdin);
 26a:	b9 00 00 00 00       	mov    $0x0,%ecx
 26f:	48 8b 05 00 00 00 00 	mov    0x0(%rip),%rax        # 276 <main+0x19>
 276:	ff d0                	callq  *%rax
 278:	49 89 c0             	mov    %rax,%r8
 27b:	48 8d 15 04 00 00 00 	lea    0x4(%rip),%rdx        # 286 <main+0x29>
 282:	48 8d 0d 06 00 00 00 	lea    0x6(%rip),%rcx        # 28f <main+0x32>
 289:	e8 00 00 00 00       	callq  28e <main+0x31>
E:\OI-Files/../code/C++/三角形/tria.cpp:34
	freopen("tria.out", "w", stdout);
 28e:	b9 01 00 00 00       	mov    $0x1,%ecx
 293:	48 8b 05 00 00 00 00 	mov    0x0(%rip),%rax        # 29a <main+0x3d>
 29a:	ff d0                	callq  *%rax
 29c:	49 89 c0             	mov    %rax,%r8
 29f:	48 8d 15 0e 00 00 00 	lea    0xe(%rip),%rdx        # 2b4 <main+0x57>
 2a6:	48 8d 0d 10 00 00 00 	lea    0x10(%rip),%rcx        # 2bd <main+0x60>
 2ad:	e8 00 00 00 00       	callq  2b2 <main+0x55>
E:\OI-Files/../code/C++/三角形/tria.cpp:35
	scanf("%d", &n);
 2b2:	48 8d 15 fc 07 00 00 	lea    0x7fc(%rip),%rdx        # ab5 <ans+0x2b5>
 2b9:	48 8d 0d 19 00 00 00 	lea    0x19(%rip),%rcx        # 2d9 <main+0x7c>
 2c0:	e8 00 00 00 00       	callq  2c5 <main+0x68>
E:\OI-Files/../code/C++/三角形/tria.cpp:36
	if (((n + 1) * n >> 1) & 1)
 2c5:	8b 05 fc 07 00 00    	mov    0x7fc(%rip),%eax        # ac7 <ans+0x2c7>
 2cb:	8d 50 01             	lea    0x1(%rax),%edx
 2ce:	8b 05 fc 07 00 00    	mov    0x7fc(%rip),%eax        # ad0 <ans+0x2d0>
 2d4:	0f af c2             	imul   %edx,%eax
 2d7:	83 e0 02             	and    $0x2,%eax
 2da:	85 c0                	test   %eax,%eax
 2dc:	74 13                	je     2f1 <main+0x94>
E:\OI-Files/../code/C++/三角形/tria.cpp:38
	{
		puts("0");
 2de:	48 8d 0d 1c 00 00 00 	lea    0x1c(%rip),%rcx        # 301 <main+0xa4>
 2e5:	e8 00 00 00 00       	callq  2ea <main+0x8d>
E:\OI-Files/../code/C++/三角形/tria.cpp:39
		return 0;
 2ea:	b8 00 00 00 00       	mov    $0x0,%eax
 2ef:	eb 60                	jmp    351 <main+0xf4>
E:\OI-Files/../code/C++/三角形/tria.cpp:41
	}
	for (int i = 0; i < n; ++i) s[i] = (i * (i + 1)) >> 1;
 2f1:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
 2f8:	8b 05 fc 07 00 00    	mov    0x7fc(%rip),%eax        # afa <ans+0x2fa>
 2fe:	39 45 fc             	cmp    %eax,-0x4(%rbp)
 301:	7d 2b                	jge    32e <main+0xd1>
 303:	8b 45 fc             	mov    -0x4(%rbp),%eax
 306:	83 c0 01             	add    $0x1,%eax
 309:	0f af 45 fc          	imul   -0x4(%rbp),%eax
 30d:	d1 f8                	sar    %eax
 30f:	89 c1                	mov    %eax,%ecx
 311:	8b 45 fc             	mov    -0x4(%rbp),%eax
 314:	48 98                	cltq   
 316:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
 31d:	00 
 31e:	48 8d 05 a0 07 00 00 	lea    0x7a0(%rip),%rax        # ac5 <ans+0x2c5>
 325:	89 0c 02             	mov    %ecx,(%rdx,%rax,1)
 328:	83 45 fc 01          	addl   $0x1,-0x4(%rbp)
 32c:	eb ca                	jmp    2f8 <main+0x9b>
E:\OI-Files/../code/C++/三角形/tria.cpp:42
	dfs(0);
 32e:	b9 00 00 00 00       	mov    $0x0,%ecx
 333:	e8 c8 fc ff ff       	callq  0 <_Z3dfsi>
E:\OI-Files/../code/C++/三角形/tria.cpp:43
	printf("%d", ans);
 338:	8b 05 00 08 00 00    	mov    0x800(%rip),%eax        # b3e <ans+0x33e>
 33e:	89 c2                	mov    %eax,%edx
 340:	48 8d 0d 19 00 00 00 	lea    0x19(%rip),%rcx        # 360 <main+0x103>
 347:	e8 00 00 00 00       	callq  34c <main+0xef>
E:\OI-Files/../code/C++/三角形/tria.cpp:44
	return 0;
 34c:	b8 00 00 00 00       	mov    $0x0,%eax
E:\OI-Files/../code/C++/三角形/tria.cpp:45
 351:	48 83 c4 30          	add    $0x30,%rsp
 355:	5d                   	pop    %rbp
 356:	c3                   	retq   
 357:	90                   	nop
 358:	90                   	nop
 359:	90                   	nop
 35a:	90                   	nop
 35b:	90                   	nop
 35c:	90                   	nop
 35d:	90                   	nop
 35e:	90                   	nop
 35f:	90                   	nop

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
tria.cpp:
typedef void void;
void f /* 0x0 */;
void s /* 0x7a0 */;
void n /* 0x7fc */;
void ans /* 0x800 */;
void __imp___acrt_iob_func /* 0x0 */;
