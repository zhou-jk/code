   1              		.file	"asm_test.cpp"
   2              		.text
   3              	.Ltext0:
   4              		.cfi_sections	.debug_frame
   5              		.section	.text$_Z5scanfPKcz,"x"
   6              		.linkonce discard
   7              		.globl	_Z5scanfPKcz
   9              		.seh_proc	_Z5scanfPKcz
  10              	_Z5scanfPKcz:
  11              	.LFB2:
  12              		.file 1 "C:/Compiler/MinGW64/x86_64-w64-mingw32/include/stdio.h"
   1:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** /**
   2:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****  * This file has no copyright assigned and is placed in the Public Domain.
   3:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****  * This file is part of the mingw-w64 runtime package.
   4:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****  * No warranty is given; refer to the file DISCLAIMER.PD within this package.
   5:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****  */
   6:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #ifndef _INC_STDIO
   7:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define _INC_STDIO
   8:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
   9:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #include <crtdefs.h>
  10:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
  11:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #include <_mingw_print_push.h>
  12:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
  13:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #pragma pack(push,_CRT_PACKING)
  14:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
  15:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #ifdef __cplusplus
  16:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** extern "C" {
  17:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #endif
  18:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
  19:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define BUFSIZ 512
  20:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define _NFILE _NSTREAM_
  21:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define _NSTREAM_ 512
  22:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define _IOB_ENTRIES 20
  23:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define EOF (-1)
  24:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
  25:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #ifndef _FILE_DEFINED
  26:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   struct _iobuf {
  27:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****     char *_ptr;
  28:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****     int _cnt;
  29:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****     char *_base;
  30:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****     int _flag;
  31:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****     int _file;
  32:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****     int _charbuf;
  33:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****     int _bufsiz;
  34:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****     char *_tmpfname;
  35:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   };
  36:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   typedef struct _iobuf FILE;
  37:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define _FILE_DEFINED
  38:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #endif
  39:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
  40:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #ifdef _POSIX_
  41:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define _P_tmpdir "/"
  42:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define _wP_tmpdir L"/"
  43:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #else
  44:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define _P_tmpdir "\\"
  45:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define _wP_tmpdir L"\\"
  46:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #endif
  47:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
  48:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define L_tmpnam (sizeof(_P_tmpdir) + 12)
  49:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
  50:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #ifdef _POSIX_
  51:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define L_ctermid 9
  52:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define L_cuserid 32
  53:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #endif
  54:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
  55:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define SEEK_CUR 1
  56:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define SEEK_END 2
  57:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define SEEK_SET 0
  58:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
  59:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define	STDIN_FILENO	0
  60:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define	STDOUT_FILENO	1
  61:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define	STDERR_FILENO	2
  62:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
  63:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define FILENAME_MAX 260
  64:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define FOPEN_MAX 20
  65:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define _SYS_OPEN 20
  66:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define TMP_MAX 32767
  67:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
  68:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #ifndef NULL
  69:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #ifdef __cplusplus
  70:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #ifndef _WIN64
  71:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define NULL 0
  72:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #else
  73:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define NULL 0LL
  74:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #endif  /* W64 */
  75:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #else
  76:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define NULL ((void *)0)
  77:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #endif
  78:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #endif
  79:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
  80:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #include <_mingw_off_t.h>
  81:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
  82:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** _CRTIMP FILE *__cdecl __acrt_iob_func(unsigned index);
  83:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #ifndef _STDIO_DEFINED
  84:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #ifdef _WIN64
  85:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   _CRTIMP FILE *__cdecl __iob_func(void);
  86:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define _iob  __iob_func()
  87:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #else
  88:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #ifdef _MSVCRT_
  89:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** extern FILE _iob[];	/* A pointer to an array of FILE */
  90:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define __iob_func()	(_iob)
  91:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #else
  92:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** extern FILE (* __MINGW_IMP_SYMBOL(_iob))[];	/* A pointer to an array of FILE */
  93:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define __iob_func()	(* __MINGW_IMP_SYMBOL(_iob))
  94:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define _iob __iob_func()
  95:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #endif
  96:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #endif
  97:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #endif
  98:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
  99:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #ifndef _FPOS_T_DEFINED
 100:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define _FPOS_T_DEFINED
 101:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #undef _FPOSOFF
 102:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
 103:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #if (!defined(NO_OLDNAMES) || defined(__GNUC__))
 104:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   __MINGW_EXTENSION typedef __int64 fpos_t;
 105:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define _FPOSOFF(fp) ((long)(fp))
 106:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #else
 107:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   __MINGW_EXTENSION typedef long long fpos_t;
 108:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define _FPOSOFF(fp) ((long)(fp))
 109:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #endif
 110:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
 111:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #endif
 112:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
 113:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #ifndef _STDSTREAM_DEFINED
 114:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define _STDSTREAM_DEFINED
 115:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
 116:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define stdin (__acrt_iob_func(0))
 117:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define stdout (__acrt_iob_func(1))
 118:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define stderr (__acrt_iob_func(2))
 119:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #endif
 120:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
 121:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define _IOREAD 0x0001
 122:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define _IOWRT 0x0002
 123:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
 124:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define _IOFBF 0x0000
 125:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define _IOLBF 0x0040
 126:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define _IONBF 0x0004
 127:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
 128:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define _IOMYBUF 0x0008
 129:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define _IOEOF 0x0010
 130:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define _IOERR 0x0020
 131:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define _IOSTRG 0x0040
 132:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define _IORW 0x0080
 133:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #ifdef _POSIX_
 134:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define _IOAPPEND 0x0200
 135:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #endif
 136:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
 137:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define _TWO_DIGIT_EXPONENT 0x1
 138:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
 139:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #if !defined(_UCRTBASE_STDIO_DEFINED) && __MSVCRT_VERSION__ >= 0x1400
 140:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define _UCRTBASE_STDIO_DEFINED
 141:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
 142:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define UCRTBASE_PRINTF_LEGACY_VSPRINTF_NULL_TERMINATION (0x0001)
 143:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define UCRTBASE_PRINTF_STANDARD_SNPRINTF_BEHAVIOUR      (0x0002)
 144:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define UCRTBASE_PRINTF_LEGACY_WIDE_SPECIFIERS           (0x0004)
 145:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define UCRTBASE_PRINTF_LEGACY_MSVCRT_COMPATIBILITY      (0x0008)
 146:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define UCRTBASE_PRINTF_LEGACY_THREE_DIGIT_EXPONENTS     (0x0010)
 147:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
 148:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define UCRTBASE_SCANF_SECURECRT                         (0x0001)
 149:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define UCRTBASE_SCANF_LEGACY_WIDE_SPECIFIERS            (0x0002)
 150:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define UCRTBASE_SCANF_LEGACY_MSVCRT_COMPATIBILITY       (0x0004)
 151:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
 152:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** // Default wide printfs and scanfs to the standard mode
 153:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #ifndef UCRTBASE_PRINTF_DEFAULT_WIDE
 154:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define UCRTBASE_PRINTF_DEFAULT_WIDE 0
 155:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #endif
 156:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #ifndef UCRTBASE_SCANF_DEFAULT_WIDE
 157:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define UCRTBASE_SCANF_DEFAULT_WIDE 0
 158:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #endif
 159:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #endif
 160:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
 161:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #ifndef _STDIO_DEFINED
 162:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** extern
 163:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   __attribute__((__format__ (gnu_scanf, 2, 3))) __MINGW_ATTRIB_NONNULL(2)
 164:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   int __cdecl __mingw_sscanf(const char * __restrict__ _Src,const char * __restrict__ _Format,...);
 165:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** extern
 166:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   __attribute__((__format__ (gnu_scanf, 2, 0))) __MINGW_ATTRIB_NONNULL(2)
 167:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   int __cdecl __mingw_vsscanf (const char * __restrict__ _Str,const char * __restrict__ Format,va_l
 168:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** extern
 169:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   __attribute__((__format__ (gnu_scanf, 1, 2))) __MINGW_ATTRIB_NONNULL(1)
 170:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   int __cdecl __mingw_scanf(const char * __restrict__ _Format,...);
 171:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** extern
 172:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   __attribute__((__format__ (gnu_scanf, 1, 0))) __MINGW_ATTRIB_NONNULL(1)
 173:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   int __cdecl __mingw_vscanf(const char * __restrict__ Format, va_list argp);
 174:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** extern
 175:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   __attribute__((__format__ (gnu_scanf, 2, 3))) __MINGW_ATTRIB_NONNULL(2)
 176:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   int __cdecl __mingw_fscanf(FILE * __restrict__ _File,const char * __restrict__ _Format,...);
 177:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** extern
 178:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   __attribute__((__format__ (gnu_scanf, 2, 0))) __MINGW_ATTRIB_NONNULL(2)
 179:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   int __cdecl __mingw_vfscanf (FILE * __restrict__ fp, const char * __restrict__ Format,va_list arg
 180:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
 181:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** extern
 182:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   __attribute__((__format__ (gnu_printf, 3, 0))) __MINGW_ATTRIB_NONNULL(3)
 183:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   int __cdecl __mingw_vsnprintf(char * __restrict__ _DstBuf,size_t _MaxCount,const char * __restric
 184:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****                                va_list _ArgList);
 185:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** extern
 186:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   __attribute__((__format__ (gnu_printf, 3, 4))) __MINGW_ATTRIB_NONNULL(3)
 187:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   int __cdecl __mingw_snprintf(char * __restrict__ s, size_t n, const char * __restrict__  format, 
 188:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** extern
 189:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   __attribute__((__format__ (gnu_printf, 1, 2))) __MINGW_ATTRIB_NONNULL(1)
 190:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   int __cdecl __mingw_printf(const char * __restrict__ , ... ) __MINGW_NOTHROW;
 191:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** extern
 192:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   __attribute__((__format__ (gnu_printf, 1, 0))) __MINGW_ATTRIB_NONNULL(1)
 193:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   int __cdecl __mingw_vprintf (const char * __restrict__ , va_list) __MINGW_NOTHROW;
 194:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** extern
 195:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   __attribute__((__format__ (gnu_printf, 2, 3))) __MINGW_ATTRIB_NONNULL(2)
 196:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   int __cdecl __mingw_fprintf (FILE * __restrict__ , const char * __restrict__ , ...) __MINGW_NOTHR
 197:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** extern
 198:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   __attribute__((__format__ (gnu_printf, 2, 0))) __MINGW_ATTRIB_NONNULL(2)
 199:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   int __cdecl __mingw_vfprintf (FILE * __restrict__ , const char * __restrict__ , va_list) __MINGW_
 200:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** extern
 201:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   __attribute__((__format__ (gnu_printf, 2, 3))) __MINGW_ATTRIB_NONNULL(2)
 202:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   int __cdecl __mingw_sprintf (char * __restrict__ , const char * __restrict__ , ...) __MINGW_NOTHR
 203:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** extern
 204:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   __attribute__((__format__ (gnu_printf, 2, 0))) __MINGW_ATTRIB_NONNULL(2)
 205:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   int __cdecl __mingw_vsprintf (char * __restrict__ , const char * __restrict__ , va_list) __MINGW_
 206:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** extern
 207:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   __attribute__((__format__ (gnu_printf, 2, 3))) __attribute__((nonnull (1,2)))
 208:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   int __cdecl __mingw_asprintf(char ** __restrict__ , const char * __restrict__ , ...) __MINGW_NOTH
 209:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** extern
 210:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   __attribute__((__format__ (gnu_printf, 2, 0))) __attribute__((nonnull (1,2)))
 211:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   int __cdecl __mingw_vasprintf(char ** __restrict__ , const char * __restrict__ , va_list) __MINGW
 212:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
 213:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #if __MSVCRT_VERSION__ >= 0x1400
 214:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   int __cdecl __stdio_common_vsprintf(unsigned __int64 options, char *str, size_t len, const char *
 215:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   int __cdecl __stdio_common_vfprintf(unsigned __int64 options, FILE *file, const char *format, _lo
 216:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   int __cdecl __stdio_common_vsscanf(unsigned __int64 options, const char *input, size_t length, co
 217:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   int __cdecl __stdio_common_vfscanf(unsigned __int64 options, FILE *file, const char *format, _loc
 218:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #endif
 219:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
 220:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #undef __MINGW_PRINTF_FORMAT
 221:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #undef __MINGW_SCANF_FORMAT
 222:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
 223:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #if defined(__clang__)
 224:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define __MINGW_PRINTF_FORMAT printf
 225:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define __MINGW_SCANF_FORMAT  scanf
 226:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #elif defined(__USE_MINGW_ANSI_STDIO)
 227:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define __MINGW_PRINTF_FORMAT gnu_printf
 228:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define __MINGW_SCANF_FORMAT  gnu_scanf
 229:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #else
 230:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define __MINGW_PRINTF_FORMAT ms_printf
 231:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #define __MINGW_SCANF_FORMAT  ms_scanf
 232:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #endif
 233:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
 234:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #if __USE_MINGW_ANSI_STDIO
 235:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** /*
 236:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****  * User has expressed a preference for C99 conformance...
 237:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****  */
 238:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
 239:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #ifdef _GNU_SOURCE
 240:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** __mingw_ovr
 241:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** __attribute__ ((__format__ (gnu_printf, 2, 3))) __attribute__((nonnull (1,2)))
 242:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** int asprintf(char **__ret, const char *__format, ...)
 243:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** {
 244:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   int __retval;
 245:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
 246:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   __retval = __mingw_vasprintf( __ret, __format, __local_argv );
 247:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   __builtin_va_end( __local_argv );
 248:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   return __retval;
 249:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** }
 250:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
 251:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** __mingw_ovr
 252:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** __attribute__ ((__format__ (gnu_printf, 2, 0))) __attribute__((nonnull (1,2)))
 253:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** int vasprintf(char **__ret, const char *__format, __builtin_va_list __local_argv)
 254:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** {
 255:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   return __mingw_vasprintf( __ret, __format, __local_argv );
 256:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** }
 257:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #endif /* _GNU_SOURCE */
 258:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
 259:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** /* There seems to be a bug about builtins and static overrides of them
 260:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****    in g++.  So we need to do here some trickery.  */
 261:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #ifdef __cplusplus
 262:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** extern "C++" {
 263:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #endif
 264:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
 265:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** __mingw_ovr
 266:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** __attribute__((__format__ (gnu_scanf, 2, 3))) __MINGW_ATTRIB_NONNULL(2)
 267:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** int sscanf(const char *__source, const char *__format, ...)
 268:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** {
 269:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   int __retval;
 270:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
 271:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   __retval = __mingw_vsscanf( __source, __format, __local_argv );
 272:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   __builtin_va_end( __local_argv );
 273:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   return __retval;
 274:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** }
 275:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
 276:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** __mingw_ovr
 277:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** __attribute__((__format__ (gnu_scanf, 1, 2))) __MINGW_ATTRIB_NONNULL(1)
 278:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** int scanf(const char *__format, ...)
 279:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** {
  13              		.loc 1 279 1
  14              		.cfi_startproc
  15 0000 55       		pushq	%rbp
  16              		.seh_pushreg	%rbp
  17              		.cfi_def_cfa_offset 16
  18              		.cfi_offset 6, -16
  19 0001 53       		pushq	%rbx
  20              		.seh_pushreg	%rbx
  21              		.cfi_def_cfa_offset 24
  22              		.cfi_offset 3, -24
  23 0002 4883EC38 		subq	$56, %rsp
  24              		.seh_stackalloc	56
  25              		.cfi_def_cfa_offset 80
  26 0006 488DAC24 		leaq	128(%rsp), %rbp
  26      80000000 
  27              		.seh_setframe	%rbp, 128
  28              		.cfi_def_cfa 6, -48
  29              		.seh_endprologue
  30 000e 48894DD0 		movq	%rcx, -48(%rbp)
  31 0012 488955D8 		movq	%rdx, -40(%rbp)
  32 0016 4C8945E0 		movq	%r8, -32(%rbp)
  33 001a 4C894DE8 		movq	%r9, -24(%rbp)
 280:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   int __retval;
 281:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
  34              		.loc 1 281 53
  35 001e 488D45D8 		leaq	-40(%rbp), %rax
  36 0022 488945A0 		movq	%rax, -96(%rbp)
 282:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   __retval = __mingw_vfscanf( stdin, __format, __local_argv );
  37              		.loc 1 282 29
  38 0026 488B5DA0 		movq	-96(%rbp), %rbx
  39 002a B9000000 		movl	$0, %ecx
  39      00
  40 002f 488B0500 		movq	__imp___acrt_iob_func(%rip), %rax
  40      000000
  41 0036 FFD0     		call	*%rax
  42              	.LVL0:
  43 0038 4989D8   		movq	%rbx, %r8
  44 003b 488B55D0 		movq	-48(%rbp), %rdx
  45 003f 4889C1   		movq	%rax, %rcx
  46 0042 E8000000 		call	__mingw_vfscanf
  46      00
  47 0047 8945AC   		movl	%eax, -84(%rbp)
 283:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   __builtin_va_end( __local_argv );
 284:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   return __retval;
  48              		.loc 1 284 10
  49 004a 8B45AC   		movl	-84(%rbp), %eax
 285:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** }
  50              		.loc 1 285 1
  51 004d 4883C438 		addq	$56, %rsp
  52 0051 5B       		popq	%rbx
  53              		.cfi_restore 3
  54 0052 5D       		popq	%rbp
  55              		.cfi_restore 6
  56              		.cfi_def_cfa 7, -40
  57 0053 C3       		ret
  58              		.cfi_endproc
  59              	.LFE2:
  60              		.seh_endproc
  61 0054 90909090 		.section	.text$_Z6printfPKcz,"x"
  61      90909090 
  61      90909090 
  62              		.linkonce discard
  63              		.globl	_Z6printfPKcz
  65              		.seh_proc	_Z6printfPKcz
  66              	_Z6printfPKcz:
  67              	.LFB8:
 286:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
 287:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** __mingw_ovr
 288:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** __attribute__((__format__ (gnu_scanf, 2, 3))) __MINGW_ATTRIB_NONNULL(2)
 289:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** int fscanf(FILE *__stream, const char *__format, ...)
 290:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** {
 291:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   int __retval;
 292:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
 293:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   __retval = __mingw_vfscanf( __stream, __format, __local_argv );
 294:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   __builtin_va_end( __local_argv );
 295:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   return __retval;
 296:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** }
 297:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
 298:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
 299:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #ifdef __GNUC__
 300:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #pragma GCC diagnostic push
 301:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #pragma GCC diagnostic ignored "-Wshadow"
 302:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #endif
 303:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
 304:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** __mingw_ovr
 305:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** __attribute__((__format__ (gnu_scanf, 2, 0))) __MINGW_ATTRIB_NONNULL(2)
 306:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** int vsscanf (const char *__source, const char *__format, __builtin_va_list __local_argv)
 307:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** {
 308:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   return __mingw_vsscanf( __source, __format, __local_argv );
 309:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** }
 310:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
 311:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** __mingw_ovr
 312:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** __attribute__((__format__ (gnu_scanf, 1, 0))) __MINGW_ATTRIB_NONNULL(1)
 313:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** int vscanf(const char *__format,  __builtin_va_list __local_argv)
 314:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** {
 315:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   return __mingw_vfscanf( stdin, __format, __local_argv );
 316:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** }
 317:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
 318:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** __mingw_ovr
 319:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** __attribute__((__format__ (gnu_scanf, 2, 0))) __MINGW_ATTRIB_NONNULL(2)
 320:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** int vfscanf (FILE *__stream,  const char *__format, __builtin_va_list __local_argv)
 321:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** {
 322:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   return __mingw_vfscanf( __stream, __format, __local_argv );
 323:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** }
 324:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
 325:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #ifdef __GNUC__
 326:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #pragma GCC diagnostic pop
 327:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #endif
 328:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** #endif /* __NO_ISOCEXT */
 329:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
 330:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
 331:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
 332:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** __mingw_ovr
 333:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** __attribute__((__format__ (gnu_printf, 2, 3))) __MINGW_ATTRIB_NONNULL(2)
 334:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** int fprintf (FILE *__stream, const char *__format, ...)
 335:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** {
 336:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   int __retval;
 337:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
 338:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   __retval = __mingw_vfprintf( __stream, __format, __local_argv );
 339:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   __builtin_va_end( __local_argv );
 340:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   return __retval;
 341:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** }
 342:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** 
 343:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** __mingw_ovr
 344:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** __attribute__((__format__ (gnu_printf, 1, 2))) __MINGW_ATTRIB_NONNULL(1)
 345:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** int printf (const char *__format, ...)
 346:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** {
  68              		.loc 1 346 1
  69              		.cfi_startproc
  70 0000 55       		pushq	%rbp
  71              		.seh_pushreg	%rbp
  72              		.cfi_def_cfa_offset 16
  73              		.cfi_offset 6, -16
  74 0001 53       		pushq	%rbx
  75              		.seh_pushreg	%rbx
  76              		.cfi_def_cfa_offset 24
  77              		.cfi_offset 3, -24
  78 0002 4883EC38 		subq	$56, %rsp
  79              		.seh_stackalloc	56
  80              		.cfi_def_cfa_offset 80
  81 0006 488DAC24 		leaq	128(%rsp), %rbp
  81      80000000 
  82              		.seh_setframe	%rbp, 128
  83              		.cfi_def_cfa 6, -48
  84              		.seh_endprologue
  85 000e 48894DD0 		movq	%rcx, -48(%rbp)
  86 0012 488955D8 		movq	%rdx, -40(%rbp)
  87 0016 4C8945E0 		movq	%r8, -32(%rbp)
  88 001a 4C894DE8 		movq	%r9, -24(%rbp)
 347:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   int __retval;
 348:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
  89              		.loc 1 348 53
  90 001e 488D45D8 		leaq	-40(%rbp), %rax
  91 0022 488945A0 		movq	%rax, -96(%rbp)
 349:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   __retval = __mingw_vfprintf( stdout, __format, __local_argv );
  92              		.loc 1 349 30
  93 0026 488B5DA0 		movq	-96(%rbp), %rbx
  94 002a B9010000 		movl	$1, %ecx
  94      00
  95 002f 488B0500 		movq	__imp___acrt_iob_func(%rip), %rax
  95      000000
  96 0036 FFD0     		call	*%rax
  97              	.LVL1:
  98 0038 4989D8   		movq	%rbx, %r8
  99 003b 488B55D0 		movq	-48(%rbp), %rdx
 100 003f 4889C1   		movq	%rax, %rcx
 101 0042 E8000000 		call	__mingw_vfprintf
 101      00
 102 0047 8945AC   		movl	%eax, -84(%rbp)
 350:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   __builtin_va_end( __local_argv );
 351:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h ****   return __retval;
 103              		.loc 1 351 10
 104 004a 8B45AC   		movl	-84(%rbp), %eax
 352:C:/Compiler/MinGW64/x86_64-w64-mingw32/include\stdio.h **** }
 105              		.loc 1 352 1
 106 004d 4883C438 		addq	$56, %rsp
 107 0051 5B       		popq	%rbx
 108              		.cfi_restore 3
 109 0052 5D       		popq	%rbp
 110              		.cfi_restore 6
 111              		.cfi_def_cfa 7, -40
 112 0053 C3       		ret
 113              		.cfi_endproc
 114              	.LFE8:
 115              		.seh_endproc
 116 0054 90909090 		.section .rdata,"dr"
 116      90909090 
 116      90909090 
 117              		.align 4
 118              	_ZL1P:
 119 0000 03000000 		.long	3
 121              	.LC0:
 122 0004 257500   		.ascii "%u\0"
 123 0007 00000000 		.text
 123      00000000 
 123      00
 124              		.globl	main
 126              		.seh_proc	main
 127              	main:
 128              	.LFB44:
 129              		.file 2 "../../../code/code/asm_test.cpp"
   1:../../../code/code/asm_test.cpp **** #include <cstdio>
   2:../../../code/code/asm_test.cpp **** using namespace std;
   3:../../../code/code/asm_test.cpp **** const unsigned int P = 3;
   4:../../../code/code/asm_test.cpp **** int main() {
 130              		.loc 2 4 12
 131              		.cfi_startproc
 132 0000 55       		pushq	%rbp
 133              		.seh_pushreg	%rbp
 134              		.cfi_def_cfa_offset 16
 135              		.cfi_offset 6, -16
 136 0001 4889E5   		movq	%rsp, %rbp
 137              		.seh_setframe	%rbp, 0
 138              		.cfi_def_cfa_register 6
 139 0004 4883EC30 		subq	$48, %rsp
 140              		.seh_stackalloc	48
 141              		.seh_endprologue
 142              		.loc 2 4 12
 143 0008 E8000000 		call	__main
 143      00
 144              	.LVL2:
   5:../../../code/code/asm_test.cpp ****     unsigned a;
   6:../../../code/code/asm_test.cpp ****     scanf("%u", &a);
 145              		.loc 2 6 10
 146 000d 488D45F8 		leaq	-8(%rbp), %rax
 147 0011 4889C2   		movq	%rax, %rdx
 148 0014 488D0D04 		leaq	.LC0(%rip), %rcx
 148      000000
 149 001b E8000000 		call	_Z5scanfPKcz
 149      00
   7:../../../code/code/asm_test.cpp ****     unsigned int b = a % P;
 150              		.loc 2 7 24
 151 0020 8B4DF8   		movl	-8(%rbp), %ecx
 152              		.loc 2 7 18
 153 0023 BAABAAAA 		movl	$-1431655765, %edx
 153      AA
 154 0028 89C8     		movl	%ecx, %eax
 155 002a F7E2     		mull	%edx
 156 002c 89D0     		movl	%edx, %eax
 157 002e D1E8     		shrl	%eax
 158 0030 8945FC   		movl	%eax, -4(%rbp)
 159 0033 8B55FC   		movl	-4(%rbp), %edx
 160 0036 89D0     		movl	%edx, %eax
 161 0038 01C0     		addl	%eax, %eax
 162 003a 01D0     		addl	%edx, %eax
 163 003c 29C1     		subl	%eax, %ecx
 164 003e 89C8     		movl	%ecx, %eax
 165 0040 8945FC   		movl	%eax, -4(%rbp)
   8:../../../code/code/asm_test.cpp ****     printf("%u", b);
 166              		.loc 2 8 11
 167 0043 8B45FC   		movl	-4(%rbp), %eax
 168 0046 89C2     		movl	%eax, %edx
 169 0048 488D0D04 		leaq	.LC0(%rip), %rcx
 169      000000
 170 004f E8000000 		call	_Z6printfPKcz
 170      00
   9:../../../code/code/asm_test.cpp **** }...
 171              		.loc 2 9 1
 172 0054 B8000000 		movl	$0, %eax
 172      00
 173 0059 4883C430 		addq	$48, %rsp
 174 005d 5D       		popq	%rbp
 175              		.cfi_restore 6
 176              		.cfi_def_cfa 7, 8
 177 005e C3       		ret
 178              		.cfi_endproc
 179              	.LFE44:
 180              		.seh_endproc
 181              	.Letext0:
 182              		.file 3 "C:/Compiler/MinGW64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/cstdio"
 183              		.file 4 "C:/Compiler/MinGW64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/x86_64-w64-mingw32/bits/
 184              		.file 5 "C:/Compiler/MinGW64/x86_64-w64-mingw32/include/crtdefs.h"
 185              		.file 6 "<built-in>"
 186 005f 90       		.section	.debug_info,"dr"
 187              	.Ldebug_info0:
 188 0000 A50A0000 		.long	0xaa5
 189 0004 0400     		.word	0x4
 190 0006 00000000 		.secrel32	.Ldebug_abbrev0
 191 000a 08       		.byte	0x8
 192 000b 01       		.uleb128 0x1
 193 000c 474E5520 		.ascii "GNU C++98 8.1.0 -mtune=core2 -march=nocona -g -std=gnu++98\0"
 193      432B2B39 
 193      3820382E 
 193      312E3020 
 193      2D6D7475 
 194 0047 04       		.byte	0x4
 195 0048 2E2E5C2E 		.ascii "..\\..\\..\\code\\code\\asm_test.cpp\0"
 195      2E5C2E2E 
 195      5C636F64 
 195      655C636F 
 195      64655C61 
 196 0068 653A5C4F 		.ascii "e:\\OI-Files\\yz\\\322\273\326\320\0"
 196      492D4669 
 196      6C65735C 
 196      797A5CD2 
 196      BBD6D000 
 197 007c 00000000 		.secrel32	.Ldebug_ranges0+0
 198 0080 00000000 		.quad	0
 198      00000000 
 199 0088 00000000 		.secrel32	.Ldebug_line0
 200 008c 02       		.uleb128 0x2
 201 008d 73746400 		.ascii "std\0"
 202 0091 06       		.byte	0x6
 203 0092 00       		.byte	0
 204 0093 FE010000 		.long	0x1fe
 205 0097 03       		.uleb128 0x3
 206 0098 5F5F6378 		.ascii "__cxx11\0"
 206      78313100 
 207 00a0 04       		.byte	0x4
 208 00a1 0401     		.word	0x104
 209 00a3 41       		.byte	0x41
 210 00a4 04       		.uleb128 0x4
 211 00a5 04       		.byte	0x4
 212 00a6 0401     		.word	0x104
 213 00a8 41       		.byte	0x41
 214 00a9 97000000 		.long	0x97
 215 00ad 05       		.uleb128 0x5
 216 00ae 03       		.byte	0x3
 217 00af 62       		.byte	0x62
 218 00b0 0B       		.byte	0xb
 219 00b1 B4030000 		.long	0x3b4
 220 00b5 05       		.uleb128 0x5
 221 00b6 03       		.byte	0x3
 222 00b7 63       		.byte	0x63
 223 00b8 0B       		.byte	0xb
 224 00b9 C1030000 		.long	0x3c1
 225 00bd 05       		.uleb128 0x5
 226 00be 03       		.byte	0x3
 227 00bf 65       		.byte	0x65
 228 00c0 0B       		.byte	0xb
 229 00c1 D5030000 		.long	0x3d5
 230 00c5 05       		.uleb128 0x5
 231 00c6 03       		.byte	0x3
 232 00c7 66       		.byte	0x66
 233 00c8 0B       		.byte	0xb
 234 00c9 F3030000 		.long	0x3f3
 235 00cd 05       		.uleb128 0x5
 236 00ce 03       		.byte	0x3
 237 00cf 67       		.byte	0x67
 238 00d0 0B       		.byte	0xb
 239 00d1 0D040000 		.long	0x40d
 240 00d5 05       		.uleb128 0x5
 241 00d6 03       		.byte	0x3
 242 00d7 68       		.byte	0x68
 243 00d8 0B       		.byte	0xb
 244 00d9 25040000 		.long	0x425
 245 00dd 05       		.uleb128 0x5
 246 00de 03       		.byte	0x3
 247 00df 69       		.byte	0x69
 248 00e0 0B       		.byte	0xb
 249 00e1 3F040000 		.long	0x43f
 250 00e5 05       		.uleb128 0x5
 251 00e6 03       		.byte	0x3
 252 00e7 6A       		.byte	0x6a
 253 00e8 0B       		.byte	0xb
 254 00e9 59040000 		.long	0x459
 255 00ed 05       		.uleb128 0x5
 256 00ee 03       		.byte	0x3
 257 00ef 6B       		.byte	0x6b
 258 00f0 0B       		.byte	0xb
 259 00f1 72040000 		.long	0x472
 260 00f5 05       		.uleb128 0x5
 261 00f6 03       		.byte	0x3
 262 00f7 6C       		.byte	0x6c
 263 00f8 0B       		.byte	0xb
 264 00f9 98040000 		.long	0x498
 265 00fd 05       		.uleb128 0x5
 266 00fe 03       		.byte	0x3
 267 00ff 6D       		.byte	0x6d
 268 0100 0B       		.byte	0xb
 269 0101 BB040000 		.long	0x4bb
 270 0105 05       		.uleb128 0x5
 271 0106 03       		.byte	0x3
 272 0107 6E       		.byte	0x6e
 273 0108 0B       		.byte	0xb
 274 0109 DF040000 		.long	0x4df
 275 010d 05       		.uleb128 0x5
 276 010e 03       		.byte	0x3
 277 010f 71       		.byte	0x71
 278 0110 0B       		.byte	0xb
 279 0111 17050000 		.long	0x517
 280 0115 05       		.uleb128 0x5
 281 0116 03       		.byte	0x3
 282 0117 72       		.byte	0x72
 283 0118 0B       		.byte	0xb
 284 0119 41050000 		.long	0x541
 285 011d 05       		.uleb128 0x5
 286 011e 03       		.byte	0x3
 287 011f 73       		.byte	0x73
 288 0120 0B       		.byte	0xb
 289 0121 66050000 		.long	0x566
 290 0125 05       		.uleb128 0x5
 291 0126 03       		.byte	0x3
 292 0127 74       		.byte	0x74
 293 0128 0B       		.byte	0xb
 294 0129 9C050000 		.long	0x59c
 295 012d 05       		.uleb128 0x5
 296 012e 03       		.byte	0x3
 297 012f 75       		.byte	0x75
 298 0130 0B       		.byte	0xb
 299 0131 BF050000 		.long	0x5bf
 300 0135 05       		.uleb128 0x5
 301 0136 03       		.byte	0x3
 302 0137 76       		.byte	0x76
 303 0138 0B       		.byte	0xb
 304 0139 E5050000 		.long	0x5e5
 305 013d 05       		.uleb128 0x5
 306 013e 03       		.byte	0x3
 307 013f 78       		.byte	0x78
 308 0140 0B       		.byte	0xb
 309 0141 FE050000 		.long	0x5fe
 310 0145 05       		.uleb128 0x5
 311 0146 03       		.byte	0x3
 312 0147 79       		.byte	0x79
 313 0148 0B       		.byte	0xb
 314 0149 16060000 		.long	0x616
 315 014d 05       		.uleb128 0x5
 316 014e 03       		.byte	0x3
 317 014f 7C       		.byte	0x7c
 318 0150 0B       		.byte	0xb
 319 0151 27060000 		.long	0x627
 320 0155 05       		.uleb128 0x5
 321 0156 03       		.byte	0x3
 322 0157 7E       		.byte	0x7e
 323 0158 0B       		.byte	0xb
 324 0159 3F060000 		.long	0x63f
 325 015d 05       		.uleb128 0x5
 326 015e 03       		.byte	0x3
 327 015f 7F       		.byte	0x7f
 328 0160 0B       		.byte	0xb
 329 0161 55060000 		.long	0x655
 330 0165 05       		.uleb128 0x5
 331 0166 03       		.byte	0x3
 332 0167 83       		.byte	0x83
 333 0168 0B       		.byte	0xb
 334 0169 C9060000 		.long	0x6c9
 335 016d 05       		.uleb128 0x5
 336 016e 03       		.byte	0x3
 337 016f 84       		.byte	0x84
 338 0170 0B       		.byte	0xb
 339 0171 E3060000 		.long	0x6e3
 340 0175 05       		.uleb128 0x5
 341 0176 03       		.byte	0x3
 342 0177 85       		.byte	0x85
 343 0178 0B       		.byte	0xb
 344 0179 02070000 		.long	0x702
 345 017d 05       		.uleb128 0x5
 346 017e 03       		.byte	0x3
 347 017f 86       		.byte	0x86
 348 0180 0B       		.byte	0xb
 349 0181 18070000 		.long	0x718
 350 0185 05       		.uleb128 0x5
 351 0186 03       		.byte	0x3
 352 0187 87       		.byte	0x87
 353 0188 0B       		.byte	0xb
 354 0189 8A070000 		.long	0x78a
 355 018d 05       		.uleb128 0x5
 356 018e 03       		.byte	0x3
 357 018f 88       		.byte	0x88
 358 0190 0B       		.byte	0xb
 359 0191 A5070000 		.long	0x7a5
 360 0195 05       		.uleb128 0x5
 361 0196 03       		.byte	0x3
 362 0197 89       		.byte	0x89
 363 0198 0B       		.byte	0xb
 364 0199 CF070000 		.long	0x7cf
 365 019d 05       		.uleb128 0x5
 366 019e 03       		.byte	0x3
 367 019f 8A       		.byte	0x8a
 368 01a0 0B       		.byte	0xb
 369 01a1 01080000 		.long	0x801
 370 01a5 05       		.uleb128 0x5
 371 01a6 03       		.byte	0x3
 372 01a7 8B       		.byte	0x8b
 373 01a8 0B       		.byte	0xb
 374 01a9 32080000 		.long	0x832
 375 01ad 05       		.uleb128 0x5
 376 01ae 03       		.byte	0x3
 377 01af 8D       		.byte	0x8d
 378 01b0 0B       		.byte	0xb
 379 01b1 43080000 		.long	0x843
 380 01b5 05       		.uleb128 0x5
 381 01b6 03       		.byte	0x3
 382 01b7 8F       		.byte	0x8f
 383 01b8 0B       		.byte	0xb
 384 01b9 5D080000 		.long	0x85d
 385 01bd 05       		.uleb128 0x5
 386 01be 03       		.byte	0x3
 387 01bf 90       		.byte	0x90
 388 01c0 0B       		.byte	0xb
 389 01c1 7C080000 		.long	0x87c
 390 01c5 05       		.uleb128 0x5
 391 01c6 03       		.byte	0x3
 392 01c7 91       		.byte	0x91
 393 01c8 0B       		.byte	0xb
 394 01c9 BB080000 		.long	0x8bb
 395 01cd 05       		.uleb128 0x5
 396 01ce 03       		.byte	0x3
 397 01cf 92       		.byte	0x92
 398 01d0 0B       		.byte	0xb
 399 01d1 EB080000 		.long	0x8eb
 400 01d5 05       		.uleb128 0x5
 401 01d6 03       		.byte	0x3
 402 01d7 B9       		.byte	0xb9
 403 01d8 16       		.byte	0x16
 404 01d9 24090000 		.long	0x924
 405 01dd 05       		.uleb128 0x5
 406 01de 03       		.byte	0x3
 407 01df BA       		.byte	0xba
 408 01e0 16       		.byte	0x16
 409 01e1 5E090000 		.long	0x95e
 410 01e5 05       		.uleb128 0x5
 411 01e6 03       		.byte	0x3
 412 01e7 BB       		.byte	0xbb
 413 01e8 16       		.byte	0x16
 414 01e9 9B090000 		.long	0x99b
 415 01ed 05       		.uleb128 0x5
 416 01ee 03       		.byte	0x3
 417 01ef BC       		.byte	0xbc
 418 01f0 16       		.byte	0x16
 419 01f1 C9090000 		.long	0x9c9
 420 01f5 05       		.uleb128 0x5
 421 01f6 03       		.byte	0x3
 422 01f7 BD       		.byte	0xbd
 423 01f8 16       		.byte	0x16
 424 01f9 0A0A0000 		.long	0xa0a
 425 01fd 00       		.byte	0
 426 01fe 06       		.uleb128 0x6
 427 01ff 5F5F676E 		.ascii "__gnu_cxx\0"
 427      755F6378 
 427      7800
 428 0209 04       		.byte	0x4
 429 020a 0601     		.word	0x106
 430 020c 0B       		.byte	0xb
 431 020d 50020000 		.long	0x250
 432 0211 03       		.uleb128 0x3
 433 0212 5F5F6378 		.ascii "__cxx11\0"
 433      78313100 
 434 021a 04       		.byte	0x4
 435 021b 0801     		.word	0x108
 436 021d 41       		.byte	0x41
 437 021e 04       		.uleb128 0x4
 438 021f 04       		.byte	0x4
 439 0220 0801     		.word	0x108
 440 0222 41       		.byte	0x41
 441 0223 11020000 		.long	0x211
 442 0227 05       		.uleb128 0x5
 443 0228 03       		.byte	0x3
 444 0229 AF       		.byte	0xaf
 445 022a 0B       		.byte	0xb
 446 022b 24090000 		.long	0x924
 447 022f 05       		.uleb128 0x5
 448 0230 03       		.byte	0x3
 449 0231 B0       		.byte	0xb0
 450 0232 0B       		.byte	0xb
 451 0233 5E090000 		.long	0x95e
 452 0237 05       		.uleb128 0x5
 453 0238 03       		.byte	0x3
 454 0239 B1       		.byte	0xb1
 455 023a 0B       		.byte	0xb
 456 023b 9B090000 		.long	0x99b
 457 023f 05       		.uleb128 0x5
 458 0240 03       		.byte	0x3
 459 0241 B2       		.byte	0xb2
 460 0242 0B       		.byte	0xb
 461 0243 C9090000 		.long	0x9c9
 462 0247 05       		.uleb128 0x5
 463 0248 03       		.byte	0x3
 464 0249 B3       		.byte	0xb3
 465 024a 0B       		.byte	0xb
 466 024b 0A0A0000 		.long	0xa0a
 467 024f 00       		.byte	0
 468 0250 07       		.uleb128 0x7
 469 0251 08       		.byte	0x8
 470 0252 5F5F6275 		.ascii "__builtin_va_list\0"
 470      696C7469 
 470      6E5F7661 
 470      5F6C6973 
 470      7400
 471 0264 68020000 		.long	0x268
 472 0268 08       		.uleb128 0x8
 473 0269 01       		.byte	0x1
 474 026a 06       		.byte	0x6
 475 026b 63686172 		.ascii "char\0"
 475      00
 476 0270 09       		.uleb128 0x9
 477 0271 68020000 		.long	0x268
 478 0275 0A       		.uleb128 0xa
 479 0276 73697A65 		.ascii "size_t\0"
 479      5F7400
 480 027d 05       		.byte	0x5
 481 027e 23       		.byte	0x23
 482 027f 2C       		.byte	0x2c
 483 0280 84020000 		.long	0x284
 484 0284 08       		.uleb128 0x8
 485 0285 08       		.byte	0x8
 486 0286 07       		.byte	0x7
 487 0287 6C6F6E67 		.ascii "long long unsigned int\0"
 487      206C6F6E 
 487      6720756E 
 487      7369676E 
 487      65642069 
 488 029e 08       		.uleb128 0x8
 489 029f 08       		.byte	0x8
 490 02a0 05       		.byte	0x5
 491 02a1 6C6F6E67 		.ascii "long long int\0"
 491      206C6F6E 
 491      6720696E 
 491      7400
 492 02af 08       		.uleb128 0x8
 493 02b0 02       		.byte	0x2
 494 02b1 07       		.byte	0x7
 495 02b2 73686F72 		.ascii "short unsigned int\0"
 495      7420756E 
 495      7369676E 
 495      65642069 
 495      6E7400
 496 02c5 08       		.uleb128 0x8
 497 02c6 04       		.byte	0x4
 498 02c7 05       		.byte	0x5
 499 02c8 696E7400 		.ascii "int\0"
 500 02cc 08       		.uleb128 0x8
 501 02cd 04       		.byte	0x4
 502 02ce 05       		.byte	0x5
 503 02cf 6C6F6E67 		.ascii "long int\0"
 503      20696E74 
 503      00
 504 02d8 0B       		.uleb128 0xb
 505 02d9 08       		.byte	0x8
 506 02da 68020000 		.long	0x268
 507 02de 08       		.uleb128 0x8
 508 02df 02       		.byte	0x2
 509 02e0 07       		.byte	0x7
 510 02e1 77636861 		.ascii "wchar_t\0"
 510      725F7400 
 511 02e9 08       		.uleb128 0x8
 512 02ea 04       		.byte	0x4
 513 02eb 07       		.byte	0x7
 514 02ec 756E7369 		.ascii "unsigned int\0"
 514      676E6564 
 514      20696E74 
 514      00
 515 02f9 09       		.uleb128 0x9
 516 02fa E9020000 		.long	0x2e9
 517 02fe 08       		.uleb128 0x8
 518 02ff 04       		.byte	0x4
 519 0300 07       		.byte	0x7
 520 0301 6C6F6E67 		.ascii "long unsigned int\0"
 520      20756E73 
 520      69676E65 
 520      6420696E 
 520      7400
 521 0313 08       		.uleb128 0x8
 522 0314 01       		.byte	0x1
 523 0315 08       		.byte	0x8
 524 0316 756E7369 		.ascii "unsigned char\0"
 524      676E6564 
 524      20636861 
 524      7200
 525 0324 0C       		.uleb128 0xc
 526 0325 5F696F62 		.ascii "_iobuf\0"
 526      756600
 527 032c 30       		.byte	0x30
 528 032d 01       		.byte	0x1
 529 032e 1A       		.byte	0x1a
 530 032f 0A       		.byte	0xa
 531 0330 B4030000 		.long	0x3b4
 532 0334 0D       		.uleb128 0xd
 533 0335 5F707472 		.ascii "_ptr\0"
 533      00
 534 033a 01       		.byte	0x1
 535 033b 1B       		.byte	0x1b
 536 033c 0B       		.byte	0xb
 537 033d D8020000 		.long	0x2d8
 538 0341 00       		.byte	0
 539 0342 0D       		.uleb128 0xd
 540 0343 5F636E74 		.ascii "_cnt\0"
 540      00
 541 0348 01       		.byte	0x1
 542 0349 1C       		.byte	0x1c
 543 034a 09       		.byte	0x9
 544 034b C5020000 		.long	0x2c5
 545 034f 08       		.byte	0x8
 546 0350 0D       		.uleb128 0xd
 547 0351 5F626173 		.ascii "_base\0"
 547      6500
 548 0357 01       		.byte	0x1
 549 0358 1D       		.byte	0x1d
 550 0359 0B       		.byte	0xb
 551 035a D8020000 		.long	0x2d8
 552 035e 10       		.byte	0x10
 553 035f 0D       		.uleb128 0xd
 554 0360 5F666C61 		.ascii "_flag\0"
 554      6700
 555 0366 01       		.byte	0x1
 556 0367 1E       		.byte	0x1e
 557 0368 09       		.byte	0x9
 558 0369 C5020000 		.long	0x2c5
 559 036d 18       		.byte	0x18
 560 036e 0D       		.uleb128 0xd
 561 036f 5F66696C 		.ascii "_file\0"
 561      6500
 562 0375 01       		.byte	0x1
 563 0376 1F       		.byte	0x1f
 564 0377 09       		.byte	0x9
 565 0378 C5020000 		.long	0x2c5
 566 037c 1C       		.byte	0x1c
 567 037d 0D       		.uleb128 0xd
 568 037e 5F636861 		.ascii "_charbuf\0"
 568      72627566 
 568      00
 569 0387 01       		.byte	0x1
 570 0388 20       		.byte	0x20
 571 0389 09       		.byte	0x9
 572 038a C5020000 		.long	0x2c5
 573 038e 20       		.byte	0x20
 574 038f 0D       		.uleb128 0xd
 575 0390 5F627566 		.ascii "_bufsiz\0"
 575      73697A00 
 576 0398 01       		.byte	0x1
 577 0399 21       		.byte	0x21
 578 039a 09       		.byte	0x9
 579 039b C5020000 		.long	0x2c5
 580 039f 24       		.byte	0x24
 581 03a0 0D       		.uleb128 0xd
 582 03a1 5F746D70 		.ascii "_tmpfname\0"
 582      666E616D 
 582      6500
 583 03ab 01       		.byte	0x1
 584 03ac 22       		.byte	0x22
 585 03ad 0B       		.byte	0xb
 586 03ae D8020000 		.long	0x2d8
 587 03b2 28       		.byte	0x28
 588 03b3 00       		.byte	0
 589 03b4 0A       		.uleb128 0xa
 590 03b5 46494C45 		.ascii "FILE\0"
 590      00
 591 03ba 01       		.byte	0x1
 592 03bb 24       		.byte	0x24
 593 03bc 19       		.byte	0x19
 594 03bd 24030000 		.long	0x324
 595 03c1 0A       		.uleb128 0xa
 596 03c2 66706F73 		.ascii "fpos_t\0"
 596      5F7400
 597 03c9 01       		.byte	0x1
 598 03ca 68       		.byte	0x68
 599 03cb 25       		.byte	0x25
 600 03cc 9E020000 		.long	0x29e
 601 03d0 09       		.uleb128 0x9
 602 03d1 C1030000 		.long	0x3c1
 603 03d5 0E       		.uleb128 0xe
 604 03d6 636C6561 		.ascii "clearerr\0"
 604      72657272 
 604      00
 605 03df 01       		.byte	0x1
 606 03e0 4202     		.word	0x242
 607 03e2 10       		.byte	0x10
 608 03e3 ED030000 		.long	0x3ed
 609 03e7 0F       		.uleb128 0xf
 610 03e8 ED030000 		.long	0x3ed
 611 03ec 00       		.byte	0
 612 03ed 0B       		.uleb128 0xb
 613 03ee 08       		.byte	0x8
 614 03ef B4030000 		.long	0x3b4
 615 03f3 10       		.uleb128 0x10
 616 03f4 66636C6F 		.ascii "fclose\0"
 616      736500
 617 03fb 01       		.byte	0x1
 618 03fc 4302     		.word	0x243
 619 03fe 0F       		.byte	0xf
 620 03ff C5020000 		.long	0x2c5
 621 0403 0D040000 		.long	0x40d
 622 0407 0F       		.uleb128 0xf
 623 0408 ED030000 		.long	0x3ed
 624 040c 00       		.byte	0
 625 040d 10       		.uleb128 0x10
 626 040e 66656F66 		.ascii "feof\0"
 626      00
 627 0413 01       		.byte	0x1
 628 0414 4A02     		.word	0x24a
 629 0416 0F       		.byte	0xf
 630 0417 C5020000 		.long	0x2c5
 631 041b 25040000 		.long	0x425
 632 041f 0F       		.uleb128 0xf
 633 0420 ED030000 		.long	0x3ed
 634 0424 00       		.byte	0
 635 0425 10       		.uleb128 0x10
 636 0426 66657272 		.ascii "ferror\0"
 636      6F7200
 637 042d 01       		.byte	0x1
 638 042e 4B02     		.word	0x24b
 639 0430 0F       		.byte	0xf
 640 0431 C5020000 		.long	0x2c5
 641 0435 3F040000 		.long	0x43f
 642 0439 0F       		.uleb128 0xf
 643 043a ED030000 		.long	0x3ed
 644 043e 00       		.byte	0
 645 043f 10       		.uleb128 0x10
 646 0440 66666C75 		.ascii "fflush\0"
 646      736800
 647 0447 01       		.byte	0x1
 648 0448 4C02     		.word	0x24c
 649 044a 0F       		.byte	0xf
 650 044b C5020000 		.long	0x2c5
 651 044f 59040000 		.long	0x459
 652 0453 0F       		.uleb128 0xf
 653 0454 ED030000 		.long	0x3ed
 654 0458 00       		.byte	0
 655 0459 10       		.uleb128 0x10
 656 045a 66676574 		.ascii "fgetc\0"
 656      6300
 657 0460 01       		.byte	0x1
 658 0461 4D02     		.word	0x24d
 659 0463 0F       		.byte	0xf
 660 0464 C5020000 		.long	0x2c5
 661 0468 72040000 		.long	0x472
 662 046c 0F       		.uleb128 0xf
 663 046d ED030000 		.long	0x3ed
 664 0471 00       		.byte	0
 665 0472 10       		.uleb128 0x10
 666 0473 66676574 		.ascii "fgetpos\0"
 666      706F7300 
 667 047b 01       		.byte	0x1
 668 047c 4F02     		.word	0x24f
 669 047e 0F       		.byte	0xf
 670 047f C5020000 		.long	0x2c5
 671 0483 92040000 		.long	0x492
 672 0487 0F       		.uleb128 0xf
 673 0488 ED030000 		.long	0x3ed
 674 048c 0F       		.uleb128 0xf
 675 048d 92040000 		.long	0x492
 676 0491 00       		.byte	0
 677 0492 0B       		.uleb128 0xb
 678 0493 08       		.byte	0x8
 679 0494 C1030000 		.long	0x3c1
 680 0498 10       		.uleb128 0x10
 681 0499 66676574 		.ascii "fgets\0"
 681      7300
 682 049f 01       		.byte	0x1
 683 04a0 5102     		.word	0x251
 684 04a2 11       		.byte	0x11
 685 04a3 D8020000 		.long	0x2d8
 686 04a7 BB040000 		.long	0x4bb
 687 04ab 0F       		.uleb128 0xf
 688 04ac D8020000 		.long	0x2d8
 689 04b0 0F       		.uleb128 0xf
 690 04b1 C5020000 		.long	0x2c5
 691 04b5 0F       		.uleb128 0xf
 692 04b6 ED030000 		.long	0x3ed
 693 04ba 00       		.byte	0
 694 04bb 10       		.uleb128 0x10
 695 04bc 666F7065 		.ascii "fopen\0"
 695      6E00
 696 04c2 01       		.byte	0x1
 697 04c3 5802     		.word	0x258
 698 04c5 11       		.byte	0x11
 699 04c6 ED030000 		.long	0x3ed
 700 04ca D9040000 		.long	0x4d9
 701 04ce 0F       		.uleb128 0xf
 702 04cf D9040000 		.long	0x4d9
 703 04d3 0F       		.uleb128 0xf
 704 04d4 D9040000 		.long	0x4d9
 705 04d8 00       		.byte	0
 706 04d9 0B       		.uleb128 0xb
 707 04da 08       		.byte	0x8
 708 04db 70020000 		.long	0x270
 709 04df 11       		.uleb128 0x11
 710 04e0 66707269 		.ascii "fprintf\0"
 710      6E746600 
 711 04e8 01       		.byte	0x1
 712 04e9 4E01     		.word	0x14e
 713 04eb 05       		.byte	0x5
 714 04ec 5F5A3766 		.ascii "_Z7fprintfP6_iobufPKcz\0"
 714      7072696E 
 714      74665036 
 714      5F696F62 
 714      7566504B 
 715 0503 C5020000 		.long	0x2c5
 716 0507 17050000 		.long	0x517
 717 050b 0F       		.uleb128 0xf
 718 050c ED030000 		.long	0x3ed
 719 0510 0F       		.uleb128 0xf
 720 0511 D9040000 		.long	0x4d9
 721 0515 12       		.uleb128 0x12
 722 0516 00       		.byte	0
 723 0517 10       		.uleb128 0x10
 724 0518 66726561 		.ascii "fread\0"
 724      6400
 725 051e 01       		.byte	0x1
 726 051f 5D02     		.word	0x25d
 727 0521 12       		.byte	0x12
 728 0522 75020000 		.long	0x275
 729 0526 3F050000 		.long	0x53f
 730 052a 0F       		.uleb128 0xf
 731 052b 3F050000 		.long	0x53f
 732 052f 0F       		.uleb128 0xf
 733 0530 75020000 		.long	0x275
 734 0534 0F       		.uleb128 0xf
 735 0535 75020000 		.long	0x275
 736 0539 0F       		.uleb128 0xf
 737 053a ED030000 		.long	0x3ed
 738 053e 00       		.byte	0
 739 053f 13       		.uleb128 0x13
 740 0540 08       		.byte	0x8
 741 0541 10       		.uleb128 0x10
 742 0542 6672656F 		.ascii "freopen\0"
 742      70656E00 
 743 054a 01       		.byte	0x1
 744 054b 5E02     		.word	0x25e
 745 054d 11       		.byte	0x11
 746 054e ED030000 		.long	0x3ed
 747 0552 66050000 		.long	0x566
 748 0556 0F       		.uleb128 0xf
 749 0557 D9040000 		.long	0x4d9
 750 055b 0F       		.uleb128 0xf
 751 055c D9040000 		.long	0x4d9
 752 0560 0F       		.uleb128 0xf
 753 0561 ED030000 		.long	0x3ed
 754 0565 00       		.byte	0
 755 0566 11       		.uleb128 0x11
 756 0567 66736361 		.ascii "fscanf\0"
 756      6E6600
 757 056e 01       		.byte	0x1
 758 056f 2101     		.word	0x121
 759 0571 05       		.byte	0x5
 760 0572 5F5A3666 		.ascii "_Z6fscanfP6_iobufPKcz\0"
 760      7363616E 
 760      6650365F 
 760      696F6275 
 760      66504B63 
 761 0588 C5020000 		.long	0x2c5
 762 058c 9C050000 		.long	0x59c
 763 0590 0F       		.uleb128 0xf
 764 0591 ED030000 		.long	0x3ed
 765 0595 0F       		.uleb128 0xf
 766 0596 D9040000 		.long	0x4d9
 767 059a 12       		.uleb128 0x12
 768 059b 00       		.byte	0
 769 059c 10       		.uleb128 0x10
 770 059d 66736565 		.ascii "fseek\0"
 770      6B00
 771 05a3 01       		.byte	0x1
 772 05a4 6102     		.word	0x261
 773 05a6 0F       		.byte	0xf
 774 05a7 C5020000 		.long	0x2c5
 775 05ab BF050000 		.long	0x5bf
 776 05af 0F       		.uleb128 0xf
 777 05b0 ED030000 		.long	0x3ed
 778 05b4 0F       		.uleb128 0xf
 779 05b5 CC020000 		.long	0x2cc
 780 05b9 0F       		.uleb128 0xf
 781 05ba C5020000 		.long	0x2c5
 782 05be 00       		.byte	0
 783 05bf 10       		.uleb128 0x10
 784 05c0 66736574 		.ascii "fsetpos\0"
 784      706F7300 
 785 05c8 01       		.byte	0x1
 786 05c9 5F02     		.word	0x25f
 787 05cb 0F       		.byte	0xf
 788 05cc C5020000 		.long	0x2c5
 789 05d0 DF050000 		.long	0x5df
 790 05d4 0F       		.uleb128 0xf
 791 05d5 ED030000 		.long	0x3ed
 792 05d9 0F       		.uleb128 0xf
 793 05da DF050000 		.long	0x5df
 794 05de 00       		.byte	0
 795 05df 0B       		.uleb128 0xb
 796 05e0 08       		.byte	0x8
 797 05e1 D0030000 		.long	0x3d0
 798 05e5 10       		.uleb128 0x10
 799 05e6 6674656C 		.ascii "ftell\0"
 799      6C00
 800 05ec 01       		.byte	0x1
 801 05ed 6202     		.word	0x262
 802 05ef 10       		.byte	0x10
 803 05f0 CC020000 		.long	0x2cc
 804 05f4 FE050000 		.long	0x5fe
 805 05f8 0F       		.uleb128 0xf
 806 05f9 ED030000 		.long	0x3ed
 807 05fd 00       		.byte	0
 808 05fe 10       		.uleb128 0x10
 809 05ff 67657463 		.ascii "getc\0"
 809      00
 810 0604 01       		.byte	0x1
 811 0605 8F02     		.word	0x28f
 812 0607 0F       		.byte	0xf
 813 0608 C5020000 		.long	0x2c5
 814 060c 16060000 		.long	0x616
 815 0610 0F       		.uleb128 0xf
 816 0611 ED030000 		.long	0x3ed
 817 0615 00       		.byte	0
 818 0616 14       		.uleb128 0x14
 819 0617 67657463 		.ascii "getchar\0"
 819      68617200 
 820 061f 01       		.byte	0x1
 821 0620 9002     		.word	0x290
 822 0622 0F       		.byte	0xf
 823 0623 C5020000 		.long	0x2c5
 824 0627 10       		.uleb128 0x10
 825 0628 67657473 		.ascii "gets\0"
 825      00
 826 062d 01       		.byte	0x1
 827 062e 9202     		.word	0x292
 828 0630 11       		.byte	0x11
 829 0631 D8020000 		.long	0x2d8
 830 0635 3F060000 		.long	0x63f
 831 0639 0F       		.uleb128 0xf
 832 063a D8020000 		.long	0x2d8
 833 063e 00       		.byte	0
 834 063f 0E       		.uleb128 0xe
 835 0640 70657272 		.ascii "perror\0"
 835      6F7200
 836 0647 01       		.byte	0x1
 837 0648 9602     		.word	0x296
 838 064a 10       		.byte	0x10
 839 064b 55060000 		.long	0x655
 840 064f 0F       		.uleb128 0xf
 841 0650 D9040000 		.long	0x4d9
 842 0654 00       		.byte	0
 843 0655 15       		.uleb128 0x15
 844 0656 7072696E 		.ascii "printf\0"
 844      746600
 845 065d 01       		.byte	0x1
 846 065e 5901     		.word	0x159
 847 0660 05       		.byte	0x5
 848 0661 5F5A3670 		.ascii "_Z6printfPKcz\0"
 848      72696E74 
 848      66504B63 
 848      7A00
 849 066f C5020000 		.long	0x2c5
 850 0673 00000000 		.quad	.LFB8
 850      00000000 
 851 067b 54000000 		.quad	.LFE8-.LFB8
 851      00000000 
 852 0683 01       		.uleb128 0x1
 853 0684 9C       		.byte	0x9c
 854 0685 C9060000 		.long	0x6c9
 855 0689 12       		.uleb128 0x12
 856 068a 16       		.uleb128 0x16
 857 068b 0D000000 		.secrel32	.LASF2
 858 068f 01       		.byte	0x1
 859 0690 5901     		.word	0x159
 860 0692 19       		.byte	0x19
 861 0693 D9040000 		.long	0x4d9
 862 0697 02       		.uleb128 0x2
 863 0698 91       		.byte	0x91
 864 0699 00       		.sleb128 0
 865 069a 12       		.uleb128 0x12
 866 069b 17       		.uleb128 0x17
 867 069c 16000000 		.secrel32	.LASF0
 868 06a0 01       		.byte	0x1
 869 06a1 5B01     		.word	0x15b
 870 06a3 07       		.byte	0x7
 871 06a4 C5020000 		.long	0x2c5
 872 06a8 02       		.uleb128 0x2
 873 06a9 91       		.byte	0x91
 874 06aa 5C       		.sleb128 -36
 875 06ab 17       		.uleb128 0x17
 876 06ac 00000000 		.secrel32	.LASF1
 877 06b0 01       		.byte	0x1
 878 06b1 5C01     		.word	0x15c
 879 06b3 15       		.byte	0x15
 880 06b4 50020000 		.long	0x250
 881 06b8 02       		.uleb128 0x2
 882 06b9 91       		.byte	0x91
 883 06ba 50       		.sleb128 -48
 884 06bb 18       		.uleb128 0x18
 885 06bc 38000000 		.quad	.LVL1
 885      00000000 
 886 06c4 9C0A0000 		.long	0xa9c
 887 06c8 00       		.byte	0
 888 06c9 10       		.uleb128 0x10
 889 06ca 72656D6F 		.ascii "remove\0"
 889      766500
 890 06d1 01       		.byte	0x1
 891 06d2 A402     		.word	0x2a4
 892 06d4 0F       		.byte	0xf
 893 06d5 C5020000 		.long	0x2c5
 894 06d9 E3060000 		.long	0x6e3
 895 06dd 0F       		.uleb128 0xf
 896 06de D9040000 		.long	0x4d9
 897 06e2 00       		.byte	0
 898 06e3 10       		.uleb128 0x10
 899 06e4 72656E61 		.ascii "rename\0"
 899      6D6500
 900 06eb 01       		.byte	0x1
 901 06ec A502     		.word	0x2a5
 902 06ee 0F       		.byte	0xf
 903 06ef C5020000 		.long	0x2c5
 904 06f3 02070000 		.long	0x702
 905 06f7 0F       		.uleb128 0xf
 906 06f8 D9040000 		.long	0x4d9
 907 06fc 0F       		.uleb128 0xf
 908 06fd D9040000 		.long	0x4d9
 909 0701 00       		.byte	0
 910 0702 0E       		.uleb128 0xe
 911 0703 72657769 		.ascii "rewind\0"
 911      6E6400
 912 070a 01       		.byte	0x1
 913 070b AB02     		.word	0x2ab
 914 070d 10       		.byte	0x10
 915 070e 18070000 		.long	0x718
 916 0712 0F       		.uleb128 0xf
 917 0713 ED030000 		.long	0x3ed
 918 0717 00       		.byte	0
 919 0718 15       		.uleb128 0x15
 920 0719 7363616E 		.ascii "scanf\0"
 920      6600
 921 071f 01       		.byte	0x1
 922 0720 1601     		.word	0x116
 923 0722 05       		.byte	0x5
 924 0723 5F5A3573 		.ascii "_Z5scanfPKcz\0"
 924      63616E66 
 924      504B637A 
 924      00
 925 0730 C5020000 		.long	0x2c5
 926 0734 00000000 		.quad	.LFB2
 926      00000000 
 927 073c 54000000 		.quad	.LFE2-.LFB2
 927      00000000 
 928 0744 01       		.uleb128 0x1
 929 0745 9C       		.byte	0x9c
 930 0746 8A070000 		.long	0x78a
 931 074a 12       		.uleb128 0x12
 932 074b 16       		.uleb128 0x16
 933 074c 0D000000 		.secrel32	.LASF2
 934 0750 01       		.byte	0x1
 935 0751 1601     		.word	0x116
 936 0753 17       		.byte	0x17
 937 0754 D9040000 		.long	0x4d9
 938 0758 02       		.uleb128 0x2
 939 0759 91       		.byte	0x91
 940 075a 00       		.sleb128 0
 941 075b 12       		.uleb128 0x12
 942 075c 17       		.uleb128 0x17
 943 075d 16000000 		.secrel32	.LASF0
 944 0761 01       		.byte	0x1
 945 0762 1801     		.word	0x118
 946 0764 07       		.byte	0x7
 947 0765 C5020000 		.long	0x2c5
 948 0769 02       		.uleb128 0x2
 949 076a 91       		.byte	0x91
 950 076b 5C       		.sleb128 -36
 951 076c 17       		.uleb128 0x17
 952 076d 00000000 		.secrel32	.LASF1
 953 0771 01       		.byte	0x1
 954 0772 1901     		.word	0x119
 955 0774 15       		.byte	0x15
 956 0775 50020000 		.long	0x250
 957 0779 02       		.uleb128 0x2
 958 077a 91       		.byte	0x91
 959 077b 50       		.sleb128 -48
 960 077c 18       		.uleb128 0x18
 961 077d 38000000 		.quad	.LVL0
 961      00000000 
 962 0785 9C0A0000 		.long	0xa9c
 963 0789 00       		.byte	0
 964 078a 0E       		.uleb128 0xe
 965 078b 73657462 		.ascii "setbuf\0"
 965      756600
 966 0792 01       		.byte	0x1
 967 0793 AD02     		.word	0x2ad
 968 0795 10       		.byte	0x10
 969 0796 A5070000 		.long	0x7a5
 970 079a 0F       		.uleb128 0xf
 971 079b ED030000 		.long	0x3ed
 972 079f 0F       		.uleb128 0xf
 973 07a0 D8020000 		.long	0x2d8
 974 07a4 00       		.byte	0
 975 07a5 10       		.uleb128 0x10
 976 07a6 73657476 		.ascii "setvbuf\0"
 976      62756600 
 977 07ae 01       		.byte	0x1
 978 07af B102     		.word	0x2b1
 979 07b1 0F       		.byte	0xf
 980 07b2 C5020000 		.long	0x2c5
 981 07b6 CF070000 		.long	0x7cf
 982 07ba 0F       		.uleb128 0xf
 983 07bb ED030000 		.long	0x3ed
 984 07bf 0F       		.uleb128 0xf
 985 07c0 D8020000 		.long	0x2d8
 986 07c4 0F       		.uleb128 0xf
 987 07c5 C5020000 		.long	0x2c5
 988 07c9 0F       		.uleb128 0xf
 989 07ca 75020000 		.long	0x275
 990 07ce 00       		.byte	0
 991 07cf 11       		.uleb128 0x11
 992 07d0 73707269 		.ascii "sprintf\0"
 992      6E746600 
 993 07d8 01       		.byte	0x1
 994 07d9 6401     		.word	0x164
 995 07db 05       		.byte	0x5
 996 07dc 5F5A3773 		.ascii "_Z7sprintfPcPKcz\0"
 996      7072696E 
 996      74665063 
 996      504B637A 
 996      00
 997 07ed C5020000 		.long	0x2c5
 998 07f1 01080000 		.long	0x801
 999 07f5 0F       		.uleb128 0xf
 1000 07f6 D8020000 		.long	0x2d8
 1001 07fa 0F       		.uleb128 0xf
 1002 07fb D9040000 		.long	0x4d9
 1003 07ff 12       		.uleb128 0x12
 1004 0800 00       		.byte	0
 1005 0801 11       		.uleb128 0x11
 1006 0802 73736361 		.ascii "sscanf\0"
 1006      6E6600
 1007 0809 01       		.byte	0x1
 1008 080a 0B01     		.word	0x10b
 1009 080c 05       		.byte	0x5
 1010 080d 5F5A3673 		.ascii "_Z6sscanfPKcS0_z\0"
 1010      7363616E 
 1010      66504B63 
 1010      53305F7A 
 1010      00
 1011 081e C5020000 		.long	0x2c5
 1012 0822 32080000 		.long	0x832
 1013 0826 0F       		.uleb128 0xf
 1014 0827 D9040000 		.long	0x4d9
 1015 082b 0F       		.uleb128 0xf
 1016 082c D9040000 		.long	0x4d9
 1017 0830 12       		.uleb128 0x12
 1018 0831 00       		.byte	0
 1019 0832 14       		.uleb128 0x14
 1020 0833 746D7066 		.ascii "tmpfile\0"
 1020      696C6500 
 1021 083b 01       		.byte	0x1
 1022 083c CB02     		.word	0x2cb
 1023 083e 11       		.byte	0x11
 1024 083f ED030000 		.long	0x3ed
 1025 0843 10       		.uleb128 0x10
 1026 0844 746D706E 		.ascii "tmpnam\0"
 1026      616D00
 1027 084b 01       		.byte	0x1
 1028 084c CC02     		.word	0x2cc
 1029 084e 11       		.byte	0x11
 1030 084f D8020000 		.long	0x2d8
 1031 0853 5D080000 		.long	0x85d
 1032 0857 0F       		.uleb128 0xf
 1033 0858 D8020000 		.long	0x2d8
 1034 085c 00       		.byte	0
 1035 085d 10       		.uleb128 0x10
 1036 085e 756E6765 		.ascii "ungetc\0"
 1036      746300
 1037 0865 01       		.byte	0x1
 1038 0866 CD02     		.word	0x2cd
 1039 0868 0F       		.byte	0xf
 1040 0869 C5020000 		.long	0x2c5
 1041 086d 7C080000 		.long	0x87c
 1042 0871 0F       		.uleb128 0xf
 1043 0872 C5020000 		.long	0x2c5
 1044 0876 0F       		.uleb128 0xf
 1045 0877 ED030000 		.long	0x3ed
 1046 087b 00       		.byte	0
 1047 087c 11       		.uleb128 0x11
 1048 087d 76667072 		.ascii "vfprintf\0"
 1048      696E7466 
 1048      00
 1049 0886 01       		.byte	0x1
 1050 0887 6F01     		.word	0x16f
 1051 0889 05       		.byte	0x5
 1052 088a 5F5A3876 		.ascii "_Z8vfprintfP6_iobufPKcPc\0"
 1052      66707269 
 1052      6E746650 
 1052      365F696F 
 1052      62756650 
 1053 08a3 C5020000 		.long	0x2c5
 1054 08a7 BB080000 		.long	0x8bb
 1055 08ab 0F       		.uleb128 0xf
 1056 08ac ED030000 		.long	0x3ed
 1057 08b0 0F       		.uleb128 0xf
 1058 08b1 D9040000 		.long	0x4d9
 1059 08b5 0F       		.uleb128 0xf
 1060 08b6 50020000 		.long	0x250
 1061 08ba 00       		.byte	0
 1062 08bb 11       		.uleb128 0x11
 1063 08bc 76707269 		.ascii "vprintf\0"
 1063      6E746600 
 1064 08c4 01       		.byte	0x1
 1065 08c5 7601     		.word	0x176
 1066 08c7 05       		.byte	0x5
 1067 08c8 5F5A3776 		.ascii "_Z7vprintfPKcPc\0"
 1067      7072696E 
 1067      7466504B 
 1067      63506300 
 1068 08d8 C5020000 		.long	0x2c5
 1069 08dc EB080000 		.long	0x8eb
 1070 08e0 0F       		.uleb128 0xf
 1071 08e1 D9040000 		.long	0x4d9
 1072 08e5 0F       		.uleb128 0xf
 1073 08e6 50020000 		.long	0x250
 1074 08ea 00       		.byte	0
 1075 08eb 11       		.uleb128 0x11
 1076 08ec 76737072 		.ascii "vsprintf\0"
 1076      696E7466 
 1076      00
 1077 08f5 01       		.byte	0x1
 1078 08f6 7D01     		.word	0x17d
 1079 08f8 05       		.byte	0x5
 1080 08f9 5F5A3876 		.ascii "_Z8vsprintfPcPKcS_\0"
 1080      73707269 
 1080      6E746650 
 1080      63504B63 
 1080      535F00
 1081 090c C5020000 		.long	0x2c5
 1082 0910 24090000 		.long	0x924
 1083 0914 0F       		.uleb128 0xf
 1084 0915 D8020000 		.long	0x2d8
 1085 0919 0F       		.uleb128 0xf
 1086 091a D9040000 		.long	0x4d9
 1087 091e 0F       		.uleb128 0xf
 1088 091f 50020000 		.long	0x250
 1089 0923 00       		.byte	0
 1090 0924 11       		.uleb128 0x11
 1091 0925 736E7072 		.ascii "snprintf\0"
 1091      696E7466 
 1091      00
 1092 092e 01       		.byte	0x1
 1093 092f 8401     		.word	0x184
 1094 0931 05       		.byte	0x5
 1095 0932 5F5A3873 		.ascii "_Z8snprintfPcyPKcz\0"
 1095      6E707269 
 1095      6E746650 
 1095      6379504B 
 1095      637A00
 1096 0945 C5020000 		.long	0x2c5
 1097 0949 5E090000 		.long	0x95e
 1098 094d 0F       		.uleb128 0xf
 1099 094e D8020000 		.long	0x2d8
 1100 0952 0F       		.uleb128 0xf
 1101 0953 75020000 		.long	0x275
 1102 0957 0F       		.uleb128 0xf
 1103 0958 D9040000 		.long	0x4d9
 1104 095c 12       		.uleb128 0x12
 1105 095d 00       		.byte	0
 1106 095e 11       		.uleb128 0x11
 1107 095f 76667363 		.ascii "vfscanf\0"
 1107      616E6600 
 1108 0967 01       		.byte	0x1
 1109 0968 4001     		.word	0x140
 1110 096a 05       		.byte	0x5
 1111 096b 5F5A3776 		.ascii "_Z7vfscanfP6_iobufPKcPc\0"
 1111      66736361 
 1111      6E665036 
 1111      5F696F62 
 1111      7566504B 
 1112 0983 C5020000 		.long	0x2c5
 1113 0987 9B090000 		.long	0x99b
 1114 098b 0F       		.uleb128 0xf
 1115 098c ED030000 		.long	0x3ed
 1116 0990 0F       		.uleb128 0xf
 1117 0991 D9040000 		.long	0x4d9
 1118 0995 0F       		.uleb128 0xf
 1119 0996 50020000 		.long	0x250
 1120 099a 00       		.byte	0
 1121 099b 11       		.uleb128 0x11
 1122 099c 76736361 		.ascii "vscanf\0"
 1122      6E6600
 1123 09a3 01       		.byte	0x1
 1124 09a4 3901     		.word	0x139
 1125 09a6 05       		.byte	0x5
 1126 09a7 5F5A3676 		.ascii "_Z6vscanfPKcPc\0"
 1126      7363616E 
 1126      66504B63 
 1126      506300
 1127 09b6 C5020000 		.long	0x2c5
 1128 09ba C9090000 		.long	0x9c9
 1129 09be 0F       		.uleb128 0xf
 1130 09bf D9040000 		.long	0x4d9
 1131 09c3 0F       		.uleb128 0xf
 1132 09c4 50020000 		.long	0x250
 1133 09c8 00       		.byte	0
 1134 09c9 11       		.uleb128 0x11
 1135 09ca 76736E70 		.ascii "vsnprintf\0"
 1135      72696E74 
 1135      6600
 1136 09d4 01       		.byte	0x1
 1137 09d5 8F01     		.word	0x18f
 1138 09d7 05       		.byte	0x5
 1139 09d8 5F5A3976 		.ascii "_Z9vsnprintfPcyPKcS_\0"
 1139      736E7072 
 1139      696E7466 
 1139      50637950 
 1139      4B63535F 
 1140 09ed C5020000 		.long	0x2c5
 1141 09f1 0A0A0000 		.long	0xa0a
 1142 09f5 0F       		.uleb128 0xf
 1143 09f6 D8020000 		.long	0x2d8
 1144 09fa 0F       		.uleb128 0xf
 1145 09fb 75020000 		.long	0x275
 1146 09ff 0F       		.uleb128 0xf
 1147 0a00 D9040000 		.long	0x4d9
 1148 0a04 0F       		.uleb128 0xf
 1149 0a05 50020000 		.long	0x250
 1150 0a09 00       		.byte	0
 1151 0a0a 11       		.uleb128 0x11
 1152 0a0b 76737363 		.ascii "vsscanf\0"
 1152      616E6600 
 1153 0a13 01       		.byte	0x1
 1154 0a14 3201     		.word	0x132
 1155 0a16 05       		.byte	0x5
 1156 0a17 5F5A3776 		.ascii "_Z7vsscanfPKcS0_Pc\0"
 1156      73736361 
 1156      6E66504B 
 1156      6353305F 
 1156      506300
 1157 0a2a C5020000 		.long	0x2c5
 1158 0a2e 420A0000 		.long	0xa42
 1159 0a32 0F       		.uleb128 0xf
 1160 0a33 D9040000 		.long	0x4d9
 1161 0a37 0F       		.uleb128 0xf
 1162 0a38 D9040000 		.long	0x4d9
 1163 0a3c 0F       		.uleb128 0xf
 1164 0a3d 50020000 		.long	0x250
 1165 0a41 00       		.byte	0
 1166 0a42 19       		.uleb128 0x19
 1167 0a43 02       		.byte	0x2
 1168 0a44 02       		.byte	0x2
 1169 0a45 11       		.byte	0x11
 1170 0a46 8C000000 		.long	0x8c
 1171 0a4a 1A       		.uleb128 0x1a
 1172 0a4b 5000     		.ascii "P\0"
 1173 0a4d 02       		.byte	0x2
 1174 0a4e 03       		.byte	0x3
 1175 0a4f 14       		.byte	0x14
 1176 0a50 F9020000 		.long	0x2f9
 1177 0a54 09       		.uleb128 0x9
 1178 0a55 03       		.byte	0x3
 1179 0a56 00000000 		.quad	_ZL1P
 1179      00000000 
 1180 0a5e 1B       		.uleb128 0x1b
 1181 0a5f 6D61696E 		.ascii "main\0"
 1181      00
 1182 0a64 02       		.byte	0x2
 1183 0a65 04       		.byte	0x4
 1184 0a66 05       		.byte	0x5
 1185 0a67 C5020000 		.long	0x2c5
 1186 0a6b 00000000 		.quad	.LFB44
 1186      00000000 
 1187 0a73 5F000000 		.quad	.LFE44-.LFB44
 1187      00000000 
 1188 0a7b 01       		.uleb128 0x1
 1189 0a7c 9C       		.byte	0x9c
 1190 0a7d 9C0A0000 		.long	0xa9c
 1191 0a81 1A       		.uleb128 0x1a
 1192 0a82 6100     		.ascii "a\0"
 1193 0a84 02       		.byte	0x2
 1194 0a85 05       		.byte	0x5
 1195 0a86 0E       		.byte	0xe
 1196 0a87 E9020000 		.long	0x2e9
 1197 0a8b 02       		.uleb128 0x2
 1198 0a8c 91       		.byte	0x91
 1199 0a8d 68       		.sleb128 -24
 1200 0a8e 1A       		.uleb128 0x1a
 1201 0a8f 6200     		.ascii "b\0"
 1202 0a91 02       		.byte	0x2
 1203 0a92 07       		.byte	0x7
 1204 0a93 12       		.byte	0x12
 1205 0a94 E9020000 		.long	0x2e9
 1206 0a98 02       		.uleb128 0x2
 1207 0a99 91       		.byte	0x91
 1208 0a9a 6C       		.sleb128 -20
 1209 0a9b 00       		.byte	0
 1210 0a9c 1C       		.uleb128 0x1c
 1211 0a9d 1F000000 		.secrel32	.LASF3
 1212 0aa1 1F000000 		.secrel32	.LASF3
 1213 0aa5 01       		.byte	0x1
 1214 0aa6 52       		.byte	0x52
 1215 0aa7 17       		.byte	0x17
 1216 0aa8 00       		.byte	0
 1217              		.section	.debug_abbrev,"dr"
 1218              	.Ldebug_abbrev0:
 1219 0000 01       		.uleb128 0x1
 1220 0001 11       		.uleb128 0x11
 1221 0002 01       		.byte	0x1
 1222 0003 25       		.uleb128 0x25
 1223 0004 08       		.uleb128 0x8
 1224 0005 13       		.uleb128 0x13
 1225 0006 0B       		.uleb128 0xb
 1226 0007 03       		.uleb128 0x3
 1227 0008 08       		.uleb128 0x8
 1228 0009 1B       		.uleb128 0x1b
 1229 000a 08       		.uleb128 0x8
 1230 000b 55       		.uleb128 0x55
 1231 000c 17       		.uleb128 0x17
 1232 000d 11       		.uleb128 0x11
 1233 000e 01       		.uleb128 0x1
 1234 000f 10       		.uleb128 0x10
 1235 0010 17       		.uleb128 0x17
 1236 0011 00       		.byte	0
 1237 0012 00       		.byte	0
 1238 0013 02       		.uleb128 0x2
 1239 0014 39       		.uleb128 0x39
 1240 0015 01       		.byte	0x1
 1241 0016 03       		.uleb128 0x3
 1242 0017 08       		.uleb128 0x8
 1243 0018 3A       		.uleb128 0x3a
 1244 0019 0B       		.uleb128 0xb
 1245 001a 3B       		.uleb128 0x3b
 1246 001b 0B       		.uleb128 0xb
 1247 001c 01       		.uleb128 0x1
 1248 001d 13       		.uleb128 0x13
 1249 001e 00       		.byte	0
 1250 001f 00       		.byte	0
 1251 0020 03       		.uleb128 0x3
 1252 0021 39       		.uleb128 0x39
 1253 0022 00       		.byte	0
 1254 0023 03       		.uleb128 0x3
 1255 0024 08       		.uleb128 0x8
 1256 0025 3A       		.uleb128 0x3a
 1257 0026 0B       		.uleb128 0xb
 1258 0027 3B       		.uleb128 0x3b
 1259 0028 05       		.uleb128 0x5
 1260 0029 39       		.uleb128 0x39
 1261 002a 0B       		.uleb128 0xb
 1262 002b 8901     		.uleb128 0x89
 1263 002d 19       		.uleb128 0x19
 1264 002e 00       		.byte	0
 1265 002f 00       		.byte	0
 1266 0030 04       		.uleb128 0x4
 1267 0031 3A       		.uleb128 0x3a
 1268 0032 00       		.byte	0
 1269 0033 3A       		.uleb128 0x3a
 1270 0034 0B       		.uleb128 0xb
 1271 0035 3B       		.uleb128 0x3b
 1272 0036 05       		.uleb128 0x5
 1273 0037 39       		.uleb128 0x39
 1274 0038 0B       		.uleb128 0xb
 1275 0039 18       		.uleb128 0x18
 1276 003a 13       		.uleb128 0x13
 1277 003b 00       		.byte	0
 1278 003c 00       		.byte	0
 1279 003d 05       		.uleb128 0x5
 1280 003e 08       		.uleb128 0x8
 1281 003f 00       		.byte	0
 1282 0040 3A       		.uleb128 0x3a
 1283 0041 0B       		.uleb128 0xb
 1284 0042 3B       		.uleb128 0x3b
 1285 0043 0B       		.uleb128 0xb
 1286 0044 39       		.uleb128 0x39
 1287 0045 0B       		.uleb128 0xb
 1288 0046 18       		.uleb128 0x18
 1289 0047 13       		.uleb128 0x13
 1290 0048 00       		.byte	0
 1291 0049 00       		.byte	0
 1292 004a 06       		.uleb128 0x6
 1293 004b 39       		.uleb128 0x39
 1294 004c 01       		.byte	0x1
 1295 004d 03       		.uleb128 0x3
 1296 004e 08       		.uleb128 0x8
 1297 004f 3A       		.uleb128 0x3a
 1298 0050 0B       		.uleb128 0xb
 1299 0051 3B       		.uleb128 0x3b
 1300 0052 05       		.uleb128 0x5
 1301 0053 39       		.uleb128 0x39
 1302 0054 0B       		.uleb128 0xb
 1303 0055 01       		.uleb128 0x1
 1304 0056 13       		.uleb128 0x13
 1305 0057 00       		.byte	0
 1306 0058 00       		.byte	0
 1307 0059 07       		.uleb128 0x7
 1308 005a 0F       		.uleb128 0xf
 1309 005b 00       		.byte	0
 1310 005c 0B       		.uleb128 0xb
 1311 005d 0B       		.uleb128 0xb
 1312 005e 03       		.uleb128 0x3
 1313 005f 08       		.uleb128 0x8
 1314 0060 49       		.uleb128 0x49
 1315 0061 13       		.uleb128 0x13
 1316 0062 00       		.byte	0
 1317 0063 00       		.byte	0
 1318 0064 08       		.uleb128 0x8
 1319 0065 24       		.uleb128 0x24
 1320 0066 00       		.byte	0
 1321 0067 0B       		.uleb128 0xb
 1322 0068 0B       		.uleb128 0xb
 1323 0069 3E       		.uleb128 0x3e
 1324 006a 0B       		.uleb128 0xb
 1325 006b 03       		.uleb128 0x3
 1326 006c 08       		.uleb128 0x8
 1327 006d 00       		.byte	0
 1328 006e 00       		.byte	0
 1329 006f 09       		.uleb128 0x9
 1330 0070 26       		.uleb128 0x26
 1331 0071 00       		.byte	0
 1332 0072 49       		.uleb128 0x49
 1333 0073 13       		.uleb128 0x13
 1334 0074 00       		.byte	0
 1335 0075 00       		.byte	0
 1336 0076 0A       		.uleb128 0xa
 1337 0077 16       		.uleb128 0x16
 1338 0078 00       		.byte	0
 1339 0079 03       		.uleb128 0x3
 1340 007a 08       		.uleb128 0x8
 1341 007b 3A       		.uleb128 0x3a
 1342 007c 0B       		.uleb128 0xb
 1343 007d 3B       		.uleb128 0x3b
 1344 007e 0B       		.uleb128 0xb
 1345 007f 39       		.uleb128 0x39
 1346 0080 0B       		.uleb128 0xb
 1347 0081 49       		.uleb128 0x49
 1348 0082 13       		.uleb128 0x13
 1349 0083 00       		.byte	0
 1350 0084 00       		.byte	0
 1351 0085 0B       		.uleb128 0xb
 1352 0086 0F       		.uleb128 0xf
 1353 0087 00       		.byte	0
 1354 0088 0B       		.uleb128 0xb
 1355 0089 0B       		.uleb128 0xb
 1356 008a 49       		.uleb128 0x49
 1357 008b 13       		.uleb128 0x13
 1358 008c 00       		.byte	0
 1359 008d 00       		.byte	0
 1360 008e 0C       		.uleb128 0xc
 1361 008f 13       		.uleb128 0x13
 1362 0090 01       		.byte	0x1
 1363 0091 03       		.uleb128 0x3
 1364 0092 08       		.uleb128 0x8
 1365 0093 0B       		.uleb128 0xb
 1366 0094 0B       		.uleb128 0xb
 1367 0095 3A       		.uleb128 0x3a
 1368 0096 0B       		.uleb128 0xb
 1369 0097 3B       		.uleb128 0x3b
 1370 0098 0B       		.uleb128 0xb
 1371 0099 39       		.uleb128 0x39
 1372 009a 0B       		.uleb128 0xb
 1373 009b 01       		.uleb128 0x1
 1374 009c 13       		.uleb128 0x13
 1375 009d 00       		.byte	0
 1376 009e 00       		.byte	0
 1377 009f 0D       		.uleb128 0xd
 1378 00a0 0D       		.uleb128 0xd
 1379 00a1 00       		.byte	0
 1380 00a2 03       		.uleb128 0x3
 1381 00a3 08       		.uleb128 0x8
 1382 00a4 3A       		.uleb128 0x3a
 1383 00a5 0B       		.uleb128 0xb
 1384 00a6 3B       		.uleb128 0x3b
 1385 00a7 0B       		.uleb128 0xb
 1386 00a8 39       		.uleb128 0x39
 1387 00a9 0B       		.uleb128 0xb
 1388 00aa 49       		.uleb128 0x49
 1389 00ab 13       		.uleb128 0x13
 1390 00ac 38       		.uleb128 0x38
 1391 00ad 0B       		.uleb128 0xb
 1392 00ae 00       		.byte	0
 1393 00af 00       		.byte	0
 1394 00b0 0E       		.uleb128 0xe
 1395 00b1 2E       		.uleb128 0x2e
 1396 00b2 01       		.byte	0x1
 1397 00b3 3F       		.uleb128 0x3f
 1398 00b4 19       		.uleb128 0x19
 1399 00b5 03       		.uleb128 0x3
 1400 00b6 08       		.uleb128 0x8
 1401 00b7 3A       		.uleb128 0x3a
 1402 00b8 0B       		.uleb128 0xb
 1403 00b9 3B       		.uleb128 0x3b
 1404 00ba 05       		.uleb128 0x5
 1405 00bb 39       		.uleb128 0x39
 1406 00bc 0B       		.uleb128 0xb
 1407 00bd 3C       		.uleb128 0x3c
 1408 00be 19       		.uleb128 0x19
 1409 00bf 01       		.uleb128 0x1
 1410 00c0 13       		.uleb128 0x13
 1411 00c1 00       		.byte	0
 1412 00c2 00       		.byte	0
 1413 00c3 0F       		.uleb128 0xf
 1414 00c4 05       		.uleb128 0x5
 1415 00c5 00       		.byte	0
 1416 00c6 49       		.uleb128 0x49
 1417 00c7 13       		.uleb128 0x13
 1418 00c8 00       		.byte	0
 1419 00c9 00       		.byte	0
 1420 00ca 10       		.uleb128 0x10
 1421 00cb 2E       		.uleb128 0x2e
 1422 00cc 01       		.byte	0x1
 1423 00cd 3F       		.uleb128 0x3f
 1424 00ce 19       		.uleb128 0x19
 1425 00cf 03       		.uleb128 0x3
 1426 00d0 08       		.uleb128 0x8
 1427 00d1 3A       		.uleb128 0x3a
 1428 00d2 0B       		.uleb128 0xb
 1429 00d3 3B       		.uleb128 0x3b
 1430 00d4 05       		.uleb128 0x5
 1431 00d5 39       		.uleb128 0x39
 1432 00d6 0B       		.uleb128 0xb
 1433 00d7 49       		.uleb128 0x49
 1434 00d8 13       		.uleb128 0x13
 1435 00d9 3C       		.uleb128 0x3c
 1436 00da 19       		.uleb128 0x19
 1437 00db 01       		.uleb128 0x1
 1438 00dc 13       		.uleb128 0x13
 1439 00dd 00       		.byte	0
 1440 00de 00       		.byte	0
 1441 00df 11       		.uleb128 0x11
 1442 00e0 2E       		.uleb128 0x2e
 1443 00e1 01       		.byte	0x1
 1444 00e2 3F       		.uleb128 0x3f
 1445 00e3 19       		.uleb128 0x19
 1446 00e4 03       		.uleb128 0x3
 1447 00e5 08       		.uleb128 0x8
 1448 00e6 3A       		.uleb128 0x3a
 1449 00e7 0B       		.uleb128 0xb
 1450 00e8 3B       		.uleb128 0x3b
 1451 00e9 05       		.uleb128 0x5
 1452 00ea 39       		.uleb128 0x39
 1453 00eb 0B       		.uleb128 0xb
 1454 00ec 6E       		.uleb128 0x6e
 1455 00ed 08       		.uleb128 0x8
 1456 00ee 49       		.uleb128 0x49
 1457 00ef 13       		.uleb128 0x13
 1458 00f0 3C       		.uleb128 0x3c
 1459 00f1 19       		.uleb128 0x19
 1460 00f2 01       		.uleb128 0x1
 1461 00f3 13       		.uleb128 0x13
 1462 00f4 00       		.byte	0
 1463 00f5 00       		.byte	0
 1464 00f6 12       		.uleb128 0x12
 1465 00f7 18       		.uleb128 0x18
 1466 00f8 00       		.byte	0
 1467 00f9 00       		.byte	0
 1468 00fa 00       		.byte	0
 1469 00fb 13       		.uleb128 0x13
 1470 00fc 0F       		.uleb128 0xf
 1471 00fd 00       		.byte	0
 1472 00fe 0B       		.uleb128 0xb
 1473 00ff 0B       		.uleb128 0xb
 1474 0100 00       		.byte	0
 1475 0101 00       		.byte	0
 1476 0102 14       		.uleb128 0x14
 1477 0103 2E       		.uleb128 0x2e
 1478 0104 00       		.byte	0
 1479 0105 3F       		.uleb128 0x3f
 1480 0106 19       		.uleb128 0x19
 1481 0107 03       		.uleb128 0x3
 1482 0108 08       		.uleb128 0x8
 1483 0109 3A       		.uleb128 0x3a
 1484 010a 0B       		.uleb128 0xb
 1485 010b 3B       		.uleb128 0x3b
 1486 010c 05       		.uleb128 0x5
 1487 010d 39       		.uleb128 0x39
 1488 010e 0B       		.uleb128 0xb
 1489 010f 49       		.uleb128 0x49
 1490 0110 13       		.uleb128 0x13
 1491 0111 3C       		.uleb128 0x3c
 1492 0112 19       		.uleb128 0x19
 1493 0113 00       		.byte	0
 1494 0114 00       		.byte	0
 1495 0115 15       		.uleb128 0x15
 1496 0116 2E       		.uleb128 0x2e
 1497 0117 01       		.byte	0x1
 1498 0118 3F       		.uleb128 0x3f
 1499 0119 19       		.uleb128 0x19
 1500 011a 03       		.uleb128 0x3
 1501 011b 08       		.uleb128 0x8
 1502 011c 3A       		.uleb128 0x3a
 1503 011d 0B       		.uleb128 0xb
 1504 011e 3B       		.uleb128 0x3b
 1505 011f 05       		.uleb128 0x5
 1506 0120 39       		.uleb128 0x39
 1507 0121 0B       		.uleb128 0xb
 1508 0122 6E       		.uleb128 0x6e
 1509 0123 08       		.uleb128 0x8
 1510 0124 49       		.uleb128 0x49
 1511 0125 13       		.uleb128 0x13
 1512 0126 11       		.uleb128 0x11
 1513 0127 01       		.uleb128 0x1
 1514 0128 12       		.uleb128 0x12
 1515 0129 07       		.uleb128 0x7
 1516 012a 40       		.uleb128 0x40
 1517 012b 18       		.uleb128 0x18
 1518 012c 9642     		.uleb128 0x2116
 1519 012e 19       		.uleb128 0x19
 1520 012f 01       		.uleb128 0x1
 1521 0130 13       		.uleb128 0x13
 1522 0131 00       		.byte	0
 1523 0132 00       		.byte	0
 1524 0133 16       		.uleb128 0x16
 1525 0134 05       		.uleb128 0x5
 1526 0135 00       		.byte	0
 1527 0136 03       		.uleb128 0x3
 1528 0137 0E       		.uleb128 0xe
 1529 0138 3A       		.uleb128 0x3a
 1530 0139 0B       		.uleb128 0xb
 1531 013a 3B       		.uleb128 0x3b
 1532 013b 05       		.uleb128 0x5
 1533 013c 39       		.uleb128 0x39
 1534 013d 0B       		.uleb128 0xb
 1535 013e 49       		.uleb128 0x49
 1536 013f 13       		.uleb128 0x13
 1537 0140 02       		.uleb128 0x2
 1538 0141 18       		.uleb128 0x18
 1539 0142 00       		.byte	0
 1540 0143 00       		.byte	0
 1541 0144 17       		.uleb128 0x17
 1542 0145 34       		.uleb128 0x34
 1543 0146 00       		.byte	0
 1544 0147 03       		.uleb128 0x3
 1545 0148 0E       		.uleb128 0xe
 1546 0149 3A       		.uleb128 0x3a
 1547 014a 0B       		.uleb128 0xb
 1548 014b 3B       		.uleb128 0x3b
 1549 014c 05       		.uleb128 0x5
 1550 014d 39       		.uleb128 0x39
 1551 014e 0B       		.uleb128 0xb
 1552 014f 49       		.uleb128 0x49
 1553 0150 13       		.uleb128 0x13
 1554 0151 02       		.uleb128 0x2
 1555 0152 18       		.uleb128 0x18
 1556 0153 00       		.byte	0
 1557 0154 00       		.byte	0
 1558 0155 18       		.uleb128 0x18
 1559 0156 898201   		.uleb128 0x4109
 1560 0159 00       		.byte	0
 1561 015a 11       		.uleb128 0x11
 1562 015b 01       		.uleb128 0x1
 1563 015c 31       		.uleb128 0x31
 1564 015d 13       		.uleb128 0x13
 1565 015e 00       		.byte	0
 1566 015f 00       		.byte	0
 1567 0160 19       		.uleb128 0x19
 1568 0161 3A       		.uleb128 0x3a
 1569 0162 00       		.byte	0
 1570 0163 3A       		.uleb128 0x3a
 1571 0164 0B       		.uleb128 0xb
 1572 0165 3B       		.uleb128 0x3b
 1573 0166 0B       		.uleb128 0xb
 1574 0167 39       		.uleb128 0x39
 1575 0168 0B       		.uleb128 0xb
 1576 0169 18       		.uleb128 0x18
 1577 016a 13       		.uleb128 0x13
 1578 016b 00       		.byte	0
 1579 016c 00       		.byte	0
 1580 016d 1A       		.uleb128 0x1a
 1581 016e 34       		.uleb128 0x34
 1582 016f 00       		.byte	0
 1583 0170 03       		.uleb128 0x3
 1584 0171 08       		.uleb128 0x8
 1585 0172 3A       		.uleb128 0x3a
 1586 0173 0B       		.uleb128 0xb
 1587 0174 3B       		.uleb128 0x3b
 1588 0175 0B       		.uleb128 0xb
 1589 0176 39       		.uleb128 0x39
 1590 0177 0B       		.uleb128 0xb
 1591 0178 49       		.uleb128 0x49
 1592 0179 13       		.uleb128 0x13
 1593 017a 02       		.uleb128 0x2
 1594 017b 18       		.uleb128 0x18
 1595 017c 00       		.byte	0
 1596 017d 00       		.byte	0
 1597 017e 1B       		.uleb128 0x1b
 1598 017f 2E       		.uleb128 0x2e
 1599 0180 01       		.byte	0x1
 1600 0181 3F       		.uleb128 0x3f
 1601 0182 19       		.uleb128 0x19
 1602 0183 03       		.uleb128 0x3
 1603 0184 08       		.uleb128 0x8
 1604 0185 3A       		.uleb128 0x3a
 1605 0186 0B       		.uleb128 0xb
 1606 0187 3B       		.uleb128 0x3b
 1607 0188 0B       		.uleb128 0xb
 1608 0189 39       		.uleb128 0x39
 1609 018a 0B       		.uleb128 0xb
 1610 018b 49       		.uleb128 0x49
 1611 018c 13       		.uleb128 0x13
 1612 018d 11       		.uleb128 0x11
 1613 018e 01       		.uleb128 0x1
 1614 018f 12       		.uleb128 0x12
 1615 0190 07       		.uleb128 0x7
 1616 0191 40       		.uleb128 0x40
 1617 0192 18       		.uleb128 0x18
 1618 0193 9642     		.uleb128 0x2116
 1619 0195 19       		.uleb128 0x19
 1620 0196 01       		.uleb128 0x1
 1621 0197 13       		.uleb128 0x13
 1622 0198 00       		.byte	0
 1623 0199 00       		.byte	0
 1624 019a 1C       		.uleb128 0x1c
 1625 019b 2E       		.uleb128 0x2e
 1626 019c 00       		.byte	0
 1627 019d 3F       		.uleb128 0x3f
 1628 019e 19       		.uleb128 0x19
 1629 019f 3C       		.uleb128 0x3c
 1630 01a0 19       		.uleb128 0x19
 1631 01a1 6E       		.uleb128 0x6e
 1632 01a2 0E       		.uleb128 0xe
 1633 01a3 03       		.uleb128 0x3
 1634 01a4 0E       		.uleb128 0xe
 1635 01a5 3A       		.uleb128 0x3a
 1636 01a6 0B       		.uleb128 0xb
 1637 01a7 3B       		.uleb128 0x3b
 1638 01a8 0B       		.uleb128 0xb
 1639 01a9 39       		.uleb128 0x39
 1640 01aa 0B       		.uleb128 0xb
 1641 01ab 00       		.byte	0
 1642 01ac 00       		.byte	0
 1643 01ad 00       		.byte	0
 1644              		.section	.debug_aranges,"dr"
 1645 0000 4C000000 		.long	0x4c
 1646 0004 0200     		.word	0x2
 1647 0006 00000000 		.secrel32	.Ldebug_info0
 1648 000a 08       		.byte	0x8
 1649 000b 00       		.byte	0
 1650 000c 0000     		.word	0
 1651 000e 0000     		.word	0
 1652 0010 00000000 		.quad	.Ltext0
 1652      00000000 
 1653 0018 5F000000 		.quad	.Letext0-.Ltext0
 1653      00000000 
 1654 0020 00000000 		.quad	.LFB2
 1654      00000000 
 1655 0028 54000000 		.quad	.LFE2-.LFB2
 1655      00000000 
 1656 0030 00000000 		.quad	.LFB8
 1656      00000000 
 1657 0038 54000000 		.quad	.LFE8-.LFB8
 1657      00000000 
 1658 0040 00000000 		.quad	0
 1658      00000000 
 1659 0048 00000000 		.quad	0
 1659      00000000 
 1660              		.section	.debug_ranges,"dr"
 1661              	.Ldebug_ranges0:
 1662 0000 00000000 		.quad	.Ltext0
 1662      00000000 
 1663 0008 5F000000 		.quad	.Letext0
 1663      00000000 
 1664 0010 00000000 		.quad	.LFB2
 1664      00000000 
 1665 0018 54000000 		.quad	.LFE2
 1665      00000000 
 1666 0020 00000000 		.quad	.LFB8
 1666      00000000 
 1667 0028 54000000 		.quad	.LFE8
 1667      00000000 
 1668 0030 00000000 		.quad	0
 1668      00000000 
 1669 0038 00000000 		.quad	0
 1669      00000000 
 1670              		.section	.debug_line,"dr"
 1671              	.Ldebug_line0:
 1672 0000 B6010000 		.section	.debug_str,"dr"
 1672      02003E01 
 1672      00000101 
 1672      FB0E0D00 
 1672      01010101 
 1673              	.LASF1:
 1674 0000 5F5F6C6F 		.ascii "__local_argv\0"
 1674      63616C5F 
 1674      61726776 
 1674      00
 1675              	.LASF2:
 1676 000d 5F5F666F 		.ascii "__format\0"
 1676      726D6174 
 1676      00
 1677              	.LASF0:
 1678 0016 5F5F7265 		.ascii "__retval\0"
 1678      7476616C 
 1678      00
 1679              	.LASF3:
 1680 001f 5F5F6163 		.ascii "__acrt_iob_func\0"
 1680      72745F69 
 1680      6F625F66 
 1680      756E6300 
 1681              		.ident	"GCC: (x86_64-win32-seh-rev0, Built by MinGW-W64 project) 8.1.0"
