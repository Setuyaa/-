#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct queue {
        char *data;  // указатель на данные
        int low;        // указатель на нижнюю границу
        int high;       // указатель на верхнюю границу
        int count;      // количество элементов в очереди
        int max;        // максимальное количество элементов
};
struct queue *init (int size)
{
        struct queue * q = calloc(1, sizeof (struct queue));
        q->data = calloc (size, sizeof (void*));
        q->low = q->high = size - 1;
        q->max = size;
        return q;
}
void queue_add (struct queue *q, char a)
{
        if (q->count == q->max) {
                fprintf (stderr, "not enough queue size\n");
                return;
        }
        q->data[q->low--] = a;
        q->count++;

        if (q->low < 0) {
                q->low = q->max - 1;
        }
}
char queue_get (struct queue *q)
{
        char a = q->data[q->high--];
        q->count--;

        if (q->high < 0) {
                q->high = q->max - 1;
        }
        return a;
}
int main (int argc, char **argv)
{
    struct queue *q = init (10);

    queue_add (q, '2');
    queue_add (q, 'c');
    queue_add (q, 'b');
    queue_add (q, 'a');

    for (int i = 0; i < 4; i++) {
        char ret = queue_get (q);
        printf ("%c\n", ret);
    }
}
