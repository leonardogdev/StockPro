#include <stdio.h>
#include "../includes/arquivo.h"
#include "../includes/produto.h"

Produto produtos[MAX_PRODUTOS];
int totalProdutos = 0;

void salvarDados() {

    FILE *arquivo; // cria um ponteiro

    arquivo = fopen("data/dados.txt", "w"); // cria um arquivo vazio

    if (arquivo == NULL) {
        printf("Erro ao salvar arquivo!\n");
        return;
    }

    for(int i = 0; i < totalProdutos; i++) {

        fprintf(arquivo,
        "%d;%s;%d;%.2f\n",
        produtos[i].codigo,
        produtos[i].nome,
        produtos[i].quantidade,
        produtos[i].preco);
    }

    fclose(arquivo);
}

void carregarDados() {

    FILE *arquivo;

    arquivo = fopen("data/dados.txt", "r");

    if (arquivo == NULL) {
        return;
    }
// %d inteiro ;%49[^;] ate 49 caracteres com espaço ;%d inteiro ;%f float
    while(fscanf(arquivo,
    "%d;%49[^;];%d;%f", 
    &produtos[totalProdutos].codigo,
    produtos[totalProdutos].nome,
    &produtos[totalProdutos].quantidade,
    &produtos[totalProdutos].preco) == 4) {

        totalProdutos++;
    }

    fclose(arquivo);
}