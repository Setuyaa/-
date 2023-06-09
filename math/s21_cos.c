#include "s21_math.h"

long double s21_cos(double x) {  // вычисляет косинус
  long double s = s21_sin(x);
  if (s21_fabs(x) > 2.0 * S21_PI) {
    if (x > 0.0) x -= s21_fmod(s21_fabs(x), 2.0 * S21_PI);
    if (x < 0.0) x = -1 * s21_fmod(s21_fabs(x), 2.0 * S21_PI);
  }
  long double c = 1 - s21_pow(s, 2);
  c = s21_sqrt(c);
  if (s21_fabs(x) > S21_PI / 2) c *= -1;
  return c;
}