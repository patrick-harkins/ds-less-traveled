#include "./DynamicArray.h"

struct DynamicArray* createDynamicArray(size_t capacity) {
    struct DynamicArray* Array = calloc(1, sizeof(struct DynamicArray));
    Array->array = calloc(capacity, sizeof(int));
    if (!Array) return NULL;
    Array->capacity = capacity;
    Array->size = 0;
    return Array;
}

void reallocateDynamicArray(struct DynamicArray* Array) {
    int* new = calloc(2*Array->capacity, sizeof(int));
    memcpy(new, Array->array, Array->size * sizeof(int));
    free(Array->array);
    Array->array = new;
    Array->capacity = 2*Array->capacity;
}

bool insertDynamicArray(struct DynamicArray* Array, size_t index, int ins) {
    if (Array->size + 1 > Array->capacity) {
        reallocateDynamicArray(Array);
    }
    
    int* insertionPoint = Array->array + index;
    int* endPoint = Array->array + Array->size;

    while (endPoint != insertionPoint)
    {
        *endPoint = *(endPoint - 1);
        endPoint--;
    }
    
    *insertionPoint = ins;

    Array->size++;
    return true;
}

void prependDynamicArray(struct DynamicArray* Array, int ins) {
    insertDynamicArray(Array, 0, ins);

}

void appendDynamicArray(struct DynamicArray* Array, int ins) {
    insertDynamicArray(Array, Array->size, ins);
}

void printDynamicArray(struct DynamicArray* Array) {
    printf("(Dynamic Array s%li c%li)[", Array->size, Array->capacity);

    for(size_t i = 0; i < Array->size; ++i) {
        printf("%i,", Array->array[i]);
    }
    printf("]\n");
}

void printDynamicArrayReverse(struct DynamicArray* Array) {
    printf("(Dynamic Array Reverse s%li c%li)[", Array->size, Array->capacity);

    for(size_t i = Array->size-1; i >= 0; --i) {
        printf("%i, ", Array->array[i]);
    }
    printf("]\n");
}

int* getDynamicArray(struct DynamicArray* Array, size_t i) {
    if (i < 0 || i >= Array->size) return NULL;
    return Array->array + i;
}

int* getDynamicArrayFinal(struct DynamicArray* Array) {
    if (Array-> size == 0) return NULL;
    return Array->array + (Array->size - 1);
}

int getDynamicArrayValue(struct DynamicArray* Array, size_t i) {
    int* node = getDynamicArray(Array, i);
    if (node != NULL) {
        return *node;
    }
    return -1;
}

bool swapDynamicArrayNodes(struct DynamicArray* Array, size_t i, size_t j) {
    if(i < 0 || j < 0 || i == j || i >= Array->size || j >= Array->size) return false;
    
    int* iNode = getDynamicArray(Array, i);
    int* jNode = getDynamicArray(Array, j);
    
    swapDynamicArrayData(iNode, jNode);

    return true;
}

int compare_asc(const void* d1, const void* d2) {
    if (*(int*)d1 == *(int*)d2) return 0;
    return *(int*)d1 > *(int*)d2 ? -1 : 1;
}

int compare_desc(const void* d1, const void* d2) {
    if (*(int*)d1 == *(int*)d2) return 0;
    return *(int*)d1 < *(int*)d2 ? -1 : 1;
}

void swapDynamicArrayData(int* iNode, int* jNode) {
    *iNode = *iNode^*jNode;
    *jNode = *iNode^*jNode;
    *iNode = *iNode^*jNode;
}

void sortDynamicArray(struct DynamicArray* Array, bool asc) {
    if(Array->size <= 1) {
        return;
    }
    if (asc) {
        qsort(Array->array, Array->size, sizeof(int), compare_asc);
    }
    else {
        qsort(Array->array, Array->size, sizeof(int), compare_desc);
    }

}

void deleteDynamicArray(struct DynamicArray* Array) {
    free(Array->array);
    free(Array);
}

int* copyArrayDynamicArray(struct DynamicArray* Array) {
    if(Array->size == 0) {
        return NULL;
    }
    int* array = calloc(Array->size, sizeof(int));
    memcpy(array, Array->array, Array->size*sizeof(int));
    return array;
}

bool checkDynamicArraySorted(struct DynamicArray* Array, bool asc) {
    if(Array->size <= 1) return true;

    for(size_t i = 1; i < Array->size; ++i) {
        if(asc) {
            if (Array->array[i] < Array->array[i-1]) return false;
        }
        else {
            if (Array->array[i] > Array->array[i-1]) return false;
        }
    }
    return true;
}