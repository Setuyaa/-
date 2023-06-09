#include "decimal.h"
int s21_checkbit(int value, int position) {
    return ((value & (1 << position)) != 0);
}

int s21_setbit_1(int value, int position) {
    return (value | (1 << position));
}

int s21_unsetbit_0(int value, int position) {
    return (value & ~(1 << position));
}

int s21_switchbit(int value, int position) {
    return (value ^ (1 << position));
}

void s21_print_decimal(s21_decimal *dst) {
    for (int i = 3; i >= 0; i--) {
        for (int j = 31; j >= 0; j--) {
            printf("%i ", s21_checkbit(dst->block[i], j));
        }
        printf("\n");
    }
    printf("\n");
}

int s21_get_sign_decimal(s21_decimal *dst) {
    int result = 0;
    if (s21_checkbit(dst->block[3], 31)) {
        result = 1;
    }
    return result;
}

void s21_init_decimal(s21_decimal *dst) {
    for (int i = 0; i <= 3; i++) {
        dst->block[i] = 0;
    }
}
