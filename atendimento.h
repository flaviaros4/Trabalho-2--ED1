#ifndef ATENDIMENTO_H
#define ATENDIMENTO_H

#include "clientes.h"
#include "filas.h"

#define MAX_ATENDIDOS 100

typedef struct
{
    Cliente cliente;
    int tempo_atendimento;

} Atendimento;

typedef struct
{
    int qtd_comum;
    int qtd_preferencial;

    int tempo_total_comum;
    int tempo_total_preferencial;

    int total_itens;

} Estatisticas;

void inicializarEstatisticas(Estatisticas *estatisticas);

int calcularTempo(Cliente cliente);

void registrarAtendimento(Cliente cliente,Estatisticas *estatisticas);

void adicionarAtendido(Cliente cliente);

void listarAtendidos();

void atenderProximo(Fila *filaComum,Fila *filaPreferencial,Estatisticas *estatisticas);

void exibirEstatisticas(Estatisticas estatisticas);

#endif