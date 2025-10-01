#include <stdio.h>

float converte_f_p_celsius(float fahrr);

int main() {


    float c,f;
    printf("Digite a temperatura em graus Fahrenheit: ");
    scanf("%f",&f);
    c = converte_f_p_celsius(f);
    printf("Celsius = %.2f\n", c);
    return 0;
}

float converte_f_p_celsius(float fahr) {

    float c;
    c = 5 *(fahr - 32) / 9;
    return c;
}