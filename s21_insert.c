#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *copy = s21_NULL;
  if (src != s21_NULL) {
    if (str == s21_NULL) {
      copy = (char *)malloc(sizeof(char) * (s21_strlen(src) + 1));
      s21_strcpy(copy, src);
    }
    if (src != s21_NULL && str != s21_NULL && start_index <= s21_strlen(src)) {
      char *output = (char *)malloc(sizeof(char) *
                                    (1 + s21_strlen(src) + s21_strlen(str)));
      copy = output;
      if (output != s21_NULL) {
        for (s21_size_t i = 0; i < start_index; i++, src++, output++)
          *output = *src;
        for (; *str; str++, output++) *output = *str;
        for (; *src; src++, output++) *output = *src;
        *output = '\0';
      }
    }
  }
  return copy;
}
