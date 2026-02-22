#include <stdio.h>
#define tamanho 10 
int encontre_maior(int v[],int tam);



int main() {
    int v[tamanho],i,maior  ;

    for (i = 0; i < tamanho ;i++) {
        printf("Digite o numero %d: ",i+ 1);
        scanf("%d",&v[i]);

    }
     maior = encontre_maior(v,tamanho);
    printf("O maior numero eh o %d",maior);

    return 0;
};




int encontre_maior(int v[],int tam) {
    int maior = 0;

  for (int i= 0;i < tamanho; i++){
    if (i == 0) {
        maior = v[i]; 
    }
    else {
        if (v[i] > maior) {
            maior = v[i];
        }
    }



  }  

  return maior;
}