#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f_leitura;
    int n,elemento_lido;
    long tamanho;
    size_t elemento_lidos;

    printf("Qual o termo que busca?");
    scanf("%d", &n);

    f_leitura = fopen("seq30_fib.dat","rb");
    if (f_leitura == NULL){
        perror("Falha ao abrir o arquivo ");
        return 1;
    }
    tamanho = n * sizeof(int);

    if (fseek(f_leitura,tamanho, SEEK_SET) != 0){
        perror("Errro ao posicionar o ponteiro do arquivo");
        fclose(f_leitura);
        return 1;
    }
 elemento_lidos = fread(&elemento_lido,sizeof(int),1,f_leitura);
 
if(elemento_lidos == 1){
    printf("O elemento %d tem o valor %d",n+ 1,elemento_lido);
}
else{
    printf("Erro ao ler o elemento do arquivo");
}
fclose(f_leitura);

    return 0;
}