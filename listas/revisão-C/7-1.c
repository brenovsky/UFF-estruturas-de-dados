#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char string[80];

    gets(string);

    int tamanho = strlen(string);
    int pont = 0;
    int num = 0;
    int min = 0;

    for (int i = 0; string[i] != '\0'; i++){
        if (string[i] == '!' || string[i] == '?' || string[i] == '.' || string[i] == ',') {//pontuacoes
            pont +=1;
        }
        else if(string[i] < 'A' && string[i] != ' ') {//identificar numero
            num += 1;
        }
        else if(string[i] > 'Z') {//identificar letras minusculas
            min += 1;
        }
    }

    printf("%d, %d, %d, %d\n", tamanho, pont, num, min);

    return 0;
}