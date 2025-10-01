#include <stdio.h>

int main() {
FILE *f1;
FILE *f2;
int p1,p2;

f1 = fopen("entrada.txt","r");
if (f1 == NULL){
        perror("Erro ao abrir o arquivo!");
      return 1;
    }
f2 = fopen("saida2.txt","w");
if (f2 == NULL){
        perror("Erro ao abrir o arquivo!");
      return 1;
    }
while (fscanf(f1,"%d%d",&p1,&p2)== 2){
    fprintf(f2,"par lido foi: %d %d\n", p1,p2);
}

fclose(f1);
fclose(f2);

    return 0;
}