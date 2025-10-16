#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, *v, n ;

    printf("Entre com a quantidade de inteiros a serem lidos: ");
    scanf("%d",&n);

//alocando dinamicamente 

v = (int *) malloc(sizeof(int) * n);

//leia inteiros
printf("Entre com %d inteiros: \n", n);
for ( i = 0 ;i < n; i++) {
    scanf("%d", &v[i]);
}

//imprimindo na ordem inversa
printf("Valores impressos na ordem inversa:\n");
for (i = n - 1;i >= 0;i--) {
    printf("%d \n",v[i]);
}
return 0;
}