#define TAM 50

typedef struct cliente_str{

    char nome[TAM];
    char id[TAM];
    char endereco[TAM];
    int cadastro; //CPF ou CNPJ
    int tipo; // 0 - Físico ou 1 - Jurídico

}TCliente;

typedef struct modulo_cliente{

    TCliente vetor[TAM];
    int indice;

}TModuloCliente;

void LerCliente(TCliente * cliente);

void InserirCliente(TModuloCliente * modulo, TCliente cliente);

void IniciarModuloCliente(TModuloCliente * modulo);

void ImprimirCliente(TCliente cliente);

int PesquisarCliente(TModuloCliente modulo, TCliente cliente);

void AlterarCliente(TModuloCliente * modulo, TCliente cliente);

void ExcluirCliente(TModuloCliente * modulo, TCliente cliente);


