typedef struct {
        char *data;  // указатель на данные
        int low;        // указатель на нижнюю границу
        int high;       // указатель на верхнюю границу
        int count;      // количество элементов в очереди
        int max;        // максимальное количество элементов
} queue;
queue init (int size);
void queue_add (queue *q, char a);
char queue_get (queue *q);
void print_queue(queue *q);
