#include <stdio.h>
#include <string.h>
#include "cadastro.h"
#include "fornecedores.h"


void salvarProdutosEmArquivo(Produto produtos[], int contador) {
    FILE *arquivo = fopen("produtos.dat", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de produtos para escrita.\n");
        return;
    }
    fwrite(&contador, sizeof(int), 1, arquivo);
    fwrite(produtos, sizeof(Produto), contador, arquivo);
    fclose(arquivo);
    printf("Produtos salvos com sucesso!\n");
}

void carregarProdutosDeArquivo(Produto produtos[], int *contador) {
    FILE *arquivo = fopen("produtos.dat", "rb");
    if (arquivo == NULL) {
        printf("Nenhum arquivo de produtos encontrado. Criando um novo.\n");
        return;
    }
    fread(contador, sizeof(int), 1, arquivo);
    fread(produtos, sizeof(Produto), *contador, arquivo);
    fclose(arquivo);
    printf("Produtos carregados com sucesso!\n");
}

void salvarFornecedoresEmArquivo(Fornecedor fornecedores[], int contador) {
    FILE *arquivo = fopen("fornecedores.dat", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de fornecedores para escrita.\n");
        return;
    }
    fwrite(&contador, sizeof(int), 1, arquivo);
    fwrite(fornecedores, sizeof(Fornecedor), contador, arquivo);
    fclose(arquivo);
    printf("Fornecedores salvos com sucesso!\n");
}

void carregarFornecedoresDeArquivo(Fornecedor fornecedores[], int *contador) {
    FILE *arquivo = fopen("fornecedores.dat", "rb");
    if (arquivo == NULL) {
        printf("Nenhum arquivo de fornecedores encontrado. Criando um novo.\n");
        return;
    }
    fread(contador, sizeof(int), 1, arquivo);
    fread(fornecedores, sizeof(Fornecedor), *contador, arquivo);
    fclose(arquivo);
    printf("Fornecedores carregados com sucesso!\n");
}
