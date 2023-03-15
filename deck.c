#define memory_value 20
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
typedef int el_type;         //тип элементов дека

typedef struct
{
    int head;                //индекс головы
    int tail;                //индекс хвоста
    int size;                //размер массива elements
    int count;               //количество элементов в деке
    el_type elements[];      //массив для хранения элементов
} deq;

//удалить из начала
el_type pop_front(deq* d)
{
    if (!d->count)
        printf("Ошибка дек пустой\n");
    else
    {
        int index = d->head;
        if (d->count == 1)
            d->tail = d->head = -1;
        else
            if (++(d->head) == d->size)
            {
                d->head = 0;
            }
        d->count--;
        return d->elements[index];
    }
}

//удалить из конца

el_type pop_back(deq* d)
{
    if (!d->count)
        printf("Ошибка дек пустой\n");
    else
    {
        int index = d->tail;
        if (d->count == 1)
            d->tail = d->head = -1;
        else
            if (--(d->tail) < 0)
                d->tail = d->size - 1;
        d->count--;
        return d->elements[index];
    }
}
deq* create_deq(int size)
{

    if (size <= 0)
        return 0;
    deq* d = malloc(sizeof(deq) + size * sizeof(el_type));
    if (d)
    {
        d->size = size;
        d->head = d->tail = -1;
        d->count = 0;
        for (int i = 0; i < size; i++)
        {
            d->elements[i] = 0;
            //flag[i] = 1;
        }
    }
    return d;
}
//вставить в конец
deq* push_back(deq* d, el_type elem)
{
    if (d->count)
    {
        if (++(d->tail) == d->size)
            d->tail = 0;
    }
    else
        d->tail = d->head = 0;
    d->elements[d->tail] = elem;

    d->count++;
    return d;
}

//вставить в начало

deq* push_front(deq* d, el_type elem)
{
    if (d->count)
    {
        if (--(d->head) < 0)
            d->head = d->size - 1;
    }
    else
        d->tail = d->head = 0;
    d->elements[d->head] = elem;
    d->count++;
    return d;
}


typedef struct
{
    deq* d;
    int index;
} iterator;

//получить итератор

iterator get_iterator(deq* d, bool head)
{
    iterator it;
    it.d = d;
    it.index = head ? d->head : d->tail;
    return it;
}

// получить текущий элемент и сделать текущим следующий
el_type next(iterator* it)
{
    int index = it->index;
    if (index == it->d->tail)
        it->index = -1;
    else
        if (++(it->index) == it->d->size)
            it->index = 0;
    return it->d->elements[index];
}

//получить текущий элемент и сделать текущим предыдущий

el_type prev(iterator* it)
{
    int index = it->index;
    if (index == it->d->head)
        it->index = -1;
    else
        if (--(it->index) < 0)
            it->index = it->d->size - 1;
    return it->d->elements[index];
}


void print_dek(deq* d, int size)
{
    printf("Дек:\n");
    iterator it = get_iterator(d, true);
    int i = 0;
    while (it.index != -1)
    {
        printf("%d", i);
        printf(" элемент: %d\n", next(&it));
        i++;
        /*if (flag[i] == 0)
            printf(" не используется");*/
    };
    it = get_iterator(d, false);
    printf("\n");
}

void demo()
{
    int size = 3;
    //int* flag = malloc(sizeof(int) * size);

    deq * d = create_deq(size);
    printf("Добавить два элемента в начало дека и третий в конец- Элементы в следующем порядке : второй, первый, третий;\n");
    printf("Добавляем в начало: %d\n", 1);
    push_front(d, 1);
    printf("Добавляем в начало: %d\n", 2);
    push_front(d, 2);
    printf("Добавляем в конец: %d\n", 3);
    push_back(d, 3);
    print_dek(d, size);

    printf("Выбрать и удалить элемент из начала дека - вернется второй элемент, остались: первый, третий;\n");
    pop_front(d);
    print_dek(d, size);

    printf("Выбрать и удалить элемент из конца дека - вернется третий элемент, остался только первый элемент;\n");
    pop_back(d);
    print_dek(d, size);

    printf("Выбрать и удалить элемент из конца дека - вернется первый элемент, дек пуст;\n");
    pop_back(d);
    print_dek(d, size);

    printf("ыбрать и удалить элемент из начала дека - Программа продолжает работать, но возвращается код неудачного выполнения операции\n");
    pop_front(d);
    print_dek(d, size);
}

int main() {
    setlocale(LC_ALL, "Rus");
    demo();
}
