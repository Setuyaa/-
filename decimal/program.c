#include "decimal.h"

int main() {
  char str1[28] = "-52345678.854884574574";
  char str2[28] = "52345678.854884574574";
  s21_decimal s21_dec1 = parser(str1);
  s21_decimal s21_dec2 = parser(str2);
  printf("%d\n", s21_dec1.ex);
  printf("%u\n", s21_dec2.block[3]);
  return 0;
}