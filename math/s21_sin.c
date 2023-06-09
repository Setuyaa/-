#include "s21_math.h"

long double s21_sin(double x) {
  long double s = 0.0;
  if (x == S21_INF || x != x) {
    s = S21_NAN;
  } else {
    if (s21_fabs(x) > 2.0 * S21_PI) {
      if (x > 0.0) x = s21_fmod(s21_fabs(x), 2.0 * S21_PI);
      if (x < 0.0) x = -1 * s21_fmod(s21_fabs(x), 2.0 * S21_PI);
    }
    int n = 0;
    long double i = x;
    s = i;
    if (x == 0.0) {
      s = 0.0;
    } else {
      while (s21_fabs(i) > S21_EPS) {
        i *= -1 * (x * x) / (4 * n * n + 10 * n + 6);
        n++;
        s += i;
      }
    }
  }
  return s;
}