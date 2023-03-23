#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "memory.h"
#include "queue.h"

int main (int argc, char **argv)
{
    queue q = init (10);
    queue_add (&q, '2');
    //    printf("%s\n", q.data);
    queue_add (&q, 'c');
     //   printf("%s\n", q.data);
    queue_add (&q, 'b');
     //   printf("%s\n", q.data);
    queue_add (&q, 'a');
   // printf("%s\n", q.data);
    for (int i = 0; i < 4; i++) {
        char ret = queue_get(&q);
         printf("\n%c\n", ret);
         print_console(q.data);
         printf("\n");
    }
}
