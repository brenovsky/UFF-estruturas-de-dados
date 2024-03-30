#include <stdio.h>
#include <stdlib.h>

void fibonacci(int* vetor, int n) {
    int a = 0;
    int b = 1;
    int temp;

    for (int i = 0; i < n; i++) {
        vetor[i] = b;

        temp = a + b;
        a = b;
        b = temp;
    }
}

int main() {
    int n;
    int* array;

    scanf("%d", &n);

    array = (int*) malloc(sizeof(int) * n);

    fibonacci(array, n);

    for (int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }

    free(array);

    return 0;
}