#include <stdio.h>
#include <stdlib.h>


int main() {
    int *fib;
    int n,i,temp1 = 0,temp2 = 1;
    FILE *f_fib;
    //precisa ser 30,mas enfim
    printf("Quantos numeros voce deseja ter no seu fibonacci?");
    scanf("%d",&n);
    n =30;
    fib = (int *) malloc(n*sizeof(int));

 if (n >= 1) {
        fib[0] = 0;
    }
    if (n >= 2) {
        fib[1] = 1;
    }
    for (i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }  


    
f_fib = fopen("arq_fib.txt","w");
if(f_fib == NULL){
    perror("Erro ao abrir o arquivo!");
}
else{
    for (i = 0;i<n;i++){
        fprintf(f_fib,"%d\n",fib[i]);
    }
}    
    fclose(f_fib);

    return 0;
}