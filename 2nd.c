#include <stdio.h>
#include <stdlib.h>
#include "memory.h"
#include "queue.h"
#include "stack.c"

int main() {
    // Инициализируем стек и очередь
    stack s = create_stack(3);
    queue q = init(3);

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

    // Выбираем элемент для удаления из стека
    char remove_stack;
    printf("\nEnter the element to remove from the stack: ");
    scanf("%c", &remove_stack);

    // Удаляем элемент из стека
    int stack_size = returnSize(s);
    int i;
    for (i = 0; i < stack_size; i++) {
        if (s.items[i] == remove_stack) {
            memory_delete_element(&(s.items[i]));
            break;
        }
    }
    if (i == stack_size) {
        printf("Element not found in stack.\n");
    }
    else {
        s.top--;
        printf("Element %c removed from stack.\n", remove_stack);
    }

    // Выбираем элемент для удаления из очереди
    char remove_queue;
    printf("\nEnter the element to remove from the queue: ");
    scanf("%c", &remove_queue);

    // Удаляем элемент из очереди
    int queue_size = q.count;
    for (i = 0; i < queue_size; i++) {
        char current = queue_get(&q);
        if (current == remove_queue) {
            printf("Element %c removed from queue.\n", remove_queue);
            break;
        }
        queue_add(&q, current);
    }
    if (i == queue_size) {
        printf("Element not found in queue.\n");
    }

    // Выводим измененный стек и очередь
    printf("\nStack after removal:\n");
    print(s);
    printf("\nQueue after removal:\n");
    print_queue(&q);
}