#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Incluido para a funcao isspace()

#define na_palavra 1
#define fora_palavra 0

int main() {
    char vetor_palavras[50];
    char novo_texto[50];
    int cont = 0,cont1= 0,estado = fora_palavra;
    FILE *f;
    FILE *f_leitura;

    f = fopen("Arq_texto","w");
    if (f == NULL) {
        perror("Erro ao abrir o arquivo!");

    }

    printf("Escreva uma frase: ");
    fgets(vetor_palavras,50,stdin);
    
    while(vetor_palavras[cont] != '\0'){
        fprintf(f,"%c",vetor_palavras[cont]);
        cont += 1;
    }
    fclose(f);
    printf("A nova frase apos ser lida eh:");

    f_leitura = fopen("Arq_texto","r");
    if (f_leitura == NULL) {
        perror("Erro ao abrir o arquivo!"); 

    }
    cont = 0;
    
    while(fscanf(f_leitura,"%c",&novo_texto[cont1]) != EOF){
        if (isspace(novo_texto[cont1])){
            estado = fora_palavra;
        }
        if (estado == fora_palavra ){
            if (isspace(novo_texto[cont1]) == false){
                estado = na_palavra;
                cont ++;
            }
            
        }
        cont1++;
    }
    fclose(f_leitura);
    printf("O numero de palavras eh %d",cont);
    return 0;
}



/*IMPORTANTE!!!!!*/
//para ler linhas de texto a gente usa sempre o fgets() em vez de scanf 
//para imprimir uma string inteira a gente usa o printf
//para imprimir um unico caractere a gente usa o %c