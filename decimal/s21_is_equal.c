#include "decimal.h"

int s21_is_equal(s21_decimal dec1, s21_decimal dec2) { //Равно
  int check = 1;
  for (int i = 0; i < 128; i++) {
    int a = s21_get_bit(dec1, i);
    int b = s21_get_bit(dec2, i);
    if (a != b) {
      check = 0;
    }
  }
  return check;
}