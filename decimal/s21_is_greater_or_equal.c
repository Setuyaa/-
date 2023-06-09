#include "decimal.h"

int s21_is_greater(s21_decimal dec1, s21_decimal dec2) { //Больше
  return !s21_is_less(dec1, dec2);
}