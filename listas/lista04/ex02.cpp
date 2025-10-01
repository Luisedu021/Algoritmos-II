#include <stdio.h>

int main() {
    float *q, b;
    b = 3.14;
    *q = *q + 1;
    printf("*q = %f\n", *q);

    return 0;

}

/*
Onde está o erro neste código? O que acontecerá se você executá-lo desta maneira?
R: O erro esta em não inicializar o ponteiro com um valor ou passar um endereço para este
*/