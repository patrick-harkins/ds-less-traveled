#include "./LinkedList.h"
#include "../Randomness/Randomness.h"

struct LinkedList* makeABigList(size_t size, int lowerBound, int upperBound) {
    struct LinkedList* LL = createLinkedList();
    for(size_t i = 0; i < size; ++i) {
        appendLinkedList(LL, randint(lowerBound, upperBound));
    }
    return LL;
}

int main() {
    /*
    struct LinkedList* LL = createLinkedList();
    appendLinkedList(LL, 1);
    appendLinkedList(LL, 3);
    appendLinkedList(LL, 4);
    insertLinkedList(LL, 1, 2);
    insertLinkedList(LL, 0, 5);
    appendLinkedList(LL, 78);
    appendLinkedList(LL, 69);
    appendLinkedList(LL, 420);
    appendLinkedList(LL, 5);
    appendLinkedList(LL, 0);
    for(int i=0; i <=10; ++i) appendLinkedList(LL, i);
    printLinkedList(LL);
    sortLinkedList(LL, false);
    printLinkedList(LL);
    sortLinkedList(LL, true);
    printLinkedList(LL);
    printf("%i\n", checkLinkedListSorted(LL, true));
    printLinkedList(LL);
    swapLinkedListNodes(LL, 0, 5);
    printLinkedList(LL);
    swapLinkedListNodes(LL, 5, 0);
    printLinkedList(LL);
    deleteLinkedList(LL);
    */
    RAND_SEED();
    struct LinkedList* LL = makeABigList(100, 1, 100);
    printf("Sorted %i %i\n", checkLinkedListSorted(LL, true), checkLinkedListSorted(LL, false));
    sortLinkedList(LL, true);
    printf("Sorted %i %i\n", checkLinkedListSorted(LL, true), checkLinkedListSorted(LL, false));
    sortLinkedList(LL, false);
    printf("Sorted %i %i\n", checkLinkedListSorted(LL, true), checkLinkedListSorted(LL, false));
    int* List = asArrayLinkedList(LL);
    free(List);
    deleteLinkedList_r(LL);
}