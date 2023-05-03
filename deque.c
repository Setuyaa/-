#include "memory.h"
#include  "deque.h"
char pop_front(deq *d) {
  if (d->count)
    {
    int index = d->head;
    if (d->count == 1)
      d->tail = d->head = -1;
    else if (++(d->head) == d->size) {
      d->head = 0;
    }
    d->count--;
    return d -> elements[index];
  }
  else return 0;
}

char pop_back(deq *d) {
  if (d->count)
  {
    int index = d->tail;
    if (d->count == 1)
      d->tail = d->head = -1;
    else if (--(d->tail) < 0)
      d->tail = d->size - 1;
    d->count--;
    return d->elements[index];
  }
  else return 0;
}
deq *create_deq(int size) {
  if (size <= 0)
    return 0;
  deq *d = memory_allocate(size);
  if (d) {
    d->size = size;
    d->head = d->tail = -1;
    d->count = 0;
    for (int i = 0; i < size; i++) {
      d->elements[i] = 0;
    }
  }
  return d;
}

deq *push_back(deq *d, char elem) {
  if (d->count) {
    if (++(d->tail) == d->size)
      d->tail = 0;
  } else
    d->tail = d->head = 0;
  d->elements[d->tail] = elem;
  d->count++;
  return d;
}
deq *push_front(deq *d, char elem) {
  if (d->count) {
    if (--(d->head) < 0)
      d->head = d->size - 1;
  } else
    d->tail = d->head = 0;
  d->elements[d->head] = elem;
  d->count++;
  return d;
}

typedef struct {
  deq *d;
  int index;
} iterator;

iterator get_iterator(deq *d, bool head) {
  iterator it;
  it.d = d;
  it.index = head ? d->head : d->tail;
  return it;
}

char next(iterator *it) {
  int index = it->index;
  if (index == it->d->tail)
    it->index = -1;
  else if (++(it->index) == it->d->size)
    it->index = 0;
  return it->d->elements[index];
}

char prev(iterator *it) {
  int index = it->index;
  if (index == it->d->head)
    it->index = -1;
  else if (--(it->index) < 0)
    it->index = it->d->size - 1;
  return it->d->elements[index];
}

void print_dek(deq *d, int size) {
  printf("print deck:\n");
  iterator it = get_iterator(d, true);
  int i = 0;
  while (it.index != -1) {
    printf("%d", i);
    printf(" under id : %c\n", next(&it));
    i++;
  };
  it = get_iterator(d, false);
  printf("\n");
}


