#include <stdio.h>
#include <string.h>
#define INICIO 0

int pali(char v[],int tamanho,int inicio);

int main(){
char nome[] = "arara";
int ver;
int tamanho_char;
tamanho_char = strlen(nome);

ver = pali(nome,tamanho_char,INICIO);

printf("%d ",ver);

    return 0;
}

int pali(char v[],int tamanho,int inicio){

if (tamanho == 1){
    return 1;
}
else{
    if(v[inicio] == v[tamanho - 1]){
        return pali(v,tamanho - 1,inicio + 1);
    }
    else{
        return 0;
    }
}


}