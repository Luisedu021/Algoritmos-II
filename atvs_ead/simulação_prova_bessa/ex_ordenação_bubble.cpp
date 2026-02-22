#include <stdio.h>
#include <stdlib.h>


typedef struct cel{
    struct cel *prox;
    struct cel *ant;
    int valor;

}celula;

void insere_valor(int valor,celula **cabeca);
void imprime_lista(celula *cabeca);
void troque(int *a,int *b);
void bubble_sort(celula *cabeca);

int main(){

    celula *cabeca = NULL;

    insere_valor(40, &cabeca);
    insere_valor(80, &cabeca);
    insere_valor(90, &cabeca);
    insere_valor(240,&cabeca);
    imprime_lista(cabeca);
    bubble_sort(cabeca);
    imprime_lista(cabeca);
    return 0;
}


void insere_valor(int valor,celula **cabeca){
    celula *nova = (celula*) malloc(sizeof(celula));
    if(nova == NULL){
        return ;
    }
    nova->valor = valor;
    nova->ant = NULL;
    nova->prox = *cabeca;

    if(*cabeca != NULL){
        (*cabeca)->ant = nova;
    }
    *cabeca = nova;


}

void imprime_lista(celula *cabeca){
    celula *aux = cabeca; 
    while(aux != NULL){
        printf("%d -> ", aux->valor);
        aux = aux->prox; 
    }
    printf("NULL\n"); 
}

void troque(int *a,int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void bubble_sort(celula *cabeca){
    int valor_aux;
    celula *aux = cabeca;
    int trocou = 1;

    if(cabeca == NULL){
        return ;
    }
    while(trocou){
        trocou = 0;
        aux = cabeca;
        while(aux->prox != NULL){
            if(aux->valor > aux->prox->valor){
            troque(&aux->prox->valor,&aux->valor);
            trocou = 1;
        }

        aux = aux->prox;

        }
        
}
}