#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "cliente.h"
#include "vendas.h"
#include "produtos.h"
#include "menu.h"
#include "prova.h"


int main(){
    setlocale(LC_ALL, "Portuguese");
    system("color 0e");

    int i,opcao, menu = 1, submenu;

    TCliente cliente;
    TModuloCliente  modulo1;
    TProduto  produto;
    TModuloProduto  modulo2;
    TVenda  venda;
    TModuloVenda   modulo3;

    IniciarModuloCliente(&modulo1);
    IniciarModuloProduto(&modulo2);
    IniciarModuloVenda(&modulo3);


    do{

            MSG_MENU();

    printf("\n\n\tOpção: ");
    fflush(stdin);
    scanf("%d", &opcao);

    switch(opcao){

    case 1:

        MENU_CLIENTE();

        printf("\n\tOpção: ");
        fflush(stdin);
        scanf("%d", &submenu);

        switch(submenu){

        case 1:
            LerCliente(&cliente);
            InserirCliente(&modulo1, cliente);
        break;

        case 2:
            printf("\n\tInsira a identidade do cliente que deseja procurar: ");
            fflush(stdin);
            fgets(cliente.id, TAM, stdin);
            PESQUISAR_CLIENTE(modulo1, cliente);
        break;

        case 3:
            printf("\n\tInsira a identidade do cliente que deseja alterar: ");
            fflush(stdin);
            fgets(cliente.id, TAM, stdin);
            int indice = PesquisarCliente(modulo1, cliente);
            if(indice != -1){
            LerCliente(&modulo1.vetor[indice]);
            printf("\n\n\tCliente Alterado com Sucesso !\n\t");
            system("pause");
            }else{
            printf("\n\tCliente não encontrado !\n\t");
            system("pause");
            }
        break;

        case 4:
            printf("\n\tInsira a identidade do cliente que deseja excluir: ");
            fflush(stdin);
            fgets(cliente.id, TAM, stdin);
            ExcluirCliente(&modulo1, cliente);
            printf("\n\t");
            system("pause");
        break;

        case 5:
            for(i=0;i<modulo1.indice;i++){
                printf("\n\n\n\n\tCliente %d", i+1);
                printf("\n\t-----------------------------------------\n");
                ImprimirCliente(modulo1.vetor[i]);
            }
            system("pause");
        break;
        default:
        menu = MSG_EXIT1();
        break;



         // fim do submenu cliente
        } break;
    case 2:

        MENU_PRODUTO();

        printf("\n\tOpção: ");
        fflush(stdin);
        scanf("%d", &submenu);

        switch(submenu){

        case 1:
            LerProduto(&produto);
            InserirProduto(&modulo2, produto);
        break;

        case 2:
            printf("\n\tInsira o código do produto que deseja procurar: ");
            fflush(stdin);
            fgets(produto.codigo, TAM, stdin);
            PESQUISAR_PRODUTO(modulo2, produto);
        break;

        case 3:
            printf("\n\tInsira o Código do Produto que deseja alterar: ");
            fflush(stdin);
            fgets(produto.codigo, TAM, stdin);
            int indice = PesquisarProduto(modulo2, produto);
            if(indice != -1){
            LerProduto(&modulo2.vetor[indice]);
            printf("\n\n\tProduto Alterado com Sucesso !\n\t");
            system("pause");
            }else{
            printf("\n\tProduto não encontrado !\n\t");
            system("pause");
            }

        break;

        case 4:
            printf("\n\tInsira o Código do Produto que deseja excluir: ");
            fflush(stdin);
            fgets(produto.codigo, TAM, stdin);
            ExcluirProduto(&modulo2, produto);
            printf("\n\t");
            system("pause");

        case 5:
            for(i=0;i<modulo2.indice;i++){
                printf("\n\n\n\n\tProduto %d", i+1);
                printf("\n\t-----------------------------------------\n");
                ImprimirProduto(modulo2.vetor[i]);
            }
            system("pause");
        break;

        default:
        menu = MSG_EXIT1();
        break;



        } break; //fim do submenu produto
    case 3:
        MENU_VENDA();

        printf("\n\tOpção: ");
        fflush(stdin);
        scanf("%d", &submenu);

        switch(submenu){

        case 1:
            LerVenda(&venda, modulo1, modulo2);
            InserirVenda(&modulo3, venda, &modulo2, produto);
        break;

        case 2:
            printf("\n\tInsira o código da venda que deseja procurar: ");
            fflush(stdin);
            scanf("%d", &venda.codigo);
            PESQUISAR_VENDA(modulo3, venda);
            printf("\n\t");
            system("pause");
        break;

        case 3:
            printf("\n\tInsira o Código da Venda que deseja alterar: ");
            fflush(stdin);
            scanf("%d", &venda.codigo);
            int indice = PesquisarVenda(modulo3, venda);
            if(indice != -1){
            LerVenda(&modulo3.vetor[indice], modulo1, modulo2);
            printf("\n\n\tVenda Alterada com Sucesso !\n\t");
            system("pause");
            }else{
            printf("\n\tCódigo de Venda não encontrado !\n\t");
            system("pause");
            }
        break;

        case 4:
            printf("\n\tInsira o Código do Venda que deseja excluir: ");
            fflush(stdin);
            scanf("%d", &venda.codigo);
            ExcluirVenda(&modulo3, venda);
            printf("\n\t");
            system("pause");
        break;

        case 5:
            for(i=0;i<modulo3.indice;i++){
                printf("\n\n\n\n\tVenda %d", i+1);
                printf("\n\t-----------------------------------------\n");
                ImprimirVenda(modulo3.vetor[i]);
            }
            system("pause");
        break;
        default:
        menu = MSG_EXIT1();
        break;


        }break; // fim do submenu vendas
        case 4:
            MSG_PROVA();

        printf("\n\tOpção: ");
        fflush(stdin);
        scanf("%d", &submenu);

        switch(submenu){

        case 1:
            printf("\n\tQuestão 1\n");
            Mais_Vendido( modulo2 );

        break;

        case 2:
           printf("\n\tQuestão 2");
           Total_Vendas(modulo3);

        break;

        case 3:
            printf("\n\tQuestão 3");
            Listar_Compras(modulo1, modulo2, modulo3);
            system("pause");
        break;

        case 4:
            printf("\n\tQuestão 4");
            printf("\n\tInsira a identidade do cliente que deseja gerar a Nota Fiscal: ");
            fflush(stdin);
            fgets(cliente.id, TAM, stdin);
            int indice1 = PesquisarCliente(modulo1, cliente);
            TData data;
            TNotaFiscal NotaFiscal;
            LerData(&data);
            Gerar_NotaFiscal(&NotaFiscal, modulo1.vetor[indice1], data);
            Imprimir_NotaFiscal(NotaFiscal, modulo3);
            system("pause");
        break;

        default:
        menu = MSG_EXIT1();
        break;


        }break; // fim do submenu prova

    default:
        menu = MSG_EXIT();
    break;

    }

    system("cls");
    }while(menu == 1);

    printf("\n\t---------------------------------------------");
    printf("\n\n\t  Obrigado por Utilizar o TAD Estoque");
    printf("\n\t  Desenvolvido por: Guilherme Lage Albano\n");
    printf("\n\t---------------------------------------------\n\n\t  ");
    return 0;
}
