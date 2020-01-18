   1              		.file	"18_12.cpp"
   2              		.text
   3              	.Ltext0:
   4              		.cfi_sections	.debug_frame
   6              		.section .rdata,"dr"
   7              	.LC0:
   8 0000 48656C6C 		.ascii "Hello,World!\0"
   8      6F2C576F 
   8      726C6421 
   8      00
   9 000d 000000   		.text
  10              		.globl	main
  12              		.seh_proc	main
  13              	main:
  14              	.LFB31:
  15              		.file 1 "18_12.cpp"
   1:18_12.cpp     **** //AC
   2:18_12.cpp     **** #include <cstdio>
   3:18_12.cpp     **** 
   4:18_12.cpp     **** int main()
   5:18_12.cpp     **** {
  16              		.loc 1 5 0
  17              		.cfi_startproc
  18 0000 55       		pushq	%rbp
  19              		.seh_pushreg	%rbp
  20              		.cfi_def_cfa_offset 16
  21              		.cfi_offset 6, -16
  22 0001 4889E5   		movq	%rsp, %rbp
  23              		.seh_setframe	%rbp, 0
  24              		.cfi_def_cfa_register 6
  25 0004 4883EC20 		subq	$32, %rsp
  26              		.seh_stackalloc	32
  27              		.seh_endprologue
  28              		.loc 1 5 0
  29 0008 E8000000 		call	__main
  29      00
   6:18_12.cpp     **** 	puts("Hello,World!");
  30              		.loc 1 6 0
  31 000d 488D0D00 		leaq	.LC0(%rip), %rcx
  31      000000
  32 0014 E8000000 		call	puts
  32      00
   7:18_12.cpp     **** 	return 0;
  33              		.loc 1 7 0
  34 0019 B8000000 		movl	$0, %eax
  34      00
   8:18_12.cpp     **** }
  35              		.loc 1 8 0
  36 001e 4883C420 		addq	$32, %rsp
  37 0022 5D       		popq	%rbp
  38              		.cfi_restore 6
  39              		.cfi_def_cfa 7, 8
  40 0023 C3       		ret
  41              		.cfi_endproc
  42              	.LFE31:
  43              		.seh_endproc
  44              	.Letext0:
  45              		.file 2 "C:/Program Files (x86)/Dev-Cpp/MinGW64/x86_64-w64-mingw32/include/stdio.h"
  46              		.file 3 "C:/Program Files (x86)/Dev-Cpp/MinGW64/x86_64-w64-mingw32/include/_mingw.h"
  47              		.file 4 "C:/Program Files (x86)/Dev-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/4.9.2/include/c++/cstdi
  48              		.file 5 "<built-in>"
  49 0024 90909090 		.section	.debug_info,"dr"
  49      90909090 
  49      90909090 
  50              	.Ldebug_info0:
  51 0000 1D090000 		.long	0x91d
  52 0004 0400     		.word	0x4
  53 0006 00000000 		.secrel32	.Ldebug_abbrev0
  54 000a 08       		.byte	0x8
  55 000b 01       		.uleb128 0x1
  56 000c 474E5520 		.ascii "GNU C++ 4.9.2 -mtune=generic -march=x86-64 -g\0"
  56      432B2B20 
  56      342E392E 
  56      32202D6D 
  56      74756E65 
  57 003a 04       		.byte	0x4
  58 003b 31385F31 		.ascii "18_12.cpp\0"
  58      322E6370 
  58      7000
  59 0045 453A5C63 		.ascii "E:\\code\\Hello,World!\0"
  59      6F64655C 
  59      48656C6C 
  59      6F2C576F 
  59      726C6421 
  60 005a 00000000 		.quad	.Ltext0
  60      00000000 
  61 0062 24000000 		.quad	.Letext0-.Ltext0
  61      00000000 
  62 006a 00000000 		.secrel32	.Ldebug_line0
  63 006e 02       		.uleb128 0x2
  64 006f 08       		.byte	0x8
  65 0070 5F5F6275 		.ascii "__builtin_va_list\0"
  65      696C7469 
  65      6E5F7661 
  65      5F6C6973 
  65      7400
  66 0082 86000000 		.long	0x86
  67 0086 03       		.uleb128 0x3
  68 0087 01       		.byte	0x1
  69 0088 06       		.byte	0x6
  70 0089 63686172 		.ascii "char\0"
  70      00
  71 008e 04       		.uleb128 0x4
  72 008f 73697A65 		.ascii "size_t\0"
  72      5F7400
  73 0096 03       		.byte	0x3
  74 0097 7901     		.word	0x179
  75 0099 9D000000 		.long	0x9d
  76 009d 03       		.uleb128 0x3
  77 009e 08       		.byte	0x8
  78 009f 07       		.byte	0x7
  79 00a0 6C6F6E67 		.ascii "long long unsigned int\0"
  79      206C6F6E 
  79      6720756E 
  79      7369676E 
  79      65642069 
  80 00b7 03       		.uleb128 0x3
  81 00b8 08       		.byte	0x8
  82 00b9 05       		.byte	0x5
  83 00ba 6C6F6E67 		.ascii "long long int\0"
  83      206C6F6E 
  83      6720696E 
  83      7400
  84 00c8 03       		.uleb128 0x3
  85 00c9 02       		.byte	0x2
  86 00ca 07       		.byte	0x7
  87 00cb 73686F72 		.ascii "short unsigned int\0"
  87      7420756E 
  87      7369676E 
  87      65642069 
  87      6E7400
  88 00de 03       		.uleb128 0x3
  89 00df 04       		.byte	0x4
  90 00e0 05       		.byte	0x5
  91 00e1 696E7400 		.ascii "int\0"
  92 00e5 03       		.uleb128 0x3
  93 00e6 04       		.byte	0x4
  94 00e7 05       		.byte	0x5
  95 00e8 6C6F6E67 		.ascii "long int\0"
  95      20696E74 
  95      00
  96 00f1 05       		.uleb128 0x5
  97 00f2 08       		.byte	0x8
  98 00f3 86000000 		.long	0x86
  99 00f7 03       		.uleb128 0x3
 100 00f8 02       		.byte	0x2
 101 00f9 07       		.byte	0x7
 102 00fa 77636861 		.ascii "wchar_t\0"
 102      725F7400 
 103 0102 03       		.uleb128 0x3
 104 0103 04       		.byte	0x4
 105 0104 07       		.byte	0x7
 106 0105 756E7369 		.ascii "unsigned int\0"
 106      676E6564 
 106      20696E74 
 106      00
 107 0112 03       		.uleb128 0x3
 108 0113 08       		.byte	0x8
 109 0114 07       		.byte	0x7
 110 0115 73697A65 		.ascii "sizetype\0"
 110      74797065 
 110      00
 111 011e 03       		.uleb128 0x3
 112 011f 04       		.byte	0x4
 113 0120 07       		.byte	0x7
 114 0121 6C6F6E67 		.ascii "long unsigned int\0"
 114      20756E73 
 114      69676E65 
 114      6420696E 
 114      7400
 115 0133 03       		.uleb128 0x3
 116 0134 01       		.byte	0x1
 117 0135 08       		.byte	0x8
 118 0136 756E7369 		.ascii "unsigned char\0"
 118      676E6564 
 118      20636861 
 118      7200
 119 0144 06       		.uleb128 0x6
 120 0145 5F696F62 		.ascii "_iobuf\0"
 120      756600
 121 014c 30       		.byte	0x30
 122 014d 02       		.byte	0x2
 123 014e 1A       		.byte	0x1a
 124 014f CB010000 		.long	0x1cb
 125 0153 07       		.uleb128 0x7
 126 0154 5F707472 		.ascii "_ptr\0"
 126      00
 127 0159 02       		.byte	0x2
 128 015a 1B       		.byte	0x1b
 129 015b F1000000 		.long	0xf1
 130 015f 00       		.byte	0
 131 0160 07       		.uleb128 0x7
 132 0161 5F636E74 		.ascii "_cnt\0"
 132      00
 133 0166 02       		.byte	0x2
 134 0167 1C       		.byte	0x1c
 135 0168 DE000000 		.long	0xde
 136 016c 08       		.byte	0x8
 137 016d 07       		.uleb128 0x7
 138 016e 5F626173 		.ascii "_base\0"
 138      6500
 139 0174 02       		.byte	0x2
 140 0175 1D       		.byte	0x1d
 141 0176 F1000000 		.long	0xf1
 142 017a 10       		.byte	0x10
 143 017b 07       		.uleb128 0x7
 144 017c 5F666C61 		.ascii "_flag\0"
 144      6700
 145 0182 02       		.byte	0x2
 146 0183 1E       		.byte	0x1e
 147 0184 DE000000 		.long	0xde
 148 0188 18       		.byte	0x18
 149 0189 07       		.uleb128 0x7
 150 018a 5F66696C 		.ascii "_file\0"
 150      6500
 151 0190 02       		.byte	0x2
 152 0191 1F       		.byte	0x1f
 153 0192 DE000000 		.long	0xde
 154 0196 1C       		.byte	0x1c
 155 0197 07       		.uleb128 0x7
 156 0198 5F636861 		.ascii "_charbuf\0"
 156      72627566 
 156      00
 157 01a1 02       		.byte	0x2
 158 01a2 20       		.byte	0x20
 159 01a3 DE000000 		.long	0xde
 160 01a7 20       		.byte	0x20
 161 01a8 07       		.uleb128 0x7
 162 01a9 5F627566 		.ascii "_bufsiz\0"
 162      73697A00 
 163 01b1 02       		.byte	0x2
 164 01b2 21       		.byte	0x21
 165 01b3 DE000000 		.long	0xde
 166 01b7 24       		.byte	0x24
 167 01b8 07       		.uleb128 0x7
 168 01b9 5F746D70 		.ascii "_tmpfname\0"
 168      666E616D 
 168      6500
 169 01c3 02       		.byte	0x2
 170 01c4 22       		.byte	0x22
 171 01c5 F1000000 		.long	0xf1
 172 01c9 28       		.byte	0x28
 173 01ca 00       		.byte	0
 174 01cb 08       		.uleb128 0x8
 175 01cc 46494C45 		.ascii "FILE\0"
 175      00
 176 01d1 02       		.byte	0x2
 177 01d2 24       		.byte	0x24
 178 01d3 44010000 		.long	0x144
 179 01d7 08       		.uleb128 0x8
 180 01d8 66706F73 		.ascii "fpos_t\0"
 180      5F7400
 181 01df 02       		.byte	0x2
 182 01e0 67       		.byte	0x67
 183 01e1 B7000000 		.long	0xb7
 184 01e5 09       		.uleb128 0x9
 185 01e6 73746400 		.ascii "std\0"
 186 01ea 05       		.byte	0x5
 187 01eb 00       		.byte	0
 188 01ec 17030000 		.long	0x317
 189 01f0 0A       		.uleb128 0xa
 190 01f1 04       		.byte	0x4
 191 01f2 62       		.byte	0x62
 192 01f3 CB010000 		.long	0x1cb
 193 01f7 0A       		.uleb128 0xa
 194 01f8 04       		.byte	0x4
 195 01f9 63       		.byte	0x63
 196 01fa D7010000 		.long	0x1d7
 197 01fe 0A       		.uleb128 0xa
 198 01ff 04       		.byte	0x4
 199 0200 65       		.byte	0x65
 200 0201 17030000 		.long	0x317
 201 0205 0A       		.uleb128 0xa
 202 0206 04       		.byte	0x4
 203 0207 66       		.byte	0x66
 204 0208 34030000 		.long	0x334
 205 020c 0A       		.uleb128 0xa
 206 020d 04       		.byte	0x4
 207 020e 67       		.byte	0x67
 208 020f 4D030000 		.long	0x34d
 209 0213 0A       		.uleb128 0xa
 210 0214 04       		.byte	0x4
 211 0215 68       		.byte	0x68
 212 0216 64030000 		.long	0x364
 213 021a 0A       		.uleb128 0xa
 214 021b 04       		.byte	0x4
 215 021c 69       		.byte	0x69
 216 021d 7D030000 		.long	0x37d
 217 0221 0A       		.uleb128 0xa
 218 0222 04       		.byte	0x4
 219 0223 6A       		.byte	0x6a
 220 0224 96030000 		.long	0x396
 221 0228 0A       		.uleb128 0xa
 222 0229 04       		.byte	0x4
 223 022a 6B       		.byte	0x6b
 224 022b AE030000 		.long	0x3ae
 225 022f 0A       		.uleb128 0xa
 226 0230 04       		.byte	0x4
 227 0231 6C       		.byte	0x6c
 228 0232 D3030000 		.long	0x3d3
 229 0236 0A       		.uleb128 0xa
 230 0237 04       		.byte	0x4
 231 0238 6D       		.byte	0x6d
 232 0239 F5030000 		.long	0x3f5
 233 023d 0A       		.uleb128 0xa
 234 023e 04       		.byte	0x4
 235 023f 6E       		.byte	0x6e
 236 0240 1D040000 		.long	0x41d
 237 0244 0A       		.uleb128 0xa
 238 0245 04       		.byte	0x4
 239 0246 71       		.byte	0x71
 240 0247 54040000 		.long	0x454
 241 024b 0A       		.uleb128 0xa
 242 024c 04       		.byte	0x4
 243 024d 72       		.byte	0x72
 244 024e 7D040000 		.long	0x47d
 245 0252 0A       		.uleb128 0xa
 246 0253 04       		.byte	0x4
 247 0254 73       		.byte	0x73
 248 0255 A1040000 		.long	0x4a1
 249 0259 0A       		.uleb128 0xa
 250 025a 04       		.byte	0x4
 251 025b 74       		.byte	0x74
 252 025c D5040000 		.long	0x4d5
 253 0260 0A       		.uleb128 0xa
 254 0261 04       		.byte	0x4
 255 0262 75       		.byte	0x75
 256 0263 F7040000 		.long	0x4f7
 257 0267 0A       		.uleb128 0xa
 258 0268 04       		.byte	0x4
 259 0269 76       		.byte	0x76
 260 026a 21050000 		.long	0x521
 261 026e 0A       		.uleb128 0xa
 262 026f 04       		.byte	0x4
 263 0270 78       		.byte	0x78
 264 0271 39050000 		.long	0x539
 265 0275 0A       		.uleb128 0xa
 266 0276 04       		.byte	0x4
 267 0277 79       		.byte	0x79
 268 0278 50050000 		.long	0x550
 269 027c 0A       		.uleb128 0xa
 270 027d 04       		.byte	0x4
 271 027e 7C       		.byte	0x7c
 272 027f 60050000 		.long	0x560
 273 0283 0A       		.uleb128 0xa
 274 0284 04       		.byte	0x4
 275 0285 7E       		.byte	0x7e
 276 0286 77050000 		.long	0x577
 277 028a 0A       		.uleb128 0xa
 278 028b 04       		.byte	0x4
 279 028c 7F       		.byte	0x7f
 280 028d 8C050000 		.long	0x58c
 281 0291 0A       		.uleb128 0xa
 282 0292 04       		.byte	0x4
 283 0293 83       		.byte	0x83
 284 0294 B4050000 		.long	0x5b4
 285 0298 0A       		.uleb128 0xa
 286 0299 04       		.byte	0x4
 287 029a 84       		.byte	0x84
 288 029b CD050000 		.long	0x5cd
 289 029f 0A       		.uleb128 0xa
 290 02a0 04       		.byte	0x4
 291 02a1 85       		.byte	0x85
 292 02a2 EB050000 		.long	0x5eb
 293 02a6 0A       		.uleb128 0xa
 294 02a7 04       		.byte	0x4
 295 02a8 86       		.byte	0x86
 296 02a9 00060000 		.long	0x600
 297 02ad 0A       		.uleb128 0xa
 298 02ae 04       		.byte	0x4
 299 02af 87       		.byte	0x87
 300 02b0 25060000 		.long	0x625
 301 02b4 0A       		.uleb128 0xa
 302 02b5 04       		.byte	0x4
 303 02b6 88       		.byte	0x88
 304 02b7 3F060000 		.long	0x63f
 305 02bb 0A       		.uleb128 0xa
 306 02bc 04       		.byte	0x4
 307 02bd 89       		.byte	0x89
 308 02be 68060000 		.long	0x668
 309 02c2 0A       		.uleb128 0xa
 310 02c3 04       		.byte	0x4
 311 02c4 8A       		.byte	0x8a
 312 02c5 99060000 		.long	0x699
 313 02c9 0A       		.uleb128 0xa
 314 02ca 04       		.byte	0x4
 315 02cb 8B       		.byte	0x8b
 316 02cc C8060000 		.long	0x6c8
 317 02d0 0A       		.uleb128 0xa
 318 02d1 04       		.byte	0x4
 319 02d2 8D       		.byte	0x8d
 320 02d3 D8060000 		.long	0x6d8
 321 02d7 0A       		.uleb128 0xa
 322 02d8 04       		.byte	0x4
 323 02d9 8F       		.byte	0x8f
 324 02da F1060000 		.long	0x6f1
 325 02de 0A       		.uleb128 0xa
 326 02df 04       		.byte	0x4
 327 02e0 90       		.byte	0x90
 328 02e1 0F070000 		.long	0x70f
 329 02e5 0A       		.uleb128 0xa
 330 02e6 04       		.byte	0x4
 331 02e7 91       		.byte	0x91
 332 02e8 4D070000 		.long	0x74d
 333 02ec 0A       		.uleb128 0xa
 334 02ed 04       		.byte	0x4
 335 02ee 92       		.byte	0x92
 336 02ef 7C070000 		.long	0x77c
 337 02f3 0A       		.uleb128 0xa
 338 02f4 04       		.byte	0x4
 339 02f5 B9       		.byte	0xb9
 340 02f6 E9070000 		.long	0x7e9
 341 02fa 0A       		.uleb128 0xa
 342 02fb 04       		.byte	0x4
 343 02fc BA       		.byte	0xba
 344 02fd 22080000 		.long	0x822
 345 0301 0A       		.uleb128 0xa
 346 0302 04       		.byte	0x4
 347 0303 BB       		.byte	0xbb
 348 0304 5E080000 		.long	0x85e
 349 0308 0A       		.uleb128 0xa
 350 0309 04       		.byte	0x4
 351 030a BC       		.byte	0xbc
 352 030b 8B080000 		.long	0x88b
 353 030f 0A       		.uleb128 0xa
 354 0310 04       		.byte	0x4
 355 0311 BD       		.byte	0xbd
 356 0312 CB080000 		.long	0x8cb
 357 0316 00       		.byte	0
 358 0317 0B       		.uleb128 0xb
 359 0318 636C6561 		.ascii "clearerr\0"
 359      72657272 
 359      00
 360 0321 02       		.byte	0x2
 361 0322 AB01     		.word	0x1ab
 362 0324 2E030000 		.long	0x32e
 363 0328 0C       		.uleb128 0xc
 364 0329 2E030000 		.long	0x32e
 365 032d 00       		.byte	0
 366 032e 05       		.uleb128 0x5
 367 032f 08       		.byte	0x8
 368 0330 CB010000 		.long	0x1cb
 369 0334 0D       		.uleb128 0xd
 370 0335 66636C6F 		.ascii "fclose\0"
 370      736500
 371 033c 02       		.byte	0x2
 372 033d AC01     		.word	0x1ac
 373 033f DE000000 		.long	0xde
 374 0343 4D030000 		.long	0x34d
 375 0347 0C       		.uleb128 0xc
 376 0348 2E030000 		.long	0x32e
 377 034c 00       		.byte	0
 378 034d 0D       		.uleb128 0xd
 379 034e 66656F66 		.ascii "feof\0"
 379      00
 380 0353 02       		.byte	0x2
 381 0354 B301     		.word	0x1b3
 382 0356 DE000000 		.long	0xde
 383 035a 64030000 		.long	0x364
 384 035e 0C       		.uleb128 0xc
 385 035f 2E030000 		.long	0x32e
 386 0363 00       		.byte	0
 387 0364 0D       		.uleb128 0xd
 388 0365 66657272 		.ascii "ferror\0"
 388      6F7200
 389 036c 02       		.byte	0x2
 390 036d B401     		.word	0x1b4
 391 036f DE000000 		.long	0xde
 392 0373 7D030000 		.long	0x37d
 393 0377 0C       		.uleb128 0xc
 394 0378 2E030000 		.long	0x32e
 395 037c 00       		.byte	0
 396 037d 0D       		.uleb128 0xd
 397 037e 66666C75 		.ascii "fflush\0"
 397      736800
 398 0385 02       		.byte	0x2
 399 0386 B501     		.word	0x1b5
 400 0388 DE000000 		.long	0xde
 401 038c 96030000 		.long	0x396
 402 0390 0C       		.uleb128 0xc
 403 0391 2E030000 		.long	0x32e
 404 0395 00       		.byte	0
 405 0396 0D       		.uleb128 0xd
 406 0397 66676574 		.ascii "fgetc\0"
 406      6300
 407 039d 02       		.byte	0x2
 408 039e B601     		.word	0x1b6
 409 03a0 DE000000 		.long	0xde
 410 03a4 AE030000 		.long	0x3ae
 411 03a8 0C       		.uleb128 0xc
 412 03a9 2E030000 		.long	0x32e
 413 03ad 00       		.byte	0
 414 03ae 0D       		.uleb128 0xd
 415 03af 66676574 		.ascii "fgetpos\0"
 415      706F7300 
 416 03b7 02       		.byte	0x2
 417 03b8 B801     		.word	0x1b8
 418 03ba DE000000 		.long	0xde
 419 03be CD030000 		.long	0x3cd
 420 03c2 0C       		.uleb128 0xc
 421 03c3 2E030000 		.long	0x32e
 422 03c7 0C       		.uleb128 0xc
 423 03c8 CD030000 		.long	0x3cd
 424 03cc 00       		.byte	0
 425 03cd 05       		.uleb128 0x5
 426 03ce 08       		.byte	0x8
 427 03cf D7010000 		.long	0x1d7
 428 03d3 0D       		.uleb128 0xd
 429 03d4 66676574 		.ascii "fgets\0"
 429      7300
 430 03da 02       		.byte	0x2
 431 03db BA01     		.word	0x1ba
 432 03dd F1000000 		.long	0xf1
 433 03e1 F5030000 		.long	0x3f5
 434 03e5 0C       		.uleb128 0xc
 435 03e6 F1000000 		.long	0xf1
 436 03ea 0C       		.uleb128 0xc
 437 03eb DE000000 		.long	0xde
 438 03ef 0C       		.uleb128 0xc
 439 03f0 2E030000 		.long	0x32e
 440 03f4 00       		.byte	0
 441 03f5 0D       		.uleb128 0xd
 442 03f6 666F7065 		.ascii "fopen\0"
 442      6E00
 443 03fc 02       		.byte	0x2
 444 03fd C101     		.word	0x1c1
 445 03ff 2E030000 		.long	0x32e
 446 0403 12040000 		.long	0x412
 447 0407 0C       		.uleb128 0xc
 448 0408 12040000 		.long	0x412
 449 040c 0C       		.uleb128 0xc
 450 040d 12040000 		.long	0x412
 451 0411 00       		.byte	0
 452 0412 05       		.uleb128 0x5
 453 0413 08       		.byte	0x8
 454 0414 18040000 		.long	0x418
 455 0418 0E       		.uleb128 0xe
 456 0419 86000000 		.long	0x86
 457 041d 0F       		.uleb128 0xf
 458 041e 66707269 		.ascii "fprintf\0"
 458      6E746600 
 459 0426 02       		.byte	0x2
 460 0427 1D01     		.word	0x11d
 461 0429 5F5A3766 		.ascii "_Z7fprintfP6_iobufPKcz\0"
 461      7072696E 
 461      74665036 
 461      5F696F62 
 461      7566504B 
 462 0440 DE000000 		.long	0xde
 463 0444 54040000 		.long	0x454
 464 0448 0C       		.uleb128 0xc
 465 0449 2E030000 		.long	0x32e
 466 044d 0C       		.uleb128 0xc
 467 044e 12040000 		.long	0x412
 468 0452 10       		.uleb128 0x10
 469 0453 00       		.byte	0
 470 0454 0D       		.uleb128 0xd
 471 0455 66726561 		.ascii "fread\0"
 471      6400
 472 045b 02       		.byte	0x2
 473 045c C601     		.word	0x1c6
 474 045e 8E000000 		.long	0x8e
 475 0462 7B040000 		.long	0x47b
 476 0466 0C       		.uleb128 0xc
 477 0467 7B040000 		.long	0x47b
 478 046b 0C       		.uleb128 0xc
 479 046c 8E000000 		.long	0x8e
 480 0470 0C       		.uleb128 0xc
 481 0471 8E000000 		.long	0x8e
 482 0475 0C       		.uleb128 0xc
 483 0476 2E030000 		.long	0x32e
 484 047a 00       		.byte	0
 485 047b 11       		.uleb128 0x11
 486 047c 08       		.byte	0x8
 487 047d 0D       		.uleb128 0xd
 488 047e 6672656F 		.ascii "freopen\0"
 488      70656E00 
 489 0486 02       		.byte	0x2
 490 0487 C701     		.word	0x1c7
 491 0489 2E030000 		.long	0x32e
 492 048d A1040000 		.long	0x4a1
 493 0491 0C       		.uleb128 0xc
 494 0492 12040000 		.long	0x412
 495 0496 0C       		.uleb128 0xc
 496 0497 12040000 		.long	0x412
 497 049b 0C       		.uleb128 0xc
 498 049c 2E030000 		.long	0x32e
 499 04a0 00       		.byte	0
 500 04a1 12       		.uleb128 0x12
 501 04a2 66736361 		.ascii "fscanf\0"
 501      6E6600
 502 04a9 02       		.byte	0x2
 503 04aa F9       		.byte	0xf9
 504 04ab 5F5A3666 		.ascii "_Z6fscanfP6_iobufPKcz\0"
 504      7363616E 
 504      6650365F 
 504      696F6275 
 504      66504B63 
 505 04c1 DE000000 		.long	0xde
 506 04c5 D5040000 		.long	0x4d5
 507 04c9 0C       		.uleb128 0xc
 508 04ca 2E030000 		.long	0x32e
 509 04ce 0C       		.uleb128 0xc
 510 04cf 12040000 		.long	0x412
 511 04d3 10       		.uleb128 0x10
 512 04d4 00       		.byte	0
 513 04d5 0D       		.uleb128 0xd
 514 04d6 66736565 		.ascii "fseek\0"
 514      6B00
 515 04dc 02       		.byte	0x2
 516 04dd CA01     		.word	0x1ca
 517 04df DE000000 		.long	0xde
 518 04e3 F7040000 		.long	0x4f7
 519 04e7 0C       		.uleb128 0xc
 520 04e8 2E030000 		.long	0x32e
 521 04ec 0C       		.uleb128 0xc
 522 04ed E5000000 		.long	0xe5
 523 04f1 0C       		.uleb128 0xc
 524 04f2 DE000000 		.long	0xde
 525 04f6 00       		.byte	0
 526 04f7 0D       		.uleb128 0xd
 527 04f8 66736574 		.ascii "fsetpos\0"
 527      706F7300 
 528 0500 02       		.byte	0x2
 529 0501 C801     		.word	0x1c8
 530 0503 DE000000 		.long	0xde
 531 0507 16050000 		.long	0x516
 532 050b 0C       		.uleb128 0xc
 533 050c 2E030000 		.long	0x32e
 534 0510 0C       		.uleb128 0xc
 535 0511 16050000 		.long	0x516
 536 0515 00       		.byte	0
 537 0516 05       		.uleb128 0x5
 538 0517 08       		.byte	0x8
 539 0518 1C050000 		.long	0x51c
 540 051c 0E       		.uleb128 0xe
 541 051d D7010000 		.long	0x1d7
 542 0521 0D       		.uleb128 0xd
 543 0522 6674656C 		.ascii "ftell\0"
 543      6C00
 544 0528 02       		.byte	0x2
 545 0529 D801     		.word	0x1d8
 546 052b E5000000 		.long	0xe5
 547 052f 39050000 		.long	0x539
 548 0533 0C       		.uleb128 0xc
 549 0534 2E030000 		.long	0x32e
 550 0538 00       		.byte	0
 551 0539 0D       		.uleb128 0xd
 552 053a 67657463 		.ascii "getc\0"
 552      00
 553 053f 02       		.byte	0x2
 554 0540 E701     		.word	0x1e7
 555 0542 DE000000 		.long	0xde
 556 0546 50050000 		.long	0x550
 557 054a 0C       		.uleb128 0xc
 558 054b 2E030000 		.long	0x32e
 559 054f 00       		.byte	0
 560 0550 13       		.uleb128 0x13
 561 0551 67657463 		.ascii "getchar\0"
 561      68617200 
 562 0559 02       		.byte	0x2
 563 055a E801     		.word	0x1e8
 564 055c DE000000 		.long	0xde
 565 0560 0D       		.uleb128 0xd
 566 0561 67657473 		.ascii "gets\0"
 566      00
 567 0566 02       		.byte	0x2
 568 0567 EA01     		.word	0x1ea
 569 0569 F1000000 		.long	0xf1
 570 056d 77050000 		.long	0x577
 571 0571 0C       		.uleb128 0xc
 572 0572 F1000000 		.long	0xf1
 573 0576 00       		.byte	0
 574 0577 0B       		.uleb128 0xb
 575 0578 70657272 		.ascii "perror\0"
 575      6F7200
 576 057f 02       		.byte	0x2
 577 0580 EE01     		.word	0x1ee
 578 0582 8C050000 		.long	0x58c
 579 0586 0C       		.uleb128 0xc
 580 0587 12040000 		.long	0x412
 581 058b 00       		.byte	0
 582 058c 0F       		.uleb128 0xf
 583 058d 7072696E 		.ascii "printf\0"
 583      746600
 584 0594 02       		.byte	0x2
 585 0595 2801     		.word	0x128
 586 0597 5F5A3670 		.ascii "_Z6printfPKcz\0"
 586      72696E74 
 586      66504B63 
 586      7A00
 587 05a5 DE000000 		.long	0xde
 588 05a9 B4050000 		.long	0x5b4
 589 05ad 0C       		.uleb128 0xc
 590 05ae 12040000 		.long	0x412
 591 05b2 10       		.uleb128 0x10
 592 05b3 00       		.byte	0
 593 05b4 0D       		.uleb128 0xd
 594 05b5 72656D6F 		.ascii "remove\0"
 594      766500
 595 05bc 02       		.byte	0x2
 596 05bd FC01     		.word	0x1fc
 597 05bf DE000000 		.long	0xde
 598 05c3 CD050000 		.long	0x5cd
 599 05c7 0C       		.uleb128 0xc
 600 05c8 12040000 		.long	0x412
 601 05cc 00       		.byte	0
 602 05cd 0D       		.uleb128 0xd
 603 05ce 72656E61 		.ascii "rename\0"
 603      6D6500
 604 05d5 02       		.byte	0x2
 605 05d6 FD01     		.word	0x1fd
 606 05d8 DE000000 		.long	0xde
 607 05dc EB050000 		.long	0x5eb
 608 05e0 0C       		.uleb128 0xc
 609 05e1 12040000 		.long	0x412
 610 05e5 0C       		.uleb128 0xc
 611 05e6 12040000 		.long	0x412
 612 05ea 00       		.byte	0
 613 05eb 0B       		.uleb128 0xb
 614 05ec 72657769 		.ascii "rewind\0"
 614      6E6400
 615 05f3 02       		.byte	0x2
 616 05f4 0302     		.word	0x203
 617 05f6 00060000 		.long	0x600
 618 05fa 0C       		.uleb128 0xc
 619 05fb 2E030000 		.long	0x32e
 620 05ff 00       		.byte	0
 621 0600 12       		.uleb128 0x12
 622 0601 7363616E 		.ascii "scanf\0"
 622      6600
 623 0607 02       		.byte	0x2
 624 0608 EE       		.byte	0xee
 625 0609 5F5A3573 		.ascii "_Z5scanfPKcz\0"
 625      63616E66 
 625      504B637A 
 625      00
 626 0616 DE000000 		.long	0xde
 627 061a 25060000 		.long	0x625
 628 061e 0C       		.uleb128 0xc
 629 061f 12040000 		.long	0x412
 630 0623 10       		.uleb128 0x10
 631 0624 00       		.byte	0
 632 0625 0B       		.uleb128 0xb
 633 0626 73657462 		.ascii "setbuf\0"
 633      756600
 634 062d 02       		.byte	0x2
 635 062e 0502     		.word	0x205
 636 0630 3F060000 		.long	0x63f
 637 0634 0C       		.uleb128 0xc
 638 0635 2E030000 		.long	0x32e
 639 0639 0C       		.uleb128 0xc
 640 063a F1000000 		.long	0xf1
 641 063e 00       		.byte	0
 642 063f 0D       		.uleb128 0xd
 643 0640 73657476 		.ascii "setvbuf\0"
 643      62756600 
 644 0648 02       		.byte	0x2
 645 0649 0902     		.word	0x209
 646 064b DE000000 		.long	0xde
 647 064f 68060000 		.long	0x668
 648 0653 0C       		.uleb128 0xc
 649 0654 2E030000 		.long	0x32e
 650 0658 0C       		.uleb128 0xc
 651 0659 F1000000 		.long	0xf1
 652 065d 0C       		.uleb128 0xc
 653 065e DE000000 		.long	0xde
 654 0662 0C       		.uleb128 0xc
 655 0663 8E000000 		.long	0x8e
 656 0667 00       		.byte	0
 657 0668 0F       		.uleb128 0xf
 658 0669 73707269 		.ascii "sprintf\0"
 658      6E746600 
 659 0671 02       		.byte	0x2
 660 0672 3301     		.word	0x133
 661 0674 5F5A3773 		.ascii "_Z7sprintfPcPKcz\0"
 661      7072696E 
 661      74665063 
 661      504B637A 
 661      00
 662 0685 DE000000 		.long	0xde
 663 0689 99060000 		.long	0x699
 664 068d 0C       		.uleb128 0xc
 665 068e F1000000 		.long	0xf1
 666 0692 0C       		.uleb128 0xc
 667 0693 12040000 		.long	0x412
 668 0697 10       		.uleb128 0x10
 669 0698 00       		.byte	0
 670 0699 12       		.uleb128 0x12
 671 069a 73736361 		.ascii "sscanf\0"
 671      6E6600
 672 06a1 02       		.byte	0x2
 673 06a2 E3       		.byte	0xe3
 674 06a3 5F5A3673 		.ascii "_Z6sscanfPKcS0_z\0"
 674      7363616E 
 674      66504B63 
 674      53305F7A 
 674      00
 675 06b4 DE000000 		.long	0xde
 676 06b8 C8060000 		.long	0x6c8
 677 06bc 0C       		.uleb128 0xc
 678 06bd 12040000 		.long	0x412
 679 06c1 0C       		.uleb128 0xc
 680 06c2 12040000 		.long	0x412
 681 06c6 10       		.uleb128 0x10
 682 06c7 00       		.byte	0
 683 06c8 13       		.uleb128 0x13
 684 06c9 746D7066 		.ascii "tmpfile\0"
 684      696C6500 
 685 06d1 02       		.byte	0x2
 686 06d2 0C02     		.word	0x20c
 687 06d4 2E030000 		.long	0x32e
 688 06d8 0D       		.uleb128 0xd
 689 06d9 746D706E 		.ascii "tmpnam\0"
 689      616D00
 690 06e0 02       		.byte	0x2
 691 06e1 0D02     		.word	0x20d
 692 06e3 F1000000 		.long	0xf1
 693 06e7 F1060000 		.long	0x6f1
 694 06eb 0C       		.uleb128 0xc
 695 06ec F1000000 		.long	0xf1
 696 06f0 00       		.byte	0
 697 06f1 0D       		.uleb128 0xd
 698 06f2 756E6765 		.ascii "ungetc\0"
 698      746300
 699 06f9 02       		.byte	0x2
 700 06fa 0E02     		.word	0x20e
 701 06fc DE000000 		.long	0xde
 702 0700 0F070000 		.long	0x70f
 703 0704 0C       		.uleb128 0xc
 704 0705 DE000000 		.long	0xde
 705 0709 0C       		.uleb128 0xc
 706 070a 2E030000 		.long	0x32e
 707 070e 00       		.byte	0
 708 070f 0F       		.uleb128 0xf
 709 0710 76667072 		.ascii "vfprintf\0"
 709      696E7466 
 709      00
 710 0719 02       		.byte	0x2
 711 071a 3E01     		.word	0x13e
 712 071c 5F5A3876 		.ascii "_Z8vfprintfP6_iobufPKcPc\0"
 712      66707269 
 712      6E746650 
 712      365F696F 
 712      62756650 
 713 0735 DE000000 		.long	0xde
 714 0739 4D070000 		.long	0x74d
 715 073d 0C       		.uleb128 0xc
 716 073e 2E030000 		.long	0x32e
 717 0742 0C       		.uleb128 0xc
 718 0743 12040000 		.long	0x412
 719 0747 0C       		.uleb128 0xc
 720 0748 6E000000 		.long	0x6e
 721 074c 00       		.byte	0
 722 074d 0F       		.uleb128 0xf
 723 074e 76707269 		.ascii "vprintf\0"
 723      6E746600 
 724 0756 02       		.byte	0x2
 725 0757 4501     		.word	0x145
 726 0759 5F5A3776 		.ascii "_Z7vprintfPKcPc\0"
 726      7072696E 
 726      7466504B 
 726      63506300 
 727 0769 DE000000 		.long	0xde
 728 076d 7C070000 		.long	0x77c
 729 0771 0C       		.uleb128 0xc
 730 0772 12040000 		.long	0x412
 731 0776 0C       		.uleb128 0xc
 732 0777 6E000000 		.long	0x6e
 733 077b 00       		.byte	0
 734 077c 0F       		.uleb128 0xf
 735 077d 76737072 		.ascii "vsprintf\0"
 735      696E7466 
 735      00
 736 0786 02       		.byte	0x2
 737 0787 4C01     		.word	0x14c
 738 0789 5F5A3876 		.ascii "_Z8vsprintfPcPKcS_\0"
 738      73707269 
 738      6E746650 
 738      63504B63 
 738      535F00
 739 079c DE000000 		.long	0xde
 740 07a0 B4070000 		.long	0x7b4
 741 07a4 0C       		.uleb128 0xc
 742 07a5 F1000000 		.long	0xf1
 743 07a9 0C       		.uleb128 0xc
 744 07aa 12040000 		.long	0x412
 745 07ae 0C       		.uleb128 0xc
 746 07af 6E000000 		.long	0x6e
 747 07b3 00       		.byte	0
 748 07b4 09       		.uleb128 0x9
 749 07b5 5F5F676E 		.ascii "__gnu_cxx\0"
 749      755F6378 
 749      7800
 750 07bf 04       		.byte	0x4
 751 07c0 9E       		.byte	0x9e
 752 07c1 E9070000 		.long	0x7e9
 753 07c5 0A       		.uleb128 0xa
 754 07c6 04       		.byte	0x4
 755 07c7 AF       		.byte	0xaf
 756 07c8 E9070000 		.long	0x7e9
 757 07cc 0A       		.uleb128 0xa
 758 07cd 04       		.byte	0x4
 759 07ce B0       		.byte	0xb0
 760 07cf 22080000 		.long	0x822
 761 07d3 0A       		.uleb128 0xa
 762 07d4 04       		.byte	0x4
 763 07d5 B1       		.byte	0xb1
 764 07d6 5E080000 		.long	0x85e
 765 07da 0A       		.uleb128 0xa
 766 07db 04       		.byte	0x4
 767 07dc B2       		.byte	0xb2
 768 07dd 8B080000 		.long	0x88b
 769 07e1 0A       		.uleb128 0xa
 770 07e2 04       		.byte	0x4
 771 07e3 B3       		.byte	0xb3
 772 07e4 CB080000 		.long	0x8cb
 773 07e8 00       		.byte	0
 774 07e9 0F       		.uleb128 0xf
 775 07ea 736E7072 		.ascii "snprintf\0"
 775      696E7466 
 775      00
 776 07f3 02       		.byte	0x2
 777 07f4 5301     		.word	0x153
 778 07f6 5F5A3873 		.ascii "_Z8snprintfPcyPKcz\0"
 778      6E707269 
 778      6E746650 
 778      6379504B 
 778      637A00
 779 0809 DE000000 		.long	0xde
 780 080d 22080000 		.long	0x822
 781 0811 0C       		.uleb128 0xc
 782 0812 F1000000 		.long	0xf1
 783 0816 0C       		.uleb128 0xc
 784 0817 8E000000 		.long	0x8e
 785 081b 0C       		.uleb128 0xc
 786 081c 12040000 		.long	0x412
 787 0820 10       		.uleb128 0x10
 788 0821 00       		.byte	0
 789 0822 0F       		.uleb128 0xf
 790 0823 76667363 		.ascii "vfscanf\0"
 790      616E6600 
 791 082b 02       		.byte	0x2
 792 082c 1301     		.word	0x113
 793 082e 5F5A3776 		.ascii "_Z7vfscanfP6_iobufPKcPc\0"
 793      66736361 
 793      6E665036 
 793      5F696F62 
 793      7566504B 
 794 0846 DE000000 		.long	0xde
 795 084a 5E080000 		.long	0x85e
 796 084e 0C       		.uleb128 0xc
 797 084f 2E030000 		.long	0x32e
 798 0853 0C       		.uleb128 0xc
 799 0854 12040000 		.long	0x412
 800 0858 0C       		.uleb128 0xc
 801 0859 6E000000 		.long	0x6e
 802 085d 00       		.byte	0
 803 085e 0F       		.uleb128 0xf
 804 085f 76736361 		.ascii "vscanf\0"
 804      6E6600
 805 0866 02       		.byte	0x2
 806 0867 0C01     		.word	0x10c
 807 0869 5F5A3676 		.ascii "_Z6vscanfPKcPc\0"
 807      7363616E 
 807      66504B63 
 807      506300
 808 0878 DE000000 		.long	0xde
 809 087c 8B080000 		.long	0x88b
 810 0880 0C       		.uleb128 0xc
 811 0881 12040000 		.long	0x412
 812 0885 0C       		.uleb128 0xc
 813 0886 6E000000 		.long	0x6e
 814 088a 00       		.byte	0
 815 088b 0F       		.uleb128 0xf
 816 088c 76736E70 		.ascii "vsnprintf\0"
 816      72696E74 
 816      6600
 817 0896 02       		.byte	0x2
 818 0897 5E01     		.word	0x15e
 819 0899 5F5A3976 		.ascii "_Z9vsnprintfPcyPKcS_\0"
 819      736E7072 
 819      696E7466 
 819      50637950 
 819      4B63535F 
 820 08ae DE000000 		.long	0xde
 821 08b2 CB080000 		.long	0x8cb
 822 08b6 0C       		.uleb128 0xc
 823 08b7 F1000000 		.long	0xf1
 824 08bb 0C       		.uleb128 0xc
 825 08bc 8E000000 		.long	0x8e
 826 08c0 0C       		.uleb128 0xc
 827 08c1 12040000 		.long	0x412
 828 08c5 0C       		.uleb128 0xc
 829 08c6 6E000000 		.long	0x6e
 830 08ca 00       		.byte	0
 831 08cb 0F       		.uleb128 0xf
 832 08cc 76737363 		.ascii "vsscanf\0"
 832      616E6600 
 833 08d4 02       		.byte	0x2
 834 08d5 0501     		.word	0x105
 835 08d7 5F5A3776 		.ascii "_Z7vsscanfPKcS0_Pc\0"
 835      73736361 
 835      6E66504B 
 835      6353305F 
 835      506300
 836 08ea DE000000 		.long	0xde
 837 08ee 02090000 		.long	0x902
 838 08f2 0C       		.uleb128 0xc
 839 08f3 12040000 		.long	0x412
 840 08f7 0C       		.uleb128 0xc
 841 08f8 12040000 		.long	0x412
 842 08fc 0C       		.uleb128 0xc
 843 08fd 6E000000 		.long	0x6e
 844 0901 00       		.byte	0
 845 0902 14       		.uleb128 0x14
 846 0903 6D61696E 		.ascii "main\0"
 846      00
 847 0908 01       		.byte	0x1
 848 0909 04       		.byte	0x4
 849 090a DE000000 		.long	0xde
 850 090e 00000000 		.quad	.LFB31
 850      00000000 
 851 0916 24000000 		.quad	.LFE31-.LFB31
 851      00000000 
 852 091e 01       		.uleb128 0x1
 853 091f 9C       		.byte	0x9c
 854 0920 00       		.byte	0
 855              		.section	.debug_abbrev,"dr"
 856              	.Ldebug_abbrev0:
 857 0000 01       		.uleb128 0x1
 858 0001 11       		.uleb128 0x11
 859 0002 01       		.byte	0x1
 860 0003 25       		.uleb128 0x25
 861 0004 08       		.uleb128 0x8
 862 0005 13       		.uleb128 0x13
 863 0006 0B       		.uleb128 0xb
 864 0007 03       		.uleb128 0x3
 865 0008 08       		.uleb128 0x8
 866 0009 1B       		.uleb128 0x1b
 867 000a 08       		.uleb128 0x8
 868 000b 11       		.uleb128 0x11
 869 000c 01       		.uleb128 0x1
 870 000d 12       		.uleb128 0x12
 871 000e 07       		.uleb128 0x7
 872 000f 10       		.uleb128 0x10
 873 0010 17       		.uleb128 0x17
 874 0011 00       		.byte	0
 875 0012 00       		.byte	0
 876 0013 02       		.uleb128 0x2
 877 0014 0F       		.uleb128 0xf
 878 0015 00       		.byte	0
 879 0016 0B       		.uleb128 0xb
 880 0017 0B       		.uleb128 0xb
 881 0018 03       		.uleb128 0x3
 882 0019 08       		.uleb128 0x8
 883 001a 49       		.uleb128 0x49
 884 001b 13       		.uleb128 0x13
 885 001c 00       		.byte	0
 886 001d 00       		.byte	0
 887 001e 03       		.uleb128 0x3
 888 001f 24       		.uleb128 0x24
 889 0020 00       		.byte	0
 890 0021 0B       		.uleb128 0xb
 891 0022 0B       		.uleb128 0xb
 892 0023 3E       		.uleb128 0x3e
 893 0024 0B       		.uleb128 0xb
 894 0025 03       		.uleb128 0x3
 895 0026 08       		.uleb128 0x8
 896 0027 00       		.byte	0
 897 0028 00       		.byte	0
 898 0029 04       		.uleb128 0x4
 899 002a 16       		.uleb128 0x16
 900 002b 00       		.byte	0
 901 002c 03       		.uleb128 0x3
 902 002d 08       		.uleb128 0x8
 903 002e 3A       		.uleb128 0x3a
 904 002f 0B       		.uleb128 0xb
 905 0030 3B       		.uleb128 0x3b
 906 0031 05       		.uleb128 0x5
 907 0032 49       		.uleb128 0x49
 908 0033 13       		.uleb128 0x13
 909 0034 00       		.byte	0
 910 0035 00       		.byte	0
 911 0036 05       		.uleb128 0x5
 912 0037 0F       		.uleb128 0xf
 913 0038 00       		.byte	0
 914 0039 0B       		.uleb128 0xb
 915 003a 0B       		.uleb128 0xb
 916 003b 49       		.uleb128 0x49
 917 003c 13       		.uleb128 0x13
 918 003d 00       		.byte	0
 919 003e 00       		.byte	0
 920 003f 06       		.uleb128 0x6
 921 0040 13       		.uleb128 0x13
 922 0041 01       		.byte	0x1
 923 0042 03       		.uleb128 0x3
 924 0043 08       		.uleb128 0x8
 925 0044 0B       		.uleb128 0xb
 926 0045 0B       		.uleb128 0xb
 927 0046 3A       		.uleb128 0x3a
 928 0047 0B       		.uleb128 0xb
 929 0048 3B       		.uleb128 0x3b
 930 0049 0B       		.uleb128 0xb
 931 004a 01       		.uleb128 0x1
 932 004b 13       		.uleb128 0x13
 933 004c 00       		.byte	0
 934 004d 00       		.byte	0
 935 004e 07       		.uleb128 0x7
 936 004f 0D       		.uleb128 0xd
 937 0050 00       		.byte	0
 938 0051 03       		.uleb128 0x3
 939 0052 08       		.uleb128 0x8
 940 0053 3A       		.uleb128 0x3a
 941 0054 0B       		.uleb128 0xb
 942 0055 3B       		.uleb128 0x3b
 943 0056 0B       		.uleb128 0xb
 944 0057 49       		.uleb128 0x49
 945 0058 13       		.uleb128 0x13
 946 0059 38       		.uleb128 0x38
 947 005a 0B       		.uleb128 0xb
 948 005b 00       		.byte	0
 949 005c 00       		.byte	0
 950 005d 08       		.uleb128 0x8
 951 005e 16       		.uleb128 0x16
 952 005f 00       		.byte	0
 953 0060 03       		.uleb128 0x3
 954 0061 08       		.uleb128 0x8
 955 0062 3A       		.uleb128 0x3a
 956 0063 0B       		.uleb128 0xb
 957 0064 3B       		.uleb128 0x3b
 958 0065 0B       		.uleb128 0xb
 959 0066 49       		.uleb128 0x49
 960 0067 13       		.uleb128 0x13
 961 0068 00       		.byte	0
 962 0069 00       		.byte	0
 963 006a 09       		.uleb128 0x9
 964 006b 39       		.uleb128 0x39
 965 006c 01       		.byte	0x1
 966 006d 03       		.uleb128 0x3
 967 006e 08       		.uleb128 0x8
 968 006f 3A       		.uleb128 0x3a
 969 0070 0B       		.uleb128 0xb
 970 0071 3B       		.uleb128 0x3b
 971 0072 0B       		.uleb128 0xb
 972 0073 01       		.uleb128 0x1
 973 0074 13       		.uleb128 0x13
 974 0075 00       		.byte	0
 975 0076 00       		.byte	0
 976 0077 0A       		.uleb128 0xa
 977 0078 08       		.uleb128 0x8
 978 0079 00       		.byte	0
 979 007a 3A       		.uleb128 0x3a
 980 007b 0B       		.uleb128 0xb
 981 007c 3B       		.uleb128 0x3b
 982 007d 0B       		.uleb128 0xb
 983 007e 18       		.uleb128 0x18
 984 007f 13       		.uleb128 0x13
 985 0080 00       		.byte	0
 986 0081 00       		.byte	0
 987 0082 0B       		.uleb128 0xb
 988 0083 2E       		.uleb128 0x2e
 989 0084 01       		.byte	0x1
 990 0085 3F       		.uleb128 0x3f
 991 0086 19       		.uleb128 0x19
 992 0087 03       		.uleb128 0x3
 993 0088 08       		.uleb128 0x8
 994 0089 3A       		.uleb128 0x3a
 995 008a 0B       		.uleb128 0xb
 996 008b 3B       		.uleb128 0x3b
 997 008c 05       		.uleb128 0x5
 998 008d 3C       		.uleb128 0x3c
 999 008e 19       		.uleb128 0x19
 1000 008f 01       		.uleb128 0x1
 1001 0090 13       		.uleb128 0x13
 1002 0091 00       		.byte	0
 1003 0092 00       		.byte	0
 1004 0093 0C       		.uleb128 0xc
 1005 0094 05       		.uleb128 0x5
 1006 0095 00       		.byte	0
 1007 0096 49       		.uleb128 0x49
 1008 0097 13       		.uleb128 0x13
 1009 0098 00       		.byte	0
 1010 0099 00       		.byte	0
 1011 009a 0D       		.uleb128 0xd
 1012 009b 2E       		.uleb128 0x2e
 1013 009c 01       		.byte	0x1
 1014 009d 3F       		.uleb128 0x3f
 1015 009e 19       		.uleb128 0x19
 1016 009f 03       		.uleb128 0x3
 1017 00a0 08       		.uleb128 0x8
 1018 00a1 3A       		.uleb128 0x3a
 1019 00a2 0B       		.uleb128 0xb
 1020 00a3 3B       		.uleb128 0x3b
 1021 00a4 05       		.uleb128 0x5
 1022 00a5 49       		.uleb128 0x49
 1023 00a6 13       		.uleb128 0x13
 1024 00a7 3C       		.uleb128 0x3c
 1025 00a8 19       		.uleb128 0x19
 1026 00a9 01       		.uleb128 0x1
 1027 00aa 13       		.uleb128 0x13
 1028 00ab 00       		.byte	0
 1029 00ac 00       		.byte	0
 1030 00ad 0E       		.uleb128 0xe
 1031 00ae 26       		.uleb128 0x26
 1032 00af 00       		.byte	0
 1033 00b0 49       		.uleb128 0x49
 1034 00b1 13       		.uleb128 0x13
 1035 00b2 00       		.byte	0
 1036 00b3 00       		.byte	0
 1037 00b4 0F       		.uleb128 0xf
 1038 00b5 2E       		.uleb128 0x2e
 1039 00b6 01       		.byte	0x1
 1040 00b7 3F       		.uleb128 0x3f
 1041 00b8 19       		.uleb128 0x19
 1042 00b9 03       		.uleb128 0x3
 1043 00ba 08       		.uleb128 0x8
 1044 00bb 3A       		.uleb128 0x3a
 1045 00bc 0B       		.uleb128 0xb
 1046 00bd 3B       		.uleb128 0x3b
 1047 00be 05       		.uleb128 0x5
 1048 00bf 6E       		.uleb128 0x6e
 1049 00c0 08       		.uleb128 0x8
 1050 00c1 49       		.uleb128 0x49
 1051 00c2 13       		.uleb128 0x13
 1052 00c3 3C       		.uleb128 0x3c
 1053 00c4 19       		.uleb128 0x19
 1054 00c5 01       		.uleb128 0x1
 1055 00c6 13       		.uleb128 0x13
 1056 00c7 00       		.byte	0
 1057 00c8 00       		.byte	0
 1058 00c9 10       		.uleb128 0x10
 1059 00ca 18       		.uleb128 0x18
 1060 00cb 00       		.byte	0
 1061 00cc 00       		.byte	0
 1062 00cd 00       		.byte	0
 1063 00ce 11       		.uleb128 0x11
 1064 00cf 0F       		.uleb128 0xf
 1065 00d0 00       		.byte	0
 1066 00d1 0B       		.uleb128 0xb
 1067 00d2 0B       		.uleb128 0xb
 1068 00d3 00       		.byte	0
 1069 00d4 00       		.byte	0
 1070 00d5 12       		.uleb128 0x12
 1071 00d6 2E       		.uleb128 0x2e
 1072 00d7 01       		.byte	0x1
 1073 00d8 3F       		.uleb128 0x3f
 1074 00d9 19       		.uleb128 0x19
 1075 00da 03       		.uleb128 0x3
 1076 00db 08       		.uleb128 0x8
 1077 00dc 3A       		.uleb128 0x3a
 1078 00dd 0B       		.uleb128 0xb
 1079 00de 3B       		.uleb128 0x3b
 1080 00df 0B       		.uleb128 0xb
 1081 00e0 6E       		.uleb128 0x6e
 1082 00e1 08       		.uleb128 0x8
 1083 00e2 49       		.uleb128 0x49
 1084 00e3 13       		.uleb128 0x13
 1085 00e4 3C       		.uleb128 0x3c
 1086 00e5 19       		.uleb128 0x19
 1087 00e6 01       		.uleb128 0x1
 1088 00e7 13       		.uleb128 0x13
 1089 00e8 00       		.byte	0
 1090 00e9 00       		.byte	0
 1091 00ea 13       		.uleb128 0x13
 1092 00eb 2E       		.uleb128 0x2e
 1093 00ec 00       		.byte	0
 1094 00ed 3F       		.uleb128 0x3f
 1095 00ee 19       		.uleb128 0x19
 1096 00ef 03       		.uleb128 0x3
 1097 00f0 08       		.uleb128 0x8
 1098 00f1 3A       		.uleb128 0x3a
 1099 00f2 0B       		.uleb128 0xb
 1100 00f3 3B       		.uleb128 0x3b
 1101 00f4 05       		.uleb128 0x5
 1102 00f5 49       		.uleb128 0x49
 1103 00f6 13       		.uleb128 0x13
 1104 00f7 3C       		.uleb128 0x3c
 1105 00f8 19       		.uleb128 0x19
 1106 00f9 00       		.byte	0
 1107 00fa 00       		.byte	0
 1108 00fb 14       		.uleb128 0x14
 1109 00fc 2E       		.uleb128 0x2e
 1110 00fd 00       		.byte	0
 1111 00fe 3F       		.uleb128 0x3f
 1112 00ff 19       		.uleb128 0x19
 1113 0100 03       		.uleb128 0x3
 1114 0101 08       		.uleb128 0x8
 1115 0102 3A       		.uleb128 0x3a
 1116 0103 0B       		.uleb128 0xb
 1117 0104 3B       		.uleb128 0x3b
 1118 0105 0B       		.uleb128 0xb
 1119 0106 49       		.uleb128 0x49
 1120 0107 13       		.uleb128 0x13
 1121 0108 11       		.uleb128 0x11
 1122 0109 01       		.uleb128 0x1
 1123 010a 12       		.uleb128 0x12
 1124 010b 07       		.uleb128 0x7
 1125 010c 40       		.uleb128 0x40
 1126 010d 18       		.uleb128 0x18
 1127 010e 9642     		.uleb128 0x2116
 1128 0110 19       		.uleb128 0x19
 1129 0111 00       		.byte	0
 1130 0112 00       		.byte	0
 1131 0113 00       		.byte	0
 1132              		.section	.debug_aranges,"dr"
 1133 0000 2C000000 		.long	0x2c
 1134 0004 0200     		.word	0x2
 1135 0006 00000000 		.secrel32	.Ldebug_info0
 1136 000a 08       		.byte	0x8
 1137 000b 00       		.byte	0
 1138 000c 0000     		.word	0
 1139 000e 0000     		.word	0
 1140 0010 00000000 		.quad	.Ltext0
 1140      00000000 
 1141 0018 24000000 		.quad	.Letext0-.Ltext0
 1141      00000000 
 1142 0020 00000000 		.quad	0
 1142      00000000 
 1143 0028 00000000 		.quad	0
 1143      00000000 
 1144              		.section	.debug_line,"dr"
 1145              	.Ldebug_line0:
 1146 0000 00010000 		.section	.debug_str,"dr"
 1146      0200E500 
 1146      00000101 
 1146      FB0E0D00 
 1146      01010101 
 1147              		.ident	"GCC: (tdm64-1) 4.9.2"
