
#include <stdio.h>

#include "s21_string.h"

//  Вычисляет длину начального сегмента str1,
//   который полностью состоит из символов str2.
s21_size_t s21_strspn(const char *str1, const char *str2) {
  const char *copy = str2;
  int flag = 0;
  s21_size_t count = 0;
  for (; *str1; str1++) {
    for (; *str2; str2++) {
      if (*str1 == *str2) {
        flag = 1;
        break;
      }
    }
    if (flag) {
      count++;
      str2 = copy;
      flag = 0;
    } else {
      break;
    }
  }
  return count;
}
