   1              		.file	"19_1.cpp"
   2              		.text
   3              	.Ltext0:
   4              		.cfi_sections	.debug_frame
   5              		.section	.text$_Z5scanfPKcz,"x"
   6              		.linkonce discard
   7              		.globl	_Z5scanfPKcz
   9              		.seh_proc	_Z5scanfPKcz
  10              	_Z5scanfPKcz:
  11              	.LFB2:
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
  59              	.LFE2:
  60              		.seh_endproc
  61 0054 90909090 		.section .rdata,"dr"
  61      90909090 
  61      90909090 
  62              		.align 4
  63              	_ZL1N:
  64 0000 1F000000 		.long	31
  65              		.globl	f
  66              		.bss
  67              		.align 32
  68              	f:
  69 0000 00000000 		.space 124
  69      00000000 
  69      00000000 
  69      00000000 
  69      00000000 
  70 007c 00000000 		.text
  71              		.globl	_Z5solveii
  73              		.seh_proc	_Z5solveii
  74              	_Z5solveii:
  75              	.LFB44:
  76              		.file 2 "C++/Moo/19_1.cpp"
   1:C++/Moo/19_1.cpp **** #include <cstdio>
   2:C++/Moo/19_1.cpp **** 
   3:C++/Moo/19_1.cpp **** const int N = 31;
   4:C++/Moo/19_1.cpp **** int f[N];
   5:C++/Moo/19_1.cpp **** 
   6:C++/Moo/19_1.cpp **** char solve(int s, int k)
   7:C++/Moo/19_1.cpp **** {
  77              		.loc 2 7 1
  78              		.cfi_startproc
  79 0000 55       		pushq	%rbp
  80              		.seh_pushreg	%rbp
  81              		.cfi_def_cfa_offset 16
  82              		.cfi_offset 6, -16
  83 0001 4889E5   		movq	%rsp, %rbp
  84              		.seh_setframe	%rbp, 0
  85              		.cfi_def_cfa_register 6
  86 0004 4883EC30 		subq	$48, %rsp
  87              		.seh_stackalloc	48
  88              		.seh_endprologue
  89 0008 894D10   		movl	%ecx, 16(%rbp)
  90 000b 895518   		movl	%edx, 24(%rbp)
   8:C++/Moo/19_1.cpp **** 	if (k <= f[s - 1]) return solve(s - 1, k);
  91              		.loc 2 8 15
  92 000e 8B4510   		movl	16(%rbp), %eax
  93 0011 83E801   		subl	$1, %eax
  94              		.loc 2 8 18
  95 0014 4898     		cltq
  96 0016 488D1485 		leaq	0(,%rax,4), %rdx
  96      00000000 
  97 001e 488D0500 		leaq	f(%rip), %rax
  97      000000
  98 0025 8B0402   		movl	(%rdx,%rax), %eax
  99              		.loc 2 8 2
 100 0028 394518   		cmpl	%eax, 24(%rbp)
 101 002b 7F12     		jg	.L4
 102              		.loc 2 8 33 discriminator 1
 103 002d 8B4510   		movl	16(%rbp), %eax
 104 0030 83E801   		subl	$1, %eax
 105 0033 8B5518   		movl	24(%rbp), %edx
 106 0036 89C1     		movl	%eax, %ecx
 107 0038 E8C3FFFF 		call	_Z5solveii
 107      FF
 108              		.loc 2 8 42 discriminator 1
 109 003d EB5C     		jmp	.L5
 110              	.L4:
   9:C++/Moo/19_1.cpp **** 	int tmp = k - f[s - 1];
 111              		.loc 2 9 20
 112 003f 8B4510   		movl	16(%rbp), %eax
 113 0042 83E801   		subl	$1, %eax
 114              		.loc 2 9 23
 115 0045 4898     		cltq
 116 0047 488D1485 		leaq	0(,%rax,4), %rdx
 116      00000000 
 117 004f 488D0500 		leaq	f(%rip), %rax
 117      000000
 118 0056 8B0402   		movl	(%rdx,%rax), %eax
 119              		.loc 2 9 6
 120 0059 8B5518   		movl	24(%rbp), %edx
 121 005c 29C2     		subl	%eax, %edx
 122 005e 89D0     		movl	%edx, %eax
 123 0060 8945FC   		movl	%eax, -4(%rbp)
  10:C++/Moo/19_1.cpp **** 	if (tmp <= s + 3) return tmp == 1 ? 'm' : 'o';
 124              		.loc 2 10 15
 125 0063 8B4510   		movl	16(%rbp), %eax
 126 0066 83C003   		addl	$3, %eax
 127              		.loc 2 10 2
 128 0069 3945FC   		cmpl	%eax, -4(%rbp)
 129 006c 7F14     		jg	.L6
 130              		.loc 2 10 36 discriminator 1
 131 006e 837DFC01 		cmpl	$1, -4(%rbp)
 132 0072 7507     		jne	.L7
 133              		.loc 2 10 36 is_stmt 0 discriminator 2
 134 0074 B86D0000 		movl	$109, %eax
 134      00
 135              		.loc 2 10 44 is_stmt 1 discriminator 2
 136 0079 EB20     		jmp	.L5
 137              	.L7:
 138              		.loc 2 10 36 discriminator 3
 139 007b B86F0000 		movl	$111, %eax
 139      00
 140              		.loc 2 10 44 discriminator 3
 141 0080 EB19     		jmp	.L5
 142              	.L6:
  11:C++/Moo/19_1.cpp **** 	return solve(s - 1, tmp - (s + 3));
 143              		.loc 2 11 31
 144 0082 8B4510   		movl	16(%rbp), %eax
 145 0085 83C003   		addl	$3, %eax
 146              		.loc 2 11 14
 147 0088 8B55FC   		movl	-4(%rbp), %edx
 148 008b 29C2     		subl	%eax, %edx
 149 008d 8B4510   		movl	16(%rbp), %eax
 150 0090 83E801   		subl	$1, %eax
 151 0093 89C1     		movl	%eax, %ecx
 152 0095 E866FFFF 		call	_Z5solveii
 152      FF
 153              		.loc 2 11 35
 154 009a 90       		nop
 155              	.L5:
  12:C++/Moo/19_1.cpp **** }
 156              		.loc 2 12 1
 157 009b 4883C430 		addq	$48, %rsp
 158 009f 5D       		popq	%rbp
 159              		.cfi_restore 6
 160              		.cfi_def_cfa 7, 8
 161 00a0 C3       		ret
 162              		.cfi_endproc
 163              	.LFE44:
 164              		.seh_endproc
 166              		.section .rdata,"dr"
 167              	.LC0:
 168 0004 256400   		.ascii "%d\0"
 169 0007 00000000 		.text
 169      00000000 
 169      00
 170              		.globl	main
 172              		.seh_proc	main
 173              	main:
 174              	.LFB45:
  13:C++/Moo/19_1.cpp **** 
  14:C++/Moo/19_1.cpp **** int main()
  15:C++/Moo/19_1.cpp **** {
 175              		.loc 2 15 1
 176              		.cfi_startproc
 177 00a1 55       		pushq	%rbp
 178              		.seh_pushreg	%rbp
 179              		.cfi_def_cfa_offset 16
 180              		.cfi_offset 6, -16
 181 00a2 4889E5   		movq	%rsp, %rbp
 182              		.seh_setframe	%rbp, 0
 183              		.cfi_def_cfa_register 6
 184 00a5 4883EC30 		subq	$48, %rsp
 185              		.seh_stackalloc	48
 186              		.seh_endprologue
 187              		.loc 2 15 1
 188 00a9 E8000000 		call	__main
 188      00
 189              	.LVL1:
  16:C++/Moo/19_1.cpp **** 	int n;
  17:C++/Moo/19_1.cpp **** 	scanf("%d", &n);
 190              		.loc 2 17 7
 191 00ae 488D45F8 		leaq	-8(%rbp), %rax
 192 00b2 4889C2   		movq	%rax, %rdx
 193 00b5 488D0D04 		leaq	.LC0(%rip), %rcx
 193      000000
 194 00bc E8000000 		call	_Z5scanfPKcz
 194      00
  18:C++/Moo/19_1.cpp **** 	f[0] = 3;
 195              		.loc 2 18 7
 196 00c1 C705FCFF 		movl	$3, f(%rip)
 196      FFFF0300 
 196      0000
  19:C++/Moo/19_1.cpp **** 	int i;
  20:C++/Moo/19_1.cpp **** 	for (i = 1; f[i - 1] < n; ++i) f[i] = i + 3 + (f[i - 1] << 1);
 197              		.loc 2 20 9
 198 00cb C745FC01 		movl	$1, -4(%rbp)
 198      000000
 199              	.L11:
 200              		.loc 2 20 18 discriminator 3
 201 00d2 8B45FC   		movl	-4(%rbp), %eax
 202 00d5 83E801   		subl	$1, %eax
 203              		.loc 2 20 21 discriminator 3
 204 00d8 4898     		cltq
 205 00da 488D1485 		leaq	0(,%rax,4), %rdx
 205      00000000 
 206 00e2 488D0500 		leaq	f(%rip), %rax
 206      000000
 207 00e9 8B1402   		movl	(%rdx,%rax), %edx
 208              		.loc 2 20 23 discriminator 3
 209 00ec 8B45F8   		movl	-8(%rbp), %eax
 210 00ef 39C2     		cmpl	%eax, %edx
 211 00f1 7D41     		jge	.L10
 212              		.loc 2 20 42 discriminator 2
 213 00f3 8B45FC   		movl	-4(%rbp), %eax
 214 00f6 8D4803   		leal	3(%rax), %ecx
 215              		.loc 2 20 53 discriminator 2
 216 00f9 8B45FC   		movl	-4(%rbp), %eax
 217 00fc 83E801   		subl	$1, %eax
 218              		.loc 2 20 56 discriminator 2
 219 00ff 4898     		cltq
 220 0101 488D1485 		leaq	0(,%rax,4), %rdx
 220      00000000 
 221 0109 488D0500 		leaq	f(%rip), %rax
 221      000000
 222 0110 8B0402   		movl	(%rdx,%rax), %eax
 223              		.loc 2 20 58 discriminator 2
 224 0113 01C0     		addl	%eax, %eax
 225              		.loc 2 20 46 discriminator 2
 226 0115 01C1     		addl	%eax, %ecx
 227              		.loc 2 20 38 discriminator 2
 228 0117 8B45FC   		movl	-4(%rbp), %eax
 229 011a 4898     		cltq
 230 011c 488D1485 		leaq	0(,%rax,4), %rdx
 230      00000000 
 231 0124 488D0500 		leaq	f(%rip), %rax
 231      000000
 232 012b 890C02   		movl	%ecx, (%rdx,%rax)
 233              		.loc 2 20 2 discriminator 2
 234 012e 8345FC01 		addl	$1, -4(%rbp)
 235 0132 EB9E     		jmp	.L11
 236              	.L10:
  21:C++/Moo/19_1.cpp **** 	putchar(solve(i - 1, n));
 237              		.loc 2 21 15
 238 0134 8B55F8   		movl	-8(%rbp), %edx
 239 0137 8B45FC   		movl	-4(%rbp), %eax
 240 013a 83E801   		subl	$1, %eax
 241 013d 89C1     		movl	%eax, %ecx
 242 013f E8BCFEFF 		call	_Z5solveii
 242      FF
 243              		.loc 2 21 9
 244 0144 0FBEC0   		movsbl	%al, %eax
 245 0147 89C1     		movl	%eax, %ecx
 246 0149 E8000000 		call	putchar
 246      00
  22:C++/Moo/19_1.cpp **** 	return 0;
 247              		.loc 2 22 9
 248 014e B8000000 		movl	$0, %eax
 248      00
  23:C++/Moo/19_1.cpp **** }...
 249              		.loc 2 23 1
 250 0153 4883C430 		addq	$48, %rsp
 251 0157 5D       		popq	%rbp
 252              		.cfi_restore 6
 253              		.cfi_def_cfa 7, 8
 254 0158 C3       		ret
 255              		.cfi_endproc
 256              	.LFE45:
 257              		.seh_endproc
 258              	.Letext0:
 259              		.file 3 "C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-m
 260              		.file 4 "C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-m
 261              		.file 5 "C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/i
 262              		.file 6 "<built-in>"
 263 0159 90909090 		.section	.debug_info,"dr"
 263      909090
 264              	.Ldebug_info0:
 265 0000 C70A0000 		.long	0xac7
 266 0004 0400     		.word	0x4
 267 0006 00000000 		.secrel32	.Ldebug_abbrev0
 268 000a 08       		.byte	0x8
 269 000b 01       		.uleb128 0x1
 270 000c 474E5520 		.ascii "GNU C++98 8.1.0 -mtune=core2 -march=nocona -g -std=gnu++98\0"
 270      432B2B39 
 270      3820382E 
 270      312E3020 
 270      2D6D7475 
 271 0047 04       		.byte	0x4
 272 0048 432B2B2F 		.ascii "C++/Moo/19_1.cpp\0"
 272      4D6F6F2F 
 272      31395F31 
 272      2E637070 
 272      00
 273 0059 453A5C63 		.ascii "E:\\code\0"
 273      6F646500 
 274 0061 00000000 		.secrel32	.Ldebug_ranges0+0
 275 0065 00000000 		.quad	0
 275      00000000 
 276 006d 00000000 		.secrel32	.Ldebug_line0
 277 0071 02       		.uleb128 0x2
 278 0072 73746400 		.ascii "std\0"
 279 0076 06       		.byte	0x6
 280 0077 00       		.byte	0
 281 0078 E3010000 		.long	0x1e3
 282 007c 03       		.uleb128 0x3
 283 007d 5F5F6378 		.ascii "__cxx11\0"
 283      78313100 
 284 0085 04       		.byte	0x4
 285 0086 0401     		.word	0x104
 286 0088 41       		.byte	0x41
 287 0089 04       		.uleb128 0x4
 288 008a 04       		.byte	0x4
 289 008b 0401     		.word	0x104
 290 008d 41       		.byte	0x41
 291 008e 7C000000 		.long	0x7c
 292 0092 05       		.uleb128 0x5
 293 0093 03       		.byte	0x3
 294 0094 62       		.byte	0x62
 295 0095 0B       		.byte	0xb
 296 0096 99030000 		.long	0x399
 297 009a 05       		.uleb128 0x5
 298 009b 03       		.byte	0x3
 299 009c 63       		.byte	0x63
 300 009d 0B       		.byte	0xb
 301 009e A6030000 		.long	0x3a6
 302 00a2 05       		.uleb128 0x5
 303 00a3 03       		.byte	0x3
 304 00a4 65       		.byte	0x65
 305 00a5 0B       		.byte	0xb
 306 00a6 BA030000 		.long	0x3ba
 307 00aa 05       		.uleb128 0x5
 308 00ab 03       		.byte	0x3
 309 00ac 66       		.byte	0x66
 310 00ad 0B       		.byte	0xb
 311 00ae D8030000 		.long	0x3d8
 312 00b2 05       		.uleb128 0x5
 313 00b3 03       		.byte	0x3
 314 00b4 67       		.byte	0x67
 315 00b5 0B       		.byte	0xb
 316 00b6 F2030000 		.long	0x3f2
 317 00ba 05       		.uleb128 0x5
 318 00bb 03       		.byte	0x3
 319 00bc 68       		.byte	0x68
 320 00bd 0B       		.byte	0xb
 321 00be 0A040000 		.long	0x40a
 322 00c2 05       		.uleb128 0x5
 323 00c3 03       		.byte	0x3
 324 00c4 69       		.byte	0x69
 325 00c5 0B       		.byte	0xb
 326 00c6 24040000 		.long	0x424
 327 00ca 05       		.uleb128 0x5
 328 00cb 03       		.byte	0x3
 329 00cc 6A       		.byte	0x6a
 330 00cd 0B       		.byte	0xb
 331 00ce 3E040000 		.long	0x43e
 332 00d2 05       		.uleb128 0x5
 333 00d3 03       		.byte	0x3
 334 00d4 6B       		.byte	0x6b
 335 00d5 0B       		.byte	0xb
 336 00d6 57040000 		.long	0x457
 337 00da 05       		.uleb128 0x5
 338 00db 03       		.byte	0x3
 339 00dc 6C       		.byte	0x6c
 340 00dd 0B       		.byte	0xb
 341 00de 7D040000 		.long	0x47d
 342 00e2 05       		.uleb128 0x5
 343 00e3 03       		.byte	0x3
 344 00e4 6D       		.byte	0x6d
 345 00e5 0B       		.byte	0xb
 346 00e6 A0040000 		.long	0x4a0
 347 00ea 05       		.uleb128 0x5
 348 00eb 03       		.byte	0x3
 349 00ec 6E       		.byte	0x6e
 350 00ed 0B       		.byte	0xb
 351 00ee C4040000 		.long	0x4c4
 352 00f2 05       		.uleb128 0x5
 353 00f3 03       		.byte	0x3
 354 00f4 71       		.byte	0x71
 355 00f5 0B       		.byte	0xb
 356 00f6 FC040000 		.long	0x4fc
 357 00fa 05       		.uleb128 0x5
 358 00fb 03       		.byte	0x3
 359 00fc 72       		.byte	0x72
 360 00fd 0B       		.byte	0xb
 361 00fe 26050000 		.long	0x526
 362 0102 05       		.uleb128 0x5
 363 0103 03       		.byte	0x3
 364 0104 73       		.byte	0x73
 365 0105 0B       		.byte	0xb
 366 0106 4B050000 		.long	0x54b
 367 010a 05       		.uleb128 0x5
 368 010b 03       		.byte	0x3
 369 010c 74       		.byte	0x74
 370 010d 0B       		.byte	0xb
 371 010e 81050000 		.long	0x581
 372 0112 05       		.uleb128 0x5
 373 0113 03       		.byte	0x3
 374 0114 75       		.byte	0x75
 375 0115 0B       		.byte	0xb
 376 0116 A4050000 		.long	0x5a4
 377 011a 05       		.uleb128 0x5
 378 011b 03       		.byte	0x3
 379 011c 76       		.byte	0x76
 380 011d 0B       		.byte	0xb
 381 011e CA050000 		.long	0x5ca
 382 0122 05       		.uleb128 0x5
 383 0123 03       		.byte	0x3
 384 0124 78       		.byte	0x78
 385 0125 0B       		.byte	0xb
 386 0126 E3050000 		.long	0x5e3
 387 012a 05       		.uleb128 0x5
 388 012b 03       		.byte	0x3
 389 012c 79       		.byte	0x79
 390 012d 0B       		.byte	0xb
 391 012e FB050000 		.long	0x5fb
 392 0132 05       		.uleb128 0x5
 393 0133 03       		.byte	0x3
 394 0134 7C       		.byte	0x7c
 395 0135 0B       		.byte	0xb
 396 0136 0C060000 		.long	0x60c
 397 013a 05       		.uleb128 0x5
 398 013b 03       		.byte	0x3
 399 013c 7E       		.byte	0x7e
 400 013d 0B       		.byte	0xb
 401 013e 24060000 		.long	0x624
 402 0142 05       		.uleb128 0x5
 403 0143 03       		.byte	0x3
 404 0144 7F       		.byte	0x7f
 405 0145 0B       		.byte	0xb
 406 0146 3A060000 		.long	0x63a
 407 014a 05       		.uleb128 0x5
 408 014b 03       		.byte	0x3
 409 014c 83       		.byte	0x83
 410 014d 0B       		.byte	0xb
 411 014e 63060000 		.long	0x663
 412 0152 05       		.uleb128 0x5
 413 0153 03       		.byte	0x3
 414 0154 84       		.byte	0x84
 415 0155 0B       		.byte	0xb
 416 0156 7D060000 		.long	0x67d
 417 015a 05       		.uleb128 0x5
 418 015b 03       		.byte	0x3
 419 015c 85       		.byte	0x85
 420 015d 0B       		.byte	0xb
 421 015e 9C060000 		.long	0x69c
 422 0162 05       		.uleb128 0x5
 423 0163 03       		.byte	0x3
 424 0164 86       		.byte	0x86
 425 0165 0B       		.byte	0xb
 426 0166 B2060000 		.long	0x6b2
 427 016a 05       		.uleb128 0x5
 428 016b 03       		.byte	0x3
 429 016c 87       		.byte	0x87
 430 016d 0B       		.byte	0xb
 431 016e 37070000 		.long	0x737
 432 0172 05       		.uleb128 0x5
 433 0173 03       		.byte	0x3
 434 0174 88       		.byte	0x88
 435 0175 0B       		.byte	0xb
 436 0176 52070000 		.long	0x752
 437 017a 05       		.uleb128 0x5
 438 017b 03       		.byte	0x3
 439 017c 89       		.byte	0x89
 440 017d 0B       		.byte	0xb
 441 017e 7C070000 		.long	0x77c
 442 0182 05       		.uleb128 0x5
 443 0183 03       		.byte	0x3
 444 0184 8A       		.byte	0x8a
 445 0185 0B       		.byte	0xb
 446 0186 AE070000 		.long	0x7ae
 447 018a 05       		.uleb128 0x5
 448 018b 03       		.byte	0x3
 449 018c 8B       		.byte	0x8b
 450 018d 0B       		.byte	0xb
 451 018e DF070000 		.long	0x7df
 452 0192 05       		.uleb128 0x5
 453 0193 03       		.byte	0x3
 454 0194 8D       		.byte	0x8d
 455 0195 0B       		.byte	0xb
 456 0196 F0070000 		.long	0x7f0
 457 019a 05       		.uleb128 0x5
 458 019b 03       		.byte	0x3
 459 019c 8F       		.byte	0x8f
 460 019d 0B       		.byte	0xb
 461 019e 0A080000 		.long	0x80a
 462 01a2 05       		.uleb128 0x5
 463 01a3 03       		.byte	0x3
 464 01a4 90       		.byte	0x90
 465 01a5 0B       		.byte	0xb
 466 01a6 29080000 		.long	0x829
 467 01aa 05       		.uleb128 0x5
 468 01ab 03       		.byte	0x3
 469 01ac 91       		.byte	0x91
 470 01ad 0B       		.byte	0xb
 471 01ae 68080000 		.long	0x868
 472 01b2 05       		.uleb128 0x5
 473 01b3 03       		.byte	0x3
 474 01b4 92       		.byte	0x92
 475 01b5 0B       		.byte	0xb
 476 01b6 98080000 		.long	0x898
 477 01ba 05       		.uleb128 0x5
 478 01bb 03       		.byte	0x3
 479 01bc B9       		.byte	0xb9
 480 01bd 16       		.byte	0x16
 481 01be D1080000 		.long	0x8d1
 482 01c2 05       		.uleb128 0x5
 483 01c3 03       		.byte	0x3
 484 01c4 BA       		.byte	0xba
 485 01c5 16       		.byte	0x16
 486 01c6 0B090000 		.long	0x90b
 487 01ca 05       		.uleb128 0x5
 488 01cb 03       		.byte	0x3
 489 01cc BB       		.byte	0xbb
 490 01cd 16       		.byte	0x16
 491 01ce 48090000 		.long	0x948
 492 01d2 05       		.uleb128 0x5
 493 01d3 03       		.byte	0x3
 494 01d4 BC       		.byte	0xbc
 495 01d5 16       		.byte	0x16
 496 01d6 76090000 		.long	0x976
 497 01da 05       		.uleb128 0x5
 498 01db 03       		.byte	0x3
 499 01dc BD       		.byte	0xbd
 500 01dd 16       		.byte	0x16
 501 01de B7090000 		.long	0x9b7
 502 01e2 00       		.byte	0
 503 01e3 06       		.uleb128 0x6
 504 01e4 5F5F676E 		.ascii "__gnu_cxx\0"
 504      755F6378 
 504      7800
 505 01ee 04       		.byte	0x4
 506 01ef 0601     		.word	0x106
 507 01f1 0B       		.byte	0xb
 508 01f2 35020000 		.long	0x235
 509 01f6 03       		.uleb128 0x3
 510 01f7 5F5F6378 		.ascii "__cxx11\0"
 510      78313100 
 511 01ff 04       		.byte	0x4
 512 0200 0801     		.word	0x108
 513 0202 41       		.byte	0x41
 514 0203 04       		.uleb128 0x4
 515 0204 04       		.byte	0x4
 516 0205 0801     		.word	0x108
 517 0207 41       		.byte	0x41
 518 0208 F6010000 		.long	0x1f6
 519 020c 05       		.uleb128 0x5
 520 020d 03       		.byte	0x3
 521 020e AF       		.byte	0xaf
 522 020f 0B       		.byte	0xb
 523 0210 D1080000 		.long	0x8d1
 524 0214 05       		.uleb128 0x5
 525 0215 03       		.byte	0x3
 526 0216 B0       		.byte	0xb0
 527 0217 0B       		.byte	0xb
 528 0218 0B090000 		.long	0x90b
 529 021c 05       		.uleb128 0x5
 530 021d 03       		.byte	0x3
 531 021e B1       		.byte	0xb1
 532 021f 0B       		.byte	0xb
 533 0220 48090000 		.long	0x948
 534 0224 05       		.uleb128 0x5
 535 0225 03       		.byte	0x3
 536 0226 B2       		.byte	0xb2
 537 0227 0B       		.byte	0xb
 538 0228 76090000 		.long	0x976
 539 022c 05       		.uleb128 0x5
 540 022d 03       		.byte	0x3
 541 022e B3       		.byte	0xb3
 542 022f 0B       		.byte	0xb
 543 0230 B7090000 		.long	0x9b7
 544 0234 00       		.byte	0
 545 0235 07       		.uleb128 0x7
 546 0236 08       		.byte	0x8
 547 0237 5F5F6275 		.ascii "__builtin_va_list\0"
 547      696C7469 
 547      6E5F7661 
 547      5F6C6973 
 547      7400
 548 0249 4D020000 		.long	0x24d
 549 024d 08       		.uleb128 0x8
 550 024e 01       		.byte	0x1
 551 024f 06       		.byte	0x6
 552 0250 63686172 		.ascii "char\0"
 552      00
 553 0255 09       		.uleb128 0x9
 554 0256 4D020000 		.long	0x24d
 555 025a 0A       		.uleb128 0xa
 556 025b 73697A65 		.ascii "size_t\0"
 556      5F7400
 557 0262 05       		.byte	0x5
 558 0263 23       		.byte	0x23
 559 0264 2C       		.byte	0x2c
 560 0265 69020000 		.long	0x269
 561 0269 08       		.uleb128 0x8
 562 026a 08       		.byte	0x8
 563 026b 07       		.byte	0x7
 564 026c 6C6F6E67 		.ascii "long long unsigned int\0"
 564      206C6F6E 
 564      6720756E 
 564      7369676E 
 564      65642069 
 565 0283 08       		.uleb128 0x8
 566 0284 08       		.byte	0x8
 567 0285 05       		.byte	0x5
 568 0286 6C6F6E67 		.ascii "long long int\0"
 568      206C6F6E 
 568      6720696E 
 568      7400
 569 0294 08       		.uleb128 0x8
 570 0295 02       		.byte	0x2
 571 0296 07       		.byte	0x7
 572 0297 73686F72 		.ascii "short unsigned int\0"
 572      7420756E 
 572      7369676E 
 572      65642069 
 572      6E7400
 573 02aa 08       		.uleb128 0x8
 574 02ab 04       		.byte	0x4
 575 02ac 05       		.byte	0x5
 576 02ad 696E7400 		.ascii "int\0"
 577 02b1 09       		.uleb128 0x9
 578 02b2 AA020000 		.long	0x2aa
 579 02b6 08       		.uleb128 0x8
 580 02b7 04       		.byte	0x4
 581 02b8 05       		.byte	0x5
 582 02b9 6C6F6E67 		.ascii "long int\0"
 582      20696E74 
 582      00
 583 02c2 0B       		.uleb128 0xb
 584 02c3 08       		.byte	0x8
 585 02c4 4D020000 		.long	0x24d
 586 02c8 08       		.uleb128 0x8
 587 02c9 02       		.byte	0x2
 588 02ca 07       		.byte	0x7
 589 02cb 77636861 		.ascii "wchar_t\0"
 589      725F7400 
 590 02d3 08       		.uleb128 0x8
 591 02d4 04       		.byte	0x4
 592 02d5 07       		.byte	0x7
 593 02d6 756E7369 		.ascii "unsigned int\0"
 593      676E6564 
 593      20696E74 
 593      00
 594 02e3 08       		.uleb128 0x8
 595 02e4 04       		.byte	0x4
 596 02e5 07       		.byte	0x7
 597 02e6 6C6F6E67 		.ascii "long unsigned int\0"
 597      20756E73 
 597      69676E65 
 597      6420696E 
 597      7400
 598 02f8 08       		.uleb128 0x8
 599 02f9 01       		.byte	0x1
 600 02fa 08       		.byte	0x8
 601 02fb 756E7369 		.ascii "unsigned char\0"
 601      676E6564 
 601      20636861 
 601      7200
 602 0309 0C       		.uleb128 0xc
 603 030a 5F696F62 		.ascii "_iobuf\0"
 603      756600
 604 0311 30       		.byte	0x30
 605 0312 01       		.byte	0x1
 606 0313 1A       		.byte	0x1a
 607 0314 0A       		.byte	0xa
 608 0315 99030000 		.long	0x399
 609 0319 0D       		.uleb128 0xd
 610 031a 5F707472 		.ascii "_ptr\0"
 610      00
 611 031f 01       		.byte	0x1
 612 0320 1B       		.byte	0x1b
 613 0321 0B       		.byte	0xb
 614 0322 C2020000 		.long	0x2c2
 615 0326 00       		.byte	0
 616 0327 0D       		.uleb128 0xd
 617 0328 5F636E74 		.ascii "_cnt\0"
 617      00
 618 032d 01       		.byte	0x1
 619 032e 1C       		.byte	0x1c
 620 032f 09       		.byte	0x9
 621 0330 AA020000 		.long	0x2aa
 622 0334 08       		.byte	0x8
 623 0335 0D       		.uleb128 0xd
 624 0336 5F626173 		.ascii "_base\0"
 624      6500
 625 033c 01       		.byte	0x1
 626 033d 1D       		.byte	0x1d
 627 033e 0B       		.byte	0xb
 628 033f C2020000 		.long	0x2c2
 629 0343 10       		.byte	0x10
 630 0344 0D       		.uleb128 0xd
 631 0345 5F666C61 		.ascii "_flag\0"
 631      6700
 632 034b 01       		.byte	0x1
 633 034c 1E       		.byte	0x1e
 634 034d 09       		.byte	0x9
 635 034e AA020000 		.long	0x2aa
 636 0352 18       		.byte	0x18
 637 0353 0D       		.uleb128 0xd
 638 0354 5F66696C 		.ascii "_file\0"
 638      6500
 639 035a 01       		.byte	0x1
 640 035b 1F       		.byte	0x1f
 641 035c 09       		.byte	0x9
 642 035d AA020000 		.long	0x2aa
 643 0361 1C       		.byte	0x1c
 644 0362 0D       		.uleb128 0xd
 645 0363 5F636861 		.ascii "_charbuf\0"
 645      72627566 
 645      00
 646 036c 01       		.byte	0x1
 647 036d 20       		.byte	0x20
 648 036e 09       		.byte	0x9
 649 036f AA020000 		.long	0x2aa
 650 0373 20       		.byte	0x20
 651 0374 0D       		.uleb128 0xd
 652 0375 5F627566 		.ascii "_bufsiz\0"
 652      73697A00 
 653 037d 01       		.byte	0x1
 654 037e 21       		.byte	0x21
 655 037f 09       		.byte	0x9
 656 0380 AA020000 		.long	0x2aa
 657 0384 24       		.byte	0x24
 658 0385 0D       		.uleb128 0xd
 659 0386 5F746D70 		.ascii "_tmpfname\0"
 659      666E616D 
 659      6500
 660 0390 01       		.byte	0x1
 661 0391 22       		.byte	0x22
 662 0392 0B       		.byte	0xb
 663 0393 C2020000 		.long	0x2c2
 664 0397 28       		.byte	0x28
 665 0398 00       		.byte	0
 666 0399 0A       		.uleb128 0xa
 667 039a 46494C45 		.ascii "FILE\0"
 667      00
 668 039f 01       		.byte	0x1
 669 03a0 24       		.byte	0x24
 670 03a1 19       		.byte	0x19
 671 03a2 09030000 		.long	0x309
 672 03a6 0A       		.uleb128 0xa
 673 03a7 66706F73 		.ascii "fpos_t\0"
 673      5F7400
 674 03ae 01       		.byte	0x1
 675 03af 68       		.byte	0x68
 676 03b0 25       		.byte	0x25
 677 03b1 83020000 		.long	0x283
 678 03b5 09       		.uleb128 0x9
 679 03b6 A6030000 		.long	0x3a6
 680 03ba 0E       		.uleb128 0xe
 681 03bb 636C6561 		.ascii "clearerr\0"
 681      72657272 
 681      00
 682 03c4 01       		.byte	0x1
 683 03c5 4202     		.word	0x242
 684 03c7 10       		.byte	0x10
 685 03c8 D2030000 		.long	0x3d2
 686 03cc 0F       		.uleb128 0xf
 687 03cd D2030000 		.long	0x3d2
 688 03d1 00       		.byte	0
 689 03d2 0B       		.uleb128 0xb
 690 03d3 08       		.byte	0x8
 691 03d4 99030000 		.long	0x399
 692 03d8 10       		.uleb128 0x10
 693 03d9 66636C6F 		.ascii "fclose\0"
 693      736500
 694 03e0 01       		.byte	0x1
 695 03e1 4302     		.word	0x243
 696 03e3 0F       		.byte	0xf
 697 03e4 AA020000 		.long	0x2aa
 698 03e8 F2030000 		.long	0x3f2
 699 03ec 0F       		.uleb128 0xf
 700 03ed D2030000 		.long	0x3d2
 701 03f1 00       		.byte	0
 702 03f2 10       		.uleb128 0x10
 703 03f3 66656F66 		.ascii "feof\0"
 703      00
 704 03f8 01       		.byte	0x1
 705 03f9 4A02     		.word	0x24a
 706 03fb 0F       		.byte	0xf
 707 03fc AA020000 		.long	0x2aa
 708 0400 0A040000 		.long	0x40a
 709 0404 0F       		.uleb128 0xf
 710 0405 D2030000 		.long	0x3d2
 711 0409 00       		.byte	0
 712 040a 10       		.uleb128 0x10
 713 040b 66657272 		.ascii "ferror\0"
 713      6F7200
 714 0412 01       		.byte	0x1
 715 0413 4B02     		.word	0x24b
 716 0415 0F       		.byte	0xf
 717 0416 AA020000 		.long	0x2aa
 718 041a 24040000 		.long	0x424
 719 041e 0F       		.uleb128 0xf
 720 041f D2030000 		.long	0x3d2
 721 0423 00       		.byte	0
 722 0424 10       		.uleb128 0x10
 723 0425 66666C75 		.ascii "fflush\0"
 723      736800
 724 042c 01       		.byte	0x1
 725 042d 4C02     		.word	0x24c
 726 042f 0F       		.byte	0xf
 727 0430 AA020000 		.long	0x2aa
 728 0434 3E040000 		.long	0x43e
 729 0438 0F       		.uleb128 0xf
 730 0439 D2030000 		.long	0x3d2
 731 043d 00       		.byte	0
 732 043e 10       		.uleb128 0x10
 733 043f 66676574 		.ascii "fgetc\0"
 733      6300
 734 0445 01       		.byte	0x1
 735 0446 4D02     		.word	0x24d
 736 0448 0F       		.byte	0xf
 737 0449 AA020000 		.long	0x2aa
 738 044d 57040000 		.long	0x457
 739 0451 0F       		.uleb128 0xf
 740 0452 D2030000 		.long	0x3d2
 741 0456 00       		.byte	0
 742 0457 10       		.uleb128 0x10
 743 0458 66676574 		.ascii "fgetpos\0"
 743      706F7300 
 744 0460 01       		.byte	0x1
 745 0461 4F02     		.word	0x24f
 746 0463 0F       		.byte	0xf
 747 0464 AA020000 		.long	0x2aa
 748 0468 77040000 		.long	0x477
 749 046c 0F       		.uleb128 0xf
 750 046d D2030000 		.long	0x3d2
 751 0471 0F       		.uleb128 0xf
 752 0472 77040000 		.long	0x477
 753 0476 00       		.byte	0
 754 0477 0B       		.uleb128 0xb
 755 0478 08       		.byte	0x8
 756 0479 A6030000 		.long	0x3a6
 757 047d 10       		.uleb128 0x10
 758 047e 66676574 		.ascii "fgets\0"
 758      7300
 759 0484 01       		.byte	0x1
 760 0485 5102     		.word	0x251
 761 0487 11       		.byte	0x11
 762 0488 C2020000 		.long	0x2c2
 763 048c A0040000 		.long	0x4a0
 764 0490 0F       		.uleb128 0xf
 765 0491 C2020000 		.long	0x2c2
 766 0495 0F       		.uleb128 0xf
 767 0496 AA020000 		.long	0x2aa
 768 049a 0F       		.uleb128 0xf
 769 049b D2030000 		.long	0x3d2
 770 049f 00       		.byte	0
 771 04a0 10       		.uleb128 0x10
 772 04a1 666F7065 		.ascii "fopen\0"
 772      6E00
 773 04a7 01       		.byte	0x1
 774 04a8 5802     		.word	0x258
 775 04aa 11       		.byte	0x11
 776 04ab D2030000 		.long	0x3d2
 777 04af BE040000 		.long	0x4be
 778 04b3 0F       		.uleb128 0xf
 779 04b4 BE040000 		.long	0x4be
 780 04b8 0F       		.uleb128 0xf
 781 04b9 BE040000 		.long	0x4be
 782 04bd 00       		.byte	0
 783 04be 0B       		.uleb128 0xb
 784 04bf 08       		.byte	0x8
 785 04c0 55020000 		.long	0x255
 786 04c4 11       		.uleb128 0x11
 787 04c5 66707269 		.ascii "fprintf\0"
 787      6E746600 
 788 04cd 01       		.byte	0x1
 789 04ce 4E01     		.word	0x14e
 790 04d0 05       		.byte	0x5
 791 04d1 5F5A3766 		.ascii "_Z7fprintfP6_iobufPKcz\0"
 791      7072696E 
 791      74665036 
 791      5F696F62 
 791      7566504B 
 792 04e8 AA020000 		.long	0x2aa
 793 04ec FC040000 		.long	0x4fc
 794 04f0 0F       		.uleb128 0xf
 795 04f1 D2030000 		.long	0x3d2
 796 04f5 0F       		.uleb128 0xf
 797 04f6 BE040000 		.long	0x4be
 798 04fa 12       		.uleb128 0x12
 799 04fb 00       		.byte	0
 800 04fc 10       		.uleb128 0x10
 801 04fd 66726561 		.ascii "fread\0"
 801      6400
 802 0503 01       		.byte	0x1
 803 0504 5D02     		.word	0x25d
 804 0506 12       		.byte	0x12
 805 0507 5A020000 		.long	0x25a
 806 050b 24050000 		.long	0x524
 807 050f 0F       		.uleb128 0xf
 808 0510 24050000 		.long	0x524
 809 0514 0F       		.uleb128 0xf
 810 0515 5A020000 		.long	0x25a
 811 0519 0F       		.uleb128 0xf
 812 051a 5A020000 		.long	0x25a
 813 051e 0F       		.uleb128 0xf
 814 051f D2030000 		.long	0x3d2
 815 0523 00       		.byte	0
 816 0524 13       		.uleb128 0x13
 817 0525 08       		.byte	0x8
 818 0526 10       		.uleb128 0x10
 819 0527 6672656F 		.ascii "freopen\0"
 819      70656E00 
 820 052f 01       		.byte	0x1
 821 0530 5E02     		.word	0x25e
 822 0532 11       		.byte	0x11
 823 0533 D2030000 		.long	0x3d2
 824 0537 4B050000 		.long	0x54b
 825 053b 0F       		.uleb128 0xf
 826 053c BE040000 		.long	0x4be
 827 0540 0F       		.uleb128 0xf
 828 0541 BE040000 		.long	0x4be
 829 0545 0F       		.uleb128 0xf
 830 0546 D2030000 		.long	0x3d2
 831 054a 00       		.byte	0
 832 054b 11       		.uleb128 0x11
 833 054c 66736361 		.ascii "fscanf\0"
 833      6E6600
 834 0553 01       		.byte	0x1
 835 0554 2101     		.word	0x121
 836 0556 05       		.byte	0x5
 837 0557 5F5A3666 		.ascii "_Z6fscanfP6_iobufPKcz\0"
 837      7363616E 
 837      6650365F 
 837      696F6275 
 837      66504B63 
 838 056d AA020000 		.long	0x2aa
 839 0571 81050000 		.long	0x581
 840 0575 0F       		.uleb128 0xf
 841 0576 D2030000 		.long	0x3d2
 842 057a 0F       		.uleb128 0xf
 843 057b BE040000 		.long	0x4be
 844 057f 12       		.uleb128 0x12
 845 0580 00       		.byte	0
 846 0581 10       		.uleb128 0x10
 847 0582 66736565 		.ascii "fseek\0"
 847      6B00
 848 0588 01       		.byte	0x1
 849 0589 6102     		.word	0x261
 850 058b 0F       		.byte	0xf
 851 058c AA020000 		.long	0x2aa
 852 0590 A4050000 		.long	0x5a4
 853 0594 0F       		.uleb128 0xf
 854 0595 D2030000 		.long	0x3d2
 855 0599 0F       		.uleb128 0xf
 856 059a B6020000 		.long	0x2b6
 857 059e 0F       		.uleb128 0xf
 858 059f AA020000 		.long	0x2aa
 859 05a3 00       		.byte	0
 860 05a4 10       		.uleb128 0x10
 861 05a5 66736574 		.ascii "fsetpos\0"
 861      706F7300 
 862 05ad 01       		.byte	0x1
 863 05ae 5F02     		.word	0x25f
 864 05b0 0F       		.byte	0xf
 865 05b1 AA020000 		.long	0x2aa
 866 05b5 C4050000 		.long	0x5c4
 867 05b9 0F       		.uleb128 0xf
 868 05ba D2030000 		.long	0x3d2
 869 05be 0F       		.uleb128 0xf
 870 05bf C4050000 		.long	0x5c4
 871 05c3 00       		.byte	0
 872 05c4 0B       		.uleb128 0xb
 873 05c5 08       		.byte	0x8
 874 05c6 B5030000 		.long	0x3b5
 875 05ca 10       		.uleb128 0x10
 876 05cb 6674656C 		.ascii "ftell\0"
 876      6C00
 877 05d1 01       		.byte	0x1
 878 05d2 6202     		.word	0x262
 879 05d4 10       		.byte	0x10
 880 05d5 B6020000 		.long	0x2b6
 881 05d9 E3050000 		.long	0x5e3
 882 05dd 0F       		.uleb128 0xf
 883 05de D2030000 		.long	0x3d2
 884 05e2 00       		.byte	0
 885 05e3 10       		.uleb128 0x10
 886 05e4 67657463 		.ascii "getc\0"
 886      00
 887 05e9 01       		.byte	0x1
 888 05ea 8F02     		.word	0x28f
 889 05ec 0F       		.byte	0xf
 890 05ed AA020000 		.long	0x2aa
 891 05f1 FB050000 		.long	0x5fb
 892 05f5 0F       		.uleb128 0xf
 893 05f6 D2030000 		.long	0x3d2
 894 05fa 00       		.byte	0
 895 05fb 14       		.uleb128 0x14
 896 05fc 67657463 		.ascii "getchar\0"
 896      68617200 
 897 0604 01       		.byte	0x1
 898 0605 9002     		.word	0x290
 899 0607 0F       		.byte	0xf
 900 0608 AA020000 		.long	0x2aa
 901 060c 10       		.uleb128 0x10
 902 060d 67657473 		.ascii "gets\0"
 902      00
 903 0612 01       		.byte	0x1
 904 0613 9202     		.word	0x292
 905 0615 11       		.byte	0x11
 906 0616 C2020000 		.long	0x2c2
 907 061a 24060000 		.long	0x624
 908 061e 0F       		.uleb128 0xf
 909 061f C2020000 		.long	0x2c2
 910 0623 00       		.byte	0
 911 0624 0E       		.uleb128 0xe
 912 0625 70657272 		.ascii "perror\0"
 912      6F7200
 913 062c 01       		.byte	0x1
 914 062d 9602     		.word	0x296
 915 062f 10       		.byte	0x10
 916 0630 3A060000 		.long	0x63a
 917 0634 0F       		.uleb128 0xf
 918 0635 BE040000 		.long	0x4be
 919 0639 00       		.byte	0
 920 063a 11       		.uleb128 0x11
 921 063b 7072696E 		.ascii "printf\0"
 921      746600
 922 0642 01       		.byte	0x1
 923 0643 5901     		.word	0x159
 924 0645 05       		.byte	0x5
 925 0646 5F5A3670 		.ascii "_Z6printfPKcz\0"
 925      72696E74 
 925      66504B63 
 925      7A00
 926 0654 AA020000 		.long	0x2aa
 927 0658 63060000 		.long	0x663
 928 065c 0F       		.uleb128 0xf
 929 065d BE040000 		.long	0x4be
 930 0661 12       		.uleb128 0x12
 931 0662 00       		.byte	0
 932 0663 10       		.uleb128 0x10
 933 0664 72656D6F 		.ascii "remove\0"
 933      766500
 934 066b 01       		.byte	0x1
 935 066c A402     		.word	0x2a4
 936 066e 0F       		.byte	0xf
 937 066f AA020000 		.long	0x2aa
 938 0673 7D060000 		.long	0x67d
 939 0677 0F       		.uleb128 0xf
 940 0678 BE040000 		.long	0x4be
 941 067c 00       		.byte	0
 942 067d 10       		.uleb128 0x10
 943 067e 72656E61 		.ascii "rename\0"
 943      6D6500
 944 0685 01       		.byte	0x1
 945 0686 A502     		.word	0x2a5
 946 0688 0F       		.byte	0xf
 947 0689 AA020000 		.long	0x2aa
 948 068d 9C060000 		.long	0x69c
 949 0691 0F       		.uleb128 0xf
 950 0692 BE040000 		.long	0x4be
 951 0696 0F       		.uleb128 0xf
 952 0697 BE040000 		.long	0x4be
 953 069b 00       		.byte	0
 954 069c 0E       		.uleb128 0xe
 955 069d 72657769 		.ascii "rewind\0"
 955      6E6400
 956 06a4 01       		.byte	0x1
 957 06a5 AB02     		.word	0x2ab
 958 06a7 10       		.byte	0x10
 959 06a8 B2060000 		.long	0x6b2
 960 06ac 0F       		.uleb128 0xf
 961 06ad D2030000 		.long	0x3d2
 962 06b1 00       		.byte	0
 963 06b2 15       		.uleb128 0x15
 964 06b3 7363616E 		.ascii "scanf\0"
 964      6600
 965 06b9 01       		.byte	0x1
 966 06ba 1601     		.word	0x116
 967 06bc 05       		.byte	0x5
 968 06bd 5F5A3573 		.ascii "_Z5scanfPKcz\0"
 968      63616E66 
 968      504B637A 
 968      00
 969 06ca AA020000 		.long	0x2aa
 970 06ce 00000000 		.quad	.LFB2
 970      00000000 
 971 06d6 54000000 		.quad	.LFE2-.LFB2
 971      00000000 
 972 06de 01       		.uleb128 0x1
 973 06df 9C       		.byte	0x9c
 974 06e0 37070000 		.long	0x737
 975 06e4 12       		.uleb128 0x12
 976 06e5 16       		.uleb128 0x16
 977 06e6 5F5F666F 		.ascii "__format\0"
 977      726D6174 
 977      00
 978 06ef 01       		.byte	0x1
 979 06f0 1601     		.word	0x116
 980 06f2 17       		.byte	0x17
 981 06f3 BE040000 		.long	0x4be
 982 06f7 02       		.uleb128 0x2
 983 06f8 91       		.byte	0x91
 984 06f9 00       		.sleb128 0
 985 06fa 12       		.uleb128 0x12
 986 06fb 17       		.uleb128 0x17
 987 06fc 5F5F7265 		.ascii "__retval\0"
 987      7476616C 
 987      00
 988 0705 01       		.byte	0x1
 989 0706 1801     		.word	0x118
 990 0708 07       		.byte	0x7
 991 0709 AA020000 		.long	0x2aa
 992 070d 02       		.uleb128 0x2
 993 070e 91       		.byte	0x91
 994 070f 5C       		.sleb128 -36
 995 0710 17       		.uleb128 0x17
 996 0711 5F5F6C6F 		.ascii "__local_argv\0"
 996      63616C5F 
 996      61726776 
 996      00
 997 071e 01       		.byte	0x1
 998 071f 1901     		.word	0x119
 999 0721 15       		.byte	0x15
 1000 0722 35020000 		.long	0x235
 1001 0726 02       		.uleb128 0x2
 1002 0727 91       		.byte	0x91
 1003 0728 50       		.sleb128 -48
 1004 0729 18       		.uleb128 0x18
 1005 072a 38000000 		.quad	.LVL0
 1005      00000000 
 1006 0732 BE0A0000 		.long	0xabe
 1007 0736 00       		.byte	0
 1008 0737 0E       		.uleb128 0xe
 1009 0738 73657462 		.ascii "setbuf\0"
 1009      756600
 1010 073f 01       		.byte	0x1
 1011 0740 AD02     		.word	0x2ad
 1012 0742 10       		.byte	0x10
 1013 0743 52070000 		.long	0x752
 1014 0747 0F       		.uleb128 0xf
 1015 0748 D2030000 		.long	0x3d2
 1016 074c 0F       		.uleb128 0xf
 1017 074d C2020000 		.long	0x2c2
 1018 0751 00       		.byte	0
 1019 0752 10       		.uleb128 0x10
 1020 0753 73657476 		.ascii "setvbuf\0"
 1020      62756600 
 1021 075b 01       		.byte	0x1
 1022 075c B102     		.word	0x2b1
 1023 075e 0F       		.byte	0xf
 1024 075f AA020000 		.long	0x2aa
 1025 0763 7C070000 		.long	0x77c
 1026 0767 0F       		.uleb128 0xf
 1027 0768 D2030000 		.long	0x3d2
 1028 076c 0F       		.uleb128 0xf
 1029 076d C2020000 		.long	0x2c2
 1030 0771 0F       		.uleb128 0xf
 1031 0772 AA020000 		.long	0x2aa
 1032 0776 0F       		.uleb128 0xf
 1033 0777 5A020000 		.long	0x25a
 1034 077b 00       		.byte	0
 1035 077c 11       		.uleb128 0x11
 1036 077d 73707269 		.ascii "sprintf\0"
 1036      6E746600 
 1037 0785 01       		.byte	0x1
 1038 0786 6401     		.word	0x164
 1039 0788 05       		.byte	0x5
 1040 0789 5F5A3773 		.ascii "_Z7sprintfPcPKcz\0"
 1040      7072696E 
 1040      74665063 
 1040      504B637A 
 1040      00
 1041 079a AA020000 		.long	0x2aa
 1042 079e AE070000 		.long	0x7ae
 1043 07a2 0F       		.uleb128 0xf
 1044 07a3 C2020000 		.long	0x2c2
 1045 07a7 0F       		.uleb128 0xf
 1046 07a8 BE040000 		.long	0x4be
 1047 07ac 12       		.uleb128 0x12
 1048 07ad 00       		.byte	0
 1049 07ae 11       		.uleb128 0x11
 1050 07af 73736361 		.ascii "sscanf\0"
 1050      6E6600
 1051 07b6 01       		.byte	0x1
 1052 07b7 0B01     		.word	0x10b
 1053 07b9 05       		.byte	0x5
 1054 07ba 5F5A3673 		.ascii "_Z6sscanfPKcS0_z\0"
 1054      7363616E 
 1054      66504B63 
 1054      53305F7A 
 1054      00
 1055 07cb AA020000 		.long	0x2aa
 1056 07cf DF070000 		.long	0x7df
 1057 07d3 0F       		.uleb128 0xf
 1058 07d4 BE040000 		.long	0x4be
 1059 07d8 0F       		.uleb128 0xf
 1060 07d9 BE040000 		.long	0x4be
 1061 07dd 12       		.uleb128 0x12
 1062 07de 00       		.byte	0
 1063 07df 14       		.uleb128 0x14
 1064 07e0 746D7066 		.ascii "tmpfile\0"
 1064      696C6500 
 1065 07e8 01       		.byte	0x1
 1066 07e9 CB02     		.word	0x2cb
 1067 07eb 11       		.byte	0x11
 1068 07ec D2030000 		.long	0x3d2
 1069 07f0 10       		.uleb128 0x10
 1070 07f1 746D706E 		.ascii "tmpnam\0"
 1070      616D00
 1071 07f8 01       		.byte	0x1
 1072 07f9 CC02     		.word	0x2cc
 1073 07fb 11       		.byte	0x11
 1074 07fc C2020000 		.long	0x2c2
 1075 0800 0A080000 		.long	0x80a
 1076 0804 0F       		.uleb128 0xf
 1077 0805 C2020000 		.long	0x2c2
 1078 0809 00       		.byte	0
 1079 080a 10       		.uleb128 0x10
 1080 080b 756E6765 		.ascii "ungetc\0"
 1080      746300
 1081 0812 01       		.byte	0x1
 1082 0813 CD02     		.word	0x2cd
 1083 0815 0F       		.byte	0xf
 1084 0816 AA020000 		.long	0x2aa
 1085 081a 29080000 		.long	0x829
 1086 081e 0F       		.uleb128 0xf
 1087 081f AA020000 		.long	0x2aa
 1088 0823 0F       		.uleb128 0xf
 1089 0824 D2030000 		.long	0x3d2
 1090 0828 00       		.byte	0
 1091 0829 11       		.uleb128 0x11
 1092 082a 76667072 		.ascii "vfprintf\0"
 1092      696E7466 
 1092      00
 1093 0833 01       		.byte	0x1
 1094 0834 6F01     		.word	0x16f
 1095 0836 05       		.byte	0x5
 1096 0837 5F5A3876 		.ascii "_Z8vfprintfP6_iobufPKcPc\0"
 1096      66707269 
 1096      6E746650 
 1096      365F696F 
 1096      62756650 
 1097 0850 AA020000 		.long	0x2aa
 1098 0854 68080000 		.long	0x868
 1099 0858 0F       		.uleb128 0xf
 1100 0859 D2030000 		.long	0x3d2
 1101 085d 0F       		.uleb128 0xf
 1102 085e BE040000 		.long	0x4be
 1103 0862 0F       		.uleb128 0xf
 1104 0863 35020000 		.long	0x235
 1105 0867 00       		.byte	0
 1106 0868 11       		.uleb128 0x11
 1107 0869 76707269 		.ascii "vprintf\0"
 1107      6E746600 
 1108 0871 01       		.byte	0x1
 1109 0872 7601     		.word	0x176
 1110 0874 05       		.byte	0x5
 1111 0875 5F5A3776 		.ascii "_Z7vprintfPKcPc\0"
 1111      7072696E 
 1111      7466504B 
 1111      63506300 
 1112 0885 AA020000 		.long	0x2aa
 1113 0889 98080000 		.long	0x898
 1114 088d 0F       		.uleb128 0xf
 1115 088e BE040000 		.long	0x4be
 1116 0892 0F       		.uleb128 0xf
 1117 0893 35020000 		.long	0x235
 1118 0897 00       		.byte	0
 1119 0898 11       		.uleb128 0x11
 1120 0899 76737072 		.ascii "vsprintf\0"
 1120      696E7466 
 1120      00
 1121 08a2 01       		.byte	0x1
 1122 08a3 7D01     		.word	0x17d
 1123 08a5 05       		.byte	0x5
 1124 08a6 5F5A3876 		.ascii "_Z8vsprintfPcPKcS_\0"
 1124      73707269 
 1124      6E746650 
 1124      63504B63 
 1124      535F00
 1125 08b9 AA020000 		.long	0x2aa
 1126 08bd D1080000 		.long	0x8d1
 1127 08c1 0F       		.uleb128 0xf
 1128 08c2 C2020000 		.long	0x2c2
 1129 08c6 0F       		.uleb128 0xf
 1130 08c7 BE040000 		.long	0x4be
 1131 08cb 0F       		.uleb128 0xf
 1132 08cc 35020000 		.long	0x235
 1133 08d0 00       		.byte	0
 1134 08d1 11       		.uleb128 0x11
 1135 08d2 736E7072 		.ascii "snprintf\0"
 1135      696E7466 
 1135      00
 1136 08db 01       		.byte	0x1
 1137 08dc 8401     		.word	0x184
 1138 08de 05       		.byte	0x5
 1139 08df 5F5A3873 		.ascii "_Z8snprintfPcyPKcz\0"
 1139      6E707269 
 1139      6E746650 
 1139      6379504B 
 1139      637A00
 1140 08f2 AA020000 		.long	0x2aa
 1141 08f6 0B090000 		.long	0x90b
 1142 08fa 0F       		.uleb128 0xf
 1143 08fb C2020000 		.long	0x2c2
 1144 08ff 0F       		.uleb128 0xf
 1145 0900 5A020000 		.long	0x25a
 1146 0904 0F       		.uleb128 0xf
 1147 0905 BE040000 		.long	0x4be
 1148 0909 12       		.uleb128 0x12
 1149 090a 00       		.byte	0
 1150 090b 11       		.uleb128 0x11
 1151 090c 76667363 		.ascii "vfscanf\0"
 1151      616E6600 
 1152 0914 01       		.byte	0x1
 1153 0915 4001     		.word	0x140
 1154 0917 05       		.byte	0x5
 1155 0918 5F5A3776 		.ascii "_Z7vfscanfP6_iobufPKcPc\0"
 1155      66736361 
 1155      6E665036 
 1155      5F696F62 
 1155      7566504B 
 1156 0930 AA020000 		.long	0x2aa
 1157 0934 48090000 		.long	0x948
 1158 0938 0F       		.uleb128 0xf
 1159 0939 D2030000 		.long	0x3d2
 1160 093d 0F       		.uleb128 0xf
 1161 093e BE040000 		.long	0x4be
 1162 0942 0F       		.uleb128 0xf
 1163 0943 35020000 		.long	0x235
 1164 0947 00       		.byte	0
 1165 0948 11       		.uleb128 0x11
 1166 0949 76736361 		.ascii "vscanf\0"
 1166      6E6600
 1167 0950 01       		.byte	0x1
 1168 0951 3901     		.word	0x139
 1169 0953 05       		.byte	0x5
 1170 0954 5F5A3676 		.ascii "_Z6vscanfPKcPc\0"
 1170      7363616E 
 1170      66504B63 
 1170      506300
 1171 0963 AA020000 		.long	0x2aa
 1172 0967 76090000 		.long	0x976
 1173 096b 0F       		.uleb128 0xf
 1174 096c BE040000 		.long	0x4be
 1175 0970 0F       		.uleb128 0xf
 1176 0971 35020000 		.long	0x235
 1177 0975 00       		.byte	0
 1178 0976 11       		.uleb128 0x11
 1179 0977 76736E70 		.ascii "vsnprintf\0"
 1179      72696E74 
 1179      6600
 1180 0981 01       		.byte	0x1
 1181 0982 8F01     		.word	0x18f
 1182 0984 05       		.byte	0x5
 1183 0985 5F5A3976 		.ascii "_Z9vsnprintfPcyPKcS_\0"
 1183      736E7072 
 1183      696E7466 
 1183      50637950 
 1183      4B63535F 
 1184 099a AA020000 		.long	0x2aa
 1185 099e B7090000 		.long	0x9b7
 1186 09a2 0F       		.uleb128 0xf
 1187 09a3 C2020000 		.long	0x2c2
 1188 09a7 0F       		.uleb128 0xf
 1189 09a8 5A020000 		.long	0x25a
 1190 09ac 0F       		.uleb128 0xf
 1191 09ad BE040000 		.long	0x4be
 1192 09b1 0F       		.uleb128 0xf
 1193 09b2 35020000 		.long	0x235
 1194 09b6 00       		.byte	0
 1195 09b7 11       		.uleb128 0x11
 1196 09b8 76737363 		.ascii "vsscanf\0"
 1196      616E6600 
 1197 09c0 01       		.byte	0x1
 1198 09c1 3201     		.word	0x132
 1199 09c3 05       		.byte	0x5
 1200 09c4 5F5A3776 		.ascii "_Z7vsscanfPKcS0_Pc\0"
 1200      73736361 
 1200      6E66504B 
 1200      6353305F 
 1200      506300
 1201 09d7 AA020000 		.long	0x2aa
 1202 09db EF090000 		.long	0x9ef
 1203 09df 0F       		.uleb128 0xf
 1204 09e0 BE040000 		.long	0x4be
 1205 09e4 0F       		.uleb128 0xf
 1206 09e5 BE040000 		.long	0x4be
 1207 09e9 0F       		.uleb128 0xf
 1208 09ea 35020000 		.long	0x235
 1209 09ee 00       		.byte	0
 1210 09ef 19       		.uleb128 0x19
 1211 09f0 4E00     		.ascii "N\0"
 1212 09f2 02       		.byte	0x2
 1213 09f3 03       		.byte	0x3
 1214 09f4 0B       		.byte	0xb
 1215 09f5 B1020000 		.long	0x2b1
 1216 09f9 09       		.uleb128 0x9
 1217 09fa 03       		.byte	0x3
 1218 09fb 00000000 		.quad	_ZL1N
 1218      00000000 
 1219 0a03 1A       		.uleb128 0x1a
 1220 0a04 AA020000 		.long	0x2aa
 1221 0a08 130A0000 		.long	0xa13
 1222 0a0c 1B       		.uleb128 0x1b
 1223 0a0d 69020000 		.long	0x269
 1224 0a11 1E       		.byte	0x1e
 1225 0a12 00       		.byte	0
 1226 0a13 1C       		.uleb128 0x1c
 1227 0a14 6600     		.ascii "f\0"
 1228 0a16 02       		.byte	0x2
 1229 0a17 04       		.byte	0x4
 1230 0a18 05       		.byte	0x5
 1231 0a19 030A0000 		.long	0xa03
 1232 0a1d 09       		.uleb128 0x9
 1233 0a1e 03       		.byte	0x3
 1234 0a1f 00000000 		.quad	f
 1234      00000000 
 1235 0a27 1D       		.uleb128 0x1d
 1236 0a28 6D61696E 		.ascii "main\0"
 1236      00
 1237 0a2d 02       		.byte	0x2
 1238 0a2e 0E       		.byte	0xe
 1239 0a2f 05       		.byte	0x5
 1240 0a30 AA020000 		.long	0x2aa
 1241 0a34 A1000000 		.quad	.LFB45
 1241      00000000 
 1242 0a3c B8000000 		.quad	.LFE45-.LFB45
 1242      00000000 
 1243 0a44 01       		.uleb128 0x1
 1244 0a45 9C       		.byte	0x9c
 1245 0a46 650A0000 		.long	0xa65
 1246 0a4a 19       		.uleb128 0x19
 1247 0a4b 6E00     		.ascii "n\0"
 1248 0a4d 02       		.byte	0x2
 1249 0a4e 10       		.byte	0x10
 1250 0a4f 06       		.byte	0x6
 1251 0a50 AA020000 		.long	0x2aa
 1252 0a54 02       		.uleb128 0x2
 1253 0a55 91       		.byte	0x91
 1254 0a56 68       		.sleb128 -24
 1255 0a57 19       		.uleb128 0x19
 1256 0a58 6900     		.ascii "i\0"
 1257 0a5a 02       		.byte	0x2
 1258 0a5b 13       		.byte	0x13
 1259 0a5c 06       		.byte	0x6
 1260 0a5d AA020000 		.long	0x2aa
 1261 0a61 02       		.uleb128 0x2
 1262 0a62 91       		.byte	0x91
 1263 0a63 6C       		.sleb128 -20
 1264 0a64 00       		.byte	0
 1265 0a65 1E       		.uleb128 0x1e
 1266 0a66 736F6C76 		.ascii "solve\0"
 1266      6500
 1267 0a6c 02       		.byte	0x2
 1268 0a6d 06       		.byte	0x6
 1269 0a6e 06       		.byte	0x6
 1270 0a6f 5F5A3573 		.ascii "_Z5solveii\0"
 1270      6F6C7665 
 1270      696900
 1271 0a7a 4D020000 		.long	0x24d
 1272 0a7e 00000000 		.quad	.LFB44
 1272      00000000 
 1273 0a86 A1000000 		.quad	.LFE44-.LFB44
 1273      00000000 
 1274 0a8e 01       		.uleb128 0x1
 1275 0a8f 9C       		.byte	0x9c
 1276 0a90 BE0A0000 		.long	0xabe
 1277 0a94 1F       		.uleb128 0x1f
 1278 0a95 7300     		.ascii "s\0"
 1279 0a97 02       		.byte	0x2
 1280 0a98 06       		.byte	0x6
 1281 0a99 10       		.byte	0x10
 1282 0a9a AA020000 		.long	0x2aa
 1283 0a9e 02       		.uleb128 0x2
 1284 0a9f 91       		.byte	0x91
 1285 0aa0 00       		.sleb128 0
 1286 0aa1 1F       		.uleb128 0x1f
 1287 0aa2 6B00     		.ascii "k\0"
 1288 0aa4 02       		.byte	0x2
 1289 0aa5 06       		.byte	0x6
 1290 0aa6 17       		.byte	0x17
 1291 0aa7 AA020000 		.long	0x2aa
 1292 0aab 02       		.uleb128 0x2
 1293 0aac 91       		.byte	0x91
 1294 0aad 08       		.sleb128 8
 1295 0aae 19       		.uleb128 0x19
 1296 0aaf 746D7000 		.ascii "tmp\0"
 1297 0ab3 02       		.byte	0x2
 1298 0ab4 09       		.byte	0x9
 1299 0ab5 06       		.byte	0x6
 1300 0ab6 AA020000 		.long	0x2aa
 1301 0aba 02       		.uleb128 0x2
 1302 0abb 91       		.byte	0x91
 1303 0abc 6C       		.sleb128 -20
 1304 0abd 00       		.byte	0
 1305 0abe 20       		.uleb128 0x20
 1306 0abf 00000000 		.secrel32	.LASF0
 1307 0ac3 00000000 		.secrel32	.LASF0
 1308 0ac7 01       		.byte	0x1
 1309 0ac8 52       		.byte	0x52
 1310 0ac9 17       		.byte	0x17
 1311 0aca 00       		.byte	0
 1312              		.section	.debug_abbrev,"dr"
 1313              	.Ldebug_abbrev0:
 1314 0000 01       		.uleb128 0x1
 1315 0001 11       		.uleb128 0x11
 1316 0002 01       		.byte	0x1
 1317 0003 25       		.uleb128 0x25
 1318 0004 08       		.uleb128 0x8
 1319 0005 13       		.uleb128 0x13
 1320 0006 0B       		.uleb128 0xb
 1321 0007 03       		.uleb128 0x3
 1322 0008 08       		.uleb128 0x8
 1323 0009 1B       		.uleb128 0x1b
 1324 000a 08       		.uleb128 0x8
 1325 000b 55       		.uleb128 0x55
 1326 000c 17       		.uleb128 0x17
 1327 000d 11       		.uleb128 0x11
 1328 000e 01       		.uleb128 0x1
 1329 000f 10       		.uleb128 0x10
 1330 0010 17       		.uleb128 0x17
 1331 0011 00       		.byte	0
 1332 0012 00       		.byte	0
 1333 0013 02       		.uleb128 0x2
 1334 0014 39       		.uleb128 0x39
 1335 0015 01       		.byte	0x1
 1336 0016 03       		.uleb128 0x3
 1337 0017 08       		.uleb128 0x8
 1338 0018 3A       		.uleb128 0x3a
 1339 0019 0B       		.uleb128 0xb
 1340 001a 3B       		.uleb128 0x3b
 1341 001b 0B       		.uleb128 0xb
 1342 001c 01       		.uleb128 0x1
 1343 001d 13       		.uleb128 0x13
 1344 001e 00       		.byte	0
 1345 001f 00       		.byte	0
 1346 0020 03       		.uleb128 0x3
 1347 0021 39       		.uleb128 0x39
 1348 0022 00       		.byte	0
 1349 0023 03       		.uleb128 0x3
 1350 0024 08       		.uleb128 0x8
 1351 0025 3A       		.uleb128 0x3a
 1352 0026 0B       		.uleb128 0xb
 1353 0027 3B       		.uleb128 0x3b
 1354 0028 05       		.uleb128 0x5
 1355 0029 39       		.uleb128 0x39
 1356 002a 0B       		.uleb128 0xb
 1357 002b 8901     		.uleb128 0x89
 1358 002d 19       		.uleb128 0x19
 1359 002e 00       		.byte	0
 1360 002f 00       		.byte	0
 1361 0030 04       		.uleb128 0x4
 1362 0031 3A       		.uleb128 0x3a
 1363 0032 00       		.byte	0
 1364 0033 3A       		.uleb128 0x3a
 1365 0034 0B       		.uleb128 0xb
 1366 0035 3B       		.uleb128 0x3b
 1367 0036 05       		.uleb128 0x5
 1368 0037 39       		.uleb128 0x39
 1369 0038 0B       		.uleb128 0xb
 1370 0039 18       		.uleb128 0x18
 1371 003a 13       		.uleb128 0x13
 1372 003b 00       		.byte	0
 1373 003c 00       		.byte	0
 1374 003d 05       		.uleb128 0x5
 1375 003e 08       		.uleb128 0x8
 1376 003f 00       		.byte	0
 1377 0040 3A       		.uleb128 0x3a
 1378 0041 0B       		.uleb128 0xb
 1379 0042 3B       		.uleb128 0x3b
 1380 0043 0B       		.uleb128 0xb
 1381 0044 39       		.uleb128 0x39
 1382 0045 0B       		.uleb128 0xb
 1383 0046 18       		.uleb128 0x18
 1384 0047 13       		.uleb128 0x13
 1385 0048 00       		.byte	0
 1386 0049 00       		.byte	0
 1387 004a 06       		.uleb128 0x6
 1388 004b 39       		.uleb128 0x39
 1389 004c 01       		.byte	0x1
 1390 004d 03       		.uleb128 0x3
 1391 004e 08       		.uleb128 0x8
 1392 004f 3A       		.uleb128 0x3a
 1393 0050 0B       		.uleb128 0xb
 1394 0051 3B       		.uleb128 0x3b
 1395 0052 05       		.uleb128 0x5
 1396 0053 39       		.uleb128 0x39
 1397 0054 0B       		.uleb128 0xb
 1398 0055 01       		.uleb128 0x1
 1399 0056 13       		.uleb128 0x13
 1400 0057 00       		.byte	0
 1401 0058 00       		.byte	0
 1402 0059 07       		.uleb128 0x7
 1403 005a 0F       		.uleb128 0xf
 1404 005b 00       		.byte	0
 1405 005c 0B       		.uleb128 0xb
 1406 005d 0B       		.uleb128 0xb
 1407 005e 03       		.uleb128 0x3
 1408 005f 08       		.uleb128 0x8
 1409 0060 49       		.uleb128 0x49
 1410 0061 13       		.uleb128 0x13
 1411 0062 00       		.byte	0
 1412 0063 00       		.byte	0
 1413 0064 08       		.uleb128 0x8
 1414 0065 24       		.uleb128 0x24
 1415 0066 00       		.byte	0
 1416 0067 0B       		.uleb128 0xb
 1417 0068 0B       		.uleb128 0xb
 1418 0069 3E       		.uleb128 0x3e
 1419 006a 0B       		.uleb128 0xb
 1420 006b 03       		.uleb128 0x3
 1421 006c 08       		.uleb128 0x8
 1422 006d 00       		.byte	0
 1423 006e 00       		.byte	0
 1424 006f 09       		.uleb128 0x9
 1425 0070 26       		.uleb128 0x26
 1426 0071 00       		.byte	0
 1427 0072 49       		.uleb128 0x49
 1428 0073 13       		.uleb128 0x13
 1429 0074 00       		.byte	0
 1430 0075 00       		.byte	0
 1431 0076 0A       		.uleb128 0xa
 1432 0077 16       		.uleb128 0x16
 1433 0078 00       		.byte	0
 1434 0079 03       		.uleb128 0x3
 1435 007a 08       		.uleb128 0x8
 1436 007b 3A       		.uleb128 0x3a
 1437 007c 0B       		.uleb128 0xb
 1438 007d 3B       		.uleb128 0x3b
 1439 007e 0B       		.uleb128 0xb
 1440 007f 39       		.uleb128 0x39
 1441 0080 0B       		.uleb128 0xb
 1442 0081 49       		.uleb128 0x49
 1443 0082 13       		.uleb128 0x13
 1444 0083 00       		.byte	0
 1445 0084 00       		.byte	0
 1446 0085 0B       		.uleb128 0xb
 1447 0086 0F       		.uleb128 0xf
 1448 0087 00       		.byte	0
 1449 0088 0B       		.uleb128 0xb
 1450 0089 0B       		.uleb128 0xb
 1451 008a 49       		.uleb128 0x49
 1452 008b 13       		.uleb128 0x13
 1453 008c 00       		.byte	0
 1454 008d 00       		.byte	0
 1455 008e 0C       		.uleb128 0xc
 1456 008f 13       		.uleb128 0x13
 1457 0090 01       		.byte	0x1
 1458 0091 03       		.uleb128 0x3
 1459 0092 08       		.uleb128 0x8
 1460 0093 0B       		.uleb128 0xb
 1461 0094 0B       		.uleb128 0xb
 1462 0095 3A       		.uleb128 0x3a
 1463 0096 0B       		.uleb128 0xb
 1464 0097 3B       		.uleb128 0x3b
 1465 0098 0B       		.uleb128 0xb
 1466 0099 39       		.uleb128 0x39
 1467 009a 0B       		.uleb128 0xb
 1468 009b 01       		.uleb128 0x1
 1469 009c 13       		.uleb128 0x13
 1470 009d 00       		.byte	0
 1471 009e 00       		.byte	0
 1472 009f 0D       		.uleb128 0xd
 1473 00a0 0D       		.uleb128 0xd
 1474 00a1 00       		.byte	0
 1475 00a2 03       		.uleb128 0x3
 1476 00a3 08       		.uleb128 0x8
 1477 00a4 3A       		.uleb128 0x3a
 1478 00a5 0B       		.uleb128 0xb
 1479 00a6 3B       		.uleb128 0x3b
 1480 00a7 0B       		.uleb128 0xb
 1481 00a8 39       		.uleb128 0x39
 1482 00a9 0B       		.uleb128 0xb
 1483 00aa 49       		.uleb128 0x49
 1484 00ab 13       		.uleb128 0x13
 1485 00ac 38       		.uleb128 0x38
 1486 00ad 0B       		.uleb128 0xb
 1487 00ae 00       		.byte	0
 1488 00af 00       		.byte	0
 1489 00b0 0E       		.uleb128 0xe
 1490 00b1 2E       		.uleb128 0x2e
 1491 00b2 01       		.byte	0x1
 1492 00b3 3F       		.uleb128 0x3f
 1493 00b4 19       		.uleb128 0x19
 1494 00b5 03       		.uleb128 0x3
 1495 00b6 08       		.uleb128 0x8
 1496 00b7 3A       		.uleb128 0x3a
 1497 00b8 0B       		.uleb128 0xb
 1498 00b9 3B       		.uleb128 0x3b
 1499 00ba 05       		.uleb128 0x5
 1500 00bb 39       		.uleb128 0x39
 1501 00bc 0B       		.uleb128 0xb
 1502 00bd 3C       		.uleb128 0x3c
 1503 00be 19       		.uleb128 0x19
 1504 00bf 01       		.uleb128 0x1
 1505 00c0 13       		.uleb128 0x13
 1506 00c1 00       		.byte	0
 1507 00c2 00       		.byte	0
 1508 00c3 0F       		.uleb128 0xf
 1509 00c4 05       		.uleb128 0x5
 1510 00c5 00       		.byte	0
 1511 00c6 49       		.uleb128 0x49
 1512 00c7 13       		.uleb128 0x13
 1513 00c8 00       		.byte	0
 1514 00c9 00       		.byte	0
 1515 00ca 10       		.uleb128 0x10
 1516 00cb 2E       		.uleb128 0x2e
 1517 00cc 01       		.byte	0x1
 1518 00cd 3F       		.uleb128 0x3f
 1519 00ce 19       		.uleb128 0x19
 1520 00cf 03       		.uleb128 0x3
 1521 00d0 08       		.uleb128 0x8
 1522 00d1 3A       		.uleb128 0x3a
 1523 00d2 0B       		.uleb128 0xb
 1524 00d3 3B       		.uleb128 0x3b
 1525 00d4 05       		.uleb128 0x5
 1526 00d5 39       		.uleb128 0x39
 1527 00d6 0B       		.uleb128 0xb
 1528 00d7 49       		.uleb128 0x49
 1529 00d8 13       		.uleb128 0x13
 1530 00d9 3C       		.uleb128 0x3c
 1531 00da 19       		.uleb128 0x19
 1532 00db 01       		.uleb128 0x1
 1533 00dc 13       		.uleb128 0x13
 1534 00dd 00       		.byte	0
 1535 00de 00       		.byte	0
 1536 00df 11       		.uleb128 0x11
 1537 00e0 2E       		.uleb128 0x2e
 1538 00e1 01       		.byte	0x1
 1539 00e2 3F       		.uleb128 0x3f
 1540 00e3 19       		.uleb128 0x19
 1541 00e4 03       		.uleb128 0x3
 1542 00e5 08       		.uleb128 0x8
 1543 00e6 3A       		.uleb128 0x3a
 1544 00e7 0B       		.uleb128 0xb
 1545 00e8 3B       		.uleb128 0x3b
 1546 00e9 05       		.uleb128 0x5
 1547 00ea 39       		.uleb128 0x39
 1548 00eb 0B       		.uleb128 0xb
 1549 00ec 6E       		.uleb128 0x6e
 1550 00ed 08       		.uleb128 0x8
 1551 00ee 49       		.uleb128 0x49
 1552 00ef 13       		.uleb128 0x13
 1553 00f0 3C       		.uleb128 0x3c
 1554 00f1 19       		.uleb128 0x19
 1555 00f2 01       		.uleb128 0x1
 1556 00f3 13       		.uleb128 0x13
 1557 00f4 00       		.byte	0
 1558 00f5 00       		.byte	0
 1559 00f6 12       		.uleb128 0x12
 1560 00f7 18       		.uleb128 0x18
 1561 00f8 00       		.byte	0
 1562 00f9 00       		.byte	0
 1563 00fa 00       		.byte	0
 1564 00fb 13       		.uleb128 0x13
 1565 00fc 0F       		.uleb128 0xf
 1566 00fd 00       		.byte	0
 1567 00fe 0B       		.uleb128 0xb
 1568 00ff 0B       		.uleb128 0xb
 1569 0100 00       		.byte	0
 1570 0101 00       		.byte	0
 1571 0102 14       		.uleb128 0x14
 1572 0103 2E       		.uleb128 0x2e
 1573 0104 00       		.byte	0
 1574 0105 3F       		.uleb128 0x3f
 1575 0106 19       		.uleb128 0x19
 1576 0107 03       		.uleb128 0x3
 1577 0108 08       		.uleb128 0x8
 1578 0109 3A       		.uleb128 0x3a
 1579 010a 0B       		.uleb128 0xb
 1580 010b 3B       		.uleb128 0x3b
 1581 010c 05       		.uleb128 0x5
 1582 010d 39       		.uleb128 0x39
 1583 010e 0B       		.uleb128 0xb
 1584 010f 49       		.uleb128 0x49
 1585 0110 13       		.uleb128 0x13
 1586 0111 3C       		.uleb128 0x3c
 1587 0112 19       		.uleb128 0x19
 1588 0113 00       		.byte	0
 1589 0114 00       		.byte	0
 1590 0115 15       		.uleb128 0x15
 1591 0116 2E       		.uleb128 0x2e
 1592 0117 01       		.byte	0x1
 1593 0118 3F       		.uleb128 0x3f
 1594 0119 19       		.uleb128 0x19
 1595 011a 03       		.uleb128 0x3
 1596 011b 08       		.uleb128 0x8
 1597 011c 3A       		.uleb128 0x3a
 1598 011d 0B       		.uleb128 0xb
 1599 011e 3B       		.uleb128 0x3b
 1600 011f 05       		.uleb128 0x5
 1601 0120 39       		.uleb128 0x39
 1602 0121 0B       		.uleb128 0xb
 1603 0122 6E       		.uleb128 0x6e
 1604 0123 08       		.uleb128 0x8
 1605 0124 49       		.uleb128 0x49
 1606 0125 13       		.uleb128 0x13
 1607 0126 11       		.uleb128 0x11
 1608 0127 01       		.uleb128 0x1
 1609 0128 12       		.uleb128 0x12
 1610 0129 07       		.uleb128 0x7
 1611 012a 40       		.uleb128 0x40
 1612 012b 18       		.uleb128 0x18
 1613 012c 9642     		.uleb128 0x2116
 1614 012e 19       		.uleb128 0x19
 1615 012f 01       		.uleb128 0x1
 1616 0130 13       		.uleb128 0x13
 1617 0131 00       		.byte	0
 1618 0132 00       		.byte	0
 1619 0133 16       		.uleb128 0x16
 1620 0134 05       		.uleb128 0x5
 1621 0135 00       		.byte	0
 1622 0136 03       		.uleb128 0x3
 1623 0137 08       		.uleb128 0x8
 1624 0138 3A       		.uleb128 0x3a
 1625 0139 0B       		.uleb128 0xb
 1626 013a 3B       		.uleb128 0x3b
 1627 013b 05       		.uleb128 0x5
 1628 013c 39       		.uleb128 0x39
 1629 013d 0B       		.uleb128 0xb
 1630 013e 49       		.uleb128 0x49
 1631 013f 13       		.uleb128 0x13
 1632 0140 02       		.uleb128 0x2
 1633 0141 18       		.uleb128 0x18
 1634 0142 00       		.byte	0
 1635 0143 00       		.byte	0
 1636 0144 17       		.uleb128 0x17
 1637 0145 34       		.uleb128 0x34
 1638 0146 00       		.byte	0
 1639 0147 03       		.uleb128 0x3
 1640 0148 08       		.uleb128 0x8
 1641 0149 3A       		.uleb128 0x3a
 1642 014a 0B       		.uleb128 0xb
 1643 014b 3B       		.uleb128 0x3b
 1644 014c 05       		.uleb128 0x5
 1645 014d 39       		.uleb128 0x39
 1646 014e 0B       		.uleb128 0xb
 1647 014f 49       		.uleb128 0x49
 1648 0150 13       		.uleb128 0x13
 1649 0151 02       		.uleb128 0x2
 1650 0152 18       		.uleb128 0x18
 1651 0153 00       		.byte	0
 1652 0154 00       		.byte	0
 1653 0155 18       		.uleb128 0x18
 1654 0156 898201   		.uleb128 0x4109
 1655 0159 00       		.byte	0
 1656 015a 11       		.uleb128 0x11
 1657 015b 01       		.uleb128 0x1
 1658 015c 31       		.uleb128 0x31
 1659 015d 13       		.uleb128 0x13
 1660 015e 00       		.byte	0
 1661 015f 00       		.byte	0
 1662 0160 19       		.uleb128 0x19
 1663 0161 34       		.uleb128 0x34
 1664 0162 00       		.byte	0
 1665 0163 03       		.uleb128 0x3
 1666 0164 08       		.uleb128 0x8
 1667 0165 3A       		.uleb128 0x3a
 1668 0166 0B       		.uleb128 0xb
 1669 0167 3B       		.uleb128 0x3b
 1670 0168 0B       		.uleb128 0xb
 1671 0169 39       		.uleb128 0x39
 1672 016a 0B       		.uleb128 0xb
 1673 016b 49       		.uleb128 0x49
 1674 016c 13       		.uleb128 0x13
 1675 016d 02       		.uleb128 0x2
 1676 016e 18       		.uleb128 0x18
 1677 016f 00       		.byte	0
 1678 0170 00       		.byte	0
 1679 0171 1A       		.uleb128 0x1a
 1680 0172 01       		.uleb128 0x1
 1681 0173 01       		.byte	0x1
 1682 0174 49       		.uleb128 0x49
 1683 0175 13       		.uleb128 0x13
 1684 0176 01       		.uleb128 0x1
 1685 0177 13       		.uleb128 0x13
 1686 0178 00       		.byte	0
 1687 0179 00       		.byte	0
 1688 017a 1B       		.uleb128 0x1b
 1689 017b 21       		.uleb128 0x21
 1690 017c 00       		.byte	0
 1691 017d 49       		.uleb128 0x49
 1692 017e 13       		.uleb128 0x13
 1693 017f 2F       		.uleb128 0x2f
 1694 0180 0B       		.uleb128 0xb
 1695 0181 00       		.byte	0
 1696 0182 00       		.byte	0
 1697 0183 1C       		.uleb128 0x1c
 1698 0184 34       		.uleb128 0x34
 1699 0185 00       		.byte	0
 1700 0186 03       		.uleb128 0x3
 1701 0187 08       		.uleb128 0x8
 1702 0188 3A       		.uleb128 0x3a
 1703 0189 0B       		.uleb128 0xb
 1704 018a 3B       		.uleb128 0x3b
 1705 018b 0B       		.uleb128 0xb
 1706 018c 39       		.uleb128 0x39
 1707 018d 0B       		.uleb128 0xb
 1708 018e 49       		.uleb128 0x49
 1709 018f 13       		.uleb128 0x13
 1710 0190 3F       		.uleb128 0x3f
 1711 0191 19       		.uleb128 0x19
 1712 0192 02       		.uleb128 0x2
 1713 0193 18       		.uleb128 0x18
 1714 0194 00       		.byte	0
 1715 0195 00       		.byte	0
 1716 0196 1D       		.uleb128 0x1d
 1717 0197 2E       		.uleb128 0x2e
 1718 0198 01       		.byte	0x1
 1719 0199 3F       		.uleb128 0x3f
 1720 019a 19       		.uleb128 0x19
 1721 019b 03       		.uleb128 0x3
 1722 019c 08       		.uleb128 0x8
 1723 019d 3A       		.uleb128 0x3a
 1724 019e 0B       		.uleb128 0xb
 1725 019f 3B       		.uleb128 0x3b
 1726 01a0 0B       		.uleb128 0xb
 1727 01a1 39       		.uleb128 0x39
 1728 01a2 0B       		.uleb128 0xb
 1729 01a3 49       		.uleb128 0x49
 1730 01a4 13       		.uleb128 0x13
 1731 01a5 11       		.uleb128 0x11
 1732 01a6 01       		.uleb128 0x1
 1733 01a7 12       		.uleb128 0x12
 1734 01a8 07       		.uleb128 0x7
 1735 01a9 40       		.uleb128 0x40
 1736 01aa 18       		.uleb128 0x18
 1737 01ab 9642     		.uleb128 0x2116
 1738 01ad 19       		.uleb128 0x19
 1739 01ae 01       		.uleb128 0x1
 1740 01af 13       		.uleb128 0x13
 1741 01b0 00       		.byte	0
 1742 01b1 00       		.byte	0
 1743 01b2 1E       		.uleb128 0x1e
 1744 01b3 2E       		.uleb128 0x2e
 1745 01b4 01       		.byte	0x1
 1746 01b5 3F       		.uleb128 0x3f
 1747 01b6 19       		.uleb128 0x19
 1748 01b7 03       		.uleb128 0x3
 1749 01b8 08       		.uleb128 0x8
 1750 01b9 3A       		.uleb128 0x3a
 1751 01ba 0B       		.uleb128 0xb
 1752 01bb 3B       		.uleb128 0x3b
 1753 01bc 0B       		.uleb128 0xb
 1754 01bd 39       		.uleb128 0x39
 1755 01be 0B       		.uleb128 0xb
 1756 01bf 6E       		.uleb128 0x6e
 1757 01c0 08       		.uleb128 0x8
 1758 01c1 49       		.uleb128 0x49
 1759 01c2 13       		.uleb128 0x13
 1760 01c3 11       		.uleb128 0x11
 1761 01c4 01       		.uleb128 0x1
 1762 01c5 12       		.uleb128 0x12
 1763 01c6 07       		.uleb128 0x7
 1764 01c7 40       		.uleb128 0x40
 1765 01c8 18       		.uleb128 0x18
 1766 01c9 9642     		.uleb128 0x2116
 1767 01cb 19       		.uleb128 0x19
 1768 01cc 01       		.uleb128 0x1
 1769 01cd 13       		.uleb128 0x13
 1770 01ce 00       		.byte	0
 1771 01cf 00       		.byte	0
 1772 01d0 1F       		.uleb128 0x1f
 1773 01d1 05       		.uleb128 0x5
 1774 01d2 00       		.byte	0
 1775 01d3 03       		.uleb128 0x3
 1776 01d4 08       		.uleb128 0x8
 1777 01d5 3A       		.uleb128 0x3a
 1778 01d6 0B       		.uleb128 0xb
 1779 01d7 3B       		.uleb128 0x3b
 1780 01d8 0B       		.uleb128 0xb
 1781 01d9 39       		.uleb128 0x39
 1782 01da 0B       		.uleb128 0xb
 1783 01db 49       		.uleb128 0x49
 1784 01dc 13       		.uleb128 0x13
 1785 01dd 02       		.uleb128 0x2
 1786 01de 18       		.uleb128 0x18
 1787 01df 00       		.byte	0
 1788 01e0 00       		.byte	0
 1789 01e1 20       		.uleb128 0x20
 1790 01e2 2E       		.uleb128 0x2e
 1791 01e3 00       		.byte	0
 1792 01e4 3F       		.uleb128 0x3f
 1793 01e5 19       		.uleb128 0x19
 1794 01e6 3C       		.uleb128 0x3c
 1795 01e7 19       		.uleb128 0x19
 1796 01e8 6E       		.uleb128 0x6e
 1797 01e9 0E       		.uleb128 0xe
 1798 01ea 03       		.uleb128 0x3
 1799 01eb 0E       		.uleb128 0xe
 1800 01ec 3A       		.uleb128 0x3a
 1801 01ed 0B       		.uleb128 0xb
 1802 01ee 3B       		.uleb128 0x3b
 1803 01ef 0B       		.uleb128 0xb
 1804 01f0 39       		.uleb128 0x39
 1805 01f1 0B       		.uleb128 0xb
 1806 01f2 00       		.byte	0
 1807 01f3 00       		.byte	0
 1808 01f4 00       		.byte	0
 1809              		.section	.debug_aranges,"dr"
 1810 0000 3C000000 		.long	0x3c
 1811 0004 0200     		.word	0x2
 1812 0006 00000000 		.secrel32	.Ldebug_info0
 1813 000a 08       		.byte	0x8
 1814 000b 00       		.byte	0
 1815 000c 0000     		.word	0
 1816 000e 0000     		.word	0
 1817 0010 00000000 		.quad	.Ltext0
 1817      00000000 
 1818 0018 59010000 		.quad	.Letext0-.Ltext0
 1818      00000000 
 1819 0020 00000000 		.quad	.LFB2
 1819      00000000 
 1820 0028 54000000 		.quad	.LFE2-.LFB2
 1820      00000000 
 1821 0030 00000000 		.quad	0
 1821      00000000 
 1822 0038 00000000 		.quad	0
 1822      00000000 
 1823              		.section	.debug_ranges,"dr"
 1824              	.Ldebug_ranges0:
 1825 0000 00000000 		.quad	.Ltext0
 1825      00000000 
 1826 0008 59010000 		.quad	.Letext0
 1826      00000000 
 1827 0010 00000000 		.quad	.LFB2
 1827      00000000 
 1828 0018 54000000 		.quad	.LFE2
 1828      00000000 
 1829 0020 00000000 		.quad	0
 1829      00000000 
 1830 0028 00000000 		.quad	0
 1830      00000000 
 1831              		.section	.debug_line,"dr"
 1832              	.Ldebug_line0:
 1833 0000 B7020000 		.section	.debug_str,"dr"
 1833      0200C201 
 1833      00000101 
 1833      FB0E0D00 
 1833      01010101 
 1834              	.LASF0:
 1835 0000 5F5F6163 		.ascii "__acrt_iob_func\0"
 1835      72745F69 
 1835      6F625F66 
 1835      756E6300 
 1836              		.ident	"GCC: (x86_64-win32-seh-rev0, Built by MinGW-W64 project) 8.1.0"
