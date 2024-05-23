#include "
#include "search-tree-functions.h"


int main() {
    TST* root = NULL;
    TST* root2 = NULL;

    root = insert(root, 5);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 10);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 12);

    print_tree(root, 0);

    int length = count(root, 0);

    //algoritmo de sort

    int vector[length] = {3, 4, 5, 6, 7, 10, 12};

    //algoritmo do vetor





    return 0;
}