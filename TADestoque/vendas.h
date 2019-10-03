#define TAM 50


typedef struct data_str{

    int dia;
    int mes;
    int ano;

}Data;


typedef struct vendas_str{
    int codigo;
    char codigoProd[TAM];
    char codigoCliente[TAM];
    char produto[TAM];
    char cliente[TAM];
    Data data;
    int quantVenda;
    float valor;
    int tipoPagamento; //0 - à vista  ou 1 - à prazo
    char descricao[TAM];
    int indiceProduto //variavel pra encontrar o indice do produto vendido no modulo
}TVenda;

typedef struct modulo_vendas{

    TVenda vetor[TAM];
    int indice;

}TModuloVenda;



void IniciarModuloVenda(TModuloVenda * modulo);

int PesquisarVenda(TModuloVenda modulo, TVenda  venda);

void ExcluirVenda(TModuloVenda * modulo, TVenda venda);

