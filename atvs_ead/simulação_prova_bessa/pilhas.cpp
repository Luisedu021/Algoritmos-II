#include <stdio.h>
#include <string.h>

#define TAMANHO 2001

int main() {
   
    char pilha[TAMANHO]; 
    
 
    int casos = 1;

   
    while (scanf("%s", pilha) == 1) {
        
        if (pilha[0] == '-') {
            break; 
        }

        int aberta = 0;   
        int fechada = 0; 
        int tamanho = strlen(pilha);

        for (int i = 0; i < tamanho; i++) {
            if (pilha[i] == '{') {
               
                aberta++;
            } else { 
                if (aberta > 0) {
                    
                    aberta--;
                } else {
                    
                    fechada++;
                }
            }
        }
        int ops = (aberta + 1) / 2 + (fechada + 1) / 2;

        printf("%d. %d\n", casos, ops);
        casos++;

    }

    return 0;
}