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

TList* lastStruct(TList* list) {
    while (list -> prox != NULL) {
        list = list -> prox;
    }

    return list;
}

TList* concatenate(TList* list3, TList* list1, TList* list2) {


    list3 = list1;

    lastStruct(list3) -> prox = list2;

    return list3;
}
int main() {

    TList* l1 = NULL;
    TList* l2 = NULL;
    TList* l3 = NULL;

    l1 = insertEnd(l1, 2);
    l1 = insertEnd(l1, 13);
    l1 = insertEnd(l1, 12);
    l1 = insertEnd(l1, 32);
    l1 = insertEnd(l1, 52);

    l2 = insertEnd(l2, 20);
    l2 = insertEnd(l2, 21);
    l2 = insertEnd(l2, 23);
    l2 = insertEnd(l2, 24);
    l2 = insertEnd(l2, 25);

    l3 = concatenate(l3, l1, l2);

    return 0;
}