typedef struct{
    char nome[100];
    char cpf[12];
    char tipoconta[30];
    double valori;
    char senha[20];
}cliente;

typedef struct {
    cliente clientes[1000];
    int qtd;
} listadeclientes;

void clearbuffer();
int criarcliente(listadeclientes *c);
int apagacliente(listadeclientes *c,const char *cpf);
int listacliente(listadeclientes *c);
int debitacliente(listadeclientes *c);
int depositacliente(listadeclientes *c);
int extrato(listadeclientes *c);
int transferencia(listadeclientes *c);
