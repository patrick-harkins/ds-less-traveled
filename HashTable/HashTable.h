#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct KeyValueNode{
    struct KeyValueNode* next;
    char* key;
    int data;
};

struct HashTable{
    struct KeyValueNode* table;
    size_t size;
    size_t capacity;
};

struct HashTable* createHashTable(size_t);
size_t jenkinsHash(char*);
void insertHashTable(struct HashTable*, char*, int);
void insertHashTableNode(struct HashTable*, struct KeyValueNode*);
void reallocateHashTable(struct HashTable*);
void printHashChain(struct KeyValueNode*);
void printHashTable(struct HashTable*);
struct KeyValueNode* getHashTableNode(struct HashTable*, char*);
struct KeyValueNode* popHashTableNode(struct HashTable*, char*);
bool membershipHashTable(struct HashTable*, char*);
char** keysArrayHashTable(struct HashTable*);
int* valuesArrayHashTable(struct HashTable*);
void deleteHashTable_r(struct HashTable*);
void deleteTable_r(struct KeyValueNode*, size_t);
void deleteTableChain_r(struct KeyValueNode*);


#endif