#ifndef PRODUTO_H 
#define PRODUTO_H

#define MAX_PRODUTOS 100 // cria uma palavra identificadora com o valor de 100 

typedef struct {
    int codigo;
    char nome[50];
    int quantidade;
    float preco;
} Produto;

extern Produto produtos[MAX_PRODUTOS]; // declaraçao global
extern int totalProdutos;

#endif