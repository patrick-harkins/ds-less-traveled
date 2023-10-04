#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Structure representing a node in a doubly linked list.
 */
struct DoubleLinkedListNode {
    struct DoubleLinkedListNode* next; // Pointer to the next node in the list.
    struct DoubleLinkedListNode* prev; // Pointer to the previous node in the list.
    int data; // The data stored in this node.
};

/**
 * Structure representing a doubly linked list.
 */
struct DoubleLinkedList {
    struct DoubleLinkedListNode* head; // Pointer to the first node (head) of the list.
    struct DoubleLinkedListNode* tail; // Pointer to the last node (tail) of the list.
    size_t size; // The number of nodes currently in the list.
};

/**
 * Creates a new double linked list and initializes it with empty values.
 *
 * @return A pointer to the newly created double linked list.
 */
struct DoubleLinkedList* createDoubleLinkedList();

/**
 * Inserts a new node with the given data at the specified position in the double linked list.
 *
 * @param list Pointer to the double linked list.
 * @param position The index at which to insert the new node (0-based index).
 * @param data The data to be stored in the new node.
 * @return True if the insertion is successful, false otherwise (e.g., if the position is out of bounds).
 */
bool insertDoubleLinkedList(struct DoubleLinkedList* list, size_t position, int data);

/**
 * Prepends a new node with the given data to the beginning of the double linked list.
 *
 * @param list Pointer to the double linked list.
 * @param data The data to be stored in the new node.
 */
void prependDoubleLinkedList(struct DoubleLinkedList* list, int data);

/**
 * Appends a new node with the given data to the end of the double linked list.
 *
 * @param list Pointer to the double linked list.
 * @param data The data to be stored in the new node.
 */
void appendDoubleLinkedList(struct DoubleLinkedList* list, int data);

/**
 * Prints the elements of the double linked list in forward order.
 *
 * @param list Pointer to the double linked list.
 */
void printDoubleLinkedList(struct DoubleLinkedList* list);

/**
 * Prints the elements of the double linked list in reverse order.
 *
 * @param list Pointer to the double linked list.
 */
void printDoubleLinkedListReverse(struct DoubleLinkedList* list);

/**
 * Retrieves the node at the specified position in the double linked list.
 *
 * @param list Pointer to the double linked list.
 * @param position The index of the node to retrieve (0-based index).
 * @return A pointer to the node if found, or NULL if the position is out of bounds.
 */
struct DoubleLinkedListNode* getDoubleLinkedListNode(struct DoubleLinkedList* list, size_t position);

/**
 * Retrieves the last node in the double linked list.
 *
 * @param list Pointer to the double linked list.
 * @return A pointer to the last node if the list is not empty, or NULL if the list is empty.
 */
struct DoubleLinkedListNode* getDoubleLinkedListNodeFinal(struct DoubleLinkedList* list);

/**
 * Swaps the positions of two nodes in the double linked list.
 *
 * @param list Pointer to the double linked list.
 * @param position1 The index of the first node to swap (0-based index).
 * @param position2 The index of the second node to swap (0-based index).
 * @return True if the swapping is successful, false otherwise (e.g., if positions are out of bounds).
 */
bool swapDoubleLinkedListNodes(struct DoubleLinkedList* list, size_t position1, size_t position2);

/**
 * Compares two integers and returns the result based on the specified comparison type.
 *
 * @param a The first integer.
 * @param b The second integer.
 * @param ascending True for ascending order, false for descending order.
 * @return -1 if a < b, 0 if a == b, or 1 if a > b (based on the specified order).
 */
int8_t compare(int a, int b, bool ascending);

/**
 * Swaps the data of two double linked list nodes.
 *
 * @param node1 Pointer to the first node.
 * @param node2 Pointer to the second node.
 */
void swapDoubleLinkedListData(struct DoubleLinkedListNode* node1, struct DoubleLinkedListNode* node2);

/**
 * Sorts the elements in the double linked list in either ascending or descending order.
 *
 * @param list Pointer to the double linked list.
 * @param ascending True for ascending order, false for descending order.
 */
void sortDoubleLinkedList(struct DoubleLinkedList* list, bool ascending);

/**
 * Deletes the entire double linked list and frees the memory.
 *
 * @param list Pointer to the double linked list to be deleted.
 */
void deleteDoubleLinkedList(struct DoubleLinkedList* list);

/**
 * Recursively deletes a double linked list node and its successors.
 *
 * @param node Pointer to the node to be deleted.
 */
void deleteDoubleLinkedListNode_r(struct DoubleLinkedListNode* node);

/**
 * Recursively deletes an entire double linked list.
 *
 * @param list Pointer to the double linked list to be deleted.
 */
void deleteDoubleLinkedList_r(struct DoubleLinkedList* list);

/**
 * Converts the elements of the double linked list into an integer array.
 *
 * @param list Pointer to the double linked list.
 * @return A dynamically allocated integer array containing the list elements.
 */
int* asArrayDoubleLinkedList(struct DoubleLinkedList* list);

/**
 * Checks if the double linked list is sorted in the specified order.
 *
 * @param list Pointer to the double linked list.
 * @param ascending True for ascending order, false for descending order.
 * @return True if the list is sorted as specified, false otherwise.
 */
bool checkDoubleLinkedListSorted(struct DoubleLinkedList* list, bool ascending);


#endif