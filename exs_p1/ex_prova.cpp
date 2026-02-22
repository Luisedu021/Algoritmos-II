#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produto{
    char nome[40];
    int cod;
    double preco;
    int qntd;
};

int main() {
    struct produto *a;
    int n,i = 0;
    int cont= 0,cont_for = 0;
    int cod_ver;
    double qntd;
    struct produto *cliente;
    
    double total = 0;


    printf("Quantos produtos deseja colocar em seu estoque?\n");
    scanf("%d%*c",&n);

    a = ( produto *) malloc(sizeof(produto) * n);
    cliente = ( produto *) malloc(sizeof(produto) * n);

    printf("REGISTRO:(comida,codigo e preco)\n");

    for(i = 0;i<n;i++){
        scanf("%s%d%lf",&a[i].nome,&a[i].cod,&a[i].preco);

    }

    printf("Imprima a quantidade produtos que voce deseja,colocando o codigo e a quantidade[0 para parar]:\n");

    while(1){
        printf("Codigo %d e quantidade:",cont);
        scanf("%d%lf",&cod_ver,&qntd);
        if (cod_ver == 0){
            break;
        }
        for(i = 0;i < n;i++){
            if (cod_ver == a[i].cod){
                cliente[cont_for].preco = a[i].preco;
                
                strcpy(cliente[cont_for].nome,a[i].nome);
                cliente[cont_for].qntd += qntd;
                cont_for++;
            }
            
        }
        cont++;
    }
    printf("PEDIDO REALIZADO:\n");

    for(int i = 0;i < cont_for;i++){
        printf("%d x %s\n",cliente[i].qntd,cliente[i].nome);
        total += (cliente[i].qntd * cliente[i].preco);
    }

    printf("TOTAL = R$%.2lf",total);

    return 0;
}