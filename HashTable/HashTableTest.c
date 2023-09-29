#include "./HashTable.h"

int main() {
    struct HashTable* HT = createHashTable(10);
    insertHashTable(HT, "hello", 0);
    insertHashTable(HT, "hello1", 1);
    insertHashTable(HT, "hello2", 2);
    insertHashTable(HT, "hello3", 3);
    insertHashTable(HT, "hello4", 4);
    insertHashTable(HT, "hello5", 5);
    insertHashTable(HT, "hello6", 6);
    insertHashTable(HT, "hello7", 7);
    insertHashTable(HT, "hello8", 8);
    
    printHashTable(HT);
    char** keys = keysArrayHashTable(HT);
    free(keys);
    int* values = valuesArrayHashTable(HT);
    free(values);
    reallocateHashTable(HT);
    printHashTable(HT);
    deleteHashTable_r(HT);

    
    return 0;
}