

#include <stdio.h>

#include "s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  char *copy = s21_NULL;
  if (str && n > 0) {
    copy = str;
    for (; n; str++, n--) *(char *)str = (char)c;
  }
  return copy;
}
