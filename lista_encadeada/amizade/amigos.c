#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Estrutura dos amigos
typedef struct amigos{
    char nome[20];
    int idade;
}Amigos;

//Estrutura da lista encadeada
typedef struct lista{
    Amigos friend;
    struct lista * prox;
}Lista;

//Leitura dos amigos
void ler_amigos( Amigos* friend, int qtd)
{
    for( int i = 0; i < qtd; i++){
        //printf("Digite o nome e a idade [%d]\n", i + 1);
        scanf("%s %d",friend[i].nome,&friend[i].idade);
    }
}

//Funcao para adicionar na lista
Lista* add( Lista* list, Amigos amizade){
    //Alocando memoria
    Lista* lista = (Lista*)malloc(sizeof(Lista));

    //Verificacao de segueranca
    if( lista != NULL){
        lista->friend = amizade;
        lista->prox = list;

        return lista;
    }else{
        printf("Erro na alocacao da lista encadeada, na funcao add\n");
        return NULL;
    }
}

//Funcao para comparar se um numero eh igual ao outro
int comparar( int a, int b){
    return (a == b) ? 1: 0; // Se a for igual ao b,entao ele retorna 1, caso contrario retorna 0
}

//Funcao generica para comparar dois numeros
Lista* possui_amigos( Lista* list,Lista* lista2,int idade_comparativa, int *cont,int (*Funcao)(int,int)){
    

    while(list != NULL){
        if( Funcao(list->friend.idade,idade_comparativa) == 1){
            lista2 = add(lista2,list->friend);
            (*cont)++;
        }
        list = list->prox;
    }

    return lista2;
}

//Imprimir a lista
void imprimir( Lista* list){
    while(list != NULL){
        printf("%s ",list->friend.nome);
        list = list->prox;
    }
    printf("\n");
}

int main(){
    Lista* list = NULL;
    Lista* amigos_filtrados = NULL;

    int qtd_amigos, cont = 0, comparador;

    //printf("Digite a quantidade de amigos: ");
    scanf("%d",&qtd_amigos);

    if (qtd_amigos < 0) {
        printf("Numero invalido de amigos. Deve ser maior que 0.\n");
        return 1;
    }

    Amigos* amizade = (Amigos*)malloc(qtd_amigos * sizeof(Amigos));

    //Verificacao de seguranca
    if( amizade == NULL){
        printf("Erro na alocacao da amizade, na main");
        return 1;
    }

    ler_amigos(amizade,qtd_amigos);
    for( int i = 0; i < qtd_amigos; i++){
        list = add( list,amizade[i]);
    }

    //printf("Digite a idade comparativa: ");
    scanf("%d",&comparador);

    amigos_filtrados = possui_amigos(list,amigos_filtrados,comparador,&cont,comparar);
    
   // printf("contador: %d\n",cont);
    if( cont > 0){
        imprimir(amigos_filtrados);
    }else{
        printf("Eleven nao tem amigos com essa idade.");
    }

    //Liberar memoria
    while( list != NULL){
        Lista* aux = list;
        list = list->prox;

        free(aux);
    }
    while( amigos_filtrados != NULL){
        Lista* aux = amigos_filtrados;
        amigos_filtrados = amigos_filtrados->prox;

        free(aux);
    }
    
    //Liberando o vetor de amigos
    free(amizade);

    return 0;
}