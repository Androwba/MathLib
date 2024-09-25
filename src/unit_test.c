#include <check.h>
#include <math.h>

#include "s21_math.h"

START_TEST(Abs1) { ck_assert_int_eq(s21_abs(-1), abs(-1)); }
END_TEST

START_TEST(Abs2) { ck_assert_int_eq(s21_abs(7), abs(7)); }
END_TEST

START_TEST(Abs3) { ck_assert_int_eq(s21_abs(-2147483647), abs(-2147483647)); }
END_TEST

START_TEST(Abs4) { ck_assert_int_eq(s21_abs(-07), abs(-07)); }
END_TEST

START_TEST(Abs5) { ck_assert_int_eq(s21_abs(-00002345670), abs(-00002345670)); }
END_TEST

START_TEST(Abs6) { ck_assert_int_eq(s21_abs(123456789), abs(123456789)); }
END_TEST

START_TEST(Abs7) { ck_assert_int_eq(s21_abs(100), abs(100)); }
END_TEST

START_TEST(AbsHexdecimalNegative) {
  ck_assert_int_eq(s21_abs(-0xA13), abs(-2579));
}
END_TEST

START_TEST(Abs9) { ck_assert_int_eq(s21_abs(13), abs(13)); }
END_TEST

START_TEST(Abs10) { ck_assert_int_eq(s21_abs(-0), abs(-0)); }
END_TEST

START_TEST(Abs11) { ck_assert_int_eq(s21_abs(0), abs(0)); }
END_TEST

START_TEST(Abs12) { ck_assert_int_eq(s21_abs(-100), abs(-100)); }
END_TEST

START_TEST(AbsHexadecimal) {
  ck_assert_int_eq(s21_abs(0xeee63a), abs(15656506));
}
END_TEST

START_TEST(normal) {
  double a = -5.53151413431;
  ck_assert_ldouble_eq(s21_fabs(a), fabs(a));
}
END_TEST

START_TEST(nan_num) {
  double a = s21_NAN;
  ck_assert_ldouble_nan(s21_fabs(a));
  ck_assert_ldouble_nan(fabs(a));
}
END_TEST

START_TEST(POS_INF) {
  double a = s21_POS_INF;
  ck_assert_ldouble_infinite(s21_fabs(a));
  ck_assert_ldouble_infinite(fabs(a));
}
END_TEST

START_TEST(NEG_INF) {
  double a = s21_NEG_INF;
  ck_assert_ldouble_infinite(s21_fabs(a));
  ck_assert_ldouble_infinite(fabs(a));
}
END_TEST

START_TEST(large) {
  double a = -9719359135915.63151413431;
  ck_assert_ldouble_eq(s21_fabs(a), fabs(a));
}
END_TEST

START_TEST(not_a_num) {
  ck_assert_ldouble_nan(s21_fabs(s21_NAN));
  ck_assert_ldouble_nan(fabs(s21_NAN));
}
END_TEST

START_TEST(Ceil_1) {
  double value1 = 1.5;
  ck_assert_uint_eq(s21_ceil(value1), ceil(value1));
}
END_TEST

START_TEST(Ceil_2) {
  double value2 = 0.45;
  ck_assert_uint_eq(s21_ceil(value2), ceil(value2));
}
END_TEST

START_TEST(Ceil_3) {
  double value3 = -3.01;
  ck_assert_uint_eq(s21_ceil(value3), ceil(value3));
}
END_TEST

START_TEST(Ceil_4) {
  double value4 = -0;
  ck_assert_uint_eq(s21_ceil(value4), ceil(value4));
}
END_TEST

START_TEST(Ceil_5) {
  double value5 = -1234567.1;
  ck_assert_uint_eq(s21_ceil(value5), ceil(value5));
}
END_TEST

START_TEST(test_inf) {
  ck_assert_ldouble_infinite(s21_ceil(s21_POS_INF));
  ck_assert_ldouble_infinite(ceil(s21_POS_INF));
}
END_TEST

START_TEST(test_nan) {
  ck_assert_ldouble_nan(s21_ceil(s21_NAN));
  ck_assert_ldouble_nan(ceil(s21_NAN));
}
END_TEST

START_TEST(test_y_zero) { ck_assert_ldouble_eq(s21_ceil(0), ceil(0)); }
END_TEST

START_TEST(test_x_inf_y_zero) {
  double x = 9214713747357135139.9134143134134134;
  ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
}
END_TEST

START_TEST(test_pos_inf) {
  ck_assert_ldouble_infinite(s21_floor(s21_POS_INF));
  ck_assert_ldouble_infinite(floor(s21_POS_INF));
}
END_TEST

START_TEST(test_neg_inf) {
  ck_assert_ldouble_infinite(s21_floor(s21_NEG_INF));
  ck_assert_ldouble_infinite(floor(s21_NEG_INF));
}
END_TEST

START_TEST(floor_nan) {
  ck_assert_ldouble_nan(s21_floor(s21_NAN));
  ck_assert_ldouble_nan(floor(s21_NAN));
}
END_TEST

START_TEST(floor_zero) { ck_assert_ldouble_eq(s21_floor(0.0), floor(0.0)); }
END_TEST

START_TEST(test_inf_y_zero) {
  double x = 8754713577135713757.9994943934934977;
  ck_assert_ldouble_eq(s21_floor(x), floor(x));
}
END_TEST

START_TEST(floor_small) {
  ck_assert_ldouble_eq(s21_floor(1e-18), floor(1e-18));
}
END_TEST

START_TEST(floor_half) { ck_assert_ldouble_eq(s21_floor(2.5), floor(2.5)); }
END_TEST

START_TEST(floor_big) {
  ck_assert_ldouble_eq(s21_floor(99.999999991), floor(99.9999999991));
}
END_TEST

START_TEST(floor_half_negative) {
  ck_assert_ldouble_eq(s21_floor(-2.5), floor(-2.5));
}
END_TEST

START_TEST(floor_negative) {
  ck_assert_ldouble_eq(s21_floor(-99999999.9999999), floor(-99999999.9999999));
}
END_TEST

START_TEST(floor_PI) { ck_assert_ldouble_eq(s21_floor(s21_PI), floor(s21_PI)); }
END_TEST

START_TEST(log_1) {
  double num = 456.789;
  long double orig_res = log(num);
  long double our_res = s21_log(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(log_2) {
  double num = s21_NAN;
  long double orig_res = log(num);
  long double our_res = s21_log(num);
  int suc = 0;
  if (s21_is_nan(our_res) && s21_is_nan(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(log_3) {
  double num = 0.001;
  long double orig_res = log(num);
  long double our_res = s21_log(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(log_4) {
  double num = 0.4;
  long double orig_res = log(num);
  long double our_res = s21_log(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(log_5) {
  double num = s21_NEG_INF;
  long double orig_res = log(num);
  long double our_res = s21_log(num);
  int suc = 0;
  if (s21_is_nan(our_res) && s21_is_nan(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(log_6) {
  for (double i = 0.001; i < 5.0; i += 0.001)
    ck_assert_ldouble_eq_tol(s21_log(i), log(i), s21_EPS);
}
END_TEST

START_TEST(log_7) {
  ck_assert_ldouble_infinite(s21_log(s21_POS_INF));
  ck_assert_ldouble_infinite(log(s21_POS_INF));
}
END_TEST

START_TEST(log_8) {
  ck_assert_ldouble_nan(s21_log(s21_NEG_INF));
  ck_assert_ldouble_nan(log(s21_NEG_INF));
}
END_TEST

START_TEST(log_9) {
  ck_assert_ldouble_nan(s21_log(s21_NAN));
  ck_assert_ldouble_nan(log(s21_NAN));
}
END_TEST

START_TEST(log_10) {
  ck_assert_ldouble_eq_tol(s21_log(1.1), log(1.1), s21_EPS);
}
END_TEST

START_TEST(log_11) {
  ck_assert_ldouble_eq_tol(s21_log(0.5), log(0.5), s21_EPS);
}
END_TEST

START_TEST(log_12) { ck_assert_ldouble_eq_tol(s21_log(1), log(1), s21_EPS); }
END_TEST

START_TEST(log_13) {
  ck_assert_ldouble_eq_tol(s21_log(100), log(100), s21_EPS);
}
END_TEST

START_TEST(log_14) {
  ck_assert_ldouble_eq_tol(s21_log(0.5), log(0.5), s21_EPS);
}
END_TEST

START_TEST(log_15) {
  ck_assert_ldouble_eq_tol(s21_log(0.5), log(0.5), s21_EPS);
}
END_TEST

START_TEST(log_16) {
  ck_assert_ldouble_eq_tol(s21_log(s21_DBL_MAX), log(s21_DBL_MAX), s21_EPS);
}
END_TEST

START_TEST(log_17) {
  ck_assert_ldouble_eq_tol(s21_log(s21_PI / 3), log(s21_PI / 3), s21_EPS);
}
END_TEST

START_TEST(log_18) {
  ck_assert_ldouble_eq_tol(s21_log(9.234578353457e-6), log(9.234578353457e-6),
                           s21_EPS);
}
END_TEST

START_TEST(log_19) {
  ck_assert_ldouble_eq_tol(s21_log(9.234578353457e6), log(9.234578353457e6),
                           s21_EPS);
}
END_TEST

START_TEST(log_20) {
  ck_assert_ldouble_eq_tol(s21_log(1234567.000000004), log(1234567.000000004),
                           s21_EPS);
}
END_TEST

START_TEST(log_21) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-16), log(1.1e-16), s21_EPS);
}
END_TEST

START_TEST(log_22) {
  ck_assert_ldouble_eq_tol(s21_log(987654321123.123e-30),
                           log(987654321123.123e-30), s21_EPS);
}
END_TEST

START_TEST(log_23) {
  ck_assert_ldouble_eq_tol(s21_log(98765.123e-11), log(98765.123e-11), s21_EPS);
}
END_TEST

START_TEST(log_24) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-45), log(1.1e-45), s21_EPS);
}
END_TEST

START_TEST(log_25) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-18), log(1.1e-18), s21_EPS);
}
END_TEST

START_TEST(log_26) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-19), log(1.1e-19), s21_EPS);
}
END_TEST

START_TEST(log_27) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-23), log(1.1e-23), s21_EPS);
}
END_TEST

START_TEST(log_28) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-17), log(1.1e-17), s21_EPS);
}
END_TEST

START_TEST(log_29) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-15), log(1.1e-15), s21_EPS);
}
END_TEST

START_TEST(log_30) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-14), log(1.1e-14), s21_EPS);
}
END_TEST

START_TEST(log_31) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-13), log(1.1e-13), s21_EPS);
}
END_TEST

START_TEST(log_32) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-12), log(1.1e-12), s21_EPS);
}
END_TEST

START_TEST(log_33) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-11), log(1.1e-11), s21_EPS);
}
END_TEST

START_TEST(log_34) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-80), log(1.1e-80), s21_EPS);
}
END_TEST

START_TEST(is_zero) {
  ck_assert_ldouble_infinite(s21_log(0));
  ck_assert_ldouble_infinite(s21_NEG_INF);
}
END_TEST

START_TEST(exp_0) {
  double x = 0;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_1) {
  double x = 1.0;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_2) {
  double x = 2.9;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_3) {
  double x = 3;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_4) {
  double x = 1.5;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_5) {
  double x = -1.5;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_6) {
  double x = 0.5;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_7) {
  double x = -0.5;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_8) {
  double x = 715;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_9) {
  double x = -715;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_10) {
  double x = -0;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_11) {
  double x = 'A';
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_12) {
  double x = -'N';
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_13) {
  double x = -'V';
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_14) {
  double x = +'B';
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_15) {
  double x = 0 / 1;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_16) {
  double x = 0 / 1;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_17) { ck_assert_float_eq(s21_exp(2), exp(2)); }
END_TEST

START_TEST(exp_18) { ck_assert_float_eq(s21_exp(-750), exp(-750)); }
END_TEST

START_TEST(exp_19) { ck_assert_float_eq(s21_exp(-2), exp(-2)); }
END_TEST

START_TEST(exp_20) {
  double num = s21_NAN;
  long double orig_res = exp(num), our_res = s21_exp(num);
  int suc = 0;
  if (s21_is_nan(orig_res) && s21_is_nan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(exp_22) {
  double num = s21_NEG_INF;
  long double orig_res = exp(num), our_res = s21_exp(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(exp_23) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), 1e-06);
}
END_TEST

START_TEST(exp_24) {
  ck_assert_ldouble_eq_tol(s21_exp(s21_NEG_INF), expl(s21_NEG_INF), 1e-06);
}
END_TEST

START_TEST(exp_25) {
  ck_assert_ldouble_infinite(s21_exp(s21_POS_INF));
  ck_assert_ldouble_infinite(expl(s21_POS_INF));
}
END_TEST

START_TEST(exp_26) {
  ck_assert_ldouble_nan(s21_exp(s21_NAN));
  ck_assert_ldouble_nan(expl(s21_NAN));
}
END_TEST

START_TEST(exp_27) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), s21_EPS);
}
END_TEST

START_TEST(exp_28) {
  double x = -1.0;
  ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), s21_EPS);
}
END_TEST

START_TEST(exp_29) {
  double x = -100;
  ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), s21_EPS);
}
END_TEST

START_TEST(exp_30) {
  double x = -1000000;
  ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), s21_EPS);
}
END_TEST

START_TEST(exp_31) {
  double x = 1;
  ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), s21_EPS);
}
END_TEST

START_TEST(exp_Last) {
  double x = 1;
  ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), s21_EPS);
}
END_TEST

START_TEST(sqrt_1) {
  for (double i = -10000.0; i < 10000.0; i++) {
    if (i >= 0.0)
      ck_assert_ldouble_eq_tol(s21_sqrt(i), sqrt(i), s21_EPS);
    else
      ck_assert_ldouble_nan(s21_sqrt(i));
  }
}
END_TEST

START_TEST(sqrt_2) {
  double num = s21_NEG_INF;
  long double orig_res = sqrt(num), our_res = s21_sqrt(num);
  int suc = 0;
  if (s21_is_nan(orig_res) && s21_is_nan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(sqrt_4) {
  double num = 0.9999;
  long double orig_res = sqrt(num), our_res = s21_sqrt(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= s21_EPS)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(sqrt_5) {
  double num = s21_NAN;
  long double orig_res = sqrt(num), our_res = s21_sqrt(num);
  int suc = 0;
  if (s21_is_nan(orig_res) && s21_is_nan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(sqrt_6) { ck_assert_ldouble_nan(s21_sqrt(s21_POS_INF)); }
END_TEST

START_TEST(sqrt_7) {
  ck_assert_ldouble_nan(s21_sqrt(s21_NAN));
  ck_assert_ldouble_nan(sqrt(s21_NAN));
}
END_TEST

START_TEST(sqrt_8) {
  ck_assert_ldouble_eq_tol(s21_sqrt(1.0), sqrt(1.0), s21_EPS);
}
END_TEST

START_TEST(sqrt_9) {
  ck_assert_ldouble_eq_tol(s21_sqrt(0.0), sqrt(0.0), s21_EPS);
}
END_TEST

START_TEST(sqrt_10) {
  ck_assert_ldouble_eq_tol(s21_sqrt(1e+16), sqrt(1e+16), s21_EPS);
}
END_TEST

START_TEST(sqrt_12) { ck_assert_ldouble_eq_tol(s21_sqrt(1), sqrt(1), s21_EPS); }
END_TEST

START_TEST(sqrt_13) {
  ck_assert_ldouble_eq_tol(s21_sqrt(100), sqrt(100), s21_EPS);
}
END_TEST

START_TEST(sqrt_14) {
  ck_assert_ldouble_eq_tol(s21_sqrt(98765432.123), sqrt(98765432.123), s21_EPS);
}
END_TEST

START_TEST(sqrt_15) {
  ck_assert_ldouble_eq_tol(s21_sqrt(981.123e6), sqrt(981.123e6), s21_EPS);
}
END_TEST

START_TEST(sqrt_16) {
  ck_assert_ldouble_eq_tol(s21_sqrt(-0.0), sqrt(-0.0), s21_EPS);
}
END_TEST

START_TEST(sqrt_17) {
  ck_assert_ldouble_eq_tol(s21_sqrt(1.1), sqrt(1.1), s21_EPS);
}
END_TEST

START_TEST(sqrt_Last) {
  ck_assert_ldouble_eq_tol(s21_sqrt(981.123e-15), sqrt(981.123e-15), s21_EPS);
}
END_TEST

START_TEST(fmod_1) {
  ck_assert_ldouble_eq(s21_fmod(2.34, 2.0), fmod(2.34, 2.0));
}
END_TEST

START_TEST(fmod_2) {
  ck_assert_ldouble_eq(s21_fmod(-2.34, 2.0), fmod(-2.34, 2.0));
}
END_TEST

START_TEST(fmod_3) {
  ck_assert_ldouble_eq(s21_fmod(2.34, -2.0), fmod(2.34, -2.0));
}
END_TEST

START_TEST(fmod_4) {
  ck_assert_ldouble_eq(s21_fmod(-2.34, -2.0), fmod(-2.34, -2.0));
}
END_TEST

START_TEST(fmod_5) { ck_assert_ldouble_eq(s21_fmod(21.21, 3), fmod(21.21, 3)); }
END_TEST

START_TEST(fmod_6) { ck_assert_ldouble_eq(s21_fmod(3, 21.21), fmod(3, 21.21)); }
END_TEST

START_TEST(fmod_7) {
  ck_assert_ldouble_eq(s21_fmod(-21.21, 3), fmod(-21.21, 3));
}
END_TEST

START_TEST(fmod_8) {
  ck_assert_ldouble_eq(s21_fmod(3, -21.21), fmod(3, -21.21));
}
END_TEST

START_TEST(fmod_9) {
  ck_assert_ldouble_eq(s21_fmod(100500, 9), fmod(100500, 9));
}
END_TEST

START_TEST(fmod_10) {
  ck_assert_ldouble_eq(s21_fmod(-100500, -9), fmod(-100500, -9));
}
END_TEST

START_TEST(fmod_11) {
  ck_assert_ldouble_eq(s21_fmod(-9, -100500), fmod(-9, -100500));
}
END_TEST

START_TEST(fmod_12) { ck_assert_ldouble_eq(s21_fmod(-9, -9), fmod(-9, -9)); }
END_TEST

START_TEST(fmod_13) { ck_assert_ldouble_eq(s21_fmod(10, 5), fmod(10, 5)); }
END_TEST

START_TEST(fmod_14) {
  ck_assert_ldouble_nan(s21_fmod(s21_POS_INF, s21_POS_INF));
  ck_assert_ldouble_nan(fmod(s21_POS_INF, s21_POS_INF));
}
END_TEST

START_TEST(fmod_15) { ck_assert_ldouble_nan(s21_fmod(s21_NAN, s21_NAN)); }
END_TEST

START_TEST(fmod_16) { ck_assert_ldouble_nan(s21_fmod(2.45, 0)); }
END_TEST

START_TEST(fmod_17) { ck_assert_ldouble_nan(s21_fmod(0, 0)); }
END_TEST

START_TEST(fmod_18) { ck_assert_ldouble_nan(s21_fmod(s21_POS_INF, 0)); }
END_TEST

START_TEST(fmod_19) {
  double num = s21_NAN;
  long double orig_res = fmod(num, 2.0), our_res = s21_fmod(num, 2.0);
  int suc = 0;
  if (s21_is_nan(orig_res) && s21_is_nan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(fmod_20) {
  double num = s21_NAN;
  long double orig_res = fmod(2.0, num), our_res = s21_fmod(2.0, num);
  int suc = 0;
  if (s21_is_nan(orig_res) && s21_is_nan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(fmod_21) {
  ck_assert_ldouble_eq(s21_fmod(2.0, s21_POS_INF), fmod(2.0, s21_POS_INF));
}
END_TEST

START_TEST(fmod_22) {
  double num = s21_POS_INF;
  long double orig_res = fmod(num, 2.0), our_res = s21_fmod(num, 2.0);
  int suc = 0;
  if (s21_is_nan(orig_res) && s21_is_nan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(fmod_23) {
  ck_assert_ldouble_eq(s21_fmod(2.0, s21_POS_INF), fmod(2.0, s21_POS_INF));
}
END_TEST

START_TEST(fmod_25) {
  ck_assert_ldouble_nan(s21_fmod(s21_POS_INF, s21_POS_INF));
  ck_assert_ldouble_nan(fmod(s21_POS_INF, s21_POS_INF));
}
END_TEST

START_TEST(fmod_Last) { ck_assert_ldouble_eq(s21_fmod(0, 23), fmod(0, 23)); }
END_TEST

START_TEST(pow_1) {
  double num = 456.789;
  double ex = 1.1;
  long double orig_res = pow(num, ex), our_res = s21_pow(num, ex);
  int suc = 0;
  ck_assert_float_eq(our_res, orig_res);
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(pow_2) {
  double num = s21_POS_INF;
  double ex = 1.1;
  long double orig_res = pow(num, ex), our_res = s21_pow(num, ex);
  int suc = 0;
  if (s21_is_inf(our_res) && s21_is_inf(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(pow_3) {
  double num = s21_NAN;
  double ex = 1.1;
  long double orig_res = pow(num, ex), our_res = s21_pow(num, ex);
  int suc = 0;
  if (s21_is_nan(our_res) && s21_is_nan(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(pow_4) {
  double num = s21_NAN;
  double ex = s21_NAN;
  long double orig_res = pow(num, ex), our_res = s21_pow(num, ex);
  int suc = 0;
  if (s21_is_nan(our_res) && s21_is_nan(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(pow_5) {
  double num = 0.001;
  double ex = s21_NAN;
  long double orig_res = pow(num, ex), our_res = s21_pow(num, ex);
  int suc = 0;
  if (s21_is_nan(our_res) && s21_is_nan(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(pow_6) {
  double num = s21_POS_INF;
  double ex = s21_POS_INF;
  long double orig_res = pow(num, ex), our_res = s21_pow(num, ex);
  int suc = 0;
  if (s21_is_inf(our_res) && s21_is_inf(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(pow_7) {
  double num = s21_POS_INF;
  double ex = s21_POS_INF;
  long double orig_res = pow(num, ex), our_res = s21_pow(num, ex);
  int suc = 0;
  if (s21_is_inf(our_res) && s21_is_inf(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(pow_8) {
  long double base = -16.161435;
  long double exp = 9.;
  ck_assert_double_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_9) {
  long double base = -10.1261;
  long double exp = -0.72;
  ck_assert_double_nan(s21_pow(base, exp));
  ck_assert_double_nan(pow(base, exp));
}
END_TEST

START_TEST(pow_10) {
  long double base = +0;
  long double exp = -0.33;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_12) {
  long double base = -0;
  long double exp = -0.33;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_13) {
  long double base = -0;
  long double exp = s21_POS_INF;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), s21_EPS);
}
END_TEST

START_TEST(pow_14) {
  long double base = +0;
  long double exp = 123;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), s21_EPS);
}
END_TEST

START_TEST(pow_15) {
  long double base = -0;
  long double exp = 123;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), s21_EPS);
}
END_TEST

START_TEST(pow_16) {
  long double base = -0;
  long double exp = s21_POS_INF;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), s21_EPS);
}
END_TEST

START_TEST(pow_17) {
  long double base = -1;
  long double exp = s21_POS_INF;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), s21_EPS);
}
END_TEST

START_TEST(pow_18) {
  long double base = -1;
  long double exp = s21_NAN;
  ck_assert_double_nan(pow(base, exp));
  ck_assert_double_nan(s21_pow(base, exp));
}
END_TEST

START_TEST(pow_19) {
  long double base = s21_NAN;
  long double exp = 0;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), s21_EPS);
}
END_TEST

START_TEST(pow_20) {
  long double base = -123;
  long double exp = s21_NAN;
  ck_assert_double_nan(s21_pow(base, exp));
  ck_assert_double_nan(pow(base, exp));
}
END_TEST

START_TEST(pow_21) {
  long double base = 0.5591951;
  long double exp = s21_NEG_INF;
  ck_assert_ldouble_infinite(pow(base, exp));
  ck_assert_ldouble_infinite(s21_pow(base, exp));
}
END_TEST

START_TEST(pow_22) {
  long double base = 1.5591951;
  long double exp = s21_NEG_INF;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), s21_EPS);
}
END_TEST

START_TEST(pow_23) {
  long double base = 0.5591951;
  long double exp = s21_POS_INF;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), s21_EPS);
}
END_TEST

START_TEST(pow_24) {
  long double base = 1.5591951;
  long double exp = s21_POS_INF;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_25) {
  long double base = s21_NEG_INF;
  long double exp = -193491;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), s21_EPS);
}
END_TEST

START_TEST(pow_26) {
  long double base = s21_NEG_INF;
  long double exp = -142;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), s21_EPS);
}
END_TEST

START_TEST(pow_27) {
  long double base = s21_NEG_INF;
  long double exp = 141;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_28) {
  long double base = s21_NEG_INF;
  long double exp = 142;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_29) {
  long double base = s21_POS_INF;
  long double exp = -1;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), s21_EPS);
}
END_TEST

START_TEST(pow_30) {
  long double base = s21_POS_INF;
  long double exp = 1;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_31) {
  ck_assert_ldouble_eq_tol(s21_pow(0.0, 0.0), pow(0.0, 0.0), s21_EPS);
}
END_TEST

START_TEST(pow_32) {
  ck_assert_ldouble_eq_tol(s21_pow(-1, 4), pow(-1, 4), s21_EPS);
}
END_TEST

START_TEST(pow_33) {
  ck_assert_ldouble_eq_tol(s21_pow(2, 18), pow(2, 18), s21_EPS);
}
END_TEST

START_TEST(pow_34) {
  ck_assert_ldouble_eq_tol(s21_pow(2.1, 11), pow(2.1, 11), s21_EPS);
}
END_TEST

START_TEST(pow_35) {
  ck_assert_ldouble_eq_tol(s21_pow(1.23456e-7, 2.21), pow(1.23456e-7, 2.21),
                           s21_EPS);
}
END_TEST

START_TEST(pow_36) {
  ck_assert_ldouble_eq_tol(s21_pow(2.1234567, -2), pow(2.1234567, -2), s21_EPS);
}
END_TEST

START_TEST(pow_37) {
  ck_assert_ldouble_eq_tol(s21_pow(2.1234567, -2), pow(2.1234567, -2), s21_EPS);
}
END_TEST

START_TEST(pow_38) {
  long double orig_res = pow(2.1234567e-7, -2.45e4),
              our_res = s21_pow(2.1234567e-7, -2.45e4);
  int suc = 0;
  if (s21_is_inf(our_res) && s21_is_inf(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(pow_39) {
  ck_assert_ldouble_eq_tol(s21_pow(9.99999999e3, 9.95e-4),
                           pow(9.99999999e3, 9.95e-4), s21_EPS);
}
END_TEST

START_TEST(pow_40) {
  long double exp = -12;
  ck_assert_ldouble_infinite(s21_pow(+0, exp));
  ck_assert_ldouble_infinite(pow(+0, exp));
}
END_TEST

START_TEST(pow_41) {
  long double exp = -12;
  ck_assert_ldouble_infinite(s21_pow(-0, exp));
  ck_assert_ldouble_infinite(pow(-0, exp));
}
END_TEST

START_TEST(pow_42) {
  long double exp = 0;
  ck_assert_ldouble_eq_tol(s21_pow(-0, exp), pow(-0, exp), s21_EPS);
}
END_TEST

START_TEST(pow_43) {
  long double exp = 2.456;
  ck_assert_ldouble_eq_tol(s21_pow(+0, exp), pow(+0, exp), s21_EPS);
}
END_TEST

START_TEST(pow_44) {
  long double exp = s21_NEG_INF;
  ck_assert_ldouble_infinite(s21_pow(+0, exp));
  ck_assert_ldouble_infinite(pow(+0, exp));
}
END_TEST

START_TEST(pow_45) {
  long double exp = 56;
  ck_assert_ldouble_eq_tol(s21_pow(+0, exp), pow(+0, exp), s21_EPS);
}
END_TEST

START_TEST(pow_46) {
  long double exp = 56;
  ck_assert_ldouble_eq_tol(s21_pow(-0, exp), pow(-0, exp), s21_EPS);
}
END_TEST

START_TEST(pow_47) {
  long double exp = 56.345;
  ck_assert_ldouble_eq_tol(s21_pow(-0, exp), pow(-0, exp), s21_EPS);
}
END_TEST

START_TEST(pow_48) {
  long double exp = s21_POS_INF;
  ck_assert_ldouble_eq_tol(s21_pow(-1, exp), pow(-1, exp), s21_EPS);
}
END_TEST

START_TEST(pow_49) {
  long double exp = s21_NEG_INF;
  ck_assert_ldouble_eq_tol(s21_pow(-1, exp), pow(-1, exp), s21_EPS);
}
END_TEST

START_TEST(pow_50) {
  long double exp = s21_NAN;
  ck_assert_ldouble_eq_tol(s21_pow(+1, exp), pow(+1, exp), s21_EPS);
}
END_TEST

START_TEST(pow_51) {
  long double exp = -0;
  ck_assert_ldouble_eq_tol(s21_pow(4567, exp), pow(4567, exp), s21_EPS);
}
END_TEST

START_TEST(pow_52) {
  long double exp = +0;
  ck_assert_ldouble_eq_tol(s21_pow(34567, exp), pow(34567, exp), s21_EPS);
}
END_TEST

START_TEST(pow_53) {
  long double exp = -0;
  ck_assert_ldouble_eq_tol(s21_pow(s21_NAN, exp), pow(s21_NAN, exp), s21_EPS);
}
END_TEST

START_TEST(pow_54) {
  long double exp = +0;
  ck_assert_ldouble_eq_tol(s21_pow(s21_NAN, exp), pow(s21_NAN, exp), s21_EPS);
}
END_TEST

START_TEST(pow_55) {
  long double exp = s21_NAN;
  ck_assert_double_nan(s21_pow(s21_NAN, exp));
  ck_assert_double_nan(pow(s21_NAN, exp));
}
END_TEST

START_TEST(pow_56) {
  long double exp = s21_POS_INF;
  ck_assert_ldouble_infinite(s21_pow(s21_POS_INF, exp));
  ck_assert_ldouble_infinite(pow(s21_POS_INF, exp));
}
END_TEST

START_TEST(pow_57) {
  long double exp = s21_NEG_INF;
  ck_assert_ldouble_eq_tol(s21_pow(s21_NEG_INF, exp), pow(s21_NEG_INF, exp),
                           s21_EPS);
}
END_TEST

START_TEST(pow_58) {
  double exp = s21_POS_INF;
  ck_assert_ldouble_infinite(s21_pow(s21_NEG_INF, exp));
  ck_assert_ldouble_infinite(pow(s21_NEG_INF, exp));
}
END_TEST

START_TEST(pow_59) {
  double exp;
  double res1;
  long double res2;

  for (exp = 0.0; exp > -1000; exp -= 0.1) {
    res1 = pow(s21_POS_INF, exp);
    res2 = s21_pow(s21_POS_INF, exp);
  }
  ck_assert_ldouble_eq_tol(res1, res2, s21_EPS);
}
END_TEST

START_TEST(pow_60) {
  double base;
  double res1;
  long double res2;

  for (base = 0.0; base < 10; base += 0.1) {
    res1 = pow(base, s21_POS_INF);
    res2 = s21_pow(base, s21_POS_INF);
  }
  ck_assert_ldouble_infinite(res1);
  ck_assert_ldouble_infinite(res2);
}
END_TEST

START_TEST(pow_61) {
  double base;
  double res1;
  long double res2;

  for (base = 0.0; base > -10; base -= 0.1) {
    res1 = pow(base, s21_POS_INF);
    res2 = s21_pow(base, s21_POS_INF);
  }
  ck_assert_ldouble_infinite(res1);
  ck_assert_ldouble_infinite(res2);
}
END_TEST

START_TEST(pow_62) {
  long double base;
  long double res1;
  long double res2;

  for (base = 0.0; base < 10; base += 0.1) {
    res1 = pow(base, s21_NEG_INF);
    res2 = s21_pow(base, s21_NEG_INF);
  }
  ck_assert_ldouble_eq_tol(res1, res2, s21_EPS);
}
END_TEST

START_TEST(pow_63) {
  long double base;
  long double res1;
  long double res2;

  for (base = 0.0; base > -10; base -= 0.1) {
    res1 = pow(base, s21_NEG_INF);
    res2 = s21_pow(base, s21_NEG_INF);
  }
  ck_assert_ldouble_eq_tol(res1, res2, s21_EPS);
}
END_TEST

START_TEST(pow_64) {
  double exp;
  double res1;
  long double res2;

  for (exp = 0.0; exp > -10; exp -= 0.1) {
    if (fmod(exp, 2) == 0) {
      res1 = pow(s21_NEG_INF, exp);
      res2 = s21_pow(s21_NEG_INF, exp);
    }
  }
  ck_assert_ldouble_eq_tol(res1, res2, s21_EPS);
}
END_TEST

START_TEST(pow_65) {
  double exp;
  double res1;
  long double res2;

  for (exp = 0.0; exp < 10; exp += 0.1) {
    if (fmod(exp, 2) == 0) {
      res1 = pow(s21_NEG_INF, exp);
      res2 = s21_pow(s21_NEG_INF, exp);
    }
  }
  ck_assert_ldouble_eq_tol(res2, res1, s21_EPS);
}
END_TEST

START_TEST(pow_66) {
  long double exp = 3;
  ck_assert_ldouble_eq_tol(s21_pow(-3, exp), pow(-3, exp), s21_EPS);
}
END_TEST

START_TEST(pow_67) {
  long double exp = -3;
  ck_assert_ldouble_eq_tol(s21_pow(-3, exp), pow(-3, exp), s21_EPS);
}
END_TEST

START_TEST(pow_68) {
  long double exp = -3;
  ck_assert_ldouble_eq_tol(s21_pow(3, exp), pow(3, exp), s21_EPS);
}
END_TEST

START_TEST(pow_69) {
  long double exp = 3;
  ck_assert_ldouble_eq_tol(s21_pow(3, exp), pow(3, exp), s21_EPS);
}
END_TEST

START_TEST(pow_70) {
  long double base = -0;
  long double exp = s21_POS_INF;
  long double res = pow(base, exp);
  long double res1 = s21_pow(base, exp);
  ck_assert_ldouble_eq_tol(res, res1, s21_EPS);
}
END_TEST

START_TEST(pow_Last) {
  long double exp;
  long double base = -0;
  long double res;
  long double res1;
  for (exp = 0.0; exp < 10; exp += 0.1) {
    if (s21_fmod(exp, 2) != 0) {
      res = pow(base, exp);
      res1 = s21_pow(base, exp);
    }
  }
  ck_assert_ldouble_eq_tol(res, res1, s21_EPS);
}
END_TEST

START_TEST(sin_1) {
  double num = 0.55;
  long double orig_res = sin(num), our_res = s21_sin(num);
  int suc = 0;
  if ((s21_fabs(orig_res - our_res) <= s21_EPS)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(sin_2) { ck_assert_float_eq(s21_sin(0), sin(0)); }
END_TEST

START_TEST(sin_3) {
  double num = 1;
  long double orig_res = s21_sin(num), our_res = s21_sin(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= s21_EPS)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(sin_4) {
  double num = -1;
  long double orig_res = s21_sin(num), our_res = s21_sin(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= s21_EPS)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(sin_5) {
  double num = 0.999999;
  long double orig_res = s21_sin(num), our_res = s21_sin(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= s21_EPS)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(sin_6) {
  double num = -0.999999;
  long double orig_res = s21_sin(num), our_res = s21_sin(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= s21_EPS)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(sin_7) {
  ck_assert_int_eq(s21_is_nan(asin(s21_NAN)), s21_is_nan(s21_asin(s21_NAN)));
}
END_TEST

START_TEST(sin_8) {
  ck_assert_int_eq(s21_is_nan(asin(s21_POS_INF)),
                   s21_is_nan(s21_asin(s21_POS_INF)));
}
END_TEST

START_TEST(sin_9) {
  ck_assert_int_eq(s21_is_nan(asin(s21_NEG_INF)),
                   s21_is_nan(s21_asin(s21_NEG_INF)));
}
END_TEST

START_TEST(sin_10) {
  double x = 0;
  ck_assert_double_eq_tol(s21_sin(x), sinl(x), 1e-06);
}
END_TEST

START_TEST(sin_11) {
  ck_assert_ldouble_nan(s21_sin(s21_NEG_INF));
  ck_assert_ldouble_nan(sin(s21_NEG_INF));
}
END_TEST

START_TEST(sin_12) {
  ck_assert_ldouble_nan(s21_sin(s21_POS_INF));
  ck_assert_ldouble_nan(sin(s21_POS_INF));
}
END_TEST

START_TEST(sin_13) {
  ck_assert_ldouble_nan(s21_sin(s21_NAN));
  ck_assert_ldouble_nan(sin(s21_NAN));
}
END_TEST

START_TEST(sin_14) { ck_assert_double_eq_tol(s21_sin(0.0), sin(0.0), s21_EPS); }
END_TEST

START_TEST(sin_15) {
  ck_assert_double_eq_tol(s21_sin(s21_PI / 6), sin(s21_PI / 6), s21_EPS);
}
END_TEST

START_TEST(sin_16) {
  ck_assert_double_eq_tol(s21_sin(s21_PI / 4), sin(s21_PI / 4), s21_EPS);
}
END_TEST

START_TEST(sin_17) {
  ck_assert_double_eq_tol(s21_sin(s21_PI / 3), sin(s21_PI / 3), s21_EPS);
}
END_TEST

START_TEST(sin_18) {
  ck_assert_double_eq_tol(s21_sin(s21_PI / 2), sin(s21_PI / 2), s21_EPS);
}
END_TEST

START_TEST(sin_19) {
  ck_assert_double_eq_tol(s21_sin(3 * s21_PI / 2), sin(3 * s21_PI / 2),
                          s21_EPS);
}
END_TEST

START_TEST(sin_20) {
  ck_assert_double_eq_tol(s21_sin(2 * s21_PI), sin(2 * s21_PI), s21_EPS);
}
END_TEST

START_TEST(sin_21) {
  ck_assert_double_eq_tol(s21_sin(-2 * s21_PI), sin(-2 * s21_PI), s21_EPS);
}
END_TEST

START_TEST(sin_22) {
  ck_assert_double_eq_tol(s21_sin(-3 * s21_PI), sin(-3 * s21_PI), s21_EPS);
}
END_TEST

START_TEST(sin_23) {
  ck_assert_double_eq_tol(s21_sin(174.532925199433), sin(174.532925199433),
                          s21_EPS);
}
END_TEST

START_TEST(sin_24) {
  ck_assert_double_eq_tol(s21_sin(-174.532925199433), sin(-174.532925199433),
                          s21_EPS);
}
END_TEST

START_TEST(sin_25) {
  ck_assert_double_eq_tol(s21_sin(-s21_PI), sin(-s21_PI), s21_EPS);
}
END_TEST

START_TEST(sin_Last) {
  ck_assert_double_eq_tol(s21_sin(s21_PI), sin(s21_PI), s21_EPS);
}
END_TEST

START_TEST(cos_1) {
  double num = 0.55;
  long double orig_res = s21_cos(num), our_res = s21_cos(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= s21_EPS)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(cos_2) {
  double num = -0.999999;
  long double orig_res = cos(num), our_res = s21_cos(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= s21_EPS)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(cos_3) {
  double num = 628;
  long double orig_res = cos(num), our_res = s21_cos(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= s21_EPS)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(cos_4) { ck_assert_float_eq(s21_cos(0), cos(0)); }
END_TEST

START_TEST(cos_5) { ck_assert_float_eq(s21_cos(-1), cos(-1)); }
END_TEST

START_TEST(cos_6) {
  ck_assert_int_eq(s21_is_nan(asin(s21_NAN)), s21_is_nan(s21_asin(s21_NAN)));
}
END_TEST

START_TEST(cos_7) {
  ck_assert_int_eq(s21_is_nan(asin(s21_POS_INF)),
                   s21_is_nan(s21_asin(s21_POS_INF)));
}
END_TEST

START_TEST(cos_8) {
  ck_assert_int_eq(s21_is_nan(asin(s21_NEG_INF)),
                   s21_is_nan(s21_asin(s21_NEG_INF)));
}
END_TEST

START_TEST(cos_9) {
  double x = 0;
  ck_assert_double_eq_tol(s21_cos(x), cosl(x), s21_EPS);
}
END_TEST

START_TEST(cos_10) {
  ck_assert_ldouble_nan(s21_cos(s21_NEG_INF));
  ck_assert_ldouble_nan(cosl(s21_NEG_INF));
}
END_TEST

START_TEST(cos_11) {
  ck_assert_ldouble_nan(s21_cos(s21_POS_INF));
  ck_assert_ldouble_nan(cos(s21_POS_INF));
}
END_TEST

START_TEST(cos_12) {
  ck_assert_ldouble_nan(s21_cos(s21_NAN));
  ck_assert_ldouble_nan(cos(s21_NAN));
}
END_TEST

START_TEST(cos_13) { ck_assert_double_eq_tol(s21_cos(0.0), cos(0.0), s21_EPS); }
END_TEST

START_TEST(cos_14) {
  ck_assert_double_eq_tol(s21_cos(s21_PI / 4), cos(M_PI / 4), s21_EPS);
}
END_TEST

START_TEST(cos_15) {
  ck_assert_double_eq_tol(s21_cos(s21_PI / 6), cos(M_PI / 6), s21_EPS);
}
END_TEST

START_TEST(cos_16) {
  ck_assert_double_eq_tol(s21_cos(s21_PI / 3), cos(s21_PI / 3), s21_EPS);
}
END_TEST

START_TEST(cos_17) {
  ck_assert_double_eq_tol(s21_cos(s21_PI / 2), cos(s21_PI / 2), s21_EPS);
}
END_TEST

START_TEST(cos_18) {
  ck_assert_double_eq_tol(s21_cos(3 * s21_PI / 2), cosl(3 * s21_PI / 2),
                          s21_EPS);
}
END_TEST

START_TEST(cos_19) {
  ck_assert_double_eq_tol(s21_cos(2 * s21_PI), cosl(2 * s21_PI), s21_EPS);
}
END_TEST

START_TEST(cos_20) {
  ck_assert_double_eq_tol(s21_cos(174.532925199433), cosl(174.532925199433),
                          s21_EPS);
}
END_TEST

START_TEST(cos_Last) {
  ck_assert_double_eq_tol(s21_cos(-174.532925199433), cosl(-174.532925199433),
                          s21_EPS);
}
END_TEST

START_TEST(tan_1) { ck_assert_float_eq(s21_tan(-15.01), tan(-15.01)); }
END_TEST

START_TEST(tan_2) {
  double num = 0.55;
  long double orig_res = s21_tan(num), our_res = s21_tan(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= s21_EPS)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(tan_3) { ck_assert_float_eq(-9999999999, -9999999999); }
END_TEST

START_TEST(tan_4) {
  ck_assert_int_eq(s21_is_nan(asin(s21_NAN)), s21_is_nan(s21_asin(s21_NAN)));
}
END_TEST

START_TEST(tan_5) {
  ck_assert_int_eq(s21_is_nan(asin(s21_POS_INF)),
                   s21_is_nan(s21_asin(s21_POS_INF)));
}
END_TEST

START_TEST(tan_6) {
  ck_assert_int_eq(s21_is_nan(asin(s21_NEG_INF)),
                   s21_is_nan(s21_asin(s21_NEG_INF)));
}
END_TEST

START_TEST(tan_7) {
  double x = 0;
  ck_assert_double_eq_tol(s21_tan(x), tanl(x), s21_EPS);
}
END_TEST

START_TEST(tan_8) {
  ck_assert_ldouble_nan(s21_tan(s21_NEG_INF));
  ck_assert_ldouble_nan(tanl(s21_NEG_INF));
}
END_TEST

START_TEST(tan_9) {
  ck_assert_ldouble_nan(s21_tan(s21_POS_INF));
  ck_assert_ldouble_nan(tan(s21_POS_INF));
}
END_TEST

START_TEST(tan_10) {
  ck_assert_ldouble_nan(s21_tan(s21_NAN));
  ck_assert_ldouble_nan(tan(s21_NAN));
}
END_TEST

START_TEST(tan_11) {
  ck_assert_double_eq_tol(s21_tan(0.0), tanl(0.0), s21_EPS);
}
END_TEST

START_TEST(tan_12) {
  ck_assert_double_eq_tol(s21_tan(s21_PI / 6), tan(s21_PI / 6), s21_EPS);
}
END_TEST

START_TEST(tan_13) {
  ck_assert_double_eq_tol(s21_tan(s21_PI / 4), tan(s21_PI / 4), s21_EPS);
}
END_TEST

START_TEST(tan_14) {
  ck_assert_double_eq_tol(s21_tan(-2 * s21_PI), tanl(-2 * s21_PI), s21_EPS);
}
END_TEST

START_TEST(tan_15) {
  ck_assert_double_eq_tol(s21_tan(s21_PI), tan(s21_PI), s21_EPS);
}
END_TEST

START_TEST(tan_16) {
  ck_assert_double_eq_tol(s21_tan(s21_PI / 3), tan(s21_PI / 3), s21_EPS);
}
END_TEST

START_TEST(tan_17) {
  ck_assert_double_eq_tol(s21_tan(3 * s21_PI / 3), tan(3 * s21_PI / 3),
                          s21_EPS);
}
END_TEST

START_TEST(tan_18) {
  ck_assert_double_eq_tol(s21_tan(174.532925199433), tan(174.532925199433),
                          s21_EPS);
}
END_TEST

START_TEST(tan_19) {
  ck_assert_double_eq_tol(s21_tan(-174.532925199433), tan(-174.532925199433),
                          s21_EPS);
}
END_TEST

START_TEST(tan_20) {
  ck_assert_double_eq_tol(s21_tan(s21_PI_2), tanl(s21_PI_2), s21_EPS);
}
END_TEST

START_TEST(tan_Last) {
  ck_assert_double_eq_tol(s21_tan(-s21_PI_2), tanl(-s21_PI_2), s21_EPS);
}
END_TEST

START_TEST(atan_1) { ck_assert_float_eq(s21_atan(-17.03), atan(-17.03)); }
END_TEST

START_TEST(atan_2) {
  double num = -0.99;
  long double orig_res = s21_atan(num), our_res = atan(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= s21_EPS)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(atan_3) { ck_assert_float_eq(-9999999999, -9999999999); }
END_TEST

START_TEST(atan_4) {
  ck_assert_ldouble_eq(s21_atan(s21_NEG_INF), atan(s21_NEG_INF));
}
END_TEST

START_TEST(atan_5) {
  double num = s21_NAN;
  long double orig_res = s21_atan(num), our_res = atan(num);
  int suc = 0;
  if (s21_is_nan(orig_res) && s21_is_nan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(atan_6) {
  ck_assert_ldouble_eq_tol(s21_atan(s21_POS_INF), (M_PI / 2.0), s21_EPS);
  ck_assert_ldouble_eq_tol(atan(s21_POS_INF), (M_PI / 2.0), s21_EPS);
}
END_TEST

START_TEST(atan_7) {
  ck_assert_ldouble_nan(s21_atan(s21_NAN));
  ck_assert_ldouble_nan(atan(s21_NAN));
}
END_TEST

START_TEST(atan_8) {
  ck_assert_ldouble_eq_tol(s21_atan(1.0), atan(1.0), s21_EPS);
}
END_TEST

START_TEST(atan_9) {
  ck_assert_ldouble_eq_tol(s21_atan(0.0), atan(0.0), s21_EPS);
}
END_TEST

START_TEST(atan_10) {
  ck_assert_ldouble_eq_tol(s21_atan(-1), atan(-1), s21_EPS);
}
END_TEST

START_TEST(atan_11) {
  ck_assert_ldouble_eq_tol(s21_atan(-sqrt(3) / 2), atan(-sqrt(3) / 2), s21_EPS);
}
END_TEST

START_TEST(atan_12) {
  ck_assert_ldouble_eq_tol(s21_atan(-sqrt(2) / 2), atan(-sqrt(2) / 2), s21_EPS);
}
END_TEST

START_TEST(atan_13) {
  ck_assert_ldouble_eq_tol(s21_atan(-1 / 2), atan(-1 / 2), s21_EPS);
}
END_TEST

START_TEST(atan_14) {
  ck_assert_ldouble_eq_tol(s21_atan(1 / 2), atan(1 / 2), s21_EPS);
}
END_TEST

START_TEST(atan_15) {
  ck_assert_ldouble_eq_tol(s21_atan(-0.2 / 2), atan(-0.2 / 2), s21_EPS);
}
END_TEST

START_TEST(atan_16) {
  ck_assert_ldouble_eq_tol(s21_atan(sqrt(3) / 2), atan(sqrt(3) / 2), s21_EPS);
}
END_TEST

START_TEST(atan_17) { ck_assert_ldouble_eq_tol(s21_atan(1), atan(1), s21_EPS); }
END_TEST

START_TEST(atan_18) {
  ck_assert_ldouble_eq_tol(s21_atan(1.23456e-7), atan(1.23456e-7), s21_EPS);
}
END_TEST

START_TEST(atan_19) {
  ck_assert_ldouble_eq_tol(s21_atan(2.1234567), atan(2.1234567), s21_EPS);
}
END_TEST

START_TEST(atan_20) {
  ck_assert_ldouble_eq_tol(s21_atan(2.1234567e-7), atan(2.1234567e-7), s21_EPS);
}
END_TEST

START_TEST(atan_21) {
  ck_assert_ldouble_eq_tol(s21_atan(2.1234567e-16), atan(2.1234567e-16),
                           s21_EPS);
}
END_TEST

START_TEST(atan_22) { ck_assert_float_nan(s21_atan(s21_NAN)); }
END_TEST

START_TEST(atan_23) {
  ck_assert_ldouble_eq_tol(s21_atan(s21_PI_2), atan(s21_PI_2), s21_EPS);
}
END_TEST

START_TEST(atan_24) {
  ck_assert_ldouble_eq_tol(s21_atan(-s21_PI_2), atan(-s21_PI_2), s21_EPS);
}
END_TEST

START_TEST(atan_25) {
  ck_assert_ldouble_eq_tol(s21_atan((s21_NEG_INF)), ((M_PI) / -2.0), s21_EPS);
  ck_assert_ldouble_eq_tol(atan(s21_NEG_INF), ((M_PI) / -2.0), s21_EPS);
}
END_TEST

START_TEST(atan_26) {
  ck_assert_ldouble_eq(s21_atan(s21_POS_INF), atan(s21_POS_INF));
}
END_TEST

START_TEST(atan_27) {
  ck_assert_ldouble_eq_tol(s21_atan(-1.0), atan(-1.0), s21_EPS);
}
END_TEST

START_TEST(atan_28) {
  ck_assert_ldouble_eq_tol(s21_atan(-1.1), atan(-1.1), s21_EPS);
}
END_TEST

START_TEST(atan_29) {
  ck_assert_ldouble_eq_tol(s21_atan(1.1), atan(1.1), s21_EPS);
}
END_TEST

START_TEST(atan_Last) {
  ck_assert_ldouble_eq_tol(s21_atan(-0.0), atan(-0.0), s21_EPS);
}
END_TEST

START_TEST(acos_1) {
  double num = 0.55;
  long double orig_res = acos(num), our_res = s21_acos(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= s21_EPS)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(acos_2) {
  double num = -0.99;
  long double orig_res = acos(num), our_res = s21_acos(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= s21_EPS)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(acos_3) {
  ck_assert_ldouble_eq_tol(s21_acos(-1.0), acos(-1.0), s21_EPS);
}
END_TEST

START_TEST(acos_4) {
  ck_assert_int_eq(s21_is_nan(asin(s21_POS_INF)),
                   s21_is_nan(s21_asin(s21_POS_INF)));
}
END_TEST

START_TEST(acos_5) {
  ck_assert_int_eq(s21_is_nan(asin(s21_NEG_INF)),
                   s21_is_nan(s21_asin(s21_NEG_INF)));
}
END_TEST

START_TEST(acos_6) {
  ck_assert_int_eq(s21_is_nan(asin(s21_NAN)), s21_is_nan(s21_asin(s21_NAN)));
}
END_TEST

START_TEST(acos_7) {
  ck_assert_ldouble_eq_tol(s21_acos(-0.0), acos(-0.0), s21_EPS);
}
END_TEST

START_TEST(acos_8) {
  ck_assert_ldouble_nan(s21_acos(s21_NAN));
  ck_assert_ldouble_nan(acos(s21_NAN));
}
END_TEST

START_TEST(acos_9) {
  ck_assert_ldouble_eq_tol(s21_acos(1.0), acos(1.0), s21_EPS);
}
END_TEST

START_TEST(acos_10) {
  ck_assert_ldouble_eq_tol(s21_acos(0.0), acos(0.0), s21_EPS);
}
END_TEST

START_TEST(acos_11) {
  ck_assert_ldouble_eq_tol(s21_acos(-1), acos(-1), s21_EPS);
}
END_TEST

START_TEST(acos_12) { ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), s21_EPS); }
END_TEST

START_TEST(acos_13) {
  ck_assert_ldouble_eq_tol(s21_acos(-sqrt(3) / 2), acos(-sqrt(3) / 2), s21_EPS);
}
END_TEST

START_TEST(acos_14) {
  ck_assert_ldouble_eq_tol(s21_acos(-sqrt(2) / 2), acos(-sqrt(2) / 2), s21_EPS);
}
END_TEST

START_TEST(acos_15) {
  ck_assert_ldouble_eq_tol(s21_acos(-1 / 2), acos(-1 / 2), s21_EPS);
}
END_TEST

START_TEST(acos_16) {
  ck_assert_ldouble_eq_tol(s21_acos(1 / 2), acos(1 / 2), s21_EPS);
}
END_TEST

START_TEST(acos_17) {
  ck_assert_ldouble_eq_tol(s21_acos(-3 / 3), acos(-3 / 3), s21_EPS);
}
END_TEST

START_TEST(acos_18) {
  ck_assert_ldouble_eq_tol(s21_acos(sqrt(2) / 2), acos(sqrt(2) / 2), s21_EPS);
}
END_TEST

START_TEST(acos_Last) {
  ck_assert_ldouble_eq_tol(s21_acos(sqrt(3) / 2), acos(sqrt(3) / 2), s21_EPS);
}
END_TEST

START_TEST(asin_1) {
  double num = 0.55;
  long double orig_res = asin(num), our_res = s21_asin(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= s21_EPS)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(asin_2) {
  double num = -0.99;
  long double orig_res = asin(num), our_res = s21_asin(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= s21_EPS)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(asin_3) {
  ck_assert_ldouble_eq_tol(s21_asin(-1.0), asin(-1.0), s21_EPS);
}
END_TEST

START_TEST(asin_4) {
  ck_assert_int_eq(s21_is_nan(asin(s21_POS_INF)),
                   s21_is_nan(s21_asin(s21_POS_INF)));
}
END_TEST

START_TEST(asin_5) {
  ck_assert_int_eq(s21_is_nan(asin(s21_NEG_INF)),
                   s21_is_nan(s21_asin(s21_NEG_INF)));
}
END_TEST

START_TEST(asin_6) {
  ck_assert_int_eq(s21_is_nan(asin(s21_NAN)), s21_is_nan(s21_asin(s21_NAN)));
}
END_TEST

START_TEST(asin_7) {
  ck_assert_ldouble_nan(s21_asin(s21_POS_INF));
  ck_assert_ldouble_nan(asin(s21_POS_INF));
}
END_TEST

START_TEST(asin_8) {
  ck_assert_ldouble_nan(s21_asin(s21_NEG_INF));
  ck_assert_ldouble_nan(asin(s21_NEG_INF));
}
END_TEST

START_TEST(asin_9) {
  ck_assert_ldouble_nan(s21_asin(s21_NAN));
  ck_assert_ldouble_nan(asin(s21_NAN));
}
END_TEST

START_TEST(asin_10) {
  ck_assert_ldouble_eq_tol(s21_asin(1.0), asin(1.0), s21_EPS);
}
END_TEST

START_TEST(asin_11) {
  ck_assert_ldouble_eq_tol(s21_asin(0.0), asin(0.0), s21_EPS);
}
END_TEST

START_TEST(asin_12) {
  ck_assert_ldouble_eq_tol(s21_asin(0.0), asin(0.0), s21_EPS);
}
END_TEST

START_TEST(asin_13) {
  ck_assert_ldouble_eq_tol(s21_asin(-1), asin(-1), s21_EPS);
}
END_TEST

START_TEST(asin_14) { ck_assert_ldouble_eq_tol(s21_asin(1), asin(1), s21_EPS); }
END_TEST

START_TEST(asin_15) {
  ck_assert_ldouble_eq_tol(s21_asin(-sqrt(3) / 2), asin(-sqrt(3) / 2), s21_EPS);
}
END_TEST

START_TEST(asin_16) {
  ck_assert_ldouble_eq_tol(s21_asin(-sqrt(2) / 2), asin(-sqrt(2) / 2), s21_EPS);
}
END_TEST

START_TEST(asin_17) {
  ck_assert_ldouble_eq_tol(s21_asin(-1 / 2), asin(-1 / 2), s21_EPS);
}
END_TEST

START_TEST(asin_18) {
  ck_assert_ldouble_eq_tol(s21_asin(1 / 2), asin(1 / 2), s21_EPS);
}
END_TEST

START_TEST(asin_19) {
  ck_assert_ldouble_eq_tol(s21_asin(sqrt(2) / 2), asin(sqrt(2) / 2), s21_EPS);
}
END_TEST

START_TEST(asin_20) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.0), asin(-0.0), s21_EPS);
}
END_TEST

START_TEST(asin_Last) {
  ck_assert_ldouble_eq_tol(s21_asin(sqrt(3) / 2), asin(sqrt(3) / 2), s21_EPS);
}
END_TEST

Suite *suite_creator(void) {
  Suite *suite;
  suite = suite_create("Math Tests");

  TCase *tc_abs = tcase_create("Abs");
  tcase_add_test(tc_abs, Abs1);
  tcase_add_test(tc_abs, Abs2);
  tcase_add_test(tc_abs, Abs3);
  tcase_add_test(tc_abs, Abs4);
  tcase_add_test(tc_abs, Abs5);
  tcase_add_test(tc_abs, Abs6);
  tcase_add_test(tc_abs, Abs7);
  tcase_add_test(tc_abs, AbsHexdecimalNegative);
  tcase_add_test(tc_abs, Abs9);
  tcase_add_test(tc_abs, Abs10);
  tcase_add_test(tc_abs, Abs11);
  tcase_add_test(tc_abs, Abs12);
  tcase_add_test(tc_abs, AbsHexadecimal);
  suite_add_tcase(suite, tc_abs);

  TCase *tc_fabs = tcase_create("Fabs");
  tcase_add_test(tc_fabs, normal);
  tcase_add_test(tc_fabs, nan_num);
  tcase_add_test(tc_fabs, POS_INF);
  tcase_add_test(tc_fabs, NEG_INF);
  tcase_add_test(tc_fabs, large);
  tcase_add_test(tc_fabs, not_a_num);
  suite_add_tcase(suite, tc_fabs);

  TCase *tc_ceil = tcase_create("Ceil");
  tcase_add_test(tc_ceil, Ceil_1);
  tcase_add_test(tc_ceil, Ceil_2);
  tcase_add_test(tc_ceil, Ceil_3);
  tcase_add_test(tc_ceil, Ceil_4);
  tcase_add_test(tc_ceil, Ceil_5);
  tcase_add_test(tc_ceil, test_inf);
  tcase_add_test(tc_ceil, test_nan);
  tcase_add_test(tc_ceil, test_y_zero);
  tcase_add_test(tc_ceil, test_x_inf_y_zero);
  suite_add_tcase(suite, tc_ceil);

  TCase *tc_floor = tcase_create("Floor");
  tcase_add_test(tc_floor, test_inf);
  tcase_add_test(tc_floor, test_pos_inf);
  tcase_add_test(tc_floor, test_neg_inf);
  tcase_add_test(tc_floor, floor_nan);
  tcase_add_test(tc_floor, floor_zero);
  tcase_add_test(tc_floor, test_inf_y_zero);
  tcase_add_test(tc_floor, floor_small);
  tcase_add_test(tc_floor, floor_half);
  tcase_add_test(tc_floor, floor_big);
  tcase_add_test(tc_floor, floor_half_negative);
  tcase_add_test(tc_floor, floor_negative);
  tcase_add_test(tc_floor, floor_PI);
  suite_add_tcase(suite, tc_floor);

  TCase *tc_log = tcase_create("Log");
  tcase_add_test(tc_log, log_1);
  tcase_add_test(tc_log, log_2);
  tcase_add_test(tc_log, log_3);
  tcase_add_test(tc_log, log_4);
  tcase_add_test(tc_log, log_5);
  tcase_add_test(tc_log, log_6);
  tcase_add_test(tc_log, log_7);
  tcase_add_test(tc_log, log_8);
  tcase_add_test(tc_log, log_9);
  tcase_add_test(tc_log, log_10);
  tcase_add_test(tc_log, log_11);
  tcase_add_test(tc_log, log_12);
  tcase_add_test(tc_log, log_13);
  tcase_add_test(tc_log, log_14);
  tcase_add_test(tc_log, log_15);
  tcase_add_test(tc_log, log_16);
  tcase_add_test(tc_log, log_17);
  tcase_add_test(tc_log, log_18);
  tcase_add_test(tc_log, log_19);
  tcase_add_test(tc_log, log_20);
  tcase_add_test(tc_log, log_21);
  tcase_add_test(tc_log, log_22);
  tcase_add_test(tc_log, log_23);
  tcase_add_test(tc_log, log_24);
  tcase_add_test(tc_log, log_25);
  tcase_add_test(tc_log, log_26);
  tcase_add_test(tc_log, log_27);
  tcase_add_test(tc_log, log_28);
  tcase_add_test(tc_log, log_29);
  tcase_add_test(tc_log, log_30);
  tcase_add_test(tc_log, log_31);
  tcase_add_test(tc_log, log_32);
  tcase_add_test(tc_log, log_33);
  tcase_add_test(tc_log, log_34);
  tcase_add_test(tc_log, is_zero);
  suite_add_tcase(suite, tc_log);

  TCase *tc_exp = tcase_create("Exp");
  tcase_add_test(tc_exp, exp_0);
  tcase_add_test(tc_exp, exp_1);
  tcase_add_test(tc_exp, exp_2);
  tcase_add_test(tc_exp, exp_3);
  tcase_add_test(tc_exp, exp_4);
  tcase_add_test(tc_exp, exp_5);
  tcase_add_test(tc_exp, exp_6);
  tcase_add_test(tc_exp, exp_7);
  tcase_add_test(tc_exp, exp_8);
  tcase_add_test(tc_exp, exp_9);
  tcase_add_test(tc_exp, exp_10);
  tcase_add_test(tc_exp, exp_11);
  tcase_add_test(tc_exp, exp_12);
  tcase_add_test(tc_exp, exp_13);
  tcase_add_test(tc_exp, exp_14);
  tcase_add_test(tc_exp, exp_15);
  tcase_add_test(tc_exp, exp_16);
  tcase_add_test(tc_exp, exp_17);
  tcase_add_test(tc_exp, exp_18);
  tcase_add_test(tc_exp, exp_19);
  tcase_add_test(tc_exp, exp_20);
  tcase_add_test(tc_exp, exp_22);
  tcase_add_test(tc_exp, exp_23);
  tcase_add_test(tc_exp, exp_24);
  tcase_add_test(tc_exp, exp_25);
  tcase_add_test(tc_exp, exp_26);
  tcase_add_test(tc_exp, exp_27);
  tcase_add_test(tc_exp, exp_28);
  tcase_add_test(tc_exp, exp_29);
  tcase_add_test(tc_exp, exp_30);
  tcase_add_test(tc_exp, exp_31);
  tcase_add_test(tc_exp, exp_Last);
  suite_add_tcase(suite, tc_exp);

  TCase *sqrt = tcase_create("Sqrt");
  tcase_add_test(sqrt, sqrt_1);
  tcase_add_test(sqrt, sqrt_2);
  tcase_add_test(sqrt, sqrt_4);
  tcase_add_test(sqrt, sqrt_5);
  tcase_add_test(sqrt, sqrt_6);
  tcase_add_test(sqrt, sqrt_7);
  tcase_add_test(sqrt, sqrt_8);
  tcase_add_test(sqrt, sqrt_9);
  tcase_add_test(sqrt, sqrt_10);
  tcase_add_test(sqrt, sqrt_12);
  tcase_add_test(sqrt, sqrt_13);
  tcase_add_test(sqrt, sqrt_14);
  tcase_add_test(sqrt, sqrt_15);
  tcase_add_test(sqrt, sqrt_16);
  tcase_add_test(sqrt, sqrt_17);
  tcase_add_test(sqrt, sqrt_Last);
  suite_add_tcase(suite, sqrt);

  TCase *tc_fmod = tcase_create("Fmod");
  tcase_add_test(tc_fmod, fmod_1);
  tcase_add_test(tc_fmod, fmod_2);
  tcase_add_test(tc_fmod, fmod_3);
  tcase_add_test(tc_fmod, fmod_4);
  tcase_add_test(tc_fmod, fmod_5);
  tcase_add_test(tc_fmod, fmod_6);
  tcase_add_test(tc_fmod, fmod_7);
  tcase_add_test(tc_fmod, fmod_8);
  tcase_add_test(tc_fmod, fmod_9);
  tcase_add_test(tc_fmod, fmod_10);
  tcase_add_test(tc_fmod, fmod_11);
  tcase_add_test(tc_fmod, fmod_12);
  tcase_add_test(tc_fmod, fmod_13);
  tcase_add_test(tc_fmod, fmod_14);
  tcase_add_test(tc_fmod, fmod_15);
  tcase_add_test(tc_fmod, fmod_16);
  tcase_add_test(tc_fmod, fmod_17);
  tcase_add_test(tc_fmod, fmod_18);
  tcase_add_test(tc_fmod, fmod_19);
  tcase_add_test(tc_fmod, fmod_20);
  tcase_add_test(tc_fmod, fmod_21);
  tcase_add_test(tc_fmod, fmod_22);
  tcase_add_test(tc_fmod, fmod_23);
  tcase_add_test(tc_fmod, fmod_25);
  tcase_add_test(tc_fmod, fmod_Last);
  suite_add_tcase(suite, tc_fmod);

  TCase *tc_pow = tcase_create("Pow");
  tcase_add_test(tc_pow, pow_1);
  tcase_add_test(tc_pow, pow_2);
  tcase_add_test(tc_pow, pow_3);
  tcase_add_test(tc_pow, pow_4);
  tcase_add_test(tc_pow, pow_5);
  tcase_add_test(tc_pow, pow_6);
  tcase_add_test(tc_pow, pow_7);
  tcase_add_test(tc_pow, pow_8);
  tcase_add_test(tc_pow, pow_9);
  tcase_add_test(tc_pow, pow_10);
  tcase_add_test(tc_pow, pow_12);
  tcase_add_test(tc_pow, pow_13);
  tcase_add_test(tc_pow, pow_14);
  tcase_add_test(tc_pow, pow_15);
  tcase_add_test(tc_pow, pow_16);
  tcase_add_test(tc_pow, pow_17);
  tcase_add_test(tc_pow, pow_18);
  tcase_add_test(tc_pow, pow_19);
  tcase_add_test(tc_pow, pow_20);
  tcase_add_test(tc_pow, pow_21);
  tcase_add_test(tc_pow, pow_22);
  tcase_add_test(tc_pow, pow_23);
  tcase_add_test(tc_pow, pow_24);
  tcase_add_test(tc_pow, pow_25);
  tcase_add_test(tc_pow, pow_26);
  tcase_add_test(tc_pow, pow_27);
  tcase_add_test(tc_pow, pow_28);
  tcase_add_test(tc_pow, pow_29);
  tcase_add_test(tc_pow, pow_30);
  tcase_add_test(tc_pow, pow_31);
  tcase_add_test(tc_pow, pow_32);
  tcase_add_test(tc_pow, pow_33);
  tcase_add_test(tc_pow, pow_34);
  tcase_add_test(tc_pow, pow_35);
  tcase_add_test(tc_pow, pow_36);
  tcase_add_test(tc_pow, pow_37);
  tcase_add_test(tc_pow, pow_38);
  tcase_add_test(tc_pow, pow_39);
  tcase_add_test(tc_pow, pow_40);
  tcase_add_test(tc_pow, pow_41);
  tcase_add_test(tc_pow, pow_42);
  tcase_add_test(tc_pow, pow_43);
  tcase_add_test(tc_pow, pow_44);
  tcase_add_test(tc_pow, pow_45);
  tcase_add_test(tc_pow, pow_46);
  tcase_add_test(tc_pow, pow_47);
  tcase_add_test(tc_pow, pow_48);
  tcase_add_test(tc_pow, pow_49);
  tcase_add_test(tc_pow, pow_50);
  tcase_add_test(tc_pow, pow_51);
  tcase_add_test(tc_pow, pow_52);
  tcase_add_test(tc_pow, pow_53);
  tcase_add_test(tc_pow, pow_54);
  tcase_add_test(tc_pow, pow_55);
  tcase_add_test(tc_pow, pow_56);
  tcase_add_test(tc_pow, pow_57);
  tcase_add_test(tc_pow, pow_58);
  tcase_add_test(tc_pow, pow_59);
  tcase_add_test(tc_pow, pow_60);
  tcase_add_test(tc_pow, pow_61);
  tcase_add_test(tc_pow, pow_62);
  tcase_add_test(tc_pow, pow_63);
  tcase_add_test(tc_pow, pow_64);
  tcase_add_test(tc_pow, pow_65);
  tcase_add_test(tc_pow, pow_66);
  tcase_add_test(tc_pow, pow_67);
  tcase_add_test(tc_pow, pow_68);
  tcase_add_test(tc_pow, pow_69);
  tcase_add_test(tc_pow, pow_70);
  tcase_add_test(tc_pow, pow_Last);
  suite_add_tcase(suite, tc_pow);

  TCase *tc_sin = tcase_create("Sine");
  tcase_add_test(tc_sin, sin_1);
  tcase_add_test(tc_sin, sin_2);
  tcase_add_test(tc_sin, sin_3);
  tcase_add_test(tc_sin, sin_4);
  tcase_add_test(tc_sin, sin_5);
  tcase_add_test(tc_sin, sin_6);
  tcase_add_test(tc_sin, sin_7);
  tcase_add_test(tc_sin, sin_8);
  tcase_add_test(tc_sin, sin_9);
  tcase_add_test(tc_sin, sin_10);
  tcase_add_test(tc_sin, sin_11);
  tcase_add_test(tc_sin, sin_12);
  tcase_add_test(tc_sin, sin_13);
  tcase_add_test(tc_sin, sin_14);
  tcase_add_test(tc_sin, sin_15);
  tcase_add_test(tc_sin, sin_16);
  tcase_add_test(tc_sin, sin_17);
  tcase_add_test(tc_sin, sin_18);
  tcase_add_test(tc_sin, sin_19);
  tcase_add_test(tc_sin, sin_20);
  tcase_add_test(tc_sin, sin_21);
  tcase_add_test(tc_sin, sin_22);
  tcase_add_test(tc_sin, sin_23);
  tcase_add_test(tc_sin, sin_24);
  tcase_add_test(tc_sin, sin_25);
  tcase_add_test(tc_sin, sin_Last);
  suite_add_tcase(suite, tc_sin);

  TCase *tc_cos = tcase_create("Cos");
  tcase_add_test(tc_cos, cos_1);
  tcase_add_test(tc_cos, cos_2);
  tcase_add_test(tc_cos, cos_3);
  tcase_add_test(tc_cos, cos_4);
  tcase_add_test(tc_cos, cos_5);
  tcase_add_test(tc_cos, cos_6);
  tcase_add_test(tc_cos, cos_7);
  tcase_add_test(tc_cos, cos_8);
  tcase_add_test(tc_cos, cos_9);
  tcase_add_test(tc_cos, cos_10);
  tcase_add_test(tc_cos, cos_11);
  tcase_add_test(tc_cos, cos_12);
  tcase_add_test(tc_cos, cos_13);
  tcase_add_test(tc_cos, cos_14);
  tcase_add_test(tc_cos, cos_15);
  tcase_add_test(tc_cos, cos_16);
  tcase_add_test(tc_cos, cos_17);
  tcase_add_test(tc_cos, cos_18);
  tcase_add_test(tc_cos, cos_19);
  tcase_add_test(tc_cos, cos_20);
  tcase_add_test(tc_cos, cos_Last);
  suite_add_tcase(suite, tc_cos);

  TCase *tc_tan = tcase_create("Tan");
  tcase_add_test(tc_tan, tan_1);
  tcase_add_test(tc_tan, tan_2);
  tcase_add_test(tc_tan, tan_3);
  tcase_add_test(tc_tan, tan_4);
  tcase_add_test(tc_tan, tan_5);
  tcase_add_test(tc_tan, tan_6);
  tcase_add_test(tc_tan, tan_7);
  tcase_add_test(tc_tan, tan_8);
  tcase_add_test(tc_tan, tan_9);
  tcase_add_test(tc_tan, tan_10);
  tcase_add_test(tc_tan, tan_11);
  tcase_add_test(tc_tan, tan_12);
  tcase_add_test(tc_tan, tan_13);
  tcase_add_test(tc_tan, tan_14);
  tcase_add_test(tc_tan, tan_15);
  tcase_add_test(tc_tan, tan_16);
  tcase_add_test(tc_tan, tan_17);
  tcase_add_test(tc_tan, tan_18);
  tcase_add_test(tc_tan, tan_19);
  tcase_add_test(tc_tan, tan_20);
  tcase_add_test(tc_tan, tan_Last);
  suite_add_tcase(suite, tc_tan);

  TCase *tc_atan = tcase_create("Atan");
  tcase_add_test(tc_atan, atan_1);
  tcase_add_test(tc_atan, atan_2);
  tcase_add_test(tc_atan, atan_3);
  tcase_add_test(tc_atan, atan_4);
  tcase_add_test(tc_atan, atan_5);
  tcase_add_test(tc_atan, atan_6);
  tcase_add_test(tc_atan, atan_7);
  tcase_add_test(tc_atan, atan_8);
  tcase_add_test(tc_atan, atan_9);
  tcase_add_test(tc_atan, atan_10);
  tcase_add_test(tc_atan, atan_11);
  tcase_add_test(tc_atan, atan_12);
  tcase_add_test(tc_atan, atan_13);
  tcase_add_test(tc_atan, atan_14);
  tcase_add_test(tc_atan, atan_15);
  tcase_add_test(tc_atan, atan_16);
  tcase_add_test(tc_atan, atan_17);
  tcase_add_test(tc_atan, atan_18);
  tcase_add_test(tc_atan, atan_19);
  tcase_add_test(tc_atan, atan_20);
  tcase_add_test(tc_atan, atan_21);
  tcase_add_test(tc_atan, atan_22);
  tcase_add_test(tc_atan, atan_23);
  tcase_add_test(tc_atan, atan_24);
  tcase_add_test(tc_atan, atan_25);
  tcase_add_test(tc_atan, atan_26);
  tcase_add_test(tc_atan, atan_27);
  tcase_add_test(tc_atan, atan_28);
  tcase_add_test(tc_atan, atan_29);
  tcase_add_test(tc_atan, atan_Last);
  suite_add_tcase(suite, tc_atan);

  TCase *tc_acos = tcase_create("Acos");
  tcase_add_test(tc_acos, acos_1);
  tcase_add_test(tc_acos, acos_2);
  tcase_add_test(tc_acos, acos_3);
  tcase_add_test(tc_acos, acos_4);
  tcase_add_test(tc_acos, acos_5);
  tcase_add_test(tc_acos, acos_6);
  tcase_add_test(tc_acos, acos_7);
  tcase_add_test(tc_acos, acos_8);
  tcase_add_test(tc_acos, acos_9);
  tcase_add_test(tc_acos, acos_10);
  tcase_add_test(tc_acos, acos_11);
  tcase_add_test(tc_acos, acos_12);
  tcase_add_test(tc_acos, acos_13);
  tcase_add_test(tc_acos, acos_14);
  tcase_add_test(tc_acos, acos_15);
  tcase_add_test(tc_acos, acos_16);
  tcase_add_test(tc_acos, acos_17);
  tcase_add_test(tc_acos, acos_18);
  tcase_add_test(tc_acos, acos_Last);
  suite_add_tcase(suite, tc_acos);

  TCase *tc_asin = tcase_create("Asin");
  tcase_add_test(tc_asin, asin_1);
  tcase_add_test(tc_asin, asin_2);
  tcase_add_test(tc_asin, asin_3);
  tcase_add_test(tc_asin, asin_4);
  tcase_add_test(tc_asin, asin_5);
  tcase_add_test(tc_asin, asin_6);
  tcase_add_test(tc_asin, asin_7);
  tcase_add_test(tc_asin, asin_8);
  tcase_add_test(tc_asin, asin_9);
  tcase_add_test(tc_asin, asin_10);
  tcase_add_test(tc_asin, asin_11);
  tcase_add_test(tc_asin, asin_12);
  tcase_add_test(tc_asin, asin_13);
  tcase_add_test(tc_asin, asin_14);
  tcase_add_test(tc_asin, asin_15);
  tcase_add_test(tc_asin, asin_16);
  tcase_add_test(tc_asin, asin_17);
  tcase_add_test(tc_asin, asin_18);
  tcase_add_test(tc_asin, asin_19);
  tcase_add_test(tc_asin, asin_20);
  tcase_add_test(tc_asin, asin_Last);
  suite_add_tcase(suite, tc_asin);

  return suite;
}

int main(void) {
  Suite *suite;
  SRunner *srunner;

  suite = suite_creator();
  srunner = srunner_create(suite);

  srunner_run_all(srunner, CK_VERBOSE);  // shows successful tests in the Term
  int failed_count = srunner_ntests_failed(srunner);  //  CK_NORMAL does not
  srunner_free(srunner);

  return failed_count == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
