#include <stdio.h>

double soma_serie(int n);

int main(){
double soma;

soma = soma_serie(3);

printf("%.2lf ",soma);

    return 0;
}

double soma_serie(int n){
if (n == 1) {
    return n;
}

else{
    if (n % 2 == 0){
        return soma_serie(n - 1) + 1.0/n;
        
    }
    else{
        return soma_serie(n - 1) - 1.0/n;
    }
    
}





}