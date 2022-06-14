

#include <stdio.h>

#include "s21_string.h"

//  Вычисляет длину начального сегмента str1,
//   который полностью состоит из символов, не входящих в str2.
s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t count = 0;
  const char *copy = str2;
  int flag = 0;
  for (; *str1; str1++) {
    for (; *str2; str2++) {
      if (*str1 == *str2) {
        flag = 1;
        break;
      }
    }
    str2 = copy;
    if (!flag)
      count++;
    else
      break;
  }
  return count;
}
