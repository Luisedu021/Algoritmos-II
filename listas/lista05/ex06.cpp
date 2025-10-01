#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char frase[100],palavra_procurada[50];
    int posicao = 0;
    FILE *f;
    const char *delim = " \t\n.,;!?";
    char *palavra;
    printf("Escreva a palavra que voce procura: ");
    scanf("%49s%*c",palavra_procurada);
    

    f = fopen("Arq_texto.txt","r");
    if (f == NULL) {
        perror("Erro ao abrir o arquivo!");

    }
    printf("Conteudo do arquivo: ");
    while (fgets(frase,sizeof(frase),f) != NULL){
        posicao++;
        palavra = strtok(frase, delim);
        while (palavra != NULL){
            if (strcmp(palavra,palavra_procurada)== 0){
                
                printf("Encontrei a palavra '%s' na linha %d'!\n",palavra,posicao);
            } 
            palavra = strtok(NULL,delim);
        }
        
    }

    
    
    
    fclose(f);
    

    

    return 0;
}