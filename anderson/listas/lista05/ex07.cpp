#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(){
    FILE *f;
    int freq_letras[26],caractere,cont_crct,minuscu,cont2;

    for (int i = 0;i < 26;i++){
        freq_letras[i] = 0;
    }

    f =(fopen("Arq_texto.txt","r"));
    if(f == NULL){
        perror("Erro ao abrir o arquivo");
        return 1;
    }
    while ((caractere = fgetc(f)) != EOF){
        if (isalpha(caractere)){
            minuscu = tolower(caractere);
            cont_crct = minuscu - 'a';
            freq_letras[cont_crct]++;
        }
    }
    fclose(f);
    for (int i = 0;i < 26;i++){
        char letra_atual = 'a' + i;
        printf("%c: ", letra_atual);
        for (int j = 1;j <= freq_letras[i];j++){
            printf("*");
        }
        printf(" (%d)", freq_letras[i]);
        printf("\n");    
        
        

    }
    return 0;
}