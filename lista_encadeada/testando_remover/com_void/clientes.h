#ifndef clientes_h
#define clientes_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct estudantes{
    char nome[10];
    int cpf;
    double media_final;  
}Estudantes;

typedef struct passageiros{
    char nome[10];
    int cpf;
    int acento;  
}Passageiros;
typedef struct letras{
    char nome[50];  
}Letras;
typedef struct numeros{
    int inteiro;  
}numeros;

typedef struct lista{
    void *item;
    struct lista* prox;;  
}Lista;
// Tipo de função para impressão
typedef void (*ImprimirFunc)(Lista*);
//Funcao para inicializar uma lista
Lista* iniciar_lista();

//Adicionar na lista
Lista* add(Lista* head, void* item);

/*
Funcoes para cada tipo de estrutura (passageiros, estudantes, string e inteiros)
*/

//Funcao para comparar se um inteiro eh igual ao outro
int inteiro_igual(void* item1, void* item2);

//Funcao para comparar se uma string eh igual a outra
int string_igual(void* item1, void* item2);

//Funcao para comparar se um passageiro eh igual ao outro
int passageiros_iguais(void* item1, void* item2);

int estudantes_iguais(void* item1, void* item2);

//Funcao de busca em uma lista
Lista* search(Lista* head, void* item, int (*equal)(void*,void*));

//Remocao de item de uma lista
Lista* remocao(Lista* head, void* valor, int (*equal)(void*,void*));

//Imprimindo a lista de strings
void imprimir_string(Lista* list);

//Imprimindo a lista de inteiros
void imprimir_inteiro(Lista* list);

// Imprimindo lista de passageiros
void imprimir_passageiro(Lista* list);

// Imprimindo lista de passageiros
void imprimir_estudante(Lista* list);

// Função genérica para imprimir elementos da lista
void imprimir_lista(Lista* list, ImprimirFunc imprimir);

//Liberar listas
void liberar(Lista* list);

#endif



