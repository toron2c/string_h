

#include <stdio.h>

#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  void *output = s21_NULL;
  unsigned char *pstr = (unsigned char *)str;
  for (; pstr && n; n--) {
    if (*pstr == (unsigned char)c) {
      output = pstr;
      break;
    }
    pstr++;
  }
  return output;
}
