

#include <stdio.h>

#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  const char *s = s21_NULL;
  //  if (str) {
  for (; *str; str++) {
    if (*str == (char)c) {
      s = str;
      break;
    }
  }
  if (*str == (char)c) s = str;
  //  }
  return (char *)s;
}
