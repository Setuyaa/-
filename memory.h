#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void optimization();
void print_condition();
void* memory_allocate(size_t size);
void memory_delete(int i);
typedef struct {
    int flag;
    int size;
    int id;
    char* link;
} block;



