#include <stdlib.h>
#include <stdio.h>
#include "vendas.h"
#include "produtos.h"
#include "cliente.h"
#include <string.h>

void LerVenda(TVenda * venda, TModuloCliente modulo1, TModuloProduto modulo2){
    TCliente cliente;
    TProduto produto;
    int aux;
    printf("\n\tCadastro de Venda");
    printf("\n\n\tCódigo da venda(deve ser um número inteiro): ");
    fflush(stdin);
    scanf("%d", &venda->codigo);
    do{
    printf("\n\tIdentidade do Cliente: ");
    fflush(stdin);
    fgets(venda->codigoCliente, TAM, stdin);
    strcpy(cliente.id, venda->codigoCliente);
    aux = PesquisarCliente(modulo1, cliente);
    if(aux == -1){
        printf("\n\tCliente não encontrado, Insira a identidade novamente");
    }else{
        printf("\n\tCliente: ");
        strcpy(venda->cliente,modulo1.vetor[aux].nome);
        puts(modulo1.vetor[aux].nome);
    }
    }while(aux == -1);
    do{
    printf("\n\tCódigo do Produto: ");
    fflush(stdin);
    fgets(venda->codigoProd, TAM, stdin);
    strcpy(produto.codigo, venda->codigoProd);
    aux = PesquisarProduto(modulo2, produto);
    if(aux == -1){
        printf("\n\tProduto não encontrado, Insira o código novamente");
    }else{
        printf("\n\tProduto: ");
        puts(modulo2.vetor[aux].nome);
        strcpy(venda->produto,modulo2.vetor[aux].nome);
        venda->indiceProduto = aux;
    }
    }while(aux == -1);
    do{
    printf("\n\tQuantidade vendida: ");
    fflush(stdin);
    scanf("%d", &venda->quantVenda);
    if((venda->quantVenda) > modulo2.vetor[aux].estoque){
        printf("\n\tImpossível realizar a venda, não há produtos suficientes em estoque");
        printf("\n\tPor Favor insira um outro valor");
    }
    }while((venda->quantVenda) > modulo2.vetor[aux].estoque);
    venda->valor = venda->quantVenda*modulo2.vetor[aux].preco;
    do{
    printf("\n\tTipo de Pagamento: ");
    printf("\n\t 0 - À Vista  ou  1 - À Prazo");
    fflush(stdin);
    scanf("%d", &venda->tipoPagamento);
    }while((*venda).tipoPagamento < 0 || (*venda).tipoPagamento > 1);
    printf("\n\tData da venda: ");
    printf("\n\tDia: ");
    fflush(stdin);
    scanf("%d", &venda->data.dia);
    printf("\n\tMês: ");
    fflush(stdin);
    scanf("%d", &venda->data.mes);
    printf("\n\tAno: ");
    fflush(stdin);
    scanf("%d", &venda->data.ano);
    printf("\n\tDescrição: ");
    fflush(stdin);
    fgets(venda->descricao, TAM, stdin);
}

void InserirVenda(TModuloVenda * modulo, TVenda venda, TModuloProduto * modulo2, TProduto produto){

    if(modulo->indice < TAM){
        modulo->vetor [modulo->indice] = venda;
        modulo->indice++;
    modulo2->vetor[venda.indiceProduto].estoque -= venda.quantVenda;
    modulo2->vetor[venda.indiceProduto].qtdVendida += venda.quantVenda;
    printf("\n\tVenda Cadastrada com Sucesso !\n");
    }else{
        printf("\n\tNão foi Possível Cadastrar a Venda !");
        printf("\n\tMotivo: Banco de Dados cheio !");

    }
    system("pause");
}

void IniciarModuloVenda(TModuloVenda * modulo){
    modulo->indice = 0;
}

void ImprimirVenda(TVenda venda){
    printf("\n\tCódigo da Venda: %d", venda.codigo);
    printf("\n\tCliente: ");
    puts(venda.cliente);
    printf("\n\tIdentidade do Cliente: ");
    puts(venda.codigoCliente);
    printf("\n\tProduto: ");
    puts(venda.produto);
    printf("\n\tQuantidade: %d", venda.quantVenda);
    printf("\n\tValor total: R$ %.2f", venda.valor);
    printf("\n\tTipo de Pagamento: %d", venda.tipoPagamento);
    if(venda.tipoPagamento == 0){
        printf("À Vista");
    }else{
    printf("À Prazo");
    }
    printf("\n\tDescrição: ");
    puts(venda.descricao);
    printf("\tData de Venda: %d/%d/%d", venda.data.dia, venda.data.mes, venda.data.ano);


}

int PesquisarVenda(TModuloVenda modulo, TVenda  venda){

    int i;
    for(i = 0; i < TAM; i++){
        if(modulo.vetor[i].codigo == venda.codigo){
        return i; }
    }
        return -1;
}


void ExcluirVenda(TModuloVenda * modulo, TVenda venda){

    int i, indice1;
    indice1 = PesquisarVenda(*modulo, venda);
    if (indice1 != -1){
        for (i=indice1; i < (modulo->indice); i++){
            modulo->vetor[i] = modulo->vetor[i+1];
        }
        modulo->indice--;
        printf("\n\n\tVenda Excluída com Sucesso !");
    }else{
        printf("\n\n\tCódigo de Venda não encontrado!");

    }
}

