#include <stdio.h>
#include <stdlib.h>

#include "clientes.h"
#include "filas.h"
#include "atendimento.h"

int main()
{
    int opcao;

    Estatisticas estatisticas;
    inicializarEstatisticas(&estatisticas);

    Fila filaComum;
    Fila filaPreferencial;

    inicializarFila(&filaComum);
    inicializarFila(&filaPreferencial);

    Cliente *clienteCadastrado = NULL;

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
            {
                if (clienteCadastrado != NULL)
                {
                    free(clienteCadastrado);
                }

                clienteCadastrado = cadastrar_cliente();
                break;
            }

            case 2:
            {
                if (clienteCadastrado == NULL)
                {
                    printf("Nenhum cliente cadastrado.\n");
                    break;
                }

                if (clienteCadastrado->tipo == 0)
                {
                    enfileirar(&filaComum, *clienteCadastrado);
                    printf("Cliente inserido na fila comum.\n");
                }
                else
                {
                    enfileirar(&filaPreferencial, *clienteCadastrado);
                    printf("Cliente inserido na fila preferencial.\n");
                }

                free(clienteCadastrado);
                clienteCadastrado = NULL;

                break;
            }

            case 3:
            {
                atenderProximo(
                    &filaComum,
                    &filaPreferencial,
                    &estatisticas
                );
                break;
            }

            case 4:
            {
                exibirFila(&filaComum, "FILA COMUM");
                exibirFila(&filaPreferencial, "FILA PREFERENCIAL");
                break;
            }

            case 5:
            {
                listarAtendidos();
                break;
            }

            case 6:
            {
                exibirEstatisticas(estatisticas);
                break;
            }

            case 0:
            {
                printf("Encerrando sistema...\n");
                break;
            }

            default:
            {
                printf("Opcao invalida!\n");
            }
        }

    } while(opcao != 0);

    liberarFila(&filaComum);
    liberarFila(&filaPreferencial);

    if (clienteCadastrado != NULL)
    {
        free(clienteCadastrado);
    }

    return 0;
}
