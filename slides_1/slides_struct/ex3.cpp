#include <stdio.h>

struct banco {
    int num;
    char titular[35];
    float saldo;

};
int main() {
    struct banco conta;

    printf("Digite o numero da conta");
    scanf("%d%*c", &conta.num); 
    printf("Digite o nome do titula da conta: ");
    scanf("%34s%*c",conta.titular );
    printf("Digite o o saldo da conta: ");
    scanf("%f%*c", &conta.saldo);

    printf("%d",conta.num);




    return 0;
}