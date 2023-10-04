#include "./DynamicArray.h"

int main() {
    struct DynamicArray* DLL = createDynamicArray(20);
    // Insert elements
    appendDynamicArray(DLL, 10);
    appendDynamicArray(DLL, 30);
    insertDynamicArray(DLL, 1, 20);
    printDynamicArray(DLL);
    sortDynamicArray(DLL, false);
    printDynamicArray(DLL);
    sortDynamicArray(DLL, true);
    printDynamicArray(DLL);
    deleteDynamicArray(DLL);
}