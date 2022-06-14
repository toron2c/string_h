

#include <stdio.h>

#include "s21_string.h"

//  Выполняет поиск последнего вхождения символа c (беззнаковый тип) в строке,
//   на которую указывает аргумент str.
char *s21_strrchr(const char *str, int c) {
  const char *s = s21_NULL;
  const char *copy = str;
  for (; *str; str++) {
  }
  for (; copy - str <= 0; str--) {
    if (*str == (char)c) {
      s = str;
      break;
    }
  }
  return (char *)s;
}
