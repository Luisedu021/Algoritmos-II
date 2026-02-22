#include <stdio.h>


void quick_sort(int *vetor,int inicio,int fim);
int particiona(int *v,int inicio, int fim);
void imprimir(int *v,int tam);

int main(){


int vetor[] = {1,6,3,7,3,130,1233};
int tamanho = 7;
printf("Vetor nao ordenado: \n");

imprimir(vetor,tamanho);

printf("Vetor ordenado: \n");
quick_sort(vetor,0,6);
imprimir(vetor,tamanho);

    return 0;
}



int particiona(int *v,int inicio, int fim){
int pivo = (v[inicio] + v[fim] + v[(inicio + fim)/2])/3;

while(inicio < fim){
    while(inicio < fim && v[inicio]<= pivo){
        inicio++;
    }
    while(inicio < fim && v[fim] > pivo){
        fim--;
    }
    int aux = v[inicio];
    v[inicio] = v[fim];
    v[fim] = aux;
}

return inicio;

}
void quick_sort(int *vetor,int inicio,int fim){//0 14
if(inicio < fim){
    int pos = particiona(vetor,inicio,fim);
    quick_sort(vetor, inicio, pos -1);
    quick_sort(vetor,pos, fim);
}
    
}

void imprimir(int *v,int tam){
    int i;
    for (i = 0; i < tam;i++){
        printf("%d ",v[i]);

    }
    printf("\n");
}
