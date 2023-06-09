#include <check.h>
#include <math.h>

#include "s21_math.h"

START_TEST(test_fmod_1) {
  ck_assert_double_nan(fmod(1, 0));
  ck_assert_double_nan(s21_fmod(1, 0));
  ck_assert_double_eq(fmod(0, -1), s21_fmod(0, -1));
  ck_assert_double_eq(fmod(0, 1), s21_fmod(0, 1));
  ck_assert_double_nan(fmod(S21_INF, -1));
  ck_assert_double_nan(s21_fmod(S21_INF, -1));
  ck_assert_double_eq(fmod(-1, S21_INF), s21_fmod(-1, S21_INF));
  ck_assert_double_eq(fmod(0, S21_INF), s21_fmod(0, S21_INF));
  ck_assert_double_nan(s21_fmod(0, S21_NAN));
  ck_assert_double_nan(fmod(0, NAN));
  ck_assert_double_nan(s21_fmod(S21_NAN, S21_NAN));
  ck_assert_double_nan(fmod(NAN, NAN));
  ck_assert_double_nan(s21_fmod(S21_NAN, S21_INF));
  ck_assert_double_nan(s21_fmod(S21_INF, S21_NAN));
  ck_assert_double_nan(s21_fmod(S21_NAN, -S21_INF));
  ck_assert_double_nan(s21_fmod(-S21_INF, S21_NAN));
  ck_assert_double_nan(fmod(NAN, INFINITY));
  ck_assert_double_nan(fmod(INFINITY, NAN));
  ck_assert_double_nan(fmod(NAN, -INFINITY));
  ck_assert_double_nan(fmod(-INFINITY, NAN));
}
END_TEST

START_TEST(test_fmod_2) {
  for (int i = -2300; i < 2000; i += 134) {
    for (int j = -12; j < 12; j += 1.38) {
      ck_assert_double_eq(fmod(j, i), s21_fmod(j, i));
    }
  }
}
END_TEST
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
START_TEST(acos_test_1) {
  double x = 1;
  ck_assert_ldouble_eq_tol(s21_acos(x), acos(x), S21_EPS_FOR);
}
END_TEST

START_TEST(acos_test_2) {
  double x = -1;
  ck_assert_ldouble_eq_tol(s21_acos(x), acos(x), S21_EPS_FOR);
}
END_TEST

START_TEST(acos_test_3) {
  double x = 0;
  ck_assert_ldouble_eq_tol(s21_acos(x), acos(x), S21_EPS_FOR);
}
END_TEST

START_TEST(acos_test_4) {
  double x = 999999999999;
  ck_assert_ldouble_nan(s21_acos(x));
  ck_assert_ldouble_nan(acos(x));
}
END_TEST

START_TEST(acos_test_5) {
  double x = -999999999999;
  ck_assert_ldouble_nan(s21_acos(x));
  ck_assert_ldouble_nan(acos(x));
}
END_TEST

START_TEST(acos_test_6) {
  double x = DBL_MAX;
  ck_assert_ldouble_nan(s21_acos(x));
  ck_assert_ldouble_nan(acos(x));
}
END_TEST

START_TEST(acos_test_7) {
  double x = -DBL_MAX;
  ck_assert_ldouble_nan(s21_acos(x));
  ck_assert_ldouble_nan(acos(x));
}
END_TEST

START_TEST(acos_test_8) {
  double x = 1e-9;
  ck_assert_ldouble_eq_tol(s21_acos(x), acos(x), S21_EPS_FOR);
}
END_TEST

START_TEST(acos_test_9) {
  double x = -1e-9;
  ck_assert_ldouble_eq_tol(s21_acos(x), acos(x), S21_EPS_FOR);
}
END_TEST

START_TEST(acos_test_10) {
  ck_assert_ldouble_nan(s21_acos(NAN));
  ck_assert_ldouble_nan(acos(NAN));
}
END_TEST

START_TEST(acos_test_11) {
  ck_assert_ldouble_nan(s21_acos(INFINITY));
  ck_assert_ldouble_nan(acos(INFINITY));
}
END_TEST

START_TEST(acos_test_12) {
  ck_assert_ldouble_nan(s21_acos(-INFINITY));
  ck_assert_ldouble_nan(acos(-INFINITY));
}
END_TEST

START_TEST(acos_test_13) {
  double x = 0.5;
  ck_assert_ldouble_eq_tol(s21_acos(x), acos(x), S21_EPS_FOR);
}
END_TEST

START_TEST(acos_test_14) {
  double x = -0.5;
  ck_assert_ldouble_eq_tol(s21_acos(x), acos(x), S21_EPS_FOR);
}
END_TEST
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
START_TEST(exp_test_1) {
  double x = 1;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), S21_EPS_FOR);
}
END_TEST

START_TEST(exp_test_2) {
  double x = -1;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), S21_EPS_FOR);
}
END_TEST

START_TEST(exp_test_3) {
  double x = 0;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), S21_EPS_FOR);
}
END_TEST

START_TEST(exp_test_4) {
  double x = 999999999999;
  ck_assert_ldouble_infinite(s21_exp(x));
  ck_assert_ldouble_infinite(exp(x));
}
END_TEST

START_TEST(exp_test_5) {
  double x = -999999999999;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), S21_EPS_FOR);
}
END_TEST

START_TEST(exp_test_6) {
  double x = DBL_MAX;
  ck_assert_ldouble_infinite(s21_exp(x));
  ck_assert_ldouble_infinite(exp(x));
}
END_TEST

START_TEST(exp_test_7) {
  double x = -DBL_MAX;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), S21_EPS_FOR);
}
END_TEST

START_TEST(exp_test_8) {
  double x = 1e-9;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), S21_EPS_FOR);
}
END_TEST

START_TEST(exp_test_9) {
  double x = -1e-9;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), S21_EPS_FOR);
}
END_TEST

START_TEST(exp_test_10) {
  ck_assert_ldouble_nan(s21_exp(NAN));
  ck_assert_ldouble_nan(exp(NAN));
}
END_TEST

START_TEST(exp_test_11) {
  ck_assert_ldouble_infinite(s21_exp(INFINITY));
  ck_assert_ldouble_infinite(exp(INFINITY));
}
END_TEST

START_TEST(exp_test_12) {
  ck_assert_ldouble_eq_tol(s21_exp(-INFINITY), exp(-INFINITY), S21_EPS);
}
END_TEST

START_TEST(exp_test_13) {
  double x = 3.156;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), S21_EPS);
}
END_TEST

START_TEST(exp_test_14) {
  double x = -3.156;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), S21_EPS);
}
END_TEST
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
START_TEST(log_test_1) {
  double x = 1;
  ck_assert_ldouble_eq_tol(log(x), s21_log(x), S21_EPS_FOR);
}
END_TEST

START_TEST(log_test_2) {
  double x = -1;
  ck_assert_ldouble_nan(s21_log(x));
  ck_assert_ldouble_nan(log(x));
  ;
}
END_TEST

START_TEST(log_test_3) {
  double x = 0;
  ck_assert_ldouble_infinite(s21_log(x));
  ck_assert_ldouble_infinite(log(x));
}
END_TEST

START_TEST(log_test_4) {
  double x = 999999999999;
  ck_assert_ldouble_eq_tol(log(x), s21_log(x), S21_EPS);
}
END_TEST

START_TEST(log_test_5) {
  double x = -999999999999;
  ck_assert_ldouble_nan(s21_log(x));
  ck_assert_ldouble_nan(log(x));
  ;
}
END_TEST

START_TEST(log_test_6) {
  double x = DBL_MAX;
  ck_assert_ldouble_eq_tol(log(x), s21_log(x), S21_EPS);
}
END_TEST

START_TEST(log_test_7) {
  double x = -DBL_MAX;
  ck_assert_ldouble_nan(s21_log(x));
  ck_assert_ldouble_nan(log(x));
  ;
}
END_TEST

START_TEST(log_test_8) {
  double x = 1e-7;
  ck_assert_ldouble_eq_tol(log(x), s21_log(x), S21_EPS);
}
END_TEST

START_TEST(log_test_9) {
  double x = -1e-7;
  ck_assert_ldouble_nan(s21_log(x));
  ck_assert_ldouble_nan(log(x));
  ;
}
END_TEST

START_TEST(log_test_10) {
  ck_assert_ldouble_nan(s21_log(NAN));
  ck_assert_ldouble_nan(log(NAN));
}
END_TEST

START_TEST(log_test_11) {
  ck_assert_ldouble_infinite(s21_log(INFINITY));
  ck_assert_ldouble_infinite(log(INFINITY));
}
END_TEST

START_TEST(log_test_12) {
  ck_assert_ldouble_nan(s21_log(-INFINITY));
  ck_assert_ldouble_nan(log(-INFINITY));
}
END_TEST

START_TEST(log_test_13) {
  double x = 3.156;
  ck_assert_ldouble_eq_tol(log(x), s21_log(x), S21_EPS);
}
END_TEST

START_TEST(log_test_14) {
  double x = -3.156;
  ck_assert_ldouble_nan(s21_log(x));
  ck_assert_ldouble_nan(log(x));
}
END_TEST
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
START_TEST(testing_tan) {
  ck_assert_ldouble_eq_tol(s21_tan(0), tan(0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_tan(1), tan(1), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_tan(3.45678901234567890),
                           tan(3.45678901234567890), S21_EPS);
  ck_assert_ldouble_nan(s21_tan(S21_NAN));
  ck_assert_ldouble_nan(s21_tan(S21_INF));
  ck_assert_ldouble_nan(s21_tan(-S21_INF));
}
END_TEST
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
START_TEST(testing_sqrt) {
  ck_assert_ldouble_eq_tol(s21_sqrt(0), sqrt(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(1), sqrt(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(3.45678901234567890),
                           sqrt(3.45678901234567890), 1e-6);
  ck_assert_ldouble_nan(s21_sqrt(S21_NAN));
  ck_assert_ldouble_nan(s21_sqrt(-0.1));
  ck_assert_ldouble_eq(s21_sqrt(S21_INF), sqrt(S21_INF));
}
END_TEST
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
START_TEST(testing_sin) {
  ck_assert_ldouble_eq_tol(s21_sin(0), sin(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(1), sin(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(1000), sin(1000), 1e-6);
  ck_assert_ldouble_nan(s21_sin(S21_NAN));
  ck_assert_ldouble_nan(s21_sin(S21_INF));
  ck_assert_ldouble_nan(s21_sin(-S21_INF));
}
END_TEST
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
START_TEST(testing_abs) {
  for (int x = -781254872; x < 781254873; x = x + 5999)
    ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
START_TEST(testing_cos) {
  ck_assert_ldouble_eq_tol(s21_cos(0), cos(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(1), cos(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(3.45678901234567890),
                           cos(3.45678901234567890), 1e-6);
  ck_assert_ldouble_nan(s21_cos(S21_NAN));
  ck_assert_ldouble_nan(s21_cos(S21_INF));
  ck_assert_ldouble_nan(s21_cos(-S21_INF));
}
END_TEST
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
START_TEST(testing_fabs) {
  for (double x = -781254872.925698256; x < 781254873; x = x + 578246.721846412)
    ck_assert_ldouble_eq(s21_fabs(x), fabs(x));
  ck_assert_ldouble_nan(s21_fabs(S21_NAN));
  ck_assert_ldouble_eq(s21_fabs(S21_INF), fabs(S21_INF));
  ck_assert_ldouble_eq(s21_fabs(-S21_INF), fabs(-S21_INF));
  ck_assert_ldouble_eq(s21_fabs(S21_EPS), fabs(S21_EPS));
  ck_assert_ldouble_eq(s21_fabs(-S21_EPS), fabs(-S21_EPS));
}
END_TEST
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
START_TEST(testing_pow) {
  ck_assert_ldouble_eq_tol(s21_pow(0.12, 2.2), pow(0.12, 2.2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(15, 2.5), pow(15, 2.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(8239751.123456789012345, 0.0001),
                           pow(8239751.123456789012345, 0.0001), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0, 0.0001), pow(0, 0.0001), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-2, 2), pow(-2, 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-2, 3), pow(-2, 3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-2, -2), pow(-2, -2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-2, -3), pow(-2, -3), 1e-6);
  ck_assert_ldouble_nan(s21_pow(S21_NAN, S21_NAN));
  ck_assert_ldouble_eq(s21_pow(123.123, S21_INF), pow(123.123, S21_INF));
  ck_assert_ldouble_eq(s21_pow(S21_INF, -1), pow(S21_INF, -1));
  ck_assert_ldouble_eq(s21_pow(123.123, -S21_INF), pow(123.123, -S21_INF));
  ck_assert_ldouble_eq(s21_pow(-123.123, -S21_INF), pow(-123.123, -S21_INF));
  ck_assert_ldouble_eq(s21_pow(-1, -S21_INF), pow(-1, -S21_INF));
  ck_assert_ldouble_eq_tol(s21_pow(S21_EPS, S21_EPS), pow(S21_EPS, S21_EPS),
                           1e-6);
  ck_assert_ldouble_eq(s21_pow(0, 0), pow(0, 0));
  ck_assert_ldouble_eq(s21_pow(0, 1), pow(0, 1));
  ck_assert_ldouble_eq(s21_pow(0, -1), pow(0, -1));

  ck_assert_ldouble_nan(s21_pow(0, S21_NAN));
}
END_TEST
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
START_TEST(s21_ceil_test1) {
  double x = -2.9;
  ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
}
END_TEST

START_TEST(s21_ceil_test2) {
  double x = 2.9;
  ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
}
END_TEST

START_TEST(s21_ceil_test3) {
  double x = 0;
  ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
}
END_TEST

START_TEST(s21_ceil_test4) {
  double x = S21_INF;
  ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
}
END_TEST

START_TEST(s21_ceil_test5) {
  double x = 1234567890123456;
  ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
}
END_TEST

START_TEST(s21_ceil_test6) {
  double x = -1234567890123456;
  ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
}
END_TEST

START_TEST(s21_ceil_test7) {
  double x = S21_EPS;
  ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
}
END_TEST

START_TEST(s21_ceil_test8) {
  double x = S21_EXP;
  ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
}
END_TEST

START_TEST(s21_ceil_test9) {
  double x = S21_PI;
  ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
}
END_TEST
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
START_TEST(asin_test_1) {
  double x = 1;
  ck_assert_ldouble_eq_tol(s21_asin(x), asin(x), S21_EPS);
}
END_TEST

START_TEST(asin_test_2) {
  double x = -1;
  ck_assert_ldouble_eq_tol(s21_asin(x), asin(x), S21_EPS);
}
END_TEST

START_TEST(asin_test_3) {
  double x = 0;
  ck_assert_ldouble_eq_tol(s21_asin(x), asin(x), S21_EPS);
}
END_TEST

START_TEST(asin_test_4) {
  double x = 999999999999;
  ck_assert_ldouble_nan(s21_asin(x));
  ck_assert_ldouble_nan(asin(x));
}
END_TEST

START_TEST(asin_test_5) {
  double x = -999999999999;
  ck_assert_ldouble_nan(s21_asin(x));
  ck_assert_ldouble_nan(asin(x));
}
END_TEST

START_TEST(asin_test_6) {
  double x = DBL_MAX;
  ck_assert_ldouble_nan(s21_asin(x));
  ck_assert_ldouble_nan(asin(x));
}
END_TEST

START_TEST(asin_test_7) {
  double x = -DBL_MAX;
  ck_assert_ldouble_nan(s21_asin(x));
  ck_assert_ldouble_nan(asin(x));
}
END_TEST

START_TEST(asin_test_8) {
  double x = 1e-9;
  ck_assert_ldouble_eq_tol(s21_asin(x), asin(x), S21_EPS);
}
END_TEST

START_TEST(asin_test_9) {
  double x = -1e-9;
  ck_assert_ldouble_eq_tol(s21_asin(x), asin(x), S21_EPS);
}
END_TEST

START_TEST(asin_test_10) {
  ck_assert_ldouble_nan(s21_asin(NAN));
  ck_assert_ldouble_nan(asin(NAN));
}
END_TEST

START_TEST(asin_test_11) {
  ck_assert_ldouble_nan(s21_asin(INFINITY));
  ck_assert_ldouble_nan(asin(INFINITY));
}
END_TEST

START_TEST(asin_test_12) {
  ck_assert_ldouble_nan(s21_asin(-INFINITY));
  ck_assert_ldouble_nan(asin(-INFINITY));
}
END_TEST

START_TEST(asin_test_13) {
  double x = 0.5;
  ck_assert_ldouble_eq_tol(s21_asin(x), asin(x), S21_EPS);
}
END_TEST

START_TEST(asin_test_14) {
  double x = -0.5;
  ck_assert_ldouble_eq_tol(s21_asin(x), asin(x), S21_EPS);
}
END_TEST
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
START_TEST(s21_floor_test1) {
  double x = -2.9;
  ck_assert_ldouble_eq(s21_floor(x), floor(x));
}
END_TEST

START_TEST(s21_floor_test2) {
  double x = 2.9;
  ck_assert_ldouble_eq(s21_floor(x), floor(x));
}
END_TEST

START_TEST(s21_floor_test3) {
  double x = 0;
  ck_assert_ldouble_eq(s21_floor(x), floor(x));
}
END_TEST

START_TEST(s21_floor_test4) {
  double x = S21_EPS;
  ck_assert_ldouble_eq(s21_floor(x), floor(x));
}
END_TEST

START_TEST(s21_floor_test5) {
  double x = S21_EXP;
  ck_assert_ldouble_eq(s21_floor(x), floor(x));
}
END_TEST

START_TEST(s21_floor_test6) {
  double x = 1234567890123456;
  ck_assert_ldouble_eq(s21_floor(x), floor(x));
}
END_TEST

START_TEST(s21_floor_test7) {
  double x = -1234567890123456;
  ck_assert_ldouble_eq(s21_floor(x), floor(x));
}
END_TEST

START_TEST(s21_floor_test8) {
  double x = S21_INF;
  ck_assert_ldouble_eq(s21_floor(x), floor(x));
}
END_TEST

START_TEST(s21_floor_test9) {
  double x = S21_PI;
  ck_assert_ldouble_eq(s21_floor(x), floor(x));
}
END_TEST
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
START_TEST(testing_atan) {
  ck_assert_ldouble_eq_tol(s21_atan(0), atan(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(1), atan(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-1), atan(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(3.45678901234567890),
                           atan(3.45678901234567890), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(0.564), atan(0.564), 1e-6);
  ck_assert_ldouble_nan(s21_atan(S21_NAN));
  ck_assert_ldouble_eq_tol(s21_atan(S21_INF), atan(S21_INF), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-S21_INF), atan(-S21_INF), 1e-6);
}
END_TEST
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

Suite *s21_string_suite(void) {
  Suite *suite;

  suite = suite_create("s21_math");
  TCase *tcase_core = tcase_create("Core");

  tcase_add_test(tcase_core, test_fmod_1);
  tcase_add_test(tcase_core, test_fmod_2);
  /////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////
  tcase_add_test(tcase_core, acos_test_1);
  tcase_add_test(tcase_core, acos_test_2);
  tcase_add_test(tcase_core, acos_test_3);
  tcase_add_test(tcase_core, acos_test_4);
  tcase_add_test(tcase_core, acos_test_5);
  tcase_add_test(tcase_core, acos_test_6);
  tcase_add_test(tcase_core, acos_test_7);
  tcase_add_test(tcase_core, acos_test_8);
  tcase_add_test(tcase_core, acos_test_9);
  tcase_add_test(tcase_core, acos_test_10);
  tcase_add_test(tcase_core, acos_test_11);
  tcase_add_test(tcase_core, acos_test_12);
  tcase_add_test(tcase_core, acos_test_13);
  tcase_add_test(tcase_core, acos_test_14);
  /////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////
  tcase_add_test(tcase_core, exp_test_1);
  tcase_add_test(tcase_core, exp_test_2);
  tcase_add_test(tcase_core, exp_test_3);
  tcase_add_test(tcase_core, exp_test_4);
  tcase_add_test(tcase_core, exp_test_5);
  tcase_add_test(tcase_core, exp_test_6);
  tcase_add_test(tcase_core, exp_test_7);
  tcase_add_test(tcase_core, exp_test_8);
  tcase_add_test(tcase_core, exp_test_9);
  tcase_add_test(tcase_core, exp_test_10);
  tcase_add_test(tcase_core, exp_test_11);
  tcase_add_test(tcase_core, exp_test_12);
  tcase_add_test(tcase_core, exp_test_13);
  tcase_add_test(tcase_core, exp_test_14);
  /////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////
  tcase_add_test(tcase_core, log_test_1);
  tcase_add_test(tcase_core, log_test_2);
  tcase_add_test(tcase_core, log_test_3);
  tcase_add_test(tcase_core, log_test_4);
  tcase_add_test(tcase_core, log_test_5);
  tcase_add_test(tcase_core, log_test_6);
  tcase_add_test(tcase_core, log_test_7);
  tcase_add_test(tcase_core, log_test_8);
  tcase_add_test(tcase_core, log_test_9);
  tcase_add_test(tcase_core, log_test_10);
  tcase_add_test(tcase_core, log_test_11);
  tcase_add_test(tcase_core, log_test_12);
  tcase_add_test(tcase_core, log_test_13);
  tcase_add_test(tcase_core, log_test_14);
  /////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////
  tcase_add_test(tcase_core, testing_tan);

  tcase_add_test(tcase_core, testing_sqrt);

  tcase_add_test(tcase_core, testing_sin);

  tcase_add_test(tcase_core, testing_abs);

  tcase_add_test(tcase_core, testing_cos);

  tcase_add_test(tcase_core, testing_fabs);

  tcase_add_test(tcase_core, testing_pow);

  tcase_add_test(tcase_core, testing_atan);
  /////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////
  tcase_add_test(tcase_core, s21_ceil_test1);
  tcase_add_test(tcase_core, s21_ceil_test2);
  tcase_add_test(tcase_core, s21_ceil_test3);
  tcase_add_test(tcase_core, s21_ceil_test4);
  tcase_add_test(tcase_core, s21_ceil_test5);
  tcase_add_test(tcase_core, s21_ceil_test6);
  tcase_add_test(tcase_core, s21_ceil_test7);
  tcase_add_test(tcase_core, s21_ceil_test8);
  tcase_add_test(tcase_core, s21_ceil_test9);
  /////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////
  tcase_add_test(tcase_core, asin_test_1);
  tcase_add_test(tcase_core, asin_test_2);
  tcase_add_test(tcase_core, asin_test_3);
  tcase_add_test(tcase_core, asin_test_4);
  tcase_add_test(tcase_core, asin_test_5);
  tcase_add_test(tcase_core, asin_test_6);
  tcase_add_test(tcase_core, asin_test_7);
  tcase_add_test(tcase_core, asin_test_8);
  tcase_add_test(tcase_core, asin_test_9);
  tcase_add_test(tcase_core, asin_test_10);
  tcase_add_test(tcase_core, asin_test_11);
  tcase_add_test(tcase_core, asin_test_12);
  tcase_add_test(tcase_core, asin_test_13);
  tcase_add_test(tcase_core, asin_test_14);
  /////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////
  tcase_add_test(tcase_core, s21_floor_test1);
  tcase_add_test(tcase_core, s21_floor_test2);
  tcase_add_test(tcase_core, s21_floor_test3);
  tcase_add_test(tcase_core, s21_floor_test4);
  tcase_add_test(tcase_core, s21_floor_test5);
  tcase_add_test(tcase_core, s21_floor_test6);
  tcase_add_test(tcase_core, s21_floor_test7);
  tcase_add_test(tcase_core, s21_floor_test8);
  tcase_add_test(tcase_core, s21_floor_test9);
  /////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////

  suite_add_tcase(suite, tcase_core);

  return suite;
}

int main() {
  Suite *suite = s21_string_suite();
  SRunner *suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner, CK_VERBOSE);
  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  return (failed_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}