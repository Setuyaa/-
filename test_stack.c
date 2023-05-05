#include "memory.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  setlocale(LC_ALL, "Rus");
  stack pt = create_stack(5);
  push(&pt, 'w');
  push(&pt, 'c');
  push(&pt, 'j');
  print_console(pt.items);
  printStack(pt);
  print(pt);
  char f = pop(&pt);
  printStack(pt);
  print(pt);
  print_console(pt.items);
  pop(&pt);
  printStack(pt);
  print(pt);
  pop(&pt);
  printStack(pt);
  print_console(pt.items);
  print(pt);
}