#ifndef lista_h
#define lista_h

#include <stdio.h>
#include <stdlib.h>
typedef struct lista{
    int numero;
    struct lista* prox;
}Lista;

Lista* criar_lista();

//Ver se a lista estah vazia
int vazia(Lista* head);
//Ver se a lista estah vazia
int vazia(Lista* head);

//Funcao para adicionar na lista
Lista* add(Lista* head, int valor);

//Funcao para buscar um item na lista
Lista* search(Lista* head, int valor);

//Remocao de item de uma lista
Lista* remocao(Lista* head, int valor);

//Imprimindo a lista
void imprimir(Lista* list);

void adicionar_numeros(Lista* lista, int qtd);

#endif