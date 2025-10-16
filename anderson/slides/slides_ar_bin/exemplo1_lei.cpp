#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f;
    int num_lidos[100];
    int num_ler = 8;

    f = fopen("vetor.bin","rb");
    if (f == NULL) {
        perror("Erro ao abrir o arquivo 'vetor.bin'");
        printf("Voce executou o programa de escrita primeiro?\n");
        return 1;
    }
    size_t itens_lidos = fread(num_lidos, sizeof(int), num_ler, f);

    fclose(f);

    if (itens_lidos != num_ler){
        printf("Erro: a leitura do arquivo falhou ou o arquivo nao continha 8 inteiros.\n");
        return 1;
    }

     printf("Arquivo 'vetor.bin' lido com sucesso! Os numeros sao:\n");
    for (int i = 0; i < num_ler; i++) {
        printf("%d ", num_lidos[i]);
    }
    printf("\n");

    return 0;
}