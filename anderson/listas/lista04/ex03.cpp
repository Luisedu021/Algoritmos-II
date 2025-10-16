#include <stdio.h>

int main() {
    int x,y,*p,*q;

    x = 2;
    y = 8;
    p =  &x;
    q = &y;

    printf("a) o endereco de x eh %p o valor de x eh %d"
        "\nb)O endereco de p eh %p e o valor eh %d"
            "\nO endereco de y e seu valor eh %p, %d"
                "\nO endereco de q eh %p",&x,x),&p,*p,&y,y,p;


    return 0;
}