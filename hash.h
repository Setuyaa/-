#define MAX_ITEMS 5
typedef struct item {
    char* key;
    char* value;
    struct item* next; // указатель на следующий элемент в цепочке
} Item;
typedef struct {
    Item* table[MAX_ITEMS]; // массив указателей на элементы таблицы
} HashTable;


void put(HashTable* ht, char* key, char* value);
char* get(HashTable* ht, char* key);
void delete(HashTable* ht, char* key);
void printTable(HashTable* ht);