#include <stdio.h>
#include <stdbool.h>
#include <assert.h> // Include the assert macro

// Include your library header
#include "./DoubleLinkedList.h"

void testCreateDoubleLinkedList() {
    struct DoubleLinkedList* list = createDoubleLinkedList();
    assert(list != NULL);
    assert(list->head == NULL);
    assert(list->tail == NULL);
    assert(list->size == 0);
    deleteDoubleLinkedList(list);
}

void testInsertDoubleLinkedList() {
    struct DoubleLinkedList* list = createDoubleLinkedList();
    assert(insertDoubleLinkedList(list, 0, 10) == true);
    assert(list->size == 1);
    assert(list->head->data == 10);
    assert(list->tail->data == 10);
    deleteDoubleLinkedList(list);
}

void testAppendDoubleLinkedList() {
    struct DoubleLinkedList* list = createDoubleLinkedList();
    appendDoubleLinkedList(list, 10);
    assert(list->size == 1);
    assert(list->head->data == 10);
    assert(list->tail->data == 10);
    deleteDoubleLinkedList(list);
}

void testSwapDoubleLinkedListNodes() {
    struct DoubleLinkedList* list = createDoubleLinkedList();
    appendDoubleLinkedList(list, 10);
    appendDoubleLinkedList(list, 20);
    appendDoubleLinkedList(list, 30);
    assert(swapDoubleLinkedListNodes(list, 0, 2) == true);
    assert(list->size == 3);
    assert(list->head->data == 30);
    assert(list->tail->data == 10);
    deleteDoubleLinkedList(list);
}

void testSortDoubleLinkedList() {
    struct DoubleLinkedList* list = createDoubleLinkedList();
    appendDoubleLinkedList(list, 30);
    appendDoubleLinkedList(list, 10);
    appendDoubleLinkedList(list, 20);
    sortDoubleLinkedList(list, true);
    assert(list->size == 3);
    assert(list->head->data == 10);
    assert(list->tail->data == 30);
    deleteDoubleLinkedList(list);
}

// Add more test functions for other library functions

int main() {
    testCreateDoubleLinkedList();
    testInsertDoubleLinkedList();
    testAppendDoubleLinkedList();
    testSwapDoubleLinkedListNodes();
    testSortDoubleLinkedList();
    // Add calls to other test functions

    printf("All tests passed!\n");
    return 0;
}
