#include <stdio.h>

void imprime_10_1(int n);

int main() {


imprime_10_1(10);



    return 0;
}

void imprime_10_1(int n){

    if (n == 1){
        printf("1 ");
        return ;
    }
    else{
        printf("%d ",n);
        imprime_10_1(n - 1);
        
    }



}

