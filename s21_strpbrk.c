

#include <stdio.h>

#include "s21_string.h"

//  Находит первый символ в строке str1,
//   который соответствует любому символу, указанному в str2.
char *s21_strpbrk(const char *str1, const char *str2) {
  s21_size_t count = s21_strcspn(str1, str2);
  return s21_strlen(str1) == count ? s21_NULL : (char *)str1 + count;
}
