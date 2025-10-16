#include <stdio.h>

void print_addr(int x);
int main() {
int x;
x = 3;
printf("o valor de x eh %d,endereco eh: %p",x,&x);

print_addr(x);


 

    return 0;
}

void print_addr(int x) {
    printf("\n O valor eh %d,endereco eh: %p",x,&x);




    return ;
}

//o comportamento n eh esperado ,pois os enderecos são diferentes 