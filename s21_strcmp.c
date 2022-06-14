

#include <stdio.h>

#include "s21_string.h"

int s21_strcmp(const char *str1, const char *str2) {
  int code = 0;
  for (; *str1 && *str2 == *str1; str1++, str2++) {
  }
  if (*str1 > *str2) code = 1;
  if (*str1 < *str2) code = -1;
  return code;
}
