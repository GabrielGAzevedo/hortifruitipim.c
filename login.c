#include <stdio.h>
#include <string.h>
#include "login.h"

#define USUARIO_CORRETO "Rogerio"
#define SENHA_CORRETA "unip123"
#define MAX_TENTATIVAS 3

int fazerLogin(char usuario[], char senha[]) {
    int tentativas = 0;

    while (tentativas < MAX_TENTATIVAS) {
        printf("Usuario: ");
        scanf("%s", usuario);

        printf("Senha: ");
        scanf("%s", senha);

        if (strcmp(usuario, USUARIO_CORRETO) == 0 && strcmp(senha, SENHA_CORRETA) == 0) {
            return 0;
        } else {
            printf("Usuario ou senha incorretos. Tente novamente.\n");
            tentativas++;
        }
    }

    printf("Limite de tentativas alcançado.\n");
    return 1;
}
