#ifndef BUILTIN_HEADERS_H
#define BUILTIN_HEADERS_H

// Built-in standard library headers for on-calc compilation.
// These provide declarations only. The actual implementations
// come from the CE toolchain runtime libraries.
//
// When the compiler sees #include <stdio.h>, it tokenizes the
// corresponding string below instead of reading a file.

// -------------------------------------------------------
// <stddef.h>
// -------------------------------------------------------
static const char builtin_stddef_h[] =
  "#ifndef _STDDEF_H\n"
  "#define _STDDEF_H\n"
  "typedef unsigned int size_t;\n"
  "typedef int ptrdiff_t;\n"
  "#define NULL ((void*)0)\n"
  "#define offsetof(type, member) ((size_t)&((type*)0)->member)\n"
  "#endif\n";

// -------------------------------------------------------
// <stdbool.h>
// -------------------------------------------------------
static const char builtin_stdbool_h[] =
  "#ifndef _STDBOOL_H\n"
  "#define _STDBOOL_H\n"
  "#define bool _Bool\n"
  "#define true 1\n"
  "#define false 0\n"
  "#endif\n";

// -------------------------------------------------------
// <stdint.h>
// -------------------------------------------------------
static const char builtin_stdint_h[] =
  "#ifndef _STDINT_H\n"
  "#define _STDINT_H\n"
  "typedef signed char int8_t;\n"
  "typedef unsigned char uint8_t;\n"
  "typedef short int16_t;\n"
  "typedef unsigned short uint16_t;\n"
  "typedef long int32_t;\n"
  "typedef unsigned long uint32_t;\n"
  "typedef int intptr_t;\n"
  "typedef unsigned int uintptr_t;\n"
  "#define INT8_MIN (-128)\n"
  "#define INT8_MAX 127\n"
  "#define UINT8_MAX 255\n"
  "#define INT16_MIN (-32768)\n"
  "#define INT16_MAX 32767\n"
  "#define UINT16_MAX 65535\n"
  "#define INT32_MIN (-2147483647L-1)\n"
  "#define INT32_MAX 2147483647L\n"
  "#define UINT32_MAX 4294967295UL\n"
  "#endif\n";

// -------------------------------------------------------
// <limits.h>
// -------------------------------------------------------
static const char builtin_limits_h[] =
  "#ifndef _LIMITS_H\n"
  "#define _LIMITS_H\n"
  "#define CHAR_BIT 8\n"
  "#define SCHAR_MIN (-128)\n"
  "#define SCHAR_MAX 127\n"
  "#define UCHAR_MAX 255\n"
  "#define CHAR_MIN (-128)\n"
  "#define CHAR_MAX 127\n"
  "#define SHRT_MIN (-32768)\n"
  "#define SHRT_MAX 32767\n"
  "#define USHRT_MAX 65535\n"
  "#define INT_MIN (-8388608)\n"
  "#define INT_MAX 8388607\n"
  "#define UINT_MAX 16777215U\n"
  "#define LONG_MIN (-2147483647L-1)\n"
  "#define LONG_MAX 2147483647L\n"
  "#define ULONG_MAX 4294967295UL\n"
  "#endif\n";

// -------------------------------------------------------
// <stdarg.h>
// -------------------------------------------------------
static const char builtin_stdarg_h[] =
  "#ifndef _STDARG_H\n"
  "#define _STDARG_H\n"
  "typedef __builtin_va_list va_list;\n"
  "#define va_start(ap, param) __builtin_va_start(ap, param)\n"
  "#define va_end(ap) __builtin_va_end(ap)\n"
  "#define va_arg(ap, type) __builtin_va_arg(ap, type)\n"
  "#endif\n";

// -------------------------------------------------------
// <string.h>
// -------------------------------------------------------
static const char builtin_string_h[] =
  "#ifndef _STRING_H\n"
  "#define _STRING_H\n"
  "typedef unsigned int size_t;\n"
  "void *memcpy(void *dest, const void *src, size_t n);\n"
  "void *memmove(void *dest, const void *src, size_t n);\n"
  "void *memset(void *s, int c, size_t n);\n"
  "int memcmp(const void *s1, const void *s2, size_t n);\n"
  "void *memchr(const void *s, int c, size_t n);\n"
  "size_t strlen(const char *s);\n"
  "char *strcpy(char *dest, const char *src);\n"
  "char *strncpy(char *dest, const char *src, size_t n);\n"
  "char *strcat(char *dest, const char *src);\n"
  "char *strncat(char *dest, const char *src, size_t n);\n"
  "int strcmp(const char *s1, const char *s2);\n"
  "int strncmp(const char *s1, const char *s2, size_t n);\n"
  "char *strchr(const char *s, int c);\n"
  "char *strrchr(const char *s, int c);\n"
  "char *strstr(const char *haystack, const char *needle);\n"
  "char *strdup(const char *s);\n"
  "char *strndup(const char *s, size_t n);\n"
  "#define NULL ((void*)0)\n"
  "#endif\n";

// -------------------------------------------------------
// <stdlib.h>
// -------------------------------------------------------
static const char builtin_stdlib_h[] =
  "#ifndef _STDLIB_H\n"
  "#define _STDLIB_H\n"
  "typedef unsigned int size_t;\n"
  "#define NULL ((void*)0)\n"
  "#define EXIT_SUCCESS 0\n"
  "#define EXIT_FAILURE 1\n"
  "void *malloc(size_t size);\n"
  "void *calloc(size_t nmemb, size_t size);\n"
  "void *realloc(void *ptr, size_t size);\n"
  "void free(void *ptr);\n"
  "void exit(int status);\n"
  "void abort(void);\n"
  "int abs(int n);\n"
  "long labs(long n);\n"
  "int atoi(const char *s);\n"
  "long atol(const char *s);\n"
  "long strtol(const char *s, char **endp, int base);\n"
  "unsigned long strtoul(const char *s, char **endp, int base);\n"
  "int rand(void);\n"
  "void srand(unsigned int seed);\n"
  "#define RAND_MAX 32767\n"
  "#endif\n";

// -------------------------------------------------------
// <ctype.h>
// -------------------------------------------------------
static const char builtin_ctype_h[] =
  "#ifndef _CTYPE_H\n"
  "#define _CTYPE_H\n"
  "int isalpha(int c);\n"
  "int isdigit(int c);\n"
  "int isalnum(int c);\n"
  "int isspace(int c);\n"
  "int isupper(int c);\n"
  "int islower(int c);\n"
  "int isprint(int c);\n"
  "int ispunct(int c);\n"
  "int isxdigit(int c);\n"
  "int iscntrl(int c);\n"
  "int toupper(int c);\n"
  "int tolower(int c);\n"
  "#endif\n";

// -------------------------------------------------------
// <stdio.h>
// -------------------------------------------------------
static const char builtin_stdio_h[] =
  "#ifndef _STDIO_H\n"
  "#define _STDIO_H\n"
  "typedef unsigned int size_t;\n"
  "#define NULL ((void*)0)\n"
  "#define EOF (-1)\n"
  "\n"
  "// printf family — these work on the CE home screen\n"
  "int printf(const char *fmt, ...);\n"
  "int sprintf(char *buf, const char *fmt, ...);\n"
  "int snprintf(char *buf, size_t n, const char *fmt, ...);\n"
  "\n"
  "// puts/putchar — screen output\n"
  "int puts(const char *s);\n"
  "int putchar(int c);\n"
  "\n"
  "// getchar — reads a key\n"
  "int getchar(void);\n"
  "\n"
  "#endif\n";

// -------------------------------------------------------
// <errno.h>
// -------------------------------------------------------
static const char builtin_errno_h[] =
  "#ifndef _ERRNO_H\n"
  "#define _ERRNO_H\n"
  "extern int errno;\n"
  "#define EDOM 1\n"
  "#define ERANGE 2\n"
  "#endif\n";

// -------------------------------------------------------
// <assert.h>
// -------------------------------------------------------
static const char builtin_assert_h[] =
  "#ifndef _ASSERT_H\n"
  "#define _ASSERT_H\n"
  "void abort(void);\n"
  "#ifdef NDEBUG\n"
  "#define assert(x) ((void)0)\n"
  "#else\n"
  "#define assert(x) ((x) ? (void)0 : abort())\n"
  "#endif\n"
  "#endif\n";

// -------------------------------------------------------
// <tice.h> — TI CE specific functions
// -------------------------------------------------------
static const char builtin_tice_h[] =
  "#ifndef _TICE_H\n"
  "#define _TICE_H\n"
  "typedef unsigned int size_t;\n"
  "#define NULL ((void*)0)\n"
  "\n"
  "// Screen output\n"
  "void os_ClrHome(void);\n"
  "void os_ClrHomeFull(void);\n"
  "void os_PutStrFull(const char *s);\n"
  "void os_PutStrLine(const char *s);\n"
  "void os_NewLine(void);\n"
  "void os_SetCursorPos(unsigned char row, unsigned char col);\n"
  "\n"
  "// Keyboard input\n"
  "int os_GetCSC(void);\n"
  "\n"
  "// Math\n"
  "int os_RandInt(int min, int max);\n"
  "\n"
  "// System\n"
  "void delay(unsigned short ms);\n"
  "void msleep(unsigned short ms);\n"
  "unsigned long timer_Get(int n);\n"
  "void timer_Set(int n, unsigned long val);\n"
  "void timer_Enable(int n, int mode, int intmode);\n"
  "void timer_Disable(int n);\n"
  "#define TIMER_32K 0\n"
  "#define TIMER_CPU 1\n"
  "#define TIMER_0INT 0\n"
  "#define TIMER_NOINT 1\n"
  "\n"
  "// Real/float conversion\n"
  "int os_Int24ToReal(int val, void *real);\n"
  "int os_RealToInt24(const void *real);\n"
  "\n"
  "// Key codes\n"
  "#define sk_Down    1\n"
  "#define sk_Left    2\n"
  "#define sk_Right   3\n"
  "#define sk_Up      4\n"
  "#define sk_Enter   9\n"
  "#define sk_2nd     54\n"
  "#define sk_Clear   15\n"
  "#define sk_Del     7\n"
  "#define sk_Mode    55\n"
  "#define sk_Graph   31\n"
  "#define sk_Yequ    22\n"
  "#define sk_Window  23\n"
  "#define sk_Zoom    24\n"
  "#define sk_Trace   25\n"
  "#endif\n";

// -------------------------------------------------------
// <graphx.h> — TI CE graphics library
// -------------------------------------------------------
static const char builtin_graphx_h[] =
  "#ifndef _GRAPHX_H\n"
  "#define _GRAPHX_H\n"
  "\n"
  "void gfx_Begin(void);\n"
  "void gfx_End(void);\n"
  "void gfx_SetColor(unsigned char color);\n"
  "void gfx_SetPixel(int x, unsigned char y);\n"
  "unsigned char gfx_GetPixel(int x, unsigned char y);\n"
  "void gfx_Line(int x0, int y0, int x1, int y1);\n"
  "void gfx_HorizLine(int x, unsigned char y, int len);\n"
  "void gfx_VertLine(int x, unsigned char y, int len);\n"
  "void gfx_Rectangle(int x, unsigned char y, int w, unsigned char h);\n"
  "void gfx_FillRectangle(int x, unsigned char y, int w, unsigned char h);\n"
  "void gfx_Circle(int x, unsigned char y, unsigned char r);\n"
  "void gfx_FillCircle(int x, unsigned char y, unsigned char r);\n"
  "void gfx_PrintStringXY(const char *s, int x, unsigned char y);\n"
  "void gfx_PrintString(const char *s);\n"
  "void gfx_PrintInt(int val, unsigned char len);\n"
  "void gfx_PrintChar(char c);\n"
  "void gfx_SetTextXY(int x, unsigned char y);\n"
  "void gfx_SetTextFGColor(unsigned char color);\n"
  "void gfx_SetTextBGColor(unsigned char color);\n"
  "void gfx_SetTextScale(unsigned char w, unsigned char h);\n"
  "void gfx_FillScreen(unsigned char color);\n"
  "void gfx_SwapDraw(void);\n"
  "void gfx_SetDrawBuffer(void);\n"
  "void gfx_SetDrawScreen(void);\n"
  "void gfx_BlitBuffer(void);\n"
  "int gfx_GetStringWidth(const char *s);\n"
  "unsigned char gfx_GetCharWidth(char c);\n"
  "\n"
  "#define gfx_lcd_width  320\n"
  "#define gfx_lcd_height 240\n"
  "#endif\n";

// -------------------------------------------------------
// <keypadc.h> — TI CE keypad
// -------------------------------------------------------
static const char builtin_keypadc_h[] =
  "#ifndef _KEYPADC_H\n"
  "#define _KEYPADC_H\n"
  "typedef unsigned char kb_key_t;\n"
  "typedef unsigned short kb_lkey_t;\n"
  "void kb_Scan(void);\n"
  "kb_key_t kb_Data[8];\n"
  "#define kb_group_0 0\n"
  "#define kb_group_1 1\n"
  "#define kb_group_2 2\n"
  "#define kb_group_3 3\n"
  "#define kb_group_4 4\n"
  "#define kb_group_5 5\n"
  "#define kb_group_6 6\n"
  "#define kb_group_7 7\n"
  "#define kb_KeyDown  1\n"
  "#define kb_KeyLeft  2\n"
  "#define kb_KeyRight 4\n"
  "#define kb_KeyUp    8\n"
  "#define kb_Key2nd   (1<<5)\n"
  "#define kb_KeyAlpha (1<<6)\n"
  "#define kb_KeyDel   (1<<7)\n"
  "#define kb_KeyClear (1<<6)\n"
  "#define kb_KeyEnter (1<<0)\n"
  "#endif\n";

// -------------------------------------------------------
// <fileioc.h> — TI CE AppVar file I/O
// -------------------------------------------------------
static const char builtin_fileioc_h[] =
  "#ifndef _FILEIOC_H\n"
  "#define _FILEIOC_H\n"
  "typedef unsigned int size_t;\n"
  "typedef unsigned char ti_var_t;\n"
  "ti_var_t ti_Open(const char *name, const char *mode);\n"
  "int ti_Close(ti_var_t slot);\n"
  "size_t ti_Read(void *buf, size_t size, size_t count, ti_var_t slot);\n"
  "size_t ti_Write(const void *buf, size_t size, size_t count, ti_var_t slot);\n"
  "int ti_GetSize(ti_var_t slot);\n"
  "int ti_Seek(int offset, int origin, ti_var_t slot);\n"
  "int ti_Tell(ti_var_t slot);\n"
  "int ti_Rewind(ti_var_t slot);\n"
  "int ti_Delete(const char *name);\n"
  "int ti_DeleteVar(const char *name, unsigned char type);\n"
  "void *ti_GetDataPtr(ti_var_t slot);\n"
  "#define TI_PRGM_TYPE 5\n"
  "#define TI_PPRGM_TYPE 6\n"
  "#define TI_APPVAR_TYPE 21\n"
  "#endif\n";

// -------------------------------------------------------
// Lookup table: maps header name -> content string
// -------------------------------------------------------
typedef struct {
  const char *name;
  const char *content;
} BuiltinHeader;

static const BuiltinHeader builtin_headers[] = {
  {"stddef.h",   builtin_stddef_h},
  {"stdbool.h",  builtin_stdbool_h},
  {"stdint.h",   builtin_stdint_h},
  {"limits.h",   builtin_limits_h},
  {"stdarg.h",   builtin_stdarg_h},
  {"string.h",   builtin_string_h},
  {"stdlib.h",   builtin_stdlib_h},
  {"ctype.h",    builtin_ctype_h},
  {"stdio.h",    builtin_stdio_h},
  {"errno.h",    builtin_errno_h},
  {"assert.h",   builtin_assert_h},
  {"tice.h",     builtin_tice_h},
  {"graphx.h",   builtin_graphx_h},
  {"keypadc.h",  builtin_keypadc_h},
  {"fileioc.h",  builtin_fileioc_h},
  {0, 0},
};

// Find a built-in header by name. Returns content string or NULL.
static const char *find_builtin_header(const char *name) {
  // Strip leading path separators or angle brackets
  const char *base = name;
  for (const char *p = name; *p; p++) {
    if (*p == '/' || *p == '\\')
      base = p + 1;
  }

  for (int i = 0; builtin_headers[i].name; i++) {
    if (strcmp(builtin_headers[i].name, base) == 0)
      return builtin_headers[i].content;
  }
  return 0;
}

#endif
