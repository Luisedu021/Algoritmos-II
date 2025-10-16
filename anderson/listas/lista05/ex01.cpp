#include <stdio.h>
int main() {
    int n1,n2;
    FILE *f;
    f = fopen("Entrada.txt","w");
    if (f == NULL){
        perror("Erro ao abrir o arquivo!");
        return 1;
    }
    n1 = 20;
    n2 = 30;
    fprintf(f,"%d,%d",n1,n2);
    return 0;
}