#include "decimal.h"

int s21_get_bit(s21_decimal decl, int index) { //newtonbe
  int num_int = index / 32;
  int num_bit = index % 32;
  return (decl.block[num_int] & (1u << num_bit)) >> num_bit;
}

void s21_set_bit(s21_decimal* decl, int index, int bit) { //newtonbe
  int num_int = index / 32;
  int num_bit = index % 32;
  if (bit == 1) {
    decl->block[num_int] |= (1u << num_bit);
  } else {
    decl->block[num_int] &= (~((1u) << num_bit));
  }
  return;
}
