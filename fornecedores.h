#ifndef FORNECEDORES_H
#define FORNECEDORES_H

#define MAX_FORNECEDORES 100

typedef struct {
    int id;
    char nome[50];
    char endereco[100];
    char telefone[15];
} Fornecedor;

void menuFornecedores(Fornecedor fornecedores[], int *contadorFornecedores);
void listarFornecedores(Fornecedor fornecedores[], int contadorFornecedores);

#endif

