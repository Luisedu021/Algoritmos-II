#include <stdio.h>

typedef struct {
    char nome[20];
    char sobrenome[20];
    int idade;
    char sexo;
    double salario;

} funcionario;
// nao preciso mais colocar struct pra definir as variaveis agora

int main() {
    funcionario f = {"Luis","Santos",19};

    printf("%s %s (%d anos)\n",f.nome,f.sobrenome,f.idade);
    return 0;

}