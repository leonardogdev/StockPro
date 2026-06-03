#include <stdio.h>

float lerFloat() {
    float valor;

    while (1) {
        if (scanf("%f", &valor) == 1) {
            while (getchar() != '\n');
            return valor;
        }

        printf("Entrada invalida! Digite um numero: ");

        while (getchar() != '\n');
    }
}


int lerInteiro() {
    int valor;

    while (1) {
        if (scanf("%d", &valor) == 1) {
            while (getchar() != '\n'); // limpa buffer
            
            return valor;
        }

        printf("Entrada invalida! Digite um numero inteiro: ");

        while (getchar() != '\n'); // descarta entrada errada
    }
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void campoVazil(char campo){
    if (campo == '\n'){
        printf("erro: campo vazil");
        return;
    }
}