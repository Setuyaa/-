#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define INT_MAX 2147483648
#define INT_UMAX 4294967295

typedef struct {
  unsigned int block[4]; // decimal
  int ex;
  char str2[28];
  int znak;
} s21_decimal;

s21_decimal parser(char str[28]);
int s21_get_bit(s21_decimal decl, int index);
void s21_set_bit(s21_decimal* decl, int index, int bit);
int s21_is_less(s21_decimal dec1, s21_decimal dec2);//Меньше
int s21_is_less_or_equal(s21_decimal dec1, s21_decimal dec2);//Меньше или равно
int s21_is_greater(s21_decimal dec1, s21_decimal dec2); //Больше
int s21_is_greater_or_equal(s21_decimal dec1, s21_decimal dec2); //Больше или равно
int s21_is_equal(s21_decimal dec1, s21_decimal dec2);//Равно
int s21_is_not_equal(s21_decimal, s21_decimal);//Не равно
int check_bits(s21_decimal dec1, s21_decimal dec2);
int s21_is_zero(s21_decimal value);
int s21_get_scale(s21_decimal decl);
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

int s21_checkbit(int value, int position);
int s21_setbit_1(int value, int position);
int s21_unsetbit_0(int value, int position);
int s21_switchbit(int value, int position);
int s21_get_sign_decimal(s21_decimal *dst);
void s21_init_decimal(s21_decimal *dst);

// print decimal
void s21_print_decimal(s21_decimal *dst);
