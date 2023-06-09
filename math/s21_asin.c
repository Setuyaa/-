#include "s21_math.h"

long double s21_asin(double x) {
  double result = 0;
  if (s21_fabs(x) == 1)
    result = x * S21_PI / 2;
  else if (s21_fabs(x) < 1) {
    result = s21_atan(x / s21_sqrt(1 - x * x));
  } else {
    result = S21_NAN;
  }
  return result;
}