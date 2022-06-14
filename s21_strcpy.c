
#include <stdio.h>

#include "s21_string.h"

char *s21_strcpy(char *dest, const char *src) {
  char *copy = dest;
  if (dest && src) {
    for (; *src; src++, dest++) {
      *dest = *src;
    }
    *dest = '\0';
  }
  return copy;
}
