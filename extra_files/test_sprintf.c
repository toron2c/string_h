#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include "s21_string.h"

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

START_TEST(simple_int) {
  char str1[500];
  char str2[500];

  char *format = "This is a simple value %d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(precise_int) {
  char str1[500];
  char str2[500];

  char *format = "%.5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(width_int) {
  char str1[500];
  char str2[500];

  char *format = "%5d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(minus_width_int) {
  char str1[500];
  char str2[500];

  char *format = "%-5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(plus_width_int) {
  char str1[500];
  char str2[500];

  char *format = "%+12d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(padding_int) {
  char str1[500];
  char str2[500];

  char *format = "%012i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(star_width_int) {
  char str1[500];
  char str2[500];

  char *format = "%0*d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(star_precision_int) {
  char str1[500];
  char str2[500];

  char *format = "%0.*i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(many_flags_many_ints) {
  char str1[500];
  char str2[500];

  char format[] = "%0.*i %d %4.*i %013d %d";
  int val = 69;
  ck_assert_int_eq(
      s21_sprintf(str1, format, 5, val, -10431, 13, 5311, 0, -581813581),
      sprintf(str2, format, 5, val, -10431, 13, 5311, 0, -581813581));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flags_long_int) {
  char str1[500];
  char str2[500];

  char *format = "%+5.31li";
  long int val = 698518581899;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flags_short_int) {
  char str1[500];
  char str2[500];

  char *format = "%-16.9hi";
  short int val = 6958;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flags_another_long_int) {
  char str1[500];
  char str2[500];

  char *format = "%0.*ld";
  long val = 8581385185;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(zero_precision_zero_int) {
  char str1[500];
  char str2[500];

  char *format = "%.0d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(space_flag_int) {
  char str1[500];
  char str2[500];

  char *format = "% d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val) {
  char str1[500];
  char str2[500];

  char *format = "%u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_width) {
  char str1[500];
  char str2[500];

  char *format = "%15u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_flags) {
  char str1[500];
  char str2[500];

  char *format = "%-16u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_precision) {
  char str1[500];
  char str2[500];

  char *format = "%.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(unsigned_val_many_flags) {
  char str1[500];
  char str2[500];

  char *format = "% 5.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(unsigned_val_short) {
  char str1[500];
  char str2[500];

  char *format = "%hu";
  unsigned short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_long) {
  char str1[500];
  char str2[500];

  char *format = "%lu";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_many) {
  char str1[500];
  char str2[500];

  char *format = "%lu, %u, %hu, %.5u, %5.u";
  unsigned long int val = 949149114140;
  int n1 = s21_sprintf(str1, format, val, 14, 1441, 14414, 9681);
  int n2 = sprintf(str2, format, val, 14, 1441, 14414, 9681);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(octal_width) {
  char str1[500];
  char str2[500];

  char *format = "%15o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_flags) {
  char str1[500];
  char str2[500];

  char *format = "%-16o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_precision) {
  char str1[500];
  char str2[500];

  char *format = "%.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(octal_many_flags) {
  char str1[500];
  char str2[500];

  char *format = "%-5.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_zero) {
  char str1[500];
  char str2[500];

  char *format = "%o";
  ck_assert_int_eq(s21_sprintf(str1, format, 0), sprintf(str2, format, 0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_hash) {
  char str1[500];
  char str2[500];

  char *format = "%#o";
  int val = 57175;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(octal_short) {
  char str1[500];
  char str2[500];

  char *format = "%hd";
  short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_long) {
  char str1[500];
  char str2[500];

  char *format = "%lo";
  long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_many) {
  char str1[500];
  char str2[500];

  char *format = "%lo, %o, %ho, %.5o, %5.o";
  long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal) {
  char str1[500];
  char str2[500];

  char *format = "%lo";
  long int val = 84518;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_zero) {
  char str1[500];
  char str2[500];

  char *format = "%u";
  ck_assert_int_eq(s21_sprintf(str1, format, 0),
                   sprintf(str2, format, (unsigned)0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hex_width) {
  char str1[500];
  char str2[500];

  char *format = "%5x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hex_flags) {
  char str1[500];
  char str2[500];

  char *format = "%#-10x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_precision) {
  char str1[500];
  char str2[500];

  char *format = "%.15x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_many) {
  char str1[500];
  char str2[500];

  char *format = "%#-10x%x%X%#x%#X%5.5x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val, val, val, val, val),
                   sprintf(str2, format, val, val, val, val, val, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_many_flags) {
  char str1[500];
  char str2[500];

  char *format = "%#-5.10x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_zero) {
  char str1[500];
  char str2[500];

  char *format = "%#x";
  unsigned val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_huge) {
  char str1[500];
  char str2[500];

  char *format = "%#x";
  unsigned val = 18571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_short) {
  char str1[500];
  char str2[500];

  char *format = "%#hx";
  unsigned short val = 12352;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_long) {
  char str1[500];
  char str2[500];

  char *format = "%#lx";
  unsigned long val = 18571757371571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_one_longer_width) {
  char str1[500];
  char str2[500];

  char *format = "%#2x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hex_two_longer_width) {
  char str1[500];
  char str2[500];

  char *format = "%#30x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_char) {
  char str1[500];
  char str2[500];

  char *format = "%c";
  char val = 'X';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(one_precision) {
  char str1[500];
  char str2[500];

  char *format = "%.5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_flags) {
  char str1[500];
  char str2[500];

  char *format = "% -5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_width) {
  char str1[500];
  char str2[500];

  char *format = "%15c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_many) {
  char str1[500];
  char str2[500];

  char *format = "%-5.3c%c%c%c%c Hello! ABOBA";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val, 'c', 'a', 'b', 'b'),
                   sprintf(str2, format, val, 'c', 'a', 'b', 'b'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_many_flags) {
  char str1[500];
  char str2[500];

  char *format = "%-5.3c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string) {
  char str1[500];
  char str2[500];

  char *format = "%s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_precision) {
  char str1[500];
  char str2[500];

  char *format = "%.15s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_width) {
  char str1[500];
  char str2[500];

  char *format = "%15s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_flags) {
  char str1[500];
  char str2[500];

  char *format = "%-15.9s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_long) {
  char str1[500];
  char str2[500];

  char *format = "%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_many) {
  char str1[500];
  char str2[500];

  char *format = "%s%s%s%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  char *s1 = "";
  char *s2 = "87418347813748913749871389480913";
  char *s3 = "HAHAABOBASUCKER";
  ck_assert_int_eq(s21_sprintf(str1, format, val, s1, s2, s3),
                   sprintf(str2, format, val, s1, s2, s3));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(ptr) {
  char str1[500];
  char str2[500];

  char *format = "%p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(ptr_width) {
  char str1[500];
  char str2[500];

  char *format = "%15p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(ptr_precision) {
  char str1[500];
  char str2[500];

  char *format = "%.5p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(null_ptr) {
  char str1[500];
  char str2[500];

  char *format = "%p";
  char *ptr = NULL;
  ck_assert_int_eq(s21_sprintf(str1, format, ptr), sprintf(str2, format, ptr));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(two_percent) {
  char str1[500];
  char str2[500];

  char format[] = "%%%c";
  ck_assert_int_eq(s21_sprintf(str1, format, ' '), sprintf(str2, format, ' '));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_width_huge) {
  char str1[500];
  char str2[500];
  char *val = "kjafdiuhfjahfjdahf";
  char *format = "%120s";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(n_specifier) {
  char str1[500];
  char str2[500];
  int ret = 0;
  char *format = "Hello, my sexy little aboba abobushka abobina %n";
  ck_assert_int_eq(s21_sprintf(str1, format, &ret),
                   sprintf(str2, format, &ret));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_precision) {
  char str1[500];
  char str2[500];
  char *format = "%Lf";
  long double val = 513515.131513515151351;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_width) {
  char str1[500];
  char str2[500];
  char *format = "%10Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_precision_zero) {
  char str1[500];
  char str2[500];
  char *format = "%.0Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(float_precision_empty) {
  char str1[500];
  char str2[500];
  char *format = "%.Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_precision_huge) {
  char str1[500];
  char str2[500];
  char *format = "%.15Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(float_precision_huge_negative) {
  char str1[500];
  char str2[500];
  char *format = "%.15Lf";
  long double val = -15.35581134;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(float_huge) {
  char str1[500];
  char str2[500];
  char *format = "%Lf";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_flags) {
  char str1[500];
  char str2[500];
  char *format = "% f";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_many) {
  char str1[500];
  char str2[500];
  char format[] = "% .0f %.lf %Lf %f %lf %Lf";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 9851.51351;
  long double val5 = 95919539159.53151351131;
  int n1 = s21_sprintf(str1, format, val, val1, val2, val3, val4, val5);
  int n2 = sprintf(str2, format, val, val1, val2, val3, val4, val5);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST
START_TEST(e_precision) {
  char str1[500];
  char str2[500];
  char *format = "%.17Le";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(e_precision_zero) {
  char str1[500];
  char str2[500];
  char *format = "%.0Le";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(e_precision_empty) {
  char str1[500];
  char str2[500];
  char *format = "%.Le";
  long double val = 15.000009121;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(e_precision_huge) {
  char str1[500];
  char str2[500];
  char *format = "%.15Le";
  long double val = 0.000000000000000123;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(e_precision_huge_negative) {
  char str1[500];
  char str2[500];
  char *format = "%.15Le";
  long double val = -15.35581134;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(e_huge) {
  char str1[500];
  char str2[500];
  char *format = "%Le";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(e_flags) {
  char str1[500];
  char str2[500];
  char *format = "%015E";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(e_width) {
  char str1[500];
  char str2[500];
  char *format = "%15e";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(e_many) {
  char str1[500];
  char str2[500];
  char *format = "% .0e %.le %Le %e %le %Le";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 0.094913941;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(E_int) {
  char str1[500];
  char str2[500];
  char *format = "%.17LE";
  long double val = 4134121;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(all_empty) {
  char str1[500];
  char str2[500];
  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(empty_format_and_parameters) {
  char str1[500];
  char str2[500];

  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_char) {
  char str1[500];
  char str2[500];

  ck_assert_int_eq(s21_sprintf(str1, "%c", '\t'), sprintf(str2, "%c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_char) {
  char str1[500];
  char str2[500];

  ck_assert_int_eq(s21_sprintf(str1, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'),
                   sprintf(str2, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_string) {
  char str1[500];
  char str2[500];

  ck_assert_int_eq(s21_sprintf(str1, "%s", "Drop Sega PLS"),
                   sprintf(str2, "%s", "Drop Sega PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_string) {
  char str1[500];
  char str2[500];

  ck_assert_int_eq(
      s21_sprintf(str1, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"),
      sprintf(str2, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_dec) {
  char str1[500];
  char str2[500];

  ck_assert_int_eq(s21_sprintf(str1, "%d", 666), sprintf(str2, "%d", 666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_dec) {
  char str1[500];
  char str2[500];

  ck_assert_int_eq(s21_sprintf(str1, "%d%d%d%d", -999, 0, 666, -100),
                   sprintf(str2, "%d%d%d%d", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_int) {
  char str1[500];
  char str2[500];

  ck_assert_int_eq(s21_sprintf(str1, "%i", -0), sprintf(str2, "%i", -0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_int) {
  char str1[500];
  char str2[500];

  ck_assert_int_eq(s21_sprintf(str1, "%i%i%i%i", -999, 0, 666, -100),
                   sprintf(str2, "%i%i%i%i", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_float) {
  char str1[500];
  char str2[500];

  ck_assert_int_eq(s21_sprintf(str1, "%f", 0.0001),
                   sprintf(str2, "%f", 0.0001));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_float) {
  char str1[500];
  char str2[500];

  ck_assert_int_eq(
      s21_sprintf(str1, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001),
      sprintf(str2, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_unsigned_dec) {
  char str1[500];
  char str2[500];

  ck_assert_int_eq(s21_sprintf(str1, "%u", 100),
                   sprintf(str2, "%u", (unsigned)100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_unsigned_dec) {
  char str1[500];
  char str2[500];

  ck_assert_int_eq(s21_sprintf(str1, "%u%u%u%u", 999, 0, 666, 100),
                   sprintf(str2, "%u%u%u%u", (unsigned)999, (unsigned)0,
                           (unsigned)666, (unsigned)100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_char_with_alignment_left) {
  char str1[500];
  char str2[500];

  ck_assert_int_eq(s21_sprintf(str1, "%8c", '\t'), sprintf(str2, "%8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_char_with_alignment_right) {
  char str1[500];
  char str2[500];

  ck_assert_int_eq(s21_sprintf(str1, "%-8c", '\t'),
                   sprintf(str2, "%-8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_char_with_alignment) {
  char str1[500];
  char str2[500];

  ck_assert_int_eq(
      s21_sprintf(str1, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'),
      sprintf(str2, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

// START HEX TEST
START_TEST(test_one_hex_lower) {
  char str1[500];
  char str2[500];
  ck_assert_int_eq(s21_sprintf(str1, "%x", (unsigned)INT32_MIN),
                   sprintf(str2, "%x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%x", 0), sprintf(str2, "%x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%x", INT32_MAX),
                   sprintf(str2, "%x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_upper) {
  char str1[500];
  char str2[500];

  ck_assert_int_eq(s21_sprintf(str1, "%X", (unsigned)INT32_MIN),
                   sprintf(str2, "%X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%X", 0), sprintf(str2, "%x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%X", INT32_MAX),
                   sprintf(str2, "%X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_lower) {
  char str1[500];
  char str2[500];

  ck_assert_int_eq(
      s21_sprintf(str1, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123),
      sprintf(str2, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_upper) {
  char str1[500];
  char str2[500];

  ck_assert_int_eq(
      s21_sprintf(str1, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123),
      sprintf(str2, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST

// START HEX WITH ALIGNMENT
START_TEST(test_one_hex_lower_with_alignment_left) {
  char str1[500];
  char str2[500];

  ck_assert_int_eq(s21_sprintf(str1, "%-3x", (unsigned)INT32_MIN),
                   sprintf(str2, "%-3x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-3x", 0), sprintf(str2, "%-3x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-3x", INT32_MAX),
                   sprintf(str2, "%-3x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_lower_with_alignment_right) {
  char str1[500];
  char str2[500];

  ck_assert_int_eq(s21_sprintf(str1, "%13x", (unsigned)INT32_MIN),
                   sprintf(str2, "%13x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%13x", 0), sprintf(str2, "%13x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%13x", INT32_MAX),
                   sprintf(str2, "%13x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_upper_with_alignment_left) {
  char str1[500];
  char str2[500];

  ck_assert_int_eq(s21_sprintf(str1, "%-60X", INT32_MIN),
                   sprintf(str2, "%-60X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-60X", 0), sprintf(str2, "%-60X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-60X", INT32_MAX),
                   sprintf(str2, "%-60X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_upper_with_alignment_right) {
  char str1[500];
  char str2[500];

  ck_assert_int_eq(s21_sprintf(str1, "%7X", (unsigned)INT32_MIN),
                   sprintf(str2, "%7X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%7X", 0), sprintf(str2, "%7X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%7X", INT32_MAX),
                   sprintf(str2, "%7X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_lower_with_alignment) {
  char str1[500];
  char str2[500];

  ck_assert_int_eq(
      s21_sprintf(str1, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999),
      sprintf(str2, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_upper_with_alignment) {
  char str1[500];
  char str2[500];
  ck_assert_int_eq(
      s21_sprintf(str1, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999),
      sprintf(str2, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// START HEX WITH ALIGNMENT

// START HEX TEST WITH #
START_TEST(test_one_hex_with_hashtag) {
  char str1[500];
  char str2[500];

  ck_assert_int_eq(s21_sprintf(str1, "%#x", INT32_MIN),
                   sprintf(str2, "%#x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#x", 0), sprintf(str2, "%#x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#x", INT32_MAX),
                   sprintf(str2, "%#x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_upper_with_hashtag) {
  char str1[500];
  char str2[500];

  ck_assert_int_eq(s21_sprintf(str1, "%#X", INT32_MIN),
                   sprintf(str2, "%#X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#X", 0), sprintf(str2, "%#X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#X", INT32_MAX),
                   sprintf(str2, "%#X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_lower_with_hashtag_and_alignm) {
  char str1[500];
  char str2[500];

  ck_assert_int_eq(
      s21_sprintf(str1, "%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13, -0,
                  123213123),
      sprintf(str2, "%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13, -0, 123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_upper_with_hashtag_and_alignm) {
  char str1[500];
  char str2[500];

  ck_assert_int_eq(
      s21_sprintf(str1, "%#X%#X%3X%#32X%#-1X", 87, 1222224535, -13, -0,
                  123213123),
      sprintf(str2, "%#X%#X%3X%#32X%#-1X", 87, 1222224535, -13, -0, 123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST WITH #

// START HEX TEST with width *
START_TEST(test_one_hex_lower_with_width_star) {
  char str1[500];
  char str2[500];

  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, INT32_MIN),
                   sprintf(str2, "%*x", 11, (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, 0),
                   sprintf(str2, "%*x", 11, 0));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, INT32_MAX),
                   sprintf(str2, "%*x", 11, INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_upper_with_width_star) {
  char str1[500];
  char str2[500];

  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, INT32_MIN),
                   sprintf(str2, "%*X", 11, (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, 0),
                   sprintf(str2, "%*X", 11, 0));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, INT32_MAX),
                   sprintf(str2, "%*X", 11, INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_lower_with_width_star_and_align_and_hashtag) {
  char str1[500];
  char str2[500];

  ck_assert_int_eq(s21_sprintf(str1, "%#*x%*x%-12x%3x%*x", 9, 127312897, 0, -1,
                               199, -123978, 3, -1251),
                   sprintf(str2, "%#*x%*x%-12x%3x%*x", 9, 127312897, -0, -1,
                           199, -123978, 3, -1251));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_upper_with_width_star) {
  char str1[500];
  char str2[500];

  ck_assert_int_eq(s21_sprintf(str1, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1,
                               199, -123978, 3, -1251),
                   sprintf(str2, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1, 199,
                           -123978, 3, -1251));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST WITH Width *

// START HEX TEST WITH precision
START_TEST(test_one_hex_lower_with_precision) {
  char str1[500];
  char str2[500];

  int a = s21_sprintf(str1, "%*.6x", 11, 0);
  int b = sprintf(str2, "%*.6x", 11, 0);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_upper_with_precision) {
  char str1[500];
  char str2[500];

  int a = s21_sprintf(str1, "%*.6X", 11, INT32_MIN);
  int b = sprintf(str2, "%*.6X", 11, (unsigned)INT32_MIN);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_lower_with_precision_and_other) {
  char str1[500];
  char str2[500];
  int a = s21_sprintf(
      str1, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x", 3, 126714,
      4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9, 41, -41, 33);
  int b = sprintf(str2, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x",
                  3, 126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9,
                  41, -41, 33);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_many_hex_upper_with_precision_and_other) {
  char str1[500];
  char str2[500];
  int n1 = s21_sprintf(
      str1, "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X", 3, -126714,
      4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9, 41, -41, 33);
  int n2 = sprintf(str2, "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X",
                   3, -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9,
                   41, -41, 33);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST
// END HEX TEST WITH precision

// START HEX TEST WITH Length
START_TEST(test_one_hex_lower_with_length) {
  char str1[500];
  char str2[500];

  ck_assert_int_eq(s21_sprintf(str1, "%hx", -11),
                   sprintf(str2, "%hx", (unsigned short)-11));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 0),
                   sprintf(str2, "%hx", (unsigned short)0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 11),
                   sprintf(str2, "%hx", (unsigned short)11));
  ck_assert_str_eq(str1, str2);
  long unsigned int val = INT32_MAX;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", val), sprintf(str2, "%lx", val));
  ck_assert_str_eq(str1, str2);
  long unsigned int v = 0;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", v), sprintf(str2, "%lx", v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_upper_with_length) {
  char str1[500];
  char str2[500];

  ck_assert_int_eq(s21_sprintf(str1, "%hx", -11),
                   sprintf(str2, "%hx", (unsigned short)-11));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 0),
                   sprintf(str2, "%hx", (unsigned short)0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 11),
                   sprintf(str2, "%hx", (unsigned short)11));
  ck_assert_str_eq(str1, str2);
  long unsigned int val = INT32_MAX;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", val), sprintf(str2, "%lx", val));
  ck_assert_str_eq(str1, str2);
  long unsigned int v = 0;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", v), sprintf(str2, "%lx", v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf1) {
  char str1[500];
  char str2[500];
  char format[] = "%10ld";

  ck_assert_int_eq(s21_sprintf(str1, format, 1), sprintf(str2, format, 1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf2) {
  char str1[500];
  char str2[500];
  char format[] = "%1.1f";

  ck_assert_int_eq(s21_sprintf(str1, format, 1.1), sprintf(str2, format, 1.1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf3) {
  char str1[500];
  char str2[500];
  char format[] = "%8.3c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf4) {
  char str1[500];
  char str2[500];
  char format[] = "%+5.5d aboba";

  int val = 10000;
  int a = s21_sprintf(str1, format, val);
  int b = sprintf(str2, format, val);
  ck_assert_int_eq(a, b);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf6) {
  char str1[500];
  char str2[500];
  char format[] = "%7.7f";

  ck_assert_int_eq(s21_sprintf(str1, format, 11.123456),
                   sprintf(str2, format, 11.123456));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf7) {
  char str1[500];
  char str2[500];
  char format[] = "%7.4s";

  ck_assert_int_eq(s21_sprintf(str1, format, "aboba floppa"),
                   sprintf(str2, format, "aboba floppa"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf8) {
  char str1[500];
  char str2[500];
  char format[] = "%6.6u";

  ck_assert_int_eq(s21_sprintf(str1, format, 12341151),
                   sprintf(str2, format, 12341151));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf9) {
  char str1[500];
  char str2[500];
  char format[] = "%li%ld%lu";

  ck_assert_int_eq(s21_sprintf(str1, format, 666666666666, 777, 111),
                   sprintf(str2, format, 666666666666, 777, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf10) {
  char str1[500];
  char str2[500];
  char format[] = "%hi%hd%hu";

  ck_assert_int_eq(s21_sprintf(str1, format, 666, -777, 111),
                   sprintf(str2, format, 666, -777, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf11) {
  char str1[500];
  char str2[500];
  char format[] = "%+li%+lu%+d%+lf";

  ck_assert_int_eq(s21_sprintf(str1, format, -123, 321, -5555, -1213.123),
                   sprintf(str2, format, -123, 321, -5555, -1213.123));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf12) {
  char str1[500];
  char str2[500];
  char format[] = "%-11.11li%-35.5lu%-3.5ld%33.19Lf";
  long double k = 333.33213;

  ck_assert_int_eq(
      s21_sprintf(str1, format, 66666666666, 5555555555, 44444444444, k),
      sprintf(str2, format, 66666666666, 5555555555, 44444444444, k));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf14) {
  char str1[500];
  char str2[500];
  char format[] = "% 0.0li% 0.0lu% 0.0ld % 0.0lf";
  ck_assert_int_eq(s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
                   sprintf(str2, format, 1, 222, 33333333333, -166513.1232));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf15) {
  char str1[500];
  char str2[500];
  //  "% 0.0hi% 0.0hu% 0.0hd % hhh %mf"
  char format[] = "% 0.0hi% 0.0hu% 0.0hd % hhhf %bf";
  int n1 = s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232, 5.);
  int n2 = sprintf(str2, format, 1, 222, 33333333333, -166513.1232, 5.);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(test_sprintf16) {
  char str1[500];
  char str2[500];
  char format[] = "% c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf17) {
  char str1[500];
  char str2[500];
  char format[] = "% s";

  ck_assert_int_eq(s21_sprintf(str1, format, "aboba likes floppa"),
                   sprintf(str2, format, "aboba likes floppa"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf18) {
  char str1[500];
  char str2[500];
  char format[] = "% s% c";

  ck_assert_int_eq(s21_sprintf(str1, format, "", 'f'),
                   sprintf(str2, format, "", 'f'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf19) {
  char str1[500];
  char str2[500];
  char format[] = "%210s";

  ck_assert_int_eq(s21_sprintf(str1, format, "AHHAHAHA\0AHHAHAHAH"),
                   sprintf(str2, format, "AHHAHAHA\0AHHAHAHAH"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf20) {
  char str1[500];
  char str2[500];
  char format[] = "%-115s";

  ck_assert_int_eq(s21_sprintf(str1, format, "Nick her"),
                   sprintf(str2, format, "Nick her"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf21) {
  char str1[500];
  char str2[500];
  char format[] = "Sample text %c";

  ck_assert_int_eq(s21_sprintf(str1, format, ' '), sprintf(str2, format, ' '));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf22) {
  char str1[500];
  char str2[500];
  char format[] = "Sample\0text%c";

  ck_assert_int_eq(s21_sprintf(str1, format, ' '), sprintf(str2, format, ' '));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf23) {
  char str1[500];
  char str2[500];
  char format[] = "% -2.1c% -4.2d% -5.4i%-10.2f% -55s% 1.1u";

  ck_assert_int_eq(
      s21_sprintf(str1, format, 'f', 21, 42, 666.666,
                  "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11),
      sprintf(str2, format, 'f', 21, 42, 666.666,
              "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf24) {
  char str1[500];
  char str2[500];
  char format[] = "%+2.1c%+4.2d%+5.4i%+10.2f%+55.55s%+1.1u";

  ck_assert_int_eq(
      s21_sprintf(str1, format, 'f', 21, 42, 666.666,
                  "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11),
      sprintf(str2, format, 'f', 21, 42, 666.666,
              "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf25) {
  char str1[500];
  char str2[500];
  char format[] = "%.f";

  ck_assert_int_eq(s21_sprintf(str1, format, 121.123),
                   sprintf(str2, format, 121.123));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf26) {
  char str1[500];
  char str2[500];
  char format[] = "%%%d";

  ck_assert_int_eq(s21_sprintf(str1, format, 5), sprintf(str2, format, 5));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf27) {
  char str1[500];
  char str2[500];
  char format[] = "%%%%%%%%c";

  ck_assert_int_eq(s21_sprintf(str1, format, ' '), sprintf(str2, format, ' '));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf28) {
  char str1[500];
  char str2[500];
  int n1;
  int n2;
  int a = s21_sprintf(str1, "%d%n", 123, &n1);
  int b = sprintf(str2, "%d%n", 123, &n2);

  ck_assert_int_eq(a, b);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf29) {
  char str1[500];
  char str2[500];
  char format[] = "%-.f";

  ck_assert_int_eq(s21_sprintf(str1, format, 111.111),
                   sprintf(str2, format, 111.111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf30) {
  char str1[500];
  char str2[500];
  char format[] = "%-.1d";

  ck_assert_int_eq(s21_sprintf(str1, format, 111), sprintf(str2, format, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf31) {
  char str1[500];
  char str2[500];
  char format[] = "%e";
  double x = 111;
  ck_assert_int_eq(s21_sprintf(str1, format, x), sprintf(str2, format, x));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf32) {
  char str1[500];
  char str2[500];
  char format[] = "%e%e%e%e";

  ck_assert_int_eq(s21_sprintf(str1, format, 11.111, 222.2222, 666., -555.125),
                   sprintf(str2, format, 11.111, 222.2222, 666., -555.125));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf33) {
  char str1[500];
  char str2[500];
  char format[] = "%Le";
  long double x = 122.1231;

  ck_assert_int_eq(s21_sprintf(str1, format, x), sprintf(str2, format, x));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf35) {
  char str1[500];
  char str2[500];
  char format[] = "%.10e";

  ck_assert_int_eq(s21_sprintf(str1, format, 111.184314818),
                   sprintf(str2, format, 111.184314818));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf36) {
  char str1[500];
  char str2[500];
  char format[] = "%5.3e%3.2e%lf";

  ck_assert_int_eq(s21_sprintf(str1, format, 0.000111, 111.555, 1.999),
                   sprintf(str2, format, 0.000111, 111.555, 1.999));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf37) {
  char str1[500];
  char str2[500];
  char format[] = "%E";

  ck_assert_int_eq(s21_sprintf(str1, format, 0.666666),
                   sprintf(str2, format, 0.666666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf38) {
  char str1[500];
  char str2[500];
  char format[] = "%E%E%E";

  ck_assert_int_eq(s21_sprintf(str1, format, 0.0000999, 111.9999, 6.666),
                   sprintf(str2, format, 0.0000999, 111.9999, 6.666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf39) {
  char str1[500];
  char str2[500];
  char format[] = "%e ABOBA %Lf %Lf %Le";
  long double c = 848181;
  long double a = 0.00000001;
  long double b = 1111111.11;
  ck_assert_int_eq(s21_sprintf(str1, format, 123.123, a, b, c),
                   sprintf(str2, format, 123.123, a, b, c));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf40) {
  char str1[500];
  char str2[500];
  char format[] = "%#e Floppa %#E%#f";

  ck_assert_int_eq(s21_sprintf(str1, format, 123.111, 0.0000999, 0.555),
                   sprintf(str2, format, 123.111, 0.0000999, 0.555));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf41) {
  char str1[500];
  char str2[500];
  char format[] = "%.Lf";
  long double a = 7.9418438184;
  int n1 = s21_sprintf(str1, format, a);
  int n2 = sprintf(str2, format, a);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf42) {
  char str1[500];
  char str2[500];
  char format[] = "%#5p";
  int a = 5;
  ck_assert_int_eq(s21_sprintf(str1, format, &a), sprintf(str2, format, &a));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf43) {
  char str1[500];
  char str2[500];
  char format[] = "%.5o";

  ck_assert_int_eq(s21_sprintf(str1, format, 12345),
                   sprintf(str2, format, 12345));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf44) {
  char str1[500];
  char str2[500];
  char format[] = "%#5lX";
  long hex = 314818438141;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(g_trailing_zero) {
  char str1[500];
  char str2[500];
  char format[] = "%g";
  double hex = 0.50300;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(g_large) {
  char str1[500];
  char str2[500];
  char format[] = "%g";
  double hex = 5131.43141;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_small) {
  char str1[500];
  char str2[500];
  char format[] = "%g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_precision) {
  char str1[500];
  char str2[500];
  char format[] = "%.5g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_precision_zero) {
  char str1[500];
  char str2[500];
  char format[] = "%.0g";
  double hex = 0.123000;
  int n1 = s21_sprintf(str1, format, hex);
  int n2 = sprintf(str2, format, hex);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST
START_TEST(g_precision_missing) {
  char str1[500];
  char str2[500];
  char format[] = "%.1g";
  double hex = 0.123000;
  int n1 = s21_sprintf(str1, format, hex);
  int n2 = sprintf(str2, format, hex);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST
START_TEST(g_many_zeroes_in_front) {
  char str1[500];
  char str2[500];
  char format[] = "%.g";
  double hex = 0.004;
  int n1 = s21_sprintf(str1, format, hex);
  int n2 = sprintf(str2, format, hex);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST
START_TEST(g_one_zero) {
  char str1[500];
  char str2[500];
  char format[] = "%g";
  double hex = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

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

START_TEST(g_mantiss) {
  char str1[500];
  char str2[500];
  char format[] = "%g";
  double hex = 0.0000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_mantiss_flags) {
  char str1[500];
  char str2[500];
  char format[] = "%5.8g";
  double hex = 0.0000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(g_short_no_mantiss) {
  char str1[500];
  char str2[500];
  char format[] = "%g";
  double hex = 0.005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(LG) {
  char str1[500];
  char str2[500];
  char format[] = "%LG";
  long double hex = 0.000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));
  ck_assert_str_eq(str1, str2);
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

Suite *string_suite(void) {
  Suite *s;
  TCase *tc_sprintf;
  s = suite_create("s21_sprintf");
  tc_sprintf = tcase_create("s21_sprintf");

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

  tcase_add_test(tc_sprintf, simple_int);
  tcase_add_test(tc_sprintf, precise_int);
  tcase_add_test(tc_sprintf, width_int);
  tcase_add_test(tc_sprintf, minus_width_int);
  tcase_add_test(tc_sprintf, plus_width_int);
  tcase_add_test(tc_sprintf, padding_int);
  tcase_add_test(tc_sprintf, star_width_int);
  tcase_add_test(tc_sprintf, star_precision_int);
  tcase_add_test(tc_sprintf, many_flags_many_ints);
  tcase_add_test(tc_sprintf, flags_long_int);
  tcase_add_test(tc_sprintf, flags_short_int);
  tcase_add_test(tc_sprintf, flags_another_long_int);
  tcase_add_test(tc_sprintf, zero_precision_zero_int);
  tcase_add_test(tc_sprintf, space_flag_int);
  tcase_add_test(tc_sprintf, unsigned_val);
  tcase_add_test(tc_sprintf, unsigned_val_width);
  tcase_add_test(tc_sprintf, unsigned_val_flags);
  tcase_add_test(tc_sprintf, unsigned_val_precision);
  tcase_add_test(tc_sprintf, unsigned_val_many_flags);
  tcase_add_test(tc_sprintf, unsigned_val_short);
  tcase_add_test(tc_sprintf, unsigned_val_long);
  tcase_add_test(tc_sprintf, unsigned_val_many);
  tcase_add_test(tc_sprintf, octal);
  tcase_add_test(tc_sprintf, octal_width);
  tcase_add_test(tc_sprintf, octal_flags);
  tcase_add_test(tc_sprintf, octal_precision);
  tcase_add_test(tc_sprintf, octal_many_flags);
  tcase_add_test(tc_sprintf, octal_short);
  tcase_add_test(tc_sprintf, octal_long);
  tcase_add_test(tc_sprintf, octal_many);
  tcase_add_test(tc_sprintf, octal_zero);
  tcase_add_test(tc_sprintf, octal_hash);
  tcase_add_test(tc_sprintf, unsigned_zero);
  tcase_add_test(tc_sprintf, hex_width);
  tcase_add_test(tc_sprintf, hex_flags);
  tcase_add_test(tc_sprintf, hex_precision);
  tcase_add_test(tc_sprintf, hex_many);
  tcase_add_test(tc_sprintf, hex_many_flags);
  tcase_add_test(tc_sprintf, hex_zero);
  tcase_add_test(tc_sprintf, hex_huge);
  tcase_add_test(tc_sprintf, hex_short);
  tcase_add_test(tc_sprintf, hex_long);
  tcase_add_test(tc_sprintf, hex_one_longer_width);
  tcase_add_test(tc_sprintf, hex_two_longer_width);
  tcase_add_test(tc_sprintf, one_char);
  tcase_add_test(tc_sprintf, one_precision);
  tcase_add_test(tc_sprintf, one_flags);
  tcase_add_test(tc_sprintf, one_width);
  tcase_add_test(tc_sprintf, one_many);
  tcase_add_test(tc_sprintf, one_many_flags);
  tcase_add_test(tc_sprintf, string);
  tcase_add_test(tc_sprintf, string_precision);
  tcase_add_test(tc_sprintf, string_width);
  tcase_add_test(tc_sprintf, string_flags);
  tcase_add_test(tc_sprintf, string_long);
  tcase_add_test(tc_sprintf, string_many);
  tcase_add_test(tc_sprintf, ptr);
  tcase_add_test(tc_sprintf, ptr_width);
  tcase_add_test(tc_sprintf, ptr_precision);
  tcase_add_test(tc_sprintf, null_ptr);
  tcase_add_test(tc_sprintf, n_specifier);
  tcase_add_test(tc_sprintf, two_percent);
  tcase_add_test(tc_sprintf, string_width_huge);
  tcase_add_test(tc_sprintf, float_precision);
  tcase_add_test(tc_sprintf, float_width);
  tcase_add_test(tc_sprintf, float_precision_zero);
  tcase_add_test(tc_sprintf, float_precision_empty);
  tcase_add_test(tc_sprintf, float_precision_huge);
  tcase_add_test(tc_sprintf, float_precision_huge_negative);
  tcase_add_test(tc_sprintf, float_huge);
  tcase_add_test(tc_sprintf, float_flags);
  tcase_add_test(tc_sprintf, float_many);
  tcase_add_test(tc_sprintf, e_precision);
  tcase_add_test(tc_sprintf, e_precision_zero);
  tcase_add_test(tc_sprintf, e_precision_empty);
  tcase_add_test(tc_sprintf, e_precision_huge);
  tcase_add_test(tc_sprintf, e_precision_huge_negative);
  tcase_add_test(tc_sprintf, e_huge);
  tcase_add_test(tc_sprintf, e_many);
  tcase_add_test(tc_sprintf, e_width);
  tcase_add_test(tc_sprintf, e_flags);
  tcase_add_test(tc_sprintf, E_int);
  tcase_add_test(tc_sprintf, all_empty);
  tcase_add_test(tc_sprintf, empty_format_and_parameters);
  tcase_add_test(tc_sprintf, test_one_char);
  tcase_add_test(tc_sprintf, test_many_char);
  tcase_add_test(tc_sprintf, test_one_string);
  tcase_add_test(tc_sprintf, test_many_string);
  tcase_add_test(tc_sprintf, test_one_dec);
  tcase_add_test(tc_sprintf, test_many_dec);
  tcase_add_test(tc_sprintf, test_one_int);
  tcase_add_test(tc_sprintf, test_many_int);
  tcase_add_test(tc_sprintf, test_one_float);
  tcase_add_test(tc_sprintf, test_many_float);
  tcase_add_test(tc_sprintf, test_one_unsigned_dec);
  tcase_add_test(tc_sprintf, test_many_unsigned_dec);
  tcase_add_test(tc_sprintf, test_one_char_with_alignment_left);
  tcase_add_test(tc_sprintf, test_one_char_with_alignment_right);
  tcase_add_test(tc_sprintf, test_many_char_with_alignment);
  tcase_add_test(tc_sprintf, test_one_hex_lower);
  tcase_add_test(tc_sprintf, test_one_hex_upper);
  tcase_add_test(tc_sprintf, test_many_hex_lower);
  tcase_add_test(tc_sprintf, test_many_hex_upper);
  tcase_add_test(tc_sprintf, test_one_hex_lower_with_alignment_left);
  tcase_add_test(tc_sprintf, test_one_hex_lower_with_alignment_right);
  tcase_add_test(tc_sprintf, test_one_hex_upper_with_alignment_left);
  tcase_add_test(tc_sprintf, test_one_hex_upper_with_alignment_right);
  tcase_add_test(tc_sprintf, test_many_hex_lower_with_alignment);
  tcase_add_test(tc_sprintf, test_many_hex_upper_with_alignment);
  tcase_add_test(tc_sprintf, test_one_hex_with_hashtag);
  tcase_add_test(tc_sprintf, test_one_hex_upper_with_hashtag);
  tcase_add_test(tc_sprintf, test_many_hex_lower_with_hashtag_and_alignm);
  tcase_add_test(tc_sprintf, test_many_hex_upper_with_hashtag_and_alignm);
  tcase_add_test(tc_sprintf, test_one_hex_lower_with_width_star);
  tcase_add_test(tc_sprintf, test_one_hex_upper_with_width_star);
  tcase_add_test(tc_sprintf,
                 test_many_hex_lower_with_width_star_and_align_and_hashtag);
  tcase_add_test(tc_sprintf, test_many_hex_upper_with_width_star);
  tcase_add_test(tc_sprintf, test_one_hex_lower_with_precision);
  tcase_add_test(tc_sprintf, test_one_hex_upper_with_precision);
  tcase_add_test(tc_sprintf, test_many_hex_lower_with_precision_and_other);
  tcase_add_test(tc_sprintf, test_many_hex_upper_with_precision_and_other);
  tcase_add_test(tc_sprintf, test_one_hex_lower_with_length);
  tcase_add_test(tc_sprintf, test_one_hex_upper_with_length);
  tcase_add_test(tc_sprintf, test_sprintf1);
  tcase_add_test(tc_sprintf, test_sprintf2);
  tcase_add_test(tc_sprintf, test_sprintf3);
  tcase_add_test(tc_sprintf, test_sprintf4);
  tcase_add_test(tc_sprintf, test_sprintf6);
  tcase_add_test(tc_sprintf, test_sprintf7);
  tcase_add_test(tc_sprintf, test_sprintf8);
  tcase_add_test(tc_sprintf, test_sprintf9);
  tcase_add_test(tc_sprintf, test_sprintf10);
  tcase_add_test(tc_sprintf, test_sprintf11);
  tcase_add_test(tc_sprintf, test_sprintf12);
  tcase_add_test(tc_sprintf, test_sprintf14);
  tcase_add_test(tc_sprintf, test_sprintf15);
  tcase_add_test(tc_sprintf, test_sprintf16);
  tcase_add_test(tc_sprintf, test_sprintf17);
  tcase_add_test(tc_sprintf, test_sprintf18);
  tcase_add_test(tc_sprintf, test_sprintf19);
  tcase_add_test(tc_sprintf, test_sprintf20);
  tcase_add_test(tc_sprintf, test_sprintf21);
  tcase_add_test(tc_sprintf, test_sprintf22);
  tcase_add_test(tc_sprintf, test_sprintf23);
  tcase_add_test(tc_sprintf, test_sprintf24);
  tcase_add_test(tc_sprintf, test_sprintf25);
  tcase_add_test(tc_sprintf, test_sprintf26);
  tcase_add_test(tc_sprintf, test_sprintf27);
  tcase_add_test(tc_sprintf, test_sprintf28);
  tcase_add_test(tc_sprintf, test_sprintf29);
  tcase_add_test(tc_sprintf, test_sprintf30);
  tcase_add_test(tc_sprintf, test_sprintf31);
  tcase_add_test(tc_sprintf, test_sprintf32);
  tcase_add_test(tc_sprintf, test_sprintf33);
  tcase_add_test(tc_sprintf, test_sprintf35);
  tcase_add_test(tc_sprintf, test_sprintf36);
  tcase_add_test(tc_sprintf, test_sprintf37);
  tcase_add_test(tc_sprintf, test_sprintf38);
  tcase_add_test(tc_sprintf, test_sprintf39);
  tcase_add_test(tc_sprintf, test_sprintf40);
  tcase_add_test(tc_sprintf, test_sprintf41);
  tcase_add_test(tc_sprintf, test_sprintf42);
  tcase_add_test(tc_sprintf, test_sprintf43);
  tcase_add_test(tc_sprintf, test_sprintf44);
  tcase_add_test(tc_sprintf, g_trailing_zero);
  tcase_add_test(tc_sprintf, g_large);
  tcase_add_test(tc_sprintf, g_small);
  tcase_add_test(tc_sprintf, g_precision);
  tcase_add_test(tc_sprintf, g_precision_zero);
  tcase_add_test(tc_sprintf, g_precision_missing);
  tcase_add_test(tc_sprintf, g_many_zeroes_in_front);
  tcase_add_test(tc_sprintf, g_one_zero);
  tcase_add_test(tc_sprintf, g_mantiss);
  tcase_add_test(tc_sprintf, g_mantiss_flags);
  tcase_add_test(tc_sprintf, g_short_no_mantiss);
  tcase_add_test(tc_sprintf, LG);
  tcase_add_test(tc_sprintf, g_many);
  tcase_add_test(tc_sprintf, g_zero);
  tcase_add_test(tc_sprintf, c_many_lengths);
  tcase_add_test(tc_sprintf, d_many_lengths);
  tcase_add_test(tc_sprintf, e_many_lengths);
  tcase_add_test(tc_sprintf, f_many_lengths);
  tcase_add_test(tc_sprintf, g_many_lengths);
  tcase_add_test(tc_sprintf, o_many_lengths);
  tcase_add_test(tc_sprintf, s_many_lengths);
  tcase_add_test(tc_sprintf, u_many_lengths);
  tcase_add_test(tc_sprintf, x_many_lengths);
  tcase_add_test(tc_sprintf, p_many_lengths);
  tcase_add_test(tc_sprintf, percent_many_lengths);

  suite_add_tcase(s, tc_sprintf);
  return s;
}

int main() {
  int number_failed;
  struct Suite *s;
  struct SRunner *sr;
  s = string_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (!number_failed) ? EXIT_SUCCESS : EXIT_FAILURE;
}
