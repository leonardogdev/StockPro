#include <stdio.h>
#include <string.h>

#include "../includes/produto.h"
#include "../includes/menu.h"
#include "../includes/arquivo.h"
#include "../includes/validacao.h"


void cadastrarProduto() {

    Produto novo;

    printf("\nCodigo: ");
    scanf("%d", &novo.codigo);
    limparBuffer();
    

    for (int i=0; i < totalProdutos; i++){
        if (produtos[i].codigo == novo.codigo){
            printf("%d o codigo ja foi cadastrado\n",novo.codigo);
            return;
        }
    }

    printf("Nome: ");
    fgets(novo.nome, 50, stdin);

    novo.nome[strcspn(novo.nome, "\n")] = '\0';

    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);
    limparBuffer();

    printf("Preco: ");
    scanf("%f", &novo.preco);
    limparBuffer();

    produtos[totalProdutos] = novo;

    totalProdutos++;
    salvarDados();
    printf("\nProduto cadastrado com sucesso!\n");
}

void listarProdutos() {

    printf("\n===== ESTOQUE =====\n");
    printf("%-10s\t%-20s\t%-10s\t%-10s\n\n","codigo","nome","quantidade","preco");

    for(int i = 0; i < totalProdutos; i++) {
        printf("%-10d\t%-25s%-10d\t%-10.2f\n\n",produtos[i].codigo,produtos[i].nome,
        produtos[i].quantidade,produtos[i].preco);

        
    }
}

void entradaProduto() {

    int codigo;
    int quantidade;

    printf("\nCodigo do produto: ");
    scanf("%d", &codigo);
    limparBuffer();

    for(int i = 0; i < totalProdutos; i++) {

        if(produtos[i].codigo == codigo) {

            printf("Quantidade entrada: ");
            scanf("%d", &quantidade);
            limparBuffer();

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
    limparBuffer();

    for(int i = 0; i < totalProdutos; i++) {

        if(produtos[i].codigo == codigo) {
            printf("Quantidade retirada: ");
            scanf("%d", &quantidade);
            limparBuffer();

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
    limparBuffer();

    for(int i = 0; i < totalProdutos; i++) {

        if(produtos[i].codigo == codigo) {

            encontrado = 1;

            for(int j = i; j < totalProdutos - 1; j++) {

                produtos[j] = produtos[j + 1];
            }

            totalProdutos--;
            salvarDados();
            printf("\nProduto removido com sucesso!\n");

            break;
        }
    }

    if(!encontrado) {

        printf("\nProduto nao encontrado!\n");
    }
}