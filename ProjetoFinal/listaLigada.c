#include <stdio.h>
#include <stdlib.h>
#include "listaLigada.h"

struct elemento{
    FUNCIONARIO dados;
    struct elemento *prox;
}; //CRIA��O DO PONTEIRO PROXIMO

typedef struct elemento ELEM;

Lista *criaLista(){
    Lista *li;
    li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        *li = NULL; //se aloca��o ok, preenche conteudo com null
    }
    return li;
}

void ArquivoBinario(FUNCIONARIO *funcionario){
    FILE *fp = fopen("arquivo.txt", "wb");
    if (fp == NULL){
        printf("Erro na abertura!\n");
        system("pause");
        exit(1);
    }

    fwrite(*funcionario, sizeof(FUNCIONARIO), fp);
    fclose(fp);
}

void apagaLista(Lista *li){ //passa o endere�o da inteira que se quer liberar
    if(li != NULL){   //Lista � valida se for diferente de NULL
        ELEM *no; //enquanto o primeiro elemento da lista fo direfente
        while((*li) != NULL){
            no = *li;                   //while: enquanto n�o estiver numa lista vazia, executa esse conjunto de instru��es, at� que a lista esteja vazia e apontando para nulo

            *li = (*li)->prox;   //inicio da lista aponta para o prox da lista
            free(no);
        }
        free(li); //ao final, libera a cabe�a da lista
    }
}

int menuLista(){
    int menu;
    printf("\n\t\t\t\t\t-------Menu-------\n\n");
    printf("[1] Adicionar funcion�rio \n[2] Excluir funcion�rio \n[3] Editar funcion�rio ");
    printf("\n[4] Buscar funcion�rio por ID \n[5] Exibir funcion�rio ordenados por ID ");
    printf("\n[6] Exibir a lista de funcion�rios por faixa salarial. \n[0] Sair da aplica��o.\nDigite: ");
    scanf("%d", &menu);
    return menu;
}

FUNCIONARIO entraDados(){
    FUNCIONARIO func;
        printf("------------------------------------------------------------\n\n");
        printf("Digite o ID: ");
        scanf("%d", &func.id);

        getchar();
        printf("Digite o Nome: ");
        fgets(func.nome, 49, stdin);

        printf("Digite o Endere�o: ");
        fgets(func.endereco, 49, stdin);

        printf("Digite a Idade: ");
        scanf("%d", &func.idade);

        getchar();
        printf("Digite o Cargo: ");
        fgets(func.cargo, 49, stdin);

        printf("Digite o Sal�rio: ");
        scanf("%f", &func.salario);

    return func;
}

int listaVazia(Lista *li){
    if(li == NULL){
        return 1;
    }
    if(*li == NULL){
        return 1;
    }
    return 0;
}

int tamLista(Lista *li){
    if(li==NULL){
        return 0;
    }
    int acum=0;
    ELEM *no = *li;
    while(no != NULL){
        acum++;
        no = no->prox;
    }
    return acum;
}


int insere_lista_ordenada(Lista *li, FUNCIONARIO dados_func){
    if(li == NULL){
        return 0;
    }
    ELEM *no = (ELEM*) malloc (sizeof(ELEM));
    if(no==NULL){
        return 0;
    }
    no->dados = dados_func;
    if(listaVazia(li)){
        no->prox = (*li);
        *li = no;
        return 1;
    }else{
        ELEM *ant, *atual = *li;
        while(atual != NULL && atual ->dados.id < dados_func.id){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){
                no->prox=(*li);
                    *li = no;
           }else{
                no->prox = ant->prox;
                ant->prox=no;
           }
           return 1;
    }
}

int remove_lista(Lista *li, int identificador){
    if(li == NULL){
        return 0;
    }
    ELEM *ant, *no = *li;
    while(no != NULL && no->dados.id != identificador){
        ant = no;
        no = no->prox;
    }
    if(no ==NULL){
        return 0;
    }
    if(no == *li){
        *li = no->prox;
    }else{
    ant->prox = no->prox;
    }
    free(no);
    return 1;
}

int consulta_lista_id(Lista *li, int identificador, FUNCIONARIO *dados_func){
    if(li == NULL){
        return 0;
    }
    ELEM *no = *li;
    while (no != NULL && no->dados.id != identificador){
        no = no->prox;
    }
    if(no ==NULL){
        return 0;
    }else{
        *dados_func = no->dados;
        return 1;
    }
}


int consulta_lista_pos(Lista *li, int posicao, FUNCIONARIO *dados_func){
    if(li == NULL || posicao <= 0){
        return 0;
    }
    ELEM *no = *li;
    int i=1;
    while (no != NULL && i < posicao){
        no = no->prox;
        i++;
    }
    if(no ==NULL){
        return 0;
    }else{
        *dados_func = no->dados;
        return 1;
    }
}

void imprimir_lista(Lista *li, FUNCIONARIO *dados_func){
    ELEM *no = *li;
    while(no != NULL){

        printf("\nID: %d", no->dados.id);
        printf("\nNome: %s",  no->dados.nome);
        printf("Cargo: %s",  no->dados.cargo);
        printf("Sal�rio: %0.2f\n----------------------\n", no->dados.salario);
        no = no->prox;
    }
}


