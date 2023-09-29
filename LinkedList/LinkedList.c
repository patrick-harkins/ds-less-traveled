#include "./LinkedList.h"


struct LinkedList* createLinkedList() {
    struct LinkedList* LL = calloc(1, sizeof(struct LinkedList));
    if (!LL) return NULL;
    LL->head = NULL;
    LL->size = 0;
    return LL;
}

bool insertLinkedList(struct LinkedList* LL, size_t index, int ins) {
    if (index > LL->size || index < 0) return false;
    if (index == 0) {
        prependLinkedList(LL, ins);
        return true;
    }
    if (index == LL->size) {
        appendLinkedList(LL, ins);
        return true;
    }
    struct LinkedListNode* Node = LL->head;
    struct LinkedListNode* NodeAfter = LL->head->next;
    size_t i = 1;
    while(Node->next != NULL) {
        if(i == index) {
            NodeAfter = Node->next;
            Node->next = calloc(1, sizeof(struct LinkedList));
            Node = Node->next;
            Node->data = ins;
            Node->next = NodeAfter;
            break;
        }
        i++;
        Node = Node->next;
    }

    LL->size++;
    return true;
}

void prependLinkedList(struct LinkedList* LL, int ins) {
    struct LinkedListNode* InsertionNode = LL->head;
    //0
    if (InsertionNode == NULL) {
        InsertionNode = calloc(1, sizeof(struct LinkedListNode));
        InsertionNode->data = ins;
        LL->head = InsertionNode;
        InsertionNode->next = NULL;
        LL->size = 1;
        return;
    }

    struct LinkedListNode* NodeAfter = InsertionNode;
    InsertionNode = calloc(1, sizeof(struct LinkedListNode));
    LL->head = InsertionNode;
    InsertionNode->data = ins;
    InsertionNode->next = NodeAfter;
    LL->size++;
}

void appendLinkedList(struct LinkedList* LL, int ins) {
    struct LinkedListNode* Node = LL->head;
    if (Node == NULL) {
        prependLinkedList(LL, ins);
        return;
    }

    while (Node->next != NULL) {
        Node = Node->next;
    }

    Node->next = calloc(1, sizeof(struct LinkedListNode));
    Node = Node->next;
    Node->data = ins;
    LL->size++;
}

void printLinkedList(struct LinkedList* LL) {
    struct LinkedListNode* Node = LL->head;
    printf("(Linked List %li)->", LL->size);

    while(Node != NULL) {
        printf("%i->", Node->data);
        Node = Node->next;
    }

    printf("\n");
}

struct LinkedListNode* getLinkedListNode(struct LinkedList* LL, size_t i) {
    //0
    if(i < 0 || i >= LL->size) {
        return NULL;
    }

    size_t j = 0;
    struct LinkedListNode* Node = LL->head;

    while(j < i) {
        Node = Node->next;
        j++;
    }

    return Node;

}

struct LinkedListNode* getLinkedListNodeFinal(struct LinkedList* LL) {
    return getLinkedListNode(LL, LL->size-1);
}

bool swapLinkedListNodes(struct LinkedList* LL, size_t i, size_t j) {
    if(i < 0 || j < 0 || i == j || i >= LL->size || j >= LL->size) return false;

    struct LinkedListNode* iNode = getLinkedListNode(LL, i);
    struct LinkedListNode* jNode = getLinkedListNode(LL, j);

    swapLinkedListData(iNode, jNode);

    return true;
}

int8_t compare(int d1, int d2, bool asc) {
    if (d1 == d2) return 0;
    if (asc) return d1 > d2 ? -1 : 1;
    else return d1 > d2 ? 1 : -1;
}

void swapLinkedListData(struct LinkedListNode* iNode, struct LinkedListNode* jNode) {
    iNode->data = iNode->data^jNode->data;
    jNode->data = iNode->data^jNode->data;
    iNode->data = iNode->data^jNode->data;
}

void sortLinkedList(struct LinkedList* LL, bool asc) {
    if(LL->size <= 1) {
        return;
    }
    struct LinkedListNode* NodeEnd = getLinkedListNodeFinal(LL);

    struct LinkedListNode* n1 = LL->head;
    struct LinkedListNode* n2 = n1->next;

    while (NodeEnd != LL->head) {
        n1 = LL->head;
        n2 = n1->next;
        while(n2 != NodeEnd) {
            n2 = n1->next;
            if (compare(n1->data, n2->data, asc) < 0) {
                swapLinkedListData(n1, n2);
            }
            n2 = n2->next;
            n1 = n1->next;
        }
        if (compare(n1->data, n2->data, asc) < 0) {
            swapLinkedListData(n1, n2);
        }
        NodeEnd = n1;
    }

}

void deleteLinkedList(struct LinkedList* LL) {
    struct LinkedListNode* p1 = LL->head;

    //0
    if (p1 ==  NULL) {
        free(LL);
        return;
    }

    struct LinkedListNode* p2;

    if(p1->next != NULL) {
        p2 = p1->next;
    }
    //1
    else {
        free(p1);
        free(LL);
        return;
    }

    while(p2 != NULL) {
        free(p1);
        p1 = p2;
        p2 = p2->next;
    }

    free(p1);
    free(LL);
}

void deleteLinkedListNode_r(struct LinkedListNode* Node) {
    if(Node != NULL) {
        deleteLinkedListNode_r(Node->next);
        free(Node);
    }
}

void deleteLinkedList_r(struct LinkedList* LL) {
    struct LinkedListNode* Node = LL->head;
    deleteLinkedListNode_r(Node);
    free(LL);
}

int* asArrayLinkedList(struct LinkedList* LL) {
    if(LL->size == 0) {
        return NULL;
    }
    int* array = calloc(LL->size, sizeof(int));
    int* ins = array;
    struct LinkedListNode* Node = LL->head;
    while(Node != NULL) {
        *ins = Node->data;
        ins++;
        Node = Node->next;
    }
    return array;
}

bool checkLinkedListSorted(struct LinkedList* LL, bool asc) {
    if(LL->size <= 1) return true;
    int prev = LL->head->data;
    struct LinkedListNode* Node = LL->head->next;
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