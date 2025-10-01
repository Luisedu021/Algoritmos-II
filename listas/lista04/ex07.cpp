#include <stdio.h>

void troque2(int *p1,int *p2);

int main() {
int a,b;

a = 5;
b = 6;
printf("Valores antes : a = %d,b = %d",a,b);
troque2(&a,&b);
printf("\nValores depois :a = %d,b = %d",a,b);


return 0;
}

void troque2(int *p1,int *p2) {
    int temp;
    temp = *p1;

    *p1 = *p2;
    *p2 = temp; //agora vale b
    




}