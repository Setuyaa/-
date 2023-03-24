#include "memory.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

void printStack(stack pt) {
  int i;
  i = pt.top + 1;
  if (isEmpty(&pt)) {
    printf("Stack is empty");
    exit(EXIT_FAILURE);
  }
  printf("Elements: ");
  do {
    i--;
    printf("%c ", pt.items[i]);
  } while (i > 0);
  printf("\n\n");
}

stack create_stack(int s_size) {
  stack pt;
  //(stack*)calloc(1, sizeof(stack));
  pt.size = s_size;
  pt.top = -1;
  pt.items = memory_allocate(s_size);
  return pt;
  //(char*)calloc(sizeof(int), s_size);
};

int isFull(stack pt) { return pt.top == pt.size - 1; }

void push(stack *pt, char x) {
  if (isFull(*pt)) {
    printf("Ñòåê çàïîëíåí\n");
    exit(EXIT_FAILURE);
  }
  pt->items[++pt->top] = x;
  printf("%d 1 \n", pt->top);
  printf("Element %c added\n\n", x);
}
int isEmpty(stack *pt) {
  printf("%d 2 \n", pt->top);
  return pt->top == -1;
}

int returnSize(stack pt) { return pt.top + 1; }

char peek(stack pt) {
  if (!isEmpty(&pt)) {
    return pt.items[pt.top];
  } else {
    exit(EXIT_FAILURE);
  }
}

char pop(stack *pt) {
  if (isEmpty(pt)) {
    printf("Stack is full");
    exit(EXIT_FAILURE);
  }
  printf("Element %c is pulled\n\n", peek(*pt));
  memory_delete_element(&(pt->items[pt->top]));
  return pt->items[pt->top--];
}

void print(stack pt) {
  for (int i = 0; i < pt.size; i++) {
    if (pt.items[i] != 0) {
      if (pt.items[i] == '+')
        printf("Segment %i isn't used\n", i);
      else
        printf("Segment %i is filled with %c\n", i, pt.items[i]);
    } else
      printf("Segment %i isn't used\n", i);
  }
}