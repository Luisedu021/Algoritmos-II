#include <stdio.h>
#include <stdlib.h>

float media(int n,float *vnotas);

int main() {

float vnotas[10],media_notas;
int i;

for (i =0;i<10;i++){
    printf("Digite o valor:");
    scanf("%f",&vnotas[i]);
}
media_notas = media(10,&vnotas[0]);
printf("A media eh %.2f",media_notas);
    return 0;
}


float media(int num,float *valor){
    float soma = 0,media1;
for (int i = 0;i<num;i++){
    soma = soma + *valor;
    valor++;
}

media1 = soma /num;
return media1;

}