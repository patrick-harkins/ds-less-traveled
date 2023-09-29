#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

struct LinkedListNode{
    struct LinkedListNode* next;
    int data;
};

struct LinkedList{
    struct LinkedListNode* head;
    size_t size;
};

struct LinkedList* createLinkedList();
bool insertLinkedList(struct LinkedList*, size_t, int);
void prependLinkedList(struct LinkedList*, int);
void appendLinkedList(struct LinkedList*, int);
void printLinkedList(struct LinkedList*);
struct LinkedListNode* getLinkedListNode(struct LinkedList*, size_t);
struct LinkedListNode* getLinkedListNodeFinal(struct LinkedList*);
bool swapLinkedListNodes(struct LinkedList*, size_t, size_t);
int8_t compare(int, int, bool);
void swapLinkedListData(struct LinkedListNode*, struct LinkedListNode*);
void sortLinkedList(struct LinkedList*, bool);
void deleteLinkedList(struct LinkedList*);
void deleteLinkedListNode_r(struct LinkedListNode*);
void deleteLinkedList_r(struct LinkedList*);
int* asArrayLinkedList(struct LinkedList*);
bool checkLinkedListSorted(struct LinkedList*, bool);

#endif