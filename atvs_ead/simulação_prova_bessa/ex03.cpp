
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

void inserir_no_fim(No** inicio,int v);
void imprimir_lista(No* inicio);
void separar_lista(No* original, No* lista_pares, No* lista_impares);

int main(){
No* original = NULL;
No* pares = NULL;
No* impares = NULL;

int valores[] = {10, 3, 5, 8, 12, 7, 1, 4};
    for(int i=0; i<8; i++) {
        inserir_no_fim(&original, valores[i]);
    }

    printf("Lista Original:\n");
    imprimir_lista(original);

    separar_lista(original, pares, impares);

    printf("\n--- DEPOIS DA SEPARACAO ---\n");
    printf("Lista Pares (Esperado: 10 -> 8 -> 12 -> 4): \n");
    imprimir_lista(pares);

    printf("Lista Impares (Esperado: 3 -> 5 -> 7 -> 1): \n");
    imprimir_lista(impares);

    return 0;
}

void imprimir_lista(No* inicio) {
    while (inicio != NULL) {
        printf("%d -> ", inicio->valor);
        inicio = inicio->prox;
    }
    printf("NULL\n");
}

void inserir_no_fim(No** inicio,int v){
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = v;
    novo->prox = NULL;
    if(*inicio == NULL){
        *inicio = novo;
    }
    else{
         No* temp = *inicio;
        while (temp->prox != NULL) temp = temp->prox;
        temp->prox = novo;
        
    }
}

void separar_lista(No* original, No* lista_pares, No* lista_impares){
    int valor_aux;

    while(original!= NULL){
        if(original->valor%2 == 0){
            
            lista_pares->valor = valor_aux;
            lista_pares->prox;
        }
        else{
            lista_impares->valor = valor_aux;
            lista_impares->prox;

        }
        original->prox;
    }







}