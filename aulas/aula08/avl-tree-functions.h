#include <stdio.h>
#include <stdlib.h>

typedef struct avl {
    int key;
    int bf;
    struct avl* left, *right;
} TAVL;

TAVL* left_rotation(TAVL* root) {
    TAVL* aux = root -> right;

    root -> right = aux -> left; //return aux left-son to the root (to linking)

    aux -> left = root;
    root -> bf = 0;

    return aux;
}

TAVL* right_rotation(TAVL* root) {
    TAVL* aux = root -> left;

    root -> left = aux -> right; //return aux right-son to the root (to linking)

    aux -> right = root;
    root -> bf = 0;

    return aux;
}

TAVL* double_right_rotation(TAVL* root) {
    root -> left = left_rotation(root -> left);

    return right_rotation(root);
}

TAVL* double_left_rotation(TAVL* root) {
    root -> right = left_rotation(root -> right);

    return right_rotation(root);
}