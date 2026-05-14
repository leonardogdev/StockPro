#ifndef PRODUTO_H
#define PRODUTO_H

#define MAX_PRODUTOS 100

typedef struct {
    int codigo;
    char nome[50];
    int quantidade;
    float preco;
} Produto;

extern Produto produtos[MAX_PRODUTOS];
extern int totalProdutos;

#endif