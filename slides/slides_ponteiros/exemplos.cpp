#include <stdio.h>

void teste(int *p1, int *p2) {
    *p1 = *p1 + 1;
    *p2 = *p2 + 1;
    printf("%d %d",*p1,*p2);

}


int main () {
    int a = 1,b = 2;
    int *p1,*p2; // ponteiro
    p2 = &a;
    p1 = &b;

    teste(&a, &b);
    printf("\n%d %d ",*p1,*p2);
    return 0;
}