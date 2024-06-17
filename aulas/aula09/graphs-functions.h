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
