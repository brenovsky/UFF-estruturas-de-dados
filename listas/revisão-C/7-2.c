#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char string[80];

    gets(string);

    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] != ' ') {
            printf("%c", string[i]);
        } else {
            printf("\n");
        }
    }

    return 0;
}