#include <stdio.h>

int busca_binaria(int valor,int vetor[],int inicio,int fim);

int main(){
int v1;
int vetor1[] = {1,4,6,8,33,56,78};

v1 = busca_binaria(8,vetor1,0,6);

printf("%d",v1);

    return 1;
}

int busca_binaria(int valor,int vetor[],int inicio,int fim){
        if(inicio > fim){
            return -1;
        }
int meio = (fim + inicio )/2;

       if(vetor[meio] == valor){
        return meio;
       }
       

        if(valor > vetor[meio]){
            inicio = meio + 1;
            return busca_binaria(valor,vetor,inicio,fim);
        }
        else{
            fim = meio - 1 ;
            return busca_binaria(valor,vetor,inicio,fim);
        }


}