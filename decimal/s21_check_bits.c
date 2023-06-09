#include "decimal.h"

int check_bits(s21_decimal dec1, s21_decimal dec2) {
    int check = 1;
    int t1 = 0;
        int t2 = 0;
        int k = 95;
        while (t1 == t2 && k >= 0) {
          t1  = s21_get_bit(dec1, k);
          t2  = s21_get_bit(dec2, k);
            k--;
        }
        if (t1 > t2 || t1 == t2) check = 0;
        return check;
}