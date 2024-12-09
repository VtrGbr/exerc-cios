#include "lista.h"

Lista* criar_lista(){
    return NULL;
}

//Ver se a lista estah vazia
int vazia(Lista* head){
    if( head){ // caso o noh cabeca seja diferente de null
        return 1;
    }else{
        return 0;
    }
}

//Funcao para adicionar na lista
Lista* add(Lista* head, int valor){
    //Alocacao de memoria para o noh
    Lista* noh = ( Lista*)malloc(sizeof(Lista*));

    //Verificacao de seguranca
    if( noh){
        noh->numero = valor;
        noh->prox = head;

        return noh;
    }else{
        printf("Erro na adicao do noh, funcao add");
        return NULL;
    }
}

//Funcao para buscar um item na lista
Lista* search(Lista* head, int valor){
    //Verificar se nao estah vazia
    while( head != NULL){
        if( head->numero == valor){
            return head;
        }
        //caso o valor ainda nao tenha sido achado, vah para o proximo
        head = head->prox;
    }

    return NULL; // Nao foi achado nenhum item com o valor especificado
}

//Remocao de item de uma lista
Lista* remocao(Lista* head, int valor){
    Lista* anterior = criar_lista();
    Lista* atual = head;

    while( atual  != NULL && atual->numero != valor){
        anterior = atual;
        atual = atual->prox;
    }

    if( atual == NULL){
        return head;
    }

    if( anterior == NULL){
        head = atual->prox;
    }else{
        anterior->prox = atual->prox;
    }

    free(atual);
    return head;
}

//Imprimindo a lista
void imprimir(Lista* list){
    while(list != NULL){
        printf("%d -> ",list->numero);
/*
        if( list->prox != NULL){
            printf(" ");
        }
*/
        list = list->prox;
    }
    printf("NULL");
}

void adicionar_numeros(Lista* lista, int qtd){
    int valor;

    for( int i = 0; i < qtd; i++){
        printf("Digite um numero: \n");
        scanf("%d",&valor);

        lista = add(lista,valor);
    }
}


