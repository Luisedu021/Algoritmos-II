#include <stdio.h>

int soma_valor(int x);
void soma_ref(int *p1);

int main() {
    int teste = 6,soma ;
printf("Valor do numero %d\n",teste);

soma = soma_valor(teste);

printf("Soma eh : %d\n",soma);
//chamando a func nova por ref
soma_ref(&teste);

printf("\nvalor da soma: %d",teste);


    return 0;
}

int soma_valor(int x) {
    int soma = 0;

    for (int i = 1;i <= x; i++){
        soma += i;}
        
    
    return soma;
}

void soma_ref(int *p1){

    int temp,soma = 0;
    temp = *p1;
    for (int i = 0;i< *p1;i++){
        soma += temp;
        temp -= 1;
    }
    *p1 = soma;
    return ;

}