

#include <stdio.h>

#include "s21_string.h"

char *s21_strcat(char *dest, const char *src) {
  char *copy = dest;
  for (; *dest; dest++) {
  }
  for (; *src; src++, dest++) *dest = *src;
  *dest = '\0';
  return copy;
}
