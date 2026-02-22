#include <stdio.h>
#include <math.h>

double e_(int x,int n);
int fatorial(int n);

int main(){

int num;
num = fatorial(6);
printf("%d",num);


    return 0;
}

double e_(double x,int n){

    if(n ==  0){
    return 1.0;
}
else{
    return pow(x,n)/fatorial(n) + e_(x,n - 1);
} 
}


int fatorial(int n){
    if(n == 1 || n == 0){
        return 1;
    }
    else{

        return n * fatorial(n - 1);
        
    }
    
}