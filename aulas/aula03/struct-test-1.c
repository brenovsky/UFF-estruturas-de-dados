#include <stdio.h>
#include <stdlib.h>

typedef struct ponto2d {
    int x;
    int y;
} TPonto;

int main() {

    TPonto p;

    scanf("%d %d", &p.x, &p.y);

    printf("%d %d", p.x, p.y);

    return 0;
}