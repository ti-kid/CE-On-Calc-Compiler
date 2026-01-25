#ifndef MEMFILE_H
#define MEMFILE_H

#include <stdio.h>
#include <stddef.h>

typedef struct {
    char *buf;
    size_t pos;
    size_t cap;
} MEMFILE;

static inline FILE *mem_fopen(char *buf, size_t cap) {
    MEMFILE *m = malloc(sizeof(MEMFILE));
    m->buf = buf;
    m->pos = 0;
    m->cap = cap;
    return (FILE*)m;
}

static inline int mem_fputc(int c, FILE *fp) {
    MEMFILE *m = (MEMFILE*)fp;
    if (m->pos < m->cap - 1) {
        m->buf[m->pos++] = c;
        m->buf[m->pos] = '\0';
    }
    return c;
}

static inline size_t mem_fwrite(const void *ptr, size_t size, size_t nmemb, FILE *fp) {
    MEMFILE *m = (MEMFILE*)fp;
    size_t total = size * nmemb;
    for (size_t i = 0; i < total; i++)
        mem_fputc(((char*)ptr)[i], fp);
    return nmemb;
}

static inline int mem_fclose(FILE *fp) {
    free(fp);
    return 0;
}

#endif

