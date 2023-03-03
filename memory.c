#include "memory.h"

int blockNumber = 1;
int remains = memory_value;
char memory[memory_value] = { 0 };
struct block array2[memory_value] = { 0 };
int operationNumber = 0;

static void optimization(struct block* array2, char* memory) {
    int empty_block = 0;
    int first_place = -1;
    for (int i = 0; i < memory_value; i++) {
        if (array2[i].flag == 0) {
            empty_block++;
            if (empty_block == 1)
                first_place = i;
        }
        else if (empty_block != 0) {
            int size = array2[i].size;
            for (int j = 0; j < size; j++) {
                int place_empty = first_place + j;
                int place_not_empty = i + j;
                array2[place_empty].flag = 1;
                array2[place_not_empty].flag = 0;
                array2[place_empty].id = array2[place_not_empty].id;
                array2[place_not_empty].id = 0;
                array2[place_empty].link = &memory[place_empty];
                array2[place_not_empty].link = NULL;
                memory[place_empty] = '+';
                memory[place_not_empty] = 0;
            }
            first_place = -1;
            empty_block = 0;
        }
    }
}

static void print_condition(struct block* array2) {
      FILE *fp;
  if((fp=fopen("test", "wb"))==NULL) {
    printf("He удается открыть файл.\n");
    exit(1);
  }
    for (int i = 0; i < memory_value; i++) {
        if (array2[i].link != NULL)
            fprintf(fp, "Ячейка памяти %d используется блоком %d\n", i + 1, array2[i].id);
        else
            fprintf(fp, "Ячейка памяти %d не используется\n", i + 1);
    }
      fclose(fp);
}

static void addBlock(struct block* array2, char* memory, int* remains, int size, int intro) {

    *remains -= size;
    for (int j = intro; j < intro + size; j++) {
        memory[j] = '+';
        array2[j].flag = 1;
        array2[j].id = blockNumber;
        array2[j].link = &memory[j];
        array2[j].size = size;
    }
}

static int findIntro(struct block* array2, int size) {
    int empty_block = 0;
    int intro = -1;

    // Находим ячейку вхождения блока в память intro,
  // если кол-во идущих друг за другом ячеек памяти хватает
    for (int j = 0; j < memory_value; j++) {
        if (array2[j].link == NULL)
            empty_block++;
        else
            empty_block = 0;
        if (empty_block == size) {
            intro = j - empty_block + 1;
            return intro;
        }
    }
    return -1;
}

void memory_allocate(int* remains, int i, struct block* array2, char* memory) {
    int size = 0;
    if (operationNumber == 0){
        for (int i = 0; i < memory_value; i++) {
            array2[i].link = NULL;
        }
    }
    operationNumber++;
    printf("\nВведите размер %d блока\n", i);
    scanf_s("%d", &size);
    printf("\n");

    // Если не хватает памяти, выдает ошибку
    if (size > *remains || size == 0) {
        fprintf(stderr, "segfault\n\n");
        return;
    }

    // Поиск ячейки вхождения
    int intro = findIntro(array2, size);

    // Если существует ячейка вхождения, добавляем блок
    if (intro != -1) {
        addBlock(array2, memory, remains, size, intro);
    }

    // Если не существует, но память имеется, делаем оптимизацию и добавляем блок
    if (size >= *remains & intro == -1) {
        optimization(array2, memory);
        printf("Произошла оптимизация\n\n");
        intro = findIntro(array2, size);
        addBlock(array2, memory, remains, size, intro);
    }
    operationNumber++;
}

void memory_delete(int i, int* remains, struct block* array2, char* memory) {
    int keySize = 0;
    for (int j = 0; j < memory_value; j++) {
        if (array2[j].id == i) {
            keySize = array2[j].size;
            memory[j] = 0;
            array2[j].flag = 0;
            array2[j].id = 0;
            array2[j].size = 0;
            array2[j].link = NULL;
        }
    }
    *remains += keySize;
}
