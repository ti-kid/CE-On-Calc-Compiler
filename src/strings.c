#include "chibicc.h"

void strarray_push(StringArray *arr, char *s) {
  if (!arr->data) {
    arr->data = calloc(8, sizeof(char *));
    arr->capacity = 8;
  }

  if (arr->capacity == arr->len) {
    arr->data = realloc(arr->data, sizeof(char *) * arr->capacity * 2);
    arr->capacity *= 2;
    for (int i = arr->len; i < arr->capacity; i++)
      arr->data[i] = NULL;
  }

  arr->data[arr->len++] = s;
}

// Takes a printf-style format string and returns a formatted string.
char *format(char *fmt, ...) {
  char tmp[256];
  va_list ap;
  va_start(ap, fmt);
  int n = vsnprintf(tmp, sizeof(tmp), fmt, ap);
  va_end(ap);

  char *buf = malloc(n + 1);
  if (n < (int)sizeof(tmp)) {
    memcpy(buf, tmp, n + 1);
  } else {
    va_start(ap, fmt);
    vsnprintf(buf, n + 1, fmt, ap);
    va_end(ap);
  }
  return buf;
}
