#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prova.h"
#include "produtos.h"
#include "vendas.h"
#include "cliente.h"

void Mais_Vendido(TModuloProduto modulo2){

    int i, j, maisVendido;

    for(i = 0;  i<modulo2.indice;  i++){
        for(j = i+1; j<modulo2.indice; j++){
            if(modulo2.vetor[ i].qtdVendida >= modulo2.vetor[ j].qtdVendida){
                maisVendido = i;
            }
        }
    }
    printf("\n\tProduto mais Vendido: \n");
    printf("\n\t-----------------------------------------------------------------\n");
    ImprimirProduto(modulo2.vetor[maisVendido]);
}

void Total_Vendas(TModuloVenda modulo3){

    int quantVendas = 0, i, j;
    float valorTotal = 0;

    for(i = 0; i<modulo3.indice; i++){
        if(modulo3.vetor[i].tipoPagamento == 0){
            quantVendas++;
            valorTotal += modulo3.vetor[i].valor;
        }
    }

    printf("\n\tNo total existem %d vendas a vista cadastradas no modulo de vendas", quantVendas);
    printf("\n\tO valor total das vendas e R$%.2f\n\n\t", valorTotal);
    system("pause");
}

void LerData(TData * data){

    printf("\n\tInsira o dia: ");
    scanf("%d", &data->dia);
    printf("\n\tInsira o mês: ");
    scanf("%d", &data->mes);
    printf("\n\tInsira o ano: ");
    scanf("%d", &data->ano);
}

void Gerar_NotaFiscal(TNotaFiscal * NotaFiscal, TCliente cliente, TData data){

        NotaFiscal->data = data;
        strcpy(NotaFiscal->cliente, cliente.nome);

}

void Imprimir_NotaFiscal(TNotaFiscal NotaFiscal, TModuloVenda modulo3){

        int valorTotal = 0;
        int i;

        printf("\n\tCliente: ");
        puts(NotaFiscal.cliente);
        printf("\n\tData:");
        printf("\n\tDia: %d", NotaFiscal.data.dia);
        printf("\n\tMês: %d", NotaFiscal.data.mes);
        printf("\n\tAno: %d", NotaFiscal.data.ano);

        for(i=0; i<modulo3.indice; i++){

            if(NotaFiscal.data.dia == modulo3.vetor[i].data.dia && NotaFiscal.data.mes == modulo3.vetor[i].data.mes && NotaFiscal.data.ano == modulo3.vetor[i].data.ano){
            if(strcmp(NotaFiscal.cliente, modulo3.vetor[i].cliente) == 0){
                printf("\n\tProduto: ");
                puts(modulo3.vetor[i].produto);
                valorTotal += modulo3.vetor[i].valor;
            }}
        }

        printf("\n\tValor Total: R$ %2.f", valorTotal);
}

void Listar_Compras(TModuloCliente modulo1, TModuloProduto modulo2, TModuloVenda modulo3){

        int i, j = 0;
        TCliente cliente1, cliente2;
        TVenda vendas1[modulo3.indice], vendas2[modulo3.indice];
        printf("\n\tInsira o codigo do primeiro cliente: ");
        fflush(stdin);
        fgets(cliente1.id, 50, stdin);
        printf("\n\tInsira o codigo do segundo cliente: ");
        fflush(stdin);
        fgets(cliente2.id, 50, stdin);

        for(i = 0; i<modulo3.indice; i++){

            if(strcmp(cliente1.id, modulo3.vetor[i].codigoCliente) == 0){
                vendas1[j] = modulo3.vetor[i];
                j++;
            }
        }

        j = 0;

        for(i = 0; i<modulo3.indice; i++){

            if(strcmp(cliente1.id, modulo3.vetor[i].codigoCliente) == 0){
                vendas2[j] = modulo3.vetor[i];
                j++;
            }
        }
        printf("\n\tCodigos de produtos em comum: \n");
        for(i = 0; i<modulo3.indice; i++){
            for(j = i+1; j<modulo3.indice; j++){
            if(strcmp(vendas1[i].codigoProd, vendas2[j].codigoProd) == 0){
                printf("\n\tCodigo: ");
                puts(vendas1[i].codigoProd);
            }
            }
        }


}
