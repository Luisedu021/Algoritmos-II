#include <stdio.h>
#include "teste.h"

int main() {int a = 5,b = 8,c = 7;

printf("Antes,a : %d,b = %d,c= %d\n",a,b,c);

troque2(&a,&b);
troque2(&a,&c);

printf("depois, a: %d,b = %d,c= %d",a,b,c);
    return 0;}
