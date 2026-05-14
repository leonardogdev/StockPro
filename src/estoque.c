#include <stdio.h>
#include <string.h>

#include "../includes/produto.h"

void cadastrarProduto() {

    Produto novo;

    printf("\nCodigo: ");
    scanf("%d", &novo.codigo);

    getchar();

    printf("Nome: ");
    fgets(novo.nome, 50, stdin);

    novo.nome[strcspn(novo.nome, "\n")] = 0;

    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);

    printf("Preco: ");
    scanf("%f", &novo.preco);

    produtos[totalProdutos] = novo;

    totalProdutos++;

    printf("\nProduto cadastrado com sucesso!\n");
}

void listarProdutos() {

    printf("\n===== ESTOQUE =====\n");

    for(int i = 0; i < totalProdutos; i++) {

        printf("\nCodigo: %d\n",
        produtos[i].codigo);

        printf("Nome: %s\n",
        produtos[i].nome);

        printf("Quantidade: %d\n",
        produtos[i].quantidade);

        printf("Preco: R$ %.2f\n",
        produtos[i].preco);
    }
}

void entradaProduto() {

    int codigo;
    int quantidade;

    printf("\nCodigo do produto: ");
    scanf("%d", &codigo);

    printf("Quantidade entrada: ");
    scanf("%d", &quantidade);

    for(int i = 0; i < totalProdutos; i++) {

        if(produtos[i].codigo == codigo) {

            produtos[i].quantidade += quantidade;

            printf("\nEstoque atualizado!\n");

            return;
        }
    }

    printf("\nProduto nao encontrado!\n");
}

void saidaProduto() {

    int codigo;
    int quantidade;

    printf("\nCodigo do produto: ");
    scanf("%d", &codigo);

    printf("Quantidade retirada: ");
    scanf("%d", &quantidade);

    for(int i = 0; i < totalProdutos; i++) {

        if(produtos[i].codigo == codigo) {

            if(produtos[i].quantidade >= quantidade) {

                produtos[i].quantidade -= quantidade;

                printf("\nSaida realizada!\n");

            } else {

                printf("\nEstoque insuficiente!\n");
            }

            return;
        }
    }

    printf("\nProduto nao encontrado!\n");
}

void apagarProduto() {

    int codigo;
    int encontrado = 0;

    printf("\nCodigo do produto para apagar: ");
    scanf("%d", &codigo);

    for(int i = 0; i < totalProdutos; i++) {

        if(produtos[i].codigo == codigo) {

            encontrado = 1;

            for(int j = i; j < totalProdutos - 1; j++) {

                produtos[j] = produtos[j + 1];
            }

            totalProdutos--;

            printf("\nProduto removido com sucesso!\n");

            break;
        }
    }

    if(!encontrado) {

        printf("\nProduto nao encontrado!\n");
    }
}