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
}

int children(TST* root) {
    int i = 0;

    if (root -> left != NULL) i++;
    if (root -> right != NULL) i++;

    return i;
}

TST* greater_right(TST* root) {
    TST* aux = root;

    while (aux -> right != NULL) {
        aux = aux -> right;
    }

    return aux;
}

TST* delete(TST* root, int value) {
    if (root -> key == value) {
        if (children(root) == 0) { // node
            free(root);

            return NULL;
        }

        else if (children(root) == 1) { // 1 child
            TST* aux;

            if (root -> left != NULL) aux = root -> left;
            else aux = root -> right;

            free(root);
            
            return aux;
        }

        else { // 2 child
            TST* greater = greater_right(root -> left);

            root -> key = greater -> key;

            root -> left = delete(root -> left, greater -> key);

            return root;
        }

    }

    else if (root -> key > value) root -> left = delete(root -> left, value);

    else if (root -> key < value) root -> right = delete(root -> right, value);

    return root;
}