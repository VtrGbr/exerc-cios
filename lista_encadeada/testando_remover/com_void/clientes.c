#include "clientes.h"


//Funcao para inicializar uma lista
Lista* iniciar_lista(){
    return NULL;
}

//Adicionar na lista
Lista* add(Lista* head, void* item){
    //Criacao do noh
    Lista* noh = (Lista*)malloc(sizeof(Lista));

    //verificacao de seguranca
    if( noh != NULL){
        noh->item = item;
        noh->prox = head;

        return noh;
    }else{
        printf("Erro na alocacao do noh, na funcao add");
        return  NULL;
    }
}

/*
Funcoes para cada tipo de estrutura (passageiros, estudantes, string e inteiros)
*/

//Funcao para comparar se um inteiro eh igual ao outro
int inteiro_igual(void* item1, void* item2){
    return *((int*) item1) == *((int*) item2);
}

//Funcao para comparar se uma string eh igual a outra
int string_igual(void* item1, void* item2){
    return strcmp((char*)item1, (char*)item2) == 0;
}

//Funcao para comparar se um passageiro eh igual ao outro
int passageiros_iguais(void* item1, void* item2){
    Passageiros* p1 = (Passageiros*)item1;
    Passageiros* p2 = (Passageiros*)item2;
    return (strcmp(p1->nome, p2->nome) == 0 && p1->cpf == p2->cpf && p1->acento == p2->acento);
}

int estudantes_iguais(void* item1, void* item2){
    Estudantes* e1 = (Estudantes*)item1;
    Estudantes* e2 = (Estudantes*)item2;
    return (strcmp(e1->nome, e2->nome) == 0 && e1->cpf == e2->cpf && e1->media_final == e2->media_final);
}

Lista* search(Lista* head, void* item, int (*equal)(void*,void*)){
    while(head !=NULL){
        if((*equal)(head->item,item)){
            return head;
        }

        head = head->prox;
    }

    return NULL;
}

//Remocao de item de uma lista
Lista* remocao(Lista* head, void* valor, int (*equal)(void*, void*)) {
    Lista* anterior = NULL;
    Lista* atual = head;

    while (atual != NULL && !(*equal)(atual->item, valor)) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        return head; // Item nao encontrado
    }

    if (anterior == NULL) {
        head = atual->prox; // Remove o primeiro elemento
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);
    return head;
}


//Imprimindo a lista de strings
void imprimir_string(Lista* list){
    while(list != NULL){
        printf("%s -> ",(char*)list->item);

        list = list->prox;
    }
    printf("NULL");
}

//Imprimindo a lista de inteiros
void imprimir_inteiro(Lista* list){
    while(list != NULL){
        printf("%d -> ",*((int*)list->item));

        list = list->prox;
    }
    printf("NULL");
}
// Imprimindo lista de passageiros
void imprimir_passageiro(Lista* list) {
    while (list != NULL) {
        Passageiros* p = (Passageiros*)list->item;
        printf("%s (CPF: %d, Acento: %d) -> ", p->nome, p->cpf, p->acento);
        list = list->prox;
    }
    printf("NULL\n");
}
// Imprimindo lista de estudantes
void imprimir_estudante(Lista* list) {
    while (list != NULL) {
        Estudantes* e = (Estudantes*)list->item;
        printf("%s (CPF: %d, Media: %.2f) -> ", e->nome, e->cpf, e->media_final);
        list = list->prox;
    }
    printf("NULL\n");
}

// Função genérica para imprimir elementos da lista
void imprimir_lista(Lista* list, ImprimirFunc imprimir) {
    if (imprimir) {
        (*imprimir)(list); // Chama a função de impressão específica
    } else {
        printf("Nenhuma função de impressão fornecida!\n");
    }
}

/*
Funcoes para adicionar os valores de cada estrutura
*/

//Liberar listas
void liberar(Lista* list){
    // Libera a memória da lista ao final do programa
    while (list != NULL) {
        Lista* temp = list;
        list = list->prox;
        free(temp->item);
        free(temp);
    }
}