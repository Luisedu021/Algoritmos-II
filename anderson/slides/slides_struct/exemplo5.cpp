#include <stdio.h>

struct empresa {
    char nome[50];
    float salario;

};

int main() {

    struct empresa funcionarios[4];

    for (int i = 0; i < 3; i++) {
        printf("Digite o nome do funcionario %d: ", i + 1);
        scanf("%49s%*c", funcionarios[i].nome);
        printf("Digite o salario do funcionario %d: ", i + 1);
        scanf("%f%*c", &funcionarios[i].salario);
    }

    for ( int i = 0; i < 3; i++) {
        printf("O funcionario %s ganha %2.f\n",funcionarios[i].nome,funcionarios[i].salario);
    }

    return 0;
}