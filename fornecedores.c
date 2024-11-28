#include <stdio.h>
#include <string.h>
#include "fornecedores.h"

void menuFornecedores(Fornecedor fornecedores[], int *contadorFornecedores) {
    int escolha;

    do {
        printf("\n--- Menu de Fornecedores ---\n");
        printf("1. Adicionar Fornecedor\n");
        printf("2. Listar Fornecedores\n");
        printf("0. Voltar\n");
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1: {
                Fornecedor novoFornecedor;
                novoFornecedor.id = *contadorFornecedores + 1;

                printf("\nDigite o nome do fornecedor: ");
                scanf(" %[^\n]s", novoFornecedor.nome);
                printf("Digite o endereco do fornecedor: ");
                scanf(" %[^\n]s", novoFornecedor.endereco);
                printf("Digite o telefone do fornecedor: ");
                scanf(" %[^\n]s", novoFornecedor.telefone);

                fornecedores[*contadorFornecedores] = novoFornecedor;
                (*contadorFornecedores)++;

                printf("\nFornecedor cadastrado com sucesso!\n");
                break;
            }
            case 2:
                listarFornecedores(fornecedores, *contadorFornecedores);
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

void listarFornecedores(Fornecedor fornecedores[], int contadorFornecedores) {
    printf("\n--- Lista de Fornecedores ---\n");
    for (int i = 0; i < contadorFornecedores; i++) {
        printf("ID: %d\n", fornecedores[i].id);
        printf("Nome: %s\n", fornecedores[i].nome);
        printf("Endereco: %s\n", fornecedores[i].endereco);
        printf("Telefone: %s\n", fornecedores[i].telefone);
        printf("---------------------------\n");
    }
}

