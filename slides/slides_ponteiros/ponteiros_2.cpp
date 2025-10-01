#include <stdio.h>

void ao_cubo( int *pont);

int main(void) {
    int num = 5;

    printf("O numero original eh %d",num);

    ao_cubo(&num) ;
    printf("\nO novo numero eh %d\n",num );


}

void ao_cubo(int *pont) {

    *pont = *pont * *pont * *pont;
    
    return ;

}