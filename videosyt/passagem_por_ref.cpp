#include <stdio.h>

void soma10(int x);

int main() {

int num ;
printf("Digite um numero: ");
scanf("%d%*c",&num);
soma10(num);
printf("O numero digitado foi: %d\n",num);

return 0;
}




void soma10(int x) {
    x += 10;
    return;
}