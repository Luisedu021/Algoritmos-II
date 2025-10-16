#include <stdio.h>

int main() {
    int n1,n2;
    FILE *f;

    n1 = 6;
    n2 = 9;

    f = fopen("entrada.dat","wb");
    if (f == NULL){
        perror("Erro ao abrir o arquivo");
        return 1;
    }
    fwrite(&n1 ,sizeof(int),1, f);
    fwrite(&n2 ,sizeof(int),1, f);

    return 0;
}