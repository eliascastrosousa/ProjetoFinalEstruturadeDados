#include <stdio.h>
#include <stdlib.h>
#include "listaLigada.h"
#include <locale.h>

int main(){
    setlocale(LC_ALL,"portuguese");

    Lista *li;
    int x, menu, m, identificador, opcEdit;
    li = criaLista(); //memoria alocada

    FILE *fp = fopen("arquivo.txt", "wb");
    if (fp == NULL){
        printf("Erro na abertura!\n");
        system("pause");
        exit(1);
    }
     struct funcionario dados_func;

    printf("\n\t\t\t\t Bem vindo as Industrias Acme!\n\n");

    do {
            m = menuLista();
            switch (m){
                case 1: //[1] Adicionar funcion�rio
                    printf("\nSelecionado: Adicionar funcion�rio!\n");
                    dados_func = entraDados();
                    x = insere_lista_ordenada(li,dados_func );
                    if(x){
                        printf("\nInserido de forma ordenada com sucesso!\n\n");
                    }else{
                        printf("\nN�o foi possivel inserir o Funcionario!\n");
                    }
                    break;

                case 2 : //[2] Excluir funcion�rio

                    printf("\nSelecionado: Remover funcion�rio!\n");
                    printf("Digite o id do Funcionario que deseja Remover: ");
                    scanf("%d", &identificador);

                    //mostrar o funcionario


                    x =  remove_lista(li,identificador);
                    if(x){
                        printf("\nFuncionario Removido com sucesso!\n\n");
                    }else{
                        printf("\nN�o foi possivel Remover o Funcionario!\n");
                    }
                    break;


                case 3: //[3] Editar funcion�rio

                    printf("\nSelecionado: Editar funcion�rio!\n");
                    printf("Digite o ID do Funcion�rio que deseja editar: ");
                    scanf("%d", &identificador);

                    printf("\nDeseja alterar: \n[1] Nome  \n[2] Endere�o \n[3] Idade  \n[4] Sal�rio (Disssidio Salarial)  \n[5] Cargo  \nDigite o numero: ");
                    scanf("%d", &opcEdit);
                    /*
                     switch (opcEdit){
                        case 1:
                            printf("\nSelecionado: Nome\n");
                            dados_func = entraDados();
                            x = insere_lista_ordenada(li,dados_func );
                            if(x){
                                printf("\nInserido de forma ordenada com sucesso!\n\n");
                            }else{
                                printf("\nN�o foi possivel inserir o Funcionario!\n");
                            }
                            break;

                        case 2 :


                    break;

                    */
                case 4:  //[4] Buscar funcion�rio por ID
                    printf("Digite o ID do funcionario: ");
                    scanf("%d", &identificador);

                    x = consulta_lista_id(li, identificador, &dados_func);
                    printf("\nID: %d",  dados_func.id);
                    printf("\nNome: %s",  dados_func.nome);
                    printf("\nEndere�o: %s",  dados_func.endereco);
                    printf("\nIdade: %d",  dados_func.idade);
                    printf("\nSal�rio: %f",  dados_func.salario);
                    printf("\nCargo: %s",  dados_func.cargo);

                    break;


                case 5:  //[5] Exibir funcion�rio ordenados por ID
                    printf("");
                    break;


                case 6: //[6] Exibir uma lista de funcion�rios por faixa salarial.
                    printf("");
                    break;

                case 7: //Mostrar qtd de funcionarios
                    printf("\nSelecionado: Mostrar qtd de funcionarios! \n");
                    x = tamLista(li);
                    printf("\nO tamanho da lista �: %d\n\n",x);
                    break;

                default:
                    printf("Op��o invalida\n");
            }
            }while(m != 0);

            printf("\n\nSalvando arquivos...\n\n");
            //fwrite(cand, sizeof(Candidato), n, fp);
            fclose(fp);
            apagaLista(li);
            printf("Limpando dados da sess�o...\nObrigado.\n\n");
            system("pause");
    }


