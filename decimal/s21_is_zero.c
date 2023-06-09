 #include "decimal.h"

 int s21_is_zero(s21_decimal value) {
  int is_zero = 0;

  if (!value.block[0] && !value.block[1] && !value.block[2])
      is_zero = 1;

  return is_zero;
}