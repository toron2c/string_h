

#include <check.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include "s21_string.h"

START_TEST(s21_memchr_0) {
  char str[30] = "Letme1down";
  int c = '1';
  int n = 10;
  char *result_memchr = memchr(str, c, n);
  char *result_s21_memchr = s21_memchr(str, c, n);
  ck_assert_str_eq(result_memchr, result_s21_memchr);
}
END_TEST

START_TEST(s21_memcmp_1) {
  char str1[30] = "next";
  char str2[30] = "nextis";
  int n = 4;
  int result_memcmp = memcmp(str1, str2, n);
  int result_s21_memcmp = s21_memcmp(str1, str2, n);
  ck_assert_int_eq(result_memcmp, result_s21_memcmp);
}
END_TEST

START_TEST(s21_memcpy_2) {
  char src[30] = "meow";
  char dest[30] = "tryit";
  int n = 10;
  char *result_memcpy = memcpy(src, dest, n);
  char *result_s21_memcpy = s21_memcpy(src, dest, n);
  ck_assert_str_eq(result_memcpy, result_s21_memcpy);
}
END_TEST

START_TEST(s21_memmove_3) {
  char str1[30] = "write";
  char str2[30] = "less";
  int n = 10;
  char *result_memmove = memmove(str2, str1, n);
  char *result_s21_memmove = s21_memmove(str2, str1, n);
  ck_assert_str_eq(result_memmove, result_s21_memmove);
}
END_TEST

//  memchr
START_TEST(s21_memchr_test) {
  char p[30] = "Hello";
  char *ptr_s21 = s21_memchr(p, 'o', 5);
  char *ptr_original = memchr(p, 'o', 5);
  ck_assert_str_eq(ptr_s21, ptr_original);
}
END_TEST

START_TEST(s21_memchr_test_NULL) {
  char p[30] = "Hello";
  char *ptr_s21 = s21_memchr(p, 'r', 5);
  char *ptr_original = memchr(p, 'r', 5);
  ck_assert_ptr_eq(ptr_s21, ptr_original);
}
END_TEST

START_TEST(s21_memchr_test_0) {
  char p[30] = "Hello";
  char *ptr_s21 = s21_memchr(p, 'H', 0);
  char *ptr_original = memchr(p, 'H', 0);
  ck_assert_ptr_eq(ptr_s21, ptr_original);
}
END_TEST

START_TEST(s21_memchr_test4) {
  char p[30] = "";
  char *ptr_s21 = s21_memchr(p, 'H', 5);
  char *ptr_original = memchr(p, 'H', 5);
  ck_assert_ptr_eq(ptr_s21, ptr_original);
}
END_TEST

//  memcmp
START_TEST(s21_memcmp_test_00) {
  char p[30] = "1234d567890";
  char p2[30] = "1234e567890";
  int original = memcmp(p, p2, 4);
  int fake = s21_memcmp(p, p2, 4);
  ck_assert_int_eq(original, fake);
}
END_TEST

START_TEST(s21_memcmp_test_0) {
  char p[30] = "123";
  char p2[30] = "123";
  int original = memcmp(p, p2, 5);
  int fake = s21_memcmp(p, p2, 5);
  ck_assert_int_eq(original, fake);
}
END_TEST

START_TEST(s21_memcmp_test_1) {
  char p[30] = "";
  char p2[30] = "1";
  int original = memcmp(p, p2, 5);
  int fake = s21_memcmp(p, p2, 5);
  ck_assert_int_eq(original < 0, fake < 0);
}
END_TEST

START_TEST(s21_memcmp_test_2) {
  char p[30] = "";
  char p2[30] = "";
  int original = memcmp(p, p2, 5);
  int fake = s21_memcmp(p, p2, 5);
  ck_assert_int_eq(original, fake);
}
END_TEST

START_TEST(s21_memcmp_test_3) {
  char p[30] = "321";
  char p2[30] = "123";
  int original = memcmp(p, p2, 5);
  int fake = s21_memcmp(p, p2, 5);
  ck_assert_int_eq(original > 0, fake > 0);
}
END_TEST

//  memcpy
START_TEST(s21_memcpy_tes1) {
  char p[30] = "";
  char p2[30];
  char *pointer_original = memcpy(p2, p, 3);
  char *pointer_fake = s21_memcpy(p2, p, 7);
  ck_assert_ptr_eq(pointer_original, pointer_fake);
}
END_TEST

START_TEST(s21_memcpy_test2) {
  char p[30] = "0";
  char p2[30];
  char *pointer_original = memcpy(p2, p, 2);
  char *pointer_fake = s21_memcpy(p2, p, 7);
  ck_assert_ptr_eq(pointer_original, pointer_fake);
}
END_TEST

START_TEST(s21_memcpy_test3) {
  char p[30] = "Test";
  char p2[30];
  char *pointer_original = memcpy(p2, p, 7);
  char *pointer_fake = s21_memcpy(p2, p, 7);
  ck_assert_ptr_eq(pointer_original, pointer_fake);
}
END_TEST

//  memmove
START_TEST(s21_memmove_test1) {
  char p[30] = "test_123";
  char *pointer_original = memmove(&p[0], &p[3], 2);
  char *pointer_fake = s21_memmove(&p[0], &p[3], 2);
  ck_assert_ptr_eq(pointer_original, pointer_fake);
}
END_TEST

START_TEST(s21_memmove_test2) {
  char p[30] = "test_123";
  char *pointer_original = memmove(&p[3], &p[0], 2);
  char *pointer_fake = s21_memmove(&p[3], &p[0], 2);
  ck_assert_ptr_eq(pointer_original, pointer_fake);
}
END_TEST

START_TEST(s21_memmove_test3) {
  char p[30] = "test_123";
  char p2[30];
  char *pointer_original = memmove(p2, p, 4);
  char *pointer_fake = s21_memmove(p2, p, 4);
  ck_assert_ptr_eq(pointer_original, pointer_fake);
}
END_TEST

//  memset
START_TEST(s21_memset_test1) {
  char p[30] = "155555";
  char p2 = '\0';
  char *pointer_original = memset(p, p2, 3);
  char *pointer_fake = s21_memset(p, p2, 3);
  ck_assert_ptr_eq(pointer_original, pointer_fake);
}
END_TEST

START_TEST(s21_memset_test2) {
  char p[30] = "test_123";
  char p2 = 'r';
  char *pointer_original = memset(p, p2, 3);
  char *pointer_fake = s21_memset(p, p2, 3);
  ck_assert_ptr_eq(pointer_original, pointer_fake);
}
END_TEST

START_TEST(s21_memset_test3) {
  char p[30] = "";
  char p2 = 'g';
  char *pointer_original = memset(p, p2, 3);
  char *pointer_fake = s21_memset(p, p2, 3);
  ck_assert_ptr_eq(pointer_original, pointer_fake);
}
END_TEST

//  strcat
START_TEST(s21_strcat_test1) {
  char p[30] = "ggg";
  char p2[30] = "321";
  char *pointer_original = strcat(p2, p);
  char *pointer_fake = s21_strcat(p2, p);
  ck_assert_ptr_eq(pointer_original, pointer_fake);
}
END_TEST

START_TEST(s21_strcat_test2) {
  char p[30] = "123";
  char p2[30] = "\0";
  char *pointer_original = strcat(p2, p);
  char *pointer_fake = s21_strcat(p2, p);
  ck_assert_ptr_eq(pointer_original, pointer_fake);
}
END_TEST

START_TEST(s21_strcat_test3) {
  char p[30] = "\0";
  char p2[30] = "123";
  char *pointer_original = strcat(p2, p);
  char *pointer_fake = s21_strcat(p2, p);
  ck_assert_ptr_eq(pointer_original, pointer_fake);
}
END_TEST

START_TEST(s21_strcat_test4) {
  char p[30] = "";
  char p2[30] = "";
  char *pointer_original = strcat(p2, p);
  char *pointer_fake = s21_strcat(p2, p);
  ck_assert_ptr_eq(pointer_original, pointer_fake);
}
END_TEST

//  strncat
START_TEST(s21_strncat_test1) {
  char p[30] = "123";
  char p2[30] = "\0";
  char *pointer_original = strncat(p2, p, 9);
  char *pointer_fake = s21_strncat(p2, p, 9);
  ck_assert_ptr_eq(pointer_original, pointer_fake);
}
END_TEST

START_TEST(s21_strncat_test2) {
  char p[30] = "\0";
  char p2[30] = "123";
  char *pointer_original = strncat(p2, p, 0);
  char *pointer_fake = s21_strncat(p2, p, 0);
  ck_assert_ptr_eq(pointer_original, pointer_fake);
}
END_TEST

START_TEST(s21_strncat_test3) {
  char p[30] = "";
  char p2[30] = "";
  char *pointer_original = strncat(p2, p, 3);
  char *pointer_fake = s21_strncat(p2, p, 3);
  ck_assert_ptr_eq(pointer_original, pointer_fake);
}
END_TEST

START_TEST(s21_strncat_test4) {
  char p[30] = "Hello";
  char p2[30] = "Test";
  char *pointer_original = strncat(p2, p, 2);
  char *pointer_fake = s21_strncat(p2, p, 2);
  ck_assert_ptr_eq(pointer_original, pointer_fake);
}
END_TEST

//  strchr
START_TEST(s21_strchr_test1) {
  char c = '\0';
  char s[30] = "123";
  char *pointer_original = strchr(s, c);
  char *pointer_fake = s21_strchr(s, c);
  ck_assert_ptr_eq(pointer_original, pointer_fake);
}
END_TEST

START_TEST(s21_strchr_test2) {
  char c = '\0';
  char s[30] = "";
  char *pointer_original = strchr(s, c);
  char *pointer_fake = s21_strchr(s, c);
  ck_assert_ptr_eq(pointer_original, pointer_fake);
}
END_TEST

START_TEST(s21_strchr_test3) {
  char c = '0';
  char s[30] = "123";
  char *pointer_original = strchr(s, c);
  char *pointer_fake = s21_strchr(s, c);
  ck_assert_ptr_eq(pointer_original, pointer_fake);
}
END_TEST

START_TEST(s21_strchr_test4) {
  char c = '1';
  char s[30] = "123";
  char *pointer_original = strchr(s, c);
  char *pointer_fake = s21_strchr(s, c);
  ck_assert_ptr_eq(pointer_original, pointer_fake);
}
END_TEST

//  strcmp
START_TEST(s21_strcmp_test1) {
  char c[30] = "321";
  char s[30] = "1";
  int pointer_original = strcmp(s, c);
  int pointer_fake = s21_strcmp(s, c);
  ck_assert_int_eq(pointer_original < 0, pointer_fake < 0);
}
END_TEST

START_TEST(s21_strcmp_test2) {
  char c[30] = "\0";
  char s[30] = "123";
  int pointer_original = strcmp(s, c);
  int pointer_fake = s21_strcmp(s, c);
  ck_assert_int_eq(pointer_original > 0, pointer_fake > 0);
}
END_TEST

START_TEST(s21_strcmp_test3) {
  char c[30] = "321";
  char s[30] = "\0";
  int pointer_original = strcmp(s, c);
  int pointer_fake = s21_strcmp(s, c);
  ck_assert_int_eq(pointer_original < 0, pointer_fake < 0);
}
END_TEST

//  strncmp
START_TEST(test_s21_strncmp_1) {
  int result_strncmp = strncmp("test1", "test2", 0);
  int result_s21_strncmp = s21_strncmp("test1", "test2", 0);
  ck_assert_int_eq(result_strncmp, result_s21_strncmp);
}
END_TEST

START_TEST(test_s21_strncmp_2) {
  int result_strncmp = strncmp("test1", "test2", 3);
  int result_s21_strncmp = s21_strncmp("test1", "test2", 3);
  ck_assert_int_eq(result_strncmp, result_s21_strncmp);
}
END_TEST

START_TEST(test_s21_strncmp_3) {
  int result_strncmp = strncmp("test1", "test2", 5);
  int result_s21_strncmp = s21_strncmp("test1", "test2", 5);
  ck_assert_int_eq(result_strncmp, result_s21_strncmp);
}
END_TEST

START_TEST(test_s21_strncmp_4) {
  int result_strncmp = strncmp("", "", 5);
  int result_s21_strncmp = s21_strncmp("", "", 5);
  ck_assert_int_eq(result_strncmp, result_s21_strncmp);
}
END_TEST

START_TEST(test_s21_strncmp_5) {
  int result_strncmp = strncmp("alsdfhd;ljdsdl;gh", "alsdfhd;ljasd", 12);
  int result_s21_strncmp =
      s21_strncmp("alsdfhd;ljdsdl;gh", "alsdfhd;ljasd", 13);
  ck_assert_int_eq(result_strncmp > 0, result_s21_strncmp > 0);
}
END_TEST

//  s21_strcpy
START_TEST(test_s21_strcpy_1) {
  char dest1[100] = "";
  char dest2[100] = "";
  char src[100] = "checking the function";
  char *result_strcpy = strcpy(dest1, src);
  char *result_s21_strcpy = s21_strcpy(dest2, src);
  ck_assert_str_eq(result_strcpy, result_s21_strcpy);
}
END_TEST

START_TEST(test_s21_strcpy_2) {
  char dest1[100] = "test: ";
  char dest2[100] = "test: ";
  char src[100] = "checking the function";
  char *result_strcpy = strcpy(dest1, src);
  char *result_s21_strcpy = s21_strcpy(dest2, src);
  ck_assert_str_eq(result_strcpy, result_s21_strcpy);
}
END_TEST

START_TEST(test_s21_strcpy_3) {
  char dest1[100] = "";
  char dest2[100] = "";
  char src[100] = "";
  char *result_strcpy = strcpy(dest1, src);
  char *result_s21_strcpy = s21_strcpy(dest2, src);
  ck_assert_str_eq(result_strcpy, result_s21_strcpy);
}
END_TEST

//  s21_strncpy
START_TEST(test_s21_strncpy_1) {
  char dest1[100] = "";
  char dest2[100] = "";
  const char *src = "checking the function";
  char *result_strncpy = strncpy(dest1, src, 5);
  char *result_s21_strncpy = s21_strncpy(dest2, src, 5);
  ck_assert_str_eq(result_strncpy, result_s21_strncpy);
}
END_TEST

START_TEST(test_s21_strncpy_2) {
  char dest1[100] = "test: ";
  char dest2[100] = "test: ";
  const char *src = "checking the function";
  char *result_strncpy = strncpy(dest1, src, 5);
  char *result_s21_strncpy = s21_strncpy(dest2, src, 5);
  ck_assert_str_eq(result_strncpy, result_s21_strncpy);
}
END_TEST

START_TEST(test_s21_strncpy_3) {
  char dest1[100] = "";
  char dest2[100] = "";
  const char *src = "";
  char *result_strncpy = strncpy(dest1, src, 2);
  char *result_s21_strncpy = s21_strncpy(dest2, src, 2);
  ck_assert_str_eq(result_strncpy, result_s21_strncpy);
}
END_TEST

//  s21_strcspn
START_TEST(test_s21_strcspn_1) {
  const char str1[] = "checking the function";
  const char str2[] = "fu";
  s21_size_t result_strcspn = strcspn(str1, str2);
  s21_size_t result_s21_strcspn = s21_strcspn(str1, str2);
  ck_assert_int_eq(result_strcspn, result_s21_strcspn);
}
END_TEST

START_TEST(test_s21_strcspn_2) {
  const char str1[] = "checking the function";
  const char str2[] = "1";
  s21_size_t result_strcspn = strcspn(str1, str2);
  s21_size_t result_s21_strcspn = s21_strcspn(str1, str2);
  ck_assert_int_eq(result_strcspn, result_s21_strcspn);
}
END_TEST

START_TEST(test_s21_strcspn_3) {
  const char str1[] = "checking the function";
  const char str2[] = "";
  s21_size_t result_strcspn = strcspn(str1, str2);
  s21_size_t result_s21_strcspn = s21_strcspn(str1, str2);
  ck_assert_int_eq(result_strcspn, result_s21_strcspn);
}
END_TEST

//  s21_strerror
START_TEST(test_s21_strerror_1) {
  ck_assert_str_eq(strerror(0), s21_strerror(0));
}
END_TEST

START_TEST(test_s21_strerror_2) {
  ck_assert_str_eq(strerror(48), s21_strerror(48));
}
END_TEST

START_TEST(test_s21_strerror_3) {
  for (int i = -10; i < 10; i++) ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

//  strlen
START_TEST(s21_strlen_test1) {
  char p[30] = "";
  int length_original = strlen(p);
  int length_fake = s21_strlen(p);
  ck_assert_int_eq(length_original, length_fake);
}
END_TEST

START_TEST(s21_strlen_test2) {
  char p[30] = "1";
  int length_original = strlen(p);
  int length_fake = s21_strlen(p);
  ck_assert_int_eq(length_original, length_fake);
}
END_TEST

START_TEST(s21_strlen_test3) {
  char p[30] = "test";
  int length_original = strlen(p);
  int length_fake = s21_strlen(p);
  ck_assert_int_eq(length_original, length_fake);
}
END_TEST

START_TEST(s21_strlen_test4) {
  char p[30] = "testlk\000sdajf";
  int length_original = strlen(p);
  int length_fake = s21_strlen(p);
  ck_assert_int_eq(length_original, length_fake);
}
END_TEST

//  strpbrk
START_TEST(s21_strpbrk_test1) {
  char p[30] = "\0";
  char p2[30] = "";
  char *original = strpbrk(p, p2);
  char *fake = s21_strpbrk(p, p2);
  ck_assert_ptr_eq(original, fake);
}
END_TEST

START_TEST(s21_strpbrk_test2) {
  char p[30] = "";
  char p2[30] = "";
  char *original = strpbrk(p, p2);
  char *fake = s21_strpbrk(p, p2);
  ck_assert_ptr_eq(original, fake);
}
END_TEST

START_TEST(s21_strpbrk_test3) {
  char p[30] = "";
  char p2[30] = "\0";
  char *original = strpbrk(p, p2);
  char *fake = s21_strpbrk(p, p2);
  ck_assert_ptr_eq(original, fake);
}
END_TEST

START_TEST(s21_strpbrk_test4) {
  char p[30] = "321";
  char p2[30] = "1";
  char *original = strpbrk(p, p2);
  char *fake = s21_strpbrk(p, p2);
  ck_assert_ptr_eq(original, fake);
}
END_TEST

START_TEST(s21_strpbrk_test5) {
  char p[30] = "1";
  char p2[30] = "321";
  char *original = strpbrk(p, p2);
  char *fake = s21_strpbrk(p, p2);
  ck_assert_ptr_eq(original, fake);
}
END_TEST

//  strrchr
START_TEST(s21_strrchr_test1) {
  char p[30] = "111  ";
  char c = ' ';
  char *original = strrchr(p, c);
  char *fake = s21_strrchr(p, c);
  ck_assert_ptr_eq(original, fake);
}
END_TEST

START_TEST(s21_strrchr_test2) {
  char p[30] = "111";
  char c = '\0';
  char *original = strrchr(p, c);
  char *fake = s21_strrchr(p, c);
  ck_assert_ptr_eq(original, fake);
}
END_TEST

START_TEST(s21_strrchr_test3) {
  char p[30] = "111";
  char c = '-';
  char *original = strrchr(p, c);
  char *fake = s21_strrchr(p, c);
  ck_assert_ptr_eq(original, fake);
}
END_TEST

START_TEST(s21_strrchr_test4) {
  char p[30] = "111111";
  char c = '1';
  char *original = strrchr(p, c);
  char *fake = s21_strrchr(p, c);
  ck_assert_ptr_eq(original, fake);
}
END_TEST

START_TEST(s21_strrchr_test5) {
  char p[30] = "321111303000\0";
  char c = '3';
  char *original = strrchr(p, c);
  char *fake = s21_strrchr(p, c);
  ck_assert_ptr_eq(original, fake);
}
END_TEST

//  strspn
START_TEST(s21_strspn_test1) {
  char p[30] = "123";
  char p2[30] = "\0";
  int original = strspn(p, p2);
  int fake = s21_strspn(p, p2);
  ck_assert_int_eq(original, fake);
}
END_TEST

START_TEST(s21_strspn_test2) {
  char p[30] = "\0";
  char p2[30] = "123";
  int original = strspn(p, p2);
  int fake = s21_strspn(p, p2);
  ck_assert_int_eq(original, fake);
}
END_TEST

START_TEST(s21_strspn_test3) {
  char p[30] = "1111111111";
  char p2[30] = "1";
  int original = strspn(p, p2);
  int fake = s21_strspn(p, p2);
  ck_assert_int_eq(original, fake);
}
END_TEST

START_TEST(s21_strspn_test4) {
  char p[30] = "11133111";
  char p2[30] = "1";
  int original = strspn(p, p2);
  int fake = s21_strspn(p, p2);
  ck_assert_int_eq(original, fake);
}
END_TEST

START_TEST(s21_strspn_test5) {
  char p[30] = "1111333311111";
  char p2[30] = "3";
  int original = strspn(p, p2);
  int fake = s21_strspn(p, p2);
  ck_assert_int_eq(original, fake);
}
END_TEST

START_TEST(s21_strspn_test6) {
  char p[30] = "azxasd123123";
  char p2[30] = "azxcasd123123";
  int original = strspn(p, p2);
  int fake = s21_strspn(p, p2);
  ck_assert_int_eq(original, fake);
}
END_TEST

START_TEST(s21_strspn_test7) {
  char p[30] = "-123-1235555";
  char p2[30] = "-123";
  int original = strspn(p, p2);
  int fake = s21_strspn(p, p2);
  ck_assert_int_eq(original, fake);
}
END_TEST

START_TEST(s21_strspn_test8) {
  char p[30] = "7878789";
  char p2[30] = "9";
  int original = strspn(p, p2);
  int fake = s21_strspn(p, p2);
  ck_assert_int_eq(original, fake);
}
END_TEST

//  strstr
START_TEST(s21_strstr_test0) {
  char p[30] = "abrakadabra";
  char p2[30] = "123";
  char *original = strstr(p, p2);
  char *fake = s21_strstr(p, p2);
  ck_assert_ptr_eq(original, fake);
}
END_TEST

START_TEST(s21_strstr_test1) {
  char p[30] = "";
  char p2[30] = "";
  char *original = strstr(p, p2);
  char *fake = s21_strstr(p, p2);
  ck_assert_ptr_eq(original, fake);
}
END_TEST

START_TEST(s21_strstr_test2) {
  char p[30] = "\0";
  char p2[30] = "123";
  char *original = strstr(p, p2);
  char *fake = s21_strstr(p, p2);
  ck_assert_ptr_eq(original, fake);
}
END_TEST

START_TEST(s21_strstr_test3) {
  char p[30] = "123";
  char p2[30] = "\0";
  char *original = strstr(p, p2);
  char *fake = s21_strstr(p, p2);
  ck_assert_ptr_eq(original, fake);
}
END_TEST

START_TEST(s21_strstr_test4) {
  char p[30] = "abrakadabra";
  char p2[30] = "a";
  char *original = strstr(p, p2);
  char *fake = s21_strstr(p, p2);
  ck_assert_ptr_eq(original, fake);
}
END_TEST

START_TEST(s21_strstr_test5) {
  char p[30] = "100500";
  char p2[30] = "1";
  char *original = strstr(p, p2);
  char *fake = s21_strstr(p, p2);
  ck_assert_ptr_eq(original, fake);
}
END_TEST

//  s21_to_upper  =====================================
START_TEST(s21_to_upper_test_empty) {
  char *output = s21_to_upper("");
  ck_assert_str_eq(output, "");
  if (output) free(output);
}
END_TEST

START_TEST(s21_to_upper_test_null) {
  char *output = s21_to_upper(s21_NULL);
  ck_assert_ptr_eq(output, s21_NULL);
  if (output) free(output);
}
END_TEST

START_TEST(s21_to_upper_test_normal) {
  char *output = s21_to_upper("aquickbrownfox jumpsoverthelazydog");
  ck_assert_str_eq(output, "AQUICKBROWNFOX JUMPSOVERTHELAZYDOG");
  if (output) free(output);
}
END_TEST

START_TEST(s21_to_upper_test_zero) {
  char *output = s21_to_upper("\000asdf");
  ck_assert_str_eq(output, "\0");
  if (output) free(output);
}
END_TEST

START_TEST(s21_to_upper_test_numbers) {
  char *output = s21_to_upper("12a3B451dfa3';'; `b45");
  ck_assert_str_eq(output, "12A3B451DFA3';'; `B45");
  if (output) free(output);
}
END_TEST

//  s21_to_lower  ======================================
START_TEST(s21_to_lower_test_empty) {
  char *output = s21_to_lower("");
  ck_assert_str_eq(output, "");
  if (output) free(output);
}
END_TEST

START_TEST(s21_to_lower_test_null) {
  char *output = s21_to_lower(s21_NULL);
  ck_assert_ptr_eq(output, s21_NULL);
  if (output) free(output);
}
END_TEST

START_TEST(s21_to_lower_test_normal) {
  char *output = s21_to_lower("AQUICKBROWNFOX JUMPSOVERTHELAZYDOG");
  ck_assert_str_eq(output, "aquickbrownfox jumpsoverthelazydog");
  if (output) free(output);
}
END_TEST

START_TEST(s21_to_lower_test_zero) {
  char *output = s21_to_lower("\0DF");
  ck_assert_str_eq(output, "\0");
  if (output) free(output);
}
END_TEST

START_TEST(s21_to_lower_test_numbers) {
  char *output = s21_to_lower("1DFa3';'; `B45");
  ck_assert_str_eq(output, "1dfa3';'; `b45");
  if (output) free(output);
}
END_TEST

//  s21_insert  ========================================
START_TEST(s21_insert_test_empty) {
  char *output = s21_insert("", "", 0);
  ck_assert_str_eq(output, "");
  if (output) free(output);
}
END_TEST

START_TEST(s21_insert_test_empty_null) {
  char *output = s21_insert("", "", 1);
  ck_assert_ptr_eq(output, s21_NULL);
  if (output) free(output);
}
END_TEST

START_TEST(s21_insert_test_src_empty) {
  char *output = s21_insert("", "3435adg ';45", 0);
  ck_assert_str_eq(output, "3435adg ';45");
  if (output) free(output);
}
END_TEST

START_TEST(s21_insert_test_str_empty) {
  char *output = s21_insert("98dYf89hsd adsf';a\000S", "", 4);
  ck_assert_str_eq(output, "98dYf89hsd adsf';a\000S");
  if (output) free(output);
}
END_TEST

START_TEST(s21_insert_test_str_outofsrc_null) {
  char *output = s21_insert("98dYf df43\000653", "kjasdy", 11);
  ck_assert_ptr_eq(output, s21_NULL);
  if (output) free(output);
}
END_TEST

START_TEST(s21_insert_test_normal) {
  char *output = s21_insert("ldskjf0u 0 o4df'", "kjasdy", 11);
  ck_assert_str_eq(output, "ldskjf0u 0 kjasdyo4df'");
  if (output) free(output);
}
END_TEST

START_TEST(s21_insert_test_normal_start) {
  char *output = s21_insert("ldskjf0u 0 o4df'", "kjasdy", 0);
  ck_assert_str_eq(output, "kjasdyldskjf0u 0 o4df'");
  if (output) free(output);
}
END_TEST

START_TEST(s21_insert_test_normal_end) {
  char *output = s21_insert("ldskjf0u 0 o4df'", "kjasdy", 16);
  ck_assert_str_eq(output, "ldskjf0u 0 o4df'kjasdy");
  if (output) free(output);
}
END_TEST

START_TEST(s21_insert_test_0) {
  char str[30] = "hello";
  char *output = s21_insert(str, "bye", 0);
  ck_assert_str_eq(output, "byehello");
  free(output);
}
END_TEST

START_TEST(s21_insert_test_1) {
  char str[30] = "hello";
  char *output = s21_insert(str, s21_NULL, 0);
  ck_assert_str_eq(output, str);
  free(output);
}
END_TEST

START_TEST(s21_insert_test_2) {
  char *output = s21_insert(s21_NULL, "bye", 0);
  ck_assert_ptr_eq(output, s21_NULL);
  free(output);
}
END_TEST

START_TEST(s21_insert_test_3) {
  char str[30] = "hello";
  char *output = s21_insert(str, "bye", -1);
  ck_assert_ptr_eq(output, s21_NULL);
  free(output);
}
END_TEST

START_TEST(s21_insert_test_4) {
  char str[30] = "hello";
  char *output = s21_insert(str, "bye", 5);
  ck_assert_str_eq(output, "hellobye");
  free(output);
}
END_TEST

START_TEST(s21_insert_test_5) {
  char str[30] = "hello";
  char *output = s21_insert(str, "bye", 6);
  ck_assert_ptr_eq(output, s21_NULL);
  free(output);
}
END_TEST

START_TEST(s21_insert_test_6) {
  char str[30] = "hello";
  char *output = s21_insert(str, "", 3);
  ck_assert_str_eq(output, str);
  free(output);
}
END_TEST

//  s21_trim  ==========================================
START_TEST(s21_trim_test_normal) {
  char *output = s21_trim("*.dd..sf**\000sd38", "3*.");
  ck_assert_str_eq(output, "dd..sf");
  if (output) free(output);
}
END_TEST

START_TEST(s21_trim_test_normal_no_trim) {
  char *output = s21_trim("*.dd..sf**\000sd38", "adfsg");
  ck_assert_str_eq(output, "*.dd..sf**");
  if (output) free(output);
}
END_TEST

START_TEST(s21_trim_test_src_empty) {
  char *output = s21_trim("\000sdfl", "dsaf");
  ck_assert_str_eq(output, "");
  if (output) free(output);
}
END_TEST

START_TEST(s21_trim_test_chars_empty) {
  char *output = s21_trim("ewr2\000sdfl", "");
  ck_assert_str_eq(output, "ewr2");
  if (output) free(output);
}
END_TEST

START_TEST(s21_trim_test_src_null) {
  char *output = s21_trim(s21_NULL, "th df 3");
  ck_assert_ptr_eq(output, s21_NULL);
  if (output) free(output);
}
END_TEST

START_TEST(s21_trim_test_chars_null) {
  char *output = s21_trim("lasdjf s23", s21_NULL);
  ck_assert_str_eq(output, "lasdjf s23");
  if (output) free(output);
}
END_TEST

START_TEST(s21_trim_test_0) {
  char *output = s21_trim(" *** Much Ado about nothing '*** ", "* '");
  ck_assert_str_eq(output, "Much Ado about nothing");
  if (output) free(output);
}
END_TEST

START_TEST(s21_trim_test_1) {
  char *output = s21_trim(" *** Much Ado about nothing '*** ", "");
  ck_assert_str_eq(output, "*** Much Ado about nothing '***");
  if (output) free(output);
}
END_TEST

START_TEST(s21_trim_test_2) {
  char *output = s21_trim(" *** Much Ado about nothing '*** ", s21_NULL);
  ck_assert_str_eq(output, "*** Much Ado about nothing '***");
  if (output) free(output);
}
END_TEST

//  s21_strtok  ========================================
START_TEST(s21_strtok_test_normal) {
  char str1[100] = "The summer soldier, the sunshine patriot.";
  char str2[100] = "The summer soldier, the sunshine patriot.";
  char *output1 = s21_strtok(str1, " ,.");
  char *output2 = strtok(str2, " ,.");
  while (output2 && output1) {
    ck_assert_str_eq(output1, output2);
    output1 = s21_strtok(s21_NULL, " ,.");
    output2 = strtok(NULL, " ,.");
  }
}
END_TEST

START_TEST(s21_strtok_test_delim_empty) {
  char str1[100] = "The summer soldier, the sunshine patriot.";
  char str2[100] = "The summer soldier, the sunshine patriot.";
  char *output1 = s21_strtok(str1, "");
  char *output2 = strtok(str2, "");
  while (output2 && output1) {
    ck_assert_str_eq(output1, output2);
    output1 = s21_strtok(s21_NULL, "");
    output2 = strtok(NULL, "");
  }
}
END_TEST

START_TEST(s21_strtok_test_str_equal_to_delim) {
  char str1[100] = "The summer soldier, the sunshine patriot.";
  char str2[100] = "The summer soldier, the sunshine patriot.";
  char *output1 = s21_strtok(str1, "The summer soldier, the sunshine patriot.");
  char *output2 = strtok(str2, "The summer soldier, the sunshine patriot.");
  ck_assert_ptr_eq(output1, output2);
}
END_TEST

START_TEST(s21_strtok_test_str_empty) {
  char str1[100] = "\000The summer soldier, the sunshine patriot.";
  char str2[100] = "\000The summer soldier, the sunshine patriot.";
  char *output1 = s21_strtok(str1, "The summer");
  char *output2 = strtok(str2, "The summer");
  ck_assert_ptr_eq(output1, output2);
}
END_TEST

START_TEST(s21_strtok_test_delim_changed) {
  char str1[100] = "The summer soldier, the sunshine patriot.";
  char str2[100] = "The summer soldier, the sunshine patriot.";
  char *output1 = s21_strtok(str1, " ,;.");
  char *output2 = strtok(str2, " ,;.");
  while (output2 && output1) {
    ck_assert_str_eq(output1, output2);
    output1 = s21_strtok(s21_NULL, "t/s");
    output2 = strtok(NULL, "t/s");
  }
}
END_TEST

START_TEST(s21_strtok_test_delim_not_found) {
  char str1[100] = "The summer soldier, the sunshine patriot.";
  char str2[100] = "The summer soldier, the sunshine patriot.";
  char *output1 = s21_strtok(str1, "SDG");
  char *output2 = strtok(str2, "SGD");
  while (output2 && output1) {
    ck_assert_str_eq(output1, output2);
    output1 = s21_strtok(s21_NULL, "t/s");
    output2 = strtok(NULL, "t/s");
  }
}
END_TEST
//  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//  +++++++++++++S+P+R+I+N+T+F++T+E+S+T+S+++++++++++++++++++
//  c tests
START_TEST(s21_sprintf_c_tests_1) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  char c = 'l';
  return_number_or = sprintf(original, "%c", c);
  return_number_fk = s21_sprintf(fake, "%c", c);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_fk, return_number_or);
}
END_TEST

START_TEST(s21_sprintf_c_tests_2) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  char c = 'l';
  char b = 'w';
  return_number_or = sprintf(original, "%3c s%-7c", b, c);
  return_number_fk = s21_sprintf(fake, "%3c s%-7c", b, c);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_fk, return_number_or);
}
END_TEST

START_TEST(s21_sprintf_c_tests_3) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  //  (void)setlocale(LC_ALL, "");
  wchar_t c = L'ф';
  wchar_t b = L'ы';
  return_number_or = sprintf(original, "%3lcsd s%-7lc   %lcfdg", b, c, 0);
  return_number_fk = s21_sprintf(fake, "%3lcsd s%-7lc   %lcfdg", b, c, 0);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_fk, return_number_or);
}
END_TEST

START_TEST(s21_sprintf_c_tests_4) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  char c = 'l';
  char b = 'w';
  char e = 'g';
  return_number_or = sprintf(original, "%3c s%-3c %c", b, c, e);
  return_number_fk = s21_sprintf(fake, "%3c s%-3c %c", b, c, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_fk, return_number_or);
}
END_TEST

START_TEST(s21_sprintf_c_tests_5) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  char c = 'l';
  char b = 49;
  return_number_or = sprintf(original, "%*c s%3chelloworld", 6, b, c);
  return_number_fk = s21_sprintf(fake, "%*c s%3chelloworld", 6, b, c);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_fk, return_number_or);
}
END_TEST

START_TEST(s21_sprintf_c_tests_6) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  return_number_or = sprintf(original, "hell%c %3c %c", 0, 0, 49);
  return_number_fk = s21_sprintf(fake, "hell%c %3c %c", 0, 0, 49);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_fk, return_number_or);
}
END_TEST

// int tests
START_TEST(s21_sprintf_d_test0) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  int d = 50000;
  return_number_or = sprintf(original, "hello  %d", d);
  return_number_fk = s21_sprintf(fake, "hello  %d", d);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_d_test1) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  int x = 0;
  return_number_or = sprintf(original, "%010d", x);
  return_number_fk = s21_sprintf(fake, "%010d", x);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_d_test2) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  int x = 10;
  return_number_or = sprintf(original, "%+*.*d", 1, 10, x);
  return_number_fk = s21_sprintf(fake, "%+*.*d", 1, 10, x);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_d_test3) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  int x = 10;
  return_number_or = sprintf(original, "%+*.*d", 2, 10, x);
  return_number_fk = s21_sprintf(fake, "%+*.*d", 2, 10, x);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_d_test4) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  int x = 10;
  return_number_or = sprintf(original, "%+*.*d", 2, 5, x);
  return_number_fk = s21_sprintf(fake, "%+*.*d", 2, 5, x);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_d_test5) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  int x = 10;
  int c = -50;
  return_number_or = sprintf(original, "%*.*d % 0d ", 2, 5, x, c);
  return_number_fk = s21_sprintf(fake, "%*.*d % 0d ", 2, 5, x, c);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_d_test6) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  short int x = 10;
  short int c = -50;
  short int e = 2000;
  return_number_or = sprintf(original, "%0*hd % .2hd %+3hd", 5, x, c, e);
  return_number_fk = s21_sprintf(fake, "%0*hd % .2hd %+3hd", 5, x, c, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_d_test7) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long int x = 10;
  long int c = -50;
  long int e = 200000;
  return_number_or = sprintf(original, "%-*.*ld % .2ld %+3ld", 2, 5, x, c, e);
  return_number_fk = s21_sprintf(fake, "%-*.*ld % .2ld %+3ld", 2, 5, x, c, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_d_test8) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long int x = 50000000000;
  long int c = -50000000000;
  long int e = 122000000000000000;
  return_number_or = sprintf(original, "%-*.*ld % .25ld %+15ld", 2, 5, x, c, e);
  return_number_fk = s21_sprintf(fake, "%-*.*ld % .25ld %+15ld", 2, 5, x, c, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_d_test9) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  signed char x = 128;
  signed char c = -128;
  signed char e = 129;
  return_number_or =
      sprintf(original, "%-*.*hhd % .25hhd  %+15hhd", 2, 5, x, c, e);
  return_number_fk =
      s21_sprintf(fake, "%-*.*hhd % .25hhd  %+15hhd", 2, 5, x, c, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_d_test99) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  signed char x = 128;
  signed char c = -128;
  signed char e = 129;
  return_number_or =
      sprintf(original, "%-*.*hhd % *.3hhd  %0+1hhd", 2, 5, x, 3, c, e);
  return_number_fk =
      s21_sprintf(fake, "%-*.*hhd % *.3hhd  %0+1hhd", 2, 5, x, 3, c, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_d_test10) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long long x = 128;
  long long c = -128;
  long long e = 129;
  return_number_or =
      sprintf(original, "%-*.*lld % .25lld  %+15lld", 2, 5, x, c, e);
  return_number_fk =
      s21_sprintf(fake, "%-*.*lld % .25lld  %+15lld", 2, 5, x, c, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_d_test11) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long long x = 128;
  long long c = -128;
  long long e = 129;
  return_number_or =
      sprintf(original, "%-*.*lld % *.5lld  %+5.*lld", 2, 5, x, 3, c, 3, e);
  return_number_fk =
      s21_sprintf(fake, "%-*.*lld % *.5lld  %+5.*lld", 2, 5, x, 3, c, 3, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_d_test12) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long long z = 0;
  return_number_or = sprintf(original, "%lld % .5lld  %+5lld", -z, -z, -z);
  return_number_fk = s21_sprintf(fake, "%lld % .5lld  %+5lld", -z, -z, -z);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_d_test13) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  return_number_or = sprintf(original, "%0d % .5d  %+5d", -0, 0, -0);
  return_number_fk = s21_sprintf(fake, "%0d % .5d  %+5d", -0, 0, -0);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_d_test14) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long int z = 0;
  return_number_or = sprintf(original, "%0ld %- .5ld  %+5ld", z, z, -z);
  return_number_fk = s21_sprintf(fake, "%0ld %- .5ld  %+5ld", z, z, -z);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_d_test15) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  return_number_or = sprintf(original, "%0hd %- .5hhd  %+5hhd", -0, 0, -0);
  return_number_fk = s21_sprintf(fake, "%0hd %- .5hhd  %+5hhd", -0, 0, -0);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

//  i tests
START_TEST(s21_sprintf_i_test0) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  int d = 50000;
  return_number_or = sprintf(original, "%i %.0d", d, -0);
  return_number_fk = s21_sprintf(fake, "%i %.0d", d, -0);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_i_test1) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  int x = 0;
  return_number_or = sprintf(original, "%22i%i-%i", x, x, x);
  return_number_fk = s21_sprintf(fake, "%22i%i-%i", x, x, x);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_i_test2) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  int x = 1111;
  long int x2 = 1123123123;
  short int x3 = -12312;
  return_number_or = sprintf(original, "%+*.*i %+*.*li %+*.*hi", 1, 10, x, 1,
                             10, x2, 1, 10, x3);
  return_number_fk = s21_sprintf(fake, "%+*.*i %+*.*li %+*.*hi", 1, 10, x, 1,
                                 10, x2, 1, 10, x3);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_i_test3) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  int x = 125124;
  long int x2 = 1231241246;
  short int x3 = 3124;
  return_number_or = sprintf(original, "%+*.*i %+*.*li %+*.*hi", 2, 10, x, 2,
                             10, x2, 2, 10, x3);
  return_number_fk = s21_sprintf(fake, "%+*.*i %+*.*li %+*.*hi", 2, 10, x, 2,
                                 10, x2, 2, 10, x3);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_i_test4) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  int x = 10;
  long int x2 = 10;
  short int x3 = 10;
  return_number_or =
      sprintf(original, "%-*.*i %-*.*li %-*.*hi", 2, 5, x, 2, 5, x2, 2, 15, x3);
  return_number_fk =
      s21_sprintf(fake, "%-*.*i %-*.*li %-*.*hi", 2, 5, x, 2, 5, x2, 2, 15, x3);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_i_test5) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  int x = 10;
  int c = -50;
  long int x2 = 10;
  long int c2 = -50;
  short int x3 = 10;
  short int c3 = -50;
  return_number_or = sprintf(original, "%-*.*i % i %-*.*li %05li %-*.*hi % hi",
                             2, 5, x, c, 2, 5, x2, c2, 2, 5, x3, c3);
  return_number_fk = s21_sprintf(fake, "%-*.*i % i %-*.*li %05li %-*.*hi % hi",
                                 2, 5, x, c, 2, 5, x2, c2, 2, 5, x3, c3);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_i_test6) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  short int x = 10;
  short int c = -50;
  short int e = 3393;
  return_number_or = sprintf(original, "%-*.*hi % .2hi  %+3hi", 2, 5, x, c, e);
  return_number_fk = s21_sprintf(fake, "%-*.*hi % .2hi  %+3hi", 2, 5, x, c, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_i_test7) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long int x = 10;
  long int c = -50;
  long int e = 200000;
  return_number_or =
      sprintf(original, "%-*.*li % .12ld  %0+7ld", 2, 5, x, c, e);
  return_number_fk =
      s21_sprintf(fake, "%-*.*li % .12ld  %0+7ld", 2, 5, x, c, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_i_test8) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long int x = 50000000000;
  long int c = -50000000000;
  long int e = 122000000000000000;
  return_number_or =
      sprintf(original, "%-*.*li % .25li  %0+15li", 2, 5, x, c, e);
  return_number_fk =
      s21_sprintf(fake, "%-*.*li % .25li  %0+15li", 2, 5, x, c, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_i_test9) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  signed char x = 128;
  signed char c = -128;
  signed char e = 129;
  return_number_or =
      sprintf(original, "%-*.*hhi % .25hhi  %+15hhi", 2, 5, x, c, e);
  return_number_fk =
      s21_sprintf(fake, "%-*.*hhi % .25hhi  %+15hhi", 2, 5, x, c, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_i_test99) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  signed char x = 128;
  signed char c = -128;
  signed char e = 129;
  return_number_or =
      sprintf(original, "%-*.*hhi % *.3hhi  %+1.*hhi", 2, 5, x, 3, c, 3, e);
  return_number_fk =
      s21_sprintf(fake, "%-*.*hhi % *.3hhi  %+1.*hhi", 2, 5, x, 3, c, 3, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_i_test10) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long long x = 128;
  long long c = -128;
  long long e = 129;
  return_number_or =
      sprintf(original, "%-*.*lli % .25lli  %0+15lli", 2, 5, x, c, e);
  return_number_fk =
      s21_sprintf(fake, "%-*.*lli % .25lli  %0+15lli", 2, 5, x, c, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_i_test11) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long long x = 128;
  long long c = -128;
  long long e = 129;
  return_number_or =
      sprintf(original, "%-*.*lli % *.5lli  %+5.*lli", 2, 5, x, 3, c, 3, e);
  return_number_fk =
      s21_sprintf(fake, "%-*.*lli % *.5lli  %+5.*lli", 2, 5, x, 3, c, 3, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_i_test12) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long long int z = 0;
  return_number_or = sprintf(original, "%lli % .5lli  %+5lli", z, z, -z);
  return_number_fk = s21_sprintf(fake, "%lld % .5lli  %+5lli", z, z, -z);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_i_test13) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  return_number_or = sprintf(original, "%08i % .5i  %+5i", -0, -0, -0);
  return_number_fk = s21_sprintf(fake, "%08i % .5i  %+5i", -0, -0, -0);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_i_test14) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long int z = 0;
  return_number_or = sprintf(original, "%020li % .5li  %+5li", z, z, -z);
  return_number_fk = s21_sprintf(fake, "%020li % .5li  %+5li", z, z, -z);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_i_test15) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  return_number_or = sprintf(original, "%07hi %- .5hhi  %+5hhi", -0, -0, 0);
  return_number_fk = s21_sprintf(fake, "%07hi %- .5hhi  %+5hhi", -0, -0, 0);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

//  e tests
START_TEST(s21_sprintf_e_test0) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  float e = 12.4423543245;
  float e2 = -12.4423543245;
  return_number_or =
      sprintf(original, "%e , %5.5e, %-5.5le, %+5.5e", e / 1000, e2, e2, e2);
  return_number_fk =
      s21_sprintf(fake, "%e , %5.5e, %-5.5le, %+5.5e", e / 1000, e2, e2, e2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_e_test1) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  float e = 12.4423543245;
  float e2 = -12.4423543245;
  return_number_or = sprintf(original, "%#- *.*e %0 *.*le %*.*e %*.*e", 2, 2, e,
                             2, 2, e2, 2, 2, e2, 11, 12, e2);
  return_number_fk = s21_sprintf(fake, "%#- *.*e %0 *.*le %*.*e %*.*e", 2, 2, e,
                                 2, 2, e2, 2, 2, e2, 11, 12, e2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_e_test2) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  double e = 1.123123123;
  double e2 = -1.123123456;
  return_number_or = sprintf(original, "%le , %5.5e, %-5.5e,", e, e2, e2);
  return_number_fk = s21_sprintf(fake, "%le , %5.5e, %-5.5e,", e, e2, e2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_e_test3) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  double e = 1.123123123;
  double e2 = -1.123123456;
  return_number_or = sprintf(original, ", %#0 *.*e %+*.*e %*.*e %-*.*e", 2, 2,
                             e, 1, 1, e2, 1, 1, e2, 1, 1, e2);
  return_number_fk = s21_sprintf(fake, ", %#0 *.*e %+*.*e %*.*e %-*.*e", 2, 2,
                                 e, 1, 1, e2, 1, 1, e2, 1, 1, e2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_e_test4) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  double e = 1.111;
  long double e2 = 1123123.123;
  long double e3 = -12.312;
  return_number_or = sprintf(original, "%+*.*e %+*.*Le %+*.*Le", -1, 10, e, 1,
                             10, e2, 1, 10, e3);
  return_number_fk = s21_sprintf(fake, "%+*.*e %+*.*Le %+*.*Le", -1, 10, e, 1,
                                 10, e2, 1, 10, e3);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_e_test5) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long double x = 125.124;
  long double x2 = -123124124.6;
  long double x3 = 3.124124215;
  return_number_or = sprintf(original, "%+*.*Le %+*.*Le %+*.*Le", 20, 10, x, 20,
                             10, x2, 20, 10, x3);
  return_number_fk = s21_sprintf(fake, "%+*.*Le %+*.*Le %+*.*Le", 20, 10, x, 20,
                                 10, x2, 20, 10, x3);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_e_test6) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  float f = NAN;
  double f1 = -INFINITY;
  long double f2 = NAN;
  long double f3 = INFINITY;
  return_number_or = sprintf(original, "%#0+10.1e %+0.10Le %-10Le %#- *.*f", f,
                             f3, f2, 23, 23, f1);
  return_number_fk = s21_sprintf(fake, "%#0+10.1e %+0.10Le %-10Le %#- *.*f", f,
                                 f3, f2, 23, 23, f1);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_e_test7) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  float f = 1;
  double f1 = -INFINITY;
  long double f2 = -1;
  long double f3 = INFINITY;
  return_number_or = sprintf(original, "%#0 10.3le %0 .10Le %#010Le %Le %+e",
                             f / f1, f2, f2 / f3, f2 / f1, f1);
  return_number_fk = s21_sprintf(fake, "%#0 10.3le %0 .10Le %#010Le %Le %+e",
                                 f / f1, f2, f2 / f3, f2 / f1, f1);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_e_test8) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  double z = 0;
  return_number_or =
      sprintf(original, "%e %.1e %010e % e %+e %# -e", z, -z, -z, z, -z, z);
  return_number_fk =
      s21_sprintf(fake, "%e %.1e %010e % e %+e %# -e", z, -z, -z, z, -z, z);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_e_test9) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long double z = 0;
  return_number_or =
      sprintf(original, "%Le %.1Le %08Le % Le %+Le %# -Le", z, z, z, z, z, -z);
  return_number_fk =
      s21_sprintf(fake, "%Le %.1Le %08Le % Le %+Le %# -Le", z, z, z, z, z, -z);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_e_test10) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  float e = 12.4423543245;
  float e2 = -12.4423543245;
  return_number_or = sprintf(original, "%#0+*.*e %- *.*e %*.*e %*.*le", 2, 2, e,
                             2, 2, e2, 2, 2, e2, 11, 12, e2);
  return_number_fk = s21_sprintf(fake, "%#0+*.*e %- *.*e %*.*e %*.*le", 2, 2, e,
                                 2, 2, e2, 2, 2, e2, 11, 12, e2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

// E tests
START_TEST(s21_sprintf_E_test0) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  float e = 12.4423543245;
  float e2 = -12.4423543245;
  return_number_or =
      sprintf(original, "%e , %5.5lE, %-5.5E, %+5.5E", e, e2, e2, e2);
  return_number_fk =
      s21_sprintf(fake, "%e , %5.5lE, %-5.5E, %+5.5E", e, e2, e2, e2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_E_test1) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  float e = 12.4423543245;
  float e2 = -12.4423543245;
  return_number_or = sprintf(original, "%#- *.*E %0 *.*E %+*.*E %*.*E", 2, 2, e,
                             2, 2, e2, 2, 2, e2, 11, 12, e2);
  return_number_fk = s21_sprintf(fake, "%#- *.*E %0 *.*E %+*.*E %*.*E", 2, 2, e,
                                 2, 2, e2, 2, 2, e2, 11, 12, e2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_E_test2) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  double e = 1.123123123;
  double e2 = -1.123123456;
  return_number_or = sprintf(original, "%E , %5.5E, %-5.5E,", e, e2, e2);
  return_number_fk = s21_sprintf(fake, "%E , %5.5E, %-5.5E,", e, e2, e2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_E_test3) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  double e = 1.123123123;
  double e2 = -1.123123456;
  return_number_or = sprintf(original, ", %#- *.*E %0 *.*E %+*.*E %*.*E", 2, 2,
                             e2, 1, 1, e, 1, 1, e2, 1, 1, e2);
  return_number_fk = s21_sprintf(fake, ", %#- *.*E %0 *.*E %+*.*E %*.*E", 2, 2,
                                 e2, 1, 1, e, 1, 1, e2, 1, 1, e2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_E_test4) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  double e = 1.111;
  long double e2 = 1123123.123;
  long double e3 = -12.312;
  return_number_or = sprintf(original, "%+*.*E %+*.*LE %+*.*LE", 1, 10, e, 1,
                             10, e2, 1, 10, e3);
  return_number_fk = s21_sprintf(fake, "%+*.*E %+*.*LE %+*.*LE", 1, 10, e, 1,
                                 10, e2, 1, 10, e3);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_E_test5) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long double x = 125.124;
  long double x2 = -123124124.6;
  long double x3 = 3.124124215;
  return_number_or = sprintf(original, "%+*.*LE %+*.*LE %+*.*LE", 20, 10, x, 20,
                             10, x2, 20, 10, x3);
  return_number_fk = s21_sprintf(fake, "%+*.*LE %+*.*LE %+*.*LE", 20, 10, x, 20,
                                 10, x2, 20, 10, x3);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_E_test6) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long double x = 125.124;
  long double x2 = -123124124.6;
  long double x3 = 3.124124215;
  return_number_or = sprintf(original, "%+*.*LE %+*.*LE %+*.*LE", 20, 10, x, 20,
                             10, x2, 20, 10, x3);
  return_number_fk = s21_sprintf(fake, "%+*.*LE %+*.*LE %+*.*LE", 20, 10, x, 20,
                                 10, x2, 20, 10, x3);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_E_test7) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long double x = 0.00000009;
  long double x2 = -9.99999999999;
  long double x3 = 3.124124215999999e-01;
  long double x4 = 9.999999e+99;
  return_number_or = sprintf(original, "%+*.*LE %+*.*LE %+*.*LE %.2LE", 20, 7,
                             x, 20, 10, x2, 20, 10, x3, x4);
  return_number_fk = s21_sprintf(fake, "%+*.*LE %+*.*LE %+*.*LE %.2LE", 20, 7,
                                 x, 20, 10, x2, 20, 10, x3, x4);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_E_test8) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long double x = 0.00000009;
  long double x2 = 9.99999999999e+09;
  long double x3 = 9.999999e-01;
  long double x4 = 9.9999e-10;
  return_number_or = sprintf(original, "%+*.*LE %+*.*LE %+*.*LE %.2LE ", 20, 5,
                             x, 20, 3, x2, 20, 3, x3, x4);
  return_number_fk = s21_sprintf(fake, "%+*.*LE %+*.*LE %+*.*LE %.2LE ", 20, 5,
                                 x, 20, 3, x2, 20, 3, x3, x4);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_E_test9) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long double x = 9.999999e-100;
  long double x2 = 9.9999e-10;
  return_number_or = sprintf(original, "%+*.*LE %.2LE ", 10, 3, x, x2);
  return_number_fk = s21_sprintf(fake, "%+*.*LE %.2LE ", 10, 3, x, x2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_E_test10) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  float z = 0;
  return_number_or =
      sprintf(original, "%E %.1E %1E %0 10E %+E %# -E", z, z, z, z, -z, z);
  return_number_fk =
      s21_sprintf(fake, "%E %.1E %1E %0 10E %+E %# -E", z, z, z, z, -z, z);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_E_test11) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  float e = 12.4423543245;
  float e2 = -12.4423543245;
  return_number_or = sprintf(original, "%#0+*.*E % *.*E %-*.*E %*.*lE", 2, 2, e,
                             2, 2, e2, 2, 2, e2, 11, 12, e2);
  return_number_fk = s21_sprintf(fake, "%#0+*.*E % *.*E %-*.*E %*.*lE", 2, 2, e,
                                 2, 2, e2, 2, 2, e2, 11, 12, e2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_E_test12) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long double z = 0;
  return_number_or = sprintf(original, "%LE %-.1LE %1LE % LE %+LE %#0 10LE", z,
                             z, z, z, -z, z);
  return_number_fk = s21_sprintf(fake, "%LE %-.1LE %1LE % LE %+LE %#0 10LE", z,
                                 z, z, z, -z, z);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_f_test0) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  float f = 12.123;
  float f2 = -12.123;
  return_number_or = sprintf(original, "%lf, %-f", f, f2);
  return_number_fk = s21_sprintf(fake, "%lf, %-f", f, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_f_test1) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  float f = 12.123;
  float f2 = -12.123;
  return_number_or = sprintf(original, "%.2f %.*lf", f, 2, f2);
  return_number_fk = s21_sprintf(fake, "%.2f %.*lf", f, 2, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_f_test2) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  float f = 12.123;
  float f2 = -12.123;
  return_number_or = sprintf(original, "%.2f %.*f", f, -2, f2);
  return_number_fk = s21_sprintf(fake, "%.2f %.*f", f, -2, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_f_test3) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  float f = 12.123;
  float f2 = -12.123;
  return_number_or = sprintf(original, "%2.2f %*.*lf", f, 2, 2, f2);
  return_number_fk = s21_sprintf(fake, "%2.2f %*.*lf", f, 2, 2, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_f_test33) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  float f = 12.123;
  float f2 = -12.123;
  return_number_or = sprintf(original, "%-2.2f %*.*f", f, -2, 2, f2);
  return_number_fk = s21_sprintf(fake, "%-2.2f %*.*f", f, -2, 2, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_f_test4) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  float f = 12.123;
  float f2 = -12.123;
  return_number_or = sprintf(original, "%#0 f %#- *.*f", f, 1, 1, f2);
  return_number_fk = s21_sprintf(fake, "%#0 f %#- *.*f", f, 1, 1, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_f_test44) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  float f = 12.123;
  float f2 = -12.123;
  return_number_or = sprintf(original, "%#0+1.1f %#- *.*f", f, 23, 23, f2);
  return_number_fk = s21_sprintf(fake, "%#0+1.1f %#- *.*f", f, 23, 23, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_f_test5) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  double f = 12.123;
  double f2 = -12.123;
  return_number_or = sprintf(original, "%f, %-f", f, f2);
  return_number_fk = s21_sprintf(fake, "%f, %-f", f, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_f_test6) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  double f = 12.123;
  double f2 = -12.123;
  return_number_or = sprintf(original, "%.2lf %.*f", f, 2, f2);
  return_number_fk = s21_sprintf(fake, "%.2lf %.*f", f, 2, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_f_test7) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  double f = 12.123;
  double f2 = -12.123;
  return_number_or = sprintf(original, "%.2f %.*f", f, -2, f2);
  return_number_fk = s21_sprintf(fake, "%.2f %.*f", f, -2, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_f_test8) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  double f = 12.123;
  double f2 = -12.123;
  return_number_or = sprintf(original, "%2.2f %*.*f", f, 2, 2, f2);
  return_number_fk = s21_sprintf(fake, "%2.2f %*.*f", f, 2, 2, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_f_test9) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  double f = 12.123;
  double f2 = -12.123;
  return_number_or = sprintf(original, "%-2.2lf %*.*f", f, -2, 2, f2);
  return_number_fk = s21_sprintf(fake, "%-2.2lf %*.*f", f, -2, 2, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_f_test10) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  double f = 12.123;
  double f2 = -12.123;
  return_number_or = sprintf(original, "%#0 f %#+-*.*f", f, 1, 1, f2);
  return_number_fk = s21_sprintf(fake, "%#0 f %#+-*.*f", f, 1, 1, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_f_test11) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  double f = 12.123;
  double f2 = -12.123;
  return_number_or = sprintf(original, "%#0+1.1f %#- *.*f", f, 23, 23, f2);
  return_number_fk = s21_sprintf(fake, "%#0+1.1f %#- *.*f", f, 23, 23, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_f_test12) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long double f = 1111112.123;
  long double f2 = -1123122.123;
  return_number_or = sprintf(original, "%Lf, %-Lf", f, f2);
  return_number_fk = s21_sprintf(fake, "%Lf, %-Lf", f, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_f_test13) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long double f = 1111112.123;
  long double f2 = -1123122.123;
  return_number_or = sprintf(original, "%.2Lf %.*Lf", f, 2, f2);
  return_number_fk = s21_sprintf(fake, "%.2Lf %.*Lf", f, 2, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_f_test14) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long double f = 1111112.123;
  long double f2 = -1123122.123;
  return_number_or = sprintf(original, "%.2Lf %.*Lf", f, -2, f2);
  return_number_fk = s21_sprintf(fake, "%.2Lf %.*Lf", f, -2, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_f_test15) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long double f = 1111112.123;
  long double f2 = -1123122.123;
  return_number_or = sprintf(original, "%2.2Lf %*.*Lf", f, 2, 2, f2);
  return_number_fk = s21_sprintf(fake, "%2.2Lf %*.*Lf", f, 2, 2, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_f_test16) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long double f = 1111112.123;
  long double f2 = -1123122.123;
  return_number_or = sprintf(original, "%-2.2Lf %*.*Lf", f, -2, 2, f2);
  return_number_fk = s21_sprintf(fake, "%-2.2Lf %*.*Lf", f, -2, 2, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_f_test17) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long double f = 1111112.123;
  long double f2 = -1123122.123;
  return_number_or = sprintf(original, "%#0 Lf %#-+*.*Lf", f, 1, 1, f2);
  return_number_fk = s21_sprintf(fake, "%#0 Lf %#-+*.*Lf", f, 1, 1, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_f_test18) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long double f = 1111112.123;
  long double f2 = -1123122.123;
  return_number_or = sprintf(original, "%#0 1.1Lf %#+-*.*Lf", f, 23, 23, f2);
  return_number_fk = s21_sprintf(fake, "%#0 1.1Lf %#+-*.*Lf", f, 23, 23, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_f_test19) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  float f = NAN;
  double f1 = -INFINITY;
  long double f2 = NAN;
  long double f3 = INFINITY;
  return_number_or = sprintf(original, "%#0+10.1f %0 .10Lf %-10Lf %#- *.*f", f,
                             f3, f2, 23, 23, f1);
  return_number_fk = s21_sprintf(fake, "%#0+10.1f %0 .10Lf %-10Lf %#- *.*f", f,
                                 f3, f2, 23, 23, f1);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_f_test20) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  float f = 1;
  double f1 = -INFINITY;
  long double f2 = -1;
  long double f3 = INFINITY;
  return_number_or = sprintf(original, "%#0+10.3f %0 .10Lf %-#10Lf %Lf %+Lf",
                             f / f1, f2, f2 / f3, f2 / f1, (long double)f1 * f);
  return_number_fk =
      s21_sprintf(fake, "%#0+10.3f %0 .10Lf %-#10Lf %Lf %+Lf", f / f1, f2,
                  f2 / f3, f2 / f1, (long double)f1 * f);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_f_test21) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  return_number_or = sprintf(original, "%#0+1.1Lf % f", (long double)0., 0.);
  return_number_fk = s21_sprintf(fake, "%#0+1.1Lf % f", (long double)0., 0.);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_f_test22) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  float z = 0.;
  return_number_or =
      sprintf(original, "%f %.1f %1f % f %+f %# -f", z, z, z, z, -z, z);
  return_number_fk =
      s21_sprintf(fake, "%f %.1f %1f % f %+f %# -f", z, z, z, z, -z, z);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_f_test23) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long double z = 0.;
  return_number_or =
      sprintf(original, "%Lf %.1Lf %+1Lf % Lf % Lf %# -Lf", z, z, z, z, -z, z);
  return_number_fk =
      s21_sprintf(fake, "%Lf %.1Lf %+1Lf % Lf % Lf %# -Lf", z, z, z, z, -z, z);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

// g tests
START_TEST(s21_sprintf_g_test0) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  float f = 12123.123;
  float f2 = -12123.123;
  return_number_or = sprintf(original, "%lg, %-g", f, f2);
  return_number_fk = s21_sprintf(fake, "%lg, %-g", f, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_g_test1) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  float f = 16666.666555;
  float f2 = -16666.666555;
  return_number_or = sprintf(original, "%.2g %.*g", f, 2, f2);
  return_number_fk = s21_sprintf(fake, "%.2g %.*g", f, 2, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_g_test2) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  float f = 12.123;
  float f2 = -12.123;
  return_number_or = sprintf(original, "%.2g %.*g", f, -2, f2);
  return_number_fk = s21_sprintf(fake, "%.2g %.*g", f, -2, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_g_test3) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  float f = 12.123;
  float f2 = -12.123;
  return_number_or = sprintf(original, "%2.2g %*.*g", f, 2, 2, f2);
  return_number_fk = s21_sprintf(fake, "%2.2g %*.*g", f, 2, 2, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_g_test33) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  float f = 0.666665555555;
  float f2 = -0.666665555555;
  return_number_or = sprintf(original, "%-2.2g %*.*g", f, -2, 2, f2);
  return_number_fk = s21_sprintf(fake, "%-2.2g %*.*g", f, -2, 2, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_g_test4) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  float f = 12.444123;
  float f2 = -12.55555123;
  return_number_or = sprintf(original, "%#0 g %#- *.*lg", f, 1, 1, f2);
  return_number_fk = s21_sprintf(fake, "%#0 g %#- *.*lg", f, 1, 1, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_g_test44) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  float f = 33.3333333;
  float f2 = -33.323232;
  return_number_or = sprintf(original, "%#0+1.1lg %#- *.*g", f, 23, 23, f2);
  return_number_fk = s21_sprintf(fake, "%#0+1.1lg %#- *.*g", f, 23, 23, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_g_test5) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  double f = 3312.123;
  double f2 = -3312.123;
  return_number_or = sprintf(original, "%g, %-lg", f, f2);
  return_number_fk = s21_sprintf(fake, "%g, %-lg", f, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_g_test6) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  double f = 12.123;
  double f2 = -12.123;
  return_number_or = sprintf(original, "%.2g %.*g", f, 2, f2);
  return_number_fk = s21_sprintf(fake, "%.2g %.*g", f, 2, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_g_test7) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  double f = 0.55554;
  double f2 = -0.5554;
  return_number_or = sprintf(original, "%.2g %.*g", f, -2, f2);
  return_number_fk = s21_sprintf(fake, "%.2g %.*g", f, -2, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_g_test8) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  double f = 0.55556;
  double f2 = -0.5556;
  return_number_or = sprintf(original, "%2.2g %*.*g", f, 2, 2, f2);
  return_number_fk = s21_sprintf(fake, "%2.2g %*.*g", f, 2, 2, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_g_test9) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  double f = 666.555555556;
  double f2 = -666.55555556;
  return_number_or = sprintf(original, "%-2.2g %*.*g", f, -2, 2, f2);
  return_number_fk = s21_sprintf(fake, "%-2.2g %*.*g", f, -2, 2, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_g_test10) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  double f = 12444.123;
  double f2 = -12444.123;
  return_number_or = sprintf(original, "%#- g %#0 *.*g", f, 1, 1, f2);
  return_number_fk = s21_sprintf(fake, "%#- g %#0 *.*g", f, 1, 1, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_g_test11) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  double f = 0.666665555555;
  double f2 = -6666666.6666666666;
  return_number_or = sprintf(original, "%#0+1.1g %#- *.*g", f, 23, 23, f2);
  return_number_fk = s21_sprintf(fake, "%#0+1.1g %#- *.*g", f, 23, 23, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_g_test12) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long double f = 1111112.123;
  long double f2 = -1123122.123;
  return_number_or = sprintf(original, "%Lg, %-Lg", f, f2);
  return_number_fk = s21_sprintf(fake, "%Lg, %-Lg", f, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_g_test13) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long double f = 1111112.123;
  long double f2 = -1123122.123;
  return_number_or = sprintf(original, "%.2Lg %.*Lg", f, 2, f2);
  return_number_fk = s21_sprintf(fake, "%.2Lg %.*Lg", f, 2, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_g_test14) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long double f = 11111122.123;
  long double f2 = -112312222.123;
  return_number_or = sprintf(original, "%.2Lg %.*Lg", f, -2, f2);
  return_number_fk = s21_sprintf(fake, "%.2Lg %.*Lg", f, -2, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_g_test15) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long double f = 1111112.123;
  long double f2 = -1123122.123;
  return_number_or = sprintf(original, "%2.2Lg %*.*Lg", f, 2, 2, f2);
  return_number_fk = s21_sprintf(fake, "%2.2Lg %*.*Lg", f, 2, 2, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_g_test16) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long double f = 1111112.123;
  long double f2 = -1123122.123;
  return_number_or = sprintf(original, "%-2.2Lg %*.*Lg", f, -2, 2, f2);
  return_number_fk = s21_sprintf(fake, "%-2.2Lg %*.*Lg", f, -2, 2, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_g_test17) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long double f = 1111112.123;
  long double f2 = -1123122.123;
  return_number_or = sprintf(original, "%#0 Lg %#- *.*Lg", f, 1, 1, f2);
  return_number_fk = s21_sprintf(fake, "%#0 Lg %#- *.*Lg", f, 1, 1, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_g_test18) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long double f = 1111112.123;
  long double f2 = -1123122.123;
  return_number_or = sprintf(original, "%#0+1.1Lg %#- *.*Lg", f, 23, 23, f2);
  return_number_fk = s21_sprintf(fake, "%#0+1.1Lg %#- *.*Lg", f, 23, 23, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_g_test19) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  float f = NAN;
  double f1 = -INFINITY;
  long double f2 = NAN;
  long double f3 = INFINITY;
  return_number_or = sprintf(original, "%#0 10.1g %+0.10Lg %-10Lg %#- *.*g", f,
                             f3, f2, 23, 23, f1);
  return_number_fk = s21_sprintf(fake, "%#0 10.1g %+0.10Lg %-10Lg %#- *.*g", f,
                                 f3, f2, 23, 23, f1);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_g_test20) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  float f = 1;
  double f1 = -INFINITY;
  long double f2 = -1;
  long double f3 = INFINITY;
  return_number_or = sprintf(original, "%#0 10.1g %+0.10Lg %-#10Lg %Lg", f / f1,
                             f2, f2 / f3, f2 / f1);
  return_number_fk = s21_sprintf(fake, "%#0 10.1g %+0.10Lg %-#10Lg %Lg", f / f1,
                                 f2, f2 / f3, f2 / f1);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_g_test21) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long double z = 0.;
  return_number_or = sprintf(original, "%#0+1.10Lg %-8Lg", -z, z);
  return_number_fk = s21_sprintf(fake, "%#0+1.10Lg %-8Lg", -z, z);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_g_test22) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  float z = 0.;
  return_number_or =
      sprintf(original, "%g %.4g %10g % g %+g %# -g", z, z, z, z, -z, -z);
  return_number_fk =
      s21_sprintf(fake, "%g %.4g %10g % g %+g %# -g", z, z, z, z, -z, -z);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_g_test23) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long double z = 0.;
  return_number_or = sprintf(original, "%#015Lg %.4Lg %1Lg %0Lg %+Lg %# -Lg", z,
                             z, z, z, -z, z);
  return_number_fk = s21_sprintf(fake, "%#015Lg %.4Lg %1Lg %0Lg %+Lg %# -Lg", z,
                                 z, z, z, -z, z);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

// G tests
START_TEST(s21_sprintf_G_test0) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  float f = 12123.123;
  float f2 = -12123.123;
  return_number_or = sprintf(original, "%G, %-lG", f, f2);
  return_number_fk = s21_sprintf(fake, "%G, %-lG", f, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_G_test1) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  float f = 16666.666555;
  float f2 = -16666.666555;
  return_number_or = sprintf(original, "%.2G %.*G", f, 2, f2);
  return_number_fk = s21_sprintf(fake, "%.2G %.*G", f, 2, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_G_test2) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  float f = 12.123;
  float f2 = -12.123;
  return_number_or = sprintf(original, "%.2G %.*G", f, -2, f2);
  return_number_fk = s21_sprintf(fake, "%.2G %.*G", f, -2, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_G_test3) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  float f = 12.123;
  float f2 = -12.123;
  return_number_or = sprintf(original, "%2.2G %*.*lG", f, 2, 2, f2);
  return_number_fk = s21_sprintf(fake, "%2.2G %*.*lG", f, 2, 2, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_G_test33) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  float f = 0.666665555555;
  float f2 = -0.666665555555;
  return_number_or = sprintf(original, "%-2.2lG %*.*G", f, -2, 2, f2);
  return_number_fk = s21_sprintf(fake, "%-2.2lG %*.*G", f, -2, 2, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_G_test4) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  float f = 12.444123;
  float f2 = -12.55555123;
  return_number_or = sprintf(original, "%#0 G %#- *.*G", f, 1, 1, f2);
  return_number_fk = s21_sprintf(fake, "%#0 G %#- *.*G", f, 1, 1, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_G_test44) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  float f = 33.3333333;
  float f2 = -33.323232;
  return_number_or = sprintf(original, "%#0+1.1G %#- *.*G", f, 23, 23, f2);
  return_number_fk = s21_sprintf(fake, "%#0+1.1G %#- *.*G", f, 23, 23, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_G_test5) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  double f = 3312.123;
  double f2 = -3312.123;
  return_number_or = sprintf(original, "%G, %-G", f, f2);
  return_number_fk = s21_sprintf(fake, "%G, %-G", f, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_G_test6) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  double f = 12.123;
  double f2 = -12.123;
  return_number_or = sprintf(original, "%.2G %.*G", f, 2, f2);
  return_number_fk = s21_sprintf(fake, "%.2G %.*G", f, 2, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_G_test7) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  double f = 0.55554;
  double f2 = -0.5554;
  return_number_or = sprintf(original, "%.5lG %.*G", f, -2, f2);
  return_number_fk = s21_sprintf(fake, "%.5lG %.*G", f, -2, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_G_test8) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  double f = 0.55556;
  double f2 = -0.5556;
  return_number_or = sprintf(original, "%2.2G %*.*G", f, 2, 2, f2);
  return_number_fk = s21_sprintf(fake, "%2.2G %*.*G", f, 2, 2, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_G_test9) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  double f = 666.555555556;
  double f2 = -666.55555556;
  return_number_or = sprintf(original, "%-2.2G %*.*G", f, -2, 2, f2);
  return_number_fk = s21_sprintf(fake, "%-2.2G %*.*G", f, -2, 2, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_G_test10) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  double f = 12444.123;
  double f2 = -12444.123;
  return_number_or = sprintf(original, "%#- G %#0 *.*G", f, 1, 1, f2);
  return_number_fk = s21_sprintf(fake, "%#- G %#0 *.*G", f, 1, 1, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_G_test11) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  double f = 0.666665555555;
  double f2 = -6666666.6666666666;
  return_number_or = sprintf(original, "%#0+1.1G %#- *.*G", f, 23, 23, f2);
  return_number_fk = s21_sprintf(fake, "%#0+1.1G %#- *.*G", f, 23, 23, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_G_test12) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long double f = 1111112.123;
  long double f2 = -1123122.123;
  return_number_or = sprintf(original, "%LG,  %-LG", f, f2);
  return_number_fk = s21_sprintf(fake, "%LG,  %-LG", f, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_G_test13) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long double f = 1111112.123;
  long double f2 = -1123122.123;
  return_number_or = sprintf(original, "%.2LG %.*LG", f, 2, f2);
  return_number_fk = s21_sprintf(fake, "%.2LG %.*LG", f, 2, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_G_test14) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long double f = 11111122.123;
  long double f2 = -112312222.123;
  return_number_or = sprintf(original, "%.2LG %.*LG", f, -2, f2);
  return_number_fk = s21_sprintf(fake, "%.2LG %.*LG", f, -2, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_G_test15) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long double f = 1111112.123;
  long double f2 = -1123122.123;
  return_number_or = sprintf(original, "%2.2LG %*.*LG", f, 2, 2, f2);
  return_number_fk = s21_sprintf(fake, "%2.2LG %*.*LG", f, 2, 2, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_G_test16) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long double f = 1111112.123;
  long double f2 = -1123122.123;
  return_number_or = sprintf(original, "%-2.2LG %*.*LG", f, -2, 2, f2);
  return_number_fk = s21_sprintf(fake, "%-2.2LG %*.*LG", f, -2, 2, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_G_test17) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long double f = 1111112.123;
  long double f2 = -1123122.123;
  return_number_or = sprintf(original, "%#- LG %#0 *.*LG", f, 1, 1, f2);
  return_number_fk = s21_sprintf(fake, "%#- LG %#0 *.*LG", f, 1, 1, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_G_test18) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long double f = 1111112.123;
  long double f2 = -1123122.123;
  return_number_or = sprintf(original, "%#0+1.1LG %#- *.*LG", f, 23, 23, f2);
  return_number_fk = s21_sprintf(fake, "%#0+1.1LG %#- *.*LG", f, 23, 23, f2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_G_test19) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long double x = 0.00000009;
  long double x2 = -9.99999999999;
  long double x3 = 3.124124215999999e-01;
  return_number_or = sprintf(original, "%+*.*LG %+*.*LG %+*.*LG", 20, 7, x, 20,
                             10, x2, 20, 10, x3);
  return_number_fk = s21_sprintf(fake, "%+*.*LG %+*.*LG %+*.*LG", 20, 7, x, 20,
                                 10, x2, 20, 10, x3);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_G_test20) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long double x = 0.00000009;
  long double x2 = 9.99999999999e+09;
  long double x3 = 9.999999e-01;
  return_number_or = sprintf(original, "%+*.*LG %+*.*LG %+*.*LG", 20, 5, x, 20,
                             3, x2, 20, 3, x3);
  return_number_fk = s21_sprintf(fake, "%+*.*LG %+*.*LG %+*.*LG", 20, 5, x, 20,
                                 3, x2, 20, 3, x3);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_G_test21) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long double z = 0.;
  return_number_or = sprintf(original, "%#0 1.1LG %+#010LG", z, -z);
  return_number_fk = s21_sprintf(fake, "%#0 1.1LG %+#010LG", z, -z);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_G_test22) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  double z = 0.;
  return_number_or =
      sprintf(original, "%- G %.1G %#020G % G %+G %# -G", z, z, z, z, -z, z);
  return_number_fk =
      s21_sprintf(fake, "%- G %.1G %#020G % G %+G %# -G", z, z, z, z, -z, z);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_G_test23) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long double z = 0;
  return_number_or = sprintf(original, "%LG %.10LG %010LG % LG %+LG %# -LG", z,
                             z, z, z, -z, z);
  return_number_fk = s21_sprintf(fake, "%LG %.10LG %010LG % LG %+LG %# -LG", z,
                                 z, z, z, -z, z);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

// o tests

START_TEST(s21_sprintf_o_test0) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  int o = 50000;
  return_number_or = sprintf(original, "%o", o);
  return_number_fk = s21_sprintf(fake, "%o", o);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_o_test1) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  int x = 0;
  return_number_or = sprintf(original, "%5o", x);
  return_number_fk = s21_sprintf(fake, "%5o", x);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_o_test2) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  int x = 10;
  return_number_or = sprintf(original, "%#*.*o", -1, 10, x);
  return_number_fk = s21_sprintf(fake, "%#*.*o", -1, 10, x);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_o_test3) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  int x = 10;
  return_number_or = sprintf(original, "%-#*.*o", 2, 10, x);
  return_number_fk = s21_sprintf(fake, "%-#*.*o", 2, 10, x);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_o_test4) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  int x = 10;
  return_number_or = sprintf(original, "%#0*o", 2, x);
  return_number_fk = s21_sprintf(fake, "%#0*o", 2, x);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_o_test5) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  int x = 10;
  int c = -50;
  return_number_or = sprintf(original, "%#-*.*o %010o ", 2, 5, x, c);
  return_number_fk = s21_sprintf(fake, "%#-*.*o %010o ", 2, 5, x, c);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_o_test6) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  short int x = 10;
  short int c = -50;
  short int e = 20000;
  return_number_or = sprintf(original, "%#-*.*ho %.2ho  %03ho", 2, 5, x, c, e);
  return_number_fk = s21_sprintf(fake, "%#-*.*ho %.2ho  %03ho", 2, 5, x, c, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_o_test7) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long int x = 10;
  long int c = -50;
  long int e = 200000;
  return_number_or = sprintf(original, "%#-*.*lo %.2lo  %03lo", 2, 5, x, c, e);
  return_number_fk = s21_sprintf(fake, "%#-*.*lo %.2lo  %03lo", 2, 5, x, c, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_o_test8) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long int x = 50000000000;
  long int c = -50000000000;
  long int e = 122000000000000000;
  return_number_or =
      sprintf(original, "%#-*.*lo %.25lo  %015lo", 2, 5, x, c, e);
  return_number_fk =
      s21_sprintf(fake, "%#-*.*lo %.25lo  %015lo", 2, 5, x, c, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_o_test88) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long int x = 50000000000;
  long int c = -50000000000;
  long int e = 122000000000000000;
  return_number_or = sprintf(original, "%#-*.*lo %.5lo %020lo", 2, 5, x, c, e);
  return_number_fk = s21_sprintf(fake, "%#-*.*lo %.5lo %020lo", 2, 5, x, c, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_o_test9) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  signed char x = 128;
  signed char c = -128;
  signed char e = 129;
  return_number_or =
      sprintf(original, "%#-*.*hho %.25hho  %-15hho", 2, 5, x, c, e);
  return_number_fk =
      s21_sprintf(fake, "%#-*.*hho %.25hho  %-15hho", 2, 5, x, c, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_o_test99) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  signed char x = 128;
  signed char c = -128;
  signed char e = 129;
  return_number_or =
      sprintf(original, "%#-*.*hho %*.3hho  %1.*hho", 2, 5, x, 3, c, 3, e);
  return_number_fk =
      s21_sprintf(fake, "%#-*.*hho %*.3hho  %1.*hho", 2, 5, x, 3, c, 3, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_o_test10) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long long x = 128;
  long long c = -128;
  long long e = 129;
  return_number_or =
      sprintf(original, "%#-*.*llo %.25llo  %015llo", 2, 5, x, c, e);
  return_number_fk =
      s21_sprintf(fake, "%#-*.*llo %.25llo  %015llo", 2, 5, x, c, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_o_test11) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long long x = 128;
  long long c = -128;
  long long e = 129;
  return_number_or =
      sprintf(original, "%#-*.*llo %*.5llo  %5.*llo", 2, 5, x, 3, c, 3, e);
  return_number_fk =
      s21_sprintf(fake, "%#-*.*llo %*.5llo  %5.*llo", 2, 5, x, 3, c, 3, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_o_test12) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  unsigned long long z = 0;
  return_number_or = sprintf(original, "%010llo %-.5llo    %-15llo", z, z, -z);
  return_number_fk = s21_sprintf(fake, "%010llo %-.5llo    %-15llo", z, z, -z);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_o_test13) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  unsigned int z = 0;
  return_number_or = sprintf(original, "%#07o %.5o  %-5o", z, z, -z);
  return_number_fk = s21_sprintf(fake, "%#07o %.5o  %-5o", z, z, -z);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_o_test14) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  unsigned long z = 0;
  return_number_or = sprintf(original, "%#012lo %-.8lo  %-5lo", z, z, -z);
  return_number_fk = s21_sprintf(fake, "%#012lo %-.8lo  %-5lo", z, z, -z);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_o_test15) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  unsigned char z = 0;
  return_number_or = sprintf(original, "%#09ho %.5hho  %-5hho", 0, z, -z);
  return_number_fk = s21_sprintf(fake, "%#09ho %.5hho  %-5hho", 0, z, -z);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

//  s tests
START_TEST(s21_sprintf_s_test) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;

  char str[200] = "Test string";
  return_number_or = sprintf(original, "%s", str);
  return_number_fk = s21_sprintf(fake, "%s", str);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);

  return_number_or = sprintf(original, "%10.2s", str);
  return_number_fk = s21_sprintf(fake, "%10.2s", str);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);

  return_number_or = sprintf(original, "%*.*s", 5, 5, str);
  return_number_fk = s21_sprintf(fake, "%*.*s", 5, 5, str);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);

  return_number_or = sprintf(original, "%*.*s", 10, 0, str);
  return_number_fk = s21_sprintf(fake, "%*.*s", 10, 0, str);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_s_test0) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  char s1[] = "`halsdkala;lksd";
  char s2[] = "alksdjlskgdn;l";
  return_number_or = sprintf(original, "%s %.2s %2.2s", s1, s2, s2);
  return_number_fk = s21_sprintf(fake, "%s %.2s %2.2s", s1, s2, s2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_s_test1) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  char s1[] = "`halsdkala;lksd asdasdas";
  char s2[] = "alksdjlskgdn; l asdasdasf";
  return_number_or = sprintf(original, "%s  %*.2s %2.2s", s1, 2, s2, s2);
  return_number_fk = s21_sprintf(fake, "%s  %*.2s %2.2s", s1, 2, s2, s2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_s_test2) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  char s1[] = "this is test";
  char s2[] = "this not test";
  return_number_or = sprintf(original, "%-s  %2.2s %-2.2s", s1, s2, s2);
  return_number_fk = s21_sprintf(fake, "%-s  %2.2s %-2.2s", s1, s2, s2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_s_test3) {
  char original[5000];
  char fake[5000];
  int return_number_or;
  int return_number_fk;
  //  (void)setlocale(LC_ALL, "");
  wchar_t s1[500] = L"абракадабра";
  wchar_t s2[500] = L"кадабраабра";
  return_number_or = sprintf(original, "%-ls  %2.2ls %-2.2ls %-2.2ls %2.2ls",
                             s1, s2, s2, s1, s2);
  return_number_fk = s21_sprintf(fake, "%-ls  %2.2ls %-2.2ls %-2.2ls %2.2ls",
                                 s1, s2, s2, s1, s2);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_s_test4) {
  char original[600];
  char fake[600];
  int return_number_or;
  int return_number_fk;
  return_number_or = sprintf(original, "%ls  %20.2ls %-2.20ls %-2.10ls %2.2ls",
                             L"", L"", L"", L"", L"");
  return_number_fk = s21_sprintf(fake, "%ls  %20.2ls %-2.20ls %-2.10ls %2.2ls",
                                 L"", L"", L"", L"", L"");
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_s_test5) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  return_number_or =
      sprintf(original, "%s  %20.2s %-2.20s %-2.20s %2.2s", "", "", "", "", "");
  return_number_fk =
      s21_sprintf(fake, "%s  %20.2s %-2.20s %-2.20s %2.2s", "", "", "", "", "");
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

//  uint
START_TEST(s21_sprintf_u_test0) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  unsigned int u = 50000;
  return_number_or = sprintf(original, "%u", u);
  return_number_fk = s21_sprintf(fake, "%u", u);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_u_test1) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  unsigned int x = 0;
  return_number_or = sprintf(original, "%05u", x);
  return_number_fk = s21_sprintf(fake, "%05u", x);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_u_test2) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  unsigned int x = 10;
  return_number_or = sprintf(original, "%-*.*u", -1, 10, x);
  return_number_fk = s21_sprintf(fake, "%-*.*u", -1, 10, x);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_u_test3) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  unsigned int x = 10;
  return_number_or = sprintf(original, "%-*.*u", 2, 10, x);
  return_number_fk = s21_sprintf(fake, "%-*.*u", 2, 10, x);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_u_test4) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  unsigned int x = 10;
  return_number_or = sprintf(original, "%*.*u", 2, -5, x);
  return_number_fk = s21_sprintf(fake, "%*.*u", 2, -5, x);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_u_test5) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  unsigned int x = 10;
  unsigned int c = -50;
  return_number_or = sprintf(original, "%-*.*u %u ", 2, 5, x, c);
  return_number_fk = s21_sprintf(fake, "%-*.*u %u ", 2, 5, x, c);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_u_test6) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  unsigned short int x = 10;
  unsigned short int c = -50;
  unsigned short int e = 20000;
  return_number_or = sprintf(original, "%-*.*hu %-.2hu  %3hu", 2, 5, x, c, e);
  return_number_fk = s21_sprintf(fake, "%-*.*hu %-.2hu  %3hu", 2, 5, x, c, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_u_test7) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  unsigned long int x = 10;
  unsigned long int c = -50;
  unsigned long int e = 20000;
  return_number_or = sprintf(original, "%-*.*lu %.2lu %013lu", 2, 5, x, c, e);
  return_number_fk = s21_sprintf(fake, "%-*.*lu %.2lu %013lu", 2, 5, x, c, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_u_test8) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  unsigned long int x = 50000000000;
  unsigned long int c = -50000000000;
  unsigned long int e = 122000000000000000;
  return_number_or = sprintf(original, "%-*.*lu %.25lu  %15lu", 2, 5, x, c, e);
  return_number_fk = s21_sprintf(fake, "%-*.*lu %.25lu  %15lu", 2, 5, x, c, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_u_test88) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  unsigned long int x = 50000000000;
  unsigned long int c = -50000000000;
  unsigned long int e = 122000000000000000;
  return_number_or = sprintf(original, "%-*.*lu %.5lu  %0lu", 2, 5, x, c, e);
  return_number_fk = s21_sprintf(fake, "%-*.*lu %.5lu  %0lu", 2, 5, x, c, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_u_test9) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  signed char x = 128;
  signed char c = -128;
  signed char e = 129;
  return_number_or =
      sprintf(original, "%-*.*hhu %.25hhu  %015hhu", 2, 5, x, c, e);
  return_number_fk =
      s21_sprintf(fake, "%-*.*hhu %.25hhu  %015hhu", 2, 5, x, c, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_u_test99) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  signed char x = 128;
  signed char c = -128;
  signed char e = 129;
  return_number_or =
      sprintf(original, "%-*.*hhu %*.3hhu  %1.*hhu", 2, 5, x, 3, c, 3, e);
  return_number_fk =
      s21_sprintf(fake, "%-*.*hhu %*.3hhu  %1.*hhu", 2, 5, x, 3, c, 3, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_u_test10) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  unsigned long long x = 128;
  unsigned long long c = -128;
  unsigned long long e = 129;
  return_number_or =
      sprintf(original, "%-*.*llu %.25llu  %015llu", 2, 5, x, c, e);
  return_number_fk =
      s21_sprintf(fake, "%-*.*llu %.25llu  %015llu", 2, 5, x, c, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_u_test11) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  unsigned long long x = 128;
  unsigned long long c = -128;
  unsigned long long e = 129;
  return_number_or =
      sprintf(original, "%-*.*llu %*.5llu  %5.*llu", 2, 5, x, 3, c, 3, e);
  return_number_fk =
      s21_sprintf(fake, "%-*.*llu %*.5llu  %5.*llu", 2, 5, x, 3, c, 3, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_u_test12) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  unsigned long long z = 0;
  return_number_or = sprintf(original, "%015llu %.5llu  %5llu", z, z, -z);
  return_number_fk = s21_sprintf(fake, "%015llu %.5llu  %5llu", z, z, -z);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_u_test13) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  unsigned int z = 0;
  return_number_or = sprintf(original, "%010u %.5u  %5u", z, z, -z);
  return_number_fk = s21_sprintf(fake, "%010u %.5u  %5u", z, z, -z);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_u_test14) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  unsigned long z = 0;
  return_number_or = sprintf(original, "%013lu %.5lu  %5lu", z, z, -z);
  return_number_fk = s21_sprintf(fake, "%013lu %.5lu  %5lu", z, z, -z);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_u_test15) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  unsigned char z = 0;
  return_number_or = sprintf(original, "%07hu %.5hhu  %5hhu", z, z, -z);
  return_number_fk = s21_sprintf(fake, "%07hu %.5hhu  %5hhu", z, z, -z);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

//  x tests
START_TEST(s21_sprintf_x_test0) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  int X = 50000;
  return_number_or = sprintf(original, "%X", X);
  return_number_fk = s21_sprintf(fake, "%X", X);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

// x test
START_TEST(s21_sprintf_x_test1) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  int x = 0;
  return_number_or = sprintf(original, "%5x", x);
  return_number_fk = s21_sprintf(fake, "%5x", x);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_x_test2) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  int x = 10;
  return_number_or = sprintf(original, "%*.*x", -1, 10, x);
  return_number_fk = s21_sprintf(fake, "%*.*x", -1, 10, x);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_x_test3) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  int x = 10;
  return_number_or = sprintf(original, "%*.*x", 2, 10, x);
  return_number_fk = s21_sprintf(fake, "%*.*x", 2, 10, x);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_x_test4) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  int x = 10;
  return_number_or = sprintf(original, "%*.*x", 2, -5, x);
  return_number_fk = s21_sprintf(fake, "%*.*x", 2, -5, x);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_x_test5) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  int x = 10;
  int c = -50;
  return_number_or = sprintf(original, "%#-*.*x %015x ", 2, 5, x, c);
  return_number_fk = s21_sprintf(fake, "%#-*.*x %015x ", 2, 5, x, c);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_x_test6) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  short int x = 10;
  short int c = -50;
  short int e = 20000;
  return_number_or =
      sprintf(original, "%#-*.*hx %.2hx  %#015hx", 2, 5, x, c, e);
  return_number_fk =
      s21_sprintf(fake, "%#-*.*hx %.2hx  %#015hx", 2, 5, x, c, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_x_test7) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long int x = 10;
  long int c = -50;
  long int e = 200000;
  return_number_or = sprintf(original, "%#-*.*lx %.2lx  %3lx", 2, 5, x, c, e);
  return_number_fk = s21_sprintf(fake, "%#-*.*lx %.2lx  %3lx", 2, 5, x, c, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_x_test8) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long int x = 50000000000;
  long int c = -50000000000;
  long int e = 122000000000000000;
  return_number_or =
      sprintf(original, "%#-*.*lx %.25lx  %#030lx", 2, 5, x, c, e);
  return_number_fk =
      s21_sprintf(fake, "%#-*.*lx %.25lx  %#030lx", 2, 5, x, c, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_x_test9) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  signed char x = 128;
  signed char c = -128;
  signed char e = 129;
  return_number_or =
      sprintf(original, "%#-*.*hhx %.25hhx  %-15hhx", 2, 5, x, c, e);
  return_number_fk =
      s21_sprintf(fake, "%#-*.*hhx %.25hhx  %-15hhx", 2, 5, x, c, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_x_test99) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  signed char x = 128;
  signed char c = -128;
  signed char e = 129;
  return_number_or =
      sprintf(original, "%#-*.*hhx %*.3hhx  %1.*hhx", 2, 5, x, 3, c, 3, e);
  return_number_fk =
      s21_sprintf(fake, "%#-*.*hhx %*.3hhx  %1.*hhx", 2, 5, x, 3, c, 3, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_x_test10) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long long x = 128;
  long long c = -128;
  long long e = 129;
  return_number_or =
      sprintf(original, "%#-*.*llx %.25llx  %015llx", 2, 5, x, c, e);
  return_number_fk =
      s21_sprintf(fake, "%#-*.*llx %.25llx  %015llx", 2, 5, x, c, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_x_test11) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long long x = 128;
  long long c = -128;
  long long e = 129;
  return_number_or =
      sprintf(original, "%#-*.*llx %*.5llx  %5.*llx", 2, 5, x, 3, c, 3, e);
  return_number_fk =
      s21_sprintf(fake, "%#-*.*llx %*.5llx  %5.*llx", 2, 5, x, 3, c, 3, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_x_test12) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  unsigned long long int z = 0;
  return_number_or = sprintf(original, "%#010llx %.5llx  %5llx", z, z, -z);
  return_number_fk = s21_sprintf(fake, "%#010llx %.5llx  %5llx", z, z, -z);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_x_test13) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  unsigned int z = 0;
  return_number_or = sprintf(original, "%7x %.5x  %#07x", z, z, -z);
  return_number_fk = s21_sprintf(fake, "%7x %.5x  %#07x", z, z, -z);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_x_test14) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  unsigned long int z = 0;
  return_number_or = sprintf(original, "%#lx %.5lx hello %0#15lx", z, z, -z);
  return_number_fk = s21_sprintf(fake, "%#lx %.5lx hello %0#15lx", z, z, -z);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_x_test15) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  unsigned char z = 0;
  return_number_or = sprintf(original, "%9hx %.5hhx  %#015hhx", z, z, -z);
  return_number_fk = s21_sprintf(fake, "%9hx %.5hhx  %#015hhx", z, z, -z);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

//  X tests
START_TEST(s21_sprintf_X_test0) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  int X = 50000;
  return_number_or = sprintf(original, "%X", X);
  return_number_fk = s21_sprintf(fake, "%X", X);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_X_test1) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  int x = 0;
  return_number_or = sprintf(original, "%-5X", x);
  return_number_fk = s21_sprintf(fake, "%-5X", x);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_X_test2) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  int x = 10;
  return_number_or = sprintf(original, "%*.*X", -1, 10, x);
  return_number_fk = s21_sprintf(fake, "%*.*X", -1, 10, x);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_X_test3) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  int x = 10;
  return_number_or = sprintf(original, "%*.*X", 2, 10, x);
  return_number_fk = s21_sprintf(fake, "%*.*X", 2, 10, x);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_X_test4) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  int x = 10;
  return_number_or = sprintf(original, "%*.*X", 2, -5, x);
  return_number_fk = s21_sprintf(fake, "%*.*X", 2, -5, x);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_X_test5) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  int x = 10;
  int c = -50;
  return_number_or = sprintf(original, "%#-*.*X %#015X ", 2, 5, x, c);
  return_number_fk = s21_sprintf(fake, "%#-*.*X %#015X ", 2, 5, x, c);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_X_test6) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  short int x = 10;
  short int c = -50;
  short int e = 20000;
  return_number_or = sprintf(original, "%#-*.*hX %.2hX  %010hX", 2, 5, x, c, e);
  return_number_fk = s21_sprintf(fake, "%#-*.*hX %.2hX  %010hX", 2, 5, x, c, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_X_test7) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long int x = 10;
  long int c = -50;
  long int e = 200000;
  return_number_or = sprintf(original, "%#-*.*lX %.2lX  %-3lX", 2, 5, x, c, e);
  return_number_fk = s21_sprintf(fake, "%#-*.*lX %.2lX  %-3lX", 2, 5, x, c, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_X_test8) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long int x = 50000000000;
  long int c = -50000000000;
  long int e = 122000000000000000;
  return_number_or = sprintf(original, "%#-*.*lX %.25lX  %15lX", 2, 5, x, c, e);
  return_number_fk = s21_sprintf(fake, "%#-*.*lX %.25lX  %15lX", 2, 5, x, c, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_X_test9) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  signed char x = 128;
  signed char c = -128;
  signed char e = 129;
  return_number_or =
      sprintf(original, "%#-*.*hhX %.25hhX  %-15hhX", 2, 5, x, c, e);
  return_number_fk =
      s21_sprintf(fake, "%#-*.*hhX %.25hhX  %-15hhX", 2, 5, x, c, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_X_test99) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  signed char x = 128;
  signed char c = -128;
  signed char e = 129;
  return_number_or =
      sprintf(original, "%#-*.*hhX %*.3hhX  %1.*hhX", 2, 5, x, 3, c, 3, e);
  return_number_fk =
      s21_sprintf(fake, "%#-*.*hhX %*.3hhX  %1.*hhX", 2, 5, x, 3, c, 3, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_X_test10) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long long x = 128;
  long long c = -128;
  long long e = 129;
  return_number_or =
      sprintf(original, "%#-*.*llX %.25llX  %015llX", 2, 5, x, c, e);
  return_number_fk =
      s21_sprintf(fake, "%#-*.*llX %.25llX  %015llX", 2, 5, x, c, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_X_test11) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  long long x = 128;
  long long c = -128;
  long long e = 129;
  return_number_or =
      sprintf(original, "%#-*.*llX %*.5llX  %5.*llX", 2, 5, x, 3, c, 3, e);
  return_number_fk =
      s21_sprintf(fake, "%#-*.*llX %*.5llX  %5.*llX", 2, 5, x, 3, c, 3, e);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_X_test12) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  unsigned long long z = 0;
  return_number_or = sprintf(original, "%#llX %.5llX  %#015llX", z, z, -z);
  return_number_fk = s21_sprintf(fake, "%#llX %.5llX  %#015llX", z, z, -z);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_X_test13) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  unsigned int z = 0;
  return_number_or = sprintf(original, "%#X %.5X  %015X", z, z, z);
  return_number_fk = s21_sprintf(fake, "%#X %.5X  %015X", z, z, z);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_X_test14) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  unsigned long z = 0;
  return_number_or = sprintf(original, "%#010lX %.5lX  %15lX", z, z, z);
  return_number_fk = s21_sprintf(fake, "%#010lX %.5lX  %15lX", z, z, z);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_X_test15) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  unsigned char z = 0;
  return_number_or = sprintf(original, "%#020hX %.5hhX  %15hhX", z, z, z);
  return_number_fk = s21_sprintf(fake, "%#020hX %.5hhX  %15hhX", z, z, z);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

// p tests
START_TEST(s21_sprintf_p_test0) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  int a = 10;
  double b = 11.11;
  float r = -123.0;
  return_number_or = sprintf(original, "%p %15p %-p", &a, &b, &r);
  return_number_fk = s21_sprintf(fake, "%p %15p %-p", &a, &b, &r);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_p_test1) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  int a = 10;
  double b = 11.11;
  float r = -123.0;
  return_number_or = sprintf(original, "%1p %-15p %-1p", &a, &b, &r);
  return_number_fk = s21_sprintf(fake, "%1p %-15p %-1p", &a, &b, &r);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_p_test2) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  int a = 10;
  double b = 11.11;
  float r = -123.0;
  return_number_or = sprintf(original, "%1p %-1p %-15p", &a, &b, &r);
  return_number_fk = s21_sprintf(fake, "%1p %-1p %-15p", &a, &b, &r);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_p_test3) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  int a = 10;
  double b = 11.11;
  float r = -123.0;
  return_number_or = sprintf(original, "%-13p %-1p %-1p", &a, &b, &r);
  return_number_fk = s21_sprintf(fake, "%-13p %-1p %-1p", &a, &b, &r);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_p_test4) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  return_number_or =
      sprintf(original, "%10p %-1p %-15p", s21_NULL, s21_NULL, s21_NULL);
  return_number_fk =
      s21_sprintf(fake, "%10p %-1p %-15p", s21_NULL, s21_NULL, s21_NULL);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

// n tests
START_TEST(s21_sprintf_n_test0) {
  char original[500];
  char fake[500];
  int number_original;
  int number_fake;
  int return_number_or;
  int return_number_fk;
  return_number_or =
      sprintf(original, "%%0123\r\n\t\aabv%ngb\"\'", &number_original);
  return_number_fk =
      s21_sprintf(fake, "%%0123\r\n\t\aabv%ngb\"\'", &number_fake);
  ck_assert_int_eq(number_original, number_fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
  ck_assert_str_eq(original, fake);
}
END_TEST

START_TEST(s21_sprintf_n_test1) {
  char original[500];
  char fake[500];
  int number_original;
  int number_fake;
  int return_number_or;
  int return_number_fk;
  return_number_or =
      sprintf(original, "%%0123\r\n\t\aabv%ngb\"\'", &number_original);
  return_number_fk =
      s21_sprintf(fake, "%%0123\r\n\t\aabv%ngb\"\'", &number_fake);
  ck_assert_int_eq(number_original, number_fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
  ck_assert_str_eq(original, fake);
}
END_TEST

//  mixed tests
START_TEST(s21_sprintf_mixed_test0) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  int d = 100500;
  int X = 0x16;
  short int ho = 01256;
  char s[100] = "Test";
  return_number_or = sprintf(original, "%d, %X123%%%ho%.2s,", d, X, ho, s);
  return_number_fk = s21_sprintf(fake, "%d, %X123%%%ho%.2s,", d, X, ho, s);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
}
END_TEST

START_TEST(s21_sprintf_mixed_test1) {
  char original[500];
  char fake[500];
  int return_number_or;
  int return_number_fk;
  int n_orig, n_fake;
  long double g3 = -25555555555555555555.123456;
  float f = 12.312123;
  char c = '\t';
  unsigned int u = -10;
  return_number_or =
      sprintf(original, "%LG %n %.5f %% %%%c %u", g3, &n_orig, f, c, u);
  return_number_fk =
      s21_sprintf(fake, "%LG %n %.5f %% %%%c %u", g3, &n_fake, f, c, u);
  ck_assert_str_eq(original, fake);
  ck_assert_int_eq(return_number_or, return_number_fk);
  ck_assert_int_eq(n_orig, n_fake);
}
END_TEST

START_TEST(g_many) {
  char str1[500];
  char str2[500];
  char format[] = "%LG %g %G %Lg %.5g";
  long double hex = 0.000005;
  double hex1 = 41.1341;
  double hex2 = 848.9000;
  long double hex3 = 0.0843;
  double hex4 = 0.0005;
  double hex5 = 0.8481481;
  ck_assert_int_eq(s21_sprintf(str1, format, hex, hex1, hex2, hex3, hex4, hex5),
                   sprintf(str2, format, hex, hex1, hex2, hex3, hex4, hex5));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(g_zero) {
  char str1[500];
  char str2[500];
  char format[] = "%.5g";
  double hex = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(c_many_lengths) {
  char str1[500];
  char str2[500];
  int n1, n2;
  char format[15][500];
  strcpy(format[0], "%c");
  strcpy(format[1], "%  c");
  strcpy(format[2], "%  lc");
  strcpy(format[3], "%  llc");
  strcpy(format[4], "%   llllc");
  strcpy(format[5], "%  lc");
  strcpy(format[6], "%  hc");
  strcpy(format[7], "%  hc");
  strcpy(format[8], "%  hhc");
  strcpy(format[9], "%    hhhc");
  strcpy(format[10], "%Lc");
  strcpy(format[11], "%LLc");
  strcpy(format[12], "%  Lc");
  strcpy(format[13], "%  LLc");
  strcpy(format[14], "%   LLLLc");
  for (int i = 0; i < 14; i++) {
    n1 = s21_sprintf(str1, format[i], 49);
    n2 = sprintf(str2, format[i], 49);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(n1, n2);
  }
}
END_TEST

START_TEST(d_many_lengths) {
  char str1[500];
  char str2[500];
  int n1, n2;
  char format[12][500];
  strcpy(format[0], "%  d");
  strcpy(format[1], "%  d");
  strcpy(format[2], "%  ld");
  strcpy(format[3], "%  lld");
  strcpy(format[4], "%  llld");
  strcpy(format[5], "%  lllld");
  strcpy(format[6], "%  Ld");
  strcpy(format[7], "%  LLd");
  strcpy(format[8], "% Ld");
  strcpy(format[9], "%   LLLLd");
  strcpy(format[10], "%  hhhd");
  strcpy(format[11], "%  hhd");
  for (int i = 0; i < 12; i++) {
    n1 = s21_sprintf(str1, format[i], 48);
    n2 = sprintf(str2, format[i], 48);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(n1, n2);
  }
}
END_TEST

START_TEST(e_many_lengths) {
  char str1[500];
  char str2[500];
  int n1, n2;
  char format[10][500];
  strcpy(format[0], "%   e");
  strcpy(format[1], "%  he");
  strcpy(format[2], "%  hhe");
  strcpy(format[3], "%  hhhhe");
  strcpy(format[4], "%  le");
  strcpy(format[5], "%  lle");
  strcpy(format[6], "%  lllle");
  strcpy(format[7], "%  Le");
  strcpy(format[8], "%  LLe");
  strcpy(format[9], "%  LLLLe");
  for (int i = 0; i < 10; i++) {
    n1 = s21_sprintf(str1, format[i], 19., (long double)51.);
    n2 = sprintf(str2, format[i], 19., (long double)51.);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(n1, n2);
  }
}
END_TEST

START_TEST(f_many_lengths) {
  char str1[500];
  char str2[500];
  int n1, n2;
  char format[10][500];
  strcpy(format[0], "%  f");
  strcpy(format[1], "%   hf");
  strcpy(format[2], "%   hhf");
  strcpy(format[3], "%   hhhf");
  strcpy(format[4], "%   lf");
  strcpy(format[5], "%   llf");
  strcpy(format[6], "%  llllf");
  strcpy(format[7], "%  Lf");
  strcpy(format[8], "%   LLf");
  strcpy(format[9], "%   LLLLf");
  for (int i = 0; i < 10; i++) {
    n1 = s21_sprintf(str1, format[i], 27., (long double)53.);
    n2 = sprintf(str2, format[i], 27., (long double)53.);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(n1, n2);
  }
}
END_TEST

START_TEST(g_many_lengths) {
  char str1[500];
  char str2[500];
  int n1, n2;
  char format[11][500];
  strcpy(format[0], "%  g");
  strcpy(format[1], "%  hg");
  strcpy(format[2], "%  hhg");
  strcpy(format[3], "%  hhhhg");
  strcpy(format[4], "%  lg");
  strcpy(format[5], "%  llg");
  strcpy(format[6], "%   lllg");
  strcpy(format[7], "%   lllllg");
  strcpy(format[8], "%  Lg");
  strcpy(format[9], "%  LLg");
  strcpy(format[10], "%  LLLLg");
  for (int i = 0; i < 11; i++) {
    n1 = s21_sprintf(str1, format[i], 31., (long double)55.);
    n2 = sprintf(str2, format[i], 31., (long double)55.);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(n1, n2);
  }
}
END_TEST

START_TEST(o_many_lengths) {
  char str1[500];
  char str2[500];
  int n1, n2;
  char format[11][500];
  strcpy(format[0], "%  o");
  strcpy(format[1], "%  ho");
  strcpy(format[2], "%  hho");
  strcpy(format[3], "%  hhhho");
  strcpy(format[4], "%  lo");
  strcpy(format[5], "%  llo");
  strcpy(format[6], "%  lllo");
  strcpy(format[7], "%  lllllo");
  strcpy(format[8], "%  Lo");
  strcpy(format[9], "%  LLo");
  strcpy(format[10], "%  LLLLLo");
  for (int i = 0; i < 11; i++) {
    n1 = s21_sprintf(str1, format[i], 52);
    n2 = sprintf(str2, format[i], 52);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(n1, n2);
  }
}
END_TEST

START_TEST(s_many_lengths) {
  char str1[500];
  char str2[500];
  int n1, n2;
  char format[12][500];
  strcpy(format[0], "%  s");
  strcpy(format[1], "%  hs");
  strcpy(format[2], "%  hhs");
  strcpy(format[3], "%  hhhs");
  strcpy(format[4], "%  hhhhs");
  strcpy(format[5], "%   LLLLs");
  strcpy(format[6], "%  lls");
  strcpy(format[7], "%  llls");
  strcpy(format[8], "%  llllls");
  strcpy(format[9], "%   Ls");
  strcpy(format[10], "%   LLs");
  strcpy(format[11], "%  ls");
  for (int i = 0; i < 12; i++) {
    n1 = s21_sprintf(str1, format[i], L"hello");
    n2 = sprintf(str2, format[i], L"hello");
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(n1, n2);
  }
}
END_TEST

START_TEST(u_many_lengths) {
  char str1[500];
  char str2[500];
  int n1, n2;
  char format[13][500];
  strcpy(format[0], "%u");
  strcpy(format[1], "%  hu");
  strcpy(format[2], "%  hhu");
  strcpy(format[3], "%  hhhu");
  strcpy(format[4], "%  hhhhhu");
  strcpy(format[5], "%  lu");
  strcpy(format[6], "%  llu");
  strcpy(format[7], "%  lllu");
  strcpy(format[8], "%  lllllu");
  strcpy(format[9], "%  Lu");
  strcpy(format[10], "%  LLu");
  strcpy(format[11], "%  LLLu");
  strcpy(format[12], "%  LLLLLu");
  for (int i = 0; i < 13; i++) {
    n1 = s21_sprintf(str1, format[i], 54);
    n2 = sprintf(str2, format[i], 54);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(n1, n2);
  }
}
END_TEST

START_TEST(x_many_lengths) {
  char str1[500];
  char str2[500];
  int n1, n2;
  char format[11][500];
  strcpy(format[0], "%  x");
  strcpy(format[1], "%  hx");
  strcpy(format[2], "%  hhx");
  strcpy(format[3], "%  hhhx");
  strcpy(format[4], "%   hhhhx");
  strcpy(format[5], "%  lx");
  strcpy(format[6], "%  llx");
  strcpy(format[7], "%   llllx");
  strcpy(format[8], "%   Lx");
  strcpy(format[9], "%  LLx");
  strcpy(format[10], "%   LLLLx");
  for (int i = 0; i < 11; i++) {
    n1 = s21_sprintf(str1, format[i], 56);
    n2 = sprintf(str2, format[i], 56);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(n1, n2);
  }
}
END_TEST

START_TEST(p_many_lengths) {
  char str1[500];
  char str2[500];
  int n1, n2;
  char format[11][500];
  strcpy(format[0], "%  p");
  strcpy(format[1], "%  hp");
  strcpy(format[2], "%  hhp");
  strcpy(format[3], "%  hhhp");
  strcpy(format[4], "%   hhhhhp");
  strcpy(format[5], "%  lp");
  strcpy(format[6], "%  llp");
  strcpy(format[7], "%   llllp");
  strcpy(format[8], "%   Lp");
  strcpy(format[9], "%  LLp");
  strcpy(format[10], "%  LLLLp");
  for (int i = 0; i < 11; i++) {
    n1 = s21_sprintf(str1, format[i], 58);
    n2 = sprintf(str2, format[i], 58);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(n1, n2);
  }
}
END_TEST

START_TEST(percent_many_lengths) {
  char str1[500];
  char str2[500];
  int n1, n2;
  char format[12][500];
  strcpy(format[0], "%  %");
  strcpy(format[1], "%  h%");
  strcpy(format[2], "%  hh%");
  strcpy(format[3], "%  hhhh%");
  strcpy(format[4], "%  l%");
  strcpy(format[5], "%  ll%");
  strcpy(format[6], "%   llll %");
  strcpy(format[7], "%   lllld%");
  strcpy(format[8], "% L%");
  strcpy(format[9], "%  LL%");
  strcpy(format[10], "%   LLL%");
  strcpy(format[11], "%   LLLLL%");
  for (int i = 0; i < 12; i++) {
    n1 = s21_sprintf(str1, format[i], 48);
    n2 = sprintf(str2, format[i], 48);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(n1, n2);
  }
}
END_TEST

START_TEST(s_s21_null) {
  char str1[500];
  char str2[500];
  int n1, n2;
  char format[10] = "%s";
  n1 = s21_sprintf(str1, format, s21_NULL);
  n2 = sprintf(str2, format, s21_NULL);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
  s21_strcpy(format, "%.4s");
  n1 = s21_sprintf(str1, format, s21_NULL);
  n2 = sprintf(str2, format, s21_NULL);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(wcs_s21_null) {
  char str1[500];
  char str2[500];
  int n1, n2;
  char format[10] = "%ls";
  n1 = s21_sprintf(str1, format, s21_NULL);
  n2 = sprintf(str2, format, s21_NULL);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
  s21_strcpy(format, "%.5ls");
  n1 = s21_sprintf(str1, format, s21_NULL);
  n2 = sprintf(str2, format, s21_NULL);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(percent_final) {
  char str1[500];
  char str2[500];
  int n1, n2;
  char format[10] = "lsdalfj% ";
  n1 = s21_sprintf(str1, format, 25);
  n2 = sprintf(str2, format, 25);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST
//  ++++++++++++++++++++++++++++++++++++++++

//  ++++++++++++++++++++++S+S+C+A+N+F+++++++

START_TEST(s21_sscanf_c_test0) {
  char c_original = 0;
  char c_fake = 0;
  char str[500] = "12345 test";
  char str2[500] = "12345 test";
  int n_org = sscanf(str, "%*2c%2c", &c_original);
  int n_fke = s21_sscanf(str2, "%*2c%2c", &c_fake);
  ck_assert_int_eq(c_original, c_fake);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_c_test1) {
  char c_original = 0;
  char c_fake = 0;
  char str[500] = "12345 test";
  char str2[500] = "12345 test";
  int n_org = sscanf(str, "tess%c", &c_original);
  int n_fke = s21_sscanf(str2, "tess%c", &c_fake);
  ck_assert_int_eq(c_original, c_fake);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_c_test2) {
  char c_original;
  char c_fake;
  char str[500] = "12345 test";
  char str2[500] = "12345 test";
  int n_org = sscanf(str, "12345 %c", &c_original);
  int n_fke = s21_sscanf(str2, "12345 %c", &c_fake);
  ck_assert_int_eq(c_original, c_fake);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_c_test3) {
  char c_original;
  char c_fake;
  char str[500] = "12345 test";
  char str2[500] = "12345 test";
  int n_org = sscanf(str, "1 %c", &c_original);
  int n_fke = s21_sscanf(str2, "1 %c", &c_fake);
  ck_assert_int_eq(c_original, c_fake);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_c_test4) {
  char c_original;
  char c_fake;
  char str[500] = "-test 12345";
  char str2[500] = "-test 12345";
  int n_org = sscanf(str, "- %c", &c_original);
  int n_fke = s21_sscanf(str2, "- %c", &c_fake);
  ck_assert_int_eq(c_original, c_fake);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_c_test5) {
  char c_original;
  char c_fake;
  char str[500] = "-test 12345";
  char str2[500] = "-test 12345";
  int n_org = sscanf(str, "%c", &c_original);
  int n_fke = s21_sscanf(str2, "%c", &c_fake);
  ck_assert_int_eq(c_original, c_fake);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_c_test6) {
  char c_original;
  char c_fake;
  char c_original2;
  char c_fake2;
  char str[500] = "-test 12345";
  char str2[500] = "-test 12345";
  int n_org = sscanf(str, "-%c s%c", &c_original, &c_original2);
  int n_fke = s21_sscanf(str2, "-%c s%c", &c_fake, &c_fake2);
  ck_assert_int_eq(c_original, c_fake);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

// d
START_TEST(s21_sscanf_d_test0) {
  int c_original = 0;
  int c_fake = 0;
  char str[500] = "-test 12345";
  char str2[500] = "-test 12345";
  int n_org = sscanf(str, "%d", &c_original);
  int n_fke = s21_sscanf(str2, "%d", &c_fake);
  ck_assert_int_eq(c_original, c_fake);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_d_test1) {
  int c_original = 0;
  int c_fake = 0;
  char str[500] = "-test 12345";
  char str2[500] = "-test 12345";
  int n_org = sscanf(str, "-%d", &c_original);
  int n_fke = s21_sscanf(str2, "-%d", &c_fake);
  ck_assert_int_eq(c_original, c_fake);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_d_test2) {
  int c_original;
  int c_fake;
  char str[500] = "-test 12345";
  char str2[500] = "-test 12345";
  int n_org = sscanf(str, "-test%d", &c_original);
  int n_fke = s21_sscanf(str2, "-test%d", &c_fake);
  ck_assert_int_eq(c_original, c_fake);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_d_test3) {
  int c_original;
  int c_fake;
  char str[500] = "-test 12345";
  char str2[500] = "-test 12345";
  int n_org = sscanf(str, "-test%2d", &c_original);
  int n_fke = s21_sscanf(str2, "-test%2d", &c_fake);
  ck_assert_int_eq(c_original, c_fake);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_d_test4) {
  long int c_original;
  long int c_fake;
  char str[500] = "-test 12345";
  char str2[500] = "-test 12345";
  int n_org = sscanf(str, "-test%2ld", &c_original);
  int n_fke = s21_sscanf(str2, "-test%2ld", &c_fake);
  ck_assert_int_eq(c_original, c_fake);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_d_test5) {
  long int c_original;
  long int c_fake;
  char str[500] = "-1928479 8172 48.981427";
  char str2[500] = "-1928479 8172 48.981427";
  unsigned char c1, c1_;
  long long int c2, c2_;
  int n_org = sscanf(str, "%2ld%hhd%lld", &c_original, &c1, &c2);
  int n_fke = s21_sscanf(str2, "%2ld%hhd%lld", &c_fake, &c1_, &c2_);
  ck_assert_int_eq(c_original, c_fake);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_d_test6) {
  short int c_original;
  short int c_fake;
  char str[500] = "-1928479817248.981427";
  char str2[500] = "-1928479817248.981427";
  int n_org = sscanf(str, "%10hd", &c_original);
  int n_fke = s21_sscanf(str2, "%10hd", &c_fake);
  ck_assert_int_eq(c_original, c_fake);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_d_test7) {
  short int c_original;
  short int c_fake;
  char str[500] = "-%19284--79[[--817248.981427";
  char str2[500] = "-%19284--79[[--817248.981427";
  int n_org = sscanf(str, "-%%%10hd", &c_original);
  int n_fke = s21_sscanf(str2, "-%%%10hd", &c_fake);
  ck_assert_int_eq(c_original, c_fake);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_d_test8) {
  int c_original = 0;
  int c_fake = 0;
  int c_original2 = 0;
  int c_fake2 = 0;
  char str[500] = "-19284--79[[--817248.981427";
  char str2[500] = "-19284--79[[--817248.981427";
  int n_org = sscanf(str, "-%10d %d", &c_original, &c_original2);
  int n_fke = s21_sscanf(str2, "-%10d %d", &c_fake, &c_fake2);
  ck_assert_int_eq(c_original, c_fake);
  ck_assert_int_eq(c_original2, c_fake2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_d_test9) {
  int c_original = 0;
  int c_fake = 0;
  int c_original2 = 0;
  int c_fake2 = 0;
  int c_original3 = 0;
  int c_fake3 = 0;
  char str[500] = "-19284--79[[--817248.981427";
  char str2[500] = "-19284--79[[--817248.981427";
  int n_org =
      sscanf(str, "-%10d %d %2d", &c_original, &c_original2, &c_original3);
  int n_fke = s21_sscanf(str2, "-%10d %d %2d", &c_fake, &c_fake3, &c_fake3);
  ck_assert_int_eq(c_original, c_fake);
  ck_assert_int_eq(c_original2, c_fake2);
  ck_assert_int_eq(c_original3, c_fake3);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

// i tests
START_TEST(s21_sscanf_i_test0) {
  int i_org = 0;
  int i_fke = 0;
  char str[500] = "-123124";
  char str2[500] = "-123124";
  int n_org = sscanf(str, "%i", &i_org);
  int n_fke = s21_sscanf(str2, "%i", &i_fke);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_int_eq(i_org, i_fke);
}
END_TEST

START_TEST(s21_sscanf_i_test1) {
  int i_org = 0;
  int i_fke = 0;
  int i_org2 = 0;
  int i_fke2 = 0;
  char str[500] = "-123124 0xffe";
  char str2[500] = "-123124 0xffe";
  int n_org = sscanf(str, "-%i %i", &i_org, &i_org2);
  int n_fke = s21_sscanf(str2, "-%i %i", &i_fke, &i_fke2);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_int_eq(i_org, i_fke);
  ck_assert_int_eq(i_org2, i_fke2);
}
END_TEST

START_TEST(s21_sscanf_i_test2) {
  int i_org = 0;
  int i_fke = 0;
  int i_org2 = 0;
  int i_fke2 = 0;
  char str[500] = "05524 0xFFE";
  char str2[500] = "05524 0xFFE";
  int n_org = sscanf(str, "%i%i", &i_org, &i_org2);
  int n_fke = s21_sscanf(str2, "%i%i", &i_fke, &i_fke2);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_int_eq(i_org, i_fke);
  ck_assert_int_eq(i_org2, i_fke2);
}
END_TEST

START_TEST(s21_sscanf_i_test3) {
  int i_org = 0;
  int i_fke = 0;
  int i_org2 = 0;
  int i_fke2 = 0;
  char str[500] = "-05524 \t -FFE";
  char str2[500] = "-05524 \t -FFE";
  int n_org = sscanf(str, "%7i%i", &i_org, &i_org2);
  int n_fke = s21_sscanf(str2, "%7i%i", &i_fke, &i_fke2);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_int_eq(i_org, i_fke);
  ck_assert_int_eq(i_org2, i_fke2);
}
END_TEST

START_TEST(s21_sscanf_i_test4) {
  int i_org = 0;
  int i_fke = 0;
  int i_org2 = 0;
  int i_fke2 = 0;
  char str[500] = "-05524 asdasd-FFE";
  char str2[500] = "-05524 asdasd-FFE";
  int n_org = sscanf(str, "%3i%i", &i_org, &i_org2);
  int n_fke = s21_sscanf(str2, "%3i%i", &i_fke, &i_fke2);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_int_eq(i_org, i_fke);
  ck_assert_int_eq(i_org2, i_fke2);
}
END_TEST

START_TEST(s21_sscanf_i_test5) {
  int i_org = 0;
  int i_fke = 0;
  int i_org2 = 0;
  int i_fke2 = 0;
  char str[500] = "55=24 \n-FFE";
  char str2[500] = "55=24 \n-FFE";
  int n_org = sscanf(str, "%i%i", &i_org, &i_org2);
  int n_fke = s21_sscanf(str2, "%i%i", &i_fke, &i_fke2);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_int_eq(i_org, i_fke);
  ck_assert_int_eq(i_org2, i_fke2);
}
END_TEST

START_TEST(s21_sscanf_i_test6) {
  int i_org = 0;
  int i_fke = 0;
  int i_org2 = 0;
  int i_fke2 = 0;
  char str[500] = "55FF=E";
  char str2[500] = "55FF=E";
  int n_org = sscanf(str, "%i%1i", &i_org, &i_org2);
  int n_fke = s21_sscanf(str2, "%i%1i", &i_fke, &i_fke2);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_int_eq(i_org, i_fke);
  ck_assert_int_eq(i_org2, i_fke2);
}
END_TEST

START_TEST(s21_sscanf_i_test7) {
  int i_org = 0;
  int i_fke = 0;
  int i_org2 = 0;
  int i_fke2 = 0;
  char str[500] = "0789FFE";
  char str2[500] = "0789FFE";
  int n_org = sscanf(str, "%i%i", &i_org, &i_org2);
  int n_fke = s21_sscanf(str2, "%i%i", &i_fke, &i_fke2);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_int_eq(i_org, i_fke);
  ck_assert_int_eq(i_org2, i_fke2);
}
END_TEST

START_TEST(s21_sscanf_i_test8) {
  int i_org = 0;
  int i_fke = 0;
  int i_org2 = 0;
  int i_fke2 = 0;
  char str[500] = "FFE0679";
  char str2[500] = "FFE0679";
  int n_org = sscanf(str, "%2i%4i", &i_org, &i_org2);
  int n_fke = s21_sscanf(str2, "%2i%4i", &i_fke, &i_fke2);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_int_eq(i_org, i_fke);
  ck_assert_int_eq(i_org2, i_fke2);
}
END_TEST

START_TEST(s21_sscanf_i_test88) {
  long int i_org = 0;
  long int i_fke = 0;
  short int i_org2 = 0;
  short int i_fke2 = 0;
  char str[500] = "FFE0679";
  char str2[500] = "FFE0679";
  int n_org = sscanf(str, "%li%hi", &i_org, &i_org2);
  int n_fke = s21_sscanf(str2, "%li%hi", &i_fke, &i_fke2);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_int_eq(i_org, i_fke);
  ck_assert_int_eq(i_org2, i_fke2);
}
END_TEST

START_TEST(s21_sscanf_i_test9) {
  long int i_org = 0;
  long int i_fke = 0;
  short int i_org2 = 0;
  short int i_fke2 = 0;
  char str[500] = "FFEF0679";
  char str2[500] = "FFEF0679";
  int n_org = sscanf(str, "F%li%2hi", &i_org, &i_org2);
  int n_fke = s21_sscanf(str2, "F%li%2hi", &i_fke, &i_fke2);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_int_eq(i_org, i_fke);
  ck_assert_int_eq(i_org2, i_fke2);
}
END_TEST

START_TEST(s21_sscanf_i_test10) {
  long int i_org = 0;
  long int i_fke = 0;
  short int i_org2 = 0;
  short int i_fke2 = 0;
  char str[500] = "FFEF0679";
  char str2[500] = "FFEF0679";
  int n_org = sscanf(str, "FFEF%li%2hi", &i_org, &i_org2);
  int n_fke = s21_sscanf(str2, "FFEF%li%2hi", &i_fke, &i_fke2);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_int_eq(i_org, i_fke);
  ck_assert_int_eq(i_org2, i_fke2);
}
END_TEST

// e tests
START_TEST(s21_sscanf_e_test0) {
  float e_org = 0.;
  float e_fke = 0.;
  float e_org2 = 0.;
  float e_fke2 = 0.;
  float e_org3 = 0.;
  float e_fke3 = 0.;
  float e_org4 = 0.;
  float e_fke4 = 0.;
  char str[500] = "1.1e-2 1.1e+002 1.1e+ d";
  char str2[500] = "1.1e-2 1.1e+002 1.1e+ d";
  int n_org = sscanf(str, "%e %e %e %e", &e_org, &e_org2, &e_org3, &e_org4);
  int n_fke =
      s21_sscanf(str2, "%e %e %e %e", &e_fke, &e_fke2, &e_fke3, &e_fke4);
  ck_assert_float_eq(e_org, e_fke);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_double_eq(e_org3, e_fke3);
  ck_assert_double_eq(e_org4, e_fke4);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_e_test1) {
  float e_org = 0;
  float e_fke = 0;
  double e_org2 = 0;
  double e_fke2 = 0;
  char str[500] = "1.1111111 3123123.22212125";
  char str2[500] = "1.1111111 3123123.22212125";
  int n_org = sscanf(str, "%e %le", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "%e %le", &e_fke, &e_fke2);
  ck_assert_float_eq(e_org, e_fke);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_e_test2) {
  float e_org = 0;
  float e_fke = 0;
  double e_org2 = 0;
  double e_fke2 = 0;
  char str[500] = "-1.1111111 +3.22212125";
  char str2[500] = "-1.1111111 +3.22212125";
  int n_org = sscanf(str, "%e %le", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "%e %le", &e_fke, &e_fke2);
  ck_assert_float_eq(e_org, e_fke);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_e_test3) {
  float e_org = 0;
  float e_fke = 0;
  double e_org2 = 0;
  double e_fke2 = 0;
  char str[500] = "-1.1111111 -3.22212125";
  char str2[500] = "-1.1111111 -3.22212125";
  int n_org = sscanf(str, "%3e %17le", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "%3e %17le", &e_fke, &e_fke2);
  ck_assert_float_eq(e_org, e_fke);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_e_test4) {
  float e_org = 0;
  float e_fke = 0;
  double e_org2 = 0;
  double e_fke2 = 0;
  char str[500] = "-0.1111111 -3444.22212125";
  char str2[500] = "-0.1111111 -3444.22212125";
  int n_org = sscanf(str, "%1e %3le", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "%1e %31le", &e_fke, &e_fke2);
  ck_assert_float_eq(e_org, e_fke);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_e_test5) {
  float e_org = 0;
  float e_fke = 0;
  double e_org2 = 0;
  double e_fke2 = 0;
  char str[500] = "0.1111111 3444.22212125";
  char str2[500] = "0.1111111 3444.22212125";
  int n_org = sscanf(str, "%1e %4le", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "%1e %4le", &e_fke, &e_fke2);
  ck_assert_float_eq(e_org, e_fke);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_e_test6) {
  long double e_org = 0;
  long double e_fke = 0;
  long double e_org2 = 0;
  long double e_fke2 = 0;
  char str[500] = "-111111110.1111111 -3444.22212125";
  char str2[500] = "-111111110.1111111 -3444.22212125";
  int n_org = sscanf(str, "%12Le %1Le", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "%12Le %1Le", &e_fke, &e_fke2);
  ck_assert_ldouble_eq(e_org, e_fke);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_e_test7) {
  long double e_org = 0;
  long double e_fke = 0;
  long double e_org2 = 0;
  long double e_fke2 = 0;
  char str[500] = "111111110.1111111 -3444.22212125";
  char str2[500] = "111111110.1111111 -3444.22212125";
  int n_org = sscanf(str, "%22Le %1Le", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "%22Le %1Le", &e_fke, &e_fke2);
  ck_assert_ldouble_eq(e_org, e_fke);
  ck_assert_ldouble_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_e_test8) {
  long double e_org = 0;
  long double e_fke = 0;
  long double e_org2 = 0;
  long double e_fke2 = 0;
  char str[500] = "111111110.1111111 -3444.22212125";
  char str2[500] = "111111110.1111111 -3444.22212125";
  int n_org = sscanf(str, "%100Le %1Le", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "%100Le %1Le", &e_fke, &e_fke2);
  ck_assert_ldouble_eq(e_org, e_fke);
  ck_assert_ldouble_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_e_test9) {
  long double e_org = 0;
  long double e_fke = 0;
  long double e_org2 = 0;
  long double e_fke2 = 0;
  char str[500] = "111111110.1111111 -0.222155552125";
  char str2[500] = "111111110.1111111 -0.222155552125";
  int n_org = sscanf(str, "%1Le %1Le", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "%1Le %1Le", &e_fke, &e_fke2);
  ck_assert_ldouble_eq(e_org, e_fke);
  ck_assert_ldouble_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

// E

START_TEST(s21_sscanf_E_test0) {
  float e_org = 0;
  float e_fke = 0;
  double e_org2 = 0;
  double e_fke2 = 0;
  char str[500] = "1.1 3.2";
  char str2[500] = "1.1 3.2";
  int n_org = sscanf(str, "%E %lE", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "%E %lE", &e_fke, &e_fke2);
  ck_assert_float_eq(e_org, e_fke);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_E_test1) {
  float e_org = 0;
  float e_fke = 0;
  double e_org2 = 0;
  double e_fke2 = 0;
  char str[500] = "1.1111111 3.22212125";
  char str2[500] = "1.1111111 3.22212125";
  int n_org = sscanf(str, "%E %lE", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "%E %lE", &e_fke, &e_fke2);
  ck_assert_float_eq(e_org, e_fke);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_E_test2) {
  float e_org = 0;
  float e_fke = 0;
  double e_org2 = 0;
  double e_fke2 = 0;
  char str[500] = "-1.1111111 -3.22212125";
  char str2[500] = "-1.1111111 -3.22212125";
  int n_org = sscanf(str, "%E %lE", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "%E %lE", &e_fke, &e_fke2);
  ck_assert_float_eq(e_org, e_fke);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_E_test3) {
  float e_org = 0;
  float e_fke = 0;
  double e_org2 = 0;
  double e_fke2 = 0;
  char str[500] = "-1.1111111 -3.22212125";
  char str2[500] = "-1.1111111 -3.22212125";
  int n_org = sscanf(str, "%3E %17lE", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "%3E %17lE", &e_fke, &e_fke2);
  ck_assert_float_eq(e_org, e_fke);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_E_test4) {
  float e_org = 0;
  float e_fke = 0;
  double e_org2 = 0;
  double e_fke2 = 0;
  char str[500] = "-0.1111111 -3444.22212125";
  char str2[500] = "-0.1111111 -3444.22212125";
  int n_org = sscanf(str, "%1E %5lE", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "%1E %5lE", &e_fke, &e_fke2);
  ck_assert_float_eq(e_org, e_fke);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_E_test5) {
  float e_org = 0;
  float e_fke = 0;
  double e_org2 = 0;
  double e_fke2 = 0;
  char str[500] = "0.1111111 3444.22212125";
  char str2[500] = "0.1111111 3444.22212125";
  int n_org = sscanf(str, "%1E %1lE", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "%1E %1lE", &e_fke, &e_fke2);
  ck_assert_float_eq(e_org, e_fke);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_E_test6) {
  long double e_org = 0;
  long double e_fke = 0;
  double e_org2 = 0;
  double e_fke2 = 0;
  char str[500] = "-111111110.1111111 -3444.22212125";
  char str2[500] = "-111111110.1111111 -3444.22212125";
  int n_org = sscanf(str, "-%12LE %1lE", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "-%12LE %1lE", &e_fke, &e_fke2);
  ck_assert_ldouble_eq(e_org, e_fke);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_E_test7) {
  long double e_org = 0;
  long double e_fke = 0;
  double e_org2 = 0;
  double e_fke2 = 0;
  char str[500] = "111111120.1111111 -3444.22212125";
  char str2[500] = "111111120.1111111 -3444.22212125";
  int n_org = sscanf(str, "11%22LE %1lE", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "11%22LE %1lE", &e_fke, &e_fke2);
  ck_assert_ldouble_lt(fabsl(e_org - e_fke), 1e-6);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_E_test8) {
  long double e_org = 0;
  long double e_fke = 0;
  double e_org2 = 0;
  double e_fke2 = 0;
  char str[500] = "111111110.1111111 -3444.22212125";
  char str2[500] = "111111110.1111111 -3444.22212125";
  int n_org = sscanf(str, "111%100LE %1lE", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "111%100LE %1lE", &e_fke, &e_fke2);
  ck_assert_ldouble_eq(e_org, e_fke);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_E_test9) {
  long double e_org = 0;
  long double e_fke = 0;
  double e_org2 = 0;
  double e_fke2 = 0;
  char str[500] = "111111110.1111111 -0.222155552125";
  char str2[500] = "111111110.1111111 -0.222155552125";
  int n_org = sscanf(str, "11%1LE %1lE", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "11%1LE %1lE", &e_fke, &e_fke2);
  ck_assert_ldouble_eq(e_org, e_fke);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

// f
START_TEST(s21_sscanf_f_test0) {
  float f_org = 0;
  float f_fke = 0;
  double f_org2 = 0;
  double f_fke2 = 0;
  char str[500] = "1.1 3.2";
  char str2[500] = "1.1 3.2";
  int n_org = sscanf(str, "%f %lf", &f_org, &f_org2);
  int n_fke = s21_sscanf(str2, "%f %lf", &f_fke, &f_fke2);
  ck_assert_float_eq(f_org, f_fke);
  ck_assert_double_eq(f_org2, f_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_f_test1) {
  float f_org = 0;
  float f_fke = 0;
  double f_org2 = 0;
  double f_fke2 = 0;
  char str[500] = "1231231.11231231  -. 3111.2123123";
  char str2[500] = "1231231.11231231  -. 3111.2123123";
  int n_org = sscanf(str, "%f %lf", &f_org, &f_org2);
  int n_fke = s21_sscanf(str2, "%f %lf", &f_fke, &f_fke2);
  ck_assert_float_eq(f_org, f_fke);
  ck_assert_double_eq(f_org2, f_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_f_test2) {
  float f_org = 0;
  float f_fke = 0;
  double f_org2 = 0;
  double f_fke2 = 0;
  char str[500] = "-1231.11231231  -. -3111.2123123";
  char str2[500] = "-1231.11231231  -. -3111.2123123";
  int n_org = sscanf(str, "%f %lf", &f_org, &f_org2);
  int n_fke = s21_sscanf(str2, "%f %lf", &f_fke, &f_fke2);
  ck_assert_float_eq(f_org, f_fke);
  ck_assert_double_eq(f_org2, f_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_f_test3) {
  float e_org = 0;
  float e_fke = 0;
  double e_org2 = 0;
  double e_fke2 = 0;
  char str[500] = "1.1111111 3.22212125";
  char str2[500] = "1.1111111 3.22212125";
  int n_org = sscanf(str, "%f %lf", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "%f %lf", &e_fke, &e_fke2);
  ck_assert_float_eq(e_org, e_fke);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_f_test4) {
  float e_org = 0;
  float e_fke = 0;
  double e_org2 = 0;
  double e_fke2 = 0;
  char str[500] = "-1.1111111 -3.22212125";
  char str2[500] = "-1.1111111 -3.22212125";
  int n_org = sscanf(str, "%f %lf", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "%f %lf", &e_fke, &e_fke2);
  ck_assert_float_eq(e_org, e_fke);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_f_test5) {
  float e_org = 0;
  float e_fke = 0;
  double e_org2 = 0;
  double e_fke2 = 0;
  char str[500] = "-1.1111111 -3.22212125";
  char str2[500] = "-1.1111111 -3.22212125";
  int n_org = sscanf(str, "%3f %17lf", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "%3f %17lf", &e_fke, &e_fke2);
  ck_assert_float_eq(e_org, e_fke);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_f_test6) {
  float e_org = 0;
  float e_fke = 0;
  double e_org2 = 0;
  double e_fke2 = 0;
  char str[500] = "-0.1111111 -3444.22212125";
  char str2[500] = "-0.1111111 -3444.22212125";
  int n_org = sscanf(str, "%1f -%3lf", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "%1f -%3lf", &e_fke, &e_fke2);
  ck_assert_float_eq(e_org, e_fke);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_f_test7) {
  float e_org = 0;
  float e_fke = 0;
  double e_org2 = 0;
  double e_fke2 = 0;
  char str[500] = "0.1111111 3444.22212125";
  char str2[500] = "0.1111111 3444.22212125";
  int n_org = sscanf(str, "%1f %4lf", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "%1f %4lf", &e_fke, &e_fke2);
  ck_assert_float_eq(e_org, e_fke);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_f_test8) {
  long double e_org = 0;
  long double e_fke = 0;
  double e_org2 = 0;
  double e_fke2 = 0;
  char str[500] = "-111111110.1111111 -3444.22212125";
  char str2[500] = "-111111110.1111111 -3444.22212125";
  int n_org = sscanf(str, "%12Lf - %1lf", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "%12Lf - %1lf", &e_fke, &e_fke2);
  ck_assert_ldouble_eq(e_org, e_fke);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_f_test9) {
  long double e_org = 0;
  long double e_fke = 0;
  double e_org2 = 0;
  double e_fke2 = 0;
  char str[500] = "111111110.1111111 -3444.22212125";
  char str2[500] = "111111110.1111111 -3444.22212125";
  int n_org = sscanf(str, "%22Lf %1lf", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "%22Lf %1lf", &e_fke, &e_fke2);
  ck_assert_ldouble_eq(e_org, e_fke);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_f_test10) {
  long double e_org = 0;
  long double e_fke = 0;
  double e_org2 = 0;
  double e_fke2 = 0;
  char str[500] = "111111110.1111111 -3444.22212125";
  char str2[500] = "111111110.1111111 -3444.22212125";
  int n_org = sscanf(str, "%100Lf %1lf", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "%100Lf %1lf", &e_fke, &e_fke2);
  ck_assert_ldouble_eq(e_org, e_fke);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_f_test11) {
  long double e_org = 0;
  long double e_fke = 0;
  double e_org2 = 0;
  double e_fke2 = 0;
  char str[500] = "111111110.1111111 -0.222155552125";
  char str2[500] = "111111110.1111111 -0.222155552125";
  int n_org = sscanf(str, "%1Lf %1lf", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "%1Lf %1lf", &e_fke, &e_fke2);
  ck_assert_ldouble_eq(e_org, e_fke);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST
START_TEST(s21_sscanf_f_test12) {
  double e_org = 1;
  double e_fke = 1;
  double e_org2 = 0;
  double e_fke2 = 0;
  char str[500] = "-. 2.5";
  char str2[500] = "-. 2.5";
  int n_org = sscanf(str, "%2lf %lf", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "%2lf %lf", &e_fke, &e_fke2);
  ck_assert_ldouble_eq(e_org, e_fke);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

// g
START_TEST(s21_sscanf_g_test0) {
  float f_org = 0;
  float f_fke = 0;
  double f_org2 = 0;
  double f_fke2 = 0;
  char str[500] = "1.1 3.2";
  char str2[500] = "1.1 3.2";
  int n_org = sscanf(str, "%g %lg", &f_org, &f_org2);
  int n_fke = s21_sscanf(str2, "%g %lg", &f_fke, &f_fke2);
  ck_assert_float_eq(f_org, f_fke);
  ck_assert_double_eq(f_org2, f_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_g_test1) {
  float f_org = 0;
  float f_fke = 0;
  double f_org2 = 0;
  double f_fke2 = 0;
  char str[500] = "1231231.11231231  -. 3111.2123123";
  char str2[500] = "1231231.11231231  -. 3111.2123123";
  int n_org = sscanf(str, "%g  . %lg", &f_org, &f_org2);
  int n_fke = s21_sscanf(str2, "%g  . %lg", &f_fke, &f_fke2);
  ck_assert_float_eq(f_org, f_fke);
  ck_assert_double_eq(f_org2, f_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_g_test2) {
  float f_org = 0;
  float f_fke = 0;
  double f_org2 = 0;
  double f_fke2 = 0;
  char str[500] = "-1231.11231231  -. -3111.2123123";
  char str2[500] = "-1231.11231231  -. -3111.2123123";
  int n_org = sscanf(str, "-%g -%lg", &f_org, &f_org2);
  int n_fke = s21_sscanf(str2, "-%g -%lg", &f_fke, &f_fke2);
  ck_assert_float_eq(f_org, f_fke);
  ck_assert_double_eq(f_org2, f_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_g_test3) {
  float e_org = 0;
  float e_fke = 0;
  double e_org2 = 0;
  double e_fke2 = 0;
  char str[500] = "1.1111111 3.22212125";
  char str2[500] = "1.1111111 3.22212125";
  int n_org = sscanf(str, "%g %lg", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "%g %lg", &e_fke, &e_fke2);
  ck_assert_float_eq(e_org, e_fke);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_g_test4) {
  float e_org = 0;
  float e_fke = 0;
  double e_org2 = 0;
  double e_fke2 = 0;
  char str[500] = "-1.1111111 - - - -3.22212125";
  char str2[500] = "-1.1111111 - - - -3.22212125";
  int n_org = sscanf(str, "%g -%lg", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "%g -%lg", &e_fke, &e_fke2);
  ck_assert_float_eq(e_org, e_fke);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_g_test5) {
  float e_org = 0;
  float e_fke = 0;
  double e_org2 = 0;
  double e_fke2 = 0;
  char str[500] = "-1.1111111 -3.22212125";
  char str2[500] = "-1.1111111 -3.22212125";
  int n_org = sscanf(str, "%3g %17lg", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "%3g %17lg", &e_fke, &e_fke2);
  ck_assert_float_eq(e_org, e_fke);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_g_test6) {
  float e_org = 0;
  float e_fke = 0;
  double e_org2 = 0;
  double e_fke2 = 0;
  char str[500] = "-0.1111111 -3444.22212125";
  char str2[500] = "-0.1111111 -3444.22212125";
  int n_org = sscanf(str, "%1g %3lg", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "%1g %3lg", &e_fke, &e_fke2);
  ck_assert_float_eq(e_org, e_fke);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_g_test7) {
  float e_org = 0;
  float e_fke = 0;
  double e_org2 = 0;
  double e_fke2 = 0;
  char str[500] = "0.1111111 3444.22212125";
  char str2[500] = "0.1111111 3444.22212125";
  int n_org = sscanf(str, "%1g 344%2lg", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "%1f 344%2lg", &e_fke, &e_fke2);
  ck_assert_float_eq(e_org, e_fke);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_g_test8) {
  long double e_org = 0;
  long double e_fke = 0;
  double e_org2 = 0;
  double e_fke2 = 0;
  char str[500] = "-111111110.1111111 -3444.22212125";
  char str2[500] = "-111111110.1111111 -3444.22212125";
  int n_org = sscanf(str, "%12Lg %1lg", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "%12Lg %1lg", &e_fke, &e_fke2);
  ck_assert_ldouble_eq(e_org, e_fke);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_g_test9) {
  long double e_org = 0;
  long double e_fke = 0;
  double e_org2 = 0;
  double e_fke2 = 0;
  char str[500] = "111111110.1111111 -3444.22212125";
  char str2[500] = "111111110.1111111 -3444.22212125";
  int n_org = sscanf(str, "%22Lg %1lg", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "%22Lg %1lg", &e_fke, &e_fke2);
  ck_assert_ldouble_eq(e_org, e_fke);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_g_test10) {
  long double e_org = 0;
  long double e_fke = 0;
  double e_org2 = 0;
  double e_fke2 = 0;
  char str[500] = "111111110.1111111 -3444.22212125";
  char str2[500] = "111111110.1111111 -3444.22212125";
  int n_org = sscanf(str, "%100Lg %1lg", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "%100Lg %1lg", &e_fke, &e_fke2);
  ck_assert_ldouble_eq(e_org, e_fke);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_g_test11) {
  long double e_org = 0;
  long double e_fke = 0;
  double e_org2 = 0;
  double e_fke2 = 0;
  char str[500] = "111111110.1111111 -0.222155552125";
  char str2[500] = "111111110.1111111 -0.222155552125";
  int n_org = sscanf(str, "%1Lg %1lg", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "%1Lg %1lg", &e_fke, &e_fke2);
  ck_assert_ldouble_eq(e_org, e_fke);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

// G

START_TEST(s21_sscanf_G_test0) {
  float f_org = 0;
  float f_fke = 0;
  double f_org2 = 0;
  double f_fke2 = 0;
  char str[500] = "1.1 3.2";
  char str2[500] = "1.1 3.2";
  int n_org = sscanf(str, "%G %lG", &f_org, &f_org2);
  int n_fke = s21_sscanf(str2, "%G %lG", &f_fke, &f_fke2);
  ck_assert_float_eq(f_org, f_fke);
  ck_assert_double_eq(f_org2, f_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_G_test1) {
  float f_org = 0;
  float f_fke = 0;
  double f_org2 = 0;
  double f_fke2 = 0;
  char str[500] = "1231231.11231231  -. 3111.2123123";
  char str2[500] = "1231231.11231231  -. 3111.2123123";
  int n_org = sscanf(str, "%G  . %lG", &f_org, &f_org2);
  int n_fke = s21_sscanf(str2, "%G  . %lG", &f_fke, &f_fke2);
  ck_assert_float_eq(f_org, f_fke);
  ck_assert_double_eq(f_org2, f_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_G_test2) {
  float f_org = 0;
  float f_fke = 0;
  double f_org2 = 0;
  double f_fke2 = 0;
  char str[500] = "-1231.11231231  -. -3111.2123123";
  char str2[500] = "-1231.11231231  -. -3111.2123123";
  int n_org = sscanf(str, "-%G -%lG", &f_org, &f_org2);
  int n_fke = s21_sscanf(str2, "-%G -%lG", &f_fke, &f_fke2);
  ck_assert_float_eq(f_org, f_fke);
  ck_assert_double_eq(f_org2, f_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_G_test3) {
  float e_org = 0;
  float e_fke = 0;
  double e_org2 = 0;
  double e_fke2 = 0;
  char str[500] = "1.1111111 3.22212125";
  char str2[500] = "1.1111111 3.22212125";
  int n_org = sscanf(str, "%G %lG", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "%G %lG", &e_fke, &e_fke2);
  ck_assert_float_eq(e_org, e_fke);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_G_test4) {
  float e_org = 0;
  float e_fke = 0;
  double e_org2 = 0;
  double e_fke2 = 0;
  char str[500] = "-1.1111111 - - - -3.22212125";
  char str2[500] = "-1.1111111 - - - -3.22212125";
  int n_org = sscanf(str, "%G -%lG", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "%G -%lG", &e_fke, &e_fke2);
  ck_assert_float_eq(e_org, e_fke);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_G_test5) {
  float e_org = 0;
  float e_fke = 0;
  double e_org2 = 0;
  double e_fke2 = 0;
  char str[500] = "-1.1111111 -3.22212125";
  char str2[500] = "-1.1111111 -3.22212125";
  int n_org = sscanf(str, "%3G %17lG", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "%3G %17lG", &e_fke, &e_fke2);
  ck_assert_float_eq(e_org, e_fke);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_G_test6) {
  float e_org = 0;
  float e_fke = 0;
  double e_org2 = 0;
  double e_fke2 = 0;
  char str[500] = "-0.1111111 -3444.22212125";
  char str2[500] = "-0.1111111 -3444.22212125";
  int n_org = sscanf(str, "%1G %2lG", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "%1G %2lG", &e_fke, &e_fke2);
  ck_assert_float_eq(e_org, e_fke);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_G_test7) {
  float e_org = 0;
  float e_fke = 0;
  double e_org2 = 0;
  double e_fke2 = 0;
  char str[500] = "0.1111111 3444.22212125";
  char str2[500] = "0.1111111 3444.22212125";
  int n_org = sscanf(str, "%1G 344%1lG", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "%1G 344%1lG", &e_fke, &e_fke2);
  ck_assert_float_eq(e_org, e_fke);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_G_test8) {
  long double e_org = 0;
  long double e_fke = 0;
  double e_org2 = 0;
  double e_fke2 = 0;
  char str[500] = "-111111110.1111111 -3444.22212125";
  char str2[500] = "-111111110.1111111 -3444.22212125";
  int n_org = sscanf(str, "%12LG %1lG", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "%12LG %1lG", &e_fke, &e_fke2);
  ck_assert_ldouble_eq(e_org, e_fke);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_G_test9) {
  long double e_org = 0;
  long double e_fke = 0;
  double e_org2 = 0;
  double e_fke2 = 0;
  char str[500] = "111111110.1111111 -3444.22212125";
  char str2[500] = "111111110.1111111 -3444.22212125";
  int n_org = sscanf(str, "%22LG %1lG", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "%22LG %1lG", &e_fke, &e_fke2);
  ck_assert_ldouble_eq(e_org, e_fke);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_G_test10) {
  long double e_org = 0;
  long double e_fke = 0;
  double e_org2 = 0;
  double e_fke2 = 0;
  char str[500] = "111111110.1111111 -3444.22212125";
  char str2[500] = "111111110.1111111 -3444.22212125";
  int n_org = sscanf(str, "%100LG %1lG", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "%100LG %1lG", &e_fke, &e_fke2);
  ck_assert_ldouble_eq(e_org, e_fke);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_G_test11) {
  long double e_org = 0;
  long double e_fke = 0;
  double e_org2 = 0;
  double e_fke2 = 0;
  char str[500] = "111111110.1111111 -0.222155552125";
  char str2[500] = "111111110.1111111 -0.222155552125";
  int n_org = sscanf(str, "%1LG %1lG", &e_org, &e_org2);
  int n_fke = s21_sscanf(str2, "%1LG %1lG", &e_fke, &e_fke2);
  ck_assert_ldouble_eq(e_org, e_fke);
  ck_assert_double_eq(e_org2, e_fke2);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

// o
START_TEST(s21_sscanf_o_test0) {
  unsigned int o_org = 0;
  unsigned int o_fke = 0;
  unsigned long int o_org2 = 0;
  unsigned long int o_fke2 = 0;
  unsigned short int o_org3 = 0;
  unsigned short int o_fke3 = 0;
  char str[500] = "0123 565 . -146";
  char str2[500] = "0123 565 . -146";
  int n_org = sscanf(str, "%o %lo %ho", &o_org, &o_org2, &o_org3);
  int n_fke = s21_sscanf(str2, "%o %lo %ho", &o_fke, &o_fke2, &o_fke3);
  ck_assert_uint_eq(o_org, o_fke);
  ck_assert_uint_eq(o_org2, o_fke2);
  ck_assert_uint_eq(o_org3, o_fke3);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_o_test1) {
  unsigned int o_org = 0;
  unsigned int o_fke = 0;
  unsigned long int o_org2 = 0;
  unsigned long int o_fke2 = 0;
  unsigned short int o_org3 = 0;
  unsigned short int o_fke3 = 0;
  char str[500] = "0123 565 . -146";
  char str2[500] = "0123 565 . -146";
  int n_org = sscanf(str, "%1o %2lo %3ho", &o_org, &o_org2, &o_org3);
  int n_fke = s21_sscanf(str2, "%1o %2lo %3ho", &o_fke, &o_fke2, &o_fke3);
  ck_assert_uint_eq(o_org, o_fke);
  ck_assert_uint_eq(o_org2, o_fke2);
  ck_assert_uint_eq(o_org3, o_fke3);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_o_test2) {
  unsigned int o_org = 0;
  unsigned int o_fke = 0;
  unsigned long int o_org2 = 0;
  unsigned long int o_fke2 = 0;
  unsigned short int o_org3 = 0;
  unsigned short int o_fke3 = 0;
  char str[500] = "0123 565 . -146";
  char str2[500] = "0123 565 . -146";
  int n_org = sscanf(str, "%1o %2lo %3ho", &o_org, &o_org2, &o_org3);
  int n_fke = s21_sscanf(str2, "%1o %2lo %3ho", &o_fke, &o_fke2, &o_fke3);
  ck_assert_uint_eq(o_org, o_fke);
  ck_assert_uint_eq(o_org2, o_fke2);
  ck_assert_uint_eq(o_org3, o_fke3);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_o_test3) {
  unsigned int o_org = 0;
  unsigned int o_fke = 0;
  unsigned long int o_org2 = 0;
  unsigned long int o_fke2 = 0;
  unsigned short int o_org3 = 0;
  unsigned short int o_fke3 = 0;
  char str[500] = "015555555528 777 . -886 54 126";
  char str2[500] = "015555555528 777 . -886 54 126";
  unsigned char c1, c1_;
  unsigned long long int c2, c2_;
  int n_org = sscanf(str, "%25o %5lo %4ho %hho %llo", &o_org, &o_org2, &o_org3,
                     &c1, &c2);
  int n_fke = s21_sscanf(str2, "%25o %5lo %4ho %hho %llo", &o_fke, &o_fke2,
                         &o_fke3, &c1_, &c2_);
  ck_assert_uint_eq(o_org, o_fke);
  ck_assert_uint_eq(o_org2, o_fke3);
  ck_assert_uint_eq(o_org3, o_fke3);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

// s
START_TEST(s21_sscanf_s_test0) {
  char str_org[500];
  char str_fke[500];
  char str[500] = "Hello test test test";
  char str2[500] = "Hello test test test";
  int n_org = sscanf(str, "%*s%s", str_org);
  int n_fke = s21_sscanf(str2, "%*s%s", str_fke);
  ck_assert_str_eq(str_org, str_fke);
  ck_assert_int_eq(n_fke, n_org);
}
END_TEST

START_TEST(s21_sscanf_s_test1) {
  char str_org[500];
  char str_fke[500];
  char str[500] = "Hello test test test";
  char str2[500] = "Hello test test test";
  int n_org = sscanf(str, "%3s", str_org);
  int n_fke = s21_sscanf(str2, "%3s", str_fke);
  ck_assert_str_eq(str_org, str_fke);
  ck_assert_int_eq(n_fke, n_org);
}
END_TEST

START_TEST(s21_sscanf_s_test2) {
  char str_org[500];
  char str_fke[500];
  char str[500] = "Hello test test test";
  char str2[500] = "Hello test test test";
  int n_org = sscanf(str, "%15s", str_org);
  int n_fke = s21_sscanf(str2, "%15s", str_fke);
  ck_assert_str_eq(str_org, str_fke);
  ck_assert_int_eq(n_fke, n_org);
}
END_TEST

START_TEST(s21_sscanf_s_test3) {
  char str_org[500];
  char str_fke[500];
  char str[500] = "Hello test test test";
  char str2[500] = "Hello test test test";
  int n_org = sscanf(str, "%150s", str_org);
  int n_fke = s21_sscanf(str2, "%150s", str_fke);
  ck_assert_str_eq(str_org, str_fke);
  ck_assert_int_eq(n_fke, n_org);
}
END_TEST

START_TEST(s21_sscanf_s_test4) {
  char str_org[500];
  char str_fke[500];
  char str[500] = "Hello test test test";
  char str2[500] = "Hello test test test";
  int n_org = sscanf(str, " H%15s", str_org);
  int n_fke = s21_sscanf(str2, " H%15s", str_fke);
  ck_assert_str_eq(str_org, str_fke);
  ck_assert_int_eq(n_fke, n_org);
}
END_TEST

START_TEST(s21_sscanf_s_test5) {
  char str_org[500];
  char str_fke[500];
  char str[500] = "Hello test test test";
  char str2[500] = "Hello test test test";
  int n_org = sscanf(str, "Hello%25s", str_org);
  int n_fke = s21_sscanf(str2, "Hello%15s", str_fke);
  ck_assert_str_eq(str_org, str_fke);
  ck_assert_int_eq(n_fke, n_org);
}
END_TEST

// u
START_TEST(s21_sscanf_u_test0) {
  unsigned int u_org = 0;
  unsigned int u_fke = 0;
  char str[500] = " 15...";
  char str2[500] = " 15...";
  int n_org = sscanf(str, "%u", &u_org);
  int n_fke = s21_sscanf(str2, "%u", &u_fke);
  ck_assert_uint_eq(u_org, u_fke);
  ck_assert_int_eq(n_fke, n_org);
}
END_TEST

START_TEST(s21_sscanf_u_test1) {
  unsigned int u_org = 0;
  unsigned int u_fke = 0;
  char str[500] = " -15...";
  char str2[500] = " -15...";
  int n_org = sscanf(str, " %u", &u_org);
  int n_fke = s21_sscanf(str2, " %u", &u_fke);
  ck_assert_uint_eq(u_org, u_fke);
  ck_assert_int_eq(n_fke, n_org);
}
END_TEST

START_TEST(s21_sscanf_u_test2) {
  unsigned int u_org = 0;
  unsigned int u_fke = 0;
  char str[500] = " 2 Nan inf -iNf";
  char str2[500] = " 2 Nan inf -iNf";
  double c1, c2, c3;
  double c1_, c2_, c3_;
  int n_org = sscanf(str, " %u %lf %lf %lf", &u_org, &c1, &c2, &c3);
  int n_fke = s21_sscanf(str2, " %u %lf %lf %lf", &u_fke, &c1_, &c2_, &c3_);
  ck_assert_uint_eq(u_org, u_fke);
  ck_assert_int_eq(n_fke, n_org);
}
END_TEST

START_TEST(s21_sscanf_u_test3) {
  unsigned int u_org = 0;
  unsigned int u_fke = 0;
  unsigned int u_org2 = 0;
  unsigned int u_fke2 = 0;
  char str[500] = " 15.124..";
  char str2[500] = " 15.124..";
  int c1, c1_;
  int n_org = sscanf(str, " %2u.%3u..%n", &u_org, &u_org2, &c1);
  int n_fke = s21_sscanf(str2, " %2u.%3u..%n", &u_fke, &u_fke2, &c1_);
  ck_assert_uint_eq(u_org, u_fke);
  ck_assert_uint_eq(u_org2, u_fke2);
  ck_assert_int_eq(n_fke, n_org);
}
END_TEST

START_TEST(s21_sscanf_u_test4) {
  unsigned int u_org = 0;
  unsigned int u_fke = 0;
  unsigned int u_org2 = 0;
  unsigned int u_fke2 = 0;
  char str[500] = " -15 -. - .\0 124..";
  char str2[500] = " -15 -. - .\0 124..";
  int n_org = sscanf(str, " %1u %2u", &u_org, &u_org2);
  int n_fke = s21_sscanf(str2, " %1u %2u", &u_fke, &u_fke2);
  ck_assert_int_eq(n_fke, n_org);
  ck_assert_uint_eq(u_org, u_fke);
  ck_assert_uint_eq(u_org2, u_fke2);
}
END_TEST

START_TEST(s21_sscanf_u_test5) {
  unsigned short int u_org = 0;
  unsigned short int u_fke = 0;
  char str[500] = " 15...";
  char str2[500] = " 15...";
  int n_org = sscanf(str, "%hu", &u_org);
  int n_fke = s21_sscanf(str2, "%hu", &u_fke);
  ck_assert_uint_eq(u_org, u_fke);
  ck_assert_int_eq(n_fke, n_org);
}
END_TEST

START_TEST(s21_sscanf_u_test6) {
  unsigned short int u_org = 0;
  unsigned short int u_fke = 0;
  char str[500] = " -15...";
  char str2[500] = " -15...";
  int n_org = sscanf(str, " %1hu", &u_org);
  int n_fke = s21_sscanf(str2, " %1hu", &u_fke);
  ck_assert_uint_eq(u_org, u_fke);
  ck_assert_int_eq(n_fke, n_org);
}
END_TEST

START_TEST(s21_sscanf_u_test7) {
  unsigned short int u_org = 0;
  unsigned short int u_fke = 0;
  char str[500] = " 15.124..";
  char str2[500] = " 15.124..";
  int n_org = sscanf(str, " %6hu", &u_org);
  int n_fke = s21_sscanf(str2, " %6hu", &u_fke);
  ck_assert_uint_eq(u_org, u_fke);
  ck_assert_int_eq(n_fke, n_org);
}
END_TEST

START_TEST(s21_sscanf_u_test8) {
  unsigned short int u_org = 0;
  unsigned short int u_fke = 0;
  unsigned short int u_org2 = 0;
  unsigned short int u_fke2 = 0;
  char str[500] = " 15.124..";
  char str2[500] = " 15.124..";
  int n_org = sscanf(str, " %2hu %3hu", &u_org, &u_org2);
  int n_fke = s21_sscanf(str2, " %2hu %3hu", &u_fke, &u_fke2);
  ck_assert_uint_eq(u_org, u_fke);
  ck_assert_uint_eq(u_org2, u_fke2);
  ck_assert_int_eq(n_fke, n_org);
}
END_TEST

START_TEST(s21_sscanf_u_test9) {
  unsigned short int u_org = 0;
  unsigned short int u_fke = 0;
  unsigned short int u_org2 = 0;
  unsigned short int u_fke2 = 0;
  char str[500] = " -15 -. - .\0 124..";
  char str2[500] = " -15 -. - .\0 124..";
  int n_org = sscanf(str, " %hu %hu", &u_org, &u_org2);
  int n_fke = s21_sscanf(str2, " %hu %hu", &u_fke, &u_fke2);
  ck_assert_uint_eq(u_org, u_fke);
  ck_assert_uint_eq(u_org2, u_fke2);
  ck_assert_int_eq(n_fke, n_org);
}
END_TEST

START_TEST(s21_sscanf_u_test10) {
  unsigned long int u_org = 0;
  unsigned long int u_fke = 0;
  char str[500] = " .15000000000...";
  char str2[500] = " .15000000000...";
  int n_org = sscanf(str, "%lu", &u_org);
  int n_fke = s21_sscanf(str2, "%lu", &u_fke);
  ck_assert_uint_eq(u_org, u_fke);
  ck_assert_int_eq(n_fke, n_org);
}
END_TEST

START_TEST(s21_sscanf_u_test11) {
  unsigned long int u_org = 0;
  unsigned long int u_fke = 0;
  char str[500] = " -15...";
  char str2[500] = " -15...";
  int n_org = sscanf(str, " %1lu", &u_org);
  int n_fke = s21_sscanf(str2, " %1lu", &u_fke);
  ck_assert_uint_eq(u_org, u_fke);
  ck_assert_int_eq(n_fke, n_org);
}
END_TEST

START_TEST(s21_sscanf_u_test12) {
  unsigned long int u_org = 0;
  unsigned long int u_fke = 0;
  char str[500] = " 15.124..";
  char str2[500] = " 15.124..";
  int n_org = sscanf(str, " %6lu", &u_org);
  int n_fke = s21_sscanf(str2, " %6lu", &u_fke);
  ck_assert_uint_eq(u_org, u_fke);
  ck_assert_int_eq(n_fke, n_org);
}
END_TEST

START_TEST(s21_sscanf_u_test13) {
  unsigned long int u_org = 0;
  unsigned long int u_fke = 0;
  unsigned long int u_org2 = 0;
  unsigned long int u_fke2 = 0;
  char str[500] = " 15.124..";
  char str2[500] = " 15.124..";
  int n_org = sscanf(str, " %2lu %3lu", &u_org, &u_org2);
  int n_fke = s21_sscanf(str2, " %2lu %3lu", &u_fke, &u_fke2);
  ck_assert_uint_eq(u_org, u_fke);
  ck_assert_uint_eq(u_org2, u_fke2);
  ck_assert_int_eq(n_fke, n_org);
}
END_TEST

START_TEST(s21_sscanf_u_test14) {
  unsigned long int u_org = 0;
  unsigned long int u_fke = 0;
  unsigned long int u_org2 = 0;
  unsigned long int u_fke2 = 0;
  char str[500] = " -15 -. - .\0 124..";
  char str2[500] = " -15 -. - .\0 124..";
  int n_org = sscanf(str, " %lu %lu", &u_org, &u_org2);
  int n_fke = s21_sscanf(str2, " %lu %lu", &u_fke, &u_fke2);
  ck_assert_uint_eq(u_org, u_fke);
  ck_assert_uint_eq(u_org2, u_fke2);
  ck_assert_int_eq(n_fke, n_org);
}
END_TEST

// X
START_TEST(s21_sscanf_X_test0) {
  unsigned int x_org = 0;
  unsigned int x_fke = 0;
  char str[500] = "0xFFe 26 26";
  char str2[500] = "0xFFe 26 26";
  unsigned char c1, c1_;
  unsigned long long int c2, c2_;
  int n_org = sscanf(str, "%X %hhu %llu", &x_org, &c1, &c2);
  int n_fke = s21_sscanf(str2, "%X %hhu %llu", &x_fke, &c1_, &c2_);
  ck_assert_uint_eq(x_org, x_fke);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_X_test1) {
  unsigned int x_org = 0;
  unsigned int x_fke = 0;
  char str[500] = "0xFFe";
  char str2[500] = "0xFFe";
  int n_org = sscanf(str, "0%X", &x_org);
  int n_fke = s21_sscanf(str2, "0%X", &x_fke);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_uint_eq(x_org, x_fke);
}
END_TEST

START_TEST(s21_sscanf_X_test2) {
  unsigned int x_org = 0;
  unsigned int x_fke = 0;
  char str[500] = "-0xFFe";
  char str2[500] = "-0xFFe";
  int n_org = sscanf(str, "%X", &x_org);
  int n_fke = s21_sscanf(str2, "%X", &x_fke);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_uint_eq(x_org, x_fke);
}
END_TEST

START_TEST(s21_sscanf_X_test3) {
  unsigned int x_org = 0;
  unsigned int x_fke = 0;
  char str[500] = "-0xFFe";
  char str2[500] = "-0xFFe";
  int n_org = sscanf(str, "%X", &x_org);
  int n_fke = s21_sscanf(str2, "%X", &x_fke);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_uint_eq(x_org, x_fke);
}
END_TEST

START_TEST(s21_sscanf_X_test4) {
  unsigned int x_org = 0;
  unsigned int x_fke = 0;
  unsigned int x_org2 = 0;
  unsigned int x_fke2 = 0;
  char str[500] = "-0xFFe,,,\0AAAa";
  char str2[500] = "-0xFFe,,,\0AAAa";
  int n_org = sscanf(str, "%X %X", &x_org, &x_org2);
  int n_fke = s21_sscanf(str2, "%X %X", &x_fke, &x_fke2);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_uint_eq(x_org, x_fke);
}
END_TEST

START_TEST(s21_sscanf_X_test5) {
  unsigned int x_org = 0;
  unsigned int x_fke = 0;
  unsigned int x_org2 = 0;
  unsigned int x_fke2 = 0;
  char str[500] = "0xFFe,,,\0AAAa";
  char str2[500] = "0xFFe,,,\0AAAa";
  int n_org = sscanf(str, "%1X ,%3X", &x_org, &x_org2);
  int n_fke = s21_sscanf(str2, "%1X ,%3X", &x_fke, &x_fke2);
  ck_assert_uint_eq(x_org, x_fke);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_X_test6) {
  unsigned short int x_org = 0;
  unsigned short int x_fke = 0;
  char str[500] = "0xFFe";
  char str2[500] = "0xFFe";
  int n_org = sscanf(str, "%hX", &x_org);
  int n_fke = s21_sscanf(str2, "%hX", &x_fke);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_uint_eq(x_org, x_fke);
}
END_TEST

START_TEST(s21_sscanf_X_test7) {
  unsigned short int x_org = 0;
  unsigned short int x_fke = 0;
  char str[500] = "0xFFe";
  char str2[500] = "0xFFe";
  int n_org = sscanf(str, "0%hX", &x_org);
  int n_fke = s21_sscanf(str2, "0%hX", &x_fke);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_uint_eq(x_org, x_fke);
}
END_TEST

START_TEST(s21_sscanf_X_test8) {
  unsigned short int x_org = 0;
  unsigned short int x_fke = 0;
  char str[500] = "-0xFFe";
  char str2[500] = "-0xFFe";
  int n_org = sscanf(str, "%hX", &x_org);
  int n_fke = s21_sscanf(str2, "%hX", &x_fke);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_uint_eq(x_org, x_fke);
}
END_TEST

START_TEST(s21_sscanf_X_test9) {
  unsigned short int x_org = 0;
  unsigned short int x_fke = 0;
  char str[500] = "-0xFFe";
  char str2[500] = "-0xFFe";
  int n_org = sscanf(str, "%hX", &x_org);
  int n_fke = s21_sscanf(str2, "%hX", &x_fke);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_uint_eq(x_org, x_fke);
}
END_TEST

START_TEST(s21_sscanf_X_test10) {
  unsigned short int x_org = 0;
  unsigned short int x_fke = 0;
  unsigned short int x_org2 = 0;
  unsigned short int x_fke2 = 0;
  char str[500] = "-0xFFe,,,\0AAAa";
  char str2[500] = "-0xFFe,,,\0AAAa";
  int n_org = sscanf(str, "%hX %hX", &x_org, &x_org2);
  int n_fke = s21_sscanf(str2, "%hX %hX", &x_fke, &x_fke2);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_uint_eq(x_org, x_fke);
}
END_TEST

START_TEST(s21_sscanf_X_test11) {
  unsigned short int x_org = 0;
  unsigned short int x_fke = 0;
  unsigned short int x_org2 = 0;
  unsigned short int x_fke2 = 0;
  char str[500] = "-0xFFe,,,\0AAAa";
  char str2[500] = "-0xFFe,,,\0AAAa";
  int n_org = sscanf(str, "%1hX ,%3hX", &x_org, &x_org2);
  int n_fke = s21_sscanf(str2, "%1hX ,%3hX", &x_fke, &x_fke2);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_uint_eq(x_org, x_fke);
}
END_TEST

START_TEST(s21_sscanf_X_test12) {
  unsigned int x_org = 0;
  unsigned int x_fke = 0;
  unsigned int x_org2 = 0;
  unsigned int x_fke2 = 0;
  char str[500] = "-0xFFFFFe,,,\0AAAa";
  char str2[500] = "-0xFFFFFe,,,\0AAAa";
  int n_org = sscanf(str, "%3X %2X", &x_org, &x_org2);
  int n_fke = s21_sscanf(str2, "%3X %2X", &x_fke, &x_fke2);
  ck_assert_uint_eq(x_org, x_fke);
  ck_assert_int_eq(n_org, n_fke);
}
END_TEST

START_TEST(s21_sscanf_X_test13) {
  unsigned short int x_org = 0;
  unsigned short int x_fke = 0;
  unsigned short int x_org2 = 0;
  unsigned short int x_fke2 = 0;
  char str[500] = "-0xFFFFFe,,,\0AAAa";
  char str2[500] = "-0xFFFFFe,,,\0AAAa";
  int n_org = sscanf(str, "%3hX %2hX", &x_org, &x_org2);
  int n_fke = s21_sscanf(str2, "%3hX %2hX", &x_fke, &x_fke2);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_uint_eq(x_org, x_fke);
}
END_TEST

START_TEST(s21_sscanf_X_test14) {
  unsigned long int x_org = 0;
  unsigned long int x_fke = 0;
  char str[500] = "0xFFe";
  char str2[500] = "0xFFe";
  int n_org = sscanf(str, "%lX", &x_org);
  int n_fke = s21_sscanf(str2, "%lX", &x_fke);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_uint_eq(x_org, x_fke);
}
END_TEST

START_TEST(s21_sscanf_X_test15) {
  unsigned long int x_org = 0;
  unsigned long int x_fke = 0;
  char str[500] = "0xFFe";
  char str2[500] = "0xFFe";
  int n_org = sscanf(str, "0%lX", &x_org);
  int n_fke = s21_sscanf(str2, "0%lX", &x_fke);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_uint_eq(x_org, x_fke);
}
END_TEST

START_TEST(s21_sscanf_X_test16) {
  unsigned long int x_org = 0;
  unsigned long int x_fke = 0;
  char str[500] = "-0xFFe";
  char str2[500] = "-0xFFe";
  int n_org = sscanf(str, "%lX", &x_org);
  int n_fke = s21_sscanf(str2, "%lX", &x_fke);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_uint_eq(x_org, x_fke);
}
END_TEST

START_TEST(s21_sscanf_X_test17) {
  unsigned long int x_org = 0;
  unsigned long int x_fke = 0;
  char str[500] = "-0xFFe";
  char str2[500] = "-0xFFe";
  int n_org = sscanf(str, "%lX", &x_org);
  int n_fke = s21_sscanf(str2, "%lX", &x_fke);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_uint_eq(x_org, x_fke);
}
END_TEST

START_TEST(s21_sscanf_X_test18) {
  unsigned long int x_org = 0;
  unsigned long int x_fke = 0;
  unsigned long int x_org2 = 0;
  unsigned long int x_fke2 = 0;
  char str[500] = "-0xFFe,,,\0AAAa";
  char str2[500] = "-0xFFe,,,\0AAAa";
  int n_org = sscanf(str, "%lX %lX", &x_org, &x_org2);
  int n_fke = s21_sscanf(str2, "%lX %lX", &x_fke, &x_fke2);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_uint_eq(x_org, x_fke);
}
END_TEST

START_TEST(s21_sscanf_X_test19) {
  unsigned long int x_org = 0;
  unsigned long int x_fke = 0;
  unsigned long int x_org2 = 0;
  unsigned long int x_fke2 = 0;
  char str[500] = "-0xFFe,,,\0AAAa";
  char str2[500] = "-0xFFe,,,\0AAAa";
  int n_org = sscanf(str, "%1lX ,%3lX", &x_org, &x_org2);
  int n_fke = s21_sscanf(str2, "%1lX ,%3lX", &x_fke, &x_fke2);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_uint_eq(x_org, x_fke);
}
END_TEST

START_TEST(s21_sscanf_X_test20) {
  unsigned long int x_org = 0;
  unsigned long int x_fke = 0;
  unsigned long int x_org2 = 0;
  unsigned long int x_fke2 = 0;
  char str[500] = "-0xFFFFFe,,,\0AAAa";
  char str2[500] = "-0xFFFFFe,,,\0AAAa";
  int n_org = sscanf(str, "%3lX %2lX", &x_org, &x_org2);
  int n_fke = s21_sscanf(str2, "%3lX %2lX", &x_fke, &x_fke2);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_uint_eq(x_org, x_fke);
}
END_TEST

// x

START_TEST(s21_sscanf_x_test0) {
  unsigned int x_org = 0;
  unsigned int x_fke = 0;
  char str[500] = "0xFFe";
  char str2[500] = "0xFFe";
  int n_org = sscanf(str, "%x", &x_org);
  int n_fke = s21_sscanf(str2, "%x", &x_fke);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_uint_eq(x_org, x_fke);
}
END_TEST

START_TEST(s21_sscanf_x_test1) {
  unsigned int x_org = 0;
  unsigned int x_fke = 0;
  char str[500] = "0xFFe";
  char str2[500] = "0xFFe";
  int n_org = sscanf(str, "0%x", &x_org);
  int n_fke = s21_sscanf(str2, "0%x", &x_fke);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_uint_eq(x_org, x_fke);
}
END_TEST

START_TEST(s21_sscanf_x_test2) {
  unsigned int x_org = 0;
  unsigned int x_fke = 0;
  char str[500] = "-0xFFe";
  char str2[500] = "-0xFFe";
  int n_org = sscanf(str, "%x", &x_org);
  int n_fke = s21_sscanf(str2, "%x", &x_fke);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_uint_eq(x_org, x_fke);
}
END_TEST

START_TEST(s21_sscanf_x_test3) {
  unsigned int x_org = 0;
  unsigned int x_fke = 0;
  char str[500] = "-0xFFe";
  char str2[500] = "-0xFFe";
  int n_org = sscanf(str, "%x", &x_org);
  int n_fke = s21_sscanf(str2, "%x", &x_fke);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_uint_eq(x_org, x_fke);
}
END_TEST

START_TEST(s21_sscanf_x_test4) {
  unsigned int x_org = 0;
  unsigned int x_fke = 0;
  unsigned int x_org2 = 0;
  unsigned int x_fke2 = 0;
  char str[500] = "-0xFFe,,,\0AAAa";
  char str2[500] = "-0xFFe,,,\0AAAa";
  int n_org = sscanf(str, "%x %x", &x_org, &x_org2);
  int n_fke = s21_sscanf(str2, "%x %x", &x_fke, &x_fke2);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_uint_eq(x_org, x_fke);
}
END_TEST

START_TEST(s21_sscanf_x_test5) {
  unsigned int x_org = 0;
  unsigned int x_fke = 0;
  unsigned int x_org2 = 0;
  unsigned int x_fke2 = 0;
  char str[500] = "-0xFFe,,,\0AAAa";
  char str2[500] = "-0xFFe,,,\0AAAa";
  int n_org = sscanf(str, "%1x ,%3x", &x_org, &x_org2);
  int n_fke = s21_sscanf(str2, "%1x ,%3x", &x_fke, &x_fke2);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_uint_eq(x_org, x_fke);
}
END_TEST

START_TEST(s21_sscanf_x_test6) {
  unsigned short int x_org = 0;
  unsigned short int x_fke = 0;
  char str[500] = "0xFFe";
  char str2[500] = "0xFFe";
  int n_org = sscanf(str, "%hx", &x_org);
  int n_fke = s21_sscanf(str2, "%hx", &x_fke);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_uint_eq(x_org, x_fke);
}
END_TEST

START_TEST(s21_sscanf_x_test7) {
  unsigned short int x_org = 0;
  unsigned short int x_fke = 0;
  char str[500] = "0xFFe";
  char str2[500] = "0xFFe";
  int n_org = sscanf(str, "0%hx", &x_org);
  int n_fke = s21_sscanf(str2, "0%hx", &x_fke);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_uint_eq(x_org, x_fke);
}
END_TEST

START_TEST(s21_sscanf_x_test8) {
  unsigned short int x_org = 0;
  unsigned short int x_fke = 0;
  char str[500] = "-0xFFe";
  char str2[500] = "-0xFFe";
  int n_org = sscanf(str, "%hx", &x_org);
  int n_fke = s21_sscanf(str2, "%hx", &x_fke);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_uint_eq(x_org, x_fke);
}
END_TEST

START_TEST(s21_sscanf_x_test9) {
  unsigned short int x_org = 0;
  unsigned short int x_fke = 0;
  char str[500] = "-0xFFe";
  char str2[500] = "-0xFFe";
  int n_org = sscanf(str, "%hx", &x_org);
  int n_fke = s21_sscanf(str2, "%hx", &x_fke);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_uint_eq(x_org, x_fke);
}
END_TEST

START_TEST(s21_sscanf_x_test10) {
  unsigned short int x_org = 0;
  unsigned short int x_fke = 0;
  unsigned short int x_org2 = 0;
  unsigned short int x_fke2 = 0;
  char str[500] = "-0xFFe,,,\0AAAa";
  char str2[500] = "-0xFFe,,,\0AAAa";
  int n_org = sscanf(str, "%hx %hx", &x_org, &x_org2);
  int n_fke = s21_sscanf(str2, "%hx %hx", &x_fke, &x_fke2);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_uint_eq(x_org, x_fke);
}
END_TEST

START_TEST(s21_sscanf_x_test11) {
  unsigned short int x_org = 0;
  unsigned short int x_fke = 0;
  unsigned short int x_org2 = 0;
  unsigned short int x_fke2 = 0;
  char str[500] = "-0xFFe,,,\0AAAa";
  char str2[500] = "-0xFFe,,,\0AAAa";
  int n_org = sscanf(str, "%1hx ,%3hx", &x_org, &x_org2);
  int n_fke = s21_sscanf(str2, "%1hx ,%3hx", &x_fke, &x_fke2);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_uint_eq(x_org, x_fke);
}
END_TEST

START_TEST(s21_sscanf_x_test12) {
  unsigned int x_org = 0;
  unsigned int x_fke = 0;
  unsigned int x_org2 = 0;
  unsigned int x_fke2 = 0;
  char str[500] = "-0xFFFFFe,,,\0AAAa";
  char str2[500] = "-0xFFFFFe,,,\0AAAa";
  int n_org = sscanf(str, "%3x %2x", &x_org, &x_org2);
  int n_fke = s21_sscanf(str2, "%3x %2x", &x_fke, &x_fke2);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_uint_eq(x_org, x_fke);
}
END_TEST

START_TEST(s21_sscanf_x_test13) {
  unsigned short int x_org = 0;
  unsigned short int x_fke = 0;
  unsigned short int x_org2 = 0;
  unsigned short int x_fke2 = 0;
  char str[500] = "-0xFFFFFe,,,\0AAAa";
  char str2[500] = "-0xFFFFFe,,,\0AAAa";
  int n_org = sscanf(str, "%3hx %2hx", &x_org, &x_org2);
  int n_fke = s21_sscanf(str2, "%3hx %2hx", &x_fke, &x_fke2);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_uint_eq(x_org, x_fke);
}
END_TEST

START_TEST(s21_sscanf_x_test14) {
  unsigned long int x_org = 0;
  unsigned long int x_fke = 0;
  char str[500] = "0xFFe";
  char str2[500] = "0xFFe";
  int n_org = sscanf(str, "%lx", &x_org);
  int n_fke = s21_sscanf(str2, "%lx", &x_fke);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_uint_eq(x_org, x_fke);
}
END_TEST

START_TEST(s21_sscanf_x_test15) {
  unsigned long int x_org = 0;
  unsigned long int x_fke = 0;
  char str[500] = "0xFFe";
  char str2[500] = "0xFFe";
  int n_org = sscanf(str, "0%lx", &x_org);
  int n_fke = s21_sscanf(str2, "0%lx", &x_fke);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_uint_eq(x_org, x_fke);
}
END_TEST

START_TEST(s21_sscanf_x_test16) {
  unsigned long int x_org = 0;
  unsigned long int x_fke = 0;
  char str[500] = "-0xFFe";
  char str2[500] = "-0xFFe";
  int n_org = sscanf(str, "%lx", &x_org);
  int n_fke = s21_sscanf(str2, "%lx", &x_fke);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_uint_eq(x_org, x_fke);
}
END_TEST

START_TEST(s21_sscanf_x_test17) {
  unsigned long int x_org = 0;
  unsigned long int x_fke = 0;
  char str[500] = "-0xFFe";
  char str2[500] = "-0xFFe";
  int n_org = sscanf(str, "%lx", &x_org);
  int n_fke = s21_sscanf(str2, "%lx", &x_fke);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_uint_eq(x_org, x_fke);
}
END_TEST

START_TEST(s21_sscanf_x_test18) {
  unsigned long int x_org = 0;
  unsigned long int x_fke = 0;
  unsigned long int x_org2 = 0;
  unsigned long int x_fke2 = 0;
  char str[500] = "-0xFFe,,,\0AAAa";
  char str2[500] = "-0xFFe,,,\0AAAa";
  int n_org = sscanf(str, "%lx %lx", &x_org, &x_org2);
  int n_fke = s21_sscanf(str2, "%lx %lx", &x_fke, &x_fke2);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_uint_eq(x_org, x_fke);
}
END_TEST

START_TEST(s21_sscanf_x_test19) {
  unsigned long int x_org = 0;
  unsigned long int x_fke = 0;
  unsigned long int x_org2 = 0;
  unsigned long int x_fke2 = 0;
  char str[500] = "-0xFFe,,,\0AAAa";
  char str2[500] = "-0xFFe,,,\0AAAa";
  int n_org = sscanf(str, "%1lx ,%3lx", &x_org, &x_org2);
  int n_fke = s21_sscanf(str2, "%1lx ,%3lx", &x_fke, &x_fke2);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_uint_eq(x_org, x_fke);
}
END_TEST

START_TEST(s21_sscanf_x_test20) {
  unsigned long int x_org = 0;
  unsigned long int x_fke = 0;
  unsigned long int x_org2 = 0;
  unsigned long int x_fke2 = 0;
  char str[500] = "-0xFFFFFe,,,\0AAAa";
  char str2[500] = "-0xFFFFFe,,,\0AAAa";
  int n_org = sscanf(str, "%3lx %2lx", &x_org, &x_org2);
  int n_fke = s21_sscanf(str2, "%3lx %2lx", &x_fke, &x_fke2);
  ck_assert_int_eq(n_org, n_fke);
  ck_assert_uint_eq(x_org, x_fke);
}
END_TEST

// p
START_TEST(s21_sscanf_p_test0) {
  int address;
  void *p_original;
  void *p_fake;
  char str[500];
  char str2[500];
  s21_sprintf(str, "%p", &address);
  s21_sprintf(str2, "%p", &address);
  int n_original = sscanf(str, "%5p", &p_original);
  int n_fake = s21_sscanf(str2, "%5p", &p_fake);
  ck_assert_ptr_eq(p_original, p_fake);
  ck_assert_int_eq(n_fake, n_original);
}
END_TEST

START_TEST(s21_sscanf_p_test1) {
  int address;
  void *p_original;
  void *p_fake;
  char str[500];
  char str2[500];
  s21_sprintf(str, "%p", &address);
  s21_sprintf(str2, "%p", &address);
  int n_original = sscanf(str, "%p", &p_original);
  int n_fake = s21_sscanf(str2, "%p", &p_fake);
  ck_assert_ptr_eq(p_original, p_fake);
  ck_assert_int_eq(n_fake, n_original);
}
END_TEST

START_TEST(s21_sscanf_p_test2) {
  int address;
  void *p_original;
  void *p_fake;
  char str[500];
  char str2[500];
  s21_sprintf(str, "%p1235", &address);
  s21_sprintf(str2, "%p1235", &address);
  int n_original = sscanf(str, "%p", &p_original);
  int n_fake = s21_sscanf(str2, "%p", &p_fake);
  ck_assert_ptr_eq(p_original, p_fake);
  ck_assert_int_eq(n_fake, n_original);
}
END_TEST

START_TEST(s21_sscanf_p_test3) {
  int address;
  void *p_original;
  void *p_fake;
  int n_original = 0;
  int n_fake = 0;
  char str[500];
  char str2[500];
  s21_sprintf(str, "%p", &address);
  s21_strcpy(str2, str);
  int n_speccific_org = sscanf(str, "%5p%n", &p_original, &n_speccific_org);
  int n_speccific_fke = s21_sscanf(str2, "%5p%n", &p_fake, &n_speccific_fke);
  ck_assert_ptr_eq(p_original, p_fake);
  ck_assert_int_eq(n_speccific_fke, n_speccific_org);
  ck_assert_int_eq(n_original, n_fake);
}
END_TEST

START_TEST(test_c_10) {
  const char str[] = "вальс";
  const char str_[] = "вальс";
  const char format[] = "%lc";

  wchar_t c1, c1_;
  int res1 = s21_sscanf(str, format, &c1);
  int res2 = sscanf(str_, format, &c1_);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c1_);
}
END_TEST
START_TEST(test_c_11) {
  (void)setlocale(LC_ALL, "");
  const char str[] = "вальс";
  const char str_[] = "вальс";
  const char format[] = "%lc%lc%lc";

  wchar_t c1, c1_;
  wchar_t c2, c2_;
  wchar_t c3, c3_;
  int res1 = s21_sscanf(str, format, &c1, &c2, &c3);
  int res2 = sscanf(str_, format, &c1_, &c2_, &c3_);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c1_);
  ck_assert_int_eq(c2, c2_);
  ck_assert_int_eq(c3, c3_);
}
END_TEST

START_TEST(test_c_12) {
  (void)setlocale(LC_ALL, "");
  const char str[] = "诶вальс";
  const char str_[] = "诶вальс";
  const char format[] = "%lc%lc";

  wchar_t c1, c1_;
  wchar_t c2, c2_;
  int res1 = s21_sscanf(str, format, &c1, &c2);
  int res2 = sscanf(str_, format, &c1_, &c2_);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c1_);
  ck_assert_int_eq(c2, c2_);
}
END_TEST
START_TEST(test_s_10) {
  const char str[] = "вальс";
  const char str_[] = "вальс";
  const char format[] = "%ls";

  wchar_t c1[500] = {};
  wchar_t c1_[500] = {};
  int res1 = s21_sscanf(str, format, c1);
  int res2 = sscanf(str_, format, c1_);
  ck_assert_int_eq(res1, res2);
  ck_assert_mem_eq(c1, c1_, 10);
  ck_assert_int_eq(c1[1], c1_[1]);
}
END_TEST
//  ++++++++++++++++++++=

Suite *s21_string_suite() {
  Suite *s = suite_create("s21_string_h");
  TCase *tc_core = tcase_create("core");

  tcase_add_test(tc_core, s21_memchr_0);
  tcase_add_test(tc_core, s21_memcmp_1);
  tcase_add_test(tc_core, s21_memcpy_2);
  tcase_add_test(tc_core, s21_memmove_3);
  //  memchr
  tcase_add_test(tc_core, s21_memchr_test);
  tcase_add_test(tc_core, s21_memchr_test_NULL);
  tcase_add_test(tc_core, s21_memchr_test_0);
  tcase_add_test(tc_core, s21_memchr_test4);
  //  memcmp 2
  tcase_add_test(tc_core, s21_memcmp_test_00);
  tcase_add_test(tc_core, s21_memcmp_test_0);
  tcase_add_test(tc_core, s21_memcmp_test_1);
  tcase_add_test(tc_core, s21_memcmp_test_2);
  tcase_add_test(tc_core, s21_memcmp_test_3);
  //  memcpy 3
  tcase_add_test(tc_core, s21_memcpy_tes1);
  tcase_add_test(tc_core, s21_memcpy_test2);
  tcase_add_test(tc_core, s21_memcpy_test3);
  //  memmove 4
  tcase_add_test(tc_core, s21_memmove_test1);
  tcase_add_test(tc_core, s21_memmove_test2);
  tcase_add_test(tc_core, s21_memmove_test3);
  //  memset 5
  tcase_add_test(tc_core, s21_memset_test1);
  tcase_add_test(tc_core, s21_memset_test2);
  tcase_add_test(tc_core, s21_memset_test3);
  //  strcat 6
  tcase_add_test(tc_core, s21_strcat_test1);
  tcase_add_test(tc_core, s21_strcat_test2);
  tcase_add_test(tc_core, s21_strcat_test3);
  tcase_add_test(tc_core, s21_strcat_test4);
  //  strncat 7
  tcase_add_test(tc_core, s21_strncat_test1);
  tcase_add_test(tc_core, s21_strncat_test2);
  tcase_add_test(tc_core, s21_strncat_test3);
  tcase_add_test(tc_core, s21_strncat_test4);
  //  strchr 8
  tcase_add_test(tc_core, s21_strchr_test1);
  tcase_add_test(tc_core, s21_strchr_test2);
  tcase_add_test(tc_core, s21_strchr_test3);
  tcase_add_test(tc_core, s21_strchr_test4);
  //  strcmp 9
  tcase_add_test(tc_core, s21_strcmp_test1);
  tcase_add_test(tc_core, s21_strcmp_test2);
  tcase_add_test(tc_core, s21_strcmp_test3);
  //===========================================
  //  strncmp
  tcase_add_test(tc_core, test_s21_strncmp_1);
  tcase_add_test(tc_core, test_s21_strncmp_2);
  tcase_add_test(tc_core, test_s21_strncmp_3);
  tcase_add_test(tc_core, test_s21_strncmp_4);
  tcase_add_test(tc_core, test_s21_strncmp_5);

  //  strcpy
  tcase_add_test(tc_core, test_s21_strcpy_1);
  tcase_add_test(tc_core, test_s21_strcpy_2);
  tcase_add_test(tc_core, test_s21_strcpy_3);
  //  strncpy
  tcase_add_test(tc_core, test_s21_strncpy_1);
  tcase_add_test(tc_core, test_s21_strncpy_2);
  tcase_add_test(tc_core, test_s21_strncpy_3);
  //  strcsnp
  tcase_add_test(tc_core, test_s21_strcspn_1);
  tcase_add_test(tc_core, test_s21_strcspn_2);
  tcase_add_test(tc_core, test_s21_strcspn_3);
  //  strerror
  tcase_add_test(tc_core, test_s21_strerror_1);
  tcase_add_test(tc_core, test_s21_strerror_2);
  tcase_add_test(tc_core, test_s21_strerror_3);
  //===========================================
  //  strlen 15
  tcase_add_test(tc_core, s21_strlen_test1);
  tcase_add_test(tc_core, s21_strlen_test2);
  tcase_add_test(tc_core, s21_strlen_test3);
  tcase_add_test(tc_core, s21_strlen_test4);
  //  strpbrk 16
  tcase_add_test(tc_core, s21_strpbrk_test1);
  tcase_add_test(tc_core, s21_strpbrk_test2);
  tcase_add_test(tc_core, s21_strpbrk_test3);
  tcase_add_test(tc_core, s21_strpbrk_test4);
  tcase_add_test(tc_core, s21_strpbrk_test5);
  //  strrchr 17
  tcase_add_test(tc_core, s21_strrchr_test1);
  tcase_add_test(tc_core, s21_strrchr_test2);
  tcase_add_test(tc_core, s21_strrchr_test3);
  tcase_add_test(tc_core, s21_strrchr_test4);
  tcase_add_test(tc_core, s21_strrchr_test5);
  //  strspn 18
  tcase_add_test(tc_core, s21_strspn_test1);
  tcase_add_test(tc_core, s21_strspn_test2);
  tcase_add_test(tc_core, s21_strspn_test3);
  tcase_add_test(tc_core, s21_strspn_test4);
  tcase_add_test(tc_core, s21_strspn_test5);
  tcase_add_test(tc_core, s21_strspn_test6);
  tcase_add_test(tc_core, s21_strspn_test7);
  tcase_add_test(tc_core, s21_strspn_test8);
  //  strstr 19
  tcase_add_test(tc_core, s21_strstr_test0);
  tcase_add_test(tc_core, s21_strstr_test1);
  tcase_add_test(tc_core, s21_strstr_test2);
  tcase_add_test(tc_core, s21_strstr_test3);
  tcase_add_test(tc_core, s21_strstr_test4);
  tcase_add_test(tc_core, s21_strstr_test5);
  //  s21_to_upper
  tcase_add_test(tc_core, s21_to_upper_test_empty);
  tcase_add_test(tc_core, s21_to_upper_test_null);
  tcase_add_test(tc_core, s21_to_upper_test_normal);
  tcase_add_test(tc_core, s21_to_upper_test_zero);
  tcase_add_test(tc_core, s21_to_upper_test_numbers);
  //  s21_to_lower
  tcase_add_test(tc_core, s21_to_lower_test_empty);
  tcase_add_test(tc_core, s21_to_lower_test_null);
  tcase_add_test(tc_core, s21_to_lower_test_normal);
  tcase_add_test(tc_core, s21_to_lower_test_zero);
  tcase_add_test(tc_core, s21_to_lower_test_numbers);
  //  s21_insert
  tcase_add_test(tc_core, s21_insert_test_empty);
  tcase_add_test(tc_core, s21_insert_test_empty_null);
  tcase_add_test(tc_core, s21_insert_test_str_empty);
  tcase_add_test(tc_core, s21_insert_test_src_empty);
  tcase_add_test(tc_core, s21_insert_test_str_outofsrc_null);
  tcase_add_test(tc_core, s21_insert_test_normal);
  tcase_add_test(tc_core, s21_insert_test_normal_start);
  tcase_add_test(tc_core, s21_insert_test_normal_end);
  tcase_add_test(tc_core, s21_insert_test_0);
  tcase_add_test(tc_core, s21_insert_test_1);
  tcase_add_test(tc_core, s21_insert_test_2);
  tcase_add_test(tc_core, s21_insert_test_3);
  tcase_add_test(tc_core, s21_insert_test_4);
  tcase_add_test(tc_core, s21_insert_test_5);
  tcase_add_test(tc_core, s21_insert_test_6);
  //  s21_trim
  tcase_add_test(tc_core, s21_trim_test_normal);
  tcase_add_test(tc_core, s21_trim_test_normal_no_trim);
  tcase_add_test(tc_core, s21_trim_test_src_empty);
  tcase_add_test(tc_core, s21_trim_test_chars_empty);
  tcase_add_test(tc_core, s21_trim_test_src_null);
  tcase_add_test(tc_core, s21_trim_test_chars_null);
  tcase_add_test(tc_core, s21_trim_test_0);
  tcase_add_test(tc_core, s21_trim_test_1);
  tcase_add_test(tc_core, s21_trim_test_2);
  //  s21_strtok
  tcase_add_test(tc_core, s21_strtok_test_normal);
  tcase_add_test(tc_core, s21_strtok_test_delim_empty);
  tcase_add_test(tc_core, s21_strtok_test_str_empty);
  tcase_add_test(tc_core, s21_strtok_test_str_equal_to_delim);
  tcase_add_test(tc_core, s21_strtok_test_delim_changed);
  tcase_add_test(tc_core, s21_strtok_test_delim_not_found);

  suite_add_tcase(s, tc_core);
  return s;
}
// +++++++++++++++++++++++++++++++++++++++

//  ++++++++++++++++++++++++++++++++++++++S P R I N T F
Suite *s21_sprintf_suite() {
  Suite *s = suite_create("s21_sprintf");
  TCase *tc_sprintf = tcase_create("s21_sprintf");

  //  char tests
  tcase_add_test(tc_sprintf, s21_sprintf_c_tests_1);
  tcase_add_test(tc_sprintf, s21_sprintf_c_tests_2);
  tcase_add_test(tc_sprintf, s21_sprintf_c_tests_3);
  tcase_add_test(tc_sprintf, s21_sprintf_c_tests_4);
  tcase_add_test(tc_sprintf, s21_sprintf_c_tests_5);
  tcase_add_test(tc_sprintf, s21_sprintf_c_tests_6);
  //  d tests
  tcase_add_test(tc_sprintf, s21_sprintf_d_test0);
  tcase_add_test(tc_sprintf, s21_sprintf_d_test1);
  tcase_add_test(tc_sprintf, s21_sprintf_d_test2);
  tcase_add_test(tc_sprintf, s21_sprintf_d_test3);
  tcase_add_test(tc_sprintf, s21_sprintf_d_test4);
  tcase_add_test(tc_sprintf, s21_sprintf_d_test5);
  tcase_add_test(tc_sprintf, s21_sprintf_d_test6);
  tcase_add_test(tc_sprintf, s21_sprintf_d_test7);
  tcase_add_test(tc_sprintf, s21_sprintf_d_test8);
  tcase_add_test(tc_sprintf, s21_sprintf_d_test9);
  tcase_add_test(tc_sprintf, s21_sprintf_d_test99);
  tcase_add_test(tc_sprintf, s21_sprintf_d_test10);
  tcase_add_test(tc_sprintf, s21_sprintf_d_test11);
  tcase_add_test(tc_sprintf, s21_sprintf_d_test12);
  tcase_add_test(tc_sprintf, s21_sprintf_d_test13);
  tcase_add_test(tc_sprintf, s21_sprintf_d_test14);
  tcase_add_test(tc_sprintf, s21_sprintf_d_test15);
  //  i tests
  tcase_add_test(tc_sprintf, s21_sprintf_i_test0);
  tcase_add_test(tc_sprintf, s21_sprintf_i_test1);
  tcase_add_test(tc_sprintf, s21_sprintf_i_test2);
  tcase_add_test(tc_sprintf, s21_sprintf_i_test3);
  tcase_add_test(tc_sprintf, s21_sprintf_i_test4);
  tcase_add_test(tc_sprintf, s21_sprintf_i_test5);
  tcase_add_test(tc_sprintf, s21_sprintf_i_test6);
  tcase_add_test(tc_sprintf, s21_sprintf_i_test7);
  tcase_add_test(tc_sprintf, s21_sprintf_i_test8);
  tcase_add_test(tc_sprintf, s21_sprintf_i_test9);
  tcase_add_test(tc_sprintf, s21_sprintf_i_test99);
  tcase_add_test(tc_sprintf, s21_sprintf_i_test10);
  tcase_add_test(tc_sprintf, s21_sprintf_i_test11);
  tcase_add_test(tc_sprintf, s21_sprintf_i_test12);
  tcase_add_test(tc_sprintf, s21_sprintf_i_test13);
  tcase_add_test(tc_sprintf, s21_sprintf_i_test14);
  tcase_add_test(tc_sprintf, s21_sprintf_i_test15);
  //  e tests
  tcase_add_test(tc_sprintf, s21_sprintf_e_test0);
  tcase_add_test(tc_sprintf, s21_sprintf_e_test1);
  tcase_add_test(tc_sprintf, s21_sprintf_e_test2);
  tcase_add_test(tc_sprintf, s21_sprintf_e_test3);
  tcase_add_test(tc_sprintf, s21_sprintf_e_test4);
  tcase_add_test(tc_sprintf, s21_sprintf_e_test5);
  tcase_add_test(tc_sprintf, s21_sprintf_e_test6);
  tcase_add_test(tc_sprintf, s21_sprintf_e_test7);
  tcase_add_test(tc_sprintf, s21_sprintf_e_test8);
  tcase_add_test(tc_sprintf, s21_sprintf_e_test9);
  tcase_add_test(tc_sprintf, s21_sprintf_e_test10);
  //  E tests
  tcase_add_test(tc_sprintf, s21_sprintf_E_test0);
  tcase_add_test(tc_sprintf, s21_sprintf_E_test1);
  tcase_add_test(tc_sprintf, s21_sprintf_E_test2);
  tcase_add_test(tc_sprintf, s21_sprintf_E_test3);
  tcase_add_test(tc_sprintf, s21_sprintf_E_test4);
  tcase_add_test(tc_sprintf, s21_sprintf_E_test5);
  tcase_add_test(tc_sprintf, s21_sprintf_E_test6);
  tcase_add_test(tc_sprintf, s21_sprintf_E_test7);
  tcase_add_test(tc_sprintf, s21_sprintf_E_test8);
  tcase_add_test(tc_sprintf, s21_sprintf_E_test9);
  tcase_add_test(tc_sprintf, s21_sprintf_E_test10);
  tcase_add_test(tc_sprintf, s21_sprintf_E_test11);
  tcase_add_test(tc_sprintf, s21_sprintf_E_test12);
  //  f tests
  tcase_add_test(tc_sprintf, s21_sprintf_f_test0);
  tcase_add_test(tc_sprintf, s21_sprintf_f_test1);
  tcase_add_test(tc_sprintf, s21_sprintf_f_test2);
  tcase_add_test(tc_sprintf, s21_sprintf_f_test3);
  tcase_add_test(tc_sprintf, s21_sprintf_f_test33);
  tcase_add_test(tc_sprintf, s21_sprintf_f_test4);
  tcase_add_test(tc_sprintf, s21_sprintf_f_test44);
  tcase_add_test(tc_sprintf, s21_sprintf_f_test5);
  tcase_add_test(tc_sprintf, s21_sprintf_f_test6);
  tcase_add_test(tc_sprintf, s21_sprintf_f_test7);
  tcase_add_test(tc_sprintf, s21_sprintf_f_test8);
  tcase_add_test(tc_sprintf, s21_sprintf_f_test9);
  tcase_add_test(tc_sprintf, s21_sprintf_f_test10);
  tcase_add_test(tc_sprintf, s21_sprintf_f_test11);
  tcase_add_test(tc_sprintf, s21_sprintf_f_test12);
  tcase_add_test(tc_sprintf, s21_sprintf_f_test13);
  tcase_add_test(tc_sprintf, s21_sprintf_f_test14);
  tcase_add_test(tc_sprintf, s21_sprintf_f_test15);
  tcase_add_test(tc_sprintf, s21_sprintf_f_test16);
  tcase_add_test(tc_sprintf, s21_sprintf_f_test17);
  tcase_add_test(tc_sprintf, s21_sprintf_f_test18);
  tcase_add_test(tc_sprintf, s21_sprintf_f_test19);
  tcase_add_test(tc_sprintf, s21_sprintf_f_test20);
  tcase_add_test(tc_sprintf, s21_sprintf_f_test21);
  tcase_add_test(tc_sprintf, s21_sprintf_f_test22);
  tcase_add_test(tc_sprintf, s21_sprintf_f_test23);

  //  g tests
  tcase_add_test(tc_sprintf, s21_sprintf_g_test0);
  tcase_add_test(tc_sprintf, s21_sprintf_g_test1);
  tcase_add_test(tc_sprintf, s21_sprintf_g_test2);
  tcase_add_test(tc_sprintf, s21_sprintf_g_test3);
  tcase_add_test(tc_sprintf, s21_sprintf_g_test33);
  tcase_add_test(tc_sprintf, s21_sprintf_g_test4);
  tcase_add_test(tc_sprintf, s21_sprintf_g_test44);
  tcase_add_test(tc_sprintf, s21_sprintf_g_test5);
  tcase_add_test(tc_sprintf, s21_sprintf_g_test6);
  tcase_add_test(tc_sprintf, s21_sprintf_g_test7);
  tcase_add_test(tc_sprintf, s21_sprintf_g_test8);
  tcase_add_test(tc_sprintf, s21_sprintf_g_test9);
  tcase_add_test(tc_sprintf, s21_sprintf_g_test10);
  tcase_add_test(tc_sprintf, s21_sprintf_g_test11);
  tcase_add_test(tc_sprintf, s21_sprintf_g_test12);
  tcase_add_test(tc_sprintf, s21_sprintf_g_test13);
  tcase_add_test(tc_sprintf, s21_sprintf_g_test14);
  tcase_add_test(tc_sprintf, s21_sprintf_g_test15);
  tcase_add_test(tc_sprintf, s21_sprintf_g_test16);
  tcase_add_test(tc_sprintf, s21_sprintf_g_test17);
  tcase_add_test(tc_sprintf, s21_sprintf_g_test18);
  tcase_add_test(tc_sprintf, s21_sprintf_g_test19);
  tcase_add_test(tc_sprintf, s21_sprintf_g_test20);
  tcase_add_test(tc_sprintf, s21_sprintf_g_test21);
  tcase_add_test(tc_sprintf, s21_sprintf_g_test22);
  tcase_add_test(tc_sprintf, s21_sprintf_g_test23);

  //  G tests
  tcase_add_test(tc_sprintf, s21_sprintf_G_test0);
  tcase_add_test(tc_sprintf, s21_sprintf_G_test1);
  tcase_add_test(tc_sprintf, s21_sprintf_G_test2);
  tcase_add_test(tc_sprintf, s21_sprintf_G_test3);
  tcase_add_test(tc_sprintf, s21_sprintf_G_test33);
  tcase_add_test(tc_sprintf, s21_sprintf_G_test4);
  tcase_add_test(tc_sprintf, s21_sprintf_G_test44);
  tcase_add_test(tc_sprintf, s21_sprintf_G_test5);
  tcase_add_test(tc_sprintf, s21_sprintf_G_test6);
  tcase_add_test(tc_sprintf, s21_sprintf_G_test7);
  tcase_add_test(tc_sprintf, s21_sprintf_G_test8);
  tcase_add_test(tc_sprintf, s21_sprintf_G_test9);
  tcase_add_test(tc_sprintf, s21_sprintf_G_test10);
  tcase_add_test(tc_sprintf, s21_sprintf_G_test11);
  tcase_add_test(tc_sprintf, s21_sprintf_G_test12);
  tcase_add_test(tc_sprintf, s21_sprintf_G_test13);
  tcase_add_test(tc_sprintf, s21_sprintf_G_test14);
  tcase_add_test(tc_sprintf, s21_sprintf_G_test15);
  tcase_add_test(tc_sprintf, s21_sprintf_G_test16);
  tcase_add_test(tc_sprintf, s21_sprintf_G_test17);
  tcase_add_test(tc_sprintf, s21_sprintf_G_test18);
  tcase_add_test(tc_sprintf, s21_sprintf_G_test19);
  tcase_add_test(tc_sprintf, s21_sprintf_G_test20);
  tcase_add_test(tc_sprintf, s21_sprintf_G_test21);
  tcase_add_test(tc_sprintf, s21_sprintf_G_test22);
  tcase_add_test(tc_sprintf, s21_sprintf_G_test23);

  //  o tests
  tcase_add_test(tc_sprintf, s21_sprintf_o_test0);
  tcase_add_test(tc_sprintf, s21_sprintf_o_test1);
  tcase_add_test(tc_sprintf, s21_sprintf_o_test2);
  tcase_add_test(tc_sprintf, s21_sprintf_o_test3);
  tcase_add_test(tc_sprintf, s21_sprintf_o_test4);
  tcase_add_test(tc_sprintf, s21_sprintf_o_test5);
  tcase_add_test(tc_sprintf, s21_sprintf_o_test6);
  tcase_add_test(tc_sprintf, s21_sprintf_o_test7);
  tcase_add_test(tc_sprintf, s21_sprintf_o_test8);
  tcase_add_test(tc_sprintf, s21_sprintf_o_test88);
  tcase_add_test(tc_sprintf, s21_sprintf_o_test9);
  tcase_add_test(tc_sprintf, s21_sprintf_o_test99);
  tcase_add_test(tc_sprintf, s21_sprintf_o_test10);
  tcase_add_test(tc_sprintf, s21_sprintf_o_test11);
  tcase_add_test(tc_sprintf, s21_sprintf_o_test12);
  tcase_add_test(tc_sprintf, s21_sprintf_o_test13);
  tcase_add_test(tc_sprintf, s21_sprintf_o_test14);
  tcase_add_test(tc_sprintf, s21_sprintf_o_test15);

  //  s tests
  tcase_add_test(tc_sprintf, s21_sprintf_s_test);
  tcase_add_test(tc_sprintf, s21_sprintf_s_test0);
  tcase_add_test(tc_sprintf, s21_sprintf_s_test1);
  tcase_add_test(tc_sprintf, s21_sprintf_s_test2);
  tcase_add_test(tc_sprintf, s21_sprintf_s_test3);
  tcase_add_test(tc_sprintf, s21_sprintf_s_test4);
  tcase_add_test(tc_sprintf, s21_sprintf_s_test5);

  //  uint tests
  tcase_add_test(tc_sprintf, s21_sprintf_u_test0);
  tcase_add_test(tc_sprintf, s21_sprintf_u_test1);
  tcase_add_test(tc_sprintf, s21_sprintf_u_test2);
  tcase_add_test(tc_sprintf, s21_sprintf_u_test3);
  tcase_add_test(tc_sprintf, s21_sprintf_u_test4);
  tcase_add_test(tc_sprintf, s21_sprintf_u_test5);
  tcase_add_test(tc_sprintf, s21_sprintf_u_test6);
  tcase_add_test(tc_sprintf, s21_sprintf_u_test7);
  tcase_add_test(tc_sprintf, s21_sprintf_u_test8);
  tcase_add_test(tc_sprintf, s21_sprintf_u_test88);
  tcase_add_test(tc_sprintf, s21_sprintf_u_test9);
  tcase_add_test(tc_sprintf, s21_sprintf_u_test99);
  tcase_add_test(tc_sprintf, s21_sprintf_u_test10);
  tcase_add_test(tc_sprintf, s21_sprintf_u_test11);
  tcase_add_test(tc_sprintf, s21_sprintf_u_test12);
  tcase_add_test(tc_sprintf, s21_sprintf_u_test13);
  tcase_add_test(tc_sprintf, s21_sprintf_u_test14);
  tcase_add_test(tc_sprintf, s21_sprintf_u_test15);

  //  x tests
  tcase_add_test(tc_sprintf, s21_sprintf_x_test0);
  tcase_add_test(tc_sprintf, s21_sprintf_x_test1);
  tcase_add_test(tc_sprintf, s21_sprintf_x_test2);
  tcase_add_test(tc_sprintf, s21_sprintf_x_test3);
  tcase_add_test(tc_sprintf, s21_sprintf_x_test4);
  tcase_add_test(tc_sprintf, s21_sprintf_x_test5);
  tcase_add_test(tc_sprintf, s21_sprintf_x_test6);
  tcase_add_test(tc_sprintf, s21_sprintf_x_test7);
  tcase_add_test(tc_sprintf, s21_sprintf_x_test8);
  tcase_add_test(tc_sprintf, s21_sprintf_x_test9);
  tcase_add_test(tc_sprintf, s21_sprintf_x_test99);
  tcase_add_test(tc_sprintf, s21_sprintf_x_test10);
  tcase_add_test(tc_sprintf, s21_sprintf_x_test11);
  tcase_add_test(tc_sprintf, s21_sprintf_x_test12);
  tcase_add_test(tc_sprintf, s21_sprintf_x_test13);
  tcase_add_test(tc_sprintf, s21_sprintf_x_test14);
  tcase_add_test(tc_sprintf, s21_sprintf_x_test15);

  //  X tests
  tcase_add_test(tc_sprintf, s21_sprintf_X_test0);
  tcase_add_test(tc_sprintf, s21_sprintf_X_test1);
  tcase_add_test(tc_sprintf, s21_sprintf_X_test2);
  tcase_add_test(tc_sprintf, s21_sprintf_X_test3);
  tcase_add_test(tc_sprintf, s21_sprintf_X_test4);
  tcase_add_test(tc_sprintf, s21_sprintf_X_test5);
  tcase_add_test(tc_sprintf, s21_sprintf_X_test6);
  tcase_add_test(tc_sprintf, s21_sprintf_X_test7);
  tcase_add_test(tc_sprintf, s21_sprintf_X_test8);
  tcase_add_test(tc_sprintf, s21_sprintf_X_test9);
  tcase_add_test(tc_sprintf, s21_sprintf_X_test99);
  tcase_add_test(tc_sprintf, s21_sprintf_X_test10);
  tcase_add_test(tc_sprintf, s21_sprintf_X_test11);
  tcase_add_test(tc_sprintf, s21_sprintf_X_test12);
  tcase_add_test(tc_sprintf, s21_sprintf_X_test13);
  tcase_add_test(tc_sprintf, s21_sprintf_X_test14);
  tcase_add_test(tc_sprintf, s21_sprintf_X_test15);

  //  p tests
  tcase_add_test(tc_sprintf, s21_sprintf_p_test0);
  tcase_add_test(tc_sprintf, s21_sprintf_p_test1);
  tcase_add_test(tc_sprintf, s21_sprintf_p_test2);
  tcase_add_test(tc_sprintf, s21_sprintf_p_test3);
  tcase_add_test(tc_sprintf, s21_sprintf_p_test4);

  //  n tests
  tcase_add_test(tc_sprintf, s21_sprintf_n_test0);
  tcase_add_test(tc_sprintf, s21_sprintf_n_test1);

  //  mixed
  tcase_add_test(tc_sprintf, s21_sprintf_mixed_test0);
  tcase_add_test(tc_sprintf, s21_sprintf_mixed_test1);
  tcase_add_test(tc_sprintf, g_many);
  tcase_add_test(tc_sprintf, g_zero);
  tcase_add_test(tc_sprintf, c_many_lengths);
  ` tcase_add_test(tc_sprintf, d_many_lengths);
  tcase_add_test(tc_sprintf, e_many_lengths);
  tcase_add_test(tc_sprintf, f_many_lengths);
  tcase_add_test(tc_sprintf, g_many_lengths);
  tcase_add_test(tc_sprintf, o_many_lengths);
  tcase_add_test(tc_sprintf, s_many_lengths);
  tcase_add_test(tc_sprintf, u_many_lengths);
  tcase_add_test(tc_sprintf, x_many_lengths);
  tcase_add_test(tc_sprintf, p_many_lengths);
  tcase_add_test(tc_sprintf, percent_many_lengths);
  tcase_add_test(tc_sprintf, s_s21_null);
  tcase_add_test(tc_sprintf, wcs_s21_null);
  tcase_add_test(tc_sprintf, percent_final);

  suite_add_tcase(s, tc_sprintf);
  return s;
}

Suite *s21_sscanf_suite(void) {
  Suite *s;
  TCase *tc_sscanf;
  s = suite_create("s21_sscanf");
  tc_sscanf = tcase_create("s21_sscanf");
  // c
  tcase_add_test(tc_sscanf, s21_sscanf_c_test0);
  tcase_add_test(tc_sscanf, s21_sscanf_c_test1);
  tcase_add_test(tc_sscanf, s21_sscanf_c_test2);
  tcase_add_test(tc_sscanf, s21_sscanf_c_test3);
  tcase_add_test(tc_sscanf, s21_sscanf_c_test4);
  tcase_add_test(tc_sscanf, s21_sscanf_c_test5);
  tcase_add_test(tc_sscanf, s21_sscanf_c_test6);

  tcase_add_test(tc_sscanf, test_c_10);
  tcase_add_test(tc_sscanf, test_c_11);
  tcase_add_test(tc_sscanf, test_c_12);

  tcase_add_test(tc_sscanf, test_s_10);

  //  d
  tcase_add_test(tc_sscanf, s21_sscanf_d_test0);
  tcase_add_test(tc_sscanf, s21_sscanf_d_test1);
  tcase_add_test(tc_sscanf, s21_sscanf_d_test2);
  tcase_add_test(tc_sscanf, s21_sscanf_d_test3);
  tcase_add_test(tc_sscanf, s21_sscanf_d_test4);
  tcase_add_test(tc_sscanf, s21_sscanf_d_test5);
  tcase_add_test(tc_sscanf, s21_sscanf_d_test6);
  tcase_add_test(tc_sscanf, s21_sscanf_d_test7);
  tcase_add_test(tc_sscanf, s21_sscanf_d_test8);
  tcase_add_test(tc_sscanf, s21_sscanf_d_test9);

  // i
  tcase_add_test(tc_sscanf, s21_sscanf_i_test0);
  tcase_add_test(tc_sscanf, s21_sscanf_i_test1);
  tcase_add_test(tc_sscanf, s21_sscanf_i_test2);
  tcase_add_test(tc_sscanf, s21_sscanf_i_test3);
  tcase_add_test(tc_sscanf, s21_sscanf_i_test4);
  tcase_add_test(tc_sscanf, s21_sscanf_i_test5);
  tcase_add_test(tc_sscanf, s21_sscanf_i_test6);
  tcase_add_test(tc_sscanf, s21_sscanf_i_test7);
  tcase_add_test(tc_sscanf, s21_sscanf_i_test8);
  tcase_add_test(tc_sscanf, s21_sscanf_i_test88);
  tcase_add_test(tc_sscanf, s21_sscanf_i_test9);
  tcase_add_test(tc_sscanf, s21_sscanf_i_test10);

  // e
  tcase_add_test(tc_sscanf, s21_sscanf_e_test0);
  tcase_add_test(tc_sscanf, s21_sscanf_e_test1);
  tcase_add_test(tc_sscanf, s21_sscanf_e_test2);
  tcase_add_test(tc_sscanf, s21_sscanf_e_test3);
  tcase_add_test(tc_sscanf, s21_sscanf_e_test4);
  tcase_add_test(tc_sscanf, s21_sscanf_e_test5);
  tcase_add_test(tc_sscanf, s21_sscanf_e_test6);
  tcase_add_test(tc_sscanf, s21_sscanf_e_test7);
  tcase_add_test(tc_sscanf, s21_sscanf_e_test8);
  tcase_add_test(tc_sscanf, s21_sscanf_e_test9);

  // E
  tcase_add_test(tc_sscanf, s21_sscanf_E_test0);
  tcase_add_test(tc_sscanf, s21_sscanf_E_test1);
  tcase_add_test(tc_sscanf, s21_sscanf_E_test2);
  tcase_add_test(tc_sscanf, s21_sscanf_E_test3);
  tcase_add_test(tc_sscanf, s21_sscanf_E_test4);
  tcase_add_test(tc_sscanf, s21_sscanf_E_test5);
  tcase_add_test(tc_sscanf, s21_sscanf_E_test6);
  tcase_add_test(tc_sscanf, s21_sscanf_E_test7);
  tcase_add_test(tc_sscanf, s21_sscanf_E_test8);
  tcase_add_test(tc_sscanf, s21_sscanf_E_test9);

  // f
  tcase_add_test(tc_sscanf, s21_sscanf_f_test0);
  tcase_add_test(tc_sscanf, s21_sscanf_f_test1);
  tcase_add_test(tc_sscanf, s21_sscanf_f_test2);
  tcase_add_test(tc_sscanf, s21_sscanf_f_test3);
  tcase_add_test(tc_sscanf, s21_sscanf_f_test4);
  tcase_add_test(tc_sscanf, s21_sscanf_f_test5);
  tcase_add_test(tc_sscanf, s21_sscanf_f_test6);
  tcase_add_test(tc_sscanf, s21_sscanf_f_test7);
  tcase_add_test(tc_sscanf, s21_sscanf_f_test8);
  tcase_add_test(tc_sscanf, s21_sscanf_f_test9);
  tcase_add_test(tc_sscanf, s21_sscanf_f_test10);
  tcase_add_test(tc_sscanf, s21_sscanf_f_test11);
  tcase_add_test(tc_sscanf, s21_sscanf_f_test12);

  // g

  tcase_add_test(tc_sscanf, s21_sscanf_g_test0);
  tcase_add_test(tc_sscanf, s21_sscanf_g_test1);
  tcase_add_test(tc_sscanf, s21_sscanf_g_test2);
  tcase_add_test(tc_sscanf, s21_sscanf_g_test3);
  tcase_add_test(tc_sscanf, s21_sscanf_g_test4);
  tcase_add_test(tc_sscanf, s21_sscanf_g_test5);
  tcase_add_test(tc_sscanf, s21_sscanf_g_test6);
  tcase_add_test(tc_sscanf, s21_sscanf_g_test7);
  tcase_add_test(tc_sscanf, s21_sscanf_g_test8);
  tcase_add_test(tc_sscanf, s21_sscanf_g_test9);
  tcase_add_test(tc_sscanf, s21_sscanf_g_test10);
  tcase_add_test(tc_sscanf, s21_sscanf_g_test11);

  // G
  tcase_add_test(tc_sscanf, s21_sscanf_G_test0);
  tcase_add_test(tc_sscanf, s21_sscanf_G_test1);
  tcase_add_test(tc_sscanf, s21_sscanf_G_test2);
  tcase_add_test(tc_sscanf, s21_sscanf_G_test3);
  tcase_add_test(tc_sscanf, s21_sscanf_G_test4);
  tcase_add_test(tc_sscanf, s21_sscanf_G_test5);
  tcase_add_test(tc_sscanf, s21_sscanf_G_test6);
  tcase_add_test(tc_sscanf, s21_sscanf_G_test7);
  tcase_add_test(tc_sscanf, s21_sscanf_G_test8);
  tcase_add_test(tc_sscanf, s21_sscanf_G_test9);
  tcase_add_test(tc_sscanf, s21_sscanf_G_test10);
  tcase_add_test(tc_sscanf, s21_sscanf_G_test11);

  // o
  tcase_add_test(tc_sscanf, s21_sscanf_o_test0);
  tcase_add_test(tc_sscanf, s21_sscanf_o_test1);
  tcase_add_test(tc_sscanf, s21_sscanf_o_test2);
  tcase_add_test(tc_sscanf, s21_sscanf_o_test3);

  // s
  tcase_add_test(tc_sscanf, s21_sscanf_s_test0);
  tcase_add_test(tc_sscanf, s21_sscanf_s_test1);
  tcase_add_test(tc_sscanf, s21_sscanf_s_test2);
  tcase_add_test(tc_sscanf, s21_sscanf_s_test3);
  tcase_add_test(tc_sscanf, s21_sscanf_s_test4);
  tcase_add_test(tc_sscanf, s21_sscanf_s_test5);

  // u
  tcase_add_test(tc_sscanf, s21_sscanf_u_test0);
  tcase_add_test(tc_sscanf, s21_sscanf_u_test1);
  tcase_add_test(tc_sscanf, s21_sscanf_u_test2);
  tcase_add_test(tc_sscanf, s21_sscanf_u_test3);
  tcase_add_test(tc_sscanf, s21_sscanf_u_test4);
  tcase_add_test(tc_sscanf, s21_sscanf_u_test5);
  tcase_add_test(tc_sscanf, s21_sscanf_u_test6);
  tcase_add_test(tc_sscanf, s21_sscanf_u_test7);
  tcase_add_test(tc_sscanf, s21_sscanf_u_test8);
  tcase_add_test(tc_sscanf, s21_sscanf_u_test9);
  tcase_add_test(tc_sscanf, s21_sscanf_u_test10);
  tcase_add_test(tc_sscanf, s21_sscanf_u_test11);
  tcase_add_test(tc_sscanf, s21_sscanf_u_test12);
  tcase_add_test(tc_sscanf, s21_sscanf_u_test13);
  tcase_add_test(tc_sscanf, s21_sscanf_u_test14);

  // X
  tcase_add_test(tc_sscanf, s21_sscanf_X_test0);
  tcase_add_test(tc_sscanf, s21_sscanf_X_test1);
  tcase_add_test(tc_sscanf, s21_sscanf_X_test2);
  tcase_add_test(tc_sscanf, s21_sscanf_X_test3);
  tcase_add_test(tc_sscanf, s21_sscanf_X_test4);
  tcase_add_test(tc_sscanf, s21_sscanf_X_test5);
  tcase_add_test(tc_sscanf, s21_sscanf_X_test6);
  tcase_add_test(tc_sscanf, s21_sscanf_X_test7);
  tcase_add_test(tc_sscanf, s21_sscanf_X_test8);
  tcase_add_test(tc_sscanf, s21_sscanf_X_test9);
  tcase_add_test(tc_sscanf, s21_sscanf_X_test10);
  tcase_add_test(tc_sscanf, s21_sscanf_X_test11);
  tcase_add_test(tc_sscanf, s21_sscanf_X_test12);
  tcase_add_test(tc_sscanf, s21_sscanf_X_test13);
  tcase_add_test(tc_sscanf, s21_sscanf_X_test14);
  tcase_add_test(tc_sscanf, s21_sscanf_X_test15);
  tcase_add_test(tc_sscanf, s21_sscanf_X_test16);
  tcase_add_test(tc_sscanf, s21_sscanf_X_test17);
  tcase_add_test(tc_sscanf, s21_sscanf_X_test18);
  tcase_add_test(tc_sscanf, s21_sscanf_X_test19);
  tcase_add_test(tc_sscanf, s21_sscanf_X_test20);

  // x
  tcase_add_test(tc_sscanf, s21_sscanf_x_test0);
  tcase_add_test(tc_sscanf, s21_sscanf_x_test1);
  tcase_add_test(tc_sscanf, s21_sscanf_x_test2);
  tcase_add_test(tc_sscanf, s21_sscanf_x_test3);
  tcase_add_test(tc_sscanf, s21_sscanf_x_test4);
  tcase_add_test(tc_sscanf, s21_sscanf_x_test5);
  tcase_add_test(tc_sscanf, s21_sscanf_x_test6);
  tcase_add_test(tc_sscanf, s21_sscanf_x_test7);
  tcase_add_test(tc_sscanf, s21_sscanf_x_test8);
  tcase_add_test(tc_sscanf, s21_sscanf_x_test9);
  tcase_add_test(tc_sscanf, s21_sscanf_x_test10);
  tcase_add_test(tc_sscanf, s21_sscanf_x_test11);
  tcase_add_test(tc_sscanf, s21_sscanf_x_test12);
  tcase_add_test(tc_sscanf, s21_sscanf_x_test13);
  tcase_add_test(tc_sscanf, s21_sscanf_x_test14);
  tcase_add_test(tc_sscanf, s21_sscanf_x_test15);
  tcase_add_test(tc_sscanf, s21_sscanf_x_test16);
  tcase_add_test(tc_sscanf, s21_sscanf_x_test17);
  tcase_add_test(tc_sscanf, s21_sscanf_x_test18);
  tcase_add_test(tc_sscanf, s21_sscanf_x_test19);
  tcase_add_test(tc_sscanf, s21_sscanf_x_test20);

  // p
  tcase_add_test(tc_sscanf, s21_sscanf_p_test0);
  tcase_add_test(tc_sscanf, s21_sscanf_p_test1);
  tcase_add_test(tc_sscanf, s21_sscanf_p_test2);
  tcase_add_test(tc_sscanf, s21_sscanf_p_test3);
  suite_add_tcase(s, tc_sscanf);
  return s;
}

int main() {
  (void)setlocale(LC_ALL, "");
  int number_failed = 0;
  Suite *s;
  SRunner *sr;
  s = s21_string_suite();
  sr = srunner_create(s);
  //  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);  //  CK_VERBOSE
  number_failed = number_failed + srunner_ntests_failed(sr);
  srunner_free(sr);

  s = s21_sprintf_suite();
  sr = srunner_create(s);
  //  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);  //  CK_VERBOSE
  number_failed = number_failed + srunner_ntests_failed(sr);
  srunner_free(sr);

  s = s21_sscanf_suite();
  sr = srunner_create(s);
  //  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);  //  CK_VERBOSE
  number_failed = number_failed + srunner_ntests_failed(sr);
  srunner_free(sr);

  return (!number_failed) ? EXIT_SUCCESS : EXIT_FAILURE;
}
