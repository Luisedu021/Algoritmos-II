#include <stdio.h>
/*
Implemente a função troque() que faz uso da passagem por valor. Essa função deve
realizar a troca dos argumentos a e b. Teste na main e veja que a função implementada
não funciona. Explique

*/


void troque(int a,int b);



int main() {
    int a,b;
    a = 5;
    b = 7;

    troque(a,b);
    printf("\nO a e b na main eh %d %d",a,b);

    return 0;
}


void troque(int a,int b) {
    int c;
    c = a;
    a = b;
    b = c; // "a"
    printf (" O valor de a e b agora eh %d %d",a,b);

    return ;
}
/*
Nao funciona pois eh passagem por valor,e os valores mudam apenas na função,quando se analisa fora
da função ,os valores desaparecem 
*/