#include "decimal.h"

int s21_is_less_or_equal(s21_decimal dec1,
                         s21_decimal dec2) { //Меньше или равно
                                             //   int check = 0;
  return (s21_is_less(dec1, dec2)) || (s21_is_equal(dec1, dec2));
}