#include <stdio.h>
#include <stdlib.h>
#include "vendas.h"
#include "produtos.h"
#include "cliente.h"

int MSG_EXIT(){
        int menu;
        printf("\n\t---------------------------------------------");
        printf("\n\t0 - Área de Trabalho\t1 - Voltar ao Menu");
        printf("\n\tOpção: ");
        fflush(stdin);
        scanf("%d", &menu);
        system("cls");
        return menu;
}

int MSG_EXIT1(){
        int menu;
        printf("\n\t----------------------------------------------");
        printf("\n\n\t0 - Área de Trabalho\t1 - Menu de Módulos");
        printf("\n\tOpção: ");
        fflush(stdin);
        scanf("%d", &menu);
        system("cls");
        return menu;
}



void MSG_MENU(){
    printf("\n\t              BEM - VINDO ao TAD ESTOQUE !");
    printf("\n\t---------------------------------------------------");
    printf("\n\tUtilize o teclado númerico para navegar pelos menus");
    printf("\n\n\n\t\t\t1. Módulo Clientes");
    printf("\n\t\t\t2. Módulo Produtos");
    printf("\n\t\t\t3. Módulo Vendas");
    printf("\n\t\t\t4. Módulo Prova");
    printf("\n\t\t\t5. Sair");
    printf("\n\n\t-------------------------------------------------");
}

void MSG_SUBMENU(){

    printf("\n\t---------------------------------------------------");
    printf("\n\tUtilize o teclado númerico para navegar pelos menus");
    printf("\n\n\n\t\t\t1. Cadastrar");
    printf("\n\t\t\t2. Pesquisar");
    printf("\n\t\t\t3. Alterar");
    printf("\n\t\t\t4. Excluir");
    printf("\n\t\t\t5. Imprimir Todos");
    printf("\n\t\t\t6. Voltar");
    printf("\n\n\t-------------------------------------------------");
}

void MENU_CLIENTE(){
    system("cls");
    int submenu;
    printf("\n\t              MÓDULO CLIENTE !");
    MSG_SUBMENU();


}

void PESQUISAR_CLIENTE(TModuloCliente modulo, TCliente cliente){
    int i;
    i = PesquisarCliente(modulo, cliente);
    if(i == -1){
        printf("\n\tCliente não encontrado !\n\n");
        system("pause");
    }else{
    ImprimirCliente(modulo.vetor[i]);
    system("pause");
    }
}


void MENU_PRODUTO(){
    system("cls");
    int submenu;
    printf("\n\t              MÓDULO PRODUTO !");
    MSG_SUBMENU();


}

void PESQUISAR_PRODUTO(TModuloProduto modulo, TProduto produto){
    int i;
    i = PesquisarProduto(modulo, produto);
    if(i == -1){
        printf("\n\tProduto não encontrado !\n\n");
    }else{
    ImprimirProduto(modulo.vetor[i]);
    }
}


void MENU_VENDA(){
    system("cls");
    int submenu;
    printf("\n\t              MÓDULO VENDA !");
    MSG_SUBMENU();


}

void PESQUISAR_VENDA(TModuloVenda modulo, TVenda venda){
    int i;
    i = PesquisarVenda(modulo, venda);
    if(i == -1){
        printf("\n\tCódigo de Venda não encontrado !\n\n");
    }else{
    ImprimirVenda(modulo.vetor[i]);
    }
}

void MSG_PROVA(){
    system("cls");
    printf("\n\t                  MÓDULO PROVA");
    printf("\n\t---------------------------------------------------");
    printf("\n\tUtilize o teclado númerico para navegar pelos menus");
    printf("\n\n\n\t\t\t1. Produto mais vendido");
    printf("\n\t\t\t2. Total de Vendas");
    printf("\n\t\t\t3. Compras em Comum");
    printf("\n\t\t\t4. Nota fiscal");
    printf("\n\t\t\t5. Voltar");
    printf("\n\n\t-------------------------------------------------");

}
