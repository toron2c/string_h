

#include <stdio.h>

#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int code = 0;
  for (; n && str1 && str2; n--) {
    if (*str1 > *str2) {
      code = 1;
      break;
    }
    if (*str1 < *str2) {
      code = -1;
      break;
    }
    if (*str1 && *str2) {
      str1++;
      str2++;
    }
  }
  return code;
}
