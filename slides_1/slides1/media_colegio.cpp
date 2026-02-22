#include <stdio.h>

int main(){

    int i ;
    float notas[10], media ,soma = 0;

    printf("Entre com as notas: ");

    for (i = 0; i < 10; i++){
        scanf("%f", &notas[i]);
        soma += notas[i] ;
    }
        

    
media = soma / 10;

printf("Media eh %.2f", media );

if (media >= 7 )
{printf("Media maior que 7");}

else {
    printf("A media eh menor que 7");
        }
    

return 0;


}