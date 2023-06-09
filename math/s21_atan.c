#include "s21_math.h"

long double s21_atan(double x) {
  long double add, result = 0;
  if (x == S21_INF)
    result = S21_PI / 2;
  else if (x == -S21_INF)
    result = -S21_PI / 2;
  else if (x <= 1 && x >= -1) {
    add = x;
    for (int i = 0; i < 1000000; i++) {
      result += add / (1 + 2 * i);
      add *= -(x * x);
    }
  } else {
    add = 1 / x;
    for (int i = 0; i < 1000000; i++) {
      result += add / (1 + 2 * i);
      add = -add / x / x;
    }
    result = S21_PI * s21_fabs(x) / (2 * x) - result;
  }
  return result;
}