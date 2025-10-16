#include <stdio.h>

int digitos(int n);

int main() {

int a;
a = digitos(330);

printf("%d ",a);


    return 0;

}

int digitos(int n){

if (n < 10){
    return 1;
}
else{

    return digitos(n / 10) + 1;
}


}
