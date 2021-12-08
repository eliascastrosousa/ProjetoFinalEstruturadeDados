typedef struct funcionario{
    int id;
    char nome[50];
    char endereco[50];
    int idade;
    char cargo[50];
    float salario;
}FUNCIONARIO;

typedef struct elemento* Lista;

Lista *criaLista();

int menuLista(menu);

FUNCIONARIO entraDados();

int insere_lista_ordenada(Lista *li, FUNCIONARIO dados_func);

int listaVazia(Lista *li);

int tamLista(Lista *li);

int remove_lista(Lista *li, int id);

void apagaLista(Lista *li);

int consulta_lista_id(Lista *li, int id, FUNCIONARIO *dados_func);

