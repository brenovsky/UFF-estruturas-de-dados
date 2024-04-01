#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char returnString(char* word) {
    if (*word != '\0') {//The pointer points to the beginning of the list, initially
        printf("%c", *word);

        return returnString(word + 1); //+1 byte (char)
    }

    return '\0';
}



char returnStringReverse(char* word, int n) {//recursive algorithm to print reversed(string)
    if (n >= 0) {

    printf("%c", word[n]);

    return returnStringReverse(word,n - 1);
    }

    return '\0';
}


int main() {

    char word[80];

    gets(word);

    returnString(word);
    printf("\n");
    returnStringReverse(word, strlen(word) - 1);

    return 0;
}