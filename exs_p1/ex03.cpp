#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *imp,*par,*final;
    int tamanho_linha = 500;
    char linha[tamanho_linha];
    
    imp = fopen("lotr_cap1_odd.txt", "r");
    if (imp == NULL){
        perror("Falha ao abrir o arquivo!");
        return 0;
    }
    par = fopen("lotr_cap1_even.txt", "r");
    if (par == NULL){
        perror("Falha ao abrir o arquvivo!");
        return 0;
    }

    final = fopen("lotr_cap1_recovered.txt", "w");
    if (final  == NULL){
        perror("Falha ao criar o arquvivo!");
        return 0;
    }
    while(1){

        if (fgets(linha, tamanho_linha, imp) == NULL){
            break;
        }
        fputs(linha, final);

        if (fgets(linha, tamanho_linha, par) == NULL){
            break;
        }
        fputs(linha, final);

}

    fclose(imp);
    fclose(par);
    fclose(final);


 printf("Arquivo 'lotr_cap1_recovered.txt' gerado com sucesso!\n");

    return 0;
}