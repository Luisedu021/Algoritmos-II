#include <stdio.h>

int conta_ate_n(int n);


int main(){

conta_ate_n(10);



    return 0;
}

int conta_ate_n(int n){
    if (n == 0){
        printf("0 ");
        return 0;
    }
    else{
        conta_ate_n(n -1);
        printf("%d ",n);
        
    }
}
