#include "memory.h"
 const int memory_value = 20;
 block array2[memory_value] = { 0 };
 int blockNumber = 1;
 int remains = memory_value;
 char memory[memory_value] = { 0 };

int operationNumber = 0;
void optimization() {
    int empty_block = 0;
    int first_place = -1;
    for (int i = 0; i < memory_value; i++) {
        if (array2[i].flag == 0) {
            empty_block++;
            if (empty_block == 1)
                first_place = i;
        }
        else if (empty_block != 0) {
            int size = array2[i].size;
            for (int j = 0; j < size; j++) {
                int place_empty = first_place + j;
                int place_not_empty = i + j;
                array2[place_empty].flag = 1;
                array2[place_not_empty].flag = 0;
                array2[place_empty].id = array2[place_not_empty].id;
                array2[place_not_empty].id = 0;
                array2[place_empty].link = &memory[place_empty];
                array2[place_not_empty].link = NULL;
                memory[place_empty] = '+';
                memory[place_not_empty] = 0;
            }
            first_place = -1;
            empty_block = 0;
        }
    }
}

void print_condition() {
      FILE *fp;
  if((fp=fopen("test", "wb"))==NULL) {
    printf("log doesn't work\n");
    exit(1);
  }
   fprintf(fp, "Condition");
    for (int i = 0; i < memory_value; i++) {
        if (array2[i].link != NULL)
            fprintf(fp, "Segment %d is used by %d\n", i + 1, array2[i].id);
        else
            fprintf(fp, "Segment %d isn't used\n", i + 1);
    }
      fclose(fp);
}

static void* addBlock(int size, int intro) {
    remains -= size;
    for (int j = intro; j < intro + size; j++) {
        memory[j] = '+';
        array2[j].flag = 1;
        array2[j].id = blockNumber;
        array2[j].link = &memory[j];
        array2[j].size = size;
    }
    blockNumber++;
    return &(memory[intro]);
}

static int findIntro(int size) {
    int empty_block = 0;
    int intro = -1;

    // ������� ������ ��������� ����� � ������ intro,
  // ���� ���-�� ������ ���� �� ������ ����� ������ �������
    for (int j = 0; j < memory_value; j++) {
        if (array2[j].link == NULL)
            empty_block++;
        else
            empty_block = 0;
        if (empty_block == size) {
            intro = j - empty_block + 1;
            return intro;
        }
    }
    return -1;
}

void *memory_allocate(size_t size) {
    if (operationNumber == 0){
        for (int i = 0; i < memory_value; i++) {
            array2[i].link = NULL;
        }
    }
    operationNumber++;
    if (size > remains || size == 0) {
        fprintf(stderr, "segfault\n\n");
        return 0;
    }
    int intro = findIntro( size);
    if (intro != -1) {
         operationNumber++;
        return addBlock(size, intro);
    }
    if (size >= remains & intro == -1) {
        optimization();
        intro = findIntro(size);
         operationNumber++;
        return addBlock(size, intro);
    }
    return 0;
}

void memory_delete(int i) {
    int keySize = 0;
    for (int j = 0; j < memory_value; j++) {
        if (array2[j].id == i) {
            keySize = array2[j].size;
            memory[j] = 0;
            array2[j].flag = 0;
            array2[j].id = 0;
            array2[j].size = 0;
            array2[j].link = NULL;
        }
    }
    remains += keySize;
}
