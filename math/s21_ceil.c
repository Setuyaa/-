#include "s21_math.h"

long double s21_ceil(double x) {
  long double result = 0;
  if (s21_fabs(x) == S21_INF || x == S21_NAN) {
    result = x;
  } else {
    result = (long long int)x;
    if (x > 0 && x != result) result += 1;
  }
  return result;
}