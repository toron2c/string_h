

#include <stdio.h>

#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
  const char *strcopy = str;
  s21_size_t count = 0;
  if (strcopy != s21_NULL) {
    for (; strcopy[count]; count++) {
    }
  }
  return count;
}
