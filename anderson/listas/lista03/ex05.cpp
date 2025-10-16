#include <stdio.h>

enum estado_civil {
    Solteiro,
    Casado,
    Divorciado,
    Viuvo
};

// Função para "traduzir" o enum para texto
void imprimirEstadoCivil(enum estado_civil ec) {
    switch (ec) {
        case Solteiro:
            printf("Solteiro");
            break;
        case Casado:
            printf("Casado");
            break;
        case Divorciado:
            printf("Divorciado");
            break;
        case Viuvo:
            printf("Viuvo");
            break;
        default:
            printf("Estado civil desconhecido");
            break;
    }
}

int main() {
    enum estado_civil p1, p2;

    p1 = Casado;
    p2 = Divorciado;

    printf("A situacao de p1 eh: ");
    imprimirEstadoCivil(p1);
    printf("\n");

    printf("A situacao de p2 eh: ");
    imprimirEstadoCivil(p2);
    printf("\n");

    return 0;
}