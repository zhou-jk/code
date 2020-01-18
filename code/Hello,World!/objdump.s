
18_12.o:     file format pe-x86-64


Disassembly of section .text:

0000000000000000 <main>:
//AC
#include <cstdio>

int main()
{
   0:	55                   	push   %rbp
   1:	48 89 e5             	mov    %rsp,%rbp
   4:	48 83 ec 20          	sub    $0x20,%rsp
   8:	e8 00 00 00 00       	callq  d <main+0xd>
	puts("Hello,World!");
   d:	48 8d 0d 00 00 00 00 	lea    0x0(%rip),%rcx        # 14 <main+0x14>
  14:	e8 00 00 00 00       	callq  19 <main+0x19>
	return 0;
  19:	b8 00 00 00 00       	mov    $0x0,%eax
}
  1e:	48 83 c4 20          	add    $0x20,%rsp
  22:	5d                   	pop    %rbp
  23:	c3                   	retq   
  24:	90                   	nop
  25:	90                   	nop
  26:	90                   	nop
  27:	90                   	nop
  28:	90                   	nop
  29:	90                   	nop
  2a:	90                   	nop
  2b:	90                   	nop
  2c:	90                   	nop
  2d:	90                   	nop
  2e:	90                   	nop
  2f:	90                   	nop
