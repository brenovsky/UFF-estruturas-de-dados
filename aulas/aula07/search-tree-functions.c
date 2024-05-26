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

    int vector[7] = {3, 4, 5, 6, 7, 10, 12};

    root2 = balance(root2, vector, 0, length - 1);

    print_tree(root2, 0);

    return 0;
}