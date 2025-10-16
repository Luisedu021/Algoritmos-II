#include <stdio.h>
void ola_mundo();

int main() {
    void (*ptr)(void);
//atribuit o end da func em prt
//(o nome da funcao sem parenteses é o seu endereço)
ptr = ola_mundo;

printf("Chamando a funçao atraves do ponteiro: ");
ptr();






    return 0;
}

void ola_mundo(){
    printf("Ola mundo!");
}