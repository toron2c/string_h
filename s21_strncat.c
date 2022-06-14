

#include <stdio.h>

#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *copy = dest;
  s21_size_t delta = n > s21_strlen(src) ? s21_strlen(src) : n;
  for (; *dest; dest++) {
  }
  for (; delta; src++, dest++, delta--) *dest = *src;
  *dest = '\0';
  return copy;
}
