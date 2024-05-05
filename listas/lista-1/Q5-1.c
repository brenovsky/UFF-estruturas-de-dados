#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int info;
    struct list* prox;
} TList;

TList* insertEnd(TList* li, int value) {
    if (li == NULL) {
        TList* new = (TList*) malloc(sizeof(TList));

        new -> info = value;
        new -> prox = NULL;

        return new;
    }
    li -> prox = insertEnd(li -> prox, value);

    return li;
}

TList* insertBeg(TList* li, int value) {
    TList* new = (TList*) malloc(sizeof(TList));

    new -> info = value;
    new -> prox = li;

    return new;
}

TList* invert(TList* l1, TList* l2) {
    for(TList* p = l1; p != NULL; p = p -> prox) {
        l2 = insertBeg(l2, p -> info);
    }

    return l2;
}

int main() {
    TList* l1 = NULL;
    TList* l2 = NULL;

    l1 = insertEnd(l1, 1);
    l1 = insertEnd(l1, 2);
    l1 = insertEnd(l1, 3);
    l1 = insertEnd(l1, 4);
    l1 = insertEnd(l1, 5);

    l2 = invert(l1, l2);

    return 0;
}