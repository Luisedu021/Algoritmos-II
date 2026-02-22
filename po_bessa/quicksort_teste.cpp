#include <stdio.h>

int particiona(int *v,int inicio,int fim);
void troque(int *a,int *b);
void quicksort(int *v,int inicio,int fim);
void imprimir(int *v,int tam);

int main(){

int vetor[] = {1,6,3,7,3,130,1233};
int tamanho = 7;
printf("Vetor nao ordenado: \n");

imprimir(vetor,tamanho);

printf("Vetor ordenado: \n");
quicksort(vetor,0,6);
imprimir(vetor,tamanho);


    return 1;

}

void troque(int *a,int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;

}

int particiona(int *v,int inicio,int fim){
int pivo = (v[inicio] + v[fim] + v[(inicio + fim)/2])/3;

while(inicio < fim){
    while(inicio < fim && v[inicio] <= pivo){
        inicio++;
    }
    while(inicio < fim && v[fim] > pivo){
        fim--;
    }
    troque(&v[inicio],&v[fim]);
}

return inicio;
}

void quicksort(int *v,int inicio,int fim){
    int indice = particiona(v,inicio,fim);
    if(inicio >= fim){
        return ;
    }
    quicksort(v,indice,fim);
    quicksort(v,inicio,indice -1);

}

void imprimir(int *v,int tam){
    int i;
    for (i = 0; i < tam;i++){
        printf("%d ",v[i]);

    }
    printf("\n");
}
