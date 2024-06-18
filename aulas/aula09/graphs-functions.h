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

TGra* inicializa(TGra* g) {
    return NULL;
}

void print_graph(TGra* g) {
    for (g; g != NULL; g = g -> prox) {
        printf("Vertice: %d\n", g -> id);
        printf("Vizinhos: ");

        for (TViz* v = g -> prim_viz; v != NULL; v = v -> prox) {
            printf("%d ", v => id);
        }

        printf("\n\n");
    }
}

void libera_viz(TViz* v) {
    while (v != NULL) {
        TViz* aux = v;

        v = v -> prox;

        free(aux);
    }
}

void libera_grafo(TGra* g) {
    while (g != NULL) {
        libera_viz(g -> prim_viz);

        aux = g;

        g = g -> prox;

        free(aux);
    }
}

TGra* search_vertice(TGra* int x) {
    if (g != NULL) {
        if (g -> id == x) return g;
    }

    return g;
}
