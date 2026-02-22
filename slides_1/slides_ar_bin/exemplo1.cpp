#include <stdio.h>
#include <stdlib.h>
/*
Solução arquivo texto!*/

int main() {
    int *v;
    int n;
    FILE *f;

    printf("Quantos numeros voce deseja alocar?");
    scanf("%d",&n);

    v = (int *) malloc(sizeof(int) * n);
   if (v == NULL) {
    perror("Erro ao alocar a memoria");
    return 1;
   }
   f = fopen("vetor.txt","w");
   if (f == NULL){
    perror("Erro ao abrir o arquivo");
    return 1;
   }

    for (int i = 0;i < n;i++){
        scanf("%d",&v[i]);
         if (i == n - 1){
            fprintf(f,"%d",v[i]);
            
         }
         else{
            fprintf(f,"%d,",v[i]);  
         }
    }
    free(v);
    fclose(f);


    return 0;
}