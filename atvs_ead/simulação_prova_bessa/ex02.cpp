#include <stdio.h>
#include <stdlib.h>

int soma_digitos(int n);

int main(){

int n1;

n1 = soma_digitos(4091);
printf("%d",n1);

    return 0;
}

int soma_digitos(int n){

    if(n < 10){
        return n;
    }

    else{
        return n%10 + soma_digitos(n/10);
    }



}