#include <stdio.h>

void troque3(int *p1,int *p2);

int main() {
    int a,b;
    a= 4;
    b=7;
    printf("O valor de a e b eh %d,%d\n",a,b);
    troque3(&a,&b);
    printf("O valor de a e b apos a troca eh %d,%d",a,b);

    return 0;
}


void troque3(int *p1,int *p2) {
    int p3;
    p3 = *p2;//b indo para p3
    *p2 = *p1;//b recebendo a
    *p1 = p3;//a recebendo b


    return;
}