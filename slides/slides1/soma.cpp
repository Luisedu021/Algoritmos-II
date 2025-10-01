#include <stdio.h>

int main() {
    int a, b, soma ;

    printf("Escreva um numero: ");
    scanf("%d", &a);

    printf("Escreva mais um numero: ");
    scanf("%d", &b);

    soma = a + b;
    printf("A soma eh %d", soma);

    return 0;

}