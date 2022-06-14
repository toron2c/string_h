
#include <stdio.h>

#include "s21_string.h"

//  Находит первое вхождение всей строки needle (не включая завершающий нулевой
//  символ),
//   которая появляется в строке haystack.
char *s21_strstr(const char *haystack, const char *needle) {
  const char *output;
  if (s21_strlen(needle) == 0) {
    output = haystack;
  } else {
    int flag = 0;  //  flag is up when the first letter of needle is found
    const char *copy = needle;
    for (; *haystack && *needle; haystack++) {
      if (*haystack == *needle) {
        if (!flag) {
          output = haystack;
          flag = 1;
        }
        needle++;
      } else {
        needle = copy;
        flag = 0;
      }
    }
    if (*needle) output = s21_NULL;
  }
  return (char *)output;
}
