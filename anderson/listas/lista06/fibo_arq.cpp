#include <stdio.h>
#include <stdlib.h>
int main() {
    int fib[30];
    int n=30 ,i;
    FILE *f_fib; 

        fib[0] = 0;
        fib[1] = 1;
    
    for (i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }  

    
f_fib = fopen("seq30_fib.dat","wb");
if(f_fib == NULL){
    perror("Erro ao abrir o arquivo!");
}
else{
    for (i = 0;i<n;i++){
        fwrite(&fib[i],sizeof(fib),1 , f_fib);
    }
}    
    fclose(f_fib);

    return 0;
}