#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct fila{
    int numero;
    struct fila* prox;
}Fila;

Fila* criar_fila(){
    return NULL;
}


//Enfileirar
void enqueue( Fila** fila, int numero){
    Fila* queue = (Fila*)malloc(sizeof(Fila));
    Fila* aux;
    //Verificacao de seguranca
    if( queue != NULL){
        queue->numero = numero;
        queue->prox = NULL;

        //Se a fila estiver vazia
        if( *fila == NULL){
            *fila = queue;
        }else{
            aux = *fila;

            //Percorrer a fila
            while(aux->prox != NULL){
                aux = aux->prox;
            }

            aux->prox = queue;
        }
    }else{
        printf("Erro na alocacao da fila, funcao enqueue\n");
        return;
    }
}

//Desenfileirar
Fila* dequeue( Fila** fila){
    Fila* remover = NULL; // Noh que serah removido
    
    if( *fila != NULL){
        remover = *fila;
        *fila = remover->prox;
    }else{
        printf("Fila vazia!\n");
    }

    return remover;
}


//imprimir
void imprimir( Fila* fila){
    while (fila != NULL)
    {
        printf("%d ",fila->numero);
        fila = fila->prox;
    }
    printf("\n");
}


int main(){
    char opcao[15];
    int numero;
    Fila* fila = criar_fila();
    Fila* desenfileirado = criar_fila();
    

    do
    {
        printf("Digite a opcao desejada (Enfileirar, Desenfileirar, imprimir ou finalizar)\n");
        fgets(opcao,15,stdin);
        opcao[strcspn(opcao, "\n")] = '\0';

        if( strcmp(opcao,"Enfileirar") == 0){
            //Escanear um numero a ser inserido na fila
            scanf("%d",&numero);
            getchar();
            //Chamar a funcao para colocar na fila
            enqueue(&fila,numero);

           
        }else if( strcmp(opcao, "Desenfileirar") == 0){
            //Chamar funcao de desenfileirar
            desenfileirado = dequeue(&fila);
        }else if( strcmp(opcao, "Imprimir") == 0){
            //Funcao imprimir
            imprimir(fila);
        }
    } while (strcmp(opcao, "Finalizar") != 0);

    // Liberar memória restante da fila
    while (fila != NULL) {
        desenfileirado = dequeue(&fila);
        free(desenfileirado);
    }
    
    return 0;
}