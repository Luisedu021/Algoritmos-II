#include <stdio.h>

void troque2(int *p1,int *p2);



void troque2(int *p1,int *p2) {
    int temp;
    temp = *p1;

    *p1 = *p2;
    *p2 = temp; //agora vale b
    

}