

#include <stdio.h>

#include "s21_string.h"

//  Разбивает строку str на ряд токенов, разделенных delim.
char *s21_strtok(char *str, const char *delim) {
  static char *reserve = s21_NULL;
  if (str == s21_NULL) str = reserve;
  if (str != s21_NULL) {
    str = str +
          s21_strspn(
              str,
              delim);  //  передв указатель на первый эл-т, не входящий в delim
    char *copy = str;
    str =
        str +
        s21_strcspn(
            copy, delim);  //  передв указатель на кол-во эл-тов, не вх в delim
    if (*str) {
      *str = '\0';  //  ставим конец строки на первый эл-т, вх в delim
      reserve = str;
      reserve++;
    } else {
      reserve = s21_NULL;
    }
    str = copy;
    //  передв указатель на первый эл-т, не вход в delim
    if (reserve) reserve = reserve + s21_strspn(reserve, delim);
    if (!s21_strlen(str)) str = reserve = s21_NULL;
  }
  return str;
}
