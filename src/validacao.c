#include <stdio.h>


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