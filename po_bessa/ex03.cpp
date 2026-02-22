#include <stdio.h>

void quick_sort(int *v,int inicio,int fim);
void troque(int *a,int *b);
int particiona(int *v,int inicio,int fim);
void imprimir(int *v,int tam);

int main(){
int vetor[] = {3,5431,34,54,7,23,45,24,77,33};

imprimir(vetor,10);

quick_sort(vetor,0,9);
printf("Vetor ordenado:\n");
imprimir(vetor,10);


    return 1;
}

void troque(int *a,int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
    
}

int particiona(int *v,int inicio,int fim){
    int pivo = (v[inicio] + v[fim] + v[(fim + inicio)/2])/3;
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

void quick_sort(int *v,int inicio,int fim){
    if(inicio < fim){
        int indice;
        indice = particiona(v,inicio,fim);
        quick_sort(v,inicio,indice -1);
        quick_sort(v,indice,fim);
    }
}


void imprimir(int *v,int tam){
    int i;
    for (i = 0; i < tam;i++){
        printf("%d ",v[i]);

    }
    printf("\n");
}
