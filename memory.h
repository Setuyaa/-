#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdint.h>

void optimization();
void print_condition();
void* memory_allocate(size_t size);
void memory_delete(char * arr);
void memory_delete_element(char *a);
void print_console(char* arr);
typedef struct {
    int flag;
    int size;
    int id;
    char* link;
} block;
typedef struct {
    int size;
    int top;
    char* items;
}stack;
stack create_stack(int s_size);
void print(stack pt);
char pop(stack* pt);
int isEmpty(stack* pt);
void push(stack *pt, char x);
void printStack(stack pt);
int returnSize(stack pt);
char peek(stack pt);




