#include "s21_string.h"
#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <locale.h>

START_TEST(s21_sscanf_c_test0) {
  char c_original;
  char c_fake;
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
  int n_fke = s21_sscanf(str2, "%e %e %e %e", &e_fke, &e_fke2, &e_fke3, &e_fke4);
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
  ck_assert_ldouble_lt(fabsl(e_org-e_fke), 1e-6);
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
  int n_org = sscanf(str, "%25o %5lo %4ho %hho %llo", &o_org, &o_org2, &o_org3, &c1, &c2);
  int n_fke = s21_sscanf(str2, "%25o %5lo %4ho %hho %llo", &o_fke, &o_fke2, &o_fke3, &c1_, &c2_);
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
    const char str[] =  "вальс";
    const char str_[] = "вальс";
    const char format[] = "%lc";

    wchar_t c1, c1_;
    int res1 = s21_sscanf(str, format, &c1);
    int res2 = sscanf(str_, format, &c1_);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(c1, c1_);
} END_TEST
START_TEST(test_c_11) {
    const char str[] =  "вальс";
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
} END_TEST
START_TEST(test_c_12) {
    const char str[] =  "вальс";
    const char str_[] = "вальс";
    const char format[] = "%lc%lc";

    wchar_t c1, c1_;
    wchar_t c2, c2_;
    int res1 = s21_sscanf(str, format, &c1, &c2);
    int res2 = sscanf(str_, format, &c1_, &c2_);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(c1, c1_);
    ck_assert_int_eq(c2, c2_);
} END_TEST
START_TEST(test_s_10) {
    const char str[] =  "вальс";
    const char str_[] = "вальс";
    const char format[] = "%ls";

    wchar_t c1[500] = {};
    wchar_t c1_[500] = {};
    int res1 = s21_sscanf(str, format, c1);
    int res2 = sscanf(str_, format, c1_);
    ck_assert_int_eq(res1, res2);
    ck_assert_mem_eq(c1, c1_, 10);
    ck_assert_int_eq(c1[1], c1_[1]);
} END_TEST




Suite *s21_sscanf_tests(void) {
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
  (void)setlocale(LC_ALL, "en-US");

  int number_failed;
  struct Suite *s;
  struct SRunner *sr;
  s = s21_sscanf_tests();
  sr = srunner_create(s);
  //  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (!number_failed) ? EXIT_SUCCESS : EXIT_FAILURE;
}
