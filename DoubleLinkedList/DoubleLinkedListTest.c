#include "./DoubleLinkedList.h"

int main() {
    struct DoubleLinkedList* DLL = createDoubleLinkedList();
    appendDoubleLinkedList(DLL, 1);
    appendDoubleLinkedList(DLL, 2);
    appendDoubleLinkedList(DLL, 4);
    prependDoubleLinkedList(DLL, -1);
    insertDoubleLinkedList(DLL, 1, 0);
    insertDoubleLinkedList(DLL, 4, 3);
    insertDoubleLinkedList(DLL, 0, -2);
    insertDoubleLinkedList(DLL, 6, 69);
    insertDoubleLinkedList(DLL, 6, 68);
    printDoubleLinkedList(DLL);
    sortDoubleLinkedList(DLL, false);
    printDoubleLinkedList(DLL);
    deleteDoubleLinkedList(DLL);
}