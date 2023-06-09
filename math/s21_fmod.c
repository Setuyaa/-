#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double result = 0;
  long long int check = x / y;
  if (y == 0.0 || x == S21_INF || x == -S21_INF) {
    result = S21_NAN;
  } else if (y == S21_INF || y == -S21_INF) {
    result = x;
  } else {
    result = x - (check * y);
  }
  return result;
}