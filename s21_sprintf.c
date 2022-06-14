#include <locale.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include "s21_string.h"

//  Очищает строку str
void clean_str(char *str) { s21_memset(str, 0, s21_strlen(str)); }

//  "%[флаги][ширина][.точность][длина]спецификатор"
int s21_sprintf(char *str, const char *format, ...) {
  clean_str(str);
  int result = 0;
  __attribute__((unused)) char *ptr_str = str;
  __attribute__((unused)) char *ptr_format = (char *)format;
  int flag_count_c = 0;
  int flag_c_null = 0;

  va_list arg;
  va_start(arg, format);
#ifdef __linux__
  s21_size_t formatlen = s21_strlen(format);
#endif
  while (*format) {
    str = end_str(str);
    format = search_specifier(str, format);
    result += s21_strlen(str);
#ifdef __linux__
    if (*format == '\0' && formatlen >= 1) {
      format--;
      if (*format != '%') format++;
    }
#endif
    if (*format) {
      struct_flags flags = {0, 0, 0, 0, 0};
      struct_sprintf_format Format;
      Format.flags = &flags;
      format = parse_format(format, &Format);
      if (Format.width == -1) Format.width = va_arg(arg, int);
      if (Format.width < 0) Format.width = 0;
      if (Format.accuracy == -1) Format.accuracy = va_arg(arg, int);
      if (Format.accuracy < 0) Format.accuracy = -2;
      char output[LEN] = {0};

      //   -----------------------------//-c-//------------------------------//
      if (Format.specifier == 'c') {
        if (Format.length == 'h' || Format.length == 'w' ||
            Format.length == 'W' || Format.length == 'L')
          Format.length = '\0';

        if (Format.length == '\0') {
          char arg_char = va_arg(arg, int);
          if (arg_char == (char)0) {
            result++;
            flag_count_c++;
            if (flag_count_c == 1) flag_c_null = s21_strlen(ptr_str);
          }
          c_to_str(output, arg_char);
        }
        if (Format.length == 'l') {
          wchar_t arg_char = va_arg(arg, int);
          if (arg_char == (wchar_t)0) {
            result++;
            flag_count_c++;
            if (flag_count_c == 1) flag_c_null = s21_strlen(ptr_str);
          }
          wc_to_str(output, arg_char);
        }
        correct_flags(&Format);
      }
      //    -----------------------------//-d-i-//----------------------------//
      if (Format.specifier == 'd' || Format.specifier == 'i') {
#ifdef __linux__
        if (Format.length == 'L') Format.length = 'W';
#elif __APPLE__
        if (Format.length == 'L') Format.length = '\0';
#endif
        if (Format.length == '\0') {
          int arg_int = va_arg(arg, int);
          d_to_str(output, arg_int, sizeof(arg_int), Format.length);
        }
        if (Format.length == 'w') {
          unsigned char arg_int = (unsigned char)va_arg(arg, int);
          d_to_str(output, arg_int, sizeof(arg_int), Format.length);
        }
        if (Format.length == 'h') {
          short int arg_int = (short int)va_arg(arg, int);
          d_to_str(output, arg_int, sizeof(arg_int), Format.length);
        }
        if (Format.length == 'l') {
          long int arg_int = va_arg(arg, long int);
          d_to_str(output, arg_int, sizeof(arg_int), Format.length);
        }
        if (Format.length == 'W') {
          long long int arg_int = va_arg(arg, long long int);
          d_to_str(output, arg_int, sizeof(arg_int), Format.length);
        }
        correct_flags(&Format);
        correct_accuracy_for_int(output, Format.accuracy);
      }
      //    -----------------------------//-e-E-//-----------------------------//
      if (Format.specifier == 'e' || Format.specifier == 'E') {
        if (Format.accuracy < 0) Format.accuracy = 6;
#ifdef __linux__
        if (Format.length == 'W') Format.length = 'L';
#endif
        if (Format.length == 'h' || Format.length == 'w' ||
            Format.length == 'W')
          Format.length = '\0';

        if (Format.length == '\0' || Format.length == 'l') {
          double arg_exp = va_arg(arg, double);
          if (Format.specifier == 'e')
            e_to_str(output, arg_exp, sizeof(arg_exp), Format.length);
          if (Format.specifier == 'E')
            E_to_str(output, arg_exp, sizeof(arg_exp), Format.length);
        }
        if (Format.length == 'L') {
          long double arg_exp = va_arg(arg, long double);
          if (Format.specifier == 'e')
            e_to_str(output, arg_exp, sizeof(arg_exp), Format.length);
          if (Format.specifier == 'E')
            E_to_str(output, arg_exp, sizeof(arg_exp), Format.length);
        }
        correct_flags(&Format);
        if (!s21_strcmp(output, "nan") || !s21_strcmp(output, "inf") ||
            !s21_strcmp(output, "-inf")) {
          Format.flags->fzero = 0;
          Format.flags->fgrid = 0;
        } else {
          correct_accuracy_for_float(output, Format.accuracy);
        }
      }
      //    -----------------------------//-f-//-------------------------------//
      if (Format.specifier == 'f') {
        if (Format.accuracy < 0) Format.accuracy = 6;
#ifdef __linux__
        if (Format.length == 'W') Format.length = 'L';
#endif
        if (Format.length == 'h' || Format.length == 'w' ||
            Format.length == 'W')
          Format.length = '\0';

        if (Format.length == '\0' || Format.length == 'l') {
          double arg_float = va_arg(arg, double);
          f_to_str(output, arg_float, sizeof(arg_float), Format.length);
        }
        if (Format.length == 'L') {
          long double arg_float = va_arg(arg, long double);
          f_to_str(output, arg_float, sizeof(arg_float), Format.length);
        }
        correct_flags(&Format);
        if (!s21_strcmp(output, "nan") || !s21_strcmp(output, "inf") ||
            !s21_strcmp(output, "-inf")) {
          Format.flags->fzero = 0;
          Format.flags->fgrid = 0;
        } else {
          correct_accuracy_for_float(output, Format.accuracy);
        }
      }
      //   -----------------------------//-g-G-//-----------------------------//
      if (Format.specifier == 'g' || Format.specifier == 'G') {
        if (Format.accuracy < 0) Format.accuracy = 6;
        if (Format.accuracy == 0) Format.accuracy = 1;
#ifdef __linux__
        if (Format.length == 'W') Format.length = 'L';
#endif
        if (Format.length == 'h' || Format.length == 'w' ||
            Format.length == 'W')
          Format.length = '\0';

        if (Format.length == '\0' || Format.length == 'l') {
          double arg_g = va_arg(arg, double);
          if (Format.specifier == 'g')
            g_to_str(output, arg_g, sizeof(arg_g), Format.length,
                     &Format.accuracy);
          if (Format.specifier == 'G')
            G_to_str(output, arg_g, sizeof(arg_g), Format.length,
                     &Format.accuracy);
        }
        if (Format.length == 'L') {
          long double arg_g = va_arg(arg, long double);
          if (Format.specifier == 'g')
            g_to_str(output, arg_g, sizeof(arg_g), Format.length,
                     &Format.accuracy);
          if (Format.specifier == 'G')
            G_to_str(output, arg_g, sizeof(arg_g), Format.length,
                     &Format.accuracy);
        }
        correct_flags(&Format);
        if (!s21_strcmp(output, "nan") || !s21_strcmp(output, "inf") ||
            !s21_strcmp(output, "-inf")) {
          Format.flags->fzero = 0;
          Format.flags->fgrid = 0;
        } else {
          correct_accuracy_for_float(output, Format.accuracy);
          correct_g(output);
        }
      }
      //   -----------------------------//-o-//-----------------------------//
      if (Format.specifier == 'o') {
#ifdef __linux__
        if (Format.length == 'L') Format.length = 'W';
#elif __APPLE__
        if (Format.length == 'L') Format.length = '\0';
#endif

        if (Format.length == '\0') {
          unsigned int arg_o = va_arg(arg, unsigned int);
          o_to_str(output, arg_o, sizeof(arg_o), Format.length);
        }
        if (Format.length == 'w') {
          unsigned char arg_o = (unsigned char)va_arg(arg, int);
          o_to_str(output, arg_o, sizeof(arg_o), Format.length);
        }
        if (Format.length == 'h') {
          unsigned short int arg_o = (unsigned short int)va_arg(arg, int);
          o_to_str(output, arg_o, sizeof(arg_o), Format.length);
        }
        if (Format.length == 'l') {
          unsigned long arg_o = va_arg(arg, unsigned long);
          o_to_str(output, arg_o, sizeof(arg_o), Format.length);
        }
        if (Format.length == 'W') {
          unsigned long long arg_o = va_arg(arg, unsigned long long);
          o_to_str(output, arg_o, sizeof(arg_o), Format.length);
        }
        correct_flags(&Format);
        correct_accuracy_for_int(output, Format.accuracy);
      }
      //  -----------------------------//-s-//-------------------------------//
      if (Format.specifier == 's') {
#ifdef __linux__
        if (Format.length == 'W' || Format.length == 'L') Format.length = 'l';
#endif
        if (Format.length == 'h' || Format.length == 'w' ||
            Format.length == 'W' || Format.length == 'L')
          Format.length = '\0';

        if (Format.length == '\0') {
          char *arg_str = va_arg(arg, char *);
          str_to_str(output, arg_str);
#ifdef __linux__
          if (s21_strcmp(output, "(null)") == 0 && Format.accuracy < 6 &&
              Format.accuracy > 0)
            s21_strcpy(output, "");
#endif
        }
        if (Format.length == 'l') {
          wchar_t *arg_str = va_arg(arg, int *);
          wcs_to_str(output, arg_str);
#ifdef __linux__
          if (s21_strcmp(output, "(null)") == 0 && Format.accuracy < 6 &&
              Format.accuracy > 0)
            s21_strcpy(output, "");
#endif
        }
        correct_flags(&Format);
        correct_accuracy_for_str(output, Format.accuracy);
      }
      //  -----------------------------//-u-//-------------------------------//
      if (Format.specifier == 'u') {
#ifdef __linux__
        if (Format.length == 'L') Format.length = 'W';
#elif __APPLE__
        if (Format.length == 'L') Format.length = '\0';
#endif

        if (Format.length == '\0') {
          unsigned int arg_u = va_arg(arg, unsigned int);
          u_to_str(output, arg_u, sizeof(arg_u), Format.length);
        }
        if (Format.length == 'w') {
          unsigned char arg_u = (unsigned char)va_arg(arg, int);
          u_to_str(output, arg_u, sizeof(arg_u), Format.length);
        }
        if (Format.length == 'h') {
          unsigned short int arg_u = (unsigned short int)va_arg(arg, int);
          u_to_str(output, arg_u, sizeof(arg_u), Format.length);
        }
        if (Format.length == 'l') {
          unsigned long arg_u = va_arg(arg, unsigned long);
          u_to_str(output, arg_u, sizeof(arg_u), Format.length);
        }
        if (Format.length == 'W') {
          unsigned long long arg_u = va_arg(arg, unsigned long long);
          u_to_str(output, arg_u, sizeof(arg_u), Format.length);
        }
        correct_flags(&Format);
        correct_accuracy_for_int(output, Format.accuracy);
      }
      //  -----------------------------//-x-X-//----------------------------//
      if (Format.specifier == 'x' || Format.specifier == 'X') {
#ifdef __linux__
        if (Format.length == 'L') Format.length = 'W';
#elif __APPLE__
        if (Format.length == 'L') Format.length = '\0';
#endif

        if (Format.length == '\0') {
          unsigned int arg_x = va_arg(arg, unsigned int);
          if (Format.specifier == 'x')
            x_to_str(output, arg_x, sizeof(arg_x), Format.length);
          if (Format.specifier == 'X')
            X_to_str(output, arg_x, sizeof(arg_x), Format.length);
        }
        if (Format.length == 'w') {
          unsigned char arg_x = (unsigned char)va_arg(arg, int);
          if (Format.specifier == 'x')
            x_to_str(output, arg_x, sizeof(arg_x), Format.length);
          if (Format.specifier == 'X')
            X_to_str(output, arg_x, sizeof(arg_x), Format.length);
        }
        if (Format.length == 'h') {
          unsigned short int arg_x = (unsigned short int)va_arg(arg, int);
          if (Format.specifier == 'x')
            x_to_str(output, arg_x, sizeof(arg_x), Format.length);
          if (Format.specifier == 'X')
            X_to_str(output, arg_x, sizeof(arg_x), Format.length);
        }
        if (Format.length == 'l') {
          unsigned long arg_x = va_arg(arg, unsigned long);
          if (Format.specifier == 'x')
            x_to_str(output, arg_x, sizeof(arg_x), Format.length);
          if (Format.specifier == 'X')
            X_to_str(output, arg_x, sizeof(arg_x), Format.length);
        }
        if (Format.length == 'W') {
          unsigned long long arg_x = va_arg(arg, unsigned long long);
          if (Format.specifier == 'x')
            x_to_str(output, arg_x, sizeof(arg_x), Format.length);
          if (Format.specifier == 'X')
            X_to_str(output, arg_x, sizeof(arg_x), Format.length);
        }
        correct_flags(&Format);
        correct_accuracy_for_int(output, Format.accuracy);
      }
      //  -----------------------------//-p-//-------------------------------//
      if (Format.specifier == 'p') {
        if (Format.length == 'h' || Format.length == 'w' ||
            Format.length == 'W' || Format.length == 'L' ||
            Format.length == 'l')
          Format.length = '\0';
        unsigned long long arg_p = va_arg(arg, unsigned long long);
        p_to_str(output, arg_p);
        correct_flags(&Format);
        correct_accuracy_for_int(output, Format.accuracy);
      }
      //  -----------------------------//-n-//-------------------------------//
      if (Format.specifier == 'n') {
        int *arg_n = va_arg(arg, int *);
        int count_symbols = s21_strlen(ptr_str);
        *arg_n = count_symbols;
        correct_flags(&Format);
      }
      //-----------------------------//-%-//-------------------------------//
      if (Format.specifier == '%' || Format.specifier == '\0') {
        output[0] = '%';
        output[1] = '\0';
#ifdef __APPLE__
        if (Format.specifier == '\0') {
          int i = 0;
          for (; format[i] && format[i] != '%'; i++) {
          }
          if (!format[i]) {
            output[0] = '\0';
          } else {
            for (; *format && *format != '%'; format++) {
            }
            if (*format) format++;
          }
        }
#elif __linux__
        if (Format.specifier == '\0' && Format.flags->fspace) {
          output[1] = ' ';
          output[2] = '\0';
        }
#endif
        correct_flags(&Format);
      }

      if (Format.flags->fgrid)
        flag_grid_str(output, Format.specifier, Format.accuracy);
      if (Format.flags->fplus) flag_plus_str(output);
      if (Format.flags->fspace) flag_space_str(output);
      set_width_str(output, Format.width, Format.specifier);
      if (Format.flags->fminus) flag_minus_str(output);
      if (Format.flags->fzero) flag_zero_str(output);
      if (Format.flags->fspace) flag_space_str(output);

      if (flag_count_c == 1) flag_c_null += (int)s21_strlen(output);
      result += s21_strlen(output);
      s21_strcat(str, output);
    }
  }
  va_end(arg);
  if (flag_count_c) ptr_str[flag_c_null] = 0;
  return result;
}

const char *search_specifier(char *str, const char *format) {
  for (; *format && *format != '%'; str++, format++) {
    *str = *format;
  }
  *str = '\0';
  if (*format) format++;
  return format;
}

const char *parse_format(const char *format, struct_sprintf_format *Format) {
  format = get_flags((char *)format, Format->flags);
  Format->width = get_width(format);
  if (Format->width != 0) {
    for (int i = get_class_number(Format->width); i > 0; i--, format++) {
    }
  }
  Format->accuracy = get_accuracy(format);
  if (*format == '.') {
    for (int i = get_class_number(Format->accuracy) + 1; i > 0; i--, format++) {
    }
    if (Format->accuracy == -2) Format->accuracy = 0;
  }
  Format->length = get_length(format);
  if (Format->length) format++;
  if (Format->length == 'w' || Format->length == 'W') format++;
#ifdef __APPLE__
  int step = 0;
  while (*format == 'h' || *format == 'l' || *format == 'L') {
    format++;
    step++;
  }
#endif
  Format->specifier = get_specifier(*format);
  if (Format->specifier) format++;
#ifdef __APPLE__
  if (Format->specifier == 's') {
    if (Format->length == 'W' && step % 2 == 0)
      Format->length = '\0';
    else if (Format->length == 'W' && step % 2 != 0)
      Format->length = 'l';
  }
#endif
  return format;
}

char *get_flags(char *format, struct_flags *flags) {
  while (*format == '-' || *format == '+' || *format == ' ' || *format == '#' ||
         *format == '0') {
    if (*format == '-')
      flags->fminus = 1;
    else if (*format == '+')
      flags->fplus = 1;
    else if (*format == ' ')
      flags->fspace = 1;
    else if (*format == '#')
      flags->fgrid = 1;
    else if (*format == '0')
      flags->fzero = 1;
    format++;
  }
  return format;
}

int get_width(const char *format) {
  int result = 0;
  if (*format == '*')
    result = -1;
  else if (*format >= '0' && *format <= '9')
    result = s21_atoi(format);
  return result;
}

int get_accuracy(const char *format) {
  int result = -2;
  if (*format == '.') {
    format++;
    if (*format == '*')
      result = -1;
    else if (*format >= '0' && *format <= '9')
      result = s21_atoi(format);
  }
  return result;
}

char get_length(const char *format) {
  char result = '\0';
  if (*format == 'h' || *format == 'l' || *format == 'L') result = *format;
  if (*format == 'l' && *(format + 1) == 'l')
    result = 'W';
  else if (*format == 'h' && *(format + 1) == 'h')
    result = 'w';
  return result;
}

char get_specifier(char symbol) {
  char result = '\0';
  if (symbol == 'c' || symbol == 'd' || symbol == 'i' || symbol == 'e' ||
      symbol == 'E' || symbol == 'f' || symbol == 'g' || symbol == 'G' ||
      symbol == 'o' || symbol == 's' || symbol == 'u' || symbol == 'x' ||
      symbol == 'X' || symbol == 'p' || symbol == 'n' || symbol == '%')
    result = symbol;
  return result;
}

int s21_atoi(const char *format) {
  int result = 0;
  for (; *format >= '0' && *format <= '9';) {
    result += (int)*format - 48;
    format++;
    if (*format >= '0' && *format <= '9') result *= 10;
  }
  return result;
}

int get_class_number(int number) {
  int result = 1;
  if (number == -2) result = 0;
  for (; number > 9; number /= 10, result++) {
  }
  return result;
}

char *end_str(char *str) {
  str = &str[s21_strlen(str)];
  return str;
}

void c_to_str(char *output, char symbol) {
  *output++ = symbol;
  *output = '\0';
}

void correct_accuracy_for_int(char *output, int accuracy) {
  if (accuracy == -2) accuracy = 1;
  int flag_minus = 0;
  if (*output == '-') flag_minus = 1;
  if (output[flag_minus] == '0' && accuracy == 0) {
    *output = '\0';
  } else {
    int len_output = s21_strlen(output);
    if (*output == '-') len_output--;
    int count_zero = accuracy - len_output;
    if (count_zero > 0) {
      char *str_zero = (char *)malloc((count_zero + 1) * sizeof(char));
      if (str_zero) {
        for (int i = 0; i < count_zero; i++) str_zero[i] = '0';
        str_zero[count_zero] = '\0';
        char *new_str = s21_insert(output, str_zero, flag_minus);
        if (new_str) {
          s21_strcpy(output, new_str);
          free(new_str);
        }
        free(str_zero);
      }
    }
  }
}

void correct_accuracy_for_float(char *output, int accuracy) {
  if (accuracy == -2) accuracy = 6;
  __attribute__((unused)) char *ptr_output = output;
  if (*output == '-') output++;
  int pos_point, len_remains, pos_e, len_e;
  init_pos(output, &pos_point, &len_remains, &pos_e, &len_e);
  if (accuracy >= len_remains) {
    if (pos_e) {
      for (int i = pos_point + accuracy + len_e, j = len_e - 1; j >= 0;
           i--, j--)
        output[i] = output[pos_e + j];
    }
    for (int i = pos_point + accuracy; i > pos_point + len_remains; i--)
      output[i] = '0';
    output[pos_point + accuracy + len_e + 1] = '\0';
  } else {
    int flag_accuracy = 0;
    if (accuracy) flag_accuracy = 1;
    s21_round(output, accuracy, pos_point);
    if (pos_e) {
      for (int i = pos_point + accuracy + flag_accuracy, j = 0; j < len_e;
           i++, j++)
        output[i] = output[pos_e + j];
    }
    output[pos_point + accuracy + len_e + flag_accuracy] = '\0';
    correct_round(output, pos_point + accuracy + flag_accuracy - 1);
    if (pos_e && output[1] == '0')
      correct_exp(output, pos_point + accuracy + flag_accuracy, len_e);
  }
  if (!output[pos_point + 1]) output[pos_point] = '\0';
}
void correct_g(char *output) {
  for (; *output && *output != '.'; output++) {
  }
  if (*output) output++;
  int pos_e = 0, flag = 0;
  for (int i = 0; output[i] && pos_e == 0; i++) {
    if (output[i] == 'E' || output[i] == 'e') pos_e = i;
    if (pos_e == 0) flag++;
    if (output[i] != '0' && pos_e == 0) flag = 0;
  }
  if (flag && pos_e) {
    int len_remains = s21_strlen(output) - s21_strlen(&output[pos_e]);
    if (flag == len_remains) flag++;
    for (int i = 0; output[pos_e + i - 1]; i++)
      output[pos_e - flag + i] = output[pos_e + i];
  } else if (flag) {
    int len_remains = s21_strlen(output);
    if (flag == len_remains) flag++;
    output[len_remains - flag] = '\0';
  }
}

void correct_accuracy_for_str(char *output, int accuracy) {
  if (accuracy >= 0) output[accuracy] = '\0';
}

void init_pos(char *output, int *pos_point, int *len_remains, int *pos_e,
              int *len_e) {
  *pos_point = 0;
  *len_remains = 0;
  *pos_e = 0;
  *len_e = 0;
  int len_output = s21_strlen(output);
  for (int i = 0; output[i] && *pos_point == 0; i++) {
    if (output[i] == '.') *pos_point = i;
  }
  for (int i = *pos_point; output[i] && *pos_e == 0; i++) {
    if (output[i] == 'e' || output[i] == 'E') *pos_e = i;
  }
  if (*pos_e) *len_e = len_output - *pos_e;
  if (*pos_point && *pos_e)
    *len_remains = *pos_e - *pos_point - 1;
  else if (*pos_point)
    *len_remains = len_output - *pos_point - 1;
}
void s21_round(char *output, int accuracy, int pos_point) {
  int flag_accuracy = 1;
  if (accuracy) flag_accuracy = 0;

  if (output[pos_point + accuracy + 1] > '5') {
    output[pos_point + accuracy - flag_accuracy]++;
  } else if (output[pos_point + accuracy + 1] == '5') {
    int flag_round = 0;
    for (int i = pos_point + accuracy + 2; output[i] && !flag_round; i++) {
      if (output[i] != '0') flag_round = 1;
    }
    if (flag_round ||
        (!flag_round && output[pos_point + accuracy - flag_accuracy] % 2 != 0))
      output[pos_point + accuracy - flag_accuracy]++;
  }
}

void correct_round(char *output, int index) {
  while (output[index] > '9' && index > 0) {
    output[index] = '0';
    index--;
    if (output[index] == '.') index--;
    output[index]++;
  }
  if (output[0] > '9') {
    index = s21_strlen(output) + 1;
    for (; index > 0; index--) {
      output[index] = output[index - 1];
    }
    output[0] = '1';
    output[1] = '0';
  }
}
void correct_exp(char *output, int pos_e, int len_e) {
  for (int i = 1; i < pos_e + len_e; i++) output[i] = output[i + 1];
  if (output[pos_e + 1] == '+') {
    output[pos_e + len_e - 1]++;
    int step = 0;
    while (output[pos_e + len_e - 1 - step] > '9' && step < len_e - 3) {
      output[pos_e + len_e - 1 - step] = '0';
      step++;
      output[pos_e + len_e - 1 - step]++;
    }
    if (output[pos_e + 2] > '9') {
      output[pos_e + 2] = '1';
      output[pos_e + len_e] = '0';
      len_e++;
    }
  } else if (output[pos_e + 1] == '-') {
    output[pos_e + len_e - 1]--;
    int step = 0;
    while (output[pos_e + len_e - 1 - step] < '0' && step < len_e - 3) {
      output[pos_e + len_e - 1 - step] = '9';
      step++;
      output[pos_e + len_e - 1 - step]--;
    }
    if (len_e > 4 && output[pos_e + 2] == '0') {
      output[pos_e + 2] = '9';
      len_e--;
    }
    if (len_e == 4 && output[pos_e + 2] == '0' && output[pos_e + 3] == '0')
      output[pos_e + 1] = '+';
  }
  output[pos_e + len_e] = '\0';
}

void reverse(char *s) {
  int i, j;
  char c;

  for (i = 0, j = s21_strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

// функция принимающая адресс и переводящий его в строку.
void p_to_str(char *output, unsigned long long mem) {
  to_the_16(output, mem, 'p');
  reverse(output);
#ifdef __linux__
  if (mem == (unsigned long long)0) s21_strcpy(output, "(nil)");
#elif __APPLE__
  if (mem == (unsigned long long)0) s21_strcpy(output, "0x0");
#endif
}

// перевод числа в 16 систему счисления.
void to_the_16(char *output, unsigned long long number, char c) {
  int temp;
  int i = 0;
  for (; number > 0; number = number / 16) {
    temp = number % 16;
    if (temp < 10) {
      output[i] = (temp + '0');
    } else if (temp > 9 && temp < 16) {
      output[i] = (temp + 'W');
    }
    i++;
  }
  if (c == 'p') {
    output[i] = 'x';
    output[i + 1] = '0';
    output[i + 2] = '\0';
  } else {
    output[i] = '\0';
  }
}
// функция принимающая число и переводящая в 16-ю систему счисления.
void x_to_str(char *output, unsigned long long num,
              s21_size_t __attribute__((unused)) size, char length) {
  switch (length) {
    case 'w': {
      //  if (size > 4) {};//exit(-1);
      unsigned char numcopy = (unsigned char)num;
      num = (unsigned long long)numcopy;
      break;
    }
    case 'h': {
      //  if (size > 4) {}; exit(-1);
      unsigned short numcopy = (unsigned short)num;
      num = (unsigned long long)numcopy;
      break;
    }
    case 'l': {
      //  if (size < 8) {}; exit(-1);
      unsigned long int numcopy = (unsigned long int)num;
      num = (unsigned long long)numcopy;
      break;
    }
    case 'W': {
      //  if (size < 8) {}; exit(-1);
      unsigned long int numcopy = (unsigned long int)num;
      num = (unsigned long long)numcopy;
      break;
    }
    default: {
      //  if (size > 4) {}; exit(-1);
      unsigned int numcopy = (unsigned int)num;
      num = (unsigned long long)numcopy;
      break;
    }
  }
  to_the_16(output, (unsigned long long)num, 'n');
  reverse(output);
}

// функция принимающая число и переводящее в 16-ю систему счисления.
void X_to_str(char *output, unsigned long long num, s21_size_t size,
              char length) {
  x_to_str(output, num, size, length);
  char *temp_output = s21_to_upper(output);
  s21_strcpy(output, temp_output);
  free(temp_output);
}

// функция принимающая число и переводящее в 8-ю систему счисления
void o_to_str(char *output, unsigned long long num,
              s21_size_t __attribute__((unused)) size, char length) {
  switch (length) {
    case 'w': {
      //  if (size > 4) {};// exit(-1);
      unsigned char numcopy = (unsigned char)num;
      num = (unsigned long long)numcopy;
      break;
    }
    case 'h': {
      //  if (size > 4) {};// exit(-1);
      unsigned short numcopy = (unsigned short)num;
      num = (unsigned long long)numcopy;
      break;
    }
    case 'l': {
      //  if (size < 8) {};// exit(-1);
      unsigned long int numcopy = (unsigned long int)num;
      num = (unsigned long long)numcopy;
      break;
    }
    case 'W': {
      //  if (size < 8) {};// exit(-1);
      unsigned long int numcopy = (unsigned long int)num;
      num = (unsigned long long)numcopy;
      break;
    }
    default: {
      //  if (size > 4) {};// exit(-1);
      unsigned int numcopy = (unsigned int)num;
      num = (unsigned long long)numcopy;
      break;
    }
  }
  to_the_8(output, (unsigned long long)num);
  reverse(output);
}

void to_the_8(char *output, unsigned long long number) {
  int temp;
  int i = 0;
  for (; number > 0; number = number / 8) {
    temp = number % 8;
    output[i] = (temp + '0');
    i++;
  }
  output[i] = '\0';
}

//  Знаковое десятичное целое число
void d_to_str(char *output, long long int num,
              __attribute__((unused)) s21_size_t size, char length) {
  //  if (num < -2147483647 || num > 2147483647) size = 8;
  if (length == 0) {
    //  if (size > 4) exit(-1);
    int numcopy = (int)num;
    num = (long long int)numcopy;
  } else if (length == 'w') {
    //  if (size > 1) exit(-1);
    signed char numcopy = (signed char)num;
    num = (long long int)numcopy;
  } else if (length == 'h') {
    //  if (size > 4) exit(-1);
    short numcopy = (short)num;
    num = (long long int)numcopy;
  } else if (length == 'l' || length == 'W') {
    //  if (size < 8) exit(-1);
    long long int numcopy = num;
    num = (long long int)numcopy;
  }
  int count = 0;
  long long int copy = num;
  for (; num; count++) num = num / 10;
  if (copy == 0) count = 1;

  if (copy < 0) {
    output[0] = '-';
    count++;
  }
  output[count] = '\0';
  count--;
  num = copy;
  int factor = 1;
  if (num == 0 && count == 0) output[count] = '0';
  for (; num; count--) {
    if (num % 10 < 0) factor = -1;
    output[count] = (char)(factor * (num % 10) + 48);
    num = num / 10;
    factor = 1;
  }
}

//  Беззнаковое целое число (значение типа unsigned int) в десятичной системе
//  счисления.
void u_to_str(char *output, unsigned long long int num,
              __attribute__((unused)) s21_size_t size, char length) {
  //  if (num > 4294967295) size = 8;
  if (length == 0) {
    //  if (size > 4) exit(-1);
    unsigned int numcopy = (int)num;
    num = (unsigned long long int)numcopy;
  } else if (length == 'w') {
    //  if (size > 1) exit(-1);
    unsigned char numcopy = (unsigned char)num;
    num = (unsigned long long int)numcopy;
  } else if (length == 'h') {
    //  if (size > 4) exit(-1);
    unsigned short numcopy = (short)num;
    num = (unsigned long long int)numcopy;
  } else if (length == 'l' || length == 'W') {
    //  if (size < 8) exit(-1);
    unsigned long int numcopy = num;
    num = (unsigned long long int)numcopy;
  }
  int count = 0;
  unsigned long long int copy = num;
  for (; num; count++) num = num / 10;
  if (copy == 0) count = 1;
  output[count] = '\0';
  count--;
  num = copy;
  if (num == 0 && count == 0) output[count] = '0';
  for (; num; count--) {
    output[count] = (char)(num % 10 + 48);
    num = num / 10;
  }
}

//  Десятичное число с плавающей точкой
//  using math.h
void f_to_str(char *output, long double num,
              __attribute__((unused)) s21_size_t size,
              __attribute__((unused)) char length) {
  switch (fpclassify(num)) {
    case FP_INFINITE:
      if (num < 0)
        s21_strcpy(output, "-inf\000");
      else
        s21_strcpy(output, "inf\000");
      break;
    case FP_NAN:
      s21_strcpy(output, "nan\000");
      break;
    default:
      //  if ((length == 0 && size > 8) || (length == 'L' && size < 16)) {
      //      exit(-1);
      //  }
      if (num == 0 && 1 / num < 0) {
        s21_strcpy(output, "-0\000");
      } else {
        if (num < 0) {
          num *= -1;
          *output = '-';
          output++;
        }
        d_to_str(output, (long long int)num, 8, 'l');
      }
      if (num - (long long int)num > 0) {
        num = num - (long long int)num;
        char *outputcopy = output;
        for (; *output; output++) {
        }
        *output = '.';
        output++;
        int digit;

        while (num > 0) {
          num *= 10;
          digit = (int)num;
          num = num - digit;
          *output = digit + 48;
          output++;
        }
        if (!num) *output = '\0';
        output = outputcopy;
      } else {
        char *outputcopy = output;
        for (; *output; output++) {
        }
        output[0] = '.';
        output[1] = 0;
        output = outputcopy;
      }
      break;
  }
}

//  Выводится значение типа float в экспоненциальной форме,
//   например, число 123.456 будет выведено в виде 1.234560e+02.
void e_to_str(char *output, long double num,
              __attribute__((unused)) s21_size_t size,
              __attribute__((unused)) char length) {
  switch (fpclassify(num)) {
    case FP_INFINITE:
      if (num < 0)
        s21_strcpy(output, "-inf");
      else
        s21_strcpy(output, "inf");
      break;
    case FP_ZERO:
      if (1 / num < 0)
        s21_strcpy(output, "-0.000000e+00");
      else
        s21_strcpy(output, "0.000000e+00");
      break;
    case FP_NAN:
      s21_strcpy(output, "nan");
      break;
    default: {
      //  if ((length == 0 && size > 8) || (length == 'L' && size < 16)) {
      //      exit(-1);
      //}
      int count = 0;
      while (num >= 10 || num <= -10) {
        num = num / 10;
        count++;
      }
      while (num < 1 && num > -1) {
        num = num * 10;
        count--;
      }
      d_to_str(output, (long int)num, 4, 0);
      if (num < 0) {
        num *= -1;
      }
      char *outputcopy = output;
      if (num - (long int)num > 0) {
        num = num - (long int)num;
        for (; *output; output++) {
        }
        *output = '.';
        output++;

        int digit;
        while (num > 0) {
          num *= 10;
          digit = (int)num;
          num = num - digit;
          *output = digit + 48;
          output++;
        }
      } else {
        num = num - (long int)num;
        for (; *output; output++) {
        }
        *output = '.';
        output++;
      }
      if (!num) {
        *output = 'e';
        output++;
        if (count >= 0) {
          *output = '+';
        } else {
          *output = '-';
          count *= -1;
        }
        output++;
        if (count >= 0 && count <= 9) {
          *output = '0';
          output++;
        }
        d_to_str(output, (long int)count, 4, 0);
        for (; *output; output++) {
        }
        *output = '\0';
      }
      output = outputcopy;
      break;
    }
  }
}

void E_to_str(char *output, long double num,
              __attribute__((unused)) s21_size_t size,
              __attribute__((unused)) char length) {
  e_to_str(output, num, size, length);
  char *output_upper = s21_to_upper(output);
  s21_strcpy(output, output_upper);
  free(output_upper);
}

//  Использует код %е или %f
//   (при использовании %g используется е нижнего регистра)
void g_to_str(char *output, long double num,
              __attribute__((unused)) s21_size_t size,
              __attribute__((unused)) char length, int *accuracy) {
  switch (fpclassify(num)) {
    case FP_INFINITE:
      if (num < 0)
        s21_strcpy(output, "-inf\000");
      else
        s21_strcpy(output, "inf\000");
      break;
    case FP_NAN:
      s21_strcpy(output, "nan\000");
      break;
    case FP_ZERO:
      if (1 / num < 0)
        s21_strcpy(output, "-0.000000\000");
      else
        s21_strcpy(output, "0.000000\000");
      *accuracy = *accuracy - 1;
      break;
    default: {
      //  if ((length == 0 && size > 8) || (length == 'L' && size < 16)) {
      //      exit(-1);
      //  }
      int count = 0;
      long double numcopy = num;
      while (num >= 10 || num <= -10) {
        num = num / 10;
        count++;
      }
      while (num < 1 && num > -1) {
        num = num * 10;
        count--;
      }
      num = numcopy;
      if (count >= -4 && count < *accuracy) {
        f_to_str(output, num, size, length);
        *accuracy = *accuracy - count - 1;
      } else {
        e_to_str(output, num, size, length);
        *accuracy = *accuracy - 1;
      }
      break;
    }
  }
}

void G_to_str(char *output, long double num,
              __attribute__((unused)) s21_size_t size,
              __attribute__((unused)) char length, int *accuracy) {
  g_to_str(output, num, size, length, accuracy);
  char *output_upper = s21_to_upper(output);
  s21_strcpy(output, output_upper);
  free(output_upper);
}

void str_to_str(char *output, char *str) {
  if (!str)
    s21_strcpy(output, "(null)");
  else
    s21_strcpy(output, str);
}

void wc_to_str(char *output, wchar_t symbol) { wctomb(output, symbol); }

void wcs_to_str(char *output, wchar_t *wstr) {
  if (!wstr)
    s21_strcpy(output, "(null)");
  else
    wcstombs(output, wstr, wcslen(wstr) * sizeof(wchar_t));
}

//  ----------------------------Ф-Л-А-Г-И---------------------------

//  ПОРЯДОК ВЫЗОВА ФУНКЦИЙ:
//        accuracy,
//        #,
//        +,
//        space (при первом вызове ставит '=' вместо ' ', требует повторного
//        вызова), width,
//        -,
//        0,
//        space (при повторном вызове заменяет '=' на ' ')

//  Обнуляет лишние и конфликтующие флаги в структуре struct_flags
void correct_flags(struct_sprintf_format *Format) {
  switch (Format->specifier) {
    case 'c':
      if (Format->flags->fplus) Format->flags->fplus = 0;
      if (Format->flags->fspace) Format->flags->fspace = 0;
      if (Format->flags->fgrid) Format->flags->fgrid = 0;
      if (Format->flags->fzero) Format->flags->fzero = 0;
      if (Format->accuracy < 0) Format->accuracy = 1;
      break;
    case 'i':
    case 'd':
      if (Format->flags->fgrid) Format->flags->fgrid = 0;
      if (Format->flags->fplus) Format->flags->fspace = 0;
      if (Format->flags->fminus) Format->flags->fzero = 0;
      if (Format->accuracy != -2) Format->flags->fzero = 0;
      if (Format->accuracy < 0) Format->accuracy = 1;
      break;
    case 'E':
    case 'e':
      if (Format->flags->fplus) Format->flags->fspace = 0;
      if (Format->flags->fminus) Format->flags->fzero = 0;
      break;
    case 'f':
      if (Format->flags->fplus) Format->flags->fspace = 0;
      if (Format->flags->fminus) Format->flags->fzero = 0;
      break;
    case 'G':
    case 'g':
      if (Format->flags->fplus) Format->flags->fspace = 0;
      if (Format->flags->fminus) Format->flags->fzero = 0;
      break;
    case 'o':
      if (Format->flags->fplus) Format->flags->fplus = 0;
      if (Format->flags->fspace) Format->flags->fspace = 0;
      if (Format->flags->fminus) Format->flags->fzero = 0;
      if (Format->accuracy != -2) Format->flags->fzero = 0;
      if (Format->accuracy < 0) Format->accuracy = 1;
      break;
    case 's':
      if (Format->flags->fplus) Format->flags->fplus = 0;
      if (Format->flags->fspace) Format->flags->fspace = 0;
      if (Format->flags->fgrid) Format->flags->fgrid = 0;
      if (Format->flags->fzero) Format->flags->fzero = 0;
      break;
    case 'u':
      if (Format->flags->fplus) Format->flags->fplus = 0;
      if (Format->flags->fspace) Format->flags->fspace = 0;
      if (Format->flags->fgrid) Format->flags->fgrid = 0;
      if (Format->flags->fminus) Format->flags->fzero = 0;
      if (Format->accuracy != -2) Format->flags->fzero = 0;
      if (Format->accuracy < 0) Format->accuracy = 1;
      break;
    case 'X':
    case 'x':
      if (Format->flags->fplus) Format->flags->fplus = 0;
      if (Format->flags->fspace) Format->flags->fspace = 0;
      if (Format->flags->fminus) Format->flags->fzero = 0;
      if (Format->accuracy != -2) Format->flags->fzero = 0;
      if (Format->accuracy < 0) Format->accuracy = 1;
      break;
    case 'p':
      if (Format->flags->fplus) Format->flags->fplus = 0;
#ifdef __APPLE__
      if (Format->flags->fspace) Format->flags->fspace = 0;
#endif
      if (Format->flags->fgrid) Format->flags->fgrid = 0;
      if (Format->flags->fzero) Format->flags->fzero = 0;
      if (Format->accuracy != -2) Format->accuracy = 1;
      if (Format->accuracy < 0) Format->accuracy = 1;
      break;
    case 'n':
    case '%':
    case '\0':
      if (Format->flags->fplus) Format->flags->fplus = 0;
      if (Format->flags->fminus) Format->flags->fminus = 0;
      if (Format->flags->fspace) Format->flags->fspace = 0;
      if (Format->flags->fgrid) Format->flags->fgrid = 0;
      if (Format->flags->fzero) Format->flags->fzero = 0;
      if (Format->accuracy != -2) Format->accuracy = 1;
      Format->width = 0;
      Format->length = 0;
      break;
  }
}

//  Если знак не будет выведен, перед значением вставляется пробел.
void flag_space_str(char *output) {
  if (*output != '+' && *output != '-' && *output != '=' && *output != ' ') {
    char *outputcopy = output;
    s21_size_t count = 0;
    for (; *output; output++) count++;
    output = outputcopy;
    s21_memmove(&output[1], output, count);
    output[0] = '=';
    output[++count] = '\0';
  } else {
    for (; *output && *output != '='; output++) {
    }
    if (*output == '=') *output = ' ';
  }
}

//  Заставляет явно указывать знак плюс или минус (+ или -) даже для
//  положительных чисел.
void flag_plus_str(char *output) {
  if (*output != '-' && *output != '+') {
    char *outputcopy = output;
    s21_size_t count = 0;
    for (; *output; output++) count++;
    output = outputcopy;
    s21_memmove(&output[1], output, count);
    output[0] = '+';
    output[++count] = '\0';
  }
#ifdef __APPLE__
  if (s21_strcmp(output, "+nan") == 0) s21_strcpy(output, "nan");
#endif
}

//  Выравнивание по левому краю в пределах заданной ширины поля.
void flag_minus_str(char *output) {
  char *outputcopy = output;
  s21_size_t count = 0;
  for (; *output == ' ' && *output; output++) {
    count++;
  }
  if (*output == '\0') count = 0;
  output = outputcopy;
  s21_memmove(output, &output[count], s21_strlen(output) - count);
  output = &output[s21_strlen(output) - count];
  for (; count; count--, output++) {
    *output = ' ';
  }
}

//  Заполняет число слева нулями (0) вместо пробелов, где указан спецификатор
//  ширины.
void flag_zero_str(char *output) {
  if (*output == ' ') {
    char *outputcopy = output;
    int count = 0;
    for (; *output && *output == ' '; output++) {
      count++;
    }
    if (*output == '\0') count = 0;
    if (*output == '+' || *output == '-' || *output == '=') {
      char sign = *output;
      output = outputcopy;
      *output = sign;
      output++;
    } else if (*output == '0' && output[1] == 'x') {
      output = outputcopy;
      *output++ = '0';
      *output++ = 'x';
    } else if (*output == '0' && output[1] == 'X') {
      output = outputcopy;
      *output++ = '0';
      *output++ = 'X';
    } else {
      output = outputcopy;
    }
    for (; count; count--, output++) *output = '0';
  }
}

//  При использовании со спецификаторами o, x или X перед числом вставляется 0,
//  0x или 0X соответственно
//   (для значений, отличных от нуля). При использовании с e, E и f "заставляет"
//   записанный вывод содержать десятичную точку, даже если за ней не последует
//   никаких цифр. По умолчанию, если не следует никаких цифр, десятичная точка
//   не записывается. При использовании с g или G результат такой же, как и с e
//   или E, но конечные нули не удаляются.
void flag_grid_str(char *output, char specifier, int accuracy) {
  int flag_n_zeros = 1;
  for (int i = 0; output[i]; i++)
    if (output[i] != '0') flag_n_zeros = 0;
  int flag_freed = 0;
  int accuracycopy = accuracy;
  char *new_str = s21_NULL;
  char *outputcopy = output;

  if (specifier == 'o' && *output != '0') new_str = s21_insert(output, "0", 0);
  if (specifier == 'x' && !flag_n_zeros) {
    if ((*output == '0' && s21_strlen(output) > 1) || (*output != '0'))
      new_str = s21_insert(output, "0x", 0);
  }
  if (specifier == 'X' && !flag_n_zeros) {
    if ((*output == '0' && s21_strlen(output) > 1) || (*output != '0'))
      new_str = s21_insert(output, "0X", 0);
  }
  if (specifier == 'f' || specifier == 'e' || specifier == 'E' ||
      specifier == 'g' || specifier == 'G') {
    if (accuracy == -2) accuracycopy = accuracy = 6;
    int count = 0;
    for (; *output && *output != '.' && *output != 'e' && *output != 'E';
         output++) {
      count++;
    }
    if (*output != '.') {
      output = outputcopy;
      new_str = s21_insert(output, ".", count);
      s21_strcpy(output, new_str);
      if (new_str) free(new_str);
      flag_freed = 1;
      new_str = s21_NULL;
      while (accuracy) {
        new_str = s21_insert(output, "0", count + 1 + accuracycopy - accuracy);
        if (new_str) flag_freed = 0;
        s21_strcpy(output, new_str);
        if (new_str) free(new_str);
        flag_freed = 1;
        new_str = s21_NULL;
        accuracy--;
      }
    } else if (*output == '.') {
      output++;
      for (; *output && *output != 'e' && *output != 'E'; output++) {
        accuracy--;
      }
      output = outputcopy;
      while (accuracy) {
        new_str = s21_insert(output, "0", count + 1 + accuracycopy - accuracy);
        if (new_str) flag_freed = 0;
        s21_strcpy(output, new_str);
        if (new_str) free(new_str);
        flag_freed = 1;
        new_str = s21_NULL;
        accuracy--;
      }
    }
  }
  if (new_str && !flag_freed) {
    output = outputcopy;
    s21_strcpy(output, new_str);
    free(new_str);
    new_str = s21_NULL;
  }
}

//  Минимальное количество печатаемых символов. Если выводимое значение короче
//  этого числа,
//   результат дополняется пробелами. Значение не усекается, даже если результат
//   больше.
void set_width_str(char *output, int width, char specifier) {
  int slength = (int)s21_strlen(output);
  //  Если строка пустая (случай, когда в %c подается 0)
  if (specifier == 'c' && slength == 0) width--;
  if (slength < width) {
    int diff = width - slength;
    char *w = calloc(diff + 1, 1);
    if (w) {
      w[diff] = '\0';
      s21_memset(w, ' ', diff);
      char *new_str = s21_insert(output, w, 0);
      if (new_str) {
        s21_strcpy(output, new_str);
        free(new_str);
      }
      free(w);
    }
  }
}
