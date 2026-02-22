#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct mus{
    char titulo[50];
    char artista[50];
    int duracao;
} musica;

void relatorio(musica playlist[], int n);

int main(){
char titulo[50];
char art[50];
int dur;

musica vetor[3];
for(int j = 0;j < 3;j++){

    printf("Insira o nome da musica:\n");
    scanf("%49s%*c",titulo);
     printf("Insira o nome do artista:\n");
    scanf("%49s%*c",art);
     printf("Insira a duracao:\n");
    scanf("%d%*c",&dur);

    strcpy(vetor[j].artista,art);
    strcpy(vetor[j].titulo,titulo);
    vetor[j].duracao = dur;
    printf("teste: dur: %d ,tit: %s,art: %s\n",vetor[j].duracao,vetor[j].titulo,vetor[j].artista);
   
}

relatorio(vetor,3);


    return 0;
}

void relatorio(musica playlist[], int n){

    int total_dur;

    int indice;

    for(int i = 0;i < n;i++){
        if(i == 0){        
           indice = 0;
           total_dur = playlist[i].duracao;
            
        }
        else if (playlist[i].duracao > playlist[indice].duracao){
            total_dur = total_dur + playlist[i].duracao;
            indice = i;
        }
        else{
            total_dur = total_dur + playlist[i].duracao;
        }

    }
    printf("\nNome da musica mais longa eh %s\n",playlist[indice].titulo);
    
    int min;
    min = total_dur / 60;
    int seg = total_dur % 60;
    if(seg<10 && min <10){
        printf("Duracao total: 0%d:0%d \n",min,seg);
    }
    else if(seg < 10 && min>10){
        printf("Duracao total: 0%d:%d \n",min,seg);
    }
    else if(seg >= 10 && min>=10){
        printf("Duracao total: %d:%d \n",min,seg);
    }
    else{
         printf("Duracao total: %d:0%d \n",min,seg);
    }


}