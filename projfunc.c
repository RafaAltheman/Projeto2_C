#include "projfunc.h"
#include <stdio.h>
#include <string.h>

void clearbuffer(){
   int c;
   while((c = getchar()) != '\n' && c != EOF);
}

int criarcliente(listadeclientes *c){
    if (c-> qtd < 1000){
        clearbuffer();
        printf("Nome: ");
        scanf("%[^\n]s", c->clientes[c->qtd].nome);
        clearbuffer();
        printf("CPF: ");
        scanf("%[^\n]s", c->clientes[c->qtd].cpf);
        clearbuffer();
        printf("Tipo de conta: ");
        scanf("%[^\n]s", c->clientes[c->qtd].tipoconta);
        clearbuffer();
        printf("Valor inicial: ");
        scanf("%2lf", &c->clientes[c->qtd].valori);
        clearbuffer();
        printf("Senha: ");
        scanf("%[^\n]s", c->clientes[c->qtd].senha);
        clearbuffer();
        c->qtd++;
        printf("Cliente cadastrado!\n");
     } else {
        printf("Número de clientes cadastrados ultrapassou o limite!\n");
     }
     return 0;
};


int apagacliente(listadeclientes *c, const char *cpf){
   int escolhido = 0;
   char cpf_deletar[12];
   clearbuffer();
   printf("Digite o CPF que deseja deletar: ");
   scanf("%s", cpf_deletar);
   int indice = buscacpfdeletar(c, cpf_deletar);

    if (indice != -1) {
        for (int i = indice; i < c->qtd - 1; i++) {
            c->clientes[i] = c->clientes[i + 1];
        }
        c->qtd--; 
        printf("Cliente com CPF %s apagado com sucesso.\n", cpf_deletar);
    } else {
        printf("CPF %s não encontrado na lista de clientes.\n", cpf_deletar);
    }
}

int listacliente(listadeclientes c){
   if (c.qtd == 0) {
        printf("A lista de clientes esta vazia.\n");
    } else {
        printf("Lista de Clientes:\n");
        for (int i = 0; i < c.qtd; i++) {
            printf("Nome: %s\n", c.clientes[i].nome);
            printf("CPF: %s\n", c.clientes[i].cpf); 
            printf("Tipo de conta: %s\n", c.clientes[i].tipoconta); 
            printf("Valor inicial: %.2lf\n", c.clientes[i].valori); 
            printf("Senha: %s\n", c.clientes[i].senha);
            printf("\n"); 
        }
    }
    return 0;
}

int debitacliente(listadeclientes *c){
   char senha_verificar[20];
   char cpf_verificar[12];
   float valor_debitado;

   clearbuffer();
   printf("Digite o CPF: ");
   scanf("%s", cpf_verificar);
   clearbuffer();
   printf("Digite a senha: ");
   scanf("%s", senha_verificar);
   
   int cpfencontrado = buscacpf(c, cpf_verificar);

   if(cpfencontrado != -1 && strcmp(c->clientes[cpfencontrado].senha, senha_verificar)==0){
      printf("Usuário localizado! Digite o valor a ser debitado: ");
      scanf("%f", &valor_debitado);
         if(c->clientes[cpfencontrado].valori >= valor_debitado){
            c->clientes[cpfencontrado].valori -= valor_debitado;
            printf("Debito realizado com sucesso!\n");
         }
         else{
            printf("Saldo insuficiente para realizar a transação\n");
         }
      }else{
         printf("CPF ou senha incorretos!\n");
      }
}

int depositacliente(listadeclientes *c){
   char cpf_verificar[12];
   double valor;

   clearbuffer();
   printf("Digite o CPF: ");
   scanf("%s", cpf_verificar);
   
   int cpfencontrado = buscacpf(c, cpf_verificar);

   if(cpfencontrado != -1){
      printf("Usuário localizado! Digite o valor a ser depositado: ");
      scanf("%lf", &valor);
         if(valor > 0){
            c->clientes[cpfencontrado].valori += valor;
            printf("Deposito realizado com sucesso!\n");
         } else {
            printf("Digite um valor maior que 0.");
         }
      }else{
         printf("CPF incorretos!\n");
      }

}

///////////////////////////////////////////////////////////////////////////////

int salvar(listadeclientes *c, char nome[]){
   FILE *f = fopen(nome, "wb");
   if (f == NULL){
      printf("Erro ao abrir o arquivo. \n");
      return 1;
   }
   fwrite(c, sizeof(listadeclientes), 1, f);
   fclose(f);
   return 0;
}

int carregarlista(listadeclientes *c, char nome[]){ 
    FILE *f = fopen(nome, "rb"); 
    if (f == NULL) {
        printf("Arquivo nao encontrado.\n"); 
        return 1;
    }
    fread(c, sizeof(listadeclientes), 1, f);
    fclose(f); 
    return 0;
}

int buscacpfdeletar(listadeclientes *c, char cpf_deletar[]){
   int encontrado = 0;
    for (int i = 0; i < c->qtd; i++) {
        if (strcmp(c->clientes[i].cpf, cpf_deletar) == 0) {
            return i;
     }
    }
   return -1;
}

int achasenha(listadeclientes *c, char senha_verificar[]){
   int encontrado = 0;
    for (int i = 0; i < c->qtd; i++) {
        if (strcmp(c->clientes[i].senha, senha_verificar) == 0) {
            return i;
     }
    }
   return -1;
}

int buscacpf(listadeclientes *c, char cpf_verificar[]){
   int encontrado = 0;
    for (int i = 0; i < c->qtd; i++) {
        if (strcmp(c->clientes[i].cpf, cpf_verificar) == 0) {
            return i;
     }
    }
   return -1;
}
