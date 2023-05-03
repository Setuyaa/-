#include "memory.h"
#include "deque.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

void demo() {
  int size = 3;
  deq *d = create_deq(size);
  printf("Deck created\n");
  printf(" push front %d\n", 1);
  push_front(d, '1');
  printf("success\n");
  printf("push front %d\n", 2);
  push_front(d, '2');
  printf("success\n");
  printf("push back %d\n", 3);
  push_back(d, '3');
  printf("success\n");
  print_dek(d, size);
 //char t = ; // smtg doesnt work
 printf("first pop front: %c\n", pop_front(d));
  print_dek(d, size);

 printf("second pop back: %c\n", pop_back(d));
print_dek(d, size);
push_front(d, '4');
push_back(d, '5');
}

int main() {
  setlocale(LC_ALL, "Rus");
  demo();
}