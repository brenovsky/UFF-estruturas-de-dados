#include <stdio.h>
#include <stdlib.h>

void desconto(float gasto) {

    float valor = gasto * 0.9;

    printf("A vista: R$%.2f\n", valor);
}

void parceladoDuasVezes(float gasto) {
    float valor = gasto / 2;

    printf("Parcela 2x (sem juros): R$%.2f 2x\n", valor);
}

void parcelaJuros(float gasto, int n) {
    float valor = gasto;

    for (int i = 1; i <= n; i++) {
        valor += 0.03 * valor;
        printf("%d parcela: R$%.2f\n", i, valor);
    }
}

int main() {

    float gasto;
    int opcao;

    printf("Insira o valor gasto: R$");
    scanf("%f", &gasto);

    if (gasto > 100) {
        printf("1 - A vista com desconto de 0.1\n");
        printf("2 - Parcela em duas vezes (sem juros)\n");
        printf("3 - Parcela de 3 ate 10 vezes (com juros de 0.03 a.m)\n");

        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                desconto(gasto);
                break;
            case 2:
                parceladoDuasVezes(gasto);
                break;
            case 3:
                printf("Quantas vezes gostaria de parcelar?");
                int n;
                scanf("%d", &n);
                parcelaJuros(gasto, n);
                break;

        }
    } else {
        printf("1 - A vista com desconto de 0.1\n");
        printf("2 - Parcela em duas vezes (sem juros)\n");

        scanf("%d", &opcao);

        switch(opcao) {
        case 1:
            desconto(gasto);
        break;
        case 2:
            parceladoDuasVezes(gasto);
        break;
        }
    }

    printf("\nProcessando sua compra...\n\n");
    printf("Obrigado! Volte sempre!\n");
    return 0;
}