   1              		.file	"19_1_DP.cpp"
   2              		.text
   3              	.Ltext0:
   4              		.cfi_sections	.debug_frame
   5              		.section	.text$_Z5scanfPKcz,"x"
   6              		.linkonce discard
   7              		.globl	_Z5scanfPKcz
   9              		.seh_proc	_Z5scanfPKcz
  10              	_Z5scanfPKcz:
  11              	.LFB476:
  12              		.file 1 "C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/i
   1:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** /**
   2:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****  * This file has no copyright assigned and is placed in the Public Domain.
   3:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****  * This file is part of the mingw-w64 runtime package.
   4:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****  * No warranty is given; refer to the file DISCLAIMER.PD within this package.
   5:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****  */
   6:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #ifndef _INC_STDIO
   7:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define _INC_STDIO
   8:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
   9:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #include <crtdefs.h>
  10:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
  11:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #include <_mingw_print_push.h>
  12:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
  13:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #pragma pack(push,_CRT_PACKING)
  14:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
  15:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #ifdef __cplusplus
  16:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** extern "C" {
  17:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #endif
  18:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
  19:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define BUFSIZ 512
  20:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define _NFILE _NSTREAM_
  21:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define _NSTREAM_ 512
  22:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define _IOB_ENTRIES 20
  23:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define EOF (-1)
  24:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
  25:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #ifndef _FILE_DEFINED
  26:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   struct _iobuf {
  27:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****     char *_ptr;
  28:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****     int _cnt;
  29:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****     char *_base;
  30:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****     int _flag;
  31:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****     int _file;
  32:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****     int _charbuf;
  33:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****     int _bufsiz;
  34:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****     char *_tmpfname;
  35:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   };
  36:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   typedef struct _iobuf FILE;
  37:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define _FILE_DEFINED
  38:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #endif
  39:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
  40:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #ifdef _POSIX_
  41:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define _P_tmpdir "/"
  42:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define _wP_tmpdir L"/"
  43:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #else
  44:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define _P_tmpdir "\\"
  45:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define _wP_tmpdir L"\\"
  46:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #endif
  47:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
  48:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define L_tmpnam (sizeof(_P_tmpdir) + 12)
  49:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
  50:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #ifdef _POSIX_
  51:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define L_ctermid 9
  52:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define L_cuserid 32
  53:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #endif
  54:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
  55:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define SEEK_CUR 1
  56:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define SEEK_END 2
  57:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define SEEK_SET 0
  58:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
  59:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define	STDIN_FILENO	0
  60:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define	STDOUT_FILENO	1
  61:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define	STDERR_FILENO	2
  62:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
  63:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define FILENAME_MAX 260
  64:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define FOPEN_MAX 20
  65:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define _SYS_OPEN 20
  66:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define TMP_MAX 32767
  67:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
  68:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #ifndef NULL
  69:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #ifdef __cplusplus
  70:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #ifndef _WIN64
  71:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define NULL 0
  72:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #else
  73:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define NULL 0LL
  74:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #endif  /* W64 */
  75:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #else
  76:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define NULL ((void *)0)
  77:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #endif
  78:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #endif
  79:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
  80:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #include <_mingw_off_t.h>
  81:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
  82:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** _CRTIMP FILE *__cdecl __acrt_iob_func(unsigned index);
  83:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #ifndef _STDIO_DEFINED
  84:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #ifdef _WIN64
  85:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   _CRTIMP FILE *__cdecl __iob_func(void);
  86:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define _iob  __iob_func()
  87:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #else
  88:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #ifdef _MSVCRT_
  89:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** extern FILE _iob[];	/* A pointer to an array of FILE */
  90:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define __iob_func()	(_iob)
  91:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #else
  92:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** extern FILE (* __MINGW_IMP_SYMBOL(_iob))[];	/* A pointer to an array of FILE */
  93:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define __iob_func()	(* __MINGW_IMP_SYMBOL(_iob))
  94:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define _iob __iob_func()
  95:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #endif
  96:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #endif
  97:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #endif
  98:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
  99:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #ifndef _FPOS_T_DEFINED
 100:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define _FPOS_T_DEFINED
 101:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #undef _FPOSOFF
 102:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
 103:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #if (!defined(NO_OLDNAMES) || defined(__GNUC__))
 104:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   __MINGW_EXTENSION typedef __int64 fpos_t;
 105:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define _FPOSOFF(fp) ((long)(fp))
 106:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #else
 107:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   __MINGW_EXTENSION typedef long long fpos_t;
 108:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define _FPOSOFF(fp) ((long)(fp))
 109:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #endif
 110:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
 111:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #endif
 112:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
 113:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #ifndef _STDSTREAM_DEFINED
 114:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define _STDSTREAM_DEFINED
 115:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
 116:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define stdin (__acrt_iob_func(0))
 117:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define stdout (__acrt_iob_func(1))
 118:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define stderr (__acrt_iob_func(2))
 119:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #endif
 120:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
 121:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define _IOREAD 0x0001
 122:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define _IOWRT 0x0002
 123:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
 124:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define _IOFBF 0x0000
 125:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define _IOLBF 0x0040
 126:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define _IONBF 0x0004
 127:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
 128:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define _IOMYBUF 0x0008
 129:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define _IOEOF 0x0010
 130:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define _IOERR 0x0020
 131:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define _IOSTRG 0x0040
 132:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define _IORW 0x0080
 133:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #ifdef _POSIX_
 134:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define _IOAPPEND 0x0200
 135:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #endif
 136:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
 137:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define _TWO_DIGIT_EXPONENT 0x1
 138:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
 139:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #if !defined(_UCRTBASE_STDIO_DEFINED) && __MSVCRT_VERSION__ >= 0x1400
 140:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define _UCRTBASE_STDIO_DEFINED
 141:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
 142:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define UCRTBASE_PRINTF_LEGACY_VSPRINTF_NULL_TERMINATION (0x0001)
 143:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define UCRTBASE_PRINTF_STANDARD_SNPRINTF_BEHAVIOUR      (0x0002)
 144:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define UCRTBASE_PRINTF_LEGACY_WIDE_SPECIFIERS           (0x0004)
 145:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define UCRTBASE_PRINTF_LEGACY_MSVCRT_COMPATIBILITY      (0x0008)
 146:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define UCRTBASE_PRINTF_LEGACY_THREE_DIGIT_EXPONENTS     (0x0010)
 147:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
 148:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define UCRTBASE_SCANF_SECURECRT                         (0x0001)
 149:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define UCRTBASE_SCANF_LEGACY_WIDE_SPECIFIERS            (0x0002)
 150:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define UCRTBASE_SCANF_LEGACY_MSVCRT_COMPATIBILITY       (0x0004)
 151:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
 152:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** // Default wide printfs and scanfs to the standard mode
 153:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #ifndef UCRTBASE_PRINTF_DEFAULT_WIDE
 154:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define UCRTBASE_PRINTF_DEFAULT_WIDE 0
 155:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #endif
 156:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #ifndef UCRTBASE_SCANF_DEFAULT_WIDE
 157:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define UCRTBASE_SCANF_DEFAULT_WIDE 0
 158:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #endif
 159:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #endif
 160:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
 161:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #ifndef _STDIO_DEFINED
 162:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** extern
 163:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   __attribute__((__format__ (gnu_scanf, 2, 3))) __MINGW_ATTRIB_NONNULL(2)
 164:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   int __cdecl __mingw_sscanf(const char * __restrict__ _Src,const char * __restrict__ _Format,...);
 165:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** extern
 166:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   __attribute__((__format__ (gnu_scanf, 2, 0))) __MINGW_ATTRIB_NONNULL(2)
 167:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   int __cdecl __mingw_vsscanf (const char * __restrict__ _Str,const char * __restrict__ Format,va_l
 168:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** extern
 169:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   __attribute__((__format__ (gnu_scanf, 1, 2))) __MINGW_ATTRIB_NONNULL(1)
 170:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   int __cdecl __mingw_scanf(const char * __restrict__ _Format,...);
 171:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** extern
 172:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   __attribute__((__format__ (gnu_scanf, 1, 0))) __MINGW_ATTRIB_NONNULL(1)
 173:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   int __cdecl __mingw_vscanf(const char * __restrict__ Format, va_list argp);
 174:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** extern
 175:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   __attribute__((__format__ (gnu_scanf, 2, 3))) __MINGW_ATTRIB_NONNULL(2)
 176:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   int __cdecl __mingw_fscanf(FILE * __restrict__ _File,const char * __restrict__ _Format,...);
 177:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** extern
 178:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   __attribute__((__format__ (gnu_scanf, 2, 0))) __MINGW_ATTRIB_NONNULL(2)
 179:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   int __cdecl __mingw_vfscanf (FILE * __restrict__ fp, const char * __restrict__ Format,va_list arg
 180:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
 181:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** extern
 182:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   __attribute__((__format__ (gnu_printf, 3, 0))) __MINGW_ATTRIB_NONNULL(3)
 183:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   int __cdecl __mingw_vsnprintf(char * __restrict__ _DstBuf,size_t _MaxCount,const char * __restric
 184:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****                                va_list _ArgList);
 185:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** extern
 186:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   __attribute__((__format__ (gnu_printf, 3, 4))) __MINGW_ATTRIB_NONNULL(3)
 187:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   int __cdecl __mingw_snprintf(char * __restrict__ s, size_t n, const char * __restrict__  format, 
 188:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** extern
 189:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   __attribute__((__format__ (gnu_printf, 1, 2))) __MINGW_ATTRIB_NONNULL(1)
 190:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   int __cdecl __mingw_printf(const char * __restrict__ , ... ) __MINGW_NOTHROW;
 191:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** extern
 192:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   __attribute__((__format__ (gnu_printf, 1, 0))) __MINGW_ATTRIB_NONNULL(1)
 193:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   int __cdecl __mingw_vprintf (const char * __restrict__ , va_list) __MINGW_NOTHROW;
 194:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** extern
 195:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   __attribute__((__format__ (gnu_printf, 2, 3))) __MINGW_ATTRIB_NONNULL(2)
 196:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   int __cdecl __mingw_fprintf (FILE * __restrict__ , const char * __restrict__ , ...) __MINGW_NOTHR
 197:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** extern
 198:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   __attribute__((__format__ (gnu_printf, 2, 0))) __MINGW_ATTRIB_NONNULL(2)
 199:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   int __cdecl __mingw_vfprintf (FILE * __restrict__ , const char * __restrict__ , va_list) __MINGW_
 200:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** extern
 201:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   __attribute__((__format__ (gnu_printf, 2, 3))) __MINGW_ATTRIB_NONNULL(2)
 202:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   int __cdecl __mingw_sprintf (char * __restrict__ , const char * __restrict__ , ...) __MINGW_NOTHR
 203:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** extern
 204:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   __attribute__((__format__ (gnu_printf, 2, 0))) __MINGW_ATTRIB_NONNULL(2)
 205:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   int __cdecl __mingw_vsprintf (char * __restrict__ , const char * __restrict__ , va_list) __MINGW_
 206:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** extern
 207:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   __attribute__((__format__ (gnu_printf, 2, 3))) __attribute__((nonnull (1,2)))
 208:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   int __cdecl __mingw_asprintf(char ** __restrict__ , const char * __restrict__ , ...) __MINGW_NOTH
 209:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** extern
 210:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   __attribute__((__format__ (gnu_printf, 2, 0))) __attribute__((nonnull (1,2)))
 211:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   int __cdecl __mingw_vasprintf(char ** __restrict__ , const char * __restrict__ , va_list) __MINGW
 212:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
 213:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #if __MSVCRT_VERSION__ >= 0x1400
 214:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   int __cdecl __stdio_common_vsprintf(unsigned __int64 options, char *str, size_t len, const char *
 215:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   int __cdecl __stdio_common_vfprintf(unsigned __int64 options, FILE *file, const char *format, _lo
 216:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   int __cdecl __stdio_common_vsscanf(unsigned __int64 options, const char *input, size_t length, co
 217:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   int __cdecl __stdio_common_vfscanf(unsigned __int64 options, FILE *file, const char *format, _loc
 218:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #endif
 219:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
 220:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #undef __MINGW_PRINTF_FORMAT
 221:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #undef __MINGW_SCANF_FORMAT
 222:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
 223:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #if defined(__clang__)
 224:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define __MINGW_PRINTF_FORMAT printf
 225:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define __MINGW_SCANF_FORMAT  scanf
 226:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #elif defined(__USE_MINGW_ANSI_STDIO)
 227:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define __MINGW_PRINTF_FORMAT gnu_printf
 228:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define __MINGW_SCANF_FORMAT  gnu_scanf
 229:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #else
 230:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define __MINGW_PRINTF_FORMAT ms_printf
 231:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #define __MINGW_SCANF_FORMAT  ms_scanf
 232:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #endif
 233:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
 234:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #if __USE_MINGW_ANSI_STDIO
 235:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** /*
 236:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****  * User has expressed a preference for C99 conformance...
 237:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****  */
 238:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
 239:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #ifdef _GNU_SOURCE
 240:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** __mingw_ovr
 241:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** __attribute__ ((__format__ (gnu_printf, 2, 3))) __attribute__((nonnull (1,2)))
 242:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** int asprintf(char **__ret, const char *__format, ...)
 243:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** {
 244:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   int __retval;
 245:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
 246:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   __retval = __mingw_vasprintf( __ret, __format, __local_argv );
 247:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   __builtin_va_end( __local_argv );
 248:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   return __retval;
 249:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** }
 250:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
 251:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** __mingw_ovr
 252:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** __attribute__ ((__format__ (gnu_printf, 2, 0))) __attribute__((nonnull (1,2)))
 253:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** int vasprintf(char **__ret, const char *__format, __builtin_va_list __local_argv)
 254:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** {
 255:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   return __mingw_vasprintf( __ret, __format, __local_argv );
 256:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** }
 257:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #endif /* _GNU_SOURCE */
 258:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
 259:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** /* There seems to be a bug about builtins and static overrides of them
 260:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****    in g++.  So we need to do here some trickery.  */
 261:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #ifdef __cplusplus
 262:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** extern "C++" {
 263:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #endif
 264:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
 265:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** __mingw_ovr
 266:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** __attribute__((__format__ (gnu_scanf, 2, 3))) __MINGW_ATTRIB_NONNULL(2)
 267:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** int sscanf(const char *__source, const char *__format, ...)
 268:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** {
 269:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   int __retval;
 270:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
 271:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   __retval = __mingw_vsscanf( __source, __format, __local_argv );
 272:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   __builtin_va_end( __local_argv );
 273:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   return __retval;
 274:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** }
 275:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
 276:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** __mingw_ovr
 277:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** __attribute__((__format__ (gnu_scanf, 1, 2))) __MINGW_ATTRIB_NONNULL(1)
 278:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** int scanf(const char *__format, ...)
 279:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** {
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
 280:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   int __retval;
 281:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
  34              		.loc 1 281 53
  35 001e 488D45D8 		leaq	-40(%rbp), %rax
  36 0022 488945A0 		movq	%rax, -96(%rbp)
 282:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   __retval = __mingw_vfscanf( stdin, __format, __local_argv );
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
 283:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   __builtin_va_end( __local_argv );
 284:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   return __retval;
  48              		.loc 1 284 10
  49 004a 8B45AC   		movl	-84(%rbp), %eax
 285:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** }
  50              		.loc 1 285 1
  51 004d 4883C438 		addq	$56, %rsp
  52 0051 5B       		popq	%rbx
  53              		.cfi_restore 3
  54 0052 5D       		popq	%rbp
  55              		.cfi_restore 6
  56              		.cfi_def_cfa 7, -40
  57 0053 C3       		ret
  58              		.cfi_endproc
  59              	.LFE476:
  60              		.seh_endproc
  61 0054 90909090 		.section	.text$_Z6printfPKcz,"x"
  61      90909090 
  61      90909090 
  62              		.linkonce discard
  63              		.globl	_Z6printfPKcz
  65              		.seh_proc	_Z6printfPKcz
  66              	_Z6printfPKcz:
  67              	.LFB482:
 286:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
 287:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** __mingw_ovr
 288:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** __attribute__((__format__ (gnu_scanf, 2, 3))) __MINGW_ATTRIB_NONNULL(2)
 289:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** int fscanf(FILE *__stream, const char *__format, ...)
 290:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** {
 291:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   int __retval;
 292:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
 293:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   __retval = __mingw_vfscanf( __stream, __format, __local_argv );
 294:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   __builtin_va_end( __local_argv );
 295:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   return __retval;
 296:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** }
 297:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
 298:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
 299:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #ifdef __GNUC__
 300:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #pragma GCC diagnostic push
 301:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #pragma GCC diagnostic ignored "-Wshadow"
 302:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #endif
 303:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
 304:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** __mingw_ovr
 305:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** __attribute__((__format__ (gnu_scanf, 2, 0))) __MINGW_ATTRIB_NONNULL(2)
 306:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** int vsscanf (const char *__source, const char *__format, __builtin_va_list __local_argv)
 307:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** {
 308:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   return __mingw_vsscanf( __source, __format, __local_argv );
 309:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** }
 310:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
 311:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** __mingw_ovr
 312:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** __attribute__((__format__ (gnu_scanf, 1, 0))) __MINGW_ATTRIB_NONNULL(1)
 313:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** int vscanf(const char *__format,  __builtin_va_list __local_argv)
 314:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** {
 315:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   return __mingw_vfscanf( stdin, __format, __local_argv );
 316:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** }
 317:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
 318:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** __mingw_ovr
 319:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** __attribute__((__format__ (gnu_scanf, 2, 0))) __MINGW_ATTRIB_NONNULL(2)
 320:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** int vfscanf (FILE *__stream,  const char *__format, __builtin_va_list __local_argv)
 321:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** {
 322:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   return __mingw_vfscanf( __stream, __format, __local_argv );
 323:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** }
 324:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
 325:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #ifdef __GNUC__
 326:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #pragma GCC diagnostic pop
 327:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #endif
 328:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** #endif /* __NO_ISOCEXT */
 329:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
 330:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
 331:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
 332:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** __mingw_ovr
 333:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** __attribute__((__format__ (gnu_printf, 2, 3))) __MINGW_ATTRIB_NONNULL(2)
 334:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** int fprintf (FILE *__stream, const char *__format, ...)
 335:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** {
 336:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   int __retval;
 337:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
 338:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   __retval = __mingw_vfprintf( __stream, __format, __local_argv );
 339:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   __builtin_va_end( __local_argv );
 340:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   return __retval;
 341:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** }
 342:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** 
 343:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** __mingw_ovr
 344:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** __attribute__((__format__ (gnu_printf, 1, 2))) __MINGW_ATTRIB_NONNULL(1)
 345:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** int printf (const char *__format, ...)
 346:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** {
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
 347:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   int __retval;
 348:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
  89              		.loc 1 348 53
  90 001e 488D45D8 		leaq	-40(%rbp), %rax
  91 0022 488945A0 		movq	%rax, -96(%rbp)
 349:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   __retval = __mingw_vfprintf( stdout, __format, __local_argv );
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
 350:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   __builtin_va_end( __local_argv );
 351:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   return __retval;
 103              		.loc 1 351 10
 104 004a 8B45AC   		movl	-84(%rbp), %eax
 352:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** }
 105              		.loc 1 352 1
 106 004d 4883C438 		addq	$56, %rsp
 107 0051 5B       		popq	%rbx
 108              		.cfi_restore 3
 109 0052 5D       		popq	%rbp
 110              		.cfi_restore 6
 111              		.cfi_def_cfa 7, -40
 112 0053 C3       		ret
 113              		.cfi_endproc
 114              	.LFE482:
 115              		.seh_endproc
 116 0054 90909090 		.section .rdata,"dr"
 116      90909090 
 116      90909090 
 117              		.align 4
 118              	_ZL1M:
 119 0000 C8000000 		.long	200
 120              		.globl	f
 121              		.bss
 122              		.align 32
 123              	f:
 124 0000 00000000 		.space 804
 124      00000000 
 124      00000000 
 124      00000000 
 124      00000000 
 126 0324 00000000 		.section .rdata,"dr"
 126      00000000 
 126      00000000 
 126      00000000 
 126      00000000 
 127              	.LC0:
 128 0004 25642564 		.ascii "%d%d\0"
 128      00
 129              	.LC1:
 130 0009 256400   		.ascii "%d\0"
 131 000c 00000000 		.text
 132              		.globl	main
 134              		.seh_proc	main
 135              	main:
 136              	.LFB518:
 137              		.file 2 "../code/C++/01\261\263\260\374\316\312\314\342/19_1_DP.cpp"
   1:../code/C++/01背包问题/19_1_DP.cpp **** // AC
   2:../code/C++/01背包问题/19_1_DP.cpp **** #include <algorithm>
   3:../code/C++/01背包问题/19_1_DP.cpp **** #include <cstdio>
   4:../code/C++/01背包问题/19_1_DP.cpp **** 
   5:../code/C++/01背包问题/19_1_DP.cpp **** using std::max;
   6:../code/C++/01背包问题/19_1_DP.cpp **** 
   7:../code/C++/01背包问题/19_1_DP.cpp **** const int M = 200;
   8:../code/C++/01背包问题/19_1_DP.cpp **** int f[M + 1];
   9:../code/C++/01背包问题/19_1_DP.cpp **** 
  10:../code/C++/01背包问题/19_1_DP.cpp **** int main()
  11:../code/C++/01背包问题/19_1_DP.cpp **** {
 138              		.loc 2 11 1
 139              		.cfi_startproc
 140 0000 55       		pushq	%rbp
 141              		.seh_pushreg	%rbp
 142              		.cfi_def_cfa_offset 16
 143              		.cfi_offset 6, -16
 144 0001 4889E5   		movq	%rsp, %rbp
 145              		.seh_setframe	%rbp, 0
 146              		.cfi_def_cfa_register 6
 147 0004 4883EC40 		subq	$64, %rsp
 148              		.seh_stackalloc	64
 149              		.seh_endprologue
 150              		.loc 2 11 1
 151 0008 E8000000 		call	__main
 151      00
 152              	.LVL2:
  12:../code/C++/01背包问题/19_1_DP.cpp **** 	int m, n;
  13:../code/C++/01背包问题/19_1_DP.cpp **** 	scanf("%d%d", &m, &n);
 153              		.loc 2 13 7
 154 000d 488D55EC 		leaq	-20(%rbp), %rdx
 155 0011 488D45F0 		leaq	-16(%rbp), %rax
 156 0015 4989D0   		movq	%rdx, %r8
 157 0018 4889C2   		movq	%rax, %rdx
 158 001b 488D0D04 		leaq	.LC0(%rip), %rcx
 158      000000
 159 0022 E8000000 		call	_Z5scanfPKcz
 159      00
 160              	.LBB2:
  14:../code/C++/01背包问题/19_1_DP.cpp **** 	for (int i = 0; i < n; ++i)
 161              		.loc 2 14 11
 162 0027 C745FC00 		movl	$0, -4(%rbp)
 162      000000
 163              	.L9:
 164              		.loc 2 14 20 discriminator 1
 165 002e 8B45EC   		movl	-20(%rbp), %eax
 166 0031 3945FC   		cmpl	%eax, -4(%rbp)
 167 0034 0F8D9A00 		jge	.L6
 167      0000
 168              	.LBB3:
  15:../code/C++/01背包问题/19_1_DP.cpp **** 	{
  16:../code/C++/01背包问题/19_1_DP.cpp **** 		int w, c;
  17:../code/C++/01背包问题/19_1_DP.cpp **** 		scanf("%d%d", &w, &c);
 169              		.loc 2 17 8
 170 003a 488D55E4 		leaq	-28(%rbp), %rdx
 171 003e 488D45E8 		leaq	-24(%rbp), %rax
 172 0042 4989D0   		movq	%rdx, %r8
 173 0045 4889C2   		movq	%rax, %rdx
 174 0048 488D0D04 		leaq	.LC0(%rip), %rcx
 174      000000
 175 004f E8000000 		call	_Z5scanfPKcz
 175      00
 176              	.LBB4:
  18:../code/C++/01背包问题/19_1_DP.cpp **** 		for (int j = m; j >= w; --j) f[j] = max(f[j], f[j - w] + c);
 177              		.loc 2 18 12
 178 0054 8B45F0   		movl	-16(%rbp), %eax
 179 0057 8945F8   		movl	%eax, -8(%rbp)
 180              	.L8:
 181              		.loc 2 18 21 discriminator 3
 182 005a 8B45E8   		movl	-24(%rbp), %eax
 183 005d 3945F8   		cmpl	%eax, -8(%rbp)
 184 0060 7C69     		jl	.L7
 185              		.loc 2 18 53 discriminator 2
 186 0062 8B45E8   		movl	-24(%rbp), %eax
 187 0065 8B55F8   		movl	-8(%rbp), %edx
 188 0068 29C2     		subl	%eax, %edx
 189 006a 89D0     		movl	%edx, %eax
 190              		.loc 2 18 56 discriminator 2
 191 006c 4898     		cltq
 192 006e 488D1485 		leaq	0(,%rax,4), %rdx
 192      00000000 
 193 0076 488D0500 		leaq	f(%rip), %rax
 193      000000
 194 007d 8B1402   		movl	(%rdx,%rax), %edx
 195              		.loc 2 18 58 discriminator 2
 196 0080 8B45E4   		movl	-28(%rbp), %eax
 197 0083 01D0     		addl	%edx, %eax
 198 0085 8945F4   		movl	%eax, -12(%rbp)
 199              		.loc 2 18 46 discriminator 2
 200 0088 8B45F8   		movl	-8(%rbp), %eax
 201 008b 4898     		cltq
 202 008d 488D1485 		leaq	0(,%rax,4), %rdx
 202      00000000 
 203 0095 488D0500 		leaq	f(%rip), %rax
 203      000000
 204 009c 488D0C02 		leaq	(%rdx,%rax), %rcx
 205              		.loc 2 18 61 discriminator 2
 206 00a0 488D45F4 		leaq	-12(%rbp), %rax
 207 00a4 4889C2   		movq	%rax, %rdx
 208 00a7 E8000000 		call	_ZSt3maxIiERKT_S2_S2_
 208      00
 209              		.loc 2 18 42 discriminator 2
 210 00ac 8B08     		movl	(%rax), %ecx
 211              		.loc 2 18 37 discriminator 2
 212 00ae 8B45F8   		movl	-8(%rbp), %eax
 213 00b1 4898     		cltq
 214 00b3 488D1485 		leaq	0(,%rax,4), %rdx
 214      00000000 
 215 00bb 488D0500 		leaq	f(%rip), %rax
 215      000000
 216 00c2 890C02   		movl	%ecx, (%rdx,%rax)
 217              		.loc 2 18 3 discriminator 2
 218 00c5 836DF801 		subl	$1, -8(%rbp)
 219 00c9 EB8F     		jmp	.L8
 220              	.L7:
 221              	.LBE4:
 222              	.LBE3:
  14:../code/C++/01背包问题/19_1_DP.cpp **** 	for (int i = 0; i < n; ++i)
 223              		.loc 2 14 2 discriminator 2
 224 00cb 8345FC01 		addl	$1, -4(%rbp)
 225 00cf E95AFFFF 		jmp	.L9
 225      FF
 226              	.L6:
 227              	.LBE2:
  19:../code/C++/01背包问题/19_1_DP.cpp **** 	}
  20:../code/C++/01背包问题/19_1_DP.cpp **** 	printf("%d", f[m]);
 228              		.loc 2 20 8
 229 00d4 8B45F0   		movl	-16(%rbp), %eax
 230 00d7 4898     		cltq
 231 00d9 488D1485 		leaq	0(,%rax,4), %rdx
 231      00000000 
 232 00e1 488D0500 		leaq	f(%rip), %rax
 232      000000
 233 00e8 8B0402   		movl	(%rdx,%rax), %eax
 234 00eb 89C2     		movl	%eax, %edx
 235 00ed 488D0D09 		leaq	.LC1(%rip), %rcx
 235      000000
 236 00f4 E8000000 		call	_Z6printfPKcz
 236      00
  21:../code/C++/01背包问题/19_1_DP.cpp **** 	return 0;
 237              		.loc 2 21 9
 238 00f9 B8000000 		movl	$0, %eax
 238      00
  22:../code/C++/01背包问题/19_1_DP.cpp **** }...
 239              		.loc 2 22 1
 240 00fe 4883C440 		addq	$64, %rsp
 241 0102 5D       		popq	%rbp
 242              		.cfi_restore 6
 243              		.cfi_def_cfa 7, 8
 244 0103 C3       		ret
 245              		.cfi_endproc
 246              	.LFE518:
 247              		.seh_endproc
 248              		.section	.text$_ZSt3maxIiERKT_S2_S2_,"x"
 249              		.linkonce discard
 250              		.globl	_ZSt3maxIiERKT_S2_S2_
 252              		.seh_proc	_ZSt3maxIiERKT_S2_S2_
 253              	_ZSt3maxIiERKT_S2_S2_:
 254              	.LFB519:
 255              		.file 3 "C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-m
   1:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** // Core algorithmic facilities -*- C++ -*-
   2:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 
   3:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** // Copyright (C) 2001-2018 Free Software Foundation, Inc.
   4:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** //
   5:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** // This file is part of the GNU ISO C++ Library.  This library is free
   6:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** // software; you can redistribute it and/or modify it under the
   7:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** // terms of the GNU General Public License as published by the
   8:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** // Free Software Foundation; either version 3, or (at your option)
   9:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** // any later version.
  10:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 
  11:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** // This library is distributed in the hope that it will be useful,
  12:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** // but WITHOUT ANY WARRANTY; without even the implied warranty of
  13:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** // MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  14:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** // GNU General Public License for more details.
  15:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 
  16:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** // Under Section 7 of GPL version 3, you are granted additional
  17:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** // permissions described in the GCC Runtime Library Exception, version
  18:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** // 3.1, as published by the Free Software Foundation.
  19:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 
  20:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** // You should have received a copy of the GNU General Public License and
  21:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** // a copy of the GCC Runtime Library Exception along with this program;
  22:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** // see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
  23:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** // <http://www.gnu.org/licenses/>.
  24:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 
  25:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** /*
  26:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****  *
  27:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****  * Copyright (c) 1994
  28:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****  * Hewlett-Packard Company
  29:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****  *
  30:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****  * Permission to use, copy, modify, distribute and sell this software
  31:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****  * and its documentation for any purpose is hereby granted without fee,
  32:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****  * provided that the above copyright notice appear in all copies and
  33:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****  * that both that copyright notice and this permission notice appear
  34:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****  * in supporting documentation.  Hewlett-Packard Company makes no
  35:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****  * representations about the suitability of this software for any
  36:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****  * purpose.  It is provided "as is" without express or implied warranty.
  37:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****  *
  38:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****  *
  39:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****  * Copyright (c) 1996-1998
  40:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****  * Silicon Graphics Computer Systems, Inc.
  41:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****  *
  42:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****  * Permission to use, copy, modify, distribute and sell this software
  43:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****  * and its documentation for any purpose is hereby granted without fee,
  44:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****  * provided that the above copyright notice appear in all copies and
  45:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****  * that both that copyright notice and this permission notice appear
  46:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****  * in supporting documentation.  Silicon Graphics makes no
  47:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****  * representations about the suitability of this software for any
  48:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****  * purpose.  It is provided "as is" without express or implied warranty.
  49:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****  */
  50:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 
  51:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** /** @file bits/stl_algobase.h
  52:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****  *  This is an internal header file, included by other library headers.
  53:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****  *  Do not attempt to use it directly. @headername{algorithm}
  54:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****  */
  55:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 
  56:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** #ifndef _STL_ALGOBASE_H
  57:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** #define _STL_ALGOBASE_H 1
  58:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 
  59:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** #include <bits/c++config.h>
  60:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** #include <bits/functexcept.h>
  61:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** #include <bits/cpp_type_traits.h>
  62:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** #include <ext/type_traits.h>
  63:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** #include <ext/numeric_traits.h>
  64:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** #include <bits/stl_pair.h>
  65:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** #include <bits/stl_iterator_base_types.h>
  66:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** #include <bits/stl_iterator_base_funcs.h>
  67:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** #include <bits/stl_iterator.h>
  68:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** #include <bits/concept_check.h>
  69:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** #include <debug/debug.h>
  70:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** #include <bits/move.h> // For std::swap
  71:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** #include <bits/predefined_ops.h>
  72:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 
  73:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** namespace std _GLIBCXX_VISIBILITY(default)
  74:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** {
  75:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** _GLIBCXX_BEGIN_NAMESPACE_VERSION
  76:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 
  77:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** #if __cplusplus < 201103L
  78:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****   // See http://gcc.gnu.org/ml/libstdc++/2004-08/msg00167.html: in a
  79:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****   // nutshell, we are partially implementing the resolution of DR 187,
  80:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****   // when it's safe, i.e., the value_types are equal.
  81:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****   template<bool _BoolType>
  82:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****     struct __iter_swap
  83:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****     {
  84:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****       template<typename _ForwardIterator1, typename _ForwardIterator2>
  85:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 	static void
  86:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 	iter_swap(_ForwardIterator1 __a, _ForwardIterator2 __b)
  87:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 	{
  88:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 	  typedef typename iterator_traits<_ForwardIterator1>::value_type
  89:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 	    _ValueType1;
  90:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 	  _ValueType1 __tmp = *__a;
  91:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 	  *__a = *__b;
  92:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 	  *__b = __tmp;
  93:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 	}
  94:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****     };
  95:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 
  96:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****   template<>
  97:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****     struct __iter_swap<true>
  98:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****     {
  99:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****       template<typename _ForwardIterator1, typename _ForwardIterator2>
 100:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 	static void
 101:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 	iter_swap(_ForwardIterator1 __a, _ForwardIterator2 __b)
 102:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 	{
 103:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 	  swap(*__a, *__b);
 104:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 	}
 105:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****     };
 106:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** #endif
 107:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 
 108:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****   /**
 109:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****    *  @brief Swaps the contents of two iterators.
 110:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****    *  @ingroup mutating_algorithms
 111:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****    *  @param  __a  An iterator.
 112:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****    *  @param  __b  Another iterator.
 113:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****    *  @return   Nothing.
 114:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****    *
 115:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****    *  This function swaps the values pointed to by two iterators, not the
 116:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****    *  iterators themselves.
 117:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****   */
 118:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****   template<typename _ForwardIterator1, typename _ForwardIterator2>
 119:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****     inline void
 120:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****     iter_swap(_ForwardIterator1 __a, _ForwardIterator2 __b)
 121:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****     {
 122:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****       // concept requirements
 123:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****       __glibcxx_function_requires(_Mutable_ForwardIteratorConcept<
 124:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 				  _ForwardIterator1>)
 125:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****       __glibcxx_function_requires(_Mutable_ForwardIteratorConcept<
 126:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 				  _ForwardIterator2>)
 127:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 
 128:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** #if __cplusplus < 201103L
 129:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****       typedef typename iterator_traits<_ForwardIterator1>::value_type
 130:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 	_ValueType1;
 131:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****       typedef typename iterator_traits<_ForwardIterator2>::value_type
 132:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 	_ValueType2;
 133:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 
 134:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****       __glibcxx_function_requires(_ConvertibleConcept<_ValueType1,
 135:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 				  _ValueType2>)
 136:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****       __glibcxx_function_requires(_ConvertibleConcept<_ValueType2,
 137:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 				  _ValueType1>)
 138:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 
 139:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****       typedef typename iterator_traits<_ForwardIterator1>::reference
 140:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 	_ReferenceType1;
 141:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****       typedef typename iterator_traits<_ForwardIterator2>::reference
 142:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 	_ReferenceType2;
 143:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****       std::__iter_swap<__are_same<_ValueType1, _ValueType2>::__value
 144:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 	&& __are_same<_ValueType1&, _ReferenceType1>::__value
 145:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 	&& __are_same<_ValueType2&, _ReferenceType2>::__value>::
 146:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 	iter_swap(__a, __b);
 147:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** #else
 148:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****       swap(*__a, *__b);
 149:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** #endif
 150:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****     }
 151:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 
 152:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****   /**
 153:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****    *  @brief Swap the elements of two sequences.
 154:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****    *  @ingroup mutating_algorithms
 155:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****    *  @param  __first1  A forward iterator.
 156:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****    *  @param  __last1   A forward iterator.
 157:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****    *  @param  __first2  A forward iterator.
 158:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****    *  @return   An iterator equal to @p first2+(last1-first1).
 159:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****    *
 160:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****    *  Swaps each element in the range @p [first1,last1) with the
 161:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****    *  corresponding element in the range @p [first2,(last1-first1)).
 162:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****    *  The ranges must not overlap.
 163:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****   */
 164:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****   template<typename _ForwardIterator1, typename _ForwardIterator2>
 165:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****     _ForwardIterator2
 166:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****     swap_ranges(_ForwardIterator1 __first1, _ForwardIterator1 __last1,
 167:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 		_ForwardIterator2 __first2)
 168:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****     {
 169:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****       // concept requirements
 170:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****       __glibcxx_function_requires(_Mutable_ForwardIteratorConcept<
 171:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 				  _ForwardIterator1>)
 172:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****       __glibcxx_function_requires(_Mutable_ForwardIteratorConcept<
 173:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 				  _ForwardIterator2>)
 174:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****       __glibcxx_requires_valid_range(__first1, __last1);
 175:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 
 176:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****       for (; __first1 != __last1; ++__first1, (void)++__first2)
 177:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 	std::iter_swap(__first1, __first2);
 178:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****       return __first2;
 179:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****     }
 180:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 
 181:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****   /**
 182:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****    *  @brief This does what you think it does.
 183:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****    *  @ingroup sorting_algorithms
 184:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****    *  @param  __a  A thing of arbitrary type.
 185:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****    *  @param  __b  Another thing of arbitrary type.
 186:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****    *  @return   The lesser of the parameters.
 187:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****    *
 188:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****    *  This is the simple classic generic implementation.  It will work on
 189:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****    *  temporary expressions, since they are only evaluated once, unlike a
 190:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****    *  preprocessor macro.
 191:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****   */
 192:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****   template<typename _Tp>
 193:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****     _GLIBCXX14_CONSTEXPR
 194:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****     inline const _Tp&
 195:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****     min(const _Tp& __a, const _Tp& __b)
 196:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****     {
 197:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****       // concept requirements
 198:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****       __glibcxx_function_requires(_LessThanComparableConcept<_Tp>)
 199:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****       //return __b < __a ? __b : __a;
 200:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****       if (__b < __a)
 201:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 	return __b;
 202:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****       return __a;
 203:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****     }
 204:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 
 205:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****   /**
 206:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****    *  @brief This does what you think it does.
 207:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****    *  @ingroup sorting_algorithms
 208:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****    *  @param  __a  A thing of arbitrary type.
 209:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****    *  @param  __b  Another thing of arbitrary type.
 210:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****    *  @return   The greater of the parameters.
 211:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****    *
 212:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****    *  This is the simple classic generic implementation.  It will work on
 213:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****    *  temporary expressions, since they are only evaluated once, unlike a
 214:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****    *  preprocessor macro.
 215:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****   */
 216:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****   template<typename _Tp>
 217:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****     _GLIBCXX14_CONSTEXPR
 218:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****     inline const _Tp&
 219:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****     max(const _Tp& __a, const _Tp& __b)
 256              		.loc 3 219 5
 257              		.cfi_startproc
 258 0000 55       		pushq	%rbp
 259              		.seh_pushreg	%rbp
 260              		.cfi_def_cfa_offset 16
 261              		.cfi_offset 6, -16
 262 0001 4889E5   		movq	%rsp, %rbp
 263              		.seh_setframe	%rbp, 0
 264              		.cfi_def_cfa_register 6
 265              		.seh_endprologue
 266 0004 48894D10 		movq	%rcx, 16(%rbp)
 267 0008 48895518 		movq	%rdx, 24(%rbp)
 220:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****     {
 221:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****       // concept requirements
 222:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****       __glibcxx_function_requires(_LessThanComparableConcept<_Tp>)
 223:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****       //return  __a < __b ? __b : __a;
 224:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****       if (__a < __b)
 268              		.loc 3 224 15
 269 000c 488B4510 		movq	16(%rbp), %rax
 270 0010 8B10     		movl	(%rax), %edx
 271 0012 488B4518 		movq	24(%rbp), %rax
 272 0016 8B00     		movl	(%rax), %eax
 273              		.loc 3 224 7
 274 0018 39C2     		cmpl	%eax, %edx
 275 001a 7D06     		jge	.L12
 225:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h **** 	return __b;
 276              		.loc 3 225 9
 277 001c 488B4518 		movq	24(%rbp), %rax
 278 0020 EB04     		jmp	.L13
 279              	.L12:
 226:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****       return __a;
 280              		.loc 3 226 14
 281 0022 488B4510 		movq	16(%rbp), %rax
 282              	.L13:
 227:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits\stl_algobase.h ****     }
 283              		.loc 3 227 5
 284 0026 5D       		popq	%rbp
 285              		.cfi_restore 6
 286              		.cfi_def_cfa 7, 8
 287 0027 C3       		ret
 288              		.cfi_endproc
 289              	.LFE519:
 290              		.seh_endproc
 291 0028 90909090 		.text
 291      90909090 
 292              	.Letext0:
 293              		.file 4 "C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-m
 294              		.file 5 "C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-m
 295              		.file 6 "C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-m
 296              		.file 7 "C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-m
 297              		.file 8 "C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-m
 298              		.file 9 "C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-m
 299              		.file 10 "C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-
 300              		.file 11 "C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-
 301              		.file 12 "C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/
 302              		.file 13 "C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/
 303              		.file 14 "C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/
 304              		.file 15 "<built-in>"
 305              		.file 16 "C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-
 306 0104 90909090 		.section	.debug_info,"dr"
 306      90909090 
 306      90909090 
 307              	.Ldebug_info0:
 308 0000 89140000 		.long	0x1489
 309 0004 0400     		.word	0x4
 310 0006 00000000 		.secrel32	.Ldebug_abbrev0
 311 000a 08       		.byte	0x8
 312 000b 01       		.uleb128 0x1
 313 000c 474E5520 		.ascii "GNU C++98 8.1.0 -mtune=core2 -march=nocona -g -std=gnu++98\0"
 313      432B2B39 
 313      3820382E 
 313      312E3020 
 313      2D6D7475 
 314 0047 04       		.byte	0x4
 315 0048 2E2E2F63 		.ascii "../code/C++/01\261\263\260\374\316\312\314\342/19_1_DP.cpp\0"
 315      6F64652F 
 315      432B2B2F 
 315      3031B1B3 
 315      B0FCCECA 
 316 006b 453A5C4F 		.ascii "E:\\OI-Files\0"
 316      492D4669 
 316      6C657300 
 317 0077 00000000 		.secrel32	.Ldebug_ranges0+0
 318 007b 00000000 		.quad	0
 318      00000000 
 319 0083 00000000 		.secrel32	.Ldebug_line0
 320 0087 02       		.uleb128 0x2
 321 0088 73746400 		.ascii "std\0"
 322 008c 0F       		.byte	0xf
 323 008d 00       		.byte	0
 324 008e 94030000 		.long	0x394
 325 0092 03       		.uleb128 0x3
 326 0093 5F5F6378 		.ascii "__cxx11\0"
 326      78313100 
 327 009b 05       		.byte	0x5
 328 009c 0401     		.word	0x104
 329 009e 41       		.byte	0x41
 330 009f 04       		.uleb128 0x4
 331 00a0 05       		.byte	0x5
 332 00a1 0401     		.word	0x104
 333 00a3 41       		.byte	0x41
 334 00a4 92000000 		.long	0x92
 335 00a8 05       		.uleb128 0x5
 336 00a9 5F5F6465 		.ascii "__debug\0"
 336      62756700 
 337 00b1 08       		.byte	0x8
 338 00b2 32       		.byte	0x32
 339 00b3 0D       		.byte	0xd
 340 00b4 06       		.uleb128 0x6
 341 00b5 04       		.byte	0x4
 342 00b6 7F       		.byte	0x7f
 343 00b7 0B       		.byte	0xb
 344 00b8 58060000 		.long	0x658
 345 00bc 06       		.uleb128 0x6
 346 00bd 04       		.byte	0x4
 347 00be 80       		.byte	0x80
 348 00bf 0B       		.byte	0xb
 349 00c0 93060000 		.long	0x693
 350 00c4 06       		.uleb128 0x6
 351 00c5 04       		.byte	0x4
 352 00c6 86       		.byte	0x86
 353 00c7 0B       		.byte	0xb
 354 00c8 90080000 		.long	0x890
 355 00cc 06       		.uleb128 0x6
 356 00cd 04       		.byte	0x4
 357 00ce 8C       		.byte	0x8c
 358 00cf 0B       		.byte	0xb
 359 00d0 AA080000 		.long	0x8aa
 360 00d4 06       		.uleb128 0x6
 361 00d5 04       		.byte	0x4
 362 00d6 8D       		.byte	0x8d
 363 00d7 0B       		.byte	0xb
 364 00d8 C8080000 		.long	0x8c8
 365 00dc 06       		.uleb128 0x6
 366 00dd 04       		.byte	0x4
 367 00de 8E       		.byte	0x8e
 368 00df 0B       		.byte	0xb
 369 00e0 E0080000 		.long	0x8e0
 370 00e4 06       		.uleb128 0x6
 371 00e5 04       		.byte	0x4
 372 00e6 8F       		.byte	0x8f
 373 00e7 0B       		.byte	0xb
 374 00e8 F8080000 		.long	0x8f8
 375 00ec 06       		.uleb128 0x6
 376 00ed 04       		.byte	0x4
 377 00ee 91       		.byte	0x91
 378 00ef 0B       		.byte	0xb
 379 00f0 4A090000 		.long	0x94a
 380 00f4 06       		.uleb128 0x6
 381 00f5 04       		.byte	0x4
 382 00f6 94       		.byte	0x94
 383 00f7 0B       		.byte	0xb
 384 00f8 66090000 		.long	0x966
 385 00fc 06       		.uleb128 0x6
 386 00fd 04       		.byte	0x4
 387 00fe 96       		.byte	0x96
 388 00ff 0B       		.byte	0xb
 389 0100 80090000 		.long	0x980
 390 0104 06       		.uleb128 0x6
 391 0105 04       		.byte	0x4
 392 0106 99       		.byte	0x99
 393 0107 0B       		.byte	0xb
 394 0108 9D090000 		.long	0x99d
 395 010c 06       		.uleb128 0x6
 396 010d 04       		.byte	0x4
 397 010e 9A       		.byte	0x9a
 398 010f 0B       		.byte	0xb
 399 0110 BB090000 		.long	0x9bb
 400 0114 06       		.uleb128 0x6
 401 0115 04       		.byte	0x4
 402 0116 9B       		.byte	0x9b
 403 0117 0B       		.byte	0xb
 404 0118 E1090000 		.long	0x9e1
 405 011c 06       		.uleb128 0x6
 406 011d 04       		.byte	0x4
 407 011e 9D       		.byte	0x9d
 408 011f 0B       		.byte	0xb
 409 0120 050A0000 		.long	0xa05
 410 0124 06       		.uleb128 0x6
 411 0125 04       		.byte	0x4
 412 0126 A3       		.byte	0xa3
 413 0127 0B       		.byte	0xb
 414 0128 290A0000 		.long	0xa29
 415 012c 06       		.uleb128 0x6
 416 012d 04       		.byte	0x4
 417 012e A5       		.byte	0xa5
 418 012f 0B       		.byte	0xb
 419 0130 370A0000 		.long	0xa37
 420 0134 06       		.uleb128 0x6
 421 0135 04       		.byte	0x4
 422 0136 A6       		.byte	0xa6
 423 0137 0B       		.byte	0xb
 424 0138 4C0A0000 		.long	0xa4c
 425 013c 06       		.uleb128 0x6
 426 013d 04       		.byte	0x4
 427 013e A7       		.byte	0xa7
 428 013f 0B       		.byte	0xb
 429 0140 6B0A0000 		.long	0xa6b
 430 0144 06       		.uleb128 0x6
 431 0145 04       		.byte	0x4
 432 0146 A8       		.byte	0xa8
 433 0147 0B       		.byte	0xb
 434 0148 8F0A0000 		.long	0xa8f
 435 014c 06       		.uleb128 0x6
 436 014d 04       		.byte	0x4
 437 014e A9       		.byte	0xa9
 438 014f 0B       		.byte	0xb
 439 0150 B40A0000 		.long	0xab4
 440 0154 06       		.uleb128 0x6
 441 0155 04       		.byte	0x4
 442 0156 AB       		.byte	0xab
 443 0157 0B       		.byte	0xb
 444 0158 CE0A0000 		.long	0xace
 445 015c 06       		.uleb128 0x6
 446 015d 04       		.byte	0x4
 447 015e AC       		.byte	0xac
 448 015f 0B       		.byte	0xb
 449 0160 F40A0000 		.long	0xaf4
 450 0164 06       		.uleb128 0x6
 451 0165 04       		.byte	0x4
 452 0166 F0       		.byte	0xf0
 453 0167 16       		.byte	0x16
 454 0168 6D080000 		.long	0x86d
 455 016c 06       		.uleb128 0x6
 456 016d 04       		.byte	0x4
 457 016e F5       		.byte	0xf5
 458 016f 16       		.byte	0x16
 459 0170 FF030000 		.long	0x3ff
 460 0174 06       		.uleb128 0x6
 461 0175 04       		.byte	0x4
 462 0176 F6       		.byte	0xf6
 463 0177 16       		.byte	0x16
 464 0178 130B0000 		.long	0xb13
 465 017c 06       		.uleb128 0x6
 466 017d 04       		.byte	0x4
 467 017e F8       		.byte	0xf8
 468 017f 16       		.byte	0x16
 469 0180 310B0000 		.long	0xb31
 470 0184 06       		.uleb128 0x6
 471 0185 04       		.byte	0x4
 472 0186 F9       		.byte	0xf9
 473 0187 16       		.byte	0x16
 474 0188 950B0000 		.long	0xb95
 475 018c 06       		.uleb128 0x6
 476 018d 04       		.byte	0x4
 477 018e FA       		.byte	0xfa
 478 018f 16       		.byte	0x16
 479 0190 4A0B0000 		.long	0xb4a
 480 0194 06       		.uleb128 0x6
 481 0195 04       		.byte	0x4
 482 0196 FB       		.byte	0xfb
 483 0197 16       		.byte	0x16
 484 0198 6F0B0000 		.long	0xb6f
 485 019c 06       		.uleb128 0x6
 486 019d 04       		.byte	0x4
 487 019e FC       		.byte	0xfc
 488 019f 16       		.byte	0x16
 489 01a0 B40B0000 		.long	0xbb4
 490 01a4 03       		.uleb128 0x3
 491 01a5 5F563200 		.ascii "_V2\0"
 492 01a9 06       		.byte	0x6
 493 01aa 2202     		.word	0x222
 494 01ac 14       		.byte	0x14
 495 01ad 04       		.uleb128 0x4
 496 01ae 06       		.byte	0x6
 497 01af 2202     		.word	0x222
 498 01b1 14       		.byte	0x14
 499 01b2 A4010000 		.long	0x1a4
 500 01b6 07       		.uleb128 0x7
 501 01b7 6E6F7468 		.ascii "nothrow_t\0"
 501      726F775F 
 501      7400
 502 01c1 01       		.byte	0x1
 503 01c2 10       		.byte	0x10
 504 01c3 56       		.byte	0x56
 505 01c4 0A       		.byte	0xa
 506 01c5 08       		.uleb128 0x8
 507 01c6 B6010000 		.long	0x1b6
 508 01ca 09       		.uleb128 0x9
 509 01cb 6E6F7468 		.ascii "nothrow\0"
 509      726F7700 
 510 01d3 10       		.byte	0x10
 511 01d4 5D       		.byte	0x5d
 512 01d5 1A       		.byte	0x1a
 513 01d6 5F5A5374 		.ascii "_ZSt7nothrow\0"
 513      376E6F74 
 513      68726F77 
 513      00
 514 01e3 C5010000 		.long	0x1c5
 515 01e7 0A       		.uleb128 0xa
 516 01e8 73697A65 		.ascii "size_t\0"
 516      5F7400
 517 01ef 05       		.byte	0x5
 518 01f0 EE       		.byte	0xee
 519 01f1 1A       		.byte	0x1a
 520 01f2 33050000 		.long	0x533
 521 01f6 0A       		.uleb128 0xa
 522 01f7 70747264 		.ascii "ptrdiff_t\0"
 522      6966665F 
 522      7400
 523 0201 05       		.byte	0x5
 524 0202 EF       		.byte	0xef
 525 0203 1C       		.byte	0x1c
 526 0204 81050000 		.long	0x581
 527 0208 06       		.uleb128 0x6
 528 0209 07       		.byte	0x7
 529 020a 62       		.byte	0x62
 530 020b 0B       		.byte	0xb
 531 020c 710C0000 		.long	0xc71
 532 0210 06       		.uleb128 0x6
 533 0211 07       		.byte	0x7
 534 0212 63       		.byte	0x63
 535 0213 0B       		.byte	0xb
 536 0214 7E0C0000 		.long	0xc7e
 537 0218 06       		.uleb128 0x6
 538 0219 07       		.byte	0x7
 539 021a 65       		.byte	0x65
 540 021b 0B       		.byte	0xb
 541 021c 920C0000 		.long	0xc92
 542 0220 06       		.uleb128 0x6
 543 0221 07       		.byte	0x7
 544 0222 66       		.byte	0x66
 545 0223 0B       		.byte	0xb
 546 0224 B00C0000 		.long	0xcb0
 547 0228 06       		.uleb128 0x6
 548 0229 07       		.byte	0x7
 549 022a 67       		.byte	0x67
 550 022b 0B       		.byte	0xb
 551 022c CA0C0000 		.long	0xcca
 552 0230 06       		.uleb128 0x6
 553 0231 07       		.byte	0x7
 554 0232 68       		.byte	0x68
 555 0233 0B       		.byte	0xb
 556 0234 E20C0000 		.long	0xce2
 557 0238 06       		.uleb128 0x6
 558 0239 07       		.byte	0x7
 559 023a 69       		.byte	0x69
 560 023b 0B       		.byte	0xb
 561 023c FC0C0000 		.long	0xcfc
 562 0240 06       		.uleb128 0x6
 563 0241 07       		.byte	0x7
 564 0242 6A       		.byte	0x6a
 565 0243 0B       		.byte	0xb
 566 0244 160D0000 		.long	0xd16
 567 0248 06       		.uleb128 0x6
 568 0249 07       		.byte	0x7
 569 024a 6B       		.byte	0x6b
 570 024b 0B       		.byte	0xb
 571 024c 2F0D0000 		.long	0xd2f
 572 0250 06       		.uleb128 0x6
 573 0251 07       		.byte	0x7
 574 0252 6C       		.byte	0x6c
 575 0253 0B       		.byte	0xb
 576 0254 550D0000 		.long	0xd55
 577 0258 06       		.uleb128 0x6
 578 0259 07       		.byte	0x7
 579 025a 6D       		.byte	0x6d
 580 025b 0B       		.byte	0xb
 581 025c 780D0000 		.long	0xd78
 582 0260 06       		.uleb128 0x6
 583 0261 07       		.byte	0x7
 584 0262 6E       		.byte	0x6e
 585 0263 0B       		.byte	0xb
 586 0264 960D0000 		.long	0xd96
 587 0268 06       		.uleb128 0x6
 588 0269 07       		.byte	0x7
 589 026a 71       		.byte	0x71
 590 026b 0B       		.byte	0xb
 591 026c CE0D0000 		.long	0xdce
 592 0270 06       		.uleb128 0x6
 593 0271 07       		.byte	0x7
 594 0272 72       		.byte	0x72
 595 0273 0B       		.byte	0xb
 596 0274 F60D0000 		.long	0xdf6
 597 0278 06       		.uleb128 0x6
 598 0279 07       		.byte	0x7
 599 027a 73       		.byte	0x73
 600 027b 0B       		.byte	0xb
 601 027c 1B0E0000 		.long	0xe1b
 602 0280 06       		.uleb128 0x6
 603 0281 07       		.byte	0x7
 604 0282 74       		.byte	0x74
 605 0283 0B       		.byte	0xb
 606 0284 510E0000 		.long	0xe51
 607 0288 06       		.uleb128 0x6
 608 0289 07       		.byte	0x7
 609 028a 75       		.byte	0x75
 610 028b 0B       		.byte	0xb
 611 028c 740E0000 		.long	0xe74
 612 0290 06       		.uleb128 0x6
 613 0291 07       		.byte	0x7
 614 0292 76       		.byte	0x76
 615 0293 0B       		.byte	0xb
 616 0294 9A0E0000 		.long	0xe9a
 617 0298 06       		.uleb128 0x6
 618 0299 07       		.byte	0x7
 619 029a 78       		.byte	0x78
 620 029b 0B       		.byte	0xb
 621 029c B30E0000 		.long	0xeb3
 622 02a0 06       		.uleb128 0x6
 623 02a1 07       		.byte	0x7
 624 02a2 79       		.byte	0x79
 625 02a3 0B       		.byte	0xb
 626 02a4 CB0E0000 		.long	0xecb
 627 02a8 06       		.uleb128 0x6
 628 02a9 07       		.byte	0x7
 629 02aa 7C       		.byte	0x7c
 630 02ab 0B       		.byte	0xb
 631 02ac DC0E0000 		.long	0xedc
 632 02b0 06       		.uleb128 0x6
 633 02b1 07       		.byte	0x7
 634 02b2 7E       		.byte	0x7e
 635 02b3 0B       		.byte	0xb
 636 02b4 F40E0000 		.long	0xef4
 637 02b8 06       		.uleb128 0x6
 638 02b9 07       		.byte	0x7
 639 02ba 7F       		.byte	0x7f
 640 02bb 0B       		.byte	0xb
 641 02bc 0A0F0000 		.long	0xf0a
 642 02c0 06       		.uleb128 0x6
 643 02c1 07       		.byte	0x7
 644 02c2 83       		.byte	0x83
 645 02c3 0B       		.byte	0xb
 646 02c4 7E0F0000 		.long	0xf7e
 647 02c8 06       		.uleb128 0x6
 648 02c9 07       		.byte	0x7
 649 02ca 84       		.byte	0x84
 650 02cb 0B       		.byte	0xb
 651 02cc 980F0000 		.long	0xf98
 652 02d0 06       		.uleb128 0x6
 653 02d1 07       		.byte	0x7
 654 02d2 85       		.byte	0x85
 655 02d3 0B       		.byte	0xb
 656 02d4 B70F0000 		.long	0xfb7
 657 02d8 06       		.uleb128 0x6
 658 02d9 07       		.byte	0x7
 659 02da 86       		.byte	0x86
 660 02db 0B       		.byte	0xb
 661 02dc CD0F0000 		.long	0xfcd
 662 02e0 06       		.uleb128 0x6
 663 02e1 07       		.byte	0x7
 664 02e2 87       		.byte	0x87
 665 02e3 0B       		.byte	0xb
 666 02e4 3F100000 		.long	0x103f
 667 02e8 06       		.uleb128 0x6
 668 02e9 07       		.byte	0x7
 669 02ea 88       		.byte	0x88
 670 02eb 0B       		.byte	0xb
 671 02ec 5A100000 		.long	0x105a
 672 02f0 06       		.uleb128 0x6
 673 02f1 07       		.byte	0x7
 674 02f2 89       		.byte	0x89
 675 02f3 0B       		.byte	0xb
 676 02f4 84100000 		.long	0x1084
 677 02f8 06       		.uleb128 0x6
 678 02f9 07       		.byte	0x7
 679 02fa 8A       		.byte	0x8a
 680 02fb 0B       		.byte	0xb
 681 02fc B6100000 		.long	0x10b6
 682 0300 06       		.uleb128 0x6
 683 0301 07       		.byte	0x7
 684 0302 8B       		.byte	0x8b
 685 0303 0B       		.byte	0xb
 686 0304 E7100000 		.long	0x10e7
 687 0308 06       		.uleb128 0x6
 688 0309 07       		.byte	0x7
 689 030a 8D       		.byte	0x8d
 690 030b 0B       		.byte	0xb
 691 030c F8100000 		.long	0x10f8
 692 0310 06       		.uleb128 0x6
 693 0311 07       		.byte	0x7
 694 0312 8F       		.byte	0x8f
 695 0313 0B       		.byte	0xb
 696 0314 12110000 		.long	0x1112
 697 0318 06       		.uleb128 0x6
 698 0319 07       		.byte	0x7
 699 031a 90       		.byte	0x90
 700 031b 0B       		.byte	0xb
 701 031c 31110000 		.long	0x1131
 702 0320 06       		.uleb128 0x6
 703 0321 07       		.byte	0x7
 704 0322 91       		.byte	0x91
 705 0323 0B       		.byte	0xb
 706 0324 70110000 		.long	0x1170
 707 0328 06       		.uleb128 0x6
 708 0329 07       		.byte	0x7
 709 032a 92       		.byte	0x92
 710 032b 0B       		.byte	0xb
 711 032c A0110000 		.long	0x11a0
 712 0330 06       		.uleb128 0x6
 713 0331 07       		.byte	0x7
 714 0332 B9       		.byte	0xb9
 715 0333 16       		.byte	0x16
 716 0334 D9110000 		.long	0x11d9
 717 0338 06       		.uleb128 0x6
 718 0339 07       		.byte	0x7
 719 033a BA       		.byte	0xba
 720 033b 16       		.byte	0x16
 721 033c 13120000 		.long	0x1213
 722 0340 06       		.uleb128 0x6
 723 0341 07       		.byte	0x7
 724 0342 BB       		.byte	0xbb
 725 0343 16       		.byte	0x16
 726 0344 50120000 		.long	0x1250
 727 0348 06       		.uleb128 0x6
 728 0349 07       		.byte	0x7
 729 034a BC       		.byte	0xbc
 730 034b 16       		.byte	0x16
 731 034c 7E120000 		.long	0x127e
 732 0350 06       		.uleb128 0x6
 733 0351 07       		.byte	0x7
 734 0352 BD       		.byte	0xbd
 735 0353 16       		.byte	0x16
 736 0354 BF120000 		.long	0x12bf
 737 0358 0B       		.uleb128 0xb
 738 0359 6D61783C 		.ascii "max<int>\0"
 738      696E743E 
 738      00
 739 0362 03       		.byte	0x3
 740 0363 DB       		.byte	0xdb
 741 0364 05       		.byte	0x5
 742 0365 5F5A5374 		.ascii "_ZSt3maxIiERKT_S2_S2_\0"
 742      336D6178 
 742      49694552 
 742      4B545F53 
 742      325F5332 
 743 037b 6E130000 		.long	0x136e
 744 037f 0C       		.uleb128 0xc
 745 0380 5F547000 		.ascii "_Tp\0"
 746 0384 69050000 		.long	0x569
 747 0388 0D       		.uleb128 0xd
 748 0389 6E130000 		.long	0x136e
 749 038d 0D       		.uleb128 0xd
 750 038e 6E130000 		.long	0x136e
 751 0392 00       		.byte	0
 752 0393 00       		.byte	0
 753 0394 0E       		.uleb128 0xe
 754 0395 5F5F676E 		.ascii "__gnu_cxx\0"
 754      755F6378 
 754      7800
 755 039f 05       		.byte	0x5
 756 03a0 0601     		.word	0x106
 757 03a2 0B       		.byte	0xb
 758 03a3 E7040000 		.long	0x4e7
 759 03a7 03       		.uleb128 0x3
 760 03a8 5F5F6378 		.ascii "__cxx11\0"
 760      78313100 
 761 03b0 05       		.byte	0x5
 762 03b1 0801     		.word	0x108
 763 03b3 41       		.byte	0x41
 764 03b4 04       		.uleb128 0x4
 765 03b5 05       		.byte	0x5
 766 03b6 0801     		.word	0x108
 767 03b8 41       		.byte	0x41
 768 03b9 A7030000 		.long	0x3a7
 769 03bd 05       		.uleb128 0x5
 770 03be 5F5F6F70 		.ascii "__ops\0"
 770      7300
 771 03c4 09       		.byte	0x9
 772 03c5 23       		.byte	0x23
 773 03c6 0B       		.byte	0xb
 774 03c7 06       		.uleb128 0x6
 775 03c8 04       		.byte	0x4
 776 03c9 C8       		.byte	0xc8
 777 03ca 0B       		.byte	0xb
 778 03cb 6D080000 		.long	0x86d
 779 03cf 06       		.uleb128 0x6
 780 03d0 04       		.byte	0x4
 781 03d1 D8       		.byte	0xd8
 782 03d2 0B       		.byte	0xb
 783 03d3 130B0000 		.long	0xb13
 784 03d7 06       		.uleb128 0x6
 785 03d8 04       		.byte	0x4
 786 03d9 E3       		.byte	0xe3
 787 03da 0B       		.byte	0xb
 788 03db 310B0000 		.long	0xb31
 789 03df 06       		.uleb128 0x6
 790 03e0 04       		.byte	0x4
 791 03e1 E4       		.byte	0xe4
 792 03e2 0B       		.byte	0xb
 793 03e3 4A0B0000 		.long	0xb4a
 794 03e7 06       		.uleb128 0x6
 795 03e8 04       		.byte	0x4
 796 03e9 E5       		.byte	0xe5
 797 03ea 0B       		.byte	0xb
 798 03eb 6F0B0000 		.long	0xb6f
 799 03ef 06       		.uleb128 0x6
 800 03f0 04       		.byte	0x4
 801 03f1 E7       		.byte	0xe7
 802 03f2 0B       		.byte	0xb
 803 03f3 950B0000 		.long	0xb95
 804 03f7 06       		.uleb128 0x6
 805 03f8 04       		.byte	0x4
 806 03f9 E8       		.byte	0xe8
 807 03fa 0B       		.byte	0xb
 808 03fb B40B0000 		.long	0xbb4
 809 03ff 0F       		.uleb128 0xf
 810 0400 64697600 		.ascii "div\0"
 811 0404 04       		.byte	0x4
 812 0405 D5       		.byte	0xd5
 813 0406 03       		.byte	0x3
 814 0407 5F5A4E39 		.ascii "_ZN9__gnu_cxx3divExx\0"
 814      5F5F676E 
 814      755F6378 
 814      78336469 
 814      76457878 
 815 041c 6D080000 		.long	0x86d
 816 0420 2F040000 		.long	0x42f
 817 0424 0D       		.uleb128 0xd
 818 0425 81050000 		.long	0x581
 819 0429 0D       		.uleb128 0xd
 820 042a 81050000 		.long	0x581
 821 042e 00       		.byte	0
 822 042f 06       		.uleb128 0x6
 823 0430 0A       		.byte	0xa
 824 0431 2C       		.byte	0x2c
 825 0432 0E       		.byte	0xe
 826 0433 E7010000 		.long	0x1e7
 827 0437 06       		.uleb128 0x6
 828 0438 0A       		.byte	0xa
 829 0439 2D       		.byte	0x2d
 830 043a 0E       		.byte	0xe
 831 043b F6010000 		.long	0x1f6
 832 043f 10       		.uleb128 0x10
 833 0440 5F5F6E75 		.ascii "__numeric_traits_integer<long long int>\0"
 833      6D657269 
 833      635F7472 
 833      61697473 
 833      5F696E74 
 834 0468 01       		.byte	0x1
 835 0469 0B       		.byte	0xb
 836 046a 37       		.byte	0x37
 837 046b 0C       		.byte	0xc
 838 046c BE040000 		.long	0x4be
 839 0470 11       		.uleb128 0x11
 840 0471 5F5F6D69 		.ascii "__min\0"
 840      6E00
 841 0477 0B       		.byte	0xb
 842 0478 3A       		.byte	0x3a
 843 0479 1B       		.byte	0x1b
 844 047a 92050000 		.long	0x592
 845 047e 11       		.uleb128 0x11
 846 047f 5F5F6D61 		.ascii "__max\0"
 846      7800
 847 0485 0B       		.byte	0xb
 848 0486 3B       		.byte	0x3b
 849 0487 1B       		.byte	0x1b
 850 0488 92050000 		.long	0x592
 851 048c 11       		.uleb128 0x11
 852 048d 5F5F6973 		.ascii "__is_signed\0"
 852      5F736967 
 852      6E656400 
 853 0499 0B       		.byte	0xb
 854 049a 3F       		.byte	0x3f
 855 049b 19       		.byte	0x19
 856 049c DC0B0000 		.long	0xbdc
 857 04a0 11       		.uleb128 0x11
 858 04a1 5F5F6469 		.ascii "__digits\0"
 858      67697473 
 858      00
 859 04aa 0B       		.byte	0xb
 860 04ab 40       		.byte	0x40
 861 04ac 18       		.byte	0x18
 862 04ad 70050000 		.long	0x570
 863 04b1 0C       		.uleb128 0xc
 864 04b2 5F56616C 		.ascii "_Value\0"
 864      756500
 865 04b9 81050000 		.long	0x581
 866 04bd 00       		.byte	0
 867 04be 06       		.uleb128 0x6
 868 04bf 07       		.byte	0x7
 869 04c0 AF       		.byte	0xaf
 870 04c1 0B       		.byte	0xb
 871 04c2 D9110000 		.long	0x11d9
 872 04c6 06       		.uleb128 0x6
 873 04c7 07       		.byte	0x7
 874 04c8 B0       		.byte	0xb0
 875 04c9 0B       		.byte	0xb
 876 04ca 13120000 		.long	0x1213
 877 04ce 06       		.uleb128 0x6
 878 04cf 07       		.byte	0x7
 879 04d0 B1       		.byte	0xb1
 880 04d1 0B       		.byte	0xb
 881 04d2 50120000 		.long	0x1250
 882 04d6 06       		.uleb128 0x6
 883 04d7 07       		.byte	0x7
 884 04d8 B2       		.byte	0xb2
 885 04d9 0B       		.byte	0xb
 886 04da 7E120000 		.long	0x127e
 887 04de 06       		.uleb128 0x6
 888 04df 07       		.byte	0x7
 889 04e0 B3       		.byte	0xb3
 890 04e1 0B       		.byte	0xb
 891 04e2 BF120000 		.long	0x12bf
 892 04e6 00       		.byte	0
 893 04e7 12       		.uleb128 0x12
 894 04e8 04       		.byte	0x4
 895 04e9 07       		.byte	0x7
 896 04ea 756E7369 		.ascii "unsigned int\0"
 896      676E6564 
 896      20696E74 
 896      00
 897 04f7 12       		.uleb128 0x12
 898 04f8 01       		.byte	0x1
 899 04f9 08       		.byte	0x8
 900 04fa 756E7369 		.ascii "unsigned char\0"
 900      676E6564 
 900      20636861 
 900      7200
 901 0508 12       		.uleb128 0x12
 902 0509 02       		.byte	0x2
 903 050a 07       		.byte	0x7
 904 050b 73686F72 		.ascii "short unsigned int\0"
 904      7420756E 
 904      7369676E 
 904      65642069 
 904      6E7400
 905 051e 12       		.uleb128 0x12
 906 051f 04       		.byte	0x4
 907 0520 07       		.byte	0x7
 908 0521 6C6F6E67 		.ascii "long unsigned int\0"
 908      20756E73 
 908      69676E65 
 908      6420696E 
 908      7400
 909 0533 12       		.uleb128 0x12
 910 0534 08       		.byte	0x8
 911 0535 07       		.byte	0x7
 912 0536 6C6F6E67 		.ascii "long long unsigned int\0"
 912      206C6F6E 
 912      6720756E 
 912      7369676E 
 912      65642069 
 913 054d 12       		.uleb128 0x12
 914 054e 01       		.byte	0x1
 915 054f 06       		.byte	0x6
 916 0550 7369676E 		.ascii "signed char\0"
 916      65642063 
 916      68617200 
 917 055c 12       		.uleb128 0x12
 918 055d 02       		.byte	0x2
 919 055e 05       		.byte	0x5
 920 055f 73686F72 		.ascii "short int\0"
 920      7420696E 
 920      7400
 921 0569 12       		.uleb128 0x12
 922 056a 04       		.byte	0x4
 923 056b 05       		.byte	0x5
 924 056c 696E7400 		.ascii "int\0"
 925 0570 08       		.uleb128 0x8
 926 0571 69050000 		.long	0x569
 927 0575 12       		.uleb128 0x12
 928 0576 04       		.byte	0x4
 929 0577 05       		.byte	0x5
 930 0578 6C6F6E67 		.ascii "long int\0"
 930      20696E74 
 930      00
 931 0581 12       		.uleb128 0x12
 932 0582 08       		.byte	0x8
 933 0583 05       		.byte	0x5
 934 0584 6C6F6E67 		.ascii "long long int\0"
 934      206C6F6E 
 934      6720696E 
 934      7400
 935 0592 08       		.uleb128 0x8
 936 0593 81050000 		.long	0x581
 937 0597 12       		.uleb128 0x12
 938 0598 10       		.byte	0x10
 939 0599 04       		.byte	0x4
 940 059a 6C6F6E67 		.ascii "long double\0"
 940      20646F75 
 940      626C6500 
 941 05a6 12       		.uleb128 0x12
 942 05a7 08       		.byte	0x8
 943 05a8 04       		.byte	0x4
 944 05a9 646F7562 		.ascii "double\0"
 944      6C6500
 945 05b0 12       		.uleb128 0x12
 946 05b1 04       		.byte	0x4
 947 05b2 04       		.byte	0x4
 948 05b3 666C6F61 		.ascii "float\0"
 948      7400
 949 05b9 13       		.uleb128 0x13
 950 05ba 5F5F676E 		.ascii "__gnu_debug\0"
 950      755F6465 
 950      62756700 
 951 05c6 08       		.byte	0x8
 952 05c7 38       		.byte	0x38
 953 05c8 0B       		.byte	0xb
 954 05c9 D6050000 		.long	0x5d6
 955 05cd 14       		.uleb128 0x14
 956 05ce 08       		.byte	0x8
 957 05cf 3A       		.byte	0x3a
 958 05d0 18       		.byte	0x18
 959 05d1 A8000000 		.long	0xa8
 960 05d5 00       		.byte	0
 961 05d6 15       		.uleb128 0x15
 962 05d7 08       		.byte	0x8
 963 05d8 5F5F6275 		.ascii "__builtin_va_list\0"
 963      696C7469 
 963      6E5F7661 
 963      5F6C6973 
 963      7400
 964 05ea EE050000 		.long	0x5ee
 965 05ee 12       		.uleb128 0x12
 966 05ef 01       		.byte	0x1
 967 05f0 06       		.byte	0x6
 968 05f1 63686172 		.ascii "char\0"
 968      00
 969 05f6 08       		.uleb128 0x8
 970 05f7 EE050000 		.long	0x5ee
 971 05fb 0A       		.uleb128 0xa
 972 05fc 73697A65 		.ascii "size_t\0"
 972      5F7400
 973 0603 0C       		.byte	0xc
 974 0604 23       		.byte	0x23
 975 0605 2C       		.byte	0x2c
 976 0606 33050000 		.long	0x533
 977 060a 16       		.uleb128 0x16
 978 060b 08       		.byte	0x8
 979 060c EE050000 		.long	0x5ee
 980 0610 16       		.uleb128 0x16
 981 0611 08       		.byte	0x8
 982 0612 16060000 		.long	0x616
 983 0616 12       		.uleb128 0x12
 984 0617 02       		.byte	0x2
 985 0618 07       		.byte	0x7
 986 0619 77636861 		.ascii "wchar_t\0"
 986      725F7400 
 987 0621 08       		.uleb128 0x8
 988 0622 16060000 		.long	0x616
 989 0626 16       		.uleb128 0x16
 990 0627 08       		.byte	0x8
 991 0628 69050000 		.long	0x569
 992 062c 10       		.uleb128 0x10
 993 062d 5F646976 		.ascii "_div_t\0"
 993      5F7400
 994 0634 08       		.byte	0x8
 995 0635 0D       		.byte	0xd
 996 0636 3B       		.byte	0x3b
 997 0637 12       		.byte	0x12
 998 0638 58060000 		.long	0x658
 999 063c 17       		.uleb128 0x17
 1000 063d 71756F74 		.ascii "quot\0"
 1000      00
 1001 0642 0D       		.byte	0xd
 1002 0643 3C       		.byte	0x3c
 1003 0644 09       		.byte	0x9
 1004 0645 69050000 		.long	0x569
 1005 0649 00       		.byte	0
 1006 064a 17       		.uleb128 0x17
 1007 064b 72656D00 		.ascii "rem\0"
 1008 064f 0D       		.byte	0xd
 1009 0650 3D       		.byte	0x3d
 1010 0651 09       		.byte	0x9
 1011 0652 69050000 		.long	0x569
 1012 0656 04       		.byte	0x4
 1013 0657 00       		.byte	0
 1014 0658 0A       		.uleb128 0xa
 1015 0659 6469765F 		.ascii "div_t\0"
 1015      7400
 1016 065f 0D       		.byte	0xd
 1017 0660 3E       		.byte	0x3e
 1018 0661 05       		.byte	0x5
 1019 0662 2C060000 		.long	0x62c
 1020 0666 10       		.uleb128 0x10
 1021 0667 5F6C6469 		.ascii "_ldiv_t\0"
 1021      765F7400 
 1022 066f 08       		.byte	0x8
 1023 0670 0D       		.byte	0xd
 1024 0671 40       		.byte	0x40
 1025 0672 12       		.byte	0x12
 1026 0673 93060000 		.long	0x693
 1027 0677 17       		.uleb128 0x17
 1028 0678 71756F74 		.ascii "quot\0"
 1028      00
 1029 067d 0D       		.byte	0xd
 1030 067e 41       		.byte	0x41
 1031 067f 0A       		.byte	0xa
 1032 0680 75050000 		.long	0x575
 1033 0684 00       		.byte	0
 1034 0685 17       		.uleb128 0x17
 1035 0686 72656D00 		.ascii "rem\0"
 1036 068a 0D       		.byte	0xd
 1037 068b 42       		.byte	0x42
 1038 068c 0A       		.byte	0xa
 1039 068d 75050000 		.long	0x575
 1040 0691 04       		.byte	0x4
 1041 0692 00       		.byte	0
 1042 0693 0A       		.uleb128 0xa
 1043 0694 6C646976 		.ascii "ldiv_t\0"
 1043      5F7400
 1044 069b 0D       		.byte	0xd
 1045 069c 43       		.byte	0x43
 1046 069d 05       		.byte	0x5
 1047 069e 66060000 		.long	0x666
 1048 06a2 18       		.uleb128 0x18
 1049 06a3 5F5F696D 		.ascii "__imp___mb_cur_max\0"
 1049      705F5F5F 
 1049      6D625F63 
 1049      75725F6D 
 1049      617800
 1050 06b6 0D       		.byte	0xd
 1051 06b7 73       		.byte	0x73
 1052 06b8 10       		.byte	0x10
 1053 06b9 26060000 		.long	0x626
 1054 06bd 16       		.uleb128 0x16
 1055 06be 08       		.byte	0x8
 1056 06bf C3060000 		.long	0x6c3
 1057 06c3 19       		.uleb128 0x19
 1058 06c4 16       		.uleb128 0x16
 1059 06c5 08       		.byte	0x8
 1060 06c6 21060000 		.long	0x621
 1061 06ca 1A       		.uleb128 0x1a
 1062 06cb 0A060000 		.long	0x60a
 1063 06cf DA060000 		.long	0x6da
 1064 06d3 1B       		.uleb128 0x1b
 1065 06d4 33050000 		.long	0x533
 1066 06d8 00       		.byte	0
 1067 06d9 00       		.byte	0
 1068 06da 18       		.uleb128 0x18
 1069 06db 5F737973 		.ascii "_sys_errlist\0"
 1069      5F657272 
 1069      6C697374 
 1069      00
 1070 06e8 0D       		.byte	0xd
 1071 06e9 AC       		.byte	0xac
 1072 06ea 26       		.byte	0x26
 1073 06eb CA060000 		.long	0x6ca
 1074 06ef 18       		.uleb128 0x18
 1075 06f0 5F737973 		.ascii "_sys_nerr\0"
 1075      5F6E6572 
 1075      7200
 1076 06fa 0D       		.byte	0xd
 1077 06fb AD       		.byte	0xad
 1078 06fc 24       		.byte	0x24
 1079 06fd 69050000 		.long	0x569
 1080 0701 1C       		.uleb128 0x1c
 1081 0702 5F5F696D 		.ascii "__imp___argc\0"
 1081      705F5F5F 
 1081      61726763 
 1081      00
 1082 070f 0D       		.byte	0xd
 1083 0710 1901     		.word	0x119
 1084 0712 10       		.byte	0x10
 1085 0713 26060000 		.long	0x626
 1086 0717 1C       		.uleb128 0x1c
 1087 0718 5F5F696D 		.ascii "__imp___argv\0"
 1087      705F5F5F 
 1087      61726776 
 1087      00
 1088 0725 0D       		.byte	0xd
 1089 0726 1D01     		.word	0x11d
 1090 0728 13       		.byte	0x13
 1091 0729 2D070000 		.long	0x72d
 1092 072d 16       		.uleb128 0x16
 1093 072e 08       		.byte	0x8
 1094 072f 33070000 		.long	0x733
 1095 0733 16       		.uleb128 0x16
 1096 0734 08       		.byte	0x8
 1097 0735 0A060000 		.long	0x60a
 1098 0739 1C       		.uleb128 0x1c
 1099 073a 5F5F696D 		.ascii "__imp___wargv\0"
 1099      705F5F5F 
 1099      77617267 
 1099      7600
 1100 0748 0D       		.byte	0xd
 1101 0749 2101     		.word	0x121
 1102 074b 16       		.byte	0x16
 1103 074c 50070000 		.long	0x750
 1104 0750 16       		.uleb128 0x16
 1105 0751 08       		.byte	0x8
 1106 0752 56070000 		.long	0x756
 1107 0756 16       		.uleb128 0x16
 1108 0757 08       		.byte	0x8
 1109 0758 10060000 		.long	0x610
 1110 075c 1C       		.uleb128 0x1c
 1111 075d 5F5F696D 		.ascii "__imp__environ\0"
 1111      705F5F65 
 1111      6E766972 
 1111      6F6E00
 1112 076c 0D       		.byte	0xd
 1113 076d 2701     		.word	0x127
 1114 076f 13       		.byte	0x13
 1115 0770 2D070000 		.long	0x72d
 1116 0774 1C       		.uleb128 0x1c
 1117 0775 5F5F696D 		.ascii "__imp__wenviron\0"
 1117      705F5F77 
 1117      656E7669 
 1117      726F6E00 
 1118 0785 0D       		.byte	0xd
 1119 0786 2C01     		.word	0x12c
 1120 0788 16       		.byte	0x16
 1121 0789 50070000 		.long	0x750
 1122 078d 1C       		.uleb128 0x1c
 1123 078e 5F5F696D 		.ascii "__imp__pgmptr\0"
 1123      705F5F70 
 1123      676D7074 
 1123      7200
 1124 079c 0D       		.byte	0xd
 1125 079d 3201     		.word	0x132
 1126 079f 12       		.byte	0x12
 1127 07a0 33070000 		.long	0x733
 1128 07a4 1C       		.uleb128 0x1c
 1129 07a5 5F5F696D 		.ascii "__imp__wpgmptr\0"
 1129      705F5F77 
 1129      70676D70 
 1129      747200
 1130 07b4 0D       		.byte	0xd
 1131 07b5 3701     		.word	0x137
 1132 07b7 15       		.byte	0x15
 1133 07b8 56070000 		.long	0x756
 1134 07bc 1C       		.uleb128 0x1c
 1135 07bd 5F5F696D 		.ascii "__imp__osplatform\0"
 1135      705F5F6F 
 1135      73706C61 
 1135      74666F72 
 1135      6D00
 1136 07cf 0D       		.byte	0xd
 1137 07d0 3C01     		.word	0x13c
 1138 07d2 19       		.byte	0x19
 1139 07d3 D7070000 		.long	0x7d7
 1140 07d7 16       		.uleb128 0x16
 1141 07d8 08       		.byte	0x8
 1142 07d9 E7040000 		.long	0x4e7
 1143 07dd 1C       		.uleb128 0x1c
 1144 07de 5F5F696D 		.ascii "__imp__osver\0"
 1144      705F5F6F 
 1144      73766572 
 1144      00
 1145 07eb 0D       		.byte	0xd
 1146 07ec 4101     		.word	0x141
 1147 07ee 19       		.byte	0x19
 1148 07ef D7070000 		.long	0x7d7
 1149 07f3 1C       		.uleb128 0x1c
 1150 07f4 5F5F696D 		.ascii "__imp__winver\0"
 1150      705F5F77 
 1150      696E7665 
 1150      7200
 1151 0802 0D       		.byte	0xd
 1152 0803 4601     		.word	0x146
 1153 0805 19       		.byte	0x19
 1154 0806 D7070000 		.long	0x7d7
 1155 080a 1C       		.uleb128 0x1c
 1156 080b 5F5F696D 		.ascii "__imp__winmajor\0"
 1156      705F5F77 
 1156      696E6D61 
 1156      6A6F7200 
 1157 081b 0D       		.byte	0xd
 1158 081c 4B01     		.word	0x14b
 1159 081e 19       		.byte	0x19
 1160 081f D7070000 		.long	0x7d7
 1161 0823 1C       		.uleb128 0x1c
 1162 0824 5F5F696D 		.ascii "__imp__winminor\0"
 1162      705F5F77 
 1162      696E6D69 
 1162      6E6F7200 
 1163 0834 0D       		.byte	0xd
 1164 0835 5001     		.word	0x150
 1165 0837 19       		.byte	0x19
 1166 0838 D7070000 		.long	0x7d7
 1167 083c 1D       		.uleb128 0x1d
 1168 083d 10       		.byte	0x10
 1169 083e 0D       		.byte	0xd
 1170 083f BB02     		.word	0x2bb
 1171 0841 12       		.byte	0x12
 1172 0842 376C6C64 		.ascii "7lldiv_t\0"
 1172      69765F74 
 1172      00
 1173 084b 6D080000 		.long	0x86d
 1174 084f 1E       		.uleb128 0x1e
 1175 0850 71756F74 		.ascii "quot\0"
 1175      00
 1176 0855 0D       		.byte	0xd
 1177 0856 BB02     		.word	0x2bb
 1178 0858 30       		.byte	0x30
 1179 0859 81050000 		.long	0x581
 1180 085d 00       		.byte	0
 1181 085e 1E       		.uleb128 0x1e
 1182 085f 72656D00 		.ascii "rem\0"
 1183 0863 0D       		.byte	0xd
 1184 0864 BB02     		.word	0x2bb
 1185 0866 36       		.byte	0x36
 1186 0867 81050000 		.long	0x581
 1187 086b 08       		.byte	0x8
 1188 086c 00       		.byte	0
 1189 086d 1F       		.uleb128 0x1f
 1190 086e 6C6C6469 		.ascii "lldiv_t\0"
 1190      765F7400 
 1191 0876 0D       		.byte	0xd
 1192 0877 BB02     		.word	0x2bb
 1193 0879 3D       		.byte	0x3d
 1194 087a 3C080000 		.long	0x83c
 1195 087e 18       		.uleb128 0x18
 1196 087f 5F616D62 		.ascii "_amblksiz\0"
 1196      6C6B7369 
 1196      7A00
 1197 0889 0E       		.byte	0xe
 1198 088a 35       		.byte	0x35
 1199 088b 17       		.byte	0x17
 1200 088c E7040000 		.long	0x4e7
 1201 0890 20       		.uleb128 0x20
 1202 0891 61746578 		.ascii "atexit\0"
 1202      697400
 1203 0898 0D       		.byte	0xd
 1204 0899 8A01     		.word	0x18a
 1205 089b 0F       		.byte	0xf
 1206 089c 69050000 		.long	0x569
 1207 08a0 AA080000 		.long	0x8aa
 1208 08a4 0D       		.uleb128 0xd
 1209 08a5 BD060000 		.long	0x6bd
 1210 08a9 00       		.byte	0
 1211 08aa 20       		.uleb128 0x20
 1212 08ab 61746F66 		.ascii "atof\0"
 1212      00
 1213 08b0 0D       		.byte	0xd
 1214 08b1 8D01     		.word	0x18d
 1215 08b3 12       		.byte	0x12
 1216 08b4 A6050000 		.long	0x5a6
 1217 08b8 C2080000 		.long	0x8c2
 1218 08bc 0D       		.uleb128 0xd
 1219 08bd C2080000 		.long	0x8c2
 1220 08c1 00       		.byte	0
 1221 08c2 16       		.uleb128 0x16
 1222 08c3 08       		.byte	0x8
 1223 08c4 F6050000 		.long	0x5f6
 1224 08c8 20       		.uleb128 0x20
 1225 08c9 61746F69 		.ascii "atoi\0"
 1225      00
 1226 08ce 0D       		.byte	0xd
 1227 08cf 9001     		.word	0x190
 1228 08d1 0F       		.byte	0xf
 1229 08d2 69050000 		.long	0x569
 1230 08d6 E0080000 		.long	0x8e0
 1231 08da 0D       		.uleb128 0xd
 1232 08db C2080000 		.long	0x8c2
 1233 08df 00       		.byte	0
 1234 08e0 20       		.uleb128 0x20
 1235 08e1 61746F6C 		.ascii "atol\0"
 1235      00
 1236 08e6 0D       		.byte	0xd
 1237 08e7 9201     		.word	0x192
 1238 08e9 10       		.byte	0x10
 1239 08ea 75050000 		.long	0x575
 1240 08ee F8080000 		.long	0x8f8
 1241 08f2 0D       		.uleb128 0xd
 1242 08f3 C2080000 		.long	0x8c2
 1243 08f7 00       		.byte	0
 1244 08f8 20       		.uleb128 0x20
 1245 08f9 62736561 		.ascii "bsearch\0"
 1245      72636800 
 1246 0901 0D       		.byte	0xd
 1247 0902 9601     		.word	0x196
 1248 0904 11       		.byte	0x11
 1249 0905 27090000 		.long	0x927
 1250 0909 27090000 		.long	0x927
 1251 090d 0D       		.uleb128 0xd
 1252 090e 29090000 		.long	0x929
 1253 0912 0D       		.uleb128 0xd
 1254 0913 29090000 		.long	0x929
 1255 0917 0D       		.uleb128 0xd
 1256 0918 FB050000 		.long	0x5fb
 1257 091c 0D       		.uleb128 0xd
 1258 091d FB050000 		.long	0x5fb
 1259 0921 0D       		.uleb128 0xd
 1260 0922 30090000 		.long	0x930
 1261 0926 00       		.byte	0
 1262 0927 21       		.uleb128 0x21
 1263 0928 08       		.byte	0x8
 1264 0929 16       		.uleb128 0x16
 1265 092a 08       		.byte	0x8
 1266 092b 2F090000 		.long	0x92f
 1267 092f 22       		.uleb128 0x22
 1268 0930 16       		.uleb128 0x16
 1269 0931 08       		.byte	0x8
 1270 0932 36090000 		.long	0x936
 1271 0936 23       		.uleb128 0x23
 1272 0937 69050000 		.long	0x569
 1273 093b 4A090000 		.long	0x94a
 1274 093f 0D       		.uleb128 0xd
 1275 0940 29090000 		.long	0x929
 1276 0944 0D       		.uleb128 0xd
 1277 0945 29090000 		.long	0x929
 1278 0949 00       		.byte	0
 1279 094a 20       		.uleb128 0x20
 1280 094b 64697600 		.ascii "div\0"
 1281 094f 0D       		.byte	0xd
 1282 0950 9C01     		.word	0x19c
 1283 0952 11       		.byte	0x11
 1284 0953 58060000 		.long	0x658
 1285 0957 66090000 		.long	0x966
 1286 095b 0D       		.uleb128 0xd
 1287 095c 69050000 		.long	0x569
 1288 0960 0D       		.uleb128 0xd
 1289 0961 69050000 		.long	0x569
 1290 0965 00       		.byte	0
 1291 0966 20       		.uleb128 0x20
 1292 0967 67657465 		.ascii "getenv\0"
 1292      6E7600
 1293 096e 0D       		.byte	0xd
 1294 096f 9D01     		.word	0x19d
 1295 0971 11       		.byte	0x11
 1296 0972 0A060000 		.long	0x60a
 1297 0976 80090000 		.long	0x980
 1298 097a 0D       		.uleb128 0xd
 1299 097b C2080000 		.long	0x8c2
 1300 097f 00       		.byte	0
 1301 0980 20       		.uleb128 0x20
 1302 0981 6C646976 		.ascii "ldiv\0"
 1302      00
 1303 0986 0D       		.byte	0xd
 1304 0987 A701     		.word	0x1a7
 1305 0989 12       		.byte	0x12
 1306 098a 93060000 		.long	0x693
 1307 098e 9D090000 		.long	0x99d
 1308 0992 0D       		.uleb128 0xd
 1309 0993 75050000 		.long	0x575
 1310 0997 0D       		.uleb128 0xd
 1311 0998 75050000 		.long	0x575
 1312 099c 00       		.byte	0
 1313 099d 20       		.uleb128 0x20
 1314 099e 6D626C65 		.ascii "mblen\0"
 1314      6E00
 1315 09a4 0D       		.byte	0xd
 1316 09a5 A901     		.word	0x1a9
 1317 09a7 0F       		.byte	0xf
 1318 09a8 69050000 		.long	0x569
 1319 09ac BB090000 		.long	0x9bb
 1320 09b0 0D       		.uleb128 0xd
 1321 09b1 C2080000 		.long	0x8c2
 1322 09b5 0D       		.uleb128 0xd
 1323 09b6 FB050000 		.long	0x5fb
 1324 09ba 00       		.byte	0
 1325 09bb 20       		.uleb128 0x20
 1326 09bc 6D627374 		.ascii "mbstowcs\0"
 1326      6F776373 
 1326      00
 1327 09c5 0D       		.byte	0xd
 1328 09c6 B101     		.word	0x1b1
 1329 09c8 12       		.byte	0x12
 1330 09c9 FB050000 		.long	0x5fb
 1331 09cd E1090000 		.long	0x9e1
 1332 09d1 0D       		.uleb128 0xd
 1333 09d2 10060000 		.long	0x610
 1334 09d6 0D       		.uleb128 0xd
 1335 09d7 C2080000 		.long	0x8c2
 1336 09db 0D       		.uleb128 0xd
 1337 09dc FB050000 		.long	0x5fb
 1338 09e0 00       		.byte	0
 1339 09e1 20       		.uleb128 0x20
 1340 09e2 6D62746F 		.ascii "mbtowc\0"
 1340      776300
 1341 09e9 0D       		.byte	0xd
 1342 09ea AF01     		.word	0x1af
 1343 09ec 0F       		.byte	0xf
 1344 09ed 69050000 		.long	0x569
 1345 09f1 050A0000 		.long	0xa05
 1346 09f5 0D       		.uleb128 0xd
 1347 09f6 10060000 		.long	0x610
 1348 09fa 0D       		.uleb128 0xd
 1349 09fb C2080000 		.long	0x8c2
 1350 09ff 0D       		.uleb128 0xd
 1351 0a00 FB050000 		.long	0x5fb
 1352 0a04 00       		.byte	0
 1353 0a05 24       		.uleb128 0x24
 1354 0a06 71736F72 		.ascii "qsort\0"
 1354      7400
 1355 0a0c 0D       		.byte	0xd
 1356 0a0d 9701     		.word	0x197
 1357 0a0f 10       		.byte	0x10
 1358 0a10 290A0000 		.long	0xa29
 1359 0a14 0D       		.uleb128 0xd
 1360 0a15 27090000 		.long	0x927
 1361 0a19 0D       		.uleb128 0xd
 1362 0a1a FB050000 		.long	0x5fb
 1363 0a1e 0D       		.uleb128 0xd
 1364 0a1f FB050000 		.long	0x5fb
 1365 0a23 0D       		.uleb128 0xd
 1366 0a24 30090000 		.long	0x930
 1367 0a28 00       		.byte	0
 1368 0a29 25       		.uleb128 0x25
 1369 0a2a 72616E64 		.ascii "rand\0"
 1369      00
 1370 0a2f 0D       		.byte	0xd
 1371 0a30 B401     		.word	0x1b4
 1372 0a32 0F       		.byte	0xf
 1373 0a33 69050000 		.long	0x569
 1374 0a37 24       		.uleb128 0x24
 1375 0a38 7372616E 		.ascii "srand\0"
 1375      6400
 1376 0a3e 0D       		.byte	0xd
 1377 0a3f B601     		.word	0x1b6
 1378 0a41 10       		.byte	0x10
 1379 0a42 4C0A0000 		.long	0xa4c
 1380 0a46 0D       		.uleb128 0xd
 1381 0a47 E7040000 		.long	0x4e7
 1382 0a4b 00       		.byte	0
 1383 0a4c 20       		.uleb128 0x20
 1384 0a4d 73747274 		.ascii "strtod\0"
 1384      6F6400
 1385 0a54 0D       		.byte	0xd
 1386 0a55 C201     		.word	0x1c2
 1387 0a57 20       		.byte	0x20
 1388 0a58 A6050000 		.long	0x5a6
 1389 0a5c 6B0A0000 		.long	0xa6b
 1390 0a60 0D       		.uleb128 0xd
 1391 0a61 C2080000 		.long	0x8c2
 1392 0a65 0D       		.uleb128 0xd
 1393 0a66 33070000 		.long	0x733
 1394 0a6a 00       		.byte	0
 1395 0a6b 20       		.uleb128 0x20
 1396 0a6c 73747274 		.ascii "strtol\0"
 1396      6F6C00
 1397 0a73 0D       		.byte	0xd
 1398 0a74 E501     		.word	0x1e5
 1399 0a76 10       		.byte	0x10
 1400 0a77 75050000 		.long	0x575
 1401 0a7b 8F0A0000 		.long	0xa8f
 1402 0a7f 0D       		.uleb128 0xd
 1403 0a80 C2080000 		.long	0x8c2
 1404 0a84 0D       		.uleb128 0xd
 1405 0a85 33070000 		.long	0x733
 1406 0a89 0D       		.uleb128 0xd
 1407 0a8a 69050000 		.long	0x569
 1408 0a8e 00       		.byte	0
 1409 0a8f 20       		.uleb128 0x20
 1410 0a90 73747274 		.ascii "strtoul\0"
 1410      6F756C00 
 1411 0a98 0D       		.byte	0xd
 1412 0a99 E701     		.word	0x1e7
 1413 0a9b 19       		.byte	0x19
 1414 0a9c 1E050000 		.long	0x51e
 1415 0aa0 B40A0000 		.long	0xab4
 1416 0aa4 0D       		.uleb128 0xd
 1417 0aa5 C2080000 		.long	0x8c2
 1418 0aa9 0D       		.uleb128 0xd
 1419 0aaa 33070000 		.long	0x733
 1420 0aae 0D       		.uleb128 0xd
 1421 0aaf 69050000 		.long	0x569
 1422 0ab3 00       		.byte	0
 1423 0ab4 20       		.uleb128 0x20
 1424 0ab5 73797374 		.ascii "system\0"
 1424      656D00
 1425 0abc 0D       		.byte	0xd
 1426 0abd EB01     		.word	0x1eb
 1427 0abf 0F       		.byte	0xf
 1428 0ac0 69050000 		.long	0x569
 1429 0ac4 CE0A0000 		.long	0xace
 1430 0ac8 0D       		.uleb128 0xd
 1431 0ac9 C2080000 		.long	0x8c2
 1432 0acd 00       		.byte	0
 1433 0ace 20       		.uleb128 0x20
 1434 0acf 77637374 		.ascii "wcstombs\0"
 1434      6F6D6273 
 1434      00
 1435 0ad8 0D       		.byte	0xd
 1436 0ad9 F001     		.word	0x1f0
 1437 0adb 12       		.byte	0x12
 1438 0adc FB050000 		.long	0x5fb
 1439 0ae0 F40A0000 		.long	0xaf4
 1440 0ae4 0D       		.uleb128 0xd
 1441 0ae5 0A060000 		.long	0x60a
 1442 0ae9 0D       		.uleb128 0xd
 1443 0aea C4060000 		.long	0x6c4
 1444 0aee 0D       		.uleb128 0xd
 1445 0aef FB050000 		.long	0x5fb
 1446 0af3 00       		.byte	0
 1447 0af4 20       		.uleb128 0x20
 1448 0af5 7763746F 		.ascii "wctomb\0"
 1448      6D6200
 1449 0afc 0D       		.byte	0xd
 1450 0afd EE01     		.word	0x1ee
 1451 0aff 0F       		.byte	0xf
 1452 0b00 69050000 		.long	0x569
 1453 0b04 130B0000 		.long	0xb13
 1454 0b08 0D       		.uleb128 0xd
 1455 0b09 0A060000 		.long	0x60a
 1456 0b0d 0D       		.uleb128 0xd
 1457 0b0e 16060000 		.long	0x616
 1458 0b12 00       		.byte	0
 1459 0b13 20       		.uleb128 0x20
 1460 0b14 6C6C6469 		.ascii "lldiv\0"
 1460      7600
 1461 0b1a 0D       		.byte	0xd
 1462 0b1b BD02     		.word	0x2bd
 1463 0b1d 25       		.byte	0x25
 1464 0b1e 6D080000 		.long	0x86d
 1465 0b22 310B0000 		.long	0xb31
 1466 0b26 0D       		.uleb128 0xd
 1467 0b27 81050000 		.long	0x581
 1468 0b2b 0D       		.uleb128 0xd
 1469 0b2c 81050000 		.long	0x581
 1470 0b30 00       		.byte	0
 1471 0b31 20       		.uleb128 0x20
 1472 0b32 61746F6C 		.ascii "atoll\0"
 1472      6C00
 1473 0b38 0D       		.byte	0xd
 1474 0b39 C802     		.word	0x2c8
 1475 0b3b 28       		.byte	0x28
 1476 0b3c 81050000 		.long	0x581
 1477 0b40 4A0B0000 		.long	0xb4a
 1478 0b44 0D       		.uleb128 0xd
 1479 0b45 C2080000 		.long	0x8c2
 1480 0b49 00       		.byte	0
 1481 0b4a 20       		.uleb128 0x20
 1482 0b4b 73747274 		.ascii "strtoll\0"
 1482      6F6C6C00 
 1483 0b53 0D       		.byte	0xd
 1484 0b54 C402     		.word	0x2c4
 1485 0b56 28       		.byte	0x28
 1486 0b57 81050000 		.long	0x581
 1487 0b5b 6F0B0000 		.long	0xb6f
 1488 0b5f 0D       		.uleb128 0xd
 1489 0b60 C2080000 		.long	0x8c2
 1490 0b64 0D       		.uleb128 0xd
 1491 0b65 33070000 		.long	0x733
 1492 0b69 0D       		.uleb128 0xd
 1493 0b6a 69050000 		.long	0x569
 1494 0b6e 00       		.byte	0
 1495 0b6f 20       		.uleb128 0x20
 1496 0b70 73747274 		.ascii "strtoull\0"
 1496      6F756C6C 
 1496      00
 1497 0b79 0D       		.byte	0xd
 1498 0b7a C502     		.word	0x2c5
 1499 0b7c 31       		.byte	0x31
 1500 0b7d 33050000 		.long	0x533
 1501 0b81 950B0000 		.long	0xb95
 1502 0b85 0D       		.uleb128 0xd
 1503 0b86 C2080000 		.long	0x8c2
 1504 0b8a 0D       		.uleb128 0xd
 1505 0b8b 33070000 		.long	0x733
 1506 0b8f 0D       		.uleb128 0xd
 1507 0b90 69050000 		.long	0x569
 1508 0b94 00       		.byte	0
 1509 0b95 20       		.uleb128 0x20
 1510 0b96 73747274 		.ascii "strtof\0"
 1510      6F6600
 1511 0b9d 0D       		.byte	0xd
 1512 0b9e C901     		.word	0x1c9
 1513 0ba0 1F       		.byte	0x1f
 1514 0ba1 B0050000 		.long	0x5b0
 1515 0ba5 B40B0000 		.long	0xbb4
 1516 0ba9 0D       		.uleb128 0xd
 1517 0baa C2080000 		.long	0x8c2
 1518 0bae 0D       		.uleb128 0xd
 1519 0baf 33070000 		.long	0x733
 1520 0bb3 00       		.byte	0
 1521 0bb4 20       		.uleb128 0x20
 1522 0bb5 73747274 		.ascii "strtold\0"
 1522      6F6C6400 
 1523 0bbd 0D       		.byte	0xd
 1524 0bbe D401     		.word	0x1d4
 1525 0bc0 27       		.byte	0x27
 1526 0bc1 97050000 		.long	0x597
 1527 0bc5 D40B0000 		.long	0xbd4
 1528 0bc9 0D       		.uleb128 0xd
 1529 0bca C2080000 		.long	0x8c2
 1530 0bce 0D       		.uleb128 0xd
 1531 0bcf 33070000 		.long	0x733
 1532 0bd3 00       		.byte	0
 1533 0bd4 12       		.uleb128 0x12
 1534 0bd5 01       		.byte	0x1
 1535 0bd6 02       		.byte	0x2
 1536 0bd7 626F6F6C 		.ascii "bool\0"
 1536      00
 1537 0bdc 08       		.uleb128 0x8
 1538 0bdd D40B0000 		.long	0xbd4
 1539 0be1 10       		.uleb128 0x10
 1540 0be2 5F696F62 		.ascii "_iobuf\0"
 1540      756600
 1541 0be9 30       		.byte	0x30
 1542 0bea 01       		.byte	0x1
 1543 0beb 1A       		.byte	0x1a
 1544 0bec 0A       		.byte	0xa
 1545 0bed 710C0000 		.long	0xc71
 1546 0bf1 17       		.uleb128 0x17
 1547 0bf2 5F707472 		.ascii "_ptr\0"
 1547      00
 1548 0bf7 01       		.byte	0x1
 1549 0bf8 1B       		.byte	0x1b
 1550 0bf9 0B       		.byte	0xb
 1551 0bfa 0A060000 		.long	0x60a
 1552 0bfe 00       		.byte	0
 1553 0bff 17       		.uleb128 0x17
 1554 0c00 5F636E74 		.ascii "_cnt\0"
 1554      00
 1555 0c05 01       		.byte	0x1
 1556 0c06 1C       		.byte	0x1c
 1557 0c07 09       		.byte	0x9
 1558 0c08 69050000 		.long	0x569
 1559 0c0c 08       		.byte	0x8
 1560 0c0d 17       		.uleb128 0x17
 1561 0c0e 5F626173 		.ascii "_base\0"
 1561      6500
 1562 0c14 01       		.byte	0x1
 1563 0c15 1D       		.byte	0x1d
 1564 0c16 0B       		.byte	0xb
 1565 0c17 0A060000 		.long	0x60a
 1566 0c1b 10       		.byte	0x10
 1567 0c1c 17       		.uleb128 0x17
 1568 0c1d 5F666C61 		.ascii "_flag\0"
 1568      6700
 1569 0c23 01       		.byte	0x1
 1570 0c24 1E       		.byte	0x1e
 1571 0c25 09       		.byte	0x9
 1572 0c26 69050000 		.long	0x569
 1573 0c2a 18       		.byte	0x18
 1574 0c2b 17       		.uleb128 0x17
 1575 0c2c 5F66696C 		.ascii "_file\0"
 1575      6500
 1576 0c32 01       		.byte	0x1
 1577 0c33 1F       		.byte	0x1f
 1578 0c34 09       		.byte	0x9
 1579 0c35 69050000 		.long	0x569
 1580 0c39 1C       		.byte	0x1c
 1581 0c3a 17       		.uleb128 0x17
 1582 0c3b 5F636861 		.ascii "_charbuf\0"
 1582      72627566 
 1582      00
 1583 0c44 01       		.byte	0x1
 1584 0c45 20       		.byte	0x20
 1585 0c46 09       		.byte	0x9
 1586 0c47 69050000 		.long	0x569
 1587 0c4b 20       		.byte	0x20
 1588 0c4c 17       		.uleb128 0x17
 1589 0c4d 5F627566 		.ascii "_bufsiz\0"
 1589      73697A00 
 1590 0c55 01       		.byte	0x1
 1591 0c56 21       		.byte	0x21
 1592 0c57 09       		.byte	0x9
 1593 0c58 69050000 		.long	0x569
 1594 0c5c 24       		.byte	0x24
 1595 0c5d 17       		.uleb128 0x17
 1596 0c5e 5F746D70 		.ascii "_tmpfname\0"
 1596      666E616D 
 1596      6500
 1597 0c68 01       		.byte	0x1
 1598 0c69 22       		.byte	0x22
 1599 0c6a 0B       		.byte	0xb
 1600 0c6b 0A060000 		.long	0x60a
 1601 0c6f 28       		.byte	0x28
 1602 0c70 00       		.byte	0
 1603 0c71 0A       		.uleb128 0xa
 1604 0c72 46494C45 		.ascii "FILE\0"
 1604      00
 1605 0c77 01       		.byte	0x1
 1606 0c78 24       		.byte	0x24
 1607 0c79 19       		.byte	0x19
 1608 0c7a E10B0000 		.long	0xbe1
 1609 0c7e 0A       		.uleb128 0xa
 1610 0c7f 66706F73 		.ascii "fpos_t\0"
 1610      5F7400
 1611 0c86 01       		.byte	0x1
 1612 0c87 68       		.byte	0x68
 1613 0c88 25       		.byte	0x25
 1614 0c89 81050000 		.long	0x581
 1615 0c8d 08       		.uleb128 0x8
 1616 0c8e 7E0C0000 		.long	0xc7e
 1617 0c92 24       		.uleb128 0x24
 1618 0c93 636C6561 		.ascii "clearerr\0"
 1618      72657272 
 1618      00
 1619 0c9c 01       		.byte	0x1
 1620 0c9d 4202     		.word	0x242
 1621 0c9f 10       		.byte	0x10
 1622 0ca0 AA0C0000 		.long	0xcaa
 1623 0ca4 0D       		.uleb128 0xd
 1624 0ca5 AA0C0000 		.long	0xcaa
 1625 0ca9 00       		.byte	0
 1626 0caa 16       		.uleb128 0x16
 1627 0cab 08       		.byte	0x8
 1628 0cac 710C0000 		.long	0xc71
 1629 0cb0 20       		.uleb128 0x20
 1630 0cb1 66636C6F 		.ascii "fclose\0"
 1630      736500
 1631 0cb8 01       		.byte	0x1
 1632 0cb9 4302     		.word	0x243
 1633 0cbb 0F       		.byte	0xf
 1634 0cbc 69050000 		.long	0x569
 1635 0cc0 CA0C0000 		.long	0xcca
 1636 0cc4 0D       		.uleb128 0xd
 1637 0cc5 AA0C0000 		.long	0xcaa
 1638 0cc9 00       		.byte	0
 1639 0cca 20       		.uleb128 0x20
 1640 0ccb 66656F66 		.ascii "feof\0"
 1640      00
 1641 0cd0 01       		.byte	0x1
 1642 0cd1 4A02     		.word	0x24a
 1643 0cd3 0F       		.byte	0xf
 1644 0cd4 69050000 		.long	0x569
 1645 0cd8 E20C0000 		.long	0xce2
 1646 0cdc 0D       		.uleb128 0xd
 1647 0cdd AA0C0000 		.long	0xcaa
 1648 0ce1 00       		.byte	0
 1649 0ce2 20       		.uleb128 0x20
 1650 0ce3 66657272 		.ascii "ferror\0"
 1650      6F7200
 1651 0cea 01       		.byte	0x1
 1652 0ceb 4B02     		.word	0x24b
 1653 0ced 0F       		.byte	0xf
 1654 0cee 69050000 		.long	0x569
 1655 0cf2 FC0C0000 		.long	0xcfc
 1656 0cf6 0D       		.uleb128 0xd
 1657 0cf7 AA0C0000 		.long	0xcaa
 1658 0cfb 00       		.byte	0
 1659 0cfc 20       		.uleb128 0x20
 1660 0cfd 66666C75 		.ascii "fflush\0"
 1660      736800
 1661 0d04 01       		.byte	0x1
 1662 0d05 4C02     		.word	0x24c
 1663 0d07 0F       		.byte	0xf
 1664 0d08 69050000 		.long	0x569
 1665 0d0c 160D0000 		.long	0xd16
 1666 0d10 0D       		.uleb128 0xd
 1667 0d11 AA0C0000 		.long	0xcaa
 1668 0d15 00       		.byte	0
 1669 0d16 20       		.uleb128 0x20
 1670 0d17 66676574 		.ascii "fgetc\0"
 1670      6300
 1671 0d1d 01       		.byte	0x1
 1672 0d1e 4D02     		.word	0x24d
 1673 0d20 0F       		.byte	0xf
 1674 0d21 69050000 		.long	0x569
 1675 0d25 2F0D0000 		.long	0xd2f
 1676 0d29 0D       		.uleb128 0xd
 1677 0d2a AA0C0000 		.long	0xcaa
 1678 0d2e 00       		.byte	0
 1679 0d2f 20       		.uleb128 0x20
 1680 0d30 66676574 		.ascii "fgetpos\0"
 1680      706F7300 
 1681 0d38 01       		.byte	0x1
 1682 0d39 4F02     		.word	0x24f
 1683 0d3b 0F       		.byte	0xf
 1684 0d3c 69050000 		.long	0x569
 1685 0d40 4F0D0000 		.long	0xd4f
 1686 0d44 0D       		.uleb128 0xd
 1687 0d45 AA0C0000 		.long	0xcaa
 1688 0d49 0D       		.uleb128 0xd
 1689 0d4a 4F0D0000 		.long	0xd4f
 1690 0d4e 00       		.byte	0
 1691 0d4f 16       		.uleb128 0x16
 1692 0d50 08       		.byte	0x8
 1693 0d51 7E0C0000 		.long	0xc7e
 1694 0d55 20       		.uleb128 0x20
 1695 0d56 66676574 		.ascii "fgets\0"
 1695      7300
 1696 0d5c 01       		.byte	0x1
 1697 0d5d 5102     		.word	0x251
 1698 0d5f 11       		.byte	0x11
 1699 0d60 0A060000 		.long	0x60a
 1700 0d64 780D0000 		.long	0xd78
 1701 0d68 0D       		.uleb128 0xd
 1702 0d69 0A060000 		.long	0x60a
 1703 0d6d 0D       		.uleb128 0xd
 1704 0d6e 69050000 		.long	0x569
 1705 0d72 0D       		.uleb128 0xd
 1706 0d73 AA0C0000 		.long	0xcaa
 1707 0d77 00       		.byte	0
 1708 0d78 20       		.uleb128 0x20
 1709 0d79 666F7065 		.ascii "fopen\0"
 1709      6E00
 1710 0d7f 01       		.byte	0x1
 1711 0d80 5802     		.word	0x258
 1712 0d82 11       		.byte	0x11
 1713 0d83 AA0C0000 		.long	0xcaa
 1714 0d87 960D0000 		.long	0xd96
 1715 0d8b 0D       		.uleb128 0xd
 1716 0d8c C2080000 		.long	0x8c2
 1717 0d90 0D       		.uleb128 0xd
 1718 0d91 C2080000 		.long	0x8c2
 1719 0d95 00       		.byte	0
 1720 0d96 26       		.uleb128 0x26
 1721 0d97 66707269 		.ascii "fprintf\0"
 1721      6E746600 
 1722 0d9f 01       		.byte	0x1
 1723 0da0 4E01     		.word	0x14e
 1724 0da2 05       		.byte	0x5
 1725 0da3 5F5A3766 		.ascii "_Z7fprintfP6_iobufPKcz\0"
 1725      7072696E 
 1725      74665036 
 1725      5F696F62 
 1725      7566504B 
 1726 0dba 69050000 		.long	0x569
 1727 0dbe CE0D0000 		.long	0xdce
 1728 0dc2 0D       		.uleb128 0xd
 1729 0dc3 AA0C0000 		.long	0xcaa
 1730 0dc7 0D       		.uleb128 0xd
 1731 0dc8 C2080000 		.long	0x8c2
 1732 0dcc 27       		.uleb128 0x27
 1733 0dcd 00       		.byte	0
 1734 0dce 20       		.uleb128 0x20
 1735 0dcf 66726561 		.ascii "fread\0"
 1735      6400
 1736 0dd5 01       		.byte	0x1
 1737 0dd6 5D02     		.word	0x25d
 1738 0dd8 12       		.byte	0x12
 1739 0dd9 FB050000 		.long	0x5fb
 1740 0ddd F60D0000 		.long	0xdf6
 1741 0de1 0D       		.uleb128 0xd
 1742 0de2 27090000 		.long	0x927
 1743 0de6 0D       		.uleb128 0xd
 1744 0de7 FB050000 		.long	0x5fb
 1745 0deb 0D       		.uleb128 0xd
 1746 0dec FB050000 		.long	0x5fb
 1747 0df0 0D       		.uleb128 0xd
 1748 0df1 AA0C0000 		.long	0xcaa
 1749 0df5 00       		.byte	0
 1750 0df6 20       		.uleb128 0x20
 1751 0df7 6672656F 		.ascii "freopen\0"
 1751      70656E00 
 1752 0dff 01       		.byte	0x1
 1753 0e00 5E02     		.word	0x25e
 1754 0e02 11       		.byte	0x11
 1755 0e03 AA0C0000 		.long	0xcaa
 1756 0e07 1B0E0000 		.long	0xe1b
 1757 0e0b 0D       		.uleb128 0xd
 1758 0e0c C2080000 		.long	0x8c2
 1759 0e10 0D       		.uleb128 0xd
 1760 0e11 C2080000 		.long	0x8c2
 1761 0e15 0D       		.uleb128 0xd
 1762 0e16 AA0C0000 		.long	0xcaa
 1763 0e1a 00       		.byte	0
 1764 0e1b 26       		.uleb128 0x26
 1765 0e1c 66736361 		.ascii "fscanf\0"
 1765      6E6600
 1766 0e23 01       		.byte	0x1
 1767 0e24 2101     		.word	0x121
 1768 0e26 05       		.byte	0x5
 1769 0e27 5F5A3666 		.ascii "_Z6fscanfP6_iobufPKcz\0"
 1769      7363616E 
 1769      6650365F 
 1769      696F6275 
 1769      66504B63 
 1770 0e3d 69050000 		.long	0x569
 1771 0e41 510E0000 		.long	0xe51
 1772 0e45 0D       		.uleb128 0xd
 1773 0e46 AA0C0000 		.long	0xcaa
 1774 0e4a 0D       		.uleb128 0xd
 1775 0e4b C2080000 		.long	0x8c2
 1776 0e4f 27       		.uleb128 0x27
 1777 0e50 00       		.byte	0
 1778 0e51 20       		.uleb128 0x20
 1779 0e52 66736565 		.ascii "fseek\0"
 1779      6B00
 1780 0e58 01       		.byte	0x1
 1781 0e59 6102     		.word	0x261
 1782 0e5b 0F       		.byte	0xf
 1783 0e5c 69050000 		.long	0x569
 1784 0e60 740E0000 		.long	0xe74
 1785 0e64 0D       		.uleb128 0xd
 1786 0e65 AA0C0000 		.long	0xcaa
 1787 0e69 0D       		.uleb128 0xd
 1788 0e6a 75050000 		.long	0x575
 1789 0e6e 0D       		.uleb128 0xd
 1790 0e6f 69050000 		.long	0x569
 1791 0e73 00       		.byte	0
 1792 0e74 20       		.uleb128 0x20
 1793 0e75 66736574 		.ascii "fsetpos\0"
 1793      706F7300 
 1794 0e7d 01       		.byte	0x1
 1795 0e7e 5F02     		.word	0x25f
 1796 0e80 0F       		.byte	0xf
 1797 0e81 69050000 		.long	0x569
 1798 0e85 940E0000 		.long	0xe94
 1799 0e89 0D       		.uleb128 0xd
 1800 0e8a AA0C0000 		.long	0xcaa
 1801 0e8e 0D       		.uleb128 0xd
 1802 0e8f 940E0000 		.long	0xe94
 1803 0e93 00       		.byte	0
 1804 0e94 16       		.uleb128 0x16
 1805 0e95 08       		.byte	0x8
 1806 0e96 8D0C0000 		.long	0xc8d
 1807 0e9a 20       		.uleb128 0x20
 1808 0e9b 6674656C 		.ascii "ftell\0"
 1808      6C00
 1809 0ea1 01       		.byte	0x1
 1810 0ea2 6202     		.word	0x262
 1811 0ea4 10       		.byte	0x10
 1812 0ea5 75050000 		.long	0x575
 1813 0ea9 B30E0000 		.long	0xeb3
 1814 0ead 0D       		.uleb128 0xd
 1815 0eae AA0C0000 		.long	0xcaa
 1816 0eb2 00       		.byte	0
 1817 0eb3 20       		.uleb128 0x20
 1818 0eb4 67657463 		.ascii "getc\0"
 1818      00
 1819 0eb9 01       		.byte	0x1
 1820 0eba 8F02     		.word	0x28f
 1821 0ebc 0F       		.byte	0xf
 1822 0ebd 69050000 		.long	0x569
 1823 0ec1 CB0E0000 		.long	0xecb
 1824 0ec5 0D       		.uleb128 0xd
 1825 0ec6 AA0C0000 		.long	0xcaa
 1826 0eca 00       		.byte	0
 1827 0ecb 25       		.uleb128 0x25
 1828 0ecc 67657463 		.ascii "getchar\0"
 1828      68617200 
 1829 0ed4 01       		.byte	0x1
 1830 0ed5 9002     		.word	0x290
 1831 0ed7 0F       		.byte	0xf
 1832 0ed8 69050000 		.long	0x569
 1833 0edc 20       		.uleb128 0x20
 1834 0edd 67657473 		.ascii "gets\0"
 1834      00
 1835 0ee2 01       		.byte	0x1
 1836 0ee3 9202     		.word	0x292
 1837 0ee5 11       		.byte	0x11
 1838 0ee6 0A060000 		.long	0x60a
 1839 0eea F40E0000 		.long	0xef4
 1840 0eee 0D       		.uleb128 0xd
 1841 0eef 0A060000 		.long	0x60a
 1842 0ef3 00       		.byte	0
 1843 0ef4 24       		.uleb128 0x24
 1844 0ef5 70657272 		.ascii "perror\0"
 1844      6F7200
 1845 0efc 0D       		.byte	0xd
 1846 0efd 6D02     		.word	0x26d
 1847 0eff 10       		.byte	0x10
 1848 0f00 0A0F0000 		.long	0xf0a
 1849 0f04 0D       		.uleb128 0xd
 1850 0f05 C2080000 		.long	0x8c2
 1851 0f09 00       		.byte	0
 1852 0f0a 28       		.uleb128 0x28
 1853 0f0b 7072696E 		.ascii "printf\0"
 1853      746600
 1854 0f12 01       		.byte	0x1
 1855 0f13 5901     		.word	0x159
 1856 0f15 05       		.byte	0x5
 1857 0f16 5F5A3670 		.ascii "_Z6printfPKcz\0"
 1857      72696E74 
 1857      66504B63 
 1857      7A00
 1858 0f24 69050000 		.long	0x569
 1859 0f28 00000000 		.quad	.LFB482
 1859      00000000 
 1860 0f30 54000000 		.quad	.LFE482-.LFB482
 1860      00000000 
 1861 0f38 01       		.uleb128 0x1
 1862 0f39 9C       		.byte	0x9c
 1863 0f3a 7E0F0000 		.long	0xf7e
 1864 0f3e 27       		.uleb128 0x27
 1865 0f3f 29       		.uleb128 0x29
 1866 0f40 19000000 		.secrel32	.LASF2
 1867 0f44 01       		.byte	0x1
 1868 0f45 5901     		.word	0x159
 1869 0f47 19       		.byte	0x19
 1870 0f48 C2080000 		.long	0x8c2
 1871 0f4c 02       		.uleb128 0x2
 1872 0f4d 91       		.byte	0x91
 1873 0f4e 00       		.sleb128 0
 1874 0f4f 27       		.uleb128 0x27
 1875 0f50 2A       		.uleb128 0x2a
 1876 0f51 10000000 		.secrel32	.LASF0
 1877 0f55 01       		.byte	0x1
 1878 0f56 5B01     		.word	0x15b
 1879 0f58 07       		.byte	0x7
 1880 0f59 69050000 		.long	0x569
 1881 0f5d 02       		.uleb128 0x2
 1882 0f5e 91       		.byte	0x91
 1883 0f5f 5C       		.sleb128 -36
 1884 0f60 2A       		.uleb128 0x2a
 1885 0f61 22000000 		.secrel32	.LASF1
 1886 0f65 01       		.byte	0x1
 1887 0f66 5C01     		.word	0x15c
 1888 0f68 15       		.byte	0x15
 1889 0f69 D6050000 		.long	0x5d6
 1890 0f6d 02       		.uleb128 0x2
 1891 0f6e 91       		.byte	0x91
 1892 0f6f 50       		.sleb128 -48
 1893 0f70 2B       		.uleb128 0x2b
 1894 0f71 38000000 		.quad	.LVL1
 1894      00000000 
 1895 0f79 80140000 		.long	0x1480
 1896 0f7d 00       		.byte	0
 1897 0f7e 20       		.uleb128 0x20
 1898 0f7f 72656D6F 		.ascii "remove\0"
 1898      766500
 1899 0f86 01       		.byte	0x1
 1900 0f87 A402     		.word	0x2a4
 1901 0f89 0F       		.byte	0xf
 1902 0f8a 69050000 		.long	0x569
 1903 0f8e 980F0000 		.long	0xf98
 1904 0f92 0D       		.uleb128 0xd
 1905 0f93 C2080000 		.long	0x8c2
 1906 0f97 00       		.byte	0
 1907 0f98 20       		.uleb128 0x20
 1908 0f99 72656E61 		.ascii "rename\0"
 1908      6D6500
 1909 0fa0 01       		.byte	0x1
 1910 0fa1 A502     		.word	0x2a5
 1911 0fa3 0F       		.byte	0xf
 1912 0fa4 69050000 		.long	0x569
 1913 0fa8 B70F0000 		.long	0xfb7
 1914 0fac 0D       		.uleb128 0xd
 1915 0fad C2080000 		.long	0x8c2
 1916 0fb1 0D       		.uleb128 0xd
 1917 0fb2 C2080000 		.long	0x8c2
 1918 0fb6 00       		.byte	0
 1919 0fb7 24       		.uleb128 0x24
 1920 0fb8 72657769 		.ascii "rewind\0"
 1920      6E6400
 1921 0fbf 01       		.byte	0x1
 1922 0fc0 AB02     		.word	0x2ab
 1923 0fc2 10       		.byte	0x10
 1924 0fc3 CD0F0000 		.long	0xfcd
 1925 0fc7 0D       		.uleb128 0xd
 1926 0fc8 AA0C0000 		.long	0xcaa
 1927 0fcc 00       		.byte	0
 1928 0fcd 28       		.uleb128 0x28
 1929 0fce 7363616E 		.ascii "scanf\0"
 1929      6600
 1930 0fd4 01       		.byte	0x1
 1931 0fd5 1601     		.word	0x116
 1932 0fd7 05       		.byte	0x5
 1933 0fd8 5F5A3573 		.ascii "_Z5scanfPKcz\0"
 1933      63616E66 
 1933      504B637A 
 1933      00
 1934 0fe5 69050000 		.long	0x569
 1935 0fe9 00000000 		.quad	.LFB476
 1935      00000000 
 1936 0ff1 54000000 		.quad	.LFE476-.LFB476
 1936      00000000 
 1937 0ff9 01       		.uleb128 0x1
 1938 0ffa 9C       		.byte	0x9c
 1939 0ffb 3F100000 		.long	0x103f
 1940 0fff 27       		.uleb128 0x27
 1941 1000 29       		.uleb128 0x29
 1942 1001 19000000 		.secrel32	.LASF2
 1943 1005 01       		.byte	0x1
 1944 1006 1601     		.word	0x116
 1945 1008 17       		.byte	0x17
 1946 1009 C2080000 		.long	0x8c2
 1947 100d 02       		.uleb128 0x2
 1948 100e 91       		.byte	0x91
 1949 100f 00       		.sleb128 0
 1950 1010 27       		.uleb128 0x27
 1951 1011 2A       		.uleb128 0x2a
 1952 1012 10000000 		.secrel32	.LASF0
 1953 1016 01       		.byte	0x1
 1954 1017 1801     		.word	0x118
 1955 1019 07       		.byte	0x7
 1956 101a 69050000 		.long	0x569
 1957 101e 02       		.uleb128 0x2
 1958 101f 91       		.byte	0x91
 1959 1020 5C       		.sleb128 -36
 1960 1021 2A       		.uleb128 0x2a
 1961 1022 22000000 		.secrel32	.LASF1
 1962 1026 01       		.byte	0x1
 1963 1027 1901     		.word	0x119
 1964 1029 15       		.byte	0x15
 1965 102a D6050000 		.long	0x5d6
 1966 102e 02       		.uleb128 0x2
 1967 102f 91       		.byte	0x91
 1968 1030 50       		.sleb128 -48
 1969 1031 2B       		.uleb128 0x2b
 1970 1032 38000000 		.quad	.LVL0
 1970      00000000 
 1971 103a 80140000 		.long	0x1480
 1972 103e 00       		.byte	0
 1973 103f 24       		.uleb128 0x24
 1974 1040 73657462 		.ascii "setbuf\0"
 1974      756600
 1975 1047 01       		.byte	0x1
 1976 1048 AD02     		.word	0x2ad
 1977 104a 10       		.byte	0x10
 1978 104b 5A100000 		.long	0x105a
 1979 104f 0D       		.uleb128 0xd
 1980 1050 AA0C0000 		.long	0xcaa
 1981 1054 0D       		.uleb128 0xd
 1982 1055 0A060000 		.long	0x60a
 1983 1059 00       		.byte	0
 1984 105a 20       		.uleb128 0x20
 1985 105b 73657476 		.ascii "setvbuf\0"
 1985      62756600 
 1986 1063 01       		.byte	0x1
 1987 1064 B102     		.word	0x2b1
 1988 1066 0F       		.byte	0xf
 1989 1067 69050000 		.long	0x569
 1990 106b 84100000 		.long	0x1084
 1991 106f 0D       		.uleb128 0xd
 1992 1070 AA0C0000 		.long	0xcaa
 1993 1074 0D       		.uleb128 0xd
 1994 1075 0A060000 		.long	0x60a
 1995 1079 0D       		.uleb128 0xd
 1996 107a 69050000 		.long	0x569
 1997 107e 0D       		.uleb128 0xd
 1998 107f FB050000 		.long	0x5fb
 1999 1083 00       		.byte	0
 2000 1084 26       		.uleb128 0x26
 2001 1085 73707269 		.ascii "sprintf\0"
 2001      6E746600 
 2002 108d 01       		.byte	0x1
 2003 108e 6401     		.word	0x164
 2004 1090 05       		.byte	0x5
 2005 1091 5F5A3773 		.ascii "_Z7sprintfPcPKcz\0"
 2005      7072696E 
 2005      74665063 
 2005      504B637A 
 2005      00
 2006 10a2 69050000 		.long	0x569
 2007 10a6 B6100000 		.long	0x10b6
 2008 10aa 0D       		.uleb128 0xd
 2009 10ab 0A060000 		.long	0x60a
 2010 10af 0D       		.uleb128 0xd
 2011 10b0 C2080000 		.long	0x8c2
 2012 10b4 27       		.uleb128 0x27
 2013 10b5 00       		.byte	0
 2014 10b6 26       		.uleb128 0x26
 2015 10b7 73736361 		.ascii "sscanf\0"
 2015      6E6600
 2016 10be 01       		.byte	0x1
 2017 10bf 0B01     		.word	0x10b
 2018 10c1 05       		.byte	0x5
 2019 10c2 5F5A3673 		.ascii "_Z6sscanfPKcS0_z\0"
 2019      7363616E 
 2019      66504B63 
 2019      53305F7A 
 2019      00
 2020 10d3 69050000 		.long	0x569
 2021 10d7 E7100000 		.long	0x10e7
 2022 10db 0D       		.uleb128 0xd
 2023 10dc C2080000 		.long	0x8c2
 2024 10e0 0D       		.uleb128 0xd
 2025 10e1 C2080000 		.long	0x8c2
 2026 10e5 27       		.uleb128 0x27
 2027 10e6 00       		.byte	0
 2028 10e7 25       		.uleb128 0x25
 2029 10e8 746D7066 		.ascii "tmpfile\0"
 2029      696C6500 
 2030 10f0 01       		.byte	0x1
 2031 10f1 CB02     		.word	0x2cb
 2032 10f3 11       		.byte	0x11
 2033 10f4 AA0C0000 		.long	0xcaa
 2034 10f8 20       		.uleb128 0x20
 2035 10f9 746D706E 		.ascii "tmpnam\0"
 2035      616D00
 2036 1100 01       		.byte	0x1
 2037 1101 CC02     		.word	0x2cc
 2038 1103 11       		.byte	0x11
 2039 1104 0A060000 		.long	0x60a
 2040 1108 12110000 		.long	0x1112
 2041 110c 0D       		.uleb128 0xd
 2042 110d 0A060000 		.long	0x60a
 2043 1111 00       		.byte	0
 2044 1112 20       		.uleb128 0x20
 2045 1113 756E6765 		.ascii "ungetc\0"
 2045      746300
 2046 111a 01       		.byte	0x1
 2047 111b CD02     		.word	0x2cd
 2048 111d 0F       		.byte	0xf
 2049 111e 69050000 		.long	0x569
 2050 1122 31110000 		.long	0x1131
 2051 1126 0D       		.uleb128 0xd
 2052 1127 69050000 		.long	0x569
 2053 112b 0D       		.uleb128 0xd
 2054 112c AA0C0000 		.long	0xcaa
 2055 1130 00       		.byte	0
 2056 1131 26       		.uleb128 0x26
 2057 1132 76667072 		.ascii "vfprintf\0"
 2057      696E7466 
 2057      00
 2058 113b 01       		.byte	0x1
 2059 113c 6F01     		.word	0x16f
 2060 113e 05       		.byte	0x5
 2061 113f 5F5A3876 		.ascii "_Z8vfprintfP6_iobufPKcPc\0"
 2061      66707269 
 2061      6E746650 
 2061      365F696F 
 2061      62756650 
 2062 1158 69050000 		.long	0x569
 2063 115c 70110000 		.long	0x1170
 2064 1160 0D       		.uleb128 0xd
 2065 1161 AA0C0000 		.long	0xcaa
 2066 1165 0D       		.uleb128 0xd
 2067 1166 C2080000 		.long	0x8c2
 2068 116a 0D       		.uleb128 0xd
 2069 116b D6050000 		.long	0x5d6
 2070 116f 00       		.byte	0
 2071 1170 26       		.uleb128 0x26
 2072 1171 76707269 		.ascii "vprintf\0"
 2072      6E746600 
 2073 1179 01       		.byte	0x1
 2074 117a 7601     		.word	0x176
 2075 117c 05       		.byte	0x5
 2076 117d 5F5A3776 		.ascii "_Z7vprintfPKcPc\0"
 2076      7072696E 
 2076      7466504B 
 2076      63506300 
 2077 118d 69050000 		.long	0x569
 2078 1191 A0110000 		.long	0x11a0
 2079 1195 0D       		.uleb128 0xd
 2080 1196 C2080000 		.long	0x8c2
 2081 119a 0D       		.uleb128 0xd
 2082 119b D6050000 		.long	0x5d6
 2083 119f 00       		.byte	0
 2084 11a0 26       		.uleb128 0x26
 2085 11a1 76737072 		.ascii "vsprintf\0"
 2085      696E7466 
 2085      00
 2086 11aa 01       		.byte	0x1
 2087 11ab 7D01     		.word	0x17d
 2088 11ad 05       		.byte	0x5
 2089 11ae 5F5A3876 		.ascii "_Z8vsprintfPcPKcS_\0"
 2089      73707269 
 2089      6E746650 
 2089      63504B63 
 2089      535F00
 2090 11c1 69050000 		.long	0x569
 2091 11c5 D9110000 		.long	0x11d9
 2092 11c9 0D       		.uleb128 0xd
 2093 11ca 0A060000 		.long	0x60a
 2094 11ce 0D       		.uleb128 0xd
 2095 11cf C2080000 		.long	0x8c2
 2096 11d3 0D       		.uleb128 0xd
 2097 11d4 D6050000 		.long	0x5d6
 2098 11d8 00       		.byte	0
 2099 11d9 26       		.uleb128 0x26
 2100 11da 736E7072 		.ascii "snprintf\0"
 2100      696E7466 
 2100      00
 2101 11e3 01       		.byte	0x1
 2102 11e4 8401     		.word	0x184
 2103 11e6 05       		.byte	0x5
 2104 11e7 5F5A3873 		.ascii "_Z8snprintfPcyPKcz\0"
 2104      6E707269 
 2104      6E746650 
 2104      6379504B 
 2104      637A00
 2105 11fa 69050000 		.long	0x569
 2106 11fe 13120000 		.long	0x1213
 2107 1202 0D       		.uleb128 0xd
 2108 1203 0A060000 		.long	0x60a
 2109 1207 0D       		.uleb128 0xd
 2110 1208 FB050000 		.long	0x5fb
 2111 120c 0D       		.uleb128 0xd
 2112 120d C2080000 		.long	0x8c2
 2113 1211 27       		.uleb128 0x27
 2114 1212 00       		.byte	0
 2115 1213 26       		.uleb128 0x26
 2116 1214 76667363 		.ascii "vfscanf\0"
 2116      616E6600 
 2117 121c 01       		.byte	0x1
 2118 121d 4001     		.word	0x140
 2119 121f 05       		.byte	0x5
 2120 1220 5F5A3776 		.ascii "_Z7vfscanfP6_iobufPKcPc\0"
 2120      66736361 
 2120      6E665036 
 2120      5F696F62 
 2120      7566504B 
 2121 1238 69050000 		.long	0x569
 2122 123c 50120000 		.long	0x1250
 2123 1240 0D       		.uleb128 0xd
 2124 1241 AA0C0000 		.long	0xcaa
 2125 1245 0D       		.uleb128 0xd
 2126 1246 C2080000 		.long	0x8c2
 2127 124a 0D       		.uleb128 0xd
 2128 124b D6050000 		.long	0x5d6
 2129 124f 00       		.byte	0
 2130 1250 26       		.uleb128 0x26
 2131 1251 76736361 		.ascii "vscanf\0"
 2131      6E6600
 2132 1258 01       		.byte	0x1
 2133 1259 3901     		.word	0x139
 2134 125b 05       		.byte	0x5
 2135 125c 5F5A3676 		.ascii "_Z6vscanfPKcPc\0"
 2135      7363616E 
 2135      66504B63 
 2135      506300
 2136 126b 69050000 		.long	0x569
 2137 126f 7E120000 		.long	0x127e
 2138 1273 0D       		.uleb128 0xd
 2139 1274 C2080000 		.long	0x8c2
 2140 1278 0D       		.uleb128 0xd
 2141 1279 D6050000 		.long	0x5d6
 2142 127d 00       		.byte	0
 2143 127e 26       		.uleb128 0x26
 2144 127f 76736E70 		.ascii "vsnprintf\0"
 2144      72696E74 
 2144      6600
 2145 1289 01       		.byte	0x1
 2146 128a 8F01     		.word	0x18f
 2147 128c 05       		.byte	0x5
 2148 128d 5F5A3976 		.ascii "_Z9vsnprintfPcyPKcS_\0"
 2148      736E7072 
 2148      696E7466 
 2148      50637950 
 2148      4B63535F 
 2149 12a2 69050000 		.long	0x569
 2150 12a6 BF120000 		.long	0x12bf
 2151 12aa 0D       		.uleb128 0xd
 2152 12ab 0A060000 		.long	0x60a
 2153 12af 0D       		.uleb128 0xd
 2154 12b0 FB050000 		.long	0x5fb
 2155 12b4 0D       		.uleb128 0xd
 2156 12b5 C2080000 		.long	0x8c2
 2157 12b9 0D       		.uleb128 0xd
 2158 12ba D6050000 		.long	0x5d6
 2159 12be 00       		.byte	0
 2160 12bf 26       		.uleb128 0x26
 2161 12c0 76737363 		.ascii "vsscanf\0"
 2161      616E6600 
 2162 12c8 01       		.byte	0x1
 2163 12c9 3201     		.word	0x132
 2164 12cb 05       		.byte	0x5
 2165 12cc 5F5A3776 		.ascii "_Z7vsscanfPKcS0_Pc\0"
 2165      73736361 
 2165      6E66504B 
 2165      6353305F 
 2165      506300
 2166 12df 69050000 		.long	0x569
 2167 12e3 F7120000 		.long	0x12f7
 2168 12e7 0D       		.uleb128 0xd
 2169 12e8 C2080000 		.long	0x8c2
 2170 12ec 0D       		.uleb128 0xd
 2171 12ed C2080000 		.long	0x8c2
 2172 12f1 0D       		.uleb128 0xd
 2173 12f2 D6050000 		.long	0x5d6
 2174 12f6 00       		.byte	0
 2175 12f7 2C       		.uleb128 0x2c
 2176 12f8 4D00     		.ascii "M\0"
 2177 12fa 02       		.byte	0x2
 2178 12fb 07       		.byte	0x7
 2179 12fc 0B       		.byte	0xb
 2180 12fd 70050000 		.long	0x570
 2181 1301 09       		.uleb128 0x9
 2182 1302 03       		.byte	0x3
 2183 1303 00000000 		.quad	_ZL1M
 2183      00000000 
 2184 130b 1A       		.uleb128 0x1a
 2185 130c 69050000 		.long	0x569
 2186 1310 1B130000 		.long	0x131b
 2187 1314 1B       		.uleb128 0x1b
 2188 1315 33050000 		.long	0x533
 2189 1319 C8       		.byte	0xc8
 2190 131a 00       		.byte	0
 2191 131b 2D       		.uleb128 0x2d
 2192 131c 6600     		.ascii "f\0"
 2193 131e 02       		.byte	0x2
 2194 131f 08       		.byte	0x8
 2195 1320 05       		.byte	0x5
 2196 1321 0B130000 		.long	0x130b
 2197 1325 09       		.uleb128 0x9
 2198 1326 03       		.byte	0x3
 2199 1327 00000000 		.quad	f
 2199      00000000 
 2200 132f 2E       		.uleb128 0x2e
 2201 1330 5F5A4E39 		.ascii "_ZN9__gnu_cxx24__numeric_traits_integerIxE5__maxE\0"
 2201      5F5F676E 
 2201      755F6378 
 2201      7832345F 
 2201      5F6E756D 
 2202 1362 7E040000 		.long	0x47e
 2203 1366 FFFFFFFF 		.quad	0x7fffffffffffffff
 2203      FFFFFF7F 
 2204 136e 2F       		.uleb128 0x2f
 2205 136f 08       		.byte	0x8
 2206 1370 70050000 		.long	0x570
 2207 1374 30       		.uleb128 0x30
 2208 1375 58030000 		.long	0x358
 2209 1379 00000000 		.quad	.LFB519
 2209      00000000 
 2210 1381 28000000 		.quad	.LFE519-.LFB519
 2210      00000000 
 2211 1389 01       		.uleb128 0x1
 2212 138a 9C       		.byte	0x9c
 2213 138b B7130000 		.long	0x13b7
 2214 138f 0C       		.uleb128 0xc
 2215 1390 5F547000 		.ascii "_Tp\0"
 2216 1394 69050000 		.long	0x569
 2217 1398 31       		.uleb128 0x31
 2218 1399 5F5F6100 		.ascii "__a\0"
 2219 139d 03       		.byte	0x3
 2220 139e DB       		.byte	0xdb
 2221 139f 14       		.byte	0x14
 2222 13a0 6E130000 		.long	0x136e
 2223 13a4 02       		.uleb128 0x2
 2224 13a5 91       		.byte	0x91
 2225 13a6 00       		.sleb128 0
 2226 13a7 31       		.uleb128 0x31
 2227 13a8 5F5F6200 		.ascii "__b\0"
 2228 13ac 03       		.byte	0x3
 2229 13ad DB       		.byte	0xdb
 2230 13ae 24       		.byte	0x24
 2231 13af 6E130000 		.long	0x136e
 2232 13b3 02       		.uleb128 0x2
 2233 13b4 91       		.byte	0x91
 2234 13b5 08       		.sleb128 8
 2235 13b6 00       		.byte	0
 2236 13b7 32       		.uleb128 0x32
 2237 13b8 6D61696E 		.ascii "main\0"
 2237      00
 2238 13bd 02       		.byte	0x2
 2239 13be 0A       		.byte	0xa
 2240 13bf 05       		.byte	0x5
 2241 13c0 69050000 		.long	0x569
 2242 13c4 00000000 		.quad	.LFB518
 2242      00000000 
 2243 13cc 04010000 		.quad	.LFE518-.LFB518
 2243      00000000 
 2244 13d4 01       		.uleb128 0x1
 2245 13d5 9C       		.byte	0x9c
 2246 13d6 5F140000 		.long	0x145f
 2247 13da 2C       		.uleb128 0x2c
 2248 13db 6D00     		.ascii "m\0"
 2249 13dd 02       		.byte	0x2
 2250 13de 0C       		.byte	0xc
 2251 13df 06       		.byte	0x6
 2252 13e0 69050000 		.long	0x569
 2253 13e4 02       		.uleb128 0x2
 2254 13e5 91       		.byte	0x91
 2255 13e6 60       		.sleb128 -32
 2256 13e7 2C       		.uleb128 0x2c
 2257 13e8 6E00     		.ascii "n\0"
 2258 13ea 02       		.byte	0x2
 2259 13eb 0C       		.byte	0xc
 2260 13ec 09       		.byte	0x9
 2261 13ed 69050000 		.long	0x569
 2262 13f1 02       		.uleb128 0x2
 2263 13f2 91       		.byte	0x91
 2264 13f3 5C       		.sleb128 -36
 2265 13f4 33       		.uleb128 0x33
 2266 13f5 27000000 		.quad	.LBB2
 2266      00000000 
 2267 13fd AD000000 		.quad	.LBE2-.LBB2
 2267      00000000 
 2268 1405 2C       		.uleb128 0x2c
 2269 1406 6900     		.ascii "i\0"
 2270 1408 02       		.byte	0x2
 2271 1409 0E       		.byte	0xe
 2272 140a 0B       		.byte	0xb
 2273 140b 69050000 		.long	0x569
 2274 140f 02       		.uleb128 0x2
 2275 1410 91       		.byte	0x91
 2276 1411 6C       		.sleb128 -20
 2277 1412 33       		.uleb128 0x33
 2278 1413 3A000000 		.quad	.LBB3
 2278      00000000 
 2279 141b 91000000 		.quad	.LBE3-.LBB3
 2279      00000000 
 2280 1423 2C       		.uleb128 0x2c
 2281 1424 7700     		.ascii "w\0"
 2282 1426 02       		.byte	0x2
 2283 1427 10       		.byte	0x10
 2284 1428 07       		.byte	0x7
 2285 1429 69050000 		.long	0x569
 2286 142d 02       		.uleb128 0x2
 2287 142e 91       		.byte	0x91
 2288 142f 58       		.sleb128 -40
 2289 1430 2C       		.uleb128 0x2c
 2290 1431 6300     		.ascii "c\0"
 2291 1433 02       		.byte	0x2
 2292 1434 10       		.byte	0x10
 2293 1435 0A       		.byte	0xa
 2294 1436 69050000 		.long	0x569
 2295 143a 02       		.uleb128 0x2
 2296 143b 91       		.byte	0x91
 2297 143c 54       		.sleb128 -44
 2298 143d 33       		.uleb128 0x33
 2299 143e 54000000 		.quad	.LBB4
 2299      00000000 
 2300 1446 77000000 		.quad	.LBE4-.LBB4
 2300      00000000 
 2301 144e 2C       		.uleb128 0x2c
 2302 144f 6A00     		.ascii "j\0"
 2303 1451 02       		.byte	0x2
 2304 1452 12       		.byte	0x12
 2305 1453 0C       		.byte	0xc
 2306 1454 69050000 		.long	0x569
 2307 1458 02       		.uleb128 0x2
 2308 1459 91       		.byte	0x91
 2309 145a 68       		.sleb128 -24
 2310 145b 00       		.byte	0
 2311 145c 00       		.byte	0
 2312 145d 00       		.byte	0
 2313 145e 00       		.byte	0
 2314 145f 12       		.uleb128 0x12
 2315 1460 10       		.byte	0x10
 2316 1461 05       		.byte	0x5
 2317 1462 5F5F696E 		.ascii "__int128\0"
 2317      74313238 
 2317      00
 2318 146b 12       		.uleb128 0x12
 2319 146c 10       		.byte	0x10
 2320 146d 07       		.byte	0x7
 2321 146e 5F5F696E 		.ascii "__int128 unsigned\0"
 2321      74313238 
 2321      20756E73 
 2321      69676E65 
 2321      6400
 2322 1480 34       		.uleb128 0x34
 2323 1481 00000000 		.secrel32	.LASF3
 2324 1485 00000000 		.secrel32	.LASF3
 2325 1489 01       		.byte	0x1
 2326 148a 52       		.byte	0x52
 2327 148b 17       		.byte	0x17
 2328 148c 00       		.byte	0
 2329              		.section	.debug_abbrev,"dr"
 2330              	.Ldebug_abbrev0:
 2331 0000 01       		.uleb128 0x1
 2332 0001 11       		.uleb128 0x11
 2333 0002 01       		.byte	0x1
 2334 0003 25       		.uleb128 0x25
 2335 0004 08       		.uleb128 0x8
 2336 0005 13       		.uleb128 0x13
 2337 0006 0B       		.uleb128 0xb
 2338 0007 03       		.uleb128 0x3
 2339 0008 08       		.uleb128 0x8
 2340 0009 1B       		.uleb128 0x1b
 2341 000a 08       		.uleb128 0x8
 2342 000b 55       		.uleb128 0x55
 2343 000c 17       		.uleb128 0x17
 2344 000d 11       		.uleb128 0x11
 2345 000e 01       		.uleb128 0x1
 2346 000f 10       		.uleb128 0x10
 2347 0010 17       		.uleb128 0x17
 2348 0011 00       		.byte	0
 2349 0012 00       		.byte	0
 2350 0013 02       		.uleb128 0x2
 2351 0014 39       		.uleb128 0x39
 2352 0015 01       		.byte	0x1
 2353 0016 03       		.uleb128 0x3
 2354 0017 08       		.uleb128 0x8
 2355 0018 3A       		.uleb128 0x3a
 2356 0019 0B       		.uleb128 0xb
 2357 001a 3B       		.uleb128 0x3b
 2358 001b 0B       		.uleb128 0xb
 2359 001c 01       		.uleb128 0x1
 2360 001d 13       		.uleb128 0x13
 2361 001e 00       		.byte	0
 2362 001f 00       		.byte	0
 2363 0020 03       		.uleb128 0x3
 2364 0021 39       		.uleb128 0x39
 2365 0022 00       		.byte	0
 2366 0023 03       		.uleb128 0x3
 2367 0024 08       		.uleb128 0x8
 2368 0025 3A       		.uleb128 0x3a
 2369 0026 0B       		.uleb128 0xb
 2370 0027 3B       		.uleb128 0x3b
 2371 0028 05       		.uleb128 0x5
 2372 0029 39       		.uleb128 0x39
 2373 002a 0B       		.uleb128 0xb
 2374 002b 8901     		.uleb128 0x89
 2375 002d 19       		.uleb128 0x19
 2376 002e 00       		.byte	0
 2377 002f 00       		.byte	0
 2378 0030 04       		.uleb128 0x4
 2379 0031 3A       		.uleb128 0x3a
 2380 0032 00       		.byte	0
 2381 0033 3A       		.uleb128 0x3a
 2382 0034 0B       		.uleb128 0xb
 2383 0035 3B       		.uleb128 0x3b
 2384 0036 05       		.uleb128 0x5
 2385 0037 39       		.uleb128 0x39
 2386 0038 0B       		.uleb128 0xb
 2387 0039 18       		.uleb128 0x18
 2388 003a 13       		.uleb128 0x13
 2389 003b 00       		.byte	0
 2390 003c 00       		.byte	0
 2391 003d 05       		.uleb128 0x5
 2392 003e 39       		.uleb128 0x39
 2393 003f 00       		.byte	0
 2394 0040 03       		.uleb128 0x3
 2395 0041 08       		.uleb128 0x8
 2396 0042 3A       		.uleb128 0x3a
 2397 0043 0B       		.uleb128 0xb
 2398 0044 3B       		.uleb128 0x3b
 2399 0045 0B       		.uleb128 0xb
 2400 0046 39       		.uleb128 0x39
 2401 0047 0B       		.uleb128 0xb
 2402 0048 00       		.byte	0
 2403 0049 00       		.byte	0
 2404 004a 06       		.uleb128 0x6
 2405 004b 08       		.uleb128 0x8
 2406 004c 00       		.byte	0
 2407 004d 3A       		.uleb128 0x3a
 2408 004e 0B       		.uleb128 0xb
 2409 004f 3B       		.uleb128 0x3b
 2410 0050 0B       		.uleb128 0xb
 2411 0051 39       		.uleb128 0x39
 2412 0052 0B       		.uleb128 0xb
 2413 0053 18       		.uleb128 0x18
 2414 0054 13       		.uleb128 0x13
 2415 0055 00       		.byte	0
 2416 0056 00       		.byte	0
 2417 0057 07       		.uleb128 0x7
 2418 0058 13       		.uleb128 0x13
 2419 0059 00       		.byte	0
 2420 005a 03       		.uleb128 0x3
 2421 005b 08       		.uleb128 0x8
 2422 005c 0B       		.uleb128 0xb
 2423 005d 0B       		.uleb128 0xb
 2424 005e 3A       		.uleb128 0x3a
 2425 005f 0B       		.uleb128 0xb
 2426 0060 3B       		.uleb128 0x3b
 2427 0061 0B       		.uleb128 0xb
 2428 0062 39       		.uleb128 0x39
 2429 0063 0B       		.uleb128 0xb
 2430 0064 00       		.byte	0
 2431 0065 00       		.byte	0
 2432 0066 08       		.uleb128 0x8
 2433 0067 26       		.uleb128 0x26
 2434 0068 00       		.byte	0
 2435 0069 49       		.uleb128 0x49
 2436 006a 13       		.uleb128 0x13
 2437 006b 00       		.byte	0
 2438 006c 00       		.byte	0
 2439 006d 09       		.uleb128 0x9
 2440 006e 34       		.uleb128 0x34
 2441 006f 00       		.byte	0
 2442 0070 03       		.uleb128 0x3
 2443 0071 08       		.uleb128 0x8
 2444 0072 3A       		.uleb128 0x3a
 2445 0073 0B       		.uleb128 0xb
 2446 0074 3B       		.uleb128 0x3b
 2447 0075 0B       		.uleb128 0xb
 2448 0076 39       		.uleb128 0x39
 2449 0077 0B       		.uleb128 0xb
 2450 0078 6E       		.uleb128 0x6e
 2451 0079 08       		.uleb128 0x8
 2452 007a 49       		.uleb128 0x49
 2453 007b 13       		.uleb128 0x13
 2454 007c 3F       		.uleb128 0x3f
 2455 007d 19       		.uleb128 0x19
 2456 007e 3C       		.uleb128 0x3c
 2457 007f 19       		.uleb128 0x19
 2458 0080 00       		.byte	0
 2459 0081 00       		.byte	0
 2460 0082 0A       		.uleb128 0xa
 2461 0083 16       		.uleb128 0x16
 2462 0084 00       		.byte	0
 2463 0085 03       		.uleb128 0x3
 2464 0086 08       		.uleb128 0x8
 2465 0087 3A       		.uleb128 0x3a
 2466 0088 0B       		.uleb128 0xb
 2467 0089 3B       		.uleb128 0x3b
 2468 008a 0B       		.uleb128 0xb
 2469 008b 39       		.uleb128 0x39
 2470 008c 0B       		.uleb128 0xb
 2471 008d 49       		.uleb128 0x49
 2472 008e 13       		.uleb128 0x13
 2473 008f 00       		.byte	0
 2474 0090 00       		.byte	0
 2475 0091 0B       		.uleb128 0xb
 2476 0092 2E       		.uleb128 0x2e
 2477 0093 01       		.byte	0x1
 2478 0094 3F       		.uleb128 0x3f
 2479 0095 19       		.uleb128 0x19
 2480 0096 03       		.uleb128 0x3
 2481 0097 08       		.uleb128 0x8
 2482 0098 3A       		.uleb128 0x3a
 2483 0099 0B       		.uleb128 0xb
 2484 009a 3B       		.uleb128 0x3b
 2485 009b 0B       		.uleb128 0xb
 2486 009c 39       		.uleb128 0x39
 2487 009d 0B       		.uleb128 0xb
 2488 009e 6E       		.uleb128 0x6e
 2489 009f 08       		.uleb128 0x8
 2490 00a0 49       		.uleb128 0x49
 2491 00a1 13       		.uleb128 0x13
 2492 00a2 3C       		.uleb128 0x3c
 2493 00a3 19       		.uleb128 0x19
 2494 00a4 00       		.byte	0
 2495 00a5 00       		.byte	0
 2496 00a6 0C       		.uleb128 0xc
 2497 00a7 2F       		.uleb128 0x2f
 2498 00a8 00       		.byte	0
 2499 00a9 03       		.uleb128 0x3
 2500 00aa 08       		.uleb128 0x8
 2501 00ab 49       		.uleb128 0x49
 2502 00ac 13       		.uleb128 0x13
 2503 00ad 00       		.byte	0
 2504 00ae 00       		.byte	0
 2505 00af 0D       		.uleb128 0xd
 2506 00b0 05       		.uleb128 0x5
 2507 00b1 00       		.byte	0
 2508 00b2 49       		.uleb128 0x49
 2509 00b3 13       		.uleb128 0x13
 2510 00b4 00       		.byte	0
 2511 00b5 00       		.byte	0
 2512 00b6 0E       		.uleb128 0xe
 2513 00b7 39       		.uleb128 0x39
 2514 00b8 01       		.byte	0x1
 2515 00b9 03       		.uleb128 0x3
 2516 00ba 08       		.uleb128 0x8
 2517 00bb 3A       		.uleb128 0x3a
 2518 00bc 0B       		.uleb128 0xb
 2519 00bd 3B       		.uleb128 0x3b
 2520 00be 05       		.uleb128 0x5
 2521 00bf 39       		.uleb128 0x39
 2522 00c0 0B       		.uleb128 0xb
 2523 00c1 01       		.uleb128 0x1
 2524 00c2 13       		.uleb128 0x13
 2525 00c3 00       		.byte	0
 2526 00c4 00       		.byte	0
 2527 00c5 0F       		.uleb128 0xf
 2528 00c6 2E       		.uleb128 0x2e
 2529 00c7 01       		.byte	0x1
 2530 00c8 3F       		.uleb128 0x3f
 2531 00c9 19       		.uleb128 0x19
 2532 00ca 03       		.uleb128 0x3
 2533 00cb 08       		.uleb128 0x8
 2534 00cc 3A       		.uleb128 0x3a
 2535 00cd 0B       		.uleb128 0xb
 2536 00ce 3B       		.uleb128 0x3b
 2537 00cf 0B       		.uleb128 0xb
 2538 00d0 39       		.uleb128 0x39
 2539 00d1 0B       		.uleb128 0xb
 2540 00d2 6E       		.uleb128 0x6e
 2541 00d3 08       		.uleb128 0x8
 2542 00d4 49       		.uleb128 0x49
 2543 00d5 13       		.uleb128 0x13
 2544 00d6 3C       		.uleb128 0x3c
 2545 00d7 19       		.uleb128 0x19
 2546 00d8 01       		.uleb128 0x1
 2547 00d9 13       		.uleb128 0x13
 2548 00da 00       		.byte	0
 2549 00db 00       		.byte	0
 2550 00dc 10       		.uleb128 0x10
 2551 00dd 13       		.uleb128 0x13
 2552 00de 01       		.byte	0x1
 2553 00df 03       		.uleb128 0x3
 2554 00e0 08       		.uleb128 0x8
 2555 00e1 0B       		.uleb128 0xb
 2556 00e2 0B       		.uleb128 0xb
 2557 00e3 3A       		.uleb128 0x3a
 2558 00e4 0B       		.uleb128 0xb
 2559 00e5 3B       		.uleb128 0x3b
 2560 00e6 0B       		.uleb128 0xb
 2561 00e7 39       		.uleb128 0x39
 2562 00e8 0B       		.uleb128 0xb
 2563 00e9 01       		.uleb128 0x1
 2564 00ea 13       		.uleb128 0x13
 2565 00eb 00       		.byte	0
 2566 00ec 00       		.byte	0
 2567 00ed 11       		.uleb128 0x11
 2568 00ee 0D       		.uleb128 0xd
 2569 00ef 00       		.byte	0
 2570 00f0 03       		.uleb128 0x3
 2571 00f1 08       		.uleb128 0x8
 2572 00f2 3A       		.uleb128 0x3a
 2573 00f3 0B       		.uleb128 0xb
 2574 00f4 3B       		.uleb128 0x3b
 2575 00f5 0B       		.uleb128 0xb
 2576 00f6 39       		.uleb128 0x39
 2577 00f7 0B       		.uleb128 0xb
 2578 00f8 49       		.uleb128 0x49
 2579 00f9 13       		.uleb128 0x13
 2580 00fa 3F       		.uleb128 0x3f
 2581 00fb 19       		.uleb128 0x19
 2582 00fc 3C       		.uleb128 0x3c
 2583 00fd 19       		.uleb128 0x19
 2584 00fe 00       		.byte	0
 2585 00ff 00       		.byte	0
 2586 0100 12       		.uleb128 0x12
 2587 0101 24       		.uleb128 0x24
 2588 0102 00       		.byte	0
 2589 0103 0B       		.uleb128 0xb
 2590 0104 0B       		.uleb128 0xb
 2591 0105 3E       		.uleb128 0x3e
 2592 0106 0B       		.uleb128 0xb
 2593 0107 03       		.uleb128 0x3
 2594 0108 08       		.uleb128 0x8
 2595 0109 00       		.byte	0
 2596 010a 00       		.byte	0
 2597 010b 13       		.uleb128 0x13
 2598 010c 39       		.uleb128 0x39
 2599 010d 01       		.byte	0x1
 2600 010e 03       		.uleb128 0x3
 2601 010f 08       		.uleb128 0x8
 2602 0110 3A       		.uleb128 0x3a
 2603 0111 0B       		.uleb128 0xb
 2604 0112 3B       		.uleb128 0x3b
 2605 0113 0B       		.uleb128 0xb
 2606 0114 39       		.uleb128 0x39
 2607 0115 0B       		.uleb128 0xb
 2608 0116 01       		.uleb128 0x1
 2609 0117 13       		.uleb128 0x13
 2610 0118 00       		.byte	0
 2611 0119 00       		.byte	0
 2612 011a 14       		.uleb128 0x14
 2613 011b 3A       		.uleb128 0x3a
 2614 011c 00       		.byte	0
 2615 011d 3A       		.uleb128 0x3a
 2616 011e 0B       		.uleb128 0xb
 2617 011f 3B       		.uleb128 0x3b
 2618 0120 0B       		.uleb128 0xb
 2619 0121 39       		.uleb128 0x39
 2620 0122 0B       		.uleb128 0xb
 2621 0123 18       		.uleb128 0x18
 2622 0124 13       		.uleb128 0x13
 2623 0125 00       		.byte	0
 2624 0126 00       		.byte	0
 2625 0127 15       		.uleb128 0x15
 2626 0128 0F       		.uleb128 0xf
 2627 0129 00       		.byte	0
 2628 012a 0B       		.uleb128 0xb
 2629 012b 0B       		.uleb128 0xb
 2630 012c 03       		.uleb128 0x3
 2631 012d 08       		.uleb128 0x8
 2632 012e 49       		.uleb128 0x49
 2633 012f 13       		.uleb128 0x13
 2634 0130 00       		.byte	0
 2635 0131 00       		.byte	0
 2636 0132 16       		.uleb128 0x16
 2637 0133 0F       		.uleb128 0xf
 2638 0134 00       		.byte	0
 2639 0135 0B       		.uleb128 0xb
 2640 0136 0B       		.uleb128 0xb
 2641 0137 49       		.uleb128 0x49
 2642 0138 13       		.uleb128 0x13
 2643 0139 00       		.byte	0
 2644 013a 00       		.byte	0
 2645 013b 17       		.uleb128 0x17
 2646 013c 0D       		.uleb128 0xd
 2647 013d 00       		.byte	0
 2648 013e 03       		.uleb128 0x3
 2649 013f 08       		.uleb128 0x8
 2650 0140 3A       		.uleb128 0x3a
 2651 0141 0B       		.uleb128 0xb
 2652 0142 3B       		.uleb128 0x3b
 2653 0143 0B       		.uleb128 0xb
 2654 0144 39       		.uleb128 0x39
 2655 0145 0B       		.uleb128 0xb
 2656 0146 49       		.uleb128 0x49
 2657 0147 13       		.uleb128 0x13
 2658 0148 38       		.uleb128 0x38
 2659 0149 0B       		.uleb128 0xb
 2660 014a 00       		.byte	0
 2661 014b 00       		.byte	0
 2662 014c 18       		.uleb128 0x18
 2663 014d 34       		.uleb128 0x34
 2664 014e 00       		.byte	0
 2665 014f 03       		.uleb128 0x3
 2666 0150 08       		.uleb128 0x8
 2667 0151 3A       		.uleb128 0x3a
 2668 0152 0B       		.uleb128 0xb
 2669 0153 3B       		.uleb128 0x3b
 2670 0154 0B       		.uleb128 0xb
 2671 0155 39       		.uleb128 0x39
 2672 0156 0B       		.uleb128 0xb
 2673 0157 49       		.uleb128 0x49
 2674 0158 13       		.uleb128 0x13
 2675 0159 3F       		.uleb128 0x3f
 2676 015a 19       		.uleb128 0x19
 2677 015b 3C       		.uleb128 0x3c
 2678 015c 19       		.uleb128 0x19
 2679 015d 00       		.byte	0
 2680 015e 00       		.byte	0
 2681 015f 19       		.uleb128 0x19
 2682 0160 15       		.uleb128 0x15
 2683 0161 00       		.byte	0
 2684 0162 00       		.byte	0
 2685 0163 00       		.byte	0
 2686 0164 1A       		.uleb128 0x1a
 2687 0165 01       		.uleb128 0x1
 2688 0166 01       		.byte	0x1
 2689 0167 49       		.uleb128 0x49
 2690 0168 13       		.uleb128 0x13
 2691 0169 01       		.uleb128 0x1
 2692 016a 13       		.uleb128 0x13
 2693 016b 00       		.byte	0
 2694 016c 00       		.byte	0
 2695 016d 1B       		.uleb128 0x1b
 2696 016e 21       		.uleb128 0x21
 2697 016f 00       		.byte	0
 2698 0170 49       		.uleb128 0x49
 2699 0171 13       		.uleb128 0x13
 2700 0172 2F       		.uleb128 0x2f
 2701 0173 0B       		.uleb128 0xb
 2702 0174 00       		.byte	0
 2703 0175 00       		.byte	0
 2704 0176 1C       		.uleb128 0x1c
 2705 0177 34       		.uleb128 0x34
 2706 0178 00       		.byte	0
 2707 0179 03       		.uleb128 0x3
 2708 017a 08       		.uleb128 0x8
 2709 017b 3A       		.uleb128 0x3a
 2710 017c 0B       		.uleb128 0xb
 2711 017d 3B       		.uleb128 0x3b
 2712 017e 05       		.uleb128 0x5
 2713 017f 39       		.uleb128 0x39
 2714 0180 0B       		.uleb128 0xb
 2715 0181 49       		.uleb128 0x49
 2716 0182 13       		.uleb128 0x13
 2717 0183 3F       		.uleb128 0x3f
 2718 0184 19       		.uleb128 0x19
 2719 0185 3C       		.uleb128 0x3c
 2720 0186 19       		.uleb128 0x19
 2721 0187 00       		.byte	0
 2722 0188 00       		.byte	0
 2723 0189 1D       		.uleb128 0x1d
 2724 018a 13       		.uleb128 0x13
 2725 018b 01       		.byte	0x1
 2726 018c 0B       		.uleb128 0xb
 2727 018d 0B       		.uleb128 0xb
 2728 018e 3A       		.uleb128 0x3a
 2729 018f 0B       		.uleb128 0xb
 2730 0190 3B       		.uleb128 0x3b
 2731 0191 05       		.uleb128 0x5
 2732 0192 39       		.uleb128 0x39
 2733 0193 0B       		.uleb128 0xb
 2734 0194 6E       		.uleb128 0x6e
 2735 0195 08       		.uleb128 0x8
 2736 0196 01       		.uleb128 0x1
 2737 0197 13       		.uleb128 0x13
 2738 0198 00       		.byte	0
 2739 0199 00       		.byte	0
 2740 019a 1E       		.uleb128 0x1e
 2741 019b 0D       		.uleb128 0xd
 2742 019c 00       		.byte	0
 2743 019d 03       		.uleb128 0x3
 2744 019e 08       		.uleb128 0x8
 2745 019f 3A       		.uleb128 0x3a
 2746 01a0 0B       		.uleb128 0xb
 2747 01a1 3B       		.uleb128 0x3b
 2748 01a2 05       		.uleb128 0x5
 2749 01a3 39       		.uleb128 0x39
 2750 01a4 0B       		.uleb128 0xb
 2751 01a5 49       		.uleb128 0x49
 2752 01a6 13       		.uleb128 0x13
 2753 01a7 38       		.uleb128 0x38
 2754 01a8 0B       		.uleb128 0xb
 2755 01a9 00       		.byte	0
 2756 01aa 00       		.byte	0
 2757 01ab 1F       		.uleb128 0x1f
 2758 01ac 16       		.uleb128 0x16
 2759 01ad 00       		.byte	0
 2760 01ae 03       		.uleb128 0x3
 2761 01af 08       		.uleb128 0x8
 2762 01b0 3A       		.uleb128 0x3a
 2763 01b1 0B       		.uleb128 0xb
 2764 01b2 3B       		.uleb128 0x3b
 2765 01b3 05       		.uleb128 0x5
 2766 01b4 39       		.uleb128 0x39
 2767 01b5 0B       		.uleb128 0xb
 2768 01b6 49       		.uleb128 0x49
 2769 01b7 13       		.uleb128 0x13
 2770 01b8 00       		.byte	0
 2771 01b9 00       		.byte	0
 2772 01ba 20       		.uleb128 0x20
 2773 01bb 2E       		.uleb128 0x2e
 2774 01bc 01       		.byte	0x1
 2775 01bd 3F       		.uleb128 0x3f
 2776 01be 19       		.uleb128 0x19
 2777 01bf 03       		.uleb128 0x3
 2778 01c0 08       		.uleb128 0x8
 2779 01c1 3A       		.uleb128 0x3a
 2780 01c2 0B       		.uleb128 0xb
 2781 01c3 3B       		.uleb128 0x3b
 2782 01c4 05       		.uleb128 0x5
 2783 01c5 39       		.uleb128 0x39
 2784 01c6 0B       		.uleb128 0xb
 2785 01c7 49       		.uleb128 0x49
 2786 01c8 13       		.uleb128 0x13
 2787 01c9 3C       		.uleb128 0x3c
 2788 01ca 19       		.uleb128 0x19
 2789 01cb 01       		.uleb128 0x1
 2790 01cc 13       		.uleb128 0x13
 2791 01cd 00       		.byte	0
 2792 01ce 00       		.byte	0
 2793 01cf 21       		.uleb128 0x21
 2794 01d0 0F       		.uleb128 0xf
 2795 01d1 00       		.byte	0
 2796 01d2 0B       		.uleb128 0xb
 2797 01d3 0B       		.uleb128 0xb
 2798 01d4 00       		.byte	0
 2799 01d5 00       		.byte	0
 2800 01d6 22       		.uleb128 0x22
 2801 01d7 26       		.uleb128 0x26
 2802 01d8 00       		.byte	0
 2803 01d9 00       		.byte	0
 2804 01da 00       		.byte	0
 2805 01db 23       		.uleb128 0x23
 2806 01dc 15       		.uleb128 0x15
 2807 01dd 01       		.byte	0x1
 2808 01de 49       		.uleb128 0x49
 2809 01df 13       		.uleb128 0x13
 2810 01e0 01       		.uleb128 0x1
 2811 01e1 13       		.uleb128 0x13
 2812 01e2 00       		.byte	0
 2813 01e3 00       		.byte	0
 2814 01e4 24       		.uleb128 0x24
 2815 01e5 2E       		.uleb128 0x2e
 2816 01e6 01       		.byte	0x1
 2817 01e7 3F       		.uleb128 0x3f
 2818 01e8 19       		.uleb128 0x19
 2819 01e9 03       		.uleb128 0x3
 2820 01ea 08       		.uleb128 0x8
 2821 01eb 3A       		.uleb128 0x3a
 2822 01ec 0B       		.uleb128 0xb
 2823 01ed 3B       		.uleb128 0x3b
 2824 01ee 05       		.uleb128 0x5
 2825 01ef 39       		.uleb128 0x39
 2826 01f0 0B       		.uleb128 0xb
 2827 01f1 3C       		.uleb128 0x3c
 2828 01f2 19       		.uleb128 0x19
 2829 01f3 01       		.uleb128 0x1
 2830 01f4 13       		.uleb128 0x13
 2831 01f5 00       		.byte	0
 2832 01f6 00       		.byte	0
 2833 01f7 25       		.uleb128 0x25
 2834 01f8 2E       		.uleb128 0x2e
 2835 01f9 00       		.byte	0
 2836 01fa 3F       		.uleb128 0x3f
 2837 01fb 19       		.uleb128 0x19
 2838 01fc 03       		.uleb128 0x3
 2839 01fd 08       		.uleb128 0x8
 2840 01fe 3A       		.uleb128 0x3a
 2841 01ff 0B       		.uleb128 0xb
 2842 0200 3B       		.uleb128 0x3b
 2843 0201 05       		.uleb128 0x5
 2844 0202 39       		.uleb128 0x39
 2845 0203 0B       		.uleb128 0xb
 2846 0204 49       		.uleb128 0x49
 2847 0205 13       		.uleb128 0x13
 2848 0206 3C       		.uleb128 0x3c
 2849 0207 19       		.uleb128 0x19
 2850 0208 00       		.byte	0
 2851 0209 00       		.byte	0
 2852 020a 26       		.uleb128 0x26
 2853 020b 2E       		.uleb128 0x2e
 2854 020c 01       		.byte	0x1
 2855 020d 3F       		.uleb128 0x3f
 2856 020e 19       		.uleb128 0x19
 2857 020f 03       		.uleb128 0x3
 2858 0210 08       		.uleb128 0x8
 2859 0211 3A       		.uleb128 0x3a
 2860 0212 0B       		.uleb128 0xb
 2861 0213 3B       		.uleb128 0x3b
 2862 0214 05       		.uleb128 0x5
 2863 0215 39       		.uleb128 0x39
 2864 0216 0B       		.uleb128 0xb
 2865 0217 6E       		.uleb128 0x6e
 2866 0218 08       		.uleb128 0x8
 2867 0219 49       		.uleb128 0x49
 2868 021a 13       		.uleb128 0x13
 2869 021b 3C       		.uleb128 0x3c
 2870 021c 19       		.uleb128 0x19
 2871 021d 01       		.uleb128 0x1
 2872 021e 13       		.uleb128 0x13
 2873 021f 00       		.byte	0
 2874 0220 00       		.byte	0
 2875 0221 27       		.uleb128 0x27
 2876 0222 18       		.uleb128 0x18
 2877 0223 00       		.byte	0
 2878 0224 00       		.byte	0
 2879 0225 00       		.byte	0
 2880 0226 28       		.uleb128 0x28
 2881 0227 2E       		.uleb128 0x2e
 2882 0228 01       		.byte	0x1
 2883 0229 3F       		.uleb128 0x3f
 2884 022a 19       		.uleb128 0x19
 2885 022b 03       		.uleb128 0x3
 2886 022c 08       		.uleb128 0x8
 2887 022d 3A       		.uleb128 0x3a
 2888 022e 0B       		.uleb128 0xb
 2889 022f 3B       		.uleb128 0x3b
 2890 0230 05       		.uleb128 0x5
 2891 0231 39       		.uleb128 0x39
 2892 0232 0B       		.uleb128 0xb
 2893 0233 6E       		.uleb128 0x6e
 2894 0234 08       		.uleb128 0x8
 2895 0235 49       		.uleb128 0x49
 2896 0236 13       		.uleb128 0x13
 2897 0237 11       		.uleb128 0x11
 2898 0238 01       		.uleb128 0x1
 2899 0239 12       		.uleb128 0x12
 2900 023a 07       		.uleb128 0x7
 2901 023b 40       		.uleb128 0x40
 2902 023c 18       		.uleb128 0x18
 2903 023d 9642     		.uleb128 0x2116
 2904 023f 19       		.uleb128 0x19
 2905 0240 01       		.uleb128 0x1
 2906 0241 13       		.uleb128 0x13
 2907 0242 00       		.byte	0
 2908 0243 00       		.byte	0
 2909 0244 29       		.uleb128 0x29
 2910 0245 05       		.uleb128 0x5
 2911 0246 00       		.byte	0
 2912 0247 03       		.uleb128 0x3
 2913 0248 0E       		.uleb128 0xe
 2914 0249 3A       		.uleb128 0x3a
 2915 024a 0B       		.uleb128 0xb
 2916 024b 3B       		.uleb128 0x3b
 2917 024c 05       		.uleb128 0x5
 2918 024d 39       		.uleb128 0x39
 2919 024e 0B       		.uleb128 0xb
 2920 024f 49       		.uleb128 0x49
 2921 0250 13       		.uleb128 0x13
 2922 0251 02       		.uleb128 0x2
 2923 0252 18       		.uleb128 0x18
 2924 0253 00       		.byte	0
 2925 0254 00       		.byte	0
 2926 0255 2A       		.uleb128 0x2a
 2927 0256 34       		.uleb128 0x34
 2928 0257 00       		.byte	0
 2929 0258 03       		.uleb128 0x3
 2930 0259 0E       		.uleb128 0xe
 2931 025a 3A       		.uleb128 0x3a
 2932 025b 0B       		.uleb128 0xb
 2933 025c 3B       		.uleb128 0x3b
 2934 025d 05       		.uleb128 0x5
 2935 025e 39       		.uleb128 0x39
 2936 025f 0B       		.uleb128 0xb
 2937 0260 49       		.uleb128 0x49
 2938 0261 13       		.uleb128 0x13
 2939 0262 02       		.uleb128 0x2
 2940 0263 18       		.uleb128 0x18
 2941 0264 00       		.byte	0
 2942 0265 00       		.byte	0
 2943 0266 2B       		.uleb128 0x2b
 2944 0267 898201   		.uleb128 0x4109
 2945 026a 00       		.byte	0
 2946 026b 11       		.uleb128 0x11
 2947 026c 01       		.uleb128 0x1
 2948 026d 31       		.uleb128 0x31
 2949 026e 13       		.uleb128 0x13
 2950 026f 00       		.byte	0
 2951 0270 00       		.byte	0
 2952 0271 2C       		.uleb128 0x2c
 2953 0272 34       		.uleb128 0x34
 2954 0273 00       		.byte	0
 2955 0274 03       		.uleb128 0x3
 2956 0275 08       		.uleb128 0x8
 2957 0276 3A       		.uleb128 0x3a
 2958 0277 0B       		.uleb128 0xb
 2959 0278 3B       		.uleb128 0x3b
 2960 0279 0B       		.uleb128 0xb
 2961 027a 39       		.uleb128 0x39
 2962 027b 0B       		.uleb128 0xb
 2963 027c 49       		.uleb128 0x49
 2964 027d 13       		.uleb128 0x13
 2965 027e 02       		.uleb128 0x2
 2966 027f 18       		.uleb128 0x18
 2967 0280 00       		.byte	0
 2968 0281 00       		.byte	0
 2969 0282 2D       		.uleb128 0x2d
 2970 0283 34       		.uleb128 0x34
 2971 0284 00       		.byte	0
 2972 0285 03       		.uleb128 0x3
 2973 0286 08       		.uleb128 0x8
 2974 0287 3A       		.uleb128 0x3a
 2975 0288 0B       		.uleb128 0xb
 2976 0289 3B       		.uleb128 0x3b
 2977 028a 0B       		.uleb128 0xb
 2978 028b 39       		.uleb128 0x39
 2979 028c 0B       		.uleb128 0xb
 2980 028d 49       		.uleb128 0x49
 2981 028e 13       		.uleb128 0x13
 2982 028f 3F       		.uleb128 0x3f
 2983 0290 19       		.uleb128 0x19
 2984 0291 02       		.uleb128 0x2
 2985 0292 18       		.uleb128 0x18
 2986 0293 00       		.byte	0
 2987 0294 00       		.byte	0
 2988 0295 2E       		.uleb128 0x2e
 2989 0296 34       		.uleb128 0x34
 2990 0297 00       		.byte	0
 2991 0298 6E       		.uleb128 0x6e
 2992 0299 08       		.uleb128 0x8
 2993 029a 47       		.uleb128 0x47
 2994 029b 13       		.uleb128 0x13
 2995 029c 1C       		.uleb128 0x1c
 2996 029d 07       		.uleb128 0x7
 2997 029e 00       		.byte	0
 2998 029f 00       		.byte	0
 2999 02a0 2F       		.uleb128 0x2f
 3000 02a1 10       		.uleb128 0x10
 3001 02a2 00       		.byte	0
 3002 02a3 0B       		.uleb128 0xb
 3003 02a4 0B       		.uleb128 0xb
 3004 02a5 49       		.uleb128 0x49
 3005 02a6 13       		.uleb128 0x13
 3006 02a7 00       		.byte	0
 3007 02a8 00       		.byte	0
 3008 02a9 30       		.uleb128 0x30
 3009 02aa 2E       		.uleb128 0x2e
 3010 02ab 01       		.byte	0x1
 3011 02ac 47       		.uleb128 0x47
 3012 02ad 13       		.uleb128 0x13
 3013 02ae 11       		.uleb128 0x11
 3014 02af 01       		.uleb128 0x1
 3015 02b0 12       		.uleb128 0x12
 3016 02b1 07       		.uleb128 0x7
 3017 02b2 40       		.uleb128 0x40
 3018 02b3 18       		.uleb128 0x18
 3019 02b4 9742     		.uleb128 0x2117
 3020 02b6 19       		.uleb128 0x19
 3021 02b7 01       		.uleb128 0x1
 3022 02b8 13       		.uleb128 0x13
 3023 02b9 00       		.byte	0
 3024 02ba 00       		.byte	0
 3025 02bb 31       		.uleb128 0x31
 3026 02bc 05       		.uleb128 0x5
 3027 02bd 00       		.byte	0
 3028 02be 03       		.uleb128 0x3
 3029 02bf 08       		.uleb128 0x8
 3030 02c0 3A       		.uleb128 0x3a
 3031 02c1 0B       		.uleb128 0xb
 3032 02c2 3B       		.uleb128 0x3b
 3033 02c3 0B       		.uleb128 0xb
 3034 02c4 39       		.uleb128 0x39
 3035 02c5 0B       		.uleb128 0xb
 3036 02c6 49       		.uleb128 0x49
 3037 02c7 13       		.uleb128 0x13
 3038 02c8 02       		.uleb128 0x2
 3039 02c9 18       		.uleb128 0x18
 3040 02ca 00       		.byte	0
 3041 02cb 00       		.byte	0
 3042 02cc 32       		.uleb128 0x32
 3043 02cd 2E       		.uleb128 0x2e
 3044 02ce 01       		.byte	0x1
 3045 02cf 3F       		.uleb128 0x3f
 3046 02d0 19       		.uleb128 0x19
 3047 02d1 03       		.uleb128 0x3
 3048 02d2 08       		.uleb128 0x8
 3049 02d3 3A       		.uleb128 0x3a
 3050 02d4 0B       		.uleb128 0xb
 3051 02d5 3B       		.uleb128 0x3b
 3052 02d6 0B       		.uleb128 0xb
 3053 02d7 39       		.uleb128 0x39
 3054 02d8 0B       		.uleb128 0xb
 3055 02d9 49       		.uleb128 0x49
 3056 02da 13       		.uleb128 0x13
 3057 02db 11       		.uleb128 0x11
 3058 02dc 01       		.uleb128 0x1
 3059 02dd 12       		.uleb128 0x12
 3060 02de 07       		.uleb128 0x7
 3061 02df 40       		.uleb128 0x40
 3062 02e0 18       		.uleb128 0x18
 3063 02e1 9642     		.uleb128 0x2116
 3064 02e3 19       		.uleb128 0x19
 3065 02e4 01       		.uleb128 0x1
 3066 02e5 13       		.uleb128 0x13
 3067 02e6 00       		.byte	0
 3068 02e7 00       		.byte	0
 3069 02e8 33       		.uleb128 0x33
 3070 02e9 0B       		.uleb128 0xb
 3071 02ea 01       		.byte	0x1
 3072 02eb 11       		.uleb128 0x11
 3073 02ec 01       		.uleb128 0x1
 3074 02ed 12       		.uleb128 0x12
 3075 02ee 07       		.uleb128 0x7
 3076 02ef 00       		.byte	0
 3077 02f0 00       		.byte	0
 3078 02f1 34       		.uleb128 0x34
 3079 02f2 2E       		.uleb128 0x2e
 3080 02f3 00       		.byte	0
 3081 02f4 3F       		.uleb128 0x3f
 3082 02f5 19       		.uleb128 0x19
 3083 02f6 3C       		.uleb128 0x3c
 3084 02f7 19       		.uleb128 0x19
 3085 02f8 6E       		.uleb128 0x6e
 3086 02f9 0E       		.uleb128 0xe
 3087 02fa 03       		.uleb128 0x3
 3088 02fb 0E       		.uleb128 0xe
 3089 02fc 3A       		.uleb128 0x3a
 3090 02fd 0B       		.uleb128 0xb
 3091 02fe 3B       		.uleb128 0x3b
 3092 02ff 0B       		.uleb128 0xb
 3093 0300 39       		.uleb128 0x39
 3094 0301 0B       		.uleb128 0xb
 3095 0302 00       		.byte	0
 3096 0303 00       		.byte	0
 3097 0304 00       		.byte	0
 3098              		.section	.debug_aranges,"dr"
 3099 0000 5C000000 		.long	0x5c
 3100 0004 0200     		.word	0x2
 3101 0006 00000000 		.secrel32	.Ldebug_info0
 3102 000a 08       		.byte	0x8
 3103 000b 00       		.byte	0
 3104 000c 0000     		.word	0
 3105 000e 0000     		.word	0
 3106 0010 00000000 		.quad	.Ltext0
 3106      00000000 
 3107 0018 04010000 		.quad	.Letext0-.Ltext0
 3107      00000000 
 3108 0020 00000000 		.quad	.LFB476
 3108      00000000 
 3109 0028 54000000 		.quad	.LFE476-.LFB476
 3109      00000000 
 3110 0030 00000000 		.quad	.LFB482
 3110      00000000 
 3111 0038 54000000 		.quad	.LFE482-.LFB482
 3111      00000000 
 3112 0040 00000000 		.quad	.LFB519
 3112      00000000 
 3113 0048 28000000 		.quad	.LFE519-.LFB519
 3113      00000000 
 3114 0050 00000000 		.quad	0
 3114      00000000 
 3115 0058 00000000 		.quad	0
 3115      00000000 
 3116              		.section	.debug_ranges,"dr"
 3117              	.Ldebug_ranges0:
 3118 0000 00000000 		.quad	.Ltext0
 3118      00000000 
 3119 0008 04010000 		.quad	.Letext0
 3119      00000000 
 3120 0010 00000000 		.quad	.LFB476
 3120      00000000 
 3121 0018 54000000 		.quad	.LFE476
 3121      00000000 
 3122 0020 00000000 		.quad	.LFB482
 3122      00000000 
 3123 0028 54000000 		.quad	.LFE482
 3123      00000000 
 3124 0030 00000000 		.quad	.LFB519
 3124      00000000 
 3125 0038 28000000 		.quad	.LFE519
 3125      00000000 
 3126 0040 00000000 		.quad	0
 3126      00000000 
 3127 0048 00000000 		.quad	0
 3127      00000000 
 3128              		.section	.debug_line,"dr"
 3129              	.Ldebug_line0:
 3130 0000 C5040000 		.section	.debug_str,"dr"
 3130      0200CD03 
 3130      00000101 
 3130      FB0E0D00 
 3130      01010101 
 3131              	.LASF3:
 3132 0000 5F5F6163 		.ascii "__acrt_iob_func\0"
 3132      72745F69 
 3132      6F625F66 
 3132      756E6300 
 3133              	.LASF0:
 3134 0010 5F5F7265 		.ascii "__retval\0"
 3134      7476616C 
 3134      00
 3135              	.LASF2:
 3136 0019 5F5F666F 		.ascii "__format\0"
 3136      726D6174 
 3136      00
 3137              	.LASF1:
 3138 0022 5F5F6C6F 		.ascii "__local_argv\0"
 3138      63616C5F 
 3138      61726776 
 3138      00
 3139              		.ident	"GCC: (x86_64-win32-seh-rev0, Built by MinGW-W64 project) 8.1.0"
