# Trabalho-2--ED1
# Simulador de Caixa de Supermercado com Atendimento Preferencial

## Descrição do Sistema
Este projeto é uma aplicação em C desenvolvida para simular o atendimento em caixas de supermercado. O sistema utiliza estruturas de filas simples e com prioridade para gerenciar clientes comuns e aqueles com prioridade legal (idosos, gestantes, PCD).A lógica principal de atendimento alterna entre as filas (ex: a cada 2 clientes comuns, atende-se 1 preferencial). 

## Vídeo de Demonstração

A demonstração completa da execução do sistema pode ser acessada pelo link abaixo:

**Vídeo:** https://youtu.be/UBjeva2ESPo

O vídeo apresenta todas as funcionalidades implementadas, incluindo:

* Cadastro de clientes;
* Inserção nas filas comum e preferencial;
* Atendimento com alternância entre filas;
* Exibição das filas;
* Listagem de clientes atendidos;
* Geração das estatísticas finais.
  
## Como Compilar e Executar
Para compilar o código fonte e executar o simulador via console, certifique-se de ter o compilador GCC instalado e rode os seguintes comandos no terminal:

```bash
# Compilação
gcc main.c clientes.c filas.c atendimento.c -o simulador_supermercado

# Execução
./simulador_supermercado


