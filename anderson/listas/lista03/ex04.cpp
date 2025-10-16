#include <stdio.h>
#define tamanho 15
struct banco  {
    int numero_conta,saldo;
    char nome[40];

};
int encontre_menor(struct banco a) ;

int main() {
    int ver = 0,cont = 0,ver2 = 0;
    struct banco meu_banco[tamanho];
    
printf("MENU DE OPCOES:\n");

while (ver != 4) {
printf("Aperte 1 para cadastrar a conta: \n");
printf("Aperte 2 para visualizar a conta: \n");
printf("Aperte 3 para excluir a conta com menor saldo: \nAperte 4 para sair: ");
scanf("%d%*c",&ver);

if (ver == 1){
printf("Digite seu numero da conta,saldo e nome: ");
scanf("%d%d%s%*c", &meu_banco[cont].numero_conta,&meu_banco[cont].saldo,&meu_banco[cont].nome);
cont += 1;
}
else if(ver == 2){
    printf("Digite o numero da conta para visualizar a conta: ");
    scanf("%d%*c",&ver2);
    for (int i = 0;i < cont;i ++){
        if (ver2 == meu_banco[i].numero_conta){
            printf("Seu nome eh %s,o numero da conta eh %d e seu saldo eh %d \n",meu_banco[i].nome,meu_banco[i].numero_conta,meu_banco[i].saldo);
            break;
        }

    }
}
else if (ver == 3) {
    cont = encontre_menor(meu_banco,cont);
    for (int j = 0;j < cont;j++){
        if( meu_banco[cont].saldo == meu_banco[j].saldo){
            printf("O menor saldo eh o do %s que possui %d reais\n",meu_banco[j].nome,meu_banco[j].saldo);
            meu_banco[j] = meu_banco[j + 1];
            printf("Conta excluida! \n");
                        }
                    }    
                }
else if(ver == 4) {
    break;
}
}
    return 0;
}

int encontre_menor(struct banco a[],int cont ) {
    int menor,cont;

    for (int i = 0; i < cont;i++) {
        cont +=1;
         if (i == 0) {
            menor = a[i].saldo ;
         } 
         if (a[i].saldo < menor) {
            break;

         }
    }
    return cont;
}