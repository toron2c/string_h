#include <locale.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include "s21_string.h"

//  %[*][ширина][длина]спецификатор
int s21_sscanf(const char* str, const char* format, ...) {
  (void)setlocale(LC_ALL, "en-US");
  const char* ptr_str = str;
  int sscanf_result = 0;  //  количество считанных переменных
  //  возвращает -1 (EOF) если str или format == NULL
  if (!*str || !*format) sscanf_result = -1;
  va_list arg;
  va_start(arg, format);
  //  если в str только знаки разделители, то sscanf_result = -1
  const char* ptr_str1 = str;  //  чтобы не менять str
  while (separator_character(*ptr_str1)) ptr_str1++;
  if (!*ptr_str1) sscanf_result = -1;

  while (*format) {
    str = sscanf_search_specifier(str, format);
    format = current_format(format);
    struct_sscanf_format Format = {0, 0, 0, 0};
    format = sscanf_parse_format(format, &Format);
    if (Format.specifier != 'c')
      while (separator_character(*str)) str++;
    if (!error(str, Format)) {
      //  -----------------------------//-c-//  ------------------------------
      if (Format.specifier == 'c') {
        if (Format.star == 0) {
          if (Format.length == '\0') {
            char* arg_char = va_arg(arg, char*);
            *arg_char = *str++;
            while (--Format.width > 0 && *str) {
              str++;
            }
          }
          if (Format.length == 'l') {
            wchar_t* arg_char = va_arg(arg, wchar_t*);
            mbstowcs(arg_char, str, 1);
            str += mblen(str, 4);
          }
        } else {
          if (Format.length == '\0') {
            str++;
            while (--Format.width > 0 && *str) {
              str++;
            }
          }
        }
      }
      //  -----------------------------//-s-//  -------------------------------
      if (Format.specifier == 's') {
        if (Format.star == 0) {
          if (Format.length == '\0') {
            char* arg_str = va_arg(arg, char*);
            *arg_str = '\0';
            str = str_to_s(str, Format, arg_str);
          }
          if (Format.length == 'l') {
            wchar_t* arg_str = va_arg(arg, wchar_t*);
            str = wstr_to_ws(str, Format, arg_str);
          }
        } else {
          int flag_width = 1;
          while (!separator_character(*str) && flag_width && *str) {
            str++;
            if (--Format.width == 0) flag_width = 0;
          }
        }
      }
      //  -----------------------------//-i-//  ----------------------------
      if (Format.specifier == 'i') {
        str_to_i(str, &Format);  //  меняем спецификатор на d, o или x
      }
      //  -----------------------------//-d-//  ----------------------------
      if (Format.specifier == 'd') {
        long long int result;
        str = str_to_d(str, Format, &result);
        if (Format.star == 0) {
          if (Format.length == '\0') {
            int* arg_int = va_arg(arg, int*);
            *arg_int = (int)result;
          }
          if (Format.length == 'w') {
            unsigned char* arg_int = (unsigned char*)va_arg(arg, int*);
            *arg_int = (unsigned char)result;
          }
          if (Format.length == 'h') {
            short int* arg_int = (short int*)va_arg(arg, int*);
            *arg_int = (short int)result;
          }
          if (Format.length == 'l') {
            long int* arg_int = va_arg(arg, long int*);
            *arg_int = (long int)result;
          }
          if (Format.length == 'W') {
            long long int* arg_int = va_arg(arg, long long int*);
            *arg_int = result;
          }
        }
      }
      //  ------------------------//-f-e-E-g-G//  -------------------------
      if (Format.specifier == 'f' || Format.specifier == 'e' ||
          Format.specifier == 'E' || Format.specifier == 'g' ||
          Format.specifier == 'G') {
        long double result;
        str = str_to_float(str, Format, &result);
        if (Format.star == 0) {
          if (Format.length == '\0') {
            float* arg_float = va_arg(arg, float*);
            *arg_float = (float)result;
          }
          if (Format.length == 'l') {
            double* arg_float = va_arg(arg, double*);
            *arg_float = (double)result;
          }
          if (Format.length == 'L') {
            long double* arg_float = va_arg(arg, long double*);
            *arg_float = result;
          }
        }
      }
      //  ---------------------------//-o-x-X-u-p-// ---------------------------
      if (Format.specifier == 'o' || Format.specifier == 'x' ||
          Format.specifier == 'X' || Format.specifier == 'p' ||
          Format.specifier == 'u') {
        unsigned long long int result;
        if (Format.specifier == 'o') str = str_to_o(str, Format, &result);
        if (Format.specifier == 'x' || Format.specifier == 'X' ||
            Format.specifier == 'p')
          str = str_to_x(str, Format, &result);
        if (Format.specifier == 'u') str = str_to_u(str, Format, &result);
        if (Format.specifier == 'p') Format.length = 'W';
        if (Format.star == 0) {
          if (Format.length == '\0') {
            unsigned int* arg_int = va_arg(arg, unsigned int*);
            *arg_int = (unsigned int)result;
          }
          if (Format.length == 'w') {
            unsigned char* arg_int = (unsigned char*)va_arg(arg, unsigned int*);
            *arg_int = (unsigned char)result;
          }
          if (Format.length == 'h') {
            unsigned short int* arg_int =
                (unsigned short int*)va_arg(arg, unsigned int*);
            *arg_int = (unsigned short int)result;
          }
          if (Format.length == 'l') {
            unsigned long int* arg_int = va_arg(arg, unsigned long int*);
            *arg_int = (unsigned long int)result;
          }
          if (Format.length == 'W') {
            unsigned long long int* arg_int =
                va_arg(arg, unsigned long long int*);
            *arg_int = result;
          }
        }
      }
      //  -----------------------------//-n-//  -------------------------------
      if (Format.specifier == 'n') {
        if (s21_strlen(ptr_str) > s21_strlen(str) &&
            !separator_character(
                *(format - 3))) {  //  смотрим есть ли пробел перед %n
          while (*(str - 1) == ' ') str--;  //  %n не учитывает пробелы до %n
        }
        if (Format.star == 0) {
          int* arg_n = va_arg(arg, int*);
          *arg_n = s21_strlen(ptr_str) - s21_strlen(str);
          ;
        }
        sscanf_result--;
      }
      //  -----------------------------//-%-//  -------------------------------
      if (Format.specifier == '%') {
        if (*str == '%') str++;
        sscanf_result--;
      }
      if (Format.star == 0) sscanf_result++;
    } else {
      //  -----//-n-//  -----// %n не отрабатывает в предыдущем условии
      if (Format.specifier == 'n') {
        if (Format.star == 0) {
          int* arg_n = va_arg(arg, int*);
          *arg_n = s21_strlen(ptr_str);
          ;
        }
      }
      while (*format) format++;
    }
  }
  va_end(arg);
  return sscanf_result;
}

const char* sscanf_search_specifier(const char* str, const char* format) {
  int flag_equality = 1;  //  флаг равенства символов строк str и format
  for (; *format && *format != '%' && flag_equality == 1; format++) {
    if (separator_character(*format)) {
      while (separator_character(*format)) format++;
      while (separator_character(*str)) str++;
    }
    if (*format != '%' && *format == *str)
      str++;
    else if (*format != '%')
      flag_equality = -1;
    else
      format--;  //  *format == '%' - делаем шаг назад, чтобы выйти из цикла
    if (flag_equality == -1)
      while (*str) str++;
  }
  return str;
}
int separator_character(char symbol) {
  int result = 0;
  if (symbol == ' ' || symbol == '\t' || symbol == '\v' || symbol == '\n' ||
      symbol == '\f')
    result = 1;
  return result;
}
const char* current_format(const char* format) {
  for (; *format && *format != '%'; format++) {
  }
  if (*format) format++;
  return format;
}
const char* sscanf_parse_format(const char* format,
                                struct_sscanf_format* Format) {
  format = sscanf_get_star(format, &Format->star);
  format = sscanf_get_width(format, &Format->width);
  format = sscanf_get_length(format, &Format->length);
  format = sscanf_get_specifier(format, &Format->specifier);
  return format;
}
const char* sscanf_get_star(const char* format, char* star) {
  *star = 0;
  if (*format == '*') {
    *star = 1;
    format++;
  }
  return format;
}
const char* sscanf_get_width(const char* format, int* width) {
  *width = 0;
  while (*format == '0') format++;
  if (*format > '0' && *format <= '9') *width = s21_atoi(format);
  if (*width != 0) {
    for (int i = get_class_number(*width); i > 0; i--, format++) {
    }
  }
  return format;
}
const char* sscanf_get_length(const char* format, char* length) {
  *length = '\0';
  if (*format == 'h' || *format == 'l' || *format == 'L') *length = *format++;
  if (*format == 'l') {
    *length = 'W';
    format++;
  } else if (*format == 'h') {
    *length = 'w';
    format++;
  }
  return format;
}
const char* sscanf_get_specifier(const char* format, char* specifier) {
  *specifier = '\0';
  if (*format == 'c' || *format == 'd' || *format == 'i' || *format == 'e' ||
      *format == 'E' || *format == 'f' || *format == 'g' || *format == 'G' ||
      *format == 'o' || *format == 's' || *format == 'u' || *format == 'x' ||
      *format == 'X' || *format == 'p' || *format == 'n' || *format == '%')
    *specifier = *format++;
  return format;
}

const char* str_to_d(const char* str, struct_sscanf_format Format,
                     long long int* result) {
  *result = 0;
  int flag_minus;
  str = chech_sign(str, &flag_minus);
  if (flag_minus) --Format.width;
  int flag_width = 1;
  while (*str >= '0' && *str <= '9' && flag_width) {
    *result += (int)*str - 48;
    str++;
    if (--Format.width == 0) flag_width = 0;
    if (*str >= '0' && *str <= '9' && flag_width) *result *= 10;
  }
  if (flag_minus) *result *= flag_minus;
  return str;
}
void str_to_i(const char* str, struct_sscanf_format* Format) {
  if (*str == '-' || *str == '+') str++;
  const char* ptr_str = str;
  int flag_x = 0;
  while (*ptr_str == '0') {
    ptr_str++;
    flag_x++;
  }
  if ((*ptr_str == 'x' || *ptr_str == 'X') && flag_x)
    Format->specifier = *ptr_str;
  else if (*str == '0')
    Format->specifier = 'o';
  else
    Format->specifier = 'd';
}

const char* str_to_u(const char* str, struct_sscanf_format Format,
                     unsigned long long int* result) {
  *result = 0;
  int flag_minus;
  str = chech_sign(str, &flag_minus);
  if (flag_minus) --Format.width;
  int flag_width = 1;
  while (*str >= '0' && *str <= '9' && flag_width) {
    *result += (int)*str - 48;
    str++;
    if (--Format.width == 0) flag_width = 0;
    if (*str >= '0' && *str <= '9' && flag_width) *result *= 10;
  }
  if (flag_minus) *result *= flag_minus;
  return str;
}
//  исправить
const char* str_to_float(const char* str, struct_sscanf_format Format,
                         long double* result) {
  *result = 0.0;
  int flag_minus;
  str = chech_sign(str, &flag_minus);
  if (flag_minus) --Format.width;
  int flag_width = 1;
  int flag_point = 1;
  int flag_inf = 1;
  while (((*str >= '0' && *str <= '9') || *str == '.') && flag_width &&
         flag_point == 1) {
    flag_inf = 0;
    if (*str == '.') {
      flag_point = 0;
      str++;
      if (--Format.width == 0) flag_width = 0;
    } else {
      *result += (int)*str - 48;
      str++;
      if (--Format.width == 0) flag_width = 0;
      if (*str >= '0' && *str <= '9' && flag_width) *result *= 10;
    }
  }
  int count_volue = 1;
  while (*str >= '0' && *str <= '9' && flag_width && flag_point == 0) {
    *result += ((int)*str - 48) / pow(10, count_volue);
    count_volue++;
    str++;
    if (--Format.width == 0) flag_width = 0;
  }
  if ((Format.specifier == 'e' || Format.specifier == 'E' ||
       Format.specifier == 'g' || Format.specifier == 'G') &&
      (*str == 'e' || *str == 'E')) {
    str++;
    int flag_rank = 0;  //  смотрим знак при степени: если '-', то flag_rank =
                        //  -1; если '+' flag_rank = 1
    if (*str == '-') {
      flag_rank = -1;
      str++;
    } else if (*str == '+') {
      flag_rank = 1;
      str++;
    }
    if (*str >= '0' && *str <= '9') {
      long long int rank = 0;
      str = str_to_d(str, Format, &rank);
      for (int i = 0; i < rank; i++) {
        if (flag_rank == 1)
          *result *= 10;
        else if (flag_rank == -1)
          *result /= 10;
      }
    } else {
      str--;
      if (flag_rank) str--;
    }
  }
  if (flag_minus) *result *= flag_minus;

  if (flag_inf)
    str = check_inf_nan(str, result, flag_minus);  //  проверка на nan и inf
  return str;
}

const char* str_to_o(const char* str, struct_sscanf_format Format,
                     unsigned long long int* result) {
  *result = 0;
  int flag_minus;  //  обработка отрицательных чисел
  str = chech_sign(str, &flag_minus);
  if (flag_minus) --Format.width;
  int flag_width = 1;
  while (*str >= '0' && *str <= '7' && flag_width) {
    *result += (int)*str - 48;
    str++;
    if (--Format.width == 0) flag_width = 0;
    if (*str >= '0' && *str <= '7' && flag_width) *result *= 8;
  }
  if (flag_minus) *result *= flag_minus;
  return str;
}
const char* chech_sign(const char* str, int* flag_minus) {
  *flag_minus = 0;
  if (*str == '-') {
    *flag_minus = -1;
    str++;
  } else if (*str == '+') {
    *flag_minus = 1;
    str++;
  }
  return str;
}
const char* str_to_x(const char* str, struct_sscanf_format Format,
                     unsigned long long int* result) {
  if (Format.width == 0) Format.width = -1;  //  если ширина не задана
  *result = 0;
  int flag_minus;  //  обработка отрицательных чисел
  str = chech_sign(str, &flag_minus);
  if (flag_minus) Format.width--;
  while (*str == '0' && Format.width) {
    str++;
    Format.width--;
  }
  if ((*str == 'x' || *str == 'X') && Format.width) {
    str++;
    Format.width--;
    if (Format.width == 0) str--;
  }
  int flag_width = 1;
  if (Format.width == 0) flag_width = 0;
  while (((*str >= '0' && *str <= '9') || (*str >= 'A' && *str <= 'F') ||
          (*str >= 'a' && *str <= 'f')) &&
         flag_width) {
    if (*str >= '0' && *str <= '9') *result += (int)*str - 48;
    if (*str >= 'A' && *str <= 'F') *result += (int)*str - 55;
    if (*str >= 'a' && *str <= 'f') *result += (int)*str - 87;
    str++;
    if (--Format.width == 0) flag_width = 0;
    if (((*str >= '0' && *str <= '9') || (*str >= 'A' && *str <= 'F') ||
         (*str >= 'a' && *str <= 'f')) &&
        flag_width)
      *result *= 16;
  }
  if (flag_minus) *result *= flag_minus;
  return str;
}
const char* str_to_s(const char* str, struct_sscanf_format Format,
                     char* arg_str) {
  int flag_width = 1;
  while (!separator_character(*str) && flag_width && *str) {
    *arg_str++ = *str++;
    if (--Format.width == 0) flag_width = 0;
  }
  *arg_str = '\0';
  return str;
}
const char* wstr_to_ws(const char* str, struct_sscanf_format Format,
                       wchar_t* arg_str) {
  int flag_width = 1;
  int count_symbol = 0;  //  количество символов для преобразования
  while (!separator_character(*str) && flag_width && str[count_symbol]) {
    count_symbol++;
    if (--Format.width == 0) flag_width = 0;
  }
  mbstowcs(arg_str, str, count_symbol);
  str += count_symbol;
  return str;
}
const char* check_inf_nan(const char* str, long double* result,
                          int flag_minus) {
  if ((*str == 'i' || *str == 'I') &&
      (*(str + 1) == 'n' || *(str + 1) == 'N') &&
      (*(str + 2) == 'f' || *(str + 2) == 'F')) {
    *result = INFINITY;
    if (flag_minus == -1) *result = -INFINITY;
    str += 3;
  }

  if ((*str == 'n' || *str == 'N') &&
      (*(str + 1) == 'a' || *(str + 1) == 'A') &&
      (*(str + 2) == 'n' || *(str + 2) == 'N')) {
    *result = NAN;
    str += 3;
  }

  return str;
}

int error(const char* str, struct_sscanf_format Format) {
  int result = 0;
  if (!*str) result = 1;  //  ?
  switch (Format.specifier) {
    case 'i':
    case 'd':
    case 'u': {
      if (*str == '-' || *str == '+') {
        str++;
        if (Format.width == 1) result = 1;
      }
      if (!(*str >= '0' && *str <= '9')) {
        result = 1;
      }  //  проверяем что в строке число
      break;
    }
    case 'o': {
      if (*str == '-' || *str == '+') str++;
      if (!(*str >= '0' && *str <= '7')) {
        result = 1;
      }  //  проверяем что в строке число
      break;
    }
    case 'x':
    case 'X': {
      if (*str == '-' || *str == '+') {
        str++;
        if (Format.width == 1) result = 1;
      }
      if (!(*str >= '0' && *str <= '9') && !(*str >= 'a' && *str <= 'f') &&
          !(*str >= 'A' && *str <= 'F'))
        result = 1;
      break;
    }
    case 'f':
    case 'e':
    case 'E':
    case 'g':
    case 'G': {
      if (*str == '-' || *str == '+') {
        str++;
        if (Format.width-- == 1) result = 1;
      }
      if (*str == '.') {
        str++;
        if (Format.width == 1) result = 1;
      }
      if (!(*str >= '0' && *str <= '9')) {
        result = 1;
      }  //  проверяем что в строке число

      long double res = 0.;
      check_inf_nan(str, &res, 0);
      if (res != 0.) result = 0;
      break;
    }
    default:
      break;
  }
  return result;
}
