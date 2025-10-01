#include<stdio.h>
#include <stdlib.h>

int main() {
    int i,maior,r;
    FILE *f;
    f = fopen("100_aleatorios.txt","r");
    if (f == NULL) {
        perror("Erro ao abrir o arquivo!");
        exit (1);
    }
maior = 0;
for (i = 0;i< 100;i++){
    fscanf(f,"%d",&r);
    if (r> maior)
    maior = r;
}
printf("%d\n",maior);
fclose(f);
return 0;
}