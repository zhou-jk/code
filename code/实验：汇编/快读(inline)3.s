   1              		.file	"\277\354\266\301(inline).cpp"
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
  78 20010 00000000 		.section	.text$_Z8Get_Charv,"x"
  78      00000000 
  78      00000000 
  78      00000000 
  79              		.linkonce discard
  80              		.globl	_Z8Get_Charv
  82              		.seh_proc	_Z8Get_Charv
  83              	_Z8Get_Charv:
  84              	.LFB44:
  85              		.file 2 "C++/\312\265\321\351\243\272\273\343\261\340/\277\354\266\301(inline).cpp"
   1:C++/实验：汇编/快读(inline).cpp **** #include <cstdio>
   2:C++/实验：汇编/快读(inline).cpp **** 
   3:C++/实验：汇编/快读(inline).cpp **** const int maxn = 2 << 16;
   4:C++/实验：汇编/快读(inline).cpp **** 
   5:C++/实验：汇编/快读(inline).cpp **** char buffer[maxn], *S, *T;
   6:C++/实验：汇编/快读(inline).cpp **** inline char Get_Char()
   7:C++/实验：汇编/快读(inline).cpp **** {
  86              		.loc 2 7 1
  87              		.cfi_startproc
  88 0000 55       		pushq	%rbp
  89              		.seh_pushreg	%rbp
  90              		.cfi_def_cfa_offset 16
  91              		.cfi_offset 6, -16
  92 0001 53       		pushq	%rbx
  93              		.seh_pushreg	%rbx
  94              		.cfi_def_cfa_offset 24
  95              		.cfi_offset 3, -24
  96 0002 4883EC28 		subq	$40, %rsp
  97              		.seh_stackalloc	40
  98              		.cfi_def_cfa_offset 64
  99 0006 488DAC24 		leaq	128(%rsp), %rbp
  99      80000000 
 100              		.seh_setframe	%rbp, 128
 101              		.cfi_def_cfa 6, -64
 102              		.seh_endprologue
   8:C++/实验：汇编/快读(inline).cpp **** 	if (S == T)
 103              		.loc 2 8 8
 104 000e 488B1500 		movq	S(%rip), %rdx
 104      000200
 105 0015 488B0508 		movq	T(%rip), %rax
 105      000200
 106              		.loc 2 8 2
 107 001c 4839C2   		cmpq	%rax, %rdx
 108 001f 7561     		jne	.L4
   9:C++/实验：汇编/快读(inline).cpp **** 	{
  10:C++/实验：汇编/快读(inline).cpp **** 		T = (S = buffer) + fread(buffer, 1, maxn, stdin);
 109              		.loc 2 10 10
 110 0021 488D0500 		leaq	buffer(%rip), %rax
 110      000000
 111 0028 48890500 		movq	%rax, S(%rip)
 111      000200
 112 002f 488B1D00 		movq	S(%rip), %rbx
 112      000200
 113              		.loc 2 10 27
 114 0036 B9000000 		movl	$0, %ecx
 114      00
 115 003b 488B0500 		movq	__imp___acrt_iob_func(%rip), %rax
 115      000000
 116 0042 FFD0     		call	*%rax
 117              	.LVL1:
 118 0044 4989C1   		movq	%rax, %r9
 119 0047 41B80000 		movl	$131072, %r8d
 119      0200
 120 004d BA010000 		movl	$1, %edx
 120      00
 121 0052 488D0D00 		leaq	buffer(%rip), %rcx
 121      000000
 122 0059 E8000000 		call	fread
 122      00
 123              		.loc 2 10 20
 124 005e 4801D8   		addq	%rbx, %rax
 125              		.loc 2 10 5
 126 0061 48890508 		movq	%rax, T(%rip)
 126      000200
  11:C++/实验：汇编/快读(inline).cpp **** 		if (S == T) return EOF;
 127              		.loc 2 11 9
 128 0068 488B1500 		movq	S(%rip), %rdx
 128      000200
 129 006f 488B0508 		movq	T(%rip), %rax
 129      000200
 130              		.loc 2 11 3
 131 0076 4839C2   		cmpq	%rax, %rdx
 132 0079 7507     		jne	.L4
 133              		.loc 2 11 22 discriminator 1
 134 007b B8FFFFFF 		movl	$-1, %eax
 134      FF
 135 0080 EB15     		jmp	.L5
 136              	.L4:
  12:C++/实验：汇编/快读(inline).cpp **** 	}
  13:C++/实验：汇编/快读(inline).cpp **** 	return *S++;
 137              		.loc 2 13 11
 138 0082 488B0500 		movq	S(%rip), %rax
 138      000200
 139 0089 488D5001 		leaq	1(%rax), %rdx
 140 008d 48891500 		movq	%rdx, S(%rip)
 140      000200
 141 0094 0FB600   		movzbl	(%rax), %eax
 142              	.L5:
  14:C++/实验：汇编/快读(inline).cpp **** }
 143              		.loc 2 14 1
 144 0097 4883C428 		addq	$40, %rsp
 145 009b 5B       		popq	%rbx
 146              		.cfi_restore 3
 147 009c 5D       		popq	%rbp
 148              		.cfi_restore 6
 149              		.cfi_def_cfa 7, -24
 150 009d C3       		ret
 151              		.cfi_endproc
 152              	.LFE44:
 153              		.seh_endproc
 154 009e 9090     		.section	.text$_Z7Get_Intv,"x"
 155              		.linkonce discard
 156              		.globl	_Z7Get_Intv
 158              		.seh_proc	_Z7Get_Intv
 159              	_Z7Get_Intv:
 160              	.LFB45:
  15:C++/实验：汇编/快读(inline).cpp **** 
  16:C++/实验：汇编/快读(inline).cpp **** inline int Get_Int()
  17:C++/实验：汇编/快读(inline).cpp **** {
 161              		.loc 2 17 1
 162              		.cfi_startproc
 163 0000 55       		pushq	%rbp
 164              		.seh_pushreg	%rbp
 165              		.cfi_def_cfa_offset 16
 166              		.cfi_offset 6, -16
 167 0001 4889E5   		movq	%rsp, %rbp
 168              		.seh_setframe	%rbp, 0
 169              		.cfi_def_cfa_register 6
 170 0004 4883EC30 		subq	$48, %rsp
 171              		.seh_stackalloc	48
 172              		.seh_endprologue
  18:C++/实验：汇编/快读(inline).cpp **** 	char c;
  19:C++/实验：汇编/快读(inline).cpp **** 	int re = 0;
 173              		.loc 2 19 6
 174 0008 C745F800 		movl	$0, -8(%rbp)
 174      000000
  20:C++/实验：汇编/快读(inline).cpp **** 	for (c = Get_Char(); c < '0' || c > '9'; c = Get_Char())
 175              		.loc 2 20 19
 176 000f E8000000 		call	_Z8Get_Charv
 176      00
 177 0014 8845FF   		movb	%al, -1(%rbp)
 178              	.L9:
 179              		.loc 2 20 31 discriminator 5
 180 0017 807DFF2F 		cmpb	$47, -1(%rbp)
 181 001b 7E06     		jle	.L7
 182              		.loc 2 20 31 is_stmt 0 discriminator 2
 183 001d 807DFF39 		cmpb	$57, -1(%rbp)
 184 0021 7E0A     		jle	.L8
 185              	.L7:
 186              		.loc 2 20 55 is_stmt 1 discriminator 4
 187 0023 E8000000 		call	_Z8Get_Charv
 187      00
 188 0028 8845FF   		movb	%al, -1(%rbp)
 189              		.loc 2 20 2 discriminator 4
 190 002b EBEA     		jmp	.L9
 191              	.L8:
  21:C++/实验：汇编/快读(inline).cpp **** 		;
  22:C++/实验：汇编/快读(inline).cpp **** 	while (c >= '0' && c <= '9')
 192              		.loc 2 22 18
 193 002d 807DFF2F 		cmpb	$47, -1(%rbp)
 194 0031 7E2A     		jle	.L10
 195              		.loc 2 22 18 is_stmt 0 discriminator 1
 196 0033 807DFF39 		cmpb	$57, -1(%rbp)
 197 0037 7F24     		jg	.L10
  23:C++/实验：汇编/快读(inline).cpp **** 		re = (re << 1) + (re << 3) + (c - '0'), c = Get_Char();
 198              		.loc 2 23 12 is_stmt 1
 199 0039 8B45F8   		movl	-8(%rbp), %eax
 200 003c 8D1400   		leal	(%rax,%rax), %edx
 201              		.loc 2 23 24
 202 003f 8B45F8   		movl	-8(%rbp), %eax
 203 0042 C1E003   		sall	$3, %eax
 204              		.loc 2 23 18
 205 0045 01C2     		addl	%eax, %edx
 206              		.loc 2 23 35
 207 0047 0FBE45FF 		movsbl	-1(%rbp), %eax
 208 004b 83E830   		subl	$48, %eax
 209              		.loc 2 23 6
 210 004e 01D0     		addl	%edx, %eax
 211 0050 8945F8   		movl	%eax, -8(%rbp)
 212              		.loc 2 23 55
 213 0053 E8000000 		call	_Z8Get_Charv
 213      00
 214 0058 8845FF   		movb	%al, -1(%rbp)
  22:C++/实验：汇编/快读(inline).cpp **** 		re = (re << 1) + (re << 3) + (c - '0'), c = Get_Char();
 215              		.loc 2 22 2
 216 005b EBD0     		jmp	.L8
 217              	.L10:
  24:C++/实验：汇编/快读(inline).cpp **** 	return re;
 218              		.loc 2 24 9
 219 005d 8B45F8   		movl	-8(%rbp), %eax
  25:C++/实验：汇编/快读(inline).cpp **** }
 220              		.loc 2 25 1
 221 0060 4883C430 		addq	$48, %rsp
 222 0064 5D       		popq	%rbp
 223              		.cfi_restore 6
 224              		.cfi_def_cfa 7, 8
 225 0065 C3       		ret
 226              		.cfi_endproc
 227              	.LFE45:
 228              		.seh_endproc
 230 0066 90909090 		.section .rdata,"dr"
 230      90909090 
 230      9090
 231              	.LC0:
 232 0004 256400   		.ascii "%d\0"
 233 0007 00000000 		.text
 233      00000000 
 233      00
 234              		.globl	main
 236              		.seh_proc	main
 237              	main:
 238              	.LFB46:
  26:C++/实验：汇编/快读(inline).cpp **** 
  27:C++/实验：汇编/快读(inline).cpp **** int main()
  28:C++/实验：汇编/快读(inline).cpp **** {
 239              		.loc 2 28 1
 240              		.cfi_startproc
 241 0000 55       		pushq	%rbp
 242              		.seh_pushreg	%rbp
 243              		.cfi_def_cfa_offset 16
 244              		.cfi_offset 6, -16
 245 0001 4889E5   		movq	%rsp, %rbp
 246              		.seh_setframe	%rbp, 0
 247              		.cfi_def_cfa_register 6
 248 0004 4883EC30 		subq	$48, %rsp
 249              		.seh_stackalloc	48
 250              		.seh_endprologue
 251              		.loc 2 28 1
 252 0008 E8000000 		call	__main
 252      00
 253              	.LVL2:
  29:C++/实验：汇编/快读(inline).cpp **** 	int a = Get_Int();
 254              		.loc 2 29 17
 255 000d E8000000 		call	_Z7Get_Intv
 255      00
 256 0012 8945FC   		movl	%eax, -4(%rbp)
  30:C++/实验：汇编/快读(inline).cpp **** 	printf("%d", a);
 257              		.loc 2 30 8
 258 0015 8B45FC   		movl	-4(%rbp), %eax
 259 0018 89C2     		movl	%eax, %edx
 260 001a 488D0D04 		leaq	.LC0(%rip), %rcx
 260      000000
 261 0021 E8000000 		call	_Z6printfPKcz
 261      00
  31:C++/实验：汇编/快读(inline).cpp **** 	return 0;
 262              		.loc 2 31 9
 263 0026 B8000000 		movl	$0, %eax
 263      00
  32:C++/实验：汇编/快读(inline).cpp **** }...
 264              		.loc 2 32 1
 265 002b 4883C430 		addq	$48, %rsp
 266 002f 5D       		popq	%rbp
 267              		.cfi_restore 6
 268              		.cfi_def_cfa 7, 8
 269 0030 C3       		ret
 270              		.cfi_endproc
 271              	.LFE46:
 272              		.seh_endproc
 273              	.Letext0:
 274              		.file 3 "C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-m
 275              		.file 4 "C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-m
 276              		.file 5 "C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/i
 277              		.file 6 "<built-in>"
 278 0031 90909090 		.section	.debug_info,"dr"
 278      90909090 
 278      90909090 
 278      909090
 279              	.Ldebug_info0:
 280 0000 330B0000 		.long	0xb33
 281 0004 0400     		.word	0x4
 282 0006 00000000 		.secrel32	.Ldebug_abbrev0
 283 000a 08       		.byte	0x8
 284 000b 01       		.uleb128 0x1
 285 000c 474E5520 		.ascii "GNU C++98 8.1.0 -mtune=core2 -march=nocona -g -std=gnu++98\0"
 285      432B2B39 
 285      3820382E 
 285      312E3020 
 285      2D6D7475 
 286 0047 04       		.byte	0x4
 287 0048 432B2B2F 		.ascii "C++/\312\265\321\351\243\272\273\343\261\340/\277\354\266\301(inline).cpp\0"
 287      CAB5D1E9 
 287      A3BABBE3 
 287      B1E02FBF 
 287      ECB6C128 
 288 0068 453A5C63 		.ascii "E:\\code\0"
 288      6F646500 
 289 0070 00000000 		.secrel32	.Ldebug_ranges0+0
 290 0074 00000000 		.quad	0
 290      00000000 
 291 007c 00000000 		.secrel32	.Ldebug_line0
 292 0080 02       		.uleb128 0x2
 293 0081 73746400 		.ascii "std\0"
 294 0085 06       		.byte	0x6
 295 0086 00       		.byte	0
 296 0087 F2010000 		.long	0x1f2
 297 008b 03       		.uleb128 0x3
 298 008c 5F5F6378 		.ascii "__cxx11\0"
 298      78313100 
 299 0094 04       		.byte	0x4
 300 0095 0401     		.word	0x104
 301 0097 41       		.byte	0x41
 302 0098 04       		.uleb128 0x4
 303 0099 04       		.byte	0x4
 304 009a 0401     		.word	0x104
 305 009c 41       		.byte	0x41
 306 009d 8B000000 		.long	0x8b
 307 00a1 05       		.uleb128 0x5
 308 00a2 03       		.byte	0x3
 309 00a3 62       		.byte	0x62
 310 00a4 0B       		.byte	0xb
 311 00a5 A8030000 		.long	0x3a8
 312 00a9 05       		.uleb128 0x5
 313 00aa 03       		.byte	0x3
 314 00ab 63       		.byte	0x63
 315 00ac 0B       		.byte	0xb
 316 00ad B5030000 		.long	0x3b5
 317 00b1 05       		.uleb128 0x5
 318 00b2 03       		.byte	0x3
 319 00b3 65       		.byte	0x65
 320 00b4 0B       		.byte	0xb
 321 00b5 C9030000 		.long	0x3c9
 322 00b9 05       		.uleb128 0x5
 323 00ba 03       		.byte	0x3
 324 00bb 66       		.byte	0x66
 325 00bc 0B       		.byte	0xb
 326 00bd E7030000 		.long	0x3e7
 327 00c1 05       		.uleb128 0x5
 328 00c2 03       		.byte	0x3
 329 00c3 67       		.byte	0x67
 330 00c4 0B       		.byte	0xb
 331 00c5 01040000 		.long	0x401
 332 00c9 05       		.uleb128 0x5
 333 00ca 03       		.byte	0x3
 334 00cb 68       		.byte	0x68
 335 00cc 0B       		.byte	0xb
 336 00cd 19040000 		.long	0x419
 337 00d1 05       		.uleb128 0x5
 338 00d2 03       		.byte	0x3
 339 00d3 69       		.byte	0x69
 340 00d4 0B       		.byte	0xb
 341 00d5 33040000 		.long	0x433
 342 00d9 05       		.uleb128 0x5
 343 00da 03       		.byte	0x3
 344 00db 6A       		.byte	0x6a
 345 00dc 0B       		.byte	0xb
 346 00dd 4D040000 		.long	0x44d
 347 00e1 05       		.uleb128 0x5
 348 00e2 03       		.byte	0x3
 349 00e3 6B       		.byte	0x6b
 350 00e4 0B       		.byte	0xb
 351 00e5 66040000 		.long	0x466
 352 00e9 05       		.uleb128 0x5
 353 00ea 03       		.byte	0x3
 354 00eb 6C       		.byte	0x6c
 355 00ec 0B       		.byte	0xb
 356 00ed 8C040000 		.long	0x48c
 357 00f1 05       		.uleb128 0x5
 358 00f2 03       		.byte	0x3
 359 00f3 6D       		.byte	0x6d
 360 00f4 0B       		.byte	0xb
 361 00f5 AF040000 		.long	0x4af
 362 00f9 05       		.uleb128 0x5
 363 00fa 03       		.byte	0x3
 364 00fb 6E       		.byte	0x6e
 365 00fc 0B       		.byte	0xb
 366 00fd D3040000 		.long	0x4d3
 367 0101 05       		.uleb128 0x5
 368 0102 03       		.byte	0x3
 369 0103 71       		.byte	0x71
 370 0104 0B       		.byte	0xb
 371 0105 0B050000 		.long	0x50b
 372 0109 05       		.uleb128 0x5
 373 010a 03       		.byte	0x3
 374 010b 72       		.byte	0x72
 375 010c 0B       		.byte	0xb
 376 010d 35050000 		.long	0x535
 377 0111 05       		.uleb128 0x5
 378 0112 03       		.byte	0x3
 379 0113 73       		.byte	0x73
 380 0114 0B       		.byte	0xb
 381 0115 5A050000 		.long	0x55a
 382 0119 05       		.uleb128 0x5
 383 011a 03       		.byte	0x3
 384 011b 74       		.byte	0x74
 385 011c 0B       		.byte	0xb
 386 011d 90050000 		.long	0x590
 387 0121 05       		.uleb128 0x5
 388 0122 03       		.byte	0x3
 389 0123 75       		.byte	0x75
 390 0124 0B       		.byte	0xb
 391 0125 B3050000 		.long	0x5b3
 392 0129 05       		.uleb128 0x5
 393 012a 03       		.byte	0x3
 394 012b 76       		.byte	0x76
 395 012c 0B       		.byte	0xb
 396 012d D9050000 		.long	0x5d9
 397 0131 05       		.uleb128 0x5
 398 0132 03       		.byte	0x3
 399 0133 78       		.byte	0x78
 400 0134 0B       		.byte	0xb
 401 0135 F2050000 		.long	0x5f2
 402 0139 05       		.uleb128 0x5
 403 013a 03       		.byte	0x3
 404 013b 79       		.byte	0x79
 405 013c 0B       		.byte	0xb
 406 013d 0A060000 		.long	0x60a
 407 0141 05       		.uleb128 0x5
 408 0142 03       		.byte	0x3
 409 0143 7C       		.byte	0x7c
 410 0144 0B       		.byte	0xb
 411 0145 1B060000 		.long	0x61b
 412 0149 05       		.uleb128 0x5
 413 014a 03       		.byte	0x3
 414 014b 7E       		.byte	0x7e
 415 014c 0B       		.byte	0xb
 416 014d 33060000 		.long	0x633
 417 0151 05       		.uleb128 0x5
 418 0152 03       		.byte	0x3
 419 0153 7F       		.byte	0x7f
 420 0154 0B       		.byte	0xb
 421 0155 49060000 		.long	0x649
 422 0159 05       		.uleb128 0x5
 423 015a 03       		.byte	0x3
 424 015b 83       		.byte	0x83
 425 015c 0B       		.byte	0xb
 426 015d D0060000 		.long	0x6d0
 427 0161 05       		.uleb128 0x5
 428 0162 03       		.byte	0x3
 429 0163 84       		.byte	0x84
 430 0164 0B       		.byte	0xb
 431 0165 EA060000 		.long	0x6ea
 432 0169 05       		.uleb128 0x5
 433 016a 03       		.byte	0x3
 434 016b 85       		.byte	0x85
 435 016c 0B       		.byte	0xb
 436 016d 09070000 		.long	0x709
 437 0171 05       		.uleb128 0x5
 438 0172 03       		.byte	0x3
 439 0173 86       		.byte	0x86
 440 0174 0B       		.byte	0xb
 441 0175 1F070000 		.long	0x71f
 442 0179 05       		.uleb128 0x5
 443 017a 03       		.byte	0x3
 444 017b 87       		.byte	0x87
 445 017c 0B       		.byte	0xb
 446 017d 46070000 		.long	0x746
 447 0181 05       		.uleb128 0x5
 448 0182 03       		.byte	0x3
 449 0183 88       		.byte	0x88
 450 0184 0B       		.byte	0xb
 451 0185 61070000 		.long	0x761
 452 0189 05       		.uleb128 0x5
 453 018a 03       		.byte	0x3
 454 018b 89       		.byte	0x89
 455 018c 0B       		.byte	0xb
 456 018d 8B070000 		.long	0x78b
 457 0191 05       		.uleb128 0x5
 458 0192 03       		.byte	0x3
 459 0193 8A       		.byte	0x8a
 460 0194 0B       		.byte	0xb
 461 0195 BD070000 		.long	0x7bd
 462 0199 05       		.uleb128 0x5
 463 019a 03       		.byte	0x3
 464 019b 8B       		.byte	0x8b
 465 019c 0B       		.byte	0xb
 466 019d EE070000 		.long	0x7ee
 467 01a1 05       		.uleb128 0x5
 468 01a2 03       		.byte	0x3
 469 01a3 8D       		.byte	0x8d
 470 01a4 0B       		.byte	0xb
 471 01a5 FF070000 		.long	0x7ff
 472 01a9 05       		.uleb128 0x5
 473 01aa 03       		.byte	0x3
 474 01ab 8F       		.byte	0x8f
 475 01ac 0B       		.byte	0xb
 476 01ad 19080000 		.long	0x819
 477 01b1 05       		.uleb128 0x5
 478 01b2 03       		.byte	0x3
 479 01b3 90       		.byte	0x90
 480 01b4 0B       		.byte	0xb
 481 01b5 38080000 		.long	0x838
 482 01b9 05       		.uleb128 0x5
 483 01ba 03       		.byte	0x3
 484 01bb 91       		.byte	0x91
 485 01bc 0B       		.byte	0xb
 486 01bd 77080000 		.long	0x877
 487 01c1 05       		.uleb128 0x5
 488 01c2 03       		.byte	0x3
 489 01c3 92       		.byte	0x92
 490 01c4 0B       		.byte	0xb
 491 01c5 A7080000 		.long	0x8a7
 492 01c9 05       		.uleb128 0x5
 493 01ca 03       		.byte	0x3
 494 01cb B9       		.byte	0xb9
 495 01cc 16       		.byte	0x16
 496 01cd E0080000 		.long	0x8e0
 497 01d1 05       		.uleb128 0x5
 498 01d2 03       		.byte	0x3
 499 01d3 BA       		.byte	0xba
 500 01d4 16       		.byte	0x16
 501 01d5 1A090000 		.long	0x91a
 502 01d9 05       		.uleb128 0x5
 503 01da 03       		.byte	0x3
 504 01db BB       		.byte	0xbb
 505 01dc 16       		.byte	0x16
 506 01dd 57090000 		.long	0x957
 507 01e1 05       		.uleb128 0x5
 508 01e2 03       		.byte	0x3
 509 01e3 BC       		.byte	0xbc
 510 01e4 16       		.byte	0x16
 511 01e5 85090000 		.long	0x985
 512 01e9 05       		.uleb128 0x5
 513 01ea 03       		.byte	0x3
 514 01eb BD       		.byte	0xbd
 515 01ec 16       		.byte	0x16
 516 01ed C6090000 		.long	0x9c6
 517 01f1 00       		.byte	0
 518 01f2 06       		.uleb128 0x6
 519 01f3 5F5F676E 		.ascii "__gnu_cxx\0"
 519      755F6378 
 519      7800
 520 01fd 04       		.byte	0x4
 521 01fe 0601     		.word	0x106
 522 0200 0B       		.byte	0xb
 523 0201 44020000 		.long	0x244
 524 0205 03       		.uleb128 0x3
 525 0206 5F5F6378 		.ascii "__cxx11\0"
 525      78313100 
 526 020e 04       		.byte	0x4
 527 020f 0801     		.word	0x108
 528 0211 41       		.byte	0x41
 529 0212 04       		.uleb128 0x4
 530 0213 04       		.byte	0x4
 531 0214 0801     		.word	0x108
 532 0216 41       		.byte	0x41
 533 0217 05020000 		.long	0x205
 534 021b 05       		.uleb128 0x5
 535 021c 03       		.byte	0x3
 536 021d AF       		.byte	0xaf
 537 021e 0B       		.byte	0xb
 538 021f E0080000 		.long	0x8e0
 539 0223 05       		.uleb128 0x5
 540 0224 03       		.byte	0x3
 541 0225 B0       		.byte	0xb0
 542 0226 0B       		.byte	0xb
 543 0227 1A090000 		.long	0x91a
 544 022b 05       		.uleb128 0x5
 545 022c 03       		.byte	0x3
 546 022d B1       		.byte	0xb1
 547 022e 0B       		.byte	0xb
 548 022f 57090000 		.long	0x957
 549 0233 05       		.uleb128 0x5
 550 0234 03       		.byte	0x3
 551 0235 B2       		.byte	0xb2
 552 0236 0B       		.byte	0xb
 553 0237 85090000 		.long	0x985
 554 023b 05       		.uleb128 0x5
 555 023c 03       		.byte	0x3
 556 023d B3       		.byte	0xb3
 557 023e 0B       		.byte	0xb
 558 023f C6090000 		.long	0x9c6
 559 0243 00       		.byte	0
 560 0244 07       		.uleb128 0x7
 561 0245 08       		.byte	0x8
 562 0246 5F5F6275 		.ascii "__builtin_va_list\0"
 562      696C7469 
 562      6E5F7661 
 562      5F6C6973 
 562      7400
 563 0258 5C020000 		.long	0x25c
 564 025c 08       		.uleb128 0x8
 565 025d 01       		.byte	0x1
 566 025e 06       		.byte	0x6
 567 025f 63686172 		.ascii "char\0"
 567      00
 568 0264 09       		.uleb128 0x9
 569 0265 5C020000 		.long	0x25c
 570 0269 0A       		.uleb128 0xa
 571 026a 73697A65 		.ascii "size_t\0"
 571      5F7400
 572 0271 05       		.byte	0x5
 573 0272 23       		.byte	0x23
 574 0273 2C       		.byte	0x2c
 575 0274 78020000 		.long	0x278
 576 0278 08       		.uleb128 0x8
 577 0279 08       		.byte	0x8
 578 027a 07       		.byte	0x7
 579 027b 6C6F6E67 		.ascii "long long unsigned int\0"
 579      206C6F6E 
 579      6720756E 
 579      7369676E 
 579      65642069 
 580 0292 08       		.uleb128 0x8
 581 0293 08       		.byte	0x8
 582 0294 05       		.byte	0x5
 583 0295 6C6F6E67 		.ascii "long long int\0"
 583      206C6F6E 
 583      6720696E 
 583      7400
 584 02a3 08       		.uleb128 0x8
 585 02a4 02       		.byte	0x2
 586 02a5 07       		.byte	0x7
 587 02a6 73686F72 		.ascii "short unsigned int\0"
 587      7420756E 
 587      7369676E 
 587      65642069 
 587      6E7400
 588 02b9 08       		.uleb128 0x8
 589 02ba 04       		.byte	0x4
 590 02bb 05       		.byte	0x5
 591 02bc 696E7400 		.ascii "int\0"
 592 02c0 09       		.uleb128 0x9
 593 02c1 B9020000 		.long	0x2b9
 594 02c5 08       		.uleb128 0x8
 595 02c6 04       		.byte	0x4
 596 02c7 05       		.byte	0x5
 597 02c8 6C6F6E67 		.ascii "long int\0"
 597      20696E74 
 597      00
 598 02d1 0B       		.uleb128 0xb
 599 02d2 08       		.byte	0x8
 600 02d3 5C020000 		.long	0x25c
 601 02d7 08       		.uleb128 0x8
 602 02d8 02       		.byte	0x2
 603 02d9 07       		.byte	0x7
 604 02da 77636861 		.ascii "wchar_t\0"
 604      725F7400 
 605 02e2 08       		.uleb128 0x8
 606 02e3 04       		.byte	0x4
 607 02e4 07       		.byte	0x7
 608 02e5 756E7369 		.ascii "unsigned int\0"
 608      676E6564 
 608      20696E74 
 608      00
 609 02f2 08       		.uleb128 0x8
 610 02f3 04       		.byte	0x4
 611 02f4 07       		.byte	0x7
 612 02f5 6C6F6E67 		.ascii "long unsigned int\0"
 612      20756E73 
 612      69676E65 
 612      6420696E 
 612      7400
 613 0307 08       		.uleb128 0x8
 614 0308 01       		.byte	0x1
 615 0309 08       		.byte	0x8
 616 030a 756E7369 		.ascii "unsigned char\0"
 616      676E6564 
 616      20636861 
 616      7200
 617 0318 0C       		.uleb128 0xc
 618 0319 5F696F62 		.ascii "_iobuf\0"
 618      756600
 619 0320 30       		.byte	0x30
 620 0321 01       		.byte	0x1
 621 0322 1A       		.byte	0x1a
 622 0323 0A       		.byte	0xa
 623 0324 A8030000 		.long	0x3a8
 624 0328 0D       		.uleb128 0xd
 625 0329 5F707472 		.ascii "_ptr\0"
 625      00
 626 032e 01       		.byte	0x1
 627 032f 1B       		.byte	0x1b
 628 0330 0B       		.byte	0xb
 629 0331 D1020000 		.long	0x2d1
 630 0335 00       		.byte	0
 631 0336 0D       		.uleb128 0xd
 632 0337 5F636E74 		.ascii "_cnt\0"
 632      00
 633 033c 01       		.byte	0x1
 634 033d 1C       		.byte	0x1c
 635 033e 09       		.byte	0x9
 636 033f B9020000 		.long	0x2b9
 637 0343 08       		.byte	0x8
 638 0344 0D       		.uleb128 0xd
 639 0345 5F626173 		.ascii "_base\0"
 639      6500
 640 034b 01       		.byte	0x1
 641 034c 1D       		.byte	0x1d
 642 034d 0B       		.byte	0xb
 643 034e D1020000 		.long	0x2d1
 644 0352 10       		.byte	0x10
 645 0353 0D       		.uleb128 0xd
 646 0354 5F666C61 		.ascii "_flag\0"
 646      6700
 647 035a 01       		.byte	0x1
 648 035b 1E       		.byte	0x1e
 649 035c 09       		.byte	0x9
 650 035d B9020000 		.long	0x2b9
 651 0361 18       		.byte	0x18
 652 0362 0D       		.uleb128 0xd
 653 0363 5F66696C 		.ascii "_file\0"
 653      6500
 654 0369 01       		.byte	0x1
 655 036a 1F       		.byte	0x1f
 656 036b 09       		.byte	0x9
 657 036c B9020000 		.long	0x2b9
 658 0370 1C       		.byte	0x1c
 659 0371 0D       		.uleb128 0xd
 660 0372 5F636861 		.ascii "_charbuf\0"
 660      72627566 
 660      00
 661 037b 01       		.byte	0x1
 662 037c 20       		.byte	0x20
 663 037d 09       		.byte	0x9
 664 037e B9020000 		.long	0x2b9
 665 0382 20       		.byte	0x20
 666 0383 0D       		.uleb128 0xd
 667 0384 5F627566 		.ascii "_bufsiz\0"
 667      73697A00 
 668 038c 01       		.byte	0x1
 669 038d 21       		.byte	0x21
 670 038e 09       		.byte	0x9
 671 038f B9020000 		.long	0x2b9
 672 0393 24       		.byte	0x24
 673 0394 0D       		.uleb128 0xd
 674 0395 5F746D70 		.ascii "_tmpfname\0"
 674      666E616D 
 674      6500
 675 039f 01       		.byte	0x1
 676 03a0 22       		.byte	0x22
 677 03a1 0B       		.byte	0xb
 678 03a2 D1020000 		.long	0x2d1
 679 03a6 28       		.byte	0x28
 680 03a7 00       		.byte	0
 681 03a8 0A       		.uleb128 0xa
 682 03a9 46494C45 		.ascii "FILE\0"
 682      00
 683 03ae 01       		.byte	0x1
 684 03af 24       		.byte	0x24
 685 03b0 19       		.byte	0x19
 686 03b1 18030000 		.long	0x318
 687 03b5 0A       		.uleb128 0xa
 688 03b6 66706F73 		.ascii "fpos_t\0"
 688      5F7400
 689 03bd 01       		.byte	0x1
 690 03be 68       		.byte	0x68
 691 03bf 25       		.byte	0x25
 692 03c0 92020000 		.long	0x292
 693 03c4 09       		.uleb128 0x9
 694 03c5 B5030000 		.long	0x3b5
 695 03c9 0E       		.uleb128 0xe
 696 03ca 636C6561 		.ascii "clearerr\0"
 696      72657272 
 696      00
 697 03d3 01       		.byte	0x1
 698 03d4 4202     		.word	0x242
 699 03d6 10       		.byte	0x10
 700 03d7 E1030000 		.long	0x3e1
 701 03db 0F       		.uleb128 0xf
 702 03dc E1030000 		.long	0x3e1
 703 03e0 00       		.byte	0
 704 03e1 0B       		.uleb128 0xb
 705 03e2 08       		.byte	0x8
 706 03e3 A8030000 		.long	0x3a8
 707 03e7 10       		.uleb128 0x10
 708 03e8 66636C6F 		.ascii "fclose\0"
 708      736500
 709 03ef 01       		.byte	0x1
 710 03f0 4302     		.word	0x243
 711 03f2 0F       		.byte	0xf
 712 03f3 B9020000 		.long	0x2b9
 713 03f7 01040000 		.long	0x401
 714 03fb 0F       		.uleb128 0xf
 715 03fc E1030000 		.long	0x3e1
 716 0400 00       		.byte	0
 717 0401 10       		.uleb128 0x10
 718 0402 66656F66 		.ascii "feof\0"
 718      00
 719 0407 01       		.byte	0x1
 720 0408 4A02     		.word	0x24a
 721 040a 0F       		.byte	0xf
 722 040b B9020000 		.long	0x2b9
 723 040f 19040000 		.long	0x419
 724 0413 0F       		.uleb128 0xf
 725 0414 E1030000 		.long	0x3e1
 726 0418 00       		.byte	0
 727 0419 10       		.uleb128 0x10
 728 041a 66657272 		.ascii "ferror\0"
 728      6F7200
 729 0421 01       		.byte	0x1
 730 0422 4B02     		.word	0x24b
 731 0424 0F       		.byte	0xf
 732 0425 B9020000 		.long	0x2b9
 733 0429 33040000 		.long	0x433
 734 042d 0F       		.uleb128 0xf
 735 042e E1030000 		.long	0x3e1
 736 0432 00       		.byte	0
 737 0433 10       		.uleb128 0x10
 738 0434 66666C75 		.ascii "fflush\0"
 738      736800
 739 043b 01       		.byte	0x1
 740 043c 4C02     		.word	0x24c
 741 043e 0F       		.byte	0xf
 742 043f B9020000 		.long	0x2b9
 743 0443 4D040000 		.long	0x44d
 744 0447 0F       		.uleb128 0xf
 745 0448 E1030000 		.long	0x3e1
 746 044c 00       		.byte	0
 747 044d 10       		.uleb128 0x10
 748 044e 66676574 		.ascii "fgetc\0"
 748      6300
 749 0454 01       		.byte	0x1
 750 0455 4D02     		.word	0x24d
 751 0457 0F       		.byte	0xf
 752 0458 B9020000 		.long	0x2b9
 753 045c 66040000 		.long	0x466
 754 0460 0F       		.uleb128 0xf
 755 0461 E1030000 		.long	0x3e1
 756 0465 00       		.byte	0
 757 0466 10       		.uleb128 0x10
 758 0467 66676574 		.ascii "fgetpos\0"
 758      706F7300 
 759 046f 01       		.byte	0x1
 760 0470 4F02     		.word	0x24f
 761 0472 0F       		.byte	0xf
 762 0473 B9020000 		.long	0x2b9
 763 0477 86040000 		.long	0x486
 764 047b 0F       		.uleb128 0xf
 765 047c E1030000 		.long	0x3e1
 766 0480 0F       		.uleb128 0xf
 767 0481 86040000 		.long	0x486
 768 0485 00       		.byte	0
 769 0486 0B       		.uleb128 0xb
 770 0487 08       		.byte	0x8
 771 0488 B5030000 		.long	0x3b5
 772 048c 10       		.uleb128 0x10
 773 048d 66676574 		.ascii "fgets\0"
 773      7300
 774 0493 01       		.byte	0x1
 775 0494 5102     		.word	0x251
 776 0496 11       		.byte	0x11
 777 0497 D1020000 		.long	0x2d1
 778 049b AF040000 		.long	0x4af
 779 049f 0F       		.uleb128 0xf
 780 04a0 D1020000 		.long	0x2d1
 781 04a4 0F       		.uleb128 0xf
 782 04a5 B9020000 		.long	0x2b9
 783 04a9 0F       		.uleb128 0xf
 784 04aa E1030000 		.long	0x3e1
 785 04ae 00       		.byte	0
 786 04af 10       		.uleb128 0x10
 787 04b0 666F7065 		.ascii "fopen\0"
 787      6E00
 788 04b6 01       		.byte	0x1
 789 04b7 5802     		.word	0x258
 790 04b9 11       		.byte	0x11
 791 04ba E1030000 		.long	0x3e1
 792 04be CD040000 		.long	0x4cd
 793 04c2 0F       		.uleb128 0xf
 794 04c3 CD040000 		.long	0x4cd
 795 04c7 0F       		.uleb128 0xf
 796 04c8 CD040000 		.long	0x4cd
 797 04cc 00       		.byte	0
 798 04cd 0B       		.uleb128 0xb
 799 04ce 08       		.byte	0x8
 800 04cf 64020000 		.long	0x264
 801 04d3 11       		.uleb128 0x11
 802 04d4 66707269 		.ascii "fprintf\0"
 802      6E746600 
 803 04dc 01       		.byte	0x1
 804 04dd 4E01     		.word	0x14e
 805 04df 05       		.byte	0x5
 806 04e0 5F5A3766 		.ascii "_Z7fprintfP6_iobufPKcz\0"
 806      7072696E 
 806      74665036 
 806      5F696F62 
 806      7566504B 
 807 04f7 B9020000 		.long	0x2b9
 808 04fb 0B050000 		.long	0x50b
 809 04ff 0F       		.uleb128 0xf
 810 0500 E1030000 		.long	0x3e1
 811 0504 0F       		.uleb128 0xf
 812 0505 CD040000 		.long	0x4cd
 813 0509 12       		.uleb128 0x12
 814 050a 00       		.byte	0
 815 050b 10       		.uleb128 0x10
 816 050c 66726561 		.ascii "fread\0"
 816      6400
 817 0512 01       		.byte	0x1
 818 0513 5D02     		.word	0x25d
 819 0515 12       		.byte	0x12
 820 0516 69020000 		.long	0x269
 821 051a 33050000 		.long	0x533
 822 051e 0F       		.uleb128 0xf
 823 051f 33050000 		.long	0x533
 824 0523 0F       		.uleb128 0xf
 825 0524 69020000 		.long	0x269
 826 0528 0F       		.uleb128 0xf
 827 0529 69020000 		.long	0x269
 828 052d 0F       		.uleb128 0xf
 829 052e E1030000 		.long	0x3e1
 830 0532 00       		.byte	0
 831 0533 13       		.uleb128 0x13
 832 0534 08       		.byte	0x8
 833 0535 10       		.uleb128 0x10
 834 0536 6672656F 		.ascii "freopen\0"
 834      70656E00 
 835 053e 01       		.byte	0x1
 836 053f 5E02     		.word	0x25e
 837 0541 11       		.byte	0x11
 838 0542 E1030000 		.long	0x3e1
 839 0546 5A050000 		.long	0x55a
 840 054a 0F       		.uleb128 0xf
 841 054b CD040000 		.long	0x4cd
 842 054f 0F       		.uleb128 0xf
 843 0550 CD040000 		.long	0x4cd
 844 0554 0F       		.uleb128 0xf
 845 0555 E1030000 		.long	0x3e1
 846 0559 00       		.byte	0
 847 055a 11       		.uleb128 0x11
 848 055b 66736361 		.ascii "fscanf\0"
 848      6E6600
 849 0562 01       		.byte	0x1
 850 0563 2101     		.word	0x121
 851 0565 05       		.byte	0x5
 852 0566 5F5A3666 		.ascii "_Z6fscanfP6_iobufPKcz\0"
 852      7363616E 
 852      6650365F 
 852      696F6275 
 852      66504B63 
 853 057c B9020000 		.long	0x2b9
 854 0580 90050000 		.long	0x590
 855 0584 0F       		.uleb128 0xf
 856 0585 E1030000 		.long	0x3e1
 857 0589 0F       		.uleb128 0xf
 858 058a CD040000 		.long	0x4cd
 859 058e 12       		.uleb128 0x12
 860 058f 00       		.byte	0
 861 0590 10       		.uleb128 0x10
 862 0591 66736565 		.ascii "fseek\0"
 862      6B00
 863 0597 01       		.byte	0x1
 864 0598 6102     		.word	0x261
 865 059a 0F       		.byte	0xf
 866 059b B9020000 		.long	0x2b9
 867 059f B3050000 		.long	0x5b3
 868 05a3 0F       		.uleb128 0xf
 869 05a4 E1030000 		.long	0x3e1
 870 05a8 0F       		.uleb128 0xf
 871 05a9 C5020000 		.long	0x2c5
 872 05ad 0F       		.uleb128 0xf
 873 05ae B9020000 		.long	0x2b9
 874 05b2 00       		.byte	0
 875 05b3 10       		.uleb128 0x10
 876 05b4 66736574 		.ascii "fsetpos\0"
 876      706F7300 
 877 05bc 01       		.byte	0x1
 878 05bd 5F02     		.word	0x25f
 879 05bf 0F       		.byte	0xf
 880 05c0 B9020000 		.long	0x2b9
 881 05c4 D3050000 		.long	0x5d3
 882 05c8 0F       		.uleb128 0xf
 883 05c9 E1030000 		.long	0x3e1
 884 05cd 0F       		.uleb128 0xf
 885 05ce D3050000 		.long	0x5d3
 886 05d2 00       		.byte	0
 887 05d3 0B       		.uleb128 0xb
 888 05d4 08       		.byte	0x8
 889 05d5 C4030000 		.long	0x3c4
 890 05d9 10       		.uleb128 0x10
 891 05da 6674656C 		.ascii "ftell\0"
 891      6C00
 892 05e0 01       		.byte	0x1
 893 05e1 6202     		.word	0x262
 894 05e3 10       		.byte	0x10
 895 05e4 C5020000 		.long	0x2c5
 896 05e8 F2050000 		.long	0x5f2
 897 05ec 0F       		.uleb128 0xf
 898 05ed E1030000 		.long	0x3e1
 899 05f1 00       		.byte	0
 900 05f2 10       		.uleb128 0x10
 901 05f3 67657463 		.ascii "getc\0"
 901      00
 902 05f8 01       		.byte	0x1
 903 05f9 8F02     		.word	0x28f
 904 05fb 0F       		.byte	0xf
 905 05fc B9020000 		.long	0x2b9
 906 0600 0A060000 		.long	0x60a
 907 0604 0F       		.uleb128 0xf
 908 0605 E1030000 		.long	0x3e1
 909 0609 00       		.byte	0
 910 060a 14       		.uleb128 0x14
 911 060b 67657463 		.ascii "getchar\0"
 911      68617200 
 912 0613 01       		.byte	0x1
 913 0614 9002     		.word	0x290
 914 0616 0F       		.byte	0xf
 915 0617 B9020000 		.long	0x2b9
 916 061b 10       		.uleb128 0x10
 917 061c 67657473 		.ascii "gets\0"
 917      00
 918 0621 01       		.byte	0x1
 919 0622 9202     		.word	0x292
 920 0624 11       		.byte	0x11
 921 0625 D1020000 		.long	0x2d1
 922 0629 33060000 		.long	0x633
 923 062d 0F       		.uleb128 0xf
 924 062e D1020000 		.long	0x2d1
 925 0632 00       		.byte	0
 926 0633 0E       		.uleb128 0xe
 927 0634 70657272 		.ascii "perror\0"
 927      6F7200
 928 063b 01       		.byte	0x1
 929 063c 9602     		.word	0x296
 930 063e 10       		.byte	0x10
 931 063f 49060000 		.long	0x649
 932 0643 0F       		.uleb128 0xf
 933 0644 CD040000 		.long	0x4cd
 934 0648 00       		.byte	0
 935 0649 15       		.uleb128 0x15
 936 064a 7072696E 		.ascii "printf\0"
 936      746600
 937 0651 01       		.byte	0x1
 938 0652 5901     		.word	0x159
 939 0654 05       		.byte	0x5
 940 0655 5F5A3670 		.ascii "_Z6printfPKcz\0"
 940      72696E74 
 940      66504B63 
 940      7A00
 941 0663 B9020000 		.long	0x2b9
 942 0667 00000000 		.quad	.LFB8
 942      00000000 
 943 066f 54000000 		.quad	.LFE8-.LFB8
 943      00000000 
 944 0677 01       		.uleb128 0x1
 945 0678 9C       		.byte	0x9c
 946 0679 D0060000 		.long	0x6d0
 947 067d 12       		.uleb128 0x12
 948 067e 16       		.uleb128 0x16
 949 067f 5F5F666F 		.ascii "__format\0"
 949      726D6174 
 949      00
 950 0688 01       		.byte	0x1
 951 0689 5901     		.word	0x159
 952 068b 19       		.byte	0x19
 953 068c CD040000 		.long	0x4cd
 954 0690 02       		.uleb128 0x2
 955 0691 91       		.byte	0x91
 956 0692 00       		.sleb128 0
 957 0693 12       		.uleb128 0x12
 958 0694 17       		.uleb128 0x17
 959 0695 5F5F7265 		.ascii "__retval\0"
 959      7476616C 
 959      00
 960 069e 01       		.byte	0x1
 961 069f 5B01     		.word	0x15b
 962 06a1 07       		.byte	0x7
 963 06a2 B9020000 		.long	0x2b9
 964 06a6 02       		.uleb128 0x2
 965 06a7 91       		.byte	0x91
 966 06a8 5C       		.sleb128 -36
 967 06a9 17       		.uleb128 0x17
 968 06aa 5F5F6C6F 		.ascii "__local_argv\0"
 968      63616C5F 
 968      61726776 
 968      00
 969 06b7 01       		.byte	0x1
 970 06b8 5C01     		.word	0x15c
 971 06ba 15       		.byte	0x15
 972 06bb 44020000 		.long	0x244
 973 06bf 02       		.uleb128 0x2
 974 06c0 91       		.byte	0x91
 975 06c1 50       		.sleb128 -48
 976 06c2 18       		.uleb128 0x18
 977 06c3 38000000 		.quad	.LVL0
 977      00000000 
 978 06cb 2A0B0000 		.long	0xb2a
 979 06cf 00       		.byte	0
 980 06d0 10       		.uleb128 0x10
 981 06d1 72656D6F 		.ascii "remove\0"
 981      766500
 982 06d8 01       		.byte	0x1
 983 06d9 A402     		.word	0x2a4
 984 06db 0F       		.byte	0xf
 985 06dc B9020000 		.long	0x2b9
 986 06e0 EA060000 		.long	0x6ea
 987 06e4 0F       		.uleb128 0xf
 988 06e5 CD040000 		.long	0x4cd
 989 06e9 00       		.byte	0
 990 06ea 10       		.uleb128 0x10
 991 06eb 72656E61 		.ascii "rename\0"
 991      6D6500
 992 06f2 01       		.byte	0x1
 993 06f3 A502     		.word	0x2a5
 994 06f5 0F       		.byte	0xf
 995 06f6 B9020000 		.long	0x2b9
 996 06fa 09070000 		.long	0x709
 997 06fe 0F       		.uleb128 0xf
 998 06ff CD040000 		.long	0x4cd
 999 0703 0F       		.uleb128 0xf
 1000 0704 CD040000 		.long	0x4cd
 1001 0708 00       		.byte	0
 1002 0709 0E       		.uleb128 0xe
 1003 070a 72657769 		.ascii "rewind\0"
 1003      6E6400
 1004 0711 01       		.byte	0x1
 1005 0712 AB02     		.word	0x2ab
 1006 0714 10       		.byte	0x10
 1007 0715 1F070000 		.long	0x71f
 1008 0719 0F       		.uleb128 0xf
 1009 071a E1030000 		.long	0x3e1
 1010 071e 00       		.byte	0
 1011 071f 11       		.uleb128 0x11
 1012 0720 7363616E 		.ascii "scanf\0"
 1012      6600
 1013 0726 01       		.byte	0x1
 1014 0727 1601     		.word	0x116
 1015 0729 05       		.byte	0x5
 1016 072a 5F5A3573 		.ascii "_Z5scanfPKcz\0"
 1016      63616E66 
 1016      504B637A 
 1016      00
 1017 0737 B9020000 		.long	0x2b9
 1018 073b 46070000 		.long	0x746
 1019 073f 0F       		.uleb128 0xf
 1020 0740 CD040000 		.long	0x4cd
 1021 0744 12       		.uleb128 0x12
 1022 0745 00       		.byte	0
 1023 0746 0E       		.uleb128 0xe
 1024 0747 73657462 		.ascii "setbuf\0"
 1024      756600
 1025 074e 01       		.byte	0x1
 1026 074f AD02     		.word	0x2ad
 1027 0751 10       		.byte	0x10
 1028 0752 61070000 		.long	0x761
 1029 0756 0F       		.uleb128 0xf
 1030 0757 E1030000 		.long	0x3e1
 1031 075b 0F       		.uleb128 0xf
 1032 075c D1020000 		.long	0x2d1
 1033 0760 00       		.byte	0
 1034 0761 10       		.uleb128 0x10
 1035 0762 73657476 		.ascii "setvbuf\0"
 1035      62756600 
 1036 076a 01       		.byte	0x1
 1037 076b B102     		.word	0x2b1
 1038 076d 0F       		.byte	0xf
 1039 076e B9020000 		.long	0x2b9
 1040 0772 8B070000 		.long	0x78b
 1041 0776 0F       		.uleb128 0xf
 1042 0777 E1030000 		.long	0x3e1
 1043 077b 0F       		.uleb128 0xf
 1044 077c D1020000 		.long	0x2d1
 1045 0780 0F       		.uleb128 0xf
 1046 0781 B9020000 		.long	0x2b9
 1047 0785 0F       		.uleb128 0xf
 1048 0786 69020000 		.long	0x269
 1049 078a 00       		.byte	0
 1050 078b 11       		.uleb128 0x11
 1051 078c 73707269 		.ascii "sprintf\0"
 1051      6E746600 
 1052 0794 01       		.byte	0x1
 1053 0795 6401     		.word	0x164
 1054 0797 05       		.byte	0x5
 1055 0798 5F5A3773 		.ascii "_Z7sprintfPcPKcz\0"
 1055      7072696E 
 1055      74665063 
 1055      504B637A 
 1055      00
 1056 07a9 B9020000 		.long	0x2b9
 1057 07ad BD070000 		.long	0x7bd
 1058 07b1 0F       		.uleb128 0xf
 1059 07b2 D1020000 		.long	0x2d1
 1060 07b6 0F       		.uleb128 0xf
 1061 07b7 CD040000 		.long	0x4cd
 1062 07bb 12       		.uleb128 0x12
 1063 07bc 00       		.byte	0
 1064 07bd 11       		.uleb128 0x11
 1065 07be 73736361 		.ascii "sscanf\0"
 1065      6E6600
 1066 07c5 01       		.byte	0x1
 1067 07c6 0B01     		.word	0x10b
 1068 07c8 05       		.byte	0x5
 1069 07c9 5F5A3673 		.ascii "_Z6sscanfPKcS0_z\0"
 1069      7363616E 
 1069      66504B63 
 1069      53305F7A 
 1069      00
 1070 07da B9020000 		.long	0x2b9
 1071 07de EE070000 		.long	0x7ee
 1072 07e2 0F       		.uleb128 0xf
 1073 07e3 CD040000 		.long	0x4cd
 1074 07e7 0F       		.uleb128 0xf
 1075 07e8 CD040000 		.long	0x4cd
 1076 07ec 12       		.uleb128 0x12
 1077 07ed 00       		.byte	0
 1078 07ee 14       		.uleb128 0x14
 1079 07ef 746D7066 		.ascii "tmpfile\0"
 1079      696C6500 
 1080 07f7 01       		.byte	0x1
 1081 07f8 CB02     		.word	0x2cb
 1082 07fa 11       		.byte	0x11
 1083 07fb E1030000 		.long	0x3e1
 1084 07ff 10       		.uleb128 0x10
 1085 0800 746D706E 		.ascii "tmpnam\0"
 1085      616D00
 1086 0807 01       		.byte	0x1
 1087 0808 CC02     		.word	0x2cc
 1088 080a 11       		.byte	0x11
 1089 080b D1020000 		.long	0x2d1
 1090 080f 19080000 		.long	0x819
 1091 0813 0F       		.uleb128 0xf
 1092 0814 D1020000 		.long	0x2d1
 1093 0818 00       		.byte	0
 1094 0819 10       		.uleb128 0x10
 1095 081a 756E6765 		.ascii "ungetc\0"
 1095      746300
 1096 0821 01       		.byte	0x1
 1097 0822 CD02     		.word	0x2cd
 1098 0824 0F       		.byte	0xf
 1099 0825 B9020000 		.long	0x2b9
 1100 0829 38080000 		.long	0x838
 1101 082d 0F       		.uleb128 0xf
 1102 082e B9020000 		.long	0x2b9
 1103 0832 0F       		.uleb128 0xf
 1104 0833 E1030000 		.long	0x3e1
 1105 0837 00       		.byte	0
 1106 0838 11       		.uleb128 0x11
 1107 0839 76667072 		.ascii "vfprintf\0"
 1107      696E7466 
 1107      00
 1108 0842 01       		.byte	0x1
 1109 0843 6F01     		.word	0x16f
 1110 0845 05       		.byte	0x5
 1111 0846 5F5A3876 		.ascii "_Z8vfprintfP6_iobufPKcPc\0"
 1111      66707269 
 1111      6E746650 
 1111      365F696F 
 1111      62756650 
 1112 085f B9020000 		.long	0x2b9
 1113 0863 77080000 		.long	0x877
 1114 0867 0F       		.uleb128 0xf
 1115 0868 E1030000 		.long	0x3e1
 1116 086c 0F       		.uleb128 0xf
 1117 086d CD040000 		.long	0x4cd
 1118 0871 0F       		.uleb128 0xf
 1119 0872 44020000 		.long	0x244
 1120 0876 00       		.byte	0
 1121 0877 11       		.uleb128 0x11
 1122 0878 76707269 		.ascii "vprintf\0"
 1122      6E746600 
 1123 0880 01       		.byte	0x1
 1124 0881 7601     		.word	0x176
 1125 0883 05       		.byte	0x5
 1126 0884 5F5A3776 		.ascii "_Z7vprintfPKcPc\0"
 1126      7072696E 
 1126      7466504B 
 1126      63506300 
 1127 0894 B9020000 		.long	0x2b9
 1128 0898 A7080000 		.long	0x8a7
 1129 089c 0F       		.uleb128 0xf
 1130 089d CD040000 		.long	0x4cd
 1131 08a1 0F       		.uleb128 0xf
 1132 08a2 44020000 		.long	0x244
 1133 08a6 00       		.byte	0
 1134 08a7 11       		.uleb128 0x11
 1135 08a8 76737072 		.ascii "vsprintf\0"
 1135      696E7466 
 1135      00
 1136 08b1 01       		.byte	0x1
 1137 08b2 7D01     		.word	0x17d
 1138 08b4 05       		.byte	0x5
 1139 08b5 5F5A3876 		.ascii "_Z8vsprintfPcPKcS_\0"
 1139      73707269 
 1139      6E746650 
 1139      63504B63 
 1139      535F00
 1140 08c8 B9020000 		.long	0x2b9
 1141 08cc E0080000 		.long	0x8e0
 1142 08d0 0F       		.uleb128 0xf
 1143 08d1 D1020000 		.long	0x2d1
 1144 08d5 0F       		.uleb128 0xf
 1145 08d6 CD040000 		.long	0x4cd
 1146 08da 0F       		.uleb128 0xf
 1147 08db 44020000 		.long	0x244
 1148 08df 00       		.byte	0
 1149 08e0 11       		.uleb128 0x11
 1150 08e1 736E7072 		.ascii "snprintf\0"
 1150      696E7466 
 1150      00
 1151 08ea 01       		.byte	0x1
 1152 08eb 8401     		.word	0x184
 1153 08ed 05       		.byte	0x5
 1154 08ee 5F5A3873 		.ascii "_Z8snprintfPcyPKcz\0"
 1154      6E707269 
 1154      6E746650 
 1154      6379504B 
 1154      637A00
 1155 0901 B9020000 		.long	0x2b9
 1156 0905 1A090000 		.long	0x91a
 1157 0909 0F       		.uleb128 0xf
 1158 090a D1020000 		.long	0x2d1
 1159 090e 0F       		.uleb128 0xf
 1160 090f 69020000 		.long	0x269
 1161 0913 0F       		.uleb128 0xf
 1162 0914 CD040000 		.long	0x4cd
 1163 0918 12       		.uleb128 0x12
 1164 0919 00       		.byte	0
 1165 091a 11       		.uleb128 0x11
 1166 091b 76667363 		.ascii "vfscanf\0"
 1166      616E6600 
 1167 0923 01       		.byte	0x1
 1168 0924 4001     		.word	0x140
 1169 0926 05       		.byte	0x5
 1170 0927 5F5A3776 		.ascii "_Z7vfscanfP6_iobufPKcPc\0"
 1170      66736361 
 1170      6E665036 
 1170      5F696F62 
 1170      7566504B 
 1171 093f B9020000 		.long	0x2b9
 1172 0943 57090000 		.long	0x957
 1173 0947 0F       		.uleb128 0xf
 1174 0948 E1030000 		.long	0x3e1
 1175 094c 0F       		.uleb128 0xf
 1176 094d CD040000 		.long	0x4cd
 1177 0951 0F       		.uleb128 0xf
 1178 0952 44020000 		.long	0x244
 1179 0956 00       		.byte	0
 1180 0957 11       		.uleb128 0x11
 1181 0958 76736361 		.ascii "vscanf\0"
 1181      6E6600
 1182 095f 01       		.byte	0x1
 1183 0960 3901     		.word	0x139
 1184 0962 05       		.byte	0x5
 1185 0963 5F5A3676 		.ascii "_Z6vscanfPKcPc\0"
 1185      7363616E 
 1185      66504B63 
 1185      506300
 1186 0972 B9020000 		.long	0x2b9
 1187 0976 85090000 		.long	0x985
 1188 097a 0F       		.uleb128 0xf
 1189 097b CD040000 		.long	0x4cd
 1190 097f 0F       		.uleb128 0xf
 1191 0980 44020000 		.long	0x244
 1192 0984 00       		.byte	0
 1193 0985 11       		.uleb128 0x11
 1194 0986 76736E70 		.ascii "vsnprintf\0"
 1194      72696E74 
 1194      6600
 1195 0990 01       		.byte	0x1
 1196 0991 8F01     		.word	0x18f
 1197 0993 05       		.byte	0x5
 1198 0994 5F5A3976 		.ascii "_Z9vsnprintfPcyPKcS_\0"
 1198      736E7072 
 1198      696E7466 
 1198      50637950 
 1198      4B63535F 
 1199 09a9 B9020000 		.long	0x2b9
 1200 09ad C6090000 		.long	0x9c6
 1201 09b1 0F       		.uleb128 0xf
 1202 09b2 D1020000 		.long	0x2d1
 1203 09b6 0F       		.uleb128 0xf
 1204 09b7 69020000 		.long	0x269
 1205 09bb 0F       		.uleb128 0xf
 1206 09bc CD040000 		.long	0x4cd
 1207 09c0 0F       		.uleb128 0xf
 1208 09c1 44020000 		.long	0x244
 1209 09c5 00       		.byte	0
 1210 09c6 11       		.uleb128 0x11
 1211 09c7 76737363 		.ascii "vsscanf\0"
 1211      616E6600 
 1212 09cf 01       		.byte	0x1
 1213 09d0 3201     		.word	0x132
 1214 09d2 05       		.byte	0x5
 1215 09d3 5F5A3776 		.ascii "_Z7vsscanfPKcS0_Pc\0"
 1215      73736361 
 1215      6E66504B 
 1215      6353305F 
 1215      506300
 1216 09e6 B9020000 		.long	0x2b9
 1217 09ea FE090000 		.long	0x9fe
 1218 09ee 0F       		.uleb128 0xf
 1219 09ef CD040000 		.long	0x4cd
 1220 09f3 0F       		.uleb128 0xf
 1221 09f4 CD040000 		.long	0x4cd
 1222 09f8 0F       		.uleb128 0xf
 1223 09f9 44020000 		.long	0x244
 1224 09fd 00       		.byte	0
 1225 09fe 19       		.uleb128 0x19
 1226 09ff 6D61786E 		.ascii "maxn\0"
 1226      00
 1227 0a04 02       		.byte	0x2
 1228 0a05 03       		.byte	0x3
 1229 0a06 0B       		.byte	0xb
 1230 0a07 C0020000 		.long	0x2c0
 1231 0a0b 09       		.uleb128 0x9
 1232 0a0c 03       		.byte	0x3
 1233 0a0d 00000000 		.quad	_ZL4maxn
 1233      00000000 
 1234 0a15 1A       		.uleb128 0x1a
 1235 0a16 5C020000 		.long	0x25c
 1236 0a1a 280A0000 		.long	0xa28
 1237 0a1e 1B       		.uleb128 0x1b
 1238 0a1f 78020000 		.long	0x278
 1239 0a23 FFFF0100 		.long	0x1ffff
 1240 0a27 00       		.byte	0
 1241 0a28 1C       		.uleb128 0x1c
 1242 0a29 62756666 		.ascii "buffer\0"
 1242      657200
 1243 0a30 02       		.byte	0x2
 1244 0a31 05       		.byte	0x5
 1245 0a32 06       		.byte	0x6
 1246 0a33 150A0000 		.long	0xa15
 1247 0a37 09       		.uleb128 0x9
 1248 0a38 03       		.byte	0x3
 1249 0a39 00000000 		.quad	buffer
 1249      00000000 
 1250 0a41 1C       		.uleb128 0x1c
 1251 0a42 5300     		.ascii "S\0"
 1252 0a44 02       		.byte	0x2
 1253 0a45 05       		.byte	0x5
 1254 0a46 15       		.byte	0x15
 1255 0a47 D1020000 		.long	0x2d1
 1256 0a4b 09       		.uleb128 0x9
 1257 0a4c 03       		.byte	0x3
 1258 0a4d 00000200 		.quad	S
 1258      00000000 
 1259 0a55 1C       		.uleb128 0x1c
 1260 0a56 5400     		.ascii "T\0"
 1261 0a58 02       		.byte	0x2
 1262 0a59 05       		.byte	0x5
 1263 0a5a 19       		.byte	0x19
 1264 0a5b D1020000 		.long	0x2d1
 1265 0a5f 09       		.uleb128 0x9
 1266 0a60 03       		.byte	0x3
 1267 0a61 08000200 		.quad	T
 1267      00000000 
 1268 0a69 1D       		.uleb128 0x1d
 1269 0a6a 6D61696E 		.ascii "main\0"
 1269      00
 1270 0a6f 02       		.byte	0x2
 1271 0a70 1B       		.byte	0x1b
 1272 0a71 05       		.byte	0x5
 1273 0a72 B9020000 		.long	0x2b9
 1274 0a76 00000000 		.quad	.LFB46
 1274      00000000 
 1275 0a7e 31000000 		.quad	.LFE46-.LFB46
 1275      00000000 
 1276 0a86 01       		.uleb128 0x1
 1277 0a87 9C       		.byte	0x9c
 1278 0a88 9A0A0000 		.long	0xa9a
 1279 0a8c 19       		.uleb128 0x19
 1280 0a8d 6100     		.ascii "a\0"
 1281 0a8f 02       		.byte	0x2
 1282 0a90 1D       		.byte	0x1d
 1283 0a91 06       		.byte	0x6
 1284 0a92 B9020000 		.long	0x2b9
 1285 0a96 02       		.uleb128 0x2
 1286 0a97 91       		.byte	0x91
 1287 0a98 6C       		.sleb128 -20
 1288 0a99 00       		.byte	0
 1289 0a9a 1E       		.uleb128 0x1e
 1290 0a9b 4765745F 		.ascii "Get_Int\0"
 1290      496E7400 
 1291 0aa3 02       		.byte	0x2
 1292 0aa4 10       		.byte	0x10
 1293 0aa5 0C       		.byte	0xc
 1294 0aa6 5F5A3747 		.ascii "_Z7Get_Intv\0"
 1294      65745F49 
 1294      6E747600 
 1295 0ab2 B9020000 		.long	0x2b9
 1296 0ab6 00000000 		.quad	.LFB45
 1296      00000000 
 1297 0abe 66000000 		.quad	.LFE45-.LFB45
 1297      00000000 
 1298 0ac6 01       		.uleb128 0x1
 1299 0ac7 9C       		.byte	0x9c
 1300 0ac8 E80A0000 		.long	0xae8
 1301 0acc 19       		.uleb128 0x19
 1302 0acd 6300     		.ascii "c\0"
 1303 0acf 02       		.byte	0x2
 1304 0ad0 12       		.byte	0x12
 1305 0ad1 07       		.byte	0x7
 1306 0ad2 5C020000 		.long	0x25c
 1307 0ad6 02       		.uleb128 0x2
 1308 0ad7 91       		.byte	0x91
 1309 0ad8 6F       		.sleb128 -17
 1310 0ad9 19       		.uleb128 0x19
 1311 0ada 726500   		.ascii "re\0"
 1312 0add 02       		.byte	0x2
 1313 0ade 13       		.byte	0x13
 1314 0adf 06       		.byte	0x6
 1315 0ae0 B9020000 		.long	0x2b9
 1316 0ae4 02       		.uleb128 0x2
 1317 0ae5 91       		.byte	0x91
 1318 0ae6 68       		.sleb128 -24
 1319 0ae7 00       		.byte	0
 1320 0ae8 1E       		.uleb128 0x1e
 1321 0ae9 4765745F 		.ascii "Get_Char\0"
 1321      43686172 
 1321      00
 1322 0af2 02       		.byte	0x2
 1323 0af3 06       		.byte	0x6
 1324 0af4 0D       		.byte	0xd
 1325 0af5 5F5A3847 		.ascii "_Z8Get_Charv\0"
 1325      65745F43 
 1325      68617276 
 1325      00
 1326 0b02 5C020000 		.long	0x25c
 1327 0b06 00000000 		.quad	.LFB44
 1327      00000000 
 1328 0b0e 9E000000 		.quad	.LFE44-.LFB44
 1328      00000000 
 1329 0b16 01       		.uleb128 0x1
 1330 0b17 9C       		.byte	0x9c
 1331 0b18 2A0B0000 		.long	0xb2a
 1332 0b1c 18       		.uleb128 0x18
 1333 0b1d 44000000 		.quad	.LVL1
 1333      00000000 
 1334 0b25 2A0B0000 		.long	0xb2a
 1335 0b29 00       		.byte	0
 1336 0b2a 1F       		.uleb128 0x1f
 1337 0b2b 00000000 		.secrel32	.LASF0
 1338 0b2f 00000000 		.secrel32	.LASF0
 1339 0b33 01       		.byte	0x1
 1340 0b34 52       		.byte	0x52
 1341 0b35 17       		.byte	0x17
 1342 0b36 00       		.byte	0
 1343              		.section	.debug_abbrev,"dr"
 1344              	.Ldebug_abbrev0:
 1345 0000 01       		.uleb128 0x1
 1346 0001 11       		.uleb128 0x11
 1347 0002 01       		.byte	0x1
 1348 0003 25       		.uleb128 0x25
 1349 0004 08       		.uleb128 0x8
 1350 0005 13       		.uleb128 0x13
 1351 0006 0B       		.uleb128 0xb
 1352 0007 03       		.uleb128 0x3
 1353 0008 08       		.uleb128 0x8
 1354 0009 1B       		.uleb128 0x1b
 1355 000a 08       		.uleb128 0x8
 1356 000b 55       		.uleb128 0x55
 1357 000c 17       		.uleb128 0x17
 1358 000d 11       		.uleb128 0x11
 1359 000e 01       		.uleb128 0x1
 1360 000f 10       		.uleb128 0x10
 1361 0010 17       		.uleb128 0x17
 1362 0011 00       		.byte	0
 1363 0012 00       		.byte	0
 1364 0013 02       		.uleb128 0x2
 1365 0014 39       		.uleb128 0x39
 1366 0015 01       		.byte	0x1
 1367 0016 03       		.uleb128 0x3
 1368 0017 08       		.uleb128 0x8
 1369 0018 3A       		.uleb128 0x3a
 1370 0019 0B       		.uleb128 0xb
 1371 001a 3B       		.uleb128 0x3b
 1372 001b 0B       		.uleb128 0xb
 1373 001c 01       		.uleb128 0x1
 1374 001d 13       		.uleb128 0x13
 1375 001e 00       		.byte	0
 1376 001f 00       		.byte	0
 1377 0020 03       		.uleb128 0x3
 1378 0021 39       		.uleb128 0x39
 1379 0022 00       		.byte	0
 1380 0023 03       		.uleb128 0x3
 1381 0024 08       		.uleb128 0x8
 1382 0025 3A       		.uleb128 0x3a
 1383 0026 0B       		.uleb128 0xb
 1384 0027 3B       		.uleb128 0x3b
 1385 0028 05       		.uleb128 0x5
 1386 0029 39       		.uleb128 0x39
 1387 002a 0B       		.uleb128 0xb
 1388 002b 8901     		.uleb128 0x89
 1389 002d 19       		.uleb128 0x19
 1390 002e 00       		.byte	0
 1391 002f 00       		.byte	0
 1392 0030 04       		.uleb128 0x4
 1393 0031 3A       		.uleb128 0x3a
 1394 0032 00       		.byte	0
 1395 0033 3A       		.uleb128 0x3a
 1396 0034 0B       		.uleb128 0xb
 1397 0035 3B       		.uleb128 0x3b
 1398 0036 05       		.uleb128 0x5
 1399 0037 39       		.uleb128 0x39
 1400 0038 0B       		.uleb128 0xb
 1401 0039 18       		.uleb128 0x18
 1402 003a 13       		.uleb128 0x13
 1403 003b 00       		.byte	0
 1404 003c 00       		.byte	0
 1405 003d 05       		.uleb128 0x5
 1406 003e 08       		.uleb128 0x8
 1407 003f 00       		.byte	0
 1408 0040 3A       		.uleb128 0x3a
 1409 0041 0B       		.uleb128 0xb
 1410 0042 3B       		.uleb128 0x3b
 1411 0043 0B       		.uleb128 0xb
 1412 0044 39       		.uleb128 0x39
 1413 0045 0B       		.uleb128 0xb
 1414 0046 18       		.uleb128 0x18
 1415 0047 13       		.uleb128 0x13
 1416 0048 00       		.byte	0
 1417 0049 00       		.byte	0
 1418 004a 06       		.uleb128 0x6
 1419 004b 39       		.uleb128 0x39
 1420 004c 01       		.byte	0x1
 1421 004d 03       		.uleb128 0x3
 1422 004e 08       		.uleb128 0x8
 1423 004f 3A       		.uleb128 0x3a
 1424 0050 0B       		.uleb128 0xb
 1425 0051 3B       		.uleb128 0x3b
 1426 0052 05       		.uleb128 0x5
 1427 0053 39       		.uleb128 0x39
 1428 0054 0B       		.uleb128 0xb
 1429 0055 01       		.uleb128 0x1
 1430 0056 13       		.uleb128 0x13
 1431 0057 00       		.byte	0
 1432 0058 00       		.byte	0
 1433 0059 07       		.uleb128 0x7
 1434 005a 0F       		.uleb128 0xf
 1435 005b 00       		.byte	0
 1436 005c 0B       		.uleb128 0xb
 1437 005d 0B       		.uleb128 0xb
 1438 005e 03       		.uleb128 0x3
 1439 005f 08       		.uleb128 0x8
 1440 0060 49       		.uleb128 0x49
 1441 0061 13       		.uleb128 0x13
 1442 0062 00       		.byte	0
 1443 0063 00       		.byte	0
 1444 0064 08       		.uleb128 0x8
 1445 0065 24       		.uleb128 0x24
 1446 0066 00       		.byte	0
 1447 0067 0B       		.uleb128 0xb
 1448 0068 0B       		.uleb128 0xb
 1449 0069 3E       		.uleb128 0x3e
 1450 006a 0B       		.uleb128 0xb
 1451 006b 03       		.uleb128 0x3
 1452 006c 08       		.uleb128 0x8
 1453 006d 00       		.byte	0
 1454 006e 00       		.byte	0
 1455 006f 09       		.uleb128 0x9
 1456 0070 26       		.uleb128 0x26
 1457 0071 00       		.byte	0
 1458 0072 49       		.uleb128 0x49
 1459 0073 13       		.uleb128 0x13
 1460 0074 00       		.byte	0
 1461 0075 00       		.byte	0
 1462 0076 0A       		.uleb128 0xa
 1463 0077 16       		.uleb128 0x16
 1464 0078 00       		.byte	0
 1465 0079 03       		.uleb128 0x3
 1466 007a 08       		.uleb128 0x8
 1467 007b 3A       		.uleb128 0x3a
 1468 007c 0B       		.uleb128 0xb
 1469 007d 3B       		.uleb128 0x3b
 1470 007e 0B       		.uleb128 0xb
 1471 007f 39       		.uleb128 0x39
 1472 0080 0B       		.uleb128 0xb
 1473 0081 49       		.uleb128 0x49
 1474 0082 13       		.uleb128 0x13
 1475 0083 00       		.byte	0
 1476 0084 00       		.byte	0
 1477 0085 0B       		.uleb128 0xb
 1478 0086 0F       		.uleb128 0xf
 1479 0087 00       		.byte	0
 1480 0088 0B       		.uleb128 0xb
 1481 0089 0B       		.uleb128 0xb
 1482 008a 49       		.uleb128 0x49
 1483 008b 13       		.uleb128 0x13
 1484 008c 00       		.byte	0
 1485 008d 00       		.byte	0
 1486 008e 0C       		.uleb128 0xc
 1487 008f 13       		.uleb128 0x13
 1488 0090 01       		.byte	0x1
 1489 0091 03       		.uleb128 0x3
 1490 0092 08       		.uleb128 0x8
 1491 0093 0B       		.uleb128 0xb
 1492 0094 0B       		.uleb128 0xb
 1493 0095 3A       		.uleb128 0x3a
 1494 0096 0B       		.uleb128 0xb
 1495 0097 3B       		.uleb128 0x3b
 1496 0098 0B       		.uleb128 0xb
 1497 0099 39       		.uleb128 0x39
 1498 009a 0B       		.uleb128 0xb
 1499 009b 01       		.uleb128 0x1
 1500 009c 13       		.uleb128 0x13
 1501 009d 00       		.byte	0
 1502 009e 00       		.byte	0
 1503 009f 0D       		.uleb128 0xd
 1504 00a0 0D       		.uleb128 0xd
 1505 00a1 00       		.byte	0
 1506 00a2 03       		.uleb128 0x3
 1507 00a3 08       		.uleb128 0x8
 1508 00a4 3A       		.uleb128 0x3a
 1509 00a5 0B       		.uleb128 0xb
 1510 00a6 3B       		.uleb128 0x3b
 1511 00a7 0B       		.uleb128 0xb
 1512 00a8 39       		.uleb128 0x39
 1513 00a9 0B       		.uleb128 0xb
 1514 00aa 49       		.uleb128 0x49
 1515 00ab 13       		.uleb128 0x13
 1516 00ac 38       		.uleb128 0x38
 1517 00ad 0B       		.uleb128 0xb
 1518 00ae 00       		.byte	0
 1519 00af 00       		.byte	0
 1520 00b0 0E       		.uleb128 0xe
 1521 00b1 2E       		.uleb128 0x2e
 1522 00b2 01       		.byte	0x1
 1523 00b3 3F       		.uleb128 0x3f
 1524 00b4 19       		.uleb128 0x19
 1525 00b5 03       		.uleb128 0x3
 1526 00b6 08       		.uleb128 0x8
 1527 00b7 3A       		.uleb128 0x3a
 1528 00b8 0B       		.uleb128 0xb
 1529 00b9 3B       		.uleb128 0x3b
 1530 00ba 05       		.uleb128 0x5
 1531 00bb 39       		.uleb128 0x39
 1532 00bc 0B       		.uleb128 0xb
 1533 00bd 3C       		.uleb128 0x3c
 1534 00be 19       		.uleb128 0x19
 1535 00bf 01       		.uleb128 0x1
 1536 00c0 13       		.uleb128 0x13
 1537 00c1 00       		.byte	0
 1538 00c2 00       		.byte	0
 1539 00c3 0F       		.uleb128 0xf
 1540 00c4 05       		.uleb128 0x5
 1541 00c5 00       		.byte	0
 1542 00c6 49       		.uleb128 0x49
 1543 00c7 13       		.uleb128 0x13
 1544 00c8 00       		.byte	0
 1545 00c9 00       		.byte	0
 1546 00ca 10       		.uleb128 0x10
 1547 00cb 2E       		.uleb128 0x2e
 1548 00cc 01       		.byte	0x1
 1549 00cd 3F       		.uleb128 0x3f
 1550 00ce 19       		.uleb128 0x19
 1551 00cf 03       		.uleb128 0x3
 1552 00d0 08       		.uleb128 0x8
 1553 00d1 3A       		.uleb128 0x3a
 1554 00d2 0B       		.uleb128 0xb
 1555 00d3 3B       		.uleb128 0x3b
 1556 00d4 05       		.uleb128 0x5
 1557 00d5 39       		.uleb128 0x39
 1558 00d6 0B       		.uleb128 0xb
 1559 00d7 49       		.uleb128 0x49
 1560 00d8 13       		.uleb128 0x13
 1561 00d9 3C       		.uleb128 0x3c
 1562 00da 19       		.uleb128 0x19
 1563 00db 01       		.uleb128 0x1
 1564 00dc 13       		.uleb128 0x13
 1565 00dd 00       		.byte	0
 1566 00de 00       		.byte	0
 1567 00df 11       		.uleb128 0x11
 1568 00e0 2E       		.uleb128 0x2e
 1569 00e1 01       		.byte	0x1
 1570 00e2 3F       		.uleb128 0x3f
 1571 00e3 19       		.uleb128 0x19
 1572 00e4 03       		.uleb128 0x3
 1573 00e5 08       		.uleb128 0x8
 1574 00e6 3A       		.uleb128 0x3a
 1575 00e7 0B       		.uleb128 0xb
 1576 00e8 3B       		.uleb128 0x3b
 1577 00e9 05       		.uleb128 0x5
 1578 00ea 39       		.uleb128 0x39
 1579 00eb 0B       		.uleb128 0xb
 1580 00ec 6E       		.uleb128 0x6e
 1581 00ed 08       		.uleb128 0x8
 1582 00ee 49       		.uleb128 0x49
 1583 00ef 13       		.uleb128 0x13
 1584 00f0 3C       		.uleb128 0x3c
 1585 00f1 19       		.uleb128 0x19
 1586 00f2 01       		.uleb128 0x1
 1587 00f3 13       		.uleb128 0x13
 1588 00f4 00       		.byte	0
 1589 00f5 00       		.byte	0
 1590 00f6 12       		.uleb128 0x12
 1591 00f7 18       		.uleb128 0x18
 1592 00f8 00       		.byte	0
 1593 00f9 00       		.byte	0
 1594 00fa 00       		.byte	0
 1595 00fb 13       		.uleb128 0x13
 1596 00fc 0F       		.uleb128 0xf
 1597 00fd 00       		.byte	0
 1598 00fe 0B       		.uleb128 0xb
 1599 00ff 0B       		.uleb128 0xb
 1600 0100 00       		.byte	0
 1601 0101 00       		.byte	0
 1602 0102 14       		.uleb128 0x14
 1603 0103 2E       		.uleb128 0x2e
 1604 0104 00       		.byte	0
 1605 0105 3F       		.uleb128 0x3f
 1606 0106 19       		.uleb128 0x19
 1607 0107 03       		.uleb128 0x3
 1608 0108 08       		.uleb128 0x8
 1609 0109 3A       		.uleb128 0x3a
 1610 010a 0B       		.uleb128 0xb
 1611 010b 3B       		.uleb128 0x3b
 1612 010c 05       		.uleb128 0x5
 1613 010d 39       		.uleb128 0x39
 1614 010e 0B       		.uleb128 0xb
 1615 010f 49       		.uleb128 0x49
 1616 0110 13       		.uleb128 0x13
 1617 0111 3C       		.uleb128 0x3c
 1618 0112 19       		.uleb128 0x19
 1619 0113 00       		.byte	0
 1620 0114 00       		.byte	0
 1621 0115 15       		.uleb128 0x15
 1622 0116 2E       		.uleb128 0x2e
 1623 0117 01       		.byte	0x1
 1624 0118 3F       		.uleb128 0x3f
 1625 0119 19       		.uleb128 0x19
 1626 011a 03       		.uleb128 0x3
 1627 011b 08       		.uleb128 0x8
 1628 011c 3A       		.uleb128 0x3a
 1629 011d 0B       		.uleb128 0xb
 1630 011e 3B       		.uleb128 0x3b
 1631 011f 05       		.uleb128 0x5
 1632 0120 39       		.uleb128 0x39
 1633 0121 0B       		.uleb128 0xb
 1634 0122 6E       		.uleb128 0x6e
 1635 0123 08       		.uleb128 0x8
 1636 0124 49       		.uleb128 0x49
 1637 0125 13       		.uleb128 0x13
 1638 0126 11       		.uleb128 0x11
 1639 0127 01       		.uleb128 0x1
 1640 0128 12       		.uleb128 0x12
 1641 0129 07       		.uleb128 0x7
 1642 012a 40       		.uleb128 0x40
 1643 012b 18       		.uleb128 0x18
 1644 012c 9642     		.uleb128 0x2116
 1645 012e 19       		.uleb128 0x19
 1646 012f 01       		.uleb128 0x1
 1647 0130 13       		.uleb128 0x13
 1648 0131 00       		.byte	0
 1649 0132 00       		.byte	0
 1650 0133 16       		.uleb128 0x16
 1651 0134 05       		.uleb128 0x5
 1652 0135 00       		.byte	0
 1653 0136 03       		.uleb128 0x3
 1654 0137 08       		.uleb128 0x8
 1655 0138 3A       		.uleb128 0x3a
 1656 0139 0B       		.uleb128 0xb
 1657 013a 3B       		.uleb128 0x3b
 1658 013b 05       		.uleb128 0x5
 1659 013c 39       		.uleb128 0x39
 1660 013d 0B       		.uleb128 0xb
 1661 013e 49       		.uleb128 0x49
 1662 013f 13       		.uleb128 0x13
 1663 0140 02       		.uleb128 0x2
 1664 0141 18       		.uleb128 0x18
 1665 0142 00       		.byte	0
 1666 0143 00       		.byte	0
 1667 0144 17       		.uleb128 0x17
 1668 0145 34       		.uleb128 0x34
 1669 0146 00       		.byte	0
 1670 0147 03       		.uleb128 0x3
 1671 0148 08       		.uleb128 0x8
 1672 0149 3A       		.uleb128 0x3a
 1673 014a 0B       		.uleb128 0xb
 1674 014b 3B       		.uleb128 0x3b
 1675 014c 05       		.uleb128 0x5
 1676 014d 39       		.uleb128 0x39
 1677 014e 0B       		.uleb128 0xb
 1678 014f 49       		.uleb128 0x49
 1679 0150 13       		.uleb128 0x13
 1680 0151 02       		.uleb128 0x2
 1681 0152 18       		.uleb128 0x18
 1682 0153 00       		.byte	0
 1683 0154 00       		.byte	0
 1684 0155 18       		.uleb128 0x18
 1685 0156 898201   		.uleb128 0x4109
 1686 0159 00       		.byte	0
 1687 015a 11       		.uleb128 0x11
 1688 015b 01       		.uleb128 0x1
 1689 015c 31       		.uleb128 0x31
 1690 015d 13       		.uleb128 0x13
 1691 015e 00       		.byte	0
 1692 015f 00       		.byte	0
 1693 0160 19       		.uleb128 0x19
 1694 0161 34       		.uleb128 0x34
 1695 0162 00       		.byte	0
 1696 0163 03       		.uleb128 0x3
 1697 0164 08       		.uleb128 0x8
 1698 0165 3A       		.uleb128 0x3a
 1699 0166 0B       		.uleb128 0xb
 1700 0167 3B       		.uleb128 0x3b
 1701 0168 0B       		.uleb128 0xb
 1702 0169 39       		.uleb128 0x39
 1703 016a 0B       		.uleb128 0xb
 1704 016b 49       		.uleb128 0x49
 1705 016c 13       		.uleb128 0x13
 1706 016d 02       		.uleb128 0x2
 1707 016e 18       		.uleb128 0x18
 1708 016f 00       		.byte	0
 1709 0170 00       		.byte	0
 1710 0171 1A       		.uleb128 0x1a
 1711 0172 01       		.uleb128 0x1
 1712 0173 01       		.byte	0x1
 1713 0174 49       		.uleb128 0x49
 1714 0175 13       		.uleb128 0x13
 1715 0176 01       		.uleb128 0x1
 1716 0177 13       		.uleb128 0x13
 1717 0178 00       		.byte	0
 1718 0179 00       		.byte	0
 1719 017a 1B       		.uleb128 0x1b
 1720 017b 21       		.uleb128 0x21
 1721 017c 00       		.byte	0
 1722 017d 49       		.uleb128 0x49
 1723 017e 13       		.uleb128 0x13
 1724 017f 2F       		.uleb128 0x2f
 1725 0180 06       		.uleb128 0x6
 1726 0181 00       		.byte	0
 1727 0182 00       		.byte	0
 1728 0183 1C       		.uleb128 0x1c
 1729 0184 34       		.uleb128 0x34
 1730 0185 00       		.byte	0
 1731 0186 03       		.uleb128 0x3
 1732 0187 08       		.uleb128 0x8
 1733 0188 3A       		.uleb128 0x3a
 1734 0189 0B       		.uleb128 0xb
 1735 018a 3B       		.uleb128 0x3b
 1736 018b 0B       		.uleb128 0xb
 1737 018c 39       		.uleb128 0x39
 1738 018d 0B       		.uleb128 0xb
 1739 018e 49       		.uleb128 0x49
 1740 018f 13       		.uleb128 0x13
 1741 0190 3F       		.uleb128 0x3f
 1742 0191 19       		.uleb128 0x19
 1743 0192 02       		.uleb128 0x2
 1744 0193 18       		.uleb128 0x18
 1745 0194 00       		.byte	0
 1746 0195 00       		.byte	0
 1747 0196 1D       		.uleb128 0x1d
 1748 0197 2E       		.uleb128 0x2e
 1749 0198 01       		.byte	0x1
 1750 0199 3F       		.uleb128 0x3f
 1751 019a 19       		.uleb128 0x19
 1752 019b 03       		.uleb128 0x3
 1753 019c 08       		.uleb128 0x8
 1754 019d 3A       		.uleb128 0x3a
 1755 019e 0B       		.uleb128 0xb
 1756 019f 3B       		.uleb128 0x3b
 1757 01a0 0B       		.uleb128 0xb
 1758 01a1 39       		.uleb128 0x39
 1759 01a2 0B       		.uleb128 0xb
 1760 01a3 49       		.uleb128 0x49
 1761 01a4 13       		.uleb128 0x13
 1762 01a5 11       		.uleb128 0x11
 1763 01a6 01       		.uleb128 0x1
 1764 01a7 12       		.uleb128 0x12
 1765 01a8 07       		.uleb128 0x7
 1766 01a9 40       		.uleb128 0x40
 1767 01aa 18       		.uleb128 0x18
 1768 01ab 9642     		.uleb128 0x2116
 1769 01ad 19       		.uleb128 0x19
 1770 01ae 01       		.uleb128 0x1
 1771 01af 13       		.uleb128 0x13
 1772 01b0 00       		.byte	0
 1773 01b1 00       		.byte	0
 1774 01b2 1E       		.uleb128 0x1e
 1775 01b3 2E       		.uleb128 0x2e
 1776 01b4 01       		.byte	0x1
 1777 01b5 3F       		.uleb128 0x3f
 1778 01b6 19       		.uleb128 0x19
 1779 01b7 03       		.uleb128 0x3
 1780 01b8 08       		.uleb128 0x8
 1781 01b9 3A       		.uleb128 0x3a
 1782 01ba 0B       		.uleb128 0xb
 1783 01bb 3B       		.uleb128 0x3b
 1784 01bc 0B       		.uleb128 0xb
 1785 01bd 39       		.uleb128 0x39
 1786 01be 0B       		.uleb128 0xb
 1787 01bf 6E       		.uleb128 0x6e
 1788 01c0 08       		.uleb128 0x8
 1789 01c1 49       		.uleb128 0x49
 1790 01c2 13       		.uleb128 0x13
 1791 01c3 11       		.uleb128 0x11
 1792 01c4 01       		.uleb128 0x1
 1793 01c5 12       		.uleb128 0x12
 1794 01c6 07       		.uleb128 0x7
 1795 01c7 40       		.uleb128 0x40
 1796 01c8 18       		.uleb128 0x18
 1797 01c9 9642     		.uleb128 0x2116
 1798 01cb 19       		.uleb128 0x19
 1799 01cc 01       		.uleb128 0x1
 1800 01cd 13       		.uleb128 0x13
 1801 01ce 00       		.byte	0
 1802 01cf 00       		.byte	0
 1803 01d0 1F       		.uleb128 0x1f
 1804 01d1 2E       		.uleb128 0x2e
 1805 01d2 00       		.byte	0
 1806 01d3 3F       		.uleb128 0x3f
 1807 01d4 19       		.uleb128 0x19
 1808 01d5 3C       		.uleb128 0x3c
 1809 01d6 19       		.uleb128 0x19
 1810 01d7 6E       		.uleb128 0x6e
 1811 01d8 0E       		.uleb128 0xe
 1812 01d9 03       		.uleb128 0x3
 1813 01da 0E       		.uleb128 0xe
 1814 01db 3A       		.uleb128 0x3a
 1815 01dc 0B       		.uleb128 0xb
 1816 01dd 3B       		.uleb128 0x3b
 1817 01de 0B       		.uleb128 0xb
 1818 01df 39       		.uleb128 0x39
 1819 01e0 0B       		.uleb128 0xb
 1820 01e1 00       		.byte	0
 1821 01e2 00       		.byte	0
 1822 01e3 00       		.byte	0
 1823              		.section	.debug_aranges,"dr"
 1824 0000 5C000000 		.long	0x5c
 1825 0004 0200     		.word	0x2
 1826 0006 00000000 		.secrel32	.Ldebug_info0
 1827 000a 08       		.byte	0x8
 1828 000b 00       		.byte	0
 1829 000c 0000     		.word	0
 1830 000e 0000     		.word	0
 1831 0010 00000000 		.quad	.Ltext0
 1831      00000000 
 1832 0018 31000000 		.quad	.Letext0-.Ltext0
 1832      00000000 
 1833 0020 00000000 		.quad	.LFB8
 1833      00000000 
 1834 0028 54000000 		.quad	.LFE8-.LFB8
 1834      00000000 
 1835 0030 00000000 		.quad	.LFB44
 1835      00000000 
 1836 0038 9E000000 		.quad	.LFE44-.LFB44
 1836      00000000 
 1837 0040 00000000 		.quad	.LFB45
 1837      00000000 
 1838 0048 66000000 		.quad	.LFE45-.LFB45
 1838      00000000 
 1839 0050 00000000 		.quad	0
 1839      00000000 
 1840 0058 00000000 		.quad	0
 1840      00000000 
 1841              		.section	.debug_ranges,"dr"
 1842              	.Ldebug_ranges0:
 1843 0000 00000000 		.quad	.Ltext0
 1843      00000000 
 1844 0008 31000000 		.quad	.Letext0
 1844      00000000 
 1845 0010 00000000 		.quad	.LFB8
 1845      00000000 
 1846 0018 54000000 		.quad	.LFE8
 1846      00000000 
 1847 0020 00000000 		.quad	.LFB44
 1847      00000000 
 1848 0028 9E000000 		.quad	.LFE44
 1848      00000000 
 1849 0030 00000000 		.quad	.LFB45
 1849      00000000 
 1850 0038 66000000 		.quad	.LFE45
 1850      00000000 
 1851 0040 00000000 		.quad	0
 1851      00000000 
 1852 0048 00000000 		.quad	0
 1852      00000000 
 1853              		.section	.debug_line,"dr"
 1854              	.Ldebug_line0:
 1855 0000 BD020000 		.section	.debug_str,"dr"
 1855      0200D101 
 1855      00000101 
 1855      FB0E0D00 
 1855      01010101 
 1856              	.LASF0:
 1857 0000 5F5F6163 		.ascii "__acrt_iob_func\0"
 1857      72745F69 
 1857      6F625F66 
 1857      756E6300 
 1858              		.ident	"GCC: (x86_64-win32-seh-rev0, Built by MinGW-W64 project) 8.1.0"
