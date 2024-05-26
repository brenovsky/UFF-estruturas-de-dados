#include "search-tree-functions.h"


int main() {
    TST* root = NULL;
    TST* root2 = NULL;

    root = insert(root, 200);
    root = insert(root, 100);
    root = insert(root, 300);
    root = insert(root, 80);
    root = insert(root, 150);
    root = insert(root, 250);
    root = insert(root, 400);
    root = insert(root, 350);
    root = insert(root, 500);
    root = insert(root, 220);
    root = insert(root, 270);
    root = insert(root, 260);
    root = insert(root, 280);
    root = insert(root, 275);
    root = insert(root, 290);

    root = delete(root, 300);

    print_tree(root, 0);

    int length = count(root, 0);

    int vector[7] = {3, 4, 5, 6, 7, 10, 12};

    root2 = balance(root2, vector, 0, length - 1);

    print_tree(root2, 0);

    return 0;
}