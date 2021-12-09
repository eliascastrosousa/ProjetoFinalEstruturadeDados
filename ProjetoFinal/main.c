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
                case 1: //[1] Adicionar funcionário
                    printf("\nSelecionado: Adicionar funcionário!\n");
                    dados_func = entraDados();
                    x = insere_lista_ordenada(li,dados_func );
                    if(x){
                        printf("\nInserido de forma ordenada com sucesso!\n\n");
                    }else{
                        printf("\nNão foi possivel inserir o Funcionario!\n");
                    }
                    break;

                case 2 : //[2] Excluir funcionário

                    printf("\nSelecionado: Remover funcionário!\n");
                    printf("Digite o id do Funcionario que deseja Remover: ");
                    scanf("%d", &identificador);

                    //mostrar o funcionario


                    x =  remove_lista(li,identificador);
                    if(x){
                        printf("\nFuncionario Removido com sucesso!\n\n");
                    }else{
                        printf("\nNão foi possivel Remover o Funcionario!\n");
                    }
                    break;


                case 3: //[3] Editar funcionário

                    printf("\nSelecionado: Editar funcionário!\n");
                    printf("Digite o ID do Funcionário que deseja editar: ");
                    scanf("%d", &identificador);

                    printf("\nDeseja alterar: \n[1] Nome  \n[2] Endereço \n[3] Idade  \n[4] Salário (Disssidio Salarial)  \n[5] Cargo  \nDigite o numero: ");
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
                                printf("\nNão foi possivel inserir o Funcionario!\n");
                            }
                            break;

                        case 2 :


                    break;

                    */
                case 4:  //[4] Buscar funcionário por ID
                    printf("Digite o ID do funcionario: ");
                    scanf("%d", &identificador);

                    x = consulta_lista_id(li, identificador, &dados_func);
                    printf("\nID: %d",  dados_func.id);
                    printf("\nNome: %s",  dados_func.nome);
                    printf("\nEndereço: %s",  dados_func.endereco);
                    printf("\nIdade: %d",  dados_func.idade);
                    printf("\nSalário: %f",  dados_func.salario);
                    printf("\nCargo: %s",  dados_func.cargo);

                    break;


                case 5:  //[5] Exibir funcionário ordenados por ID
                    printf("");
                    break;


                case 6: //[6] Exibir uma lista de funcionários por faixa salarial.
                    printf("");
                    break;

                case 7: //Mostrar qtd de funcionarios
                    printf("\nSelecionado: Mostrar qtd de funcionarios! \n");
                    x = tamLista(li);
                    printf("\nO tamanho da lista é: %d\n\n",x);
                    break;

                default:
                    printf("Opção invalida\n");
            }
            }while(m != 0);

            printf("\n\nSalvando arquivos...\n\n");
            //fwrite(cand, sizeof(Candidato), n, fp);
            fclose(fp);
            apagaLista(li);
            printf("Limpando dados da sessão...\nObrigado.\n\n");
            system("pause");
    }


