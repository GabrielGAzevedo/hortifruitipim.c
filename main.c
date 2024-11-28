#include <stdio.h>
#include <string.h>
#include "cadastro.h"
#include "caixa.h"
#include "estoque.h"
#include "fornecedores.h"
#include "login.h"
#include "persistencia.h" // Adicionado

#define MAX_PRODUTOS 100
#define MAX_FORNECEDORES 100

int main() {
    Produto produtos[MAX_PRODUTOS];
    Fornecedor fornecedores[MAX_FORNECEDORES];
    int contadorProdutos = 0, contadorFornecedores = 0;

    char usuario[20], senha[20];
    int opcao, logado = 0;

    // Carregar dados do arquivo
    carregarProdutosDeArquivo(produtos, &contadorProdutos);
    carregarFornecedoresDeArquivo(fornecedores, &contadorFornecedores);

    // Realiza o login
    printf("Bem-vindo ao Sistema de Gerenciamento!\n");
    if (fazerLogin(usuario, senha) == 0) {
        logado = 1;
        printf("\nLogin bem-sucedido! Bem-vindo, %s.\n", usuario);
    } else {
        printf("\nFalha no login. Programa encerrado.\n");
        return 1;
    }

    if (logado) {
        do {
            printf("\n--- Menu Principal ---\n");
            printf("1. Cadastro de Produtos\n");
            printf("2. Modulo de Caixa\n");
            printf("3. Controle de Estoque\n");
            printf("4. Cadastro de Fornecedores\n");
            printf("0. Sair\n");
            printf("Digite sua escolha: ");
            scanf("%d", &opcao);

            switch (opcao) {
                case 1:
                    menuCadastro(produtos, &contadorProdutos);
                    break;
                case 2:
                    menuCaixa(produtos, contadorProdutos);
                    break;
                case 3:
                    menuEstoque(produtos, contadorProdutos);
                    break;
                case 4:
                    menuFornecedores(fornecedores, &contadorFornecedores);
                    break;
                case 0:
                    printf("\nSalvando os dados...\n");
                    salvarProdutosEmArquivo(produtos, contadorProdutos);
                    salvarFornecedoresEmArquivo(fornecedores, contadorFornecedores);
                    printf("Saindo do programa...\n");
                    break;
                default:
                    printf("\nOpção inválida! Tente novamente.\n");
                    break;
            }
        } while (opcao != 0);
    }

    return 0;
}
