

#include <stdio.h>

#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int code = 0;
  unsigned char *pstr1 = (unsigned char *)str1;
  unsigned char *pstr2 = (unsigned char *)str2;
  for (; n && pstr1 && pstr2; n--) {
    if (*pstr1 > *pstr2) {
      code = 1;
      break;
    }
    if (*pstr1 < *pstr2) {
      code = -1;
      break;
    }
    if (*pstr1 && *pstr2) {
      pstr1++;
      pstr2++;
    }
  }
  return code;
}
