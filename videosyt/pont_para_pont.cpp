#include <stdio.h>
#include<stdlib.h>

int main(void)
{
    int x, *ptrx, **pptrx;

    //inicializando a variavel com 0
    x = 0;
    printf("\nValor de x = %d\n",x);
    printf("Endereco de x: %x\n\n",&x);

    ptrx = &x;
    pptrx = &ptrx;
    *ptrx += 10;

    printf("\nValor de x = %d", x);
    printf("\nEndereco apontado por ptrx: %x",ptrx);
    printf("\nValor da variavel x que esta sendo apontada por ptrx: %d\n",*ptrx);
    **pptrx += 20;
    printf("\nValor da variavel x que esta sendo apontada por pptrx: %d",**pptrx);
    printf("\nEndereco de memoria da variavel ptrx %x\n\n",&ptrx);
    



    return 0;
}