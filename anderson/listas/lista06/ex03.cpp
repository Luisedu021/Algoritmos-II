#include <stdio.h>

int main() {
    int n1,n2,soma,soma_novo;
    FILE *f;
    FILE *f_saida;
    FILE *f_leit;

    f = fopen("entrada.dat","rb");
    if (f == NULL){
        perror("Erro ao abrir o arquivo");
        return 1;
    }
    fread(&n1 ,sizeof(int),1, f);
    fread(&n2 ,sizeof(int),1, f);
    fclose(f);

    printf("dois numeros: %d %d\n",n1,n2);
    
    f_saida = fopen("saida.dat","wb");
    if (f_saida == NULL){
        perror("Erro ao abrir o arquivo");
        return 1;
    }
    soma = n1 + n2;

    fwrite(&soma ,sizeof(int),1, f_saida);
    fclose(f_saida);
// segunda parte para ler o arquivo 

    f_leit = fopen("saida.dat","rb");
    if (f_leit == NULL){
        perror("Erro ao abrir o arquivo");
        return 1;
    } 
    fread(&soma_novo,sizeof(int), 1, f_leit);
    fclose(f_leit);
    
    printf("A soma nova eh %d",soma_novo);
    return 0;
}
// o numero nao eh o esperado