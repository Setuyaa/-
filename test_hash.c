#include "hash.h"
#include "memory.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    HashTable ht = { { NULL } };

    put(&ht, "ананас", "ananas");
    put(&ht, "петрушка", "parsley");
    put(&ht, "банан", "banana");
    put(&ht, "персик", "peach");

    printTable(&ht);

    get(&ht, "петрушка");
    get(&ht, "персик");

    delete(&ht, "ананас");
    delete(&ht, "банан");
    return 0;
}
