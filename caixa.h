#ifndef CAIXA_H
#define CAIXA_H

#include "cadastro.h"

void menuCaixa(Produto produtos[], int contadorCadastro);
void adicionarAoCarrinho(Produto carrinho[], int *contCarrinho, Produto produto, int quantidade);
void exibirRecibo(Produto carrinho[], int contCarrinho);

#endif

