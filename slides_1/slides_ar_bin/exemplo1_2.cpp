#include <stdio.h>

int main() {
    int v[100] = {5,3,2,5,6,7,8,2};
    FILE *f;

    f = fopen("vetor.bin","wb");
   if (f == NULL){
    perror("Erro ao abrir o arquivo");
    return 1;
   }

   fwrite(v, sizeof(int), 8, f);

   fclose(f);

    return 0;
}