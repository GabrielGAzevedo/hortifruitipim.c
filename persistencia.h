#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H
#include "cadastro.h"
#include "fornecedores.h"



void salvarProdutosEmArquivo(Produto produtos[], int contador);
void carregarProdutosDeArquivo(Produto produtos[], int *contador);

void salvarFornecedoresEmArquivo(Fornecedor fornecedores[], int contador);
void carregarFornecedoresDeArquivo(Fornecedor fornecedores[], int *contador);

#endif

