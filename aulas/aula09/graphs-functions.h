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

TViz* search_edge(TGra* g, TViz* v1, TViz* v2) {
    TGra* pv1 = search_vertice(g, v1);
    TGra* pv2 = search_vertice(g, v2);

    TViz* target = NULL;

    if (pv1 && pv2) {
        target = g -> prim_viz;

        while(resp && resp -> id != v2) {
            resp = resp -> prox;
        }

    return resp;
}

TGra* insert_vertice(TGra* g, int x) {
    TGra* new = (TGra*) malloc(sizeof(TGra));

    new -> id = x;
    new -> prox = g;
    new -> prim_viz = NULL;

    return new;
}
