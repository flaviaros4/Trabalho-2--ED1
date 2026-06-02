#ifndef CLIENTES_H
#define CLIENTES_H


typedef struct {
    char nome[50];
    int tipo; 
    int qtd_itens; 
} Cliente;


Cliente* cadastrar_cliente();

#endif
