   1              		.file	"\277\354\266\301.cpp"
   2              		.text
   3              	.Ltext0:
   4              		.cfi_sections	.debug_frame
   5              		.section	.text$_Z6printfPKcz,"x"
   6              		.linkonce discard
   7              		.globl	_Z6printfPKcz
   9              		.seh_proc	_Z6printfPKcz
  10              	_Z6printfPKcz:
  11              	.LFB8:
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
 280:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   int __retval;
 281:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
 282:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   __retval = __mingw_vfscanf( stdin, __format, __local_argv );
 283:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   __builtin_va_end( __local_argv );
 284:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   return __retval;
 285:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** }
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
  13              		.loc 1 346 1
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
 347:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   int __retval;
 348:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
  34              		.loc 1 348 53
  35 001e 488D45D8 		leaq	-40(%rbp), %rax
  36 0022 488945A0 		movq	%rax, -96(%rbp)
 349:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   __retval = __mingw_vfprintf( stdout, __format, __local_argv );
  37              		.loc 1 349 30
  38 0026 488B5DA0 		movq	-96(%rbp), %rbx
  39 002a B9010000 		movl	$1, %ecx
  39      00
  40 002f 488B0500 		movq	__imp___acrt_iob_func(%rip), %rax
  40      000000
  41 0036 FFD0     		call	*%rax
  42              	.LVL0:
  43 0038 4989D8   		movq	%rbx, %r8
  44 003b 488B55D0 		movq	-48(%rbp), %rdx
  45 003f 4889C1   		movq	%rax, %rcx
  46 0042 E8000000 		call	__mingw_vfprintf
  46      00
  47 0047 8945AC   		movl	%eax, -84(%rbp)
 350:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   __builtin_va_end( __local_argv );
 351:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h ****   return __retval;
  48              		.loc 1 351 10
  49 004a 8B45AC   		movl	-84(%rbp), %eax
 352:C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include\stdio.h **** }
  50              		.loc 1 352 1
  51 004d 4883C438 		addq	$56, %rsp
  52 0051 5B       		popq	%rbx
  53              		.cfi_restore 3
  54 0052 5D       		popq	%rbp
  55              		.cfi_restore 6
  56              		.cfi_def_cfa 7, -40
  57 0053 C3       		ret
  58              		.cfi_endproc
  59              	.LFE8:
  60              		.seh_endproc
  61 0054 90909090 		.section .rdata,"dr"
  61      90909090 
  61      90909090 
  62              		.align 4
  63              	_ZL4maxn:
  64 0000 00000200 		.long	131072
  65              		.globl	buffer
  66              		.bss
  67              		.align 32
  68              	buffer:
  69 0000 00000000 		.space 131072
  69      00000000 
  69      00000000 
  69      00000000 
  69      00000000 
  70              		.globl	S
  71              		.align 8
  72              	S:
  73 20000 00000000 		.space 8
  73      00000000 
  74              		.globl	T
  75              		.align 8
  76              	T:
  77 20008 00000000 		.space 8
  77      00000000 
  78 20010 00000000 		.text
  78      00000000 
  78      00000000 
  78      00000000 
  79              		.globl	_Z8Get_Charv
  81              		.seh_proc	_Z8Get_Charv
  82              	_Z8Get_Charv:
  83              	.LFB44:
  84              		.file 2 "../../code/code/\312\265\321\351\243\272\273\343\261\340/\277\354\266\301.cpp"
   1:../../code/code/实验：汇编/快读.cpp **** #include <cstdio>
   2:../../code/code/实验：汇编/快读.cpp **** 
   3:../../code/code/实验：汇编/快读.cpp **** using namespace std;
   4:../../code/code/实验：汇编/快读.cpp **** 
   5:../../code/code/实验：汇编/快读.cpp **** const int maxn = 2 << 16;
   6:../../code/code/实验：汇编/快读.cpp **** 
   7:../../code/code/实验：汇编/快读.cpp **** char buffer[maxn], *S, *T;
   8:../../code/code/实验：汇编/快读.cpp **** char Get_Char()
   9:../../code/code/实验：汇编/快读.cpp **** {
  85              		.loc 2 9 1
  86              		.cfi_startproc
  87 0000 55       		pushq	%rbp
  88              		.seh_pushreg	%rbp
  89              		.cfi_def_cfa_offset 16
  90              		.cfi_offset 6, -16
  91 0001 53       		pushq	%rbx
  92              		.seh_pushreg	%rbx
  93              		.cfi_def_cfa_offset 24
  94              		.cfi_offset 3, -24
  95 0002 4883EC28 		subq	$40, %rsp
  96              		.seh_stackalloc	40
  97              		.cfi_def_cfa_offset 64
  98 0006 488DAC24 		leaq	128(%rsp), %rbp
  98      80000000 
  99              		.seh_setframe	%rbp, 128
 100              		.cfi_def_cfa 6, -64
 101              		.seh_endprologue
  10:../../code/code/实验：汇编/快读.cpp **** 	if (S == T)
 102              		.loc 2 10 8
 103 000e 488B1500 		movq	S(%rip), %rdx
 103      000200
 104 0015 488B0508 		movq	T(%rip), %rax
 104      000200
 105              		.loc 2 10 2
 106 001c 4839C2   		cmpq	%rax, %rdx
 107 001f 7561     		jne	.L4
  11:../../code/code/实验：汇编/快读.cpp **** 	{
  12:../../code/code/实验：汇编/快读.cpp **** 		T = (S = buffer) + fread(buffer, 1, maxn, stdin);
 108              		.loc 2 12 10
 109 0021 488D0500 		leaq	buffer(%rip), %rax
 109      000000
 110 0028 48890500 		movq	%rax, S(%rip)
 110      000200
 111 002f 488B1D00 		movq	S(%rip), %rbx
 111      000200
 112              		.loc 2 12 27
 113 0036 B9000000 		movl	$0, %ecx
 113      00
 114 003b 488B0500 		movq	__imp___acrt_iob_func(%rip), %rax
 114      000000
 115 0042 FFD0     		call	*%rax
 116              	.LVL1:
 117 0044 4989C1   		movq	%rax, %r9
 118 0047 41B80000 		movl	$131072, %r8d
 118      0200
 119 004d BA010000 		movl	$1, %edx
 119      00
 120 0052 488D0D00 		leaq	buffer(%rip), %rcx
 120      000000
 121 0059 E8000000 		call	fread
 121      00
 122              		.loc 2 12 20
 123 005e 4801D8   		addq	%rbx, %rax
 124              		.loc 2 12 5
 125 0061 48890508 		movq	%rax, T(%rip)
 125      000200
  13:../../code/code/实验：汇编/快读.cpp **** 		if (S == T) return EOF;
 126              		.loc 2 13 9
 127 0068 488B1500 		movq	S(%rip), %rdx
 127      000200
 128 006f 488B0508 		movq	T(%rip), %rax
 128      000200
 129              		.loc 2 13 3
 130 0076 4839C2   		cmpq	%rax, %rdx
 131 0079 7507     		jne	.L4
 132              		.loc 2 13 22 discriminator 1
 133 007b B8FFFFFF 		movl	$-1, %eax
 133      FF
 134 0080 EB15     		jmp	.L5
 135              	.L4:
  14:../../code/code/实验：汇编/快读.cpp **** 	}
  15:../../code/code/实验：汇编/快读.cpp **** 	return *S++;
 136              		.loc 2 15 11
 137 0082 488B0500 		movq	S(%rip), %rax
 137      000200
 138 0089 488D5001 		leaq	1(%rax), %rdx
 139 008d 48891500 		movq	%rdx, S(%rip)
 139      000200
 140 0094 0FB600   		movzbl	(%rax), %eax
 141              	.L5:
  16:../../code/code/实验：汇编/快读.cpp **** }
 142              		.loc 2 16 1
 143 0097 4883C428 		addq	$40, %rsp
 144 009b 5B       		popq	%rbx
 145              		.cfi_restore 3
 146 009c 5D       		popq	%rbp
 147              		.cfi_restore 6
 148              		.cfi_def_cfa 7, -24
 149 009d C3       		ret
 150              		.cfi_endproc
 151              	.LFE44:
 152              		.seh_endproc
 153              		.globl	_Z7Get_Intv
 155              		.seh_proc	_Z7Get_Intv
 156              	_Z7Get_Intv:
 157              	.LFB45:
  17:../../code/code/实验：汇编/快读.cpp **** 
  18:../../code/code/实验：汇编/快读.cpp **** int Get_Int()
  19:../../code/code/实验：汇编/快读.cpp **** {
 158              		.loc 2 19 1
 159              		.cfi_startproc
 160 009e 55       		pushq	%rbp
 161              		.seh_pushreg	%rbp
 162              		.cfi_def_cfa_offset 16
 163              		.cfi_offset 6, -16
 164 009f 4889E5   		movq	%rsp, %rbp
 165              		.seh_setframe	%rbp, 0
 166              		.cfi_def_cfa_register 6
 167 00a2 4883EC30 		subq	$48, %rsp
 168              		.seh_stackalloc	48
 169              		.seh_endprologue
  20:../../code/code/实验：汇编/快读.cpp **** 	char c;
  21:../../code/code/实验：汇编/快读.cpp **** 	int re = 0;
 170              		.loc 2 21 6
 171 00a6 C745F800 		movl	$0, -8(%rbp)
 171      000000
  22:../../code/code/实验：汇编/快读.cpp **** 	for (c = Get_Char(); c < '0' || c > '9'; c = Get_Char())
 172              		.loc 2 22 19
 173 00ad E84EFFFF 		call	_Z8Get_Charv
 173      FF
 174 00b2 8845FF   		movb	%al, -1(%rbp)
 175              	.L9:
 176              		.loc 2 22 31 discriminator 5
 177 00b5 807DFF2F 		cmpb	$47, -1(%rbp)
 178 00b9 7E06     		jle	.L7
 179              		.loc 2 22 31 is_stmt 0 discriminator 2
 180 00bb 807DFF39 		cmpb	$57, -1(%rbp)
 181 00bf 7E0A     		jle	.L8
 182              	.L7:
 183              		.loc 2 22 55 is_stmt 1 discriminator 4
 184 00c1 E83AFFFF 		call	_Z8Get_Charv
 184      FF
 185 00c6 8845FF   		movb	%al, -1(%rbp)
 186              		.loc 2 22 2 discriminator 4
 187 00c9 EBEA     		jmp	.L9
 188              	.L8:
  23:../../code/code/实验：汇编/快读.cpp **** 		;
  24:../../code/code/实验：汇编/快读.cpp **** 	while (c >= '0' && c <= '9')
 189              		.loc 2 24 18
 190 00cb 807DFF2F 		cmpb	$47, -1(%rbp)
 191 00cf 7E2A     		jle	.L10
 192              		.loc 2 24 18 is_stmt 0 discriminator 1
 193 00d1 807DFF39 		cmpb	$57, -1(%rbp)
 194 00d5 7F24     		jg	.L10
  25:../../code/code/实验：汇编/快读.cpp **** 		re = (re << 1) + (re << 3) + (c - '0'), c = Get_Char();
 195              		.loc 2 25 12 is_stmt 1
 196 00d7 8B45F8   		movl	-8(%rbp), %eax
 197 00da 8D1400   		leal	(%rax,%rax), %edx
 198              		.loc 2 25 24
 199 00dd 8B45F8   		movl	-8(%rbp), %eax
 200 00e0 C1E003   		sall	$3, %eax
 201              		.loc 2 25 18
 202 00e3 01C2     		addl	%eax, %edx
 203              		.loc 2 25 35
 204 00e5 0FBE45FF 		movsbl	-1(%rbp), %eax
 205 00e9 83E830   		subl	$48, %eax
 206              		.loc 2 25 6
 207 00ec 01D0     		addl	%edx, %eax
 208 00ee 8945F8   		movl	%eax, -8(%rbp)
 209              		.loc 2 25 55
 210 00f1 E80AFFFF 		call	_Z8Get_Charv
 210      FF
 211 00f6 8845FF   		movb	%al, -1(%rbp)
  24:../../code/code/实验：汇编/快读.cpp **** 		re = (re << 1) + (re << 3) + (c - '0'), c = Get_Char();
 212              		.loc 2 24 2
 213 00f9 EBD0     		jmp	.L8
 214              	.L10:
  26:../../code/code/实验：汇编/快读.cpp **** 	return re;
 215              		.loc 2 26 9
 216 00fb 8B45F8   		movl	-8(%rbp), %eax
  27:../../code/code/实验：汇编/快读.cpp **** }
 217              		.loc 2 27 1
 218 00fe 4883C430 		addq	$48, %rsp
 219 0102 5D       		popq	%rbp
 220              		.cfi_restore 6
 221              		.cfi_def_cfa 7, 8
 222 0103 C3       		ret
 223              		.cfi_endproc
 224              	.LFE45:
 225              		.seh_endproc
 227              		.section .rdata,"dr"
 228              	.LC0:
 229 0004 256400   		.ascii "%d\0"
 230 0007 00000000 		.text
 230      00000000 
 230      00
 231              		.globl	main
 233              		.seh_proc	main
 234              	main:
 235              	.LFB46:
  28:../../code/code/实验：汇编/快读.cpp **** 
  29:../../code/code/实验：汇编/快读.cpp **** int main()
  30:../../code/code/实验：汇编/快读.cpp **** {
 236              		.loc 2 30 1
 237              		.cfi_startproc
 238 0104 55       		pushq	%rbp
 239              		.seh_pushreg	%rbp
 240              		.cfi_def_cfa_offset 16
 241              		.cfi_offset 6, -16
 242 0105 4889E5   		movq	%rsp, %rbp
 243              		.seh_setframe	%rbp, 0
 244              		.cfi_def_cfa_register 6
 245 0108 4883EC30 		subq	$48, %rsp
 246              		.seh_stackalloc	48
 247              		.seh_endprologue
 248              		.loc 2 30 1
 249 010c E8000000 		call	__main
 249      00
 250              	.LVL2:
  31:../../code/code/实验：汇编/快读.cpp **** 	int a = Get_Int();
 251              		.loc 2 31 17
 252 0111 E888FFFF 		call	_Z7Get_Intv
 252      FF
 253 0116 8945FC   		movl	%eax, -4(%rbp)
  32:../../code/code/实验：汇编/快读.cpp **** 	printf("%d", a);
 254              		.loc 2 32 8
 255 0119 8B45FC   		movl	-4(%rbp), %eax
 256 011c 89C2     		movl	%eax, %edx
 257 011e 488D0D04 		leaq	.LC0(%rip), %rcx
 257      000000
 258 0125 E8000000 		call	_Z6printfPKcz
 258      00
  33:../../code/code/实验：汇编/快读.cpp **** 	return 0;
 259              		.loc 2 33 9
 260 012a B8000000 		movl	$0, %eax
 260      00
  34:../../code/code/实验：汇编/快读.cpp **** }...
 261              		.loc 2 34 1
 262 012f 4883C430 		addq	$48, %rsp
 263 0133 5D       		popq	%rbp
 264              		.cfi_restore 6
 265              		.cfi_def_cfa 7, 8
 266 0134 C3       		ret
 267              		.cfi_endproc
 268              	.LFE46:
 269              		.seh_endproc
 270              	.Letext0:
 271              		.file 3 "C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-m
 272              		.file 4 "C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-m
 273              		.file 5 "C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/i
 274              		.file 6 "<built-in>"
 275 0135 90909090 		.section	.debug_info,"dr"
 275      90909090 
 275      909090
 276              	.Ldebug_info0:
 277 0000 420B0000 		.long	0xb42
 278 0004 0400     		.word	0x4
 279 0006 00000000 		.secrel32	.Ldebug_abbrev0
 280 000a 08       		.byte	0x8
 281 000b 01       		.uleb128 0x1
 282 000c 474E5520 		.ascii "GNU C++98 8.1.0 -mtune=core2 -march=nocona -g -std=gnu++98\0"
 282      432B2B39 
 282      3820382E 
 282      312E3020 
 282      2D6D7475 
 283 0047 04       		.byte	0x4
 284 0048 2E2E5C2E 		.ascii "..\\..\\code\\code\\\312\265\321\351\243\272\273\343\261\340\\\277\354\266\301.cpp\0"
 284      2E5C636F 
 284      64655C63 
 284      6F64655C 
 284      CAB5D1E9 
 285 006c 653A5C79 		.ascii "e:\\yz\\\322\273\326\320\0"
 285      7A5CD2BB 
 285      D6D000
 286 0077 00000000 		.secrel32	.Ldebug_ranges0+0
 287 007b 00000000 		.quad	0
 287      00000000 
 288 0083 00000000 		.secrel32	.Ldebug_line0
 289 0087 02       		.uleb128 0x2
 290 0088 73746400 		.ascii "std\0"
 291 008c 06       		.byte	0x6
 292 008d 00       		.byte	0
 293 008e F9010000 		.long	0x1f9
 294 0092 03       		.uleb128 0x3
 295 0093 5F5F6378 		.ascii "__cxx11\0"
 295      78313100 
 296 009b 04       		.byte	0x4
 297 009c 0401     		.word	0x104
 298 009e 41       		.byte	0x41
 299 009f 04       		.uleb128 0x4
 300 00a0 04       		.byte	0x4
 301 00a1 0401     		.word	0x104
 302 00a3 41       		.byte	0x41
 303 00a4 92000000 		.long	0x92
 304 00a8 05       		.uleb128 0x5
 305 00a9 03       		.byte	0x3
 306 00aa 62       		.byte	0x62
 307 00ab 0B       		.byte	0xb
 308 00ac AF030000 		.long	0x3af
 309 00b0 05       		.uleb128 0x5
 310 00b1 03       		.byte	0x3
 311 00b2 63       		.byte	0x63
 312 00b3 0B       		.byte	0xb
 313 00b4 BC030000 		.long	0x3bc
 314 00b8 05       		.uleb128 0x5
 315 00b9 03       		.byte	0x3
 316 00ba 65       		.byte	0x65
 317 00bb 0B       		.byte	0xb
 318 00bc D0030000 		.long	0x3d0
 319 00c0 05       		.uleb128 0x5
 320 00c1 03       		.byte	0x3
 321 00c2 66       		.byte	0x66
 322 00c3 0B       		.byte	0xb
 323 00c4 EE030000 		.long	0x3ee
 324 00c8 05       		.uleb128 0x5
 325 00c9 03       		.byte	0x3
 326 00ca 67       		.byte	0x67
 327 00cb 0B       		.byte	0xb
 328 00cc 08040000 		.long	0x408
 329 00d0 05       		.uleb128 0x5
 330 00d1 03       		.byte	0x3
 331 00d2 68       		.byte	0x68
 332 00d3 0B       		.byte	0xb
 333 00d4 20040000 		.long	0x420
 334 00d8 05       		.uleb128 0x5
 335 00d9 03       		.byte	0x3
 336 00da 69       		.byte	0x69
 337 00db 0B       		.byte	0xb
 338 00dc 3A040000 		.long	0x43a
 339 00e0 05       		.uleb128 0x5
 340 00e1 03       		.byte	0x3
 341 00e2 6A       		.byte	0x6a
 342 00e3 0B       		.byte	0xb
 343 00e4 54040000 		.long	0x454
 344 00e8 05       		.uleb128 0x5
 345 00e9 03       		.byte	0x3
 346 00ea 6B       		.byte	0x6b
 347 00eb 0B       		.byte	0xb
 348 00ec 6D040000 		.long	0x46d
 349 00f0 05       		.uleb128 0x5
 350 00f1 03       		.byte	0x3
 351 00f2 6C       		.byte	0x6c
 352 00f3 0B       		.byte	0xb
 353 00f4 93040000 		.long	0x493
 354 00f8 05       		.uleb128 0x5
 355 00f9 03       		.byte	0x3
 356 00fa 6D       		.byte	0x6d
 357 00fb 0B       		.byte	0xb
 358 00fc B6040000 		.long	0x4b6
 359 0100 05       		.uleb128 0x5
 360 0101 03       		.byte	0x3
 361 0102 6E       		.byte	0x6e
 362 0103 0B       		.byte	0xb
 363 0104 DA040000 		.long	0x4da
 364 0108 05       		.uleb128 0x5
 365 0109 03       		.byte	0x3
 366 010a 71       		.byte	0x71
 367 010b 0B       		.byte	0xb
 368 010c 12050000 		.long	0x512
 369 0110 05       		.uleb128 0x5
 370 0111 03       		.byte	0x3
 371 0112 72       		.byte	0x72
 372 0113 0B       		.byte	0xb
 373 0114 3C050000 		.long	0x53c
 374 0118 05       		.uleb128 0x5
 375 0119 03       		.byte	0x3
 376 011a 73       		.byte	0x73
 377 011b 0B       		.byte	0xb
 378 011c 61050000 		.long	0x561
 379 0120 05       		.uleb128 0x5
 380 0121 03       		.byte	0x3
 381 0122 74       		.byte	0x74
 382 0123 0B       		.byte	0xb
 383 0124 97050000 		.long	0x597
 384 0128 05       		.uleb128 0x5
 385 0129 03       		.byte	0x3
 386 012a 75       		.byte	0x75
 387 012b 0B       		.byte	0xb
 388 012c BA050000 		.long	0x5ba
 389 0130 05       		.uleb128 0x5
 390 0131 03       		.byte	0x3
 391 0132 76       		.byte	0x76
 392 0133 0B       		.byte	0xb
 393 0134 E0050000 		.long	0x5e0
 394 0138 05       		.uleb128 0x5
 395 0139 03       		.byte	0x3
 396 013a 78       		.byte	0x78
 397 013b 0B       		.byte	0xb
 398 013c F9050000 		.long	0x5f9
 399 0140 05       		.uleb128 0x5
 400 0141 03       		.byte	0x3
 401 0142 79       		.byte	0x79
 402 0143 0B       		.byte	0xb
 403 0144 11060000 		.long	0x611
 404 0148 05       		.uleb128 0x5
 405 0149 03       		.byte	0x3
 406 014a 7C       		.byte	0x7c
 407 014b 0B       		.byte	0xb
 408 014c 22060000 		.long	0x622
 409 0150 05       		.uleb128 0x5
 410 0151 03       		.byte	0x3
 411 0152 7E       		.byte	0x7e
 412 0153 0B       		.byte	0xb
 413 0154 3A060000 		.long	0x63a
 414 0158 05       		.uleb128 0x5
 415 0159 03       		.byte	0x3
 416 015a 7F       		.byte	0x7f
 417 015b 0B       		.byte	0xb
 418 015c 50060000 		.long	0x650
 419 0160 05       		.uleb128 0x5
 420 0161 03       		.byte	0x3
 421 0162 83       		.byte	0x83
 422 0163 0B       		.byte	0xb
 423 0164 D7060000 		.long	0x6d7
 424 0168 05       		.uleb128 0x5
 425 0169 03       		.byte	0x3
 426 016a 84       		.byte	0x84
 427 016b 0B       		.byte	0xb
 428 016c F1060000 		.long	0x6f1
 429 0170 05       		.uleb128 0x5
 430 0171 03       		.byte	0x3
 431 0172 85       		.byte	0x85
 432 0173 0B       		.byte	0xb
 433 0174 10070000 		.long	0x710
 434 0178 05       		.uleb128 0x5
 435 0179 03       		.byte	0x3
 436 017a 86       		.byte	0x86
 437 017b 0B       		.byte	0xb
 438 017c 26070000 		.long	0x726
 439 0180 05       		.uleb128 0x5
 440 0181 03       		.byte	0x3
 441 0182 87       		.byte	0x87
 442 0183 0B       		.byte	0xb
 443 0184 4D070000 		.long	0x74d
 444 0188 05       		.uleb128 0x5
 445 0189 03       		.byte	0x3
 446 018a 88       		.byte	0x88
 447 018b 0B       		.byte	0xb
 448 018c 68070000 		.long	0x768
 449 0190 05       		.uleb128 0x5
 450 0191 03       		.byte	0x3
 451 0192 89       		.byte	0x89
 452 0193 0B       		.byte	0xb
 453 0194 92070000 		.long	0x792
 454 0198 05       		.uleb128 0x5
 455 0199 03       		.byte	0x3
 456 019a 8A       		.byte	0x8a
 457 019b 0B       		.byte	0xb
 458 019c C4070000 		.long	0x7c4
 459 01a0 05       		.uleb128 0x5
 460 01a1 03       		.byte	0x3
 461 01a2 8B       		.byte	0x8b
 462 01a3 0B       		.byte	0xb
 463 01a4 F5070000 		.long	0x7f5
 464 01a8 05       		.uleb128 0x5
 465 01a9 03       		.byte	0x3
 466 01aa 8D       		.byte	0x8d
 467 01ab 0B       		.byte	0xb
 468 01ac 06080000 		.long	0x806
 469 01b0 05       		.uleb128 0x5
 470 01b1 03       		.byte	0x3
 471 01b2 8F       		.byte	0x8f
 472 01b3 0B       		.byte	0xb
 473 01b4 20080000 		.long	0x820
 474 01b8 05       		.uleb128 0x5
 475 01b9 03       		.byte	0x3
 476 01ba 90       		.byte	0x90
 477 01bb 0B       		.byte	0xb
 478 01bc 3F080000 		.long	0x83f
 479 01c0 05       		.uleb128 0x5
 480 01c1 03       		.byte	0x3
 481 01c2 91       		.byte	0x91
 482 01c3 0B       		.byte	0xb
 483 01c4 7E080000 		.long	0x87e
 484 01c8 05       		.uleb128 0x5
 485 01c9 03       		.byte	0x3
 486 01ca 92       		.byte	0x92
 487 01cb 0B       		.byte	0xb
 488 01cc AE080000 		.long	0x8ae
 489 01d0 05       		.uleb128 0x5
 490 01d1 03       		.byte	0x3
 491 01d2 B9       		.byte	0xb9
 492 01d3 16       		.byte	0x16
 493 01d4 E7080000 		.long	0x8e7
 494 01d8 05       		.uleb128 0x5
 495 01d9 03       		.byte	0x3
 496 01da BA       		.byte	0xba
 497 01db 16       		.byte	0x16
 498 01dc 21090000 		.long	0x921
 499 01e0 05       		.uleb128 0x5
 500 01e1 03       		.byte	0x3
 501 01e2 BB       		.byte	0xbb
 502 01e3 16       		.byte	0x16
 503 01e4 5E090000 		.long	0x95e
 504 01e8 05       		.uleb128 0x5
 505 01e9 03       		.byte	0x3
 506 01ea BC       		.byte	0xbc
 507 01eb 16       		.byte	0x16
 508 01ec 8C090000 		.long	0x98c
 509 01f0 05       		.uleb128 0x5
 510 01f1 03       		.byte	0x3
 511 01f2 BD       		.byte	0xbd
 512 01f3 16       		.byte	0x16
 513 01f4 CD090000 		.long	0x9cd
 514 01f8 00       		.byte	0
 515 01f9 06       		.uleb128 0x6
 516 01fa 5F5F676E 		.ascii "__gnu_cxx\0"
 516      755F6378 
 516      7800
 517 0204 04       		.byte	0x4
 518 0205 0601     		.word	0x106
 519 0207 0B       		.byte	0xb
 520 0208 4B020000 		.long	0x24b
 521 020c 03       		.uleb128 0x3
 522 020d 5F5F6378 		.ascii "__cxx11\0"
 522      78313100 
 523 0215 04       		.byte	0x4
 524 0216 0801     		.word	0x108
 525 0218 41       		.byte	0x41
 526 0219 04       		.uleb128 0x4
 527 021a 04       		.byte	0x4
 528 021b 0801     		.word	0x108
 529 021d 41       		.byte	0x41
 530 021e 0C020000 		.long	0x20c
 531 0222 05       		.uleb128 0x5
 532 0223 03       		.byte	0x3
 533 0224 AF       		.byte	0xaf
 534 0225 0B       		.byte	0xb
 535 0226 E7080000 		.long	0x8e7
 536 022a 05       		.uleb128 0x5
 537 022b 03       		.byte	0x3
 538 022c B0       		.byte	0xb0
 539 022d 0B       		.byte	0xb
 540 022e 21090000 		.long	0x921
 541 0232 05       		.uleb128 0x5
 542 0233 03       		.byte	0x3
 543 0234 B1       		.byte	0xb1
 544 0235 0B       		.byte	0xb
 545 0236 5E090000 		.long	0x95e
 546 023a 05       		.uleb128 0x5
 547 023b 03       		.byte	0x3
 548 023c B2       		.byte	0xb2
 549 023d 0B       		.byte	0xb
 550 023e 8C090000 		.long	0x98c
 551 0242 05       		.uleb128 0x5
 552 0243 03       		.byte	0x3
 553 0244 B3       		.byte	0xb3
 554 0245 0B       		.byte	0xb
 555 0246 CD090000 		.long	0x9cd
 556 024a 00       		.byte	0
 557 024b 07       		.uleb128 0x7
 558 024c 08       		.byte	0x8
 559 024d 5F5F6275 		.ascii "__builtin_va_list\0"
 559      696C7469 
 559      6E5F7661 
 559      5F6C6973 
 559      7400
 560 025f 63020000 		.long	0x263
 561 0263 08       		.uleb128 0x8
 562 0264 01       		.byte	0x1
 563 0265 06       		.byte	0x6
 564 0266 63686172 		.ascii "char\0"
 564      00
 565 026b 09       		.uleb128 0x9
 566 026c 63020000 		.long	0x263
 567 0270 0A       		.uleb128 0xa
 568 0271 73697A65 		.ascii "size_t\0"
 568      5F7400
 569 0278 05       		.byte	0x5
 570 0279 23       		.byte	0x23
 571 027a 2C       		.byte	0x2c
 572 027b 7F020000 		.long	0x27f
 573 027f 08       		.uleb128 0x8
 574 0280 08       		.byte	0x8
 575 0281 07       		.byte	0x7
 576 0282 6C6F6E67 		.ascii "long long unsigned int\0"
 576      206C6F6E 
 576      6720756E 
 576      7369676E 
 576      65642069 
 577 0299 08       		.uleb128 0x8
 578 029a 08       		.byte	0x8
 579 029b 05       		.byte	0x5
 580 029c 6C6F6E67 		.ascii "long long int\0"
 580      206C6F6E 
 580      6720696E 
 580      7400
 581 02aa 08       		.uleb128 0x8
 582 02ab 02       		.byte	0x2
 583 02ac 07       		.byte	0x7
 584 02ad 73686F72 		.ascii "short unsigned int\0"
 584      7420756E 
 584      7369676E 
 584      65642069 
 584      6E7400
 585 02c0 08       		.uleb128 0x8
 586 02c1 04       		.byte	0x4
 587 02c2 05       		.byte	0x5
 588 02c3 696E7400 		.ascii "int\0"
 589 02c7 09       		.uleb128 0x9
 590 02c8 C0020000 		.long	0x2c0
 591 02cc 08       		.uleb128 0x8
 592 02cd 04       		.byte	0x4
 593 02ce 05       		.byte	0x5
 594 02cf 6C6F6E67 		.ascii "long int\0"
 594      20696E74 
 594      00
 595 02d8 0B       		.uleb128 0xb
 596 02d9 08       		.byte	0x8
 597 02da 63020000 		.long	0x263
 598 02de 08       		.uleb128 0x8
 599 02df 02       		.byte	0x2
 600 02e0 07       		.byte	0x7
 601 02e1 77636861 		.ascii "wchar_t\0"
 601      725F7400 
 602 02e9 08       		.uleb128 0x8
 603 02ea 04       		.byte	0x4
 604 02eb 07       		.byte	0x7
 605 02ec 756E7369 		.ascii "unsigned int\0"
 605      676E6564 
 605      20696E74 
 605      00
 606 02f9 08       		.uleb128 0x8
 607 02fa 04       		.byte	0x4
 608 02fb 07       		.byte	0x7
 609 02fc 6C6F6E67 		.ascii "long unsigned int\0"
 609      20756E73 
 609      69676E65 
 609      6420696E 
 609      7400
 610 030e 08       		.uleb128 0x8
 611 030f 01       		.byte	0x1
 612 0310 08       		.byte	0x8
 613 0311 756E7369 		.ascii "unsigned char\0"
 613      676E6564 
 613      20636861 
 613      7200
 614 031f 0C       		.uleb128 0xc
 615 0320 5F696F62 		.ascii "_iobuf\0"
 615      756600
 616 0327 30       		.byte	0x30
 617 0328 01       		.byte	0x1
 618 0329 1A       		.byte	0x1a
 619 032a 0A       		.byte	0xa
 620 032b AF030000 		.long	0x3af
 621 032f 0D       		.uleb128 0xd
 622 0330 5F707472 		.ascii "_ptr\0"
 622      00
 623 0335 01       		.byte	0x1
 624 0336 1B       		.byte	0x1b
 625 0337 0B       		.byte	0xb
 626 0338 D8020000 		.long	0x2d8
 627 033c 00       		.byte	0
 628 033d 0D       		.uleb128 0xd
 629 033e 5F636E74 		.ascii "_cnt\0"
 629      00
 630 0343 01       		.byte	0x1
 631 0344 1C       		.byte	0x1c
 632 0345 09       		.byte	0x9
 633 0346 C0020000 		.long	0x2c0
 634 034a 08       		.byte	0x8
 635 034b 0D       		.uleb128 0xd
 636 034c 5F626173 		.ascii "_base\0"
 636      6500
 637 0352 01       		.byte	0x1
 638 0353 1D       		.byte	0x1d
 639 0354 0B       		.byte	0xb
 640 0355 D8020000 		.long	0x2d8
 641 0359 10       		.byte	0x10
 642 035a 0D       		.uleb128 0xd
 643 035b 5F666C61 		.ascii "_flag\0"
 643      6700
 644 0361 01       		.byte	0x1
 645 0362 1E       		.byte	0x1e
 646 0363 09       		.byte	0x9
 647 0364 C0020000 		.long	0x2c0
 648 0368 18       		.byte	0x18
 649 0369 0D       		.uleb128 0xd
 650 036a 5F66696C 		.ascii "_file\0"
 650      6500
 651 0370 01       		.byte	0x1
 652 0371 1F       		.byte	0x1f
 653 0372 09       		.byte	0x9
 654 0373 C0020000 		.long	0x2c0
 655 0377 1C       		.byte	0x1c
 656 0378 0D       		.uleb128 0xd
 657 0379 5F636861 		.ascii "_charbuf\0"
 657      72627566 
 657      00
 658 0382 01       		.byte	0x1
 659 0383 20       		.byte	0x20
 660 0384 09       		.byte	0x9
 661 0385 C0020000 		.long	0x2c0
 662 0389 20       		.byte	0x20
 663 038a 0D       		.uleb128 0xd
 664 038b 5F627566 		.ascii "_bufsiz\0"
 664      73697A00 
 665 0393 01       		.byte	0x1
 666 0394 21       		.byte	0x21
 667 0395 09       		.byte	0x9
 668 0396 C0020000 		.long	0x2c0
 669 039a 24       		.byte	0x24
 670 039b 0D       		.uleb128 0xd
 671 039c 5F746D70 		.ascii "_tmpfname\0"
 671      666E616D 
 671      6500
 672 03a6 01       		.byte	0x1
 673 03a7 22       		.byte	0x22
 674 03a8 0B       		.byte	0xb
 675 03a9 D8020000 		.long	0x2d8
 676 03ad 28       		.byte	0x28
 677 03ae 00       		.byte	0
 678 03af 0A       		.uleb128 0xa
 679 03b0 46494C45 		.ascii "FILE\0"
 679      00
 680 03b5 01       		.byte	0x1
 681 03b6 24       		.byte	0x24
 682 03b7 19       		.byte	0x19
 683 03b8 1F030000 		.long	0x31f
 684 03bc 0A       		.uleb128 0xa
 685 03bd 66706F73 		.ascii "fpos_t\0"
 685      5F7400
 686 03c4 01       		.byte	0x1
 687 03c5 68       		.byte	0x68
 688 03c6 25       		.byte	0x25
 689 03c7 99020000 		.long	0x299
 690 03cb 09       		.uleb128 0x9
 691 03cc BC030000 		.long	0x3bc
 692 03d0 0E       		.uleb128 0xe
 693 03d1 636C6561 		.ascii "clearerr\0"
 693      72657272 
 693      00
 694 03da 01       		.byte	0x1
 695 03db 4202     		.word	0x242
 696 03dd 10       		.byte	0x10
 697 03de E8030000 		.long	0x3e8
 698 03e2 0F       		.uleb128 0xf
 699 03e3 E8030000 		.long	0x3e8
 700 03e7 00       		.byte	0
 701 03e8 0B       		.uleb128 0xb
 702 03e9 08       		.byte	0x8
 703 03ea AF030000 		.long	0x3af
 704 03ee 10       		.uleb128 0x10
 705 03ef 66636C6F 		.ascii "fclose\0"
 705      736500
 706 03f6 01       		.byte	0x1
 707 03f7 4302     		.word	0x243
 708 03f9 0F       		.byte	0xf
 709 03fa C0020000 		.long	0x2c0
 710 03fe 08040000 		.long	0x408
 711 0402 0F       		.uleb128 0xf
 712 0403 E8030000 		.long	0x3e8
 713 0407 00       		.byte	0
 714 0408 10       		.uleb128 0x10
 715 0409 66656F66 		.ascii "feof\0"
 715      00
 716 040e 01       		.byte	0x1
 717 040f 4A02     		.word	0x24a
 718 0411 0F       		.byte	0xf
 719 0412 C0020000 		.long	0x2c0
 720 0416 20040000 		.long	0x420
 721 041a 0F       		.uleb128 0xf
 722 041b E8030000 		.long	0x3e8
 723 041f 00       		.byte	0
 724 0420 10       		.uleb128 0x10
 725 0421 66657272 		.ascii "ferror\0"
 725      6F7200
 726 0428 01       		.byte	0x1
 727 0429 4B02     		.word	0x24b
 728 042b 0F       		.byte	0xf
 729 042c C0020000 		.long	0x2c0
 730 0430 3A040000 		.long	0x43a
 731 0434 0F       		.uleb128 0xf
 732 0435 E8030000 		.long	0x3e8
 733 0439 00       		.byte	0
 734 043a 10       		.uleb128 0x10
 735 043b 66666C75 		.ascii "fflush\0"
 735      736800
 736 0442 01       		.byte	0x1
 737 0443 4C02     		.word	0x24c
 738 0445 0F       		.byte	0xf
 739 0446 C0020000 		.long	0x2c0
 740 044a 54040000 		.long	0x454
 741 044e 0F       		.uleb128 0xf
 742 044f E8030000 		.long	0x3e8
 743 0453 00       		.byte	0
 744 0454 10       		.uleb128 0x10
 745 0455 66676574 		.ascii "fgetc\0"
 745      6300
 746 045b 01       		.byte	0x1
 747 045c 4D02     		.word	0x24d
 748 045e 0F       		.byte	0xf
 749 045f C0020000 		.long	0x2c0
 750 0463 6D040000 		.long	0x46d
 751 0467 0F       		.uleb128 0xf
 752 0468 E8030000 		.long	0x3e8
 753 046c 00       		.byte	0
 754 046d 10       		.uleb128 0x10
 755 046e 66676574 		.ascii "fgetpos\0"
 755      706F7300 
 756 0476 01       		.byte	0x1
 757 0477 4F02     		.word	0x24f
 758 0479 0F       		.byte	0xf
 759 047a C0020000 		.long	0x2c0
 760 047e 8D040000 		.long	0x48d
 761 0482 0F       		.uleb128 0xf
 762 0483 E8030000 		.long	0x3e8
 763 0487 0F       		.uleb128 0xf
 764 0488 8D040000 		.long	0x48d
 765 048c 00       		.byte	0
 766 048d 0B       		.uleb128 0xb
 767 048e 08       		.byte	0x8
 768 048f BC030000 		.long	0x3bc
 769 0493 10       		.uleb128 0x10
 770 0494 66676574 		.ascii "fgets\0"
 770      7300
 771 049a 01       		.byte	0x1
 772 049b 5102     		.word	0x251
 773 049d 11       		.byte	0x11
 774 049e D8020000 		.long	0x2d8
 775 04a2 B6040000 		.long	0x4b6
 776 04a6 0F       		.uleb128 0xf
 777 04a7 D8020000 		.long	0x2d8
 778 04ab 0F       		.uleb128 0xf
 779 04ac C0020000 		.long	0x2c0
 780 04b0 0F       		.uleb128 0xf
 781 04b1 E8030000 		.long	0x3e8
 782 04b5 00       		.byte	0
 783 04b6 10       		.uleb128 0x10
 784 04b7 666F7065 		.ascii "fopen\0"
 784      6E00
 785 04bd 01       		.byte	0x1
 786 04be 5802     		.word	0x258
 787 04c0 11       		.byte	0x11
 788 04c1 E8030000 		.long	0x3e8
 789 04c5 D4040000 		.long	0x4d4
 790 04c9 0F       		.uleb128 0xf
 791 04ca D4040000 		.long	0x4d4
 792 04ce 0F       		.uleb128 0xf
 793 04cf D4040000 		.long	0x4d4
 794 04d3 00       		.byte	0
 795 04d4 0B       		.uleb128 0xb
 796 04d5 08       		.byte	0x8
 797 04d6 6B020000 		.long	0x26b
 798 04da 11       		.uleb128 0x11
 799 04db 66707269 		.ascii "fprintf\0"
 799      6E746600 
 800 04e3 01       		.byte	0x1
 801 04e4 4E01     		.word	0x14e
 802 04e6 05       		.byte	0x5
 803 04e7 5F5A3766 		.ascii "_Z7fprintfP6_iobufPKcz\0"
 803      7072696E 
 803      74665036 
 803      5F696F62 
 803      7566504B 
 804 04fe C0020000 		.long	0x2c0
 805 0502 12050000 		.long	0x512
 806 0506 0F       		.uleb128 0xf
 807 0507 E8030000 		.long	0x3e8
 808 050b 0F       		.uleb128 0xf
 809 050c D4040000 		.long	0x4d4
 810 0510 12       		.uleb128 0x12
 811 0511 00       		.byte	0
 812 0512 10       		.uleb128 0x10
 813 0513 66726561 		.ascii "fread\0"
 813      6400
 814 0519 01       		.byte	0x1
 815 051a 5D02     		.word	0x25d
 816 051c 12       		.byte	0x12
 817 051d 70020000 		.long	0x270
 818 0521 3A050000 		.long	0x53a
 819 0525 0F       		.uleb128 0xf
 820 0526 3A050000 		.long	0x53a
 821 052a 0F       		.uleb128 0xf
 822 052b 70020000 		.long	0x270
 823 052f 0F       		.uleb128 0xf
 824 0530 70020000 		.long	0x270
 825 0534 0F       		.uleb128 0xf
 826 0535 E8030000 		.long	0x3e8
 827 0539 00       		.byte	0
 828 053a 13       		.uleb128 0x13
 829 053b 08       		.byte	0x8
 830 053c 10       		.uleb128 0x10
 831 053d 6672656F 		.ascii "freopen\0"
 831      70656E00 
 832 0545 01       		.byte	0x1
 833 0546 5E02     		.word	0x25e
 834 0548 11       		.byte	0x11
 835 0549 E8030000 		.long	0x3e8
 836 054d 61050000 		.long	0x561
 837 0551 0F       		.uleb128 0xf
 838 0552 D4040000 		.long	0x4d4
 839 0556 0F       		.uleb128 0xf
 840 0557 D4040000 		.long	0x4d4
 841 055b 0F       		.uleb128 0xf
 842 055c E8030000 		.long	0x3e8
 843 0560 00       		.byte	0
 844 0561 11       		.uleb128 0x11
 845 0562 66736361 		.ascii "fscanf\0"
 845      6E6600
 846 0569 01       		.byte	0x1
 847 056a 2101     		.word	0x121
 848 056c 05       		.byte	0x5
 849 056d 5F5A3666 		.ascii "_Z6fscanfP6_iobufPKcz\0"
 849      7363616E 
 849      6650365F 
 849      696F6275 
 849      66504B63 
 850 0583 C0020000 		.long	0x2c0
 851 0587 97050000 		.long	0x597
 852 058b 0F       		.uleb128 0xf
 853 058c E8030000 		.long	0x3e8
 854 0590 0F       		.uleb128 0xf
 855 0591 D4040000 		.long	0x4d4
 856 0595 12       		.uleb128 0x12
 857 0596 00       		.byte	0
 858 0597 10       		.uleb128 0x10
 859 0598 66736565 		.ascii "fseek\0"
 859      6B00
 860 059e 01       		.byte	0x1
 861 059f 6102     		.word	0x261
 862 05a1 0F       		.byte	0xf
 863 05a2 C0020000 		.long	0x2c0
 864 05a6 BA050000 		.long	0x5ba
 865 05aa 0F       		.uleb128 0xf
 866 05ab E8030000 		.long	0x3e8
 867 05af 0F       		.uleb128 0xf
 868 05b0 CC020000 		.long	0x2cc
 869 05b4 0F       		.uleb128 0xf
 870 05b5 C0020000 		.long	0x2c0
 871 05b9 00       		.byte	0
 872 05ba 10       		.uleb128 0x10
 873 05bb 66736574 		.ascii "fsetpos\0"
 873      706F7300 
 874 05c3 01       		.byte	0x1
 875 05c4 5F02     		.word	0x25f
 876 05c6 0F       		.byte	0xf
 877 05c7 C0020000 		.long	0x2c0
 878 05cb DA050000 		.long	0x5da
 879 05cf 0F       		.uleb128 0xf
 880 05d0 E8030000 		.long	0x3e8
 881 05d4 0F       		.uleb128 0xf
 882 05d5 DA050000 		.long	0x5da
 883 05d9 00       		.byte	0
 884 05da 0B       		.uleb128 0xb
 885 05db 08       		.byte	0x8
 886 05dc CB030000 		.long	0x3cb
 887 05e0 10       		.uleb128 0x10
 888 05e1 6674656C 		.ascii "ftell\0"
 888      6C00
 889 05e7 01       		.byte	0x1
 890 05e8 6202     		.word	0x262
 891 05ea 10       		.byte	0x10
 892 05eb CC020000 		.long	0x2cc
 893 05ef F9050000 		.long	0x5f9
 894 05f3 0F       		.uleb128 0xf
 895 05f4 E8030000 		.long	0x3e8
 896 05f8 00       		.byte	0
 897 05f9 10       		.uleb128 0x10
 898 05fa 67657463 		.ascii "getc\0"
 898      00
 899 05ff 01       		.byte	0x1
 900 0600 8F02     		.word	0x28f
 901 0602 0F       		.byte	0xf
 902 0603 C0020000 		.long	0x2c0
 903 0607 11060000 		.long	0x611
 904 060b 0F       		.uleb128 0xf
 905 060c E8030000 		.long	0x3e8
 906 0610 00       		.byte	0
 907 0611 14       		.uleb128 0x14
 908 0612 67657463 		.ascii "getchar\0"
 908      68617200 
 909 061a 01       		.byte	0x1
 910 061b 9002     		.word	0x290
 911 061d 0F       		.byte	0xf
 912 061e C0020000 		.long	0x2c0
 913 0622 10       		.uleb128 0x10
 914 0623 67657473 		.ascii "gets\0"
 914      00
 915 0628 01       		.byte	0x1
 916 0629 9202     		.word	0x292
 917 062b 11       		.byte	0x11
 918 062c D8020000 		.long	0x2d8
 919 0630 3A060000 		.long	0x63a
 920 0634 0F       		.uleb128 0xf
 921 0635 D8020000 		.long	0x2d8
 922 0639 00       		.byte	0
 923 063a 0E       		.uleb128 0xe
 924 063b 70657272 		.ascii "perror\0"
 924      6F7200
 925 0642 01       		.byte	0x1
 926 0643 9602     		.word	0x296
 927 0645 10       		.byte	0x10
 928 0646 50060000 		.long	0x650
 929 064a 0F       		.uleb128 0xf
 930 064b D4040000 		.long	0x4d4
 931 064f 00       		.byte	0
 932 0650 15       		.uleb128 0x15
 933 0651 7072696E 		.ascii "printf\0"
 933      746600
 934 0658 01       		.byte	0x1
 935 0659 5901     		.word	0x159
 936 065b 05       		.byte	0x5
 937 065c 5F5A3670 		.ascii "_Z6printfPKcz\0"
 937      72696E74 
 937      66504B63 
 937      7A00
 938 066a C0020000 		.long	0x2c0
 939 066e 00000000 		.quad	.LFB8
 939      00000000 
 940 0676 54000000 		.quad	.LFE8-.LFB8
 940      00000000 
 941 067e 01       		.uleb128 0x1
 942 067f 9C       		.byte	0x9c
 943 0680 D7060000 		.long	0x6d7
 944 0684 12       		.uleb128 0x12
 945 0685 16       		.uleb128 0x16
 946 0686 5F5F666F 		.ascii "__format\0"
 946      726D6174 
 946      00
 947 068f 01       		.byte	0x1
 948 0690 5901     		.word	0x159
 949 0692 19       		.byte	0x19
 950 0693 D4040000 		.long	0x4d4
 951 0697 02       		.uleb128 0x2
 952 0698 91       		.byte	0x91
 953 0699 00       		.sleb128 0
 954 069a 12       		.uleb128 0x12
 955 069b 17       		.uleb128 0x17
 956 069c 5F5F7265 		.ascii "__retval\0"
 956      7476616C 
 956      00
 957 06a5 01       		.byte	0x1
 958 06a6 5B01     		.word	0x15b
 959 06a8 07       		.byte	0x7
 960 06a9 C0020000 		.long	0x2c0
 961 06ad 02       		.uleb128 0x2
 962 06ae 91       		.byte	0x91
 963 06af 5C       		.sleb128 -36
 964 06b0 17       		.uleb128 0x17
 965 06b1 5F5F6C6F 		.ascii "__local_argv\0"
 965      63616C5F 
 965      61726776 
 965      00
 966 06be 01       		.byte	0x1
 967 06bf 5C01     		.word	0x15c
 968 06c1 15       		.byte	0x15
 969 06c2 4B020000 		.long	0x24b
 970 06c6 02       		.uleb128 0x2
 971 06c7 91       		.byte	0x91
 972 06c8 50       		.sleb128 -48
 973 06c9 18       		.uleb128 0x18
 974 06ca 38000000 		.quad	.LVL0
 974      00000000 
 975 06d2 390B0000 		.long	0xb39
 976 06d6 00       		.byte	0
 977 06d7 10       		.uleb128 0x10
 978 06d8 72656D6F 		.ascii "remove\0"
 978      766500
 979 06df 01       		.byte	0x1
 980 06e0 A402     		.word	0x2a4
 981 06e2 0F       		.byte	0xf
 982 06e3 C0020000 		.long	0x2c0
 983 06e7 F1060000 		.long	0x6f1
 984 06eb 0F       		.uleb128 0xf
 985 06ec D4040000 		.long	0x4d4
 986 06f0 00       		.byte	0
 987 06f1 10       		.uleb128 0x10
 988 06f2 72656E61 		.ascii "rename\0"
 988      6D6500
 989 06f9 01       		.byte	0x1
 990 06fa A502     		.word	0x2a5
 991 06fc 0F       		.byte	0xf
 992 06fd C0020000 		.long	0x2c0
 993 0701 10070000 		.long	0x710
 994 0705 0F       		.uleb128 0xf
 995 0706 D4040000 		.long	0x4d4
 996 070a 0F       		.uleb128 0xf
 997 070b D4040000 		.long	0x4d4
 998 070f 00       		.byte	0
 999 0710 0E       		.uleb128 0xe
 1000 0711 72657769 		.ascii "rewind\0"
 1000      6E6400
 1001 0718 01       		.byte	0x1
 1002 0719 AB02     		.word	0x2ab
 1003 071b 10       		.byte	0x10
 1004 071c 26070000 		.long	0x726
 1005 0720 0F       		.uleb128 0xf
 1006 0721 E8030000 		.long	0x3e8
 1007 0725 00       		.byte	0
 1008 0726 11       		.uleb128 0x11
 1009 0727 7363616E 		.ascii "scanf\0"
 1009      6600
 1010 072d 01       		.byte	0x1
 1011 072e 1601     		.word	0x116
 1012 0730 05       		.byte	0x5
 1013 0731 5F5A3573 		.ascii "_Z5scanfPKcz\0"
 1013      63616E66 
 1013      504B637A 
 1013      00
 1014 073e C0020000 		.long	0x2c0
 1015 0742 4D070000 		.long	0x74d
 1016 0746 0F       		.uleb128 0xf
 1017 0747 D4040000 		.long	0x4d4
 1018 074b 12       		.uleb128 0x12
 1019 074c 00       		.byte	0
 1020 074d 0E       		.uleb128 0xe
 1021 074e 73657462 		.ascii "setbuf\0"
 1021      756600
 1022 0755 01       		.byte	0x1
 1023 0756 AD02     		.word	0x2ad
 1024 0758 10       		.byte	0x10
 1025 0759 68070000 		.long	0x768
 1026 075d 0F       		.uleb128 0xf
 1027 075e E8030000 		.long	0x3e8
 1028 0762 0F       		.uleb128 0xf
 1029 0763 D8020000 		.long	0x2d8
 1030 0767 00       		.byte	0
 1031 0768 10       		.uleb128 0x10
 1032 0769 73657476 		.ascii "setvbuf\0"
 1032      62756600 
 1033 0771 01       		.byte	0x1
 1034 0772 B102     		.word	0x2b1
 1035 0774 0F       		.byte	0xf
 1036 0775 C0020000 		.long	0x2c0
 1037 0779 92070000 		.long	0x792
 1038 077d 0F       		.uleb128 0xf
 1039 077e E8030000 		.long	0x3e8
 1040 0782 0F       		.uleb128 0xf
 1041 0783 D8020000 		.long	0x2d8
 1042 0787 0F       		.uleb128 0xf
 1043 0788 C0020000 		.long	0x2c0
 1044 078c 0F       		.uleb128 0xf
 1045 078d 70020000 		.long	0x270
 1046 0791 00       		.byte	0
 1047 0792 11       		.uleb128 0x11
 1048 0793 73707269 		.ascii "sprintf\0"
 1048      6E746600 
 1049 079b 01       		.byte	0x1
 1050 079c 6401     		.word	0x164
 1051 079e 05       		.byte	0x5
 1052 079f 5F5A3773 		.ascii "_Z7sprintfPcPKcz\0"
 1052      7072696E 
 1052      74665063 
 1052      504B637A 
 1052      00
 1053 07b0 C0020000 		.long	0x2c0
 1054 07b4 C4070000 		.long	0x7c4
 1055 07b8 0F       		.uleb128 0xf
 1056 07b9 D8020000 		.long	0x2d8
 1057 07bd 0F       		.uleb128 0xf
 1058 07be D4040000 		.long	0x4d4
 1059 07c2 12       		.uleb128 0x12
 1060 07c3 00       		.byte	0
 1061 07c4 11       		.uleb128 0x11
 1062 07c5 73736361 		.ascii "sscanf\0"
 1062      6E6600
 1063 07cc 01       		.byte	0x1
 1064 07cd 0B01     		.word	0x10b
 1065 07cf 05       		.byte	0x5
 1066 07d0 5F5A3673 		.ascii "_Z6sscanfPKcS0_z\0"
 1066      7363616E 
 1066      66504B63 
 1066      53305F7A 
 1066      00
 1067 07e1 C0020000 		.long	0x2c0
 1068 07e5 F5070000 		.long	0x7f5
 1069 07e9 0F       		.uleb128 0xf
 1070 07ea D4040000 		.long	0x4d4
 1071 07ee 0F       		.uleb128 0xf
 1072 07ef D4040000 		.long	0x4d4
 1073 07f3 12       		.uleb128 0x12
 1074 07f4 00       		.byte	0
 1075 07f5 14       		.uleb128 0x14
 1076 07f6 746D7066 		.ascii "tmpfile\0"
 1076      696C6500 
 1077 07fe 01       		.byte	0x1
 1078 07ff CB02     		.word	0x2cb
 1079 0801 11       		.byte	0x11
 1080 0802 E8030000 		.long	0x3e8
 1081 0806 10       		.uleb128 0x10
 1082 0807 746D706E 		.ascii "tmpnam\0"
 1082      616D00
 1083 080e 01       		.byte	0x1
 1084 080f CC02     		.word	0x2cc
 1085 0811 11       		.byte	0x11
 1086 0812 D8020000 		.long	0x2d8
 1087 0816 20080000 		.long	0x820
 1088 081a 0F       		.uleb128 0xf
 1089 081b D8020000 		.long	0x2d8
 1090 081f 00       		.byte	0
 1091 0820 10       		.uleb128 0x10
 1092 0821 756E6765 		.ascii "ungetc\0"
 1092      746300
 1093 0828 01       		.byte	0x1
 1094 0829 CD02     		.word	0x2cd
 1095 082b 0F       		.byte	0xf
 1096 082c C0020000 		.long	0x2c0
 1097 0830 3F080000 		.long	0x83f
 1098 0834 0F       		.uleb128 0xf
 1099 0835 C0020000 		.long	0x2c0
 1100 0839 0F       		.uleb128 0xf
 1101 083a E8030000 		.long	0x3e8
 1102 083e 00       		.byte	0
 1103 083f 11       		.uleb128 0x11
 1104 0840 76667072 		.ascii "vfprintf\0"
 1104      696E7466 
 1104      00
 1105 0849 01       		.byte	0x1
 1106 084a 6F01     		.word	0x16f
 1107 084c 05       		.byte	0x5
 1108 084d 5F5A3876 		.ascii "_Z8vfprintfP6_iobufPKcPc\0"
 1108      66707269 
 1108      6E746650 
 1108      365F696F 
 1108      62756650 
 1109 0866 C0020000 		.long	0x2c0
 1110 086a 7E080000 		.long	0x87e
 1111 086e 0F       		.uleb128 0xf
 1112 086f E8030000 		.long	0x3e8
 1113 0873 0F       		.uleb128 0xf
 1114 0874 D4040000 		.long	0x4d4
 1115 0878 0F       		.uleb128 0xf
 1116 0879 4B020000 		.long	0x24b
 1117 087d 00       		.byte	0
 1118 087e 11       		.uleb128 0x11
 1119 087f 76707269 		.ascii "vprintf\0"
 1119      6E746600 
 1120 0887 01       		.byte	0x1
 1121 0888 7601     		.word	0x176
 1122 088a 05       		.byte	0x5
 1123 088b 5F5A3776 		.ascii "_Z7vprintfPKcPc\0"
 1123      7072696E 
 1123      7466504B 
 1123      63506300 
 1124 089b C0020000 		.long	0x2c0
 1125 089f AE080000 		.long	0x8ae
 1126 08a3 0F       		.uleb128 0xf
 1127 08a4 D4040000 		.long	0x4d4
 1128 08a8 0F       		.uleb128 0xf
 1129 08a9 4B020000 		.long	0x24b
 1130 08ad 00       		.byte	0
 1131 08ae 11       		.uleb128 0x11
 1132 08af 76737072 		.ascii "vsprintf\0"
 1132      696E7466 
 1132      00
 1133 08b8 01       		.byte	0x1
 1134 08b9 7D01     		.word	0x17d
 1135 08bb 05       		.byte	0x5
 1136 08bc 5F5A3876 		.ascii "_Z8vsprintfPcPKcS_\0"
 1136      73707269 
 1136      6E746650 
 1136      63504B63 
 1136      535F00
 1137 08cf C0020000 		.long	0x2c0
 1138 08d3 E7080000 		.long	0x8e7
 1139 08d7 0F       		.uleb128 0xf
 1140 08d8 D8020000 		.long	0x2d8
 1141 08dc 0F       		.uleb128 0xf
 1142 08dd D4040000 		.long	0x4d4
 1143 08e1 0F       		.uleb128 0xf
 1144 08e2 4B020000 		.long	0x24b
 1145 08e6 00       		.byte	0
 1146 08e7 11       		.uleb128 0x11
 1147 08e8 736E7072 		.ascii "snprintf\0"
 1147      696E7466 
 1147      00
 1148 08f1 01       		.byte	0x1
 1149 08f2 8401     		.word	0x184
 1150 08f4 05       		.byte	0x5
 1151 08f5 5F5A3873 		.ascii "_Z8snprintfPcyPKcz\0"
 1151      6E707269 
 1151      6E746650 
 1151      6379504B 
 1151      637A00
 1152 0908 C0020000 		.long	0x2c0
 1153 090c 21090000 		.long	0x921
 1154 0910 0F       		.uleb128 0xf
 1155 0911 D8020000 		.long	0x2d8
 1156 0915 0F       		.uleb128 0xf
 1157 0916 70020000 		.long	0x270
 1158 091a 0F       		.uleb128 0xf
 1159 091b D4040000 		.long	0x4d4
 1160 091f 12       		.uleb128 0x12
 1161 0920 00       		.byte	0
 1162 0921 11       		.uleb128 0x11
 1163 0922 76667363 		.ascii "vfscanf\0"
 1163      616E6600 
 1164 092a 01       		.byte	0x1
 1165 092b 4001     		.word	0x140
 1166 092d 05       		.byte	0x5
 1167 092e 5F5A3776 		.ascii "_Z7vfscanfP6_iobufPKcPc\0"
 1167      66736361 
 1167      6E665036 
 1167      5F696F62 
 1167      7566504B 
 1168 0946 C0020000 		.long	0x2c0
 1169 094a 5E090000 		.long	0x95e
 1170 094e 0F       		.uleb128 0xf
 1171 094f E8030000 		.long	0x3e8
 1172 0953 0F       		.uleb128 0xf
 1173 0954 D4040000 		.long	0x4d4
 1174 0958 0F       		.uleb128 0xf
 1175 0959 4B020000 		.long	0x24b
 1176 095d 00       		.byte	0
 1177 095e 11       		.uleb128 0x11
 1178 095f 76736361 		.ascii "vscanf\0"
 1178      6E6600
 1179 0966 01       		.byte	0x1
 1180 0967 3901     		.word	0x139
 1181 0969 05       		.byte	0x5
 1182 096a 5F5A3676 		.ascii "_Z6vscanfPKcPc\0"
 1182      7363616E 
 1182      66504B63 
 1182      506300
 1183 0979 C0020000 		.long	0x2c0
 1184 097d 8C090000 		.long	0x98c
 1185 0981 0F       		.uleb128 0xf
 1186 0982 D4040000 		.long	0x4d4
 1187 0986 0F       		.uleb128 0xf
 1188 0987 4B020000 		.long	0x24b
 1189 098b 00       		.byte	0
 1190 098c 11       		.uleb128 0x11
 1191 098d 76736E70 		.ascii "vsnprintf\0"
 1191      72696E74 
 1191      6600
 1192 0997 01       		.byte	0x1
 1193 0998 8F01     		.word	0x18f
 1194 099a 05       		.byte	0x5
 1195 099b 5F5A3976 		.ascii "_Z9vsnprintfPcyPKcS_\0"
 1195      736E7072 
 1195      696E7466 
 1195      50637950 
 1195      4B63535F 
 1196 09b0 C0020000 		.long	0x2c0
 1197 09b4 CD090000 		.long	0x9cd
 1198 09b8 0F       		.uleb128 0xf
 1199 09b9 D8020000 		.long	0x2d8
 1200 09bd 0F       		.uleb128 0xf
 1201 09be 70020000 		.long	0x270
 1202 09c2 0F       		.uleb128 0xf
 1203 09c3 D4040000 		.long	0x4d4
 1204 09c7 0F       		.uleb128 0xf
 1205 09c8 4B020000 		.long	0x24b
 1206 09cc 00       		.byte	0
 1207 09cd 11       		.uleb128 0x11
 1208 09ce 76737363 		.ascii "vsscanf\0"
 1208      616E6600 
 1209 09d6 01       		.byte	0x1
 1210 09d7 3201     		.word	0x132
 1211 09d9 05       		.byte	0x5
 1212 09da 5F5A3776 		.ascii "_Z7vsscanfPKcS0_Pc\0"
 1212      73736361 
 1212      6E66504B 
 1212      6353305F 
 1212      506300
 1213 09ed C0020000 		.long	0x2c0
 1214 09f1 050A0000 		.long	0xa05
 1215 09f5 0F       		.uleb128 0xf
 1216 09f6 D4040000 		.long	0x4d4
 1217 09fa 0F       		.uleb128 0xf
 1218 09fb D4040000 		.long	0x4d4
 1219 09ff 0F       		.uleb128 0xf
 1220 0a00 4B020000 		.long	0x24b
 1221 0a04 00       		.byte	0
 1222 0a05 19       		.uleb128 0x19
 1223 0a06 02       		.byte	0x2
 1224 0a07 03       		.byte	0x3
 1225 0a08 11       		.byte	0x11
 1226 0a09 87000000 		.long	0x87
 1227 0a0d 1A       		.uleb128 0x1a
 1228 0a0e 6D61786E 		.ascii "maxn\0"
 1228      00
 1229 0a13 02       		.byte	0x2
 1230 0a14 05       		.byte	0x5
 1231 0a15 0B       		.byte	0xb
 1232 0a16 C7020000 		.long	0x2c7
 1233 0a1a 09       		.uleb128 0x9
 1234 0a1b 03       		.byte	0x3
 1235 0a1c 00000000 		.quad	_ZL4maxn
 1235      00000000 
 1236 0a24 1B       		.uleb128 0x1b
 1237 0a25 63020000 		.long	0x263
 1238 0a29 370A0000 		.long	0xa37
 1239 0a2d 1C       		.uleb128 0x1c
 1240 0a2e 7F020000 		.long	0x27f
 1241 0a32 FFFF0100 		.long	0x1ffff
 1242 0a36 00       		.byte	0
 1243 0a37 1D       		.uleb128 0x1d
 1244 0a38 62756666 		.ascii "buffer\0"
 1244      657200
 1245 0a3f 02       		.byte	0x2
 1246 0a40 07       		.byte	0x7
 1247 0a41 06       		.byte	0x6
 1248 0a42 240A0000 		.long	0xa24
 1249 0a46 09       		.uleb128 0x9
 1250 0a47 03       		.byte	0x3
 1251 0a48 00000000 		.quad	buffer
 1251      00000000 
 1252 0a50 1D       		.uleb128 0x1d
 1253 0a51 5300     		.ascii "S\0"
 1254 0a53 02       		.byte	0x2
 1255 0a54 07       		.byte	0x7
 1256 0a55 15       		.byte	0x15
 1257 0a56 D8020000 		.long	0x2d8
 1258 0a5a 09       		.uleb128 0x9
 1259 0a5b 03       		.byte	0x3
 1260 0a5c 00000200 		.quad	S
 1260      00000000 
 1261 0a64 1D       		.uleb128 0x1d
 1262 0a65 5400     		.ascii "T\0"
 1263 0a67 02       		.byte	0x2
 1264 0a68 07       		.byte	0x7
 1265 0a69 19       		.byte	0x19
 1266 0a6a D8020000 		.long	0x2d8
 1267 0a6e 09       		.uleb128 0x9
 1268 0a6f 03       		.byte	0x3
 1269 0a70 08000200 		.quad	T
 1269      00000000 
 1270 0a78 1E       		.uleb128 0x1e
 1271 0a79 6D61696E 		.ascii "main\0"
 1271      00
 1272 0a7e 02       		.byte	0x2
 1273 0a7f 1D       		.byte	0x1d
 1274 0a80 05       		.byte	0x5
 1275 0a81 C0020000 		.long	0x2c0
 1276 0a85 04010000 		.quad	.LFB46
 1276      00000000 
 1277 0a8d 31000000 		.quad	.LFE46-.LFB46
 1277      00000000 
 1278 0a95 01       		.uleb128 0x1
 1279 0a96 9C       		.byte	0x9c
 1280 0a97 A90A0000 		.long	0xaa9
 1281 0a9b 1A       		.uleb128 0x1a
 1282 0a9c 6100     		.ascii "a\0"
 1283 0a9e 02       		.byte	0x2
 1284 0a9f 1F       		.byte	0x1f
 1285 0aa0 06       		.byte	0x6
 1286 0aa1 C0020000 		.long	0x2c0
 1287 0aa5 02       		.uleb128 0x2
 1288 0aa6 91       		.byte	0x91
 1289 0aa7 6C       		.sleb128 -20
 1290 0aa8 00       		.byte	0
 1291 0aa9 1F       		.uleb128 0x1f
 1292 0aaa 4765745F 		.ascii "Get_Int\0"
 1292      496E7400 
 1293 0ab2 02       		.byte	0x2
 1294 0ab3 12       		.byte	0x12
 1295 0ab4 05       		.byte	0x5
 1296 0ab5 5F5A3747 		.ascii "_Z7Get_Intv\0"
 1296      65745F49 
 1296      6E747600 
 1297 0ac1 C0020000 		.long	0x2c0
 1298 0ac5 9E000000 		.quad	.LFB45
 1298      00000000 
 1299 0acd 66000000 		.quad	.LFE45-.LFB45
 1299      00000000 
 1300 0ad5 01       		.uleb128 0x1
 1301 0ad6 9C       		.byte	0x9c
 1302 0ad7 F70A0000 		.long	0xaf7
 1303 0adb 1A       		.uleb128 0x1a
 1304 0adc 6300     		.ascii "c\0"
 1305 0ade 02       		.byte	0x2
 1306 0adf 14       		.byte	0x14
 1307 0ae0 07       		.byte	0x7
 1308 0ae1 63020000 		.long	0x263
 1309 0ae5 02       		.uleb128 0x2
 1310 0ae6 91       		.byte	0x91
 1311 0ae7 6F       		.sleb128 -17
 1312 0ae8 1A       		.uleb128 0x1a
 1313 0ae9 726500   		.ascii "re\0"
 1314 0aec 02       		.byte	0x2
 1315 0aed 15       		.byte	0x15
 1316 0aee 06       		.byte	0x6
 1317 0aef C0020000 		.long	0x2c0
 1318 0af3 02       		.uleb128 0x2
 1319 0af4 91       		.byte	0x91
 1320 0af5 68       		.sleb128 -24
 1321 0af6 00       		.byte	0
 1322 0af7 1F       		.uleb128 0x1f
 1323 0af8 4765745F 		.ascii "Get_Char\0"
 1323      43686172 
 1323      00
 1324 0b01 02       		.byte	0x2
 1325 0b02 08       		.byte	0x8
 1326 0b03 06       		.byte	0x6
 1327 0b04 5F5A3847 		.ascii "_Z8Get_Charv\0"
 1327      65745F43 
 1327      68617276 
 1327      00
 1328 0b11 63020000 		.long	0x263
 1329 0b15 00000000 		.quad	.LFB44
 1329      00000000 
 1330 0b1d 9E000000 		.quad	.LFE44-.LFB44
 1330      00000000 
 1331 0b25 01       		.uleb128 0x1
 1332 0b26 9C       		.byte	0x9c
 1333 0b27 390B0000 		.long	0xb39
 1334 0b2b 18       		.uleb128 0x18
 1335 0b2c 44000000 		.quad	.LVL1
 1335      00000000 
 1336 0b34 390B0000 		.long	0xb39
 1337 0b38 00       		.byte	0
 1338 0b39 20       		.uleb128 0x20
 1339 0b3a 00000000 		.secrel32	.LASF0
 1340 0b3e 00000000 		.secrel32	.LASF0
 1341 0b42 01       		.byte	0x1
 1342 0b43 52       		.byte	0x52
 1343 0b44 17       		.byte	0x17
 1344 0b45 00       		.byte	0
 1345              		.section	.debug_abbrev,"dr"
 1346              	.Ldebug_abbrev0:
 1347 0000 01       		.uleb128 0x1
 1348 0001 11       		.uleb128 0x11
 1349 0002 01       		.byte	0x1
 1350 0003 25       		.uleb128 0x25
 1351 0004 08       		.uleb128 0x8
 1352 0005 13       		.uleb128 0x13
 1353 0006 0B       		.uleb128 0xb
 1354 0007 03       		.uleb128 0x3
 1355 0008 08       		.uleb128 0x8
 1356 0009 1B       		.uleb128 0x1b
 1357 000a 08       		.uleb128 0x8
 1358 000b 55       		.uleb128 0x55
 1359 000c 17       		.uleb128 0x17
 1360 000d 11       		.uleb128 0x11
 1361 000e 01       		.uleb128 0x1
 1362 000f 10       		.uleb128 0x10
 1363 0010 17       		.uleb128 0x17
 1364 0011 00       		.byte	0
 1365 0012 00       		.byte	0
 1366 0013 02       		.uleb128 0x2
 1367 0014 39       		.uleb128 0x39
 1368 0015 01       		.byte	0x1
 1369 0016 03       		.uleb128 0x3
 1370 0017 08       		.uleb128 0x8
 1371 0018 3A       		.uleb128 0x3a
 1372 0019 0B       		.uleb128 0xb
 1373 001a 3B       		.uleb128 0x3b
 1374 001b 0B       		.uleb128 0xb
 1375 001c 01       		.uleb128 0x1
 1376 001d 13       		.uleb128 0x13
 1377 001e 00       		.byte	0
 1378 001f 00       		.byte	0
 1379 0020 03       		.uleb128 0x3
 1380 0021 39       		.uleb128 0x39
 1381 0022 00       		.byte	0
 1382 0023 03       		.uleb128 0x3
 1383 0024 08       		.uleb128 0x8
 1384 0025 3A       		.uleb128 0x3a
 1385 0026 0B       		.uleb128 0xb
 1386 0027 3B       		.uleb128 0x3b
 1387 0028 05       		.uleb128 0x5
 1388 0029 39       		.uleb128 0x39
 1389 002a 0B       		.uleb128 0xb
 1390 002b 8901     		.uleb128 0x89
 1391 002d 19       		.uleb128 0x19
 1392 002e 00       		.byte	0
 1393 002f 00       		.byte	0
 1394 0030 04       		.uleb128 0x4
 1395 0031 3A       		.uleb128 0x3a
 1396 0032 00       		.byte	0
 1397 0033 3A       		.uleb128 0x3a
 1398 0034 0B       		.uleb128 0xb
 1399 0035 3B       		.uleb128 0x3b
 1400 0036 05       		.uleb128 0x5
 1401 0037 39       		.uleb128 0x39
 1402 0038 0B       		.uleb128 0xb
 1403 0039 18       		.uleb128 0x18
 1404 003a 13       		.uleb128 0x13
 1405 003b 00       		.byte	0
 1406 003c 00       		.byte	0
 1407 003d 05       		.uleb128 0x5
 1408 003e 08       		.uleb128 0x8
 1409 003f 00       		.byte	0
 1410 0040 3A       		.uleb128 0x3a
 1411 0041 0B       		.uleb128 0xb
 1412 0042 3B       		.uleb128 0x3b
 1413 0043 0B       		.uleb128 0xb
 1414 0044 39       		.uleb128 0x39
 1415 0045 0B       		.uleb128 0xb
 1416 0046 18       		.uleb128 0x18
 1417 0047 13       		.uleb128 0x13
 1418 0048 00       		.byte	0
 1419 0049 00       		.byte	0
 1420 004a 06       		.uleb128 0x6
 1421 004b 39       		.uleb128 0x39
 1422 004c 01       		.byte	0x1
 1423 004d 03       		.uleb128 0x3
 1424 004e 08       		.uleb128 0x8
 1425 004f 3A       		.uleb128 0x3a
 1426 0050 0B       		.uleb128 0xb
 1427 0051 3B       		.uleb128 0x3b
 1428 0052 05       		.uleb128 0x5
 1429 0053 39       		.uleb128 0x39
 1430 0054 0B       		.uleb128 0xb
 1431 0055 01       		.uleb128 0x1
 1432 0056 13       		.uleb128 0x13
 1433 0057 00       		.byte	0
 1434 0058 00       		.byte	0
 1435 0059 07       		.uleb128 0x7
 1436 005a 0F       		.uleb128 0xf
 1437 005b 00       		.byte	0
 1438 005c 0B       		.uleb128 0xb
 1439 005d 0B       		.uleb128 0xb
 1440 005e 03       		.uleb128 0x3
 1441 005f 08       		.uleb128 0x8
 1442 0060 49       		.uleb128 0x49
 1443 0061 13       		.uleb128 0x13
 1444 0062 00       		.byte	0
 1445 0063 00       		.byte	0
 1446 0064 08       		.uleb128 0x8
 1447 0065 24       		.uleb128 0x24
 1448 0066 00       		.byte	0
 1449 0067 0B       		.uleb128 0xb
 1450 0068 0B       		.uleb128 0xb
 1451 0069 3E       		.uleb128 0x3e
 1452 006a 0B       		.uleb128 0xb
 1453 006b 03       		.uleb128 0x3
 1454 006c 08       		.uleb128 0x8
 1455 006d 00       		.byte	0
 1456 006e 00       		.byte	0
 1457 006f 09       		.uleb128 0x9
 1458 0070 26       		.uleb128 0x26
 1459 0071 00       		.byte	0
 1460 0072 49       		.uleb128 0x49
 1461 0073 13       		.uleb128 0x13
 1462 0074 00       		.byte	0
 1463 0075 00       		.byte	0
 1464 0076 0A       		.uleb128 0xa
 1465 0077 16       		.uleb128 0x16
 1466 0078 00       		.byte	0
 1467 0079 03       		.uleb128 0x3
 1468 007a 08       		.uleb128 0x8
 1469 007b 3A       		.uleb128 0x3a
 1470 007c 0B       		.uleb128 0xb
 1471 007d 3B       		.uleb128 0x3b
 1472 007e 0B       		.uleb128 0xb
 1473 007f 39       		.uleb128 0x39
 1474 0080 0B       		.uleb128 0xb
 1475 0081 49       		.uleb128 0x49
 1476 0082 13       		.uleb128 0x13
 1477 0083 00       		.byte	0
 1478 0084 00       		.byte	0
 1479 0085 0B       		.uleb128 0xb
 1480 0086 0F       		.uleb128 0xf
 1481 0087 00       		.byte	0
 1482 0088 0B       		.uleb128 0xb
 1483 0089 0B       		.uleb128 0xb
 1484 008a 49       		.uleb128 0x49
 1485 008b 13       		.uleb128 0x13
 1486 008c 00       		.byte	0
 1487 008d 00       		.byte	0
 1488 008e 0C       		.uleb128 0xc
 1489 008f 13       		.uleb128 0x13
 1490 0090 01       		.byte	0x1
 1491 0091 03       		.uleb128 0x3
 1492 0092 08       		.uleb128 0x8
 1493 0093 0B       		.uleb128 0xb
 1494 0094 0B       		.uleb128 0xb
 1495 0095 3A       		.uleb128 0x3a
 1496 0096 0B       		.uleb128 0xb
 1497 0097 3B       		.uleb128 0x3b
 1498 0098 0B       		.uleb128 0xb
 1499 0099 39       		.uleb128 0x39
 1500 009a 0B       		.uleb128 0xb
 1501 009b 01       		.uleb128 0x1
 1502 009c 13       		.uleb128 0x13
 1503 009d 00       		.byte	0
 1504 009e 00       		.byte	0
 1505 009f 0D       		.uleb128 0xd
 1506 00a0 0D       		.uleb128 0xd
 1507 00a1 00       		.byte	0
 1508 00a2 03       		.uleb128 0x3
 1509 00a3 08       		.uleb128 0x8
 1510 00a4 3A       		.uleb128 0x3a
 1511 00a5 0B       		.uleb128 0xb
 1512 00a6 3B       		.uleb128 0x3b
 1513 00a7 0B       		.uleb128 0xb
 1514 00a8 39       		.uleb128 0x39
 1515 00a9 0B       		.uleb128 0xb
 1516 00aa 49       		.uleb128 0x49
 1517 00ab 13       		.uleb128 0x13
 1518 00ac 38       		.uleb128 0x38
 1519 00ad 0B       		.uleb128 0xb
 1520 00ae 00       		.byte	0
 1521 00af 00       		.byte	0
 1522 00b0 0E       		.uleb128 0xe
 1523 00b1 2E       		.uleb128 0x2e
 1524 00b2 01       		.byte	0x1
 1525 00b3 3F       		.uleb128 0x3f
 1526 00b4 19       		.uleb128 0x19
 1527 00b5 03       		.uleb128 0x3
 1528 00b6 08       		.uleb128 0x8
 1529 00b7 3A       		.uleb128 0x3a
 1530 00b8 0B       		.uleb128 0xb
 1531 00b9 3B       		.uleb128 0x3b
 1532 00ba 05       		.uleb128 0x5
 1533 00bb 39       		.uleb128 0x39
 1534 00bc 0B       		.uleb128 0xb
 1535 00bd 3C       		.uleb128 0x3c
 1536 00be 19       		.uleb128 0x19
 1537 00bf 01       		.uleb128 0x1
 1538 00c0 13       		.uleb128 0x13
 1539 00c1 00       		.byte	0
 1540 00c2 00       		.byte	0
 1541 00c3 0F       		.uleb128 0xf
 1542 00c4 05       		.uleb128 0x5
 1543 00c5 00       		.byte	0
 1544 00c6 49       		.uleb128 0x49
 1545 00c7 13       		.uleb128 0x13
 1546 00c8 00       		.byte	0
 1547 00c9 00       		.byte	0
 1548 00ca 10       		.uleb128 0x10
 1549 00cb 2E       		.uleb128 0x2e
 1550 00cc 01       		.byte	0x1
 1551 00cd 3F       		.uleb128 0x3f
 1552 00ce 19       		.uleb128 0x19
 1553 00cf 03       		.uleb128 0x3
 1554 00d0 08       		.uleb128 0x8
 1555 00d1 3A       		.uleb128 0x3a
 1556 00d2 0B       		.uleb128 0xb
 1557 00d3 3B       		.uleb128 0x3b
 1558 00d4 05       		.uleb128 0x5
 1559 00d5 39       		.uleb128 0x39
 1560 00d6 0B       		.uleb128 0xb
 1561 00d7 49       		.uleb128 0x49
 1562 00d8 13       		.uleb128 0x13
 1563 00d9 3C       		.uleb128 0x3c
 1564 00da 19       		.uleb128 0x19
 1565 00db 01       		.uleb128 0x1
 1566 00dc 13       		.uleb128 0x13
 1567 00dd 00       		.byte	0
 1568 00de 00       		.byte	0
 1569 00df 11       		.uleb128 0x11
 1570 00e0 2E       		.uleb128 0x2e
 1571 00e1 01       		.byte	0x1
 1572 00e2 3F       		.uleb128 0x3f
 1573 00e3 19       		.uleb128 0x19
 1574 00e4 03       		.uleb128 0x3
 1575 00e5 08       		.uleb128 0x8
 1576 00e6 3A       		.uleb128 0x3a
 1577 00e7 0B       		.uleb128 0xb
 1578 00e8 3B       		.uleb128 0x3b
 1579 00e9 05       		.uleb128 0x5
 1580 00ea 39       		.uleb128 0x39
 1581 00eb 0B       		.uleb128 0xb
 1582 00ec 6E       		.uleb128 0x6e
 1583 00ed 08       		.uleb128 0x8
 1584 00ee 49       		.uleb128 0x49
 1585 00ef 13       		.uleb128 0x13
 1586 00f0 3C       		.uleb128 0x3c
 1587 00f1 19       		.uleb128 0x19
 1588 00f2 01       		.uleb128 0x1
 1589 00f3 13       		.uleb128 0x13
 1590 00f4 00       		.byte	0
 1591 00f5 00       		.byte	0
 1592 00f6 12       		.uleb128 0x12
 1593 00f7 18       		.uleb128 0x18
 1594 00f8 00       		.byte	0
 1595 00f9 00       		.byte	0
 1596 00fa 00       		.byte	0
 1597 00fb 13       		.uleb128 0x13
 1598 00fc 0F       		.uleb128 0xf
 1599 00fd 00       		.byte	0
 1600 00fe 0B       		.uleb128 0xb
 1601 00ff 0B       		.uleb128 0xb
 1602 0100 00       		.byte	0
 1603 0101 00       		.byte	0
 1604 0102 14       		.uleb128 0x14
 1605 0103 2E       		.uleb128 0x2e
 1606 0104 00       		.byte	0
 1607 0105 3F       		.uleb128 0x3f
 1608 0106 19       		.uleb128 0x19
 1609 0107 03       		.uleb128 0x3
 1610 0108 08       		.uleb128 0x8
 1611 0109 3A       		.uleb128 0x3a
 1612 010a 0B       		.uleb128 0xb
 1613 010b 3B       		.uleb128 0x3b
 1614 010c 05       		.uleb128 0x5
 1615 010d 39       		.uleb128 0x39
 1616 010e 0B       		.uleb128 0xb
 1617 010f 49       		.uleb128 0x49
 1618 0110 13       		.uleb128 0x13
 1619 0111 3C       		.uleb128 0x3c
 1620 0112 19       		.uleb128 0x19
 1621 0113 00       		.byte	0
 1622 0114 00       		.byte	0
 1623 0115 15       		.uleb128 0x15
 1624 0116 2E       		.uleb128 0x2e
 1625 0117 01       		.byte	0x1
 1626 0118 3F       		.uleb128 0x3f
 1627 0119 19       		.uleb128 0x19
 1628 011a 03       		.uleb128 0x3
 1629 011b 08       		.uleb128 0x8
 1630 011c 3A       		.uleb128 0x3a
 1631 011d 0B       		.uleb128 0xb
 1632 011e 3B       		.uleb128 0x3b
 1633 011f 05       		.uleb128 0x5
 1634 0120 39       		.uleb128 0x39
 1635 0121 0B       		.uleb128 0xb
 1636 0122 6E       		.uleb128 0x6e
 1637 0123 08       		.uleb128 0x8
 1638 0124 49       		.uleb128 0x49
 1639 0125 13       		.uleb128 0x13
 1640 0126 11       		.uleb128 0x11
 1641 0127 01       		.uleb128 0x1
 1642 0128 12       		.uleb128 0x12
 1643 0129 07       		.uleb128 0x7
 1644 012a 40       		.uleb128 0x40
 1645 012b 18       		.uleb128 0x18
 1646 012c 9642     		.uleb128 0x2116
 1647 012e 19       		.uleb128 0x19
 1648 012f 01       		.uleb128 0x1
 1649 0130 13       		.uleb128 0x13
 1650 0131 00       		.byte	0
 1651 0132 00       		.byte	0
 1652 0133 16       		.uleb128 0x16
 1653 0134 05       		.uleb128 0x5
 1654 0135 00       		.byte	0
 1655 0136 03       		.uleb128 0x3
 1656 0137 08       		.uleb128 0x8
 1657 0138 3A       		.uleb128 0x3a
 1658 0139 0B       		.uleb128 0xb
 1659 013a 3B       		.uleb128 0x3b
 1660 013b 05       		.uleb128 0x5
 1661 013c 39       		.uleb128 0x39
 1662 013d 0B       		.uleb128 0xb
 1663 013e 49       		.uleb128 0x49
 1664 013f 13       		.uleb128 0x13
 1665 0140 02       		.uleb128 0x2
 1666 0141 18       		.uleb128 0x18
 1667 0142 00       		.byte	0
 1668 0143 00       		.byte	0
 1669 0144 17       		.uleb128 0x17
 1670 0145 34       		.uleb128 0x34
 1671 0146 00       		.byte	0
 1672 0147 03       		.uleb128 0x3
 1673 0148 08       		.uleb128 0x8
 1674 0149 3A       		.uleb128 0x3a
 1675 014a 0B       		.uleb128 0xb
 1676 014b 3B       		.uleb128 0x3b
 1677 014c 05       		.uleb128 0x5
 1678 014d 39       		.uleb128 0x39
 1679 014e 0B       		.uleb128 0xb
 1680 014f 49       		.uleb128 0x49
 1681 0150 13       		.uleb128 0x13
 1682 0151 02       		.uleb128 0x2
 1683 0152 18       		.uleb128 0x18
 1684 0153 00       		.byte	0
 1685 0154 00       		.byte	0
 1686 0155 18       		.uleb128 0x18
 1687 0156 898201   		.uleb128 0x4109
 1688 0159 00       		.byte	0
 1689 015a 11       		.uleb128 0x11
 1690 015b 01       		.uleb128 0x1
 1691 015c 31       		.uleb128 0x31
 1692 015d 13       		.uleb128 0x13
 1693 015e 00       		.byte	0
 1694 015f 00       		.byte	0
 1695 0160 19       		.uleb128 0x19
 1696 0161 3A       		.uleb128 0x3a
 1697 0162 00       		.byte	0
 1698 0163 3A       		.uleb128 0x3a
 1699 0164 0B       		.uleb128 0xb
 1700 0165 3B       		.uleb128 0x3b
 1701 0166 0B       		.uleb128 0xb
 1702 0167 39       		.uleb128 0x39
 1703 0168 0B       		.uleb128 0xb
 1704 0169 18       		.uleb128 0x18
 1705 016a 13       		.uleb128 0x13
 1706 016b 00       		.byte	0
 1707 016c 00       		.byte	0
 1708 016d 1A       		.uleb128 0x1a
 1709 016e 34       		.uleb128 0x34
 1710 016f 00       		.byte	0
 1711 0170 03       		.uleb128 0x3
 1712 0171 08       		.uleb128 0x8
 1713 0172 3A       		.uleb128 0x3a
 1714 0173 0B       		.uleb128 0xb
 1715 0174 3B       		.uleb128 0x3b
 1716 0175 0B       		.uleb128 0xb
 1717 0176 39       		.uleb128 0x39
 1718 0177 0B       		.uleb128 0xb
 1719 0178 49       		.uleb128 0x49
 1720 0179 13       		.uleb128 0x13
 1721 017a 02       		.uleb128 0x2
 1722 017b 18       		.uleb128 0x18
 1723 017c 00       		.byte	0
 1724 017d 00       		.byte	0
 1725 017e 1B       		.uleb128 0x1b
 1726 017f 01       		.uleb128 0x1
 1727 0180 01       		.byte	0x1
 1728 0181 49       		.uleb128 0x49
 1729 0182 13       		.uleb128 0x13
 1730 0183 01       		.uleb128 0x1
 1731 0184 13       		.uleb128 0x13
 1732 0185 00       		.byte	0
 1733 0186 00       		.byte	0
 1734 0187 1C       		.uleb128 0x1c
 1735 0188 21       		.uleb128 0x21
 1736 0189 00       		.byte	0
 1737 018a 49       		.uleb128 0x49
 1738 018b 13       		.uleb128 0x13
 1739 018c 2F       		.uleb128 0x2f
 1740 018d 06       		.uleb128 0x6
 1741 018e 00       		.byte	0
 1742 018f 00       		.byte	0
 1743 0190 1D       		.uleb128 0x1d
 1744 0191 34       		.uleb128 0x34
 1745 0192 00       		.byte	0
 1746 0193 03       		.uleb128 0x3
 1747 0194 08       		.uleb128 0x8
 1748 0195 3A       		.uleb128 0x3a
 1749 0196 0B       		.uleb128 0xb
 1750 0197 3B       		.uleb128 0x3b
 1751 0198 0B       		.uleb128 0xb
 1752 0199 39       		.uleb128 0x39
 1753 019a 0B       		.uleb128 0xb
 1754 019b 49       		.uleb128 0x49
 1755 019c 13       		.uleb128 0x13
 1756 019d 3F       		.uleb128 0x3f
 1757 019e 19       		.uleb128 0x19
 1758 019f 02       		.uleb128 0x2
 1759 01a0 18       		.uleb128 0x18
 1760 01a1 00       		.byte	0
 1761 01a2 00       		.byte	0
 1762 01a3 1E       		.uleb128 0x1e
 1763 01a4 2E       		.uleb128 0x2e
 1764 01a5 01       		.byte	0x1
 1765 01a6 3F       		.uleb128 0x3f
 1766 01a7 19       		.uleb128 0x19
 1767 01a8 03       		.uleb128 0x3
 1768 01a9 08       		.uleb128 0x8
 1769 01aa 3A       		.uleb128 0x3a
 1770 01ab 0B       		.uleb128 0xb
 1771 01ac 3B       		.uleb128 0x3b
 1772 01ad 0B       		.uleb128 0xb
 1773 01ae 39       		.uleb128 0x39
 1774 01af 0B       		.uleb128 0xb
 1775 01b0 49       		.uleb128 0x49
 1776 01b1 13       		.uleb128 0x13
 1777 01b2 11       		.uleb128 0x11
 1778 01b3 01       		.uleb128 0x1
 1779 01b4 12       		.uleb128 0x12
 1780 01b5 07       		.uleb128 0x7
 1781 01b6 40       		.uleb128 0x40
 1782 01b7 18       		.uleb128 0x18
 1783 01b8 9642     		.uleb128 0x2116
 1784 01ba 19       		.uleb128 0x19
 1785 01bb 01       		.uleb128 0x1
 1786 01bc 13       		.uleb128 0x13
 1787 01bd 00       		.byte	0
 1788 01be 00       		.byte	0
 1789 01bf 1F       		.uleb128 0x1f
 1790 01c0 2E       		.uleb128 0x2e
 1791 01c1 01       		.byte	0x1
 1792 01c2 3F       		.uleb128 0x3f
 1793 01c3 19       		.uleb128 0x19
 1794 01c4 03       		.uleb128 0x3
 1795 01c5 08       		.uleb128 0x8
 1796 01c6 3A       		.uleb128 0x3a
 1797 01c7 0B       		.uleb128 0xb
 1798 01c8 3B       		.uleb128 0x3b
 1799 01c9 0B       		.uleb128 0xb
 1800 01ca 39       		.uleb128 0x39
 1801 01cb 0B       		.uleb128 0xb
 1802 01cc 6E       		.uleb128 0x6e
 1803 01cd 08       		.uleb128 0x8
 1804 01ce 49       		.uleb128 0x49
 1805 01cf 13       		.uleb128 0x13
 1806 01d0 11       		.uleb128 0x11
 1807 01d1 01       		.uleb128 0x1
 1808 01d2 12       		.uleb128 0x12
 1809 01d3 07       		.uleb128 0x7
 1810 01d4 40       		.uleb128 0x40
 1811 01d5 18       		.uleb128 0x18
 1812 01d6 9642     		.uleb128 0x2116
 1813 01d8 19       		.uleb128 0x19
 1814 01d9 01       		.uleb128 0x1
 1815 01da 13       		.uleb128 0x13
 1816 01db 00       		.byte	0
 1817 01dc 00       		.byte	0
 1818 01dd 20       		.uleb128 0x20
 1819 01de 2E       		.uleb128 0x2e
 1820 01df 00       		.byte	0
 1821 01e0 3F       		.uleb128 0x3f
 1822 01e1 19       		.uleb128 0x19
 1823 01e2 3C       		.uleb128 0x3c
 1824 01e3 19       		.uleb128 0x19
 1825 01e4 6E       		.uleb128 0x6e
 1826 01e5 0E       		.uleb128 0xe
 1827 01e6 03       		.uleb128 0x3
 1828 01e7 0E       		.uleb128 0xe
 1829 01e8 3A       		.uleb128 0x3a
 1830 01e9 0B       		.uleb128 0xb
 1831 01ea 3B       		.uleb128 0x3b
 1832 01eb 0B       		.uleb128 0xb
 1833 01ec 39       		.uleb128 0x39
 1834 01ed 0B       		.uleb128 0xb
 1835 01ee 00       		.byte	0
 1836 01ef 00       		.byte	0
 1837 01f0 00       		.byte	0
 1838              		.section	.debug_aranges,"dr"
 1839 0000 3C000000 		.long	0x3c
 1840 0004 0200     		.word	0x2
 1841 0006 00000000 		.secrel32	.Ldebug_info0
 1842 000a 08       		.byte	0x8
 1843 000b 00       		.byte	0
 1844 000c 0000     		.word	0
 1845 000e 0000     		.word	0
 1846 0010 00000000 		.quad	.Ltext0
 1846      00000000 
 1847 0018 35010000 		.quad	.Letext0-.Ltext0
 1847      00000000 
 1848 0020 00000000 		.quad	.LFB8
 1848      00000000 
 1849 0028 54000000 		.quad	.LFE8-.LFB8
 1849      00000000 
 1850 0030 00000000 		.quad	0
 1850      00000000 
 1851 0038 00000000 		.quad	0
 1851      00000000 
 1852              		.section	.debug_ranges,"dr"
 1853              	.Ldebug_ranges0:
 1854 0000 00000000 		.quad	.Ltext0
 1854      00000000 
 1855 0008 35010000 		.quad	.Letext0
 1855      00000000 
 1856 0010 00000000 		.quad	.LFB8
 1856      00000000 
 1857 0018 54000000 		.quad	.LFE8
 1857      00000000 
 1858 0020 00000000 		.quad	0
 1858      00000000 
 1859 0028 00000000 		.quad	0
 1859      00000000 
 1860              		.section	.debug_line,"dr"
 1861              	.Ldebug_line0:
 1862 0000 95020000 		.section	.debug_str,"dr"
 1862      0200D501 
 1862      00000101 
 1862      FB0E0D00 
 1862      01010101 
 1863              	.LASF0:
 1864 0000 5F5F6163 		.ascii "__acrt_iob_func\0"
 1864      72745F69 
 1864      6F625F66 
 1864      756E6300 
 1865              		.ident	"GCC: (x86_64-win32-seh-rev0, Built by MinGW-W64 project) 8.1.0"
