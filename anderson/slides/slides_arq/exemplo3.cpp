#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    int i,r;
    FILE *f;
    //abra o arquivo
    f = fopen("100_aleatorios.txt","w");
    if (f == NULL){
        perror("Erro ao abrir o arquivo");
        exit(1);
    }
srand(time(NULL));
for (i = 0;i <100; i++){
    r = (rand() % 100) + 1;
    fprintf(f,"%d\n",r);
}
fclose(f);
return 0;
}