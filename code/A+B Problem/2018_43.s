   1              		.file	"2018_4.cpp"
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
  61 0054 90909090 		.section	.text$_Z6printfPKcz,"x"
  61      90909090 
  61      90909090 
  62              		.linkonce discard
  63              		.globl	_Z6printfPKcz
  65              		.seh_proc	_Z6printfPKcz
  66              	_Z6printfPKcz:
  67              	.LFB8:
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
 114              	.LFE8:
 115              		.seh_endproc
 117 0054 90909090 		.section .rdata,"dr"
 117      90909090 
 117      90909090 
 118              	.LC0:
 119 0000 25642564 		.ascii "%d%d\0"
 119      00
 120              	.LC1:
 121 0005 256400   		.ascii "%d\0"
 122 0008 00000000 		.text
 122      00000000 
 123              		.globl	main
 125              		.seh_proc	main
 126              	main:
 127              	.LFB44:
 128              		.file 2 "A+B Problem/2018_4.cpp"
   1:A+B Problem/2018_4.cpp **** #include <cstdio>
   2:A+B Problem/2018_4.cpp **** 
   3:A+B Problem/2018_4.cpp **** int main()
   4:A+B Problem/2018_4.cpp **** {
 129              		.loc 2 4 1
 130              		.cfi_startproc
 131 0000 55       		pushq	%rbp
 132              		.seh_pushreg	%rbp
 133              		.cfi_def_cfa_offset 16
 134              		.cfi_offset 6, -16
 135 0001 4889E5   		movq	%rsp, %rbp
 136              		.seh_setframe	%rbp, 0
 137              		.cfi_def_cfa_register 6
 138 0004 4883EC30 		subq	$48, %rsp
 139              		.seh_stackalloc	48
 140              		.seh_endprologue
 141              		.loc 2 4 1
 142 0008 E8000000 		call	__main
 142      00
 143              	.LVL2:
   5:A+B Problem/2018_4.cpp **** 	int a, b;
   6:A+B Problem/2018_4.cpp **** 	scanf("%d%d", &a, &b);
 144              		.loc 2 6 7
 145 000d 488D55F8 		leaq	-8(%rbp), %rdx
 146 0011 488D45FC 		leaq	-4(%rbp), %rax
 147 0015 4989D0   		movq	%rdx, %r8
 148 0018 4889C2   		movq	%rax, %rdx
 149 001b 488D0D00 		leaq	.LC0(%rip), %rcx
 149      000000
 150 0022 E8000000 		call	_Z5scanfPKcz
 150      00
   7:A+B Problem/2018_4.cpp **** 	printf("%d", a + b);
 151              		.loc 2 7 8
 152 0027 8B55FC   		movl	-4(%rbp), %edx
 153 002a 8B45F8   		movl	-8(%rbp), %eax
 154 002d 01D0     		addl	%edx, %eax
 155 002f 89C2     		movl	%eax, %edx
 156 0031 488D0D05 		leaq	.LC1(%rip), %rcx
 156      000000
 157 0038 E8000000 		call	_Z6printfPKcz
 157      00
   8:A+B Problem/2018_4.cpp **** 	return 0;
 158              		.loc 2 8 9
 159 003d B8000000 		movl	$0, %eax
 159      00
   9:A+B Problem/2018_4.cpp **** }...
 160              		.loc 2 9 1
 161 0042 4883C430 		addq	$48, %rsp
 162 0046 5D       		popq	%rbp
 163              		.cfi_restore 6
 164              		.cfi_def_cfa 7, 8
 165 0047 C3       		ret
 166              		.cfi_endproc
 167              	.LFE44:
 168              		.seh_endproc
 169              	.Letext0:
 170              		.file 3 "C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-m
 171              		.file 4 "C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-m
 172              		.file 5 "C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/i
 173              		.file 6 "<built-in>"
 174 0048 90909090 		.section	.debug_info,"dr"
 174      90909090 
 175              	.Ldebug_info0:
 176 0000 730A0000 		.long	0xa73
 177 0004 0400     		.word	0x4
 178 0006 00000000 		.secrel32	.Ldebug_abbrev0
 179 000a 08       		.byte	0x8
 180 000b 01       		.uleb128 0x1
 181 000c 474E5520 		.ascii "GNU C++98 8.1.0 -mtune=core2 -march=nocona -g -std=gnu++98\0"
 181      432B2B39 
 181      3820382E 
 181      312E3020 
 181      2D6D7475 
 182 0047 04       		.byte	0x4
 183 0048 412B4220 		.ascii "A+B Problem/2018_4.cpp\0"
 183      50726F62 
 183      6C656D2F 
 183      32303138 
 183      5F342E63 
 184 005f 453A5C63 		.ascii "E:\\code\\C++\0"
 184      6F64655C 
 184      432B2B00 
 185 006b 00000000 		.secrel32	.Ldebug_ranges0+0
 186 006f 00000000 		.quad	0
 186      00000000 
 187 0077 00000000 		.secrel32	.Ldebug_line0
 188 007b 02       		.uleb128 0x2
 189 007c 73746400 		.ascii "std\0"
 190 0080 06       		.byte	0x6
 191 0081 00       		.byte	0
 192 0082 ED010000 		.long	0x1ed
 193 0086 03       		.uleb128 0x3
 194 0087 5F5F6378 		.ascii "__cxx11\0"
 194      78313100 
 195 008f 04       		.byte	0x4
 196 0090 0401     		.word	0x104
 197 0092 41       		.byte	0x41
 198 0093 04       		.uleb128 0x4
 199 0094 04       		.byte	0x4
 200 0095 0401     		.word	0x104
 201 0097 41       		.byte	0x41
 202 0098 86000000 		.long	0x86
 203 009c 05       		.uleb128 0x5
 204 009d 03       		.byte	0x3
 205 009e 62       		.byte	0x62
 206 009f 0B       		.byte	0xb
 207 00a0 9E030000 		.long	0x39e
 208 00a4 05       		.uleb128 0x5
 209 00a5 03       		.byte	0x3
 210 00a6 63       		.byte	0x63
 211 00a7 0B       		.byte	0xb
 212 00a8 AB030000 		.long	0x3ab
 213 00ac 05       		.uleb128 0x5
 214 00ad 03       		.byte	0x3
 215 00ae 65       		.byte	0x65
 216 00af 0B       		.byte	0xb
 217 00b0 BF030000 		.long	0x3bf
 218 00b4 05       		.uleb128 0x5
 219 00b5 03       		.byte	0x3
 220 00b6 66       		.byte	0x66
 221 00b7 0B       		.byte	0xb
 222 00b8 DD030000 		.long	0x3dd
 223 00bc 05       		.uleb128 0x5
 224 00bd 03       		.byte	0x3
 225 00be 67       		.byte	0x67
 226 00bf 0B       		.byte	0xb
 227 00c0 F7030000 		.long	0x3f7
 228 00c4 05       		.uleb128 0x5
 229 00c5 03       		.byte	0x3
 230 00c6 68       		.byte	0x68
 231 00c7 0B       		.byte	0xb
 232 00c8 0F040000 		.long	0x40f
 233 00cc 05       		.uleb128 0x5
 234 00cd 03       		.byte	0x3
 235 00ce 69       		.byte	0x69
 236 00cf 0B       		.byte	0xb
 237 00d0 29040000 		.long	0x429
 238 00d4 05       		.uleb128 0x5
 239 00d5 03       		.byte	0x3
 240 00d6 6A       		.byte	0x6a
 241 00d7 0B       		.byte	0xb
 242 00d8 43040000 		.long	0x443
 243 00dc 05       		.uleb128 0x5
 244 00dd 03       		.byte	0x3
 245 00de 6B       		.byte	0x6b
 246 00df 0B       		.byte	0xb
 247 00e0 5C040000 		.long	0x45c
 248 00e4 05       		.uleb128 0x5
 249 00e5 03       		.byte	0x3
 250 00e6 6C       		.byte	0x6c
 251 00e7 0B       		.byte	0xb
 252 00e8 82040000 		.long	0x482
 253 00ec 05       		.uleb128 0x5
 254 00ed 03       		.byte	0x3
 255 00ee 6D       		.byte	0x6d
 256 00ef 0B       		.byte	0xb
 257 00f0 A5040000 		.long	0x4a5
 258 00f4 05       		.uleb128 0x5
 259 00f5 03       		.byte	0x3
 260 00f6 6E       		.byte	0x6e
 261 00f7 0B       		.byte	0xb
 262 00f8 C9040000 		.long	0x4c9
 263 00fc 05       		.uleb128 0x5
 264 00fd 03       		.byte	0x3
 265 00fe 71       		.byte	0x71
 266 00ff 0B       		.byte	0xb
 267 0100 01050000 		.long	0x501
 268 0104 05       		.uleb128 0x5
 269 0105 03       		.byte	0x3
 270 0106 72       		.byte	0x72
 271 0107 0B       		.byte	0xb
 272 0108 2B050000 		.long	0x52b
 273 010c 05       		.uleb128 0x5
 274 010d 03       		.byte	0x3
 275 010e 73       		.byte	0x73
 276 010f 0B       		.byte	0xb
 277 0110 50050000 		.long	0x550
 278 0114 05       		.uleb128 0x5
 279 0115 03       		.byte	0x3
 280 0116 74       		.byte	0x74
 281 0117 0B       		.byte	0xb
 282 0118 86050000 		.long	0x586
 283 011c 05       		.uleb128 0x5
 284 011d 03       		.byte	0x3
 285 011e 75       		.byte	0x75
 286 011f 0B       		.byte	0xb
 287 0120 A9050000 		.long	0x5a9
 288 0124 05       		.uleb128 0x5
 289 0125 03       		.byte	0x3
 290 0126 76       		.byte	0x76
 291 0127 0B       		.byte	0xb
 292 0128 CF050000 		.long	0x5cf
 293 012c 05       		.uleb128 0x5
 294 012d 03       		.byte	0x3
 295 012e 78       		.byte	0x78
 296 012f 0B       		.byte	0xb
 297 0130 E8050000 		.long	0x5e8
 298 0134 05       		.uleb128 0x5
 299 0135 03       		.byte	0x3
 300 0136 79       		.byte	0x79
 301 0137 0B       		.byte	0xb
 302 0138 00060000 		.long	0x600
 303 013c 05       		.uleb128 0x5
 304 013d 03       		.byte	0x3
 305 013e 7C       		.byte	0x7c
 306 013f 0B       		.byte	0xb
 307 0140 11060000 		.long	0x611
 308 0144 05       		.uleb128 0x5
 309 0145 03       		.byte	0x3
 310 0146 7E       		.byte	0x7e
 311 0147 0B       		.byte	0xb
 312 0148 29060000 		.long	0x629
 313 014c 05       		.uleb128 0x5
 314 014d 03       		.byte	0x3
 315 014e 7F       		.byte	0x7f
 316 014f 0B       		.byte	0xb
 317 0150 3F060000 		.long	0x63f
 318 0154 05       		.uleb128 0x5
 319 0155 03       		.byte	0x3
 320 0156 83       		.byte	0x83
 321 0157 0B       		.byte	0xb
 322 0158 B3060000 		.long	0x6b3
 323 015c 05       		.uleb128 0x5
 324 015d 03       		.byte	0x3
 325 015e 84       		.byte	0x84
 326 015f 0B       		.byte	0xb
 327 0160 CD060000 		.long	0x6cd
 328 0164 05       		.uleb128 0x5
 329 0165 03       		.byte	0x3
 330 0166 85       		.byte	0x85
 331 0167 0B       		.byte	0xb
 332 0168 EC060000 		.long	0x6ec
 333 016c 05       		.uleb128 0x5
 334 016d 03       		.byte	0x3
 335 016e 86       		.byte	0x86
 336 016f 0B       		.byte	0xb
 337 0170 02070000 		.long	0x702
 338 0174 05       		.uleb128 0x5
 339 0175 03       		.byte	0x3
 340 0176 87       		.byte	0x87
 341 0177 0B       		.byte	0xb
 342 0178 74070000 		.long	0x774
 343 017c 05       		.uleb128 0x5
 344 017d 03       		.byte	0x3
 345 017e 88       		.byte	0x88
 346 017f 0B       		.byte	0xb
 347 0180 8F070000 		.long	0x78f
 348 0184 05       		.uleb128 0x5
 349 0185 03       		.byte	0x3
 350 0186 89       		.byte	0x89
 351 0187 0B       		.byte	0xb
 352 0188 B9070000 		.long	0x7b9
 353 018c 05       		.uleb128 0x5
 354 018d 03       		.byte	0x3
 355 018e 8A       		.byte	0x8a
 356 018f 0B       		.byte	0xb
 357 0190 EB070000 		.long	0x7eb
 358 0194 05       		.uleb128 0x5
 359 0195 03       		.byte	0x3
 360 0196 8B       		.byte	0x8b
 361 0197 0B       		.byte	0xb
 362 0198 1C080000 		.long	0x81c
 363 019c 05       		.uleb128 0x5
 364 019d 03       		.byte	0x3
 365 019e 8D       		.byte	0x8d
 366 019f 0B       		.byte	0xb
 367 01a0 2D080000 		.long	0x82d
 368 01a4 05       		.uleb128 0x5
 369 01a5 03       		.byte	0x3
 370 01a6 8F       		.byte	0x8f
 371 01a7 0B       		.byte	0xb
 372 01a8 47080000 		.long	0x847
 373 01ac 05       		.uleb128 0x5
 374 01ad 03       		.byte	0x3
 375 01ae 90       		.byte	0x90
 376 01af 0B       		.byte	0xb
 377 01b0 66080000 		.long	0x866
 378 01b4 05       		.uleb128 0x5
 379 01b5 03       		.byte	0x3
 380 01b6 91       		.byte	0x91
 381 01b7 0B       		.byte	0xb
 382 01b8 A5080000 		.long	0x8a5
 383 01bc 05       		.uleb128 0x5
 384 01bd 03       		.byte	0x3
 385 01be 92       		.byte	0x92
 386 01bf 0B       		.byte	0xb
 387 01c0 D5080000 		.long	0x8d5
 388 01c4 05       		.uleb128 0x5
 389 01c5 03       		.byte	0x3
 390 01c6 B9       		.byte	0xb9
 391 01c7 16       		.byte	0x16
 392 01c8 0E090000 		.long	0x90e
 393 01cc 05       		.uleb128 0x5
 394 01cd 03       		.byte	0x3
 395 01ce BA       		.byte	0xba
 396 01cf 16       		.byte	0x16
 397 01d0 48090000 		.long	0x948
 398 01d4 05       		.uleb128 0x5
 399 01d5 03       		.byte	0x3
 400 01d6 BB       		.byte	0xbb
 401 01d7 16       		.byte	0x16
 402 01d8 85090000 		.long	0x985
 403 01dc 05       		.uleb128 0x5
 404 01dd 03       		.byte	0x3
 405 01de BC       		.byte	0xbc
 406 01df 16       		.byte	0x16
 407 01e0 B3090000 		.long	0x9b3
 408 01e4 05       		.uleb128 0x5
 409 01e5 03       		.byte	0x3
 410 01e6 BD       		.byte	0xbd
 411 01e7 16       		.byte	0x16
 412 01e8 F4090000 		.long	0x9f4
 413 01ec 00       		.byte	0
 414 01ed 06       		.uleb128 0x6
 415 01ee 5F5F676E 		.ascii "__gnu_cxx\0"
 415      755F6378 
 415      7800
 416 01f8 04       		.byte	0x4
 417 01f9 0601     		.word	0x106
 418 01fb 0B       		.byte	0xb
 419 01fc 3F020000 		.long	0x23f
 420 0200 03       		.uleb128 0x3
 421 0201 5F5F6378 		.ascii "__cxx11\0"
 421      78313100 
 422 0209 04       		.byte	0x4
 423 020a 0801     		.word	0x108
 424 020c 41       		.byte	0x41
 425 020d 04       		.uleb128 0x4
 426 020e 04       		.byte	0x4
 427 020f 0801     		.word	0x108
 428 0211 41       		.byte	0x41
 429 0212 00020000 		.long	0x200
 430 0216 05       		.uleb128 0x5
 431 0217 03       		.byte	0x3
 432 0218 AF       		.byte	0xaf
 433 0219 0B       		.byte	0xb
 434 021a 0E090000 		.long	0x90e
 435 021e 05       		.uleb128 0x5
 436 021f 03       		.byte	0x3
 437 0220 B0       		.byte	0xb0
 438 0221 0B       		.byte	0xb
 439 0222 48090000 		.long	0x948
 440 0226 05       		.uleb128 0x5
 441 0227 03       		.byte	0x3
 442 0228 B1       		.byte	0xb1
 443 0229 0B       		.byte	0xb
 444 022a 85090000 		.long	0x985
 445 022e 05       		.uleb128 0x5
 446 022f 03       		.byte	0x3
 447 0230 B2       		.byte	0xb2
 448 0231 0B       		.byte	0xb
 449 0232 B3090000 		.long	0x9b3
 450 0236 05       		.uleb128 0x5
 451 0237 03       		.byte	0x3
 452 0238 B3       		.byte	0xb3
 453 0239 0B       		.byte	0xb
 454 023a F4090000 		.long	0x9f4
 455 023e 00       		.byte	0
 456 023f 07       		.uleb128 0x7
 457 0240 08       		.byte	0x8
 458 0241 5F5F6275 		.ascii "__builtin_va_list\0"
 458      696C7469 
 458      6E5F7661 
 458      5F6C6973 
 458      7400
 459 0253 57020000 		.long	0x257
 460 0257 08       		.uleb128 0x8
 461 0258 01       		.byte	0x1
 462 0259 06       		.byte	0x6
 463 025a 63686172 		.ascii "char\0"
 463      00
 464 025f 09       		.uleb128 0x9
 465 0260 57020000 		.long	0x257
 466 0264 0A       		.uleb128 0xa
 467 0265 73697A65 		.ascii "size_t\0"
 467      5F7400
 468 026c 05       		.byte	0x5
 469 026d 23       		.byte	0x23
 470 026e 2C       		.byte	0x2c
 471 026f 73020000 		.long	0x273
 472 0273 08       		.uleb128 0x8
 473 0274 08       		.byte	0x8
 474 0275 07       		.byte	0x7
 475 0276 6C6F6E67 		.ascii "long long unsigned int\0"
 475      206C6F6E 
 475      6720756E 
 475      7369676E 
 475      65642069 
 476 028d 08       		.uleb128 0x8
 477 028e 08       		.byte	0x8
 478 028f 05       		.byte	0x5
 479 0290 6C6F6E67 		.ascii "long long int\0"
 479      206C6F6E 
 479      6720696E 
 479      7400
 480 029e 08       		.uleb128 0x8
 481 029f 02       		.byte	0x2
 482 02a0 07       		.byte	0x7
 483 02a1 73686F72 		.ascii "short unsigned int\0"
 483      7420756E 
 483      7369676E 
 483      65642069 
 483      6E7400
 484 02b4 08       		.uleb128 0x8
 485 02b5 04       		.byte	0x4
 486 02b6 05       		.byte	0x5
 487 02b7 696E7400 		.ascii "int\0"
 488 02bb 08       		.uleb128 0x8
 489 02bc 04       		.byte	0x4
 490 02bd 05       		.byte	0x5
 491 02be 6C6F6E67 		.ascii "long int\0"
 491      20696E74 
 491      00
 492 02c7 0B       		.uleb128 0xb
 493 02c8 08       		.byte	0x8
 494 02c9 57020000 		.long	0x257
 495 02cd 08       		.uleb128 0x8
 496 02ce 02       		.byte	0x2
 497 02cf 07       		.byte	0x7
 498 02d0 77636861 		.ascii "wchar_t\0"
 498      725F7400 
 499 02d8 08       		.uleb128 0x8
 500 02d9 04       		.byte	0x4
 501 02da 07       		.byte	0x7
 502 02db 756E7369 		.ascii "unsigned int\0"
 502      676E6564 
 502      20696E74 
 502      00
 503 02e8 08       		.uleb128 0x8
 504 02e9 04       		.byte	0x4
 505 02ea 07       		.byte	0x7
 506 02eb 6C6F6E67 		.ascii "long unsigned int\0"
 506      20756E73 
 506      69676E65 
 506      6420696E 
 506      7400
 507 02fd 08       		.uleb128 0x8
 508 02fe 01       		.byte	0x1
 509 02ff 08       		.byte	0x8
 510 0300 756E7369 		.ascii "unsigned char\0"
 510      676E6564 
 510      20636861 
 510      7200
 511 030e 0C       		.uleb128 0xc
 512 030f 5F696F62 		.ascii "_iobuf\0"
 512      756600
 513 0316 30       		.byte	0x30
 514 0317 01       		.byte	0x1
 515 0318 1A       		.byte	0x1a
 516 0319 0A       		.byte	0xa
 517 031a 9E030000 		.long	0x39e
 518 031e 0D       		.uleb128 0xd
 519 031f 5F707472 		.ascii "_ptr\0"
 519      00
 520 0324 01       		.byte	0x1
 521 0325 1B       		.byte	0x1b
 522 0326 0B       		.byte	0xb
 523 0327 C7020000 		.long	0x2c7
 524 032b 00       		.byte	0
 525 032c 0D       		.uleb128 0xd
 526 032d 5F636E74 		.ascii "_cnt\0"
 526      00
 527 0332 01       		.byte	0x1
 528 0333 1C       		.byte	0x1c
 529 0334 09       		.byte	0x9
 530 0335 B4020000 		.long	0x2b4
 531 0339 08       		.byte	0x8
 532 033a 0D       		.uleb128 0xd
 533 033b 5F626173 		.ascii "_base\0"
 533      6500
 534 0341 01       		.byte	0x1
 535 0342 1D       		.byte	0x1d
 536 0343 0B       		.byte	0xb
 537 0344 C7020000 		.long	0x2c7
 538 0348 10       		.byte	0x10
 539 0349 0D       		.uleb128 0xd
 540 034a 5F666C61 		.ascii "_flag\0"
 540      6700
 541 0350 01       		.byte	0x1
 542 0351 1E       		.byte	0x1e
 543 0352 09       		.byte	0x9
 544 0353 B4020000 		.long	0x2b4
 545 0357 18       		.byte	0x18
 546 0358 0D       		.uleb128 0xd
 547 0359 5F66696C 		.ascii "_file\0"
 547      6500
 548 035f 01       		.byte	0x1
 549 0360 1F       		.byte	0x1f
 550 0361 09       		.byte	0x9
 551 0362 B4020000 		.long	0x2b4
 552 0366 1C       		.byte	0x1c
 553 0367 0D       		.uleb128 0xd
 554 0368 5F636861 		.ascii "_charbuf\0"
 554      72627566 
 554      00
 555 0371 01       		.byte	0x1
 556 0372 20       		.byte	0x20
 557 0373 09       		.byte	0x9
 558 0374 B4020000 		.long	0x2b4
 559 0378 20       		.byte	0x20
 560 0379 0D       		.uleb128 0xd
 561 037a 5F627566 		.ascii "_bufsiz\0"
 561      73697A00 
 562 0382 01       		.byte	0x1
 563 0383 21       		.byte	0x21
 564 0384 09       		.byte	0x9
 565 0385 B4020000 		.long	0x2b4
 566 0389 24       		.byte	0x24
 567 038a 0D       		.uleb128 0xd
 568 038b 5F746D70 		.ascii "_tmpfname\0"
 568      666E616D 
 568      6500
 569 0395 01       		.byte	0x1
 570 0396 22       		.byte	0x22
 571 0397 0B       		.byte	0xb
 572 0398 C7020000 		.long	0x2c7
 573 039c 28       		.byte	0x28
 574 039d 00       		.byte	0
 575 039e 0A       		.uleb128 0xa
 576 039f 46494C45 		.ascii "FILE\0"
 576      00
 577 03a4 01       		.byte	0x1
 578 03a5 24       		.byte	0x24
 579 03a6 19       		.byte	0x19
 580 03a7 0E030000 		.long	0x30e
 581 03ab 0A       		.uleb128 0xa
 582 03ac 66706F73 		.ascii "fpos_t\0"
 582      5F7400
 583 03b3 01       		.byte	0x1
 584 03b4 68       		.byte	0x68
 585 03b5 25       		.byte	0x25
 586 03b6 8D020000 		.long	0x28d
 587 03ba 09       		.uleb128 0x9
 588 03bb AB030000 		.long	0x3ab
 589 03bf 0E       		.uleb128 0xe
 590 03c0 636C6561 		.ascii "clearerr\0"
 590      72657272 
 590      00
 591 03c9 01       		.byte	0x1
 592 03ca 4202     		.word	0x242
 593 03cc 10       		.byte	0x10
 594 03cd D7030000 		.long	0x3d7
 595 03d1 0F       		.uleb128 0xf
 596 03d2 D7030000 		.long	0x3d7
 597 03d6 00       		.byte	0
 598 03d7 0B       		.uleb128 0xb
 599 03d8 08       		.byte	0x8
 600 03d9 9E030000 		.long	0x39e
 601 03dd 10       		.uleb128 0x10
 602 03de 66636C6F 		.ascii "fclose\0"
 602      736500
 603 03e5 01       		.byte	0x1
 604 03e6 4302     		.word	0x243
 605 03e8 0F       		.byte	0xf
 606 03e9 B4020000 		.long	0x2b4
 607 03ed F7030000 		.long	0x3f7
 608 03f1 0F       		.uleb128 0xf
 609 03f2 D7030000 		.long	0x3d7
 610 03f6 00       		.byte	0
 611 03f7 10       		.uleb128 0x10
 612 03f8 66656F66 		.ascii "feof\0"
 612      00
 613 03fd 01       		.byte	0x1
 614 03fe 4A02     		.word	0x24a
 615 0400 0F       		.byte	0xf
 616 0401 B4020000 		.long	0x2b4
 617 0405 0F040000 		.long	0x40f
 618 0409 0F       		.uleb128 0xf
 619 040a D7030000 		.long	0x3d7
 620 040e 00       		.byte	0
 621 040f 10       		.uleb128 0x10
 622 0410 66657272 		.ascii "ferror\0"
 622      6F7200
 623 0417 01       		.byte	0x1
 624 0418 4B02     		.word	0x24b
 625 041a 0F       		.byte	0xf
 626 041b B4020000 		.long	0x2b4
 627 041f 29040000 		.long	0x429
 628 0423 0F       		.uleb128 0xf
 629 0424 D7030000 		.long	0x3d7
 630 0428 00       		.byte	0
 631 0429 10       		.uleb128 0x10
 632 042a 66666C75 		.ascii "fflush\0"
 632      736800
 633 0431 01       		.byte	0x1
 634 0432 4C02     		.word	0x24c
 635 0434 0F       		.byte	0xf
 636 0435 B4020000 		.long	0x2b4
 637 0439 43040000 		.long	0x443
 638 043d 0F       		.uleb128 0xf
 639 043e D7030000 		.long	0x3d7
 640 0442 00       		.byte	0
 641 0443 10       		.uleb128 0x10
 642 0444 66676574 		.ascii "fgetc\0"
 642      6300
 643 044a 01       		.byte	0x1
 644 044b 4D02     		.word	0x24d
 645 044d 0F       		.byte	0xf
 646 044e B4020000 		.long	0x2b4
 647 0452 5C040000 		.long	0x45c
 648 0456 0F       		.uleb128 0xf
 649 0457 D7030000 		.long	0x3d7
 650 045b 00       		.byte	0
 651 045c 10       		.uleb128 0x10
 652 045d 66676574 		.ascii "fgetpos\0"
 652      706F7300 
 653 0465 01       		.byte	0x1
 654 0466 4F02     		.word	0x24f
 655 0468 0F       		.byte	0xf
 656 0469 B4020000 		.long	0x2b4
 657 046d 7C040000 		.long	0x47c
 658 0471 0F       		.uleb128 0xf
 659 0472 D7030000 		.long	0x3d7
 660 0476 0F       		.uleb128 0xf
 661 0477 7C040000 		.long	0x47c
 662 047b 00       		.byte	0
 663 047c 0B       		.uleb128 0xb
 664 047d 08       		.byte	0x8
 665 047e AB030000 		.long	0x3ab
 666 0482 10       		.uleb128 0x10
 667 0483 66676574 		.ascii "fgets\0"
 667      7300
 668 0489 01       		.byte	0x1
 669 048a 5102     		.word	0x251
 670 048c 11       		.byte	0x11
 671 048d C7020000 		.long	0x2c7
 672 0491 A5040000 		.long	0x4a5
 673 0495 0F       		.uleb128 0xf
 674 0496 C7020000 		.long	0x2c7
 675 049a 0F       		.uleb128 0xf
 676 049b B4020000 		.long	0x2b4
 677 049f 0F       		.uleb128 0xf
 678 04a0 D7030000 		.long	0x3d7
 679 04a4 00       		.byte	0
 680 04a5 10       		.uleb128 0x10
 681 04a6 666F7065 		.ascii "fopen\0"
 681      6E00
 682 04ac 01       		.byte	0x1
 683 04ad 5802     		.word	0x258
 684 04af 11       		.byte	0x11
 685 04b0 D7030000 		.long	0x3d7
 686 04b4 C3040000 		.long	0x4c3
 687 04b8 0F       		.uleb128 0xf
 688 04b9 C3040000 		.long	0x4c3
 689 04bd 0F       		.uleb128 0xf
 690 04be C3040000 		.long	0x4c3
 691 04c2 00       		.byte	0
 692 04c3 0B       		.uleb128 0xb
 693 04c4 08       		.byte	0x8
 694 04c5 5F020000 		.long	0x25f
 695 04c9 11       		.uleb128 0x11
 696 04ca 66707269 		.ascii "fprintf\0"
 696      6E746600 
 697 04d2 01       		.byte	0x1
 698 04d3 4E01     		.word	0x14e
 699 04d5 05       		.byte	0x5
 700 04d6 5F5A3766 		.ascii "_Z7fprintfP6_iobufPKcz\0"
 700      7072696E 
 700      74665036 
 700      5F696F62 
 700      7566504B 
 701 04ed B4020000 		.long	0x2b4
 702 04f1 01050000 		.long	0x501
 703 04f5 0F       		.uleb128 0xf
 704 04f6 D7030000 		.long	0x3d7
 705 04fa 0F       		.uleb128 0xf
 706 04fb C3040000 		.long	0x4c3
 707 04ff 12       		.uleb128 0x12
 708 0500 00       		.byte	0
 709 0501 10       		.uleb128 0x10
 710 0502 66726561 		.ascii "fread\0"
 710      6400
 711 0508 01       		.byte	0x1
 712 0509 5D02     		.word	0x25d
 713 050b 12       		.byte	0x12
 714 050c 64020000 		.long	0x264
 715 0510 29050000 		.long	0x529
 716 0514 0F       		.uleb128 0xf
 717 0515 29050000 		.long	0x529
 718 0519 0F       		.uleb128 0xf
 719 051a 64020000 		.long	0x264
 720 051e 0F       		.uleb128 0xf
 721 051f 64020000 		.long	0x264
 722 0523 0F       		.uleb128 0xf
 723 0524 D7030000 		.long	0x3d7
 724 0528 00       		.byte	0
 725 0529 13       		.uleb128 0x13
 726 052a 08       		.byte	0x8
 727 052b 10       		.uleb128 0x10
 728 052c 6672656F 		.ascii "freopen\0"
 728      70656E00 
 729 0534 01       		.byte	0x1
 730 0535 5E02     		.word	0x25e
 731 0537 11       		.byte	0x11
 732 0538 D7030000 		.long	0x3d7
 733 053c 50050000 		.long	0x550
 734 0540 0F       		.uleb128 0xf
 735 0541 C3040000 		.long	0x4c3
 736 0545 0F       		.uleb128 0xf
 737 0546 C3040000 		.long	0x4c3
 738 054a 0F       		.uleb128 0xf
 739 054b D7030000 		.long	0x3d7
 740 054f 00       		.byte	0
 741 0550 11       		.uleb128 0x11
 742 0551 66736361 		.ascii "fscanf\0"
 742      6E6600
 743 0558 01       		.byte	0x1
 744 0559 2101     		.word	0x121
 745 055b 05       		.byte	0x5
 746 055c 5F5A3666 		.ascii "_Z6fscanfP6_iobufPKcz\0"
 746      7363616E 
 746      6650365F 
 746      696F6275 
 746      66504B63 
 747 0572 B4020000 		.long	0x2b4
 748 0576 86050000 		.long	0x586
 749 057a 0F       		.uleb128 0xf
 750 057b D7030000 		.long	0x3d7
 751 057f 0F       		.uleb128 0xf
 752 0580 C3040000 		.long	0x4c3
 753 0584 12       		.uleb128 0x12
 754 0585 00       		.byte	0
 755 0586 10       		.uleb128 0x10
 756 0587 66736565 		.ascii "fseek\0"
 756      6B00
 757 058d 01       		.byte	0x1
 758 058e 6102     		.word	0x261
 759 0590 0F       		.byte	0xf
 760 0591 B4020000 		.long	0x2b4
 761 0595 A9050000 		.long	0x5a9
 762 0599 0F       		.uleb128 0xf
 763 059a D7030000 		.long	0x3d7
 764 059e 0F       		.uleb128 0xf
 765 059f BB020000 		.long	0x2bb
 766 05a3 0F       		.uleb128 0xf
 767 05a4 B4020000 		.long	0x2b4
 768 05a8 00       		.byte	0
 769 05a9 10       		.uleb128 0x10
 770 05aa 66736574 		.ascii "fsetpos\0"
 770      706F7300 
 771 05b2 01       		.byte	0x1
 772 05b3 5F02     		.word	0x25f
 773 05b5 0F       		.byte	0xf
 774 05b6 B4020000 		.long	0x2b4
 775 05ba C9050000 		.long	0x5c9
 776 05be 0F       		.uleb128 0xf
 777 05bf D7030000 		.long	0x3d7
 778 05c3 0F       		.uleb128 0xf
 779 05c4 C9050000 		.long	0x5c9
 780 05c8 00       		.byte	0
 781 05c9 0B       		.uleb128 0xb
 782 05ca 08       		.byte	0x8
 783 05cb BA030000 		.long	0x3ba
 784 05cf 10       		.uleb128 0x10
 785 05d0 6674656C 		.ascii "ftell\0"
 785      6C00
 786 05d6 01       		.byte	0x1
 787 05d7 6202     		.word	0x262
 788 05d9 10       		.byte	0x10
 789 05da BB020000 		.long	0x2bb
 790 05de E8050000 		.long	0x5e8
 791 05e2 0F       		.uleb128 0xf
 792 05e3 D7030000 		.long	0x3d7
 793 05e7 00       		.byte	0
 794 05e8 10       		.uleb128 0x10
 795 05e9 67657463 		.ascii "getc\0"
 795      00
 796 05ee 01       		.byte	0x1
 797 05ef 8F02     		.word	0x28f
 798 05f1 0F       		.byte	0xf
 799 05f2 B4020000 		.long	0x2b4
 800 05f6 00060000 		.long	0x600
 801 05fa 0F       		.uleb128 0xf
 802 05fb D7030000 		.long	0x3d7
 803 05ff 00       		.byte	0
 804 0600 14       		.uleb128 0x14
 805 0601 67657463 		.ascii "getchar\0"
 805      68617200 
 806 0609 01       		.byte	0x1
 807 060a 9002     		.word	0x290
 808 060c 0F       		.byte	0xf
 809 060d B4020000 		.long	0x2b4
 810 0611 10       		.uleb128 0x10
 811 0612 67657473 		.ascii "gets\0"
 811      00
 812 0617 01       		.byte	0x1
 813 0618 9202     		.word	0x292
 814 061a 11       		.byte	0x11
 815 061b C7020000 		.long	0x2c7
 816 061f 29060000 		.long	0x629
 817 0623 0F       		.uleb128 0xf
 818 0624 C7020000 		.long	0x2c7
 819 0628 00       		.byte	0
 820 0629 0E       		.uleb128 0xe
 821 062a 70657272 		.ascii "perror\0"
 821      6F7200
 822 0631 01       		.byte	0x1
 823 0632 9602     		.word	0x296
 824 0634 10       		.byte	0x10
 825 0635 3F060000 		.long	0x63f
 826 0639 0F       		.uleb128 0xf
 827 063a C3040000 		.long	0x4c3
 828 063e 00       		.byte	0
 829 063f 15       		.uleb128 0x15
 830 0640 7072696E 		.ascii "printf\0"
 830      746600
 831 0647 01       		.byte	0x1
 832 0648 5901     		.word	0x159
 833 064a 05       		.byte	0x5
 834 064b 5F5A3670 		.ascii "_Z6printfPKcz\0"
 834      72696E74 
 834      66504B63 
 834      7A00
 835 0659 B4020000 		.long	0x2b4
 836 065d 00000000 		.quad	.LFB8
 836      00000000 
 837 0665 54000000 		.quad	.LFE8-.LFB8
 837      00000000 
 838 066d 01       		.uleb128 0x1
 839 066e 9C       		.byte	0x9c
 840 066f B3060000 		.long	0x6b3
 841 0673 12       		.uleb128 0x12
 842 0674 16       		.uleb128 0x16
 843 0675 0D000000 		.secrel32	.LASF2
 844 0679 01       		.byte	0x1
 845 067a 5901     		.word	0x159
 846 067c 19       		.byte	0x19
 847 067d C3040000 		.long	0x4c3
 848 0681 02       		.uleb128 0x2
 849 0682 91       		.byte	0x91
 850 0683 00       		.sleb128 0
 851 0684 12       		.uleb128 0x12
 852 0685 17       		.uleb128 0x17
 853 0686 16000000 		.secrel32	.LASF0
 854 068a 01       		.byte	0x1
 855 068b 5B01     		.word	0x15b
 856 068d 07       		.byte	0x7
 857 068e B4020000 		.long	0x2b4
 858 0692 02       		.uleb128 0x2
 859 0693 91       		.byte	0x91
 860 0694 5C       		.sleb128 -36
 861 0695 17       		.uleb128 0x17
 862 0696 00000000 		.secrel32	.LASF1
 863 069a 01       		.byte	0x1
 864 069b 5C01     		.word	0x15c
 865 069d 15       		.byte	0x15
 866 069e 3F020000 		.long	0x23f
 867 06a2 02       		.uleb128 0x2
 868 06a3 91       		.byte	0x91
 869 06a4 50       		.sleb128 -48
 870 06a5 18       		.uleb128 0x18
 871 06a6 38000000 		.quad	.LVL1
 871      00000000 
 872 06ae 6A0A0000 		.long	0xa6a
 873 06b2 00       		.byte	0
 874 06b3 10       		.uleb128 0x10
 875 06b4 72656D6F 		.ascii "remove\0"
 875      766500
 876 06bb 01       		.byte	0x1
 877 06bc A402     		.word	0x2a4
 878 06be 0F       		.byte	0xf
 879 06bf B4020000 		.long	0x2b4
 880 06c3 CD060000 		.long	0x6cd
 881 06c7 0F       		.uleb128 0xf
 882 06c8 C3040000 		.long	0x4c3
 883 06cc 00       		.byte	0
 884 06cd 10       		.uleb128 0x10
 885 06ce 72656E61 		.ascii "rename\0"
 885      6D6500
 886 06d5 01       		.byte	0x1
 887 06d6 A502     		.word	0x2a5
 888 06d8 0F       		.byte	0xf
 889 06d9 B4020000 		.long	0x2b4
 890 06dd EC060000 		.long	0x6ec
 891 06e1 0F       		.uleb128 0xf
 892 06e2 C3040000 		.long	0x4c3
 893 06e6 0F       		.uleb128 0xf
 894 06e7 C3040000 		.long	0x4c3
 895 06eb 00       		.byte	0
 896 06ec 0E       		.uleb128 0xe
 897 06ed 72657769 		.ascii "rewind\0"
 897      6E6400
 898 06f4 01       		.byte	0x1
 899 06f5 AB02     		.word	0x2ab
 900 06f7 10       		.byte	0x10
 901 06f8 02070000 		.long	0x702
 902 06fc 0F       		.uleb128 0xf
 903 06fd D7030000 		.long	0x3d7
 904 0701 00       		.byte	0
 905 0702 15       		.uleb128 0x15
 906 0703 7363616E 		.ascii "scanf\0"
 906      6600
 907 0709 01       		.byte	0x1
 908 070a 1601     		.word	0x116
 909 070c 05       		.byte	0x5
 910 070d 5F5A3573 		.ascii "_Z5scanfPKcz\0"
 910      63616E66 
 910      504B637A 
 910      00
 911 071a B4020000 		.long	0x2b4
 912 071e 00000000 		.quad	.LFB2
 912      00000000 
 913 0726 54000000 		.quad	.LFE2-.LFB2
 913      00000000 
 914 072e 01       		.uleb128 0x1
 915 072f 9C       		.byte	0x9c
 916 0730 74070000 		.long	0x774
 917 0734 12       		.uleb128 0x12
 918 0735 16       		.uleb128 0x16
 919 0736 0D000000 		.secrel32	.LASF2
 920 073a 01       		.byte	0x1
 921 073b 1601     		.word	0x116
 922 073d 17       		.byte	0x17
 923 073e C3040000 		.long	0x4c3
 924 0742 02       		.uleb128 0x2
 925 0743 91       		.byte	0x91
 926 0744 00       		.sleb128 0
 927 0745 12       		.uleb128 0x12
 928 0746 17       		.uleb128 0x17
 929 0747 16000000 		.secrel32	.LASF0
 930 074b 01       		.byte	0x1
 931 074c 1801     		.word	0x118
 932 074e 07       		.byte	0x7
 933 074f B4020000 		.long	0x2b4
 934 0753 02       		.uleb128 0x2
 935 0754 91       		.byte	0x91
 936 0755 5C       		.sleb128 -36
 937 0756 17       		.uleb128 0x17
 938 0757 00000000 		.secrel32	.LASF1
 939 075b 01       		.byte	0x1
 940 075c 1901     		.word	0x119
 941 075e 15       		.byte	0x15
 942 075f 3F020000 		.long	0x23f
 943 0763 02       		.uleb128 0x2
 944 0764 91       		.byte	0x91
 945 0765 50       		.sleb128 -48
 946 0766 18       		.uleb128 0x18
 947 0767 38000000 		.quad	.LVL0
 947      00000000 
 948 076f 6A0A0000 		.long	0xa6a
 949 0773 00       		.byte	0
 950 0774 0E       		.uleb128 0xe
 951 0775 73657462 		.ascii "setbuf\0"
 951      756600
 952 077c 01       		.byte	0x1
 953 077d AD02     		.word	0x2ad
 954 077f 10       		.byte	0x10
 955 0780 8F070000 		.long	0x78f
 956 0784 0F       		.uleb128 0xf
 957 0785 D7030000 		.long	0x3d7
 958 0789 0F       		.uleb128 0xf
 959 078a C7020000 		.long	0x2c7
 960 078e 00       		.byte	0
 961 078f 10       		.uleb128 0x10
 962 0790 73657476 		.ascii "setvbuf\0"
 962      62756600 
 963 0798 01       		.byte	0x1
 964 0799 B102     		.word	0x2b1
 965 079b 0F       		.byte	0xf
 966 079c B4020000 		.long	0x2b4
 967 07a0 B9070000 		.long	0x7b9
 968 07a4 0F       		.uleb128 0xf
 969 07a5 D7030000 		.long	0x3d7
 970 07a9 0F       		.uleb128 0xf
 971 07aa C7020000 		.long	0x2c7
 972 07ae 0F       		.uleb128 0xf
 973 07af B4020000 		.long	0x2b4
 974 07b3 0F       		.uleb128 0xf
 975 07b4 64020000 		.long	0x264
 976 07b8 00       		.byte	0
 977 07b9 11       		.uleb128 0x11
 978 07ba 73707269 		.ascii "sprintf\0"
 978      6E746600 
 979 07c2 01       		.byte	0x1
 980 07c3 6401     		.word	0x164
 981 07c5 05       		.byte	0x5
 982 07c6 5F5A3773 		.ascii "_Z7sprintfPcPKcz\0"
 982      7072696E 
 982      74665063 
 982      504B637A 
 982      00
 983 07d7 B4020000 		.long	0x2b4
 984 07db EB070000 		.long	0x7eb
 985 07df 0F       		.uleb128 0xf
 986 07e0 C7020000 		.long	0x2c7
 987 07e4 0F       		.uleb128 0xf
 988 07e5 C3040000 		.long	0x4c3
 989 07e9 12       		.uleb128 0x12
 990 07ea 00       		.byte	0
 991 07eb 11       		.uleb128 0x11
 992 07ec 73736361 		.ascii "sscanf\0"
 992      6E6600
 993 07f3 01       		.byte	0x1
 994 07f4 0B01     		.word	0x10b
 995 07f6 05       		.byte	0x5
 996 07f7 5F5A3673 		.ascii "_Z6sscanfPKcS0_z\0"
 996      7363616E 
 996      66504B63 
 996      53305F7A 
 996      00
 997 0808 B4020000 		.long	0x2b4
 998 080c 1C080000 		.long	0x81c
 999 0810 0F       		.uleb128 0xf
 1000 0811 C3040000 		.long	0x4c3
 1001 0815 0F       		.uleb128 0xf
 1002 0816 C3040000 		.long	0x4c3
 1003 081a 12       		.uleb128 0x12
 1004 081b 00       		.byte	0
 1005 081c 14       		.uleb128 0x14
 1006 081d 746D7066 		.ascii "tmpfile\0"
 1006      696C6500 
 1007 0825 01       		.byte	0x1
 1008 0826 CB02     		.word	0x2cb
 1009 0828 11       		.byte	0x11
 1010 0829 D7030000 		.long	0x3d7
 1011 082d 10       		.uleb128 0x10
 1012 082e 746D706E 		.ascii "tmpnam\0"
 1012      616D00
 1013 0835 01       		.byte	0x1
 1014 0836 CC02     		.word	0x2cc
 1015 0838 11       		.byte	0x11
 1016 0839 C7020000 		.long	0x2c7
 1017 083d 47080000 		.long	0x847
 1018 0841 0F       		.uleb128 0xf
 1019 0842 C7020000 		.long	0x2c7
 1020 0846 00       		.byte	0
 1021 0847 10       		.uleb128 0x10
 1022 0848 756E6765 		.ascii "ungetc\0"
 1022      746300
 1023 084f 01       		.byte	0x1
 1024 0850 CD02     		.word	0x2cd
 1025 0852 0F       		.byte	0xf
 1026 0853 B4020000 		.long	0x2b4
 1027 0857 66080000 		.long	0x866
 1028 085b 0F       		.uleb128 0xf
 1029 085c B4020000 		.long	0x2b4
 1030 0860 0F       		.uleb128 0xf
 1031 0861 D7030000 		.long	0x3d7
 1032 0865 00       		.byte	0
 1033 0866 11       		.uleb128 0x11
 1034 0867 76667072 		.ascii "vfprintf\0"
 1034      696E7466 
 1034      00
 1035 0870 01       		.byte	0x1
 1036 0871 6F01     		.word	0x16f
 1037 0873 05       		.byte	0x5
 1038 0874 5F5A3876 		.ascii "_Z8vfprintfP6_iobufPKcPc\0"
 1038      66707269 
 1038      6E746650 
 1038      365F696F 
 1038      62756650 
 1039 088d B4020000 		.long	0x2b4
 1040 0891 A5080000 		.long	0x8a5
 1041 0895 0F       		.uleb128 0xf
 1042 0896 D7030000 		.long	0x3d7
 1043 089a 0F       		.uleb128 0xf
 1044 089b C3040000 		.long	0x4c3
 1045 089f 0F       		.uleb128 0xf
 1046 08a0 3F020000 		.long	0x23f
 1047 08a4 00       		.byte	0
 1048 08a5 11       		.uleb128 0x11
 1049 08a6 76707269 		.ascii "vprintf\0"
 1049      6E746600 
 1050 08ae 01       		.byte	0x1
 1051 08af 7601     		.word	0x176
 1052 08b1 05       		.byte	0x5
 1053 08b2 5F5A3776 		.ascii "_Z7vprintfPKcPc\0"
 1053      7072696E 
 1053      7466504B 
 1053      63506300 
 1054 08c2 B4020000 		.long	0x2b4
 1055 08c6 D5080000 		.long	0x8d5
 1056 08ca 0F       		.uleb128 0xf
 1057 08cb C3040000 		.long	0x4c3
 1058 08cf 0F       		.uleb128 0xf
 1059 08d0 3F020000 		.long	0x23f
 1060 08d4 00       		.byte	0
 1061 08d5 11       		.uleb128 0x11
 1062 08d6 76737072 		.ascii "vsprintf\0"
 1062      696E7466 
 1062      00
 1063 08df 01       		.byte	0x1
 1064 08e0 7D01     		.word	0x17d
 1065 08e2 05       		.byte	0x5
 1066 08e3 5F5A3876 		.ascii "_Z8vsprintfPcPKcS_\0"
 1066      73707269 
 1066      6E746650 
 1066      63504B63 
 1066      535F00
 1067 08f6 B4020000 		.long	0x2b4
 1068 08fa 0E090000 		.long	0x90e
 1069 08fe 0F       		.uleb128 0xf
 1070 08ff C7020000 		.long	0x2c7
 1071 0903 0F       		.uleb128 0xf
 1072 0904 C3040000 		.long	0x4c3
 1073 0908 0F       		.uleb128 0xf
 1074 0909 3F020000 		.long	0x23f
 1075 090d 00       		.byte	0
 1076 090e 11       		.uleb128 0x11
 1077 090f 736E7072 		.ascii "snprintf\0"
 1077      696E7466 
 1077      00
 1078 0918 01       		.byte	0x1
 1079 0919 8401     		.word	0x184
 1080 091b 05       		.byte	0x5
 1081 091c 5F5A3873 		.ascii "_Z8snprintfPcyPKcz\0"
 1081      6E707269 
 1081      6E746650 
 1081      6379504B 
 1081      637A00
 1082 092f B4020000 		.long	0x2b4
 1083 0933 48090000 		.long	0x948
 1084 0937 0F       		.uleb128 0xf
 1085 0938 C7020000 		.long	0x2c7
 1086 093c 0F       		.uleb128 0xf
 1087 093d 64020000 		.long	0x264
 1088 0941 0F       		.uleb128 0xf
 1089 0942 C3040000 		.long	0x4c3
 1090 0946 12       		.uleb128 0x12
 1091 0947 00       		.byte	0
 1092 0948 11       		.uleb128 0x11
 1093 0949 76667363 		.ascii "vfscanf\0"
 1093      616E6600 
 1094 0951 01       		.byte	0x1
 1095 0952 4001     		.word	0x140
 1096 0954 05       		.byte	0x5
 1097 0955 5F5A3776 		.ascii "_Z7vfscanfP6_iobufPKcPc\0"
 1097      66736361 
 1097      6E665036 
 1097      5F696F62 
 1097      7566504B 
 1098 096d B4020000 		.long	0x2b4
 1099 0971 85090000 		.long	0x985
 1100 0975 0F       		.uleb128 0xf
 1101 0976 D7030000 		.long	0x3d7
 1102 097a 0F       		.uleb128 0xf
 1103 097b C3040000 		.long	0x4c3
 1104 097f 0F       		.uleb128 0xf
 1105 0980 3F020000 		.long	0x23f
 1106 0984 00       		.byte	0
 1107 0985 11       		.uleb128 0x11
 1108 0986 76736361 		.ascii "vscanf\0"
 1108      6E6600
 1109 098d 01       		.byte	0x1
 1110 098e 3901     		.word	0x139
 1111 0990 05       		.byte	0x5
 1112 0991 5F5A3676 		.ascii "_Z6vscanfPKcPc\0"
 1112      7363616E 
 1112      66504B63 
 1112      506300
 1113 09a0 B4020000 		.long	0x2b4
 1114 09a4 B3090000 		.long	0x9b3
 1115 09a8 0F       		.uleb128 0xf
 1116 09a9 C3040000 		.long	0x4c3
 1117 09ad 0F       		.uleb128 0xf
 1118 09ae 3F020000 		.long	0x23f
 1119 09b2 00       		.byte	0
 1120 09b3 11       		.uleb128 0x11
 1121 09b4 76736E70 		.ascii "vsnprintf\0"
 1121      72696E74 
 1121      6600
 1122 09be 01       		.byte	0x1
 1123 09bf 8F01     		.word	0x18f
 1124 09c1 05       		.byte	0x5
 1125 09c2 5F5A3976 		.ascii "_Z9vsnprintfPcyPKcS_\0"
 1125      736E7072 
 1125      696E7466 
 1125      50637950 
 1125      4B63535F 
 1126 09d7 B4020000 		.long	0x2b4
 1127 09db F4090000 		.long	0x9f4
 1128 09df 0F       		.uleb128 0xf
 1129 09e0 C7020000 		.long	0x2c7
 1130 09e4 0F       		.uleb128 0xf
 1131 09e5 64020000 		.long	0x264
 1132 09e9 0F       		.uleb128 0xf
 1133 09ea C3040000 		.long	0x4c3
 1134 09ee 0F       		.uleb128 0xf
 1135 09ef 3F020000 		.long	0x23f
 1136 09f3 00       		.byte	0
 1137 09f4 11       		.uleb128 0x11
 1138 09f5 76737363 		.ascii "vsscanf\0"
 1138      616E6600 
 1139 09fd 01       		.byte	0x1
 1140 09fe 3201     		.word	0x132
 1141 0a00 05       		.byte	0x5
 1142 0a01 5F5A3776 		.ascii "_Z7vsscanfPKcS0_Pc\0"
 1142      73736361 
 1142      6E66504B 
 1142      6353305F 
 1142      506300
 1143 0a14 B4020000 		.long	0x2b4
 1144 0a18 2C0A0000 		.long	0xa2c
 1145 0a1c 0F       		.uleb128 0xf
 1146 0a1d C3040000 		.long	0x4c3
 1147 0a21 0F       		.uleb128 0xf
 1148 0a22 C3040000 		.long	0x4c3
 1149 0a26 0F       		.uleb128 0xf
 1150 0a27 3F020000 		.long	0x23f
 1151 0a2b 00       		.byte	0
 1152 0a2c 19       		.uleb128 0x19
 1153 0a2d 6D61696E 		.ascii "main\0"
 1153      00
 1154 0a32 02       		.byte	0x2
 1155 0a33 03       		.byte	0x3
 1156 0a34 05       		.byte	0x5
 1157 0a35 B4020000 		.long	0x2b4
 1158 0a39 00000000 		.quad	.LFB44
 1158      00000000 
 1159 0a41 48000000 		.quad	.LFE44-.LFB44
 1159      00000000 
 1160 0a49 01       		.uleb128 0x1
 1161 0a4a 9C       		.byte	0x9c
 1162 0a4b 6A0A0000 		.long	0xa6a
 1163 0a4f 1A       		.uleb128 0x1a
 1164 0a50 6100     		.ascii "a\0"
 1165 0a52 02       		.byte	0x2
 1166 0a53 05       		.byte	0x5
 1167 0a54 06       		.byte	0x6
 1168 0a55 B4020000 		.long	0x2b4
 1169 0a59 02       		.uleb128 0x2
 1170 0a5a 91       		.byte	0x91
 1171 0a5b 6C       		.sleb128 -20
 1172 0a5c 1A       		.uleb128 0x1a
 1173 0a5d 6200     		.ascii "b\0"
 1174 0a5f 02       		.byte	0x2
 1175 0a60 05       		.byte	0x5
 1176 0a61 09       		.byte	0x9
 1177 0a62 B4020000 		.long	0x2b4
 1178 0a66 02       		.uleb128 0x2
 1179 0a67 91       		.byte	0x91
 1180 0a68 68       		.sleb128 -24
 1181 0a69 00       		.byte	0
 1182 0a6a 1B       		.uleb128 0x1b
 1183 0a6b 1F000000 		.secrel32	.LASF3
 1184 0a6f 1F000000 		.secrel32	.LASF3
 1185 0a73 01       		.byte	0x1
 1186 0a74 52       		.byte	0x52
 1187 0a75 17       		.byte	0x17
 1188 0a76 00       		.byte	0
 1189              		.section	.debug_abbrev,"dr"
 1190              	.Ldebug_abbrev0:
 1191 0000 01       		.uleb128 0x1
 1192 0001 11       		.uleb128 0x11
 1193 0002 01       		.byte	0x1
 1194 0003 25       		.uleb128 0x25
 1195 0004 08       		.uleb128 0x8
 1196 0005 13       		.uleb128 0x13
 1197 0006 0B       		.uleb128 0xb
 1198 0007 03       		.uleb128 0x3
 1199 0008 08       		.uleb128 0x8
 1200 0009 1B       		.uleb128 0x1b
 1201 000a 08       		.uleb128 0x8
 1202 000b 55       		.uleb128 0x55
 1203 000c 17       		.uleb128 0x17
 1204 000d 11       		.uleb128 0x11
 1205 000e 01       		.uleb128 0x1
 1206 000f 10       		.uleb128 0x10
 1207 0010 17       		.uleb128 0x17
 1208 0011 00       		.byte	0
 1209 0012 00       		.byte	0
 1210 0013 02       		.uleb128 0x2
 1211 0014 39       		.uleb128 0x39
 1212 0015 01       		.byte	0x1
 1213 0016 03       		.uleb128 0x3
 1214 0017 08       		.uleb128 0x8
 1215 0018 3A       		.uleb128 0x3a
 1216 0019 0B       		.uleb128 0xb
 1217 001a 3B       		.uleb128 0x3b
 1218 001b 0B       		.uleb128 0xb
 1219 001c 01       		.uleb128 0x1
 1220 001d 13       		.uleb128 0x13
 1221 001e 00       		.byte	0
 1222 001f 00       		.byte	0
 1223 0020 03       		.uleb128 0x3
 1224 0021 39       		.uleb128 0x39
 1225 0022 00       		.byte	0
 1226 0023 03       		.uleb128 0x3
 1227 0024 08       		.uleb128 0x8
 1228 0025 3A       		.uleb128 0x3a
 1229 0026 0B       		.uleb128 0xb
 1230 0027 3B       		.uleb128 0x3b
 1231 0028 05       		.uleb128 0x5
 1232 0029 39       		.uleb128 0x39
 1233 002a 0B       		.uleb128 0xb
 1234 002b 8901     		.uleb128 0x89
 1235 002d 19       		.uleb128 0x19
 1236 002e 00       		.byte	0
 1237 002f 00       		.byte	0
 1238 0030 04       		.uleb128 0x4
 1239 0031 3A       		.uleb128 0x3a
 1240 0032 00       		.byte	0
 1241 0033 3A       		.uleb128 0x3a
 1242 0034 0B       		.uleb128 0xb
 1243 0035 3B       		.uleb128 0x3b
 1244 0036 05       		.uleb128 0x5
 1245 0037 39       		.uleb128 0x39
 1246 0038 0B       		.uleb128 0xb
 1247 0039 18       		.uleb128 0x18
 1248 003a 13       		.uleb128 0x13
 1249 003b 00       		.byte	0
 1250 003c 00       		.byte	0
 1251 003d 05       		.uleb128 0x5
 1252 003e 08       		.uleb128 0x8
 1253 003f 00       		.byte	0
 1254 0040 3A       		.uleb128 0x3a
 1255 0041 0B       		.uleb128 0xb
 1256 0042 3B       		.uleb128 0x3b
 1257 0043 0B       		.uleb128 0xb
 1258 0044 39       		.uleb128 0x39
 1259 0045 0B       		.uleb128 0xb
 1260 0046 18       		.uleb128 0x18
 1261 0047 13       		.uleb128 0x13
 1262 0048 00       		.byte	0
 1263 0049 00       		.byte	0
 1264 004a 06       		.uleb128 0x6
 1265 004b 39       		.uleb128 0x39
 1266 004c 01       		.byte	0x1
 1267 004d 03       		.uleb128 0x3
 1268 004e 08       		.uleb128 0x8
 1269 004f 3A       		.uleb128 0x3a
 1270 0050 0B       		.uleb128 0xb
 1271 0051 3B       		.uleb128 0x3b
 1272 0052 05       		.uleb128 0x5
 1273 0053 39       		.uleb128 0x39
 1274 0054 0B       		.uleb128 0xb
 1275 0055 01       		.uleb128 0x1
 1276 0056 13       		.uleb128 0x13
 1277 0057 00       		.byte	0
 1278 0058 00       		.byte	0
 1279 0059 07       		.uleb128 0x7
 1280 005a 0F       		.uleb128 0xf
 1281 005b 00       		.byte	0
 1282 005c 0B       		.uleb128 0xb
 1283 005d 0B       		.uleb128 0xb
 1284 005e 03       		.uleb128 0x3
 1285 005f 08       		.uleb128 0x8
 1286 0060 49       		.uleb128 0x49
 1287 0061 13       		.uleb128 0x13
 1288 0062 00       		.byte	0
 1289 0063 00       		.byte	0
 1290 0064 08       		.uleb128 0x8
 1291 0065 24       		.uleb128 0x24
 1292 0066 00       		.byte	0
 1293 0067 0B       		.uleb128 0xb
 1294 0068 0B       		.uleb128 0xb
 1295 0069 3E       		.uleb128 0x3e
 1296 006a 0B       		.uleb128 0xb
 1297 006b 03       		.uleb128 0x3
 1298 006c 08       		.uleb128 0x8
 1299 006d 00       		.byte	0
 1300 006e 00       		.byte	0
 1301 006f 09       		.uleb128 0x9
 1302 0070 26       		.uleb128 0x26
 1303 0071 00       		.byte	0
 1304 0072 49       		.uleb128 0x49
 1305 0073 13       		.uleb128 0x13
 1306 0074 00       		.byte	0
 1307 0075 00       		.byte	0
 1308 0076 0A       		.uleb128 0xa
 1309 0077 16       		.uleb128 0x16
 1310 0078 00       		.byte	0
 1311 0079 03       		.uleb128 0x3
 1312 007a 08       		.uleb128 0x8
 1313 007b 3A       		.uleb128 0x3a
 1314 007c 0B       		.uleb128 0xb
 1315 007d 3B       		.uleb128 0x3b
 1316 007e 0B       		.uleb128 0xb
 1317 007f 39       		.uleb128 0x39
 1318 0080 0B       		.uleb128 0xb
 1319 0081 49       		.uleb128 0x49
 1320 0082 13       		.uleb128 0x13
 1321 0083 00       		.byte	0
 1322 0084 00       		.byte	0
 1323 0085 0B       		.uleb128 0xb
 1324 0086 0F       		.uleb128 0xf
 1325 0087 00       		.byte	0
 1326 0088 0B       		.uleb128 0xb
 1327 0089 0B       		.uleb128 0xb
 1328 008a 49       		.uleb128 0x49
 1329 008b 13       		.uleb128 0x13
 1330 008c 00       		.byte	0
 1331 008d 00       		.byte	0
 1332 008e 0C       		.uleb128 0xc
 1333 008f 13       		.uleb128 0x13
 1334 0090 01       		.byte	0x1
 1335 0091 03       		.uleb128 0x3
 1336 0092 08       		.uleb128 0x8
 1337 0093 0B       		.uleb128 0xb
 1338 0094 0B       		.uleb128 0xb
 1339 0095 3A       		.uleb128 0x3a
 1340 0096 0B       		.uleb128 0xb
 1341 0097 3B       		.uleb128 0x3b
 1342 0098 0B       		.uleb128 0xb
 1343 0099 39       		.uleb128 0x39
 1344 009a 0B       		.uleb128 0xb
 1345 009b 01       		.uleb128 0x1
 1346 009c 13       		.uleb128 0x13
 1347 009d 00       		.byte	0
 1348 009e 00       		.byte	0
 1349 009f 0D       		.uleb128 0xd
 1350 00a0 0D       		.uleb128 0xd
 1351 00a1 00       		.byte	0
 1352 00a2 03       		.uleb128 0x3
 1353 00a3 08       		.uleb128 0x8
 1354 00a4 3A       		.uleb128 0x3a
 1355 00a5 0B       		.uleb128 0xb
 1356 00a6 3B       		.uleb128 0x3b
 1357 00a7 0B       		.uleb128 0xb
 1358 00a8 39       		.uleb128 0x39
 1359 00a9 0B       		.uleb128 0xb
 1360 00aa 49       		.uleb128 0x49
 1361 00ab 13       		.uleb128 0x13
 1362 00ac 38       		.uleb128 0x38
 1363 00ad 0B       		.uleb128 0xb
 1364 00ae 00       		.byte	0
 1365 00af 00       		.byte	0
 1366 00b0 0E       		.uleb128 0xe
 1367 00b1 2E       		.uleb128 0x2e
 1368 00b2 01       		.byte	0x1
 1369 00b3 3F       		.uleb128 0x3f
 1370 00b4 19       		.uleb128 0x19
 1371 00b5 03       		.uleb128 0x3
 1372 00b6 08       		.uleb128 0x8
 1373 00b7 3A       		.uleb128 0x3a
 1374 00b8 0B       		.uleb128 0xb
 1375 00b9 3B       		.uleb128 0x3b
 1376 00ba 05       		.uleb128 0x5
 1377 00bb 39       		.uleb128 0x39
 1378 00bc 0B       		.uleb128 0xb
 1379 00bd 3C       		.uleb128 0x3c
 1380 00be 19       		.uleb128 0x19
 1381 00bf 01       		.uleb128 0x1
 1382 00c0 13       		.uleb128 0x13
 1383 00c1 00       		.byte	0
 1384 00c2 00       		.byte	0
 1385 00c3 0F       		.uleb128 0xf
 1386 00c4 05       		.uleb128 0x5
 1387 00c5 00       		.byte	0
 1388 00c6 49       		.uleb128 0x49
 1389 00c7 13       		.uleb128 0x13
 1390 00c8 00       		.byte	0
 1391 00c9 00       		.byte	0
 1392 00ca 10       		.uleb128 0x10
 1393 00cb 2E       		.uleb128 0x2e
 1394 00cc 01       		.byte	0x1
 1395 00cd 3F       		.uleb128 0x3f
 1396 00ce 19       		.uleb128 0x19
 1397 00cf 03       		.uleb128 0x3
 1398 00d0 08       		.uleb128 0x8
 1399 00d1 3A       		.uleb128 0x3a
 1400 00d2 0B       		.uleb128 0xb
 1401 00d3 3B       		.uleb128 0x3b
 1402 00d4 05       		.uleb128 0x5
 1403 00d5 39       		.uleb128 0x39
 1404 00d6 0B       		.uleb128 0xb
 1405 00d7 49       		.uleb128 0x49
 1406 00d8 13       		.uleb128 0x13
 1407 00d9 3C       		.uleb128 0x3c
 1408 00da 19       		.uleb128 0x19
 1409 00db 01       		.uleb128 0x1
 1410 00dc 13       		.uleb128 0x13
 1411 00dd 00       		.byte	0
 1412 00de 00       		.byte	0
 1413 00df 11       		.uleb128 0x11
 1414 00e0 2E       		.uleb128 0x2e
 1415 00e1 01       		.byte	0x1
 1416 00e2 3F       		.uleb128 0x3f
 1417 00e3 19       		.uleb128 0x19
 1418 00e4 03       		.uleb128 0x3
 1419 00e5 08       		.uleb128 0x8
 1420 00e6 3A       		.uleb128 0x3a
 1421 00e7 0B       		.uleb128 0xb
 1422 00e8 3B       		.uleb128 0x3b
 1423 00e9 05       		.uleb128 0x5
 1424 00ea 39       		.uleb128 0x39
 1425 00eb 0B       		.uleb128 0xb
 1426 00ec 6E       		.uleb128 0x6e
 1427 00ed 08       		.uleb128 0x8
 1428 00ee 49       		.uleb128 0x49
 1429 00ef 13       		.uleb128 0x13
 1430 00f0 3C       		.uleb128 0x3c
 1431 00f1 19       		.uleb128 0x19
 1432 00f2 01       		.uleb128 0x1
 1433 00f3 13       		.uleb128 0x13
 1434 00f4 00       		.byte	0
 1435 00f5 00       		.byte	0
 1436 00f6 12       		.uleb128 0x12
 1437 00f7 18       		.uleb128 0x18
 1438 00f8 00       		.byte	0
 1439 00f9 00       		.byte	0
 1440 00fa 00       		.byte	0
 1441 00fb 13       		.uleb128 0x13
 1442 00fc 0F       		.uleb128 0xf
 1443 00fd 00       		.byte	0
 1444 00fe 0B       		.uleb128 0xb
 1445 00ff 0B       		.uleb128 0xb
 1446 0100 00       		.byte	0
 1447 0101 00       		.byte	0
 1448 0102 14       		.uleb128 0x14
 1449 0103 2E       		.uleb128 0x2e
 1450 0104 00       		.byte	0
 1451 0105 3F       		.uleb128 0x3f
 1452 0106 19       		.uleb128 0x19
 1453 0107 03       		.uleb128 0x3
 1454 0108 08       		.uleb128 0x8
 1455 0109 3A       		.uleb128 0x3a
 1456 010a 0B       		.uleb128 0xb
 1457 010b 3B       		.uleb128 0x3b
 1458 010c 05       		.uleb128 0x5
 1459 010d 39       		.uleb128 0x39
 1460 010e 0B       		.uleb128 0xb
 1461 010f 49       		.uleb128 0x49
 1462 0110 13       		.uleb128 0x13
 1463 0111 3C       		.uleb128 0x3c
 1464 0112 19       		.uleb128 0x19
 1465 0113 00       		.byte	0
 1466 0114 00       		.byte	0
 1467 0115 15       		.uleb128 0x15
 1468 0116 2E       		.uleb128 0x2e
 1469 0117 01       		.byte	0x1
 1470 0118 3F       		.uleb128 0x3f
 1471 0119 19       		.uleb128 0x19
 1472 011a 03       		.uleb128 0x3
 1473 011b 08       		.uleb128 0x8
 1474 011c 3A       		.uleb128 0x3a
 1475 011d 0B       		.uleb128 0xb
 1476 011e 3B       		.uleb128 0x3b
 1477 011f 05       		.uleb128 0x5
 1478 0120 39       		.uleb128 0x39
 1479 0121 0B       		.uleb128 0xb
 1480 0122 6E       		.uleb128 0x6e
 1481 0123 08       		.uleb128 0x8
 1482 0124 49       		.uleb128 0x49
 1483 0125 13       		.uleb128 0x13
 1484 0126 11       		.uleb128 0x11
 1485 0127 01       		.uleb128 0x1
 1486 0128 12       		.uleb128 0x12
 1487 0129 07       		.uleb128 0x7
 1488 012a 40       		.uleb128 0x40
 1489 012b 18       		.uleb128 0x18
 1490 012c 9642     		.uleb128 0x2116
 1491 012e 19       		.uleb128 0x19
 1492 012f 01       		.uleb128 0x1
 1493 0130 13       		.uleb128 0x13
 1494 0131 00       		.byte	0
 1495 0132 00       		.byte	0
 1496 0133 16       		.uleb128 0x16
 1497 0134 05       		.uleb128 0x5
 1498 0135 00       		.byte	0
 1499 0136 03       		.uleb128 0x3
 1500 0137 0E       		.uleb128 0xe
 1501 0138 3A       		.uleb128 0x3a
 1502 0139 0B       		.uleb128 0xb
 1503 013a 3B       		.uleb128 0x3b
 1504 013b 05       		.uleb128 0x5
 1505 013c 39       		.uleb128 0x39
 1506 013d 0B       		.uleb128 0xb
 1507 013e 49       		.uleb128 0x49
 1508 013f 13       		.uleb128 0x13
 1509 0140 02       		.uleb128 0x2
 1510 0141 18       		.uleb128 0x18
 1511 0142 00       		.byte	0
 1512 0143 00       		.byte	0
 1513 0144 17       		.uleb128 0x17
 1514 0145 34       		.uleb128 0x34
 1515 0146 00       		.byte	0
 1516 0147 03       		.uleb128 0x3
 1517 0148 0E       		.uleb128 0xe
 1518 0149 3A       		.uleb128 0x3a
 1519 014a 0B       		.uleb128 0xb
 1520 014b 3B       		.uleb128 0x3b
 1521 014c 05       		.uleb128 0x5
 1522 014d 39       		.uleb128 0x39
 1523 014e 0B       		.uleb128 0xb
 1524 014f 49       		.uleb128 0x49
 1525 0150 13       		.uleb128 0x13
 1526 0151 02       		.uleb128 0x2
 1527 0152 18       		.uleb128 0x18
 1528 0153 00       		.byte	0
 1529 0154 00       		.byte	0
 1530 0155 18       		.uleb128 0x18
 1531 0156 898201   		.uleb128 0x4109
 1532 0159 00       		.byte	0
 1533 015a 11       		.uleb128 0x11
 1534 015b 01       		.uleb128 0x1
 1535 015c 31       		.uleb128 0x31
 1536 015d 13       		.uleb128 0x13
 1537 015e 00       		.byte	0
 1538 015f 00       		.byte	0
 1539 0160 19       		.uleb128 0x19
 1540 0161 2E       		.uleb128 0x2e
 1541 0162 01       		.byte	0x1
 1542 0163 3F       		.uleb128 0x3f
 1543 0164 19       		.uleb128 0x19
 1544 0165 03       		.uleb128 0x3
 1545 0166 08       		.uleb128 0x8
 1546 0167 3A       		.uleb128 0x3a
 1547 0168 0B       		.uleb128 0xb
 1548 0169 3B       		.uleb128 0x3b
 1549 016a 0B       		.uleb128 0xb
 1550 016b 39       		.uleb128 0x39
 1551 016c 0B       		.uleb128 0xb
 1552 016d 49       		.uleb128 0x49
 1553 016e 13       		.uleb128 0x13
 1554 016f 11       		.uleb128 0x11
 1555 0170 01       		.uleb128 0x1
 1556 0171 12       		.uleb128 0x12
 1557 0172 07       		.uleb128 0x7
 1558 0173 40       		.uleb128 0x40
 1559 0174 18       		.uleb128 0x18
 1560 0175 9642     		.uleb128 0x2116
 1561 0177 19       		.uleb128 0x19
 1562 0178 01       		.uleb128 0x1
 1563 0179 13       		.uleb128 0x13
 1564 017a 00       		.byte	0
 1565 017b 00       		.byte	0
 1566 017c 1A       		.uleb128 0x1a
 1567 017d 34       		.uleb128 0x34
 1568 017e 00       		.byte	0
 1569 017f 03       		.uleb128 0x3
 1570 0180 08       		.uleb128 0x8
 1571 0181 3A       		.uleb128 0x3a
 1572 0182 0B       		.uleb128 0xb
 1573 0183 3B       		.uleb128 0x3b
 1574 0184 0B       		.uleb128 0xb
 1575 0185 39       		.uleb128 0x39
 1576 0186 0B       		.uleb128 0xb
 1577 0187 49       		.uleb128 0x49
 1578 0188 13       		.uleb128 0x13
 1579 0189 02       		.uleb128 0x2
 1580 018a 18       		.uleb128 0x18
 1581 018b 00       		.byte	0
 1582 018c 00       		.byte	0
 1583 018d 1B       		.uleb128 0x1b
 1584 018e 2E       		.uleb128 0x2e
 1585 018f 00       		.byte	0
 1586 0190 3F       		.uleb128 0x3f
 1587 0191 19       		.uleb128 0x19
 1588 0192 3C       		.uleb128 0x3c
 1589 0193 19       		.uleb128 0x19
 1590 0194 6E       		.uleb128 0x6e
 1591 0195 0E       		.uleb128 0xe
 1592 0196 03       		.uleb128 0x3
 1593 0197 0E       		.uleb128 0xe
 1594 0198 3A       		.uleb128 0x3a
 1595 0199 0B       		.uleb128 0xb
 1596 019a 3B       		.uleb128 0x3b
 1597 019b 0B       		.uleb128 0xb
 1598 019c 39       		.uleb128 0x39
 1599 019d 0B       		.uleb128 0xb
 1600 019e 00       		.byte	0
 1601 019f 00       		.byte	0
 1602 01a0 00       		.byte	0
 1603              		.section	.debug_aranges,"dr"
 1604 0000 4C000000 		.long	0x4c
 1605 0004 0200     		.word	0x2
 1606 0006 00000000 		.secrel32	.Ldebug_info0
 1607 000a 08       		.byte	0x8
 1608 000b 00       		.byte	0
 1609 000c 0000     		.word	0
 1610 000e 0000     		.word	0
 1611 0010 00000000 		.quad	.Ltext0
 1611      00000000 
 1612 0018 48000000 		.quad	.Letext0-.Ltext0
 1612      00000000 
 1613 0020 00000000 		.quad	.LFB2
 1613      00000000 
 1614 0028 54000000 		.quad	.LFE2-.LFB2
 1614      00000000 
 1615 0030 00000000 		.quad	.LFB8
 1615      00000000 
 1616 0038 54000000 		.quad	.LFE8-.LFB8
 1616      00000000 
 1617 0040 00000000 		.quad	0
 1617      00000000 
 1618 0048 00000000 		.quad	0
 1618      00000000 
 1619              		.section	.debug_ranges,"dr"
 1620              	.Ldebug_ranges0:
 1621 0000 00000000 		.quad	.Ltext0
 1621      00000000 
 1622 0008 48000000 		.quad	.Letext0
 1622      00000000 
 1623 0010 00000000 		.quad	.LFB2
 1623      00000000 
 1624 0018 54000000 		.quad	.LFE2
 1624      00000000 
 1625 0020 00000000 		.quad	.LFB8
 1625      00000000 
 1626 0028 54000000 		.quad	.LFE8
 1626      00000000 
 1627 0030 00000000 		.quad	0
 1627      00000000 
 1628 0038 00000000 		.quad	0
 1628      00000000 
 1629              		.section	.debug_line,"dr"
 1630              	.Ldebug_line0:
 1631 0000 3C020000 		.section	.debug_str,"dr"
 1631      0200C801 
 1631      00000101 
 1631      FB0E0D00 
 1631      01010101 
 1632              	.LASF1:
 1633 0000 5F5F6C6F 		.ascii "__local_argv\0"
 1633      63616C5F 
 1633      61726776 
 1633      00
 1634              	.LASF2:
 1635 000d 5F5F666F 		.ascii "__format\0"
 1635      726D6174 
 1635      00
 1636              	.LASF0:
 1637 0016 5F5F7265 		.ascii "__retval\0"
 1637      7476616C 
 1637      00
 1638              	.LASF3:
 1639 001f 5F5F6163 		.ascii "__acrt_iob_func\0"
 1639      72745F69 
 1639      6F625F66 
 1639      756E6300 
 1640              		.ident	"GCC: (x86_64-win32-seh-rev0, Built by MinGW-W64 project) 8.1.0"
