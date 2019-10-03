#define TAM 50

typedef struct produto_str{

    char codigo[TAM];
    char nome[TAM];
    char descricao[TAM];
    int estoque;
    float preco;
    int qtdVendida;

}TProduto;

typedef struct modulo_produto{

    TProduto vetor[TAM];
    int indice;

}TModuloProduto;

void LerProduto(TProduto * produto);

void IniciarModuloProduto(TModuloProduto * modulo);

void imprimirProduto(TProduto produto);

int PesquisarProduto(TModuloProduto modulo, TProduto produto);

void AlterarProduto(TModuloProduto * modulo, TProduto produto);

void ExcluirProduto(TModuloProduto * modulo, TProduto produto);
