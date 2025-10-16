#include <stdio.h>

struct dado_cliente {
    int num_conta;
    char ultimo_nome[19];
    char primeiro_nome[20];
    double saldo;
};

int main() {
    struct dado_cliente a = {0, "", "s",0.0};
    FILE *f;
    f = fopen("credit.dat","wb");
    if (f == NULL) {
        perror("Erro ao abrir o arquivo binario");
        return 1;
    }
    for (int i = 0;i <= 100;i++){
        fwrite(&a, sizeof(struct dado_cliente), 1, f);

    }
fclose(f);

    return 0;
}