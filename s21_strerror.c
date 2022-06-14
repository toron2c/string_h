
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

//  Выполняет поиск во внутреннем массиве номера ошибки errnum и возвращает
//   указатель на строку с сообщением об ошибке. Нужно объявить макросы,
//   содержащие массивы сообщений об ошибке для операционных систем mac и linux.
//   Описания ошибок есть в оригинальной библиотеке. Проверка текущей ОС
//   осуществляется с помощью директив.
char* s21_strerror(int errnum) {
  static char output[30];
  char errnumstr[12];
#ifdef __linux__
  if (errnum > 133 || errnum < 0) {
    s21_strcpy(output, "Unknown error ");
    itostr(errnumstr, errnum);
    s21_strcat(output, errnumstr);
  } else {
    char* errors[134] = LINUX;
    s21_strcpy(output, errors[errnum]);
  }
#elif __APPLE__
  if (errnum > 106 || errnum < 0) {
    s21_strcpy(output, "Unknown error: ");
    itostr(errnumstr, errnum);
    s21_strcat(output, errnumstr);
  } else {
    char* errors[107] = MAC;
    s21_strcpy(output, errors[errnum]);
  }
#endif
  return output;
}

//  Выполняет преобразование числа типа int в строку.
void itostr(char* output, int num) {
  int count = 0;
  int numcopy = num;
  for (; num; num = num / 10) count++;
  if (numcopy < 0) {
    output[0] = '-';
    count++;
  }
  output[count] = '\0';
  count--;
  num = numcopy;
  int factor = 1;
  for (; num; count--) {
    if (num % 10 < 0) factor = -1;
    output[count] = (char)(factor * (num % 10) + 48);
    num = num / 10;
    factor = 1;
  }
}
