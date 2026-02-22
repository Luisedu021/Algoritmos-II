#include <stdio.h>

int pali(char v[],int tamanho_vetor,int inicializador);

int main(){

int ver;

ver = pali("renner",6,0);
printf("%d",ver);

    return 0;
}




int pali(char v[],int tamanho_vetor,int inicializador){
    if(tamanho_vetor == 1 || tamanho_vetor == 0){
        return 1;
    }
    else{
        if(v[inicializador] == v[tamanho_vetor - 1]){
            return 1;
        }
        else{
            return 0;
        }
        pali(v,tamanho_vetor - 1,inicializador + 1);
    }




}