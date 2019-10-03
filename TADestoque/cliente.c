#include <stdlib.h>
#include <stdio.h>
#include "cliente.h"

void LerCliente(TCliente * cliente){

    printf("\n\tCadastro de Cliente");
    printf("\n\n\tIdentidade: ");
    fflush(stdin);
    fgets(cliente->id, TAM, stdin);
    printf("\n\tNome: ");
    fflush(stdin);
    fgets(cliente->nome, TAM, stdin);
    printf("\n\tEndere�o: ");
    fflush(stdin);
    fgets(cliente->endereco, TAM, stdin);
    printf("\n\tTipo de cliente");
    do{
    printf("\n\t0 - F�sico  ou 1 - Jur�dico:  ");
    fflush(stdin);
    scanf("%d", &cliente->tipo);
    if((*cliente).tipo < 0 || (*cliente).tipo > 1){
       printf("\n\tValor inv�lido !");
       printf("\n\tPor favor, Insira um valor v�lido\n\n");
       }
    }while((*cliente).tipo < 0 || (*cliente).tipo > 1);
    if((*cliente).tipo == 0){
        printf("\n\tCPF: ");
        fflush(stdin);
        scanf("%d", &cliente->cadastro);
    }else{
        printf("\n\tCNPJ: ");
        fflush(stdin);
        scanf("%d", &cliente->cadastro);
    }

}

void IniciarModuloCliente(TModuloCliente * modulo){
    modulo->indice = 0;
}

void ImprimirCliente(TCliente cliente){

    printf("\n\n\tIdentidade: ");
    puts(cliente.id);
    printf("\n\tNome: ");
    puts(cliente.nome);
    printf("\tTipo: ");
    if(cliente.tipo == 0){
        printf("F�sico");
        printf("\n\tCPF: %d", cliente.cadastro);
    }else{
        printf("J�ridico");
        printf("\n\tCNPJ: %d", cliente.cadastro);
    }
    printf("\n\tEndere�o: ");
    puts(cliente.endereco);
}

void InserirCliente(TModuloCliente * modulo, TCliente cliente){

    if(modulo->indice < TAM){
        modulo->vetor [modulo->indice] = cliente;
        modulo->indice++;
    printf("\n\tCliente Cadastrado com Sucesso !\n");
    }else{
        printf("\n\tN�o foi Poss�vel Cadastrar o Cliente !");
        printf("\n\tMotivo: Banco de Dados cheio !");
    }
    system("pause");
}

int  PesquisarCliente(TModuloCliente modulo, TCliente cliente){

    int i;
    for (i=0;i < modulo.indice; i++){
        if (strcmp (cliente.id, modulo.vetor[i].id) == 0){

            return i;
        }
    }
    return -1;
}



void ExcluirCliente(TModuloCliente * modulo, TCliente cliente){

    int i, indice1;
    indice1 = PesquisarCliente(*modulo, cliente);
    if (indice1 != -1){
        for (i=indice1; i < (modulo->indice); i++){
            modulo->vetor[i] = modulo->vetor[i+1];
        }
        modulo->indice--;
        printf("\n\n\tCliente Exclu�do com Sucesso !");
    }else{
        printf("\n\n\tIdentifica��o do Cliente n�o encontrado!");

    }
}
