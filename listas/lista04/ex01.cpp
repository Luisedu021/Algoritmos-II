#include <stdio.h>

int main() {
    int *p, a;

    a = 10;
    p = &a;
    *p = *p * 2;
    printf("a = %d\n", a);

    return 0;
}
/*
Qual o valor da variável a ao final da execução? (Tente primeiro responder apenas analisando o código. Confirme a sua resposta compilando e executando o código.).
R: o valor vai ser 20

*/