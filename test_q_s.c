#include "memory.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Инициализируем стек и очередь
  stack s = create_stack(3);
  queue q = init(5);
 
  // Добавляем элементы в стек
  push(&s, 'A');
  push(&s, 'B');
  push(&s, 'C');

  // Добавляем элементы в очередь
  queue_add(&q, 'X');
  queue_add(&q, 'Y');
  queue_add(&q, 'Z');

  // Выводим стек и очередь
  printf("Stack:\n");
  print(s);
  printf("\nQueue:\n");
  print_queue(&q); 

  // Удаляем элемент из стека
  printf("The process of deleting from stack.\n");
  pop(&s);
  printf("Queue ");
  print_console(q.data);
  printf("\n");
  char w = queue_get(&q);
  printf("Element %c deleted from queue.\n", w);
  // Выводим измененный стек и очередь
  printf("\nStack after removal:\n");
  print(s);
  printf("\nQueue after removal:\n");
  print_queue(&q);
  printf("Queue ");
  print_console(q.data);
  printf("\n");
}