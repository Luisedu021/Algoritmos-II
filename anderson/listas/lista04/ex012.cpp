#include <stdio.h>
int adicione(int a,int b);
int subtraia(int a,int b);
int mult(int a,int b);
int divida(int a,int b);

int main() {
    int n1,n2,resultado;
    int (*pont) (int a, int b);
    char ver;

    printf("Entre com dois inteiros:");
    scanf("%d%d%*c",&n1,&n2);
    printf("Qual operacao vc deseja fazer?\n");
    printf("'a' para adicionar, 's' para subtrair, 'm' para multiplicar e 'd' para dividir: ");
    scanf("%c",&ver);

    if (ver == 's'){
        pont = subtraia;
    }

    else if(ver == 'm'){
        pont = mult;
    }

    else if(ver == 'a') {
        pont = adicione;
    }

    else if (ver == 'd'){
        pont = divida;
    }
    else{
        printf("Entrada invalida");
        return 0;
        
    }
    resultado = pont(n1,n2);
    printf("O resultado eh %d",resultado);
    return 0;
}

int adicione(int a,int b) {
    return a + b;
}

int subtraia(int a,int b) {

    return a - b;
}

int mult(int a,int b) {

    return a * b;
}

int divida(int a,int b) {
    
    if (b == 0){
        return 0;
    }else{
        return a / b;
    }
    
}