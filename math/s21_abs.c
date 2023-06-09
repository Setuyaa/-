#include "s21_math.h"

int s21_abs(int x) {  // вычисляет абсолютное значение целого числа +
  if (x < 0) x *= -1;
  return x;
}