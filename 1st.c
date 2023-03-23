
#include "memory.h"

void demo() {
    printf("Демо режим\n");\
    char* ar[8];
    for (int i = 0; i < 6; i++) {
        int g = 0;
        scanf("%d", &g);
        ar[i] = memory_allocate(g);
    }
    printf("Состояние после выделения памяти:\n");
    print_condition();
    for (int i = 0; i < 6; i++) {
        print_console(ar[i]);
        printf("\n");
    }
    printf("Удаление блоков 2 и 4\n");
    memory_delete(ar[1]); // указатель
    memory_delete(ar[3]);  // указатель
    printf("Состояние памяти после удаления:\n");
  print_condition();
    for (int i = 0; i < 6; i++) {
        print_console(ar[i]);
        printf("\n");
    }
//     print_condition();
//     printf("Удаление блока 3\n");
//     memory_delete(2);  // указатель
//     printf("Состояние памяти после удаления:\n");
//     print_condition();
//     printf("Оптимизация памяти\n");
//     optimization();
//     printf("Состояние памяти после оптимизации:\n");
//     print_condition();
//     printf("Запрос на выделение памяти = memory_value. Впишите %d\n", 20);
//     ar[4] = memory_allocate(5);
//     printf("Запрос на выделение памяти = memory_value/2. Впишите %d\n", 20/2);
//     ar[5] = memory_allocate(6);
//     printf("Запрос на выделение памяти = memory_value/2. Впишите %d\n", 20/2);
//     ar[6] = memory_allocate(7);
//     printf("Запрос на выделение памяти = memory_value/2. Впишите %d\n", 20/2);
//    ar[7] = memory_allocate(8);
//     printf("Состояние после последнего выделения памяти:\n");
//     print_condition();
}

int main() {
    demo();
    return 0;
}