#include <stdio.h>
#include <stdlib.h>

typedef struct vizinho {
    int id;
    struct vizinho* prox;
} TViz;

typedef struct grafo {
    int id;
    TViz* prim_viz;
    struct grafo* prox;
} TGra;
