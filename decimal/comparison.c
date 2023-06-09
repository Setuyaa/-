 #include "decimal.h"

int main() {
char str2[28] = "0.6876898776";
    char str1[28] = "0.13669";
  s21_decimal dec1 = parser(str1);
  s21_decimal dec2 = parser(str2);
int check = s21_is_less(dec1, dec2);
printf("%d", check);
  return 0;
}