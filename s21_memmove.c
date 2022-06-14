

#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  unsigned char *copy = s21_NULL;
  if (dest && src) {
    s21_size_t count = s21_strlen((char *)dest);
    if (count < s21_strlen((char *)src)) count = s21_strlen((char *)src);
    if (n > count) count = n;
    unsigned char *p =
        (unsigned char *)malloc(sizeof(unsigned char) * (count + 1));
    if (p) {
      p[count] = '\0';
      copy = p;
      unsigned char *copydest = (unsigned char *)dest;
      s21_memcpy(p, dest, s21_strlen((char *)dest));
      for (; n; p++, n--) {
        if (*(unsigned char *)src) {
          *(unsigned char *)p = *(unsigned char *)src;
          src++;
        } else {
          *(unsigned char *)p = '\0';
        }
      }
      dest = copydest;
      p = copy;
      s21_memcpy(dest, p, s21_strlen((char *)p));
      copy = copydest;
      free(p);
    }
  }
  return (void *)copy;
}
