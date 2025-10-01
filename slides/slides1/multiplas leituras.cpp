#include <stdio.h>

int main() {

    float p1, p2, p3, p4 ;
    double media ;

    printf("Digite as notas das 4 provas: ");
    scanf("%f%f%f%f", &p1, &p2, &p3, &p4);

    media = (p1 + p2 + p3 + p4) / 4;

    printf("MEDIA: %.2f ", media );

    return 0;

}