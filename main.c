#include <stdio.h>
#include "projfunc.h"

int main(){

    listadeclientes c;
    c.qtd = 0;
    
    while (1){
        int opcao;
        
        printf("Bem-vindo ao menu do banco QuemPoupaTem: ");
        printf("\n1. Novo Cliente\n");
        printf("2. Apagar Cliente\n");
        printf("3. Listar Clientes\n");
        printf("4. Débito\n");
        printf("5. Depósito\n");
        printf("6. Extrato\n");
        printf("7. Transfência entre contas\n");
        printf("0. Sair\n");

        printf("Escolha uma opção:");
        scanf("%d", &opcao);

        if (opcao==1){
            criarcliente(&c);
        } else if (opcao==2){
            char cpf[12];
            apagacliente(&c,cpf);
        } else if (opcao==3){
            listacliente(c);
        } else if (opcao==4){


        } else if (opcao==5){

        } else if (opcao==6){

        } else if (opcao==7){

        } else if (opcao==8){

        } else {
            break;
        }
    }
}