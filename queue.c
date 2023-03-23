#include "memory.h"
#include "queue.h"

queue init (int size)
{
        queue q;
        q.data = memory_allocate (size);
        q.low = q.high = size - 1;
        q.max = size;
        q.count = 0;
        return q;
}
void queue_add (queue *q, char a)
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
char queue_get (queue *q)
{
        char a = q->data[q->max -1];
        memory_delete_element(&(q->data[q->high--]));
        q->count--;
        queue_activity(q->data, q->max, q->count);
        if (q->high < 0) {
                q->high = q->max - 1;
        }
        return a;
}

void print_queue(queue *q) {
   printf("Condition");
   int data = 0;
        while (q[data].data != NULL) {
            printf("Segment %d is used by %s\n", q[data].count, q[data].data);
            data++;
        }
}