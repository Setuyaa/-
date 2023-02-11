#define memory_value 20
#include <stdio.h>
#include <stdlib.h>
struct block {
    int flag;
    int razm;
    int id;
    char* link;
};
void optimization(struct block *array2, char *memory) {
    int empty_block = 0;
    int first_place = -1;
    for (int i = 0; i < memory_value; i++) {
        if (array2[i].flag == 0) {
            empty_block++;
            if (empty_block == 1)
                first_place = i;
        }
        else if (empty_block != 0) {
            int razm = array2[i].razm;
            for (int j = 0; j < razm; j++) {
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
void print_condition(struct block *array2) {
for (int i = 0; i < memory_value; i++) {
    if (array2[i].link !=  NULL)
        printf("Ячейка памяти %d используется блоком %d\n", i + 1, array2[i].id + 1);
    else 
        printf("Ячейка памяти %d не используется\n", i + 1);
    }
}
void memory_allocate(int *remains, int i,  struct block *array2,  char *memory) {
    int razm = 0;
    printf("Введите размер %d блока\n", i + 1);
    scanf("%d", &razm);
    if (razm > *remains) {
        fprintf(stderr, "segfault\n");
        return;
    }
    int empty_block = 0;
    int intro = -1;
    for (int j = 0; j < memory_value;  j++) {
        if (array2[j].link == NULL) 
            empty_block++;
        else 
            empty_block = 0;
        if (empty_block == razm) {
            intro = j - empty_block + 1;
            break;
        }
    } 
    if (intro != -1) {
        *remains -= razm;
        for (int j = intro; j < intro + razm; j++) {
            memory[j] = '+';
            array2[j].flag = 1;
            array2[j].id = i;
            array2[j].link = &memory[j];
            array2[j].razm = razm;
        }
    } 
    // else { // for not demo
    //     optimization();
    // }
}
void memory_delete(int i, int *remains, struct block *array2, char *memory) {
    *remains += array2[i].razm;
    for (int j = 0; j < memory_value; j++) {
        if (array2[j].id == i) {
            memory[j] = 0;
            array2[j].flag = 0;
            array2[j].id = 0;
            array2[j].razm = 0;
            array2[j].link = NULL;
        }

    }
}
void demo() {
    printf("Демо режим\n");
    int remains = memory_value; 
    char memory[memory_value] = {0};
    struct block array2[memory_value] = {0};
    for (int i = 0; i < memory_value; i++) {
        array2[i].link= NULL;
    }
    for (int i = 0; i < 5; i++) {
        memory_allocate(&remains, i, array2, memory);
    }
    printf("Состояние после выделения памяти:\n");
    print_condition(array2);
    printf("Удаление блоков 2 и 4\n");
    memory_delete(1, &remains, array2, memory);
    memory_delete(3, &remains, array2, memory);
    printf("Состояние памяти после удаления:\n");
    print_condition(array2);
    printf("Удаление блока 3\n");
    memory_delete(2, &remains, array2, memory);
    printf("Состояние памяти после удаления:\n");
    print_condition(array2);
    printf("Оптимизация памяти\n");
    optimization(array2, memory);
    printf("Состояние памяти после оптимизации:\n");
    print_condition(array2);
    printf("Запрос на выделение памяти = memory_value. Впишите %d\n", memory_value);
    memory_allocate(&remains, 5, array2, memory);
    printf("Запрос на выделение памяти = memory_value/2. Впишите %d\n", memory_value/2);
    memory_allocate(&remains, 6, array2, memory);
    printf("Запрос на выделение памяти = memory_value/2. Впишите %d\n", memory_value/2);
    memory_allocate(&remains, 7, array2, memory);
    printf("Запрос на выделение памяти = memory_value/2. Впишите %d\n", memory_value/2);
    memory_allocate(&remains, 8, array2, memory);
    printf("Состояние после последнего выделения памяти:\n");
    print_condition(array2);
}

int main() {
    demo();
    return 0;
}