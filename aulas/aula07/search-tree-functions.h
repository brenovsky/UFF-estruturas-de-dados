#include <stdio.h>
#include <stdlib.h>

typedef struct search {
    int key;
    struct search* left, *right;
} TST;

TST* insert(TST* root, int value) {
    if (root == NULL) {
        TST* new = (TST*) malloc(sizeof(TST));

        new -> key = value;
        new -> left = NULL;
        new -> right = NULL;

        return new;
    }
    else if (value < root -> key) {
        root -> left = insert(root -> left, value);
    }
    else if (value > root -> key) {
        root -> right = insert(root -> right, value);
    }

    return root;
}

int count(TST* root, int i) {
    if (root != NULL) {
        i++;
        i = count(root -> left, i);
        i = count(root -> right, i);
    }
    return i;
}

TST* balance(TST* root2, int* vector, int begin, int finish) {
    if (begin > finish) {
        return NULL;
    }

    int mid = (begin + finish) / 2; //calculate middle position

    root2 = insert(root2, vector[mid]);

    root2 -> left = balance(root2 -> left, vector, begin, mid - 1);
    root2 -> right = balance(root2 -> right, vector, mid + 1, finish);

    return root2;
}

void print_tree(TST* root, int tab) {
    if (root != NULL) {
        for (int i = 0; i < tab; i++) printf("--");

        printf("%d\n", root->key);

        print_tree(root->left, tab + 1);
        print_tree(root->right, tab + 1);
    }

    //exclusao
}