#include "./DoubleLinkedList.h"

int main() {
    struct DoubleLinkedList* DLL = createDoubleLinkedList();
    // Insert elements
    appendDoubleLinkedList(DLL, 10);
    appendDoubleLinkedList(DLL, 30);
    insertDoubleLinkedList(DLL, 1, 20);
    bool isSorted = checkDoubleLinkedListSorted(DLL, true);
    printDoubleLinkedList(DLL);
    deleteDoubleLinkedList(DLL);
}