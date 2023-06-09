#include "s21_math.h"

long double s21_pow(double x, double y) {
  long double result = 0;
  int flag = 0;
  if ((x == 0) && (y != y)) {
    result = S21_NAN;
    flag = 1;
  }
  if ((x == 0) && (y < 0)) {
    result = S21_INF;
    flag = 1;
  }
  if ((x == S21_INF) && (y < 0)) {
    result = 0;
    flag = 1;
  }
  if ((x == -1) && (y == -S21_INF)) {
    result = 1;
    flag = 1;
  }
  if (y == 0) {
    result = 1;
    flag = 1;
  }
  if (flag == 0) {
    if (x == 0) {
      result = 0;
    } else {
      if (x < 0) {
        result = s21_exp(y * s21_log(-x));  //
        if (s21_fmod(y, 2) != 0) {
          result = result * -1;
        }
      } else {
        result = s21_exp(y * s21_log(x));  //
      }
    }
  }
  return result;
}