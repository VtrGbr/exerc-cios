#include "clientes.h"

int main(){
    Lista* list_passageiros = iniciar_lista();
    Lista* list_estudantes = iniciar_lista();
    Lista* list_inteiros = iniciar_lista();
    Lista* list_string = iniciar_lista();

    int opcao, sub_opcao;

    do
    {
        printf("\nDigite a opcao desejada:\n1 - Adicionar na lista;\n2-Remover da lista;\n3-Buscar na lista;\n4-Imprimir a lista;\n5-Encerrar programa;\n");
        scanf("%d",&opcao);
        if( opcao >= 1 && opcao <= 4){
            printf("\nEscolha qual a lista voce quer usar\n1 - Lista de inteiros:\n2 - Lista de Strings:\n3 - Lista Passageiros:\n4 - Lista de estudantes:\n");
            scanf("%d",&sub_opcao);
        }
        switch (opcao)
        {
        case 1: // Adicionar
            if( sub_opcao == 1){

                printf("Digite um numero a ser adicionado na lista: \n");
                int* valor = (int*)malloc(sizeof(int));

                if( valor == NULL){
                    printf("Erro na alocacao da variavel valor, na main\n");
                    return 1;
                }
                scanf("%d",valor);
                list_inteiros = add(list_inteiros,valor);
                printf("Numero %d adicionado com sucesso!\n",*valor);
            }else if( sub_opcao == 2){
                printf("Digite uma string a ser adicionado na lista: \n");
                char* valor = (char*)malloc(50 * sizeof(char));
                scanf("%s",valor);
                list_string = add(list_string,valor);
                printf("String '%s' adicionada com sucesso!\n", valor);
            }else if( sub_opcao == 3){
                Passageiros* pass = (Passageiros*)malloc(sizeof(Passageiros));
                printf("Digite o nome do passageiro: \n");
                scanf("%s",pass->nome);
                printf("Digite o cpf do passageiro: \n");
                scanf("%d",&pass->cpf);
                printf("Digite o numero do acento do passageiro: \n");
                scanf("%d",&pass->acento);
                list_passageiros = add(list_passageiros,pass);

                printf("Passageiro %s adicionado com sucesso!",pass->nome);
            }else if(sub_opcao == 4){
                Estudantes* est = (Estudantes*)malloc(sizeof(Estudantes));
                printf("Digite o nome do estudante: \n");
                scanf("%s",est->nome);
                printf("Digite o cpf do estudante: \n");
                scanf("%d",&est->cpf);
                printf("Digite a media final do estudante: \n");
                scanf("%lf",&est->media_final);
                list_estudantes = add(list_estudantes,est);

                printf("Estudante %s adicionado com sucesso!",est->nome);
            }
            break;
        case 2: // Remover
            if(sub_opcao == 1){ // Inteiro
                int valor;
                printf("Digite um numero a ser removido da lista: \n");
                scanf("%d",&valor);
                list_inteiros = remocao(list_inteiros,&valor,inteiro_igual);
            }else if( sub_opcao == 2){ //String
                char valor[50];
                printf("Digite a string a ser removida: ");
                scanf("%s", valor);
                list_string = remocao(list_string, valor, string_igual);
            }else if( sub_opcao == 3){
                Passageiros pass;
                printf("Digite o nome do passageiro a ser removido: ");
                scanf("%s", pass.nome);
                list_passageiros = remocao(list_passageiros, &pass, passageiros_iguais);
            }else if( sub_opcao == 4){
                Estudantes est;
                printf("Digite o nome do estudante a ser removido: ");
                scanf("%s", est.nome);
                list_estudantes = remocao(list_estudantes, &est, estudantes_iguais);
            }
            
            break;

        case 3: //Buscar
            if( sub_opcao == 1){
                int valor;
                printf("Digite o numero a ser buscado: ");
                scanf("%d", &valor);
                Lista* busca = search(list_inteiros, &valor, inteiro_igual);
                printf(busca ? "Numero encontrado!\n" : "Numero nao encontrado!\n");
            }else if( sub_opcao == 2){
                char valor[50];
                printf("Digite a string a ser buscada: ");
                scanf("%s", valor);
                Lista* busca = search(list_string, valor, string_igual);
                printf(busca ? "String encontrada!\n" : "String nao encontrada!\n");
            }else if( sub_opcao == 3){
                Passageiros pass;
                printf("Digite o nome do passageiro a ser buscado: ");
                scanf("%s", pass.nome);
                Lista* busca = search(list_passageiros, &pass, passageiros_iguais);
                printf(busca ? "Passageiro encontrado!\n" : "Passageiro nao encontrado!\n");
            }else if( sub_opcao == 4){
                Estudantes est;
                printf("Digite o nome do estudante a ser buscado: ");
                scanf("%s", est.nome);
                Lista* busca = search(list_estudantes, &est, estudantes_iguais);
                printf(busca ? "Estudante encontrado!\n" : "Estudante nao encontrado!\n");
            }
            
            break;
        case 4: // Imprimir
            if(sub_opcao == 1){
                printf("Lista de inteiros:\n");
                imprimir_lista(list_inteiros,imprimir_inteiro);
            }else if( sub_opcao == 2){
                printf("Lista de Strings:\n");
                imprimir_lista(list_string,imprimir_string);
            }else if( sub_opcao == 3){
                printf("Lista de Passageiros:\n");
                imprimir_lista(list_passageiros,imprimir_passageiro);
            }else if( sub_opcao == 4){
                printf("Lista de Estudante:\n");
                imprimir_lista(list_estudantes,imprimir_estudante);
            }
            
            break;
        case 5:
            printf("Encerrando programa...\n");
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    } while (opcao != 5);
    
    
    //Liberacao de memoria
    liberar(list_inteiros);
    liberar(list_string);
    liberar(list_passageiros);
    liberar(list_estudantes);
    return 0;
}