   1              		.file	"tria.cpp"
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
 116 0054 90909090 		.section .rdata,"dr"
 116      90909090 
 116      90909090 
 117              		.align 4
 118              	_ZL1N:
 119 0000 16000000 		.long	22
 120              		.globl	f
 121              		.bss
 122              		.align 32
 123              	f:
 124 0000 00000000 		.space 1936
 124      00000000 
 124      00000000 
 124      00000000 
 124      00000000 
 125              		.globl	s
 126 0790 00000000 		.align 32
 126      00000000 
 126      00000000 
 126      00000000 
 127              	s:
 128 07a0 00000000 		.space 92
 128      00000000 
 128      00000000 
 128      00000000 
 128      00000000 
 129              		.globl	n
 130              		.align 4
 131              	n:
 132 07fc 00000000 		.space 4
 133              		.globl	ans
 134              		.align 4
 135              	ans:
 136 0800 00000000 		.space 4
 137 0804 00000000 		.text
 137      00000000 
 137      00000000 
 137      00000000 
 137      00000000 
 138              		.globl	_Z3dfsi
 140              		.seh_proc	_Z3dfsi
 141              	_Z3dfsi:
 142              	.LFB44:
 143              		.file 2 "../code/C++/\310\375\275\307\320\316/tria.cpp"
   1:../code/C++/三角形/tria.cpp **** #include <cstdio>
   2:../code/C++/三角形/tria.cpp **** 
   3:../code/C++/三角形/tria.cpp **** const int N = 22;
   4:../code/C++/三角形/tria.cpp **** int f[N][N], s[N + 1], n, ans;
   5:../code/C++/三角形/tria.cpp **** 
   6:../code/C++/三角形/tria.cpp **** void dfs(int k)
   7:../code/C++/三角形/tria.cpp **** {
 144              		.loc 2 7 1
 145              		.cfi_startproc
 146 0000 55       		pushq	%rbp
 147              		.seh_pushreg	%rbp
 148              		.cfi_def_cfa_offset 16
 149              		.cfi_offset 6, -16
 150 0001 4889E5   		movq	%rsp, %rbp
 151              		.seh_setframe	%rbp, 0
 152              		.cfi_def_cfa_register 6
 153 0004 4883EC30 		subq	$48, %rsp
 154              		.seh_stackalloc	48
 155              		.seh_endprologue
 156 0008 894D10   		movl	%ecx, 16(%rbp)
 157              	.LBB2:
   8:../code/C++/三角形/tria.cpp **** 	if (k == n)
 158              		.loc 2 8 8
 159 000b 8B05FC07 		movl	n(%rip), %eax
 159      0000
 160              		.loc 2 8 2
 161 0011 394510   		cmpl	%eax, 16(%rbp)
 162 0014 0F85E701 		jne	.L6
 162      0000
 163              	.LBB3:
   9:../code/C++/三角形/tria.cpp **** 	{
  10:../code/C++/三角形/tria.cpp **** 		int tmp = 0;
 164              		.loc 2 10 7
 165 001a C745FC00 		movl	$0, -4(%rbp)
 165      000000
 166              	.LBB4:
  11:../code/C++/三角形/tria.cpp **** 		for (int j = 0; j < n; ++j) tmp += f[0][j] ? 1 : -1;
 167              		.loc 2 11 12
 168 0021 C745F800 		movl	$0, -8(%rbp)
 168      000000
 169              	.L10:
 170              		.loc 2 11 21 discriminator 7
 171 0028 8B05FC07 		movl	n(%rip), %eax
 171      0000
 172 002e 3945F8   		cmpl	%eax, -8(%rbp)
 173 0031 7D30     		jge	.L7
 174              		.loc 2 11 44 discriminator 2
 175 0033 8B45F8   		movl	-8(%rbp), %eax
 176 0036 4898     		cltq
 177 0038 488D1485 		leaq	0(,%rax,4), %rdx
 177      00000000 
 178 0040 488D0500 		leaq	f(%rip), %rax
 178      000000
 179 0047 8B0402   		movl	(%rdx,%rax), %eax
 180              		.loc 2 11 46 discriminator 2
 181 004a 85C0     		testl	%eax, %eax
 182 004c 7407     		je	.L8
 183              		.loc 2 11 46 is_stmt 0 discriminator 3
 184 004e B8010000 		movl	$1, %eax
 184      00
 185 0053 EB05     		jmp	.L9
 186              	.L8:
 187              		.loc 2 11 46 discriminator 4
 188 0055 B8FFFFFF 		movl	$-1, %eax
 188      FF
 189              	.L9:
 190              		.loc 2 11 35 is_stmt 1 discriminator 6
 191 005a 0145FC   		addl	%eax, -4(%rbp)
 192              		.loc 2 11 3 discriminator 6
 193 005d 8345F801 		addl	$1, -8(%rbp)
 194 0061 EBC5     		jmp	.L10
 195              	.L7:
 196              	.LBE4:
  12:../code/C++/三角形/tria.cpp **** 		if (tmp > s[n - 1] || tmp < -s[n - 1]) return;
 197              		.loc 2 12 17
 198 0063 8B05FC07 		movl	n(%rip), %eax
 198      0000
 199 0069 83E801   		subl	$1, %eax
 200              		.loc 2 12 20
 201 006c 4898     		cltq
 202 006e 488D1485 		leaq	0(,%rax,4), %rdx
 202      00000000 
 203 0076 488D05A0 		leaq	s(%rip), %rax
 203      070000
 204 007d 8B0402   		movl	(%rdx,%rax), %eax
 205              		.loc 2 12 3
 206 0080 3945FC   		cmpl	%eax, -4(%rbp)
 207 0083 0F8FCA01 		jg	.L22
 207      0000
 208              		.loc 2 12 36 discriminator 2
 209 0089 8B05FC07 		movl	n(%rip), %eax
 209      0000
 210 008f 83E801   		subl	$1, %eax
 211              		.loc 2 12 39 discriminator 2
 212 0092 4898     		cltq
 213 0094 488D1485 		leaq	0(,%rax,4), %rdx
 213      00000000 
 214 009c 488D05A0 		leaq	s(%rip), %rax
 214      070000
 215 00a3 8B0402   		movl	(%rdx,%rax), %eax
 216              		.loc 2 12 31 discriminator 2
 217 00a6 F7D8     		negl	%eax
 218              		.loc 2 12 22 discriminator 2
 219 00a8 3945FC   		cmpl	%eax, -4(%rbp)
 220 00ab 0F8CA201 		jl	.L22
 220      0000
 221              	.LBB5:
  13:../code/C++/三角形/tria.cpp **** 		for (int i = 1; i < n; ++i)
 222              		.loc 2 13 12
 223 00b1 C745F401 		movl	$1, -12(%rbp)
 223      000000
 224              	.L21:
 225              		.loc 2 13 21 discriminator 1
 226 00b8 8B05FC07 		movl	n(%rip), %eax
 226      0000
 227 00be 3945F4   		cmpl	%eax, -12(%rbp)
 228 00c1 0F8D2901 		jge	.L14
 228      0000
 229              	.LBB6:
 230              	.LBB7:
  14:../code/C++/三角形/tria.cpp **** 		{
  15:../code/C++/三角形/tria.cpp **** 			for (int j = 0; j < n - i; ++j)
 231              		.loc 2 15 13
 232 00c7 C745F000 		movl	$0, -16(%rbp)
 232      000000
 233              	.L18:
 234              		.loc 2 15 26 discriminator 2
 235 00ce 8B05FC07 		movl	n(%rip), %eax
 235      0000
 236 00d4 2B45F4   		subl	-12(%rbp), %eax
 237              		.loc 2 15 22 discriminator 2
 238 00d7 3945F0   		cmpl	%eax, -16(%rbp)
 239 00da 0F8DB700 		jge	.L15
 239      0000
  16:../code/C++/三角形/tria.cpp **** 			{
  17:../code/C++/三角形/tria.cpp **** 				f[i][j] = f[i - 1][j] ^ f[i - 1][j + 1];
 240              		.loc 2 17 19
 241 00e0 8B45F4   		movl	-12(%rbp), %eax
 242 00e3 8D50FF   		leal	-1(%rax), %edx
 243              		.loc 2 17 25
 244 00e6 8B45F0   		movl	-16(%rbp), %eax
 245 00e9 4898     		cltq
 246 00eb 4863D2   		movslq	%edx, %rdx
 247 00ee 486BD216 		imulq	$22, %rdx, %rdx
 248 00f2 4801D0   		addq	%rdx, %rax
 249 00f5 488D1485 		leaq	0(,%rax,4), %rdx
 249      00000000 
 250 00fd 488D0500 		leaq	f(%rip), %rax
 250      000000
 251 0104 8B0C02   		movl	(%rdx,%rax), %ecx
 252              		.loc 2 17 33
 253 0107 8B45F4   		movl	-12(%rbp), %eax
 254 010a 8D50FF   		leal	-1(%rax), %edx
 255              		.loc 2 17 40
 256 010d 8B45F0   		movl	-16(%rbp), %eax
 257 0110 83C001   		addl	$1, %eax
 258              		.loc 2 17 43
 259 0113 4898     		cltq
 260 0115 4863D2   		movslq	%edx, %rdx
 261 0118 486BD216 		imulq	$22, %rdx, %rdx
 262 011c 4801D0   		addq	%rdx, %rax
 263 011f 488D1485 		leaq	0(,%rax,4), %rdx
 263      00000000 
 264 0127 488D0500 		leaq	f(%rip), %rax
 264      000000
 265 012e 8B0402   		movl	(%rdx,%rax), %eax
 266              		.loc 2 17 27
 267 0131 31C1     		xorl	%eax, %ecx
 268              		.loc 2 17 13
 269 0133 8B45F0   		movl	-16(%rbp), %eax
 270 0136 4898     		cltq
 271 0138 8B55F4   		movl	-12(%rbp), %edx
 272 013b 4863D2   		movslq	%edx, %rdx
 273 013e 486BD216 		imulq	$22, %rdx, %rdx
 274 0142 4801D0   		addq	%rdx, %rax
 275 0145 488D1485 		leaq	0(,%rax,4), %rdx
 275      00000000 
 276 014d 488D0500 		leaq	f(%rip), %rax
 276      000000
 277 0154 890C02   		movl	%ecx, (%rdx,%rax)
  18:../code/C++/三角形/tria.cpp **** 				tmp += f[i][j] ? 1 : -1;
 278              		.loc 2 18 18
 279 0157 8B45F0   		movl	-16(%rbp), %eax
 280 015a 4898     		cltq
 281 015c 8B55F4   		movl	-12(%rbp), %edx
 282 015f 4863D2   		movslq	%edx, %rdx
 283 0162 486BD216 		imulq	$22, %rdx, %rdx
 284 0166 4801D0   		addq	%rdx, %rax
 285 0169 488D1485 		leaq	0(,%rax,4), %rdx
 285      00000000 
 286 0171 488D0500 		leaq	f(%rip), %rax
 286      000000
 287 0178 8B0402   		movl	(%rdx,%rax), %eax
 288              		.loc 2 18 20
 289 017b 85C0     		testl	%eax, %eax
 290 017d 7407     		je	.L16
 291              		.loc 2 18 20 is_stmt 0 discriminator 1
 292 017f B8010000 		movl	$1, %eax
 292      00
 293 0184 EB05     		jmp	.L17
 294              	.L16:
 295              		.loc 2 18 20 discriminator 2
 296 0186 B8FFFFFF 		movl	$-1, %eax
 296      FF
 297              	.L17:
 298              		.loc 2 18 9 is_stmt 1 discriminator 4
 299 018b 0145FC   		addl	%eax, -4(%rbp)
  15:../code/C++/三角形/tria.cpp **** 			{
 300              		.loc 2 15 4 discriminator 4
 301 018e 8345F001 		addl	$1, -16(%rbp)
 302 0192 E937FFFF 		jmp	.L18
 302      FF
 303              	.L15:
 304              	.LBE7:
  19:../code/C++/三角形/tria.cpp **** 			}
  20:../code/C++/三角形/tria.cpp **** 			if (tmp > s[n - 1 - i] || tmp < -s[n - 1 - i]) return;
 305              		.loc 2 20 18
 306 0197 8B05FC07 		movl	n(%rip), %eax
 306      0000
 307 019d 83E801   		subl	$1, %eax
 308              		.loc 2 20 22
 309 01a0 2B45F4   		subl	-12(%rbp), %eax
 310              		.loc 2 20 25
 311 01a3 4898     		cltq
 312 01a5 488D1485 		leaq	0(,%rax,4), %rdx
 312      00000000 
 313 01ad 488D05A0 		leaq	s(%rip), %rax
 313      070000
 314 01b4 8B0402   		movl	(%rdx,%rax), %eax
 315              		.loc 2 20 4
 316 01b7 3945FC   		cmpl	%eax, -4(%rbp)
 317 01ba 0F8F9600 		jg	.L23
 317      0000
 318              		.loc 2 20 41 discriminator 2
 319 01c0 8B05FC07 		movl	n(%rip), %eax
 319      0000
 320 01c6 83E801   		subl	$1, %eax
 321              		.loc 2 20 45 discriminator 2
 322 01c9 2B45F4   		subl	-12(%rbp), %eax
 323              		.loc 2 20 48 discriminator 2
 324 01cc 4898     		cltq
 325 01ce 488D1485 		leaq	0(,%rax,4), %rdx
 325      00000000 
 326 01d6 488D05A0 		leaq	s(%rip), %rax
 326      070000
 327 01dd 8B0402   		movl	(%rdx,%rax), %eax
 328              		.loc 2 20 36 discriminator 2
 329 01e0 F7D8     		negl	%eax
 330              		.loc 2 20 27 discriminator 2
 331 01e2 3945FC   		cmpl	%eax, -4(%rbp)
 332 01e5 7C6F     		jl	.L23
 333              	.LBE6:
  13:../code/C++/三角形/tria.cpp **** 		{
 334              		.loc 2 13 3 discriminator 2
 335 01e7 8345F401 		addl	$1, -12(%rbp)
 336 01eb E9C8FEFF 		jmp	.L21
 336      FF
 337              	.L14:
 338              	.LBE5:
  21:../code/C++/三角形/tria.cpp **** 		}
  22:../code/C++/三角形/tria.cpp **** 		++ans;
 339              		.loc 2 22 3
 340 01f0 8B050008 		movl	ans(%rip), %eax
 340      0000
 341 01f6 83C001   		addl	$1, %eax
 342 01f9 89050008 		movl	%eax, ans(%rip)
 342      0000
  23:../code/C++/三角形/tria.cpp **** 		return;
 343              		.loc 2 23 3
 344 01ff EB56     		jmp	.L5
 345              	.L6:
 346              	.LBE3:
 347              	.LBE2:
  24:../code/C++/三角形/tria.cpp **** 	}
  25:../code/C++/三角形/tria.cpp **** 	f[0][k] = 0;
 348              		.loc 2 25 10
 349 0201 8B4510   		movl	16(%rbp), %eax
 350 0204 4898     		cltq
 351 0206 488D1485 		leaq	0(,%rax,4), %rdx
 351      00000000 
 352 020e 488D0500 		leaq	f(%rip), %rax
 352      000000
 353 0215 C7040200 		movl	$0, (%rdx,%rax)
 353      000000
  26:../code/C++/三角形/tria.cpp **** 	dfs(k + 1);
 354              		.loc 2 26 5
 355 021c 8B4510   		movl	16(%rbp), %eax
 356 021f 83C001   		addl	$1, %eax
 357 0222 89C1     		movl	%eax, %ecx
 358 0224 E8D7FDFF 		call	_Z3dfsi
 358      FF
  27:../code/C++/三角形/tria.cpp **** 	f[0][k] = 1;
 359              		.loc 2 27 10
 360 0229 8B4510   		movl	16(%rbp), %eax
 361 022c 4898     		cltq
 362 022e 488D1485 		leaq	0(,%rax,4), %rdx
 362      00000000 
 363 0236 488D0500 		leaq	f(%rip), %rax
 363      000000
 364 023d C7040201 		movl	$1, (%rdx,%rax)
 364      000000
  28:../code/C++/三角形/tria.cpp **** 	dfs(k + 1);
 365              		.loc 2 28 5
 366 0244 8B4510   		movl	16(%rbp), %eax
 367 0247 83C001   		addl	$1, %eax
 368 024a 89C1     		movl	%eax, %ecx
 369 024c E8AFFDFF 		call	_Z3dfsi
 369      FF
 370 0251 EB04     		jmp	.L5
 371              	.L22:
 372              	.LBB11:
 373              	.LBB10:
  12:../code/C++/三角形/tria.cpp **** 		for (int i = 1; i < n; ++i)
 374              		.loc 2 12 42
 375 0253 90       		nop
 376 0254 EB01     		jmp	.L5
 377              	.L23:
 378              	.LBB9:
 379              	.LBB8:
  20:../code/C++/三角形/tria.cpp **** 		}
 380              		.loc 2 20 51
 381 0256 90       		nop
 382              	.L5:
 383              	.LBE8:
 384              	.LBE9:
 385              	.LBE10:
 386              	.LBE11:
  29:../code/C++/三角形/tria.cpp **** }
 387              		.loc 2 29 1
 388 0257 4883C430 		addq	$48, %rsp
 389 025b 5D       		popq	%rbp
 390              		.cfi_restore 6
 391              		.cfi_def_cfa 7, 8
 392 025c C3       		ret
 393              		.cfi_endproc
 394              	.LFE44:
 395              		.seh_endproc
 397              		.section .rdata,"dr"
 398              	.LC0:
 399 0004 7200     		.ascii "r\0"
 400              	.LC1:
 401 0006 74726961 		.ascii "tria.in\0"
 401      2E696E00 
 402              	.LC2:
 403 000e 7700     		.ascii "w\0"
 404              	.LC3:
 405 0010 74726961 		.ascii "tria.out\0"
 405      2E6F7574 
 405      00
 406              	.LC4:
 407 0019 256400   		.ascii "%d\0"
 408              	.LC5:
 409 001c 3000     		.ascii "0\0"
 410 001e 0000     		.text
 411              		.globl	main
 413              		.seh_proc	main
 414              	main:
 415              	.LFB45:
  30:../code/C++/三角形/tria.cpp **** 
  31:../code/C++/三角形/tria.cpp **** int main()
  32:../code/C++/三角形/tria.cpp **** {
 416              		.loc 2 32 1
 417              		.cfi_startproc
 418 025d 55       		pushq	%rbp
 419              		.seh_pushreg	%rbp
 420              		.cfi_def_cfa_offset 16
 421              		.cfi_offset 6, -16
 422 025e 4889E5   		movq	%rsp, %rbp
 423              		.seh_setframe	%rbp, 0
 424              		.cfi_def_cfa_register 6
 425 0261 4883EC30 		subq	$48, %rsp
 426              		.seh_stackalloc	48
 427              		.seh_endprologue
 428              		.loc 2 32 1
 429 0265 E8000000 		call	__main
 429      00
 430              	.LVL2:
  33:../code/C++/三角形/tria.cpp **** 	freopen("tria.in", "r", stdin);
 431              		.loc 2 33 9
 432 026a B9000000 		movl	$0, %ecx
 432      00
 433 026f 488B0500 		movq	__imp___acrt_iob_func(%rip), %rax
 433      000000
 434 0276 FFD0     		call	*%rax
 435              	.LVL3:
 436 0278 4989C0   		movq	%rax, %r8
 437 027b 488D1504 		leaq	.LC0(%rip), %rdx
 437      000000
 438 0282 488D0D06 		leaq	.LC1(%rip), %rcx
 438      000000
 439 0289 E8000000 		call	freopen
 439      00
  34:../code/C++/三角形/tria.cpp **** 	freopen("tria.out", "w", stdout);
 440              		.loc 2 34 9
 441 028e B9010000 		movl	$1, %ecx
 441      00
 442 0293 488B0500 		movq	__imp___acrt_iob_func(%rip), %rax
 442      000000
 443 029a FFD0     		call	*%rax
 444              	.LVL4:
 445 029c 4989C0   		movq	%rax, %r8
 446 029f 488D150E 		leaq	.LC2(%rip), %rdx
 446      000000
 447 02a6 488D0D10 		leaq	.LC3(%rip), %rcx
 447      000000
 448 02ad E8000000 		call	freopen
 448      00
  35:../code/C++/三角形/tria.cpp **** 	scanf("%d", &n);
 449              		.loc 2 35 7
 450 02b2 488D15FC 		leaq	n(%rip), %rdx
 450      070000
 451 02b9 488D0D19 		leaq	.LC4(%rip), %rcx
 451      000000
 452 02c0 E8000000 		call	_Z5scanfPKcz
 452      00
  36:../code/C++/三角形/tria.cpp **** 	if (((n + 1) * n >> 1) & 1)
 453              		.loc 2 36 10
 454 02c5 8B05FC07 		movl	n(%rip), %eax
 454      0000
 455 02cb 8D5001   		leal	1(%rax), %edx
 456              		.loc 2 36 15
 457 02ce 8B05FC07 		movl	n(%rip), %eax
 457      0000
 458 02d4 0FAFC2   		imull	%edx, %eax
 459              		.loc 2 36 28
 460 02d7 83E002   		andl	$2, %eax
 461              		.loc 2 36 2
 462 02da 85C0     		testl	%eax, %eax
 463 02dc 7413     		je	.L25
  37:../code/C++/三角形/tria.cpp **** 	{
  38:../code/C++/三角形/tria.cpp **** 		puts("0");
 464              		.loc 2 38 7
 465 02de 488D0D1C 		leaq	.LC5(%rip), %rcx
 465      000000
 466 02e5 E8000000 		call	puts
 466      00
  39:../code/C++/三角形/tria.cpp **** 		return 0;
 467              		.loc 2 39 10
 468 02ea B8000000 		movl	$0, %eax
 468      00
 469 02ef EB60     		jmp	.L26
 470              	.L25:
 471              	.LBB12:
  40:../code/C++/三角形/tria.cpp **** 	}
  41:../code/C++/三角形/tria.cpp **** 	for (int i = 0; i < n; ++i) s[i] = (i * (i + 1)) >> 1;
 472              		.loc 2 41 11
 473 02f1 C745FC00 		movl	$0, -4(%rbp)
 473      000000
 474              	.L28:
 475              		.loc 2 41 20 discriminator 3
 476 02f8 8B05FC07 		movl	n(%rip), %eax
 476      0000
 477 02fe 3945FC   		cmpl	%eax, -4(%rbp)
 478 0301 7D2B     		jge	.L27
 479              		.loc 2 41 45 discriminator 2
 480 0303 8B45FC   		movl	-4(%rbp), %eax
 481 0306 83C001   		addl	$1, %eax
 482              		.loc 2 41 40 discriminator 2
 483 0309 0FAF45FC 		imull	-4(%rbp), %eax
 484              		.loc 2 41 51 discriminator 2
 485 030d D1F8     		sarl	%eax
 486 030f 89C1     		movl	%eax, %ecx
 487              		.loc 2 41 35 discriminator 2
 488 0311 8B45FC   		movl	-4(%rbp), %eax
 489 0314 4898     		cltq
 490 0316 488D1485 		leaq	0(,%rax,4), %rdx
 490      00000000 
 491 031e 488D05A0 		leaq	s(%rip), %rax
 491      070000
 492 0325 890C02   		movl	%ecx, (%rdx,%rax)
 493              		.loc 2 41 2 discriminator 2
 494 0328 8345FC01 		addl	$1, -4(%rbp)
 495 032c EBCA     		jmp	.L28
 496              	.L27:
 497              	.LBE12:
  42:../code/C++/三角形/tria.cpp **** 	dfs(0);
 498              		.loc 2 42 5
 499 032e B9000000 		movl	$0, %ecx
 499      00
 500 0333 E8C8FCFF 		call	_Z3dfsi
 500      FF
  43:../code/C++/三角形/tria.cpp **** 	printf("%d", ans);
 501              		.loc 2 43 8
 502 0338 8B050008 		movl	ans(%rip), %eax
 502      0000
 503 033e 89C2     		movl	%eax, %edx
 504 0340 488D0D19 		leaq	.LC4(%rip), %rcx
 504      000000
 505 0347 E8000000 		call	_Z6printfPKcz
 505      00
  44:../code/C++/三角形/tria.cpp **** 	return 0;
 506              		.loc 2 44 9
 507 034c B8000000 		movl	$0, %eax
 507      00
 508              	.L26:
  45:../code/C++/三角形/tria.cpp **** }...
 509              		.loc 2 45 1
 510 0351 4883C430 		addq	$48, %rsp
 511 0355 5D       		popq	%rbp
 512              		.cfi_restore 6
 513              		.cfi_def_cfa 7, 8
 514 0356 C3       		ret
 515              		.cfi_endproc
 516              	.LFE45:
 517              		.seh_endproc
 518              	.Letext0:
 519              		.file 3 "C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-m
 520              		.file 4 "C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-m
 521              		.file 5 "C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/i
 522              		.file 6 "<built-in>"
 523 0357 90909090 		.section	.debug_info,"dr"
 523      90909090 
 523      90
 524              	.Ldebug_info0:
 525 0000 CA0B0000 		.long	0xbca
 526 0004 0400     		.word	0x4
 527 0006 00000000 		.secrel32	.Ldebug_abbrev0
 528 000a 08       		.byte	0x8
 529 000b 01       		.uleb128 0x1
 530 000c 474E5520 		.ascii "GNU C++98 8.1.0 -mtune=core2 -march=nocona -g -std=gnu++98\0"
 530      432B2B39 
 530      3820382E 
 530      312E3020 
 530      2D6D7475 
 531 0047 04       		.byte	0x4
 532 0048 2E2E2F63 		.ascii "../code/C++/\310\375\275\307\320\316/tria.cpp\0"
 532      6F64652F 
 532      432B2B2F 
 532      C8FDBDC7 
 532      D0CE2F74 
 533 0064 453A5C4F 		.ascii "E:\\OI-Files\0"
 533      492D4669 
 533      6C657300 
 534 0070 60000000 		.secrel32	.Ldebug_ranges0+0x60
 535 0074 00000000 		.quad	0
 535      00000000 
 536 007c 00000000 		.secrel32	.Ldebug_line0
 537 0080 02       		.uleb128 0x2
 538 0081 73746400 		.ascii "std\0"
 539 0085 06       		.byte	0x6
 540 0086 00       		.byte	0
 541 0087 F2010000 		.long	0x1f2
 542 008b 03       		.uleb128 0x3
 543 008c 5F5F6378 		.ascii "__cxx11\0"
 543      78313100 
 544 0094 04       		.byte	0x4
 545 0095 0401     		.word	0x104
 546 0097 41       		.byte	0x41
 547 0098 04       		.uleb128 0x4
 548 0099 04       		.byte	0x4
 549 009a 0401     		.word	0x104
 550 009c 41       		.byte	0x41
 551 009d 8B000000 		.long	0x8b
 552 00a1 05       		.uleb128 0x5
 553 00a2 03       		.byte	0x3
 554 00a3 62       		.byte	0x62
 555 00a4 0B       		.byte	0xb
 556 00a5 A8030000 		.long	0x3a8
 557 00a9 05       		.uleb128 0x5
 558 00aa 03       		.byte	0x3
 559 00ab 63       		.byte	0x63
 560 00ac 0B       		.byte	0xb
 561 00ad B5030000 		.long	0x3b5
 562 00b1 05       		.uleb128 0x5
 563 00b2 03       		.byte	0x3
 564 00b3 65       		.byte	0x65
 565 00b4 0B       		.byte	0xb
 566 00b5 C9030000 		.long	0x3c9
 567 00b9 05       		.uleb128 0x5
 568 00ba 03       		.byte	0x3
 569 00bb 66       		.byte	0x66
 570 00bc 0B       		.byte	0xb
 571 00bd E7030000 		.long	0x3e7
 572 00c1 05       		.uleb128 0x5
 573 00c2 03       		.byte	0x3
 574 00c3 67       		.byte	0x67
 575 00c4 0B       		.byte	0xb
 576 00c5 01040000 		.long	0x401
 577 00c9 05       		.uleb128 0x5
 578 00ca 03       		.byte	0x3
 579 00cb 68       		.byte	0x68
 580 00cc 0B       		.byte	0xb
 581 00cd 19040000 		.long	0x419
 582 00d1 05       		.uleb128 0x5
 583 00d2 03       		.byte	0x3
 584 00d3 69       		.byte	0x69
 585 00d4 0B       		.byte	0xb
 586 00d5 33040000 		.long	0x433
 587 00d9 05       		.uleb128 0x5
 588 00da 03       		.byte	0x3
 589 00db 6A       		.byte	0x6a
 590 00dc 0B       		.byte	0xb
 591 00dd 4D040000 		.long	0x44d
 592 00e1 05       		.uleb128 0x5
 593 00e2 03       		.byte	0x3
 594 00e3 6B       		.byte	0x6b
 595 00e4 0B       		.byte	0xb
 596 00e5 66040000 		.long	0x466
 597 00e9 05       		.uleb128 0x5
 598 00ea 03       		.byte	0x3
 599 00eb 6C       		.byte	0x6c
 600 00ec 0B       		.byte	0xb
 601 00ed 8C040000 		.long	0x48c
 602 00f1 05       		.uleb128 0x5
 603 00f2 03       		.byte	0x3
 604 00f3 6D       		.byte	0x6d
 605 00f4 0B       		.byte	0xb
 606 00f5 AF040000 		.long	0x4af
 607 00f9 05       		.uleb128 0x5
 608 00fa 03       		.byte	0x3
 609 00fb 6E       		.byte	0x6e
 610 00fc 0B       		.byte	0xb
 611 00fd D3040000 		.long	0x4d3
 612 0101 05       		.uleb128 0x5
 613 0102 03       		.byte	0x3
 614 0103 71       		.byte	0x71
 615 0104 0B       		.byte	0xb
 616 0105 0B050000 		.long	0x50b
 617 0109 05       		.uleb128 0x5
 618 010a 03       		.byte	0x3
 619 010b 72       		.byte	0x72
 620 010c 0B       		.byte	0xb
 621 010d 35050000 		.long	0x535
 622 0111 05       		.uleb128 0x5
 623 0112 03       		.byte	0x3
 624 0113 73       		.byte	0x73
 625 0114 0B       		.byte	0xb
 626 0115 5A050000 		.long	0x55a
 627 0119 05       		.uleb128 0x5
 628 011a 03       		.byte	0x3
 629 011b 74       		.byte	0x74
 630 011c 0B       		.byte	0xb
 631 011d 90050000 		.long	0x590
 632 0121 05       		.uleb128 0x5
 633 0122 03       		.byte	0x3
 634 0123 75       		.byte	0x75
 635 0124 0B       		.byte	0xb
 636 0125 B3050000 		.long	0x5b3
 637 0129 05       		.uleb128 0x5
 638 012a 03       		.byte	0x3
 639 012b 76       		.byte	0x76
 640 012c 0B       		.byte	0xb
 641 012d D9050000 		.long	0x5d9
 642 0131 05       		.uleb128 0x5
 643 0132 03       		.byte	0x3
 644 0133 78       		.byte	0x78
 645 0134 0B       		.byte	0xb
 646 0135 F2050000 		.long	0x5f2
 647 0139 05       		.uleb128 0x5
 648 013a 03       		.byte	0x3
 649 013b 79       		.byte	0x79
 650 013c 0B       		.byte	0xb
 651 013d 0A060000 		.long	0x60a
 652 0141 05       		.uleb128 0x5
 653 0142 03       		.byte	0x3
 654 0143 7C       		.byte	0x7c
 655 0144 0B       		.byte	0xb
 656 0145 1B060000 		.long	0x61b
 657 0149 05       		.uleb128 0x5
 658 014a 03       		.byte	0x3
 659 014b 7E       		.byte	0x7e
 660 014c 0B       		.byte	0xb
 661 014d 33060000 		.long	0x633
 662 0151 05       		.uleb128 0x5
 663 0152 03       		.byte	0x3
 664 0153 7F       		.byte	0x7f
 665 0154 0B       		.byte	0xb
 666 0155 49060000 		.long	0x649
 667 0159 05       		.uleb128 0x5
 668 015a 03       		.byte	0x3
 669 015b 83       		.byte	0x83
 670 015c 0B       		.byte	0xb
 671 015d BD060000 		.long	0x6bd
 672 0161 05       		.uleb128 0x5
 673 0162 03       		.byte	0x3
 674 0163 84       		.byte	0x84
 675 0164 0B       		.byte	0xb
 676 0165 D7060000 		.long	0x6d7
 677 0169 05       		.uleb128 0x5
 678 016a 03       		.byte	0x3
 679 016b 85       		.byte	0x85
 680 016c 0B       		.byte	0xb
 681 016d F6060000 		.long	0x6f6
 682 0171 05       		.uleb128 0x5
 683 0172 03       		.byte	0x3
 684 0173 86       		.byte	0x86
 685 0174 0B       		.byte	0xb
 686 0175 0C070000 		.long	0x70c
 687 0179 05       		.uleb128 0x5
 688 017a 03       		.byte	0x3
 689 017b 87       		.byte	0x87
 690 017c 0B       		.byte	0xb
 691 017d 7E070000 		.long	0x77e
 692 0181 05       		.uleb128 0x5
 693 0182 03       		.byte	0x3
 694 0183 88       		.byte	0x88
 695 0184 0B       		.byte	0xb
 696 0185 99070000 		.long	0x799
 697 0189 05       		.uleb128 0x5
 698 018a 03       		.byte	0x3
 699 018b 89       		.byte	0x89
 700 018c 0B       		.byte	0xb
 701 018d C3070000 		.long	0x7c3
 702 0191 05       		.uleb128 0x5
 703 0192 03       		.byte	0x3
 704 0193 8A       		.byte	0x8a
 705 0194 0B       		.byte	0xb
 706 0195 F5070000 		.long	0x7f5
 707 0199 05       		.uleb128 0x5
 708 019a 03       		.byte	0x3
 709 019b 8B       		.byte	0x8b
 710 019c 0B       		.byte	0xb
 711 019d 26080000 		.long	0x826
 712 01a1 05       		.uleb128 0x5
 713 01a2 03       		.byte	0x3
 714 01a3 8D       		.byte	0x8d
 715 01a4 0B       		.byte	0xb
 716 01a5 37080000 		.long	0x837
 717 01a9 05       		.uleb128 0x5
 718 01aa 03       		.byte	0x3
 719 01ab 8F       		.byte	0x8f
 720 01ac 0B       		.byte	0xb
 721 01ad 51080000 		.long	0x851
 722 01b1 05       		.uleb128 0x5
 723 01b2 03       		.byte	0x3
 724 01b3 90       		.byte	0x90
 725 01b4 0B       		.byte	0xb
 726 01b5 70080000 		.long	0x870
 727 01b9 05       		.uleb128 0x5
 728 01ba 03       		.byte	0x3
 729 01bb 91       		.byte	0x91
 730 01bc 0B       		.byte	0xb
 731 01bd AF080000 		.long	0x8af
 732 01c1 05       		.uleb128 0x5
 733 01c2 03       		.byte	0x3
 734 01c3 92       		.byte	0x92
 735 01c4 0B       		.byte	0xb
 736 01c5 DF080000 		.long	0x8df
 737 01c9 05       		.uleb128 0x5
 738 01ca 03       		.byte	0x3
 739 01cb B9       		.byte	0xb9
 740 01cc 16       		.byte	0x16
 741 01cd 18090000 		.long	0x918
 742 01d1 05       		.uleb128 0x5
 743 01d2 03       		.byte	0x3
 744 01d3 BA       		.byte	0xba
 745 01d4 16       		.byte	0x16
 746 01d5 52090000 		.long	0x952
 747 01d9 05       		.uleb128 0x5
 748 01da 03       		.byte	0x3
 749 01db BB       		.byte	0xbb
 750 01dc 16       		.byte	0x16
 751 01dd 8F090000 		.long	0x98f
 752 01e1 05       		.uleb128 0x5
 753 01e2 03       		.byte	0x3
 754 01e3 BC       		.byte	0xbc
 755 01e4 16       		.byte	0x16
 756 01e5 BD090000 		.long	0x9bd
 757 01e9 05       		.uleb128 0x5
 758 01ea 03       		.byte	0x3
 759 01eb BD       		.byte	0xbd
 760 01ec 16       		.byte	0x16
 761 01ed FE090000 		.long	0x9fe
 762 01f1 00       		.byte	0
 763 01f2 06       		.uleb128 0x6
 764 01f3 5F5F676E 		.ascii "__gnu_cxx\0"
 764      755F6378 
 764      7800
 765 01fd 04       		.byte	0x4
 766 01fe 0601     		.word	0x106
 767 0200 0B       		.byte	0xb
 768 0201 44020000 		.long	0x244
 769 0205 03       		.uleb128 0x3
 770 0206 5F5F6378 		.ascii "__cxx11\0"
 770      78313100 
 771 020e 04       		.byte	0x4
 772 020f 0801     		.word	0x108
 773 0211 41       		.byte	0x41
 774 0212 04       		.uleb128 0x4
 775 0213 04       		.byte	0x4
 776 0214 0801     		.word	0x108
 777 0216 41       		.byte	0x41
 778 0217 05020000 		.long	0x205
 779 021b 05       		.uleb128 0x5
 780 021c 03       		.byte	0x3
 781 021d AF       		.byte	0xaf
 782 021e 0B       		.byte	0xb
 783 021f 18090000 		.long	0x918
 784 0223 05       		.uleb128 0x5
 785 0224 03       		.byte	0x3
 786 0225 B0       		.byte	0xb0
 787 0226 0B       		.byte	0xb
 788 0227 52090000 		.long	0x952
 789 022b 05       		.uleb128 0x5
 790 022c 03       		.byte	0x3
 791 022d B1       		.byte	0xb1
 792 022e 0B       		.byte	0xb
 793 022f 8F090000 		.long	0x98f
 794 0233 05       		.uleb128 0x5
 795 0234 03       		.byte	0x3
 796 0235 B2       		.byte	0xb2
 797 0236 0B       		.byte	0xb
 798 0237 BD090000 		.long	0x9bd
 799 023b 05       		.uleb128 0x5
 800 023c 03       		.byte	0x3
 801 023d B3       		.byte	0xb3
 802 023e 0B       		.byte	0xb
 803 023f FE090000 		.long	0x9fe
 804 0243 00       		.byte	0
 805 0244 07       		.uleb128 0x7
 806 0245 08       		.byte	0x8
 807 0246 5F5F6275 		.ascii "__builtin_va_list\0"
 807      696C7469 
 807      6E5F7661 
 807      5F6C6973 
 807      7400
 808 0258 5C020000 		.long	0x25c
 809 025c 08       		.uleb128 0x8
 810 025d 01       		.byte	0x1
 811 025e 06       		.byte	0x6
 812 025f 63686172 		.ascii "char\0"
 812      00
 813 0264 09       		.uleb128 0x9
 814 0265 5C020000 		.long	0x25c
 815 0269 0A       		.uleb128 0xa
 816 026a 73697A65 		.ascii "size_t\0"
 816      5F7400
 817 0271 05       		.byte	0x5
 818 0272 23       		.byte	0x23
 819 0273 2C       		.byte	0x2c
 820 0274 78020000 		.long	0x278
 821 0278 08       		.uleb128 0x8
 822 0279 08       		.byte	0x8
 823 027a 07       		.byte	0x7
 824 027b 6C6F6E67 		.ascii "long long unsigned int\0"
 824      206C6F6E 
 824      6720756E 
 824      7369676E 
 824      65642069 
 825 0292 08       		.uleb128 0x8
 826 0293 08       		.byte	0x8
 827 0294 05       		.byte	0x5
 828 0295 6C6F6E67 		.ascii "long long int\0"
 828      206C6F6E 
 828      6720696E 
 828      7400
 829 02a3 08       		.uleb128 0x8
 830 02a4 02       		.byte	0x2
 831 02a5 07       		.byte	0x7
 832 02a6 73686F72 		.ascii "short unsigned int\0"
 832      7420756E 
 832      7369676E 
 832      65642069 
 832      6E7400
 833 02b9 08       		.uleb128 0x8
 834 02ba 04       		.byte	0x4
 835 02bb 05       		.byte	0x5
 836 02bc 696E7400 		.ascii "int\0"
 837 02c0 09       		.uleb128 0x9
 838 02c1 B9020000 		.long	0x2b9
 839 02c5 08       		.uleb128 0x8
 840 02c6 04       		.byte	0x4
 841 02c7 05       		.byte	0x5
 842 02c8 6C6F6E67 		.ascii "long int\0"
 842      20696E74 
 842      00
 843 02d1 0B       		.uleb128 0xb
 844 02d2 08       		.byte	0x8
 845 02d3 5C020000 		.long	0x25c
 846 02d7 08       		.uleb128 0x8
 847 02d8 02       		.byte	0x2
 848 02d9 07       		.byte	0x7
 849 02da 77636861 		.ascii "wchar_t\0"
 849      725F7400 
 850 02e2 08       		.uleb128 0x8
 851 02e3 04       		.byte	0x4
 852 02e4 07       		.byte	0x7
 853 02e5 756E7369 		.ascii "unsigned int\0"
 853      676E6564 
 853      20696E74 
 853      00
 854 02f2 08       		.uleb128 0x8
 855 02f3 04       		.byte	0x4
 856 02f4 07       		.byte	0x7
 857 02f5 6C6F6E67 		.ascii "long unsigned int\0"
 857      20756E73 
 857      69676E65 
 857      6420696E 
 857      7400
 858 0307 08       		.uleb128 0x8
 859 0308 01       		.byte	0x1
 860 0309 08       		.byte	0x8
 861 030a 756E7369 		.ascii "unsigned char\0"
 861      676E6564 
 861      20636861 
 861      7200
 862 0318 0C       		.uleb128 0xc
 863 0319 5F696F62 		.ascii "_iobuf\0"
 863      756600
 864 0320 30       		.byte	0x30
 865 0321 01       		.byte	0x1
 866 0322 1A       		.byte	0x1a
 867 0323 0A       		.byte	0xa
 868 0324 A8030000 		.long	0x3a8
 869 0328 0D       		.uleb128 0xd
 870 0329 5F707472 		.ascii "_ptr\0"
 870      00
 871 032e 01       		.byte	0x1
 872 032f 1B       		.byte	0x1b
 873 0330 0B       		.byte	0xb
 874 0331 D1020000 		.long	0x2d1
 875 0335 00       		.byte	0
 876 0336 0D       		.uleb128 0xd
 877 0337 5F636E74 		.ascii "_cnt\0"
 877      00
 878 033c 01       		.byte	0x1
 879 033d 1C       		.byte	0x1c
 880 033e 09       		.byte	0x9
 881 033f B9020000 		.long	0x2b9
 882 0343 08       		.byte	0x8
 883 0344 0D       		.uleb128 0xd
 884 0345 5F626173 		.ascii "_base\0"
 884      6500
 885 034b 01       		.byte	0x1
 886 034c 1D       		.byte	0x1d
 887 034d 0B       		.byte	0xb
 888 034e D1020000 		.long	0x2d1
 889 0352 10       		.byte	0x10
 890 0353 0D       		.uleb128 0xd
 891 0354 5F666C61 		.ascii "_flag\0"
 891      6700
 892 035a 01       		.byte	0x1
 893 035b 1E       		.byte	0x1e
 894 035c 09       		.byte	0x9
 895 035d B9020000 		.long	0x2b9
 896 0361 18       		.byte	0x18
 897 0362 0D       		.uleb128 0xd
 898 0363 5F66696C 		.ascii "_file\0"
 898      6500
 899 0369 01       		.byte	0x1
 900 036a 1F       		.byte	0x1f
 901 036b 09       		.byte	0x9
 902 036c B9020000 		.long	0x2b9
 903 0370 1C       		.byte	0x1c
 904 0371 0D       		.uleb128 0xd
 905 0372 5F636861 		.ascii "_charbuf\0"
 905      72627566 
 905      00
 906 037b 01       		.byte	0x1
 907 037c 20       		.byte	0x20
 908 037d 09       		.byte	0x9
 909 037e B9020000 		.long	0x2b9
 910 0382 20       		.byte	0x20
 911 0383 0D       		.uleb128 0xd
 912 0384 5F627566 		.ascii "_bufsiz\0"
 912      73697A00 
 913 038c 01       		.byte	0x1
 914 038d 21       		.byte	0x21
 915 038e 09       		.byte	0x9
 916 038f B9020000 		.long	0x2b9
 917 0393 24       		.byte	0x24
 918 0394 0D       		.uleb128 0xd
 919 0395 5F746D70 		.ascii "_tmpfname\0"
 919      666E616D 
 919      6500
 920 039f 01       		.byte	0x1
 921 03a0 22       		.byte	0x22
 922 03a1 0B       		.byte	0xb
 923 03a2 D1020000 		.long	0x2d1
 924 03a6 28       		.byte	0x28
 925 03a7 00       		.byte	0
 926 03a8 0A       		.uleb128 0xa
 927 03a9 46494C45 		.ascii "FILE\0"
 927      00
 928 03ae 01       		.byte	0x1
 929 03af 24       		.byte	0x24
 930 03b0 19       		.byte	0x19
 931 03b1 18030000 		.long	0x318
 932 03b5 0A       		.uleb128 0xa
 933 03b6 66706F73 		.ascii "fpos_t\0"
 933      5F7400
 934 03bd 01       		.byte	0x1
 935 03be 68       		.byte	0x68
 936 03bf 25       		.byte	0x25
 937 03c0 92020000 		.long	0x292
 938 03c4 09       		.uleb128 0x9
 939 03c5 B5030000 		.long	0x3b5
 940 03c9 0E       		.uleb128 0xe
 941 03ca 636C6561 		.ascii "clearerr\0"
 941      72657272 
 941      00
 942 03d3 01       		.byte	0x1
 943 03d4 4202     		.word	0x242
 944 03d6 10       		.byte	0x10
 945 03d7 E1030000 		.long	0x3e1
 946 03db 0F       		.uleb128 0xf
 947 03dc E1030000 		.long	0x3e1
 948 03e0 00       		.byte	0
 949 03e1 0B       		.uleb128 0xb
 950 03e2 08       		.byte	0x8
 951 03e3 A8030000 		.long	0x3a8
 952 03e7 10       		.uleb128 0x10
 953 03e8 66636C6F 		.ascii "fclose\0"
 953      736500
 954 03ef 01       		.byte	0x1
 955 03f0 4302     		.word	0x243
 956 03f2 0F       		.byte	0xf
 957 03f3 B9020000 		.long	0x2b9
 958 03f7 01040000 		.long	0x401
 959 03fb 0F       		.uleb128 0xf
 960 03fc E1030000 		.long	0x3e1
 961 0400 00       		.byte	0
 962 0401 10       		.uleb128 0x10
 963 0402 66656F66 		.ascii "feof\0"
 963      00
 964 0407 01       		.byte	0x1
 965 0408 4A02     		.word	0x24a
 966 040a 0F       		.byte	0xf
 967 040b B9020000 		.long	0x2b9
 968 040f 19040000 		.long	0x419
 969 0413 0F       		.uleb128 0xf
 970 0414 E1030000 		.long	0x3e1
 971 0418 00       		.byte	0
 972 0419 10       		.uleb128 0x10
 973 041a 66657272 		.ascii "ferror\0"
 973      6F7200
 974 0421 01       		.byte	0x1
 975 0422 4B02     		.word	0x24b
 976 0424 0F       		.byte	0xf
 977 0425 B9020000 		.long	0x2b9
 978 0429 33040000 		.long	0x433
 979 042d 0F       		.uleb128 0xf
 980 042e E1030000 		.long	0x3e1
 981 0432 00       		.byte	0
 982 0433 10       		.uleb128 0x10
 983 0434 66666C75 		.ascii "fflush\0"
 983      736800
 984 043b 01       		.byte	0x1
 985 043c 4C02     		.word	0x24c
 986 043e 0F       		.byte	0xf
 987 043f B9020000 		.long	0x2b9
 988 0443 4D040000 		.long	0x44d
 989 0447 0F       		.uleb128 0xf
 990 0448 E1030000 		.long	0x3e1
 991 044c 00       		.byte	0
 992 044d 10       		.uleb128 0x10
 993 044e 66676574 		.ascii "fgetc\0"
 993      6300
 994 0454 01       		.byte	0x1
 995 0455 4D02     		.word	0x24d
 996 0457 0F       		.byte	0xf
 997 0458 B9020000 		.long	0x2b9
 998 045c 66040000 		.long	0x466
 999 0460 0F       		.uleb128 0xf
 1000 0461 E1030000 		.long	0x3e1
 1001 0465 00       		.byte	0
 1002 0466 10       		.uleb128 0x10
 1003 0467 66676574 		.ascii "fgetpos\0"
 1003      706F7300 
 1004 046f 01       		.byte	0x1
 1005 0470 4F02     		.word	0x24f
 1006 0472 0F       		.byte	0xf
 1007 0473 B9020000 		.long	0x2b9
 1008 0477 86040000 		.long	0x486
 1009 047b 0F       		.uleb128 0xf
 1010 047c E1030000 		.long	0x3e1
 1011 0480 0F       		.uleb128 0xf
 1012 0481 86040000 		.long	0x486
 1013 0485 00       		.byte	0
 1014 0486 0B       		.uleb128 0xb
 1015 0487 08       		.byte	0x8
 1016 0488 B5030000 		.long	0x3b5
 1017 048c 10       		.uleb128 0x10
 1018 048d 66676574 		.ascii "fgets\0"
 1018      7300
 1019 0493 01       		.byte	0x1
 1020 0494 5102     		.word	0x251
 1021 0496 11       		.byte	0x11
 1022 0497 D1020000 		.long	0x2d1
 1023 049b AF040000 		.long	0x4af
 1024 049f 0F       		.uleb128 0xf
 1025 04a0 D1020000 		.long	0x2d1
 1026 04a4 0F       		.uleb128 0xf
 1027 04a5 B9020000 		.long	0x2b9
 1028 04a9 0F       		.uleb128 0xf
 1029 04aa E1030000 		.long	0x3e1
 1030 04ae 00       		.byte	0
 1031 04af 10       		.uleb128 0x10
 1032 04b0 666F7065 		.ascii "fopen\0"
 1032      6E00
 1033 04b6 01       		.byte	0x1
 1034 04b7 5802     		.word	0x258
 1035 04b9 11       		.byte	0x11
 1036 04ba E1030000 		.long	0x3e1
 1037 04be CD040000 		.long	0x4cd
 1038 04c2 0F       		.uleb128 0xf
 1039 04c3 CD040000 		.long	0x4cd
 1040 04c7 0F       		.uleb128 0xf
 1041 04c8 CD040000 		.long	0x4cd
 1042 04cc 00       		.byte	0
 1043 04cd 0B       		.uleb128 0xb
 1044 04ce 08       		.byte	0x8
 1045 04cf 64020000 		.long	0x264
 1046 04d3 11       		.uleb128 0x11
 1047 04d4 66707269 		.ascii "fprintf\0"
 1047      6E746600 
 1048 04dc 01       		.byte	0x1
 1049 04dd 4E01     		.word	0x14e
 1050 04df 05       		.byte	0x5
 1051 04e0 5F5A3766 		.ascii "_Z7fprintfP6_iobufPKcz\0"
 1051      7072696E 
 1051      74665036 
 1051      5F696F62 
 1051      7566504B 
 1052 04f7 B9020000 		.long	0x2b9
 1053 04fb 0B050000 		.long	0x50b
 1054 04ff 0F       		.uleb128 0xf
 1055 0500 E1030000 		.long	0x3e1
 1056 0504 0F       		.uleb128 0xf
 1057 0505 CD040000 		.long	0x4cd
 1058 0509 12       		.uleb128 0x12
 1059 050a 00       		.byte	0
 1060 050b 10       		.uleb128 0x10
 1061 050c 66726561 		.ascii "fread\0"
 1061      6400
 1062 0512 01       		.byte	0x1
 1063 0513 5D02     		.word	0x25d
 1064 0515 12       		.byte	0x12
 1065 0516 69020000 		.long	0x269
 1066 051a 33050000 		.long	0x533
 1067 051e 0F       		.uleb128 0xf
 1068 051f 33050000 		.long	0x533
 1069 0523 0F       		.uleb128 0xf
 1070 0524 69020000 		.long	0x269
 1071 0528 0F       		.uleb128 0xf
 1072 0529 69020000 		.long	0x269
 1073 052d 0F       		.uleb128 0xf
 1074 052e E1030000 		.long	0x3e1
 1075 0532 00       		.byte	0
 1076 0533 13       		.uleb128 0x13
 1077 0534 08       		.byte	0x8
 1078 0535 10       		.uleb128 0x10
 1079 0536 6672656F 		.ascii "freopen\0"
 1079      70656E00 
 1080 053e 01       		.byte	0x1
 1081 053f 5E02     		.word	0x25e
 1082 0541 11       		.byte	0x11
 1083 0542 E1030000 		.long	0x3e1
 1084 0546 5A050000 		.long	0x55a
 1085 054a 0F       		.uleb128 0xf
 1086 054b CD040000 		.long	0x4cd
 1087 054f 0F       		.uleb128 0xf
 1088 0550 CD040000 		.long	0x4cd
 1089 0554 0F       		.uleb128 0xf
 1090 0555 E1030000 		.long	0x3e1
 1091 0559 00       		.byte	0
 1092 055a 11       		.uleb128 0x11
 1093 055b 66736361 		.ascii "fscanf\0"
 1093      6E6600
 1094 0562 01       		.byte	0x1
 1095 0563 2101     		.word	0x121
 1096 0565 05       		.byte	0x5
 1097 0566 5F5A3666 		.ascii "_Z6fscanfP6_iobufPKcz\0"
 1097      7363616E 
 1097      6650365F 
 1097      696F6275 
 1097      66504B63 
 1098 057c B9020000 		.long	0x2b9
 1099 0580 90050000 		.long	0x590
 1100 0584 0F       		.uleb128 0xf
 1101 0585 E1030000 		.long	0x3e1
 1102 0589 0F       		.uleb128 0xf
 1103 058a CD040000 		.long	0x4cd
 1104 058e 12       		.uleb128 0x12
 1105 058f 00       		.byte	0
 1106 0590 10       		.uleb128 0x10
 1107 0591 66736565 		.ascii "fseek\0"
 1107      6B00
 1108 0597 01       		.byte	0x1
 1109 0598 6102     		.word	0x261
 1110 059a 0F       		.byte	0xf
 1111 059b B9020000 		.long	0x2b9
 1112 059f B3050000 		.long	0x5b3
 1113 05a3 0F       		.uleb128 0xf
 1114 05a4 E1030000 		.long	0x3e1
 1115 05a8 0F       		.uleb128 0xf
 1116 05a9 C5020000 		.long	0x2c5
 1117 05ad 0F       		.uleb128 0xf
 1118 05ae B9020000 		.long	0x2b9
 1119 05b2 00       		.byte	0
 1120 05b3 10       		.uleb128 0x10
 1121 05b4 66736574 		.ascii "fsetpos\0"
 1121      706F7300 
 1122 05bc 01       		.byte	0x1
 1123 05bd 5F02     		.word	0x25f
 1124 05bf 0F       		.byte	0xf
 1125 05c0 B9020000 		.long	0x2b9
 1126 05c4 D3050000 		.long	0x5d3
 1127 05c8 0F       		.uleb128 0xf
 1128 05c9 E1030000 		.long	0x3e1
 1129 05cd 0F       		.uleb128 0xf
 1130 05ce D3050000 		.long	0x5d3
 1131 05d2 00       		.byte	0
 1132 05d3 0B       		.uleb128 0xb
 1133 05d4 08       		.byte	0x8
 1134 05d5 C4030000 		.long	0x3c4
 1135 05d9 10       		.uleb128 0x10
 1136 05da 6674656C 		.ascii "ftell\0"
 1136      6C00
 1137 05e0 01       		.byte	0x1
 1138 05e1 6202     		.word	0x262
 1139 05e3 10       		.byte	0x10
 1140 05e4 C5020000 		.long	0x2c5
 1141 05e8 F2050000 		.long	0x5f2
 1142 05ec 0F       		.uleb128 0xf
 1143 05ed E1030000 		.long	0x3e1
 1144 05f1 00       		.byte	0
 1145 05f2 10       		.uleb128 0x10
 1146 05f3 67657463 		.ascii "getc\0"
 1146      00
 1147 05f8 01       		.byte	0x1
 1148 05f9 8F02     		.word	0x28f
 1149 05fb 0F       		.byte	0xf
 1150 05fc B9020000 		.long	0x2b9
 1151 0600 0A060000 		.long	0x60a
 1152 0604 0F       		.uleb128 0xf
 1153 0605 E1030000 		.long	0x3e1
 1154 0609 00       		.byte	0
 1155 060a 14       		.uleb128 0x14
 1156 060b 67657463 		.ascii "getchar\0"
 1156      68617200 
 1157 0613 01       		.byte	0x1
 1158 0614 9002     		.word	0x290
 1159 0616 0F       		.byte	0xf
 1160 0617 B9020000 		.long	0x2b9
 1161 061b 10       		.uleb128 0x10
 1162 061c 67657473 		.ascii "gets\0"
 1162      00
 1163 0621 01       		.byte	0x1
 1164 0622 9202     		.word	0x292
 1165 0624 11       		.byte	0x11
 1166 0625 D1020000 		.long	0x2d1
 1167 0629 33060000 		.long	0x633
 1168 062d 0F       		.uleb128 0xf
 1169 062e D1020000 		.long	0x2d1
 1170 0632 00       		.byte	0
 1171 0633 0E       		.uleb128 0xe
 1172 0634 70657272 		.ascii "perror\0"
 1172      6F7200
 1173 063b 01       		.byte	0x1
 1174 063c 9602     		.word	0x296
 1175 063e 10       		.byte	0x10
 1176 063f 49060000 		.long	0x649
 1177 0643 0F       		.uleb128 0xf
 1178 0644 CD040000 		.long	0x4cd
 1179 0648 00       		.byte	0
 1180 0649 15       		.uleb128 0x15
 1181 064a 7072696E 		.ascii "printf\0"
 1181      746600
 1182 0651 01       		.byte	0x1
 1183 0652 5901     		.word	0x159
 1184 0654 05       		.byte	0x5
 1185 0655 5F5A3670 		.ascii "_Z6printfPKcz\0"
 1185      72696E74 
 1185      66504B63 
 1185      7A00
 1186 0663 B9020000 		.long	0x2b9
 1187 0667 00000000 		.quad	.LFB8
 1187      00000000 
 1188 066f 54000000 		.quad	.LFE8-.LFB8
 1188      00000000 
 1189 0677 01       		.uleb128 0x1
 1190 0678 9C       		.byte	0x9c
 1191 0679 BD060000 		.long	0x6bd
 1192 067d 12       		.uleb128 0x12
 1193 067e 16       		.uleb128 0x16
 1194 067f 19000000 		.secrel32	.LASF2
 1195 0683 01       		.byte	0x1
 1196 0684 5901     		.word	0x159
 1197 0686 19       		.byte	0x19
 1198 0687 CD040000 		.long	0x4cd
 1199 068b 02       		.uleb128 0x2
 1200 068c 91       		.byte	0x91
 1201 068d 00       		.sleb128 0
 1202 068e 12       		.uleb128 0x12
 1203 068f 17       		.uleb128 0x17
 1204 0690 10000000 		.secrel32	.LASF0
 1205 0694 01       		.byte	0x1
 1206 0695 5B01     		.word	0x15b
 1207 0697 07       		.byte	0x7
 1208 0698 B9020000 		.long	0x2b9
 1209 069c 02       		.uleb128 0x2
 1210 069d 91       		.byte	0x91
 1211 069e 5C       		.sleb128 -36
 1212 069f 17       		.uleb128 0x17
 1213 06a0 22000000 		.secrel32	.LASF1
 1214 06a4 01       		.byte	0x1
 1215 06a5 5C01     		.word	0x15c
 1216 06a7 15       		.byte	0x15
 1217 06a8 44020000 		.long	0x244
 1218 06ac 02       		.uleb128 0x2
 1219 06ad 91       		.byte	0x91
 1220 06ae 50       		.sleb128 -48
 1221 06af 18       		.uleb128 0x18
 1222 06b0 38000000 		.quad	.LVL1
 1222      00000000 
 1223 06b8 C10B0000 		.long	0xbc1
 1224 06bc 00       		.byte	0
 1225 06bd 10       		.uleb128 0x10
 1226 06be 72656D6F 		.ascii "remove\0"
 1226      766500
 1227 06c5 01       		.byte	0x1
 1228 06c6 A402     		.word	0x2a4
 1229 06c8 0F       		.byte	0xf
 1230 06c9 B9020000 		.long	0x2b9
 1231 06cd D7060000 		.long	0x6d7
 1232 06d1 0F       		.uleb128 0xf
 1233 06d2 CD040000 		.long	0x4cd
 1234 06d6 00       		.byte	0
 1235 06d7 10       		.uleb128 0x10
 1236 06d8 72656E61 		.ascii "rename\0"
 1236      6D6500
 1237 06df 01       		.byte	0x1
 1238 06e0 A502     		.word	0x2a5
 1239 06e2 0F       		.byte	0xf
 1240 06e3 B9020000 		.long	0x2b9
 1241 06e7 F6060000 		.long	0x6f6
 1242 06eb 0F       		.uleb128 0xf
 1243 06ec CD040000 		.long	0x4cd
 1244 06f0 0F       		.uleb128 0xf
 1245 06f1 CD040000 		.long	0x4cd
 1246 06f5 00       		.byte	0
 1247 06f6 0E       		.uleb128 0xe
 1248 06f7 72657769 		.ascii "rewind\0"
 1248      6E6400
 1249 06fe 01       		.byte	0x1
 1250 06ff AB02     		.word	0x2ab
 1251 0701 10       		.byte	0x10
 1252 0702 0C070000 		.long	0x70c
 1253 0706 0F       		.uleb128 0xf
 1254 0707 E1030000 		.long	0x3e1
 1255 070b 00       		.byte	0
 1256 070c 15       		.uleb128 0x15
 1257 070d 7363616E 		.ascii "scanf\0"
 1257      6600
 1258 0713 01       		.byte	0x1
 1259 0714 1601     		.word	0x116
 1260 0716 05       		.byte	0x5
 1261 0717 5F5A3573 		.ascii "_Z5scanfPKcz\0"
 1261      63616E66 
 1261      504B637A 
 1261      00
 1262 0724 B9020000 		.long	0x2b9
 1263 0728 00000000 		.quad	.LFB2
 1263      00000000 
 1264 0730 54000000 		.quad	.LFE2-.LFB2
 1264      00000000 
 1265 0738 01       		.uleb128 0x1
 1266 0739 9C       		.byte	0x9c
 1267 073a 7E070000 		.long	0x77e
 1268 073e 12       		.uleb128 0x12
 1269 073f 16       		.uleb128 0x16
 1270 0740 19000000 		.secrel32	.LASF2
 1271 0744 01       		.byte	0x1
 1272 0745 1601     		.word	0x116
 1273 0747 17       		.byte	0x17
 1274 0748 CD040000 		.long	0x4cd
 1275 074c 02       		.uleb128 0x2
 1276 074d 91       		.byte	0x91
 1277 074e 00       		.sleb128 0
 1278 074f 12       		.uleb128 0x12
 1279 0750 17       		.uleb128 0x17
 1280 0751 10000000 		.secrel32	.LASF0
 1281 0755 01       		.byte	0x1
 1282 0756 1801     		.word	0x118
 1283 0758 07       		.byte	0x7
 1284 0759 B9020000 		.long	0x2b9
 1285 075d 02       		.uleb128 0x2
 1286 075e 91       		.byte	0x91
 1287 075f 5C       		.sleb128 -36
 1288 0760 17       		.uleb128 0x17
 1289 0761 22000000 		.secrel32	.LASF1
 1290 0765 01       		.byte	0x1
 1291 0766 1901     		.word	0x119
 1292 0768 15       		.byte	0x15
 1293 0769 44020000 		.long	0x244
 1294 076d 02       		.uleb128 0x2
 1295 076e 91       		.byte	0x91
 1296 076f 50       		.sleb128 -48
 1297 0770 18       		.uleb128 0x18
 1298 0771 38000000 		.quad	.LVL0
 1298      00000000 
 1299 0779 C10B0000 		.long	0xbc1
 1300 077d 00       		.byte	0
 1301 077e 0E       		.uleb128 0xe
 1302 077f 73657462 		.ascii "setbuf\0"
 1302      756600
 1303 0786 01       		.byte	0x1
 1304 0787 AD02     		.word	0x2ad
 1305 0789 10       		.byte	0x10
 1306 078a 99070000 		.long	0x799
 1307 078e 0F       		.uleb128 0xf
 1308 078f E1030000 		.long	0x3e1
 1309 0793 0F       		.uleb128 0xf
 1310 0794 D1020000 		.long	0x2d1
 1311 0798 00       		.byte	0
 1312 0799 10       		.uleb128 0x10
 1313 079a 73657476 		.ascii "setvbuf\0"
 1313      62756600 
 1314 07a2 01       		.byte	0x1
 1315 07a3 B102     		.word	0x2b1
 1316 07a5 0F       		.byte	0xf
 1317 07a6 B9020000 		.long	0x2b9
 1318 07aa C3070000 		.long	0x7c3
 1319 07ae 0F       		.uleb128 0xf
 1320 07af E1030000 		.long	0x3e1
 1321 07b3 0F       		.uleb128 0xf
 1322 07b4 D1020000 		.long	0x2d1
 1323 07b8 0F       		.uleb128 0xf
 1324 07b9 B9020000 		.long	0x2b9
 1325 07bd 0F       		.uleb128 0xf
 1326 07be 69020000 		.long	0x269
 1327 07c2 00       		.byte	0
 1328 07c3 11       		.uleb128 0x11
 1329 07c4 73707269 		.ascii "sprintf\0"
 1329      6E746600 
 1330 07cc 01       		.byte	0x1
 1331 07cd 6401     		.word	0x164
 1332 07cf 05       		.byte	0x5
 1333 07d0 5F5A3773 		.ascii "_Z7sprintfPcPKcz\0"
 1333      7072696E 
 1333      74665063 
 1333      504B637A 
 1333      00
 1334 07e1 B9020000 		.long	0x2b9
 1335 07e5 F5070000 		.long	0x7f5
 1336 07e9 0F       		.uleb128 0xf
 1337 07ea D1020000 		.long	0x2d1
 1338 07ee 0F       		.uleb128 0xf
 1339 07ef CD040000 		.long	0x4cd
 1340 07f3 12       		.uleb128 0x12
 1341 07f4 00       		.byte	0
 1342 07f5 11       		.uleb128 0x11
 1343 07f6 73736361 		.ascii "sscanf\0"
 1343      6E6600
 1344 07fd 01       		.byte	0x1
 1345 07fe 0B01     		.word	0x10b
 1346 0800 05       		.byte	0x5
 1347 0801 5F5A3673 		.ascii "_Z6sscanfPKcS0_z\0"
 1347      7363616E 
 1347      66504B63 
 1347      53305F7A 
 1347      00
 1348 0812 B9020000 		.long	0x2b9
 1349 0816 26080000 		.long	0x826
 1350 081a 0F       		.uleb128 0xf
 1351 081b CD040000 		.long	0x4cd
 1352 081f 0F       		.uleb128 0xf
 1353 0820 CD040000 		.long	0x4cd
 1354 0824 12       		.uleb128 0x12
 1355 0825 00       		.byte	0
 1356 0826 14       		.uleb128 0x14
 1357 0827 746D7066 		.ascii "tmpfile\0"
 1357      696C6500 
 1358 082f 01       		.byte	0x1
 1359 0830 CB02     		.word	0x2cb
 1360 0832 11       		.byte	0x11
 1361 0833 E1030000 		.long	0x3e1
 1362 0837 10       		.uleb128 0x10
 1363 0838 746D706E 		.ascii "tmpnam\0"
 1363      616D00
 1364 083f 01       		.byte	0x1
 1365 0840 CC02     		.word	0x2cc
 1366 0842 11       		.byte	0x11
 1367 0843 D1020000 		.long	0x2d1
 1368 0847 51080000 		.long	0x851
 1369 084b 0F       		.uleb128 0xf
 1370 084c D1020000 		.long	0x2d1
 1371 0850 00       		.byte	0
 1372 0851 10       		.uleb128 0x10
 1373 0852 756E6765 		.ascii "ungetc\0"
 1373      746300
 1374 0859 01       		.byte	0x1
 1375 085a CD02     		.word	0x2cd
 1376 085c 0F       		.byte	0xf
 1377 085d B9020000 		.long	0x2b9
 1378 0861 70080000 		.long	0x870
 1379 0865 0F       		.uleb128 0xf
 1380 0866 B9020000 		.long	0x2b9
 1381 086a 0F       		.uleb128 0xf
 1382 086b E1030000 		.long	0x3e1
 1383 086f 00       		.byte	0
 1384 0870 11       		.uleb128 0x11
 1385 0871 76667072 		.ascii "vfprintf\0"
 1385      696E7466 
 1385      00
 1386 087a 01       		.byte	0x1
 1387 087b 6F01     		.word	0x16f
 1388 087d 05       		.byte	0x5
 1389 087e 5F5A3876 		.ascii "_Z8vfprintfP6_iobufPKcPc\0"
 1389      66707269 
 1389      6E746650 
 1389      365F696F 
 1389      62756650 
 1390 0897 B9020000 		.long	0x2b9
 1391 089b AF080000 		.long	0x8af
 1392 089f 0F       		.uleb128 0xf
 1393 08a0 E1030000 		.long	0x3e1
 1394 08a4 0F       		.uleb128 0xf
 1395 08a5 CD040000 		.long	0x4cd
 1396 08a9 0F       		.uleb128 0xf
 1397 08aa 44020000 		.long	0x244
 1398 08ae 00       		.byte	0
 1399 08af 11       		.uleb128 0x11
 1400 08b0 76707269 		.ascii "vprintf\0"
 1400      6E746600 
 1401 08b8 01       		.byte	0x1
 1402 08b9 7601     		.word	0x176
 1403 08bb 05       		.byte	0x5
 1404 08bc 5F5A3776 		.ascii "_Z7vprintfPKcPc\0"
 1404      7072696E 
 1404      7466504B 
 1404      63506300 
 1405 08cc B9020000 		.long	0x2b9
 1406 08d0 DF080000 		.long	0x8df
 1407 08d4 0F       		.uleb128 0xf
 1408 08d5 CD040000 		.long	0x4cd
 1409 08d9 0F       		.uleb128 0xf
 1410 08da 44020000 		.long	0x244
 1411 08de 00       		.byte	0
 1412 08df 11       		.uleb128 0x11
 1413 08e0 76737072 		.ascii "vsprintf\0"
 1413      696E7466 
 1413      00
 1414 08e9 01       		.byte	0x1
 1415 08ea 7D01     		.word	0x17d
 1416 08ec 05       		.byte	0x5
 1417 08ed 5F5A3876 		.ascii "_Z8vsprintfPcPKcS_\0"
 1417      73707269 
 1417      6E746650 
 1417      63504B63 
 1417      535F00
 1418 0900 B9020000 		.long	0x2b9
 1419 0904 18090000 		.long	0x918
 1420 0908 0F       		.uleb128 0xf
 1421 0909 D1020000 		.long	0x2d1
 1422 090d 0F       		.uleb128 0xf
 1423 090e CD040000 		.long	0x4cd
 1424 0912 0F       		.uleb128 0xf
 1425 0913 44020000 		.long	0x244
 1426 0917 00       		.byte	0
 1427 0918 11       		.uleb128 0x11
 1428 0919 736E7072 		.ascii "snprintf\0"
 1428      696E7466 
 1428      00
 1429 0922 01       		.byte	0x1
 1430 0923 8401     		.word	0x184
 1431 0925 05       		.byte	0x5
 1432 0926 5F5A3873 		.ascii "_Z8snprintfPcyPKcz\0"
 1432      6E707269 
 1432      6E746650 
 1432      6379504B 
 1432      637A00
 1433 0939 B9020000 		.long	0x2b9
 1434 093d 52090000 		.long	0x952
 1435 0941 0F       		.uleb128 0xf
 1436 0942 D1020000 		.long	0x2d1
 1437 0946 0F       		.uleb128 0xf
 1438 0947 69020000 		.long	0x269
 1439 094b 0F       		.uleb128 0xf
 1440 094c CD040000 		.long	0x4cd
 1441 0950 12       		.uleb128 0x12
 1442 0951 00       		.byte	0
 1443 0952 11       		.uleb128 0x11
 1444 0953 76667363 		.ascii "vfscanf\0"
 1444      616E6600 
 1445 095b 01       		.byte	0x1
 1446 095c 4001     		.word	0x140
 1447 095e 05       		.byte	0x5
 1448 095f 5F5A3776 		.ascii "_Z7vfscanfP6_iobufPKcPc\0"
 1448      66736361 
 1448      6E665036 
 1448      5F696F62 
 1448      7566504B 
 1449 0977 B9020000 		.long	0x2b9
 1450 097b 8F090000 		.long	0x98f
 1451 097f 0F       		.uleb128 0xf
 1452 0980 E1030000 		.long	0x3e1
 1453 0984 0F       		.uleb128 0xf
 1454 0985 CD040000 		.long	0x4cd
 1455 0989 0F       		.uleb128 0xf
 1456 098a 44020000 		.long	0x244
 1457 098e 00       		.byte	0
 1458 098f 11       		.uleb128 0x11
 1459 0990 76736361 		.ascii "vscanf\0"
 1459      6E6600
 1460 0997 01       		.byte	0x1
 1461 0998 3901     		.word	0x139
 1462 099a 05       		.byte	0x5
 1463 099b 5F5A3676 		.ascii "_Z6vscanfPKcPc\0"
 1463      7363616E 
 1463      66504B63 
 1463      506300
 1464 09aa B9020000 		.long	0x2b9
 1465 09ae BD090000 		.long	0x9bd
 1466 09b2 0F       		.uleb128 0xf
 1467 09b3 CD040000 		.long	0x4cd
 1468 09b7 0F       		.uleb128 0xf
 1469 09b8 44020000 		.long	0x244
 1470 09bc 00       		.byte	0
 1471 09bd 11       		.uleb128 0x11
 1472 09be 76736E70 		.ascii "vsnprintf\0"
 1472      72696E74 
 1472      6600
 1473 09c8 01       		.byte	0x1
 1474 09c9 8F01     		.word	0x18f
 1475 09cb 05       		.byte	0x5
 1476 09cc 5F5A3976 		.ascii "_Z9vsnprintfPcyPKcS_\0"
 1476      736E7072 
 1476      696E7466 
 1476      50637950 
 1476      4B63535F 
 1477 09e1 B9020000 		.long	0x2b9
 1478 09e5 FE090000 		.long	0x9fe
 1479 09e9 0F       		.uleb128 0xf
 1480 09ea D1020000 		.long	0x2d1
 1481 09ee 0F       		.uleb128 0xf
 1482 09ef 69020000 		.long	0x269
 1483 09f3 0F       		.uleb128 0xf
 1484 09f4 CD040000 		.long	0x4cd
 1485 09f8 0F       		.uleb128 0xf
 1486 09f9 44020000 		.long	0x244
 1487 09fd 00       		.byte	0
 1488 09fe 11       		.uleb128 0x11
 1489 09ff 76737363 		.ascii "vsscanf\0"
 1489      616E6600 
 1490 0a07 01       		.byte	0x1
 1491 0a08 3201     		.word	0x132
 1492 0a0a 05       		.byte	0x5
 1493 0a0b 5F5A3776 		.ascii "_Z7vsscanfPKcS0_Pc\0"
 1493      73736361 
 1493      6E66504B 
 1493      6353305F 
 1493      506300
 1494 0a1e B9020000 		.long	0x2b9
 1495 0a22 360A0000 		.long	0xa36
 1496 0a26 0F       		.uleb128 0xf
 1497 0a27 CD040000 		.long	0x4cd
 1498 0a2b 0F       		.uleb128 0xf
 1499 0a2c CD040000 		.long	0x4cd
 1500 0a30 0F       		.uleb128 0xf
 1501 0a31 44020000 		.long	0x244
 1502 0a35 00       		.byte	0
 1503 0a36 19       		.uleb128 0x19
 1504 0a37 4E00     		.ascii "N\0"
 1505 0a39 02       		.byte	0x2
 1506 0a3a 03       		.byte	0x3
 1507 0a3b 0B       		.byte	0xb
 1508 0a3c C0020000 		.long	0x2c0
 1509 0a40 09       		.uleb128 0x9
 1510 0a41 03       		.byte	0x3
 1511 0a42 00000000 		.quad	_ZL1N
 1511      00000000 
 1512 0a4a 1A       		.uleb128 0x1a
 1513 0a4b B9020000 		.long	0x2b9
 1514 0a4f 600A0000 		.long	0xa60
 1515 0a53 1B       		.uleb128 0x1b
 1516 0a54 78020000 		.long	0x278
 1517 0a58 15       		.byte	0x15
 1518 0a59 1B       		.uleb128 0x1b
 1519 0a5a 78020000 		.long	0x278
 1520 0a5e 15       		.byte	0x15
 1521 0a5f 00       		.byte	0
 1522 0a60 1C       		.uleb128 0x1c
 1523 0a61 6600     		.ascii "f\0"
 1524 0a63 02       		.byte	0x2
 1525 0a64 04       		.byte	0x4
 1526 0a65 05       		.byte	0x5
 1527 0a66 4A0A0000 		.long	0xa4a
 1528 0a6a 09       		.uleb128 0x9
 1529 0a6b 03       		.byte	0x3
 1530 0a6c 00000000 		.quad	f
 1530      00000000 
 1531 0a74 1A       		.uleb128 0x1a
 1532 0a75 B9020000 		.long	0x2b9
 1533 0a79 840A0000 		.long	0xa84
 1534 0a7d 1B       		.uleb128 0x1b
 1535 0a7e 78020000 		.long	0x278
 1536 0a82 16       		.byte	0x16
 1537 0a83 00       		.byte	0
 1538 0a84 1C       		.uleb128 0x1c
 1539 0a85 7300     		.ascii "s\0"
 1540 0a87 02       		.byte	0x2
 1541 0a88 04       		.byte	0x4
 1542 0a89 0E       		.byte	0xe
 1543 0a8a 740A0000 		.long	0xa74
 1544 0a8e 09       		.uleb128 0x9
 1545 0a8f 03       		.byte	0x3
 1546 0a90 A0070000 		.quad	s
 1546      00000000 
 1547 0a98 1C       		.uleb128 0x1c
 1548 0a99 6E00     		.ascii "n\0"
 1549 0a9b 02       		.byte	0x2
 1550 0a9c 04       		.byte	0x4
 1551 0a9d 18       		.byte	0x18
 1552 0a9e B9020000 		.long	0x2b9
 1553 0aa2 09       		.uleb128 0x9
 1554 0aa3 03       		.byte	0x3
 1555 0aa4 FC070000 		.quad	n
 1555      00000000 
 1556 0aac 1C       		.uleb128 0x1c
 1557 0aad 616E7300 		.ascii "ans\0"
 1558 0ab1 02       		.byte	0x2
 1559 0ab2 04       		.byte	0x4
 1560 0ab3 1B       		.byte	0x1b
 1561 0ab4 B9020000 		.long	0x2b9
 1562 0ab8 09       		.uleb128 0x9
 1563 0ab9 03       		.byte	0x3
 1564 0aba 00080000 		.quad	ans
 1564      00000000 
 1565 0ac2 1D       		.uleb128 0x1d
 1566 0ac3 6D61696E 		.ascii "main\0"
 1566      00
 1567 0ac8 02       		.byte	0x2
 1568 0ac9 1F       		.byte	0x1f
 1569 0aca 05       		.byte	0x5
 1570 0acb B9020000 		.long	0x2b9
 1571 0acf 5D020000 		.quad	.LFB45
 1571      00000000 
 1572 0ad7 FA000000 		.quad	.LFE45-.LFB45
 1572      00000000 
 1573 0adf 01       		.uleb128 0x1
 1574 0ae0 9C       		.byte	0x9c
 1575 0ae1 230B0000 		.long	0xb23
 1576 0ae5 1E       		.uleb128 0x1e
 1577 0ae6 F1020000 		.quad	.LBB12
 1577      00000000 
 1578 0aee 3D000000 		.quad	.LBE12-.LBB12
 1578      00000000 
 1579 0af6 080B0000 		.long	0xb08
 1580 0afa 19       		.uleb128 0x19
 1581 0afb 6900     		.ascii "i\0"
 1582 0afd 02       		.byte	0x2
 1583 0afe 29       		.byte	0x29
 1584 0aff 0B       		.byte	0xb
 1585 0b00 B9020000 		.long	0x2b9
 1586 0b04 02       		.uleb128 0x2
 1587 0b05 91       		.byte	0x91
 1588 0b06 6C       		.sleb128 -20
 1589 0b07 00       		.byte	0
 1590 0b08 18       		.uleb128 0x18
 1591 0b09 78020000 		.quad	.LVL3
 1591      00000000 
 1592 0b11 C10B0000 		.long	0xbc1
 1593 0b15 18       		.uleb128 0x18
 1594 0b16 9C020000 		.quad	.LVL4
 1594      00000000 
 1595 0b1e C10B0000 		.long	0xbc1
 1596 0b22 00       		.byte	0
 1597 0b23 1F       		.uleb128 0x1f
 1598 0b24 64667300 		.ascii "dfs\0"
 1599 0b28 02       		.byte	0x2
 1600 0b29 06       		.byte	0x6
 1601 0b2a 06       		.byte	0x6
 1602 0b2b 5F5A3364 		.ascii "_Z3dfsi\0"
 1602      66736900 
 1603 0b33 00000000 		.quad	.LFB44
 1603      00000000 
 1604 0b3b 5D020000 		.quad	.LFE44-.LFB44
 1604      00000000 
 1605 0b43 01       		.uleb128 0x1
 1606 0b44 9C       		.byte	0x9c
 1607 0b45 C10B0000 		.long	0xbc1
 1608 0b49 20       		.uleb128 0x20
 1609 0b4a 6B00     		.ascii "k\0"
 1610 0b4c 02       		.byte	0x2
 1611 0b4d 06       		.byte	0x6
 1612 0b4e 0E       		.byte	0xe
 1613 0b4f B9020000 		.long	0x2b9
 1614 0b53 02       		.uleb128 0x2
 1615 0b54 91       		.byte	0x91
 1616 0b55 00       		.sleb128 0
 1617 0b56 21       		.uleb128 0x21
 1618 0b57 00000000 		.secrel32	.Ldebug_ranges0+0
 1619 0b5b 19       		.uleb128 0x19
 1620 0b5c 746D7000 		.ascii "tmp\0"
 1621 0b60 02       		.byte	0x2
 1622 0b61 0A       		.byte	0xa
 1623 0b62 07       		.byte	0x7
 1624 0b63 B9020000 		.long	0x2b9
 1625 0b67 02       		.uleb128 0x2
 1626 0b68 91       		.byte	0x91
 1627 0b69 6C       		.sleb128 -20
 1628 0b6a 1E       		.uleb128 0x1e
 1629 0b6b 21000000 		.quad	.LBB4
 1629      00000000 
 1630 0b73 42000000 		.quad	.LBE4-.LBB4
 1630      00000000 
 1631 0b7b 8D0B0000 		.long	0xb8d
 1632 0b7f 19       		.uleb128 0x19
 1633 0b80 6A00     		.ascii "j\0"
 1634 0b82 02       		.byte	0x2
 1635 0b83 0B       		.byte	0xb
 1636 0b84 0C       		.byte	0xc
 1637 0b85 B9020000 		.long	0x2b9
 1638 0b89 02       		.uleb128 0x2
 1639 0b8a 91       		.byte	0x91
 1640 0b8b 68       		.sleb128 -24
 1641 0b8c 00       		.byte	0
 1642 0b8d 21       		.uleb128 0x21
 1643 0b8e 30000000 		.secrel32	.Ldebug_ranges0+0x30
 1644 0b92 19       		.uleb128 0x19
 1645 0b93 6900     		.ascii "i\0"
 1646 0b95 02       		.byte	0x2
 1647 0b96 0D       		.byte	0xd
 1648 0b97 0C       		.byte	0xc
 1649 0b98 B9020000 		.long	0x2b9
 1650 0b9c 02       		.uleb128 0x2
 1651 0b9d 91       		.byte	0x91
 1652 0b9e 64       		.sleb128 -28
 1653 0b9f 22       		.uleb128 0x22
 1654 0ba0 C7000000 		.quad	.LBB7
 1654      00000000 
 1655 0ba8 D0000000 		.quad	.LBE7-.LBB7
 1655      00000000 
 1656 0bb0 19       		.uleb128 0x19
 1657 0bb1 6A00     		.ascii "j\0"
 1658 0bb3 02       		.byte	0x2
 1659 0bb4 0F       		.byte	0xf
 1660 0bb5 0D       		.byte	0xd
 1661 0bb6 B9020000 		.long	0x2b9
 1662 0bba 02       		.uleb128 0x2
 1663 0bbb 91       		.byte	0x91
 1664 0bbc 60       		.sleb128 -32
 1665 0bbd 00       		.byte	0
 1666 0bbe 00       		.byte	0
 1667 0bbf 00       		.byte	0
 1668 0bc0 00       		.byte	0
 1669 0bc1 23       		.uleb128 0x23
 1670 0bc2 00000000 		.secrel32	.LASF3
 1671 0bc6 00000000 		.secrel32	.LASF3
 1672 0bca 01       		.byte	0x1
 1673 0bcb 52       		.byte	0x52
 1674 0bcc 17       		.byte	0x17
 1675 0bcd 00       		.byte	0
 1676              		.section	.debug_abbrev,"dr"
 1677              	.Ldebug_abbrev0:
 1678 0000 01       		.uleb128 0x1
 1679 0001 11       		.uleb128 0x11
 1680 0002 01       		.byte	0x1
 1681 0003 25       		.uleb128 0x25
 1682 0004 08       		.uleb128 0x8
 1683 0005 13       		.uleb128 0x13
 1684 0006 0B       		.uleb128 0xb
 1685 0007 03       		.uleb128 0x3
 1686 0008 08       		.uleb128 0x8
 1687 0009 1B       		.uleb128 0x1b
 1688 000a 08       		.uleb128 0x8
 1689 000b 55       		.uleb128 0x55
 1690 000c 17       		.uleb128 0x17
 1691 000d 11       		.uleb128 0x11
 1692 000e 01       		.uleb128 0x1
 1693 000f 10       		.uleb128 0x10
 1694 0010 17       		.uleb128 0x17
 1695 0011 00       		.byte	0
 1696 0012 00       		.byte	0
 1697 0013 02       		.uleb128 0x2
 1698 0014 39       		.uleb128 0x39
 1699 0015 01       		.byte	0x1
 1700 0016 03       		.uleb128 0x3
 1701 0017 08       		.uleb128 0x8
 1702 0018 3A       		.uleb128 0x3a
 1703 0019 0B       		.uleb128 0xb
 1704 001a 3B       		.uleb128 0x3b
 1705 001b 0B       		.uleb128 0xb
 1706 001c 01       		.uleb128 0x1
 1707 001d 13       		.uleb128 0x13
 1708 001e 00       		.byte	0
 1709 001f 00       		.byte	0
 1710 0020 03       		.uleb128 0x3
 1711 0021 39       		.uleb128 0x39
 1712 0022 00       		.byte	0
 1713 0023 03       		.uleb128 0x3
 1714 0024 08       		.uleb128 0x8
 1715 0025 3A       		.uleb128 0x3a
 1716 0026 0B       		.uleb128 0xb
 1717 0027 3B       		.uleb128 0x3b
 1718 0028 05       		.uleb128 0x5
 1719 0029 39       		.uleb128 0x39
 1720 002a 0B       		.uleb128 0xb
 1721 002b 8901     		.uleb128 0x89
 1722 002d 19       		.uleb128 0x19
 1723 002e 00       		.byte	0
 1724 002f 00       		.byte	0
 1725 0030 04       		.uleb128 0x4
 1726 0031 3A       		.uleb128 0x3a
 1727 0032 00       		.byte	0
 1728 0033 3A       		.uleb128 0x3a
 1729 0034 0B       		.uleb128 0xb
 1730 0035 3B       		.uleb128 0x3b
 1731 0036 05       		.uleb128 0x5
 1732 0037 39       		.uleb128 0x39
 1733 0038 0B       		.uleb128 0xb
 1734 0039 18       		.uleb128 0x18
 1735 003a 13       		.uleb128 0x13
 1736 003b 00       		.byte	0
 1737 003c 00       		.byte	0
 1738 003d 05       		.uleb128 0x5
 1739 003e 08       		.uleb128 0x8
 1740 003f 00       		.byte	0
 1741 0040 3A       		.uleb128 0x3a
 1742 0041 0B       		.uleb128 0xb
 1743 0042 3B       		.uleb128 0x3b
 1744 0043 0B       		.uleb128 0xb
 1745 0044 39       		.uleb128 0x39
 1746 0045 0B       		.uleb128 0xb
 1747 0046 18       		.uleb128 0x18
 1748 0047 13       		.uleb128 0x13
 1749 0048 00       		.byte	0
 1750 0049 00       		.byte	0
 1751 004a 06       		.uleb128 0x6
 1752 004b 39       		.uleb128 0x39
 1753 004c 01       		.byte	0x1
 1754 004d 03       		.uleb128 0x3
 1755 004e 08       		.uleb128 0x8
 1756 004f 3A       		.uleb128 0x3a
 1757 0050 0B       		.uleb128 0xb
 1758 0051 3B       		.uleb128 0x3b
 1759 0052 05       		.uleb128 0x5
 1760 0053 39       		.uleb128 0x39
 1761 0054 0B       		.uleb128 0xb
 1762 0055 01       		.uleb128 0x1
 1763 0056 13       		.uleb128 0x13
 1764 0057 00       		.byte	0
 1765 0058 00       		.byte	0
 1766 0059 07       		.uleb128 0x7
 1767 005a 0F       		.uleb128 0xf
 1768 005b 00       		.byte	0
 1769 005c 0B       		.uleb128 0xb
 1770 005d 0B       		.uleb128 0xb
 1771 005e 03       		.uleb128 0x3
 1772 005f 08       		.uleb128 0x8
 1773 0060 49       		.uleb128 0x49
 1774 0061 13       		.uleb128 0x13
 1775 0062 00       		.byte	0
 1776 0063 00       		.byte	0
 1777 0064 08       		.uleb128 0x8
 1778 0065 24       		.uleb128 0x24
 1779 0066 00       		.byte	0
 1780 0067 0B       		.uleb128 0xb
 1781 0068 0B       		.uleb128 0xb
 1782 0069 3E       		.uleb128 0x3e
 1783 006a 0B       		.uleb128 0xb
 1784 006b 03       		.uleb128 0x3
 1785 006c 08       		.uleb128 0x8
 1786 006d 00       		.byte	0
 1787 006e 00       		.byte	0
 1788 006f 09       		.uleb128 0x9
 1789 0070 26       		.uleb128 0x26
 1790 0071 00       		.byte	0
 1791 0072 49       		.uleb128 0x49
 1792 0073 13       		.uleb128 0x13
 1793 0074 00       		.byte	0
 1794 0075 00       		.byte	0
 1795 0076 0A       		.uleb128 0xa
 1796 0077 16       		.uleb128 0x16
 1797 0078 00       		.byte	0
 1798 0079 03       		.uleb128 0x3
 1799 007a 08       		.uleb128 0x8
 1800 007b 3A       		.uleb128 0x3a
 1801 007c 0B       		.uleb128 0xb
 1802 007d 3B       		.uleb128 0x3b
 1803 007e 0B       		.uleb128 0xb
 1804 007f 39       		.uleb128 0x39
 1805 0080 0B       		.uleb128 0xb
 1806 0081 49       		.uleb128 0x49
 1807 0082 13       		.uleb128 0x13
 1808 0083 00       		.byte	0
 1809 0084 00       		.byte	0
 1810 0085 0B       		.uleb128 0xb
 1811 0086 0F       		.uleb128 0xf
 1812 0087 00       		.byte	0
 1813 0088 0B       		.uleb128 0xb
 1814 0089 0B       		.uleb128 0xb
 1815 008a 49       		.uleb128 0x49
 1816 008b 13       		.uleb128 0x13
 1817 008c 00       		.byte	0
 1818 008d 00       		.byte	0
 1819 008e 0C       		.uleb128 0xc
 1820 008f 13       		.uleb128 0x13
 1821 0090 01       		.byte	0x1
 1822 0091 03       		.uleb128 0x3
 1823 0092 08       		.uleb128 0x8
 1824 0093 0B       		.uleb128 0xb
 1825 0094 0B       		.uleb128 0xb
 1826 0095 3A       		.uleb128 0x3a
 1827 0096 0B       		.uleb128 0xb
 1828 0097 3B       		.uleb128 0x3b
 1829 0098 0B       		.uleb128 0xb
 1830 0099 39       		.uleb128 0x39
 1831 009a 0B       		.uleb128 0xb
 1832 009b 01       		.uleb128 0x1
 1833 009c 13       		.uleb128 0x13
 1834 009d 00       		.byte	0
 1835 009e 00       		.byte	0
 1836 009f 0D       		.uleb128 0xd
 1837 00a0 0D       		.uleb128 0xd
 1838 00a1 00       		.byte	0
 1839 00a2 03       		.uleb128 0x3
 1840 00a3 08       		.uleb128 0x8
 1841 00a4 3A       		.uleb128 0x3a
 1842 00a5 0B       		.uleb128 0xb
 1843 00a6 3B       		.uleb128 0x3b
 1844 00a7 0B       		.uleb128 0xb
 1845 00a8 39       		.uleb128 0x39
 1846 00a9 0B       		.uleb128 0xb
 1847 00aa 49       		.uleb128 0x49
 1848 00ab 13       		.uleb128 0x13
 1849 00ac 38       		.uleb128 0x38
 1850 00ad 0B       		.uleb128 0xb
 1851 00ae 00       		.byte	0
 1852 00af 00       		.byte	0
 1853 00b0 0E       		.uleb128 0xe
 1854 00b1 2E       		.uleb128 0x2e
 1855 00b2 01       		.byte	0x1
 1856 00b3 3F       		.uleb128 0x3f
 1857 00b4 19       		.uleb128 0x19
 1858 00b5 03       		.uleb128 0x3
 1859 00b6 08       		.uleb128 0x8
 1860 00b7 3A       		.uleb128 0x3a
 1861 00b8 0B       		.uleb128 0xb
 1862 00b9 3B       		.uleb128 0x3b
 1863 00ba 05       		.uleb128 0x5
 1864 00bb 39       		.uleb128 0x39
 1865 00bc 0B       		.uleb128 0xb
 1866 00bd 3C       		.uleb128 0x3c
 1867 00be 19       		.uleb128 0x19
 1868 00bf 01       		.uleb128 0x1
 1869 00c0 13       		.uleb128 0x13
 1870 00c1 00       		.byte	0
 1871 00c2 00       		.byte	0
 1872 00c3 0F       		.uleb128 0xf
 1873 00c4 05       		.uleb128 0x5
 1874 00c5 00       		.byte	0
 1875 00c6 49       		.uleb128 0x49
 1876 00c7 13       		.uleb128 0x13
 1877 00c8 00       		.byte	0
 1878 00c9 00       		.byte	0
 1879 00ca 10       		.uleb128 0x10
 1880 00cb 2E       		.uleb128 0x2e
 1881 00cc 01       		.byte	0x1
 1882 00cd 3F       		.uleb128 0x3f
 1883 00ce 19       		.uleb128 0x19
 1884 00cf 03       		.uleb128 0x3
 1885 00d0 08       		.uleb128 0x8
 1886 00d1 3A       		.uleb128 0x3a
 1887 00d2 0B       		.uleb128 0xb
 1888 00d3 3B       		.uleb128 0x3b
 1889 00d4 05       		.uleb128 0x5
 1890 00d5 39       		.uleb128 0x39
 1891 00d6 0B       		.uleb128 0xb
 1892 00d7 49       		.uleb128 0x49
 1893 00d8 13       		.uleb128 0x13
 1894 00d9 3C       		.uleb128 0x3c
 1895 00da 19       		.uleb128 0x19
 1896 00db 01       		.uleb128 0x1
 1897 00dc 13       		.uleb128 0x13
 1898 00dd 00       		.byte	0
 1899 00de 00       		.byte	0
 1900 00df 11       		.uleb128 0x11
 1901 00e0 2E       		.uleb128 0x2e
 1902 00e1 01       		.byte	0x1
 1903 00e2 3F       		.uleb128 0x3f
 1904 00e3 19       		.uleb128 0x19
 1905 00e4 03       		.uleb128 0x3
 1906 00e5 08       		.uleb128 0x8
 1907 00e6 3A       		.uleb128 0x3a
 1908 00e7 0B       		.uleb128 0xb
 1909 00e8 3B       		.uleb128 0x3b
 1910 00e9 05       		.uleb128 0x5
 1911 00ea 39       		.uleb128 0x39
 1912 00eb 0B       		.uleb128 0xb
 1913 00ec 6E       		.uleb128 0x6e
 1914 00ed 08       		.uleb128 0x8
 1915 00ee 49       		.uleb128 0x49
 1916 00ef 13       		.uleb128 0x13
 1917 00f0 3C       		.uleb128 0x3c
 1918 00f1 19       		.uleb128 0x19
 1919 00f2 01       		.uleb128 0x1
 1920 00f3 13       		.uleb128 0x13
 1921 00f4 00       		.byte	0
 1922 00f5 00       		.byte	0
 1923 00f6 12       		.uleb128 0x12
 1924 00f7 18       		.uleb128 0x18
 1925 00f8 00       		.byte	0
 1926 00f9 00       		.byte	0
 1927 00fa 00       		.byte	0
 1928 00fb 13       		.uleb128 0x13
 1929 00fc 0F       		.uleb128 0xf
 1930 00fd 00       		.byte	0
 1931 00fe 0B       		.uleb128 0xb
 1932 00ff 0B       		.uleb128 0xb
 1933 0100 00       		.byte	0
 1934 0101 00       		.byte	0
 1935 0102 14       		.uleb128 0x14
 1936 0103 2E       		.uleb128 0x2e
 1937 0104 00       		.byte	0
 1938 0105 3F       		.uleb128 0x3f
 1939 0106 19       		.uleb128 0x19
 1940 0107 03       		.uleb128 0x3
 1941 0108 08       		.uleb128 0x8
 1942 0109 3A       		.uleb128 0x3a
 1943 010a 0B       		.uleb128 0xb
 1944 010b 3B       		.uleb128 0x3b
 1945 010c 05       		.uleb128 0x5
 1946 010d 39       		.uleb128 0x39
 1947 010e 0B       		.uleb128 0xb
 1948 010f 49       		.uleb128 0x49
 1949 0110 13       		.uleb128 0x13
 1950 0111 3C       		.uleb128 0x3c
 1951 0112 19       		.uleb128 0x19
 1952 0113 00       		.byte	0
 1953 0114 00       		.byte	0
 1954 0115 15       		.uleb128 0x15
 1955 0116 2E       		.uleb128 0x2e
 1956 0117 01       		.byte	0x1
 1957 0118 3F       		.uleb128 0x3f
 1958 0119 19       		.uleb128 0x19
 1959 011a 03       		.uleb128 0x3
 1960 011b 08       		.uleb128 0x8
 1961 011c 3A       		.uleb128 0x3a
 1962 011d 0B       		.uleb128 0xb
 1963 011e 3B       		.uleb128 0x3b
 1964 011f 05       		.uleb128 0x5
 1965 0120 39       		.uleb128 0x39
 1966 0121 0B       		.uleb128 0xb
 1967 0122 6E       		.uleb128 0x6e
 1968 0123 08       		.uleb128 0x8
 1969 0124 49       		.uleb128 0x49
 1970 0125 13       		.uleb128 0x13
 1971 0126 11       		.uleb128 0x11
 1972 0127 01       		.uleb128 0x1
 1973 0128 12       		.uleb128 0x12
 1974 0129 07       		.uleb128 0x7
 1975 012a 40       		.uleb128 0x40
 1976 012b 18       		.uleb128 0x18
 1977 012c 9642     		.uleb128 0x2116
 1978 012e 19       		.uleb128 0x19
 1979 012f 01       		.uleb128 0x1
 1980 0130 13       		.uleb128 0x13
 1981 0131 00       		.byte	0
 1982 0132 00       		.byte	0
 1983 0133 16       		.uleb128 0x16
 1984 0134 05       		.uleb128 0x5
 1985 0135 00       		.byte	0
 1986 0136 03       		.uleb128 0x3
 1987 0137 0E       		.uleb128 0xe
 1988 0138 3A       		.uleb128 0x3a
 1989 0139 0B       		.uleb128 0xb
 1990 013a 3B       		.uleb128 0x3b
 1991 013b 05       		.uleb128 0x5
 1992 013c 39       		.uleb128 0x39
 1993 013d 0B       		.uleb128 0xb
 1994 013e 49       		.uleb128 0x49
 1995 013f 13       		.uleb128 0x13
 1996 0140 02       		.uleb128 0x2
 1997 0141 18       		.uleb128 0x18
 1998 0142 00       		.byte	0
 1999 0143 00       		.byte	0
 2000 0144 17       		.uleb128 0x17
 2001 0145 34       		.uleb128 0x34
 2002 0146 00       		.byte	0
 2003 0147 03       		.uleb128 0x3
 2004 0148 0E       		.uleb128 0xe
 2005 0149 3A       		.uleb128 0x3a
 2006 014a 0B       		.uleb128 0xb
 2007 014b 3B       		.uleb128 0x3b
 2008 014c 05       		.uleb128 0x5
 2009 014d 39       		.uleb128 0x39
 2010 014e 0B       		.uleb128 0xb
 2011 014f 49       		.uleb128 0x49
 2012 0150 13       		.uleb128 0x13
 2013 0151 02       		.uleb128 0x2
 2014 0152 18       		.uleb128 0x18
 2015 0153 00       		.byte	0
 2016 0154 00       		.byte	0
 2017 0155 18       		.uleb128 0x18
 2018 0156 898201   		.uleb128 0x4109
 2019 0159 00       		.byte	0
 2020 015a 11       		.uleb128 0x11
 2021 015b 01       		.uleb128 0x1
 2022 015c 31       		.uleb128 0x31
 2023 015d 13       		.uleb128 0x13
 2024 015e 00       		.byte	0
 2025 015f 00       		.byte	0
 2026 0160 19       		.uleb128 0x19
 2027 0161 34       		.uleb128 0x34
 2028 0162 00       		.byte	0
 2029 0163 03       		.uleb128 0x3
 2030 0164 08       		.uleb128 0x8
 2031 0165 3A       		.uleb128 0x3a
 2032 0166 0B       		.uleb128 0xb
 2033 0167 3B       		.uleb128 0x3b
 2034 0168 0B       		.uleb128 0xb
 2035 0169 39       		.uleb128 0x39
 2036 016a 0B       		.uleb128 0xb
 2037 016b 49       		.uleb128 0x49
 2038 016c 13       		.uleb128 0x13
 2039 016d 02       		.uleb128 0x2
 2040 016e 18       		.uleb128 0x18
 2041 016f 00       		.byte	0
 2042 0170 00       		.byte	0
 2043 0171 1A       		.uleb128 0x1a
 2044 0172 01       		.uleb128 0x1
 2045 0173 01       		.byte	0x1
 2046 0174 49       		.uleb128 0x49
 2047 0175 13       		.uleb128 0x13
 2048 0176 01       		.uleb128 0x1
 2049 0177 13       		.uleb128 0x13
 2050 0178 00       		.byte	0
 2051 0179 00       		.byte	0
 2052 017a 1B       		.uleb128 0x1b
 2053 017b 21       		.uleb128 0x21
 2054 017c 00       		.byte	0
 2055 017d 49       		.uleb128 0x49
 2056 017e 13       		.uleb128 0x13
 2057 017f 2F       		.uleb128 0x2f
 2058 0180 0B       		.uleb128 0xb
 2059 0181 00       		.byte	0
 2060 0182 00       		.byte	0
 2061 0183 1C       		.uleb128 0x1c
 2062 0184 34       		.uleb128 0x34
 2063 0185 00       		.byte	0
 2064 0186 03       		.uleb128 0x3
 2065 0187 08       		.uleb128 0x8
 2066 0188 3A       		.uleb128 0x3a
 2067 0189 0B       		.uleb128 0xb
 2068 018a 3B       		.uleb128 0x3b
 2069 018b 0B       		.uleb128 0xb
 2070 018c 39       		.uleb128 0x39
 2071 018d 0B       		.uleb128 0xb
 2072 018e 49       		.uleb128 0x49
 2073 018f 13       		.uleb128 0x13
 2074 0190 3F       		.uleb128 0x3f
 2075 0191 19       		.uleb128 0x19
 2076 0192 02       		.uleb128 0x2
 2077 0193 18       		.uleb128 0x18
 2078 0194 00       		.byte	0
 2079 0195 00       		.byte	0
 2080 0196 1D       		.uleb128 0x1d
 2081 0197 2E       		.uleb128 0x2e
 2082 0198 01       		.byte	0x1
 2083 0199 3F       		.uleb128 0x3f
 2084 019a 19       		.uleb128 0x19
 2085 019b 03       		.uleb128 0x3
 2086 019c 08       		.uleb128 0x8
 2087 019d 3A       		.uleb128 0x3a
 2088 019e 0B       		.uleb128 0xb
 2089 019f 3B       		.uleb128 0x3b
 2090 01a0 0B       		.uleb128 0xb
 2091 01a1 39       		.uleb128 0x39
 2092 01a2 0B       		.uleb128 0xb
 2093 01a3 49       		.uleb128 0x49
 2094 01a4 13       		.uleb128 0x13
 2095 01a5 11       		.uleb128 0x11
 2096 01a6 01       		.uleb128 0x1
 2097 01a7 12       		.uleb128 0x12
 2098 01a8 07       		.uleb128 0x7
 2099 01a9 40       		.uleb128 0x40
 2100 01aa 18       		.uleb128 0x18
 2101 01ab 9642     		.uleb128 0x2116
 2102 01ad 19       		.uleb128 0x19
 2103 01ae 01       		.uleb128 0x1
 2104 01af 13       		.uleb128 0x13
 2105 01b0 00       		.byte	0
 2106 01b1 00       		.byte	0
 2107 01b2 1E       		.uleb128 0x1e
 2108 01b3 0B       		.uleb128 0xb
 2109 01b4 01       		.byte	0x1
 2110 01b5 11       		.uleb128 0x11
 2111 01b6 01       		.uleb128 0x1
 2112 01b7 12       		.uleb128 0x12
 2113 01b8 07       		.uleb128 0x7
 2114 01b9 01       		.uleb128 0x1
 2115 01ba 13       		.uleb128 0x13
 2116 01bb 00       		.byte	0
 2117 01bc 00       		.byte	0
 2118 01bd 1F       		.uleb128 0x1f
 2119 01be 2E       		.uleb128 0x2e
 2120 01bf 01       		.byte	0x1
 2121 01c0 3F       		.uleb128 0x3f
 2122 01c1 19       		.uleb128 0x19
 2123 01c2 03       		.uleb128 0x3
 2124 01c3 08       		.uleb128 0x8
 2125 01c4 3A       		.uleb128 0x3a
 2126 01c5 0B       		.uleb128 0xb
 2127 01c6 3B       		.uleb128 0x3b
 2128 01c7 0B       		.uleb128 0xb
 2129 01c8 39       		.uleb128 0x39
 2130 01c9 0B       		.uleb128 0xb
 2131 01ca 6E       		.uleb128 0x6e
 2132 01cb 08       		.uleb128 0x8
 2133 01cc 11       		.uleb128 0x11
 2134 01cd 01       		.uleb128 0x1
 2135 01ce 12       		.uleb128 0x12
 2136 01cf 07       		.uleb128 0x7
 2137 01d0 40       		.uleb128 0x40
 2138 01d1 18       		.uleb128 0x18
 2139 01d2 9642     		.uleb128 0x2116
 2140 01d4 19       		.uleb128 0x19
 2141 01d5 01       		.uleb128 0x1
 2142 01d6 13       		.uleb128 0x13
 2143 01d7 00       		.byte	0
 2144 01d8 00       		.byte	0
 2145 01d9 20       		.uleb128 0x20
 2146 01da 05       		.uleb128 0x5
 2147 01db 00       		.byte	0
 2148 01dc 03       		.uleb128 0x3
 2149 01dd 08       		.uleb128 0x8
 2150 01de 3A       		.uleb128 0x3a
 2151 01df 0B       		.uleb128 0xb
 2152 01e0 3B       		.uleb128 0x3b
 2153 01e1 0B       		.uleb128 0xb
 2154 01e2 39       		.uleb128 0x39
 2155 01e3 0B       		.uleb128 0xb
 2156 01e4 49       		.uleb128 0x49
 2157 01e5 13       		.uleb128 0x13
 2158 01e6 02       		.uleb128 0x2
 2159 01e7 18       		.uleb128 0x18
 2160 01e8 00       		.byte	0
 2161 01e9 00       		.byte	0
 2162 01ea 21       		.uleb128 0x21
 2163 01eb 0B       		.uleb128 0xb
 2164 01ec 01       		.byte	0x1
 2165 01ed 55       		.uleb128 0x55
 2166 01ee 17       		.uleb128 0x17
 2167 01ef 00       		.byte	0
 2168 01f0 00       		.byte	0
 2169 01f1 22       		.uleb128 0x22
 2170 01f2 0B       		.uleb128 0xb
 2171 01f3 01       		.byte	0x1
 2172 01f4 11       		.uleb128 0x11
 2173 01f5 01       		.uleb128 0x1
 2174 01f6 12       		.uleb128 0x12
 2175 01f7 07       		.uleb128 0x7
 2176 01f8 00       		.byte	0
 2177 01f9 00       		.byte	0
 2178 01fa 23       		.uleb128 0x23
 2179 01fb 2E       		.uleb128 0x2e
 2180 01fc 00       		.byte	0
 2181 01fd 3F       		.uleb128 0x3f
 2182 01fe 19       		.uleb128 0x19
 2183 01ff 3C       		.uleb128 0x3c
 2184 0200 19       		.uleb128 0x19
 2185 0201 6E       		.uleb128 0x6e
 2186 0202 0E       		.uleb128 0xe
 2187 0203 03       		.uleb128 0x3
 2188 0204 0E       		.uleb128 0xe
 2189 0205 3A       		.uleb128 0x3a
 2190 0206 0B       		.uleb128 0xb
 2191 0207 3B       		.uleb128 0x3b
 2192 0208 0B       		.uleb128 0xb
 2193 0209 39       		.uleb128 0x39
 2194 020a 0B       		.uleb128 0xb
 2195 020b 00       		.byte	0
 2196 020c 00       		.byte	0
 2197 020d 00       		.byte	0
 2198              		.section	.debug_aranges,"dr"
 2199 0000 4C000000 		.long	0x4c
 2200 0004 0200     		.word	0x2
 2201 0006 00000000 		.secrel32	.Ldebug_info0
 2202 000a 08       		.byte	0x8
 2203 000b 00       		.byte	0
 2204 000c 0000     		.word	0
 2205 000e 0000     		.word	0
 2206 0010 00000000 		.quad	.Ltext0
 2206      00000000 
 2207 0018 57030000 		.quad	.Letext0-.Ltext0
 2207      00000000 
 2208 0020 00000000 		.quad	.LFB2
 2208      00000000 
 2209 0028 54000000 		.quad	.LFE2-.LFB2
 2209      00000000 
 2210 0030 00000000 		.quad	.LFB8
 2210      00000000 
 2211 0038 54000000 		.quad	.LFE8-.LFB8
 2211      00000000 
 2212 0040 00000000 		.quad	0
 2212      00000000 
 2213 0048 00000000 		.quad	0
 2213      00000000 
 2214              		.section	.debug_ranges,"dr"
 2215              	.Ldebug_ranges0:
 2216 0000 1A000000 		.quad	.LBB3
 2216      00000000 
 2217 0008 01020000 		.quad	.LBE3
 2217      00000000 
 2218 0010 53020000 		.quad	.LBB10
 2218      00000000 
 2219 0018 57020000 		.quad	.LBE10
 2219      00000000 
 2220 0020 00000000 		.quad	0
 2220      00000000 
 2221 0028 00000000 		.quad	0
 2221      00000000 
 2222 0030 B1000000 		.quad	.LBB5
 2222      00000000 
 2223 0038 F0010000 		.quad	.LBE5
 2223      00000000 
 2224 0040 56020000 		.quad	.LBB9
 2224      00000000 
 2225 0048 57020000 		.quad	.LBE9
 2225      00000000 
 2226 0050 00000000 		.quad	0
 2226      00000000 
 2227 0058 00000000 		.quad	0
 2227      00000000 
 2228 0060 00000000 		.quad	.Ltext0
 2228      00000000 
 2229 0068 57030000 		.quad	.Letext0
 2229      00000000 
 2230 0070 00000000 		.quad	.LFB2
 2230      00000000 
 2231 0078 54000000 		.quad	.LFE2
 2231      00000000 
 2232 0080 00000000 		.quad	.LFB8
 2232      00000000 
 2233 0088 54000000 		.quad	.LFE8
 2233      00000000 
 2234 0090 00000000 		.quad	0
 2234      00000000 
 2235 0098 00000000 		.quad	0
 2235      00000000 
 2236              		.section	.debug_line,"dr"
 2237              	.Ldebug_line0:
 2238 0000 9F030000 		.section	.debug_str,"dr"
 2238      0200CD01 
 2238      00000101 
 2238      FB0E0D00 
 2238      01010101 
 2239              	.LASF3:
 2240 0000 5F5F6163 		.ascii "__acrt_iob_func\0"
 2240      72745F69 
 2240      6F625F66 
 2240      756E6300 
 2241              	.LASF0:
 2242 0010 5F5F7265 		.ascii "__retval\0"
 2242      7476616C 
 2242      00
 2243              	.LASF2:
 2244 0019 5F5F666F 		.ascii "__format\0"
 2244      726D6174 
 2244      00
 2245              	.LASF1:
 2246 0022 5F5F6C6F 		.ascii "__local_argv\0"
 2246      63616C5F 
 2246      61726776 
 2246      00
 2247              		.ident	"GCC: (x86_64-win32-seh-rev0, Built by MinGW-W64 project) 8.1.0"
