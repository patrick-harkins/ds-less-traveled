#include "./DoubleLinkedList.h"

struct DoubleLinkedList* createDoubleLinkedList() {
    struct DoubleLinkedList* DLL = calloc(1, sizeof(struct DoubleLinkedList));
    if (!DLL) return NULL;
    DLL->head = NULL;
    DLL->tail = NULL;
    DLL->size = 0;
    return DLL;
}

bool insertDoubleLinkedList(struct DoubleLinkedList* DLL, size_t index, int ins) {
    //0
    if (index > DLL->size || index < 0) return false;
    if (index == 0) {
        prependDoubleLinkedList(DLL, ins);
        return true;
    }

    if (index == DLL->size) {
        appendDoubleLinkedList(DLL, ins);
        return true;
    }
    struct DoubleLinkedListNode* Node;
    struct DoubleLinkedListNode* InsertionNode;
    size_t i;
    //head
    if (index < (DLL->size)/2) {
        //puts("head insertion");
        i = 0;
        Node = DLL->head;
        while(Node->next != NULL) {
            //printf("Node=%i i=%li\n", Node->data, i);
            if(i == index) {
                InsertionNode = calloc(1, sizeof(struct DoubleLinkedList));
                InsertionNode->data = ins;
                InsertionNode->next = Node;
                InsertionNode->prev = Node->prev;

                Node->prev->next = InsertionNode;
                Node->prev = InsertionNode;
                break;
            }
            i++;
            Node = Node->next;
        }
    }
    //tail
    else {
        i = DLL->size - 1;
        Node = DLL->tail;
        while(Node->prev != NULL) {
            if(i == index) {
                InsertionNode = calloc(1, sizeof(struct DoubleLinkedListNode));
                InsertionNode->data = ins;
                InsertionNode->next = Node;
                InsertionNode->prev = Node->prev;

                Node->prev->next = InsertionNode;
                Node->prev = InsertionNode;
                break;
            }
            i--;
            Node = Node->prev;
        }
    }

    DLL->size++;
    return true;
}

void prependDoubleLinkedList(struct DoubleLinkedList* DLL, int ins) {
    struct DoubleLinkedListNode* InsertionNode = DLL->head;
    //0
    if (InsertionNode == NULL) {
        InsertionNode = calloc(1, sizeof(struct DoubleLinkedListNode));
        InsertionNode->data = ins;
        DLL->head = InsertionNode;
        DLL->tail = InsertionNode;
        InsertionNode->next = NULL;
        InsertionNode->prev = NULL;
        DLL->size = 1;
        return;
    }

    struct DoubleLinkedListNode* NodeAfter = InsertionNode;
    InsertionNode = calloc(1, sizeof(struct DoubleLinkedListNode));
    DLL->head = InsertionNode;
    InsertionNode->data = ins;
    InsertionNode->next = NodeAfter;
    NodeAfter->prev = InsertionNode;
    DLL->size++;
}

void appendDoubleLinkedList(struct DoubleLinkedList* DLL, int ins) {
    struct DoubleLinkedListNode* Node = DLL->tail;
    if (Node == NULL) {
        DLL->head = calloc(1, sizeof(struct DoubleLinkedListNode));
        Node = DLL->head;
        Node->data = ins;
        DLL->tail = Node;
        DLL->size = 1;
        return;
    }

    Node->next = calloc(1, sizeof(struct DoubleLinkedListNode));
    Node->next->prev = Node;
    Node = Node->next;
    Node->data = ins;
    DLL->tail = Node;
    DLL->size++;
}

void printDoubleLinkedList(struct DoubleLinkedList* DLL) {
    struct DoubleLinkedListNode* Node = DLL->head;
    printf("(Double Linked List head %li)<->", DLL->size);

    while(Node != NULL) {
        printf("%i<->", Node->data);
        Node = Node->next;
    }

    printf("\n");
}

void printDoubleLinkedListReverse(struct DoubleLinkedList* DLL) {
    struct DoubleLinkedListNode* Node = DLL->tail;
    printf("(Double Linked List tail %li)<->", DLL->size);

    while(Node != NULL) {
        printf("%i<->", Node->data);
        Node = Node->prev;
    }

    printf("\n");
}

struct DoubleLinkedListNode* getDoubleLinkedListNode(struct DoubleLinkedList* DLL, size_t i) {
    if (i < 0 || i >= DLL->size) return NULL;
    struct DoubleLinkedListNode* Node;
    size_t j;
    if (i < (DLL->size)/2) {
        Node = DLL->head;
        j = 0;
        while(j != i) {
            Node = Node->next;
            j++;
        }
    }
    else {
        Node = DLL->tail;
        j = DLL->size - 1;
        while(j != i) {
            Node = Node->prev;
            j--;
        }
    }
    return Node;
}

struct DoubleLinkedListNode* getDoubleLinkedListNodeFinal(struct DoubleLinkedList* DLL) {
    return DLL->tail;
}

bool swapDoubleLinkedListNodes(struct DoubleLinkedList* DLL, size_t i, size_t j) {
    if(i < 0 || j < 0 || i == j || i >= DLL->size || j >= DLL->size) return false;
    
    struct DoubleLinkedListNode* iNode = getDoubleLinkedListNode(DLL, i);
    struct DoubleLinkedListNode* jNode = getDoubleLinkedListNode(DLL, j);
    
    swapDoubleLinkedListData(iNode, jNode);

    return true;
}

int8_t compare(int d1, int d2, bool asc) {
    if (d1 == d2) return 0;
    if (asc) return d1 > d2 ? -1 : 1;
    else return d1 > d2 ? 1 : -1;
}

void swapDoubleLinkedListData(struct DoubleLinkedListNode* iNode, struct DoubleLinkedListNode* jNode) {
    iNode->data = iNode->data^jNode->data;
    jNode->data = iNode->data^jNode->data;
    iNode->data = iNode->data^jNode->data;
}

void sortDoubleLinkedList(struct DoubleLinkedList* DLL, bool asc) {
    if(DLL->size <= 1) {
        return;
    }
    struct DoubleLinkedListNode* NodeEnd = getDoubleLinkedListNodeFinal(DLL);

    struct DoubleLinkedListNode* n1 = DLL->head;
    struct DoubleLinkedListNode* n2 = n1->next;

    while (NodeEnd != DLL->head) {
        n1 = DLL->head;
        n2 = n1->next;
        while(n2 != NodeEnd) {
            n2 = n1->next;
            if (compare(n1->data, n2->data, asc) < 0) {
                swapDoubleLinkedListData(n1, n2);
            }
            n2 = n2->next;
            n1 = n1->next;
        }
        if (compare(n1->data, n2->data, asc) < 0) {
            swapDoubleLinkedListData(n1, n2);
        }
        NodeEnd = n1;
    }

}

void deleteDoubleLinkedList(struct DoubleLinkedList* DLL) {
    struct DoubleLinkedListNode* p1 = DLL->head;

    //0
    if (p1 ==  NULL) {
        free(DLL);
        return;
    }

    struct DoubleLinkedListNode* p2;

    if(p1->next != NULL) {
        p2 = p1->next;
    }
    //1
    else {
        free(p1);
        free(DLL);
        return;
    }

    while(p2 != NULL) {
        free(p1);
        p1 = p2;
        p2 = p2->next;
    }

    free(p1);
    free(DLL);

}

void deleteDoubleLinkedListNode_r(struct DoubleLinkedListNode* Node) {
    if(Node != NULL) {
        deleteDoubleLinkedListNode_r(Node->next);
        free(Node);
    }
}

void deleteDoubleLinkedList_r(struct DoubleLinkedList* DLL) {
    struct DoubleLinkedListNode* Node = DLL->head;
    deleteDoubleLinkedListNode_r(Node);
    free(DLL);
}

int* asArrayDoubleLinkedList(struct DoubleLinkedList* DLL) {
    if(DLL->size == 0) {
        return NULL;
    }
    int* array = calloc(DLL->size, sizeof(int));
    int* ins = array;
    struct DoubleLinkedListNode* Node = DLL->head;
    while(Node != NULL) {
        *ins = Node->data;
        ins++;
        Node = Node->next;
    }
    return array;
}

bool checkDoubleLinkedListSorted(struct DoubleLinkedList* DLL, bool asc) {
    if(DLL->size <= 1) return true;
    int prev = DLL->head->data;
    struct DoubleLinkedListNode* Node = DLL->head->next;
    while(Node != NULL) {
        if(asc) {
            if (Node->data < prev) return false;
        }
        else {
            if (Node->data > prev) return false;
        }
        prev = Node->data;
        Node = Node->next; 
    }
    return true;
}