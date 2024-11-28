#include <stdio.h>
#include "caixa.h"

void menuCaixa(Produto produtos[], int contadorCadastro) {
    Produto carrinho[100];
    int contCarrinho = 0;
    int id, quantidade;

    do {
        printf("\n--- Menu de Caixa ---\n");
        printf("1. Adicionar Produto ao Carrinho\n");
        printf("2. Exibir Recibo\n");
        printf("0. Voltar\n");
        printf("Digite sua escolha: ");
        scanf("%d", &quantidade);

        switch (quantidade) {
            case 1:
                printf("Digite o ID do produto: ");
                scanf("%d", &id);

                Produto *produtoSelecionado = NULL;
                for (int i = 0; i < contadorCadastro; i++) {
                    if (produtos[i].id == id) {
                        produtoSelecionado = &produtos[i];
                        break;
                    }
                }

                if (produtoSelecionado == NULL) {
                    printf("\nProduto não encontrado.\n");
                    break;
                }

                printf("Digite a quantidade: ");
                scanf("%d", &quantidade);

                adicionarAoCarrinho(carrinho, &contCarrinho, *produtoSelecionado, quantidade);
                produtoSelecionado->quantidade -= quantidade;
                break;

            case 2:
                exibirRecibo(carrinho, contCarrinho);
                break;

            case 0:
                printf("\nVoltando ao menu principal...\n");
                break;

            default:
                printf("\nOpção inválida! Tente novamente.\n");
                break;
        }
    } while (quantidade != 0);
}

void adicionarAoCarrinho(Produto carrinho[], int *contCarrinho, Produto produto, int quantidade) {
    carrinho[*contCarrinho] = produto;
    carrinho[*contCarrinho].quantidade = quantidade;
    (*contCarrinho)++;
}

void exibirRecibo(Produto carrinho[], int contCarrinho) {
    float total = 0;
    printf("\n--- Recibo ---\n");
    for (int i = 0; i < contCarrinho; i++) {
        printf("Produto: %s | Quantidade: %d | Preco: R$%.2f\n",
            carrinho[i].nome, carrinho[i].quantidade, carrinho[i].preco);
        total += carrinho[i].preco * carrinho[i].quantidade;
    }
    printf("\nTotal: R$%.2f\n", total);
}

