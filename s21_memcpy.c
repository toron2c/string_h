

#include <stdio.h>

#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *pcopy = s21_NULL;
  if (dest && src) {
    unsigned char *pdest = (unsigned char *)dest;
    unsigned char *psrc = (unsigned char *)src;
    pcopy = pdest;
    for (; n; pdest++, n--) {
      if (*psrc) {
        *pdest = *psrc;
        psrc++;
      } else {
        *pdest = '\0';
      }
    }
  }
  return (void *)pcopy;
}
