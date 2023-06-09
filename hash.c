#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include "memory.h"
// хеш-функция
unsigned int hash(char* key)
{
    unsigned int sum = 0;
    int i = 0;
    while (key[i] != '\0') {
        sum += key[i];
        i++;
    }
    return sum % MAX_ITEMS;
}
HashTable* CreateTable(){
    HashTable *ht;
    return ht;
}
static Item* CreateItem (char* key, char* value){
    Item* newItem ; //(Item*)memmory_allocate(sizeof(Item));
    newItem -> key = memory_allocate(strlen(key));
    newItem -> value =  memory_allocate(strlen(value));
    strcpy(newItem -> key, key);
    strcpy(newItem -> value, value);
    newItem->next = NULL;
    return newItem;
}
// добавление элемента в таблицу
void put(HashTable* ht, char* key, char* value)
{
     unsigned int index = hash(key);
    Item* new_item= (Item*)memmory_allocate(sizeof(Item));
    new_item->key = key;
    new_item->value = value;
    new_item->next = NULL;

    if (ht->table[index] == NULL) {
        ht->table[index] = new_item;
    }
    else { // коллизия – добавление в начало цепочки
        new_item->next = ht->table[index];
        ht->table[index] = new_item;
    }

    printf("Added item: %s - %s\n", key, value);
}

// получение значения элемента по ключу
char* get(HashTable* ht, char* key)
{
    unsigned int index = hash(key);
    Item* current = ht->table[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            printf("Found item: %s - %s\n", current->key, current->value);
            return current->value;
        }
        current = current->next;
    }

    printf("Item not found: %s\n", key);
    return NULL;
}

// удаление элемента по ключу
void delete(HashTable* ht, char* key)
{
    unsigned int index = hash(key);

    Item* current = ht->table[index];
    Item* previous = NULL;

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            if (previous == NULL) { // элемент первый в цепочке
                ht->table[index] = current->next;
            }
            else { // элемент в середине или конце
                previous->next = current->next;
            }
            printf("Deleted item: %s\n", key);
            memmory_delete(current);
            return;
        }

        previous = current;
        current = current->next;
    }

    printf("Item not found: %s\n", key);
}

void printTable(HashTable* ht)
{
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        //if (ht->table[i] != NULL) // (печатает все/только не NULL строчки)
        //{
            Item* curr = ht->table[i];
            printf("[%d]: ", i);
            while (curr != NULL)
            {
                printf("%s - %s ", curr->key, curr->value);
                curr = curr->next;
            }
            printf("\n");
        //}
    }
}
