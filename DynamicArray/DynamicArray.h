#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct DynamicArray {
    int* array;
    size_t size;
    size_t capacity;
};

struct DynamicArray* createDynamicArray(size_t);

void reallocateDynamicArray(struct DynamicArray*);

bool insertDynamicArray(struct DynamicArray*, size_t, int);

void prependDynamicArray(struct DynamicArray*, int);

void appendDynamicArray(struct DynamicArray*, int);

void printDynamicArray(struct DynamicArray*);

int* getDynamicArrayNode(struct DynamicArray*, size_t);

struct DynamicArrayNode* getDynamicArrayNodeFinal(struct DynamicArray*);

bool swapDynamicArrayNodes(struct DynamicArray*, size_t, size_t);

int8_t compare(int, int, bool);

void swapDynamicArrayData(int*, int*);

void sortDynamicArray(struct DynamicArray*, bool);

bool checkDynamicArraySorted(struct DynamicArray* Array, bool asc);

void deleteDynamicArray(struct DynamicArray* Array);

#endif