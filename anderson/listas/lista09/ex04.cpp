#include <stdio.h>

void numeros_primos(int n);
void numeros_primosb(int n);

int main() {

numeros_primos(11);
printf("\n");
numeros_primosb(11);

    return 0;
}

//letra a
void numeros_primos(int n){

    if(n == 1){
        printf("1 ");

    }
    else{
        numeros_primos(n - 1);
        if ((n)% 2 == 1){
            printf("%d ",n );
        }     
    }
}
//letra b

void numeros_primosb(int n){

    if(n == 1){
        printf("1 ");

    }
    else{
        printf("%d ",n );
        numeros_primos(n - 1);
        if ((n)% 2 == 1){
            
        }     
    }
}