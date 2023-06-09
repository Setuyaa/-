#include "decimal.h"

int s21_is_less(s21_decimal dec1, s21_decimal dec2) { //Меньше
  int check = 1;
  int znak1 = s21_get_bit(dec1, 127);
  int znak2 = s21_get_bit(dec2, 127);
  int checkNull1 = s21_is_zero(dec1);
  int checkNull2 = s21_is_zero(dec2);
  if (checkNull1 && checkNull2) check = 0;
  else if (checkNull1 && !znak2) check = 1;
  else if (checkNull1 && znak2) check =0;
  else if (checkNull2 && znak1) check =1;
   else if (checkNull2 && !znak1) check =0;
  else if (!znak1 && znak2) {
    check = 0;
  } else if (!znak2 && znak1) {
    check = 1;
  } else {
    int ex1 = s21_get_scale(dec1);
    int ex2 = s21_get_scale(dec2);
    s21_decimal temp;
    for (int i = 0; i < 127; i++)
      s21_set_bit(&temp, i, 0);
    if (ex1 < ex2) {
      char str[30] = "";
      int i = 0;
      for (; i < ex2-ex1; i++)
      {
          str[i] = '0';
      }
      str[i+1]='\n';
      char str2[100] = "";
      char str1[70] = "";
      char str0[40] = "";
      sprintf(str2, "%u", dec1.block[2]);
      sprintf(str1, "%u", dec1.block[1]);
      sprintf(str0, "%u", dec1.block[0]);
      strcat(str0, str);
      strcat(str2, str1);
      strcat(str2, str0);
      temp = parser(str2);
      check = check_bits(temp, dec2);
    }
    else if (ex1 > ex2) {
      char str[30] = "";
      int i = 0;
      for (; i < ex1-ex2; i++)
      {
          str[i] = '0';
      }
      str[i+1]='\n';
      char str2[100] = "";
      char str1[70] = "";
      char str0[40] = "";
      sprintf(str2, "%u", dec2.block[2]);
      sprintf(str1, "%u", dec2.block[1]);
      sprintf(str0, "%u", dec2.block[0]);
      strcat(str0, str);
      strcat(str2, str1);
      strcat(str2, str0);
      temp = parser(str2);
      check = check_bits(dec1, temp);
    } else {
      check = check_bits(dec1, dec2);
    }
  }
  return check;
}











