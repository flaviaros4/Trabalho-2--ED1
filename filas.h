#ifndef FILAS_H
#define FILAS_H

#include "clientes.h"

typedef struct No {
    Cliente cliente;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
    No *fim;
    int tamanho;
} Fila;

void inicializarFila(Fila *fila);
int filaVazia(Fila *fila);
void enfileirar(Fila *fila, Cliente cliente);
Cliente desenfileirar(Fila *fila);
void exibirFila(Fila *fila, const char *nomeFila);
void liberarFila(Fila *fila);

#endif