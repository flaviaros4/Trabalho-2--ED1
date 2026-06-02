#include <stdio.h>
#include "clientes.h"
#include "filas.h"
#include "atendimento.h"

int main()
{
    int opcao;

    Estatisticas estatisticas;
    inicializarEstatisticas(&estatisticas);

    do
    {
        printf("\n===== SUPERMERCADO =====\n");
        printf("1 - Cadastrar cliente\n");
        printf("2 - Inserir cliente na fila\n");
        printf("3 - Realizar atendimento\n");
        printf("4 - Exibir filas\n");
        printf("5 - Exibir clientes atendidos\n");
        printf("6 - Exibir estatisticas\n");
        printf("0 - Sair\n");

        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                printf("Cadastrar cliente\n");
                break;

            case 2:
                printf("Inserir na fila\n");
                break;

            case 3:
                printf("Atender cliente\n");
                break;

            case 4:
                printf("Exibir filas\n");
                break;

            case 5:
                listarAtendidos();
                break;

            case 6:
                exibirEstatisticas(estatisticas);
                break;

            case 0:
                printf("Encerrando sistema...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}