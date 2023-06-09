#include "decimal.h"

void ef(char *str, s21_decimal *s21_dec) {
  int i = 0;
  int t = 0;
  if (str[0] == '-') {
    s21_dec -> znak = 1; // change to set bit
    i++;
  }
s21_dec -> ex = -1;
  for (; i < strlen(str); i++) {
    if (str[i] == '.') {
      s21_dec -> ex++;
      continue;
    }
    if (s21_dec -> ex > -1)
      s21_dec -> ex++;
    s21_dec -> str2[t] = str[i];
    t++;
  }
   if ( s21_dec -> ex == -1)
       s21_dec -> ex = 0;
}

void reverse(char* str)
{
    char temp;
    char* end = str + strlen(str);
    while( str < --end ) {
        temp = *str;
        *str = *end;
        *end = temp;
        ++str;
    }
}
void mantisa(char * str, s21_decimal *s21_dec) {
  strcpy(str, "");
  double temp = 0;
    reverse(s21_dec -> str2);
    int length = strlen(s21_dec -> str2);
  strncat(str, s21_dec -> str2, 10);
    reverse(str);
  temp = atof(str);
    reverse(str);
  if (temp > INT_UMAX) {
    strcpy(str, "");
    strncat(str, s21_dec -> str2, 9);
      reverse(str);
    s21_dec-> block[0] = atol(str);
    double temp1 = 0;
    strcpy(str, "");
    strncat(str, &s21_dec -> str2[9], 10);//
      reverse(str);
    temp1 = atof(str);
      reverse(str);
    if (temp1 > INT_UMAX) {
      strcpy(str, "");
      strncat(str, &s21_dec -> str2[9], 9);//
        reverse(str);
      s21_dec -> block[1] = atol(str);
      strcpy(str, "");
      strncat(str, &s21_dec -> str2[19], 10); //
      double temp2 = 0;
        reverse(str);
      temp2 = atof(str);
        reverse(str);
      if (temp2 > INT_UMAX) {
        strcpy(str, "");
        strncat(str, &s21_dec -> str2[18], 9); //
          reverse(str);
         s21_dec -> block[2] = atol(str);
      } else {
        strcpy(str, "");
        strncat(str, &s21_dec -> str2[18], 10); //
          reverse(str);
         s21_dec -> block[2] = atol(str);
      }
    } else {
      strcpy(str, "");
      strncat(str, &s21_dec -> str2[9], 10); //
        reverse(str);
      s21_dec -> block[1] = atol(str);
      strcpy(str, "");
      strncat(str, &s21_dec -> str2[19], 10); //
      double temp2 = 0;
        reverse(str);
      temp2 = atof(str);
        reverse(str);
      if (temp2 > INT_UMAX) {
        strcpy(str, "");
        strncat(str, &s21_dec -> str2[19], 9); //
          reverse(str);
         s21_dec -> block[2] = atol(str);
      } else {
        strcpy(str, "");
        strncat(str, &s21_dec -> str2[19], 10); //
          reverse(str);
         s21_dec -> block[2] = atol(str);
      }
    }
  } else {
    strcpy(str, "");
    strncat(str, s21_dec -> str2, 10);
      reverse(str);
    s21_dec -> block[0] = atol(str);
    double temp1 = 0;
    strcpy(str, "");
    strncat(str, &s21_dec -> str2[10], 10); //
      reverse(str);
    temp1 = atof(str);
      reverse(str);
    if (temp1 > INT_UMAX) {
      strcpy(str, "");
      strncat(str, &s21_dec -> str2[10], 9); //
        reverse(str);
      s21_dec -> block[1] = atol(str);
      strcpy(str, "");
      strncat(str, &s21_dec -> str2[19], 10); //
      double temp2 = 0;
        reverse(str);
      temp2 = atof(str);
        reverse(str);
      if (temp2 > INT_UMAX) {
        strcpy(str, "");
        strncat(str, &s21_dec -> str2[19], 9); //
          reverse(str);
        s21_dec -> block[2] = atol(str);
      } else {
        strcpy(str, "");
        strncat(str, &s21_dec -> str2[19], 10); //
          reverse(str);
        s21_dec -> block[2] = atol(str);
      }
    } else {
      strcpy(str, "");
      strncat(str, &s21_dec -> str2[10], 10); //
        reverse(str);
      s21_dec -> block[1] = atol(str);
      strcpy(str, "");
      strncat(str, &s21_dec -> str2[20], 10); //
      double temp2 = 0;
        reverse(str);
      temp2 = atof(str);
        reverse(str);
      if (temp2 > INT_UMAX) {
        strcpy(str, "");
        strncat(str, &s21_dec -> str2[20], 9); //
          reverse(str);
        s21_dec -> block[2] = atol(str);
      } else {
        strcpy(str, "");
        strncat(str, &s21_dec ->str2[20], 10); //
          reverse(str);
        s21_dec -> block[2] = atol(str);
      }
    }
      
 }
    reverse(s21_dec -> str2);
}

void sp_block(s21_decimal *s21_dec) {
    s21_dec-> block[3] = 0;
    //s21_dec -> ex = s21_dec -> ;
    s21_dec -> block[3] += s21_dec -> ex << 16;
    // set bit znak
    s21_dec -> znak = s21_dec -> znak << 31;
    s21_dec -> block[3] += s21_dec -> znak;
   // printf("%u\n", s21_dec -> znak);
}

s21_decimal parser(char str[28]) {
  s21_decimal dec;
  strcpy(dec.str2, "");
  dec.znak = 0;
  ef(str, &dec);
  mantisa(str, &dec);
  sp_block(&dec);
  return dec;
}
