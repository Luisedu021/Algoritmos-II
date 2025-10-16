#include <stdio.h>

int main() {
    FILE *f;FILE *f2;
    int n1,n2,soma;

f = fopen("entrada.txt","r");
if (f ==NULL){
    perror("Erro ao abrir o arquivo!");
    return 1;
}
    
fscanf(f,"%d,%d",&n1,&n2);
soma = n1 + n2;
f2 = fopen("saida.txt","w");
if (f2 == NULL){
    perror("Erro ao abrir o arquivo!");
    return 1;
}
else{
    fprintf(f2,"%d",soma);
}
    return 0;
}