#include <stdio.h>

#include "../includes/estoque.h"
#include "../includes/arquivo.h"

void menuPrincipal() {

    int opcao;

    do {

        printf("\n===== STOCKPRO =====\n");

        printf("1 - Cadastrar Produto\n");
        printf("2 - Listar Produtos\n");
        printf("3 - Entrada Produto\n");
        printf("4 - Saida Produto\n");
        printf("5 - Apagar Produto\n");
        printf("6 - Salvar Dados\n");
        printf("0 - Sair\n");

        printf("Escolha: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch(opcao) {

            case 1:
                cadastrarProduto();
                break;

            case 2:
                listarProdutos();
                break;

            case 3:
                entradaProduto();
                break;

            case 4:
                saidaProduto();
                break;

            case 5:
                apagarProduto();
                break;

            case 6:
                salvarDados();
                break;

            case 0:
                salvarDados();
                printf("\nEncerrando sistema...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while(opcao != 0);
}