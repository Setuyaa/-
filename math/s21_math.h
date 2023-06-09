#ifndef S21_MATH_H
#define S21_MATH_H

#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define S21_PI 3.14159265358979323846
#define S21_NAN (0.0 / 0.0)
#define MAX_N 1.7e+308
#define S21_INF (1.0 / 0.0)
#define S21_EPS_FOR 0.000000000000001
#define S21_EXP 2.71828182845904523536028747
#define S21_EPS 1e-7
#define LONG_LONG_INT_MIN -9223372036854775800
#define LONG_LONG_INT_MAX 9223372036854775800

long double s21_fmod(double x, double y);
long double s21_exp(double x);
long double s21_log(double x);
long double s21_tan(double x);
long double s21_acos(double x);
int s21_abs(int x);
long double s21_fabs(double x);
long double s21_pow(double base, double exp);
long double s21_cos(double x);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);
long double s21_ceil(double x);
long double s21_floor(double x);
long double s21_asin(double x);
long double s21_atan(double x);

#endif