#include "./HashTable.h"

struct HashTable* createHashTable(size_t capacity) {
    if (capacity <= 0) return NULL;
    struct HashTable* HT = calloc(1, sizeof(struct HashTable));
    HT->table = calloc(capacity, sizeof(struct KeyValueNode));
 
    HT->capacity = capacity;
    HT->size = 0;

    return HT;
}

// https://en.wikipedia.org/wiki/Jenkins_hash_function
size_t jenkinsHash(char* key) { 
    size_t hash = 0;
    for(size_t i = 0; i < strlen(key); ++i)
    {
        hash += key[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash;
}

void insertHashTable(struct HashTable* HT, char* key, int data) {
    if(key == NULL) return;

    size_t hashIndex = jenkinsHash(key) % HT->capacity;
    struct KeyValueNode* Node = HT->table + hashIndex;
    if (Node->key == NULL) {
        (HT->table + hashIndex)->next = NULL;
        (HT->table + hashIndex)->key = calloc(strlen(key)+1, sizeof(char));
        strcpy((HT->table + hashIndex)->key, key);
        (HT->table + hashIndex)->data = data;
        HT->size++;
        return;
    }
    while(Node->next != NULL) {
        if(strcmp(Node->next->key, key) == 0) {
            Node->next->data = data;
            return;
        }
        Node = Node->next;
    }
    Node->next = calloc(1, sizeof(struct KeyValueNode));
    Node->next->key = calloc(strlen(key)+1, sizeof(char));
    strcpy(Node->next->key, key);
    Node->next->data = data;
    HT->size++;
}

void insertHashTableNode(struct HashTable* HT, struct KeyValueNode* Node) {
    insertHashTable(HT, Node->key, Node->data);
}

void reallocateHashTable(struct HashTable* HT) {
    struct KeyValueNode* oldTable = HT->table;
    size_t oldCap = HT->capacity;
    size_t oldSize = HT->size;
    struct KeyValueNode* Node;

    HT->capacity *= 2;
    HT->table = calloc(HT->capacity, sizeof(struct KeyValueNode));
    
    for(size_t i=0; i < oldCap; ++i) {
        Node = oldTable + i;
        while(Node != NULL && Node->key != NULL) {
            insertHashTableNode(HT, Node);
            Node = Node->next;
        }
    }
    deleteTable_r(oldTable, oldCap);
    HT->size = oldSize;
}

void printHashChain(struct KeyValueNode* Node) {
    while(Node != NULL && Node->key != NULL) {
        printf("(%s, %i)->", Node->key, Node->data);
        Node = Node->next;
    }
}
void printHashTable(struct HashTable* HT) {
    printf("(Hash Table s%li c%li) [\n", HT->size, HT->capacity);
    for(size_t i = 0; i < HT->capacity; ++i) {
        printf("%li->", i);
        printHashChain((HT->table + i));
        printf("\n");
    }
    printf("]\n");
}

struct KeyValueNode* getHashTableNode(struct HashTable* HT, char* key) {
    size_t hashIndex = jenkinsHash(key) % HT->capacity;
    struct KeyValueNode* Node = (HT->table + hashIndex);
    while(Node != NULL) {
        if(strcmp(Node->key, key) == 0) {
            return Node;
        }
        Node = Node->next;
    }
    return NULL;
}

struct KeyValueNode* popHashTableNode(struct HashTable* HT, char* key) {
    size_t hashIndex = jenkinsHash(key) % HT->capacity;
    struct KeyValueNode* Node = (HT->table + hashIndex);
    while(Node != NULL) {
        if(strcmp(Node->key, key) == 0) {
            return Node;
        }
        Node = Node->next;
    }
    return NULL;
}

bool membershipHashTable(struct HashTable* HT, char* key) {
    return getHashTableNode(HT, key) != NULL;
}

char** keysArrayHashTable(struct HashTable* HT) {
    size_t j = 0;
    char** keys = calloc(HT->size, sizeof(char*));
    struct KeyValueNode* Node;
    for(size_t i = 0; i <HT->capacity; ++i) {
        Node = HT->table+i;
        while(Node != NULL && Node->key != NULL) {
            keys[j] = Node->key;
            j++;
            Node = Node->next;
        }
    }
    return keys;
}

int* valuesArrayHashTable(struct HashTable* HT) {
    size_t j = 0;
    int* values = calloc(HT->size, sizeof(int));
    struct KeyValueNode* Node;
    for(size_t i = 0; i <HT->capacity; ++i) {
        Node = HT->table+i;
        while(Node != NULL && Node->key != NULL) {
            values[j] = Node->data;
            j++;
            Node = Node->next;
        }
    }
    return values;
}

void deleteHashTable_r(struct HashTable* HT) {
    deleteTable_r(HT->table, HT->capacity);
    free(HT);
}

void deleteTable_r(struct KeyValueNode* table, size_t capacity) {
    for(size_t i =0; i < capacity; ++i) {
        if ((table + i)->key != NULL) {
            free((table+i)->key);
        }
        deleteTableChain_r((table + i)->next);
    }
    free(table);
}

void deleteTableChain_r(struct KeyValueNode* Node) {
    if(Node != NULL) {
        free(Node->key);
        deleteTableChain_r(Node->next);
        free(Node);
    }
}
