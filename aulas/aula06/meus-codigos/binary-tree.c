#include "binary-trees-operations.h"

int main() {

    TTree* root;

    root = createTree();

    root = insertRoot(100);

    root = insertLeft(root, 20);

    root = insertRight(root, 50);

    return 0;
}

// e com mais niveis? esse código vai precisar ser alterado...