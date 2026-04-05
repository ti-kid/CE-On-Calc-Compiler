#ifndef OUTBUF_H
#define OUTBUF_H

#include <stdio.h>
#include <stddef.h>
#include <stdarg.h>
#include <string.h>

// Simple output string buffer - replaces the broken FILE* cast approach.
// Used by codegen and format() to write formatted text to memory.
typedef struct {
    char *buf;
    size_t pos;
    size_t cap;
} OutBuf;

static inline void outbuf_init(OutBuf *ob, char *buf, size_t cap) {
    ob->buf = buf;
    ob->pos = 0;
    ob->cap = cap;
    if (cap > 0)
        buf[0] = '\0';
}

static inline void outbuf_putc(OutBuf *ob, char c) {
    if (ob->pos < ob->cap - 1) {
        ob->buf[ob->pos++] = c;
        ob->buf[ob->pos] = '\0';
    }
}

static inline void outbuf_puts(OutBuf *ob, const char *s) {
    while (*s)
        outbuf_putc(ob, *s++);
}

static inline void outbuf_printf(OutBuf *ob, const char *fmt, ...) {
    if (ob->pos >= ob->cap - 1)
        return;
    va_list ap;
    va_start(ap, fmt);
    int n = vsnprintf(ob->buf + ob->pos, ob->cap - ob->pos, fmt, ap);
    va_end(ap);
    if (n > 0) {
        if ((size_t)n >= ob->cap - ob->pos)
            ob->pos = ob->cap - 1;
        else
            ob->pos += n;
    }
}

static inline void outbuf_vprintf(OutBuf *ob, const char *fmt, va_list ap) {
    if (ob->pos >= ob->cap - 1)
        return;
    int n = vsnprintf(ob->buf + ob->pos, ob->cap - ob->pos, fmt, ap);
    if (n > 0) {
        if ((size_t)n >= ob->cap - ob->pos)
            ob->pos = ob->cap - 1;
        else
            ob->pos += n;
    }
}

static inline size_t outbuf_len(OutBuf *ob) {
    return ob->pos;
}

#endif
