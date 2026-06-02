#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"


Cliente* cadastrar_cliente() {
    Cliente *novo_cliente = (Cliente*) malloc(sizeof(Cliente));
    
    if (novo_cliente == NULL) {
        printf("Erro de alocação de memória!\n");
        return NULL;
    }

    printf("\n--- Cadastro de Cliente ---\n");
    printf("Nome do cliente: ");
    scanf(" %49[^\n]", novo_cliente->nome);

    printf("Tipo de atendimento (0 - Comum, 1 - Preferencial): ");
    scanf("%d", &novo_cliente->tipo);

    // Validação simples para garantir que o tipo seja 0 ou 1
    while(novo_cliente->tipo != 0 && novo_cliente->tipo != 1) {
        printf("Tipo inválido. Digite 0 para Comum ou 1 para Preferencial: ");
        scanf("%d", &novo_cliente->tipo);
    }

    printf("Quantidade de itens: ");
    scanf("%d", &novo_cliente->qtd_itens);

    printf("Cliente %s cadastrado com sucesso!\n", novo_cliente->nome);
    return novo_cliente;
}