

#include <stdio.h>

#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *copy = dest;
  for (; n; dest++, n--) {
    if (*src) {
      *dest = *src;
      src++;
    } else {
      *dest = '\0';
    }
  }
  return copy;
}
