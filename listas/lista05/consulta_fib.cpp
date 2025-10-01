#include <stdio.h>
#include <stdlib.h>

int main() {
    int *vetor,n,valor;
    FILE *f_fib;
    f_fib = fopen("arq_fib.txt","r");
    if (f_fib == NULL) {
        perror("Erro ao abrir o arquivo!");

    }

    printf("Quais valores voce deseja ler?");
    scanf("%d",&n);
    if (n >30){
        printf("O arquvivo apenas possui os 30 primeiros numeros");
        return 0;
    }

    vetor = (int *) malloc(sizeof(int) *n);
    for (int i = 0;i < n;i++){
        fscanf(f_fib,"%d",&valor);
        vetor[i] = valor;
        printf("%d ",vetor[i]);
    }


    fclose(f_fib);
    return 0;
}