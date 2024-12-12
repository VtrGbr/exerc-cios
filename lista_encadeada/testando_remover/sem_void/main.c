#include "lista.h"

int main(){
    Lista* list = criar_lista();
    Lista* busca = criar_lista();

    int qtd, opcao,valor;
/*
    printf("Digite a quantidade de numero que voce quer colocar na lista: \n");
    scanf("%d",&qtd);
*/
    //adicionar_numeros(list,qtd);
    
    do
    {
        printf("\nDigite a opcao desejada:\n1 - Adicionar na lista;\n2-Remover da lista;\n3-Buscar na lista;\n4-Imprimir a lista;\n5-Encerrar programa;\n");
        scanf("%d",&opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite um numero a ser adicionado na lista: \n");
            scanf("%d",&valor);
            list = add(list,valor);
            break;
        case 2:
            printf("Digite um numero a ser removido da lista: \n");
            scanf("%d",&valor);
            list = remocao(list,valor);
            break;

        case 3:
            printf("Digite um numero a ser procurado na lista: \n");
            scanf("%d",&valor);
            busca = search(list,valor);
            if( busca !=NULL){
                printf("\nNumero: %d, encontrado!\n",busca->numero);
            }else{
                printf("\nNumero nao encontrado!\n");
            }
            break;
        case 4:
            imprimir(list);
            break;
        
        default:
            printf("Opcao invalida!\n");
            break;
        }
    } while (opcao != 5);

    
    
    return 0;

}