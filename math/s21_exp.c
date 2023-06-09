#include "s21_math.h"

long double s21_exp(double x) {
  long double add = 1, ans = 1, i = 1;
  if (x <= -25) {
    ans = 0.00000;
  } else {
    while (s21_fabs((double)add) > S21_EPS_FOR) {  //////////
      add *= (x / i);
      i++;
      ans += add;
      if (ans > MAX_N) {
        ans = S21_INF;
        break;
      }
    }
  }
  return ans;
}