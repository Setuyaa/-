#define memory_value 20
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char head;           
  char tail;           
  int size;           
  int count;          
  char elements[]; 
} deq;
deq *create_deq(int size);
deq *push_back(deq *d, char elem);
deq *push_front(deq *d, char elem);
char pop_back(deq *d);
char pop_front(deq *d);
void print_dek(deq *d, int size);
