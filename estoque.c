#include <stdio.h>
#include "estoque.h"

void menuEstoque(Produto produtos[], int contadorCadastro) {
    int escolha;

    do {
        printf("\n--- Menu de Estoque ---\n");
        printf("1. Ajustar Quantidade de Produto\n");
        printf("2. Listar Produtos\n");
        printf("0. Voltar\n");
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                ajustarEstoque(produtos, contadorCadastro);
                break;
            case 2:
                listarProdutos(produtos, contadorCadastro);
                break;
            case 0:
                printf("\nVoltando ao menu principal...\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
                break;
        }
    } while (escolha != 0);
}

void ajustarEstoque(Produto produtos[], int contadorCadastro) {
    int id, quantidade;

    printf("Digite o ID do produto para ajustar: ");
    scanf("%d", &id);

    for (int i = 0; i < contadorCadastro; i++) {
        if (produtos[i].id == id) {
            printf("Quantidade atual: %d\n", produtos[i].quantidade);
            printf("Digite a quantidade a ser ajustada: ");
            scanf("%d", &quantidade);

            produtos[i].quantidade += quantidade;
            printf("Estoque atualizado! Nova quantidade: %d\n", produtos[i].quantidade);
            return;
        }
    }

    printf("\nProduto nao encontrado.\n");
}

