#include <stdio.h>

int prod_vetor(int v[],int tamanho );

int main(){

int vetor[] = {2,1,1,6,6};
int tamanho;
tamanho = sizeof(vetor) / sizeof(int);
int a;

a = prod_vetor(vetor,tamanho);


printf("%d ",a);



    return 0;
}

int prod_vetor(int v[],int tamanho){
    

    if(tamanho == 1){

        return  v[0];
    }
    else{
        return v[tamanho  - 1] * prod_vetor(v,tamanho - 1);
    }


}