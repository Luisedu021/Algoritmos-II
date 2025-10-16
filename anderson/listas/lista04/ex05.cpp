#include <stdio.h>
#include <stdlib.h>

float media( int n, float v[]);

int main() {
    int num_notas, i;
    float *v;

    printf("Quantas notas voce deseja alocar? ");
    scanf("%d",&num_notas);

    v = (float *) malloc(sizeof(float) * num_notas);

    printf("Entre com as suas %d notas: ",num_notas);
    for (i = 0;i < num_notas;i++) {
        scanf("%f",&v[i]);

    }
    printf("Sua media no final vai ser: %.2f",media(num_notas,v));


    free(v);
    return 0;
}


float media(int n, float v[]) {
 float somatorio = 0,media ;

for (int i= 0; i < n;i++) {
    somatorio += v[i];
}
media = somatorio / n;

return media;
}