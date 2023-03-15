#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct stack {
    int size;
    int top;
    char* items;
};

void printStack(struct stack *pt){

    int i;
    i = pt->top+1;

    if(isEmpty(pt)){
        printf("Стек пуст");
        exit(EXIT_FAILURE);
    }
    printf("Элементы стека: ");
    do{
        i--;
        printf("%c ", pt->items[i]);
    } while (i>0);
    printf("\n\n");
}

// Создание стека
struct stack* create_stack(int s_size){
    struct stack *pt = (struct stack*)calloc(1, sizeof(struct stack));
    pt->size = s_size;
    pt->top=-1;
    pt->items=(char*)calloc(sizeof(int), s_size);
};

// Проверка, заполнен ли стек
int isFull(struct stack *pt){
    return pt->top == pt->size-1;
}

// Добавление элемента
void push(struct stack *pt, char x){
    // Проверка на заполненный стек
    if (isFull(pt)){
        printf("Стек заполнен\n");
        exit(EXIT_FAILURE);
    }
    // Добавление x
    pt->items[++pt->top] = x;
    printf("Элемент %c добавлен\n\n", x);
}

// Проверка на пустой стек
int isEmpty(struct stack *pt){
    return pt->top == -1;
}

// Возврат размера стека
int returnSize(struct stack *pt){
    return pt->top + 1;
}

// Возврат последнего элемента
char peek(struct stack *pt){
    if (!isEmpty(pt)){
        return pt->items[pt->top];
    }
    else {
        exit(EXIT_FAILURE);
    }
}

// Извлечение верхнего элемента из стека
char pop(struct stack *pt){
    if(isEmpty(pt)){
        printf("Стек пуст");
        exit(EXIT_FAILURE);
    }
    printf("Элемент %c удален\n\n", peek(pt));
    return pt->items[pt->top--];
}

void print(struct stack *pt){
    for (int i = 0; i < pt->size; i++){
        if ( pt->items[i] != NULL) {
            printf("Ячейка %i занята символом %c\n", i, pt->items[i]);
        }
        else printf("Ячейка %i не используется\n", i);
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    struct stack *pt = create_stack(5);

    push(pt, 'w');
    push(pt, 'c');
    push(pt, 'j');

    printf("Верхний элемент: %c\n", peek(pt));
    printf("Размер стека: %d\n\n", returnSize(pt));
    printStack(pt);
    print(pt);
    printf("\n");
    pop(pt);
    pop(pt);
    pop(pt);

    if (isEmpty(pt)) {
        printf("Стек пуст");
    }
    else {
        printf("Стек пуст");
    }

    return 0;
}
