#include "s21_math.h"

long double s21_sqrt(double x) {  // вычисляет квадратный корень
  long double q = 1;
  long double q2 = 2;
  if ((x != x) || (x < 0.0))
    q = S21_NAN;
  else if (x == S21_INF)
    q = S21_INF;
  else {
    while (s21_fabs(q2 - q) > S21_EPS) {
      q2 = q;
      q = (q + x / q) / 2;
    }
  }
  return q;
}