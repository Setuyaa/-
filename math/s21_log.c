#include "s21_math.h"

long double s21_log(double x) {
  long double result = 0;
  long int ex_pow = 0;
  long double compare = 0;
  if (x < 0)
    result = S21_NAN;
  else if (x == 0)
    result = -S21_INF;
  else if (x == S21_INF)
    result = S21_INF;
  else {
    for (; x >= S21_EXP; x /= S21_EXP, ex_pow++) continue;

    for (int i = 0; i < 1000; i++) {
      compare = result;
      result = compare + 2 * (x - s21_exp(compare)) / (x + s21_exp(compare));
    }
  }
  return result + ex_pow;
}