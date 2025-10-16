#include <stdio.h>
#include <stdlib.h>

struct dado_cliente {
    int num_conta;
    char ultimo_nome[19];
    char primeiro_nome[20];
    double saldo;
};

int main() {
    struct dado_cliente cliente;
    FILE *f;

    f = fopen("credit.dat", "rb+");
    if (f == NULL){
        perror("Arquivo nao pode ser aberto");
        return 1;
    }
    printf("Entre com o numero da conta(1 a 100,0 para encerrar o input): ");
    scanf("%d",&cliente.num_conta);
    while (cliente.num_conta != 0){
        printf("Entre com o primeiro nome, ultimo nome e o saldo\n?");
        scanf("%s%s%lf", cliente.primeiro_nome,cliente.ultimo_nome,&cliente.saldo);
        fseek(f,(cliente.num_conta - 1) * sizeof(struct dado_cliente), SEEK_SET);
        fwrite(&cliente, sizeof(struct dado_cliente), 1, f);
        printf("Entre com o numero da conta: ");
        scanf("%d", &cliente.num_conta);
    }

    fclose(f);

    return 0;
}