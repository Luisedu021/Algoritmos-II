#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define no_espaco 1
#define fora_espaco 0

int main() {
int caractere;
int cont = 0;
int contstrig = 0;
FILE *f;
FILE *f_novo;
char string_nova[100];


f = fopen("Arq_texto.txt", "r");
if (f == NULL){
    perror("Erro ao abrir o arquivo");
    return 1;
}


while((caractere = fgetc(f)) != EOF){
    if (isspace(caractere)){
        cont++;
        if (cont < 2){
            string_nova[contstrig] = ' ';
            contstrig++;
                    }
                }
    else{
        cont = 0;
        string_nova[contstrig] = caractere;
        contstrig++;
         }    
    
}
fclose(f);
f_novo = fopen("Arq_novo.txt","w");
if (f_novo == NULL){
    perror("Erro ao abrir o arquivo!");
    return 1;
}

string_nova[contstrig] = '\0';
fprintf(f_novo,"%s\n", string_nova);
fclose(f_novo);

    return 0;
}