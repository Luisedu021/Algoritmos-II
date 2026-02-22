#include <stdio.h>
#include <ctype.h>

/*
Variaveis declaradas com qualificador const não podem ser alteradas!!*/

void converterparaM(char *string);

int main(void) {
    char string[] = "ola mundo!!!!";

    printf("A string antes da conversao eh : %s\n", string);
    converterparaM(string);
    printf("A string apos a conversao eh : %s",string);



    return 0;
}

void converterparaM(char *string){

    while (*string != '\0') {
        if (islower(*string)) {
            *string = toupper( *string);
        }

        ++string;

    }
}