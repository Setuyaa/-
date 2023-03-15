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
        printf("���� ����");
        exit(EXIT_FAILURE);
    }
    printf("�������� �����: ");
    do{
        i--;
        printf("%c ", pt->items[i]);
    } while (i>0);
    printf("\n\n");
}

// �������� �����
struct stack* create_stack(int s_size){
    struct stack *pt = (struct stack*)calloc(1, sizeof(struct stack));
    pt->size = s_size;
    pt->top=-1;
    pt->items=(char*)calloc(sizeof(int), s_size);
};

// ��������, �������� �� ����
int isFull(struct stack *pt){
    return pt->top == pt->size-1;
}

// ���������� ��������
void push(struct stack *pt, char x){
    // �������� �� ����������� ����
    if (isFull(pt)){
        printf("���� ��������\n");
        exit(EXIT_FAILURE);
    }
    // ���������� x
    pt->items[++pt->top] = x;
    printf("������� %c ��������\n\n", x);
}

// �������� �� ������ ����
int isEmpty(struct stack *pt){
    return pt->top == -1;
}

// ������� ������� �����
int returnSize(struct stack *pt){
    return pt->top + 1;
}

// ������� ���������� ��������
char peek(struct stack *pt){
    if (!isEmpty(pt)){
        return pt->items[pt->top];
    }
    else {
        exit(EXIT_FAILURE);
    }
}

// ���������� �������� �������� �� �����
char pop(struct stack *pt){
    if(isEmpty(pt)){
        printf("���� ����");
        exit(EXIT_FAILURE);
    }
    printf("������� %c ������\n\n", peek(pt));
    return pt->items[pt->top--];
}

void print(struct stack *pt){
    for (int i = 0; i < pt->size; i++){
        if ( pt->items[i] != NULL) {
            printf("������ %i ������ �������� %c\n", i, pt->items[i]);
        }
        else printf("������ %i �� ������������\n", i);
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    struct stack *pt = create_stack(5);

    push(pt, 'w');
    push(pt, 'c');
    push(pt, 'j');

    printf("������� �������: %c\n", peek(pt));
    printf("������ �����: %d\n\n", returnSize(pt));
    printStack(pt);
    print(pt);
    printf("\n");
    pop(pt);
    pop(pt);
    pop(pt);

    if (isEmpty(pt)) {
        printf("���� ����");
    }
    else {
        printf("���� ����");
    }

    return 0;
}
