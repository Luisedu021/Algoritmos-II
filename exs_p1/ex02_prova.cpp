#include <stdio.h>
#include <stdlib.h>

int* vetor_dobro(int *vetor,int capacidade);

int main() {
    int n,cont = 0;
    int *vetor;
    n = 5;
    vetor = (int *) malloc(sizeof(int) * n);
    while(1){
        if(cont == n){
            vetor = vetor_dobro(vetor,n);
            n = n*2;
        }
        printf("Escreva o elemento %d do vetor: ",cont);
        scanf("%d%*c",&vetor[cont]);

        if(vetor[cont] == -1){
            break;
        }
        

        cont++;
    }

    for (int i = 0;i < cont;i++){
        printf("%d ",vetor[i]);
    }


    free(vetor);
    return 0;
}

int* vetor_dobro(int *vetor,int capacidade){
    int *vetor_novo;
    int capacidade_nova = capacidade *2;

    vetor_novo = (int *) malloc(sizeof(int) * capacidade_nova);
    if (vetor_novo == NULL){
        free(vetor);
        return NULL;
    }

    for (int i = 0;i < capacidade;i++){
        vetor_novo[i] = vetor[i];

    }
    free(vetor);
    return vetor_novo;
}