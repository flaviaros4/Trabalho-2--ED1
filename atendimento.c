#include <stdio.h>
#include <string.h>
#include "atendimento.h"

Atendimento historico[MAX_ATENDIDOS];
int totalAtendidos = 0;

void inicializarEstatisticas(Estatisticas *estatisticas)
{
    estatisticas->qtd_comum = 0;
    estatisticas->qtd_preferencial = 0;

    estatisticas->tempo_total_comum = 0;
    estatisticas->tempo_total_preferencial = 0;

    estatisticas->total_itens = 0;
};

int calcularTempo(Cliente cliente)
{
    return cliente.qtd_itens * 2;
};

void registrarAtendimento(Cliente cliente, Estatisticas *estatisticas)
{
    int tempo = calcularTempo(cliente);

    estatisticas->total_itens += cliente.qtd_itens;

    if (cliente.tipo == 0)
    {
        estatisticas->qtd_comum++;
        estatisticas->tempo_total_comum += tempo;
    }
    else
    {
        estatisticas->qtd_preferencial++;
        estatisticas->tempo_total_preferencial += tempo;
    }
};

void adicionarAtendido(Cliente cliente)
{
    if (totalAtendidos >= MAX_ATENDIDOS)
    {
        printf("Limite de atendimentos atingido!\n");
        return;
    }

    historico[totalAtendidos].cliente = cliente;
    historico[totalAtendidos].tempo_atendimento =
        calcularTempo(cliente);

    totalAtendidos++;
};

void listarAtendidos()
{
    printf("\n=== CLIENTES ATENDIDOS ===\n");

    for (int i = 0; i < totalAtendidos; i++)
    {
        printf(
            "%d. %s | %s | %d itens | %d segundos\n",
            i + 1,
            historico[i].cliente.nome,
            historico[i].cliente.tipo == 0 ? "Comum" : "Preferencial",
            historico[i].cliente.qtd_itens,
            historico[i].tempo_atendimento);
    }
};

void atenderProximo(Fila *filaComum, Fila *filaPreferencial, Estatisticas *estatisticas) {
    static int comunsSeguidos = 0;
    Cliente cliente;

    if (filaVazia(filaComum) && filaVazia(filaPreferencial)) {
        printf("Nenhum cliente nas filas.\n");
        return;
    }

    if (!filaVazia(filaPreferencial) && comunsSeguidos >= 2) {
        cliente = desenfileirar(filaPreferencial);
        comunsSeguidos = 0;
    } else if (!filaVazia(filaComum)) {
        cliente = desenfileirar(filaComum);
        comunsSeguidos++;
    } else {
        cliente = desenfileirar(filaPreferencial);
        comunsSeguidos = 0;
    }

    printf(
        "Cliente atendido: %s | %s | %d itens | Tempo: %d segundos\n",
        cliente.nome,
        cliente.tipo == 0 ? "Comum" : "Preferencial",
        cliente.qtd_itens,
        calcularTempo(cliente)
    );

    registrarAtendimento(cliente, estatisticas);
    adicionarAtendido(cliente);
}

void exibirEstatisticas(Estatisticas estatisticas)
{
    printf("\n===== ESTATISTICAS =====\n");

    printf(
        "Clientes comuns atendidos: %d\n",
        estatisticas.qtd_comum);

    printf(
        "Clientes preferenciais atendidos: %d\n",
        estatisticas.qtd_preferencial);

    printf(
        "Total de itens processados: %d\n",
        estatisticas.total_itens);

    if (estatisticas.qtd_comum > 0)
    {
        printf(
            "Tempo medio comum: %.2f segundos\n",
            (float)estatisticas.tempo_total_comum /
                estatisticas.qtd_comum);
    }

    if (estatisticas.qtd_preferencial > 0)
    {
        printf(
            "Tempo medio preferencial: %.2f segundos\n",
            (float)estatisticas.tempo_total_preferencial /
                estatisticas.qtd_preferencial);
    }
};