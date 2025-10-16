#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINHAS 500
#define MAX_COMPRIMENTO 200

int main() {
    FILE *f;
    char buffer[200];
    char *linhas[MAX_LINHAS]; 
    int num_linhas = 0;
    f = fopen("Arq_texto.txt","r");
    if (f == NULL){
        perror("Erro ao abrir o arquivo");
        return 1;
    }
    while(fgets(buffer,sizeof(buffer), f) != NULL){
        printf("%s\n",buffer);
        buffer[strcspn(buffer, "\n")] = '\0';

        if (linhas[num_linhas] == NULL){
            perror("Erro ao alocar a memoria");
            return 1;
        }
        strcpy(linhas[num_linhas], buffer);
        num_linhas++;
        
    }
fclose(f);

printf("\n--- Teste de Armazenamento ---\n");
    // Apenas imprima se tivermos lido alguma linha
    if (num_linhas > 0) {
        printf("Primeira linha guardada: %s\n", linhas[0]);
        printf("Ultima linha guardada: %s\n", linhas[num_linhas - 1]);
    } else {
        printf("Nenhuma linha foi lida do arquivo.\n");
    }

    // --- IMPORTANTE: Liberar a memória que alocamos ---
    // Como usamos malloc, precisamos usar free para cada ponteiro.
    for (int i = 0; i < num_linhas; i++) {
        free(linhas[i]);
    }

    return 0;
}