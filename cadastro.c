#include <stdio.h>
#include <string.h>
#include "cadastro.h"

void menuCadastro(Produto produtos[], int *contadorCadastro) {
    int escolha;

    do {
        printf("\n--- Menu de Cadastro de Produtos ---\n");
        printf("1. Adicionar Produto\n");
        printf("2. Listar Produtos\n");
        printf("0. Voltar\n");
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1: {
                Produto novoProduto;
                novoProduto.id = *contadorCadastro + 1;

                printf("\nDigite o nome do produto: ");
                scanf(" %[^\n]s", novoProduto.nome);
                printf("Digite o preco do produto: R$");
                scanf("%f", &novoProduto.preco);
                printf("Digite a quantidade disponivel: ");
                scanf("%d", &novoProduto.quantidade);

                produtos[*contadorCadastro] = novoProduto;
                (*contadorCadastro)++;

                printf("\nProduto cadastrado com sucesso!\n");
                break;
            }
            case 2:
                listarProdutos(produtos, *contadorCadastro);
                break;
            case 0:
                printf("\nVoltando ao menu principal...\n");
                break;
            default:
                printf("\nOpção invalida! Tente novamente.\n");
                break;
        }
    } while (escolha != 0);
}

void listarProdutos(Produto produtos[], int contadorCadastro) {
    printf("\n--- Lista de Produtos ---\n");
    for (int i = 0; i < contadorCadastro; i++) {
        printf("ID: %d\n", produtos[i].id);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Preco: R$%.2f\n", produtos[i].preco);
        printf("Quantidade: %d\n", produtos[i].quantidade);
        printf("---------------------------\n");
    }
}

