#include "produtos.h"
#include <stdio.h>
#include <stdlib.h>

void LerProduto(TProduto * produto){

    printf("\n\tCadastro de Produto");
    printf("\n\n\tC�digo: ");
    fflush(stdin);
    fgets(produto->codigo, TAM, stdin);
    printf("\n\tNome: ");
    fflush(stdin);
    fgets(produto->nome, TAM, stdin);
    printf("\n\tDescri��o: ");
    fflush(stdin);
    fgets(produto->descricao, TAM, stdin);
    printf("\n\tQuantidade em estoque: ");
    fflush(stdin);
    scanf("%d", &produto->estoque);
    printf("\n\tPre�o: R$ ");
    fflush(stdin);
    scanf("%f", &produto->preco);
    produto->qtdVendida = 0;
}

void IniciarModuloProduto(TModuloProduto * modulo){
    modulo->indice = 0;
}

void ImprimirProduto(TProduto produto){

    printf("\n\tC�digo: ");
    puts(produto.codigo);
    printf("\n\tNome: ");
    puts(produto.nome);
    printf("\n\tPre�o: R$ %.2f", produto.preco);
    printf("\n\tQuantidade em Estoque: %d", produto.estoque);
    printf("\n\tDescri��o: ");
    puts(produto.descricao);
    system("pause");
}

void InserirProduto(TModuloProduto * modulo, TProduto produto){

    if(modulo->indice < TAM){
        modulo->vetor [modulo->indice] = produto;
        modulo->indice++;
    printf("\n\tProduto Cadastrado com Sucesso !\n");
    }else{
        printf("\n\tN�o foi Poss�vel Cadastrar o Produto !");
        printf("\n\tMotivo: Banco de Dados cheio !");
    }
    system("pause");
}

int PesquisarProduto(TModuloProduto modulo, TProduto produto){

    int i;
    for(i = 0; i < modulo.indice; i++){
        if(strcmp (produto.codigo, modulo.vetor[i].codigo) == 0){
        return i;
        }
    }
        return -1;
}


void ExcluirProduto(TModuloProduto * modulo, TProduto produto){

    int i, indice1;
    indice1 = PesquisarProduto(*modulo, produto);
    if (indice1 != -1){
        for (i=indice1; i < (modulo->indice); i++){
            modulo->vetor[i] = modulo->vetor[i+1];
        }
        modulo->indice--;
        printf("\n\n\tProduto Exclu�do com Sucesso !");
    }else{
        printf("\n\n\tC�digo de Produto n�o encontrado!");

    }
    system("pause");
}
