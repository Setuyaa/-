#pragma once
#define memory_value 20
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct block {
    int flag;
    int size;
    int id;
    char* link;
};

void memory_delete(int i, int* remains, struct block* array2, char* memory);
void memory_allocate(int* remains, int i, struct block* array2, char* memory);
