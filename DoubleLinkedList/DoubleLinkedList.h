#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

struct DoubleLinkedListNode{
    struct DoubleLinkedListNode* next;
    struct DoubleLinkedListNode* prev;
    int data;
};

struct DoubleLinkedList{
    struct DoubleLinkedListNode* head;
    struct DoubleLinkedListNode* tail;
    size_t size;
};

struct DoubleLinkedList* createDoubleLinkedList();
bool insertDoubleLinkedList(struct DoubleLinkedList*, size_t, int);
void prependDoubleLinkedList(struct DoubleLinkedList*, int);
void appendDoubleLinkedList(struct DoubleLinkedList*, int);
void printDoubleLinkedList(struct DoubleLinkedList*);
void printDoubleLinkedListReverse(struct DoubleLinkedList*);

struct DoubleLinkedListNode* getDoubleLinkedListNode(struct DoubleLinkedList*, size_t);
struct DoubleLinkedListNode* getDoubleLinkedListNodeFinal(struct DoubleLinkedList*);
bool swapDoubleLinkedListNodes(struct DoubleLinkedList*, size_t, size_t);
int8_t compare(int, int, bool);
void swapDoubleLinkedListData(struct DoubleLinkedListNode*, struct DoubleLinkedListNode*);
void sortDoubleLinkedList(struct DoubleLinkedList*, bool);

void deleteDoubleLinkedList(struct DoubleLinkedList*);

void deleteDoubleListNode_r(struct DoubleLinkedListNode*);
void deleteDoubleList_r(struct DoubleLinkedList*);
int* asArrayDoubleLinkedList(struct DoubleLinkedList*);
bool checkDoubleLinkedListSorted(struct DoubleLinkedList*, bool);


#endif