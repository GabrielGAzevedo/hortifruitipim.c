#ifndef CADASTRO_H
#define CADASTRO_H

typedef struct {
    int id;
    char nome[50];
    float preco;
    int quantidade;
} Produto;

void menuCadastro(Produto produtos[], int *contadorCadastro);
void listarProdutos(Produto produtos[], int contadorCadastro);

#endif

