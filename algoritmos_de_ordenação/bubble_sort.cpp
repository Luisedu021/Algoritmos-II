#include <stdio.h>

void bubble_sort(int v[],int tamanho);

int main(){

    int vetor[] = {1,55,8,2,35,8};
    bubble_sort(vetor,6);
    for(int i = 0;i < 6;i++){
    printf("%d ",vetor[i]);
    }
    return 0;
}

void bubble_sort(int v[],int tamanho){

for(int i = 0;i < tamanho - 1;i++){

    for(int j = 0;j < tamanho - 1 - i;j++){
        int aux;
        if(v[j] > v[j+ 1]){
        aux = v[j];
        v[j] = v[j+1];
        v[j+1] = aux;
    }
}

}
}
