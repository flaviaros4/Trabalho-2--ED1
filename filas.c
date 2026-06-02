#include <stdio.h>
#include <stdlib.h>
#include "filas.h"

// inicializa uma fila vazia, sem início, fim ou clientes
void inicializarFila(Fila *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

// verifica se a fila está vazia
int filaVazia(Fila *fila) {
    return fila->inicio == NULL;
}

// insere um cliente no final da fila
void enfileirar(Fila *fila, Cliente cliente) {
    No *novo = malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        return;
    }

    novo->cliente = cliente;
    novo->proximo = NULL;

    if (filaVazia(fila)) {
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->proximo = novo;
        fila->fim = novo;
    }

    fila->tamanho++;
}

// remove e retorna o primeiro cliente da fila
Cliente desenfileirar(Fila *fila) {
    Cliente clienteVazio = {"", -1, 0};

    if (filaVazia(fila)) {
        printf("Fila vazia!\n");
        return clienteVazio;
    }

    No *remover = fila->inicio;
    Cliente cliente = remover->cliente;

    fila->inicio = fila->inicio->proximo;

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(remover);
    fila->tamanho--;

    return cliente;
}

// exibe todos os clientes atualmente presentes na fila
void exibirFila(Fila *fila, const char *nomeFila) {
    printf("\n=== %s ===\n", nomeFila);

    if (filaVazia(fila)) {
        printf("Fila vazia.\n");
        return;
    }

    No *atual = fila->inicio;
    int posicao = 1;

    while (atual != NULL) {
        printf(
            "%d. %s | %s | %d itens\n",
            posicao,
            atual->cliente.nome,
            atual->cliente.tipo == 0 ? "Comum" : "Preferencial",
            atual->cliente.qtd_itens
        );

        atual = atual->proximo;
        posicao++;
    }
}

// libera todos os nós alocados dinamicamente na fila
void liberarFila(Fila *fila) {
    while (!filaVazia(fila)) {
        desenfileirar(fila);
    }
}