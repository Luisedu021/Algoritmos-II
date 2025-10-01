#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char frase[100];
    char palavra_procurada[50];
    char *palavra_atual;
    int posicao = 0;
    int encontrada = 0; 

    
    printf("Escreva uma frase: ");
    // Usar fgets para ler a linha inteira, incluindo espaços. É mais seguro que scanf.
    fgets(frase, sizeof(frase), stdin);

    // Remove o caractere de nova linha (\n) que o fgets pode deixar no final
    frase[strcspn(frase, "\n")] = 0;

    // 2. Ler a palavra a ser procurada
    printf("Escreva uma palavra para ser encontrada: ");
    scanf("%s", palavra_procurada);


    palavra_atual = strtok(frase, " \t\n");

    // Loop para percorrer todas as palavras da frase
    while (palavra_atual != NULL) {
        posicao++; // Incrementa a posição para cada palavra encontrada

        // Compara a palavra atual da frase com a palavra procurada
        // strcmp retorna 0 se as strings forem idênticas
        if (strcmp(palavra_atual, palavra_procurada) == 0) {
            encontrada = 1; // Marca que a palavra foi encontrada
            break;          // Interrompe o loop, pois já encontramos a primeira ocorrência
        }

        // Pega a próxima palavra da frase
        palavra_atual = strtok(NULL, " \t\n");
    }

    // 4. Exibir o resultado
    if (encontrada) {
        printf("A palavra \"%s\" foi encontrada na posicao %d.\n", palavra_procurada, posicao);
    } else {
        printf("A palavra \"%s\" nao foi encontrada na frase.\n", palavra_procurada);
    }

    return 0;
}