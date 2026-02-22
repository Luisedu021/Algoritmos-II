#include <stdio.h>
//metodo por inserção
void insertion_sort(int vetor[],int tamanho);


int main() {

    return 0;
}

void insertion_sort(int vetor[],int tamanho){
int chave;
int j;

    for(int i = 1;i < tamanho;i++){
        
        chave = vetor[i];
        j = i - 1;
        while(j >= 0 && vetor[j] > chave){
            vetor[j+1] = vetor[j];
            j = j - 1;
        }
        vetor[j+1] = chave;
    }
}


//melhor caso o de n
//pior caso o de n^2
//são executadas i - 1 iterações no pior caso
