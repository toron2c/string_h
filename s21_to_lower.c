
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

//  Возвращает копию строки (str), преобразованной в нижний регистр.
//   В случае какой-либо ошибки следует вернуть значение NULL
void *s21_to_lower(const char *str) {
  char *copy = s21_NULL;
  if (str != s21_NULL) {
    char *output = (char *)malloc(sizeof(char) * (1 + s21_strlen(str)));
    copy = output;
    if (output != s21_NULL) {
      for (; *str; str++, output++)
        if (*str > 64 && *str < 91)
          *output = *str + 32;
        else
          *output = *str;
      *output = '\0';
    }
  }
  return copy;
}
