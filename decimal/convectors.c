
#include "decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
    int result_status = 0;
    if (dst) {
        result_status = 0;
        if (src < 0) {
            dst->block[3] = 2147483648;
            dst->block[0] = src * -1;
        } else {
            dst->block[0] = src;
        }
    } else {
        result_status = 1;
    }
    return result_status;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
    int result_status = 0;
    int sign = 0;
    int count = 0;
    if (dst) {
        if (s21_get_sign_decimal(&src)) {
            sign = 1;
        }
        for (int i = 3; i > 0; i--) {
            for (int j = 31; j >= 0; j--) {
                if (s21_checkbit(src.block[i], j)) {
                    if (s21_checkbit(src.block[3], 31)) count--;
                    count++;  
                }
            }
        }
        if (count != 0) {
            result_status = 1; 
        } else {
            if (s21_checkbit(src.block[0], 31) == 0) {
                result_status = 0;
                *dst = src.block[0];
                if (sign) *dst = -(*dst);
            } else if (s21_checkbit(src.block[0], 31) == 1) {
                for (int i = 30; i >= 0; i--) {
                    if (s21_checkbit(src.block[0], i) == 1) {
                        result_status = 1;
                        count++;
                    }
                }
                if (count == 0) *dst = -INT_MAX;
            } else {
                result_status = 1;
            }
        }
    } else {
        result_status = 1;
    }
    return result_status;
}

